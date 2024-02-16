'strict mode'

import vx_core from "../../vx/core.js"


export default class vx_data_db {


  /**
   * type: db
   * Database trait
   */
  static t_db = {}
  static e_db = {vx_type: vx_data_db.t_db}

  /**
   * type: dbcell
   * Database Cell trait
   */
  static t_dbcell = {}
  static e_dbcell = {vx_type: vx_data_db.t_dbcell}

  /**
   * type: dbcellmap
   * Database Cell Map
   */
  static t_dbcellmap = {}
  static e_dbcellmap = {vx_type: vx_data_db.t_dbcellmap}

  /**
   * type: dbfield
   * Database Field trait
   */
  static t_dbfield = {}
  static e_dbfield = {vx_type: vx_data_db.t_dbfield}

  /**
   * type: dbfieldmap
   * Database Field Map
   */
  static t_dbfieldmap = {}
  static e_dbfieldmap = {vx_type: vx_data_db.t_dbfieldmap}

  /**
   * type: dbid
   * Database id
   */
  static t_dbid = {}
  static e_dbid = {vx_type: vx_data_db.t_dbid}

  /**
   * type: dblink
   * Database link
   */
  static t_dblink = {}
  static e_dblink = {vx_type: vx_data_db.t_dblink}

  /**
   * type: dblinklist
   * Database link
   */
  static t_dblinklist = {}
  static e_dblinklist = vx_core.vx_new_list(vx_data_db.t_dblinklist, [])

  /**
   * type: dbnode
   * Database node
   */
  static t_dbnode = {}
  static e_dbnode = {vx_type: vx_data_db.t_dbnode}

  /**
   * type: dbnote
   * Database Value
   */
  static t_dbnote = {}
  static e_dbnote = {vx_type: vx_data_db.t_dbnote}

  /**
   * type: dbtable
   * Database Table trait
   */
  static t_dbtable = {}
  static e_dbtable = {vx_type: vx_data_db.t_dbtable}

  /**
   * type: dbvalue
   * Database Value
   */
  static t_dbvalue = {}
  static e_dbvalue = {vx_type: vx_data_db.t_dbvalue}


  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "db": vx_data_db.e_db,
      "dbcell": vx_data_db.e_dbcell,
      "dbcellmap": vx_data_db.e_dbcellmap,
      "dbfield": vx_data_db.e_dbfield,
      "dbfieldmap": vx_data_db.e_dbfieldmap,
      "dbid": vx_data_db.e_dbid,
      "dblink": vx_data_db.e_dblink,
      "dblinklist": vx_data_db.e_dblinklist,
      "dbnode": vx_data_db.e_dbnode,
      "dbnote": vx_data_db.e_dbnote,
      "dbtable": vx_data_db.e_dbtable,
      "dbvalue": vx_data_db.e_dbvalue
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      "db": vx_data_db.t_db,
      "dbcell": vx_data_db.t_dbcell,
      "dbcellmap": vx_data_db.t_dbcellmap,
      "dbfield": vx_data_db.t_dbfield,
      "dbfieldmap": vx_data_db.t_dbfieldmap,
      "dbid": vx_data_db.t_dbid,
      "dblink": vx_data_db.t_dblink,
      "dblinklist": vx_data_db.t_dblinklist,
      "dbnode": vx_data_db.t_dbnode,
      "dbnote": vx_data_db.t_dbnote,
      "dbtable": vx_data_db.t_dbtable,
      "dbvalue": vx_data_db.t_dbvalue
    })
    const pkg = vx_core.vx_new_struct(vx_core.t_package, {
      "name": "vx/data/db",
      "constmap": constmap,
      "emptymap": emptymap,
      "funcmap": funcmap,
      "typemap": typemap
    })
    vx_core.vx_global_package_set(pkg)

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

    // (type dbid)
    vx_data_db.t_dbid['vx_type'] = vx_core.t_type
    vx_data_db.t_dbid['vx_value'] = {
      name          : "dbid",
      pkgname       : "vx/data/db",
      extends       : ":string",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_data_db.e_dbid['vx_type'] = vx_data_db.t_dbid
    vx_data_db.e_dbid['vx_value'] = {}

    // (type dblink)
    vx_data_db.t_dblink['vx_type'] = vx_core.t_type
    vx_data_db.t_dblink['vx_value'] = {
      name          : "dblink",
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
        "fromid": {
          "name" : "fromid",
          "type" : vx_data_db.t_dbid,
          "multi": false
        },
        "toid": {
          "name" : "toid",
          "type" : vx_data_db.t_dbid,
          "multi": false
        }
      },
      proplast      : {
        "name" : "toid",
        "type" : vx_data_db.t_dbid,
        "multi": false
      }
    }
    vx_data_db.e_dblink['vx_type'] = vx_data_db.t_dblink
    vx_data_db.e_dblink['vx_value'] = {}

    // (type dblinklist)
    vx_data_db.t_dblinklist['vx_type'] = vx_core.t_type
    vx_data_db.t_dblinklist['vx_value'] = {
      name          : "dblinklist",
      pkgname       : "vx/data/db",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_data_db.t_dblink],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_data_db.e_dblinklist['vx_type'] = vx_data_db.t_dblinklist

    // (type dbnode)
    vx_data_db.t_dbnode['vx_type'] = vx_core.t_type
    vx_data_db.t_dbnode['vx_value'] = {
      name          : "dbnode",
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
          "type" : vx_data_db.t_dbid,
          "multi": false
        },
        "links": {
          "name" : "links",
          "type" : vx_data_db.t_dblinklist,
          "multi": false
        }
      },
      proplast      : {
        "name" : "links",
        "type" : vx_data_db.t_dblinklist,
        "multi": false
      }
    }
    vx_data_db.e_dbnode['vx_type'] = vx_data_db.t_dbnode
    vx_data_db.e_dbnode['vx_value'] = {}

    // (type dbnote)
    vx_data_db.t_dbnote['vx_type'] = vx_core.t_type
    vx_data_db.t_dbnote['vx_value'] = {
      name          : "dbnote",
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
          "type" : vx_data_db.t_dbid,
          "multi": false
        },
        "valid": {
          "name" : "valid",
          "type" : vx_data_db.t_dbid,
          "multi": false
        },
        "noteid": {
          "name" : "noteid",
          "type" : vx_data_db.t_dbid,
          "multi": false
        },
        "valueid": {
          "name" : "valueid",
          "type" : vx_data_db.t_dbid,
          "multi": false
        },
        "value": {
          "name" : "value",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "value",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    vx_data_db.e_dbnote['vx_type'] = vx_data_db.t_dbnote
    vx_data_db.e_dbnote['vx_value'] = {}

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

    // (type dbvalue)
    vx_data_db.t_dbvalue['vx_type'] = vx_core.t_type
    vx_data_db.t_dbvalue['vx_value'] = {
      name          : "dbvalue",
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
          "type" : vx_data_db.t_dbid,
          "multi": false
        },
        "fromid": {
          "name" : "fromid",
          "type" : vx_data_db.t_dbid,
          "multi": false
        },
        "toid": {
          "name" : "toid",
          "type" : vx_data_db.t_dbid,
          "multi": false
        },
        "noteid": {
          "name" : "noteid",
          "type" : vx_data_db.t_dbid,
          "multi": false
        },
        "valid": {
          "name" : "valid",
          "type" : vx_data_db.t_dbid,
          "multi": false
        },
        "valtext": {
          "name" : "valtext",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "valtext",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    vx_data_db.e_dbvalue['vx_type'] = vx_data_db.t_dbvalue
    vx_data_db.e_dbvalue['vx_value'] = {}

  }
}
