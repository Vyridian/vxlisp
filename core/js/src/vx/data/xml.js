'strict mode'

import vx_core from "../../vx/core.js"
import vx_data_file from "../../vx/data/file.js"
import vx_data_textblock from "../../vx/data/textblock.js"
import vx_type from "../../vx/type.js"


export default class vx_data_xml {


  /**
   * type: xml
   */
  static t_xml = {}

  /**
   * type: xmllist
   */
  static t_xmllist = {}

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
   * Constant: delimxmlcdata
   * {delim}
   */
  static c_delimxmlcdata = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/data/xml', name: 'delimxmlcdata'}}

  /**
   * Constant: delimxmlcomment
   * {delim}
   */
  static c_delimxmlcomment = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/data/xml', name: 'delimxmlcomment'}}

  /**
   * Constant: delimxmlequal
   * {delim}
   */
  static c_delimxmlequal = {vx_type: vx_data_textblock.t_delim, vx_constdef: {pkgname: 'vx/data/xml', name: 'delimxmlequal'}}

  /**
   * @function string_first_from_xml
   * Returns string from first child's text.
   * @param  {xml} xml
   * @return {string}
   */
  static t_string_first_from_xml = {}
  static e_string_first_from_xml = {vx_type: vx_data_xml.t_string_first_from_xml}

