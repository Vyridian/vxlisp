#ifndef VX_DATA_TEXTBLOCK_TEST_HPP
#define VX_DATA_TEXTBLOCK_TEST_HPP
#include "../../../main/vx/core.hpp"
#include "../../../main/vx/test.hpp"

namespace vx_data_textblock_test {

  vx_test::Type_testcase f_delim_first_from_delim_delim(vx_core::Type_context context);
  vx_test::Type_testcase f_delim_first_from_string_delimlist(vx_core::Type_context context);
  vx_test::Type_testcase f_delim_startpos_from_string_delim(vx_core::Type_context context);
  vx_test::Type_testcase f_delimlist_startpos_from_string_delimlist(vx_core::Type_context context);
  vx_test::Type_testcase f_textblock_firstdelim_from_textblock_delimlist(vx_core::Type_context context);
  vx_test::Type_testcase f_textblock_startafter_from_string_delim(vx_core::Type_context context);
  vx_test::Type_testcase f_textblock_startbefore_from_string_delim(vx_core::Type_context context);

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context);
  vx_test::Type_testcoveragesummary test_coveragesummary();
  vx_test::Type_testcoveragedetail test_coveragedetail();
  vx_test::Type_testpackage test_package(vx_core::Type_context context);

}
#endif
