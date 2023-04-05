'strict mode'

import vx_core from "../vx/core.js"
import vx_type from "../vx/type.js"

export default class vx_collection {
  /**
   * @function is_list
   * Returns true if the given value is a list.
   * @param  {any} val Any value
   * @return {boolean}
   */
  static t_is_list = {}
  static e_is_list = {vx_type: vx_collection.t_is_list}

  static f_is_list(val) {
    let output = vx_core.e_boolean
    output = vx_core.f_eq(
      ":list",
      vx_core.f_extends_from_any(val)
    )
    return output
  }

  /**
   * @function is_map
   * Returns true if the given value is a map.
   * @param  {any} val Any value
   * @return {boolean}
   */
  static t_is_map = {}
  static e_is_map = {vx_type: vx_collection.t_is_map}

  static f_is_map(val) {
    let output = vx_core.e_boolean
    output = vx_core.f_eq(
      ":map",
      vx_core.f_extends_from_any(val)
    )
    return output
  }

  /**
   * @function list_from_list_end
   * Returns a sub list from positions 0 to end.
   * @param  {typemap} generic
   * @param  {list} values
   * @param  {int} end
   * @return {list-1}
   */
  static t_list_from_list_end = {}
  static e_list_from_list_end = {vx_type: vx_collection.t_list_from_list_end}

  static f_list_from_list_end(generic, values, end) {
    const generic_any_1 = generic["any-1"]
    const generic_list_1 = generic["list-1"]
    let output = vx_core.f_empty(generic_list_1)
    output = vx_collection.f_list_from_list_start_end({"any-1": vx_core.t_any, "list-1": vx_core.t_list}, values, 0, end)
    return output
  }

  /**
   * @function list_from_list_filtertypes
   * Filter List to only include matching types
   * @param  {typemap} generic
   * @param  {list} vallist
   * @param  {typelist} ... filtertypes
   * @return {list-1}
   */
  static t_list_from_list_filtertypes = {}
  static e_list_from_list_filtertypes = {vx_type: vx_collection.t_list_from_list_filtertypes}

  static f_list_from_list_filtertypes(generic, vallist, ...filtertypes) {
    const generic_any_1 = generic["any-1"]
    const generic_list_1 = generic["list-1"]
    let output = vx_core.f_empty(generic_list_1)
    filtertypes = vx_core.f_new(vx_core.t_typelist, ...filtertypes)
    output = vx_collection.f_list_from_list_fn_filter(
      {"any-1": vx_core.t_any, "list-1": vx_core.t_list},
      vallist,
      vx_core.f_new(vx_core.t_any_from_any, (val) => 
        vx_core.f_if(
          {"any-1": vx_core.t_any},
          vx_type.f_is_type_from_any_typelist(val, filtertypes),
          val
        ))
    )
    return output
  }

  /**
   * @function list_from_list_fn_filter
   * Filter List to only include non-empty values
   * @param  {typemap} generic
   * @param  {list} vallist
   * @param  {any_from_any} fn_filter
   * @return {list-1}
   */
  static t_list_from_list_fn_filter = {}
  static e_list_from_list_fn_filter = {vx_type: vx_collection.t_list_from_list_fn_filter}

  static f_list_from_list_fn_filter(generic, vallist, fn_filter) {
    const generic_any_1 = generic["any-1"]
    const generic_list_1 = generic["list-1"]
    let output = vx_core.f_empty(generic_list_1)
    const fn = fn_filter['vx_value']
    if (fn) {
      const items = []
      vallist.forEach(val => {
        const newval = fn(val)
        if (!vx_core.f_is_empty_1(newval)) {
          items.push(newval)
        }
      })
      const type = vx_core.f_type_from_any(
      output
    )
      output = vx_core.f_new(generic_list_1, ...items)
    }
    return output
  }

  /**
   * @function list_from_list_start
   * Returns a sub list from start to list end.
   * @param  {typemap} generic
   * @param  {list} values
   * @param  {int} start
   * @return {list-1}
   */
  static t_list_from_list_start = {}
  static e_list_from_list_start = {vx_type: vx_collection.t_list_from_list_start}

