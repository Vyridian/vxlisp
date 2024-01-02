'strict mode'

import vx_translate from "../../src/vx/translate.js"
import vx_core from "../../src/vx/core.js"
import vx_test from "../../src/vx/test.js"
import vx_data_csv from "../../src/vx/data/csv.js"
import vx_data_file from "../../src/vx/data/file.js"

export default class vx_translate_test {


  static test_package(context) {
    const testcaselist = vx_translate_test.test_cases(context)
    const output = vx_core.f_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/translate",
      ":caselist", testcaselist,
      ":coveragesummary", vx_translate_test.test_coveragesummary(),
      ":coveragedetail", vx_translate_test.test_coveragedetail()
    );
    return output;
  }

  static test_coveragesummary() {
    return vx_core.f_new(
      vx_test.t_testcoveragesummary,
      "testpkg",   "vx/translate", 
      "constnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 11, ":total", 11), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 30, ":tests", 3, ":total", 10), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 30, ":tests", 3, ":total", 10), 
      "typenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0)
    )
  }

  static test_coveragedetail() {
    return vx_core.f_new(
      vx_test.t_testcoveragedetail,
      "testpkg", "vx/translate",
      "typemap",
        vx_core.f_new(
          vx_core.t_intmap
        ),
      "constmap",
        vx_core.f_new(
          vx_core.t_intmap
        ),
      "funcmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "session<-session-name", 0,
          "session<-session-translation", 0,
          "session<-session-translationmap-name", 0,
          "translate", 1,
          "translate_1", 1,
          "translate<-translation-string", 1,
          "translate<-translationmap-name-string", 0,
          "translation-load-session", 0,
          "translation<-context", 0,
          "translation<-session-name", 0,
          "translationmap<-translations", 0
        )
    )
  }

  static f_translate(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/translate",
      ":casename", "translate",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n \"!NotFound!\"\n (translate \"!NotFound!\"))",
            ":testresult",
            vx_test.f_test(
              context,
              "!NotFound!",
              vx_translate.f_translate(context, "!NotFound!")
            )
          )
        )
    )
    return output
  }

  static f_translate_1(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/translate",
      ":casename", "translate",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n \"Repl Type Not Found\"\n (translate\n  (msg\n   :path \"vx/repl/repl/repl<-string-argmap\"\n   :code \"repltypenotfound\")))",
            ":testresult",
            vx_test.f_test(
              context,
              "Repl Type Not Found",
              vx_translate.f_translate_1(
                context,
                vx_core.f_new(
                  vx_core.t_msg,
                  ":path",
                  "vx/repl/repl/repl<-string-argmap",
                  ":code",
                  "repltypenotfound"
                )
              )
            )
          )
        )
    )
    return output
  }

  static f_translate_from_translation_string(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/translate",
      ":casename", "translate<-translation-string",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n \"Hola\"\n (translate<-translation-string\n  (translation\n   :wordmap\n    (stringmap\n     \"Hello\" \"Hola\"))\n  \"Hello\"))",
            ":testresult",
            vx_test.f_test(
              context,
              "Hola",
              vx_translate.f_translate_from_translation_string(
                vx_core.f_new(
                  vx_core.t_translation,
                  ":wordmap",
                  vx_core.f_new(
                    vx_core.t_stringmap,
                    "Hello",
                    "Hola"
                  )
                ),
                "Hello"
              )
            )
          )
        )
    )
    return output
  }

  static test_cases(context) {
    const output = vx_core.f_new(
      vx_test.t_testcaselist,
      vx_translate_test.f_translate(context),
      vx_translate_test.f_translate_1(context),
      vx_translate_test.f_translate_from_translation_string(context)
    )
    return output
  }
}
