'strict mode'

import vx_state from "../../src/vx/state.js"
import vx_core from "../../src/vx/core.js"
import vx_test from "../../src/vx/test.js"

export default class vx_state_test {


  static test_package(context) {
    const testcaselist = vx_state_test.test_cases(context)
    const output = vx_core.f_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/state",
      ":caselist", testcaselist,
      ":coveragesummary", vx_state_test.test_coveragesummary(),
      ":coveragedetail", vx_state_test.test_coveragedetail()
    );
    return output;
  }

  static test_coveragesummary() {
    return vx_core.f_new(
      vx_test.t_testcoveragesummary,
      "testpkg",   "vx/state", 
      "constnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 85, ":tests", 12, ":total", 14), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 13), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 14), 
      "typenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 1)
    )
  }

  static test_coveragedetail() {
    return vx_core.f_new(
      vx_test.t_testcoveragedetail,
      "testpkg", "vx/state",
      "typemap",
        vx_core.f_new(
          vx_core.t_intmap,
          "valuemap", 0
        ),
      "constmap",
        vx_core.f_new(
          vx_core.t_intmap
        ),
      "funcmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "any-readstate<-mapname-name", 0,
          "any-readstate<-name", 0,
          "boolean-removestate<-name", 0,
          "boolean-writestate<-mapname-name-value", 0,
          "boolean-writestate<-name-value", 0,
          "boolean-writestate<-statelistener", 0,
          "change", 0,
          "register", 0,
          "state<-context", 0,
          "statelistener-readstate<-name", 0,
          "statelistenermap-readstate", 0,
          "value-readstate<-name", 0,
          "valuemap-readstate<-mapname", 0
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
