
package com.vxlisp.vx.ui;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import com.vxlisp.vx.*;
import com.vxlisp.vx.data.*;

public final class UiTest {

  static Test.Type_testcase f_ui_from_ui_selected(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/ui/ui",
      ":casename", "ui<-ui-selected",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (ui\n  :uimap\n   (uimap\n    :a\n     (ui\n      :uid \"a\")\n    :b\n     (ui\n      :uid \"b\"\n      :selected true)))\n (ui<-ui-selected\n  (ui\n   :uimap\n    (uimap\n     :a\n      (ui\n       :uid \"a\"\n       :selected true)\n     :b\n      (ui\n       :uid \"b\")))\n  2))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Ui.t_ui,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":uimap"),
                  Core.f_new(
                    Ui.t_uimap,
                    Core.t_anylist.vx_new(
                      Core.vx_new_string(":a"),
                      Core.f_new(
                        Ui.t_ui,
                        Core.t_anylist.vx_new(
                          Core.vx_new_string(":uid"),
                          Core.vx_new_string("a")
                        )
                      ),
                      Core.vx_new_string(":b"),
                      Core.f_new(
                        Ui.t_ui,
                        Core.t_anylist.vx_new(
                          Core.vx_new_string(":uid"),
                          Core.vx_new_string("b"),
                          Core.vx_new_string(":selected"),
                          Core.vx_new_boolean(true)
                        )
                      )
                    )
                  )
                )
              ),
              Ui.f_ui_from_ui_selected(
                Core.f_new(
                  Ui.t_ui,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":uimap"),
                    Core.f_new(
                      Ui.t_uimap,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string(":a"),
                        Core.f_new(
                          Ui.t_ui,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":uid"),
                            Core.vx_new_string("a"),
                            Core.vx_new_string(":selected"),
                            Core.vx_new_boolean(true)
                          )
                        ),
                        Core.vx_new_string(":b"),
                        Core.f_new(
                          Ui.t_ui,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":uid"),
                            Core.vx_new_string("b")
                          )
                        )
                      )
                    )
                  )
                ),
                Core.vx_new_int(2)
              )
            )
        )
      )
    );
    return output;
  }

  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(
      UiTest.f_ui_from_ui_selected(context)
    ));
    Test.Type_testcaselist output = Test.t_testcaselist.vx_new(arraylisttestcase);
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    return Test.t_testcoveragesummary.vx_new(
      ":testpkg",   "vx/ui/ui", 
      ":constnums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 41), 
      ":docnums", Test.t_testcoveragenums.vx_new(":pct", 58, ":tests", 65, ":total", 111), 
      ":funcnums", Test.t_testcoveragenums.vx_new(":pct", 2, ":tests", 1, ":total", 42), 
      ":bigospacenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 42), 
      ":bigotimenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 42), 
      ":totalnums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 1, ":total", 111), 
      ":typenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 28)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Test.t_testcoveragedetail.vx_new(
      ":testpkg", "vx/ui/ui",
      ":typemap", Core.t_intmap.vx_new(
        ":align", 0,
        ":bounds", 0,
        ":cursor", 0,
        ":cursor-pointer", 0,
        ":font", 0,
        ":fontface", 0,
        ":fontfacelist", 0,
        ":fontfacemap", 0,
        ":fontmap", 0,
        ":fontstyle", 0,
        ":fontstylemap", 0,
        ":image", 0,
        ":layout", 0,
        ":layoutengine", 0,
        ":layoutlist", 0,
        ":layoutmap", 0,
        ":pin", 0,
        ":point", 0,
        ":pointtype", 0,
        ":style", 0,
        ":stylelist", 0,
        ":stylemap", 0,
        ":stylesheet", 0,
        ":styletype", 0,
        ":ui", 0,
        ":uiengine", 0,
        ":uilist", 0,
        ":uimap", 0
      ),
      ":constmap", Core.t_intmap.vx_new(
        ":align-center", 0,
        ":align-left", 0,
        ":align-right", 0,
        ":layout-app", 0,
        ":layout-background", 0,
        ":layout-button", 0,
        ":layout-combobox", 0,
        ":layout-else", 0,
        ":layout-flow-columns", 0,
        ":layout-flow-item", 0,
        ":layout-flow-rows", 0,
        ":layout-image", 0,
        ":layout-label", 0,
        ":layout-main", 0,
        ":layout-maxpanel", 0,
        ":layout-menubar", 0,
        ":layout-menudrawer", 0,
        ":layout-msgbox", 0,
        ":layout-navbar", 0,
        ":layout-navdrawer", 0,
        ":layout-panel", 0,
        ":layout-parallax", 0,
        ":layout-statusbar", 0,
        ":layout-statusdrawer", 0,
        ":layout-text", 0,
        ":layout-textentry", 0,
        ":layout-titlebar", 0,
        ":pin-bottom", 0,
        ":pin-center", 0,
        ":pin-center-h", 0,
        ":pin-center-v", 0,
        ":pin-expand", 0,
        ":pin-left", 0,
        ":pin-right", 0,
        ":pin-top", 0,
        ":pointtype-absolute", 0,
        ":pointtype-percent", 0,
        ":pointtype-relative", 0,
        ":styletype-custom", 0,
        ":styletype-shared", 0,
        ":styletype-system", 0
      ),
      ":funcmap", Core.t_intmap.vx_new(
        ":boolean-print", 0,
        ":boolean-writestate<-ui", 0,
        ":boolean-writestate<-uiengine", 0,
        ":fontfacemap<-fontfacelist", 0,
        ":int-selected<-ui", 0,
        ":layout<-style", 0,
        ":layout<-ui", 0,
        ":layout<-ui-layoutengine", 0,
        ":layout<-ui-layoutmap-else", 0,
        ":layoutengine-readstate", 0,
        ":layoutmap<-layoutlist", 0,
        ":string-selected<-ui", 0,
        ":stringlist-selected<-ui", 0,
        ":stringlist<-ui", 0,
        ":stylemap<-stylelist", 0,
        ":stylesheet-readstate", 0,
        ":stylesheet-render", 0,
        ":ui-child<-ui-uid", 0,
        ":ui-from<-event", 0,
        ":ui-layout<-ui", 0,
        ":ui-layout<-ui-layoutengine", 0,
        ":ui-layout<-ui-layoutmap-else", 0,
        ":ui-layout<-ui-uiengine", 0,
        ":ui-readstate<-uid", 0,
        ":ui-render", 0,
        ":ui-render<-fn-render-ui-orig-parent", 0,
        ":ui-render<-ui-orig-parent", 0,
        ":ui-render<-ui-parent-selected", 0,
        ":ui-selected<-ui", 0,
        ":ui-writechild<-ui-child", 0,
        ":ui-writechildmap<-ui-childmap", 0,
        ":ui<-layout-ui-orig-parent", 0,
        ":ui<-ui-selected", 1,
        ":uid-selected<-ui", 0,
        ":uiengine-readstate", 0,
        ":uiengine-render", 0,
        ":uilist-selected<-ui", 0,
        ":uilist<-uimap", 0,
        ":uimap-layout<-uimap-layoutmap-else", 0,
        ":uimap-render<-uimap-parent", 0,
        ":uimap<-uilist", 0,
        ":uimap<-uimap-data", 0
      )
    );
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Test.t_testpackage.vx_new(
      ":testpkg", "vx/ui/ui", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
