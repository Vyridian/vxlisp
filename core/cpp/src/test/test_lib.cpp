#include "../main/vx/core.hpp"
#include "../main/vx/test.hpp"
#include "../main/vx/data/file.hpp"

namespace test_lib {

	vx_test::Type_testresult run_testresult(std::string testpkg, std::string testname, std::string message, vx_test::Type_testresult testresult) {
    vx_core::Type_any valexpected = testresult->expected();
    vx_core::Type_any valactual = testresult->actual();
    bool passfail = testresult->passfail()->vx_boolean();
    std::string code = testresult->code()->vx_string();
    std::string expected = vx_core::vx_string_from_any(valexpected);
    std::string actual = vx_core::vx_string_from_any(valactual);
    std::string msg = testpkg + "/" + testname + " " + message;
    if (!passfail) {
      vx_core::f_log(testresult);
    }
    return testresult;
  }

  // Blocking
  vx_test::Type_testresult run_testresult_async(std::string testpkg, std::string testname, std::string message, vx_test::Type_testresult testresult) {
    vx_core::vx_Type_async async_testresult = vx_test::f_resolve_testresult(testresult);
    vx_test::Type_testresult testresult_resolved = vx_core::vx_sync_from_async(vx_test::t_testresult(), async_testresult);
    vx_test::Type_testresult output = test_lib::run_testresult(testpkg, testname, message, testresult_resolved);
		return output;
  }

  vx_test::Type_testdescribe run_testdescribe(std::string testpkg, std::string casename, vx_test::Type_testdescribe testdescribe) {
    vx_core::Type_string testcode = testdescribe->describename();
    std::string message = testcode->vx_string();
    vx_test::Type_testresult testresult = testdescribe->testresult();
    vx_test::Type_testresult testresultresolved = test_lib::run_testresult(testpkg, casename, message, testresult);
    vx_test::Type_testdescribe output = vx_core::vx_copy(testdescribe, {vx_core::vx_new_string(":testresult"), testresultresolved});
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
    vx_core::vx_release_except(testdescribelist, output);
    return output;
  }

	vx_test::Type_testcase run_testcase(vx_test::Type_testcase testcase) {
    std::string testpkg = testcase->testpkg()->vx_string();
    std::string casename = testcase->casename()->vx_string();
    vx_test::Type_testdescribelist testdescribelist = testcase->describelist();
    vx_test::Type_testdescribelist testdescribelist_resolved = test_lib::run_testdescribelist(testpkg, casename, testdescribelist);
		vx_test::Type_testcase output = vx_core::vx_copy(testcase, {vx_core::vx_new_string(":describelist"), testdescribelist_resolved});
		return output;
  }

  // Blocking
  // Only use if running a single testcase
  vx_test::Type_testcase run_testcase_async(vx_test::Type_testcase testcase) {
    vx_core::vx_Type_async async_testcase = vx_test::f_resolve_testcase(testcase);
    vx_test::Type_testcase testcase_resolved = vx_core::vx_sync_from_async(vx_test::t_testcase(), async_testcase);
    vx_test::Type_testcase output = test_lib::run_testcase(testcase_resolved);
    vx_core::vx_release_except(testcase_resolved, output);
		return output;
  }

	vx_test::Type_testcaselist run_testcaselist(vx_test::Type_testcaselist testcaselist) {
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
    vx_core::vx_release_except(testcaselist, output);
    return output;
  }

  vx_test::Type_testpackage run_testpackage(vx_test::Type_testpackage testpackage) {
    vx_test::Type_testcaselist testcaselist = testpackage->caselist();
    vx_test::Type_testcaselist testcaselist_resolved = test_lib::run_testcaselist(testcaselist);
		vx_test::Type_testpackage output = vx_core::vx_copy(testpackage, {vx_core::vx_new_string(":caselist"), testcaselist_resolved});
    vx_core::vx_release_except(testpackage, output);
		return output;
  }

