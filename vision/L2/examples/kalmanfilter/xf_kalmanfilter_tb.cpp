/***************************************************************************
Copyright (c) 2018, Xilinx, Inc.
All rights reserved.
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software
without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ***************************************************************************/
#include "common/xf_headers.h"
#include "xcl2.hpp"

void error_check(
    cv::KalmanFilter kf, float* Xout_ptr, float* Uout_ptr, float* Dout_ptr, bool tu_or_mu, float* error_out) {
    uint32_t nan_xf = 0x7fc00000;

    cv::Mat Uout(KF_N, KF_N, CV_32FC1, Uout_ptr);
    cv::Mat Dout = cv::Mat::zeros(KF_N, KF_N, CV_32FC1);
    for (int i = 0; i < KF_N; i++) Dout.at<float>(i, i) = Dout_ptr[i];

    cv::Mat Pout(KF_N, KF_N, CV_32FC1);
    Pout = ((Uout * Dout) * Uout.t());

    float tu_max_error_P = -10000;
    int cnt = 0;

    for (int i = 0; i < KF_N; i++) {
        for (int j = 0; j < KF_N; j++) {
            float kernel_output = Pout.at<float>(i, j);
            float refernce_output;
            if (tu_or_mu == 0)
                refernce_output = (float)kf.errorCovPre.at<double>(i, j);
            else
                refernce_output = (float)kf.errorCovPost.at<double>(i, j);

            float error = fabs(kernel_output - refernce_output);

            uint32_t error_int = *(int*)(float*)&error;

            if (error > tu_max_error_P || error_int == nan_xf) {
                tu_max_error_P = error;
                // std::cout << "ERROR: Difference in results for Pout at (" << i << "," << j << "): " << error <<
                // std::endl;
                cnt++;
            }
        }
    }

    float tu_max_error_X = -10000;

    for (int i = 0; i < KF_N; i++) {
        float kernel_output = Xout_ptr[i];

        float refernce_output;
        if (tu_or_mu == 0)
            refernce_output = (float)kf.statePre.at<double>(i);
        else
            refernce_output = (float)kf.statePost.at<double>(i);

        float error = fabs(kernel_output - refernce_output);

        uint32_t error_int = *(int*)(float*)&error;

        if (error > tu_max_error_X || error_int == nan_xf) {
            tu_max_error_X = error;
            // std::cout << "ERROR: Difference in results for Xout at " << i << ": " << error << std::endl;
            cnt++;
        }
    }

    std::cout << "INFO: Percentage of errors = " << (float)cnt * 100 / (KF_N * KF_N + KF_N) << "%" << std::endl;

    if (tu_max_error_X > tu_max_error_P)
        *error_out = tu_max_error_X;
    else
        *error_out = tu_max_error_P;
}

