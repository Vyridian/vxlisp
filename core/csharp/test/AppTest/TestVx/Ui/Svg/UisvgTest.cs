
namespace AppTest.TestVx.Ui.Svg;

public class UisvgTest {

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
      ":testpkg", "vx/ui/svg/uisvg", 
      ":constnums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":funcnums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":bigospacenums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":bigotimenums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":totalnums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":typenums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Vx.Core.vx_new(Test.t_testcoveragedetail, ":testpkg", "vx/ui/svg/uisvg", ":typemap", Vx.Core.e_intmap, ":constmap", Vx.Core.e_intmap, ":funcmap", Vx.Core.e_intmap);
  }

  public static Test.Type_testpackage test_package(Vx.Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Vx.Core.vx_new(
      Test.t_testpackage,
      ":testpkg", "vx/ui/svg/uisvg", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