  static f_list_from_list_start(generic, values, start) {
    const generic_any_1 = generic["any-1"]
    const generic_list_1 = generic["list-1"]
    let output = vx_core.f_empty(generic_list_1)
    output = vx_collection.f_list_from_list_start_end(
      {"any-1": vx_core.t_any, "list-1": vx_core.t_list},
      values,
      start,
      vx_core.f_length_from_list(values)
    )
    return output
  }

  /**
   * @function list_from_list_start_end
   * Returns a list from another list
   * @param  {typemap} generic
   * @param  {list} values
   * @param  {int} start
   * @param  {int} end
   * @return {list-1}
   */
  static t_list_from_list_start_end = {}
  static e_list_from_list_start_end = {vx_type: vx_collection.t_list_from_list_start_end}

  static f_list_from_list_start_end(generic, values, start, end) {
    const generic_any_1 = generic["any-1"]
    const generic_list_1 = generic["list-1"]
    let output = vx_core.f_empty(generic_list_1)
    let istart = start
    let iend = end
    const isize = values.length
    if (isize > 0) {
      if (istart < 0) {
        istart = 0
      }
      if (iend > isize) {
        iend = isize
      }
      output = values.slice(istart, iend)
      const typ = values['vx_type']
      if (typ) {
        output['vx_type'] = typ
      }
    }
    return output
  }

  // empty types

  static c_empty = {
    "is-list": vx_collection.e_is_list,
    "is-map": vx_collection.e_is_map,
    "list<-list-end": vx_collection.e_list_from_list_end,
    "list<-list-filtertypes": vx_collection.e_list_from_list_filtertypes,
    "list<-list-fn-filter": vx_collection.e_list_from_list_fn_filter,
    "list<-list-start": vx_collection.e_list_from_list_start,
    "list<-list-start-end": vx_collection.e_list_from_list_start_end
  }


  static {
    vx_core.f_global_package_set("vx/collection", vx_collection)

    // (func is_list)
    vx_collection.t_is_list['vx_type'] = vx_core.t_type
    vx_collection.t_is_list['vx_value'] = {
      name          : "is-list",
      pkgname       : "vx/collection",
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
      fn            : vx_collection.f_is_list
    }

    // (func is_map)
    vx_collection.t_is_map['vx_type'] = vx_core.t_type
    vx_collection.t_is_map['vx_value'] = {
      name          : "is-map",
      pkgname       : "vx/collection",
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
      fn            : vx_collection.f_is_map
    }

    // (func list_from_list_end)
    vx_collection.t_list_from_list_end['vx_type'] = vx_core.t_type
    vx_collection.t_list_from_list_end['vx_value'] = {
      name          : "list<-list-end",
      pkgname       : "vx/collection",
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
      fn            : vx_collection.f_list_from_list_end
    }

    // (func list_from_list_filtertypes)
    vx_collection.t_list_from_list_filtertypes['vx_type'] = vx_core.t_type
    vx_collection.t_list_from_list_filtertypes['vx_value'] = {
      name          : "list<-list-filtertypes",
      pkgname       : "vx/collection",
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
      fn            : vx_collection.f_list_from_list_filtertypes
    }

    // (func list_from_list_fn_filter)
    vx_collection.t_list_from_list_fn_filter['vx_type'] = vx_core.t_type
    vx_collection.t_list_from_list_fn_filter['vx_value'] = {
      name          : "list<-list-fn-filter",
      pkgname       : "vx/collection",
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
      fn            : vx_collection.f_list_from_list_fn_filter
    }

    // (func list_from_list_start)
    vx_collection.t_list_from_list_start['vx_type'] = vx_core.t_type
    vx_collection.t_list_from_list_start['vx_value'] = {
      name          : "list<-list-start",
      pkgname       : "vx/collection",
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
      fn            : vx_collection.f_list_from_list_start
    }

    // (func list_from_list_start_end)
    vx_collection.t_list_from_list_start_end['vx_type'] = vx_core.t_type
    vx_collection.t_list_from_list_start_end['vx_value'] = {
      name          : "list<-list-start-end",
      pkgname       : "vx/collection",
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
      fn            : vx_collection.f_list_from_list_start_end
    }

  }
}
