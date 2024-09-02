
package com.vxlisp.vx;

import java.util.List;

public final class CollectionTest {

  public static Test.Type_testcase f_any_from_for_until_loop(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "any<-for-until-loop",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        f_any_from_for_until_loop_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Test.Type_testdescribe f_any_from_for_until_loop_testdescribe_1(final Core.Type_context context) {
    Test.Type_testdescribe output = Core.vx_new(
      Test.t_testdescribe,
      ":describename", "(test\n 8\n (any<-for-until-loop\n  1\n  (fn : boolean\n   [current : int]\n   (> current 6))\n  (fn : int\n   [current : int]\n   (+ current current))))",
      ":testresult", Test.f_test(
        context,
        Core.vx_new_int(8),
        Collection.f_any_from_for_until_loop(
          Core.t_int,
          Core.vx_new_int(1),
          Core.t_boolean_from_any.vx_fn_new((current_any) -> {
            Core.Type_int current = Core.f_any_from_any(Core.t_int, current_any);
            Core.Type_any output_1 = Core.f_gt(
              current,
              Core.vx_new_int(6)
            );
            return output_1;
          }),
          Core.t_any_from_any.vx_fn_new((current_any) -> {
            Core.Type_int current = Core.f_any_from_any(Core.t_int, current_any);
            Core.Type_any output_2 = Core.f_plus(
              current,
              current
            );
            return output_2;
          })
        )
      )
    );
    return output;
  }

  public static Test.Type_testcase f_any_from_for_while_loop(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "any<-for-while-loop",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        f_any_from_for_while_loop_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Test.Type_testdescribe f_any_from_for_while_loop_testdescribe_1(final Core.Type_context context) {
    Test.Type_testdescribe output = Core.vx_new(
      Test.t_testdescribe,
      ":describename", "(test\n 8\n (any<-for-while-loop\n  1\n  (fn : boolean\n   [current : int]\n   (< current 5))\n  (fn : int\n   [current : int]\n   (+ current current))))",
      ":testresult", Test.f_test(
        context,
        Core.vx_new_int(8),
        Collection.f_any_from_for_while_loop(
          Core.t_int,
          Core.vx_new_int(1),
          Core.t_boolean_from_any.vx_fn_new((current_any) -> {
            Core.Type_int current = Core.f_any_from_any(Core.t_int, current_any);
            Core.Type_any output_1 = Core.f_lt(
              current,
              Core.vx_new_int(5)
            );
            return output_1;
          }),
          Core.t_any_from_any.vx_fn_new((current_any) -> {
            Core.Type_int current = Core.f_any_from_any(Core.t_int, current_any);
            Core.Type_any output_2 = Core.f_plus(
              current,
              current
            );
            return output_2;
          })
        )
      )
    );
    return output;
  }

  public static Test.Type_testcase f_int_from_map_key(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "int<-map-key",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        f_int_from_map_key_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Test.Type_testdescribe f_int_from_map_key_testdescribe_1(final Core.Type_context context) {
    Test.Type_testdescribe output = Core.vx_new(
      Test.t_testdescribe,
      ":describename", "(test\n 2\n (int<-map-key\n  (stringmap\n   :a \"x\"\n   :b \"y\")\n  \"b\"))",
      ":testresult", Test.f_test(
        context,
        Core.vx_new_int(2),
        Collection.f_int_from_map_key(
          Core.f_new(
            Core.t_stringmap,
            Core.vx_new(
              Core.t_anylist,
              Core.vx_new_string(":a"),
              Core.vx_new_string("x"),
              Core.vx_new_string(":b"),
              Core.vx_new_string("y")
            )
          ),
          Core.vx_new_string("b")
        )
      )
    );
    return output;
  }

  public static Test.Type_testcase f_int_from_stringlist_find(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "int<-stringlist-find",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        f_int_from_stringlist_find_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Test.Type_testdescribe f_int_from_stringlist_find_testdescribe_1(final Core.Type_context context) {
    Test.Type_testdescribe output = Core.vx_new(
      Test.t_testdescribe,
      ":describename", "(test\n 2\n (int<-stringlist-find\n  (stringlist \"a\" \"b\")\n  \"b\"))",
      ":testresult", Test.f_test(
        context,
        Core.vx_new_int(2),
        Collection.f_int_from_stringlist_find(
          Core.f_new(
            Core.t_stringlist,
            Core.vx_new(
              Core.t_anylist,
              Core.vx_new_string("a"),
              Core.vx_new_string("b")
            )
          ),
          Core.vx_new_string("b")
        )
      )
    );
    return output;
  }

  public static Test.Type_testcase f_is_list(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "is-list",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        f_is_list_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Test.Type_testdescribe f_is_list_testdescribe_1(final Core.Type_context context) {
    Test.Type_testdescribe output = Core.vx_new(
      Test.t_testdescribe,
      ":describename", "(test-true\n (is-list (empty stringlist)))",
      ":testresult", Test.f_test_true(
        context,
        Collection.f_is_list(
          Core.f_empty(
            Core.t_stringlist
          )
        )
      )
    );
    return output;
  }

  public static Test.Type_testcase f_is_map(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "is-map",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        f_is_map_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Test.Type_testdescribe f_is_map_testdescribe_1(final Core.Type_context context) {
    Test.Type_testdescribe output = Core.vx_new(
      Test.t_testdescribe,
      ":describename", "(test-true\n (is-map (empty stringmap)))",
      ":testresult", Test.f_test_true(
        context,
        Collection.f_is_map(
          Core.f_empty(
            Core.t_stringmap
          )
        )
      )
    );
    return output;
  }

  public static Test.Type_testcase f_list_from_for_end_loop(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-for-end-loop",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        f_list_from_for_end_loop_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Test.Type_testdescribe f_list_from_for_end_loop_testdescribe_1(final Core.Type_context context) {
    Test.Type_testdescribe output = Core.vx_new(
      Test.t_testdescribe,
      ":describename", "(test\n (intlist 4 9)\n (list<-for-end-loop : intlist\n  2\n  3\n  (fn\n   [current : int]\n   (* current current))))",
      ":testresult", Test.f_test(
        context,
        Core.f_new(
          Core.t_intlist,
          Core.vx_new(
            Core.t_anylist,
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
            Core.Type_any output_1 = Core.f_multiply(
              current,
              current
            );
            return output_1;
          })
        )
      )
    );
    return output;
  }

  public static Test.Type_testcase f_list_from_list_end(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-list-end",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        f_list_from_list_end_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Test.Type_testdescribe f_list_from_list_end_testdescribe_1(final Core.Type_context context) {
    Test.Type_testdescribe output = Core.vx_new(
      Test.t_testdescribe,
      ":describename", "(test\n (stringlist\n  \"a\" \"b\" \"c\")\n (list<-list-end\n  (stringlist\n   \"a\" \"b\" \"c\" \"d\")\n  3))",
      ":testresult", Test.f_test(
        context,
        Core.f_new(
          Core.t_stringlist,
          Core.vx_new(
            Core.t_anylist,
            Core.vx_new_string("a"),
            Core.vx_new_string("b"),
            Core.vx_new_string("c")
          )
        ),
        Collection.f_list_from_list_end(
          Core.t_stringlist,
          Core.f_new(
            Core.t_stringlist,
            Core.vx_new(
              Core.t_anylist,
              Core.vx_new_string("a"),
              Core.vx_new_string("b"),
              Core.vx_new_string("c"),
              Core.vx_new_string("d")
            )
          ),
          Core.vx_new_int(3)
        )
      )
    );
    return output;
  }

  public static Test.Type_testcase f_list_from_list_filter(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-list-filter",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        f_list_from_list_filter_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Test.Type_testdescribe f_list_from_list_filter_testdescribe_1(final Core.Type_context context) {
    Test.Type_testdescribe output = Core.vx_new(
      Test.t_testdescribe,
      ":describename", "(test\n (stringlist\n  \"a1\" \"b1\" \"c1\" \"d1\")\n (list<-list-filter : stringlist\n  (list\n   \"a\" 4 \"b\" (list) \"c\" (map) \"d\")\n  (fn : string\n   [value : any]\n   (if\n    (then\n     (is-string value)\n     (string value \"1\"))))))",
      ":testresult", Test.f_test(
        context,
        Core.f_new(
          Core.t_stringlist,
          Core.vx_new(
            Core.t_anylist,
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
            Core.vx_new(
              Core.t_anylist,
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
          Core.t_any_from_any.vx_fn_new((value_any) -> {
            Core.Type_any value = Core.f_any_from_any(Core.t_any, value_any);
            Core.Type_any output_1 = Core.f_if_2(
              Core.t_string,
              Core.vx_new(
                Core.t_thenelselist,
                Core.f_then(
                  Core.t_boolean_from_func.vx_fn_new(() -> {
                    Core.Type_any output_2 = Type.f_is_string(
                      value
                    );
                    return output_2;
                  }),
                  Core.t_any_from_func.vx_fn_new(() -> {
                    Core.Type_any output_3 = Core.f_new(
                      Core.t_string,
                      Core.vx_new(
                        Core.t_anylist,
                        value,
                        Core.vx_new_string("1")
                      )
                    );
                    return output_3;
                  })
                )
              )
            );
            return output_1;
          })
        )
      )
    );
    return output;
  }

  public static Test.Type_testcase f_list_from_list_filtertypes(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-list-filtertypes",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        f_list_from_list_filtertypes_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Test.Type_testdescribe f_list_from_list_filtertypes_testdescribe_1(final Core.Type_context context) {
    Test.Type_testdescribe output = Core.vx_new(
      Test.t_testdescribe,
      ":describename", "(test\n (list\n  \"a\" 1 \"b\" \"c\")\n (list<-list-filtertypes : list\n  (list\n   \"a\" 1 \"b\" \"c\" 4.5)\n  string int))",
      ":testresult", Test.f_test(
        context,
        Core.f_new(
          Core.t_list,
          Core.vx_new(
            Core.t_anylist,
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
            Core.vx_new(
              Core.t_anylist,
              Core.vx_new_string("a"),
              Core.vx_new_int(1),
              Core.vx_new_string("b"),
              Core.vx_new_string("c"),
              Core.vx_new_decimal("4.5")
            )
          ),
          Core.vx_new(
            Core.t_typelist,
            Core.t_string,
            Core.t_int
          )
        )
      )
    );
    return output;
  }

  public static Test.Type_testcase f_list_from_list_start(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-list-start",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        f_list_from_list_start_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Test.Type_testdescribe f_list_from_list_start_testdescribe_1(final Core.Type_context context) {
    Test.Type_testdescribe output = Core.vx_new(
      Test.t_testdescribe,
      ":describename", "(test\n (stringlist\n  \"b\" \"c\" \"d\")\n (list<-list-start\n  (stringlist\n   \"a\" \"b\" \"c\" \"d\")\n  2))",
      ":testresult", Test.f_test(
        context,
        Core.f_new(
          Core.t_stringlist,
          Core.vx_new(
            Core.t_anylist,
            Core.vx_new_string("b"),
            Core.vx_new_string("c"),
            Core.vx_new_string("d")
          )
        ),
        Collection.f_list_from_list_start(
          Core.t_stringlist,
          Core.f_new(
            Core.t_stringlist,
            Core.vx_new(
              Core.t_anylist,
              Core.vx_new_string("a"),
              Core.vx_new_string("b"),
              Core.vx_new_string("c"),
              Core.vx_new_string("d")
            )
          ),
          Core.vx_new_int(2)
        )
      )
    );
    return output;
  }

  public static Test.Type_testcase f_list_from_list_start_end(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-list-start-end",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        f_list_from_list_start_end_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Test.Type_testdescribe f_list_from_list_start_end_testdescribe_1(final Core.Type_context context) {
    Test.Type_testdescribe output = Core.vx_new(
      Test.t_testdescribe,
      ":describename", "(test\n (stringlist\n  \"b\" \"c\")\n (list<-list-start-end\n  (stringlist\n   \"a\" \"b\" \"c\" \"d\")\n  2 3))",
      ":testresult", Test.f_test(
        context,
        Core.f_new(
          Core.t_stringlist,
          Core.vx_new(
            Core.t_anylist,
            Core.vx_new_string("b"),
            Core.vx_new_string("c")
          )
        ),
        Collection.f_list_from_list_start_end(
          Core.t_stringlist,
          Core.f_new(
            Core.t_stringlist,
            Core.vx_new(
              Core.t_anylist,
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
    );
    return output;
  }

  public static Test.Type_testcase f_map_from_map_end(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "map<-map-end",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        f_map_from_map_end_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Test.Type_testdescribe f_map_from_map_end_testdescribe_1(final Core.Type_context context) {
    Test.Type_testdescribe output = Core.vx_new(
      Test.t_testdescribe,
      ":describename", "(test\n (stringmap\n  :b \"1\"\n  :a \"2\")\n (map<-map-end\n  (stringmap\n   :b \"1\"\n   :a \"2\"\n   :c \"3\")\n  2))",
      ":testresult", Test.f_test(
        context,
        Core.f_new(
          Core.t_stringmap,
          Core.vx_new(
            Core.t_anylist,
            Core.vx_new_string(":b"),
            Core.vx_new_string("1"),
            Core.vx_new_string(":a"),
            Core.vx_new_string("2")
          )
        ),
        Collection.f_map_from_map_end(
          Core.t_stringmap,
          Core.f_new(
            Core.t_stringmap,
            Core.vx_new(
              Core.t_anylist,
              Core.vx_new_string(":b"),
              Core.vx_new_string("1"),
              Core.vx_new_string(":a"),
              Core.vx_new_string("2"),
              Core.vx_new_string(":c"),
              Core.vx_new_string("3")
            )
          ),
          Core.vx_new_int(2)
        )
      )
    );
    return output;
  }

  public static Test.Type_testcase f_map_from_map_keys(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "map<-map-keys",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        f_map_from_map_keys_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Test.Type_testdescribe f_map_from_map_keys_testdescribe_1(final Core.Type_context context) {
    Test.Type_testdescribe output = Core.vx_new(
      Test.t_testdescribe,
      ":describename", "(test\n (stringmap\n  :c \"3\"\n  :a \"1\")\n (map<-map-keys\n  (stringmap\n   :a \"1\"\n   :b \"2\"\n   :c \"3\")\n  (stringlist\n   \"c\" \"a\")))",
      ":testresult", Test.f_test(
        context,
        Core.f_new(
          Core.t_stringmap,
          Core.vx_new(
            Core.t_anylist,
            Core.vx_new_string(":c"),
            Core.vx_new_string("3"),
            Core.vx_new_string(":a"),
            Core.vx_new_string("1")
          )
        ),
        Collection.f_map_from_map_keys(
          Core.t_stringmap,
          Core.f_new(
            Core.t_stringmap,
            Core.vx_new(
              Core.t_anylist,
              Core.vx_new_string(":a"),
              Core.vx_new_string("1"),
              Core.vx_new_string(":b"),
              Core.vx_new_string("2"),
              Core.vx_new_string(":c"),
              Core.vx_new_string("3")
            )
          ),
          Core.f_new(
            Core.t_stringlist,
            Core.vx_new(
              Core.t_anylist,
              Core.vx_new_string("c"),
              Core.vx_new_string("a")
            )
          )
        )
      )
    );
    return output;
  }

  public static Test.Type_testcase f_map_from_map_start(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "map<-map-start",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        f_map_from_map_start_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Test.Type_testdescribe f_map_from_map_start_testdescribe_1(final Core.Type_context context) {
    Test.Type_testdescribe output = Core.vx_new(
      Test.t_testdescribe,
      ":describename", "(test\n (stringmap\n  :a \"2\"\n  :c \"3\")\n (map<-map-start\n  (stringmap\n   :b \"1\"\n   :a \"2\"\n   :c \"3\")\n  2))",
      ":testresult", Test.f_test(
        context,
        Core.f_new(
          Core.t_stringmap,
          Core.vx_new(
            Core.t_anylist,
            Core.vx_new_string(":a"),
            Core.vx_new_string("2"),
            Core.vx_new_string(":c"),
            Core.vx_new_string("3")
          )
        ),
        Collection.f_map_from_map_start(
          Core.t_stringmap,
          Core.f_new(
            Core.t_stringmap,
            Core.vx_new(
              Core.t_anylist,
              Core.vx_new_string(":b"),
              Core.vx_new_string("1"),
              Core.vx_new_string(":a"),
              Core.vx_new_string("2"),
              Core.vx_new_string(":c"),
              Core.vx_new_string("3")
            )
          ),
          Core.vx_new_int(2)
        )
      )
    );
    return output;
  }

  public static Test.Type_testcase f_map_from_map_start_end(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "map<-map-start-end",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        f_map_from_map_start_end_testdescribe_1(context)
      )
    );
    return output;
  }

  public static Test.Type_testdescribe f_map_from_map_start_end_testdescribe_1(final Core.Type_context context) {
    Test.Type_testdescribe output = Core.vx_new(
      Test.t_testdescribe,
      ":describename", "(test\n (stringmap\n  :a \"2\"\n  :c \"3\")\n (map<-map-start-end\n  (stringmap\n   :b \"1\"\n   :a \"2\"\n   :c \"3\"\n   :d \"4\")\n  2 3))",
      ":testresult", Test.f_test(
        context,
        Core.f_new(
          Core.t_stringmap,
          Core.vx_new(
            Core.t_anylist,
            Core.vx_new_string(":a"),
            Core.vx_new_string("2"),
            Core.vx_new_string(":c"),
            Core.vx_new_string("3")
          )
        ),
        Collection.f_map_from_map_start_end(
          Core.t_stringmap,
          Core.f_new(
            Core.t_stringmap,
            Core.vx_new(
              Core.t_anylist,
              Core.vx_new_string(":b"),
              Core.vx_new_string("1"),
              Core.vx_new_string(":a"),
              Core.vx_new_string("2"),
              Core.vx_new_string(":c"),
              Core.vx_new_string("3"),
              Core.vx_new_string(":d"),
              Core.vx_new_string("4")
            )
          ),
          Core.vx_new_int(2),
          Core.vx_new_int(3)
        )
      )
    );
    return output;
  }

  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> testcases = Core.arraylist_from_array(
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
      CollectionTest.f_map_from_map_end(context),
      CollectionTest.f_map_from_map_keys(context),
      CollectionTest.f_map_from_map_start(context),
      CollectionTest.f_map_from_map_start_end(context)
    );
    Test.Type_testcaselist output = Core.vx_new(
      Test.t_testcaselist,
      testcases
    );
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    Test.Type_testcoveragesummary output = Core.vx_new(
      Test.t_testcoveragesummary,
      ":testpkg", "vx/collection", 
      ":constnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 23, ":total", 23), 
      ":funcnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 69, ":tests", 16, ":total", 23), 
      ":bigospacenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 23), 
      ":bigotimenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 23), 
      ":totalnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 69, ":tests", 16, ":total", 23), 
      ":typenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0)
    );
    return output;
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    Test.Type_testcoveragedetail output = Core.vx_new(
      Test.t_testcoveragedetail,
      ":testpkg", "vx/collection",
      ":typemap", Core.e_intmap, 
      ":constmap", Core.e_intmap, 
      ":funcmap", Core.vx_new(
        Core.t_intmap,
        ":any<-for-until-loop", 1,
        ":any<-for-until-loop-max", 0,
        ":any<-for-while-loop", 1,
        ":any<-for-while-loop-max", 0,
        ":any<-map-pos", 0,
        ":boolean-write<-map-removekey", 0,
        ":boolean-write<-map-removekeys", 0,
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
        ":map<-map-end", 1,
        ":map<-map-keys", 1,
        ":map<-map-start", 1,
        ":map<-map-start-end", 1
      )
    );
    return output;
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Core.vx_new(
      Test.t_testpackage,
      ":testpkg", "vx/collection", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
