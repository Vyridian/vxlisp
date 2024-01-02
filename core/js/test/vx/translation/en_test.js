'strict mode'

import vx_translation_en from "../../../src/vx/translation/en.js"
import vx_core from "../../../src/vx/core.js"
import vx_test from "../../../src/vx/test.js"
import vx_data_file from "../../../src/vx/data/file.js"
import vx_translate from "../../../src/vx/translate.js"

export default class vx_translation_en_test {


  static test_package(context) {
    const testcaselist = vx_translation_en_test.test_cases(context)
    const output = vx_core.f_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/translation/en",
      ":caselist", testcaselist,
      ":coveragesummary", vx_translation_en_test.test_coveragesummary(),
      ":coveragedetail", vx_translation_en_test.test_coveragedetail()
    );
    return output;
  }

  static test_coveragesummary() {
    return vx_core.f_new(
      vx_test.t_testcoveragesummary,
      "testpkg",   "vx/translation/en", 
      "constnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 5, ":total", 5), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 20, ":tests", 1, ":total", 5), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 20, ":tests", 1, ":total", 5), 
      "typenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0)
    )
  }

  static test_coveragedetail() {
    return vx_core.f_new(
      vx_test.t_testcoveragedetail,
      "testpkg", "vx/translation/en",
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
          "context-en", 0,
          "context-test", 0,
          "securitydata-test", 0,
          "translation-en", 1,
          "words", 0
        )
    )
  }

  static f_translation_en(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/translation/en",
      ":casename", "translation-en",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n \"Hello\"\n (trn/translate<-translation-string\n  (translation-en)\n  \"Hello\"))",
            ":testresult",
            vx_test.f_test(
              context,
              "Hello",
              vx_translate.f_translate_from_translation_string(
                vx_translation_en.f_translation_en(),
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
      vx_translation_en_test.f_translation_en(context)
    )
    return output
  }
}
