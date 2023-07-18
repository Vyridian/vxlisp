#include "../main/vx/core.hpp"
#include "../main/vx/test.hpp"
#include "../main/vx/data/file.hpp"

namespace test_lib {

  vx_test::Type_testresult run_testresult(std::string testpkg, std::string testname, std::string message, vx_test::Type_testresult testresult) {
    vx_core::Type_any valexpected = testresult->expected();
    vx_core::Type_any valactual = testresult->actual();
    bool passfail = testresult->passfail()->vx_boolean();
    std::string code = testresult->code()->vx_string();
    std::string expected = vx_core::f_string_from_any(valexpected)->vx_string();
    std::string actual = vx_core::f_string_from_any(valactual)->vx_string();
    std::string msg = testpkg + "/" + testname + " " + message;
    if (!passfail) {
//      System.out.println(msg);
//      System.out.println(expected);
//      System.out.println(actual);
      vx_core::f_log(testresult);
    }
//    if (code == ":ne") {
//      assertNotEquals(expected, actual, msg);
//    } else {
//      assertEquals(expected, actual, msg);
//    }
    return testresult;
  }

  // Blocking
  vx_test::Type_testresult run_testresult_async(std::string testpkg, std::string testname, std::string message, vx_test::Type_testresult testresult) {
    vx_core::vx_Type_async async_testresult = vx_test::f_resolve_testresult(testresult);
    vx_test::Type_testresult testresult_resolved = vx_core::vx_sync_from_async(vx_test::t_testresult(), async_testresult);
    return test_lib::run_testresult(testpkg, testname, message, testresult_resolved);
  }

  vx_test::Type_testdescribe run_testdescribe(std::string testpkg, std::string casename, vx_test::Type_testdescribe describe) {
    vx_core::Type_string testcode = describe->describename();
    std::string message = testcode->vx_string();
    vx_test::Type_testresult testresult = describe->testresult();
    vx_test::Type_testresult testresultresolved = test_lib::run_testresult(testpkg, casename, message, testresult);
    vx_test::Type_testdescribe output = vx_core::vx_copy(describe, {vx_core::vx_new_string(":testresult"), testresultresolved});
		return output;
  }

  // Blocking
  // Only use if running a single testdescribe
  vx_test::Type_testdescribe run_testdescribe_async(std::string testpkg, std::string casename, vx_test::Type_testdescribe testdescribe) {
    vx_core::vx_Type_async async_testdescribe = vx_test::f_resolve_testdescribe(testdescribe);
    vx_test::Type_testdescribe testdescribe_resolved = vx_core::vx_sync_from_async(vx_test::t_testdescribe(), async_testdescribe);
    return run_testdescribe(testpkg, casename, testdescribe_resolved);
  }

  vx_test::Type_testdescribelist run_testdescribelist(std::string testpkg, std::string casename, vx_test::Type_testdescribelist testdescribelist) {
    std::vector<vx_test::Type_testdescribe> listtestdescribe = testdescribelist->vx_listtestdescribe();
    vx_core::vx_Type_listany listtestdescribe_resolved;
    for (vx_test::Type_testdescribe testdescribe : listtestdescribe) {
      vx_test::Type_testdescribe testdescribe_resolved = run_testdescribe(testpkg, casename, testdescribe);
			listtestdescribe_resolved.push_back(testdescribe_resolved);
    }
		vx_test::Type_testdescribelist output = vx_core::vx_any_from_any(
			vx_test::t_testdescribelist(),
			testdescribelist->vx_new_from_list(listtestdescribe_resolved)
		);
    return output;
  }

	vx_test::Type_testcase run_testcase(vx_test::Type_testcase testcase) {
    std::string testpkg = testcase->testpkg()->vx_string();
    std::string casename = testcase->casename()->vx_string();
    vx_test::Type_testdescribelist testdescribelist = testcase->describelist();
    vx_test::Type_testdescribelist testdescribelist_resolved = run_testdescribelist(testpkg, casename, testdescribelist);
		vx_test::Type_testcase output = vx_core::vx_copy(testcase, {vx_core::vx_new_string(":describelist"), testdescribelist_resolved});
		return output;
  }

  // Blocking
  // Only use if running a single testcase
  vx_test::Type_testcase run_testcase_async(vx_test::Type_testcase testcase) {
    vx_core::vx_Type_async async_testcase = vx_test::f_resolve_testcase(testcase);
    vx_test::Type_testcase testcase_resolved = vx_core::vx_sync_from_async(vx_test::t_testcase(), async_testcase);
    return run_testcase(testcase_resolved);
  }

