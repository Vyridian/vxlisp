#include "../../main/vx/core.hpp"
#include "../../main/vx/test.hpp"

namespace vx_core_test {

  vx_test::Type_testcase t_boolean(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("boolean"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true true)"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::vx_new_boolean(true),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-false false)"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_false(
              vx_core::vx_new_boolean(false),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (boolean true))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_new(
                vx_core::t_boolean(),
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_boolean(true)
                })
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-false (boolean false))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_false(
              vx_core::f_new(
                vx_core::t_boolean(),
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_boolean(false)
                })
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase t_float(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("float"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 4.5 (float 4.5))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_decimal_from_string("4.5"),
              vx_core::f_new(
                vx_core::t_float(),
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_decimal_from_string("4.5")
                })
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase t_int(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("int"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true  (is-int 4))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_is_int(vx_core::vx_new_int(4)),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true  (is-int \"4\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_is_int(vx_core::vx_new_string("4")),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true  (is-int infinity))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_is_int(
                vx_core::c_infinity()
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true  (is-int neginfinity))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_is_int(
                vx_core::c_neginfinity()
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true  (is-int notanumber))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_is_int(
                vx_core::c_notanumber()
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-false (is-int \"a\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_false(
              vx_core::f_is_int(vx_core::vx_new_string("a")),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-false (is-int 5.5))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_false(
              vx_core::f_is_int(vx_core::vx_new_decimal_from_string("5.5")),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase t_string(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("string"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"a\" (string \"a\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("a"),
              vx_core::f_new(
                vx_core::t_string(),
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_string("a")
                })
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"ab\" (string \"a\" \"b\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("ab"),
              vx_core::f_new(
                vx_core::t_string(),
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_string("a"),
                  vx_core::vx_new_string("b")
                })
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase c_false(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("false"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-false false)"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_false(
              vx_core::vx_new_boolean(false),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase c_true(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("true"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true true)"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::vx_new_boolean(true),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_not(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("!"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-false false)"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_false(
              vx_core::vx_new_boolean(false),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-false (! true))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_false(
              vx_core::f_not(
                vx_core::vx_new_boolean(true)
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_ne(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("!="),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-ne true false)"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_ne(
              vx_core::vx_new_boolean(true),
              vx_core::vx_new_boolean(false),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-ne \"a\" \"b\")"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_ne(vx_core::vx_new_string("a"), vx_core::vx_new_string("b"), context)
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_multiply(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("*"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 6 (* 3 2))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(6),
              vx_core::f_multiply(vx_core::vx_new_int(3), vx_core::vx_new_int(2)),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test -10 (* 5 -2))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(-10),
              vx_core::f_multiply(vx_core::vx_new_int(5), vx_core::vx_new_int(-2)),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_multiply_1(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("*_1"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 6.4 (* 3.2 2))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_decimal_from_string("6.4"),
              vx_core::f_multiply_1((vx_core::Type_number)vx_core::vx_new_decimal_from_string("3.2"), (vx_core::Type_number)vx_core::vx_new_int(2)),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test -10.2 (* 5.1 -2))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_decimal_from_string("-10.2"),
              vx_core::f_multiply_1((vx_core::Type_number)vx_core::vx_new_decimal_from_string("5.1"), (vx_core::Type_number)vx_core::vx_new_int(-2)),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_multiply_2(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("*_2"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 24 (* 3 2 4))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(24),
              vx_core::f_multiply_2(
                vx_core::vx_new(vx_core::t_intlist(), {
                  vx_core::vx_new_int(3),
                  vx_core::vx_new_int(2),
                  vx_core::vx_new_int(4)
                })
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test -20 (* 5 -2 2))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(-20),
              vx_core::f_multiply_2(
                vx_core::vx_new(vx_core::t_intlist(), {
                  vx_core::vx_new_int(5),
                  vx_core::vx_new_int(-2),
                  vx_core::vx_new_int(2)
                })
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_multiply_3(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("*_3"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 24 (* 3 2 4))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(24),
              vx_core::f_multiply_2(
                vx_core::vx_new(vx_core::t_intlist(), {
                  vx_core::vx_new_int(3),
                  vx_core::vx_new_int(2),
                  vx_core::vx_new_int(4)
                })
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test -20 (* 5 -2 2))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(-20),
              vx_core::f_multiply_2(
                vx_core::vx_new(vx_core::t_intlist(), {
                  vx_core::vx_new_int(5),
                  vx_core::vx_new_int(-2),
                  vx_core::vx_new_int(2)
                })
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_plus(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("+"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 5 (+ 2 3))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(5),
              vx_core::f_plus(vx_core::vx_new_int(2), vx_core::vx_new_int(3)),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 3 (+ 5 -2))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(3),
              vx_core::f_plus(vx_core::vx_new_int(5), vx_core::vx_new_int(-2)),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_plus_1(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("+_1"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 5 (+ 2  3))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(5),
              vx_core::f_plus(vx_core::vx_new_int(2), vx_core::vx_new_int(3)),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 3 (+ 5 -2))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(3),
              vx_core::f_plus(vx_core::vx_new_int(5), vx_core::vx_new_int(-2)),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_plus1(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("+1"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test  3 (+1  2))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(3),
              vx_core::f_plus1(vx_core::vx_new_int(2)),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test -1 (+1 -2))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(-1),
              vx_core::f_plus1(vx_core::vx_new_int(-2)),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_minus(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("-"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 1 (- 3 2))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(1),
              vx_core::f_minus(vx_core::vx_new_int(3), vx_core::vx_new_int(2)),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 7 (- 5 -2))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(7),
              vx_core::f_minus(vx_core::vx_new_int(5), vx_core::vx_new_int(-2)),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_minus_1(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("-_1"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 5 (+ 2 3))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(5),
              vx_core::f_plus(vx_core::vx_new_int(2), vx_core::vx_new_int(3)),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 3 (+ 5 -2))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(3),
              vx_core::f_plus(vx_core::vx_new_int(5), vx_core::vx_new_int(-2)),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_divide(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("/"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 3 (/ 6 2))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(3),
              vx_core::f_divide((vx_core::Type_number)vx_core::vx_new_int(6), (vx_core::Type_number)vx_core::vx_new_int(2)),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test -5 (/ 10 -2))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(-5),
              vx_core::f_divide((vx_core::Type_number)vx_core::vx_new_int(10), (vx_core::Type_number)vx_core::vx_new_int(-2)),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_lt(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("<"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (< 2 3))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_lt(vx_core::vx_new_int(2), vx_core::vx_new_int(3)),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_lt_1(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("<_1"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (< 2 3))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_lt(vx_core::vx_new_int(2), vx_core::vx_new_int(3)),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (< \"b\" \"d\" \"z\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_lt_1(
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_string("b"),
                  vx_core::vx_new_string("d"),
                  vx_core::vx_new_string("z")
                })
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_chainfirst(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("<-"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (*\n  (+\n   (- 5 3)\n   3)\n  2)\n (<-\n  5\n  (- 3)\n  (+ 3)\n  (* 2)))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::f_multiply(
                vx_core::f_plus(
                  vx_core::f_minus(vx_core::vx_new_int(5), vx_core::vx_new_int(3)),
                  vx_core::vx_new_int(3)
                ),
                vx_core::vx_new_int(2)
              ),
              vx_core::f_multiply(
                vx_core::f_plus(
                  vx_core::f_minus(vx_core::vx_new_int(5), vx_core::vx_new_int(3)),
                  vx_core::vx_new_int(3)
                ),
                vx_core::vx_new_int(2)
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_chainlast(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("<<-"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (* (+ (- 3 5) 3) 2)\n (<<-\n  5\n  (- 3)\n  (+ 3)\n  (* 2)))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::f_multiply(
                vx_core::f_plus(
                  vx_core::f_minus(vx_core::vx_new_int(3), vx_core::vx_new_int(5)),
                  vx_core::vx_new_int(3)
                ),
                vx_core::vx_new_int(2)
              ),
              vx_core::f_multiply(
                vx_core::vx_new_int(2),
                vx_core::f_plus(
                  vx_core::vx_new_int(3),
                  vx_core::f_minus(vx_core::vx_new_int(3), vx_core::vx_new_int(5))
                )
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_le(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("<="),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (<= 2 3))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_le(vx_core::vx_new_int(2), vx_core::vx_new_int(3)),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_le_1(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("<=_1"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (<= \"b\" \"d\" \"z\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_le_1(
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_string("b"),
                  vx_core::vx_new_string("d"),
                  vx_core::vx_new_string("z")
                })
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_eq(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("="),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (= true true))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_eq(
                vx_core::vx_new_boolean(true),
                vx_core::vx_new_boolean(true)
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (= 2 2))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_eq(vx_core::vx_new_int(2), vx_core::vx_new_int(2)),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (= \"a\" \"a\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_eq(vx_core::vx_new_string("a"), vx_core::vx_new_string("a")),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (= (stringlist \"a\" \"b\" \"c\") (new stringlist \"a\" \"b\" \"c\")))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_eq(
                vx_core::f_new(
                  vx_core::t_stringlist(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string("a"),
                    vx_core::vx_new_string("b"),
                    vx_core::vx_new_string("c")
                  })
                ),
                vx_core::f_new(
                  vx_core::t_stringlist(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string("a"),
                    vx_core::vx_new_string("b"),
                    vx_core::vx_new_string("c")
                  })
                )
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (= (stringmap :a \"1\" :b \"2\") (new stringmap :a \"1\" :b \"2\")))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_eq(
                vx_core::f_new(
                  vx_core::t_stringmap(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":a"),
                    vx_core::vx_new_string("1"),
                    vx_core::vx_new_string(":b"),
                    vx_core::vx_new_string("2")
                  })
                ),
                vx_core::f_new(
                  vx_core::t_stringmap(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":a"),
                    vx_core::vx_new_string("1"),
                    vx_core::vx_new_string(":b"),
                    vx_core::vx_new_string("2")
                  })
                )
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_eq_1(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("=_1"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-false (= 2 2 3))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_false(
              vx_core::f_eq_1(
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_int(2),
                  vx_core::vx_new_int(2),
                  vx_core::vx_new_int(3)
                })
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_gt(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string(">"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (> 3 2))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_gt(vx_core::vx_new_int(3), vx_core::vx_new_int(2)),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_gt_1(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string(">_1"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (> \"z\" \"y\" \"b\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_gt_1(
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_string("z"),
                  vx_core::vx_new_string("y"),
                  vx_core::vx_new_string("b")
                })
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_ge(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string(">="),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (>= 3 2))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_ge(vx_core::vx_new_int(3), vx_core::vx_new_int(2)),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_ge_1(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string(">=_1"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (>= \"z\" \"b\" \"b\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_ge_1(
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_string("z"),
                  vx_core::vx_new_string("b"),
                  vx_core::vx_new_string("b")
                })
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_and(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("and"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (and true true))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_and(
                vx_core::vx_new_boolean(true),
                vx_core::vx_new_boolean(true)
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-false (and true false))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_false(
              vx_core::f_and(
                vx_core::vx_new_boolean(true),
                vx_core::vx_new_boolean(false)
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_and_1(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("and_1"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (and true true true))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_and_1(
                vx_core::vx_new(vx_core::t_booleanlist(), {
                  vx_core::vx_new_boolean(true),
                  vx_core::vx_new_boolean(true),
                  vx_core::vx_new_boolean(true)
                })
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-false (and true true false))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_false(
              vx_core::f_and_1(
                vx_core::vx_new(vx_core::t_booleanlist(), {
                  vx_core::vx_new_boolean(true),
                  vx_core::vx_new_boolean(true),
                  vx_core::vx_new_boolean(false)
                })
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_any_from_list(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("any<-list"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"b\"\n (any<-list (list \"a\" \"b\" \"c\") 1))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("b"),
              vx_core::f_any_from_list(
                vx_core::t_any(),
                vx_core::f_new(
                  vx_core::t_list(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string("a"),
                    vx_core::vx_new_string("b"),
                    vx_core::vx_new_string("c")
                  })
                ),
                vx_core::vx_new_int(1)
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"b\"\n (:1 (stringlist \"a\" \"b\" \"c\")))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("b"),
              vx_core::f_any_from_list(
                vx_core::t_string(),
                vx_core::f_new(
                  vx_core::t_stringlist(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string("a"),
                    vx_core::vx_new_string("b"),
                    vx_core::vx_new_string("c")
                  })
                ),
                vx_core::vx_new_int(1)
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_any_from_list_reduce(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("any<-list-reduce"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n 24\n (any<-list-reduce : int\n  (intlist 3 2 4)\n  1\n  (fn : int\n   [total : int\n    num   : int]\n   (* total num))\n ))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(24),
              vx_core::f_any_from_list_reduce(
                vx_core::t_int(),
                vx_core::f_new(
                  vx_core::t_intlist(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_int(3),
                    vx_core::vx_new_int(2),
                    vx_core::vx_new_int(4)
                  })
                ),
                vx_core::vx_new_int(1),
                vx_core::t_any_from_reduce()->vx_fn_new([](vx_core::Type_any total_any, vx_core::Type_any num_any) {
                  vx_core::Type_int total = vx_core::vx_any_from_any(vx_core::t_int(), total_any);
                  vx_core::Type_int num = vx_core::vx_any_from_any(vx_core::t_int(), num_any);
                  return 
                    vx_core::f_multiply(total, num);
                })
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_any_from_map(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("any<-map"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"v2\"\n (any<-map (map :a \"v1\" :b \"v2\" :c \"v3\") :b))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("v2"),
              vx_core::f_any_from_map(
                vx_core::t_any(),
                vx_core::f_new(
                  vx_core::t_map(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":a"),
                    vx_core::vx_new_string("v1"),
                    vx_core::vx_new_string(":b"),
                    vx_core::vx_new_string("v2"),
                    vx_core::vx_new_string(":c"),
                    vx_core::vx_new_string("v3")
                  })
                ),
                vx_core::vx_new_string(":b")
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_compare(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("compare"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 1 (compare 3 2))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(1),
              vx_core::f_compare(vx_core::vx_new_int(3), vx_core::vx_new_int(2)),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 1 (compare \"z\" \"a\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(1),
              vx_core::f_compare(vx_core::vx_new_string("z"), vx_core::vx_new_string("a")),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_contains(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("contains"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true  (contains \"abcde\" \"cd\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_contains(vx_core::vx_new_string("abcde"), vx_core::vx_new_string("cd")),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-false (contains \"abcde\" \"dc\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_false(
              vx_core::f_contains(vx_core::vx_new_string("abcde"), vx_core::vx_new_string("dc")),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_contains_1(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("contains_1"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true  (contains (stringlist \"1\" \"2\" \"3\") \"2\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_contains_1(
                vx_core::f_new(
                  vx_core::t_stringlist(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string("1"),
                    vx_core::vx_new_string("2"),
                    vx_core::vx_new_string("3")
                  })
                ),
                vx_core::vx_new_string("2")
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true  (contains (intlist 1 2 3) 2))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_contains_1(
                vx_core::f_new(
                  vx_core::t_intlist(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_int(1),
                    vx_core::vx_new_int(2),
                    vx_core::vx_new_int(3)
                  })
                ),
                vx_core::vx_new_int(2)
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-false (contains (list 1 \"2\" 3) 2))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_false(
              vx_core::f_contains_1(
                vx_core::f_new(
                  vx_core::t_list(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_int(1),
                    vx_core::vx_new_string("2"),
                    vx_core::vx_new_int(3)
                  })
                ),
                vx_core::vx_new_int(2)
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_empty(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("empty"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"\"     (empty string))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string(""),
              vx_core::f_empty(
                vx_core::t_string()
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test (list) (empty list))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::f_empty(
                vx_core::t_list()
              ),
              vx_core::f_empty(
                vx_core::t_list()
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test (map)  (empty map))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::f_empty(
                vx_core::t_map()
              ),
              vx_core::f_empty(
                vx_core::t_map()
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_first_from_list(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("first<-list"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"b\" (first<-list (stringlist \"b\" \"c\")))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("b"),
              vx_core::f_first_from_list(
                vx_core::t_string(),
                vx_core::f_new(
                  vx_core::t_stringlist(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string("b"),
                    vx_core::vx_new_string("c")
                  })
                )
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_first_from_list_fn_any_from_any(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("first<-list-fn-any<-any"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"b\" (first<-list-fn-any<-any (list nothing \"b\" \"c\") resolve))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("b"),
              vx_core::f_first_from_list_fn_any_from_any(
                vx_core::t_any(),
                vx_core::f_new(
                  vx_core::t_list(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::c_nothing(),
                    vx_core::vx_new_string("b"),
                    vx_core::vx_new_string("c")
                  })
                ),
                vx_core::t_resolve()
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_if(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("if"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"a\" (if (= 2 2) \"a\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("a"),
              vx_core::f_if(
                vx_core::t_string(),
                vx_core::f_eq(vx_core::vx_new_int(2), vx_core::vx_new_int(2)),
                vx_core::vx_new_string("a")
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"\"  (if : string (= 1 2) \"a\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string(""),
              vx_core::f_if(
                vx_core::t_string(),
                vx_core::f_eq(vx_core::vx_new_int(1), vx_core::vx_new_int(2)),
                vx_core::vx_new_string("a")
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_if_1(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("if_1"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"a\" (if (= 2 2) \"a\" \"b\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("a"),
              vx_core::f_if_1(
                vx_core::t_string(),
                vx_core::f_eq(vx_core::vx_new_int(2), vx_core::vx_new_int(2)),
                vx_core::vx_new_string("a"),
                vx_core::vx_new_string("b")
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"b\"  (if (= 1 2) \"a\" \"b\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("b"),
              vx_core::f_if_1(
                vx_core::t_string(),
                vx_core::f_eq(vx_core::vx_new_int(1), vx_core::vx_new_int(2)),
                vx_core::vx_new_string("a"),
                vx_core::vx_new_string("b")
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_if_2(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("if_2"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true\n (if\n  (then (= 2 3) false)\n  (then (!= 3 3) false)\n  (else (! false))))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_if_2(
                vx_core::t_any(),
                vx_core::vx_new(vx_core::t_thenelselist(), {
                  vx_core::f_then(
                    vx_core::t_boolean_from_func()->vx_fn_new([]() {
                      return vx_core::f_eq(vx_core::vx_new_int(2), vx_core::vx_new_int(3));
                    }),
                    vx_core::t_any_from_func()->vx_fn_new([]() {
                      return vx_core::vx_new_boolean(false);
                    })
                  ),
                  vx_core::f_then(
                    vx_core::t_boolean_from_func()->vx_fn_new([]() {
                      return vx_core::f_ne(vx_core::vx_new_int(3), vx_core::vx_new_int(3));
                    }),
                    vx_core::t_any_from_func()->vx_fn_new([]() {
                      return vx_core::vx_new_boolean(false);
                    })
                  ),
                  vx_core::f_else(
                    vx_core::t_any_from_func()->vx_fn_new([]() {
                      return vx_core::f_not(
                        vx_core::vx_new_boolean(false)
                      );
                    })
                  )
                })
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_int_from_string(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("int<-string"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 4 (int<-string \"4\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(4),
              vx_core::f_int_from_string(vx_core::vx_new_string("4")),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 5 (int<-string \"5.4\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(5),
              vx_core::f_int_from_string(vx_core::vx_new_string("5.4")),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 5 (int<-string \"5.9\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(5),
              vx_core::f_int_from_string(vx_core::vx_new_string("5.9")),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test notanumber  (int<-string \"notanumber\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::c_notanumber(),
              vx_core::f_int_from_string(vx_core::vx_new_string("notanumber")),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test infinity    (int<-string \"infinity\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::c_infinity(),
              vx_core::f_int_from_string(vx_core::vx_new_string("infinity")),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test neginfinity (int<-string \"neginfinity\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::c_neginfinity(),
              vx_core::f_int_from_string(vx_core::vx_new_string("neginfinity")),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_is_empty_1(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("is-empty_1"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (is-empty \"\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_is_empty(vx_core::vx_new_string("")),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (is-empty (list)))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_is_empty_1(
                vx_core::f_empty(
                  vx_core::t_list()
                )
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (is-empty (map)))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_is_empty_1(
                vx_core::f_empty(
                  vx_core::t_map()
                )
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_is_number(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("is-number"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true  (is-number 5))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_is_number(vx_core::vx_new_int(5)),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true  (is-number 5.5))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_is_number(vx_core::vx_new_decimal_from_string("5.5")),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-false (is-number \"a\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_false(
              vx_core::f_is_number(vx_core::vx_new_string("a")),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_last_from_list(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("last<-list"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"c\" (last<-list (list \"b\" \"c\")))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("c"),
              vx_core::f_last_from_list(
                vx_core::t_any(),
                vx_core::f_new(
                  vx_core::t_list(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string("b"),
                    vx_core::vx_new_string("c")
                  })
                )
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_length_from_list(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("length<-list"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 3 (length<-list (stringlist \"a\" \"b\" \"c\")))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(3),
              vx_core::f_length_from_list(
                vx_core::f_new(
                  vx_core::t_stringlist(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string("a"),
                    vx_core::vx_new_string("b"),
                    vx_core::vx_new_string("c")
                  })
                )
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_let(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("let"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n 7\n (let\n  [v1 : int := 2\n   v2 : int := (+ v1 3)]\n  (+ v1 v2)))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(7),
              vx_core::f_let(
                vx_core::t_int(),
                vx_core::t_any_from_func()->vx_fn_new([]() {
                  vx_core::Type_int v1 = vx_core::vx_new_int(2);
                  vx_core::Type_int v2 = vx_core::f_plus(v1, vx_core::vx_new_int(3));
                  vx_core::Type_int output = vx_core::f_plus(v1, v2);vx_core::vx_release({v1, v2});
                  return output;
                })
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_list_from_map(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("list<-map"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (stringlist \"a1\" \"b2\")\n (list<-map : stringlist\n  (stringmap \"a\" \"1\" \"b\" \"2\")\n  (fn : string\n   [key : string\n    val : string]\n   (string key val))))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::f_new(
                vx_core::t_stringlist(),
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_string("a1"),
                  vx_core::vx_new_string("b2")
                })
              ),
              vx_core::f_list_from_map(
                vx_core::t_stringlist(),
                vx_core::f_new(
                  vx_core::t_stringmap(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string("a"),
                    vx_core::vx_new_string("1"),
                    vx_core::vx_new_string("b"),
                    vx_core::vx_new_string("2")
                  })
                ),
                vx_core::t_any_from_key_value()->vx_fn_new([](vx_core::Type_any key_any, vx_core::Type_any val_any) {
                  vx_core::Type_string key = vx_core::vx_any_from_any(vx_core::t_string(), key_any);
                  vx_core::Type_string val = vx_core::vx_any_from_any(vx_core::t_string(), val_any);
                  return 
                    vx_core::f_new(
                      vx_core::t_string(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        key,
                        val
                      })
                    );
                })
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_map_from_list(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("map<-list"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (stringlist \"a1\" \"b2\")\n (list<-map : stringlist\n  (stringmap \"a\" \"1\" \"b\" \"2\")\n  (fn : string\n   [key : string\n    val : string]\n   (string key val))))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::f_new(
                vx_core::t_stringlist(),
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_string("a1"),
                  vx_core::vx_new_string("b2")
                })
              ),
              vx_core::f_list_from_map(
                vx_core::t_stringlist(),
                vx_core::f_new(
                  vx_core::t_stringmap(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string("a"),
                    vx_core::vx_new_string("1"),
                    vx_core::vx_new_string("b"),
                    vx_core::vx_new_string("2")
                  })
                ),
                vx_core::t_any_from_key_value()->vx_fn_new([](vx_core::Type_any key_any, vx_core::Type_any val_any) {
                  vx_core::Type_string key = vx_core::vx_any_from_any(vx_core::t_string(), key_any);
                  vx_core::Type_string val = vx_core::vx_any_from_any(vx_core::t_string(), val_any);
                  return 
                    vx_core::f_new(
                      vx_core::t_string(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        key,
                        val
                      })
                    );
                })
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_new(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("new"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test true (new boolean true))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_boolean(true),
              vx_core::f_new(
                vx_core::t_boolean(),
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_boolean(true)
                })
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 4 (new int 4))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(4),
              vx_core::f_new(
                vx_core::t_int(),
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_int(4)
                })
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 5.4 (new float 5.4))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_decimal_from_string("5.4"),
              vx_core::f_new(
                vx_core::t_float(),
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_decimal_from_string("5.4")
                })
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"a\" (new string \"a\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("a"),
              vx_core::f_new(
                vx_core::t_string(),
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_string("a")
                })
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (stringlist \"a\" \"b\" \"c\")\n (new stringlist \"a\" \"b\" \"c\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::f_new(
                vx_core::t_stringlist(),
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_string("a"),
                  vx_core::vx_new_string("b"),
                  vx_core::vx_new_string("c")
                })
              ),
              vx_core::f_new(
                vx_core::t_stringlist(),
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_string("a"),
                  vx_core::vx_new_string("b"),
                  vx_core::vx_new_string("c")
                })
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (stringmap :a \"1\" :b \"2\")\n (new stringmap :a \"1\" :b \"2\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::f_new(
                vx_core::t_stringmap(),
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_string(":a"),
                  vx_core::vx_new_string("1"),
                  vx_core::vx_new_string(":b"),
                  vx_core::vx_new_string("2")
                })
              ),
              vx_core::f_new(
                vx_core::t_stringmap(),
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_string(":a"),
                  vx_core::vx_new_string("1"),
                  vx_core::vx_new_string(":b"),
                  vx_core::vx_new_string("2")
                })
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_or(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("or"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (or true true))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_or(
                vx_core::vx_new_boolean(true),
                vx_core::vx_new_boolean(true)
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (or true false))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_or(
                vx_core::vx_new_boolean(true),
                vx_core::vx_new_boolean(false)
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-false (or false false))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_false(
              vx_core::f_or(
                vx_core::vx_new_boolean(false),
                vx_core::vx_new_boolean(false)
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_or_1(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("or_1"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true (or false true false))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_or_1(
                vx_core::vx_new(vx_core::t_booleanlist(), {
                  vx_core::vx_new_boolean(false),
                  vx_core::vx_new_boolean(true),
                  vx_core::vx_new_boolean(false)
                })
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-false (or false false false))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_false(
              vx_core::f_or_1(
                vx_core::vx_new(vx_core::t_booleanlist(), {
                  vx_core::vx_new_boolean(false),
                  vx_core::vx_new_boolean(false),
                  vx_core::vx_new_boolean(false)
                })
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_resolve(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("resolve"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"a\" (resolve \"a\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("a"),
              vx_core::f_resolve(vx_core::t_string(), vx_core::vx_new_string("a")),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_resolve_1(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("resolve_1"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 4 (resolve (fn : int [] (+ 1 3))))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(4),
              vx_core::f_resolve_1(
                vx_core::t_int(),
                vx_core::t_any_from_func()->vx_fn_new([]() {
                  return 
                    vx_core::f_plus(vx_core::vx_new_int(1), vx_core::vx_new_int(3));
                })
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_resolve_async(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("resolve-async"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 4 (resolve : int (fn : int [] (+ 1 3))))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(4),
              vx_core::f_resolve_1(
                vx_core::t_int(),
                vx_core::t_any_from_func()->vx_fn_new([]() {
                  return 
                    vx_core::f_plus(vx_core::vx_new_int(1), vx_core::vx_new_int(3));
                })
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_string_repeat(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("string-repeat"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"abab\" (string-repeat \"ab\" 2))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("abab"),
              vx_core::f_string_repeat(vx_core::vx_new_string("ab"), vx_core::vx_new_int(2)),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_string_from_any(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("string<-any"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"true\"  (string<-any true))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("true"),
              vx_core::f_string_from_any(
                vx_core::vx_new_boolean(true)
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"4\"     (string<-any 4))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("4"),
              vx_core::f_string_from_any(vx_core::vx_new_int(4)),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"5.4\"   (string<-any 5.4))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("5.4"),
              vx_core::f_string_from_any(vx_core::vx_new_decimal_from_string("5.4")),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"\\\"a\\\"\" (string<-any \"a\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("\"a\""),
              vx_core::f_string_from_any(vx_core::vx_new_string("a")),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"(stringlist\n   \\\"a\\\"\n   \\\"b\\\"\n   \\\"c\\\")\"\n (string<-any (stringlist \"a\" \"b\" \"c\")))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("(stringlist\n \"a\"\n \"b\"\n \"c\")"),
              vx_core::f_string_from_any(
                vx_core::f_new(
                  vx_core::t_stringlist(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string("a"),
                    vx_core::vx_new_string("b"),
                    vx_core::vx_new_string("c")
                  })
                )
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"(stringmap\n   :a \\\"1\\\"\n   :b \\\"2\\\")\"\n (string<-any (stringmap :a \"1\" :b \"2\")))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("(stringmap\n :a \"1\"\n :b \"2\")"),
              vx_core::f_string_from_any(
                vx_core::f_new(
                  vx_core::t_stringmap(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":a"),
                    vx_core::vx_new_string("1"),
                    vx_core::vx_new_string(":b"),
                    vx_core::vx_new_string("2")
                  })
                )
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_switch(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("switch"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test 1\n (switch : int\n  \"d\"\n  (case (list \"b\" \"c\" \"d\") 1)\n  (else 2)))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_int(1),
              vx_core::f_switch(
                vx_core::t_int(),
                vx_core::vx_new_string("d"),
                vx_core::vx_new(vx_core::t_thenelselist(), {
                  vx_core::f_case(
                    vx_core::f_new(
                      vx_core::t_list(),
                      vx_core::vx_new(vx_core::t_anylist(), {
                        vx_core::vx_new_string("b"),
                        vx_core::vx_new_string("c"),
                        vx_core::vx_new_string("d")
                      })
                    ),
                    vx_core::t_any_from_func()->vx_fn_new([]() {
                      return vx_core::vx_new_int(1);
                    })
                  ),
                  vx_core::f_else(
                    vx_core::t_any_from_func()->vx_fn_new([]() {
                      return vx_core::vx_new_int(2);
                    })
                  )
                })
              ),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_type_from_any(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("type<-any"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test boolean (type<-any false))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::t_boolean(),
              vx_core::f_type_from_any(
                vx_core::vx_new_boolean(false)
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test int (type<-any 5))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::t_int(),
              vx_core::f_type_from_any(vx_core::vx_new_int(5)),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test string (type<-any \"a\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::t_string(),
              vx_core::f_type_from_any(vx_core::vx_new_string("a")),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcase f_typename_from_any(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("typename<-any"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"vx/core/boolean\" (typename<-any false))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("vx/core/boolean"),
              vx_core::f_typename_from_any(
                vx_core::vx_new_boolean(false)
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"vx/core/int\"     (typename<-any 5))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("vx/core/int"),
              vx_core::f_typename_from_any(vx_core::vx_new_int(5)),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test \"vx/core/string\"  (typename<-any \"a\"))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("vx/core/string"),
              vx_core::f_typename_from_any(vx_core::vx_new_string("a")),
              context
            )
          })
        }
      ))
    });
    return output;
  }

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {
    vx_core::vx_Type_listany listtestcase;
    listtestcase.push_back(vx_core_test::t_boolean(context));
    listtestcase.push_back(vx_core_test::t_float(context));
    listtestcase.push_back(vx_core_test::t_int(context));
    listtestcase.push_back(vx_core_test::t_string(context));
    listtestcase.push_back(vx_core_test::c_false(context));
    listtestcase.push_back(vx_core_test::c_true(context));
    listtestcase.push_back(vx_core_test::f_not(context));
    listtestcase.push_back(vx_core_test::f_ne(context));
    listtestcase.push_back(vx_core_test::f_multiply(context));
    listtestcase.push_back(vx_core_test::f_multiply_1(context));
    listtestcase.push_back(vx_core_test::f_multiply_2(context));
    listtestcase.push_back(vx_core_test::f_multiply_3(context));
    listtestcase.push_back(vx_core_test::f_plus(context));
    listtestcase.push_back(vx_core_test::f_plus_1(context));
    listtestcase.push_back(vx_core_test::f_plus1(context));
    listtestcase.push_back(vx_core_test::f_minus(context));
    listtestcase.push_back(vx_core_test::f_minus_1(context));
    listtestcase.push_back(vx_core_test::f_divide(context));
    listtestcase.push_back(vx_core_test::f_lt(context));
    listtestcase.push_back(vx_core_test::f_lt_1(context));
    listtestcase.push_back(vx_core_test::f_chainfirst(context));
    listtestcase.push_back(vx_core_test::f_chainlast(context));
    listtestcase.push_back(vx_core_test::f_le(context));
    listtestcase.push_back(vx_core_test::f_le_1(context));
    listtestcase.push_back(vx_core_test::f_eq(context));
    listtestcase.push_back(vx_core_test::f_eq_1(context));
    listtestcase.push_back(vx_core_test::f_gt(context));
    listtestcase.push_back(vx_core_test::f_gt_1(context));
    listtestcase.push_back(vx_core_test::f_ge(context));
    listtestcase.push_back(vx_core_test::f_ge_1(context));
    listtestcase.push_back(vx_core_test::f_and(context));
    listtestcase.push_back(vx_core_test::f_and_1(context));
    listtestcase.push_back(vx_core_test::f_any_from_list(context));
    listtestcase.push_back(vx_core_test::f_any_from_list_reduce(context));
    listtestcase.push_back(vx_core_test::f_any_from_map(context));
    listtestcase.push_back(vx_core_test::f_compare(context));
    listtestcase.push_back(vx_core_test::f_contains(context));
    listtestcase.push_back(vx_core_test::f_contains_1(context));
    listtestcase.push_back(vx_core_test::f_empty(context));
    listtestcase.push_back(vx_core_test::f_first_from_list(context));
    listtestcase.push_back(vx_core_test::f_first_from_list_fn_any_from_any(context));
    listtestcase.push_back(vx_core_test::f_if(context));
    listtestcase.push_back(vx_core_test::f_if_1(context));
    listtestcase.push_back(vx_core_test::f_if_2(context));
    listtestcase.push_back(vx_core_test::f_int_from_string(context));
    listtestcase.push_back(vx_core_test::f_is_empty_1(context));
    listtestcase.push_back(vx_core_test::f_is_number(context));
    listtestcase.push_back(vx_core_test::f_last_from_list(context));
    listtestcase.push_back(vx_core_test::f_length_from_list(context));
    listtestcase.push_back(vx_core_test::f_let(context));
    listtestcase.push_back(vx_core_test::f_list_from_map(context));
    listtestcase.push_back(vx_core_test::f_map_from_list(context));
    listtestcase.push_back(vx_core_test::f_new(context));
    listtestcase.push_back(vx_core_test::f_or(context));
    listtestcase.push_back(vx_core_test::f_or_1(context));
    listtestcase.push_back(vx_core_test::f_resolve(context));
    listtestcase.push_back(vx_core_test::f_resolve_1(context));
    listtestcase.push_back(vx_core_test::f_resolve_async(context));
    listtestcase.push_back(vx_core_test::f_string_repeat(context));
    listtestcase.push_back(vx_core_test::f_string_from_any(context));
    listtestcase.push_back(vx_core_test::f_switch(context));
    listtestcase.push_back(vx_core_test::f_type_from_any(context));
    listtestcase.push_back(vx_core_test::f_typename_from_any(context));
    vx_test::Type_testcaselist output = vx_core::vx_any_from_any(
      vx_test::t_testcaselist(),
      vx_test::t_testcaselist()->vx_new_from_list(listtestcase)
    );
    return output;
  }

  vx_test::Type_testcoveragesummary test_coveragesummary() {
    return vx_core::vx_new(vx_test::t_testcoveragesummary(), {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":constnums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(14), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(2), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(14)
      }),
      vx_core::vx_new_string(":docnums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(81), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(180), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(222)
      }),
      vx_core::vx_new_string(":funcnums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(47), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(57), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(119)
      }),
      vx_core::vx_new_string(":ospacenums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(142)
      }),
      vx_core::vx_new_string(":otimenums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(142)
      }),
      vx_core::vx_new_string(":totalnums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(31), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(63), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(199)
      }),
      vx_core::vx_new_string(":typenums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(6), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(4), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(66)
      })
    });
  }

  vx_test::Type_testcoveragedetail test_coveragedetail() {
    return vx_core::vx_new(vx_test::t_testcoveragedetail(), {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"),
      vx_core::vx_new_string(":typemap"), vx_core::vx_new(vx_core::t_intmap(), {
        vx_core::vx_new_string(":any"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":any-async<-func"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":any<-anylist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":anylist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":anytype"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":arg"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":arglist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":argmap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":boolean"), vx_core::vx_new_int(4),
        vx_core::vx_new_string(":booleanlist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":collection"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":compilelanguages"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":connect"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":connectlist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":connectmap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":const"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":constdef"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":constlist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":constmap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":context"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":decimal"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":error"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":float"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":func"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":funcdef"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":funclist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":funcmap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":int"), vx_core::vx_new_int(7),
        vx_core::vx_new_string(":intlist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":intmap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":list"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":listtype"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":map"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":maptype"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":mempool"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":msg"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":msgblock"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":msgblocklist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":msglist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":none"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":notype"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":number"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":numberlist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":numbermap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":package"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":packagemap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":permission"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":permissionlist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":permissionmap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":security"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":session"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":setting"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":state"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":statelistener"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":stringlist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":stringmap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":struct"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":thenelse"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":thenelselist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":type"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":typedef"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":typelist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":typemap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":user"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":value"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":constmap"), vx_core::vx_new(vx_core::t_intmap(), {
        vx_core::vx_new_string(":false"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":globalpackagemap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":infinity"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":mempool-active"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":msg-error"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":msg-info"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":msg-severe"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":msg-warning"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":neginfinity"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":newline"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":notanumber"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":nothing"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":quote"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":true"), vx_core::vx_new_int(1)
      }),
      vx_core::vx_new_string(":funcmap"), vx_core::vx_new(vx_core::t_intmap(), {
        vx_core::vx_new_string(":!"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":!-empty"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":!-empty_1"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":!="), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":*"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":*_1"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":*_2"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":*_3"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":+"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":+_1"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":+_2"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":+_3"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":+1"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":-"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":-_1"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":-_2"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":-_3"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":."), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":/"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":<"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":<_1"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":<-"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":<<-"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":<="), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":<=_1"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":="), vx_core::vx_new_int(5),
        vx_core::vx_new_string(":=_1"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":>"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":>_1"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":>="), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":>=_1"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":allowtypenames<-typedef"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":allowtypes<-typedef"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":and"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":and_1"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":any<-any"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":any<-any-async"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":any<-any-context"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":any<-any-context-async"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":any<-func"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":any<-func-async"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":any<-key-value"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":any<-key-value-async"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":any<-list"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":any<-list-reduce"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":any<-list-reduce-next"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":any<-map"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":any<-none"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":any<-none-async"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":any<-reduce"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":any<-reduce-async"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":any<-reduce-next"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":any<-reduce-next-async"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":any<-struct"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":async"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":boolean<-any"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":boolean<-func"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":boolean<-none"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":case"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":case_1"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":compare"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":contains"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":contains_1"), vx_core::vx_new_int(3),
        vx_core::vx_new_string(":copy"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":else"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":empty"), vx_core::vx_new_int(3),
        vx_core::vx_new_string(":extends<-any"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":extends<-typedef"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":first<-list"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":first<-list-fn-any<-any"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":fn"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":funcdef<-func"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":funcname<-funcdef"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":global-package-get"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":global-package-set"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":if"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":if_1"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":if_2"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":int<-func"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":int<-string"), vx_core::vx_new_int(6),
        vx_core::vx_new_string(":is-empty"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":is-empty_1"), vx_core::vx_new_int(3),
        vx_core::vx_new_string(":is-endswith"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":is-func"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":is-int"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":is-number"), vx_core::vx_new_int(3),
        vx_core::vx_new_string(":is-pass<-permission"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":last<-list"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":length<-list"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":let"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":let-async"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":list-join<-list"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":list<-list"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":list<-list-async"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":list<-map"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":list<-map-async"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":list<-type"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":log"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":map<-list"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":mempool-addref"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":mempool-release"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":mempool-removeref"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":mempool-removerefchildren"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":mempool-reserve"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":msg<-error"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":msgblock<-msgblock-msg"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":msgblock<-msgblock-msgblock"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":name<-typedef"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":native"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":native<-any"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":new"), vx_core::vx_new_int(6),
        vx_core::vx_new_string(":number<-func"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":or"), vx_core::vx_new_int(3),
        vx_core::vx_new_string(":or_1"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":packagename<-typedef"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":path<-context-path"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":path<-setting-path"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":permission<-id-context"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":properties<-typedef"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":proplast<-typedef"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":resolve"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":resolve_1"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":resolve-async"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":resolve-first"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":resolve-list"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":session<-context"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":setting<-context"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string-repeat"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":string<-any"), vx_core::vx_new_int(6),
        vx_core::vx_new_string(":string<-any-indent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string<-func"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":switch"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":then"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":traits<-typedef"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":type<-any"), vx_core::vx_new_int(3),
        vx_core::vx_new_string(":typedef<-any"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":typedef<-type"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":typename<-any"), vx_core::vx_new_int(3),
        vx_core::vx_new_string(":typename<-type"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":typename<-typedef"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":typenames<-typelist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":user<-context"), vx_core::vx_new_int(0)
      })
    });
  }

  vx_test::Type_testpackage test_package(vx_core::Type_context context) {
    vx_test::Type_testcaselist testcaselist = test_cases(context);
    vx_test::Type_testpackage output = vx_core::vx_new(vx_test::t_testpackage(), {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/core"), 
      vx_core::vx_new_string(":caselist"), testcaselist,
      vx_core::vx_new_string(":coveragesummary"), test_coveragesummary(),
      vx_core::vx_new_string(":coveragedetail"), test_coveragedetail()
    });
    return output;
  }

}
