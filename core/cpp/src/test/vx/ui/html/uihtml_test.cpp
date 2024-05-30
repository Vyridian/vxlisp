#include "../../../../main/vx/ui/html/uihtml.hpp"
#include "../../../../main/vx/core.hpp"
#include "../../../../main/vx/test.hpp"
#include "../../../../main/vx/data/file.hpp"
#include "../../../../main/vx/web/html.hpp"
#include "../../../../main/vx/web/htmldoc.hpp"
#include "../../../../main/vx/type.hpp"
#include "../../../../main/vx/ui/ui.hpp"
#include "uihtml_test.hpp"

namespace vx_ui_html_uihtml_test {


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
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/ui/html/uihtml"),
      vx_core::vx_new_string(":constnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(7)
      }),
      vx_core::vx_new_string(":docnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(60), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(23), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(38)
      }),
      vx_core::vx_new_string(":funcnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(30)
      }),
      vx_core::vx_new_string(":bigospacenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(31)
      }),
      vx_core::vx_new_string(":bigotimenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(31)
      }),
      vx_core::vx_new_string(":totalnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(37)
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
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/ui/html/uihtml"),
      vx_core::vx_new_string(":typemap"), vx_core::vx_new(vx_core::t_intmap, {
        
      }),
      vx_core::vx_new_string(":constmap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":layout-app-html"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-else-html"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-image-html"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layout-label-html"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":layoutenginehtml"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":style-hidden"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":style-selected"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":funcmap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":boolean-print-html"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":boolean-writeeventsall<-ui"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":boolean-writeeventsall<-uimap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":context-write"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":divchild<-ui"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":divchildlist<-uimap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":divchildlist<-uimap_1"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":divchildlist<-uimap-origmap-parent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":node-app<-ui-orig-parent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":node-default<-ui-orig-parent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":node-image<-ui-orig-parent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":node-label<-ui-orig-parent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":node-layout<-node-ui"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":node<-ui-orig-parent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string-style<-font"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string-style<-image"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string-stylename<-name-styletype"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":style<-fontface"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":style<-style"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":stylelist-extra<-ui"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":stylelist-reset"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":stylelist<-fontfacemap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":stylelist<-stylelist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":stylelist<-stylemap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":stylemap<-stylemap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":stylesheet-layout-html"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":stylesheet<-stylesheet"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":ui-layout-app<-ui-orig-parent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":ui-layout-default<-ui-orig-parent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":ui-layout-image<-ui-orig-parent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":ui-layout-label<-ui-orig-parent"), vx_core::vx_new_int(0)
      })
    });
    return output;
  }

  vx_test::Type_testpackage test_package(vx_core::Type_context context) {
    vx_test::Type_testcaselist testcaselist = vx_ui_html_uihtml_test::test_cases(context);
    vx_test::Type_testcoveragesummary testcoveragesummary = vx_ui_html_uihtml_test::test_coveragesummary();
    vx_test::Type_testcoveragedetail testcoveragedetail = vx_ui_html_uihtml_test::test_coveragedetail();
    vx_test::Type_testpackage output = vx_core::vx_new(vx_test::t_testpackage, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/ui/html/uihtml"),
      vx_core::vx_new_string(":caselist"), testcaselist,
      vx_core::vx_new_string(":coveragesummary"), testcoveragesummary,
      vx_core::vx_new_string(":coveragedetail"), testcoveragedetail
    });
    return output;
  }

}
