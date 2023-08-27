#include "../main/vx/core.hpp"
#include "../main/vx/test.hpp"
#include "../main/vx/data/file.hpp"
#include "../main/vx/web/html.hpp"

namespace test_lib {

  vx_test::Type_testresult sample_testresult(vx_core::Type_context context) {
    vx_test::Type_testresult output;
    long irefcount = vx_core::refcount;
    output = vx_test::f_test_true(
      vx_core::vx_new_boolean(true),
      context
    );
    vx_core::vx_memory_leak_test("sample_testresult", irefcount, 2);
    return output;
  }

  std::string sample_testresult_text() {
    std::string output =
      "(vx/test/testresult"
      "\n :actual true"
      "\n :code \":true\""
      "\n :expected true"
      "\n :passfail true)";
    return output;
  }

  vx_test::Type_testdescribe sample_testdescribe(vx_core::Type_context context) {
    vx_test::Type_testdescribe output;
    long irefcount = vx_core::refcount;
    output = vx_core::vx_new(vx_test::t_testdescribe(), {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true true)"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":testresult"),
      sample_testresult(context)
    });
    vx_core::vx_memory_leak_test("sample_testdescribe", irefcount, 5);
    return output;
  }

  std::string sample_testdescribe_text() {
    std::string output =
      "(vx/test/testdescribe"
      "\n :describename \"(test-true true)\""
      "\n :testpkg \"vx/core\""
      "\n :testresult"
      "\n  (vx/test/testresult"
      "\n   :actual true"
      "\n   :code \":true\""
      "\n   :expected true"
      "\n   :passfail true))";
    return output;
  }

  vx_test::Type_testdescribelist sample_testdescribelist(vx_core::Type_context context) {
    vx_test::Type_testdescribelist output;
    long irefcount = vx_core::refcount;
    output = vx_core::vx_any_from_any(
      vx_test::t_testdescribelist(),
      vx_test::t_testdescribelist()->vx_new_from_list({
        sample_testdescribe(context)
      })
    );
    vx_core::vx_memory_leak_test("sample_testdescribelist", irefcount, 6);
    return output;
  }

  std::string sample_testdescribelist_text() {
    std::string output =
      "(vx/test/testdescribelist"
      "\n (vx/test/testdescribe"
      "\n  :describename \"(test-true true)\""
      "\n  :testpkg \"vx/core\""
      "\n  :testresult"
      "\n   (vx/test/testresult"
      "\n    :actual true"
      "\n    :code \":true\""
      "\n    :expected true"
      "\n    :passfail true)))";
    return output;
  }

  vx_test::Type_testcase sample_testcase(vx_core::Type_context context) {
    vx_test::Type_testcase output;
    long irefcount = vx_core::refcount;
    output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("boolean"),
      vx_core::vx_new_string(":describelist"), sample_testdescribelist(context)
    });
    vx_core::vx_memory_leak_test("sample_testcase", irefcount, 9);
    return output;
  }

  std::string sample_testcase_text() {
    std::string output =
      "(vx/test/testcase"
      "\n :casename \"boolean\""
      "\n :describelist"
      "\n  (vx/test/testdescribelist"
      "\n   (vx/test/testdescribe"
      "\n    :describename \"(test-true true)\""
      "\n    :testpkg \"vx/core\""
      "\n    :testresult"
      "\n     (vx/test/testresult"
      "\n      :actual true"
      "\n      :code \":true\""
      "\n      :expected true"
      "\n      :passfail true)))"
      "\n :testpkg \"vx/core\")";
    return output;
  }

  std::string sample_testcase_resolved_text() {
    std::string output =
      "(vx/test/testcase"
      "\n :casename \"boolean\""
      "\n :describelist"
      "\n  (vx/test/testdescribelist"
      "\n   (vx/test/testdescribe"
      "\n    :describename \"(test-true true)\""
      "\n    :testpkg \"vx/core\""
      "\n    :testresult"
      "\n     (vx/test/testresult"
      "\n      :actual true"
      "\n      :code \":true\""
      "\n      :expected true"
      "\n      :passfail true)))"
      "\n :passfail true"
      "\n :testpkg \"vx/core\")";
    return output;
  }

  vx_test::Type_testcaselist sample_testcaselist(vx_core::Type_context context) {
    vx_test::Type_testcaselist output;
    long irefcount = vx_core::refcount;
    output = vx_core::vx_any_from_any(
      vx_test::t_testcaselist(),
      vx_test::t_testcaselist()->vx_new_from_list({
        sample_testcase(context)
      })
    );
    vx_core::vx_memory_leak_test("sample_testcaselist", irefcount, 10);
    return output;
  }

  std::string sample_testcaselist_text() {
    std::string output =
      "(vx/test/testcaselist"
      "\n (vx/test/testcase"
      "\n  :casename \"boolean\""
      "\n  :describelist"
      "\n   (vx/test/testdescribelist"
      "\n    (vx/test/testdescribe"
      "\n     :describename \"(test-true true)\""
      "\n     :testpkg \"vx/core\""
      "\n     :testresult"
      "\n      (vx/test/testresult"
      "\n       :actual true"
      "\n       :code \":true\""
      "\n       :expected true"
      "\n       :passfail true)))"
      "\n  :testpkg \"vx/core\"))";
    return output;
  }

  std::string sample_testcaselist_resolved_text() {
    std::string output =
      "(vx/test/testcaselist"
      "\n (vx/test/testcase"
      "\n  :casename \"boolean\""
      "\n  :describelist"
      "\n   (vx/test/testdescribelist"
      "\n    (vx/test/testdescribe"
      "\n     :describename \"(test-true true)\""
      "\n     :testpkg \"vx/core\""
      "\n     :testresult"
      "\n      (vx/test/testresult"
      "\n       :actual true"
      "\n       :code \":true\""
      "\n       :expected true"
      "\n       :passfail true)))"
      "\n  :passfail true"
      "\n  :testpkg \"vx/core\"))";
    return output;
  }

  vx_test::Type_testpackage sample_testpackage(vx_core::Type_context context) {
    vx_test::Type_testpackage output;
    long irefcount = vx_core::refcount;
    output = vx_core::vx_new(vx_test::t_testpackage(), {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":caselist"), sample_testcaselist(context)
    });
    vx_core::vx_memory_leak_test("sample_testpackage", irefcount, 12);
    return output;
  }

  std::string sample_testpackage_text() {
    std::string output =
      "(vx/test/testpackage"
      "\n :caselist"
      "\n  (vx/test/testcaselist"
      "\n   (vx/test/testcase"
      "\n    :casename \"boolean\""
      "\n    :describelist"
      "\n     (vx/test/testdescribelist"
      "\n      (vx/test/testdescribe"
      "\n       :describename \"(test-true true)\""
      "\n       :testpkg \"vx/core\""
      "\n       :testresult"
      "\n        (vx/test/testresult"
      "\n         :actual true"
      "\n         :code \":true\""
      "\n         :expected true"
      "\n         :passfail true)))"
      "\n    :testpkg \"vx/core\"))"
      "\n :testpkg \"vx/core\")";
    return output;
  }

  std::string sample_testpackage_resolved_text() {
    std::string output =
      "(vx/test/testpackage"
      "\n :caselist"
      "\n  (vx/test/testcaselist"
      "\n   (vx/test/testcase"
      "\n    :casename \"boolean\""
      "\n    :describelist"
      "\n     (vx/test/testdescribelist"
      "\n      (vx/test/testdescribe"
      "\n       :describename \"(test-true true)\""
      "\n       :testpkg \"vx/core\""
      "\n       :testresult"
      "\n        (vx/test/testresult"
      "\n         :actual true"
      "\n         :code \":true\""
      "\n         :expected true"
      "\n         :passfail true)))"
      "\n    :passfail true"
      "\n    :testpkg \"vx/core\"))"
      "\n :passfail true"
      "\n :testpkg \"vx/core\")";
    return output;
  }

  vx_test::Type_testpackagelist sample_testpackagelist(vx_core::Type_context context) {
    vx_test::Type_testpackagelist output;
    long irefcount = vx_core::refcount;
    output = vx_core::vx_any_from_any(
      vx_test::t_testpackagelist(),
      vx_test::t_testpackagelist()->vx_new_from_list({
        sample_testpackage(context)
      })
    );
    vx_core::vx_memory_leak_test("sample_testpackagelist", irefcount, 13);
    return output;
  }

  std::string sample_testpackagelist_text() {
    std::string output =
      "(vx/test/testpackagelist"
      "\n (vx/test/testpackage"
      "\n  :caselist"
      "\n   (vx/test/testcaselist"
      "\n    (vx/test/testcase"
      "\n     :casename \"boolean\""
      "\n     :describelist"
      "\n      (vx/test/testdescribelist"
      "\n       (vx/test/testdescribe"
      "\n        :describename \"(test-true true)\""
      "\n        :testpkg \"vx/core\""
      "\n        :testresult"
      "\n         (vx/test/testresult"
      "\n          :actual true"
      "\n          :code \":true\""
      "\n          :expected true"
      "\n          :passfail true)))"
      "\n     :testpkg \"vx/core\"))"
      "\n  :testpkg \"vx/core\"))";
    return output;
  }

  std::string sample_testpackagelist_resolved_text() {
    std::string output =
      "(vx/test/testpackagelist"
      "\n (vx/test/testpackage"
      "\n  :caselist"
      "\n   (vx/test/testcaselist"
      "\n    (vx/test/testcase"
      "\n     :casename \"boolean\""
      "\n     :describelist"
      "\n      (vx/test/testdescribelist"
      "\n       (vx/test/testdescribe"
      "\n        :describename \"(test-true true)\""
      "\n        :testpkg \"vx/core\""
      "\n        :testresult"
      "\n         (vx/test/testresult"
      "\n          :actual true"
      "\n          :code \":true\""
      "\n          :expected true"
      "\n          :passfail true)))"
      "\n     :passfail true"
      "\n     :testpkg \"vx/core\"))"
      "\n  :passfail true"
      "\n  :testpkg \"vx/core\"))";
    return output;
  }

	vx_test::Type_testresult run_testresult(std::string testpkg, std::string testname, std::string message, vx_test::Type_testresult testresult) {
    vx_core::Type_any valexpected = testresult->expected();
    vx_core::Type_any valactual = testresult->actual();
    bool passfail = testresult->passfail()->vx_boolean();
    if (!passfail) {
      //std::string code = testresult->code()->vx_string();
      std::string expected = vx_core::vx_string_from_any(valexpected);
      std::string actual = vx_core::vx_string_from_any(valactual);
      std::string msg = testpkg + "/" + testname + "\n" + message;
      vx_core::vx_debug("--Test Result Fail-- " + msg);
      vx_core::vx_debug("---Expected---\n" + expected);
      vx_core::vx_debug("---Actual---\n" + actual);
      //vx_core::vx_debug(testresult);
      vx_core::vx_debug("");
    }
    return testresult;
  }

  // Blocking
  vx_test::Type_testresult run_testresult_async(std::string testpkg, std::string testname, std::string message, vx_test::Type_testresult testresult) {
    vx_core::vx_Type_async async_testresult = vx_test::f_resolve_testresult(testresult);
    vx_test::Type_testresult testresult_resolved = vx_core::vx_sync_from_async(vx_test::t_testresult(), async_testresult);
    vx_test::Type_testresult output = test_lib::run_testresult(testpkg, testname, message, testresult_resolved);
    vx_core::vx_release_except(testresult_resolved, output);
		return output;
  }

  vx_test::Type_testdescribe run_testdescribe(std::string testpkg, std::string casename, vx_test::Type_testdescribe testdescribe) {
    vx_core::vx_reserve(testdescribe);
    vx_core::Type_string testcode = testdescribe->describename();
    std::string message = testcode->vx_string();
    vx_test::Type_testresult testresult = testdescribe->testresult();
    vx_test::Type_testresult testresult_resolved = test_lib::run_testresult(testpkg, casename, message, testresult);
    vx_test::Type_testdescribe output = vx_core::vx_copy(testdescribe, {
      vx_core::vx_new_string(":testresult"), testresult_resolved
    });
    vx_core::vx_release_one_except(testdescribe, output);
		return output;
  }

  // Blocking
  // Only use if running a single testdescribe
  vx_test::Type_testdescribe run_testdescribe_async(std::string testpkg, std::string casename, vx_test::Type_testdescribe testdescribe) {
    vx_core::vx_Type_async async_testdescribe = vx_test::f_resolve_testdescribe(testdescribe);
    vx_test::Type_testdescribe testdescribe_resolved = vx_core::vx_sync_from_async(vx_test::t_testdescribe(), async_testdescribe);
    vx_test::Type_testdescribe output = test_lib::run_testdescribe(testpkg, casename, testdescribe_resolved);
		return output;
  }

  vx_test::Type_testdescribelist run_testdescribelist(std::string testpkg, std::string casename, vx_test::Type_testdescribelist testdescribelist) {
    vx_core::vx_reserve(testdescribelist);
    std::vector<vx_test::Type_testdescribe> listtestdescribe = testdescribelist->vx_listtestdescribe();
    vx_core::vx_Type_listany listtestdescribe_resolved;
    for (vx_test::Type_testdescribe testdescribe : listtestdescribe) {
      vx_test::Type_testdescribe testdescribe_resolved = test_lib::run_testdescribe(testpkg, casename, testdescribe);
			listtestdescribe_resolved.push_back(testdescribe_resolved);
    }
		vx_test::Type_testdescribelist output = vx_core::vx_any_from_any(
			vx_test::t_testdescribelist(),
			testdescribelist->vx_new_from_list(listtestdescribe_resolved)
		);
    vx_core::vx_release_one_except(testdescribelist, output);
    return output;
  }

  // Blocking
  // Only use if running a single testdescribelist
  vx_test::Type_testdescribelist run_testdescribelist_async(std::string testpkg, std::string casename, vx_test::Type_testdescribelist testdescribelist) {
    vx_core::vx_Type_async async_testdescribelist = vx_test::f_resolve_testdescribelist(testdescribelist);
    vx_test::Type_testdescribelist testdescribelist_resolved = vx_core::vx_sync_from_async(vx_test::t_testdescribelist(), async_testdescribelist);
    vx_test::Type_testdescribelist output = test_lib::run_testdescribelist(testpkg, casename, testdescribelist_resolved);
    return output;
  }

  vx_test::Type_testcase run_testcase(vx_test::Type_testcase testcase) {
    vx_core::vx_reserve(testcase);
    std::string testpkg = testcase->testpkg()->vx_string();
    std::string casename = testcase->casename()->vx_string();
    vx_test::Type_testdescribelist testdescribelist = testcase->describelist();
    vx_test::Type_testdescribelist testdescribelist_resolved = test_lib::run_testdescribelist(testpkg, casename, testdescribelist);
    vx_test::Type_testcase output = vx_core::vx_copy(testcase, {
      vx_core::vx_new_string(":describelist"), testdescribelist_resolved
    });
    vx_core::vx_release_one_except(testcase, output);
		return output;
  }

  // Blocking
  // Only use if running a single testcase
  vx_test::Type_testcase run_testcase_async(vx_test::Type_testcase testcase) {
    vx_core::vx_Type_async async_testcase = vx_test::f_resolve_testcase(testcase);
    vx_test::Type_testcase testcase_resolved = vx_core::vx_sync_from_async(vx_test::t_testcase(), async_testcase);
    vx_test::Type_testcase output = test_lib::run_testcase(testcase_resolved);
		return output;
  }

	vx_test::Type_testcaselist run_testcaselist(vx_test::Type_testcaselist testcaselist) {
    vx_core::vx_reserve(testcaselist);
    std::vector<vx_test::Type_testcase> listtestcase = testcaselist->vx_listtestcase();
    vx_core::vx_Type_listany listtestcase_resolved;
    for (vx_test::Type_testcase testcase : listtestcase) {
      vx_test::Type_testcase testcase_resolved = test_lib::run_testcase(testcase);
			listtestcase_resolved.push_back(testcase_resolved);
    }
		vx_test::Type_testcaselist output = vx_core::vx_any_from_any(
			vx_test::t_testcaselist(),
			testcaselist->vx_new_from_list(listtestcase_resolved)
		);
    vx_core::vx_release_one_except(testcaselist, output);
    return output;
  }

  // Blocking
  // Only use if running a single testcaselist
  vx_test::Type_testcaselist run_testcaselist_async(vx_test::Type_testcaselist testcaselist) {
    vx_core::vx_Type_async async_testcaselist = vx_test::f_resolve_testcaselist(testcaselist);
    vx_test::Type_testcaselist testcaselist_resolved = vx_core::vx_sync_from_async(vx_test::t_testcaselist(), async_testcaselist);
    vx_test::Type_testcaselist output = test_lib::run_testcaselist(testcaselist_resolved);
    return output;
  }

  vx_test::Type_testpackage run_testpackage(vx_test::Type_testpackage testpackage) {
    vx_core::vx_reserve(testpackage);
    vx_test::Type_testcaselist testcaselist = testpackage->caselist();
    vx_test::Type_testcaselist testcaselist_resolved = test_lib::run_testcaselist(testcaselist);
		vx_test::Type_testpackage output = vx_core::vx_copy(testpackage, {
      vx_core::vx_new_string(":caselist"), testcaselist_resolved
    });
    vx_core::vx_release_one_except(testpackage, output);
		return output;
  }

  // Blocking
  // This is the preferred way of calling test (1 block per package)
  vx_test::Type_testpackage run_testpackage_async(vx_test::Type_testpackage testpackage) {
    vx_core::vx_Type_async async_testpackage = vx_test::f_resolve_testpackage(testpackage);
    vx_test::Type_testpackage testpackage_resolved = vx_core::vx_sync_from_async(vx_test::t_testpackage(), async_testpackage);
    vx_test::Type_testpackage output = test_lib::run_testpackage(testpackage_resolved);
		return output;
  }

  vx_test::Type_testpackagelist run_testpackagelist(vx_test::Type_testpackagelist testpackagelist) {
    vx_core::vx_reserve(testpackagelist);
    std::vector<vx_test::Type_testpackage> listtestpackage = testpackagelist->vx_listtestpackage();
    vx_core::vx_Type_listany listtestpackage_resolved;
    for (vx_test::Type_testpackage testpackage : listtestpackage) {
      vx_test::Type_testpackage testpackage_resolved = test_lib::run_testpackage(testpackage);
			listtestpackage_resolved.push_back(testpackage_resolved);
    }
		vx_test::Type_testpackagelist output = vx_core::vx_any_from_any(
			vx_test::t_testpackagelist(),
			testpackagelist->vx_new_from_list(listtestpackage_resolved)
		);
    vx_core::vx_release_one_except(testpackagelist, output);
    return output;
  }

  // Blocking
  // This is the preferred way of calling testsuite (1 block per testsuite)
  vx_test::Type_testpackagelist run_testpackagelist_async(vx_test::Type_testpackagelist testpackagelist) {
    vx_core::vx_Type_async async_testpackagelist = vx_test::f_resolve_testpackagelist(testpackagelist);
    vx_test::Type_testpackagelist testpackagelist_resolved = vx_core::vx_sync_from_async(vx_test::t_testpackagelist(), async_testpackagelist);
    vx_test::Type_testpackagelist output = test_lib::run_testpackagelist(testpackagelist_resolved);
		return output;
  }

  vx_core::Type_boolean write_html(vx_web_html::Type_html htmlnode) {
    vx_core::Type_string string_html = vx_web_html::f_string_from_html(htmlnode);
    vx_data_file::Type_file file = vx_test::f_file_testhtml();
    vx_core::Type_boolean output = vx_data_file::vx_boolean_write_from_file_string(file, string_html);
    return output;
  }

  vx_core::Type_boolean write_node(vx_web_html::Type_html htmlnode) {
    vx_core::Type_string string_node = vx_core::f_string_from_any(htmlnode);
    vx_data_file::Type_file file = vx_test::f_file_testnode();
    vx_core::Type_boolean output = vx_data_file::vx_boolean_write_from_file_string(file, string_node);
    return output;
  }

  vx_core::Type_boolean write_testpackagelist(vx_test::Type_testpackagelist testpackagelist, vx_core::Type_context context) {
    vx_core::Type_string string_node = vx_core::f_string_from_any(testpackagelist);
    vx_data_file::Type_file file = vx_test::f_file_test();
    vx_core::Type_boolean output = vx_data_file::vx_boolean_write_from_file_string(file, string_node);
    return output;
  }

  // Blocking
  // This is the preferred way of writing testsuite (1 block per testsuite)
  vx_core::Type_boolean write_testpackagelist_async(vx_test::Type_testpackagelist testpackagelist, vx_core::Type_context context) {
    vx_test::Type_testpackagelist testpackagelist_resolved = test_lib::run_testpackagelist_async(testpackagelist);
    vx_core::vx_reserve(testpackagelist_resolved);
    vx_core::Type_boolean write_testpackagelist = test_lib::write_testpackagelist(testpackagelist_resolved, context);
    vx_web_html::Type_div divtest = vx_test::f_div_from_testpackagelist(testpackagelist_resolved);
    vx_core::vx_release_one(testpackagelist_resolved);
    vx_web_html::Type_html htmlnode = vx_test::f_html_from_divtest(divtest);
    vx_core::vx_reserve(htmlnode);
    vx_core::Type_boolean write_node = test_lib::write_node(htmlnode);
    vx_core::Type_boolean write_html = test_lib::write_html(htmlnode);
    vx_core::vx_release_one(htmlnode);
    vx_core::Type_boolean output = vx_core::vx_new(vx_core::t_boolean(), {
      write_testpackagelist,
      write_node,
      write_html
    });
    return output;
  }

  bool test(std::string testname, std::string expected, std::string actual) {
    bool output = false;
    if (expected == actual) {
      vx_core::vx_debug("Test Pass: " + testname);
      output = true;
    } else {
      vx_core::vx_debug("Test Fail: " + testname);
      vx_core::vx_debug("Expected:\n" + expected);
      vx_core::vx_debug("Actual:\n" + actual);
    }
    return output;
  }

  bool test_helloworld() {
    std::string testname = "test_helloworld";
    long irefcount = vx_core::refcount;
    vx_core::Type_string helloworld = vx_core::vx_new_string("Hello World");
    std::string expected = "Hello World";
    std::string actual = helloworld->vx_string();
    bool output = test_lib::test(testname, expected, actual);
    vx_core::vx_release(helloworld);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_async_new_from_value() {
    std::string testname = "test_async_new_from_value";
    long irefcount = vx_core::refcount;
    vx_core::Type_string helloworld = vx_core::vx_new_string("Hello World");
    vx_core::vx_Type_async async = vx_core::vx_async_new_from_value(helloworld);
    vx_core::Type_string sync = vx_core::vx_sync_from_async(vx_core::t_string(), async);
    std::string expected = "Hello World";
    std::string actual = sync->vx_string();
    vx_core::vx_release(sync);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_async_from_async_fn() {
    std::string testname = "test_async_from_async_fn";
    long irefcount = vx_core::refcount;
    vx_core::Type_string helloworld = vx_core::vx_new_string("Hello World");
    vx_core::vx_Type_async async = vx_core::vx_async_new_from_value(helloworld);
    vx_core::vx_Type_async async1 = vx_core::vx_async_from_async_fn(
      async,
      vx_core::t_string(),
      {},
      [](vx_core::Type_any any) {
        return any;
      }
    );
    vx_core::Type_string sync = vx_core::vx_sync_from_async(vx_core::t_string(), async1);
    std::string expected = "Hello World";
    std::string actual = sync->vx_string();
    vx_core::vx_release(sync);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_html_from_testpackagelist(vx_core::Type_context context) {
    std::string testname = "test_html_from_testpackagelist";
    long irefcount = vx_core::refcount;
    vx_data_file::Type_file file = vx_core::vx_new(vx_data_file::t_file(), {
      vx_core::vx_new_string(":path"), vx_core::vx_new_string("src/test/resources/vx"),
      vx_core::vx_new_string(":name"), vx_core::vx_new_string(testname + ".html")
    });
    vx_core::Type_string string_file = vx_data_file::vx_string_read_from_file(file);
    std::string expected = string_file->vx_string();
    vx_core::vx_release(string_file);
    vx_test::Type_testcaselist testcaselist = sample_testcaselist(context);
    vx_web_html::Type_div div = vx_test::f_div_from_testcaselist(testcaselist);
    vx_web_html::Type_html html = vx_test::f_html_from_divtest(div);
    vx_core::Type_string string_html = vx_web_html::f_string_from_html(html);
    std::string actual = string_html->vx_string();
    vx_core::vx_release(string_html);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_node_from_testpackagelist(vx_core::Type_context context) {
    std::string testname = "test_node_from_testpackagelist";
    long irefcount = vx_core::refcount;
    vx_data_file::Type_file file = vx_core::vx_new(vx_data_file::t_file(), {
      vx_core::vx_new_string(":path"), vx_core::vx_new_string("src/test/resources/vx"),
      vx_core::vx_new_string(":name"), vx_core::vx_new_string(testname + ".vxlisp")
    });
    vx_core::Type_string string_file = vx_data_file::vx_string_read_from_file(file);
    std::string expected = string_file->vx_string();
    vx_core::vx_release(string_file);
    vx_test::Type_testcaselist testcaselist = sample_testcaselist(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 10);
    vx_web_html::Type_div div = vx_test::f_div_from_testcaselist(testcaselist);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 52);
    vx_web_html::Type_html html = vx_test::f_html_from_divtest(div);
    std::string actual = vx_core::vx_string_from_any(html);
    vx_core::vx_release(html);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_node_f_div_from_testcaselist(vx_core::Type_context context) {
    std::string testname = "test_node_f_div_from_testcaselist";
    long irefcount = vx_core::refcount;
    vx_data_file::Type_file file = vx_core::vx_new(vx_data_file::t_file(), {
      vx_core::vx_new_string(":path"), vx_core::vx_new_string("src/test/resources/vx"),
      vx_core::vx_new_string(":name"), vx_core::vx_new_string(testname + ".vxlisp")
    });
    vx_core::Type_string string_file = vx_data_file::vx_string_read_from_file(file);
    std::string expected = string_file->vx_string();
    vx_core::vx_release(string_file);
    vx_test::Type_testcaselist testcaselist = sample_testcaselist(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 10);
    vx_web_html::Type_div div = vx_test::f_div_from_testcaselist(testcaselist);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 52);
    std::string actual = vx_core::vx_string_from_any(div);
    vx_core::vx_release(div);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_node_f_trlist_from_testcase(vx_core::Type_context context) {
    std::string testname = "test_node_f_trlist_from_testcase";
    long irefcount = vx_core::refcount;
    vx_data_file::Type_file file = vx_core::vx_new(vx_data_file::t_file(), {
      vx_core::vx_new_string(":path"), vx_core::vx_new_string("src/test/resources/vx"),
      vx_core::vx_new_string(":name"), vx_core::vx_new_string(testname + ".vxlisp")
    });
    vx_core::Type_string string_file = vx_data_file::vx_string_read_from_file(file);
    std::string expected = string_file->vx_string();
    vx_core::vx_release(string_file);
    vx_test::Type_testcase testcase = sample_testcase(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 9);
    vx_web_html::Type_trlist trlist = vx_test::f_trlist_from_testcase(testcase);
    std::string actual = vx_core::vx_string_from_any(trlist);
    vx_core::vx_release(trlist);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_node_f_trlist_from_testcaselist(vx_core::Type_context context) {
    std::string testname = "test_node_f_trlist_from_testcaselist";
    long irefcount = vx_core::refcount;
    vx_data_file::Type_file file = vx_core::vx_new(vx_data_file::t_file(), {
      vx_core::vx_new_string(":path"), vx_core::vx_new_string("src/test/resources/vx"),
      vx_core::vx_new_string(":name"), vx_core::vx_new_string(testname + ".vxlisp")
    });
    vx_core::Type_string string_file = vx_data_file::vx_string_read_from_file(file);
    std::string expected = string_file->vx_string();
    vx_core::vx_release(string_file);
    vx_test::Type_testcaselist testcaselist = sample_testcaselist(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 10);
    vx_core::vx_reserve(testcaselist);

    vx_core::Func_any_from_any fn_any_from_any = vx_test::t_trlist_from_testcase();
    vx_core::Type_any list = vx_core::vx_list_join_from_list_fn(vx_web_html::t_trlist(), testcaselist, fn_any_from_any);

    vx_core::vx_release_one_except(testcaselist, list);
    std::string actual = vx_core::vx_string_from_any(list);
    vx_core::vx_release(list);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_node_f_trlist_from_testcaselist1(vx_core::Type_context context) {
    std::string testname = "test_node_f_trlist_from_testcaselist";
    long irefcount = vx_core::refcount;
    vx_data_file::Type_file file = vx_core::vx_new(vx_data_file::t_file(), {
      vx_core::vx_new_string(":path"), vx_core::vx_new_string("src/test/resources/vx"),
      vx_core::vx_new_string(":name"), vx_core::vx_new_string(testname + ".vxlisp")
    });
    vx_core::Type_string string_file = vx_data_file::vx_string_read_from_file(file);
    std::string expected = string_file->vx_string();
    vx_core::vx_release(string_file);
    vx_test::Type_testcaselist testcaselist = sample_testcaselist(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 10);
    vx_web_html::Type_trlist trlist = vx_test::f_trlist_from_testcaselist(testcaselist);
    std::string actual = vx_core::vx_string_from_any(trlist);
    vx_core::vx_release(trlist);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_all(vx_test::Type_testpackagelist testpackagelist, vx_core::Type_context context) {
    vx_core::Type_boolean issuccess = test_lib::write_testpackagelist_async(testpackagelist, context);
    std::string expected = "true";
    std::string actual = vx_core::vx_string_from_any(issuccess);
    bool output = test_lib::test("Full Test Suite", expected, actual);
    vx_core::vx_release(issuccess);
    return output;
  }

  bool test_run_testcase(vx_core::Type_context context) {
    std::string testname = "test_run_testcase";
    long irefcount = vx_core::refcount;
    vx_test::Type_testcase testcase = sample_testcase(context);
    vx_test::Type_testcase testcase_resolved = test_lib::run_testcase(testcase);
    std::string expected = sample_testcase_text();
    std::string actual = vx_core::vx_string_from_any(testcase_resolved);
    vx_core::vx_release(testcase_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testcase_async(vx_core::Type_context context) {
    std::string testname = "test_run_testcase_async";
    long irefcount = vx_core::refcount;
    vx_test::Type_testcase testcase = sample_testcase(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 9);
    vx_test::Type_testcase testcase_resolved = test_lib::run_testcase_async(testcase);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 9);
    std::string expected = sample_testcase_resolved_text();
    std::string actual = vx_core::vx_string_from_any(testcase_resolved);
    vx_core::vx_release(testcase_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testcase_async_f_resolvetestcase(vx_core::Type_context context) {
    std::string testname = "test_run_testcase_async_f_resolvetestcase";
    long irefcount = vx_core::refcount;
    vx_test::Type_testcase testcase = sample_testcase(context);
    vx_core::vx_Type_async async_testcase = vx_test::f_resolve_testcase(testcase);
    vx_core::vx_memory_leak_test(testname, irefcount, 14);
    std::string expected =
      "(async"
      "\n :type vx/test/testcase"
      "\n :lambdavars ("
      "\n  (vx/test/testcase"
      "\n   :casename \"boolean\""
      "\n   :describelist"
      "\n    (vx/test/testdescribelist"
      "\n     (vx/test/testdescribe"
      "\n      :describename \"(test-true true)\""
      "\n      :testpkg \"vx/core\""
      "\n      :testresult"
      "\n       (vx/test/testresult"
      "\n        :actual true"
      "\n        :code \":true\""
      "\n        :expected true"
      "\n        :passfail true)))"
      "\n   :testpkg \"vx/core\"))"
      "\n :fn fn"
      "\n :async_parent"
      "\n  (async"
      "\n   :type vx/test/testdescribelist"
      "\n   :listasync ("
      "\n    (async"
      "\n     :type vx/test/testdescribe"
      "\n     :lambdavars ("
      "\n      (vx/test/testdescribe"
      "\n       :describename \"(test-true true)\""
      "\n       :testpkg \"vx/core\""
      "\n       :testresult"
      "\n        (vx/test/testresult"
      "\n         :actual true"
      "\n         :code \":true\""
      "\n         :expected true"
      "\n         :passfail true)))"
      "\n     :fn fn"
      "\n     :async_parent"
      "\n      (async"
      "\n       :type vx/test/testresult"
      "\n       :lambdavars ("
      "\n        (any<-func-async)"
      "\n        (vx/test/testresult"
      "\n         :actual true"
      "\n         :code \":true\""
      "\n         :expected true"
      "\n         :passfail true)"
      "\n        true)"
      "\n       :fn fn"
      "\n       :async_parent"
      "\n        (async"
      "\n         :type any"
      "\n         :value (any)))))))";
    std::string actual = vx_core::vx_string_from_async(async_testcase);
    vx_core::vx_release_async(async_testcase);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testcase_async_syncvalue(vx_core::Type_context context) {
    std::string testname = "test_run_testcase_async_syncvalue";
    long irefcount = vx_core::refcount;
    vx_test::Type_testcase testcase = sample_testcase(context);
    vx_core::vx_memory_leak_test(testname, irefcount, 9);
    vx_core::vx_Type_async async_testcase = vx_test::f_resolve_testcase(testcase);
    vx_core::vx_memory_leak_test(testname, irefcount, 14);
    vx_core::vx_Type_async async_testdescribelist = async_testcase->async_parent;
    vx_core::vx_Type_listasync list_async_testdescribe = async_testdescribelist->listasync;
    vx_core::vx_Type_async async_testdescribe = list_async_testdescribe[0];
    vx_core::vx_Type_async async_testresult = async_testdescribe->async_parent;
    vx_core::vx_Type_async async_any = async_testresult->async_parent;
    vx_core::Type_any any = async_any->sync_value();
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 14);
    vx_core::Type_any testresult_resolved = async_testresult->sync_value();
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 13);
    vx_core::Type_any testdescribe_resolved = async_testdescribe->sync_value();
    vx_core::vx_memory_leak_test(testname + "-3", irefcount, 13);
    vx_core::Type_any testdescribelist_resolved = async_testdescribelist->sync_value();
    vx_core::vx_memory_leak_test(testname + "-4", irefcount, 13);
    vx_core::Type_any testcase_resolved = async_testcase->sync_value();
    vx_core::vx_memory_leak_test(testname + "-5", irefcount, 10);
    std::string expected = sample_testcase_resolved_text();
    std::string actual = vx_core::vx_string_from_any(testcase_resolved);
    vx_core::vx_release_async(async_testcase);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testcaselist(vx_core::Type_context context) {
    std::string testname = "test_run_testcaselist";
    long irefcount = vx_core::refcount;
    vx_test::Type_testcaselist testcaselist = sample_testcaselist(context);
    vx_test::Type_testcaselist testcaselist_resolved = test_lib::run_testcaselist(testcaselist);
    std::string expected = sample_testcaselist_text();
    std::string actual = vx_core::vx_string_from_any(testcaselist_resolved);
    vx_core::vx_release(testcaselist_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testcaselist_async(vx_core::Type_context context) {
    std::string testname = "test_run_testcaselist_async";
    long irefcount = vx_core::refcount;
    vx_test::Type_testcaselist testcaselist = sample_testcaselist(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 10);
    vx_test::Type_testcaselist testcaselist_resolved = test_lib::run_testcaselist_async(testcaselist);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 10);
    std::string expected = sample_testcaselist_resolved_text();
    std::string actual = vx_core::vx_string_from_any(testcaselist_resolved);
    vx_core::vx_release(testcaselist_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testdescribe(vx_core::Type_context context) {
    std::string testname = "test_run_testdescribe";
    long irefcount = vx_core::refcount;
    vx_test::Type_testdescribe testdescribe = sample_testdescribe(context);
    vx_test::Type_testdescribe testdescribe_resolved = test_lib::run_testdescribe("vx/core", "boolean", testdescribe);
    std::string expected = sample_testdescribe_text();
    std::string actual = vx_core::vx_string_from_any(testdescribe_resolved);
    vx_core::vx_release(testdescribe_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testdescribe_async(vx_core::Type_context context) {
    std::string testname = "test_run_testdescribe_async";
    long irefcount = vx_core::refcount;
    vx_test::Type_testdescribe testdescribe = sample_testdescribe(context);
    vx_test::Type_testdescribe testdescribe_resolved = test_lib::run_testdescribe_async("vx/core", "boolean", testdescribe);
    std::string expected = sample_testdescribe_text();
    std::string actual = vx_core::vx_string_from_any(testdescribe_resolved);
    vx_core::vx_release(testdescribe_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testdescribelist(vx_core::Type_context context) {
    std::string testname = "test_run_testdescribelist";
    long irefcount = vx_core::refcount;
    vx_test::Type_testdescribelist testdescribelist = sample_testdescribelist(context);
    vx_test::Type_testdescribelist testdescribelist_resolved = test_lib::run_testdescribelist("vx/core", "boolean", testdescribelist);
    std::string expected = sample_testdescribelist_text();
    std::string actual = vx_core::vx_string_from_any(testdescribelist_resolved);
    vx_core::vx_release(testdescribelist_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testdescribelist_async(vx_core::Type_context context) {
    std::string testname = "test_run_testdescribelist_async";
    long irefcount = vx_core::refcount;
    vx_test::Type_testdescribelist testdescribelist = sample_testdescribelist(context);
    vx_test::Type_testdescribelist testdescribelist_resolved = test_lib::run_testdescribelist_async("vx/core", "boolean", testdescribelist);
    std::string expected = sample_testdescribelist_text();
    std::string actual = vx_core::vx_string_from_any(testdescribelist_resolved);
    vx_core::vx_release(testdescribelist_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testdescribelist_async_f_list_from_list_async(vx_core::Type_context context) {
    std::string testname = "test_run_testdescribelist_async_f_list_from_list_async";
    long irefcount = vx_core::refcount;
    vx_test::Type_testdescribelist testdescribelist = sample_testdescribelist(context);
    vx_core::vx_Type_async async_testdescribelist = vx_core::f_list_from_list_async(
      vx_test::t_testdescribelist(),
      testdescribelist,
      vx_test::t_resolve_testdescribe()
    );
    vx_test::Type_testdescribelist testdescribelist_resolved = vx_core::vx_sync_from_async(vx_test::t_testdescribelist(), async_testdescribelist);
    std::string expected = sample_testdescribelist_text();
    std::string actual = vx_core::vx_string_from_any(testdescribelist_resolved);
    vx_core::vx_release(testdescribelist_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testpackage(vx_core::Type_context context) {
    std::string testname = "test_run_testpackage";
    long irefcount = vx_core::refcount;
    vx_test::Type_testpackage testpackage = sample_testpackage(context);
    vx_test::Type_testpackage testpackage_resolved = test_lib::run_testpackage(testpackage);
    std::string expected = sample_testpackage_text();
    std::string actual = vx_core::vx_string_from_any(testpackage_resolved);
    vx_core::vx_release(testpackage_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testpackage_async(vx_core::Type_context context) {
    std::string testname = "test_run_testpackage_async";
    long irefcount = vx_core::refcount;
    vx_test::Type_testpackage testpackage = sample_testpackage(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 12);
    vx_test::Type_testpackage testpackage_resolved = test_lib::run_testpackage_async(testpackage);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 12);
    std::string expected = sample_testpackage_resolved_text();
    std::string actual = vx_core::vx_string_from_any(testpackage_resolved);
    vx_core::vx_release(testpackage_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testpackagelist(vx_core::Type_context context) {
    std::string testname = "test_run_testpackagelist";
    long irefcount = vx_core::refcount;
    vx_test::Type_testpackagelist testpackagelist = sample_testpackagelist(context);
    vx_test::Type_testpackagelist testpackagelist_resolved = test_lib::run_testpackagelist(testpackagelist);
    std::string expected = sample_testpackagelist_text();
    std::string actual = vx_core::vx_string_from_any(testpackagelist_resolved);
    vx_core::vx_release(testpackagelist_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testpackagelist_async(vx_core::Type_context context) {
    std::string testname = "test_run_testpackagelist_async";
    long irefcount = vx_core::refcount;
    vx_test::Type_testpackagelist testpackagelist = sample_testpackagelist(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 13);
    vx_test::Type_testpackagelist testpackagelist_resolved = test_lib::run_testpackagelist_async(testpackagelist);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 13);
    std::string expected = sample_testpackagelist_resolved_text();
    std::string actual = vx_core::vx_string_from_any(testpackagelist_resolved);
    vx_core::vx_release(testpackagelist_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testresult(vx_core::Type_context context) {
    std::string testname = "test_run_testresult";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = sample_testresult(context);
    vx_test::Type_testresult testresult_resolved = run_testresult("vx/core", "boolean", "", testresult);
    std::string expected = sample_testresult_text();
    std::string actual = vx_core::vx_string_from_any(testresult_resolved);
    vx_core::vx_release(testresult_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_resolve_testresult_anyfromfunc(vx_core::Type_context context) {
    std::string testname = "test_resolve_testresult_anyfromfunc";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = sample_testresult(context);
    vx_core::Func_any_from_func_async fn_actual = testresult->fn_actual();
    vx_core::Type_any expected = testresult->expected();
    vx_core::Type_any actual = testresult->actual();
    vx_core::Func_any_from_func anyfromfunc = vx_core::t_any_from_func()->vx_fn_new({testresult}, [testresult]() {
      vx_core::Type_any output_1 = testresult;
      return output_1;
    });
    std::string expected1 = sample_testresult_text();
    std::string actual1 = vx_core::vx_string_from_any(testresult);
    vx_core::vx_release(anyfromfunc);
    bool output = test_lib::test(testname, expected1, actual1);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testresult_async(vx_core::Type_context context) {
    std::string testname = "test_run_testresult_async";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = sample_testresult(context);
    vx_test::Type_testresult testresult_resolved = test_lib::run_testresult_async("vx/core", "boolean", "", testresult);
    std::string expected = sample_testresult_text();
    std::string actual = vx_core::vx_string_from_any(testresult_resolved);
    vx_core::vx_release(testresult_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_resolve_testresult_f_resolve_testresult(vx_core::Type_context context) {
    std::string testname = "test_resolve_testresult_f_resolve_testresult";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = sample_testresult(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 2);
    vx_core::vx_Type_async async_testresult = vx_test::f_resolve_testresult(testresult);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 4);
    vx_test::Type_testresult testresult_resolved = vx_core::vx_sync_from_async(vx_test::t_testresult(), async_testresult);
    vx_core::vx_memory_leak_test(testname + "-3", irefcount, 2);
    std::string expected = sample_testresult_text();
    std::string actual = vx_core::vx_string_from_any(testresult_resolved);
    vx_core::vx_release(testresult_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_resolve_testresult_f_resolve_testresult_async(vx_core::Type_context context) {
    std::string testname = "test_resolve_testresult_f_resolve_testresult_async";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = sample_testresult(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 2);
    vx_core::vx_Type_async async_testresult = vx_test::f_resolve_testresult(testresult);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 4);
    std::string expected = 
      "(async"
      "\n :type vx/test/testresult"
      "\n :lambdavars ("
      "\n  (any<-func-async)"
      "\n  (vx/test/testresult"
      "\n   :actual true"
      "\n   :code \":true\""
      "\n   :expected true"
      "\n   :passfail true)"
      "\n  true)"
      "\n :fn fn"
      "\n :async_parent"
      "\n  (async"
      "\n   :type any"
      "\n   :value (any)))";
    std::string actual = vx_core::vx_string_from_async(async_testresult);
    vx_core::vx_release_async(async_testresult);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_resolve_testresult_if(vx_core::Type_context context) {
    std::string testname = "test_resolve_testresult_if";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = sample_testresult(context);
    vx_core::Func_any_from_func_async fn_actual = testresult->fn_actual();
    vx_core::Type_any expected = testresult->expected();
    vx_core::Type_any actual = testresult->actual();
    vx_core::Type_any output_2 = vx_core::f_if_2(
      vx_test::t_testresult(),
      vx_core::vx_new(vx_core::t_thenelselist(), {
        vx_core::f_then(
          vx_core::t_boolean_from_func()->vx_fn_new({fn_actual}, [fn_actual]() {
            vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(fn_actual);
            return output_1;
          }),
          vx_core::t_any_from_func()->vx_fn_new({testresult}, [testresult]() {
            vx_core::Type_any output_1 = testresult;
            return output_1;
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func()->vx_fn_new({expected, actual, testresult}, [expected, actual, testresult]() {
            vx_test::Type_testresult output_1 = vx_core::f_let(
              vx_test::t_testresult(),
              vx_core::t_any_from_func()->vx_fn_new({expected, actual, testresult}, [expected, actual, testresult]() {
                vx_core::Type_boolean passfail = vx_core::f_eq(expected, actual);
                vx_core::vx_ref_plus(passfail);
                vx_test::Type_testresult output_1 = vx_core::f_copy(
                  testresult,
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":passfail"),
                    passfail,
                    vx_core::vx_new_string(":actual"),
                    actual
                  })
                );
                vx_core::vx_release_one_except(passfail, output_1);
                return output_1;
              })
            );
            return output_1;
          })
        )
      })
    );
    std::string expected1 = sample_testresult_text();
    std::string actual1 = vx_core::vx_string_from_any(output_2);
    vx_core::vx_release(output_2);
    bool output = test_lib::test(testname, expected1, actual1);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_resolve_testresult_then(vx_core::Type_context context) {
    std::string testname = "test_resolve_testresult_then";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = sample_testresult(context);
    vx_core::Func_any_from_func_async fn_actual = testresult->fn_actual();
    vx_core::Type_any expected = testresult->expected();
    vx_core::Type_any actual = testresult->actual();
    vx_core::Type_thenelse thenelse = vx_core::f_then(
      vx_core::t_boolean_from_func()->vx_fn_new({fn_actual}, [fn_actual]() {
        vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(fn_actual);
        return output_1;
      }),
      vx_core::t_any_from_func()->vx_fn_new({testresult}, [testresult]() {
        vx_core::Type_any output_1 = testresult;
        return output_1;
      })
    );
    std::string expected1 = sample_testresult_text();
    std::string actual1 = vx_core::vx_string_from_any(testresult);
    vx_core::vx_release(thenelse);
    bool output = test_lib::test(testname, expected1, actual1);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_resolve_testresult_thenelselist(vx_core::Type_context context) {
    std::string testname = "test_resolve_testresult_thenelselist";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = sample_testresult(context);
    vx_core::Func_any_from_func_async fn_actual = testresult->fn_actual();
    vx_core::Type_any expected = testresult->expected();
    vx_core::Type_any actual = testresult->actual();
    vx_core::Type_thenelselist thenelselist = vx_core::vx_new(vx_core::t_thenelselist(), {
      vx_core::f_then(
        vx_core::t_boolean_from_func()->vx_fn_new({fn_actual}, [fn_actual]() {
          vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(fn_actual);
          return output_1;
        }),
        vx_core::t_any_from_func()->vx_fn_new({testresult}, [testresult]() {
          vx_core::Type_any output_1 = testresult;
          return output_1;
        })
      ),
      vx_core::f_else(
        vx_core::t_any_from_func()->vx_fn_new({expected, actual, testresult}, [expected, actual, testresult]() {
          vx_test::Type_testresult output_1 = vx_core::f_let(
            vx_test::t_testresult(),
            vx_core::t_any_from_func()->vx_fn_new({expected, actual, testresult}, [expected, actual, testresult]() {
              vx_core::Type_boolean passfail = vx_core::f_eq(expected, actual);
              vx_core::vx_ref_plus(passfail);
              vx_test::Type_testresult output_1 = vx_core::f_copy(
                testresult,
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_string(":passfail"),
                  passfail,
                  vx_core::vx_new_string(":actual"),
                  actual
                })
              );
              vx_core::vx_release_one_except(passfail, output_1);
              return output_1;
            })
          );
          return output_1;
        })
      )
    });
    std::string expected1 = sample_testresult_text();
    std::string actual1 = vx_core::vx_string_from_any(testresult);
    vx_core::vx_release(thenelselist);
    bool output = test_lib::test(testname, expected1, actual1);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_pathfull_from_file(vx_core::Type_context context) {
    std::string testname = "test_pathfull_from_file";
    long irefcount = vx_core::refcount;
    vx_data_file::Type_file file = vx_core::vx_new(vx_data_file::t_file(), {
      vx_core::vx_new_string(":path"), vx_core::vx_new_string("src/test/resources/vx"),
      vx_core::vx_new_string(":name"), vx_core::vx_new_string("string_read_from_file.txt")
    });
    vx_core::Type_string string_path = vx_data_file::f_pathfull_from_file(file);
    std::string expected = "src/test/resources/vx/string_read_from_file.txt";
    std::string actual = string_path->vx_string();
    vx_core::vx_release(string_path);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_read_file(vx_core::Type_context context) {
    std::string testname = "test_read_file";
    long irefcount = vx_core::refcount;
    vx_data_file::Type_file file = vx_core::vx_new(vx_data_file::t_file(), {
      vx_core::vx_new_string(":path"), vx_core::vx_new_string("src/test/resources/vx"),
      vx_core::vx_new_string(":name"), vx_core::vx_new_string("string_read_from_file.txt")
    });
    vx_core::Type_string string_file = vx_data_file::vx_string_read_from_file(file);
    std::string expected = "testdata";
    std::string actual = string_file->vx_string();
    vx_core::vx_release(string_file);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_write_file(vx_core::Type_context context) {
    std::string testname = "test_write_file";
    long irefcount = vx_core::refcount;
    vx_data_file::Type_file file = vx_core::vx_new(vx_data_file::t_file(), {
      vx_core::vx_new_string(":path"), vx_core::vx_new_string("src/test/resources/vx"),
      vx_core::vx_new_string(":name"), vx_core::vx_new_string("boolean_write_from_file_string.txt")
    });
    vx_core::Type_string string_file = vx_core::vx_new_string("writetext");
    vx_core::Type_boolean boolean_write = vx_data_file::vx_boolean_write_from_file_string(file, string_file);
    std::string expected = "true";
    std::string actual = vx_core::vx_string_from_any(boolean_write);
    vx_core::vx_release(boolean_write);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_write_node(vx_core::Type_context context) {
    std::string testname = "test_write_node";
    long irefcount = vx_core::refcount;
    vx_test::Type_testpackagelist testpackagelist = sample_testpackagelist(context);
    vx_core::Type_string string_node = vx_core::f_string_from_any(testpackagelist);
    vx_data_file::Type_file file = vx_test::f_file_testnode();
    vx_core::Type_boolean boolean_write = vx_data_file::vx_boolean_write_from_file_string(file, string_node);
    std::string expected = "true";
    std::string actual = vx_core::vx_string_from_any(boolean_write);
    vx_core::vx_release(boolean_write);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_write_html(vx_core::Type_context context) {
    std::string testname = "test_write_html";
    long irefcount = vx_core::refcount;
    vx_test::Type_testpackagelist testpackagelist = sample_testpackagelist(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 13);
    vx_web_html::Type_div divtest = vx_test::f_div_from_testpackagelist(testpackagelist);
    vx_web_html::Type_html html = vx_test::f_html_from_divtest(divtest);
    vx_core::Type_string string_html = vx_web_html::f_string_from_html(html);
    vx_data_file::Type_file file_html = vx_test::f_file_testhtml();
    vx_core::Type_boolean boolean_write = vx_data_file::vx_boolean_write_from_file_string(file_html, string_html);
    std::string expected = "true";
    std::string actual = vx_core::vx_string_from_any(boolean_write);
    vx_core::vx_release(boolean_write);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_write_testpackagelist(vx_core::Type_context context) {
    std::string testname = "test_write_testpackagelist";
    long irefcount = vx_core::refcount;
    vx_test::Type_testpackagelist testpackagelist = sample_testpackagelist(context);
    vx_core::Type_string string_vxlsp = vx_core::f_string_from_any(testpackagelist);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 1);
    vx_data_file::Type_file file = vx_test::f_file_test();
    vx_core::Type_boolean boolean_write = vx_data_file::vx_boolean_write_from_file_string(file, string_vxlsp);
    std::string expected = "true";
    std::string actual = vx_core::vx_string_from_any(boolean_write);
    bool output = test_lib::test(testname, expected, actual);
    vx_core::vx_release(boolean_write);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_write_testpackagelist_async(vx_core::Type_context context) {
    std::string testname = "test_write_testpackagelist_async";
    long irefcount = vx_core::refcount;
    vx_test::Type_testpackagelist testpackagelist = sample_testpackagelist(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 13);
    vx_test::Type_testpackagelist testpackagelist_resolved = test_lib::run_testpackagelist_async(testpackagelist);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 13);
    std::string snode = vx_core::vx_string_from_any(testpackagelist_resolved);
    vx_core::Type_string string_node = vx_core::vx_new_string(snode);
    vx_data_file::Type_file file_node = vx_test::f_file_testnode();
    vx_core::Type_boolean boolean_writenode = vx_data_file::vx_boolean_write_from_file_string(file_node, string_node);
    std::string expected = vx_core::vx_string_from_any(boolean_writenode);
    std::string actual = "true";
    bool output = test_lib::test(testname + "-1", expected, actual);
    vx_data_file::Type_file file_html = vx_test::f_file_testhtml();
    vx_web_html::Type_div divtest = vx_test::f_div_from_testpackagelist(testpackagelist_resolved);
    vx_web_html::Type_html html = vx_test::f_html_from_divtest(divtest);
    vx_core::Type_string string_html = vx_web_html::f_string_from_html(html);
    vx_core::Type_boolean boolean_writehtml = vx_data_file::vx_boolean_write_from_file_string(file_html, string_html);
    std::string expected1 = vx_core::vx_string_from_any(boolean_writehtml);
    std::string actual1 = "true";
    output = output && test_lib::test(testname + "-2", expected1, actual1);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

}
