#include "../main/vx/core.hpp"
#include "../main/vx/test.hpp"
#include "../main/vx/data/file.hpp"
#include "../main/vx/web/html.hpp"

namespace test_lib {

  std::string read_test_file(std::string path, std::string filename) {
    vx_data_file::Type_file file = vx_core::vx_new(vx_data_file::t_file, {
      vx_core::vx_new_string(":path"), vx_core::vx_new_string(path),
      vx_core::vx_new_string(":name"), vx_core::vx_new_string(filename)
    });
    vx_core::Type_string string_file = vx_data_file::vx_string_read_from_file(file);
    std::string output = string_file->vx_string();
    vx_core::vx_release(string_file);
    return output;
  }

  vx_test::Type_testresult sample_testresult1(vx_core::Type_context context) {
    vx_test::Type_testresult output;
    long irefcount = vx_core::refcount;
    output = vx_test::f_test_true(
					 context,
      vx_core::vx_new_boolean(true)
    );
    vx_core::vx_memory_leak_test("sample_testresult1", irefcount, 2);
    return output;
  }

  vx_test::Type_testresult sample_testresult2(vx_core::Type_context context) {
    vx_test::Type_testresult output;
    long irefcount = vx_core::refcount;
    output = vx_test::f_test_false(
					 context,
      vx_core::vx_new_boolean(false)
    );
    vx_core::vx_memory_leak_test("sample_testresult2", irefcount, 2);
    return output;
  }

