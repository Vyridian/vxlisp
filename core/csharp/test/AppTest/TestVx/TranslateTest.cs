
namespace AppTest.TestVx;

public class TranslateTest {

  static Vx.Test.Type_testcase f_translate(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/translate",
      ":casename", "translate",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"!NotFound!\"\n (translate \"!NotFound!\"))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("!NotFound!"),
              Vx.Translate.f_translate(context, Vx.Core.vx_new_string("!NotFound!"))
            )
        )
      )
    );
    return output;
  }

  static Vx.Test.Type_testcase f_translate_1(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/translate",
      ":casename", "translate_1",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"Repl Type Not Found\"\n (translate\n  (msg\n   :path \"vx/repl/repl/repl<-string-argmap\"\n   :code \"repltypenotfound\")))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("Repl Type Not Found"),
              Vx.Translate.f_translate_1(
                context,
                Vx.Core.f_new(
                  Vx.Core.t_msg,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":path"),
                    Vx.Core.vx_new_string("vx/repl/repl/repl<-string-argmap"),
                    Vx.Core.vx_new_string(":code"),
                    Vx.Core.vx_new_string("repltypenotfound")
                  )
                )
              )
            )
        )
      )
    );
    return output;
  }

  static Vx.Test.Type_testcase f_translate_from_translation_string(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/translate",
      ":casename", "translate<-translation-string",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"Hola\"\n (translate<-translation-string\n  (translation\n   :wordmap\n    (stringmap\n     \"Hello\" \"Hola\"))\n  \"Hello\"))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("Hola"),
              Vx.Translate.f_translate_from_translation_string(
                Vx.Core.f_new(
                  Vx.Core.t_translation,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":wordmap"),
                    Vx.Core.f_new(
                      Vx.Core.t_stringmap,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.vx_new_string("Hello"),
                        Vx.Core.vx_new_string("Hola")
                      )
                    )
                  )
                ),
                Vx.Core.vx_new_string("Hello")
              )
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcaselist test_cases(Vx.Core.Type_context context) {
    List<Vx.Core.Type_any> arraylisttestcase = Vx.Core.arraylist_from_array(
      TranslateTest.f_translate(context),
      TranslateTest.f_translate_1(context),
      TranslateTest.f_translate_from_translation_string(context)
    );
    Vx.Test.Type_testcaselist output = Vx.Core.vx_new(
      Vx.Test.t_testcaselist,
      arraylisttestcase
    );
    return output;
  }

  public static Vx.Test.Type_testcoveragesummary test_coveragesummary() {
    return Vx.Core.vx_new(
      Vx.Test.t_testcoveragesummary,
      ":testpkg", "vx/translate", 
      ":constnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 100, ":tests", 11, ":total", 11), 
      ":funcnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 30, ":tests", 3, ":total", 10), 
      ":bigospacenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 11), 
      ":bigotimenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 11), 
      ":totalnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 30, ":tests", 3, ":total", 10), 
      ":typenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0)
    );
  }

  public static Vx.Test.Type_testcoveragedetail test_coveragedetail() {
    return Vx.Core.vx_new(Vx.Test.t_testcoveragedetail, ":testpkg", "vx/translate", ":typemap", Vx.Core.e_intmap, ":constmap", Vx.Core.e_intmap, ":funcmap", Vx.Core.vx_new(
  Vx.Core.t_intmap,
        ":session<-session-name", 0,
        ":session<-session-translation", 0,
        ":session<-session-translationmap-name", 0,
        ":translate", 1,
        ":translate_1", 1,
        ":translate<-translation-string", 1,
        ":translate<-translationmap-name-string", 0,
        ":translation-load-session", 0,
        ":translation<-context", 0,
        ":translation<-session-name", 0,
        ":translationmap<-translations", 0
      ));
  }

  public static Vx.Test.Type_testpackage test_package(Vx.Core.Type_context context) {
    Vx.Test.Type_testcaselist testcaselist = test_cases(context);
    Vx.Test.Type_testpackage output = Vx.Core.vx_new(
      Vx.Test.t_testpackage,
      ":testpkg", "vx/translate", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
