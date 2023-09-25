'strict mode'

import vx_test from "../../src/vx/test.js"
import vx_core from "../../src/vx/core.js"
import vx_data_file from "../../src/vx/data/file.js"
import vx_web_html from "../../src/vx/web/html.js"

export default class vx_test_test {

  static test_package(context) {
    const testcaselist = vx_test_test.test_cases(context)
    const output = vx_core.f_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/test",
      ":caselist", testcaselist,
      ":coveragesummary", vx_test_test.test_coveragesummary(),
      ":coveragedetail", vx_test_test.test_coveragedetail()
    );
    return output;
  }

  static test_coveragesummary() {
    return vx_core.f_new(
      vx_test.t_testcoveragesummary,
      "testpkg",   "vx/test", 
      "constnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 1), 
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 93, ":tests", 40, ":total", 43), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 25), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 37), 
      "typenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 11)
    )
  }

  static test_coveragedetail() {
    return vx_core.f_new(
      vx_test.t_testcoveragedetail,
      "testpkg", "vx/test",
      "typemap",
        vx_core.f_new(
          vx_core.t_intmap,
          "testcase", 0,
          "testcaselist", 0,
          "testcoveragedetail", 0,
          "testcoveragenums", 0,
          "testcoveragesummary", 0,
          "testdescribe", 0,
          "testdescribelist", 0,
          "testpackage", 0,
          "testpackagelist", 0,
          "testresult", 0,
          "testresultlist", 0
        ),
      "constmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "stylesheet-test", 0
        ),
      "funcmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "context-test", 0,
          "div<-testcaselist", 0,
          "div<-testpackage", 0,
          "div<-testpackagelist", 0,
          "divchildlist<-testpackagelist", 0,
          "html<-divtest", 0,
          "p<-passfail", 0,
          "p<-testcoveragenums", 0,
          "resolve-testcase", 0,
          "resolve-testcaselist", 0,
          "resolve-testdescribe", 0,
          "resolve-testdescribelist", 0,
          "resolve-testpackage", 0,
          "resolve-testpackagelist", 0,
          "resolve-testresult", 0,
          "security-test", 0,
          "test", 0,
          "test_1", 0,
          "test-false", 0,
          "test-false_1", 0,
          "test-gt", 0,
          "test-gt_1", 0,
          "test-ne", 0,
          "test-ne_1", 0,
          "test-string", 0,
          "test-string_1", 0,
          "test-true", 0,
          "test-true_1", 0,
          "tr<-testdescribe-casename", 0,
          "trlist<-testcase", 0,
          "trlist<-testcaselist", 0
        )
    )
  }

  static test_cases(context) {
    const output = vx_core.f_new(
      vx_test.t_testcaselist
    )
    return output
  }

}
