'strict mode'

import vx_repl from "../../src/vx/repl.js"
import vx_core from "../../src/vx/core.js"
import vx_test from "../../src/vx/test.js"
import vx_data_textblock from "../../src/vx/data/textblock.js"

export default class vx_repl_test {

  static test_package(context) {
    const testcaselist = vx_repl_test.test_cases(context)
    const output = vx_core.f_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/repl",
      ":caselist", testcaselist,
      ":coveragesummary", vx_repl_test.test_coveragesummary(),
      ":coveragedetail", vx_repl_test.test_coveragedetail()
    );
    return output;
  }

  static test_coveragesummary() {
    return vx_core.f_new(
      vx_test.t_testcoveragesummary,
      "testpkg",   "vx/repl", 
      "constnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 10, ":total", 10), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 14, ":tests", 1, ":total", 7), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 10, ":tests", 1, ":total", 10), 
      "typenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 3)
    )
  }

  static test_coveragedetail() {
    return vx_core.f_new(
      vx_test.t_testcoveragedetail,
      "testpkg", "vx/repl",
      "typemap",
        vx_core.f_new(
          vx_core.t_intmap,
          "liblist", 0,
          "repl", 0,
          "repllist", 0
        ),
      "constmap",
        vx_core.f_new(
          vx_core.t_intmap
        ),
      "funcmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "any-repl<-functype-args", 0,
          "any<-liblist-string", 0,
          "any<-liblist-string-async", 0,
          "any<-repl", 2,
          "any<-repl-async", 0,
          "anylist<-repllist", 0,
          "repl<-liblist-string", 0
        )
    )
  }

  static f_any_from_repl(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "any<-repl",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n \"HelloWorld\"\n (any<-repl\n  (repl\n   :type string\n   :repllist\n    (repllist\n     (repl :val \"Hello\")\n     (repl :val \"World\")\n    ))))",
            ":testresult",
            vx_test.f_test(
              "HelloWorld",
              vx_repl.f_any_from_repl(
                vx_core.f_new(
                  vx_repl.t_repl,
                  ":type",
                  vx_core.t_string,
                  ":repllist",
                  vx_core.f_new(
                    vx_repl.t_repllist,
                    vx_core.f_new(
                      vx_repl.t_repl,
                      ":val",
                      "Hello"
                    ),
                    vx_core.f_new(
                      vx_repl.t_repl,
                      ":val",
                      "World"
                    )
                  )
                ),
                context
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n 5\n (any<-repl\n  (repl\n   :type +\n   :repllist\n    (repllist\n     (repl :val 2)\n     (repl :val 3)\n    ))))",
            ":testresult",
            vx_test.f_test(
              5,
              vx_repl.f_any_from_repl(
                vx_core.f_new(
                  vx_repl.t_repl,
                  ":type",
                  vx_core.t_plus,
                  ":repllist",
                  vx_core.f_new(
                    vx_repl.t_repllist,
                    vx_core.f_new(
                      vx_repl.t_repl,
                      ":val",
                      2
                    ),
                    vx_core.f_new(
                      vx_repl.t_repl,
                      ":val",
                      3
                    )
                  )
                ),
                context
              ),
              context
            )
          )
        )
    )
    return output
  }

  static test_cases(context) {
    const output = vx_core.f_new(
      vx_test.t_testcaselist,
      vx_repl_test.f_any_from_repl(context)
    )
    return output
  }

}
