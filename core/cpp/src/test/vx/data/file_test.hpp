#ifndef VX_DATA_FILE_TEST_HPP
#define VX_DATA_FILE_TEST_HPP
#include "../../../main/vx/core.hpp"
#include "../../../main/vx/test.hpp"

namespace vx_data_file_test {


  vx_test::Type_testcase f_boolean_exists_from_file(vx_core::Type_context context);
  vx_test::Type_testcase f_boolean_write_from_file_string(vx_core::Type_context context);
  vx_test::Type_testcase f_file_read_from_file(vx_core::Type_context context);
  vx_test::Type_testcase f_string_read_from_file(vx_core::Type_context context);

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context);
  vx_test::Type_testcoveragesummary test_coveragesummary();
  vx_test::Type_testcoveragedetail test_coveragedetail();
  vx_test::Type_testpackage test_package(vx_core::Type_context context);

}

#endif
