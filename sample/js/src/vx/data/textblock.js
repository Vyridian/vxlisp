'strict mode'

import vx_core from "../../vx/core.js"

export default class vx_data_textblock {

  /**
   * type: delimset
   */
  static t_delimset = {}

  /**
   * type: textblock
   */
  static t_textblock = {}

  /**
   * type: textblocklist
   */
  static t_textblocklist = {}
  /**
   * @function parse
   * @param  {textblock} block
   * @param  {delimset} delimpairlist
   * @return {textblock}
   */
  static t_parse = {}
  static e_parse = {vx_type: vx_data_textblock.t_parse}

  static f_parse(block, delimpairlist) {
    let output = vx_data_textblock.e_textblock
    output = block
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
  static e_delimset = {}
  static e_textblock = {}
  static e_textblocklist = []

  static c_empty = {
    "delimset": vx_data_textblock.e_delimset,
    "textblock": vx_data_textblock.e_textblock,
    "textblocklist": vx_data_textblock.e_textblocklist,
    "parse": vx_data_textblock.e_parse,
    "stringlist<-textblocklist": vx_data_textblock.e_stringlist_from_textblocklist,
    "text<-textblock": vx_data_textblock.e_text_from_textblock,
    "textblocks<-textblock": vx_data_textblock.e_textblocks_from_textblock
  }


  static {
    vx_core.f_global_package_set("vx/data/textblock", vx_data_textblock)

    // (type delimset)
    vx_data_textblock.t_delimset['vx_type'] = vx_core.t_type
    vx_data_textblock.t_delimset['vx_value'] = {
      name          : "delimset",
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
        "start": {
          "name" : "start",
          "type" : vx_core.t_stringlist,
          "multi": false
        },
        "end": {
          "name" : "end",
          "type" : vx_core.t_stringlist,
          "multi": false
        },
        "split": {
          "name" : "split",
          "type" : vx_core.t_stringlist,
          "multi": false
        },
        "subset": {
          "name" : "subset",
          "type" : vx_data_textblock.t_delimset,
          "multi": false
        }
      },
      proplast      : {
        "name" : "subset",
        "type" : vx_data_textblock.t_delimset,
        "multi": false
      }
    }
    vx_data_textblock.e_delimset['vx_type'] = vx_data_textblock.t_delimset
    vx_data_textblock.e_delimset['vx_value'] = {}

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
        "textblocks": {
          "name" : "textblocks",
          "type" : vx_data_textblock.t_textblocklist,
          "multi": false
        }
      },
      proplast      : {
        "name" : "textblocks",
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

    // (func parse)
    vx_data_textblock.t_parse['vx_type'] = vx_core.t_type
    vx_data_textblock.t_parse['vx_value'] = {
      name          : "parse",
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
      fn            : vx_data_textblock.f_parse
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
