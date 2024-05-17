#ifndef VX_UI_UI_TEST_HPP
#define VX_UI_UI_TEST_HPP
#include "../../../main/vx/core.hpp"
#include "../../../main/vx/test.hpp"

namespace vx_ui_ui_test {


  vx_test::Type_testcase f_boolean_writestate_from_uiapp(vx_core::Type_context context);
  vx_test::Type_testcase f_string_parentuid_from_uid(vx_core::Type_context context);
  vx_test::Type_testcase f_ui_readstate_uiapp(vx_core::Type_context context);
  vx_test::Type_testcase f_ui_readstate_from_uid(vx_core::Type_context context);
  vx_test::Type_testcase f_ui_from_ui_find(vx_core::Type_context context);
  vx_test::Type_testcase f_ui_from_ui_selected(vx_core::Type_context context);
  vx_test::Type_testcase f_ui_from_ui_visible(vx_core::Type_context context);

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context);
  vx_test::Type_testcoveragesummary test_coveragesummary();
  vx_test::Type_testcoveragedetail test_coveragedetail();
  vx_test::Type_testpackage test_package(vx_core::Type_context context);

}

#endif