  vx_test::Type_testpackagelist run_testpackagelist(vx_test::Type_testpackagelist testpackagelist) {
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
    vx_core::vx_release_except(testpackagelist, output);
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

  // Blocking
  // This is the preferred way of calling testsuite (1 block per testsuite)
  vx_test::Type_testpackagelist run_testpackagelist_async(vx_test::Type_testpackagelist testpackagelist) {
    vx_core::vx_Type_async async_testpackagelist = vx_test::f_resolve_testpackagelist(testpackagelist);
    vx_test::Type_testpackagelist testpackagelist_resolved = vx_core::vx_sync_from_async(vx_test::t_testpackagelist(), async_testpackagelist);
    vx_test::Type_testpackagelist output = test_lib::run_testpackagelist(testpackagelist_resolved);
		return output;
  }

  // Blocking
  // This is the preferred way of writing testsuite (1 block per testsuite)
  vx_core::Type_boolean write_testpackagelist_async(vx_test::Type_testpackagelist testpackagelist, vx_core::Type_context context) {
    vx_core::vx_Type_async async_testpackagelist = vx_test::f_resolve_testpackagelist(testpackagelist);
    vx_test::Type_testpackagelist testpackagelist_resolved = vx_core::vx_sync_from_async(vx_test::t_testpackagelist(), async_testpackagelist);
    vx_core::vx_reserve(testpackagelist_resolved);
    vx_data_file::Type_file filetest = vx_test::f_file_test();
    vx_core::Type_boolean booleanwritetest = vx_data_file::f_boolean_write_from_file_any(filetest, testpackagelist_resolved, context);
    vx_web_html::Type_div divtest = vx_test::f_div_from_testpackagelist(testpackagelist_resolved);
    vx_web_html::Type_html htmlnode = vx_test::f_html_from_divtest(divtest);
    vx_core::vx_reserve(htmlnode);
    vx_core::Type_string shtml = vx_web_html::f_string_from_html(htmlnode);
    vx_data_file::Type_file filenode = vx_test::f_file_testnode();
    vx_core::Type_boolean booleanwritenode = vx_data_file::f_boolean_write_from_file_any(filenode, htmlnode, context);
    vx_core::vx_release(htmlnode);
    vx_data_file::Type_file filehtml = vx_test::f_file_testhtml();
    vx_core::Type_boolean booleanwritehtml = vx_data_file::f_boolean_write_from_file_string(filehtml, shtml, context);
    vx_core::Type_boolean output = vx_core::vx_new(vx_core::t_boolean(), {booleanwritetest, booleanwritenode, booleanwritehtml});
    vx_core::vx_release_except(testpackagelist_resolved, output);
    return output;
  }

	bool test(std::string testname, std::string expected, std::string actual) {
    bool output = false;
    if (expected == actual) {
      vx_core::vx_debug("Test Pass: " + testname);
      output = true;
    } else {
      vx_core::vx_debug("Test Fail: " + testname);
      vx_core::vx_debug("Expected : " + expected);
      vx_core::vx_debug("Actual   : " + actual);
    }
    return output;
  }

  bool test_helloworld() {
    std::string testname = "helloworld";
    long irefcount = vx_core::refcount;
    vx_core::Type_string helloworld = vx_core::vx_new_string("Hello World");
    std::string expected = "Hello World";
    std::string actual = helloworld->vx_string();
    bool output = test(testname, expected, actual);
    vx_core::vx_release(helloworld);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_async_new_from_value() {
    std::string testname = "async_new_from_value";
    long irefcount = vx_core::refcount;
    vx_core::Type_string helloworld = vx_core::vx_new_string("Hello World");
    vx_core::vx_Type_async async = vx_core::vx_async_new_from_value(helloworld);
    vx_core::Type_string sync = vx_core::vx_sync_from_async(vx_core::t_string(), async);
    std::string expected = "Hello World";
    std::string actual = sync->vx_string();
    vx_core::vx_release(sync);
    bool output = test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_async_from_async_fn() {
    std::string testname = "async_from_async_fn";
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
    bool output = test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testresult(vx_core::Type_context context) {
    std::string testname = "run_testresult";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = vx_test::f_test_true(
      vx_core::vx_new_boolean(true),
      context
    );
    vx_test::Type_testresult testresult_resolved = run_testresult("vx/core", "boolean", "", testresult);
    std::string expected =
      "(vx/test/testresult"
      "\n :actual true"
      "\n :code \":true\""
      "\n :expected true"
      "\n :passfail true)";
    std::string actual = vx_core::vx_string_from_any(testresult_resolved);
    vx_core::vx_release(testresult_resolved);
    bool output = test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_resolve_testresult_anyfromfunc(vx_core::Type_context context) {
    std::string testname = "resolve_testresult_anyfromfunc";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = vx_test::f_test_true(
      vx_core::vx_new_boolean(true),
      context
    );
    vx_core::Func_any_from_func_async fn_actual = testresult->fn_actual();
    vx_core::Type_any expected = testresult->expected();
    vx_core::Type_any actual = testresult->actual();
    vx_core::Func_any_from_func anyfromfunc = vx_core::t_any_from_func()->vx_fn_new({testresult}, [testresult]() {
      vx_core::Type_any output_1 = testresult;
      return output_1;
    });
    std::string expected1 =
      "(vx/test/testresult"
      "\n :actual true"
      "\n :code \":true\""
      "\n :expected true"
      "\n :passfail true)";
    std::string actual1 = vx_core::vx_string_from_any(testresult);
    vx_core::vx_release(anyfromfunc);
    bool output = test(testname, expected1, actual1);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_resolve_testresult_then(vx_core::Type_context context) {
    std::string testname = "resolve_testresult_then";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = vx_test::f_test_true(
      vx_core::vx_new_boolean(true),
      context
    );
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
    std::string expected1 =
      "(vx/test/testresult"
      "\n :actual true"
      "\n :code \":true\""
      "\n :expected true"
      "\n :passfail true)";
    std::string actual1 = vx_core::vx_string_from_any(testresult);
    vx_core::vx_release(thenelse);
    bool output = test(testname, expected1, actual1);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_resolve_testresult_thenelselist(vx_core::Type_context context) {
    std::string testname = "resolve_testresult_thenelselist";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = vx_test::f_test_true(
      vx_core::vx_new_boolean(true),
      context
    );
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
              vx_test::Type_testresult output_1 = vx_core::f_copy(
                testresult,
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_string(":passfail"),
                  passfail,
                  vx_core::vx_new_string(":actual"),
                  actual
                })
              );
              vx_core::vx_release(passfail);
              return output_1;
            })
          );
          return output_1;
        })
      )
    });
    std::string expected1 =
      "(vx/test/testresult"
      "\n :actual true"
      "\n :code \":true\""
      "\n :expected true"
      "\n :passfail true)";
    std::string actual1 = vx_core::vx_string_from_any(testresult);
    vx_core::vx_release(thenelselist);
    bool output = test(testname, expected1, actual1);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_resolve_testresult_if(vx_core::Type_context context) {
    std::string testname = "resolve_testresult_if";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = vx_test::f_test_true(
      vx_core::vx_new_boolean(true),
      context
    );
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
                vx_test::Type_testresult output_1 = vx_core::f_copy(
                  testresult,
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":passfail"),
                    passfail,
                    vx_core::vx_new_string(":actual"),
                    actual
                  })
                );
                vx_core::vx_release(passfail);
                return output_1;
              })
            );
            return output_1;
          })
        )
      })
    );
    std::string expected1 =
      "(vx/test/testresult"
      "\n :actual true"
      "\n :code \":true\""
      "\n :expected true"
      "\n :passfail true)";
    std::string actual1 = vx_core::vx_string_from_any(output_2);
    vx_core::vx_release(output_2);
    bool output = test(testname, expected1, actual1);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testresult_async(vx_core::Type_context context) {
    std::string testname = "run_testresult_async";
    long irefcount = vx_core::refcount;
    vx_test::Type_testresult testresult = vx_test::f_test_true(
      vx_core::vx_new_boolean(true),
      context
    );
    vx_test::Type_testresult testresult_resolved = run_testresult_async("vx/core", "boolean", "", testresult);
    std::string expected =
      "(vx/test/testresult"
      "\n :actual true"
      "\n :code \":true\""
      "\n :expected true"
      "\n :passfail true)";
    std::string actual = vx_core::vx_string_from_any(testresult_resolved);
    vx_core::vx_release(testresult_resolved);
    bool output = test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testdescribe(vx_core::Type_context context) {
    std::string testname = "run_testdescribe";
    long irefcount = vx_core::refcount;
    vx_test::Type_testdescribe testdescribe = vx_core::vx_new(vx_test::t_testdescribe(), {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true true)"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":testresult"),
      vx_test::f_test_true(
        vx_core::vx_new_boolean(true),
        context
      )
    });
    vx_test::Type_testdescribe testdescribe_resolved = run_testdescribe("vx/core", "boolean", testdescribe);
    std::string expected =
      "(vx/test/testdescribe"
      "\n :describename \"(test-true true)\""
      "\n :testpkg \"vx/core\""
      "\n :testresult"
      "\n  (vx/test/testresult"
      "\n   :actual true"
      "\n   :code \":true\""
      "\n   :expected true"
      "\n   :passfail true))";
    std::string actual = vx_core::vx_string_from_any(testdescribe_resolved);
    vx_core::vx_release(testdescribe_resolved);
    bool output = test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

  bool test_run_testdescribe_async(vx_core::Type_context context) {
    std::string testname = "run_testdescribe_async";
    long irefcount = vx_core::refcount;
    vx_test::Type_testdescribe testdescribe = vx_core::vx_new(vx_test::t_testdescribe(), {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true true)"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":testresult"),
      vx_test::f_test_true(
        vx_core::vx_new_boolean(true),
        context
      )
    });
    vx_test::Type_testdescribe testdescribe_resolved = run_testdescribe_async("vx/core", "boolean", testdescribe);
    std::string expected =
      "(vx/test/testdescribe"
      "\n :describename \"(test-true true)\""
      "\n :testpkg \"vx/core\""
      "\n :testresult"
      "\n  (vx/test/testresult"
      "\n   :actual true"
      "\n   :code \":true\""
      "\n   :expected true"
      "\n   :passfail true))";
    std::string actual = vx_core::vx_string_from_any(testdescribe_resolved);
    vx_core::vx_release(testdescribe_resolved);
    bool output = test(testname, expected, actual);
    output = output && vx_core::vx_memory_leak_test(testname, irefcount);
    return output;
  }

}
