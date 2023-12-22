'strict mode'

import vx_data_csv from "../../../src/vx/data/csv.js"
import vx_core from "../../../src/vx/core.js"
import vx_test from "../../../src/vx/test.js"
import vx_collection from "../../../src/vx/collection.js"
import vx_data_file from "../../../src/vx/data/file.js"
import vx_data_textblock from "../../../src/vx/data/textblock.js"
import vx_type from "../../../src/vx/type.js"

export default class vx_data_csv_test {

  static test_package(context) {
    const testcaselist = vx_data_csv_test.test_cases(context)
    const output = vx_core.f_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/data/csv",
      ":caselist", testcaselist,
      ":coveragesummary", vx_data_csv_test.test_coveragesummary(),
      ":coveragedetail", vx_data_csv_test.test_coveragedetail()
    );
    return output;
  }

  static test_coveragesummary() {
    return vx_core.f_new(
      vx_test.t_testcoveragesummary,
      "testpkg",   "vx/data/csv", 
      "constnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 1), 
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 63, ":tests", 7, ":total", 11), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 14, ":tests", 1, ":total", 7), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 9, ":tests", 1, ":total", 11), 
      "typenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 3)
    )
  }

  static test_coveragedetail() {
    return vx_core.f_new(
      vx_test.t_testcoveragedetail,
      "testpkg", "vx/data/csv",
      "typemap",
        vx_core.f_new(
          vx_core.t_intmap,
          "csv", 0,
          "csvrowmap", 0,
          "csvrows", 0
        ),
      "constmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "delimcsv", 0
        ),
      "funcmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "csv-read<-file", 0,
          "csv<-file", 0,
          "csv<-string", 0,
          "csv<-textblock", 0,
          "csvrows<-textblock", 0,
          "stringmap<-csv", 0,
          "textblock-csv<-string", 1
        )
    )
  }

  static f_textblock_csv_from_string(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/csv",
      ":casename", "textblock-csv<-string",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (tb/textblock\n  :text\n`\"a\",\"b\"\n1,\"2\"`\n  :startpos 1\n  :endpos 13\n  :children\n   (tb/textblocklist\n    (tb/textblock\n     :text `\"a\"`\n     :startpos 1\n     :endpos 3\n     :delim\n      (copy tb/delimquote\n       :pos 0)\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"a\"\n        :startpos 2\n        :endpos 2)))\n    (tb/textblock\n     :text \",\"\n     :startpos 4\n     :endpos 4\n     :delim\n      (copy tb/delimcomma\n       :pos 0))\n    (tb/textblock\n     :text `\"b\"`\n     :startpos 5\n     :endpos 7\n     :delim\n      (copy tb/delimquote\n       :pos 0)\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"b\"\n        :startpos 6\n        :endpos 6)))\n    (tb/textblock\n     :text \"\n\"\n     :startpos 8\n     :endpos 8\n     :delim\n      (copy tb/delimline\n       :pos 0))\n    (tb/textblock\n     :text \"1\"\n     :startpos 9\n     :endpos 9)\n    (tb/textblock\n     :text \",\"\n     :startpos 10\n     :endpos 10\n     :delim\n      (copy tb/delimcomma\n       :pos 0))\n    (tb/textblock\n     :text `\"2\"`\n     :startpos 11\n     :endpos 13\n     :delim\n      (copy tb/delimquote\n       :pos 0)\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"2\"\n        :startpos 12\n        :endpos 12)))))\n (textblock-csv<-string\n  `\"a\",\"b\"\n1,\"2\"`))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_data_textblock.t_textblock,
                ":text",
                "\"a\",\"b\"\n1,\"2\"",
                ":startpos",
                1,
                ":endpos",
                13,
                ":children",
                vx_core.f_new(
                  vx_data_textblock.t_textblocklist,
                  vx_core.f_new(
                    vx_data_textblock.t_textblock,
                    ":text",
                    "\"a\"",
                    ":startpos",
                    1,
                    ":endpos",
                    3,
                    ":delim",
                    vx_core.f_copy(
                      vx_data_textblock.c_delimquote,
                      ":pos",
                      0
                    ),
                    ":children",
                    vx_core.f_new(
                      vx_data_textblock.t_textblocklist,
                      vx_core.f_new(
                        vx_data_textblock.t_textblock,
                        ":text",
                        "a",
                        ":startpos",
                        2,
                        ":endpos",
                        2
                      )
                    )
                  ),
                  vx_core.f_new(
                    vx_data_textblock.t_textblock,
                    ":text",
                    ",",
                    ":startpos",
                    4,
                    ":endpos",
                    4,
                    ":delim",
                    vx_core.f_copy(
                      vx_data_textblock.c_delimcomma,
                      ":pos",
                      0
                    )
                  ),
                  vx_core.f_new(
                    vx_data_textblock.t_textblock,
                    ":text",
                    "\"b\"",
                    ":startpos",
                    5,
                    ":endpos",
                    7,
                    ":delim",
                    vx_core.f_copy(
                      vx_data_textblock.c_delimquote,
                      ":pos",
                      0
                    ),
                    ":children",
                    vx_core.f_new(
                      vx_data_textblock.t_textblocklist,
                      vx_core.f_new(
                        vx_data_textblock.t_textblock,
                        ":text",
                        "b",
                        ":startpos",
                        6,
                        ":endpos",
                        6
                      )
                    )
                  ),
                  vx_core.f_new(
                    vx_data_textblock.t_textblock,
                    ":text",
                    "\n",
                    ":startpos",
                    8,
                    ":endpos",
                    8,
                    ":delim",
                    vx_core.f_copy(
                      vx_data_textblock.c_delimline,
                      ":pos",
                      0
                    )
                  ),
                  vx_core.f_new(
                    vx_data_textblock.t_textblock,
                    ":text",
                    "1",
                    ":startpos",
                    9,
                    ":endpos",
                    9
                  ),
                  vx_core.f_new(
                    vx_data_textblock.t_textblock,
                    ":text",
                    ",",
                    ":startpos",
                    10,
                    ":endpos",
                    10,
                    ":delim",
                    vx_core.f_copy(
                      vx_data_textblock.c_delimcomma,
                      ":pos",
                      0
                    )
                  ),
                  vx_core.f_new(
                    vx_data_textblock.t_textblock,
                    ":text",
                    "\"2\"",
                    ":startpos",
                    11,
                    ":endpos",
                    13,
                    ":delim",
                    vx_core.f_copy(
                      vx_data_textblock.c_delimquote,
                      ":pos",
                      0
                    ),
                    ":children",
                    vx_core.f_new(
                      vx_data_textblock.t_textblocklist,
                      vx_core.f_new(
                        vx_data_textblock.t_textblock,
                        ":text",
                        "2",
                        ":startpos",
                        12,
                        ":endpos",
                        12
                      )
                    )
                  )
                )
              ),
              vx_data_csv.f_textblock_csv_from_string("\"a\",\"b\"\n1,\"2\"")
            )
          )
        )
    )
    return output
  }

  static test_cases(context) {
    const output = vx_core.f_new(
      vx_test.t_testcaselist,
      vx_data_csv_test.f_textblock_csv_from_string(context)
    )
    return output
  }

}
