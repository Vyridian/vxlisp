'strict mode'

import vx_core from "../../vx/core.js"
import vx_type from "../../vx/type.js"


export default class vx_web_html {


  /**
   * type: body
   * Body Tag
   */
  static t_body = {}

  /**
   * type: details
   * Details Tag
   */
  static t_details = {}

  /**
   * type: div
   * Div Tag
   */
  static t_div = {}

  /**
   * type: divchild
   * Div Child Trait
   */
  static t_divchild = {}

  /**
   * type: divchildlist
   * List of divchild
   */
  static t_divchildlist = {}

  /**
   * type: divlist
   * List of div
   */
  static t_divlist = {}

  /**
   * type: footer
   * Body Tag
   */
  static t_footer = {}

  /**
   * type: h1
   * Header 1 Tag
   */
  static t_h1 = {}

  /**
   * type: h2
   * Header 2 Tag
   */
  static t_h2 = {}

  /**
   * type: h3
   * Header 3 Tag
   */
  static t_h3 = {}

  /**
   * type: head
   * Head Tag
   */
  static t_head = {}

  /**
   * type: headchild
   * Head Child Trait
   */
  static t_headchild = {}

  /**
   * type: headchildlist
   * List of headchild
   */
  static t_headchildlist = {}

  /**
   * type: html
   * Html Tag
   */
  static t_html = {}

  /**
   * type: meta
   * Meta Tag
   */
  static t_meta = {}

  /**
   * type: node
   * Common Html Node Trait
   */
  static t_node = {}

  /**
   * type: nodelist
   * List of node
   */
  static t_nodelist = {}

  /**
   * type: p
   * Paragraph Tag
   */
  static t_p = {}

  /**
   * type: propmap
   * Map of props
   */
  static t_propmap = {}

  /**
   * type: style
   * Programmable Cascading Style
   */
  static t_style = {}

  /**
   * type: stylelist
   * List of style
   */
  static t_stylelist = {}

  /**
   * type: stylemap
   * Map of style
   */
  static t_stylemap = {}

  /**
   * type: stylesheet
   * Programmable Cascading Style Sheet CSS type
   */
  static t_stylesheet = {}

  /**
   * type: table
   * <table> Tag
   */
  static t_table = {}

  /**
   * type: tbody
   * <tbody> Tag
   */
  static t_tbody = {}

  /**
   * type: td
   * <tr> Tag
   */
  static t_td = {}

  /**
   * type: tdlist
   * List of td
   */
  static t_tdlist = {}

  /**
   * type: thead
   * <thead> Tag
   */
  static t_thead = {}

  /**
   * type: title
   * Title Tag
   */
  static t_title = {}

  /**
   * type: tr
   * <tr> Tag
   */
  static t_tr = {}

  /**
   * type: trlist
   * List of tr
   */
  static t_trlist = {}
  /**
   * @function htmlstring_from_string
   * Convert text to HTML string
   * @param  {string} text
   * @return {string}
   */
  static t_htmlstring_from_string = {}
  static e_htmlstring_from_string = {vx_type: vx_web_html.t_htmlstring_from_string}