  vx_test::Type_testdescribe sample_testdescribe1(vx_core::Type_context context) {
    vx_test::Type_testdescribe output;
    long irefcount = vx_core::refcount;
    output = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true true)"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":testresult"),
      sample_testresult1(context)
    });
    vx_core::vx_memory_leak_test("sample_testdescribe1", irefcount, 5);
    return output;
  }

  vx_test::Type_testdescribe sample_testdescribe2(vx_core::Type_context context) {
    vx_test::Type_testdescribe output;
    long irefcount = vx_core::refcount;
    output = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-false false)"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":testresult"),
      sample_testresult2(context)
    });
    vx_core::vx_memory_leak_test("sample_testdescribe2", irefcount, 5);
    return output;
  }

  vx_test::Type_testdescribelist sample_testdescribelist(vx_core::Type_context context) {
    vx_test::Type_testdescribelist output;
    long irefcount = vx_core::refcount;
    output = vx_core::vx_any_from_any(
      vx_test::t_testdescribelist,
      vx_test::t_testdescribelist->vx_new_from_list({
        sample_testdescribe1(context),
        sample_testdescribe2(context)
      })
    );
    vx_core::vx_memory_leak_test("sample_testdescribelist", irefcount, 11);
    return output;
  }

  vx_test::Type_testcase sample_testcase(vx_core::Type_context context) {
    vx_test::Type_testcase output;
    long irefcount = vx_core::refcount;
    output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("boolean"),
      vx_core::vx_new_string(":describelist"), sample_testdescribelist(context)
    });
    vx_core::vx_memory_leak_test("sample_testcase", irefcount, 14);
    return output;
  }

  vx_test::Type_testcase sample_testcase2(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("float"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 4.5 (float 4.5))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
 													context,
	 												vx_core::vx_new_decimal_from_string("4.5"),
              vx_core::f_new(
                vx_core::t_float,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_decimal_from_string("4.5")
                })
              )
            )
          })
        })
      )
    });
    return output;
  }

  vx_test::Type_testcaselist sample_testcaselist(vx_core::Type_context context) {
    vx_test::Type_testcaselist output;
    long irefcount = vx_core::refcount;
    output = vx_core::vx_any_from_any(
      vx_test::t_testcaselist,
      vx_test::t_testcaselist->vx_new_from_list({
        sample_testcase(context),
        sample_testcase2(context)
      })
    );
    vx_core::vx_memory_leak_test("sample_testcaselist", irefcount, 26);
    return output;
  }

  vx_test::Type_testpackage sample_testpackage(vx_core::Type_context context) {
    vx_test::Type_testpackage output;
    long irefcount = vx_core::refcount;
    output = vx_core::vx_new(vx_test::t_testpackage, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":caselist"), sample_testcaselist(context)
    });
    vx_core::vx_memory_leak_test("sample_testpackage", irefcount, 28);
    return output;
  }

  vx_test::Type_testpackagelist sample_testpackagelist(vx_core::Type_context context) {
    vx_test::Type_testpackagelist output;
    long irefcount = vx_core::refcount;
    output = vx_core::vx_any_from_any(
      vx_test::t_testpackagelist,
      vx_test::t_testpackagelist->vx_new_from_list({
        sample_testpackage(context)
      })
    );
    vx_core::vx_memory_leak_test("sample_testpackagelist", irefcount, 29);
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
      vx_core::vx_log("--Test Result Fail-- " + msg);
      vx_core::vx_log("---Expected---\n" + expected);
      vx_core::vx_log("---Actual---\n" + actual);
      //vx_core::vx_log(testresult);
    }
    return testresult;
  }

  // Blocking
  vx_test::Type_testresult run_testresult_async(std::string testpkg, std::string testname, std::string message, vx_test::Type_testresult testresult) {
    vx_core::vx_Type_async async_testresult = vx_test::f_resolve_testresult(testresult);
    vx_test::Type_testresult testresult_resolved = vx_core::vx_sync_from_async(vx_test::t_testresult, async_testresult);
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
    vx_test::Type_testdescribe testdescribe_resolved = vx_core::vx_sync_from_async(vx_test::t_testdescribe, async_testdescribe);
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
      vx_test::t_testdescribelist,
      testdescribelist->vx_new_from_list(listtestdescribe_resolved)
    );
    vx_core::vx_release_one_except(testdescribelist, output);
    return output;
  }

  // Blocking
  // Only use if running a single testdescribelist
  vx_test::Type_testdescribelist run_testdescribelist_async(std::string testpkg, std::string casename, vx_test::Type_testdescribelist testdescribelist) {
    vx_core::vx_Type_async async_testdescribelist = vx_test::f_resolve_testdescribelist(testdescribelist);
    vx_test::Type_testdescribelist testdescribelist_resolved = vx_core::vx_sync_from_async(vx_test::t_testdescribelist, async_testdescribelist);
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
    vx_test::Type_testcase testcase_resolved = vx_core::vx_sync_from_async(vx_test::t_testcase, async_testcase);
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
      vx_test::t_testcaselist,
      testcaselist->vx_new_from_list(listtestcase_resolved)
    );
    vx_core::vx_release_one_except(testcaselist, output);
    return output;
  }

  // Blocking
  // Only use if running a single testcaselist
  vx_test::Type_testcaselist run_testcaselist_async(vx_test::Type_testcaselist testcaselist) {
    vx_core::vx_Type_async async_testcaselist = vx_test::f_resolve_testcaselist(testcaselist);
    vx_test::Type_testcaselist testcaselist_resolved = vx_core::vx_sync_from_async(vx_test::t_testcaselist, async_testcaselist);
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
    vx_test::Type_testpackage testpackage_resolved = vx_core::vx_sync_from_async(vx_test::t_testpackage, async_testpackage);
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
      vx_test::t_testpackagelist,
      testpackagelist->vx_new_from_list(listtestpackage_resolved)
    );
    vx_core::vx_release_one_except(testpackagelist, output);
    return output;
  }

  // Blocking
  // This is the preferred way of calling testsuite (1 block per testsuite)
  vx_test::Type_testpackagelist run_testpackagelist_async(vx_test::Type_testpackagelist testpackagelist) {
    vx_core::vx_Type_async async_testpackagelist = vx_test::f_resolve_testpackagelist(testpackagelist);
    vx_test::Type_testpackagelist testpackagelist_resolved = vx_core::vx_sync_from_async(vx_test::t_testpackagelist, async_testpackagelist);
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

  vx_core::Type_boolean write_testpackagelist(vx_core::Type_context context, vx_test::Type_testpackagelist testpackagelist) {
    vx_core::Type_string string_node = vx_core::f_string_from_any(testpackagelist);
    vx_data_file::Type_file file = vx_test::f_file_test();
    vx_core::Type_boolean output = vx_data_file::vx_boolean_write_from_file_string(file, string_node);
    return output;
  }

  // Blocking
  // This is the preferred way of writing testsuite (1 block per testsuite)
  vx_core::Type_boolean write_testpackagelist_async(vx_core::Type_context context, vx_test::Type_testpackagelist testpackagelist) {
    vx_test::Type_testpackagelist testpackagelist_resolved = test_lib::run_testpackagelist_async(testpackagelist);
    vx_core::vx_reserve(testpackagelist_resolved);
    vx_core::Type_boolean write_testpackagelist = test_lib::write_testpackagelist(context, testpackagelist_resolved);
    vx_web_html::Type_div divtest = vx_test::f_div_from_testpackagelist(testpackagelist_resolved);
    vx_core::vx_release_one(testpackagelist_resolved);
    vx_web_html::Type_html htmlnode = vx_test::f_html_from_divtest(divtest);
    vx_core::vx_reserve(htmlnode);
    vx_core::Type_boolean write_node = test_lib::write_node(htmlnode);
    vx_core::Type_boolean write_html = test_lib::write_html(htmlnode);
    vx_core::vx_release_one(htmlnode);
    vx_core::Type_boolean output = vx_core::vx_new(vx_core::t_boolean, {
      write_testpackagelist,
      write_node,
      write_html
    });
    return output;
  }

  bool test(std::string testname, std::string expected, std::string actual) {
    bool output = false;
    if (expected == actual) {
      vx_core::vx_log("Test Pass: " + testname);
      output = true;
    } else {
      vx_core::vx_log("Test Fail: " + testname);
      vx_core::vx_log("Expected:\n" + expected);
      vx_core::vx_log("Actual:\n" + actual);
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
    vx_core::Type_string sync = vx_core::vx_sync_from_async(vx_core::t_string, async);
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
      vx_core::t_string,
      {},
      [](vx_core::Type_any any) {
        return any;
      }
    );
    vx_core::Type_string sync = vx_core::vx_sync_from_async(vx_core::t_string, async1);
    std::string expected = "Hello World";
    std::string actual = sync->vx_string();
    vx_core::vx_release(sync);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_div_from_testcaselist(vx_core::Type_context context) {
    std::string testname = "test_div_from_testcaselist";
    long irefcount = vx_core::refcount;
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    vx_test::Type_testcaselist testcaselist = sample_testcaselist(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 26);
    vx_web_html::Type_div div = vx_test::f_div_from_testcaselist(testcaselist);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 94);
    std::string actual = vx_core::vx_string_from_any(div);
    vx_core::vx_release(div);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_div_from_testpackage(vx_core::Type_context context) {
    std::string testname = "test_div_from_testpackage";
    long irefcount = vx_core::refcount;
    vx_test::Type_testpackage testpackage = sample_testpackage(context);
    vx_web_html::Type_div div = vx_test::f_div_from_testpackage(testpackage);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(div);
    vx_core::vx_release(div);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_div_from_testpackagelist(vx_core::Type_context context) {
    std::string testname = "test_div_from_testpackagelist";
    long irefcount = vx_core::refcount;
    vx_test::Type_testpackagelist testpackagelist = sample_testpackagelist(context);
    vx_web_html::Type_div div = vx_test::f_div_from_testpackagelist(testpackagelist);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(div);
    vx_core::vx_release(div);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_html_from_testpackagelist(vx_core::Type_context context) {
    std::string testname = "test_html_from_testpackagelist";
    long irefcount = vx_core::refcount;
    std::string expected = read_test_file("src/test/resources/vx", testname + ".html");
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
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    vx_test::Type_testcaselist testcaselist = sample_testcaselist(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 26);
    vx_web_html::Type_div div = vx_test::f_div_from_testcaselist(testcaselist);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 94);
    vx_web_html::Type_html html = vx_test::f_html_from_divtest(div);
    std::string actual = vx_core::vx_string_from_any(html);
    vx_core::vx_release(html);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_all(vx_core::Type_context context, vx_test::Type_testpackagelist testpackagelist) {
    vx_core::Type_boolean issuccess = test_lib::write_testpackagelist_async(context, testpackagelist);
    std::string expected = "true";
    std::string actual = vx_core::vx_string_from_any(issuccess);
    vx_core::vx_release(issuccess);
    bool output = test_lib::test("Full Test Suite", expected, actual);
    return output;
  }

  bool test_run_testcase(vx_core::Type_context context) {
    std::string testname = "test_run_testcase";
    long irefcount = vx_core::refcount;
    vx_test::Type_testcase testcase = sample_testcase(context);
    vx_test::Type_testcase testcase_resolved = test_lib::run_testcase(testcase);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
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
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 14);
    vx_test::Type_testcase testcase_resolved = test_lib::run_testcase_async(testcase);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 14);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
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
    vx_core::vx_memory_leak_test(testname, irefcount, 22);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
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
    vx_core::vx_memory_leak_test(testname, irefcount, 14);
    vx_core::vx_Type_async async_testcase = vx_test::f_resolve_testcase(testcase);
    vx_core::vx_memory_leak_test(testname, irefcount, 22);
    vx_core::vx_Type_async async_testdescribelist = async_testcase->async_parent;
    vx_core::vx_Type_listasync list_async_testdescribe = async_testdescribelist->listasync;
    vx_core::vx_Type_async async_testdescribe = list_async_testdescribe[0];
    vx_core::vx_Type_async async_testresult = async_testdescribe->async_parent;
    vx_core::vx_Type_async async_any = async_testresult->async_parent;
    vx_core::Type_any any = async_any->sync_value();
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 22);
    vx_core::Type_any testresult_resolved = async_testresult->sync_value();
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 21);
    vx_core::Type_any testdescribe_resolved = async_testdescribe->sync_value();
    vx_core::vx_memory_leak_test(testname + "-3", irefcount, 20);
    vx_core::Type_any testdescribelist_resolved = async_testdescribelist->sync_value();
    vx_core::vx_memory_leak_test(testname + "-4", irefcount, 17);
    vx_core::Type_any testcase_resolved = async_testcase->sync_value();
    vx_core::vx_memory_leak_test(testname + "-5", irefcount, 15);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
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
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
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
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 26);
    vx_test::Type_testcaselist testcaselist_resolved = test_lib::run_testcaselist_async(testcaselist);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 26);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(testcaselist_resolved);
    vx_core::vx_release(testcaselist_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testdescribe(vx_core::Type_context context) {
    std::string testname = "test_run_testdescribe";
    long irefcount = vx_core::refcount;
    vx_test::Type_testdescribe testdescribe = sample_testdescribe1(context);
    vx_test::Type_testdescribe testdescribe_resolved = test_lib::run_testdescribe("vx/core", "boolean", testdescribe);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(testdescribe_resolved);
    vx_core::vx_release(testdescribe_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testdescribe_async(vx_core::Type_context context) {
    std::string testname = "test_run_testdescribe_async";
    long irefcount = vx_core::refcount;
    vx_test::Type_testdescribe testdescribe = sample_testdescribe1(context);
    vx_test::Type_testdescribe testdescribe_resolved = test_lib::run_testdescribe_async("vx/core", "boolean", testdescribe);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
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
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
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
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
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
      vx_test::t_testdescribelist,
      testdescribelist,
      vx_test::t_resolve_testdescribe
    );
    vx_test::Type_testdescribelist testdescribelist_resolved = vx_core::vx_sync_from_async(vx_test::t_testdescribelist, async_testdescribelist);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
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
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
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
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 28);
    vx_test::Type_testpackage testpackage_resolved = test_lib::run_testpackage_async(testpackage);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 28);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
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
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
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
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 29);
    vx_test::Type_testpackagelist testpackagelist_resolved = test_lib::run_testpackagelist_async(testpackagelist);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 29);
    std::string actual = vx_core::vx_string_from_any(testpackagelist_resolved);
    vx_core::vx_release(testpackagelist_resolved);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testresult(vx_core::Type_context context) {
    std::string testname = "test_run_testresult";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = sample_testresult1(context);
    vx_test::Type_testresult testresult_resolved = run_testresult("vx/core", "boolean", "", testresult);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(testresult_resolved);
    vx_core::vx_release(testresult_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_resolve_testresult_anyfromfunc(vx_core::Type_context context) {
    std::string testname = "test_resolve_testresult_anyfromfunc";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = sample_testresult1(context);
    vx_core::Func_any_from_func_async fn_actual = testresult->fn_actual();
    vx_core::Type_any expected = testresult->expected();
    vx_core::Type_any actual = testresult->actual();
    vx_core::Func_any_from_func anyfromfunc = vx_core::t_any_from_func->vx_fn_new({testresult}, [testresult]() {
      vx_core::Type_any output_1 = testresult;
      return output_1;
    });
    std::string expected1 = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual1 = vx_core::vx_string_from_any(testresult);
    vx_core::vx_release(anyfromfunc);
    bool output = test_lib::test(testname, expected1, actual1);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testresult_async(vx_core::Type_context context) {
    std::string testname = "test_run_testresult_async";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = sample_testresult1(context);
    vx_test::Type_testresult testresult_resolved = test_lib::run_testresult_async("vx/core", "boolean", "", testresult);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(testresult_resolved);
    vx_core::vx_release(testresult_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_resolve_testresult_f_resolve_testresult(vx_core::Type_context context) {
    std::string testname = "test_resolve_testresult_f_resolve_testresult";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = sample_testresult1(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 2);
    vx_core::vx_Type_async async_testresult = vx_test::f_resolve_testresult(testresult);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 4);
    vx_test::Type_testresult testresult_resolved = vx_core::vx_sync_from_async(vx_test::t_testresult, async_testresult);
    vx_core::vx_memory_leak_test(testname + "-3", irefcount, 2);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(testresult_resolved);
    vx_core::vx_release(testresult_resolved);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_resolve_testresult_f_resolve_testresult_async(vx_core::Type_context context) {
    std::string testname = "test_resolve_testresult_f_resolve_testresult_async";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = sample_testresult1(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 2);
    vx_core::vx_Type_async async_testresult = vx_test::f_resolve_testresult(testresult);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 4);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_async(async_testresult);
    vx_core::vx_release_async(async_testresult);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_resolve_testresult_if(vx_core::Type_context context) {
    std::string testname = "test_resolve_testresult_if";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = sample_testresult1(context);
    vx_core::Func_any_from_func_async fn_actual = testresult->fn_actual();
    vx_core::Type_any expected = testresult->expected();
    vx_core::Type_any actual = testresult->actual();
    vx_core::Type_any output_2 = vx_core::f_if_2(
      vx_test::t_testresult,
      vx_core::vx_new(vx_core::t_thenelselist, {
        vx_core::f_then(
          vx_core::t_boolean_from_func->vx_fn_new({fn_actual}, [fn_actual]() {
            vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(fn_actual);
            return output_1;
          }),
          vx_core::t_any_from_func->vx_fn_new({testresult}, [testresult]() {
            vx_core::Type_any output_1 = testresult;
            return output_1;
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func->vx_fn_new({expected, actual, testresult}, [expected, actual, testresult]() {
            vx_test::Type_testresult output_1 = vx_core::f_let(
              vx_test::t_testresult,
              vx_core::t_any_from_func->vx_fn_new({expected, actual, testresult}, [expected, actual, testresult]() {
                vx_core::Type_boolean passfail = vx_core::f_eq(expected, actual);
                vx_core::vx_ref_plus(passfail);
                vx_test::Type_testresult output_1 = vx_core::f_copy(
                  vx_test::t_testresult,
                  testresult,
                  vx_core::vx_new(vx_core::t_anylist, {
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
    std::string expected1 = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual1 = vx_core::vx_string_from_any(output_2);
    vx_core::vx_release(output_2);
    bool output = test_lib::test(testname, expected1, actual1);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_resolve_testresult_then(vx_core::Type_context context) {
    std::string testname = "test_resolve_testresult_then";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = sample_testresult1(context);
    vx_core::Func_any_from_func_async fn_actual = testresult->fn_actual();
    vx_core::Type_any expected = testresult->expected();
    vx_core::Type_any actual = testresult->actual();
    vx_core::Type_thenelse thenelse = vx_core::f_then(
      vx_core::t_boolean_from_func->vx_fn_new({fn_actual}, [fn_actual]() {
        vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(fn_actual);
        return output_1;
      }),
      vx_core::t_any_from_func->vx_fn_new({testresult}, [testresult]() {
        vx_core::Type_any output_1 = testresult;
        return output_1;
      })
    );
    std::string expected1 = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual1 = vx_core::vx_string_from_any(testresult);
    vx_core::vx_release(thenelse);
    bool output = test_lib::test(testname, expected1, actual1);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_resolve_testresult_thenelselist(vx_core::Type_context context) {
    std::string testname = "test_resolve_testresult_thenelselist";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = sample_testresult1(context);
    vx_core::Func_any_from_func_async fn_actual = testresult->fn_actual();
    vx_core::Type_any expected = testresult->expected();
    vx_core::Type_any actual = testresult->actual();
    vx_core::Type_thenelselist thenelselist = vx_core::vx_new(vx_core::t_thenelselist, {
      vx_core::f_then(
        vx_core::t_boolean_from_func->vx_fn_new({fn_actual}, [fn_actual]() {
          vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(fn_actual);
          return output_1;
        }),
        vx_core::t_any_from_func->vx_fn_new({testresult}, [testresult]() {
          vx_core::Type_any output_1 = testresult;
          return output_1;
        })
      ),
      vx_core::f_else(
        vx_core::t_any_from_func->vx_fn_new({expected, actual, testresult}, [expected, actual, testresult]() {
          vx_test::Type_testresult output_1 = vx_core::f_let(
            vx_test::t_testresult,
            vx_core::t_any_from_func->vx_fn_new({expected, actual, testresult}, [expected, actual, testresult]() {
              vx_core::Type_boolean passfail = vx_core::f_eq(expected, actual);
              vx_core::vx_ref_plus(passfail);
              vx_test::Type_testresult output_1 = vx_core::f_copy(
                vx_test::t_testresult,
                testresult,
                vx_core::vx_new(vx_core::t_anylist, {
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
    std::string expected1 = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual1 = vx_core::vx_string_from_any(testresult);
    vx_core::vx_release(thenelselist);
    bool output = test_lib::test(testname, expected1, actual1);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_pathfull_from_file(vx_core::Type_context context) {
    std::string testname = "test_pathfull_from_file";
    long irefcount = vx_core::refcount;
    vx_data_file::Type_file file = vx_core::vx_new(vx_data_file::t_file, {
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
    std::string expected = "testdata";
    std::string actual = read_test_file("src/test/resources/vx", "string_read_from_file.txt");
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_tr_from_testdescribe_casename(vx_core::Type_context context) {
    std::string testname = "test_tr_from_testdescribe_casename";
    long irefcount = vx_core::refcount;
    vx_core::Type_string casename = vx_core::vx_new_string("vx/core/boolean");
    vx_test::Type_testdescribe testdescribe = sample_testdescribe1(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 6);
    vx_web_html::Type_tr tr = vx_test::f_tr_from_testdescribe_casename(testdescribe, casename);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 22);
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    std::string actual = vx_core::vx_string_from_any(tr);
    vx_core::vx_release(tr);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_trlist_from_testcase(vx_core::Type_context context) {
    std::string testname = "test_trlist_from_testcase";
    long irefcount = vx_core::refcount;
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    vx_test::Type_testcase testcase = sample_testcase(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 14);
    vx_web_html::Type_trlist trlist = vx_test::f_trlist_from_testcase(testcase);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 44);
    std::string actual = vx_core::vx_string_from_any(trlist);
    vx_core::vx_release(trlist);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_trlist_from_testcaselist(vx_core::Type_context context) {
    std::string testname = "test_trlist_from_testcaselist";
    long irefcount = vx_core::refcount;
    std::string expected = read_test_file("src/test/resources/vx", testname + ".txt");
    vx_test::Type_testcaselist testcaselist = sample_testcaselist(context);
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 26);
    vx_web_html::Type_trlist trlist = vx_test::f_trlist_from_testcaselist(testcaselist);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 66);
    std::string actual = vx_core::vx_string_from_any(trlist);
    vx_core::vx_release(trlist);
    bool output = test_lib::test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_write_file(vx_core::Type_context context) {
    std::string testname = "test_write_file";
    long irefcount = vx_core::refcount;
    vx_data_file::Type_file file = vx_core::vx_new(vx_data_file::t_file, {
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
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 29);
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
    vx_core::vx_memory_leak_test(testname + "-1", irefcount, 29);
    vx_test::Type_testpackagelist testpackagelist_resolved = test_lib::run_testpackagelist_async(testpackagelist);
    vx_core::vx_memory_leak_test(testname + "-2", irefcount, 29);
    std::string snode = vx_core::vx_string_from_any(testpackagelist_resolved);
    vx_core::Type_string string_node = vx_core::vx_new_string(snode);
    vx_data_file::Type_file file_node = vx_test::f_file_testnode();
    vx_core::Type_boolean boolean_writenode = vx_data_file::vx_boolean_write_from_file_string(file_node, string_node);
    std::string expected = "true";
    std::string actual = vx_core::vx_string_from_any(boolean_writenode);
    bool output = test_lib::test(testname + "-1", expected, actual);
    vx_data_file::Type_file file_html = vx_test::f_file_testhtml();
    vx_web_html::Type_div divtest = vx_test::f_div_from_testpackagelist(testpackagelist_resolved);
    vx_web_html::Type_html html = vx_test::f_html_from_divtest(divtest);
    vx_core::Type_string string_html = vx_web_html::f_string_from_html(html);
    vx_core::Type_boolean boolean_writehtml = vx_data_file::vx_boolean_write_from_file_string(file_html, string_html);
    std::string expected1 = "true";
    std::string actual1 = vx_core::vx_string_from_any(boolean_writehtml);
    output = output && test_lib::test(testname + "-2", expected1, actual1);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

}
