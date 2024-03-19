'strict mode'

import vx_collection from "../../src/vx/collection.js"
import vx_core from "../../src/vx/core.js"
import vx_test from "../../src/vx/test.js"
import vx_type from "../../src/vx/type.js"

export default class vx_collection_test {


  static test_package(context) {
    const testcaselist = vx_collection_test.test_cases(context)
    const output = vx_core.f_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/collection",
      ":caselist", testcaselist,
      ":coveragesummary", vx_collection_test.test_coveragesummary(),
      ":coveragedetail", vx_collection_test.test_coveragedetail()
    );
    return output;
  }

  static test_coveragesummary() {
    return vx_core.f_new(
      vx_test.t_testcoveragesummary,
      "testpkg",   "vx/collection", 
      "constnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 17, ":total", 17), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 76, ":tests", 13, ":total", 17), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 76, ":tests", 13, ":total", 17), 
      "typenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0)
    )
  }

  static test_coveragedetail() {
    return vx_core.f_new(
      vx_test.t_testcoveragedetail,
      "testpkg", "vx/collection",
      "typemap",
        vx_core.f_new(
          vx_core.t_intmap
        ),
      "constmap",
        vx_core.f_new(
          vx_core.t_intmap
        ),
      "funcmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "any<-for-until-loop", 1,
          "any<-for-until-loop-max", 0,
          "any<-for-while-loop", 1,
          "any<-for-while-loop-max", 0,
          "int<-map-key", 1,
          "int<-stringlist-find", 1,
          "is-list", 1,
          "is-map", 1,
          "list<-for-end-loop", 1,
          "list<-for-while-loop", 0,
          "list<-for-while-loop-max", 0,
          "list<-list-end", 1,
          "list<-list-filter", 1,
          "list<-list-filtertypes", 1,
          "list<-list-start", 1,
          "list<-list-start-end", 1,
          "stringlist<-map", 1
        )
    )
  }

  static f_any_from_for_until_loop(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "any<-for-until-loop",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n 8\n (any<-for-until-loop\n  1\n  (fn : boolean\n   [current : int]\n   (> current 6))\n  (fn : int\n   [current : int]\n   (+ current current))))",
            ":testresult",
            vx_test.f_test(
              context,
              8,
              vx_collection.f_any_from_for_until_loop(
                {"any-1": vx_core.t_int},
                1,
                vx_core.f_new(vx_core.t_boolean_from_any, (current) => 
                  vx_core.f_gt(current, 6)),
                vx_core.f_new(vx_core.t_any_from_any, (current) => 
                  vx_core.f_plus(current, current))
              )
            )
          )
        )
    )
    return output
  }

  static f_any_from_for_while_loop(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "any<-for-while-loop",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n 8\n (any<-for-while-loop\n  1\n  (fn : boolean\n   [current : int]\n   (< current 5))\n  (fn : int\n   [current : int]\n   (+ current current))))",
            ":testresult",
            vx_test.f_test(
              context,
              8,
              vx_collection.f_any_from_for_while_loop(
                {"any-1": vx_core.t_int},
                1,
                vx_core.f_new(vx_core.t_boolean_from_any, (current) => 
                  vx_core.f_lt(current, 5)),
                vx_core.f_new(vx_core.t_any_from_any, (current) => 
                  vx_core.f_plus(current, current))
              )
            )
          )
        )
    )
    return output
  }

  static f_int_from_map_key(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "int<-map-key",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n 2\n (int<-map-key\n  (stringmap\n   :a \"x\"\n   :b \"y\")\n  \"b\"))",
            ":testresult",
            vx_test.f_test(
              context,
              2,
              vx_collection.f_int_from_map_key(
                vx_core.f_new(
                  vx_core.t_stringmap,
                  ":a",
                  "x",
                  ":b",
                  "y"
                ),
                "b"
              )
            )
          )
        )
    )
    return output
  }

  static f_int_from_stringlist_find(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "int<-stringlist-find",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n 2\n (int<-stringlist-find\n  (stringlist \"a\" \"b\")\n  \"b\"))",
            ":testresult",
            vx_test.f_test(
              context,
              2,
              vx_collection.f_int_from_stringlist_find(
                vx_core.f_new(
                  vx_core.t_stringlist,
                  "a",
                  "b"
                ),
                "b"
              )
            )
          )
        )
    )
    return output
  }

  static f_is_list(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "is-list",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true\n (is-list (empty stringlist)))",
            ":testresult",
            vx_test.f_test_true(
              context,
              vx_collection.f_is_list(
                vx_core.f_empty(
                  vx_core.t_stringlist
                )
              )
            )
          )
        )
    )
    return output
  }

  static f_is_map(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "is-map",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true\n (is-map (empty stringmap)))",
            ":testresult",
            vx_test.f_test_true(
              context,
              vx_collection.f_is_map(
                vx_core.f_empty(
                  vx_core.t_stringmap
                )
              )
            )
          )
        )
    )
    return output
  }

  static f_list_from_for_end_loop(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-for-end-loop",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (intlist 4 9)\n (list<-for-end-loop : intlist\n  2\n  3\n  (fn\n   [current : int]\n   (* current current))))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_core.t_intlist,
                4,
                9
              ),
              vx_collection.f_list_from_for_end_loop(
                {"any-1": vx_core.t_int, "list-1": vx_core.t_intlist},
                2,
                3,
                vx_core.f_new(vx_core.t_any_from_int, (current) => 
                  vx_core.f_multiply(current, current))
              )
            )
          )
        )
    )
    return output
  }

  static f_list_from_list_end(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-list-end",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (stringlist\n  \"a\" \"b\" \"c\")\n (list<-list-end\n  (stringlist\n   \"a\" \"b\" \"c\" \"d\")\n  3))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_core.t_stringlist,
                "a",
                "b",
                "c"
              ),
              vx_collection.f_list_from_list_end(
                {"any-1": vx_core.t_string, "list-1": vx_core.t_stringlist},
                vx_core.f_new(
                  vx_core.t_stringlist,
                  "a",
                  "b",
                  "c",
                  "d"
                ),
                3
              )
            )
          )
        )
    )
    return output
  }

  static f_list_from_list_filter(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-list-filter",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (stringlist\n  \"a1\" \"b1\" \"c1\" \"d1\")\n (list<-list-filter : stringlist\n  (list\n   \"a\" 4 \"b\" (list) \"c\" (map) \"d\")\n  (fn : string\n   [val : any]\n   (if\n    (then\n     (is-string val)\n     (string val \"1\"))))))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_core.t_stringlist,
                "a1",
                "b1",
                "c1",
                "d1"
              ),
              vx_collection.f_list_from_list_filter(
                {"any-1": vx_core.t_string, "list-1": vx_core.t_stringlist, "list-2": vx_core.t_list},
                vx_core.f_new(
                  vx_core.t_list,
                  "a",
                  4,
                  "b",
                  vx_core.f_empty(
                    vx_core.t_list
                  ),
                  "c",
                  vx_core.f_empty(
                    vx_core.t_map
                  ),
                  "d"
                ),
                vx_core.f_new(vx_core.t_any_from_any, (val) => 
                  vx_core.f_if_2(
                    {"any-1": vx_core.t_string},
                    vx_core.f_then(
                      vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_type.f_is_string(val)}),
                      vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
                        vx_core.t_string,
                        val,
                        "1"
                      )})
                    )
                  ))
              )
            )
          )
        )
    )
    return output
  }

  static f_list_from_list_filtertypes(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-list-filtertypes",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (list\n  \"a\" 1 \"b\" \"c\")\n (list<-list-filtertypes : list\n  (list\n   \"a\" 1 \"b\" \"c\" 4.5)\n  string int))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_core.t_list,
                "a",
                1,
                "b",
                "c"
              ),
              vx_collection.f_list_from_list_filtertypes(
                {"list-1": vx_core.t_list, "list-2": vx_core.t_list},
                vx_core.f_new(
                  vx_core.t_list,
                  "a",
                  1,
                  "b",
                  "c",
                  4.5
                ),
                vx_core.t_string,
                vx_core.t_int
              )
            )
          )
        )
    )
    return output
  }

  static f_list_from_list_start(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-list-start",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (stringlist\n  \"b\" \"c\" \"d\")\n (list<-list-start\n  (stringlist\n   \"a\" \"b\" \"c\" \"d\")\n  2))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_core.t_stringlist,
                "b",
                "c",
                "d"
              ),
              vx_collection.f_list_from_list_start(
                {"any-1": vx_core.t_string, "list-1": vx_core.t_stringlist},
                vx_core.f_new(
                  vx_core.t_stringlist,
                  "a",
                  "b",
                  "c",
                  "d"
                ),
                2
              )
            )
          )
        )
    )
    return output
  }

  static f_list_from_list_start_end(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-list-start-end",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (stringlist\n  \"b\" \"c\")\n (list<-list-start-end\n  (stringlist\n   \"a\" \"b\" \"c\" \"d\")\n  2 3))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_core.t_stringlist,
                "b",
                "c"
              ),
              vx_collection.f_list_from_list_start_end(
                {"any-1": vx_core.t_string, "list-1": vx_core.t_stringlist},
                vx_core.f_new(
                  vx_core.t_stringlist,
                  "a",
                  "b",
                  "c",
                  "d"
                ),
                2,
                3
              )
            )
          )
        )
    )
    return output
  }

  static f_stringlist_from_map(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "stringlist<-map",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (stringlist \"a\" \"b\")\n (stringlist<-map\n  (intmap\n   :a 1\n   :b 2)))",
            ":testresult",
            vx_test.f_test(
              context,
              vx_core.f_new(
                vx_core.t_stringlist,
                "a",
                "b"
              ),
              vx_collection.f_stringlist_from_map(
                vx_core.f_new(
                  vx_core.t_intmap,
                  ":a",
                  1,
                  ":b",
                  2
                )
              )
            )
          )
        )
    )
    return output
  }

  static test_cases(context) {
    const output = vx_core.f_new(
      vx_test.t_testcaselist,
      vx_collection_test.f_any_from_for_until_loop(context),
      vx_collection_test.f_any_from_for_while_loop(context),
      vx_collection_test.f_int_from_map_key(context),
      vx_collection_test.f_int_from_stringlist_find(context),
      vx_collection_test.f_is_list(context),
      vx_collection_test.f_is_map(context),
      vx_collection_test.f_list_from_for_end_loop(context),
      vx_collection_test.f_list_from_list_end(context),
      vx_collection_test.f_list_from_list_filter(context),
      vx_collection_test.f_list_from_list_filtertypes(context),
      vx_collection_test.f_list_from_list_start(context),
      vx_collection_test.f_list_from_list_start_end(context),
      vx_collection_test.f_stringlist_from_map(context)
    )
    return output
  }
}
