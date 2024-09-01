
namespace AppTest.TestVx;

public class SampleTest {

  public static Vx.Test.Type_testcase c_myconst(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/sample",
      ":casename", "myconst",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n myconst\n myconst)",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Sample.c_myconst,
              Vx.Sample.c_myconst
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_myfunc(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/sample",
      ":casename", "myfunc",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test 5 (myfunc 1))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_int(5),
              Vx.Sample.f_myfunc(
                Vx.Core.vx_new_int(1)
              )
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcaselist test_cases(Vx.Core.Type_context context) {
    object[] testcases = [
      SampleTest.c_myconst(context),
      SampleTest.f_myfunc(context)
    ];
    Vx.Test.Type_testcaselist output = Vx.Core.vx_new(
      Vx.Test.t_testcaselist,
      testcases
    );
    return output;
  }

  public static Vx.Test.Type_testcoveragesummary test_coveragesummary() {
    Vx.Test.Type_testcoveragesummary output = Vx.Core.vx_new(
      Vx.Test.t_testcoveragesummary,
      ":testpkg", "vx/sample", 
      ":constnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 100, ":tests", 1, ":total", 1), 
      ":docnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 50, ":tests", 2, ":total", 4), 
      ":funcnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 50, ":tests", 1, ":total", 2), 
      ":bigospacenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 2), 
      ":bigotimenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 2), 
      ":totalnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 50, ":tests", 2, ":total", 4), 
      ":typenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 1)
    );
    return output;
  }

  public static Vx.Test.Type_testcoveragedetail test_coveragedetail() {
    Vx.Test.Type_testcoveragedetail output = Vx.Core.vx_new(
      Vx.Test.t_testcoveragedetail,
      ":testpkg", "vx/sample",
      ":typemap", Vx.Core.vx_new(
        Vx.Core.t_intmap,
        ":mytype", 0
      ), 
      ":constmap", Vx.Core.vx_new(
        Vx.Core.t_intmap,
        ":myconst", 1
      ), 
      ":funcmap", Vx.Core.vx_new(
        Vx.Core.t_intmap,
        ":main", 0,
        ":myfunc", 1
      )
    );
    return output;
  }

  public static Vx.Test.Type_testpackage test_package(Vx.Core.Type_context context) {
    Vx.Test.Type_testcaselist testcaselist = test_cases(context);
    Vx.Test.Type_testpackage output = Vx.Core.vx_new(
      Vx.Test.t_testpackage,
      ":testpkg", "vx/sample", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
