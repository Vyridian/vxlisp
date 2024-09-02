
package com.vxlisp.vx

import com.vxlisp.vx.data.*
import com.vxlisp.vx.web.*

object vx_testTest {

  fun f_file_test(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/test",
      ":casename", "file-test",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_file_test_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_file_test_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test-true\n (boolean-exists<-file\n  (file\n   :name \"testsuite.vxlisp\"\n   :path path-test-resources)))",
      ":testresult", vx_test.f_test_true(
        context,
        vx_data_file.f_boolean_exists_from_file(
          vx_core.f_new(
            vx_data_file.t_file,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":name"),
              vx_core.vx_new_string("testsuite.vxlisp"),
              vx_core.vx_new_string(":path"),
              vx_core.c_path_test_resources
            )
          )
        )
      )
    )
    return output
  }

  fun f_file_testhtml(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/test",
      ":casename", "file-testhtml",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_file_testhtml_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_file_testhtml_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test-true\n (boolean-exists<-file\n  (file\n   :name \"testsuite.html\"\n   :path path-test-resources)))",
      ":testresult", vx_test.f_test_true(
        context,
        vx_data_file.f_boolean_exists_from_file(
          vx_core.f_new(
            vx_data_file.t_file,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":name"),
              vx_core.vx_new_string("testsuite.html"),
              vx_core.vx_new_string(":path"),
              vx_core.c_path_test_resources
            )
          )
        )
      )
    )
    return output
  }

  fun f_file_testnode(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/test",
      ":casename", "file-testnode",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_file_testnode_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_file_testnode_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test-true\n (boolean-exists<-file\n  (file\n   :name \"testsuitenode.vxlisp\"\n   :path path-test-resources)))",
      ":testresult", vx_test.f_test_true(
        context,
        vx_data_file.f_boolean_exists_from_file(
          vx_core.f_new(
            vx_data_file.t_file,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":name"),
              vx_core.vx_new_string("testsuitenode.vxlisp"),
              vx_core.vx_new_string(":path"),
              vx_core.c_path_test_resources
            )
          )
        )
      )
    )
    return output
  }

  fun test_cases(context : vx_core.Type_context) : vx_test.Type_testcaselist {
    var testcases : List<vx_core.Type_any> = vx_core.arraylist_from_array(
      vx_testTest.f_file_test(context),
      vx_testTest.f_file_testhtml(context),
      vx_testTest.f_file_testnode(context)
    )
    var output : vx_test.Type_testcaselist = vx_core.vx_new(
      vx_test.t_testcaselist,
      testcases
    )
    return output
  }

  fun test_coveragesummary() : vx_test.Type_testcoveragesummary {
    var output : vx_test.Type_testcoveragesummary = vx_core.vx_new(
      vx_test.t_testcoveragesummary,
      ":testpkg", "vx/test", 
      ":constnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 1), 
      ":docnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 93, ":tests", 43, ":total", 46), 
      ":funcnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 10, ":tests", 3, ":total", 28), 
      ":bigospacenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 34), 
      ":bigotimenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 34), 
      ":totalnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 7, ":tests", 3, ":total", 40), 
      ":typenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 11)
    )
    return output
  }

  fun test_coveragedetail() : vx_test.Type_testcoveragedetail {
    var output : vx_test.Type_testcoveragedetail = vx_core.vx_new(
      vx_test.t_testcoveragedetail,
      ":testpkg", "vx/test",
      ":typemap", vx_core.vx_new(
        vx_core.t_intmap,
        ":testcase", 0,
        ":testcaselist", 0,
        ":testcoveragedetail", 0,
        ":testcoveragenums", 0,
        ":testcoveragesummary", 0,
        ":testdescribe", 0,
        ":testdescribelist", 0,
        ":testpackage", 0,
        ":testpackagelist", 0,
        ":testresult", 0,
        ":testresultlist", 0
      ), 
      ":constmap", vx_core.vx_new(
        vx_core.t_intmap,
        ":stylesheet-test", 0
      ), 
      ":funcmap", vx_core.vx_new(
        vx_core.t_intmap,
        ":context-test", 0,
        ":div<-testcaselist", 0,
        ":div<-testpackage", 0,
        ":div<-testpackagelist", 0,
        ":divchildlist<-testpackagelist", 0,
        ":file-test", 1,
        ":file-testhtml", 1,
        ":file-testnode", 1,
        ":html<-divtest", 0,
        ":p<-passfail", 0,
        ":p<-testcoveragenums", 0,
        ":resolve-testcase", 0,
        ":resolve-testcaselist", 0,
        ":resolve-testdescribe", 0,
        ":resolve-testdescribelist", 0,
        ":resolve-testpackage", 0,
        ":resolve-testpackagelist", 0,
        ":resolve-testresult", 0,
        ":security-test", 0,
        ":test", 0,
        ":test_1", 0,
        ":test-false", 0,
        ":test-false_1", 0,
        ":test-gt", 0,
        ":test-gt_1", 0,
        ":test-ne", 0,
        ":test-ne_1", 0,
        ":test-string", 0,
        ":test-string_1", 0,
        ":test-true", 0,
        ":test-true_1", 0,
        ":tr<-testdescribe-casename", 0,
        ":trlist<-testcase", 0,
        ":trlist<-testcaselist", 0
      )
    )
    return output
  }

  fun test_package(context : vx_core.Type_context) : vx_test.Type_testpackage {
    var testcaselist : vx_test.Type_testcaselist = test_cases(context)
    var output : vx_test.Type_testpackage = vx_core.vx_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/test", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    )
    return output
  }

}
