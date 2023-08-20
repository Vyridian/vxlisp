#include "../../main/vx/repl.hpp"
#include "../../main/vx/core.hpp"
#include "../../main/vx/test.hpp"
#include "../../main/vx/data/textblock.hpp"

#include "repl_test.hpp"

namespace vx_repl_test {

  vx_test::Type_testcase f_any_from_repl(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("any<-repl"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"HelloWorld\"\n (any<-repl\n  (repl\n   :type string\n   :repllist\n    (repllist\n     (repl :val \"Hello\")\n     (repl :val \"World\")\n    ))))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("HelloWorld"),
              vx_repl::f_any_from_repl(
                vx_core::f_new(
                  vx_repl::t_repl(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":type"),
                    vx_core::t_string(),
                    vx_core::vx_new_string(":repllist"),
                    vx_core::f_new(
                      vx_repl::t_repllist(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        vx_core::f_new(
                          vx_repl::t_repl(),
                          vx_core::vx_new(vx_core::t_anylist(), {
                            vx_core::vx_new_string(":val"),
                            vx_core::vx_new_string("Hello")
                          })
                        ),
                        vx_core::f_new(
                          vx_repl::t_repl(),
                          vx_core::vx_new(vx_core::t_anylist(), {
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
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n 5\n (any<-repl\n  (repl\n   :type +\n   :repllist\n    (repllist\n     (repl :val 2)\n     (repl :val 3)\n    ))))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(5),
              vx_repl::f_any_from_repl(
                vx_core::f_new(
                  vx_repl::t_repl(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":type"),
                    vx_core::t_plus(),
                    vx_core::vx_new_string(":repllist"),
                    vx_core::f_new(
                      vx_repl::t_repllist(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        vx_core::f_new(
                          vx_repl::t_repl(),
                          vx_core::vx_new(vx_core::t_anylist(), {
                            vx_core::vx_new_string(":val"),
                            vx_core::vx_new_int(2)
                          })
                        ),
                        vx_core::f_new(
                          vx_repl::t_repl(),
                          vx_core::vx_new(vx_core::t_anylist(), {
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
            )
          })
        })
      )
    });
    return output;
  }

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {
    vx_core::vx_Type_listany listtestcase;
    listtestcase.push_back(vx_repl_test::f_any_from_repl(context));
    vx_test::Type_testcaselist output = vx_core::vx_any_from_any(
      vx_test::t_testcaselist(),
      vx_test::t_testcaselist()->vx_new_from_list(listtestcase)
    );
    return output;
  }

  vx_test::Type_testcoveragesummary test_coveragesummary() {
    vx_test::Type_testcoveragesummary output = vx_core::vx_new(vx_test::t_testcoveragesummary(), {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":constnums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(100), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":docnums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(100), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(10), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(10)
      }),
      vx_core::vx_new_string(":funcnums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(14), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(1), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(7)
      }),
      vx_core::vx_new_string(":bigospacenums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(7)
      }),
      vx_core::vx_new_string(":bigotimenums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(7)
      }),
      vx_core::vx_new_string(":totalnums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(10), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(1), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(10)
      }),
      vx_core::vx_new_string(":typenums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(3)
      })
    });
    return output;
  }

  vx_test::Type_testcoveragedetail test_coveragedetail() {
    vx_test::Type_testcoveragedetail output = vx_core::vx_new(vx_test::t_testcoveragedetail(), {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":typemap"), vx_core::vx_new(vx_core::t_intmap(), {
        vx_core::vx_new_string(":liblist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":repl"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":repllist"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":constmap"), vx_core::vx_new(vx_core::t_intmap(), {
        
      }),
      vx_core::vx_new_string(":funcmap"), vx_core::vx_new(vx_core::t_intmap(), {
        vx_core::vx_new_string(":any-repl<-functype-args"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":any<-liblist-string"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":any<-liblist-string-async"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":any<-repl"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":any<-repl-async"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":anylist<-repllist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":repl<-liblist-string"), vx_core::vx_new_int(0)
      })
    });
    return output;
  }

  vx_test::Type_testpackage test_package(vx_core::Type_context context) {
    vx_test::Type_testcaselist testcaselist = vx_repl_test::test_cases(context);
    vx_test::Type_testcoveragesummary testcoveragesummary = vx_repl_test::test_coveragesummary();
    vx_test::Type_testcoveragedetail testcoveragedetail = vx_repl_test::test_coveragedetail();
    vx_test::Type_testpackage output = vx_core::vx_new(vx_test::t_testpackage(), {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/repl"),
      vx_core::vx_new_string(":caselist"), testcaselist,
      vx_core::vx_new_string(":coveragesummary"), testcoveragesummary,
      vx_core::vx_new_string(":coveragedetail"), testcoveragedetail
    });
    return output;
  }

}
