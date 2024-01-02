'strict mode'

import vx_core from "../vx/core.js"
import vx_type from "../vx/type.js"


export default class vx_collection {

  static vx_any_from_for_until_loop_max(generic_any_1, start, fn_until, fn_loop, max) {
    let output = start
    let iscontinue = true
    let icount = 0
    const fnuntil = fn_until['vx_value']
    const fnloop = fn_loop['vx_value']
    while (iscontinue) {
      if (icount >= max) {
        iscontinue = false
      } else {
        icount += 1
        output = fnloop(output)
        iscontinue = !fnuntil(output)
      }
    }
    return output
  }

  static vx_any_from_for_while_loop_max(generic_any_1, start, fn_while, fn_loop, max) {
    let output = start
    let iscontinue = true
    let icount = 0
    const fnwhile = fn_while['vx_value']
    const fnloop = fn_loop['vx_value']
    while (iscontinue) {
      if (icount >= max) {
        iscontinue = false
      } else {
        icount += 1;
        iscontinue = fnwhile(output)
        if (iscontinue) {
          output = fnloop(output)
        }
      }
    }
    return output
  }

  static vx_list_from_for_end_loop(generic_list_1, start, end, fn_loop) {
    let output = vx_core.vx_empty(generic_list_1)
    let listvals = []
    const fnloop = fn_loop['vx_value']
    if (start <= end) {
      for (let i = start; i <= end; i++) {
        let val = fnloop(i)
        listvals.push(val)
      }
    } else {
      for (let i = start; i >= end; i--) {
        let val = fnloop(i)
        listvals.push(val)
      }
    }
    if (listvals.length > 0) {
      output = vx_core.vx_new(generic_list_1, listvals)
    }
    return output
  }

  static vx_list_from_for_while_loop_max(generic_list_1, start, fn_while, fn_loop, max) {
    let output = vx_core.vx_empty(generic_list_1)
    let listvals = []
    let iscontinue = true
    let icount = 0
    const fnwhile = fn_while['vx_value']
    const fnloop = fn_loop['vx_value']
    let work = start
    while (iscontinue) {
      if (icount >= max) {
        iscontinue = false
      } else {
        iscontinue = !fnwhile(work)
        if (iscontinue) {
          icount += 1
          work = fnloop(work)
          listvals.push(work)
        }
      }
    }
    if (listvals.length > 0) {
      output = vx_core.vx_new(generic_list_1, listvals)
    }
    return output
  }

  static vx_list_from_list_filter(generic_list_1, vallist, fn_filter) {
    let output = vx_core.vx_empty(generic_list_1)
    const fn = fn_filter['vx_value']
    if (fn) {
      const items = []
      vallist.forEach(val => {
        const newval = fn(val)
        if (!vx_core.f_is_empty_1(newval)) {
          items.push(newval)
        }
      })
      //const type = vx_core.f_type_from_any(output)
      output = vx_core.f_new(generic_list_1, ...items)
    }
    return output
  }

  static vx_list_from_list_start_end(generic_list_1, values, start, end) {
    let output = vx_core.vx_empty(generic_list_1)
    const maxlen = values.length
    if (end < 0) {
     end += maxlen
    }
    if (start < 1) {
    } else if (start > end) {
    } else if (start > maxlen) {
    } else {
      if (end > maxlen) {
        end = maxlen
      }
      output = values.slice(start - 1, end)
      const typ = values['vx_type']
      if (typ) {
        output['vx_type'] = typ
      }
    }
    return output
  }
  /**
   * @function any_from_for_until_loop
   * Returns a value using an until loop. Maximum 1000 times.
   * @param  {typemap} generic
   * @param  {any} start
   * @param  {boolean_from_any} fn_until
   * @param  {any_from_any} fn_loop
   * @return {any-1}
   */
  static t_any_from_for_until_loop = {}
  static e_any_from_for_until_loop = {vx_type: vx_collection.t_any_from_for_until_loop}

