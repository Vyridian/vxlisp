'strict mode'

import vx_core from "../vx/core.js"


export default class vx_event {


  /**
   * type: event
   * Generic Event
   */
  static t_event = {}
  static e_event = {vx_type: vx_event.t_event}

  /**
   * type: eventlist
   * Map of event
   */
  static t_eventlist = {}
  static e_eventlist = vx_core.vx_new_list(vx_event.t_eventlist, [])

  /**
   * type: eventmap
   * Map of event
   */
  static t_eventmap = {}
  static e_eventmap = {vx_type: vx_event.t_eventmap}
  /**
   * Constant: event-change
   * Change Event
   * {event}
   */
  static c_event_change = {vx_type: vx_event.t_event, vx_constdef: {pkgname: 'vx/event', name: 'event-change'}}

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
   * Constant: event-select
   * Move Event
   * {event}
   */
  static c_event_select = {vx_type: vx_event.t_event, vx_constdef: {pkgname: 'vx/event', name: 'event-select'}}

  /**
   * @function event_from_event
   * Template for triggering ui events
   * @param  {event} event
   * @return {event}
   */
  static t_event_from_event = {
    vx_type: vx_core.t_type
  }
  static e_event_from_event = {
    vx_type: vx_event.t_event_from_event
  }

  // (func event<-event)
  static f_event_from_event(event) {
    let output = vx_event.e_event
    output = event
    return output
  }

  /**
   * @function eventmap_from_eventlist
   * Returns an eventmap from an eventlist
   * @param  {eventlist} eventlist
   * @return {eventmap}
   */
  static t_eventmap_from_eventlist = {
    vx_type: vx_core.t_type
  }
  static e_eventmap_from_eventlist = {
    vx_type: vx_event.t_eventmap_from_eventlist
  }

  // (func eventmap<-eventlist)
  static f_eventmap_from_eventlist(eventlist) {
    let output = vx_event.e_eventmap
    output = vx_core.f_map_from_list(
      {"any-1": vx_event.t_event, "any-2": vx_event.t_event, "list-2": vx_event.t_eventlist, "map-1": vx_event.t_eventmap, "struct-2": vx_event.t_event},
      eventlist,
      vx_core.f_new(vx_core.t_any_from_any, (event) => 
        vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_event.t_event}, event, ":name"))
    )
    return output
  }



  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      "event-change": vx_event.c_event_change,
      "event-click": vx_event.c_event_click,
      "event-move": vx_event.c_event_move,
      "event-select": vx_event.c_event_select
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "event": vx_event.e_event,
      "eventlist": vx_event.e_eventlist,
      "eventmap": vx_event.e_eventmap,
      "event<-event": vx_event.e_event_from_event,
      "eventmap<-eventlist": vx_event.e_eventmap_from_eventlist
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "event<-event": vx_event.t_event_from_event,
      "eventmap<-eventlist": vx_event.t_eventmap_from_eventlist
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      "event": vx_event.t_event,
      "eventlist": vx_event.t_eventlist,
      "eventmap": vx_event.t_eventmap
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
        "datamap": {
          "name" : "datamap",
          "type" : vx_core.t_anymap,
          "multi": false
        },
        "event<-event": {
          "name" : "event<-event",
          "type" : vx_event.t_event_from_event,
          "multi": false
        }
      },
      proplast      : {
        "name" : "event<-event",
        "type" : vx_event.t_event_from_event,
        "multi": false
      }
    }
    vx_event.e_event['vx_type'] = vx_event.t_event
    vx_event.e_event['vx_value'] = {}

    // (type eventlist)
    vx_event.t_eventlist['vx_type'] = vx_core.t_type
    vx_event.t_eventlist['vx_value'] = {
      name          : "eventlist",
      pkgname       : "vx/event",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_event.t_event],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_event.e_eventlist['vx_type'] = vx_event.t_eventlist

    // (type eventmap)
    vx_event.t_eventmap['vx_type'] = vx_core.t_type
    vx_event.t_eventmap['vx_value'] = {
      name          : "eventmap",
      pkgname       : "vx/event",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_event.t_event],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_event.e_eventmap['vx_type'] = vx_event.t_eventmap
    vx_event.e_eventmap['vx_value'] = {}

    // (func event<-event)
    vx_event.t_event_from_event['vx_value'] = {
      name          : "event<-event",
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
      fn            : vx_event.f_event_from_event
    }

    // (func eventmap<-eventlist)
    vx_event.t_eventmap_from_eventlist['vx_value'] = {
      name          : "eventmap<-eventlist",
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
      fn            : vx_event.f_eventmap_from_eventlist
    }

    // (const event-change)
    Object.assign(vx_event.c_event_change, vx_core.f_new(
      vx_event.t_event,
      ":name",
      "change"
    ))

    // (const event-click)
    Object.assign(vx_event.c_event_click, vx_core.f_new(
      vx_event.t_event,
      ":name",
      "click"
    ))

    // (const event-move)
    Object.assign(vx_event.c_event_move, vx_core.f_new(
      vx_event.t_event,
      ":name",
      "move"
    ))

    // (const event-select)
    Object.assign(vx_event.c_event_select, vx_core.f_new(
      vx_event.t_event,
      ":name",
      "move"
    ))

  }
}
