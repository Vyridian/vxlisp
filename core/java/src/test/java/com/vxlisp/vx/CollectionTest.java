
package com.vxlisp.vx;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;

public final class CollectionTest {

  static Test.Type_testcase f_any_from_for_until_loop(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "any<-for-until-loop",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n 8\n (any<-for-until-loop\n  1\n  (fn : boolean\n   [current : int]\n   (> current 6))\n  (fn : int\n   [current : int]\n   (+ current current))))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_int(8),
              Collection.f_any_from_for_until_loop(
                Core.t_int,
                Core.vx_new_int(1),
                Core.t_boolean_from_any.vx_fn_new((current_any) -> {
                  Core.Type_int current = Core.f_any_from_any(Core.t_int, current_any);
                  return 
                  Core.f_gt(current, Core.vx_new_int(6));
                }),
                Core.t_any_from_any.vx_fn_new((current_any) -> {
                  Core.Type_int current = Core.f_any_from_any(Core.t_int, current_any);
                  return 
                  Core.f_plus(current, current);
                })
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_any_from_for_while_loop(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "any<-for-while-loop",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n 8\n (any<-for-while-loop\n  1\n  (fn : boolean\n   [current : int]\n   (< current 5))\n  (fn : int\n   [current : int]\n   (+ current current))))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_int(8),
              Collection.f_any_from_for_while_loop(
                Core.t_int,
                Core.vx_new_int(1),
                Core.t_boolean_from_any.vx_fn_new((current_any) -> {
                  Core.Type_int current = Core.f_any_from_any(Core.t_int, current_any);
                  return 
                  Core.f_lt(current, Core.vx_new_int(5));
                }),
                Core.t_any_from_any.vx_fn_new((current_any) -> {
                  Core.Type_int current = Core.f_any_from_any(Core.t_int, current_any);
                  return 
                  Core.f_plus(current, current);
                })
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_int_from_map_key(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "int<-map-key",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n 2\n (int<-map-key\n  (stringmap\n   :a \"x\"\n   :b \"y\")\n  \"b\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_int(2),
              Collection.f_int_from_map_key(
                Core.f_new(
                  Core.t_stringmap,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":a"),
                    Core.vx_new_string("x"),
                    Core.vx_new_string(":b"),
                    Core.vx_new_string("y")
                  )
                ),
                Core.vx_new_string("b")
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_int_from_stringlist_find(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "int<-stringlist-find",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n 2\n (int<-stringlist-find\n  (stringlist \"a\" \"b\")\n  \"b\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_int(2),
              Collection.f_int_from_stringlist_find(
                Core.f_new(
                  Core.t_stringlist,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string("a"),
                    Core.vx_new_string("b")
                  )
                ),
                Core.vx_new_string("b")
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_is_list(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "is-list",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test-true\n (is-list (empty stringlist)))",
          ":testresult",
            Test.f_test_true(
              context,
              Collection.f_is_list(
                Core.f_empty(
                  Core.t_stringlist
                )
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_is_map(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "is-map",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test-true\n (is-map (empty stringmap)))",
          ":testresult",
            Test.f_test_true(
              context,
              Collection.f_is_map(
                Core.f_empty(
                  Core.t_stringmap
                )
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_list_from_for_end_loop(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-for-end-loop",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (intlist 4 9)\n (list<-for-end-loop : intlist\n  2\n  3\n  (fn\n   [current : int]\n   (* current current))))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Core.t_intlist,
                Core.t_anylist.vx_new(
                  Core.vx_new_int(4),
                  Core.vx_new_int(9)
                )
              ),
              Collection.f_list_from_for_end_loop(
                Core.t_intlist,
                Core.vx_new_int(2),
                Core.vx_new_int(3),
                Core.t_any_from_int.vx_fn_new((current_any) -> {
                  Core.Type_int current = Core.f_any_from_any(Core.t_int, current_any);
                  return 
                  Core.f_multiply(current, current);
                })
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_list_from_list_end(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-list-end",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (stringlist\n  \"a\" \"b\" \"c\")\n (list<-list-end\n  (stringlist\n   \"a\" \"b\" \"c\" \"d\")\n  3))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Core.t_stringlist,
                Core.t_anylist.vx_new(
                  Core.vx_new_string("a"),
                  Core.vx_new_string("b"),
                  Core.vx_new_string("c")
                )
              ),
              Collection.f_list_from_list_end(
                Core.t_stringlist,
                Core.f_new(
                  Core.t_stringlist,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string("a"),
                    Core.vx_new_string("b"),
                    Core.vx_new_string("c"),
                    Core.vx_new_string("d")
                  )
                ),
                Core.vx_new_int(3)
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_list_from_list_filter(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-list-filter",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (stringlist\n  \"a1\" \"b1\" \"c1\" \"d1\")\n (list<-list-filter : stringlist\n  (list\n   \"a\" 4 \"b\" (list) \"c\" (map) \"d\")\n  (fn : string\n   [val : any]\n   (if\n    (then\n     (is-string val)\n     (string val \"1\"))))))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Core.t_stringlist,
                Core.t_anylist.vx_new(
                  Core.vx_new_string("a1"),
                  Core.vx_new_string("b1"),
                  Core.vx_new_string("c1"),
                  Core.vx_new_string("d1")
                )
              ),
              Collection.f_list_from_list_filter(
                Core.t_stringlist,
                Core.f_new(
                  Core.t_list,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string("a"),
                    Core.vx_new_int(4),
                    Core.vx_new_string("b"),
                    Core.f_empty(
                      Core.t_list
                    ),
                    Core.vx_new_string("c"),
                    Core.f_empty(
                      Core.t_map
                    ),
                    Core.vx_new_string("d")
                  )
                ),
                Core.t_any_from_any.vx_fn_new((val_any) -> {
                  Core.Type_any val = Core.f_any_from_any(Core.t_any, val_any);
                  return 
                  Core.f_if_2(
                    Core.t_string,
                    Core.t_thenelselist.vx_new(
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Type.f_is_string(val);
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.f_new(
                            Core.t_string,
                            Core.t_anylist.vx_new(
                                val,
                                Core.vx_new_string("1")
                            )
                          );
                        })
                      )
                    )
                  );
                })
              )
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
          ":describename", "(test\n (list\n  \"a\" 1 \"b\" \"c\")\n (list<-list-filtertypes : list\n  (list\n   \"a\" 1 \"b\" \"c\" 4.5)\n  string int))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Core.t_list,
                Core.t_anylist.vx_new(
                  Core.vx_new_string("a"),
                  Core.vx_new_int(1),
                  Core.vx_new_string("b"),
                  Core.vx_new_string("c")
                )
              ),
              Collection.f_list_from_list_filtertypes(
                Core.t_list,
                Core.f_new(
                  Core.t_list,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string("a"),
                    Core.vx_new_int(1),
                    Core.vx_new_string("b"),
                    Core.vx_new_string("c"),
                    Core.t_decimal.vx_new_from_string("4.5")
                  )
                ),
                Core.t_typelist.vx_new(
                  Core.t_string,
                  Core.t_int
                )
              )
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
          ":describename", "(test\n (stringlist\n  \"b\" \"c\" \"d\")\n (list<-list-start\n  (stringlist\n   \"a\" \"b\" \"c\" \"d\")\n  2))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Core.t_stringlist,
                Core.t_anylist.vx_new(
                  Core.vx_new_string("b"),
                  Core.vx_new_string("c"),
                  Core.vx_new_string("d")
                )
              ),
              Collection.f_list_from_list_start(
                Core.t_stringlist,
                Core.f_new(
                  Core.t_stringlist,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string("a"),
                    Core.vx_new_string("b"),
                    Core.vx_new_string("c"),
                    Core.vx_new_string("d")
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

  static Test.Type_testcase f_list_from_list_start_end(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-list-start-end",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (stringlist\n  \"b\" \"c\")\n (list<-list-start-end\n  (stringlist\n   \"a\" \"b\" \"c\" \"d\")\n  2 3))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Core.t_stringlist,
                Core.t_anylist.vx_new(
                  Core.vx_new_string("b"),
                  Core.vx_new_string("c")
                )
              ),
              Collection.f_list_from_list_start_end(
                Core.t_stringlist,
                Core.f_new(
                  Core.t_stringlist,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string("a"),
                    Core.vx_new_string("b"),
                    Core.vx_new_string("c"),
                    Core.vx_new_string("d")
                  )
                ),
                Core.vx_new_int(2),
                Core.vx_new_int(3)
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_stringlist_from_map(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "stringlist<-map",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (stringlist \"a\" \"b\")\n (stringlist<-map\n  (intmap\n   :a 1\n   :b 2)))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Core.t_stringlist,
                Core.t_anylist.vx_new(
                  Core.vx_new_string("a"),
                  Core.vx_new_string("b")
                )
              ),
              Collection.f_stringlist_from_map(
                Core.f_new(
                  Core.t_intmap,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":a"),
                    Core.vx_new_int(1),
                    Core.vx_new_string(":b"),
                    Core.vx_new_int(2)
                  )
                )
              )
            )
        )
      )
    );
    return output;
  }

  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(
      CollectionTest.f_any_from_for_until_loop(context),
      CollectionTest.f_any_from_for_while_loop(context),
      CollectionTest.f_int_from_map_key(context),
      CollectionTest.f_int_from_stringlist_find(context),
      CollectionTest.f_is_list(context),
      CollectionTest.f_is_map(context),
      CollectionTest.f_list_from_for_end_loop(context),
      CollectionTest.f_list_from_list_end(context),
      CollectionTest.f_list_from_list_filter(context),
      CollectionTest.f_list_from_list_filtertypes(context),
      CollectionTest.f_list_from_list_start(context),
      CollectionTest.f_list_from_list_start_end(context),
      CollectionTest.f_stringlist_from_map(context)
    ));
    Test.Type_testcaselist output = Test.t_testcaselist.vx_new(arraylisttestcase);
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    return Test.t_testcoveragesummary.vx_new(
      ":testpkg",   "vx/collection", 
      ":constnums", Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 17, ":total", 17), 
      ":funcnums", Test.t_testcoveragenums.vx_new(":pct", 76, ":tests", 13, ":total", 17), 
      ":bigospacenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 17), 
      ":bigotimenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 17), 
      ":totalnums", Test.t_testcoveragenums.vx_new(":pct", 76, ":tests", 13, ":total", 17), 
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
        ":any<-for-until-loop", 1,
        ":any<-for-until-loop-max", 0,
        ":any<-for-while-loop", 1,
        ":any<-for-while-loop-max", 0,
        ":int<-map-key", 1,
        ":int<-stringlist-find", 1,
        ":is-list", 1,
        ":is-map", 1,
        ":list<-for-end-loop", 1,
        ":list<-for-while-loop", 0,
        ":list<-for-while-loop-max", 0,
        ":list<-list-end", 1,
        ":list<-list-filter", 1,
        ":list<-list-filtertypes", 1,
        ":list<-list-start", 1,
        ":list<-list-start-end", 1,
        ":stringlist<-map", 1
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
