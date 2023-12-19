#include "../../main/vx/repl.hpp"
#include "../../main/vx/core.hpp"
#include "../../main/vx/test.hpp"
#include "../../main/vx/collection.hpp"
#include "../../main/vx/type.hpp"
#include "../../main/vx/data/textblock.hpp"

#include "repl_test.hpp"

namespace vx_repl_test {

  vx_test::Type_testcase f_any_from_macro(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_any_from_macro");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::vx_new_int(5),
      vx_repl::f_any_from_macro(
        vx_core::t_int,
        context,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string("(+ "),
          vx_core::f_minus(vx_core::vx_new_int(7), vx_core::vx_new_int(5)),
          vx_core::vx_new_string(" 3)")
        })
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n 5\n (any<-macro : int\n  \"(+ \"\n  (- 7 5)\n  \" 3)\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("any<-macro"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_any_from_macro");
    return output;
  }

  vx_test::Type_testcase f_any_from_repl(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_any_from_repl");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::vx_new_string("HelloWorld"),
      vx_repl::f_any_from_repl(
        context,
        vx_core::f_new(
          vx_repl::t_repl,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":type"),
            vx_core::t_string,
            vx_core::vx_new_string(":repllist"),
            vx_core::f_new(
              vx_repl::t_repllist,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::f_new(
                  vx_repl::t_repl,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":val"),
                    vx_core::vx_new_string("Hello")
                  })
                ),
                vx_core::f_new(
                  vx_repl::t_repl,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":val"),
                    vx_core::vx_new_string("World")
                  })
                )
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"HelloWorld\"\n (any<-repl\n  (repl\n   :type string\n   :repllist\n    (repllist\n     (repl :val \"Hello\")\n     (repl :val \"World\")\n    ))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::vx_new_int(5),
      vx_repl::f_any_from_repl(
        context,
        vx_core::f_new(
          vx_repl::t_repl,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":type"),
            vx_core::t_plus,
            vx_core::vx_new_string(":repllist"),
            vx_core::f_new(
              vx_repl::t_repllist,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::f_new(
                  vx_repl::t_repl,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":val"),
                    vx_core::vx_new_int(2)
                  })
                ),
                vx_core::f_new(
                  vx_repl::t_repl,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":val"),
                    vx_core::vx_new_int(3)
                  })
                )
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n 5\n (any<-repl\n  (repl\n   :type +\n   :repllist\n    (repllist\n     (repl :val 2)\n     (repl :val 3)))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("any<-repl"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_any_from_repl");
    return output;
  }

  vx_test::Type_testcase f_any_from_script(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_any_from_script");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::vx_new_int(5),
      vx_repl::f_any_from_script(context, vx_core::vx_new_string("(+ 2 3)"))
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n 5\n (any<-script\n  \"(+ 2 3)\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("any<-script"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_any_from_script");
    return output;
  }

  vx_test::Type_testcase f_const_from_string(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_const_from_string");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::c_infinity,
      vx_repl::f_const_from_string(vx_core::vx_new_string("infinity"))
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n infinity\n (const<-string\n  \"infinity\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_data_textblock::c_delimcomma,
      vx_repl::f_const_from_string(vx_core::vx_new_string("vx/data/textblock/delimcomma"))
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n tb/delimcomma\n (const<-string\n  \"vx/data/textblock/delimcomma\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("const<-string"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_const_from_string");
    return output;
  }

  vx_test::Type_testcase f_repl_empty_from_textblock_argmap(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_repl_empty_from_textblock_argmap");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":val"),
          vx_core::vx_new_int(2)
        })
      ),
      vx_repl::f_repl_empty_from_textblock_argmap(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("2")
          })
        ),
        vx_core::f_empty(
          vx_core::t_argmap
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl :val 2)\n (repl-empty<-textblock-argmap\n  (tb/textblock\n   :text \"2\")\n  (empty argmap)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":type"),
          vx_core::t_plus
        })
      ),
      vx_repl::f_repl_empty_from_textblock_argmap(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("+")
          })
        ),
        vx_core::f_empty(
          vx_core::t_argmap
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl :type +)\n (repl-empty<-textblock-argmap\n  (tb/textblock\n   :text \"+\")\n  (empty argmap)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    // testdescribe_3
    vx_test::Type_testresult testresult_3 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":val"),
          vx_core::vx_new_int(2)
        })
      ),
      vx_repl::f_repl_empty_from_textblock_argmap(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("1"),
            vx_core::vx_new_string(":children"),
            vx_core::f_new(
              vx_data_textblock::t_textblocklist,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("2")
                  })
                )
              })
            )
          })
        ),
        vx_core::f_empty(
          vx_core::t_argmap
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_3 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl :val 2)\n (repl-empty<-textblock-argmap\n  (tb/textblock\n   :text \"1\"\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"2\")))\n  (empty argmap)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_3
    });
    // testdescribe_4
    vx_test::Type_testresult testresult_4 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::f_msg_from_error(vx_core::vx_new_string("Empty delim cannot have more than one child."))
        })
      ),
      vx_repl::f_repl_empty_from_textblock_argmap(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("1"),
            vx_core::vx_new_string(":children"),
            vx_core::f_new(
              vx_data_textblock::t_textblocklist,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("2")
                  })
                ),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("3")
                  })
                )
              })
            )
          })
        ),
        vx_core::f_empty(
          vx_core::t_argmap
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_4 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl\n  (msg<-error \"Empty delim cannot have more than one child.\"))\n (repl-empty<-textblock-argmap\n  (tb/textblock\n   :text \"1\"\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"2\")\n     (tb/textblock\n      :text \"3\")))\n  (empty argmap)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_4
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2,
      testdescribe_3,
      testdescribe_4
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("repl-empty<-textblock-argmap"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_repl_empty_from_textblock_argmap");
    return output;
  }

  vx_test::Type_testcase f_repl_paren_from_textblock_argmap(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_repl_paren_from_textblock_argmap");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":type"),
          vx_core::t_plus,
          vx_core::vx_new_string(":repllist"),
          vx_core::f_new(
            vx_repl::t_repllist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::f_new(
                vx_repl::t_repl,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":val"),
                  vx_core::vx_new_int(2)
                })
              ),
              vx_core::f_new(
                vx_repl::t_repl,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":val"),
                  vx_core::vx_new_int(3)
                })
              )
            })
          )
        })
      ),
      vx_repl::f_repl_paren_from_textblock_argmap(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("(+ 2 3)"),
            vx_core::vx_new_string(":delim"),
            vx_core::f_copy(
              vx_data_textblock::t_delim,
              vx_repl::c_delimvxlispparen,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_core::f_empty(
                  vx_data_textblock::t_delimlist
                )
              })
            ),
            vx_core::vx_new_string(":children"),
            vx_core::f_new(
              vx_data_textblock::t_textblocklist,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("+")
                  })
                ),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string(" "),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimwhitespace,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":pos"),
                        vx_core::vx_new_int(0)
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("2")
                  })
                ),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string(" "),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimwhitespace,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":pos"),
                        vx_core::vx_new_int(0)
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("3")
                  })
                )
              })
            )
          })
        ),
        vx_core::f_empty(
          vx_core::t_argmap
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl\n  :type vx/core/+\n  :repllist\n   (repllist\n    (repl\n     :val 2)\n    (repl\n     :val 3)))\n (repl-paren<-textblock-argmap\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :delim\n    (copy delimvxlispparen\n     :delimlist\n      (empty delimlist))\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"+\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"2\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"3\")))\n  (empty argmap)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("repl-paren<-textblock-argmap"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_repl_paren_from_textblock_argmap");
    return output;
  }

  vx_test::Type_testcase f_repl_from_macro(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_repl_from_macro");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":type"),
          vx_core::t_plus,
          vx_core::vx_new_string(":repllist"),
          vx_core::f_new(
            vx_repl::t_repllist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::f_new(
                vx_repl::t_repl,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":val"),
                  vx_core::vx_new_int(2)
                })
              ),
              vx_core::f_new(
                vx_repl::t_repl,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":val"),
                  vx_core::vx_new_int(3)
                })
              )
            })
          )
        })
      ),
      vx_repl::f_repl_from_macro(
        context,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string("(+ "),
          vx_core::f_minus(vx_core::vx_new_int(7), vx_core::vx_new_int(5)),
          vx_core::vx_new_string(" 3)")
        })
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl\n  :type vx/core/+\n  :repllist\n   (repllist\n    (repl\n     :val 2)\n    (repl\n     :val 3)))\n (repl<-macro\n  \"(+ \"\n  (- 7 5)\n  \" 3)\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("repl<-macro"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_repl_from_macro");
    return output;
  }

  vx_test::Type_testcase f_repl_from_script(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_repl_from_script");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":val"),
          vx_core::vx_new_int(2)
        })
      ),
      vx_repl::f_repl_from_script(vx_core::vx_new_string("2"))
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl\n  :val 2)\n (repl<-script\n  \"2\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":val"),
          vx_core::c_infinity
        })
      ),
      vx_repl::f_repl_from_script(vx_core::vx_new_string("infinity"))
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl\n  :val infinity)\n (repl<-script\n  \"infinity\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    // testdescribe_3
    vx_test::Type_testresult testresult_3 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":type"),
          vx_core::t_plus
        })
      ),
      vx_repl::f_repl_from_script(vx_core::vx_new_string("+"))
    );
    vx_test::Type_testdescribe testdescribe_3 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl\n  :type +)\n (repl<-script\n  \"+\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_3
    });
    // testdescribe_4
    vx_test::Type_testresult testresult_4 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":type"),
          vx_core::t_plus,
          vx_core::vx_new_string(":repllist"),
          vx_core::f_new(
            vx_repl::t_repllist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::f_new(
                vx_repl::t_repl,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":val"),
                  vx_core::vx_new_int(2)
                })
              ),
              vx_core::f_new(
                vx_repl::t_repl,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":val"),
                  vx_core::vx_new_int(3)
                })
              )
            })
          )
        })
      ),
      vx_repl::f_repl_from_script(vx_core::vx_new_string("(+ 2 3)"))
    );
    vx_test::Type_testdescribe testdescribe_4 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl\n     :val 2)\n    (repl\n     :val 3)))\n (repl<-script\n  \"(+ 2 3)\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_4
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2,
      testdescribe_3,
      testdescribe_4
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("repl<-script"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_repl_from_script");
    return output;
  }

  vx_test::Type_testcase f_repl_from_string_argmap(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_repl_from_string_argmap");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":val"),
          vx_core::vx_new_string("Hello")
        })
      ),
      vx_repl::f_repl_from_string_argmap(
        vx_core::vx_new_string("\"Hello\""),
        vx_core::f_empty(
          vx_core::t_argmap
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl :val \"Hello\")\n (repl<-string-argmap\n  `\"Hello\"`\n  (empty argmap)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":val"),
          vx_core::vx_new_int(2)
        })
      ),
      vx_repl::f_repl_from_string_argmap(
        vx_core::vx_new_string("2"),
        vx_core::f_empty(
          vx_core::t_argmap
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl\n  :val 2)\n (repl<-string-argmap\n  \"2\"\n  (empty argmap)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    // testdescribe_3
    vx_test::Type_testresult testresult_3 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":val"),
          vx_core::vx_new_decimal_from_string("2.3")
        })
      ),
      vx_repl::f_repl_from_string_argmap(
        vx_core::vx_new_string("2.3"),
        vx_core::f_empty(
          vx_core::t_argmap
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_3 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl :val 2.3)\n (repl<-string-argmap\n  \"2.3\"\n  (empty argmap)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_3
    });
    // testdescribe_4
    vx_test::Type_testresult testresult_4 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":val"),
          vx_core::c_infinity
        })
      ),
      vx_repl::f_repl_from_string_argmap(
        vx_core::vx_new_string("infinity"),
        vx_core::f_empty(
          vx_core::t_argmap
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_4 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl\n  :val infinity)\n (repl<-string-argmap\n  \"infinity\"\n  (empty argmap)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_4
    });
    // testdescribe_5
    vx_test::Type_testresult testresult_5 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":val"),
          vx_data_textblock::c_delimcomma
        })
      ),
      vx_repl::f_repl_from_string_argmap(
        vx_core::vx_new_string("vx/data/textblock/delimcomma"),
        vx_core::f_empty(
          vx_core::t_argmap
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_5 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl\n  :val tb/delimcomma)\n (repl<-string-argmap\n  \"vx/data/textblock/delimcomma\"\n  (empty argmap)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_5
    });
    // testdescribe_6
    vx_test::Type_testresult testresult_6 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":type"),
          vx_core::t_string
        })
      ),
      vx_repl::f_repl_from_string_argmap(
        vx_core::vx_new_string("string"),
        vx_core::f_empty(
          vx_core::t_argmap
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_6 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl :type string)\n (repl<-string-argmap\n  \"string\"\n  (empty argmap)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_6
    });
    // testdescribe_7
    vx_test::Type_testresult testresult_7 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":type"),
          vx_core::t_plus
        })
      ),
      vx_repl::f_repl_from_string_argmap(
        vx_core::vx_new_string("+"),
        vx_core::f_empty(
          vx_core::t_argmap
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_7 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl :type +)\n (repl<-string-argmap\n  \"+\"\n  (empty argmap)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_7
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2,
      testdescribe_3,
      testdescribe_4,
      testdescribe_5,
      testdescribe_6,
      testdescribe_7
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("repl<-string-argmap"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_repl_from_string_argmap");
    return output;
  }

  vx_test::Type_testcase f_repl_from_textblock(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_repl_from_textblock");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":val"),
          vx_core::vx_new_int(2)
        })
      ),
      vx_repl::f_repl_from_textblock(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("2")
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl :val 2)\n (repl<-textblock\n  (tb/textblock\n   :text \"2\")))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":type"),
          vx_core::t_plus
        })
      ),
      vx_repl::f_repl_from_textblock(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("+")
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl :type +)\n (repl<-textblock\n  (tb/textblock\n   :text \"+\")))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    // testdescribe_3
    vx_test::Type_testresult testresult_3 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":type"),
          vx_core::t_plus
        })
      ),
      vx_repl::f_repl_from_textblock(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("+")
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_3 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl :type +)\n (repl<-textblock\n  (tb/textblock\n   :text \"+\")))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_3
    });
    // testdescribe_4
    vx_test::Type_testresult testresult_4 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":type"),
          vx_core::t_plus,
          vx_core::vx_new_string(":repllist"),
          vx_core::f_new(
            vx_repl::t_repllist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::f_new(
                vx_repl::t_repl,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":val"),
                  vx_core::vx_new_int(2)
                })
              ),
              vx_core::f_new(
                vx_repl::t_repl,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":val"),
                  vx_core::vx_new_int(3)
                })
              )
            })
          )
        })
      ),
      vx_repl::f_repl_from_textblock(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("(+ 2 3)"),
            vx_core::vx_new_string(":delim"),
            vx_core::f_copy(
              vx_data_textblock::t_delim,
              vx_repl::c_delimvxlispparen,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_core::f_empty(
                  vx_data_textblock::t_delimlist
                )
              })
            ),
            vx_core::vx_new_string(":children"),
            vx_core::f_new(
              vx_data_textblock::t_textblocklist,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("+")
                  })
                ),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string(" "),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimwhitespace,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":pos"),
                        vx_core::vx_new_int(0)
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("2")
                  })
                ),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string(" "),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimwhitespace,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":pos"),
                        vx_core::vx_new_int(0)
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("3")
                  })
                )
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_4 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl :val 2)\n    (repl :val 3)))\n (repl<-textblock\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :delim\n    (copy delimvxlispparen\n     :delimlist\n      (empty delimlist))\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"+\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"2\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"3\")))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_4
    });
    // testdescribe_5
    vx_test::Type_testresult testresult_5 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":type"),
          vx_core::t_plus,
          vx_core::vx_new_string(":repllist"),
          vx_core::f_new(
            vx_repl::t_repllist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::f_new(
                vx_repl::t_repl,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":val"),
                  vx_core::vx_new_int(2)
                })
              ),
              vx_core::f_new(
                vx_repl::t_repl,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":val"),
                  vx_core::vx_new_int(3)
                })
              )
            })
          )
        })
      ),
      vx_repl::f_repl_from_textblock(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("(+ 2 3)"),
            vx_core::vx_new_string(":children"),
            vx_core::f_new(
              vx_data_textblock::t_textblocklist,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("(+ 2 3)"),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_repl::c_delimvxlispparen,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":delimlist"),
                        vx_core::f_empty(
                          vx_data_textblock::t_delimlist
                        )
                      })
                    ),
                    vx_core::vx_new_string(":children"),
                    vx_core::f_new(
                      vx_data_textblock::t_textblocklist,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::f_new(
                          vx_data_textblock::t_textblock,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string("+")
                          })
                        ),
                        vx_core::f_new(
                          vx_data_textblock::t_textblock,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string(" "),
                            vx_core::vx_new_string(":delim"),
                            vx_core::f_copy(
                              vx_data_textblock::t_delim,
                              vx_data_textblock::c_delimwhitespace,
                              vx_core::vx_new(vx_core::t_anylist, {
                                vx_core::vx_new_string(":pos"),
                                vx_core::vx_new_int(0)
                              })
                            )
                          })
                        ),
                        vx_core::f_new(
                          vx_data_textblock::t_textblock,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string("2")
                          })
                        ),
                        vx_core::f_new(
                          vx_data_textblock::t_textblock,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string(" "),
                            vx_core::vx_new_string(":delim"),
                            vx_core::f_copy(
                              vx_data_textblock::t_delim,
                              vx_data_textblock::c_delimwhitespace,
                              vx_core::vx_new(vx_core::t_anylist, {
                                vx_core::vx_new_string(":pos"),
                                vx_core::vx_new_int(0)
                              })
                            )
                          })
                        ),
                        vx_core::f_new(
                          vx_data_textblock::t_textblock,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string("3")
                          })
                        )
                      })
                    )
                  })
                )
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_5 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl :val 2)\n    (repl :val 3)))\n (repl<-textblock\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"(+ 2 3)\"\n      :delim\n       (copy delimvxlispparen\n        :delimlist\n         (empty delimlist))\n      :children\n       (tb/textblocklist\n        (tb/textblock\n         :text \"+\")\n        (tb/textblock\n         :text \" \"\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"2\")\n        (tb/textblock\n         :text \" \"\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"3\")))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_5
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2,
      testdescribe_3,
      testdescribe_4,
      testdescribe_5
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("repl<-textblock"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_repl_from_textblock");
    return output;
  }

  vx_test::Type_testcase f_repl_from_textblock_argmap(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_repl_from_textblock_argmap");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":val"),
          vx_core::vx_new_int(2)
        })
      ),
      vx_repl::f_repl_from_textblock_argmap(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("2")
          })
        ),
        vx_core::f_empty(
          vx_core::t_argmap
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl :val 2)\n (repl<-textblock-argmap\n  (tb/textblock\n   :text \"2\")\n  (empty argmap)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":type"),
          vx_core::t_plus
        })
      ),
      vx_repl::f_repl_from_textblock_argmap(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("+")
          })
        ),
        vx_core::f_empty(
          vx_core::t_argmap
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl :type +)\n (repl<-textblock-argmap\n  (tb/textblock\n   :text \"+\")\n  (empty argmap)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    // testdescribe_3
    vx_test::Type_testresult testresult_3 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":type"),
          vx_core::t_plus,
          vx_core::vx_new_string(":repllist"),
          vx_core::f_new(
            vx_repl::t_repllist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::f_new(
                vx_repl::t_repl,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":val"),
                  vx_core::vx_new_int(2)
                })
              ),
              vx_core::f_new(
                vx_repl::t_repl,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":val"),
                  vx_core::vx_new_int(3)
                })
              )
            })
          )
        })
      ),
      vx_repl::f_repl_from_textblock_argmap(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("(+ 2 3)"),
            vx_core::vx_new_string(":delim"),
            vx_core::f_copy(
              vx_data_textblock::t_delim,
              vx_repl::c_delimvxlispparen,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_core::f_empty(
                  vx_data_textblock::t_delimlist
                )
              })
            ),
            vx_core::vx_new_string(":children"),
            vx_core::f_new(
              vx_data_textblock::t_textblocklist,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("+")
                  })
                ),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string(" "),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimwhitespace,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":pos"),
                        vx_core::vx_new_int(0)
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("2")
                  })
                ),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string(" "),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimwhitespace,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":pos"),
                        vx_core::vx_new_int(0)
                      })
                    )
                  })
                ),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("3")
                  })
                )
              })
            )
          })
        ),
        vx_core::f_empty(
          vx_core::t_argmap
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_3 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl :val 2)\n    (repl :val 3)))\n (repl<-textblock-argmap\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :delim\n    (copy delimvxlispparen\n     :delimlist\n      (empty delimlist))\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"+\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"2\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"3\")))\n  (empty argmap)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_3
    });
    // testdescribe_4
    vx_test::Type_testresult testresult_4 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_repl::t_repl,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":type"),
          vx_core::t_plus,
          vx_core::vx_new_string(":repllist"),
          vx_core::f_new(
            vx_repl::t_repllist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::f_new(
                vx_repl::t_repl,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":val"),
                  vx_core::vx_new_int(2)
                })
              ),
              vx_core::f_new(
                vx_repl::t_repl,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":val"),
                  vx_core::vx_new_int(3)
                })
              )
            })
          )
        })
      ),
      vx_repl::f_repl_from_textblock_argmap(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("(+ 2 3)"),
            vx_core::vx_new_string(":children"),
            vx_core::f_new(
              vx_data_textblock::t_textblocklist,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("(+ 2 3)"),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_repl::c_delimvxlispparen,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":delimlist"),
                        vx_core::f_empty(
                          vx_data_textblock::t_delimlist
                        )
                      })
                    ),
                    vx_core::vx_new_string(":children"),
                    vx_core::f_new(
                      vx_data_textblock::t_textblocklist,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::f_new(
                          vx_data_textblock::t_textblock,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string("+")
                          })
                        ),
                        vx_core::f_new(
                          vx_data_textblock::t_textblock,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string(" "),
                            vx_core::vx_new_string(":delim"),
                            vx_core::f_copy(
                              vx_data_textblock::t_delim,
                              vx_data_textblock::c_delimwhitespace,
                              vx_core::vx_new(vx_core::t_anylist, {
                                vx_core::vx_new_string(":pos"),
                                vx_core::vx_new_int(0)
                              })
                            )
                          })
                        ),
                        vx_core::f_new(
                          vx_data_textblock::t_textblock,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string("2")
                          })
                        ),
                        vx_core::f_new(
                          vx_data_textblock::t_textblock,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string(" "),
                            vx_core::vx_new_string(":delim"),
                            vx_core::f_copy(
                              vx_data_textblock::t_delim,
                              vx_data_textblock::c_delimwhitespace,
                              vx_core::vx_new(vx_core::t_anylist, {
                                vx_core::vx_new_string(":pos"),
                                vx_core::vx_new_int(0)
                              })
                            )
                          })
                        ),
                        vx_core::f_new(
                          vx_data_textblock::t_textblock,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string("3")
                          })
                        )
                      })
                    )
                  })
                )
              })
            )
          })
        ),
        vx_core::f_empty(
          vx_core::t_argmap
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_4 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (repl\n  :type +\n  :repllist\n   (repllist\n    (repl :val 2)\n    (repl :val 3)))\n (repl<-textblock-argmap\n  (tb/textblock\n   :text \"(+ 2 3)\"\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"(+ 2 3)\"\n      :delim\n       (copy delimvxlispparen\n        :delimlist\n         (empty delimlist))\n      :children\n       (tb/textblocklist\n        (tb/textblock\n         :text \"+\")\n        (tb/textblock\n         :text \" \"\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"2\")\n        (tb/textblock\n         :text \" \"\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"3\")))))\n  (empty argmap)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_4
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2,
      testdescribe_3,
      testdescribe_4
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("repl<-textblock-argmap"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_repl_from_textblock_argmap");
    return output;
  }

  vx_test::Type_testcase f_textblock_from_script(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_textblock_from_script");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("infinity"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(1),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(8),
          vx_core::vx_new_string(":children"),
          vx_core::f_new(
            vx_data_textblock::t_textblocklist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("infinity"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(8),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_new(
                    vx_data_textblock::t_delim,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":name"),
                      vx_core::vx_new_string("delimvxlisp")
                    })
                  )
                })
              )
            })
          )
        })
      ),
      vx_repl::f_textblock_from_script(vx_core::vx_new_string("infinity"))
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (tb/textblock\n  :text \"infinity\"\n  :startpos 1\n  :endpos 8\n  :children\n   (tb/textblocklist\n    (tb/textblock\n    :text \"infinity\"\n    :startpos 1\n    :endpos 8\n    :delim\n     (delim\n      :name \"delimvxlisp\"))))\n (textblock<-script\n  \"infinity\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("(+ 2 3)"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(1),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(7),
          vx_core::vx_new_string(":children"),
          vx_core::f_new(
            vx_data_textblock::t_textblocklist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("(+ 2 3)"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(7),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_repl::c_delimvxlispparen,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      vx_core::f_empty(
                        vx_data_textblock::t_delimlist
                      )
                    })
                  ),
                  vx_core::vx_new_string(":children"),
                  vx_core::f_new(
                    vx_data_textblock::t_textblocklist,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::f_new(
                        vx_data_textblock::t_textblock,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":text"),
                          vx_core::vx_new_string("+"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(2),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(2)
                        })
                      ),
                      vx_core::f_new(
                        vx_data_textblock::t_textblock,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":text"),
                          vx_core::vx_new_string(" "),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(3),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(3),
                          vx_core::vx_new_string(":delim"),
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_textblock::c_delimwhitespace,
                            vx_core::vx_new(vx_core::t_anylist, {
                              vx_core::vx_new_string(":pos"),
                              vx_core::vx_new_int(0)
                            })
                          )
                        })
                      ),
                      vx_core::f_new(
                        vx_data_textblock::t_textblock,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":text"),
                          vx_core::vx_new_string("2"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(4),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(4)
                        })
                      ),
                      vx_core::f_new(
                        vx_data_textblock::t_textblock,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":text"),
                          vx_core::vx_new_string(" "),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(5),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(5),
                          vx_core::vx_new_string(":delim"),
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_textblock::c_delimwhitespace,
                            vx_core::vx_new(vx_core::t_anylist, {
                              vx_core::vx_new_string(":pos"),
                              vx_core::vx_new_int(0)
                            })
                          )
                        })
                      ),
                      vx_core::f_new(
                        vx_data_textblock::t_textblock,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":text"),
                          vx_core::vx_new_string("3"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(6),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(6)
                        })
                      )
                    })
                  )
                })
              )
            })
          )
        })
      ),
      vx_repl::f_textblock_from_script(vx_core::vx_new_string("(+ 2 3)"))
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (tb/textblock\n  :text \"(+ 2 3)\"\n  :startpos 1\n  :endpos 7\n  :children\n   (tb/textblocklist\n    (tb/textblock\n     :text \"(+ 2 3)\"\n     :startpos 1\n     :endpos 7\n     :delim\n      (copy delimvxlispparen\n       :delimlist\n        (empty delimlist))\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"+\"\n        :startpos 2\n        :endpos 2)\n       (tb/textblock\n        :text \" \"\n        :startpos 3\n        :endpos 3\n        :delim\n         (copy tb/delimwhitespace\n          :pos 0))\n       (tb/textblock\n        :text \"2\"\n        :startpos 4\n        :endpos 4)\n       (tb/textblock\n        :text \" \"\n        :startpos 5\n        :endpos 5\n        :delim\n         (copy tb/delimwhitespace\n          :pos 0))\n       (tb/textblock\n        :text \"3\"\n        :startpos 6\n        :endpos 6)))))\n (textblock<-script\n  \"(+ 2 3)\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("textblock<-script"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_textblock_from_script");
    return output;
  }

  vx_test::Type_testcase f_typefunc_from_string(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_typefunc_from_string");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::t_string,
      vx_repl::f_typefunc_from_string(vx_core::vx_new_string("string"))
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n string\n (typefunc<-string\n  \"string\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::t_plus,
      vx_repl::f_typefunc_from_string(vx_core::vx_new_string("+"))
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n +\n (typefunc<-string\n  \"+\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("typefunc<-string"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_typefunc_from_string");
    return output;
  }

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {
    vx_core::vx_Type_listany listtestcase;
    listtestcase.push_back(vx_repl_test::f_any_from_macro(context));
    listtestcase.push_back(vx_repl_test::f_any_from_repl(context));
    listtestcase.push_back(vx_repl_test::f_any_from_script(context));
    listtestcase.push_back(vx_repl_test::f_const_from_string(context));
    listtestcase.push_back(vx_repl_test::f_repl_empty_from_textblock_argmap(context));
    listtestcase.push_back(vx_repl_test::f_repl_paren_from_textblock_argmap(context));
    listtestcase.push_back(vx_repl_test::f_repl_from_macro(context));
    listtestcase.push_back(vx_repl_test::f_repl_from_script(context));
    listtestcase.push_back(vx_repl_test::f_repl_from_string_argmap(context));
    listtestcase.push_back(vx_repl_test::f_repl_from_textblock(context));
    listtestcase.push_back(vx_repl_test::f_repl_from_textblock_argmap(context));
    listtestcase.push_back(vx_repl_test::f_textblock_from_script(context));
    listtestcase.push_back(vx_repl_test::f_typefunc_from_string(context));
    vx_test::Type_testcaselist output = vx_core::vx_any_from_any(
      vx_test::t_testcaselist,
      vx_test::t_testcaselist->vx_new_from_list(listtestcase)
    );
    return output;
  }

  vx_test::Type_testcoveragesummary test_coveragesummary() {
    vx_test::Type_testcoveragesummary output = vx_core::vx_new(vx_test::t_testcoveragesummary, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":constnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(3)
      }),
      vx_core::vx_new_string(":docnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(100), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(25), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(25)
      }),
      vx_core::vx_new_string(":funcnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(68), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(13), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(19)
      }),
      vx_core::vx_new_string(":bigospacenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(19)
      }),
      vx_core::vx_new_string(":bigotimenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(19)
      }),
      vx_core::vx_new_string(":totalnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(52), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(13), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(25)
      }),
      vx_core::vx_new_string(":typenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(3)
      })
    });
    return output;
  }

  vx_test::Type_testcoveragedetail test_coveragedetail() {
    vx_test::Type_testcoveragedetail output = vx_core::vx_new(vx_test::t_testcoveragedetail, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":typemap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":liblist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":repl"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":repllist"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":constmap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":delimvxlisp"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimvxlispbracket"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimvxlispparen"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":funcmap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":any-repl<-functype-args"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":any<-liblist-string"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":any<-macro"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":any<-repl"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":any<-script"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":anylist<-repllist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":argmap<-textblock-argmap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":const<-string"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":repl-empty<-textblock-argmap"), vx_core::vx_new_int(4),
        vx_core::vx_new_string(":repl-paren<-textblock-argmap"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":repl<-liblist-string"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":repl<-macro"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":repl<-script"), vx_core::vx_new_int(4),
        vx_core::vx_new_string(":repl<-string-argmap"), vx_core::vx_new_int(7),
        vx_core::vx_new_string(":repl<-textblock"), vx_core::vx_new_int(5),
        vx_core::vx_new_string(":repl<-textblock-argmap"), vx_core::vx_new_int(4),
        vx_core::vx_new_string(":repllist<-textblocklist-argmap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":textblock<-script"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":typefunc<-string"), vx_core::vx_new_int(2)
      })
    });
    return output;
  }

  vx_test::Type_testpackage test_package(vx_core::Type_context context) {
    vx_test::Type_testcaselist testcaselist = vx_repl_test::test_cases(context);
    vx_test::Type_testcoveragesummary testcoveragesummary = vx_repl_test::test_coveragesummary();
    vx_test::Type_testcoveragedetail testcoveragedetail = vx_repl_test::test_coveragedetail();
    vx_test::Type_testpackage output = vx_core::vx_new(vx_test::t_testpackage, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":caselist"), testcaselist,
      vx_core::vx_new_string(":coveragesummary"), testcoveragesummary,
      vx_core::vx_new_string(":coveragedetail"), testcoveragedetail
    });
    return output;
  }

}
