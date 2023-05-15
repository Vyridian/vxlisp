#include "../../../main/vx/web/html.hpp"
#include "../../../main/vx/core.hpp"
#include "../../../main/vx/test.hpp"
#include "../../../main/vx/type.hpp"

namespace vx_web_html_test {

  vx_test::Type_testcase f_string_from_body_indent(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/web/html"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("string<-body-indent"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(vx_test::t_testdescribelist, 
        vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
          vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test\n \"<body></body>\"\n (string<-body-indent (body) 0))"),
          vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
              vx_core::t_string->vx_new_from_string("<body></body>"),
              vx_web_html::f_string_from_body_indent(
                vx_core::f_empty(
                  vx_web_html::t_body
                ),
                vx_core::t_int->vx_new_from_int(0)
              ),
              context
            )
        }),
        vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
          vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test\n \"<body>\n  <div></div>\n</body>\"\n (string<-body-indent (body (div)) 0))"),
          vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
              vx_core::t_string->vx_new_from_string("<body>\n  <div></div>\n</body>"),
              vx_web_html::f_string_from_body_indent(
                vx_core::f_new(
                  vx_web_html::t_body,
                  vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                    vx_core::f_empty(
                      vx_web_html::t_div
                    )
                  })
                ),
                vx_core::t_int->vx_new_from_int(0)
              ),
              context
            )
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_string_from_div_indent(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/web/html"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("string<-div-indent"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(vx_test::t_testdescribelist, 
        vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
          vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test\n \"<div></div>\"\n (string<-div-indent (div) 0))"),
          vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
              vx_core::t_string->vx_new_from_string("<div></div>"),
              vx_web_html::f_string_from_div_indent(
                vx_core::f_empty(
                  vx_web_html::t_div
                ),
                vx_core::t_int->vx_new_from_int(0)
              ),
              context
            )
        }),
        vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
          vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test\n \"<div id=\\\"myid\\\"></div>\"\n (string<-div-indent\n  (div :id \"myid\") 0))"),
          vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
              vx_core::t_string->vx_new_from_string("<div id=\"myid\"></div>"),
              vx_web_html::f_string_from_div_indent(
                vx_core::f_new(
                  vx_web_html::t_div,
                  vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                    vx_core::t_string->vx_new_from_string(":id"),
                    vx_core::t_string->vx_new_from_string("myid")
                  })
                ),
                vx_core::t_int->vx_new_from_int(0)
              ),
              context
            )
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_string_from_head_indent(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/web/html"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("string<-head-indent"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(vx_test::t_testdescribelist, 
        vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
          vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test\n \"<head></head>\"\n (string<-head-indent (head) 0))"),
          vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
              vx_core::t_string->vx_new_from_string("<head></head>"),
              vx_web_html::f_string_from_head_indent(
                vx_core::f_empty(
                  vx_web_html::t_head
                ),
                vx_core::t_int->vx_new_from_int(0)
              ),
              context
            )
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_string_from_html(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/web/html"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("string<-html"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(vx_test::t_testdescribelist, 
        vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
          vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test\n \"<!DOCTYPE html>\n<html>\n  <head></head>\n  <body></body>\n  <footer></footer>\n</html>\"\n (string<-html\n  (html :head (head) :body (body))))"),
          vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
              vx_core::t_string->vx_new_from_string("<!DOCTYPE html>\n<html>\n  <head></head>\n  <body></body>\n  <footer></footer>\n</html>"),
              vx_web_html::f_string_from_html(
                vx_core::f_new(
                  vx_web_html::t_html,
                  vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                    vx_core::t_string->vx_new_from_string(":head"),
                    vx_core::f_empty(
                      vx_web_html::t_head
                    ),
                    vx_core::t_string->vx_new_from_string(":body"),
                    vx_core::f_empty(
                      vx_web_html::t_body
                    )
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

  vx_test::Type_testcase f_string_from_meta_indent(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/web/html"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("string<-meta-indent"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(vx_test::t_testdescribelist, 
        vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
          vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test\n \"<meta charset=\\\"utf-8\\\" />\"\n (string<-meta-indent (meta :charset \"utf-8\") 0))"),
          vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
              vx_core::t_string->vx_new_from_string("<meta charset=\"utf-8\" />"),
              vx_web_html::f_string_from_meta_indent(
                vx_core::f_new(
                  vx_web_html::t_meta,
                  vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                    vx_core::t_string->vx_new_from_string(":charset"),
                    vx_core::t_string->vx_new_from_string("utf-8")
                  })
                ),
                vx_core::t_int->vx_new_from_int(0)
              ),
              context
            )
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_string_from_p_indent(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_test::t_testcase->vx_new(vx_test::t_testcase, {
      vx_core::t_string->vx_new_from_string(":passfail"), vx_core::c_false,
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/web/html"),
      vx_core::t_string->vx_new_from_string(":casename"), vx_core::t_string->vx_new_from_string("string<-p-indent"),
      vx_core::t_string->vx_new_from_string(":describelist"),
      vx_test::t_testdescribelist->vx_new_from_list(vx_test::t_testdescribelist, 
        vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
          vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test\n \"<p>data</p>\"\n (string<-p-indent (p :text \"data\") 0))"),
          vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
              vx_core::t_string->vx_new_from_string("<p>data</p>"),
              vx_web_html::f_string_from_p_indent(
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                    vx_core::t_string->vx_new_from_string(":text"),
                    vx_core::t_string->vx_new_from_string("data")
                  })
                ),
                vx_core::t_int->vx_new_from_int(0)
              ),
              context
            )
        }),
        vx_test::t_testdescribe->vx_new(vx_test::t_testdescribe, {
          vx_core::t_string->vx_new_from_string(":describename"), vx_core::t_string->vx_new_from_string("(test\n \"<p id=\\\"myid\\\">data</p>\"\n (string<-p-indent\n  (p :id \"myid\" :text \"data\") 0))"),
          vx_core::t_string->vx_new_from_string(":testresult"),
            vx_test::f_test(
              vx_core::t_string->vx_new_from_string("<p id=\"myid\">data</p>"),
              vx_web_html::f_string_from_p_indent(
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                    vx_core::t_string->vx_new_from_string(":id"),
                    vx_core::t_string->vx_new_from_string("myid"),
                    vx_core::t_string->vx_new_from_string(":text"),
                    vx_core::t_string->vx_new_from_string("data")
                  })
                ),
                vx_core::t_int->vx_new_from_int(0)
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
    arraylisttestcase->push_back(vx_web_html_test::f_string_from_body_indent(context));
    arraylisttestcase->push_back(vx_web_html_test::f_string_from_div_indent(context));
    arraylisttestcase->push_back(vx_web_html_test::f_string_from_head_indent(context));
    arraylisttestcase->push_back(vx_web_html_test::f_string_from_html(context));
    arraylisttestcase->push_back(vx_web_html_test::f_string_from_meta_indent(context));
    arraylisttestcase->push_back(vx_web_html_test::f_string_from_p_indent(context));
    vx_test::Type_testcaselist output = vx_test::t_testcaselist->vx_new_from_list(vx_test::t_testcaselist, arraylisttestcase);
    return output;
  }

  vx_test::Type_testcoveragesummary test_coveragesummary() {
    return vx_test::t_testcoveragesummary->vx_new(vx_test::t_testcoveragesummary, {
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/web/html"),
      vx_core::t_string->vx_new_from_string(":constnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(100), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(0)
      }),
      vx_core::t_string->vx_new_from_string(":docnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(98), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(68), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(69)
      }),
      vx_core::t_string->vx_new_from_string(":funcnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(15), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(6), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(38)
      }),
      vx_core::t_string->vx_new_from_string(":ospacenums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(38)
      }),
      vx_core::t_string->vx_new_from_string(":otimenums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(38)
      }),
      vx_core::t_string->vx_new_from_string(":totalnums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(8), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(6), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(69)
      }),
      vx_core::t_string->vx_new_from_string(":typenums"), vx_test::t_testcoveragenums->vx_new(vx_test::t_testcoveragenums, {
        vx_core::t_string->vx_new_from_string(":pct"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":tests"), vx_core::t_int->vx_new_from_int(0), 
        vx_core::t_string->vx_new_from_string(":total"), vx_core::t_int->vx_new_from_int(31)
      })
    });
  }

  vx_test::Type_testcoveragedetail test_coveragedetail() {
    return vx_test::t_testcoveragedetail->vx_new(vx_test::t_testcoveragedetail, {
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/web/html"),
      vx_core::t_string->vx_new_from_string(":typemap"), vx_core::t_intmap->vx_new(vx_core::t_intmap, {
              vx_core::t_string->vx_new_from_string(":body"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":details"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":div"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":divchild"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":divchildlist"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":divlist"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":footer"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":h1"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":h2"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":h3"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":head"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":headchild"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":headchildlist"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":html"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":meta"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":node"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":nodelist"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":p"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":propmap"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":style"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":stylelist"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":stylemap"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":stylesheet"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":table"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":tbody"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":td"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":tdlist"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":thead"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":title"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":tr"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":trlist"), vx_core::t_int->vx_new_from_int(0)
      }),
      vx_core::t_string->vx_new_from_string(":constmap"), vx_core::t_intmap->vx_new(vx_core::t_intmap, {
        
      }),
      vx_core::t_string->vx_new_from_string(":funcmap"), vx_core::t_intmap->vx_new(vx_core::t_intmap, {
              vx_core::t_string->vx_new_from_string(":boolean-write<-id-htmltext"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":boolean-write<-stylesheet"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":htmlstring<-string"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":string-indent"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":string<-body-indent"), vx_core::t_int->vx_new_from_int(2),
              vx_core::t_string->vx_new_from_string(":string<-details-indent"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":string<-div-indent"), vx_core::t_int->vx_new_from_int(2),
              vx_core::t_string->vx_new_from_string(":string<-footer-indent"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":string<-h1-indent"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":string<-h2-indent"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":string<-h3-indent"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":string<-head-indent"), vx_core::t_int->vx_new_from_int(1),
              vx_core::t_string->vx_new_from_string(":string<-html"), vx_core::t_int->vx_new_from_int(1),
              vx_core::t_string->vx_new_from_string(":string<-indent"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":string<-meta-indent"), vx_core::t_int->vx_new_from_int(1),
              vx_core::t_string->vx_new_from_string(":string<-node-indent"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":string<-nodelist-indent"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":string<-nodelist-tag-prop-indent"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":string<-p-indent"), vx_core::t_int->vx_new_from_int(2),
              vx_core::t_string->vx_new_from_string(":string<-propname-val"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":string<-propstyle"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":string<-style-indent"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":string<-stylelist-indent"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":string<-stylepropmap-indent"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":string<-stylesheet-indent"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":string<-table-indent"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":string<-tbody-indent"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":string<-td-indent"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":string<-thead-indent"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":string<-title-indent"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":string<-tr-indent"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":string<-uri"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":style<-stylesheet-name"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":stylemap<-stylelist"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":stylemap<-stylesheet"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":styles<-stylesheet"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":stylesheet-loadmap"), vx_core::t_int->vx_new_from_int(0),
              vx_core::t_string->vx_new_from_string(":uri<-string"), vx_core::t_int->vx_new_from_int(0)
      })
    });
  }

  vx_test::Type_testpackage test_package(vx_core::Type_context context) {
    vx_test::Type_testcaselist testcaselist = test_cases(context);
    vx_test::Type_testpackage output = vx_test::t_testpackage->vx_new(vx_test::t_testpackage, {
      vx_core::t_string->vx_new_from_string(":testpkg"), vx_core::t_string->vx_new_from_string("vx/web/html"), 
      vx_core::t_string->vx_new_from_string(":caselist"), testcaselist,
      vx_core::t_string->vx_new_from_string(":coveragesummary"), test_coveragesummary(),
      vx_core::t_string->vx_new_from_string(":coveragedetail"), test_coveragedetail()
    });
    return output;
  }

}
