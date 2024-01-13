
package com.vxlisp.vx;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import com.vxlisp.vx.data.*;

public final class TranslateTest {

  static Test.Type_testcase f_translate(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/translate",
      ":casename", "translate",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
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
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/translate",
      ":casename", "translate_1",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n \"Repl Type Not Found\"\n (translate\n  (msg\n   :path \"vx/repl/repl/repl<-string-argmap\"\n   :code \"repltypenotfound\")))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("Repl Type Not Found"),
              Translate.f_translate_1(
                context,
                Core.f_new(
                  Core.t_msg,
                  Core.t_anylist.vx_new(
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
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/translate",
      ":casename", "translate<-translation-string",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n \"Hola\"\n (translate<-translation-string\n  (translation\n   :wordmap\n    (stringmap\n     \"Hello\" \"Hola\"))\n  \"Hello\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("Hola"),
              Translate.f_translate_from_translation_string(
                Core.f_new(
                  Core.t_translation,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":wordmap"),
                    Core.f_new(
                      Core.t_stringmap,
                      Core.t_anylist.vx_new(
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
    List<Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(
      TranslateTest.f_translate(context),
      TranslateTest.f_translate_1(context),
      TranslateTest.f_translate_from_translation_string(context)
    ));
    Test.Type_testcaselist output = Test.t_testcaselist.vx_new(arraylisttestcase);
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    return Test.t_testcoveragesummary.vx_new(
      ":testpkg",   "vx/translate", 
      ":constnums", Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 11, ":total", 11), 
      ":funcnums", Test.t_testcoveragenums.vx_new(":pct", 30, ":tests", 3, ":total", 10), 
      ":bigospacenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 11), 
      ":bigotimenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 11), 
      ":totalnums", Test.t_testcoveragenums.vx_new(":pct", 30, ":tests", 3, ":total", 10), 
      ":typenums", Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 0, ":total", 0)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Test.t_testcoveragedetail.vx_new(
      ":testpkg", "vx/translate",
      ":typemap", Core.t_intmap.vx_new(
  
      ),
      ":constmap", Core.t_intmap.vx_new(
  
      ),
      ":funcmap", Core.t_intmap.vx_new(
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
      )
    );
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Test.t_testpackage.vx_new(
      ":testpkg", "vx/translate", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
