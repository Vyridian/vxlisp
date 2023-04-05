
package com.vxlisp.vx;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;


public final class TypeTest {

  static com.vxlisp.vx.Test.Type_testcase f_is_string(final Core.Type_context context) {
    com.vxlisp.vx.Test.Type_testcase output = com.vxlisp.vx.Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "is-string",
      ":describelist",
      com.vxlisp.vx.Test.t_testdescribelist.vx_new(
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test-true  (is-string \"\"))",
          ":testresult",
            Test.f_test_true(
              Type.f_is_string(Core.t_string.vx_new_from_string("")),
              context
            )
        ),
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test-true  (is-string \"a\"))",
          ":testresult",
            Test.f_test_true(
              Type.f_is_string(Core.t_string.vx_new_from_string("a")),
              context
            )
        ),
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test-false (is-string 5))",
          ":testresult",
            Test.f_test_false(
              Type.f_is_string(Core.t_int.vx_new_from_int(5)),
              context
            )
        ),
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test-false (is-string (list)))",
          ":testresult",
            Test.f_test_false(
              Type.f_is_string(
                Core.f_empty(
                  Core.t_list
                )
              ),
              context
            )
        )
      )
    );
    return output;
  }

  static com.vxlisp.vx.Test.Type_testcase f_is_type(final Core.Type_context context) {
    com.vxlisp.vx.Test.Type_testcase output = com.vxlisp.vx.Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "is-type",
      ":describelist",
      com.vxlisp.vx.Test.t_testdescribelist.vx_new(
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test-true (is-type false boolean))",
          ":testresult",
            Test.f_test_true(
              Type.f_is_type(
                Core.t_boolean.vx_new_from_boolean(false),
                Core.t_boolean
              ),
              context
            )
        ),
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test-true (is-type \"a\"   string))",
          ":testresult",
            Test.f_test_true(
              Type.f_is_type(
                Core.t_string.vx_new_from_string("a"),
                Core.t_string
              ),
              context
            )
        ),
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test-true (is-type 5.5   number))",
          ":testresult",
            Test.f_test_true(
              Type.f_is_type(
                Core.t_decimal.vx_new_from_string("5.5"),
                Core.t_number
              ),
              context
            )
        ),
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test-true (is-type 4     int))",
          ":testresult",
            Test.f_test_true(
              Type.f_is_type(
                Core.t_int.vx_new_from_int(4),
                Core.t_int
              ),
              context
            )
        )
      )
    );
    return output;
  }

  static com.vxlisp.vx.Test.Type_testcase f_is_type_from_any_typelist(final Core.Type_context context) {
    com.vxlisp.vx.Test.Type_testcase output = com.vxlisp.vx.Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "is-type<-any-typelist",
      ":describelist",
      com.vxlisp.vx.Test.t_testdescribelist.vx_new(
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test-true\n (is-type<-any-typelist\n  false (typelist int boolean)))",
          ":testresult",
            Test.f_test_true(
              Type.f_is_type_from_any_typelist(
                Core.t_boolean.vx_new_from_boolean(false),
                Core.f_new(
                  Core.t_typelist,
                  Core.t_anylist.vx_new(
                    Core.t_int,
                    Core.t_boolean
                  )
                )
              ),
              context
            )
        ),
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test-true\n (is-type<-any-typelist\n  \"a\"   (typelist number string)))",
          ":testresult",
            Test.f_test_true(
              Type.f_is_type_from_any_typelist(
                Core.t_string.vx_new_from_string("a"),
                Core.f_new(
                  Core.t_typelist,
                  Core.t_anylist.vx_new(
                    Core.t_number,
                    Core.t_string
                  )
                )
              ),
              context
            )
        ),
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test-true\n (is-type<-any-typelist\n  5.5   (typelist string number)))",
          ":testresult",
            Test.f_test_true(
              Type.f_is_type_from_any_typelist(
                Core.t_decimal.vx_new_from_string("5.5"),
                Core.f_new(
                  Core.t_typelist,
                  Core.t_anylist.vx_new(
                    Core.t_string,
                    Core.t_number
                  )
                )
              ),
              context
            )
        ),
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test-true\n (is-type<-any-typelist\n  4     (typelist string int)))",
          ":testresult",
            Test.f_test_true(
              Type.f_is_type_from_any_typelist(
                Core.t_int.vx_new_from_int(4),
                Core.f_new(
                  Core.t_typelist,
                  Core.t_anylist.vx_new(
                    Core.t_string,
                    Core.t_int
                  )
                )
              ),
              context
            )
        )
      )
    );
    return output;
  }

  static com.vxlisp.vx.Test.Type_testcase f_length_from_string(final Core.Type_context context) {
    com.vxlisp.vx.Test.Type_testcase output = com.vxlisp.vx.Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "length<-string",
      ":describelist",
      com.vxlisp.vx.Test.t_testdescribelist.vx_new(
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test 4 (length<-string \"abcd\"))",
          ":testresult",
            Test.f_test(
              Core.t_int.vx_new_from_int(4),
              Type.f_length_from_string(Core.t_string.vx_new_from_string("abcd")),
              context
            )
        ),
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test 0 (length<-string \"\"))",
          ":testresult",
            Test.f_test(
              Core.t_int.vx_new_from_int(0),
              Type.f_length_from_string(Core.t_string.vx_new_from_string("")),
              context
            )
        )
      )
    );
    return output;
  }

  static com.vxlisp.vx.Test.Type_testcase f_string_from_int(final Core.Type_context context) {
    com.vxlisp.vx.Test.Type_testcase output = com.vxlisp.vx.Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-int",
      ":describelist",
      com.vxlisp.vx.Test.t_testdescribelist.vx_new(
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test \"4\"           (string<-int 4))",
          ":testresult",
            Test.f_test(
              Core.t_string.vx_new_from_string("4"),
              Type.f_string_from_int(Core.t_int.vx_new_from_int(4)),
              context
            )
        ),
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test \"51\"          (string<-int 51))",
          ":testresult",
            Test.f_test(
              Core.t_string.vx_new_from_string("51"),
              Type.f_string_from_int(Core.t_int.vx_new_from_int(51)),
              context
            )
        ),
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test \"notanumber\"  (string<-int notanumber))",
          ":testresult",
            Test.f_test(
              Core.t_string.vx_new_from_string("notanumber"),
              Type.f_string_from_int(
                Core.c_notanumber
              ),
              context
            )
        ),
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test \"infinity\"    (string<-int infinity))",
          ":testresult",
            Test.f_test(
              Core.t_string.vx_new_from_string("infinity"),
              Type.f_string_from_int(
                Core.c_infinity
              ),
              context
            )
        ),
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test \"neginfinity\" (string<-int neginfinity))",
          ":testresult",
            Test.f_test(
              Core.t_string.vx_new_from_string("neginfinity"),
              Type.f_string_from_int(
                Core.c_neginfinity
              ),
              context
            )
        )
      )
    );
    return output;
  }

  static com.vxlisp.vx.Test.Type_testcase f_string_from_string_end(final Core.Type_context context) {
    com.vxlisp.vx.Test.Type_testcase output = com.vxlisp.vx.Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-string-end",
      ":describelist",
      com.vxlisp.vx.Test.t_testdescribelist.vx_new(
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test \"abc\" (string<-string-end \"abcd\" 3))",
          ":testresult",
            Test.f_test(
              Core.t_string.vx_new_from_string("abc"),
              Type.f_string_from_string_end(Core.t_string.vx_new_from_string("abcd"), Core.t_int.vx_new_from_int(3)),
              context
            )
        ),
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test \"ab\"  (string<-string-end \"abcd\" 2))",
          ":testresult",
            Test.f_test(
              Core.t_string.vx_new_from_string("ab"),
              Type.f_string_from_string_end(Core.t_string.vx_new_from_string("abcd"), Core.t_int.vx_new_from_int(2)),
              context
            )
        )
      )
    );
    return output;
  }

  static com.vxlisp.vx.Test.Type_testcase f_string_from_string_start(final Core.Type_context context) {
    com.vxlisp.vx.Test.Type_testcase output = com.vxlisp.vx.Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-string-start",
      ":describelist",
      com.vxlisp.vx.Test.t_testdescribelist.vx_new(
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test \"abcd\" (string<-string-start \"abcd\" 0))",
          ":testresult",
            Test.f_test(
              Core.t_string.vx_new_from_string("abcd"),
              Type.f_string_from_string_start(Core.t_string.vx_new_from_string("abcd"), Core.t_int.vx_new_from_int(0)),
              context
            )
        ),
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test \"bcd\"  (string<-string-start \"abcd\" 1))",
          ":testresult",
            Test.f_test(
              Core.t_string.vx_new_from_string("bcd"),
              Type.f_string_from_string_start(Core.t_string.vx_new_from_string("abcd"), Core.t_int.vx_new_from_int(1)),
              context
            )
        )
      )
    );
    return output;
  }

  static com.vxlisp.vx.Test.Type_testcase f_string_from_string_start_end(final Core.Type_context context) {
    com.vxlisp.vx.Test.Type_testcase output = com.vxlisp.vx.Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-string-start-end",
      ":describelist",
      com.vxlisp.vx.Test.t_testdescribelist.vx_new(
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test \"abc\" (string<-string-start-end \"abcd\" 0 3))",
          ":testresult",
            Test.f_test(
              Core.t_string.vx_new_from_string("abc"),
              Type.f_string_from_string_start_end(Core.t_string.vx_new_from_string("abcd"), Core.t_int.vx_new_from_int(0), Core.t_int.vx_new_from_int(3)),
              context
            )
        ),
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test \"bc\"  (string<-string-start-end \"abcd\" 1 3))",
          ":testresult",
            Test.f_test(
              Core.t_string.vx_new_from_string("bc"),
              Type.f_string_from_string_start_end(Core.t_string.vx_new_from_string("abcd"), Core.t_int.vx_new_from_int(1), Core.t_int.vx_new_from_int(3)),
              context
            )
        ),
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test \"\"    (string<-string-start-end \"abcd\" 5 6))",
          ":testresult",
            Test.f_test(
              Core.t_string.vx_new_from_string(""),
              Type.f_string_from_string_start_end(Core.t_string.vx_new_from_string("abcd"), Core.t_int.vx_new_from_int(5), Core.t_int.vx_new_from_int(6)),
              context
            )
        ),
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test \"bcd\" (string<-string-start-end \"abcd\" 1 5))",
          ":testresult",
            Test.f_test(
              Core.t_string.vx_new_from_string("bcd"),
              Type.f_string_from_string_start_end(Core.t_string.vx_new_from_string("abcd"), Core.t_int.vx_new_from_int(1), Core.t_int.vx_new_from_int(5)),
              context
            )
        )
      )
    );
    return output;
  }

  static com.vxlisp.vx.Test.Type_testcase f_string_from_stringlist_join(final Core.Type_context context) {
    com.vxlisp.vx.Test.Type_testcase output = com.vxlisp.vx.Test.t_testcase.vx_new(
      ":passfail", false,
      ":testpkg", "vx/type",
      ":casename", "string<-stringlist-join",
      ":describelist",
      com.vxlisp.vx.Test.t_testdescribelist.vx_new(
        com.vxlisp.vx.Test.t_testdescribe.vx_new(
          ":describename", "(test \"a$b$c\" (string<-stringlist-join (stringlist \"a\" \"b\" \"c\") \"$\"))",
          ":testresult",
            Test.f_test(
              Core.t_string.vx_new_from_string("a$b$c"),
              Type.f_string_from_stringlist_join(
                Core.f_new(
                  Core.t_stringlist,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string("a"),
                    Core.t_string.vx_new_from_string("b"),
                    Core.t_string.vx_new_from_string("c")
                  )
                ),
                Core.t_string.vx_new_from_string("$")
              ),
              context
            )
        )
      )
    );
    return output;
  }

  public static com.vxlisp.vx.Test.Type_testcaselist test_cases(final Core.Type_context context) {
    List<Core.Type_any> arraylisttestcase = new ArrayList<>(Arrays.asList(
      Typecom.vxlisp.vx.Test.f_is_string(context),
      Typecom.vxlisp.vx.Test.f_is_type(context),
      Typecom.vxlisp.vx.Test.f_is_type_from_any_typelist(context),
      Typecom.vxlisp.vx.Test.f_length_from_string(context),
      Typecom.vxlisp.vx.Test.f_string_from_int(context),
      Typecom.vxlisp.vx.Test.f_string_from_string_end(context),
      Typecom.vxlisp.vx.Test.f_string_from_string_start(context),
      Typecom.vxlisp.vx.Test.f_string_from_string_start_end(context),
      Typecom.vxlisp.vx.Test.f_string_from_stringlist_join(context)
    ));
    com.vxlisp.vx.Test.Type_testcaselist output = com.vxlisp.vx.Test.t_testcaselist.vx_new(arraylisttestcase);
    return output;
  }

  public static com.vxlisp.vx.Test.Type_testcoveragesummary test_coveragesummary() {
    return com.vxlisp.vx.Test.t_testcoveragesummary.vx_new(
      ":testpkg",   "vx/type", 
      ":constnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 0, ":total", 0), 
      ":docnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 61, ":tests", 11, ":total", 18), 
      ":funcnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 50, ":tests", 9, ":total", 18), 
      ":ospacenums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 18), 
      ":otimenums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 0, ":tests", 0, ":total", 18), 
      ":totalnums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 50, ":tests", 9, ":total", 18), 
      ":typenums", com.vxlisp.vx.Test.t_testcoveragenums.vx_new(":pct", 100, ":tests", 0, ":total", 0)
    );
  }

  public static com.vxlisp.vx.Test.Type_testcoveragedetail test_coveragedetail() {
    return com.vxlisp.vx.Test.t_testcoveragedetail.vx_new(
      ":testpkg", "vx/type",
      ":typemap", Core.t_intmap.vx_new(
  
      ),
      ":constmap", Core.t_intmap.vx_new(
  
      ),
      ":funcmap", Core.t_intmap.vx_new(
        ":allowtypenames<-type", 0,
        ":allowtypes<-type", 0,
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
        ":traitnames<-any", 0,
        ":traits<-any", 0,
        ":traits<-typedef", 0
      )
    );
  }

  public static com.vxlisp.vx.Test.Type_testpackage test_package(final Core.Type_context context) {
    com.vxlisp.vx.Test.Type_testcaselist testcaselist = test_cases(context);
    com.vxlisp.vx.Test.Type_testpackage output = com.vxlisp.vx.Test.t_testpackage.vx_new(
      ":testpkg", "vx/type", 
      ":caselist", testcaselist,
      ":coveragesummary", test_coveragesummary(),
      ":coveragedetail", test_coveragedetail()
    );
    return output;
  }

}
