
namespace AppTest.TestVx.Translation;

public class EnTest {

  static Test.Type_testcase f_translation_en(Vx.Core.Type_context context) {
    Test.Type_testcase output = Vx.Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/translation/en",
      ":casename", "translation-en",
      ":describelist",
      Vx.Core.vx_new(
        Test.t_testdescribelist, 
        Vx.Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"Hello\"\n (trn/translate<-translation-string\n  (translation-en)\n  \"Hello\"))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("Hello"),
              Vx.Translate.f_translate_from_translation_string(
                Vx.Translation.En.f_translation_en(),
                Vx.Core.vx_new_string("Hello")
              )
            )
        )
      )
    );
    return output;
  }

  public static Test.Type_testcaselist test_cases(Vx.Core.Type_context context) {
    List<Vx.Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(
      EnTest.f_translation_en(context)
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
      ":testpkg", "vx/translation/en", 
      ":constnums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 5, ":total", 5), 
      ":funcnums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 20, ":tests", 1, ":total", 5), 
      ":bigospacenums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 5), 
      ":bigotimenums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 5), 
      ":totalnums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 20, ":tests", 1, ":total", 5), 
      ":typenums", Vx.Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Vx.Core.vx_new(Test.t_testcoveragedetail, ":testpkg", "vx/translation/en", ":typemap", Vx.Core.e_intmap, ":constmap", Vx.Core.e_intmap, ":funcmap", Vx.Core.vx_new(
  Vx.Core.t_intmap,
        ":context-en", 0,
        ":context-test", 0,
        ":securitydata-test", 0,
        ":translation-en", 1,
        ":words", 0
      ));
  }

  public static Test.Type_testpackage test_package(Vx.Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Vx.Core.vx_new(
      Test.t_testpackage,
      ":testpkg", "vx/translation/en", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
