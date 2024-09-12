'strict mode'

import vx_core from "../vx/core.js"
import vx_type from "../vx/type.js"


export default class vx_collection {

  static vx_any_from_for_until_loop_max(
    generic_any_1,
    start,
    fn_until,
    fn_loop, max) {
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

  static vx_any_from_for_while_loop_max(
    generic_any_1,
    start,
    fn_while,
    fn_loop,
    max) {
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

  // (func anymap<-struct)
  static vx_anymap_from_struct(
    structure) {
    const map = structure['vx_value']
    const output = vx_core.vx_new_map(vx_core.t_anymap, map)
    return output
  }

  static vx_list_from_for_end_loop(
    generic_list_1,
    start,
    end,
    fn_loop) {
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

  static vx_list_from_for_while_loop_max(
    generic_list_1,
    start,
    fn_while,
    fn_loop, max) {
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

  static vx_list_from_list_filter(
    generic_list_1,
    vallist,
    fn_filter) {
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

  static vx_list_from_list_start_end(
    generic_list_1,
    values,
    start,
    end) {
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

  static vx_map_from_map_keys(
    generic_map_1,
    valuemap,
    keys) {
    let output = vx_core.vx_empty(generic_map_1)
    if (keys.length > 0) {
      const map = valuemap['vx_value']
      const values = []
      for (const key of keys) {
        const value = map[key]
        values.push(key)
        values.push(value)
      }
      output = vx_core.f_new(generic_map_1, ...values)
    }
    return output
  }
  /**
   * @function any_from_for_until_loop
   * Returns a value using an until loop. Maximum 10000 times.
   * @param  {typemap} generic
   * @param  {generic_any_1} start
   * @param  {boolean_from_any} fn_until
   * @param  {any_from_any} fn_loop
   * @return {any-1}
   */
  static t_any_from_for_until_loop = {
    vx_type: vx_core.t_type
  }
  static e_any_from_for_until_loop = {
    vx_type: vx_collection.t_any_from_for_until_loop
  }

  // (func any<-for-until-loop)
  static f_any_from_for_until_loop(generic, start, fn_until, fn_loop) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    output = vx_collection.f_any_from_for_until_loop_max({"any-1": generic_any_1}, start, fn_until, fn_loop, 10000)
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
   * @param  {generic_any_1} start
   * @param  {boolean_from_any} fn_until
   * @param  {any_from_any} fn_loop
   * @param  {int} max
   * @return {any-1}
   */
  static t_any_from_for_until_loop_max = {
    vx_type: vx_core.t_type
  }
  static e_any_from_for_until_loop_max = {
    vx_type: vx_collection.t_any_from_for_until_loop_max
  }

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
   * @param  {generic_any_1} start
   * @param  {boolean_from_any} fn_while
   * @param  {any_from_any} fn_loop
   * @return {any-1}
   */
  static t_any_from_for_while_loop = {
    vx_type: vx_core.t_type
  }
  static e_any_from_for_while_loop = {
    vx_type: vx_collection.t_any_from_for_while_loop
  }

  // (func any<-for-while-loop)
  static f_any_from_for_while_loop(generic, start, fn_while, fn_loop) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    output = vx_collection.f_any_from_for_while_loop_max({"any-1": generic_any_1}, start, fn_while, fn_loop, 1000)
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
   * @param  {generic_any_1} start
   * @param  {boolean_from_any} fn_while
   * @param  {any_from_any} fn_loop
   * @param  {int} max
   * @return {any-1}
   */
  static t_any_from_for_while_loop_max = {
    vx_type: vx_core.t_type
  }
  static e_any_from_for_while_loop_max = {
    vx_type: vx_collection.t_any_from_for_while_loop_max
  }

  // (func any<-for-while-loop-max)
  static f_any_from_for_while_loop_max(generic, start, fn_while, fn_loop, max) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    output = vx_collection.vx_any_from_for_while_loop_max(generic_any_1, start, fn_while, fn_loop, max)
    return output
  }

  /**
   * @function any_from_map_pos
   * Returns then numbered child from a map.
   * @param  {typemap} generic
   * @param  {generic_map_1} map
   * @param  {int} pos
   * @return {any-1}
   */
  static t_any_from_map_pos = {
    vx_type: vx_core.t_type
  }
  static e_any_from_map_pos = {
    vx_type: vx_collection.t_any_from_map_pos
  }

  // (func any<-map-pos)
  static f_any_from_map_pos(generic, map, pos) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    output = vx_core.f_let(
      {"any-1": generic_any_1},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const keys = vx_core.f_stringlist_from_map(map)
        const key = vx_core.f_any_from_list({"any-1": vx_core.t_string, "list-1": vx_core.t_stringlist}, keys, pos)
        return vx_core.f_any_from_map({"any-1": generic_any_1}, map, key)
      })
    )
    return output
  }

  /**
   * @function anymap_from_struct
   * Returns anymap from all the properties in a struct.
   * @param  {generic_struct_1} structure
   * @return {anymap}
   */
  static t_anymap_from_struct = {
    vx_type: vx_core.t_type
  }
  static e_anymap_from_struct = {
    vx_type: vx_collection.t_anymap_from_struct
  }

  // (func anymap<-struct)
  static f_anymap_from_struct(structure) {
    let output = vx_core.e_anymap
    output = vx_collection.vx_anymap_from_struct(structure)
    return output
  }

  /**
   * @function boolean_write_from_map_removekey
   * Returns true if it alters a mutable map false if it fails.
   * @param  {generic_map_1} valuemap
   * @param  {string} key
   * @return {boolean}
   */
  static t_boolean_write_from_map_removekey = {
    vx_type: vx_core.t_type
  }
  static e_boolean_write_from_map_removekey = {
    vx_type: vx_collection.t_boolean_write_from_map_removekey
  }

  // (func boolean-write<-map-removekey)
  static f_boolean_write_from_map_removekey(valuemap, key) {
    let output = vx_core.e_boolean
    output = vx_core.f_boolean_write_from_map_name_value(
      valuemap,
      key,
      vx_core.f_empty(
        vx_core.t_any
      )
    )
    return output
  }

  /**
   * @function boolean_write_from_map_removekeys
   * Returns true if it alters a mutable map false if it fails.
   * @param  {generic_map_1} valuemap
   * @param  {stringlist} keys
   * @return {boolean}
   */
  static t_boolean_write_from_map_removekeys = {
    vx_type: vx_core.t_type
  }
  static e_boolean_write_from_map_removekeys = {
    vx_type: vx_collection.t_boolean_write_from_map_removekeys
  }

  // (func boolean-write<-map-removekeys)
  static f_boolean_write_from_map_removekeys(valuemap, keys) {
    let output = vx_core.e_boolean
    output = vx_core.f_let(
      {"any-1": vx_core.t_boolean},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const writelist = vx_core.f_list_from_list_1(
          {"any-1": vx_core.t_boolean, "any-2": vx_core.t_string, "list-1": vx_core.t_booleanlist, "list-2": vx_core.t_stringlist},
          keys,
          vx_core.f_new(vx_core.t_any_from_any, (key) => 
            vx_collection.f_boolean_write_from_map_removekey(valuemap, key))
        )
        return vx_core.f_and_1(writelist)
      })
    )
    return output
  }

