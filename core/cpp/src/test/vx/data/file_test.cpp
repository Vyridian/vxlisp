#include "../../../main/vx/data/file.hpp"
#include "../../../main/vx/core.hpp"
#include "../../../main/vx/test.hpp"
#include "../../../main/vx/data/textblock.hpp"

namespace vx_data_file_test {

  vx_test::Type_testcase f_boolean_exists_from_file(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/file"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("boolean-exists<-file"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true\n (boolean-exists<-file\n  (file\n   :name \"boolean_exists_from_file.txt\"\n   :path \"src/test/resources/vx\")))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/file"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_data_file::f_boolean_exists_from_file(
                vx_core::f_new(
                  vx_data_file::t_file(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("boolean_exists_from_file.txt"),
                    vx_core::vx_new_string(":path"),
                    vx_core::vx_new_string("src/test/resources/vx")
                  })
                )
              ),
              context
            )
          })
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_boolean_write_from_file_string(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/file"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("boolean-write<-file-string"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true\n (boolean-write<-file-string\n  (file\n   :name \"boolean_write_from_file_string.txt\"\n   :path \"src/test/resources/vx\")\n  \"writetext\"))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/file"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_data_file::f_boolean_write_from_file_string(
                vx_core::f_new(
                  vx_data_file::t_file(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("boolean_write_from_file_string.txt"),
                    vx_core::vx_new_string(":path"),
                    vx_core::vx_new_string("src/test/resources/vx")
                  })
                ),
                vx_core::vx_new_string("writetext"),
                context
              ),
              context
            )
          })
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_file_read_from_file(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/file"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("file-read<-file"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (file\n  :name \"string_read_from_file.txt\"\n  :path \"src/test/resources/vx\"\n  :text \"testdata\")\n (file-read<-file\n  (file\n   :name \"string_read_from_file.txt\"\n   :path \"src/test/resources/vx\")))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/file"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::f_new(
                vx_data_file::t_file(),
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_string(":name"),
                  vx_core::vx_new_string("string_read_from_file.txt"),
                  vx_core::vx_new_string(":path"),
                  vx_core::vx_new_string("src/test/resources/vx"),
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("testdata")
                })
              ),
              vx_data_file::f_file_read_from_file(
                vx_core::f_new(
                  vx_data_file::t_file(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("string_read_from_file.txt"),
                    vx_core::vx_new_string(":path"),
                    vx_core::vx_new_string("src/test/resources/vx")
                  })
                ),
                context
              ),
              context
            )
          })
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_pathcurrent_from_os(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/file"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("pathcurrent<-os"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test-true\n (is-endswith (pathcurrent<-os) \"\\java\"))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/file"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test_true(
              vx_core::f_is_endswith(
                vx_data_file::f_pathcurrent_from_os(),
                vx_core::vx_new_string("\\java")
              ),
              context
            )
          })
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_string_read_from_file(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase(), {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/file"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("string-read<-file"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist(),
        vx_test::t_testdescribelist()->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe(), {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"testdata\"\n (string-read<-file\n  (file\n   :name \"string_read_from_file.txt\"\n   :path \"src/test/resources/vx\")))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/file"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("testdata"),
              vx_data_file::f_string_read_from_file(
                vx_core::f_new(
                  vx_data_file::t_file(),
                  vx_core::vx_new(vx_core::t_anylist(), {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("string_read_from_file.txt"),
                    vx_core::vx_new_string(":path"),
                    vx_core::vx_new_string("src/test/resources/vx")
                  })
                ),
                context
              ),
              context
            )
          })
        })
      )
    });
    return output;
  }

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {
    vx_core::vx_Type_listany listtestcase;
    listtestcase.push_back(vx_data_file_test::f_boolean_exists_from_file(context));
    listtestcase.push_back(vx_data_file_test::f_boolean_write_from_file_string(context));
    listtestcase.push_back(vx_data_file_test::f_file_read_from_file(context));
    listtestcase.push_back(vx_data_file_test::f_pathcurrent_from_os(context));
    listtestcase.push_back(vx_data_file_test::f_string_read_from_file(context));
    vx_test::Type_testcaselist output = vx_core::vx_any_from_any(
      vx_test::t_testcaselist(),
      vx_test::t_testcaselist()->vx_new_from_list(listtestcase)
    );
    return output;
  }

  vx_test::Type_testcoveragesummary test_coveragesummary() {
    return vx_core::vx_new(vx_test::t_testcoveragesummary(), {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/file"),
      vx_core::vx_new_string(":constnums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(100), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":docnums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(90), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(10), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(11)
      }),
      vx_core::vx_new_string(":funcnums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(55), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(5), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(9)
      }),
      vx_core::vx_new_string(":ospacenums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(9)
      }),
      vx_core::vx_new_string(":otimenums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(9)
      }),
      vx_core::vx_new_string(":totalnums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(45), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(5), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(11)
      }),
      vx_core::vx_new_string(":typenums"), vx_core::vx_new(vx_test::t_testcoveragenums(), {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(2)
      })
    });
  }

  vx_test::Type_testcoveragedetail test_coveragedetail() {
    return vx_core::vx_new(vx_test::t_testcoveragedetail(), {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/file"),
      vx_core::vx_new_string(":typemap"), vx_core::vx_new(vx_core::t_intmap(), {
        vx_core::vx_new_string(":file"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":fileformat"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":constmap"), vx_core::vx_new(vx_core::t_intmap(), {
        
      }),
      vx_core::vx_new_string(":funcmap"), vx_core::vx_new(vx_core::t_intmap(), {
        vx_core::vx_new_string(":boolean-exists<-file"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":boolean-write<-file-any"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":boolean-write<-file-string"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":file-read<-file"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":name<-file"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":path<-file"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":pathcurrent<-os"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":pathfull<-file"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string-read<-file"), vx_core::vx_new_int(1)
      })
    });
  }

  vx_test::Type_testpackage test_package(vx_core::Type_context context) {
    vx_test::Type_testcaselist testcaselist = test_cases(context);
    vx_test::Type_testpackage output = vx_core::vx_new(vx_test::t_testpackage(), {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/file"), 
      vx_core::vx_new_string(":caselist"), testcaselist,
      vx_core::vx_new_string(":coveragesummary"), test_coveragesummary(),
      vx_core::vx_new_string(":coveragedetail"), test_coveragedetail()
    });
    return output;
  }

}
