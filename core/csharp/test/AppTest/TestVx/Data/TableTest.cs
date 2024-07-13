
namespace AppTest.TestVx.Data;

public class TableTest {

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
      ":testpkg", "vx/data/table", 
      ":constnums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 12), 
      ":funcnums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":bigospacenums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":bigotimenums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":totalnums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 12), 
      ":typenums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 12)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Vx.Core.vx_new(Test.t_testcoveragedetail, ":testpkg", "vx/data/table", ":typemap", Vx.Core.vx_new(
  Vx.Core.t_intmap,
        ":cell", 0,
        ":celllist", 0,
        ":cellmap", 0,
        ":field", 0,
        ":fieldlist", 0,
        ":fieldmap", 0,
        ":filter", 0,
        ":row", 0,
        ":rowlist", 0,
        ":rowmap", 0,
        ":sort", 0,
        ":table", 0
), ":constmap", Vx.Core.e_intmap, ":funcmap", Vx.Core.e_intmap);
  }

  public static Test.Type_testpackage test_package(Vx.Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Vx.Core.vx_new(
      Test.t_testpackage,
      ":testpkg", "vx/data/table", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
