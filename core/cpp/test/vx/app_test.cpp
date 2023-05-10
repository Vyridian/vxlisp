#include <iostream>
#include "test_lib.cpp"
#include "../vx/collection_test.cpp"
#include "../vx/core_test.cpp"
#include "../vx/data/csv_test.cpp"
#include "../vx/data/db_test.cpp"
#include "../vx/data/file_test.cpp"
#include "../vx/data/table_test.cpp"
#include "../vx/data/textblock_test.cpp"
#include "../vx/data/tree_test.cpp"
#include "../vx/data/xml_test.cpp"
#include "../vx/repl_test.cpp"
#include "../vx/sample_test.cpp"
#include "../vx/state_test.cpp"
#include "../vx/test_test.cpp"
#include "../vx/type_test.cpp"
#include "../vx/web/html_test.cpp"
#include "../vx/web/http_test.cpp"

/**
 * Unit test for whole App.
 */
namespace app_test {

  vx_core::Type_context* context = vx_core::t_context->vx_new();


  // (package "vx/collection")
  bool test_vx_collection() {
	  vx_test::Type_testpackage* testpackage = vx_collection_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/core")
  bool test_vx_core() {
	  vx_test::Type_testpackage* testpackage = vx_core_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/data/csv")
  bool test_vx_data_csv() {
	  vx_test::Type_testpackage* testpackage = vx_data_csv_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/data/db")
  bool test_vx_data_db() {
	  vx_test::Type_testpackage* testpackage = vx_data_db_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/data/file")
  bool test_vx_data_file() {
	  vx_test::Type_testpackage* testpackage = vx_data_file_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/data/table")
  bool test_vx_data_table() {
	  vx_test::Type_testpackage* testpackage = vx_data_table_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/data/textblock")
  bool test_vx_data_textblock() {
	  vx_test::Type_testpackage* testpackage = vx_data_textblock_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/data/tree")
  bool test_vx_data_tree() {
	  vx_test::Type_testpackage* testpackage = vx_data_tree_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/data/xml")
  bool test_vx_data_xml() {
	  vx_test::Type_testpackage* testpackage = vx_data_xml_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/repl")
  bool test_vx_repl() {
	  vx_test::Type_testpackage* testpackage = vx_repl_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/sample")
  bool test_vx_sample() {
	  vx_test::Type_testpackage* testpackage = vx_sample_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/state")
  bool test_vx_state() {
	  vx_test::Type_testpackage* testpackage = vx_state_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/test")
  bool test_vx_test() {
	  vx_test::Type_testpackage* testpackage = vx_test_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/type")
  bool test_vx_type() {
	  vx_test::Type_testpackage* testpackage = vx_type_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/web/html")
  bool test_vx_web_html() {
	  vx_test::Type_testpackage* testpackage = vx_web_html_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


  // (package "vx/web/http")
  bool test_vx_web_http() {
	  vx_test::Type_testpackage* testpackage = vx_web_http_test::test_package(context);
	  return test_lib::run_testpackage_async(testpackage);
  }


	// test_writetestsuite
  vx_core::Type_boolean* test_writetestsuite() {
    vx_test::Type_testpackagelist* testpackagelist = vx_test::t_testpackagelist->vx_new(
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
    );
    return test_lib::write_testpackagelist_async(testpackagelist, context);
  }

	int main(int argc, char* argv[]) {
    std::string current_exec_name = argv[0]; // Name of the current exec program
    std::vector<std::string> all_args;
    if (argc > 1) {
      all_args.assign(argv + 1, argv + argc);
    }
    int output = 1;
    vx_core::Type_boolean* writetest = test_writetestsuite();
		vx_core::Type_string* stringwritetest = vx_core::f_string_from_any(writetest);
		std::string swritetest = stringwritetest->vx_string();
		std::cout << swritetest;
    return output;
  }

}
