
package com.vxlisp.vx.data

import com.vxlisp.vx.*

object vx_data_csvTest {

  fun f_textblock_csv_from_string(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/csv",
      ":casename", "textblock-csv<-string",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_textblock_csv_from_string_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_textblock_csv_from_string_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (tb/textblock\n  :text\n`\"a\",\"b\"\n1,\"2\"`\n  :startpos 1\n  :endpos 13\n  :children\n   (tb/textblocklist\n    (tb/textblock\n     :text `\"a\"`\n     :startpos 1\n     :endpos 3\n     :delim\n      (copy tb/delimquote\n       :pos 0)\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"a\"\n        :startpos 2\n        :endpos 2)))\n    (tb/textblock\n     :text \",\"\n     :startpos 4\n     :endpos 4\n     :delim\n      (copy tb/delimcomma\n       :pos 0))\n    (tb/textblock\n     :text `\"b\"`\n     :startpos 5\n     :endpos 7\n     :delim\n      (copy tb/delimquote\n       :pos 0)\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"b\"\n        :startpos 6\n        :endpos 6)))\n    (tb/textblock\n     :text \"\n\"\n     :startpos 8\n     :endpos 8\n     :delim\n      (copy tb/delimline\n       :pos 0))\n    (tb/textblock\n     :text \"1\"\n     :startpos 9\n     :endpos 9)\n    (tb/textblock\n     :text \",\"\n     :startpos 10\n     :endpos 10\n     :delim\n      (copy tb/delimcomma\n       :pos 0))\n    (tb/textblock\n     :text `\"2\"`\n     :startpos 11\n     :endpos 13\n     :delim\n      (copy tb/delimquote\n       :pos 0)\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"2\"\n        :startpos 12\n        :endpos 12)))))\n (textblock-csv<-string\n  `\"a\",\"b\"\n1,\"2\"`))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_data_textblock.t_textblock,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":text"),
            vx_core.vx_new_string("\"a\",\"b\"\n1,\"2\""),
            vx_core.vx_new_string(":startpos"),
            vx_core.vx_new_int(1),
            vx_core.vx_new_string(":endpos"),
            vx_core.vx_new_int(13),
            vx_core.vx_new_string(":children"),
            vx_core.f_new(
              vx_data_textblock.t_textblocklist,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":text"),
                    vx_core.vx_new_string("\"a\""),
                    vx_core.vx_new_string(":startpos"),
                    vx_core.vx_new_int(1),
                    vx_core.vx_new_string(":endpos"),
                    vx_core.vx_new_int(3),
                    vx_core.vx_new_string(":delim"),
                    vx_core.f_copy(
                      vx_data_textblock.c_delimquote,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string(":pos"),
                        vx_core.vx_new_int(0)
                      )
                    ),
                    vx_core.vx_new_string(":children"),
                    vx_core.f_new(
                      vx_data_textblock.t_textblocklist,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.f_new(
                          vx_data_textblock.t_textblock,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string(":text"),
                            vx_core.vx_new_string("a"),
                            vx_core.vx_new_string(":startpos"),
                            vx_core.vx_new_int(2),
                            vx_core.vx_new_string(":endpos"),
                            vx_core.vx_new_int(2)
                          )
                        )
                      )
                    )
                  )
                ),
                vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":text"),
                    vx_core.vx_new_string(","),
                    vx_core.vx_new_string(":startpos"),
                    vx_core.vx_new_int(4),
                    vx_core.vx_new_string(":endpos"),
                    vx_core.vx_new_int(4),
                    vx_core.vx_new_string(":delim"),
                    vx_core.f_copy(
                      vx_data_textblock.c_delimcomma,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string(":pos"),
                        vx_core.vx_new_int(0)
                      )
                    )
                  )
                ),
                vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":text"),
                    vx_core.vx_new_string("\"b\""),
                    vx_core.vx_new_string(":startpos"),
                    vx_core.vx_new_int(5),
                    vx_core.vx_new_string(":endpos"),
                    vx_core.vx_new_int(7),
                    vx_core.vx_new_string(":delim"),
                    vx_core.f_copy(
                      vx_data_textblock.c_delimquote,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string(":pos"),
                        vx_core.vx_new_int(0)
                      )
                    ),
                    vx_core.vx_new_string(":children"),
                    vx_core.f_new(
                      vx_data_textblock.t_textblocklist,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.f_new(
                          vx_data_textblock.t_textblock,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string(":text"),
                            vx_core.vx_new_string("b"),
                            vx_core.vx_new_string(":startpos"),
                            vx_core.vx_new_int(6),
                            vx_core.vx_new_string(":endpos"),
                            vx_core.vx_new_int(6)
                          )
                        )
                      )
                    )
                  )
                ),
                vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":text"),
                    vx_core.vx_new_string("\n"),
                    vx_core.vx_new_string(":startpos"),
                    vx_core.vx_new_int(8),
                    vx_core.vx_new_string(":endpos"),
                    vx_core.vx_new_int(8),
                    vx_core.vx_new_string(":delim"),
                    vx_core.f_copy(
                      vx_data_textblock.c_delimline,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string(":pos"),
                        vx_core.vx_new_int(0)
                      )
                    )
                  )
                ),
                vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":text"),
                    vx_core.vx_new_string("1"),
                    vx_core.vx_new_string(":startpos"),
                    vx_core.vx_new_int(9),
                    vx_core.vx_new_string(":endpos"),
                    vx_core.vx_new_int(9)
                  )
                ),
                vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":text"),
                    vx_core.vx_new_string(","),
                    vx_core.vx_new_string(":startpos"),
                    vx_core.vx_new_int(10),
                    vx_core.vx_new_string(":endpos"),
                    vx_core.vx_new_int(10),
                    vx_core.vx_new_string(":delim"),
                    vx_core.f_copy(
                      vx_data_textblock.c_delimcomma,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string(":pos"),
                        vx_core.vx_new_int(0)
                      )
                    )
                  )
                ),
                vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":text"),
                    vx_core.vx_new_string("\"2\""),
                    vx_core.vx_new_string(":startpos"),
                    vx_core.vx_new_int(11),
                    vx_core.vx_new_string(":endpos"),
                    vx_core.vx_new_int(13),
                    vx_core.vx_new_string(":delim"),
                    vx_core.f_copy(
                      vx_data_textblock.c_delimquote,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string(":pos"),
                        vx_core.vx_new_int(0)
                      )
                    ),
                    vx_core.vx_new_string(":children"),
                    vx_core.f_new(
                      vx_data_textblock.t_textblocklist,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.f_new(
                          vx_data_textblock.t_textblock,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string(":text"),
                            vx_core.vx_new_string("2"),
                            vx_core.vx_new_string(":startpos"),
                            vx_core.vx_new_int(12),
                            vx_core.vx_new_string(":endpos"),
                            vx_core.vx_new_int(12)
                          )
                        )
                      )
                    )
                  )
                )
              )
            )
          )
        ),
        vx_data_csv.f_textblock_csv_from_string(
          vx_core.vx_new_string("\"a\",\"b\"\n1,\"2\"")
        )
      )
    )
    return output
  }

  fun test_cases(context : vx_core.Type_context) : vx_test.Type_testcaselist {
    var testcases : List<vx_core.Type_any> = vx_core.arraylist_from_array(
      vx_data_csvTest.f_textblock_csv_from_string(context)
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
      ":testpkg", "vx/data/csv", 
      ":constnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 1), 
      ":docnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 63, ":tests", 7, ":total", 11), 
      ":funcnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 14, ":tests", 1, ":total", 7), 
      ":bigospacenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 7), 
      ":bigotimenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 7), 
      ":totalnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 9, ":tests", 1, ":total", 11), 
      ":typenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 3)
    )
    return output
  }

  fun test_coveragedetail() : vx_test.Type_testcoveragedetail {
    var output : vx_test.Type_testcoveragedetail = vx_core.vx_new(
      vx_test.t_testcoveragedetail,
      ":testpkg", "vx/data/csv",
      ":typemap", vx_core.vx_new(
        vx_core.t_intmap,
        ":csv", 0,
        ":csvrowmap", 0,
        ":csvrows", 0
      ), 
      ":constmap", vx_core.vx_new(
        vx_core.t_intmap,
        ":delimcsv", 0
      ), 
      ":funcmap", vx_core.vx_new(
        vx_core.t_intmap,
        ":csv-read<-file", 0,
        ":csv<-file", 0,
        ":csv<-string", 0,
        ":csv<-textblock", 0,
        ":csvrows<-textblock", 0,
        ":stringmap<-csv", 0,
        ":textblock-csv<-string", 1
      )
    )
    return output
  }

  fun test_package(context : vx_core.Type_context) : vx_test.Type_testpackage {
    var testcaselist : vx_test.Type_testcaselist = test_cases(context)
    var output : vx_test.Type_testpackage = vx_core.vx_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/data/csv", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    )
    return output
  }

}
