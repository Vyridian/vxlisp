
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

  static Test.Type_testcase f_any_from_script(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "any<-script",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n 5\n (any<-script\n  \"(+ 2 3)\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_int(5),
              Repl.f_any_from_script(context, Core.vx_new_string("(+ 2 3)"))
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_const_from_string(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "const<-string",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n infinity\n (const<-string\n  \"infinity\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.c_infinity,
              Repl.f_const_from_string(Core.vx_new_string("infinity"))
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n tb/delimcomma\n (const<-string\n  \"vx/data/textblock/delimcomma\"))",
          ":testresult",
            Test.f_test(
              context,
              Textblock.c_delimcomma,
              Repl.f_const_from_string(Core.vx_new_string("vx/data/textblock/delimcomma"))
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_macro(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "macro",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n 5\n (macro : int\n  \"(+ \"\n  (- 7 5)\n  \" 3)\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_int(5),
              Repl.f_macro(
                Core.t_int,
                context,
                Core.t_anylist.vx_new(
                  Core.vx_new_string("(+ "),
                  Core.f_minus(Core.vx_new_int(7), Core.vx_new_int(5)),
                  Core.vx_new_string(" 3)")
                )
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_repl_empty_from_textblock_argmap(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl-empty<-textblock-argmap",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (repl :val 2)\n (repl-empty<-textblock-argmap\n  (tb/textblock\n   :text \"2\")\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":val"),
                  Core.vx_new_int(2)
                )
              ),
              Repl.f_repl_empty_from_textblock_argmap(
                Core.f_new(
                  Textblock.t_textblock,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("2")
                  )
                ),
                Core.f_empty(
                  Core.t_argmap
                )
              )
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (repl :type +)\n (repl-empty<-textblock-argmap\n  (tb/textblock\n   :text \"+\")\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":type"),
                  Core.t_plus
                )
              ),
              Repl.f_repl_empty_from_textblock_argmap(
                Core.f_new(
                  Textblock.t_textblock,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("+")
                  )
                ),
                Core.f_empty(
                  Core.t_argmap
                )
              )
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (repl :val 2)\n (repl-empty<-textblock-argmap\n  (tb/textblock\n   :text \"1\"\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"2\")))\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":val"),
                  Core.vx_new_int(2)
                )
              ),
              Repl.f_repl_empty_from_textblock_argmap(
                Core.f_new(
                  Textblock.t_textblock,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("1"),
                    Core.vx_new_string(":children"),
                    Core.f_new(
                      Textblock.t_textblocklist,
                      Core.t_anylist.vx_new(
                        Core.f_new(
                          Textblock.t_textblock,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":text"),
                            Core.vx_new_string("2")
                          )
                        )
                      )
                    )
                  )
                ),
                Core.f_empty(
                  Core.t_argmap
                )
              )
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (repl\n  (msg<-error \"Empty delim cannot have more than one child.\"))\n (repl-empty<-textblock-argmap\n  (tb/textblock\n   :text \"1\"\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"2\")\n     (tb/textblock\n      :text \"3\")))\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.t_anylist.vx_new(
                  Core.f_msg_from_error(Core.vx_new_string("Empty delim cannot have more than one child."))
                )
              ),
              Repl.f_repl_empty_from_textblock_argmap(
                Core.f_new(
                  Textblock.t_textblock,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("1"),
                    Core.vx_new_string(":children"),
                    Core.f_new(
                      Textblock.t_textblocklist,
                      Core.t_anylist.vx_new(
                        Core.f_new(
                          Textblock.t_textblock,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":text"),
                            Core.vx_new_string("2")
                          )
                        ),
                        Core.f_new(
                          Textblock.t_textblock,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":text"),
                            Core.vx_new_string("3")
                          )
                        )
                      )
                    )
                  )
                ),
                Core.f_empty(
                  Core.t_argmap
                )
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_repl_paren_from_textblock_argmap(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl-paren<-textblock-argmap",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (repl\n  :type vx/core/+\n  :repllist\n   (repllist\n    (repl\n     :val 2)\n    (repl\n     :val 3)))\n (repl-paren<-textblock-argmap\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :delim\n    (copy delimvxlispparen\n     :delimlist\n      (empty delimlist))\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"+\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"2\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"3\")))\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
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
              ),
              Repl.f_repl_paren_from_textblock_argmap(
                Core.f_new(
                  Textblock.t_textblock,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("(+ 2 3)"),
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
                            Core.vx_new_string("+")
                          )
                        ),
                        Core.f_new(
                          Textblock.t_textblock,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":text"),
                            Core.vx_new_string(" "),
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
                            Core.vx_new_string("2")
                          )
                        ),
                        Core.f_new(
                          Textblock.t_textblock,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":text"),
                            Core.vx_new_string(" "),
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
                            Core.vx_new_string("3")
                          )
                        )
                      )
                    )
                  )
                ),
                Core.f_empty(
                  Core.t_argmap
                )
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_repl_from_script(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl<-script",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (repl\n  :val 2)\n (repl<-script\n  \"2\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":val"),
                  Core.vx_new_int(2)
                )
              ),
              Repl.f_repl_from_script(Core.vx_new_string("2"))
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (repl\n  :val infinity)\n (repl<-script\n  \"infinity\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":val"),
                  Core.c_infinity
                )
              ),
              Repl.f_repl_from_script(Core.vx_new_string("infinity"))
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (repl\n  :type +)\n (repl<-script\n  \"+\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":type"),
                  Core.t_plus
                )
              ),
              Repl.f_repl_from_script(Core.vx_new_string("+"))
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl\n     :val 2)\n    (repl\n     :val 3)))\n (repl<-script\n  \"(+ 2 3)\"))",
          ":testresult",
            Test.f_test(
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
              ),
              Repl.f_repl_from_script(Core.vx_new_string("(+ 2 3)"))
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_repl_from_string_argmap(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl<-string-argmap",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (repl :val \"Hello\")\n (repl<-string-argmap\n  `\"Hello\"`\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":val"),
                  Core.vx_new_string("Hello")
                )
              ),
              Repl.f_repl_from_string_argmap(
                Core.vx_new_string("\"Hello\""),
                Core.f_empty(
                  Core.t_argmap
                )
              )
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (repl\n  :val 2)\n (repl<-string-argmap\n  \"2\"\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":val"),
                  Core.vx_new_int(2)
                )
              ),
              Repl.f_repl_from_string_argmap(
                Core.vx_new_string("2"),
                Core.f_empty(
                  Core.t_argmap
                )
              )
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (repl :val 2.3)\n (repl<-string-argmap\n  \"2.3\"\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":val"),
                  Core.t_decimal.vx_new_from_string("2.3")
                )
              ),
              Repl.f_repl_from_string_argmap(
                Core.vx_new_string("2.3"),
                Core.f_empty(
                  Core.t_argmap
                )
              )
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (repl\n  :val infinity)\n (repl<-string-argmap\n  \"infinity\"\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":val"),
                  Core.c_infinity
                )
              ),
              Repl.f_repl_from_string_argmap(
                Core.vx_new_string("infinity"),
                Core.f_empty(
                  Core.t_argmap
                )
              )
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (repl\n  :val tb/delimcomma)\n (repl<-string-argmap\n  \"vx/data/textblock/delimcomma\"\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":val"),
                  Textblock.c_delimcomma
                )
              ),
              Repl.f_repl_from_string_argmap(
                Core.vx_new_string("vx/data/textblock/delimcomma"),
                Core.f_empty(
                  Core.t_argmap
                )
              )
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (repl :type string)\n (repl<-string-argmap\n  \"string\"\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":type"),
                  Core.t_string
                )
              ),
              Repl.f_repl_from_string_argmap(
                Core.vx_new_string("string"),
                Core.f_empty(
                  Core.t_argmap
                )
              )
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (repl :type +)\n (repl<-string-argmap\n  \"+\"\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":type"),
                  Core.t_plus
                )
              ),
              Repl.f_repl_from_string_argmap(
                Core.vx_new_string("+"),
                Core.f_empty(
                  Core.t_argmap
                )
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_repl_from_textblock(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl<-textblock",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (repl :val 2)\n (repl<-textblock\n  (tb/textblock\n   :text \"2\")))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":val"),
                  Core.vx_new_int(2)
                )
              ),
              Repl.f_repl_from_textblock(
                Core.f_new(
                  Textblock.t_textblock,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("2")
                  )
                )
              )
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (repl :type +)\n (repl<-textblock\n  (tb/textblock\n   :text \"+\")))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":type"),
                  Core.t_plus
                )
              ),
              Repl.f_repl_from_textblock(
                Core.f_new(
                  Textblock.t_textblock,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("+")
                  )
                )
              )
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (repl :type +)\n (repl<-textblock\n  (tb/textblock\n   :text \"+\")))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":type"),
                  Core.t_plus
                )
              ),
              Repl.f_repl_from_textblock(
                Core.f_new(
                  Textblock.t_textblock,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("+")
                  )
                )
              )
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl :val 2)\n    (repl :val 3)))\n (repl<-textblock\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :delim\n    (copy delimvxlispparen\n     :delimlist\n      (empty delimlist))\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"+\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"2\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"3\")))))",
          ":testresult",
            Test.f_test(
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
              ),
              Repl.f_repl_from_textblock(
                Core.f_new(
                  Textblock.t_textblock,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("(+ 2 3)"),
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
                            Core.vx_new_string("+")
                          )
                        ),
                        Core.f_new(
                          Textblock.t_textblock,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":text"),
                            Core.vx_new_string(" "),
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
                            Core.vx_new_string("2")
                          )
                        ),
                        Core.f_new(
                          Textblock.t_textblock,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":text"),
                            Core.vx_new_string(" "),
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
                            Core.vx_new_string("3")
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
          ":describename", "(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl :val 2)\n    (repl :val 3)))\n (repl<-textblock\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"(+ 2 3)\"\n      :delim\n       (copy delimvxlispparen\n        :delimlist\n         (empty delimlist))\n      :children\n       (tb/textblocklist\n        (tb/textblock\n         :text \"+\")\n        (tb/textblock\n         :text \" \"\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"2\")\n        (tb/textblock\n         :text \" \"\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"3\")))))))",
          ":testresult",
            Test.f_test(
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
              ),
              Repl.f_repl_from_textblock(
                Core.f_new(
                  Textblock.t_textblock,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("(+ 2 3)"),
                    Core.vx_new_string(":children"),
                    Core.f_new(
                      Textblock.t_textblocklist,
                      Core.t_anylist.vx_new(
                        Core.f_new(
                          Textblock.t_textblock,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":text"),
                            Core.vx_new_string("(+ 2 3)"),
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
                                    Core.vx_new_string("+")
                                  )
                                ),
                                Core.f_new(
                                  Textblock.t_textblock,
                                  Core.t_anylist.vx_new(
                                    Core.vx_new_string(":text"),
                                    Core.vx_new_string(" "),
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
                                    Core.vx_new_string("2")
                                  )
                                ),
                                Core.f_new(
                                  Textblock.t_textblock,
                                  Core.t_anylist.vx_new(
                                    Core.vx_new_string(":text"),
                                    Core.vx_new_string(" "),
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
                                    Core.vx_new_string("3")
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
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_repl_from_textblock_argmap(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl<-textblock-argmap",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (repl :val 2)\n (repl<-textblock-argmap\n  (tb/textblock\n   :text \"2\")\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":val"),
                  Core.vx_new_int(2)
                )
              ),
              Repl.f_repl_from_textblock_argmap(
                Core.f_new(
                  Textblock.t_textblock,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("2")
                  )
                ),
                Core.f_empty(
                  Core.t_argmap
                )
              )
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (repl :type +)\n (repl<-textblock-argmap\n  (tb/textblock\n   :text \"+\")\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":type"),
                  Core.t_plus
                )
              ),
              Repl.f_repl_from_textblock_argmap(
                Core.f_new(
                  Textblock.t_textblock,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("+")
                  )
                ),
                Core.f_empty(
                  Core.t_argmap
                )
              )
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl :val 2)\n    (repl :val 3)))\n (repl<-textblock-argmap\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :delim\n    (copy delimvxlispparen\n     :delimlist\n      (empty delimlist))\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"+\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"2\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"3\")))\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
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
              ),
              Repl.f_repl_from_textblock_argmap(
                Core.f_new(
                  Textblock.t_textblock,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("(+ 2 3)"),
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
                            Core.vx_new_string("+")
                          )
                        ),
                        Core.f_new(
                          Textblock.t_textblock,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":text"),
                            Core.vx_new_string(" "),
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
                            Core.vx_new_string("2")
                          )
                        ),
                        Core.f_new(
                          Textblock.t_textblock,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":text"),
                            Core.vx_new_string(" "),
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
                            Core.vx_new_string("3")
                          )
                        )
                      )
                    )
                  )
                ),
                Core.f_empty(
                  Core.t_argmap
                )
              )
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl :val 2)\n    (repl :val 3)))\n (repl<-textblock-argmap\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"(+ 2 3)\"\n      :delim\n       (copy delimvxlispparen\n        :delimlist\n         (empty delimlist))\n      :children\n       (tb/textblocklist\n        (tb/textblock\n         :text \"+\")\n        (tb/textblock\n         :text \" \"\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"2\")\n        (tb/textblock\n         :text \" \"\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"3\")))))\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
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
              ),
              Repl.f_repl_from_textblock_argmap(
                Core.f_new(
                  Textblock.t_textblock,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("(+ 2 3)"),
                    Core.vx_new_string(":children"),
                    Core.f_new(
                      Textblock.t_textblocklist,
                      Core.t_anylist.vx_new(
                        Core.f_new(
                          Textblock.t_textblock,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":text"),
                            Core.vx_new_string("(+ 2 3)"),
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
                                    Core.vx_new_string("+")
                                  )
                                ),
                                Core.f_new(
                                  Textblock.t_textblock,
                                  Core.t_anylist.vx_new(
                                    Core.vx_new_string(":text"),
                                    Core.vx_new_string(" "),
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
                                    Core.vx_new_string("2")
                                  )
                                ),
                                Core.f_new(
                                  Textblock.t_textblock,
                                  Core.t_anylist.vx_new(
                                    Core.vx_new_string(":text"),
                                    Core.vx_new_string(" "),
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
                                    Core.vx_new_string("3")
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
                Core.f_empty(
                  Core.t_argmap
                )
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_textblock_from_script(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "textblock<-script",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (tb/textblock\n  :text \"infinity\"\n  :startpos 1\n  :endpos 8\n  :children\n   (tb/textblocklist\n    (tb/textblock\n    :text \"infinity\"\n    :startpos 1\n    :endpos 8\n    :delim\n     (delim\n      :name \"delimvxlisp\"))))\n (textblock<-script\n  \"infinity\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Textblock.t_textblock,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":text"),
                  Core.vx_new_string("infinity"),
                  Core.vx_new_string(":startpos"),
                  Core.vx_new_int(1),
                  Core.vx_new_string(":endpos"),
                  Core.vx_new_int(8),
                  Core.vx_new_string(":children"),
                  Core.f_new(
                    Textblock.t_textblocklist,
                    Core.t_anylist.vx_new(
                      Core.f_new(
                        Textblock.t_textblock,
                        Core.t_anylist.vx_new(
                          Core.vx_new_string(":text"),
                          Core.vx_new_string("infinity"),
                          Core.vx_new_string(":startpos"),
                          Core.vx_new_int(1),
                          Core.vx_new_string(":endpos"),
                          Core.vx_new_int(8),
                          Core.vx_new_string(":delim"),
                          Core.f_new(
                            Textblock.t_delim,
                            Core.t_anylist.vx_new(
                              Core.vx_new_string(":name"),
                              Core.vx_new_string("delimvxlisp")
                            )
                          )
                        )
                      )
                    )
                  )
                )
              ),
              Repl.f_textblock_from_script(Core.vx_new_string("infinity"))
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (tb/textblock\n  :text \"(+ 2 3)\"\n  :startpos 1\n  :endpos 7\n  :children\n   (tb/textblocklist\n    (tb/textblock\n     :text \"(+ 2 3)\"\n     :startpos 1\n     :endpos 7\n     :delim\n      (copy delimvxlispparen\n       :delimlist\n        (empty delimlist))\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"+\"\n        :startpos 2\n        :endpos 2)\n       (tb/textblock\n        :text \" \"\n        :startpos 3\n        :endpos 3\n        :delim\n         (copy tb/delimwhitespace\n          :pos 0))\n       (tb/textblock\n        :text \"2\"\n        :startpos 4\n        :endpos 4)\n       (tb/textblock\n        :text \" \"\n        :startpos 5\n        :endpos 5\n        :delim\n         (copy tb/delimwhitespace\n          :pos 0))\n       (tb/textblock\n        :text \"3\"\n        :startpos 6\n        :endpos 6)))))\n (textblock<-script\n  \"(+ 2 3)\"))",
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
              Repl.f_textblock_from_script(Core.vx_new_string("(+ 2 3)"))
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_typefunc_from_string(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "typefunc<-string",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n string\n (typefunc<-string\n  \"string\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.t_string,
              Repl.f_typefunc_from_string(Core.vx_new_string("string"))
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n +\n (typefunc<-string\n  \"+\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.t_plus,
              Repl.f_typefunc_from_string(Core.vx_new_string("+"))
            )
        )
      )
    );
    return output;
  }

  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(
      ReplTest.f_any_from_repl(context),
      ReplTest.f_any_from_script(context),
      ReplTest.f_const_from_string(context),
      ReplTest.f_macro(context),
      ReplTest.f_repl_empty_from_textblock_argmap(context),
      ReplTest.f_repl_paren_from_textblock_argmap(context),
      ReplTest.f_repl_from_script(context),
      ReplTest.f_repl_from_string_argmap(context),
      ReplTest.f_repl_from_textblock(context),
      ReplTest.f_repl_from_textblock_argmap(context),
      ReplTest.f_textblock_from_script(context),
      ReplTest.f_typefunc_from_string(context)
    ));
    Test.Type_testcaselist output = Test.t_testcaselist.vx_new(arraylisttestcase);
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    return Test.t_testcoveragesummary.vx_new(
      ":testpkg",   "vx/repl", 
      ":constnums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 3), 
      ":docnums", Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 24, ":total", 24), 
      ":funcnums", Test.t_testcoveragenums.vx_new(":pct", 66, ":tests", 12, ":total", 18), 
      ":ospacenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 18), 
      ":otimenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 18), 
      ":totalnums", Test.t_testcoveragenums.vx_new(":pct", 50, ":tests", 12, ":total", 24), 
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
        ":any<-script", 1,
        ":anylist<-repllist", 0,
        ":argmap<-textblock-argmap", 0,
        ":const<-string", 2,
        ":macro", 1,
        ":repl-empty<-textblock-argmap", 4,
        ":repl-paren<-textblock-argmap", 1,
        ":repl<-liblist-string", 0,
        ":repl<-script", 4,
        ":repl<-string-argmap", 7,
        ":repl<-textblock", 5,
        ":repl<-textblock-argmap", 4,
        ":repllist<-textblocklist-argmap", 0,
        ":textblock<-script", 2,
        ":typefunc<-string", 2
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
