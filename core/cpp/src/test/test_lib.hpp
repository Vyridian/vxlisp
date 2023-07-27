#ifndef TEST_LIB_HPP
#define TEST_LIB_HPP
#include "../main/vx/core.hpp"
#include "../main/vx/test.hpp"
#include "../main/vx/data/file.hpp"
	
namespace test_lib {
	
  vx_test::Type_testresult run_testresult(std::string testpkg, std::string testname, std::string message, vx_test::Type_testresult testresult);
	// Blocking
  vx_test::Type_testresult run_testresult_async(std::string testpkg, std::string testname, std::string message, vx_test::Type_testresult testresult);
  vx_test::Type_testdescribe run_testdescribe(std::string testpkg, std::string casename, vx_test::Type_testdescribe describe);
  // Only use if running a single testdescribe
  vx_test::Type_testdescribe run_testdescribe_async(std::string testpkg, std::string casename, vx_test::Type_testdescribe testdescribe);
  vx_test::Type_testdescribelist run_testdescribelist(std::string testpkg, std::string casename, vx_test::Type_testdescribelist testdescribelist);
  vx_test::Type_testcase run_testcase(vx_test::Type_testcase testcase);
  // Blocking
  // Only use if running a single testcase
  vx_test::Type_testcase run_testcase_async(vx_test::Type_testcase testcase);
  vx_test::Type_testcaselist run_testcaselist(vx_test::Type_testcaselist testcaselist);
  vx_test::Type_testpackage run_testpackage(vx_test::Type_testpackage testpackage);
  vx_test::Type_testpackagelist run_testpackagelist(vx_test::Type_testpackagelist testpackagelist);
  // Blocking
  // This is the preferred way of calling test (1 block per package)
  vx_test::Type_testpackage run_testpackage_async(vx_test::Type_testpackage testpackage);
  // Blocking
  // This is the preferred way of calling testsuite (1 block per testsuite)
  vx_test::Type_testpackagelist run_testpackagelist_async(vx_test::Type_testpackagelist testpackagelist);
  // Blocking
  // This is the preferred way of writing testsuite (1 block per testsuite)
  vx_core::Type_boolean write_testpackagelist_async(vx_test::Type_testpackagelist testpackagelist, vx_core::Type_context context);

}
#endif
