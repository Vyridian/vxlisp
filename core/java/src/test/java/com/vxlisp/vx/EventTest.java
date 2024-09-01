
package com.vxlisp.vx;

public final class EventTest {

  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {
    Test.Type_testcaselist output = Test.e_testcaselist;
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    Test.Type_testcoveragesummary output = Core.vx_new(
      Test.t_testcoveragesummary,
      ":testpkg", "vx/event", 
      ":constnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 4), 
      ":docnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 90, ":tests", 10, ":total", 11), 
      ":funcnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 4), 
      ":bigospacenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 4), 
      ":bigotimenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 4), 
      ":totalnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 11), 
      ":typenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 3)
    );
    return output;
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    Test.Type_testcoveragedetail output = Core.vx_new(
      Test.t_testcoveragedetail,
      ":testpkg", "vx/event",
      ":typemap", Core.vx_new(
        Core.t_intmap,
        ":event", 0,
        ":eventlist", 0,
        ":eventmap", 0
      ), 
      ":constmap", Core.vx_new(
        Core.t_intmap,
        ":event-change", 0,
        ":event-click", 0,
        ":event-move", 0,
        ":event-select", 0
      ), 
      ":funcmap", Core.vx_new(
        Core.t_intmap,
        ":any-from<-event", 0,
        ":event<-event", 0,
        ":event<-event-async", 0,
        ":eventmap<-eventlist", 0
      )
    );
    return output;
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Core.vx_new(
      Test.t_testpackage,
      ":testpkg", "vx/event", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
