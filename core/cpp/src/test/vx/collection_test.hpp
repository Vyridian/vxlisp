#ifndef VX_COLLECTION_TEST_HPP
#define VX_COLLECTION_TEST_HPP
#include "../../main/vx/core.hpp"
#include "../../main/vx/test.hpp"

namespace vx_collection_test {


  vx_test::Type_testcase f_any_from_for_until_loop(vx_core::Type_context context);
  vx_test::Type_testcase f_any_from_for_while_loop(vx_core::Type_context context);
  vx_test::Type_testcase f_int_from_map_key(vx_core::Type_context context);
  vx_test::Type_testcase f_int_from_stringlist_find(vx_core::Type_context context);
  vx_test::Type_testcase f_is_list(vx_core::Type_context context);
  vx_test::Type_testcase f_is_map(vx_core::Type_context context);
  vx_test::Type_testcase f_list_from_for_end_loop(vx_core::Type_context context);
  vx_test::Type_testcase f_list_from_list_end(vx_core::Type_context context);
  vx_test::Type_testcase f_list_from_list_filter(vx_core::Type_context context);
  vx_test::Type_testcase f_list_from_list_filtertypes(vx_core::Type_context context);
  vx_test::Type_testcase f_list_from_list_start(vx_core::Type_context context);
  vx_test::Type_testcase f_list_from_list_start_end(vx_core::Type_context context);
  vx_test::Type_testcase f_stringlist_from_map(vx_core::Type_context context);

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context);
  vx_test::Type_testcoveragesummary test_coveragesummary();
  vx_test::Type_testcoveragedetail test_coveragedetail();
  vx_test::Type_testpackage test_package(vx_core::Type_context context);

}

#endif
