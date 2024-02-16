'strict mode'

import vx_core from "../../vx/core.js"
import vx_data_csv from "../../vx/data/csv.js"
import vx_data_textblock from "../../vx/data/textblock.js"
import vx_data_xml from "../../vx/data/xml.js"


export default class vx_web_http {


  /**
   * type: response
   */
  static t_response = {}
  static e_response = {vx_type: vx_web_http.t_response}
  /**
   * 
   * @async @function csv_from_httpget
   * Returns a csv file from an httpget
   * @param  {string} url
   * @return {csv}
   */
  static t_csv_from_httpget = {
    vx_type: vx_core.t_type
  }
  static e_csv_from_httpget = {
    vx_type: vx_web_http.t_csv_from_httpget
  }

  // (func csv<-httpget)
  static async f_csv_from_httpget(url) {
    let output = Promise.resolve(vx_data_csv.e_csv)
    output = await vx_core.f_let_async(
      {"any-1": vx_data_csv.t_csv},
      [],
      vx_core.f_new(vx_core.t_any_from_func, async () => {
        const textblock = await vx_web_http.f_textblock_from_httpget(url, "text/csv")
        return vx_data_csv.f_csv_from_textblock(textblock)
      })
    )
    return output
  }

  /**
   * 
   * @async @function json_from_httpget
   * Returns a json response from an httpget
   * @param  {string} url
   * @return {response}
   */
  static t_json_from_httpget = {
    vx_type: vx_core.t_type
  }
  static e_json_from_httpget = {
    vx_type: vx_web_http.t_json_from_httpget
  }

  // (func json<-httpget)
  static async f_json_from_httpget(url) {
    let output = Promise.resolve(vx_web_http.e_response)
    output = await vx_core.f_let_async(
      {"any-1": vx_web_http.t_response},
      [],
      vx_core.f_new(vx_core.t_any_from_func, async () => {
        const response = await vx_web_http.f_response_from_httpget(url, "application/json")
        return response
      })
    )
    return output
  }

  /**
   * 
   * @async @function response_from_httpget
   * Returns a response from an httpget
   * @param  {string} url
   * @param  {string} contenttype
   * @return {response}
   */
  static t_response_from_httpget = {
    vx_type: vx_core.t_type
  }
  static e_response_from_httpget = {
    vx_type: vx_web_http.t_response_from_httpget
  }

  // (func response<-httpget)
  static async f_response_from_httpget(url, contenttype) {
    let output = Promise.resolve(vx_web_http.e_response)
    output = fetch(url,
     {mode: 'no-cors',
      method: 'GET',
      headers: {
       'Content-Type': contenttype
      }})
    return output
  }

  /**
   * 
   * @async @function text_from_httpget
   * Returns string from an httpget
   * @param  {string} url
   * @return {string}
   */
  static t_text_from_httpget = {
    vx_type: vx_core.t_type
  }
  static e_text_from_httpget = {
    vx_type: vx_web_http.t_text_from_httpget
  }

  // (func text<-httpget)
  static async f_text_from_httpget(url) {
    let output = Promise.resolve(vx_core.e_string)
    output = await vx_core.f_let_async(
      {"any-1": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, async () => {
        const response = await vx_web_http.f_response_from_httpget(url, "text/plain")
        return vx_web_http.f_text_from_response(response)
      })
    )
    return output
  }

  /**
   * @function text_from_response
   * Returns a string from a response
   * @param  {response} response
   * @return {string}
   */
  static t_text_from_response = {
    vx_type: vx_core.t_type
  }
  static e_text_from_response = {
    vx_type: vx_web_http.t_text_from_response
  }

  // (func text<-response)
  static f_text_from_response(response) {
    let output = vx_core.e_string
    output = response.text()
    return output
  }

  /**
   * 
   * @async @function textblock_from_httpget
   * Returns a textblock from an httpget
   * @param  {string} url
   * @param  {string} contenttype
   * @return {textblock}
   */
  static t_textblock_from_httpget = {
    vx_type: vx_core.t_type
  }
  static e_textblock_from_httpget = {
    vx_type: vx_web_http.t_textblock_from_httpget
  }

  // (func textblock<-httpget)
  static async f_textblock_from_httpget(url, contenttype) {
    let output = Promise.resolve(vx_data_textblock.e_textblock)
    output = await vx_core.f_let_async(
      {"any-1": vx_data_textblock.t_textblock},
      [],
      vx_core.f_new(vx_core.t_any_from_func, async () => {
        const response = await vx_web_http.f_response_from_httpget(url, contenttype)
        return vx_web_http.f_textblock_from_response(response)
      })
    )
    return output
  }

  /**
   * @function textblock_from_response
   * Returns a textblock from a response
   * @param  {response} response
   * @return {textblock}
   */
  static t_textblock_from_response = {
    vx_type: vx_core.t_type
  }
  static e_textblock_from_response = {
    vx_type: vx_web_http.t_textblock_from_response
  }

