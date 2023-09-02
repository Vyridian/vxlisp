#include "../../../main/vx/web/html.hpp"
#include "../../../main/vx/core.hpp"
#include "../../../main/vx/test.hpp"
#include "../../../main/vx/type.hpp"

#include "html_test.hpp"

namespace vx_web_html_test {

  vx_test::Type_testcase f_string_from_body_indent(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/web/html"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("string<-body-indent"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"<body></body>\"\n (string<-body-indent (body) 0))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/web/html"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("<body></body>"),
              vx_web_html::f_string_from_body_indent(
                vx_core::f_empty(
                  vx_web_html::t_body
                ),
                vx_core::vx_new_int(0)
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"<body>\n  <div></div>\n</body>\"\n (string<-body-indent (body (div)) 0))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/web/html"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("<body>\n  <div></div>\n</body>"),
              vx_web_html::f_string_from_body_indent(
                vx_core::f_new(
                  vx_web_html::t_body,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::f_empty(
                      vx_web_html::t_div
                    )
                  })
                ),
                vx_core::vx_new_int(0)
              ),
              context
            )
          })
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_string_from_div_indent(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/web/html"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("string<-div-indent"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"<div></div>\"\n (string<-div-indent (div) 0))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/web/html"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("<div></div>"),
              vx_web_html::f_string_from_div_indent(
                vx_core::f_empty(
                  vx_web_html::t_div
                ),
                vx_core::vx_new_int(0)
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"<div id=\\\"myid\\\"></div>\"\n (string<-div-indent\n  (div :id \"myid\") 0))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/web/html"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("<div id=\"myid\"></div>"),
              vx_web_html::f_string_from_div_indent(
                vx_core::f_new(
                  vx_web_html::t_div,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":id"),
                    vx_core::vx_new_string("myid")
                  })
                ),
                vx_core::vx_new_int(0)
              ),
              context
            )
          })
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_string_from_head_indent(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/web/html"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("string<-head-indent"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"<head></head>\"\n (string<-head-indent (head) 0))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/web/html"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("<head></head>"),
              vx_web_html::f_string_from_head_indent(
                vx_core::f_empty(
                  vx_web_html::t_head
                ),
                vx_core::vx_new_int(0)
              ),
              context
            )
          })
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_string_from_html(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/web/html"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("string<-html"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"<!DOCTYPE html>\n<html>\n  <head></head>\n  <body></body>\n  <footer></footer>\n</html>\"\n (string<-html\n  (html :head (head) :body (body))))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/web/html"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("<!DOCTYPE html>\n<html>\n  <head></head>\n  <body></body>\n  <footer></footer>\n</html>"),
              vx_web_html::f_string_from_html(
                vx_core::f_new(
                  vx_web_html::t_html,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":head"),
                    vx_core::f_empty(
                      vx_web_html::t_head
                    ),
                    vx_core::vx_new_string(":body"),
                    vx_core::f_empty(
                      vx_web_html::t_body
                    )
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

  vx_test::Type_testcase f_string_from_meta_indent(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/web/html"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("string<-meta-indent"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"<meta charset=\\\"utf-8\\\" />\"\n (string<-meta-indent (meta :charset \"utf-8\") 0))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/web/html"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("<meta charset=\"utf-8\" />"),
              vx_web_html::f_string_from_meta_indent(
                vx_core::f_new(
                  vx_web_html::t_meta,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":charset"),
                    vx_core::vx_new_string("utf-8")
                  })
                ),
                vx_core::vx_new_int(0)
              ),
              context
            )
          })
        })
      )
    });
    return output;
  }

  vx_test::Type_testcase f_string_from_p_indent(vx_core::Type_context context) {
    vx_test::Type_testcase output = vx_core::vx_new(vx_test::t_testcase, {
      vx_core::vx_new_string(":passfail"), vx_core::c_false(),
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/web/html"),
      vx_core::vx_new_string(":casename"), vx_core::vx_new_string("string<-p-indent"),
      vx_core::vx_new_string(":describelist"),
      vx_core::vx_any_from_any(
        vx_test::t_testdescribelist,
        vx_test::t_testdescribelist->vx_new_from_list({
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"<p>data</p>\"\n (string<-p-indent (p :text \"data\") 0))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/web/html"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("<p>data</p>"),
              vx_web_html::f_string_from_p_indent(
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("data")
                  })
                ),
                vx_core::vx_new_int(0)
              ),
              context
            )
          }),
          vx_core::vx_new(vx_test::t_testdescribe, {
            vx_core::vx_new_string(":describename"), vx_core::vx_new_string("(test\n \"<p id=\\\"myid\\\">data</p>\"\n (string<-p-indent\n  (p :id \"myid\" :text \"data\") 0))"),
            vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/web/html"),
            vx_core::vx_new_string(":testresult"),
            vx_test::f_test(
              vx_core::vx_new_string("<p id=\"myid\">data</p>"),
              vx_web_html::f_string_from_p_indent(
                vx_core::f_new(
                  vx_web_html::t_p,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":id"),
                    vx_core::vx_new_string("myid"),
                    vx_core::vx_new_string(":text"),
                    vx_core::vx_new_string("data")
                  })
                ),
                vx_core::vx_new_int(0)
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
    listtestcase.push_back(vx_web_html_test::f_string_from_body_indent(context));
    listtestcase.push_back(vx_web_html_test::f_string_from_div_indent(context));
    listtestcase.push_back(vx_web_html_test::f_string_from_head_indent(context));
    listtestcase.push_back(vx_web_html_test::f_string_from_html(context));
    listtestcase.push_back(vx_web_html_test::f_string_from_meta_indent(context));
    listtestcase.push_back(vx_web_html_test::f_string_from_p_indent(context));
    vx_test::Type_testcaselist output = vx_core::vx_any_from_any(
      vx_test::t_testcaselist,
      vx_test::t_testcaselist->vx_new_from_list(listtestcase)
    );
    return output;
  }

  vx_test::Type_testcoveragesummary test_coveragesummary() {
    vx_test::Type_testcoveragesummary output = vx_core::vx_new(vx_test::t_testcoveragesummary, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/web/html"),
      vx_core::vx_new_string(":constnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(100), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":docnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(98), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(68), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(69)
      }),
      vx_core::vx_new_string(":funcnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(15), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(6), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(38)
      }),
      vx_core::vx_new_string(":bigospacenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(38)
      }),
      vx_core::vx_new_string(":bigotimenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(38)
      }),
      vx_core::vx_new_string(":totalnums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(8), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(6), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(69)
      }),
      vx_core::vx_new_string(":typenums"), vx_core::vx_new(vx_test::t_testcoveragenums, {
        vx_core::vx_new_string(":pct"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":tests"), vx_core::vx_new_int(0), 
        vx_core::vx_new_string(":total"), vx_core::vx_new_int(31)
      })
    });
    return output;
  }

  vx_test::Type_testcoveragedetail test_coveragedetail() {
    vx_test::Type_testcoveragedetail output = vx_core::vx_new(vx_test::t_testcoveragedetail, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/web/html"),
      vx_core::vx_new_string(":typemap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":body"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":details"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":div"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":divchild"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":divchildlist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":divlist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":footer"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":h1"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":h2"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":h3"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":head"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":headchild"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":headchildlist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":html"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":meta"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":node"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":nodelist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":p"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":propmap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":style"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":stylelist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":stylemap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":stylesheet"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":table"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":tbody"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":td"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":tdlist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":thead"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":title"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":tr"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":trlist"), vx_core::vx_new_int(0)
      }),
      vx_core::vx_new_string(":constmap"), vx_core::vx_new(vx_core::t_intmap, {
        
      }),
      vx_core::vx_new_string(":funcmap"), vx_core::vx_new(vx_core::t_intmap, {
        vx_core::vx_new_string(":boolean-write<-id-htmltext"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":boolean-write<-stylesheet"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":htmlstring<-string"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string-indent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string<-body-indent"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":string<-details-indent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string<-div-indent"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":string<-footer-indent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string<-h1-indent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string<-h2-indent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string<-h3-indent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string<-head-indent"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":string<-html"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":string<-indent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string<-meta-indent"), vx_core::vx_new_int(1),
        vx_core::vx_new_string(":string<-node-indent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string<-nodelist-indent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string<-nodelist-tag-prop-indent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string<-p-indent"), vx_core::vx_new_int(2),
        vx_core::vx_new_string(":string<-propname-val"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string<-propstyle"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string<-style-indent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string<-stylelist-indent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string<-stylepropmap-indent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string<-stylesheet-indent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string<-table-indent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string<-tbody-indent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string<-td-indent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string<-thead-indent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string<-title-indent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string<-tr-indent"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":string<-uri"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":style<-stylesheet-name"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":stylemap<-stylelist"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":stylemap<-stylesheet"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":styles<-stylesheet"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":stylesheet-loadmap"), vx_core::vx_new_int(0),
        vx_core::vx_new_string(":uri<-string"), vx_core::vx_new_int(0)
      })
    });
    return output;
  }

  vx_test::Type_testpackage test_package(vx_core::Type_context context) {
    vx_test::Type_testcaselist testcaselist = vx_web_html_test::test_cases(context);
    vx_test::Type_testcoveragesummary testcoveragesummary = vx_web_html_test::test_coveragesummary();
    vx_test::Type_testcoveragedetail testcoveragedetail = vx_web_html_test::test_coveragedetail();
    vx_test::Type_testpackage output = vx_core::vx_new(vx_test::t_testpackage, {
      vx_core::vx_new_string(":testpkg"), vx_core::vx_new_string("vx/web/html"),
      vx_core::vx_new_string(":caselist"), testcaselist,
      vx_core::vx_new_string(":coveragesummary"), testcoveragesummary,
      vx_core::vx_new_string(":coveragedetail"), testcoveragedetail
    });
    return output;
  }

}
