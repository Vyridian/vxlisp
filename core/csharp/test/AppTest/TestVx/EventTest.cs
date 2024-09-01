
namespace AppTest.TestVx;

public class EventTest {

  public static Vx.Test.Type_testcaselist test_cases(Vx.Core.Type_context context) {
    Vx.Test.Type_testcaselist output = Vx.Test.e_testcaselist;
    return output;
  }

  public static Vx.Test.Type_testcoveragesummary test_coveragesummary() {
    Vx.Test.Type_testcoveragesummary output = Vx.Core.vx_new(
      Vx.Test.t_testcoveragesummary,
      ":testpkg", "vx/event", 
      ":constnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 4), 
      ":docnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 90, ":tests", 10, ":total", 11), 
      ":funcnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 4), 
      ":bigospacenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 4), 
      ":bigotimenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 4), 
      ":totalnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 11), 
      ":typenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 3)
    );
    return output;
  }

  public static Vx.Test.Type_testcoveragedetail test_coveragedetail() {
    Vx.Test.Type_testcoveragedetail output = Vx.Core.vx_new(
      Vx.Test.t_testcoveragedetail,
      ":testpkg", "vx/event",
      ":typemap", Vx.Core.vx_new(
        Vx.Core.t_intmap,
        ":event", 0,
        ":eventlist", 0,
        ":eventmap", 0
      ), 
      ":constmap", Vx.Core.vx_new(
        Vx.Core.t_intmap,
        ":event-change", 0,
        ":event-click", 0,
        ":event-move", 0,
        ":event-select", 0
      ), 
      ":funcmap", Vx.Core.vx_new(
        Vx.Core.t_intmap,
        ":any-from<-event", 0,
        ":event<-event", 0,
        ":event<-event-async", 0,
        ":eventmap<-eventlist", 0
      )
    );
    return output;
  }

  public static Vx.Test.Type_testpackage test_package(Vx.Core.Type_context context) {
    Vx.Test.Type_testcaselist testcaselist = test_cases(context);
    Vx.Test.Type_testpackage output = Vx.Core.vx_new(
      Vx.Test.t_testpackage,
      ":testpkg", "vx/event", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
