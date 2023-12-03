'strict mode'

import vx_core from "../vx/core.js"
import vx_type from "../vx/type.js"
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
   * Constant: delimvxlisp
   * vxlisp File Delimiters
   * {delim}
   */
  static c_delimvxlisp = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/repl', name: 'delimvxlisp'}}

  /**
   * Constant: delimvxlispbracket
   * vxlisp Square Bracket Delimiters
   * {delim}
   */
  static c_delimvxlispbracket = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/repl', name: 'delimvxlispbracket'}}

  /**
   * Constant: delimvxlispparen
   * vxlisp Paren Delimiters
   * {delim}
   */
  static c_delimvxlispparen = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/repl', name: 'delimvxlispparen'}}

  /**
   * @function any_repl_from_functype_args
   * Returns any from a repl func and args.
   * @param  {any} type
   * @param  {anylist} args
   * @return {any}
   */
  static t_any_repl_from_functype_args = {}
  static e_any_repl_from_functype_args = {vx_type: vx_repl.t_any_repl_from_functype_args}

  // (func any-repl<-functype-args)
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

  // (func any<-liblist-string)
  static f_any_from_liblist_string(context, liblist, text) {
    let output = vx_core.e_any
    output = vx_core.f_let(
      {"any-1": vx_core.t_any},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const repl = vx_repl.f_repl_from_liblist_string(liblist, text)
        return vx_repl.f_any_from_repl(context, repl)
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

  // (func any<-repl)
  static f_any_from_repl(context, repl) {
    let output = vx_core.e_any
    output = vx_core.f_let(
      {"any-1": vx_core.t_any},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const val = vx_core.f_any_from_struct({"any-1": vx_core.t_any, "struct-2": vx_repl.t_repl}, repl, ":val")
        const repltype = vx_core.f_any_from_struct({"any-1": vx_core.t_any, "struct-2": vx_repl.t_repl}, repl, ":type")
        const repllist = vx_core.f_any_from_struct({"any-1": vx_repl.t_repllist, "struct-2": vx_repl.t_repl}, repl, ":repllist")
        const args = vx_repl.f_anylist_from_repllist(context, repllist)
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
   * @function any_from_script
   * Run an arbitrary script.
   * @param  {string} script
   * @return {any}
   */
  static t_any_from_script = {}
  static e_any_from_script = {vx_type: vx_repl.t_any_from_script}

  // (func any<-script)
  static f_any_from_script(context, script) {
    let output = vx_core.e_any
    output = vx_core.f_let(
      {"any-1": vx_core.t_any},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const textblock = vx_repl.f_textblock_repl_from_script(script)
        const repl = vx_repl.f_repl_from_textblock(textblock)
        return vx_repl.f_any_from_repl(context, repl)
      })
    )
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

  // (func anylist<-repllist)
  static f_anylist_from_repllist(context, repllist) {
    let output = vx_core.e_anylist
    output = vx_core.f_list_from_list(
      {"any-1": vx_core.t_any, "any-2": vx_repl.t_repl, "list-1": vx_core.t_anylist, "list-2": vx_repl.t_repllist},
      repllist,
      vx_core.f_new(vx_core.t_any_from_any, (repl) => 
        vx_repl.f_any_from_repl(context, repl))
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

  // (func macro)
  static f_macro(generic, context, ...anylist) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    anylist = vx_core.f_new(vx_core.t_anylist, ...anylist)
    output = vx_core.f_let(
      {"any-1": vx_core.t_any, "any-2": vx_core.t_any},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const textlist = vx_core.f_list_from_list(
          {"any-1": vx_core.t_string, "any-2": vx_core.t_any, "list-1": vx_core.t_stringlist, "list-2": vx_core.t_anylist},
          anylist,
          vx_core.f_new(vx_core.t_any_from_any, (item) => 
            vx_core.f_string_from_any(item))
        )
        const script = vx_type.f_string_from_stringlist_join(textlist, "")
        const tb = vx_repl.f_textblock_repl_from_script(script)
        const repl = vx_repl.f_repl_from_textblock(tb)
        return vx_core.f_any_from_any(
          {"any-1": vx_core.t_any, "any-2": vx_core.t_any},
          vx_repl.f_any_from_repl(context, repl)
        )
      })
    )
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

  // (func repl<-liblist-string)
  static f_repl_from_liblist_string(liblist, text) {
    let output = vx_repl.e_repl
    return output
  }

  /**
   * @function repl_from_textblock
   * Returns a parsed repl from a parsed textblock
   * @param  {} textblock
   * @return {repl}
   */
  static t_repl_from_textblock = {}
  static e_repl_from_textblock = {vx_type: vx_repl.t_repl_from_textblock}

  // (func repl<-textblock)
  static f_repl_from_textblock(textblock) {
    let output = vx_repl.e_repl
    return output
  }

  /**
   * @function textblock_repl_from_script
   * Returns a parsed textblock from a string
   * @param  {string} script
   * @return {textblock}
   */
  static t_textblock_repl_from_script = {}
  static e_textblock_repl_from_script = {vx_type: vx_repl.t_textblock_repl_from_script}

  // (func textblock-repl<-script)
  static f_textblock_repl_from_script(script) {
    let output = vx_data_textblock.e_textblock
    output = vx_data_textblock.f_textblock_parse_from_string_delim(
      script,
      vx_repl.c_delimvxlisp
    )
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
    "any<-repl": vx_repl.e_any_from_repl,
    "any<-script": vx_repl.e_any_from_script,
    "anylist<-repllist": vx_repl.e_anylist_from_repllist,
    "macro": vx_repl.e_macro,
    "repl<-liblist-string": vx_repl.e_repl_from_liblist_string,
    "repl<-textblock": vx_repl.e_repl_from_textblock,
    "textblock-repl<-script": vx_repl.e_textblock_repl_from_script
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

    // (const delimvxlisp)
    Object.assign(vx_repl.c_delimvxlisp, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":name",
      "delimvxlisp",
      ":delimlist",
      vx_core.f_new(
        vx_data_textblock.t_delimlist,
        vx_repl.c_delimvxlispparen,
        vx_data_textblock.c_delimcomment,
        vx_data_textblock.c_delimcommentblock
      )
    ))

    // (const delimvxlispbracket)
    Object.assign(vx_repl.c_delimvxlispbracket, vx_core.f_copy(
      vx_data_textblock.c_delimbracketsquare,
      ":name",
      "delimvxlispbracketsquare",
      ":delimlist",
      vx_core.f_new(
        vx_data_textblock.t_delimlist,
        vx_data_textblock.c_delimcomment,
        vx_data_textblock.c_delimcommentblock,
        vx_data_textblock.c_delimquote,
        vx_data_textblock.c_delimquoteblock,
        vx_data_textblock.c_delimwhitespace,
        vx_repl.c_delimvxlispbracket,
        vx_repl.c_delimvxlispparen
      )
    ))

    // (const delimvxlispparen)
    Object.assign(vx_repl.c_delimvxlispparen, vx_core.f_copy(
      vx_data_textblock.c_delimparen,
      ":name",
      "delimvxlispparen",
      ":delimlist",
      vx_core.f_new(
        vx_data_textblock.t_delimlist,
        vx_data_textblock.c_delimcomment,
        vx_data_textblock.c_delimcommentblock,
        vx_data_textblock.c_delimquote,
        vx_data_textblock.c_delimquoteblock,
        vx_data_textblock.c_delimwhitespace,
        vx_repl.c_delimvxlispbracket,
        vx_repl.c_delimvxlispparen
      )
    ))

    // (func any-repl<-functype-args)
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

    // (func any<-liblist-string)
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

    // (func any<-repl)
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

    // (func any<-script)
    vx_repl.t_any_from_script['vx_type'] = vx_core.t_type
    vx_repl.t_any_from_script['vx_value'] = {
      name          : "any<-script",
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
      fn            : vx_repl.f_any_from_script
    }

    // (func anylist<-repllist)
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

    // (func repl<-liblist-string)
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

    // (func repl<-textblock)
    vx_repl.t_repl_from_textblock['vx_type'] = vx_core.t_type
    vx_repl.t_repl_from_textblock['vx_value'] = {
      name          : "repl<-textblock",
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
      fn            : vx_repl.f_repl_from_textblock
    }

    // (func textblock-repl<-script)
    vx_repl.t_textblock_repl_from_script['vx_type'] = vx_core.t_type
    vx_repl.t_textblock_repl_from_script['vx_value'] = {
      name          : "textblock-repl<-script",
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
      fn            : vx_repl.f_textblock_repl_from_script
    }

  }
}