int main(int argc, char* argv[]) {
    // Vector sizes:
    size_t vec_nn_size_bytes = KF_N * KF_N * sizeof(float);
    size_t vec_mn_size_bytes = KF_M * KF_N * sizeof(float);
    size_t vec_nc_size_bytes = KF_N * KF_C * sizeof(float);
    size_t vec_n_size_bytes = KF_N * sizeof(float);
    size_t vec_m_size_bytes = KF_M * sizeof(float);
    size_t vec_c_size_bytes = KF_C * sizeof(float);

    // Vectors to hold input/output data:
    std::vector<float, aligned_allocator<float> > A_ptr(vec_nn_size_bytes);
    std::vector<float, aligned_allocator<float> > B_ptr(vec_nc_size_bytes);
    std::vector<float, aligned_allocator<float> > Uq_ptr(vec_nn_size_bytes);
    std::vector<float, aligned_allocator<float> > Dq_ptr(vec_n_size_bytes);
    std::vector<float, aligned_allocator<float> > H_ptr(vec_mn_size_bytes);
    std::vector<float, aligned_allocator<float> > X0_ptr(vec_n_size_bytes);
    std::vector<float, aligned_allocator<float> > U0_ptr(vec_nn_size_bytes);
    std::vector<float, aligned_allocator<float> > D0_ptr(vec_n_size_bytes);
    std::vector<float, aligned_allocator<float> > R_ptr(vec_m_size_bytes);
    std::vector<float, aligned_allocator<float> > u_ptr(vec_c_size_bytes);
    std::vector<float, aligned_allocator<float> > y_ptr(vec_m_size_bytes);
    std::vector<float, aligned_allocator<float> > Xout_ptr(vec_n_size_bytes);
    std::vector<float, aligned_allocator<float> > Uout_ptr(vec_nn_size_bytes);
    std::vector<float, aligned_allocator<float> > Dout_ptr(vec_n_size_bytes);

    std::vector<double> A_ptr_dp(KF_N * KF_N);
    std::vector<double> B_ptr_dp(KF_N * KF_C);
    std::vector<double> Uq_ptr_dp(KF_N * KF_N);
    std::vector<double> Dq_ptr_dp(KF_N);
    std::vector<double> H_ptr_dp(KF_M * KF_N);
    std::vector<double> X0_ptr_dp(KF_N);
    std::vector<double> U0_ptr_dp(KF_N * KF_N);
    std::vector<double> D0_ptr_dp(KF_N);
    std::vector<double> R_ptr_dp(KF_M);
    std::vector<double> u_ptr_dp(KF_C);
    std::vector<double> y_ptr_dp(KF_M);

    // Control flag for Xilinx Kalman Filter:
    unsigned char control_flag = 103;

    // Init A:
    int Acnt = 0;
    for (int i = 0; i < KF_N; i++) {
        for (int j = 0; j < KF_N; j++) {
            double val = ((double)rand() / (double)(RAND_MAX)) * 2.0;
            A_ptr_dp[Acnt] = val;
            A_ptr[Acnt++] = (float)val;
        }
    }

    // Init B:
    int Bcnt = 0;
    for (int i = 0; i < KF_N; i++) {
        for (int j = 0; j < KF_C; j++) {
            double val = ((double)rand() / (double)(RAND_MAX)) * 1.0;
            B_ptr_dp[Bcnt] = val;
            B_ptr[Bcnt++] = (float)val;
        }
    }

    // Init H:
    int Hcnt = 0;
    for (int i = 0; i < KF_M; i++) {
        for (int j = 0; j < KF_N; j++) {
            double val = ((double)rand() / (double)(RAND_MAX)) * 0.001;
            H_ptr_dp[Hcnt] = val;
            H_ptr[Hcnt++] = (float)val;
        }
    }

    // Init X0:
    for (int i = 0; i < KF_N; i++) {
        double val = ((double)rand() / (double)(RAND_MAX)) * 5.0;
        X0_ptr_dp[i] = val;
        X0_ptr[i] = (float)val;
    }

    // Init R:
    for (int i = 0; i < KF_M; i++) {
        double val = ((double)rand() / (double)(RAND_MAX)) * 0.01;
        R_ptr_dp[i] = val;
        R_ptr[i] = (float)val;
    }
    // Init U0:
    for (int i = 0; i < KF_N; i++) {
        for (int jn = (-i), j = 0; j < KF_N; jn++, j++) {
            int index = j + i * KF_N;
            if (jn < 0) {
                U0_ptr_dp[index] = 0;
                U0_ptr[index] = 0;
            } else if (jn == 0) {
                U0_ptr_dp[index] = 1;
                U0_ptr[index] = 1;
            } else {
                double val = ((double)rand() / (double)(RAND_MAX)) * 1.0;
                U0_ptr_dp[index] = val;
                U0_ptr[index] = (float)val;
            }
        }
    }

    // Init D0:
    for (int i = 0; i < KF_N; i++) {
        double val = ((double)rand() / (double)(RAND_MAX)) * 1.0;
        D0_ptr_dp[i] = val;
        D0_ptr[i] = (float)val;
    }

    // Init Uq:
    for (int i = 0; i < KF_N; i++) {
        for (int jn = (-i), j = 0; j < KF_N; jn++, j++) {
            int index = j + i * KF_N;
            if (jn < 0) {
                Uq_ptr_dp[index] = 0;
                Uq_ptr[index] = 0;
            } else if (jn == 0) {
                Uq_ptr_dp[index] = 1;
                Uq_ptr[index] = 1;
            } else {
                double val = ((double)rand() / (double)(RAND_MAX)) * 1.0;
                Uq_ptr_dp[index] = val;
                Uq_ptr[index] = (float)val;
            }
        }
    }

    // Init Dq:
    for (int i = 0; i < KF_N; i++) {
        double val = ((double)rand() / (double)(RAND_MAX)) * 1.0;
        Dq_ptr_dp[i] = val;
        Dq_ptr[i] = (float)val;
    }

    // Initialization of cv::Mat objects:
    std::cout << "INFO: Init cv::Mat objects." << std::endl;

    cv::Mat A(KF_N, KF_N, CV_64FC1, A_ptr_dp.data());
    cv::Mat B(KF_N, KF_C, CV_64FC1, B_ptr_dp.data());

    cv::Mat Uq(KF_N, KF_N, CV_64FC1, Uq_ptr_dp.data());
    cv::Mat Dq = cv::Mat::zeros(KF_N, KF_N, CV_64FC1);
    for (int i = 0; i < KF_N; i++) Dq.at<double>(i, i) = Dq_ptr_dp[i];
    cv::Mat Q(KF_N, KF_N, CV_64FC1);
    Q = Uq * Dq * Uq.t();

    cv::Mat H(KF_M, KF_N, CV_64FC1, H_ptr_dp.data());
    cv::Mat X0(KF_N, 1, CV_64FC1);
    for (int i = 0; i < KF_N; i++) X0.at<double>(i) = X0_ptr_dp[i];

    cv::Mat U0(KF_N, KF_N, CV_64FC1, U0_ptr_dp.data());
    cv::Mat D0 = cv::Mat::zeros(KF_N, KF_N, CV_64FC1);
    for (int i = 0; i < KF_N; i++) D0.at<double>(i, i) = D0_ptr_dp[i];
    cv::Mat P0(KF_N, KF_N, CV_64FC1);
    P0 = U0 * D0 * U0.t();

    cv::Mat R = cv::Mat::zeros(KF_M, KF_M, CV_64FC1);
    for (int i = 0; i < KF_M; i++) R.at<double>(i, i) = R_ptr_dp[i];
    cv::Mat uk(KF_C, 1, CV_64FC1);
    cv::Mat zk(KF_M, 1, CV_64FC1);

    std::cout << "INFO: Kalman Filter Verification:" << std::endl;
    std::cout << "\tNumber of state variables: " << KF_N << std::endl;
    std::cout << "\tNumber of measurements: " << KF_M << std::endl;
    std::cout << "\tNumber of control input: " << KF_C << std::endl;

    // OpenCv Kalman Filter in Double Precision
    cv::KalmanFilter kf(KF_N, KF_M, KF_C, CV_64F);
    kf.statePost = X0;
    kf.errorCovPost = P0;
    kf.transitionMatrix = A;
    kf.processNoiseCov = Q;
    kf.measurementMatrix = H;
    kf.measurementNoiseCov = R;
    kf.controlMatrix = B;

    // Init control parameter:
    for (int i = 0; i < KF_C; i++) {
        double val = ((double)rand() / (double)(RAND_MAX)) * 10.0;
        u_ptr[i] = (float)val;
        uk.at<double>(i) = val;
    }

    // OpenCv Kalman Filter in Double Precision - predict:
    kf.predict(uk);

    // Init measurement parameter:
    for (int i = 0; i < KF_M; i++) {
        double val = ((double)rand() / (double)(RAND_MAX)) * 5.0;
        y_ptr[i] = (float)val;
        zk.at<double>(i) = val;
    }

    // OpenCv Kalman Filter in Double Precision - correct/update:
    kf.correct(zk);

    // xfOpenCV Kalman Filter in Single Precision - OpenCL section:

    cl_int err;
    std::cout << "INFO: Running OpenCL section." << std::endl;

    // Get the device:
    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    // Context, command queue and device name:
    OCL_CHECK(err, cl::Context context(device, NULL, NULL, NULL, &err));
    OCL_CHECK(err, cl::CommandQueue queue(context, device, CL_QUEUE_PROFILING_ENABLE, &err));
    OCL_CHECK(err, std::string device_name = device.getInfo<CL_DEVICE_NAME>(&err));

    std::cout << "INFO: Device found - " << device_name << std::endl;

    // Load binary:
    unsigned fileBufSize;
    std::string binaryFile = argv[1];
    char* fileBuf = xcl::read_binary_file(binaryFile, fileBufSize);
    cl::Program::Binaries bins{{fileBuf, fileBufSize}};
    devices.resize(1);
    OCL_CHECK(err, cl::Program program(context, devices, bins, NULL, &err));

    // Create a kernel:
    OCL_CHECK(err, cl::Kernel kernel(program, "kalman", &err));

    // Allocate the buffers:
    OCL_CHECK(err, cl::Buffer buffer_inA(context, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR, vec_nn_size_bytes,
                                         A_ptr.data(), &err));
    OCL_CHECK(err, cl::Buffer buffer_inB(context, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR, vec_nc_size_bytes,
                                         B_ptr.data(), &err));
    OCL_CHECK(err, cl::Buffer buffer_inUq(context, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR, vec_nn_size_bytes,
                                          Uq_ptr.data(), &err));
    OCL_CHECK(err, cl::Buffer buffer_inDq(context, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR, vec_n_size_bytes,
                                          Dq_ptr.data(), &err));
    OCL_CHECK(err, cl::Buffer buffer_inH(context, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR, vec_mn_size_bytes,
                                         H_ptr.data(), &err));
    OCL_CHECK(err, cl::Buffer buffer_inX0(context, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR, vec_n_size_bytes,
                                          X0_ptr.data(), &err));
    OCL_CHECK(err, cl::Buffer buffer_inU0(context, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR, vec_nn_size_bytes,
                                          U0_ptr.data(), &err));
    OCL_CHECK(err, cl::Buffer buffer_inD0(context, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR, vec_n_size_bytes,
                                          D0_ptr.data(), &err));
    OCL_CHECK(err, cl::Buffer buffer_inR(context, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR, vec_m_size_bytes,
                                         R_ptr.data(), &err));
    OCL_CHECK(err, cl::Buffer buffer_inu(context, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR, vec_c_size_bytes,
                                         u_ptr.data(), &err));
    OCL_CHECK(err, cl::Buffer buffer_iny(context, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR, vec_m_size_bytes,
                                         y_ptr.data(), &err));

    OCL_CHECK(err, cl::Buffer buffer_outX(context, CL_MEM_WRITE_ONLY | CL_MEM_USE_HOST_PTR, vec_n_size_bytes,
                                          Xout_ptr.data(), &err));
    OCL_CHECK(err, cl::Buffer buffer_outU(context, CL_MEM_WRITE_ONLY | CL_MEM_USE_HOST_PTR, vec_nn_size_bytes,
                                          Uout_ptr.data(), &err));
    OCL_CHECK(err, cl::Buffer buffer_outD(context, CL_MEM_WRITE_ONLY | CL_MEM_USE_HOST_PTR, vec_n_size_bytes,
                                          Dout_ptr.data(), &err));

    // Set kernel arguments:
    OCL_CHECK(err, err = kernel.setArg(0, buffer_inA));
    OCL_CHECK(err, err = kernel.setArg(1, buffer_inB));
    OCL_CHECK(err, err = kernel.setArg(2, buffer_inUq));
    OCL_CHECK(err, err = kernel.setArg(3, buffer_inDq));
    OCL_CHECK(err, err = kernel.setArg(4, buffer_inH));
    OCL_CHECK(err, err = kernel.setArg(5, buffer_inX0));
    OCL_CHECK(err, err = kernel.setArg(6, buffer_inU0));
    OCL_CHECK(err, err = kernel.setArg(7, buffer_inD0));
    OCL_CHECK(err, err = kernel.setArg(8, buffer_inR));
    OCL_CHECK(err, err = kernel.setArg(9, buffer_inu));
    OCL_CHECK(err, err = kernel.setArg(10, buffer_iny));
    OCL_CHECK(err, err = kernel.setArg(11, control_flag));
    OCL_CHECK(err, err = kernel.setArg(12, buffer_outX));
    OCL_CHECK(err, err = kernel.setArg(13, buffer_outU));
    OCL_CHECK(err, err = kernel.setArg(14, buffer_outD));

    // Copy input data to device global memory
    OCL_CHECK(err, err = queue.enqueueMigrateMemObjects(
                       {buffer_inA, buffer_inB, buffer_inUq, buffer_inDq, buffer_inH, buffer_inX0, buffer_inU0,
                        buffer_inD0, buffer_inR, buffer_inu, buffer_iny},
                       0));

    // Execute the kernel:
    OCL_CHECK(err, err = queue.enqueueTask(kernel));

    // Copy Result from Device Global Memory to Host Local Memory
    queue.enqueueMigrateMemObjects({buffer_outX, buffer_outU, buffer_outD}, CL_MIGRATE_MEM_OBJECT_HOST);

    // Clean up:
    queue.finish();

    // Results verification:
    float error;
    error_check(kf, Xout_ptr.data(), Uout_ptr.data(), Dout_ptr.data(), 1, &error);

    if (error < 0.001f) {
        std::cout << "INFO: Test Pass" << std::endl;
        return 0;
    } else {
        std::cout << "ERROR: Test Fail" << std::endl;
        return -1;
    }
}
