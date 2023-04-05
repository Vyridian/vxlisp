'strict mode'

import vx_core from "../../vx/core.js"

export default class vx_data_db {

  /**
   * type: db
   * Database trait
   */
  static t_db = {}

  /**
   * type: dbcell
   * Database Cell trait
   */
  static t_dbcell = {}

  /**
   * type: dbcellmap
   * Database Cell Map
   */
  static t_dbcellmap = {}

  /**
   * type: dbfield
   * Database Field trait
   */
  static t_dbfield = {}

  /**
   * type: dbfieldmap
   * Database Field Map
   */
  static t_dbfieldmap = {}

  /**
   * type: dbtable
   * Database Table trait
   */
  static t_dbtable = {}
  // empty types
  static e_db = {}
  static e_dbcell = {}
  static e_dbcellmap = {}
  static e_dbfield = {}
  static e_dbfieldmap = {}
  static e_dbtable = {}

  static c_empty = {
    "db": vx_data_db.e_db,
    "dbcell": vx_data_db.e_dbcell,
    "dbcellmap": vx_data_db.e_dbcellmap,
    "dbfield": vx_data_db.e_dbfield,
    "dbfieldmap": vx_data_db.e_dbfieldmap,
    "dbtable": vx_data_db.e_dbtable
  }


  static {
    vx_core.f_global_package_set("vx/data/db", vx_data_db)

    // (type db)
    vx_data_db.t_db['vx_type'] = vx_core.t_type
    vx_data_db.t_db['vx_value'] = {
      name          : "db",
      pkgname       : "vx/data/db",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "dbid": {
          "name" : "dbid",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "dbid",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    vx_data_db.e_db['vx_type'] = vx_data_db.t_db
    vx_data_db.e_db['vx_value'] = {}

    // (type dbcell)
    vx_data_db.t_dbcell['vx_type'] = vx_core.t_type
    vx_data_db.t_dbcell['vx_value'] = {
      name          : "dbcell",
      pkgname       : "vx/data/db",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "dbcellid": {
          "name" : "dbcellid",
          "type" : vx_core.t_string,
          "multi": false
        },
        "dbcellmap": {
          "name" : "dbcellmap",
          "type" : vx_data_db.t_dbcellmap,
          "multi": false
        },
        "dbfieldmap": {
          "name" : "dbfieldmap",
          "type" : vx_data_db.t_dbfieldmap,
          "multi": false
        },
        "dbparent": {
          "name" : "dbparent",
          "type" : vx_data_db.t_dbcell,
          "multi": false
        },
        "dbtable": {
          "name" : "dbtable",
          "type" : vx_data_db.t_dbtable,
          "multi": false
        }
      },
      proplast      : {
        "name" : "dbtable",
        "type" : vx_data_db.t_dbtable,
        "multi": false
      }
    }
    vx_data_db.e_dbcell['vx_type'] = vx_data_db.t_dbcell
    vx_data_db.e_dbcell['vx_value'] = {}

    // (type dbcellmap)
    vx_data_db.t_dbcellmap['vx_type'] = vx_core.t_type
    vx_data_db.t_dbcellmap['vx_value'] = {
      name          : "dbcellmap",
      pkgname       : "vx/data/db",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_data_db.t_dbcell],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_data_db.e_dbcellmap['vx_type'] = vx_data_db.t_dbcellmap
    vx_data_db.e_dbcellmap['vx_value'] = {}

    // (type dbfield)
    vx_data_db.t_dbfield['vx_type'] = vx_core.t_type
    vx_data_db.t_dbfield['vx_value'] = {
      name          : "dbfield",
      pkgname       : "vx/data/db",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "dbfieldid": {
          "name" : "dbfieldid",
          "type" : vx_core.t_string,
          "multi": false
        },
        "type": {
          "name" : "type",
          "type" : vx_core.t_any,
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
    vx_data_db.e_dbfield['vx_type'] = vx_data_db.t_dbfield
    vx_data_db.e_dbfield['vx_value'] = {}

    // (type dbfieldmap)
    vx_data_db.t_dbfieldmap['vx_type'] = vx_core.t_type
    vx_data_db.t_dbfieldmap['vx_value'] = {
      name          : "dbfieldmap",
      pkgname       : "vx/data/db",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_data_db.t_dbfield],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_data_db.e_dbfieldmap['vx_type'] = vx_data_db.t_dbfieldmap
    vx_data_db.e_dbfieldmap['vx_value'] = {}

    // (type dbtable)
    vx_data_db.t_dbtable['vx_type'] = vx_core.t_type
    vx_data_db.t_dbtable['vx_value'] = {
      name          : "dbtable",
      pkgname       : "vx/data/db",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "dbtableid": {
          "name" : "dbtableid",
          "type" : vx_core.t_string,
          "multi": false
        },
        "db": {
          "name" : "db",
          "type" : vx_data_db.t_db,
          "multi": false
        },
        "dbcellmap": {
          "name" : "dbcellmap",
          "type" : vx_data_db.t_dbcellmap,
          "multi": false
        },
        "dbfieldmap": {
          "name" : "dbfieldmap",
          "type" : vx_data_db.t_dbfieldmap,
          "multi": false
        }
      },
      proplast      : {
        "name" : "dbfieldmap",
        "type" : vx_data_db.t_dbfieldmap,
        "multi": false
      }
    }
    vx_data_db.e_dbtable['vx_type'] = vx_data_db.t_dbtable
    vx_data_db.e_dbtable['vx_value'] = {}

  }
}
