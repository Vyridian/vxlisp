
package com.vxlisp.vx.data;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import com.vxlisp.vx.*;


public final class CsvTest {

  static Test.Type_testcase f_textblock_csv_from_string(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/data/csv",
      ":casename", "textblock-csv<-string",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (tb/textblock\n  :text\n`\"a\",\"b\"\n1,\"2\"`\n  :startpos 1\n  :endpos 13\n  :children\n   (tb/textblocklist\n    (tb/textblock\n     :text `\"a\"`\n     :startpos 1\n     :endpos 3\n     :delim\n      (copy tb/delimquote\n       :pos 0)\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"a\"\n        :startpos 2\n        :endpos 2)))\n    (tb/textblock\n     :text \",\"\n     :startpos 4\n     :endpos 4\n     :delim\n      (copy tb/delimcomma\n       :pos 0))\n    (tb/textblock\n     :text `\"b\"`\n     :startpos 5\n     :endpos 7\n     :delim\n      (copy tb/delimquote\n       :pos 0)\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"b\"\n        :startpos 6\n        :endpos 6)))\n    (tb/textblock\n     :text \"\n\"\n     :startpos 8\n     :endpos 8\n     :delim\n      (copy tb/delimline\n       :pos 0))\n    (tb/textblock\n     :text \"1\"\n     :startpos 9\n     :endpos 9)\n    (tb/textblock\n     :text \",\"\n     :startpos 10\n     :endpos 10\n     :delim\n      (copy tb/delimcomma\n       :pos 0))\n    (tb/textblock\n     :text `\"2\"`\n     :startpos 11\n     :endpos 13\n     :delim\n      (copy tb/delimquote\n       :pos 0)\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"2\"\n        :startpos 12\n        :endpos 12)))))\n (textblock-csv<-string\n  `\"a\",\"b\"\n1,\"2\"`))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Textblock.t_textblock,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":text"),
                  Core.vx_new_string("\"a\",\"b\"\n1,\"2\""),
                  Core.vx_new_string(":startpos"),
                  Core.vx_new_int(1),
                  Core.vx_new_string(":endpos"),
                  Core.vx_new_int(13),
                  Core.vx_new_string(":children"),
                  Core.f_new(
                    Textblock.t_textblocklist,
                    Core.t_anylist.vx_new(
                      Core.f_new(
                        Textblock.t_textblock,
                        Core.t_anylist.vx_new(
                          Core.vx_new_string(":text"),
                          Core.vx_new_string("\"a\""),
                          Core.vx_new_string(":startpos"),
                          Core.vx_new_int(1),
                          Core.vx_new_string(":endpos"),
                          Core.vx_new_int(3),
                          Core.vx_new_string(":delim"),
                          Core.f_copy(
                            Textblock.c_delimquote,
                            Core.t_anylist.vx_new(
                              Core.vx_new_string(":pos"),
                              Core.vx_new_int(0)
                            )
                          ),
                          Core.vx_new_string(":children"),
                          Core.f_new(
                            Textblock.t_textblocklist,
                            Core.t_anylist.vx_new(
                              Core.f_new(
                                Textblock.t_textblock,
                                Core.t_anylist.vx_new(
                                  Core.vx_new_string(":text"),
                                  Core.vx_new_string("a"),
                                  Core.vx_new_string(":startpos"),
                                  Core.vx_new_int(2),
                                  Core.vx_new_string(":endpos"),
                                  Core.vx_new_int(2)
                                )
                              )
                            )
                          )
                        )
                      ),
                      Core.f_new(
                        Textblock.t_textblock,
                        Core.t_anylist.vx_new(
                          Core.vx_new_string(":text"),
                          Core.vx_new_string(","),
                          Core.vx_new_string(":startpos"),
                          Core.vx_new_int(4),
                          Core.vx_new_string(":endpos"),
                          Core.vx_new_int(4),
                          Core.vx_new_string(":delim"),
                          Core.f_copy(
                            Textblock.c_delimcomma,
                            Core.t_anylist.vx_new(
                              Core.vx_new_string(":pos"),
                              Core.vx_new_int(0)
                            )
                          )
                        )
                      ),
                      Core.f_new(
                        Textblock.t_textblock,
                        Core.t_anylist.vx_new(
                          Core.vx_new_string(":text"),
                          Core.vx_new_string("\"b\""),
                          Core.vx_new_string(":startpos"),
                          Core.vx_new_int(5),
                          Core.vx_new_string(":endpos"),
                          Core.vx_new_int(7),
                          Core.vx_new_string(":delim"),
                          Core.f_copy(
                            Textblock.c_delimquote,
                            Core.t_anylist.vx_new(
                              Core.vx_new_string(":pos"),
                              Core.vx_new_int(0)
                            )
                          ),
                          Core.vx_new_string(":children"),
                          Core.f_new(
                            Textblock.t_textblocklist,
                            Core.t_anylist.vx_new(
                              Core.f_new(
                                Textblock.t_textblock,
                                Core.t_anylist.vx_new(
                                  Core.vx_new_string(":text"),
                                  Core.vx_new_string("b"),
                                  Core.vx_new_string(":startpos"),
                                  Core.vx_new_int(6),
                                  Core.vx_new_string(":endpos"),
                                  Core.vx_new_int(6)
                                )
                              )
                            )
                          )
                        )
                      ),
                      Core.f_new(
                        Textblock.t_textblock,
                        Core.t_anylist.vx_new(
                          Core.vx_new_string(":text"),
                          Core.vx_new_string("\n"),
                          Core.vx_new_string(":startpos"),
                          Core.vx_new_int(8),
                          Core.vx_new_string(":endpos"),
                          Core.vx_new_int(8),
                          Core.vx_new_string(":delim"),
                          Core.f_copy(
                            Textblock.c_delimline,
                            Core.t_anylist.vx_new(
                              Core.vx_new_string(":pos"),
                              Core.vx_new_int(0)
                            )
                          )
                        )
                      ),
                      Core.f_new(
                        Textblock.t_textblock,
                        Core.t_anylist.vx_new(
                          Core.vx_new_string(":text"),
                          Core.vx_new_string("1"),
                          Core.vx_new_string(":startpos"),
                          Core.vx_new_int(9),
                          Core.vx_new_string(":endpos"),
                          Core.vx_new_int(9)
                        )
                      ),
                      Core.f_new(
                        Textblock.t_textblock,
                        Core.t_anylist.vx_new(
                          Core.vx_new_string(":text"),
                          Core.vx_new_string(","),
                          Core.vx_new_string(":startpos"),
                          Core.vx_new_int(10),
                          Core.vx_new_string(":endpos"),
                          Core.vx_new_int(10),
                          Core.vx_new_string(":delim"),
                          Core.f_copy(
                            Textblock.c_delimcomma,
                            Core.t_anylist.vx_new(
                              Core.vx_new_string(":pos"),
                              Core.vx_new_int(0)
                            )
                          )
                        )
                      ),
                      Core.f_new(
                        Textblock.t_textblock,
                        Core.t_anylist.vx_new(
                          Core.vx_new_string(":text"),
                          Core.vx_new_string("\"2\""),
                          Core.vx_new_string(":startpos"),
                          Core.vx_new_int(11),
                          Core.vx_new_string(":endpos"),
                          Core.vx_new_int(13),
                          Core.vx_new_string(":delim"),
                          Core.f_copy(
                            Textblock.c_delimquote,
                            Core.t_anylist.vx_new(
                              Core.vx_new_string(":pos"),
                              Core.vx_new_int(0)
                            )
                          ),
                          Core.vx_new_string(":children"),
                          Core.f_new(
                            Textblock.t_textblocklist,
                            Core.t_anylist.vx_new(
                              Core.f_new(
                                Textblock.t_textblock,
                                Core.t_anylist.vx_new(
                                  Core.vx_new_string(":text"),
                                  Core.vx_new_string("2"),
                                  Core.vx_new_string(":startpos"),
                                  Core.vx_new_int(12),
                                  Core.vx_new_string(":endpos"),
                                  Core.vx_new_int(12)
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
              Csv.f_textblock_csv_from_string(Core.vx_new_string("\"a\",\"b\"\n1,\"2\""))
            )
        )
      )
    );
    return output;
  }

  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(
      CsvTest.f_textblock_csv_from_string(context)
    ));
    Test.Type_testcaselist output = Test.t_testcaselist.vx_new(arraylisttestcase);
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    return Test.t_testcoveragesummary.vx_new(
      ":testpkg",   "vx/data/csv", 
      ":constnums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 1), 
      ":docnums", Test.t_testcoveragenums.vx_new(":pct", 33, ":tests", 2, ":total", 6), 
      ":funcnums", Test.t_testcoveragenums.vx_new(":pct", 33, ":tests", 1, ":total", 3), 
      ":ospacenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 3), 
      ":otimenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 3), 
      ":totalnums", Test.t_testcoveragenums.vx_new(":pct", 16, ":tests", 1, ":total", 6), 
      ":typenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 2)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Test.t_testcoveragedetail.vx_new(
      ":testpkg", "vx/data/csv",
      ":typemap", Core.t_intmap.vx_new(
        ":csv", 0,
        ":csvrows", 0
      ),
      ":constmap", Core.t_intmap.vx_new(
        ":delimcsv", 0
      ),
      ":funcmap", Core.t_intmap.vx_new(
        ":csv<-textblock", 0,
        ":csvrows<-textblock", 0,
        ":textblock-csv<-string", 1
      )
    );
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Test.t_testpackage.vx_new(
      ":testpkg", "vx/data/csv", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
