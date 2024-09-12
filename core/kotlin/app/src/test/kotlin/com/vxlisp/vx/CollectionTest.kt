
package com.vxlisp.vx

object vx_collectionTest {

  fun f_any_from_for_until_loop(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "any<-for-until-loop",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_any_from_for_until_loop_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_any_from_for_until_loop_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n 8\n (any<-for-until-loop\n  1\n  (fn : boolean\n   [current : int]\n   (> current 6))\n  (fn : int\n   [current : int]\n   (+ current current))))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.vx_new_int(8),
        vx_collection.f_any_from_for_until_loop(
          vx_core.t_int,
          vx_core.vx_new_int(1),
          vx_core.t_boolean_from_any.vx_fn_new({current_any : vx_core.Type_any ->
            var current : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, current_any)
            var output_1 : vx_core.Type_any = vx_core.f_gt(
              current,
              vx_core.vx_new_int(6)
            )
            output_1
          }),
          vx_core.t_any_from_any.vx_fn_new({current_any : vx_core.Type_any ->
            var current : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, current_any)
            var output_2 : vx_core.Type_any = vx_core.f_plus(
              current,
              current
            )
            output_2
          })
        )
      )
    )
    return output
  }

  fun f_any_from_for_while_loop(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "any<-for-while-loop",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_any_from_for_while_loop_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_any_from_for_while_loop_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n 8\n (any<-for-while-loop\n  1\n  (fn : boolean\n   [current : int]\n   (< current 5))\n  (fn : int\n   [current : int]\n   (+ current current))))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.vx_new_int(8),
        vx_collection.f_any_from_for_while_loop(
          vx_core.t_int,
          vx_core.vx_new_int(1),
          vx_core.t_boolean_from_any.vx_fn_new({current_any : vx_core.Type_any ->
            var current : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, current_any)
            var output_1 : vx_core.Type_any = vx_core.f_lt(
              current,
              vx_core.vx_new_int(5)
            )
            output_1
          }),
          vx_core.t_any_from_any.vx_fn_new({current_any : vx_core.Type_any ->
            var current : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, current_any)
            var output_2 : vx_core.Type_any = vx_core.f_plus(
              current,
              current
            )
            output_2
          })
        )
      )
    )
    return output
  }

  fun f_anymap_from_struct(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "anymap<-struct",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_anymap_from_struct_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_anymap_from_struct_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (anymap\n  :name \"sname\"\n  :wordmap\n   (stringmap\n    :a \"x\"))\n (anymap<-struct\n  (translation\n   :name \"sname\"\n   :wordmap\n    (stringmap\n     :a \"x\"))))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_core.t_anymap,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":name"),
            vx_core.vx_new_string("sname"),
            vx_core.vx_new_string(":wordmap"),
            vx_core.f_new(
              vx_core.t_stringmap,
              vx_core.vx_new(
                vx_core.t_anylist,
                vx_core.vx_new_string(":a"),
                vx_core.vx_new_string("x")
              )
            )
          )
        ),
        vx_collection.f_anymap_from_struct(
          vx_core.f_new(
            vx_core.t_translation,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":name"),
              vx_core.vx_new_string("sname"),
              vx_core.vx_new_string(":wordmap"),
              vx_core.f_new(
                vx_core.t_stringmap,
                vx_core.vx_new(
                  vx_core.t_anylist,
                  vx_core.vx_new_string(":a"),
                  vx_core.vx_new_string("x")
                )
              )
            )
          )
        )
      )
    )
    return output
  }

  fun f_int_from_map_key(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "int<-map-key",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_int_from_map_key_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_int_from_map_key_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n 2\n (int<-map-key\n  (stringmap\n   :a \"x\"\n   :b \"y\")\n  \"b\"))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.vx_new_int(2),
        vx_collection.f_int_from_map_key(
          vx_core.f_new(
            vx_core.t_stringmap,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":a"),
              vx_core.vx_new_string("x"),
              vx_core.vx_new_string(":b"),
              vx_core.vx_new_string("y")
            )
          ),
          vx_core.vx_new_string("b")
        )
      )
    )
    return output
  }

  fun f_int_from_stringlist_find(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "int<-stringlist-find",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_int_from_stringlist_find_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_int_from_stringlist_find_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n 2\n (int<-stringlist-find\n  (stringlist \"a\" \"b\")\n  \"b\"))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.vx_new_int(2),
        vx_collection.f_int_from_stringlist_find(
          vx_core.f_new(
            vx_core.t_stringlist,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string("a"),
              vx_core.vx_new_string("b")
            )
          ),
          vx_core.vx_new_string("b")
        )
      )
    )
    return output
  }

  fun f_is_list(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "is-list",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_is_list_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_is_list_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test-true\n (is-list (empty stringlist)))",
      ":testresult", vx_test.f_test_true(
        context,
        vx_collection.f_is_list(
          vx_core.f_empty(
            vx_core.t_stringlist
          )
        )
      )
    )
    return output
  }

  fun f_is_map(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "is-map",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_is_map_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_is_map_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test-true\n (is-map (empty stringmap)))",
      ":testresult", vx_test.f_test_true(
        context,
        vx_collection.f_is_map(
          vx_core.f_empty(
            vx_core.t_stringmap
          )
        )
      )
    )
    return output
  }

  fun f_list_from_for_end_loop(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-for-end-loop",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_list_from_for_end_loop_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_list_from_for_end_loop_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (intlist 4 9)\n (list<-for-end-loop : intlist\n  2\n  3\n  (fn\n   [current : int]\n   (* current current))))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_core.t_intlist,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_int(4),
            vx_core.vx_new_int(9)
          )
        ),
        vx_collection.f_list_from_for_end_loop(
          vx_core.t_intlist,
          vx_core.vx_new_int(2),
          vx_core.vx_new_int(3),
          vx_core.t_any_from_int.vx_fn_new({current_any : vx_core.Type_any ->
            var current : vx_core.Type_int = vx_core.f_any_from_any(vx_core.t_int, current_any)
            var output_1 : vx_core.Type_any = vx_core.f_multiply(
              current,
              current
            )
            output_1
          })
        )
      )
    )
    return output
  }

  fun f_list_from_list_end(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-list-end",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_list_from_list_end_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_list_from_list_end_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (stringlist\n  \"a\" \"b\" \"c\")\n (list<-list-end\n  (stringlist\n   \"a\" \"b\" \"c\" \"d\")\n  3))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_core.t_stringlist,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string("a"),
            vx_core.vx_new_string("b"),
            vx_core.vx_new_string("c")
          )
        ),
        vx_collection.f_list_from_list_end(
          vx_core.t_stringlist,
          vx_core.f_new(
            vx_core.t_stringlist,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string("a"),
              vx_core.vx_new_string("b"),
              vx_core.vx_new_string("c"),
              vx_core.vx_new_string("d")
            )
          ),
          vx_core.vx_new_int(3)
        )
      )
    )
    return output
  }

  fun f_list_from_list_filter(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-list-filter",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_list_from_list_filter_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_list_from_list_filter_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (stringlist\n  \"a1\" \"b1\" \"c1\" \"d1\")\n (list<-list-filter : stringlist\n  (list\n   \"a\" 4 \"b\" (list) \"c\" (map) \"d\")\n  (fn : string\n   [value : any]\n   (if\n    (then\n     (is-string value)\n     (string value \"1\"))))))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_core.t_stringlist,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string("a1"),
            vx_core.vx_new_string("b1"),
            vx_core.vx_new_string("c1"),
            vx_core.vx_new_string("d1")
          )
        ),
        vx_collection.f_list_from_list_filter(
          vx_core.t_stringlist,
          vx_core.f_new(
            vx_core.t_list,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string("a"),
              vx_core.vx_new_int(4),
              vx_core.vx_new_string("b"),
              vx_core.f_empty(
                vx_core.t_list
              ),
              vx_core.vx_new_string("c"),
              vx_core.f_empty(
                vx_core.t_map
              ),
              vx_core.vx_new_string("d")
            )
          ),
          vx_core.t_any_from_any.vx_fn_new({value_any : vx_core.Type_any ->
            var value : vx_core.Type_any = vx_core.f_any_from_any(vx_core.t_any, value_any)
            var output_1 : vx_core.Type_any = vx_core.f_if_2(
              vx_core.t_string,
              vx_core.vx_new(
                vx_core.t_thenelselist,
                vx_core.f_then(
                  vx_core.t_boolean_from_func.vx_fn_new({ ->
                    var output_2 : vx_core.Type_any = vx_type.f_is_string(
                      value
                    )
                    output_2
                  }),
                  vx_core.t_any_from_func.vx_fn_new({ ->
                    var output_3 : vx_core.Type_any = vx_core.f_new(
                      vx_core.t_string,
                      vx_core.vx_new(
                        vx_core.t_anylist,
                        value,
                        vx_core.vx_new_string("1")
                      )
                    )
                    output_3
                  })
                )
              )
            )
            output_1
          })
        )
      )
    )
    return output
  }

  fun f_list_from_list_filtertypes(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-list-filtertypes",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_list_from_list_filtertypes_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_list_from_list_filtertypes_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (list\n  \"a\" 1 \"b\" \"c\")\n (list<-list-filtertypes : list\n  (list\n   \"a\" 1 \"b\" \"c\" 4.5)\n  string int))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_core.t_list,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string("a"),
            vx_core.vx_new_int(1),
            vx_core.vx_new_string("b"),
            vx_core.vx_new_string("c")
          )
        ),
        vx_collection.f_list_from_list_filtertypes(
          vx_core.t_list,
          vx_core.f_new(
            vx_core.t_list,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string("a"),
              vx_core.vx_new_int(1),
              vx_core.vx_new_string("b"),
              vx_core.vx_new_string("c"),
              vx_core.vx_new_decimal("4.5")
            )
          ),
          vx_core.vx_new(
            vx_core.t_typelist,
            vx_core.t_string,
            vx_core.t_int
          )
        )
      )
    )
    return output
  }

  fun f_list_from_list_start(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-list-start",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_list_from_list_start_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_list_from_list_start_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (stringlist\n  \"b\" \"c\" \"d\")\n (list<-list-start\n  (stringlist\n   \"a\" \"b\" \"c\" \"d\")\n  2))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_core.t_stringlist,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string("b"),
            vx_core.vx_new_string("c"),
            vx_core.vx_new_string("d")
          )
        ),
        vx_collection.f_list_from_list_start(
          vx_core.t_stringlist,
          vx_core.f_new(
            vx_core.t_stringlist,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string("a"),
              vx_core.vx_new_string("b"),
              vx_core.vx_new_string("c"),
              vx_core.vx_new_string("d")
            )
          ),
          vx_core.vx_new_int(2)
        )
      )
    )
    return output
  }

  fun f_list_from_list_start_end(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-list-start-end",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_list_from_list_start_end_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_list_from_list_start_end_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (stringlist\n  \"b\" \"c\")\n (list<-list-start-end\n  (stringlist\n   \"a\" \"b\" \"c\" \"d\")\n  2 3))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_core.t_stringlist,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string("b"),
            vx_core.vx_new_string("c")
          )
        ),
        vx_collection.f_list_from_list_start_end(
          vx_core.t_stringlist,
          vx_core.f_new(
            vx_core.t_stringlist,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string("a"),
              vx_core.vx_new_string("b"),
              vx_core.vx_new_string("c"),
              vx_core.vx_new_string("d")
            )
          ),
          vx_core.vx_new_int(2),
          vx_core.vx_new_int(3)
        )
      )
    )
    return output
  }

  fun f_map_from_map_end(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "map<-map-end",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_map_from_map_end_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_map_from_map_end_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (stringmap\n  :b \"1\"\n  :a \"2\")\n (map<-map-end\n  (stringmap\n   :b \"1\"\n   :a \"2\"\n   :c \"3\")\n  2))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_core.t_stringmap,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":b"),
            vx_core.vx_new_string("1"),
            vx_core.vx_new_string(":a"),
            vx_core.vx_new_string("2")
          )
        ),
        vx_collection.f_map_from_map_end(
          vx_core.t_stringmap,
          vx_core.f_new(
            vx_core.t_stringmap,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":b"),
              vx_core.vx_new_string("1"),
              vx_core.vx_new_string(":a"),
              vx_core.vx_new_string("2"),
              vx_core.vx_new_string(":c"),
              vx_core.vx_new_string("3")
            )
          ),
          vx_core.vx_new_int(2)
        )
      )
    )
    return output
  }

  fun f_map_from_map_keys(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "map<-map-keys",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_map_from_map_keys_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_map_from_map_keys_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (stringmap\n  :c \"3\"\n  :a \"1\")\n (map<-map-keys\n  (stringmap\n   :a \"1\"\n   :b \"2\"\n   :c \"3\")\n  (stringlist\n   \"c\" \"a\")))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_core.t_stringmap,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":c"),
            vx_core.vx_new_string("3"),
            vx_core.vx_new_string(":a"),
            vx_core.vx_new_string("1")
          )
        ),
        vx_collection.f_map_from_map_keys(
          vx_core.t_stringmap,
          vx_core.f_new(
            vx_core.t_stringmap,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":a"),
              vx_core.vx_new_string("1"),
              vx_core.vx_new_string(":b"),
              vx_core.vx_new_string("2"),
              vx_core.vx_new_string(":c"),
              vx_core.vx_new_string("3")
            )
          ),
          vx_core.f_new(
            vx_core.t_stringlist,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string("c"),
              vx_core.vx_new_string("a")
            )
          )
        )
      )
    )
    return output
  }

  fun f_map_from_map_start(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "map<-map-start",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_map_from_map_start_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_map_from_map_start_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (stringmap\n  :a \"2\"\n  :c \"3\")\n (map<-map-start\n  (stringmap\n   :b \"1\"\n   :a \"2\"\n   :c \"3\")\n  2))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_core.t_stringmap,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":a"),
            vx_core.vx_new_string("2"),
            vx_core.vx_new_string(":c"),
            vx_core.vx_new_string("3")
          )
        ),
        vx_collection.f_map_from_map_start(
          vx_core.t_stringmap,
          vx_core.f_new(
            vx_core.t_stringmap,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":b"),
              vx_core.vx_new_string("1"),
              vx_core.vx_new_string(":a"),
              vx_core.vx_new_string("2"),
              vx_core.vx_new_string(":c"),
              vx_core.vx_new_string("3")
            )
          ),
          vx_core.vx_new_int(2)
        )
      )
    )
    return output
  }

  fun f_map_from_map_start_end(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "map<-map-start-end",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_map_from_map_start_end_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_map_from_map_start_end_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (stringmap\n  :a \"2\"\n  :c \"3\")\n (map<-map-start-end\n  (stringmap\n   :b \"1\"\n   :a \"2\"\n   :c \"3\"\n   :d \"4\")\n  2 3))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_core.t_stringmap,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":a"),
            vx_core.vx_new_string("2"),
            vx_core.vx_new_string(":c"),
            vx_core.vx_new_string("3")
          )
        ),
        vx_collection.f_map_from_map_start_end(
          vx_core.t_stringmap,
          vx_core.f_new(
            vx_core.t_stringmap,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":b"),
              vx_core.vx_new_string("1"),
              vx_core.vx_new_string(":a"),
              vx_core.vx_new_string("2"),
              vx_core.vx_new_string(":c"),
              vx_core.vx_new_string("3"),
              vx_core.vx_new_string(":d"),
              vx_core.vx_new_string("4")
            )
          ),
          vx_core.vx_new_int(2),
          vx_core.vx_new_int(3)
        )
      )
    )
    return output
  }

  fun f_map_from_struct(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "map<-struct",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        f_map_from_struct_testdescribe_1(context)
      )
    )
    return output
  }

  fun f_map_from_struct_testdescribe_1(context : vx_core.Type_context) : vx_test.Type_testdescribe {
    var output : vx_test.Type_testdescribe = vx_core.vx_new(
      vx_test.t_testdescribe,
      ":describename", "(test\n (stringmap\n  :name \"sname\")\n (map<-struct : stringmap\n  (translation\n   :name \"sname\"\n   :wordmap\n    (stringmap\n     :a \"x\"))))",
      ":testresult", vx_test.f_test(
        context,
        vx_core.f_new(
          vx_core.t_stringmap,
          vx_core.vx_new(
            vx_core.t_anylist,
            vx_core.vx_new_string(":name"),
            vx_core.vx_new_string("sname")
          )
        ),
        vx_collection.f_map_from_struct(
          vx_core.t_stringmap,
          vx_core.f_new(
            vx_core.t_translation,
            vx_core.vx_new(
              vx_core.t_anylist,
              vx_core.vx_new_string(":name"),
              vx_core.vx_new_string("sname"),
              vx_core.vx_new_string(":wordmap"),
              vx_core.f_new(
                vx_core.t_stringmap,
                vx_core.vx_new(
                  vx_core.t_anylist,
                  vx_core.vx_new_string(":a"),
                  vx_core.vx_new_string("x")
                )
              )
            )
          )
        )
      )
    )
    return output
  }

  fun test_cases(context : vx_core.Type_context) : vx_test.Type_testcaselist {
    var testcases : List<vx_core.Type_any> = vx_core.arraylist_from_array(
      vx_collectionTest.f_any_from_for_until_loop(context),
      vx_collectionTest.f_any_from_for_while_loop(context),
      vx_collectionTest.f_anymap_from_struct(context),
      vx_collectionTest.f_int_from_map_key(context),
      vx_collectionTest.f_int_from_stringlist_find(context),
      vx_collectionTest.f_is_list(context),
      vx_collectionTest.f_is_map(context),
      vx_collectionTest.f_list_from_for_end_loop(context),
      vx_collectionTest.f_list_from_list_end(context),
      vx_collectionTest.f_list_from_list_filter(context),
      vx_collectionTest.f_list_from_list_filtertypes(context),
      vx_collectionTest.f_list_from_list_start(context),
      vx_collectionTest.f_list_from_list_start_end(context),
      vx_collectionTest.f_map_from_map_end(context),
      vx_collectionTest.f_map_from_map_keys(context),
      vx_collectionTest.f_map_from_map_start(context),
      vx_collectionTest.f_map_from_map_start_end(context),
      vx_collectionTest.f_map_from_struct(context)
    )
    var output : vx_test.Type_testcaselist = vx_core.vx_new(
      vx_test.t_testcaselist,
      testcases
    )
    return output
  }

  fun test_coveragesummary() : vx_test.Type_testcoveragesummary {
    var output : vx_test.Type_testcoveragesummary = vx_core.vx_new(
      vx_test.t_testcoveragesummary,
      ":testpkg", "vx/collection", 
      ":constnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 25, ":total", 25), 
      ":funcnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 72, ":tests", 18, ":total", 25), 
      ":bigospacenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 25), 
      ":bigotimenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 25), 
      ":totalnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 72, ":tests", 18, ":total", 25), 
      ":typenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0)
    )
    return output
  }

  fun test_coveragedetail() : vx_test.Type_testcoveragedetail {
    var output : vx_test.Type_testcoveragedetail = vx_core.vx_new(
      vx_test.t_testcoveragedetail,
      ":testpkg", "vx/collection",
      ":typemap", vx_core.e_intmap, 
      ":constmap", vx_core.e_intmap, 
      ":funcmap", vx_core.vx_new(
        vx_core.t_intmap,
        ":any<-for-until-loop", 1,
        ":any<-for-until-loop-max", 0,
        ":any<-for-while-loop", 1,
        ":any<-for-while-loop-max", 0,
        ":any<-map-pos", 0,
        ":anymap<-struct", 1,
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
        ":map<-map-start-end", 1,
        ":map<-struct", 1
      )
    )
    return output
  }

  fun test_package(context : vx_core.Type_context) : vx_test.Type_testpackage {
    var testcaselist : vx_test.Type_testcaselist = test_cases(context)
    var output : vx_test.Type_testpackage = vx_core.vx_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/collection", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    )
    return output
  }

}
