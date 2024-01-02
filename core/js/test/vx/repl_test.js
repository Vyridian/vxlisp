'strict mode'

import vx_repl from "../../src/vx/repl.js"
import vx_core from "../../src/vx/core.js"
import vx_test from "../../src/vx/test.js"
import vx_collection from "../../src/vx/collection.js"
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
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 28, ":total", 28), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 61, ":tests", 13, ":total", 21), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 46, ":tests", 13, ":total", 28), 
      "typenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 4)
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
          "replarglist", 0,
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
          "any<-macro", 1,
          "any<-repl", 2,
          "any<-script", 1,
          "anylist<-repllist", 0,
          "argmap<-textblock-argmap", 0,
          "const<-string", 2,
          "repl-bracket<-textblock-argmap", 0,
          "repl-empty<-textblock-argmap", 4,
          "repl-paren<-textblock-argmap", 1,
          "repl<-liblist-string", 0,
          "repl<-macro", 1,
          "repl<-script", 4,
          "repl<-string-argmap", 7,
          "repl<-textblock", 5,
          "repl<-textblock-argmap", 4,
          "replarglist<-replarglist-textblock-argmap", 0,
          "repllist<-textblocklist-argmap", 0,
          "textblock<-script", 2,
          "typefunc<-string", 2
        )
    )
  }

  static f_any_from_macro(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "any<-macro",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n 5\n (any<-macro : int\n  \"(+ \"\n  (- 7 5)\n  \" 3)\"))",
            ":testresult",
            vx_test.f_test(
              context,
              5,
              vx_repl.f_any_from_macro(
                {"any-1": vx_core.t_int},
                context,
                "(+ ",
                vx_core.f_minus(7, 5),
                " 3)"
              )
            )
          )
        )
    )
    return output
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
            ":describename", "(test\n 5\n (any<-repl\n  (repl\n   :type +\n   :repllist\n    (repllist\n     (repl :val 2)\n     (repl :val 3)))))",
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

  static f_any_from_script(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "any<-script",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n 5\n (any<-script\n  \"(+ 2 3)\"))",
            ":testresult",
            vx_test.f_test(
              context,
              5,
              vx_repl.f_any_from_script(context, "(+ 2 3)")
            )
          )
        )
    )
    return output
  }

  static f_const_from_string(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "const<-string",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n infinity\n (const<-string\n  \"infinity\"))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.c_infinity,
              vx_repl.f_const_from_string("infinity")
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n tb/delimcomma\n (const<-string\n  \"vx/data/textblock/delimcomma\"))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_data_textblock.c_delimcomma,
              vx_repl.f_const_from_string("vx/data/textblock/delimcomma")
            )
          )
        )
    )
    return output
  }

  static f_repl_empty_from_textblock_argmap(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl-empty<-textblock-argmap",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl :val 2)\n (repl-empty<-textblock-argmap\n  (tb/textblock\n   :text \"2\")\n  (empty argmap)))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_repl.t_repl,
                ":val",
                2
              ),
              vx_repl.f_repl_empty_from_textblock_argmap(
                vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  ":text",
                  "2"
                ),
                vx_core.f_empty(
                  vx_core.t_argmap
                )
              )
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl :type +)\n (repl-empty<-textblock-argmap\n  (tb/textblock\n   :text \"+\")\n  (empty argmap)))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_repl.t_repl,
                ":type",
                vx_core.t_plus
              ),
              vx_repl.f_repl_empty_from_textblock_argmap(
                vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  ":text",
                  "+"
                ),
                vx_core.f_empty(
                  vx_core.t_argmap
                )
              )
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl :val 2)\n (repl-empty<-textblock-argmap\n  (tb/textblock\n   :text \"1\"\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"2\")))\n  (empty argmap)))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_repl.t_repl,
                ":val",
                2
              ),
              vx_repl.f_repl_empty_from_textblock_argmap(
                vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  ":text",
                  "1",
                  ":children",
                  vx_core.f_new(
                    vx_data_textblock.t_textblocklist,
                    vx_core.f_new(
                      vx_data_textblock.t_textblock,
                      ":text",
                      "2"
                    )
                  )
                ),
                vx_core.f_empty(
                  vx_core.t_argmap
                )
              )
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl\n  (msg<-error \"Empty delim cannot have more than one child.\"))\n (repl-empty<-textblock-argmap\n  (tb/textblock\n   :text \"1\"\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"2\")\n     (tb/textblock\n      :text \"3\")))\n  (empty argmap)))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_repl.t_repl,
                vx_core.f_msg_from_error("Empty delim cannot have more than one child.")
              ),
              vx_repl.f_repl_empty_from_textblock_argmap(
                vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  ":text",
                  "1",
                  ":children",
                  vx_core.f_new(
                    vx_data_textblock.t_textblocklist,
                    vx_core.f_new(
                      vx_data_textblock.t_textblock,
                      ":text",
                      "2"
                    ),
                    vx_core.f_new(
                      vx_data_textblock.t_textblock,
                      ":text",
                      "3"
                    )
                  )
                ),
                vx_core.f_empty(
                  vx_core.t_argmap
                )
              )
            )
          )
        )
    )
    return output
  }

  static f_repl_paren_from_textblock_argmap(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl-paren<-textblock-argmap",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl\n  :type vx/core/+\n  :repllist\n   (repllist\n    (repl\n     :val 2)\n    (repl\n     :val 3)))\n (repl-paren<-textblock-argmap\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :delim\n    (copy delimvxlispparen\n     :delimlist\n      (empty delimlist))\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"+\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"2\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"3\")))\n  (empty argmap)))",
            ":testresult",
            vx_test.f_test(
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
              ),
              vx_repl.f_repl_paren_from_textblock_argmap(
                vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  ":text",
                  "(+ 2 3)",
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
                      "+"
                    ),
                    vx_core.f_new(
                      vx_data_textblock.t_textblock,
                      ":text",
                      " ",
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
                      "2"
                    ),
                    vx_core.f_new(
                      vx_data_textblock.t_textblock,
                      ":text",
                      " ",
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
                      "3"
                    )
                  )
                ),
                vx_core.f_empty(
                  vx_core.t_argmap
                )
              )
            )
          )
        )
    )
    return output
  }

  static f_repl_from_macro(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl<-macro",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl\n  :type vx/core/+\n  :repllist\n   (repllist\n    (repl\n     :val 2)\n    (repl\n     :val 3)))\n (repl<-macro\n  \"(+ \"\n  (- 7 5)\n  \" 3)\"))",
            ":testresult",
            vx_test.f_test(
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
              ),
              vx_repl.f_repl_from_macro(
                context,
                "(+ ",
                vx_core.f_minus(7, 5),
                " 3)"
              )
            )
          )
        )
    )
    return output
  }

  static f_repl_from_script(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl<-script",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl\n  :val 2)\n (repl<-script\n  \"2\"))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_repl.t_repl,
                ":val",
                2
              ),
              vx_repl.f_repl_from_script("2")
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl\n  :val infinity)\n (repl<-script\n  \"infinity\"))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_repl.t_repl,
                ":val",
                vx_core.c_infinity
              ),
              vx_repl.f_repl_from_script("infinity")
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl\n  :type +)\n (repl<-script\n  \"+\"))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_repl.t_repl,
                ":type",
                vx_core.t_plus
              ),
              vx_repl.f_repl_from_script("+")
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl\n     :val 2)\n    (repl\n     :val 3)))\n (repl<-script\n  \"(+ 2 3)\"))",
            ":testresult",
            vx_test.f_test(
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
              ),
              vx_repl.f_repl_from_script("(+ 2 3)")
            )
          )
        )
    )
    return output
  }

  static f_repl_from_string_argmap(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl<-string-argmap",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl :val \"Hello\")\n (repl<-string-argmap\n  `\"Hello\"`\n  (empty argmap)))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_repl.t_repl,
                ":val",
                "Hello"
              ),
              vx_repl.f_repl_from_string_argmap(
                "\"Hello\"",
                vx_core.f_empty(
                  vx_core.t_argmap
                )
              )
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl\n  :val 2)\n (repl<-string-argmap\n  \"2\"\n  (empty argmap)))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_repl.t_repl,
                ":val",
                2
              ),
              vx_repl.f_repl_from_string_argmap(
                "2",
                vx_core.f_empty(
                  vx_core.t_argmap
                )
              )
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl :val 2.3)\n (repl<-string-argmap\n  \"2.3\"\n  (empty argmap)))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_repl.t_repl,
                ":val",
                2.3
              ),
              vx_repl.f_repl_from_string_argmap(
                "2.3",
                vx_core.f_empty(
                  vx_core.t_argmap
                )
              )
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl\n  :val infinity)\n (repl<-string-argmap\n  \"infinity\"\n  (empty argmap)))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_repl.t_repl,
                ":val",
                vx_core.c_infinity
              ),
              vx_repl.f_repl_from_string_argmap(
                "infinity",
                vx_core.f_empty(
                  vx_core.t_argmap
                )
              )
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl\n  :val tb/delimcomma)\n (repl<-string-argmap\n  \"vx/data/textblock/delimcomma\"\n  (empty argmap)))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_repl.t_repl,
                ":val",
                vx_data_textblock.c_delimcomma
              ),
              vx_repl.f_repl_from_string_argmap(
                "vx/data/textblock/delimcomma",
                vx_core.f_empty(
                  vx_core.t_argmap
                )
              )
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl :type string)\n (repl<-string-argmap\n  \"string\"\n  (empty argmap)))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_repl.t_repl,
                ":type",
                vx_core.t_string
              ),
              vx_repl.f_repl_from_string_argmap(
                "string",
                vx_core.f_empty(
                  vx_core.t_argmap
                )
              )
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl :type +)\n (repl<-string-argmap\n  \"+\"\n  (empty argmap)))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_repl.t_repl,
                ":type",
                vx_core.t_plus
              ),
              vx_repl.f_repl_from_string_argmap(
                "+",
                vx_core.f_empty(
                  vx_core.t_argmap
                )
              )
            )
          )
        )
    )
    return output
  }

  static f_repl_from_textblock(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl<-textblock",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl :val 2)\n (repl<-textblock\n  (tb/textblock\n   :text \"2\")))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_repl.t_repl,
                ":val",
                2
              ),
              vx_repl.f_repl_from_textblock(
                vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  ":text",
                  "2"
                )
              )
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl :type +)\n (repl<-textblock\n  (tb/textblock\n   :text \"+\")))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_repl.t_repl,
                ":type",
                vx_core.t_plus
              ),
              vx_repl.f_repl_from_textblock(
                vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  ":text",
                  "+"
                )
              )
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl :type +)\n (repl<-textblock\n  (tb/textblock\n   :text \"+\")))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_repl.t_repl,
                ":type",
                vx_core.t_plus
              ),
              vx_repl.f_repl_from_textblock(
                vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  ":text",
                  "+"
                )
              )
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl :val 2)\n    (repl :val 3)))\n (repl<-textblock\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :delim\n    (copy delimvxlispparen\n     :delimlist\n      (empty delimlist))\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"+\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"2\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"3\")))))",
            ":testresult",
            vx_test.f_test(
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
              ),
              vx_repl.f_repl_from_textblock(
                vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  ":text",
                  "(+ 2 3)",
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
                      "+"
                    ),
                    vx_core.f_new(
                      vx_data_textblock.t_textblock,
                      ":text",
                      " ",
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
                      "2"
                    ),
                    vx_core.f_new(
                      vx_data_textblock.t_textblock,
                      ":text",
                      " ",
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
                      "3"
                    )
                  )
                )
              )
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl :val 2)\n    (repl :val 3)))\n (repl<-textblock\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"(+ 2 3)\"\n      :delim\n       (copy delimvxlispparen\n        :delimlist\n         (empty delimlist))\n      :children\n       (tb/textblocklist\n        (tb/textblock\n         :text \"+\")\n        (tb/textblock\n         :text \" \"\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"2\")\n        (tb/textblock\n         :text \" \"\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"3\")))))))",
            ":testresult",
            vx_test.f_test(
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
              ),
              vx_repl.f_repl_from_textblock(
                vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  ":text",
                  "(+ 2 3)",
                  ":children",
                  vx_core.f_new(
                    vx_data_textblock.t_textblocklist,
                    vx_core.f_new(
                      vx_data_textblock.t_textblock,
                      ":text",
                      "(+ 2 3)",
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
                          "+"
                        ),
                        vx_core.f_new(
                          vx_data_textblock.t_textblock,
                          ":text",
                          " ",
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
                          "2"
                        ),
                        vx_core.f_new(
                          vx_data_textblock.t_textblock,
                          ":text",
                          " ",
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
                          "3"
                        )
                      )
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

  static f_repl_from_textblock_argmap(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl<-textblock-argmap",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl :val 2)\n (repl<-textblock-argmap\n  (tb/textblock\n   :text \"2\")\n  (empty argmap)))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_repl.t_repl,
                ":val",
                2
              ),
              vx_repl.f_repl_from_textblock_argmap(
                vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  ":text",
                  "2"
                ),
                vx_core.f_empty(
                  vx_core.t_argmap
                )
              )
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl :type +)\n (repl<-textblock-argmap\n  (tb/textblock\n   :text \"+\")\n  (empty argmap)))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_repl.t_repl,
                ":type",
                vx_core.t_plus
              ),
              vx_repl.f_repl_from_textblock_argmap(
                vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  ":text",
                  "+"
                ),
                vx_core.f_empty(
                  vx_core.t_argmap
                )
              )
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl :val 2)\n    (repl :val 3)))\n (repl<-textblock-argmap\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :delim\n    (copy delimvxlispparen\n     :delimlist\n      (empty delimlist))\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"+\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"2\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"3\")))\n  (empty argmap)))",
            ":testresult",
            vx_test.f_test(
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
              ),
              vx_repl.f_repl_from_textblock_argmap(
                vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  ":text",
                  "(+ 2 3)",
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
                      "+"
                    ),
                    vx_core.f_new(
                      vx_data_textblock.t_textblock,
                      ":text",
                      " ",
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
                      "2"
                    ),
                    vx_core.f_new(
                      vx_data_textblock.t_textblock,
                      ":text",
                      " ",
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
                      "3"
                    )
                  )
                ),
                vx_core.f_empty(
                  vx_core.t_argmap
                )
              )
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl :val 2)\n    (repl :val 3)))\n (repl<-textblock-argmap\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"(+ 2 3)\"\n      :delim\n       (copy delimvxlispparen\n        :delimlist\n         (empty delimlist))\n      :children\n       (tb/textblocklist\n        (tb/textblock\n         :text \"+\")\n        (tb/textblock\n         :text \" \"\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"2\")\n        (tb/textblock\n         :text \" \"\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"3\")))))\n  (empty argmap)))",
            ":testresult",
            vx_test.f_test(
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
              ),
              vx_repl.f_repl_from_textblock_argmap(
                vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  ":text",
                  "(+ 2 3)",
                  ":children",
                  vx_core.f_new(
                    vx_data_textblock.t_textblocklist,
                    vx_core.f_new(
                      vx_data_textblock.t_textblock,
                      ":text",
                      "(+ 2 3)",
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
                          "+"
                        ),
                        vx_core.f_new(
                          vx_data_textblock.t_textblock,
                          ":text",
                          " ",
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
                          "2"
                        ),
                        vx_core.f_new(
                          vx_data_textblock.t_textblock,
                          ":text",
                          " ",
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
                          "3"
                        )
                      )
                    )
                  )
                ),
                vx_core.f_empty(
                  vx_core.t_argmap
                )
              )
            )
          )
        )
    )
    return output
  }

  static f_textblock_from_script(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "textblock<-script",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (tb/textblock\n  :text \"infinity\"\n  :startpos 1\n  :endpos 8\n  :children\n   (tb/textblocklist\n    (tb/textblock\n    :text \"infinity\"\n    :startpos 1\n    :endpos 8\n    :delim\n     (delim\n      :name \"delimvxlisp\"))))\n (textblock<-script\n  \"infinity\"))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_data_textblock.t_textblock,
                ":text",
                "infinity",
                ":startpos",
                1,
                ":endpos",
                8,
                ":children",
                vx_core.f_new(
                  vx_data_textblock.t_textblocklist,
                  vx_core.f_new(
                    vx_data_textblock.t_textblock,
                    ":text",
                    "infinity",
                    ":startpos",
                    1,
                    ":endpos",
                    8,
                    ":delim",
                    vx_core.f_new(
                      vx_data_textblock.t_delim,
                      ":name",
                      "delimvxlisp"
                    )
                  )
                )
              ),
              vx_repl.f_textblock_from_script("infinity")
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (tb/textblock\n  :text \"(+ 2 3)\"\n  :startpos 1\n  :endpos 7\n  :children\n   (tb/textblocklist\n    (tb/textblock\n     :text \"(+ 2 3)\"\n     :startpos 1\n     :endpos 7\n     :delim\n      (copy delimvxlispparen\n       :delimlist\n        (empty delimlist))\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"+\"\n        :startpos 2\n        :endpos 2)\n       (tb/textblock\n        :text \" \"\n        :startpos 3\n        :endpos 3\n        :delim\n         (copy tb/delimwhitespace\n          :pos 0))\n       (tb/textblock\n        :text \"2\"\n        :startpos 4\n        :endpos 4)\n       (tb/textblock\n        :text \" \"\n        :startpos 5\n        :endpos 5\n        :delim\n         (copy tb/delimwhitespace\n          :pos 0))\n       (tb/textblock\n        :text \"3\"\n        :startpos 6\n        :endpos 6)))))\n (textblock<-script\n  \"(+ 2 3)\"))",
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
              vx_repl.f_textblock_from_script("(+ 2 3)")
            )
          )
        )
    )
    return output
  }

  static f_typefunc_from_string(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "typefunc<-string",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n string\n (typefunc<-string\n  \"string\"))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.t_string,
              vx_repl.f_typefunc_from_string("string")
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n +\n (typefunc<-string\n  \"+\"))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.t_plus,
              vx_repl.f_typefunc_from_string("+")
            )
          )
        )
    )
    return output
  }

  static test_cases(context) {
    const output = vx_core.f_new(
      vx_test.t_testcaselist,
      vx_repl_test.f_any_from_macro(context),
      vx_repl_test.f_any_from_repl(context),
      vx_repl_test.f_any_from_script(context),
      vx_repl_test.f_const_from_string(context),
      vx_repl_test.f_repl_empty_from_textblock_argmap(context),
      vx_repl_test.f_repl_paren_from_textblock_argmap(context),
      vx_repl_test.f_repl_from_macro(context),
      vx_repl_test.f_repl_from_script(context),
      vx_repl_test.f_repl_from_string_argmap(context),
      vx_repl_test.f_repl_from_textblock(context),
      vx_repl_test.f_repl_from_textblock_argmap(context),
      vx_repl_test.f_textblock_from_script(context),
      vx_repl_test.f_typefunc_from_string(context)
    )
    return output
  }
}
