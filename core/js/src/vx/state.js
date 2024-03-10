'strict mode'

import vx_core from "../vx/core.js"


export default class vx_state {


  /**
   * type: valuemap
   */
  static t_valuemap = {}
  static e_valuemap = {vx_type: vx_state.t_valuemap}
  /**
   * @function any_readstate_from_mapname_name
   * Returns the named state value
   * @param  {typemap} generic
   * @param  {string} mapname
   * @param  {string} name
   * @return {any-1}
   */
  static t_any_readstate_from_mapname_name = {
    vx_type: vx_core.t_type
  }
  static e_any_readstate_from_mapname_name = {
    vx_type: vx_state.t_any_readstate_from_mapname_name
  }

  // (func any-readstate<-mapname-name)
  static f_any_readstate_from_mapname_name(generic, context, mapname, name) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    output = vx_core.f_let(
      {"any-1": generic_any_1, "map-1": vx_state.t_valuemap},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const submap = vx_state.f_valuemap_readstate_from_mapname(context, mapname)
        return vx_core.f_any_from_map({"any-1": generic_any_1, "map-1": vx_state.t_valuemap}, submap, name)
      })
    )
    return output
  }

  /**
   * @function any_readstate_from_name
   * Returns the named state value
   * @param  {typemap} generic
   * @param  {string} name
   * @return {any-1}
   */
  static t_any_readstate_from_name = {
    vx_type: vx_core.t_type
  }
  static e_any_readstate_from_name = {
    vx_type: vx_state.t_any_readstate_from_name
  }

  // (func any-readstate<-name)
  static f_any_readstate_from_name(generic, context, name) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    output = vx_core.f_any_from_any(
      {"any-1": generic_any_1, "any-2": vx_core.t_any},
      vx_state.f_value_readstate_from_name(context, name)
    )
    return output
  }

  /**
   * @function boolean_writestate_from_mapname_name_value
   * Returns the named state value and changes it to the new value
   * @param  {string} mapname
   * @param  {string} name
   * @param  {any} value
   * @return {boolean}
   */
  static t_boolean_writestate_from_mapname_name_value = {
    vx_type: vx_core.t_type
  }
  static e_boolean_writestate_from_mapname_name_value = {
    vx_type: vx_state.t_boolean_writestate_from_mapname_name_value
  }

  // (func boolean-writestate<-mapname-name-value)
  static f_boolean_writestate_from_mapname_name_value(context, mapname, name, value) {
    let output = vx_core.e_boolean
    output = vx_core.f_let(
      {"any-1": vx_core.t_boolean},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const valmap = vx_state.f_any_readstate_from_name({"any-1": vx_state.t_valuemap}, context, mapname)
        return vx_core.f_if_2(
          {"any-1": vx_core.t_boolean},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty_1(valmap)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_let(
              {"any-1": vx_core.t_boolean},
              [],
              vx_core.f_new(vx_core.t_any_from_func, () => {
                const valmap2 = vx_core.f_new(
                  vx_state.t_valuemap,
                  name,
                  value
                )
                const listener = vx_core.f_new(
                  vx_core.t_statelistener,
                  ":name",
                  mapname,
                  ":value",
                  valmap2
                )
                return vx_state.f_boolean_writestate_from_statelistener(context, listener)
              })
            )})
          ),
          vx_core.f_else(
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_boolean_write_from_map_name_value(valmap, name, value)})
          )
        )
      })
    )
    return output
  }

  /**
   * @function boolean_writestate_from_name_value
   * Returns the named state value and changes it to the new value
   * @param  {string} name
   * @param  {any} value
   * @return {boolean}
   */
  static t_boolean_writestate_from_name_value = {
    vx_type: vx_core.t_type
  }
  static e_boolean_writestate_from_name_value = {
    vx_type: vx_state.t_boolean_writestate_from_name_value
  }

  // (func boolean-writestate<-name-value)
  static f_boolean_writestate_from_name_value(context, name, value) {
    let output = vx_core.e_boolean
    output = vx_core.f_let(
      {"any-1": vx_core.t_boolean},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const listenercur = vx_state.f_statelistener_readstate_from_name(context, name)
        const listenerchg = vx_core.f_copy(listenercur, ":name", name, ":value", value)
        return vx_state.f_boolean_writestate_from_statelistener(context, listenerchg)
      })
    )
    return output
  }

  /**
   * @function boolean_writestate_from_statelistener
   * Writes statelistener into state
   * @param  {statelistener} statelistener
   * @return {boolean}
   */
  static t_boolean_writestate_from_statelistener = {
    vx_type: vx_core.t_type
  }
  static e_boolean_writestate_from_statelistener = {
    vx_type: vx_state.t_boolean_writestate_from_statelistener
  }

  // (func boolean-writestate<-statelistener)
  static f_boolean_writestate_from_statelistener(context, statelistener) {
    let output = vx_core.e_boolean
    output = vx_core.f_let(
      {"any-1": vx_core.t_boolean, "map-1": vx_core.t_statelistenermap},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const statelistenermap = vx_state.f_statelistenermap_readstate(context)
        const name = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_core.t_statelistener}, statelistener, ":name")
        return vx_core.f_boolean_write_from_map_name_value(statelistenermap, name, statelistener)
      })
    )
    return output
  }

  /**
   * @function change
   * Changes the current state
   * @param  {valuemap} valuemap
   * @return {boolean}
   */
  static t_change = {
    vx_type: vx_core.t_type
  }
  static e_change = {
    vx_type: vx_state.t_change
  }

  // (func change)
  static f_change(valuemap) {
    let output = vx_core.e_boolean
    return output
  }

  /**
   * @function register
   * @param  {statelistener} listener
   * @return {boolean}
   */
  static t_register = {
    vx_type: vx_core.t_type
  }
  static e_register = {
    vx_type: vx_state.t_register
  }

  // (func register)
  static f_register(listener) {
    let output = vx_core.e_boolean
    return output
  }

  /**
   * @function state_from_context
   * Returns the full current state
   * @return {state}
   */
  static t_state_from_context = {
    vx_type: vx_core.t_type
  }
  static e_state_from_context = {
    vx_type: vx_state.t_state_from_context
  }

  // (func state<-context)
  static f_state_from_context(context) {
    let output = vx_core.e_state
    output = vx_core.f_any_from_struct({"any-1": vx_core.t_state, "struct-2": vx_core.t_context}, context, ":state")
    return output
  }

  /**
   * @function statelistener_readstate_from_name
   * Returns the named statelistener
   * @param  {string} name
   * @return {statelistener}
   */
  static t_statelistener_readstate_from_name = {
    vx_type: vx_core.t_type
  }
  static e_statelistener_readstate_from_name = {
    vx_type: vx_state.t_statelistener_readstate_from_name
  }

  // (func statelistener-readstate<-name)
  static f_statelistener_readstate_from_name(context, name) {
    let output = vx_core.e_statelistener
    output = vx_core.f_let(
      {"any-1": vx_core.t_statelistener, "map-1": vx_core.t_statelistenermap},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const statelistenermap = vx_state.f_statelistenermap_readstate(context)
        return vx_core.f_any_from_map({"any-1": vx_core.t_statelistener, "map-1": vx_core.t_statelistenermap}, statelistenermap, name)
      })
    )
    return output
  }

  /**
   * @function statelistenermap_readstate
   * Returns the current state valuemap
   * @return {statelistenermap}
   */
  static t_statelistenermap_readstate = {
    vx_type: vx_core.t_type
  }
  static e_statelistenermap_readstate = {
    vx_type: vx_state.t_statelistenermap_readstate
  }

  // (func statelistenermap-readstate)
  static f_statelistenermap_readstate(context) {
    let output = vx_core.e_statelistenermap
    output = vx_core.f_let(
      {"any-1": vx_core.t_statelistenermap, "struct-2": vx_core.t_state},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const state = vx_state.f_state_from_context(context)
        return vx_core.f_any_from_struct({"any-1": vx_core.t_statelistenermap, "struct-2": vx_core.t_state}, state, ":statelistenermap")
      })
    )
    return output
  }

  /**
   * @function value_readstate_from_name
   * Returns the named state value
   * @param  {string} name
   * @return {any}
   */
  static t_value_readstate_from_name = {
    vx_type: vx_core.t_type
  }
  static e_value_readstate_from_name = {
    vx_type: vx_state.t_value_readstate_from_name
  }

  // (func value-readstate<-name)
  static f_value_readstate_from_name(context, name) {
    let output = vx_core.e_any
    output = vx_core.f_let(
      {"any-1": vx_core.t_any, "struct-2": vx_core.t_statelistener},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const statelistener = vx_state.f_statelistener_readstate_from_name(context, name)
        return vx_core.f_any_from_struct({"any-1": vx_core.t_any, "struct-2": vx_core.t_statelistener}, statelistener, ":value")
      })
    )
    return output
  }

  /**
   * @function valuemap_readstate_from_mapname
   * Returns the current state valuemap
   * @param  {string} mapname
   * @return {valuemap}
   */
  static t_valuemap_readstate_from_mapname = {
    vx_type: vx_core.t_type
  }
  static e_valuemap_readstate_from_mapname = {
    vx_type: vx_state.t_valuemap_readstate_from_mapname
  }

  // (func valuemap-readstate<-mapname)
  static f_valuemap_readstate_from_mapname(context, mapname) {
    let output = vx_state.e_valuemap
    output = vx_core.f_let(
      {"any-1": vx_state.t_valuemap},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const value = vx_state.f_value_readstate_from_name(context, mapname)
        const valmap = vx_core.f_any_from_any({"any-1": vx_state.t_valuemap, "any-2": vx_core.t_any}, value)
        return valmap
      })
    )
    return output
  }



  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "valuemap": vx_state.e_valuemap,
      "any-readstate<-mapname-name": vx_state.e_any_readstate_from_mapname_name,
      "any-readstate<-name": vx_state.e_any_readstate_from_name,
      "boolean-writestate<-mapname-name-value": vx_state.e_boolean_writestate_from_mapname_name_value,
      "boolean-writestate<-name-value": vx_state.e_boolean_writestate_from_name_value,
      "boolean-writestate<-statelistener": vx_state.e_boolean_writestate_from_statelistener,
      "change": vx_state.e_change,
      "register": vx_state.e_register,
      "state<-context": vx_state.e_state_from_context,
      "statelistener-readstate<-name": vx_state.e_statelistener_readstate_from_name,
      "statelistenermap-readstate": vx_state.e_statelistenermap_readstate,
      "value-readstate<-name": vx_state.e_value_readstate_from_name,
      "valuemap-readstate<-mapname": vx_state.e_valuemap_readstate_from_mapname
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "any-readstate<-mapname-name": vx_state.t_any_readstate_from_mapname_name,
      "any-readstate<-name": vx_state.t_any_readstate_from_name,
      "boolean-writestate<-mapname-name-value": vx_state.t_boolean_writestate_from_mapname_name_value,
      "boolean-writestate<-name-value": vx_state.t_boolean_writestate_from_name_value,
      "boolean-writestate<-statelistener": vx_state.t_boolean_writestate_from_statelistener,
      "change": vx_state.t_change,
      "register": vx_state.t_register,
      "state<-context": vx_state.t_state_from_context,
      "statelistener-readstate<-name": vx_state.t_statelistener_readstate_from_name,
      "statelistenermap-readstate": vx_state.t_statelistenermap_readstate,
      "value-readstate<-name": vx_state.t_value_readstate_from_name,
      "valuemap-readstate<-mapname": vx_state.t_valuemap_readstate_from_mapname
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      "valuemap": vx_state.t_valuemap
    })
    const pkg = vx_core.vx_new_struct(vx_core.t_package, {
      "name": "vx/state",
      "constmap": constmap,
      "emptymap": emptymap,
      "funcmap": funcmap,
      "typemap": typemap
    })
    vx_core.vx_global_package_set(pkg)

    // (type valuemap)
    vx_state.t_valuemap['vx_type'] = vx_core.t_type
    vx_state.t_valuemap['vx_value'] = {
      name          : "valuemap",
      pkgname       : "vx/state",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_any],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_state.e_valuemap['vx_type'] = vx_state.t_valuemap
    vx_state.e_valuemap['vx_value'] = {}

    // (func any-readstate<-mapname-name)
    vx_state.t_any_readstate_from_mapname_name['vx_value'] = {
      name          : "any-readstate<-mapname-name",
      pkgname       : "vx/state",
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
      fn            : vx_state.f_any_readstate_from_mapname_name
    }

    // (func any-readstate<-name)
    vx_state.t_any_readstate_from_name['vx_value'] = {
      name          : "any-readstate<-name",
      pkgname       : "vx/state",
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
      fn            : vx_state.f_any_readstate_from_name
    }

    // (func boolean-writestate<-mapname-name-value)
    vx_state.t_boolean_writestate_from_mapname_name_value['vx_value'] = {
      name          : "boolean-writestate<-mapname-name-value",
      pkgname       : "vx/state",
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
      fn            : vx_state.f_boolean_writestate_from_mapname_name_value
    }

    // (func boolean-writestate<-name-value)
    vx_state.t_boolean_writestate_from_name_value['vx_value'] = {
      name          : "boolean-writestate<-name-value",
      pkgname       : "vx/state",
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
      fn            : vx_state.f_boolean_writestate_from_name_value
    }

    // (func boolean-writestate<-statelistener)
    vx_state.t_boolean_writestate_from_statelistener['vx_value'] = {
      name          : "boolean-writestate<-statelistener",
      pkgname       : "vx/state",
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
      fn            : vx_state.f_boolean_writestate_from_statelistener
    }

    // (func change)
    vx_state.t_change['vx_value'] = {
      name          : "change",
      pkgname       : "vx/state",
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
      fn            : vx_state.f_change
    }

    // (func register)
    vx_state.t_register['vx_value'] = {
      name          : "register",
      pkgname       : "vx/state",
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
      fn            : vx_state.f_register
    }

    // (func state<-context)
    vx_state.t_state_from_context['vx_value'] = {
      name          : "state<-context",
      pkgname       : "vx/state",
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
      fn            : vx_state.f_state_from_context
    }

    // (func statelistener-readstate<-name)
    vx_state.t_statelistener_readstate_from_name['vx_value'] = {
      name          : "statelistener-readstate<-name",
      pkgname       : "vx/state",
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
      fn            : vx_state.f_statelistener_readstate_from_name
    }

    // (func statelistenermap-readstate)
    vx_state.t_statelistenermap_readstate['vx_value'] = {
      name          : "statelistenermap-readstate",
      pkgname       : "vx/state",
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
      fn            : vx_state.f_statelistenermap_readstate
    }

    // (func value-readstate<-name)
    vx_state.t_value_readstate_from_name['vx_value'] = {
      name          : "value-readstate<-name",
      pkgname       : "vx/state",
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
      fn            : vx_state.f_value_readstate_from_name
    }

    // (func valuemap-readstate<-mapname)
    vx_state.t_valuemap_readstate_from_mapname['vx_value'] = {
      name          : "valuemap-readstate<-mapname",
      pkgname       : "vx/state",
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
      fn            : vx_state.f_valuemap_readstate_from_mapname
    }

  }
}
