'strict mode'

import vx_core from "../vx/core.js"
import vx_data_textblock from "../vx/data/textblock.js"

export default class vx_repl {

  /**
   * type: liblist
   * List of library names
   */
  static t_liblist = {}

  /**
   * type: repl
   * Repl structure
   */
  static t_repl = {}

  /**
   * type: repllist
   * List of repl
   */
  static t_repllist = {}
  /**
   * @function any_repl_from_functype_args
   * Returns any from a repl func and args.
   * @param  {any} type
   * @param  {anylist} args
   * @return {any}
   */
  static t_any_repl_from_functype_args = {}
  static e_any_repl_from_functype_args = {vx_type: vx_repl.t_any_repl_from_functype_args}

  static f_any_repl_from_functype_args(type, args) {
    let output = vx_core.e_any
    const vxvalue = type['vx_value']
    if (vxvalue != undefined) {
      const fn = vxvalue['fn']
      if (fn != undefined) {
        output = fn(...args)
      }
    }
    return output
  }

  /**
   * @function any_from_liblist_string
   * Run an arbitrary program in the REPL.
   * @param  {liblist} liblist
   * @param  {string} text Program to run
   * @return {any}
   */
  static t_any_from_liblist_string = {}
  static e_any_from_liblist_string = {vx_type: vx_repl.t_any_from_liblist_string}

