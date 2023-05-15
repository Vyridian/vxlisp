#include "../../main/vx/sample.hpp"
#include "../../main/vx/core.hpp"
#include "../../main/vx/test.hpp"

namespace vx_sample_test {

  vx_test::Type_testcase c_myconst(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/sample"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("myconst"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(vx_test::t_testdescribelist, 
        vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
          vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test 4 myconst)"),
          vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
              vx_core::t_int->vx_new_from_int(4),
              vx_sample::c_myconst,
              context
            )
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_myfunc(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/sample"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("myfunc"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(vx_test::t_testdescribelist, 
        vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
          vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test 5 (myfunc 1))"),
          vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
              vx_core::t_int->vx_new_from_int(5),
              vx_sample::f_myfunc(vx_core::t_int->vx_new_from_int(1)),
              context
            )
        })
      )
    });
    return output;
  }

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {
    vx_core::vx_Type_listany arraylisttestcase;
    arraylisttestcase->push_back(vx_sample_test::c_myconst(context));
    arraylisttestcase->push_back(vx_sample_test::f_myfunc(context));
    vx_test::Type_testcaselist output = vx_test::t_testcaselist->vx_new_from_list(vx_test::t_testcaselist, arraylisttestcase);
    return output;
  }

  vx_test::Type_testcoveragesummary test_coveragesummary() {
    return vx_test::t_testcoveragesummary->vx_new(vx_test::t_testcoveragesummary, {
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/sample"),
      vx_core::t_string->vx_new_from_string(":constnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(100), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(1), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(1)
      }),
      vx_core::t_string->vx_new_from_string(":docnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(50), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(2), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(4)
      }),
      vx_core::t_string->vx_new_from_string(":funcnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(50), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(1), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(2)
      }),
      vx_core::t_string->vx_new_from_string(":ospacenums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(2)
      }),
      vx_core::t_string->vx_new_from_string(":otimenums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(2)
      }),
      vx_core::t_string->vx_new_from_string(":totalnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(50), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(2), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(4)
      }),
      vx_core::t_string->vx_new_from_string(":typenums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(1)
      })
    });
  }

  vx_test::Type_testcoveragedetail test_coveragedetail() {
    return vx_test::t_testcoveragedetail->vx_new(vx_test::t_testcoveragedetail, {
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/sample"),
      vx_core::t_string->vx_new_from_string(":typemap"), vx_core::t_intmap->vx_new(vx_core::t_intmap, {
              vx_core::t_string->vx_new_from_string(":mytype"), vx_core::t_int->vx_new_from_int(0)
      }),
      vx_core::t_string->vx_new_from_string(":constmap"), vx_core::t_intmap->vx_new(vx_core::t_intmap, {
              vx_core::t_string->vx_new_from_string(":myconst"), vx_core::t_int->vx_new_from_int(1)
      }),
      vx_core::t_string->vx_new_from_string(":funcmap"), vx_core::t_intmap->vx_new(vx_core::t_intmap, {
              vx_core::t_string->vx_new_from_string(":main"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":myfunc"), vx_core::t_int->vx_new_from_int(1)
      })
    });
  }

  vx_test::Type_testpackage test_package(vx_core::Type_context context) {
    vx_test::Type_testcaselist testcaselist = test_cases(context);
    vx_test::Type_testpackage output = vx_test::t_testpackage->vx_new(vx_test::t_testpackage, {
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/sample"), 
      vx_core::t_string->vx_new_from_string(":caselist"), testcaselist,
      vx_core::t_string->vx_new_from_string(":coveragesummary"), test_coveragesummary(),
      vx_core::t_string->vx_new_from_string(":coveragedetail"), test_coveragedetail()
    });
    return output;
  }

}
