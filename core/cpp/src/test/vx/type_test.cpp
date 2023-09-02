#include "../../main/vx/type.hpp"
#include "../../main/vx/core.hpp"
#include "../../main/vx/test.hpp"

#include "type_test.hpp"

namespace vx_type_test {

  vx_test::Type_testcase f_is_string(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("is-string"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true  (is-string \"\"))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_type::f_is_string(vx_core::vx_new_string("")),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true  (is-string \"a\"))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_type::f_is_string(vx_core::vx_new_string("a")),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-false (is-string 5))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_false(
              vx_type::f_is_string(vx_core::vx_new_int(5)),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-false (is-string (list)))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_false(
              vx_type::f_is_string(
                vx_core::f_empty(
                  vx_core::t_list
                )
              ),
              context
            )
          })
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_is_type(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("is-type"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (is-type false boolean))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_type::f_is_type(
                vx_core::vx_new_boolean(false),
                vx_core::t_boolean
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (is-type \"a\"   string))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_type::f_is_type(
                vx_core::vx_new_string("a"),
                vx_core::t_string
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (is-type 5.5   number))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_type::f_is_type(
                vx_core::vx_new_decimal_from_string("5.5"),
                vx_core::t_number
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (is-type 4     int))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_type::f_is_type(
                vx_core::vx_new_int(4),
                vx_core::t_int
              ),
              context
            )
          })
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_is_type_from_any_typelist(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("is-type<-any-typelist"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true\n (is-type<-any-typelist\n  false (typelist int boolean)))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_type::f_is_type_from_any_typelist(
                vx_core::vx_new_boolean(false),
                vx_core::f_new(
                  vx_core::t_typelist,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::t_int,
                    vx_core::t_boolean
                  })
                )
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true\n (is-type<-any-typelist\n  \"a\"   (typelist number string)))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_type::f_is_type_from_any_typelist(
                vx_core::vx_new_string("a"),
                vx_core::f_new(
                  vx_core::t_typelist,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::t_number,
                    vx_core::t_string
                  })
                )
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true\n (is-type<-any-typelist\n  5.5   (typelist string number)))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_type::f_is_type_from_any_typelist(
                vx_core::vx_new_decimal_from_string("5.5"),
                vx_core::f_new(
                  vx_core::t_typelist,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::t_string,
                    vx_core::t_number
                  })
                )
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true\n (is-type<-any-typelist\n  4     (typelist string int)))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_type::f_is_type_from_any_typelist(
                vx_core::vx_new_int(4),
                vx_core::f_new(
                  vx_core::t_typelist,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::t_string,
                    vx_core::t_int
                  })
                )
              ),
              context
            )
          })
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_length_from_string(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("length<-string"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 4 (length<-string \"abcd\"))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(4),
              vx_type::f_length_from_string(vx_core::vx_new_string("abcd")),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 0 (length<-string \"\"))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(0),
              vx_type::f_length_from_string(vx_core::vx_new_string("")),
              context
            )
          })
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_string_from_int(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("string<-int"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"4\"           (string<-int 4))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("4"),
              vx_type::f_string_from_int(vx_core::vx_new_int(4)),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"51\"          (string<-int 51))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("51"),
              vx_type::f_string_from_int(vx_core::vx_new_int(51)),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"notanumber\"  (string<-int notanumber))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("notanumber"),
              vx_type::f_string_from_int(
                vx_core::c_notanumber()
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"infinity\"    (string<-int infinity))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("infinity"),
              vx_type::f_string_from_int(
                vx_core::c_infinity()
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"neginfinity\" (string<-int neginfinity))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("neginfinity"),
              vx_type::f_string_from_int(
                vx_core::c_neginfinity()
              ),
              context
            )
          })
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_string_from_string_end(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("string<-string-end"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"abc\" (string<-string-end \"abcd\" 3))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("abc"),
              vx_type::f_string_from_string_end(vx_core::vx_new_string("abcd"), vx_core::vx_new_int(3)),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"ab\"  (string<-string-end \"abcd\" 2))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("ab"),
              vx_type::f_string_from_string_end(vx_core::vx_new_string("abcd"), vx_core::vx_new_int(2)),
              context
            )
          })
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_string_from_string_start(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("string<-string-start"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"abcd\" (string<-string-start \"abcd\" 0))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("abcd"),
              vx_type::f_string_from_string_start(vx_core::vx_new_string("abcd"), vx_core::vx_new_int(0)),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"bcd\"  (string<-string-start \"abcd\" 1))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("bcd"),
              vx_type::f_string_from_string_start(vx_core::vx_new_string("abcd"), vx_core::vx_new_int(1)),
              context
            )
          })
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_string_from_string_start_end(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("string<-string-start-end"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"abc\" (string<-string-start-end \"abcd\" 0 3))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("abc"),
              vx_type::f_string_from_string_start_end(vx_core::vx_new_string("abcd"), vx_core::vx_new_int(0), vx_core::vx_new_int(3)),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"bc\"  (string<-string-start-end \"abcd\" 1 3))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("bc"),
              vx_type::f_string_from_string_start_end(vx_core::vx_new_string("abcd"), vx_core::vx_new_int(1), vx_core::vx_new_int(3)),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"\"    (string<-string-start-end \"abcd\" 5 6))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string(""),
              vx_type::f_string_from_string_start_end(vx_core::vx_new_string("abcd"), vx_core::vx_new_int(5), vx_core::vx_new_int(6)),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"bcd\" (string<-string-start-end \"abcd\" 1 5))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("bcd"),
              vx_type::f_string_from_string_start_end(vx_core::vx_new_string("abcd"), vx_core::vx_new_int(1), vx_core::vx_new_int(5)),
              context
            )
          })
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_string_from_stringlist_join(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("string<-stringlist-join"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"a$b$c\" (string<-stringlist-join (stringlist \"a\" \"b\" \"c\") \"$\"))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/type"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
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
              ),
              context
            )
          })
        })
      )
    });
    return output;
  }

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {
    vx_core::vx_Type_listany listtestcase;
    listtestcase.push_back(vx_type_test::f_is_string(context));
    listtestcase.push_back(vx_type_test::f_is_type(context));
    listtestcase.push_back(vx_type_test::f_is_type_from_any_typelist(context));
    listtestcase.push_back(vx_type_test::f_length_from_string(context));
    listtestcase.push_back(vx_type_test::f_string_from_int(context));
    listtestcase.push_back(vx_type_test::f_string_from_string_end(context));
    listtestcase.push_back(vx_type_test::f_string_from_string_start(context));
    listtestcase.push_back(vx_type_test::f_string_from_string_start_end(context));
    listtestcase.push_back(vx_type_test::f_string_from_stringlist_join(context));
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
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(61), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(11), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(18)
      }),
      vx_core::vx_new_string(":funcnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(50), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(9), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(18)
      }),
      vx_core::vx_new_string(":bigospacenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(18)
      }),
      vx_core::vx_new_string(":bigotimenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(18)
      }),
      vx_core::vx_new_string(":totalnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(50), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(9), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(18)
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
        vx_core::vx_new_string(":is-boolean"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":is-decimal"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":is-float"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":is-none"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":is-string"), vx_core::vx_new_int(4),
        vx_core::vx_new_string(":is-type"), vx_core::vx_new_int(4),
        vx_core::vx_new_string(":is-type<-any-typelist"), vx_core::vx_new_int(4),
        vx_core::vx_new_string(":length<-string"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":string<-int"), vx_core::vx_new_int(5),
        vx_core::vx_new_string(":string<-string-end"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":string<-string-start"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":string<-string-start-end"), vx_core::vx_new_int(4),
        vx_core::vx_new_string(":string<-stringlist-join"), vx_core::vx_new_int(1),
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
