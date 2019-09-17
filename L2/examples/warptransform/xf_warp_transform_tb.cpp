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
#include "xf_warp_transform_config.h"

// Changing transformation matrix dimensions with transform Affine 2x3, Perspecitve 3x3
#if TRANSFORM_TYPE == 1
#define TRMAT_DIM2 3
#define TRMAT_DIM1 3
#else
#define TRMAT_DIM2 3
#define TRMAT_DIM1 2
#endif

// Random Number generator limits
#define M_NUMI1 1
#define M_NUMI2 20

// Image operations and transformation matrix input format
typedef float image_oper;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <XCLBIN File> <INPUT IMAGE PATH 1>" << std::endl;
        return EXIT_FAILURE;
    }

    cv::RNG rng;
    std::vector<float> R(9);
    cv::Mat _transformation_matrix(TRMAT_DIM1, TRMAT_DIM2, CV_32FC1);
    cv::Mat _transformation_matrix_2(TRMAT_DIM1, TRMAT_DIM2, CV_32FC1);

#if TRANSFORM_TYPE == 1
    cv::Point2f src_p[4];
    cv::Point2f dst_p[4];
    src_p[0] = cv::Point2f(0.0f, 0.0f);
    src_p[1] = cv::Point2f(WIDTH - 1, 0.0f);
    src_p[2] = cv::Point2f(WIDTH - 1, HEIGHT - 1);
    src_p[3] = cv::Point2f(0.0f, HEIGHT - 1);
    //	  to points
    dst_p[0] = cv::Point2f(rng.uniform(int(M_NUMI1), int(M_NUMI2)), rng.uniform(int(M_NUMI1), int(M_NUMI2)));
    dst_p[1] = cv::Point2f(WIDTH - rng.uniform(int(M_NUMI1), int(M_NUMI2)), rng.uniform(int(M_NUMI1), int(M_NUMI2)));
    dst_p[2] =
        cv::Point2f(WIDTH - rng.uniform(int(M_NUMI1), int(M_NUMI2)), HEIGHT - rng.uniform(int(M_NUMI1), int(M_NUMI2)));
    dst_p[3] = cv::Point2f(rng.uniform(int(M_NUMI1), int(M_NUMI2)), HEIGHT - rng.uniform(int(M_NUMI1), int(M_NUMI2)));

    _transformation_matrix = cv::getPerspectiveTransform(dst_p, src_p);
    cv::Mat transform_mat = _transformation_matrix;
#else
    cv::Point2f src_p[3];
    cv::Point2f dst_p[3];
    src_p[0] = cv::Point2f(0.0f, 0.0f);
    src_p[1] = cv::Point2f(WIDTH - 1, 0.0f);
    src_p[2] = cv::Point2f(0.0f, HEIGHT - 1);
    //	  to points
    dst_p[0] = cv::Point2f(rng.uniform(int(M_NUMI1), int(M_NUMI2)), rng.uniform(int(M_NUMI1), int(M_NUMI2)));
    dst_p[1] = cv::Point2f(WIDTH - rng.uniform(int(M_NUMI1), int(M_NUMI2)), rng.uniform(int(M_NUMI1), int(M_NUMI2)));
    dst_p[2] = cv::Point2f(rng.uniform(int(M_NUMI1), int(M_NUMI2)), HEIGHT - rng.uniform(int(M_NUMI1), int(M_NUMI2)));

    _transformation_matrix = cv::getAffineTransform(dst_p, src_p);
    cv::Mat transform_mat = _transformation_matrix;
#endif

    int i = 0, j = 0;

    std::cout << "INFO: Transformation Matrix is:";
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
#if TRANSFORM_TYPE == 1
            R[i * 3 + j] = image_oper(transform_mat.at<double>(i, j));
            _transformation_matrix_2.at<image_oper>(i, j) = image_oper(transform_mat.at<double>(i, j));
#else
            if (i == 2) {
                R[i * 3 + j] = 0;
            } else {
                R[i * 3 + j] = image_oper(transform_mat.at<double>(i, j));
                _transformation_matrix_2.at<image_oper>(i, j) = image_oper(transform_mat.at<double>(i, j));
            }
