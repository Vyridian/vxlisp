#include "../../main/vx/state.hpp"
#include "../../main/vx/core.hpp"
#include "../../main/vx/test.hpp"

namespace vx_state_test {

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {
    vx_core::vx_Type_listany listtestcase;
    vx_test::Type_testcaselist output = vx_core::vx_any_from_any(
      vx_test::t_testcaselist(),
      vx_test::t_testcaselist()->vx_new_from_list(listtestcase)
    );
    return output;
  }

  vx_test::Type_testcoveragesummary test_coveragesummary() {
    return vx_core::vx_new(vx_test::t_testcoveragesummary(), {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/state"),
      vx_core::vx_new_string(":constnums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(100), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":docnums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(33), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(1), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(3)
      }),
      vx_core::vx_new_string(":funcnums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(2)
      }),
      vx_core::vx_new_string(":ospacenums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(2)
      }),
      vx_core::vx_new_string(":otimenums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(2)
      }),
      vx_core::vx_new_string(":totalnums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(3)
      }),
      vx_core::vx_new_string(":typenums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(1)
      })
    });
  }

  vx_test::Type_testcoveragedetail test_coveragedetail() {
    return vx_core::vx_new(vx_test::t_testcoveragedetail(), {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/state"),
      vx_core::vx_new_string(":typemap"), vx_core::vx_new(vx_core::t_intmap(), {
        vx_core::vx_new_string(":value-map"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":constmap"), vx_core::vx_new(vx_core::t_intmap(), {
        
      }),
      vx_core::vx_new_string(":funcmap"), vx_core::vx_new(vx_core::t_intmap(), {
        vx_core::vx_new_string(":change"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":register"), vx_core::vx_new_int(0)
      })
    });
  }

  vx_test::Type_testpackage test_package(vx_core::Type_context context) {
    vx_test::Type_testcaselist testcaselist = test_cases(context);
    vx_test::Type_testpackage output = vx_core::vx_new(vx_test::t_testpackage(), {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/state"), 
      vx_core::vx_new_string(":caselist"), testcaselist,
      vx_core::vx_new_string(":coveragesummary"), test_coveragesummary(),
      vx_core::vx_new_string(":coveragedetail"), test_coveragedetail()
    });
    return output;
  }

}