  // (func string-first<-xml)
  static f_string_first_from_xml(xml) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const children = vx_core.f_any_from_struct({"any-1": vx_data_xml.t_xmllist, "struct-2": vx_data_xml.t_xml}, xml, ":children")
        const first = vx_core.f_any_from_list({"any-1": vx_data_xml.t_xml, "list-1": vx_data_xml.t_xmllist}, children, 1)
        const text = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_xml.t_xml}, first, ":text")
        const outdent = vx_type.f_string_outdent(text)
        const trim = vx_type.f_string_trim(outdent)
        return trim
      })
    )
    return output
  }

  /**
   * @function textblock_xml_from_string
   * Returns a parsed textblock from a string.
   * @param  {string} text
   * @return {textblock}
   */
  static t_textblock_xml_from_string = {}
  static e_textblock_xml_from_string = {vx_type: vx_data_xml.t_textblock_xml_from_string}

  // (func textblock-xml<-string)
  static f_textblock_xml_from_string(text) {
    let output = vx_data_textblock.e_textblock
    output = vx_data_textblock.f_textblock_parse_from_string_delim(
      text,
      vx_data_xml.c_delimxml
    )
    return output
  }

  /**
   * @function xml_angle_from_xml_textblock
   * Returns a modified xml from a single textblock.
   * @param  {xml} xmlarg
   * @param  {textblock} tb
   * @return {xml}
   */
  static t_xml_angle_from_xml_textblock = {}
  static e_xml_angle_from_xml_textblock = {vx_type: vx_data_xml.t_xml_angle_from_xml_textblock}

  // (func xml-angle<-xml-textblock)
  static f_xml_angle_from_xml_textblock(xmlarg, tb) {
    let output = vx_data_xml.e_xml
    output = vx_core.f_if_2(
      {"any-1": vx_data_xml.t_xml},
      vx_core.f_then(
        vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq(
          vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_textblock}, tb, ":text"),
          vx_core.f_new(
            vx_core.t_string,
            "</",
            vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_xml.t_xml}, xmlarg, ":tag"),
            ">"
          )
        )}),
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_data_xml.f_xml_close_from_xml_textblock(xmlarg, tb)})
      ),
      vx_core.f_else(
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_let(
          {"any-1": vx_data_xml.t_xml},
          [],
          vx_core.f_new(vx_core.t_any_from_func, () => {
            const children = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblocklist, "struct-2": vx_data_textblock.t_textblock}, tb, ":children")
            const xmlchg = vx_core.f_new(
              vx_data_xml.t_xml,
              ":tag",
              ":notag",
              ":parent",
              xmlarg
            )
            return vx_data_xml.f_xml_properties_from_xml_textblocklist(xmlchg, children)
          })
        )})
      )
    )
    return output
  }

  /**
   * @function xml_close_from_xml_textblock
   * Returns a modified xml from a closing tag.
   * @param  {xml} xmlarg
   * @param  {textblock} tb
   * @return {xml}
   */
  static t_xml_close_from_xml_textblock = {}
  static e_xml_close_from_xml_textblock = {vx_type: vx_data_xml.t_xml_close_from_xml_textblock}

  // (func xml-close<-xml-textblock)
  static f_xml_close_from_xml_textblock(xmlarg, tb) {
    let output = vx_data_xml.e_xml
    output = vx_core.f_let(
      {"any-1": vx_data_xml.t_xml},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const tag = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_xml.t_xml}, xmlarg, ":tag")
        const text = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_textblock}, tb, ":text")
        const parent = vx_core.f_any_from_struct({"any-1": vx_data_xml.t_xml, "struct-2": vx_data_xml.t_xml}, xmlarg, ":parent")
        const isnoparent = vx_core.f_is_empty_1(parent)
        return vx_core.f_if_2(
          {"any-1": vx_data_xml.t_xml},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_or(
              vx_core.f_eq("/", text),
              vx_core.f_eq(
                text,
                vx_core.f_new(
                  vx_core.t_string,
                  "</",
                  tag,
                  ">"
                )
              )
            )}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_if_2(
              {"any-1": vx_data_xml.t_xml},
              vx_core.f_then(vx_core.f_new(vx_core.t_boolean_from_func, () => {return isnoparent}), vx_core.f_new(vx_core.t_any_from_func, () => {return xmlarg})),
              vx_core.f_else(
                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(
                  parent,
                  ":children",
                  vx_core.f_new(
                    vx_data_xml.t_xmllist,
                    vx_core.f_any_from_struct({"any-1": vx_data_xml.t_xmllist, "struct-2": vx_data_xml.t_xml}, parent, ":children"),
                    vx_core.f_copy(
                      xmlarg,
                      ":parent",
                      vx_core.f_empty(
                        vx_data_xml.t_xml
                      )
                    )
                  )
                )})
              )
            )})
          ),
          vx_core.f_else(
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(
              xmlarg,
              vx_core.f_msg_from_error(
                vx_core.f_new(
                  vx_core.t_string,
                  "Invalid Xml Close tag: ",
                  text
                )
              )
            )})
          )
        )
      })
    )
    return output
  }

  /**
   * @function xml_parse_from_xml_textblock
   * Returns a modified xml from a single textblock.
   * @param  {xml} xmlarg
   * @param  {textblock} tb
   * @return {xml}
   */
  static t_xml_parse_from_xml_textblock = {}
  static e_xml_parse_from_xml_textblock = {vx_type: vx_data_xml.t_xml_parse_from_xml_textblock}

  // (func xml-parse<-xml-textblock)
  static f_xml_parse_from_xml_textblock(xmlarg, tb) {
    let output = vx_data_xml.e_xml
    output = vx_core.f_let(
      {"any-1": vx_data_xml.t_xml, "any-2": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const delim = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delim, "struct-2": vx_data_textblock.t_textblock}, tb, ":delim")
        const text = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_textblock}, tb, ":text")
        const starttext = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delim, ":starttext")
        return vx_core.f_switch(
          {"any-1": vx_data_xml.t_xml, "any-2": vx_core.t_string},
          starttext,
          vx_core.f_case_1(
            "",
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_data_xml.f_xml_text_from_xml_textblock(xmlarg, tb)})
          ),
          vx_core.f_case_1(
            vx_core.f_any_from_struct(
              {"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim},
              vx_data_textblock.c_delimbracketangle,
              ":starttext"
            ),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_data_xml.f_xml_angle_from_xml_textblock(xmlarg, tb)})
          ),
          vx_core.f_case_1(
            vx_core.f_any_from_struct(
              {"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim},
              vx_data_textblock.c_delimwhitespace,
              ":starttext"
            ),
            vx_core.f_new(vx_core.t_any_from_func, () => {return xmlarg})
          ),
          vx_core.f_case_1(
            vx_core.f_any_from_struct(
              {"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim},
              vx_data_xml.c_delimxmlcomment,
              ":starttext"
            ),
            vx_core.f_new(vx_core.t_any_from_func, () => {return xmlarg})
          ),
          vx_core.f_case_1(
            vx_core.f_any_from_struct(
              {"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim},
              vx_data_xml.c_delimxmlcdata,
              ":starttext"
            ),
            vx_core.f_new(vx_core.t_any_from_func, () => {return xmlarg})
          )
        )
      })
    )
    return output
  }

  /**
   * @function xml_parse_from_xml_textblocklist
   * Returns a modified xml from a textblocklist.
   * @param  {xml} xmlarg
   * @param  {textblocklist} textblocklist
   * @return {xml}
   */
  static t_xml_parse_from_xml_textblocklist = {}
  static e_xml_parse_from_xml_textblocklist = {vx_type: vx_data_xml.t_xml_parse_from_xml_textblocklist}

  // (func xml-parse<-xml-textblocklist)
  static f_xml_parse_from_xml_textblocklist(xmlarg, textblocklist) {
    let output = vx_data_xml.e_xml
    output = vx_core.f_any_from_list_start_reduce(
      {"any-1": vx_data_xml.t_xml, "any-2": vx_data_textblock.t_textblock, "list-2": vx_data_textblock.t_textblocklist},
      textblocklist,
      xmlarg,
      vx_core.f_new(vx_core.t_any_from_reduce, (reduce, current) => 
        vx_data_xml.f_xml_parse_from_xml_textblock(reduce, current))
    )
    return output
  }

  /**
   * @function xml_properties_from_xml_textblocklist
   * Returns a modified xml from a textblocklist.
   * @param  {xml} xmlarg
   * @param  {textblocklist} textblocklist
   * @return {xml}
   */
  static t_xml_properties_from_xml_textblocklist = {}
  static e_xml_properties_from_xml_textblocklist = {vx_type: vx_data_xml.t_xml_properties_from_xml_textblocklist}

  // (func xml-properties<-xml-textblocklist)
  static f_xml_properties_from_xml_textblocklist(xmlarg, textblocklist) {
    let output = vx_data_xml.e_xml
    output = vx_core.f_let(
      {"any-1": vx_data_xml.t_xml},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const xmlchg = vx_core.f_any_from_list_start_reduce(
          {"any-1": vx_data_xml.t_xml, "any-2": vx_data_textblock.t_textblock, "list-2": vx_data_textblock.t_textblocklist},
          textblocklist,
          xmlarg,
          vx_core.f_new(vx_core.t_any_from_reduce, (reduce, current) => 
            vx_data_xml.f_xml_property_from_xml_textblock(reduce, current))
        )
        return xmlchg
      })
    )
    return output
  }

  /**
   * @function xml_property_from_xml_textblock
   * Returns a modified xml from a single property.
   * @param  {xml} xmlarg
   * @param  {textblock} tbarg
   * @return {xml}
   */
  static t_xml_property_from_xml_textblock = {}
  static e_xml_property_from_xml_textblock = {vx_type: vx_data_xml.t_xml_property_from_xml_textblock}

  // (func xml-property<-xml-textblock)
  static f_xml_property_from_xml_textblock(xmlarg, tbarg) {
    let output = vx_data_xml.e_xml
    output = vx_core.f_let(
      {"any-1": vx_data_xml.t_xml, "any-2": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const delim = vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_delim, "struct-2": vx_data_textblock.t_textblock}, tbarg, ":delim")
        const text = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_textblock}, tbarg, ":text")
        const delimname = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_delim}, delim, ":name")
        const tag = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_xml.t_xml}, xmlarg, ":tag")
        const prop = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_xml.t_xml}, xmlarg, ":prop")
        const propmap = vx_core.f_any_from_struct({"any-1": vx_core.t_stringmap, "struct-2": vx_data_xml.t_xml}, xmlarg, ":propmap")
        return vx_core.f_switch(
          {"any-1": vx_data_xml.t_xml, "any-2": vx_core.t_string},
          delimname,
          vx_core.f_case_1(
            "",
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_if_2(
              {"any-1": vx_data_xml.t_xml},
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_type.f_boolean_from_string_starts(text, "/")}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_data_xml.f_xml_close_from_xml_textblock(xmlarg, tbarg)})
              ),
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq(":notag", tag)}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(xmlarg, ":tag", text)})
              ),
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq("", prop)}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(xmlarg, ":prop", text)})
              )
            )})
          ),
          vx_core.f_case_1(
            "delimquote",
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_if_1(
              {"any-1": vx_data_xml.t_xml},
              vx_core.f_eq("", prop),
              vx_core.f_copy(
                xmlarg,
                vx_core.f_msg_from_error("Found quoted text with no matching attribute.")
              ),
              vx_core.f_copy(
                xmlarg,
                ":prop",
                "",
                ":propmap",
                vx_core.f_copy(
                  propmap,
                  prop,
                  vx_core.f_any_from_struct(
                    {"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_textblock},
                    vx_core.f_any_from_list(
                      {"any-1": vx_data_textblock.t_textblock, "list-1": vx_data_textblock.t_textblocklist},
                      vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblocklist, "struct-2": vx_data_textblock.t_textblock}, tbarg, ":children"),
                      1
                    ),
                    ":text"
                  )
                )
              )
            )})
          ),
          vx_core.f_else(vx_core.f_new(vx_core.t_any_from_func, () => {return xmlarg}))
        )
      })
    )
    return output
  }

  /**
   * @function xml_read_from_file
   * Returns a parsed xml from a file.
   * @param  {file} file
   * @return {xml}
   */
  static t_xml_read_from_file = {}
  static e_xml_read_from_file = {vx_type: vx_data_xml.t_xml_read_from_file}

  // (func xml-read<-file)
  static f_xml_read_from_file(context, file) {
    let output = vx_data_xml.e_xml
    output = vx_core.f_let(
      {"any-1": vx_data_xml.t_xml},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const loaded = vx_data_file.f_file_read_from_file(context, file)
        return vx_data_xml.f_xml_from_file(loaded)
      })
    )
    return output
  }

  /**
   * @function xml_text_from_xml_textblock
   * Returns a modified xml from text.
   * @param  {xml} xmlarg
   * @param  {textblock} tb
   * @return {xml}
   */
  static t_xml_text_from_xml_textblock = {}
  static e_xml_text_from_xml_textblock = {vx_type: vx_data_xml.t_xml_text_from_xml_textblock}

  // (func xml-text<-xml-textblock)
  static f_xml_text_from_xml_textblock(xmlarg, tb) {
    let output = vx_data_xml.e_xml
    output = vx_core.f_let(
      {"any-1": vx_data_xml.t_xml},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const text = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_textblock.t_textblock}, tb, ":text")
        const xmlchg = vx_core.f_new(
          vx_data_xml.t_xml,
          ":text",
          text
        )
        return vx_core.f_if_2(
          {"any-1": vx_data_xml.t_xml},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty_1(xmlarg)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return xmlchg})
          ),
          vx_core.f_else(
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(
              xmlarg,
              ":children",
              vx_core.f_new(
                vx_data_xml.t_xmllist,
                vx_core.f_any_from_struct({"any-1": vx_data_xml.t_xmllist, "struct-2": vx_data_xml.t_xml}, xmlarg, ":children"),
                xmlchg
              )
            )})
          )
        )
      })
    )
    return output
  }

  /**
   * @function xml_from_file
   * Returns a parsed xml from a file.
   * @param  {file} file
   * @return {xml}
   */
  static t_xml_from_file = {}
  static e_xml_from_file = {vx_type: vx_data_xml.t_xml_from_file}

  // (func xml<-file)
  static f_xml_from_file(file) {
    let output = vx_data_xml.e_xml
    output = vx_core.f_let(
      {"any-1": vx_data_xml.t_xml},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const text = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_data_file.t_file}, file, ":text")
        return vx_data_xml.f_xml_from_string(text)
      })
    )
    return output
  }

  /**
   * @function xml_from_string
   * Returns a parsed xml from a string.
   * @param  {string} text
   * @return {xml}
   */
  static t_xml_from_string = {}
  static e_xml_from_string = {vx_type: vx_data_xml.t_xml_from_string}

  // (func xml<-string)
  static f_xml_from_string(text) {
    let output = vx_data_xml.e_xml
    output = vx_data_xml.f_xml_from_textblock(
      vx_data_xml.f_textblock_xml_from_string(text)
    )
    return output
  }

  /**
   * @function xml_from_textblock
   * Returns a parsed xml from a textblock.
   * @param  {textblock} textblock
   * @return {xml}
   */
  static t_xml_from_textblock = {}
  static e_xml_from_textblock = {vx_type: vx_data_xml.t_xml_from_textblock}

  // (func xml<-textblock)
  static f_xml_from_textblock(textblock) {
    let output = vx_data_xml.e_xml
    output = vx_data_xml.f_xml_parse_from_xml_textblocklist(
      vx_core.f_empty(
        vx_data_xml.t_xml
      ),
      vx_core.f_any_from_struct({"any-1": vx_data_textblock.t_textblocklist, "struct-2": vx_data_textblock.t_textblock}, textblock, ":children")
    )
    return output
  }

  // empty types
  static e_xml = {}
  static e_xmllist = []
  static e_xmlpropmap = {}


  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      "delimxml": vx_data_xml.c_delimxml,
      "delimxmlcdata": vx_data_xml.c_delimxmlcdata,
      "delimxmlcomment": vx_data_xml.c_delimxmlcomment,
      "delimxmlequal": vx_data_xml.c_delimxmlequal
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "xml": vx_data_xml.e_xml,
      "xmllist": vx_data_xml.e_xmllist,
      "xmlpropmap": vx_data_xml.e_xmlpropmap,
      "string-first<-xml": vx_data_xml.e_string_first_from_xml,
      "textblock-xml<-string": vx_data_xml.e_textblock_xml_from_string,
      "xml-angle<-xml-textblock": vx_data_xml.e_xml_angle_from_xml_textblock,
      "xml-close<-xml-textblock": vx_data_xml.e_xml_close_from_xml_textblock,
      "xml-parse<-xml-textblock": vx_data_xml.e_xml_parse_from_xml_textblock,
      "xml-parse<-xml-textblocklist": vx_data_xml.e_xml_parse_from_xml_textblocklist,
      "xml-properties<-xml-textblocklist": vx_data_xml.e_xml_properties_from_xml_textblocklist,
      "xml-property<-xml-textblock": vx_data_xml.e_xml_property_from_xml_textblock,
      "xml-read<-file": vx_data_xml.e_xml_read_from_file,
      "xml-text<-xml-textblock": vx_data_xml.e_xml_text_from_xml_textblock,
      "xml<-file": vx_data_xml.e_xml_from_file,
      "xml<-string": vx_data_xml.e_xml_from_string,
      "xml<-textblock": vx_data_xml.e_xml_from_textblock
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "string-first<-xml": vx_data_xml.t_string_first_from_xml,
      "textblock-xml<-string": vx_data_xml.t_textblock_xml_from_string,
      "xml-angle<-xml-textblock": vx_data_xml.t_xml_angle_from_xml_textblock,
      "xml-close<-xml-textblock": vx_data_xml.t_xml_close_from_xml_textblock,
      "xml-parse<-xml-textblock": vx_data_xml.t_xml_parse_from_xml_textblock,
      "xml-parse<-xml-textblocklist": vx_data_xml.t_xml_parse_from_xml_textblocklist,
      "xml-properties<-xml-textblocklist": vx_data_xml.t_xml_properties_from_xml_textblocklist,
      "xml-property<-xml-textblock": vx_data_xml.t_xml_property_from_xml_textblock,
      "xml-read<-file": vx_data_xml.t_xml_read_from_file,
      "xml-text<-xml-textblock": vx_data_xml.t_xml_text_from_xml_textblock,
      "xml<-file": vx_data_xml.t_xml_from_file,
      "xml<-string": vx_data_xml.t_xml_from_string,
      "xml<-textblock": vx_data_xml.t_xml_from_textblock
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      "xml": vx_data_xml.t_xml,
      "xmllist": vx_data_xml.t_xmllist,
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
        "tag": {
          "name" : "tag",
          "type" : vx_core.t_string,
          "multi": false
        },
        "text": {
          "name" : "text",
          "type" : vx_core.t_string,
          "multi": false
        },
        "prop": {
          "name" : "prop",
          "type" : vx_core.t_string,
          "multi": false
        },
        "propmap": {
          "name" : "propmap",
          "type" : vx_core.t_stringmap,
          "multi": false
        },
        "children": {
          "name" : "children",
          "type" : vx_data_xml.t_xmllist,
          "multi": false
        },
        "parent": {
          "name" : "parent",
          "type" : vx_data_xml.t_xml,
          "multi": false
        }
      },
      proplast      : {
        "name" : "parent",
        "type" : vx_data_xml.t_xml,
        "multi": false
      }
    }
    vx_data_xml.e_xml['vx_type'] = vx_data_xml.t_xml
    vx_data_xml.e_xml['vx_value'] = {}

    // (type xmllist)
    vx_data_xml.t_xmllist['vx_type'] = vx_core.t_type
    vx_data_xml.t_xmllist['vx_value'] = {
      name          : "xmllist",
      pkgname       : "vx/data/xml",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_data_xml.t_xml],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_data_xml.e_xmllist['vx_type'] = vx_data_xml.t_xmllist

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
        vx_data_xml.c_delimxmlcomment,
        vx_data_xml.c_delimxmlcdata,
        vx_core.f_copy(
          vx_data_textblock.c_delimbracketangle,
          ":delimlist",
          vx_core.f_new(
            vx_data_textblock.t_delimlist,
            vx_data_xml.c_delimxmlequal,
            vx_data_textblock.c_delimwhitespace,
            vx_data_textblock.c_delimquote
          )
        )
      )
    ))

    // (const delimxmlcdata)
    Object.assign(vx_data_xml.c_delimxmlcdata, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":name",
      "delimxmlcomment",
      ":starttext",
      "<![CDATA[",
      ":endtext",
      "]]>"
    ))

    // (const delimxmlcomment)
    Object.assign(vx_data_xml.c_delimxmlcomment, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":name",
      "delimxmlcomment",
      ":starttext",
      "<!--",
      ":endtext",
      "-->"
    ))

    // (const delimxmlequal)
    Object.assign(vx_data_xml.c_delimxmlequal, vx_core.f_new(
      vx_data_textblock.t_delim,
      ":name",
      "delimxmlequal",
      ":starttext",
      "="
    ))

    // (func string-first<-xml)
    vx_data_xml.t_string_first_from_xml['vx_type'] = vx_core.t_type
    vx_data_xml.t_string_first_from_xml['vx_value'] = {
      name          : "string-first<-xml",
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
      fn            : vx_data_xml.f_string_first_from_xml
    }

    // (func textblock-xml<-string)
    vx_data_xml.t_textblock_xml_from_string['vx_type'] = vx_core.t_type
    vx_data_xml.t_textblock_xml_from_string['vx_value'] = {
      name          : "textblock-xml<-string",
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
      fn            : vx_data_xml.f_textblock_xml_from_string
    }

    // (func xml-angle<-xml-textblock)
    vx_data_xml.t_xml_angle_from_xml_textblock['vx_type'] = vx_core.t_type
    vx_data_xml.t_xml_angle_from_xml_textblock['vx_value'] = {
      name          : "xml-angle<-xml-textblock",
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
      fn            : vx_data_xml.f_xml_angle_from_xml_textblock
    }

    // (func xml-close<-xml-textblock)
    vx_data_xml.t_xml_close_from_xml_textblock['vx_type'] = vx_core.t_type
    vx_data_xml.t_xml_close_from_xml_textblock['vx_value'] = {
      name          : "xml-close<-xml-textblock",
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
      fn            : vx_data_xml.f_xml_close_from_xml_textblock
    }

    // (func xml-parse<-xml-textblock)
    vx_data_xml.t_xml_parse_from_xml_textblock['vx_type'] = vx_core.t_type
    vx_data_xml.t_xml_parse_from_xml_textblock['vx_value'] = {
      name          : "xml-parse<-xml-textblock",
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
      fn            : vx_data_xml.f_xml_parse_from_xml_textblock
    }

    // (func xml-parse<-xml-textblocklist)
    vx_data_xml.t_xml_parse_from_xml_textblocklist['vx_type'] = vx_core.t_type
    vx_data_xml.t_xml_parse_from_xml_textblocklist['vx_value'] = {
      name          : "xml-parse<-xml-textblocklist",
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
      fn            : vx_data_xml.f_xml_parse_from_xml_textblocklist
    }

    // (func xml-properties<-xml-textblocklist)
    vx_data_xml.t_xml_properties_from_xml_textblocklist['vx_type'] = vx_core.t_type
    vx_data_xml.t_xml_properties_from_xml_textblocklist['vx_value'] = {
      name          : "xml-properties<-xml-textblocklist",
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
      fn            : vx_data_xml.f_xml_properties_from_xml_textblocklist
    }

    // (func xml-property<-xml-textblock)
    vx_data_xml.t_xml_property_from_xml_textblock['vx_type'] = vx_core.t_type
    vx_data_xml.t_xml_property_from_xml_textblock['vx_value'] = {
      name          : "xml-property<-xml-textblock",
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
      fn            : vx_data_xml.f_xml_property_from_xml_textblock
    }

    // (func xml-read<-file)
    vx_data_xml.t_xml_read_from_file['vx_type'] = vx_core.t_type
    vx_data_xml.t_xml_read_from_file['vx_value'] = {
      name          : "xml-read<-file",
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
      fn            : vx_data_xml.f_xml_read_from_file
    }

    // (func xml-text<-xml-textblock)
    vx_data_xml.t_xml_text_from_xml_textblock['vx_type'] = vx_core.t_type
    vx_data_xml.t_xml_text_from_xml_textblock['vx_value'] = {
      name          : "xml-text<-xml-textblock",
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
      fn            : vx_data_xml.f_xml_text_from_xml_textblock
    }

    // (func xml<-file)
    vx_data_xml.t_xml_from_file['vx_type'] = vx_core.t_type
    vx_data_xml.t_xml_from_file['vx_value'] = {
      name          : "xml<-file",
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
      fn            : vx_data_xml.f_xml_from_file
    }

    // (func xml<-string)
    vx_data_xml.t_xml_from_string['vx_type'] = vx_core.t_type
    vx_data_xml.t_xml_from_string['vx_value'] = {
      name          : "xml<-string",
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
      fn            : vx_data_xml.f_xml_from_string
    }

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
