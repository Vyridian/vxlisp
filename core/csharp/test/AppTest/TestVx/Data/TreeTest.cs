
namespace AppTest.TestVx.Data;

public class TreeTest {

  public static Vx.Test.Type_testcaselist test_cases(Vx.Core.Type_context context) {
    Vx.Test.Type_testcaselist output = Vx.Test.e_testcaselist;
    return output;
  }

  public static Vx.Test.Type_testcoveragesummary test_coveragesummary() {
    Vx.Test.Type_testcoveragesummary output = Vx.Core.vx_new(
      Vx.Test.t_testcoveragesummary,
      ":testpkg", "vx/data/tree", 
      ":constnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 3), 
      ":docnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 9), 
      ":funcnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":bigospacenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":bigotimenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":totalnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 9), 
      ":typenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 6)
    );
    return output;
  }

  public static Vx.Test.Type_testcoveragedetail test_coveragedetail() {
    Vx.Test.Type_testcoveragedetail output = Vx.Core.vx_new(
      Vx.Test.t_testcoveragedetail,
      ":testpkg", "vx/data/tree",
      ":typemap", Vx.Core.vx_new(
        Vx.Core.t_intmap,
        ":branch", 0,
        ":brancharrow", 0,
        ":branchlist", 0,
        ":leaf", 0,
        ":leaflist", 0,
        ":tree", 0
      ), 
      ":constmap", Vx.Core.vx_new(
        Vx.Core.t_intmap,
        ":brancharrow-down", 0,
        ":brancharrow-up", 0,
        ":brancharrow-updown", 0
      ), 
      ":funcmap", Vx.Core.e_intmap
    );
    return output;
  }

  public static Vx.Test.Type_testpackage test_package(Vx.Core.Type_context context) {
    Vx.Test.Type_testcaselist testcaselist = test_cases(context);
    Vx.Test.Type_testpackage output = Vx.Core.vx_new(
      Vx.Test.t_testpackage,
      ":testpkg", "vx/data/tree", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
