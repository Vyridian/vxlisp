#include "../../../main/vx/data/textblock.hpp"
#include "../../../main/vx/core.hpp"
#include "../../../main/vx/test.hpp"
#include "../../../main/vx/type.hpp"

#include "textblock_test.hpp"

namespace vx_data_textblock_test {

  vx_test::Type_testcase f_delim_first_from_delim_delim(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_delim_first_from_delim_delim");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::f_copy(
        vx_data_textblock::t_delim,
        vx_data_textblock::c_delimcomma,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(1)
        })
      ),
      vx_data_textblock::f_delim_first_from_delim_delim(
        vx_core::f_copy(
          vx_data_textblock::t_delim,
          vx_data_textblock::c_delimspace,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(2)
          })
        ),
        vx_core::f_copy(
          vx_data_textblock::t_delim,
          vx_data_textblock::c_delimcomma,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(1)
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (copy delimcomma\n  :startpos 1)\n (delim-first<-delim-delim\n  (copy delimspace\n   :startpos 2)\n  (copy delimcomma\n   :startpos 1)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("delim-first<-delim-delim"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_delim_first_from_delim_delim");
    return output;
  }

  vx_test::Type_testcase f_delim_first_from_string_delimlist(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_delim_first_from_string_delimlist");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::f_copy(
        vx_data_textblock::t_delim,
        vx_data_textblock::c_delimcomma,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(1)
        })
      ),
      vx_data_textblock::f_delim_first_from_string_delimlist(
        vx_core::vx_new_string("a, b"),
        vx_core::f_new(
          vx_data_textblock::t_delimlist,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_data_textblock::c_delimspace,
            vx_data_textblock::c_delimcomma
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (copy delimcomma\n  :startpos 1)\n (delim-first<-string-delimlist\n  \"a, b\"\n  (delimlist delimspace delimcomma)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("delim-first<-string-delimlist"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_delim_first_from_string_delimlist");
    return output;
  }

  vx_test::Type_testcase f_delim_startpos_from_string_delim(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_delim_startpos_from_string_delim");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::f_copy(
        vx_data_textblock::t_delim,
        vx_data_textblock::c_delimcomma,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(1)
        })
      ),
      vx_data_textblock::f_delim_startpos_from_string_delim(
        vx_core::vx_new_string("a,b"),
        vx_data_textblock::c_delimcomma
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (copy delimcomma\n  :startpos 1)\n (delim-startpos<-string-delim\n  \"a,b\"\n  delimcomma))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("delim-startpos<-string-delim"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_delim_startpos_from_string_delim");
    return output;
  }

  vx_test::Type_testcase f_delimlist_startpos_from_string_delimlist(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_delimlist_startpos_from_string_delimlist");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_delimlist,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::f_copy(
            vx_data_textblock::t_delim,
            vx_data_textblock::c_delimspace,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(2)
            })
          ),
          vx_core::f_copy(
            vx_data_textblock::t_delim,
            vx_data_textblock::c_delimcomma,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(1)
            })
          )
        })
      ),
      vx_data_textblock::f_delimlist_startpos_from_string_delimlist(
        vx_core::vx_new_string("a, b"),
        vx_core::f_new(
          vx_data_textblock::t_delimlist,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_data_textblock::c_delimspace,
            vx_data_textblock::c_delimcomma
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (delimlist\n  (copy delimspace\n   :startpos 2)\n  (copy delimcomma\n   :startpos 1))\n (delimlist-startpos<-string-delimlist\n  \"a, b\"\n  (delimlist delimspace delimcomma)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("delimlist-startpos<-string-delimlist"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_delimlist_startpos_from_string_delimlist");
    return output;
  }

  vx_test::Type_testcase f_textblock_firstdelim_from_textblock_delimlist(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_textblock_firstdelim_from_textblock_delimlist");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":delim"),
          vx_core::f_copy(
            vx_data_textblock::t_delim,
            vx_data_textblock::c_delimcomma,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(1)
            })
          ),
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string(" b"),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("a, b"),
              vx_core::vx_new_string(":textblocks"),
              vx_core::f_new(
                vx_data_textblock::t_textblocklist,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::f_new(
                    vx_data_textblock::t_textblock,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":text"),
                      vx_core::vx_new_string("a")
                    })
                  )
                })
              )
            })
          )
        })
      ),
      vx_data_textblock::f_textblock_firstdelim_from_textblock_delimlist(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("a, b")
          })
        ),
        vx_core::f_new(
          vx_data_textblock::t_delimlist,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_data_textblock::c_delimspace,
            vx_data_textblock::c_delimcomma
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :delim\n   (copy delimcomma\n    :startpos 1)\n  :text \" b\"\n  :parent\n   (textblock\n    :text \"a, b\"\n    :textblocks\n     (textblocklist\n      (textblock\n       :text \"a\"))))\n (textblock-firstdelim<-textblock-delimlist\n  (textblock\n   :text \"a, b\")\n  (delimlist delimspace delimcomma)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("textblock-firstdelim<-textblock-delimlist"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_textblock_firstdelim_from_textblock_delimlist");
    return output;
  }

  vx_test::Type_testcase f_textblock_startafter_from_string_delim(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_textblock_startafter_from_string_delim");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string(" b")
        })
      ),
      vx_data_textblock::f_textblock_startafter_from_string_delim(
        vx_core::vx_new_string("a, b"),
        vx_core::f_new(
          vx_data_textblock::t_delim,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":starttext"),
            vx_core::vx_new_string(","),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(1)
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \" b\")\n (textblock-startafter<-string-delim\n  \"a, b\"\n  (delim\n   :starttext \",\"\n   :startpos  1)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("textblock-startafter<-string-delim"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_textblock_startafter_from_string_delim");
    return output;
  }

  vx_test::Type_testcase f_textblock_startbefore_from_string_delim(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_textblock_startbefore_from_string_delim");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("a")
        })
      ),
      vx_data_textblock::f_textblock_startbefore_from_string_delim(
        vx_core::vx_new_string("a, b"),
        vx_core::f_new(
          vx_data_textblock::t_delim,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(1)
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"a\")\n (textblock-startbefore<-string-delim\n  \"a, b\"\n  (delim\n   :startpos 1)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("textblock-startbefore<-string-delim"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_textblock_startbefore_from_string_delim");
    return output;
  }

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {
    vx_core::vx_Type_listany listtestcase;
    listtestcase.push_back(vx_data_textblock_test::f_delim_first_from_delim_delim(context));
    listtestcase.push_back(vx_data_textblock_test::f_delim_first_from_string_delimlist(context));
    listtestcase.push_back(vx_data_textblock_test::f_delim_startpos_from_string_delim(context));
    listtestcase.push_back(vx_data_textblock_test::f_delimlist_startpos_from_string_delimlist(context));
    listtestcase.push_back(vx_data_textblock_test::f_textblock_firstdelim_from_textblock_delimlist(context));
    listtestcase.push_back(vx_data_textblock_test::f_textblock_startafter_from_string_delim(context));
    listtestcase.push_back(vx_data_textblock_test::f_textblock_startbefore_from_string_delim(context));
    vx_test::Type_testcaselist output = vx_core::vx_any_from_any(
      vx_test::t_testcaselist,
      vx_test::t_testcaselist->vx_new_from_list(listtestcase)
    );
    return output;
  }

  vx_test::Type_testcoveragesummary test_coveragesummary() {
    vx_test::Type_testcoveragesummary output = vx_core::vx_new(vx_test::t_testcoveragesummary, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":constnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(15)
      }),
      vx_core::vx_new_string(":docnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(100), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(30), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(30)
      }),
      vx_core::vx_new_string(":funcnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(63), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(7), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(11)
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
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(23), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(7), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(30)
      }),
      vx_core::vx_new_string(":typenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(4)
      })
    });
    return output;
  }

  vx_test::Type_testcoveragedetail test_coveragedetail() {
    vx_test::Type_testcoveragedetail output = vx_core::vx_new(vx_test::t_testcoveragedetail, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":typemap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":delim"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimlist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":textblock"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":textblocklist"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":constmap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":delimbracketcurly"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimbracketsquare"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimclose"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimcomma"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimcomment"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimcommentblock"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimline"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimnonwhitespace"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimparen"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimparenline"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimquote"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimquoteblock"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimspace"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimtext"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimwhitespace"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":funcmap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":delim-first<-delim-delim"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":delim-first<-string-delimlist"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":delim-startpos<-string-delim"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":delimlist-startpos<-string-delimlist"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":stringlist<-textblocklist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":text<-textblock"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":textblock-firstdelim<-textblock-delimlist"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":textblock-startafter<-string-delim"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":textblock-startbefore<-string-delim"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":textblock<-textblock-delim"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":textblocks<-textblock"), vx_core::vx_new_int(0)
      })
    });
    return output;
  }

  vx_test::Type_testpackage test_package(vx_core::Type_context context) {
    vx_test::Type_testcaselist testcaselist = vx_data_textblock_test::test_cases(context);
    vx_test::Type_testcoveragesummary testcoveragesummary = vx_data_textblock_test::test_coveragesummary();
    vx_test::Type_testcoveragedetail testcoveragedetail = vx_data_textblock_test::test_coveragedetail();
    vx_test::Type_testpackage output = vx_core::vx_new(vx_test::t_testpackage, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":caselist"), testcaselist,
      vx_core::vx_new_string(":coveragesummary"), testcoveragesummary,
      vx_core::vx_new_string(":coveragedetail"), testcoveragedetail
    });
    return output;
  }

}
