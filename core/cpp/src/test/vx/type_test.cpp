#include "../../main/vx/type.hpp"
#include "../../main/vx/core.hpp"
#include "../../main/vx/test.hpp"

#include "type_test.hpp"

namespace vx_type_test {

  vx_test::Type_testcase f_boolean_from_string_ends(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_boolean_from_string_ends");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test_true(
      context,
      vx_type::f_boolean_from_string_ends(vx_core::vx_new_string("abcd"), vx_core::vx_new_string("cd"))
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true\n (boolean<-string-ends\n  \"abcd\"\n  \"cd\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("boolean<-string-ends"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_boolean_from_string_ends");
    return output;
  }

  vx_test::Type_testcase f_boolean_from_string_starts(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_boolean_from_string_starts");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test_true(
      context,
      vx_type::f_boolean_from_string_starts(vx_core::vx_new_string("abcd"), vx_core::vx_new_string("ab"))
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true\n (boolean<-string-starts\n  \"abcd\"\n  \"ab\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("boolean<-string-starts"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_boolean_from_string_starts");
    return output;
  }

  vx_test::Type_testcase f_int_from_string_find(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_int_from_string_find");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::vx_new_int(3),
      vx_type::f_int_from_string_find(vx_core::vx_new_string("abcdcdg"), vx_core::vx_new_string("cd"))
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n 3\n (int<-string-find\n  \"abcdcdg\"\n  \"cd\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("int<-string-find"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_int_from_string_find");
    return output;
  }

