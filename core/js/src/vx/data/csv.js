'strict mode'

import vx_core from "../../vx/core.js"
import vx_collection from "../../vx/collection.js"
import vx_data_file from "../../vx/data/file.js"
import vx_data_textblock from "../../vx/data/textblock.js"
import vx_type from "../../vx/type.js"


export default class vx_data_csv {


  /**
   * type: csv
   */
  static t_csv = {}
  static e_csv = {vx_type: vx_data_csv.t_csv}

  /**
   * type: csvrowmap
   */
  static t_csvrowmap = {}
  static e_csvrowmap = {vx_type: vx_data_csv.t_csvrowmap}

  /**
   * type: csvrows
   */
  static t_csvrows = {}
  static e_csvrows = vx_core.vx_new_list(vx_data_csv.t_csvrows, [])
  /**
   * Constant: delimcsv
   * Csv File Delimiters
   * {delim}
   */
  static c_delimcsv = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/data/csv', name: 'delimcsv'}}

  /**
   * @function csv_read_from_file
   * Returns a parsed csv from a file.
   * @param  {file} file
   * @return {csv}
   */
  static t_csv_read_from_file = {
    vx_type: vx_core.t_type
  }
  static e_csv_read_from_file = {
    vx_type: vx_data_csv.t_csv_read_from_file
  }

