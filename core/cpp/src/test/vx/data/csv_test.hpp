#ifndef VX_DATA_CSV_TEST_HPP
#define VX_DATA_CSV_TEST_HPP
#include "../../../main/vx/core.hpp"
#include "../../../main/vx/test.hpp"

namespace vx_data_csv_test {

  vx_test::Type_testcase f_textblock_csv_from_string(vx_core::Type_context context);

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context);
  vx_test::Type_testcoveragesummary test_coveragesummary();
  vx_test::Type_testcoveragedetail test_coveragedetail();
  vx_test::Type_testpackage test_package(vx_core::Type_context context);

}
#endif
