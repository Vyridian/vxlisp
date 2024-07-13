
package com.vxlisp.vx;

import java.util.List;
import com.vxlisp.vx.data.*;

public final class ReplTest {

  static Test.Type_testcase f_any_from_macro(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "any<-macro",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n 5\n (any<-macro : int\n  \"(+ \"\n  (- 7 5)\n  \" 3)\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_int(5),
              Repl.f_any_from_macro(
                Core.t_int,
                context,
                Core.vx_new(Core.t_anylist,
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

  static Test.Type_testcase f_any_from_repl(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "any<-repl",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"HelloWorld\"\n (any<-repl\n  (repl\n   :type string\n   :repllist\n    (repllist\n     (repl :val \"Hello\")\n     (repl :val \"World\")\n    ))))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("HelloWorld"),
              Repl.f_any_from_repl(
                context,
                Core.f_new(
                  Repl.t_repl,
                  Core.vx_new(Core.t_anylist,
                    Core.vx_new_string(":type"),
                    Core.t_string,
                    Core.vx_new_string(":repllist"),
                    Core.f_new(
                      Repl.t_repllist,
                      Core.vx_new(Core.t_anylist,
                        Core.f_new(
                          Repl.t_repl,
                          Core.vx_new(Core.t_anylist,
                            Core.vx_new_string(":val"),
                            Core.vx_new_string("Hello")
                          )
                        ),
                        Core.f_new(
                          Repl.t_repl,
                          Core.vx_new(Core.t_anylist,
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
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n 5\n (any<-repl\n  (repl\n   :type +\n   :repllist\n    (repllist\n     (repl :val 2)\n     (repl :val 3)))))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_int(5),
              Repl.f_any_from_repl(
                context,
                Core.f_new(
                  Repl.t_repl,
                  Core.vx_new(Core.t_anylist,
                    Core.vx_new_string(":type"),
                    Core.t_plus,
                    Core.vx_new_string(":repllist"),
                    Core.f_new(
                      Repl.t_repllist,
                      Core.vx_new(Core.t_anylist,
                        Core.f_new(
                          Repl.t_repl,
                          Core.vx_new(Core.t_anylist,
                            Core.vx_new_string(":val"),
                            Core.vx_new_int(2)
                          )
                        ),
                        Core.f_new(
                          Repl.t_repl,
                          Core.vx_new(Core.t_anylist,
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
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "any<-script",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
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
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "const<-string",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n infinity\n (const<-string\n  \"infinity\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.c_infinity,
              Repl.f_const_from_string(Core.vx_new_string("infinity"))
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
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

  static Test.Type_testcase f_repl_empty_from_textblock_argmap(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl-empty<-textblock-argmap",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl :val 2)\n (repl-empty<-textblock-argmap\n  (tb/textblock\n   :text \"2\")\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
                  Core.vx_new_string(":val"),
                  Core.vx_new_int(2)
                )
              ),
              Repl.f_repl_empty_from_textblock_argmap(
                Core.f_new(
                  Textblock.t_textblock,
                  Core.vx_new(Core.t_anylist,
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
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl :type +)\n (repl-empty<-textblock-argmap\n  (tb/textblock\n   :text \"+\")\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
                  Core.vx_new_string(":type"),
                  Core.t_plus
                )
              ),
              Repl.f_repl_empty_from_textblock_argmap(
                Core.f_new(
                  Textblock.t_textblock,
                  Core.vx_new(Core.t_anylist,
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
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl :val 2)\n (repl-empty<-textblock-argmap\n  (tb/textblock\n   :text \"1\"\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"2\")))\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
                  Core.vx_new_string(":val"),
                  Core.vx_new_int(2)
                )
              ),
              Repl.f_repl_empty_from_textblock_argmap(
                Core.f_new(
                  Textblock.t_textblock,
                  Core.vx_new(Core.t_anylist,
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("1"),
                    Core.vx_new_string(":children"),
                    Core.f_new(
                      Textblock.t_textblocklist,
                      Core.vx_new(Core.t_anylist,
                        Core.f_new(
                          Textblock.t_textblock,
                          Core.vx_new(Core.t_anylist,
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
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl\n  (msg<-error \"Empty delim cannot have more than one child.\"))\n (repl-empty<-textblock-argmap\n  (tb/textblock\n   :text \"1\"\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"2\")\n     (tb/textblock\n      :text \"3\")))\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
                  Core.f_msg_from_error(Core.vx_new_string("Empty delim cannot have more than one child."))
                )
              ),
              Repl.f_repl_empty_from_textblock_argmap(
                Core.f_new(
                  Textblock.t_textblock,
                  Core.vx_new(Core.t_anylist,
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("1"),
                    Core.vx_new_string(":children"),
                    Core.f_new(
                      Textblock.t_textblocklist,
                      Core.vx_new(Core.t_anylist,
                        Core.f_new(
                          Textblock.t_textblock,
                          Core.vx_new(Core.t_anylist,
                            Core.vx_new_string(":text"),
                            Core.vx_new_string("2")
                          )
                        ),
                        Core.f_new(
                          Textblock.t_textblock,
                          Core.vx_new(Core.t_anylist,
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
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl-paren<-textblock-argmap",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl\n  :type vx/core/+\n  :repllist\n   (repllist\n    (repl\n     :val 2)\n    (repl\n     :val 3)))\n (repl-paren<-textblock-argmap\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :delim\n    (copy delimvxlispparen\n     :delimlist\n      (empty delimlist))\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"+\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"2\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"3\")))\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
                  Core.vx_new_string(":type"),
                  Core.t_plus,
                  Core.vx_new_string(":repllist"),
                  Core.f_new(
                    Repl.t_repllist,
                    Core.vx_new(Core.t_anylist,
                      Core.f_new(
                        Repl.t_repl,
                        Core.vx_new(Core.t_anylist,
                          Core.vx_new_string(":val"),
                          Core.vx_new_int(2)
                        )
                      ),
                      Core.f_new(
                        Repl.t_repl,
                        Core.vx_new(Core.t_anylist,
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
                  Core.vx_new(Core.t_anylist,
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("(+ 2 3)"),
                    Core.vx_new_string(":delim"),
                    Core.f_copy(
                      Repl.c_delimvxlispparen,
                      Core.vx_new(Core.t_anylist,
                        Core.vx_new_string(":delimlist"),
                        Core.f_empty(
                          Textblock.t_delimlist
                        )
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
                            Core.vx_new_string("+")
                          )
                        ),
                        Core.f_new(
                          Textblock.t_textblock,
                          Core.vx_new(Core.t_anylist,
                            Core.vx_new_string(":text"),
                            Core.vx_new_string(" "),
                            Core.vx_new_string(":delim"),
                            Core.f_copy(
                              Textblock.c_delimwhitespace,
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
                            Core.vx_new_string("2")
                          )
                        ),
                        Core.f_new(
                          Textblock.t_textblock,
                          Core.vx_new(Core.t_anylist,
                            Core.vx_new_string(":text"),
                            Core.vx_new_string(" "),
                            Core.vx_new_string(":delim"),
                            Core.f_copy(
                              Textblock.c_delimwhitespace,
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

  static Test.Type_testcase f_repl_from_macro(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl<-macro",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl\n  :type vx/core/+\n  :repllist\n   (repllist\n    (repl\n     :val 2)\n    (repl\n     :val 3)))\n (repl<-macro\n  \"(+ \"\n  (- 7 5)\n  \" 3)\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
                  Core.vx_new_string(":type"),
                  Core.t_plus,
                  Core.vx_new_string(":repllist"),
                  Core.f_new(
                    Repl.t_repllist,
                    Core.vx_new(Core.t_anylist,
                      Core.f_new(
                        Repl.t_repl,
                        Core.vx_new(Core.t_anylist,
                          Core.vx_new_string(":val"),
                          Core.vx_new_int(2)
                        )
                      ),
                      Core.f_new(
                        Repl.t_repl,
                        Core.vx_new(Core.t_anylist,
                          Core.vx_new_string(":val"),
                          Core.vx_new_int(3)
                        )
                      )
                    )
                  )
                )
              ),
              Repl.f_repl_from_macro(
                context,
                Core.vx_new(Core.t_anylist,
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

  static Test.Type_testcase f_repl_from_script(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl<-script",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl\n  :val 2)\n (repl<-script\n  \"2\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
                  Core.vx_new_string(":val"),
                  Core.vx_new_int(2)
                )
              ),
              Repl.f_repl_from_script(Core.vx_new_string("2"))
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl\n  :val infinity)\n (repl<-script\n  \"infinity\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
                  Core.vx_new_string(":val"),
                  Core.c_infinity
                )
              ),
              Repl.f_repl_from_script(Core.vx_new_string("infinity"))
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl\n  :type +)\n (repl<-script\n  \"+\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
                  Core.vx_new_string(":type"),
                  Core.t_plus
                )
              ),
              Repl.f_repl_from_script(Core.vx_new_string("+"))
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl\n     :val 2)\n    (repl\n     :val 3)))\n (repl<-script\n  \"(+ 2 3)\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
                  Core.vx_new_string(":type"),
                  Core.t_plus,
                  Core.vx_new_string(":repllist"),
                  Core.f_new(
                    Repl.t_repllist,
                    Core.vx_new(Core.t_anylist,
                      Core.f_new(
                        Repl.t_repl,
                        Core.vx_new(Core.t_anylist,
                          Core.vx_new_string(":val"),
                          Core.vx_new_int(2)
                        )
                      ),
                      Core.f_new(
                        Repl.t_repl,
                        Core.vx_new(Core.t_anylist,
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
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl<-string-argmap",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl :val \"Hello\")\n (repl<-string-argmap\n  `\"Hello\"`\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
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
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl\n  :val 2)\n (repl<-string-argmap\n  \"2\"\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
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
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl :val 2.3)\n (repl<-string-argmap\n  \"2.3\"\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
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
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl\n  :val infinity)\n (repl<-string-argmap\n  \"infinity\"\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
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
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl\n  :val tb/delimcomma)\n (repl<-string-argmap\n  \"vx/data/textblock/delimcomma\"\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
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
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl :type string)\n (repl<-string-argmap\n  \"string\"\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
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
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl :type +)\n (repl<-string-argmap\n  \"+\"\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
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
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl<-textblock",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl :val 2)\n (repl<-textblock\n  (tb/textblock\n   :text \"2\")))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
                  Core.vx_new_string(":val"),
                  Core.vx_new_int(2)
                )
              ),
              Repl.f_repl_from_textblock(
                Core.f_new(
                  Textblock.t_textblock,
                  Core.vx_new(Core.t_anylist,
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("2")
                  )
                )
              )
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl :type +)\n (repl<-textblock\n  (tb/textblock\n   :text \"+\")))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
                  Core.vx_new_string(":type"),
                  Core.t_plus
                )
              ),
              Repl.f_repl_from_textblock(
                Core.f_new(
                  Textblock.t_textblock,
                  Core.vx_new(Core.t_anylist,
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("+")
                  )
                )
              )
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl :type +)\n (repl<-textblock\n  (tb/textblock\n   :text \"+\")))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
                  Core.vx_new_string(":type"),
                  Core.t_plus
                )
              ),
              Repl.f_repl_from_textblock(
                Core.f_new(
                  Textblock.t_textblock,
                  Core.vx_new(Core.t_anylist,
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("+")
                  )
                )
              )
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl :val 2)\n    (repl :val 3)))\n (repl<-textblock\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :delim\n    (copy delimvxlispparen\n     :delimlist\n      (empty delimlist))\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"+\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"2\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"3\")))))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
                  Core.vx_new_string(":type"),
                  Core.t_plus,
                  Core.vx_new_string(":repllist"),
                  Core.f_new(
                    Repl.t_repllist,
                    Core.vx_new(Core.t_anylist,
                      Core.f_new(
                        Repl.t_repl,
                        Core.vx_new(Core.t_anylist,
                          Core.vx_new_string(":val"),
                          Core.vx_new_int(2)
                        )
                      ),
                      Core.f_new(
                        Repl.t_repl,
                        Core.vx_new(Core.t_anylist,
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
                  Core.vx_new(Core.t_anylist,
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("(+ 2 3)"),
                    Core.vx_new_string(":delim"),
                    Core.f_copy(
                      Repl.c_delimvxlispparen,
                      Core.vx_new(Core.t_anylist,
                        Core.vx_new_string(":delimlist"),
                        Core.f_empty(
                          Textblock.t_delimlist
                        )
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
                            Core.vx_new_string("+")
                          )
                        ),
                        Core.f_new(
                          Textblock.t_textblock,
                          Core.vx_new(Core.t_anylist,
                            Core.vx_new_string(":text"),
                            Core.vx_new_string(" "),
                            Core.vx_new_string(":delim"),
                            Core.f_copy(
                              Textblock.c_delimwhitespace,
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
                            Core.vx_new_string("2")
                          )
                        ),
                        Core.f_new(
                          Textblock.t_textblock,
                          Core.vx_new(Core.t_anylist,
                            Core.vx_new_string(":text"),
                            Core.vx_new_string(" "),
                            Core.vx_new_string(":delim"),
                            Core.f_copy(
                              Textblock.c_delimwhitespace,
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
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl :val 2)\n    (repl :val 3)))\n (repl<-textblock\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"(+ 2 3)\"\n      :delim\n       (copy delimvxlispparen\n        :delimlist\n         (empty delimlist))\n      :children\n       (tb/textblocklist\n        (tb/textblock\n         :text \"+\")\n        (tb/textblock\n         :text \" \"\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"2\")\n        (tb/textblock\n         :text \" \"\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"3\")))))))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
                  Core.vx_new_string(":type"),
                  Core.t_plus,
                  Core.vx_new_string(":repllist"),
                  Core.f_new(
                    Repl.t_repllist,
                    Core.vx_new(Core.t_anylist,
                      Core.f_new(
                        Repl.t_repl,
                        Core.vx_new(Core.t_anylist,
                          Core.vx_new_string(":val"),
                          Core.vx_new_int(2)
                        )
                      ),
                      Core.f_new(
                        Repl.t_repl,
                        Core.vx_new(Core.t_anylist,
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
                  Core.vx_new(Core.t_anylist,
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("(+ 2 3)"),
                    Core.vx_new_string(":children"),
                    Core.f_new(
                      Textblock.t_textblocklist,
                      Core.vx_new(Core.t_anylist,
                        Core.f_new(
                          Textblock.t_textblock,
                          Core.vx_new(Core.t_anylist,
                            Core.vx_new_string(":text"),
                            Core.vx_new_string("(+ 2 3)"),
                            Core.vx_new_string(":delim"),
                            Core.f_copy(
                              Repl.c_delimvxlispparen,
                              Core.vx_new(Core.t_anylist,
                                Core.vx_new_string(":delimlist"),
                                Core.f_empty(
                                  Textblock.t_delimlist
                                )
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
                                    Core.vx_new_string("+")
                                  )
                                ),
                                Core.f_new(
                                  Textblock.t_textblock,
                                  Core.vx_new(Core.t_anylist,
                                    Core.vx_new_string(":text"),
                                    Core.vx_new_string(" "),
                                    Core.vx_new_string(":delim"),
                                    Core.f_copy(
                                      Textblock.c_delimwhitespace,
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
                                    Core.vx_new_string("2")
                                  )
                                ),
                                Core.f_new(
                                  Textblock.t_textblock,
                                  Core.vx_new(Core.t_anylist,
                                    Core.vx_new_string(":text"),
                                    Core.vx_new_string(" "),
                                    Core.vx_new_string(":delim"),
                                    Core.f_copy(
                                      Textblock.c_delimwhitespace,
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
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl<-textblock-argmap",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl :val 2)\n (repl<-textblock-argmap\n  (tb/textblock\n   :text \"2\")\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
                  Core.vx_new_string(":val"),
                  Core.vx_new_int(2)
                )
              ),
              Repl.f_repl_from_textblock_argmap(
                Core.f_new(
                  Textblock.t_textblock,
                  Core.vx_new(Core.t_anylist,
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
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl :type +)\n (repl<-textblock-argmap\n  (tb/textblock\n   :text \"+\")\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
                  Core.vx_new_string(":type"),
                  Core.t_plus
                )
              ),
              Repl.f_repl_from_textblock_argmap(
                Core.f_new(
                  Textblock.t_textblock,
                  Core.vx_new(Core.t_anylist,
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
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl :val 2)\n    (repl :val 3)))\n (repl<-textblock-argmap\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :delim\n    (copy delimvxlispparen\n     :delimlist\n      (empty delimlist))\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"+\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"2\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"3\")))\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
                  Core.vx_new_string(":type"),
                  Core.t_plus,
                  Core.vx_new_string(":repllist"),
                  Core.f_new(
                    Repl.t_repllist,
                    Core.vx_new(Core.t_anylist,
                      Core.f_new(
                        Repl.t_repl,
                        Core.vx_new(Core.t_anylist,
                          Core.vx_new_string(":val"),
                          Core.vx_new_int(2)
                        )
                      ),
                      Core.f_new(
                        Repl.t_repl,
                        Core.vx_new(Core.t_anylist,
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
                  Core.vx_new(Core.t_anylist,
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("(+ 2 3)"),
                    Core.vx_new_string(":delim"),
                    Core.f_copy(
                      Repl.c_delimvxlispparen,
                      Core.vx_new(Core.t_anylist,
                        Core.vx_new_string(":delimlist"),
                        Core.f_empty(
                          Textblock.t_delimlist
                        )
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
                            Core.vx_new_string("+")
                          )
                        ),
                        Core.f_new(
                          Textblock.t_textblock,
                          Core.vx_new(Core.t_anylist,
                            Core.vx_new_string(":text"),
                            Core.vx_new_string(" "),
                            Core.vx_new_string(":delim"),
                            Core.f_copy(
                              Textblock.c_delimwhitespace,
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
                            Core.vx_new_string("2")
                          )
                        ),
                        Core.f_new(
                          Textblock.t_textblock,
                          Core.vx_new(Core.t_anylist,
                            Core.vx_new_string(":text"),
                            Core.vx_new_string(" "),
                            Core.vx_new_string(":delim"),
                            Core.f_copy(
                              Textblock.c_delimwhitespace,
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
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl :val 2)\n    (repl :val 3)))\n (repl<-textblock-argmap\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"(+ 2 3)\"\n      :delim\n       (copy delimvxlispparen\n        :delimlist\n         (empty delimlist))\n      :children\n       (tb/textblocklist\n        (tb/textblock\n         :text \"+\")\n        (tb/textblock\n         :text \" \"\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"2\")\n        (tb/textblock\n         :text \" \"\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"3\")))))\n  (empty argmap)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Repl.t_repl,
                Core.vx_new(Core.t_anylist,
                  Core.vx_new_string(":type"),
                  Core.t_plus,
                  Core.vx_new_string(":repllist"),
                  Core.f_new(
                    Repl.t_repllist,
                    Core.vx_new(Core.t_anylist,
                      Core.f_new(
                        Repl.t_repl,
                        Core.vx_new(Core.t_anylist,
                          Core.vx_new_string(":val"),
                          Core.vx_new_int(2)
                        )
                      ),
                      Core.f_new(
                        Repl.t_repl,
                        Core.vx_new(Core.t_anylist,
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
                  Core.vx_new(Core.t_anylist,
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("(+ 2 3)"),
                    Core.vx_new_string(":children"),
                    Core.f_new(
                      Textblock.t_textblocklist,
                      Core.vx_new(Core.t_anylist,
                        Core.f_new(
                          Textblock.t_textblock,
                          Core.vx_new(Core.t_anylist,
                            Core.vx_new_string(":text"),
                            Core.vx_new_string("(+ 2 3)"),
                            Core.vx_new_string(":delim"),
                            Core.f_copy(
                              Repl.c_delimvxlispparen,
                              Core.vx_new(Core.t_anylist,
                                Core.vx_new_string(":delimlist"),
                                Core.f_empty(
                                  Textblock.t_delimlist
                                )
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
                                    Core.vx_new_string("+")
                                  )
                                ),
                                Core.f_new(
                                  Textblock.t_textblock,
                                  Core.vx_new(Core.t_anylist,
                                    Core.vx_new_string(":text"),
                                    Core.vx_new_string(" "),
                                    Core.vx_new_string(":delim"),
                                    Core.f_copy(
                                      Textblock.c_delimwhitespace,
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
                                    Core.vx_new_string("2")
                                  )
                                ),
                                Core.f_new(
                                  Textblock.t_textblock,
                                  Core.vx_new(Core.t_anylist,
                                    Core.vx_new_string(":text"),
                                    Core.vx_new_string(" "),
                                    Core.vx_new_string(":delim"),
                                    Core.f_copy(
                                      Textblock.c_delimwhitespace,
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
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "textblock<-script",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (tb/textblock\n  :text \"infinity\"\n  :startpos 1\n  :endpos 8\n  :children\n   (tb/textblocklist\n    (tb/textblock\n    :text \"infinity\"\n    :startpos 1\n    :endpos 8\n    :delim\n     (delim\n      :name \"delimvxlisp\"))))\n (textblock<-script\n  \"infinity\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Textblock.t_textblock,
                Core.vx_new(Core.t_anylist,
                  Core.vx_new_string(":text"),
                  Core.vx_new_string("infinity"),
                  Core.vx_new_string(":startpos"),
                  Core.vx_new_int(1),
                  Core.vx_new_string(":endpos"),
                  Core.vx_new_int(8),
                  Core.vx_new_string(":children"),
                  Core.f_new(
                    Textblock.t_textblocklist,
                    Core.vx_new(Core.t_anylist,
                      Core.f_new(
                        Textblock.t_textblock,
                        Core.vx_new(Core.t_anylist,
                          Core.vx_new_string(":text"),
                          Core.vx_new_string("infinity"),
                          Core.vx_new_string(":startpos"),
                          Core.vx_new_int(1),
                          Core.vx_new_string(":endpos"),
                          Core.vx_new_int(8),
                          Core.vx_new_string(":delim"),
                          Core.f_new(
                            Textblock.t_delim,
                            Core.vx_new(Core.t_anylist,
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
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (tb/textblock\n  :text \"(+ 2 3)\"\n  :startpos 1\n  :endpos 7\n  :children\n   (tb/textblocklist\n    (tb/textblock\n     :text \"(+ 2 3)\"\n     :startpos 1\n     :endpos 7\n     :delim\n      (copy delimvxlispparen\n       :delimlist\n        (empty delimlist))\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"+\"\n        :startpos 2\n        :endpos 2)\n       (tb/textblock\n        :text \" \"\n        :startpos 3\n        :endpos 3\n        :delim\n         (copy tb/delimwhitespace\n          :pos 0))\n       (tb/textblock\n        :text \"2\"\n        :startpos 4\n        :endpos 4)\n       (tb/textblock\n        :text \" \"\n        :startpos 5\n        :endpos 5\n        :delim\n         (copy tb/delimwhitespace\n          :pos 0))\n       (tb/textblock\n        :text \"3\"\n        :startpos 6\n        :endpos 6)))))\n (textblock<-script\n  \"(+ 2 3)\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Textblock.t_textblock,
                Core.vx_new(Core.t_anylist,
                  Core.vx_new_string(":text"),
                  Core.vx_new_string("(+ 2 3)"),
                  Core.vx_new_string(":startpos"),
                  Core.vx_new_int(1),
                  Core.vx_new_string(":endpos"),
                  Core.vx_new_int(7),
                  Core.vx_new_string(":children"),
                  Core.f_new(
                    Textblock.t_textblocklist,
                    Core.vx_new(Core.t_anylist,
                      Core.f_new(
                        Textblock.t_textblock,
                        Core.vx_new(Core.t_anylist,
                          Core.vx_new_string(":text"),
                          Core.vx_new_string("(+ 2 3)"),
                          Core.vx_new_string(":startpos"),
                          Core.vx_new_int(1),
                          Core.vx_new_string(":endpos"),
                          Core.vx_new_int(7),
                          Core.vx_new_string(":delim"),
                          Core.f_copy(
                            Repl.c_delimvxlispparen,
                            Core.vx_new(Core.t_anylist,
                              Core.vx_new_string(":delimlist"),
                              Core.f_empty(
                                Textblock.t_delimlist
                              )
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
                                  Core.vx_new_string("+"),
                                  Core.vx_new_string(":startpos"),
                                  Core.vx_new_int(2),
                                  Core.vx_new_string(":endpos"),
                                  Core.vx_new_int(2)
                                )
                              ),
                              Core.f_new(
                                Textblock.t_textblock,
                                Core.vx_new(Core.t_anylist,
                                  Core.vx_new_string(":text"),
                                  Core.vx_new_string(" "),
                                  Core.vx_new_string(":startpos"),
                                  Core.vx_new_int(3),
                                  Core.vx_new_string(":endpos"),
                                  Core.vx_new_int(3),
                                  Core.vx_new_string(":delim"),
                                  Core.f_copy(
                                    Textblock.c_delimwhitespace,
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
                                  Core.vx_new_string("2"),
                                  Core.vx_new_string(":startpos"),
                                  Core.vx_new_int(4),
                                  Core.vx_new_string(":endpos"),
                                  Core.vx_new_int(4)
                                )
                              ),
                              Core.f_new(
                                Textblock.t_textblock,
                                Core.vx_new(Core.t_anylist,
                                  Core.vx_new_string(":text"),
                                  Core.vx_new_string(" "),
                                  Core.vx_new_string(":startpos"),
                                  Core.vx_new_int(5),
                                  Core.vx_new_string(":endpos"),
                                  Core.vx_new_int(5),
                                  Core.vx_new_string(":delim"),
                                  Core.f_copy(
                                    Textblock.c_delimwhitespace,
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
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "typefunc<-string",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n string\n (typefunc<-string\n  \"string\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.t_string,
              Repl.f_typefunc_from_string(Core.vx_new_string("string"))
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
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
    List<Core.Type_any> arraylisttestcase = Core.arraylist_from_array(
      ReplTest.f_any_from_macro(context),
      ReplTest.f_any_from_repl(context),
      ReplTest.f_any_from_script(context),
      ReplTest.f_const_from_string(context),
      ReplTest.f_repl_empty_from_textblock_argmap(context),
      ReplTest.f_repl_paren_from_textblock_argmap(context),
      ReplTest.f_repl_from_macro(context),
      ReplTest.f_repl_from_script(context),
      ReplTest.f_repl_from_string_argmap(context),
      ReplTest.f_repl_from_textblock(context),
      ReplTest.f_repl_from_textblock_argmap(context),
      ReplTest.f_textblock_from_script(context),
      ReplTest.f_typefunc_from_string(context)
    );
    Test.Type_testcaselist output = Core.vx_new(
      Test.t_testcaselist,
      arraylisttestcase
    );
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    return Core.vx_new(
      Test.t_testcoveragesummary,
      ":testpkg", "vx/repl", 
      ":constnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 3), 
      ":docnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 28, ":total", 28), 
      ":funcnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 61, ":tests", 13, ":total", 21), 
      ":bigospacenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 21), 
      ":bigotimenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 21), 
      ":totalnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 46, ":tests", 13, ":total", 28), 
      ":typenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 4)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Core.vx_new(Test.t_testcoveragedetail, ":testpkg", "vx/repl", ":typemap", Core.vx_new(
  Core.t_intmap,
        ":liblist", 0,
        ":repl", 0,
        ":replarglist", 0,
        ":repllist", 0
), ":constmap", Core.vx_new(
  Core.t_intmap,
        ":delimvxlisp", 0,
        ":delimvxlispbracket", 0,
        ":delimvxlispparen", 0
), ":funcmap", Core.vx_new(
  Core.t_intmap,
        ":any-repl<-functype-args", 0,
        ":any<-liblist-string", 0,
        ":any<-macro", 1,
        ":any<-repl", 2,
        ":any<-script", 1,
        ":anylist<-repllist", 0,
        ":argmap<-textblock-argmap", 0,
        ":const<-string", 2,
        ":repl-bracket<-textblock-argmap", 0,
        ":repl-empty<-textblock-argmap", 4,
        ":repl-paren<-textblock-argmap", 1,
        ":repl<-liblist-string", 0,
        ":repl<-macro", 1,
        ":repl<-script", 4,
        ":repl<-string-argmap", 7,
        ":repl<-textblock", 5,
        ":repl<-textblock-argmap", 4,
        ":replarglist<-replarglist-textblock-argmap", 0,
        ":repllist<-textblocklist-argmap", 0,
        ":textblock<-script", 2,
        ":typefunc<-string", 2
      ));
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Core.vx_new(
      Test.t_testpackage,
      ":testpkg", "vx/repl", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
