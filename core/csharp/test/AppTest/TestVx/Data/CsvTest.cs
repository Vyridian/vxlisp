
namespace AppTest.TestVx.Data;

public class CsvTest {

  public static Vx.Test.Type_testcase f_textblock_csv_from_string(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/data/csv",
      ":casename", "textblock-csv<-string",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        f_textblock_csv_from_string_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_textblock_csv_from_string_testdescribe_1(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (tb/textblock\n  :text\n`\"a\",\"b\"\n1,\"2\"`\n  :startpos 1\n  :endpos 13\n  :children\n   (tb/textblocklist\n    (tb/textblock\n     :text `\"a\"`\n     :startpos 1\n     :endpos 3\n     :delim\n      (copy tb/delimquote\n       :pos 0)\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"a\"\n        :startpos 2\n        :endpos 2)))\n    (tb/textblock\n     :text \",\"\n     :startpos 4\n     :endpos 4\n     :delim\n      (copy tb/delimcomma\n       :pos 0))\n    (tb/textblock\n     :text `\"b\"`\n     :startpos 5\n     :endpos 7\n     :delim\n      (copy tb/delimquote\n       :pos 0)\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"b\"\n        :startpos 6\n        :endpos 6)))\n    (tb/textblock\n     :text \"\n\"\n     :startpos 8\n     :endpos 8\n     :delim\n      (copy tb/delimline\n       :pos 0))\n    (tb/textblock\n     :text \"1\"\n     :startpos 9\n     :endpos 9)\n    (tb/textblock\n     :text \",\"\n     :startpos 10\n     :endpos 10\n     :delim\n      (copy tb/delimcomma\n       :pos 0))\n    (tb/textblock\n     :text `\"2\"`\n     :startpos 11\n     :endpos 13\n     :delim\n      (copy tb/delimquote\n       :pos 0)\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"2\"\n        :startpos 12\n        :endpos 12)))))\n (textblock-csv<-string\n  `\"a\",\"b\"\n1,\"2\"`))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Data.Textblock.t_textblock,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":text"),
            Vx.Core.vx_new_string("\"a\",\"b\"\n1,\"2\""),
            Vx.Core.vx_new_string(":startpos"),
            Vx.Core.vx_new_int(1),
            Vx.Core.vx_new_string(":endpos"),
            Vx.Core.vx_new_int(13),
            Vx.Core.vx_new_string(":children"),
            Vx.Core.f_new(
              Vx.Data.Textblock.t_textblocklist,
              Vx.Core.vx_new(
                Vx.Core.t_anylist,
                Vx.Core.f_new(
                  Vx.Data.Textblock.t_textblock,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":text"),
                    Vx.Core.vx_new_string("\"a\""),
                    Vx.Core.vx_new_string(":startpos"),
                    Vx.Core.vx_new_int(1),
                    Vx.Core.vx_new_string(":endpos"),
                    Vx.Core.vx_new_int(3),
                    Vx.Core.vx_new_string(":delim"),
                    Vx.Core.f_copy(
                      Vx.Data.Textblock.c_delimquote,
                      Vx.Core.vx_new(
                        Vx.Core.t_anylist,
                        Vx.Core.vx_new_string(":pos"),
                        Vx.Core.vx_new_int(0)
                      )
                    ),
                    Vx.Core.vx_new_string(":children"),
                    Vx.Core.f_new(
                      Vx.Data.Textblock.t_textblocklist,
                      Vx.Core.vx_new(
                        Vx.Core.t_anylist,
                        Vx.Core.f_new(
                          Vx.Data.Textblock.t_textblock,
                          Vx.Core.vx_new(
                            Vx.Core.t_anylist,
                            Vx.Core.vx_new_string(":text"),
                            Vx.Core.vx_new_string("a"),
                            Vx.Core.vx_new_string(":startpos"),
                            Vx.Core.vx_new_int(2),
                            Vx.Core.vx_new_string(":endpos"),
                            Vx.Core.vx_new_int(2)
                          )
                        )
                      )
                    )
                  )
                ),
                Vx.Core.f_new(
                  Vx.Data.Textblock.t_textblock,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":text"),
                    Vx.Core.vx_new_string(","),
                    Vx.Core.vx_new_string(":startpos"),
                    Vx.Core.vx_new_int(4),
                    Vx.Core.vx_new_string(":endpos"),
                    Vx.Core.vx_new_int(4),
                    Vx.Core.vx_new_string(":delim"),
                    Vx.Core.f_copy(
                      Vx.Data.Textblock.c_delimcomma,
                      Vx.Core.vx_new(
                        Vx.Core.t_anylist,
                        Vx.Core.vx_new_string(":pos"),
                        Vx.Core.vx_new_int(0)
                      )
                    )
                  )
                ),
                Vx.Core.f_new(
                  Vx.Data.Textblock.t_textblock,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":text"),
                    Vx.Core.vx_new_string("\"b\""),
                    Vx.Core.vx_new_string(":startpos"),
                    Vx.Core.vx_new_int(5),
                    Vx.Core.vx_new_string(":endpos"),
                    Vx.Core.vx_new_int(7),
                    Vx.Core.vx_new_string(":delim"),
                    Vx.Core.f_copy(
                      Vx.Data.Textblock.c_delimquote,
                      Vx.Core.vx_new(
                        Vx.Core.t_anylist,
                        Vx.Core.vx_new_string(":pos"),
                        Vx.Core.vx_new_int(0)
                      )
                    ),
                    Vx.Core.vx_new_string(":children"),
                    Vx.Core.f_new(
                      Vx.Data.Textblock.t_textblocklist,
                      Vx.Core.vx_new(
                        Vx.Core.t_anylist,
                        Vx.Core.f_new(
                          Vx.Data.Textblock.t_textblock,
                          Vx.Core.vx_new(
                            Vx.Core.t_anylist,
                            Vx.Core.vx_new_string(":text"),
                            Vx.Core.vx_new_string("b"),
                            Vx.Core.vx_new_string(":startpos"),
                            Vx.Core.vx_new_int(6),
                            Vx.Core.vx_new_string(":endpos"),
                            Vx.Core.vx_new_int(6)
                          )
                        )
                      )
                    )
                  )
                ),
                Vx.Core.f_new(
                  Vx.Data.Textblock.t_textblock,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":text"),
                    Vx.Core.vx_new_string("\n"),
                    Vx.Core.vx_new_string(":startpos"),
                    Vx.Core.vx_new_int(8),
                    Vx.Core.vx_new_string(":endpos"),
                    Vx.Core.vx_new_int(8),
                    Vx.Core.vx_new_string(":delim"),
                    Vx.Core.f_copy(
                      Vx.Data.Textblock.c_delimline,
                      Vx.Core.vx_new(
                        Vx.Core.t_anylist,
                        Vx.Core.vx_new_string(":pos"),
                        Vx.Core.vx_new_int(0)
                      )
                    )
                  )
                ),
                Vx.Core.f_new(
                  Vx.Data.Textblock.t_textblock,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":text"),
                    Vx.Core.vx_new_string("1"),
                    Vx.Core.vx_new_string(":startpos"),
                    Vx.Core.vx_new_int(9),
                    Vx.Core.vx_new_string(":endpos"),
                    Vx.Core.vx_new_int(9)
                  )
                ),
                Vx.Core.f_new(
                  Vx.Data.Textblock.t_textblock,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":text"),
                    Vx.Core.vx_new_string(","),
                    Vx.Core.vx_new_string(":startpos"),
                    Vx.Core.vx_new_int(10),
                    Vx.Core.vx_new_string(":endpos"),
                    Vx.Core.vx_new_int(10),
                    Vx.Core.vx_new_string(":delim"),
                    Vx.Core.f_copy(
                      Vx.Data.Textblock.c_delimcomma,
                      Vx.Core.vx_new(
                        Vx.Core.t_anylist,
                        Vx.Core.vx_new_string(":pos"),
                        Vx.Core.vx_new_int(0)
                      )
                    )
                  )
                ),
                Vx.Core.f_new(
                  Vx.Data.Textblock.t_textblock,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":text"),
                    Vx.Core.vx_new_string("\"2\""),
                    Vx.Core.vx_new_string(":startpos"),
                    Vx.Core.vx_new_int(11),
                    Vx.Core.vx_new_string(":endpos"),
                    Vx.Core.vx_new_int(13),
                    Vx.Core.vx_new_string(":delim"),
                    Vx.Core.f_copy(
                      Vx.Data.Textblock.c_delimquote,
                      Vx.Core.vx_new(
                        Vx.Core.t_anylist,
                        Vx.Core.vx_new_string(":pos"),
                        Vx.Core.vx_new_int(0)
                      )
                    ),
                    Vx.Core.vx_new_string(":children"),
                    Vx.Core.f_new(
                      Vx.Data.Textblock.t_textblocklist,
                      Vx.Core.vx_new(
                        Vx.Core.t_anylist,
                        Vx.Core.f_new(
                          Vx.Data.Textblock.t_textblock,
                          Vx.Core.vx_new(
                            Vx.Core.t_anylist,
                            Vx.Core.vx_new_string(":text"),
                            Vx.Core.vx_new_string("2"),
                            Vx.Core.vx_new_string(":startpos"),
                            Vx.Core.vx_new_int(12),
                            Vx.Core.vx_new_string(":endpos"),
                            Vx.Core.vx_new_int(12)
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
        Vx.Data.Csv.f_textblock_csv_from_string(
          Vx.Core.vx_new_string("\"a\",\"b\"\n1,\"2\"")
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcaselist test_cases(Vx.Core.Type_context context) {
    object[] testcases = [
      CsvTest.f_textblock_csv_from_string(context)
    ];
    Vx.Test.Type_testcaselist output = Vx.Core.vx_new(
      Vx.Test.t_testcaselist,
      testcases
    );
    return output;
  }

  public static Vx.Test.Type_testcoveragesummary test_coveragesummary() {
    Vx.Test.Type_testcoveragesummary output = Vx.Core.vx_new(
      Vx.Test.t_testcoveragesummary,
      ":testpkg", "vx/data/csv", 
      ":constnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 1), 
      ":docnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 63, ":tests", 7, ":total", 11), 
      ":funcnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 14, ":tests", 1, ":total", 7), 
      ":bigospacenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 7), 
      ":bigotimenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 7), 
      ":totalnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 9, ":tests", 1, ":total", 11), 
      ":typenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 3)
    );
    return output;
  }

  public static Vx.Test.Type_testcoveragedetail test_coveragedetail() {
    Vx.Test.Type_testcoveragedetail output = Vx.Core.vx_new(
      Vx.Test.t_testcoveragedetail,
      ":testpkg", "vx/data/csv",
      ":typemap", Vx.Core.vx_new(
        Vx.Core.t_intmap,
        ":csv", 0,
        ":csvrowmap", 0,
        ":csvrows", 0
      ), 
      ":constmap", Vx.Core.vx_new(
        Vx.Core.t_intmap,
        ":delimcsv", 0
      ), 
      ":funcmap", Vx.Core.vx_new(
        Vx.Core.t_intmap,
        ":csv-read<-file", 0,
        ":csv<-file", 0,
        ":csv<-string", 0,
        ":csv<-textblock", 0,
        ":csvrows<-textblock", 0,
        ":stringmap<-csv", 0,
        ":textblock-csv<-string", 1
      )
    );
    return output;
  }

  public static Vx.Test.Type_testpackage test_package(Vx.Core.Type_context context) {
    Vx.Test.Type_testcaselist testcaselist = test_cases(context);
    Vx.Test.Type_testpackage output = Vx.Core.vx_new(
      Vx.Test.t_testpackage,
      ":testpkg", "vx/data/csv", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
