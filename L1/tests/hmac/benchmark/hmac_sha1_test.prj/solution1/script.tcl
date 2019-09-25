############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project hmac_sha1_test.prj
set_top aes256CbcEncryptKernel_1
add_files test.cpp -cflags "-I/wrk/xsjhdnobkup4/tuol/xf_security//L1/include"
add_files -tb main.cpp -cflags "-I/wrk/xsjhdnobkup4/tuol/xf_security//L1/include -Wno-unknown-pragmas"
open_solution "solution1"
set_part {xcu250-figd2104-2L-e}
create_clock -period 3.33 -name default
set_clock_uncertainty 1.05
#source "./hmac_sha1_test.prj/solution1/directives.tcl"
csim_design -ldflags {-lcrypto -lssl}
csynth_design
cosim_design -ldflags {-lcrypto -lssl}
export_design -format ip_catalog
