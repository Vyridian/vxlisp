#include "../../main/vx/translate.hpp"
#include "../../main/vx/core.hpp"
#include "../../main/vx/test.hpp"
#include "../../main/vx/data/csv.hpp"
#include "../../main/vx/data/file.hpp"
#include "translate_test.hpp"

namespace vx_translate_test {


  vx_test::Type_testcase f_translate(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_translate");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::vx_new_string("!NotFound!"),
      vx_translate::f_translate(context, vx_core::vx_new_string("!NotFound!"))
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"!NotFound!\"\n (translate \"!NotFound!\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/translate"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/translate"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("translate"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_translate");
    return output;
  }

  vx_test::Type_testcase f_translate_1(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_translate_1");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::vx_new_string("Repl Type Not Found"),
      vx_translate::f_translate_1(
        context,
        vx_core::f_new(
          vx_core::t_msg,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":path"),
            vx_core::vx_new_string("vx/repl/repl/repl<-string-argmap"),
            vx_core::vx_new_string(":code"),
            vx_core::vx_new_string("repltypenotfound")
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"Repl Type Not Found\"\n (translate\n  (msg\n   :path \"vx/repl/repl/repl<-string-argmap\"\n   :code \"repltypenotfound\")))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/translate"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/translate"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("translate_1"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_translate_1");
    return output;
  }

  vx_test::Type_testcase f_translate_from_translation_string(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_translate_from_translation_string");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::vx_new_string("Hola"),
      vx_translate::f_translate_from_translation_string(
        vx_core::f_new(
          vx_core::t_translation,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":wordmap"),
            vx_core::f_new(
              vx_core::t_stringmap,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string("Hello"),
                vx_core::vx_new_string("Hola")
              })
            )
          })
        ),
        vx_core::vx_new_string("Hello")
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"Hola\"\n (translate<-translation-string\n  (translation\n   :wordmap\n    (stringmap\n     \"Hello\" \"Hola\"))\n  \"Hello\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/translate"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/translate"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("translate<-translation-string"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_translate_from_translation_string");
    return output;
  }

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {
    vx_core::vx_Type_listany listtestcase;
    listtestcase.push_back(vx_translate_test::f_translate(context));
    listtestcase.push_back(vx_translate_test::f_translate_1(context));
    listtestcase.push_back(vx_translate_test::f_translate_from_translation_string(context));
    vx_test::Type_testcaselist output = vx_core::vx_any_from_any(
      vx_test::t_testcaselist,
      vx_test::t_testcaselist->vx_new_from_list(listtestcase)
    );
    return output;
  }

  vx_test::Type_testcoveragesummary test_coveragesummary() {
    vx_test::Type_testcoveragesummary output = vx_core::vx_new(vx_test::t_testcoveragesummary, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/translate"),
      vx_core::vx_new_string(":constnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(100), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":docnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(100), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(11), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(11)
      }),
      vx_core::vx_new_string(":funcnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(30), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(3), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(10)
      }),
      vx_core::vx_new_string(":bigospacenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(11)
      }),
      vx_core::vx_new_string(":bigotimenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(11)
      }),
      vx_core::vx_new_string(":totalnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(30), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(3), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(10)
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
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/translate"),
      vx_core::vx_new_string(":typemap"), vx_core::vx_new(vx_core::t_intmap, {
        
      }),
      vx_core::vx_new_string(":constmap"), vx_core::vx_new(vx_core::t_intmap, {
        
      }),
      vx_core::vx_new_string(":funcmap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":session<-session-name"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":session<-session-translation"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":session<-session-translationmap-name"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":translate"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":translate_1"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":translate<-translation-string"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":translate<-translationmap-name-string"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":translation-load-session"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":translation<-context"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":translation<-session-name"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":translationmap<-translations"), vx_core::vx_new_int(0)
      })
    });
    return output;
  }

  vx_test::Type_testpackage test_package(vx_core::Type_context context) {
    vx_test::Type_testcaselist testcaselist = vx_translate_test::test_cases(context);
    vx_test::Type_testcoveragesummary testcoveragesummary = vx_translate_test::test_coveragesummary();
    vx_test::Type_testcoveragedetail testcoveragedetail = vx_translate_test::test_coveragedetail();
    vx_test::Type_testpackage output = vx_core::vx_new(vx_test::t_testpackage, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/translate"),
      vx_core::vx_new_string(":caselist"), testcaselist,
      vx_core::vx_new_string(":coveragesummary"), testcoveragesummary,
      vx_core::vx_new_string(":coveragedetail"), testcoveragedetail
    });
    return output;
  }

}