  vx_test::Type_testcase f_int_from_string_findkeyword(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_int_from_string_findkeyword");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::vx_new_int(3),
      vx_type::f_int_from_string_findkeyword(vx_core::vx_new_string("ab\tcdefg"), vx_core::vx_new_string(":whitespace"))
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n 3\n (int<-string-findkeyword\n  \"ab\tcdefg\"\n  \":whitespace\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::vx_new_int(5),
      vx_type::f_int_from_string_findkeyword(vx_core::vx_new_string(" \t\n\rab"), vx_core::vx_new_string(":nonwhitespace"))
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n 5\n (int<-string-findkeyword\n  \" \t\n\rab\"\n  \":nonwhitespace\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("int<-string-findkeyword"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_int_from_string_findkeyword");
    return output;
  }

  vx_test::Type_testcase f_int_from_string_findlast(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_int_from_string_findlast");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::vx_new_int(5),
      vx_type::f_int_from_string_findlast(vx_core::vx_new_string("abcdcdg"), vx_core::vx_new_string("cd"))
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n 5\n (int<-string-findlast\n  \"abcdcdg\"\n  \"cd\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("int<-string-findlast"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_int_from_string_findlast");
    return output;
  }

  vx_test::Type_testcase f_is_string(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_is_string");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test_true(
      context,
      vx_type::f_is_string(vx_core::vx_new_string(""))
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true\n (is-string \"\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test_true(
      context,
      vx_type::f_is_string(vx_core::vx_new_string("a"))
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true\n (is-string \"a\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    // testdescribe_3
    vx_test::Type_testresult testresult_3 = vx_test::f_test_false(
      context,
      vx_type::f_is_string(vx_core::vx_new_int(5))
    );
    vx_test::Type_testdescribe testdescribe_3 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-false\n (is-string 5))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_3
    });
    // testdescribe_4
    vx_test::Type_testresult testresult_4 = vx_test::f_test_false(
      context,
      vx_type::f_is_string(
        vx_core::f_empty(
          vx_core::t_list
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_4 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-false\n (is-string (list)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_4
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2,
      testdescribe_3,
      testdescribe_4
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("is-string"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_is_string");
    return output;
  }

  vx_test::Type_testcase f_is_type(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_is_type");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test_true(
      context,
      vx_type::f_is_type(
        vx_core::vx_new_boolean(false),
        vx_core::t_boolean
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true\n (is-type false boolean))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test_true(
      context,
      vx_type::f_is_type(
        vx_core::vx_new_string("a"),
        vx_core::t_string
      )
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true\n (is-type \"a\" string))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    // testdescribe_3
    vx_test::Type_testresult testresult_3 = vx_test::f_test_true(
      context,
      vx_type::f_is_type(
        vx_core::vx_new_decimal_from_string("5.5"),
        vx_core::t_number
      )
    );
    vx_test::Type_testdescribe testdescribe_3 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true\n (is-type 5.5 number))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_3
    });
    // testdescribe_4
    vx_test::Type_testresult testresult_4 = vx_test::f_test_true(
      context,
      vx_type::f_is_type(
        vx_core::vx_new_int(4),
        vx_core::t_int
      )
    );
    vx_test::Type_testdescribe testdescribe_4 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true\n (is-type 4 int))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_4
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2,
      testdescribe_3,
      testdescribe_4
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("is-type"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_is_type");
    return output;
  }

  vx_test::Type_testcase f_is_type_from_any_typelist(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_is_type_from_any_typelist");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test_true(
      context,
      vx_type::f_is_type_from_any_typelist(
        vx_core::vx_new_boolean(false),
        vx_core::f_new(
          vx_core::t_typelist,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::t_int,
            vx_core::t_boolean
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true\n (is-type<-any-typelist\n  false\n  (typelist int boolean)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test_true(
      context,
      vx_type::f_is_type_from_any_typelist(
        vx_core::vx_new_string("a"),
        vx_core::f_new(
          vx_core::t_typelist,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::t_number,
            vx_core::t_string
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true\n (is-type<-any-typelist\n  \"a\"\n  (typelist number string)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    // testdescribe_3
    vx_test::Type_testresult testresult_3 = vx_test::f_test_true(
      context,
      vx_type::f_is_type_from_any_typelist(
        vx_core::vx_new_decimal_from_string("5.5"),
        vx_core::f_new(
          vx_core::t_typelist,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::t_string,
            vx_core::t_number
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_3 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true\n (is-type<-any-typelist\n  5.5\n  (typelist string number)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_3
    });
    // testdescribe_4
    vx_test::Type_testresult testresult_4 = vx_test::f_test_true(
      context,
      vx_type::f_is_type_from_any_typelist(
        vx_core::vx_new_int(4),
        vx_core::f_new(
          vx_core::t_typelist,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::t_string,
            vx_core::t_int
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_4 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true\n (is-type<-any-typelist\n  4\n  (typelist string int)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_4
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2,
      testdescribe_3,
      testdescribe_4
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("is-type<-any-typelist"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_is_type_from_any_typelist");
    return output;
  }

  vx_test::Type_testcase f_length_from_string(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_length_from_string");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::vx_new_int(4),
      vx_type::f_length_from_string(vx_core::vx_new_string("abcd"))
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n 4\n (length<-string \"abcd\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::vx_new_int(0),
      vx_type::f_length_from_string(vx_core::vx_new_string(""))
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n 0\n (length<-string \"\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("length<-string"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_length_from_string");
    return output;
  }

  vx_test::Type_testcase f_string_from_int(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_string_from_int");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::vx_new_string("4"),
      vx_type::f_string_from_int(vx_core::vx_new_int(4))
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"4\"\n (string<-int 4))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::vx_new_string("51"),
      vx_type::f_string_from_int(vx_core::vx_new_int(51))
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"51\"\n (string<-int 51))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    // testdescribe_3
    vx_test::Type_testresult testresult_3 = vx_test::f_test(
      context,
      vx_core::vx_new_string("notanumber"),
      vx_type::f_string_from_int(
        vx_core::c_notanumber
      )
    );
    vx_test::Type_testdescribe testdescribe_3 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"notanumber\"\n (string<-int notanumber))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_3
    });
    // testdescribe_4
    vx_test::Type_testresult testresult_4 = vx_test::f_test(
      context,
      vx_core::vx_new_string("infinity"),
      vx_type::f_string_from_int(
        vx_core::c_infinity
      )
    );
    vx_test::Type_testdescribe testdescribe_4 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"infinity\"\n (string<-int infinity))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_4
    });
    // testdescribe_5
    vx_test::Type_testresult testresult_5 = vx_test::f_test(
      context,
      vx_core::vx_new_string("neginfinity"),
      vx_type::f_string_from_int(
        vx_core::c_neginfinity
      )
    );
    vx_test::Type_testdescribe testdescribe_5 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"neginfinity\"\n (string<-int neginfinity))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_5
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2,
      testdescribe_3,
      testdescribe_4,
      testdescribe_5
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("string<-int"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_string_from_int");
    return output;
  }

  vx_test::Type_testcase f_string_from_string_end(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_string_from_string_end");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::vx_new_string("abc"),
      vx_type::f_string_from_string_end(vx_core::vx_new_string("abcd"), vx_core::vx_new_int(3))
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"abc\"\n (string<-string-end\n  \"abcd\"\n  3))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::vx_new_string("ab"),
      vx_type::f_string_from_string_end(vx_core::vx_new_string("abcd"), vx_core::vx_new_int(2))
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"ab\"\n (string<-string-end\n  \"abcd\"\n  2))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("string<-string-end"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_string_from_string_end");
    return output;
  }

  vx_test::Type_testcase f_string_from_string_start(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_string_from_string_start");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::vx_new_string("abcd"),
      vx_type::f_string_from_string_start(vx_core::vx_new_string("abcd"), vx_core::vx_new_int(1))
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"abcd\"\n (string<-string-start\n  \"abcd\"\n  1))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::vx_new_string("bcd"),
      vx_type::f_string_from_string_start(vx_core::vx_new_string("abcd"), vx_core::vx_new_int(2))
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"bcd\"\n (string<-string-start\n  \"abcd\"\n  2))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("string<-string-start"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_string_from_string_start");
    return output;
  }

  vx_test::Type_testcase f_string_from_string_start_end(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_string_from_string_start_end");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::vx_new_string("abc"),
      vx_type::f_string_from_string_start_end(vx_core::vx_new_string("abcd"), vx_core::vx_new_int(1), vx_core::vx_new_int(3))
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"abc\"\n (string<-string-start-end\n  \"abcd\"\n  1\n  3))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::vx_new_string("bc"),
      vx_type::f_string_from_string_start_end(vx_core::vx_new_string("abcd"), vx_core::vx_new_int(2), vx_core::vx_new_int(3))
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"bc\"\n (string<-string-start-end\n  \"abcd\"\n  2\n  3))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    // testdescribe_3
    vx_test::Type_testresult testresult_3 = vx_test::f_test(
      context,
      vx_core::vx_new_string(""),
      vx_type::f_string_from_string_start_end(vx_core::vx_new_string("abcd"), vx_core::vx_new_int(5), vx_core::vx_new_int(6))
    );
    vx_test::Type_testdescribe testdescribe_3 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"\"\n (string<-string-start-end\n  \"abcd\"\n  5\n  6))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_3
    });
    // testdescribe_4
    vx_test::Type_testresult testresult_4 = vx_test::f_test(
      context,
      vx_core::vx_new_string("bcd"),
      vx_type::f_string_from_string_start_end(vx_core::vx_new_string("abcd"), vx_core::vx_new_int(2), vx_core::vx_new_int(5))
    );
    vx_test::Type_testdescribe testdescribe_4 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"bcd\"\n (string<-string-start-end\n  \"abcd\"\n  2\n  5))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_4
    });
    // testdescribe_5
    vx_test::Type_testresult testresult_5 = vx_test::f_test(
      context,
      vx_core::vx_new_string("bc"),
      vx_type::f_string_from_string_start_end(vx_core::vx_new_string("abcd"), vx_core::vx_new_int(2), vx_core::vx_new_int(-1))
    );
    vx_test::Type_testdescribe testdescribe_5 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"bc\"\n (string<-string-start-end\n  \"abcd\"\n  2\n  -1))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_5
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2,
      testdescribe_3,
      testdescribe_4,
      testdescribe_5
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("string<-string-start-end"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_string_from_string_start_end");
    return output;
  }

  vx_test::Type_testcase f_string_from_stringlist_join(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_string_from_stringlist_join");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::vx_new_string("a$b$c"),
      vx_type::f_string_from_stringlist_join(
        vx_core::f_new(
          vx_core::t_stringlist,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string("a"),
            vx_core::vx_new_string("b"),
            vx_core::vx_new_string("c")
          })
        ),
        vx_core::vx_new_string("$")
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"a$b$c\"\n (string<-stringlist-join\n  (stringlist \"a\" \"b\" \"c\")\n  \"$\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("string<-stringlist-join"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_string_from_stringlist_join");
    return output;
  }

  vx_test::Type_testcase f_stringlist_from_string_split(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_stringlist_from_string_split");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_core::t_stringlist,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string("a"),
          vx_core::vx_new_string("b"),
          vx_core::vx_new_string("c")
        })
      ),
      vx_type::f_stringlist_from_string_split(vx_core::vx_new_string("a$b$c"), vx_core::vx_new_string("$"))
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (stringlist \"a\" \"b\" \"c\")\n (stringlist<-string-split\n  \"a$b$c\"\n  \"$\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("stringlist<-string-split"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_stringlist_from_string_split");
    return output;
  }

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {
    vx_core::vx_Type_listany listtestcase;
    listtestcase.push_back(vx_type_test::f_boolean_from_string_ends(context));
    listtestcase.push_back(vx_type_test::f_boolean_from_string_starts(context));
    listtestcase.push_back(vx_type_test::f_int_from_string_find(context));
    listtestcase.push_back(vx_type_test::f_int_from_string_findkeyword(context));
    listtestcase.push_back(vx_type_test::f_int_from_string_findlast(context));
    listtestcase.push_back(vx_type_test::f_is_string(context));
    listtestcase.push_back(vx_type_test::f_is_type(context));
    listtestcase.push_back(vx_type_test::f_is_type_from_any_typelist(context));
    listtestcase.push_back(vx_type_test::f_length_from_string(context));
    listtestcase.push_back(vx_type_test::f_string_from_int(context));
    listtestcase.push_back(vx_type_test::f_string_from_string_end(context));
    listtestcase.push_back(vx_type_test::f_string_from_string_start(context));
    listtestcase.push_back(vx_type_test::f_string_from_string_start_end(context));
    listtestcase.push_back(vx_type_test::f_string_from_stringlist_join(context));
    listtestcase.push_back(vx_type_test::f_stringlist_from_string_split(context));
    vx_test::Type_testcaselist output = vx_core::vx_any_from_any(
      vx_test::t_testcaselist,
      vx_test::t_testcaselist->vx_new_from_list(listtestcase)
    );
    return output;
  }

  vx_test::Type_testcoveragesummary test_coveragesummary() {
    vx_test::Type_testcoveragesummary output = vx_core::vx_new(vx_test::t_testcoveragesummary, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":constnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(100), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":docnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(79), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(19), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(24)
      }),
      vx_core::vx_new_string(":funcnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(62), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(15), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(24)
      }),
      vx_core::vx_new_string(":bigospacenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(24)
      }),
      vx_core::vx_new_string(":bigotimenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(24)
      }),
      vx_core::vx_new_string(":totalnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(62), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(15), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(24)
      }),
      vx_core::vx_new_string(":typenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(100), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(0)
      })
    });
    return output;
  }

  vx_test::Type_testcoveragedetail test_coveragedetail() {
    vx_test::Type_testcoveragedetail output = vx_core::vx_new(vx_test::t_testcoveragedetail, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":typemap"), vx_core::vx_new(vx_core::t_intmap, {
        
      }),
      vx_core::vx_new_string(":constmap"), vx_core::vx_new(vx_core::t_intmap, {
        
      }),
      vx_core::vx_new_string(":funcmap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":allowtypenames<-type"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":allowtypes<-type"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":any<-int"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":boolean<-string-ends"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":boolean<-string-starts"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":int<-string-find"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":int<-string-findkeyword"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":int<-string-findlast"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":is-boolean"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":is-decimal"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":is-none"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":is-string"), vx_core::vx_new_int(4),
        vx_core::vx_new_string(":is-type"), vx_core::vx_new_int(4),
        vx_core::vx_new_string(":is-type<-any-typelist"), vx_core::vx_new_int(4),
        vx_core::vx_new_string(":length<-string"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":string<-int"), vx_core::vx_new_int(5),
        vx_core::vx_new_string(":string<-string-end"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":string<-string-start"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":string<-string-start-end"), vx_core::vx_new_int(5),
        vx_core::vx_new_string(":string<-stringlist-join"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":stringlist<-string-split"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":traitnames<-any"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":traits<-any"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":traits<-typedef"), vx_core::vx_new_int(0)
      })
    });
    return output;
  }

  vx_test::Type_testpackage test_package(vx_core::Type_context context) {
    vx_test::Type_testcaselist testcaselist = vx_type_test::test_cases(context);
    vx_test::Type_testcoveragesummary testcoveragesummary = vx_type_test::test_coveragesummary();
    vx_test::Type_testcoveragedetail testcoveragedetail = vx_type_test::test_coveragedetail();
    vx_test::Type_testpackage output = vx_core::vx_new(vx_test::t_testpackage, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":caselist"), testcaselist,
      vx_core::vx_new_string(":coveragesummary"), testcoveragesummary,
      vx_core::vx_new_string(":coveragedetail"), testcoveragedetail
    });
    return output;
  }

}
