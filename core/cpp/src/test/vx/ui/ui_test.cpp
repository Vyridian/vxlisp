#include "../../../main/vx/ui/ui.hpp"
#include "../../../main/vx/core.hpp"
#include "../../../main/vx/test.hpp"
#include "../../../main/vx/collection.hpp"
#include "../../../main/vx/event.hpp"
#include "../../../main/vx/data/file.hpp"
#include "../../../main/vx/state.hpp"
#include "../../../main/vx/type.hpp"
#include "ui_test.hpp"

namespace vx_ui_ui_test {


  vx_test::Type_testcase f_boolean_writestate_from_uiapp(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_boolean_writestate_from_uiapp");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_ui_ui::t_ui,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":uid"),
          vx_core::vx_new_string("app")
        })
      ),
      vx_core::f_let(
        vx_ui_ui::t_ui,
        vx_core::t_any_from_func->vx_fn_new({context}, [context]() {
          vx_core::Type_boolean iswrite = vx_ui_ui::f_boolean_writestate_from_uiapp(
            context,
            vx_core::f_new(
              vx_ui_ui::t_ui,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":uid"),
                vx_core::vx_new_string("app")
              })
            )
          );
          vx_core::vx_ref_plus(iswrite);
          vx_ui_ui::Type_ui appui = vx_ui_ui::f_ui_readstate_uiapp(context);
          vx_core::vx_ref_plus(appui);
          vx_core::Type_boolean isremoved = vx_ui_ui::f_boolean_removestate_uiapp(context);
          vx_core::vx_ref_plus(isremoved);
          vx_ui_ui::Type_ui output_1 = appui;
          vx_core::vx_release_one_except({iswrite, appui, isremoved}, output_1);
          return output_1;
        })
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (ui :uid \"app\")\n (let : ui\n  [iswrite : boolean :=\n    (boolean-writestate<-uiapp\n     (ui :uid \"app\"))\n   appui : ui :=\n    (ui-readstate-uiapp)\n   isremoved : boolean :=\n    (boolean-removestate-uiapp)]\n  appui))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/ui/ui"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/ui/ui"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("boolean-writestate<-uiapp"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_boolean_writestate_from_uiapp");
    return output;
  }

  vx_test::Type_testcase f_string_parentuid_from_uid(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_string_parentuid_from_uid");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::vx_new_string(""),
      vx_ui_ui::f_string_parentuid_from_uid(vx_core::vx_new_string("a"))
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"\"\n (string-parentuid<-uid\n  \"a\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/ui/ui"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::vx_new_string("a/b"),
      vx_ui_ui::f_string_parentuid_from_uid(vx_core::vx_new_string("a/b/c"))
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"a/b\"\n (string-parentuid<-uid\n  \"a/b/c\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/ui/ui"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/ui/ui"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("string-parentuid<-uid"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_string_parentuid_from_uid");
    return output;
  }

  vx_test::Type_testcase f_ui_readstate_uiapp(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_ui_readstate_uiapp");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_ui_ui::t_ui,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":uid"),
          vx_core::vx_new_string("myapp")
        })
      ),
      vx_core::f_let(
        vx_ui_ui::t_ui,
        vx_core::t_any_from_func->vx_fn_new({context}, [context]() {
          vx_core::Type_boolean iswrite = vx_ui_ui::f_boolean_writestate_from_uiapp(
            context,
            vx_core::f_new(
              vx_ui_ui::t_ui,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":uid"),
                vx_core::vx_new_string("myapp")
              })
            )
          );
          vx_core::vx_ref_plus(iswrite);
          vx_ui_ui::Type_ui output_1 = vx_ui_ui::f_ui_readstate_uiapp(context);
          vx_core::vx_release_one_except(iswrite, output_1);
          return output_1;
        })
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (ui\n  :uid \"myapp\")\n (let : ui\n  [iswrite : boolean :=\n    (boolean-writestate<-uiapp\n     (ui\n      :uid \"myapp\"))]\n  (ui-readstate-uiapp)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/ui/ui"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/ui/ui"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("ui-readstate-uiapp"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_ui_readstate_uiapp");
    return output;
  }

  vx_test::Type_testcase f_ui_readstate_from_uid(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_ui_readstate_from_uid");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_ui_ui::t_ui,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":uid"),
          vx_core::vx_new_string("a/b/c")
        })
      ),
      vx_core::f_let(
        vx_ui_ui::t_ui,
        vx_core::t_any_from_func->vx_fn_new({context}, [context]() {
          vx_ui_ui::Type_ui uiapp = vx_core::f_new(
            vx_ui_ui::t_ui,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":uid"),
              vx_core::vx_new_string("a"),
              vx_core::vx_new_string(":uimap"),
              vx_ui_ui::f_uimap_from_uilist(
                vx_core::vx_new(vx_ui_ui::t_uilist, {
                  vx_core::f_new(
                    vx_ui_ui::t_ui,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":uid"),
                      vx_core::vx_new_string("a/b"),
                      vx_core::vx_new_string(":uimap"),
                      vx_ui_ui::f_uimap_from_uilist(
                        vx_core::vx_new(vx_ui_ui::t_uilist, {
                          vx_core::f_new(
                            vx_ui_ui::t_ui,
                            vx_core::vx_new(vx_core::t_anylist, {
                              vx_core::vx_new_string(":uid"),
                              vx_core::vx_new_string("a/b/c")
                            })
                          )
                        })
                      )
                    })
                  )
                })
              )
            })
          );
          vx_core::vx_ref_plus(uiapp);
          vx_core::Type_boolean iswrite = vx_ui_ui::f_boolean_writestate_from_uiapp(context, uiapp);
          vx_core::vx_ref_plus(iswrite);
          vx_ui_ui::Type_ui readval = vx_ui_ui::f_ui_readstate_from_uid(context, vx_core::vx_new_string("a/b/c"));
          vx_core::vx_ref_plus(readval);
          vx_core::Type_boolean isremoved = vx_ui_ui::f_boolean_removestate_uiapp(context);
          vx_core::vx_ref_plus(isremoved);
          vx_ui_ui::Type_ui output_1 = readval;
          vx_core::vx_release_one_except({uiapp, iswrite, readval, isremoved}, output_1);
          return output_1;
        })
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (ui\n  :uid \"a/b/c\")\n (let : ui\n  [uiapp : ui :=\n    (ui\n     :uid \"a\"\n     :uimap\n      (uimap<-uilist\n       (ui\n        :uid \"a/b\"\n        :uimap\n         (uimap<-uilist\n          (ui\n           :uid \"a/b/c\")))))\n   iswrite : boolean :=\n    (boolean-writestate<-uiapp uiapp)\n   readval : ui :=\n    (ui-readstate<-uid\n     \"a/b/c\")\n   isremoved : boolean := (boolean-removestate-uiapp)]\n  readval))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/ui/ui"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/ui/ui"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("ui-readstate<-uid"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_ui_readstate_from_uid");
    return output;
  }

  vx_test::Type_testcase f_ui_from_ui_find(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_ui_from_ui_find");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_ui_ui::t_ui,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":uid"),
          vx_core::vx_new_string("a/b/c")
        })
      ),
      vx_ui_ui::f_ui_from_ui_find(
        vx_core::f_new(
          vx_ui_ui::t_ui,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":uid"),
            vx_core::vx_new_string("a"),
            vx_core::vx_new_string(":uimap"),
            vx_core::f_new(
              vx_ui_ui::t_uimap,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":a/b"),
                vx_core::f_new(
                  vx_ui_ui::t_ui,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":uid"),
                    vx_core::vx_new_string("a/b"),
                    vx_core::vx_new_string(":uimap"),
                    vx_core::f_new(
                      vx_ui_ui::t_uimap,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":a/b/c"),
                        vx_core::f_new(
                          vx_ui_ui::t_ui,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":uid"),
                            vx_core::vx_new_string("a/b/c")
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
        vx_core::vx_new_string("a/b/c")
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (ui\n  :uid \"a/b/c\")\n (ui<-ui-find\n  (ui\n   :uid \"a\"\n   :uimap\n    (uimap\n     :a/b\n      (ui\n       :uid \"a/b\"\n       :uimap\n        (uimap\n         :a/b/c\n          (ui\n           :uid \"a/b/c\")))))\n  \"a/b/c\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/ui/ui"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/ui/ui"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("ui<-ui-find"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_ui_from_ui_find");
    return output;
  }

  vx_test::Type_testcase f_ui_from_ui_selected(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_ui_from_ui_selected");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_ui_ui::t_ui,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":uimap"),
          vx_core::f_new(
            vx_ui_ui::t_uimap,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":a"),
              vx_core::f_new(
                vx_ui_ui::t_ui,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":uid"),
                  vx_core::vx_new_string("a")
                })
              ),
              vx_core::vx_new_string(":b"),
              vx_core::f_new(
                vx_ui_ui::t_ui,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":uid"),
                  vx_core::vx_new_string("b"),
                  vx_core::vx_new_string(":selected"),
                  vx_core::vx_new_boolean(true)
                })
              )
            })
          )
        })
      ),
      vx_ui_ui::f_ui_from_ui_selected(
        vx_core::f_new(
          vx_ui_ui::t_ui,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":uimap"),
            vx_core::f_new(
              vx_ui_ui::t_uimap,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":a"),
                vx_core::f_new(
                  vx_ui_ui::t_ui,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":uid"),
                    vx_core::vx_new_string("a"),
                    vx_core::vx_new_string(":selected"),
                    vx_core::vx_new_boolean(true)
                  })
                ),
                vx_core::vx_new_string(":b"),
                vx_core::f_new(
                  vx_ui_ui::t_ui,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":uid"),
                    vx_core::vx_new_string("b")
                  })
                )
              })
            )
          })
        ),
        vx_core::vx_new_int(2)
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (ui\n  :uimap\n   (uimap\n    :a\n     (ui\n      :uid \"a\")\n    :b\n     (ui\n      :uid \"b\"\n      :selected true)))\n (ui<-ui-selected\n  (ui\n   :uimap\n    (uimap\n     :a\n      (ui\n       :uid \"a\"\n       :selected true)\n     :b\n      (ui\n       :uid \"b\")))\n  2))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/ui/ui"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/ui/ui"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("ui<-ui-selected"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_ui_from_ui_selected");
    return output;
  }

  vx_test::Type_testcase f_ui_from_ui_visible(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_ui_from_ui_visible");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_ui_ui::t_ui,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":uimap"),
          vx_core::f_new(
            vx_ui_ui::t_uimap,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":a"),
              vx_core::f_new(
                vx_ui_ui::t_ui,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":uid"),
                  vx_core::vx_new_string("a"),
                  vx_core::vx_new_string(":hidden"),
                  vx_core::vx_new_boolean(true)
                })
              ),
              vx_core::vx_new_string(":b"),
              vx_core::f_new(
                vx_ui_ui::t_ui,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":uid"),
                  vx_core::vx_new_string("b")
                })
              )
            })
          )
        })
      ),
      vx_ui_ui::f_ui_from_ui_visible(
        vx_core::f_new(
          vx_ui_ui::t_ui,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":uimap"),
            vx_core::f_new(
              vx_ui_ui::t_uimap,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":a"),
                vx_core::f_new(
                  vx_ui_ui::t_ui,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":uid"),
                    vx_core::vx_new_string("a")
                  })
                ),
                vx_core::vx_new_string(":b"),
                vx_core::f_new(
                  vx_ui_ui::t_ui,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":uid"),
                    vx_core::vx_new_string("b"),
                    vx_core::vx_new_string(":hidden"),
                    vx_core::vx_new_boolean(true)
                  })
                )
              })
            )
          })
        ),
        vx_core::vx_new_int(2)
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (ui\n  :uimap\n   (uimap\n    :a\n     (ui\n      :uid \"a\"\n      :hidden true)\n    :b\n     (ui\n      :uid \"b\")))\n (ui<-ui-visible\n  (ui\n   :uimap\n    (uimap\n     :a\n      (ui\n       :uid \"a\")\n     :b\n      (ui\n       :uid \"b\"\n       :hidden true)))\n  2))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/ui/ui"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/ui/ui"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("ui<-ui-visible"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_ui_from_ui_visible");
    return output;
  }

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {
    vx_core::vx_Type_listany listtestcase;
    listtestcase.push_back(vx_ui_ui_test::f_boolean_writestate_from_uiapp(context));
    listtestcase.push_back(vx_ui_ui_test::f_string_parentuid_from_uid(context));
    listtestcase.push_back(vx_ui_ui_test::f_ui_readstate_uiapp(context));
    listtestcase.push_back(vx_ui_ui_test::f_ui_readstate_from_uid(context));
    listtestcase.push_back(vx_ui_ui_test::f_ui_from_ui_find(context));
    listtestcase.push_back(vx_ui_ui_test::f_ui_from_ui_selected(context));
    listtestcase.push_back(vx_ui_ui_test::f_ui_from_ui_visible(context));
    vx_test::Type_testcaselist output = vx_core::vx_any_from_any(
      vx_test::t_testcaselist,
      vx_test::t_testcaselist->vx_new_from_list(listtestcase)
    );
    return output;
  }

  vx_test::Type_testcoveragesummary test_coveragesummary() {
    vx_test::Type_testcoveragesummary output = vx_core::vx_new(vx_test::t_testcoveragesummary, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/ui/ui"),
      vx_core::vx_new_string(":constnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(41)
      }),
      vx_core::vx_new_string(":docnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(61), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(74), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(120)
      }),
      vx_core::vx_new_string(":funcnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(13), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(7), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(51)
      }),
      vx_core::vx_new_string(":bigospacenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(51)
      }),
      vx_core::vx_new_string(":bigotimenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(51)
      }),
      vx_core::vx_new_string(":totalnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(5), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(7), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(120)
      }),
      vx_core::vx_new_string(":typenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(28)
      })
    });
    return output;
  }

  vx_test::Type_testcoveragedetail test_coveragedetail() {
    vx_test::Type_testcoveragedetail output = vx_core::vx_new(vx_test::t_testcoveragedetail, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/ui/ui"),
      vx_core::vx_new_string(":typemap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":align"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":bounds"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":cursor"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":cursor-pointer"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":font"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":fontface"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":fontfacelist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":fontfacemap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":fontmap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":fontstyle"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":fontstylemap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":image"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layoutengine"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layoutlist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layoutmap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":pin"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":point"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":pointtype"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":style"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":stylelist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":stylemap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":stylesheet"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":styletype"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":ui"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":uiengine"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":uilist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":uimap"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":constmap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":align-center"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":align-left"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":align-right"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-app"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-background"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-button"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-combobox"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-else"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-flow-columns"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-flow-item"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-flow-rows"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-image"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-label"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-main"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-maxpanel"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-menubar"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-menudrawer"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-msgbox"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-navbar"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-navdrawer"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-panel"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-parallax"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-statusbar"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-statusdrawer"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-text"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-textentry"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-titlebar"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":pin-bottom"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":pin-center"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":pin-center-h"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":pin-center-v"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":pin-expand"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":pin-left"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":pin-right"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":pin-top"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":pointtype-absolute"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":pointtype-percent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":pointtype-relative"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":styletype-custom"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":styletype-shared"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":styletype-system"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":funcmap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":boolean-print"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":boolean-removestate-uiapp"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":boolean-writestate<-ui"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":boolean-writestate<-uiapp"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":boolean-writestate<-uiengine"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":fontfacemap<-fontfacelist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":int-selected<-ui"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":int-visible<-ui"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":intlist-visible<-ui"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout<-style"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout<-ui"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout<-ui-layoutengine"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout<-ui-layoutmap-else"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layoutengine-readstate"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layoutmap<-layoutlist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string-parentuid<-uid"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":string-selected<-ui"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":stringlist-selected<-ui"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":stringlist<-ui"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":stylemap<-stylelist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":stylesheet-readstate"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":stylesheet-render"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":ui-addlayout<-ui"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":ui-addlayout<-ui-layoutengine"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":ui-addlayout<-ui-layoutmap-else"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":ui-addlayout<-ui-uiengine"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":ui-child<-ui-uid"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":ui-from<-event"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":ui-layout"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":ui-layout<-fn-layout-ui-orig-parent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":ui-layout<-ui-orig-parent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":ui-layout<-ui-parent-selected"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":ui-layout<-ui-parent-visible"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":ui-readstate-uiapp"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":ui-readstate<-uid"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":ui-selected<-ui"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":ui-writechild<-ui-child"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":ui-writechildmap<-ui-childmap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":ui<-layout-ui-orig-parent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":ui<-ui-find"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":ui<-ui-selected"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":ui<-ui-visible"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":uid-selected<-ui"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":uiengine-readstate"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":uiengine-render"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":uilist-selected<-ui"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":uilist<-uimap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":uimap-addlayout<-uimap-layoutmap-else"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":uimap-layout<-uimap-parent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":uimap<-uilist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":uimap<-uimap-data"), vx_core::vx_new_int(0)
      })
    });
    return output;
  }

  vx_test::Type_testpackage test_package(vx_core::Type_context context) {
    vx_test::Type_testcaselist testcaselist = vx_ui_ui_test::test_cases(context);
    vx_test::Type_testcoveragesummary testcoveragesummary = vx_ui_ui_test::test_coveragesummary();
    vx_test::Type_testcoveragedetail testcoveragedetail = vx_ui_ui_test::test_coveragedetail();
    vx_test::Type_testpackage output = vx_core::vx_new(vx_test::t_testpackage, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/ui/ui"),
      vx_core::vx_new_string(":caselist"), testcaselist,
      vx_core::vx_new_string(":coveragesummary"), testcoveragesummary,
      vx_core::vx_new_string(":coveragedetail"), testcoveragedetail
    });
    return output;
  }

}
