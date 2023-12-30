'strict mode'

import vx_translation_all from "../../../src/vx/translation/all.js"
import vx_core from "../../../src/vx/core.js"
import vx_test from "../../../src/vx/test.js"
import vx_translate from "../../../src/vx/translate.js"
import vx_translation_en from "../../../src/vx/translation/en.js"
import vx_translation_es from "../../../src/vx/translation/es.js"

export default class vx_translation_all_test {

  static test_package(context) {
    const testcaselist = vx_translation_all_test.test_cases(context)
    const output = vx_core.f_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/translation/all",
      ":caselist", testcaselist,
      ":coveragesummary", vx_translation_all_test.test_coveragesummary(),
      ":coveragedetail", vx_translation_all_test.test_coveragedetail()
    );
    return output;
  }

  static test_coveragesummary() {
    return vx_core.f_new(
      vx_test.t_testcoveragesummary,
      "testpkg",   "vx/translation/all", 
      "constnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 2, ":total", 2), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 50, ":tests", 1, ":total", 2), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 50, ":tests", 1, ":total", 2), 
      "typenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0)
    )
  }

  static test_coveragedetail() {
    return vx_core.f_new(
      vx_test.t_testcoveragedetail,
      "testpkg", "vx/translation/all",
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
          "context-all", 0,
          "translationmap-all", 1
        )
    )
  }

  static f_translationmap_all(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/translation/all",
      ":casename", "translationmap-all",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n \"Hola\"\n (trn/translate<-translationmap-name-string\n  (translationmap-all)\n  \"es\"\n  \"Hello\"))",
            ":testresult",
            vx_test.f_test(
              context,
              "Hola",
              vx_translate.f_translate_from_translationmap_name_string(
                vx_translation_all.f_translationmap_all(),
                "es",
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
      vx_translation_all_test.f_translationmap_all(context)
    )
    return output
  }

}
