
package com.vxlisp.vx;

import java.util.List;
import com.vxlisp.vx.data.*;

public final class TranslateTest {

  static Test.Type_testcase f_translate(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/translate",
      ":casename", "translate",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"!NotFound!\"\n (translate \"!NotFound!\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("!NotFound!"),
              Translate.f_translate(context, Core.vx_new_string("!NotFound!"))
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_translate_1(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/translate",
      ":casename", "translate_1",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"Repl Type Not Found\"\n (translate\n  (msg\n   :path \"vx/repl/repl/repl<-string-argmap\"\n   :code \"repltypenotfound\")))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("Repl Type Not Found"),
              Translate.f_translate_1(
                context,
                Core.f_new(
                  Core.t_msg,
                  Core.vx_new(Core.t_anylist,
                    Core.vx_new_string(":path"),
                    Core.vx_new_string("vx/repl/repl/repl<-string-argmap"),
                    Core.vx_new_string(":code"),
                    Core.vx_new_string("repltypenotfound")
                  )
                )
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_translate_from_translation_string(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/translate",
      ":casename", "translate<-translation-string",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"Hola\"\n (translate<-translation-string\n  (translation\n   :wordmap\n    (stringmap\n     \"Hello\" \"Hola\"))\n  \"Hello\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("Hola"),
              Translate.f_translate_from_translation_string(
                Core.f_new(
                  Core.t_translation,
                  Core.vx_new(Core.t_anylist,
                    Core.vx_new_string(":wordmap"),
                    Core.f_new(
                      Core.t_stringmap,
                      Core.vx_new(Core.t_anylist,
                        Core.vx_new_string("Hello"),
                        Core.vx_new_string("Hola")
                      )
                    )
                  )
                ),
                Core.vx_new_string("Hello")
              )
            )
        )
      )
    );
    return output;
  }

  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> arraylisttestcase = Core.arraylist_from_array(
      TranslateTest.f_translate(context),
      TranslateTest.f_translate_1(context),
      TranslateTest.f_translate_from_translation_string(context)
    );
    Test.Type_testcaselist output = Core.vx_new(
      Test.t_testcaselist,
      arraylisttestcase
    );
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    return Core.vx_new(
      Test.t_testcoveragesummary,
      ":testpkg", "vx/translate", 
      ":constnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 11, ":total", 11), 
      ":funcnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 30, ":tests", 3, ":total", 10), 
      ":bigospacenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 11), 
      ":bigotimenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 11), 
      ":totalnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 30, ":tests", 3, ":total", 10), 
      ":typenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Core.vx_new(Test.t_testcoveragedetail, ":testpkg", "vx/translate", ":typemap", Core.e_intmap, ":constmap", Core.e_intmap, ":funcmap", Core.vx_new(
  Core.t_intmap,
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

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Core.vx_new(
      Test.t_testpackage,
      ":testpkg", "vx/translate", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
