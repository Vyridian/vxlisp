'strict mode'

import vx_data_textblock from "../../../src/vx/data/textblock.js"
import vx_core from "../../../src/vx/core.js"
import vx_test from "../../../src/vx/test.js"
import vx_type from "../../../src/vx/type.js"

export default class vx_data_textblock_test {

  static test_package(context) {
    const testcaselist = vx_data_textblock_test.test_cases(context)
    const output = vx_core.f_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/data/textblock",
      ":caselist", testcaselist,
      ":coveragesummary", vx_data_textblock_test.test_coveragesummary(),
      ":coveragedetail", vx_data_textblock_test.test_coveragedetail()
    );
    return output;
  }

  static test_coveragesummary() {
    return vx_core.f_new(
      vx_test.t_testcoveragesummary,
      "testpkg",   "vx/data/textblock", 
      "constnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 15), 
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 30, ":total", 30), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 63, ":tests", 7, ":total", 11), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 23, ":tests", 7, ":total", 30), 
      "typenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 4)
    )
  }

  static test_coveragedetail() {
    return vx_core.f_new(
      vx_test.t_testcoveragedetail,
      "testpkg", "vx/data/textblock",
      "typemap",
        vx_core.f_new(
          vx_core.t_intmap,
          "delim", 0,
          "delimlist", 0,
          "textblock", 0,
          "textblocklist", 0
        ),
      "constmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "delimbracketcurly", 0,
          "delimbracketsquare", 0,
          "delimclose", 0,
          "delimcomma", 0,
          "delimcomment", 0,
          "delimcommentblock", 0,
          "delimline", 0,
          "delimnonwhitespace", 0,
          "delimparen", 0,
          "delimparenline", 0,
          "delimquote", 0,
          "delimquoteblock", 0,
          "delimspace", 0,
          "delimtext", 0,
          "delimwhitespace", 0
        ),
      "funcmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "delim-first<-delim-delim", 1,
          "delim-first<-string-delimlist", 1,
          "delim-startpos<-string-delim", 1,
          "delimlist-startpos<-string-delimlist", 1,
          "stringlist<-textblocklist", 0,
          "text<-textblock", 0,
          "textblock-firstdelim<-textblock-delimlist", 1,
          "textblock-startafter<-string-delim", 1,
          "textblock-startbefore<-string-delim", 1,
          "textblock<-textblock-delim", 0,
          "textblocks<-textblock", 0
        )
    )
  }

  static f_delim_first_from_delim_delim(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/textblock",
      ":casename", "delim-first<-delim-delim",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (copy delimcomma\n  :startpos 1)\n (delim-first<-delim-delim\n  (copy delimspace\n   :startpos 2)\n  (copy delimcomma\n   :startpos 1)))",
            ":testresult",
            vx_test.f_test(
              vx_core.f_copy(
                vx_data_textblock.c_delimcomma,
                ":startpos",
                1
              ),
              vx_data_textblock.f_delim_first_from_delim_delim(
                vx_core.f_copy(
                  vx_data_textblock.c_delimspace,
                  ":startpos",
                  2
                ),
                vx_core.f_copy(
                  vx_data_textblock.c_delimcomma,
                  ":startpos",
                  1
                )
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_delim_first_from_string_delimlist(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/textblock",
      ":casename", "delim-first<-string-delimlist",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (copy delimcomma\n  :startpos 1)\n (delim-first<-string-delimlist\n  \"a, b\"\n  (delimlist delimspace delimcomma)))",
            ":testresult",
            vx_test.f_test(
              vx_core.f_copy(
                vx_data_textblock.c_delimcomma,
                ":startpos",
                1
              ),
              vx_data_textblock.f_delim_first_from_string_delimlist(
                "a, b",
                vx_core.f_new(
                  vx_data_textblock.t_delimlist,
                  vx_data_textblock.c_delimspace,
                  vx_data_textblock.c_delimcomma
                )
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_delim_startpos_from_string_delim(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/textblock",
      ":casename", "delim-startpos<-string-delim",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (copy delimcomma\n  :startpos 1)\n (delim-startpos<-string-delim\n  \"a,b\"\n  delimcomma))",
            ":testresult",
            vx_test.f_test(
              vx_core.f_copy(
                vx_data_textblock.c_delimcomma,
                ":startpos",
                1
              ),
              vx_data_textblock.f_delim_startpos_from_string_delim(
                "a,b",
                vx_data_textblock.c_delimcomma
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_delimlist_startpos_from_string_delimlist(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/textblock",
      ":casename", "delimlist-startpos<-string-delimlist",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (delimlist\n  (copy delimspace\n   :startpos 2)\n  (copy delimcomma\n   :startpos 1))\n (delimlist-startpos<-string-delimlist\n  \"a, b\"\n  (delimlist delimspace delimcomma)))",
            ":testresult",
            vx_test.f_test(
              vx_core.f_new(
                vx_data_textblock.t_delimlist,
                vx_core.f_copy(
                  vx_data_textblock.c_delimspace,
                  ":startpos",
                  2
                ),
                vx_core.f_copy(
                  vx_data_textblock.c_delimcomma,
                  ":startpos",
                  1
                )
              ),
              vx_data_textblock.f_delimlist_startpos_from_string_delimlist(
                "a, b",
                vx_core.f_new(
                  vx_data_textblock.t_delimlist,
                  vx_data_textblock.c_delimspace,
                  vx_data_textblock.c_delimcomma
                )
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_textblock_firstdelim_from_textblock_delimlist(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/textblock",
      ":casename", "textblock-firstdelim<-textblock-delimlist",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (textblock\n  :delim\n   (copy delimcomma\n    :startpos 1)\n  :text \" b\"\n  :parent\n   (textblock\n    :text \"a, b\"\n    :textblocks\n     (textblocklist\n      (textblock\n       :text \"a\"))))\n (textblock-firstdelim<-textblock-delimlist\n  (textblock\n   :text \"a, b\")\n  (delimlist delimspace delimcomma)))",
            ":testresult",
            vx_test.f_test(
              vx_core.f_new(
                vx_data_textblock.t_textblock,
                ":delim",
                vx_core.f_copy(
                  vx_data_textblock.c_delimcomma,
                  ":startpos",
                  1
                ),
                ":text",
                " b",
                ":parent",
                vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  ":text",
                  "a, b",
                  ":textblocks",
                  vx_core.f_new(
                    vx_data_textblock.t_textblocklist,
                    vx_core.f_new(
                      vx_data_textblock.t_textblock,
                      ":text",
                      "a"
                    )
                  )
                )
              ),
              vx_data_textblock.f_textblock_firstdelim_from_textblock_delimlist(
                vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  ":text",
                  "a, b"
                ),
                vx_core.f_new(
                  vx_data_textblock.t_delimlist,
                  vx_data_textblock.c_delimspace,
                  vx_data_textblock.c_delimcomma
                )
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_textblock_startafter_from_string_delim(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/textblock",
      ":casename", "textblock-startafter<-string-delim",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (textblock\n  :text \" b\")\n (textblock-startafter<-string-delim\n  \"a, b\"\n  (delim\n   :starttext \",\"\n   :startpos  1)))",
            ":testresult",
            vx_test.f_test(
              vx_core.f_new(
                vx_data_textblock.t_textblock,
                ":text",
                " b"
              ),
              vx_data_textblock.f_textblock_startafter_from_string_delim(
                "a, b",
                vx_core.f_new(
                  vx_data_textblock.t_delim,
                  ":starttext",
                  ",",
                  ":startpos",
                  1
                )
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_textblock_startbefore_from_string_delim(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/textblock",
      ":casename", "textblock-startbefore<-string-delim",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (textblock\n  :text \"a\")\n (textblock-startbefore<-string-delim\n  \"a, b\"\n  (delim\n   :startpos 1)))",
            ":testresult",
            vx_test.f_test(
              vx_core.f_new(
                vx_data_textblock.t_textblock,
                ":text",
                "a"
              ),
              vx_data_textblock.f_textblock_startbefore_from_string_delim(
                "a, b",
                vx_core.f_new(
                  vx_data_textblock.t_delim,
                  ":startpos",
                  1
                )
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
      vx_data_textblock_test.f_delim_first_from_delim_delim(context),
      vx_data_textblock_test.f_delim_first_from_string_delimlist(context),
      vx_data_textblock_test.f_delim_startpos_from_string_delim(context),
      vx_data_textblock_test.f_delimlist_startpos_from_string_delimlist(context),
      vx_data_textblock_test.f_textblock_firstdelim_from_textblock_delimlist(context),
      vx_data_textblock_test.f_textblock_startafter_from_string_delim(context),
      vx_data_textblock_test.f_textblock_startbefore_from_string_delim(context)
    )
    return output
  }

}