  // (func csv-read<-file)
  static f_csv_read_from_file(context, file) {
    let output = vx_data_csv.e_csv
    output = vx_core.f_let(
      {"any-1": vx_data_csv.t_csv},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const loaded = vx_data_file.f_file_read_from_file(context, file)
        return vx_data_csv.f_csv_from_file(loaded)
      })
    )
    return output
  }

  /**
   * @function csv_from_file
   * Returns a parsed csv from a file.
   * @param  {file} file
   * @return {csv}
   */
  static t_csv_from_file = {
    vx_type: vx_core.t_type
  }
  static e_csv_from_file = {
    vx_type: vx_data_csv.t_csv_from_file
  }

  // (func csv<-file)
  static f_csv_from_file(file) {
    let output = vx_data_csv.e_csv
    output = vx_core.f_let(
      {"any-1": vx_data_csv.t_csv},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const text = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_file.t_file}, file, ":text")
        return vx_data_csv.f_csv_from_string(text)
      })
    )
    return output
  }

  /**
   * @function csv_from_string
   * Returns a parsed csv from a string.
   * @param  {string} text
   * @return {csv}
   */
  static t_csv_from_string = {
    vx_type: vx_core.t_type
  }
  static e_csv_from_string = {
    vx_type: vx_data_csv.t_csv_from_string
  }

  // (func csv<-string)
  static f_csv_from_string(text) {
    let output = vx_data_csv.e_csv
    output = vx_data_csv.f_csv_from_textblock(
      vx_data_textblock.f_textblock_parse_from_string_delim(
        text,
        vx_data_csv.c_delimcsv
      )
    )
    return output
  }

  /**
   * @function csv_from_textblock
   * Returns a parsed csv from a textblock.
   * @param  {textblock} textblock
   * @return {csv}
   */
  static t_csv_from_textblock = {
    vx_type: vx_core.t_type
  }
  static e_csv_from_textblock = {
    vx_type: vx_data_csv.t_csv_from_textblock
  }

  // (func csv<-textblock)
  static f_csv_from_textblock(textblock) {
    let output = vx_data_csv.e_csv
    output = vx_core.f_let(
      {"any-1": vx_data_csv.t_csv},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const allrows = vx_data_csv.f_csvrows_from_textblock(textblock)
        const headers = vx_core.f_any_from_list({"any-1": vx_core.t_stringlist, "list-1": vx_data_csv.t_csvrows}, allrows, 1)
        const rows = vx_collection.f_list_from_list_end({"any-1": vx_core.t_stringlist, "list-1": vx_data_csv.t_csvrows}, allrows, 2)
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
   * @param  {textblock} textblock
   * @return {csvrows}
   */
  static t_csvrows_from_textblock = {
    vx_type: vx_core.t_type
  }
  static e_csvrows_from_textblock = {
    vx_type: vx_data_csv.t_csvrows_from_textblock
  }

  // (func csvrows<-textblock)
  static f_csvrows_from_textblock(textblock) {
    let output = vx_data_csv.e_csvrows
    output = vx_core.f_let(
      {"any-1": vx_data_csv.t_csvrows},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const parsedtb = vx_data_textblock.f_textblock_from_textblock_delim(
          textblock,
          vx_data_csv.c_delimcsv
        )
        const children = vx_data_textblock.f_children_from_textblock(parsedtb)
        const strings = vx_data_textblock.f_stringlist_from_textblocklist(children)
        return vx_core.f_new(
          vx_data_csv.t_csvrows,
          strings
        )
      })
    )
    return output
  }

  /**
   * @function stringmap_from_csv
   * Returns a stringmap using the first 2 values in each row.
   * @param  {csv} csv
   * @return {stringmap}
   */
  static t_stringmap_from_csv = {
    vx_type: vx_core.t_type
  }
  static e_stringmap_from_csv = {
    vx_type: vx_data_csv.t_stringmap_from_csv
  }

  // (func stringmap<-csv)
  static f_stringmap_from_csv(csv) {
    let output = vx_core.e_stringmap
    output = vx_core.f_let(
      {"any-1": vx_core.t_stringmap, "any-2": vx_core.t_stringlist, "list-1": vx_core.t_stringlist, "map-1": vx_core.t_stringmap, "map-2": vx_data_csv.t_csvrowmap},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const rows = vx_core.f_any_from_struct({"any-1": vx_data_csv.t_csvrows, "struct-2": vx_data_csv.t_csv}, csv, ":rows")
        const rowmap = vx_core.f_map_from_list(
          {"any-1": vx_core.t_stringlist, "any-2": vx_core.t_stringlist, "list-1": vx_core.t_stringlist, "list-2": vx_data_csv.t_csvrows, "map-1": vx_data_csv.t_csvrowmap},
          rows,
          vx_core.f_new(vx_core.t_any_from_any, (textlist) => 
            vx_core.f_any_from_list({"any-1": vx_core.t_string, "list-1": vx_core.t_stringlist}, textlist, 1))
        )
        return vx_core.f_map_from_map_1(
          {"any-1": vx_core.t_string, "any-2": vx_core.t_stringlist, "list-1": vx_core.t_stringlist, "map-1": vx_core.t_stringmap, "map-2": vx_data_csv.t_csvrowmap},
          rowmap,
          vx_core.f_new(vx_core.t_any_from_key_value, ([key, val]) => 
            vx_core.f_any_from_list({"any-1": vx_core.t_string, "list-1": vx_core.t_stringlist}, val, 2))
        )
      })
    )
    return output
  }

  /**
   * @function textblock_csv_from_string
   * Returns a parsed csv-textblock from a string.
   * @param  {string} text
   * @return {textblock}
   */
  static t_textblock_csv_from_string = {
    vx_type: vx_core.t_type
  }
  static e_textblock_csv_from_string = {
    vx_type: vx_data_csv.t_textblock_csv_from_string
  }

  // (func textblock-csv<-string)
  static f_textblock_csv_from_string(text) {
    let output = vx_data_textblock.e_textblock
    output = vx_data_textblock.f_textblock_parse_from_string_delim(
      text,
      vx_data_csv.c_delimcsv
    )
    return output
  }



  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      "delimcsv": vx_data_csv.c_delimcsv
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "csv": vx_data_csv.e_csv,
      "csvrowmap": vx_data_csv.e_csvrowmap,
      "csvrows": vx_data_csv.e_csvrows,
      "csv-read<-file": vx_data_csv.e_csv_read_from_file,
      "csv<-file": vx_data_csv.e_csv_from_file,
      "csv<-string": vx_data_csv.e_csv_from_string,
      "csv<-textblock": vx_data_csv.e_csv_from_textblock,
      "csvrows<-textblock": vx_data_csv.e_csvrows_from_textblock,
      "stringmap<-csv": vx_data_csv.e_stringmap_from_csv,
      "textblock-csv<-string": vx_data_csv.e_textblock_csv_from_string
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "csv-read<-file": vx_data_csv.t_csv_read_from_file,
      "csv<-file": vx_data_csv.t_csv_from_file,
      "csv<-string": vx_data_csv.t_csv_from_string,
      "csv<-textblock": vx_data_csv.t_csv_from_textblock,
      "csvrows<-textblock": vx_data_csv.t_csvrows_from_textblock,
      "stringmap<-csv": vx_data_csv.t_stringmap_from_csv,
      "textblock-csv<-string": vx_data_csv.t_textblock_csv_from_string
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      "csv": vx_data_csv.t_csv,
      "csvrowmap": vx_data_csv.t_csvrowmap,
      "csvrows": vx_data_csv.t_csvrows
    })
    const pkg = vx_core.vx_new_struct(vx_core.t_package, {
      "name": "vx/data/csv",
      "constmap": constmap,
      "emptymap": emptymap,
      "funcmap": funcmap,
      "typemap": typemap
    })
    vx_core.vx_global_package_set(pkg)

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

    // (type csvrowmap)
    vx_data_csv.t_csvrowmap['vx_type'] = vx_core.t_type
    vx_data_csv.t_csvrowmap['vx_value'] = {
      name          : "csvrowmap",
      pkgname       : "vx/data/csv",
      extends       : ":map",
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
    vx_data_csv.e_csvrowmap['vx_type'] = vx_data_csv.t_csvrowmap
    vx_data_csv.e_csvrowmap['vx_value'] = {}

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

    // (func csv-read<-file)
    vx_data_csv.t_csv_read_from_file['vx_value'] = {
      name          : "csv-read<-file",
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
      fn            : vx_data_csv.f_csv_read_from_file
    }

    // (func csv<-file)
    vx_data_csv.t_csv_from_file['vx_value'] = {
      name          : "csv<-file",
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
      fn            : vx_data_csv.f_csv_from_file
    }

    // (func csv<-string)
    vx_data_csv.t_csv_from_string['vx_value'] = {
      name          : "csv<-string",
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
      fn            : vx_data_csv.f_csv_from_string
    }

    // (func csv<-textblock)
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

    // (func csvrows<-textblock)
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

    // (func stringmap<-csv)
    vx_data_csv.t_stringmap_from_csv['vx_value'] = {
      name          : "stringmap<-csv",
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
      fn            : vx_data_csv.f_stringmap_from_csv
    }

    // (func textblock-csv<-string)
    vx_data_csv.t_textblock_csv_from_string['vx_value'] = {
      name          : "textblock-csv<-string",
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
      fn            : vx_data_csv.f_textblock_csv_from_string
    }

    // (const delimcsv)
    Object.assign(vx_data_csv.c_delimcsv, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":name",
      "delimcsv",
      ":delimlist",
      vx_core.f_new(
        vx_data_textblock.t_delimlist,
        vx_data_textblock.c_delimline,
        vx_data_textblock.c_delimquote,
        vx_data_textblock.c_delimcomma
      )
    ))

  }
}
