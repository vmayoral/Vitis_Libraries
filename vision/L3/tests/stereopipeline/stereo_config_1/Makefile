#
# Copyright 2019 Xilinx, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# -----------------------------------------------------------------------------
#                          project common settings

MK_PATH       := $(abspath $(lastword $(MAKEFILE_LIST)))
CUR_DIR       := $(patsubst %/,%,$(dir $(MK_PATH)))
CASE_ROOT     ?= $(CUR_DIR)
#PLATFORM_REPO_PATHS=/proj/xbuilds/2019.1_Scout_daily_latest/internal_platforms/xilinx_u200_xdma_201830_2
#DEVICE = /proj/xbuilds/2019.1_Scout_daily_latest/internal_platforms/xilinx_u200_xdma_201830_2/xilinx_u200_xdma_201830_2.xpfm
#MK_COMMON_DIR := mk

# Below should point to library repo
XF_LIB_DIR    ?= $(abspath $(CASE_ROOT)/../../../../L3)
MK_COMMON_DIR := $(XF_LIB_DIR)/../ext/makefile_templates

.SECONDEXPANSION:

# -----------------------------------------------------------------------------
#                            sdx common setup

include $(MK_COMMON_DIR)/sdx_help.mk

include $(MK_COMMON_DIR)/vivado.mk

include $(MK_COMMON_DIR)/scout.mk

include $(MK_COMMON_DIR)/set_platform.mk

# Initial definition
KERNELS     :=

# -----------------------------------------------------------------------------
# BEGIN_XF_MK_USER_SECTION
# -----------------------------------------------------------------------------
# TODO:          data creation and other user targets

# a (typically hidden) file as stamp
DATA_STAMP := $(CUR_DIR)/.stamp
$(DATA_STAMP):
	touch $@

.PHONY: data
data: $(DATA_STAMP)

# -----------------------------------------------------------------------------
#                          kernel setup

KSRC_DIR 		:= $(XF_LIB_DIR)/examples/stereolbm
XFREQUENCY 		:= 300

XCLBIN_NAME 	:= krnl_stereolbm
KER_NAME    	:= stereopipeline_accel:xf_stereo_pipeline_accel.cpp

VPP_CFLAGS  	+= -I$(XF_LIB_DIR)/include -I. -I$(XF_LIB_DIR)/../L1/include
VPP_CFLAGS  	+= -D__SDSVHLS__ -DHLS_NO_XIL_FPO_LIB
ifeq ($(BOARD), Zynq)
VPP_CFLAGS		+= --sys_config sysconfig1
endif
$(KER_NAME)_VPP_CFLAGS := --xp vivado_prop:run.impl_1.strategy=Performance_Explore

KERNELS     	+= $(KER_NAME)

# -----------------------------------------------------------------------------
#                           host setup

SRC_DIR 		:= $(XF_LIB_DIR)/examples/stereopipeline

EXE_NAME  		:= stereopipeline
HOST_ARGS 		= $(SRC_DIR)/data/128x128.png #$(XCLBIN_FILE)
SRCS      		:= xf_stereo_pipeline_tb

# Macro definitions
CXXFLAGS 		+= -D XDEVICE=$(XDEVICE) -DVIVADO_HLS_SIM -D__SDSVHLS__ -DHLS_NO_XIL_FPO_LIB
# Search paths:
CXXFLAGS 		+= -I$(XF_LIB_DIR)/include -I. -I$(XF_LIB_DIR)/../L1/include -I$(XF_LIB_DIR)/../ext/xcl2 -I$(XF_LIB_DIR)/../Vivado_include
# Options
CXXFLAGS 		+= -g


ifeq ($(BOARD), Zynq)
    CXXFLAGS 	+= --sysroot=${SYSROOT} -D__ZYNQ
endif

# EXTRA_OBJS is cannot be compiled from SRC_DIR, user should provide the rule
EXTRA_OBJS 		+= xcl2

EXT_DIR   		= $(XF_LIB_DIR)/../ext
xcl2_SRCS 		= $(EXT_DIR)/xcl2/xcl2.cpp
xcl2_HDRS 		= $(EXT_DIR)/xcl2/xcl2.hpp
xcl2_CXXFLAGS 	= -I $(EXT_DIR)/xcl2


# OpenCV related:
ifeq ($(BOARD), Zynq)
    opencv_LDFLAGS	:= -L${SYSROOT}/usr/lib -Wl,-rpath-link=${SYSROOT}/usr/lib/ -L${SYSROOT}/opt/xilinx/xrt/lib -lopencv_imgcodecs
else
    opencv_LDFLAGS	:= -L$(XILINX_SCOUT)/lnx64/tools/opencv#/opencv_gcc/lib
endif
    opencv_LDFLAGS	+= -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_calib3d -lopencv_features2d -lopencv_flann


LDFLAGS 			:= $(opencv_LDFLAGS)

# -----------------------------------------------------------------------------
# END_XF_MK_USER_SECTION
# -----------------------------------------------------------------------------

.PHONY: all
all: host xclbin

include $(MK_COMMON_DIR)/sdx_kernel_rules.mk

export XCL_BINDIR= $(XCLBIN_DIR)

include $(MK_COMMON_DIR)/sdx_host_rules.mk

include $(MK_COMMON_DIR)/sdx_test_rules.mk

