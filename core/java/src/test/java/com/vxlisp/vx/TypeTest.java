
package com.vxlisp.vx;

import java.util.List;

public final class TypeTest {

  static Test.Type_testcase f_boolean_from_string_ends(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "boolean<-string-ends",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test-true\n (boolean<-string-ends\n  \"abcd\"\n  \"cd\"))",
          ":testresult",
            Test.f_test_true(
              context,
              Type.f_boolean_from_string_ends(Core.vx_new_string("abcd"), Core.vx_new_string("cd"))
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_boolean_from_string_starts(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "boolean<-string-starts",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test-true\n (boolean<-string-starts\n  \"abcd\"\n  \"ab\"))",
          ":testresult",
            Test.f_test_true(
              context,
              Type.f_boolean_from_string_starts(Core.vx_new_string("abcd"), Core.vx_new_string("ab"))
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_int_from_string_find(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "int<-string-find",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n 3\n (int<-string-find\n  \"abcdcdg\"\n  \"cd\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_int(3),
              Type.f_int_from_string_find(Core.vx_new_string("abcdcdg"), Core.vx_new_string("cd"))
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_int_from_string_findkeyword(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "int<-string-findkeyword",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n 3\n (int<-string-findkeyword\n  \"ab\tcdefg\"\n  \":whitespace\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_int(3),
              Type.f_int_from_string_findkeyword(Core.vx_new_string("ab\tcdefg"), Core.vx_new_string(":whitespace"))
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n 5\n (int<-string-findkeyword\n  \" \t\n\rab\"\n  \":nonwhitespace\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_int(5),
              Type.f_int_from_string_findkeyword(Core.vx_new_string(" \t\n\rab"), Core.vx_new_string(":nonwhitespace"))
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_int_from_string_findlast(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "int<-string-findlast",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n 5\n (int<-string-findlast\n  \"abcdcdg\"\n  \"cd\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_int(5),
              Type.f_int_from_string_findlast(Core.vx_new_string("abcdcdg"), Core.vx_new_string("cd"))
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_is_string(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "is-string",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test-true\n (is-string \"\"))",
          ":testresult",
            Test.f_test_true(
              context,
              Type.f_is_string(Core.vx_new_string(""))
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test-true\n (is-string \"a\"))",
          ":testresult",
            Test.f_test_true(
              context,
              Type.f_is_string(Core.vx_new_string("a"))
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test-false\n (is-string 5))",
          ":testresult",
            Test.f_test_false(
              context,
              Type.f_is_string(Core.vx_new_int(5))
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test-false\n (is-string (list)))",
          ":testresult",
            Test.f_test_false(
              context,
              Type.f_is_string(
                Core.f_empty(
                  Core.t_list
                )
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_is_type(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "is-type",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test-true\n (is-type false boolean))",
          ":testresult",
            Test.f_test_true(
              context,
              Type.f_is_type(
                Core.vx_new_boolean(false),
                Core.t_boolean
              )
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test-true\n (is-type \"a\" string))",
          ":testresult",
            Test.f_test_true(
              context,
              Type.f_is_type(
                Core.vx_new_string("a"),
                Core.t_string
              )
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test-true\n (is-type 5.5 number))",
          ":testresult",
            Test.f_test_true(
              context,
              Type.f_is_type(
                Core.t_decimal.vx_new_from_string("5.5"),
                Core.t_number
              )
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test-true\n (is-type 4 int))",
          ":testresult",
            Test.f_test_true(
              context,
              Type.f_is_type(
                Core.vx_new_int(4),
                Core.t_int
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_is_type_from_any_typelist(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "is-type<-any-typelist",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test-true\n (is-type<-any-typelist\n  false\n  (typelist int boolean)))",
          ":testresult",
            Test.f_test_true(
              context,
              Type.f_is_type_from_any_typelist(
                Core.vx_new_boolean(false),
                Core.f_new(
                  Core.t_typelist,
                  Core.vx_new(Core.t_anylist,
                    Core.t_int,
                    Core.t_boolean
                  )
                )
              )
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test-true\n (is-type<-any-typelist\n  \"a\"\n  (typelist number string)))",
          ":testresult",
            Test.f_test_true(
              context,
              Type.f_is_type_from_any_typelist(
                Core.vx_new_string("a"),
                Core.f_new(
                  Core.t_typelist,
                  Core.vx_new(Core.t_anylist,
                    Core.t_number,
                    Core.t_string
                  )
                )
              )
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test-true\n (is-type<-any-typelist\n  5.5\n  (typelist string number)))",
          ":testresult",
            Test.f_test_true(
              context,
              Type.f_is_type_from_any_typelist(
                Core.t_decimal.vx_new_from_string("5.5"),
                Core.f_new(
                  Core.t_typelist,
                  Core.vx_new(Core.t_anylist,
                    Core.t_string,
                    Core.t_number
                  )
                )
              )
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test-true\n (is-type<-any-typelist\n  4\n  (typelist string int)))",
          ":testresult",
            Test.f_test_true(
              context,
              Type.f_is_type_from_any_typelist(
                Core.vx_new_int(4),
                Core.f_new(
                  Core.t_typelist,
                  Core.vx_new(Core.t_anylist,
                    Core.t_string,
                    Core.t_int
                  )
                )
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_string_lowercase(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string-lowercase",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"abc\"\n (string-lowercase\n  \"AbC\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("abc"),
              Type.f_string_lowercase(Core.vx_new_string("AbC"))
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_string_outdent(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string-outdent",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"ab\"\n (string-outdent\n  \"ab\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("ab"),
              Type.f_string_outdent(Core.vx_new_string("ab"))
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"a\nb\"\n (string-outdent\n  \"\n a\n b\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("a\nb"),
              Type.f_string_outdent(Core.vx_new_string("\n a\n b"))
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_string_trim(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string-trim",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"ab\"\n (string-trim\n  \" \t\nab\n\t \"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("ab"),
              Type.f_string_trim(Core.vx_new_string(" \t\nab\n\t "))
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_string_uppercase(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string-uppercase",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"ABC\"\n (string-uppercase\n  \"aBc\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("ABC"),
              Type.f_string_uppercase(Core.vx_new_string("aBc"))
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_string_from_int(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-int",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"4\"\n (string<-int 4))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("4"),
              Type.f_string_from_int(Core.vx_new_int(4))
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"51\"\n (string<-int 51))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("51"),
              Type.f_string_from_int(Core.vx_new_int(51))
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"notanumber\"\n (string<-int notanumber))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("notanumber"),
              Type.f_string_from_int(
                Core.c_notanumber
              )
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"infinity\"\n (string<-int infinity))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("infinity"),
              Type.f_string_from_int(
                Core.c_infinity
              )
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"neginfinity\"\n (string<-int neginfinity))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("neginfinity"),
              Type.f_string_from_int(
                Core.c_neginfinity
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_string_from_string_end(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-string-end",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"abc\"\n (string<-string-end\n  \"abcd\"\n  3))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("abc"),
              Type.f_string_from_string_end(Core.vx_new_string("abcd"), Core.vx_new_int(3))
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"ab\"\n (string<-string-end\n  \"abcd\"\n  2))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("ab"),
              Type.f_string_from_string_end(Core.vx_new_string("abcd"), Core.vx_new_int(2))
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_string_from_string_start(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-string-start",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"abcd\"\n (string<-string-start\n  \"abcd\"\n  1))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("abcd"),
              Type.f_string_from_string_start(Core.vx_new_string("abcd"), Core.vx_new_int(1))
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"bcd\"\n (string<-string-start\n  \"abcd\"\n  2))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("bcd"),
              Type.f_string_from_string_start(Core.vx_new_string("abcd"), Core.vx_new_int(2))
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_string_from_string_start_end(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-string-start-end",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"abc\"\n (string<-string-start-end\n  \"abcd\"\n  1\n  3))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("abc"),
              Type.f_string_from_string_start_end(Core.vx_new_string("abcd"), Core.vx_new_int(1), Core.vx_new_int(3))
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"bc\"\n (string<-string-start-end\n  \"abcd\"\n  2\n  3))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("bc"),
              Type.f_string_from_string_start_end(Core.vx_new_string("abcd"), Core.vx_new_int(2), Core.vx_new_int(3))
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"\"\n (string<-string-start-end\n  \"abcd\"\n  5\n  6))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string(""),
              Type.f_string_from_string_start_end(Core.vx_new_string("abcd"), Core.vx_new_int(5), Core.vx_new_int(6))
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"bcd\"\n (string<-string-start-end\n  \"abcd\"\n  2\n  5))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("bcd"),
              Type.f_string_from_string_start_end(Core.vx_new_string("abcd"), Core.vx_new_int(2), Core.vx_new_int(5))
            )
        ),
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"bc\"\n (string<-string-start-end\n  \"abcd\"\n  2\n  -1))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("bc"),
              Type.f_string_from_string_start_end(Core.vx_new_string("abcd"), Core.vx_new_int(2), Core.vx_new_int(-1))
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_string_from_stringlist_join(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-stringlist-join",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n \"a$b$c\"\n (string<-stringlist-join\n  (stringlist \"a\" \"b\" \"c\")\n  \"$\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("a$b$c"),
              Type.f_string_from_stringlist_join(
                Core.f_new(
                  Core.t_stringlist,
                  Core.vx_new(Core.t_anylist,
                    Core.vx_new_string("a"),
                    Core.vx_new_string("b"),
                    Core.vx_new_string("c")
                  )
                ),
                Core.vx_new_string("$")
              )
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_stringlist_from_string_split(final Core.Type_context context) {
    Test.Type_testcase output = Core.vx_new(
      Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "stringlist<-string-split",
      ":describelist",
      Core.vx_new(
        Test.t_testdescribelist,
        Core.vx_new(
          Test.t_testdescribe,
          ":describename", "(test\n (stringlist \"a\" \"b\" \"c\")\n (stringlist<-string-split\n  \"a$b$c\"\n  \"$\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.f_new(
                Core.t_stringlist,
                Core.vx_new(Core.t_anylist,
                  Core.vx_new_string("a"),
                  Core.vx_new_string("b"),
                  Core.vx_new_string("c")
                )
              ),
              Type.f_stringlist_from_string_split(Core.vx_new_string("a$b$c"), Core.vx_new_string("$"))
            )
        )
      )
    );
    return output;
  }

  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> arraylisttestcase = Core.arraylist_from_array(
      TypeTest.f_boolean_from_string_ends(context),
      TypeTest.f_boolean_from_string_starts(context),
      TypeTest.f_int_from_string_find(context),
      TypeTest.f_int_from_string_findkeyword(context),
      TypeTest.f_int_from_string_findlast(context),
      TypeTest.f_is_string(context),
      TypeTest.f_is_type(context),
      TypeTest.f_is_type_from_any_typelist(context),
      TypeTest.f_string_lowercase(context),
      TypeTest.f_string_outdent(context),
      TypeTest.f_string_trim(context),
      TypeTest.f_string_uppercase(context),
      TypeTest.f_string_from_int(context),
      TypeTest.f_string_from_string_end(context),
      TypeTest.f_string_from_string_start(context),
      TypeTest.f_string_from_string_start_end(context),
      TypeTest.f_string_from_stringlist_join(context),
      TypeTest.f_stringlist_from_string_split(context)
    );
    Test.Type_testcaselist output = Core.vx_new(
      Test.t_testcaselist,
      arraylisttestcase
    );
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    return Core.vx_new(
      Test.t_testcoveragesummary,
      ":testpkg", "vx/type", 
      ":constnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 81, ":tests", 22, ":total", 27), 
      ":funcnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 66, ":tests", 18, ":total", 27), 
      ":bigospacenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 27), 
      ":bigotimenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 27), 
      ":totalnums", Core.vx_new(Test.t_testcoveragenums, ":pct", 66, ":tests", 18, ":total", 27), 
      ":typenums", Core.vx_new(Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Core.vx_new(Test.t_testcoveragedetail, ":testpkg", "vx/type", ":typemap", Core.e_intmap, ":constmap", Core.e_intmap, ":funcmap", Core.vx_new(
  Core.t_intmap,
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
      ));
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Core.vx_new(
      Test.t_testpackage,
      ":testpkg", "vx/type", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
