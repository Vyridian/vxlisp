'strict mode'

import vx_ui_html_uihtml from "../../../../src/vx/ui/html/uihtml.js"
import vx_core from "../../../../src/vx/core.js"
import vx_test from "../../../../src/vx/test.js"
import vx_data_file from "../../../../src/vx/data/file.js"
import vx_web_html from "../../../../src/vx/web/html.js"
import vx_web_htmldoc from "../../../../src/vx/web/htmldoc.js"
import vx_event from "../../../../src/vx/event.js"
import vx_type from "../../../../src/vx/type.js"
import vx_ui_ui from "../../../../src/vx/ui/ui.js"

export default class vx_ui_html_uihtml_test {


  static test_package(context) {
    const testcaselist = vx_ui_html_uihtml_test.test_cases(context)
    const output = vx_core.f_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/ui/html/uihtml",
      ":caselist", testcaselist,
      ":coveragesummary", vx_ui_html_uihtml_test.test_coveragesummary(),
      ":coveragedetail", vx_ui_html_uihtml_test.test_coveragedetail()
    );
    return output;
  }

  static test_coveragesummary() {
    return vx_core.f_new(
      vx_test.t_testcoveragesummary,
      "testpkg",   "vx/ui/html/uihtml", 
      "constnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 7), 
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 63, ":tests", 19, ":total", 30), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 23), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 30), 
      "typenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0)
    )
  }

  static test_coveragedetail() {
    return vx_core.f_new(
      vx_test.t_testcoveragedetail,
      "testpkg", "vx/ui/html/uihtml",
      "typemap",
        vx_core.f_new(
          vx_core.t_intmap
        ),
      "constmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "layout-app-html", 0,
          "layout-else-html", 0,
          "layout-image-html", 0,
          "layout-label-html", 0,
          "layoutenginehtml", 0,
          "style-hidden", 0,
          "style-selected", 0
        ),
      "funcmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "boolean-print-html", 0,
          "context-write", 0,
          "divchild<-ui", 0,
          "divchildlist<-uimap", 0,
          "node-app<-ui-orig-parent", 0,
          "node-render<-node-ui", 0,
          "string-style<-font", 0,
          "string-style<-image", 0,
          "string-stylename<-name-styletype", 0,
          "style<-fontface", 0,
          "style<-style", 0,
          "stylelist-extra<-ui", 0,
          "stylelist-reset", 0,
          "stylelist<-fontfacemap", 0,
          "stylelist<-stylelist", 0,
          "stylelist<-stylemap", 0,
          "stylemap<-stylemap", 0,
          "stylesheet-render-html", 0,
          "stylesheet<-stylesheet", 0,
          "ui-render-app<-ui-orig-parent", 0,
          "ui-render-default<-ui-orig-parent", 0,
          "ui-render-image<-ui-orig-parent", 0,
          "ui-render-label<-ui-orig-parent", 0
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
