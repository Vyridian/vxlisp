
package com.vxlisp.vx.data;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import com.vxlisp.vx.*;

public final class CsvTest {

  static Test.Type_testcase f_textblock_csv_from_string(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/csv",
      ":casename", "textblock-csv<-string",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist, 
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (tb/textblock\n  :text\n`\"a\",\"b\"\n1,\"2\"`\n  :startpos 1\n  :endpos 13\n  :children\n   (tb/textblocklist\n    (tb/textblock\n     :text `\"a\"`\n     :startpos 1\n     :endpos 3\n     :delim\n      (copy tb/delimquote\n       :pos 0)\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"a\"\n        :startpos 2\n        :endpos 2)))\n    (tb/textblock\n     :text \",\"\n     :startpos 4\n     :endpos 4\n     :delim\n      (copy tb/delimcomma\n       :pos 0))\n    (tb/textblock\n     :text `\"b\"`\n     :startpos 5\n     :endpos 7\n     :delim\n      (copy tb/delimquote\n       :pos 0)\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"b\"\n        :startpos 6\n        :endpos 6)))\n    (tb/textblock\n     :text \"\n\"\n     :startpos 8\n     :endpos 8\n     :delim\n      (copy tb/delimline\n       :pos 0))\n    (tb/textblock\n     :text \"1\"\n     :startpos 9\n     :endpos 9)\n    (tb/textblock\n     :text \",\"\n     :startpos 10\n     :endpos 10\n     :delim\n      (copy tb/delimcomma\n       :pos 0))\n    (tb/textblock\n     :text `\"2\"`\n     :startpos 11\n     :endpos 13\n     :delim\n      (copy tb/delimquote\n       :pos 0)\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"2\"\n        :startpos 12\n        :endpos 12)))))\n (textblock-csv<-string\n  `\"a\",\"b\"\n1,\"2\"`))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Textblock.t_textblock,
                Core.vx_new(Core.t_anylist,
                  Core.vx_new_string(":text"),
                  Core.vx_new_string("\"a\",\"b\"\n1,\"2\""),
                  Core.vx_new_string(":startpos"),
                  Core.vx_new_int(1),
                  Core.vx_new_string(":endpos"),
                  Core.vx_new_int(13),
                  Core.vx_new_string(":children"),
                  Core.f_new(
                    Textblock.t_textblocklist,
                    Core.vx_new(Core.t_anylist,
                      Core.f_new(
                        Textblock.t_textblock,
                        Core.vx_new(Core.t_anylist,
                          Core.vx_new_string(":text"),
                          Core.vx_new_string("\"a\""),
                          Core.vx_new_string(":startpos"),
                          Core.vx_new_int(1),
                          Core.vx_new_string(":endpos"),
                          Core.vx_new_int(3),
                          Core.vx_new_string(":delim"),
                          Core.f_copy(
                            Textblock.c_delimquote,
                            Core.vx_new(Core.t_anylist,
                              Core.vx_new_string(":pos"),
                              Core.vx_new_int(0)
                            )
                          ),
                          Core.vx_new_string(":children"),
                          Core.f_new(
                            Textblock.t_textblocklist,
                            Core.vx_new(Core.t_anylist,
                              Core.f_new(
                                Textblock.t_textblock,
                                Core.vx_new(Core.t_anylist,
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
                        Core.vx_new(Core.t_anylist,
                          Core.vx_new_string(":text"),
                          Core.vx_new_string(","),
                          Core.vx_new_string(":startpos"),
                          Core.vx_new_int(4),
                          Core.vx_new_string(":endpos"),
                          Core.vx_new_int(4),
                          Core.vx_new_string(":delim"),
                          Core.f_copy(
                            Textblock.c_delimcomma,
                            Core.vx_new(Core.t_anylist,
                              Core.vx_new_string(":pos"),
                              Core.vx_new_int(0)
                            )
                          )
                        )
                      ),
                      Core.f_new(
                        Textblock.t_textblock,
                        Core.vx_new(Core.t_anylist,
                          Core.vx_new_string(":text"),
                          Core.vx_new_string("\"b\""),
                          Core.vx_new_string(":startpos"),
                          Core.vx_new_int(5),
                          Core.vx_new_string(":endpos"),
                          Core.vx_new_int(7),
                          Core.vx_new_string(":delim"),
                          Core.f_copy(
                            Textblock.c_delimquote,
                            Core.vx_new(Core.t_anylist,
                              Core.vx_new_string(":pos"),
                              Core.vx_new_int(0)
                            )
                          ),
                          Core.vx_new_string(":children"),
                          Core.f_new(
                            Textblock.t_textblocklist,
                            Core.vx_new(Core.t_anylist,
                              Core.f_new(
                                Textblock.t_textblock,
                                Core.vx_new(Core.t_anylist,
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
                        Core.vx_new(Core.t_anylist,
                          Core.vx_new_string(":text"),
                          Core.vx_new_string("\n"),
                          Core.vx_new_string(":startpos"),
                          Core.vx_new_int(8),
                          Core.vx_new_string(":endpos"),
                          Core.vx_new_int(8),
                          Core.vx_new_string(":delim"),
                          Core.f_copy(
                            Textblock.c_delimline,
                            Core.vx_new(Core.t_anylist,
                              Core.vx_new_string(":pos"),
                              Core.vx_new_int(0)
                            )
                          )
                        )
                      ),
                      Core.f_new(
                        Textblock.t_textblock,
                        Core.vx_new(Core.t_anylist,
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
                        Core.vx_new(Core.t_anylist,
                          Core.vx_new_string(":text"),
                          Core.vx_new_string(","),
                          Core.vx_new_string(":startpos"),
                          Core.vx_new_int(10),
                          Core.vx_new_string(":endpos"),
                          Core.vx_new_int(10),
                          Core.vx_new_string(":delim"),
                          Core.f_copy(
                            Textblock.c_delimcomma,
                            Core.vx_new(Core.t_anylist,
                              Core.vx_new_string(":pos"),
                              Core.vx_new_int(0)
                            )
                          )
                        )
                      ),
                      Core.f_new(
                        Textblock.t_textblock,
                        Core.vx_new(Core.t_anylist,
                          Core.vx_new_string(":text"),
                          Core.vx_new_string("\"2\""),
                          Core.vx_new_string(":startpos"),
                          Core.vx_new_int(11),
                          Core.vx_new_string(":endpos"),
                          Core.vx_new_int(13),
                          Core.vx_new_string(":delim"),
                          Core.f_copy(
                            Textblock.c_delimquote,
                            Core.vx_new(Core.t_anylist,
                              Core.vx_new_string(":pos"),
                              Core.vx_new_int(0)
                            )
                          ),
                          Core.vx_new_string(":children"),
                          Core.f_new(
                            Textblock.t_textblocklist,
                            Core.vx_new(Core.t_anylist,
                              Core.f_new(
                                Textblock.t_textblock,
                                Core.vx_new(Core.t_anylist,
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
    Test.Type_testcaselist output = Core.vx_new(
      Test.t_testcaselist,
      arraylisttestcase
    );
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    return Core.vx_new(
      Test.t_testcoveragesummary,
      ":testpkg", "vx/data/csv", 
      ":constnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 1), 
      ":docnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 63, ":tests", 7, ":total", 11), 
      ":funcnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 14, ":tests", 1, ":total", 7), 
      ":bigospacenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 7), 
      ":bigotimenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 7), 
      ":totalnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 9, ":tests", 1, ":total", 11), 
      ":typenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 3)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Core.vx_new(Test.t_testcoveragedetail, ":testpkg", "vx/data/csv", ":typemap", Core.vx_new(
  Core.t_intmap,
        ":csv", 0,
        ":csvrowmap", 0,
        ":csvrows", 0
), ":constmap", Core.vx_new(
  Core.t_intmap,
        ":delimcsv", 0
), ":funcmap", Core.vx_new(
  Core.t_intmap,
        ":csv-read<-file", 0,
        ":csv<-file", 0,
        ":csv<-string", 0,
        ":csv<-textblock", 0,
        ":csvrows<-textblock", 0,
        ":stringmap<-csv", 0,
        ":textblock-csv<-string", 1
      ));
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Core.vx_new(
      Test.t_testpackage,
      ":testpkg", "vx/data/csv", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
