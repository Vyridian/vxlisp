'strict mode'

import vx_core from "../vx/core.js"


export default class vx_sample {


  /**
   * type: mytype
   */
  static t_mytype = {}
  /**
   * Constant: myconst
   * My Constant
   * {int}
   */
  static c_myconst = 4

  /**
   * @function main
   * @return {none}
   */
  static t_main = {}
  static e_main = {vx_type: vx_sample.t_main}

  // (func main)
  static f_main() {
    vx_sample.f_myfunc(2)
  }

  /**
   * @function myfunc
   * My Function
   * @param  {int} myarg My Arg
   * @return {int}
   */
  static t_myfunc = {}
  static e_myfunc = {vx_type: vx_sample.t_myfunc}

  // (func myfunc)
  static f_myfunc(myarg) {
    let output = vx_core.e_int
    output = vx_core.f_plus(
      vx_sample.c_myconst,
      myarg
    )
    return output
  }

  // empty types
  static e_mytype = {}


  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      "myconst": vx_sample.c_myconst
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "mytype": vx_sample.e_mytype,
      "main": vx_sample.e_main,
      "myfunc": vx_sample.e_myfunc
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "main": vx_sample.t_main,
      "myfunc": vx_sample.t_myfunc
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      "mytype": vx_sample.t_mytype
    })
    const pkg = vx_core.vx_new_struct(vx_core.t_package, {
      "name": "vx/sample",
      "constmap": constmap,
      "emptymap": emptymap,
      "funcmap": funcmap,
      "typemap": typemap
    })
    vx_core.vx_global_package_set(pkg)

    // (type mytype)
    vx_sample.t_mytype['vx_type'] = vx_core.t_type
    vx_sample.t_mytype['vx_value'] = {
      name          : "mytype",
      pkgname       : "vx/sample",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "mynum": {
          "name" : "mynum",
          "type" : vx_core.t_int,
          "multi": false
        },
        "mystr": {
          "name" : "mystr",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "mystr",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    vx_sample.e_mytype['vx_type'] = vx_sample.t_mytype
    vx_sample.e_mytype['vx_value'] = {}

    // (func main)
    vx_sample.t_main['vx_type'] = vx_core.t_type
    vx_sample.t_main['vx_value'] = {
      name          : "main",
      pkgname       : "vx/sample",
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
      fn            : vx_sample.f_main
    }

    // (func myfunc)
    vx_sample.t_myfunc['vx_type'] = vx_core.t_type
    vx_sample.t_myfunc['vx_value'] = {
      name          : "myfunc",
      pkgname       : "vx/sample",
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
      fn            : vx_sample.f_myfunc
    }

  }
}
