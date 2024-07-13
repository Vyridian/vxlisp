
namespace AppTest.TestVx;

public class EventTest {

  public static Test.Type_testcaselist test_cases(Vx.Core.Type_context context) {
    List<Vx.Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(
      
    ));
    Test.Type_testcaselist output = Vx.Core.vx_new(
      Test.t_testcaselist,
      arraylisttestcase
    );
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    return Vx.Core.vx_new(
      Test.t_testcoveragesummary,
      ":testpkg", "vx/event", 
      ":constnums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 4), 
      ":docnums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 90, ":tests", 10, ":total", 11), 
      ":funcnums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 4), 
      ":bigospacenums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 4), 
      ":bigotimenums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 4), 
      ":totalnums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 11), 
      ":typenums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 3)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Vx.Core.vx_new(Test.t_testcoveragedetail, ":testpkg", "vx/event", ":typemap", Vx.Core.vx_new(
  Vx.Core.t_intmap,
        ":event", 0,
        ":eventlist", 0,
        ":eventmap", 0
), ":constmap", Vx.Core.vx_new(
  Vx.Core.t_intmap,
        ":event-change", 0,
        ":event-click", 0,
        ":event-move", 0,
        ":event-select", 0
), ":funcmap", Vx.Core.vx_new(
  Vx.Core.t_intmap,
        ":any-from<-event", 0,
        ":event<-event", 0,
        ":event<-event-async", 0,
        ":eventmap<-eventlist", 0
      ));
  }

  public static Test.Type_testpackage test_package(Vx.Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Vx.Core.vx_new(
      Test.t_testpackage,
      ":testpkg", "vx/event", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
