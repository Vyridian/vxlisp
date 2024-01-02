#ifndef VX_DATA_TEXTBLOCK_TEST_HPP
#define VX_DATA_TEXTBLOCK_TEST_HPP
#include "../../../main/vx/core.hpp"
#include "../../../main/vx/test.hpp"

namespace vx_data_textblock_test {


  vx_test::Type_testcase t_delimlist(vx_core::Type_context context);
  vx_test::Type_testcase f_delim_first_from_delim_delim(vx_core::Type_context context);
  vx_test::Type_testcase f_delim_first_from_string_delimlist(vx_core::Type_context context);
  vx_test::Type_testcase f_delim_pos_from_string_delim(vx_core::Type_context context);
  vx_test::Type_testcase f_delimlist_pos_from_string_delimlist(vx_core::Type_context context);
  vx_test::Type_testcase f_stringlist_from_textblocklist(vx_core::Type_context context);
  vx_test::Type_testcase f_text_from_textblock(vx_core::Type_context context);
  vx_test::Type_testcase f_textblock_delimnotfound(vx_core::Type_context context);
  vx_test::Type_testcase f_textblock_init(vx_core::Type_context context);
  vx_test::Type_testcase f_textblock_parse(vx_core::Type_context context);
  vx_test::Type_testcase f_textblock_parse_one(vx_core::Type_context context);
  vx_test::Type_testcase f_textblock_startleft_from_string_delim_offset(vx_core::Type_context context);
  vx_test::Type_testcase f_textblock_startright_from_string_delim_offset(vx_core::Type_context context);
  vx_test::Type_testcase f_textblock_from_close_textblock(vx_core::Type_context context);
  vx_test::Type_testcase f_textblock_from_open_textblock(vx_core::Type_context context);
  vx_test::Type_testcase f_textblock_from_single_textblock(vx_core::Type_context context);
  vx_test::Type_testcase f_textblock_from_string_delim(vx_core::Type_context context);
  vx_test::Type_testcase f_textblocklist_from_textblocklist_remove(vx_core::Type_context context);

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context);
  vx_test::Type_testcoveragesummary test_coveragesummary();
  vx_test::Type_testcoveragedetail test_coveragedetail();
  vx_test::Type_testpackage test_package(vx_core::Type_context context);

}

#endif
