/*
 * Copyright 2020 Xilinx, Inc.
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

#ifndef _GQE_JOIN_CONFIG_L3_
#define _GQE_JOIN_CONFIG_L3_
// commmon
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iomanip>
// HLS
#include <ap_int.h>
// L2
#include "xf_database/gqe_utils.hpp"
// L3
#include "xf_database/gqe_table.hpp"
#include "xf_database/gqe_base_config.hpp"

namespace xf {
namespace database {
namespace gqe {

class JoinConfig : protected BaseConfig {
   private:
    // sw-shuffle for scan, determins the column order while scanning data in
    std::vector<std::vector<int8_t> > sw_shuffle_scan_hj;
    // sw-shuffle for write out, determins the column order while writing data out
    std::vector<int8_t> sw_shuffle_wr_hj;

    // the kernel config passed to gqeJoin kernel
    ap_uint<512>* table_join_cfg;

    // setup kernel config (table_join_cfg) for gqeJoin
    void SetupKernelConfig(int join_type,
                           std::string filter_a,
                           std::string filter_b,
                           bool gen_rowID_en[2],
                           bool valid_en[2],
                           std::vector<std::vector<std::string> > join_keys,
                           std::vector<std::vector<int8_t> > sw_shuffle_scan_hj,
                           std::vector<int8_t> sw_shuffle_wr_hj);

   public:
    /**
    * @brief constructor of JoinConfig.
    *
    * The class generates join configure bits by parsing the join .run() arguments,
    *
    * @param a left table
    * @param filter_a filter condition of left table
    * @param b right table
    * @param filter_b filter condition of right table
    * @param join_str join condition(s)
    * @param evals eval expressions list
    * @param evals_const eval expression constant list
    * @param c result table
    * @param output_str output column mapping
    * @param join_type INNER_JOIN(default) | SEMI_JOIN | ANTI_JOIN.
    * @param part_tag if use partition kernel
    *
    */
    JoinConfig(Table a,
               std::string filter_a,
               Table b,
               std::string filter_b,
               std::string join_str, // comma separated
               Table c,
               std::string output_str, // comma separated
               int join_Type = INNER_JOIN);

    /**
     * @brief get the gqeJoin kernel config
     *
     * @return join config bits
     */
    ap_uint<512>* getJoinConfigBits() const;

    /**
     * @brief get the sw-shuffle config for scan.
     *
     * @return return the scan sw_shuffle cfg
    */
    std::vector<std::vector<int8_t> > getShuffleScan() const;

    /**
     * @brief get the sw-shuffle config for write out.
     *
     * @return return the write out sw_shuffle cfg
    */
    std::vector<int8_t> getShuffleWrite() const;
};
}
}
}
#endif
