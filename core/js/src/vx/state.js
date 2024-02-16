'strict mode'

import vx_core from "../vx/core.js"


export default class vx_state {


  /**
   * type: value-map
   */
  static t_value_map = {}
  static e_value_map = {vx_type: vx_state.t_value_map}
  /**
   * @function change
   * Changes the current state
   * @param  {value_map} valuemap
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



  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "value-map": vx_state.e_value_map,
      "change": vx_state.e_change,
      "register": vx_state.e_register
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "change": vx_state.t_change,
      "register": vx_state.t_register
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      "value-map": vx_state.t_value_map
    })
    const pkg = vx_core.vx_new_struct(vx_core.t_package, {
      "name": "vx/state",
      "constmap": constmap,
      "emptymap": emptymap,
      "funcmap": funcmap,
      "typemap": typemap
    })
    vx_core.vx_global_package_set(pkg)

    // (type value-map)
    vx_state.t_value_map['vx_type'] = vx_core.t_type
    vx_state.t_value_map['vx_value'] = {
      name          : "value-map",
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
    vx_state.e_value_map['vx_type'] = vx_state.t_value_map
    vx_state.e_value_map['vx_value'] = {}

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

  }
}
