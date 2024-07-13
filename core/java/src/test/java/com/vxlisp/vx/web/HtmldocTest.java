
package com.vxlisp.vx.web;

import com.vxlisp.vx.*;
import com.vxlisp.vx.ui.*;

public final class HtmldocTest {

  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {
    Test.Type_testcaselist output = Test.e_testcaselist;
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    return Core.vx_new(
      Test.t_testcoveragesummary,
      ":testpkg", "vx/web/htmldoc", 
      ":constnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 15, ":total", 15), 
      ":funcnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 15), 
      ":bigospacenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 15), 
      ":bigotimenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 15), 
      ":totalnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 15), 
      ":typenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Core.vx_new(Test.t_testcoveragedetail, ":testpkg", "vx/web/htmldoc", ":typemap", Core.e_intmap, ":constmap", Core.e_intmap, ":funcmap", Core.vx_new(
  Core.t_intmap,
        ":boolean-print<-id-stylesheettext", 0,
        ":boolean-remove<-id", 0,
        ":boolean-replace<-id-htmltext", 0,
        ":boolean-replace<-id-parent-htmltext", 0,
        ":boolean-write-stylesheet<-string", 0,
        ":boolean-write<-id-attribute-value", 0,
        ":boolean-write<-id-htmltext", 0,
        ":boolean-write<-id-visible", 0,
        ":boolean-write<-stylesheet", 0,
        ":boolean-writeevents<-ui", 0,
        ":context-read", 0,
        ":context-write", 0,
        ":string<-id", 0,
        ":string<-stylesheet", 0,
        ":ui-readstate<-uid", 0
      ));
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Core.vx_new(
      Test.t_testpackage,
      ":testpkg", "vx/web/htmldoc", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
