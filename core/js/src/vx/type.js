'strict mode'

import vx_core from "../vx/core.js"


export default class vx_type {

  // vx_boolean_from_string_starts(string, string)
  static vx_boolean_from_string_starts(text, starts) {
    return vx_core.vx_boolean_from_string_starts(text, starts)
  }

  // vx_int_from_string_find(string, string)
  static vx_int_from_string_find(text, find) {
    return text.indexOf(find) + 1
  }

  // vx_int_from_string_findlast(string, string)
  static vx_int_from_string_findlast(text, findlast) {
    return text.lastIndexOf(findlast) + 1
  }

  // vx_int_from_string_findkeyword(string, string)
  static vx_int_from_string_findkeyword(text, find) {
    let output = -1
    if (text != "") {
      switch (find) {
      case ":nonwhitespace":
        const wschars1 = [" ", "\n", "\r", "\t"]
        let ilen = text.length
        for (let i = 0; i < ilen; i++) {
          const char = text.charAt(i)
          if (!wschars1.includes(char)) {
            output = i
            break
          }
        }
        break
      case ":whitespace":
        const wschars2 = [" ", "\n", "\r", "\t"]
        for (let char of wschars2) {
          const pos = text.indexOf(char)
          if (pos < 0) {
          } else if (output < 0) {
           output = pos
          } else if (pos < output) {
           output = pos
          }
        }
        break
      default:
        output = text.indexOf(find)
        break
      }
    }
    output += 1
    return output
  }

  static vx_string_from_stringlist_join(stringlist, join) {
    let output = vx_core.e_string
    if (stringlist.length > 0) {
      output = stringlist.join(join)
    }
    return output
  }

  static vx_string_lowercase(text) {
    let output = text.toLowerCase()
    return output
  }

  static vx_string_trim(text) {
    let output = text.trim()
    return output
  }

  static vx_string_uppercase(text) {
    let output = text.toUpperCase()
    return output
  }

  static vx_stringlist_from_string_split(text, delim) {
    const liststring = text.split(delim)
    const output = vx_core.f_new(vx_core.t_stringlist, ...liststring)
    return output
  }
  /**
   * @function allowtypenames_from_type
   * Get the name of a given type
   * @param  {any} type
   * @return {stringlist}
   */
  static t_allowtypenames_from_type = {
    vx_type: vx_core.t_type
  }
  static e_allowtypenames_from_type = {
    vx_type: vx_type.t_allowtypenames_from_type
  }

  // (func allowtypenames<-type)
  static f_allowtypenames_from_type(type) {
    let output = vx_core.e_stringlist
    output = vx_core.f_typenames_from_typelist(
      vx_type.f_allowtypes_from_type(type)
    )
    return output
  }

  /**
   * @function allowtypes_from_type
   * Returns the allowed types from a given type
   * @param  {any} type
   * @return {typelist}
   */
  static t_allowtypes_from_type = {
    vx_type: vx_core.t_type
  }
  static e_allowtypes_from_type = {
    vx_type: vx_type.t_allowtypes_from_type
  }

  // (func allowtypes<-type)
  static f_allowtypes_from_type(type) {
    let output = vx_core.e_typelist
    output = vx_core.f_any_from_struct(
      {"any-1": vx_core.t_typelist, "struct-2": vx_core.t_typedef},
      vx_core.f_typedef_from_type(type),
      ":allowtypes"
    )
    return output
  }

  /**
   * @function any_from_int
   * Generic function returns any from an int.
   * @param  {typemap} generic
   * @param  {int} value
   * @return {any-1}
   */
  static t_any_from_int = {
    vx_type: vx_core.t_type
  }
  static e_any_from_int = {
    vx_type: vx_type.t_any_from_int
  }