  // (func textblock<-response)
  static f_textblock_from_response(response) {
    let output = vx_data_textblock.e_textblock
    output = vx_core.f_new(
      vx_data_textblock.t_textblock,
      ":text",
      vx_web_http.f_text_from_response(response)
    )
    return output
  }

  /**
   * 
   * @async @function xml_from_httpget
   * Return Xml from an httpget
   * @param  {string} url
   * @return {xml}
   */
  static t_xml_from_httpget = {
    vx_type: vx_core.t_type
  }
  static e_xml_from_httpget = {
    vx_type: vx_web_http.t_xml_from_httpget
  }

  // (func xml<-httpget)
  static async f_xml_from_httpget(url) {
    let output = Promise.resolve(vx_data_xml.e_xml)
    output = await vx_core.f_let_async(
      {"any-1": vx_data_xml.t_xml},
      [],
      vx_core.f_new(vx_core.t_any_from_func, async () => {
        const textblock = await vx_web_http.f_textblock_from_httpget(url, "text/xml")
        return vx_data_xml.f_xml_from_textblock(textblock)
      })
    )
    return output
  }



  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "response": vx_web_http.e_response,
      "csv<-httpget": vx_web_http.e_csv_from_httpget,
      "json<-httpget": vx_web_http.e_json_from_httpget,
      "response<-httpget": vx_web_http.e_response_from_httpget,
      "text<-httpget": vx_web_http.e_text_from_httpget,
      "text<-response": vx_web_http.e_text_from_response,
      "textblock<-httpget": vx_web_http.e_textblock_from_httpget,
      "textblock<-response": vx_web_http.e_textblock_from_response,
      "xml<-httpget": vx_web_http.e_xml_from_httpget
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "csv<-httpget": vx_web_http.t_csv_from_httpget,
      "json<-httpget": vx_web_http.t_json_from_httpget,
      "response<-httpget": vx_web_http.t_response_from_httpget,
      "text<-httpget": vx_web_http.t_text_from_httpget,
      "text<-response": vx_web_http.t_text_from_response,
      "textblock<-httpget": vx_web_http.t_textblock_from_httpget,
      "textblock<-response": vx_web_http.t_textblock_from_response,
      "xml<-httpget": vx_web_http.t_xml_from_httpget
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      "response": vx_web_http.t_response
    })
    const pkg = vx_core.vx_new_struct(vx_core.t_package, {
      "name": "vx/web/http",
      "constmap": constmap,
      "emptymap": emptymap,
      "funcmap": funcmap,
      "typemap": typemap
    })
    vx_core.vx_global_package_set(pkg)

    // (type response)
    vx_web_http.t_response['vx_type'] = vx_core.t_type
    vx_web_http.t_response['vx_value'] = {
      name          : "response",
      pkgname       : "vx/web/http",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "ok": {
          "name" : "ok",
          "type" : vx_core.t_boolean,
          "multi": false
        },
        "status": {
          "name" : "status",
          "type" : vx_core.t_int,
          "multi": false
        }
      },
      proplast      : {
        "name" : "status",
        "type" : vx_core.t_int,
        "multi": false
      }
    }
    vx_web_http.e_response['vx_type'] = vx_web_http.t_response
    vx_web_http.e_response['vx_value'] = {}

    // (func csv<-httpget)
    vx_web_http.t_csv_from_httpget['vx_value'] = {
      name          : "csv<-httpget",
      pkgname       : "vx/web/http",
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
      fn            : vx_web_http.f_csv_from_httpget
    }

    // (func json<-httpget)
    vx_web_http.t_json_from_httpget['vx_value'] = {
      name          : "json<-httpget",
      pkgname       : "vx/web/http",
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
      fn            : vx_web_http.f_json_from_httpget
    }

    // (func response<-httpget)
    vx_web_http.t_response_from_httpget['vx_value'] = {
      name          : "response<-httpget",
      pkgname       : "vx/web/http",
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
      fn            : vx_web_http.f_response_from_httpget
    }

    // (func text<-httpget)
    vx_web_http.t_text_from_httpget['vx_value'] = {
      name          : "text<-httpget",
      pkgname       : "vx/web/http",
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
      fn            : vx_web_http.f_text_from_httpget
    }

    // (func text<-response)
    vx_web_http.t_text_from_response['vx_value'] = {
      name          : "text<-response",
      pkgname       : "vx/web/http",
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
      fn            : vx_web_http.f_text_from_response
    }

    // (func textblock<-httpget)
    vx_web_http.t_textblock_from_httpget['vx_value'] = {
      name          : "textblock<-httpget",
      pkgname       : "vx/web/http",
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
      fn            : vx_web_http.f_textblock_from_httpget
    }

    // (func textblock<-response)
    vx_web_http.t_textblock_from_response['vx_value'] = {
      name          : "textblock<-response",
      pkgname       : "vx/web/http",
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
      fn            : vx_web_http.f_textblock_from_response
    }

    // (func xml<-httpget)
    vx_web_http.t_xml_from_httpget['vx_value'] = {
      name          : "xml<-httpget",
      pkgname       : "vx/web/http",
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
      fn            : vx_web_http.f_xml_from_httpget
    }

  }
}
