'strict mode'

import vx_sample from "../../src/vx/sample.js"
import vx_core from "../../src/vx/core.js"
import vx_test from "../../src/vx/test.js"

export default class vx_sample_test {

  static test_package(context) {
    const testcaselist = vx_sample_test.test_cases(context)
    const output = vx_core.f_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/sample",
      ":caselist", testcaselist,
      ":coveragesummary", vx_sample_test.test_coveragesummary(),
      ":coveragedetail", vx_sample_test.test_coveragedetail()
    );
    return output;
  }

  static test_coveragesummary() {
    return vx_core.f_new(
      vx_test.t_testcoveragesummary,
      "testpkg",   "vx/sample", 
      "constnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 1, ":total", 1), 
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 50, ":tests", 2, ":total", 4), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 50, ":tests", 1, ":total", 2), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 50, ":tests", 2, ":total", 4), 
      "typenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 1)
    )
  }

  static test_coveragedetail() {
    return vx_core.f_new(
      vx_test.t_testcoveragedetail,
      "testpkg", "vx/sample",
      "typemap",
        vx_core.f_new(
          vx_core.t_intmap,
          "mytype", 0
        ),
      "constmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "myconst", 1
        ),
      "funcmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "main", 0,
          "myfunc", 1
        )
    )
  }

  static c_myconst(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/sample",
      ":casename", "myconst",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 4 myconst)",
            ":testresult",
            vx_test.f_test(
                4,
                vx_sample.c_myconst,
                context
              )
          )
        )
    )
    return output
  }

  static f_myfunc(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/sample",
      ":casename", "myfunc",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 5 (myfunc 1))",
            ":testresult",
            vx_test.f_test(
              5,
              vx_sample.f_myfunc(1),
              context
            )
          )
        )
    )
    return output
  }

  static test_cases(context) {
    const output = vx_core.f_new(
      vx_test.t_testcaselist,
      vx_sample_test.c_myconst(),
      vx_sample_test.f_myfunc(context)
    )
    return output
  }

}
