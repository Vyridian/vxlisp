
package com.vxlisp.vx.translation;

import java.util.List;
import com.vxlisp.vx.*;

public final class AllTest {

  public static Test.Type_testcase f_translationmap_all(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/translation/all",
      ":casename", "translationmap-all",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        f_translationmap_all_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Test.Type_testdescribe f_translationmap_all_testdescribe_1(final Core.Type_context context) {
    Test.Type_testdescribe output = Core.vx_new(
      Test.t_testdescribe,
      ":describename", "(test\n \"Hola\"\n (trn/translate<-translationmap-name-string\n  (translationmap-all)\n  \"es\"\n  \"Hello\"))",
      ":testresult", Test.f_test(
        context,
        Core.vx_new_string("Hola"),
        Translate.f_translate_from_translationmap_name_string(
          All.f_translationmap_all(),
          Core.vx_new_string("es"),
          Core.vx_new_string("Hello")
        )
      )
    );
    return output;
  }

  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> testcases = Core.arraylist_from_array(
      AllTest.f_translationmap_all(context)
    );
    Test.Type_testcaselist output = Core.vx_new(
      Test.t_testcaselist,
      testcases
    );
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    Test.Type_testcoveragesummary output = Core.vx_new(
      Test.t_testcoveragesummary,
      ":testpkg", "vx/translation/all", 
      ":constnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 2, ":total", 2), 
      ":funcnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 50, ":tests", 1, ":total", 2), 
      ":bigospacenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 2), 
      ":bigotimenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 2), 
      ":totalnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 50, ":tests", 1, ":total", 2), 
      ":typenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0)
    );
    return output;
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    Test.Type_testcoveragedetail output = Core.vx_new(
      Test.t_testcoveragedetail,
      ":testpkg", "vx/translation/all",
      ":typemap", Core.e_intmap, 
      ":constmap", Core.e_intmap, 
      ":funcmap", Core.vx_new(
        Core.t_intmap,
        ":context-all", 0,
        ":translationmap-all", 1
      )
    );
    return output;
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Core.vx_new(
      Test.t_testpackage,
      ":testpkg", "vx/translation/all", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
