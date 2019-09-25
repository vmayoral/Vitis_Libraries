#include <ap_int.h>
#include <iostream>

#include <openssl/sha.h>

#include <sys/time.h>
#include <new>
#include <cstdlib>

#include "kernel_config.hpp"
// text length for each task in 128-bit
#define N_ROW 64
// text length for each task in Byte, should be dividable by (4 * 16 / SUB_GRP_SZ)
#define N_MSG 1024
// number of tasks for a single PCIe block
#define N_TASK 2 // 8192
// cipher key size in bytes
#define KEY_SIZE 32

extern "C" void aes256CbcEncryptKernel_1(ap_uint<512>* inputData, ap_uint<512>* outputData);

template <typename T>
T* aligned_alloc(std::size_t num) {
    void* ptr = nullptr;
    if (posix_memalign(&ptr, 4096, num * sizeof(T))) throw std::bad_alloc();
    return reinterpret_cast<T*>(ptr);
}

void hmacSHA1(const unsigned char* key,
              unsigned int keyLen,
              const unsigned char* message,
              unsigned int msgLen,
              unsigned char* h) {
    const int MSG_SIZE = 4;             // size of each message word in byte
    const int HASH_SIZE = 5 * MSG_SIZE; // size of hash value in byte
    const int MAX_MSG = 4096;           // max size of message in byte
    const int BLOCK_SIZE = 64;          // size of SHA1 block

    unsigned char kone[BLOCK_SIZE + 8] = {0};
    unsigned char kipad[BLOCK_SIZE + 8] = {0};
    unsigned char kopad[BLOCK_SIZE + 8] = {0};
    unsigned char kmsg[BLOCK_SIZE + MAX_MSG + 8] = {0};
    unsigned char khsh[BLOCK_SIZE + HASH_SIZE + 8] = {0};
    unsigned char h1[HASH_SIZE + 8] = {0};
    unsigned char h2[HASH_SIZE + 8] = {0};

    if (keyLen > BLOCK_SIZE) {
        SHA1((const unsigned char*)key, keyLen, (unsigned char*)h1);
        memcpy(kone, h1, HASH_SIZE);
    } else
        memcpy(kone, key, keyLen);

    for (int i = 0; i < BLOCK_SIZE; ++i) {
        kipad[i] = (unsigned int)(kone[i]) ^ 0x36;
        kopad[i] = (unsigned int)(kone[i]) ^ 0x5c;
    }

    memcpy(kmsg, kipad, BLOCK_SIZE);
    memcpy(kmsg + BLOCK_SIZE, message, msgLen);
    SHA1((const unsigned char*)kmsg, BLOCK_SIZE + msgLen, (unsigned char*)h2);

    memcpy(khsh, kopad, BLOCK_SIZE);
    memcpy(khsh + BLOCK_SIZE, h2, HASH_SIZE);
    SHA1((const unsigned char*)khsh, BLOCK_SIZE + HASH_SIZE, (unsigned char*)h);
}

