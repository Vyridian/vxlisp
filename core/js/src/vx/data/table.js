'strict mode'

import vx_core from "../../vx/core.js"

export default class vx_data_table {

  /**
   * type: cell
   */
  static t_cell = {}

  /**
   * type: celllist
   */
  static t_celllist = {}

  /**
   * type: cellmap
   */
  static t_cellmap = {}

  /**
   * type: field
   */
  static t_field = {}

  /**
   * type: fieldlist
   */
  static t_fieldlist = {}

  /**
   * type: fieldmap
   */
  static t_fieldmap = {}

  /**
   * type: filter
   */
  static t_filter = {}

  /**
   * type: row
   */
  static t_row = {}

  /**
   * type: rowlist
   */
  static t_rowlist = {}

  /**
   * type: rowmap
   */
  static t_rowmap = {}

  /**
   * type: sort
   */
  static t_sort = {}

  /**
   * type: table
   */
  static t_table = {}
  // empty types
  static e_cell = {}
  static e_celllist = []
  static e_cellmap = {}
  static e_field = {}
  static e_fieldlist = []
  static e_fieldmap = []
  static e_filter = {}
  static e_row = {}
  static e_rowlist = []
  static e_rowmap = {}
  static e_sort = {}
  static e_table = {}


  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "cell": vx_data_table.e_cell,
      "celllist": vx_data_table.e_celllist,
      "cellmap": vx_data_table.e_cellmap,
      "field": vx_data_table.e_field,
      "fieldlist": vx_data_table.e_fieldlist,
      "fieldmap": vx_data_table.e_fieldmap,
      "filter": vx_data_table.e_filter,
      "row": vx_data_table.e_row,
      "rowlist": vx_data_table.e_rowlist,
      "rowmap": vx_data_table.e_rowmap,
      "sort": vx_data_table.e_sort,
      "table": vx_data_table.e_table
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      "cell": vx_data_table.t_cell,
      "celllist": vx_data_table.t_celllist,
      "cellmap": vx_data_table.t_cellmap,
      "field": vx_data_table.t_field,
      "fieldlist": vx_data_table.t_fieldlist,
      "fieldmap": vx_data_table.t_fieldmap,
      "filter": vx_data_table.t_filter,
      "row": vx_data_table.t_row,
      "rowlist": vx_data_table.t_rowlist,
      "rowmap": vx_data_table.t_rowmap,
      "sort": vx_data_table.t_sort,
      "table": vx_data_table.t_table
    })
    const pkg = vx_core.vx_new_struct(vx_core.t_package, {
      "name": "vx/data/table",
      "constmap": constmap,
      "emptymap": emptymap,
      "funcmap": funcmap,
      "typemap": typemap
    })
    vx_core.vx_global_package_set(pkg)

    // (type cell)
    vx_data_table.t_cell['vx_type'] = vx_core.t_type
    vx_data_table.t_cell['vx_value'] = {
      name          : "cell",
      pkgname       : "vx/data/table",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "id": {
          "name" : "id",
          "type" : vx_core.t_string,
          "multi": false
        },
        "value": {
          "name" : "value",
          "type" : vx_core.t_any,
          "multi": false
        }
      },
      proplast      : {
        "name" : "value",
        "type" : vx_core.t_any,
        "multi": false
      }
    }
    vx_data_table.e_cell['vx_type'] = vx_data_table.t_cell
    vx_data_table.e_cell['vx_value'] = {}

    // (type celllist)
    vx_data_table.t_celllist['vx_type'] = vx_core.t_type
    vx_data_table.t_celllist['vx_value'] = {
      name          : "celllist",
      pkgname       : "vx/data/table",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_data_table.t_cell],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_data_table.e_celllist['vx_type'] = vx_data_table.t_celllist

    // (type cellmap)
    vx_data_table.t_cellmap['vx_type'] = vx_core.t_type
    vx_data_table.t_cellmap['vx_value'] = {
      name          : "cellmap",
      pkgname       : "vx/data/table",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_data_table.t_cell],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_data_table.e_cellmap['vx_type'] = vx_data_table.t_cellmap
    vx_data_table.e_cellmap['vx_value'] = {}

    // (type field)
    vx_data_table.t_field['vx_type'] = vx_core.t_type
    vx_data_table.t_field['vx_value'] = {
      name          : "field",
      pkgname       : "vx/data/table",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "id": {
          "name" : "id",
          "type" : vx_core.t_string,
          "multi": false
        },
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "fldtype": {
          "name" : "fldtype",
          "type" : vx_core.t_any,
          "multi": false
        }
      },
      proplast      : {
        "name" : "fldtype",
        "type" : vx_core.t_any,
        "multi": false
      }
    }
    vx_data_table.e_field['vx_type'] = vx_data_table.t_field
    vx_data_table.e_field['vx_value'] = {}

    // (type fieldlist)
    vx_data_table.t_fieldlist['vx_type'] = vx_core.t_type
    vx_data_table.t_fieldlist['vx_value'] = {
      name          : "fieldlist",
      pkgname       : "vx/data/table",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_data_table.t_field],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_data_table.e_fieldlist['vx_type'] = vx_data_table.t_fieldlist

    // (type fieldmap)
    vx_data_table.t_fieldmap['vx_type'] = vx_core.t_type
    vx_data_table.t_fieldmap['vx_value'] = {
      name          : "fieldmap",
      pkgname       : "vx/data/table",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_data_table.t_field],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_data_table.e_fieldmap['vx_type'] = vx_data_table.t_fieldmap

    // (type filter)
    vx_data_table.t_filter['vx_type'] = vx_core.t_type
    vx_data_table.t_filter['vx_value'] = {
      name          : "filter",
      pkgname       : "vx/data/table",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "id": {
          "name" : "id",
          "type" : vx_core.t_string,
          "multi": false
        },
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "idlist": {
          "name" : "idlist",
          "type" : vx_core.t_stringlist,
          "multi": false
        }
      },
      proplast      : {
        "name" : "idlist",
        "type" : vx_core.t_stringlist,
        "multi": false
      }
    }
    vx_data_table.e_filter['vx_type'] = vx_data_table.t_filter
    vx_data_table.e_filter['vx_value'] = {}

    // (type row)
    vx_data_table.t_row['vx_type'] = vx_core.t_type
    vx_data_table.t_row['vx_value'] = {
      name          : "row",
      pkgname       : "vx/data/table",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "id": {
          "name" : "id",
          "type" : vx_core.t_string,
          "multi": false
        },
        "cellmap": {
          "name" : "cellmap",
          "type" : vx_data_table.t_cellmap,
          "multi": false
        },
        "cellsort": {
          "name" : "cellsort",
          "type" : vx_data_table.t_sort,
          "multi": false
        }
      },
      proplast      : {
        "name" : "cellsort",
        "type" : vx_data_table.t_sort,
        "multi": false
      }
    }
    vx_data_table.e_row['vx_type'] = vx_data_table.t_row
    vx_data_table.e_row['vx_value'] = {}

    // (type rowlist)
    vx_data_table.t_rowlist['vx_type'] = vx_core.t_type
    vx_data_table.t_rowlist['vx_value'] = {
      name          : "rowlist",
      pkgname       : "vx/data/table",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_data_table.t_row],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_data_table.e_rowlist['vx_type'] = vx_data_table.t_rowlist

    // (type rowmap)
    vx_data_table.t_rowmap['vx_type'] = vx_core.t_type
    vx_data_table.t_rowmap['vx_value'] = {
      name          : "rowmap",
      pkgname       : "vx/data/table",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_data_table.t_row],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_data_table.e_rowmap['vx_type'] = vx_data_table.t_rowmap
    vx_data_table.e_rowmap['vx_value'] = {}

    // (type sort)
    vx_data_table.t_sort['vx_type'] = vx_core.t_type
    vx_data_table.t_sort['vx_value'] = {
      name          : "sort",
      pkgname       : "vx/data/table",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "id": {
          "name" : "id",
          "type" : vx_core.t_string,
          "multi": false
        },
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "idlist": {
          "name" : "idlist",
          "type" : vx_core.t_stringlist,
          "multi": false
        }
      },
      proplast      : {
        "name" : "idlist",
        "type" : vx_core.t_stringlist,
        "multi": false
      }
    }
    vx_data_table.e_sort['vx_type'] = vx_data_table.t_sort
    vx_data_table.e_sort['vx_value'] = {}

    // (type table)
    vx_data_table.t_table['vx_type'] = vx_core.t_type
    vx_data_table.t_table['vx_value'] = {
      name          : "table",
      pkgname       : "vx/data/table",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "id": {
          "name" : "id",
          "type" : vx_core.t_string,
          "multi": false
        },
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "fieldmap": {
          "name" : "fieldmap",
          "type" : vx_data_table.t_fieldmap,
          "multi": false
        },
        "fieldsort": {
          "name" : "fieldsort",
          "type" : vx_data_table.t_sort,
          "multi": false
        },
        "rowmap": {
          "name" : "rowmap",
          "type" : vx_data_table.t_rowmap,
          "multi": false
        },
        "rowfilter": {
          "name" : "rowfilter",
          "type" : vx_data_table.t_filter,
          "multi": false
        },
        "rowsort": {
          "name" : "rowsort",
          "type" : vx_data_table.t_sort,
          "multi": false
        }
      },
      proplast      : {
        "name" : "rowsort",
        "type" : vx_data_table.t_sort,
        "multi": false
      }
    }
    vx_data_table.e_table['vx_type'] = vx_data_table.t_table
    vx_data_table.e_table['vx_value'] = {}

  }
}
