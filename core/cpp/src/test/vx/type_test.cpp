#include "../../main/vx/type.hpp"
#include "../../main/vx/core.hpp"
#include "../../main/vx/test.hpp"

namespace vx_type_test {

  vx_test::Type_testcase f_is_string(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/type"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("is-string"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(
        vx_test::t_testdescribelist,
        {
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test-true  (is-string \"\"))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test_true(
                vx_type::f_is_string(vx_core::t_string->vx_new_from_string("")),
                context
              )
          }),
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test-true  (is-string \"a\"))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test_true(
                vx_type::f_is_string(vx_core::t_string->vx_new_from_string("a")),
                context
              )
          }),
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test-false (is-string 5))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test_false(
                vx_type::f_is_string(vx_core::t_int->vx_new_from_int(5)),
                context
              )
          }),
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test-false (is-string (list)))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test_false(
                vx_type::f_is_string(
                  vx_core::f_empty(
                    vx_core::t_list
                  )
                ),
                context
              )
          })
        }
      )
    });
    return output;
  }

  vx_test::Type_testcase f_is_type(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/type"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("is-type"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(
        vx_test::t_testdescribelist,
        {
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test-true (is-type false boolean))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test_true(
                vx_type::f_is_type(
                  vx_core::t_boolean->vx_new_from_boolean(false),
                  vx_core::t_boolean
                ),
                context
              )
          }),
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test-true (is-type \"a\"   string))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test_true(
                vx_type::f_is_type(
                  vx_core::t_string->vx_new_from_string("a"),
                  vx_core::t_string
                ),
                context
              )
          }),
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test-true (is-type 5.5   number))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test_true(
                vx_type::f_is_type(
                  vx_core::t_decimal->vx_new_from_string("5.5"),
                  vx_core::t_number
                ),
                context
              )
          }),
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test-true (is-type 4     int))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test_true(
                vx_type::f_is_type(
                  vx_core::t_int->vx_new_from_int(4),
                  vx_core::t_int
                ),
                context
              )
          })
        }
      )
    });
    return output;
  }

  vx_test::Type_testcase f_is_type_from_any_typelist(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/type"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("is-type<-any-typelist"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(
        vx_test::t_testdescribelist,
        {
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test-true\n (is-type<-any-typelist\n  false (typelist int boolean)))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test_true(
                vx_type::f_is_type_from_any_typelist(
                  vx_core::t_boolean->vx_new_from_boolean(false),
                  vx_core::f_new(
                    vx_core::t_typelist,
                    vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                      vx_core::t_int,
                      vx_core::t_boolean
                    })
                  )
                ),
                context
              )
          }),
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test-true\n (is-type<-any-typelist\n  \"a\"   (typelist number string)))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test_true(
                vx_type::f_is_type_from_any_typelist(
                  vx_core::t_string->vx_new_from_string("a"),
                  vx_core::f_new(
                    vx_core::t_typelist,
                    vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                      vx_core::t_number,
                      vx_core::t_string
                    })
                  )
                ),
                context
              )
          }),
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test-true\n (is-type<-any-typelist\n  5.5   (typelist string number)))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test_true(
                vx_type::f_is_type_from_any_typelist(
                  vx_core::t_decimal->vx_new_from_string("5.5"),
                  vx_core::f_new(
                    vx_core::t_typelist,
                    vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                      vx_core::t_string,
                      vx_core::t_number
                    })
                  )
                ),
                context
              )
          }),
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test-true\n (is-type<-any-typelist\n  4     (typelist string int)))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test_true(
                vx_type::f_is_type_from_any_typelist(
                  vx_core::t_int->vx_new_from_int(4),
                  vx_core::f_new(
                    vx_core::t_typelist,
                    vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                      vx_core::t_string,
                      vx_core::t_int
                    })
                  )
                ),
                context
              )
          })
        }
      )
    });
    return output;
  }

  vx_test::Type_testcase f_length_from_string(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/type"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("length<-string"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(
        vx_test::t_testdescribelist,
        {
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test 4 (length<-string \"abcd\"))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
                vx_core::t_int->vx_new_from_int(4),
                vx_type::f_length_from_string(vx_core::t_string->vx_new_from_string("abcd")),
                context
              )
          }),
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test 0 (length<-string \"\"))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
                vx_core::t_int->vx_new_from_int(0),
                vx_type::f_length_from_string(vx_core::t_string->vx_new_from_string("")),
                context
              )
          })
        }
      )
    });
    return output;
  }

  vx_test::Type_testcase f_string_from_int(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/type"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("string<-int"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(
        vx_test::t_testdescribelist,
        {
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test \"4\"           (string<-int 4))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
                vx_core::t_string->vx_new_from_string("4"),
                vx_type::f_string_from_int(vx_core::t_int->vx_new_from_int(4)),
                context
              )
          }),
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test \"51\"          (string<-int 51))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
                vx_core::t_string->vx_new_from_string("51"),
                vx_type::f_string_from_int(vx_core::t_int->vx_new_from_int(51)),
                context
              )
          }),
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test \"notanumber\"  (string<-int notanumber))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
                vx_core::t_string->vx_new_from_string("notanumber"),
                vx_type::f_string_from_int(
                  vx_core::c_notanumber
                ),
                context
              )
          }),
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test \"infinity\"    (string<-int infinity))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
                vx_core::t_string->vx_new_from_string("infinity"),
                vx_type::f_string_from_int(
                  vx_core::c_infinity
                ),
                context
              )
          }),
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test \"neginfinity\" (string<-int neginfinity))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
                vx_core::t_string->vx_new_from_string("neginfinity"),
                vx_type::f_string_from_int(
                  vx_core::c_neginfinity
                ),
                context
              )
          })
        }
      )
    });
    return output;
  }

  vx_test::Type_testcase f_string_from_string_end(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/type"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("string<-string-end"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(
        vx_test::t_testdescribelist,
        {
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test \"abc\" (string<-string-end \"abcd\" 3))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
                vx_core::t_string->vx_new_from_string("abc"),
                vx_type::f_string_from_string_end(vx_core::t_string->vx_new_from_string("abcd"), vx_core::t_int->vx_new_from_int(3)),
                context
              )
          }),
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test \"ab\"  (string<-string-end \"abcd\" 2))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
                vx_core::t_string->vx_new_from_string("ab"),
                vx_type::f_string_from_string_end(vx_core::t_string->vx_new_from_string("abcd"), vx_core::t_int->vx_new_from_int(2)),
                context
              )
          })
        }
      )
    });
    return output;
  }

  vx_test::Type_testcase f_string_from_string_start(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/type"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("string<-string-start"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(
        vx_test::t_testdescribelist,
        {
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test \"abcd\" (string<-string-start \"abcd\" 0))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
                vx_core::t_string->vx_new_from_string("abcd"),
                vx_type::f_string_from_string_start(vx_core::t_string->vx_new_from_string("abcd"), vx_core::t_int->vx_new_from_int(0)),
                context
              )
          }),
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test \"bcd\"  (string<-string-start \"abcd\" 1))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
                vx_core::t_string->vx_new_from_string("bcd"),
                vx_type::f_string_from_string_start(vx_core::t_string->vx_new_from_string("abcd"), vx_core::t_int->vx_new_from_int(1)),
                context
              )
          })
        }
      )
    });
    return output;
  }

  vx_test::Type_testcase f_string_from_string_start_end(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/type"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("string<-string-start-end"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(
        vx_test::t_testdescribelist,
        {
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test \"abc\" (string<-string-start-end \"abcd\" 0 3))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
                vx_core::t_string->vx_new_from_string("abc"),
                vx_type::f_string_from_string_start_end(vx_core::t_string->vx_new_from_string("abcd"), vx_core::t_int->vx_new_from_int(0), vx_core::t_int->vx_new_from_int(3)),
                context
              )
          }),
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test \"bc\"  (string<-string-start-end \"abcd\" 1 3))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
                vx_core::t_string->vx_new_from_string("bc"),
                vx_type::f_string_from_string_start_end(vx_core::t_string->vx_new_from_string("abcd"), vx_core::t_int->vx_new_from_int(1), vx_core::t_int->vx_new_from_int(3)),
                context
              )
          }),
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test \"\"    (string<-string-start-end \"abcd\" 5 6))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
                vx_core::t_string->vx_new_from_string(""),
                vx_type::f_string_from_string_start_end(vx_core::t_string->vx_new_from_string("abcd"), vx_core::t_int->vx_new_from_int(5), vx_core::t_int->vx_new_from_int(6)),
                context
              )
          }),
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test \"bcd\" (string<-string-start-end \"abcd\" 1 5))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
                vx_core::t_string->vx_new_from_string("bcd"),
                vx_type::f_string_from_string_start_end(vx_core::t_string->vx_new_from_string("abcd"), vx_core::t_int->vx_new_from_int(1), vx_core::t_int->vx_new_from_int(5)),
                context
              )
          })
        }
      )
    });
    return output;
  }

  vx_test::Type_testcase f_string_from_stringlist_join(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/type"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("string<-stringlist-join"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(
        vx_test::t_testdescribelist,
        {
          vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
            vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test \"a$b$c\" (string<-stringlist-join (stringlist \"a\" \"b\" \"c\") \"$\"))"),
            vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
                vx_core::t_string->vx_new_from_string("a$b$c"),
                vx_type::f_string_from_stringlist_join(
                  vx_core::f_new(
                    vx_core::t_stringlist,
                    vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                      vx_core::t_string->vx_new_from_string("a"),
                      vx_core::t_string->vx_new_from_string("b"),
                      vx_core::t_string->vx_new_from_string("c")
                    })
                  ),
                  vx_core::t_string->vx_new_from_string("$")
                ),
                context
              )
          })
        }
      )
    });
    return output;
  }

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {
    vx_core::vx_Type_listany arraylisttestcase;
    arraylisttestcase.push_back(vx_type_test::f_is_string(context));
    arraylisttestcase.push_back(vx_type_test::f_is_type(context));
    arraylisttestcase.push_back(vx_type_test::f_is_type_from_any_typelist(context));
    arraylisttestcase.push_back(vx_type_test::f_length_from_string(context));
    arraylisttestcase.push_back(vx_type_test::f_string_from_int(context));
    arraylisttestcase.push_back(vx_type_test::f_string_from_string_end(context));
    arraylisttestcase.push_back(vx_type_test::f_string_from_string_start(context));
    arraylisttestcase.push_back(vx_type_test::f_string_from_string_start_end(context));
    arraylisttestcase.push_back(vx_type_test::f_string_from_stringlist_join(context));
    vx_test::Type_testcaselist output = vx_test::t_testcaselist->vx_new_from_list(vx_test::t_testcaselist, arraylisttestcase);
    return output;
  }

  vx_test::Type_testcoveragesummary test_coveragesummary() {
    return vx_test::t_testcoveragesummary->vx_new(vx_test::t_testcoveragesummary, {
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/type"),
      vx_core::t_string->vx_new_from_string(":constnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(100), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(0)
      }),
      vx_core::t_string->vx_new_from_string(":docnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(61), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(11), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(18)
      }),
      vx_core::t_string->vx_new_from_string(":funcnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(50), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(9), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(18)
      }),
      vx_core::t_string->vx_new_from_string(":ospacenums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(18)
      }),
      vx_core::t_string->vx_new_from_string(":otimenums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(18)
      }),
      vx_core::t_string->vx_new_from_string(":totalnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(50), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(9), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(18)
      }),
      vx_core::t_string->vx_new_from_string(":typenums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(100), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(0)
      })
    });
  }

  vx_test::Type_testcoveragedetail test_coveragedetail() {
    return vx_test::t_testcoveragedetail->vx_new(vx_test::t_testcoveragedetail, {
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/type"),
      vx_core::t_string->vx_new_from_string(":typemap"), vx_core::t_intmap->vx_new(vx_core::t_intmap, {
        
      }),
      vx_core::t_string->vx_new_from_string(":constmap"), vx_core::t_intmap->vx_new(vx_core::t_intmap, {
        
      }),
      vx_core::t_string->vx_new_from_string(":funcmap"), vx_core::t_intmap->vx_new(vx_core::t_intmap, {
              vx_core::t_string->vx_new_from_string(":allowtypenames<-type"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":allowtypes<-type"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":is-boolean"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":is-decimal"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":is-float"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":is-none"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":is-string"), vx_core::t_int->vx_new_from_int(4),
              vx_core::t_string->vx_new_from_string(":is-type"), vx_core::t_int->vx_new_from_int(4),
              vx_core::t_string->vx_new_from_string(":is-type<-any-typelist"), vx_core::t_int->vx_new_from_int(4),
              vx_core::t_string->vx_new_from_string(":length<-string"), vx_core::t_int->vx_new_from_int(2),
              vx_core::t_string->vx_new_from_string(":string<-int"), vx_core::t_int->vx_new_from_int(5),
              vx_core::t_string->vx_new_from_string(":string<-string-end"), vx_core::t_int->vx_new_from_int(2),
              vx_core::t_string->vx_new_from_string(":string<-string-start"), vx_core::t_int->vx_new_from_int(2),
              vx_core::t_string->vx_new_from_string(":string<-string-start-end"), vx_core::t_int->vx_new_from_int(4),
              vx_core::t_string->vx_new_from_string(":string<-stringlist-join"), vx_core::t_int->vx_new_from_int(1),
              vx_core::t_string->vx_new_from_string(":traitnames<-any"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":traits<-any"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":traits<-typedef"), vx_core::t_int->vx_new_from_int(0)
      })
    });
  }

  vx_test::Type_testpackage test_package(vx_core::Type_context context) {
    vx_test::Type_testcaselist testcaselist = test_cases(context);
    vx_test::Type_testpackage output = vx_test::t_testpackage->vx_new(vx_test::t_testpackage, {
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/type"), 
      vx_core::t_string->vx_new_from_string(":caselist"), testcaselist,
      vx_core::t_string->vx_new_from_string(":coveragesummary"), test_coveragesummary(),
      vx_core::t_string->vx_new_from_string(":coveragedetail"), test_coveragedetail()
    });
    return output;
  }

}
