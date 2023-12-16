#ifndef TEST_LIB_HPP
#define TEST_LIB_HPP
#include "../main/vx/core.hpp"
#include "../main/vx/test.hpp"
#include "../main/vx/data/file.hpp"

namespace test_lib {

  vx_test::Type_testcase run_testcase(vx_test::Type_testcase testcase);

  // Blocking
  // Only use if running a single testcase
  vx_test::Type_testcase run_testcase_async(vx_test::Type_testcase testcase);

  vx_test::Type_testcaselist run_testcaselist(vx_test::Type_testcaselist testcaselist);

  // Blocking
  // Only use if running a single testcaselist
  vx_test::Type_testcaselist run_testcaselist_async(vx_test::Type_testcaselist testcaselist);

  vx_test::Type_testdescribe run_testdescribe(std::string testpkg, std::string casename, vx_test::Type_testdescribe describe);

  // Only use if running a single testdescribe
  vx_test::Type_testdescribe run_testdescribe_async(std::string testpkg, std::string casename, vx_test::Type_testdescribe testdescribe);

  vx_test::Type_testdescribelist run_testdescribelist(std::string testpkg, std::string casename, vx_test::Type_testdescribelist testdescribelist);

  // Blocking
  // Only use if running a single testdescribelist
  vx_test::Type_testdescribelist run_testdescribelist_async(std::string testpkg, std::string casename, vx_test::Type_testdescribelist testdescribelist);

  vx_test::Type_testpackage run_testpackage(vx_test::Type_testpackage testpackage);

  // Blocking
  // This is the preferred way of calling test (1 block per package)
  vx_test::Type_testpackage run_testpackage_async(vx_test::Type_testpackage testpackage);

  vx_test::Type_testpackagelist run_testpackagelist(vx_test::Type_testpackagelist testpackagelist);

  // Blocking
  // This is the preferred way of calling testsuite (1 block per testsuite)
  vx_test::Type_testpackagelist run_testpackagelist_async(vx_test::Type_testpackagelist testpackagelist);

  vx_test::Type_testresult run_testresult(std::string testpkg, std::string testname, std::string message, vx_test::Type_testresult testresult);

	// Blocking
  vx_test::Type_testresult run_testresult_async(std::string testpkg, std::string testname, std::string message, vx_test::Type_testresult testresult);

  // Blocking
  // This is the preferred way of writing testsuite (1 block per testsuite)
  vx_core::Type_boolean write_testpackagelist_async(vx_core::Type_context context, vx_test::Type_testpackagelist testpackagelist);

  bool test(std::string testname, std::string expected, std::string actual);

  bool test_helloworld();

  bool test_async_new_from_value();

  bool test_async_from_async_fn();

  bool test_div_from_testcaselist(vx_core::Type_context context);

  bool test_div_from_testpackage(vx_core::Type_context context);

  bool test_div_from_testpackagelist(vx_core::Type_context context);

  bool test_html_from_testpackagelist(vx_core::Type_context context);

  bool test_node_from_testpackagelist(vx_core::Type_context context);

  bool test_pathfull_from_file(vx_core::Type_context context);

  bool test_read_file(vx_core::Type_context context);

  bool test_resolve_testresult_anyfromfunc(vx_core::Type_context context);

  bool test_resolve_testresult_f_resolve_testresult(vx_core::Type_context context);

  bool test_resolve_testresult_f_resolve_testresult_async(vx_core::Type_context context);

  bool test_resolve_testresult_if(vx_core::Type_context context);

  bool test_resolve_testresult_then(vx_core::Type_context context);

  bool test_resolve_testresult_thenelselist(vx_core::Type_context context);

  bool test_run_all(vx_core::Type_context context, vx_test::Type_testpackagelist testpackagelist);

  bool test_run_testcase(vx_core::Type_context context);

  bool test_run_testcase_async(vx_core::Type_context context);

  bool test_run_testcase_async_f_resolvetestcase(vx_core::Type_context context);

  bool test_run_testcase_async_syncvalue(vx_core::Type_context context);

  bool test_run_testcaselist(vx_core::Type_context context);

  bool test_run_testcaselist_async(vx_core::Type_context context);

  bool test_run_testdescribe(vx_core::Type_context context);

  bool test_run_testdescribe_async(vx_core::Type_context context);

  bool test_run_testdescribelist(vx_core::Type_context context);

  bool test_run_testdescribelist_async(vx_core::Type_context context);

  bool test_run_testdescribelist_async_f_list_from_list_async(vx_core::Type_context context);

  bool test_run_testpackage(vx_core::Type_context context);

  bool test_run_testpackage_async(vx_core::Type_context context);

  bool test_run_testpackagelist(vx_core::Type_context context);

  bool test_run_testpackagelist_async(vx_core::Type_context context);

  bool test_run_testresult(vx_core::Type_context context);

  bool test_run_testresult_async(vx_core::Type_context context);

  bool test_tr_from_testdescribe_casename(vx_core::Type_context context);

  bool test_trlist_from_testcase(vx_core::Type_context context);

  bool test_trlist_from_testcaselist(vx_core::Type_context context);

  bool test_write_file(vx_core::Type_context context);

  bool test_write_node(vx_core::Type_context context);

  bool test_write_html(vx_core::Type_context context);

  bool test_write_testpackagelist(vx_core::Type_context context);

  bool test_write_testpackagelist_async(vx_core::Type_context context);

}
#endif
