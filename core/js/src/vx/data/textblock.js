'strict mode'

import vx_core from "../../vx/core.js"
import vx_type from "../../vx/type.js"

export default class vx_data_textblock {

  /**
   * type: delim
   * A delimiter type supporting start and end delimiters and positions.
   */
  static t_delim = {}

  /**
   * type: delimlist
   * A list of delim.
   */
  static t_delimlist = {}

  /**
   * type: textblock
   * A textblock is a tree of text used for parsing by delimter.
   */
  static t_textblock = {}

  /**
   * type: textblocklist
   * A list of textblock.
   */
  static t_textblocklist = {}
  /**
   * Constant: delimbracketcurly
   * Curly Bracket Delimiter
   * {delim}
   */
  static c_delimbracketcurly = {vx_type: vx_data_textblock.t_delim}

  /**
   * Constant: delimbracketsquare
   * Square Bracket Delimiter
   * {delim}
   */
  static c_delimbracketsquare = {vx_type: vx_data_textblock.t_delim}

  /**
   * Constant: delimclose
   * A placeholder delimiter used to mark the close of whatever is the current delimiter.
   * {delim}
   */
  static c_delimclose = {vx_type: vx_data_textblock.t_delim}

  /**
   * Constant: delimcomma
   * Comma Delimiter
   * {delim}
   */
  static c_delimcomma = {vx_type: vx_data_textblock.t_delim}

  /**
   * Constant: delimcomment
   * Comment Delimiter
   * {delim}
   */
  static c_delimcomment = {vx_type: vx_data_textblock.t_delim}

  /**
   * Constant: delimcommentblock
   * Block Comment Delimiter
   * {delim}
   */
  static c_delimcommentblock = {vx_type: vx_data_textblock.t_delim}

  /**
   * Constant: delimline
   * New Line Delimiter
   * {delim}
   */
  static c_delimline = {vx_type: vx_data_textblock.t_delim}

  /**
   * Constant: delimnonwhitespace
   * Placeholder for delimited non-whitespace
   * {delim}
   */
  static c_delimnonwhitespace = {vx_type: vx_data_textblock.t_delim}

  /**
   * Constant: delimparen
   * Parenthesis Delimiter
   * {delim}
   */
  static c_delimparen = {vx_type: vx_data_textblock.t_delim}

  /**
   * Constant: delimparenline
   * Parenthesis with newline Delimiter
   * {delim}
   */
  static c_delimparenline = {vx_type: vx_data_textblock.t_delim}

  /**
   * Constant: delimquote
   * Quote Delimiter
   * {delim}
   */
  static c_delimquote = {vx_type: vx_data_textblock.t_delim}

  /**
   * Constant: delimquoteblock
   * Block Quote Delimiter
   * {delim}
   */
  static c_delimquoteblock = {vx_type: vx_data_textblock.t_delim}

  /**
   * Constant: delimspace
   * Space Delimiter
   * {delim}
   */
  static c_delimspace = {vx_type: vx_data_textblock.t_delim}

  /**
   * Constant: delimtext
   * Placeholder for delimited text
   * {delim}
   */
  static c_delimtext = {vx_type: vx_data_textblock.t_delim}

  /**
   * Constant: delimwhitespace
   * Placeholder for delimited whitespace
   * {delim}
   */
  static c_delimwhitespace = {vx_type: vx_data_textblock.t_delim}

  /**
   * @function delim_first_from_delim_delim
   * Returns non-empty delim with lowest, non-negative startpos found in string.
   * @param  {delim} delim1
   * @param  {delim} delim2
   * @return {delim}
   */
  static t_delim_first_from_delim_delim = {}
  static e_delim_first_from_delim_delim = {vx_type: vx_data_textblock.t_delim_first_from_delim_delim}

