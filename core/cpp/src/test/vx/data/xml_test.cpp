#include "../../../main/vx/data/xml.hpp"
#include "../../../main/vx/core.hpp"
#include "../../../main/vx/test.hpp"
#include "../../../main/vx/data/file.hpp"
#include "../../../main/vx/data/textblock.hpp"
#include "../../../main/vx/type.hpp"
#include "xml_test.hpp"

namespace vx_data_xml_test {


  vx_test::Type_testcase f_string_first_from_xml(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_string_first_from_xml");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::vx_new_string("text"),
      vx_data_xml::f_string_first_from_xml(
        vx_core::f_new(
          vx_data_xml::t_xml,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":children"),
            vx_core::f_new(
              vx_data_xml::t_xmllist,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::f_new(
                  vx_data_xml::t_xml,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("text")
                  })
                )
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"text\"\n (string-first<-xml\n  (xml\n   :children\n    (xmllist\n     (xml\n      :text \"text\")))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("string-first<-xml"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_string_first_from_xml");
    return output;
  }

  vx_test::Type_testcase f_textblock_xml_from_string(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_textblock_xml_from_string");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_textblock::t_textblock,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("<doc>\n  <tag1>\n    <tag2 prop1=\"val1\" prop2=\"val2\" />\n  </tag1>\n</doc>"),
          vx_core::vx_new_string(":startpos"),
          vx_core::vx_new_int(1),
          vx_core::vx_new_string(":endpos"),
          vx_core::vx_new_int(70),
          vx_core::vx_new_string(":children"),
          vx_core::f_new(
            vx_data_textblock::t_textblocklist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("<doc>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(1),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(5),
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
                          vx_core::vx_new_string("doc"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(2),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(4)
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
                  vx_core::vx_new_string("\n  "),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(6),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(8)
                })
              ),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("<tag1>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(9),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(14),
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
                          vx_core::vx_new_string("tag1"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(10),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(13)
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
                  vx_core::vx_new_string("\n    "),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(15),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(19)
                })
              ),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("<tag2 prop1=\"val1\" prop2=\"val2\" />"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(20),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(53),
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
                          vx_core::vx_new_string("tag2"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(21),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(24)
                        })
                      ),
                      vx_core::f_new(
                        vx_data_textblock::t_textblock,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":text"),
                          vx_core::vx_new_string(" "),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(25),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(25),
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
                          vx_core::vx_new_string("prop1"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(26),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(30)
                        })
                      ),
                      vx_core::f_new(
                        vx_data_textblock::t_textblock,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":text"),
                          vx_core::vx_new_string("="),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(31),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(31),
                          vx_core::vx_new_string(":delim"),
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_xml::c_delimxmlequal,
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
                          vx_core::vx_new_string("\"val1\""),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(32),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(37),
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
                                  vx_core::vx_new_string("val1"),
                                  vx_core::vx_new_string(":startpos"),
                                  vx_core::vx_new_int(33),
                                  vx_core::vx_new_string(":endpos"),
                                  vx_core::vx_new_int(36)
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
                          vx_core::vx_new_string(" "),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(38),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(38),
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
                          vx_core::vx_new_string("prop2"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(39),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(43)
                        })
                      ),
                      vx_core::f_new(
                        vx_data_textblock::t_textblock,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":text"),
                          vx_core::vx_new_string("="),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(44),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(44),
                          vx_core::vx_new_string(":delim"),
                          vx_core::f_copy(
                            vx_data_textblock::t_delim,
                            vx_data_xml::c_delimxmlequal,
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
                          vx_core::vx_new_string("\"val2\""),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(45),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(50),
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
                                  vx_core::vx_new_string("val2"),
                                  vx_core::vx_new_string(":startpos"),
                                  vx_core::vx_new_int(46),
                                  vx_core::vx_new_string(":endpos"),
                                  vx_core::vx_new_int(49)
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
                          vx_core::vx_new_string(" "),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(51),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(51),
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
                          vx_core::vx_new_string("/"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(52),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(52)
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
                  vx_core::vx_new_string("\n  "),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(54),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(56)
                })
              ),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("</tag1>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(57),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(63),
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
                          vx_core::vx_new_string("/tag1"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(58),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(62)
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
                  vx_core::vx_new_int(64),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(64)
                })
              ),
              vx_core::f_new(
                vx_data_textblock::t_textblock,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("</doc>"),
                  vx_core::vx_new_string(":startpos"),
                  vx_core::vx_new_int(65),
                  vx_core::vx_new_string(":endpos"),
                  vx_core::vx_new_int(70),
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
                          vx_core::vx_new_string("/doc"),
                          vx_core::vx_new_string(":startpos"),
                          vx_core::vx_new_int(66),
                          vx_core::vx_new_string(":endpos"),
                          vx_core::vx_new_int(69)
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
      vx_data_xml::f_textblock_xml_from_string(vx_core::vx_new_string("<doc>\n  <tag1>\n    <tag2 prop1=\"val1\" prop2=\"val2\" />\n  </tag1>\n</doc>"))
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (tb/textblock\n  :text\n   \"<doc>\n      <tag1>\n        <tag2 prop1=\\\"val1\\\" prop2=\\\"val2\\\" />\n      </tag1>\n    </doc>\"\n  :startpos 1\n  :endpos 70\n  :children\n   (tb/textblocklist\n    (tb/textblock\n     :text \"<doc>\"\n     :startpos 1\n     :endpos 5\n     :delim\n      (copy tb/delimbracketangle\n       :pos 0)\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"doc\"\n        :startpos 2\n        :endpos 4)))\n    (tb/textblock\n     :text \"\n  \"\n     :startpos 6\n     :endpos 8)\n    (tb/textblock\n     :text \"<tag1>\"\n     :startpos 9\n     :endpos 14\n     :delim\n      (copy tb/delimbracketangle\n       :pos 0)\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"tag1\"\n        :startpos 10\n        :endpos 13)))\n    (tb/textblock\n     :text \"\n    \"\n     :startpos 15\n     :endpos 19)\n    (tb/textblock\n     :text \"<tag2 prop1=\\\"val1\\\" prop2=\\\"val2\\\" />\"\n     :startpos 20\n     :endpos 53\n     :delim\n      (copy tb/delimbracketangle\n       :pos 0)\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"tag2\"\n        :startpos 21\n        :endpos 24)\n       (tb/textblock\n        :text \" \"\n        :startpos 25\n        :endpos 25\n        :delim\n         (copy tb/delimwhitespace\n          :pos 0))\n       (textblock\n        :text \"prop1\"\n        :startpos 26\n        :endpos 30)\n       (textblock\n        :text \"=\"\n        :startpos 31\n        :endpos 31\n        :delim\n         (copy delimxmlequal\n          :pos 0))\n       (tb/textblock\n        :text \"\\\"val1\\\"\"\n        :startpos 32\n        :endpos 37\n        :delim\n         (copy tb/delimquote\n          :pos 0)\n        :children\n         (tb/textblocklist\n          (tb/textblock\n           :text \"val1\"\n           :startpos 33\n           :endpos 36)))\n       (tb/textblock\n        :text \" \"\n        :startpos 38\n        :endpos 38\n        :delim\n         (copy tb/delimwhitespace\n          :pos 0))\n       (tb/textblock\n        :text \"prop2\"\n        :startpos 39\n        :endpos 43)\n       (textblock\n        :text \"=\"\n        :startpos 44\n        :endpos 44\n        :delim\n         (copy delimxmlequal\n          :pos 0))\n       (tb/textblock\n        :text \"\\\"val2\\\"\"\n        :startpos 45\n        :endpos 50\n        :delim\n         (copy tb/delimquote\n          :pos 0)\n        :children\n         (tb/textblocklist\n          (tb/textblock\n           :text \"val2\"\n           :startpos 46\n           :endpos 49)))\n        (tb/textblock\n         :text \" \"\n         :startpos 51\n         :endpos 51\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"/\"\n         :startpos 52\n         :endpos 52)))\n    (tb/textblock\n     :text \"\n  \"\n     :startpos 54\n     :endpos 56)\n    (tb/textblock\n     :text \"</tag1>\"\n     :startpos 57\n     :endpos 63\n     :delim\n      (copy tb/delimbracketangle\n       :pos 0)\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"/tag1\"\n        :startpos 58\n        :endpos 62)))\n    (tb/textblock\n     :text \"\n\"\n     :startpos 64\n     :endpos 64)\n    (tb/textblock\n     :text \"</doc>\"\n     :startpos 65\n     :endpos 70\n     :delim\n      (copy tb/delimbracketangle\n       :pos 0)\n     :children\n      (tb/textblocklist\n       (tb/textblock\n        :text \"/doc\"\n        :startpos 66\n        :endpos 69)))))\n (textblock-xml<-string\n  \"<doc>\n     <tag1>\n       <tag2 prop1=\\\"val1\\\" prop2=\\\"val2\\\" />\n     </tag1>\n   </doc>\"))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("textblock-xml<-string"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_textblock_xml_from_string");
    return output;
  }

  vx_test::Type_testcase f_xml_angle_from_xml_textblock(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_xml_angle_from_xml_textblock");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_xml::t_xml,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":tag"),
          vx_core::vx_new_string(":notag")
        })
      ),
      vx_data_xml::f_xml_angle_from_xml_textblock(
        vx_core::f_empty(
          vx_data_xml::t_xml
        ),
        vx_core::f_empty(
          vx_data_textblock::t_textblock
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (xml\n  :tag :notag)\n (xml-angle<-xml-textblock\n  (empty xml)\n  (empty tb/textblock)))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_xml::t_xml,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":tag"),
          vx_core::vx_new_string("doc")
        })
      ),
      vx_data_xml::f_xml_angle_from_xml_textblock(
        vx_core::f_empty(
          vx_data_xml::t_xml
        ),
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("<doc>"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(1),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(5),
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
                    vx_core::vx_new_string("doc"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(2),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(4)
                  })
                )
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (xml\n  :tag \"doc\")\n (xml-angle<-xml-textblock\n  (empty xml)\n  (tb/textblock\n   :text \"<doc>\"\n   :startpos 1\n   :endpos 5\n   :delim\n    (copy tb/delimbracketangle\n     :pos 0)\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"doc\"\n      :startpos 2\n      :endpos 4)))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    // testdescribe_3
    vx_test::Type_testresult testresult_3 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_xml::t_xml,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":tag"),
          vx_core::vx_new_string("tag1"),
          vx_core::vx_new_string(":children"),
          vx_core::f_new(
            vx_data_xml::t_xmllist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::f_new(
                vx_data_xml::t_xml,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":tag"),
                  vx_core::vx_new_string("tag2"),
                  vx_core::vx_new_string(":propmap"),
                  vx_core::f_new(
                    vx_core::t_stringmap,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":prop1"),
                      vx_core::vx_new_string("val1"),
                      vx_core::vx_new_string(":prop2"),
                      vx_core::vx_new_string("val2")
                    })
                  )
                })
              )
            })
          )
        })
      ),
      vx_data_xml::f_xml_angle_from_xml_textblock(
        vx_core::f_new(
          vx_data_xml::t_xml,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":tag"),
            vx_core::vx_new_string("tag1")
          })
        ),
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("<tag2 prop1=\"val1\" prop2=\"val2\" />"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(20),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(53),
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
                    vx_core::vx_new_string("tag2"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(21),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(24)
                  })
                ),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string(" "),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(25),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(25),
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
                    vx_core::vx_new_string("prop1"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(26),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(30)
                  })
                ),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("="),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(31),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(31),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_xml::c_delimxmlequal,
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
                    vx_core::vx_new_string("\"val1\""),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(32),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(37),
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
                            vx_core::vx_new_string("val1"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(33),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(36)
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
                    vx_core::vx_new_string(" "),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(38),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(38),
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
                    vx_core::vx_new_string("prop2"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(39),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(43)
                  })
                ),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("="),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(44),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(44),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_xml::c_delimxmlequal,
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
                    vx_core::vx_new_string("\"val2\""),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(45),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(50),
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
                            vx_core::vx_new_string("val2"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(46),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(49)
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
                    vx_core::vx_new_string(" "),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(51),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(51),
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
                    vx_core::vx_new_string("/"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(52),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(52)
                  })
                )
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_3 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (xml\n  :tag \"tag1\"\n  :children\n   (xmllist\n    (xml\n     :tag \"tag2\"\n     :propmap\n      (stringmap\n       :prop1 \"val1\"\n       :prop2 \"val2\"))))\n (xml-angle<-xml-textblock\n  (xml\n   :tag \"tag1\")\n  (tb/textblock\n   :text \"<tag2 prop1=\\\"val1\\\" prop2=\\\"val2\\\" />\"\n   :startpos 20\n   :endpos 53\n   :delim\n    (copy tb/delimbracketangle\n     :pos 0)\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"tag2\"\n      :startpos 21\n      :endpos 24)\n     (tb/textblock\n      :text \" \"\n      :startpos 25\n      :endpos 25\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"prop1\"\n      :startpos 26\n      :endpos 30)\n     (tb/textblock\n      :text \"=\"\n      :startpos 31\n      :endpos 31\n      :delim\n       (copy delimxmlequal\n        :pos 0))\n     (tb/textblock\n      :text \"\\\"val1\\\"\"\n      :startpos 32\n      :endpos 37\n      :delim\n       (copy tb/delimquote\n        :pos 0)\n      :children\n       (tb/textblocklist\n        (tb/textblock\n         :text \"val1\"\n         :startpos 33\n         :endpos 36)))\n     (tb/textblock\n      :text \" \"\n      :startpos 38\n      :endpos 38\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"prop2\"\n      :startpos 39\n      :endpos 43)\n     (tb/textblock\n      :text \"=\"\n      :startpos 44\n      :endpos 44\n      :delim\n       (copy delimxmlequal\n        :pos 0))\n     (tb/textblock\n      :text \"\\\"val2\\\"\"\n      :startpos 45\n      :endpos 50\n      :delim\n       (copy tb/delimquote\n        :pos 0)\n      :children\n       (tb/textblocklist\n        (tb/textblock\n         :text \"val2\"\n         :startpos 46\n         :endpos 49)))\n      (tb/textblock\n       :text \" \"\n       :startpos 51\n       :endpos 51\n       :delim\n        (copy tb/delimwhitespace\n         :pos 0))\n      (tb/textblock\n       :text \"/\"\n       :startpos 52\n       :endpos 52)))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":testresult"), testresult_3
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2,
      testdescribe_3
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("xml-angle<-xml-textblock"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_xml_angle_from_xml_textblock");
    return output;
  }

  vx_test::Type_testcase f_xml_close_from_xml_textblock(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_xml_close_from_xml_textblock");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_xml::t_xml,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":tag"),
          vx_core::vx_new_string("doc")
        })
      ),
      vx_data_xml::f_xml_close_from_xml_textblock(
        vx_core::f_new(
          vx_data_xml::t_xml,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":tag"),
            vx_core::vx_new_string("doc")
          })
        ),
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("/")
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (xml\n  :tag \"doc\")\n (xml-close<-xml-textblock\n  (xml\n   :tag \"doc\")\n  (tb/textblock\n   :text \"/\")))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_xml::t_xml,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":tag"),
          vx_core::vx_new_string("doc")
        })
      ),
      vx_data_xml::f_xml_close_from_xml_textblock(
        vx_core::f_new(
          vx_data_xml::t_xml,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":tag"),
            vx_core::vx_new_string("doc")
          })
        ),
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("</doc>")
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (xml\n  :tag \"doc\")\n (xml-close<-xml-textblock\n  (xml\n   :tag \"doc\")\n  (tb/textblock\n   :text \"</doc>\")))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    // testdescribe_3
    vx_test::Type_testresult testresult_3 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_xml::t_xml,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":tag"),
          vx_core::vx_new_string("doc"),
          vx_core::f_new(
            vx_core::t_msg,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":severity"),
              vx_core::vx_new_int(2),
              vx_core::vx_new_string(":text"),
              vx_core::vx_new_string("Invalid Xml Close tag: /wrong")
            })
          )
        })
      ),
      vx_data_xml::f_xml_close_from_xml_textblock(
        vx_core::f_new(
          vx_data_xml::t_xml,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":tag"),
            vx_core::vx_new_string("doc")
          })
        ),
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("/wrong")
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_3 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (xml\n  :tag \"doc\"\n  (msg\n   :severity 2\n   :text \"Invalid Xml Close tag: /wrong\"))\n (xml-close<-xml-textblock\n  (xml\n   :tag \"doc\")\n  (tb/textblock\n   :text \"/wrong\")))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":testresult"), testresult_3
    });
    // testdescribe_4
    vx_test::Type_testresult testresult_4 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_xml::t_xml,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":tag"),
          vx_core::vx_new_string("top"),
          vx_core::vx_new_string(":children"),
          vx_core::f_new(
            vx_data_xml::t_xmllist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::f_new(
                vx_data_xml::t_xml,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":tag"),
                  vx_core::vx_new_string("doc")
                })
              )
            })
          )
        })
      ),
      vx_data_xml::f_xml_close_from_xml_textblock(
        vx_core::f_new(
          vx_data_xml::t_xml,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":tag"),
            vx_core::vx_new_string("doc"),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_xml::t_xml,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":tag"),
                vx_core::vx_new_string("top")
              })
            )
          })
        ),
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("/")
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_4 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (xml\n  :tag \"top\"\n  :children\n   (xmllist\n    (xml\n     :tag \"doc\")))\n (xml-close<-xml-textblock\n  (xml\n   :tag \"doc\"\n   :parent\n    (xml\n     :tag \"top\"))\n  (tb/textblock\n   :text \"/\")))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
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
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("xml-close<-xml-textblock"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_xml_close_from_xml_textblock");
    return output;
  }

  vx_test::Type_testcase f_xml_parse_from_xml_textblock(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_xml_parse_from_xml_textblock");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_xml::t_xml,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":tag"),
          vx_core::vx_new_string("doc")
        })
      ),
      vx_data_xml::f_xml_parse_from_xml_textblock(
        vx_core::f_empty(
          vx_data_xml::t_xml
        ),
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("<doc>"),
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
                    vx_core::vx_new_string("doc")
                  })
                )
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (xml\n  :tag \"doc\")\n (xml-parse<-xml-textblock\n  (empty xml)\n  (tb/textblock\n   :text \"<doc>\"\n   :delim\n    (copy tb/delimbracketangle\n     :pos 0)\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"doc\")))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_xml::t_xml,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":tag"),
          vx_core::vx_new_string("doc")
        })
      ),
      vx_data_xml::f_xml_parse_from_xml_textblock(
        vx_core::f_new(
          vx_data_xml::t_xml,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":tag"),
            vx_core::vx_new_string("doc")
          })
        ),
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("\n  "),
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
      )
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (xml\n  :tag \"doc\")\n (xml-parse<-xml-textblock\n  (xml\n   :tag \"doc\")\n  (tb/textblock\n   :text \"\n  \"\n   :delim\n    (copy tb/delimwhitespace\n     :pos 0))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    // testdescribe_3
    vx_test::Type_testresult testresult_3 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_xml::t_xml,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":tag"),
          vx_core::vx_new_string("tag1"),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_xml::t_xml,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":tag"),
              vx_core::vx_new_string("doc")
            })
          )
        })
      ),
      vx_data_xml::f_xml_parse_from_xml_textblock(
        vx_core::f_new(
          vx_data_xml::t_xml,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":tag"),
            vx_core::vx_new_string("doc")
          })
        ),
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("<tag1>"),
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
                    vx_core::vx_new_string("tag1")
                  })
                )
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_3 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (xml\n  :tag \"tag1\"\n  :parent\n   (xml\n    :tag \"doc\"))\n (xml-parse<-xml-textblock\n  (xml\n   :tag \"doc\")\n  (tb/textblock\n   :text \"<tag1>\"\n   :delim\n    (copy tb/delimbracketangle\n     :pos 0)\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"tag1\")))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":testresult"), testresult_3
    });
    // testdescribe_4
    vx_test::Type_testresult testresult_4 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_xml::t_xml,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":tag"),
          vx_core::vx_new_string("tag1"),
          vx_core::vx_new_string(":children"),
          vx_core::f_new(
            vx_data_xml::t_xmllist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::f_new(
                vx_data_xml::t_xml,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":tag"),
                  vx_core::vx_new_string("tag2"),
                  vx_core::vx_new_string(":propmap"),
                  vx_core::f_new(
                    vx_core::t_stringmap,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":prop1"),
                      vx_core::vx_new_string("val1"),
                      vx_core::vx_new_string(":prop2"),
                      vx_core::vx_new_string("val2")
                    })
                  )
                })
              )
            })
          ),
          vx_core::vx_new_string(":parent"),
          vx_core::f_new(
            vx_data_xml::t_xml,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":tag"),
              vx_core::vx_new_string("doc")
            })
          )
        })
      ),
      vx_data_xml::f_xml_parse_from_xml_textblock(
        vx_core::f_new(
          vx_data_xml::t_xml,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":tag"),
            vx_core::vx_new_string("tag1"),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_xml::t_xml,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":tag"),
                vx_core::vx_new_string("doc")
              })
            )
          })
        ),
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("<tag2 prop1=\"val1\" prop2=\"val2\" />"),
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
                    vx_core::vx_new_string("tag2")
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
                    vx_core::vx_new_string("prop1")
                  })
                ),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("="),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_xml::c_delimxmlequal,
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
                    vx_core::vx_new_string("\"val1\""),
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
                            vx_core::vx_new_string("val1")
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
                    vx_core::vx_new_string("prop2")
                  })
                ),
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("="),
                    vx_core::vx_new_string(":delim"),
                    vx_core::f_copy(
                      vx_data_textblock::t_delim,
                      vx_data_xml::c_delimxmlequal,
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
                    vx_core::vx_new_string("\"val2\""),
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
                            vx_core::vx_new_string("val2")
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
                    vx_core::vx_new_string("/")
                  })
                )
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_4 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (xml\n  :tag \"tag1\"\n  :children\n   (xmllist\n    (xml\n     :tag \"tag2\"\n     :propmap\n      (stringmap\n       :prop1 \"val1\"\n       :prop2 \"val2\")))\n  :parent\n   (xml\n    :tag \"doc\"))\n (xml-parse<-xml-textblock\n  (xml\n   :tag \"tag1\"\n   :parent\n    (xml\n     :tag \"doc\"))\n  (tb/textblock\n   :text \"<tag2 prop1=\\\"val1\\\" prop2=\\\"val2\\\" />\"\n   :delim\n    (copy tb/delimbracketangle\n     :pos 0)\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"tag2\")\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"prop1\")\n     (tb/textblock\n      :text \"=\"\n      :delim\n       (copy delimxmlequal\n        :pos 0))\n     (tb/textblock\n      :text \"\\\"val1\\\"\"\n      :delim\n       (copy tb/delimquote\n        :pos 0)\n      :children\n       (tb/textblocklist\n        (tb/textblock\n         :text \"val1\")))\n     (tb/textblock\n      :text \" \"\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"prop2\")\n     (tb/textblock\n      :text \"=\"\n      :delim\n       (copy delimxmlequal\n        :pos 0))\n     (tb/textblock\n      :text \"\\\"val2\\\"\"\n      :delim\n       (copy tb/delimquote\n        :pos 0)\n      :children\n       (tb/textblocklist\n        (tb/textblock\n         :text \"val2\")))\n      (tb/textblock\n       :text \" \"\n       :delim\n        (copy tb/delimwhitespace\n         :pos 0))\n      (tb/textblock\n       :text \"/\")))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":testresult"), testresult_4
    });
    // testdescribe_5
    vx_test::Type_testresult testresult_5 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_xml::t_xml,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":tag"),
          vx_core::vx_new_string("doc"),
          vx_core::vx_new_string(":children"),
          vx_core::f_new(
            vx_data_xml::t_xmllist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::f_new(
                vx_data_xml::t_xml,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":tag"),
                  vx_core::vx_new_string("tag1"),
                  vx_core::vx_new_string(":children"),
                  vx_core::f_new(
                    vx_data_xml::t_xmllist,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::f_new(
                        vx_data_xml::t_xml,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":tag"),
                          vx_core::vx_new_string("tag2"),
                          vx_core::vx_new_string(":propmap"),
                          vx_core::f_new(
                            vx_core::t_stringmap,
                            vx_core::vx_new(vx_core::t_anylist, {
                              vx_core::vx_new_string(":prop1"),
                              vx_core::vx_new_string("val1"),
                              vx_core::vx_new_string(":prop2"),
                              vx_core::vx_new_string("val2")
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
      vx_data_xml::f_xml_parse_from_xml_textblock(
        vx_core::f_new(
          vx_data_xml::t_xml,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":tag"),
            vx_core::vx_new_string("tag1"),
            vx_core::vx_new_string(":children"),
            vx_core::f_new(
              vx_data_xml::t_xmllist,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::f_new(
                  vx_data_xml::t_xml,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":tag"),
                    vx_core::vx_new_string("tag2"),
                    vx_core::vx_new_string(":propmap"),
                    vx_core::f_new(
                      vx_core::t_stringmap,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":prop1"),
                        vx_core::vx_new_string("val1"),
                        vx_core::vx_new_string(":prop2"),
                        vx_core::vx_new_string("val2")
                      })
                    )
                  })
                )
              })
            ),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_xml::t_xml,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":tag"),
                vx_core::vx_new_string("doc")
              })
            )
          })
        ),
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("</tag1>"),
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
                    vx_core::vx_new_string("/tag1")
                  })
                )
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_5 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (xml\n  :tag \"doc\"\n  :children\n   (xmllist\n    (xml\n    :tag \"tag1\"\n    :children\n     (xmllist\n      (xml\n       :tag \"tag2\"\n       :propmap\n        (stringmap\n         :prop1 \"val1\"\n         :prop2 \"val2\"))))))\n (xml-parse<-xml-textblock\n  (xml\n   :tag \"tag1\"\n   :children\n    (xmllist\n     (xml\n      :tag \"tag2\"\n      :propmap\n       (stringmap\n        :prop1 \"val1\"\n        :prop2 \"val2\")))\n   :parent\n    (xml\n     :tag \"doc\"))\n  (tb/textblock\n   :text \"</tag1>\"\n   :delim\n    (copy tb/delimbracketangle\n     :pos 0)\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"/tag1\")))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":testresult"), testresult_5
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2,
      testdescribe_3,
      testdescribe_4,
      testdescribe_5
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("xml-parse<-xml-textblock"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_xml_parse_from_xml_textblock");
    return output;
  }

  vx_test::Type_testcase f_xml_parse_from_xml_textblocklist(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_xml_parse_from_xml_textblocklist");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_xml::t_xml,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":tag"),
          vx_core::vx_new_string("doc"),
          vx_core::vx_new_string(":children"),
          vx_core::f_new(
            vx_data_xml::t_xmllist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::f_new(
                vx_data_xml::t_xml,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":tag"),
                  vx_core::vx_new_string("tag1"),
                  vx_core::vx_new_string(":children"),
                  vx_core::f_new(
                    vx_data_xml::t_xmllist,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::f_new(
                        vx_data_xml::t_xml,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":tag"),
                          vx_core::vx_new_string("tag2"),
                          vx_core::vx_new_string(":propmap"),
                          vx_core::f_new(
                            vx_core::t_stringmap,
                            vx_core::vx_new(vx_core::t_anylist, {
                              vx_core::vx_new_string(":prop1"),
                              vx_core::vx_new_string("val1"),
                              vx_core::vx_new_string(":prop2"),
                              vx_core::vx_new_string("val2")
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
      vx_data_xml::f_xml_parse_from_xml_textblocklist(
        vx_core::f_empty(
          vx_data_xml::t_xml
        ),
        vx_core::f_new(
          vx_data_textblock::t_textblocklist,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("<doc>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(1),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(5),
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
                        vx_core::vx_new_string("doc"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(2),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(4)
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
                vx_core::vx_new_string("\n  "),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(6),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(8),
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
                vx_core::vx_new_string("<tag1>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(9),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(14),
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
                        vx_core::vx_new_string("tag1"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(10),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(13)
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
                vx_core::vx_new_string("\n    "),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(15),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(19),
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
                vx_core::vx_new_string("<tag2 prop1=\"val1\" prop2=\"val2\" />"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(20),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(53),
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
                        vx_core::vx_new_string("tag2"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(21),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(24)
                      })
                    ),
                    vx_core::f_new(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":text"),
                        vx_core::vx_new_string(" "),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(25),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(25),
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
                        vx_core::vx_new_string("prop1"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(26),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(30)
                      })
                    ),
                    vx_core::f_new(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":text"),
                        vx_core::vx_new_string("="),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(31),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(31),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_xml::c_delimxmlequal,
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
                        vx_core::vx_new_string("\"val1\""),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(32),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(37),
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
                                vx_core::vx_new_string("val1"),
                                vx_core::vx_new_string(":startpos"),
                                vx_core::vx_new_int(33),
                                vx_core::vx_new_string(":endpos"),
                                vx_core::vx_new_int(36)
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
                        vx_core::vx_new_string(" "),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(38),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(38),
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
                        vx_core::vx_new_string("prop2"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(39),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(43)
                      })
                    ),
                    vx_core::f_new(
                      vx_data_textblock::t_textblock,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":text"),
                        vx_core::vx_new_string("="),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(44),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(44),
                        vx_core::vx_new_string(":delim"),
                        vx_core::f_copy(
                          vx_data_textblock::t_delim,
                          vx_data_xml::c_delimxmlequal,
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
                        vx_core::vx_new_string("\"val2\""),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(45),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(50),
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
                                vx_core::vx_new_string("val2"),
                                vx_core::vx_new_string(":startpos"),
                                vx_core::vx_new_int(46),
                                vx_core::vx_new_string(":endpos"),
                                vx_core::vx_new_int(49)
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
                        vx_core::vx_new_string(" "),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(51),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(51),
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
                        vx_core::vx_new_string("/"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(52),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(52)
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
                vx_core::vx_new_string("\n  "),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(54),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(56),
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
                vx_core::vx_new_string("</tag1>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(57),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(63),
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
                        vx_core::vx_new_string("/tag1"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(58),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(62)
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
                vx_core::vx_new_int(64),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(64),
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
                vx_core::vx_new_string("</doc>"),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(65),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(70),
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
                        vx_core::vx_new_string("/doc"),
                        vx_core::vx_new_string(":startpos"),
                        vx_core::vx_new_int(66),
                        vx_core::vx_new_string(":endpos"),
                        vx_core::vx_new_int(69)
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
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (xml\n  :tag \"doc\"\n  :children\n   (xmllist\n    (xml\n     :tag \"tag1\"\n     :children\n      (xmllist\n       (xml\n        :tag \"tag2\"\n        :propmap\n         (stringmap\n          :prop1 \"val1\"\n          :prop2 \"val2\"))))))\n (xml-parse<-xml-textblocklist\n  (empty xml)\n  (tb/textblocklist\n   (tb/textblock\n    :text \"<doc>\"\n    :startpos 1\n    :endpos 5\n    :delim\n     (copy tb/delimbracketangle\n      :pos 0)\n    :children\n     (tb/textblocklist\n      (tb/textblock\n       :text \"doc\"\n       :startpos 2\n       :endpos 4)))\n   (tb/textblock\n    :text \"\n  \"\n    :startpos 6\n    :endpos 8\n    :delim\n     (copy tb/delimwhitespace\n      :pos 0))\n   (tb/textblock\n    :text \"<tag1>\"\n    :startpos 9\n    :endpos 14\n    :delim\n     (copy tb/delimbracketangle\n      :pos 0)\n    :children\n     (tb/textblocklist\n      (tb/textblock\n       :text \"tag1\"\n       :startpos 10\n       :endpos 13)))\n   (tb/textblock\n    :text \"\n    \"\n    :startpos 15\n    :endpos 19\n    :delim\n     (copy tb/delimwhitespace\n      :pos 0))\n   (tb/textblock\n    :text \"<tag2 prop1=\\\"val1\\\" prop2=\\\"val2\\\" />\"\n    :startpos 20\n    :endpos 53\n    :delim\n     (copy tb/delimbracketangle\n      :pos 0)\n    :children\n     (tb/textblocklist\n      (tb/textblock\n       :text \"tag2\"\n       :startpos 21\n       :endpos 24)\n      (tb/textblock\n       :text \" \"\n       :startpos 25\n       :endpos 25\n       :delim\n        (copy tb/delimwhitespace\n         :pos 0))\n      (tb/textblock\n       :text \"prop1\"\n       :startpos 26\n       :endpos 30)\n      (tb/textblock\n       :text \"=\"\n       :startpos 31\n       :endpos 31\n       :delim\n        (copy delimxmlequal\n         :pos 0))\n      (tb/textblock\n       :text \"\\\"val1\\\"\"\n       :startpos 32\n       :endpos 37\n       :delim\n        (copy tb/delimquote\n         :pos 0)\n       :children\n        (tb/textblocklist\n         (tb/textblock\n          :text \"val1\"\n          :startpos 33\n          :endpos 36)))\n      (tb/textblock\n       :text \" \"\n       :startpos 38\n       :endpos 38\n       :delim\n        (copy tb/delimwhitespace\n         :pos 0))\n      (tb/textblock\n       :text \"prop2\"\n       :startpos 39\n       :endpos 43)\n      (tb/textblock\n       :text \"=\"\n       :startpos 44\n       :endpos 44\n       :delim\n        (copy delimxmlequal\n         :pos 0))\n      (tb/textblock\n       :text \"\\\"val2\\\"\"\n       :startpos 45\n       :endpos 50\n       :delim\n        (copy tb/delimquote\n         :pos 0)\n       :children\n        (tb/textblocklist\n         (tb/textblock\n          :text \"val2\"\n          :startpos 46\n          :endpos 49)))\n       (tb/textblock\n        :text \" \"\n        :startpos 51\n        :endpos 51\n        :delim\n         (copy tb/delimwhitespace\n          :pos 0))\n       (tb/textblock\n        :text \"/\"\n        :startpos 52\n        :endpos 52)))\n   (tb/textblock\n    :text \"\n  \"\n    :startpos 54\n    :endpos 56\n    :delim\n     (copy tb/delimwhitespace\n      :pos 0))\n   (tb/textblock\n    :text \"</tag1>\"\n    :startpos 57\n    :endpos 63\n    :delim\n     (copy tb/delimbracketangle\n      :pos 0)\n    :children\n     (tb/textblocklist\n      (tb/textblock\n       :text \"/tag1\"\n       :startpos 58\n       :endpos 62)))\n   (tb/textblock\n    :text \"\n\"\n    :startpos 64\n    :endpos 64\n    :delim\n     (copy tb/delimwhitespace\n      :pos 0))\n   (tb/textblock\n    :text \"</doc>\"\n    :startpos 65\n    :endpos 70\n    :delim\n     (copy tb/delimbracketangle\n      :pos 0)\n    :children\n     (tb/textblocklist\n      (tb/textblock\n       :text \"/doc\"\n       :startpos 66\n       :endpos 69))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("xml-parse<-xml-textblocklist"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_xml_parse_from_xml_textblocklist");
    return output;
  }

  vx_test::Type_testcase f_xml_properties_from_xml_textblocklist(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_xml_properties_from_xml_textblocklist");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_xml::t_xml,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":tag"),
          vx_core::vx_new_string("doc"),
          vx_core::vx_new_string(":children"),
          vx_core::f_new(
            vx_data_xml::t_xmllist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::f_new(
                vx_data_xml::t_xml,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":tag"),
                  vx_core::vx_new_string("tag2"),
                  vx_core::vx_new_string(":propmap"),
                  vx_core::f_new(
                    vx_core::t_stringmap,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":prop1"),
                      vx_core::vx_new_string("val1"),
                      vx_core::vx_new_string(":prop2"),
                      vx_core::vx_new_string("val2")
                    })
                  )
                })
              )
            })
          )
        })
      ),
      vx_data_xml::f_xml_properties_from_xml_textblocklist(
        vx_core::f_new(
          vx_data_xml::t_xml,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":tag"),
            vx_core::vx_new_string(":notag"),
            vx_core::vx_new_string(":parent"),
            vx_core::f_new(
              vx_data_xml::t_xml,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":tag"),
                vx_core::vx_new_string("doc")
              })
            )
          })
        ),
        vx_core::f_new(
          vx_data_textblock::t_textblocklist,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("tag2")
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
                vx_core::vx_new_string("prop1")
              })
            ),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("="),
                vx_core::vx_new_string(":delim"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_xml::c_delimxmlequal,
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
                vx_core::vx_new_string("\"val1\""),
                vx_core::vx_new_string(":startpos"),
                vx_core::vx_new_int(32),
                vx_core::vx_new_string(":endpos"),
                vx_core::vx_new_int(37),
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
                        vx_core::vx_new_string("val1")
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
                vx_core::vx_new_string("prop2")
              })
            ),
            vx_core::f_new(
              vx_data_textblock::t_textblock,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":text"),
                vx_core::vx_new_string("="),
                vx_core::vx_new_string(":delim"),
                vx_core::f_copy(
                  vx_data_textblock::t_delim,
                  vx_data_xml::c_delimxmlequal,
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
                vx_core::vx_new_string("\"val2\""),
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
                        vx_core::vx_new_string("val2")
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
                vx_core::vx_new_string("/")
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (xml\n  :tag \"doc\"\n  :children\n   (xmllist\n    (xml\n     :tag \"tag2\"\n     :propmap\n      (stringmap\n       :prop1 \"val1\"\n       :prop2 \"val2\"))))\n (xml-properties<-xml-textblocklist\n  (xml\n   :tag :notag\n   :parent\n    (xml\n     :tag \"doc\"))\n  (tb/textblocklist\n   (tb/textblock\n    :text \"tag2\")\n   (tb/textblock\n    :text \" \"\n    :delim\n     (copy tb/delimwhitespace\n      :pos 0))\n   (tb/textblock\n    :text \"prop1\")\n   (tb/textblock\n    :text \"=\"\n    :delim\n     (copy delimxmlequal\n      :pos 0))\n   (tb/textblock\n    :text \"\\\"val1\\\"\"\n    :startpos 32\n    :endpos 37\n    :delim\n     (copy tb/delimquote\n      :pos 0)\n    :children\n     (tb/textblocklist\n      (tb/textblock\n       :text \"val1\")))\n   (tb/textblock\n    :text \" \"\n    :delim\n     (copy tb/delimwhitespace\n      :pos 0))\n   (tb/textblock\n    :text \"prop2\")\n   (tb/textblock\n    :text \"=\"\n    :delim\n     (copy delimxmlequal\n      :pos 0))\n   (tb/textblock\n    :text \"\\\"val2\\\"\"\n    :delim\n     (copy tb/delimquote\n      :pos 0)\n    :children\n     (tb/textblocklist\n      (tb/textblock\n       :text \"val2\")))\n   (tb/textblock\n    :text \" \"\n    :delim\n     (copy tb/delimwhitespace\n      :pos 0))\n   (tb/textblock\n    :text \"/\"))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("xml-properties<-xml-textblocklist"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_xml_properties_from_xml_textblocklist");
    return output;
  }

  vx_test::Type_testcase f_xml_property_from_xml_textblock(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_xml_property_from_xml_textblock");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_xml::t_xml,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":tag"),
          vx_core::vx_new_string("tag1")
        })
      ),
      vx_data_xml::f_xml_property_from_xml_textblock(
        vx_core::f_new(
          vx_data_xml::t_xml,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":tag"),
            vx_core::vx_new_string(":notag")
          })
        ),
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("tag1")
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (xml\n  :tag \"tag1\")\n (xml-property<-xml-textblock\n  (xml\n   :tag \":notag\")\n  (tb/textblock\n   :text \"tag1\")))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_xml::t_xml,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":tag"),
          vx_core::vx_new_string("tag1"),
          vx_core::vx_new_string(":prop"),
          vx_core::vx_new_string("prop1")
        })
      ),
      vx_data_xml::f_xml_property_from_xml_textblock(
        vx_core::f_new(
          vx_data_xml::t_xml,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":tag"),
            vx_core::vx_new_string("tag1")
          })
        ),
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("prop1")
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (xml\n  :tag \"tag1\"\n  :prop \"prop1\")\n (xml-property<-xml-textblock\n  (xml\n   :tag \"tag1\")\n  (tb/textblock\n   :text \"prop1\")))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    // testdescribe_3
    vx_test::Type_testresult testresult_3 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_xml::t_xml,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":tag"),
          vx_core::vx_new_string("tag1"),
          vx_core::vx_new_string(":propmap"),
          vx_core::f_new(
            vx_core::t_stringmap,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":prop1"),
              vx_core::vx_new_string("val1")
            })
          )
        })
      ),
      vx_data_xml::f_xml_property_from_xml_textblock(
        vx_core::f_new(
          vx_data_xml::t_xml,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":tag"),
            vx_core::vx_new_string("tag1"),
            vx_core::vx_new_string(":prop"),
            vx_core::vx_new_string("prop1")
          })
        ),
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
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
                    vx_core::vx_new_string("val1")
                  })
                )
              })
            )
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_3 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (xml\n  :tag \"tag1\"\n  :propmap\n   (stringmap\n    :prop1 \"val1\"))\n (xml-property<-xml-textblock\n  (xml\n   :tag \"tag1\"\n   :prop \"prop1\")\n  (tb/textblock\n   :delim\n    (copy tb/delimquote\n     :pos 0)\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"val1\")))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":testresult"), testresult_3
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2,
      testdescribe_3
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("xml-property<-xml-textblock"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_xml_property_from_xml_textblock");
    return output;
  }

  vx_test::Type_testcase f_xml_text_from_xml_textblock(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_xml_text_from_xml_textblock");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_xml::t_xml,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":text"),
          vx_core::vx_new_string("text1")
        })
      ),
      vx_data_xml::f_xml_text_from_xml_textblock(
        vx_core::f_empty(
          vx_data_xml::t_xml
        ),
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("text1")
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_1 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (xml\n  :text \"text1\")\n (xml-text<-xml-textblock\n  (empty xml)\n  (tb/textblock\n   :text \"text1\")))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    // testdescribe_2
    vx_test::Type_testresult testresult_2 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_xml::t_xml,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":tag"),
          vx_core::vx_new_string("doc"),
          vx_core::vx_new_string(":children"),
          vx_core::f_new(
            vx_data_xml::t_xmllist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::f_new(
                vx_data_xml::t_xml,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":text"),
                  vx_core::vx_new_string("text1")
                })
              )
            })
          )
        })
      ),
      vx_data_xml::f_xml_text_from_xml_textblock(
        vx_core::f_new(
          vx_data_xml::t_xml,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":tag"),
            vx_core::vx_new_string("doc")
          })
        ),
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("text1")
          })
        )
      )
    );
    vx_test::Type_testdescribe testdescribe_2 = vx_core::vx_new(vx_test::t_testdescribe, {
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (xml\n  :tag \"doc\"\n  :children\n   (xmllist\n    (xml\n     :text \"text1\")))\n (xml-text<-xml-textblock\n  (xml\n   :tag \"doc\")\n  (tb/textblock\n   :text \"text1\")))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":testresult"), testresult_2
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1,
      testdescribe_2
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("xml-text<-xml-textblock"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_xml_text_from_xml_textblock");
    return output;
  }

  vx_test::Type_testcase f_xml_from_textblock(vx_core::Type_context context) {
    vx_core::vx_log("Test Start: f_xml_from_textblock");
    // testdescribe_1
    vx_test::Type_testresult testresult_1 = vx_test::f_test(
      context,
      vx_core::f_new(
        vx_data_xml::t_xml,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":tag"),
          vx_core::vx_new_string("doc"),
          vx_core::vx_new_string(":children"),
          vx_core::f_new(
            vx_data_xml::t_xmllist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::f_new(
                vx_data_xml::t_xml,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":tag"),
                  vx_core::vx_new_string("tag1"),
                  vx_core::vx_new_string(":children"),
                  vx_core::f_new(
                    vx_data_xml::t_xmllist,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::f_new(
                        vx_data_xml::t_xml,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":tag"),
                          vx_core::vx_new_string("tag2"),
                          vx_core::vx_new_string(":propmap"),
                          vx_core::f_new(
                            vx_core::t_stringmap,
                            vx_core::vx_new(vx_core::t_anylist, {
                              vx_core::vx_new_string(":prop1"),
                              vx_core::vx_new_string("val1"),
                              vx_core::vx_new_string(":prop2"),
                              vx_core::vx_new_string("val2")
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
      vx_data_xml::f_xml_from_textblock(
        vx_core::f_new(
          vx_data_textblock::t_textblock,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            vx_core::vx_new_string("<doc>\n  <tag1>\n    <tag2 prop1=\"val1\" prop2=\"val2\" />\n  </tag1>\n</doc>"),
            vx_core::vx_new_string(":startpos"),
            vx_core::vx_new_int(1),
            vx_core::vx_new_string(":endpos"),
            vx_core::vx_new_int(70),
            vx_core::vx_new_string(":children"),
            vx_core::f_new(
              vx_data_textblock::t_textblocklist,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::f_new(
                  vx_data_textblock::t_textblock,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("<doc>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(1),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(5),
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
                            vx_core::vx_new_string("doc"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(2),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(4)
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
                    vx_core::vx_new_string("\n  "),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(6),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(8),
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
                    vx_core::vx_new_string("<tag1>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(9),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(14),
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
                            vx_core::vx_new_string("tag1"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(10),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(13)
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
                    vx_core::vx_new_string("\n    "),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(15),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(19),
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
                    vx_core::vx_new_string("<tag2 prop1=\"val1\" prop2=\"val2\" />"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(20),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(53),
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
                            vx_core::vx_new_string("tag2"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(21),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(24)
                          })
                        ),
                        vx_core::f_new(
                          vx_data_textblock::t_textblock,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string(" "),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(25),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(25),
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
                            vx_core::vx_new_string("prop1"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(26),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(30)
                          })
                        ),
                        vx_core::f_new(
                          vx_data_textblock::t_textblock,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string("="),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(31),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(31),
                            vx_core::vx_new_string(":delim"),
                            vx_core::f_copy(
                              vx_data_textblock::t_delim,
                              vx_data_xml::c_delimxmlequal,
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
                            vx_core::vx_new_string("\"val1\""),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(32),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(37),
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
                                    vx_core::vx_new_string("val1"),
                                    vx_core::vx_new_string(":startpos"),
                                    vx_core::vx_new_int(33),
                                    vx_core::vx_new_string(":endpos"),
                                    vx_core::vx_new_int(36)
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
                            vx_core::vx_new_string(" "),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(38),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(38),
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
                            vx_core::vx_new_string("prop2"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(39),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(43)
                          })
                        ),
                        vx_core::f_new(
                          vx_data_textblock::t_textblock,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":text"),
                            vx_core::vx_new_string("="),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(44),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(44),
                            vx_core::vx_new_string(":delim"),
                            vx_core::f_copy(
                              vx_data_textblock::t_delim,
                              vx_data_xml::c_delimxmlequal,
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
                            vx_core::vx_new_string("\"val2\""),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(45),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(50),
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
                                    vx_core::vx_new_string("val2"),
                                    vx_core::vx_new_string(":startpos"),
                                    vx_core::vx_new_int(46),
                                    vx_core::vx_new_string(":endpos"),
                                    vx_core::vx_new_int(49)
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
                            vx_core::vx_new_string(" "),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(51),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(51),
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
                            vx_core::vx_new_string("/"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(52),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(52)
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
                    vx_core::vx_new_string("\n  "),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(54),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(56),
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
                    vx_core::vx_new_string("</tag1>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(57),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(63),
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
                            vx_core::vx_new_string("/tag1"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(58),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(62)
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
                    vx_core::vx_new_int(64),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(64),
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
                    vx_core::vx_new_string("</doc>"),
                    vx_core::vx_new_string(":startpos"),
                    vx_core::vx_new_int(65),
                    vx_core::vx_new_string(":endpos"),
                    vx_core::vx_new_int(70),
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
                            vx_core::vx_new_string("/doc"),
                            vx_core::vx_new_string(":startpos"),
                            vx_core::vx_new_int(66),
                            vx_core::vx_new_string(":endpos"),
                            vx_core::vx_new_int(69)
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
      vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n (xml\n  :tag \"doc\"\n  :children\n   (xmllist\n    (xml\n     :tag \"tag1\"\n     :children\n      (xmllist\n       (xml\n        :tag \"tag2\"\n        :propmap\n         (stringmap\n          :prop1 \"val1\"\n          :prop2 \"val2\"))))))\n (xml<-textblock\n  (tb/textblock\n   :text\n    \"<doc>\n       <tag1>\n         <tag2 prop1=\\\"val1\\\" prop2=\\\"val2\\\" />\n       </tag1>\n     </doc>\"\n   :startpos 1\n   :endpos 70\n   :children\n    (tb/textblocklist\n     (tb/textblock\n      :text \"<doc>\"\n      :startpos 1\n      :endpos 5\n      :delim\n       (copy tb/delimbracketangle\n        :pos 0)\n      :children\n       (tb/textblocklist\n        (tb/textblock\n         :text \"doc\"\n         :startpos 2\n         :endpos 4)))\n     (tb/textblock\n      :text \"\n  \"\n      :startpos 6\n      :endpos 8\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"<tag1>\"\n      :startpos 9\n      :endpos 14\n      :delim\n       (copy tb/delimbracketangle\n        :pos 0)\n      :children\n       (tb/textblocklist\n        (tb/textblock\n         :text \"tag1\"\n         :startpos 10\n         :endpos 13)))\n     (tb/textblock\n      :text \"\n    \"\n      :startpos 15\n      :endpos 19\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"<tag2 prop1=\\\"val1\\\" prop2=\\\"val2\\\" />\"\n      :startpos 20\n      :endpos 53\n      :delim\n       (copy tb/delimbracketangle\n        :pos 0)\n      :children\n       (tb/textblocklist\n        (tb/textblock\n         :text \"tag2\"\n         :startpos 21\n         :endpos 24)\n        (tb/textblock\n         :text \" \"\n         :startpos 25\n         :endpos 25\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"prop1\"\n         :startpos 26\n         :endpos 30)\n        (tb/textblock\n         :text \"=\"\n         :startpos 31\n         :endpos 31\n         :delim\n          (copy delimxmlequal\n           :pos 0))\n        (tb/textblock\n         :text \"\\\"val1\\\"\"\n         :startpos 32\n         :endpos 37\n         :delim\n          (copy tb/delimquote\n           :pos 0)\n         :children\n          (tb/textblocklist\n           (tb/textblock\n            :text \"val1\"\n            :startpos 33\n            :endpos 36)))\n        (tb/textblock\n         :text \" \"\n         :startpos 38\n         :endpos 38\n         :delim\n          (copy tb/delimwhitespace\n           :pos 0))\n        (tb/textblock\n         :text \"prop2\"\n         :startpos 39\n         :endpos 43)\n        (tb/textblock\n         :text \"=\"\n         :startpos 44\n         :endpos 44\n         :delim\n          (copy delimxmlequal\n           :pos 0))\n        (tb/textblock\n         :text \"\\\"val2\\\"\"\n         :startpos 45\n         :endpos 50\n         :delim\n          (copy tb/delimquote\n           :pos 0)\n         :children\n          (tb/textblocklist\n           (tb/textblock\n            :text \"val2\"\n            :startpos 46\n            :endpos 49)))\n         (tb/textblock\n          :text \" \"\n          :startpos 51\n          :endpos 51\n          :delim\n           (copy tb/delimwhitespace\n            :pos 0))\n         (tb/textblock\n          :text \"/\"\n          :startpos 52\n          :endpos 52)))\n     (tb/textblock\n      :text \"\n  \"\n      :startpos 54\n      :endpos 56\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"</tag1>\"\n      :startpos 57\n      :endpos 63\n      :delim\n       (copy tb/delimbracketangle\n        :pos 0)\n      :children\n       (tb/textblocklist\n        (tb/textblock\n         :text \"/tag1\"\n         :startpos 58\n         :endpos 62)))\n     (tb/textblock\n      :text \"\n\"\n      :startpos 64\n      :endpos 64\n      :delim\n       (copy tb/delimwhitespace\n        :pos 0))\n     (tb/textblock\n      :text \"</doc>\"\n      :startpos 65\n      :endpos 70\n      :delim\n       (copy tb/delimbracketangle\n        :pos 0)\n      :children\n       (tb/textblocklist\n        (tb/textblock\n         :text \"/doc\"\n         :startpos 66\n         :endpos 69)))))))"),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":testresult"), testresult_1
    });
    vx_core::vx_Type_listany listdescribe = {
      testdescribe_1
    };
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false,
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("xml<-textblock"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list(listdescribe)
      )
    });
    vx_core::vx_log("Test End  : f_xml_from_textblock");
    return output;
  }

  vx_test::Type_testcaselist test_cases(vx_core::Type_context context) {
    vx_core::vx_Type_listany listtestcase;
    listtestcase.push_back(vx_data_xml_test::f_string_first_from_xml(context));
    listtestcase.push_back(vx_data_xml_test::f_textblock_xml_from_string(context));
    listtestcase.push_back(vx_data_xml_test::f_xml_angle_from_xml_textblock(context));
    listtestcase.push_back(vx_data_xml_test::f_xml_close_from_xml_textblock(context));
    listtestcase.push_back(vx_data_xml_test::f_xml_parse_from_xml_textblock(context));
    listtestcase.push_back(vx_data_xml_test::f_xml_parse_from_xml_textblocklist(context));
    listtestcase.push_back(vx_data_xml_test::f_xml_properties_from_xml_textblocklist(context));
    listtestcase.push_back(vx_data_xml_test::f_xml_property_from_xml_textblock(context));
    listtestcase.push_back(vx_data_xml_test::f_xml_text_from_xml_textblock(context));
    listtestcase.push_back(vx_data_xml_test::f_xml_from_textblock(context));
    vx_test::Type_testcaselist output = vx_core::vx_any_from_any(
      vx_test::t_testcaselist,
      vx_test::t_testcaselist->vx_new_from_list(listtestcase)
    );
    return output;
  }

  vx_test::Type_testcoveragesummary test_coveragesummary() {
    vx_test::Type_testcoveragesummary output = vx_core::vx_new(vx_test::t_testcoveragesummary, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":constnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(4)
      }),
      vx_core::vx_new_string(":docnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(65), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(13), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(20)
      }),
      vx_core::vx_new_string(":funcnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(76), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(10), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(13)
      }),
      vx_core::vx_new_string(":bigospacenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(13)
      }),
      vx_core::vx_new_string(":bigotimenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(13)
      }),
      vx_core::vx_new_string(":totalnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(50), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(10), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(20)
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
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":typemap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":xml"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":xmllist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":xmlpropmap"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":constmap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":delimxml"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimxmlcdata"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimxmlcomment"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":delimxmlequal"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":funcmap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":string-first<-xml"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":textblock-xml<-string"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":xml-angle<-xml-textblock"), vx_core::vx_new_int(3),
        vx_core::vx_new_string(":xml-close<-xml-textblock"), vx_core::vx_new_int(4),
        vx_core::vx_new_string(":xml-parse<-xml-textblock"), vx_core::vx_new_int(5),
        vx_core::vx_new_string(":xml-parse<-xml-textblocklist"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":xml-properties<-xml-textblocklist"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":xml-property<-xml-textblock"), vx_core::vx_new_int(3),
        vx_core::vx_new_string(":xml-read<-file"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":xml-text<-xml-textblock"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":xml<-file"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":xml<-string"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":xml<-textblock"), vx_core::vx_new_int(1)
      })
    });
    return output;
  }

  vx_test::Type_testpackage test_package(vx_core::Type_context context) {
    vx_test::Type_testcaselist testcaselist = vx_data_xml_test::test_cases(context);
    vx_test::Type_testcoveragesummary testcoveragesummary = vx_data_xml_test::test_coveragesummary();
    vx_test::Type_testcoveragedetail testcoveragedetail = vx_data_xml_test::test_coveragedetail();
    vx_test::Type_testpackage output = vx_core::vx_new(vx_test::t_testpackage, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/data/xml"),
      vx_core::vx_new_string(":caselist"), testcaselist,
      vx_core::vx_new_string(":coveragesummary"), testcoveragesummary,
      vx_core::vx_new_string(":coveragedetail"), testcoveragedetail
    });
    return output;
  }

}
