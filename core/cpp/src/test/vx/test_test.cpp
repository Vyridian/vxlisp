#include "../../main/vx/test.hpp"
#include "../../main/vx/core.hpp"
#include "../../main/vx/data/file.hpp"
#include "../../main/vx/web/html.hpp"

namespace vx_test_test {

  vx_test::Type_testcase f_file_test(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/test"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("file-test"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true\n (boolean-exists<-file\n  (file\n   :name \"testsuite.vxlisp\"\n   :path \"src/test/resources\")))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_data_file::f_boolean_exists_from_file(
                vx_core::f_new(
                  vx_data_file::t_file(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("testsuite.vxlisp"),
                    vx_core::vx_new_string(":path"),
                    vx_core::vx_new_string("src/test/resources")
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

  vx_test::Type_testcase f_file_testhtml(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/test"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("file-testhtml"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true\n (boolean-exists<-file\n  (file\n   :name \"testsuite.html\"\n   :path \"src/test/resources\")))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_data_file::f_boolean_exists_from_file(
                vx_core::f_new(
                  vx_data_file::t_file(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("testsuite.html"),
                    vx_core::vx_new_string(":path"),
                    vx_core::vx_new_string("src/test/resources")
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

  vx_test::Type_testcase f_file_testnode(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/test"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("file-testnode"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true\n (boolean-exists<-file\n  (file\n   :name \"testsuitenode.vxlisp\"\n   :path \"src/test/resources\")))"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_data_file::f_boolean_exists_from_file(
                vx_core::f_new(
                  vx_data_file::t_file(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("testsuitenode.vxlisp"),
                    vx_core::vx_new_string(":path"),
                    vx_core::vx_new_string("src/test/resources")
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

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {
    vx_core::vx_Type_listany listtestcase;
    listtestcase.push_back(vx_test_test::f_file_test(context));
    listtestcase.push_back(vx_test_test::f_file_testhtml(context));
    listtestcase.push_back(vx_test_test::f_file_testnode(context));
    vx_test::Type_testcaselist output = vx_core::vx_any_from_any(
      vx_test::t_testcaselist(),
      vx_test::t_testcaselist()->vx_new_from_list(listtestcase)
    );
    return output;
  }

  vx_test::Type_testcoveragesummary test_coveragesummary() {
    return vx_core::vx_new(vx_test::t_testcoveragesummary(), {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/test"),
      vx_core::vx_new_string(":constnums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(1)
      }),
      vx_core::vx_new_string(":docnums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(93), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(41), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(44)
      }),
      vx_core::vx_new_string(":funcnums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(11), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(3), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(26)
      }),
      vx_core::vx_new_string(":ospacenums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(32)
      }),
      vx_core::vx_new_string(":otimenums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(32)
      }),
      vx_core::vx_new_string(":totalnums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(7), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(3), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(38)
      }),
      vx_core::vx_new_string(":typenums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(11)
      })
    });
  }

  vx_test::Type_testcoveragedetail test_coveragedetail() {
    return vx_core::vx_new(vx_test::t_testcoveragedetail(), {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/test"),
      vx_core::vx_new_string(":typemap"), vx_core::vx_new(vx_core::t_intmap(), {
        vx_core::vx_new_string(":testcase"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":testcaselist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":testcoveragedetail"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":testcoveragenums"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":testcoveragesummary"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":testdescribe"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":testdescribelist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":testpackage"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":testpackagelist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":testresult"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":testresultlist"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":constmap"), vx_core::vx_new(vx_core::t_intmap(), {
        vx_core::vx_new_string(":stylesheet-test"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":funcmap"), vx_core::vx_new(vx_core::t_intmap(), {
        vx_core::vx_new_string(":div<-testcaselist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":div<-testpackage"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":div<-testpackagelist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":divchildlist<-testpackagelist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":file-test"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":file-testhtml"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":file-testnode"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":html<-divtest"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":p<-passfail"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":p<-testcoveragenums"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":resolve-testcase"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":resolve-testcaselist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":resolve-testdescribe"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":resolve-testdescribelist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":resolve-testpackage"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":resolve-testpackagelist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":resolve-testresult"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":test"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":test_1"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":test-false"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":test-false_1"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":test-gt"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":test-gt_1"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":test-ne"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":test-ne_1"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":test-string"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":test-string_1"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":test-true"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":test-true_1"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":tr<-testdescribe-casename"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":trlist<-testcase"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":trlist<-testcaselist"), vx_core::vx_new_int(0)
      })
    });
  }

  vx_test::Type_testpackage test_package(vx_core::Type_context context) {
    vx_test::Type_testcaselist testcaselist = test_cases(context);
    vx_test::Type_testpackage output = vx_core::vx_new(vx_test::t_testpackage(), {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/test"), 
      vx_core::vx_new_string(":caselist"), testcaselist,
      vx_core::vx_new_string(":coveragesummary"), test_coveragesummary(),
      vx_core::vx_new_string(":coveragedetail"), test_coveragedetail()
    });
    return output;
  }

}
