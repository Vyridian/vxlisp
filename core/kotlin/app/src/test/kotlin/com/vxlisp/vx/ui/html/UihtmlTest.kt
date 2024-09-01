
package com.vxlisp.vx.ui.html

import com.vxlisp.vx.*
import com.vxlisp.vx.data.*
import com.vxlisp.vx.web.*
import com.vxlisp.vx.ui.*

object vx_ui_html_uihtmlTest {

  fun test_cases(context : vx_core.Type_context) : vx_test.Type_testcaselist {
    var output : vx_test.Type_testcaselist = vx_test.e_testcaselist
    return output
  }

  fun test_coveragesummary() : vx_test.Type_testcoveragesummary {
    var output : vx_test.Type_testcoveragesummary = vx_core.vx_new(
      vx_test.t_testcoveragesummary,
      ":testpkg", "vx/ui/html/uihtml", 
      ":constnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 7), 
      ":docnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 66, ":tests", 30, ":total", 45), 
      ":funcnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 37), 
      ":bigospacenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 38), 
      ":bigotimenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 38), 
      ":totalnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 44), 
      ":typenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0)
    )
    return output
  }

  fun test_coveragedetail() : vx_test.Type_testcoveragedetail {
    var output : vx_test.Type_testcoveragedetail = vx_core.vx_new(
      vx_test.t_testcoveragedetail,
      ":testpkg", "vx/ui/html/uihtml",
      ":typemap", vx_core.e_intmap, 
      ":constmap", vx_core.vx_new(
        vx_core.t_intmap,
        ":layout-app-html", 0,
        ":layout-else-html", 0,
        ":layout-image-html", 0,
        ":layout-label-html", 0,
        ":layoutenginehtml", 0,
        ":style-hidden", 0,
        ":style-selected", 0
      ), 
      ":funcmap", vx_core.vx_new(
        vx_core.t_intmap,
        ":boolean-layoutremove-html", 0,
        ":boolean-layoutselected-html", 0,
        ":boolean-layoutvisible-html", 0,
        ":boolean-print-html", 0,
        ":boolean-writeclass<-ui", 0,
        ":boolean-writeeventsall<-ui", 0,
        ":boolean-writeeventsall<-uimap", 0,
        ":boolean-writeselected<-ui", 0,
        ":boolean-writevisible<-ui", 0,
        ":context-write", 0,
        ":divchild<-ui", 0,
        ":divchildlist<-uimap", 0,
        ":divchildlist<-uimap_1", 0,
        ":divchildlist<-uimap-origmap-parent", 0,
        ":node-app<-ui-orig-parent", 0,
        ":node-default<-ui-orig-parent", 0,
        ":node-image<-ui-orig-parent", 0,
        ":node-label<-ui-orig-parent", 0,
        ":node-layout<-node-ui-parent", 0,
        ":node<-ui-orig-parent", 0,
        ":string-class<-ui", 0,
        ":string-style<-font", 0,
        ":string-style<-image", 0,
        ":string-stylename<-name-styletype", 0,
        ":style<-fontface", 0,
        ":style<-style", 0,
        ":stylelist-extra<-ui", 0,
        ":stylelist-reset", 0,
        ":stylelist<-fontfacemap", 0,
        ":stylelist<-stylelist", 0,
        ":stylelist<-stylemap", 0,
        ":stylemap<-stylemap", 0,
        ":stylesheet-layout-html", 0,
        ":stylesheet<-stylesheet", 0,
        ":ui-layout-app<-ui-orig-parent", 0,
        ":ui-layout-default<-ui-orig-parent", 0,
        ":ui-layout-image<-ui-orig-parent", 0,
        ":ui-layout-label<-ui-orig-parent", 0
      )
    )
    return output
  }

  fun test_package(context : vx_core.Type_context) : vx_test.Type_testpackage {
    var testcaselist : vx_test.Type_testcaselist = test_cases(context)
    var output : vx_test.Type_testpackage = vx_core.vx_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/ui/html/uihtml", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    )
    return output
  }

}
