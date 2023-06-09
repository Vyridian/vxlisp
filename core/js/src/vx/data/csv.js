'strict mode'

import vx_core from "../../vx/core.js"
import vx_collection from "../../vx/collection.js"
import vx_type from "../../vx/type.js"
import vx_data_textblock from "../../vx/data/textblock.js"

export default class vx_data_csv {

  /**
   * type: csv
   */
  static t_csv = {}

  /**
   * type: csvrows
   */
  static t_csvrows = {}
  /**
   * Constant: delims
   * {delimset}
   */
  static c_delims = {vx_type: vx_data_textblock.t_delimset}

  /**
   * @function csv_from_textblock
   * @param  {} textblock
   * @return {csv}
   */
  static t_csv_from_textblock = {}
  static e_csv_from_textblock = {vx_type: vx_data_csv.t_csv_from_textblock}

  static f_csv_from_textblock(textblock) {
    let output = vx_data_csv.e_csv
    output = vx_core.f_let(
      {"any-1": vx_data_csv.t_csv},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const allrows = vx_data_csv.f_csvrows_from_textblock(textblock)
        const headers = vx_core.f_any_from_list({"any-1": vx_core.t_stringlist, "list-1": vx_data_csv.t_csvrows}, allrows, 0)
        const rows = vx_collection.f_list_from_list_end({"any-1": vx_core.t_stringlist, "list-1": vx_data_csv.t_csvrows}, allrows, 1)
        return vx_core.f_new(
          vx_data_csv.t_csv,
          ":headers",
          headers,
          ":rows",
          rows
        )
      })
    )
    return output
  }

  /**
   * @function csvrows_from_textblock
   * @param  {} textblock
   * @return {csvrows}
   */
  static t_csvrows_from_textblock = {}
  static e_csvrows_from_textblock = {vx_type: vx_data_csv.t_csvrows_from_textblock}

  static f_csvrows_from_textblock(textblock) {
    let output = vx_data_csv.e_csvrows
    output = vx_core.f_let(
      {"any-1": vx_data_csv.t_csvrows},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const parsedtb = vx_data_textblock.f_parse(
          textblock,
          vx_data_csv.c_delims
        )
        const childtbs = vx_data_textblock.f_textblocks_from_textblock(parsedtb)
        const strings = vx_data_textblock.f_stringlist_from_textblocklist(childtbs)
        return vx_core.f_new(
          vx_data_csv.t_csvrows,
          strings
        )
      })
    )
    return output
  }

  // empty types
  static e_csv = {}
  static e_csvrows = []

  static c_empty = {
    "csv": vx_data_csv.e_csv,
    "csvrows": vx_data_csv.e_csvrows,
    "csv<-textblock": vx_data_csv.e_csv_from_textblock,
    "csvrows<-textblock": vx_data_csv.e_csvrows_from_textblock
  }


  static {
    vx_core.f_global_package_set("vx/data/csv", vx_data_csv)

    // (type csv)
    vx_data_csv.t_csv['vx_type'] = vx_core.t_type
    vx_data_csv.t_csv['vx_value'] = {
      name          : "csv",
      pkgname       : "vx/data/csv",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "headers": {
          "name" : "headers",
          "type" : vx_core.t_stringlist,
          "multi": false
        },
        "rows": {
          "name" : "rows",
          "type" : vx_data_csv.t_csvrows,
          "multi": false
        }
      },
      proplast      : {
        "name" : "rows",
        "type" : vx_data_csv.t_csvrows,
        "multi": false
      }
    }
    vx_data_csv.e_csv['vx_type'] = vx_data_csv.t_csv
    vx_data_csv.e_csv['vx_value'] = {}

    // (type csvrows)
    vx_data_csv.t_csvrows['vx_type'] = vx_core.t_type
    vx_data_csv.t_csvrows['vx_value'] = {
      name          : "csvrows",
      pkgname       : "vx/data/csv",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_stringlist],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_data_csv.e_csvrows['vx_type'] = vx_data_csv.t_csvrows

    // (const delims)
    Object.assign(vx_data_csv.c_delims, vx_core.f_new(
      vx_data_textblock.t_delimset,
      ":split",
      vx_core.f_new(
        vx_core.t_stringlist,
        "\n"
      ),
      ":subset",
      vx_core.f_new(
        vx_data_textblock.t_delimset,
        ":split",
        vx_core.f_new(
          vx_core.t_stringlist,
          ","
        ),
        ":subset",
        vx_core.f_new(
          vx_data_textblock.t_delimset,
          ":start",
          vx_core.f_new(
            vx_core.t_stringlist,
            "\""
          ),
          ":end",
          vx_core.f_new(
            vx_core.t_stringlist,
            "\""
          )
        )
      )
    ))

    // (func csv_from_textblock)
    vx_data_csv.t_csv_from_textblock['vx_type'] = vx_core.t_type
    vx_data_csv.t_csv_from_textblock['vx_value'] = {
      name          : "csv<-textblock",
      pkgname       : "vx/data/csv",
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
      fn            : vx_data_csv.f_csv_from_textblock
    }

    // (func csvrows_from_textblock)
    vx_data_csv.t_csvrows_from_textblock['vx_type'] = vx_core.t_type
    vx_data_csv.t_csvrows_from_textblock['vx_value'] = {
      name          : "csvrows<-textblock",
      pkgname       : "vx/data/csv",
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
      fn            : vx_data_csv.f_csvrows_from_textblock
    }

  }
}
