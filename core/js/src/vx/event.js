'strict mode'

import vx_core from "../vx/core.js"


export default class vx_event {


  /**
   * type: event
   * Generic event
   */
  static t_event = {}
  /**
   * Constant: event-click
   * Click Event
   * {event}
   */
  static c_event_click = {vx_type: vx_event.t_event, vx_constdef: {pkgname: 'vx/event', name: 'event-click'}}

  /**
   * Constant: event-move
   * Move Event
   * {event}
   */
  static c_event_move = {vx_type: vx_event.t_event, vx_constdef: {pkgname: 'vx/event', name: 'event-move'}}

  /**
   * @function any_from_from_to
   * From to handling function.
   * @param  {typemap} generic
   * @param  {any} from
   * @param  {any} to
   * @return {any-1}
   */
  static t_any_from_from_to = {}
  static e_any_from_from_to = {vx_type: vx_event.t_any_from_from_to}

  // (func any<-from-to)
  static f_any_from_from_to(generic, from, to) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    return output
  }

  // empty types
  static e_event = {}


  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      "event-click": vx_event.c_event_click,
      "event-move": vx_event.c_event_move
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "event": vx_event.e_event,
      "any<-from-to": vx_event.e_any_from_from_to
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "any<-from-to": vx_event.t_any_from_from_to
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      "event": vx_event.t_event
    })
    const pkg = vx_core.vx_new_struct(vx_core.t_package, {
      "name": "vx/event",
      "constmap": constmap,
      "emptymap": emptymap,
      "funcmap": funcmap,
      "typemap": typemap
    })
    vx_core.vx_global_package_set(pkg)

    // (type event)
    vx_event.t_event['vx_type'] = vx_core.t_type
    vx_event.t_event['vx_value'] = {
      name          : "event",
      pkgname       : "vx/event",
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
        "from": {
          "name" : "from",
          "type" : vx_core.t_any,
          "multi": false
        },
        "to": {
          "name" : "to",
          "type" : vx_core.t_any,
          "multi": false
        },
        "fn-any<-any": {
          "name" : "fn-any<-any",
          "type" : vx_core.t_any_from_any,
          "multi": false
        },
        "fn-any<-from-to": {
          "name" : "fn-any<-from-to",
          "type" : vx_event.t_any_from_from_to,
          "multi": false
        }
      },
      proplast      : {
        "name" : "fn-any<-from-to",
        "type" : vx_event.t_any_from_from_to,
        "multi": false
      }
    }
    vx_event.e_event['vx_type'] = vx_event.t_event
    vx_event.e_event['vx_value'] = {}

    // (const event-click)
    Object.assign(vx_event.c_event_click, vx_core.f_new(
      vx_event.t_event,
      ":name",
      ":click"
    ))

    // (const event-move)
    Object.assign(vx_event.c_event_move, vx_core.f_new(
      vx_event.t_event,
      ":name",
      ":move"
    ))

    // (func any<-from-to)
    vx_event.t_any_from_from_to['vx_type'] = vx_core.t_type
    vx_event.t_any_from_from_to['vx_value'] = {
      name          : "any<-from-to",
      pkgname       : "vx/event",
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
      fn            : vx_event.f_any_from_from_to
    }

  }
}
