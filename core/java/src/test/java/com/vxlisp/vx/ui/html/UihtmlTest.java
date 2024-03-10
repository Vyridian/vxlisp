
package com.vxlisp.vx.ui.html;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import com.vxlisp.vx.*;
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
      ":constnums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 6), 
      ":docnums", Test.t_testcoveragenums.vx_new(":pct", 54, ":tests", 12, ":total", 22), 
      ":funcnums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 16), 
      ":bigospacenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 16), 
      ":bigotimenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 16), 
      ":totalnums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 22), 
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
        ":layout-label-html", 0,
        ":layoutenginehtml", 0,
        ":style-hidden", 0,
        ":style-selected", 0
      ),
      ":funcmap", Core.t_intmap.vx_new(
        ":context-write", 0,
        ":divchild<-ui", 0,
        ":divchildlist<-uimap", 0,
        ":node-app<-ui-orig-parent", 0,
        ":node-render<-node-ui", 0,
        ":string-stylename<-name-styletype", 0,
        ":style<-style", 0,
        ":stylelist-extra<-ui", 0,
        ":stylelist<-stylelist", 0,
        ":stylelist<-stylemap", 0,
        ":stylemap<-stylemap", 0,
        ":stylesheet-render-html", 0,
        ":stylesheet<-stylesheet", 0,
        ":ui-render-app<-ui-orig-parent", 0,
        ":ui-render-default<-ui-orig-parent", 0,
        ":ui-render-label<-ui-orig-parent", 0
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
