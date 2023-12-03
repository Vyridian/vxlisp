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
  static c_delimbracketangle = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/data/textblock', name: 'delimbracketangle'}}

  /**
   * Constant: delimbracketcurly
   * Curly Bracket Delimiter
   * {delim}
   */
  static c_delimbracketcurly = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/data/textblock', name: 'delimbracketcurly'}}

  /**
   * Constant: delimbracketsquare
   * Square Bracket Delimiter
   * {delim}
   */
  static c_delimbracketsquare = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/data/textblock', name: 'delimbracketsquare'}}

  /**
   * Constant: delimclose
   * A placeholder delimiter used to mark the close of whatever is the current delimiter.
   * {delim}
   */
  static c_delimclose = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/data/textblock', name: 'delimclose'}}

  /**
   * Constant: delimclosing
   * A placeholder delimiter used to mark the closing of whatever is the current delimiter.
   * {delim}
   */
  static c_delimclosing = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/data/textblock', name: 'delimclosing'}}

  /**
   * Constant: delimcomma
   * Comma Delimiter
   * {delim}
   */
  static c_delimcomma = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/data/textblock', name: 'delimcomma'}}

  /**
   * Constant: delimcomment
   * Comment Delimiter
   * {delim}
   */
  static c_delimcomment = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/data/textblock', name: 'delimcomment'}}

  /**
   * Constant: delimcommentblock
   * Block Comment Delimiter
   * {delim}
   */
  static c_delimcommentblock = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/data/textblock', name: 'delimcommentblock'}}

  /**
   * Constant: delimline
   * New Line Delimiter
   * {delim}
   */
  static c_delimline = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/data/textblock', name: 'delimline'}}

  /**
   * Constant: delimlisttest1
   * A delimiter used for test suite
   * {delimlist}
   */
  static c_delimlisttest1 = Object.assign([], {vx_type: vx_data_textblock.t_delimlist, vx_constdef: {pkgname: 'vx/data/textblock', name: 'delimlisttest1'}})

  /**
   * Constant: delimlisttest2
   * A delimiter used for test suite
   * {delimlist}
   */
  static c_delimlisttest2 = Object.assign([], {vx_type: vx_data_textblock.t_delimlist, vx_constdef: {pkgname: 'vx/data/textblock', name: 'delimlisttest2'}})

  /**
   * Constant: delimlisttest3
   * A delimiter used for test suite
   * {delimlist}
   */
  static c_delimlisttest3 = Object.assign([], {vx_type: vx_data_textblock.t_delimlist, vx_constdef: {pkgname: 'vx/data/textblock', name: 'delimlisttest3'}})

  /**
   * Constant: delimnonwhitespace
   * Placeholder for delimited non-whitespace
   * {delim}
   */
  static c_delimnonwhitespace = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/data/textblock', name: 'delimnonwhitespace'}}

  /**
   * Constant: delimparen
   * Parenthesis Delimiter
   * {delim}
   */
  static c_delimparen = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/data/textblock', name: 'delimparen'}}

  /**
   * Constant: delimquote
   * Quote Delimiter
   * {delim}
   */
  static c_delimquote = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/data/textblock', name: 'delimquote'}}

  /**
   * Constant: delimquoteblock
   * Block Quote Delimiter
   * {delim}
   */
  static c_delimquoteblock = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/data/textblock', name: 'delimquoteblock'}}

  /**
   * Constant: delimspace
   * Space Delimiter
   * {delim}
   */
  static c_delimspace = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/data/textblock', name: 'delimspace'}}

  /**
   * Constant: delimtest1
   * A delimiter used for test suite
   * {delim}
   */
  static c_delimtest1 = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/data/textblock', name: 'delimtest1'}}

  /**
   * Constant: delimtest2
   * A delimiter used for test suite
   * {delim}
   */
  static c_delimtest2 = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/data/textblock', name: 'delimtest2'}}

  /**
   * Constant: delimtest3
   * A delimiter used for test suite
   * {delim}
   */
  static c_delimtest3 = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/data/textblock', name: 'delimtest3'}}

  /**
   * Constant: delimtext
   * Placeholder for delimited text
   * {delim}
   */
  static c_delimtext = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/data/textblock', name: 'delimtext'}}

  /**
   * Constant: delimwhitespace
   * Placeholder for delimited whitespace
   * {delim}
   */
  static c_delimwhitespace = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/data/textblock', name: 'delimwhitespace'}}

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
        const pos1 = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_delim}, delim1, ":pos")
        const pos2 = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_delim}, delim2, ":pos")
        return vx_core.f_if_2(
          {"any-1": vx_data_textblock.t_delim},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq(0, pos2)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return delim1})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq(0, pos1)}),
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
   * @function delim_first_from_string_delimlist
   * Returns delim with lowest startpos found in string.
   * @param  {string} text
   * @param  {delimlist} delimlist
   * @return {delim}
   */
  static t_delim_first_from_string_delimlist = {}
  static e_delim_first_from_string_delimlist = {vx_type: vx_data_textblock.t_delim_first_from_string_delimlist}

  // (func delim-first<-string-delimlist)
  static f_delim_first_from_string_delimlist(text, delimlist) {
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
            const resolvedlist = vx_data_textblock.f_delimlist_pos_from_string_delimlist(text, delimlist)
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
   * @function delim_pos_from_string_delim
   * Return a delim with istart updated to position of first starttext.
   * @param  {string} text
   * @param  {delim} delim
   * @return {delim}
   */
  static t_delim_pos_from_string_delim = {}
  static e_delim_pos_from_string_delim = {vx_type: vx_data_textblock.t_delim_pos_from_string_delim}

  // (func delim-pos<-string-delim)
  static f_delim_pos_from_string_delim(text, delim) {
    let output = vx_data_textblock.e_delim
    output = vx_core.f_let(
      {"any-1": vx_data_textblock.t_delim},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const find = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delim, ":starttext")
        const pos = vx_type.f_int_from_string_findkeyword(text, find)
        return vx_core.f_if_1(
          {"any-1": vx_data_textblock.t_delim},
          vx_core.f_eq(pos, 0),
          delim,
          vx_core.f_copy(delim, ":pos", pos)
        )
      })
    )
    return output
  }

  /**
   * @function delimlist_pos_from_string_delimlist
   * Returns a delimlist with each delim updated to position of first starttext.
   * @param  {string} text
   * @param  {delimlist} delimlist
   * @return {delimlist}
   */
  static t_delimlist_pos_from_string_delimlist = {}
  static e_delimlist_pos_from_string_delimlist = {vx_type: vx_data_textblock.t_delimlist_pos_from_string_delimlist}

  // (func delimlist-pos<-string-delimlist)
  static f_delimlist_pos_from_string_delimlist(text, delimlist) {
    let output = vx_data_textblock.e_delimlist
    output = vx_core.f_list_from_list(
      {"any-1": vx_data_textblock.t_delim, "any-2": vx_data_textblock.t_delim, "list-1": vx_data_textblock.t_delimlist, "list-2": vx_data_textblock.t_delimlist},
      delimlist,
      vx_core.f_new(vx_core.t_any_from_any, (delim) => 
        vx_data_textblock.f_delim_pos_from_string_delim(text, delim))
    )
    return output
  }

  /**
   * @function is_close
   * Return true if the given delim is a close delim.
   * @param  {delim} delimarg
   * @return {boolean}
   */
  static t_is_close = {}
  static e_is_close = {vx_type: vx_data_textblock.t_is_close}

  // (func is-close)
  static f_is_close(delimarg) {
    let output = vx_core.e_boolean
    output = vx_core.f_eq(
      vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delimarg, ":name"),
      vx_core.f_any_from_struct(
        {"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim},
        vx_data_textblock.c_delimclose,
        ":name"
      )
    )
    return output
  }

  /**
   * @function is_single
   * Return true if the given delim is a single text delim.
   * @param  {delim} delimarg
   * @return {boolean}
   */
  static t_is_single = {}
  static e_is_single = {vx_type: vx_data_textblock.t_is_single}

  // (func is-single)
  static f_is_single(delimarg) {
    let output = vx_core.e_boolean
    output = vx_core.f_and(
      vx_core.f_ne(
        "",
        vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delimarg, ":starttext")
      ),
      vx_core.f_eq(
        "",
        vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delimarg, ":endtext")
      )
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
   * @param  {textblock} textblockarg
   * @return {textblock}
   */
  static t_textblock_delimnotfound = {}
  static e_textblock_delimnotfound = {vx_type: vx_data_textblock.t_textblock_delimnotfound}

  // (func textblock-delimnotfound)
  static f_textblock_delimnotfound(textblockarg) {
    let output = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      {"any-1": vx_data_textblock.t_textblock},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const text = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":text")
        const delima = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delim, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":delim")
        const close = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delim, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":close")
        const parent = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblock, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":parent")
        const delimp = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delim, "struct-2": vx_data_textblock.t_textblock}, parent, ":delim")
        const delims = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delimlist, "struct-2": vx_data_textblock.t_delim}, delimp, ":delimlist")
        return vx_core.f_if_2(
          {"any-1": vx_data_textblock.t_textblock},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_not(
              vx_core.f_is_empty_1(close)
            )}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(
              parent,
              ":delimlist",
              vx_core.f_copy(
                delims,
                vx_core.f_copy(
                  textblockarg,
                  ":parent",
                  vx_core.f_empty(
                    vx_data_textblock.t_textblock
                  ),
                  ":msg",
                  vx_core.f_msg_from_error(
                    vx_core.f_new(
                      vx_core.t_string,
                      "Close delim not found: ",
                      vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delima, ":name")
                    )
                  )
                )
              )
            )})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty_1(parent)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return textblockarg})
          ),
          vx_core.f_else(
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_let(
              {"any-1": vx_data_textblock.t_textblock},
              [],
              vx_core.f_new(vx_core.t_any_from_func, () => {
                const delimchg = vx_core.f_if_1(
                  {"any-1": vx_data_textblock.t_delim},
                  vx_core.f_is_empty_1(
                    vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delimlist, "struct-2": vx_data_textblock.t_delim}, delima, ":delimlist")
                  ),
                  delima,
                  vx_core.f_copy(
                    delima,
                    ":delimlist",
                    vx_core.f_empty(
                      vx_data_textblock.t_delimlist
                    )
                  )
                )
                const child = vx_core.f_if_1(
                  {"any-1": vx_data_textblock.t_textblock},
                  vx_core.f_eq("", text),
                  vx_core.f_empty(
                    vx_data_textblock.t_textblock
                  ),
                  vx_core.f_copy(
                    textblockarg,
                    ":delim",
                    delimchg,
                    ":parent",
                    vx_core.f_empty(
                      vx_data_textblock.t_textblock
                    )
                  )
                )
                const find = vx_data_textblock.f_textblock_findparent_from_textblock(parent)
                const closef = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delim, "struct-2": vx_data_textblock.t_textblock}, find, ":close")
                const closing = vx_core.f_if(
                  {"any-1": vx_core.t_boolean},
                  vx_core.f_eqeq(
                    closef,
                    vx_data_textblock.c_delimclosing
                  ),
                  true
                )
                return vx_core.f_if_2(
                  {"any-1": vx_data_textblock.t_textblock},
                  vx_core.f_then(
                    vx_core.f_new(vx_core.t_boolean_from_func, () => {return closing}),
                    vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_let(
                      {"any-1": vx_data_textblock.t_textblock},
                      [],
                      vx_core.f_new(vx_core.t_any_from_func, () => {
                        const parent2 = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblock, "struct-2": vx_data_textblock.t_textblock}, find, ":parent")
                        const find2 = vx_data_textblock.f_textblock_findparent_from_textblock(parent2)
                        const children1 = vx_core.f_if_1(
                          {"any-1": vx_data_textblock.t_textblocklist},
                          vx_core.f_is_empty_1(child),
                          vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblocklist, "struct-2": vx_data_textblock.t_textblock}, find, ":children"),
                          vx_core.f_copy(
                            vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblocklist, "struct-2": vx_data_textblock.t_textblock}, find, ":children"),
                            child
                          )
                        )
                        const replace1 = vx_core.f_copy(
                          find,
                          ":close",
                          vx_core.f_empty(
                            vx_data_textblock.t_delim
                          ),
                          ":parent",
                          vx_core.f_empty(
                            vx_data_textblock.t_textblock
                          ),
                          ":children",
                          children1
                        )
                        return vx_core.f_if_2(
                          {"any-1": vx_data_textblock.t_textblock},
                          vx_core.f_then(
                            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty_1(find2)}),
                            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(
                              parent,
                              ":parent",
                              vx_core.f_copy(
                                parent2,
                                ":children",
                                vx_core.f_new(
                                  vx_data_textblock.t_textblocklist,
                                  replace1
                                )
                              )
                            )})
                          ),
                          vx_core.f_else(
                            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_let(
                              {"any-1": vx_data_textblock.t_textblock},
                              [],
                              vx_core.f_new(vx_core.t_any_from_func, () => {
                                const children2 = vx_core.f_copy(
                                  vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblocklist, "struct-2": vx_data_textblock.t_textblock}, find2, ":children"),
                                  replace1
                                )
                                const replace2 = vx_core.f_copy(
                                  find2,
                                  ":close",
                                  vx_core.f_empty(
                                    vx_data_textblock.t_delim
                                  ),
                                  ":children",
                                  children2
                                )
                                const replace = vx_data_textblock.f_textblock_replace_from_textblock_find_replace(parent2, find2, replace2)
                                return vx_data_textblock.f_textblock_replace_from_textblock_find_replace(parent, find, replace)
                              })
                            )})
                          )
                        )
                      })
                    )})
                  ),
                  vx_core.f_then(
                    vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty_1(child)}),
                    vx_core.f_new(vx_core.t_any_from_func, () => {return parent})
                  ),
                  vx_core.f_else(
                    vx_core.f_new(vx_core.t_any_from_func, () => {return vx_data_textblock.f_textblock_addchild_from_textblock_find_child(parent, find, child)})
                  )
                )
              })
            )})
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
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_or(
              vx_core.f_is_empty_1(parent),
              vx_core.f_and(
                vx_core.f_ne("", starttext),
                vx_core.f_ne("", endtext)
              )
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
   * @function textblock_init
   * Returns a textblock ready for parsing.
   * @param  {textblock} textblockarg
   * @return {textblock}
   */
  static t_textblock_init = {}
  static e_textblock_init = {vx_type: vx_data_textblock.t_textblock_init}

  // (func textblock-init)
  static f_textblock_init(textblockarg) {
    let output = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      {"any-1": vx_data_textblock.t_textblock},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const text = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":text")
        const startpos = vx_core.f_if_1(
          {"any-1": vx_core.t_int},
          vx_core.f_eq("", text),
          0,
          1
        )
        const endpos = vx_core.f_if_1(
          {"any-1": vx_core.t_int},
          vx_core.f_eq("", text),
          0,
          vx_type.f_length_from_string(text)
        )
        return vx_core.f_copy(
          textblockarg,
          ":startpos",
          startpos,
          ":endpos",
          endpos,
          ":parent",
          vx_core.f_copy(
            textblockarg,
            ":startpos",
            startpos,
            ":endpos",
            endpos,
            ":delim",
            vx_core.f_empty(
              vx_data_textblock.t_delim
            )
          )
        )
      })
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
   * @param  {textblock} textblockarg
   * @return {textblock}
   */
  static t_textblock_parse_one = {}
  static e_textblock_parse_one = {vx_type: vx_data_textblock.t_textblock_parse_one}

  // (func textblock-parse-one)
  static f_textblock_parse_one(textblockarg) {
    let output = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      {"any-1": vx_data_textblock.t_textblock},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const delimarg = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delim, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":delim")
        const close = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delim, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":close")
        const startpos = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":startpos")
        const textarg = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":text")
        const parent = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblock, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":parent")
        const is_init = vx_core.f_and(
          vx_core.f_is_empty_1(parent),
          vx_core.f_eq(startpos, 0)
        )
        const starttext = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delimarg, ":starttext")
        const endtext = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delimarg, ":endtext")
        const delimlistarg = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delimlist, "struct-2": vx_data_textblock.t_delim}, delimarg, ":delimlist")
        const startposchg = vx_core.f_if_2(
          {"any-1": vx_core.t_int},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq("", textarg)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return startpos})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq(0, startpos)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return 1})
          ),
          vx_core.f_else(vx_core.f_new(vx_core.t_any_from_func, () => {return startpos}))
        )
        const delimlistcl = vx_core.f_if_1(
          {"any-1": vx_data_textblock.t_delimlist},
          vx_core.f_is_empty_1(close),
          delimlistarg,
          vx_core.f_copy(delimlistarg, close)
        )
        const delimfirst = vx_data_textblock.f_delim_first_from_string_delimlist(textarg, delimlistcl)
        return vx_core.f_if_2(
          {"any-1": vx_data_textblock.t_textblock},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return is_init}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_data_textblock.f_textblock_init(textblockarg)})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty_1(parent)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return textblockarg})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty_1(delimfirst)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_data_textblock.f_textblock_delimnotfound(textblockarg)})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_data_textblock.f_is_close(delimfirst)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_data_textblock.f_textblock_from_close_textblock(delimfirst, textblockarg)})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_data_textblock.f_is_single(delimfirst)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_data_textblock.f_textblock_from_single_textblock(delimfirst, textblockarg)})
          ),
          vx_core.f_else(
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_data_textblock.f_textblock_from_open_textblock(delimfirst, textblockarg)})
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
   * @function textblock_replace_from_textblock_find_replace
   * Replace the given parent textblock.
   * @param  {textblock} textblockarg
   * @param  {textblock} find
   * @param  {textblock} replace
   * @return {textblock}
   */
  static t_textblock_replace_from_textblock_find_replace = {}
  static e_textblock_replace_from_textblock_find_replace = {vx_type: vx_data_textblock.t_textblock_replace_from_textblock_find_replace}

  // (func textblock-replace<-textblock-find-replace)
  static f_textblock_replace_from_textblock_find_replace(textblockarg, find, replace) {
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
        vx_core.f_new(vx_core.t_any_from_func, () => {return replace})
      ),
      vx_core.f_else(
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(
          textblockarg,
          ":parent",
          vx_data_textblock.f_textblock_replace_from_textblock_find_replace(
            vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblock, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":parent"),
            find,
            replace
          )
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
        const pos = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_delim}, delim, ":pos")
        const start = 1
        const end = vx_core.f_minus(pos, 1)
        return vx_core.f_if_2(
          {"any-1": vx_data_textblock.t_textblock},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq("", text)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_empty(
              vx_data_textblock.t_textblock
            )})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq(0, pos)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_empty(
              vx_data_textblock.t_textblock
            )})
          ),
          vx_core.f_else(
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
              vx_data_textblock.t_textblock,
              ":text",
              vx_type.f_string_from_string_start_end(text, start, end),
              ":startpos",
              vx_core.f_plus(offset, start),
              ":endpos",
              vx_core.f_plus(offset, end),
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
        const startpos = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_delim}, delimin, ":pos")
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
        const delimlen = vx_core.f_switch(
          {"any-1": vx_core.t_int, "any-2": vx_core.t_string},
          starttext,
          vx_core.f_case_1(":nonwhitespace", vx_core.f_new(vx_core.t_any_from_func, () => {return 0})),
          vx_core.f_case_1(":whitespace", vx_core.f_new(vx_core.t_any_from_func, () => {return 0})),
          vx_core.f_else(
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_type.f_length_from_string(starttext)})
          )
        )
        const curpos = 0
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
   * @function textblock_from_close_textblock
   * Returns a textblock after a close delim found.
   * @param  {delim} close
   * @param  {textblock} textblockarg
   * @return {textblock}
   */
  static t_textblock_from_close_textblock = {}
  static e_textblock_from_close_textblock = {vx_type: vx_data_textblock.t_textblock_from_close_textblock}

  // (func textblock<-close-textblock)
  static f_textblock_from_close_textblock(close, textblockarg) {
    let output = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      {"any-1": vx_data_textblock.t_textblock},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const text = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":text")
        const parent = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblock, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":parent")
        const startpos = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":startpos")
        const endpos = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":endpos")
        const pos = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_delim}, close, ":pos")
        const textclose = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, close, ":starttext")
        const lenclose = vx_type.f_length_from_string(textclose)
        const posminus = vx_core.f_minus1(pos)
        const startleft = startpos
        const startclose = vx_core.f_plus(startpos, posminus)
        const endclose = vx_core.f_switch(
          {"any-1": vx_core.t_int, "any-2": vx_core.t_string},
          textclose,
          vx_core.f_case_1(
            ":whitespace",
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_type.f_int_from_string_findkeyword(text, ":nonwhitespace")})
          ),
          vx_core.f_else(
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_plus(
              vx_core.f_minus1(startclose),
              lenclose
            )})
          )
        )
        const endleft = vx_core.f_if_1(
          {"any-1": vx_core.t_int},
          vx_core.f_eq(1, pos),
          startclose,
          vx_core.f_minus1(startclose)
        )
        const startright = vx_core.f_plus1(endclose)
        const endright = vx_core.f_if_1(
          {"any-1": vx_core.t_int},
          vx_core.f_lt(endpos, startright),
          startright,
          endpos
        )
        const textleft = vx_type.f_string_from_string_end(text, posminus)
        const textright = vx_type.f_string_from_string_start(
          text,
          vx_core.f_plus(pos, lenclose)
        )
        const find = vx_data_textblock.f_textblock_findparent_from_textblock(parent)
        const closefind = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delim, "struct-2": vx_data_textblock.t_textblock}, find, ":close")
        const textfind = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_textblock}, find, ":text")
        const startfind = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_textblock}, find, ":startpos")
        const delimfind = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delim, "struct-2": vx_data_textblock.t_textblock}, find, ":delim")
        const delimright = vx_core.f_new(
          vx_data_textblock.t_delim,
          ":delimlist",
          vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delimlist, "struct-2": vx_data_textblock.t_delim}, delimfind, ":delimlist")
        )
        const lenfind = vx_core.f_minus(
          vx_core.f_plus1(endclose),
          startfind
        )
        const textreplace = vx_type.f_string_from_string_end(textfind, lenfind)
        const replace = vx_core.f_copy(
          find,
          ":text",
          textreplace,
          ":endpos",
          endclose,
          ":delim",
          vx_core.f_copy(
            delimfind,
            ":delimlist",
            vx_core.f_empty(
              vx_data_textblock.t_delimlist
            )
          ),
          ":close",
          vx_data_textblock.c_delimclosing
        )
        const parentchg = vx_data_textblock.f_textblock_replace_from_textblock_find_replace(parent, find, replace)
        return vx_core.f_new(
          vx_data_textblock.t_textblock,
          ":text",
          textleft,
          ":startpos",
          startleft,
          ":endpos",
          endleft,
          ":parent",
          vx_core.f_copy(textblockarg, ":text", textright, ":startpos", startright, ":endpos", endright, ":delim", delimright, ":close", closefind, ":parent", parentchg)
        )
      })
    )
    return output
  }

  /**
   * @function textblock_from_empty_textblock
   * Returns a textblock after an empty delim found.
   * @param  {delim} empty
   * @param  {textblock} textblockarg
   * @return {textblock}
   */
  static t_textblock_from_empty_textblock = {}
  static e_textblock_from_empty_textblock = {vx_type: vx_data_textblock.t_textblock_from_empty_textblock}

  // (func textblock<-empty-textblock)
  static f_textblock_from_empty_textblock(empty, textblockarg) {
    let output = vx_data_textblock.e_textblock
    return output
  }

  /**
   * @function textblock_from_open_textblock
   * Returns a textblock after a close delim found.
   * @param  {delim} open
   * @param  {textblock} textblockarg
   * @return {textblock}
   */
  static t_textblock_from_open_textblock = {}
  static e_textblock_from_open_textblock = {vx_type: vx_data_textblock.t_textblock_from_open_textblock}

  // (func textblock<-open-textblock)
  static f_textblock_from_open_textblock(open, textblockarg) {
    let output = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      {"any-1": vx_data_textblock.t_textblock},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const text = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":text")
        const parent = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblock, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":parent")
        const startpos = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":startpos")
        const endpos = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":endpos")
        const delima = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delim, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":delim")
        const pos = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_delim}, open, ":pos")
        const textopen = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, open, ":starttext")
        const textclose = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, open, ":endtext")
        const delimlistl = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delimlist, "struct-2": vx_data_textblock.t_delim}, open, ":delimlist")
        const lenopen = vx_type.f_length_from_string(textopen)
        const posminus = vx_core.f_minus1(pos)
        const startleft = vx_core.f_minus1(startpos)
        const endleft = vx_core.f_plus(startleft, posminus)
        const startright = vx_core.f_plus_2(startleft, pos, lenopen)
        const startopen = vx_core.f_plus(startpos, posminus)
        const textleft = vx_type.f_string_from_string_end(text, posminus)
        const textpar = vx_type.f_string_from_string_start(text, pos)
        const textright = vx_type.f_string_from_string_start(
          text,
          vx_core.f_plus(pos, lenopen)
        )
        const close = vx_core.f_copy(
          vx_data_textblock.c_delimclose,
          ":starttext",
          textclose
        )
        return vx_core.f_new(
          vx_data_textblock.t_textblock,
          ":text",
          textleft,
          ":startpos",
          startleft,
          ":endpos",
          endleft,
          ":delim",
          vx_core.f_new(
            vx_data_textblock.t_delim,
            ":delimlist",
            delimlistl
          ),
          ":parent",
          vx_core.f_new(
            vx_data_textblock.t_textblock,
            ":text",
            textright,
            ":startpos",
            startright,
            ":endpos",
            endpos,
            ":delim",
            vx_core.f_new(
              vx_data_textblock.t_delim,
              ":delimlist",
              delimlistl
            ),
            ":close",
            close,
            ":parent",
            vx_core.f_copy(
              textblockarg,
              ":startpos",
              startopen,
              ":delim",
              vx_core.f_copy(
                open,
                ":pos",
                0,
                ":delimlist",
                vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delimlist, "struct-2": vx_data_textblock.t_delim}, delima, ":delimlist")
              ),
              ":parent",
              parent
            )
          )
        )
      })
    )
    return output
  }

  /**
   * @function textblock_from_single_textblock
   * Returns a textblock after a single value delim found.
   * @param  {delim} single
   * @param  {textblock} textblockarg
   * @return {textblock}
   */
  static t_textblock_from_single_textblock = {}
  static e_textblock_from_single_textblock = {vx_type: vx_data_textblock.t_textblock_from_single_textblock}

  // (func textblock<-single-textblock)
  static f_textblock_from_single_textblock(single, textblockarg) {
    let output = vx_data_textblock.e_textblock
    output = vx_core.f_let(
      {"any-1": vx_data_textblock.t_textblock},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const text = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":text")
        const parent = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblock, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":parent")
        const startpos = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":startpos")
        const endpos = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_textblock}, textblockarg, ":endpos")
        const pos = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_data_textblock.t_delim}, single, ":pos")
        const origsingle = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, single, ":starttext")
        const textsingle = vx_core.f_switch(
          {"any-1": vx_core.t_string, "any-2": vx_core.t_string},
          origsingle,
          vx_core.f_case_1(
            ":whitespace",
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_let(
              {"any-1": vx_core.t_string},
              [],
              vx_core.f_new(vx_core.t_any_from_func, () => {
                const text2 = vx_type.f_string_from_string_start(text, pos)
                const pos2 = vx_type.f_int_from_string_findkeyword(text2, ":nonwhitespace")
                const pos3 = vx_core.f_if_1(
                  {"any-1": vx_core.t_int},
                  vx_core.f_eq(0, pos2),
                  vx_type.f_length_from_string(text2),
                  pos2
                )
                return vx_type.f_string_from_string_start_end(text, pos, pos3)
              })
            )})
          ),
          vx_core.f_else(vx_core.f_new(vx_core.t_any_from_func, () => {return origsingle}))
        )
        const delimlistl = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delimlist, "struct-2": vx_data_textblock.t_delim}, single, ":delimlist")
        const lensingle = vx_type.f_length_from_string(textsingle)
        const posminus = vx_core.f_minus1(pos)
        const startleft = startpos
        const startsingle = vx_core.f_plus(startpos, posminus)
        const endsingle = vx_core.f_switch(
          {"any-1": vx_core.t_int, "any-2": vx_core.t_string},
          textsingle,
          vx_core.f_case_1(
            ":whitespace",
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_type.f_int_from_string_findkeyword(text, ":nonwhitespace")})
          ),
          vx_core.f_else(
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_plus(
              vx_core.f_minus1(startsingle),
              lensingle
            )})
          )
        )
        const endleft = vx_core.f_if_1(
          {"any-1": vx_core.t_int},
          vx_core.f_eq(startsingle, startpos),
          startsingle,
          vx_core.f_minus1(startsingle)
        )
        const startright = vx_core.f_plus1(endsingle)
        const textleft = vx_type.f_string_from_string_end(text, posminus)
        const textpar = vx_type.f_string_from_string_start(text, pos)
        const textright = vx_type.f_string_from_string_start(
          text,
          vx_core.f_plus(pos, lensingle)
        )
        return vx_core.f_new(
          vx_data_textblock.t_textblock,
          ":text",
          textleft,
          ":startpos",
          startleft,
          ":endpos",
          endleft,
          ":delim",
          vx_core.f_new(
            vx_data_textblock.t_delim,
            ":delimlist",
            delimlistl
          ),
          ":parent",
          vx_core.f_new(
            vx_data_textblock.t_textblock,
            ":text",
            textsingle,
            ":startpos",
            startsingle,
            ":endpos",
            endsingle,
            ":delim",
            vx_core.f_copy(
              single,
              ":pos",
              0,
              ":delimlist",
              vx_core.f_empty(
                vx_data_textblock.t_delimlist
              )
            ),
            ":parent",
            vx_core.f_copy(textblockarg, ":text", textright, ":startpos", startright, ":endpos", endpos)
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
    "delim-first<-delim-delim": vx_data_textblock.e_delim_first_from_delim_delim,
    "delim-first<-string-delimlist": vx_data_textblock.e_delim_first_from_string_delimlist,
    "delim-pos<-string-delim": vx_data_textblock.e_delim_pos_from_string_delim,
    "delimlist-pos<-string-delimlist": vx_data_textblock.e_delimlist_pos_from_string_delimlist,
    "is-close": vx_data_textblock.e_is_close,
    "is-single": vx_data_textblock.e_is_single,
    "stringlist<-textblocklist": vx_data_textblock.e_stringlist_from_textblocklist,
    "text<-textblock": vx_data_textblock.e_text_from_textblock,
    "textblock-addchild<-textblock-find-child": vx_data_textblock.e_textblock_addchild_from_textblock_find_child,
    "textblock-delimnotfound": vx_data_textblock.e_textblock_delimnotfound,
    "textblock-findparent<-textblock": vx_data_textblock.e_textblock_findparent_from_textblock,
    "textblock-groupby<-textblock-delim": vx_data_textblock.e_textblock_groupby_from_textblock_delim,
    "textblock-init": vx_data_textblock.e_textblock_init,
    "textblock-parse": vx_data_textblock.e_textblock_parse,
    "textblock-parse-one": vx_data_textblock.e_textblock_parse_one,
    "textblock-parse<-string-delim": vx_data_textblock.e_textblock_parse_from_string_delim,
    "textblock-replace<-textblock-find-replace": vx_data_textblock.e_textblock_replace_from_textblock_find_replace,
    "textblock-startleft<-string-delim-offset": vx_data_textblock.e_textblock_startleft_from_string_delim_offset,
    "textblock-startright<-string-delim-offset": vx_data_textblock.e_textblock_startright_from_string_delim_offset,
    "textblock<-close-textblock": vx_data_textblock.e_textblock_from_close_textblock,
    "textblock<-empty-textblock": vx_data_textblock.e_textblock_from_empty_textblock,
    "textblock<-open-textblock": vx_data_textblock.e_textblock_from_open_textblock,
    "textblock<-single-textblock": vx_data_textblock.e_textblock_from_single_textblock,
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
        "pos": {
          "name" : "pos",
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
      "delimclose"
    ))

    // (const delimclosing)
    Object.assign(vx_data_textblock.c_delimclosing, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":name",
      "delimclosing"
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

    // (const delimlisttest1)
    Object.assign(vx_data_textblock.c_delimlisttest1, vx_core.f_new(
      vx_data_textblock.t_delimlist,
      vx_data_textblock.c_delimtest2
    ))

    // (const delimlisttest2)
    Object.assign(vx_data_textblock.c_delimlisttest2, vx_core.f_new(
      vx_data_textblock.t_delimlist,
      vx_data_textblock.c_delimcomma,
      vx_data_textblock.c_delimtest3
    ))

    // (const delimlisttest3)
    Object.assign(vx_data_textblock.c_delimlisttest3, vx_core.f_new(
      vx_data_textblock.t_delimlist,
      vx_data_textblock.c_delimcomma,
      vx_data_textblock.c_delimwhitespace
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

    // (const delimtest1)
    Object.assign(vx_data_textblock.c_delimtest1, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":delimlist",
      vx_data_textblock.c_delimlisttest1
    ))

    // (const delimtest2)
    Object.assign(vx_data_textblock.c_delimtest2, vx_core.f_copy(
      vx_data_textblock.c_delimbracketangle,
      ":delimlist",
      vx_data_textblock.c_delimlisttest2
    ))

    // (const delimtest3)
    Object.assign(vx_data_textblock.c_delimtest3, vx_core.f_copy(
      vx_data_textblock.c_delimbracketcurly,
      ":delimlist",
      vx_data_textblock.c_delimlisttest3
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
      ":whitespace"
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

    // (func delim-first<-string-delimlist)
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

    // (func delim-pos<-string-delim)
    vx_data_textblock.t_delim_pos_from_string_delim['vx_type'] = vx_core.t_type
    vx_data_textblock.t_delim_pos_from_string_delim['vx_value'] = {
      name          : "delim-pos<-string-delim",
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
      fn            : vx_data_textblock.f_delim_pos_from_string_delim
    }

    // (func delimlist-pos<-string-delimlist)
    vx_data_textblock.t_delimlist_pos_from_string_delimlist['vx_type'] = vx_core.t_type
    vx_data_textblock.t_delimlist_pos_from_string_delimlist['vx_value'] = {
      name          : "delimlist-pos<-string-delimlist",
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
      fn            : vx_data_textblock.f_delimlist_pos_from_string_delimlist
    }

    // (func is-close)
    vx_data_textblock.t_is_close['vx_type'] = vx_core.t_type
    vx_data_textblock.t_is_close['vx_value'] = {
      name          : "is-close",
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
      fn            : vx_data_textblock.f_is_close
    }

    // (func is-single)
    vx_data_textblock.t_is_single['vx_type'] = vx_core.t_type
    vx_data_textblock.t_is_single['vx_value'] = {
      name          : "is-single",
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
      fn            : vx_data_textblock.f_is_single
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

    // (func textblock-init)
    vx_data_textblock.t_textblock_init['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblock_init['vx_value'] = {
      name          : "textblock-init",
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
      fn            : vx_data_textblock.f_textblock_init
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

    // (func textblock-replace<-textblock-find-replace)
    vx_data_textblock.t_textblock_replace_from_textblock_find_replace['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblock_replace_from_textblock_find_replace['vx_value'] = {
      name          : "textblock-replace<-textblock-find-replace",
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
      fn            : vx_data_textblock.f_textblock_replace_from_textblock_find_replace
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

    // (func textblock<-close-textblock)
    vx_data_textblock.t_textblock_from_close_textblock['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblock_from_close_textblock['vx_value'] = {
      name          : "textblock<-close-textblock",
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
      fn            : vx_data_textblock.f_textblock_from_close_textblock
    }

    // (func textblock<-empty-textblock)
    vx_data_textblock.t_textblock_from_empty_textblock['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblock_from_empty_textblock['vx_value'] = {
      name          : "textblock<-empty-textblock",
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
      fn            : vx_data_textblock.f_textblock_from_empty_textblock
    }

    // (func textblock<-open-textblock)
    vx_data_textblock.t_textblock_from_open_textblock['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblock_from_open_textblock['vx_value'] = {
      name          : "textblock<-open-textblock",
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
      fn            : vx_data_textblock.f_textblock_from_open_textblock
    }

    // (func textblock<-single-textblock)
    vx_data_textblock.t_textblock_from_single_textblock['vx_type'] = vx_core.t_type
    vx_data_textblock.t_textblock_from_single_textblock['vx_value'] = {
      name          : "textblock<-single-textblock",
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
      fn            : vx_data_textblock.f_textblock_from_single_textblock
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
