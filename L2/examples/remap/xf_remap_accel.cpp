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
HOWEVER CXFSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

***************************************************************************/

#include "xf_remap_config.h"

extern "C" {

void remap(ap_uint<PTR_IMG_WIDTH>* img_in, float* map_x, float* map_y, ap_uint<PTR_IMG_WIDTH>* img_out) {
    #pragma HLS INTERFACE m_axi      port=img_in        offset=slave  bundle=gmem0
    #pragma HLS INTERFACE s_axilite  port=img_in 			          bundle=control
    #pragma HLS INTERFACE m_axi      port=map_x         offset=slave  bundle=gmem1
    #pragma HLS INTERFACE s_axilite  port=map_x 			          bundle=control
    #pragma HLS INTERFACE m_axi      port=map_y         offset=slave  bundle=gmem2
    #pragma HLS INTERFACE s_axilite  port=map_y 			          bundle=control
    #pragma HLS INTERFACE m_axi      port=img_out       offset=slave  bundle=gmem3
    #pragma HLS INTERFACE s_axilite  port=img_out 			          bundle=control
    #pragma HLS INTERFACE s_axilite  port=return 			          bundle=control

    xf::cv::Mat<TYPE, HEIGHT, WIDTH, NPC1> imgInput;
    xf::cv::Mat<TYPE_XY, HEIGHT, WIDTH, NPC1> mapX;
    xf::cv::Mat<TYPE_XY, HEIGHT, WIDTH, NPC1> mapY;
    xf::cv::Mat<TYPE, HEIGHT, WIDTH, NPC1> imgOutput;

    const int sdepth = WIDTH / NPC1;

    for (unsigned int i = 0; i < HEIGHT * WIDTH; ++i) {
        #pragma HLS PIPELINE
        mapX.data[i] = map_x[i];
        mapY.data[i] = map_y[i];
    }

    #pragma HLS STREAM variable=imgInput.data depth=sdepth
    #pragma HLS STREAM variable=mapX.data depth=sdepth
    #pragma HLS STREAM variable=mapY.data depth=sdepth
    #pragma HLS STREAM variable=imgOutput.data depth=sdepth

    #pragma HLS DATAFLOW

    // Retrieve xf::cv::Mat objects from img_in data:
    xf::cv::Array2xfMat<PTR_IMG_WIDTH, TYPE, HEIGHT, WIDTH, NPC1>(img_in, imgInput);

    // Run xfOpenCV kernel:
    xf::cv::remap<XF_WIN_ROWS, XF_INTERPOLATION_TYPE, TYPE, TYPE_XY, TYPE, HEIGHT, WIDTH, NPC1, XF_USE_URAM>(
        imgInput, imgOutput, mapX, mapY);

    // Convert _dst xf::cv::Mat object to output array:
    xf::cv::xfMat2Array<PTR_IMG_WIDTH, TYPE, HEIGHT, WIDTH, NPC1>(imgOutput, img_out);

    return;
} // End of kernel

} // End of extern C
