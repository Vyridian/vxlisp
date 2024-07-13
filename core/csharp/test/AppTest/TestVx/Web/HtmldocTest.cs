
namespace AppTest.TestVx.Web;

public class HtmldocTest {

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
      ":testpkg", "vx/web/htmldoc", 
      ":constnums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 15, ":total", 15), 
      ":funcnums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 15), 
      ":bigospacenums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 15), 
      ":bigotimenums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 15), 
      ":totalnums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 15), 
      ":typenums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Vx.Core.vx_new(Test.t_testcoveragedetail, ":testpkg", "vx/web/htmldoc", ":typemap", Vx.Core.e_intmap, ":constmap", Vx.Core.e_intmap, ":funcmap", Vx.Core.vx_new(
  Vx.Core.t_intmap,
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

  public static Test.Type_testpackage test_package(Vx.Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Vx.Core.vx_new(
      Test.t_testpackage,
      ":testpkg", "vx/web/htmldoc", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
