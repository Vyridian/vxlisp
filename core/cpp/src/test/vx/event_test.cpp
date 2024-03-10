#include "../../main/vx/event.hpp"
#include "../../main/vx/core.hpp"
#include "../../main/vx/test.hpp"
#include "event_test.hpp"

namespace vx_event_test {


  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {
    vx_core::vx_Type_listany listtestcase;
    vx_test::Type_testcaselist output = vx_core::vx_any_from_any(
      vx_test::t_testcaselist,
      vx_test::t_testcaselist->vx_new_from_list(listtestcase)
    );
    return output;
  }

  vx_test::Type_testcoveragesummary test_coveragesummary() {
    vx_test::Type_testcoveragesummary output = vx_core::vx_new(vx_test::t_testcoveragesummary, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/event"),
      vx_core::vx_new_string(":constnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(4)
      }),
      vx_core::vx_new_string(":docnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(90), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(10), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(11)
      }),
      vx_core::vx_new_string(":funcnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(4)
      }),
      vx_core::vx_new_string(":bigospacenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(4)
      }),
      vx_core::vx_new_string(":bigotimenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(4)
      }),
      vx_core::vx_new_string(":totalnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(11)
      }),
      vx_core::vx_new_string(":typenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(3)
      })
    });
    return output;
  }

  vx_test::Type_testcoveragedetail test_coveragedetail() {
    vx_test::Type_testcoveragedetail output = vx_core::vx_new(vx_test::t_testcoveragedetail, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/event"),
      vx_core::vx_new_string(":typemap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":event"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":eventlist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":eventmap"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":constmap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":event-change"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":event-click"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":event-move"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":event-select"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":funcmap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":any-from<-event"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":event<-event"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":event<-event-async"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":eventmap<-eventlist"), vx_core::vx_new_int(0)
      })
    });
    return output;
  }

  vx_test::Type_testpackage test_package(vx_core::Type_context context) {
    vx_test::Type_testcaselist testcaselist = vx_event_test::test_cases(context);
    vx_test::Type_testcoveragesummary testcoveragesummary = vx_event_test::test_coveragesummary();
    vx_test::Type_testcoveragedetail testcoveragedetail = vx_event_test::test_coveragedetail();
    vx_test::Type_testpackage output = vx_core::vx_new(vx_test::t_testpackage, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/event"),
      vx_core::vx_new_string(":caselist"), testcaselist,
      vx_core::vx_new_string(":coveragesummary"), testcoveragesummary,
      vx_core::vx_new_string(":coveragedetail"), testcoveragedetail
    });
    return output;
  }

}
