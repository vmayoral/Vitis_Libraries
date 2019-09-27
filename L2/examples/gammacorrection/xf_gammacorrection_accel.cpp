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

#include "xf_gammacorrection_config.h"

extern "C" {
void gammacorrection_accel(
    ap_uint<INPUT_PTR_WIDTH>* img_inp, ap_uint<OUTPUT_PTR_WIDTH>* img_out, float gammaval, int rows, int cols) {
// clang-format off
#pragma HLS INTERFACE m_axi     port=img_inp  offset=slave bundle=gmem1
#pragma HLS INTERFACE m_axi     port=img_out  offset=slave bundle=gmem2
#pragma HLS INTERFACE s_axilite port=gammaval     bundle=control
#pragma HLS INTERFACE s_axilite port=rows     bundle=control
#pragma HLS INTERFACE s_axilite port=cols     bundle=control
#pragma HLS INTERFACE s_axilite port=return   bundle=control
    // clang-format on

    xf::cv::Mat<IN_TYPE, HEIGHT, WIDTH, NPC1> in_mat(rows, cols);
// clang-format off
    #pragma HLS stream variable=in_mat.data depth=2
    // clang-format on

    xf::cv::Mat<IN_TYPE, HEIGHT, WIDTH, NPC1> out_mat(rows, cols);
// clang-format off
    #pragma HLS stream variable=out_mat.data depth=2
// clang-format on

#pragma HLS DATAFLOW

    xf::cv::Array2xfMat<INPUT_PTR_WIDTH, IN_TYPE, HEIGHT, WIDTH, NPC1>(img_inp, in_mat);

    xf::cv::gammacorrection<IN_TYPE, IN_TYPE, HEIGHT, WIDTH, NPC1>(in_mat, out_mat, gammaval);

    xf::cv::xfMat2Array<OUTPUT_PTR_WIDTH, IN_TYPE, HEIGHT, WIDTH, NPC1>(out_mat, img_out);
}
}
