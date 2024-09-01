
package com.vxlisp.vx

object vx_typeTest {

  fun f_boolean_from_string_ends(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "boolean<-string-ends",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test-true\n (boolean<-string-ends\n  \"abcd\"\n  \"cd\"))",
          ":testresult",
            vx_test.f_test_true(
              context,
              vx_type.f_boolean_from_string_ends(
                vx_core.vx_new_string("abcd"),
                vx_core.vx_new_string("cd")
              )
            )
        )
      )
    )
    return output
  }

  fun f_boolean_from_string_starts(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "boolean<-string-starts",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test-true\n (boolean<-string-starts\n  \"abcd\"\n  \"ab\"))",
          ":testresult",
            vx_test.f_test_true(
              context,
              vx_type.f_boolean_from_string_starts(
                vx_core.vx_new_string("abcd"),
                vx_core.vx_new_string("ab")
              )
            )
        )
      )
    )
    return output
  }

  fun f_int_from_string_find(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "int<-string-find",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n 3\n (int<-string-find\n  \"abcdcdg\"\n  \"cd\"))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_int(3),
              vx_type.f_int_from_string_find(
                vx_core.vx_new_string("abcdcdg"),
                vx_core.vx_new_string("cd")
              )
            )
        )
      )
    )
    return output
  }

  fun f_int_from_string_findkeyword(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "int<-string-findkeyword",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n 3\n (int<-string-findkeyword\n  \"ab\tcdefg\"\n  \":whitespace\"))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_int(3),
              vx_type.f_int_from_string_findkeyword(
                vx_core.vx_new_string("ab\tcdefg"),
                vx_core.vx_new_string(":whitespace")
              )
            )
        ),
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n 5\n (int<-string-findkeyword\n  \" \t\n\rab\"\n  \":nonwhitespace\"))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_int(5),
              vx_type.f_int_from_string_findkeyword(
                vx_core.vx_new_string(" \t\n\rab"),
                vx_core.vx_new_string(":nonwhitespace")
              )
            )
        )
      )
    )
    return output
  }

  fun f_int_from_string_findlast(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "int<-string-findlast",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n 5\n (int<-string-findlast\n  \"abcdcdg\"\n  \"cd\"))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_int(5),
              vx_type.f_int_from_string_findlast(
                vx_core.vx_new_string("abcdcdg"),
                vx_core.vx_new_string("cd")
              )
            )
        )
      )
    )
    return output
  }

  fun f_is_string(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "is-string",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test-true\n (is-string \"\"))",
          ":testresult",
            vx_test.f_test_true(
              context,
              vx_type.f_is_string(
                vx_core.vx_new_string("")
              )
            )
        ),
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test-true\n (is-string \"a\"))",
          ":testresult",
            vx_test.f_test_true(
              context,
              vx_type.f_is_string(
                vx_core.vx_new_string("a")
              )
            )
        ),
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test-false\n (is-string 5))",
          ":testresult",
            vx_test.f_test_false(
              context,
              vx_type.f_is_string(
                vx_core.vx_new_int(5)
              )
            )
        ),
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test-false\n (is-string (list)))",
          ":testresult",
            vx_test.f_test_false(
              context,
              vx_type.f_is_string(
                vx_core.f_empty(
                  vx_core.t_list
                )
              )
            )
        )
      )
    )
    return output
  }

  fun f_is_type(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "is-type",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test-true\n (is-type false boolean))",
          ":testresult",
            vx_test.f_test_true(
              context,
              vx_type.f_is_type(
                vx_core.vx_new_boolean(false),
                vx_core.t_boolean
              )
            )
        ),
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test-true\n (is-type \"a\" string))",
          ":testresult",
            vx_test.f_test_true(
              context,
              vx_type.f_is_type(
                vx_core.vx_new_string("a"),
                vx_core.t_string
              )
            )
        ),
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test-true\n (is-type 5.5 number))",
          ":testresult",
            vx_test.f_test_true(
              context,
              vx_type.f_is_type(
                vx_core.vx_new_decimal("5.5"),
                vx_core.t_number
              )
            )
        ),
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test-true\n (is-type 4 int))",
          ":testresult",
            vx_test.f_test_true(
              context,
              vx_type.f_is_type(
                vx_core.vx_new_int(4),
                vx_core.t_int
              )
            )
        )
      )
    )
    return output
  }

  fun f_is_type_from_any_typelist(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "is-type<-any-typelist",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test-true\n (is-type<-any-typelist\n  false\n  (typelist int boolean)))",
          ":testresult",
            vx_test.f_test_true(
              context,
              vx_type.f_is_type_from_any_typelist(
                vx_core.vx_new_boolean(false),
                vx_core.f_new(
                  vx_core.t_typelist,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.t_int,
                    vx_core.t_boolean
                  )
                )
              )
            )
        ),
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test-true\n (is-type<-any-typelist\n  \"a\"\n  (typelist number string)))",
          ":testresult",
            vx_test.f_test_true(
              context,
              vx_type.f_is_type_from_any_typelist(
                vx_core.vx_new_string("a"),
                vx_core.f_new(
                  vx_core.t_typelist,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.t_number,
                    vx_core.t_string
                  )
                )
              )
            )
        ),
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test-true\n (is-type<-any-typelist\n  5.5\n  (typelist string number)))",
          ":testresult",
            vx_test.f_test_true(
              context,
              vx_type.f_is_type_from_any_typelist(
                vx_core.vx_new_decimal("5.5"),
                vx_core.f_new(
                  vx_core.t_typelist,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.t_string,
                    vx_core.t_number
                  )
                )
              )
            )
        ),
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test-true\n (is-type<-any-typelist\n  4\n  (typelist string int)))",
          ":testresult",
            vx_test.f_test_true(
              context,
              vx_type.f_is_type_from_any_typelist(
                vx_core.vx_new_int(4),
                vx_core.f_new(
                  vx_core.t_typelist,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.t_string,
                    vx_core.t_int
                  )
                )
              )
            )
        )
      )
    )
    return output
  }

  fun f_string_lowercase(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string-lowercase",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n \"abc\"\n (string-lowercase\n  \"AbC\"))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_string("abc"),
              vx_type.f_string_lowercase(
                vx_core.vx_new_string("AbC")
              )
            )
        )
      )
    )
    return output
  }

  fun f_string_outdent(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string-outdent",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n \"ab\"\n (string-outdent\n  \"ab\"))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_string("ab"),
              vx_type.f_string_outdent(
                vx_core.vx_new_string("ab")
              )
            )
        ),
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n \"a\nb\"\n (string-outdent\n  \"\n a\n b\"))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_string("a\nb"),
              vx_type.f_string_outdent(
                vx_core.vx_new_string("\n a\n b")
              )
            )
        )
      )
    )
    return output
  }

  fun f_string_trim(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string-trim",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n \"ab\"\n (string-trim\n  \" \t\nab\n\t \"))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_string("ab"),
              vx_type.f_string_trim(
                vx_core.vx_new_string(" \t\nab\n\t ")
              )
            )
        )
      )
    )
    return output
  }

  fun f_string_uppercase(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string-uppercase",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n \"ABC\"\n (string-uppercase\n  \"aBc\"))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_string("ABC"),
              vx_type.f_string_uppercase(
                vx_core.vx_new_string("aBc")
              )
            )
        )
      )
    )
    return output
  }

  fun f_string_from_int(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-int",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n \"4\"\n (string<-int 4))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_string("4"),
              vx_type.f_string_from_int(
                vx_core.vx_new_int(4)
              )
            )
        ),
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n \"51\"\n (string<-int 51))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_string("51"),
              vx_type.f_string_from_int(
                vx_core.vx_new_int(51)
              )
            )
        ),
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n \"notanumber\"\n (string<-int notanumber))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_string("notanumber"),
              vx_type.f_string_from_int(
                vx_core.c_notanumber
              )
            )
        ),
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n \"infinity\"\n (string<-int infinity))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_string("infinity"),
              vx_type.f_string_from_int(
                vx_core.c_infinity
              )
            )
        ),
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n \"neginfinity\"\n (string<-int neginfinity))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_string("neginfinity"),
              vx_type.f_string_from_int(
                vx_core.c_neginfinity
              )
            )
        )
      )
    )
    return output
  }

  fun f_string_from_string_end(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-string-end",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n \"abc\"\n (string<-string-end\n  \"abcd\"\n  3))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_string("abc"),
              vx_type.f_string_from_string_end(
                vx_core.vx_new_string("abcd"),
                vx_core.vx_new_int(3)
              )
            )
        ),
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n \"ab\"\n (string<-string-end\n  \"abcd\"\n  2))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_string("ab"),
              vx_type.f_string_from_string_end(
                vx_core.vx_new_string("abcd"),
                vx_core.vx_new_int(2)
              )
            )
        )
      )
    )
    return output
  }

  fun f_string_from_string_start(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-string-start",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n \"abcd\"\n (string<-string-start\n  \"abcd\"\n  1))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_string("abcd"),
              vx_type.f_string_from_string_start(
                vx_core.vx_new_string("abcd"),
                vx_core.vx_new_int(1)
              )
            )
        ),
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n \"bcd\"\n (string<-string-start\n  \"abcd\"\n  2))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_string("bcd"),
              vx_type.f_string_from_string_start(
                vx_core.vx_new_string("abcd"),
                vx_core.vx_new_int(2)
              )
            )
        )
      )
    )
    return output
  }

  fun f_string_from_string_start_end(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-string-start-end",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n \"abc\"\n (string<-string-start-end\n  \"abcd\"\n  1\n  3))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_string("abc"),
              vx_type.f_string_from_string_start_end(
                vx_core.vx_new_string("abcd"),
                vx_core.vx_new_int(1),
                vx_core.vx_new_int(3)
              )
            )
        ),
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n \"bc\"\n (string<-string-start-end\n  \"abcd\"\n  2\n  3))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_string("bc"),
              vx_type.f_string_from_string_start_end(
                vx_core.vx_new_string("abcd"),
                vx_core.vx_new_int(2),
                vx_core.vx_new_int(3)
              )
            )
        ),
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n \"\"\n (string<-string-start-end\n  \"abcd\"\n  5\n  6))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_string(""),
              vx_type.f_string_from_string_start_end(
                vx_core.vx_new_string("abcd"),
                vx_core.vx_new_int(5),
                vx_core.vx_new_int(6)
              )
            )
        ),
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n \"bcd\"\n (string<-string-start-end\n  \"abcd\"\n  2\n  5))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_string("bcd"),
              vx_type.f_string_from_string_start_end(
                vx_core.vx_new_string("abcd"),
                vx_core.vx_new_int(2),
                vx_core.vx_new_int(5)
              )
            )
        ),
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n \"bc\"\n (string<-string-start-end\n  \"abcd\"\n  2\n  -1))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_string("bc"),
              vx_type.f_string_from_string_start_end(
                vx_core.vx_new_string("abcd"),
                vx_core.vx_new_int(2),
                vx_core.vx_new_int(-1)
              )
            )
        )
      )
    )
    return output
  }

  fun f_string_from_stringlist_join(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-stringlist-join",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n \"a\$b\$c\"\n (string<-stringlist-join\n  (stringlist \"a\" \"b\" \"c\")\n  \"\$\"))",
          ":testresult",
            vx_test.f_test(
              context,
              vx_core.vx_new_string("a\$b\$c"),
              vx_type.f_string_from_stringlist_join(
                vx_core.f_new(
                  vx_core.t_stringlist,
                  vx_core.vx_new(
                    vx_core.t_anylist,
                    vx_core.vx_new_string("a"),
                    vx_core.vx_new_string("b"),
                    vx_core.vx_new_string("c")
                  )
                ),
                vx_core.vx_new_string("\$")
              )
            )
        )
      )
    )
    return output
  }

  fun f_stringlist_from_string_split(context : vx_core.Type_context) : vx_test.Type_testcase {
    var output : vx_test.Type_testcase = vx_core.vx_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "stringlist<-string-split",
      ":describelist",
      vx_core.vx_new(
        vx_test.t_testdescribelist,
        vx_core.vx_new(
          vx_test.t_testdescribe,
          ":describename", "(test\n (stringlist \"a\" \"b\" \"c\")\n (stringlist<-string-split\n  \"a\$b\$c\"\n  \"\$\"))",
          ":testresult",
            vx_test.f_test(
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
              vx_type.f_stringlist_from_string_split(
                vx_core.vx_new_string("a\$b\$c"),
                vx_core.vx_new_string("\$")
              )
            )
        )
      )
    )
    return output
  }

  fun test_cases(context : vx_core.Type_context) : vx_test.Type_testcaselist {
    var testcases : List<vx_core.Type_any> = vx_core.arraylist_from_array(
      vx_typeTest.f_boolean_from_string_ends(context),
      vx_typeTest.f_boolean_from_string_starts(context),
      vx_typeTest.f_int_from_string_find(context),
      vx_typeTest.f_int_from_string_findkeyword(context),
      vx_typeTest.f_int_from_string_findlast(context),
      vx_typeTest.f_is_string(context),
      vx_typeTest.f_is_type(context),
      vx_typeTest.f_is_type_from_any_typelist(context),
      vx_typeTest.f_string_lowercase(context),
      vx_typeTest.f_string_outdent(context),
      vx_typeTest.f_string_trim(context),
      vx_typeTest.f_string_uppercase(context),
      vx_typeTest.f_string_from_int(context),
      vx_typeTest.f_string_from_string_end(context),
      vx_typeTest.f_string_from_string_start(context),
      vx_typeTest.f_string_from_string_start_end(context),
      vx_typeTest.f_string_from_stringlist_join(context),
      vx_typeTest.f_stringlist_from_string_split(context)
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
      ":testpkg", "vx/type", 
      ":constnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 81, ":tests", 22, ":total", 27), 
      ":funcnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 66, ":tests", 18, ":total", 27), 
      ":bigospacenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 27), 
      ":bigotimenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 27), 
      ":totalnums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 66, ":tests", 18, ":total", 27), 
      ":typenums", vx_core.vx_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0)
    )
    return output
  }

  fun test_coveragedetail() : vx_test.Type_testcoveragedetail {
    var output : vx_test.Type_testcoveragedetail = vx_core.vx_new(
      vx_test.t_testcoveragedetail,
      ":testpkg", "vx/type",
      ":typemap", vx_core.e_intmap, 
      ":constmap", vx_core.e_intmap, 
      ":funcmap", vx_core.vx_new(
        vx_core.t_intmap,
        ":allowtypenames<-type", 0,
        ":allowtypes<-type", 0,
        ":any<-int", 0,
        ":boolean<-string-ends", 1,
        ":boolean<-string-starts", 1,
        ":int<-string-find", 1,
        ":int<-string-findkeyword", 2,
        ":int<-string-findlast", 1,
        ":is-boolean", 0,
        ":is-decimal", 0,
        ":is-none", 0,
        ":is-string", 4,
        ":is-type", 4,
        ":is-type<-any-typelist", 4,
        ":string-lowercase", 1,
        ":string-outdent", 2,
        ":string-trim", 1,
        ":string-uppercase", 1,
        ":string<-int", 5,
        ":string<-string-end", 2,
        ":string<-string-start", 2,
        ":string<-string-start-end", 5,
        ":string<-stringlist-join", 1,
        ":stringlist<-string-split", 1,
        ":traitnames<-any", 0,
        ":traits<-any", 0,
        ":traits<-typedef", 0
      )
    )
    return output
  }

  fun test_package(context : vx_core.Type_context) : vx_test.Type_testpackage {
    var testcaselist : vx_test.Type_testcaselist = test_cases(context)
    var output : vx_test.Type_testpackage = vx_core.vx_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/type", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    )
    return output
  }

}
