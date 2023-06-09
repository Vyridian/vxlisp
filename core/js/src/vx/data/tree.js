'strict mode'

import vx_core from "../../vx/core.js"

export default class vx_data_tree {

  /**
   * type: branch
   */
  static t_branch = {}

  /**
   * type: brancharrow
   */
  static t_brancharrow = {}

  /**
   * type: branchlist
   */
  static t_branchlist = {}

  /**
   * type: leaf
   */
  static t_leaf = {}

  /**
   * type: leaflist
   */
  static t_leaflist = {}

  /**
   * type: tree
   */
  static t_tree = {}
  /**
   * Constant: brancharrow-down
   * {brancharrow}
   */
  static c_brancharrow_down = {vx_type: vx_data_tree.t_brancharrow}

  /**
   * Constant: brancharrow-up
   * {brancharrow}
   */
  static c_brancharrow_up = {vx_type: vx_data_tree.t_brancharrow}

  /**
   * Constant: brancharrow-updown
   * {brancharrow}
   */
  static c_brancharrow_updown = {vx_type: vx_data_tree.t_brancharrow}

  // empty types
  static e_branch = {}
  static e_brancharrow = {}
  static e_branchlist = []
  static e_leaf = {}
  static e_leaflist = []
  static e_tree = {}

  static c_empty = {
    "branch": vx_data_tree.e_branch,
    "brancharrow": vx_data_tree.e_brancharrow,
    "branchlist": vx_data_tree.e_branchlist,
    "leaf": vx_data_tree.e_leaf,
    "leaflist": vx_data_tree.e_leaflist,
    "tree": vx_data_tree.e_tree
  }


  static {
    vx_core.f_global_package_set("vx/data/tree", vx_data_tree)

    // (type branch)
    vx_data_tree.t_branch['vx_type'] = vx_core.t_type
    vx_data_tree.t_branch['vx_value'] = {
      name          : "branch",
      pkgname       : "vx/data/tree",
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
        "brancharrow": {
          "name" : "brancharrow",
          "type" : vx_data_tree.t_brancharrow,
          "multi": false
        },
        "branchlist": {
          "name" : "branchlist",
          "type" : vx_data_tree.t_branchlist,
          "multi": false
        },
        "leaflist": {
          "name" : "leaflist",
          "type" : vx_data_tree.t_leaflist,
          "multi": false
        },
        "parentbranch": {
          "name" : "parentbranch",
          "type" : vx_data_tree.t_branch,
          "multi": false
        },
        "tree": {
          "name" : "tree",
          "type" : vx_data_tree.t_tree,
          "multi": false
        }
      },
      proplast      : {
        "name" : "tree",
        "type" : vx_data_tree.t_tree,
        "multi": false
      }
    }
    vx_data_tree.e_branch['vx_type'] = vx_data_tree.t_branch
    vx_data_tree.e_branch['vx_value'] = {}

    // (type brancharrow)
    vx_data_tree.t_brancharrow['vx_type'] = vx_core.t_type
    vx_data_tree.t_brancharrow['vx_value'] = {
      name          : "brancharrow",
      pkgname       : "vx/data/tree",
      extends       : "",
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
    vx_data_tree.e_brancharrow['vx_type'] = vx_data_tree.t_brancharrow
    vx_data_tree.e_brancharrow['vx_value'] = {}

    // (type branchlist)
    vx_data_tree.t_branchlist['vx_type'] = vx_core.t_type
    vx_data_tree.t_branchlist['vx_value'] = {
      name          : "branchlist",
      pkgname       : "vx/data/tree",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_data_tree.t_branch],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_data_tree.e_branchlist['vx_type'] = vx_data_tree.t_branchlist

    // (type leaf)
    vx_data_tree.t_leaf['vx_type'] = vx_core.t_type
    vx_data_tree.t_leaf['vx_value'] = {
      name          : "leaf",
      pkgname       : "vx/data/tree",
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
    vx_data_tree.e_leaf['vx_type'] = vx_data_tree.t_leaf
    vx_data_tree.e_leaf['vx_value'] = {}

    // (type leaflist)
    vx_data_tree.t_leaflist['vx_type'] = vx_core.t_type
    vx_data_tree.t_leaflist['vx_value'] = {
      name          : "leaflist",
      pkgname       : "vx/data/tree",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_data_tree.t_leaf],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_data_tree.e_leaflist['vx_type'] = vx_data_tree.t_leaflist

    // (type tree)
    vx_data_tree.t_tree['vx_type'] = vx_core.t_type
    vx_data_tree.t_tree['vx_value'] = {
      name          : "tree",
      pkgname       : "vx/data/tree",
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
        "branch": {
          "name" : "branch",
          "type" : vx_data_tree.t_branch,
          "multi": false
        }
      },
      proplast      : {
        "name" : "branch",
        "type" : vx_data_tree.t_branch,
        "multi": false
      }
    }
    vx_data_tree.e_tree['vx_type'] = vx_data_tree.t_tree
    vx_data_tree.e_tree['vx_value'] = {}

  }
}
