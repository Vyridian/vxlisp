#ifndef vx_collection_test
#define vx_collection_test
#include "../../main/vx/core.hpp"
#include "../../main/vx/test.hpp"

namespace vx_collection_test {

  vx_test::Type_testcase f_list_from_list_end(vx_core::Type_context context);
  vx_test::Type_testcase f_list_from_list_filtertypes(vx_core::Type_context context);
  vx_test::Type_testcase f_list_from_list_fn_filter(vx_core::Type_context context);
  vx_test::Type_testcase f_list_from_list_start(vx_core::Type_context context);
  vx_test::Type_testcase f_list_from_list_start_end(vx_core::Type_context context);

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context);
  vx_test::Type_testcoveragesummary test_coveragesummary();
  vx_test::Type_testcoveragedetail test_coveragedetail();
  vx_test::Type_testpackage test_package(vx_core::Type_context context);

}
#endif
