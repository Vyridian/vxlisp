#include "../../main/vx/repl.hpp"
#include "../../main/vx/core.hpp"
#include "../../main/vx/test.hpp"
#include "../../main/vx/data/textblock.hpp"

namespace vx_repl_test {

  vx_test::Type_testcase f_any_from_repl(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/repl"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("any<-repl"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(
        vx_test::t_testdescribelist,
        {
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test\n \"HelloWorld\"\n (any<-repl\n  (repl\n   :type string\n   :repllist\n    (repllist\n     (repl :val \"Hello\")\n     (repl :val \"World\")\n    ))))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
                vx_core::t_string->vx_new_from_string("HelloWorld"),
                vx_repl::f_any_from_repl(
                  vx_core::f_new(
                    vx_repl::t_repl,
                    vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                      vx_core::t_string->vx_new_from_string(":type"),
                      vx_core::t_string,
                      vx_core::t_string->vx_new_from_string(":repllist"),
                      vx_core::f_new(
                        vx_repl::t_repllist,
                        vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                          vx_core::f_new(
                            vx_repl::t_repl,
                            vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                              vx_core::t_string->vx_new_from_string(":val"),
                              vx_core::t_string->vx_new_from_string("Hello")
                            })
                          ),
                          vx_core::f_new(
                            vx_repl::t_repl,
                            vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                              vx_core::t_string->vx_new_from_string(":val"),
                              vx_core::t_string->vx_new_from_string("World")
                            })
                          )
                        })
                      )
                    })
                  ),
                  context
                ),
                context
              )
          }),
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test\n 5\n (any<-repl\n  (repl\n   :type +\n   :repllist\n    (repllist\n     (repl :val 2)\n     (repl :val 3)\n    ))))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
                vx_core::t_int->vx_new_from_int(5),
                vx_repl::f_any_from_repl(
                  vx_core::f_new(
                    vx_repl::t_repl,
                    vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                      vx_core::t_string->vx_new_from_string(":type"),
                      vx_core::t_plus,
                      vx_core::t_string->vx_new_from_string(":repllist"),
                      vx_core::f_new(
                        vx_repl::t_repllist,
                        vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                          vx_core::f_new(
                            vx_repl::t_repl,
                            vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                              vx_core::t_string->vx_new_from_string(":val"),
                              vx_core::t_int->vx_new_from_int(2)
                            })
                          ),
                          vx_core::f_new(
                            vx_repl::t_repl,
                            vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                              vx_core::t_string->vx_new_from_string(":val"),
                              vx_core::t_int->vx_new_from_int(3)
                            })
                          )
                        })
                      )
                    })
                  ),
                  context
                ),
                context
              )
          })
        }
      )
    });
    return output;
  }

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {
    vx_core::vx_Type_listany arraylisttestcase;
    arraylisttestcase.push_back(vx_repl_test::f_any_from_repl(context));
    vx_test::Type_testcaselist output = vx_test::t_testcaselist->vx_new_from_list(vx_test::t_testcaselist, arraylisttestcase);
    return output;
  }

  vx_test::Type_testcoveragesummary test_coveragesummary() {
    return vx_test::t_testcoveragesummary->vx_new(vx_test::t_testcoveragesummary, {
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/repl"),
      vx_core::t_string->vx_new_from_string(":constnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(100), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(0)
      }),
      vx_core::t_string->vx_new_from_string(":docnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(100), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(10), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(10)
      }),
      vx_core::t_string->vx_new_from_string(":funcnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(14), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(1), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(7)
      }),
      vx_core::t_string->vx_new_from_string(":ospacenums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(7)
      }),
      vx_core::t_string->vx_new_from_string(":otimenums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(7)
      }),
      vx_core::t_string->vx_new_from_string(":totalnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(10), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(1), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(10)
      }),
      vx_core::t_string->vx_new_from_string(":typenums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(3)
      })
    });
  }

  vx_test::Type_testcoveragedetail test_coveragedetail() {
    return vx_test::t_testcoveragedetail->vx_new(vx_test::t_testcoveragedetail, {
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/repl"),
      vx_core::t_string->vx_new_from_string(":typemap"), vx_core::t_intmap->vx_new(vx_core::t_intmap, {
              vx_core::t_string->vx_new_from_string(":liblist"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":repl"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":repllist"), vx_core::t_int->vx_new_from_int(0)
      }),
      vx_core::t_string->vx_new_from_string(":constmap"), vx_core::t_intmap->vx_new(vx_core::t_intmap, {
        
      }),
      vx_core::t_string->vx_new_from_string(":funcmap"), vx_core::t_intmap->vx_new(vx_core::t_intmap, {
              vx_core::t_string->vx_new_from_string(":any-repl<-functype-args"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":any<-liblist-string"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":any<-liblist-string-async"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":any<-repl"), vx_core::t_int->vx_new_from_int(2),
              vx_core::t_string->vx_new_from_string(":any<-repl-async"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":anylist<-repllist"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":repl<-liblist-string"), vx_core::t_int->vx_new_from_int(0)
      })
    });
  }

  vx_test::Type_testpackage test_package(vx_core::Type_context context) {
    vx_test::Type_testcaselist testcaselist = test_cases(context);
    vx_test::Type_testpackage output = vx_test::t_testpackage->vx_new(vx_test::t_testpackage, {
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/repl"), 
      vx_core::t_string->vx_new_from_string(":caselist"), testcaselist,
      vx_core::t_string->vx_new_from_string(":coveragesummary"), test_coveragesummary(),
      vx_core::t_string->vx_new_from_string(":coveragedetail"), test_coveragedetail()
    });
    return output;
  }

}
