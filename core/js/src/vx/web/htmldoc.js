'strict mode'

import vx_core from "../../vx/core.js"
import vx_web_html from "../../vx/web/html.js"


export default class vx_web_htmldoc {

  /**
   * @function boolean_write_from_id_htmltext
   * Writes to an html node with given id and text.
   * @param  {string} id
   * @param  {string} htmltext
   * @return {boolean}
   */
  static t_boolean_write_from_id_htmltext = {}
  static e_boolean_write_from_id_htmltext = {vx_type: vx_web_htmldoc.t_boolean_write_from_id_htmltext}

  // (func boolean-write<-id-htmltext)
  static f_boolean_write_from_id_htmltext(id, htmltext) {
    let output = vx_core.e_boolean
    const elem = document.getElementById(id)
    if (elem != null) {
      elem.innerHTML = htmltext
      output = vx_core.c_true
    }
    return output
  }

  /**
   * 
   * @async @function boolean_write_from_stylesheet
   * Writes to an html node with given id and text.
   * @param  {stylesheet} stylesheet
   * @return {boolean}
   */
  static t_boolean_write_from_stylesheet = {}
  static e_boolean_write_from_stylesheet = {vx_type: vx_web_htmldoc.t_boolean_write_from_stylesheet}

  // (func boolean-write<-stylesheet)
  static async f_boolean_write_from_stylesheet(stylesheet) {
    let output = Promise.resolve(vx_core.e_boolean)
    const stylelist = vx_web_html.f_styles_from_stylesheet(stylesheet)
    const text = vx_web_html.f_string_from_stylelist_indent(stylelist, 0)
    const cssstylesheet = new CSSStyleSheet()
    document.adoptedStyleSheets = [cssstylesheet]
    output = await cssstylesheet.replace(text)
    return output
  }

  /**
   * @function string_from_id
   * Reads the value of an html node by id.
   * @param  {string} id
   * @return {string}
   */
  static t_string_from_id = {}
  static e_string_from_id = {vx_type: vx_web_htmldoc.t_string_from_id}

  // (func string<-id)
  static f_string_from_id(id) {
    let output = vx_core.e_string
    const elem = document.getElementById(id)
    if (!elem) {
    } else if (elem.value) {
      output = elem.value
    } else if (elem.value) {
      output = elem.innerHTML
    }
    return output
  }

  // empty types


  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "boolean-write<-id-htmltext": vx_web_htmldoc.e_boolean_write_from_id_htmltext,
      "boolean-write<-stylesheet": vx_web_htmldoc.e_boolean_write_from_stylesheet,
      "string<-id": vx_web_htmldoc.e_string_from_id
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "boolean-write<-id-htmltext": vx_web_htmldoc.t_boolean_write_from_id_htmltext,
      "boolean-write<-stylesheet": vx_web_htmldoc.t_boolean_write_from_stylesheet,
      "string<-id": vx_web_htmldoc.t_string_from_id
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      
    })
    const pkg = vx_core.vx_new_struct(vx_core.t_package, {
      "name": "vx/web/htmldoc",
      "constmap": constmap,
      "emptymap": emptymap,
      "funcmap": funcmap,
      "typemap": typemap
    })
    vx_core.vx_global_package_set(pkg)

    // (func boolean-write<-id-htmltext)
    vx_web_htmldoc.t_boolean_write_from_id_htmltext['vx_type'] = vx_core.t_type
    vx_web_htmldoc.t_boolean_write_from_id_htmltext['vx_value'] = {
      name          : "boolean-write<-id-htmltext",
      pkgname       : "vx/web/htmldoc",
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
      fn            : vx_web_htmldoc.f_boolean_write_from_id_htmltext
    }

    // (func boolean-write<-stylesheet)
    vx_web_htmldoc.t_boolean_write_from_stylesheet['vx_type'] = vx_core.t_type
    vx_web_htmldoc.t_boolean_write_from_stylesheet['vx_value'] = {
      name          : "boolean-write<-stylesheet",
      pkgname       : "vx/web/htmldoc",
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
      fn            : vx_web_htmldoc.f_boolean_write_from_stylesheet
    }

    // (func string<-id)
    vx_web_htmldoc.t_string_from_id['vx_type'] = vx_core.t_type
    vx_web_htmldoc.t_string_from_id['vx_value'] = {
      name          : "string<-id",
      pkgname       : "vx/web/htmldoc",
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
      fn            : vx_web_htmldoc.f_string_from_id
    }

  }
}
