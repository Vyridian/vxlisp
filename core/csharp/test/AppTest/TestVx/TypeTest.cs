
namespace AppTest.TestVx;

public class TypeTest {

  public static Vx.Test.Type_testcase f_boolean_from_string_ends(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "boolean<-string-ends",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test-true\n (boolean<-string-ends\n  \"abcd\"\n  \"cd\"))",
          ":testresult",
            Vx.Test.f_test_true(
              context,
              Vx.Type.f_boolean_from_string_ends(Vx.Core.vx_new_string("abcd"), Vx.Core.vx_new_string("cd"))
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_boolean_from_string_starts(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "boolean<-string-starts",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test-true\n (boolean<-string-starts\n  \"abcd\"\n  \"ab\"))",
          ":testresult",
            Vx.Test.f_test_true(
              context,
              Vx.Type.f_boolean_from_string_starts(Vx.Core.vx_new_string("abcd"), Vx.Core.vx_new_string("ab"))
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_int_from_string_find(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "int<-string-find",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n 3\n (int<-string-find\n  \"abcdcdg\"\n  \"cd\"))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_int(3),
              Vx.Type.f_int_from_string_find(Vx.Core.vx_new_string("abcdcdg"), Vx.Core.vx_new_string("cd"))
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_int_from_string_findkeyword(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "int<-string-findkeyword",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n 3\n (int<-string-findkeyword\n  \"ab\tcdefg\"\n  \":whitespace\"))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_int(3),
              Vx.Type.f_int_from_string_findkeyword(Vx.Core.vx_new_string("ab\tcdefg"), Vx.Core.vx_new_string(":whitespace"))
            )
        ),
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n 5\n (int<-string-findkeyword\n  \" \t\n\rab\"\n  \":nonwhitespace\"))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_int(5),
              Vx.Type.f_int_from_string_findkeyword(Vx.Core.vx_new_string(" \t\n\rab"), Vx.Core.vx_new_string(":nonwhitespace"))
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_int_from_string_findlast(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "int<-string-findlast",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n 5\n (int<-string-findlast\n  \"abcdcdg\"\n  \"cd\"))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_int(5),
              Vx.Type.f_int_from_string_findlast(Vx.Core.vx_new_string("abcdcdg"), Vx.Core.vx_new_string("cd"))
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_is_string(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "is-string",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test-true\n (is-string \"\"))",
          ":testresult",
            Vx.Test.f_test_true(
              context,
              Vx.Type.f_is_string(Vx.Core.vx_new_string(""))
            )
        ),
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test-true\n (is-string \"a\"))",
          ":testresult",
            Vx.Test.f_test_true(
              context,
              Vx.Type.f_is_string(Vx.Core.vx_new_string("a"))
            )
        ),
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test-false\n (is-string 5))",
          ":testresult",
            Vx.Test.f_test_false(
              context,
              Vx.Type.f_is_string(Vx.Core.vx_new_int(5))
            )
        ),
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test-false\n (is-string (list)))",
          ":testresult",
            Vx.Test.f_test_false(
              context,
              Vx.Type.f_is_string(
                Vx.Core.f_empty(
                  Vx.Core.t_list
                )
              )
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_is_type(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "is-type",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test-true\n (is-type false boolean))",
          ":testresult",
            Vx.Test.f_test_true(
              context,
              Vx.Type.f_is_type(
                Vx.Core.vx_new_boolean(false),
                Vx.Core.t_boolean
              )
            )
        ),
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test-true\n (is-type \"a\" string))",
          ":testresult",
            Vx.Test.f_test_true(
              context,
              Vx.Type.f_is_type(
                Vx.Core.vx_new_string("a"),
                Vx.Core.t_string
              )
            )
        ),
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test-true\n (is-type 5.5 number))",
          ":testresult",
            Vx.Test.f_test_true(
              context,
              Vx.Type.f_is_type(
                Vx.Core.t_decimal.vx_new_from_string("5.5"),
                Vx.Core.t_number
              )
            )
        ),
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test-true\n (is-type 4 int))",
          ":testresult",
            Vx.Test.f_test_true(
              context,
              Vx.Type.f_is_type(
                Vx.Core.vx_new_int(4),
                Vx.Core.t_int
              )
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_is_type_from_any_typelist(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "is-type<-any-typelist",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test-true\n (is-type<-any-typelist\n  false\n  (typelist int boolean)))",
          ":testresult",
            Vx.Test.f_test_true(
              context,
              Vx.Type.f_is_type_from_any_typelist(
                Vx.Core.vx_new_boolean(false),
                Vx.Core.f_new(
                  Vx.Core.t_typelist,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.t_int,
                    Vx.Core.t_boolean
                  )
                )
              )
            )
        ),
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test-true\n (is-type<-any-typelist\n  \"a\"\n  (typelist number string)))",
          ":testresult",
            Vx.Test.f_test_true(
              context,
              Vx.Type.f_is_type_from_any_typelist(
                Vx.Core.vx_new_string("a"),
                Vx.Core.f_new(
                  Vx.Core.t_typelist,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.t_number,
                    Vx.Core.t_string
                  )
                )
              )
            )
        ),
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test-true\n (is-type<-any-typelist\n  5.5\n  (typelist string number)))",
          ":testresult",
            Vx.Test.f_test_true(
              context,
              Vx.Type.f_is_type_from_any_typelist(
                Vx.Core.t_decimal.vx_new_from_string("5.5"),
                Vx.Core.f_new(
                  Vx.Core.t_typelist,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.t_string,
                    Vx.Core.t_number
                  )
                )
              )
            )
        ),
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test-true\n (is-type<-any-typelist\n  4\n  (typelist string int)))",
          ":testresult",
            Vx.Test.f_test_true(
              context,
              Vx.Type.f_is_type_from_any_typelist(
                Vx.Core.vx_new_int(4),
                Vx.Core.f_new(
                  Vx.Core.t_typelist,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.t_string,
                    Vx.Core.t_int
                  )
                )
              )
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_string_lowercase(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string-lowercase",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"abc\"\n (string-lowercase\n  \"AbC\"))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("abc"),
              Vx.Type.f_string_lowercase(Vx.Core.vx_new_string("AbC"))
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_string_outdent(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string-outdent",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"ab\"\n (string-outdent\n  \"ab\"))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("ab"),
              Vx.Type.f_string_outdent(Vx.Core.vx_new_string("ab"))
            )
        ),
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"a\nb\"\n (string-outdent\n  \"\n a\n b\"))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("a\nb"),
              Vx.Type.f_string_outdent(Vx.Core.vx_new_string("\n a\n b"))
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_string_trim(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string-trim",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"ab\"\n (string-trim\n  \" \t\nab\n\t \"))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("ab"),
              Vx.Type.f_string_trim(Vx.Core.vx_new_string(" \t\nab\n\t "))
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_string_uppercase(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string-uppercase",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"ABC\"\n (string-uppercase\n  \"aBc\"))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("ABC"),
              Vx.Type.f_string_uppercase(Vx.Core.vx_new_string("aBc"))
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_string_from_int(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-int",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"4\"\n (string<-int 4))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("4"),
              Vx.Type.f_string_from_int(Vx.Core.vx_new_int(4))
            )
        ),
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"51\"\n (string<-int 51))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("51"),
              Vx.Type.f_string_from_int(Vx.Core.vx_new_int(51))
            )
        ),
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"notanumber\"\n (string<-int notanumber))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("notanumber"),
              Vx.Type.f_string_from_int(
                Vx.Core.c_notanumber
              )
            )
        ),
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"infinity\"\n (string<-int infinity))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("infinity"),
              Vx.Type.f_string_from_int(
                Vx.Core.c_infinity
              )
            )
        ),
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"neginfinity\"\n (string<-int neginfinity))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("neginfinity"),
              Vx.Type.f_string_from_int(
                Vx.Core.c_neginfinity
              )
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_string_from_string_end(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-string-end",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"abc\"\n (string<-string-end\n  \"abcd\"\n  3))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("abc"),
              Vx.Type.f_string_from_string_end(Vx.Core.vx_new_string("abcd"), Vx.Core.vx_new_int(3))
            )
        ),
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"ab\"\n (string<-string-end\n  \"abcd\"\n  2))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("ab"),
              Vx.Type.f_string_from_string_end(Vx.Core.vx_new_string("abcd"), Vx.Core.vx_new_int(2))
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_string_from_string_start(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-string-start",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"abcd\"\n (string<-string-start\n  \"abcd\"\n  1))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("abcd"),
              Vx.Type.f_string_from_string_start(Vx.Core.vx_new_string("abcd"), Vx.Core.vx_new_int(1))
            )
        ),
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"bcd\"\n (string<-string-start\n  \"abcd\"\n  2))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("bcd"),
              Vx.Type.f_string_from_string_start(Vx.Core.vx_new_string("abcd"), Vx.Core.vx_new_int(2))
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_string_from_string_start_end(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-string-start-end",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"abc\"\n (string<-string-start-end\n  \"abcd\"\n  1\n  3))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("abc"),
              Vx.Type.f_string_from_string_start_end(Vx.Core.vx_new_string("abcd"), Vx.Core.vx_new_int(1), Vx.Core.vx_new_int(3))
            )
        ),
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"bc\"\n (string<-string-start-end\n  \"abcd\"\n  2\n  3))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("bc"),
              Vx.Type.f_string_from_string_start_end(Vx.Core.vx_new_string("abcd"), Vx.Core.vx_new_int(2), Vx.Core.vx_new_int(3))
            )
        ),
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"\"\n (string<-string-start-end\n  \"abcd\"\n  5\n  6))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string(""),
              Vx.Type.f_string_from_string_start_end(Vx.Core.vx_new_string("abcd"), Vx.Core.vx_new_int(5), Vx.Core.vx_new_int(6))
            )
        ),
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"bcd\"\n (string<-string-start-end\n  \"abcd\"\n  2\n  5))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("bcd"),
              Vx.Type.f_string_from_string_start_end(Vx.Core.vx_new_string("abcd"), Vx.Core.vx_new_int(2), Vx.Core.vx_new_int(5))
            )
        ),
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"bc\"\n (string<-string-start-end\n  \"abcd\"\n  2\n  -1))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("bc"),
              Vx.Type.f_string_from_string_start_end(Vx.Core.vx_new_string("abcd"), Vx.Core.vx_new_int(2), Vx.Core.vx_new_int(-1))
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_string_from_stringlist_join(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-stringlist-join",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n \"a$b$c\"\n (string<-stringlist-join\n  (stringlist \"a\" \"b\" \"c\")\n  \"$\"))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.vx_new_string("a$b$c"),
              Vx.Type.f_string_from_stringlist_join(
                Vx.Core.f_new(
                  Vx.Core.t_stringlist,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string("a"),
                    Vx.Core.vx_new_string("b"),
                    Vx.Core.vx_new_string("c")
                  )
                ),
                Vx.Core.vx_new_string("$")
              )
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcase f_stringlist_from_string_split(Vx.Core.Type_context context) {
    Vx.Test.Type_testcase output = Vx.Core.vx_new(
      Vx.Test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "stringlist<-string-split",
      ":describelist",
      Vx.Core.vx_new(
        Vx.Test.t_testdescribelist,
        Vx.Core.vx_new(
          Vx.Test.t_testdescribe,
          ":describename", "(test\n (stringlist \"a\" \"b\" \"c\")\n (stringlist<-string-split\n  \"a$b$c\"\n  \"$\"))",
          ":testresult",
            Vx.Test.f_test(
              context,
              Vx.Core.f_new(
                Vx.Core.t_stringlist,
                Vx.Core.vx_new(Vx.Core.t_anylist,
                  Vx.Core.vx_new_string("a"),
                  Vx.Core.vx_new_string("b"),
                  Vx.Core.vx_new_string("c")
                )
              ),
              Vx.Type.f_stringlist_from_string_split(Vx.Core.vx_new_string("a$b$c"), Vx.Core.vx_new_string("$"))
            )
        )
      )
    );
    return output;
  }

  public static Vx.Test.Type_testcaselist test_cases(Vx.Core.Type_context context) {
    object[] testcases = [
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
    ];
    Vx.Test.Type_testcaselist output = Vx.Core.vx_new(
      Vx.Test.t_testcaselist,
      testcases
    );
    return output;
  }

  public static Vx.Test.Type_testcoveragesummary test_coveragesummary() {
    return Vx.Core.vx_new(
      Vx.Test.t_testcoveragesummary,
      ":testpkg", "vx/type", 
      ":constnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 81, ":tests", 22, ":total", 27), 
      ":funcnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 66, ":tests", 18, ":total", 27), 
      ":bigospacenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 27), 
      ":bigotimenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 27), 
      ":totalnums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 66, ":tests", 18, ":total", 27), 
      ":typenums", Vx.Core.vx_new(Vx.Test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0)
    );
  }

  public static Vx.Test.Type_testcoveragedetail test_coveragedetail() {
    return Vx.Core.vx_new(Vx.Test.t_testcoveragedetail, ":testpkg", "vx/type", ":typemap", Vx.Core.e_intmap, ":constmap", Vx.Core.e_intmap, ":funcmap", Vx.Core.vx_new(
  Vx.Core.t_intmap,
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

  public static Vx.Test.Type_testpackage test_package(Vx.Core.Type_context context) {
    Vx.Test.Type_testcaselist testcaselist = test_cases(context);
    Vx.Test.Type_testpackage output = Vx.Core.vx_new(
      Vx.Test.t_testpackage,
      ":testpkg", "vx/type", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
