
package com.vxlisp.vx

import com.vxlisp.vx.data.*

object vx_translateTest {

  fun f_translate(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/translate",
      ":casename", "translate",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_translate_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_translate_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n \"!NotFound!\"\n (translate \"!NotFound!\"))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.vx_new_string("!NotFound!"),
        vx_translate.f_translate(
          context,
          vx_core.vx_new_string("!NotFound!")
        )
      )
    )
    return output
  }

  fun f_translate_1(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/translate",
      ":casename", "translate_1",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_translate_1_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_translate_1_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n \"Repl Type Not Found\"\n (translate\n  (msg\n   :path \"vx/repl/repl/repl<-string-argmap\"\n   :code \"repltypenotfound\")))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.vx_new_string("Repl Type Not Found"),
        vx_translate.f_translate_1(
          context,
          vx_core.f_new(
            vx_core.t_msg,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":path"),
              vx_core.vx_new_string("vx/repl/repl/repl<-string-argmap"),
              vx_core.vx_new_string(":code"),
              vx_core.vx_new_string("repltypenotfound")
            )
          )
        )
      )
    )
    return output
  }

  fun f_translate_from_translation_string(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/translate",
      ":casename", "translate<-translation-string",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_translate_from_translation_string_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_translate_from_translation_string_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n \"Hola\"\n (translate<-translation-string\n  (translation\n   :wordmap\n    (stringmap\n     \"Hello\" \"Hola\"))\n  \"Hello\"))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.vx_new_string("Hola"),
        vx_translate.f_translate_from_translation_string(
          vx_core.f_new(
            vx_core.t_translation,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":wordmap"),
              vx_core.f_new(
                vx_core.t_stringmap,
                vx_core.vx_new(
                  vx_core.t_anylist,
                  vx_core.vx_new_string("Hello"),
                  vx_core.vx_new_string("Hola")
                )
              )
            )
          ),
          vx_core.vx_new_string("Hello")
        )
      )
    )
    return output
  }

  fun test_cases(context : vx_core.Type_context) : vx_test.Type_testcaselist {
    var testcases : List<vx_core.Type_any> = vx_core.arraylist_from_array(
      vx_translateTest.f_translate(context),
      vx_translateTest.f_translate_1(context),
      vx_translateTest.f_translate_from_translation_string(context)
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
      ":testpkg", "vx/translate", 
      ":constnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 11, ":total", 11), 
      ":funcnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 30, ":tests", 3, ":total", 10), 
      ":bigospacenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 11), 
      ":bigotimenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 11), 
      ":totalnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 30, ":tests", 3, ":total", 10), 
      ":typenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0)
    )
    return output
  }

  fun test_coveragedetail() : vx_test.Type_testcoveragedetail {
    var output : vx_test.Type_testcoveragedetail = vx_core.vx_new(
      vx_test.t_testcoveragedetail,
      ":testpkg", "vx/translate",
      ":typemap", vx_core.e_intmap, 
      ":constmap", vx_core.e_intmap, 
      ":funcmap", vx_core.vx_new(
        vx_core.t_intmap,
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
    )
    return output
  }

  fun test_package(context : vx_core.Type_context) : vx_test.Type_testpackage {
    var testcaselist : vx_test.Type_testcaselist = test_cases(context)
    var output : vx_test.Type_testpackage = vx_core.vx_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/translate", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    )
    return output
  }

}
