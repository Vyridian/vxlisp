'strict mode'

import vx_core from "../../src/vx/core.js"
import vx_test from "../../src/vx/test.js"

export default class vx_core_test {

  static test_package(context) {
    const testcaselist = vx_core_test.test_cases(context)
    const output = vx_core.f_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/core",
      ":caselist", testcaselist,
      ":coveragesummary", vx_core_test.test_coveragesummary(),
      ":coveragedetail", vx_core_test.test_coveragedetail()
    );
    return output;
  }

  static test_coveragesummary() {
    return vx_core.f_new(
      vx_test.t_testcoveragesummary,
      "testpkg",   "vx/core", 
      "constnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 14, ":tests", 2, ":total", 14), 
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 81, ":tests", 186, ":total", 228), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 45, ":tests", 57, ":total", 125), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 30, ":tests", 63, ":total", 205), 
      "typenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 6, ":tests", 4, ":total", 66)
    )
  }

  static test_coveragedetail() {
    return vx_core.f_new(
      vx_test.t_testcoveragedetail,
      "testpkg", "vx/core",
      "typemap",
        vx_core.f_new(
          vx_core.t_intmap,
          "any", 0,
          "any-async<-func", 0,
          "any<-anylist", 0,
          "anylist", 0,
          "anytype", 0,
          "arg", 0,
          "arglist", 0,
          "argmap", 0,
          "boolean", 4,
          "booleanlist", 0,
          "collection", 0,
          "compilelanguages", 0,
          "connect", 0,
          "connectlist", 0,
          "connectmap", 0,
          "const", 0,
          "constdef", 0,
          "constlist", 0,
          "constmap", 0,
          "context", 0,
          "decimal", 0,
          "error", 0,
          "float", 1,
          "func", 0,
          "funcdef", 0,
          "funclist", 0,
          "funcmap", 0,
          "int", 7,
          "intlist", 0,
          "intmap", 0,
          "list", 0,
          "listtype", 0,
          "map", 0,
          "maptype", 0,
          "mempool", 0,
          "msg", 0,
          "msgblock", 0,
          "msgblocklist", 0,
          "msglist", 0,
          "none", 0,
          "notype", 0,
          "number", 0,
          "numberlist", 0,
          "numbermap", 0,
          "package", 0,
          "packagemap", 0,
          "permission", 0,
          "permissionlist", 0,
          "permissionmap", 0,
          "security", 0,
          "session", 0,
          "setting", 0,
          "state", 0,
          "statelistener", 0,
          "string", 2,
          "stringlist", 0,
          "stringmap", 0,
          "struct", 0,
          "thenelse", 0,
          "thenelselist", 0,
          "type", 0,
          "typedef", 0,
          "typelist", 0,
          "typemap", 0,
          "user", 0,
          "value", 0
        ),
      "constmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "false", 1,
          "globalpackagemap", 0,
          "infinity", 0,
          "mempool-active", 0,
          "msg-error", 0,
          "msg-info", 0,
          "msg-severe", 0,
          "msg-warning", 0,
          "neginfinity", 0,
          "newline", 0,
          "notanumber", 0,
          "nothing", 0,
          "quote", 0,
          "true", 1
        ),
      "funcmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "!", 2,
          "!-empty", 0,
          "!-empty_1", 0,
          "!=", 2,
          "*", 2,
          "*_1", 2,
          "*_2", 2,
          "*_3", 2,
          "+", 2,
          "+_1", 2,
          "+_2", 0,
          "+_3", 0,
          "+1", 2,
          "-", 2,
          "-_1", 2,
          "-_2", 0,
          "-_3", 0,
          ".", 0,
          "/", 2,
          "<", 1,
          "<_1", 2,
          "<-", 1,
          "<<-", 1,
          "<=", 1,
          "<=_1", 1,
          "=", 5,
          "=_1", 1,
          ">", 1,
          ">_1", 1,
          ">=", 1,
          ">=_1", 1,
          "allowfuncs<-security", 0,
          "allowtypenames<-typedef", 0,
          "allowtypes<-typedef", 0,
          "and", 2,
          "and_1", 2,
          "any<-any", 0,
          "any<-any-async", 0,
          "any<-any-context", 0,
          "any<-any-context-async", 0,
          "any<-func", 0,
          "any<-func-async", 0,
          "any<-key-value", 0,
          "any<-key-value-async", 0,
          "any<-list", 2,
          "any<-list-reduce", 1,
          "any<-list-reduce-next", 0,
          "any<-map", 1,
          "any<-none", 0,
          "any<-none-async", 0,
          "any<-reduce", 0,
          "any<-reduce-async", 0,
          "any<-reduce-next", 0,
          "any<-reduce-next-async", 0,
          "any<-struct", 0,
          "async", 0,
          "boolean-permission<-func", 0,
          "boolean<-any", 0,
          "boolean<-func", 0,
          "boolean<-none", 0,
          "case", 0,
          "case_1", 0,
          "compare", 2,
          "contains", 2,
          "contains_1", 3,
          "context-main", 0,
          "copy", 0,
          "else", 0,
          "empty", 3,
          "extends<-any", 0,
          "extends<-typedef", 0,
          "first<-list", 1,
          "first<-list-fn-any<-any", 1,
          "fn", 0,
          "funcdef<-func", 0,
          "funcname<-funcdef", 0,
          "global-package-get", 0,
          "global-package-set", 0,
          "if", 2,
          "if_1", 2,
          "if_2", 1,
          "int<-func", 0,
          "int<-string", 6,
          "is-empty", 0,
          "is-empty_1", 3,
          "is-endswith", 0,
          "is-func", 0,
          "is-int", 0,
          "is-number", 3,
          "is-pass<-permission", 0,
          "last<-list", 1,
          "length<-list", 1,
          "let", 1,
          "let-async", 0,
          "list-join<-list", 0,
          "list<-list", 0,
          "list<-list-async", 0,
          "list<-map", 1,
          "list<-map-async", 0,
          "list<-type", 0,
          "log", 0,
          "main", 0,
          "map<-list", 1,
          "mempool-addref", 0,
          "mempool-release", 0,
          "mempool-removeref", 0,
          "mempool-removerefchildren", 0,
          "mempool-reserve", 0,
          "msg<-error", 0,
          "msgblock<-msgblock-msg", 0,
          "msgblock<-msgblock-msgblock", 0,
          "name<-typedef", 0,
          "native", 0,
          "native<-any", 0,
          "new", 6,
          "number<-func", 0,
          "or", 3,
          "or_1", 2,
          "packagename<-typedef", 0,
          "path<-context-path", 0,
          "path<-setting-path", 0,
          "permission<-id-context", 0,
          "properties<-typedef", 0,
          "proplast<-typedef", 0,
          "resolve", 1,
          "resolve_1", 1,
          "resolve-async", 1,
          "resolve-first", 0,
          "resolve-list", 0,
          "security<-context", 0,
          "security<-user", 0,
          "session<-context", 0,
          "setting<-context", 0,
          "string-repeat", 1,
          "string<-any", 6,
          "string<-any-indent", 0,
          "string<-func", 0,
          "switch", 1,
          "then", 0,
          "traits<-typedef", 0,
          "type<-any", 3,
          "typedef<-any", 0,
          "typedef<-type", 0,
          "typename<-any", 3,
          "typename<-type", 0,
          "typename<-typedef", 0,
          "typenames<-typelist", 0,
          "user<-context", 0
        )
    )
  }

  static t_boolean(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "boolean",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true true)",
            ":testresult", vx_test.f_test_true(
              true,
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-false false)",
            ":testresult", vx_test.f_test_false(
              false,
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (boolean true))",
            ":testresult", vx_test.f_test_true(
              vx_core.f_new(
                vx_core.t_boolean,
                true
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-false (boolean false))",
            ":testresult", vx_test.f_test_false(
              vx_core.f_new(
                vx_core.t_boolean,
                false
              ),
              context
            )
          )
        )
    )
    return output
  }

  static t_float(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "float",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 4.5 (float 4.5))",
            ":testresult", vx_test.f_test(
              4.5,
              vx_core.f_new(
                vx_core.t_float,
                4.5
              ),
              context
            )
          )
        )
    )
    return output
  }

  static t_int(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "int",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true  (is-int 4))",
            ":testresult", vx_test.f_test_true(
              vx_core.f_is_int(4),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true  (is-int \"4\"))",
            ":testresult", vx_test.f_test_true(
              vx_core.f_is_int("4"),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true  (is-int infinity))",
            ":testresult", vx_test.f_test_true(
              vx_core.f_is_int(
                vx_core.c_infinity
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true  (is-int neginfinity))",
            ":testresult", vx_test.f_test_true(
              vx_core.f_is_int(
                vx_core.c_neginfinity
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true  (is-int notanumber))",
            ":testresult", vx_test.f_test_true(
              vx_core.f_is_int(
                vx_core.c_notanumber
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-false (is-int \"a\"))",
            ":testresult", vx_test.f_test_false(
              vx_core.f_is_int("a"),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-false (is-int 5.5))",
            ":testresult", vx_test.f_test_false(
              vx_core.f_is_int(5.5),
              context
            )
          )
        )
    )
    return output
  }

  static t_string(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "string",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"a\" (string \"a\"))",
            ":testresult", vx_test.f_test(
              "a",
              vx_core.f_new(
                vx_core.t_string,
                "a"
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"ab\" (string \"a\" \"b\"))",
            ":testresult", vx_test.f_test(
              "ab",
              vx_core.f_new(
                vx_core.t_string,
                "a",
                "b"
              ),
              context
            )
          )
        )
    )
    return output
  }

  static c_false(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "false",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-false false)",
            ":testresult",
            vx_test.f_test_false(
                false,
                context
              )
          )
        )
    )
    return output
  }

  static c_true(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "true",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true true)",
            ":testresult",
            vx_test.f_test_true(
                true,
                context
              )
          )
        )
    )
    return output
  }

  static f_not(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "!",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-false false)",
            ":testresult",
            vx_test.f_test_false(
              false,
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-false (! true))",
            ":testresult",
            vx_test.f_test_false(
              vx_core.f_not(
                true
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_ne(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "!=",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-ne true false)",
            ":testresult",
            vx_test.f_test_ne(
              true,
              false,
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-ne \"a\" \"b\")",
            ":testresult",
            vx_test.f_test_ne("a", "b", context)
          )
        )
    )
    return output
  }

  static f_multiply(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "*",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 6 (* 3 2))",
            ":testresult",
            vx_test.f_test(
              6,
              vx_core.f_multiply(3, 2),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test -10 (* 5 -2))",
            ":testresult",
            vx_test.f_test(
              -10,
              vx_core.f_multiply(5, -2),
              context
            )
          )
        )
    )
    return output
  }

  static f_multiply_1(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "*",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 6.4 (* 3.2 2))",
            ":testresult",
            vx_test.f_test(
              6.4,
              vx_core.f_multiply_1(3.2, 2),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test -10.2 (* 5.1 -2))",
            ":testresult",
            vx_test.f_test(
              -10.2,
              vx_core.f_multiply_1(5.1, -2),
              context
            )
          )
        )
    )
    return output
  }

  static f_multiply_2(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "*",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 24 (* 3 2 4))",
            ":testresult",
            vx_test.f_test(
              24,
              vx_core.f_multiply_2(3, 2, 4),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test -20 (* 5 -2 2))",
            ":testresult",
            vx_test.f_test(
              -20,
              vx_core.f_multiply_2(5, -2, 2),
              context
            )
          )
        )
    )
    return output
  }

  static f_multiply_3(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "*",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 24 (* 3 2 4))",
            ":testresult",
            vx_test.f_test(
              24,
              vx_core.f_multiply_2(3, 2, 4),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test -20 (* 5 -2 2))",
            ":testresult",
            vx_test.f_test(
              -20,
              vx_core.f_multiply_2(5, -2, 2),
              context
            )
          )
        )
    )
    return output
  }

  static f_plus(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "+",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 5 (+ 2 3))",
            ":testresult",
            vx_test.f_test(
              5,
              vx_core.f_plus(2, 3),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 3 (+ 5 -2))",
            ":testresult",
            vx_test.f_test(
              3,
              vx_core.f_plus(5, -2),
              context
            )
          )
        )
    )
    return output
  }

  static f_plus_1(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "+",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 5 (+ 2  3))",
            ":testresult",
            vx_test.f_test(
              5,
              vx_core.f_plus(2, 3),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 3 (+ 5 -2))",
            ":testresult",
            vx_test.f_test(
              3,
              vx_core.f_plus(5, -2),
              context
            )
          )
        )
    )
    return output
  }

  static f_plus1(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "+1",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test  3 (+1  2))",
            ":testresult",
            vx_test.f_test(
              3,
              vx_core.f_plus1(2),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test -1 (+1 -2))",
            ":testresult",
            vx_test.f_test(
              -1,
              vx_core.f_plus1(-2),
              context
            )
          )
        )
    )
    return output
  }

  static f_minus(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "-",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 1 (- 3 2))",
            ":testresult",
            vx_test.f_test(
              1,
              vx_core.f_minus(3, 2),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 7 (- 5 -2))",
            ":testresult",
            vx_test.f_test(
              7,
              vx_core.f_minus(5, -2),
              context
            )
          )
        )
    )
    return output
  }

  static f_minus_1(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "-",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 5 (+ 2 3))",
            ":testresult",
            vx_test.f_test(
              5,
              vx_core.f_plus(2, 3),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 3 (+ 5 -2))",
            ":testresult",
            vx_test.f_test(
              3,
              vx_core.f_plus(5, -2),
              context
            )
          )
        )
    )
    return output
  }

  static f_divide(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "/",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 3 (/ 6 2))",
            ":testresult",
            vx_test.f_test(
              3,
              vx_core.f_divide(6, 2),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test -5 (/ 10 -2))",
            ":testresult",
            vx_test.f_test(
              -5,
              vx_core.f_divide(10, -2),
              context
            )
          )
        )
    )
    return output
  }

  static f_lt(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "<",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (< 2 3))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_lt(2, 3),
              context
            )
          )
        )
    )
    return output
  }

  static f_lt_1(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "<",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (< 2 3))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_lt(2, 3),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (< \"b\" \"d\" \"z\"))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_lt_1("b", "d", "z"),
              context
            )
          )
        )
    )
    return output
  }

  static f_chainfirst(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "<-",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (*\n  (+\n   (- 5 3)\n   3)\n  2)\n (<-\n  5\n  (- 3)\n  (+ 3)\n  (* 2)))",
            ":testresult",
            vx_test.f_test(
              vx_core.f_multiply(
                vx_core.f_plus(
                  vx_core.f_minus(5, 3),
                  3
                ),
                2
              ),
              vx_core.f_multiply(
                vx_core.f_plus(
                  vx_core.f_minus(5, 3),
                  3
                ),
                2
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_chainlast(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "<<-",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (* (+ (- 3 5) 3) 2)\n (<<-\n  5\n  (- 3)\n  (+ 3)\n  (* 2)))",
            ":testresult",
            vx_test.f_test(
              vx_core.f_multiply(
                vx_core.f_plus(
                  vx_core.f_minus(3, 5),
                  3
                ),
                2
              ),
              vx_core.f_multiply(
                2,
                vx_core.f_plus(
                  3,
                  vx_core.f_minus(3, 5)
                )
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_le(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "<=",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (<= 2 3))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_le(2, 3),
              context
            )
          )
        )
    )
    return output
  }

  static f_le_1(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "<=",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (<= \"b\" \"d\" \"z\"))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_le_1("b", "d", "z"),
              context
            )
          )
        )
    )
    return output
  }

  static f_eq(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "=",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (= true true))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_eq(
                true,
                true
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (= 2 2))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_eq(2, 2),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (= \"a\" \"a\"))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_eq("a", "a"),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (= (stringlist \"a\" \"b\" \"c\") (new stringlist \"a\" \"b\" \"c\")))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_eq(
                vx_core.f_new(
                  vx_core.t_stringlist,
                  "a",
                  "b",
                  "c"
                ),
                vx_core.f_new(
                  vx_core.t_stringlist,
                  "a",
                  "b",
                  "c"
                )
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (= (stringmap :a \"1\" :b \"2\") (new stringmap :a \"1\" :b \"2\")))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_eq(
                vx_core.f_new(
                  vx_core.t_stringmap,
                  ":a",
                  "1",
                  ":b",
                  "2"
                ),
                vx_core.f_new(
                  vx_core.t_stringmap,
                  ":a",
                  "1",
                  ":b",
                  "2"
                )
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_eq_1(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "=",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-false (= 2 2 3))",
            ":testresult",
            vx_test.f_test_false(
              vx_core.f_eq_1(2, 2, 3),
              context
            )
          )
        )
    )
    return output
  }

  static f_gt(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", ">",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (> 3 2))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_gt(3, 2),
              context
            )
          )
        )
    )
    return output
  }

  static f_gt_1(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", ">",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (> \"z\" \"y\" \"b\"))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_gt_1("z", "y", "b"),
              context
            )
          )
        )
    )
    return output
  }

  static f_ge(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", ">=",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (>= 3 2))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_ge(3, 2),
              context
            )
          )
        )
    )
    return output
  }

  static f_ge_1(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", ">=",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (>= \"z\" \"b\" \"b\"))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_ge_1("z", "b", "b"),
              context
            )
          )
        )
    )
    return output
  }

  static f_and(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "and",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (and true true))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_and(
                true,
                true
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-false (and true false))",
            ":testresult",
            vx_test.f_test_false(
              vx_core.f_and(
                true,
                false
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_and_1(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "and",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (and true true true))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_and_1(
                true,
                true,
                true
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-false (and true true false))",
            ":testresult",
            vx_test.f_test_false(
              vx_core.f_and_1(
                true,
                true,
                false
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_any_from_list(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "any<-list",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n \"b\"\n (any<-list (list \"a\" \"b\" \"c\") 1))",
            ":testresult",
            vx_test.f_test(
              "b",
              vx_core.f_any_from_list(
                {"any-1": vx_core.t_any, "list-1": vx_core.t_list},
                vx_core.f_new(
                  vx_core.t_list,
                  "a",
                  "b",
                  "c"
                ),
                1
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n \"b\"\n (:1 (stringlist \"a\" \"b\" \"c\")))",
            ":testresult",
            vx_test.f_test(
              "b",
              vx_core.f_any_from_list(
                {"any-1": vx_core.t_string, "list-1": vx_core.t_stringlist},
                vx_core.f_new(
                  vx_core.t_stringlist,
                  "a",
                  "b",
                  "c"
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

  static f_any_from_list_reduce(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "any<-list-reduce",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n 24\n (any<-list-reduce : int\n  (intlist 3 2 4)\n  1\n  (fn : int\n   [total : int\n    num   : int]\n   (* total num))\n ))",
            ":testresult",
            vx_test.f_test(
              24,
              vx_core.f_any_from_list_reduce(
                {"any-1": vx_core.t_int, "any-2": vx_core.t_int, "list-2": vx_core.t_intlist},
                vx_core.f_new(
                  vx_core.t_intlist,
                  3,
                  2,
                  4
                ),
                1,
                vx_core.f_new(vx_core.t_any_from_reduce, (total, num) => 
                  vx_core.f_multiply(total, num))
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_any_from_map(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "any<-map",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n \"v2\"\n (any<-map (map :a \"v1\" :b \"v2\" :c \"v3\") :b))",
            ":testresult",
            vx_test.f_test(
              "v2",
              vx_core.f_any_from_map(
                {"any-1": vx_core.t_any, "map-1": vx_core.t_map},
                vx_core.f_new(
                  vx_core.t_map,
                  ":a",
                  "v1",
                  ":b",
                  "v2",
                  ":c",
                  "v3"
                ),
                ":b"
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_compare(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "compare",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 1 (compare 3 2))",
            ":testresult",
            vx_test.f_test(
              1,
              vx_core.f_compare(3, 2),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 1 (compare \"z\" \"a\"))",
            ":testresult",
            vx_test.f_test(
              1,
              vx_core.f_compare("z", "a"),
              context
            )
          )
        )
    )
    return output
  }

  static f_contains(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "contains",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true  (contains \"abcde\" \"cd\"))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_contains("abcde", "cd"),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-false (contains \"abcde\" \"dc\"))",
            ":testresult",
            vx_test.f_test_false(
              vx_core.f_contains("abcde", "dc"),
              context
            )
          )
        )
    )
    return output
  }

  static f_contains_1(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "contains",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true  (contains (stringlist \"1\" \"2\" \"3\") \"2\"))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_contains_1(
                vx_core.f_new(
                  vx_core.t_stringlist,
                  "1",
                  "2",
                  "3"
                ),
                "2"
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true  (contains (intlist 1 2 3) 2))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_contains_1(
                vx_core.f_new(
                  vx_core.t_intlist,
                  1,
                  2,
                  3
                ),
                2
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-false (contains (list 1 \"2\" 3) 2))",
            ":testresult",
            vx_test.f_test_false(
              vx_core.f_contains_1(
                vx_core.f_new(
                  vx_core.t_list,
                  1,
                  "2",
                  3
                ),
                2
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_empty(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "empty",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"\"     (empty string))",
            ":testresult",
            vx_test.f_test(
              "",
              vx_core.f_empty(
                vx_core.t_string
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test (list) (empty list))",
            ":testresult",
            vx_test.f_test(
              vx_core.f_empty(
                vx_core.t_list
              ),
              vx_core.f_empty(
                vx_core.t_list
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test (map)  (empty map))",
            ":testresult",
            vx_test.f_test(
              vx_core.f_empty(
                vx_core.t_map
              ),
              vx_core.f_empty(
                vx_core.t_map
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_first_from_list(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "first<-list",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"b\" (first<-list (stringlist \"b\" \"c\")))",
            ":testresult",
            vx_test.f_test(
              "b",
              vx_core.f_first_from_list(
                {"any-1": vx_core.t_string, "list-1": vx_core.t_stringlist},
                vx_core.f_new(
                  vx_core.t_stringlist,
                  "b",
                  "c"
                )
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_first_from_list_fn_any_from_any(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "first<-list-fn-any<-any",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"b\" (first<-list-fn-any<-any (list nothing \"b\" \"c\") resolve))",
            ":testresult",
            vx_test.f_test(
              "b",
              vx_core.f_first_from_list_fn_any_from_any(
                {"any-1": vx_core.t_any, "list-1": vx_core.t_list},
                vx_core.f_new(
                  vx_core.t_list,
                  vx_core.c_nothing,
                  "b",
                  "c"
                ),
                vx_core.f_new(vx_core.t_any_from_any, vx_core.t_resolve)
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_if(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "if",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"a\" (if (= 2 2) \"a\"))",
            ":testresult",
            vx_test.f_test(
              "a",
              vx_core.f_if(
                {"any-1": vx_core.t_string},
                vx_core.f_eq(2, 2),
                "a"
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"\"  (if : string (= 1 2) \"a\"))",
            ":testresult",
            vx_test.f_test(
              "",
              vx_core.f_if(
                {"any-1": vx_core.t_string},
                vx_core.f_eq(1, 2),
                "a"
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_if_1(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "if",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"a\" (if (= 2 2) \"a\" \"b\"))",
            ":testresult",
            vx_test.f_test(
              "a",
              vx_core.f_if_1(
                {"any-1": vx_core.t_string},
                vx_core.f_eq(2, 2),
                "a",
                "b"
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"b\"  (if (= 1 2) \"a\" \"b\"))",
            ":testresult",
            vx_test.f_test(
              "b",
              vx_core.f_if_1(
                {"any-1": vx_core.t_string},
                vx_core.f_eq(1, 2),
                "a",
                "b"
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_if_2(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "if",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true\n (if\n  (then (= 2 3) false)\n  (then (!= 3 3) false)\n  (else (! false))))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_if_2(
                {"any-1": vx_core.t_any},
                vx_core.f_then(
                  vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq(2, 3)}),
                  vx_core.f_new(vx_core.t_any_from_func, () => {return false})
                ),
                vx_core.f_then(
                  vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_ne(3, 3)}),
                  vx_core.f_new(vx_core.t_any_from_func, () => {return false})
                ),
                vx_core.f_else(
                  vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_not(
                    false
                  )})
                )
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_int_from_string(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "int<-string",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 4 (int<-string \"4\"))",
            ":testresult",
            vx_test.f_test(
              4,
              vx_core.f_int_from_string("4"),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 5 (int<-string \"5.4\"))",
            ":testresult",
            vx_test.f_test(
              5,
              vx_core.f_int_from_string("5.4"),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 5 (int<-string \"5.9\"))",
            ":testresult",
            vx_test.f_test(
              5,
              vx_core.f_int_from_string("5.9"),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test notanumber  (int<-string \"notanumber\"))",
            ":testresult",
            vx_test.f_test(
              vx_core.c_notanumber,
              vx_core.f_int_from_string("notanumber"),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test infinity    (int<-string \"infinity\"))",
            ":testresult",
            vx_test.f_test(
              vx_core.c_infinity,
              vx_core.f_int_from_string("infinity"),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test neginfinity (int<-string \"neginfinity\"))",
            ":testresult",
            vx_test.f_test(
              vx_core.c_neginfinity,
              vx_core.f_int_from_string("neginfinity"),
              context
            )
          )
        )
    )
    return output
  }

  static f_is_empty_1(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "is-empty",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (is-empty \"\"))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_is_empty(""),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (is-empty (list)))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_is_empty_1(
                vx_core.f_empty(
                  vx_core.t_list
                )
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (is-empty (map)))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_is_empty_1(
                vx_core.f_empty(
                  vx_core.t_map
                )
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_is_number(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "is-number",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true  (is-number 5))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_is_number(5),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true  (is-number 5.5))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_is_number(5.5),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-false (is-number \"a\"))",
            ":testresult",
            vx_test.f_test_false(
              vx_core.f_is_number("a"),
              context
            )
          )
        )
    )
    return output
  }

  static f_last_from_list(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "last<-list",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"c\" (last<-list (list \"b\" \"c\")))",
            ":testresult",
            vx_test.f_test(
              "c",
              vx_core.f_last_from_list(
                {"any-1": vx_core.t_any, "list-1": vx_core.t_list},
                vx_core.f_new(
                  vx_core.t_list,
                  "b",
                  "c"
                )
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_length_from_list(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "length<-list",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 3 (length<-list (stringlist \"a\" \"b\" \"c\")))",
            ":testresult",
            vx_test.f_test(
              3,
              vx_core.f_length_from_list(
                vx_core.f_new(
                  vx_core.t_stringlist,
                  "a",
                  "b",
                  "c"
                )
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_let(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "let",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n 7\n (let\n  [v1 : int := 2\n   v2 : int := (+ v1 3)]\n  (+ v1 v2)))",
            ":testresult",
            vx_test.f_test(
              7,
              vx_core.f_let(
                {"any-1": vx_core.t_int},
                [],
                vx_core.f_new(vx_core.t_any_from_func, () => {
                  const v1 = 2
                  const v2 = vx_core.f_plus(v1, 3)
                  return vx_core.f_plus(v1, v2)
                })
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_list_from_map(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "list<-map",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (stringlist \"a1\" \"b2\")\n (list<-map : stringlist\n  (stringmap \"a\" \"1\" \"b\" \"2\")\n  (fn : string\n   [key : string\n    val : string]\n   (string key val))))",
            ":testresult",
            vx_test.f_test(
              vx_core.f_new(
                vx_core.t_stringlist,
                "a1",
                "b2"
              ),
              vx_core.f_list_from_map(
                {"any-1": vx_core.t_string, "any-2": vx_core.t_string, "list-1": vx_core.t_stringlist, "map-2": vx_core.t_stringmap},
                vx_core.f_new(
                  vx_core.t_stringmap,
                  "a",
                  "1",
                  "b",
                  "2"
                ),
                vx_core.f_new(vx_core.t_any_from_key_value, ([key, val]) => 
                  vx_core.f_new(
                    vx_core.t_string,
                    key,
                    val
                  ))
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_map_from_list(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "map<-list",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (stringmap\n  \"keya\" \"a\"\n  \"keyb\" \"b\")\n (map<-list : stringmap\n  (stringlist \"a\" \"b\")\n  (fn : string\n   [val : string]\n   (string \"key\" val))))",
            ":testresult",
            vx_test.f_test(
              vx_core.f_new(
                vx_core.t_stringmap,
                "keya",
                "a",
                "keyb",
                "b"
              ),
              vx_core.f_map_from_list(
                {"any-1": vx_core.t_string, "any-2": vx_core.t_string, "list-2": vx_core.t_stringlist, "map-1": vx_core.t_stringmap},
                vx_core.f_new(
                  vx_core.t_stringlist,
                  "a",
                  "b"
                ),
                vx_core.f_new(vx_core.t_any_from_any, (val) => 
                  vx_core.f_new(
                    vx_core.t_string,
                    "key",
                    val
                  ))
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_new(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "new",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test true (new boolean true))",
            ":testresult",
            vx_test.f_test(
              true,
              vx_core.f_new(
                vx_core.t_boolean,
                true
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 4 (new int 4))",
            ":testresult",
            vx_test.f_test(
              4,
              vx_core.f_new(
                vx_core.t_int,
                4
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 5.4 (new float 5.4))",
            ":testresult",
            vx_test.f_test(
              5.4,
              vx_core.f_new(
                vx_core.t_float,
                5.4
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"a\" (new string \"a\"))",
            ":testresult",
            vx_test.f_test(
              "a",
              vx_core.f_new(
                vx_core.t_string,
                "a"
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (stringlist \"a\" \"b\" \"c\")\n (new stringlist \"a\" \"b\" \"c\"))",
            ":testresult",
            vx_test.f_test(
              vx_core.f_new(
                vx_core.t_stringlist,
                "a",
                "b",
                "c"
              ),
              vx_core.f_new(
                vx_core.t_stringlist,
                "a",
                "b",
                "c"
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n (stringmap :a \"1\" :b \"2\")\n (new stringmap :a \"1\" :b \"2\"))",
            ":testresult",
            vx_test.f_test(
              vx_core.f_new(
                vx_core.t_stringmap,
                ":a",
                "1",
                ":b",
                "2"
              ),
              vx_core.f_new(
                vx_core.t_stringmap,
                ":a",
                "1",
                ":b",
                "2"
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_or(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "or",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (or true true))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_or(
                true,
                true
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (or true false))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_or(
                true,
                false
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-false (or false false))",
            ":testresult",
            vx_test.f_test_false(
              vx_core.f_or(
                false,
                false
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_or_1(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "or",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (or false true false))",
            ":testresult",
            vx_test.f_test_true(
              vx_core.f_or_1(
                false,
                true,
                false
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-false (or false false false))",
            ":testresult",
            vx_test.f_test_false(
              vx_core.f_or_1(
                false,
                false,
                false
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_resolve(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "resolve",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"a\" (resolve \"a\"))",
            ":testresult",
            vx_test.f_test(
              "a",
              vx_core.f_resolve({"any-1": vx_core.t_string}, "a"),
              context
            )
          )
        )
    )
    return output
  }

  static f_resolve_1(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "resolve",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 4 (resolve (fn : int [] (+ 1 3))))",
            ":testresult",
            vx_test.f_test(
              4,
              vx_core.f_resolve_1(
                {"any-1": vx_core.t_int},
                vx_core.f_new(vx_core.t_any_from_func, () => 
                  vx_core.f_plus(1, 3))
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_resolve_async(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "resolve-async",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 4 (resolve : int (fn : int [] (+ 1 3))))",
            ":testresult",
            vx_test.f_test(
              4,
              vx_core.f_resolve_1(
                {"any-1": vx_core.t_int},
                vx_core.f_new(vx_core.t_any_from_func, () => 
                  vx_core.f_plus(1, 3))
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_string_repeat(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "string-repeat",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"abab\" (string-repeat \"ab\" 2))",
            ":testresult",
            vx_test.f_test(
              "abab",
              vx_core.f_string_repeat("ab", 2),
              context
            )
          )
        )
    )
    return output
  }

  static f_string_from_any(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "string<-any",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"true\"  (string<-any true))",
            ":testresult",
            vx_test.f_test(
              "true",
              vx_core.f_string_from_any(
                true
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"4\"     (string<-any 4))",
            ":testresult",
            vx_test.f_test(
              "4",
              vx_core.f_string_from_any(4),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"5.4\"   (string<-any 5.4))",
            ":testresult",
            vx_test.f_test(
              "5.4",
              vx_core.f_string_from_any(5.4),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"\\\"a\\\"\" (string<-any \"a\"))",
            ":testresult",
            vx_test.f_test(
              "\"a\"",
              vx_core.f_string_from_any("a"),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n \"(stringlist\n   \\\"a\\\"\n   \\\"b\\\"\n   \\\"c\\\")\"\n (string<-any (stringlist \"a\" \"b\" \"c\")))",
            ":testresult",
            vx_test.f_test(
              "(stringlist\n \"a\"\n \"b\"\n \"c\")",
              vx_core.f_string_from_any(
                vx_core.f_new(
                  vx_core.t_stringlist,
                  "a",
                  "b",
                  "c"
                )
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n \"(stringmap\n   :a \\\"1\\\"\n   :b \\\"2\\\")\"\n (string<-any (stringmap :a \"1\" :b \"2\")))",
            ":testresult",
            vx_test.f_test(
              "(stringmap\n :a \"1\"\n :b \"2\")",
              vx_core.f_string_from_any(
                vx_core.f_new(
                  vx_core.t_stringmap,
                  ":a",
                  "1",
                  ":b",
                  "2"
                )
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_switch(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "switch",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 1\n (switch : int\n  \"d\"\n  (case (list \"b\" \"c\" \"d\") 1)\n  (else 2)))",
            ":testresult",
            vx_test.f_test(
              1,
              vx_core.f_switch(
                {"any-1": vx_core.t_int, "any-2": vx_core.t_string},
                "d",
                vx_core.f_case(
                  vx_core.f_new(
                    vx_core.t_list,
                    "b",
                    "c",
                    "d"
                  ),
                  vx_core.f_new(vx_core.t_any_from_func, () => {return 1})
                ),
                vx_core.f_else(vx_core.f_new(vx_core.t_any_from_func, () => {return 2}))
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_type_from_any(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "type<-any",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test boolean (type<-any false))",
            ":testresult",
            vx_test.f_test(
              vx_core.t_boolean,
              vx_core.f_type_from_any(
                false
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test int (type<-any 5))",
            ":testresult",
            vx_test.f_test(
              vx_core.t_int,
              vx_core.f_type_from_any(5),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test string (type<-any \"a\"))",
            ":testresult",
            vx_test.f_test(
              vx_core.t_string,
              vx_core.f_type_from_any("a"),
              context
            )
          )
        )
    )
    return output
  }

  static f_typename_from_any(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/core",
      ":casename", "typename<-any",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"vx/core/boolean\" (typename<-any false))",
            ":testresult",
            vx_test.f_test(
              "vx/core/boolean",
              vx_core.f_typename_from_any(
                false
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"vx/core/int\"     (typename<-any 5))",
            ":testresult",
            vx_test.f_test(
              "vx/core/int",
              vx_core.f_typename_from_any(5),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"vx/core/string\"  (typename<-any \"a\"))",
            ":testresult",
            vx_test.f_test(
              "vx/core/string",
              vx_core.f_typename_from_any("a"),
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
      vx_core_test.t_boolean(),
      vx_core_test.t_float(),
      vx_core_test.t_int(),
      vx_core_test.t_string(),
      vx_core_test.c_false(),
      vx_core_test.c_true(),
      vx_core_test.f_not(context),
      vx_core_test.f_ne(context),
      vx_core_test.f_multiply(context),
      vx_core_test.f_multiply_1(context),
      vx_core_test.f_multiply_2(context),
      vx_core_test.f_multiply_3(context),
      vx_core_test.f_plus(context),
      vx_core_test.f_plus_1(context),
      vx_core_test.f_plus1(context),
      vx_core_test.f_minus(context),
      vx_core_test.f_minus_1(context),
      vx_core_test.f_divide(context),
      vx_core_test.f_lt(context),
      vx_core_test.f_lt_1(context),
      vx_core_test.f_chainfirst(context),
      vx_core_test.f_chainlast(context),
      vx_core_test.f_le(context),
      vx_core_test.f_le_1(context),
      vx_core_test.f_eq(context),
      vx_core_test.f_eq_1(context),
      vx_core_test.f_gt(context),
      vx_core_test.f_gt_1(context),
      vx_core_test.f_ge(context),
      vx_core_test.f_ge_1(context),
      vx_core_test.f_and(context),
      vx_core_test.f_and_1(context),
      vx_core_test.f_any_from_list(context),
      vx_core_test.f_any_from_list_reduce(context),
      vx_core_test.f_any_from_map(context),
      vx_core_test.f_compare(context),
      vx_core_test.f_contains(context),
      vx_core_test.f_contains_1(context),
      vx_core_test.f_empty(context),
      vx_core_test.f_first_from_list(context),
      vx_core_test.f_first_from_list_fn_any_from_any(context),
      vx_core_test.f_if(context),
      vx_core_test.f_if_1(context),
      vx_core_test.f_if_2(context),
      vx_core_test.f_int_from_string(context),
      vx_core_test.f_is_empty_1(context),
      vx_core_test.f_is_number(context),
      vx_core_test.f_last_from_list(context),
      vx_core_test.f_length_from_list(context),
      vx_core_test.f_let(context),
      vx_core_test.f_list_from_map(context),
      vx_core_test.f_map_from_list(context),
      vx_core_test.f_new(context),
      vx_core_test.f_or(context),
      vx_core_test.f_or_1(context),
      vx_core_test.f_resolve(context),
      vx_core_test.f_resolve_1(context),
      vx_core_test.f_resolve_async(context),
      vx_core_test.f_string_repeat(context),
      vx_core_test.f_string_from_any(context),
      vx_core_test.f_switch(context),
      vx_core_test.f_type_from_any(context),
      vx_core_test.f_typename_from_any(context)
    )
    return output
  }

}