  // (func htmlstring<-string)
  static f_htmlstring_from_string(text) {
    let output = vx_core.e_string
    const str = "" + text
    output = str
      .replace(/&/g, "&amp;")
      .replace(/'/g, "\'")
      .replace(/>/g, "&gt;")   
      .replace(/</g, "&lt;")
    return output
  }

  /**
   * @function string_indent
   * @param  {int} indent
   * @return {string}
   */
  static t_string_indent = {}
  static e_string_indent = {vx_type: vx_web_html.t_string_indent}

  // (func string-indent)
  static f_string_indent(indent) {
    let output = vx_core.e_string
    output = vx_core.f_string_repeat("  ", indent)
    return output
  }

  /**
   * @function string_from_body_indent
   * Returns string from body
   * @param  {body} body
   * @param  {int} indent
   * @return {string}
   */
  static t_string_from_body_indent = {}
  static e_string_from_body_indent = {vx_type: vx_web_html.t_string_from_body_indent}

  // (func string<-body-indent)
  static f_string_from_body_indent(body, indent) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string, "list-1": vx_web_html.t_divchildlist},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const nodes = vx_core.f_any_from_struct({"any-1": vx_web_html.t_divchildlist, "struct-2": vx_web_html.t_body}, body, ":nodes")
        return vx_web_html.f_string_from_nodelist_tag_prop_indent(nodes, "body", "", indent)
      })
    )
    return output
  }

  /**
   * @function string_from_details_indent
   * Returns string from details
   * @param  {details} details
   * @param  {int} indent
   * @return {string}
   */
  static t_string_from_details_indent = {}
  static e_string_from_details_indent = {vx_type: vx_web_html.t_string_from_details_indent}

  // (func string<-details-indent)
  static f_string_from_details_indent(details, indent) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const sindent = vx_web_html.f_string_from_indent(indent)
        const summary = vx_core.f_any_from_struct({"any-1": vx_web_html.t_divchildlist, "struct-2": vx_web_html.t_details}, details, ":summary")
        const nodes = vx_core.f_any_from_struct({"any-1": vx_web_html.t_divchildlist, "struct-2": vx_web_html.t_details}, details, ":nodes")
        const ssummary = vx_web_html.f_string_from_nodelist_indent(
          summary,
          vx_core.f_plus(indent, 2)
        )
        const snodes = vx_web_html.f_string_from_nodelist_indent(
          nodes,
          vx_core.f_plus(indent, 1)
        )
        return vx_core.f_new(
          vx_core.t_string,
          sindent,
          "<details>",
          sindent,
          "  <summary>",
          ssummary,
          sindent,
          "  </summary>",
          snodes,
          sindent,
          "</details>"
        )
      })
    )
    return output
  }

  /**
   * @function string_from_div_indent
   * Returns string from div
   * @param  {div} div
   * @param  {int} indent
   * @return {string}
   */
  static t_string_from_div_indent = {}
  static e_string_from_div_indent = {vx_type: vx_web_html.t_string_from_div_indent}

  // (func string<-div-indent)
  static f_string_from_div_indent(div, indent) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string, "list-1": vx_web_html.t_divchildlist},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const nodes = vx_core.f_any_from_struct({"any-1": vx_web_html.t_divchildlist, "struct-2": vx_web_html.t_div}, div, ":nodes")
        const sid = vx_web_html.f_string_from_propname_val(
          "id",
          vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_web_html.t_div}, div, ":id")
        )
        const sstyle = vx_web_html.f_string_from_propstyle(
          vx_core.f_any_from_struct({"any-1": vx_web_html.t_style, "struct-2": vx_web_html.t_div}, div, ":style")
        )
        return vx_web_html.f_string_from_nodelist_tag_prop_indent(
          nodes,
          "div",
          vx_core.f_new(
            vx_core.t_string,
            sid,
            sstyle
          ),
          indent
        )
      })
    )
    return output
  }

  /**
   * @function string_from_footer_indent
   * Returns string from footer
   * @param  {footer} footer
   * @param  {int} indent
   * @return {string}
   */
  static t_string_from_footer_indent = {}
  static e_string_from_footer_indent = {vx_type: vx_web_html.t_string_from_footer_indent}

  // (func string<-footer-indent)
  static f_string_from_footer_indent(footer, indent) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string, "list-1": vx_web_html.t_divchildlist},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const nodes = vx_core.f_any_from_struct({"any-1": vx_web_html.t_divchildlist, "struct-2": vx_web_html.t_footer}, footer, ":nodes")
        return vx_web_html.f_string_from_nodelist_tag_prop_indent(nodes, "footer", "", indent)
      })
    )
    return output
  }

  /**
   * @function string_from_h1_indent
   * Returns string from h1
   * @param  {h1} h1
   * @param  {int} indent
   * @return {string}
   */
  static t_string_from_h1_indent = {}
  static e_string_from_h1_indent = {vx_type: vx_web_html.t_string_from_h1_indent}

  // (func string<-h1-indent)
  static f_string_from_h1_indent(h1, indent) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const sindent = vx_web_html.f_string_from_indent(indent)
        const text = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_web_html.t_h1}, h1, ":text")
        const sid = vx_web_html.f_string_from_propname_val(
          "id",
          vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_web_html.t_h1}, h1, ":id")
        )
        return vx_core.f_new(
          vx_core.t_string,
          sindent,
          "<h1",
          sid,
          ">",
          text,
          "</h1>"
        )
      })
    )
    return output
  }

  /**
   * @function string_from_h2_indent
   * Returns string from h2
   * @param  {h2} h2
   * @param  {int} indent
   * @return {string}
   */
  static t_string_from_h2_indent = {}
  static e_string_from_h2_indent = {vx_type: vx_web_html.t_string_from_h2_indent}

  // (func string<-h2-indent)
  static f_string_from_h2_indent(h2, indent) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const text = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_web_html.t_h2}, h2, ":text")
        const sindent = vx_web_html.f_string_from_indent(indent)
        const sid = vx_web_html.f_string_from_propname_val(
          "id",
          vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_web_html.t_h2}, h2, ":id")
        )
        return vx_core.f_new(
          vx_core.t_string,
          sindent,
          "<h2",
          sid,
          ">",
          text,
          "</h2>"
        )
      })
    )
    return output
  }

  /**
   * @function string_from_h3_indent
   * Returns string from h3
   * @param  {h3} h3
   * @param  {int} indent
   * @return {string}
   */
  static t_string_from_h3_indent = {}
  static e_string_from_h3_indent = {vx_type: vx_web_html.t_string_from_h3_indent}

  // (func string<-h3-indent)
  static f_string_from_h3_indent(h3, indent) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const text = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_web_html.t_h3}, h3, ":text")
        const sindent = vx_web_html.f_string_from_indent(indent)
        const sid = vx_web_html.f_string_from_propname_val(
          "id",
          vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_web_html.t_h3}, h3, ":id")
        )
        return vx_core.f_new(
          vx_core.t_string,
          sindent,
          "<h3",
          sid,
          ">",
          text,
          "</h3>"
        )
      })
    )
    return output
  }

  /**
   * @function string_from_head_indent
   * Returns string from head
   * @param  {head} head
   * @param  {int} indent
   * @return {string}
   */
  static t_string_from_head_indent = {}
  static e_string_from_head_indent = {vx_type: vx_web_html.t_string_from_head_indent}

  // (func string<-head-indent)
  static f_string_from_head_indent(head, indent) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string, "list-1": vx_web_html.t_headchildlist},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const nodes = vx_core.f_any_from_struct({"any-1": vx_web_html.t_headchildlist, "struct-2": vx_web_html.t_head}, head, ":nodes")
        return vx_web_html.f_string_from_nodelist_tag_prop_indent(nodes, "head", "", indent)
      })
    )
    return output
  }

  /**
   * @function string_from_html
   * Returns string from html
   * @param  {html} html
   * @return {string}
   */
  static t_string_from_html = {}
  static e_string_from_html = {vx_type: vx_web_html.t_string_from_html}

  // (func string<-html)
  static f_string_from_html(html) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const lang = vx_web_html.f_string_from_propname_val(
          "lang",
          vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_web_html.t_html}, html, ":lang")
        )
        const head = vx_core.f_any_from_struct({"any-1": vx_web_html.t_head, "struct-2": vx_web_html.t_html}, html, ":head")
        const body = vx_core.f_any_from_struct({"any-1": vx_web_html.t_body, "struct-2": vx_web_html.t_html}, html, ":body")
        const footer = vx_core.f_any_from_struct({"any-1": vx_web_html.t_footer, "struct-2": vx_web_html.t_html}, html, ":footer")
        const shead = vx_web_html.f_string_from_head_indent(head, 1)
        const sbody = vx_web_html.f_string_from_body_indent(body, 1)
        const sfooter = vx_web_html.f_string_from_footer_indent(footer, 1)
        return vx_core.f_new(
          vx_core.t_string,
          "<!DOCTYPE html>",
          vx_core.c_newline,
          "<html",
          lang,
          ">",
          shead,
          sbody,
          sfooter,
          vx_core.c_newline,
          "</html>"
        )
      })
    )
    return output
  }

  /**
   * @function string_from_indent
   * Returns a string to do indentation for a given indent count.
   * @param  {int} indent
   * @return {string}
   */
  static t_string_from_indent = {}
  static e_string_from_indent = {vx_type: vx_web_html.t_string_from_indent}

  // (func string<-indent)
  static f_string_from_indent(indent) {
    let output = vx_core.e_string
    output = vx_core.f_if_1(
      {"any-1": vx_core.t_string},
      vx_core.f_eq(indent, 0),
      "",
      vx_core.f_new(
        vx_core.t_string,
        vx_core.c_newline,
        vx_web_html.f_string_indent(indent)
      )
    )
    return output
  }

  /**
   * @function string_from_meta_indent
   * Returns string from head
   * @param  {meta} meta
   * @param  {int} indent
   * @return {string}
   */
  static t_string_from_meta_indent = {}
  static e_string_from_meta_indent = {vx_type: vx_web_html.t_string_from_meta_indent}

  // (func string<-meta-indent)
  static f_string_from_meta_indent(meta, indent) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const sindent = vx_web_html.f_string_from_indent(indent)
        const charset = vx_web_html.f_string_from_propname_val(
          "charset",
          vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_web_html.t_meta}, meta, ":charset")
        )
        return vx_core.f_new(
          vx_core.t_string,
          sindent,
          "<meta",
          charset,
          " />"
        )
      })
    )
    return output
  }

  /**
   * @function string_from_node_indent
   * Returns a string from any node
   * @param  {any} node
   * @param  {int} indent
   * @return {string}
   */
  static t_string_from_node_indent = {}
  static e_string_from_node_indent = {vx_type: vx_web_html.t_string_from_node_indent}

  // (func string<-node-indent)
  static f_string_from_node_indent(node, indent) {
    let output = vx_core.e_string
    output = vx_core.f_switch(
      {"any-1": vx_core.t_string, "any-2": vx_core.t_any},
      vx_core.f_type_from_any(node),
      vx_core.f_case_1(
        vx_web_html.t_body,
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_web_html.f_string_from_body_indent(
          vx_core.f_any_from_any({"any-1": vx_web_html.t_body}, node),
          indent
        )})
      ),
      vx_core.f_case_1(
        vx_web_html.t_details,
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_web_html.f_string_from_details_indent(
          vx_core.f_any_from_any({"any-1": vx_web_html.t_details}, node),
          indent
        )})
      ),
      vx_core.f_case_1(
        vx_web_html.t_div,
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_web_html.f_string_from_div_indent(
          vx_core.f_any_from_any({"any-1": vx_web_html.t_div}, node),
          indent
        )})
      ),
      vx_core.f_case_1(
        vx_web_html.t_h1,
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_web_html.f_string_from_h1_indent(
          vx_core.f_any_from_any({"any-1": vx_web_html.t_h1}, node),
          indent
        )})
      ),
      vx_core.f_case_1(
        vx_web_html.t_h2,
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_web_html.f_string_from_h2_indent(
          vx_core.f_any_from_any({"any-1": vx_web_html.t_h2}, node),
          indent
        )})
      ),
      vx_core.f_case_1(
        vx_web_html.t_h3,
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_web_html.f_string_from_h3_indent(
          vx_core.f_any_from_any({"any-1": vx_web_html.t_h3}, node),
          indent
        )})
      ),
      vx_core.f_case_1(
        vx_web_html.t_head,
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_web_html.f_string_from_head_indent(
          vx_core.f_any_from_any({"any-1": vx_web_html.t_head}, node),
          indent
        )})
      ),
      vx_core.f_case_1(
        vx_web_html.t_footer,
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_web_html.f_string_from_footer_indent(
          vx_core.f_any_from_any({"any-1": vx_web_html.t_footer}, node),
          indent
        )})
      ),
      vx_core.f_case_1(
        vx_web_html.t_meta,
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_web_html.f_string_from_meta_indent(
          vx_core.f_any_from_any({"any-1": vx_web_html.t_meta}, node),
          indent
        )})
      ),
      vx_core.f_case_1(
        vx_web_html.t_p,
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_web_html.f_string_from_p_indent(
          vx_core.f_any_from_any({"any-1": vx_web_html.t_p}, node),
          indent
        )})
      ),
      vx_core.f_case_1(
        vx_web_html.t_stylesheet,
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_web_html.f_string_from_stylesheet_indent(
          vx_core.f_any_from_any({"any-1": vx_web_html.t_stylesheet}, node),
          indent
        )})
      ),
      vx_core.f_case_1(
        vx_web_html.t_table,
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_web_html.f_string_from_table_indent(
          vx_core.f_any_from_any({"any-1": vx_web_html.t_table}, node),
          indent
        )})
      ),
      vx_core.f_case_1(
        vx_web_html.t_title,
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_web_html.f_string_from_title_indent(
          vx_core.f_any_from_any({"any-1": vx_web_html.t_title}, node),
          indent
        )})
      ),
      vx_core.f_case_1(
        vx_web_html.t_tbody,
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_web_html.f_string_from_tbody_indent(
          vx_core.f_any_from_any({"any-1": vx_web_html.t_tbody}, node),
          indent
        )})
      ),
      vx_core.f_case_1(
        vx_web_html.t_thead,
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_web_html.f_string_from_thead_indent(
          vx_core.f_any_from_any({"any-1": vx_web_html.t_thead}, node),
          indent
        )})
      ),
      vx_core.f_case_1(
        vx_web_html.t_td,
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_web_html.f_string_from_td_indent(
          vx_core.f_any_from_any({"any-1": vx_web_html.t_td}, node),
          indent
        )})
      ),
      vx_core.f_case_1(
        vx_web_html.t_tr,
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_web_html.f_string_from_tr_indent(
          vx_core.f_any_from_any({"any-1": vx_web_html.t_tr}, node),
          indent
        )})
      )
    )
    return output
  }

  /**
   * @function string_from_nodelist_indent
   * Returns a string from any node
   * @param  {list} nodelist
   * @param  {int} indent
   * @return {string}
   */
  static t_string_from_nodelist_indent = {}
  static e_string_from_nodelist_indent = {vx_type: vx_web_html.t_string_from_nodelist_indent}

  // (func string<-nodelist-indent)
  static f_string_from_nodelist_indent(nodelist, indent) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const textlist = vx_core.f_list_from_list(
          {"any-1": vx_core.t_string, "list-1": vx_core.t_stringlist},
          nodelist,
          vx_core.f_new(vx_core.t_any_from_any, (node) => 
            vx_web_html.f_string_from_node_indent(node, indent))
        )
        return vx_type.f_string_from_stringlist_join(textlist, "")
      })
    )
    return output
  }

  /**
   * @function string_from_nodelist_tag_prop_indent
   * Returns string from generic nodelist
   * @param  {list} nodes
   * @param  {string} tag
   * @param  {string} prop
   * @param  {int} indent
   * @return {string}
   */
  static t_string_from_nodelist_tag_prop_indent = {}
  static e_string_from_nodelist_tag_prop_indent = {vx_type: vx_web_html.t_string_from_nodelist_tag_prop_indent}

  // (func string<-nodelist-tag-prop-indent)
  static f_string_from_nodelist_tag_prop_indent(nodes, tag, prop, indent) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const text = vx_web_html.f_string_from_nodelist_indent(
          nodes,
          vx_core.f_plus1(indent)
        )
        const sindent = vx_web_html.f_string_from_indent(indent)
        const eindent = vx_core.f_if_2(
          {"any-1": vx_core.t_string},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty(text)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return ""})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty(sindent)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.c_newline})
          ),
          vx_core.f_else(vx_core.f_new(vx_core.t_any_from_func, () => {return sindent}))
        )
        return vx_core.f_new(
          vx_core.t_string,
          sindent,
          "<",
          tag,
          prop,
          ">",
          text,
          eindent,
          "</",
          tag,
          ">"
        )
      })
    )
    return output
  }

  /**
   * @function string_from_p_indent
   * Returns string from p
   * @param  {p} p
   * @param  {int} indent
   * @return {string}
   */
  static t_string_from_p_indent = {}
  static e_string_from_p_indent = {vx_type: vx_web_html.t_string_from_p_indent}

  // (func string<-p-indent)
  static f_string_from_p_indent(p, indent) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const sindent = vx_web_html.f_string_from_indent(indent)
        const text = vx_web_html.f_htmlstring_from_string(
          vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_web_html.t_p}, p, ":text")
        )
        const sid = vx_web_html.f_string_from_propname_val(
          "id",
          vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_web_html.t_p}, p, ":id")
        )
        const sstyle = vx_web_html.f_string_from_propstyle(
          vx_core.f_any_from_struct({"any-1": vx_web_html.t_style, "struct-2": vx_web_html.t_p}, p, ":style")
        )
        return vx_core.f_new(
          vx_core.t_string,
          sindent,
          "<p",
          sid,
          sstyle,
          ">",
          text,
          "</p>"
        )
      })
    )
    return output
  }

  /**
   * @function string_from_propname_val
   * Returns ' key=\"val\"' if val is not blank.
   * @param  {string} key
   * @param  {string} val
   * @return {string}
   */
  static t_string_from_propname_val = {}
  static e_string_from_propname_val = {vx_type: vx_web_html.t_string_from_propname_val}

  // (func string<-propname-val)
  static f_string_from_propname_val(key, val) {
    let output = vx_core.e_string
    output = vx_core.f_if(
      {"any-1": vx_core.t_string},
      vx_core.f_notempty(val),
      vx_core.f_new(
        vx_core.t_string,
        " ",
        key,
        "=",
        vx_core.c_quote,
        val,
        vx_core.c_quote
      )
    )
    return output
  }

  /**
   * @function string_from_propstyle
   * Returns ' class=\"style.name\"' if style is not empty.
   * @param  {style} style
   * @return {string}
   */
  static t_string_from_propstyle = {}
  static e_string_from_propstyle = {vx_type: vx_web_html.t_string_from_propstyle}

  // (func string<-propstyle)
  static f_string_from_propstyle(style) {
    let output = vx_core.e_string
    output = vx_core.f_if(
      {"any-1": vx_core.t_string},
      vx_core.f_notempty_1(style),
      vx_core.f_new(
        vx_core.t_string,
        " class=",
        vx_core.c_quote,
        vx_type.f_string_from_string_start(
          vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_web_html.t_style}, style, ":name"),
          2
        ),
        vx_core.c_quote
      )
    )
    return output
  }

  /**
   * @function string_from_style_indent
   * Returns indent'name {key: val;}' for each style.
   * @param  {style} style
   * @param  {int} indent
   * @return {string}
   */
  static t_string_from_style_indent = {}
  static e_string_from_style_indent = {vx_type: vx_web_html.t_string_from_style_indent}

  // (func string<-style-indent)
  static f_string_from_style_indent(style, indent) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const sindent = vx_web_html.f_string_from_indent(indent)
        const name = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_web_html.t_style}, style, ":name")
        const propmap = vx_core.f_any_from_struct({"any-1": vx_web_html.t_propmap, "struct-2": vx_web_html.t_style}, style, ":props")
        const stext = vx_web_html.f_string_from_stylepropmap_indent(
          propmap,
          vx_core.f_plus1(indent)
        )
        return vx_core.f_new(
          vx_core.t_string,
          sindent,
          name,
          " {",
          stext,
          sindent,
          "}"
        )
      })
    )
    return output
  }

  /**
   * @function string_from_stylelist_indent
   * Return a string from a stylelist
   * @param  {stylelist} stylelist
   * @param  {int} indent
   * @return {string}
   */
  static t_string_from_stylelist_indent = {}
  static e_string_from_stylelist_indent = {vx_type: vx_web_html.t_string_from_stylelist_indent}

  // (func string<-stylelist-indent)
  static f_string_from_stylelist_indent(stylelist, indent) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const sstyles = vx_core.f_list_from_list(
          {"any-1": vx_core.t_string, "any-2": vx_web_html.t_style, "list-1": vx_core.t_stringlist, "list-2": vx_web_html.t_stylelist},
          stylelist,
          vx_core.f_new(vx_core.t_any_from_any, (substyle) => 
            vx_web_html.f_string_from_style_indent(substyle, indent))
        )
        return vx_type.f_string_from_stringlist_join(sstyles, "")
      })
    )
    return output
  }

  /**
   * @function string_from_stylepropmap_indent
   * Returns indent'key: val;' for each prop.
   * @param  {propmap} propmap
   * @param  {int} indent
   * @return {string}
   */
  static t_string_from_stylepropmap_indent = {}
  static e_string_from_stylepropmap_indent = {vx_type: vx_web_html.t_string_from_stylepropmap_indent}

  // (func string<-stylepropmap-indent)
  static f_string_from_stylepropmap_indent(propmap, indent) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const sindent = vx_web_html.f_string_from_indent(indent)
        const sprops = vx_core.f_list_from_map(
          {"any-1": vx_core.t_string, "any-2": vx_core.t_string, "list-1": vx_core.t_stringlist, "map-2": vx_web_html.t_propmap},
          propmap,
          vx_core.f_new(vx_core.t_any_from_key_value, ([key, val]) => 
            vx_core.f_new(
              vx_core.t_string,
              sindent,
              key,
              ": ",
              val,
              ";"
            ))
        )
        return vx_type.f_string_from_stringlist_join(sprops, "")
      })
    )
    return output
  }

  /**
   * @function string_from_stylesheet_indent
   * Returns string representation of given stylesheet.
   * @param  {stylesheet} stylesheet
   * @param  {int} indent
   * @return {string}
   */
  static t_string_from_stylesheet_indent = {}
  static e_string_from_stylesheet_indent = {vx_type: vx_web_html.t_string_from_stylesheet_indent}

  // (func string<-stylesheet-indent)
  static f_string_from_stylesheet_indent(stylesheet, indent) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const text = vx_web_html.f_string_from_stylelist_indent(
          vx_core.f_any_from_struct({"any-1": vx_web_html.t_stylelist, "struct-2": vx_web_html.t_stylesheet}, stylesheet, ":styles"),
          vx_core.f_plus1(indent)
        )
        const sindent = vx_web_html.f_string_from_indent(indent)
        const eindent = vx_core.f_if(
          {"any-1": vx_core.t_string},
          vx_core.f_notempty(text),
          sindent
        )
        return vx_core.f_new(
          vx_core.t_string,
          sindent,
          "<style>",
          text,
          eindent,
          "</style>"
        )
      })
    )
    return output
  }

  /**
   * @function string_from_table_indent
   * Returns string from table
   * @param  {table} table
   * @param  {int} indent
   * @return {string}
   */
  static t_string_from_table_indent = {}
  static e_string_from_table_indent = {vx_type: vx_web_html.t_string_from_table_indent}

  // (func string<-table-indent)
  static f_string_from_table_indent(table, indent) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const sindent = vx_web_html.f_string_from_indent(indent)
        const sid = vx_web_html.f_string_from_propname_val(
          "id",
          vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_web_html.t_table}, table, ":id")
        )
        const thead = vx_core.f_any_from_struct({"any-1": vx_web_html.t_thead, "struct-2": vx_web_html.t_table}, table, ":thead")
        const tbody = vx_core.f_any_from_struct({"any-1": vx_web_html.t_tbody, "struct-2": vx_web_html.t_table}, table, ":tbody")
        const shead = vx_web_html.f_string_from_thead_indent(
          thead,
          vx_core.f_plus1(indent)
        )
        const sbody = vx_web_html.f_string_from_tbody_indent(
          tbody,
          vx_core.f_plus1(indent)
        )
        return vx_core.f_new(
          vx_core.t_string,
          sindent,
          "<table",
          sid,
          ">",
          shead,
          sbody,
          sindent,
          "</table>"
        )
      })
    )
    return output
  }

  /**
   * @function string_from_tbody_indent
   * Returns string from tbody
   * @param  {tbody} tbody
   * @param  {int} indent
   * @return {string}
   */
  static t_string_from_tbody_indent = {}
  static e_string_from_tbody_indent = {vx_type: vx_web_html.t_string_from_tbody_indent}

  // (func string<-tbody-indent)
  static f_string_from_tbody_indent(tbody, indent) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string, "list-1": vx_web_html.t_trlist},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const nodes = vx_core.f_any_from_struct({"any-1": vx_web_html.t_trlist, "struct-2": vx_web_html.t_tbody}, tbody, ":nodes")
        return vx_web_html.f_string_from_nodelist_tag_prop_indent(nodes, "tbody", "", indent)
      })
    )
    return output
  }

  /**
   * @function string_from_td_indent
   * Returns string from td
   * @param  {td} td
   * @param  {int} indent
   * @return {string}
   */
  static t_string_from_td_indent = {}
  static e_string_from_td_indent = {vx_type: vx_web_html.t_string_from_td_indent}

  // (func string<-td-indent)
  static f_string_from_td_indent(td, indent) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string, "list-1": vx_web_html.t_divchildlist},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const nodes = vx_core.f_any_from_struct({"any-1": vx_web_html.t_divchildlist, "struct-2": vx_web_html.t_td}, td, ":nodes")
        return vx_web_html.f_string_from_nodelist_tag_prop_indent(nodes, "td", "", indent)
      })
    )
    return output
  }

  /**
   * @function string_from_thead_indent
   * Returns string from thead
   * @param  {thead} thead
   * @param  {int} indent
   * @return {string}
   */
  static t_string_from_thead_indent = {}
  static e_string_from_thead_indent = {vx_type: vx_web_html.t_string_from_thead_indent}

  // (func string<-thead-indent)
  static f_string_from_thead_indent(thead, indent) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string, "list-1": vx_web_html.t_trlist},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const nodes = vx_core.f_any_from_struct({"any-1": vx_web_html.t_trlist, "struct-2": vx_web_html.t_thead}, thead, ":nodes")
        return vx_web_html.f_string_from_nodelist_tag_prop_indent(nodes, "thead", "", indent)
      })
    )
    return output
  }

  /**
   * @function string_from_title_indent
   * Returns string from h2
   * @param  {title} title
   * @param  {int} indent
   * @return {string}
   */
  static t_string_from_title_indent = {}
  static e_string_from_title_indent = {vx_type: vx_web_html.t_string_from_title_indent}

  // (func string<-title-indent)
  static f_string_from_title_indent(title, indent) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const sindent = vx_web_html.f_string_from_indent(indent)
        const text = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_web_html.t_title}, title, ":text")
        return vx_core.f_new(
          vx_core.t_string,
          sindent,
          "<title>",
          text,
          "</title>"
        )
      })
    )
    return output
  }

  /**
   * @function string_from_tr_indent
   * Returns string from tr
   * @param  {tr} tr
   * @param  {int} indent
   * @return {string}
   */
  static t_string_from_tr_indent = {}
  static e_string_from_tr_indent = {vx_type: vx_web_html.t_string_from_tr_indent}

  // (func string<-tr-indent)
  static f_string_from_tr_indent(tr, indent) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string, "list-1": vx_web_html.t_tdlist},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const nodes = vx_core.f_any_from_struct({"any-1": vx_web_html.t_tdlist, "struct-2": vx_web_html.t_tr}, tr, ":nodes")
        return vx_web_html.f_string_from_nodelist_tag_prop_indent(nodes, "tr", "", indent)
      })
    )
    return output
  }

  /**
   * @function string_from_uri
   * Decode a URI string
   * @param  {string} uri
   * @return {string}
   */
  static t_string_from_uri = {}
  static e_string_from_uri = {vx_type: vx_web_html.t_string_from_uri}

  // (func string<-uri)
  static f_string_from_uri(uri) {
    let output = vx_core.e_string
    output = decodeURI(uri)
    return output
  }

  /**
   * @function style_from_stylesheet_name
   * Return style from stylesheet.stylemap
   * @param  {stylesheet} stylesheet
   * @param  {string} name
   * @return {style}
   */
  static t_style_from_stylesheet_name = {}
  static e_style_from_stylesheet_name = {vx_type: vx_web_html.t_style_from_stylesheet_name}

  // (func style<-stylesheet-name)
  static f_style_from_stylesheet_name(stylesheet, name) {
    let output = vx_web_html.e_style
    output = vx_core.f_any_from_map(
      {"any-1": vx_web_html.t_style, "map-1": vx_web_html.t_stylemap},
      vx_web_html.f_stylemap_from_stylesheet(stylesheet),
      name
    )
    return output
  }

  /**
   * @function stylemap_from_stylelist
   * Returns a stylemap from a given stylelist
   * @param  {stylelist} stylelist
   * @return {stylemap}
   */
  static t_stylemap_from_stylelist = {}
  static e_stylemap_from_stylelist = {vx_type: vx_web_html.t_stylemap_from_stylelist}

  // (func stylemap<-stylelist)
  static f_stylemap_from_stylelist(stylelist) {
    let output = vx_web_html.e_stylemap
    output = vx_core.f_map_from_list(
      {"any-1": vx_web_html.t_style, "any-2": vx_web_html.t_style, "list-2": vx_web_html.t_stylelist, "map-1": vx_web_html.t_stylemap, "struct-2": vx_web_html.t_style},
      stylelist,
      vx_core.f_new(vx_core.t_any_from_any, (style) => 
        vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_web_html.t_style}, style, ":name"))
    )
    return output
  }

  /**
   * @function stylemap_from_stylesheet
   * Return stylemap from stylesheet
   * @param  {stylesheet} stylesheet
   * @return {stylemap}
   */
  static t_stylemap_from_stylesheet = {}
  static e_stylemap_from_stylesheet = {vx_type: vx_web_html.t_stylemap_from_stylesheet}

  // (func stylemap<-stylesheet)
  static f_stylemap_from_stylesheet(stylesheet) {
    let output = vx_web_html.e_stylemap
    output = vx_core.f_any_from_struct({"any-1": vx_web_html.t_stylemap, "struct-2": vx_web_html.t_stylesheet}, stylesheet, ":stylemap")
    return output
  }

  /**
   * @function styles_from_stylesheet
   * Return style from stylesheet.stylemap
   * @param  {stylesheet} stylesheet
   * @return {stylelist}
   */
  static t_styles_from_stylesheet = {}
  static e_styles_from_stylesheet = {vx_type: vx_web_html.t_styles_from_stylesheet}

  // (func styles<-stylesheet)
  static f_styles_from_stylesheet(stylesheet) {
    let output = vx_web_html.e_stylelist
    output = vx_core.f_any_from_struct({"any-1": vx_web_html.t_stylelist, "struct-2": vx_web_html.t_stylesheet}, stylesheet, ":styles")
    return output
  }

  /**
   * @function stylesheet_loadmap
   * Decode a URI string
   * @param  {stylesheet} stylesheet
   * @return {stylesheet}
   */
  static t_stylesheet_loadmap = {}
  static e_stylesheet_loadmap = {vx_type: vx_web_html.t_stylesheet_loadmap}

  // (func stylesheet-loadmap)
  static f_stylesheet_loadmap(stylesheet) {
    let output = vx_web_html.e_stylesheet
    output = vx_core.f_copy(
      stylesheet,
      ":stylemap",
      vx_web_html.f_stylemap_from_stylelist(
        vx_core.f_any_from_struct({"any-1": vx_web_html.t_stylelist, "struct-2": vx_web_html.t_stylesheet}, stylesheet, ":styles")
      )
    )
    return output
  }

  /**
   * @function uri_from_string
   * Encode a URI string
   * @param  {string} text
   * @return {string}
   */
  static t_uri_from_string = {}
  static e_uri_from_string = {vx_type: vx_web_html.t_uri_from_string}

  // (func uri<-string)
  static f_uri_from_string(text) {
    let output = vx_core.e_string
    output = encodeURI(text)
    return output
  }

  // empty types
  static e_body = {}
  static e_details = {}
  static e_div = {}
  static e_divchild = {}
  static e_divchildlist = []
  static e_divlist = []
  static e_footer = {}
  static e_h1 = {}
  static e_h2 = {}
  static e_h3 = {}
  static e_head = {}
  static e_headchild = {}
  static e_headchildlist = []
  static e_html = {}
  static e_meta = {}
  static e_node = {}
  static e_nodelist = []
  static e_p = {}
  static e_propmap = {}
  static e_style = {}
  static e_stylelist = []
  static e_stylemap = {}
  static e_stylesheet = {}
  static e_table = {}
  static e_tbody = {}
  static e_td = {}
  static e_tdlist = []
  static e_thead = {}
  static e_title = {}
  static e_tr = {}
  static e_trlist = []


  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "body": vx_web_html.e_body,
      "details": vx_web_html.e_details,
      "div": vx_web_html.e_div,
      "divchild": vx_web_html.e_divchild,
      "divchildlist": vx_web_html.e_divchildlist,
      "divlist": vx_web_html.e_divlist,
      "footer": vx_web_html.e_footer,
      "h1": vx_web_html.e_h1,
      "h2": vx_web_html.e_h2,
      "h3": vx_web_html.e_h3,
      "head": vx_web_html.e_head,
      "headchild": vx_web_html.e_headchild,
      "headchildlist": vx_web_html.e_headchildlist,
      "html": vx_web_html.e_html,
      "meta": vx_web_html.e_meta,
      "node": vx_web_html.e_node,
      "nodelist": vx_web_html.e_nodelist,
      "p": vx_web_html.e_p,
      "propmap": vx_web_html.e_propmap,
      "style": vx_web_html.e_style,
      "stylelist": vx_web_html.e_stylelist,
      "stylemap": vx_web_html.e_stylemap,
      "stylesheet": vx_web_html.e_stylesheet,
      "table": vx_web_html.e_table,
      "tbody": vx_web_html.e_tbody,
      "td": vx_web_html.e_td,
      "tdlist": vx_web_html.e_tdlist,
      "thead": vx_web_html.e_thead,
      "title": vx_web_html.e_title,
      "tr": vx_web_html.e_tr,
      "trlist": vx_web_html.e_trlist,
      "htmlstring<-string": vx_web_html.e_htmlstring_from_string,
      "string-indent": vx_web_html.e_string_indent,
      "string<-body-indent": vx_web_html.e_string_from_body_indent,
      "string<-details-indent": vx_web_html.e_string_from_details_indent,
      "string<-div-indent": vx_web_html.e_string_from_div_indent,
      "string<-footer-indent": vx_web_html.e_string_from_footer_indent,
      "string<-h1-indent": vx_web_html.e_string_from_h1_indent,
      "string<-h2-indent": vx_web_html.e_string_from_h2_indent,
      "string<-h3-indent": vx_web_html.e_string_from_h3_indent,
      "string<-head-indent": vx_web_html.e_string_from_head_indent,
      "string<-html": vx_web_html.e_string_from_html,
      "string<-indent": vx_web_html.e_string_from_indent,
      "string<-meta-indent": vx_web_html.e_string_from_meta_indent,
      "string<-node-indent": vx_web_html.e_string_from_node_indent,
      "string<-nodelist-indent": vx_web_html.e_string_from_nodelist_indent,
      "string<-nodelist-tag-prop-indent": vx_web_html.e_string_from_nodelist_tag_prop_indent,
      "string<-p-indent": vx_web_html.e_string_from_p_indent,
      "string<-propname-val": vx_web_html.e_string_from_propname_val,
      "string<-propstyle": vx_web_html.e_string_from_propstyle,
      "string<-style-indent": vx_web_html.e_string_from_style_indent,
      "string<-stylelist-indent": vx_web_html.e_string_from_stylelist_indent,
      "string<-stylepropmap-indent": vx_web_html.e_string_from_stylepropmap_indent,
      "string<-stylesheet-indent": vx_web_html.e_string_from_stylesheet_indent,
      "string<-table-indent": vx_web_html.e_string_from_table_indent,
      "string<-tbody-indent": vx_web_html.e_string_from_tbody_indent,
      "string<-td-indent": vx_web_html.e_string_from_td_indent,
      "string<-thead-indent": vx_web_html.e_string_from_thead_indent,
      "string<-title-indent": vx_web_html.e_string_from_title_indent,
      "string<-tr-indent": vx_web_html.e_string_from_tr_indent,
      "string<-uri": vx_web_html.e_string_from_uri,
      "style<-stylesheet-name": vx_web_html.e_style_from_stylesheet_name,
      "stylemap<-stylelist": vx_web_html.e_stylemap_from_stylelist,
      "stylemap<-stylesheet": vx_web_html.e_stylemap_from_stylesheet,
      "styles<-stylesheet": vx_web_html.e_styles_from_stylesheet,
      "stylesheet-loadmap": vx_web_html.e_stylesheet_loadmap,
      "uri<-string": vx_web_html.e_uri_from_string
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "htmlstring<-string": vx_web_html.t_htmlstring_from_string,
      "string-indent": vx_web_html.t_string_indent,
      "string<-body-indent": vx_web_html.t_string_from_body_indent,
      "string<-details-indent": vx_web_html.t_string_from_details_indent,
      "string<-div-indent": vx_web_html.t_string_from_div_indent,
      "string<-footer-indent": vx_web_html.t_string_from_footer_indent,
      "string<-h1-indent": vx_web_html.t_string_from_h1_indent,
      "string<-h2-indent": vx_web_html.t_string_from_h2_indent,
      "string<-h3-indent": vx_web_html.t_string_from_h3_indent,
      "string<-head-indent": vx_web_html.t_string_from_head_indent,
      "string<-html": vx_web_html.t_string_from_html,
      "string<-indent": vx_web_html.t_string_from_indent,
      "string<-meta-indent": vx_web_html.t_string_from_meta_indent,
      "string<-node-indent": vx_web_html.t_string_from_node_indent,
      "string<-nodelist-indent": vx_web_html.t_string_from_nodelist_indent,
      "string<-nodelist-tag-prop-indent": vx_web_html.t_string_from_nodelist_tag_prop_indent,
      "string<-p-indent": vx_web_html.t_string_from_p_indent,
      "string<-propname-val": vx_web_html.t_string_from_propname_val,
      "string<-propstyle": vx_web_html.t_string_from_propstyle,
      "string<-style-indent": vx_web_html.t_string_from_style_indent,
      "string<-stylelist-indent": vx_web_html.t_string_from_stylelist_indent,
      "string<-stylepropmap-indent": vx_web_html.t_string_from_stylepropmap_indent,
      "string<-stylesheet-indent": vx_web_html.t_string_from_stylesheet_indent,
      "string<-table-indent": vx_web_html.t_string_from_table_indent,
      "string<-tbody-indent": vx_web_html.t_string_from_tbody_indent,
      "string<-td-indent": vx_web_html.t_string_from_td_indent,
      "string<-thead-indent": vx_web_html.t_string_from_thead_indent,
      "string<-title-indent": vx_web_html.t_string_from_title_indent,
      "string<-tr-indent": vx_web_html.t_string_from_tr_indent,
      "string<-uri": vx_web_html.t_string_from_uri,
      "style<-stylesheet-name": vx_web_html.t_style_from_stylesheet_name,
      "stylemap<-stylelist": vx_web_html.t_stylemap_from_stylelist,
      "stylemap<-stylesheet": vx_web_html.t_stylemap_from_stylesheet,
      "styles<-stylesheet": vx_web_html.t_styles_from_stylesheet,
      "stylesheet-loadmap": vx_web_html.t_stylesheet_loadmap,
      "uri<-string": vx_web_html.t_uri_from_string
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      "body": vx_web_html.t_body,
      "details": vx_web_html.t_details,
      "div": vx_web_html.t_div,
      "divchild": vx_web_html.t_divchild,
      "divchildlist": vx_web_html.t_divchildlist,
      "divlist": vx_web_html.t_divlist,
      "footer": vx_web_html.t_footer,
      "h1": vx_web_html.t_h1,
      "h2": vx_web_html.t_h2,
      "h3": vx_web_html.t_h3,
      "head": vx_web_html.t_head,
      "headchild": vx_web_html.t_headchild,
      "headchildlist": vx_web_html.t_headchildlist,
      "html": vx_web_html.t_html,
      "meta": vx_web_html.t_meta,
      "node": vx_web_html.t_node,
      "nodelist": vx_web_html.t_nodelist,
      "p": vx_web_html.t_p,
      "propmap": vx_web_html.t_propmap,
      "style": vx_web_html.t_style,
      "stylelist": vx_web_html.t_stylelist,
      "stylemap": vx_web_html.t_stylemap,
      "stylesheet": vx_web_html.t_stylesheet,
      "table": vx_web_html.t_table,
      "tbody": vx_web_html.t_tbody,
      "td": vx_web_html.t_td,
      "tdlist": vx_web_html.t_tdlist,
      "thead": vx_web_html.t_thead,
      "title": vx_web_html.t_title,
      "tr": vx_web_html.t_tr,
      "trlist": vx_web_html.t_trlist
    })
    const pkg = vx_core.vx_new_struct(vx_core.t_package, {
      "name": "vx/web/html",
      "constmap": constmap,
      "emptymap": emptymap,
      "funcmap": funcmap,
      "typemap": typemap
    })
    vx_core.vx_global_package_set(pkg)

    // (type body)
    vx_web_html.t_body['vx_type'] = vx_core.t_type
    vx_web_html.t_body['vx_value'] = {
      name          : "body",
      pkgname       : "vx/web/html",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "nodes": {
          "name" : "nodes",
          "type" : vx_web_html.t_divchildlist,
          "multi": true
        }
      },
      proplast      : {
        "name" : "nodes",
        "type" : vx_web_html.t_divchildlist,
        "multi": true
      }
    }
    vx_web_html.e_body['vx_type'] = vx_web_html.t_body
    vx_web_html.e_body['vx_value'] = {}

    // (type details)
    vx_web_html.t_details['vx_type'] = vx_core.t_type
    vx_web_html.t_details['vx_value'] = {
      name          : "details",
      pkgname       : "vx/web/html",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [vx_web_html.t_node, vx_web_html.t_divchild],
      properties    : {
        "id": {
          "name" : "id",
          "type" : vx_core.t_string,
          "multi": false
        },
        "style": {
          "name" : "style",
          "type" : vx_web_html.t_style,
          "multi": false
        },
        "summary": {
          "name" : "summary",
          "type" : vx_web_html.t_divchildlist,
          "multi": false
        },
        "nodes": {
          "name" : "nodes",
          "type" : vx_web_html.t_divchildlist,
          "multi": false
        }
      },
      proplast      : {
        "name" : "nodes",
        "type" : vx_web_html.t_divchildlist,
        "multi": false
      }
    }
    vx_web_html.e_details['vx_type'] = vx_web_html.t_details
    vx_web_html.e_details['vx_value'] = {}

    // (type div)
    vx_web_html.t_div['vx_type'] = vx_core.t_type
    vx_web_html.t_div['vx_value'] = {
      name          : "div",
      pkgname       : "vx/web/html",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [vx_web_html.t_node, vx_web_html.t_divchild],
      properties    : {
        "id": {
          "name" : "id",
          "type" : vx_core.t_string,
          "multi": false
        },
        "style": {
          "name" : "style",
          "type" : vx_web_html.t_style,
          "multi": false
        },
        "nodes": {
          "name" : "nodes",
          "type" : vx_web_html.t_divchildlist,
          "multi": true
        }
      },
      proplast      : {
        "name" : "nodes",
        "type" : vx_web_html.t_divchildlist,
        "multi": true
      }
    }
    vx_web_html.e_div['vx_type'] = vx_web_html.t_div
    vx_web_html.e_div['vx_value'] = {}

    // (type divchild)
    vx_web_html.t_divchild['vx_type'] = vx_core.t_type
    vx_web_html.t_divchild['vx_value'] = {
      name          : "divchild",
      pkgname       : "vx/web/html",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_web_html.e_divchild['vx_type'] = vx_web_html.t_divchild
    vx_web_html.e_divchild['vx_value'] = {}

    // (type divchildlist)
    vx_web_html.t_divchildlist['vx_type'] = vx_core.t_type
    vx_web_html.t_divchildlist['vx_value'] = {
      name          : "divchildlist",
      pkgname       : "vx/web/html",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_web_html.t_divchild],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_web_html.e_divchildlist['vx_type'] = vx_web_html.t_divchildlist

    // (type divlist)
    vx_web_html.t_divlist['vx_type'] = vx_core.t_type
    vx_web_html.t_divlist['vx_value'] = {
      name          : "divlist",
      pkgname       : "vx/web/html",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_web_html.t_div],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_web_html.e_divlist['vx_type'] = vx_web_html.t_divlist

    // (type footer)
    vx_web_html.t_footer['vx_type'] = vx_core.t_type
    vx_web_html.t_footer['vx_value'] = {
      name          : "footer",
      pkgname       : "vx/web/html",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "nodes": {
          "name" : "nodes",
          "type" : vx_web_html.t_divchildlist,
          "multi": true
        }
      },
      proplast      : {
        "name" : "nodes",
        "type" : vx_web_html.t_divchildlist,
        "multi": true
      }
    }
    vx_web_html.e_footer['vx_type'] = vx_web_html.t_footer
    vx_web_html.e_footer['vx_value'] = {}

    // (type h1)
    vx_web_html.t_h1['vx_type'] = vx_core.t_type
    vx_web_html.t_h1['vx_value'] = {
      name          : "h1",
      pkgname       : "vx/web/html",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [vx_web_html.t_node, vx_web_html.t_divchild],
      properties    : {
        "id": {
          "name" : "id",
          "type" : vx_core.t_string,
          "multi": false
        },
        "style": {
          "name" : "style",
          "type" : vx_web_html.t_style,
          "multi": false
        },
        "text": {
          "name" : "text",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "text",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    vx_web_html.e_h1['vx_type'] = vx_web_html.t_h1
    vx_web_html.e_h1['vx_value'] = {}

    // (type h2)
    vx_web_html.t_h2['vx_type'] = vx_core.t_type
    vx_web_html.t_h2['vx_value'] = {
      name          : "h2",
      pkgname       : "vx/web/html",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [vx_web_html.t_node, vx_web_html.t_divchild],
      properties    : {
        "id": {
          "name" : "id",
          "type" : vx_core.t_string,
          "multi": false
        },
        "style": {
          "name" : "style",
          "type" : vx_web_html.t_style,
          "multi": false
        },
        "text": {
          "name" : "text",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "text",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    vx_web_html.e_h2['vx_type'] = vx_web_html.t_h2
    vx_web_html.e_h2['vx_value'] = {}

    // (type h3)
    vx_web_html.t_h3['vx_type'] = vx_core.t_type
    vx_web_html.t_h3['vx_value'] = {
      name          : "h3",
      pkgname       : "vx/web/html",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [vx_web_html.t_node, vx_web_html.t_divchild],
      properties    : {
        "id": {
          "name" : "id",
          "type" : vx_core.t_string,
          "multi": false
        },
        "style": {
          "name" : "style",
          "type" : vx_web_html.t_style,
          "multi": false
        },
        "text": {
          "name" : "text",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "text",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    vx_web_html.e_h3['vx_type'] = vx_web_html.t_h3
    vx_web_html.e_h3['vx_value'] = {}

    // (type head)
    vx_web_html.t_head['vx_type'] = vx_core.t_type
    vx_web_html.t_head['vx_value'] = {
      name          : "head",
      pkgname       : "vx/web/html",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "nodes": {
          "name" : "nodes",
          "type" : vx_web_html.t_headchildlist,
          "multi": true
        }
      },
      proplast      : {
        "name" : "nodes",
        "type" : vx_web_html.t_headchildlist,
        "multi": true
      }
    }
    vx_web_html.e_head['vx_type'] = vx_web_html.t_head
    vx_web_html.e_head['vx_value'] = {}

    // (type headchild)
    vx_web_html.t_headchild['vx_type'] = vx_core.t_type
    vx_web_html.t_headchild['vx_value'] = {
      name          : "headchild",
      pkgname       : "vx/web/html",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_web_html.e_headchild['vx_type'] = vx_web_html.t_headchild
    vx_web_html.e_headchild['vx_value'] = {}

    // (type headchildlist)
    vx_web_html.t_headchildlist['vx_type'] = vx_core.t_type
    vx_web_html.t_headchildlist['vx_value'] = {
      name          : "headchildlist",
      pkgname       : "vx/web/html",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_web_html.t_headchild],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_web_html.e_headchildlist['vx_type'] = vx_web_html.t_headchildlist

    // (type html)
    vx_web_html.t_html['vx_type'] = vx_core.t_type
    vx_web_html.t_html['vx_value'] = {
      name          : "html",
      pkgname       : "vx/web/html",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "lang": {
          "name" : "lang",
          "type" : vx_core.t_string,
          "multi": false
        },
        "head": {
          "name" : "head",
          "type" : vx_web_html.t_head,
          "multi": false
        },
        "body": {
          "name" : "body",
          "type" : vx_web_html.t_body,
          "multi": false
        },
        "footer": {
          "name" : "footer",
          "type" : vx_web_html.t_footer,
          "multi": false
        }
      },
      proplast      : {
        "name" : "footer",
        "type" : vx_web_html.t_footer,
        "multi": false
      }
    }
    vx_web_html.e_html['vx_type'] = vx_web_html.t_html
    vx_web_html.e_html['vx_value'] = {}

    // (type meta)
    vx_web_html.t_meta['vx_type'] = vx_core.t_type
    vx_web_html.t_meta['vx_value'] = {
      name          : "meta",
      pkgname       : "vx/web/html",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [vx_web_html.t_node, vx_web_html.t_headchild],
      properties    : {
        "id": {
          "name" : "id",
          "type" : vx_core.t_string,
          "multi": false
        },
        "style": {
          "name" : "style",
          "type" : vx_web_html.t_style,
          "multi": false
        },
        "charset": {
          "name" : "charset",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "charset",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    vx_web_html.e_meta['vx_type'] = vx_web_html.t_meta
    vx_web_html.e_meta['vx_value'] = {}

    // (type node)
    vx_web_html.t_node['vx_type'] = vx_core.t_type
    vx_web_html.t_node['vx_value'] = {
      name          : "node",
      pkgname       : "vx/web/html",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "id": {
          "name" : "id",
          "type" : vx_core.t_string,
          "multi": false
        },
        "style": {
          "name" : "style",
          "type" : vx_web_html.t_style,
          "multi": false
        }
      },
      proplast      : {
        "name" : "style",
        "type" : vx_web_html.t_style,
        "multi": false
      }
    }
    vx_web_html.e_node['vx_type'] = vx_web_html.t_node
    vx_web_html.e_node['vx_value'] = {}

    // (type nodelist)
    vx_web_html.t_nodelist['vx_type'] = vx_core.t_type
    vx_web_html.t_nodelist['vx_value'] = {
      name          : "nodelist",
      pkgname       : "vx/web/html",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_web_html.t_node],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_web_html.e_nodelist['vx_type'] = vx_web_html.t_nodelist

    // (type p)
    vx_web_html.t_p['vx_type'] = vx_core.t_type
    vx_web_html.t_p['vx_value'] = {
      name          : "p",
      pkgname       : "vx/web/html",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [vx_web_html.t_node, vx_web_html.t_divchild],
      properties    : {
        "id": {
          "name" : "id",
          "type" : vx_core.t_string,
          "multi": false
        },
        "style": {
          "name" : "style",
          "type" : vx_web_html.t_style,
          "multi": false
        },
        "text": {
          "name" : "text",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "text",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    vx_web_html.e_p['vx_type'] = vx_web_html.t_p
    vx_web_html.e_p['vx_value'] = {}

    // (type propmap)
    vx_web_html.t_propmap['vx_type'] = vx_core.t_type
    vx_web_html.t_propmap['vx_value'] = {
      name          : "propmap",
      pkgname       : "vx/web/html",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_string],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_web_html.e_propmap['vx_type'] = vx_web_html.t_propmap
    vx_web_html.e_propmap['vx_value'] = {}

    // (type style)
    vx_web_html.t_style['vx_type'] = vx_core.t_type
    vx_web_html.t_style['vx_value'] = {
      name          : "style",
      pkgname       : "vx/web/html",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "props": {
          "name" : "props",
          "type" : vx_web_html.t_propmap,
          "multi": false
        }
      },
      proplast      : {
        "name" : "props",
        "type" : vx_web_html.t_propmap,
        "multi": false
      }
    }
    vx_web_html.e_style['vx_type'] = vx_web_html.t_style
    vx_web_html.e_style['vx_value'] = {}

    // (type stylelist)
    vx_web_html.t_stylelist['vx_type'] = vx_core.t_type
    vx_web_html.t_stylelist['vx_value'] = {
      name          : "stylelist",
      pkgname       : "vx/web/html",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_web_html.t_style],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_web_html.e_stylelist['vx_type'] = vx_web_html.t_stylelist

    // (type stylemap)
    vx_web_html.t_stylemap['vx_type'] = vx_core.t_type
    vx_web_html.t_stylemap['vx_value'] = {
      name          : "stylemap",
      pkgname       : "vx/web/html",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_web_html.t_style],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_web_html.e_stylemap['vx_type'] = vx_web_html.t_stylemap
    vx_web_html.e_stylemap['vx_value'] = {}

    // (type stylesheet)
    vx_web_html.t_stylesheet['vx_type'] = vx_core.t_type
    vx_web_html.t_stylesheet['vx_value'] = {
      name          : "stylesheet",
      pkgname       : "vx/web/html",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [vx_web_html.t_node, vx_web_html.t_headchild],
      properties    : {
        "id": {
          "name" : "id",
          "type" : vx_core.t_string,
          "multi": false
        },
        "style": {
          "name" : "style",
          "type" : vx_web_html.t_style,
          "multi": false
        },
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "styles": {
          "name" : "styles",
          "type" : vx_web_html.t_stylelist,
          "multi": false
        },
        "stylemap": {
          "name" : "stylemap",
          "type" : vx_web_html.t_stylemap,
          "multi": false
        }
      },
      proplast      : {
        "name" : "stylemap",
        "type" : vx_web_html.t_stylemap,
        "multi": false
      }
    }
    vx_web_html.e_stylesheet['vx_type'] = vx_web_html.t_stylesheet
    vx_web_html.e_stylesheet['vx_value'] = {}

    // (type table)
    vx_web_html.t_table['vx_type'] = vx_core.t_type
    vx_web_html.t_table['vx_value'] = {
      name          : "table",
      pkgname       : "vx/web/html",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [vx_web_html.t_node, vx_web_html.t_divchild],
      properties    : {
        "id": {
          "name" : "id",
          "type" : vx_core.t_string,
          "multi": false
        },
        "style": {
          "name" : "style",
          "type" : vx_web_html.t_style,
          "multi": false
        },
        "tbody": {
          "name" : "tbody",
          "type" : vx_web_html.t_tbody,
          "multi": false
        },
        "thead": {
          "name" : "thead",
          "type" : vx_web_html.t_thead,
          "multi": false
        }
      },
      proplast      : {
        "name" : "thead",
        "type" : vx_web_html.t_thead,
        "multi": false
      }
    }
    vx_web_html.e_table['vx_type'] = vx_web_html.t_table
    vx_web_html.e_table['vx_value'] = {}

    // (type tbody)
    vx_web_html.t_tbody['vx_type'] = vx_core.t_type
    vx_web_html.t_tbody['vx_value'] = {
      name          : "tbody",
      pkgname       : "vx/web/html",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [vx_web_html.t_node],
      properties    : {
        "id": {
          "name" : "id",
          "type" : vx_core.t_string,
          "multi": false
        },
        "style": {
          "name" : "style",
          "type" : vx_web_html.t_style,
          "multi": false
        },
        "nodes": {
          "name" : "nodes",
          "type" : vx_web_html.t_trlist,
          "multi": true
        }
      },
      proplast      : {
        "name" : "nodes",
        "type" : vx_web_html.t_trlist,
        "multi": true
      }
    }
    vx_web_html.e_tbody['vx_type'] = vx_web_html.t_tbody
    vx_web_html.e_tbody['vx_value'] = {}

    // (type td)
    vx_web_html.t_td['vx_type'] = vx_core.t_type
    vx_web_html.t_td['vx_value'] = {
      name          : "td",
      pkgname       : "vx/web/html",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [vx_web_html.t_node],
      properties    : {
        "id": {
          "name" : "id",
          "type" : vx_core.t_string,
          "multi": false
        },
        "style": {
          "name" : "style",
          "type" : vx_web_html.t_style,
          "multi": false
        },
        "nodes": {
          "name" : "nodes",
          "type" : vx_web_html.t_divchildlist,
          "multi": true
        }
      },
      proplast      : {
        "name" : "nodes",
        "type" : vx_web_html.t_divchildlist,
        "multi": true
      }
    }
    vx_web_html.e_td['vx_type'] = vx_web_html.t_td
    vx_web_html.e_td['vx_value'] = {}

    // (type tdlist)
    vx_web_html.t_tdlist['vx_type'] = vx_core.t_type
    vx_web_html.t_tdlist['vx_value'] = {
      name          : "tdlist",
      pkgname       : "vx/web/html",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_web_html.t_td],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_web_html.e_tdlist['vx_type'] = vx_web_html.t_tdlist

    // (type thead)
    vx_web_html.t_thead['vx_type'] = vx_core.t_type
    vx_web_html.t_thead['vx_value'] = {
      name          : "thead",
      pkgname       : "vx/web/html",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [vx_web_html.t_node],
      properties    : {
        "id": {
          "name" : "id",
          "type" : vx_core.t_string,
          "multi": false
        },
        "style": {
          "name" : "style",
          "type" : vx_web_html.t_style,
          "multi": false
        },
        "nodes": {
          "name" : "nodes",
          "type" : vx_web_html.t_trlist,
          "multi": true
        }
      },
      proplast      : {
        "name" : "nodes",
        "type" : vx_web_html.t_trlist,
        "multi": true
      }
    }
    vx_web_html.e_thead['vx_type'] = vx_web_html.t_thead
    vx_web_html.e_thead['vx_value'] = {}

    // (type title)
    vx_web_html.t_title['vx_type'] = vx_core.t_type
    vx_web_html.t_title['vx_value'] = {
      name          : "title",
      pkgname       : "vx/web/html",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [vx_web_html.t_node, vx_web_html.t_headchild],
      properties    : {
        "id": {
          "name" : "id",
          "type" : vx_core.t_string,
          "multi": false
        },
        "style": {
          "name" : "style",
          "type" : vx_web_html.t_style,
          "multi": false
        },
        "text": {
          "name" : "text",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "text",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    vx_web_html.e_title['vx_type'] = vx_web_html.t_title
    vx_web_html.e_title['vx_value'] = {}

    // (type tr)
    vx_web_html.t_tr['vx_type'] = vx_core.t_type
    vx_web_html.t_tr['vx_value'] = {
      name          : "tr",
      pkgname       : "vx/web/html",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [vx_web_html.t_node],
      properties    : {
        "id": {
          "name" : "id",
          "type" : vx_core.t_string,
          "multi": false
        },
        "style": {
          "name" : "style",
          "type" : vx_web_html.t_style,
          "multi": false
        },
        "nodes": {
          "name" : "nodes",
          "type" : vx_web_html.t_tdlist,
          "multi": true
        }
      },
      proplast      : {
        "name" : "nodes",
        "type" : vx_web_html.t_tdlist,
        "multi": true
      }
    }
    vx_web_html.e_tr['vx_type'] = vx_web_html.t_tr
    vx_web_html.e_tr['vx_value'] = {}

    // (type trlist)
    vx_web_html.t_trlist['vx_type'] = vx_core.t_type
    vx_web_html.t_trlist['vx_value'] = {
      name          : "trlist",
      pkgname       : "vx/web/html",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_web_html.t_tr],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_web_html.e_trlist['vx_type'] = vx_web_html.t_trlist

    // (func htmlstring<-string)
    vx_web_html.t_htmlstring_from_string['vx_type'] = vx_core.t_type
    vx_web_html.t_htmlstring_from_string['vx_value'] = {
      name          : "htmlstring<-string",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_htmlstring_from_string
    }

    // (func string-indent)
    vx_web_html.t_string_indent['vx_type'] = vx_core.t_type
    vx_web_html.t_string_indent['vx_value'] = {
      name          : "string-indent",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_indent
    }

    // (func string<-body-indent)
    vx_web_html.t_string_from_body_indent['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_body_indent['vx_value'] = {
      name          : "string<-body-indent",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_body_indent
    }

    // (func string<-details-indent)
    vx_web_html.t_string_from_details_indent['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_details_indent['vx_value'] = {
      name          : "string<-details-indent",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_details_indent
    }

    // (func string<-div-indent)
    vx_web_html.t_string_from_div_indent['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_div_indent['vx_value'] = {
      name          : "string<-div-indent",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_div_indent
    }

    // (func string<-footer-indent)
    vx_web_html.t_string_from_footer_indent['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_footer_indent['vx_value'] = {
      name          : "string<-footer-indent",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_footer_indent
    }

    // (func string<-h1-indent)
    vx_web_html.t_string_from_h1_indent['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_h1_indent['vx_value'] = {
      name          : "string<-h1-indent",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_h1_indent
    }

    // (func string<-h2-indent)
    vx_web_html.t_string_from_h2_indent['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_h2_indent['vx_value'] = {
      name          : "string<-h2-indent",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_h2_indent
    }

    // (func string<-h3-indent)
    vx_web_html.t_string_from_h3_indent['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_h3_indent['vx_value'] = {
      name          : "string<-h3-indent",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_h3_indent
    }

    // (func string<-head-indent)
    vx_web_html.t_string_from_head_indent['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_head_indent['vx_value'] = {
      name          : "string<-head-indent",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_head_indent
    }

    // (func string<-html)
    vx_web_html.t_string_from_html['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_html['vx_value'] = {
      name          : "string<-html",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_html
    }

    // (func string<-indent)
    vx_web_html.t_string_from_indent['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_indent['vx_value'] = {
      name          : "string<-indent",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_indent
    }

    // (func string<-meta-indent)
    vx_web_html.t_string_from_meta_indent['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_meta_indent['vx_value'] = {
      name          : "string<-meta-indent",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_meta_indent
    }

    // (func string<-node-indent)
    vx_web_html.t_string_from_node_indent['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_node_indent['vx_value'] = {
      name          : "string<-node-indent",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_node_indent
    }

    // (func string<-nodelist-indent)
    vx_web_html.t_string_from_nodelist_indent['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_nodelist_indent['vx_value'] = {
      name          : "string<-nodelist-indent",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_nodelist_indent
    }

    // (func string<-nodelist-tag-prop-indent)
    vx_web_html.t_string_from_nodelist_tag_prop_indent['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_nodelist_tag_prop_indent['vx_value'] = {
      name          : "string<-nodelist-tag-prop-indent",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_nodelist_tag_prop_indent
    }

    // (func string<-p-indent)
    vx_web_html.t_string_from_p_indent['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_p_indent['vx_value'] = {
      name          : "string<-p-indent",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_p_indent
    }

    // (func string<-propname-val)
    vx_web_html.t_string_from_propname_val['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_propname_val['vx_value'] = {
      name          : "string<-propname-val",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_propname_val
    }

    // (func string<-propstyle)
    vx_web_html.t_string_from_propstyle['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_propstyle['vx_value'] = {
      name          : "string<-propstyle",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_propstyle
    }

    // (func string<-style-indent)
    vx_web_html.t_string_from_style_indent['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_style_indent['vx_value'] = {
      name          : "string<-style-indent",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_style_indent
    }

    // (func string<-stylelist-indent)
    vx_web_html.t_string_from_stylelist_indent['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_stylelist_indent['vx_value'] = {
      name          : "string<-stylelist-indent",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_stylelist_indent
    }

    // (func string<-stylepropmap-indent)
    vx_web_html.t_string_from_stylepropmap_indent['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_stylepropmap_indent['vx_value'] = {
      name          : "string<-stylepropmap-indent",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_stylepropmap_indent
    }

    // (func string<-stylesheet-indent)
    vx_web_html.t_string_from_stylesheet_indent['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_stylesheet_indent['vx_value'] = {
      name          : "string<-stylesheet-indent",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_stylesheet_indent
    }

    // (func string<-table-indent)
    vx_web_html.t_string_from_table_indent['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_table_indent['vx_value'] = {
      name          : "string<-table-indent",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_table_indent
    }

    // (func string<-tbody-indent)
    vx_web_html.t_string_from_tbody_indent['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_tbody_indent['vx_value'] = {
      name          : "string<-tbody-indent",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_tbody_indent
    }

    // (func string<-td-indent)
    vx_web_html.t_string_from_td_indent['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_td_indent['vx_value'] = {
      name          : "string<-td-indent",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_td_indent
    }

    // (func string<-thead-indent)
    vx_web_html.t_string_from_thead_indent['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_thead_indent['vx_value'] = {
      name          : "string<-thead-indent",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_thead_indent
    }

    // (func string<-title-indent)
    vx_web_html.t_string_from_title_indent['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_title_indent['vx_value'] = {
      name          : "string<-title-indent",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_title_indent
    }

    // (func string<-tr-indent)
    vx_web_html.t_string_from_tr_indent['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_tr_indent['vx_value'] = {
      name          : "string<-tr-indent",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_tr_indent
    }

    // (func string<-uri)
    vx_web_html.t_string_from_uri['vx_type'] = vx_core.t_type
    vx_web_html.t_string_from_uri['vx_value'] = {
      name          : "string<-uri",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_string_from_uri
    }

    // (func style<-stylesheet-name)
    vx_web_html.t_style_from_stylesheet_name['vx_type'] = vx_core.t_type
    vx_web_html.t_style_from_stylesheet_name['vx_value'] = {
      name          : "style<-stylesheet-name",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_style_from_stylesheet_name
    }

    // (func stylemap<-stylelist)
    vx_web_html.t_stylemap_from_stylelist['vx_type'] = vx_core.t_type
    vx_web_html.t_stylemap_from_stylelist['vx_value'] = {
      name          : "stylemap<-stylelist",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_stylemap_from_stylelist
    }

    // (func stylemap<-stylesheet)
    vx_web_html.t_stylemap_from_stylesheet['vx_type'] = vx_core.t_type
    vx_web_html.t_stylemap_from_stylesheet['vx_value'] = {
      name          : "stylemap<-stylesheet",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_stylemap_from_stylesheet
    }

    // (func styles<-stylesheet)
    vx_web_html.t_styles_from_stylesheet['vx_type'] = vx_core.t_type
    vx_web_html.t_styles_from_stylesheet['vx_value'] = {
      name          : "styles<-stylesheet",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_styles_from_stylesheet
    }

    // (func stylesheet-loadmap)
    vx_web_html.t_stylesheet_loadmap['vx_type'] = vx_core.t_type
    vx_web_html.t_stylesheet_loadmap['vx_value'] = {
      name          : "stylesheet-loadmap",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_stylesheet_loadmap
    }

    // (func uri<-string)
    vx_web_html.t_uri_from_string['vx_type'] = vx_core.t_type
    vx_web_html.t_uri_from_string['vx_value'] = {
      name          : "uri<-string",
      pkgname       : "vx/web/html",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_web_html.f_uri_from_string
    }

  }
}
