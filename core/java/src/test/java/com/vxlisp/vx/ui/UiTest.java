
package com.vxlisp.vx.ui;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import com.vxlisp.vx.*;
import com.vxlisp.vx.data.*;

public final class UiTest {

  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(
      
    ));
    Test.Type_testcaselist output = Test.t_testcaselist.vx_new(arraylisttestcase);
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    return Test.t_testcoveragesummary.vx_new(
      ":testpkg",   "vx/ui/ui", 
      ":constnums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 32), 
      ":docnums", Test.t_testcoveragenums.vx_new(":pct", 46, ":tests", 34, ":total", 73), 
      ":funcnums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 20), 
      ":bigospacenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 20), 
      ":bigotimenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 20), 
      ":totalnums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 73), 
      ":typenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 21)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Test.t_testcoveragedetail.vx_new(
      ":testpkg", "vx/ui/ui",
      ":typemap", Core.t_intmap.vx_new(
        ":bounds", 0,
        ":cursor", 0,
        ":cursor-pointer", 0,
        ":layout", 0,
        ":layoutengine", 0,
        ":layoutlist", 0,
        ":layoutmap", 0,
        ":pin", 0,
        ":point", 0,
        ":pointstyle", 0,
        ":render", 0,
        ":rendermap", 0,
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
        ":layout-app", 0,
        ":layout-background", 0,
        ":layout-combobox", 0,
        ":layout-else", 0,
        ":layout-flow-columns", 0,
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
        ":pin-bottom", 0,
        ":pin-center", 0,
        ":pin-center-h", 0,
        ":pin-center-v", 0,
        ":pin-expand", 0,
        ":pin-left", 0,
        ":pin-right", 0,
        ":pin-top", 0,
        ":styletype-custom", 0,
        ":styletype-shared", 0,
        ":styletype-system", 0
      ),
      ":funcmap", Core.t_intmap.vx_new(
        ":boolean-writestate<-ui", 0,
        ":boolean-writestate<-uiengine", 0,
        ":layout<-style", 0,
        ":layoutmap<-layoutlist", 0,
        ":stylemap<-stylelist", 0,
        ":stylesheet-render", 0,
        ":ui-data<-ui", 0,
        ":ui-from<-event", 0,
        ":ui-layout<-ui-layoutmap-else", 0,
        ":ui-readstate<-uid", 0,
        ":ui-render", 0,
        ":ui-render<-fn-render-ui-orig-parent", 0,
        ":ui-render<-ui-orig-parent", 0,
        ":ui<-renderer-ui-orig-parent", 0,
        ":uiengine-readstate", 0,
        ":uiengine-render", 0,
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