int main(int argc, char* argv[]) {
    // input data
    const unsigned char datain[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                                    0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};

    unsigned char messagein[N_MSG];
    for (int i = 0; i < N_MSG; i += 16) {
        for (int j = 0; j < 16; j++) {
            messagein[i + j] = datain[j];
        }
    }

    // cipher key
    const unsigned char key[] = {0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a,
                                 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25,
                                 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f};

    // generate golden
    unsigned char hmacResult[20];
    hmacSHA1(key, 32, messagein, N_MSG, hmacResult);

    ap_uint<512> golden = 0;
    for (unsigned int j = 0; j < 20; j++) {
        golden.range(j * 8 + 7, j * 8) = hmacResult[j];
    }

    ap_uint<8 * KEY_SIZE> keyReg;
    for (unsigned int i = 0; i < KEY_SIZE; i++) {
        keyReg.range(i * 8 + 7, i * 8) = key[i];
    }

    ap_uint<128> dataReg;
    for (unsigned int i = 0; i < 16; i++) {
        dataReg.range(i * 8 + 7, i * 8) = datain[i];
    }

    std::cout << "Goldens have been created using OpenSSL.\n";

    // Host buffers
    ap_uint<512>* hb_in1 = aligned_alloc<ap_uint<512> >(N_MSG * N_TASK * CH_NM / 64 + CH_NM);
    ap_uint<512>* hb_in2 = aligned_alloc<ap_uint<512> >(N_MSG * N_TASK * CH_NM / 64 + CH_NM);
    ap_uint<512>* hb_in3 = aligned_alloc<ap_uint<512> >(N_MSG * N_TASK * CH_NM / 64 + CH_NM);
    ap_uint<512>* hb_in4 = aligned_alloc<ap_uint<512> >(N_MSG * N_TASK * CH_NM / 64 + CH_NM);
    ap_uint<512>* hb_out_a[4];
    for (int i = 0; i < 4; i++) {
        hb_out_a[i] = aligned_alloc<ap_uint<512> >(N_TASK * CH_NM);
    }
    // generate configurations
    for (unsigned int j = 0; j < CH_NM; j++) {
        // massage length in 128-bit for each task
        hb_in1[j].range(511, 448) = N_ROW;
        hb_in2[j].range(511, 448) = N_ROW;
        hb_in3[j].range(511, 448) = N_ROW;
        hb_in4[j].range(511, 448) = N_ROW;

        // number of tasks in a single PCIe block
        hb_in1[j].range(447, 384) = N_TASK;
        hb_in2[j].range(447, 384) = N_TASK;
        hb_in3[j].range(447, 384) = N_TASK;
        hb_in4[j].range(447, 384) = N_TASK;

        // cipherkey
        hb_in1[j].range(255, 0) = keyReg.range(255, 0);
        hb_in2[j].range(255, 0) = keyReg.range(255, 0);
        hb_in3[j].range(255, 0) = keyReg.range(255, 0);
        hb_in4[j].range(255, 0) = keyReg.range(255, 0);
    }
    // generate texts
    /*
    for (int i = 0; i < N_TASK; i++) {
        for(int j = 0; j < N_ROW; j++) {
            for(int k = 0; k < 128 / 32; k++) {
                for(int l = 0; l < CH_NM / 16; l++) {
                    int pos = CH_NM + l + k * (CH_NM / 16) + j * (CH_NM / 16 * 128 / 32) + i * (CH_NM / 16 * 128 / 32 *
    N_ROW);
                    for(int m = 0; m < 16; m++) {
                        hb_in1[pos].range(m * 32 + 31, m * 32) = dataReg.range(k * 32 + 31, k * 32);
                        hb_in2[pos].range(m * 32 + 31, m * 32) = dataReg.range(k * 32 + 31, k * 32);
                        hb_in3[pos].range(m * 32 + 31, m * 32) = dataReg.range(k * 32 + 31, k * 32);
                        hb_in4[pos].range(m * 32 + 31, m * 32) = dataReg.range(k * 32 + 31, k * 32);
                    }
                }
            }
        }
    }
    */
    int chWord = (512 / 32 / SUB_GRP_SZ);
    for (int i = 0; i < N_TASK; i++) {
        for (int j = 0; j < (N_MSG / 4); j += chWord) {
            for (int k = 0; k < GRP_NM; k++) {
                int pos = k + (j / chWord) * GRP_NM + i * (N_MSG * CH_NM / 64) + CH_NM;
                for (int l = 0; l < SUB_GRP_SZ; l++) {
                    if (SUB_GRP_SZ >= 4) {
                        hb_in1[pos].range((l + 1) * 32 * chWord - 1, l * 32 * chWord) =
                            dataReg.range(((j % 4) + 1) * chWord * 32 - 1, (j % 4) * chWord * 32);
                    } else {
                        hb_in1[pos].range(127, 0) = dataReg.range(127, 0);
                        hb_in1[pos].range(255, 128) = dataReg.range(127, 0);
                        hb_in1[pos].range(383, 256) = dataReg.range(127, 0);
                        hb_in1[pos].range(511, 384) = dataReg.range(127, 0);
                    }
                }
            }
        }
    }

    std::cout << "Host map buffer has been allocated and set.\n";

    aes256CbcEncryptKernel_1(hb_in1, hb_out_a[0]);

    // check result
    bool checked = true;
    // check ping buffer
    std::cout << "check ping buffer" << std::endl;
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < N_TASK; j++) {
            for (int k = 0; k < CH_NM; k++) {
                if (hb_out_a[i][j * CH_NM + k] != golden) {
                    checked = false;
                    std::cout << std::dec << i << "th kernel " << j << "th message " << k
                              << "th channel's result is wrong" << std::endl;
                    std::cout << std::hex << "golden: " << golden << std::endl;
                    std::cout << std::hex << "result: " << hb_out_a[i][j * CH_NM + k] << std::endl;
                }
            }
        }
    }

    // final output
    std::cout << std::dec << std::endl;
    if (checked) {
        std::cout << std::dec << CH_NM << " channels, " << N_TASK << " tasks, " << N_ROW
                  << " messages verified. No error found!" << std::endl;
        return 0;
    } else {
        std::cout << "something is wrong!" << std::endl;
        return 1;
    }
}
