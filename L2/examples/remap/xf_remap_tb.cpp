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
#include "xf_remap_config.h"

int main(int argc, char** argv) {
    if (argc != 5) {
        std::cout << "Usage: " << argv[0] << " <XCLBIN File> <INPUT IMAGE PATH 1> <INPUT MAP X> <INPUT MAP Y>"
                  << std::endl;
        return EXIT_FAILURE;
    }

    cv::Mat src, ocv_remapped, hls_remapped;
    cv::Mat map_x, map_y, diff;

    // Reading in the image:
#if GRAY
    src = cv::imread(argv[2], 0); // read image Grayscale
#else
    src = cv::imread(argv[2], 1); // read image RGB
#endif

    if (!src.data) {
        std::cout << "ERROR: Cannot open image " << argv[2] << std::endl;
        return EXIT_FAILURE;
    }

    // Allocate memory for the outputs:
    std::cout << "INFO: Allocate memory for input and output data." << std::endl;
    ocv_remapped.create(src.rows, src.cols, src.type()); // opencv result
    map_x.create(src.rows, src.cols, CV_32FC1);          // Mapx for opencv remap function
    map_y.create(src.rows, src.cols, CV_32FC1);          // Mapy for opencv remap function
    hls_remapped.create(src.rows, src.cols, src.type()); // create memory for output images
    diff.create(src.rows, src.cols, src.type());

    // Initialize the float maps:
    std::cout << "INFO: Initialize maps." << std::endl;
    for (int i = 0; i < src.rows; i++) {
        for (int j = 0; j < src.cols; j++) {
            float valx = float(src.cols - j), valy = float(i);
            map_x.at<float>(i, j) = valx;
            map_y.at<float>(i, j) = valy;
        }
    }

    // Opencv reference:
    std::cout << "INFO: Run reference function in CV." << std::endl;
#if INTERPOLATION == 0
    cv::remap(src, ocv_remapped, map_x, map_y, cv::INTER_NEAREST, cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0));
#else
    cv::remap(src, ocv_remapped, map_x, map_y, cv::INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0));
#endif

    // OpenCL section:
    size_t image_in_size_bytes = src.rows * src.cols * sizeof(unsigned char) * CHANNELS;
    size_t map_in_size_bytes = src.rows * src.cols * sizeof(float);
    size_t image_out_size_bytes = image_in_size_bytes;

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
    OCL_CHECK(err, cl::Kernel kernel(program, "remap", &err));

    // Allocate the buffers:
    OCL_CHECK(err, cl::Buffer buffer_inImage(context, CL_MEM_READ_ONLY, image_in_size_bytes, NULL, &err));
    OCL_CHECK(err, cl::Buffer buffer_inMapX(context, CL_MEM_READ_ONLY, map_in_size_bytes, NULL, &err));
    OCL_CHECK(err, cl::Buffer buffer_inMapY(context, CL_MEM_READ_ONLY, map_in_size_bytes, NULL, &err));
    OCL_CHECK(err, cl::Buffer buffer_outImage(context, CL_MEM_WRITE_ONLY, image_out_size_bytes, NULL, &err));

    // Set kernel arguments:
    OCL_CHECK(err, err = kernel.setArg(0, buffer_inImage));
    OCL_CHECK(err, err = kernel.setArg(1, buffer_inMapX));
    OCL_CHECK(err, err = kernel.setArg(2, buffer_inMapY));
    OCL_CHECK(err, err = kernel.setArg(3, buffer_outImage));

    // Initialize the buffers:
    cl::Event event;

    OCL_CHECK(err, queue.enqueueWriteBuffer(buffer_inImage,      // buffer on the FPGA
                                            CL_TRUE,             // blocking call
                                            0,                   // buffer offset in bytes
                                            image_in_size_bytes, // Size in bytes
                                            src.data,            // Pointer to the data to copy
                                            nullptr, &event));

    OCL_CHECK(err, queue.enqueueWriteBuffer(buffer_inMapX,     // buffer on the FPGA
                                            CL_TRUE,           // blocking call
                                            0,                 // buffer offset in bytes
                                            map_in_size_bytes, // Size in bytes
                                            map_x.data,        // Pointer to the data to copy
                                            nullptr, &event));

    OCL_CHECK(err, queue.enqueueWriteBuffer(buffer_inMapY,     // buffer on the FPGA
                                            CL_TRUE,           // blocking call
                                            0,                 // buffer offset in bytes
                                            map_in_size_bytes, // Size in bytes
                                            map_y.data,        // Pointer to the data to copy
                                            nullptr, &event));

    // Execute the kernel:
    OCL_CHECK(err, err = queue.enqueueTask(kernel));

    // Copy Result from Device Global Memory to Host Local Memory
    queue.enqueueReadBuffer(buffer_outImage, // This buffers data will be read
                            CL_TRUE,         // blocking call
                            0,               // offset
                            image_out_size_bytes,
                            hls_remapped.data, // Data will be stored here
                            nullptr, &event);

    // Clean up:
    queue.finish();

    // Save the results:
    cv::imwrite("output_ocv.jpg", ocv_remapped); // Opencv Result
    cv::imwrite("hls_out.jpg", hls_remapped);

    // Results verification:
    cv::absdiff(ocv_remapped, hls_remapped, diff);
    cv::imwrite("diff.png", diff);

    // Find minimum and maximum differences.
    double minval = 256, maxval = 0;
    int cnt = 0;
    for (int i = 0; i < src.rows; i++) {
        for (int j = 0; j < src.cols; j++) {
            uchar v = diff.at<uchar>(i, j);
            if (v > 0) cnt++;
            if (minval > v) minval = v;
            if (maxval < v) maxval = v;
        }
    }

    float err_per = 100.0 * (float)cnt / (src.rows * src.cols);

    std::cout << "INFO: Verification results:" << std::endl;
    std::cout << "\tMinimum error in intensity = " << minval << std::endl;
    std::cout << "\tMaximum error in intensity = " << maxval << std::endl;
    std::cout << "\tPercentage of pixels above error threshold = " << err_per << std::endl;

    if (err_per > 0.02f) {
        std::cout << "ERROR: Test Failed." << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}
