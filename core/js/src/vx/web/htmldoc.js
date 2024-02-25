'strict mode'

import vx_core from "../../vx/core.js"
import vx_event from "../../vx/event.js"
import vx_web_html from "../../vx/web/html.js"


export default class vx_web_htmldoc {

  static vx_any_data_from_id(id) {
    let output = vx_core.e_any
    const elem = document.getElementById(id)
    if (elem != null) {
      const elemdata = elem.getAttribute('data-data')
      if (elemdata) {
        output = elemdata
      }
    }
    return output
  }

  static vx_boolean_replace_from_id_htmltext_data_eventmap(id, htmltext, data, eventmap) {
    let output = vx_core.c_false
    const elem = document.getElementById(id)
    if (elem != null) {
      elem.outerHTML = htmltext
      output = vx_core.c_true
    }
    return output
  }

  static vx_boolean_replace_from_id_htmltext_data_eventmap(id, htmltext, data, eventmap) {
    let output = vx_core.c_false
    let elem = document.getElementById(id)
    if (elem != null) {
      const eventmapold = elem.getAttribute('data-eventmap')
      let issameevents = false
      if (eventmapold == eventmap) {
        issameevents = true
      }
      if (issameevents) {
      } else if (eventmapold) {
        for (const [key, event] of Object.entries(eventmap['vx_value'])) {
          elem.removeEventListener(event)
        }
      }
      elem.outerHTML = htmltext
      elem = document.getElementById(id)
      elem.setAttribute('data-data', data)
      if (issameevents) {
      } else if (eventmap == vx_event.e_eventmap) {
      } else {
        elem.setAttribute('data-eventmap', eventmap)
        for (const [eventname, event] of Object.entries(eventmap['vx_value'])) {
          const listener = (nativeevent) => {
            const fn_event = event['vx_value']['event<-event']
            const fn = fn_event['vx_value']['fn']
            const eventchg = vx_web_htmldoc.vx_event_from_event_nativeevent(event, nativeevent)
            const eventoutput = fn(eventchg)
            return eventoutput
          }
          const nativeeventname = vx_web_htmldoc.vx_nativeeventname_from_eventname(eventname)
          elem.addEventListener(nativeeventname, listener)
        }
      }
      output = vx_core.c_true
    }
    return output
  }

  static vx_boolean_write_from_id_htmltext(id, htmltext) {
   let output = vx_core.c_false
   const elem = document.getElementById(id)
    if (elem != null) {
      elem.innerHTML = htmltext
      output = vx_core.c_true
    }
    return output
  }

  static async vx_boolean_write_stylesheet_from_string(text) {
    let output = vx_core.c_false
    const cssstylesheet = new CSSStyleSheet()
    document.adoptedStyleSheets = [cssstylesheet]
    output = await cssstylesheet.replace(text)
    return output
  }

  static vx_event_from_event_nativeevent(event, nativeevent) {
    let output = event
    return output
  }

  static vx_nativeeventname_from_eventname(eventname) {
    let output = eventname
    return output
  }

