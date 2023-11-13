#include "../../../main/vx/data/textblock.hpp"
#include "../../../main/vx/core.hpp"
#include "../../../main/vx/test.hpp"
#include "../../../main/vx/collection.hpp"
#include "../../../main/vx/type.hpp"

#include "textblock_test.hpp"

namespace vx_data_textblock_test {

  vx_test::Type_testcase t_delimlist(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: t_delimlist");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_delimlist,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_data_textblock::c_delimcomma,
          vx_data_textblock::c_delimwhitespace
        })
      ),
      vx_core::f_new(
        vx_data_textblock::t_delimlist,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_data_textblock::c_delimcomma,
          vx_data_textblock::c_delimwhitespace
        })
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (new delimlist\n  delimcomma\n  delimwhitespace)\n (delimlist\n  delimcomma\n  delimwhitespace))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("delimlist"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : t_delimlist");
    return output;
  }

  vx_test::Type_testcase f_delim_close_from_delim(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_delim_close_from_delim");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::f_copy(
        vx_data_textblock::t_delim,
        vx_data_textblock::c_delimbracketangle,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":delimlist"),
          vx_core::f_new(
            vx_data_textblock::t_delimlist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimclose,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":starttext"),
                  vx_core::vx_new_string(">")
                })
              )
            })
          )
        })
      ),
      vx_data_textblock::f_delim_close_from_delim(
        vx_data_textblock::c_delimbracketangle
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (copy delimbracketangle\n  :delimlist\n   (delimlist\n    (copy delimclose\n     :starttext \">\")))\n (delim-close<-delim delimbracketangle))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("delim-close<-delim"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_delim_close_from_delim");
    return output;
  }

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
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      vx_core::f_empty(
        vx_data_textblock::t_delim
      ),
      vx_data_textblock::f_delim_first_from_delim_delim(
        vx_core::f_new(
          vx_data_textblock::t_delim,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(-1)
          })
        ),
        vx_core::f_empty(
          vx_data_textblock::t_delim
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (empty delim)\n (delim-first<-delim-delim\n  (delim\n   :startpos -1)\n  (empty delim)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2
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

  vx_test::Type_testcase f_delim_first_from_string_delimlist_offset(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_delim_first_from_string_delimlist_offset");
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
      vx_data_textblock::f_delim_first_from_string_delimlist_offset(
        vx_core::vx_new_string("a, b"),
        vx_core::f_new(
          vx_data_textblock::t_delimlist,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_data_textblock::c_delimspace,
            vx_data_textblock::c_delimcomma
          })
        ),
        vx_core::vx_new_int(0)
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (copy delimcomma\n  :startpos 1)\n (delim-first<-string-delimlist-offset\n  \"a, b\"\n  (delimlist delimspace delimcomma)\n  0))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("delim-first<-string-delimlist-offset"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_delim_first_from_string_delimlist_offset");
    return output;
  }

  vx_test::Type_testcase f_delim_pos_from_string_delim_offset(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_delim_pos_from_string_delim_offset");
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
      vx_data_textblock::f_delim_pos_from_string_delim_offset(
        vx_core::vx_new_string("a,b"),
        vx_data_textblock::c_delimcomma,
        vx_core::vx_new_int(0)
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (copy delimcomma\n  :startpos 1)\n (delim-pos<-string-delim-offset\n  \"a,b\"\n  delimcomma\n  0))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("delim-pos<-string-delim-offset"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_delim_pos_from_string_delim_offset");
    return output;
  }

  vx_test::Type_testcase f_delimlist_pos_from_string_delimlist_offset(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_delimlist_pos_from_string_delimlist_offset");
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
      vx_data_textblock::f_delimlist_pos_from_string_delimlist_offset(
        vx_core::vx_new_string("a, b"),
        vx_core::f_new(
          vx_data_textblock::t_delimlist,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_data_textblock::c_delimspace,
            vx_data_textblock::c_delimcomma
          })
        ),
        vx_core::vx_new_int(0)
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (delimlist\n  (copy delimspace\n   :startpos 2)\n  (copy delimcomma\n   :startpos 1))\n (delimlist-pos<-string-delimlist-offset\n  \"a, b\"\n  (delimlist delimspace delimcomma)\n  0))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("delimlist-pos<-string-delimlist-offset"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_delimlist_pos_from_string_delimlist_offset");
    return output;
  }

  vx_test::Type_testcase f_stringlist_from_textblocklist(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_stringlist_from_textblocklist");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::f_new(
        vx_core::t_stringlist,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string("a"),
          vx_core::vx_new_string("b")
        })
      ),
      vx_data_textblock::f_stringlist_from_textblocklist(
        vx_core::f_new(
          vx_data_textblock::t_textblocklist,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("a")
              })
            ),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("b")
              })
            )
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (stringlist \"a\" \"b\")\n (stringlist<-textblocklist\n  (textblocklist\n   (textblock :text \"a\")\n   (textblock :text \"b\"))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("stringlist<-textblocklist"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_stringlist_from_textblocklist");
    return output;
  }

  vx_test::Type_testcase f_text_from_textblock(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_text_from_textblock");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::vx_new_string("a"),
      vx_data_textblock::f_text_from_textblock(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("a")
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"a\"\n (text<-textblock\n  (textblock\n   :text \"a\")))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("text<-textblock"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_text_from_textblock");
    return output;
  }

  vx_test::Type_testcase f_textblock_parse(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_textblock_parse");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("a,b,c"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(0),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(5),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(0),
              vx_core::vx_new_string(":delimlist"),
              vx_core::f_new(
                vx_data_textblock::t_delimlist,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_data_textblock::c_delimcomma
                })
              )
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
                  vx_core::vx_new_int(0),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(1)
                })
              ),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string(","),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(2),
                  vx_core::vx_new_string(":delim"),
                  vx_data_textblock::c_delimcomma
                })
              ),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("b"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(2),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(3)
                })
              ),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string(","),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(3),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(4),
                  vx_core::vx_new_string(":delim"),
                  vx_data_textblock::c_delimcomma
                })
              ),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("c"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(4),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(5)
                })
              )
            })
          )
        })
      ),
      vx_data_textblock::f_textblock_parse(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("a,b,c"),
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_core::f_new(
                  vx_data_textblock::t_delimlist,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_data_textblock::c_delimcomma
                  })
                )
              })
            )
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"a,b,c\"\n  :startpos 0\n  :endpos 5\n  :delim\n   (delim\n    :startpos 0\n    :delimlist\n     (delimlist\n      delimcomma))\n  :children\n   (textblocklist\n    (textblock\n     :text \"a\"\n     :startpos 0\n     :endpos 1)\n    (textblock\n     :text \",\"\n     :startpos 1\n     :endpos 2\n     :delim delimcomma)\n    (textblock\n     :text \"b\"\n     :startpos 2\n     :endpos 3)\n    (textblock\n     :text \",\"\n     :startpos 3\n     :endpos 4\n     :delim delimcomma)\n    (textblock\n     :text \"c\"\n     :startpos 4\n     :endpos 5)))\n (textblock-parse\n  (textblock\n   :text \"a,b,c\"\n   :delim\n    (delim\n     :delimlist\n      (delimlist\n       delimcomma)))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("a<b>c"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(0),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(5),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(0),
              vx_core::vx_new_string(":delimlist"),
              vx_core::f_new(
                vx_data_textblock::t_delimlist,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_data_textblock::c_delimbracketangle
                })
              )
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
                  vx_core::vx_new_int(0),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(1)
                })
              ),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("<b>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(4),
                  vx_core::vx_new_string(":delim"),
                  vx_data_textblock::c_delimbracketangle,
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
                          vx_core::vx_new_int(2),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(3)
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
                  vx_core::vx_new_string("c"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(4),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(5)
                })
              )
            })
          )
        })
      ),
      vx_data_textblock::f_textblock_parse(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("a<b>c"),
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_core::f_new(
                  vx_data_textblock::t_delimlist,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_data_textblock::c_delimbracketangle
                  })
                )
              })
            )
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"a<b>c\"\n  :startpos 0\n  :endpos 5\n  :delim\n   (delim\n    :startpos 0\n    :delimlist\n     (delimlist\n      delimbracketangle))\n  :children\n   (textblocklist\n    (textblock\n     :text \"a\"\n     :startpos 0\n     :endpos 1)\n    (textblock\n     :text \"<b>\"\n     :startpos 1\n     :endpos 4\n     :delim delimbracketangle\n     :children\n      (textblocklist\n       (textblock\n        :text \"b\"\n        :startpos 2\n        :endpos 3)))\n    (textblock\n     :text \"c\"\n     :startpos 4\n     :endpos 5)))\n (textblock-parse\n  (textblock\n   :text \"a<b>c\"\n   :delim\n    (delim\n     :delimlist\n      (delimlist\n       delimbracketangle)))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("textblock-parse"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_textblock_parse");
    return output;
  }

  vx_test::Type_testcase f_textblock_parse_one(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_textblock_parse_one");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("a"),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(1)
        })
      ),
      vx_data_textblock::f_textblock_parse_one(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("a")
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"a\"\n  :endpos 1)\n (textblock-parse-one\n  (textblock\n   :text \"a\")))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("b"),
          vx_core::vx_new_string(":children"),
          vx_core::f_new(
            vx_data_textblock::t_textblocklist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("a"),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(1)
                })
              )
            })
          )
        })
      ),
      vx_data_textblock::f_textblock_parse_one(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("a"),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("b")
              })
            )
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"b\"\n  :children\n   (textblocklist\n    (textblock\n     :text \"a\"\n     :endpos 1)))\n (textblock-parse-one\n  (textblock\n   :text \"a\"\n   :parent\n    (textblock\n     :text \"b\"))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    // testdescribe_3
    vx_test::Type_testresult testresult_3 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("a"),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(1),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string(",b,c"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(1),
              vx_core::vx_new_string(":curpos"),
              vx_core::vx_new_int(1),
              vx_core::vx_new_string(":delim"),
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimcomma,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":delimlist"),
                  vx_core::f_new(
                    vx_data_textblock::t_delimlist,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_data_textblock::c_delimcomma
                    })
                  )
                })
              ),
              vx_core::vx_new_string(":parent"),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("a,b,c"),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(5),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_new(
                    vx_data_textblock::t_delim,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      vx_core::f_new(
                        vx_data_textblock::t_delimlist,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_data_textblock::c_delimcomma
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
      vx_data_textblock::f_textblock_parse_one(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("a,b,c"),
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_core::f_new(
                  vx_data_textblock::t_delimlist,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_data_textblock::c_delimcomma
                  })
                )
              })
            )
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_3 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"a\"\n  :endpos 1\n  :parent\n   (textblock\n    :text \",b,c\"\n    :startpos 1\n    :curpos 1\n    :delim\n     (copy delimcomma\n      :startpos 1\n      :delimlist\n       (delimlist\n        delimcomma))\n    :parent\n     (textblock\n      :text \"a,b,c\"\n      :endpos 5\n      :delim\n       (delim\n        :delimlist\n         (delimlist\n          delimcomma)))))\n (textblock-parse-one\n  (textblock\n   :text \"a,b,c\"\n   :delim\n    (delim\n     :delimlist\n      (delimlist\n       delimcomma)))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_3
    });
    // testdescribe_4
    vx_test::Type_testresult testresult_4 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string(",b,c"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(1),
          vx_core::vx_new_string(":curpos"),
          vx_core::vx_new_int(1),
          vx_core::vx_new_string(":delim"),
          vx_core::f_copy(
            vx_data_textblock::t_delim,
            vx_data_textblock::c_delimcomma,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(1),
              vx_core::vx_new_string(":delimlist"),
              vx_core::f_new(
                vx_data_textblock::t_delimlist,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_data_textblock::c_delimcomma
                })
              )
            })
          ),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("a,b,c"),
              vx_core::vx_new_string(":delim"),
              vx_core::f_new(
                vx_data_textblock::t_delim,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_core::f_new(
                    vx_data_textblock::t_delimlist,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_data_textblock::c_delimcomma
                    })
                  )
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
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(1)
                    })
                  )
                })
              )
            })
          )
        })
      ),
      vx_data_textblock::f_textblock_parse_one(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("a"),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(1),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string(",b,c"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(1),
                vx_core::vx_new_string(":curpos"),
                vx_core::vx_new_int(1),
                vx_core::vx_new_string(":delim"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimcomma,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(1),
                    vx_core::vx_new_string(":delimlist"),
                    vx_core::f_new(
                      vx_data_textblock::t_delimlist,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_data_textblock::c_delimcomma
                      })
                    )
                  })
                ),
                vx_core::vx_new_string(":parent"),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("a,b,c"),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_new(
                      vx_data_textblock::t_delim,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":delimlist"),
                        vx_core::f_new(
                          vx_data_textblock::t_delimlist,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_data_textblock::c_delimcomma
                          })
                        )
                      })
                    )
                  })
                )
              })
            )
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_4 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \",b,c\"\n  :startpos 1\n  :curpos 1\n  :delim\n   (copy delimcomma\n    :startpos 1\n    :delimlist\n     (delimlist\n      delimcomma))\n  :parent\n   (textblock\n    :text \"a,b,c\"\n    :delim\n     (delim\n      :delimlist\n       (delimlist\n        delimcomma))\n    :children\n     (textblocklist\n      (textblock\n       :text \"a\"\n       :endpos 1))))\n (textblock-parse-one\n  (textblock\n   :text \"a\"\n   :endpos 1\n   :parent\n    (textblock\n     :text \",b,c\"\n     :startpos 1\n     :curpos 1\n     :delim\n      (copy delimcomma\n       :startpos 1\n       :delimlist\n        (delimlist\n         delimcomma))\n     :parent\n      (textblock\n       :text \"a,b,c\"\n       :delim\n        (delim\n         :delimlist\n          (delimlist\n           delimcomma)))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_4
    });
    // testdescribe_5
    vx_test::Type_testresult testresult_5 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("b,c"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(2),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              vx_core::f_new(
                vx_data_textblock::t_delimlist,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_data_textblock::c_delimcomma
                })
              )
            })
          ),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("a,b,c"),
              vx_core::vx_new_string(":delim"),
              vx_core::f_new(
                vx_data_textblock::t_delim,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_core::f_new(
                    vx_data_textblock::t_delimlist,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_data_textblock::c_delimcomma
                    })
                  )
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
                      vx_core::vx_new_int(0),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(1)
                    })
                  ),
                  vx_core::f_new(
                    vx_data_textblock::t_textblock,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":text"),
                      vx_core::vx_new_string(","),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(2),
                      vx_core::vx_new_string(":delim"),
                      vx_data_textblock::c_delimcomma
                    })
                  )
                })
              )
            })
          )
        })
      ),
      vx_data_textblock::f_textblock_parse_one(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string(",b,c"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(1),
            vx_core::vx_new_string(":curpos"),
            vx_core::vx_new_int(1),
            vx_core::vx_new_string(":delim"),
            vx_core::f_copy(
              vx_data_textblock::t_delim,
              vx_data_textblock::c_delimcomma,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(1),
                vx_core::vx_new_string(":delimlist"),
                vx_core::f_new(
                  vx_data_textblock::t_delimlist,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_data_textblock::c_delimcomma
                  })
                )
              })
            ),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("a,b,c"),
                vx_core::vx_new_string(":delim"),
                vx_core::f_new(
                  vx_data_textblock::t_delim,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_core::f_new(
                      vx_data_textblock::t_delimlist,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_data_textblock::c_delimcomma
                      })
                    )
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
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(1)
                      })
                    )
                  })
                )
              })
            )
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_5 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"b,c\"\n  :startpos 2\n  :delim\n   (delim\n    :delimlist\n     (delimlist\n      delimcomma))\n  :parent\n   (textblock\n    :text \"a,b,c\"\n    :delim\n     (delim\n      :delimlist\n       (delimlist\n        delimcomma))\n    :children\n     (textblocklist\n      (textblock\n       :text \"a\"\n       :startpos 0\n       :endpos 1)\n      (textblock\n       :text \",\"\n       :startpos 1\n       :endpos 2\n       :delim delimcomma))))\n (textblock-parse-one\n  (textblock\n   :text \",b,c\"\n   :startpos 1\n   :curpos 1\n   :delim\n    (copy delimcomma\n     :startpos 1\n     :delimlist\n      (delimlist\n       delimcomma))\n   :parent\n    (textblock\n     :text \"a,b,c\"\n     :delim\n      (delim\n       :delimlist\n        (delimlist\n         delimcomma))\n     :children\n      (textblocklist\n       (textblock\n        :text \"a\"\n        :endpos 1))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_5
    });
    // testdescribe_6
    vx_test::Type_testresult testresult_6 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("b"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(2),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(3),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string(",c"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(3),
              vx_core::vx_new_string(":curpos"),
              vx_core::vx_new_int(1),
              vx_core::vx_new_string(":delim"),
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimcomma,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":delimlist"),
                  vx_core::f_new(
                    vx_data_textblock::t_delimlist,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_data_textblock::c_delimcomma
                    })
                  )
                })
              ),
              vx_core::vx_new_string(":parent"),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("a,b,c"),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_new(
                    vx_data_textblock::t_delim,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      vx_core::f_new(
                        vx_data_textblock::t_delimlist,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_data_textblock::c_delimcomma
                        })
                      )
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
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(1)
                        })
                      ),
                      vx_core::f_new(
                        vx_data_textblock::t_textblock,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":text"),
                          vx_core::vx_new_string(","),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(1),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(2),
                          vx_core::vx_new_string(":delim"),
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_textblock::c_delimcomma,
                            vx_core::vx_new(vx_core::t_anylist, {
                              vx_core::vx_new_string(":startpos"),
                              vx_core::vx_new_int(1),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(2)
                            })
                          )
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
      vx_data_textblock::f_textblock_parse_one(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("b,c"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(2),
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_core::f_new(
                  vx_data_textblock::t_delimlist,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_data_textblock::c_delimcomma
                  })
                )
              })
            ),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("a,b,c"),
                vx_core::vx_new_string(":delim"),
                vx_core::f_new(
                  vx_data_textblock::t_delim,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_core::f_new(
                      vx_data_textblock::t_delimlist,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_data_textblock::c_delimcomma
                      })
                    )
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
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(1)
                      })
                    ),
                    vx_core::f_new(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":text"),
                        vx_core::vx_new_string(","),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(1),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(2),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_textblock::c_delimcomma,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(1),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(2)
                          })
                        )
                      })
                    )
                  })
                )
              })
            )
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_6 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"b\"\n  :startpos 2\n  :endpos 3\n  :parent\n   (textblock\n    :text \",c\"\n    :startpos 3\n    :curpos 1\n    :delim\n     (copy delimcomma\n      :startpos 1\n      :delimlist\n       (delimlist\n        delimcomma))\n    :parent\n     (textblock\n      :text \"a,b,c\"\n      :delim\n       (delim\n        :delimlist\n         (delimlist\n          delimcomma))\n      :children\n       (textblocklist\n        (textblock\n         :text \"a\"\n         :endpos 1)\n        (textblock\n         :text \",\"\n         :startpos 1\n         :endpos 2\n         :delim\n          (copy delimcomma\n           :startpos 1\n           :endpos 2))))))\n (textblock-parse-one\n  (textblock\n   :text \"b,c\"\n   :startpos 2\n   :delim\n    (delim\n     :delimlist\n      (delimlist\n       delimcomma))\n   :parent\n    (textblock\n     :text \"a,b,c\"\n     :delim\n      (delim\n       :delimlist\n        (delimlist\n         delimcomma))\n     :children\n      (textblocklist\n       (textblock\n        :text \"a\"\n        :endpos 1)\n       (textblock\n        :text \",\"\n        :startpos 1\n        :endpos 2\n        :delim\n         (copy delimcomma\n          :startpos 1\n          :endpos 2)))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_6
    });
    // testdescribe_7
    vx_test::Type_testresult testresult_7 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("a"),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(1),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("<b>c"),
              vx_core::vx_new_string(":delim"),
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimbracketangle,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1)
                })
              ),
              vx_core::vx_new_string(":close"),
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimclose,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":starttext"),
                  vx_core::vx_new_string(">")
                })
              ),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(1),
              vx_core::vx_new_string(":curpos"),
              vx_core::vx_new_int(1),
              vx_core::vx_new_string(":parent"),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("a<b>c"),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(5),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_new(
                    vx_data_textblock::t_delim,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      vx_core::f_new(
                        vx_data_textblock::t_delimlist,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_data_textblock::c_delimbracketangle
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
      vx_data_textblock::f_textblock_parse_one(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("a<b>c"),
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_core::f_new(
                  vx_data_textblock::t_delimlist,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_data_textblock::c_delimbracketangle
                  })
                )
              })
            )
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_7 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"a\"\n  :endpos 1\n  :parent\n   (textblock\n    :text \"<b>c\"\n    :delim\n     (copy delimbracketangle\n      :startpos 1)\n    :close\n     (copy delimclose\n      :starttext \">\")\n    :startpos 1\n    :curpos 1\n    :parent\n     (textblock\n      :text \"a<b>c\"\n      :endpos 5\n      :delim\n       (delim\n        :delimlist\n         (delimlist\n          delimbracketangle)))))\n (textblock-parse-one\n  (textblock\n   :text \"a<b>c\"\n   :delim\n    (delim\n     :delimlist\n      (delimlist\n       delimbracketangle)))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_7
    });
    // testdescribe_8
    vx_test::Type_testresult testresult_8 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("<b>c"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(2),
          vx_core::vx_new_string(":curpos"),
          vx_core::vx_new_int(1),
          vx_core::vx_new_string(":delim"),
          vx_core::f_copy(
            vx_data_textblock::t_delim,
            vx_data_textblock::c_delimbracketangle,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(1)
            })
          ),
          vx_core::vx_new_string(":close"),
          vx_core::f_copy(
            vx_data_textblock::t_delim,
            vx_data_textblock::c_delimclose,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":starttext"),
              vx_core::vx_new_string(">")
            })
          ),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("a<b>c"),
              vx_core::vx_new_string(":delim"),
              vx_core::f_new(
                vx_data_textblock::t_delim,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_core::f_new(
                    vx_data_textblock::t_delimlist,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_data_textblock::c_delimbracketangle
                    })
                  )
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
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(1)
                    })
                  )
                })
              )
            })
          )
        })
      ),
      vx_data_textblock::f_textblock_parse_one(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("a"),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(1),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("<b>c"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(2),
                vx_core::vx_new_string(":curpos"),
                vx_core::vx_new_int(1),
                vx_core::vx_new_string(":delim"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimbracketangle,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(1)
                  })
                ),
                vx_core::vx_new_string(":close"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimclose,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":starttext"),
                    vx_core::vx_new_string(">")
                  })
                ),
                vx_core::vx_new_string(":parent"),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("a<b>c"),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_new(
                      vx_data_textblock::t_delim,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":delimlist"),
                        vx_core::f_new(
                          vx_data_textblock::t_delimlist,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_data_textblock::c_delimbracketangle
                          })
                        )
                      })
                    )
                  })
                )
              })
            )
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_8 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"<b>c\"\n  :startpos 2\n  :curpos 1\n  :delim\n   (copy delimbracketangle\n    :startpos 1)\n  :close\n   (copy delimclose\n    :starttext \">\")\n  :parent\n   (textblock\n    :text \"a<b>c\"\n    :delim \n     (delim\n      :delimlist\n       (delimlist\n        delimbracketangle))\n    :children\n     (textblocklist\n      (textblock\n       :text \"a\"\n       :endpos 1))))\n (textblock-parse-one\n  (textblock\n   :text \"a\"\n   :endpos 1\n   :parent\n    (textblock\n     :text \"<b>c\"\n     :startpos 2\n     :curpos 1\n     :delim\n      (copy delimbracketangle\n       :startpos 1)\n     :close\n      (copy delimclose\n       :starttext \">\")\n     :parent\n      (textblock\n       :text \"a<b>c\"\n       :delim\n        (delim\n         :delimlist\n          (delimlist\n           delimbracketangle)))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_8
    });
    // testdescribe_9
    vx_test::Type_testresult testresult_9 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("c"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(4),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              vx_core::f_new(
                vx_data_textblock::t_delimlist,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_data_textblock::c_delimbracketangle
                })
              )
            })
          ),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("a<b>c"),
              vx_core::vx_new_string(":delim"),
              vx_core::f_new(
                vx_data_textblock::t_delim,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_core::f_new(
                    vx_data_textblock::t_delimlist,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_data_textblock::c_delimbracketangle
                    })
                  )
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
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(1)
                    })
                  ),
                  vx_core::f_new(
                    vx_data_textblock::t_textblock,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":text"),
                      vx_core::vx_new_string("<b>"),
                      vx_core::vx_new_string(":delim"),
                      vx_data_textblock::c_delimbracketangle,
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(4),
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
                              vx_core::vx_new_int(2),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(3)
                            })
                          )
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
      vx_data_textblock::f_textblock_parse_one(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("<b>c"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(1),
            vx_core::vx_new_string(":curpos"),
            vx_core::vx_new_int(1),
            vx_core::vx_new_string(":delim"),
            vx_core::f_copy(
              vx_data_textblock::t_delim,
              vx_data_textblock::c_delimbracketangle,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(1)
              })
            ),
            vx_core::vx_new_string(":close"),
            vx_core::f_copy(
              vx_data_textblock::t_delim,
              vx_data_textblock::c_delimclose,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":starttext"),
                vx_core::vx_new_string(">")
              })
            ),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("a<b>c"),
                vx_core::vx_new_string(":delim"),
                vx_core::f_new(
                  vx_data_textblock::t_delim,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_core::f_new(
                      vx_data_textblock::t_delimlist,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_data_textblock::c_delimbracketangle
                      })
                    )
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
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(1)
                      })
                    )
                  })
                )
              })
            )
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_9 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"c\"\n  :startpos 4\n  :delim\n   (delim\n    :delimlist\n     (delimlist\n      delimbracketangle))\n  :parent\n   (textblock\n    :text \"a<b>c\"\n    :delim \n     (delim\n      :delimlist\n       (delimlist\n        delimbracketangle))\n    :children\n     (textblocklist\n      (textblock\n       :text \"a\"\n       :endpos 1)\n      (textblock\n       :text \"<b>\"\n       :delim delimbracketangle\n       :startpos 1\n       :endpos 4\n       :children\n        (textblocklist\n         (textblock\n          :text \"b\"\n          :startpos 2\n          :endpos 3))))))\n (textblock-parse-one\n  (textblock\n   :text \"<b>c\"\n   :startpos 1\n   :curpos 1\n   :delim\n    (copy delimbracketangle\n     :startpos 1)\n   :close\n    (copy delimclose\n     :starttext \">\")\n   :parent\n    (textblock\n     :text \"a<b>c\"\n     :delim\n      (delim\n       :delimlist\n        (delimlist\n         delimbracketangle))\n     :children\n      (textblocklist\n       (textblock\n        :text \"a\"\n        :endpos 1))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_9
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2,
      testdescribe_3,
      testdescribe_4,
      testdescribe_5,
      testdescribe_6,
      testdescribe_7,
      testdescribe_8,
      testdescribe_9
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("textblock-parse-one"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_textblock_parse_one");
    return output;
  }

  vx_test::Type_testcase f_textblock_pop(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_textblock_pop");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("parent"),
          vx_core::vx_new_string(":children"),
          vx_core::f_new(
            vx_data_textblock::t_textblocklist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("child"),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(5)
                })
              )
            })
          )
        })
      ),
      vx_data_textblock::f_textblock_pop(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("child"),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("parent")
              })
            )
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"parent\"\n  :children\n   (textblocklist\n    (textblock\n     :text \"child\"\n     :endpos 5)))\n (textblock-pop\n  (textblock\n   :text \"child\"\n   :parent\n    (textblock\n     :text \"parent\"))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("a,b,c"),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              vx_core::f_new(
                vx_data_textblock::t_delimlist,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::f_new(
                    vx_data_textblock::t_delim,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":name"),
                      vx_core::vx_new_string("delimcomma"),
                      vx_core::vx_new_string(":starttext"),
                      vx_core::vx_new_string(",")
                    })
                  )
                })
              )
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
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(1)
                })
              ),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string(","),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(2),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_new(
                    vx_data_textblock::t_delim,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":name"),
                      vx_core::vx_new_string("delimcomma"),
                      vx_core::vx_new_string(":starttext"),
                      vx_core::vx_new_string(","),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(2)
                    })
                  )
                })
              ),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("b"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(2),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(3)
                })
              ),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string(","),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(3),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(4),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_new(
                    vx_data_textblock::t_delim,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":name"),
                      vx_core::vx_new_string("delimcomma"),
                      vx_core::vx_new_string(":starttext"),
                      vx_core::vx_new_string(","),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(4)
                    })
                  )
                })
              ),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("c"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(4),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(5)
                })
              )
            })
          )
        })
      ),
      vx_data_textblock::f_textblock_pop(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("c"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(4),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(5),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("a,b,c"),
                vx_core::vx_new_string(":delim"),
                vx_core::f_new(
                  vx_data_textblock::t_delim,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_core::f_new(
                      vx_data_textblock::t_delimlist,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::f_new(
                          vx_data_textblock::t_delim,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":name"),
                            vx_core::vx_new_string("delimcomma"),
                            vx_core::vx_new_string(":starttext"),
                            vx_core::vx_new_string(",")
                          })
                        )
                      })
                    )
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
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(1)
                      })
                    ),
                    vx_core::f_new(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":text"),
                        vx_core::vx_new_string(","),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(1),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(2),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_new(
                          vx_data_textblock::t_delim,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":name"),
                            vx_core::vx_new_string("delimcomma"),
                            vx_core::vx_new_string(":starttext"),
                            vx_core::vx_new_string(","),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(1),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(2)
                          })
                        )
                      })
                    ),
                    vx_core::f_new(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":text"),
                        vx_core::vx_new_string("b"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(2),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(3)
                      })
                    ),
                    vx_core::f_new(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":text"),
                        vx_core::vx_new_string(","),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(3),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(4),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_new(
                          vx_data_textblock::t_delim,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":name"),
                            vx_core::vx_new_string("delimcomma"),
                            vx_core::vx_new_string(":starttext"),
                            vx_core::vx_new_string(","),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(1),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(4)
                          })
                        )
                      })
                    )
                  })
                )
              })
            )
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"a,b,c\"\n  :delim\n   (delim\n    :delimlist\n     (delimlist\n      (delim\n       :name \"delimcomma\"\n       :starttext \",\")))\n  :children\n   (textblocklist\n    (textblock\n     :text \"a\"\n     :endpos 1)\n    (textblock\n     :text \",\"\n     :startpos 1\n     :endpos 2\n     :delim\n      (delim\n       :name \"delimcomma\"\n       :starttext \",\"\n       :startpos 1\n       :endpos 2))\n    (textblock\n     :text \"b\"\n     :startpos 2\n     :endpos 3)\n    (textblock\n     :text \",\"\n     :startpos 3\n     :endpos 4\n     :delim\n      (delim\n       :name \"delimcomma\"\n       :starttext \",\"\n       :startpos 1\n       :endpos 4))\n    (textblock\n     :text \"c\"\n     :startpos 4\n     :endpos 5)))\n (textblock-pop\n  (textblock\n   :text \"c\"\n   :startpos 4\n   :endpos 5\n   :parent\n    (textblock\n     :text \"a,b,c\"\n     :delim\n      (delim\n       :delimlist\n        (delimlist\n         (delim\n          :name \"delimcomma\"\n          :starttext \",\")))\n     :children\n      (textblocklist\n       (textblock\n        :text \"a\"\n        :endpos 1)\n       (textblock\n        :text \",\"\n        :startpos 1\n        :endpos 2\n        :delim\n         (delim\n          :name \"delimcomma\"\n          :starttext \",\"\n          :startpos 1\n          :endpos 2))\n       (textblock\n        :text \"b\"\n        :startpos 2\n        :endpos 3)\n       (textblock\n        :text \",\"\n        :startpos 3\n        :endpos 4\n        :delim\n         (delim\n          :name \"delimcomma\"\n          :starttext \",\"\n          :startpos 1\n          :endpos 4)))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("textblock-pop"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_textblock_pop");
    return output;
  }

  vx_test::Type_testcase f_textblock_pop_from_textblock_delim(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_textblock_pop_from_textblock_delim");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("parent"),
          vx_core::vx_new_string(":children"),
          vx_core::f_new(
            vx_data_textblock::t_textblocklist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("child"),
                  vx_core::vx_new_string(":delim"),
                  vx_data_textblock::c_delimcomma
                })
              )
            })
          )
        })
      ),
      vx_data_textblock::f_textblock_pop_from_textblock_delim(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("child"),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("parent")
              })
            )
          })
        ),
        vx_data_textblock::c_delimcomma
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"parent\"\n  :children\n   (textblocklist\n    (textblock\n     :text \"child\"\n     :delim delimcomma)))\n (textblock-pop<-textblock-delim\n  (textblock\n   :text \"child\"\n   :parent\n    (textblock\n     :text \"parent\"))\n   delimcomma))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("c"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(4),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              vx_core::f_new(
                vx_data_textblock::t_delimlist,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_data_textblock::c_delimbracketangle
                })
              )
            })
          ),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("a<b>c"),
              vx_core::vx_new_string(":delim"),
              vx_core::f_new(
                vx_data_textblock::t_delim,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_core::f_new(
                    vx_data_textblock::t_delimlist,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_data_textblock::c_delimbracketangle
                    })
                  )
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
                      vx_core::vx_new_int(0),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(1)
                    })
                  ),
                  vx_core::f_new(
                    vx_data_textblock::t_textblock,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":text"),
                      vx_core::vx_new_string("<b>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(4),
                      vx_core::vx_new_string(":delim"),
                      vx_data_textblock::c_delimbracketangle,
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
                              vx_core::vx_new_int(2),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(3)
                            })
                          )
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
      vx_data_textblock::f_textblock_pop_from_textblock_delim(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("<b>c"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(1),
            vx_core::vx_new_string(":curpos"),
            vx_core::vx_new_int(1),
            vx_core::vx_new_string(":delim"),
            vx_core::f_copy(
              vx_data_textblock::t_delim,
              vx_data_textblock::c_delimbracketangle,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(1)
              })
            ),
            vx_core::vx_new_string(":close"),
            vx_core::f_copy(
              vx_data_textblock::t_delim,
              vx_data_textblock::c_delimclose,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":starttext"),
                vx_core::vx_new_string(">")
              })
            ),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("a<b>c"),
                vx_core::vx_new_string(":delim"),
                vx_core::f_new(
                  vx_data_textblock::t_delim,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_core::f_new(
                      vx_data_textblock::t_delimlist,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_data_textblock::c_delimbracketangle
                      })
                    )
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
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(1)
                      })
                    )
                  })
                )
              })
            )
          })
        ),
        vx_core::f_copy(
          vx_data_textblock::t_delim,
          vx_data_textblock::c_delimclose,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":starttext"),
            vx_core::vx_new_string(">"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(2)
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"c\"\n  :startpos 4\n  :delim\n   (delim\n    :delimlist\n     (delimlist\n      delimbracketangle))\n  :parent\n   (textblock\n    :text \"a<b>c\"\n    :delim\n     (delim\n      :delimlist\n       (delimlist\n        delimbracketangle))\n    :children\n     (textblocklist\n      (textblock\n       :text \"a\"\n       :startpos 0\n       :endpos 1)\n      (textblock\n       :text \"<b>\"\n       :startpos 1\n       :endpos 4\n       :delim delimbracketangle\n       :children\n        (textblocklist\n         (textblock\n          :text \"b\"\n          :startpos 2\n          :endpos 3))))))\n (textblock-pop<-textblock-delim\n  (textblock\n   :text \"<b>c\"\n   :startpos 1\n   :curpos 1\n   :delim\n    (copy delimbracketangle\n     :startpos 1)\n   :close\n    (copy delimclose\n     :starttext \">\")\n   :parent\n    (textblock\n     :text \"a<b>c\"\n     :delim\n      (delim\n       :delimlist\n        (delimlist\n         delimbracketangle))\n     :children\n      (textblocklist\n       (textblock\n        :text \"a\"\n        :endpos 1))))\n  (copy delimclose\n   :starttext \">\"\n   :startpos 2)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("textblock-pop<-textblock-delim"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_textblock_pop_from_textblock_delim");
    return output;
  }

  vx_test::Type_testcase f_textblock_push(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_textblock_push");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("b,c"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(2),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              vx_core::f_new(
                vx_data_textblock::t_delimlist,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimcomma,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      vx_core::f_new(
                        vx_data_textblock::t_delimlist,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_data_textblock::c_delimbracketangle
                        })
                      )
                    })
                  )
                })
              )
            })
          ),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("a,b,c"),
              vx_core::vx_new_string(":delim"),
              vx_core::f_new(
                vx_data_textblock::t_delim,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_core::f_new(
                    vx_data_textblock::t_delimlist,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimcomma,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":delimlist"),
                          vx_core::f_new(
                            vx_data_textblock::t_delimlist,
                            vx_core::vx_new(vx_core::t_anylist, {
                              vx_data_textblock::c_delimbracketangle
                            })
                          )
                        })
                      )
                    })
                  )
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
                      vx_core::vx_new_int(0),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(1)
                    })
                  ),
                  vx_core::f_new(
                    vx_data_textblock::t_textblock,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":text"),
                      vx_core::vx_new_string(","),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(2),
                      vx_core::vx_new_string(":delim"),
                      vx_data_textblock::c_delimcomma
                    })
                  )
                })
              )
            })
          )
        })
      ),
      vx_data_textblock::f_textblock_push(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string(",b,c"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(1),
            vx_core::vx_new_string(":curpos"),
            vx_core::vx_new_int(1),
            vx_core::vx_new_string(":delim"),
            vx_core::f_copy(
              vx_data_textblock::t_delim,
              vx_data_textblock::c_delimcomma,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_core::f_new(
                  vx_data_textblock::t_delimlist,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimcomma,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":delimlist"),
                        vx_core::f_new(
                          vx_data_textblock::t_delimlist,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_data_textblock::c_delimbracketangle
                          })
                        )
                      })
                    )
                  })
                )
              })
            ),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("a,b,c"),
                vx_core::vx_new_string(":delim"),
                vx_core::f_new(
                  vx_data_textblock::t_delim,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_core::f_new(
                      vx_data_textblock::t_delimlist,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_textblock::c_delimcomma,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":delimlist"),
                            vx_core::f_new(
                              vx_data_textblock::t_delimlist,
                              vx_core::vx_new(vx_core::t_anylist, {
                                vx_data_textblock::c_delimbracketangle
                              })
                            )
                          })
                        )
                      })
                    )
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
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(1)
                      })
                    )
                  })
                )
              })
            )
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"b,c\"\n  :startpos 2\n  :delim\n   (delim\n    :delimlist\n     (delimlist\n      (copy delimcomma\n       :delimlist\n        (delimlist\n         delimbracketangle))))\n  :parent\n   (textblock\n    :text \"a,b,c\"\n    :delim\n     (delim\n      :delimlist\n       (delimlist\n        (copy delimcomma\n         :delimlist\n          (delimlist\n           delimbracketangle))))\n    :children\n     (textblocklist\n      (textblock\n       :text \"a\"\n       :startpos 0\n       :endpos 1)\n      (textblock\n       :text \",\"\n       :startpos 1\n       :endpos 2\n       :delim delimcomma))))\n (textblock-push\n  (textblock\n   :text \",b,c\"\n   :startpos 1\n   :curpos 1\n   :delim\n    (copy delimcomma\n     :delimlist\n      (delimlist\n       (copy delimcomma\n        :delimlist\n         (delimlist\n          delimbracketangle))))\n   :parent\n    (textblock\n     :text \"a,b,c\"\n     :delim\n      (delim\n       :delimlist\n        (delimlist\n         (copy delimcomma\n          :delimlist\n           (delimlist\n            delimbracketangle))))\n     :children\n      (textblocklist\n       (textblock\n        :text \"a\"\n        :endpos 1))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("\"b\"\n1,\"2\""),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(4),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              vx_core::f_new(
                vx_data_textblock::t_delimlist,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_data_textblock::c_delimline,
                  vx_data_textblock::c_delimquote,
                  vx_data_textblock::c_delimcomma
                })
              )
            })
          ),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("\"a\",\"b\"\n1,\"2\""),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(13),
              vx_core::vx_new_string(":delim"),
              vx_core::f_new(
                vx_data_textblock::t_delim,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":name"),
                  vx_core::vx_new_string("delimcsv"),
                  vx_core::vx_new_string(":delimlist"),
                  vx_core::f_new(
                    vx_data_textblock::t_delimlist,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_data_textblock::c_delimline,
                      vx_data_textblock::c_delimquote,
                      vx_data_textblock::c_delimcomma
                    })
                  )
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
                      vx_core::vx_new_string("\"a\""),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(3),
                      vx_core::vx_new_string(":delim"),
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimquote,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(2)
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
                              vx_core::vx_new_int(1),
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
                      vx_core::vx_new_int(3),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(4),
                      vx_core::vx_new_string(":delim"),
                      vx_data_textblock::c_delimcomma
                    })
                  )
                })
              )
            })
          )
        })
      ),
      vx_data_textblock::f_textblock_push(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string(",\"b\"\n1,\"2\""),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(3),
            vx_core::vx_new_string(":curpos"),
            vx_core::vx_new_int(1),
            vx_core::vx_new_string(":delim"),
            vx_core::f_copy(
              vx_data_textblock::t_delim,
              vx_data_textblock::c_delimcomma,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_core::f_new(
                  vx_data_textblock::t_delimlist,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_data_textblock::c_delimline,
                    vx_data_textblock::c_delimquote,
                    vx_data_textblock::c_delimcomma
                  })
                )
              })
            ),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("\"a\",\"b\"\n1,\"2\""),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13),
                vx_core::vx_new_string(":delim"),
                vx_core::f_new(
                  vx_data_textblock::t_delim,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":name"),
                    vx_core::vx_new_string("delimcsv"),
                    vx_core::vx_new_string(":delimlist"),
                    vx_core::f_new(
                      vx_data_textblock::t_delimlist,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_data_textblock::c_delimline,
                        vx_data_textblock::c_delimquote,
                        vx_data_textblock::c_delimcomma
                      })
                    )
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
                        vx_core::vx_new_string("\"a\""),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(3),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_textblock::c_delimquote,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(2)
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
                                vx_core::vx_new_int(1),
                                vx_core::vx_new_string(":endpos"),
                                vx_core::vx_new_int(2)
                              })
                            )
                          })
                        )
                      })
                    )
                  })
                )
              })
            )
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text `\"b\"\n1,\"2\"`\n  :startpos 4\n  :delim\n   (delim\n    :delimlist\n     (delimlist\n      delimline\n      delimquote\n      delimcomma))\n  :parent\n   (textblock\n    :text `\"a\",\"b\"\n1,\"2\"`\n    :endpos 13\n    :delim\n     (delim\n      :name \"delimcsv\"\n      :delimlist\n       (delimlist\n        delimline\n        delimquote\n        delimcomma))\n  :children\n   (textblocklist\n    (textblock\n     :text `\"a\"`\n     :endpos 3\n     :delim\n      (copy delimquote\n       :endpos 2)\n     :children\n      (textblocklist\n       (textblock\n        :text \"a\"\n        :startpos 1\n        :endpos 2)))\n    (textblock\n     :text \",\"\n     :startpos 3\n     :endpos 4           \n     :delim\n      delimcomma\n       ))))\n (textblock-push\n  (textblock\n   :text `,\"b\"\n1,\"2\"`\n    :startpos 3\n    :curpos 1\n    :delim\n     (copy delimcomma\n      :delimlist\n       (delimlist\n        delimline\n        delimquote\n        delimcomma))\n    :parent\n     (textblock\n      :text `\"a\",\"b\"\n1,\"2\"`\n      :endpos 13\n      :delim\n       (delim\n        :name \"delimcsv\"\n        :delimlist\n         (delimlist\n          delimline\n          delimquote\n          delimcomma))\n      :children\n       (textblocklist\n        (textblock\n         :text \"\\\"a\\\"\"\n         :endpos 3\n         :delim\n          (copy delimquote\n           :endpos 2)\n         :children\n          (textblocklist\n           (textblock\n            :text \"a\"\n            :startpos 1\n            :endpos 2))))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("textblock-push"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_textblock_push");
    return output;
  }

  vx_test::Type_testcase f_textblock_push_from_textblock_delim(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_textblock_push_from_textblock_delim");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("a"),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              vx_core::f_new(
                vx_data_textblock::t_delimlist,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_data_textblock::c_delimbracketangle
                })
              )
            })
          ),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(1),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string(",b,c"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(1),
              vx_core::vx_new_string(":curpos"),
              vx_core::vx_new_int(1),
              vx_core::vx_new_string(":delim"),
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimcomma,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":delimlist"),
                  vx_core::f_new(
                    vx_data_textblock::t_delimlist,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimcomma,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":delimlist"),
                          vx_core::f_new(
                            vx_data_textblock::t_delimlist,
                            vx_core::vx_new(vx_core::t_anylist, {
                              vx_data_textblock::c_delimbracketangle
                            })
                          )
                        })
                      )
                    })
                  )
                })
              ),
              vx_core::vx_new_string(":parent"),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("a,b,c"),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_new(
                    vx_data_textblock::t_delim,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      vx_core::f_new(
                        vx_data_textblock::t_delimlist,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_textblock::c_delimcomma,
                            vx_core::vx_new(vx_core::t_anylist, {
                              vx_core::vx_new_string(":delimlist"),
                              vx_core::f_new(
                                vx_data_textblock::t_delimlist,
                                vx_core::vx_new(vx_core::t_anylist, {
                                  vx_data_textblock::c_delimbracketangle
                                })
                              )
                            })
                          )
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
      vx_data_textblock::f_textblock_push_from_textblock_delim(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("a,b,c"),
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_core::f_new(
                  vx_data_textblock::t_delimlist,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimcomma,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":delimlist"),
                        vx_core::f_new(
                          vx_data_textblock::t_delimlist,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_data_textblock::c_delimbracketangle
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
        vx_core::f_copy(
          vx_data_textblock::t_delim,
          vx_data_textblock::c_delimcomma,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(1),
            vx_core::vx_new_string(":delimlist"),
            vx_core::f_new(
              vx_data_textblock::t_delimlist,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_data_textblock::c_delimbracketangle
              })
            )
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"a\"\n  :delim\n   (delim\n    :delimlist\n     (delimlist\n      delimbracketangle))\n  :endpos 1\n  :parent\n   (textblock\n    :text \",b,c\"\n    :startpos 1\n    :curpos 1\n    :delim\n     (copy delimcomma\n      :startpos 1\n      :delimlist\n       (delimlist\n        (copy delimcomma\n         :delimlist\n          (delimlist\n           delimbracketangle))))\n    :parent\n     (textblock\n      :text \"a,b,c\"\n      :delim\n       (delim\n        :delimlist\n         (delimlist\n          (copy delimcomma\n           :delimlist\n            (delimlist\n             delimbracketangle)))))))\n (textblock-push<-textblock-delim\n  (textblock\n   :text \"a,b,c\"\n   :delim\n    (delim\n     :delimlist\n      (delimlist\n       (copy delimcomma\n        :delimlist\n         (delimlist\n          delimbracketangle)))))\n  (copy delimcomma\n   :startpos 1\n   :delimlist\n    (delimlist\n     delimbracketangle))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("b"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(2),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(3),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              vx_core::f_new(
                vx_data_textblock::t_delimlist,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_data_textblock::c_delimbracketangle
                })
              )
            })
          ),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string(",c"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(3),
              vx_core::vx_new_string(":curpos"),
              vx_core::vx_new_int(1),
              vx_core::vx_new_string(":delim"),
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimcomma,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":delimlist"),
                  vx_core::f_new(
                    vx_data_textblock::t_delimlist,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimcomma,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":delimlist"),
                          vx_core::f_new(
                            vx_data_textblock::t_delimlist,
                            vx_core::vx_new(vx_core::t_anylist, {
                              vx_data_textblock::c_delimbracketangle
                            })
                          )
                        })
                      )
                    })
                  )
                })
              ),
              vx_core::vx_new_string(":parent"),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("a,b,c"),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_new(
                    vx_data_textblock::t_delim,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      vx_core::f_new(
                        vx_data_textblock::t_delimlist,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_textblock::c_delimcomma,
                            vx_core::vx_new(vx_core::t_anylist, {
                              vx_core::vx_new_string(":delimlist"),
                              vx_core::f_new(
                                vx_data_textblock::t_delimlist,
                                vx_core::vx_new(vx_core::t_anylist, {
                                  vx_data_textblock::c_delimbracketangle
                                })
                              )
                            })
                          )
                        })
                      )
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
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(1)
                        })
                      ),
                      vx_core::f_new(
                        vx_data_textblock::t_textblock,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":text"),
                          vx_core::vx_new_string(","),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(1),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(2),
                          vx_core::vx_new_string(":delim"),
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_textblock::c_delimcomma,
                            vx_core::vx_new(vx_core::t_anylist, {
                              vx_core::vx_new_string(":startpos"),
                              vx_core::vx_new_int(1),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(2)
                            })
                          )
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
      vx_data_textblock::f_textblock_push_from_textblock_delim(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("b,c"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(2),
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_core::f_new(
                  vx_data_textblock::t_delimlist,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimcomma,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":delimlist"),
                        vx_core::f_new(
                          vx_data_textblock::t_delimlist,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::f_new(
                              vx_data_textblock::t_delim,
                              vx_core::vx_new(vx_core::t_anylist, {
                                vx_core::vx_new_string(":name"),
                                vx_core::vx_new_string("delimbracketangle"),
                                vx_core::vx_new_string(":starttext"),
                                vx_core::vx_new_string("<"),
                                vx_core::vx_new_string(":endtext"),
                                vx_core::vx_new_string(">")
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
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("a,b,c"),
                vx_core::vx_new_string(":delim"),
                vx_core::f_new(
                  vx_data_textblock::t_delim,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_core::f_new(
                      vx_data_textblock::t_delimlist,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_textblock::c_delimcomma,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":delimlist"),
                            vx_core::f_new(
                              vx_data_textblock::t_delimlist,
                              vx_core::vx_new(vx_core::t_anylist, {
                                vx_data_textblock::c_delimbracketangle
                              })
                            )
                          })
                        )
                      })
                    )
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
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(1)
                      })
                    ),
                    vx_core::f_new(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":text"),
                        vx_core::vx_new_string(","),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(1),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(2),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_textblock::c_delimcomma,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(1),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(2)
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
        vx_core::f_copy(
          vx_data_textblock::t_delim,
          vx_data_textblock::c_delimcomma,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(1),
            vx_core::vx_new_string(":delimlist"),
            vx_core::f_new(
              vx_data_textblock::t_delimlist,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_data_textblock::c_delimbracketangle
              })
            )
          })
        )
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"b\"\n  :startpos 2\n  :endpos 3\n  :delim\n   (delim\n    :delimlist\n     (delimlist\n      delimbracketangle))\n  :parent\n   (textblock\n    :text \",c\"\n    :startpos 3\n    :curpos 1\n    :delim\n     (copy delimcomma\n      :startpos 1\n      :delimlist\n       (delimlist\n        (copy delimcomma\n         :delimlist\n          (delimlist\n           delimbracketangle))))\n    :parent\n     (textblock\n      :text \"a,b,c\"\n      :delim\n       (delim\n        :delimlist\n         (delimlist\n          (copy delimcomma\n           :delimlist\n            (delimlist\n             delimbracketangle))))\n      :children\n       (textblocklist\n        (textblock\n         :text \"a\"\n         :endpos 1)\n        (textblock\n         :text \",\"\n         :startpos 1\n         :endpos 2\n         :delim\n          (copy delimcomma\n           :startpos 1\n           :endpos 2))))))\n (textblock-push<-textblock-delim\n  (textblock\n   :text \"b,c\"\n   :startpos 2\n   :delim\n    (delim\n     :delimlist\n      (delimlist\n       (copy delimcomma\n        :delimlist\n         (delimlist\n          (delim\n           :name \"delimbracketangle\"\n           :starttext \"<\"\n           :endtext \">\")))))\n   :parent\n    (textblock\n     :text \"a,b,c\"\n     :delim\n      (delim\n       :delimlist\n        (delimlist\n         (copy delimcomma\n          :delimlist\n           (delimlist\n            delimbracketangle))))\n     :children\n      (textblocklist\n       (textblock\n        :text \"a\"\n        :endpos 1)\n       (textblock\n        :text \",\"\n        :startpos 1\n        :endpos 2\n        :delim\n         (copy delimcomma\n          :startpos 1\n          :endpos 2)))))\n  (copy delimcomma\n   :startpos 1\n   :delimlist\n    (delimlist\n     delimbracketangle))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("textblock-push<-textblock-delim"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_textblock_push_from_textblock_delim");
    return output;
  }

  vx_test::Type_testcase f_textblock_startleft_from_string_delim_offset(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_textblock_startleft_from_string_delim_offset");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("a"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(0),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(1)
        })
      ),
      vx_data_textblock::f_textblock_startleft_from_string_delim_offset(
        vx_core::vx_new_string("a,b"),
        vx_core::f_new(
          vx_data_textblock::t_delim,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(1)
          })
        ),
        vx_core::vx_new_int(0)
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"a\"\n  :startpos 0\n  :endpos 1)\n (textblock-startleft<-string-delim-offset\n  \"a,b\"\n  (delim\n   :startpos 1)\n  0))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("textblock-startleft<-string-delim-offset"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_textblock_startleft_from_string_delim_offset");
    return output;
  }

  vx_test::Type_testcase f_textblock_startright_from_string_delim_offset(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_textblock_startright_from_string_delim_offset");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string(",b"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(1),
          vx_core::vx_new_string(":curpos"),
          vx_core::vx_new_int(1),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":starttext"),
              vx_core::vx_new_string(","),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(1)
            })
          )
        })
      ),
      vx_data_textblock::f_textblock_startright_from_string_delim_offset(
        vx_core::vx_new_string("a,b"),
        vx_core::f_new(
          vx_data_textblock::t_delim,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":starttext"),
            vx_core::vx_new_string(","),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(1)
          })
        ),
        vx_core::vx_new_int(0)
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \",b\"\n  :startpos 1\n  :curpos 1\n  :delim\n   (delim\n    :starttext \",\"\n    :startpos  1))\n (textblock-startright<-string-delim-offset\n  \"a,b\"\n  (delim\n   :starttext \",\"\n   :startpos  1)\n  0))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("<b>c"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(1),
          vx_core::vx_new_string(":curpos"),
          vx_core::vx_new_int(1),
          vx_core::vx_new_string(":delim"),
          vx_core::f_copy(
            vx_data_textblock::t_delim,
            vx_data_textblock::c_delimbracketangle,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(1),
              vx_core::vx_new_string(":delimlist"),
              vx_core::f_new(
                vx_data_textblock::t_delimlist,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_data_textblock::c_delimbracketcurly
                })
              )
            })
          ),
          vx_core::vx_new_string(":close"),
          vx_core::f_copy(
            vx_data_textblock::t_delim,
            vx_data_textblock::c_delimclose,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":starttext"),
              vx_core::vx_new_string(">")
            })
          )
        })
      ),
      vx_data_textblock::f_textblock_startright_from_string_delim_offset(
        vx_core::vx_new_string("a<b>c"),
        vx_core::f_copy(
          vx_data_textblock::t_delim,
          vx_data_textblock::c_delimbracketangle,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(1),
            vx_core::vx_new_string(":delimlist"),
            vx_core::f_new(
              vx_data_textblock::t_delimlist,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_data_textblock::c_delimbracketcurly
              })
            )
          })
        ),
        vx_core::vx_new_int(0)
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"<b>c\"\n  :startpos 1\n  :curpos 1\n  :delim\n   (copy delimbracketangle\n    :startpos 1\n    :delimlist\n     (delimlist\n      delimbracketcurly))\n  :close\n   (copy delimclose\n    :starttext \">\"))\n (textblock-startright<-string-delim-offset\n  \"a<b>c\"\n  (copy delimbracketangle\n   :startpos 1\n   :delimlist\n    (delimlist\n     delimbracketcurly))\n  0))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("textblock-startright<-string-delim-offset"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_textblock_startright_from_string_delim_offset");
    return output;
  }

  vx_test::Type_testcase f_textblock_from_string_delim(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_textblock_from_string_delim");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("a"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(0),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(1),
          vx_core::vx_new_string(":delim"),
          vx_data_textblock::c_delimcomma
        })
      ),
      vx_data_textblock::f_textblock_from_string_delim(
        vx_core::vx_new_string("a"),
        vx_data_textblock::c_delimcomma
      ),
      context
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"a\"\n  :startpos 0\n  :endpos 1\n  :delim delimcomma)\n (textblock<-string-delim\n  \"a\"\n  delimcomma))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("textblock<-string-delim"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_textblock_from_string_delim");
    return output;
  }

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {
    vx_core::vx_Type_listany listtestcase;
    listtestcase.push_back(vx_data_textblock_test::t_delimlist(context));
    listtestcase.push_back(vx_data_textblock_test::f_delim_close_from_delim(context));
    listtestcase.push_back(vx_data_textblock_test::f_delim_first_from_delim_delim(context));
    listtestcase.push_back(vx_data_textblock_test::f_delim_first_from_string_delimlist_offset(context));
    listtestcase.push_back(vx_data_textblock_test::f_delim_pos_from_string_delim_offset(context));
    listtestcase.push_back(vx_data_textblock_test::f_delimlist_pos_from_string_delimlist_offset(context));
    listtestcase.push_back(vx_data_textblock_test::f_stringlist_from_textblocklist(context));
    listtestcase.push_back(vx_data_textblock_test::f_text_from_textblock(context));
    listtestcase.push_back(vx_data_textblock_test::f_textblock_parse(context));
    listtestcase.push_back(vx_data_textblock_test::f_textblock_parse_one(context));
    listtestcase.push_back(vx_data_textblock_test::f_textblock_pop(context));
    listtestcase.push_back(vx_data_textblock_test::f_textblock_pop_from_textblock_delim(context));
    listtestcase.push_back(vx_data_textblock_test::f_textblock_push(context));
    listtestcase.push_back(vx_data_textblock_test::f_textblock_push_from_textblock_delim(context));
    listtestcase.push_back(vx_data_textblock_test::f_textblock_startleft_from_string_delim_offset(context));
    listtestcase.push_back(vx_data_textblock_test::f_textblock_startright_from_string_delim_offset(context));
    listtestcase.push_back(vx_data_textblock_test::f_textblock_from_string_delim(context));
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
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(42), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(42)
      }),
      vx_core::vx_new_string(":funcnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(69), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(16), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(23)
      }),
      vx_core::vx_new_string(":bigospacenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(4), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(1), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(23)
      }),
      vx_core::vx_new_string(":bigotimenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(4), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(1), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(23)
      }),
      vx_core::vx_new_string(":totalnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(40), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(17), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(42)
      }),
      vx_core::vx_new_string(":typenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(25), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(1), 
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
        vx_core::vx_new_string(":delimlist"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":textblock"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":textblocklist"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":constmap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":delimbracketangle"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimbracketcurly"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimbracketsquare"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimclose"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimcomma"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimcomment"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimcommentblock"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimline"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimnonwhitespace"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimparen"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimquote"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimquoteblock"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimspace"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimtext"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimwhitespace"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":funcmap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":children<-textblock"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delim-close<-delim"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":delim-first<-delim-delim"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":delim-first<-string-delimlist-offset"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":delim-pos<-string-delim-offset"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":delimlist-pos<-string-delimlist-offset"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":stringlist<-textblocklist"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":text<-textblock"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":textblock-addchild<-textblock-find-child"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":textblock-delimnotfound"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":textblock-findparent<-textblock"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":textblock-groupby<-textblock-delim"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":textblock-parse"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":textblock-parse-one"), vx_core::vx_new_int(9),
        vx_core::vx_new_string(":textblock-parse<-string-delim"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":textblock-pop"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":textblock-pop<-textblock-delim"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":textblock-push"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":textblock-push<-textblock-delim"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":textblock-startleft<-string-delim-offset"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":textblock-startright<-string-delim-offset"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":textblock<-string-delim"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":textblock<-textblock-delim"), vx_core::vx_new_int(0)
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
