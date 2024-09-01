
package com.vxlisp.vx;

public final class StateTest {

  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {
    Test.Type_testcaselist output = Test.e_testcaselist;
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    Test.Type_testcoveragesummary output = Core.vx_new(
      Test.t_testcoveragesummary,
      ":testpkg", "vx/state", 
      ":constnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 85, ":tests", 12, ":total", 14), 
      ":funcnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 13), 
      ":bigospacenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 13), 
      ":bigotimenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 13), 
      ":totalnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 14), 
      ":typenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 1)
    );
    return output;
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    Test.Type_testcoveragedetail output = Core.vx_new(
      Test.t_testcoveragedetail,
      ":testpkg", "vx/state",
      ":typemap", Core.vx_new(
        Core.t_intmap,
        ":valuemap", 0
      ), 
      ":constmap", Core.e_intmap, 
      ":funcmap", Core.vx_new(
        Core.t_intmap,
        ":any-readstate<-mapname-name", 0,
        ":any-readstate<-name", 0,
        ":boolean-removestate<-name", 0,
        ":boolean-writestate<-mapname-name-value", 0,
        ":boolean-writestate<-name-value", 0,
        ":boolean-writestate<-statelistener", 0,
        ":change", 0,
        ":register", 0,
        ":state<-context", 0,
        ":statelistener-readstate<-name", 0,
        ":statelistenermap-readstate", 0,
        ":value-readstate<-name", 0,
        ":valuemap-readstate<-mapname", 0
      )
    );
    return output;
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Core.vx_new(
      Test.t_testpackage,
      ":testpkg", "vx/state", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
