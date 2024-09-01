
namespace AppTest.TestVx.Data;

public class DbTest {

  public static Vx.Test.Type_testcaselist test_cases(Vx.Core.Type_context context) {
    Vx.Test.Type_testcaselist output = Vx.Test.e_testcaselist;
    return output;
  }

  public static Vx.Test.Type_testcoveragesummary test_coveragesummary() {
    Vx.Test.Type_testcoveragesummary output = Vx.Core.vx_new(
      Vx.Test.t_testcoveragesummary,
      ":testpkg", "vx/data/db", 
      ":constnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 100, ":tests", 12, ":total", 12), 
      ":funcnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":bigospacenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":bigotimenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":totalnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 12), 
      ":typenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 12)
    );
    return output;
  }

  public static Vx.Test.Type_testcoveragedetail test_coveragedetail() {
    Vx.Test.Type_testcoveragedetail output = Vx.Core.vx_new(
      Vx.Test.t_testcoveragedetail,
      ":testpkg", "vx/data/db",
      ":typemap", Vx.Core.vx_new(
        Vx.Core.t_intmap,
        ":db", 0,
        ":dbcell", 0,
        ":dbcellmap", 0,
        ":dbfield", 0,
        ":dbfieldmap", 0,
        ":dbid", 0,
        ":dblink", 0,
        ":dblinklist", 0,
        ":dbnode", 0,
        ":dbnote", 0,
        ":dbtable", 0,
        ":dbvalue", 0
      ), 
      ":constmap", Vx.Core.e_intmap, 
      ":funcmap", Vx.Core.e_intmap
    );
    return output;
  }

  public static Vx.Test.Type_testpackage test_package(Vx.Core.Type_context context) {
    Vx.Test.Type_testcaselist testcaselist = test_cases(context);
    Vx.Test.Type_testpackage output = Vx.Core.vx_new(
      Vx.Test.t_testpackage,
      ":testpkg", "vx/data/db", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
