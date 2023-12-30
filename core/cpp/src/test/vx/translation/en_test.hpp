#ifndef VX_TRANSLATION_EN_TEST_HPP
#define VX_TRANSLATION_EN_TEST_HPP
#include "../../../main/vx/core.hpp"
#include "../../../main/vx/test.hpp"

namespace vx_translation_en_test {

  vx_test::Type_testcase f_translation_en(vx_core::Type_context context);

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context);
  vx_test::Type_testcoveragesummary test_coveragesummary();
  vx_test::Type_testcoveragedetail test_coveragedetail();
  vx_test::Type_testpackage test_package(vx_core::Type_context context);

}
#endif
