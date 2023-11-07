
package com.vxlisp.vx;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;


public final class TypeTest {

  static Test.Type_testcase f_int_from_string_find(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "int<-string-find",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n 2\n (int<-string-find \"abcdefg\" \"cd\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_int(2),
              Type.f_int_from_string_find(Core.vx_new_string("abcdefg"), Core.vx_new_string("cd"))
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_int_from_string_findkeyword(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "int<-string-findkeyword",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n 2\n (int<-string-findkeyword \"ab\tcdefg\" \":whitespace\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_int(2),
              Type.f_int_from_string_findkeyword(Core.vx_new_string("ab\tcdefg"), Core.vx_new_string(":whitespace"))
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n 4\n (int<-string-findkeyword \" \t\n\rab\" \":nonwhitespace\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_int(4),
              Type.f_int_from_string_findkeyword(Core.vx_new_string(" \t\n\rab"), Core.vx_new_string(":nonwhitespace"))
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_is_string(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "is-string",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test-true  (is-string \"\"))",
          ":testresult",
            Test.f_test_true(
              context,
              Type.f_is_string(Core.vx_new_string(""))
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test-true  (is-string \"a\"))",
          ":testresult",
            Test.f_test_true(
              context,
              Type.f_is_string(Core.vx_new_string("a"))
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test-false (is-string 5))",
          ":testresult",
            Test.f_test_false(
              context,
              Type.f_is_string(Core.vx_new_int(5))
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test-false (is-string (list)))",
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
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "is-type",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test-true (is-type false boolean))",
          ":testresult",
            Test.f_test_true(
              context,
              Type.f_is_type(
                Core.vx_new_boolean(false),
                Core.t_boolean
              )
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test-true (is-type \"a\"   string))",
          ":testresult",
            Test.f_test_true(
              context,
              Type.f_is_type(
                Core.vx_new_string("a"),
                Core.t_string
              )
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test-true (is-type 5.5   number))",
          ":testresult",
            Test.f_test_true(
              context,
              Type.f_is_type(
                Core.t_decimal.vx_new_from_string("5.5"),
                Core.t_number
              )
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test-true (is-type 4     int))",
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
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "is-type<-any-typelist",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test-true\n (is-type<-any-typelist\n  false (typelist int boolean)))",
          ":testresult",
            Test.f_test_true(
              context,
              Type.f_is_type_from_any_typelist(
                Core.vx_new_boolean(false),
                Core.f_new(
                  Core.t_typelist,
                  Core.t_anylist.vx_new(
                    Core.t_int,
                    Core.t_boolean
                  )
                )
              )
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test-true\n (is-type<-any-typelist\n  \"a\"   (typelist number string)))",
          ":testresult",
            Test.f_test_true(
              context,
              Type.f_is_type_from_any_typelist(
                Core.vx_new_string("a"),
                Core.f_new(
                  Core.t_typelist,
                  Core.t_anylist.vx_new(
                    Core.t_number,
                    Core.t_string
                  )
                )
              )
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test-true\n (is-type<-any-typelist\n  5.5   (typelist string number)))",
          ":testresult",
            Test.f_test_true(
              context,
              Type.f_is_type_from_any_typelist(
                Core.t_decimal.vx_new_from_string("5.5"),
                Core.f_new(
                  Core.t_typelist,
                  Core.t_anylist.vx_new(
                    Core.t_string,
                    Core.t_number
                  )
                )
              )
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test-true\n (is-type<-any-typelist\n  4     (typelist string int)))",
          ":testresult",
            Test.f_test_true(
              context,
              Type.f_is_type_from_any_typelist(
                Core.vx_new_int(4),
                Core.f_new(
                  Core.t_typelist,
                  Core.t_anylist.vx_new(
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

  static Test.Type_testcase f_length_from_string(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "length<-string",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test 4 (length<-string \"abcd\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_int(4),
              Type.f_length_from_string(Core.vx_new_string("abcd"))
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test 0 (length<-string \"\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_int(0),
              Type.f_length_from_string(Core.vx_new_string(""))
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_string_from_int(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-int",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test \"4\"           (string<-int 4))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("4"),
              Type.f_string_from_int(Core.vx_new_int(4))
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test \"51\"          (string<-int 51))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("51"),
              Type.f_string_from_int(Core.vx_new_int(51))
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test \"notanumber\"  (string<-int notanumber))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("notanumber"),
              Type.f_string_from_int(
                Core.c_notanumber
              )
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test \"infinity\"    (string<-int infinity))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("infinity"),
              Type.f_string_from_int(
                Core.c_infinity
              )
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test \"neginfinity\" (string<-int neginfinity))",
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
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-string-end",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test \"abc\" (string<-string-end \"abcd\" 3))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("abc"),
              Type.f_string_from_string_end(Core.vx_new_string("abcd"), Core.vx_new_int(3))
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test \"ab\"  (string<-string-end \"abcd\" 2))",
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
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-string-start",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test \"abcd\" (string<-string-start \"abcd\" 0))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("abcd"),
              Type.f_string_from_string_start(Core.vx_new_string("abcd"), Core.vx_new_int(0))
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test \"bcd\"  (string<-string-start \"abcd\" 1))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("bcd"),
              Type.f_string_from_string_start(Core.vx_new_string("abcd"), Core.vx_new_int(1))
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_string_from_string_start_end(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-string-start-end",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test \"abc\" (string<-string-start-end \"abcd\" 0 3))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("abc"),
              Type.f_string_from_string_start_end(Core.vx_new_string("abcd"), Core.vx_new_int(0), Core.vx_new_int(3))
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test \"bc\"  (string<-string-start-end \"abcd\" 1 3))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("bc"),
              Type.f_string_from_string_start_end(Core.vx_new_string("abcd"), Core.vx_new_int(1), Core.vx_new_int(3))
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test \"\"    (string<-string-start-end \"abcd\" 5 6))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string(""),
              Type.f_string_from_string_start_end(Core.vx_new_string("abcd"), Core.vx_new_int(5), Core.vx_new_int(6))
            )
        ),
        Test.t_testdescribe.vx_new(
          ":describename", "(test \"bcd\" (string<-string-start-end \"abcd\" 1 5))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("bcd"),
              Type.f_string_from_string_start_end(Core.vx_new_string("abcd"), Core.vx_new_int(1), Core.vx_new_int(5))
            )
        )
      )
    );
    return output;
  }

  static Test.Type_testcase f_string_from_stringlist_join(final Core.Type_context context) {
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-stringlist-join",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n \"a$b$c\"\n (string<-stringlist-join (stringlist \"a\" \"b\" \"c\") \"$\"))",
          ":testresult",
            Test.f_test(
              context,
              Core.vx_new_string("a$b$c"),
              Type.f_string_from_stringlist_join(
                Core.f_new(
                  Core.t_stringlist,
                  Core.t_anylist.vx_new(
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
    Test.Type_testcase output = Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "stringlist<-string-split",
      ":describelist",
      Test.t_testdescribelist.vx_new(
        Test.t_testdescribe.vx_new(
          ":describename", "(test\n (stringlist \"a\" \"b\" \"c\")\n (stringlist<-string-split \"a$b$c\" \"$\"))",
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
              Type.f_stringlist_from_string_split(Core.vx_new_string("a$b$c"), Core.vx_new_string("$"))
            )
        )
      )
    );
    return output;
  }

  public static Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(
      TypeTest.f_int_from_string_find(context),
      TypeTest.f_int_from_string_findkeyword(context),
      TypeTest.f_is_string(context),
      TypeTest.f_is_type(context),
      TypeTest.f_is_type_from_any_typelist(context),
      TypeTest.f_length_from_string(context),
      TypeTest.f_string_from_int(context),
      TypeTest.f_string_from_string_end(context),
      TypeTest.f_string_from_string_start(context),
      TypeTest.f_string_from_string_start_end(context),
      TypeTest.f_string_from_stringlist_join(context),
      TypeTest.f_stringlist_from_string_split(context)
    ));
    Test.Type_testcaselist output = Test.t_testcaselist.vx_new(arraylisttestcase);
    return output;
  }

  public static Test.Type_testcoveragesummary test_coveragesummary() {
    return Test.t_testcoveragesummary.vx_new(
      ":testpkg",   "vx/type", 
      ":constnums", Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", Test.t_testcoveragenums.vx_new(":pct", 72, ":tests", 16, ":total", 22), 
      ":funcnums", Test.t_testcoveragenums.vx_new(":pct", 54, ":tests", 12, ":total", 22), 
      ":ospacenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 22), 
      ":otimenums", Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 22), 
      ":totalnums", Test.t_testcoveragenums.vx_new(":pct", 54, ":tests", 12, ":total", 22), 
      ":typenums", Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 0, ":total", 0)
    );
  }

  public static Test.Type_testcoveragedetail test_coveragedetail() {
    return Test.t_testcoveragedetail.vx_new(
      ":testpkg", "vx/type",
      ":typemap", Core.t_intmap.vx_new(
  
      ),
      ":constmap", Core.t_intmap.vx_new(
  
      ),
      ":funcmap", Core.t_intmap.vx_new(
        ":allowtypenames<-type", 0,
        ":allowtypes<-type", 0,
        ":any<-int", 0,
        ":int<-string-find", 1,
        ":int<-string-findkeyword", 2,
        ":is-boolean", 0,
        ":is-decimal", 0,
        ":is-float", 0,
        ":is-none", 0,
        ":is-string", 4,
        ":is-type", 4,
        ":is-type<-any-typelist", 4,
        ":length<-string", 2,
        ":string<-int", 5,
        ":string<-string-end", 2,
        ":string<-string-start", 2,
        ":string<-string-start-end", 4,
        ":string<-stringlist-join", 1,
        ":stringlist<-string-split", 1,
        ":traitnames<-any", 0,
        ":traits<-any", 0,
        ":traits<-typedef", 0
      )
    );
  }

  public static Test.Type_testpackage test_package(final Core.Type_context context) {
    Test.Type_testcaselist testcaselist = test_cases(context);
    Test.Type_testpackage output = Test.t_testpackage.vx_new(
      ":testpkg", "vx/type", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
