
package com.vxlisp.vx.data;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import com.vxlisp.vx.*;


public final class TextblockTest {

  static Test.Type_testcase f_delim_first_from_delim_delim(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/data/textblock",
      ":casename", "delim-first<-delim-delim",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (copy delimcomma\n  :startpos 1)\n (delim-first<-delim-delim\n  (copy delimspace\n   :startpos 2)\n  (copy delimcomma\n   :startpos 1)))",
          ":testresult",
            Test.f_test(
              Core.f_copy(
                Textblock.c_delimcomma,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":startpos"),
                  Core.vx_new_int(1)
                )
              ),
              Textblock.f_delim_first_from_delim_delim(
                Core.f_copy(
                  Textblock.c_delimspace,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":startpos"),
                    Core.vx_new_int(2)
                  )
                ),
                Core.f_copy(
                  Textblock.c_delimcomma,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":startpos"),
                    Core.vx_new_int(1)
                  )
                )
              ),
              context
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_delim_first_from_string_delimlist(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/data/textblock",
      ":casename", "delim-first<-string-delimlist",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (copy delimcomma\n  :startpos 1)\n (delim-first<-string-delimlist\n  \"a, b\"\n  (delimlist delimspace delimcomma)))",
          ":testresult",
            Test.f_test(
              Core.f_copy(
                Textblock.c_delimcomma,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":startpos"),
                  Core.vx_new_int(1)
                )
              ),
              Textblock.f_delim_first_from_string_delimlist(
                Core.vx_new_string("a, b"),
                Core.f_new(
                  Textblock.t_delimlist,
                  Core.t_anylist.vx_new(
                    Textblock.c_delimspace,
                    Textblock.c_delimcomma
                  )
                )
              ),
              context
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_delim_startpos_from_string_delim(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/data/textblock",
      ":casename", "delim-startpos<-string-delim",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (copy delimcomma\n  :startpos 1)\n (delim-startpos<-string-delim\n  \"a,b\"\n  delimcomma))",
          ":testresult",
            Test.f_test(
              Core.f_copy(
                Textblock.c_delimcomma,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":startpos"),
                  Core.vx_new_int(1)
                )
              ),
              Textblock.f_delim_startpos_from_string_delim(
                Core.vx_new_string("a,b"),
                Textblock.c_delimcomma
              ),
              context
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_delimlist_startpos_from_string_delimlist(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/data/textblock",
      ":casename", "delimlist-startpos<-string-delimlist",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (delimlist\n  (copy delimspace\n   :startpos 2)\n  (copy delimcomma\n   :startpos 1))\n (delimlist-startpos<-string-delimlist\n  \"a, b\"\n  (delimlist delimspace delimcomma)))",
          ":testresult",
            Test.f_test(
              Core.f_new(
                Textblock.t_delimlist,
                Core.t_anylist.vx_new(
                  Core.f_copy(
                    Textblock.c_delimspace,
                    Core.t_anylist.vx_new(
                      Core.vx_new_string(":startpos"),
                      Core.vx_new_int(2)
                    )
                  ),
                  Core.f_copy(
                    Textblock.c_delimcomma,
                    Core.t_anylist.vx_new(
                      Core.vx_new_string(":startpos"),
                      Core.vx_new_int(1)
                    )
                  )
                )
              ),
              Textblock.f_delimlist_startpos_from_string_delimlist(
                Core.vx_new_string("a, b"),
                Core.f_new(
                  Textblock.t_delimlist,
                  Core.t_anylist.vx_new(
                    Textblock.c_delimspace,
                    Textblock.c_delimcomma
                  )
                )
              ),
              context
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_textblock_firstdelim_from_textblock_delimlist(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/data/textblock",
      ":casename", "textblock-firstdelim<-textblock-delimlist",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (textblock\n  :delim\n   (copy delimcomma\n    :startpos 1)\n  :text \" b\"\n  :parent\n   (textblock\n    :text \"a, b\"\n    :textblocks\n     (textblocklist\n      (textblock\n       :text \"a\"))))\n (textblock-firstdelim<-textblock-delimlist\n  (textblock\n   :text \"a, b\")\n  (delimlist delimspace delimcomma)))",
          ":testresult",
            Test.f_test(
              Core.f_new(
                Textblock.t_textblock,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":delim"),
                  Core.f_copy(
                    Textblock.c_delimcomma,
                    Core.t_anylist.vx_new(
                      Core.vx_new_string(":startpos"),
                      Core.vx_new_int(1)
                    )
                  ),
                  Core.vx_new_string(":text"),
                  Core.vx_new_string(" b"),
                  Core.vx_new_string(":parent"),
                  Core.f_new(
                    Textblock.t_textblock,
                    Core.t_anylist.vx_new(
                      Core.vx_new_string(":text"),
                      Core.vx_new_string("a, b"),
                      Core.vx_new_string(":textblocks"),
                      Core.f_new(
                        Textblock.t_textblocklist,
                        Core.t_anylist.vx_new(
                          Core.f_new(
                            Textblock.t_textblock,
                            Core.t_anylist.vx_new(
                              Core.vx_new_string(":text"),
                              Core.vx_new_string("a")
                            )
                          )
                        )
                      )
                    )
                  )
                )
              ),
              Textblock.f_textblock_firstdelim_from_textblock_delimlist(
                Core.f_new(
                  Textblock.t_textblock,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("a, b")
                  )
                ),
                Core.f_new(
                  Textblock.t_delimlist,
                  Core.t_anylist.vx_new(
                    Textblock.c_delimspace,
                    Textblock.c_delimcomma
                  )
                )
              ),
              context
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_textblock_startafter_from_string_delim(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/data/textblock",
      ":casename", "textblock-startafter<-string-delim",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (textblock\n  :text \" b\")\n (textblock-startafter<-string-delim\n  \"a, b\"\n  (delim\n   :starttext \",\"\n   :startpos  1)))",
          ":testresult",
            Test.f_test(
              Core.f_new(
                Textblock.t_textblock,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":text"),
                  Core.vx_new_string(" b")
                )
              ),
              Textblock.f_textblock_startafter_from_string_delim(
                Core.vx_new_string("a, b"),
                Core.f_new(
                  Textblock.t_delim,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":starttext"),
                    Core.vx_new_string(","),
                    Core.vx_new_string(":startpos"),
                    Core.vx_new_int(1)
                  )
                )
              ),
              context
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_textblock_startbefore_from_string_delim(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/data/textblock",
      ":casename", "textblock-startbefore<-string-delim",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (textblock\n  :text \"a\")\n (textblock-startbefore<-string-delim\n  \"a, b\"\n  (delim\n   :startpos 1)))",
          ":testresult",
            Test.f_test(
              Core.f_new(
                Textblock.t_textblock,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":text"),
                  Core.vx_new_string("a")
                )
              ),
              Textblock.f_textblock_startbefore_from_string_delim(
                Core.vx_new_string("a, b"),
                Core.f_new(
                  Textblock.t_delim,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":startpos"),
                    Core.vx_new_int(1)
                  )
                )
              ),
              context
            )
        )
      )
    );
    return output;
  }

  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(
      TextblockTest.f_delim_first_from_delim_delim(context),
      TextblockTest.f_delim_first_from_string_delimlist(context),
      TextblockTest.f_delim_startpos_from_string_delim(context),
      TextblockTest.f_delimlist_startpos_from_string_delimlist(context),
      TextblockTest.f_textblock_firstdelim_from_textblock_delimlist(context),
      TextblockTest.f_textblock_startafter_from_string_delim(context),
      TextblockTest.f_textblock_startbefore_from_string_delim(context)
    ));
    Test.Type_testcaselist output = Test.t_testcaselist.vx_new(arraylisttestcase);
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    return Test.t_testcoveragesummary.vx_new(
      ":testpkg",   "vx/data/textblock", 
      ":constnums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 15), 
      ":docnums", Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 30, ":total", 30), 
      ":funcnums", Test.t_testcoveragenums.vx_new(":pct", 63, ":tests", 7, ":total", 11), 
      ":ospacenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 11), 
      ":otimenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 11), 
      ":totalnums", Test.t_testcoveragenums.vx_new(":pct", 23, ":tests", 7, ":total", 30), 
      ":typenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 4)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Test.t_testcoveragedetail.vx_new(
      ":testpkg", "vx/data/textblock",
      ":typemap", Core.t_intmap.vx_new(
        ":delim", 0,
        ":delimlist", 0,
        ":textblock", 0,
        ":textblocklist", 0
      ),
      ":constmap", Core.t_intmap.vx_new(
        ":delimbracketcurly", 0,
        ":delimbracketsquare", 0,
        ":delimclose", 0,
        ":delimcomma", 0,
        ":delimcomment", 0,
        ":delimcommentblock", 0,
        ":delimline", 0,
        ":delimnonwhitespace", 0,
        ":delimparen", 0,
        ":delimparenline", 0,
        ":delimquote", 0,
        ":delimquoteblock", 0,
        ":delimspace", 0,
        ":delimtext", 0,
        ":delimwhitespace", 0
      ),
      ":funcmap", Core.t_intmap.vx_new(
        ":delim-first<-delim-delim", 1,
        ":delim-first<-string-delimlist", 1,
        ":delim-startpos<-string-delim", 1,
        ":delimlist-startpos<-string-delimlist", 1,
        ":stringlist<-textblocklist", 0,
        ":text<-textblock", 0,
        ":textblock-firstdelim<-textblock-delimlist", 1,
        ":textblock-startafter<-string-delim", 1,
        ":textblock-startbefore<-string-delim", 1,
        ":textblock<-textblock-delim", 0,
        ":textblocks<-textblock", 0
      )
    );
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Test.t_testpackage.vx_new(
      ":testpkg", "vx/data/textblock", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