  static vx_string_from_id(id) {
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
  /**
   * @function any_data_from_id
   * Returns data component from element.
   * @param  {string} id
   * @return {any}
   */
  static t_any_data_from_id = {
    vx_type: vx_core.t_type
  }
  static e_any_data_from_id = {
    vx_type: vx_web_htmldoc.t_any_data_from_id
  }

  // (func any-data<-id)
  static f_any_data_from_id(id) {
    let output = vx_core.e_any
    output = vx_web_htmldoc.vx_any_data_from_id(id)
    return output
  }

  /**
   * @function boolean_replace_from_id_htmltext
   * Replaces an html node with given id and text.
   * @param  {string} id
   * @param  {string} htmltext
   * @return {boolean}
   */
  static t_boolean_replace_from_id_htmltext = {
    vx_type: vx_core.t_type
  }
  static e_boolean_replace_from_id_htmltext = {
    vx_type: vx_web_htmldoc.t_boolean_replace_from_id_htmltext
  }

  // (func boolean-replace<-id-htmltext)
  static f_boolean_replace_from_id_htmltext(id, htmltext) {
    let output = vx_core.e_boolean
    output = vx_web_htmldoc.vx_boolean_replace_from_id_htmltext(id, htmltext)
    return output
  }

  /**
   * @function boolean_replace_from_id_htmltext_data_eventmap
   * Replaces an html node with given id and text.
   * @param  {string} id
   * @param  {string} htmltext
   * @param  {any} data
   * @param  {eventmap} eventmap
   * @return {boolean}
   */
  static t_boolean_replace_from_id_htmltext_data_eventmap = {
    vx_type: vx_core.t_type
  }
  static e_boolean_replace_from_id_htmltext_data_eventmap = {
    vx_type: vx_web_htmldoc.t_boolean_replace_from_id_htmltext_data_eventmap
  }

  // (func boolean-replace<-id-htmltext-data-eventmap)
  static f_boolean_replace_from_id_htmltext_data_eventmap(id, htmltext, data, eventmap) {
    let output = vx_core.e_boolean
    output = vx_web_htmldoc.vx_boolean_replace_from_id_htmltext_data_eventmap(id, htmltext, data, eventmap)
    return output
  }

  /**
   * 
   * @async @function boolean_write_stylesheet_from_string
   * Writes a css stylesheet.
   * @param  {string} text
   * @return {boolean}
   */
  static t_boolean_write_stylesheet_from_string = {
    vx_type: vx_core.t_type
  }
  static e_boolean_write_stylesheet_from_string = {
    vx_type: vx_web_htmldoc.t_boolean_write_stylesheet_from_string
  }

  // (func boolean-write-stylesheet<-string)
  static async f_boolean_write_stylesheet_from_string(text) {
    let output = Promise.resolve(vx_core.e_boolean)
    output = vx_web_htmldoc.vx_boolean_write_stylesheet_from_string(text)
    return output
  }

  /**
   * @function boolean_write_from_id_htmltext
   * Writes to an html node with given id and text.
   * @param  {string} id
   * @param  {string} htmltext
   * @return {boolean}
   */
  static t_boolean_write_from_id_htmltext = {
    vx_type: vx_core.t_type
  }
  static e_boolean_write_from_id_htmltext = {
    vx_type: vx_web_htmldoc.t_boolean_write_from_id_htmltext
  }

  // (func boolean-write<-id-htmltext)
  static f_boolean_write_from_id_htmltext(id, htmltext) {
    let output = vx_core.e_boolean
    output = vx_web_htmldoc.vx_boolean_write_from_id_htmltext(id, htmltext)
    return output
  }

  /**
   * 
   * @async @function boolean_write_from_stylesheet
   * Writes a css stylesheet.
   * @param  {stylesheet} stylesheet
   * @return {boolean}
   */
  static t_boolean_write_from_stylesheet = {
    vx_type: vx_core.t_type
  }
  static e_boolean_write_from_stylesheet = {
    vx_type: vx_web_htmldoc.t_boolean_write_from_stylesheet
  }

  // (func boolean-write<-stylesheet)
  static async f_boolean_write_from_stylesheet(stylesheet) {
    let output = Promise.resolve(vx_core.e_boolean)
    output = await vx_core.f_let_async(
      {"any-1": vx_core.t_boolean},
      [],
      vx_core.f_new(vx_core.t_any_from_func, async () => {
        const stylelist = vx_web_html.f_styles_from_stylesheet(stylesheet)
        const text = vx_web_html.f_string_from_stylelist_indent(stylelist, 0)
        const iswrite = await vx_web_htmldoc.f_boolean_write_stylesheet_from_string(text)
        return iswrite
      })
    )
    return output
  }

  /**
   * @function string_from_id
   * Reads the value of an html node by id.
   * @param  {string} id
   * @return {string}
   */
  static t_string_from_id = {
    vx_type: vx_core.t_type
  }
  static e_string_from_id = {
    vx_type: vx_web_htmldoc.t_string_from_id
  }

  // (func string<-id)
  static f_string_from_id(id) {
    let output = vx_core.e_string
    output = vx_web_htmldoc.vx_string_from_id(id)
    return output
  }



  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "any-data<-id": vx_web_htmldoc.e_any_data_from_id,
      "boolean-replace<-id-htmltext": vx_web_htmldoc.e_boolean_replace_from_id_htmltext,
      "boolean-replace<-id-htmltext-data-eventmap": vx_web_htmldoc.e_boolean_replace_from_id_htmltext_data_eventmap,
      "boolean-write-stylesheet<-string": vx_web_htmldoc.e_boolean_write_stylesheet_from_string,
      "boolean-write<-id-htmltext": vx_web_htmldoc.e_boolean_write_from_id_htmltext,
      "boolean-write<-stylesheet": vx_web_htmldoc.e_boolean_write_from_stylesheet,
      "string<-id": vx_web_htmldoc.e_string_from_id
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "any-data<-id": vx_web_htmldoc.t_any_data_from_id,
      "boolean-replace<-id-htmltext": vx_web_htmldoc.t_boolean_replace_from_id_htmltext,
      "boolean-replace<-id-htmltext-data-eventmap": vx_web_htmldoc.t_boolean_replace_from_id_htmltext_data_eventmap,
      "boolean-write-stylesheet<-string": vx_web_htmldoc.t_boolean_write_stylesheet_from_string,
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

    // (func any-data<-id)
    vx_web_htmldoc.t_any_data_from_id['vx_value'] = {
      name          : "any-data<-id",
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
      fn            : vx_web_htmldoc.f_any_data_from_id
    }

    // (func boolean-replace<-id-htmltext)
    vx_web_htmldoc.t_boolean_replace_from_id_htmltext['vx_value'] = {
      name          : "boolean-replace<-id-htmltext",
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
      fn            : vx_web_htmldoc.f_boolean_replace_from_id_htmltext
    }

    // (func boolean-replace<-id-htmltext-data-eventmap)
    vx_web_htmldoc.t_boolean_replace_from_id_htmltext_data_eventmap['vx_value'] = {
      name          : "boolean-replace<-id-htmltext-data-eventmap",
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
      fn            : vx_web_htmldoc.f_boolean_replace_from_id_htmltext_data_eventmap
    }

    // (func boolean-write-stylesheet<-string)
    vx_web_htmldoc.t_boolean_write_stylesheet_from_string['vx_value'] = {
      name          : "boolean-write-stylesheet<-string",
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
      fn            : vx_web_htmldoc.f_boolean_write_stylesheet_from_string
    }

    // (func boolean-write<-id-htmltext)
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
