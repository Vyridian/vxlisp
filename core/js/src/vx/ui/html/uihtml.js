'strict mode'

import vx_core from "../../../vx/core.js"
import vx_data_file from "../../../vx/data/file.js"
import vx_web_html from "../../../vx/web/html.js"
import vx_web_htmldoc from "../../../vx/web/htmldoc.js"
import vx_event from "../../../vx/event.js"
import vx_type from "../../../vx/type.js"
import vx_ui_ui from "../../../vx/ui/ui.js"


export default class vx_ui_html_uihtml {

  /**
   * Constant: layout-app-html
   * Html App Renderer
   * {layout}
   */
  static c_layout_app_html = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/html/uihtml', name: 'layout-app-html'}}

  /**
   * Constant: layout-else-html
   * Html Default Renderer
   * {layout}
   */
  static c_layout_else_html = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/html/uihtml', name: 'layout-else-html'}}

  /**
   * Constant: layout-label-html
   * Html Label Renderer
   * {layout}
   */
  static c_layout_label_html = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/html/uihtml', name: 'layout-label-html'}}

  /**
   * Constant: layoutenginehtml
   * Html layout engine used to render html from ui and stylesheet
   * {layoutengine}
   */
  static c_layoutenginehtml = {vx_type: vx_ui_ui.t_layoutengine, vx_constdef: {pkgname: 'vx/ui/html/uihtml', name: 'layoutenginehtml'}}

  /**
   * Constant: style-hidden
   * {style}
   */
  static c_style_hidden = {vx_type: vx_web_html.t_style, vx_constdef: {pkgname: 'vx/ui/html/uihtml', name: 'style-hidden'}}

  /**
   * Constant: style-selected
   * {style}
   */
  static c_style_selected = {vx_type: vx_web_html.t_style, vx_constdef: {pkgname: 'vx/ui/html/uihtml', name: 'style-selected'}}

  /**
   * @function boolean_print_html
   * Create a print ready version of ui
   * @param  {ui} ui
   * @return {boolean}
   */
  static t_boolean_print_html = {
    vx_type: vx_core.t_type
  }
  static e_boolean_print_html = {
    vx_type: vx_ui_html_uihtml.t_boolean_print_html
  }

