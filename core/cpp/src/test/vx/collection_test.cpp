#include "../../main/vx/collection.hpp"
#include "../../main/vx/core.hpp"
#include "../../main/vx/test.hpp"
#include "../../main/vx/type.hpp"

#include "collection_test.hpp"

namespace vx_collection_test {

  vx_test::Type_testcase f_list_from_list_end(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_list_from_list_end");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::f_new(
        vx_core::t_stringlist,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string("a"),
          vx_core::vx_new_string("b"),
          vx_core::vx_new_string("c")
        })
      ),
      vx_collection::f_list_from_list_end(
        vx_core::t_stringlist,
        vx_core::f_new(
          vx_core::t_stringlist,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string("a"),
            vx_core::vx_new_string("b"),
            vx_core::vx_new_string("c"),
            vx_core::vx_new_string("d")
          })
        ),
        vx_core::vx_new_int(3)
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (stringlist \"a\" \"b\" \"c\")\n (list<-list-end\n  (stringlist \"a\" \"b\" \"c\" \"d\")\n  3))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/collection"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/collection"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("list<-list-end"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_list_from_list_end");
    return output;
  }

  vx_test::Type_testcase f_list_from_list_filtertypes(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_list_from_list_filtertypes");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::f_new(
        vx_core::t_list,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string("a"),
          vx_core::vx_new_int(1),
          vx_core::vx_new_string("b"),
          vx_core::vx_new_string("c")
        })
      ),
      vx_collection::f_list_from_list_filtertypes(
        vx_core::t_list,
        vx_core::f_new(
          vx_core::t_list,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string("a"),
            vx_core::vx_new_int(1),
            vx_core::vx_new_string("b"),
            vx_core::vx_new_string("c"),
            vx_core::vx_new_decimal_from_string("4.5")
          })
        ),
        vx_core::vx_new(vx_core::t_typelist, {
          vx_core::t_string,
          vx_core::t_int
        })
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (list \"a\" 1 \"b\" \"c\")\n (list<-list-filtertypes : list\n  (list \"a\" 1 \"b\" \"c\" 4.5)\n  string int))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/collection"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/collection"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("list<-list-filtertypes"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_list_from_list_filtertypes");
    return output;
  }

  vx_test::Type_testcase f_list_from_list_fn_filter(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_list_from_list_fn_filter");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::f_new(
        vx_core::t_stringlist,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string("a1"),
          vx_core::vx_new_string("b1"),
          vx_core::vx_new_string("c1"),
          vx_core::vx_new_string("d1")
        })
      ),
      vx_collection::f_list_from_list_fn_filter(
        vx_core::t_stringlist,
        vx_core::f_new(
          vx_core::t_list,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string("a"),
            vx_core::vx_new_int(4),
            vx_core::vx_new_string("b"),
            vx_core::f_empty(
              vx_core::t_list
            ),
            vx_core::vx_new_string("c"),
            vx_core::f_empty(
              vx_core::t_map
            ),
            vx_core::vx_new_string("d")
          })
        ),
        vx_core::t_any_from_any->vx_fn_new({}, [](vx_core::Type_any val) {
          vx_core::Type_any output_1 = 
            vx_core::f_if_2(
              vx_core::t_string,
              vx_core::vx_new(vx_core::t_thenelselist, {
                vx_core::f_then(
                  vx_core::t_boolean_from_func->vx_fn_new({val}, [val]() {
                    vx_core::Type_boolean output_1 = vx_type::f_is_string(val);
                    return output_1;
                  }),
                  vx_core::t_any_from_func->vx_fn_new({val}, [val]() {
                    vx_core::Type_string output_1 = vx_core::f_new(
                      vx_core::t_string,
                      vx_core::vx_new(vx_core::t_anylist, {
                        val,
                        vx_core::vx_new_string("1")
                      })
                    );
                    return output_1;
                  })
                )
              })
            );
          return output_1;
        })
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (stringlist \"a1\" \"b1\" \"c1\" \"d1\")\n (list<-list-fn-filter : stringlist\n  (list \"a\" 4 \"b\" (list) \"c\" (map) \"d\")\n  (fn : string\n   [val : any]\n   (if\n    (then\n     (is-string val)\n     (string val \"1\"))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/collection"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/collection"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("list<-list-fn-filter"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_list_from_list_fn_filter");
    return output;
  }

  vx_test::Type_testcase f_list_from_list_start(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_list_from_list_start");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::f_new(
        vx_core::t_stringlist,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string("b"),
          vx_core::vx_new_string("c"),
          vx_core::vx_new_string("d")
        })
      ),
      vx_collection::f_list_from_list_start(
        vx_core::t_stringlist,
        vx_core::f_new(
          vx_core::t_stringlist,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string("a"),
            vx_core::vx_new_string("b"),
            vx_core::vx_new_string("c"),
            vx_core::vx_new_string("d")
          })
        ),
        vx_core::vx_new_int(1)
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (stringlist \"b\" \"c\" \"d\")\n (list<-list-start\n  (stringlist \"a\" \"b\" \"c\" \"d\")\n  1))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/collection"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/collection"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("list<-list-start"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_list_from_list_start");
    return output;
  }

  vx_test::Type_testcase f_list_from_list_start_end(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_list_from_list_start_end");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::f_new(
        vx_core::t_stringlist,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string("b"),
          vx_core::vx_new_string("c")
        })
      ),
      vx_collection::f_list_from_list_start_end(
        vx_core::t_stringlist,
        vx_core::f_new(
          vx_core::t_stringlist,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string("a"),
            vx_core::vx_new_string("b"),
            vx_core::vx_new_string("c"),
            vx_core::vx_new_string("d")
          })
        ),
        vx_core::vx_new_int(1),
        vx_core::vx_new_int(3)
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (stringlist \"b\" \"c\")\n (list<-list-start-end\n  (stringlist \"a\" \"b\" \"c\" \"d\")\n  1 3))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/collection"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/collection"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("list<-list-start-end"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_list_from_list_start_end");
    return output;
  }

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {
    vx_core::vx_Type_listany listtestcase;
    listtestcase.push_back(vx_collection_test::f_list_from_list_end(context));
    listtestcase.push_back(vx_collection_test::f_list_from_list_filtertypes(context));
    listtestcase.push_back(vx_collection_test::f_list_from_list_fn_filter(context));
    listtestcase.push_back(vx_collection_test::f_list_from_list_start(context));
    listtestcase.push_back(vx_collection_test::f_list_from_list_start_end(context));
    vx_test::Type_testcaselist output = vx_core::vx_any_from_any(
      vx_test::t_testcaselist,
      vx_test::t_testcaselist->vx_new_from_list(listtestcase)
    );
    return output;
  }

  vx_test::Type_testcoveragesummary test_coveragesummary() {
    vx_test::Type_testcoveragesummary output = vx_core::vx_new(vx_test::t_testcoveragesummary, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/collection"),
      vx_core::vx_new_string(":constnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(100), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":docnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(100), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(7), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(7)
      }),
      vx_core::vx_new_string(":funcnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(71), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(5), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(7)
      }),
      vx_core::vx_new_string(":bigospacenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(7)
      }),
      vx_core::vx_new_string(":bigotimenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(7)
      }),
      vx_core::vx_new_string(":totalnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(71), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(5), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(7)
      }),
      vx_core::vx_new_string(":typenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(100), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(0)
      })
    });
    return output;
  }

  vx_test::Type_testcoveragedetail test_coveragedetail() {
    vx_test::Type_testcoveragedetail output = vx_core::vx_new(vx_test::t_testcoveragedetail, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/collection"),
      vx_core::vx_new_string(":typemap"), vx_core::vx_new(vx_core::t_intmap, {
        
      }),
      vx_core::vx_new_string(":constmap"), vx_core::vx_new(vx_core::t_intmap, {
        
      }),
      vx_core::vx_new_string(":funcmap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":is-list"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":is-map"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":list<-list-end"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":list<-list-filtertypes"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":list<-list-fn-filter"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":list<-list-start"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":list<-list-start-end"), vx_core::vx_new_int(1)
      })
    });
    return output;
  }

  vx_test::Type_testpackage test_package(vx_core::Type_context context) {
    vx_test::Type_testcaselist testcaselist = vx_collection_test::test_cases(context);
    vx_test::Type_testcoveragesummary testcoveragesummary = vx_collection_test::test_coveragesummary();
    vx_test::Type_testcoveragedetail testcoveragedetail = vx_collection_test::test_coveragedetail();
    vx_test::Type_testpackage output = vx_core::vx_new(vx_test::t_testpackage, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/collection"),
      vx_core::vx_new_string(":caselist"), testcaselist,
      vx_core::vx_new_string(":coveragesummary"), testcoveragesummary,
      vx_core::vx_new_string(":coveragedetail"), testcoveragedetail
    });
    return output;
  }

}
