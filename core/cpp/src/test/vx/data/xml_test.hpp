#ifndef VX_DATA_XML_TEST_HPP
#define VX_DATA_XML_TEST_HPP
#include "../../../main/vx/core.hpp"
#include "../../../main/vx/test.hpp"

namespace vx_data_xml_test {

  vx_test::Type_testcase f_textblock_xml_from_string(vx_core::Type_context context);
  vx_test::Type_testcase f_xml_angle_from_xml_textblock(vx_core::Type_context context);
  vx_test::Type_testcase f_xml_close_from_xml_textblock(vx_core::Type_context context);
  vx_test::Type_testcase f_xml_parse_from_xml_textblock(vx_core::Type_context context);
  vx_test::Type_testcase f_xml_parse_from_xml_textblocklist(vx_core::Type_context context);
  vx_test::Type_testcase f_xml_properties_from_xml_textblocklist(vx_core::Type_context context);
  vx_test::Type_testcase f_xml_property_from_xml_textblock(vx_core::Type_context context);
  vx_test::Type_testcase f_xml_text_from_xml_textblock(vx_core::Type_context context);
  vx_test::Type_testcase f_xml_from_textblock(vx_core::Type_context context);

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context);
  vx_test::Type_testcoveragesummary test_coveragesummary();
  vx_test::Type_testcoveragedetail test_coveragedetail();
  vx_test::Type_testpackage test_package(vx_core::Type_context context);

}
#endif
