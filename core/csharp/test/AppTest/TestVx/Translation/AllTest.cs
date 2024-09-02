
namespace AppTest.TestVx.Translation;

public class AllTest {

  public static Vx.Test.Type_testcase f_translationmap_all(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/translation/all",
      ":casename", "translationmap-all",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        f_translationmap_all_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_translationmap_all_testdescribe_1(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n \"Hola\"\n (trn/translate<-translationmap-name-string\n  (translationmap-all)\n  \"es\"\n  \"Hello\"))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.vx_new_string("Hola"),
        Vx.Translate.f_translate_from_translationmap_name_string(
          Vx.Translation.All.f_translationmap_all(),
          Vx.Core.vx_new_string("es"),
          Vx.Core.vx_new_string("Hello")
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcaselist test_cases(Vx.Core.Type_context context) {
    object[] testcases = [
      AllTest.f_translationmap_all(context)
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
      ":testpkg", "vx/translation/all", 
      ":constnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 100, ":tests", 2, ":total", 2), 
      ":funcnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 50, ":tests", 1, ":total", 2), 
      ":bigospacenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 2), 
      ":bigotimenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 2), 
      ":totalnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 50, ":tests", 1, ":total", 2), 
      ":typenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0)
    );
    return output;
  }

  public static Vx.Test.Type_testcoveragedetail test_coveragedetail() {
    Vx.Test.Type_testcoveragedetail output = Vx.Core.vx_new(
      Vx.Test.t_testcoveragedetail,
      ":testpkg", "vx/translation/all",
      ":typemap", Vx.Core.e_intmap, 
      ":constmap", Vx.Core.e_intmap, 
      ":funcmap", Vx.Core.vx_new(
        Vx.Core.t_intmap,
        ":context-all", 0,
        ":translationmap-all", 1
      )
    );
    return output;
  }

  public static Vx.Test.Type_testpackage test_package(Vx.Core.Type_context context) {
    Vx.Test.Type_testcaselist testcaselist = test_cases(context);
    Vx.Test.Type_testpackage output = Vx.Core.vx_new(
      Vx.Test.t_testpackage,
      ":testpkg", "vx/translation/all", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
