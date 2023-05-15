#include "../../main/vx/test.hpp"
#include "../../main/vx/core.hpp"
#include "../../main/vx/data/file.hpp"
#include "../../main/vx/web/html.hpp"

namespace vx_test_test {

  vx_test::Type_testcase f_file_test(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/test"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("file-test"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(vx_test::t_testdescribelist, 
        vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
          vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test-true\n (boolean-exists<-file\n  (file\n   :name \"testsuite.vxlisp\"\n   :path \"src/test/resources\")))"),
          vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test_true(
              vx_data_file::f_boolean_exists_from_file(
                vx_core::f_new(
                  vx_data_file::t_file,
                  vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                    vx_core::t_string->vx_new_from_string(":name"),
                    vx_core::t_string->vx_new_from_string("testsuite.vxlisp"),
                    vx_core::t_string->vx_new_from_string(":path"),
                    vx_core::t_string->vx_new_from_string("src/test/resources")
                  })
                )
              ),
              context
            )
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_file_testhtml(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/test"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("file-testhtml"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(vx_test::t_testdescribelist, 
        vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
          vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test-true\n (boolean-exists<-file\n  (file\n   :name \"testsuite.html\"\n   :path \"src/test/resources\")))"),
          vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test_true(
              vx_data_file::f_boolean_exists_from_file(
                vx_core::f_new(
                  vx_data_file::t_file,
                  vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                    vx_core::t_string->vx_new_from_string(":name"),
                    vx_core::t_string->vx_new_from_string("testsuite.html"),
                    vx_core::t_string->vx_new_from_string(":path"),
                    vx_core::t_string->vx_new_from_string("src/test/resources")
                  })
                )
              ),
              context
            )
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_file_testnode(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/test"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("file-testnode"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(vx_test::t_testdescribelist, 
        vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
          vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test-true\n (boolean-exists<-file\n  (file\n   :name \"testsuitenode.vxlisp\"\n   :path \"src/test/resources\")))"),
          vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test_true(
              vx_data_file::f_boolean_exists_from_file(
                vx_core::f_new(
                  vx_data_file::t_file,
                  vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                    vx_core::t_string->vx_new_from_string(":name"),
                    vx_core::t_string->vx_new_from_string("testsuitenode.vxlisp"),
                    vx_core::t_string->vx_new_from_string(":path"),
                    vx_core::t_string->vx_new_from_string("src/test/resources")
                  })
                )
              ),
              context
            )
        })
      )
    });
    return output;
  }

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {
    vx_core::vx_Type_listany arraylisttestcase;
    arraylisttestcase->push_back(vx_test_test::f_file_test(context));
    arraylisttestcase->push_back(vx_test_test::f_file_testhtml(context));
    arraylisttestcase->push_back(vx_test_test::f_file_testnode(context));
    vx_test::Type_testcaselist output = vx_test::t_testcaselist->vx_new_from_list(vx_test::t_testcaselist, arraylisttestcase);
    return output;
  }

  vx_test::Type_testcoveragesummary test_coveragesummary() {
    return vx_test::t_testcoveragesummary->vx_new(vx_test::t_testcoveragesummary, {
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/test"),
      vx_core::t_string->vx_new_from_string(":constnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(1)
      }),
      vx_core::t_string->vx_new_from_string(":docnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(93), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(41), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(44)
      }),
      vx_core::t_string->vx_new_from_string(":funcnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(11), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(3), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(26)
      }),
      vx_core::t_string->vx_new_from_string(":ospacenums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(32)
      }),
      vx_core::t_string->vx_new_from_string(":otimenums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(32)
      }),
      vx_core::t_string->vx_new_from_string(":totalnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(7), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(3), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(38)
      }),
      vx_core::t_string->vx_new_from_string(":typenums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(11)
      })
    });
  }

  vx_test::Type_testcoveragedetail test_coveragedetail() {
    return vx_test::t_testcoveragedetail->vx_new(vx_test::t_testcoveragedetail, {
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/test"),
      vx_core::t_string->vx_new_from_string(":typemap"), vx_core::t_intmap->vx_new(vx_core::t_intmap, {
              vx_core::t_string->vx_new_from_string(":testcase"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":testcaselist"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":testcoveragedetail"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":testcoveragenums"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":testcoveragesummary"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":testdescribe"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":testdescribelist"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":testpackage"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":testpackagelist"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":testresult"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":testresultlist"), vx_core::t_int->vx_new_from_int(0)
      }),
      vx_core::t_string->vx_new_from_string(":constmap"), vx_core::t_intmap->vx_new(vx_core::t_intmap, {
              vx_core::t_string->vx_new_from_string(":stylesheet-test"), vx_core::t_int->vx_new_from_int(0)
      }),
      vx_core::t_string->vx_new_from_string(":funcmap"), vx_core::t_intmap->vx_new(vx_core::t_intmap, {
              vx_core::t_string->vx_new_from_string(":div<-testcaselist"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":div<-testpackage"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":div<-testpackagelist"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":divchildlist<-testpackagelist"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":file-test"), vx_core::t_int->vx_new_from_int(1),
              vx_core::t_string->vx_new_from_string(":file-testhtml"), vx_core::t_int->vx_new_from_int(1),
              vx_core::t_string->vx_new_from_string(":file-testnode"), vx_core::t_int->vx_new_from_int(1),
              vx_core::t_string->vx_new_from_string(":html<-divtest"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":p<-passfail"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":p<-testcoveragenums"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":resolve-testcase"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":resolve-testcaselist"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":resolve-testdescribe"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":resolve-testdescribelist"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":resolve-testpackage"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":resolve-testpackagelist"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":resolve-testresult"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":test"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":test_1"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":test-false"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":test-false_1"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":test-gt"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":test-gt_1"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":test-ne"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":test-ne_1"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":test-string"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":test-string_1"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":test-true"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":test-true_1"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":tr<-testdescribe-casename"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":trlist<-testcase"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":trlist<-testcaselist"), vx_core::t_int->vx_new_from_int(0)
      })
    });
  }

  vx_test::Type_testpackage test_package(vx_core::Type_context context) {
    vx_test::Type_testcaselist testcaselist = test_cases(context);
    vx_test::Type_testpackage output = vx_test::t_testpackage->vx_new(vx_test::t_testpackage, {
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/test"), 
      vx_core::t_string->vx_new_from_string(":caselist"), testcaselist,
      vx_core::t_string->vx_new_from_string(":coveragesummary"), test_coveragesummary(),
      vx_core::t_string->vx_new_from_string(":coveragedetail"), test_coveragedetail()
    });
    return output;
  }

}
