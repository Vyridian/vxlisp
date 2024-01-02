'strict mode'

import vx_web_http from "../../../src/vx/web/http.js"
import vx_core from "../../../src/vx/core.js"
import vx_test from "../../../src/vx/test.js"
import vx_data_csv from "../../../src/vx/data/csv.js"
import vx_data_textblock from "../../../src/vx/data/textblock.js"
import vx_data_xml from "../../../src/vx/data/xml.js"

export default class vx_web_http_test {


  static test_package(context) {
    const testcaselist = vx_web_http_test.test_cases(context)
    const output = vx_core.f_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/web/http",
      ":caselist", testcaselist,
      ":coveragesummary", vx_web_http_test.test_coveragesummary(),
      ":coveragedetail", vx_web_http_test.test_coveragedetail()
    );
    return output;
  }

  static test_coveragesummary() {
    return vx_core.f_new(
      vx_test.t_testcoveragesummary,
      "testpkg",   "vx/web/http", 
      "constnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 88, ":tests", 8, ":total", 9), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 8), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 9), 
      "typenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 1)
    )
  }

  static test_coveragedetail() {
    return vx_core.f_new(
      vx_test.t_testcoveragedetail,
      "testpkg", "vx/web/http",
      "typemap",
        vx_core.f_new(
          vx_core.t_intmap,
          "response", 0
        ),
      "constmap",
        vx_core.f_new(
          vx_core.t_intmap
        ),
      "funcmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "csv<-httpget", 0,
          "json<-httpget", 0,
          "response<-httpget", 0,
          "text<-httpget", 0,
          "text<-response", 0,
          "textblock<-httpget", 0,
          "textblock<-response", 0,
          "xml<-httpget", 0
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
