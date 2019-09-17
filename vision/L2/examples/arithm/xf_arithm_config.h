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

#ifndef _XF_ARITHM_CONFIG_H_
#define _XF_ARITHM_CONFIG_H_

#include "hls_stream.h"
#include <ap_int.h>
#include "xf_config_params.h"
#include "common/xf_common.h"
#include "common/xf_utility.h"

#include "core/xf_arithm.hpp"


#define HEIGHT 2160
#define WIDTH 3840


// Resolve function name:
#if FUNCT_NUM == 0
#define FUNCT_NAME add
#elif FUNCT_NUM == 1
#define FUNCT_NAME addS
#elif FUNCT_NUM == 2
#define FUNCT_NAME subtract
#elif FUNCT_NUM == 3
#define FUNCT_NAME SubS
#elif FUNCT_NUM == 4
#define FUNCT_NAME SubRS
#define FUNCT_SUBRS
#elif FUNCT_NUM == 5
#define FUNCT_NAME multiply
#define FUNCT_MULTIPLY
#elif FUNCT_NUM == 6
#define FUNCT_NAME absdiff
#elif FUNCT_NUM == 7
#define FUNCT_NAME bitwise_and
#elif FUNCT_NUM == 8
#define FUNCT_NAME bitwise_xor
#elif FUNCT_NUM == 9
#define FUNCT_NAME bitwise_not
#define FUNCT_BITWISENOT
#elif FUNCT_NUM == 10
#define FUNCT_NAME bitwise_or
#elif FUNCT_NUM == 11
#define FUNCT_NAME min
#elif FUNCT_NUM == 12
#define FUNCT_NAME max
#elif FUNCT_NUM == 13
#define FUNCT_NAME set
#elif FUNCT_NUM == 14
#define FUNCT_NAME zero
#define FUNCT_ZERO
#elif FUNCT_NUM == 15
#define FUNCT_NAME compare
#else
#define FUNCT_NAME add
#endif

// Resolve ARRAY/SCALAR mode based on function name FUNCT_NUM:
#if SCALAR == 1
#if FUNCT_NUM == 1 || FUNCT_NUM == 3 || FUNCT_NUM == 4 || FUNCT_NUM == 15 || FUNCT_NUM == 11 || FUNCT_NUM == 12 || \
    FUNCT_NUM == 14 || FUNCT_NUM == 13
#define ARRAY 0
#define SCALAR 1
#else
#define ARRAY 1
#define SCALAR 0
#endif
#endif

// Resolve EXTRA_PARM depending on FUNCT_NUM:
#if FUNCT_NUM == 15
// 0 - XF_CMP_EQ, 1 - XF_CMP_GT, 2 - XF_CMP_GE, 3 - XF_CMP_LT, 4 - XF_CMP_LE, 5 - XF_CMP_NE
#if EXTRA_PARM == 0
#define XF_EXTRA_PARM XF_CMP_EQ
#elif EXTRA_PARM == 1
#define XF_EXTRA_PARM XF_CMP_GT
#elif EXTRA_PARM == 2
#define XF_EXTRA_PARM XF_CMP_GE
#elif EXTRA_PARM == 3
#define XF_EXTRA_PARM XF_CMP_LT
#elif EXTRA_PARM == 4
#define XF_EXTRA_PARM XF_CMP_LE
#elif EXTRA_PARM == 5
#define XF_EXTRA_PARM XF_CMP_NE
#else
#define XF_EXTRA_PARM XF_CMP_EQ
#endif
#elif FUNCT_NUM == 0 || FUNCT_NAME == 1 || FUNCT_NUM == 3 || FUNCT_NUM == 4 || FUNCT_NUM == 2 || FUNCT_NUM == 5
// 0 - XF_CONVERT_POLICY_SATURATE, 1 - XF_CONVERT_POLICY_TRUNCATE
#if EXTRA_PARM == 0
#define XF_EXTRA_PARM XF_CONVERT_POLICY_SATURATE
#elif EXTRA_PARM == 1
#define XF_EXTRA_PARM XF_CONVERT_POLICY_TRUNCATE
#else
#define XF_EXTRA_PARM XF_CONVERT_POLICY_SATURATE
#endif
#else
#undef XF_EXTRA_PARM
#endif

// Resolve pixel precision:
#if NO
#define NPC1 XF_NPPC1
#endif
#if RO
#define NPC1 XF_NPPC8
#endif

// Resolve pixel type based on FUNCT_NAME:
#if T_16S == 1
#if FUNCT_NUM == 0 || FUNCT_NUM == 1 || FUNCT_NUM == 2 || FUNCT_NUM == 5
#define TYPE XF_16SC1
#if NO
#define PTR_WIDTH 16
#else
#define PTR_WIDTH 128
#endif
#else
#define TYPE XF_8UC1
#if NO
#define PTR_WIDTH 8
#else
#define PTR_WIDTH 64
#endif
#endif
#else
#define TYPE XF_8UC1
#if NO
#define PTR_WIDTH 8
#else
#define PTR_WIDTH 64
#endif
#endif

#endif // end of _XF_ARITHM_CONFIG_H_
