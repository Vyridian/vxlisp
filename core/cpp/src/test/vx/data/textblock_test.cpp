#include "../../../main/vx/data/textblock.hpp"
#include "../../../main/vx/core.hpp"
#include "../../../main/vx/test.hpp"

namespace vx_data_textblock_test {

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {
    vx_core::vx_Type_listany arraylisttestcase;
    vx_test::Type_testcaselist output = vx_test::t_testcaselist->vx_new_from_list(vx_test::t_testcaselist, arraylisttestcase);
    return output;
  }

  vx_test::Type_testcoveragesummary test_coveragesummary() {
    return vx_test::t_testcoveragesummary->vx_new(vx_test::t_testcoveragesummary, {
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/data/textblock"),
      vx_core::t_string->vx_new_from_string(":constnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(100), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(0)
      }),
      vx_core::t_string->vx_new_from_string(":docnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(42), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(3), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(7)
      }),
      vx_core::t_string->vx_new_from_string(":funcnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(4)
      }),
      vx_core::t_string->vx_new_from_string(":ospacenums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(4)
      }),
      vx_core::t_string->vx_new_from_string(":otimenums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(4)
      }),
      vx_core::t_string->vx_new_from_string(":totalnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(7)
      }),
      vx_core::t_string->vx_new_from_string(":typenums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(3)
      })
    });
  }

  vx_test::Type_testcoveragedetail test_coveragedetail() {
    return vx_test::t_testcoveragedetail->vx_new(vx_test::t_testcoveragedetail, {
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/data/textblock"),
      vx_core::t_string->vx_new_from_string(":typemap"), vx_core::t_intmap->vx_new(vx_core::t_intmap, {
              vx_core::t_string->vx_new_from_string(":delimset"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":textblock"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":textblocklist"), vx_core::t_int->vx_new_from_int(0)
      }),
      vx_core::t_string->vx_new_from_string(":constmap"), vx_core::t_intmap->vx_new(vx_core::t_intmap, {
        
      }),
      vx_core::t_string->vx_new_from_string(":funcmap"), vx_core::t_intmap->vx_new(vx_core::t_intmap, {
              vx_core::t_string->vx_new_from_string(":parse"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":stringlist<-textblocklist"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":text<-textblock"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":textblocks<-textblock"), vx_core::t_int->vx_new_from_int(0)
      })
    });
  }

  vx_test::Type_testpackage test_package(vx_core::Type_context context) {
    vx_test::Type_testcaselist testcaselist = test_cases(context);
    vx_test::Type_testpackage output = vx_test::t_testpackage->vx_new(vx_test::t_testpackage, {
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/data/textblock"), 
      vx_core::t_string->vx_new_from_string(":caselist"), testcaselist,
      vx_core::t_string->vx_new_from_string(":coveragesummary"), test_coveragesummary(),
      vx_core::t_string->vx_new_from_string(":coveragedetail"), test_coveragedetail()
    });
    return output;
  }

}
