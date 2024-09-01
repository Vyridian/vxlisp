
package com.vxlisp.vx.web

import com.vxlisp.vx.*
import com.vxlisp.vx.ui.*

object vx_web_htmldocTest {

  fun test_cases(context : vx_core.Type_context) : vx_test.Type_testcaselist {
    var output : vx_test.Type_testcaselist = vx_test.e_testcaselist
    return output
  }

  fun test_coveragesummary() : vx_test.Type_testcoveragesummary {
    var output : vx_test.Type_testcoveragesummary = vx_core.vx_new(
      vx_test.t_testcoveragesummary,
      ":testpkg", "vx/web/htmldoc", 
      ":constnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 15, ":total", 15), 
      ":funcnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 15), 
      ":bigospacenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 15), 
      ":bigotimenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 15), 
      ":totalnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 15), 
      ":typenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0)
    )
    return output
  }

  fun test_coveragedetail() : vx_test.Type_testcoveragedetail {
    var output : vx_test.Type_testcoveragedetail = vx_core.vx_new(
      vx_test.t_testcoveragedetail,
      ":testpkg", "vx/web/htmldoc",
      ":typemap", vx_core.e_intmap, 
      ":constmap", vx_core.e_intmap, 
      ":funcmap", vx_core.vx_new(
        vx_core.t_intmap,
        ":boolean-print<-id-stylesheettext", 0,
        ":boolean-remove<-id", 0,
        ":boolean-replace<-id-htmltext", 0,
        ":boolean-replace<-id-parent-htmltext", 0,
        ":boolean-write-stylesheet<-string", 0,
        ":boolean-write<-id-attribute-value", 0,
        ":boolean-write<-id-htmltext", 0,
        ":boolean-write<-id-visible", 0,
        ":boolean-write<-stylesheet", 0,
        ":boolean-writeevents<-ui", 0,
        ":context-read", 0,
        ":context-write", 0,
        ":string<-id", 0,
        ":string<-stylesheet", 0,
        ":ui-readstate<-uid", 0
      )
    )
    return output
  }

  fun test_package(context : vx_core.Type_context) : vx_test.Type_testpackage {
    var testcaselist : vx_test.Type_testcaselist = test_cases(context)
    var output : vx_test.Type_testpackage = vx_core.vx_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/web/htmldoc", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    )
    return output
  }

}
