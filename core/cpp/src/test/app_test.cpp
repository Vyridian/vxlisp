#include <iostream>
#include "../main/vx/core.hpp"
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
namespace app_test {

  vx_core::Type_context context = vx_core::vx_new(vx_core::t_context(), {});


  // (package "vx/collection")
  vx_test::Type_testpackage test_vx_collection() {
	  vx_test::Type_testpackage testpackage = vx_collection_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/core")
  vx_test::Type_testpackage test_vx_core() {
	  vx_test::Type_testpackage testpackage = vx_core_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/data/csv")
  vx_test::Type_testpackage test_vx_data_csv() {
	  vx_test::Type_testpackage testpackage = vx_data_csv_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/data/db")
  vx_test::Type_testpackage test_vx_data_db() {
	  vx_test::Type_testpackage testpackage = vx_data_db_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/data/file")
  vx_test::Type_testpackage test_vx_data_file() {
	  vx_test::Type_testpackage testpackage = vx_data_file_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/data/table")
  vx_test::Type_testpackage test_vx_data_table() {
	  vx_test::Type_testpackage testpackage = vx_data_table_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/data/textblock")
  vx_test::Type_testpackage test_vx_data_textblock() {
	  vx_test::Type_testpackage testpackage = vx_data_textblock_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/data/tree")
  vx_test::Type_testpackage test_vx_data_tree() {
	  vx_test::Type_testpackage testpackage = vx_data_tree_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/data/xml")
  vx_test::Type_testpackage test_vx_data_xml() {
	  vx_test::Type_testpackage testpackage = vx_data_xml_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/repl")
  vx_test::Type_testpackage test_vx_repl() {
	  vx_test::Type_testpackage testpackage = vx_repl_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/sample")
  vx_test::Type_testpackage test_vx_sample() {
	  vx_test::Type_testpackage testpackage = vx_sample_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/state")
  vx_test::Type_testpackage test_vx_state() {
	  vx_test::Type_testpackage testpackage = vx_state_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/test")
  vx_test::Type_testpackage test_vx_test() {
	  vx_test::Type_testpackage testpackage = vx_test_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/type")
  vx_test::Type_testpackage test_vx_type() {
	  vx_test::Type_testpackage testpackage = vx_type_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/web/html")
  vx_test::Type_testpackage test_vx_web_html() {
	  vx_test::Type_testpackage testpackage = vx_web_html_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/web/http")
  vx_test::Type_testpackage test_vx_web_http() {
	  vx_test::Type_testpackage testpackage = vx_web_http_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


	// test_writetestsuite
  vx_core::Type_boolean test_writetestsuite() {
    vx_test::Type_testpackagelist testpackagelist = vx_core::vx_new(vx_test::t_testpackagelist(), {
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
    return test_lib::write_testpackagelist_async(testpackagelist, context);
  }

	int main(int iarglen, char* arrayarg[]) {
		std::vector<std::string> listarg = vx_core::vx_liststring_from_arraystring(iarglen, arrayarg);
    std::string current_exec_name = vx_core::vx_string_from_liststring_pos(listarg, 0); // Name of the current exec program
    vx_core::Type_boolean writetest = test_writetestsuite();
		vx_core::Type_string stringwritetest = vx_core::f_string_from_any(writetest);
		std::string swritetest = stringwritetest->vx_string();
		std::cout << swritetest;
    return 0;
  }

}
