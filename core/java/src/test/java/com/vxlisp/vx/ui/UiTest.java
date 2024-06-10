
package com.vxlisp.vx.ui;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import com.vxlisp.vx.*;
import com.vxlisp.vx.data.*;

public final class UiTest {

  static Test.Type_testcase f_boolean_writestate_from_uiapp(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/ui/ui",
      ":casename", "boolean-writestate<-uiapp",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (ui :uid \"app\")\n (let : ui\n  [iswrite : boolean :=\n    (boolean-writestate<-uiapp\n     (ui :uid \"app\"))\n   appui : ui :=\n    (ui-readstate-uiapp)\n   isremoved : boolean :=\n    (boolean-removestate-uiapp)]\n  appui))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Ui.t_ui,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":uid"),
                  Core.vx_new_string("app")
                )
              ),
              Core.f_let(
                Ui.t_ui,
                Core.t_any_from_func.vx_fn_new(() -> {
                  final Core.Type_boolean iswrite = Ui.f_boolean_writestate_from_uiapp(
                    context,
                    Core.f_new(
                      Ui.t_ui,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string(":uid"),
                        Core.vx_new_string("app")
                      )
                    )
                  );
                  final Ui.Type_ui appui = Ui.f_ui_readstate_uiapp(context);
                  final Core.Type_boolean isremoved = Ui.f_boolean_removestate_uiapp(context);
                  return appui;
                })
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_string_parentuid_from_uid(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/ui/ui",
      ":casename", "string-parentuid<-uid",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n \"\"\n (string-parentuid<-uid\n  \"a\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string(""),
              Ui.f_string_parentuid_from_uid(Core.vx_new_string("a"))
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n \"a/b\"\n (string-parentuid<-uid\n  \"a/b/c\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("a/b"),
              Ui.f_string_parentuid_from_uid(Core.vx_new_string("a/b/c"))
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_ui_readstate_uiapp(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/ui/ui",
      ":casename", "ui-readstate-uiapp",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (ui\n  :uid \"myapp\")\n (let : ui\n  [iswrite : boolean :=\n    (boolean-writestate<-uiapp\n     (ui\n      :uid \"myapp\"))]\n  (ui-readstate-uiapp)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Ui.t_ui,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":uid"),
                  Core.vx_new_string("myapp")
                )
              ),
              Core.f_let(
                Ui.t_ui,
                Core.t_any_from_func.vx_fn_new(() -> {
                  final Core.Type_boolean iswrite = Ui.f_boolean_writestate_from_uiapp(
                    context,
                    Core.f_new(
                      Ui.t_ui,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string(":uid"),
                        Core.vx_new_string("myapp")
                      )
                    )
                  );
                  return Ui.f_ui_readstate_uiapp(context);
                })
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_ui_readstate_from_uid(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/ui/ui",
      ":casename", "ui-readstate<-uid",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (ui\n  :uid \"a/b/c\")\n (let : ui\n  [uiapp : ui :=\n    (ui\n     :uid \"a\"\n     :uimap\n      (uimap<-uilist\n       (ui\n        :uid \"a/b\"\n        :uimap\n         (uimap<-uilist\n          (ui\n           :uid \"a/b/c\")))))\n   iswrite : boolean :=\n    (boolean-writestate<-uiapp uiapp)\n   readval : ui :=\n    (ui-readstate<-uid\n     \"a/b/c\")\n   isremoved : boolean := (boolean-removestate-uiapp)]\n  readval))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Ui.t_ui,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":uid"),
                  Core.vx_new_string("a/b/c")
                )
              ),
              Core.f_let(
                Ui.t_ui,
                Core.t_any_from_func.vx_fn_new(() -> {
                  final Ui.Type_ui uiapp = Core.f_new(
                    Ui.t_ui,
                    Core.t_anylist.vx_new(
                        Core.vx_new_string(":uid"),
                        Core.vx_new_string("a"),
                        Core.vx_new_string(":uimap"),
                        Ui.f_uimap_from_uilist(
                          Ui.t_uilist.vx_new(
                            Core.f_new(
                              Ui.t_ui,
                              Core.t_anylist.vx_new(
                                Core.vx_new_string(":uid"),
                                Core.vx_new_string("a/b"),
                                Core.vx_new_string(":uimap"),
                                Ui.f_uimap_from_uilist(
                                  Ui.t_uilist.vx_new(
                                    Core.f_new(
                                      Ui.t_ui,
                                      Core.t_anylist.vx_new(
                                        Core.vx_new_string(":uid"),
                                        Core.vx_new_string("a/b/c")
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
                  final Core.Type_boolean iswrite = Ui.f_boolean_writestate_from_uiapp(context, uiapp);
                  final Ui.Type_ui readval = Ui.f_ui_readstate_from_uid(context, Core.vx_new_string("a/b/c"));
                  final Core.Type_boolean isremoved = Ui.f_boolean_removestate_uiapp(context);
                  return readval;
                })
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_ui_write_from_ui_visible(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/ui/ui",
      ":casename", "ui-write<-ui-visible",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (ui\n  :uimap\n   (uimap\n    :a\n     (ui\n      :uid \"a\"\n      :hidden true)\n    :b\n     (ui\n      :uid \"b\")))\n (ui-write<-ui-visible\n  (ui\n   :uimap\n    (uimap\n     :a\n      (ui\n       :uid \"a\")\n     :b\n      (ui\n       :uid \"b\"\n       :hidden true)))\n  2))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Ui.t_ui,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":uimap"),
                  Core.f_new(
                    Ui.t_uimap,
                    Core.t_anylist.vx_new(
                      Core.vx_new_string(":a"),
                      Core.f_new(
                        Ui.t_ui,
                        Core.t_anylist.vx_new(
                          Core.vx_new_string(":uid"),
                          Core.vx_new_string("a"),
                          Core.vx_new_string(":hidden"),
                          Core.vx_new_boolean(true)
                        )
                      ),
                      Core.vx_new_string(":b"),
                      Core.f_new(
                        Ui.t_ui,
                        Core.t_anylist.vx_new(
                          Core.vx_new_string(":uid"),
                          Core.vx_new_string("b")
                        )
                      )
                    )
                  )
                )
              ),
              Ui.f_ui_write_from_ui_visible(
                Core.f_new(
                  Ui.t_ui,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":uimap"),
                    Core.f_new(
                      Ui.t_uimap,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string(":a"),
                        Core.f_new(
                          Ui.t_ui,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":uid"),
                            Core.vx_new_string("a")
                          )
                        ),
                        Core.vx_new_string(":b"),
                        Core.f_new(
                          Ui.t_ui,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":uid"),
                            Core.vx_new_string("b"),
                            Core.vx_new_string(":hidden"),
                            Core.vx_new_boolean(true)
                          )
                        )
                      )
                    )
                  )
                ),
                Core.vx_new_int(2)
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_ui_from_ui_find(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/ui/ui",
      ":casename", "ui<-ui-find",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (ui\n  :uid \"a/b/c\")\n (ui<-ui-find\n  (ui\n   :uid \"a\"\n   :uimap\n    (uimap\n     :a/b\n      (ui\n       :uid \"a/b\"\n       :uimap\n        (uimap\n         :a/b/c\n          (ui\n           :uid \"a/b/c\")))))\n  \"a/b/c\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Ui.t_ui,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":uid"),
                  Core.vx_new_string("a/b/c")
                )
              ),
              Ui.f_ui_from_ui_find(
                Core.f_new(
                  Ui.t_ui,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":uid"),
                    Core.vx_new_string("a"),
                    Core.vx_new_string(":uimap"),
                    Core.f_new(
                      Ui.t_uimap,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string(":a/b"),
                        Core.f_new(
                          Ui.t_ui,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":uid"),
                            Core.vx_new_string("a/b"),
                            Core.vx_new_string(":uimap"),
                            Core.f_new(
                              Ui.t_uimap,
                              Core.t_anylist.vx_new(
                                Core.vx_new_string(":a/b/c"),
                                Core.f_new(
                                  Ui.t_ui,
                                  Core.t_anylist.vx_new(
                                    Core.vx_new_string(":uid"),
                                    Core.vx_new_string("a/b/c")
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
                Core.vx_new_string("a/b/c")
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_ui_from_ui_selected(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/ui/ui",
      ":casename", "ui<-ui-selected",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (ui\n  :uimap\n   (uimap\n    :a\n     (ui\n      :uid \"a\")\n    :b\n     (ui\n      :uid \"b\"\n      :selected true)))\n (ui<-ui-selected\n  (ui\n   :uimap\n    (uimap\n     :a\n      (ui\n       :uid \"a\"\n       :selected true)\n     :b\n      (ui\n       :uid \"b\")))\n  2))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Ui.t_ui,
                Core.t_anylist.vx_new(
                  Core.vx_new_string(":uimap"),
                  Core.f_new(
                    Ui.t_uimap,
                    Core.t_anylist.vx_new(
                      Core.vx_new_string(":a"),
                      Core.f_new(
                        Ui.t_ui,
                        Core.t_anylist.vx_new(
                          Core.vx_new_string(":uid"),
                          Core.vx_new_string("a")
                        )
                      ),
                      Core.vx_new_string(":b"),
                      Core.f_new(
                        Ui.t_ui,
                        Core.t_anylist.vx_new(
                          Core.vx_new_string(":uid"),
                          Core.vx_new_string("b"),
                          Core.vx_new_string(":selected"),
                          Core.vx_new_boolean(true)
                        )
                      )
                    )
                  )
                )
              ),
              Ui.f_ui_from_ui_selected(
                Core.f_new(
                  Ui.t_ui,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":uimap"),
                    Core.f_new(
                      Ui.t_uimap,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string(":a"),
                        Core.f_new(
                          Ui.t_ui,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":uid"),
                            Core.vx_new_string("a"),
                            Core.vx_new_string(":selected"),
                            Core.vx_new_boolean(true)
                          )
                        ),
                        Core.vx_new_string(":b"),
                        Core.f_new(
                          Ui.t_ui,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":uid"),
                            Core.vx_new_string("b")
                          )
                        )
                      )
                    )
                  )
                ),
                Core.vx_new_int(2)
              )
            )
        )
      )
    );
    return output;
  }

  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(
      UiTest.f_boolean_writestate_from_uiapp(context),
      UiTest.f_string_parentuid_from_uid(context),
      UiTest.f_ui_readstate_uiapp(context),
      UiTest.f_ui_readstate_from_uid(context),
      UiTest.f_ui_write_from_ui_visible(context),
      UiTest.f_ui_from_ui_find(context),
      UiTest.f_ui_from_ui_selected(context)
    ));
    Test.Type_testcaselist output = Test.t_testcaselist.vx_new(arraylisttestcase);
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    return Test.t_testcoveragesummary.vx_new(
      ":testpkg",   "vx/ui/ui", 
      ":constnums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 41), 
      ":docnums", Test.t_testcoveragenums.vx_new(":pct", 66, ":tests", 91, ":total", 137), 
      ":funcnums", Test.t_testcoveragenums.vx_new(":pct", 10, ":tests", 7, ":total", 68), 
      ":bigospacenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 68), 
      ":bigotimenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 68), 
      ":totalnums", Test.t_testcoveragenums.vx_new(":pct", 5, ":tests", 7, ":total", 137), 
      ":typenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 28)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Test.t_testcoveragedetail.vx_new(
      ":testpkg", "vx/ui/ui",
      ":typemap", Core.t_intmap.vx_new(
        ":align", 0,
        ":bounds", 0,
        ":cursor", 0,
        ":cursor-pointer", 0,
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
      ":constmap", Core.t_intmap.vx_new(
        ":align-center", 0,
        ":align-left", 0,
        ":align-right", 0,
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
        ":pointtype-absolute", 0,
        ":pointtype-percent", 0,
        ":pointtype-relative", 0,
        ":styletype-custom", 0,
        ":styletype-shared", 0,
        ":styletype-system", 0
      ),
      ":funcmap", Core.t_intmap.vx_new(
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
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Test.t_testpackage.vx_new(
      ":testpkg", "vx/ui/ui", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