#endif
            std::cout << R[i * 3 + j] << " ";
        }
        std::cout << "\n";
    }

    cv::Mat image_input, image_output, diff_img;

    // Reading in the image:
    image_input = cv::imread(argv[2], 0);

    if (!image_input.data) {
        std::cout << "ERROR: Cannot open image " << argv[2] << std::endl;
        return EXIT_FAILURE;
    }

    // Allocate memory for the output images:
    image_output.create(image_input.rows, image_input.cols, image_input.depth());
    diff_img.create(image_input.rows, image_input.cols, image_input.depth());

    // OpenCL section:
    size_t image_in_size_bytes = image_input.rows * image_input.cols * image_input.channels() * sizeof(unsigned char);
    size_t image_out_size_bytes = image_in_size_bytes;
    size_t vec_in_size_bytes = R.size() * sizeof(float);

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
    OCL_CHECK(err, cl::Kernel kernel(program, "warptransform", &err));

    // Allocate the buffers:
    OCL_CHECK(err, cl::Buffer buffer_inImage(context, CL_MEM_READ_ONLY, image_in_size_bytes, NULL, &err));
    OCL_CHECK(err, cl::Buffer buffer_inVec(context, CL_MEM_READ_ONLY, vec_in_size_bytes, NULL, &err));
    OCL_CHECK(err, cl::Buffer buffer_outImage(context, CL_MEM_WRITE_ONLY, image_out_size_bytes, NULL, &err));

    // Set kernel arguments:
    OCL_CHECK(err, err = kernel.setArg(0, buffer_inImage));
    OCL_CHECK(err, err = kernel.setArg(1, buffer_inVec));
    OCL_CHECK(err, err = kernel.setArg(2, buffer_outImage));

    // Initialize the buffers:
    cl::Event event;

    OCL_CHECK(err, queue.enqueueWriteBuffer(buffer_inImage,      // buffer on the FPGA
                                            CL_TRUE,             // blocking call
                                            0,                   // buffer offset in bytes
                                            image_in_size_bytes, // Size in bytes
                                            image_input.data,    // Pointer to the data to copy
                                            nullptr, &event));

    OCL_CHECK(err, queue.enqueueWriteBuffer(buffer_inVec,      // buffer on the FPGA
                                            CL_TRUE,           // blocking call
                                            0,                 // buffer offset in bytes
                                            vec_in_size_bytes, // Size in bytes
                                            R.data(),          // Pointer to the data to copy
                                            nullptr, &event));

    // Execute the kernel:
    OCL_CHECK(err, err = queue.enqueueTask(kernel));

    // Copy Result from Device Global Memory to Host Local Memory
    queue.enqueueReadBuffer(buffer_outImage, // This buffers data will be read
                            CL_TRUE,         // blocking call
                            0,               // offset
                            image_out_size_bytes,
                            image_output.data, // Data will be stored here
                            nullptr, &event);

    // Clean up:
    queue.finish();

    cv::imwrite("output.png", image_output);

    // OpenCV reference:
    cv::Mat opencv_image;
    opencv_image.create(image_input.rows, image_input.cols, image_input.depth());
    for (int I1 = 0; I1 < opencv_image.rows; I1++) {
        for (int J1 = 0; J1 < opencv_image.cols; J1++) {
            opencv_image.at<uint8_t>(I1, J1) = 0;
        }
    }

#if TRANSFORM_TYPE == 1
#if INTERPOLATION == 1
    cv::warpPerspective(image_input, opencv_image, _transformation_matrix_2,
                        cv::Size(image_input.cols, image_input.rows), cv::INTER_LINEAR + cv::WARP_INVERSE_MAP,
                        cv::BORDER_TRANSPARENT, 80);
#else
    cv::warpPerspective(image_input, opencv_image, _transformation_matrix_2,
                        cv::Size(image_input.cols, image_input.rows), cv::INTER_NEAREST + cv::WARP_INVERSE_MAP,
                        cv::BORDER_TRANSPARENT, 80);
#endif
#else
#if INTERPOLATION == 1
    cv::warpAffine(image_input, opencv_image, _transformation_matrix_2, cv::Size(image_input.cols, image_input.rows),
                   cv::INTER_LINEAR + cv::WARP_INVERSE_MAP, cv::BORDER_TRANSPARENT, 80);
#else
    cv::warpAffine(image_input, opencv_image, _transformation_matrix_2, cv::Size(image_input.cols, image_input.rows),
                   cv::INTER_NEAREST + cv::WARP_INVERSE_MAP, cv::BORDER_TRANSPARENT, 80);
#endif
#endif

    cv::imwrite("opencv_output.png", opencv_image);

    // Results verification:
    uint8_t max_err = 0, min_err = 255;
    int num_errs = 0, num_errs1 = 0;

    for (i = 0; i < image_output.rows; i++) {
        for (j = 0; j < image_output.cols; j++) {
            if (image_output.at<uint8_t>(i, j) == opencv_image.at<uint8_t>(i, j)) {
                diff_img.at<uint8_t>(i, j) = 0;
            } else {
                if (image_output.at<uint8_t>(i, j) > opencv_image.at<uint8_t>(i, j)) {
                    diff_img.at<uint8_t>(i, j) = image_output.at<uint8_t>(i, j) - opencv_image.at<uint8_t>(i, j);
                } else {
                    diff_img.at<uint8_t>(i, j) = -image_output.at<uint8_t>(i, j) + opencv_image.at<uint8_t>(i, j);
                }
                num_errs = num_errs + 1;
                if (max_err < diff_img.at<uint8_t>(i, j)) {
                    max_err = diff_img.at<uint8_t>(i, j);
                }
                if (min_err > diff_img.at<uint8_t>(i, j)) {
                    min_err = diff_img.at<uint8_t>(i, j);
                }

                if (diff_img.at<uint8_t>(i, j) > 0) {
                    num_errs1 = num_errs1 + 1;
                    diff_img.at<uint8_t>(i, j) = 255;
                }
            }
        }
    }

    cv::imwrite("diff_image.png", diff_img);
    min_err = (min_err == uint8_t(255)) ? uint8_t(0) : min_err;

    std::cout << "INFO: Calucalted results: " << std::endl;
    std::cout << "\tMax_err: " << max_err << "\tMin_err: " << min_err << "\tNum_errs: " << num_errs
              << "\tNum_errs > 1: " << num_errs1 << std::endl;

    if (num_errs > 10000) {
        std::cout << "ERROR: Test Failed." << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}
