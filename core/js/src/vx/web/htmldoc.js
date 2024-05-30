'strict mode'

import vx_core from "../../vx/core.js"
import vx_event from "../../vx/event.js"
import vx_web_html from "../../vx/web/html.js"
import vx_ui_ui from "../../vx/ui/ui.js"


export default class vx_web_htmldoc {

  static vx_global = {context    : vx_core.e_context,
                      listenermap: {}}

  static vx_boolean_print_from_id_stylesheettext(id, stylesheettext) {
    const text = document.getElementById(id).innerHTML
    const win = window.open('', 'Print', 'popup=true')
    const doctext = '' +
     '<html>\n' +
     '<head>\n' +
     stylesheettext + '\n' +
     '</head>\n' +
     '<body>\n' +
     text + '\n'
     '</body>\n' +
     '</html>'
    win.document.write(doctext)
    win.document.write('</body></html>')
    win.document.close()
    win.print()
  }

  static vx_boolean_replace_from_id_htmltext(id, htmltext) {
    let output = vx_core.c_false
    const elem = document.getElementById(id)
    if (elem != null) {
      elem.outerHTML = htmltext
      output = vx_core.c_true
    }
    return output
  }

  static vx_boolean_replace_from_ui_htmltext(ui, htmltext) {
    let output = vx_core.c_false
    const id = vx_core.f_any_from_struct({'any-1': vx_core.t_string}, ui, ':uid')
    let elem = document.getElementById(id)
    if (elem != null) {
      elem.outerHTML = htmltext
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

  static vx_boolean_write_from_id_maplistener(id, maplistener) {
    vx_web_htmldoc.vx_global['listenermap'][id] = maplistener
    return vx_core.c_true
  }

  static vx_boolean_write_from_id_visible(id, visible) {
    let output = vx_core.c_false
    const elem = document.getElementById(id)
    if (elem != null) {
      elem.hidden = !visible
      output = vx_core.c_true
    }
    return output
  }

  static vx_boolean_writeevents_from_ui(ui) {
    let output = vx_core.c_false
    const eventmap = vx_core.f_any_from_struct({'any-1': vx_event.t_eventmap}, ui, ':eventmap')
    if (eventmap == vx_event.e_eventmap) {
      output = vx_core.c_true
    } else {
      const id = vx_core.f_any_from_struct({'any-1': vx_core.t_string}, ui, ':uid')
      let elem = document.getElementById(id)
      if (elem != null) {
        const maplistenerold = vx_web_htmldoc.vx_maplistener_read_from_id(id)
        if (maplistenerold) {
          vx_web_htmldoc.vx_boolean_write_from_id_maplistener(id, {})
          for (const [nativeeventname, listener] of Object.entries(maplistenerold)) {
            elem.removeEventListener(nativeeventname, listener)
          }
        }
        if (eventmap != vx_event.e_eventmap) {
          elem = document.getElementById(id)
          const maplistener = {}
          for (const [eventname, event] of Object.entries(eventmap['vx_value'])) {
            const listener = (nativeevent) => {
              const context = vx_web_htmldoc.vx_context_read()
              const eventchg = vx_web_htmldoc.vx_event_from_event_id_nativeevent(event, id, nativeevent)
              const fn_event = event['vx_value']['event<-event']
              const fn_event_async = event['vx_value']['event<-event']
              let eventoutput = null
              if (fn_event != vx_event.e_event_from_event) {
                eventoutput = vx_core.vx_any_from_func(vx_event.t_event, fn_event, context, eventchg)
              } else if (fn_event_async != vx_event.e_event_from_event) {
                eventoutput = vx_core.vx_any_from_func_async(vx_event.t_event, fn_event_async, context, eventchg)
              }
              return eventoutput
            }
            const nativeeventname = vx_web_htmldoc.vx_nativeeventname_from_eventname(eventname)
            elem.addEventListener(nativeeventname, listener)
            maplistener[nativeeventname] = maplistener
          }
          vx_web_htmldoc.vx_boolean_write_from_id_maplistener(id, maplistener)
        }
        output = vx_core.c_true
      }
    }
    return output
  }

  static vx_boolean_writestate_from_ui(ui) {
    const context = vx_web_htmldoc.vx_context_read()
    return vx_ui_ui.f_boolean_writestate_from_ui(context, ui)
  }

  static async vx_boolean_write_stylesheet_from_string(text) {
    let output = vx_core.c_false
    const cssstylesheet = new CSSStyleSheet()
    document.adoptedStyleSheets = [cssstylesheet]
    const css = await cssstylesheet.replace(text)
    output = vx_core.c_true
    return output
  }

  static vx_context_read() {
    let output = vx_core.e_context
    const context = vx_web_htmldoc.vx_global['context']
    if (context) {
      output = context
    }
    return output
  }

  static vx_context_write(context) {
    let output = context
    vx_web_htmldoc.vx_global['context'] = context
    return output
  }

  static vx_event_from_event_id_nativeevent(event, id, nativeevent) {
    let output
    output = vx_core.f_copy(event, ":from", id)
    return output
  }

  static vx_maplistener_read_from_id(id) {
    return vx_web_htmldoc.vx_global.listenermap[id]
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

  static vx_ui_readstate_from_uid(uid) {
    let output = vx_ui_ui.e_ui
    const context = vx_web_htmldoc.vx_context_read()
    output = vx_ui_ui.f_ui_readstate_from_id(context, uid)
    return output
  }
  /**
   * @function boolean_print_from_id_stylesheettext
   * Print the contents of the given id.
   * @param  {string} id
   * @param  {string} stylesheettext
   * @return {boolean}
   */
  static t_boolean_print_from_id_stylesheettext = {
    vx_type: vx_core.t_type
  }
  static e_boolean_print_from_id_stylesheettext = {
    vx_type: vx_web_htmldoc.t_boolean_print_from_id_stylesheettext
  }

  // (func boolean-print<-id-stylesheettext)
  static f_boolean_print_from_id_stylesheettext(id, stylesheettext) {
    let output = vx_core.e_boolean
    output = vx_web_htmldoc.vx_boolean_print_from_id_stylesheettext(id, stylesheettext)
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
   * @function boolean_replace_from_ui_htmltext
   * Replaces an html node with given id and text.
   * @param  {ui} ui
   * @param  {string} htmltext
   * @return {boolean}
   */
  static t_boolean_replace_from_ui_htmltext = {
    vx_type: vx_core.t_type
  }
  static e_boolean_replace_from_ui_htmltext = {
    vx_type: vx_web_htmldoc.t_boolean_replace_from_ui_htmltext
  }

  // (func boolean-replace<-ui-htmltext)
  static f_boolean_replace_from_ui_htmltext(ui, htmltext) {
    let output = vx_core.e_boolean
    output = vx_web_htmldoc.vx_boolean_replace_from_ui_htmltext(ui, htmltext)
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
   * @function boolean_write_from_id_visible
   * Writes to an html node changing its visibility.
   * @param  {string} id
   * @param  {boolean} visible
   * @return {boolean}
   */
  static t_boolean_write_from_id_visible = {
    vx_type: vx_core.t_type
  }
  static e_boolean_write_from_id_visible = {
    vx_type: vx_web_htmldoc.t_boolean_write_from_id_visible
  }

  // (func boolean-write<-id-visible)
  static f_boolean_write_from_id_visible(id, visible) {
    let output = vx_core.e_boolean
    output = vx_web_htmldoc.vx_boolean_write_from_id_visible(id, visible)
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
        const text = vx_web_htmldoc.f_string_from_stylesheet(stylesheet)
        const iswrite = await vx_web_htmldoc.f_boolean_write_stylesheet_from_string(text)
        return iswrite
      })
    )
    return output
  }

  /**
   * @function boolean_writeevents_from_ui
   * Writes the eventmap from ui into dom.
   * @param  {ui} ui
   * @return {boolean}
   */
  static t_boolean_writeevents_from_ui = {
    vx_type: vx_core.t_type
  }
  static e_boolean_writeevents_from_ui = {
    vx_type: vx_web_htmldoc.t_boolean_writeevents_from_ui
  }

  // (func boolean-writeevents<-ui)
  static f_boolean_writeevents_from_ui(ui) {
    let output = vx_core.e_boolean
    output = vx_web_htmldoc.vx_boolean_writeevents_from_ui(ui)
    return output
  }

  /**
   * @function context_read
   * Reads context from document.data.context
   * @return {context}
   */
  static t_context_read = {
    vx_type: vx_core.t_type
  }
  static e_context_read = {
    vx_type: vx_web_htmldoc.t_context_read
  }

  // (func context-read)
  static f_context_read() {
    let output = vx_core.e_context
    output = vx_web_htmldoc.vx_context_read()
    return output
  }

  /**
   * @function context_write
   * Writes context to document.data.context
   * @return {context}
   */
  static t_context_write = {
    vx_type: vx_core.t_type
  }
  static e_context_write = {
    vx_type: vx_web_htmldoc.t_context_write
  }

  // (func context-write)
  static f_context_write(context) {
    let output = vx_core.e_context
    output = vx_web_htmldoc.vx_context_write(context)
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

  /**
   * @function string_from_stylesheet
   * Returns string from a given stylesheet
   * @param  {stylesheet} stylesheet
   * @return {string}
   */
  static t_string_from_stylesheet = {
    vx_type: vx_core.t_type
  }
  static e_string_from_stylesheet = {
    vx_type: vx_web_htmldoc.t_string_from_stylesheet
  }

  // (func string<-stylesheet)
  static f_string_from_stylesheet(stylesheet) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const stylelist = vx_web_html.f_styles_from_stylesheet(stylesheet)
        const text = vx_web_html.f_string_from_stylelist_indent(stylelist, 0)
        return text
      })
    )
    return output
  }

  /**
   * @function ui_readstate_from_uid
   * Returns ui component from element.
   * @param  {string} uid
   * @return {any}
   */
  static t_ui_readstate_from_uid = {
    vx_type: vx_core.t_type
  }
  static e_ui_readstate_from_uid = {
    vx_type: vx_web_htmldoc.t_ui_readstate_from_uid
  }

  // (func ui-readstate<-uid)
  static f_ui_readstate_from_uid(uid) {
    let output = vx_core.e_any
    output = vx_web_htmldoc.vx_ui_readstate_from_uid(uid)
    return output
  }



  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "boolean-print<-id-stylesheettext": vx_web_htmldoc.e_boolean_print_from_id_stylesheettext,
      "boolean-replace<-id-htmltext": vx_web_htmldoc.e_boolean_replace_from_id_htmltext,
      "boolean-replace<-ui-htmltext": vx_web_htmldoc.e_boolean_replace_from_ui_htmltext,
      "boolean-write-stylesheet<-string": vx_web_htmldoc.e_boolean_write_stylesheet_from_string,
      "boolean-write<-id-htmltext": vx_web_htmldoc.e_boolean_write_from_id_htmltext,
      "boolean-write<-id-visible": vx_web_htmldoc.e_boolean_write_from_id_visible,
      "boolean-write<-stylesheet": vx_web_htmldoc.e_boolean_write_from_stylesheet,
      "boolean-writeevents<-ui": vx_web_htmldoc.e_boolean_writeevents_from_ui,
      "context-read": vx_web_htmldoc.e_context_read,
      "context-write": vx_web_htmldoc.e_context_write,
      "string<-id": vx_web_htmldoc.e_string_from_id,
      "string<-stylesheet": vx_web_htmldoc.e_string_from_stylesheet,
      "ui-readstate<-uid": vx_web_htmldoc.e_ui_readstate_from_uid
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "boolean-print<-id-stylesheettext": vx_web_htmldoc.t_boolean_print_from_id_stylesheettext,
      "boolean-replace<-id-htmltext": vx_web_htmldoc.t_boolean_replace_from_id_htmltext,
      "boolean-replace<-ui-htmltext": vx_web_htmldoc.t_boolean_replace_from_ui_htmltext,
      "boolean-write-stylesheet<-string": vx_web_htmldoc.t_boolean_write_stylesheet_from_string,
      "boolean-write<-id-htmltext": vx_web_htmldoc.t_boolean_write_from_id_htmltext,
      "boolean-write<-id-visible": vx_web_htmldoc.t_boolean_write_from_id_visible,
      "boolean-write<-stylesheet": vx_web_htmldoc.t_boolean_write_from_stylesheet,
      "boolean-writeevents<-ui": vx_web_htmldoc.t_boolean_writeevents_from_ui,
      "context-read": vx_web_htmldoc.t_context_read,
      "context-write": vx_web_htmldoc.t_context_write,
      "string<-id": vx_web_htmldoc.t_string_from_id,
      "string<-stylesheet": vx_web_htmldoc.t_string_from_stylesheet,
      "ui-readstate<-uid": vx_web_htmldoc.t_ui_readstate_from_uid
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

    // (func boolean-print<-id-stylesheettext)
    vx_web_htmldoc.t_boolean_print_from_id_stylesheettext['vx_value'] = {
      name          : "boolean-print<-id-stylesheettext",
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
      fn            : vx_web_htmldoc.f_boolean_print_from_id_stylesheettext
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

    // (func boolean-replace<-ui-htmltext)
    vx_web_htmldoc.t_boolean_replace_from_ui_htmltext['vx_value'] = {
      name          : "boolean-replace<-ui-htmltext",
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
      fn            : vx_web_htmldoc.f_boolean_replace_from_ui_htmltext
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

    // (func boolean-write<-id-visible)
    vx_web_htmldoc.t_boolean_write_from_id_visible['vx_value'] = {
      name          : "boolean-write<-id-visible",
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
      fn            : vx_web_htmldoc.f_boolean_write_from_id_visible
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

    // (func boolean-writeevents<-ui)
    vx_web_htmldoc.t_boolean_writeevents_from_ui['vx_value'] = {
      name          : "boolean-writeevents<-ui",
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
      fn            : vx_web_htmldoc.f_boolean_writeevents_from_ui
    }

    // (func context-read)
    vx_web_htmldoc.t_context_read['vx_value'] = {
      name          : "context-read",
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
      fn            : vx_web_htmldoc.f_context_read
    }

    // (func context-write)
    vx_web_htmldoc.t_context_write['vx_value'] = {
      name          : "context-write",
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
      fn            : vx_web_htmldoc.f_context_write
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

    // (func string<-stylesheet)
    vx_web_htmldoc.t_string_from_stylesheet['vx_value'] = {
      name          : "string<-stylesheet",
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
      fn            : vx_web_htmldoc.f_string_from_stylesheet
    }

    // (func ui-readstate<-uid)
    vx_web_htmldoc.t_ui_readstate_from_uid['vx_value'] = {
      name          : "ui-readstate<-uid",
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
      fn            : vx_web_htmldoc.f_ui_readstate_from_uid
    }

  }
}
