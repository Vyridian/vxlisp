#include "../../main/vx/collection.hpp"
#include "../../main/vx/core.hpp"
#include "../../main/vx/test.hpp"
#include "../../main/vx/type.hpp"

namespace vx_collection_test {

  vx_test::Type_testcase f_list_from_list_end(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/collection"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("list<-list-end"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(vx_test::t_testdescribelist, 
        vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
          vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test\n (stringlist \"a\" \"b\" \"c\")\n (list<-list-end\n  (stringlist \"a\" \"b\" \"c\" \"d\")\n  3))"),
          vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
              vx_core::f_new(
                vx_core::t_stringlist,
                vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                  vx_core::t_string->vx_new_from_string("a"),
                  vx_core::t_string->vx_new_from_string("b"),
                  vx_core::t_string->vx_new_from_string("c")
                })
              ),
              vx_collection::f_list_from_list_end(
                vx_core::t_stringlist,
                vx_core::f_new(
                  vx_core::t_stringlist,
                  vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                    vx_core::t_string->vx_new_from_string("a"),
                    vx_core::t_string->vx_new_from_string("b"),
                    vx_core::t_string->vx_new_from_string("c"),
                    vx_core::t_string->vx_new_from_string("d")
                  })
                ),
                vx_core::t_int->vx_new_from_int(3)
              ),
              context
            )
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_list_from_list_filtertypes(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/collection"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("list<-list-filtertypes"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(vx_test::t_testdescribelist, 
        vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
          vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test\n (list \"a\" 1 \"b\" \"c\")\n (list<-list-filtertypes : list\n  (list \"a\" 1 \"b\" \"c\" 4.5)\n  string int))"),
          vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
              vx_core::f_new(
                vx_core::t_list,
                vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                  vx_core::t_string->vx_new_from_string("a"),
                  vx_core::t_int->vx_new_from_int(1),
                  vx_core::t_string->vx_new_from_string("b"),
                  vx_core::t_string->vx_new_from_string("c")
                })
              ),
              vx_collection::f_list_from_list_filtertypes(
                vx_core::t_list,
                vx_core::f_new(
                  vx_core::t_list,
                  vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                    vx_core::t_string->vx_new_from_string("a"),
                    vx_core::t_int->vx_new_from_int(1),
                    vx_core::t_string->vx_new_from_string("b"),
                    vx_core::t_string->vx_new_from_string("c"),
                    vx_core::t_decimal->vx_new_from_string("4.5")
                  })
                ),
                vx_core::t_typelist->vx_new(vx_core::t_typelist, {
                  vx_core::t_string,
                  vx_core::t_int
                })
              ),
              context
            )
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_list_from_list_fn_filter(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/collection"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("list<-list-fn-filter"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(vx_test::t_testdescribelist, 
        vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
          vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test\n (stringlist \"a1\" \"b1\" \"c1\" \"d1\")\n (list<-list-fn-filter : stringlist\n  (list \"a\" 4 \"b\" (list) \"c\" (map) \"d\")\n  (fn : string\n   [val : any]\n   (if\n    (then\n     (is-string val)\n     (string val \"1\"))))))"),
          vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
              vx_core::f_new(
                vx_core::t_stringlist,
                vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                  vx_core::t_string->vx_new_from_string("a1"),
                  vx_core::t_string->vx_new_from_string("b1"),
                  vx_core::t_string->vx_new_from_string("c1"),
                  vx_core::t_string->vx_new_from_string("d1")
                })
              ),
              vx_collection::f_list_from_list_fn_filter(
                vx_core::t_stringlist,
                vx_core::f_new(
                  vx_core::t_list,
                  vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                    vx_core::t_string->vx_new_from_string("a"),
                    vx_core::t_int->vx_new_from_int(4),
                    vx_core::t_string->vx_new_from_string("b"),
                    vx_core::f_empty(
                      vx_core::t_list
                    ),
                    vx_core::t_string->vx_new_from_string("c"),
                    vx_core::f_empty(
                      vx_core::t_map
                    ),
                    vx_core::t_string->vx_new_from_string("d")
                  })
                ),
                vx_core::t_any_from_any->fn_new([](vx_core::Type_any val_any) {
                  vx_core::Type_any val = vx_core::f_any_from_any(vx_core::t_any, val_any);
                  return 
                    vx_core::f_if_2(
                      vx_core::t_string,
                      vx_core::t_thenelselist->vx_new(vx_core::t_thenelselist, {
                        vx_core::f_then(
                          vx_core::t_boolean_from_func->fn_new([val]() {
                            return vx_type::f_is_string(val);
                          }),
                          vx_core::t_any_from_func->fn_new([val]() {
                            return vx_core::f_new(
                              vx_core::t_string,
                              vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                                val,
                                vx_core::t_string->vx_new_from_string("1")
                              })
                            );
                          })
                        )
                      })
                    );
                })
              ),
              context
            )
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_list_from_list_start(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/collection"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("list<-list-start"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(vx_test::t_testdescribelist, 
        vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
          vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test\n (stringlist \"b\" \"c\" \"d\")\n (list<-list-start\n  (stringlist \"a\" \"b\" \"c\" \"d\")\n  1))"),
          vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
              vx_core::f_new(
                vx_core::t_stringlist,
                vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                  vx_core::t_string->vx_new_from_string("b"),
                  vx_core::t_string->vx_new_from_string("c"),
                  vx_core::t_string->vx_new_from_string("d")
                })
              ),
              vx_collection::f_list_from_list_start(
                vx_core::t_stringlist,
                vx_core::f_new(
                  vx_core::t_stringlist,
                  vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                    vx_core::t_string->vx_new_from_string("a"),
                    vx_core::t_string->vx_new_from_string("b"),
                    vx_core::t_string->vx_new_from_string("c"),
                    vx_core::t_string->vx_new_from_string("d")
                  })
                ),
                vx_core::t_int->vx_new_from_int(1)
              ),
              context
            )
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_list_from_list_start_end(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/collection"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("list<-list-start-end"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(vx_test::t_testdescribelist, 
        vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
          vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test\n (stringlist \"b\" \"c\")\n (list<-list-start-end\n  (stringlist \"a\" \"b\" \"c\" \"d\")\n  1 3))"),
          vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
              vx_core::f_new(
                vx_core::t_stringlist,
                vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                  vx_core::t_string->vx_new_from_string("b"),
                  vx_core::t_string->vx_new_from_string("c")
                })
              ),
              vx_collection::f_list_from_list_start_end(
                vx_core::t_stringlist,
                vx_core::f_new(
                  vx_core::t_stringlist,
                  vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                    vx_core::t_string->vx_new_from_string("a"),
                    vx_core::t_string->vx_new_from_string("b"),
                    vx_core::t_string->vx_new_from_string("c"),
                    vx_core::t_string->vx_new_from_string("d")
                  })
                ),
                vx_core::t_int->vx_new_from_int(1),
                vx_core::t_int->vx_new_from_int(3)
              ),
              context
            )
        })
      )
    });
    return output;
  }

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {
    vx_core::vx_Type_listany arraylisttestcase;
    arraylisttestcase->push_back(vx_collection_test::f_list_from_list_end(context));
    arraylisttestcase->push_back(vx_collection_test::f_list_from_list_filtertypes(context));
    arraylisttestcase->push_back(vx_collection_test::f_list_from_list_fn_filter(context));
    arraylisttestcase->push_back(vx_collection_test::f_list_from_list_start(context));
    arraylisttestcase->push_back(vx_collection_test::f_list_from_list_start_end(context));
    vx_test::Type_testcaselist output = vx_test::t_testcaselist->vx_new_from_list(vx_test::t_testcaselist, arraylisttestcase);
    return output;
  }

  vx_test::Type_testcoveragesummary test_coveragesummary() {
    return vx_test::t_testcoveragesummary->vx_new(vx_test::t_testcoveragesummary, {
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/collection"),
      vx_core::t_string->vx_new_from_string(":constnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(100), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(0)
      }),
      vx_core::t_string->vx_new_from_string(":docnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(100), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(7), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(7)
      }),
      vx_core::t_string->vx_new_from_string(":funcnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(71), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(5), 
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
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(71), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(5), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(7)
      }),
      vx_core::t_string->vx_new_from_string(":typenums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(100), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(0)
      })
    });
  }

  vx_test::Type_testcoveragedetail test_coveragedetail() {
    return vx_test::t_testcoveragedetail->vx_new(vx_test::t_testcoveragedetail, {
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/collection"),
      vx_core::t_string->vx_new_from_string(":typemap"), vx_core::t_intmap->vx_new(vx_core::t_intmap, {
        
      }),
      vx_core::t_string->vx_new_from_string(":constmap"), vx_core::t_intmap->vx_new(vx_core::t_intmap, {
        
      }),
      vx_core::t_string->vx_new_from_string(":funcmap"), vx_core::t_intmap->vx_new(vx_core::t_intmap, {
              vx_core::t_string->vx_new_from_string(":is-list"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":is-map"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":list<-list-end"), vx_core::t_int->vx_new_from_int(1),
              vx_core::t_string->vx_new_from_string(":list<-list-filtertypes"), vx_core::t_int->vx_new_from_int(1),
              vx_core::t_string->vx_new_from_string(":list<-list-fn-filter"), vx_core::t_int->vx_new_from_int(1),
              vx_core::t_string->vx_new_from_string(":list<-list-start"), vx_core::t_int->vx_new_from_int(1),
              vx_core::t_string->vx_new_from_string(":list<-list-start-end"), vx_core::t_int->vx_new_from_int(1)
      })
    });
  }

  vx_test::Type_testpackage test_package(vx_core::Type_context context) {
    vx_test::Type_testcaselist testcaselist = test_cases(context);
    vx_test::Type_testpackage output = vx_test::t_testpackage->vx_new(vx_test::t_testpackage, {
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/collection"), 
      vx_core::t_string->vx_new_from_string(":caselist"), testcaselist,
      vx_core::t_string->vx_new_from_string(":coveragesummary"), test_coveragesummary(),
      vx_core::t_string->vx_new_from_string(":coveragedetail"), test_coveragedetail()
    });
    return output;
  }

}
