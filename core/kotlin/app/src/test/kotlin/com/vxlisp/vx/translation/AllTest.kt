
package com.vxlisp.vx.translation

import com.vxlisp.vx.*

object vx_translation_allTest {

  fun f_translationmap_all(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/translation/all",
      ":casename", "translationmap-all",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_translationmap_all_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_translationmap_all_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n \"Hola\"\n (trn/translate<-translationmap-name-string\n  (translationmap-all)\n  \"es\"\n  \"Hello\"))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.vx_new_string("Hola"),
        vx_translate.f_translate_from_translationmap_name_string(
          vx_translation_all.f_translationmap_all(),
          vx_core.vx_new_string("es"),
          vx_core.vx_new_string("Hello")
        )
      )
    )
    return output
  }

  fun test_cases(context : vx_core.Type_context) : vx_test.Type_testcaselist {
    var testcases : List<vx_core.Type_any> = vx_core.arraylist_from_array(
      vx_translation_allTest.f_translationmap_all(context)
    )
    var output : vx_test.Type_testcaselist = vx_core.vx_new(
      vx_test.t_testcaselist,
      testcases
    )
    return output
  }

  fun test_coveragesummary() : vx_test.Type_testcoveragesummary {
    var output : vx_test.Type_testcoveragesummary = vx_core.vx_new(
      vx_test.t_testcoveragesummary,
      ":testpkg", "vx/translation/all", 
      ":constnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 2, ":total", 2), 
      ":funcnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 50, ":tests", 1, ":total", 2), 
      ":bigospacenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 2), 
      ":bigotimenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 2), 
      ":totalnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 50, ":tests", 1, ":total", 2), 
      ":typenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0)
    )
    return output
  }

  fun test_coveragedetail() : vx_test.Type_testcoveragedetail {
    var output : vx_test.Type_testcoveragedetail = vx_core.vx_new(
      vx_test.t_testcoveragedetail,
      ":testpkg", "vx/translation/all",
      ":typemap", vx_core.e_intmap, 
      ":constmap", vx_core.e_intmap, 
      ":funcmap", vx_core.vx_new(
        vx_core.t_intmap,
        ":context-all", 0,
        ":translationmap-all", 1
      )
    )
    return output
  }

  fun test_package(context : vx_core.Type_context) : vx_test.Type_testpackage {
    var testcaselist : vx_test.Type_testcaselist = test_cases(context)
    var output : vx_test.Type_testpackage = vx_core.vx_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/translation/all", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    )
    return output
  }

}