	vx_test::Type_testcaselist run_testcaselist(vx_test::Type_testcaselist testcaselist) {
    std::vector<vx_test::Type_testcase> listtestcase = testcaselist->vx_listtestcase();
    vx_core::vx_Type_listany listtestcase_resolved;
    for (vx_test::Type_testcase testcase : listtestcase) {
      vx_test::Type_testcase testcase_resolved = run_testcase(testcase);
			listtestcase_resolved.push_back(testcase_resolved);
    }
		vx_test::Type_testcaselist output = vx_core::vx_any_from_any(
			vx_test::t_testcaselist(),
			testcaselist->vx_new_from_list(listtestcase_resolved)
		);
    return output;
  }

  vx_test::Type_testpackage run_testpackage(vx_test::Type_testpackage testpackage) {
    vx_test::Type_testcaselist testcaselist = testpackage->caselist();
    vx_test::Type_testcaselist testcaselist_resolved = run_testcaselist(testcaselist);
		vx_test::Type_testpackage output = vx_core::vx_copy(testpackage, {vx_core::vx_new_string(":caselist"), testcaselist_resolved});
		return output;
  }

  vx_test::Type_testpackagelist run_testpackagelist(vx_test::Type_testpackagelist testpackagelist) {
    std::vector<vx_test::Type_testpackage> listtestpackage = testpackagelist->vx_listtestpackage();
    vx_core::vx_Type_listany listtestpackage_resolved;
    for (vx_test::Type_testpackage testpackage : listtestpackage) {
      vx_test::Type_testpackage testpackage_resolved = run_testpackage(testpackage);
			listtestpackage_resolved.push_back(testpackage_resolved);
    }
		vx_test::Type_testpackagelist output = vx_core::vx_any_from_any(
			vx_test::t_testpackagelist(),
			testpackagelist->vx_new_from_list(listtestpackage_resolved)
		);
    return output;
  }

  // Blocking
  // This is the preferred way of calling test (1 block per package)
  vx_test::Type_testpackage run_testpackage_async(vx_test::Type_testpackage testpackage) {
    vx_core::vx_Type_async async_testpackage = vx_test::f_resolve_testpackage(testpackage);
    vx_test::Type_testpackage testpackage_resolved = vx_core::vx_sync_from_async(vx_test::t_testpackage(), async_testpackage);
    return run_testpackage(testpackage_resolved);
  }

  // Blocking
  // This is the preferred way of calling testsuite (1 block per testsuite)
  vx_test::Type_testpackagelist run_testpackagelist_async(vx_test::Type_testpackagelist testpackagelist) {
    vx_core::vx_Type_async async_testpackagelist = vx_test::f_resolve_testpackagelist(testpackagelist);
    vx_test::Type_testpackagelist testpackagelist_resolved = vx_core::vx_sync_from_async(vx_test::t_testpackagelist(), async_testpackagelist);
    return run_testpackagelist(testpackagelist_resolved);
  }

  // Blocking
  // This is the preferred way of writing testsuite (1 block per testsuite)
  vx_core::Type_boolean write_testpackagelist_async(vx_test::Type_testpackagelist testpackagelist, vx_core::Type_context context) {
    vx_core::vx_Type_async async_testpackagelist = vx_test::f_resolve_testpackagelist(testpackagelist);
    vx_test::Type_testpackagelist testpackagelist_resolved = vx_core::vx_sync_from_async(vx_test::t_testpackagelist(), async_testpackagelist);
    vx_data_file::Type_file filetest = vx_test::f_file_test();
    vx_core::Type_boolean booleanwritetest = vx_data_file::f_boolean_write_from_file_any(filetest, testpackagelist_resolved, context);
    vx_web_html::Type_div divtest = vx_test::f_div_from_testpackagelist(testpackagelist_resolved);
    vx_web_html::Type_html htmlnode = vx_test::f_html_from_divtest(divtest);
    vx_data_file::Type_file filenode = vx_test::f_file_testnode();
    vx_core::Type_boolean booleanwritenode = vx_data_file::f_boolean_write_from_file_any(filenode, htmlnode, context);
    vx_data_file::Type_file filehtml = vx_test::f_file_testhtml();
    vx_core::Type_string shtml = vx_web_html::f_string_from_html(htmlnode);
    vx_core::Type_boolean booleanwritehtml = vx_data_file::f_boolean_write_from_file_string(filehtml, shtml, context);
    vx_core::Type_boolean output = vx_core::vx_new(vx_core::t_boolean(), {booleanwritetest, booleanwritenode, booleanwritehtml});
    return output;
  }

}
