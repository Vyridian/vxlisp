#ifndef vx_type_test
#define vx_type_test
#include "../../main/vx/core.hpp"
#include "../../main/vx/test.hpp"

namespace vx_type_test {

  vx_test::Type_testcase f_is_string(vx_core::Type_context context);
  vx_test::Type_testcase f_is_type(vx_core::Type_context context);
  vx_test::Type_testcase f_is_type_from_any_typelist(vx_core::Type_context context);
  vx_test::Type_testcase f_length_from_string(vx_core::Type_context context);
  vx_test::Type_testcase f_string_from_int(vx_core::Type_context context);
  vx_test::Type_testcase f_string_from_string_end(vx_core::Type_context context);
  vx_test::Type_testcase f_string_from_string_start(vx_core::Type_context context);
  vx_test::Type_testcase f_string_from_string_start_end(vx_core::Type_context context);
  vx_test::Type_testcase f_string_from_stringlist_join(vx_core::Type_context context);

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context);
  vx_test::Type_testcoveragesummary test_coveragesummary();
  vx_test::Type_testcoveragedetail test_coveragedetail();
  vx_test::Type_testpackage test_package(vx_core::Type_context context);

}
#endif
