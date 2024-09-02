
package com.vxlisp.vx

import com.vxlisp.vx.data.*

object vx_replTest {

  fun f_any_from_macro(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "any<-macro",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_any_from_macro_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_any_from_macro_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n 5\n (any<-macro : int\n  \"(+ \"\n  (- 7 5)\n  \" 3)\"))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.vx_new_int(5),
        vx_repl.f_any_from_macro(
          vx_core.t_int,
          context,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string("(+ "),
            vx_core.f_minus(
              vx_core.vx_new_int(7),
              vx_core.vx_new_int(5)
            ),
            vx_core.vx_new_string(" 3)")
          )
        )
      )
    )
    return output
  }

  fun f_any_from_repl(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "any<-repl",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_any_from_repl_testdescribe_1(context),
        f_any_from_repl_testdescribe_2(context)
      )
    )
    return output
  }

  fun f_any_from_repl_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n \"HelloWorld\"\n (any<-repl\n  (repl\n   :type string\n   :repllist\n    (repllist\n     (repl :value \"Hello\")\n     (repl :value \"World\")\n    ))))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.vx_new_string("HelloWorld"),
        vx_repl.f_any_from_repl(
          context,
          vx_core.f_new(
            vx_repl.t_repl,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":type"),
              vx_core.t_string,
              vx_core.vx_new_string(":repllist"),
              vx_core.f_new(
                vx_repl.t_repllist,
                vx_core.vx_new(
                  vx_core.t_anylist,
                  vx_core.f_new(
                    vx_repl.t_repl,
                    vx_core.vx_new(
                      vx_core.t_anylist,
                      vx_core.vx_new_string(":value"),
                      vx_core.vx_new_string("Hello")
                    )
                  ),
                  vx_core.f_new(
                    vx_repl.t_repl,
                    vx_core.vx_new(
                      vx_core.t_anylist,
                      vx_core.vx_new_string(":value"),
                      vx_core.vx_new_string("World")
                    )
                  )
                )
              )
            )
          )
        )
      )
    )
    return output
  }

  fun f_any_from_repl_testdescribe_2(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n 5\n (any<-repl\n  (repl\n   :type +\n   :repllist\n    (repllist\n     (repl :value 2)\n     (repl :value 3)))))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.vx_new_int(5),
        vx_repl.f_any_from_repl(
          context,
          vx_core.f_new(
            vx_repl.t_repl,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":type"),
              vx_core.t_plus,
              vx_core.vx_new_string(":repllist"),
              vx_core.f_new(
                vx_repl.t_repllist,
                vx_core.vx_new(
                  vx_core.t_anylist,
                  vx_core.f_new(
                    vx_repl.t_repl,
                    vx_core.vx_new(
                      vx_core.t_anylist,
                      vx_core.vx_new_string(":value"),
                      vx_core.vx_new_int(2)
                    )
                  ),
                  vx_core.f_new(
                    vx_repl.t_repl,
                    vx_core.vx_new(
                      vx_core.t_anylist,
                      vx_core.vx_new_string(":value"),
                      vx_core.vx_new_int(3)
                    )
                  )
                )
              )
            )
          )
        )
      )
    )
    return output
  }

  fun f_any_from_script(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "any<-script",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_any_from_script_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_any_from_script_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n 5\n (any<-script\n  \"(+ 2 3)\"))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.vx_new_int(5),
        vx_repl.f_any_from_script(
          context,
          vx_core.vx_new_string("(+ 2 3)")
        )
      )
    )
    return output
  }

  fun f_const_from_string(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "const<-string",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_const_from_string_testdescribe_1(context),
        f_const_from_string_testdescribe_2(context)
      )
    )
    return output
  }

  fun f_const_from_string_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n infinity\n (const<-string\n  \"infinity\"))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.c_infinity,
        vx_repl.f_const_from_string(
          vx_core.vx_new_string("infinity")
        )
      )
    )
    return output
  }

  fun f_const_from_string_testdescribe_2(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n tb/delimcomma\n (const<-string\n  \"vx/data/textblock/delimcomma\"))",
      ":testresult", vx_test.f_test(
        context,
        vx_data_textblock.c_delimcomma,
        vx_repl.f_const_from_string(
          vx_core.vx_new_string("vx/data/textblock/delimcomma")
        )
      )
    )
    return output
  }

  fun f_repl_empty_from_textblock_argmap(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl-empty<-textblock-argmap",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_repl_empty_from_textblock_argmap_testdescribe_1(context),
        f_repl_empty_from_textblock_argmap_testdescribe_2(context),
        f_repl_empty_from_textblock_argmap_testdescribe_3(context),
        f_repl_empty_from_textblock_argmap_testdescribe_4(context)
      )
    )
    return output
  }

  fun f_repl_empty_from_textblock_argmap_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl :value 2)\n (repl-empty<-textblock-argmap\n  (tb/textblock\n   :text \"2\")\n  (empty argmap)))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":value"),
            vx_core.vx_new_int(2)
          )
        ),
        vx_repl.f_repl_empty_from_textblock_argmap(
          vx_core.f_new(
            vx_data_textblock.t_textblock,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":text"),
              vx_core.vx_new_string("2")
            )
          ),
          vx_core.f_empty(
            vx_core.t_argmap
          )
        )
      )
    )
    return output
  }

  fun f_repl_empty_from_textblock_argmap_testdescribe_2(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl :type +)\n (repl-empty<-textblock-argmap\n  (tb/textblock\n   :text \"+\")\n  (empty argmap)))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":type"),
            vx_core.t_plus
          )
        ),
        vx_repl.f_repl_empty_from_textblock_argmap(
          vx_core.f_new(
            vx_data_textblock.t_textblock,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":text"),
              vx_core.vx_new_string("+")
            )
          ),
          vx_core.f_empty(
            vx_core.t_argmap
          )
        )
      )
    )
    return output
  }

  fun f_repl_empty_from_textblock_argmap_testdescribe_3(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl :value 2)\n (repl-empty<-textblock-argmap\n  (tb/textblock\n   :text \"1\"\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"2\")))\n  (empty argmap)))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":value"),
            vx_core.vx_new_int(2)
          )
        ),
        vx_repl.f_repl_empty_from_textblock_argmap(
          vx_core.f_new(
            vx_data_textblock.t_textblock,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":text"),
              vx_core.vx_new_string("1"),
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
                      vx_core.vx_new_string("2")
                    )
                  )
                )
              )
            )
          ),
          vx_core.f_empty(
            vx_core.t_argmap
          )
        )
      )
    )
    return output
  }

  fun f_repl_empty_from_textblock_argmap_testdescribe_4(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl\n  (msg<-error \"Empty delim cannot have more than one child.\"))\n (repl-empty<-textblock-argmap\n  (tb/textblock\n   :text \"1\"\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"2\")\n     (tb/textblock\n      :text \"3\")))\n  (empty argmap)))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.f_msg_from_error(
              vx_core.vx_new_string("Empty delim cannot have more than one child.")
            )
          )
        ),
        vx_repl.f_repl_empty_from_textblock_argmap(
          vx_core.f_new(
            vx_data_textblock.t_textblock,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":text"),
              vx_core.vx_new_string("1"),
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
                      vx_core.vx_new_string("2")
                    )
                  ),
                  vx_core.f_new(
                    vx_data_textblock.t_textblock,
                    vx_core.vx_new(
                      vx_core.t_anylist,
                      vx_core.vx_new_string(":text"),
                      vx_core.vx_new_string("3")
                    )
                  )
                )
              )
            )
          ),
          vx_core.f_empty(
            vx_core.t_argmap
          )
        )
      )
    )
    return output
  }

  fun f_repl_paren_from_textblock_argmap(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl-paren<-textblock-argmap",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_repl_paren_from_textblock_argmap_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_repl_paren_from_textblock_argmap_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl\n  :type vx/core/+\n  :repllist\n   (repllist\n    (repl\n     :value 2)\n    (repl\n     :value 3)))\n (repl-paren<-textblock-argmap\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :delim\n    (copy delimvxlispparen\n     :delimlist\n      (empty delimlist))\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"+\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"2\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"3\")))\n  (empty argmap)))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":type"),
            vx_core.t_plus,
            vx_core.vx_new_string(":repllist"),
            vx_core.f_new(
              vx_repl.t_repllist,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.f_new(
                  vx_repl.t_repl,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":value"),
                    vx_core.vx_new_int(2)
                  )
                ),
                vx_core.f_new(
                  vx_repl.t_repl,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":value"),
                    vx_core.vx_new_int(3)
                  )
                )
              )
            )
          )
        ),
        vx_repl.f_repl_paren_from_textblock_argmap(
          vx_core.f_new(
            vx_data_textblock.t_textblock,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":text"),
              vx_core.vx_new_string("(+ 2 3)"),
              vx_core.vx_new_string(":delim"),
              vx_core.f_copy(
                vx_repl.c_delimvxlispparen,
                vx_core.vx_new(
                  vx_core.t_anylist,
                  vx_core.vx_new_string(":delimlist"),
                  vx_core.f_empty(
                    vx_data_textblock.t_delimlist
                  )
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
                      vx_core.vx_new_string("+")
                    )
                  ),
                  vx_core.f_new(
                    vx_data_textblock.t_textblock,
                    vx_core.vx_new(
                      vx_core.t_anylist,
                      vx_core.vx_new_string(":text"),
                      vx_core.vx_new_string(" "),
                      vx_core.vx_new_string(":delim"),
                      vx_core.f_copy(
                        vx_data_textblock.c_delimwhitespace,
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
                      vx_core.vx_new_string("2")
                    )
                  ),
                  vx_core.f_new(
                    vx_data_textblock.t_textblock,
                    vx_core.vx_new(
                      vx_core.t_anylist,
                      vx_core.vx_new_string(":text"),
                      vx_core.vx_new_string(" "),
                      vx_core.vx_new_string(":delim"),
                      vx_core.f_copy(
                        vx_data_textblock.c_delimwhitespace,
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
                      vx_core.vx_new_string("3")
                    )
                  )
                )
              )
            )
          ),
          vx_core.f_empty(
            vx_core.t_argmap
          )
        )
      )
    )
    return output
  }

  fun f_repl_from_macro(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl<-macro",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_repl_from_macro_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_repl_from_macro_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl\n  :type vx/core/+\n  :repllist\n   (repllist\n    (repl\n     :value 2)\n    (repl\n     :value 3)))\n (repl<-macro\n  \"(+ \"\n  (- 7 5)\n  \" 3)\"))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":type"),
            vx_core.t_plus,
            vx_core.vx_new_string(":repllist"),
            vx_core.f_new(
              vx_repl.t_repllist,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.f_new(
                  vx_repl.t_repl,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":value"),
                    vx_core.vx_new_int(2)
                  )
                ),
                vx_core.f_new(
                  vx_repl.t_repl,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":value"),
                    vx_core.vx_new_int(3)
                  )
                )
              )
            )
          )
        ),
        vx_repl.f_repl_from_macro(
          context,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string("(+ "),
            vx_core.f_minus(
              vx_core.vx_new_int(7),
              vx_core.vx_new_int(5)
            ),
            vx_core.vx_new_string(" 3)")
          )
        )
      )
    )
    return output
  }

  fun f_repl_from_script(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl<-script",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_repl_from_script_testdescribe_1(context),
        f_repl_from_script_testdescribe_2(context),
        f_repl_from_script_testdescribe_3(context),
        f_repl_from_script_testdescribe_4(context)
      )
    )
    return output
  }

  fun f_repl_from_script_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl\n  :value 2)\n (repl<-script\n  \"2\"))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":value"),
            vx_core.vx_new_int(2)
          )
        ),
        vx_repl.f_repl_from_script(
          vx_core.vx_new_string("2")
        )
      )
    )
    return output
  }

  fun f_repl_from_script_testdescribe_2(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl\n  :value infinity)\n (repl<-script\n  \"infinity\"))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":value"),
            vx_core.c_infinity
          )
        ),
        vx_repl.f_repl_from_script(
          vx_core.vx_new_string("infinity")
        )
      )
    )
    return output
  }

  fun f_repl_from_script_testdescribe_3(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl\n  :type +)\n (repl<-script\n  \"+\"))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":type"),
            vx_core.t_plus
          )
        ),
        vx_repl.f_repl_from_script(
          vx_core.vx_new_string("+")
        )
      )
    )
    return output
  }

  fun f_repl_from_script_testdescribe_4(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl\n     :value 2)\n    (repl\n     :value 3)))\n (repl<-script\n  \"(+ 2 3)\"))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":type"),
            vx_core.t_plus,
            vx_core.vx_new_string(":repllist"),
            vx_core.f_new(
              vx_repl.t_repllist,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.f_new(
                  vx_repl.t_repl,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":value"),
                    vx_core.vx_new_int(2)
                  )
                ),
                vx_core.f_new(
                  vx_repl.t_repl,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":value"),
                    vx_core.vx_new_int(3)
                  )
                )
              )
            )
          )
        ),
        vx_repl.f_repl_from_script(
          vx_core.vx_new_string("(+ 2 3)")
        )
      )
    )
    return output
  }

  fun f_repl_from_string_argmap(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl<-string-argmap",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_repl_from_string_argmap_testdescribe_1(context),
        f_repl_from_string_argmap_testdescribe_2(context),
        f_repl_from_string_argmap_testdescribe_3(context),
        f_repl_from_string_argmap_testdescribe_4(context),
        f_repl_from_string_argmap_testdescribe_5(context),
        f_repl_from_string_argmap_testdescribe_6(context),
        f_repl_from_string_argmap_testdescribe_7(context)
      )
    )
    return output
  }

  fun f_repl_from_string_argmap_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl :value \"Hello\")\n (repl<-string-argmap\n  `\"Hello\"`\n  (empty argmap)))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":value"),
            vx_core.vx_new_string("Hello")
          )
        ),
        vx_repl.f_repl_from_string_argmap(
          vx_core.vx_new_string("\"Hello\""),
          vx_core.f_empty(
            vx_core.t_argmap
          )
        )
      )
    )
    return output
  }

  fun f_repl_from_string_argmap_testdescribe_2(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl\n  :value 2)\n (repl<-string-argmap\n  \"2\"\n  (empty argmap)))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":value"),
            vx_core.vx_new_int(2)
          )
        ),
        vx_repl.f_repl_from_string_argmap(
          vx_core.vx_new_string("2"),
          vx_core.f_empty(
            vx_core.t_argmap
          )
        )
      )
    )
    return output
  }

  fun f_repl_from_string_argmap_testdescribe_3(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl :value 2.3)\n (repl<-string-argmap\n  \"2.3\"\n  (empty argmap)))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":value"),
            vx_core.vx_new_decimal("2.3")
          )
        ),
        vx_repl.f_repl_from_string_argmap(
          vx_core.vx_new_string("2.3"),
          vx_core.f_empty(
            vx_core.t_argmap
          )
        )
      )
    )
    return output
  }

  fun f_repl_from_string_argmap_testdescribe_4(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl\n  :value infinity)\n (repl<-string-argmap\n  \"infinity\"\n  (empty argmap)))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":value"),
            vx_core.c_infinity
          )
        ),
        vx_repl.f_repl_from_string_argmap(
          vx_core.vx_new_string("infinity"),
          vx_core.f_empty(
            vx_core.t_argmap
          )
        )
      )
    )
    return output
  }

  fun f_repl_from_string_argmap_testdescribe_5(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl\n  :value tb/delimcomma)\n (repl<-string-argmap\n  \"vx/data/textblock/delimcomma\"\n  (empty argmap)))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":value"),
            vx_data_textblock.c_delimcomma
          )
        ),
        vx_repl.f_repl_from_string_argmap(
          vx_core.vx_new_string("vx/data/textblock/delimcomma"),
          vx_core.f_empty(
            vx_core.t_argmap
          )
        )
      )
    )
    return output
  }

  fun f_repl_from_string_argmap_testdescribe_6(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl :type string)\n (repl<-string-argmap\n  \"string\"\n  (empty argmap)))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":type"),
            vx_core.t_string
          )
        ),
        vx_repl.f_repl_from_string_argmap(
          vx_core.vx_new_string("string"),
          vx_core.f_empty(
            vx_core.t_argmap
          )
        )
      )
    )
    return output
  }

  fun f_repl_from_string_argmap_testdescribe_7(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl :type +)\n (repl<-string-argmap\n  \"+\"\n  (empty argmap)))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":type"),
            vx_core.t_plus
          )
        ),
        vx_repl.f_repl_from_string_argmap(
          vx_core.vx_new_string("+"),
          vx_core.f_empty(
            vx_core.t_argmap
          )
        )
      )
    )
    return output
  }

  fun f_repl_from_textblock(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl<-textblock",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_repl_from_textblock_testdescribe_1(context),
        f_repl_from_textblock_testdescribe_2(context),
        f_repl_from_textblock_testdescribe_3(context),
        f_repl_from_textblock_testdescribe_4(context),
        f_repl_from_textblock_testdescribe_5(context)
      )
    )
    return output
  }

  fun f_repl_from_textblock_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl :value 2)\n (repl<-textblock\n  (tb/textblock\n   :text \"2\")))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":value"),
            vx_core.vx_new_int(2)
          )
        ),
        vx_repl.f_repl_from_textblock(
          vx_core.f_new(
            vx_data_textblock.t_textblock,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":text"),
              vx_core.vx_new_string("2")
            )
          )
        )
      )
    )
    return output
  }

  fun f_repl_from_textblock_testdescribe_2(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl :type +)\n (repl<-textblock\n  (tb/textblock\n   :text \"+\")))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":type"),
            vx_core.t_plus
          )
        ),
        vx_repl.f_repl_from_textblock(
          vx_core.f_new(
            vx_data_textblock.t_textblock,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":text"),
              vx_core.vx_new_string("+")
            )
          )
        )
      )
    )
    return output
  }

  fun f_repl_from_textblock_testdescribe_3(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl :type +)\n (repl<-textblock\n  (tb/textblock\n   :text \"+\")))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":type"),
            vx_core.t_plus
          )
        ),
        vx_repl.f_repl_from_textblock(
          vx_core.f_new(
            vx_data_textblock.t_textblock,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":text"),
              vx_core.vx_new_string("+")
            )
          )
        )
      )
    )
    return output
  }

  fun f_repl_from_textblock_testdescribe_4(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl :value 2)\n    (repl :value 3)))\n (repl<-textblock\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :delim\n    (copy delimvxlispparen\n     :delimlist\n      (empty delimlist))\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"+\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"2\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"3\")))))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":type"),
            vx_core.t_plus,
            vx_core.vx_new_string(":repllist"),
            vx_core.f_new(
              vx_repl.t_repllist,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.f_new(
                  vx_repl.t_repl,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":value"),
                    vx_core.vx_new_int(2)
                  )
                ),
                vx_core.f_new(
                  vx_repl.t_repl,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":value"),
                    vx_core.vx_new_int(3)
                  )
                )
              )
            )
          )
        ),
        vx_repl.f_repl_from_textblock(
          vx_core.f_new(
            vx_data_textblock.t_textblock,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":text"),
              vx_core.vx_new_string("(+ 2 3)"),
              vx_core.vx_new_string(":delim"),
              vx_core.f_copy(
                vx_repl.c_delimvxlispparen,
                vx_core.vx_new(
                  vx_core.t_anylist,
                  vx_core.vx_new_string(":delimlist"),
                  vx_core.f_empty(
                    vx_data_textblock.t_delimlist
                  )
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
                      vx_core.vx_new_string("+")
                    )
                  ),
                  vx_core.f_new(
                    vx_data_textblock.t_textblock,
                    vx_core.vx_new(
                      vx_core.t_anylist,
                      vx_core.vx_new_string(":text"),
                      vx_core.vx_new_string(" "),
                      vx_core.vx_new_string(":delim"),
                      vx_core.f_copy(
                        vx_data_textblock.c_delimwhitespace,
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
                      vx_core.vx_new_string("2")
                    )
                  ),
                  vx_core.f_new(
                    vx_data_textblock.t_textblock,
                    vx_core.vx_new(
                      vx_core.t_anylist,
                      vx_core.vx_new_string(":text"),
                      vx_core.vx_new_string(" "),
                      vx_core.vx_new_string(":delim"),
                      vx_core.f_copy(
                        vx_data_textblock.c_delimwhitespace,
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
                      vx_core.vx_new_string("3")
                    )
                  )
                )
              )
            )
          )
        )
      )
    )
    return output
  }

  fun f_repl_from_textblock_testdescribe_5(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl :value 2)\n    (repl :value 3)))\n (repl<-textblock\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"(+ 2 3)\"\n      :delim\n       (copy delimvxlispparen\n        :delimlist\n         (empty delimlist))\n      :children\n       (tb/textblocklist\n        (tb/textblock\n         :text \"+\")\n        (tb/textblock\n         :text \" \"\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"2\")\n        (tb/textblock\n         :text \" \"\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"3\")))))))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":type"),
            vx_core.t_plus,
            vx_core.vx_new_string(":repllist"),
            vx_core.f_new(
              vx_repl.t_repllist,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.f_new(
                  vx_repl.t_repl,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":value"),
                    vx_core.vx_new_int(2)
                  )
                ),
                vx_core.f_new(
                  vx_repl.t_repl,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":value"),
                    vx_core.vx_new_int(3)
                  )
                )
              )
            )
          )
        ),
        vx_repl.f_repl_from_textblock(
          vx_core.f_new(
            vx_data_textblock.t_textblock,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":text"),
              vx_core.vx_new_string("(+ 2 3)"),
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
                      vx_core.vx_new_string("(+ 2 3)"),
                      vx_core.vx_new_string(":delim"),
                      vx_core.f_copy(
                        vx_repl.c_delimvxlispparen,
                        vx_core.vx_new(
                          vx_core.t_anylist,
                          vx_core.vx_new_string(":delimlist"),
                          vx_core.f_empty(
                            vx_data_textblock.t_delimlist
                          )
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
                              vx_core.vx_new_string("+")
                            )
                          ),
                          vx_core.f_new(
                            vx_data_textblock.t_textblock,
                            vx_core.vx_new(
                              vx_core.t_anylist,
                              vx_core.vx_new_string(":text"),
                              vx_core.vx_new_string(" "),
                              vx_core.vx_new_string(":delim"),
                              vx_core.f_copy(
                                vx_data_textblock.c_delimwhitespace,
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
                              vx_core.vx_new_string("2")
                            )
                          ),
                          vx_core.f_new(
                            vx_data_textblock.t_textblock,
                            vx_core.vx_new(
                              vx_core.t_anylist,
                              vx_core.vx_new_string(":text"),
                              vx_core.vx_new_string(" "),
                              vx_core.vx_new_string(":delim"),
                              vx_core.f_copy(
                                vx_data_textblock.c_delimwhitespace,
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
                              vx_core.vx_new_string("3")
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
    return output
  }

  fun f_repl_from_textblock_argmap(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "repl<-textblock-argmap",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_repl_from_textblock_argmap_testdescribe_1(context),
        f_repl_from_textblock_argmap_testdescribe_2(context),
        f_repl_from_textblock_argmap_testdescribe_3(context),
        f_repl_from_textblock_argmap_testdescribe_4(context)
      )
    )
    return output
  }

  fun f_repl_from_textblock_argmap_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl :value 2)\n (repl<-textblock-argmap\n  (tb/textblock\n   :text \"2\")\n  (empty argmap)))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":value"),
            vx_core.vx_new_int(2)
          )
        ),
        vx_repl.f_repl_from_textblock_argmap(
          vx_core.f_new(
            vx_data_textblock.t_textblock,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":text"),
              vx_core.vx_new_string("2")
            )
          ),
          vx_core.f_empty(
            vx_core.t_argmap
          )
        )
      )
    )
    return output
  }

  fun f_repl_from_textblock_argmap_testdescribe_2(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl :type +)\n (repl<-textblock-argmap\n  (tb/textblock\n   :text \"+\")\n  (empty argmap)))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":type"),
            vx_core.t_plus
          )
        ),
        vx_repl.f_repl_from_textblock_argmap(
          vx_core.f_new(
            vx_data_textblock.t_textblock,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":text"),
              vx_core.vx_new_string("+")
            )
          ),
          vx_core.f_empty(
            vx_core.t_argmap
          )
        )
      )
    )
    return output
  }

  fun f_repl_from_textblock_argmap_testdescribe_3(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl :value 2)\n    (repl :value 3)))\n (repl<-textblock-argmap\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :delim\n    (copy delimvxlispparen\n     :delimlist\n      (empty delimlist))\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"+\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"2\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"3\")))\n  (empty argmap)))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":type"),
            vx_core.t_plus,
            vx_core.vx_new_string(":repllist"),
            vx_core.f_new(
              vx_repl.t_repllist,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.f_new(
                  vx_repl.t_repl,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":value"),
                    vx_core.vx_new_int(2)
                  )
                ),
                vx_core.f_new(
                  vx_repl.t_repl,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":value"),
                    vx_core.vx_new_int(3)
                  )
                )
              )
            )
          )
        ),
        vx_repl.f_repl_from_textblock_argmap(
          vx_core.f_new(
            vx_data_textblock.t_textblock,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":text"),
              vx_core.vx_new_string("(+ 2 3)"),
              vx_core.vx_new_string(":delim"),
              vx_core.f_copy(
                vx_repl.c_delimvxlispparen,
                vx_core.vx_new(
                  vx_core.t_anylist,
                  vx_core.vx_new_string(":delimlist"),
                  vx_core.f_empty(
                    vx_data_textblock.t_delimlist
                  )
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
                      vx_core.vx_new_string("+")
                    )
                  ),
                  vx_core.f_new(
                    vx_data_textblock.t_textblock,
                    vx_core.vx_new(
                      vx_core.t_anylist,
                      vx_core.vx_new_string(":text"),
                      vx_core.vx_new_string(" "),
                      vx_core.vx_new_string(":delim"),
                      vx_core.f_copy(
                        vx_data_textblock.c_delimwhitespace,
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
                      vx_core.vx_new_string("2")
                    )
                  ),
                  vx_core.f_new(
                    vx_data_textblock.t_textblock,
                    vx_core.vx_new(
                      vx_core.t_anylist,
                      vx_core.vx_new_string(":text"),
                      vx_core.vx_new_string(" "),
                      vx_core.vx_new_string(":delim"),
                      vx_core.f_copy(
                        vx_data_textblock.c_delimwhitespace,
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
                      vx_core.vx_new_string("3")
                    )
                  )
                )
              )
            )
          ),
          vx_core.f_empty(
            vx_core.t_argmap
          )
        )
      )
    )
    return output
  }

  fun f_repl_from_textblock_argmap_testdescribe_4(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl :value 2)\n    (repl :value 3)))\n (repl<-textblock-argmap\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"(+ 2 3)\"\n      :delim\n       (copy delimvxlispparen\n        :delimlist\n         (empty delimlist))\n      :children\n       (tb/textblocklist\n        (tb/textblock\n         :text \"+\")\n        (tb/textblock\n         :text \" \"\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"2\")\n        (tb/textblock\n         :text \" \"\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"3\")))))\n  (empty argmap)))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_repl.t_repl,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":type"),
            vx_core.t_plus,
            vx_core.vx_new_string(":repllist"),
            vx_core.f_new(
              vx_repl.t_repllist,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.f_new(
                  vx_repl.t_repl,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":value"),
                    vx_core.vx_new_int(2)
                  )
                ),
                vx_core.f_new(
                  vx_repl.t_repl,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string(":value"),
                    vx_core.vx_new_int(3)
                  )
                )
              )
            )
          )
        ),
        vx_repl.f_repl_from_textblock_argmap(
          vx_core.f_new(
            vx_data_textblock.t_textblock,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":text"),
              vx_core.vx_new_string("(+ 2 3)"),
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
                      vx_core.vx_new_string("(+ 2 3)"),
                      vx_core.vx_new_string(":delim"),
                      vx_core.f_copy(
                        vx_repl.c_delimvxlispparen,
                        vx_core.vx_new(
                          vx_core.t_anylist,
                          vx_core.vx_new_string(":delimlist"),
                          vx_core.f_empty(
                            vx_data_textblock.t_delimlist
                          )
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
                              vx_core.vx_new_string("+")
                            )
                          ),
                          vx_core.f_new(
                            vx_data_textblock.t_textblock,
                            vx_core.vx_new(
                              vx_core.t_anylist,
                              vx_core.vx_new_string(":text"),
                              vx_core.vx_new_string(" "),
                              vx_core.vx_new_string(":delim"),
                              vx_core.f_copy(
                                vx_data_textblock.c_delimwhitespace,
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
                              vx_core.vx_new_string("2")
                            )
                          ),
                          vx_core.f_new(
                            vx_data_textblock.t_textblock,
                            vx_core.vx_new(
                              vx_core.t_anylist,
                              vx_core.vx_new_string(":text"),
                              vx_core.vx_new_string(" "),
                              vx_core.vx_new_string(":delim"),
                              vx_core.f_copy(
                                vx_data_textblock.c_delimwhitespace,
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
                              vx_core.vx_new_string("3")
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
          vx_core.f_empty(
            vx_core.t_argmap
          )
        )
      )
    )
    return output
  }

  fun f_textblock_from_script(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "textblock<-script",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_textblock_from_script_testdescribe_1(context),
        f_textblock_from_script_testdescribe_2(context)
      )
    )
    return output
  }

  fun f_textblock_from_script_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (tb/textblock\n  :text \"infinity\"\n  :startpos 1\n  :endpos 8\n  :children\n   (tb/textblocklist\n    (tb/textblock\n    :text \"infinity\"\n    :startpos 1\n    :endpos 8\n    :delim\n     (delim\n      :name \"delimvxlisp\"))))\n (textblock<-script\n  \"infinity\"))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_data_textblock.t_textblock,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":text"),
            vx_core.vx_new_string("infinity"),
            vx_core.vx_new_string(":startpos"),
            vx_core.vx_new_int(1),
            vx_core.vx_new_string(":endpos"),
            vx_core.vx_new_int(8),
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
                    vx_core.vx_new_string("infinity"),
                    vx_core.vx_new_string(":startpos"),
                    vx_core.vx_new_int(1),
                    vx_core.vx_new_string(":endpos"),
                    vx_core.vx_new_int(8),
                    vx_core.vx_new_string(":delim"),
                    vx_core.f_new(
                      vx_data_textblock.t_delim,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string(":name"),
                        vx_core.vx_new_string("delimvxlisp")
                      )
                    )
                  )
                )
              )
            )
          )
        ),
        vx_repl.f_textblock_from_script(
          vx_core.vx_new_string("infinity")
        )
      )
    )
    return output
  }

  fun f_textblock_from_script_testdescribe_2(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (tb/textblock\n  :text \"(+ 2 3)\"\n  :startpos 1\n  :endpos 7\n  :children\n   (tb/textblocklist\n    (tb/textblock\n     :text \"(+ 2 3)\"\n     :startpos 1\n     :endpos 7\n     :delim\n      (copy delimvxlispparen\n       :delimlist\n        (empty delimlist))\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"+\"\n        :startpos 2\n        :endpos 2)\n       (tb/textblock\n        :text \" \"\n        :startpos 3\n        :endpos 3\n        :delim\n         (copy tb/delimwhitespace\n          :pos 0))\n       (tb/textblock\n        :text \"2\"\n        :startpos 4\n        :endpos 4)\n       (tb/textblock\n        :text \" \"\n        :startpos 5\n        :endpos 5\n        :delim\n         (copy tb/delimwhitespace\n          :pos 0))\n       (tb/textblock\n        :text \"3\"\n        :startpos 6\n        :endpos 6)))))\n (textblock<-script\n  \"(+ 2 3)\"))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_data_textblock.t_textblock,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":text"),
            vx_core.vx_new_string("(+ 2 3)"),
            vx_core.vx_new_string(":startpos"),
            vx_core.vx_new_int(1),
            vx_core.vx_new_string(":endpos"),
            vx_core.vx_new_int(7),
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
                    vx_core.vx_new_string("(+ 2 3)"),
                    vx_core.vx_new_string(":startpos"),
                    vx_core.vx_new_int(1),
                    vx_core.vx_new_string(":endpos"),
                    vx_core.vx_new_int(7),
                    vx_core.vx_new_string(":delim"),
                    vx_core.f_copy(
                      vx_repl.c_delimvxlispparen,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        vx_core.vx_new_string(":delimlist"),
                        vx_core.f_empty(
                          vx_data_textblock.t_delimlist
                        )
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
                            vx_core.vx_new_string("+"),
                            vx_core.vx_new_string(":startpos"),
                            vx_core.vx_new_int(2),
                            vx_core.vx_new_string(":endpos"),
                            vx_core.vx_new_int(2)
                          )
                        ),
                        vx_core.f_new(
                          vx_data_textblock.t_textblock,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string(":text"),
                            vx_core.vx_new_string(" "),
                            vx_core.vx_new_string(":startpos"),
                            vx_core.vx_new_int(3),
                            vx_core.vx_new_string(":endpos"),
                            vx_core.vx_new_int(3),
                            vx_core.vx_new_string(":delim"),
                            vx_core.f_copy(
                              vx_data_textblock.c_delimwhitespace,
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
                            vx_core.vx_new_string("2"),
                            vx_core.vx_new_string(":startpos"),
                            vx_core.vx_new_int(4),
                            vx_core.vx_new_string(":endpos"),
                            vx_core.vx_new_int(4)
                          )
                        ),
                        vx_core.f_new(
                          vx_data_textblock.t_textblock,
                          vx_core.vx_new(
                            vx_core.t_anylist,
                            vx_core.vx_new_string(":text"),
                            vx_core.vx_new_string(" "),
                            vx_core.vx_new_string(":startpos"),
                            vx_core.vx_new_int(5),
                            vx_core.vx_new_string(":endpos"),
                            vx_core.vx_new_int(5),
                            vx_core.vx_new_string(":delim"),
                            vx_core.f_copy(
                              vx_data_textblock.c_delimwhitespace,
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
                            vx_core.vx_new_string("3"),
                            vx_core.vx_new_string(":startpos"),
                            vx_core.vx_new_int(6),
                            vx_core.vx_new_string(":endpos"),
                            vx_core.vx_new_int(6)
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
        vx_repl.f_textblock_from_script(
          vx_core.vx_new_string("(+ 2 3)")
        )
      )
    )
    return output
  }

  fun f_typefunc_from_string(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/repl",
      ":casename", "typefunc<-string",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_typefunc_from_string_testdescribe_1(context),
        f_typefunc_from_string_testdescribe_2(context)
      )
    )
    return output
  }

  fun f_typefunc_from_string_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n string\n (typefunc<-string\n  \"string\"))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.t_string,
        vx_repl.f_typefunc_from_string(
          vx_core.vx_new_string("string")
        )
      )
    )
    return output
  }

  fun f_typefunc_from_string_testdescribe_2(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n +\n (typefunc<-string\n  \"+\"))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.t_plus,
        vx_repl.f_typefunc_from_string(
          vx_core.vx_new_string("+")
        )
      )
    )
    return output
  }

  fun test_cases(context : vx_core.Type_context) : vx_test.Type_testcaselist {
    var testcases : List<vx_core.Type_any> = vx_core.arraylist_from_array(
      vx_replTest.f_any_from_macro(context),
      vx_replTest.f_any_from_repl(context),
      vx_replTest.f_any_from_script(context),
      vx_replTest.f_const_from_string(context),
      vx_replTest.f_repl_empty_from_textblock_argmap(context),
      vx_replTest.f_repl_paren_from_textblock_argmap(context),
      vx_replTest.f_repl_from_macro(context),
      vx_replTest.f_repl_from_script(context),
      vx_replTest.f_repl_from_string_argmap(context),
      vx_replTest.f_repl_from_textblock(context),
      vx_replTest.f_repl_from_textblock_argmap(context),
      vx_replTest.f_textblock_from_script(context),
      vx_replTest.f_typefunc_from_string(context)
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
      ":testpkg", "vx/repl", 
      ":constnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 3), 
      ":docnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 28, ":total", 28), 
      ":funcnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 61, ":tests", 13, ":total", 21), 
      ":bigospacenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 21), 
      ":bigotimenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 21), 
      ":totalnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 46, ":tests", 13, ":total", 28), 
      ":typenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 4)
    )
    return output
  }

  fun test_coveragedetail() : vx_test.Type_testcoveragedetail {
    var output : vx_test.Type_testcoveragedetail = vx_core.vx_new(
      vx_test.t_testcoveragedetail,
      ":testpkg", "vx/repl",
      ":typemap", vx_core.vx_new(
        vx_core.t_intmap,
        ":liblist", 0,
        ":repl", 0,
        ":replarglist", 0,
        ":repllist", 0
      ), 
      ":constmap", vx_core.vx_new(
        vx_core.t_intmap,
        ":delimvxlisp", 0,
        ":delimvxlispbracket", 0,
        ":delimvxlispparen", 0
      ), 
      ":funcmap", vx_core.vx_new(
        vx_core.t_intmap,
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
    )
    return output
  }

  fun test_package(context : vx_core.Type_context) : vx_test.Type_testpackage {
    var testcaselist : vx_test.Type_testcaselist = test_cases(context)
    var output : vx_test.Type_testpackage = vx_core.vx_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/repl", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    )
    return output
  }

}
