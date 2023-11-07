'strict mode'

import vx_core from "../vx/core.js"

export default class vx_type {

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
  static t_allowtypenames_from_type = {}
  static e_allowtypenames_from_type = {vx_type: vx_type.t_allowtypenames_from_type}

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
  static t_allowtypes_from_type = {}
  static e_allowtypes_from_type = {vx_type: vx_type.t_allowtypes_from_type}

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
   * @param  {int} val
   * @return {any-1}
   */
  static t_any_from_int = {}
  static e_any_from_int = {vx_type: vx_type.t_any_from_int}

  static f_any_from_int(generic, val) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    return output
  }

  /**
   * @function int_from_string_find
   * Returns integer position of find string in text string.
   * @param  {string} text
   * @param  {string} find
   * @return {int}
   */
  static t_int_from_string_find = {}
  static e_int_from_string_find = {vx_type: vx_type.t_int_from_string_find}

  static f_int_from_string_find(text, find) {
    let output = vx_core.e_int
    output = text.indexOf(find)
    return output
  }

  /**
   * @function int_from_string_findkeyword
   * Returns integer position of find string in text string. Note: the find terms :whitespace and :nonwhitespace have special meaning.
   * @param  {string} text
   * @param  {string} find
   * @return {int}
   */
  static t_int_from_string_findkeyword = {}
  static e_int_from_string_findkeyword = {vx_type: vx_type.t_int_from_string_findkeyword}

  static f_int_from_string_findkeyword(text, find) {
    let output = vx_core.e_int
    output = vx_type.vx_int_from_string_findkeyword(text, find)
    return output
  }

  /**
   * @function is_boolean
   * @param  {any} value
   * @return {boolean}
   */
  static t_is_boolean = {}
  static e_is_boolean = {vx_type: vx_type.t_is_boolean}

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
  static t_is_decimal = {}
  static e_is_decimal = {vx_type: vx_type.t_is_decimal}

  static f_is_decimal(value) {
    let output = vx_core.e_boolean
    output = vx_core.f_eq(
      "decimal",
      vx_core.f_typename_from_any(value)
    )
    return output
  }

  /**
   * @function is_float
   * @param  {any} value
   * @return {boolean}
   */
  static t_is_float = {}
  static e_is_float = {vx_type: vx_type.t_is_float}

  static f_is_float(value) {
    let output = vx_core.e_boolean
    output = vx_core.f_eq(
      "float",
      vx_core.f_typename_from_any(value)
    )
    return output
  }

  /**
   * @function is_none
   * @param  {any} value
   * @return {boolean}
   */
  static t_is_none = {}
  static e_is_none = {vx_type: vx_type.t_is_none}

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
  static t_is_string = {}
  static e_is_string = {vx_type: vx_type.t_is_string}

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
   * @param  {any} val
   * @param  {any} type
   * @return {boolean}
   */
  static t_is_type = {}
  static e_is_type = {vx_type: vx_type.t_is_type}

  static f_is_type(val, type) {
    let output = vx_core.e_boolean
    output = vx_core.f_or_1(
      vx_core.f_eq(
        vx_core.f_typename_from_type(type),
        vx_core.f_typename_from_any(val)
      ),
      vx_core.f_contains_1(
        vx_type.f_allowtypenames_from_type(type),
        vx_core.f_typename_from_any(val)
      ),
      vx_core.f_contains_1(
        vx_type.f_traitnames_from_any(val),
        vx_core.f_typename_from_type(type)
      )
    )
    return output
  }

  /**
   * @function is_type_from_any_typelist
   * Returns true if val is any type in typelist.
   * @param  {any} val
   * @param  {typelist} typelist
   * @return {boolean}
   */
  static t_is_type_from_any_typelist = {}
  static e_is_type_from_any_typelist = {vx_type: vx_type.t_is_type_from_any_typelist}

  static f_is_type_from_any_typelist(val, typelist) {
    let output = vx_core.e_boolean
    output = vx_core.f_any_from_list_reduce(
      {"any-1": vx_core.t_boolean, "any-2": vx_core.t_any, "list-2": vx_core.t_typelist},
      typelist,
      false,
      vx_core.f_new(vx_core.t_any_from_reduce, (result, type) => 
        vx_core.f_or(
          result,
          vx_type.f_is_type(val, type)
        ))
    )
    return output
  }

  /**
   * @function length_from_string
   * Returns length of a string.
   * @param  {string} text
   * @return {int}
   */
  static t_length_from_string = {}
  static e_length_from_string = {vx_type: vx_type.t_length_from_string}

  static f_length_from_string(text) {
    let output = vx_core.e_int
    output = text.length
    return output
  }

  /**
   * @function string_from_int
   * Function Type converting int to string
   * @param  {int} val
   * @return {string}
   */
  static t_string_from_int = {}
  static e_string_from_int = {vx_type: vx_type.t_string_from_int}

  static f_string_from_int(val) {
    let output = vx_core.e_string
    output = vx_core.f_switch(
      {"any-1": vx_core.t_string, "any-2": vx_core.t_int},
      val,
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
          val
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
  static t_string_from_string_end = {}
  static e_string_from_string_end = {vx_type: vx_type.t_string_from_string_end}

  static f_string_from_string_end(text, endpos) {
    let output = vx_core.e_string
    output = vx_type.f_string_from_string_start_end(text, 0, endpos)
    return output
  }

  /**
   * @function string_from_string_start
   * Returns a substring between start string end.
   * @param  {string} text
   * @param  {int} startpos
   * @return {string}
   */
  static t_string_from_string_start = {}
  static e_string_from_string_start = {vx_type: vx_type.t_string_from_string_start}

  static f_string_from_string_start(text, startpos) {
    let output = vx_core.e_string
    output = vx_type.f_string_from_string_start_end(
      text,
      startpos,
      vx_type.f_length_from_string(text)
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
  static t_string_from_string_start_end = {}
  static e_string_from_string_start_end = {vx_type: vx_type.t_string_from_string_start_end}

  static f_string_from_string_start_end(text, start, end) {
    let output = vx_core.e_string
    output = text.substring(start, end)
    return output
  }

  /**
   * @function string_from_stringlist_join
   * Returns a string by joining a stringlist by the delimiter
   * @param  {stringlist} vals
   * @param  {string} delim
   * @return {string}
   */
  static t_string_from_stringlist_join = {}
  static e_string_from_stringlist_join = {vx_type: vx_type.t_string_from_stringlist_join}

  static f_string_from_stringlist_join(vals, delim) {
    let output = vx_core.e_string
    output = vals.join(delim)
    return output
  }

  /**
   * @function stringlist_from_string_split
   * Returns a stringlist by splitting a string by the delimiter
   * @param  {string} text
   * @param  {string} delim
   * @return {stringlist}
   */
  static t_stringlist_from_string_split = {}
  static e_stringlist_from_string_split = {vx_type: vx_type.t_stringlist_from_string_split}

  static f_stringlist_from_string_split(text, delim) {
    let output = vx_core.e_stringlist
    output = vx_type.vx_stringlist_from_string_split(text, delim)
    return output
  }

  /**
   * @function traitnames_from_any
   * Get the trait names of a given type
   * @param  {any} val
   * @return {stringlist}
   */
  static t_traitnames_from_any = {}
  static e_traitnames_from_any = {vx_type: vx_type.t_traitnames_from_any}

  static f_traitnames_from_any(val) {
    let output = vx_core.e_stringlist
    output = vx_core.f_typenames_from_typelist(
      vx_type.f_traits_from_any(val)
    )
    return output
  }

  /**
   * @function traits_from_any
   * Get the traits of a given value
   * @param  {any} val
   * @return {typelist}
   */
  static t_traits_from_any = {}
  static e_traits_from_any = {vx_type: vx_type.t_traits_from_any}

  static f_traits_from_any(val) {
    let output = vx_core.e_typelist
    output = vx_core.f_traits_from_typedef(
      vx_core.f_typedef_from_any(val)
    )
    return output
  }

  /**
   * @function traits_from_typedef
   * Get the traits of a given typedef
   * @param  {typedef} vtypedef
   * @return {typelist}
   */
  static t_traits_from_typedef = {}
  static e_traits_from_typedef = {vx_type: vx_type.t_traits_from_typedef}

  static f_traits_from_typedef(vtypedef) {
    let output = vx_core.e_typelist
    output = vx_core.f_any_from_struct({"any-1": vx_core.t_typelist, "struct-2": vx_core.t_typedef}, vtypedef, ":traits")
    return output
  }

  // empty types

  static c_empty = {
    "allowtypenames<-type": vx_type.e_allowtypenames_from_type,
    "allowtypes<-type": vx_type.e_allowtypes_from_type,
    "any<-int": vx_type.e_any_from_int,
    "int<-string-find": vx_type.e_int_from_string_find,
    "int<-string-findkeyword": vx_type.e_int_from_string_findkeyword,
    "is-boolean": vx_type.e_is_boolean,
    "is-decimal": vx_type.e_is_decimal,
    "is-float": vx_type.e_is_float,
    "is-none": vx_type.e_is_none,
    "is-string": vx_type.e_is_string,
    "is-type": vx_type.e_is_type,
    "is-type<-any-typelist": vx_type.e_is_type_from_any_typelist,
    "length<-string": vx_type.e_length_from_string,
    "string<-int": vx_type.e_string_from_int,
    "string<-string-end": vx_type.e_string_from_string_end,
    "string<-string-start": vx_type.e_string_from_string_start,
    "string<-string-start-end": vx_type.e_string_from_string_start_end,
    "string<-stringlist-join": vx_type.e_string_from_stringlist_join,
    "stringlist<-string-split": vx_type.e_stringlist_from_string_split,
    "traitnames<-any": vx_type.e_traitnames_from_any,
    "traits<-any": vx_type.e_traits_from_any,
    "traits<-typedef": vx_type.e_traits_from_typedef
  }


  static {
    vx_core.f_global_package_set("vx/type", vx_type)

    // (func allowtypenames_from_type)
    vx_type.t_allowtypenames_from_type['vx_type'] = vx_core.t_type
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

    // (func allowtypes_from_type)
    vx_type.t_allowtypes_from_type['vx_type'] = vx_core.t_type
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

    // (func any_from_int)
    vx_type.t_any_from_int['vx_type'] = vx_core.t_type
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

    // (func int_from_string_find)
    vx_type.t_int_from_string_find['vx_type'] = vx_core.t_type
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

    // (func int_from_string_findkeyword)
    vx_type.t_int_from_string_findkeyword['vx_type'] = vx_core.t_type
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

    // (func is_boolean)
    vx_type.t_is_boolean['vx_type'] = vx_core.t_type
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

    // (func is_decimal)
    vx_type.t_is_decimal['vx_type'] = vx_core.t_type
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

    // (func is_float)
    vx_type.t_is_float['vx_type'] = vx_core.t_type
    vx_type.t_is_float['vx_value'] = {
      name          : "is-float",
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
      fn            : vx_type.f_is_float
    }

    // (func is_none)
    vx_type.t_is_none['vx_type'] = vx_core.t_type
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

    // (func is_string)
    vx_type.t_is_string['vx_type'] = vx_core.t_type
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

    // (func is_type)
    vx_type.t_is_type['vx_type'] = vx_core.t_type
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

    // (func is_type_from_any_typelist)
    vx_type.t_is_type_from_any_typelist['vx_type'] = vx_core.t_type
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

    // (func length_from_string)
    vx_type.t_length_from_string['vx_type'] = vx_core.t_type
    vx_type.t_length_from_string['vx_value'] = {
      name          : "length<-string",
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
      fn            : vx_type.f_length_from_string
    }

    // (func string_from_int)
    vx_type.t_string_from_int['vx_type'] = vx_core.t_type
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

    // (func string_from_string_end)
    vx_type.t_string_from_string_end['vx_type'] = vx_core.t_type
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

    // (func string_from_string_start)
    vx_type.t_string_from_string_start['vx_type'] = vx_core.t_type
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

    // (func string_from_string_start_end)
    vx_type.t_string_from_string_start_end['vx_type'] = vx_core.t_type
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

    // (func string_from_stringlist_join)
    vx_type.t_string_from_stringlist_join['vx_type'] = vx_core.t_type
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

    // (func stringlist_from_string_split)
    vx_type.t_stringlist_from_string_split['vx_type'] = vx_core.t_type
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

    // (func traitnames_from_any)
    vx_type.t_traitnames_from_any['vx_type'] = vx_core.t_type
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

    // (func traits_from_any)
    vx_type.t_traits_from_any['vx_type'] = vx_core.t_type
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

    // (func traits_from_typedef)
    vx_type.t_traits_from_typedef['vx_type'] = vx_core.t_type
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
