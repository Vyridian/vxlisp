
package com.vxlisp.vx.ui.html;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import com.vxlisp.vx.*;
import com.vxlisp.vx.data.*;
import com.vxlisp.vx.web.*;
import com.vxlisp.vx.ui.*;

public final class UihtmlTest {

  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(
      
    ));
    Test.Type_testcaselist output = Test.t_testcaselist.vx_new(arraylisttestcase);
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    return Test.t_testcoveragesummary.vx_new(
      ":testpkg",   "vx/ui/html/uihtml", 
      ":constnums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 7), 
      ":docnums", Test.t_testcoveragenums.vx_new(":pct", 60, ":tests", 23, ":total", 38), 
      ":funcnums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 30), 
      ":bigospacenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 31), 
      ":bigotimenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 31), 
      ":totalnums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 37), 
      ":typenums", Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 0, ":total", 0)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Test.t_testcoveragedetail.vx_new(
      ":testpkg", "vx/ui/html/uihtml",
      ":typemap", Core.t_intmap.vx_new(
  
      ),
      ":constmap", Core.t_intmap.vx_new(
        ":layout-app-html", 0,
        ":layout-else-html", 0,
        ":layout-image-html", 0,
        ":layout-label-html", 0,
        ":layoutenginehtml", 0,
        ":style-hidden", 0,
        ":style-selected", 0
      ),
      ":funcmap", Core.t_intmap.vx_new(
        ":boolean-print-html", 0,
        ":boolean-writeeventsall<-ui", 0,
        ":boolean-writeeventsall<-uimap", 0,
        ":context-write", 0,
        ":divchild<-ui", 0,
        ":divchildlist<-uimap", 0,
        ":divchildlist<-uimap_1", 0,
        ":divchildlist<-uimap-origmap-parent", 0,
        ":node-app<-ui-orig-parent", 0,
        ":node-default<-ui-orig-parent", 0,
        ":node-image<-ui-orig-parent", 0,
        ":node-label<-ui-orig-parent", 0,
        ":node-layout<-node-ui", 0,
        ":node<-ui-orig-parent", 0,
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
    );
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Test.t_testpackage.vx_new(
      ":testpkg", "vx/ui/html/uihtml", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
