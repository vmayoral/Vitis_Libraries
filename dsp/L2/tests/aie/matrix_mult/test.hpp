#ifndef _DSPLIB_TEST_HPP_
#define _DSPLIB_TEST_HPP_

// This file holds the header for the test harness of the matrix mult graph class

#include <adf.h>
#include <vector>
#include "utils.hpp"

#include "uut_config.h"
#include "test_stim.hpp"

// The following macro allows this test harness to be used
// to stimulate the UUT (kernel code for this library element)
// or its reference model by makefile directive.
#define Q(x) #x
#define QUOTE(x) Q(x)

#ifndef UUT_GRAPH
#define UUT_GRAPH matrix_mult_graph
#endif

#include QUOTE(UUT_GRAPH.hpp)

using namespace adf;

namespace xf {
namespace dsp {
namespace aie {
namespace testcase {

class test_graph : public graph {
   private:
   public:
#ifdef USING_UUT
    port<input> inA[P_CASC_LEN];
    port<input> inB[P_CASC_LEN];
#else
    port<input> inA;
    port<input> inB;
#endif
    port<output> out;

    // Constructor
    test_graph() {
        printf("========================\n");
        printf("== UUT Graph Class: ");
        printf(QUOTE(UUT_GRAPH));
        printf("\n");
        printf("========================\n");
        printf("Input samples A   = %d \n", P_INPUT_SAMPLES_A);
        printf("Input window A [B]= %lu \n", P_INPUT_SAMPLES_A * sizeof(T_DATA_A));
        printf("Input samples B   = %d \n", P_INPUT_SAMPLES_B);
        printf("Input window B [B]= %lu \n", P_INPUT_SAMPLES_B * sizeof(T_DATA_B));
        printf("Output samples  = %d \n", P_OUTPUT_SAMPLES);
        printf("Shift           = %d \n", P_SHIFT);
        printf("P_ROUND_MODE      = %d \n", P_ROUND_MODE);
        printf("Data type       = ");
        printf(QUOTE(T_DATA_A) QUOTE(T_DATA_B));
        printf("\n");
        printf("\n");
        namespace dsplib = xf::dsp::aie;

        dsplib::blas::matrix_mult::UUT_GRAPH<T_DATA_A, T_DATA_B, P_DIM_A, P_DIM_AB, P_DIM_B, P_SHIFT, P_ROUND_MODE,
                                             P_DIM_A_LEADING, P_DIM_B_LEADING, P_DIM_OUT_LEADING, P_ADD_TILING_A,
                                             P_ADD_TILING_B, P_ADD_DETILING_OUT, P_INPUT_WINDOW_VSIZE_A,
                                             P_INPUT_WINDOW_VSIZE_B, P_CASC_LEN>
            mmultGraph;

// Make connections
// Size of window in Bytes.
// broadcast
#ifdef USING_UUT
        for (int i = 0; i < P_CASC_LEN; i++) {
            connect<>(inA[i], mmultGraph.inA[i]);
            connect<>(inB[i], mmultGraph.inB[i]);
        }
#else
        connect<>(inA, mmultGraph.inA);
        connect<>(inB, mmultGraph.inB);
#endif

        connect<>(mmultGraph.out, out);

        printf("========================\n");
    };
};
}
}
}
};
#endif // _DSPLIB_TEST_HPP_

/*  (c) Copyright 2020 Xilinx, Inc. All rights reserved.

    This file contains confidential and proprietary information
    of Xilinx, Inc. and is protected under U.S. and
    international copyright and other intellectual property
    laws.

    DISCLAIMER
    This disclaimer is not a license and does not grant any
    rights to the materials distributed herewith. Except as
    otherwise provided in a valid license issued to you by
    Xilinx, and to the maximum extent permitted by applicable
    law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
    WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
    AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
    BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
    INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
    (2) Xilinx shall not be liable (whether in contract or tort,
    including negligence, or under any other theory of
    liability) for any loss or damage of any kind or nature
    related to, arising under or in connection with these
    materials, including for any direct, or any indirect,
    special, incidental, or consequential loss or damage
    (including loss of data, profits, goodwill, or any type of
    loss or damage suffered as a result of any action brought
    by a third party) even if such damage or loss was
    reasonably foreseeable or Xilinx had been advised of the
    possibility of the same.

    CRITICAL APPLICATIONS
    Xilinx products are not designed or intended to be fail-
    safe, or for use in any application requiring fail-safe
    performance, such as life-support or safety devices or
    systems, Class III medical devices, nuclear facilities,
    applications related to the deployment of airbags, or any
    other applications that could lead to death, personal
    injury, or severe property or environmental damage
    (individually and collectively, "Critical
    Applications"). Customer assumes the sole risk and
    liability of any use of Xilinx products in Critical
    Applications, subject only to applicable laws and
    regulations governing limitations on product liability.

    THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
    PART OF THIS FILE AT ALL TIMES.                       */