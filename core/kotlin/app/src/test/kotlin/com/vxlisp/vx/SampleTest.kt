
package com.vxlisp.vx

object vx_sampleTest {

  fun c_myconst(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/sample",
      ":casename", "myconst",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        c_myconst_testdescribe_1(context)
      )
    )
    return output
  }

  fun c_myconst_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n myconst\n myconst)",
      ":testresult", vx_test.f_test(
        context,
        vx_sample.c_myconst,
        vx_sample.c_myconst
      )
    )
    return output
  }

  fun f_myfunc(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/sample",
      ":casename", "myfunc",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_myfunc_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_myfunc_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test 5 (myfunc 1))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.vx_new_int(5),
        vx_sample.f_myfunc(
          vx_core.vx_new_int(1)
        )
      )
    )
    return output
  }

  fun test_cases(context : vx_core.Type_context) : vx_test.Type_testcaselist {
    var testcases : List<vx_core.Type_any> = vx_core.arraylist_from_array(
      vx_sampleTest.c_myconst(context),
      vx_sampleTest.f_myfunc(context)
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
      ":testpkg", "vx/sample", 
      ":constnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 1, ":total", 1), 
      ":docnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 50, ":tests", 2, ":total", 4), 
      ":funcnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 50, ":tests", 1, ":total", 2), 
      ":bigospacenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 2), 
      ":bigotimenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 2), 
      ":totalnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 50, ":tests", 2, ":total", 4), 
      ":typenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 1)
    )
    return output
  }

  fun test_coveragedetail() : vx_test.Type_testcoveragedetail {
    var output : vx_test.Type_testcoveragedetail = vx_core.vx_new(
      vx_test.t_testcoveragedetail,
      ":testpkg", "vx/sample",
      ":typemap", vx_core.vx_new(
        vx_core.t_intmap,
        ":mytype", 0
      ), 
      ":constmap", vx_core.vx_new(
        vx_core.t_intmap,
        ":myconst", 1
      ), 
      ":funcmap", vx_core.vx_new(
        vx_core.t_intmap,
        ":main", 0,
        ":myfunc", 1
      )
    )
    return output
  }

  fun test_package(context : vx_core.Type_context) : vx_test.Type_testpackage {
    var testcaselist : vx_test.Type_testcaselist = test_cases(context)
    var output : vx_test.Type_testpackage = vx_core.vx_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/sample", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    )
    return output
  }

}
