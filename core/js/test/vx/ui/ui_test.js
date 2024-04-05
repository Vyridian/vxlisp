'strict mode'

import vx_ui_ui from "../../../src/vx/ui/ui.js"
import vx_core from "../../../src/vx/core.js"
import vx_test from "../../../src/vx/test.js"
import vx_collection from "../../../src/vx/collection.js"
import vx_event from "../../../src/vx/event.js"
import vx_data_file from "../../../src/vx/data/file.js"
import vx_state from "../../../src/vx/state.js"

export default class vx_ui_ui_test {


  static test_package(context) {
    const testcaselist = vx_ui_ui_test.test_cases(context)
    const output = vx_core.f_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/ui/ui",
      ":caselist", testcaselist,
      ":coveragesummary", vx_ui_ui_test.test_coveragesummary(),
      ":coveragedetail", vx_ui_ui_test.test_coveragedetail()
    );
    return output;
  }

  static test_coveragesummary() {
    return vx_core.f_new(
      vx_test.t_testcoveragesummary,
      "testpkg",   "vx/ui/ui", 
      "constnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 41), 
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 56, ":tests", 62, ":total", 109), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 40), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 109), 
      "typenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 28)
    )
  }

  static test_coveragedetail() {
    return vx_core.f_new(
      vx_test.t_testcoveragedetail,
      "testpkg", "vx/ui/ui",
      "typemap",
        vx_core.f_new(
          vx_core.t_intmap,
          "align", 0,
          "bounds", 0,
          "cursor", 0,
          "cursor-pointer", 0,
          "font", 0,
          "fontface", 0,
          "fontfacelist", 0,
          "fontfacemap", 0,
          "fontmap", 0,
          "fontstyle", 0,
          "fontstylemap", 0,
          "image", 0,
          "layout", 0,
          "layoutengine", 0,
          "layoutlist", 0,
          "layoutmap", 0,
          "pin", 0,
          "point", 0,
          "pointtype", 0,
          "style", 0,
          "stylelist", 0,
          "stylemap", 0,
          "stylesheet", 0,
          "styletype", 0,
          "ui", 0,
          "uiengine", 0,
          "uilist", 0,
          "uimap", 0
        ),
      "constmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "align-center", 0,
          "align-left", 0,
          "align-right", 0,
          "layout-app", 0,
          "layout-background", 0,
          "layout-button", 0,
          "layout-combobox", 0,
          "layout-else", 0,
          "layout-flow-columns", 0,
          "layout-flow-item", 0,
          "layout-flow-rows", 0,
          "layout-image", 0,
          "layout-label", 0,
          "layout-main", 0,
          "layout-maxpanel", 0,
          "layout-menubar", 0,
          "layout-menudrawer", 0,
          "layout-msgbox", 0,
          "layout-navbar", 0,
          "layout-navdrawer", 0,
          "layout-panel", 0,
          "layout-parallax", 0,
          "layout-statusbar", 0,
          "layout-statusdrawer", 0,
          "layout-text", 0,
          "layout-textentry", 0,
          "layout-titlebar", 0,
          "pin-bottom", 0,
          "pin-center", 0,
          "pin-center-h", 0,
          "pin-center-v", 0,
          "pin-expand", 0,
          "pin-left", 0,
          "pin-right", 0,
          "pin-top", 0,
          "pointtype-absolute", 0,
          "pointtype-percent", 0,
          "pointtype-relative", 0,
          "styletype-custom", 0,
          "styletype-shared", 0,
          "styletype-system", 0
        ),
      "funcmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "boolean-print", 0,
          "boolean-writestate<-ui", 0,
          "boolean-writestate<-uiengine", 0,
          "fontfacemap<-fontfacelist", 0,
          "int-selected<-ui", 0,
          "layout<-style", 0,
          "layout<-ui", 0,
          "layout<-ui-layoutengine", 0,
          "layout<-ui-layoutmap-else", 0,
          "layoutengine-readstate", 0,
          "layoutmap<-layoutlist", 0,
          "string-selected<-ui", 0,
          "stringlist-selected<-ui", 0,
          "stringlist<-ui", 0,
          "stylemap<-stylelist", 0,
          "stylesheet-readstate", 0,
          "stylesheet-render", 0,
          "ui-child<-ui-uid", 0,
          "ui-from<-event", 0,
          "ui-layout<-ui", 0,
          "ui-layout<-ui-layoutengine", 0,
          "ui-layout<-ui-layoutmap-else", 0,
          "ui-layout<-ui-uiengine", 0,
          "ui-readstate<-uid", 0,
          "ui-render", 0,
          "ui-render<-fn-render-ui-orig-parent", 0,
          "ui-render<-ui-orig-parent", 0,
          "ui-selected<-ui", 0,
          "ui-writechild<-ui-child", 0,
          "ui-writechildmap<-ui-childmap", 0,
          "ui<-layout-ui-orig-parent", 0,
          "uid-selected<-ui", 0,
          "uiengine-readstate", 0,
          "uiengine-render", 0,
          "uilist-selected<-ui", 0,
          "uilist<-uimap", 0,
          "uimap-layout<-uimap-layoutmap-else", 0,
          "uimap-render<-uimap-parent", 0,
          "uimap<-uilist", 0,
          "uimap<-uimap-data", 0
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
