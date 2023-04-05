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
   * @function xml_from_textblock
   * @param  {} textblock
   * @return {xml}
   */
  static t_xml_from_textblock = {}
  static e_xml_from_textblock = {vx_type: vx_data_xml.t_xml_from_textblock}

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

  static c_empty = {
    "xml": vx_data_xml.e_xml,
    "xmlnode": vx_data_xml.e_xmlnode,
    "xmlnodelist": vx_data_xml.e_xmlnodelist,
    "xmlpropmap": vx_data_xml.e_xmlpropmap,
    "xml<-textblock": vx_data_xml.e_xml_from_textblock
  }


  static {
    vx_core.f_global_package_set("vx/data/xml", vx_data_xml)

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

    // (func xml_from_textblock)
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
