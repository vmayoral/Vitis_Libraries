/*
 * Copyright 2019 Xilinx, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "common/xf_headers.hpp"
#include "xf_gaussian_filter_config.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: <executable> <input image path> \n");
        return -1;
    }

    cv::Mat in_img, out_img, ocv_ref, in_img_gau;
    cv::Mat in_gray, in_gray1, diff;

#if GRAY
    in_img = cv::imread(argv[1], 0); // reading in the color image
#else
    in_img = cv::imread(argv[1], 1); // reading in the color image
#endif
    if (!in_img.data) {
        printf("Failed to load the image ... !!!");
        return -1;
    }
// extractChannel(in_img, in_img, 1);
#if GRAY

    out_img.create(in_img.rows, in_img.cols, CV_8UC1); // create memory for output image
    diff.create(in_img.rows, in_img.cols, CV_8UC1);    // create memory for OCV-ref image
    ocv_ref.create(in_img.rows, in_img.cols, CV_8UC1); // create memory for OCV-ref image

#else
    out_img.create(in_img.rows, in_img.cols, CV_8UC3); // create memory for output image
    diff.create(in_img.rows, in_img.cols, CV_8UC3);    // create memory for OCV-ref image
    ocv_ref.create(in_img.rows, in_img.cols, CV_8UC3); // create memory for OCV-ref image
#endif

#if FILTER_WIDTH == 3
    float sigma = 0.5f;
#endif
#if FILTER_WIDTH == 7
    float sigma = 1.16666f;
#endif
#if FILTER_WIDTH == 5
    float sigma = 0.8333f;
#endif

    // OpenCV Gaussian filter function
    cv::GaussianBlur(in_img, ocv_ref, cvSize(FILTER_WIDTH, FILTER_WIDTH), FILTER_WIDTH / 6.0, FILTER_WIDTH / 6.0,
                     cv::BORDER_CONSTANT);
    imwrite("output_ocv.png", ocv_ref);

    static xf::cv::Mat<TYPE, HEIGHT, WIDTH, NPC1> imgInput(in_img.rows, in_img.cols);
    static xf::cv::Mat<TYPE, HEIGHT, WIDTH, NPC1> imgOutput(in_img.rows, in_img.cols);

    imgInput.copyTo(in_img.data);

    gaussian_filter_accel(imgInput, imgOutput, sigma);

    // Write output image
    xf::cv::imwrite("hls_out.jpg", imgOutput);

    // Compute absolute difference image
    xf::cv::absDiff(ocv_ref, imgOutput, diff);

    imwrite("error.png", diff); // Save the difference image for debugging purpose

    float err_per;
    xf::cv::analyzeDiff(diff, 0, err_per);

    return 0;
}
