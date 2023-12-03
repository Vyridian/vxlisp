
package com.vxlisp.vx;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import com.vxlisp.vx.data.*;


public final class ReplTest {

  static Test.Type_testcase f_any_from_repl(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "any<-repl",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n \"HelloWorld\"\n (any<-repl\n  (repl\n   :type string\n   :repllist\n    (repllist\n     (repl :val \"Hello\")\n     (repl :val \"World\")\n    ))))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("HelloWorld"),
              Repl.f_any_from_repl(
                context,
                Core.f_new(
                  Repl.t_repl,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":type"),
                    Core.t_string,
                    Core.vx_new_string(":repllist"),
                    Core.f_new(
                      Repl.t_repllist,
                      Core.t_anylist.vx_new(
                        Core.f_new(
                          Repl.t_repl,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":val"),
                            Core.vx_new_string("Hello")
                          )
                        ),
                        Core.f_new(
                          Repl.t_repl,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":val"),
                            Core.vx_new_string("World")
                          )
                        )
                      )
                    )
                  )
                )
              )
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n 5\n (any<-repl\n  (repl\n   :type +\n   :repllist\n    (repllist\n     (repl :val 2)\n     (repl :val 3)\n    ))))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_int(5),
              Repl.f_any_from_repl(
                context,
                Core.f_new(
                  Repl.t_repl,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":type"),
                    Core.t_plus,
                    Core.vx_new_string(":repllist"),
                    Core.f_new(
                      Repl.t_repllist,
                      Core.t_anylist.vx_new(
                        Core.f_new(
                          Repl.t_repl,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":val"),
                            Core.vx_new_int(2)
                          )
                        ),
                        Core.f_new(
                          Repl.t_repl,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":val"),
                            Core.vx_new_int(3)
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
    );
    return output;
  }

  static Test.Type_testcase f_textblock_repl_from_script(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "textblock-repl<-script",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (tb/textblock\n  :text \"(+ 2 3)\"\n  :startpos 1\n  :endpos 7\n  :children\n   (tb/textblocklist\n    (tb/textblock\n     :text \"(+ 2 3)\"\n     :startpos 1\n     :endpos 7\n     :delim\n      (copy delimvxlispparen\n       :delimlist\n        (empty delimlist))\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"+\"\n        :startpos 2\n        :endpos 2)\n       (tb/textblock\n        :text \" \"\n        :startpos 3\n        :endpos 3\n        :delim\n         (copy tb/delimwhitespace\n          :pos 0))\n       (tb/textblock\n        :text \"2\"\n        :startpos 4\n        :endpos 4)\n       (tb/textblock\n        :text \" \"\n        :startpos 5\n        :endpos 5\n        :delim\n         (copy tb/delimwhitespace\n          :pos 0))\n       (tb/textblock\n        :text \"3\"\n        :startpos 6\n        :endpos 6)))))\n (textblock-repl<-script\n  \"(+ 2 3)\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Textblock.t_textblock,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":text"),
                  Core.vx_new_string("(+ 2 3)"),
                  Core.vx_new_string(":startpos"),
                  Core.vx_new_int(1),
                  Core.vx_new_string(":endpos"),
                  Core.vx_new_int(7),
                  Core.vx_new_string(":children"),
                  Core.f_new(
                    Textblock.t_textblocklist,
                    Core.t_anylist.vx_new(
                      Core.f_new(
                        Textblock.t_textblock,
                        Core.t_anylist.vx_new(
                          Core.vx_new_string(":text"),
                          Core.vx_new_string("(+ 2 3)"),
                          Core.vx_new_string(":startpos"),
                          Core.vx_new_int(1),
                          Core.vx_new_string(":endpos"),
                          Core.vx_new_int(7),
                          Core.vx_new_string(":delim"),
                          Core.f_copy(
                            Repl.c_delimvxlispparen,
                            Core.t_anylist.vx_new(
                              Core.vx_new_string(":delimlist"),
                              Core.f_empty(
                                Textblock.t_delimlist
                              )
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
                                  Core.vx_new_string("+"),
                                  Core.vx_new_string(":startpos"),
                                  Core.vx_new_int(2),
                                  Core.vx_new_string(":endpos"),
                                  Core.vx_new_int(2)
                                )
                              ),
                              Core.f_new(
                                Textblock.t_textblock,
                                Core.t_anylist.vx_new(
                                  Core.vx_new_string(":text"),
                                  Core.vx_new_string(" "),
                                  Core.vx_new_string(":startpos"),
                                  Core.vx_new_int(3),
                                  Core.vx_new_string(":endpos"),
                                  Core.vx_new_int(3),
                                  Core.vx_new_string(":delim"),
                                  Core.f_copy(
                                    Textblock.c_delimwhitespace,
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
                                  Core.vx_new_string("2"),
                                  Core.vx_new_string(":startpos"),
                                  Core.vx_new_int(4),
                                  Core.vx_new_string(":endpos"),
                                  Core.vx_new_int(4)
                                )
                              ),
                              Core.f_new(
                                Textblock.t_textblock,
                                Core.t_anylist.vx_new(
                                  Core.vx_new_string(":text"),
                                  Core.vx_new_string(" "),
                                  Core.vx_new_string(":startpos"),
                                  Core.vx_new_int(5),
                                  Core.vx_new_string(":endpos"),
                                  Core.vx_new_int(5),
                                  Core.vx_new_string(":delim"),
                                  Core.f_copy(
                                    Textblock.c_delimwhitespace,
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
                                  Core.vx_new_string("3"),
                                  Core.vx_new_string(":startpos"),
                                  Core.vx_new_int(6),
                                  Core.vx_new_string(":endpos"),
                                  Core.vx_new_int(6)
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
              Repl.f_textblock_repl_from_script(Core.vx_new_string("(+ 2 3)"))
            )
        )
      )
    );
    return output;
  }

  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(
      ReplTest.f_any_from_repl(context),
      ReplTest.f_textblock_repl_from_script(context)
    ));
    Test.Type_testcaselist output = Test.t_testcaselist.vx_new(arraylisttestcase);
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    return Test.t_testcoveragesummary.vx_new(
      ":testpkg",   "vx/repl", 
      ":constnums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 3), 
      ":docnums", Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 15, ":total", 15), 
      ":funcnums", Test.t_testcoveragenums.vx_new(":pct", 22, ":tests", 2, ":total", 9), 
      ":ospacenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 9), 
      ":otimenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 9), 
      ":totalnums", Test.t_testcoveragenums.vx_new(":pct", 13, ":tests", 2, ":total", 15), 
      ":typenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 3)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Test.t_testcoveragedetail.vx_new(
      ":testpkg", "vx/repl",
      ":typemap", Core.t_intmap.vx_new(
        ":liblist", 0,
        ":repl", 0,
        ":repllist", 0
      ),
      ":constmap", Core.t_intmap.vx_new(
        ":delimvxlisp", 0,
        ":delimvxlispbracket", 0,
        ":delimvxlispparen", 0
      ),
      ":funcmap", Core.t_intmap.vx_new(
        ":any-repl<-functype-args", 0,
        ":any<-liblist-string", 0,
        ":any<-repl", 2,
        ":any<-script", 0,
        ":anylist<-repllist", 0,
        ":macro", 0,
        ":repl<-liblist-string", 0,
        ":repl<-textblock", 0,
        ":textblock-repl<-script", 1
      )
    );
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Test.t_testpackage.vx_new(
      ":testpkg", "vx/repl", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