  /**
   * @function int_from_map_key
   * Returns the position of key in any map.
   * @param  {generic_map_1} map
   * @param  {string} key
   * @return {int}
   */
  static t_int_from_map_key = {
    vx_type: vx_core.t_type
  }
  static e_int_from_map_key = {
    vx_type: vx_collection.t_int_from_map_key
  }

  // (func int<-map-key)
  static f_int_from_map_key(map, key) {
    let output = vx_core.e_int
    output = vx_core.f_let(
      {"any-1": vx_core.t_int},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const keys = vx_core.f_stringlist_from_map(map)
        return vx_collection.f_int_from_stringlist_find(keys, key)
      })
    )
    return output
  }

  /**
   * @function int_from_stringlist_find
   * Returns the position (first position is 1) of find text in a stringlist.
   * @param  {stringlist} stringlist
   * @param  {string} find
   * @return {int}
   */
  static t_int_from_stringlist_find = {
    vx_type: vx_core.t_type
  }
  static e_int_from_stringlist_find = {
    vx_type: vx_collection.t_int_from_stringlist_find
  }

  // (func int<-stringlist-find)
  static f_int_from_stringlist_find(stringlist, find) {
    let output = vx_core.e_int
    output = vx_core.f_let(
      {"any-1": vx_core.t_int, "list-1": vx_core.t_intlist},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const poslist = vx_core.f_list_from_list_intany(
          {"any-1": vx_core.t_int, "any-2": vx_core.t_string, "list-1": vx_core.t_intlist, "list-2": vx_core.t_stringlist},
          stringlist,
          vx_core.f_new(vx_core.t_any_from_int_any, (pos, value) => 
            vx_core.f_if_1(
              {"any-1": vx_core.t_int},
              vx_core.f_eq(find, value),
              pos,
              0
            ))
        )
        const gt0list = vx_collection.f_list_from_list_filter(
          {"any-1": vx_core.t_int, "any-2": vx_core.t_int, "list-1": vx_core.t_intlist, "list-2": vx_core.t_intlist},
          poslist,
          vx_core.f_new(vx_core.t_any_from_any, (item) => item)
        )
        return vx_core.f_first_from_list({"any-1": vx_core.t_int, "list-1": vx_core.t_intlist}, gt0list)
      })
    )
    return output
  }

  /**
   * @function is_list
   * Returns true if the given value is a list.
   * @param  {any} value Any value
   * @return {boolean}
   */
  static t_is_list = {
    vx_type: vx_core.t_type
  }
  static e_is_list = {
    vx_type: vx_collection.t_is_list
  }

  // (func is-list)
  static f_is_list(value) {
    let output = vx_core.e_boolean
    output = vx_core.f_eq(
      ":list",
      vx_core.f_extends_from_any(value)
    )
    return output
  }

  /**
   * @function is_map
   * Returns true if the given value is a map.
   * @param  {any} value Any value
   * @return {boolean}
   */
  static t_is_map = {
    vx_type: vx_core.t_type
  }
  static e_is_map = {
    vx_type: vx_collection.t_is_map
  }

  // (func is-map)
  static f_is_map(value) {
    let output = vx_core.e_boolean
    output = vx_core.f_eq(
      ":map",
      vx_core.f_extends_from_any(value)
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
   *   value : any-1 := (fn-loop i)
   *   output += value)
   *  (else
   *   (for i=start to end; i--
   *    value : any-1 := (fn-loop i)
   *    output += value)
   *  ))
   * @param  {typemap} generic
   * @param  {int} start
   * @param  {int} end
   * @param  {any_from_int} fn_loop
   * @return {list-1}
   */
  static t_list_from_for_end_loop = {
    vx_type: vx_core.t_type
  }
  static e_list_from_for_end_loop = {
    vx_type: vx_collection.t_list_from_for_end_loop
  }

  // (func list<-for-end-loop)
  static f_list_from_for_end_loop(generic, start, end, fn_loop) {
    const generic_list_1 = generic["list-1"]
    let output = vx_core.f_empty(generic_list_1)
    output = vx_collection.vx_list_from_for_end_loop(generic_list_1, start, end, fn_loop)
    return output
  }

  /**
   * @function list_from_for_while_loop
   * Returns a list of any-1 using a while loop. Max: 1000
   * @param  {typemap} generic
   * @param  {generic_any_1} start
   * @param  {boolean_from_any} fn_while
   * @param  {any_from_any} fn_loop
   * @return {list-1}
   */
  static t_list_from_for_while_loop = {
    vx_type: vx_core.t_type
  }
  static e_list_from_for_while_loop = {
    vx_type: vx_collection.t_list_from_for_while_loop
  }

  // (func list<-for-while-loop)
  static f_list_from_for_while_loop(generic, start, fn_while, fn_loop) {
    const generic_list_1 = generic["list-1"]
    let output = vx_core.f_empty(generic_list_1)
    output = vx_collection.f_list_from_for_while_loop_max({"list-1": generic_list_1}, start, fn_while, fn_loop, 1000)
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
   * @param  {generic_any_1} start
   * @param  {boolean_from_any} fn_while
   * @param  {any_from_any} fn_loop
   * @param  {int} max
   * @return {list-1}
   */
  static t_list_from_for_while_loop_max = {
    vx_type: vx_core.t_type
  }
  static e_list_from_for_while_loop_max = {
    vx_type: vx_collection.t_list_from_for_while_loop_max
  }

  // (func list<-for-while-loop-max)
  static f_list_from_for_while_loop_max(generic, start, fn_while, fn_loop, max) {
    const generic_list_1 = generic["list-1"]
    let output = vx_core.f_empty(generic_list_1)
    output = vx_collection.vx_list_from_for_while_loop_max(generic_list_1, start, fn_while, fn_loop, max)
    return output
  }

  /**
   * @function list_from_list_end
   * Returns a sub list from positions 1 to end inclusive.
   * @param  {typemap} generic
   * @param  {generic_list_1} values
   * @param  {int} end
   * @return {list-1}
   */
  static t_list_from_list_end = {
    vx_type: vx_core.t_type
  }
  static e_list_from_list_end = {
    vx_type: vx_collection.t_list_from_list_end
  }

  // (func list<-list-end)
  static f_list_from_list_end(generic, values, end) {
    const generic_list_1 = generic["list-1"]
    let output = vx_core.f_empty(generic_list_1)
    output = vx_collection.f_list_from_list_start_end({"list-1": generic_list_1}, values, 1, end)
    return output
  }

  /**
   * @function list_from_list_filter
   * Filter List to only include non-empty values
   * @param  {typemap} generic
   * @param  {generic_list_2} vallist
   * @param  {any_from_any} fn_filter
   * @return {list-1}
   */
  static t_list_from_list_filter = {
    vx_type: vx_core.t_type
  }
  static e_list_from_list_filter = {
    vx_type: vx_collection.t_list_from_list_filter
  }

  // (func list<-list-filter)
  static f_list_from_list_filter(generic, vallist, fn_filter) {
    const generic_list_1 = generic["list-1"]
    let output = vx_core.f_empty(generic_list_1)
    output = vx_collection.vx_list_from_list_filter(generic_list_1, vallist, fn_filter)
    return output
  }

  /**
   * @function list_from_list_filtertypes
   * Filter List to only include matching types
   * @param  {typemap} generic
   * @param  {generic_list_2} vallist
   * @param  {typelist} ... filtertypes
   * @return {list-1}
   */
  static t_list_from_list_filtertypes = {
    vx_type: vx_core.t_type
  }
  static e_list_from_list_filtertypes = {
    vx_type: vx_collection.t_list_from_list_filtertypes
  }

  // (func list<-list-filtertypes)
  static f_list_from_list_filtertypes(generic, vallist, ...filtertypes) {
    const generic_list_1 = generic["list-1"]
    let output = vx_core.f_empty(generic_list_1)
    filtertypes = vx_core.f_new(vx_core.t_typelist, ...filtertypes)
    output = vx_collection.f_list_from_list_filter(
      {"any-1": vx_core.t_any, "list-1": generic_list_1},
      vallist,
      vx_core.f_new(vx_core.t_any_from_any, (value) => 
        vx_core.f_if(
          {"any-1": vx_core.t_any},
          vx_type.f_is_type_from_any_typelist(value, filtertypes),
          value
        ))
    )
    return output
  }

  /**
   * @function list_from_list_start
   * Returns a sub list from start to list end.
   * @param  {typemap} generic
   * @param  {generic_list_1} values
   * @param  {int} start
   * @return {list-1}
   */
  static t_list_from_list_start = {
    vx_type: vx_core.t_type
  }
  static e_list_from_list_start = {
    vx_type: vx_collection.t_list_from_list_start
  }

  // (func list<-list-start)
  static f_list_from_list_start(generic, values, start) {
    const generic_list_1 = generic["list-1"]
    let output = vx_core.f_empty(generic_list_1)
    output = vx_collection.f_list_from_list_start_end(
      {"list-1": generic_list_1},
      values,
      start,
      vx_core.f_length_1(values)
    )
    return output
  }

  /**
   * @function list_from_list_start_end
   * Returns a sublist from another list
   * @param  {typemap} generic
   * @param  {generic_list_1} values
   * @param  {int} start
   * @param  {int} end
   * @return {list-1}
   */
  static t_list_from_list_start_end = {
    vx_type: vx_core.t_type
  }
  static e_list_from_list_start_end = {
    vx_type: vx_collection.t_list_from_list_start_end
  }

  // (func list<-list-start-end)
  static f_list_from_list_start_end(generic, values, start, end) {
    const generic_list_1 = generic["list-1"]
    let output = vx_core.f_empty(generic_list_1)
    output = vx_collection.vx_list_from_list_start_end(generic_list_1, values, start, end)
    return output
  }

  /**
   * @function map_from_map_end
   * Returns a submap from key positions 1 to end inclusive.
   * @param  {typemap} generic
   * @param  {generic_map_1} valuemap
   * @param  {int} end
   * @return {map-1}
   */
  static t_map_from_map_end = {
    vx_type: vx_core.t_type
  }
  static e_map_from_map_end = {
    vx_type: vx_collection.t_map_from_map_end
  }

  // (func map<-map-end)
  static f_map_from_map_end(generic, valuemap, end) {
    const generic_map_1 = generic["map-1"]
    let output = vx_core.f_empty(generic_map_1)
    output = vx_collection.f_map_from_map_start_end({"map-1": generic_map_1}, valuemap, 1, end)
    return output
  }

  /**
   * @function map_from_map_keys
   * Returns a submap from another map using a keylist
   * @param  {typemap} generic
   * @param  {generic_map_1} valuemap
   * @param  {stringlist} keys
   * @return {map-1}
   */
  static t_map_from_map_keys = {
    vx_type: vx_core.t_type
  }
  static e_map_from_map_keys = {
    vx_type: vx_collection.t_map_from_map_keys
  }

  // (func map<-map-keys)
  static f_map_from_map_keys(generic, valuemap, keys) {
    const generic_map_1 = generic["map-1"]
    let output = vx_core.f_empty(generic_map_1)
    output = vx_collection.vx_map_from_map_keys(generic_map_1, valuemap, keys)
    return output
  }

  /**
   * @function map_from_map_start
   * Returns a sub map from start to map end.
   * @param  {typemap} generic
   * @param  {generic_map_1} valuemap
   * @param  {int} start
   * @return {map-1}
   */
  static t_map_from_map_start = {
    vx_type: vx_core.t_type
  }
  static e_map_from_map_start = {
    vx_type: vx_collection.t_map_from_map_start
  }

  // (func map<-map-start)
  static f_map_from_map_start(generic, valuemap, start) {
    const generic_map_1 = generic["map-1"]
    let output = vx_core.f_empty(generic_map_1)
    output = vx_collection.f_map_from_map_start_end(
      {"map-1": generic_map_1},
      valuemap,
      start,
      vx_core.f_length_2(valuemap)
    )
    return output
  }

  /**
   * @function map_from_map_start_end
   * Returns a submap from another map using the index of the keylist
   * @param  {typemap} generic
   * @param  {generic_map_1} valuemap
   * @param  {int} start
   * @param  {int} end
   * @return {map-1}
   */
  static t_map_from_map_start_end = {
    vx_type: vx_core.t_type
  }
  static e_map_from_map_start_end = {
    vx_type: vx_collection.t_map_from_map_start_end
  }

  // (func map<-map-start-end)
  static f_map_from_map_start_end(generic, valuemap, start, end) {
    const generic_map_1 = generic["map-1"]
    let output = vx_core.f_empty(generic_map_1)
    output = vx_core.f_let(
      {"any-1": generic_map_1, "map-1": generic_map_1},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const keys1 = vx_core.f_stringlist_from_map(valuemap)
        const keys2 = vx_collection.f_list_from_list_start_end({"any-1": vx_core.t_string, "list-1": vx_core.t_stringlist}, keys1, start, end)
        return vx_collection.f_map_from_map_keys({"map-1": generic_map_1}, valuemap, keys2)
      })
    )
    return output
  }

  /**
   * @function map_from_struct
   * Returns a typed map from all the properties in a struct.
   * @param  {typemap} generic
   * @param  {generic_struct_2} structure
   * @return {map-1}
   */
  static t_map_from_struct = {
    vx_type: vx_core.t_type
  }
  static e_map_from_struct = {
    vx_type: vx_collection.t_map_from_struct
  }

  // (func map<-struct)
  static f_map_from_struct(generic, structure) {
    const generic_map_1 = generic["map-1"]
    let output = vx_core.f_empty(generic_map_1)
    output = vx_core.f_let(
      {"any-1": generic_map_1, "map-1": generic_map_1, "map-2": vx_core.t_anymap},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const anymap = vx_collection.f_anymap_from_struct(structure)
        return vx_core.f_map_from_map({"map-1": generic_map_1, "map-2": vx_core.t_anymap}, anymap)
      })
    )
    return output
  }



  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "any<-for-until-loop": vx_collection.e_any_from_for_until_loop,
      "any<-for-until-loop-max": vx_collection.e_any_from_for_until_loop_max,
      "any<-for-while-loop": vx_collection.e_any_from_for_while_loop,
      "any<-for-while-loop-max": vx_collection.e_any_from_for_while_loop_max,
      "any<-map-pos": vx_collection.e_any_from_map_pos,
      "anymap<-struct": vx_collection.e_anymap_from_struct,
      "boolean-write<-map-removekey": vx_collection.e_boolean_write_from_map_removekey,
      "boolean-write<-map-removekeys": vx_collection.e_boolean_write_from_map_removekeys,
      "int<-map-key": vx_collection.e_int_from_map_key,
      "int<-stringlist-find": vx_collection.e_int_from_stringlist_find,
      "is-list": vx_collection.e_is_list,
      "is-map": vx_collection.e_is_map,
      "list<-for-end-loop": vx_collection.e_list_from_for_end_loop,
      "list<-for-while-loop": vx_collection.e_list_from_for_while_loop,
      "list<-for-while-loop-max": vx_collection.e_list_from_for_while_loop_max,
      "list<-list-end": vx_collection.e_list_from_list_end,
      "list<-list-filter": vx_collection.e_list_from_list_filter,
      "list<-list-filtertypes": vx_collection.e_list_from_list_filtertypes,
      "list<-list-start": vx_collection.e_list_from_list_start,
      "list<-list-start-end": vx_collection.e_list_from_list_start_end,
      "map<-map-end": vx_collection.e_map_from_map_end,
      "map<-map-keys": vx_collection.e_map_from_map_keys,
      "map<-map-start": vx_collection.e_map_from_map_start,
      "map<-map-start-end": vx_collection.e_map_from_map_start_end,
      "map<-struct": vx_collection.e_map_from_struct
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "any<-for-until-loop": vx_collection.t_any_from_for_until_loop,
      "any<-for-until-loop-max": vx_collection.t_any_from_for_until_loop_max,
      "any<-for-while-loop": vx_collection.t_any_from_for_while_loop,
      "any<-for-while-loop-max": vx_collection.t_any_from_for_while_loop_max,
      "any<-map-pos": vx_collection.t_any_from_map_pos,
      "anymap<-struct": vx_collection.t_anymap_from_struct,
      "boolean-write<-map-removekey": vx_collection.t_boolean_write_from_map_removekey,
      "boolean-write<-map-removekeys": vx_collection.t_boolean_write_from_map_removekeys,
      "int<-map-key": vx_collection.t_int_from_map_key,
      "int<-stringlist-find": vx_collection.t_int_from_stringlist_find,
      "is-list": vx_collection.t_is_list,
      "is-map": vx_collection.t_is_map,
      "list<-for-end-loop": vx_collection.t_list_from_for_end_loop,
      "list<-for-while-loop": vx_collection.t_list_from_for_while_loop,
      "list<-for-while-loop-max": vx_collection.t_list_from_for_while_loop_max,
      "list<-list-end": vx_collection.t_list_from_list_end,
      "list<-list-filter": vx_collection.t_list_from_list_filter,
      "list<-list-filtertypes": vx_collection.t_list_from_list_filtertypes,
      "list<-list-start": vx_collection.t_list_from_list_start,
      "list<-list-start-end": vx_collection.t_list_from_list_start_end,
      "map<-map-end": vx_collection.t_map_from_map_end,
      "map<-map-keys": vx_collection.t_map_from_map_keys,
      "map<-map-start": vx_collection.t_map_from_map_start,
      "map<-map-start-end": vx_collection.t_map_from_map_start_end,
      "map<-struct": vx_collection.t_map_from_struct
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

    // (func any<-map-pos)
    vx_collection.t_any_from_map_pos['vx_value'] = {
      name          : "any<-map-pos",
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
      fn            : vx_collection.f_any_from_map_pos
    }

    // (func anymap<-struct)
    vx_collection.t_anymap_from_struct['vx_value'] = {
      name          : "anymap<-struct",
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
      fn            : vx_collection.f_anymap_from_struct
    }

    // (func boolean-write<-map-removekey)
    vx_collection.t_boolean_write_from_map_removekey['vx_value'] = {
      name          : "boolean-write<-map-removekey",
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
      fn            : vx_collection.f_boolean_write_from_map_removekey
    }

    // (func boolean-write<-map-removekeys)
    vx_collection.t_boolean_write_from_map_removekeys['vx_value'] = {
      name          : "boolean-write<-map-removekeys",
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
      fn            : vx_collection.f_boolean_write_from_map_removekeys
    }

    // (func int<-map-key)
    vx_collection.t_int_from_map_key['vx_value'] = {
      name          : "int<-map-key",
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
      fn            : vx_collection.f_int_from_map_key
    }

    // (func int<-stringlist-find)
    vx_collection.t_int_from_stringlist_find['vx_value'] = {
      name          : "int<-stringlist-find",
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
      fn            : vx_collection.f_int_from_stringlist_find
    }

    // (func is-list)
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

    // (func map<-map-end)
    vx_collection.t_map_from_map_end['vx_value'] = {
      name          : "map<-map-end",
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
      fn            : vx_collection.f_map_from_map_end
    }

    // (func map<-map-keys)
    vx_collection.t_map_from_map_keys['vx_value'] = {
      name          : "map<-map-keys",
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
      fn            : vx_collection.f_map_from_map_keys
    }

    // (func map<-map-start)
    vx_collection.t_map_from_map_start['vx_value'] = {
      name          : "map<-map-start",
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
      fn            : vx_collection.f_map_from_map_start
    }

    // (func map<-map-start-end)
    vx_collection.t_map_from_map_start_end['vx_value'] = {
      name          : "map<-map-start-end",
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
      fn            : vx_collection.f_map_from_map_start_end
    }

    // (func map<-struct)
    vx_collection.t_map_from_struct['vx_value'] = {
      name          : "map<-struct",
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
      fn            : vx_collection.f_map_from_struct
    }

  }
}
