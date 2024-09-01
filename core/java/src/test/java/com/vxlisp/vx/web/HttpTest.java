
package com.vxlisp.vx.web;

import com.vxlisp.vx.*;
import com.vxlisp.vx.data.*;

public final class HttpTest {

  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {
    Test.Type_testcaselist output = Test.e_testcaselist;
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    Test.Type_testcoveragesummary output = Core.vx_new(
      Test.t_testcoveragesummary,
      ":testpkg", "vx/web/http", 
      ":constnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 88, ":tests", 8, ":total", 9), 
      ":funcnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 8), 
      ":bigospacenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 8), 
      ":bigotimenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 8), 
      ":totalnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 9), 
      ":typenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 1)
    );
    return output;
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    Test.Type_testcoveragedetail output = Core.vx_new(
      Test.t_testcoveragedetail,
      ":testpkg", "vx/web/http",
      ":typemap", Core.vx_new(
        Core.t_intmap,
        ":response", 0
      ), 
      ":constmap", Core.e_intmap, 
      ":funcmap", Core.vx_new(
        Core.t_intmap,
        ":csv<-httpget", 0,
        ":json<-httpget", 0,
        ":response<-httpget", 0,
        ":text<-httpget", 0,
        ":text<-response", 0,
        ":textblock<-httpget", 0,
        ":textblock<-response", 0,
        ":xml<-httpget", 0
      )
    );
    return output;
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Core.vx_new(
      Test.t_testpackage,
      ":testpkg", "vx/web/http", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