  static f_delim_first_from_delim_delim(delim1, delim2) {
    let output = vx_data_textblock.e_delim
    output = vx_core.f_let(
      {"any-1": vx_data_textblock.t_delim},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const pos1 = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-1": vx_data_textblock.t_delim}, delim1, ":startpos")
        const pos2 = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-1": vx_data_textblock.t_delim}, delim2, ":startpos")
        return vx_core.f_if_2(
          {"any-1": vx_data_textblock.t_delim},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty_1(delim2)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return delim1})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty_1(delim1)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return delim2})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_lt(pos2, 0)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return delim1})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_lt(pos1, 0)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return delim2})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_lt(pos2, pos1)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return delim2})
          ),
          vx_core.f_else(vx_core.f_new(vx_core.t_any_from_func, () => {return delim1}))
        )
      })
    )
    return output
  }

  /**
   * @function delim_first_from_string_delimlist
   * Returns delim with lowest startpos found in string.
   * @param  {string} text
   * @param  {delimlist} delimlist
   * @return {delim}
   */
  static t_delim_first_from_string_delimlist = {}
  static e_delim_first_from_string_delimlist = {vx_type: vx_data_textblock.t_delim_first_from_string_delimlist}

  static f_delim_first_from_string_delimlist(text, delimlist) {
    let output = vx_data_textblock.e_delim
    output = vx_core.f_let(
      {"any-1": vx_data_textblock.t_delim, "any-2": vx_data_textblock.t_delim, "list-2": vx_data_textblock.t_delimlist},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const resolvedlist = vx_data_textblock.f_delimlist_startpos_from_string_delimlist(text, delimlist)
        return vx_core.f_any_from_list_reduce(
          {"any-1": vx_data_textblock.t_delim, "any-2": vx_data_textblock.t_delim, "list-2": vx_data_textblock.t_delimlist},
          resolvedlist,
          vx_core.f_empty(
            vx_data_textblock.t_delim
          ),
          vx_core.f_new(vx_core.t_any_from_reduce, vx_data_textblock.t_delim_first_from_delim_delim)
        )
      })
    )
    return output
  }

  /**
   * @function delim_startpos_from_string_delim
   * Return a delim with istart updated to position of first starttext.
   * @param  {string} text
   * @param  {delim} delim
   * @return {delim}
   */
  static t_delim_startpos_from_string_delim = {}
  static e_delim_startpos_from_string_delim = {vx_type: vx_data_textblock.t_delim_startpos_from_string_delim}

  static f_delim_startpos_from_string_delim(text, delim) {
    let output = vx_data_textblock.e_delim
    output = vx_core.f_let(
      {"any-1": vx_data_textblock.t_delim},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const find = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-1": vx_data_textblock.t_delim}, delim, ":starttext")
        const pos = vx_core.f_if_2(
          {"any-1": vx_core.t_int},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq(find, "")}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return -1})
          ),
          vx_core.f_else(
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_type.f_int_from_string_findkeyword(text, find)})
          )
        )
        return vx_core.f_copy(delim, ":startpos", pos)
      })
    )
    return output
  }

  /**
   * @function delimlist_startpos_from_string_delimlist
   * Returns a delimlist with each delim updated to position of first starttext.
   * @param  {string} text
   * @param  {delimlist} delimlist
   * @return {delimlist}
   */
  static t_delimlist_startpos_from_string_delimlist = {}
  static e_delimlist_startpos_from_string_delimlist = {vx_type: vx_data_textblock.t_delimlist_startpos_from_string_delimlist}

  static f_delimlist_startpos_from_string_delimlist(text, delimlist) {
    let output = vx_data_textblock.e_delimlist
    output = vx_core.f_list_from_list(
      {"any-1": vx_data_textblock.t_delim, "any-2": vx_data_textblock.t_delim, "list-1": vx_data_textblock.t_delimlist, "list-2": vx_data_textblock.t_delimlist},
      delimlist,
      vx_core.f_new(vx_core.t_any_from_any, (delim) => 
        vx_data_textblock.f_delim_startpos_from_string_delim(text, delim))
    )
    return output
  }

  /**
   * @function stringlist_from_textblocklist
   * Returns the child textblocks from a given textblock.
   * @param  {textblocklist} textblocks
   * @return {stringlist}
   */
  static t_stringlist_from_textblocklist = {}
  static e_stringlist_from_textblocklist = {vx_type: vx_data_textblock.t_stringlist_from_textblocklist}

  static f_stringlist_from_textblocklist(textblocks) {
    let output = vx_core.e_stringlist
    output = vx_core.f_list_from_list(
      {"any-1": vx_core.t_string, "any-2": vx_data_textblock.t_textblock, "list-1": vx_core.t_stringlist, "list-2": vx_data_textblock.t_textblocklist},
      textblocks,
      vx_core.f_new(vx_core.t_any_from_any, vx_data_textblock.t_text_from_textblock)
    )
    return output
  }

  /**
   * @function text_from_textblock
   * Returns the text from a given textblock.
   * @param  {textblock} block
   * @return {string}
   */
  static t_text_from_textblock = {}
  static e_text_from_textblock = {vx_type: vx_data_textblock.t_text_from_textblock}

  static f_text_from_textblock(block) {
    let output = vx_core.e_string
    output = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-1": vx_data_textblock.t_textblock}, block, ":text")
    return output
  }

  /**
   * @function textblock_firstdelim_from_textblock_delimlist
   * Returns textblock with delim with lowest startpos found in text.
   * @param  {textblock} textblock
   * @param  {delimlist} delimlist
   * @return {textblock}
   */
  static t_textblock_firstdelim_from_textblock_delimlist = {}
  static e_textblock_firstdelim_from_textblock_delimlist = {vx_type: vx_data_textblock.t_textblock_firstdelim_from_textblock_delimlist}

  static f_textblock_firstdelim_from_textblock_delimlist(textblock, delimlist) {
    let output = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      {"any-1": vx_data_textblock.t_textblock},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const text = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-1": vx_data_textblock.t_textblock}, textblock, ":text")
        const delim = vx_data_textblock.f_delim_first_from_string_delimlist(text, delimlist)
        return vx_core.f_if_2(
          {"any-1": vx_data_textblock.t_textblock},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty_1(delim)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return textblock})
          ),
          vx_core.f_else(
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_let(
              {"any-1": vx_data_textblock.t_textblock},
              [],
              vx_core.f_new(vx_core.t_any_from_func, () => {
                const textblockbefore = vx_data_textblock.f_textblock_startbefore_from_string_delim(text, delim)
                const textblockafter = vx_data_textblock.f_textblock_startafter_from_string_delim(text, delim)
                const textblocks = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblocklist, "struct-1": vx_data_textblock.t_textblock}, textblock, ":textblocks")
                const addtextblocks = vx_core.f_if_2(
                  {"any-1": vx_data_textblock.t_textblocklist},
                  vx_core.f_then(
                    vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty_1(textblockbefore)}),
                    vx_core.f_new(vx_core.t_any_from_func, () => {return textblocks})
                  ),
                  vx_core.f_then(
                    vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty_1(textblocks)}),
                    vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
                      vx_data_textblock.t_textblocklist,
                      textblockbefore
                    )})
                  ),
                  vx_core.f_else(
                    vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(textblocks, textblockbefore)})
                  )
                )
                const parent = vx_core.f_copy(textblock, ":textblocks", addtextblocks)
                return vx_core.f_copy(textblockafter, ":delim", delim, ":parent", parent)
              })
            )})
          )
        )
      })
    )
    return output
  }

  /**
   * @function textblock_startafter_from_string_delim
   * Returns a textblock constructed from the text after the current delimiter start.
   * @param  {string} text
   * @param  {delim} delim
   * @return {textblock}
   */
  static t_textblock_startafter_from_string_delim = {}
  static e_textblock_startafter_from_string_delim = {vx_type: vx_data_textblock.t_textblock_startafter_from_string_delim}

  static f_textblock_startafter_from_string_delim(text, delim) {
    let output = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      {"any-1": vx_data_textblock.t_textblock},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const startpos = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-1": vx_data_textblock.t_delim}, delim, ":startpos")
        const starttext = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-1": vx_data_textblock.t_delim}, delim, ":starttext")
        const delimlen = vx_type.f_length_from_string(starttext)
        const beginpos = vx_core.f_plus(startpos, delimlen)
        return vx_core.f_if_2(
          {"any-1": vx_data_textblock.t_textblock},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq(text, "")}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_empty(
              vx_data_textblock.t_textblock
            )})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_lt(startpos, 0)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_empty(
              vx_data_textblock.t_textblock
            )})
          ),
          vx_core.f_else(
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
              vx_data_textblock.t_textblock,
              ":text",
              vx_type.f_string_from_string_start(text, beginpos)
            )})
          )
        )
      })
    )
    return output
  }

  /**
   * @function textblock_startbefore_from_string_delim
   * Returns a textblock constructed from the text before the current delimiter start.
   * @param  {string} text
   * @param  {delim} delim
   * @return {textblock}
   */
  static t_textblock_startbefore_from_string_delim = {}
  static e_textblock_startbefore_from_string_delim = {vx_type: vx_data_textblock.t_textblock_startbefore_from_string_delim}

  static f_textblock_startbefore_from_string_delim(text, delim) {
    let output = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      {"any-1": vx_data_textblock.t_textblock},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const startpos = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-1": vx_data_textblock.t_delim}, delim, ":startpos")
        return vx_core.f_if_2(
          {"any-1": vx_data_textblock.t_textblock},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq(text, "")}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_empty(
              vx_data_textblock.t_textblock
            )})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_lt(startpos, 0)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_empty(
              vx_data_textblock.t_textblock
            )})
          ),
          vx_core.f_else(
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
              vx_data_textblock.t_textblock,
              ":text",
              vx_type.f_string_from_string_start_end(text, 0, startpos)
            )})
          )
        )
      })
    )
    return output
  }

  /**
   * @function textblock_from_textblock_delim
   * Returns a parsed textblock from an unparsed one.
   * @param  {textblock} textblock
   * @param  {delim} delim
   * @return {textblock}
   */
  static t_textblock_from_textblock_delim = {}
  static e_textblock_from_textblock_delim = {vx_type: vx_data_textblock.t_textblock_from_textblock_delim}

  static f_textblock_from_textblock_delim(textblock, delim) {
    let output = vx_data_textblock.e_textblock
    return output
  }

  /**
   * @function textblocks_from_textblock
   * Returns the child textblocks from a given textblock.
   * @param  {textblock} block
   * @return {textblocklist}
   */
  static t_textblocks_from_textblock = {}
  static e_textblocks_from_textblock = {vx_type: vx_data_textblock.t_textblocks_from_textblock}

  static f_textblocks_from_textblock(block) {
    let output = vx_data_textblock.e_textblocklist
    output = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblocklist, "struct-1": vx_data_textblock.t_textblock}, block, ":textblocks")
    return output
  }

  // empty types
  static e_delim = {}
  static e_delimlist = []
  static e_textblock = {}
  static e_textblocklist = []

  static c_empty = {
    "delim": vx_data_textblock.e_delim,
    "delimlist": vx_data_textblock.e_delimlist,
    "textblock": vx_data_textblock.e_textblock,
    "textblocklist": vx_data_textblock.e_textblocklist,
    "delim-first<-delim-delim": vx_data_textblock.e_delim_first_from_delim_delim,
    "delim-first<-string-delimlist": vx_data_textblock.e_delim_first_from_string_delimlist,
    "delim-startpos<-string-delim": vx_data_textblock.e_delim_startpos_from_string_delim,
    "delimlist-startpos<-string-delimlist": vx_data_textblock.e_delimlist_startpos_from_string_delimlist,
    "stringlist<-textblocklist": vx_data_textblock.e_stringlist_from_textblocklist,
    "text<-textblock": vx_data_textblock.e_text_from_textblock,
    "textblock-firstdelim<-textblock-delimlist": vx_data_textblock.e_textblock_firstdelim_from_textblock_delimlist,
    "textblock-startafter<-string-delim": vx_data_textblock.e_textblock_startafter_from_string_delim,
    "textblock-startbefore<-string-delim": vx_data_textblock.e_textblock_startbefore_from_string_delim,
    "textblock<-textblock-delim": vx_data_textblock.e_textblock_from_textblock_delim,
    "textblocks<-textblock": vx_data_textblock.e_textblocks_from_textblock
  }


  static {
    vx_core.f_global_package_set("vx/data/textblock", vx_data_textblock)

    // (type delim)
    vx_data_textblock.t_delim['vx_type'] = vx_core.t_type
    vx_data_textblock.t_delim['vx_value'] = {
      name          : "delim",
      pkgname       : "vx/data/textblock",
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
        "starttext": {
          "name" : "starttext",
          "type" : vx_core.t_string,
          "multi": false
        },
        "endtext": {
          "name" : "endtext",
          "type" : vx_core.t_string,
          "multi": false
        },
        "startpos": {
          "name" : "startpos",
          "type" : vx_core.t_int,
          "multi": false
        },
        "endpos": {
          "name" : "endpos",
          "type" : vx_core.t_int,
          "multi": false
        },
        "delimlist": {
          "name" : "delimlist",
          "type" : vx_data_textblock.t_delimlist,
          "multi": false
        }
      },
      proplast      : {
        "name" : "delimlist",
        "type" : vx_data_textblock.t_delimlist,
        "multi": false
      }
    }
    vx_data_textblock.e_delim['vx_type'] = vx_data_textblock.t_delim
    vx_data_textblock.e_delim['vx_value'] = {}

    // (type delimlist)
    vx_data_textblock.t_delimlist['vx_type'] = vx_core.t_type
    vx_data_textblock.t_delimlist['vx_value'] = {
      name          : "delimlist",
      pkgname       : "vx/data/textblock",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_data_textblock.t_delim],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_data_textblock.e_delimlist['vx_type'] = vx_data_textblock.t_delimlist

    // (type textblock)
    vx_data_textblock.t_textblock['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblock['vx_value'] = {
      name          : "textblock",
      pkgname       : "vx/data/textblock",
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
        "text": {
          "name" : "text",
          "type" : vx_core.t_string,
          "multi": false
        },
        "line": {
          "name" : "line",
          "type" : vx_core.t_int,
          "multi": false
        },
        "column": {
          "name" : "column",
          "type" : vx_core.t_int,
          "multi": false
        },
        "delim": {
          "name" : "delim",
          "type" : vx_data_textblock.t_delim,
          "multi": false
        },
        "textblocks": {
          "name" : "textblocks",
          "type" : vx_data_textblock.t_textblocklist,
          "multi": false
        },
        "parent": {
          "name" : "parent",
          "type" : vx_data_textblock.t_textblock,
          "multi": false
        }
      },
      proplast      : {
        "name" : "parent",
        "type" : vx_data_textblock.t_textblock,
        "multi": false
      }
    }
    vx_data_textblock.e_textblock['vx_type'] = vx_data_textblock.t_textblock
    vx_data_textblock.e_textblock['vx_value'] = {}

    // (type textblocklist)
    vx_data_textblock.t_textblocklist['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblocklist['vx_value'] = {
      name          : "textblocklist",
      pkgname       : "vx/data/textblock",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_data_textblock.t_textblock],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_data_textblock.e_textblocklist['vx_type'] = vx_data_textblock.t_textblocklist

    // (const delimbracketcurly)
    Object.assign(vx_data_textblock.c_delimbracketcurly, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":name",
      "delimbracketcurly",
      ":starttext",
      "{",
      ":endtext",
      "}"
    ))

    // (const delimbracketsquare)
    Object.assign(vx_data_textblock.c_delimbracketsquare, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":name",
      "delimbracketsquare",
      ":starttext",
      "[",
      ":endtext",
      "]"
    ))

    // (const delimclose)
    Object.assign(vx_data_textblock.c_delimclose, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":name",
      "delimclose",
      ":starttext",
      "",
      ":endtext",
      ""
    ))

    // (const delimcomma)
    Object.assign(vx_data_textblock.c_delimcomma, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":name",
      "delimcomma",
      ":starttext",
      ",",
      ":endtext",
      ","
    ))

    // (const delimcomment)
    Object.assign(vx_data_textblock.c_delimcomment, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":name",
      "delimcomment",
      ":starttext",
      "//",
      ":endtext",
      "\n"
    ))

    // (const delimcommentblock)
    Object.assign(vx_data_textblock.c_delimcommentblock, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":name",
      "delimcommentblock",
      ":starttext",
      "/*",
      ":endtext",
      "*/"
    ))

    // (const delimline)
    Object.assign(vx_data_textblock.c_delimline, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":name",
      "delimline",
      ":starttext",
      "\n",
      ":endtext",
      "\n"
    ))

    // (const delimnonwhitespace)
    Object.assign(vx_data_textblock.c_delimnonwhitespace, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":name",
      "delimnonwhitespace",
      ":starttext",
      ":nonwhitespace",
      ":endtext",
      ":whitespace"
    ))

    // (const delimparen)
    Object.assign(vx_data_textblock.c_delimparen, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":name",
      "delimparen",
      ":starttext",
      "(",
      ":endtext",
      ")"
    ))

    // (const delimparenline)
    Object.assign(vx_data_textblock.c_delimparenline, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":name",
      "delimparenline",
      ":starttext",
      "\n(",
      ":endtext",
      ")\n"
    ))

    // (const delimquote)
    Object.assign(vx_data_textblock.c_delimquote, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":name",
      "delimquote",
      ":starttext",
      "\"",
      ":endtext",
      "\""
    ))

    // (const delimquoteblock)
    Object.assign(vx_data_textblock.c_delimquoteblock, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":name",
      "delimquoteblock",
      ":starttext",
      "`",
      ":endtext",
      "`"
    ))

    // (const delimspace)
    Object.assign(vx_data_textblock.c_delimspace, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":name",
      "delimspace",
      ":starttext",
      " ",
      ":endtext",
      " "
    ))

    // (const delimtext)
    Object.assign(vx_data_textblock.c_delimtext, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":name",
      "delimtext"
    ))

    // (const delimwhitespace)
    Object.assign(vx_data_textblock.c_delimwhitespace, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":name",
      "delimwhitespace",
      ":starttext",
      ":whitespace",
      ":endtext",
      ":nonwhitespace"
    ))

    // (func delim_first_from_delim_delim)
    vx_data_textblock.t_delim_first_from_delim_delim['vx_type'] = vx_core.t_type
    vx_data_textblock.t_delim_first_from_delim_delim['vx_value'] = {
      name          : "delim-first<-delim-delim",
      pkgname       : "vx/data/textblock",
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
      fn            : vx_data_textblock.f_delim_first_from_delim_delim
    }

    // (func delim_first_from_string_delimlist)
    vx_data_textblock.t_delim_first_from_string_delimlist['vx_type'] = vx_core.t_type
    vx_data_textblock.t_delim_first_from_string_delimlist['vx_value'] = {
      name          : "delim-first<-string-delimlist",
      pkgname       : "vx/data/textblock",
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
      fn            : vx_data_textblock.f_delim_first_from_string_delimlist
    }

    // (func delim_startpos_from_string_delim)
    vx_data_textblock.t_delim_startpos_from_string_delim['vx_type'] = vx_core.t_type
    vx_data_textblock.t_delim_startpos_from_string_delim['vx_value'] = {
      name          : "delim-startpos<-string-delim",
      pkgname       : "vx/data/textblock",
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
      fn            : vx_data_textblock.f_delim_startpos_from_string_delim
    }

    // (func delimlist_startpos_from_string_delimlist)
    vx_data_textblock.t_delimlist_startpos_from_string_delimlist['vx_type'] = vx_core.t_type
    vx_data_textblock.t_delimlist_startpos_from_string_delimlist['vx_value'] = {
      name          : "delimlist-startpos<-string-delimlist",
      pkgname       : "vx/data/textblock",
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
      fn            : vx_data_textblock.f_delimlist_startpos_from_string_delimlist
    }

    // (func stringlist_from_textblocklist)
    vx_data_textblock.t_stringlist_from_textblocklist['vx_type'] = vx_core.t_type
    vx_data_textblock.t_stringlist_from_textblocklist['vx_value'] = {
      name          : "stringlist<-textblocklist",
      pkgname       : "vx/data/textblock",
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
      fn            : vx_data_textblock.f_stringlist_from_textblocklist
    }

    // (func text_from_textblock)
    vx_data_textblock.t_text_from_textblock['vx_type'] = vx_core.t_type
    vx_data_textblock.t_text_from_textblock['vx_value'] = {
      name          : "text<-textblock",
      pkgname       : "vx/data/textblock",
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
      fn            : vx_data_textblock.f_text_from_textblock
    }

    // (func textblock_firstdelim_from_textblock_delimlist)
    vx_data_textblock.t_textblock_firstdelim_from_textblock_delimlist['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblock_firstdelim_from_textblock_delimlist['vx_value'] = {
      name          : "textblock-firstdelim<-textblock-delimlist",
      pkgname       : "vx/data/textblock",
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
      fn            : vx_data_textblock.f_textblock_firstdelim_from_textblock_delimlist
    }

    // (func textblock_startafter_from_string_delim)
    vx_data_textblock.t_textblock_startafter_from_string_delim['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblock_startafter_from_string_delim['vx_value'] = {
      name          : "textblock-startafter<-string-delim",
      pkgname       : "vx/data/textblock",
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
      fn            : vx_data_textblock.f_textblock_startafter_from_string_delim
    }

    // (func textblock_startbefore_from_string_delim)
    vx_data_textblock.t_textblock_startbefore_from_string_delim['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblock_startbefore_from_string_delim['vx_value'] = {
      name          : "textblock-startbefore<-string-delim",
      pkgname       : "vx/data/textblock",
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
      fn            : vx_data_textblock.f_textblock_startbefore_from_string_delim
    }

    // (func textblock_from_textblock_delim)
    vx_data_textblock.t_textblock_from_textblock_delim['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblock_from_textblock_delim['vx_value'] = {
      name          : "textblock<-textblock-delim",
      pkgname       : "vx/data/textblock",
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
      fn            : vx_data_textblock.f_textblock_from_textblock_delim
    }

    // (func textblocks_from_textblock)
    vx_data_textblock.t_textblocks_from_textblock['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblocks_from_textblock['vx_value'] = {
      name          : "textblocks<-textblock",
      pkgname       : "vx/data/textblock",
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
      fn            : vx_data_textblock.f_textblocks_from_textblock
    }

  }
}
