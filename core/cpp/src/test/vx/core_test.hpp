#include "../../main/vx/core.hpp"
#include "../../main/vx/test.hpp"

namespace vx_core_test {

  vx_test::Type_testcase t_boolean(vx_core::Type_context context);
  vx_test::Type_testcase t_float(vx_core::Type_context context);
  vx_test::Type_testcase t_int(vx_core::Type_context context);
  vx_test::Type_testcase t_string(vx_core::Type_context context);
  vx_test::Type_testcase c_false(vx_core::Type_context context);
  vx_test::Type_testcase c_true(vx_core::Type_context context);
  vx_test::Type_testcase f_not(vx_core::Type_context context);
  vx_test::Type_testcase f_ne(vx_core::Type_context context);
  vx_test::Type_testcase f_multiply(vx_core::Type_context context);
  vx_test::Type_testcase f_multiply(vx_core::Type_context context);
  vx_test::Type_testcase f_multiply(vx_core::Type_context context);
  vx_test::Type_testcase f_multiply(vx_core::Type_context context);
  vx_test::Type_testcase f_plus(vx_core::Type_context context);
  vx_test::Type_testcase f_plus(vx_core::Type_context context);
  vx_test::Type_testcase f_plus1(vx_core::Type_context context);
  vx_test::Type_testcase f_minus(vx_core::Type_context context);
  vx_test::Type_testcase f_minus(vx_core::Type_context context);
  vx_test::Type_testcase f_divide(vx_core::Type_context context);
  vx_test::Type_testcase f_lt(vx_core::Type_context context);
  vx_test::Type_testcase f_lt(vx_core::Type_context context);
  vx_test::Type_testcase f_chainfirst(vx_core::Type_context context);
  vx_test::Type_testcase f_chainlast(vx_core::Type_context context);
  vx_test::Type_testcase f_le(vx_core::Type_context context);
  vx_test::Type_testcase f_le(vx_core::Type_context context);
  vx_test::Type_testcase f_eq(vx_core::Type_context context);
  vx_test::Type_testcase f_eq(vx_core::Type_context context);
  vx_test::Type_testcase f_gt(vx_core::Type_context context);
  vx_test::Type_testcase f_gt(vx_core::Type_context context);
  vx_test::Type_testcase f_ge(vx_core::Type_context context);
  vx_test::Type_testcase f_ge(vx_core::Type_context context);
  vx_test::Type_testcase f_and(vx_core::Type_context context);
  vx_test::Type_testcase f_and(vx_core::Type_context context);
  vx_test::Type_testcase f_any_from_list(vx_core::Type_context context);
  vx_test::Type_testcase f_any_from_list_reduce(vx_core::Type_context context);
  vx_test::Type_testcase f_any_from_map(vx_core::Type_context context);
  vx_test::Type_testcase f_compare(vx_core::Type_context context);
  vx_test::Type_testcase f_contains(vx_core::Type_context context);
  vx_test::Type_testcase f_contains(vx_core::Type_context context);
  vx_test::Type_testcase f_empty(vx_core::Type_context context);
  vx_test::Type_testcase f_first_from_list(vx_core::Type_context context);
  vx_test::Type_testcase f_first_from_list_fn_any_from_any(vx_core::Type_context context);
  vx_test::Type_testcase f_if(vx_core::Type_context context);
  vx_test::Type_testcase f_if(vx_core::Type_context context);
  vx_test::Type_testcase f_if(vx_core::Type_context context);
  vx_test::Type_testcase f_int_from_string(vx_core::Type_context context);
  vx_test::Type_testcase f_is_empty(vx_core::Type_context context);
  vx_test::Type_testcase f_is_number(vx_core::Type_context context);
  vx_test::Type_testcase f_last_from_list(vx_core::Type_context context);
  vx_test::Type_testcase f_length_from_list(vx_core::Type_context context);
  vx_test::Type_testcase f_let(vx_core::Type_context context);
  vx_test::Type_testcase f_list_from_map(vx_core::Type_context context);
  vx_test::Type_testcase f_map_from_list(vx_core::Type_context context);
  vx_test::Type_testcase f_new(vx_core::Type_context context);
  vx_test::Type_testcase f_or(vx_core::Type_context context);
  vx_test::Type_testcase f_or(vx_core::Type_context context);
  vx_test::Type_testcase f_resolve(vx_core::Type_context context);
  vx_test::Type_testcase f_resolve(vx_core::Type_context context);
  vx_test::Type_testcase f_resolve_async(vx_core::Type_context context);
  vx_test::Type_testcase f_string_repeat(vx_core::Type_context context);
  vx_test::Type_testcase f_string_from_any(vx_core::Type_context context);
  vx_test::Type_testcase f_switch(vx_core::Type_context context);
  vx_test::Type_testcase f_type_from_any(vx_core::Type_context context);
  vx_test::Type_testcase f_typename_from_any(vx_core::Type_context context);

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context);
  vx_test::Type_testcoveragesummary test_coveragesummary();
  vx_test::Type_testcoveragedetail test_coveragedetail();
  vx_test::Type_testpackage test_package(vx_core::Type_context context);

}
