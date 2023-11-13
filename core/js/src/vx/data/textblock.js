'strict mode'

import vx_core from "../../vx/core.js"
import vx_collection from "../../vx/collection.js"
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
   * Constant: delimbracketangle
   * Angle Bracket Delimiter
   * {delim}
   */
  static c_delimbracketangle = {vx_type: vx_data_textblock.t_delim}

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
   * @function children_from_textblock
   * Returns the child textblocks from a given textblock.
   * @param  {textblock} textblock
   * @return {textblocklist}
   */
  static t_children_from_textblock = {}
  static e_children_from_textblock = {vx_type: vx_data_textblock.t_children_from_textblock}

  // (func children<-textblock)
  static f_children_from_textblock(textblock) {
    let output = vx_data_textblock.e_textblocklist
    output = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblocklist, "struct-2": vx_data_textblock.t_textblock}, textblock, ":children")
    return output
  }

  /**
   * @function delim_close_from_delim
   * Returns delim with a close delim added.
   * @param  {delim} delim
   * @return {delim}
   */
  static t_delim_close_from_delim = {}
  static e_delim_close_from_delim = {vx_type: vx_data_textblock.t_delim_close_from_delim}

  // (func delim-close<-delim)
  static f_delim_close_from_delim(delim) {
    let output = vx_data_textblock.e_delim
    output = vx_core.f_let(
      {"any-1": vx_data_textblock.t_delim},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const delimlist = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delimlist, "struct-2": vx_data_textblock.t_delim}, delim, ":delimlist")
        const endtext = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delim, ":endtext")
        const addlist = vx_core.f_if_2(
          {"any-1": vx_data_textblock.t_delimlist},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq("", endtext)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return delimlist})
          ),
          vx_core.f_else(
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(
              delimlist,
              vx_core.f_copy(
                vx_data_textblock.c_delimclose,
                ":starttext",
                endtext
              )
            )})
          )
        )
        return vx_core.f_if_2(
          {"any-1": vx_data_textblock.t_delim},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty_1(addlist)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return delim})
          ),
          vx_core.f_else(
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(delim, ":delimlist", addlist)})
          )
        )
      })
    )
    return output
  }

  /**
   * @function delim_first_from_delim_delim
   * Returns non-empty delim with lowest, non-negative startpos found in string.
   * @param  {delim} delim1
   * @param  {delim} delim2
   * @return {delim}
   */
  static t_delim_first_from_delim_delim = {}
  static e_delim_first_from_delim_delim = {vx_type: vx_data_textblock.t_delim_first_from_delim_delim}

  // (func delim-first<-delim-delim)
  static f_delim_first_from_delim_delim(delim1, delim2) {
    let output = vx_data_textblock.e_delim
    output = vx_core.f_let(
      {"any-1": vx_data_textblock.t_delim},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const pos1 = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_delim}, delim1, ":startpos")
        const pos2 = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_delim}, delim2, ":startpos")
        return vx_core.f_if_2(
          {"any-1": vx_data_textblock.t_delim},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_lt(pos2, 0)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return delim1})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_lt(pos1, 0)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return delim2})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty_1(delim2)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return delim1})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty_1(delim1)}),
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
   * @function delim_first_from_string_delimlist_offset
   * Returns delim with lowest startpos found in string.
   * @param  {string} text
   * @param  {delimlist} delimlist
   * @param  {int} start
   * @return {delim}
   */
  static t_delim_first_from_string_delimlist_offset = {}
  static e_delim_first_from_string_delimlist_offset = {vx_type: vx_data_textblock.t_delim_first_from_string_delimlist_offset}

  // (func delim-first<-string-delimlist-offset)
  static f_delim_first_from_string_delimlist_offset(text, delimlist, start) {
    let output = vx_data_textblock.e_delim
    output = vx_core.f_if_2(
      {"any-1": vx_data_textblock.t_delim},
      vx_core.f_then(
        vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty_1(delimlist)}),
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_empty(
          vx_data_textblock.t_delim
        )})
      ),
      vx_core.f_else(
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_let(
          {"any-1": vx_data_textblock.t_delim, "any-2": vx_data_textblock.t_delim, "list-2": vx_data_textblock.t_delimlist},
          [],
          vx_core.f_new(vx_core.t_any_from_func, () => {
            const resolvedlist = vx_data_textblock.f_delimlist_pos_from_string_delimlist_offset(text, delimlist, start)
            return vx_core.f_any_from_list_reduce(
              {"any-1": vx_data_textblock.t_delim, "any-2": vx_data_textblock.t_delim, "list-2": vx_data_textblock.t_delimlist},
              resolvedlist,
              vx_core.f_empty(
                vx_data_textblock.t_delim
              ),
              vx_core.f_new(vx_core.t_any_from_reduce, vx_data_textblock.t_delim_first_from_delim_delim)
            )
          })
        )})
      )
    )
    return output
  }

  /**
   * @function delim_pos_from_string_delim_offset
   * Return a delim with istart updated to position of first starttext.
   * @param  {string} text
   * @param  {delim} delim
   * @param  {int} start
   * @return {delim}
   */
  static t_delim_pos_from_string_delim_offset = {}
  static e_delim_pos_from_string_delim_offset = {vx_type: vx_data_textblock.t_delim_pos_from_string_delim_offset}

  // (func delim-pos<-string-delim-offset)
  static f_delim_pos_from_string_delim_offset(text, delim, start) {
    let output = vx_data_textblock.e_delim
    output = vx_core.f_let(
      {"any-1": vx_data_textblock.t_delim},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const find = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delim, ":starttext")
        const work = vx_type.f_string_from_string_start(text, start)
        const pos = vx_type.f_int_from_string_findkeyword(work, find)
        return vx_core.f_if_1(
          {"any-1": vx_data_textblock.t_delim},
          vx_core.f_eq(pos, -1),
          vx_core.f_copy(delim, ":startpos", -1),
          vx_core.f_copy(
            delim,
            ":startpos",
            vx_core.f_plus(pos, start)
          )
        )
      })
    )
    return output
  }

  /**
   * @function delimlist_pos_from_string_delimlist_offset
   * Returns a delimlist with each delim updated to position of first starttext.
   * @param  {string} text
   * @param  {delimlist} delimlist
   * @param  {int} start
   * @return {delimlist}
   */
  static t_delimlist_pos_from_string_delimlist_offset = {}
  static e_delimlist_pos_from_string_delimlist_offset = {vx_type: vx_data_textblock.t_delimlist_pos_from_string_delimlist_offset}

  // (func delimlist-pos<-string-delimlist-offset)
  static f_delimlist_pos_from_string_delimlist_offset(text, delimlist, start) {
    let output = vx_data_textblock.e_delimlist
    output = vx_core.f_list_from_list(
      {"any-1": vx_data_textblock.t_delim, "any-2": vx_data_textblock.t_delim, "list-1": vx_data_textblock.t_delimlist, "list-2": vx_data_textblock.t_delimlist},
      delimlist,
      vx_core.f_new(vx_core.t_any_from_any, (delim) => 
        vx_data_textblock.f_delim_pos_from_string_delim_offset(text, delim, start))
    )
    return output
  }

  /**
   * @function stringlist_from_textblocklist
   * Returns a stringlist from each (:text textblock).
   * @param  {textblocklist} textblocklist
   * @return {stringlist}
   */
  static t_stringlist_from_textblocklist = {}
  static e_stringlist_from_textblocklist = {vx_type: vx_data_textblock.t_stringlist_from_textblocklist}

  // (func stringlist<-textblocklist)
  static f_stringlist_from_textblocklist(textblocklist) {
    let output = vx_core.e_stringlist
    output = vx_core.f_list_from_list(
      {"any-1": vx_core.t_string, "any-2": vx_data_textblock.t_textblock, "list-1": vx_core.t_stringlist, "list-2": vx_data_textblock.t_textblocklist},
      textblocklist,
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

  // (func text<-textblock)
  static f_text_from_textblock(block) {
    let output = vx_core.e_string
    output = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_textblock}, block, ":text")
    return output
  }

  /**
   * @function textblock_addchild_from_textblock_find_child
   * Add the child to the given parent textblock.
   * @param  {textblock} textblockarg
   * @param  {textblock} find
   * @param  {textblock} child
   * @return {textblock}
   */
  static t_textblock_addchild_from_textblock_find_child = {}
  static e_textblock_addchild_from_textblock_find_child = {vx_type: vx_data_textblock.t_textblock_addchild_from_textblock_find_child}

  // (func textblock-addchild<-textblock-find-child)
  static f_textblock_addchild_from_textblock_find_child(textblockarg, find, child) {
    let output = vx_data_textblock.e_textblock
    output = vx_core.f_if_2(
      {"any-1": vx_data_textblock.t_textblock},
      vx_core.f_then(
        vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty_1(textblockarg)}),
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_empty(
          vx_data_textblock.t_textblock
        )})
      ),
      vx_core.f_then(
        vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_and_1(
          vx_core.f_eqeq(find, textblockarg)
        )}),
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(
          textblockarg,
          ":children",
          vx_core.f_copy(
            vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblocklist, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":children"),
            child
          )
        )})
      ),
      vx_core.f_else(
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(
          textblockarg,
          ":parent",
          vx_data_textblock.f_textblock_addchild_from_textblock_find_child(
            vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblock, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":parent"),
            find,
            child
          )
        )})
      )
    )
    return output
  }

  /**
   * @function textblock_delimnotfound
   * Returns a textblock when a delim is not found.
   * @param  {textblock} textblockin
   * @return {textblock}
   */
  static t_textblock_delimnotfound = {}
  static e_textblock_delimnotfound = {vx_type: vx_data_textblock.t_textblock_delimnotfound}

  // (func textblock-delimnotfound)
  static f_textblock_delimnotfound(textblockin) {
    let output = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      {"any-1": vx_data_textblock.t_textblock},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const delimin = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delim, "struct-2": vx_data_textblock.t_textblock}, textblockin, ":delim")
        const endtext = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delimin, ":endtext")
        const parent = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblock, "struct-2": vx_data_textblock.t_textblock}, textblockin, ":parent")
        const delimp = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delim, "struct-2": vx_data_textblock.t_textblock}, parent, ":delim")
        const delims = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delimlist, "struct-2": vx_data_textblock.t_delim}, delimp, ":delimlist")
        return vx_core.f_if_2(
          {"any-1": vx_data_textblock.t_textblock},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_ne("", endtext)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(
              parent,
              ":delimlist",
              vx_core.f_copy(
                delims,
                vx_core.f_copy(
                  textblockin,
                  ":parent",
                  vx_core.f_empty(
                    vx_data_textblock.t_textblock
                  ),
                  ":msg",
                  vx_core.f_msg_from_error(
                    vx_core.f_new(
                      vx_core.t_string,
                      "Close delim not found: ",
                      vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delimin, ":name")
                    )
                  )
                )
              )
            )})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq(
              parent,
              vx_core.f_empty(
                vx_data_textblock.t_textblock
              )
            )}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return textblockin})
          ),
          vx_core.f_else(
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_data_textblock.f_textblock_pop(textblockin)})
          )
        )
      })
    )
    return output
  }

  /**
   * @function textblock_findparent_from_textblock
   * Find a parent that accepts a child.
   * @param  {textblock} textblockarg
   * @return {textblock}
   */
  static t_textblock_findparent_from_textblock = {}
  static e_textblock_findparent_from_textblock = {vx_type: vx_data_textblock.t_textblock_findparent_from_textblock}

  // (func textblock-findparent<-textblock)
  static f_textblock_findparent_from_textblock(textblockarg) {
    let output = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      {"any-1": vx_data_textblock.t_textblock},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const delimcurr = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delim, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":delim")
        const parent = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblock, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":parent")
        const children = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblocklist, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":children")
        const starttext = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delimcurr, ":starttext")
        const endtext = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delimcurr, ":endtext")
        return vx_core.f_if_2(
          {"any-1": vx_data_textblock.t_textblock},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty_1(textblockarg)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_empty(
              vx_data_textblock.t_textblock
            )})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_and(
              vx_core.f_eq(starttext, ""),
              vx_core.f_eq(endtext, "")
            )}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return textblockarg})
          ),
          vx_core.f_else(
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_data_textblock.f_textblock_findparent_from_textblock(parent)})
          )
        )
      })
    )
    return output
  }

  /**
   * @function textblock_groupby_from_textblock_delim
   * Returns a textblock grouped by the given delim.
   * @param  {textblock} textblockarg
   * @param  {delim} delimarg
   * @return {textblock}
   */
  static t_textblock_groupby_from_textblock_delim = {}
  static e_textblock_groupby_from_textblock_delim = {vx_type: vx_data_textblock.t_textblock_groupby_from_textblock_delim}

  // (func textblock-groupby<-textblock-delim)
  static f_textblock_groupby_from_textblock_delim(textblockarg, delimarg) {
    let output = vx_data_textblock.e_textblock
    output = vx_core.f_new(
      vx_data_textblock.t_textblock,
      ":delim",
      delimarg
    )
    return output
  }

  /**
   * @function textblock_parse
   * Returns a fully parsed textblock from an initialized textblock.
   * @param  {textblock} textblock
   * @return {textblock}
   */
  static t_textblock_parse = {}
  static e_textblock_parse = {vx_type: vx_data_textblock.t_textblock_parse}

  // (func textblock-parse)
  static f_textblock_parse(textblock) {
    let output = vx_data_textblock.e_textblock
    output = vx_collection.f_any_from_for_until_loop(
      {"any-1": vx_data_textblock.t_textblock},
      textblock,
      vx_core.f_new(vx_core.t_boolean_from_any, (current) => 
        vx_core.f_is_empty_1(
          vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblock, "struct-2": vx_data_textblock.t_textblock}, current, ":parent")
        )),
      vx_core.f_new(vx_core.t_any_from_any, (current) => 
        vx_data_textblock.f_textblock_parse_one(current))
    )
    return output
  }

  /**
   * @function textblock_parse_one
   * Returns a textblock that has been parse a single level.
   * @param  {textblock} textblockin
   * @return {textblock}
   */
  static t_textblock_parse_one = {}
  static e_textblock_parse_one = {vx_type: vx_data_textblock.t_textblock_parse_one}

  // (func textblock-parse-one)
  static f_textblock_parse_one(textblockin) {
    let output = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      {"any-1": vx_data_textblock.t_textblock},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const delimin = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delim, "struct-2": vx_data_textblock.t_textblock}, textblockin, ":delim")
        const close = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delim, "struct-2": vx_data_textblock.t_textblock}, textblockin, ":close")
        const startpos = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_textblock}, textblockin, ":startpos")
        const curpos = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_textblock}, textblockin, ":curpos")
        const textin = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_textblock}, textblockin, ":text")
        const parent = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblock, "struct-2": vx_data_textblock.t_textblock}, textblockin, ":parent")
        const starttext = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delimin, ":starttext")
        const endtext = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delimin, ":endtext")
        const delimlistin = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delimlist, "struct-2": vx_data_textblock.t_delim}, delimin, ":delimlist")
        const tbchg = vx_core.f_copy(
          textblockin,
          ":endpos",
          vx_core.f_plus(
            startpos,
            vx_type.f_length_from_string(textin)
          )
        )
        const delimlistcl = vx_core.f_if_1(
          {"any-1": vx_data_textblock.t_delimlist},
          vx_core.f_is_empty_1(close),
          delimlistin,
          vx_core.f_copy(delimlistin, close)
        )
        const delimfirst = vx_data_textblock.f_delim_first_from_string_delimlist_offset(textin, delimlistcl, curpos)
        return vx_core.f_if_2(
          {"any-1": vx_data_textblock.t_textblock},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq("", textin)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return parent})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_and(
              vx_core.f_ne("", starttext),
              vx_core.f_eq("", endtext)
            )}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_data_textblock.f_textblock_push(tbchg)})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty_1(delimlistcl)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_if_2(
              {"any-1": vx_data_textblock.t_textblock},
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq(
                  parent,
                  vx_core.f_empty(
                    vx_data_textblock.t_textblock
                  )
                )}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return tbchg})
              ),
              vx_core.f_else(
                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_data_textblock.f_textblock_pop(tbchg)})
              )
            )})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq(
              delimfirst,
              vx_core.f_empty(
                vx_data_textblock.t_delim
              )
            )}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_data_textblock.f_textblock_delimnotfound(tbchg)})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq(
              vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delimfirst, ":name"),
              vx_core.f_any_from_struct(
                {"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim},
                vx_data_textblock.c_delimclose,
                ":name"
              )
            )}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_data_textblock.f_textblock_pop_from_textblock_delim(tbchg, delimfirst)})
          ),
          vx_core.f_else(
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_data_textblock.f_textblock_push_from_textblock_delim(tbchg, delimfirst)})
          )
        )
      })
    )
    return output
  }

  /**
   * @function textblock_parse_from_string_delim
   * Returns a fully parsed textblock from a string and delim.
   * @param  {string} text
   * @param  {delim} delim
   * @return {textblock}
   */
  static t_textblock_parse_from_string_delim = {}
  static e_textblock_parse_from_string_delim = {vx_type: vx_data_textblock.t_textblock_parse_from_string_delim}

  // (func textblock-parse<-string-delim)
  static f_textblock_parse_from_string_delim(text, delim) {
    let output = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      {"any-1": vx_data_textblock.t_textblock},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const textblockinit = vx_data_textblock.f_textblock_from_string_delim(text, delim)
        return vx_data_textblock.f_textblock_parse(textblockinit)
      })
    )
    return output
  }

  /**
   * @function textblock_pop
   * Returns the parent of a textblock with the current textblock added to textblocklist.
   * @param  {textblock} textblockarg
   * @return {textblock}
   */
  static t_textblock_pop = {}
  static e_textblock_pop = {vx_type: vx_data_textblock.t_textblock_pop}

  // (func textblock-pop)
  static f_textblock_pop(textblockarg) {
    let output = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      {"any-1": vx_data_textblock.t_textblock},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const parent = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblock, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":parent")
        const text = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":text")
        const startpos = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":startpos")
        const endpos = vx_core.f_plus(
          startpos,
          vx_type.f_length_from_string(text)
        )
        const delimpar = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delim, "struct-2": vx_data_textblock.t_textblock}, parent, ":delim")
        const child = vx_core.f_copy(
          textblockarg,
          ":endpos",
          endpos,
          ":delim",
          vx_core.f_empty(
            vx_data_textblock.t_delim
          ),
          ":parent",
          vx_core.f_empty(
            vx_data_textblock.t_textblock
          )
        )
        const parenttgt = vx_data_textblock.f_textblock_findparent_from_textblock(parent)
        return vx_data_textblock.f_textblock_addchild_from_textblock_find_child(parent, parenttgt, child)
      })
    )
    return output
  }

  /**
   * @function textblock_pop_from_textblock_delim
   * Returns the parent of a textblock with the current textblock added to textblocklist.
   * @param  {textblock} textblockarg
   * @param  {delim} delimarg
   * @return {textblock}
   */
  static t_textblock_pop_from_textblock_delim = {}
  static e_textblock_pop_from_textblock_delim = {vx_type: vx_data_textblock.t_textblock_pop_from_textblock_delim}

  // (func textblock-pop<-textblock-delim)
  static f_textblock_pop_from_textblock_delim(textblockarg, delimarg) {
    let output = vx_data_textblock.e_textblock
    output = vx_core.f_if_2(
      {"any-1": vx_data_textblock.t_textblock},
      vx_core.f_then(
        vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty_1(delimarg)}),
        vx_core.f_new(vx_core.t_any_from_func, () => {return textblockarg})
      ),
      vx_core.f_then(
        vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq(
          vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delimarg, ":name"),
          vx_core.f_any_from_struct(
            {"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim},
            vx_data_textblock.c_delimclose,
            ":name"
          )
        )}),
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_let(
          {"any-1": vx_data_textblock.t_textblock},
          [],
          vx_core.f_new(vx_core.t_any_from_func, () => {
            const parentcur = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblock, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":parent")
            const delimcur = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delim, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":delim")
            const starttext = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delimcur, ":starttext")
            const endtext = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delimcur, ":endtext")
            const delimpos = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_delim}, delimarg, ":startpos")
            const startpos = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":startpos")
            const startsub = vx_type.f_length_from_string(starttext)
            const endpos = vx_core.f_plus(
              delimpos,
              vx_type.f_length_from_string(endtext)
            )
            const endsub = delimpos
            const textcur = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":text")
            const textout = vx_type.f_string_from_string_start(textcur, endpos)
            const textsub = vx_type.f_string_from_string_start_end(textcur, startsub, endsub)
            const textdelim = vx_type.f_string_from_string_start_end(textcur, 0, endpos)
            const childchg = vx_core.f_copy(
              textblockarg,
              ":text",
              textdelim,
              ":endpos",
              vx_core.f_plus(startpos, endpos),
              ":curpos",
              0,
              ":delim",
              vx_core.f_copy(
                delimcur,
                ":startpos",
                0,
                ":endpos",
                0,
                ":delimlist",
                vx_core.f_empty(
                  vx_data_textblock.t_delimlist
                )
              ),
              ":close",
              vx_core.f_empty(
                vx_data_textblock.t_delim
              ),
              ":parent",
              vx_core.f_empty(
                vx_data_textblock.t_textblock
              ),
              ":children",
              vx_core.f_new(
                vx_data_textblock.t_textblocklist,
                vx_core.f_new(
                  vx_data_textblock.t_textblock,
                  ":text",
                  textsub,
                  ":startpos",
                  vx_core.f_plus(startpos, startsub),
                  ":endpos",
                  vx_core.f_plus(startpos, endsub),
                  ":curpos",
                  0
                )
              )
            )
            const parenttgt = vx_data_textblock.f_textblock_findparent_from_textblock(parentcur)
            const parentchg = vx_data_textblock.f_textblock_addchild_from_textblock_find_child(parentcur, parenttgt, childchg)
            return vx_core.f_new(
              vx_data_textblock.t_textblock,
              ":text",
              textout,
              ":delim",
              vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delim, "struct-2": vx_data_textblock.t_textblock}, parenttgt, ":delim"),
              ":startpos",
              vx_core.f_plus(startpos, endpos),
              ":parent",
              parentchg
            )
          })
        )})
      ),
      vx_core.f_else(
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_let(
          {"any-1": vx_data_textblock.t_textblock},
          [],
          vx_core.f_new(vx_core.t_any_from_func, () => {
            const parentcur = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblock, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":parent")
            const childrenpar = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblocklist, "struct-2": vx_data_textblock.t_textblock}, parentcur, ":children")
            const childchg = vx_core.f_copy(
              textblockarg,
              ":delim",
              delimarg,
              ":parent",
              vx_core.f_empty(
                vx_data_textblock.t_textblock
              )
            )
            const childrenchg = vx_core.f_copy(childrenpar, childchg)
            return vx_core.f_copy(parentcur, ":children", childrenchg)
          })
        )})
      )
    )
    return output
  }

  /**
   * @function textblock_push
   * Returns a a textblock using the textblocks current delim.
   * @param  {textblock} textblockin
   * @return {textblock}
   */
  static t_textblock_push = {}
  static e_textblock_push = {vx_type: vx_data_textblock.t_textblock_push}

  // (func textblock-push)
  static f_textblock_push(textblockin) {
    let output = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      {"any-1": vx_data_textblock.t_textblock},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const text = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_textblock}, textblockin, ":text")
        const delimcur = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delim, "struct-2": vx_data_textblock.t_textblock}, textblockin, ":delim")
        const offset = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_textblock}, textblockin, ":startpos")
        const starttext = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delimcur, ":starttext")
        const endtext = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delimcur, ":endtext")
        const startlen = vx_type.f_length_from_string(starttext)
        const issingle = vx_core.f_and(
          vx_core.f_ne("", starttext),
          vx_core.f_eq("", endtext)
        )
        const delimsplit = vx_core.f_if_1(
          {"any-1": vx_data_textblock.t_delim},
          issingle,
          vx_core.f_copy(
            delimcur,
            ":startpos",
            startlen,
            ":delimlist",
            vx_core.f_empty(
              vx_data_textblock.t_delimlist
            )
          ),
          delimcur
        )
        const delimchg = vx_core.f_if_1(
          {"any-1": vx_data_textblock.t_delim},
          issingle,
          vx_core.f_copy(delimsplit, ":startpos", 0),
          delimsplit
        )
        const tbleft = vx_data_textblock.f_textblock_startleft_from_string_delim_offset(text, delimsplit, offset)
        const tbright = vx_data_textblock.f_textblock_startright_from_string_delim_offset(text, delimsplit, offset)
        const tbchg = vx_core.f_copy(tbleft, ":delim", delimchg)
        const parent = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblock, "struct-2": vx_data_textblock.t_textblock}, textblockin, ":parent")
        const parenttgt = vx_data_textblock.f_textblock_findparent_from_textblock(parent)
        const parentchg = vx_data_textblock.f_textblock_addchild_from_textblock_find_child(parent, parenttgt, tbchg)
        const delimright = vx_core.f_if_1(
          {"any-1": vx_data_textblock.t_delim},
          issingle,
          vx_core.f_new(
            vx_data_textblock.t_delim,
            ":delimlist",
            vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delimlist, "struct-2": vx_data_textblock.t_delim}, delimcur, ":delimlist")
          ),
          vx_core.f_empty(
            vx_data_textblock.t_delim
          )
        )
        return vx_core.f_copy(tbright, ":curpos", 0, ":delim", delimright, ":parent", parentchg)
      })
    )
    return output
  }

  /**
   * @function textblock_push_from_textblock_delim
   * Returns the parent of a textblock with the current textblock added to textblocklist.
   * @param  {textblock} textblockin
   * @param  {delim} delimin
   * @return {textblock}
   */
  static t_textblock_push_from_textblock_delim = {}
  static e_textblock_push_from_textblock_delim = {vx_type: vx_data_textblock.t_textblock_push_from_textblock_delim}

  // (func textblock-push<-textblock-delim)
  static f_textblock_push_from_textblock_delim(textblockin, delimin) {
    let output = vx_data_textblock.e_textblock
    output = vx_core.f_if_2(
      {"any-1": vx_data_textblock.t_textblock},
      vx_core.f_then(
        vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty_1(delimin)}),
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_data_textblock.f_textblock_push(textblockin)})
      ),
      vx_core.f_else(
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_let(
          {"any-1": vx_data_textblock.t_textblock},
          [],
          vx_core.f_new(vx_core.t_any_from_func, () => {
            const text = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_textblock}, textblockin, ":text")
            const offset = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_textblock}, textblockin, ":startpos")
            const delimcur = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delim, "struct-2": vx_data_textblock.t_textblock}, textblockin, ":delim")
            const parent = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblock, "struct-2": vx_data_textblock.t_textblock}, textblockin, ":parent")
            const startpos = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_delim}, delimin, ":startpos")
            const starttext = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delimin, ":starttext")
            const endtext = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delimin, ":endtext")
            const issingle = vx_core.f_and(
              vx_core.f_ne("", starttext),
              vx_core.f_eq("", endtext)
            )
            const tbleft = vx_data_textblock.f_textblock_startleft_from_string_delim_offset(text, delimin, offset)
            const delimsr = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delimlist, "struct-2": vx_data_textblock.t_delim}, delimcur, ":delimlist")
            const delimr = vx_core.f_if_1(
              {"any-1": vx_data_textblock.t_delim},
              issingle,
              vx_core.f_copy(delimin, ":delimlist", delimsr),
              delimin
            )
            const tbright = vx_data_textblock.f_textblock_startright_from_string_delim_offset(text, delimr, offset)
            const tbparent = vx_core.f_copy(
              tbright,
              ":parent",
              vx_core.f_if_1(
                {"any-1": vx_data_textblock.t_textblock},
                vx_core.f_is_empty_1(parent),
                textblockin,
                parent
              )
            )
            const delims = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delimlist, "struct-2": vx_data_textblock.t_delim}, delimin, ":delimlist")
            const delimchg = vx_core.f_if_1(
              {"any-1": vx_data_textblock.t_delim},
              vx_core.f_is_empty_1(delims),
              vx_core.f_empty(
                vx_data_textblock.t_delim
              ),
              vx_core.f_new(
                vx_data_textblock.t_delim,
                ":delimlist",
                delims
              )
            )
            return vx_core.f_if_2(
              {"any-1": vx_data_textblock.t_textblock},
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq(0, startpos)}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return tbparent})
              ),
              vx_core.f_else(
                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(tbleft, ":delim", delimchg, ":parent", tbparent)})
              )
            )
          })
        )})
      )
    )
    return output
  }

  /**
   * @function textblock_startleft_from_string_delim_offset
   * Returns a textblock constructed from the text before the current delimiter start.
   * @param  {string} text
   * @param  {delim} delim
   * @param  {int} offset
   * @return {textblock}
   */
  static t_textblock_startleft_from_string_delim_offset = {}
  static e_textblock_startleft_from_string_delim_offset = {vx_type: vx_data_textblock.t_textblock_startleft_from_string_delim_offset}

  // (func textblock-startleft<-string-delim-offset)
  static f_textblock_startleft_from_string_delim_offset(text, delim, offset) {
    let output = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      {"any-1": vx_data_textblock.t_textblock},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const startpos = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_delim}, delim, ":startpos")
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
              vx_type.f_string_from_string_start_end(text, 0, startpos),
              ":startpos",
              offset,
              ":endpos",
              vx_core.f_plus(offset, startpos),
              ":curpos",
              0
            )})
          )
        )
      })
    )
    return output
  }

  /**
   * @function textblock_startright_from_string_delim_offset
   * Returns a textblock constructed from the text after the current delimiter start.
   * @param  {string} text
   * @param  {delim} delimin
   * @param  {int} offset
   * @return {textblock}
   */
  static t_textblock_startright_from_string_delim_offset = {}
  static e_textblock_startright_from_string_delim_offset = {vx_type: vx_data_textblock.t_textblock_startright_from_string_delim_offset}

  // (func textblock-startright<-string-delim-offset)
  static f_textblock_startright_from_string_delim_offset(text, delimin, offset) {
    let output = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      {"any-1": vx_data_textblock.t_textblock},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const startpos = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_delim}, delimin, ":startpos")
        const starttext = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delimin, ":starttext")
        const endtext = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delimin, ":endtext")
        const delimlist = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delimlist, "struct-2": vx_data_textblock.t_delim}, delimin, ":delimlist")
        const close = vx_core.f_if_2(
          {"any-1": vx_data_textblock.t_delim},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq(endtext, "")}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_empty(
              vx_data_textblock.t_delim
            )})
          ),
          vx_core.f_else(
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(
              vx_data_textblock.c_delimclose,
              ":starttext",
              endtext
            )})
          )
        )
        const delimlen = vx_type.f_length_from_string(starttext)
        const curpos = delimlen
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
              vx_type.f_string_from_string_start(text, startpos),
              ":startpos",
              vx_core.f_plus(offset, startpos),
              ":curpos",
              curpos,
              ":delim",
              delimin,
              ":close",
              close
            )})
          )
        )
      })
    )
    return output
  }

  /**
   * @function textblock_from_string_delim
   * Returns a textblock from a string and delim.
   * @param  {string} text
   * @param  {delim} delim
   * @return {textblock}
   */
  static t_textblock_from_string_delim = {}
  static e_textblock_from_string_delim = {vx_type: vx_data_textblock.t_textblock_from_string_delim}

  // (func textblock<-string-delim)
  static f_textblock_from_string_delim(text, delim) {
    let output = vx_data_textblock.e_textblock
    output = vx_core.f_new(
      vx_data_textblock.t_textblock,
      ":text",
      text,
      ":delim",
      delim,
      ":startpos",
      0,
      ":endpos",
      vx_type.f_length_from_string(text)
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

  // (func textblock<-textblock-delim)
  static f_textblock_from_textblock_delim(textblock, delim) {
    let output = vx_data_textblock.e_textblock
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
    "children<-textblock": vx_data_textblock.e_children_from_textblock,
    "delim-close<-delim": vx_data_textblock.e_delim_close_from_delim,
    "delim-first<-delim-delim": vx_data_textblock.e_delim_first_from_delim_delim,
    "delim-first<-string-delimlist-offset": vx_data_textblock.e_delim_first_from_string_delimlist_offset,
    "delim-pos<-string-delim-offset": vx_data_textblock.e_delim_pos_from_string_delim_offset,
    "delimlist-pos<-string-delimlist-offset": vx_data_textblock.e_delimlist_pos_from_string_delimlist_offset,
    "stringlist<-textblocklist": vx_data_textblock.e_stringlist_from_textblocklist,
    "text<-textblock": vx_data_textblock.e_text_from_textblock,
    "textblock-addchild<-textblock-find-child": vx_data_textblock.e_textblock_addchild_from_textblock_find_child,
    "textblock-delimnotfound": vx_data_textblock.e_textblock_delimnotfound,
    "textblock-findparent<-textblock": vx_data_textblock.e_textblock_findparent_from_textblock,
    "textblock-groupby<-textblock-delim": vx_data_textblock.e_textblock_groupby_from_textblock_delim,
    "textblock-parse": vx_data_textblock.e_textblock_parse,
    "textblock-parse-one": vx_data_textblock.e_textblock_parse_one,
    "textblock-parse<-string-delim": vx_data_textblock.e_textblock_parse_from_string_delim,
    "textblock-pop": vx_data_textblock.e_textblock_pop,
    "textblock-pop<-textblock-delim": vx_data_textblock.e_textblock_pop_from_textblock_delim,
    "textblock-push": vx_data_textblock.e_textblock_push,
    "textblock-push<-textblock-delim": vx_data_textblock.e_textblock_push_from_textblock_delim,
    "textblock-startleft<-string-delim-offset": vx_data_textblock.e_textblock_startleft_from_string_delim_offset,
    "textblock-startright<-string-delim-offset": vx_data_textblock.e_textblock_startright_from_string_delim_offset,
    "textblock<-string-delim": vx_data_textblock.e_textblock_from_string_delim,
    "textblock<-textblock-delim": vx_data_textblock.e_textblock_from_textblock_delim
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
        "curpos": {
          "name" : "curpos",
          "type" : vx_core.t_int,
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
        "close": {
          "name" : "close",
          "type" : vx_data_textblock.t_delim,
          "multi": false
        },
        "parent": {
          "name" : "parent",
          "type" : vx_data_textblock.t_textblock,
          "multi": false
        },
        "children": {
          "name" : "children",
          "type" : vx_data_textblock.t_textblocklist,
          "multi": false
        }
      },
      proplast      : {
        "name" : "children",
        "type" : vx_data_textblock.t_textblocklist,
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

    // (const delimbracketangle)
    Object.assign(vx_data_textblock.c_delimbracketangle, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":name",
      "delimbracketangle",
      ":starttext",
      "<",
      ":endtext",
      ">"
    ))

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

    // (const delimquote)
    Object.assign(vx_data_textblock.c_delimquote, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":name",
      "delimquote",
      ":starttext",
      vx_core.c_quote,
      ":endtext",
      vx_core.c_quote
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

    // (func children<-textblock)
    vx_data_textblock.t_children_from_textblock['vx_type'] = vx_core.t_type
    vx_data_textblock.t_children_from_textblock['vx_value'] = {
      name          : "children<-textblock",
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
      fn            : vx_data_textblock.f_children_from_textblock
    }

    // (func delim-close<-delim)
    vx_data_textblock.t_delim_close_from_delim['vx_type'] = vx_core.t_type
    vx_data_textblock.t_delim_close_from_delim['vx_value'] = {
      name          : "delim-close<-delim",
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
      fn            : vx_data_textblock.f_delim_close_from_delim
    }

    // (func delim-first<-delim-delim)
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

    // (func delim-first<-string-delimlist-offset)
    vx_data_textblock.t_delim_first_from_string_delimlist_offset['vx_type'] = vx_core.t_type
    vx_data_textblock.t_delim_first_from_string_delimlist_offset['vx_value'] = {
      name          : "delim-first<-string-delimlist-offset",
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
      fn            : vx_data_textblock.f_delim_first_from_string_delimlist_offset
    }

    // (func delim-pos<-string-delim-offset)
    vx_data_textblock.t_delim_pos_from_string_delim_offset['vx_type'] = vx_core.t_type
    vx_data_textblock.t_delim_pos_from_string_delim_offset['vx_value'] = {
      name          : "delim-pos<-string-delim-offset",
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
      fn            : vx_data_textblock.f_delim_pos_from_string_delim_offset
    }

    // (func delimlist-pos<-string-delimlist-offset)
    vx_data_textblock.t_delimlist_pos_from_string_delimlist_offset['vx_type'] = vx_core.t_type
    vx_data_textblock.t_delimlist_pos_from_string_delimlist_offset['vx_value'] = {
      name          : "delimlist-pos<-string-delimlist-offset",
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
      fn            : vx_data_textblock.f_delimlist_pos_from_string_delimlist_offset
    }

    // (func stringlist<-textblocklist)
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

    // (func text<-textblock)
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

    // (func textblock-addchild<-textblock-find-child)
    vx_data_textblock.t_textblock_addchild_from_textblock_find_child['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblock_addchild_from_textblock_find_child['vx_value'] = {
      name          : "textblock-addchild<-textblock-find-child",
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
      fn            : vx_data_textblock.f_textblock_addchild_from_textblock_find_child
    }

    // (func textblock-delimnotfound)
    vx_data_textblock.t_textblock_delimnotfound['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblock_delimnotfound['vx_value'] = {
      name          : "textblock-delimnotfound",
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
      fn            : vx_data_textblock.f_textblock_delimnotfound
    }

    // (func textblock-findparent<-textblock)
    vx_data_textblock.t_textblock_findparent_from_textblock['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblock_findparent_from_textblock['vx_value'] = {
      name          : "textblock-findparent<-textblock",
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
      fn            : vx_data_textblock.f_textblock_findparent_from_textblock
    }

    // (func textblock-groupby<-textblock-delim)
    vx_data_textblock.t_textblock_groupby_from_textblock_delim['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblock_groupby_from_textblock_delim['vx_value'] = {
      name          : "textblock-groupby<-textblock-delim",
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
      fn            : vx_data_textblock.f_textblock_groupby_from_textblock_delim
    }

    // (func textblock-parse)
    vx_data_textblock.t_textblock_parse['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblock_parse['vx_value'] = {
      name          : "textblock-parse",
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
      fn            : vx_data_textblock.f_textblock_parse
    }

    // (func textblock-parse-one)
    vx_data_textblock.t_textblock_parse_one['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblock_parse_one['vx_value'] = {
      name          : "textblock-parse-one",
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
      fn            : vx_data_textblock.f_textblock_parse_one
    }

    // (func textblock-parse<-string-delim)
    vx_data_textblock.t_textblock_parse_from_string_delim['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblock_parse_from_string_delim['vx_value'] = {
      name          : "textblock-parse<-string-delim",
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
      fn            : vx_data_textblock.f_textblock_parse_from_string_delim
    }

    // (func textblock-pop)
    vx_data_textblock.t_textblock_pop['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblock_pop['vx_value'] = {
      name          : "textblock-pop",
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
      fn            : vx_data_textblock.f_textblock_pop
    }

    // (func textblock-pop<-textblock-delim)
    vx_data_textblock.t_textblock_pop_from_textblock_delim['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblock_pop_from_textblock_delim['vx_value'] = {
      name          : "textblock-pop<-textblock-delim",
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
      fn            : vx_data_textblock.f_textblock_pop_from_textblock_delim
    }

    // (func textblock-push)
    vx_data_textblock.t_textblock_push['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblock_push['vx_value'] = {
      name          : "textblock-push",
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
      fn            : vx_data_textblock.f_textblock_push
    }

    // (func textblock-push<-textblock-delim)
    vx_data_textblock.t_textblock_push_from_textblock_delim['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblock_push_from_textblock_delim['vx_value'] = {
      name          : "textblock-push<-textblock-delim",
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
      fn            : vx_data_textblock.f_textblock_push_from_textblock_delim
    }

    // (func textblock-startleft<-string-delim-offset)
    vx_data_textblock.t_textblock_startleft_from_string_delim_offset['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblock_startleft_from_string_delim_offset['vx_value'] = {
      name          : "textblock-startleft<-string-delim-offset",
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
      fn            : vx_data_textblock.f_textblock_startleft_from_string_delim_offset
    }

    // (func textblock-startright<-string-delim-offset)
    vx_data_textblock.t_textblock_startright_from_string_delim_offset['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblock_startright_from_string_delim_offset['vx_value'] = {
      name          : "textblock-startright<-string-delim-offset",
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
      fn            : vx_data_textblock.f_textblock_startright_from_string_delim_offset
    }

    // (func textblock<-string-delim)
    vx_data_textblock.t_textblock_from_string_delim['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblock_from_string_delim['vx_value'] = {
      name          : "textblock<-string-delim",
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
      fn            : vx_data_textblock.f_textblock_from_string_delim
    }

    // (func textblock<-textblock-delim)
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

  }
}
