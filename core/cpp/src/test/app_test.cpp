#include <iostream>
#include <stdexcept>
#include "../main/vx/core.hpp"
#include "../main/vx/test.hpp"
#include "test_lib.hpp"
#include "vx/collection_test.hpp"
#include "vx/core_test.hpp"
#include "vx/data/csv_test.hpp"
#include "vx/data/db_test.hpp"
#include "vx/data/file_test.hpp"
#include "vx/data/table_test.hpp"
#include "vx/data/textblock_test.hpp"
#include "vx/data/tree_test.hpp"
#include "vx/data/xml_test.hpp"
#include "vx/repl_test.hpp"
#include "vx/sample_test.hpp"
#include "vx/state_test.hpp"
#include "vx/test_test.hpp"
#include "vx/type_test.hpp"
#include "vx/web/html_test.hpp"
#include "vx/web/http_test.hpp"

/**
 * Unit test for whole App.
 */

vx_test::Type_testpackagelist testsuite(vx_core::Type_context context) {
  vx_test::Type_testpackagelist output = vx_core::vx_new(vx_test::t_testpackagelist(), {
    vx_collection_test::test_package(context),
    vx_core_test::test_package(context),
    vx_data_csv_test::test_package(context),
    vx_data_db_test::test_package(context),
    vx_data_file_test::test_package(context),
    vx_data_table_test::test_package(context),
    vx_data_textblock_test::test_package(context),
    vx_data_tree_test::test_package(context),
    vx_data_xml_test::test_package(context),
    vx_repl_test::test_package(context),
    vx_sample_test::test_package(context),
    vx_state_test::test_package(context),
    vx_test_test::test_package(context),
    vx_type_test::test_package(context),
    vx_web_html_test::test_package(context),
    vx_web_http_test::test_package(context)
  });
  return output;
}

int main(int iarglen, char* arrayarg[]) {
  int output = 0;
  try {
    vx_core::vx_debug("Test Start");
    std::vector<std::string> listarg = vx_core::vx_liststring_from_arraystring(iarglen, arrayarg);
    vx_core::Type_context context = vx_core::e_context();
    test_lib::test_helloworld();
    test_lib::test_async_new_from_value();
    test_lib::test_async_from_async_fn();
    test_lib::test_run_testresult(context);
    test_lib::test_run_testdescribe(context);
    test_lib::test_run_testdescribelist(context);
    test_lib::test_run_testcase(context);
    test_lib::test_run_testcaselist(context);
    test_lib::test_run_testpackage(context);
    test_lib::test_run_testpackagelist(context);
    test_lib::test_resolve_testresult_anyfromfunc(context);
    test_lib::test_resolve_testresult_then(context);
    test_lib::test_resolve_testresult_thenelselist(context);
    test_lib::test_resolve_testresult_if(context);
    test_lib::test_resolve_testresult_f_resolve_testresult_async(context);
    test_lib::test_resolve_testresult_f_resolve_testresult(context);
    test_lib::test_run_testresult_async(context);
    test_lib::test_run_testdescribe_async(context);
    test_lib::test_run_testdescribelist_async_f_list_from_list_async(context);
    test_lib::test_run_testdescribelist_async(context);
    test_lib::test_run_testcase_async_f_resolvetestcase(context);
    test_lib::test_run_testcase_async_syncvalue(context);
    test_lib::test_run_testcase_async(context);
    test_lib::test_run_testcaselist_async(context);
    test_lib::test_run_testpackage_async(context);
    test_lib::test_run_testpackagelist_async(context);
    test_lib::test_pathfull_from_file(context);
    test_lib::test_read_file(context);
    test_lib::test_write_file(context);
    test_lib::test_node_from_testpackagelist(context);
    test_lib::test_html_from_testpackagelist(context);
    test_lib::test_write_testpackagelist(context);
    test_lib::test_write_node(context);
    test_lib::test_write_html(context);
    test_lib::test_write_testpackagelist_async(context);
    vx_test::Type_testpackagelist testpackagelist = testsuite(context);
    vx_core::Type_boolean issuccess = test_lib::write_testpackagelist_async(testpackagelist, context);
    std::string expected = "true";
    std::string actual = vx_core::vx_string_from_any(issuccess);
    output = test_lib::test("Full Test Suite", expected, actual);
    vx_core::vx_release({issuccess, context});
    vx_core::vx_memory_leak_test();
    vx_core::vx_debug("Test End");
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    output = -1;
  } catch (...) {
    vx_core::vx_debug("Unexpected error");
    output = -1;
  }
  return output;
}