  // (func boolean-print-html)
  static f_boolean_print_html(context, ui) {
    let output = vx_core.e_boolean
    output = vx_core.f_let(
      {"any-1": vx_core.t_boolean},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const uid = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_ui_ui.t_ui}, ui, ":uid")
        const stylesheetui = vx_ui_ui.f_stylesheet_readstate(context)
        const stylesheethtml = vx_ui_html_uihtml.f_stylesheet_from_stylesheet(stylesheetui)
        const styletext = vx_web_html.f_string_from_stylesheet_indent(stylesheethtml, 0)
        return vx_web_htmldoc.f_boolean_print_from_id_stylesheettext(uid, styletext)
      })
    )
    return output
  }

  /**
   * @function context_write
   * @return {context}
   */
  static t_context_write = {
    vx_type: vx_core.t_type
  }
  static e_context_write = {
    vx_type: vx_ui_html_uihtml.t_context_write
  }

  // (func context-write)
  static f_context_write(context) {
    let output = vx_core.e_context
    output = vx_web_htmldoc.f_context_write(context)
    return output
  }

  /**
   * @function divchild_from_ui
   * Returns a divchildlist of empty divs from a uimap
   * @param  {ui} ui
   * @return {divchild}
   */
  static t_divchild_from_ui = {
    vx_type: vx_core.t_type
  }
  static e_divchild_from_ui = {
    vx_type: vx_ui_html_uihtml.t_divchild_from_ui
  }

  // (func divchild<-ui)
  static f_divchild_from_ui(ui) {
    let output = vx_web_html.e_divchild
    output = vx_core.f_let(
      {"any-1": vx_web_html.t_div},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const uid = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_ui_ui.t_ui}, ui, ":uid")
        const uimapchild = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_uimap, "struct-2": vx_ui_ui.t_ui}, ui, ":uimap")
        const uistyle = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_style, "struct-2": vx_ui_ui.t_ui}, ui, ":style")
        const uistyles = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_stylelist, "struct-2": vx_ui_ui.t_ui}, ui, ":stylelist")
        const styleunique = vx_ui_html_uihtml.f_style_from_style(uistyle)
        const htmlstyles = vx_ui_html_uihtml.f_stylelist_from_stylelist(uistyles)
        return vx_core.f_new(
          vx_web_html.t_div,
          ":id",
          uid,
          ":style-unique",
          styleunique,
          ":stylelist",
          htmlstyles
        )
      })
    )
    return output
  }

  /**
   * @function divchildlist_from_uimap
   * Returns a divchildlist of empty divs from a uimap
   * @param  {uimap} uimap
   * @return {divchildlist}
   */
  static t_divchildlist_from_uimap = {
    vx_type: vx_core.t_type
  }
  static e_divchildlist_from_uimap = {
    vx_type: vx_ui_html_uihtml.t_divchildlist_from_uimap
  }

  // (func divchildlist<-uimap)
  static f_divchildlist_from_uimap(uimap) {
    let output = vx_web_html.e_divchildlist
    output = vx_core.f_list_from_map_1(
      {"any-1": vx_web_html.t_divchild, "any-2": vx_ui_ui.t_ui, "list-1": vx_web_html.t_divchildlist, "map-2": vx_ui_ui.t_uimap},
      uimap,
      vx_core.f_new(vx_core.t_any_from_key_value, ([key, value]) => 
        vx_core.f_let(
          {"any-1": vx_web_html.t_div},
          [],
          vx_core.f_new(vx_core.t_any_from_func, () => {
            const uid = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_ui_ui.t_ui}, value, ":uid")
            return vx_core.f_new(
              vx_web_html.t_div,
              ":id",
              uid
            )
          })
        ))
    )
    return output
  }

  /**
   * @function node_app_from_ui_orig_parent
   * @param  {ui} ui
   * @param  {ui} orig
   * @param  {ui} parent
   * @return {node}
   */
  static t_node_app_from_ui_orig_parent = {
    vx_type: vx_core.t_type
  }
  static e_node_app_from_ui_orig_parent = {
    vx_type: vx_ui_html_uihtml.t_node_app_from_ui_orig_parent
  }

  // (func node-app<-ui-orig-parent)
  static f_node_app_from_ui_orig_parent(ui, orig, parent) {
    let output = vx_web_html.e_node
    output = vx_core.f_empty(
      vx_web_html.t_div
    )
    return output
  }

  /**
   * @function node_render_from_node_ui
   * @param  {node} node
   * @param  {ui} ui
   * @return {node}
   */
  static t_node_render_from_node_ui = {
    vx_type: vx_core.t_type
  }
  static e_node_render_from_node_ui = {
    vx_type: vx_ui_html_uihtml.t_node_render_from_node_ui
  }

  // (func node-render<-node-ui)
  static f_node_render_from_node_ui(node, ui) {
    let output = vx_web_html.e_node
    output = vx_core.f_let(
      {"any-1": vx_web_html.t_node},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const htmltext = vx_web_html.f_string_from_node_indent(node, 2)
        const htmldone = vx_web_htmldoc.f_boolean_replace_from_ui_htmltext(ui, htmltext)
        return node
      })
    )
    return output
  }

  /**
   * @function string_style_from_font
   * Returns a font css string from a logical font.
   * @param  {font} font
   * @return {string}
   */
  static t_string_style_from_font = {
    vx_type: vx_core.t_type
  }
  static e_string_style_from_font = {
    vx_type: vx_ui_html_uihtml.t_string_style_from_font
  }

  // (func string-style<-font)
  static f_string_style_from_font(font) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const face = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_fontface, "struct-2": vx_ui_ui.t_font}, font, ":fontface")
        const size = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_ui_ui.t_font}, font, ":fontsize")
        const name = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_ui_ui.t_fontface}, face, ":name")
        const ssize = vx_core.f_if_2(
          {"any-1": vx_core.t_string},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_gt(size, 0)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
              vx_core.t_string,
              vx_core.f_divide(size, 100),
              "em",
              " "
            )})
          )
        )
        return vx_core.f_if_2(
          {"any-1": vx_core.t_string},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_notempty(name)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
              vx_core.t_string,
              ssize,
              vx_core.c_quote,
              name,
              vx_core.c_quote
            )})
          )
        )
      })
    )
    return output
  }

  /**
   * @function string_style_from_image
   * Returns an image css string from a logical image.
   * @param  {image} image
   * @return {string}
   */
  static t_string_style_from_image = {
    vx_type: vx_core.t_type
  }
  static e_string_style_from_image = {
    vx_type: vx_ui_html_uihtml.t_string_style_from_image
  }

  // (func string-style<-image)
  static f_string_style_from_image(image) {
    let output = vx_core.e_string
    output = vx_core.f_if_2(
      {"any-1": vx_core.t_string},
      vx_core.f_then(
        vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_notempty_1(image)}),
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_let(
          {"any-1": vx_core.t_string},
          [],
          vx_core.f_new(vx_core.t_any_from_func, () => {
            const file = vx_core.f_any_from_struct({"any-1": vx_data_file.t_file, "struct-2": vx_ui_ui.t_image}, image, ":file")
            const url = vx_data_file.f_pathfull_from_file(file)
            return vx_core.f_if_2(
              {"any-1": vx_core.t_string},
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_notempty(url)}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
                  vx_core.t_string,
                  "url(",
                  url,
                  ")"
                )})
              )
            )
          })
        )})
      )
    )
    return output
  }

  /**
   * @function string_stylename_from_name_styletype
   * @param  {string} name
   * @param  {styletype} styletype
   * @return {string}
   */
  static t_string_stylename_from_name_styletype = {
    vx_type: vx_core.t_type
  }
  static e_string_stylename_from_name_styletype = {
    vx_type: vx_ui_html_uihtml.t_string_stylename_from_name_styletype
  }

  // (func string-stylename<-name-styletype)
  static f_string_stylename_from_name_styletype(name, styletype) {
    let output = vx_core.e_string
    output = vx_core.f_if_2(
      {"any-1": vx_core.t_string},
      vx_core.f_then(
        vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq("", name)}),
        vx_core.f_new(vx_core.t_any_from_func, () => {return ""})
      ),
      vx_core.f_then(
        vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eqeq(
          styletype,
          vx_ui_ui.c_styletype_shared
        )}),
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
          vx_core.t_string,
          ".",
          name
        )})
      ),
      vx_core.f_then(
        vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eqeq(
          styletype,
          vx_ui_ui.c_styletype_system
        )}),
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
          vx_core.t_string,
          "#",
          name
        )})
      ),
      vx_core.f_else(vx_core.f_new(vx_core.t_any_from_func, () => {return name}))
    )
    return output
  }

  /**
   * @function style_from_fontface
   * Returns an html style from a font
   * @param  {fontface} fontface
   * @return {style}
   */
  static t_style_from_fontface = {
    vx_type: vx_core.t_type
  }
  static e_style_from_fontface = {
    vx_type: vx_ui_html_uihtml.t_style_from_fontface
  }

  // (func style<-fontface)
  static f_style_from_fontface(fontface) {
    let output = vx_web_html.e_style
    output = vx_core.f_let(
      {"any-1": vx_web_html.t_style},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const name = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_ui_ui.t_fontface}, fontface, ":name")
        const weight = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_ui_ui.t_fontface}, fontface, ":weight")
        const unicode = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_ui_ui.t_fontface}, fontface, ":unicode")
        const files = vx_core.f_any_from_struct({"any-1": vx_data_file.t_filelist, "struct-2": vx_ui_ui.t_fontface}, fontface, ":filelist")
        const urls = vx_core.f_list_from_list_1(
          {"any-1": vx_core.t_string, "any-2": vx_data_file.t_file, "list-1": vx_core.t_stringlist, "list-2": vx_data_file.t_filelist},
          files,
          vx_core.f_new(vx_core.t_any_from_any, (file) => 
            vx_core.f_new(
              vx_core.t_string,
              "url(",
              vx_data_file.f_pathfull_from_file(file),
              ")"
            ))
        )
        const fontfamily = vx_core.f_new(
          vx_core.t_string,
          vx_core.c_quote,
          name,
          vx_core.c_quote
        )
        const srcurls = vx_type.f_string_from_stringlist_join(urls, ",")
        const src = vx_core.f_new(
          vx_core.t_string,
          srcurls,
          ";"
        )
        const propmap = vx_core.f_new(
          vx_web_html.t_propmap,
          ":font-family",
          fontfamily,
          ":font-style",
          "normal",
          ":font-weight",
          weight,
          ":font-display",
          "swap",
          ":src",
          src,
          ":unicode-range",
          unicode
        )
        return vx_core.f_new(
          vx_web_html.t_style,
          ":name",
          "@font-face",
          ":props",
          propmap
        )
      })
    )
    return output
  }

  /**
   * @function style_from_style
   * Returns a htmlstyle from a uistyle
   * @param  {style} uistyle
   * @return {style}
   */
  static t_style_from_style = {
    vx_type: vx_core.t_type
  }
  static e_style_from_style = {
    vx_type: vx_ui_html_uihtml.t_style_from_style
  }

  // (func style<-style)
  static f_style_from_style(uistyle) {
    let output = vx_web_html.e_style
    output = vx_core.f_if_2(
      {"any-1": vx_web_html.t_style},
      vx_core.f_then(
        vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty_1(uistyle)}),
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_empty(
          vx_web_html.t_style
        )})
      ),
      vx_core.f_else(
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_let(
          {"any-1": vx_web_html.t_style},
          [],
          vx_core.f_new(vx_core.t_any_from_func, () => {
            const layout = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_layout, "struct-2": vx_ui_ui.t_style}, uistyle, ":layout")
            const name = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_ui_ui.t_style}, uistyle, ":name")
            const font = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_font, "struct-2": vx_ui_ui.t_style}, uistyle, ":font")
            const pin = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_pin, "struct-2": vx_ui_ui.t_style}, uistyle, ":pin")
            const pointpos = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_point, "struct-2": vx_ui_ui.t_style}, uistyle, ":pointpos")
            const pointsize = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_point, "struct-2": vx_ui_ui.t_style}, uistyle, ":pointsize")
            const pointrotate = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_point, "struct-2": vx_ui_ui.t_style}, uistyle, ":pointrotate")
            const styletype = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_styletype, "struct-2": vx_ui_ui.t_style}, uistyle, ":type")
            const color_bkg = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_ui_ui.t_style}, uistyle, ":color-background")
            const image_bkg = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_image, "struct-2": vx_ui_ui.t_style}, uistyle, ":image-background")
            const color_hoverbkg = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_ui_ui.t_style}, uistyle, ":color-hoverbkgrd")
            const cursor = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_cursor, "struct-2": vx_ui_ui.t_style}, uistyle, ":cursor")
            const hidden = vx_core.f_any_from_struct({"any-1": vx_core.t_boolean, "struct-2": vx_ui_ui.t_style}, uistyle, ":hidden")
            const align = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_align, "struct-2": vx_ui_ui.t_style}, uistyle, ":align")
            const posx = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_ui_ui.t_point}, pointpos, ":x")
            const posy = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_ui_ui.t_point}, pointpos, ":y")
            const sizex = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_ui_ui.t_point}, pointsize, ":x")
            const sizey = vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_ui_ui.t_point}, pointsize, ":y")
            const stylename = vx_ui_html_uihtml.f_string_stylename_from_name_styletype(name, styletype)
            const bkgcolor = vx_core.f_if_2(
              {"any-1": vx_core.t_string},
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_notempty(color_bkg)}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
                  vx_core.t_string,
                  "#",
                  color_bkg
                )})
              )
            )
            const bkgimage = vx_ui_html_uihtml.f_string_style_from_image(image_bkg)
            const bkgsize = vx_core.f_if_2(
              {"any-1": vx_core.t_string},
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_notempty_1(image_bkg)}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return "cover"})
              )
            )
            const position = vx_core.f_if_2(
              {"any-1": vx_core.t_string},
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_or_1(
                  vx_core.f_eqeq(
                    layout,
                    vx_ui_ui.c_layout_app
                  ),
                  vx_core.f_eqeq(
                    layout,
                    vx_ui_ui.c_layout_background
                  ),
                  vx_core.f_eqeq(
                    layout,
                    vx_ui_ui.c_layout_main
                  ),
                  vx_core.f_eqeq(
                    layout,
                    vx_ui_ui.c_layout_navbar
                  ),
                  vx_core.f_eqeq(
                    layout,
                    vx_ui_ui.c_layout_parallax
                  ),
                  vx_core.f_eqeq(
                    layout,
                    vx_ui_ui.c_layout_statusbar
                  ),
                  vx_core.f_eqeq(
                    layout,
                    vx_ui_ui.c_layout_titlebar
                  )
                )}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return "fixed"})
              ),
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_notempty_1(pointpos)}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return "absolute"})
              ),
              vx_core.f_else(vx_core.f_new(vx_core.t_any_from_func, () => {return ""}))
            )
            const top = vx_core.f_if_2(
              {"any-1": vx_core.t_string},
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eqeq(
                  pin,
                  vx_ui_ui.c_pin_expand
                )}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
                  vx_core.t_string,
                  posy,
                  "mm"
                )})
              ),
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eqeq(0, posy)}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return ""})
              ),
              vx_core.f_else(
                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
                  vx_core.t_string,
                  posy,
                  "mm"
                )})
              )
            )
            const bottom = vx_core.f_if_2(
              {"any-1": vx_core.t_string},
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eqeq(
                  pin,
                  vx_ui_ui.c_pin_expand
                )}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return ""})
              ),
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eqeq(
                  pin,
                  vx_ui_ui.c_pin_bottom
                )}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return "0mm"})
              ),
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_or(
                  vx_core.f_eqeq(
                    pin,
                    vx_ui_ui.c_pin_left
                  ),
                  vx_core.f_eqeq(
                    pin,
                    vx_ui_ui.c_pin_center_v
                  )
                )}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
                  vx_core.t_string,
                  sizey,
                  "mm"
                )})
              )
            )
            const left = vx_core.f_if_2(
              {"any-1": vx_core.t_string},
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eqeq(
                  pin,
                  vx_ui_ui.c_pin_expand
                )}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return ""})
              ),
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eqeq(
                  pin,
                  vx_ui_ui.c_pin_bottom
                )}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
                  vx_core.t_string,
                  posx,
                  "mm"
                )})
              ),
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eqeq(0, posx)}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return ""})
              ),
              vx_core.f_else(
                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
                  vx_core.t_string,
                  posx,
                  "mm"
                )})
              )
            )
            const right = vx_core.f_if_2(
              {"any-1": vx_core.t_string},
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eqeq(
                  pin,
                  vx_ui_ui.c_pin_expand
                )}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return ""})
              ),
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_or_1(
                  vx_core.f_eqeq(
                    pin,
                    vx_ui_ui.c_pin_top
                  ),
                  vx_core.f_eqeq(
                    pin,
                    vx_ui_ui.c_pin_bottom
                  ),
                  vx_core.f_eqeq(
                    pin,
                    vx_ui_ui.c_pin_center_v
                  )
                )}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
                  vx_core.t_string,
                  sizex,
                  "mm"
                )})
              )
            )
            const height = vx_core.f_if_2(
              {"any-1": vx_core.t_string},
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eqeq(
                  pin,
                  vx_ui_ui.c_pin_expand
                )}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return "100%"})
              ),
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_or_1(
                  vx_core.f_eqeq(
                    pin,
                    vx_ui_ui.c_pin_left
                  ),
                  vx_core.f_eqeq(
                    pin,
                    vx_ui_ui.c_pin_right
                  ),
                  vx_core.f_eqeq(
                    pin,
                    vx_ui_ui.c_pin_center_v
                  )
                )}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return ""})
              ),
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eqeq(0, sizey)}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return ""})
              ),
              vx_core.f_else(
                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
                  vx_core.t_string,
                  sizey,
                  "mm"
                )})
              )
            )
            const width = vx_core.f_if_2(
              {"any-1": vx_core.t_string},
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eqeq(
                  pin,
                  vx_ui_ui.c_pin_expand
                )}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return "100%"})
              ),
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_or_1(
                  vx_core.f_eqeq(
                    pin,
                    vx_ui_ui.c_pin_top
                  ),
                  vx_core.f_eqeq(
                    pin,
                    vx_ui_ui.c_pin_bottom
                  ),
                  vx_core.f_eqeq(
                    pin,
                    vx_ui_ui.c_pin_center_v
                  )
                )}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return ""})
              ),
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eqeq(0, sizex)}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return ""})
              ),
              vx_core.f_else(
                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
                  vx_core.t_string,
                  sizex,
                  "mm"
                )})
              )
            )
            const display = vx_core.f_if_2(
              {"any-1": vx_core.t_string},
              vx_core.f_then(vx_core.f_new(vx_core.t_boolean_from_func, () => {return hidden}), vx_core.f_new(vx_core.t_any_from_func, () => {return "none"})),
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eqeq(
                  layout,
                  vx_ui_ui.c_layout_flow_item
                )}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return "inline-block"})
              )
            )
            const sfont = vx_ui_html_uihtml.f_string_style_from_font(font)
            const gap = vx_core.f_if_2(
              {"any-1": vx_core.t_string},
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_or(
                  vx_core.f_eqeq(
                    layout,
                    vx_ui_ui.c_layout_flow_columns
                  ),
                  vx_core.f_eqeq(
                    layout,
                    vx_ui_ui.c_layout_flow_rows
                  )
                )}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return "1mm"})
              )
            )
            const overflowx = vx_core.f_if_2(
              {"any-1": vx_core.t_string},
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eqeq(
                  layout,
                  vx_ui_ui.c_layout_flow_rows
                )}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return "auto"})
              )
            )
            const overflowy = vx_core.f_if_2(
              {"any-1": vx_core.t_string},
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eqeq(
                  layout,
                  vx_ui_ui.c_layout_flow_columns
                )}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return "auto"})
              )
            )
            const hoverbkgrdcolor = vx_core.f_if_2(
              {"any-1": vx_core.t_string},
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_ne("", color_hoverbkg)}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
                  vx_core.t_string,
                  "#",
                  color_hoverbkg
                )})
              )
            )
            const scursor = vx_core.f_if_2(
              {"any-1": vx_core.t_string},
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eqeq(
                  cursor,
                  vx_ui_ui.t_cursor_pointer
                )}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return "pointer"})
              )
            )
            const textalign = vx_core.f_if_2(
              {"any-1": vx_core.t_string},
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eqeq(
                  align,
                  vx_ui_ui.c_align_left
                )}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return "left"})
              ),
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eqeq(
                  align,
                  vx_ui_ui.c_align_center
                )}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return "center"})
              ),
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eqeq(
                  align,
                  vx_ui_ui.c_align_right
                )}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return "right"})
              )
            )
            const transform = vx_core.f_if_2(
              {"any-1": vx_core.t_string},
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty_1(pointrotate)}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return ""})
              ),
              vx_core.f_else(
                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
                  vx_core.t_string,
                  "rotate(",
                  vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_ui_ui.t_point}, pointrotate, ":x"),
                  "deg)"
                )})
              )
            )
            const transformorigin = vx_core.f_if_2(
              {"any-1": vx_core.t_string},
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty_1(pointrotate)}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return ""})
              ),
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eqeq(
                  layout,
                  vx_ui_ui.c_layout_label
                )}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return "left top"})
              )
            )
            const props = vx_core.f_new(
              vx_web_html.t_propmap,
              ":background-color",
              bkgcolor,
              ":background-image",
              bkgimage,
              ":background-size",
              bkgsize,
              ":cursor",
              scursor,
              ":display",
              display,
              ":font",
              sfont,
              ":gap",
              gap,
              ":position",
              position,
              ":top",
              top,
              ":bottom",
              bottom,
              ":left",
              left,
              ":right",
              right,
              ":height",
              height,
              ":width",
              width,
              ":overflow-x",
              overflowx,
              ":overflow-y",
              overflowy,
              ":text-align",
              textalign,
              ":transform",
              transform,
              ":transform-origin",
              transformorigin
            )
            const hoverprops = vx_core.f_new(
              vx_web_html.t_propmap,
              ":background-color",
              hoverbkgrdcolor
            )
            const substylelist = vx_core.f_if_2(
              {"any-1": vx_web_html.t_stylelist},
              vx_core.f_then(
                vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_notempty_1(hoverprops)}),
                vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_new(
                  vx_web_html.t_stylelist,
                  vx_core.f_new(
                    vx_web_html.t_style,
                    ":name",
                    "&:hover",
                    ":props",
                    hoverprops
                  )
                )})
              )
            )
            return vx_core.f_new(
              vx_web_html.t_style,
              ":name",
              stylename,
              ":props",
              props,
              ":stylelist",
              substylelist
            )
          })
        )})
      )
    )
    return output
  }

  /**
   * @function stylelist_extra_from_ui
   * Returns a stylelist from a ui including style-hidden and style-selected
   * @param  {ui} ui
   * @return {stylelist}
   */
  static t_stylelist_extra_from_ui = {
    vx_type: vx_core.t_type
  }
  static e_stylelist_extra_from_ui = {
    vx_type: vx_ui_html_uihtml.t_stylelist_extra_from_ui
  }

  // (func stylelist-extra<-ui)
  static f_stylelist_extra_from_ui(ui) {
    let output = vx_web_html.e_stylelist
    output = vx_core.f_let(
      {"any-1": vx_web_html.t_stylelist},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const uistyles = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_stylelist, "struct-2": vx_ui_ui.t_ui}, ui, ":stylelist")
        const selected = vx_core.f_any_from_struct({"any-1": vx_core.t_boolean, "struct-2": vx_ui_ui.t_ui}, ui, ":selected")
        const hidden = vx_core.f_any_from_struct({"any-1": vx_core.t_boolean, "struct-2": vx_ui_ui.t_ui}, ui, ":hidden")
        const styles1 = vx_ui_html_uihtml.f_stylelist_from_stylelist(uistyles)
        const styles2 = vx_core.f_if_2(
          {"any-1": vx_web_html.t_stylelist},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return hidden}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(
              styles1,
              vx_ui_html_uihtml.c_style_hidden
            )})
          ),
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return selected}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(
              styles1,
              vx_ui_html_uihtml.c_style_selected
            )})
          ),
          vx_core.f_else(vx_core.f_new(vx_core.t_any_from_func, () => {return styles1}))
        )
        return styles2
      })
    )
    return output
  }

  /**
   * @function stylelist_reset
   * Returns the initial reset styles for ui framework
   * @return {stylelist}
   */
  static t_stylelist_reset = {
    vx_type: vx_core.t_type
  }
  static e_stylelist_reset = {
    vx_type: vx_ui_html_uihtml.t_stylelist_reset
  }

  // (func stylelist-reset)
  static f_stylelist_reset() {
    let output = vx_web_html.e_stylelist
    output = vx_core.f_new(
      vx_web_html.t_stylelist,
      vx_core.f_new(
        vx_web_html.t_style,
        ":name",
        "html",
        ":props",
        vx_core.f_new(
          vx_web_html.t_propmap,
          ":margin",
          "0mm",
          ":padding",
          "0mm"
        )
      ),
      vx_core.f_new(
        vx_web_html.t_style,
        ":name",
        "body",
        ":props",
        vx_core.f_new(
          vx_web_html.t_propmap,
          ":margin",
          "0mm",
          ":padding",
          "0mm",
          ":-webkit-print-color-adjust",
          "exact !important",
          ":color-adjust",
          "exact !important",
          ":print-color-adjust",
          "exact !important"
        )
      ),
      vx_core.f_new(
        vx_web_html.t_style,
        ":name",
        "div",
        ":props",
        vx_core.f_new(
          vx_web_html.t_propmap,
          ":position",
          "relative"
        )
      ),
      vx_core.f_new(
        vx_web_html.t_style,
        ":name",
        "p",
        ":props",
        vx_core.f_new(
          vx_web_html.t_propmap,
          ":margin-block-start",
          "0mm",
          ":margin-block-end",
          "0mm",
          ":white-space",
          "pre-line"
        )
      )
    )
    return output
  }

  /**
   * @function stylelist_from_fontfacemap
   * Returns stylelist from a fontfacemap
   * @param  {fontfacemap} fontfacemap
   * @return {stylelist}
   */
  static t_stylelist_from_fontfacemap = {
    vx_type: vx_core.t_type
  }
  static e_stylelist_from_fontfacemap = {
    vx_type: vx_ui_html_uihtml.t_stylelist_from_fontfacemap
  }

  // (func stylelist<-fontfacemap)
  static f_stylelist_from_fontfacemap(fontfacemap) {
    let output = vx_web_html.e_stylelist
    output = vx_core.f_list_from_map_1(
      {"any-1": vx_web_html.t_style, "any-2": vx_ui_ui.t_fontface, "list-1": vx_web_html.t_stylelist, "map-2": vx_ui_ui.t_fontfacemap},
      fontfacemap,
      vx_core.f_new(vx_core.t_any_from_key_value, ([key, fontface]) => 
        vx_ui_html_uihtml.f_style_from_fontface(fontface))
    )
    return output
  }

  /**
   * @function stylelist_from_stylelist
   * Returns a htmlstylelist from a uistylemap
   * @param  {stylelist} uistylelist
   * @return {stylelist}
   */
  static t_stylelist_from_stylelist = {
    vx_type: vx_core.t_type
  }
  static e_stylelist_from_stylelist = {
    vx_type: vx_ui_html_uihtml.t_stylelist_from_stylelist
  }

  // (func stylelist<-stylelist)
  static f_stylelist_from_stylelist(uistylelist) {
    let output = vx_web_html.e_stylelist
    output = vx_core.f_list_from_list_1(
      {"any-1": vx_web_html.t_style, "any-2": vx_ui_ui.t_style, "list-1": vx_web_html.t_stylelist, "list-2": vx_ui_ui.t_stylelist},
      uistylelist,
      vx_core.f_new(vx_core.t_any_from_any, vx_ui_html_uihtml.t_style_from_style)
    )
    return output
  }

  /**
   * @function stylelist_from_stylemap
   * Returns a htmlstylelist from a uistylemap
   * @param  {stylemap} uistylemap
   * @return {stylelist}
   */
  static t_stylelist_from_stylemap = {
    vx_type: vx_core.t_type
  }
  static e_stylelist_from_stylemap = {
    vx_type: vx_ui_html_uihtml.t_stylelist_from_stylemap
  }

  // (func stylelist<-stylemap)
  static f_stylelist_from_stylemap(uistylemap) {
    let output = vx_web_html.e_stylelist
    output = vx_core.f_list_from_map_1(
      {"any-1": vx_web_html.t_style, "any-2": vx_ui_ui.t_style, "list-1": vx_web_html.t_stylelist, "map-2": vx_ui_ui.t_stylemap},
      uistylemap,
      vx_core.f_new(vx_core.t_any_from_key_value, ([key, value]) => 
        vx_ui_html_uihtml.f_style_from_style(value))
    )
    return output
  }

  /**
   * @function stylemap_from_stylemap
   * Returns a htmlstylesheet from a uistylesheet
   * @param  {stylemap} uistylemap
   * @return {stylemap}
   */
  static t_stylemap_from_stylemap = {
    vx_type: vx_core.t_type
  }
  static e_stylemap_from_stylemap = {
    vx_type: vx_ui_html_uihtml.t_stylemap_from_stylemap
  }

  // (func stylemap<-stylemap)
  static f_stylemap_from_stylemap(uistylemap) {
    let output = vx_web_html.e_stylemap
    output = vx_core.f_map_from_map_1(
      {"any-1": vx_web_html.t_style, "any-2": vx_ui_ui.t_style, "map-1": vx_web_html.t_stylemap, "map-2": vx_ui_ui.t_stylemap},
      uistylemap,
      vx_core.f_new(vx_core.t_any_from_key_value, ([key, value]) => 
        vx_ui_html_uihtml.f_style_from_style(value))
    )
    return output
  }

  /**
   * 
   * @async @function stylesheet_render_html
   * @param  {stylesheet} stylesheetui
   * @return {stylesheet}
   */
  static t_stylesheet_render_html = {
    vx_type: vx_core.t_type
  }
  static e_stylesheet_render_html = {
    vx_type: vx_ui_html_uihtml.t_stylesheet_render_html
  }

  // (func stylesheet-render-html)
  static async f_stylesheet_render_html(stylesheetui) {
    let output = Promise.resolve(vx_ui_ui.e_stylesheet)
    output = await vx_core.f_let_async(
      {"any-1": vx_ui_ui.t_stylesheet},
      [],
      vx_core.f_new(vx_core.t_any_from_func, async () => {
        const stylesheethtml = vx_ui_html_uihtml.f_stylesheet_from_stylesheet(stylesheetui)
        const write = await vx_web_htmldoc.f_boolean_write_from_stylesheet(stylesheethtml)
        return stylesheetui
      })
    )
    return output
  }

  /**
   * @function stylesheet_from_stylesheet
   * Returns a htmlstylesheet from a uistylesheet
   * @param  {stylesheet} uistylesheet
   * @return {stylesheet}
   */
  static t_stylesheet_from_stylesheet = {
    vx_type: vx_core.t_type
  }
  static e_stylesheet_from_stylesheet = {
    vx_type: vx_ui_html_uihtml.t_stylesheet_from_stylesheet
  }

  // (func stylesheet<-stylesheet)
  static f_stylesheet_from_stylesheet(uistylesheet) {
    let output = vx_web_html.e_stylesheet
    output = vx_core.f_let(
      {"any-1": vx_web_html.t_stylesheet},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const uistylemap = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_stylemap, "struct-2": vx_ui_ui.t_stylesheet}, uistylesheet, ":stylemap")
        const fontfacemap = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_fontfacemap, "struct-2": vx_ui_ui.t_stylesheet}, uistylesheet, ":fontfacemap")
        const resetlist = vx_ui_html_uihtml.f_stylelist_reset()
        const fontstyles = vx_ui_html_uihtml.f_stylelist_from_fontfacemap(fontfacemap)
        const stylelist = vx_ui_html_uihtml.f_stylelist_from_stylemap(uistylemap)
        const allstyles = vx_core.f_new(
          vx_web_html.t_stylelist,
          resetlist,
          fontstyles,
          stylelist
        )
        return vx_core.f_new(
          vx_web_html.t_stylesheet,
          ":styles",
          allstyles
        )
      })
    )
    return output
  }

  /**
   * @function ui_render_app_from_ui_orig_parent
   * @param  {ui} ui
   * @param  {ui} orig
   * @param  {ui} parent
   * @return {ui}
   */
  static t_ui_render_app_from_ui_orig_parent = {
    vx_type: vx_core.t_type
  }
  static e_ui_render_app_from_ui_orig_parent = {
    vx_type: vx_ui_html_uihtml.t_ui_render_app_from_ui_orig_parent
  }

  // (func ui-render-app<-ui-orig-parent)
  static f_ui_render_app_from_ui_orig_parent(ui, orig, parent) {
    let output = vx_ui_ui.e_ui
    output = vx_core.f_let(
      {"any-1": vx_ui_ui.t_ui},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const uid = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_ui_ui.t_ui}, ui, ":uid")
        const uimap = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_uimap, "struct-2": vx_ui_ui.t_ui}, ui, ":uimap")
        const children = vx_ui_html_uihtml.f_divchildlist_from_uimap(uimap)
        const node = vx_core.f_new(
          vx_web_html.t_div,
          ":id",
          uid,
          ":nodes",
          children
        )
        const nodechg = vx_ui_html_uihtml.f_node_render_from_node_ui(node, ui)
        const uimapchg = vx_ui_ui.f_uimap_render_from_uimap_parent(uimap, ui)
        return vx_core.f_new(
          vx_ui_ui.t_ui,
          ":uimap",
          uimapchg
        )
      })
    )
    return output
  }

  /**
   * @function ui_render_default_from_ui_orig_parent
   * @param  {ui} ui
   * @param  {ui} orig
   * @param  {ui} parent
   * @return {ui}
   */
  static t_ui_render_default_from_ui_orig_parent = {
    vx_type: vx_core.t_type
  }
  static e_ui_render_default_from_ui_orig_parent = {
    vx_type: vx_ui_html_uihtml.t_ui_render_default_from_ui_orig_parent
  }

  // (func ui-render-default<-ui-orig-parent)
  static f_ui_render_default_from_ui_orig_parent(ui, orig, parent) {
    let output = vx_ui_ui.e_ui
    output = vx_core.f_let(
      {"any-1": vx_ui_ui.t_ui},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const uid = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_ui_ui.t_ui}, ui, ":uid")
        const uimap = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_uimap, "struct-2": vx_ui_ui.t_ui}, ui, ":uimap")
        const uistyle = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_style, "struct-2": vx_ui_ui.t_ui}, ui, ":style")
        const style = vx_ui_html_uihtml.f_style_from_style(uistyle)
        const styles = vx_ui_html_uihtml.f_stylelist_extra_from_ui(ui)
        const children = vx_ui_html_uihtml.f_divchildlist_from_uimap(uimap)
        const node = vx_core.f_new(
          vx_web_html.t_div,
          ":id",
          uid,
          ":style-unique",
          style,
          ":stylelist",
          styles,
          ":nodes",
          children
        )
        const nodechg = vx_ui_html_uihtml.f_node_render_from_node_ui(node, ui)
        const uimapchg = vx_ui_ui.f_uimap_render_from_uimap_parent(uimap, ui)
        return vx_core.f_new(
          vx_ui_ui.t_ui,
          ":uimap",
          uimapchg
        )
      })
    )
    return output
  }

  /**
   * @function ui_render_label_from_ui_orig_parent
   * @param  {ui} ui
   * @param  {ui} orig
   * @param  {ui} parent
   * @return {ui}
   */
  static t_ui_render_label_from_ui_orig_parent = {
    vx_type: vx_core.t_type
  }
  static e_ui_render_label_from_ui_orig_parent = {
    vx_type: vx_ui_html_uihtml.t_ui_render_label_from_ui_orig_parent
  }

  // (func ui-render-label<-ui-orig-parent)
  static f_ui_render_label_from_ui_orig_parent(ui, orig, parent) {
    let output = vx_ui_ui.e_ui
    output = vx_core.f_let(
      {"any-1": vx_ui_ui.t_ui},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const uid = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_ui_ui.t_ui}, ui, ":uid")
        const data = vx_core.f_any_from_struct({"any-1": vx_core.t_any, "struct-2": vx_ui_ui.t_ui}, ui, ":data")
        const uimap = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_uimap, "struct-2": vx_ui_ui.t_ui}, ui, ":uimap")
        const uistyle = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_style, "struct-2": vx_ui_ui.t_ui}, ui, ":style")
        const uistyles = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_stylelist, "struct-2": vx_ui_ui.t_ui}, ui, ":stylelist")
        const datatype = vx_core.f_type_from_any(data)
        const style = vx_ui_html_uihtml.f_style_from_style(uistyle)
        const styles = vx_ui_html_uihtml.f_stylelist_from_stylelist(uistyles)
        const text = vx_core.f_if_2(
          {"any-1": vx_core.t_string},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eqeq(
              datatype,
              vx_core.t_string
            )}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_any_from_any({"any-1": vx_core.t_string, "any-2": vx_core.t_any}, data)})
          ),
          vx_core.f_else(
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_string_from_any(data)})
          )
        )
        const node = vx_core.f_new(
          vx_web_html.t_p,
          ":id",
          uid,
          ":style-unique",
          style,
          ":stylelist",
          styles,
          ":text",
          text
        )
        const nodechg = vx_ui_html_uihtml.f_node_render_from_node_ui(node, ui)
        const uimapchg = vx_ui_ui.f_uimap_render_from_uimap_parent(uimap, ui)
        return vx_core.f_new(
          vx_ui_ui.t_ui,
          ":uimap",
          uimapchg
        )
      })
    )
    return output
  }



  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      "layout-app-html": vx_ui_html_uihtml.c_layout_app_html,
      "layout-else-html": vx_ui_html_uihtml.c_layout_else_html,
      "layout-label-html": vx_ui_html_uihtml.c_layout_label_html,
      "layoutenginehtml": vx_ui_html_uihtml.c_layoutenginehtml,
      "style-hidden": vx_ui_html_uihtml.c_style_hidden,
      "style-selected": vx_ui_html_uihtml.c_style_selected
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "boolean-print-html": vx_ui_html_uihtml.e_boolean_print_html,
      "context-write": vx_ui_html_uihtml.e_context_write,
      "divchild<-ui": vx_ui_html_uihtml.e_divchild_from_ui,
      "divchildlist<-uimap": vx_ui_html_uihtml.e_divchildlist_from_uimap,
      "node-app<-ui-orig-parent": vx_ui_html_uihtml.e_node_app_from_ui_orig_parent,
      "node-render<-node-ui": vx_ui_html_uihtml.e_node_render_from_node_ui,
      "string-style<-font": vx_ui_html_uihtml.e_string_style_from_font,
      "string-style<-image": vx_ui_html_uihtml.e_string_style_from_image,
      "string-stylename<-name-styletype": vx_ui_html_uihtml.e_string_stylename_from_name_styletype,
      "style<-fontface": vx_ui_html_uihtml.e_style_from_fontface,
      "style<-style": vx_ui_html_uihtml.e_style_from_style,
      "stylelist-extra<-ui": vx_ui_html_uihtml.e_stylelist_extra_from_ui,
      "stylelist-reset": vx_ui_html_uihtml.e_stylelist_reset,
      "stylelist<-fontfacemap": vx_ui_html_uihtml.e_stylelist_from_fontfacemap,
      "stylelist<-stylelist": vx_ui_html_uihtml.e_stylelist_from_stylelist,
      "stylelist<-stylemap": vx_ui_html_uihtml.e_stylelist_from_stylemap,
      "stylemap<-stylemap": vx_ui_html_uihtml.e_stylemap_from_stylemap,
      "stylesheet-render-html": vx_ui_html_uihtml.e_stylesheet_render_html,
      "stylesheet<-stylesheet": vx_ui_html_uihtml.e_stylesheet_from_stylesheet,
      "ui-render-app<-ui-orig-parent": vx_ui_html_uihtml.e_ui_render_app_from_ui_orig_parent,
      "ui-render-default<-ui-orig-parent": vx_ui_html_uihtml.e_ui_render_default_from_ui_orig_parent,
      "ui-render-label<-ui-orig-parent": vx_ui_html_uihtml.e_ui_render_label_from_ui_orig_parent
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "boolean-print-html": vx_ui_html_uihtml.t_boolean_print_html,
      "context-write": vx_ui_html_uihtml.t_context_write,
      "divchild<-ui": vx_ui_html_uihtml.t_divchild_from_ui,
      "divchildlist<-uimap": vx_ui_html_uihtml.t_divchildlist_from_uimap,
      "node-app<-ui-orig-parent": vx_ui_html_uihtml.t_node_app_from_ui_orig_parent,
      "node-render<-node-ui": vx_ui_html_uihtml.t_node_render_from_node_ui,
      "string-style<-font": vx_ui_html_uihtml.t_string_style_from_font,
      "string-style<-image": vx_ui_html_uihtml.t_string_style_from_image,
      "string-stylename<-name-styletype": vx_ui_html_uihtml.t_string_stylename_from_name_styletype,
      "style<-fontface": vx_ui_html_uihtml.t_style_from_fontface,
      "style<-style": vx_ui_html_uihtml.t_style_from_style,
      "stylelist-extra<-ui": vx_ui_html_uihtml.t_stylelist_extra_from_ui,
      "stylelist-reset": vx_ui_html_uihtml.t_stylelist_reset,
      "stylelist<-fontfacemap": vx_ui_html_uihtml.t_stylelist_from_fontfacemap,
      "stylelist<-stylelist": vx_ui_html_uihtml.t_stylelist_from_stylelist,
      "stylelist<-stylemap": vx_ui_html_uihtml.t_stylelist_from_stylemap,
      "stylemap<-stylemap": vx_ui_html_uihtml.t_stylemap_from_stylemap,
      "stylesheet-render-html": vx_ui_html_uihtml.t_stylesheet_render_html,
      "stylesheet<-stylesheet": vx_ui_html_uihtml.t_stylesheet_from_stylesheet,
      "ui-render-app<-ui-orig-parent": vx_ui_html_uihtml.t_ui_render_app_from_ui_orig_parent,
      "ui-render-default<-ui-orig-parent": vx_ui_html_uihtml.t_ui_render_default_from_ui_orig_parent,
      "ui-render-label<-ui-orig-parent": vx_ui_html_uihtml.t_ui_render_label_from_ui_orig_parent
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      
    })
    const pkg = vx_core.vx_new_struct(vx_core.t_package, {
      "name": "vx/ui/html/uihtml",
      "constmap": constmap,
      "emptymap": emptymap,
      "funcmap": funcmap,
      "typemap": typemap
    })
    vx_core.vx_global_package_set(pkg)

    // (func boolean-print-html)
    vx_ui_html_uihtml.t_boolean_print_html['vx_value'] = {
      name          : "boolean-print-html",
      pkgname       : "vx/ui/html/uihtml",
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
      fn            : vx_ui_html_uihtml.f_boolean_print_html
    }

    // (func context-write)
    vx_ui_html_uihtml.t_context_write['vx_value'] = {
      name          : "context-write",
      pkgname       : "vx/ui/html/uihtml",
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
      fn            : vx_ui_html_uihtml.f_context_write
    }

    // (func divchild<-ui)
    vx_ui_html_uihtml.t_divchild_from_ui['vx_value'] = {
      name          : "divchild<-ui",
      pkgname       : "vx/ui/html/uihtml",
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
      fn            : vx_ui_html_uihtml.f_divchild_from_ui
    }

    // (func divchildlist<-uimap)
    vx_ui_html_uihtml.t_divchildlist_from_uimap['vx_value'] = {
      name          : "divchildlist<-uimap",
      pkgname       : "vx/ui/html/uihtml",
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
      fn            : vx_ui_html_uihtml.f_divchildlist_from_uimap
    }

    // (func node-app<-ui-orig-parent)
    vx_ui_html_uihtml.t_node_app_from_ui_orig_parent['vx_value'] = {
      name          : "node-app<-ui-orig-parent",
      pkgname       : "vx/ui/html/uihtml",
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
      fn            : vx_ui_html_uihtml.f_node_app_from_ui_orig_parent
    }

    // (func node-render<-node-ui)
    vx_ui_html_uihtml.t_node_render_from_node_ui['vx_value'] = {
      name          : "node-render<-node-ui",
      pkgname       : "vx/ui/html/uihtml",
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
      fn            : vx_ui_html_uihtml.f_node_render_from_node_ui
    }

    // (func string-style<-font)
    vx_ui_html_uihtml.t_string_style_from_font['vx_value'] = {
      name          : "string-style<-font",
      pkgname       : "vx/ui/html/uihtml",
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
      fn            : vx_ui_html_uihtml.f_string_style_from_font
    }

    // (func string-style<-image)
    vx_ui_html_uihtml.t_string_style_from_image['vx_value'] = {
      name          : "string-style<-image",
      pkgname       : "vx/ui/html/uihtml",
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
      fn            : vx_ui_html_uihtml.f_string_style_from_image
    }

    // (func string-stylename<-name-styletype)
    vx_ui_html_uihtml.t_string_stylename_from_name_styletype['vx_value'] = {
      name          : "string-stylename<-name-styletype",
      pkgname       : "vx/ui/html/uihtml",
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
      fn            : vx_ui_html_uihtml.f_string_stylename_from_name_styletype
    }

    // (func style<-fontface)
    vx_ui_html_uihtml.t_style_from_fontface['vx_value'] = {
      name          : "style<-fontface",
      pkgname       : "vx/ui/html/uihtml",
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
      fn            : vx_ui_html_uihtml.f_style_from_fontface
    }

    // (func style<-style)
    vx_ui_html_uihtml.t_style_from_style['vx_value'] = {
      name          : "style<-style",
      pkgname       : "vx/ui/html/uihtml",
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
      fn            : vx_ui_html_uihtml.f_style_from_style
    }

    // (func stylelist-extra<-ui)
    vx_ui_html_uihtml.t_stylelist_extra_from_ui['vx_value'] = {
      name          : "stylelist-extra<-ui",
      pkgname       : "vx/ui/html/uihtml",
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
      fn            : vx_ui_html_uihtml.f_stylelist_extra_from_ui
    }

    // (func stylelist-reset)
    vx_ui_html_uihtml.t_stylelist_reset['vx_value'] = {
      name          : "stylelist-reset",
      pkgname       : "vx/ui/html/uihtml",
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
      fn            : vx_ui_html_uihtml.f_stylelist_reset
    }

    // (func stylelist<-fontfacemap)
    vx_ui_html_uihtml.t_stylelist_from_fontfacemap['vx_value'] = {
      name          : "stylelist<-fontfacemap",
      pkgname       : "vx/ui/html/uihtml",
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
      fn            : vx_ui_html_uihtml.f_stylelist_from_fontfacemap
    }

    // (func stylelist<-stylelist)
    vx_ui_html_uihtml.t_stylelist_from_stylelist['vx_value'] = {
      name          : "stylelist<-stylelist",
      pkgname       : "vx/ui/html/uihtml",
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
      fn            : vx_ui_html_uihtml.f_stylelist_from_stylelist
    }

    // (func stylelist<-stylemap)
    vx_ui_html_uihtml.t_stylelist_from_stylemap['vx_value'] = {
      name          : "stylelist<-stylemap",
      pkgname       : "vx/ui/html/uihtml",
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
      fn            : vx_ui_html_uihtml.f_stylelist_from_stylemap
    }

    // (func stylemap<-stylemap)
    vx_ui_html_uihtml.t_stylemap_from_stylemap['vx_value'] = {
      name          : "stylemap<-stylemap",
      pkgname       : "vx/ui/html/uihtml",
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
      fn            : vx_ui_html_uihtml.f_stylemap_from_stylemap
    }

    // (func stylesheet-render-html)
    vx_ui_html_uihtml.t_stylesheet_render_html['vx_value'] = {
      name          : "stylesheet-render-html",
      pkgname       : "vx/ui/html/uihtml",
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
      fn            : vx_ui_html_uihtml.f_stylesheet_render_html
    }

    // (func stylesheet<-stylesheet)
    vx_ui_html_uihtml.t_stylesheet_from_stylesheet['vx_value'] = {
      name          : "stylesheet<-stylesheet",
      pkgname       : "vx/ui/html/uihtml",
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
      fn            : vx_ui_html_uihtml.f_stylesheet_from_stylesheet
    }

    // (func ui-render-app<-ui-orig-parent)
    vx_ui_html_uihtml.t_ui_render_app_from_ui_orig_parent['vx_value'] = {
      name          : "ui-render-app<-ui-orig-parent",
      pkgname       : "vx/ui/html/uihtml",
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
      fn            : vx_ui_html_uihtml.f_ui_render_app_from_ui_orig_parent
    }

    // (func ui-render-default<-ui-orig-parent)
    vx_ui_html_uihtml.t_ui_render_default_from_ui_orig_parent['vx_value'] = {
      name          : "ui-render-default<-ui-orig-parent",
      pkgname       : "vx/ui/html/uihtml",
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
      fn            : vx_ui_html_uihtml.f_ui_render_default_from_ui_orig_parent
    }

    // (func ui-render-label<-ui-orig-parent)
    vx_ui_html_uihtml.t_ui_render_label_from_ui_orig_parent['vx_value'] = {
      name          : "ui-render-label<-ui-orig-parent",
      pkgname       : "vx/ui/html/uihtml",
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
      fn            : vx_ui_html_uihtml.f_ui_render_label_from_ui_orig_parent
    }

    // (const layout-app-html)
    Object.assign(vx_ui_html_uihtml.c_layout_app_html, vx_core.f_copy(
      vx_ui_ui.c_layout_app,
      ":fn-layout",
      vx_ui_html_uihtml.t_ui_render_app_from_ui_orig_parent
    ))

    // (const layout-else-html)
    Object.assign(vx_ui_html_uihtml.c_layout_else_html, vx_core.f_copy(
      vx_ui_ui.c_layout_else,
      ":fn-layout",
      vx_ui_html_uihtml.t_ui_render_default_from_ui_orig_parent
    ))

    // (const layout-label-html)
    Object.assign(vx_ui_html_uihtml.c_layout_label_html, vx_core.f_copy(
      vx_ui_ui.c_layout_label,
      ":fn-layout",
      vx_ui_html_uihtml.t_ui_render_label_from_ui_orig_parent
    ))

    // (const layoutenginehtml)
    Object.assign(vx_ui_html_uihtml.c_layoutenginehtml, vx_core.f_new(
      vx_ui_ui.t_layoutengine,
      ":layoutmap",
      vx_ui_ui.f_layoutmap_from_layoutlist(
        vx_core.f_new(
          vx_ui_ui.t_layoutlist,
          vx_ui_html_uihtml.c_layout_app_html,
          vx_ui_html_uihtml.c_layout_label_html
        )
      ),
      ":layoutelse",
      vx_ui_html_uihtml.c_layout_else_html,
      ":boolean-print",
      vx_ui_html_uihtml.t_boolean_print_html,
      ":stylesheetrender",
      vx_ui_html_uihtml.t_stylesheet_render_html
    ))

    // (const style-hidden)
    Object.assign(vx_ui_html_uihtml.c_style_hidden, vx_core.f_new(
      vx_web_html.t_style,
      ":name",
      ".style-hidden"
    ))

    // (const style-selected)
    Object.assign(vx_ui_html_uihtml.c_style_selected, vx_core.f_new(
      vx_web_html.t_style,
      ":name",
      ".style-selected"
    ))

  }
}
