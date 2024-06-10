'strict mode'

import vx_web_htmldoc from "../../../src/vx/web/htmldoc.js"
import vx_core from "../../../src/vx/core.js"
import vx_test from "../../../src/vx/test.js"
import vx_event from "../../../src/vx/event.js"
import vx_web_html from "../../../src/vx/web/html.js"
import vx_ui_ui from "../../../src/vx/ui/ui.js"

export default class vx_web_htmldoc_test {


  static test_package(context) {
    const testcaselist = vx_web_htmldoc_test.test_cases(context)
    const output = vx_core.f_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/web/htmldoc",
      ":caselist", testcaselist,
      ":coveragesummary", vx_web_htmldoc_test.test_coveragesummary(),
      ":coveragedetail", vx_web_htmldoc_test.test_coveragedetail()
    );
    return output;
  }

  static test_coveragesummary() {
    return vx_core.f_new(
      vx_test.t_testcoveragesummary,
      "testpkg",   "vx/web/htmldoc", 
      "constnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 15, ":total", 15), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 15), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 15), 
      "typenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0)
    )
  }

  static test_coveragedetail() {
    return vx_core.f_new(
      vx_test.t_testcoveragedetail,
      "testpkg", "vx/web/htmldoc",
      "typemap",
        vx_core.f_new(
          vx_core.t_intmap
        ),
      "constmap",
        vx_core.f_new(
          vx_core.t_intmap
        ),
      "funcmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "boolean-print<-id-stylesheettext", 0,
          "boolean-remove<-id", 0,
          "boolean-replace<-id-htmltext", 0,
          "boolean-replace<-id-parent-htmltext", 0,
          "boolean-write-stylesheet<-string", 0,
          "boolean-write<-id-attribute-value", 0,
          "boolean-write<-id-htmltext", 0,
          "boolean-write<-id-visible", 0,
          "boolean-write<-stylesheet", 0,
          "boolean-writeevents<-ui", 0,
          "context-read", 0,
          "context-write", 0,
          "string<-id", 0,
          "string<-stylesheet", 0,
          "ui-readstate<-uid", 0
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
