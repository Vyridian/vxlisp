#include <vector>
#include "../../../src/vx/data/xml.hpp"
#include "../../../src/vx/core.hpp"
#include "../../../src/vx/test.hpp"
#include "../../../src/vx/data/textblock.hpp"

namespace vx_data_xml_test {

  vx_test::Type_testcaselist* test_cases(vx_core::Type_context* context) {
    std::vector<vx_core::Type_any*>* arraylisttestcase;
    vx_test::Type_testcaselist* output = vx_test::t_testcaselist->vx_new(arraylisttestcase);
    return output;
  }

  vx_test::Type_testcoveragesummary* test_coveragesummary() {
    return vx_test::t_testcoveragesummary->vx_new(
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/data/xml"),
      vx_core::t_string->vx_new_from_string(":constnums"), vx_test::t_testcoveragenums->vx_new(vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(100), vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(0)),
      vx_core::t_string->vx_new_from_string(":docnums"), vx_test::t_testcoveragenums->vx_new(vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(5)),
      vx_core::t_string->vx_new_from_string(":funcnums"), vx_test::t_testcoveragenums->vx_new(vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(1)),
      vx_core::t_string->vx_new_from_string(":ospacenums"), vx_test::t_testcoveragenums->vx_new(vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(1)),
      vx_core::t_string->vx_new_from_string(":otimenums"), vx_test::t_testcoveragenums->vx_new(vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(1)),
      vx_core::t_string->vx_new_from_string(":totalnums"), vx_test::t_testcoveragenums->vx_new(vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(5)),
      vx_core::t_string->vx_new_from_string(":typenums"), vx_test::t_testcoveragenums->vx_new(vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(4))
    );
  }

  vx_test::Type_testcoveragedetail* test_coveragedetail() {
    return vx_test::t_testcoveragedetail->vx_new(
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/data/xml"),
      vx_core::t_string->vx_new_from_string(":typemap"), vx_core::t_intmap->vx_new(
        vx_core::t_string->vx_new_from_string(":xml"), vx_core::t_int->vx_new_from_int(0),
        vx_core::t_string->vx_new_from_string(":xmlnode"), vx_core::t_int->vx_new_from_int(0),
        vx_core::t_string->vx_new_from_string(":xmlnodelist"), vx_core::t_int->vx_new_from_int(0),
        vx_core::t_string->vx_new_from_string(":xmlpropmap"), vx_core::t_int->vx_new_from_int(0)
      ),
      vx_core::t_string->vx_new_from_string(":constmap"), vx_core::t_intmap->vx_new(
  
      ),
      vx_core::t_string->vx_new_from_string(":funcmap"), vx_core::t_intmap->vx_new(
        vx_core::t_string->vx_new_from_string(":xml<-textblock"), vx_core::t_int->vx_new_from_int(0)
      )
    );
  }

  vx_test::Type_testpackage* test_package(vx_core::Type_context* context) {
    vx_test::Type_testcaselist* testcaselist = test_cases(context);
    vx_test::Type_testpackage* output = vx_test::t_testpackage->vx_new(
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/data/xml"), 
      vx_core::t_string->vx_new_from_string(":caselist"), testcaselist,
      vx_core::t_string->vx_new_from_string(":coveragesummary"), test_coveragesummary(),
      vx_core::t_string->vx_new_from_string(":coveragedetail"), test_coveragedetail()
    );
    return output;
  }

}