  // (func any<-int)
  static f_any_from_int(generic, value) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    return output
  }

  /**
   * @function boolean_from_string_ends
   * Returns true if string starts with find.
   * @param  {string} text
   * @param  {string} ends
   * @return {boolean}
   */
  static t_boolean_from_string_ends = {
    vx_type: vx_core.t_type
  }
  static e_boolean_from_string_ends = {
    vx_type: vx_type.t_boolean_from_string_ends
  }

  // (func boolean<-string-ends)
  static f_boolean_from_string_ends(text, ends) {
    let output = vx_core.e_boolean
    output = vx_core.vx_boolean_from_string_ends(text, ends)
    return output
  }

  /**
   * @function boolean_from_string_starts
   * Returns true if string starts with find.
   * @param  {string} text
   * @param  {string} starts
   * @return {boolean}
   */
  static t_boolean_from_string_starts = {
    vx_type: vx_core.t_type
  }
  static e_boolean_from_string_starts = {
    vx_type: vx_type.t_boolean_from_string_starts
  }

  // (func boolean<-string-starts)
  static f_boolean_from_string_starts(text, starts) {
    let output = vx_core.e_boolean
    output = vx_type.vx_boolean_from_string_starts(text, starts)
    return output
  }

  /**
   * @function int_from_string_find
   * Returns integer position of find string in text string.
   * @param  {string} text
   * @param  {string} find
   * @return {int}
   */
  static t_int_from_string_find = {
    vx_type: vx_core.t_type
  }
  static e_int_from_string_find = {
    vx_type: vx_type.t_int_from_string_find
  }

  // (func int<-string-find)
  static f_int_from_string_find(text, find) {
    let output = vx_core.e_int
    output = vx_type.vx_int_from_string_find(text, find)
    return output
  }

  /**
   * @function int_from_string_findkeyword
   * Returns integer position of find string in text string. Note: the find terms :whitespace and :nonwhitespace have special meaning.
   * @param  {string} text
   * @param  {string} find
   * @return {int}
   */
  static t_int_from_string_findkeyword = {
    vx_type: vx_core.t_type
  }
  static e_int_from_string_findkeyword = {
    vx_type: vx_type.t_int_from_string_findkeyword
  }

  // (func int<-string-findkeyword)
  static f_int_from_string_findkeyword(text, find) {
    let output = vx_core.e_int
    output = vx_type.vx_int_from_string_findkeyword(text, find)
    return output
  }

  /**
   * @function int_from_string_findlast
   * Returns integer position of find string in text string.
   * @param  {string} text
   * @param  {string} findlast
   * @return {int}
   */
  static t_int_from_string_findlast = {
    vx_type: vx_core.t_type
  }
  static e_int_from_string_findlast = {
    vx_type: vx_type.t_int_from_string_findlast
  }

  // (func int<-string-findlast)
  static f_int_from_string_findlast(text, findlast) {
    let output = vx_core.e_int
    output = vx_type.vx_int_from_string_findlast(text, findlast)
    return output
  }

  /**
   * @function is_boolean
   * @param  {any} value
   * @return {boolean}
   */
  static t_is_boolean = {
    vx_type: vx_core.t_type
  }
  static e_is_boolean = {
    vx_type: vx_type.t_is_boolean
  }

  // (func is-boolean)
  static f_is_boolean(value) {
    let output = vx_core.e_boolean
    output = vx_core.f_eq(
      "boolean",
      vx_core.f_typename_from_any(value)
    )
    return output
  }

  /**
   * @function is_decimal
   * @param  {any} value
   * @return {boolean}
   */
  static t_is_decimal = {
    vx_type: vx_core.t_type
  }
  static e_is_decimal = {
    vx_type: vx_type.t_is_decimal
  }

  // (func is-decimal)
  static f_is_decimal(value) {
    let output = vx_core.e_boolean
    output = vx_core.f_eq(
      "decimal",
      vx_core.f_typename_from_any(value)
    )
    return output
  }

  /**
   * @function is_none
   * @param  {any} value
   * @return {boolean}
   */
  static t_is_none = {
    vx_type: vx_core.t_type
  }
  static e_is_none = {
    vx_type: vx_type.t_is_none
  }

  // (func is-none)
  static f_is_none(value) {
    let output = vx_core.e_boolean
    output = vx_core.f_eq(
      value,
      vx_core.t_none
    )
    return output
  }

  /**
   * @function is_string
   * @param  {any} value
   * @return {boolean}
   */
  static t_is_string = {
    vx_type: vx_core.t_type
  }
  static e_is_string = {
    vx_type: vx_type.t_is_string
  }

  // (func is-string)
  static f_is_string(value) {
    let output = vx_core.e_boolean
    output = vx_core.f_eq(
      "vx/core/string",
      vx_core.f_typename_from_any(value)
    )
    return output
  }

  /**
   * @function is_type
   * @param  {any} value
   * @param  {any} type
   * @return {boolean}
   */
  static t_is_type = {
    vx_type: vx_core.t_type
  }
  static e_is_type = {
    vx_type: vx_type.t_is_type
  }

  // (func is-type)
  static f_is_type(value, type) {
    let output = vx_core.e_boolean
    output = vx_core.f_or_1(
      vx_core.f_eq(
        vx_core.f_typename_from_type(type),
        vx_core.f_typename_from_any(value)
      ),
      vx_core.f_contains_1(
        vx_type.f_allowtypenames_from_type(type),
        vx_core.f_typename_from_any(value)
      ),
      vx_core.f_contains_1(
        vx_type.f_traitnames_from_any(value),
        vx_core.f_typename_from_type(type)
      )
    )
    return output
  }

  /**
   * @function is_type_from_any_typelist
   * Returns true if value is any type in typelist.
   * @param  {any} value
   * @param  {typelist} typelist
   * @return {boolean}
   */
  static t_is_type_from_any_typelist = {
    vx_type: vx_core.t_type
  }
  static e_is_type_from_any_typelist = {
    vx_type: vx_type.t_is_type_from_any_typelist
  }

  // (func is-type<-any-typelist)
  static f_is_type_from_any_typelist(value, typelist) {
    let output = vx_core.e_boolean
    output = vx_core.f_any_from_list_start_reduce(
      {"any-1": vx_core.t_boolean, "list-2": vx_core.t_typelist},
      typelist,
      false,
      vx_core.f_new(vx_core.t_any_from_reduce, (result, type) => 
        vx_core.f_or(
          result,
          vx_type.f_is_type(value, type)
        ))
    )
    return output
  }

  /**
   * @function string_lowercase
   * Returns lowercase version of string
   * @param  {string} text
   * @return {string}
   */
  static t_string_lowercase = {
    vx_type: vx_core.t_type
  }
  static e_string_lowercase = {
    vx_type: vx_type.t_string_lowercase
  }

  // (func string-lowercase)
  static f_string_lowercase(text) {
    let output = vx_core.e_string
    output = vx_type.vx_string_lowercase(text)
    return output
  }

  /**
   * @function string_outdent
   * Returns a string replacing leading whitespace on all lines based on first line.
   * @param  {string} text
   * @return {string}
   */
  static t_string_outdent = {
    vx_type: vx_core.t_type
  }
  static e_string_outdent = {
    vx_type: vx_type.t_string_outdent
  }

  // (func string-outdent)
  static f_string_outdent(text) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const pos = vx_type.f_int_from_string_findkeyword(text, ":nonwhitespace")
        return vx_core.f_if_2(
          {"any-1": vx_core.t_string},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq(0, pos)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return text})
          ),
          vx_core.f_else(
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_let(
              {"any-1": vx_core.t_string},
              [],
              vx_core.f_new(vx_core.t_any_from_func, () => {
                const indent = vx_type.f_string_from_string_end(
                  text,
                  vx_core.f_minus1(pos)
                )
                const rest = vx_type.f_string_from_string_start(text, pos)
                const linepos = vx_type.f_int_from_string_find(indent, "\n")
                const outdent = vx_core.f_if_1(
                  {"any-1": vx_core.t_string},
                  vx_core.f_eq(0, linepos),
                  "",
                  "\n"
                )
                return vx_core.f_string_from_string_find_replace(rest, indent, outdent)
              })
            )})
          )
        )
      })
    )
    return output
  }

  /**
   * @function string_trim
   * Trims whitespace from the front and back of text
   * @param  {string} text
   * @return {string}
   */
  static t_string_trim = {
    vx_type: vx_core.t_type
  }
  static e_string_trim = {
    vx_type: vx_type.t_string_trim
  }

  // (func string-trim)
  static f_string_trim(text) {
    let output = vx_core.e_string
    output = vx_type.vx_string_trim(text)
    return output
  }

  /**
   * @function string_uppercase
   * Returns uppercase version of string
   * @param  {string} text
   * @return {string}
   */
  static t_string_uppercase = {
    vx_type: vx_core.t_type
  }
  static e_string_uppercase = {
    vx_type: vx_type.t_string_uppercase
  }

  // (func string-uppercase)
  static f_string_uppercase(text) {
    let output = vx_core.e_string
    output = vx_type.vx_string_uppercase(text)
    return output
  }

  /**
   * @function string_from_int
   * Function Type converting int to string
   * @param  {int} value
   * @return {string}
   */
  static t_string_from_int = {
    vx_type: vx_core.t_type
  }
  static e_string_from_int = {
    vx_type: vx_type.t_string_from_int
  }

  // (func string<-int)
  static f_string_from_int(value) {
    let output = vx_core.e_string
    output = vx_core.f_switch(
      {"any-1": vx_core.t_string, "any-2": vx_core.t_int},
      value,
      vx_core.f_case_1(
        vx_core.c_infinity,
        vx_core.f_new(vx_core.t_any_from_func, () => {return "infinity"})
      ),
      vx_core.f_case_1(
        vx_core.c_neginfinity,
        vx_core.f_new(vx_core.t_any_from_func, () => {return "neginfinity"})
      ),
      vx_core.f_case_1(
        vx_core.c_notanumber,
        vx_core.f_new(vx_core.t_any_from_func, () => {return "notanumber"})
      ),
      vx_core.f_else(
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
          vx_core.t_string,
          value
        )})
      )
    )
    return output
  }

  /**
   * @function string_from_string_end
   * Returns a substring between 0 end position.
   * @param  {string} text
   * @param  {int} endpos
   * @return {string}
   */
  static t_string_from_string_end = {
    vx_type: vx_core.t_type
  }
  static e_string_from_string_end = {
    vx_type: vx_type.t_string_from_string_end
  }

  // (func string<-string-end)
  static f_string_from_string_end(text, endpos) {
    let output = vx_core.e_string
    output = vx_type.f_string_from_string_start_end(text, 1, endpos)
    return output
  }

  /**
   * @function string_from_string_start
   * Returns a substring between start string end.
   * @param  {string} text
   * @param  {int} startpos
   * @return {string}
   */
  static t_string_from_string_start = {
    vx_type: vx_core.t_type
  }
  static e_string_from_string_start = {
    vx_type: vx_type.t_string_from_string_start
  }

  // (func string<-string-start)
  static f_string_from_string_start(text, startpos) {
    let output = vx_core.e_string
    output = vx_type.f_string_from_string_start_end(
      text,
      startpos,
      vx_core.f_length(text)
    )
    return output
  }

  /**
   * @function string_from_string_start_end
   * Returns a substring between start and end positions.
   * @param  {string} text
   * @param  {int} start
   * @param  {int} end
   * @return {string}
   */
  static t_string_from_string_start_end = {
    vx_type: vx_core.t_type
  }
  static e_string_from_string_start_end = {
    vx_type: vx_type.t_string_from_string_start_end
  }

  // (func string<-string-start-end)
  static f_string_from_string_start_end(text, start, end) {
    let output = vx_core.e_string
    output = vx_core.vx_string_from_string_start_end(text, start, end)
    return output
  }

  /**
   * @function string_from_stringlist_join
   * Returns a string by joining a stringlist by the delimiter
   * @param  {stringlist} vals
   * @param  {string} delim
   * @return {string}
   */
  static t_string_from_stringlist_join = {
    vx_type: vx_core.t_type
  }
  static e_string_from_stringlist_join = {
    vx_type: vx_type.t_string_from_stringlist_join
  }

  // (func string<-stringlist-join)
  static f_string_from_stringlist_join(vals, delim) {
    let output = vx_core.e_string
    output = vx_type.vx_string_from_stringlist_join(vals, delim)
    return output
  }

  /**
   * @function stringlist_from_string_split
   * Returns a stringlist by splitting a string by the delimiter
   * @param  {string} text
   * @param  {string} delim
   * @return {stringlist}
   */
  static t_stringlist_from_string_split = {
    vx_type: vx_core.t_type
  }
  static e_stringlist_from_string_split = {
    vx_type: vx_type.t_stringlist_from_string_split
  }

  // (func stringlist<-string-split)
  static f_stringlist_from_string_split(text, delim) {
    let output = vx_core.e_stringlist
    output = vx_type.vx_stringlist_from_string_split(text, delim)
    return output
  }

  /**
   * @function traitnames_from_any
   * Get the trait names of a given type
   * @param  {any} value
   * @return {stringlist}
   */
  static t_traitnames_from_any = {
    vx_type: vx_core.t_type
  }
  static e_traitnames_from_any = {
    vx_type: vx_type.t_traitnames_from_any
  }

  // (func traitnames<-any)
  static f_traitnames_from_any(value) {
    let output = vx_core.e_stringlist
    output = vx_core.f_typenames_from_typelist(
      vx_type.f_traits_from_any(value)
    )
    return output
  }

  /**
   * @function traits_from_any
   * Get the traits of a given value
   * @param  {any} value
   * @return {typelist}
   */
  static t_traits_from_any = {
    vx_type: vx_core.t_type
  }
  static e_traits_from_any = {
    vx_type: vx_type.t_traits_from_any
  }

  // (func traits<-any)
  static f_traits_from_any(value) {
    let output = vx_core.e_typelist
    output = vx_core.f_traits_from_typedef(
      vx_core.f_typedef_from_any(value)
    )
    return output
  }

  /**
   * @function traits_from_typedef
   * Get the traits of a given typedef
   * @param  {typedef} vtypedef
   * @return {typelist}
   */
  static t_traits_from_typedef = {
    vx_type: vx_core.t_type
  }
  static e_traits_from_typedef = {
    vx_type: vx_type.t_traits_from_typedef
  }

  // (func traits<-typedef)
  static f_traits_from_typedef(vtypedef) {
    let output = vx_core.e_typelist
    output = vx_core.f_any_from_struct({"any-1": vx_core.t_typelist, "struct-2": vx_core.t_typedef}, vtypedef, ":traits")
    return output
  }



  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "allowtypenames<-type": vx_type.e_allowtypenames_from_type,
      "allowtypes<-type": vx_type.e_allowtypes_from_type,
      "any<-int": vx_type.e_any_from_int,
      "boolean<-string-ends": vx_type.e_boolean_from_string_ends,
      "boolean<-string-starts": vx_type.e_boolean_from_string_starts,
      "int<-string-find": vx_type.e_int_from_string_find,
      "int<-string-findkeyword": vx_type.e_int_from_string_findkeyword,
      "int<-string-findlast": vx_type.e_int_from_string_findlast,
      "is-boolean": vx_type.e_is_boolean,
      "is-decimal": vx_type.e_is_decimal,
      "is-none": vx_type.e_is_none,
      "is-string": vx_type.e_is_string,
      "is-type": vx_type.e_is_type,
      "is-type<-any-typelist": vx_type.e_is_type_from_any_typelist,
      "string-lowercase": vx_type.e_string_lowercase,
      "string-outdent": vx_type.e_string_outdent,
      "string-trim": vx_type.e_string_trim,
      "string-uppercase": vx_type.e_string_uppercase,
      "string<-int": vx_type.e_string_from_int,
      "string<-string-end": vx_type.e_string_from_string_end,
      "string<-string-start": vx_type.e_string_from_string_start,
      "string<-string-start-end": vx_type.e_string_from_string_start_end,
      "string<-stringlist-join": vx_type.e_string_from_stringlist_join,
      "stringlist<-string-split": vx_type.e_stringlist_from_string_split,
      "traitnames<-any": vx_type.e_traitnames_from_any,
      "traits<-any": vx_type.e_traits_from_any,
      "traits<-typedef": vx_type.e_traits_from_typedef
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "allowtypenames<-type": vx_type.t_allowtypenames_from_type,
      "allowtypes<-type": vx_type.t_allowtypes_from_type,
      "any<-int": vx_type.t_any_from_int,
      "boolean<-string-ends": vx_type.t_boolean_from_string_ends,
      "boolean<-string-starts": vx_type.t_boolean_from_string_starts,
      "int<-string-find": vx_type.t_int_from_string_find,
      "int<-string-findkeyword": vx_type.t_int_from_string_findkeyword,
      "int<-string-findlast": vx_type.t_int_from_string_findlast,
      "is-boolean": vx_type.t_is_boolean,
      "is-decimal": vx_type.t_is_decimal,
      "is-none": vx_type.t_is_none,
      "is-string": vx_type.t_is_string,
      "is-type": vx_type.t_is_type,
      "is-type<-any-typelist": vx_type.t_is_type_from_any_typelist,
      "string-lowercase": vx_type.t_string_lowercase,
      "string-outdent": vx_type.t_string_outdent,
      "string-trim": vx_type.t_string_trim,
      "string-uppercase": vx_type.t_string_uppercase,
      "string<-int": vx_type.t_string_from_int,
      "string<-string-end": vx_type.t_string_from_string_end,
      "string<-string-start": vx_type.t_string_from_string_start,
      "string<-string-start-end": vx_type.t_string_from_string_start_end,
      "string<-stringlist-join": vx_type.t_string_from_stringlist_join,
      "stringlist<-string-split": vx_type.t_stringlist_from_string_split,
      "traitnames<-any": vx_type.t_traitnames_from_any,
      "traits<-any": vx_type.t_traits_from_any,
      "traits<-typedef": vx_type.t_traits_from_typedef
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      
    })
    const pkg = vx_core.vx_new_struct(vx_core.t_package, {
      "name": "vx/type",
      "constmap": constmap,
      "emptymap": emptymap,
      "funcmap": funcmap,
      "typemap": typemap
    })
    vx_core.vx_global_package_set(pkg)

    // (func allowtypenames<-type)
    vx_type.t_allowtypenames_from_type['vx_value'] = {
      name          : "allowtypenames<-type",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_allowtypenames_from_type
    }

    // (func allowtypes<-type)
    vx_type.t_allowtypes_from_type['vx_value'] = {
      name          : "allowtypes<-type",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_allowtypes_from_type
    }

    // (func any<-int)
    vx_type.t_any_from_int['vx_value'] = {
      name          : "any<-int",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_any_from_int
    }

    // (func boolean<-string-ends)
    vx_type.t_boolean_from_string_ends['vx_value'] = {
      name          : "boolean<-string-ends",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_boolean_from_string_ends
    }

    // (func boolean<-string-starts)
    vx_type.t_boolean_from_string_starts['vx_value'] = {
      name          : "boolean<-string-starts",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_boolean_from_string_starts
    }

    // (func int<-string-find)
    vx_type.t_int_from_string_find['vx_value'] = {
      name          : "int<-string-find",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_int_from_string_find
    }

    // (func int<-string-findkeyword)
    vx_type.t_int_from_string_findkeyword['vx_value'] = {
      name          : "int<-string-findkeyword",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_int_from_string_findkeyword
    }

    // (func int<-string-findlast)
    vx_type.t_int_from_string_findlast['vx_value'] = {
      name          : "int<-string-findlast",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_int_from_string_findlast
    }

    // (func is-boolean)
    vx_type.t_is_boolean['vx_value'] = {
      name          : "is-boolean",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_is_boolean
    }

    // (func is-decimal)
    vx_type.t_is_decimal['vx_value'] = {
      name          : "is-decimal",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_is_decimal
    }

    // (func is-none)
    vx_type.t_is_none['vx_value'] = {
      name          : "is-none",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_is_none
    }

    // (func is-string)
    vx_type.t_is_string['vx_value'] = {
      name          : "is-string",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_is_string
    }

    // (func is-type)
    vx_type.t_is_type['vx_value'] = {
      name          : "is-type",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_is_type
    }

    // (func is-type<-any-typelist)
    vx_type.t_is_type_from_any_typelist['vx_value'] = {
      name          : "is-type<-any-typelist",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_is_type_from_any_typelist
    }

    // (func string-lowercase)
    vx_type.t_string_lowercase['vx_value'] = {
      name          : "string-lowercase",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_string_lowercase
    }

    // (func string-outdent)
    vx_type.t_string_outdent['vx_value'] = {
      name          : "string-outdent",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_string_outdent
    }

    // (func string-trim)
    vx_type.t_string_trim['vx_value'] = {
      name          : "string-trim",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_string_trim
    }

    // (func string-uppercase)
    vx_type.t_string_uppercase['vx_value'] = {
      name          : "string-uppercase",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_string_uppercase
    }

    // (func string<-int)
    vx_type.t_string_from_int['vx_value'] = {
      name          : "string<-int",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_string_from_int
    }

    // (func string<-string-end)
    vx_type.t_string_from_string_end['vx_value'] = {
      name          : "string<-string-end",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_string_from_string_end
    }

    // (func string<-string-start)
    vx_type.t_string_from_string_start['vx_value'] = {
      name          : "string<-string-start",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_string_from_string_start
    }

    // (func string<-string-start-end)
    vx_type.t_string_from_string_start_end['vx_value'] = {
      name          : "string<-string-start-end",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_string_from_string_start_end
    }

    // (func string<-stringlist-join)
    vx_type.t_string_from_stringlist_join['vx_value'] = {
      name          : "string<-stringlist-join",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_string_from_stringlist_join
    }

    // (func stringlist<-string-split)
    vx_type.t_stringlist_from_string_split['vx_value'] = {
      name          : "stringlist<-string-split",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_stringlist_from_string_split
    }

    // (func traitnames<-any)
    vx_type.t_traitnames_from_any['vx_value'] = {
      name          : "traitnames<-any",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_traitnames_from_any
    }

    // (func traits<-any)
    vx_type.t_traits_from_any['vx_value'] = {
      name          : "traits<-any",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_traits_from_any
    }

    // (func traits<-typedef)
    vx_type.t_traits_from_typedef['vx_value'] = {
      name          : "traits<-typedef",
      pkgname       : "vx/type",
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
      fn            : vx_type.f_traits_from_typedef
    }

  }
}
