#include "../../../main/vx/data/csv.hpp"
#include "../../../main/vx/core.hpp"
#include "../../../main/vx/test.hpp"
#include "../../../main/vx/collection.hpp"
#include "../../../main/vx/data/file.hpp"
#include "../../../main/vx/data/textblock.hpp"
#include "../../../main/vx/type.hpp"

#include "csv_test.hpp"

namespace vx_data_csv_test {

  vx_test::Type_testcase f_textblock_csv_from_string(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_textblock_csv_from_string");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("\"a\",\"b\"\n1,\"2\""),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(1),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(13),
          vx_core::vx_new_string(":children"),
          vx_core::f_new(
            vx_data_textblock::t_textblocklist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("\"a\""),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(3),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimquote,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":pos"),
                      vx_core::vx_new_int(0)
                    })
                  ),
                  vx_core::vx_new_string(":children"),
                  vx_core::f_new(
                    vx_data_textblock::t_textblocklist,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::f_new(
                        vx_data_textblock::t_textblock,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":text"),
                          vx_core::vx_new_string("a"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(2),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(2)
                        })
                      )
                    })
                  )
                })
              ),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string(","),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(4),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(4),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimcomma,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":pos"),
                      vx_core::vx_new_int(0)
                    })
                  )
                })
              ),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("\"b\""),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(5),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(7),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimquote,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":pos"),
                      vx_core::vx_new_int(0)
                    })
                  ),
                  vx_core::vx_new_string(":children"),
                  vx_core::f_new(
                    vx_data_textblock::t_textblocklist,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::f_new(
                        vx_data_textblock::t_textblock,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":text"),
                          vx_core::vx_new_string("b"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(6),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(6)
                        })
                      )
                    })
                  )
                })
              ),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("\n"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(8),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(8),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimline,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":pos"),
                      vx_core::vx_new_int(0)
                    })
                  )
                })
              ),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("1"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(9),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(9)
                })
              ),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string(","),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(10),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(10),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimcomma,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":pos"),
                      vx_core::vx_new_int(0)
                    })
                  )
                })
              ),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("\"2\""),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(11),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimquote,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":pos"),
                      vx_core::vx_new_int(0)
                    })
                  ),
                  vx_core::vx_new_string(":children"),
                  vx_core::f_new(
                    vx_data_textblock::t_textblocklist,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::f_new(
                        vx_data_textblock::t_textblock,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":text"),
                          vx_core::vx_new_string("2"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(12),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(12)
                        })
                      )
                    })
                  )
                })
              )
            })
          )
        })
      ),
      vx_data_csv::f_textblock_csv_from_string(vx_core::vx_new_string("\"a\",\"b\"\n1,\"2\""))
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (tb/textblock\n  :text\n`\"a\",\"b\"\n1,\"2\"`\n  :startpos 1\n  :endpos 13\n  :children\n   (tb/textblocklist\n    (tb/textblock\n     :text `\"a\"`\n     :startpos 1\n     :endpos 3\n     :delim\n      (copy tb/delimquote\n       :pos 0)\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"a\"\n        :startpos 2\n        :endpos 2)))\n    (tb/textblock\n     :text \",\"\n     :startpos 4\n     :endpos 4\n     :delim\n      (copy tb/delimcomma\n       :pos 0))\n    (tb/textblock\n     :text `\"b\"`\n     :startpos 5\n     :endpos 7\n     :delim\n      (copy tb/delimquote\n       :pos 0)\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"b\"\n        :startpos 6\n        :endpos 6)))\n    (tb/textblock\n     :text \"\n\"\n     :startpos 8\n     :endpos 8\n     :delim\n      (copy tb/delimline\n       :pos 0))\n    (tb/textblock\n     :text \"1\"\n     :startpos 9\n     :endpos 9)\n    (tb/textblock\n     :text \",\"\n     :startpos 10\n     :endpos 10\n     :delim\n      (copy tb/delimcomma\n       :pos 0))\n    (tb/textblock\n     :text `\"2\"`\n     :startpos 11\n     :endpos 13\n     :delim\n      (copy tb/delimquote\n       :pos 0)\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"2\"\n        :startpos 12\n        :endpos 12)))))\n (textblock-csv<-string\n  `\"a\",\"b\"\n1,\"2\"`))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/csv"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/csv"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("textblock-csv<-string"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_textblock_csv_from_string");
    return output;
  }

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {
    vx_core::vx_Type_listany listtestcase;
    listtestcase.push_back(vx_data_csv_test::f_textblock_csv_from_string(context));
    vx_test::Type_testcaselist output = vx_core::vx_any_from_any(
      vx_test::t_testcaselist,
      vx_test::t_testcaselist->vx_new_from_list(listtestcase)
    );
    return output;
  }

  vx_test::Type_testcoveragesummary test_coveragesummary() {
    vx_test::Type_testcoveragesummary output = vx_core::vx_new(vx_test::t_testcoveragesummary, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/csv"),
      vx_core::vx_new_string(":constnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(1)
      }),
      vx_core::vx_new_string(":docnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(63), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(7), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(11)
      }),
      vx_core::vx_new_string(":funcnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(14), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(1), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(7)
      }),
      vx_core::vx_new_string(":bigospacenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(7)
      }),
      vx_core::vx_new_string(":bigotimenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(7)
      }),
      vx_core::vx_new_string(":totalnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(9), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(1), 
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
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/csv"),
      vx_core::vx_new_string(":typemap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":csv"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":csvrowmap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":csvrows"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":constmap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":delimcsv"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":funcmap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":csv-read<-file"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":csv<-file"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":csv<-string"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":csv<-textblock"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":csvrows<-textblock"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":stringmap<-csv"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":textblock-csv<-string"), vx_core::vx_new_int(1)
      })
    });
    return output;
  }

  vx_test::Type_testpackage test_package(vx_core::Type_context context) {
    vx_test::Type_testcaselist testcaselist = vx_data_csv_test::test_cases(context);
    vx_test::Type_testcoveragesummary testcoveragesummary = vx_data_csv_test::test_coveragesummary();
    vx_test::Type_testcoveragedetail testcoveragedetail = vx_data_csv_test::test_coveragedetail();
    vx_test::Type_testpackage output = vx_core::vx_new(vx_test::t_testpackage, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/csv"),
      vx_core::vx_new_string(":caselist"), testcaselist,
      vx_core::vx_new_string(":coveragesummary"), testcoveragesummary,
      vx_core::vx_new_string(":coveragedetail"), testcoveragedetail
    });
    return output;
  }

}
