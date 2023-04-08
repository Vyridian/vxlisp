
package com.vxlisp.vx;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;


public final class CollectionTest {

  static Test.Type_testcase f_list_from_list_end(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-list-end",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (stringlist \"a\" \"b\" \"c\")\n (list<-list-end\n  (stringlist \"a\" \"b\" \"c\" \"d\")\n  3))",
          ":testresult",
            Test.f_test(
              Core.f_new(
                Core.t_stringlist,
                Core.t_anylist.vx_new(
                  Core.t_string.vx_new_from_string("a"),
                  Core.t_string.vx_new_from_string("b"),
                  Core.t_string.vx_new_from_string("c")
                )
              ),
              Collection.f_list_from_list_end(
                Core.t_stringlist,
                Core.f_new(
                  Core.t_stringlist,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string("a"),
                    Core.t_string.vx_new_from_string("b"),
                    Core.t_string.vx_new_from_string("c"),
                    Core.t_string.vx_new_from_string("d")
                  )
                ),
                Core.t_int.vx_new_from_int(3)
              ),
              context
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_list_from_list_filtertypes(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-list-filtertypes",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (list \"a\" 1 \"b\" \"c\")\n (list<-list-filtertypes : list\n  (list \"a\" 1 \"b\" \"c\" 4.5)\n  string int))",
          ":testresult",
            Test.f_test(
              Core.f_new(
                Core.t_list,
                Core.t_anylist.vx_new(
                  Core.t_string.vx_new_from_string("a"),
                  Core.t_int.vx_new_from_int(1),
                  Core.t_string.vx_new_from_string("b"),
                  Core.t_string.vx_new_from_string("c")
                )
              ),
              Collection.f_list_from_list_filtertypes(
                Core.t_list,
                Core.f_new(
                  Core.t_list,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string("a"),
                    Core.t_int.vx_new_from_int(1),
                    Core.t_string.vx_new_from_string("b"),
                    Core.t_string.vx_new_from_string("c"),
                    Core.t_decimal.vx_new_from_string("4.5")
                  )
                ),
                Core.t_typelist.vx_new(
                  Core.t_string,
                  Core.t_int
                )
              ),
              context
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_list_from_list_fn_filter(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-list-fn-filter",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (stringlist \"a1\" \"b1\" \"c1\" \"d1\")\n (list<-list-fn-filter : stringlist\n  (list \"a\" 4 \"b\" (list) \"c\" (map) \"d\")\n  (fn : string\n   [val : any]\n   (if\n    (then\n     (is-string val)\n     (string val \"1\"))))))",
          ":testresult",
            Test.f_test(
              Core.f_new(
                Core.t_stringlist,
                Core.t_anylist.vx_new(
                  Core.t_string.vx_new_from_string("a1"),
                  Core.t_string.vx_new_from_string("b1"),
                  Core.t_string.vx_new_from_string("c1"),
                  Core.t_string.vx_new_from_string("d1")
                )
              ),
              Collection.f_list_from_list_fn_filter(
                Core.t_stringlist,
                Core.f_new(
                  Core.t_list,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string("a"),
                    Core.t_int.vx_new_from_int(4),
                    Core.t_string.vx_new_from_string("b"),
                    Core.f_empty(
                      Core.t_list
                    ),
                    Core.t_string.vx_new_from_string("c"),
                    Core.f_empty(
                      Core.t_map
                    ),
                    Core.t_string.vx_new_from_string("d")
                  )
                ),
                Core.t_any_from_any.fn_new((val_any) -> {
                  Core.Type_any val = Core.f_any_from_any(Core.t_any, val_any);
                  return 
                    Core.f_if_2(
                      Core.t_string,
                      Core.t_thenelselist.vx_new(
                        Core.f_then(
                          Core.t_boolean_from_func.fn_new(() -> {
                            return Type.f_is_string(val);
                          }),
                          Core.t_any_from_func.fn_new(() -> {
                            return Core.f_new(
                              Core.t_string,
                              Core.t_anylist.vx_new(
                                  val,
                                  Core.t_string.vx_new_from_string("1")
                              )
                            );
                          })
                        )
                      )
                    );
                })
              ),
              context
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_list_from_list_start(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-list-start",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (stringlist \"b\" \"c\" \"d\")\n (list<-list-start\n  (stringlist \"a\" \"b\" \"c\" \"d\")\n  1))",
          ":testresult",
            Test.f_test(
              Core.f_new(
                Core.t_stringlist,
                Core.t_anylist.vx_new(
                  Core.t_string.vx_new_from_string("b"),
                  Core.t_string.vx_new_from_string("c"),
                  Core.t_string.vx_new_from_string("d")
                )
              ),
              Collection.f_list_from_list_start(
                Core.t_stringlist,
                Core.f_new(
                  Core.t_stringlist,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string("a"),
                    Core.t_string.vx_new_from_string("b"),
                    Core.t_string.vx_new_from_string("c"),
                    Core.t_string.vx_new_from_string("d")
                  )
                ),
                Core.t_int.vx_new_from_int(1)
              ),
              context
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_list_from_list_start_end(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-list-start-end",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (stringlist \"b\" \"c\")\n (list<-list-start-end\n  (stringlist \"a\" \"b\" \"c\" \"d\")\n  1 3))",
          ":testresult",
            Test.f_test(
              Core.f_new(
                Core.t_stringlist,
                Core.t_anylist.vx_new(
                  Core.t_string.vx_new_from_string("b"),
                  Core.t_string.vx_new_from_string("c")
                )
              ),
              Collection.f_list_from_list_start_end(
                Core.t_stringlist,
                Core.f_new(
                  Core.t_stringlist,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string("a"),
                    Core.t_string.vx_new_from_string("b"),
                    Core.t_string.vx_new_from_string("c"),
                    Core.t_string.vx_new_from_string("d")
                  )
                ),
                Core.t_int.vx_new_from_int(1),
                Core.t_int.vx_new_from_int(3)
              ),
              context
            )
        )
      )
    );
    return output;
  }

  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(
      CollectionTest.f_list_from_list_end(context),
      CollectionTest.f_list_from_list_filtertypes(context),
      CollectionTest.f_list_from_list_fn_filter(context),
      CollectionTest.f_list_from_list_start(context),
      CollectionTest.f_list_from_list_start_end(context)
    ));
    Test.Type_testcaselist output = Test.t_testcaselist.vx_new(arraylisttestcase);
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    return Test.t_testcoveragesummary.vx_new(
      ":testpkg",   "vx/collection", 
      ":constnums", Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 7, ":total", 7), 
      ":funcnums", Test.t_testcoveragenums.vx_new(":pct", 71, ":tests", 5, ":total", 7), 
      ":ospacenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 7), 
      ":otimenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 7), 
      ":totalnums", Test.t_testcoveragenums.vx_new(":pct", 71, ":tests", 5, ":total", 7), 
      ":typenums", Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 0, ":total", 0)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Test.t_testcoveragedetail.vx_new(
      ":testpkg", "vx/collection",
      ":typemap", Core.t_intmap.vx_new(
  
      ),
      ":constmap", Core.t_intmap.vx_new(
  
      ),
      ":funcmap", Core.t_intmap.vx_new(
        ":is-list", 0,
        ":is-map", 0,
        ":list<-list-end", 1,
        ":list<-list-filtertypes", 1,
        ":list<-list-fn-filter", 1,
        ":list<-list-start", 1,
        ":list<-list-start-end", 1
      )
    );
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Test.t_testpackage.vx_new(
      ":testpkg", "vx/collection", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
