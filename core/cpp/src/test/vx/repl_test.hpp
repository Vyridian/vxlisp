#ifndef VX_REPL_TEST_HPP
#define VX_REPL_TEST_HPP
#include "../../main/vx/core.hpp"
#include "../../main/vx/test.hpp"

namespace vx_repl_test {

  vx_test::Type_testcase f_any_from_macro(vx_core::Type_context context);
  vx_test::Type_testcase f_any_from_repl(vx_core::Type_context context);
  vx_test::Type_testcase f_any_from_script(vx_core::Type_context context);
  vx_test::Type_testcase f_const_from_string(vx_core::Type_context context);
  vx_test::Type_testcase f_repl_empty_from_textblock_argmap(vx_core::Type_context context);
  vx_test::Type_testcase f_repl_paren_from_textblock_argmap(vx_core::Type_context context);
  vx_test::Type_testcase f_repl_from_macro(vx_core::Type_context context);
  vx_test::Type_testcase f_repl_from_script(vx_core::Type_context context);
  vx_test::Type_testcase f_repl_from_string_argmap(vx_core::Type_context context);
  vx_test::Type_testcase f_repl_from_textblock(vx_core::Type_context context);
  vx_test::Type_testcase f_repl_from_textblock_argmap(vx_core::Type_context context);
  vx_test::Type_testcase f_textblock_from_script(vx_core::Type_context context);
  vx_test::Type_testcase f_typefunc_from_string(vx_core::Type_context context);

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context);
  vx_test::Type_testcoveragesummary test_coveragesummary();
  vx_test::Type_testcoveragedetail test_coveragedetail();
  vx_test::Type_testpackage test_package(vx_core::Type_context context);

}
#endif
