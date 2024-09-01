
package com.vxlisp.vx

object vx_eventTest {

  fun test_cases(context : vx_core.Type_context) : vx_test.Type_testcaselist {
    var output : vx_test.Type_testcaselist = vx_test.e_testcaselist
    return output
  }

  fun test_coveragesummary() : vx_test.Type_testcoveragesummary {
    var output : vx_test.Type_testcoveragesummary = vx_core.vx_new(
      vx_test.t_testcoveragesummary,
      ":testpkg", "vx/event", 
      ":constnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 4), 
      ":docnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 90, ":tests", 10, ":total", 11), 
      ":funcnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 4), 
      ":bigospacenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 4), 
      ":bigotimenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 4), 
      ":totalnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 11), 
      ":typenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 3)
    )
    return output
  }

  fun test_coveragedetail() : vx_test.Type_testcoveragedetail {
    var output : vx_test.Type_testcoveragedetail = vx_core.vx_new(
      vx_test.t_testcoveragedetail,
      ":testpkg", "vx/event",
      ":typemap", vx_core.vx_new(
        vx_core.t_intmap,
        ":event", 0,
        ":eventlist", 0,
        ":eventmap", 0
      ), 
      ":constmap", vx_core.vx_new(
        vx_core.t_intmap,
        ":event-change", 0,
        ":event-click", 0,
        ":event-move", 0,
        ":event-select", 0
      ), 
      ":funcmap", vx_core.vx_new(
        vx_core.t_intmap,
        ":any-from<-event", 0,
        ":event<-event", 0,
        ":event<-event-async", 0,
        ":eventmap<-eventlist", 0
      )
    )
    return output
  }

  fun test_package(context : vx_core.Type_context) : vx_test.Type_testpackage {
    var testcaselist : vx_test.Type_testcaselist = test_cases(context)
    var output : vx_test.Type_testpackage = vx_core.vx_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/event", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    )
    return output
  }

}
