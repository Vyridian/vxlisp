'strict mode'

import vx_core from "../../vx/core.js"
import vx_data_textblock from "../../vx/data/textblock.js"


export default class vx_data_file {


  /**
   * type: file
   * File structure
   */
  static t_file = {}

  /**
   * type: fileformat
   */
  static t_fileformat = {}
  /**
   * @function boolean_exists_from_file
   * Returns true if file/path exists.
   * @param  {file} file
   * @return {boolean}
   */
  static t_boolean_exists_from_file = {}
  static e_boolean_exists_from_file = {vx_type: vx_data_file.t_boolean_exists_from_file}

  // (func boolean-exists<-file)
  static f_boolean_exists_from_file(file) {
    let output = vx_core.e_boolean
    return output
  }

  /**
   * @function boolean_write_from_file
   * Write a File to Disk
   * @param  {file} file
   * @return {boolean}
   */
  static t_boolean_write_from_file = {}
  static e_boolean_write_from_file = {vx_type: vx_data_file.t_boolean_write_from_file}

  // (func boolean-write<-file)
  static f_boolean_write_from_file(context, file) {
    let output = vx_core.e_boolean
    output = vx_data_file.f_boolean_write_from_file_string(
      context,
      file,
      vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_file.t_file}, file, ":text")
    )
    return output
  }

  /**
   * @function boolean_write_from_file_any
   * Write any data structure as a file.
   * @param  {file} file
   * @param  {any} val
   * @return {boolean}
   */
  static t_boolean_write_from_file_any = {}
  static e_boolean_write_from_file_any = {vx_type: vx_data_file.t_boolean_write_from_file_any}

  // (func boolean-write<-file-any)
  static f_boolean_write_from_file_any(context, file, val) {
    let output = vx_core.e_boolean
    output = vx_data_file.f_boolean_write_from_file_string(
      context,
      file,
      vx_core.f_string_from_any(val)
    )
    return output
  }

  /**
   * @function boolean_write_from_file_string
   * Write a File to Disk
   * @param  {file} file
   * @param  {string} text
   * @return {boolean}
   */
  static t_boolean_write_from_file_string = {}
  static e_boolean_write_from_file_string = {vx_type: vx_data_file.t_boolean_write_from_file_string}

  // (func boolean-write<-file-string)
  static f_boolean_write_from_file_string(context, file, text) {
    let output = vx_core.e_boolean
    try {
    } catch (err) {
      console.log(err)
    }
    return output
  }

  /**
   * @function file_read_from_file
   * Read a Text File from Disk
   * @param  {file} file
   * @return {file}
   */
  static t_file_read_from_file = {}
  static e_file_read_from_file = {vx_type: vx_data_file.t_file_read_from_file}

  // (func file-read<-file)
  static f_file_read_from_file(context, file) {
    let output = vx_data_file.e_file
    output = vx_core.f_copy(
      file,
      ":text",
      vx_data_file.f_string_read_from_file(context, file)
    )
    return output
  }

  /**
   * @function name_from_file
   * Returns path and name from file.
   * @param  {file} file
   * @return {string}
   */
  static t_name_from_file = {}
  static e_name_from_file = {vx_type: vx_data_file.t_name_from_file}

  // (func name<-file)
  static f_name_from_file(file) {
    let output = vx_core.e_string
    output = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_file.t_file}, file, ":name")
    return output
  }

  /**
   * @function path_from_file
   * Returns path and name from file.
   * @param  {file} file
   * @return {string}
   */
  static t_path_from_file = {}
  static e_path_from_file = {vx_type: vx_data_file.t_path_from_file}

  // (func path<-file)
  static f_path_from_file(file) {
    let output = vx_core.e_string
    output = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_file.t_file}, file, ":path")
    return output
  }

  /**
   * @function pathcurrent_from_os
   * Returns current system path.
   * @return {string}
   */
  static t_pathcurrent_from_os = {}
  static e_pathcurrent_from_os = {vx_type: vx_data_file.t_pathcurrent_from_os}

  // (func pathcurrent<-os)
  static f_pathcurrent_from_os() {
    let output = vx_core.e_string
    return output
  }

  /**
   * @function pathfull_from_file
   * Returns full path and name from file.
   * @param  {file} file
   * @return {string}
   */
  static t_pathfull_from_file = {}
  static e_pathfull_from_file = {vx_type: vx_data_file.t_pathfull_from_file}

  // (func pathfull<-file)
  static f_pathfull_from_file(file) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const path = vx_data_file.f_path_from_file(file)
        const name = vx_data_file.f_name_from_file(file)
        return vx_core.f_new(
          vx_core.t_string,
          path,
          "/",
          name
        )
      })
    )
    return output
  }

  /**
   * @function string_read_from_file
   * Read text from a File
   * @param  {file} file
   * @return {string}
   */
  static t_string_read_from_file = {}
  static e_string_read_from_file = {vx_type: vx_data_file.t_string_read_from_file}

  // (func string-read<-file)
  static f_string_read_from_file(context, file) {
    let output = vx_core.e_string
    try {
    } catch (err) {
      console.log(err)
    }
    return output
  }

  // empty types
  static e_file = {}
  static e_fileformat = {}


  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "file": vx_data_file.e_file,
      "fileformat": vx_data_file.e_fileformat,
      "boolean-exists<-file": vx_data_file.e_boolean_exists_from_file,
      "boolean-write<-file": vx_data_file.e_boolean_write_from_file,
      "boolean-write<-file-any": vx_data_file.e_boolean_write_from_file_any,
      "boolean-write<-file-string": vx_data_file.e_boolean_write_from_file_string,
      "file-read<-file": vx_data_file.e_file_read_from_file,
      "name<-file": vx_data_file.e_name_from_file,
      "path<-file": vx_data_file.e_path_from_file,
      "pathcurrent<-os": vx_data_file.e_pathcurrent_from_os,
      "pathfull<-file": vx_data_file.e_pathfull_from_file,
      "string-read<-file": vx_data_file.e_string_read_from_file
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "boolean-exists<-file": vx_data_file.t_boolean_exists_from_file,
      "boolean-write<-file": vx_data_file.t_boolean_write_from_file,
      "boolean-write<-file-any": vx_data_file.t_boolean_write_from_file_any,
      "boolean-write<-file-string": vx_data_file.t_boolean_write_from_file_string,
      "file-read<-file": vx_data_file.t_file_read_from_file,
      "name<-file": vx_data_file.t_name_from_file,
      "path<-file": vx_data_file.t_path_from_file,
      "pathcurrent<-os": vx_data_file.t_pathcurrent_from_os,
      "pathfull<-file": vx_data_file.t_pathfull_from_file,
      "string-read<-file": vx_data_file.t_string_read_from_file
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      "file": vx_data_file.t_file,
      "fileformat": vx_data_file.t_fileformat
    })
    const pkg = vx_core.vx_new_struct(vx_core.t_package, {
      "name": "vx/data/file",
      "constmap": constmap,
      "emptymap": emptymap,
      "funcmap": funcmap,
      "typemap": typemap
    })
    vx_core.vx_global_package_set(pkg)

    // (type file)
    vx_data_file.t_file['vx_type'] = vx_core.t_type
    vx_data_file.t_file['vx_value'] = {
      name          : "file",
      pkgname       : "vx/data/file",
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
        "format": {
          "name" : "format",
          "type" : vx_data_file.t_fileformat,
          "multi": false
        },
        "path": {
          "name" : "path",
          "type" : vx_core.t_string,
          "multi": false
        },
        "permission": {
          "name" : "permission",
          "type" : vx_core.t_permission,
          "multi": false
        },
        "text": {
          "name" : "text",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "text",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    vx_data_file.e_file['vx_type'] = vx_data_file.t_file
    vx_data_file.e_file['vx_value'] = {}

    // (type fileformat)
    vx_data_file.t_fileformat['vx_type'] = vx_core.t_type
    vx_data_file.t_fileformat['vx_value'] = {
      name          : "fileformat",
      pkgname       : "vx/data/file",
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
    vx_data_file.e_fileformat['vx_type'] = vx_data_file.t_fileformat
    vx_data_file.e_fileformat['vx_value'] = {}

    // (func boolean-exists<-file)
    vx_data_file.t_boolean_exists_from_file['vx_type'] = vx_core.t_type
    vx_data_file.t_boolean_exists_from_file['vx_value'] = {
      name          : "boolean-exists<-file",
      pkgname       : "vx/data/file",
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
      fn            : vx_data_file.f_boolean_exists_from_file
    }

    // (func boolean-write<-file)
    vx_data_file.t_boolean_write_from_file['vx_type'] = vx_core.t_type
    vx_data_file.t_boolean_write_from_file['vx_value'] = {
      name          : "boolean-write<-file",
      pkgname       : "vx/data/file",
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
      fn            : vx_data_file.f_boolean_write_from_file
    }

    // (func boolean-write<-file-any)
    vx_data_file.t_boolean_write_from_file_any['vx_type'] = vx_core.t_type
    vx_data_file.t_boolean_write_from_file_any['vx_value'] = {
      name          : "boolean-write<-file-any",
      pkgname       : "vx/data/file",
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
      fn            : vx_data_file.f_boolean_write_from_file_any
    }

    // (func boolean-write<-file-string)
    vx_data_file.t_boolean_write_from_file_string['vx_type'] = vx_core.t_type
    vx_data_file.t_boolean_write_from_file_string['vx_value'] = {
      name          : "boolean-write<-file-string",
      pkgname       : "vx/data/file",
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
      fn            : vx_data_file.f_boolean_write_from_file_string
    }

    // (func file-read<-file)
    vx_data_file.t_file_read_from_file['vx_type'] = vx_core.t_type
    vx_data_file.t_file_read_from_file['vx_value'] = {
      name          : "file-read<-file",
      pkgname       : "vx/data/file",
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
      fn            : vx_data_file.f_file_read_from_file
    }

    // (func name<-file)
    vx_data_file.t_name_from_file['vx_type'] = vx_core.t_type
    vx_data_file.t_name_from_file['vx_value'] = {
      name          : "name<-file",
      pkgname       : "vx/data/file",
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
      fn            : vx_data_file.f_name_from_file
    }

    // (func path<-file)
    vx_data_file.t_path_from_file['vx_type'] = vx_core.t_type
    vx_data_file.t_path_from_file['vx_value'] = {
      name          : "path<-file",
      pkgname       : "vx/data/file",
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
      fn            : vx_data_file.f_path_from_file
    }

    // (func pathcurrent<-os)
    vx_data_file.t_pathcurrent_from_os['vx_type'] = vx_core.t_type
    vx_data_file.t_pathcurrent_from_os['vx_value'] = {
      name          : "pathcurrent<-os",
      pkgname       : "vx/data/file",
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
      fn            : vx_data_file.f_pathcurrent_from_os
    }

    // (func pathfull<-file)
    vx_data_file.t_pathfull_from_file['vx_type'] = vx_core.t_type
    vx_data_file.t_pathfull_from_file['vx_value'] = {
      name          : "pathfull<-file",
      pkgname       : "vx/data/file",
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
      fn            : vx_data_file.f_pathfull_from_file
    }

    // (func string-read<-file)
    vx_data_file.t_string_read_from_file['vx_type'] = vx_core.t_type
    vx_data_file.t_string_read_from_file['vx_value'] = {
      name          : "string-read<-file",
      pkgname       : "vx/data/file",
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
      fn            : vx_data_file.f_string_read_from_file
    }

  }
}
