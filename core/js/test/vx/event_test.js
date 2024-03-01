'strict mode'

import vx_event from "../../src/vx/event.js"
import vx_core from "../../src/vx/core.js"
import vx_test from "../../src/vx/test.js"

export default class vx_event_test {


  static test_package(context) {
    const testcaselist = vx_event_test.test_cases(context)
    const output = vx_core.f_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/event",
      ":caselist", testcaselist,
      ":coveragesummary", vx_event_test.test_coveragesummary(),
      ":coveragedetail", vx_event_test.test_coveragedetail()
    );
    return output;
  }

  static test_coveragesummary() {
    return vx_core.f_new(
      vx_test.t_testcoveragesummary,
      "testpkg",   "vx/event", 
      "constnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 4), 
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 90, ":tests", 9, ":total", 10), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 3), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 10), 
      "typenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 3)
    )
  }

  static test_coveragedetail() {
    return vx_core.f_new(
      vx_test.t_testcoveragedetail,
      "testpkg", "vx/event",
      "typemap",
        vx_core.f_new(
          vx_core.t_intmap,
          "event", 0,
          "eventlist", 0,
          "eventmap", 0
        ),
      "constmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "event-change", 0,
          "event-click", 0,
          "event-move", 0,
          "event-select", 0
        ),
      "funcmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "any-from<-event", 0,
          "event<-event", 0,
          "eventmap<-eventlist", 0
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
