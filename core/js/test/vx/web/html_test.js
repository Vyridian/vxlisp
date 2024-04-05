'strict mode'

import vx_web_html from "../../../src/vx/web/html.js"
import vx_core from "../../../src/vx/core.js"
import vx_test from "../../../src/vx/test.js"
import vx_event from "../../../src/vx/event.js"
import vx_type from "../../../src/vx/type.js"

export default class vx_web_html_test {


  static test_package(context) {
    const testcaselist = vx_web_html_test.test_cases(context)
    const output = vx_core.f_new(
      vx_test.t_testpackage,
      ":testpkg", "vx/web/html",
      ":caselist", testcaselist,
      ":coveragesummary", vx_web_html_test.test_coveragesummary(),
      ":coveragedetail", vx_web_html_test.test_coveragedetail()
    );
    return output;
  }

  static test_coveragesummary() {
    return vx_core.f_new(
      vx_test.t_testcoveragesummary,
      "testpkg",   "vx/web/html", 
      "constnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 98, ":tests", 71, ":total", 72), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 17, ":tests", 7, ":total", 40), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 9, ":tests", 7, ":total", 72), 
      "typenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 32)
    )
  }

  static test_coveragedetail() {
    return vx_core.f_new(
      vx_test.t_testcoveragedetail,
      "testpkg", "vx/web/html",
      "typemap",
        vx_core.f_new(
          vx_core.t_intmap,
          "body", 0,
          "details", 0,
          "div", 0,
          "divchild", 0,
          "divchildlist", 0,
          "divlist", 0,
          "footer", 0,
          "h1", 0,
          "h2", 0,
          "h3", 0,
          "head", 0,
          "headchild", 0,
          "headchildlist", 0,
          "html", 0,
          "img", 0,
          "meta", 0,
          "node", 0,
          "nodelist", 0,
          "p", 0,
          "propmap", 0,
          "style", 0,
          "stylelist", 0,
          "stylemap", 0,
          "stylesheet", 0,
          "table", 0,
          "tbody", 0,
          "td", 0,
          "tdlist", 0,
          "thead", 0,
          "title", 0,
          "tr", 0,
          "trlist", 0
        ),
      "constmap",
        vx_core.f_new(
          vx_core.t_intmap
        ),
      "funcmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "htmlstring<-string", 0,
          "string-indent", 0,
          "string<-body-indent", 2,
          "string<-details-indent", 0,
          "string<-div-indent", 2,
          "string<-footer-indent", 0,
          "string<-h1-indent", 0,
          "string<-h2-indent", 0,
          "string<-h3-indent", 0,
          "string<-head-indent", 1,
          "string<-html", 1,
          "string<-img-indent", 2,
          "string<-indent", 0,
          "string<-meta-indent", 1,
          "string<-node-indent", 0,
          "string<-nodelist-indent", 0,
          "string<-nodelist-tag-prop-indent", 0,
          "string<-p-indent", 2,
          "string<-propname-val", 0,
          "string<-propstyle", 0,
          "string<-propstyle-stylelist", 0,
          "string<-propstylelist", 0,
          "string<-propstyleunique", 0,
          "string<-style-indent", 0,
          "string<-stylelist-indent", 0,
          "string<-stylepropmap-indent", 0,
          "string<-stylesheet-indent", 0,
          "string<-table-indent", 0,
          "string<-tbody-indent", 0,
          "string<-td-indent", 0,
          "string<-thead-indent", 0,
          "string<-title-indent", 0,
          "string<-tr-indent", 0,
          "string<-uri", 0,
          "style<-stylesheet-name", 0,
          "stylemap<-stylelist", 0,
          "stylemap<-stylesheet", 0,
          "styles<-stylesheet", 0,
          "stylesheet-loadmap", 0,
          "uri<-string", 0
        )
    )
  }

  static f_string_from_body_indent(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/web/html",
      ":casename", "string<-body-indent",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n \"<body></body>\"\n (string<-body-indent (body) 0))",
            ":testresult",
            vx_test.f_test(
              context,
              "<body></body>",
              vx_web_html.f_string_from_body_indent(
                vx_core.f_empty(
                  vx_web_html.t_body
                ),
                0
              )
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n \"<body>\n  <div></div>\n</body>\"\n (string<-body-indent (body (div)) 0))",
            ":testresult",
            vx_test.f_test(
              context,
              "<body>\n  <div></div>\n</body>",
              vx_web_html.f_string_from_body_indent(
                vx_core.f_new(
                  vx_web_html.t_body,
                  vx_core.f_empty(
                    vx_web_html.t_div
                  )
                ),
                0
              )
            )
          )
        )
    )
    return output
  }

  static f_string_from_div_indent(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/web/html",
      ":casename", "string<-div-indent",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n \"<div></div>\"\n (string<-div-indent (div) 0))",
            ":testresult",
            vx_test.f_test(
              context,
              "<div></div>",
              vx_web_html.f_string_from_div_indent(
                vx_core.f_empty(
                  vx_web_html.t_div
                ),
                0
              )
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n \"<div id=\\\"myid\\\"></div>\"\n (string<-div-indent\n  (div :id \"myid\") 0))",
            ":testresult",
            vx_test.f_test(
              context,
              "<div id=\"myid\"></div>",
              vx_web_html.f_string_from_div_indent(
                vx_core.f_new(
                  vx_web_html.t_div,
                  ":id",
                  "myid"
                ),
                0
              )
            )
          )
        )
    )
    return output
  }

  static f_string_from_head_indent(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/web/html",
      ":casename", "string<-head-indent",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n \"<head></head>\"\n (string<-head-indent (head) 0))",
            ":testresult",
            vx_test.f_test(
              context,
              "<head></head>",
              vx_web_html.f_string_from_head_indent(
                vx_core.f_empty(
                  vx_web_html.t_head
                ),
                0
              )
            )
          )
        )
    )
    return output
  }

  static f_string_from_html(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/web/html",
      ":casename", "string<-html",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n \"<!DOCTYPE html>\n<html>\n  <head></head>\n  <body></body>\n  <footer></footer>\n</html>\"\n (string<-html\n  (html :head (head) :body (body))))",
            ":testresult",
            vx_test.f_test(
              context,
              "<!DOCTYPE html>\n<html>\n  <head></head>\n  <body></body>\n  <footer></footer>\n</html>",
              vx_web_html.f_string_from_html(
                vx_core.f_new(
                  vx_web_html.t_html,
                  ":head",
                  vx_core.f_empty(
                    vx_web_html.t_head
                  ),
                  ":body",
                  vx_core.f_empty(
                    vx_web_html.t_body
                  )
                )
              )
            )
          )
        )
    )
    return output
  }

  static f_string_from_img_indent(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/web/html",
      ":casename", "string<-img-indent",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n \"<img src=\\\"test.svg\\\" />\"\n (string<-img-indent\n  (img :src \"test.svg\")\n  0))",
            ":testresult",
            vx_test.f_test(
              context,
              "<img src=\"test.svg\" />",
              vx_web_html.f_string_from_img_indent(
                vx_core.f_new(
                  vx_web_html.t_img,
                  ":src",
                  "test.svg"
                ),
                0
              )
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n \"<img id=\\\"myid\\\" src=\\\"test.svg\\\" />\"\n (string<-img-indent\n  (img :id \"myid\" :src \"test.svg\")\n  0))",
            ":testresult",
            vx_test.f_test(
              context,
              "<img id=\"myid\" src=\"test.svg\" />",
              vx_web_html.f_string_from_img_indent(
                vx_core.f_new(
                  vx_web_html.t_img,
                  ":id",
                  "myid",
                  ":src",
                  "test.svg"
                ),
                0
              )
            )
          )
        )
    )
    return output
  }

  static f_string_from_meta_indent(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/web/html",
      ":casename", "string<-meta-indent",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n \"<meta charset=\\\"utf-8\\\" />\"\n (string<-meta-indent (meta :charset \"utf-8\") 0))",
            ":testresult",
            vx_test.f_test(
              context,
              "<meta charset=\"utf-8\" />",
              vx_web_html.f_string_from_meta_indent(
                vx_core.f_new(
                  vx_web_html.t_meta,
                  ":charset",
                  "utf-8"
                ),
                0
              )
            )
          )
        )
    )
    return output
  }

  static f_string_from_p_indent(context) {
    const output = vx_core.f_new(
      vx_test.t_testcase,
      ":passfail", false,
      ":testpkg", "vx/web/html",
      ":casename", "string<-p-indent",
      ":describelist",
        vx_core.f_new(
          vx_test.t_testdescribelist,
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n \"<p>data</p>\"\n (string<-p-indent\n  (p :text \"data\")\n  0))",
            ":testresult",
            vx_test.f_test(
              context,
              "<p>data</p>",
              vx_web_html.f_string_from_p_indent(
                vx_core.f_new(
                  vx_web_html.t_p,
                  ":text",
                  "data"
                ),
                0
              )
            )
          ),
          vx_core.f_new(
            vx_test.t_testdescribe,
            ":describename", "(test\n \"<p id=\\\"myid\\\">data</p>\"\n (string<-p-indent\n  (p :id \"myid\" :text \"data\")\n  0))",
            ":testresult",
            vx_test.f_test(
              context,
              "<p id=\"myid\">data</p>",
              vx_web_html.f_string_from_p_indent(
                vx_core.f_new(
                  vx_web_html.t_p,
                  ":id",
                  "myid",
                  ":text",
                  "data"
                ),
                0
              )
            )
          )
        )
    )
    return output
  }

  static test_cases(context) {
    const output = vx_core.f_new(
      vx_test.t_testcaselist,
      vx_web_html_test.f_string_from_body_indent(context),
      vx_web_html_test.f_string_from_div_indent(context),
      vx_web_html_test.f_string_from_head_indent(context),
      vx_web_html_test.f_string_from_html(context),
      vx_web_html_test.f_string_from_img_indent(context),
      vx_web_html_test.f_string_from_meta_indent(context),
      vx_web_html_test.f_string_from_p_indent(context)
    )
    return output
  }
}
