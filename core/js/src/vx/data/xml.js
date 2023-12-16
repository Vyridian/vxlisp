'strict mode'

import vx_core from "../../vx/core.js"
import vx_data_textblock from "../../vx/data/textblock.js"

export default class vx_data_xml {

  /**
   * type: xml
   */
  static t_xml = {}

  /**
   * type: xmlnode
   */
  static t_xmlnode = {}

  /**
   * type: xmlnodelist
   */
  static t_xmlnodelist = {}

  /**
   * type: xmlpropmap
   */
  static t_xmlpropmap = {}
  /**
   * Constant: delimxml
   * {delim}
   */
  static c_delimxml = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/data/xml', name: 'delimxml'}}

  /**
   * Constant: delimxmlequal
   * {delim}
   */
  static c_delimxmlequal = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/data/xml', name: 'delimxmlequal'}}

  /**
   * @function xml_from_textblock
   * @param  {textblock} textblock
   * @return {xml}
   */
  static t_xml_from_textblock = {}
  static e_xml_from_textblock = {vx_type: vx_data_xml.t_xml_from_textblock}

  // (func xml<-textblock)
  static f_xml_from_textblock(textblock) {
    let output = vx_data_xml.e_xml
    output = vx_core.f_empty(
      vx_data_xml.t_xml
    )
    return output
  }

  // empty types
  static e_xml = {}
  static e_xmlnode = {}
  static e_xmlnodelist = []
  static e_xmlpropmap = {}


  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      "delimxml": vx_data_xml.c_delimxml,
      "delimxmlequal": vx_data_xml.c_delimxmlequal
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "xml": vx_data_xml.e_xml,
      "xmlnode": vx_data_xml.e_xmlnode,
      "xmlnodelist": vx_data_xml.e_xmlnodelist,
      "xmlpropmap": vx_data_xml.e_xmlpropmap,
      "xml<-textblock": vx_data_xml.e_xml_from_textblock
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "xml<-textblock": vx_data_xml.t_xml_from_textblock
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      "xml": vx_data_xml.t_xml,
      "xmlnode": vx_data_xml.t_xmlnode,
      "xmlnodelist": vx_data_xml.t_xmlnodelist,
      "xmlpropmap": vx_data_xml.t_xmlpropmap
    })
    const pkg = vx_core.vx_new_struct(vx_core.t_package, {
      "name": "vx/data/xml",
      "constmap": constmap,
      "emptymap": emptymap,
      "funcmap": funcmap,
      "typemap": typemap
    })
    vx_core.vx_global_package_set(pkg)

    // (type xml)
    vx_data_xml.t_xml['vx_type'] = vx_core.t_type
    vx_data_xml.t_xml['vx_value'] = {
      name          : "xml",
      pkgname       : "vx/data/xml",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "nodes": {
          "name" : "nodes",
          "type" : vx_data_xml.t_xmlnodelist,
          "multi": false
        }
      },
      proplast      : {
        "name" : "nodes",
        "type" : vx_data_xml.t_xmlnodelist,
        "multi": false
      }
    }
    vx_data_xml.e_xml['vx_type'] = vx_data_xml.t_xml
    vx_data_xml.e_xml['vx_value'] = {}

    // (type xmlnode)
    vx_data_xml.t_xmlnode['vx_type'] = vx_core.t_type
    vx_data_xml.t_xmlnode['vx_value'] = {
      name          : "xmlnode",
      pkgname       : "vx/data/xml",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "nodes": {
          "name" : "nodes",
          "type" : vx_data_xml.t_xmlnode,
          "multi": false
        },
        "props": {
          "name" : "props",
          "type" : vx_data_xml.t_xmlpropmap,
          "multi": false
        },
        "tag": {
          "name" : "tag",
          "type" : vx_core.t_string,
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
    vx_data_xml.e_xmlnode['vx_type'] = vx_data_xml.t_xmlnode
    vx_data_xml.e_xmlnode['vx_value'] = {}

    // (type xmlnodelist)
    vx_data_xml.t_xmlnodelist['vx_type'] = vx_core.t_type
    vx_data_xml.t_xmlnodelist['vx_value'] = {
      name          : "xmlnodelist",
      pkgname       : "vx/data/xml",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_data_xml.t_xmlnode],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_data_xml.e_xmlnodelist['vx_type'] = vx_data_xml.t_xmlnodelist

    // (type xmlpropmap)
    vx_data_xml.t_xmlpropmap['vx_type'] = vx_core.t_type
    vx_data_xml.t_xmlpropmap['vx_value'] = {
      name          : "xmlpropmap",
      pkgname       : "vx/data/xml",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_core.t_string],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_data_xml.e_xmlpropmap['vx_type'] = vx_data_xml.t_xmlpropmap
    vx_data_xml.e_xmlpropmap['vx_value'] = {}

    // (const delimxml)
    Object.assign(vx_data_xml.c_delimxml, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":delimlist",
      vx_core.f_new(
        vx_data_textblock.t_delimlist,
        vx_core.f_copy(
          vx_data_textblock.c_delimbracketangle,
          ":delimlist",
          vx_core.f_new(
            vx_data_textblock.t_delimlist,
            vx_data_xml.c_delimxmlequal,
            vx_data_textblock.c_delimquote
          )
        )
      )
    ))

    // (const delimxmlequal)
    Object.assign(vx_data_xml.c_delimxmlequal, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":starttext",
      "="
    ))

    // (func xml<-textblock)
    vx_data_xml.t_xml_from_textblock['vx_type'] = vx_core.t_type
    vx_data_xml.t_xml_from_textblock['vx_value'] = {
      name          : "xml<-textblock",
      pkgname       : "vx/data/xml",
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
      fn            : vx_data_xml.f_xml_from_textblock
    }

  }
}