  // (func any<-for-until-loop)
  static f_any_from_for_until_loop(generic, start, fn_until, fn_loop) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    output = vx_collection.f_any_from_for_until_loop_max({"any-1": vx_core.t_any}, start, fn_until, fn_loop, 1000)
    return output
  }

  /**
   * @function any_from_for_until_loop_max
   * Returns a value using a until loop.
   * output : any-1 := start
   * count : int := 0
   * (while continue
   *   continue : boolean := (count <= max)
   *   (if continue
   *     count += 1
   *     output = (fn-loop output)
   *     continue = (fn-until output)))
   * @param  {typemap} generic
   * @param  {any} start
   * @param  {boolean_from_any} fn_until
   * @param  {any_from_any} fn_loop
   * @param  {int} max
   * @return {any-1}
   */
  static t_any_from_for_until_loop_max = {}
  static e_any_from_for_until_loop_max = {vx_type: vx_collection.t_any_from_for_until_loop_max}

  // (func any<-for-until-loop-max)
  static f_any_from_for_until_loop_max(generic, start, fn_until, fn_loop, max) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    output = vx_collection.vx_any_from_for_until_loop_max(generic_any_1, start, fn_until, fn_loop, max)
    return output
  }

  /**
   * @function any_from_for_while_loop
   * Returns a value using a while loop. Maximum 1000 times.
   * @param  {typemap} generic
   * @param  {any} start
   * @param  {boolean_from_any} fn_while
   * @param  {any_from_any} fn_loop
   * @return {any-1}
   */
  static t_any_from_for_while_loop = {}
  static e_any_from_for_while_loop = {vx_type: vx_collection.t_any_from_for_while_loop}

  // (func any<-for-while-loop)
  static f_any_from_for_while_loop(generic, start, fn_while, fn_loop) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    output = vx_collection.f_any_from_for_while_loop_max({"any-1": vx_core.t_any}, start, fn_while, fn_loop, 1000)
    return output
  }

  /**
   * @function any_from_for_while_loop_max
   * Returns a value using a while loop.
   * output : any-1 := start
   * count : int := 0
   * (while continue
   *  continue : boolean := (count <= max)
   *  (if continue
   *   continue = (fn-while output)
   *   (if continue
   *    count += 1
   *    output = (fn-loop output))))
   * @param  {typemap} generic
   * @param  {any} start
   * @param  {boolean_from_any} fn_while
   * @param  {any_from_any} fn_loop
   * @param  {int} max
   * @return {any-1}
   */
  static t_any_from_for_while_loop_max = {}
  static e_any_from_for_while_loop_max = {vx_type: vx_collection.t_any_from_for_while_loop_max}

  // (func any<-for-while-loop-max)
  static f_any_from_for_while_loop_max(generic, start, fn_while, fn_loop, max) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    output = vx_collection.vx_any_from_for_while_loop_max(generic_any_1, start, fn_while, fn_loop, max)
    return output
  }

  /**
   * @function is_list
   * Returns true if the given value is a list.
   * @param  {any} val Any value
   * @return {boolean}
   */
  static t_is_list = {}
  static e_is_list = {vx_type: vx_collection.t_is_list}

  // (func is-list)
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

  // (func is-map)
  static f_is_map(val) {
    let output = vx_core.e_boolean
    output = vx_core.f_eq(
      ":map",
      vx_core.f_extends_from_any(val)
    )
    return output
  }

  /**
   * @function list_from_for_end_loop
   * Returns a list of any-1 by iterating i from for to next where each item is (loop i).
   * This is similar to a for next loop in other languages.
   * output : list-1 := (empty list-1)
   * (if start <= end
   *  (for i=start to end
   *   val : any-1 := (fn-loop i)
   *   output += val)
   *  (else
   *   (for i=start to end; i--
   *    val : any-1 := (fn-loop i)
   *    output += val)
   *  ))
   * @param  {typemap} generic
   * @param  {int} start
   * @param  {int} end
   * @param  {any_from_int} fn_loop
   * @return {list-1}
   */
  static t_list_from_for_end_loop = {}
  static e_list_from_for_end_loop = {vx_type: vx_collection.t_list_from_for_end_loop}

  // (func list<-for-end-loop)
  static f_list_from_for_end_loop(generic, start, end, fn_loop) {
    const generic_any_1 = generic["any-1"]
    const generic_list_1 = generic["list-1"]
    let output = vx_core.f_empty(generic_list_1)
    output = vx_collection.vx_list_from_for_end_loop(generic_list_1, start, end, fn_loop)
    return output
  }

  /**
   * @function list_from_for_while_loop
   * Returns a list of any-1 using a while loop. Max: 1000
   * @param  {typemap} generic
   * @param  {any} start
   * @param  {boolean_from_any} fn_while
   * @param  {any_from_any} fn_loop
   * @return {list-1}
   */
  static t_list_from_for_while_loop = {}
  static e_list_from_for_while_loop = {vx_type: vx_collection.t_list_from_for_while_loop}

  // (func list<-for-while-loop)
  static f_list_from_for_while_loop(generic, start, fn_while, fn_loop) {
    const generic_any_1 = generic["any-1"]
    const generic_list_1 = generic["list-1"]
    let output = vx_core.f_empty(generic_list_1)
    output = vx_collection.f_list_from_for_while_loop_max({"any-1": vx_core.t_any, "list-1": vx_core.t_list}, start, fn_while, fn_loop, 1000)
    return output
  }

  /**
   * @function list_from_for_while_loop_max
   * Returns a list of any-1 using a while loop.
   * 1. output : list-1 := (empty list-1)
   * 2. value : any-1 := start.
   * 3. value : any-1 := (fn-loop value).
   * 4. check : boolean := (fn-while value).
   * 5. if (= check true) output := (copy output value), Go to 3 (Maximum max times).
   * 6. else end.
   * @param  {typemap} generic
   * @param  {any} start
   * @param  {boolean_from_any} fn_while
   * @param  {any_from_any} fn_loop
   * @param  {int} max
   * @return {list-1}
   */
  static t_list_from_for_while_loop_max = {}
  static e_list_from_for_while_loop_max = {vx_type: vx_collection.t_list_from_for_while_loop_max}

  // (func list<-for-while-loop-max)
  static f_list_from_for_while_loop_max(generic, start, fn_while, fn_loop, max) {
    const generic_any_1 = generic["any-1"]
    const generic_list_1 = generic["list-1"]
    let output = vx_core.f_empty(generic_list_1)
    output = vx_collection.vx_list_from_for_while_loop_max(generic_list_1, start, fn_while, fn_loop, max)
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

  // (func list<-list-end)
  static f_list_from_list_end(generic, values, end) {
    const generic_any_1 = generic["any-1"]
    const generic_list_1 = generic["list-1"]
    let output = vx_core.f_empty(generic_list_1)
    output = vx_collection.f_list_from_list_start_end({"any-1": vx_core.t_any, "list-1": vx_core.t_list}, values, 1, end)
    return output
  }

  /**
   * @function list_from_list_filter
   * Filter List to only include non-empty values
   * @param  {typemap} generic
   * @param  {list} vallist
   * @param  {any_from_any} fn_filter
   * @return {list-1}
   */
  static t_list_from_list_filter = {}
  static e_list_from_list_filter = {vx_type: vx_collection.t_list_from_list_filter}

  // (func list<-list-filter)
  static f_list_from_list_filter(generic, vallist, fn_filter) {
    const generic_any_1 = generic["any-1"]
    const generic_list_1 = generic["list-1"]
    let output = vx_core.f_empty(generic_list_1)
    output = vx_collection.vx_list_from_list_filter(generic_list_1, vallist, fn_filter)
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

  // (func list<-list-filtertypes)
  static f_list_from_list_filtertypes(generic, vallist, ...filtertypes) {
    const generic_any_1 = generic["any-1"]
    const generic_list_1 = generic["list-1"]
    let output = vx_core.f_empty(generic_list_1)
    filtertypes = vx_core.f_new(vx_core.t_typelist, ...filtertypes)
    output = vx_collection.f_list_from_list_filter(
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
   * @function list_from_list_start
   * Returns a sub list from start to list end.
   * @param  {typemap} generic
   * @param  {list} values
   * @param  {int} start
   * @return {list-1}
   */
  static t_list_from_list_start = {}
  static e_list_from_list_start = {vx_type: vx_collection.t_list_from_list_start}

  // (func list<-list-start)
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

  // (func list<-list-start-end)
  static f_list_from_list_start_end(generic, values, start, end) {
    const generic_any_1 = generic["any-1"]
    const generic_list_1 = generic["list-1"]
    let output = vx_core.f_empty(generic_list_1)
    output = vx_collection.vx_list_from_list_start_end(generic_list_1, values, start, end)
    return output
  }

  // empty types


  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "any<-for-until-loop": vx_collection.e_any_from_for_until_loop,
      "any<-for-until-loop-max": vx_collection.e_any_from_for_until_loop_max,
      "any<-for-while-loop": vx_collection.e_any_from_for_while_loop,
      "any<-for-while-loop-max": vx_collection.e_any_from_for_while_loop_max,
      "is-list": vx_collection.e_is_list,
      "is-map": vx_collection.e_is_map,
      "list<-for-end-loop": vx_collection.e_list_from_for_end_loop,
      "list<-for-while-loop": vx_collection.e_list_from_for_while_loop,
      "list<-for-while-loop-max": vx_collection.e_list_from_for_while_loop_max,
      "list<-list-end": vx_collection.e_list_from_list_end,
      "list<-list-filter": vx_collection.e_list_from_list_filter,
      "list<-list-filtertypes": vx_collection.e_list_from_list_filtertypes,
      "list<-list-start": vx_collection.e_list_from_list_start,
      "list<-list-start-end": vx_collection.e_list_from_list_start_end
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "any<-for-until-loop": vx_collection.t_any_from_for_until_loop,
      "any<-for-until-loop-max": vx_collection.t_any_from_for_until_loop_max,
      "any<-for-while-loop": vx_collection.t_any_from_for_while_loop,
      "any<-for-while-loop-max": vx_collection.t_any_from_for_while_loop_max,
      "is-list": vx_collection.t_is_list,
      "is-map": vx_collection.t_is_map,
      "list<-for-end-loop": vx_collection.t_list_from_for_end_loop,
      "list<-for-while-loop": vx_collection.t_list_from_for_while_loop,
      "list<-for-while-loop-max": vx_collection.t_list_from_for_while_loop_max,
      "list<-list-end": vx_collection.t_list_from_list_end,
      "list<-list-filter": vx_collection.t_list_from_list_filter,
      "list<-list-filtertypes": vx_collection.t_list_from_list_filtertypes,
      "list<-list-start": vx_collection.t_list_from_list_start,
      "list<-list-start-end": vx_collection.t_list_from_list_start_end
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      
    })
    const pkg = vx_core.vx_new_struct(vx_core.t_package, {
      "name": "vx/collection",
      "constmap": constmap,
      "emptymap": emptymap,
      "funcmap": funcmap,
      "typemap": typemap
    })
    vx_core.vx_global_package_set(pkg)

    // (func any<-for-until-loop)
    vx_collection.t_any_from_for_until_loop['vx_type'] = vx_core.t_type
    vx_collection.t_any_from_for_until_loop['vx_value'] = {
      name          : "any<-for-until-loop",
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
      fn            : vx_collection.f_any_from_for_until_loop
    }

    // (func any<-for-until-loop-max)
    vx_collection.t_any_from_for_until_loop_max['vx_type'] = vx_core.t_type
    vx_collection.t_any_from_for_until_loop_max['vx_value'] = {
      name          : "any<-for-until-loop-max",
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
      fn            : vx_collection.f_any_from_for_until_loop_max
    }

    // (func any<-for-while-loop)
    vx_collection.t_any_from_for_while_loop['vx_type'] = vx_core.t_type
    vx_collection.t_any_from_for_while_loop['vx_value'] = {
      name          : "any<-for-while-loop",
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
      fn            : vx_collection.f_any_from_for_while_loop
    }

    // (func any<-for-while-loop-max)
    vx_collection.t_any_from_for_while_loop_max['vx_type'] = vx_core.t_type
    vx_collection.t_any_from_for_while_loop_max['vx_value'] = {
      name          : "any<-for-while-loop-max",
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
      fn            : vx_collection.f_any_from_for_while_loop_max
    }

    // (func is-list)
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

    // (func is-map)
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

    // (func list<-for-end-loop)
    vx_collection.t_list_from_for_end_loop['vx_type'] = vx_core.t_type
    vx_collection.t_list_from_for_end_loop['vx_value'] = {
      name          : "list<-for-end-loop",
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
      fn            : vx_collection.f_list_from_for_end_loop
    }

    // (func list<-for-while-loop)
    vx_collection.t_list_from_for_while_loop['vx_type'] = vx_core.t_type
    vx_collection.t_list_from_for_while_loop['vx_value'] = {
      name          : "list<-for-while-loop",
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
      fn            : vx_collection.f_list_from_for_while_loop
    }

    // (func list<-for-while-loop-max)
    vx_collection.t_list_from_for_while_loop_max['vx_type'] = vx_core.t_type
    vx_collection.t_list_from_for_while_loop_max['vx_value'] = {
      name          : "list<-for-while-loop-max",
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
      fn            : vx_collection.f_list_from_for_while_loop_max
    }

    // (func list<-list-end)
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

    // (func list<-list-filter)
    vx_collection.t_list_from_list_filter['vx_type'] = vx_core.t_type
    vx_collection.t_list_from_list_filter['vx_value'] = {
      name          : "list<-list-filter",
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
      fn            : vx_collection.f_list_from_list_filter
    }

    // (func list<-list-filtertypes)
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

    // (func list<-list-start)
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

    // (func list<-list-start-end)
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
