'strict mode'

import vx_repl from "../../src/vx/repl.js"
import vx_core from "../../src/vx/core.js"
import vx_test from "../../src/vx/test.js"
import vx_type from "../../src/vx/type.js"
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
      "constnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 3), 
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 15, ":total", 15), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 22, ":tests", 2, ":total", 9), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 13, ":tests", 2, ":total", 15), 
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
          vx_core.t_intmap,
          "delimvxlisp", 0,
          "delimvxlispbracket", 0,
          "delimvxlispparen", 0
        ),
      "funcmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "any-repl<-functype-args", 0,
          "any<-liblist-string", 0,
          "any<-repl", 2,
          "any<-script", 0,
          "anylist<-repllist", 0,
          "macro", 0,
          "repl<-liblist-string", 0,
          "repl<-textblock", 0,
          "textblock-repl<-script", 1
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
              context,
              "HelloWorld",
              vx_repl.f_any_from_repl(
                context,
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
                )
              )
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n 5\n (any<-repl\n  (repl\n   :type +\n   :repllist\n    (repllist\n     (repl :val 2)\n     (repl :val 3)\n    ))))",
            ":testresult",
            vx_test.f_test(
              context,
              5,
              vx_repl.f_any_from_repl(
                context,
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
                )
              )
            )
          )
        )
    )
    return output
  }

  static f_textblock_repl_from_script(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "textblock-repl<-script",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (tb/textblock\n  :text \"(+ 2 3)\"\n  :startpos 1\n  :endpos 7\n  :children\n   (tb/textblocklist\n    (tb/textblock\n     :text \"(+ 2 3)\"\n     :startpos 1\n     :endpos 7\n     :delim\n      (copy delimvxlispparen\n       :delimlist\n        (empty delimlist))\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"+\"\n        :startpos 2\n        :endpos 2)\n       (tb/textblock\n        :text \" \"\n        :startpos 3\n        :endpos 3\n        :delim\n         (copy tb/delimwhitespace\n          :pos 0))\n       (tb/textblock\n        :text \"2\"\n        :startpos 4\n        :endpos 4)\n       (tb/textblock\n        :text \" \"\n        :startpos 5\n        :endpos 5\n        :delim\n         (copy tb/delimwhitespace\n          :pos 0))\n       (tb/textblock\n        :text \"3\"\n        :startpos 6\n        :endpos 6)))))\n (textblock-repl<-script\n  \"(+ 2 3)\"))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_data_textblock.t_textblock,
                ":text",
                "(+ 2 3)",
                ":startpos",
                1,
                ":endpos",
                7,
                ":children",
                vx_core.f_new(
                  vx_data_textblock.t_textblocklist,
                  vx_core.f_new(
                    vx_data_textblock.t_textblock,
                    ":text",
                    "(+ 2 3)",
                    ":startpos",
                    1,
                    ":endpos",
                    7,
                    ":delim",
                    vx_core.f_copy(
                      vx_repl.c_delimvxlispparen,
                      ":delimlist",
                      vx_core.f_empty(
                        vx_data_textblock.t_delimlist
                      )
                    ),
                    ":children",
                    vx_core.f_new(
                      vx_data_textblock.t_textblocklist,
                      vx_core.f_new(
                        vx_data_textblock.t_textblock,
                        ":text",
                        "+",
                        ":startpos",
                        2,
                        ":endpos",
                        2
                      ),
                      vx_core.f_new(
                        vx_data_textblock.t_textblock,
                        ":text",
                        " ",
                        ":startpos",
                        3,
                        ":endpos",
                        3,
                        ":delim",
                        vx_core.f_copy(
                          vx_data_textblock.c_delimwhitespace,
                          ":pos",
                          0
                        )
                      ),
                      vx_core.f_new(
                        vx_data_textblock.t_textblock,
                        ":text",
                        "2",
                        ":startpos",
                        4,
                        ":endpos",
                        4
                      ),
                      vx_core.f_new(
                        vx_data_textblock.t_textblock,
                        ":text",
                        " ",
                        ":startpos",
                        5,
                        ":endpos",
                        5,
                        ":delim",
                        vx_core.f_copy(
                          vx_data_textblock.c_delimwhitespace,
                          ":pos",
                          0
                        )
                      ),
                      vx_core.f_new(
                        vx_data_textblock.t_textblock,
                        ":text",
                        "3",
                        ":startpos",
                        6,
                        ":endpos",
                        6
                      )
                    )
                  )
                )
              ),
              vx_repl.f_textblock_repl_from_script("(+ 2 3)")
            )
          )
        )
    )
    return output
  }

  static test_cases(context) {
    const output = vx_core.f_new(
      vx_test.t_testcaselist,
      vx_repl_test.f_any_from_repl(context),
      vx_repl_test.f_textblock_repl_from_script(context)
    )
    return output
  }

}
