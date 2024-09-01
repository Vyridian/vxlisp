
namespace AppTest.TestVx;

public class StateTest {

  public static Vx.Test.Type_testcaselist test_cases(Vx.Core.Type_context context) {
    Vx.Test.Type_testcaselist output = Vx.Test.e_testcaselist;
    return output;
  }

  public static Vx.Test.Type_testcoveragesummary test_coveragesummary() {
    Vx.Test.Type_testcoveragesummary output = Vx.Core.vx_new(
      Vx.Test.t_testcoveragesummary,
      ":testpkg", "vx/state", 
      ":constnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 85, ":tests", 12, ":total", 14), 
      ":funcnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 13), 
      ":bigospacenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 13), 
      ":bigotimenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 13), 
      ":totalnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 14), 
      ":typenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 1)
    );
    return output;
  }

  public static Vx.Test.Type_testcoveragedetail test_coveragedetail() {
    Vx.Test.Type_testcoveragedetail output = Vx.Core.vx_new(
      Vx.Test.t_testcoveragedetail,
      ":testpkg", "vx/state",
      ":typemap", Vx.Core.vx_new(
        Vx.Core.t_intmap,
        ":valuemap", 0
      ), 
      ":constmap", Vx.Core.e_intmap, 
      ":funcmap", Vx.Core.vx_new(
        Vx.Core.t_intmap,
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

  public static Vx.Test.Type_testpackage test_package(Vx.Core.Type_context context) {
    Vx.Test.Type_testcaselist testcaselist = test_cases(context);
    Vx.Test.Type_testpackage output = Vx.Core.vx_new(
      Vx.Test.t_testpackage,
      ":testpkg", "vx/state", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
