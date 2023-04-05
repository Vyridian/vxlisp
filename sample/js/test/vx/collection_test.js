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
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 7, ":total", 7), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 71, ":tests", 5, ":total", 7), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 71, ":tests", 5, ":total", 7), 
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
          "is-list", 0,
          "is-map", 0,
          "list<-list-end", 1,
          "list<-list-filtertypes", 1,
          "list<-list-fn-filter", 1,
          "list<-list-start", 1,
          "list<-list-start-end", 1
        )
    )
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
            ":describename", "(test\n (stringlist \"a\" \"b\" \"c\")\n (list<-list-end\n  (stringlist \"a\" \"b\" \"c\" \"d\")\n  3))",
            ":testresult",
            vx_test.f_test(
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
              ),
              context
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
            ":describename", "(test\n (list \"a\" 1 \"b\" \"c\")\n (list<-list-filtertypes : list\n  (list \"a\" 1 \"b\" \"c\" 4.5)\n  string int))",
            ":testresult",
            vx_test.f_test(
              vx_core.f_new(
                vx_core.t_list,
                "a",
                1,
                "b",
                "c"
              ),
              vx_collection.f_list_from_list_filtertypes(
                {"any-1": vx_core.t_any, "any-2": vx_core.t_any, "list-1": vx_core.t_list, "list-2": vx_core.t_list},
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
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_list_from_list_fn_filter(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/collection",
      ":casename", "list<-list-fn-filter",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (stringlist \"a1\" \"b1\" \"c1\" \"d1\")\n (list<-list-fn-filter : stringlist\n  (list \"a\" 4 \"b\" (list) \"c\" (map) \"d\")\n  (fn : string\n   [val : any]\n   (if\n    (then\n     (is-string val)\n     (string val \"1\"))))))",
            ":testresult",
            vx_test.f_test(
              vx_core.f_new(
                vx_core.t_stringlist,
                "a1",
                "b1",
                "c1",
                "d1"
              ),
              vx_collection.f_list_from_list_fn_filter(
                {"any-1": vx_core.t_string, "any-2": vx_core.t_any, "list-1": vx_core.t_stringlist, "list-2": vx_core.t_list},
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
              ),
              context
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
            ":describename", "(test\n (stringlist \"b\" \"c\" \"d\")\n (list<-list-start\n  (stringlist \"a\" \"b\" \"c\" \"d\")\n  1))",
            ":testresult",
            vx_test.f_test(
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
                1
              ),
              context
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
            ":describename", "(test\n (stringlist \"b\" \"c\")\n (list<-list-start-end\n  (stringlist \"a\" \"b\" \"c\" \"d\")\n  1 3))",
            ":testresult",
            vx_test.f_test(
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
                1,
                3
              ),
              context
            )
          )
        )
    )
    return output
  }

  static test_cases(context) {
    const output = vx_core.f_new(
      vx_test.t_testcaselist,
      vx_collection_test.f_list_from_list_end(context),
      vx_collection_test.f_list_from_list_filtertypes(context),
      vx_collection_test.f_list_from_list_fn_filter(context),
      vx_collection_test.f_list_from_list_start(context),
      vx_collection_test.f_list_from_list_start_end(context)
    )
    return output
  }

}
