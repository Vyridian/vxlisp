'strict mode'

import vx_core from "../vx/core.js"
import vx_collection from "../vx/collection.js"
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
   * type: replarglist
   * Builder for a repllist
   */
  static t_replarglist = {}

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
   * @function any_from_macro
   * A function that joins any number of values into a string and then parses and evaluates it.
   * @param  {typemap} generic
   * @param  {anylist} ... anylist
   * @return {any-1}
   */
  static t_any_from_macro = {}
  static e_any_from_macro = {vx_type: vx_repl.t_any_from_macro}

  // (func any<-macro)
  static f_any_from_macro(generic, context, ...anylist) {
    const generic_any_1 = generic["any-1"]
    let output = vx_core.f_empty(generic_any_1)
    anylist = vx_core.f_new(vx_core.t_anylist, ...anylist)
    output = vx_core.f_let(
      {"any-1": vx_core.t_any, "any-2": vx_core.t_any},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const repl = vx_repl.f_repl_from_macro(context, ...anylist)
        const val = vx_repl.f_any_from_repl(context, repl)
        return vx_core.f_any_from_any({"any-1": vx_core.t_any, "any-2": vx_core.t_any}, val)
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
        const textblock = vx_repl.f_textblock_from_script(script)
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
   * @function argmap_from_textblock_argmap
   * Returns an argmap with parsed args from textblock added.
   * @param  {textblock} textblock
   * @param  {argmap} argmap
   * @return {argmap}
   */
  static t_argmap_from_textblock_argmap = {}
  static e_argmap_from_textblock_argmap = {vx_type: vx_repl.t_argmap_from_textblock_argmap}

  // (func argmap<-textblock-argmap)
  static f_argmap_from_textblock_argmap(textblock, argmap) {
    let output = vx_core.e_argmap
    output = vx_core.f_if_1(
      {"any-1": vx_core.t_argmap},
      vx_core.f_ne(
        "delimbracketsquare",
        vx_core.f_any_from_struct(
          {"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim},
          vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delim, "struct-2": vx_data_textblock.t_textblock}, textblock, ":delim"),
          ":name"
        )
      ),
      argmap,
      argmap
    )
    return output
  }

  /**
   * @function const_from_string
   * Returns a constant from a fully qualified name.
   * @param  {string} text
   * @return {any}
   */
  static t_const_from_string = {}
  static e_const_from_string = {vx_type: vx_repl.t_const_from_string}

  // (func const<-string)
  static f_const_from_string(text) {
    let output = vx_core.e_any
    output = vx_core.f_let(
      {"any-1": vx_core.t_any},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const pkgpos = vx_type.f_int_from_string_findlast(text, "/")
        const pkgname = vx_core.f_if_1(
          {"any-1": vx_core.t_string},
          vx_core.f_eq(0, pkgpos),
          "vx/core",
          vx_type.f_string_from_string_end(
            text,
            vx_core.f_minus1(pkgpos)
          )
        )
        const name = vx_core.f_if_1(
          {"any-1": vx_core.t_string},
          vx_core.f_eq(0, pkgpos),
          text,
          vx_type.f_string_from_string_start(
            text,
            vx_core.f_plus1(pkgpos)
          )
        )
        const pkg = vx_core.f_package_global_from_name(pkgname)
        const constmap = vx_core.f_any_from_struct({"any-1": vx_core.t_constmap, "struct-2": vx_core.t_package}, pkg, ":constmap")
        const constval = vx_core.f_any_from_map({"any-1": vx_core.t_any, "map-1": vx_core.t_constmap}, constmap, name)
        return vx_core.f_if_1(
          {"any-1": vx_core.t_any},
          vx_core.f_notempty_1(constval),
          constval,
          vx_core.f_empty(
            vx_core.t_any
          )
        )
      })
    )
    return output
  }

  /**
   * @function repl_bracket_from_textblock_argmap
   * Returns a repl from a squarebracket parsed textblock
   * @param  {textblock} textblock
   * @param  {argmap} argmap
   * @return {repl}
   */
  static t_repl_bracket_from_textblock_argmap = {}
  static e_repl_bracket_from_textblock_argmap = {vx_type: vx_repl.t_repl_bracket_from_textblock_argmap}

  // (func repl-bracket<-textblock-argmap)
  static f_repl_bracket_from_textblock_argmap(textblock, argmap) {
    let output = vx_repl.e_repl
    output = vx_core.f_empty(
      vx_repl.t_repl
    )
    return output
  }

  /**
   * @function repl_empty_from_textblock_argmap
   * Returns a repl from an empty delim textblock
   * @param  {textblock} textblock
   * @param  {argmap} argmap
   * @return {repl}
   */
  static t_repl_empty_from_textblock_argmap = {}
  static e_repl_empty_from_textblock_argmap = {vx_type: vx_repl.t_repl_empty_from_textblock_argmap}

  // (func repl-empty<-textblock-argmap)
  static f_repl_empty_from_textblock_argmap(textblock, argmap) {
    let output = vx_repl.e_repl
    output = vx_core.f_let(
      {"any-1": vx_repl.t_repl, "any-2": vx_core.t_int},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const children = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblocklist, "struct-2": vx_data_textblock.t_textblock}, textblock, ":children")
        const len = vx_core.f_length_from_list(children)
        return vx_core.f_switch(
          {"any-1": vx_repl.t_repl, "any-2": vx_core.t_int},
          len,
          vx_core.f_case_1(
            0,
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_repl.f_repl_from_string_argmap(
              vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_textblock}, textblock, ":text"),
              argmap
            )})
          ),
          vx_core.f_case_1(
            1,
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_repl.f_repl_from_textblock_argmap(
              vx_core.f_any_from_list({"any-1": vx_data_textblock.t_textblock, "list-1": vx_data_textblock.t_textblocklist}, children, 1),
              argmap
            )})
          ),
          vx_core.f_else(
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
              vx_repl.t_repl,
              vx_core.f_msg_from_error("Empty delim cannot have more than one child.")
            )})
          )
        )
      })
    )
    return output
  }

  /**
   * @function repl_paren_from_textblock_argmap
   * Returns a repl from a parsed textblock
   * @param  {textblock} textblock
   * @param  {argmap} argmap
   * @return {repl}
   */
  static t_repl_paren_from_textblock_argmap = {}
  static e_repl_paren_from_textblock_argmap = {vx_type: vx_repl.t_repl_paren_from_textblock_argmap}

  // (func repl-paren<-textblock-argmap)
  static f_repl_paren_from_textblock_argmap(textblock, argmap) {
    let output = vx_repl.e_repl
    output = vx_core.f_let(
      {"any-1": vx_repl.t_repl},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const childlst = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblocklist, "struct-2": vx_data_textblock.t_textblock}, textblock, ":children")
        const children = vx_data_textblock.f_textblocklist_from_textblocklist_remove(
          childlst,
          vx_data_textblock.c_delimwhitespace
        )
        const tbfunc = vx_core.f_any_from_list({"any-1": vx_data_textblock.t_textblock, "list-1": vx_data_textblock.t_textblocklist}, children, 1)
        const sfunc = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_textblock}, tbfunc, ":text")
        const replfunc = vx_repl.f_repl_from_string_argmap(sfunc, argmap)
        const typefunc = vx_core.f_any_from_struct({"any-1": vx_core.t_any, "struct-2": vx_repl.t_repl}, replfunc, ":type")
        const posarg = vx_core.f_switch(
          {"any-1": vx_core.t_int, "any-2": vx_core.t_any},
          typefunc,
          vx_core.f_case_1(
            vx_core.t_let,
            vx_core.f_new(vx_core.t_any_from_func, () => {return 3})
          ),
          vx_core.f_case_1(
            vx_core.t_fn,
            vx_core.f_new(vx_core.t_any_from_func, () => {return 3})
          ),
          vx_core.f_else(vx_core.f_new(vx_core.t_any_from_func, () => {return 2}))
        )
        const argmap2 = vx_core.f_switch(
          {"any-1": vx_core.t_argmap, "any-2": vx_core.t_any},
          typefunc,
          vx_core.f_case_1(
            vx_core.t_let,
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_repl.f_argmap_from_textblock_argmap(
              vx_core.f_any_from_list({"any-1": vx_data_textblock.t_textblock, "list-1": vx_data_textblock.t_textblocklist}, children, 3),
              argmap
            )})
          ),
          vx_core.f_case_1(
            vx_core.t_fn,
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_repl.f_argmap_from_textblock_argmap(
              vx_core.f_any_from_list({"any-1": vx_data_textblock.t_textblock, "list-1": vx_data_textblock.t_textblocklist}, children, 3),
              argmap
            )})
          ),
          vx_core.f_else(vx_core.f_new(vx_core.t_any_from_func, () => {return argmap}))
        )
        const tbargs = vx_collection.f_list_from_list_start({"any-1": vx_data_textblock.t_textblock, "list-1": vx_data_textblock.t_textblocklist}, children, posarg)
        const replargs = vx_repl.f_repllist_from_textblocklist_argmap(tbargs, argmap)
        return vx_core.f_copy(replfunc, ":repllist", replargs)
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
   * @function repl_from_macro
   * A function that joins any number of values into a string and then parses it.
   * @param  {anylist} ... anylist
   * @return {repl}
   */
  static t_repl_from_macro = {}
  static e_repl_from_macro = {vx_type: vx_repl.t_repl_from_macro}

  // (func repl<-macro)
  static f_repl_from_macro(context, ...anylist) {
    let output = vx_repl.e_repl
    anylist = vx_core.f_new(vx_core.t_anylist, ...anylist)
    output = vx_core.f_let(
      {"any-1": vx_repl.t_repl},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const textlist = vx_core.f_list_from_list(
          {"any-1": vx_core.t_string, "any-2": vx_core.t_any, "list-1": vx_core.t_stringlist, "list-2": vx_core.t_anylist},
          anylist,
          vx_core.f_new(vx_core.t_any_from_any, (item) => 
            vx_core.f_let(
              {"any-1": vx_core.t_string, "any-2": vx_core.t_any},
              [],
              vx_core.f_new(vx_core.t_any_from_func, () => {
                const typ = vx_core.f_type_from_any(item)
                return vx_core.f_switch(
                  {"any-1": vx_core.t_string, "any-2": vx_core.t_any},
                  typ,
                  vx_core.f_case_1(
                    vx_core.t_string,
                    vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_any_from_any({"any-1": vx_core.t_string, "any-2": vx_core.t_any}, item)})
                  ),
                  vx_core.f_else(
                    vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_string_from_any(item)})
                  )
                )
              })
            ))
        )
        const script = vx_type.f_string_from_stringlist_join(textlist, "")
        const tb = vx_repl.f_textblock_from_script(script)
        return vx_repl.f_repl_from_textblock(tb)
      })
    )
    return output
  }

  /**
   * @function repl_from_script
   * Returns a parsed repl from a string
   * @param  {string} script
   * @return {repl}
   */
  static t_repl_from_script = {}
  static e_repl_from_script = {vx_type: vx_repl.t_repl_from_script}

  // (func repl<-script)
  static f_repl_from_script(script) {
    let output = vx_repl.e_repl
    output = vx_core.f_let(
      {"any-1": vx_repl.t_repl},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const textblock = vx_repl.f_textblock_from_script(script)
        return vx_repl.f_repl_from_textblock(textblock)
      })
    )
    return output
  }

  /**
   * @function repl_from_string_argmap
   * Returns a function, type, const or primitive from given string.
   * @param  {string} text
   * @param  {argmap} argmap
   * @return {repl}
   */
  static t_repl_from_string_argmap = {}
  static e_repl_from_string_argmap = {vx_type: vx_repl.t_repl_from_string_argmap}

  // (func repl<-string-argmap)
  static f_repl_from_string_argmap(text, argmap) {
    let output = vx_repl.e_repl
    output = vx_core.f_if_2(
      {"any-1": vx_repl.t_repl},
      vx_core.f_then(
        vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_and(
          vx_type.f_boolean_from_string_starts(
            text,
            vx_core.c_quote
          ),
          vx_type.f_boolean_from_string_ends(
            text,
            vx_core.c_quote
          )
        )}),
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
          vx_repl.t_repl,
          ":val",
          vx_type.f_string_from_string_start_end(text, 2, -1)
        )})
      ),
      vx_core.f_then(
        vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_int(text)}),
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
          vx_repl.t_repl,
          ":val",
          vx_core.f_int_from_string(text)
        )})
      ),
      vx_core.f_then(
        vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_float(text)}),
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
          vx_repl.t_repl,
          ":val",
          vx_core.f_float_from_string(text)
        )})
      ),
      vx_core.f_else(
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_let(
          {"any-1": vx_repl.t_repl},
          [],
          vx_core.f_new(vx_core.t_any_from_func, () => {
            const arg = vx_core.f_any_from_map({"any-1": vx_core.t_arg, "map-1": vx_core.t_argmap}, argmap, text)
            return vx_core.f_if_2(
              {"any-1": vx_repl.t_repl},
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_notempty_1(arg)}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
                  vx_repl.t_repl,
                  ":val",
                  arg
                )})
              ),
              vx_core.f_else(
                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_let(
                  {"any-1": vx_repl.t_repl},
                  [],
                  vx_core.f_new(vx_core.t_any_from_func, () => {
                    const cnst = vx_repl.f_const_from_string(text)
                    return vx_core.f_if_2(
                      {"any-1": vx_repl.t_repl},
                      vx_core.f_then(
                        vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_notempty_1(cnst)}),
                        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
                          vx_repl.t_repl,
                          ":val",
                          cnst
                        )})
                      ),
                      vx_core.f_else(
                        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_let(
                          {"any-1": vx_repl.t_repl},
                          [],
                          vx_core.f_new(vx_core.t_any_from_func, () => {
                            const typefunc = vx_repl.f_typefunc_from_string(text)
                            return vx_core.f_if_2(
                              {"any-1": vx_repl.t_repl},
                              vx_core.f_then(
                                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_notempty_1(typefunc)}),
                                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
                                  vx_repl.t_repl,
                                  ":type",
                                  typefunc
                                )})
                              ),
                              vx_core.f_else(
                                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
                                  vx_repl.t_repl,
                                  vx_core.f_msg_from_error_1(":repltypenotfound", text)
                                )})
                              )
                            )
                          })
                        )})
                      )
                    )
                  })
                )})
              )
            )
          })
        )})
      )
    )
    return output
  }

  /**
   * @function repl_from_textblock
   * Returns a repl from a parsed textblock
   * @param  {textblock} textblock
   * @return {repl}
   */
  static t_repl_from_textblock = {}
  static e_repl_from_textblock = {vx_type: vx_repl.t_repl_from_textblock}

  // (func repl<-textblock)
  static f_repl_from_textblock(textblock) {
    let output = vx_repl.e_repl
    output = vx_repl.f_repl_from_textblock_argmap(
      textblock,
      vx_core.f_empty(
        vx_core.t_argmap
      )
    )
    return output
  }

  /**
   * @function repl_from_textblock_argmap
   * Returns a repl from a parsed textblock
   * @param  {textblock} textblock
   * @param  {argmap} argmap
   * @return {repl}
   */
  static t_repl_from_textblock_argmap = {}
  static e_repl_from_textblock_argmap = {vx_type: vx_repl.t_repl_from_textblock_argmap}

  // (func repl<-textblock-argmap)
  static f_repl_from_textblock_argmap(textblock, argmap) {
    let output = vx_repl.e_repl
    output = vx_core.f_let(
      {"any-1": vx_repl.t_repl, "any-2": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const delim = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delim, "struct-2": vx_data_textblock.t_textblock}, textblock, ":delim")
        const starttext = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delim, ":starttext")
        return vx_core.f_switch(
          {"any-1": vx_repl.t_repl, "any-2": vx_core.t_string},
          starttext,
          vx_core.f_case_1(
            "",
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_repl.f_repl_empty_from_textblock_argmap(textblock, argmap)})
          ),
          vx_core.f_case_1(
            vx_core.f_any_from_struct(
              {"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim},
              vx_data_textblock.c_delimparen,
              ":starttext"
            ),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_repl.f_repl_paren_from_textblock_argmap(textblock, argmap)})
          ),
          vx_core.f_case_1(
            vx_core.f_any_from_struct(
              {"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim},
              vx_data_textblock.c_delimbracketsquare,
              ":starttext"
            ),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_repl.f_repl_bracket_from_textblock_argmap(textblock, argmap)})
          )
        )
      })
    )
    return output
  }

  /**
   * @function replarglist_from_replarglist_textblock_argmap
   * Returns a modified replarglist from by applying a textblock
   * @param  {replarglist} replargs
   * @param  {textblock} tb
   * @param  {argmap} argmap
   * @return {replarglist}
   */
  static t_replarglist_from_replarglist_textblock_argmap = {}
  static e_replarglist_from_replarglist_textblock_argmap = {vx_type: vx_repl.t_replarglist_from_replarglist_textblock_argmap}

  // (func replarglist<-replarglist-textblock-argmap)
  static f_replarglist_from_replarglist_textblock_argmap(replargs, tb, argmap) {
    let output = vx_repl.e_replarglist
    output = vx_core.f_let(
      {"any-1": vx_repl.t_replarglist},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const key = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_repl.t_replarglist}, replargs, ":key")
        const current = vx_core.f_any_from_struct({"any-1": vx_repl.t_repl, "struct-2": vx_repl.t_replarglist}, replargs, ":current")
        const repllist = vx_core.f_any_from_struct({"any-1": vx_repl.t_repllist, "struct-2": vx_repl.t_replarglist}, replargs, ":repllist")
        const currlist = vx_core.f_any_from_struct({"any-1": vx_repl.t_repllist, "struct-2": vx_repl.t_repl}, current, ":repllist")
        const text = vx_core.f_any_from_struct(
          {"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_textblock},
          vx_data_textblock.t_textblock,
          ":text"
        )
        return vx_core.f_if_2(
          {"any-1": vx_repl.t_replarglist},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq(key, "")}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_if_2(
              {"any-1": vx_repl.t_replarglist},
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq_1(text)}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(replargs, ":key", text)})
              ),
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq(text, ":=")}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(replargs, ":key", text)})
              ),
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq(text, ":doc")}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(replargs, ":key", text)})
              ),
              vx_core.f_else(
                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(
                  replargs,
                  ":current",
                  vx_core.f_new(
                    vx_repl.t_repl,
                    ":name",
                    text
                  ),
                  ":repllist",
                  vx_core.f_copy(repllist, current)
                )})
              )
            )})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq_1(key)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(
              replargs,
              ":key",
              "",
              ":current",
              vx_core.f_copy(current, ":type", text)
            )})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq(key, ":=")}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(
              replargs,
              ":key",
              "",
              ":current",
              vx_core.f_copy(
                current,
                ":repllist",
                vx_core.f_copy(
                  currlist,
                  vx_repl.f_repl_from_textblock_argmap(tb, argmap)
                )
              )
            )})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq(key, ":doc")}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(
              replargs,
              ":key",
              "",
              ":current",
              vx_core.f_copy(current, ":doc", text)
            )})
          ),
          vx_core.f_else(vx_core.f_new(vx_core.t_any_from_func, () => {return replargs}))
        )
      })
    )
    return output
  }

  /**
   * @function repllist_from_textblocklist_argmap
   * Returns a repllist from a parsed textblocklist
   * @param  {textblocklist} textblocklist
   * @param  {argmap} argmap
   * @return {repllist}
   */
  static t_repllist_from_textblocklist_argmap = {}
  static e_repllist_from_textblocklist_argmap = {vx_type: vx_repl.t_repllist_from_textblocklist_argmap}

  // (func repllist<-textblocklist-argmap)
  static f_repllist_from_textblocklist_argmap(textblocklist, argmap) {
    let output = vx_repl.e_repllist
    output = vx_core.f_list_from_list(
      {"any-1": vx_repl.t_repl, "any-2": vx_data_textblock.t_textblock, "list-1": vx_repl.t_repllist, "list-2": vx_data_textblock.t_textblocklist},
      textblocklist,
      vx_core.f_new(vx_core.t_any_from_any, (textblock) => 
        vx_repl.f_repl_from_textblock(textblock))
    )
    return output
  }

  /**
   * @function textblock_from_script
   * Returns a parsed textblock from a string
   * @param  {string} script
   * @return {textblock}
   */
  static t_textblock_from_script = {}
  static e_textblock_from_script = {vx_type: vx_repl.t_textblock_from_script}

  // (func textblock<-script)
  static f_textblock_from_script(script) {
    let output = vx_data_textblock.e_textblock
    output = vx_data_textblock.f_textblock_parse_from_string_delim(
      script,
      vx_repl.c_delimvxlisp
    )
    return output
  }

  /**
   * @function typefunc_from_string
   * Returns a type, or func from a fully qualified name.
   * @param  {string} text
   * @return {any}
   */
  static t_typefunc_from_string = {}
  static e_typefunc_from_string = {vx_type: vx_repl.t_typefunc_from_string}

  // (func typefunc<-string)
  static f_typefunc_from_string(text) {
    let output = vx_core.e_any
    output = vx_core.f_let(
      {"any-1": vx_core.t_any},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const pkgpos = vx_type.f_int_from_string_findlast(text, "/")
        const pkgname = vx_core.f_if_1(
          {"any-1": vx_core.t_string},
          vx_core.f_eq(0, pkgpos),
          "vx/core",
          vx_type.f_string_from_string_end(
            text,
            vx_core.f_minus1(pkgpos)
          )
        )
        const name = vx_core.f_if_1(
          {"any-1": vx_core.t_string},
          vx_core.f_eq(0, pkgpos),
          text,
          vx_type.f_string_from_string_start(
            text,
            vx_core.f_plus1(pkgpos)
          )
        )
        const pkg = vx_core.f_package_global_from_name(pkgname)
        const typemap = vx_core.f_any_from_struct({"any-1": vx_core.t_typemap, "struct-2": vx_core.t_package}, pkg, ":typemap")
        const typeval = vx_core.f_any_from_map({"any-1": vx_core.t_any, "map-1": vx_core.t_typemap}, typemap, name)
        return vx_core.f_if_1(
          {"any-1": vx_core.t_any},
          vx_core.f_notempty_1(typeval),
          typeval,
          vx_core.f_let(
            {"any-1": vx_core.t_any},
            [],
            vx_core.f_new(vx_core.t_any_from_func, () => {
              const funcmap = vx_core.f_any_from_struct({"any-1": vx_core.t_funcmap, "struct-2": vx_core.t_package}, pkg, ":funcmap")
              const funcval = vx_core.f_any_from_map({"any-1": vx_core.t_func, "map-1": vx_core.t_funcmap}, funcmap, name)
              return vx_core.f_if_1(
                {"any-1": vx_core.t_any},
                vx_core.f_notempty_1(funcval),
                funcval,
                vx_core.f_empty(
                  vx_core.t_any
                )
              )
            })
          )
        )
      })
    )
    return output
  }

  // empty types
  static e_liblist = []
  static e_repl = {}
  static e_replarglist = {}
  static e_repllist = []


  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      "delimvxlisp": vx_repl.c_delimvxlisp,
      "delimvxlispbracket": vx_repl.c_delimvxlispbracket,
      "delimvxlispparen": vx_repl.c_delimvxlispparen
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "liblist": vx_repl.e_liblist,
      "repl": vx_repl.e_repl,
      "replarglist": vx_repl.e_replarglist,
      "repllist": vx_repl.e_repllist,
      "any-repl<-functype-args": vx_repl.e_any_repl_from_functype_args,
      "any<-liblist-string": vx_repl.e_any_from_liblist_string,
      "any<-macro": vx_repl.e_any_from_macro,
      "any<-repl": vx_repl.e_any_from_repl,
      "any<-script": vx_repl.e_any_from_script,
      "anylist<-repllist": vx_repl.e_anylist_from_repllist,
      "argmap<-textblock-argmap": vx_repl.e_argmap_from_textblock_argmap,
      "const<-string": vx_repl.e_const_from_string,
      "repl-bracket<-textblock-argmap": vx_repl.e_repl_bracket_from_textblock_argmap,
      "repl-empty<-textblock-argmap": vx_repl.e_repl_empty_from_textblock_argmap,
      "repl-paren<-textblock-argmap": vx_repl.e_repl_paren_from_textblock_argmap,
      "repl<-liblist-string": vx_repl.e_repl_from_liblist_string,
      "repl<-macro": vx_repl.e_repl_from_macro,
      "repl<-script": vx_repl.e_repl_from_script,
      "repl<-string-argmap": vx_repl.e_repl_from_string_argmap,
      "repl<-textblock": vx_repl.e_repl_from_textblock,
      "repl<-textblock-argmap": vx_repl.e_repl_from_textblock_argmap,
      "replarglist<-replarglist-textblock-argmap": vx_repl.e_replarglist_from_replarglist_textblock_argmap,
      "repllist<-textblocklist-argmap": vx_repl.e_repllist_from_textblocklist_argmap,
      "textblock<-script": vx_repl.e_textblock_from_script,
      "typefunc<-string": vx_repl.e_typefunc_from_string
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "any-repl<-functype-args": vx_repl.t_any_repl_from_functype_args,
      "any<-liblist-string": vx_repl.t_any_from_liblist_string,
      "any<-macro": vx_repl.t_any_from_macro,
      "any<-repl": vx_repl.t_any_from_repl,
      "any<-script": vx_repl.t_any_from_script,
      "anylist<-repllist": vx_repl.t_anylist_from_repllist,
      "argmap<-textblock-argmap": vx_repl.t_argmap_from_textblock_argmap,
      "const<-string": vx_repl.t_const_from_string,
      "repl-bracket<-textblock-argmap": vx_repl.t_repl_bracket_from_textblock_argmap,
      "repl-empty<-textblock-argmap": vx_repl.t_repl_empty_from_textblock_argmap,
      "repl-paren<-textblock-argmap": vx_repl.t_repl_paren_from_textblock_argmap,
      "repl<-liblist-string": vx_repl.t_repl_from_liblist_string,
      "repl<-macro": vx_repl.t_repl_from_macro,
      "repl<-script": vx_repl.t_repl_from_script,
      "repl<-string-argmap": vx_repl.t_repl_from_string_argmap,
      "repl<-textblock": vx_repl.t_repl_from_textblock,
      "repl<-textblock-argmap": vx_repl.t_repl_from_textblock_argmap,
      "replarglist<-replarglist-textblock-argmap": vx_repl.t_replarglist_from_replarglist_textblock_argmap,
      "repllist<-textblocklist-argmap": vx_repl.t_repllist_from_textblocklist_argmap,
      "textblock<-script": vx_repl.t_textblock_from_script,
      "typefunc<-string": vx_repl.t_typefunc_from_string
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      "liblist": vx_repl.t_liblist,
      "repl": vx_repl.t_repl,
      "replarglist": vx_repl.t_replarglist,
      "repllist": vx_repl.t_repllist
    })
    const pkg = vx_core.vx_new_struct(vx_core.t_package, {
      "name": "vx/repl",
      "constmap": constmap,
      "emptymap": emptymap,
      "funcmap": funcmap,
      "typemap": typemap
    })
    vx_core.vx_global_package_set(pkg)

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
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
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
        },
        "doc": {
          "name" : "doc",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "doc",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    vx_repl.e_repl['vx_type'] = vx_repl.t_repl
    vx_repl.e_repl['vx_value'] = {}

    // (type replarglist)
    vx_repl.t_replarglist['vx_type'] = vx_core.t_type
    vx_repl.t_replarglist['vx_value'] = {
      name          : "replarglist",
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
        "key": {
          "name" : "key",
          "type" : vx_core.t_string,
          "multi": false
        },
        "current": {
          "name" : "current",
          "type" : vx_repl.t_repl,
          "multi": false
        },
        "repllist": {
          "name" : "repllist",
          "type" : vx_repl.t_repllist,
          "multi": false
        }
      },
      proplast      : {
        "name" : "repllist",
        "type" : vx_repl.t_repllist,
        "multi": false
      }
    }
    vx_repl.e_replarglist['vx_type'] = vx_repl.t_replarglist
    vx_repl.e_replarglist['vx_value'] = {}

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

    // (func any<-macro)
    vx_repl.t_any_from_macro['vx_type'] = vx_core.t_type
    vx_repl.t_any_from_macro['vx_value'] = {
      name          : "any<-macro",
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
      fn            : vx_repl.f_any_from_macro
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

    // (func argmap<-textblock-argmap)
    vx_repl.t_argmap_from_textblock_argmap['vx_type'] = vx_core.t_type
    vx_repl.t_argmap_from_textblock_argmap['vx_value'] = {
      name          : "argmap<-textblock-argmap",
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
      fn            : vx_repl.f_argmap_from_textblock_argmap
    }

    // (func const<-string)
    vx_repl.t_const_from_string['vx_type'] = vx_core.t_type
    vx_repl.t_const_from_string['vx_value'] = {
      name          : "const<-string",
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
      fn            : vx_repl.f_const_from_string
    }

    // (func repl-bracket<-textblock-argmap)
    vx_repl.t_repl_bracket_from_textblock_argmap['vx_type'] = vx_core.t_type
    vx_repl.t_repl_bracket_from_textblock_argmap['vx_value'] = {
      name          : "repl-bracket<-textblock-argmap",
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
      fn            : vx_repl.f_repl_bracket_from_textblock_argmap
    }

    // (func repl-empty<-textblock-argmap)
    vx_repl.t_repl_empty_from_textblock_argmap['vx_type'] = vx_core.t_type
    vx_repl.t_repl_empty_from_textblock_argmap['vx_value'] = {
      name          : "repl-empty<-textblock-argmap",
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
      fn            : vx_repl.f_repl_empty_from_textblock_argmap
    }

    // (func repl-paren<-textblock-argmap)
    vx_repl.t_repl_paren_from_textblock_argmap['vx_type'] = vx_core.t_type
    vx_repl.t_repl_paren_from_textblock_argmap['vx_value'] = {
      name          : "repl-paren<-textblock-argmap",
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
      fn            : vx_repl.f_repl_paren_from_textblock_argmap
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

    // (func repl<-macro)
    vx_repl.t_repl_from_macro['vx_type'] = vx_core.t_type
    vx_repl.t_repl_from_macro['vx_value'] = {
      name          : "repl<-macro",
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
      fn            : vx_repl.f_repl_from_macro
    }

    // (func repl<-script)
    vx_repl.t_repl_from_script['vx_type'] = vx_core.t_type
    vx_repl.t_repl_from_script['vx_value'] = {
      name          : "repl<-script",
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
      fn            : vx_repl.f_repl_from_script
    }

    // (func repl<-string-argmap)
    vx_repl.t_repl_from_string_argmap['vx_type'] = vx_core.t_type
    vx_repl.t_repl_from_string_argmap['vx_value'] = {
      name          : "repl<-string-argmap",
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
      fn            : vx_repl.f_repl_from_string_argmap
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

    // (func repl<-textblock-argmap)
    vx_repl.t_repl_from_textblock_argmap['vx_type'] = vx_core.t_type
    vx_repl.t_repl_from_textblock_argmap['vx_value'] = {
      name          : "repl<-textblock-argmap",
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
      fn            : vx_repl.f_repl_from_textblock_argmap
    }

    // (func replarglist<-replarglist-textblock-argmap)
    vx_repl.t_replarglist_from_replarglist_textblock_argmap['vx_type'] = vx_core.t_type
    vx_repl.t_replarglist_from_replarglist_textblock_argmap['vx_value'] = {
      name          : "replarglist<-replarglist-textblock-argmap",
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
      fn            : vx_repl.f_replarglist_from_replarglist_textblock_argmap
    }

    // (func repllist<-textblocklist-argmap)
    vx_repl.t_repllist_from_textblocklist_argmap['vx_type'] = vx_core.t_type
    vx_repl.t_repllist_from_textblocklist_argmap['vx_value'] = {
      name          : "repllist<-textblocklist-argmap",
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
      fn            : vx_repl.f_repllist_from_textblocklist_argmap
    }

    // (func textblock<-script)
    vx_repl.t_textblock_from_script['vx_type'] = vx_core.t_type
    vx_repl.t_textblock_from_script['vx_value'] = {
      name          : "textblock<-script",
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
      fn            : vx_repl.f_textblock_from_script
    }

    // (func typefunc<-string)
    vx_repl.t_typefunc_from_string['vx_type'] = vx_core.t_type
    vx_repl.t_typefunc_from_string['vx_value'] = {
      name          : "typefunc<-string",
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
      fn            : vx_repl.f_typefunc_from_string
    }

  }
}
