
namespace AppTest.TestVx.Ui;

public class UiTest {

  public static Vx.Test.Type_testcase f_boolean_writestate_from_uiapp(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/ui/ui",
      ":casename", "boolean-writestate<-uiapp",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n (ui :uid \"app\")\n (let : ui\n  [iswrite : boolean :=\n    (boolean-writestate<-uiapp\n     (ui :uid \"app\"))\n   appui : ui :=\n    (ui-readstate-uiapp)\n   isremoved : boolean :=\n    (boolean-removestate-uiapp)]\n  appui))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.f_new(
                Vx.Ui.Ui.t_ui,
                Vx.Core.vx_new(
                  Vx.Core.t_anylist,
                  Vx.Core.vx_new_string(":uid"),
                  Vx.Core.vx_new_string("app")
                )
              ),
              Vx.Core.f_let(
                Vx.Ui.Ui.t_ui,
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  Vx.Core.Type_boolean iswrite = Vx.Ui.Ui.f_boolean_writestate_from_uiapp(
                    context,
                    Vx.Core.f_new(
                      Vx.Ui.Ui.t_ui,
                      Vx.Core.vx_new(
                        Vx.Core.t_anylist,
                        Vx.Core.vx_new_string(":uid"),
                        Vx.Core.vx_new_string("app")
                      )
                    )
                  );
                  Vx.Ui.Ui.Type_ui appui = Vx.Ui.Ui.f_ui_readstate_uiapp(
                    context
                  );
                  Vx.Core.Type_boolean isremoved = Vx.Ui.Ui.f_boolean_removestate_uiapp(
                    context
                  );
                  Vx.Core.Type_any output_1 = appui;
                  return output_1;
                })
              )
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_string_parentuid_from_uid(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/ui/ui",
      ":casename", "string-parentuid<-uid",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"\"\n (string-parentuid<-uid\n  \"a\"))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string(""),
              Vx.Ui.Ui.f_string_parentuid_from_uid(
                Vx.Core.vx_new_string("a")
              )
            )
        ),
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"a/b\"\n (string-parentuid<-uid\n  \"a/b/c\"))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("a/b"),
              Vx.Ui.Ui.f_string_parentuid_from_uid(
                Vx.Core.vx_new_string("a/b/c")
              )
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_ui_readstate_uiapp(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/ui/ui",
      ":casename", "ui-readstate-uiapp",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n (ui\n  :uid \"myapp\")\n (let : ui\n  [iswrite : boolean :=\n    (boolean-writestate<-uiapp\n     (ui\n      :uid \"myapp\"))]\n  (ui-readstate-uiapp)))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.f_new(
                Vx.Ui.Ui.t_ui,
                Vx.Core.vx_new(
                  Vx.Core.t_anylist,
                  Vx.Core.vx_new_string(":uid"),
                  Vx.Core.vx_new_string("myapp")
                )
              ),
              Vx.Core.f_let(
                Vx.Ui.Ui.t_ui,
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  Vx.Core.Type_boolean iswrite = Vx.Ui.Ui.f_boolean_writestate_from_uiapp(
                    context,
                    Vx.Core.f_new(
                      Vx.Ui.Ui.t_ui,
                      Vx.Core.vx_new(
                        Vx.Core.t_anylist,
                        Vx.Core.vx_new_string(":uid"),
                        Vx.Core.vx_new_string("myapp")
                      )
                    )
                  );
                  Vx.Core.Type_any output_1 = Vx.Ui.Ui.f_ui_readstate_uiapp(
                    context
                  );
                  return output_1;
                })
              )
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_ui_readstate_from_uid(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/ui/ui",
      ":casename", "ui-readstate<-uid",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n (ui\n  :uid \"a/b/c\")\n (let : ui\n  [uiapp : ui :=\n    (ui\n     :uid \"a\"\n     :uimap\n      (uimap<-uilist\n       (ui\n        :uid \"a/b\"\n        :uimap\n         (uimap<-uilist\n          (ui\n           :uid \"a/b/c\")))))\n   iswrite : boolean :=\n    (boolean-writestate<-uiapp uiapp)\n   readval : ui :=\n    (ui-readstate<-uid\n     \"a/b/c\")\n   isremoved : boolean := (boolean-removestate-uiapp)]\n  readval))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.f_new(
                Vx.Ui.Ui.t_ui,
                Vx.Core.vx_new(
                  Vx.Core.t_anylist,
                  Vx.Core.vx_new_string(":uid"),
                  Vx.Core.vx_new_string("a/b/c")
                )
              ),
              Vx.Core.f_let(
                Vx.Ui.Ui.t_ui,
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  Vx.Ui.Ui.Type_ui uiapp = Vx.Core.f_new(
                    Vx.Ui.Ui.t_ui,
                    Vx.Core.vx_new(
                      Vx.Core.t_anylist,
                      Vx.Core.vx_new_string(":uid"),
                      Vx.Core.vx_new_string("a"),
                      Vx.Core.vx_new_string(":uimap"),
                      Vx.Ui.Ui.f_uimap_from_uilist(
                        Vx.Core.vx_new(
                          Vx.Ui.Ui.t_uilist,
                          Vx.Core.f_new(
                            Vx.Ui.Ui.t_ui,
                            Vx.Core.vx_new(
                              Vx.Core.t_anylist,
                              Vx.Core.vx_new_string(":uid"),
                              Vx.Core.vx_new_string("a/b"),
                              Vx.Core.vx_new_string(":uimap"),
                              Vx.Ui.Ui.f_uimap_from_uilist(
                                Vx.Core.vx_new(
                                  Vx.Ui.Ui.t_uilist,
                                  Vx.Core.f_new(
                                    Vx.Ui.Ui.t_ui,
                                    Vx.Core.vx_new(
                                      Vx.Core.t_anylist,
                                      Vx.Core.vx_new_string(":uid"),
                                      Vx.Core.vx_new_string("a/b/c")
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
                  Vx.Core.Type_boolean iswrite = Vx.Ui.Ui.f_boolean_writestate_from_uiapp(
                    context,
                    uiapp
                  );
                  Vx.Ui.Ui.Type_ui readval = Vx.Ui.Ui.f_ui_readstate_from_uid(
                    context,
                    Vx.Core.vx_new_string("a/b/c")
                  );
                  Vx.Core.Type_boolean isremoved = Vx.Ui.Ui.f_boolean_removestate_uiapp(
                    context
                  );
                  Vx.Core.Type_any output_1 = readval;
                  return output_1;
                })
              )
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_ui_write_from_ui_visible(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/ui/ui",
      ":casename", "ui-write<-ui-visible",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n (ui\n  :uimap\n   (uimap\n    :a\n     (ui\n      :uid \"a\"\n      :hidden true)\n    :b\n     (ui\n      :uid \"b\")))\n (ui-write<-ui-visible\n  (ui\n   :uimap\n    (uimap\n     :a\n      (ui\n       :uid \"a\")\n     :b\n      (ui\n       :uid \"b\"\n       :hidden true)))\n  2))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.f_new(
                Vx.Ui.Ui.t_ui,
                Vx.Core.vx_new(
                  Vx.Core.t_anylist,
                  Vx.Core.vx_new_string(":uimap"),
                  Vx.Core.f_new(
                    Vx.Ui.Ui.t_uimap,
                    Vx.Core.vx_new(
                      Vx.Core.t_anylist,
                      Vx.Core.vx_new_string(":a"),
                      Vx.Core.f_new(
                        Vx.Ui.Ui.t_ui,
                        Vx.Core.vx_new(
                          Vx.Core.t_anylist,
                          Vx.Core.vx_new_string(":uid"),
                          Vx.Core.vx_new_string("a"),
                          Vx.Core.vx_new_string(":hidden"),
                          Vx.Core.vx_new_boolean(true)
                        )
                      ),
                      Vx.Core.vx_new_string(":b"),
                      Vx.Core.f_new(
                        Vx.Ui.Ui.t_ui,
                        Vx.Core.vx_new(
                          Vx.Core.t_anylist,
                          Vx.Core.vx_new_string(":uid"),
                          Vx.Core.vx_new_string("b")
                        )
                      )
                    )
                  )
                )
              ),
              Vx.Ui.Ui.f_ui_write_from_ui_visible(
                Vx.Core.f_new(
                  Vx.Ui.Ui.t_ui,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":uimap"),
                    Vx.Core.f_new(
                      Vx.Ui.Ui.t_uimap,
                      Vx.Core.vx_new(
                        Vx.Core.t_anylist,
                        Vx.Core.vx_new_string(":a"),
                        Vx.Core.f_new(
                          Vx.Ui.Ui.t_ui,
                          Vx.Core.vx_new(
                            Vx.Core.t_anylist,
                            Vx.Core.vx_new_string(":uid"),
                            Vx.Core.vx_new_string("a")
                          )
                        ),
                        Vx.Core.vx_new_string(":b"),
                        Vx.Core.f_new(
                          Vx.Ui.Ui.t_ui,
                          Vx.Core.vx_new(
                            Vx.Core.t_anylist,
                            Vx.Core.vx_new_string(":uid"),
                            Vx.Core.vx_new_string("b"),
                            Vx.Core.vx_new_string(":hidden"),
                            Vx.Core.vx_new_boolean(true)
                          )
                        )
                      )
                    )
                  )
                ),
                Vx.Core.vx_new_int(2)
              )
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_ui_from_ui_find(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/ui/ui",
      ":casename", "ui<-ui-find",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n (ui\n  :uid \"a/b/c\")\n (ui<-ui-find\n  (ui\n   :uid \"a\"\n   :uimap\n    (uimap\n     :a/b\n      (ui\n       :uid \"a/b\"\n       :uimap\n        (uimap\n         :a/b/c\n          (ui\n           :uid \"a/b/c\")))))\n  \"a/b/c\"))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.f_new(
                Vx.Ui.Ui.t_ui,
                Vx.Core.vx_new(
                  Vx.Core.t_anylist,
                  Vx.Core.vx_new_string(":uid"),
                  Vx.Core.vx_new_string("a/b/c")
                )
              ),
              Vx.Ui.Ui.f_ui_from_ui_find(
                Vx.Core.f_new(
                  Vx.Ui.Ui.t_ui,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":uid"),
                    Vx.Core.vx_new_string("a"),
                    Vx.Core.vx_new_string(":uimap"),
                    Vx.Core.f_new(
                      Vx.Ui.Ui.t_uimap,
                      Vx.Core.vx_new(
                        Vx.Core.t_anylist,
                        Vx.Core.vx_new_string(":a/b"),
                        Vx.Core.f_new(
                          Vx.Ui.Ui.t_ui,
                          Vx.Core.vx_new(
                            Vx.Core.t_anylist,
                            Vx.Core.vx_new_string(":uid"),
                            Vx.Core.vx_new_string("a/b"),
                            Vx.Core.vx_new_string(":uimap"),
                            Vx.Core.f_new(
                              Vx.Ui.Ui.t_uimap,
                              Vx.Core.vx_new(
                                Vx.Core.t_anylist,
                                Vx.Core.vx_new_string(":a/b/c"),
                                Vx.Core.f_new(
                                  Vx.Ui.Ui.t_ui,
                                  Vx.Core.vx_new(
                                    Vx.Core.t_anylist,
                                    Vx.Core.vx_new_string(":uid"),
                                    Vx.Core.vx_new_string("a/b/c")
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
                Vx.Core.vx_new_string("a/b/c")
              )
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_ui_from_ui_selected(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/ui/ui",
      ":casename", "ui<-ui-selected",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n (ui\n  :uimap\n   (uimap\n    :a\n     (ui\n      :uid \"a\")\n    :b\n     (ui\n      :uid \"b\"\n      :selected true)))\n (ui<-ui-selected\n  (ui\n   :uimap\n    (uimap\n     :a\n      (ui\n       :uid \"a\"\n       :selected true)\n     :b\n      (ui\n       :uid \"b\")))\n  2))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.f_new(
                Vx.Ui.Ui.t_ui,
                Vx.Core.vx_new(
                  Vx.Core.t_anylist,
                  Vx.Core.vx_new_string(":uimap"),
                  Vx.Core.f_new(
                    Vx.Ui.Ui.t_uimap,
                    Vx.Core.vx_new(
                      Vx.Core.t_anylist,
                      Vx.Core.vx_new_string(":a"),
                      Vx.Core.f_new(
                        Vx.Ui.Ui.t_ui,
                        Vx.Core.vx_new(
                          Vx.Core.t_anylist,
                          Vx.Core.vx_new_string(":uid"),
                          Vx.Core.vx_new_string("a")
                        )
                      ),
                      Vx.Core.vx_new_string(":b"),
                      Vx.Core.f_new(
                        Vx.Ui.Ui.t_ui,
                        Vx.Core.vx_new(
                          Vx.Core.t_anylist,
                          Vx.Core.vx_new_string(":uid"),
                          Vx.Core.vx_new_string("b"),
                          Vx.Core.vx_new_string(":selected"),
                          Vx.Core.vx_new_boolean(true)
                        )
                      )
                    )
                  )
                )
              ),
              Vx.Ui.Ui.f_ui_from_ui_selected(
                Vx.Core.f_new(
                  Vx.Ui.Ui.t_ui,
                  Vx.Core.vx_new(
                    Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":uimap"),
                    Vx.Core.f_new(
                      Vx.Ui.Ui.t_uimap,
                      Vx.Core.vx_new(
                        Vx.Core.t_anylist,
                        Vx.Core.vx_new_string(":a"),
                        Vx.Core.f_new(
                          Vx.Ui.Ui.t_ui,
                          Vx.Core.vx_new(
                            Vx.Core.t_anylist,
                            Vx.Core.vx_new_string(":uid"),
                            Vx.Core.vx_new_string("a"),
                            Vx.Core.vx_new_string(":selected"),
                            Vx.Core.vx_new_boolean(true)
                          )
                        ),
                        Vx.Core.vx_new_string(":b"),
                        Vx.Core.f_new(
                          Vx.Ui.Ui.t_ui,
                          Vx.Core.vx_new(
                            Vx.Core.t_anylist,
                            Vx.Core.vx_new_string(":uid"),
                            Vx.Core.vx_new_string("b")
                          )
                        )
                      )
                    )
                  )
                ),
                Vx.Core.vx_new_int(2)
              )
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcaselist test_cases(Vx.Core.Type_context context) {
    object[] testcases = [
      UiTest.f_boolean_writestate_from_uiapp(context),
      UiTest.f_string_parentuid_from_uid(context),
      UiTest.f_ui_readstate_uiapp(context),
      UiTest.f_ui_readstate_from_uid(context),
      UiTest.f_ui_write_from_ui_visible(context),
      UiTest.f_ui_from_ui_find(context),
      UiTest.f_ui_from_ui_selected(context)
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
      ":testpkg", "vx/ui/ui", 
      ":constnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 47), 
      ":docnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 65, ":tests", 95, ":total", 144), 
      ":funcnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 10, ":tests", 7, ":total", 68), 
      ":bigospacenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 68), 
      ":bigotimenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 68), 
      ":totalnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 4, ":tests", 7, ":total", 144), 
      ":typenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 29)
    );
    return output;
  }

  public static Vx.Test.Type_testcoveragedetail test_coveragedetail() {
    Vx.Test.Type_testcoveragedetail output = Vx.Core.vx_new(
      Vx.Test.t_testcoveragedetail,
      ":testpkg", "vx/ui/ui",
      ":typemap", Vx.Core.vx_new(
        Vx.Core.t_intmap,
        ":align", 0,
        ":bounds", 0,
        ":cursor", 0,
        ":cursor-pointer", 0,
        ":flip", 0,
        ":font", 0,
        ":fontface", 0,
        ":fontfacelist", 0,
        ":fontfacemap", 0,
        ":fontmap", 0,
        ":fontstyle", 0,
        ":fontstylemap", 0,
        ":image", 0,
        ":layout", 0,
        ":layoutengine", 0,
        ":layoutlist", 0,
        ":layoutmap", 0,
        ":pin", 0,
        ":point", 0,
        ":pointtype", 0,
        ":style", 0,
        ":stylelist", 0,
        ":stylemap", 0,
        ":stylesheet", 0,
        ":styletype", 0,
        ":ui", 0,
        ":uiengine", 0,
        ":uilist", 0,
        ":uimap", 0
      ), 
      ":constmap", Vx.Core.vx_new(
        Vx.Core.t_intmap,
        ":align-center", 0,
        ":align-left", 0,
        ":align-right", 0,
        ":flip-x", 0,
        ":flip-xy", 0,
        ":flip-y", 0,
        ":layout-app", 0,
        ":layout-background", 0,
        ":layout-button", 0,
        ":layout-combobox", 0,
        ":layout-else", 0,
        ":layout-flow-columns", 0,
        ":layout-flow-item", 0,
        ":layout-flow-rows", 0,
        ":layout-image", 0,
        ":layout-label", 0,
        ":layout-main", 0,
        ":layout-maxpanel", 0,
        ":layout-menubar", 0,
        ":layout-menudrawer", 0,
        ":layout-msgbox", 0,
        ":layout-navbar", 0,
        ":layout-navdrawer", 0,
        ":layout-panel", 0,
        ":layout-parallax", 0,
        ":layout-statusbar", 0,
        ":layout-statusdrawer", 0,
        ":layout-text", 0,
        ":layout-textentry", 0,
        ":layout-titlebar", 0,
        ":pin-bottom", 0,
        ":pin-center", 0,
        ":pin-center-h", 0,
        ":pin-center-v", 0,
        ":pin-expand", 0,
        ":pin-left", 0,
        ":pin-right", 0,
        ":pin-top", 0,
        ":point-center", 0,
        ":point-lefttop", 0,
        ":point-rightbottom", 0,
        ":pointtype-absolute", 0,
        ":pointtype-percent", 0,
        ":pointtype-relative", 0,
        ":styletype-custom", 0,
        ":styletype-shared", 0,
        ":styletype-system", 0
      ), 
      ":funcmap", Vx.Core.vx_new(
        Vx.Core.t_intmap,
        ":boolean-layout<-ui-parent-selected", 0,
        ":boolean-layout<-ui-parent-visible", 0,
        ":boolean-layoutaddchild<-ui-parent", 0,
        ":boolean-layoutremove<-ui", 0,
        ":boolean-layoutremove<-ui-keys", 0,
        ":boolean-layoutremove<-ui-parent", 0,
        ":boolean-layoutremove<-ui-start-end", 0,
        ":boolean-layoutselected<-ui", 0,
        ":boolean-layoutselected<-ui-parent", 0,
        ":boolean-layoutselected<-ui-selected", 0,
        ":boolean-layoutvisible<-ui", 0,
        ":boolean-print", 0,
        ":boolean-removestate-uiapp", 0,
        ":boolean-write<-ui-parent", 0,
        ":boolean-writeremove<-ui-uid", 0,
        ":boolean-writestate<-ui", 0,
        ":boolean-writestate<-uiapp", 1,
        ":boolean-writestate<-uiengine", 0,
        ":fontfacemap<-fontfacelist", 0,
        ":int-child<-ui-uid", 0,
        ":int-selected<-ui", 0,
        ":int-visible<-ui", 0,
        ":intlist-visible<-ui", 0,
        ":layout<-style", 0,
        ":layout<-ui", 0,
        ":layout<-ui-layoutengine", 0,
        ":layout<-ui-layoutmap-else", 0,
        ":layoutengine-readstate", 0,
        ":layoutmap<-layoutlist", 0,
        ":string-parentuid<-uid", 2,
        ":string-selected<-ui", 0,
        ":stringlist-selected<-ui", 0,
        ":stringlist<-ui", 0,
        ":stylemap<-stylelist", 0,
        ":stylesheet-readstate", 0,
        ":stylesheet-render", 0,
        ":ui-addlayout<-ui", 0,
        ":ui-addlayout<-ui-layoutengine", 0,
        ":ui-addlayout<-ui-layoutmap-else", 0,
        ":ui-addlayout<-ui-uiengine", 0,
        ":ui-child<-ui-pos", 0,
        ":ui-child<-ui-uid", 0,
        ":ui-from<-event", 0,
        ":ui-layout", 0,
        ":ui-layout<-fn-layout-ui-orig-parent", 0,
        ":ui-layout<-ui-orig-parent", 0,
        ":ui-layout<-ui-parent-selected", 0,
        ":ui-layout<-ui-parent-visible", 0,
        ":ui-readstate-uiapp", 1,
        ":ui-readstate<-uid", 1,
        ":ui-selected<-ui", 0,
        ":ui-visible<-ui", 0,
        ":ui-write<-ui-child", 0,
        ":ui-write<-ui-childmap", 0,
        ":ui-write<-ui-visible", 1,
        ":ui<-layout-ui-orig-parent", 0,
        ":ui<-ui-find", 1,
        ":ui<-ui-selected", 1,
        ":uid-selected<-ui", 0,
        ":uiengine-readstate", 0,
        ":uiengine-render", 0,
        ":uilist-selected<-ui", 0,
        ":uilist-visible<-ui", 0,
        ":uilist<-uimap", 0,
        ":uimap-addlayout<-uimap-layoutmap-else", 0,
        ":uimap-layout<-uimap-parent", 0,
        ":uimap<-uilist", 0,
        ":uimap<-uimap-data", 0
      )
    );
    return output;
  }

  public static Vx.Test.Type_testpackage test_package(Vx.Core.Type_context context) {
    Vx.Test.Type_testcaselist testcaselist = test_cases(context);
    Vx.Test.Type_testpackage output = Vx.Core.vx_new(
      Vx.Test.t_testpackage,
      ":testpkg", "vx/ui/ui", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
