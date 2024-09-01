
package com.vxlisp.vx.translation

import com.vxlisp.vx.*

object vx_translation_esTest {

  fun f_translation_es(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/translation/es",
      ":casename", "translation-es",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n \"Hola\"\n (trn/translate<-translation-string\n  (translation-es)\n  \"Hello\"))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_string("Hola"),
              vx_translate.f_translate_from_translation_string(
                vx_translation_es.f_translation_es(),
                vx_core.vx_new_string("Hello")
              )
            )
        )
      )
    )
    return output
  }

  fun test_cases(context : vx_core.Type_context) : vx_test.Type_testcaselist {
    var testcases : List<vx_core.Type_any> = vx_core.arraylist_from_array(
      vx_translation_esTest.f_translation_es(context)
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
      ":testpkg", "vx/translation/es", 
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
      ":testpkg", "vx/translation/es",
      ":typemap", vx_core.e_intmap, 
      ":constmap", vx_core.e_intmap, 
      ":funcmap", vx_core.vx_new(
        vx_core.t_intmap,
        ":translation-es", 1,
        ":words", 0
      )
    )
    return output
  }

  fun test_package(context : vx_core.Type_context) : vx_test.Type_testpackage {
    var testcaselist : vx_test.Type_testcaselist = test_cases(context)
    var output : vx_test.Type_testpackage = vx_core.vx_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/translation/es", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    )
    return output
  }

}
