'strict mode'

import vx_translation_es from "../../../src/vx/translation/es.js"
import vx_core from "../../../src/vx/core.js"
import vx_test from "../../../src/vx/test.js"
import vx_translate from "../../../src/vx/translate.js"

export default class vx_translation_es_test {

  static test_package(context) {
    const testcaselist = vx_translation_es_test.test_cases(context)
    const output = vx_core.f_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/translation/es",
      ":caselist", testcaselist,
      ":coveragesummary", vx_translation_es_test.test_coveragesummary(),
      ":coveragedetail", vx_translation_es_test.test_coveragedetail()
    );
    return output;
  }

  static test_coveragesummary() {
    return vx_core.f_new(
      vx_test.t_testcoveragesummary,
      "testpkg",   "vx/translation/es", 
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
      "testpkg", "vx/translation/es",
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
          "translation-es", 1,
          "words", 0
        )
    )
  }

  static f_translation_es(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/translation/es",
      ":casename", "translation-es",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n \"Hola\"\n (trn/translate<-translation-string\n  (translation-es)\n  \"Hello\"))",
            ":testresult",
            vx_test.f_test(
              context,
              "Hola",
              vx_translate.f_translate_from_translation_string(
                vx_translation_es.f_translation_es(),
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
      vx_translation_es_test.f_translation_es(context)
    )
    return output
  }

}
