
namespace AppTest.TestVx;

public class ReplTest {

  public static Vx.Test.Type_testcase f_any_from_macro(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "any<-macro",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        f_any_from_macro_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_any_from_macro_testdescribe_1(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n 5\n (any<-macro : int\n  \"(+ \"\n  (- 7 5)\n  \" 3)\"))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.vx_new_int(5),
        Vx.Repl.f_any_from_macro(
          Vx.Core.t_int,
          context,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string("(+ "),
            Vx.Core.f_minus(
              Vx.Core.vx_new_int(7),
              Vx.Core.vx_new_int(5)
            ),
            Vx.Core.vx_new_string(" 3)")
          )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_any_from_repl(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "any<-repl",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        f_any_from_repl_testdescribe_1(context),
        f_any_from_repl_testdescribe_2(context)
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_any_from_repl_testdescribe_1(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n \"HelloWorld\"\n (any<-repl\n  (repl\n   :type string\n   :repllist\n    (repllist\n     (repl :value \"Hello\")\n     (repl :value \"World\")\n    ))))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.vx_new_string("HelloWorld"),
        Vx.Repl.f_any_from_repl(
          context,
          Vx.Core.f_new(
            Vx.Repl.t_repl,
            Vx.Core.vx_new(
              Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":type"),
              Vx.Core.t_string,
              Vx.Core.vx_new_string(":repllist"),
              Vx.Core.f_new(
                Vx.Repl.t_repllist,
                Vx.Core.vx_new(
                  Vx.Core.t_anylist,
                  Vx.Core.f_new(
                    Vx.Repl.t_repl,
                    Vx.Core.vx_new(
                      Vx.Core.t_anylist,
                      Vx.Core.vx_new_string(":value"),
                      Vx.Core.vx_new_string("Hello")
                    )
                  ),
                  Vx.Core.f_new(
                    Vx.Repl.t_repl,
                    Vx.Core.vx_new(
                      Vx.Core.t_anylist,
                      Vx.Core.vx_new_string(":value"),
                      Vx.Core.vx_new_string("World")
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

  public static Vx.Test.Type_testdescribe f_any_from_repl_testdescribe_2(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n 5\n (any<-repl\n  (repl\n   :type +\n   :repllist\n    (repllist\n     (repl :value 2)\n     (repl :value 3)))))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.vx_new_int(5),
        Vx.Repl.f_any_from_repl(
          context,
          Vx.Core.f_new(
            Vx.Repl.t_repl,
            Vx.Core.vx_new(
              Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":type"),
              Vx.Core.t_plus,
              Vx.Core.vx_new_string(":repllist"),
              Vx.Core.f_new(
                Vx.Repl.t_repllist,
                Vx.Core.vx_new(
                  Vx.Core.t_anylist,
                  Vx.Core.f_new(
                    Vx.Repl.t_repl,
                    Vx.Core.vx_new(
                      Vx.Core.t_anylist,
                      Vx.Core.vx_new_string(":value"),
                      Vx.Core.vx_new_int(2)
                    )
                  ),
                  Vx.Core.f_new(
                    Vx.Repl.t_repl,
                    Vx.Core.vx_new(
                      Vx.Core.t_anylist,
                      Vx.Core.vx_new_string(":value"),
                      Vx.Core.vx_new_int(3)
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

  public static Vx.Test.Type_testcase f_any_from_script(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "any<-script",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        f_any_from_script_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_any_from_script_testdescribe_1(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n 5\n (any<-script\n  \"(+ 2 3)\"))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.vx_new_int(5),
        Vx.Repl.f_any_from_script(
          context,
          Vx.Core.vx_new_string("(+ 2 3)")
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_const_from_string(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "const<-string",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        f_const_from_string_testdescribe_1(context),
        f_const_from_string_testdescribe_2(context)
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_const_from_string_testdescribe_1(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n infinity\n (const<-string\n  \"infinity\"))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.c_infinity,
        Vx.Repl.f_const_from_string(
          Vx.Core.vx_new_string("infinity")
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_const_from_string_testdescribe_2(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n tb/delimcomma\n (const<-string\n  \"vx/data/textblock/delimcomma\"))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Data.Textblock.c_delimcomma,
        Vx.Repl.f_const_from_string(
          Vx.Core.vx_new_string("vx/data/textblock/delimcomma")
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_repl_empty_from_textblock_argmap(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl-empty<-textblock-argmap",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        f_repl_empty_from_textblock_argmap_testdescribe_1(context),
        f_repl_empty_from_textblock_argmap_testdescribe_2(context),
        f_repl_empty_from_textblock_argmap_testdescribe_3(context),
        f_repl_empty_from_textblock_argmap_testdescribe_4(context)
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_repl_empty_from_textblock_argmap_testdescribe_1(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl :value 2)\n (repl-empty<-textblock-argmap\n  (tb/textblock\n   :text \"2\")\n  (empty argmap)))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":value"),
            Vx.Core.vx_new_int(2)
          )
        ),
        Vx.Repl.f_repl_empty_from_textblock_argmap(
          Vx.Core.f_new(
            Vx.Data.Textblock.t_textblock,
            Vx.Core.vx_new(
              Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":text"),
              Vx.Core.vx_new_string("2")
            )
          ),
          Vx.Core.f_empty(
            Vx.Core.t_argmap
          )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_repl_empty_from_textblock_argmap_testdescribe_2(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl :type +)\n (repl-empty<-textblock-argmap\n  (tb/textblock\n   :text \"+\")\n  (empty argmap)))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":type"),
            Vx.Core.t_plus
          )
        ),
        Vx.Repl.f_repl_empty_from_textblock_argmap(
          Vx.Core.f_new(
            Vx.Data.Textblock.t_textblock,
            Vx.Core.vx_new(
              Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":text"),
              Vx.Core.vx_new_string("+")
            )
          ),
          Vx.Core.f_empty(
            Vx.Core.t_argmap
          )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_repl_empty_from_textblock_argmap_testdescribe_3(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl :value 2)\n (repl-empty<-textblock-argmap\n  (tb/textblock\n   :text \"1\"\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"2\")))\n  (empty argmap)))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":value"),
            Vx.Core.vx_new_int(2)
          )
        ),
        Vx.Repl.f_repl_empty_from_textblock_argmap(
          Vx.Core.f_new(
            Vx.Data.Textblock.t_textblock,
            Vx.Core.vx_new(
              Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":text"),
              Vx.Core.vx_new_string("1"),
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
                      Vx.Core.vx_new_string("2")
                    )
                  )
                )
              )
            )
          ),
          Vx.Core.f_empty(
            Vx.Core.t_argmap
          )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_repl_empty_from_textblock_argmap_testdescribe_4(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl\n  (msg<-error \"Empty delim cannot have more than one child.\"))\n (repl-empty<-textblock-argmap\n  (tb/textblock\n   :text \"1\"\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"2\")\n     (tb/textblock\n      :text \"3\")))\n  (empty argmap)))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.f_msg_from_error(
              Vx.Core.vx_new_string("Empty delim cannot have more than one child.")
            )
          )
        ),
        Vx.Repl.f_repl_empty_from_textblock_argmap(
          Vx.Core.f_new(
            Vx.Data.Textblock.t_textblock,
            Vx.Core.vx_new(
              Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":text"),
              Vx.Core.vx_new_string("1"),
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
                      Vx.Core.vx_new_string("2")
                    )
                  ),
                  Vx.Core.f_new(
                    Vx.Data.Textblock.t_textblock,
                    Vx.Core.vx_new(
                      Vx.Core.t_anylist,
                      Vx.Core.vx_new_string(":text"),
                      Vx.Core.vx_new_string("3")
                    )
                  )
                )
              )
            )
          ),
          Vx.Core.f_empty(
            Vx.Core.t_argmap
          )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_repl_paren_from_textblock_argmap(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl-paren<-textblock-argmap",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        f_repl_paren_from_textblock_argmap_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_repl_paren_from_textblock_argmap_testdescribe_1(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl\n  :type vx/core/+\n  :repllist\n   (repllist\n    (repl\n     :value 2)\n    (repl\n     :value 3)))\n (repl-paren<-textblock-argmap\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :delim\n    (copy delimvxlispparen\n     :delimlist\n      (empty delimlist))\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"+\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"2\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"3\")))\n  (empty argmap)))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":type"),
            Vx.Core.t_plus,
            Vx.Core.vx_new_string(":repllist"),
            Vx.Core.f_new(
              Vx.Repl.t_repllist,
              Vx.Core.vx_new(
                Vx.Core.t_anylist,
                Vx.Core.f_new(
                  Vx.Repl.t_repl,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":value"),
                    Vx.Core.vx_new_int(2)
                  )
                ),
                Vx.Core.f_new(
                  Vx.Repl.t_repl,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":value"),
                    Vx.Core.vx_new_int(3)
                  )
                )
              )
            )
          )
        ),
        Vx.Repl.f_repl_paren_from_textblock_argmap(
          Vx.Core.f_new(
            Vx.Data.Textblock.t_textblock,
            Vx.Core.vx_new(
              Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":text"),
              Vx.Core.vx_new_string("(+ 2 3)"),
              Vx.Core.vx_new_string(":delim"),
              Vx.Core.f_copy(
                Vx.Repl.c_delimvxlispparen,
                Vx.Core.vx_new(
                  Vx.Core.t_anylist,
                  Vx.Core.vx_new_string(":delimlist"),
                  Vx.Core.f_empty(
                    Vx.Data.Textblock.t_delimlist
                  )
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
                      Vx.Core.vx_new_string("+")
                    )
                  ),
                  Vx.Core.f_new(
                    Vx.Data.Textblock.t_textblock,
                    Vx.Core.vx_new(
                      Vx.Core.t_anylist,
                      Vx.Core.vx_new_string(":text"),
                      Vx.Core.vx_new_string(" "),
                      Vx.Core.vx_new_string(":delim"),
                      Vx.Core.f_copy(
                        Vx.Data.Textblock.c_delimwhitespace,
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
                      Vx.Core.vx_new_string("2")
                    )
                  ),
                  Vx.Core.f_new(
                    Vx.Data.Textblock.t_textblock,
                    Vx.Core.vx_new(
                      Vx.Core.t_anylist,
                      Vx.Core.vx_new_string(":text"),
                      Vx.Core.vx_new_string(" "),
                      Vx.Core.vx_new_string(":delim"),
                      Vx.Core.f_copy(
                        Vx.Data.Textblock.c_delimwhitespace,
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
                      Vx.Core.vx_new_string("3")
                    )
                  )
                )
              )
            )
          ),
          Vx.Core.f_empty(
            Vx.Core.t_argmap
          )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_repl_from_macro(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl<-macro",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        f_repl_from_macro_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_repl_from_macro_testdescribe_1(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl\n  :type vx/core/+\n  :repllist\n   (repllist\n    (repl\n     :value 2)\n    (repl\n     :value 3)))\n (repl<-macro\n  \"(+ \"\n  (- 7 5)\n  \" 3)\"))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":type"),
            Vx.Core.t_plus,
            Vx.Core.vx_new_string(":repllist"),
            Vx.Core.f_new(
              Vx.Repl.t_repllist,
              Vx.Core.vx_new(
                Vx.Core.t_anylist,
                Vx.Core.f_new(
                  Vx.Repl.t_repl,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":value"),
                    Vx.Core.vx_new_int(2)
                  )
                ),
                Vx.Core.f_new(
                  Vx.Repl.t_repl,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":value"),
                    Vx.Core.vx_new_int(3)
                  )
                )
              )
            )
          )
        ),
        Vx.Repl.f_repl_from_macro(
          context,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string("(+ "),
            Vx.Core.f_minus(
              Vx.Core.vx_new_int(7),
              Vx.Core.vx_new_int(5)
            ),
            Vx.Core.vx_new_string(" 3)")
          )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_repl_from_script(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl<-script",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        f_repl_from_script_testdescribe_1(context),
        f_repl_from_script_testdescribe_2(context),
        f_repl_from_script_testdescribe_3(context),
        f_repl_from_script_testdescribe_4(context)
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_repl_from_script_testdescribe_1(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl\n  :value 2)\n (repl<-script\n  \"2\"))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":value"),
            Vx.Core.vx_new_int(2)
          )
        ),
        Vx.Repl.f_repl_from_script(
          Vx.Core.vx_new_string("2")
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_repl_from_script_testdescribe_2(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl\n  :value infinity)\n (repl<-script\n  \"infinity\"))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":value"),
            Vx.Core.c_infinity
          )
        ),
        Vx.Repl.f_repl_from_script(
          Vx.Core.vx_new_string("infinity")
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_repl_from_script_testdescribe_3(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl\n  :type +)\n (repl<-script\n  \"+\"))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":type"),
            Vx.Core.t_plus
          )
        ),
        Vx.Repl.f_repl_from_script(
          Vx.Core.vx_new_string("+")
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_repl_from_script_testdescribe_4(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl\n     :value 2)\n    (repl\n     :value 3)))\n (repl<-script\n  \"(+ 2 3)\"))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":type"),
            Vx.Core.t_plus,
            Vx.Core.vx_new_string(":repllist"),
            Vx.Core.f_new(
              Vx.Repl.t_repllist,
              Vx.Core.vx_new(
                Vx.Core.t_anylist,
                Vx.Core.f_new(
                  Vx.Repl.t_repl,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":value"),
                    Vx.Core.vx_new_int(2)
                  )
                ),
                Vx.Core.f_new(
                  Vx.Repl.t_repl,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":value"),
                    Vx.Core.vx_new_int(3)
                  )
                )
              )
            )
          )
        ),
        Vx.Repl.f_repl_from_script(
          Vx.Core.vx_new_string("(+ 2 3)")
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_repl_from_string_argmap(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl<-string-argmap",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        f_repl_from_string_argmap_testdescribe_1(context),
        f_repl_from_string_argmap_testdescribe_2(context),
        f_repl_from_string_argmap_testdescribe_3(context),
        f_repl_from_string_argmap_testdescribe_4(context),
        f_repl_from_string_argmap_testdescribe_5(context),
        f_repl_from_string_argmap_testdescribe_6(context),
        f_repl_from_string_argmap_testdescribe_7(context)
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_repl_from_string_argmap_testdescribe_1(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl :value \"Hello\")\n (repl<-string-argmap\n  `\"Hello\"`\n  (empty argmap)))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":value"),
            Vx.Core.vx_new_string("Hello")
          )
        ),
        Vx.Repl.f_repl_from_string_argmap(
          Vx.Core.vx_new_string("\"Hello\""),
          Vx.Core.f_empty(
            Vx.Core.t_argmap
          )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_repl_from_string_argmap_testdescribe_2(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl\n  :value 2)\n (repl<-string-argmap\n  \"2\"\n  (empty argmap)))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":value"),
            Vx.Core.vx_new_int(2)
          )
        ),
        Vx.Repl.f_repl_from_string_argmap(
          Vx.Core.vx_new_string("2"),
          Vx.Core.f_empty(
            Vx.Core.t_argmap
          )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_repl_from_string_argmap_testdescribe_3(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl :value 2.3)\n (repl<-string-argmap\n  \"2.3\"\n  (empty argmap)))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":value"),
            Vx.Core.vx_new_decimal("2.3")
          )
        ),
        Vx.Repl.f_repl_from_string_argmap(
          Vx.Core.vx_new_string("2.3"),
          Vx.Core.f_empty(
            Vx.Core.t_argmap
          )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_repl_from_string_argmap_testdescribe_4(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl\n  :value infinity)\n (repl<-string-argmap\n  \"infinity\"\n  (empty argmap)))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":value"),
            Vx.Core.c_infinity
          )
        ),
        Vx.Repl.f_repl_from_string_argmap(
          Vx.Core.vx_new_string("infinity"),
          Vx.Core.f_empty(
            Vx.Core.t_argmap
          )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_repl_from_string_argmap_testdescribe_5(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl\n  :value tb/delimcomma)\n (repl<-string-argmap\n  \"vx/data/textblock/delimcomma\"\n  (empty argmap)))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":value"),
            Vx.Data.Textblock.c_delimcomma
          )
        ),
        Vx.Repl.f_repl_from_string_argmap(
          Vx.Core.vx_new_string("vx/data/textblock/delimcomma"),
          Vx.Core.f_empty(
            Vx.Core.t_argmap
          )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_repl_from_string_argmap_testdescribe_6(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl :type string)\n (repl<-string-argmap\n  \"string\"\n  (empty argmap)))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":type"),
            Vx.Core.t_string
          )
        ),
        Vx.Repl.f_repl_from_string_argmap(
          Vx.Core.vx_new_string("string"),
          Vx.Core.f_empty(
            Vx.Core.t_argmap
          )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_repl_from_string_argmap_testdescribe_7(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl :type +)\n (repl<-string-argmap\n  \"+\"\n  (empty argmap)))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":type"),
            Vx.Core.t_plus
          )
        ),
        Vx.Repl.f_repl_from_string_argmap(
          Vx.Core.vx_new_string("+"),
          Vx.Core.f_empty(
            Vx.Core.t_argmap
          )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_repl_from_textblock(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl<-textblock",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        f_repl_from_textblock_testdescribe_1(context),
        f_repl_from_textblock_testdescribe_2(context),
        f_repl_from_textblock_testdescribe_3(context),
        f_repl_from_textblock_testdescribe_4(context),
        f_repl_from_textblock_testdescribe_5(context)
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_repl_from_textblock_testdescribe_1(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl :value 2)\n (repl<-textblock\n  (tb/textblock\n   :text \"2\")))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":value"),
            Vx.Core.vx_new_int(2)
          )
        ),
        Vx.Repl.f_repl_from_textblock(
          Vx.Core.f_new(
            Vx.Data.Textblock.t_textblock,
            Vx.Core.vx_new(
              Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":text"),
              Vx.Core.vx_new_string("2")
            )
          )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_repl_from_textblock_testdescribe_2(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl :type +)\n (repl<-textblock\n  (tb/textblock\n   :text \"+\")))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":type"),
            Vx.Core.t_plus
          )
        ),
        Vx.Repl.f_repl_from_textblock(
          Vx.Core.f_new(
            Vx.Data.Textblock.t_textblock,
            Vx.Core.vx_new(
              Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":text"),
              Vx.Core.vx_new_string("+")
            )
          )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_repl_from_textblock_testdescribe_3(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl :type +)\n (repl<-textblock\n  (tb/textblock\n   :text \"+\")))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":type"),
            Vx.Core.t_plus
          )
        ),
        Vx.Repl.f_repl_from_textblock(
          Vx.Core.f_new(
            Vx.Data.Textblock.t_textblock,
            Vx.Core.vx_new(
              Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":text"),
              Vx.Core.vx_new_string("+")
            )
          )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_repl_from_textblock_testdescribe_4(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl :value 2)\n    (repl :value 3)))\n (repl<-textblock\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :delim\n    (copy delimvxlispparen\n     :delimlist\n      (empty delimlist))\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"+\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"2\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"3\")))))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":type"),
            Vx.Core.t_plus,
            Vx.Core.vx_new_string(":repllist"),
            Vx.Core.f_new(
              Vx.Repl.t_repllist,
              Vx.Core.vx_new(
                Vx.Core.t_anylist,
                Vx.Core.f_new(
                  Vx.Repl.t_repl,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":value"),
                    Vx.Core.vx_new_int(2)
                  )
                ),
                Vx.Core.f_new(
                  Vx.Repl.t_repl,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":value"),
                    Vx.Core.vx_new_int(3)
                  )
                )
              )
            )
          )
        ),
        Vx.Repl.f_repl_from_textblock(
          Vx.Core.f_new(
            Vx.Data.Textblock.t_textblock,
            Vx.Core.vx_new(
              Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":text"),
              Vx.Core.vx_new_string("(+ 2 3)"),
              Vx.Core.vx_new_string(":delim"),
              Vx.Core.f_copy(
                Vx.Repl.c_delimvxlispparen,
                Vx.Core.vx_new(
                  Vx.Core.t_anylist,
                  Vx.Core.vx_new_string(":delimlist"),
                  Vx.Core.f_empty(
                    Vx.Data.Textblock.t_delimlist
                  )
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
                      Vx.Core.vx_new_string("+")
                    )
                  ),
                  Vx.Core.f_new(
                    Vx.Data.Textblock.t_textblock,
                    Vx.Core.vx_new(
                      Vx.Core.t_anylist,
                      Vx.Core.vx_new_string(":text"),
                      Vx.Core.vx_new_string(" "),
                      Vx.Core.vx_new_string(":delim"),
                      Vx.Core.f_copy(
                        Vx.Data.Textblock.c_delimwhitespace,
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
                      Vx.Core.vx_new_string("2")
                    )
                  ),
                  Vx.Core.f_new(
                    Vx.Data.Textblock.t_textblock,
                    Vx.Core.vx_new(
                      Vx.Core.t_anylist,
                      Vx.Core.vx_new_string(":text"),
                      Vx.Core.vx_new_string(" "),
                      Vx.Core.vx_new_string(":delim"),
                      Vx.Core.f_copy(
                        Vx.Data.Textblock.c_delimwhitespace,
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
                      Vx.Core.vx_new_string("3")
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

  public static Vx.Test.Type_testdescribe f_repl_from_textblock_testdescribe_5(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl :value 2)\n    (repl :value 3)))\n (repl<-textblock\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"(+ 2 3)\"\n      :delim\n       (copy delimvxlispparen\n        :delimlist\n         (empty delimlist))\n      :children\n       (tb/textblocklist\n        (tb/textblock\n         :text \"+\")\n        (tb/textblock\n         :text \" \"\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"2\")\n        (tb/textblock\n         :text \" \"\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"3\")))))))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":type"),
            Vx.Core.t_plus,
            Vx.Core.vx_new_string(":repllist"),
            Vx.Core.f_new(
              Vx.Repl.t_repllist,
              Vx.Core.vx_new(
                Vx.Core.t_anylist,
                Vx.Core.f_new(
                  Vx.Repl.t_repl,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":value"),
                    Vx.Core.vx_new_int(2)
                  )
                ),
                Vx.Core.f_new(
                  Vx.Repl.t_repl,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":value"),
                    Vx.Core.vx_new_int(3)
                  )
                )
              )
            )
          )
        ),
        Vx.Repl.f_repl_from_textblock(
          Vx.Core.f_new(
            Vx.Data.Textblock.t_textblock,
            Vx.Core.vx_new(
              Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":text"),
              Vx.Core.vx_new_string("(+ 2 3)"),
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
                      Vx.Core.vx_new_string("(+ 2 3)"),
                      Vx.Core.vx_new_string(":delim"),
                      Vx.Core.f_copy(
                        Vx.Repl.c_delimvxlispparen,
                        Vx.Core.vx_new(
                          Vx.Core.t_anylist,
                          Vx.Core.vx_new_string(":delimlist"),
                          Vx.Core.f_empty(
                            Vx.Data.Textblock.t_delimlist
                          )
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
                              Vx.Core.vx_new_string("+")
                            )
                          ),
                          Vx.Core.f_new(
                            Vx.Data.Textblock.t_textblock,
                            Vx.Core.vx_new(
                              Vx.Core.t_anylist,
                              Vx.Core.vx_new_string(":text"),
                              Vx.Core.vx_new_string(" "),
                              Vx.Core.vx_new_string(":delim"),
                              Vx.Core.f_copy(
                                Vx.Data.Textblock.c_delimwhitespace,
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
                              Vx.Core.vx_new_string("2")
                            )
                          ),
                          Vx.Core.f_new(
                            Vx.Data.Textblock.t_textblock,
                            Vx.Core.vx_new(
                              Vx.Core.t_anylist,
                              Vx.Core.vx_new_string(":text"),
                              Vx.Core.vx_new_string(" "),
                              Vx.Core.vx_new_string(":delim"),
                              Vx.Core.f_copy(
                                Vx.Data.Textblock.c_delimwhitespace,
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
                              Vx.Core.vx_new_string("3")
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

  public static Vx.Test.Type_testcase f_repl_from_textblock_argmap(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl<-textblock-argmap",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        f_repl_from_textblock_argmap_testdescribe_1(context),
        f_repl_from_textblock_argmap_testdescribe_2(context),
        f_repl_from_textblock_argmap_testdescribe_3(context),
        f_repl_from_textblock_argmap_testdescribe_4(context)
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_repl_from_textblock_argmap_testdescribe_1(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl :value 2)\n (repl<-textblock-argmap\n  (tb/textblock\n   :text \"2\")\n  (empty argmap)))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":value"),
            Vx.Core.vx_new_int(2)
          )
        ),
        Vx.Repl.f_repl_from_textblock_argmap(
          Vx.Core.f_new(
            Vx.Data.Textblock.t_textblock,
            Vx.Core.vx_new(
              Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":text"),
              Vx.Core.vx_new_string("2")
            )
          ),
          Vx.Core.f_empty(
            Vx.Core.t_argmap
          )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_repl_from_textblock_argmap_testdescribe_2(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl :type +)\n (repl<-textblock-argmap\n  (tb/textblock\n   :text \"+\")\n  (empty argmap)))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":type"),
            Vx.Core.t_plus
          )
        ),
        Vx.Repl.f_repl_from_textblock_argmap(
          Vx.Core.f_new(
            Vx.Data.Textblock.t_textblock,
            Vx.Core.vx_new(
              Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":text"),
              Vx.Core.vx_new_string("+")
            )
          ),
          Vx.Core.f_empty(
            Vx.Core.t_argmap
          )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_repl_from_textblock_argmap_testdescribe_3(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl :value 2)\n    (repl :value 3)))\n (repl<-textblock-argmap\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :delim\n    (copy delimvxlispparen\n     :delimlist\n      (empty delimlist))\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"+\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"2\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"3\")))\n  (empty argmap)))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":type"),
            Vx.Core.t_plus,
            Vx.Core.vx_new_string(":repllist"),
            Vx.Core.f_new(
              Vx.Repl.t_repllist,
              Vx.Core.vx_new(
                Vx.Core.t_anylist,
                Vx.Core.f_new(
                  Vx.Repl.t_repl,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":value"),
                    Vx.Core.vx_new_int(2)
                  )
                ),
                Vx.Core.f_new(
                  Vx.Repl.t_repl,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":value"),
                    Vx.Core.vx_new_int(3)
                  )
                )
              )
            )
          )
        ),
        Vx.Repl.f_repl_from_textblock_argmap(
          Vx.Core.f_new(
            Vx.Data.Textblock.t_textblock,
            Vx.Core.vx_new(
              Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":text"),
              Vx.Core.vx_new_string("(+ 2 3)"),
              Vx.Core.vx_new_string(":delim"),
              Vx.Core.f_copy(
                Vx.Repl.c_delimvxlispparen,
                Vx.Core.vx_new(
                  Vx.Core.t_anylist,
                  Vx.Core.vx_new_string(":delimlist"),
                  Vx.Core.f_empty(
                    Vx.Data.Textblock.t_delimlist
                  )
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
                      Vx.Core.vx_new_string("+")
                    )
                  ),
                  Vx.Core.f_new(
                    Vx.Data.Textblock.t_textblock,
                    Vx.Core.vx_new(
                      Vx.Core.t_anylist,
                      Vx.Core.vx_new_string(":text"),
                      Vx.Core.vx_new_string(" "),
                      Vx.Core.vx_new_string(":delim"),
                      Vx.Core.f_copy(
                        Vx.Data.Textblock.c_delimwhitespace,
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
                      Vx.Core.vx_new_string("2")
                    )
                  ),
                  Vx.Core.f_new(
                    Vx.Data.Textblock.t_textblock,
                    Vx.Core.vx_new(
                      Vx.Core.t_anylist,
                      Vx.Core.vx_new_string(":text"),
                      Vx.Core.vx_new_string(" "),
                      Vx.Core.vx_new_string(":delim"),
                      Vx.Core.f_copy(
                        Vx.Data.Textblock.c_delimwhitespace,
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
                      Vx.Core.vx_new_string("3")
                    )
                  )
                )
              )
            )
          ),
          Vx.Core.f_empty(
            Vx.Core.t_argmap
          )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_repl_from_textblock_argmap_testdescribe_4(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl :value 2)\n    (repl :value 3)))\n (repl<-textblock-argmap\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"(+ 2 3)\"\n      :delim\n       (copy delimvxlispparen\n        :delimlist\n         (empty delimlist))\n      :children\n       (tb/textblocklist\n        (tb/textblock\n         :text \"+\")\n        (tb/textblock\n         :text \" \"\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"2\")\n        (tb/textblock\n         :text \" \"\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"3\")))))\n  (empty argmap)))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Repl.t_repl,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":type"),
            Vx.Core.t_plus,
            Vx.Core.vx_new_string(":repllist"),
            Vx.Core.f_new(
              Vx.Repl.t_repllist,
              Vx.Core.vx_new(
                Vx.Core.t_anylist,
                Vx.Core.f_new(
                  Vx.Repl.t_repl,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":value"),
                    Vx.Core.vx_new_int(2)
                  )
                ),
                Vx.Core.f_new(
                  Vx.Repl.t_repl,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":value"),
                    Vx.Core.vx_new_int(3)
                  )
                )
              )
            )
          )
        ),
        Vx.Repl.f_repl_from_textblock_argmap(
          Vx.Core.f_new(
            Vx.Data.Textblock.t_textblock,
            Vx.Core.vx_new(
              Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":text"),
              Vx.Core.vx_new_string("(+ 2 3)"),
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
                      Vx.Core.vx_new_string("(+ 2 3)"),
                      Vx.Core.vx_new_string(":delim"),
                      Vx.Core.f_copy(
                        Vx.Repl.c_delimvxlispparen,
                        Vx.Core.vx_new(
                          Vx.Core.t_anylist,
                          Vx.Core.vx_new_string(":delimlist"),
                          Vx.Core.f_empty(
                            Vx.Data.Textblock.t_delimlist
                          )
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
                              Vx.Core.vx_new_string("+")
                            )
                          ),
                          Vx.Core.f_new(
                            Vx.Data.Textblock.t_textblock,
                            Vx.Core.vx_new(
                              Vx.Core.t_anylist,
                              Vx.Core.vx_new_string(":text"),
                              Vx.Core.vx_new_string(" "),
                              Vx.Core.vx_new_string(":delim"),
                              Vx.Core.f_copy(
                                Vx.Data.Textblock.c_delimwhitespace,
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
                              Vx.Core.vx_new_string("2")
                            )
                          ),
                          Vx.Core.f_new(
                            Vx.Data.Textblock.t_textblock,
                            Vx.Core.vx_new(
                              Vx.Core.t_anylist,
                              Vx.Core.vx_new_string(":text"),
                              Vx.Core.vx_new_string(" "),
                              Vx.Core.vx_new_string(":delim"),
                              Vx.Core.f_copy(
                                Vx.Data.Textblock.c_delimwhitespace,
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
                              Vx.Core.vx_new_string("3")
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
          Vx.Core.f_empty(
            Vx.Core.t_argmap
          )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_textblock_from_script(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "textblock<-script",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        f_textblock_from_script_testdescribe_1(context),
        f_textblock_from_script_testdescribe_2(context)
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_textblock_from_script_testdescribe_1(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (tb/textblock\n  :text \"infinity\"\n  :startpos 1\n  :endpos 8\n  :children\n   (tb/textblocklist\n    (tb/textblock\n    :text \"infinity\"\n    :startpos 1\n    :endpos 8\n    :delim\n     (delim\n      :name \"delimvxlisp\"))))\n (textblock<-script\n  \"infinity\"))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Data.Textblock.t_textblock,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":text"),
            Vx.Core.vx_new_string("infinity"),
            Vx.Core.vx_new_string(":startpos"),
            Vx.Core.vx_new_int(1),
            Vx.Core.vx_new_string(":endpos"),
            Vx.Core.vx_new_int(8),
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
                    Vx.Core.vx_new_string("infinity"),
                    Vx.Core.vx_new_string(":startpos"),
                    Vx.Core.vx_new_int(1),
                    Vx.Core.vx_new_string(":endpos"),
                    Vx.Core.vx_new_int(8),
                    Vx.Core.vx_new_string(":delim"),
                    Vx.Core.f_new(
                      Vx.Data.Textblock.t_delim,
                      Vx.Core.vx_new(
                        Vx.Core.t_anylist,
                        Vx.Core.vx_new_string(":name"),
                        Vx.Core.vx_new_string("delimvxlisp")
                      )
                    )
                  )
                )
              )
            )
          )
        ),
        Vx.Repl.f_textblock_from_script(
          Vx.Core.vx_new_string("infinity")
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_textblock_from_script_testdescribe_2(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n (tb/textblock\n  :text \"(+ 2 3)\"\n  :startpos 1\n  :endpos 7\n  :children\n   (tb/textblocklist\n    (tb/textblock\n     :text \"(+ 2 3)\"\n     :startpos 1\n     :endpos 7\n     :delim\n      (copy delimvxlispparen\n       :delimlist\n        (empty delimlist))\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"+\"\n        :startpos 2\n        :endpos 2)\n       (tb/textblock\n        :text \" \"\n        :startpos 3\n        :endpos 3\n        :delim\n         (copy tb/delimwhitespace\n          :pos 0))\n       (tb/textblock\n        :text \"2\"\n        :startpos 4\n        :endpos 4)\n       (tb/textblock\n        :text \" \"\n        :startpos 5\n        :endpos 5\n        :delim\n         (copy tb/delimwhitespace\n          :pos 0))\n       (tb/textblock\n        :text \"3\"\n        :startpos 6\n        :endpos 6)))))\n (textblock<-script\n  \"(+ 2 3)\"))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.f_new(
          Vx.Data.Textblock.t_textblock,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":text"),
            Vx.Core.vx_new_string("(+ 2 3)"),
            Vx.Core.vx_new_string(":startpos"),
            Vx.Core.vx_new_int(1),
            Vx.Core.vx_new_string(":endpos"),
            Vx.Core.vx_new_int(7),
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
                    Vx.Core.vx_new_string("(+ 2 3)"),
                    Vx.Core.vx_new_string(":startpos"),
                    Vx.Core.vx_new_int(1),
                    Vx.Core.vx_new_string(":endpos"),
                    Vx.Core.vx_new_int(7),
                    Vx.Core.vx_new_string(":delim"),
                    Vx.Core.f_copy(
                      Vx.Repl.c_delimvxlispparen,
                      Vx.Core.vx_new(
                        Vx.Core.t_anylist,
                        Vx.Core.vx_new_string(":delimlist"),
                        Vx.Core.f_empty(
                          Vx.Data.Textblock.t_delimlist
                        )
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
                            Vx.Core.vx_new_string("+"),
                            Vx.Core.vx_new_string(":startpos"),
                            Vx.Core.vx_new_int(2),
                            Vx.Core.vx_new_string(":endpos"),
                            Vx.Core.vx_new_int(2)
                          )
                        ),
                        Vx.Core.f_new(
                          Vx.Data.Textblock.t_textblock,
                          Vx.Core.vx_new(
                            Vx.Core.t_anylist,
                            Vx.Core.vx_new_string(":text"),
                            Vx.Core.vx_new_string(" "),
                            Vx.Core.vx_new_string(":startpos"),
                            Vx.Core.vx_new_int(3),
                            Vx.Core.vx_new_string(":endpos"),
                            Vx.Core.vx_new_int(3),
                            Vx.Core.vx_new_string(":delim"),
                            Vx.Core.f_copy(
                              Vx.Data.Textblock.c_delimwhitespace,
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
                            Vx.Core.vx_new_string("2"),
                            Vx.Core.vx_new_string(":startpos"),
                            Vx.Core.vx_new_int(4),
                            Vx.Core.vx_new_string(":endpos"),
                            Vx.Core.vx_new_int(4)
                          )
                        ),
                        Vx.Core.f_new(
                          Vx.Data.Textblock.t_textblock,
                          Vx.Core.vx_new(
                            Vx.Core.t_anylist,
                            Vx.Core.vx_new_string(":text"),
                            Vx.Core.vx_new_string(" "),
                            Vx.Core.vx_new_string(":startpos"),
                            Vx.Core.vx_new_int(5),
                            Vx.Core.vx_new_string(":endpos"),
                            Vx.Core.vx_new_int(5),
                            Vx.Core.vx_new_string(":delim"),
                            Vx.Core.f_copy(
                              Vx.Data.Textblock.c_delimwhitespace,
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
                            Vx.Core.vx_new_string("3"),
                            Vx.Core.vx_new_string(":startpos"),
                            Vx.Core.vx_new_int(6),
                            Vx.Core.vx_new_string(":endpos"),
                            Vx.Core.vx_new_int(6)
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
        Vx.Repl.f_textblock_from_script(
          Vx.Core.vx_new_string("(+ 2 3)")
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_typefunc_from_string(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "typefunc<-string",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        f_typefunc_from_string_testdescribe_1(context),
        f_typefunc_from_string_testdescribe_2(context)
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_typefunc_from_string_testdescribe_1(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n string\n (typefunc<-string\n  \"string\"))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.t_string,
        Vx.Repl.f_typefunc_from_string(
          Vx.Core.vx_new_string("string")
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testdescribe f_typefunc_from_string_testdescribe_2(Vx.Core.Type_context context) {
    Vx.Test.Type_testdescribe output = Vx.Core.vx_new(
      Vx.Test.t_testdescribe,
      ":describename", "(test\n +\n (typefunc<-string\n  \"+\"))",
      ":testresult", Vx.Test.f_test(
        context,
        Vx.Core.t_plus,
        Vx.Repl.f_typefunc_from_string(
          Vx.Core.vx_new_string("+")
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcaselist test_cases(Vx.Core.Type_context context) {
    object[] testcases = [
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
      ":testpkg", "vx/repl", 
      ":constnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 3), 
      ":docnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 100, ":tests", 28, ":total", 28), 
      ":funcnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 61, ":tests", 13, ":total", 21), 
      ":bigospacenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 21), 
      ":bigotimenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 21), 
      ":totalnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 46, ":tests", 13, ":total", 28), 
      ":typenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 4)
    );
    return output;
  }

  public static Vx.Test.Type_testcoveragedetail test_coveragedetail() {
    Vx.Test.Type_testcoveragedetail output = Vx.Core.vx_new(
      Vx.Test.t_testcoveragedetail,
      ":testpkg", "vx/repl",
      ":typemap", Vx.Core.vx_new(
        Vx.Core.t_intmap,
        ":liblist", 0,
        ":repl", 0,
        ":replarglist", 0,
        ":repllist", 0
      ), 
      ":constmap", Vx.Core.vx_new(
        Vx.Core.t_intmap,
        ":delimvxlisp", 0,
        ":delimvxlispbracket", 0,
        ":delimvxlispparen", 0
      ), 
      ":funcmap", Vx.Core.vx_new(
        Vx.Core.t_intmap,
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
      )
    );
    return output;
  }

  public static Vx.Test.Type_testpackage test_package(Vx.Core.Type_context context) {
    Vx.Test.Type_testcaselist testcaselist = test_cases(context);
    Vx.Test.Type_testpackage output = Vx.Core.vx_new(
      Vx.Test.t_testpackage,
      ":testpkg", "vx/repl", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
