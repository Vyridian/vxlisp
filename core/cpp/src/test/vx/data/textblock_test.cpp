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
      context,
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
      )
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

  vx_test::Type_testcase f_delim_first_from_delim_delim(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_delim_first_from_delim_delim");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_copy(
        vx_data_textblock::t_delim,
        vx_data_textblock::c_delimcomma,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":pos"),
          vx_core::vx_new_int(1)
        })
      ),
      vx_data_textblock::f_delim_first_from_delim_delim(
        vx_core::f_copy(
          vx_data_textblock::t_delim,
          vx_data_textblock::c_delimspace,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":pos"),
            vx_core::vx_new_int(2)
          })
        ),
        vx_core::f_copy(
          vx_data_textblock::t_delim,
          vx_data_textblock::c_delimcomma,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":pos"),
            vx_core::vx_new_int(1)
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (copy delimcomma\n  :pos 1)\n (delim-first<-delim-delim\n  (copy delimspace\n   :pos 2)\n  (copy delimcomma\n   :pos 1)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::f_empty(
        vx_data_textblock::t_delim
      ),
      vx_data_textblock::f_delim_first_from_delim_delim(
        vx_core::f_new(
          vx_data_textblock::t_delim,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":pos"),
            vx_core::vx_new_int(0)
          })
        ),
        vx_core::f_empty(
          vx_data_textblock::t_delim
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (empty delim)\n (delim-first<-delim-delim\n  (delim\n   :pos 0)\n  (empty delim)))"),
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

  vx_test::Type_testcase f_delim_first_from_string_delimlist(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_delim_first_from_string_delimlist");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_copy(
        vx_data_textblock::t_delim,
        vx_data_textblock::c_delimcomma,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":pos"),
          vx_core::vx_new_int(2)
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
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (copy delimcomma\n  :pos 2)\n (delim-first<-string-delimlist\n  \"a, b\"\n  (delimlist\n   delimspace\n   delimcomma)))"),
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

  vx_test::Type_testcase f_delim_pos_from_string_delim(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_delim_pos_from_string_delim");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_copy(
        vx_data_textblock::t_delim,
        vx_data_textblock::c_delimcomma,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":pos"),
          vx_core::vx_new_int(2)
        })
      ),
      vx_data_textblock::f_delim_pos_from_string_delim(
        vx_core::vx_new_string("a,b"),
        vx_data_textblock::c_delimcomma
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (copy delimcomma\n  :pos 2)\n (delim-pos<-string-delim\n  \"a,b\"\n  delimcomma))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("delim-pos<-string-delim"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_delim_pos_from_string_delim");
    return output;
  }

  vx_test::Type_testcase f_delimlist_pos_from_string_delimlist(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_delimlist_pos_from_string_delimlist");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_delimlist,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::f_copy(
            vx_data_textblock::t_delim,
            vx_data_textblock::c_delimspace,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":pos"),
              vx_core::vx_new_int(3)
            })
          ),
          vx_core::f_copy(
            vx_data_textblock::t_delim,
            vx_data_textblock::c_delimcomma,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":pos"),
              vx_core::vx_new_int(2)
            })
          )
        })
      ),
      vx_data_textblock::f_delimlist_pos_from_string_delimlist(
        vx_core::vx_new_string("a, b"),
        vx_core::f_new(
          vx_data_textblock::t_delimlist,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_data_textblock::c_delimspace,
            vx_data_textblock::c_delimcomma
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (delimlist\n  (copy delimspace\n   :pos 3)\n  (copy delimcomma\n   :pos 2))\n (delimlist-pos<-string-delimlist\n  \"a, b\"\n  (delimlist\n   delimspace\n   delimcomma)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("delimlist-pos<-string-delimlist"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_delimlist_pos_from_string_delimlist");
    return output;
  }

  vx_test::Type_testcase f_stringlist_from_textblocklist(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_stringlist_from_textblocklist");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
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
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (stringlist\n  \"a\" \"b\")\n (stringlist<-textblocklist\n  (textblocklist\n   (textblock\n    :text \"a\")\n   (textblock\n    :text \"b\"))))"),
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
      context,
      vx_core::vx_new_string("a"),
      vx_data_textblock::f_text_from_textblock(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("a")
          })
        )
      )
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

  vx_test::Type_testcase f_textblock_delimnotfound(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_textblock_delimnotfound");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
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
          ),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("b},{c d}>"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(5),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(13),
              vx_core::vx_new_string(":delim"),
              vx_core::f_new(
                vx_data_textblock::t_delim,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_data_textblock::c_delimlisttest3
                })
              ),
              vx_core::vx_new_string(":close"),
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimclose,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":starttext"),
                  vx_core::vx_new_string("}")
                })
              ),
              vx_core::vx_new_string(":parent"),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("{a,b},{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(2),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimbracketcurly,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":pos"),
                      vx_core::vx_new_int(0)
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
                      vx_core::vx_new_string("<{a,b},{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13),
                      vx_core::vx_new_string(":delim"),
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimbracketangle,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":pos"),
                          vx_core::vx_new_int(0)
                        })
                      ),
                      vx_core::vx_new_string(":parent"),
                      vx_core::f_new(
                        vx_data_textblock::t_textblock,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":text"),
                          vx_core::vx_new_string("<{a,b},{c d}>"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(1),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(13)
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
                          vx_core::vx_new_int(3),
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
      ),
      vx_data_textblock::f_textblock_delimnotfound(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("a"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(3),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(3),
            vx_core::vx_new_string(":parent"),
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
                ),
                vx_core::vx_new_string(":parent"),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("b},{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(5),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_new(
                      vx_data_textblock::t_delim,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":delimlist"),
                        vx_data_textblock::c_delimlisttest3
                      })
                    ),
                    vx_core::vx_new_string(":close"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimclose,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":starttext"),
                        vx_core::vx_new_string("}")
                      })
                    ),
                    vx_core::vx_new_string(":parent"),
                    vx_core::f_new(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":text"),
                        vx_core::vx_new_string("{a,b},{c d}>"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(2),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(13),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_textblock::c_delimbracketcurly,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":pos"),
                            vx_core::vx_new_int(0)
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
                            vx_core::vx_new_string("<{a,b},{c d}>"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(1),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(13),
                            vx_core::vx_new_string(":delim"),
                            vx_core::f_copy(
                              vx_data_textblock::t_delim,
                              vx_data_textblock::c_delimbracketangle,
                              vx_core::vx_new(vx_core::t_anylist, {
                                vx_core::vx_new_string(":pos"),
                                vx_core::vx_new_int(0)
                              })
                            ),
                            vx_core::vx_new_string(":parent"),
                            vx_core::f_new(
                              vx_data_textblock::t_textblock,
                              vx_core::vx_new(vx_core::t_anylist, {
                                vx_core::vx_new_string(":text"),
                                vx_core::vx_new_string("<{a,b},{c d}>"),
                                vx_core::vx_new_string(":startpos"),
                                vx_core::vx_new_int(1),
                                vx_core::vx_new_string(":endpos"),
                                vx_core::vx_new_int(13)
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
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \",\"\n  :startpos 4\n  :endpos 4\n  :delim\n   (copy delimcomma\n    :pos 0)\n  :parent\n   (textblock\n    :text \"b},{c d}>\"\n    :startpos 5\n    :endpos 13\n    :delim\n     (delim\n      :delimlist delimlisttest3)\n    :close\n     (copy delimclose\n      :starttext \"}\")\n    :parent\n     (textblock\n      :text \"{a,b},{c d}>\"\n      :startpos 2\n      :endpos 13\n      :delim\n       (copy delimbracketcurly\n        :pos 0)\n      :close\n       (copy delimclose\n        :starttext \">\")\n      :parent\n       (textblock\n        :text \"<{a,b},{c d}>\"\n        :startpos 1\n        :endpos 13\n        :delim\n         (copy delimbracketangle\n          :pos 0)\n        :parent\n         (textblock\n          :text \"<{a,b},{c d}>\"\n          :startpos 1\n          :endpos 13))\n      :children\n       (textblocklist\n        (textblock\n         :text \"a\"\n         :startpos 3\n         :endpos 3)))))\n (textblock-delimnotfound\n  (textblock\n   :text \"a\"\n   :startpos 3\n   :endpos 3\n   :parent\n    (textblock\n     :text \",\"\n     :startpos 4\n     :endpos 4\n     :delim\n      (copy delimcomma\n       :pos 0)\n     :parent\n      (textblock\n       :text \"b},{c d}>\"\n       :startpos 5\n       :endpos 13\n       :delim\n        (delim\n         :delimlist delimlisttest3)\n       :close\n        (copy delimclose\n         :starttext \"}\")\n       :parent\n        (textblock\n         :text \"{a,b},{c d}>\"\n         :startpos 2\n         :endpos 13\n         :delim\n          (copy delimbracketcurly\n           :pos 0)\n         :close\n          (copy delimclose\n           :starttext \">\")\n         :parent\n          (textblock\n           :text \"<{a,b},{c d}>\"\n           :startpos 1\n           :endpos 13\n           :delim\n            (copy delimbracketangle\n             :pos 0)\n           :parent\n            (textblock\n             :text \"<{a,b},{c d}>\"\n             :startpos 1\n             :endpos 13))))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string(",{c d}>"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(7),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(13),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              vx_data_textblock::c_delimlisttest3
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
              vx_core::vx_new_string("<{a,b},{c d}>"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(1),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(13),
              vx_core::vx_new_string(":delim"),
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimbracketangle,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":pos"),
                  vx_core::vx_new_int(0)
                })
              ),
              vx_core::vx_new_string(":parent"),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("<{a,b},{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13)
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
                      vx_core::vx_new_string("{a,b}"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(2),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(6),
                      vx_core::vx_new_string(":delim"),
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimbracketcurly,
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
                              vx_core::vx_new_int(3),
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
                              vx_core::vx_new_string("b"),
                              vx_core::vx_new_string(":startpos"),
                              vx_core::vx_new_int(5),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(5)
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
      vx_data_textblock::f_textblock_delimnotfound(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("b"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(5),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(5),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string(",{c d}>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(7),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13),
                vx_core::vx_new_string(":delim"),
                vx_core::f_new(
                  vx_data_textblock::t_delim,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_data_textblock::c_delimlisttest3
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
                    vx_core::vx_new_string("{a,b}"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(2),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(6),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimbracketcurly,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":pos"),
                        vx_core::vx_new_int(0)
                      })
                    ),
                    vx_core::vx_new_string(":close"),
                    vx_data_textblock::c_delimclosing,
                    vx_core::vx_new_string(":parent"),
                    vx_core::f_new(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":text"),
                        vx_core::vx_new_string("<{a,b},{c d}>"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(1),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(13),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_textblock::c_delimbracketangle,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":pos"),
                            vx_core::vx_new_int(0)
                          })
                        ),
                        vx_core::vx_new_string(":parent"),
                        vx_core::f_new(
                          vx_data_textblock::t_textblock,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string("<{a,b},{c d}>"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(1),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(13)
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
                            vx_core::vx_new_int(3),
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
                        )
                      })
                    )
                  })
                )
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \",{c d}>\"\n  :startpos 7\n  :endpos 13\n  :delim\n   (delim\n    :delimlist delimlisttest3)\n  :close\n   (copy delimclose\n    :starttext \">\")\n  :parent\n   (textblock\n    :text \"<{a,b},{c d}>\"\n    :startpos 1\n    :endpos 13\n    :delim\n     (copy delimbracketangle\n      :pos 0)\n    :parent\n     (textblock\n      :text \"<{a,b},{c d}>\"\n      :startpos 1\n      :endpos 13)\n    :children\n     (textblocklist\n      (textblock\n       :text \"{a,b}\"\n       :startpos 2\n       :endpos 6\n       :delim\n        (copy delimbracketcurly\n         :pos 0)\n       :children\n        (textblocklist\n         (textblock\n          :text \"a\"\n          :startpos 3\n          :endpos 3)\n         (textblock\n          :text \",\"\n          :startpos 4\n          :endpos 4\n          :delim\n           (copy delimcomma\n            :pos 0))\n         (textblock\n          :text \"b\"\n          :startpos 5\n          :endpos 5))))))\n (textblock-delimnotfound\n  (textblock\n   :text \"b\"\n   :startpos 5\n   :endpos 5\n   :parent\n    (textblock\n     :text \",{c d}>\"\n     :startpos 7\n     :endpos 13\n     :delim\n      (delim\n       :delimlist delimlisttest3)\n     :close\n      (copy delimclose\n       :starttext \">\")\n     :parent\n      (textblock\n       :text \"{a,b}\"\n       :startpos 2\n       :endpos 6\n       :delim\n        (copy delimbracketcurly\n         :pos 0)\n       :close delimclosing\n       :parent\n        (textblock\n         :text \"<{a,b},{c d}>\"\n         :startpos 1\n         :endpos 13\n         :delim\n          (copy delimbracketangle\n           :pos 0)\n         :parent\n          (textblock\n           :text \"<{a,b},{c d}>\"\n           :startpos 1\n           :endpos 13))\n       :children\n        (textblocklist\n         (textblock\n          :text \"a\"\n          :startpos 3\n          :endpos 3)\n         (textblock\n          :text \",\"\n          :startpos 4\n          :endpos 4\n          :delim\n           (copy delimcomma\n            :pos 0))))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    // testdescribe_3
    vx_test::Type_testresult testresult_3 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(14),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(14),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              vx_data_textblock::c_delimlisttest1
            })
          ),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("<{a,b},{c d}>"),
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
                      vx_core::vx_new_string("<{a,b},{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13),
                      vx_core::vx_new_string(":delim"),
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimbracketangle,
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
                              vx_core::vx_new_string("{a,b}"),
                              vx_core::vx_new_string(":startpos"),
                              vx_core::vx_new_int(2),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(6),
                              vx_core::vx_new_string(":delim"),
                              vx_core::f_copy(
                                vx_data_textblock::t_delim,
                                vx_data_textblock::c_delimbracketcurly,
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
                                      vx_core::vx_new_int(3),
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
                                      vx_core::vx_new_string("b"),
                                      vx_core::vx_new_string(":startpos"),
                                      vx_core::vx_new_int(5),
                                      vx_core::vx_new_string(":endpos"),
                                      vx_core::vx_new_int(5)
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
                              vx_core::vx_new_int(7),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(7),
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
                              vx_core::vx_new_string("{c d}"),
                              vx_core::vx_new_string(":startpos"),
                              vx_core::vx_new_int(8),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(12),
                              vx_core::vx_new_string(":delim"),
                              vx_core::f_copy(
                                vx_data_textblock::t_delim,
                                vx_data_textblock::c_delimbracketcurly,
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
                                      vx_core::vx_new_string("c"),
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
                                      vx_core::vx_new_string(" "),
                                      vx_core::vx_new_string(":startpos"),
                                      vx_core::vx_new_int(10),
                                      vx_core::vx_new_string(":endpos"),
                                      vx_core::vx_new_int(10),
                                      vx_core::vx_new_string(":delim"),
                                      vx_core::f_copy(
                                        vx_data_textblock::t_delim,
                                        vx_data_textblock::c_delimwhitespace,
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
                                      vx_core::vx_new_string("d"),
                                      vx_core::vx_new_string(":startpos"),
                                      vx_core::vx_new_int(11),
                                      vx_core::vx_new_string(":endpos"),
                                      vx_core::vx_new_int(11)
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
          )
        })
      ),
      vx_data_textblock::f_textblock_delimnotfound(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(13),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(13),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(14),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(14),
                vx_core::vx_new_string(":delim"),
                vx_core::f_new(
                  vx_data_textblock::t_delim,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_data_textblock::c_delimlisttest1
                  })
                ),
                vx_core::vx_new_string(":parent"),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("<{a,b},{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(1),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimbracketangle,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":pos"),
                        vx_core::vx_new_int(0)
                      })
                    ),
                    vx_core::vx_new_string(":close"),
                    vx_data_textblock::c_delimclosing,
                    vx_core::vx_new_string(":parent"),
                    vx_core::f_new(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":text"),
                        vx_core::vx_new_string("<{a,b},{c d}>"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(1),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(13)
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
                            vx_core::vx_new_string("{a,b}"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(2),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(6),
                            vx_core::vx_new_string(":delim"),
                            vx_core::f_copy(
                              vx_data_textblock::t_delim,
                              vx_data_textblock::c_delimbracketcurly,
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
                                    vx_core::vx_new_int(3),
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
                                    vx_core::vx_new_string("b"),
                                    vx_core::vx_new_string(":startpos"),
                                    vx_core::vx_new_int(5),
                                    vx_core::vx_new_string(":endpos"),
                                    vx_core::vx_new_int(5)
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
                            vx_core::vx_new_int(7),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(7),
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
                            vx_core::vx_new_string("{c d}"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(8),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(12),
                            vx_core::vx_new_string(":delim"),
                            vx_core::f_copy(
                              vx_data_textblock::t_delim,
                              vx_data_textblock::c_delimbracketcurly,
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
                                    vx_core::vx_new_string("c"),
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
                                    vx_core::vx_new_string(" "),
                                    vx_core::vx_new_string(":startpos"),
                                    vx_core::vx_new_int(10),
                                    vx_core::vx_new_string(":endpos"),
                                    vx_core::vx_new_int(10),
                                    vx_core::vx_new_string(":delim"),
                                    vx_core::f_copy(
                                      vx_data_textblock::t_delim,
                                      vx_data_textblock::c_delimwhitespace,
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
                                    vx_core::vx_new_string("d"),
                                    vx_core::vx_new_string(":startpos"),
                                    vx_core::vx_new_int(11),
                                    vx_core::vx_new_string(":endpos"),
                                    vx_core::vx_new_int(11)
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
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_3 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :startpos 14\n  :endpos 14\n  :delim\n   (delim\n    :delimlist delimlisttest1)\n  :parent\n   (textblock\n    :text \"<{a,b},{c d}>\"\n    :startpos 1\n    :endpos 13\n    :children\n     (textblocklist\n      (textblock\n       :text \"<{a,b},{c d}>\"\n       :startpos 1\n       :endpos 13\n       :delim\n        (copy delimbracketangle\n         :pos 0)\n       :children\n        (textblocklist\n         (textblock\n          :text \"{a,b}\"\n          :startpos 2\n          :endpos 6\n          :delim\n           (copy delimbracketcurly\n            :pos 0)\n          :children\n           (textblocklist\n            (textblock\n             :text \"a\"\n             :startpos 3\n             :endpos 3)\n            (textblock\n             :text \",\"\n             :startpos 4\n             :endpos 4\n             :delim\n              (copy delimcomma\n               :pos 0))\n            (textblock\n             :text \"b\"\n             :startpos 5\n             :endpos 5)))\n         (textblock\n          :text \",\"\n          :startpos 7\n          :endpos 7\n          :delim\n           (copy delimcomma\n            :pos 0))\n         (textblock\n          :text \"{c d}\"\n          :startpos 8\n          :endpos 12\n          :delim\n           (copy delimbracketcurly\n            :pos 0)\n          :children\n           (textblocklist\n            (textblock\n             :text \"c\"\n             :startpos 9\n             :endpos 9)\n           (textblock\n            :text \" \"\n            :startpos 10\n            :endpos 10\n            :delim\n             (copy delimwhitespace\n              :pos 0))\n           (textblock\n            :text \"d\"\n            :startpos 11\n            :endpos 11))))))))\n (textblock-delimnotfound\n  (textblock\n   :startpos 13\n   :endpos 13\n   :parent\n    (textblock\n     :startpos 14\n     :endpos 14\n     :delim\n      (delim\n       :delimlist delimlisttest1)\n     :parent\n      (textblock\n       :text \"<{a,b},{c d}>\"\n       :startpos 1\n       :endpos 13\n       :delim\n        (copy delimbracketangle\n         :pos 0)\n       :close delimclosing\n       :parent\n        (textblock\n         :text \"<{a,b},{c d}>\"\n         :startpos 1\n         :endpos 13)\n       :children\n        (textblocklist\n         (textblock\n          :text \"{a,b}\"\n          :startpos 2\n          :endpos 6\n          :delim\n           (copy delimbracketcurly\n            :pos 0)\n          :children\n           (textblocklist\n            (textblock\n             :text \"a\"\n             :startpos 3\n             :endpos 3)\n            (textblock\n             :text \",\"\n             :startpos 4\n             :endpos 4\n             :delim\n              (copy delimcomma\n               :pos 0))\n            (textblock\n             :text \"b\"\n             :startpos 5\n             :endpos 5)))\n         (textblock\n          :text \",\"\n          :startpos 7\n          :endpos 7\n          :delim\n           (copy delimcomma\n            :pos 0))\n         (textblock\n          :text \"{c d}\"\n          :startpos 8\n          :endpos 12\n          :delim\n           (copy delimbracketcurly\n            :pos 0)\n          :children\n           (textblocklist\n            (textblock\n             :text \"c\"\n             :startpos 9\n             :endpos 9)\n           (textblock\n            :text \" \"\n            :startpos 10\n            :endpos 10\n            :delim\n             (copy delimwhitespace\n              :pos 0))\n           (textblock\n            :text \"d\"\n            :startpos 11\n            :endpos 11)))))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_3
    });
    // testdescribe_4
    vx_test::Type_testresult testresult_4 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("\"b\"\n1,\"2\""),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(5),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(13),
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
                      vx_core::f_new(
                        vx_data_textblock::t_delim,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":name"),
                          vx_core::vx_new_string("delimquote"),
                          vx_core::vx_new_string(":starttext"),
                          vx_core::vx_new_string("\""),
                          vx_core::vx_new_string(":endtext"),
                          vx_core::vx_new_string("\"")
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
              )
            })
          )
        })
      ),
      vx_data_textblock::f_textblock_delimnotfound(
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
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":name"),
                vx_core::vx_new_string("delimcomma"),
                vx_core::vx_new_string(":starttext"),
                vx_core::vx_new_string(",")
              })
            ),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("\"b\"\n1,\"2\""),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(5),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13),
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
                            vx_core::f_new(
                              vx_data_textblock::t_delim,
                              vx_core::vx_new(vx_core::t_anylist, {
                                vx_core::vx_new_string(":name"),
                                vx_core::vx_new_string("delimquote"),
                                vx_core::vx_new_string(":starttext"),
                                vx_core::vx_new_string("\""),
                                vx_core::vx_new_string(":endtext"),
                                vx_core::vx_new_string("\"")
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
                        )
                      })
                    )
                  })
                )
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_4 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text\n   \"\\\"b\\\"\n1,\\\"2\\\"\"\n  :startpos 5\n  :endpos 13\n  :delim\n   (delim\n    :delimlist\n     (delimlist\n      vx/data/textblock/delimline\n      vx/data/textblock/delimquote\n      vx/data/textblock/delimcomma))\n  :parent\n   (textblock\n    :text\n     \"\\\"a\\\",\\\"b\\\"\n1,\\\"2\\\"\"\n    :startpos 1\n    :endpos 13\n    :children\n     (textblocklist\n      (textblock\n       :text \"\\\"a\\\"\"\n       :startpos 1\n       :endpos 3\n       :delim\n        (delim\n         :name \"delimquote\"\n         :starttext \"\\\"\"\n         :endtext \"\\\"\")\n       :children\n        (textblocklist\n         (textblock\n          :text \"a\"\n          :startpos 2\n          :endpos 2)))\n      (textblock\n       :text \",\"\n       :startpos 4\n       :endpos 4\n       :delim\n        (delim\n         :name \"delimcomma\"\n         :starttext \",\")))))\n(textblock-delimnotfound\n (textblock\n  :text \",\"\n  :startpos 4\n  :endpos 4\n  :delim\n   (delim\n    :name \"delimcomma\"\n    :starttext \",\")\n  :parent\n   (textblock\n    :text\n     \"\\\"b\\\"\n1,\\\"2\\\"\"\n    :startpos 5\n    :endpos 13\n    :delim\n     (delim\n      :delimlist\n       (delimlist\n        vx/data/textblock/delimline\n        vx/data/textblock/delimquote\n        vx/data/textblock/delimcomma))\n    :parent\n     (textblock\n      :text\n       \"\\\"a\\\",\\\"b\\\"\n1,\\\"2\\\"\"\n      :startpos 1\n      :endpos 13\n      :children\n       (textblocklist\n        (textblock\n         :text \"\\\"a\\\"\"\n         :startpos 1\n         :endpos 3\n         :delim\n          (delim\n           :name \"delimquote\"\n           :starttext \"\\\"\"\n           :endtext \"\\\"\")\n         :children\n          (textblocklist\n           (textblock\n            :text \"a\"\n            :startpos 2\n            :endpos 2)))))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_4
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2,
      testdescribe_3,
      testdescribe_4
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("textblock-delimnotfound"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_textblock_delimnotfound");
    return output;
  }

  vx_test::Type_testcase f_textblock_init(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_textblock_init");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("<{a,b},{c d}>"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(1),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(13),
          vx_core::vx_new_string(":delim"),
          vx_data_textblock::c_delimtest1,
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("<{a,b},{c d}>"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(1),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(13)
            })
          )
        })
      ),
      vx_data_textblock::f_textblock_init(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("<{a,b},{c d}>"),
            vx_core::vx_new_string(":delim"),
            vx_data_textblock::c_delimtest1
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"<{a,b},{c d}>\"\n  :startpos 1\n  :endpos 13\n  :delim delimtest1\n  :parent\n   (textblock\n    :text \"<{a,b},{c d}>\"\n    :startpos 1\n    :endpos 13))\n (textblock-init\n  (textblock\n   :text \"<{a,b},{c d}>\"\n   :delim delimtest1)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("textblock-init"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_textblock_init");
    return output;
  }

  vx_test::Type_testcase f_textblock_parse(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_textblock_parse");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("<{a,b},{c d}>"),
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
                  vx_core::vx_new_string("<{a,b},{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimbracketangle,
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
                          vx_core::vx_new_string("{a,b}"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(2),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(6),
                          vx_core::vx_new_string(":delim"),
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_textblock::c_delimbracketcurly,
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
                                  vx_core::vx_new_int(3),
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
                                  vx_core::vx_new_string("b"),
                                  vx_core::vx_new_string(":startpos"),
                                  vx_core::vx_new_int(5),
                                  vx_core::vx_new_string(":endpos"),
                                  vx_core::vx_new_int(5)
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
                          vx_core::vx_new_int(7),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(7),
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
                          vx_core::vx_new_string("{c d}"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(8),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(12),
                          vx_core::vx_new_string(":delim"),
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_textblock::c_delimbracketcurly,
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
                                  vx_core::vx_new_string("c"),
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
                                  vx_core::vx_new_string(" "),
                                  vx_core::vx_new_string(":startpos"),
                                  vx_core::vx_new_int(10),
                                  vx_core::vx_new_string(":endpos"),
                                  vx_core::vx_new_int(10),
                                  vx_core::vx_new_string(":delim"),
                                  vx_core::f_copy(
                                    vx_data_textblock::t_delim,
                                    vx_data_textblock::c_delimwhitespace,
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
                                  vx_core::vx_new_string("d"),
                                  vx_core::vx_new_string(":startpos"),
                                  vx_core::vx_new_int(11),
                                  vx_core::vx_new_string(":endpos"),
                                  vx_core::vx_new_int(11)
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
      vx_data_textblock::f_textblock_parse(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("<{a,b},{c d}>"),
            vx_core::vx_new_string(":delim"),
            vx_data_textblock::c_delimtest1
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"<{a,b},{c d}>\"\n  :startpos 1\n  :endpos 13\n  :children\n   (textblocklist\n    (textblock\n     :text \"<{a,b},{c d}>\"\n     :startpos 1\n     :endpos 13\n     :delim\n      (copy delimbracketangle\n       :pos 0)\n     :children\n      (textblocklist\n       (textblock\n        :text \"{a,b}\"\n        :startpos 2\n        :endpos 6\n        :delim\n         (copy delimbracketcurly\n          :pos 0)\n        :children\n         (textblocklist\n          (textblock\n           :text \"a\"\n           :startpos 3\n           :endpos 3)\n          (textblock\n           :text \",\"\n           :startpos 4\n           :endpos 4\n           :delim\n            (copy delimcomma\n             :pos 0))\n          (textblock\n           :text \"b\"\n           :startpos 5\n           :endpos 5)))\n       (textblock\n        :text \",\"\n        :startpos 7\n        :endpos 7\n        :delim\n         (copy delimcomma\n          :pos 0))\n       (textblock\n        :text \"{c d}\"\n        :startpos 8\n        :endpos 12\n        :delim\n         (copy delimbracketcurly\n          :pos 0)\n        :children\n         (textblocklist\n          (textblock\n           :text \"c\"\n           :startpos 9\n           :endpos 9)\n          (textblock\n           :text \" \"\n           :startpos 10\n           :endpos 10\n           :delim\n            (copy delimwhitespace\n             :pos 0))\n          (textblock\n           :text \"d\"\n           :startpos 11\n           :endpos 11)))))))\n (textblock-parse\n  (textblock\n   :text \"<{a,b},{c d}>\"\n   :delim delimtest1)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
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
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("<{a,b},{c d}>"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(1),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(13),
          vx_core::vx_new_string(":delim"),
          vx_data_textblock::c_delimtest1,
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("<{a,b},{c d}>"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(1),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(13)
            })
          )
        })
      ),
      vx_data_textblock::f_textblock_parse_one(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("<{a,b},{c d}>"),
            vx_core::vx_new_string(":delim"),
            vx_data_textblock::c_delimtest1
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"<{a,b},{c d}>\"\n  :startpos 1\n  :endpos 13\n  :delim delimtest1\n  :parent\n   (textblock\n    :text \"<{a,b},{c d}>\"\n    :startpos 1\n    :endpos 13))\n (textblock-parse-one\n  (textblock\n   :text \"<{a,b},{c d}>\"\n   :delim delimtest1)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string(""),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              vx_data_textblock::c_delimlisttest2
            })
          ),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("{a,b},{c d}>"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(2),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(13),
              vx_core::vx_new_string(":delim"),
              vx_core::f_new(
                vx_data_textblock::t_delim,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_data_textblock::c_delimlisttest2
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
                  vx_core::vx_new_string("<{a,b},{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimbracketangle,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      vx_data_textblock::c_delimlisttest1
                    })
                  ),
                  vx_core::vx_new_string(":parent"),
                  vx_core::f_new(
                    vx_data_textblock::t_textblock,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":text"),
                      vx_core::vx_new_string("<{a,b},{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13)
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
            vx_core::vx_new_string("<{a,b},{c d}>"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(1),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(13),
            vx_core::vx_new_string(":delim"),
            vx_data_textblock::c_delimtest1,
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("<{a,b},{c d}>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(1),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13)
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"\"\n  :delim\n   (delim\n    :delimlist delimlisttest2)\n  :parent\n   (textblock\n    :text \"{a,b},{c d}>\"\n    :startpos 2\n    :endpos 13\n    :delim\n     (delim\n      :delimlist delimlisttest2)\n    :close\n     (copy delimclose\n      :starttext \">\")\n    :parent\n     (textblock\n      :text \"<{a,b},{c d}>\"\n      :startpos 1\n      :endpos 13\n      :delim\n       (copy delimbracketangle\n        :delimlist delimlisttest1)\n      :parent\n       (textblock\n        :text \"<{a,b},{c d}>\"\n        :startpos 1\n        :endpos 13))))\n (textblock-parse-one\n  (textblock\n   :text \"<{a,b},{c d}>\"\n   :startpos 1\n   :endpos 13\n   :delim delimtest1\n   :parent\n    (textblock\n     :text \"<{a,b},{c d}>\"\n     :startpos 1\n     :endpos 13))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    // testdescribe_3
    vx_test::Type_testresult testresult_3 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("{a,b},{c d}>"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(2),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(13),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              vx_data_textblock::c_delimlisttest2
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
              vx_core::vx_new_string("<{a,b},{c d}>"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(1),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(13),
              vx_core::vx_new_string(":delim"),
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimbracketangle,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_data_textblock::c_delimlisttest1
                })
              ),
              vx_core::vx_new_string(":parent"),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("<{a,b},{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13)
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
            vx_core::vx_new_string(""),
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_data_textblock::c_delimlisttest2
              })
            ),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("{a,b},{c d}>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(2),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13),
                vx_core::vx_new_string(":delim"),
                vx_core::f_new(
                  vx_data_textblock::t_delim,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_data_textblock::c_delimlisttest2
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
                    vx_core::vx_new_string("<{a,b},{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(1),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimbracketangle,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":delimlist"),
                        vx_data_textblock::c_delimlisttest1
                      })
                    ),
                    vx_core::vx_new_string(":parent"),
                    vx_core::f_new(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":text"),
                        vx_core::vx_new_string("<{a,b},{c d}>"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(1),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(13)
                      })
                    )
                  })
                )
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_3 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"{a,b},{c d}>\"\n  :startpos 2\n  :endpos 13\n  :delim\n   (delim\n    :delimlist delimlisttest2)\n  :close\n   (copy delimclose\n    :starttext \">\")\n  :parent\n   (textblock\n    :text \"<{a,b},{c d}>\"\n    :startpos 1\n    :endpos 13\n    :delim\n     (copy delimbracketangle\n      :delimlist delimlisttest1)\n    :parent\n     (textblock\n      :text \"<{a,b},{c d}>\"\n      :startpos 1\n      :endpos 13)))\n (textblock-parse-one\n  (textblock\n   :text \"\"\n   :delim\n    (delim\n     :delimlist delimlisttest2)\n   :parent\n    (textblock\n     :text \"{a,b},{c d}>\"\n     :startpos 2\n     :endpos 13\n     :delim\n      (delim\n       :delimlist delimlisttest2)\n     :close\n      (copy delimclose\n       :starttext \">\")\n     :parent\n      (textblock\n       :text \"<{a,b},{c d}>\"\n       :startpos 1\n       :endpos 13\n       :delim\n        (copy delimbracketangle\n         :delimlist delimlisttest1)\n       :parent\n        (textblock\n         :text \"<{a,b},{c d}>\"\n         :startpos 1\n         :endpos 13))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_3
    });
    // testdescribe_4
    vx_test::Type_testresult testresult_4 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(1),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(1),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              vx_data_textblock::c_delimlisttest3
            })
          ),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("a,b},{c d}>"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(3),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(13),
              vx_core::vx_new_string(":delim"),
              vx_core::f_new(
                vx_data_textblock::t_delim,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_data_textblock::c_delimlisttest3
                })
              ),
              vx_core::vx_new_string(":close"),
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimclose,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":starttext"),
                  vx_core::vx_new_string("}")
                })
              ),
              vx_core::vx_new_string(":parent"),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("{a,b},{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(2),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimbracketcurly,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      vx_data_textblock::c_delimlisttest2
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
                      vx_core::vx_new_string("<{a,b},{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13),
                      vx_core::vx_new_string(":delim"),
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimbracketangle,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":delimlist"),
                          vx_data_textblock::c_delimlisttest1
                        })
                      ),
                      vx_core::vx_new_string(":parent"),
                      vx_core::f_new(
                        vx_data_textblock::t_textblock,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":text"),
                          vx_core::vx_new_string("<{a,b},{c d}>"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(1),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(13)
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
            vx_core::vx_new_string("{a,b},{c d}>"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(2),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(13),
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_data_textblock::c_delimlisttest2
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
                vx_core::vx_new_string("<{a,b},{c d}>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(1),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13),
                vx_core::vx_new_string(":delim"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimbracketangle,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_data_textblock::c_delimlisttest1
                  })
                ),
                vx_core::vx_new_string(":parent"),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("<{a,b},{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(1),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13)
                  })
                )
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_4 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :startpos 1\n  :endpos 1\n  :delim\n   (delim\n    :delimlist delimlisttest3)\n  :parent\n   (textblock\n    :text \"a,b},{c d}>\"\n    :startpos 3\n    :endpos 13\n    :delim\n     (delim\n      :delimlist delimlisttest3)\n    :close\n     (copy delimclose\n      :starttext \"}\")\n    :parent\n     (textblock\n      :text \"{a,b},{c d}>\"\n      :startpos 2\n      :endpos 13\n      :delim\n       (copy delimbracketcurly\n        :delimlist delimlisttest2)\n      :close\n       (copy delimclose\n        :starttext \">\")\n      :parent\n       (textblock\n        :text \"<{a,b},{c d}>\"\n        :startpos 1\n        :endpos 13\n        :delim\n         (copy delimbracketangle\n          :delimlist delimlisttest1)\n        :parent\n         (textblock\n          :text \"<{a,b},{c d}>\"\n          :startpos 1\n          :endpos 13)))))\n (textblock-parse-one\n  (textblock\n   :text \"{a,b},{c d}>\"\n   :startpos 2\n   :endpos 13\n   :delim\n    (delim\n     :delimlist delimlisttest2)\n   :close\n    (copy delimclose\n     :starttext \">\")\n   :parent\n    (textblock\n     :text \"<{a,b},{c d}>\"\n     :startpos 1\n     :endpos 13\n     :delim\n      (copy delimbracketangle\n       :delimlist delimlisttest1)\n     :parent\n      (textblock\n       :text \"<{a,b},{c d}>\"\n       :startpos 1\n       :endpos 13)))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_4
    });
    // testdescribe_5
    vx_test::Type_testresult testresult_5 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("a,b},{c d}>"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(3),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(13),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              vx_data_textblock::c_delimlisttest3
            })
          ),
          vx_core::vx_new_string(":close"),
          vx_core::f_copy(
            vx_data_textblock::t_delim,
            vx_data_textblock::c_delimclose,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":starttext"),
              vx_core::vx_new_string("}")
            })
          ),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("{a,b},{c d}>"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(2),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(13),
              vx_core::vx_new_string(":delim"),
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimbracketcurly,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_data_textblock::c_delimlisttest2
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
                  vx_core::vx_new_string("<{a,b},{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimbracketangle,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      vx_data_textblock::c_delimlisttest1
                    })
                  ),
                  vx_core::vx_new_string(":parent"),
                  vx_core::f_new(
                    vx_data_textblock::t_textblock,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":text"),
                      vx_core::vx_new_string("<{a,b},{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13)
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
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(1),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(1),
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_data_textblock::c_delimlisttest3
              })
            ),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("a,b},{c d}>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(3),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13),
                vx_core::vx_new_string(":delim"),
                vx_core::f_new(
                  vx_data_textblock::t_delim,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_data_textblock::c_delimlisttest3
                  })
                ),
                vx_core::vx_new_string(":close"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimclose,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":starttext"),
                    vx_core::vx_new_string("}")
                  })
                ),
                vx_core::vx_new_string(":parent"),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("{a,b},{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(2),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimbracketcurly,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":delimlist"),
                        vx_data_textblock::c_delimlisttest2
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
                        vx_core::vx_new_string("<{a,b},{c d}>"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(1),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(13),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_textblock::c_delimbracketangle,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":delimlist"),
                            vx_data_textblock::c_delimlisttest1
                          })
                        ),
                        vx_core::vx_new_string(":parent"),
                        vx_core::f_new(
                          vx_data_textblock::t_textblock,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string("<{a,b},{c d}>"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(1),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(13)
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
      )
    );
    vx_test::Type_testdescribe testdescribe_5 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"a,b},{c d}>\"\n  :startpos 3\n  :endpos 13\n  :delim\n   (delim\n    :delimlist delimlisttest3)\n  :close\n   (copy delimclose\n    :starttext \"}\")\n  :parent\n   (textblock\n    :text \"{a,b},{c d}>\"\n    :startpos 2\n    :endpos 13\n    :delim\n     (copy delimbracketcurly\n      :delimlist delimlisttest2)\n    :close\n     (copy delimclose\n      :starttext \">\")\n    :parent\n     (textblock\n      :text \"<{a,b},{c d}>\"\n      :startpos 1\n      :endpos 13\n      :delim\n       (copy delimbracketangle\n        :delimlist delimlisttest1)\n      :parent\n       (textblock\n        :text \"<{a,b},{c d}>\"\n        :startpos 1\n        :endpos 13))))\n (textblock-parse-one\n  (textblock\n   :startpos 1\n   :endpos 1\n   :delim\n    (delim\n     :delimlist delimlisttest3)\n   :parent\n    (textblock\n     :text \"a,b},{c d}>\"\n     :startpos 3\n     :endpos 13\n     :delim\n      (delim\n       :delimlist delimlisttest3)\n     :close\n      (copy delimclose\n       :starttext \"}\")\n     :parent\n      (textblock\n       :text \"{a,b},{c d}>\"\n       :startpos 2\n       :endpos 13\n       :delim\n        (copy delimbracketcurly\n         :delimlist delimlisttest2)\n       :close\n        (copy delimclose\n         :starttext \">\")\n       :parent\n        (textblock\n         :text \"<{a,b},{c d}>\"\n         :startpos 1\n         :endpos 13\n         :delim\n          (copy delimbracketangle\n           :delimlist delimlisttest1)\n         :parent\n          (textblock\n           :text \"<{a,b},{c d}>\"\n           :startpos 1\n           :endpos 13)))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_5
    });
    // testdescribe_6
    vx_test::Type_testresult testresult_6 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("a"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(3),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(3),
          vx_core::vx_new_string(":parent"),
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
              ),
              vx_core::vx_new_string(":parent"),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("b},{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(5),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_new(
                    vx_data_textblock::t_delim,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      vx_data_textblock::c_delimlisttest3
                    })
                  ),
                  vx_core::vx_new_string(":close"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimclose,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":starttext"),
                      vx_core::vx_new_string("}")
                    })
                  ),
                  vx_core::vx_new_string(":parent"),
                  vx_core::f_new(
                    vx_data_textblock::t_textblock,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":text"),
                      vx_core::vx_new_string("{a,b},{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(2),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13),
                      vx_core::vx_new_string(":delim"),
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimbracketcurly,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":delimlist"),
                          vx_data_textblock::c_delimlisttest2
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
                          vx_core::vx_new_string("<{a,b},{c d}>"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(1),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(13),
                          vx_core::vx_new_string(":delim"),
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_textblock::c_delimbracketangle,
                            vx_core::vx_new(vx_core::t_anylist, {
                              vx_core::vx_new_string(":delimlist"),
                              vx_data_textblock::c_delimlisttest1
                            })
                          ),
                          vx_core::vx_new_string(":parent"),
                          vx_core::f_new(
                            vx_data_textblock::t_textblock,
                            vx_core::vx_new(vx_core::t_anylist, {
                              vx_core::vx_new_string(":text"),
                              vx_core::vx_new_string("<{a,b},{c d}>"),
                              vx_core::vx_new_string(":startpos"),
                              vx_core::vx_new_int(1),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(13)
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
            vx_core::vx_new_string("a,b},{c d}>"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(3),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(13),
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_data_textblock::c_delimlisttest3
              })
            ),
            vx_core::vx_new_string(":close"),
            vx_core::f_copy(
              vx_data_textblock::t_delim,
              vx_data_textblock::c_delimclose,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":starttext"),
                vx_core::vx_new_string("}")
              })
            ),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("{a,b},{c d}>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(2),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13),
                vx_core::vx_new_string(":delim"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimbracketcurly,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_data_textblock::c_delimlisttest2
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
                    vx_core::vx_new_string("<{a,b},{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(1),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimbracketangle,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":delimlist"),
                        vx_data_textblock::c_delimlisttest1
                      })
                    ),
                    vx_core::vx_new_string(":parent"),
                    vx_core::f_new(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":text"),
                        vx_core::vx_new_string("<{a,b},{c d}>"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(1),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(13)
                      })
                    )
                  })
                )
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_6 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"a\"\n  :startpos 3\n  :endpos 3\n  :parent\n   (textblock\n    :text \",\"\n    :startpos 4\n    :endpos 4\n    :delim\n     (copy delimcomma\n      :pos 0)\n    :parent\n     (textblock\n      :text \"b},{c d}>\"\n      :startpos 5\n      :endpos 13\n      :delim\n       (delim\n        :delimlist delimlisttest3)\n      :close\n       (copy delimclose\n        :starttext \"}\")\n      :parent\n       (textblock\n        :text \"{a,b},{c d}>\"\n        :startpos 2\n        :endpos 13\n        :delim\n         (copy delimbracketcurly\n          :delimlist delimlisttest2)\n        :close\n         (copy delimclose\n          :starttext \">\")\n        :parent\n         (textblock\n          :text \"<{a,b},{c d}>\"\n          :startpos 1\n          :endpos 13\n          :delim\n           (copy delimbracketangle\n            :delimlist delimlisttest1)\n          :parent\n           (textblock\n            :text \"<{a,b},{c d}>\"\n            :startpos 1\n            :endpos 13))))))\n (textblock-parse-one\n  (textblock\n   :text \"a,b},{c d}>\"\n   :startpos 3\n   :endpos 13\n   :delim\n    (delim\n     :delimlist delimlisttest3)\n   :close\n    (copy delimclose\n     :starttext \"}\")\n   :parent\n    (textblock\n     :text \"{a,b},{c d}>\"\n     :startpos 2\n     :endpos 13\n     :delim\n      (copy delimbracketcurly\n       :delimlist delimlisttest2)\n     :close\n      (copy delimclose\n       :starttext \">\")\n     :parent\n      (textblock\n       :text \"<{a,b},{c d}>\"\n       :startpos 1\n       :endpos 13\n       :delim\n        (copy delimbracketangle\n         :delimlist delimlisttest1)\n       :parent\n        (textblock\n         :text \"<{a,b},{c d}>\"\n         :startpos 1\n         :endpos 13))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_6
    });
    // testdescribe_7
    vx_test::Type_testresult testresult_7 = vx_test::f_test(
      context,
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
          ),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("b},{c d}>"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(5),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(13),
              vx_core::vx_new_string(":delim"),
              vx_core::f_new(
                vx_data_textblock::t_delim,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_data_textblock::c_delimlisttest3
                })
              ),
              vx_core::vx_new_string(":close"),
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimclose,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":starttext"),
                  vx_core::vx_new_string("}")
                })
              ),
              vx_core::vx_new_string(":parent"),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("{a,b},{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(2),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimbracketcurly,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      vx_data_textblock::c_delimlisttest2
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
                      vx_core::vx_new_string("<{a,b},{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13),
                      vx_core::vx_new_string(":delim"),
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimbracketangle,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":delimlist"),
                          vx_data_textblock::c_delimlisttest1
                        })
                      ),
                      vx_core::vx_new_string(":parent"),
                      vx_core::f_new(
                        vx_data_textblock::t_textblock,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":text"),
                          vx_core::vx_new_string("<{a,b},{c d}>"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(1),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(13)
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
                          vx_core::vx_new_int(3),
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
      ),
      vx_data_textblock::f_textblock_parse_one(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("a"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(3),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(3),
            vx_core::vx_new_string(":parent"),
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
                ),
                vx_core::vx_new_string(":parent"),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("b},{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(5),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_new(
                      vx_data_textblock::t_delim,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":delimlist"),
                        vx_data_textblock::c_delimlisttest3
                      })
                    ),
                    vx_core::vx_new_string(":close"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimclose,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":starttext"),
                        vx_core::vx_new_string("}")
                      })
                    ),
                    vx_core::vx_new_string(":parent"),
                    vx_core::f_new(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":text"),
                        vx_core::vx_new_string("{a,b},{c d}>"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(2),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(13),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_textblock::c_delimbracketcurly,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":delimlist"),
                            vx_data_textblock::c_delimlisttest2
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
                            vx_core::vx_new_string("<{a,b},{c d}>"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(1),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(13),
                            vx_core::vx_new_string(":delim"),
                            vx_core::f_copy(
                              vx_data_textblock::t_delim,
                              vx_data_textblock::c_delimbracketangle,
                              vx_core::vx_new(vx_core::t_anylist, {
                                vx_core::vx_new_string(":delimlist"),
                                vx_data_textblock::c_delimlisttest1
                              })
                            ),
                            vx_core::vx_new_string(":parent"),
                            vx_core::f_new(
                              vx_data_textblock::t_textblock,
                              vx_core::vx_new(vx_core::t_anylist, {
                                vx_core::vx_new_string(":text"),
                                vx_core::vx_new_string("<{a,b},{c d}>"),
                                vx_core::vx_new_string(":startpos"),
                                vx_core::vx_new_int(1),
                                vx_core::vx_new_string(":endpos"),
                                vx_core::vx_new_int(13)
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
      )
    );
    vx_test::Type_testdescribe testdescribe_7 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \",\"\n  :startpos 4\n  :endpos 4\n  :delim\n   (copy delimcomma\n    :pos 0)\n  :parent\n   (textblock\n    :text \"b},{c d}>\"\n    :startpos 5\n    :endpos 13\n    :delim\n     (delim\n      :delimlist delimlisttest3)\n    :close\n     (copy delimclose\n      :starttext \"}\")\n    :parent\n     (textblock\n      :text \"{a,b},{c d}>\"\n      :startpos 2\n      :endpos 13\n      :delim\n       (copy delimbracketcurly\n        :delimlist delimlisttest2)\n      :close\n       (copy delimclose\n        :starttext \">\")\n      :parent\n       (textblock\n        :text \"<{a,b},{c d}>\"\n        :startpos 1\n        :endpos 13\n        :delim\n         (copy delimbracketangle\n          :delimlist delimlisttest1)\n        :parent\n         (textblock\n          :text \"<{a,b},{c d}>\"\n          :startpos 1\n          :endpos 13))\n      :children\n       (textblocklist\n        (textblock\n         :text \"a\"\n         :startpos 3\n         :endpos 3)))))\n (textblock-parse-one\n  (textblock\n   :text \"a\"\n   :startpos 3\n   :endpos 3\n   :parent\n    (textblock\n     :text \",\"\n     :startpos 4\n     :endpos 4\n     :delim\n      (copy delimcomma\n       :pos 0)\n     :parent\n      (textblock\n       :text \"b},{c d}>\"\n       :startpos 5\n       :endpos 13\n       :delim\n        (delim\n         :delimlist delimlisttest3)\n       :close\n        (copy delimclose\n         :starttext \"}\")\n       :parent\n        (textblock\n         :text \"{a,b},{c d}>\"\n         :startpos 2\n         :endpos 13\n         :delim\n          (copy delimbracketcurly\n           :delimlist delimlisttest2)\n         :close\n          (copy delimclose\n           :starttext \">\")\n         :parent\n          (textblock\n           :text \"<{a,b},{c d}>\"\n           :startpos 1\n           :endpos 13\n           :delim\n            (copy delimbracketangle\n             :delimlist delimlisttest1)\n           :parent\n            (textblock\n             :text \"<{a,b},{c d}>\"\n             :startpos 1\n             :endpos 13))))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_7
    });
    // testdescribe_8
    vx_test::Type_testresult testresult_8 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("b},{c d}>"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(5),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(13),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              vx_data_textblock::c_delimlisttest3
            })
          ),
          vx_core::vx_new_string(":close"),
          vx_core::f_copy(
            vx_data_textblock::t_delim,
            vx_data_textblock::c_delimclose,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":starttext"),
              vx_core::vx_new_string("}")
            })
          ),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("{a,b},{c d}>"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(2),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(13),
              vx_core::vx_new_string(":delim"),
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimbracketcurly,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_data_textblock::c_delimlisttest2
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
                  vx_core::vx_new_string("<{a,b},{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimbracketangle,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      vx_data_textblock::c_delimlisttest1
                    })
                  ),
                  vx_core::vx_new_string(":parent"),
                  vx_core::f_new(
                    vx_data_textblock::t_textblock,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":text"),
                      vx_core::vx_new_string("<{a,b},{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13)
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
                      vx_core::vx_new_int(3),
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
            ),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("b},{c d}>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(5),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13),
                vx_core::vx_new_string(":delim"),
                vx_core::f_new(
                  vx_data_textblock::t_delim,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_data_textblock::c_delimlisttest3
                  })
                ),
                vx_core::vx_new_string(":close"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimclose,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":starttext"),
                    vx_core::vx_new_string("}")
                  })
                ),
                vx_core::vx_new_string(":parent"),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("{a,b},{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(2),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimbracketcurly,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":delimlist"),
                        vx_data_textblock::c_delimlisttest2
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
                        vx_core::vx_new_string("<{a,b},{c d}>"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(1),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(13),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_textblock::c_delimbracketangle,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":delimlist"),
                            vx_data_textblock::c_delimlisttest1
                          })
                        ),
                        vx_core::vx_new_string(":parent"),
                        vx_core::f_new(
                          vx_data_textblock::t_textblock,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string("<{a,b},{c d}>"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(1),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(13)
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
                            vx_core::vx_new_int(3),
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
      )
    );
    vx_test::Type_testdescribe testdescribe_8 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"b},{c d}>\"\n  :startpos 5\n  :endpos 13\n  :delim\n   (delim\n    :delimlist delimlisttest3)\n  :close\n   (copy delimclose\n    :starttext \"}\")\n  :parent\n   (textblock\n    :text \"{a,b},{c d}>\"\n    :startpos 2\n    :endpos 13\n    :delim\n     (copy delimbracketcurly\n      :delimlist delimlisttest2)\n    :close\n     (copy delimclose\n      :starttext \">\")\n    :parent\n     (textblock\n      :text \"<{a,b},{c d}>\"\n      :startpos 1\n      :endpos 13\n      :delim\n       (copy delimbracketangle\n        :delimlist delimlisttest1)\n      :parent\n       (textblock\n        :text \"<{a,b},{c d}>\"\n        :startpos 1\n        :endpos 13))\n    :children\n     (textblocklist\n      (textblock\n       :text \"a\"\n       :startpos 3\n       :endpos 3)\n      (textblock\n       :text \",\"\n       :startpos 4\n       :endpos 4\n       :delim\n        (copy delimcomma\n         :pos 0)))))\n (textblock-parse-one\n  (textblock\n   :text \",\"\n   :startpos 4\n   :endpos 4\n   :delim\n    (copy delimcomma\n     :pos 0)\n   :parent\n    (textblock\n     :text \"b},{c d}>\"\n     :startpos 5\n     :endpos 13\n     :delim\n      (delim\n       :delimlist delimlisttest3)\n     :close\n      (copy delimclose\n       :starttext \"}\")\n     :parent\n      (textblock\n       :text \"{a,b},{c d}>\"\n       :startpos 2\n       :endpos 13\n       :delim\n        (copy delimbracketcurly\n         :delimlist delimlisttest2)\n       :close\n        (copy delimclose\n         :starttext \">\")\n       :parent\n        (textblock\n         :text \"<{a,b},{c d}>\"\n         :startpos 1\n         :endpos 13\n         :delim\n          (copy delimbracketangle\n           :delimlist delimlisttest1)\n         :parent\n          (textblock\n           :text \"<{a,b},{c d}>\"\n           :startpos 1\n           :endpos 13))\n       :children\n        (textblocklist\n         (textblock\n          :text \"a\"\n          :startpos 3\n          :endpos 3)))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_8
    });
    // testdescribe_9
    vx_test::Type_testresult testresult_9 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("b"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(5),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(5),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string(",{c d}>"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(7),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(13),
              vx_core::vx_new_string(":delim"),
              vx_core::f_new(
                vx_data_textblock::t_delim,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_data_textblock::c_delimlisttest2
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
                  vx_core::vx_new_string("{a,b}"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(2),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(6),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimbracketcurly,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":pos"),
                      vx_core::vx_new_int(0)
                    })
                  ),
                  vx_core::vx_new_string(":close"),
                  vx_data_textblock::c_delimclosing,
                  vx_core::vx_new_string(":parent"),
                  vx_core::f_new(
                    vx_data_textblock::t_textblock,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":text"),
                      vx_core::vx_new_string("<{a,b},{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13),
                      vx_core::vx_new_string(":delim"),
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimbracketangle,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":delimlist"),
                          vx_data_textblock::c_delimlisttest1
                        })
                      ),
                      vx_core::vx_new_string(":parent"),
                      vx_core::f_new(
                        vx_data_textblock::t_textblock,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":text"),
                          vx_core::vx_new_string("<{a,b},{c d}>"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(1),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(13)
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
                          vx_core::vx_new_int(3),
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
            vx_core::vx_new_string("b},{c d}>"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(5),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(13),
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_data_textblock::c_delimlisttest3
              })
            ),
            vx_core::vx_new_string(":close"),
            vx_core::f_copy(
              vx_data_textblock::t_delim,
              vx_data_textblock::c_delimclose,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":starttext"),
                vx_core::vx_new_string("}")
              })
            ),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("{a,b},{c d}>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(2),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13),
                vx_core::vx_new_string(":delim"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimbracketcurly,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_data_textblock::c_delimlisttest2
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
                    vx_core::vx_new_string("<{a,b},{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(1),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimbracketangle,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":delimlist"),
                        vx_data_textblock::c_delimlisttest1
                      })
                    ),
                    vx_core::vx_new_string(":parent"),
                    vx_core::f_new(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":text"),
                        vx_core::vx_new_string("<{a,b},{c d}>"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(1),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(13)
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
                        vx_core::vx_new_int(3),
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
                    )
                  })
                )
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_9 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"b\"\n  :startpos 5\n  :endpos 5\n  :parent\n   (textblock\n    :text \",{c d}>\"\n    :startpos 7\n    :endpos 13\n    :delim\n     (delim\n      :delimlist delimlisttest2)\n    :close\n     (copy delimclose\n      :starttext \">\")\n    :parent\n     (textblock\n      :text \"{a,b}\"\n      :startpos 2\n      :endpos 6\n      :delim\n       (copy delimbracketcurly\n        :pos 0)\n      :close delimclosing\n      :parent\n       (textblock\n        :text \"<{a,b},{c d}>\"\n        :startpos 1\n        :endpos 13\n        :delim\n         (copy delimbracketangle\n          :delimlist delimlisttest1)\n        :parent\n         (textblock\n          :text \"<{a,b},{c d}>\"\n          :startpos 1\n          :endpos 13))\n      :children\n       (textblocklist\n        (textblock\n         :text \"a\"\n         :startpos 3\n         :endpos 3)\n        (textblock\n         :text \",\"\n         :startpos 4\n         :endpos 4\n         :delim\n          (copy delimcomma\n           :pos 0))))))\n (textblock-parse-one\n  (textblock\n   :text \"b},{c d}>\"\n   :startpos 5\n   :endpos 13\n   :delim\n    (delim\n     :delimlist delimlisttest3)\n   :close\n    (copy delimclose\n     :starttext \"}\")\n   :parent\n    (textblock\n     :text \"{a,b},{c d}>\"\n     :startpos 2\n     :endpos 13\n     :delim\n      (copy delimbracketcurly\n       :delimlist delimlisttest2)\n     :close\n      (copy delimclose\n       :starttext \">\")\n     :parent\n      (textblock\n       :text \"<{a,b},{c d}>\"\n       :startpos 1\n       :endpos 13\n       :delim\n        (copy delimbracketangle\n         :delimlist delimlisttest1)\n       :parent\n        (textblock\n         :text \"<{a,b},{c d}>\"\n         :startpos 1\n         :endpos 13))\n     :children\n      (textblocklist\n       (textblock\n        :text \"a\"\n        :startpos 3\n        :endpos 3)\n       (textblock\n        :text \",\"\n        :startpos 4\n        :endpos 4\n        :delim\n         (copy delimcomma\n          :pos 0)))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_9
    });
    // testdescribe_10
    vx_test::Type_testresult testresult_10 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string(",{c d}>"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(7),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(13),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              vx_data_textblock::c_delimlisttest2
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
              vx_core::vx_new_string("<{a,b},{c d}>"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(1),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(13),
              vx_core::vx_new_string(":delim"),
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimbracketangle,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_data_textblock::c_delimlisttest1
                })
              ),
              vx_core::vx_new_string(":parent"),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("<{a,b},{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13)
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
                      vx_core::vx_new_string("{a,b}"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(2),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(6),
                      vx_core::vx_new_string(":delim"),
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimbracketcurly,
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
                              vx_core::vx_new_int(3),
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
                              vx_core::vx_new_string("b"),
                              vx_core::vx_new_string(":startpos"),
                              vx_core::vx_new_int(5),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(5)
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
            vx_core::vx_new_string("b"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(5),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(5),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string(",{c d}>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(7),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13),
                vx_core::vx_new_string(":delim"),
                vx_core::f_new(
                  vx_data_textblock::t_delim,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_data_textblock::c_delimlisttest2
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
                    vx_core::vx_new_string("{a,b}"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(2),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(6),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimbracketcurly,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":pos"),
                        vx_core::vx_new_int(0)
                      })
                    ),
                    vx_core::vx_new_string(":close"),
                    vx_data_textblock::c_delimclosing,
                    vx_core::vx_new_string(":parent"),
                    vx_core::f_new(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":text"),
                        vx_core::vx_new_string("<{a,b},{c d}>"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(1),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(13),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_textblock::c_delimbracketangle,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":delimlist"),
                            vx_data_textblock::c_delimlisttest1
                          })
                        ),
                        vx_core::vx_new_string(":parent"),
                        vx_core::f_new(
                          vx_data_textblock::t_textblock,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string("<{a,b},{c d}>"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(1),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(13)
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
                            vx_core::vx_new_int(3),
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
                        )
                      })
                    )
                  })
                )
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_10 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \",{c d}>\"\n  :startpos 7\n  :endpos 13\n  :delim\n   (delim\n    :delimlist delimlisttest2)\n  :close\n   (copy delimclose\n    :starttext \">\")\n  :parent\n   (textblock\n    :text \"<{a,b},{c d}>\"\n    :startpos 1\n    :endpos 13\n    :delim\n     (copy delimbracketangle\n      :delimlist delimlisttest1)\n    :parent\n     (textblock\n      :text \"<{a,b},{c d}>\"\n      :startpos 1\n      :endpos 13)\n    :children\n     (textblocklist\n      (textblock\n       :text \"{a,b}\"\n       :startpos 2\n       :endpos 6\n       :delim\n        (copy delimbracketcurly\n         :pos 0)\n       :children\n        (textblocklist\n         (textblock\n          :text \"a\"\n          :startpos 3\n          :endpos 3)\n         (textblock\n          :text \",\"\n          :startpos 4\n          :endpos 4\n          :delim\n           (copy delimcomma\n            :pos 0))\n         (textblock\n          :text \"b\"\n          :startpos 5\n          :endpos 5))))))\n (textblock-parse-one\n  (textblock\n   :text \"b\"\n   :startpos 5\n   :endpos 5\n   :parent\n    (textblock\n     :text \",{c d}>\"\n     :startpos 7\n     :endpos 13\n     :delim\n      (delim\n       :delimlist delimlisttest2)\n     :close\n      (copy delimclose\n       :starttext \">\")\n     :parent\n      (textblock\n       :text \"{a,b}\"\n       :startpos 2\n       :endpos 6\n       :delim\n        (copy delimbracketcurly\n         :pos 0)\n       :close delimclosing\n       :parent\n        (textblock\n         :text \"<{a,b},{c d}>\"\n         :startpos 1\n         :endpos 13\n         :delim\n          (copy delimbracketangle\n           :delimlist delimlisttest1)\n         :parent\n          (textblock\n           :text \"<{a,b},{c d}>\"\n           :startpos 1\n           :endpos 13))\n       :children\n        (textblocklist\n         (textblock\n          :text \"a\"\n          :startpos 3\n          :endpos 3)\n         (textblock\n          :text \",\"\n          :startpos 4\n          :endpos 4\n          :delim\n           (copy delimcomma\n            :pos 0))))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_10
    });
    // testdescribe_11
    vx_test::Type_testresult testresult_11 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(7),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(7),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string(","),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(7),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(7),
              vx_core::vx_new_string(":delim"),
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimcomma,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":pos"),
                  vx_core::vx_new_int(0)
                })
              ),
              vx_core::vx_new_string(":parent"),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(8),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_new(
                    vx_data_textblock::t_delim,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      vx_data_textblock::c_delimlisttest2
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
                      vx_core::vx_new_string("<{a,b},{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13),
                      vx_core::vx_new_string(":delim"),
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimbracketangle,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":delimlist"),
                          vx_data_textblock::c_delimlisttest1
                        })
                      ),
                      vx_core::vx_new_string(":parent"),
                      vx_core::f_new(
                        vx_data_textblock::t_textblock,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":text"),
                          vx_core::vx_new_string("<{a,b},{c d}>"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(1),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(13)
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
                              vx_core::vx_new_string("{a,b}"),
                              vx_core::vx_new_string(":startpos"),
                              vx_core::vx_new_int(2),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(6),
                              vx_core::vx_new_string(":delim"),
                              vx_core::f_copy(
                                vx_data_textblock::t_delim,
                                vx_data_textblock::c_delimbracketcurly,
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
                                      vx_core::vx_new_int(3),
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
                                      vx_core::vx_new_string("b"),
                                      vx_core::vx_new_string(":startpos"),
                                      vx_core::vx_new_int(5),
                                      vx_core::vx_new_string(":endpos"),
                                      vx_core::vx_new_int(5)
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
          )
        })
      ),
      vx_data_textblock::f_textblock_parse_one(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string(",{c d}>"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(7),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(13),
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_data_textblock::c_delimlisttest2
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
                vx_core::vx_new_string("<{a,b},{c d}>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(1),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13),
                vx_core::vx_new_string(":delim"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimbracketangle,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_data_textblock::c_delimlisttest1
                  })
                ),
                vx_core::vx_new_string(":parent"),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("<{a,b},{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(1),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13)
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
                        vx_core::vx_new_string("{a,b}"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(2),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(6),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_textblock::c_delimbracketcurly,
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
                                vx_core::vx_new_int(3),
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
                                vx_core::vx_new_string("b"),
                                vx_core::vx_new_string(":startpos"),
                                vx_core::vx_new_int(5),
                                vx_core::vx_new_string(":endpos"),
                                vx_core::vx_new_int(5)
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
      )
    );
    vx_test::Type_testdescribe testdescribe_11 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :startpos 7\n  :endpos 7\n  :parent\n   (textblock\n    :text \",\"\n    :startpos 7\n    :endpos 7\n    :delim\n     (copy delimcomma\n      :pos 0)\n    :parent\n     (textblock\n      :text \"{c d}>\"\n      :startpos 8\n      :endpos 13\n      :delim\n       (delim\n        :delimlist delimlisttest2)\n      :close\n       (copy delimclose\n        :starttext \">\")\n      :parent\n       (textblock\n        :text \"<{a,b},{c d}>\"\n        :startpos 1\n        :endpos 13\n        :delim\n         (copy delimbracketangle\n          :delimlist delimlisttest1)\n        :parent\n         (textblock\n          :text \"<{a,b},{c d}>\"\n          :startpos 1\n          :endpos 13)\n        :children\n         (textblocklist\n          (textblock\n           :text \"{a,b}\"\n           :startpos 2\n           :endpos 6\n           :delim\n            (copy delimbracketcurly\n             :pos 0)\n           :children\n            (textblocklist\n             (textblock\n              :text \"a\"\n              :startpos 3\n              :endpos 3)\n             (textblock\n              :text \",\"\n              :startpos 4\n              :endpos 4\n              :delim\n               (copy delimcomma\n                :pos 0))\n             (textblock\n              :text \"b\"\n              :startpos 5\n              :endpos 5))))))))\n (textblock-parse-one\n  (textblock\n   :text \",{c d}>\"\n   :startpos 7\n   :endpos 13\n   :delim\n    (delim\n     :delimlist delimlisttest2)\n   :close\n    (copy delimclose\n     :starttext \">\")\n   :parent\n    (textblock\n     :text \"<{a,b},{c d}>\"\n     :startpos 1\n     :endpos 13\n     :delim\n      (copy delimbracketangle\n       :delimlist delimlisttest1)\n     :parent\n      (textblock\n       :text \"<{a,b},{c d}>\"\n       :startpos 1\n       :endpos 13)\n     :children\n      (textblocklist\n       (textblock\n        :text \"{a,b}\"\n        :startpos 2\n        :endpos 6\n        :delim\n         (copy delimbracketcurly\n          :pos 0)\n        :children\n         (textblocklist\n          (textblock\n           :text \"a\"\n           :startpos 3\n           :endpos 3)\n          (textblock\n           :text \",\"\n           :startpos 4\n           :endpos 4\n           :delim\n            (copy delimcomma\n             :pos 0))\n          (textblock\n           :text \"b\"\n           :startpos 5\n           :endpos 5))))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_11
    });
    // testdescribe_12
    vx_test::Type_testresult testresult_12 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string(","),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(7),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(7),
          vx_core::vx_new_string(":delim"),
          vx_core::f_copy(
            vx_data_textblock::t_delim,
            vx_data_textblock::c_delimcomma,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":pos"),
              vx_core::vx_new_int(0)
            })
          ),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("{c d}>"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(8),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(13),
              vx_core::vx_new_string(":delim"),
              vx_core::f_new(
                vx_data_textblock::t_delim,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_data_textblock::c_delimlisttest2
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
                  vx_core::vx_new_string("<{a,b},{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimbracketangle,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      vx_data_textblock::c_delimlisttest1
                    })
                  ),
                  vx_core::vx_new_string(":parent"),
                  vx_core::f_new(
                    vx_data_textblock::t_textblock,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":text"),
                      vx_core::vx_new_string("<{a,b},{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13)
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
                          vx_core::vx_new_string("{a,b}"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(2),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(6),
                          vx_core::vx_new_string(":delim"),
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_textblock::c_delimbracketcurly,
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
                                  vx_core::vx_new_int(3),
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
                                  vx_core::vx_new_string("b"),
                                  vx_core::vx_new_string(":startpos"),
                                  vx_core::vx_new_int(5),
                                  vx_core::vx_new_string(":endpos"),
                                  vx_core::vx_new_int(5)
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
      vx_data_textblock::f_textblock_parse_one(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(7),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(7),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string(","),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(7),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(7),
                vx_core::vx_new_string(":delim"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimcomma,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":pos"),
                    vx_core::vx_new_int(0)
                  })
                ),
                vx_core::vx_new_string(":parent"),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(8),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_new(
                      vx_data_textblock::t_delim,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":delimlist"),
                        vx_data_textblock::c_delimlisttest2
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
                        vx_core::vx_new_string("<{a,b},{c d}>"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(1),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(13),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_textblock::c_delimbracketangle,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":delimlist"),
                            vx_data_textblock::c_delimlisttest1
                          })
                        ),
                        vx_core::vx_new_string(":parent"),
                        vx_core::f_new(
                          vx_data_textblock::t_textblock,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string("<{a,b},{c d}>"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(1),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(13)
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
                                vx_core::vx_new_string("{a,b}"),
                                vx_core::vx_new_string(":startpos"),
                                vx_core::vx_new_int(2),
                                vx_core::vx_new_string(":endpos"),
                                vx_core::vx_new_int(6),
                                vx_core::vx_new_string(":delim"),
                                vx_core::f_copy(
                                  vx_data_textblock::t_delim,
                                  vx_data_textblock::c_delimbracketcurly,
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
                                        vx_core::vx_new_int(3),
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
                                        vx_core::vx_new_string("b"),
                                        vx_core::vx_new_string(":startpos"),
                                        vx_core::vx_new_int(5),
                                        vx_core::vx_new_string(":endpos"),
                                        vx_core::vx_new_int(5)
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
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_12 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \",\"\n  :startpos 7\n  :endpos 7\n  :delim\n   (copy delimcomma\n    :pos 0)\n  :parent\n   (textblock\n    :text \"{c d}>\"\n    :startpos 8\n    :endpos 13\n    :delim\n     (delim\n      :delimlist delimlisttest2)\n    :close\n     (copy delimclose\n      :starttext \">\")\n    :parent\n     (textblock\n      :text \"<{a,b},{c d}>\"\n      :startpos 1\n      :endpos 13\n      :delim\n       (copy delimbracketangle\n        :delimlist delimlisttest1)\n      :parent\n       (textblock\n        :text \"<{a,b},{c d}>\"\n        :startpos 1\n        :endpos 13)\n      :children\n       (textblocklist\n        (textblock\n         :text \"{a,b}\"\n         :startpos 2\n         :endpos 6\n         :delim\n          (copy delimbracketcurly\n           :pos 0)\n         :children\n          (textblocklist\n           (textblock\n            :text \"a\"\n            :startpos 3\n            :endpos 3)\n           (textblock\n            :text \",\"\n            :startpos 4\n            :endpos 4\n            :delim\n             (copy delimcomma\n              :pos 0))\n           (textblock\n            :text \"b\"\n            :startpos 5\n            :endpos 5)))))))\n (textblock-parse-one\n  (textblock\n   :startpos 7\n   :endpos 7\n   :parent\n    (textblock\n     :text \",\"\n     :startpos 7\n     :endpos 7\n     :delim\n      (copy delimcomma\n       :pos 0)\n     :parent\n      (textblock\n       :text \"{c d}>\"\n       :startpos 8\n       :endpos 13\n       :delim\n        (delim\n         :delimlist delimlisttest2)\n       :close\n        (copy delimclose\n         :starttext \">\")\n       :parent\n        (textblock\n         :text \"<{a,b},{c d}>\"\n         :startpos 1\n         :endpos 13\n         :delim\n          (copy delimbracketangle\n           :delimlist delimlisttest1)\n         :parent\n          (textblock\n           :text \"<{a,b},{c d}>\"\n           :startpos 1\n           :endpos 13)\n         :children\n          (textblocklist\n           (textblock\n            :text \"{a,b}\"\n            :startpos 2\n            :endpos 6\n            :delim\n             (copy delimbracketcurly\n              :pos 0)\n            :children\n             (textblocklist\n              (textblock\n               :text \"a\"\n               :startpos 3\n               :endpos 3)\n              (textblock\n               :text \",\"\n               :startpos 4\n               :endpos 4\n               :delim\n                (copy delimcomma\n                 :pos 0))\n              (textblock\n               :text \"b\"\n               :startpos 5\n               :endpos 5))))))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_12
    });
    // testdescribe_13
    vx_test::Type_testresult testresult_13 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("{c d}>"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(8),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(13),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              vx_data_textblock::c_delimlisttest2
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
              vx_core::vx_new_string("<{a,b},{c d}>"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(1),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(13),
              vx_core::vx_new_string(":delim"),
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimbracketangle,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_data_textblock::c_delimlisttest1
                })
              ),
              vx_core::vx_new_string(":parent"),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("<{a,b},{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13)
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
                      vx_core::vx_new_string("{a,b}"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(2),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(6),
                      vx_core::vx_new_string(":delim"),
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimbracketcurly,
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
                              vx_core::vx_new_int(3),
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
                              vx_core::vx_new_string("b"),
                              vx_core::vx_new_string(":startpos"),
                              vx_core::vx_new_int(5),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(5)
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
                      vx_core::vx_new_int(7),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(7),
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
            vx_core::vx_new_string(","),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(7),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(7),
            vx_core::vx_new_string(":delim"),
            vx_core::f_copy(
              vx_data_textblock::t_delim,
              vx_data_textblock::c_delimcomma,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":pos"),
                vx_core::vx_new_int(0)
              })
            ),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("{c d}>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(8),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13),
                vx_core::vx_new_string(":delim"),
                vx_core::f_new(
                  vx_data_textblock::t_delim,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_data_textblock::c_delimlisttest2
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
                    vx_core::vx_new_string("<{a,b},{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(1),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimbracketangle,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":delimlist"),
                        vx_data_textblock::c_delimlisttest1
                      })
                    ),
                    vx_core::vx_new_string(":parent"),
                    vx_core::f_new(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":text"),
                        vx_core::vx_new_string("<{a,b},{c d}>"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(1),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(13)
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
                            vx_core::vx_new_string("{a,b}"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(2),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(6),
                            vx_core::vx_new_string(":delim"),
                            vx_core::f_copy(
                              vx_data_textblock::t_delim,
                              vx_data_textblock::c_delimbracketcurly,
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
                                    vx_core::vx_new_int(3),
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
                                    vx_core::vx_new_string("b"),
                                    vx_core::vx_new_string(":startpos"),
                                    vx_core::vx_new_int(5),
                                    vx_core::vx_new_string(":endpos"),
                                    vx_core::vx_new_int(5)
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
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_13 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"{c d}>\"\n  :startpos 8\n  :endpos 13\n  :delim\n   (delim\n    :delimlist delimlisttest2)\n  :close\n   (copy delimclose\n    :starttext \">\")\n  :parent\n   (textblock\n    :text \"<{a,b},{c d}>\"\n    :startpos 1\n    :endpos 13\n    :delim\n     (copy delimbracketangle\n      :delimlist delimlisttest1)\n    :parent\n     (textblock\n      :text \"<{a,b},{c d}>\"\n      :startpos 1\n      :endpos 13)\n    :children\n     (textblocklist\n      (textblock\n       :text \"{a,b}\"\n       :startpos 2\n       :endpos 6\n       :delim\n        (copy delimbracketcurly\n         :pos 0)\n       :children\n        (textblocklist\n         (textblock\n          :text \"a\"\n          :startpos 3\n          :endpos 3)\n         (textblock\n          :text \",\"\n          :startpos 4\n          :endpos 4\n          :delim\n           (copy delimcomma\n            :pos 0))\n         (textblock\n          :text \"b\"\n          :startpos 5\n          :endpos 5)))\n      (textblock\n       :text \",\"\n       :startpos 7\n       :endpos 7\n       :delim\n        (copy delimcomma\n         :pos 0)))))\n (textblock-parse-one\n  (textblock\n   :text \",\"\n   :startpos 7\n   :endpos 7\n   :delim\n    (copy delimcomma\n     :pos 0)\n   :parent\n    (textblock\n     :text \"{c d}>\"\n     :startpos 8\n     :endpos 13\n     :delim\n      (delim\n       :delimlist delimlisttest2)\n       :close\n        (copy delimclose\n         :starttext \">\")\n     :parent\n      (textblock\n       :text \"<{a,b},{c d}>\"\n       :startpos 1\n       :endpos 13\n       :delim\n        (copy delimbracketangle\n         :delimlist delimlisttest1)\n       :parent\n        (textblock\n         :text \"<{a,b},{c d}>\"\n         :startpos 1\n         :endpos 13)\n       :children\n        (textblocklist\n         (textblock\n          :text \"{a,b}\"\n          :startpos 2\n          :endpos 6\n          :delim\n           (copy delimbracketcurly\n            :pos 0)\n          :children\n           (textblocklist\n            (textblock\n             :text \"a\"\n             :startpos 3\n             :endpos 3)\n            (textblock\n             :text \",\"\n             :startpos 4\n             :endpos 4\n             :delim\n              (copy delimcomma\n               :pos 0))\n            (textblock\n             :text \"b\"\n             :startpos 5\n             :endpos 5)))))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_13
    });
    // testdescribe_14
    vx_test::Type_testresult testresult_14 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(7),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(7),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              vx_data_textblock::c_delimlisttest3
            })
          ),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("c d}>"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(9),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(13),
              vx_core::vx_new_string(":delim"),
              vx_core::f_new(
                vx_data_textblock::t_delim,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_data_textblock::c_delimlisttest3
                })
              ),
              vx_core::vx_new_string(":close"),
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimclose,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":starttext"),
                  vx_core::vx_new_string("}")
                })
              ),
              vx_core::vx_new_string(":parent"),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(8),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimbracketcurly,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      vx_data_textblock::c_delimlisttest2
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
                      vx_core::vx_new_string("<{a,b},{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13),
                      vx_core::vx_new_string(":delim"),
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimbracketangle,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":delimlist"),
                          vx_data_textblock::c_delimlisttest1
                        })
                      ),
                      vx_core::vx_new_string(":parent"),
                      vx_core::f_new(
                        vx_data_textblock::t_textblock,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":text"),
                          vx_core::vx_new_string("<{a,b},{c d}>"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(1),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(13)
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
                              vx_core::vx_new_string("{a,b}"),
                              vx_core::vx_new_string(":startpos"),
                              vx_core::vx_new_int(2),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(6),
                              vx_core::vx_new_string(":delim"),
                              vx_core::f_copy(
                                vx_data_textblock::t_delim,
                                vx_data_textblock::c_delimbracketcurly,
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
                                      vx_core::vx_new_int(3),
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
                                      vx_core::vx_new_string("b"),
                                      vx_core::vx_new_string(":startpos"),
                                      vx_core::vx_new_int(5),
                                      vx_core::vx_new_string(":endpos"),
                                      vx_core::vx_new_int(5)
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
                              vx_core::vx_new_int(7),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(7),
                              vx_core::vx_new_string(":delim"),
                              vx_core::f_copy(
                                vx_data_textblock::t_delim,
                                vx_data_textblock::c_delimcomma,
                                vx_core::vx_new(vx_core::t_anylist, {
                                  vx_core::vx_new_string(":pos")
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
      vx_data_textblock::f_textblock_parse_one(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("{c d}>"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(8),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(13),
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_data_textblock::c_delimlisttest2
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
                vx_core::vx_new_string("<{a,b},{c d}>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(1),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13),
                vx_core::vx_new_string(":delim"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimbracketangle,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_data_textblock::c_delimlisttest1
                  })
                ),
                vx_core::vx_new_string(":parent"),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("<{a,b},{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(1),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13)
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
                        vx_core::vx_new_string("{a,b}"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(2),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(6),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_textblock::c_delimbracketcurly,
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
                                vx_core::vx_new_int(3),
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
                                vx_core::vx_new_string("b"),
                                vx_core::vx_new_string(":startpos"),
                                vx_core::vx_new_int(5),
                                vx_core::vx_new_string(":endpos"),
                                vx_core::vx_new_int(5)
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
                        vx_core::vx_new_int(7),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(7),
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
                    )
                  })
                )
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_14 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :startpos 7\n  :endpos 7\n  :delim\n   (delim\n    :delimlist delimlisttest3)\n  :parent\n   (textblock\n    :text \"c d}>\"\n    :startpos 9\n    :endpos 13\n    :delim\n     (delim\n      :delimlist delimlisttest3)\n  :close\n   (copy delimclose\n    :starttext \"}\")\n  :parent\n   (textblock\n    :text \"{c d}>\"\n    :startpos 8\n    :endpos 13\n    :delim\n     (copy delimbracketcurly\n      :delimlist delimlisttest2)\n    :close\n     (copy delimclose\n      :starttext \">\")\n    :parent\n     (textblock\n      :text \"<{a,b},{c d}>\"\n      :startpos 1\n      :endpos 13\n      :delim\n       (copy delimbracketangle\n        :delimlist delimlisttest1)\n      :parent\n       (textblock\n        :text \"<{a,b},{c d}>\"\n        :startpos 1\n        :endpos 13)\n      :children\n       (textblocklist\n        (textblock\n         :text \"{a,b}\"\n         :startpos 2\n         :endpos 6\n         :delim\n          (copy delimbracketcurly\n           :pos 0)\n         :children\n          (textblocklist\n           (textblock\n            :text \"a\"\n            :startpos 3\n            :endpos 3)\n           (textblock\n            :text \",\"\n            :startpos 4\n            :endpos 4\n            :delim\n             (copy delimcomma\n              :pos 0))\n           (textblock\n            :text \"b\"\n            :startpos 5\n            :endpos 5)))\n        (textblock\n         :text \",\"\n         :startpos 7\n         :endpos 7\n         :delim\n          (copy delimcomma\n           :pos)))))))\n (textblock-parse-one\n  (textblock\n   :text \"{c d}>\"\n   :startpos 8\n   :endpos 13\n   :delim\n    (delim\n     :delimlist delimlisttest2)\n   :close\n    (copy delimclose\n     :starttext \">\")\n   :parent\n    (textblock\n     :text \"<{a,b},{c d}>\"\n     :startpos 1\n     :endpos 13\n     :delim\n      (copy delimbracketangle\n       :delimlist delimlisttest1)\n     :parent\n      (textblock\n       :text \"<{a,b},{c d}>\"\n       :startpos 1\n       :endpos 13)\n     :children\n      (textblocklist\n       (textblock\n        :text \"{a,b}\"\n        :startpos 2\n        :endpos 6\n        :delim\n         (copy delimbracketcurly\n          :pos 0)\n        :children\n         (textblocklist\n          (textblock\n           :text \"a\"\n           :startpos 3\n           :endpos 3)\n          (textblock\n           :text \",\"\n           :startpos 4\n           :endpos 4\n           :delim\n            (copy delimcomma\n             :pos 0))\n          (textblock\n           :text \"b\"\n           :startpos 5\n           :endpos 5)))\n       (textblock\n        :text \",\"\n        :startpos 7\n        :endpos 7\n        :delim\n         (copy delimcomma\n          :pos 0)))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_14
    });
    // testdescribe_15
    vx_test::Type_testresult testresult_15 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("c d}>"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(9),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(13),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              vx_data_textblock::c_delimlisttest3
            })
          ),
          vx_core::vx_new_string(":close"),
          vx_core::f_copy(
            vx_data_textblock::t_delim,
            vx_data_textblock::c_delimclose,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":starttext"),
              vx_core::vx_new_string("}")
            })
          ),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("{c d}>"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(8),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(13),
              vx_core::vx_new_string(":delim"),
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimbracketcurly,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_data_textblock::c_delimlisttest2
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
                  vx_core::vx_new_string("<{a,b},{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimbracketangle,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      vx_data_textblock::c_delimlisttest1
                    })
                  ),
                  vx_core::vx_new_string(":parent"),
                  vx_core::f_new(
                    vx_data_textblock::t_textblock,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":text"),
                      vx_core::vx_new_string("<{a,b},{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13)
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
                          vx_core::vx_new_string("{a,b}"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(2),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(6),
                          vx_core::vx_new_string(":delim"),
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_textblock::c_delimbracketcurly,
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
                                  vx_core::vx_new_int(3),
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
                                  vx_core::vx_new_string("b"),
                                  vx_core::vx_new_string(":startpos"),
                                  vx_core::vx_new_int(5),
                                  vx_core::vx_new_string(":endpos"),
                                  vx_core::vx_new_int(5)
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
                          vx_core::vx_new_int(7),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(7),
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
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(7),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(7),
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_data_textblock::c_delimlisttest3
              })
            ),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("c d}>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(9),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13),
                vx_core::vx_new_string(":delim"),
                vx_core::f_new(
                  vx_data_textblock::t_delim,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_data_textblock::c_delimlisttest3
                  })
                ),
                vx_core::vx_new_string(":close"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimclose,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":starttext"),
                    vx_core::vx_new_string("}")
                  })
                ),
                vx_core::vx_new_string(":parent"),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(8),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimbracketcurly,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":delimlist"),
                        vx_data_textblock::c_delimlisttest2
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
                        vx_core::vx_new_string("<{a,b},{c d}>"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(1),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(13),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_textblock::c_delimbracketangle,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":delimlist"),
                            vx_data_textblock::c_delimlisttest1
                          })
                        ),
                        vx_core::vx_new_string(":parent"),
                        vx_core::f_new(
                          vx_data_textblock::t_textblock,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string("<{a,b},{c d}>"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(1),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(13)
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
                                vx_core::vx_new_string("{a,b}"),
                                vx_core::vx_new_string(":startpos"),
                                vx_core::vx_new_int(2),
                                vx_core::vx_new_string(":endpos"),
                                vx_core::vx_new_int(6),
                                vx_core::vx_new_string(":delim"),
                                vx_core::f_copy(
                                  vx_data_textblock::t_delim,
                                  vx_data_textblock::c_delimbracketcurly,
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
                                        vx_core::vx_new_int(3),
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
                                        vx_core::vx_new_string("b"),
                                        vx_core::vx_new_string(":startpos"),
                                        vx_core::vx_new_int(5),
                                        vx_core::vx_new_string(":endpos"),
                                        vx_core::vx_new_int(5)
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
                                vx_core::vx_new_int(7),
                                vx_core::vx_new_string(":endpos"),
                                vx_core::vx_new_int(7),
                                vx_core::vx_new_string(":delim"),
                                vx_core::f_copy(
                                  vx_data_textblock::t_delim,
                                  vx_data_textblock::c_delimcomma,
                                  vx_core::vx_new(vx_core::t_anylist, {
                                    vx_core::vx_new_string(":pos")
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
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_15 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"c d}>\"\n  :startpos 9\n  :endpos 13\n  :delim\n   (delim\n    :delimlist delimlisttest3)\n  :close\n   (copy delimclose\n    :starttext \"}\")\n    :parent\n     (textblock\n      :text \"{c d}>\"\n      :startpos 8\n      :endpos 13\n      :delim\n       (copy delimbracketcurly\n        :delimlist delimlisttest2)\n      :close\n       (copy delimclose\n        :starttext \">\")\n      :parent\n       (textblock\n        :text \"<{a,b},{c d}>\"\n        :startpos 1\n        :endpos 13\n        :delim\n         (copy delimbracketangle\n          :delimlist delimlisttest1)\n        :parent\n         (textblock\n          :text \"<{a,b},{c d}>\"\n          :startpos 1\n          :endpos 13)\n        :children\n         (textblocklist\n          (textblock\n           :text \"{a,b}\"\n           :startpos 2\n           :endpos 6\n           :delim\n            (copy delimbracketcurly\n             :pos 0)\n           :children\n            (textblocklist\n             (textblock\n              :text \"a\"\n              :startpos 3\n              :endpos 3)\n             (textblock\n              :text \",\"\n              :startpos 4\n              :endpos 4\n              :delim\n               (copy delimcomma\n                :pos 0))\n             (textblock\n              :text \"b\"\n              :startpos 5\n              :endpos 5)))\n          (textblock\n           :text \",\"\n           :startpos 7\n           :endpos 7\n           :delim\n            (copy delimcomma\n             :pos 0))))))\n (textblock-parse-one\n  (textblock\n   :startpos 7\n   :endpos 7\n   :delim\n    (delim\n     :delimlist delimlisttest3)\n   :parent\n    (textblock\n     :text \"c d}>\"\n     :startpos 9\n     :endpos 13\n     :delim\n      (delim\n       :delimlist delimlisttest3)\n   :close\n    (copy delimclose\n     :starttext \"}\")\n   :parent\n    (textblock\n     :text \"{c d}>\"\n     :startpos 8\n     :endpos 13\n     :delim\n      (copy delimbracketcurly\n       :delimlist delimlisttest2)\n     :close\n      (copy delimclose\n       :starttext \">\")\n     :parent\n      (textblock\n       :text \"<{a,b},{c d}>\"\n       :startpos 1\n       :endpos 13\n       :delim\n        (copy delimbracketangle\n         :delimlist delimlisttest1)\n       :parent\n        (textblock\n         :text \"<{a,b},{c d}>\"\n         :startpos 1\n         :endpos 13)\n       :children\n        (textblocklist\n         (textblock\n          :text \"{a,b}\"\n          :startpos 2\n          :endpos 6\n          :delim\n           (copy delimbracketcurly\n            :pos 0)\n          :children\n           (textblocklist\n            (textblock\n             :text \"a\"\n             :startpos 3\n             :endpos 3)\n            (textblock\n             :text \",\"\n             :startpos 4\n             :endpos 4\n             :delim\n              (copy delimcomma\n               :pos 0))\n            (textblock\n             :text \"b\"\n             :startpos 5\n             :endpos 5)))\n         (textblock\n          :text \",\"\n          :startpos 7\n          :endpos 7\n          :delim\n           (copy delimcomma\n            :pos)))))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_15
    });
    // testdescribe_16
    vx_test::Type_testresult testresult_16 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("c"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(9),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(9),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string(" "),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(10),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(10),
              vx_core::vx_new_string(":delim"),
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimwhitespace,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":pos"),
                  vx_core::vx_new_int(0)
                })
              ),
              vx_core::vx_new_string(":parent"),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(11),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_new(
                    vx_data_textblock::t_delim,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      vx_data_textblock::c_delimlisttest3
                    })
                  ),
                  vx_core::vx_new_string(":close"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimclose,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":starttext"),
                      vx_core::vx_new_string("}")
                    })
                  ),
                  vx_core::vx_new_string(":parent"),
                  vx_core::f_new(
                    vx_data_textblock::t_textblock,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":text"),
                      vx_core::vx_new_string("{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(8),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13),
                      vx_core::vx_new_string(":delim"),
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimbracketcurly,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":delimlist"),
                          vx_data_textblock::c_delimlisttest2
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
                          vx_core::vx_new_string("<{a,b},{c d}>"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(1),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(13),
                          vx_core::vx_new_string(":delim"),
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_textblock::c_delimbracketangle,
                            vx_core::vx_new(vx_core::t_anylist, {
                              vx_core::vx_new_string(":delimlist"),
                              vx_data_textblock::c_delimlisttest1
                            })
                          ),
                          vx_core::vx_new_string(":parent"),
                          vx_core::f_new(
                            vx_data_textblock::t_textblock,
                            vx_core::vx_new(vx_core::t_anylist, {
                              vx_core::vx_new_string(":text"),
                              vx_core::vx_new_string("<{a,b},{c d}>"),
                              vx_core::vx_new_string(":startpos"),
                              vx_core::vx_new_int(1),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(13)
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
                                  vx_core::vx_new_string("{a,b}"),
                                  vx_core::vx_new_string(":startpos"),
                                  vx_core::vx_new_int(2),
                                  vx_core::vx_new_string(":endpos"),
                                  vx_core::vx_new_int(6),
                                  vx_core::vx_new_string(":delim"),
                                  vx_core::f_copy(
                                    vx_data_textblock::t_delim,
                                    vx_data_textblock::c_delimbracketcurly,
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
                                          vx_core::vx_new_int(3),
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
                                          vx_core::vx_new_string("b"),
                                          vx_core::vx_new_string(":startpos"),
                                          vx_core::vx_new_int(5),
                                          vx_core::vx_new_string(":endpos"),
                                          vx_core::vx_new_int(5)
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
                                  vx_core::vx_new_int(7),
                                  vx_core::vx_new_string(":endpos"),
                                  vx_core::vx_new_int(7),
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
      vx_data_textblock::f_textblock_parse_one(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("c d}>"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(9),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(13),
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_data_textblock::c_delimlisttest3
              })
            ),
            vx_core::vx_new_string(":close"),
            vx_core::f_copy(
              vx_data_textblock::t_delim,
              vx_data_textblock::c_delimclose,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":starttext"),
                vx_core::vx_new_string("}")
              })
            ),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("{c d}>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(8),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13),
                vx_core::vx_new_string(":delim"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimbracketcurly,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_data_textblock::c_delimlisttest2
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
                    vx_core::vx_new_string("<{a,b},{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(1),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimbracketangle,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":delimlist"),
                        vx_data_textblock::c_delimlisttest1
                      })
                    ),
                    vx_core::vx_new_string(":parent"),
                    vx_core::f_new(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":text"),
                        vx_core::vx_new_string("<{a,b},{c d}>"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(1),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(13)
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
                            vx_core::vx_new_string("{a,b}"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(2),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(6),
                            vx_core::vx_new_string(":delim"),
                            vx_core::f_copy(
                              vx_data_textblock::t_delim,
                              vx_data_textblock::c_delimbracketcurly,
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
                                    vx_core::vx_new_int(3),
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
                                    vx_core::vx_new_string("b"),
                                    vx_core::vx_new_string(":startpos"),
                                    vx_core::vx_new_int(5),
                                    vx_core::vx_new_string(":endpos"),
                                    vx_core::vx_new_int(5)
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
                            vx_core::vx_new_int(7),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(7),
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
                        )
                      })
                    )
                  })
                )
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_16 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"c\"\n  :startpos 9\n  :endpos 9\n  :parent\n   (textblock\n    :text \" \"\n    :startpos 10\n    :endpos 10\n    :delim\n     (copy delimwhitespace\n      :pos 0)\n    :parent\n     (textblock\n      :text \"d}>\"\n      :startpos 11\n      :endpos 13\n      :delim\n       (delim\n        :delimlist delimlisttest3)\n      :close\n       (copy delimclose\n        :starttext \"}\")\n      :parent\n       (textblock\n        :text \"{c d}>\"\n        :startpos 8\n        :endpos 13\n        :delim\n         (copy delimbracketcurly\n          :delimlist delimlisttest2)\n        :close\n         (copy delimclose\n          :starttext \">\")\n        :parent\n         (textblock\n          :text \"<{a,b},{c d}>\"\n          :startpos 1\n          :endpos 13\n          :delim\n           (copy delimbracketangle\n            :delimlist delimlisttest1)\n          :parent\n           (textblock\n            :text \"<{a,b},{c d}>\"\n            :startpos 1\n            :endpos 13)\n          :children\n           (textblocklist\n            (textblock\n             :text \"{a,b}\"\n             :startpos 2\n             :endpos 6\n             :delim\n              (copy delimbracketcurly\n               :pos 0)\n             :children\n              (textblocklist\n               (textblock\n                :text \"a\"\n                :startpos 3\n                :endpos 3)\n               (textblock\n                :text \",\"\n                :startpos 4\n                :endpos 4\n                :delim\n                 (copy delimcomma\n                  :pos 0))\n               (textblock\n                :text \"b\"\n                :startpos 5\n                :endpos 5)))\n            (textblock\n             :text \",\"\n             :startpos 7\n             :endpos 7\n             :delim\n              (copy delimcomma\n               :pos 0))))))))\n (textblock-parse-one\n  (textblock\n   :text \"c d}>\"\n   :startpos 9\n   :endpos 13\n   :delim\n    (delim\n     :delimlist delimlisttest3)\n     :close\n      (copy delimclose\n       :starttext \"}\")\n     :parent\n      (textblock\n       :text \"{c d}>\"\n       :startpos 8\n       :endpos 13\n       :delim\n        (copy delimbracketcurly\n         :delimlist delimlisttest2)\n       :close\n        (copy delimclose\n         :starttext \">\")\n       :parent\n        (textblock\n         :text \"<{a,b},{c d}>\"\n         :startpos 1\n         :endpos 13\n         :delim\n          (copy delimbracketangle\n           :delimlist delimlisttest1)\n         :parent\n          (textblock\n           :text \"<{a,b},{c d}>\"\n           :startpos 1\n           :endpos 13)\n         :children\n          (textblocklist\n           (textblock\n            :text \"{a,b}\"\n            :startpos 2\n            :endpos 6\n            :delim\n             (copy delimbracketcurly\n              :pos 0)\n            :children\n             (textblocklist\n              (textblock\n               :text \"a\"\n               :startpos 3\n               :endpos 3)\n              (textblock\n               :text \",\"\n               :startpos 4\n               :endpos 4\n               :delim\n                (copy delimcomma\n                 :pos 0))\n              (textblock\n               :text \"b\"\n               :startpos 5\n               :endpos 5)))\n           (textblock\n            :text \",\"\n            :startpos 7\n            :endpos 7\n            :delim\n             (copy delimcomma\n              :pos 0))))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_16
    });
    // testdescribe_17
    vx_test::Type_testresult testresult_17 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string(" "),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(10),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(10),
          vx_core::vx_new_string(":delim"),
          vx_core::f_copy(
            vx_data_textblock::t_delim,
            vx_data_textblock::c_delimwhitespace,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":pos"),
              vx_core::vx_new_int(0)
            })
          ),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("d}>"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(11),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(13),
              vx_core::vx_new_string(":delim"),
              vx_core::f_new(
                vx_data_textblock::t_delim,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_data_textblock::c_delimlisttest3
                })
              ),
              vx_core::vx_new_string(":close"),
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimclose,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":starttext"),
                  vx_core::vx_new_string("}")
                })
              ),
              vx_core::vx_new_string(":parent"),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(8),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimbracketcurly,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      vx_data_textblock::c_delimlisttest2
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
                      vx_core::vx_new_string("<{a,b},{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13),
                      vx_core::vx_new_string(":delim"),
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimbracketangle,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":delimlist"),
                          vx_data_textblock::c_delimlisttest1
                        })
                      ),
                      vx_core::vx_new_string(":parent"),
                      vx_core::f_new(
                        vx_data_textblock::t_textblock,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":text"),
                          vx_core::vx_new_string("<{a,b},{c d}>"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(1),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(13)
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
                              vx_core::vx_new_string("{a,b}"),
                              vx_core::vx_new_string(":startpos"),
                              vx_core::vx_new_int(2),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(6),
                              vx_core::vx_new_string(":delim"),
                              vx_core::f_copy(
                                vx_data_textblock::t_delim,
                                vx_data_textblock::c_delimbracketcurly,
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
                                      vx_core::vx_new_int(3),
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
                                      vx_core::vx_new_string("b"),
                                      vx_core::vx_new_string(":startpos"),
                                      vx_core::vx_new_int(5),
                                      vx_core::vx_new_string(":endpos"),
                                      vx_core::vx_new_int(5)
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
                              vx_core::vx_new_int(7),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(7),
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
                          vx_core::vx_new_string("c"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(9),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(9)
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
            vx_core::vx_new_string("c"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(9),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(9),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string(" "),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(10),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(10),
                vx_core::vx_new_string(":delim"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimwhitespace,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":pos"),
                    vx_core::vx_new_int(0)
                  })
                ),
                vx_core::vx_new_string(":parent"),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(11),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_new(
                      vx_data_textblock::t_delim,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":delimlist"),
                        vx_data_textblock::c_delimlisttest3
                      })
                    ),
                    vx_core::vx_new_string(":close"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimclose,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":starttext"),
                        vx_core::vx_new_string("}")
                      })
                    ),
                    vx_core::vx_new_string(":parent"),
                    vx_core::f_new(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":text"),
                        vx_core::vx_new_string("{c d}>"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(8),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(13),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_textblock::c_delimbracketcurly,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":delimlist"),
                            vx_data_textblock::c_delimlisttest2
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
                            vx_core::vx_new_string("<{a,b},{c d}>"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(1),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(13),
                            vx_core::vx_new_string(":delim"),
                            vx_core::f_copy(
                              vx_data_textblock::t_delim,
                              vx_data_textblock::c_delimbracketangle,
                              vx_core::vx_new(vx_core::t_anylist, {
                                vx_core::vx_new_string(":delimlist"),
                                vx_data_textblock::c_delimlisttest1
                              })
                            ),
                            vx_core::vx_new_string(":parent"),
                            vx_core::f_new(
                              vx_data_textblock::t_textblock,
                              vx_core::vx_new(vx_core::t_anylist, {
                                vx_core::vx_new_string(":text"),
                                vx_core::vx_new_string("<{a,b},{c d}>"),
                                vx_core::vx_new_string(":startpos"),
                                vx_core::vx_new_int(1),
                                vx_core::vx_new_string(":endpos"),
                                vx_core::vx_new_int(13)
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
                                    vx_core::vx_new_string("{a,b}"),
                                    vx_core::vx_new_string(":startpos"),
                                    vx_core::vx_new_int(2),
                                    vx_core::vx_new_string(":endpos"),
                                    vx_core::vx_new_int(6),
                                    vx_core::vx_new_string(":delim"),
                                    vx_core::f_copy(
                                      vx_data_textblock::t_delim,
                                      vx_data_textblock::c_delimbracketcurly,
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
                                            vx_core::vx_new_int(3),
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
                                            vx_core::vx_new_string("b"),
                                            vx_core::vx_new_string(":startpos"),
                                            vx_core::vx_new_int(5),
                                            vx_core::vx_new_string(":endpos"),
                                            vx_core::vx_new_int(5)
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
                                    vx_core::vx_new_int(7),
                                    vx_core::vx_new_string(":endpos"),
                                    vx_core::vx_new_int(7),
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
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_17 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \" \"\n  :startpos 10\n  :endpos 10\n  :delim\n   (copy delimwhitespace\n    :pos 0)\n  :parent\n   (textblock\n    :text \"d}>\"\n    :startpos 11\n    :endpos 13\n    :delim\n     (delim\n      :delimlist delimlisttest3)\n    :close\n     (copy delimclose\n      :starttext \"}\")\n    :parent\n     (textblock\n      :text \"{c d}>\"\n      :startpos 8\n      :endpos 13\n      :delim\n       (copy delimbracketcurly\n       :delimlist delimlisttest2)\n      :close\n       (copy delimclose\n        :starttext \">\")\n      :parent\n       (textblock\n        :text \"<{a,b},{c d}>\"\n        :startpos 1\n        :endpos 13\n        :delim\n         (copy delimbracketangle\n          :delimlist delimlisttest1)\n        :parent\n         (textblock\n          :text \"<{a,b},{c d}>\"\n          :startpos 1\n          :endpos 13)\n          :children\n           (textblocklist\n            (textblock\n             :text \"{a,b}\"\n             :startpos 2\n             :endpos 6\n             :delim\n              (copy delimbracketcurly\n               :pos 0)\n             :children\n              (textblocklist\n               (textblock\n                :text \"a\"\n                :startpos 3\n                :endpos 3)\n               (textblock\n                :text \",\"\n                :startpos 4\n                :endpos 4\n                :delim\n                 (copy delimcomma\n                  :pos 0))\n               (textblock\n                :text \"b\"\n                :startpos 5\n                :endpos 5)))\n               (textblock\n                :text \",\"\n                :startpos 7\n                :endpos 7\n                :delim\n                 (copy delimcomma\n                  :pos 0))))\n      :children\n       (textblocklist\n        (textblock\n         :text \"c\"\n         :startpos 9\n         :endpos 9)))))\n (textblock-parse-one\n  (textblock\n   :text \"c\"\n   :startpos 9\n   :endpos 9\n   :parent\n    (textblock\n     :text \" \"\n     :startpos 10\n     :endpos 10\n     :delim\n      (copy delimwhitespace\n       :pos 0)\n     :parent\n      (textblock\n       :text \"d}>\"\n       :startpos 11\n       :endpos 13\n       :delim\n        (delim\n         :delimlist delimlisttest3)\n       :close\n        (copy delimclose\n         :starttext \"}\")\n       :parent\n        (textblock\n         :text \"{c d}>\"\n         :startpos 8\n         :endpos 13\n         :delim\n          (copy delimbracketcurly\n           :delimlist delimlisttest2)\n         :close\n          (copy delimclose\n           :starttext \">\")\n         :parent\n          (textblock\n           :text \"<{a,b},{c d}>\"\n           :startpos 1\n           :endpos 13\n           :delim\n            (copy delimbracketangle\n             :delimlist delimlisttest1)\n           :parent\n            (textblock\n             :text \"<{a,b},{c d}>\"\n             :startpos 1\n             :endpos 13)\n           :children\n            (textblocklist\n             (textblock\n              :text \"{a,b}\"\n              :startpos 2\n              :endpos 6\n              :delim\n               (copy delimbracketcurly\n                :pos 0)\n              :children\n               (textblocklist\n                (textblock\n                 :text \"a\"\n                 :startpos 3\n                 :endpos 3)\n                (textblock\n                 :text \",\"\n                 :startpos 4\n                 :endpos 4\n                 :delim\n                  (copy delimcomma\n                   :pos 0))\n                (textblock\n                 :text \"b\"\n                 :startpos 5\n                 :endpos 5)))\n             (textblock\n              :text \",\"\n              :startpos 7\n              :endpos 7\n              :delim\n               (copy delimcomma\n                :pos 0))))))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_17
    });
    // testdescribe_18
    vx_test::Type_testresult testresult_18 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("d}>"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(11),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(13),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              vx_data_textblock::c_delimlisttest3
            })
          ),
          vx_core::vx_new_string(":close"),
          vx_core::f_copy(
            vx_data_textblock::t_delim,
            vx_data_textblock::c_delimclose,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":starttext"),
              vx_core::vx_new_string("}")
            })
          ),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("{c d}>"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(8),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(13),
              vx_core::vx_new_string(":delim"),
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimbracketcurly,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_data_textblock::c_delimlisttest2
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
                  vx_core::vx_new_string("<{a,b},{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_new(
                    vx_data_textblock::t_delim,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":name"),
                      vx_core::vx_new_string("delimbracketangle"),
                      vx_core::vx_new_string(":starttext"),
                      vx_core::vx_new_string("<"),
                      vx_core::vx_new_string(":endtext"),
                      vx_core::vx_new_string(">"),
                      vx_core::vx_new_string(":delimlist"),
                      vx_data_textblock::c_delimlisttest1
                    })
                  ),
                  vx_core::vx_new_string(":parent"),
                  vx_core::f_new(
                    vx_data_textblock::t_textblock,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":text"),
                      vx_core::vx_new_string("<{a,b},{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13)
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
                          vx_core::vx_new_string("{a,b}"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(2),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(6),
                          vx_core::vx_new_string(":delim"),
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_textblock::c_delimbracketcurly,
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
                                  vx_core::vx_new_int(3),
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
                                  vx_core::vx_new_string("b"),
                                  vx_core::vx_new_string(":startpos"),
                                  vx_core::vx_new_int(5),
                                  vx_core::vx_new_string(":endpos"),
                                  vx_core::vx_new_int(5)
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
                          vx_core::vx_new_int(7),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(7),
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
                      vx_core::vx_new_string("c"),
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
                      vx_core::vx_new_string(" "),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(10),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(10),
                      vx_core::vx_new_string(":delim"),
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimwhitespace,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":pos"),
                          vx_core::vx_new_int(0)
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
            vx_core::vx_new_string(" "),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(10),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(10),
            vx_core::vx_new_string(":delim"),
            vx_core::f_copy(
              vx_data_textblock::t_delim,
              vx_data_textblock::c_delimwhitespace,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":pos"),
                vx_core::vx_new_int(0)
              })
            ),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("d}>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(11),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13),
                vx_core::vx_new_string(":delim"),
                vx_core::f_new(
                  vx_data_textblock::t_delim,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_data_textblock::c_delimlisttest3
                  })
                ),
                vx_core::vx_new_string(":close"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimclose,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":starttext"),
                    vx_core::vx_new_string("}")
                  })
                ),
                vx_core::vx_new_string(":parent"),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(8),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimbracketcurly,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":delimlist"),
                        vx_data_textblock::c_delimlisttest2
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
                        vx_core::vx_new_string("<{a,b},{c d}>"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(1),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(13),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_textblock::c_delimbracketangle,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":delimlist"),
                            vx_data_textblock::c_delimlisttest1
                          })
                        ),
                        vx_core::vx_new_string(":parent"),
                        vx_core::f_new(
                          vx_data_textblock::t_textblock,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string("<{a,b},{c d}>"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(1),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(13)
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
                                vx_core::vx_new_string("{a,b}"),
                                vx_core::vx_new_string(":startpos"),
                                vx_core::vx_new_int(2),
                                vx_core::vx_new_string(":endpos"),
                                vx_core::vx_new_int(6),
                                vx_core::vx_new_string(":delim"),
                                vx_core::f_copy(
                                  vx_data_textblock::t_delim,
                                  vx_data_textblock::c_delimbracketcurly,
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
                                        vx_core::vx_new_int(3),
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
                                        vx_core::vx_new_string("b"),
                                        vx_core::vx_new_string(":startpos"),
                                        vx_core::vx_new_int(5),
                                        vx_core::vx_new_string(":endpos"),
                                        vx_core::vx_new_int(5)
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
                                vx_core::vx_new_int(7),
                                vx_core::vx_new_string(":endpos"),
                                vx_core::vx_new_int(7),
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
                            vx_core::vx_new_string("c"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(9),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(9)
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
      )
    );
    vx_test::Type_testdescribe testdescribe_18 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"d}>\"\n  :startpos 11\n  :endpos 13\n  :delim\n   (delim\n    :delimlist delimlisttest3)\n  :close\n   (copy delimclose\n    :starttext \"}\")\n  :parent\n   (textblock\n    :text \"{c d}>\"\n    :startpos 8\n    :endpos 13\n    :delim\n     (copy delimbracketcurly\n      :delimlist delimlisttest2)\n    :close\n     (copy delimclose\n      :starttext \">\")\n    :parent\n     (textblock\n      :text \"<{a,b},{c d}>\"\n      :startpos 1\n      :endpos 13\n      :delim\n       (delim\n        :name \"delimbracketangle\"\n        :starttext \"<\"\n        :endtext \">\"\n        :delimlist delimlisttest1)\n      :parent\n       (textblock\n        :text \"<{a,b},{c d}>\"\n        :startpos 1\n        :endpos 13)\n      :children\n       (textblocklist\n        (textblock\n         :text \"{a,b}\"\n         :startpos 2\n         :endpos 6\n         :delim\n          (copy delimbracketcurly\n           :pos 0)\n         :children\n          (textblocklist\n           (textblock\n            :text \"a\"\n            :startpos 3\n            :endpos 3)\n             (textblock\n              :text \",\"\n              :startpos 4\n              :endpos 4\n              :delim\n               (copy delimcomma\n                :pos 0))\n           (textblock\n            :text \"b\"\n            :startpos 5\n            :endpos 5)))\n        (textblock\n         :text \",\"\n         :startpos 7\n         :endpos 7\n         :delim\n          (copy delimcomma\n           :pos 0))))\n    :children\n     (textblocklist\n      (textblock\n       :text \"c\"\n       :startpos 9\n       :endpos 9)\n      (textblock\n       :text \" \"\n       :startpos 10\n       :endpos 10\n       :delim\n        (copy delimwhitespace\n         :pos 0)))))\n (textblock-parse-one\n  (textblock\n   :text \" \"\n   :startpos 10\n   :endpos 10\n   :delim\n    (copy delimwhitespace\n     :pos 0)\n   :parent\n    (textblock\n     :text \"d}>\"\n     :startpos 11\n     :endpos 13\n     :delim\n      (delim\n       :delimlist delimlisttest3)\n     :close\n      (copy delimclose\n       :starttext \"}\")\n     :parent\n      (textblock\n       :text \"{c d}>\"\n       :startpos 8\n       :endpos 13\n       :delim\n        (copy delimbracketcurly\n        :delimlist delimlisttest2)\n       :close\n        (copy delimclose\n         :starttext \">\")\n       :parent\n        (textblock\n         :text \"<{a,b},{c d}>\"\n         :startpos 1\n         :endpos 13\n         :delim\n          (copy delimbracketangle\n           :delimlist delimlisttest1)\n         :parent\n          (textblock\n           :text \"<{a,b},{c d}>\"\n           :startpos 1\n           :endpos 13)\n         :children\n          (textblocklist\n           (textblock\n            :text \"{a,b}\"\n            :startpos 2\n            :endpos 6\n            :delim\n             (copy delimbracketcurly\n              :pos 0)\n            :children\n             (textblocklist\n              (textblock\n               :text \"a\"\n               :startpos 3\n               :endpos 3)\n              (textblock\n               :text \",\"\n               :startpos 4\n               :endpos 4\n               :delim\n                (copy delimcomma\n                 :pos 0))\n              (textblock\n               :text \"b\"\n               :startpos 5\n               :endpos 5)))\n              (textblock\n               :text \",\"\n               :startpos 7\n               :endpos 7\n               :delim\n                (copy delimcomma\n                 :pos 0))))\n       :children\n        (textblocklist\n         (textblock\n          :text \"c\"\n          :startpos 9\n          :endpos 9)))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_18
    });
    // testdescribe_19
    vx_test::Type_testresult testresult_19 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("d"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(11),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(11),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string(">"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(13),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(13),
              vx_core::vx_new_string(":delim"),
              vx_core::f_new(
                vx_data_textblock::t_delim,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_data_textblock::c_delimlisttest2
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
                  vx_core::vx_new_string("{c d}"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(8),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(12),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimbracketcurly,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":pos"),
                      vx_core::vx_new_int(0)
                    })
                  ),
                  vx_core::vx_new_string(":close"),
                  vx_data_textblock::c_delimclosing,
                  vx_core::vx_new_string(":parent"),
                  vx_core::f_new(
                    vx_data_textblock::t_textblock,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":text"),
                      vx_core::vx_new_string("<{a,b},{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13),
                      vx_core::vx_new_string(":delim"),
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimbracketangle,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":delimlist"),
                          vx_data_textblock::c_delimlisttest1
                        })
                      ),
                      vx_core::vx_new_string(":parent"),
                      vx_core::f_new(
                        vx_data_textblock::t_textblock,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":text"),
                          vx_core::vx_new_string("<{a,b},{c d}>"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(1),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(13)
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
                              vx_core::vx_new_string("{a,b}"),
                              vx_core::vx_new_string(":startpos"),
                              vx_core::vx_new_int(2),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(6),
                              vx_core::vx_new_string(":delim"),
                              vx_core::f_copy(
                                vx_data_textblock::t_delim,
                                vx_data_textblock::c_delimbracketcurly,
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
                                      vx_core::vx_new_int(3),
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
                                      vx_core::vx_new_string("b"),
                                      vx_core::vx_new_string(":startpos"),
                                      vx_core::vx_new_int(5),
                                      vx_core::vx_new_string(":endpos"),
                                      vx_core::vx_new_int(5)
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
                              vx_core::vx_new_int(7),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(7),
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
                          vx_core::vx_new_string("c"),
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
                          vx_core::vx_new_string(" "),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(10),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(10),
                          vx_core::vx_new_string(":delim"),
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_textblock::c_delimwhitespace,
                            vx_core::vx_new(vx_core::t_anylist, {
                              vx_core::vx_new_string(":pos"),
                              vx_core::vx_new_int(0)
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
            vx_core::vx_new_string("d}>"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(11),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(13),
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_data_textblock::c_delimlisttest3
              })
            ),
            vx_core::vx_new_string(":close"),
            vx_core::f_copy(
              vx_data_textblock::t_delim,
              vx_data_textblock::c_delimclose,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":starttext"),
                vx_core::vx_new_string("}")
              })
            ),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("{c d}>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(8),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13),
                vx_core::vx_new_string(":delim"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimbracketcurly,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_data_textblock::c_delimlisttest2
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
                    vx_core::vx_new_string("<{a,b},{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(1),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_new(
                      vx_data_textblock::t_delim,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":name"),
                        vx_core::vx_new_string("delimbracketangle"),
                        vx_core::vx_new_string(":starttext"),
                        vx_core::vx_new_string("<"),
                        vx_core::vx_new_string(":endtext"),
                        vx_core::vx_new_string(">"),
                        vx_core::vx_new_string(":delimlist"),
                        vx_data_textblock::c_delimlisttest1
                      })
                    ),
                    vx_core::vx_new_string(":parent"),
                    vx_core::f_new(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":text"),
                        vx_core::vx_new_string("<{a,b},{c d}>"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(1),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(13)
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
                            vx_core::vx_new_string("{a,b}"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(2),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(6),
                            vx_core::vx_new_string(":delim"),
                            vx_core::f_copy(
                              vx_data_textblock::t_delim,
                              vx_data_textblock::c_delimbracketcurly,
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
                                    vx_core::vx_new_int(3),
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
                                    vx_core::vx_new_string("b"),
                                    vx_core::vx_new_string(":startpos"),
                                    vx_core::vx_new_int(5),
                                    vx_core::vx_new_string(":endpos"),
                                    vx_core::vx_new_int(5)
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
                            vx_core::vx_new_int(7),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(7),
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
                        vx_core::vx_new_string("c"),
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
                        vx_core::vx_new_string(" "),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(10),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(10),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_textblock::c_delimwhitespace,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":pos"),
                            vx_core::vx_new_int(0)
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
      )
    );
    vx_test::Type_testdescribe testdescribe_19 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"d\"\n  :startpos 11\n  :endpos 11\n  :parent\n   (textblock\n    :text \">\"\n    :startpos 13\n    :endpos 13\n    :delim\n     (delim\n      :delimlist delimlisttest2)\n    :close\n     (copy delimclose\n      :starttext \">\")\n    :parent\n     (textblock\n      :text \"{c d}\"\n      :startpos 8\n      :endpos 12\n      :delim\n       (copy delimbracketcurly\n        :pos 0)\n      :close delimclosing\n      :parent\n       (textblock\n        :text \"<{a,b},{c d}>\"\n        :startpos 1\n        :endpos 13\n        :delim\n         (copy delimbracketangle\n          :delimlist delimlisttest1)\n        :parent\n         (textblock\n          :text \"<{a,b},{c d}>\"\n          :startpos 1\n          :endpos 13)\n        :children\n         (textblocklist\n          (textblock\n           :text \"{a,b}\"\n           :startpos 2\n           :endpos 6\n           :delim\n            (copy delimbracketcurly\n             :pos 0)\n           :children\n            (textblocklist\n             (textblock\n              :text \"a\"\n              :startpos 3\n              :endpos 3)\n             (textblock\n              :text \",\"\n              :startpos 4\n              :endpos 4\n              :delim\n               (copy delimcomma\n                :pos 0))\n             (textblock\n              :text \"b\"\n              :startpos 5\n              :endpos 5)))\n          (textblock\n           :text \",\"\n           :startpos 7\n           :endpos 7\n           :delim\n            (copy delimcomma\n             :pos 0))))\n           :children\n            (textblocklist\n             (textblock\n              :text \"c\"\n              :startpos 9\n              :endpos 9)\n             (textblock\n              :text \" \"\n              :startpos 10\n              :endpos 10\n              :delim\n               (copy delimwhitespace\n                :pos 0))))))\n (textblock-parse-one\n  (textblock\n   :text \"d}>\"\n   :startpos 11\n   :endpos 13\n   :delim\n    (delim\n     :delimlist delimlisttest3)\n   :close\n    (copy delimclose\n     :starttext \"}\")\n   :parent\n    (textblock\n     :text \"{c d}>\"\n     :startpos 8\n     :endpos 13\n     :delim\n      (copy delimbracketcurly\n       :delimlist delimlisttest2)\n     :close\n      (copy delimclose\n       :starttext \">\")\n     :parent\n      (textblock\n       :text \"<{a,b},{c d}>\"\n       :startpos 1\n       :endpos 13\n       :delim\n        (delim\n         :name \"delimbracketangle\"\n         :starttext \"<\"\n         :endtext \">\"\n         :delimlist delimlisttest1)\n       :parent\n        (textblock\n         :text \"<{a,b},{c d}>\"\n         :startpos 1\n         :endpos 13)\n       :children\n        (textblocklist\n         (textblock\n          :text \"{a,b}\"\n          :startpos 2\n          :endpos 6\n          :delim\n           (copy delimbracketcurly\n            :pos 0)\n          :children\n           (textblocklist\n            (textblock\n             :text \"a\"\n             :startpos 3\n             :endpos 3)\n              (textblock\n               :text \",\"\n               :startpos 4\n               :endpos 4\n               :delim\n                (copy delimcomma\n                 :pos 0))\n            (textblock\n             :text \"b\"\n             :startpos 5\n             :endpos 5)))\n         (textblock\n          :text \",\"\n          :startpos 7\n          :endpos 7\n          :delim\n           (copy delimcomma\n            :pos 0))))\n     :children\n      (textblocklist\n       (textblock\n        :text \"c\"\n        :startpos 9\n        :endpos 9)\n       (textblock\n        :text \" \"\n        :startpos 10\n        :endpos 10\n        :delim\n         (copy delimwhitespace\n          :pos 0)))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_19
    });
    // testdescribe_20
    vx_test::Type_testresult testresult_20 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string(">"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(13),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(13),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              vx_data_textblock::c_delimlisttest2
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
              vx_core::vx_new_string("<{a,b},{c d}>"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(1),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(13),
              vx_core::vx_new_string(":delim"),
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimbracketangle,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_data_textblock::c_delimlisttest1
                })
              ),
              vx_core::vx_new_string(":parent"),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("<{a,b},{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13)
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
                      vx_core::vx_new_string("{a,b}"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(2),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(6),
                      vx_core::vx_new_string(":delim"),
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimbracketcurly,
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
                              vx_core::vx_new_int(3),
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
                              vx_core::vx_new_string("b"),
                              vx_core::vx_new_string(":startpos"),
                              vx_core::vx_new_int(5),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(5)
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
                      vx_core::vx_new_int(7),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(7),
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
                      vx_core::vx_new_string("{c d}"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(8),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(12),
                      vx_core::vx_new_string(":delim"),
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimbracketcurly,
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
                              vx_core::vx_new_string("c"),
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
                              vx_core::vx_new_string(" "),
                              vx_core::vx_new_string(":startpos"),
                              vx_core::vx_new_int(10),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(10),
                              vx_core::vx_new_string(":delim"),
                              vx_core::f_copy(
                                vx_data_textblock::t_delim,
                                vx_data_textblock::c_delimwhitespace,
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
                              vx_core::vx_new_string("d"),
                              vx_core::vx_new_string(":startpos"),
                              vx_core::vx_new_int(11),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(11)
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
            vx_core::vx_new_string("d"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(11),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(11),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string(">"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(13),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13),
                vx_core::vx_new_string(":delim"),
                vx_core::f_new(
                  vx_data_textblock::t_delim,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_data_textblock::c_delimlisttest2
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
                    vx_core::vx_new_string("{c d}"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(8),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(12),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimbracketcurly,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":pos"),
                        vx_core::vx_new_int(0)
                      })
                    ),
                    vx_core::vx_new_string(":close"),
                    vx_data_textblock::c_delimclosing,
                    vx_core::vx_new_string(":parent"),
                    vx_core::f_new(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":text"),
                        vx_core::vx_new_string("<{a,b},{c d}>"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(1),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(13),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_textblock::c_delimbracketangle,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":delimlist"),
                            vx_data_textblock::c_delimlisttest1
                          })
                        ),
                        vx_core::vx_new_string(":parent"),
                        vx_core::f_new(
                          vx_data_textblock::t_textblock,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string("<{a,b},{c d}>"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(1),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(13)
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
                                vx_core::vx_new_string("{a,b}"),
                                vx_core::vx_new_string(":startpos"),
                                vx_core::vx_new_int(2),
                                vx_core::vx_new_string(":endpos"),
                                vx_core::vx_new_int(6),
                                vx_core::vx_new_string(":delim"),
                                vx_core::f_copy(
                                  vx_data_textblock::t_delim,
                                  vx_data_textblock::c_delimbracketcurly,
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
                                        vx_core::vx_new_int(3),
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
                                        vx_core::vx_new_string("b"),
                                        vx_core::vx_new_string(":startpos"),
                                        vx_core::vx_new_int(5),
                                        vx_core::vx_new_string(":endpos"),
                                        vx_core::vx_new_int(5)
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
                                vx_core::vx_new_int(7),
                                vx_core::vx_new_string(":endpos"),
                                vx_core::vx_new_int(7),
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
                            vx_core::vx_new_string("c"),
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
                            vx_core::vx_new_string(" "),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(10),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(10),
                            vx_core::vx_new_string(":delim"),
                            vx_core::f_copy(
                              vx_data_textblock::t_delim,
                              vx_data_textblock::c_delimwhitespace,
                              vx_core::vx_new(vx_core::t_anylist, {
                                vx_core::vx_new_string(":pos"),
                                vx_core::vx_new_int(0)
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
      )
    );
    vx_test::Type_testdescribe testdescribe_20 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \">\"\n  :startpos 13\n  :endpos 13\n  :delim\n   (delim\n    :delimlist delimlisttest2)\n  :close\n   (copy delimclose\n    :starttext \">\")\n  :parent\n   (textblock\n    :text \"<{a,b},{c d}>\"\n    :startpos 1\n    :endpos 13\n    :delim\n     (copy delimbracketangle\n      :delimlist delimlisttest1)\n    :parent\n     (textblock\n      :text \"<{a,b},{c d}>\"\n      :startpos 1\n      :endpos 13)\n    :children\n     (textblocklist\n      (textblock\n       :text \"{a,b}\"\n       :startpos 2\n       :endpos 6\n       :delim\n        (copy delimbracketcurly\n         :pos 0)\n       :children\n        (textblocklist\n         (textblock\n          :text \"a\"\n          :startpos 3\n          :endpos 3)\n         (textblock\n          :text \",\"\n          :startpos 4\n          :endpos 4\n          :delim\n           (copy delimcomma\n            :pos 0))\n         (textblock\n          :text \"b\"\n          :startpos 5\n          :endpos 5)))\n      (textblock\n       :text \",\"\n       :startpos 7\n       :endpos 7\n       :delim\n        (copy delimcomma\n         :pos 0))\n      (textblock\n       :text \"{c d}\"\n       :startpos 8\n       :endpos 12\n       :delim\n        (copy delimbracketcurly\n         :pos 0)\n       :children\n        (textblocklist\n         (textblock\n          :text \"c\"\n          :startpos 9\n          :endpos 9)\n         (textblock\n          :text \" \"\n          :startpos 10\n          :endpos 10\n          :delim\n           (copy delimwhitespace\n            :pos 0))\n         (textblock\n          :text \"d\"\n          :startpos 11\n          :endpos 11))))))\n (textblock-parse-one\n  (textblock\n   :text \"d\"\n   :startpos 11\n   :endpos 11\n   :parent\n    (textblock\n     :text \">\"\n     :startpos 13\n     :endpos 13\n     :delim\n      (delim\n       :delimlist delimlisttest2)\n     :close\n      (copy delimclose\n       :starttext \">\")\n     :parent\n      (textblock\n       :text \"{c d}\"\n       :startpos 8\n       :endpos 12\n       :delim\n        (copy delimbracketcurly\n         :pos 0)\n       :close delimclosing\n       :parent\n        (textblock\n         :text \"<{a,b},{c d}>\"\n         :startpos 1\n         :endpos 13\n         :delim\n          (copy delimbracketangle\n           :delimlist delimlisttest1)\n         :parent\n          (textblock\n           :text \"<{a,b},{c d}>\"\n           :startpos 1\n           :endpos 13)\n         :children\n          (textblocklist\n           (textblock\n            :text \"{a,b}\"\n            :startpos 2\n            :endpos 6\n            :delim\n             (copy delimbracketcurly\n              :pos 0)\n            :children\n             (textblocklist\n              (textblock\n               :text \"a\"\n               :startpos 3\n               :endpos 3)\n              (textblock\n               :text \",\"\n               :startpos 4\n               :endpos 4\n               :delim\n                (copy delimcomma\n                 :pos 0))\n              (textblock\n               :text \"b\"\n               :startpos 5\n               :endpos 5)))\n           (textblock\n            :text \",\"\n            :startpos 7\n            :endpos 7\n            :delim\n             (copy delimcomma\n              :pos 0))))\n            :children\n             (textblocklist\n              (textblock\n               :text \"c\"\n               :startpos 9\n               :endpos 9)\n              (textblock\n               :text \" \"\n               :startpos 10\n               :endpos 10\n               :delim\n                (copy delimwhitespace\n                 :pos 0))))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_20
    });
    // testdescribe_21
    vx_test::Type_testresult testresult_21 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(13),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(13),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(14),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(14),
              vx_core::vx_new_string(":delim"),
              vx_core::f_new(
                vx_data_textblock::t_delim,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_data_textblock::c_delimlisttest1
                })
              ),
              vx_core::vx_new_string(":parent"),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("<{a,b},{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimbracketangle,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":pos"),
                      vx_core::vx_new_int(0)
                    })
                  ),
                  vx_core::vx_new_string(":close"),
                  vx_data_textblock::c_delimclosing,
                  vx_core::vx_new_string(":parent"),
                  vx_core::f_new(
                    vx_data_textblock::t_textblock,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":text"),
                      vx_core::vx_new_string("<{a,b},{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13)
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
                          vx_core::vx_new_string("{a,b}"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(2),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(6),
                          vx_core::vx_new_string(":delim"),
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_textblock::c_delimbracketcurly,
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
                                  vx_core::vx_new_int(3),
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
                                  vx_core::vx_new_string("b"),
                                  vx_core::vx_new_string(":startpos"),
                                  vx_core::vx_new_int(5),
                                  vx_core::vx_new_string(":endpos"),
                                  vx_core::vx_new_int(5)
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
                          vx_core::vx_new_int(7),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(7),
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
                          vx_core::vx_new_string("{c d}"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(8),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(12),
                          vx_core::vx_new_string(":delim"),
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_textblock::c_delimbracketcurly,
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
                                  vx_core::vx_new_string("c"),
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
                                  vx_core::vx_new_string(" "),
                                  vx_core::vx_new_string(":startpos"),
                                  vx_core::vx_new_int(10),
                                  vx_core::vx_new_string(":endpos"),
                                  vx_core::vx_new_int(10),
                                  vx_core::vx_new_string(":delim"),
                                  vx_core::f_copy(
                                    vx_data_textblock::t_delim,
                                    vx_data_textblock::c_delimwhitespace,
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
                                  vx_core::vx_new_string("d"),
                                  vx_core::vx_new_string(":startpos"),
                                  vx_core::vx_new_int(11),
                                  vx_core::vx_new_string(":endpos"),
                                  vx_core::vx_new_int(11)
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
      vx_data_textblock::f_textblock_parse_one(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string(">"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(13),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(13),
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_data_textblock::c_delimlisttest2
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
                vx_core::vx_new_string("<{a,b},{c d}>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(1),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13),
                vx_core::vx_new_string(":delim"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimbracketangle,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_data_textblock::c_delimlisttest1
                  })
                ),
                vx_core::vx_new_string(":parent"),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("<{a,b},{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(1),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13)
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
                        vx_core::vx_new_string("{a,b}"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(2),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(6),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_textblock::c_delimbracketcurly,
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
                                vx_core::vx_new_int(3),
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
                                vx_core::vx_new_string("b"),
                                vx_core::vx_new_string(":startpos"),
                                vx_core::vx_new_int(5),
                                vx_core::vx_new_string(":endpos"),
                                vx_core::vx_new_int(5)
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
                        vx_core::vx_new_int(7),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(7),
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
                        vx_core::vx_new_string("{c d}"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(8),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(12),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_textblock::c_delimbracketcurly,
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
                                vx_core::vx_new_string("c"),
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
                                vx_core::vx_new_string(" "),
                                vx_core::vx_new_string(":startpos"),
                                vx_core::vx_new_int(10),
                                vx_core::vx_new_string(":endpos"),
                                vx_core::vx_new_int(10),
                                vx_core::vx_new_string(":delim"),
                                vx_core::f_copy(
                                  vx_data_textblock::t_delim,
                                  vx_data_textblock::c_delimwhitespace,
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
                                vx_core::vx_new_string("d"),
                                vx_core::vx_new_string(":startpos"),
                                vx_core::vx_new_int(11),
                                vx_core::vx_new_string(":endpos"),
                                vx_core::vx_new_int(11)
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
      )
    );
    vx_test::Type_testdescribe testdescribe_21 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :startpos 13\n  :endpos 13\n  :parent\n   (textblock\n    :startpos 14\n    :endpos 14\n    :delim\n     (delim\n      :delimlist delimlisttest1)\n    :parent\n     (textblock\n      :text \"<{a,b},{c d}>\"\n      :startpos 1\n      :endpos 13\n      :delim\n       (copy delimbracketangle\n        :pos 0)\n      :close delimclosing\n      :parent\n       (textblock\n        :text \"<{a,b},{c d}>\"\n        :startpos 1\n        :endpos 13)\n      :children\n       (textblocklist\n        (textblock\n         :text \"{a,b}\"\n         :startpos 2\n         :endpos 6\n         :delim\n          (copy delimbracketcurly\n           :pos 0)\n         :children\n          (textblocklist\n           (textblock\n            :text \"a\"\n            :startpos 3\n            :endpos 3)\n           (textblock\n            :text \",\"\n            :startpos 4\n            :endpos 4\n            :delim\n             (copy delimcomma\n              :pos 0))\n           (textblock\n            :text \"b\"\n            :startpos 5\n            :endpos 5)))\n        (textblock\n         :text \",\"\n         :startpos 7\n         :endpos 7\n         :delim\n          (copy delimcomma\n           :pos 0))\n        (textblock\n         :text \"{c d}\"\n         :startpos 8\n         :endpos 12\n         :delim\n          (copy delimbracketcurly\n           :pos 0)\n         :children\n          (textblocklist\n           (textblock\n            :text \"c\"\n            :startpos 9\n            :endpos 9)\n          (textblock\n           :text \" \"\n           :startpos 10\n           :endpos 10\n           :delim\n            (copy delimwhitespace\n             :pos 0))\n          (textblock\n           :text \"d\"\n           :startpos 11\n           :endpos 11)))))))\n (textblock-parse-one\n  (textblock\n   :text \">\"\n   :startpos 13\n   :endpos 13\n   :delim\n    (delim\n     :delimlist delimlisttest2)\n   :close\n    (copy delimclose\n     :starttext \">\")\n   :parent\n    (textblock\n     :text \"<{a,b},{c d}>\"\n     :startpos 1\n     :endpos 13\n     :delim\n      (copy delimbracketangle\n       :delimlist delimlisttest1)\n     :parent\n      (textblock\n       :text \"<{a,b},{c d}>\"\n       :startpos 1\n       :endpos 13)\n     :children\n      (textblocklist\n       (textblock\n        :text \"{a,b}\"\n        :startpos 2\n        :endpos 6\n        :delim\n         (copy delimbracketcurly\n          :pos 0)\n        :children\n         (textblocklist\n          (textblock\n           :text \"a\"\n           :startpos 3\n           :endpos 3)\n          (textblock\n           :text \",\"\n           :startpos 4\n           :endpos 4\n           :delim\n            (copy delimcomma\n             :pos 0))\n          (textblock\n           :text \"b\"\n           :startpos 5\n           :endpos 5)))\n       (textblock\n        :text \",\"\n        :startpos 7\n        :endpos 7\n        :delim\n         (copy delimcomma\n          :pos 0))\n       (textblock\n        :text \"{c d}\"\n        :startpos 8\n        :endpos 12\n        :delim\n         (copy delimbracketcurly\n          :pos 0)\n        :children\n         (textblocklist\n          (textblock\n           :text \"c\"\n           :startpos 9\n           :endpos 9)\n          (textblock\n           :text \" \"\n           :startpos 10\n           :endpos 10\n           :delim\n            (copy delimwhitespace\n             :pos 0))\n          (textblock\n           :text \"d\"\n           :startpos 11\n           :endpos 11))))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_21
    });
    // testdescribe_22
    vx_test::Type_testresult testresult_22 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(14),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(14),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              vx_data_textblock::c_delimlisttest1
            })
          ),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("<{a,b},{c d}>"),
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
                      vx_core::vx_new_string("<{a,b},{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13),
                      vx_core::vx_new_string(":delim"),
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimbracketangle,
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
                              vx_core::vx_new_string("{a,b}"),
                              vx_core::vx_new_string(":startpos"),
                              vx_core::vx_new_int(2),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(6),
                              vx_core::vx_new_string(":delim"),
                              vx_core::f_copy(
                                vx_data_textblock::t_delim,
                                vx_data_textblock::c_delimbracketcurly,
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
                                      vx_core::vx_new_int(3),
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
                                      vx_core::vx_new_string("b"),
                                      vx_core::vx_new_string(":startpos"),
                                      vx_core::vx_new_int(5),
                                      vx_core::vx_new_string(":endpos"),
                                      vx_core::vx_new_int(5)
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
                              vx_core::vx_new_int(7),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(7),
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
                              vx_core::vx_new_string("{c d}"),
                              vx_core::vx_new_string(":startpos"),
                              vx_core::vx_new_int(8),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(12),
                              vx_core::vx_new_string(":delim"),
                              vx_core::f_copy(
                                vx_data_textblock::t_delim,
                                vx_data_textblock::c_delimbracketcurly,
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
                                      vx_core::vx_new_string("c"),
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
                                      vx_core::vx_new_string(" "),
                                      vx_core::vx_new_string(":startpos"),
                                      vx_core::vx_new_int(10),
                                      vx_core::vx_new_string(":endpos"),
                                      vx_core::vx_new_int(10),
                                      vx_core::vx_new_string(":delim"),
                                      vx_core::f_copy(
                                        vx_data_textblock::t_delim,
                                        vx_data_textblock::c_delimwhitespace,
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
                                      vx_core::vx_new_string("d"),
                                      vx_core::vx_new_string(":startpos"),
                                      vx_core::vx_new_int(11),
                                      vx_core::vx_new_string(":endpos"),
                                      vx_core::vx_new_int(11)
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
          )
        })
      ),
      vx_data_textblock::f_textblock_parse_one(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(13),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(13),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(14),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(14),
                vx_core::vx_new_string(":delim"),
                vx_core::f_new(
                  vx_data_textblock::t_delim,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_data_textblock::c_delimlisttest1
                  })
                ),
                vx_core::vx_new_string(":parent"),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("<{a,b},{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(1),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimbracketangle,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":pos"),
                        vx_core::vx_new_int(0)
                      })
                    ),
                    vx_core::vx_new_string(":close"),
                    vx_data_textblock::c_delimclosing,
                    vx_core::vx_new_string(":parent"),
                    vx_core::f_new(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":text"),
                        vx_core::vx_new_string("<{a,b},{c d}>"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(1),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(13)
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
                            vx_core::vx_new_string("{a,b}"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(2),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(6),
                            vx_core::vx_new_string(":delim"),
                            vx_core::f_copy(
                              vx_data_textblock::t_delim,
                              vx_data_textblock::c_delimbracketcurly,
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
                                    vx_core::vx_new_int(3),
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
                                    vx_core::vx_new_string("b"),
                                    vx_core::vx_new_string(":startpos"),
                                    vx_core::vx_new_int(5),
                                    vx_core::vx_new_string(":endpos"),
                                    vx_core::vx_new_int(5)
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
                            vx_core::vx_new_int(7),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(7),
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
                            vx_core::vx_new_string("{c d}"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(8),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(12),
                            vx_core::vx_new_string(":delim"),
                            vx_core::f_copy(
                              vx_data_textblock::t_delim,
                              vx_data_textblock::c_delimbracketcurly,
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
                                    vx_core::vx_new_string("c"),
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
                                    vx_core::vx_new_string(" "),
                                    vx_core::vx_new_string(":startpos"),
                                    vx_core::vx_new_int(10),
                                    vx_core::vx_new_string(":endpos"),
                                    vx_core::vx_new_int(10),
                                    vx_core::vx_new_string(":delim"),
                                    vx_core::f_copy(
                                      vx_data_textblock::t_delim,
                                      vx_data_textblock::c_delimwhitespace,
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
                                    vx_core::vx_new_string("d"),
                                    vx_core::vx_new_string(":startpos"),
                                    vx_core::vx_new_int(11),
                                    vx_core::vx_new_string(":endpos"),
                                    vx_core::vx_new_int(11)
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
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_22 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :startpos 14\n  :endpos 14\n  :delim\n   (delim\n    :delimlist delimlisttest1)\n  :parent\n   (textblock\n    :text \"<{a,b},{c d}>\"\n    :startpos 1\n    :endpos 13\n    :children\n     (textblocklist\n      (textblock\n       :text \"<{a,b},{c d}>\"\n       :startpos 1\n       :endpos 13\n       :delim\n        (copy delimbracketangle\n         :pos 0)\n       :children\n        (textblocklist\n         (textblock\n          :text \"{a,b}\"\n          :startpos 2\n          :endpos 6\n          :delim\n           (copy delimbracketcurly\n            :pos 0)\n          :children\n           (textblocklist\n            (textblock\n             :text \"a\"\n             :startpos 3\n             :endpos 3)\n            (textblock\n             :text \",\"\n             :startpos 4\n             :endpos 4\n             :delim\n              (copy delimcomma\n               :pos 0))\n            (textblock\n             :text \"b\"\n             :startpos 5\n             :endpos 5)))\n         (textblock\n          :text \",\"\n          :startpos 7\n          :endpos 7\n          :delim\n           (copy delimcomma\n            :pos 0))\n         (textblock\n          :text \"{c d}\"\n          :startpos 8\n          :endpos 12\n          :delim\n           (copy delimbracketcurly\n            :pos 0)\n          :children\n           (textblocklist\n            (textblock\n             :text \"c\"\n             :startpos 9\n             :endpos 9)\n           (textblock\n            :text \" \"\n            :startpos 10\n            :endpos 10\n            :delim\n             (copy delimwhitespace\n              :pos 0))\n           (textblock\n            :text \"d\"\n            :startpos 11\n            :endpos 11))))))))\n (textblock-parse-one\n  (textblock\n   :startpos 13\n   :endpos 13\n   :parent\n    (textblock\n     :startpos 14\n     :endpos 14\n     :delim\n      (delim\n       :delimlist delimlisttest1)\n     :parent\n      (textblock\n       :text \"<{a,b},{c d}>\"\n       :startpos 1\n       :endpos 13\n       :delim\n        (copy delimbracketangle\n         :pos 0)\n       :close delimclosing\n       :parent\n        (textblock\n         :text \"<{a,b},{c d}>\"\n         :startpos 1\n         :endpos 13)\n       :children\n        (textblocklist\n         (textblock\n          :text \"{a,b}\"\n          :startpos 2\n          :endpos 6\n          :delim\n           (copy delimbracketcurly\n            :pos 0)\n          :children\n           (textblocklist\n            (textblock\n             :text \"a\"\n             :startpos 3\n             :endpos 3)\n            (textblock\n             :text \",\"\n             :startpos 4\n             :endpos 4\n             :delim\n              (copy delimcomma\n               :pos 0))\n            (textblock\n             :text \"b\"\n             :startpos 5\n             :endpos 5)))\n         (textblock\n          :text \",\"\n          :startpos 7\n          :endpos 7\n          :delim\n           (copy delimcomma\n            :pos 0))\n         (textblock\n          :text \"{c d}\"\n          :startpos 8\n          :endpos 12\n          :delim\n           (copy delimbracketcurly\n            :pos 0)\n          :children\n           (textblocklist\n            (textblock\n             :text \"c\"\n             :startpos 9\n             :endpos 9)\n           (textblock\n            :text \" \"\n            :startpos 10\n            :endpos 10\n            :delim\n             (copy delimwhitespace\n              :pos 0))\n           (textblock\n            :text \"d\"\n            :startpos 11\n            :endpos 11)))))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_22
    });
    // testdescribe_23
    vx_test::Type_testresult testresult_23 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("<{a,b},{c d}>"),
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
                  vx_core::vx_new_string("<{a,b},{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimbracketangle,
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
                          vx_core::vx_new_string("{a,b}"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(2),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(6),
                          vx_core::vx_new_string(":delim"),
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_textblock::c_delimbracketcurly,
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
                                  vx_core::vx_new_int(3),
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
                                  vx_core::vx_new_string("b"),
                                  vx_core::vx_new_string(":startpos"),
                                  vx_core::vx_new_int(5),
                                  vx_core::vx_new_string(":endpos"),
                                  vx_core::vx_new_int(5)
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
                          vx_core::vx_new_int(7),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(7),
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
                          vx_core::vx_new_string("{c d}"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(8),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(12),
                          vx_core::vx_new_string(":delim"),
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_textblock::c_delimbracketcurly,
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
                                  vx_core::vx_new_string("c"),
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
                                  vx_core::vx_new_string(" "),
                                  vx_core::vx_new_string(":startpos"),
                                  vx_core::vx_new_int(10),
                                  vx_core::vx_new_string(":endpos"),
                                  vx_core::vx_new_int(10),
                                  vx_core::vx_new_string(":delim"),
                                  vx_core::f_copy(
                                    vx_data_textblock::t_delim,
                                    vx_data_textblock::c_delimwhitespace,
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
                                  vx_core::vx_new_string("d"),
                                  vx_core::vx_new_string(":startpos"),
                                  vx_core::vx_new_int(11),
                                  vx_core::vx_new_string(":endpos"),
                                  vx_core::vx_new_int(11)
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
      vx_data_textblock::f_textblock_parse_one(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(14),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(14),
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_data_textblock::c_delimlisttest1
              })
            ),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("<{a,b},{c d}>"),
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
                        vx_core::vx_new_string("<{a,b},{c d}>"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(1),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(13),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_textblock::c_delimbracketangle,
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
                                vx_core::vx_new_string("{a,b}"),
                                vx_core::vx_new_string(":startpos"),
                                vx_core::vx_new_int(2),
                                vx_core::vx_new_string(":endpos"),
                                vx_core::vx_new_int(6),
                                vx_core::vx_new_string(":delim"),
                                vx_core::f_copy(
                                  vx_data_textblock::t_delim,
                                  vx_data_textblock::c_delimbracketcurly,
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
                                        vx_core::vx_new_int(3),
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
                                        vx_core::vx_new_string("b"),
                                        vx_core::vx_new_string(":startpos"),
                                        vx_core::vx_new_int(5),
                                        vx_core::vx_new_string(":endpos"),
                                        vx_core::vx_new_int(5)
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
                                vx_core::vx_new_int(7),
                                vx_core::vx_new_string(":endpos"),
                                vx_core::vx_new_int(7),
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
                                vx_core::vx_new_string("{c d}"),
                                vx_core::vx_new_string(":startpos"),
                                vx_core::vx_new_int(8),
                                vx_core::vx_new_string(":endpos"),
                                vx_core::vx_new_int(12),
                                vx_core::vx_new_string(":delim"),
                                vx_core::f_copy(
                                  vx_data_textblock::t_delim,
                                  vx_data_textblock::c_delimbracketcurly,
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
                                        vx_core::vx_new_string("c"),
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
                                        vx_core::vx_new_string(" "),
                                        vx_core::vx_new_string(":startpos"),
                                        vx_core::vx_new_int(10),
                                        vx_core::vx_new_string(":endpos"),
                                        vx_core::vx_new_int(10),
                                        vx_core::vx_new_string(":delim"),
                                        vx_core::f_copy(
                                          vx_data_textblock::t_delim,
                                          vx_data_textblock::c_delimwhitespace,
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
                                        vx_core::vx_new_string("d"),
                                        vx_core::vx_new_string(":startpos"),
                                        vx_core::vx_new_int(11),
                                        vx_core::vx_new_string(":endpos"),
                                        vx_core::vx_new_int(11)
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
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_23 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"<{a,b},{c d}>\"\n  :startpos 1\n  :endpos 13\n  :children\n   (textblocklist\n    (textblock\n     :text \"<{a,b},{c d}>\"\n     :startpos 1\n     :endpos 13\n     :delim\n      (copy delimbracketangle\n       :pos 0)\n     :children\n      (textblocklist\n       (textblock\n        :text \"{a,b}\"\n        :startpos 2\n        :endpos 6\n        :delim\n         (copy delimbracketcurly\n          :pos 0)\n        :children\n         (textblocklist\n          (textblock\n           :text \"a\"\n           :startpos 3\n           :endpos 3)\n          (textblock\n           :text \",\"\n           :startpos 4\n           :endpos 4\n           :delim\n            (copy delimcomma\n             :pos 0))\n          (textblock\n           :text \"b\"\n           :startpos 5\n           :endpos 5)))\n       (textblock\n        :text \",\"\n        :startpos 7\n        :endpos 7\n        :delim\n         (copy delimcomma\n          :pos 0))\n       (textblock\n        :text \"{c d}\"\n        :startpos 8\n        :endpos 12\n        :delim\n         (copy delimbracketcurly\n          :pos 0)\n        :children\n         (textblocklist\n          (textblock\n           :text \"c\"\n           :startpos 9\n           :endpos 9)\n          (textblock\n           :text \" \"\n           :startpos 10\n           :endpos 10\n           :delim\n            (copy delimwhitespace\n             :pos 0))\n          (textblock\n           :text \"d\"\n           :startpos 11\n           :endpos 11)))))))\n (textblock-parse-one\n  (textblock\n   :startpos 14\n   :endpos 14\n   :delim\n    (delim\n     :delimlist delimlisttest1)\n   :parent\n    (textblock\n     :text \"<{a,b},{c d}>\"\n     :startpos 1\n     :endpos 13\n     :children\n      (textblocklist\n       (textblock\n        :text \"<{a,b},{c d}>\"\n        :startpos 1\n        :endpos 13\n        :delim\n         (copy delimbracketangle\n          :pos 0)\n        :children\n         (textblocklist\n          (textblock\n           :text \"{a,b}\"\n           :startpos 2\n           :endpos 6\n           :delim\n            (copy delimbracketcurly\n             :pos 0)\n           :children\n            (textblocklist\n             (textblock\n              :text \"a\"\n              :startpos 3\n              :endpos 3)\n             (textblock\n              :text \",\"\n              :startpos 4\n              :endpos 4\n              :delim\n               (copy delimcomma\n                :pos 0))\n             (textblock\n              :text \"b\"\n              :startpos 5\n              :endpos 5)))\n          (textblock\n           :text \",\"\n           :startpos 7\n           :endpos 7\n           :delim\n            (copy delimcomma\n             :pos 0))\n          (textblock\n           :text \"{c d}\"\n           :startpos 8\n           :endpos 12\n           :delim\n            (copy delimbracketcurly\n             :pos 0)\n           :children\n            (textblocklist\n             (textblock\n              :text \"c\"\n              :startpos 9\n              :endpos 9)\n            (textblock\n             :text \" \"\n             :startpos 10\n             :endpos 10\n             :delim\n              (copy delimwhitespace\n               :pos 0))\n            (textblock\n             :text \"d\"\n             :startpos 11\n             :endpos 11))))))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_23
    });
    // testdescribe_24
    vx_test::Type_testresult testresult_24 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("<{a,b},{c d}>"),
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
                  vx_core::vx_new_string("<{a,b},{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimbracketangle,
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
                          vx_core::vx_new_string("{a,b}"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(2),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(6),
                          vx_core::vx_new_string(":delim"),
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_textblock::c_delimbracketcurly,
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
                                  vx_core::vx_new_int(3),
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
                                  vx_core::vx_new_string("b"),
                                  vx_core::vx_new_string(":startpos"),
                                  vx_core::vx_new_int(5),
                                  vx_core::vx_new_string(":endpos"),
                                  vx_core::vx_new_int(5)
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
                          vx_core::vx_new_int(7),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(7),
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
                          vx_core::vx_new_string("{c d}"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(8),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(12),
                          vx_core::vx_new_string(":delim"),
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_textblock::c_delimbracketcurly,
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
                                  vx_core::vx_new_string("c"),
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
                                  vx_core::vx_new_string(" "),
                                  vx_core::vx_new_string(":startpos"),
                                  vx_core::vx_new_int(10),
                                  vx_core::vx_new_string(":endpos"),
                                  vx_core::vx_new_int(10),
                                  vx_core::vx_new_string(":delim"),
                                  vx_core::f_copy(
                                    vx_data_textblock::t_delim,
                                    vx_data_textblock::c_delimwhitespace,
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
                                  vx_core::vx_new_string("d"),
                                  vx_core::vx_new_string(":startpos"),
                                  vx_core::vx_new_int(11),
                                  vx_core::vx_new_string(":endpos"),
                                  vx_core::vx_new_int(11)
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
      vx_data_textblock::f_textblock_parse_one(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("<{a,b},{c d}>"),
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
                    vx_core::vx_new_string("<{a,b},{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(1),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimbracketangle,
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
                            vx_core::vx_new_string("{a,b}"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(2),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(6),
                            vx_core::vx_new_string(":delim"),
                            vx_core::f_copy(
                              vx_data_textblock::t_delim,
                              vx_data_textblock::c_delimbracketcurly,
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
                                    vx_core::vx_new_int(3),
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
                                    vx_core::vx_new_string("b"),
                                    vx_core::vx_new_string(":startpos"),
                                    vx_core::vx_new_int(5),
                                    vx_core::vx_new_string(":endpos"),
                                    vx_core::vx_new_int(5)
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
                            vx_core::vx_new_int(7),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(7),
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
                            vx_core::vx_new_string("{c d}"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(8),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(12),
                            vx_core::vx_new_string(":delim"),
                            vx_core::f_copy(
                              vx_data_textblock::t_delim,
                              vx_data_textblock::c_delimbracketcurly,
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
                                    vx_core::vx_new_string("c"),
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
                                    vx_core::vx_new_string(" "),
                                    vx_core::vx_new_string(":startpos"),
                                    vx_core::vx_new_int(10),
                                    vx_core::vx_new_string(":endpos"),
                                    vx_core::vx_new_int(10),
                                    vx_core::vx_new_string(":delim"),
                                    vx_core::f_copy(
                                      vx_data_textblock::t_delim,
                                      vx_data_textblock::c_delimwhitespace,
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
                                    vx_core::vx_new_string("d"),
                                    vx_core::vx_new_string(":startpos"),
                                    vx_core::vx_new_int(11),
                                    vx_core::vx_new_string(":endpos"),
                                    vx_core::vx_new_int(11)
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
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_24 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"<{a,b},{c d}>\"\n  :startpos 1\n  :endpos 13\n  :children\n   (textblocklist\n    (textblock\n     :text \"<{a,b},{c d}>\"\n     :startpos 1\n     :endpos 13\n     :delim\n      (copy delimbracketangle\n       :pos 0)\n     :children\n      (textblocklist\n       (textblock\n        :text \"{a,b}\"\n        :startpos 2\n        :endpos 6\n        :delim\n         (copy delimbracketcurly\n          :pos 0)\n        :children\n         (textblocklist\n          (textblock\n           :text \"a\"\n           :startpos 3\n           :endpos 3)\n          (textblock\n           :text \",\"\n           :startpos 4\n           :endpos 4\n           :delim\n            (copy delimcomma\n             :pos 0))\n          (textblock\n           :text \"b\"\n           :startpos 5\n           :endpos 5)))\n       (textblock\n        :text \",\"\n        :startpos 7\n        :endpos 7\n        :delim\n         (copy delimcomma\n          :pos 0))\n       (textblock\n        :text \"{c d}\"\n        :startpos 8\n        :endpos 12\n        :delim\n         (copy delimbracketcurly\n          :pos 0)\n        :children\n         (textblocklist\n          (textblock\n           :text \"c\"\n           :startpos 9\n           :endpos 9)\n          (textblock\n           :text \" \"\n           :startpos 10\n           :endpos 10\n           :delim\n            (copy delimwhitespace\n             :pos 0))\n          (textblock\n           :text \"d\"\n           :startpos 11\n           :endpos 11)))))))\n (textblock-parse-one\n  (textblock\n   :text \"<{a,b},{c d}>\"\n   :startpos 1\n   :endpos 13\n   :children\n    (textblocklist\n     (textblock\n      :text \"<{a,b},{c d}>\"\n      :startpos 1\n      :endpos 13\n      :delim\n       (copy delimbracketangle\n        :pos 0)\n      :children\n       (textblocklist\n        (textblock\n         :text \"{a,b}\"\n         :startpos 2\n         :endpos 6\n         :delim\n          (copy delimbracketcurly\n           :pos 0)\n         :children\n          (textblocklist\n           (textblock\n            :text \"a\"\n            :startpos 3\n            :endpos 3)\n           (textblock\n            :text \",\"\n            :startpos 4\n            :endpos 4\n            :delim\n             (copy delimcomma\n              :pos 0))\n           (textblock\n            :text \"b\"\n            :startpos 5\n            :endpos 5)))\n        (textblock\n         :text \",\"\n         :startpos 7\n         :endpos 7\n         :delim\n          (copy delimcomma\n           :pos 0))\n        (textblock\n         :text \"{c d}\"\n         :startpos 8\n         :endpos 12\n         :delim\n          (copy delimbracketcurly\n           :pos 0)\n         :children\n          (textblocklist\n           (textblock\n            :text \"c\"\n            :startpos 9\n            :endpos 9)\n           (textblock\n            :text \" \"\n            :startpos 10\n            :endpos 10\n            :delim\n             (copy delimwhitespace\n              :pos 0))\n           (textblock\n            :text \"d\"\n            :startpos 11\n            :endpos 11)))))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_24
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
      testdescribe_9,
      testdescribe_10,
      testdescribe_11,
      testdescribe_12,
      testdescribe_13,
      testdescribe_14,
      testdescribe_15,
      testdescribe_16,
      testdescribe_17,
      testdescribe_18,
      testdescribe_19,
      testdescribe_20,
      testdescribe_21,
      testdescribe_22,
      testdescribe_23,
      testdescribe_24
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

  vx_test::Type_testcase f_textblock_startleft_from_string_delim_offset(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_textblock_startleft_from_string_delim_offset");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("a"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(1),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(1)
        })
      ),
      vx_data_textblock::f_textblock_startleft_from_string_delim_offset(
        vx_core::vx_new_string("a,b"),
        vx_core::f_new(
          vx_data_textblock::t_delim,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":pos"),
            vx_core::vx_new_int(2)
          })
        ),
        vx_core::vx_new_int(0)
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"a\"\n  :startpos 1\n  :endpos 1)\n (textblock-startleft<-string-delim-offset\n  \"a,b\"\n  (delim\n   :pos 2)\n  0))"),
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
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string(",b"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(2),
          vx_core::vx_new_string(":delim"),
          vx_core::f_copy(
            vx_data_textblock::t_delim,
            vx_data_textblock::c_delimcomma,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":pos"),
              vx_core::vx_new_int(2)
            })
          )
        })
      ),
      vx_data_textblock::f_textblock_startright_from_string_delim_offset(
        vx_core::vx_new_string("a,b"),
        vx_core::f_copy(
          vx_data_textblock::t_delim,
          vx_data_textblock::c_delimcomma,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":pos"),
            vx_core::vx_new_int(2)
          })
        ),
        vx_core::vx_new_int(0)
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \",b\"\n  :startpos 2\n  :delim\n   (copy delimcomma\n    :pos 2))\n (textblock-startright<-string-delim-offset\n  \"a,b\"\n  (copy delimcomma\n   :pos 2)\n  0))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("<b>c"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(2),
          vx_core::vx_new_string(":delim"),
          vx_core::f_copy(
            vx_data_textblock::t_delim,
            vx_data_textblock::c_delimbracketangle,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":pos"),
              vx_core::vx_new_int(2),
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
            vx_core::vx_new_string(":pos"),
            vx_core::vx_new_int(2),
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
      )
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"<b>c\"\n  :startpos 2\n  :delim\n   (copy delimbracketangle\n    :pos 2\n    :delimlist\n     (delimlist\n      delimbracketcurly))\n  :close\n   (copy delimclose\n    :starttext \">\"))\n (textblock-startright<-string-delim-offset\n  \"a<b>c\"\n  (copy delimbracketangle\n   :pos 2\n   :delimlist\n    (delimlist\n     delimbracketcurly))\n  0))"),
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

  vx_test::Type_testcase f_textblock_from_close_textblock(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_textblock_from_close_textblock");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("b"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(5),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(5),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string(",{c d}>"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(7),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(13),
              vx_core::vx_new_string(":delim"),
              vx_core::f_new(
                vx_data_textblock::t_delim,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_data_textblock::c_delimlisttest2
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
                  vx_core::vx_new_string("{a,b}"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(2),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(6),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimbracketcurly,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":pos"),
                      vx_core::vx_new_int(0)
                    })
                  ),
                  vx_core::vx_new_string(":close"),
                  vx_data_textblock::c_delimclosing,
                  vx_core::vx_new_string(":parent"),
                  vx_core::f_new(
                    vx_data_textblock::t_textblock,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":text"),
                      vx_core::vx_new_string("<{a,b},{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13),
                      vx_core::vx_new_string(":delim"),
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimbracketangle,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":delimlist"),
                          vx_data_textblock::c_delimlisttest1
                        })
                      ),
                      vx_core::vx_new_string(":parent"),
                      vx_core::f_new(
                        vx_data_textblock::t_textblock,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":text"),
                          vx_core::vx_new_string("<{a,b},{c d}>"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(1),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(13)
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
                          vx_core::vx_new_int(3),
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
                      )
                    })
                  )
                })
              )
            })
          )
        })
      ),
      vx_data_textblock::f_textblock_from_close_textblock(
        vx_core::f_copy(
          vx_data_textblock::t_delim,
          vx_data_textblock::c_delimclose,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":starttext"),
            vx_core::vx_new_string("}"),
            vx_core::vx_new_string(":pos"),
            vx_core::vx_new_int(2)
          })
        ),
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("b},{c d}>"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(5),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(13),
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_data_textblock::c_delimlisttest3
              })
            ),
            vx_core::vx_new_string(":close"),
            vx_core::f_copy(
              vx_data_textblock::t_delim,
              vx_data_textblock::c_delimclose,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":starttext"),
                vx_core::vx_new_string("}")
              })
            ),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("{a,b},{c d}>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(2),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13),
                vx_core::vx_new_string(":delim"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimbracketcurly,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_data_textblock::c_delimlisttest2
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
                    vx_core::vx_new_string("<{a,b},{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(1),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimbracketangle,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":delimlist"),
                        vx_data_textblock::c_delimlisttest1
                      })
                    ),
                    vx_core::vx_new_string(":parent"),
                    vx_core::f_new(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":text"),
                        vx_core::vx_new_string("<{a,b},{c d}>"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(1),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(13)
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
                        vx_core::vx_new_int(3),
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
                    )
                  })
                )
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"b\"\n  :startpos 5\n  :endpos 5\n  :parent\n   (textblock\n    :text \",{c d}>\"\n    :startpos 7\n    :endpos 13\n    :delim\n     (delim\n      :delimlist delimlisttest2)\n    :close\n     (copy delimclose\n      :starttext \">\")\n    :parent\n     (textblock\n      :text \"{a,b}\"\n      :startpos 2\n      :endpos 6\n      :delim\n       (copy delimbracketcurly\n        :pos 0)\n      :close delimclosing\n      :parent\n       (textblock\n        :text \"<{a,b},{c d}>\"\n        :startpos 1\n        :endpos 13\n        :delim\n         (copy delimbracketangle\n          :delimlist delimlisttest1)\n        :parent\n         (textblock\n          :text \"<{a,b},{c d}>\"\n          :startpos 1\n          :endpos 13))\n      :children\n       (textblocklist\n        (textblock\n         :text \"a\"\n         :startpos 3\n         :endpos 3)\n        (textblock\n         :text \",\"\n         :startpos 4\n         :endpos 4\n         :delim\n          (copy delimcomma\n           :pos 0))))))\n (textblock<-close-textblock\n  (copy delimclose\n   :starttext \"}\"\n   :pos 2)\n  (textblock\n   :text \"b},{c d}>\"\n   :startpos 5\n   :endpos 13\n   :delim\n    (delim\n     :delimlist delimlisttest3)\n   :close\n    (copy delimclose\n     :starttext \"}\")\n   :parent\n    (textblock\n     :text \"{a,b},{c d}>\"\n     :startpos 2\n     :endpos 13\n     :delim\n      (copy delimbracketcurly\n       :delimlist delimlisttest2)\n     :close\n      (copy delimclose\n       :starttext \">\")\n     :parent\n      (textblock\n       :text \"<{a,b},{c d}>\"\n       :startpos 1\n       :endpos 13\n       :delim\n        (copy delimbracketangle\n         :delimlist delimlisttest1)\n       :parent\n        (textblock\n         :text \"<{a,b},{c d}>\"\n         :startpos 1\n         :endpos 13))\n     :children\n      (textblocklist\n       (textblock\n        :text \"a\"\n        :startpos 3\n        :endpos 3)\n       (textblock\n        :text \",\"\n        :startpos 4\n        :endpos 4\n        :delim\n         (copy delimcomma\n          :pos 0)))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(13),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(13),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(14),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(14),
              vx_core::vx_new_string(":delim"),
              vx_core::f_new(
                vx_data_textblock::t_delim,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_data_textblock::c_delimlisttest1
                })
              ),
              vx_core::vx_new_string(":parent"),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("<{a,b},{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimbracketangle,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":pos"),
                      vx_core::vx_new_int(0)
                    })
                  ),
                  vx_core::vx_new_string(":close"),
                  vx_data_textblock::c_delimclosing,
                  vx_core::vx_new_string(":parent"),
                  vx_core::f_new(
                    vx_data_textblock::t_textblock,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":text"),
                      vx_core::vx_new_string("<{a,b},{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13)
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
                          vx_core::vx_new_string("{a,b}"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(2),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(6),
                          vx_core::vx_new_string(":delim"),
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_textblock::c_delimbracketcurly,
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
                                  vx_core::vx_new_int(3),
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
                                  vx_core::vx_new_string("b"),
                                  vx_core::vx_new_string(":startpos"),
                                  vx_core::vx_new_int(5),
                                  vx_core::vx_new_string(":endpos"),
                                  vx_core::vx_new_int(5)
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
                          vx_core::vx_new_int(7),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(7),
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
                          vx_core::vx_new_string("{c d}"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(8),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(12),
                          vx_core::vx_new_string(":delim"),
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_textblock::c_delimbracketcurly,
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
                                  vx_core::vx_new_string("c"),
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
                                  vx_core::vx_new_string(" "),
                                  vx_core::vx_new_string(":startpos"),
                                  vx_core::vx_new_int(10),
                                  vx_core::vx_new_string(":endpos"),
                                  vx_core::vx_new_int(10),
                                  vx_core::vx_new_string(":delim"),
                                  vx_core::f_copy(
                                    vx_data_textblock::t_delim,
                                    vx_data_textblock::c_delimwhitespace,
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
                                  vx_core::vx_new_string("d"),
                                  vx_core::vx_new_string(":startpos"),
                                  vx_core::vx_new_int(11),
                                  vx_core::vx_new_string(":endpos"),
                                  vx_core::vx_new_int(11)
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
      vx_data_textblock::f_textblock_from_close_textblock(
        vx_core::f_copy(
          vx_data_textblock::t_delim,
          vx_data_textblock::c_delimclose,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":starttext"),
            vx_core::vx_new_string(">"),
            vx_core::vx_new_string(":pos"),
            vx_core::vx_new_int(1)
          })
        ),
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string(">"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(13),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(13),
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_data_textblock::c_delimlisttest2
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
                vx_core::vx_new_string("<{a,b},{c d}>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(1),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13),
                vx_core::vx_new_string(":delim"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimbracketangle,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_data_textblock::c_delimlisttest1
                  })
                ),
                vx_core::vx_new_string(":parent"),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("<{a,b},{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(1),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13)
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
                        vx_core::vx_new_string("{a,b}"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(2),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(6),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_textblock::c_delimbracketcurly,
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
                                vx_core::vx_new_int(3),
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
                                vx_core::vx_new_string("b"),
                                vx_core::vx_new_string(":startpos"),
                                vx_core::vx_new_int(5),
                                vx_core::vx_new_string(":endpos"),
                                vx_core::vx_new_int(5)
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
                        vx_core::vx_new_int(7),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(7),
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
                        vx_core::vx_new_string("{c d}"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(8),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(12),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_textblock::c_delimbracketcurly,
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
                                vx_core::vx_new_string("c"),
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
                                vx_core::vx_new_string(" "),
                                vx_core::vx_new_string(":startpos"),
                                vx_core::vx_new_int(10),
                                vx_core::vx_new_string(":endpos"),
                                vx_core::vx_new_int(10),
                                vx_core::vx_new_string(":delim"),
                                vx_core::f_copy(
                                  vx_data_textblock::t_delim,
                                  vx_data_textblock::c_delimwhitespace,
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
                                vx_core::vx_new_string("d"),
                                vx_core::vx_new_string(":startpos"),
                                vx_core::vx_new_int(11),
                                vx_core::vx_new_string(":endpos"),
                                vx_core::vx_new_int(11)
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
      )
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :startpos 13\n  :endpos 13\n  :parent\n   (textblock\n    :startpos 14\n    :endpos 14\n    :delim\n     (delim\n      :delimlist delimlisttest1)\n    :parent\n     (textblock\n      :text \"<{a,b},{c d}>\"\n      :startpos 1\n      :endpos 13\n      :delim\n       (copy delimbracketangle\n        :pos 0)\n      :close delimclosing\n      :parent\n       (textblock\n        :text \"<{a,b},{c d}>\"\n        :startpos 1\n        :endpos 13)\n      :children\n       (textblocklist\n        (textblock\n         :text \"{a,b}\"\n         :startpos 2\n         :endpos 6\n         :delim\n          (copy delimbracketcurly\n           :pos 0)\n         :children\n          (textblocklist\n           (textblock\n            :text \"a\"\n            :startpos 3\n            :endpos 3)\n           (textblock\n            :text \",\"\n            :startpos 4\n            :endpos 4\n            :delim\n             (copy delimcomma\n              :pos 0))\n           (textblock\n            :text \"b\"\n            :startpos 5\n            :endpos 5)))\n        (textblock\n         :text \",\"\n         :startpos 7\n         :endpos 7\n         :delim\n          (copy delimcomma\n           :pos 0))\n        (textblock\n         :text \"{c d}\"\n         :startpos 8\n         :endpos 12\n         :delim\n          (copy delimbracketcurly\n           :pos 0)\n         :children\n          (textblocklist\n           (textblock\n            :text \"c\"\n            :startpos 9\n            :endpos 9)\n          (textblock\n           :text \" \"\n           :startpos 10\n           :endpos 10\n           :delim\n            (copy delimwhitespace\n             :pos 0))\n          (textblock\n           :text \"d\"\n           :startpos 11\n           :endpos 11)))))))\n (textblock<-close-textblock\n  (copy delimclose\n   :starttext \">\"\n   :pos 1)\n  (textblock\n   :text \">\"\n   :startpos 13\n   :endpos 13\n   :delim\n    (delim\n     :delimlist delimlisttest2)\n   :close\n    (copy delimclose\n     :starttext \">\")\n   :parent\n    (textblock\n     :text \"<{a,b},{c d}>\"\n     :startpos 1\n     :endpos 13\n     :delim\n      (copy delimbracketangle\n       :delimlist delimlisttest1)\n     :parent\n      (textblock\n       :text \"<{a,b},{c d}>\"\n       :startpos 1\n       :endpos 13)\n     :children\n      (textblocklist\n       (textblock\n        :text \"{a,b}\"\n        :startpos 2\n        :endpos 6\n        :delim\n         (copy delimbracketcurly\n          :pos 0)\n        :children\n         (textblocklist\n          (textblock\n           :text \"a\"\n           :startpos 3\n           :endpos 3)\n          (textblock\n           :text \",\"\n           :startpos 4\n           :endpos 4\n           :delim\n            (copy delimcomma\n             :pos 0))\n          (textblock\n           :text \"b\"\n           :startpos 5\n           :endpos 5)))\n       (textblock\n        :text \",\"\n        :startpos 7\n        :endpos 7\n        :delim\n         (copy delimcomma\n          :pos 0))\n       (textblock\n        :text \"{c d}\"\n        :startpos 8\n        :endpos 12\n        :delim\n         (copy delimbracketcurly\n          :pos 0)\n        :children\n         (textblocklist\n          (textblock\n           :text \"c\"\n           :startpos 9\n           :endpos 9)\n          (textblock\n           :text \" \"\n           :startpos 10\n           :endpos 10\n           :delim\n            (copy delimwhitespace\n             :pos 0))\n          (textblock\n           :text \"d\"\n           :startpos 11\n           :endpos 11))))))))"),
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
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("textblock<-close-textblock"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_textblock_from_close_textblock");
    return output;
  }

  vx_test::Type_testcase f_textblock_from_open_textblock(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_textblock_from_open_textblock");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string(""),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              vx_data_textblock::c_delimlisttest2
            })
          ),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("{a,b},{c d}>"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(2),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(13),
              vx_core::vx_new_string(":delim"),
              vx_core::f_new(
                vx_data_textblock::t_delim,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_data_textblock::c_delimlisttest2
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
                  vx_core::vx_new_string("<{a,b},{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimbracketangle,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      vx_data_textblock::c_delimlisttest1
                    })
                  ),
                  vx_core::vx_new_string(":parent"),
                  vx_core::f_new(
                    vx_data_textblock::t_textblock,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":text"),
                      vx_core::vx_new_string("<{a,b},{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13)
                    })
                  )
                })
              )
            })
          )
        })
      ),
      vx_data_textblock::f_textblock_from_open_textblock(
        vx_core::f_copy(
          vx_data_textblock::t_delim,
          vx_data_textblock::c_delimtest2,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":pos"),
            vx_core::vx_new_int(1)
          })
        ),
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("<{a,b},{c d}>"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(1),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(13),
            vx_core::vx_new_string(":delim"),
            vx_data_textblock::c_delimtest1,
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("<{a,b},{c d}>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(1),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13)
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"\"\n  :delim\n   (delim\n    :delimlist delimlisttest2)\n  :parent\n   (textblock\n    :text \"{a,b},{c d}>\"\n    :startpos 2\n    :endpos 13\n    :delim\n     (delim\n      :delimlist delimlisttest2)\n    :close\n     (copy delimclose\n      :starttext \">\")\n    :parent\n     (textblock\n      :text \"<{a,b},{c d}>\"\n      :startpos 1\n      :endpos 13\n      :delim\n       (copy delimbracketangle\n        :delimlist delimlisttest1)\n      :parent\n       (textblock\n        :text \"<{a,b},{c d}>\"\n        :startpos 1\n        :endpos 13))))\n (textblock<-open-textblock\n  (copy delimtest2\n   :pos 1)\n  (textblock\n   :text \"<{a,b},{c d}>\"\n   :startpos 1\n   :endpos 13\n   :delim delimtest1\n   :parent\n    (textblock\n     :text \"<{a,b},{c d}>\"\n     :startpos 1\n     :endpos 13))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(1),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(1),
          vx_core::vx_new_string(":delim"),
          vx_core::f_new(
            vx_data_textblock::t_delim,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":delimlist"),
              vx_data_textblock::c_delimlisttest3
            })
          ),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("a,b},{c d}>"),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(3),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(13),
              vx_core::vx_new_string(":delim"),
              vx_core::f_new(
                vx_data_textblock::t_delim,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_data_textblock::c_delimlisttest3
                })
              ),
              vx_core::vx_new_string(":close"),
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimclose,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":starttext"),
                  vx_core::vx_new_string("}")
                })
              ),
              vx_core::vx_new_string(":parent"),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("{a,b},{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(2),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimbracketcurly,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      vx_data_textblock::c_delimlisttest2
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
                      vx_core::vx_new_string("<{a,b},{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13),
                      vx_core::vx_new_string(":delim"),
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimbracketangle,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":pos"),
                          vx_core::vx_new_int(0)
                        })
                      ),
                      vx_core::vx_new_string(":parent"),
                      vx_core::f_new(
                        vx_data_textblock::t_textblock,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":text"),
                          vx_core::vx_new_string("<{a,b},{c d}>"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(1),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(13)
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
      vx_data_textblock::f_textblock_from_open_textblock(
        vx_core::f_copy(
          vx_data_textblock::t_delim,
          vx_data_textblock::c_delimtest3,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":pos"),
            vx_core::vx_new_int(1)
          })
        ),
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("{a,b},{c d}>"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(2),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(13),
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_data_textblock::c_delimlisttest2
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
                vx_core::vx_new_string("<{a,b},{c d}>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(1),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13),
                vx_core::vx_new_string(":delim"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimbracketangle,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":pos"),
                    vx_core::vx_new_int(0)
                  })
                ),
                vx_core::vx_new_string(":parent"),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("<{a,b},{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(1),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13)
                  })
                )
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :startpos 1\n  :endpos 1\n  :delim\n   (delim\n    :delimlist delimlisttest3)\n  :parent\n   (textblock\n    :text \"a,b},{c d}>\"\n    :startpos 3\n    :endpos 13\n    :delim\n     (delim\n      :delimlist delimlisttest3)\n    :close\n     (copy delimclose\n      :starttext \"}\")\n    :parent\n     (textblock\n      :text \"{a,b},{c d}>\"\n      :startpos 2\n      :endpos 13\n      :delim\n       (copy delimbracketcurly\n        :delimlist delimlisttest2)\n      :close\n       (copy delimclose\n        :starttext \">\")\n      :parent\n       (textblock\n        :text \"<{a,b},{c d}>\"\n        :startpos 1\n        :endpos 13\n        :delim\n         (copy delimbracketangle\n          :pos 0)\n        :parent\n         (textblock\n          :text \"<{a,b},{c d}>\"\n          :startpos 1\n          :endpos 13)))))\n (textblock<-open-textblock\n  (copy delimtest3\n   :pos 1)\n  (textblock\n   :text \"{a,b},{c d}>\"\n   :startpos 2\n   :endpos 13\n   :delim\n    (delim\n     :delimlist delimlisttest2)\n   :close\n    (copy delimclose\n     :starttext \">\")\n   :parent\n    (textblock\n     :text \"<{a,b},{c d}>\"\n     :startpos 1\n     :endpos 13\n     :delim\n      (copy delimbracketangle\n       :pos 0)\n     :parent\n      (textblock\n       :text \"<{a,b},{c d}>\"\n       :startpos 1\n       :endpos 13)))))"),
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
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("textblock<-open-textblock"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_textblock_from_open_textblock");
    return output;
  }

  vx_test::Type_testcase f_textblock_from_single_textblock(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_textblock_from_single_textblock");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("a"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(3),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(3),
          vx_core::vx_new_string(":parent"),
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
              ),
              vx_core::vx_new_string(":parent"),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("b},{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(5),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_new(
                    vx_data_textblock::t_delim,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      vx_data_textblock::c_delimlisttest3
                    })
                  ),
                  vx_core::vx_new_string(":close"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimclose,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":starttext"),
                      vx_core::vx_new_string("}")
                    })
                  ),
                  vx_core::vx_new_string(":parent"),
                  vx_core::f_new(
                    vx_data_textblock::t_textblock,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":text"),
                      vx_core::vx_new_string("{a,b},{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(2),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13),
                      vx_core::vx_new_string(":delim"),
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimbracketcurly,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":pos"),
                          vx_core::vx_new_int(0)
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
                          vx_core::vx_new_string("<{a,b},{c d}>"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(1),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(13),
                          vx_core::vx_new_string(":delim"),
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_textblock::c_delimbracketangle,
                            vx_core::vx_new(vx_core::t_anylist, {
                              vx_core::vx_new_string(":pos"),
                              vx_core::vx_new_int(0)
                            })
                          ),
                          vx_core::vx_new_string(":parent"),
                          vx_core::f_new(
                            vx_data_textblock::t_textblock,
                            vx_core::vx_new(vx_core::t_anylist, {
                              vx_core::vx_new_string(":text"),
                              vx_core::vx_new_string("<{a,b},{c d}>"),
                              vx_core::vx_new_string(":startpos"),
                              vx_core::vx_new_int(1),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(13)
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
      vx_data_textblock::f_textblock_from_single_textblock(
        vx_core::f_copy(
          vx_data_textblock::t_delim,
          vx_data_textblock::c_delimcomma,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":pos"),
            vx_core::vx_new_int(2)
          })
        ),
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("a,b},{c d}>"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(3),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(13),
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_data_textblock::c_delimlisttest3
              })
            ),
            vx_core::vx_new_string(":close"),
            vx_core::f_copy(
              vx_data_textblock::t_delim,
              vx_data_textblock::c_delimclose,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":starttext"),
                vx_core::vx_new_string("}")
              })
            ),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("{a,b},{c d}>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(2),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13),
                vx_core::vx_new_string(":delim"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimbracketcurly,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":pos"),
                    vx_core::vx_new_int(0)
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
                    vx_core::vx_new_string("<{a,b},{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(1),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimbracketangle,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":pos"),
                        vx_core::vx_new_int(0)
                      })
                    ),
                    vx_core::vx_new_string(":parent"),
                    vx_core::f_new(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":text"),
                        vx_core::vx_new_string("<{a,b},{c d}>"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(1),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(13)
                      })
                    )
                  })
                )
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"a\"\n  :startpos 3\n  :endpos 3\n  :parent\n   (textblock\n    :text \",\"\n    :startpos 4\n    :endpos 4\n    :delim\n     (copy delimcomma\n      :pos 0)\n    :parent\n     (textblock\n      :text \"b},{c d}>\"\n      :startpos 5\n      :endpos 13\n      :delim\n       (delim\n        :delimlist delimlisttest3)\n      :close\n       (copy delimclose\n        :starttext \"}\")\n      :parent\n       (textblock\n        :text \"{a,b},{c d}>\"\n        :startpos 2\n        :endpos 13\n        :delim\n         (copy delimbracketcurly\n          :pos 0)\n        :close\n         (copy delimclose\n          :starttext \">\")\n        :parent\n         (textblock\n          :text \"<{a,b},{c d}>\"\n          :startpos 1\n          :endpos 13\n          :delim\n           (copy delimbracketangle\n            :pos 0)\n          :parent\n           (textblock\n            :text \"<{a,b},{c d}>\"\n            :startpos 1\n            :endpos 13))))))\n (textblock<-single-textblock\n  (copy delimcomma\n   :pos 2)\n  (textblock\n   :text \"a,b},{c d}>\"\n   :startpos 3\n   :endpos 13\n   :delim\n    (delim\n     :delimlist delimlisttest3)\n   :close\n    (copy delimclose\n     :starttext \"}\")\n   :parent\n    (textblock\n     :text \"{a,b},{c d}>\"\n     :startpos 2\n     :endpos 13\n     :delim\n      (copy delimbracketcurly\n       :pos 0)\n     :close\n      (copy delimclose\n       :starttext \">\")\n     :parent\n      (textblock\n       :text \"<{a,b},{c d}>\"\n       :startpos 1\n       :endpos 13\n       :delim\n        (copy delimbracketangle\n         :pos 0)\n       :parent\n        (textblock\n         :text \"<{a,b},{c d}>\"\n         :startpos 1\n         :endpos 13))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(7),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(7),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string(","),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(7),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(7),
              vx_core::vx_new_string(":delim"),
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimcomma,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":pos"),
                  vx_core::vx_new_int(0)
                })
              ),
              vx_core::vx_new_string(":parent"),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("{c d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(8),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_new(
                    vx_data_textblock::t_delim,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      vx_data_textblock::c_delimlisttest3
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
                      vx_core::vx_new_string("<{a,b},{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(1),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13),
                      vx_core::vx_new_string(":delim"),
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimbracketangle,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":pos"),
                          vx_core::vx_new_int(0)
                        })
                      ),
                      vx_core::vx_new_string(":parent"),
                      vx_core::f_new(
                        vx_data_textblock::t_textblock,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":text"),
                          vx_core::vx_new_string("<{a,b},{c d}>"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(1),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(13)
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
                              vx_core::vx_new_string("{a,b}"),
                              vx_core::vx_new_string(":startpos"),
                              vx_core::vx_new_int(2),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(6),
                              vx_core::vx_new_string(":delim"),
                              vx_core::f_copy(
                                vx_data_textblock::t_delim,
                                vx_data_textblock::c_delimbracketcurly,
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
                                      vx_core::vx_new_int(3),
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
                                      vx_core::vx_new_string("b"),
                                      vx_core::vx_new_string(":startpos"),
                                      vx_core::vx_new_int(5),
                                      vx_core::vx_new_string(":endpos"),
                                      vx_core::vx_new_int(5)
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
          )
        })
      ),
      vx_data_textblock::f_textblock_from_single_textblock(
        vx_core::f_copy(
          vx_data_textblock::t_delim,
          vx_data_textblock::c_delimcomma,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":pos"),
            vx_core::vx_new_int(1)
          })
        ),
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string(",{c d}>"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(7),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(13),
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_data_textblock::c_delimlisttest3
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
                vx_core::vx_new_string("<{a,b},{c d}>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(1),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13),
                vx_core::vx_new_string(":delim"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimbracketangle,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":pos"),
                    vx_core::vx_new_int(0)
                  })
                ),
                vx_core::vx_new_string(":parent"),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("<{a,b},{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(1),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13)
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
                        vx_core::vx_new_string("{a,b}"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(2),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(6),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_textblock::c_delimbracketcurly,
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
                                vx_core::vx_new_int(3),
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
                                vx_core::vx_new_string("b"),
                                vx_core::vx_new_string(":startpos"),
                                vx_core::vx_new_int(5),
                                vx_core::vx_new_string(":endpos"),
                                vx_core::vx_new_int(5)
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
      )
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :startpos 7\n  :endpos 7\n  :parent\n   (textblock\n    :text \",\"\n    :startpos 7\n    :endpos 7\n    :delim\n     (copy delimcomma\n      :pos 0)\n    :parent\n     (textblock\n      :text \"{c d}>\"\n      :startpos 8\n      :endpos 13\n      :delim\n       (delim\n        :delimlist delimlisttest3)\n      :close\n       (copy delimclose\n        :starttext \">\")\n      :parent\n       (textblock\n        :text \"<{a,b},{c d}>\"\n        :startpos 1\n        :endpos 13\n        :delim\n         (copy delimbracketangle\n          :pos 0)\n        :parent\n         (textblock\n          :text \"<{a,b},{c d}>\"\n          :startpos 1\n          :endpos 13)\n        :children\n         (textblocklist\n          (textblock\n           :text \"{a,b}\"\n           :startpos 2\n           :endpos 6\n           :delim\n            (copy delimbracketcurly\n           :pos 0)\n           :children\n            (textblocklist\n             (textblock\n              :text \"a\"\n              :startpos 3\n              :endpos 3)\n             (textblock\n              :text \",\"\n              :startpos 4\n              :endpos 4\n              :delim\n               (copy delimcomma\n                :pos 0))\n             (textblock\n              :text \"b\"\n              :startpos 5\n              :endpos 5))))))))\n (textblock<-single-textblock\n  (copy delimcomma\n   :pos 1)\n  (textblock\n   :text \",{c d}>\"\n   :startpos 7\n   :endpos 13\n   :delim\n    (delim\n     :delimlist delimlisttest3)\n   :close\n    (copy delimclose\n     :starttext \">\")\n   :parent\n    (textblock\n     :text \"<{a,b},{c d}>\"\n     :startpos 1\n     :endpos 13\n     :delim\n      (copy delimbracketangle\n       :pos 0)\n     :parent\n      (textblock\n       :text \"<{a,b},{c d}>\"\n       :startpos 1\n       :endpos 13)\n     :children\n      (textblocklist\n       (textblock\n        :text \"{a,b}\"\n        :startpos 2\n        :endpos 6\n        :delim\n         (copy delimbracketcurly\n          :pos 0)\n        :children\n         (textblocklist\n          (textblock\n           :text \"a\"\n           :startpos 3\n           :endpos 3)\n          (textblock\n           :text \",\"\n           :startpos 4\n           :endpos 4\n           :delim\n            (copy delimcomma\n             :pos 0))\n          (textblock\n           :text \"b\"\n           :startpos 5\n           :endpos 5))))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    // testdescribe_3
    vx_test::Type_testresult testresult_3 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("c"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(9),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(9),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string(" "),
              vx_core::vx_new_string(":startpos"),
              vx_core::vx_new_int(10),
              vx_core::vx_new_string(":endpos"),
              vx_core::vx_new_int(10),
              vx_core::vx_new_string(":delim"),
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimwhitespace,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":pos"),
                  vx_core::vx_new_int(0)
                })
              ),
              vx_core::vx_new_string(":parent"),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("d}>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(11),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(13),
                  vx_core::vx_new_string(":delim"),
                  vx_core::f_new(
                    vx_data_textblock::t_delim,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":delimlist"),
                      vx_data_textblock::c_delimlisttest3
                    })
                  ),
                  vx_core::vx_new_string(":close"),
                  vx_core::f_copy(
                    vx_data_textblock::t_delim,
                    vx_data_textblock::c_delimclose,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":starttext"),
                      vx_core::vx_new_string("}")
                    })
                  ),
                  vx_core::vx_new_string(":parent"),
                  vx_core::f_new(
                    vx_data_textblock::t_textblock,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":text"),
                      vx_core::vx_new_string("{c d}>"),
                      vx_core::vx_new_string(":startpos"),
                      vx_core::vx_new_int(8),
                      vx_core::vx_new_string(":endpos"),
                      vx_core::vx_new_int(13),
                      vx_core::vx_new_string(":delim"),
                      vx_core::f_copy(
                        vx_data_textblock::t_delim,
                        vx_data_textblock::c_delimbracketcurly,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":delimlist"),
                          vx_data_textblock::c_delimlisttest2
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
                          vx_core::vx_new_string("<{a,b},{c d}>"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(1),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(13),
                          vx_core::vx_new_string(":delim"),
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_textblock::c_delimbracketangle,
                            vx_core::vx_new(vx_core::t_anylist, {
                              vx_core::vx_new_string(":delimlist"),
                              vx_data_textblock::c_delimlisttest1
                            })
                          ),
                          vx_core::vx_new_string(":parent"),
                          vx_core::f_new(
                            vx_data_textblock::t_textblock,
                            vx_core::vx_new(vx_core::t_anylist, {
                              vx_core::vx_new_string(":text"),
                              vx_core::vx_new_string("<{a,b},{c d}>"),
                              vx_core::vx_new_string(":startpos"),
                              vx_core::vx_new_int(1),
                              vx_core::vx_new_string(":endpos"),
                              vx_core::vx_new_int(13)
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
                                  vx_core::vx_new_string("{a,b}"),
                                  vx_core::vx_new_string(":startpos"),
                                  vx_core::vx_new_int(2),
                                  vx_core::vx_new_string(":endpos"),
                                  vx_core::vx_new_int(6),
                                  vx_core::vx_new_string(":delim"),
                                  vx_core::f_copy(
                                    vx_data_textblock::t_delim,
                                    vx_data_textblock::c_delimbracketcurly,
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
                                          vx_core::vx_new_int(3),
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
                                          vx_core::vx_new_string("b"),
                                          vx_core::vx_new_string(":startpos"),
                                          vx_core::vx_new_int(5),
                                          vx_core::vx_new_string(":endpos"),
                                          vx_core::vx_new_int(5)
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
                                  vx_core::vx_new_int(7),
                                  vx_core::vx_new_string(":endpos"),
                                  vx_core::vx_new_int(7),
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
      vx_data_textblock::f_textblock_from_single_textblock(
        vx_core::f_copy(
          vx_data_textblock::t_delim,
          vx_data_textblock::c_delimwhitespace,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":pos"),
            vx_core::vx_new_int(2)
          })
        ),
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("c d}>"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(9),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(13),
            vx_core::vx_new_string(":delim"),
            vx_core::f_new(
              vx_data_textblock::t_delim,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":delimlist"),
                vx_data_textblock::c_delimlisttest3
              })
            ),
            vx_core::vx_new_string(":close"),
            vx_core::f_copy(
              vx_data_textblock::t_delim,
              vx_data_textblock::c_delimclose,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":starttext"),
                vx_core::vx_new_string("}")
              })
            ),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("{c d}>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(8),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(13),
                vx_core::vx_new_string(":delim"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimbracketcurly,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":delimlist"),
                    vx_data_textblock::c_delimlisttest2
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
                    vx_core::vx_new_string("<{a,b},{c d}>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(1),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(13),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_textblock::c_delimbracketangle,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":delimlist"),
                        vx_data_textblock::c_delimlisttest1
                      })
                    ),
                    vx_core::vx_new_string(":parent"),
                    vx_core::f_new(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":text"),
                        vx_core::vx_new_string("<{a,b},{c d}>"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(1),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(13)
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
                            vx_core::vx_new_string("{a,b}"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(2),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(6),
                            vx_core::vx_new_string(":delim"),
                            vx_core::f_copy(
                              vx_data_textblock::t_delim,
                              vx_data_textblock::c_delimbracketcurly,
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
                                    vx_core::vx_new_int(3),
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
                                    vx_core::vx_new_string("b"),
                                    vx_core::vx_new_string(":startpos"),
                                    vx_core::vx_new_int(5),
                                    vx_core::vx_new_string(":endpos"),
                                    vx_core::vx_new_int(5)
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
                            vx_core::vx_new_int(7),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(7),
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
                        )
                      })
                    )
                  })
                )
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_3 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblock\n  :text \"c\"\n  :startpos 9\n  :endpos 9\n  :parent\n   (textblock\n    :text \" \"\n    :startpos 10\n    :endpos 10\n    :delim\n     (copy delimwhitespace\n      :pos 0)\n    :parent\n     (textblock\n      :text \"d}>\"\n      :startpos 11\n      :endpos 13\n      :delim\n       (delim\n        :delimlist delimlisttest3)\n      :close\n       (copy delimclose\n        :starttext \"}\")\n      :parent\n       (textblock\n        :text \"{c d}>\"\n        :startpos 8\n        :endpos 13\n        :delim\n         (copy delimbracketcurly\n          :delimlist delimlisttest2)\n        :close\n         (copy delimclose\n          :starttext \">\")\n        :parent\n         (textblock\n          :text \"<{a,b},{c d}>\"\n          :startpos 1\n          :endpos 13\n          :delim\n           (copy delimbracketangle\n            :delimlist delimlisttest1)\n          :parent\n           (textblock\n            :text \"<{a,b},{c d}>\"\n            :startpos 1\n            :endpos 13)\n          :children\n           (textblocklist\n            (textblock\n             :text \"{a,b}\"\n             :startpos 2\n             :endpos 6\n             :delim\n              (copy delimbracketcurly\n               :pos 0)\n             :children\n              (textblocklist\n               (textblock\n                :text \"a\"\n                :startpos 3\n                :endpos 3)\n               (textblock\n                :text \",\"\n                :startpos 4\n                :endpos 4\n                :delim\n                 (copy delimcomma\n                  :pos 0))\n               (textblock\n                :text \"b\"\n                :startpos 5\n                :endpos 5)))\n            (textblock\n             :text \",\"\n             :startpos 7\n             :endpos 7\n             :delim\n              (copy delimcomma\n               :pos 0))))))))\n (textblock<-single-textblock\n  (copy delimwhitespace\n   :pos 2)\n  (textblock\n   :text \"c d}>\"\n   :startpos 9\n   :endpos 13\n   :delim\n    (delim\n     :delimlist delimlisttest3)\n     :close\n      (copy delimclose\n       :starttext \"}\")\n     :parent\n      (textblock\n       :text \"{c d}>\"\n       :startpos 8\n       :endpos 13\n       :delim\n        (copy delimbracketcurly\n         :delimlist delimlisttest2)\n       :close\n        (copy delimclose\n         :starttext \">\")\n       :parent\n        (textblock\n         :text \"<{a,b},{c d}>\"\n         :startpos 1\n         :endpos 13\n         :delim\n          (copy delimbracketangle\n           :delimlist delimlisttest1)\n         :parent\n          (textblock\n           :text \"<{a,b},{c d}>\"\n           :startpos 1\n           :endpos 13)\n         :children\n          (textblocklist\n           (textblock\n            :text \"{a,b}\"\n            :startpos 2\n            :endpos 6\n            :delim\n             (copy delimbracketcurly\n              :pos 0)\n            :children\n             (textblocklist\n              (textblock\n               :text \"a\"\n               :startpos 3\n               :endpos 3)\n              (textblock\n               :text \",\"\n               :startpos 4\n               :endpos 4\n               :delim\n                (copy delimcomma\n                 :pos 0))\n              (textblock\n               :text \"b\"\n               :startpos 5\n               :endpos 5)))\n           (textblock\n            :text \",\"\n            :startpos 7\n            :endpos 7\n            :delim\n             (copy delimcomma\n              :pos 0))))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_3
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2,
      testdescribe_3
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("textblock<-single-textblock"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_textblock_from_single_textblock");
    return output;
  }

  vx_test::Type_testcase f_textblock_from_string_delim(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_textblock_from_string_delim");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
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
      )
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

  vx_test::Type_testcase f_textblocklist_from_textblocklist_remove(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_textblocklist_from_textblocklist_remove");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblocklist,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("+")
            })
          ),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("2")
            })
          ),
          vx_core::f_new(
            vx_data_textblock::t_textblock,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("3")
            })
          )
        })
      ),
      vx_data_textblock::f_textblocklist_from_textblocklist_remove(
        vx_core::f_new(
          vx_data_textblock::t_textblocklist,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("+")
              })
            ),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string(" "),
                vx_core::vx_new_string(":delim"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimwhitespace,
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
                vx_core::vx_new_string("2")
              })
            ),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string(" "),
                vx_core::vx_new_string(":delim"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_textblock::c_delimwhitespace,
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
                vx_core::vx_new_string("3")
              })
            )
          })
        ),
        vx_data_textblock::c_delimwhitespace
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (textblocklist\n  (textblock\n   :text \"+\")\n  (textblock\n   :text \"2\")\n  (textblock\n   :text \"3\"))\n (textblocklist<-textblocklist-remove\n  (textblocklist\n   (textblock\n    :text \"+\")\n   (textblock\n    :text \" \"\n    :delim\n     (copy delimwhitespace\n      :pos 0))\n   (textblock\n    :text \"2\")\n   (textblock\n    :text \" \"\n    :delim\n     (copy delimwhitespace\n      :pos 0))\n   (textblock\n    :text \"3\"))\n  delimwhitespace))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/textblock"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("textblocklist<-textblocklist-remove"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_textblocklist_from_textblocklist_remove");
    return output;
  }

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {
    vx_core::vx_Type_listany listtestcase;
    listtestcase.push_back(vx_data_textblock_test::t_delimlist(context));
    listtestcase.push_back(vx_data_textblock_test::f_delim_first_from_delim_delim(context));
    listtestcase.push_back(vx_data_textblock_test::f_delim_first_from_string_delimlist(context));
    listtestcase.push_back(vx_data_textblock_test::f_delim_pos_from_string_delim(context));
    listtestcase.push_back(vx_data_textblock_test::f_delimlist_pos_from_string_delimlist(context));
    listtestcase.push_back(vx_data_textblock_test::f_stringlist_from_textblocklist(context));
    listtestcase.push_back(vx_data_textblock_test::f_text_from_textblock(context));
    listtestcase.push_back(vx_data_textblock_test::f_textblock_delimnotfound(context));
    listtestcase.push_back(vx_data_textblock_test::f_textblock_init(context));
    listtestcase.push_back(vx_data_textblock_test::f_textblock_parse(context));
    listtestcase.push_back(vx_data_textblock_test::f_textblock_parse_one(context));
    listtestcase.push_back(vx_data_textblock_test::f_textblock_startleft_from_string_delim_offset(context));
    listtestcase.push_back(vx_data_textblock_test::f_textblock_startright_from_string_delim_offset(context));
    listtestcase.push_back(vx_data_textblock_test::f_textblock_from_close_textblock(context));
    listtestcase.push_back(vx_data_textblock_test::f_textblock_from_open_textblock(context));
    listtestcase.push_back(vx_data_textblock_test::f_textblock_from_single_textblock(context));
    listtestcase.push_back(vx_data_textblock_test::f_textblock_from_string_delim(context));
    listtestcase.push_back(vx_data_textblock_test::f_textblocklist_from_textblocklist_remove(context));
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
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(22)
      }),
      vx_core::vx_new_string(":docnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(100), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(53), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(53)
      }),
      vx_core::vx_new_string(":funcnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(62), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(17), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(27)
      }),
      vx_core::vx_new_string(":bigospacenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(3), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(1), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(27)
      }),
      vx_core::vx_new_string(":bigotimenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(3), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(1), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(27)
      }),
      vx_core::vx_new_string(":totalnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(33), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(18), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(53)
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
        vx_core::vx_new_string(":delimclosing"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimcomma"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimcomment"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimcommentblock"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimline"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimlisttest1"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimlisttest2"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimlisttest3"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimnonwhitespace"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimparen"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimquote"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimquoteblock"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimspace"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimtest1"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimtest2"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimtest3"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimtext"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimwhitespace"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":funcmap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":children<-textblock"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delim-first<-delim-delim"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":delim-first<-string-delimlist"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":delim-pos<-string-delim"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":delimlist-pos<-string-delimlist"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":is-close"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":is-single"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":stringlist<-textblocklist"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":text<-textblock"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":textblock-addchild<-textblock-find-child"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":textblock-delimnotfound"), vx_core::vx_new_int(4),
        vx_core::vx_new_string(":textblock-findparent<-textblock"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":textblock-groupby<-textblock-delim"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":textblock-init"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":textblock-parse"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":textblock-parse-one"), vx_core::vx_new_int(24),
        vx_core::vx_new_string(":textblock-parse<-string-delim"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":textblock-replace<-textblock-find-replace"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":textblock-startleft<-string-delim-offset"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":textblock-startright<-string-delim-offset"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":textblock<-close-textblock"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":textblock<-empty-textblock"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":textblock<-open-textblock"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":textblock<-single-textblock"), vx_core::vx_new_int(3),
        vx_core::vx_new_string(":textblock<-string-delim"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":textblock<-textblock-delim"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":textblocklist<-textblocklist-remove"), vx_core::vx_new_int(1)
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
