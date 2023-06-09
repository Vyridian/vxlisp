'strict mode'

import vx_type from "../../src/vx/type.js"
import vx_core from "../../src/vx/core.js"
import vx_test from "../../src/vx/test.js"

export default class vx_type_test {

  static test_package(context) {
    const testcaselist = vx_type_test.test_cases(context)
    const output = vx_core.f_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/type",
      ":caselist", testcaselist,
      ":coveragesummary", vx_type_test.test_coveragesummary(),
      ":coveragedetail", vx_type_test.test_coveragedetail()
    );
    return output;
  }

  static test_coveragesummary() {
    return vx_core.f_new(
      vx_test.t_testcoveragesummary,
      "testpkg",   "vx/type", 
      "constnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 61, ":tests", 11, ":total", 18), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 50, ":tests", 9, ":total", 18), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 50, ":tests", 9, ":total", 18), 
      "typenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0)
    )
  }

  static test_coveragedetail() {
    return vx_core.f_new(
      vx_test.t_testcoveragedetail,
      "testpkg", "vx/type",
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
          "allowtypenames<-type", 0,
          "allowtypes<-type", 0,
          "is-boolean", 0,
          "is-decimal", 0,
          "is-float", 0,
          "is-none", 0,
          "is-string", 4,
          "is-type", 4,
          "is-type<-any-typelist", 4,
          "length<-string", 2,
          "string<-int", 5,
          "string<-string-end", 2,
          "string<-string-start", 2,
          "string<-string-start-end", 4,
          "string<-stringlist-join", 1,
          "traitnames<-any", 0,
          "traits<-any", 0,
          "traits<-typedef", 0
        )
    )
  }

  static f_is_string(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "is-string",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true  (is-string \"\"))",
            ":testresult",
            vx_test.f_test_true(
              vx_type.f_is_string(""),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true  (is-string \"a\"))",
            ":testresult",
            vx_test.f_test_true(
              vx_type.f_is_string("a"),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-false (is-string 5))",
            ":testresult",
            vx_test.f_test_false(
              vx_type.f_is_string(5),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-false (is-string (list)))",
            ":testresult",
            vx_test.f_test_false(
              vx_type.f_is_string(
                vx_core.f_empty(
                  vx_core.t_list
                )
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_is_type(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "is-type",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (is-type false boolean))",
            ":testresult",
            vx_test.f_test_true(
              vx_type.f_is_type(
                false,
                vx_core.t_boolean
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (is-type \"a\"   string))",
            ":testresult",
            vx_test.f_test_true(
              vx_type.f_is_type(
                "a",
                vx_core.t_string
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (is-type 5.5   number))",
            ":testresult",
            vx_test.f_test_true(
              vx_type.f_is_type(
                5.5,
                vx_core.t_number
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true (is-type 4     int))",
            ":testresult",
            vx_test.f_test_true(
              vx_type.f_is_type(
                4,
                vx_core.t_int
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_is_type_from_any_typelist(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "is-type<-any-typelist",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true\n (is-type<-any-typelist\n  false (typelist int boolean)))",
            ":testresult",
            vx_test.f_test_true(
              vx_type.f_is_type_from_any_typelist(
                false,
                vx_core.f_new(
                  vx_core.t_typelist,
                  vx_core.t_int,
                  vx_core.t_boolean
                )
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true\n (is-type<-any-typelist\n  \"a\"   (typelist number string)))",
            ":testresult",
            vx_test.f_test_true(
              vx_type.f_is_type_from_any_typelist(
                "a",
                vx_core.f_new(
                  vx_core.t_typelist,
                  vx_core.t_number,
                  vx_core.t_string
                )
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true\n (is-type<-any-typelist\n  5.5   (typelist string number)))",
            ":testresult",
            vx_test.f_test_true(
              vx_type.f_is_type_from_any_typelist(
                5.5,
                vx_core.f_new(
                  vx_core.t_typelist,
                  vx_core.t_string,
                  vx_core.t_number
                )
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test-true\n (is-type<-any-typelist\n  4     (typelist string int)))",
            ":testresult",
            vx_test.f_test_true(
              vx_type.f_is_type_from_any_typelist(
                4,
                vx_core.f_new(
                  vx_core.t_typelist,
                  vx_core.t_string,
                  vx_core.t_int
                )
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_length_from_string(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "length<-string",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 4 (length<-string \"abcd\"))",
            ":testresult",
            vx_test.f_test(
              4,
              vx_type.f_length_from_string("abcd"),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test 0 (length<-string \"\"))",
            ":testresult",
            vx_test.f_test(
              0,
              vx_type.f_length_from_string(""),
              context
            )
          )
        )
    )
    return output
  }

  static f_string_from_int(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-int",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"4\"           (string<-int 4))",
            ":testresult",
            vx_test.f_test(
              "4",
              vx_type.f_string_from_int(4),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"51\"          (string<-int 51))",
            ":testresult",
            vx_test.f_test(
              "51",
              vx_type.f_string_from_int(51),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"notanumber\"  (string<-int notanumber))",
            ":testresult",
            vx_test.f_test(
              "notanumber",
              vx_type.f_string_from_int(
                vx_core.c_notanumber
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"infinity\"    (string<-int infinity))",
            ":testresult",
            vx_test.f_test(
              "infinity",
              vx_type.f_string_from_int(
                vx_core.c_infinity
              ),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"neginfinity\" (string<-int neginfinity))",
            ":testresult",
            vx_test.f_test(
              "neginfinity",
              vx_type.f_string_from_int(
                vx_core.c_neginfinity
              ),
              context
            )
          )
        )
    )
    return output
  }

  static f_string_from_string_end(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-string-end",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"abc\" (string<-string-end \"abcd\" 3))",
            ":testresult",
            vx_test.f_test(
              "abc",
              vx_type.f_string_from_string_end("abcd", 3),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"ab\"  (string<-string-end \"abcd\" 2))",
            ":testresult",
            vx_test.f_test(
              "ab",
              vx_type.f_string_from_string_end("abcd", 2),
              context
            )
          )
        )
    )
    return output
  }

  static f_string_from_string_start(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-string-start",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"abcd\" (string<-string-start \"abcd\" 0))",
            ":testresult",
            vx_test.f_test(
              "abcd",
              vx_type.f_string_from_string_start("abcd", 0),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"bcd\"  (string<-string-start \"abcd\" 1))",
            ":testresult",
            vx_test.f_test(
              "bcd",
              vx_type.f_string_from_string_start("abcd", 1),
              context
            )
          )
        )
    )
    return output
  }

  static f_string_from_string_start_end(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-string-start-end",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"abc\" (string<-string-start-end \"abcd\" 0 3))",
            ":testresult",
            vx_test.f_test(
              "abc",
              vx_type.f_string_from_string_start_end("abcd", 0, 3),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"bc\"  (string<-string-start-end \"abcd\" 1 3))",
            ":testresult",
            vx_test.f_test(
              "bc",
              vx_type.f_string_from_string_start_end("abcd", 1, 3),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"\"    (string<-string-start-end \"abcd\" 5 6))",
            ":testresult",
            vx_test.f_test(
              "",
              vx_type.f_string_from_string_start_end("abcd", 5, 6),
              context
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"bcd\" (string<-string-start-end \"abcd\" 1 5))",
            ":testresult",
            vx_test.f_test(
              "bcd",
              vx_type.f_string_from_string_start_end("abcd", 1, 5),
              context
            )
          )
        )
    )
    return output
  }

  static f_string_from_stringlist_join(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-stringlist-join",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test \"a$b$c\" (string<-stringlist-join (stringlist \"a\" \"b\" \"c\") \"$\"))",
            ":testresult",
            vx_test.f_test(
              "a$b$c",
              vx_type.f_string_from_stringlist_join(
                vx_core.f_new(
                  vx_core.t_stringlist,
                  "a",
                  "b",
                  "c"
                ),
                "$"
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
      vx_type_test.f_is_string(context),
      vx_type_test.f_is_type(context),
      vx_type_test.f_is_type_from_any_typelist(context),
      vx_type_test.f_length_from_string(context),
      vx_type_test.f_string_from_int(context),
      vx_type_test.f_string_from_string_end(context),
      vx_type_test.f_string_from_string_start(context),
      vx_type_test.f_string_from_string_start_end(context),
      vx_type_test.f_string_from_stringlist_join(context)
    )
    return output
  }

}
