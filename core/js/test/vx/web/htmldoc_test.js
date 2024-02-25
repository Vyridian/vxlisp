'strict mode'

import vx_web_htmldoc from "../../../src/vx/web/htmldoc.js"
import vx_core from "../../../src/vx/core.js"
import vx_test from "../../../src/vx/test.js"
import vx_event from "../../../src/vx/event.js"
import vx_web_html from "../../../src/vx/web/html.js"

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
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 7, ":total", 7), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 7), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 7), 
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
          "any-data<-id", 0,
          "boolean-replace<-id-htmltext", 0,
          "boolean-replace<-id-htmltext-data-eventmap", 0,
          "boolean-write-stylesheet<-string", 0,
          "boolean-write<-id-htmltext", 0,
          "boolean-write<-stylesheet", 0,
          "string<-id", 0
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
