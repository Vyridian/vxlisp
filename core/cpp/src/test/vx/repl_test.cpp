#include "../../main/vx/repl.hpp"
#include "../../main/vx/core.hpp"
#include "../../main/vx/test.hpp"
#include "../../main/vx/type.hpp"
#include "../../main/vx/data/textblock.hpp"

#include "repl_test.hpp"

namespace vx_repl_test {

  vx_test::Type_testcase f_any_from_repl(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_any_from_repl");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::vx_new_string("HelloWorld"),
      vx_repl::f_any_from_repl(
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
        ),
        context
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"HelloWorld\"\n (any<-repl\n  (repl\n   :type string\n   :repllist\n    (repllist\n     (repl :val \"Hello\")\n     (repl :val \"World\")\n    ))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      vx_core::vx_new_int(5),
      vx_repl::f_any_from_repl(
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
        context
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n 5\n (any<-repl\n  (repl\n   :type +\n   :repllist\n    (repllist\n     (repl :val 2)\n     (repl :val 3)\n    ))))"),
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

  vx_test::Type_testcase f_textblock_repl_from_script(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_textblock_repl_from_script");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
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
      vx_repl::f_textblock_repl_from_script(vx_core::vx_new_string("(+ 2 3)")),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (tb/textblock\n  :text \"(+ 2 3)\"\n  :startpos 1\n  :endpos 7\n  :children\n   (tb/textblocklist\n    (tb/textblock\n     :text \"(+ 2 3)\"\n     :startpos 1\n     :endpos 7\n     :delim\n      (copy delimvxlispparen\n       :delimlist\n        (empty delimlist))\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"+\"\n        :startpos 2\n        :endpos 2)\n       (tb/textblock\n        :text \" \"\n        :startpos 3\n        :endpos 3\n        :delim\n         (copy tb/delimwhitespace\n          :pos 0))\n       (tb/textblock\n        :text \"2\"\n        :startpos 4\n        :endpos 4)\n       (tb/textblock\n        :text \" \"\n        :startpos 5\n        :endpos 5\n        :delim\n         (copy tb/delimwhitespace\n          :pos 0))\n       (tb/textblock\n        :text \"3\"\n        :startpos 6\n        :endpos 6)))))\n (textblock-repl<-script\n  \"(+ 2 3)\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("textblock-repl<-script"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_textblock_repl_from_script");
    return output;
  }

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {
    vx_core::vx_Type_listany listtestcase;
    listtestcase.push_back(vx_repl_test::f_any_from_repl(context));
    listtestcase.push_back(vx_repl_test::f_textblock_repl_from_script(context));
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
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(15), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(15)
      }),
      vx_core::vx_new_string(":funcnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(22), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(2), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(9)
      }),
      vx_core::vx_new_string(":bigospacenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(9)
      }),
      vx_core::vx_new_string(":bigotimenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(9)
      }),
      vx_core::vx_new_string(":totalnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(13), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(2), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(15)
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
        vx_core::vx_new_string(":any<-repl"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":any<-script"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":anylist<-repllist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":macro"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":repl<-liblist-string"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":repl<-textblock"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":textblock-repl<-script"), vx_core::vx_new_int(1)
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