  static f_any_from_liblist_string(liblist, text, context) {
    let output = vx_core.e_any
    output = vx_core.f_let(
      {"any-1": vx_core.t_any},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const repl = vx_repl.f_repl_from_liblist_string(liblist, text)
        return vx_repl.f_any_from_repl(repl, context)
      })
    )
    return output
  }

  /**
   * 
   * @async @function any_from_liblist_string_async
   * Run an arbitrary program in the REPL asynchrously.
   * @param  {liblist} liblist
   * @param  {string} text Program to run
   * @return {any}
   */
  static t_any_from_liblist_string_async = {}
  static e_any_from_liblist_string_async = {vx_type: vx_repl.t_any_from_liblist_string_async}

  static async f_any_from_liblist_string_async(liblist, text, context) {
    let output = Promise.resolve(vx_core.e_any)
    output = await vx_core.f_let_async(
      {"any-1": vx_core.t_any},
      [],
      vx_core.f_new(vx_core.t_any_from_func, async () => {
        const repl = vx_repl.f_repl_from_liblist_string(liblist, text)
        const val = await vx_repl.f_any_from_repl_async(repl, context)
        return val
      })
    )
    return output
  }

  /**
   * @function any_from_repl
   * Run an arbitrary program in the REPL.
   * @param  {repl} repl
   * @return {any}
   */
  static t_any_from_repl = {}
  static e_any_from_repl = {vx_type: vx_repl.t_any_from_repl}

  static f_any_from_repl(repl, context) {
    let output = vx_core.e_any
    output = vx_core.f_let(
      {"any-1": vx_core.t_any},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const val = vx_core.f_any_from_struct({"any-1": vx_core.t_any, "struct-1": vx_repl.t_repl}, repl, ":val")
        const repltype = vx_core.f_any_from_struct({"any-1": vx_core.t_any, "struct-1": vx_repl.t_repl}, repl, ":type")
        const repllist = vx_core.f_any_from_struct({"any-1": vx_repl.t_repllist, "struct-1": vx_repl.t_repl}, repl, ":repllist")
        const args = vx_repl.f_anylist_from_repllist(repllist, context)
        return vx_core.f_if_2(
          {"any-1": vx_core.t_any},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_notempty_1(val)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return val})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_func(repltype)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_repl.f_any_repl_from_functype_args(repltype, args)})
          ),
          vx_core.f_else(
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(repltype, args)})
          )
        )
      })
    )
    return output
  }

  /**
   * 
   * @async @function any_from_repl_async
   * Run an arbitrary program in the REPL.
   * @param  {repl} repl
   * @return {any}
   */
  static t_any_from_repl_async = {}
  static e_any_from_repl_async = {vx_type: vx_repl.t_any_from_repl_async}

  static async f_any_from_repl_async(repl, context) {
    let output = Promise.resolve(vx_core.e_any)
    return output
  }

  /**
   * @function anylist_from_repllist
   * Run an arbitrary program in the REPL.
   * @param  {repllist} repllist
   * @return {anylist}
   */
  static t_anylist_from_repllist = {}
  static e_anylist_from_repllist = {vx_type: vx_repl.t_anylist_from_repllist}

  static f_anylist_from_repllist(repllist, context) {
    let output = vx_core.e_anylist
    output = vx_core.f_list_from_list(
      {"any-1": vx_core.t_any, "any-2": vx_repl.t_repl, "list-1": vx_core.t_anylist, "list-2": vx_repl.t_repllist},
      repllist,
      vx_core.f_new(vx_core.t_any_from_any, (repl) => 
        vx_repl.f_any_from_repl(repl, context))
    )
    return output
  }

  /**
   * @function macro
   * A function that joins any number of values into a string and then parses and evaluates it.
   * @param  {typemap} generic
   * @param  {anylist} ... anylist
   * @return {any-1}
   */
  static t_macro = {}
  static e_macro = {vx_type: vx_repl.t_macro}

  static f_macro(generic, ...anylist) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    anylist = vx_core.f_new(vx_core.t_anylist, ...anylist)
    return output
  }

  /**
   * @function repl_from_liblist_string
   * Returns a repl from the given text.
   * @param  {liblist} liblist
   * @param  {string} text Program to run
   * @return {repl}
   */
  static t_repl_from_liblist_string = {}
  static e_repl_from_liblist_string = {vx_type: vx_repl.t_repl_from_liblist_string}

  static f_repl_from_liblist_string(liblist, text) {
    let output = vx_repl.e_repl
    return output
  }

  // empty types
  static e_liblist = []
  static e_repl = {}
  static e_repllist = []

  static c_empty = {
    "liblist": vx_repl.e_liblist,
    "repl": vx_repl.e_repl,
    "repllist": vx_repl.e_repllist,
    "any-repl<-functype-args": vx_repl.e_any_repl_from_functype_args,
    "any<-liblist-string": vx_repl.e_any_from_liblist_string,
    "any<-liblist-string-async": vx_repl.e_any_from_liblist_string_async,
    "any<-repl": vx_repl.e_any_from_repl,
    "any<-repl-async": vx_repl.e_any_from_repl_async,
    "anylist<-repllist": vx_repl.e_anylist_from_repllist,
    "macro": vx_repl.e_macro,
    "repl<-liblist-string": vx_repl.e_repl_from_liblist_string
  }


  static {
    vx_core.f_global_package_set("vx/repl", vx_repl)

    // (type liblist)
    vx_repl.t_liblist['vx_type'] = vx_core.t_type
    vx_repl.t_liblist['vx_value'] = {
      name          : "liblist",
      pkgname       : "vx/repl",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_string],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_repl.e_liblist['vx_type'] = vx_repl.t_liblist

    // (type repl)
    vx_repl.t_repl['vx_type'] = vx_core.t_type
    vx_repl.t_repl['vx_value'] = {
      name          : "repl",
      pkgname       : "vx/repl",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "type": {
          "name" : "type",
          "type" : vx_core.t_any,
          "multi": false
        },
        "repllist": {
          "name" : "repllist",
          "type" : vx_repl.t_repllist,
          "multi": false
        },
        "async": {
          "name" : "async",
          "type" : vx_core.t_boolean,
          "multi": false
        },
        "val": {
          "name" : "val",
          "type" : vx_core.t_any,
          "multi": false
        }
      },
      proplast      : {
        "name" : "val",
        "type" : vx_core.t_any,
        "multi": false
      }
    }
    vx_repl.e_repl['vx_type'] = vx_repl.t_repl
    vx_repl.e_repl['vx_value'] = {}

    // (type repllist)
    vx_repl.t_repllist['vx_type'] = vx_core.t_type
    vx_repl.t_repllist['vx_value'] = {
      name          : "repllist",
      pkgname       : "vx/repl",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_repl.t_repl],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_repl.e_repllist['vx_type'] = vx_repl.t_repllist

    // (func any_repl_from_functype_args)
    vx_repl.t_any_repl_from_functype_args['vx_type'] = vx_core.t_type
    vx_repl.t_any_repl_from_functype_args['vx_value'] = {
      name          : "any-repl<-functype-args",
      pkgname       : "vx/repl",
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
      fn            : vx_repl.f_any_repl_from_functype_args
    }

    // (func any_from_liblist_string)
    vx_repl.t_any_from_liblist_string['vx_type'] = vx_core.t_type
    vx_repl.t_any_from_liblist_string['vx_value'] = {
      name          : "any<-liblist-string",
      pkgname       : "vx/repl",
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
      fn            : vx_repl.f_any_from_liblist_string
    }

    // (func any_from_liblist_string_async)
    vx_repl.t_any_from_liblist_string_async['vx_type'] = vx_core.t_type
    vx_repl.t_any_from_liblist_string_async['vx_value'] = {
      name          : "any<-liblist-string-async",
      pkgname       : "vx/repl",
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
      fn            : vx_repl.f_any_from_liblist_string_async
    }

    // (func any_from_repl)
    vx_repl.t_any_from_repl['vx_type'] = vx_core.t_type
    vx_repl.t_any_from_repl['vx_value'] = {
      name          : "any<-repl",
      pkgname       : "vx/repl",
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
      fn            : vx_repl.f_any_from_repl
    }

    // (func any_from_repl_async)
    vx_repl.t_any_from_repl_async['vx_type'] = vx_core.t_type
    vx_repl.t_any_from_repl_async['vx_value'] = {
      name          : "any<-repl-async",
      pkgname       : "vx/repl",
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
      fn            : vx_repl.f_any_from_repl_async
    }

    // (func anylist_from_repllist)
    vx_repl.t_anylist_from_repllist['vx_type'] = vx_core.t_type
    vx_repl.t_anylist_from_repllist['vx_value'] = {
      name          : "anylist<-repllist",
      pkgname       : "vx/repl",
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
      fn            : vx_repl.f_anylist_from_repllist
    }

    // (func macro)
    vx_repl.t_macro['vx_type'] = vx_core.t_type
    vx_repl.t_macro['vx_value'] = {
      name          : "macro",
      pkgname       : "vx/repl",
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
      fn            : vx_repl.f_macro
    }

    // (func repl_from_liblist_string)
    vx_repl.t_repl_from_liblist_string['vx_type'] = vx_core.t_type
    vx_repl.t_repl_from_liblist_string['vx_value'] = {
      name          : "repl<-liblist-string",
      pkgname       : "vx/repl",
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
      fn            : vx_repl.f_repl_from_liblist_string
    }

  }
}
