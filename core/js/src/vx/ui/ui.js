'strict mode'

import vx_core from "../../vx/core.js"
import vx_collection from "../../vx/collection.js"
import vx_event from "../../vx/event.js"
import vx_data_file from "../../vx/data/file.js"
import vx_state from "../../vx/state.js"


export default class vx_ui_ui {


  /**
   * type: align
   * Universal Alignment
   */
  static t_align = {}
  static e_align = {vx_type: vx_ui_ui.t_align}

  /**
   * type: bounds
   * Universal Bounds
   */
  static t_bounds = {}
  static e_bounds = {vx_type: vx_ui_ui.t_bounds}

  /**
   * type: cursor
   * Univeral Cursor Type
   */
  static t_cursor = {}
  static e_cursor = {vx_type: vx_ui_ui.t_cursor}

  /**
   * type: cursor-pointer
   */
  static t_cursor_pointer = {}
  static e_cursor_pointer = {vx_type: vx_ui_ui.t_cursor_pointer}

  /**
   * type: font
   * Univeral Font Type
   */
  static t_font = {}
  static e_font = {vx_type: vx_ui_ui.t_font}

  /**
   * type: fontface
   * Univeral Font Face Type
   */
  static t_fontface = {}
  static e_fontface = {vx_type: vx_ui_ui.t_fontface}

  /**
   * type: fontfacelist
   * List of fontface
   */
  static t_fontfacelist = {}
  static e_fontfacelist = vx_core.vx_new_list(vx_ui_ui.t_fontfacelist, [])

  /**
   * type: fontfacemap
   * Map of fontface
   */
  static t_fontfacemap = {}
  static e_fontfacemap = {vx_type: vx_ui_ui.t_fontfacemap}

  /**
   * type: fontmap
   * Map of font
   */
  static t_fontmap = {}
  static e_fontmap = {vx_type: vx_ui_ui.t_fontmap}

  /**
   * type: fontstyle
   * Univeral Font Style Type
   */
  static t_fontstyle = {}
  static e_fontstyle = {vx_type: vx_ui_ui.t_fontstyle}

  /**
   * type: fontstylemap
   * Map of fontstyle
   */
  static t_fontstylemap = {}
  static e_fontstylemap = {vx_type: vx_ui_ui.t_fontstylemap}

  /**
   * type: image
   * Univeral Image Type
   */
  static t_image = {}
  static e_image = {vx_type: vx_ui_ui.t_image}

  /**
   * type: layout
   * Universal Layout
   */
  static t_layout = {}
  static e_layout = {vx_type: vx_ui_ui.t_layout}

  /**
   * type: layoutengine
   * Pluggable layoutengine
   */
  static t_layoutengine = {}
  static e_layoutengine = {vx_type: vx_ui_ui.t_layoutengine}

  /**
   * type: layoutlist
   * Map of layout
   */
  static t_layoutlist = {}
  static e_layoutlist = vx_core.vx_new_list(vx_ui_ui.t_layoutlist, [])

  /**
   * type: layoutmap
   * Map of layout
   */
  static t_layoutmap = {}
  static e_layoutmap = {vx_type: vx_ui_ui.t_layoutmap}

  /**
   * type: pin
   * Pin an element
   */
  static t_pin = {}
  static e_pin = {vx_type: vx_ui_ui.t_pin}

  /**
   * type: point
   * Universal Point
   */
  static t_point = {}
  static e_point = {vx_type: vx_ui_ui.t_point}

  /**
   * type: pointtype
   * Universal Point Scale
   */
  static t_pointtype = {}
  static e_pointtype = {vx_type: vx_ui_ui.t_pointtype}

  /**
   * type: style
   * Universal Style
   */
  static t_style = {}
  static e_style = {vx_type: vx_ui_ui.t_style}

  /**
   * type: stylelist
   * Universal Stylelist
   */
  static t_stylelist = {}
  static e_stylelist = vx_core.vx_new_list(vx_ui_ui.t_stylelist, [])

  /**
   * type: stylemap
   * Universal Stylemap
   */
  static t_stylemap = {}
  static e_stylemap = {vx_type: vx_ui_ui.t_stylemap}

  /**
   * type: stylesheet
   * Universal Stylesheet
   */
  static t_stylesheet = {}
  static e_stylesheet = {vx_type: vx_ui_ui.t_stylesheet}

  /**
   * type: styletype
   * Universal Style Type
   */
  static t_styletype = {}
  static e_styletype = {vx_type: vx_ui_ui.t_styletype}

  /**
   * type: ui
   * Universal UI Element
   */
  static t_ui = {}
  static e_ui = {vx_type: vx_ui_ui.t_ui}

  /**
   * type: uiengine
   * Template for uiengine
   */
  static t_uiengine = {}
  static e_uiengine = {vx_type: vx_ui_ui.t_uiengine}

  /**
   * type: uilist
   * List of ui
   */
  static t_uilist = {}
  static e_uilist = vx_core.vx_new_list(vx_ui_ui.t_uilist, [])

  /**
   * type: uimap
   * Map of ui
   */
  static t_uimap = {}
  static e_uimap = {vx_type: vx_ui_ui.t_uimap}
  /**
   * Constant: align-center
   * Logical Center Align in parent
   * {align}
   */
  static c_align_center = {vx_type: vx_ui_ui.t_align, vx_constdef: {pkgname: 'vx/ui/ui', name: 'align-center'}}

  /**
   * Constant: align-left
   * Logical Left Align in parent
   * {align}
   */
  static c_align_left = {vx_type: vx_ui_ui.t_align, vx_constdef: {pkgname: 'vx/ui/ui', name: 'align-left'}}

  /**
   * Constant: align-right
   * Logical Right Align in parent
   * {align}
   */
  static c_align_right = {vx_type: vx_ui_ui.t_align, vx_constdef: {pkgname: 'vx/ui/ui', name: 'align-right'}}

  /**
   * Constant: layout-app
   * {layout}
   */
  static c_layout_app = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/ui', name: 'layout-app'}}

  /**
   * Constant: layout-background
   * {layout}
   */
  static c_layout_background = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/ui', name: 'layout-background'}}

  /**
   * Constant: layout-button
   * {layout}
   */
  static c_layout_button = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/ui', name: 'layout-button'}}

  /**
   * Constant: layout-combobox
   * {layout}
   */
  static c_layout_combobox = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/ui', name: 'layout-combobox'}}

  /**
   * Constant: layout-else
   * {layout}
   */
  static c_layout_else = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/ui', name: 'layout-else'}}

  /**
   * Constant: layout-flow-columns
   * {layout}
   */
  static c_layout_flow_columns = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/ui', name: 'layout-flow-columns'}}

  /**
   * Constant: layout-flow-item
   * {layout}
   */
  static c_layout_flow_item = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/ui', name: 'layout-flow-item'}}

  /**
   * Constant: layout-flow-rows
   * {layout}
   */
  static c_layout_flow_rows = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/ui', name: 'layout-flow-rows'}}

  /**
   * Constant: layout-image
   * {layout}
   */
  static c_layout_image = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/ui', name: 'layout-image'}}

  /**
   * Constant: layout-label
   * {layout}
   */
  static c_layout_label = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/ui', name: 'layout-label'}}

  /**
   * Constant: layout-main
   * {layout}
   */
  static c_layout_main = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/ui', name: 'layout-main'}}

  /**
   * Constant: layout-maxpanel
   * {layout}
   */
  static c_layout_maxpanel = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/ui', name: 'layout-maxpanel'}}

  /**
   * Constant: layout-menubar
   * {layout}
   */
  static c_layout_menubar = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/ui', name: 'layout-menubar'}}

  /**
   * Constant: layout-menudrawer
   * {layout}
   */
  static c_layout_menudrawer = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/ui', name: 'layout-menudrawer'}}

  /**
   * Constant: layout-msgbox
   * {layout}
   */
  static c_layout_msgbox = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/ui', name: 'layout-msgbox'}}

  /**
   * Constant: layout-navbar
   * {layout}
   */
  static c_layout_navbar = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/ui', name: 'layout-navbar'}}

  /**
   * Constant: layout-navdrawer
   * {layout}
   */
  static c_layout_navdrawer = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/ui', name: 'layout-navdrawer'}}

  /**
   * Constant: layout-panel
   * {layout}
   */
  static c_layout_panel = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/ui', name: 'layout-panel'}}

  /**
   * Constant: layout-parallax
   * {layout}
   */
  static c_layout_parallax = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/ui', name: 'layout-parallax'}}

  /**
   * Constant: layout-statusbar
   * {layout}
   */
  static c_layout_statusbar = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/ui', name: 'layout-statusbar'}}

  /**
   * Constant: layout-statusdrawer
   * {layout}
   */
  static c_layout_statusdrawer = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/ui', name: 'layout-statusdrawer'}}

  /**
   * Constant: layout-text
   * {layout}
   */
  static c_layout_text = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/ui', name: 'layout-text'}}

  /**
   * Constant: layout-textentry
   * {layout}
   */
  static c_layout_textentry = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/ui', name: 'layout-textentry'}}

  /**
   * Constant: layout-titlebar
   * {layout}
   */
  static c_layout_titlebar = {vx_type: vx_ui_ui.t_layout, vx_constdef: {pkgname: 'vx/ui/ui', name: 'layout-titlebar'}}

  /**
   * Constant: pin-bottom
   * {pin}
   */
  static c_pin_bottom = {vx_type: vx_ui_ui.t_pin, vx_constdef: {pkgname: 'vx/ui/ui', name: 'pin-bottom'}}

  /**
   * Constant: pin-center
   * {pin}
   */
  static c_pin_center = {vx_type: vx_ui_ui.t_pin, vx_constdef: {pkgname: 'vx/ui/ui', name: 'pin-center'}}

  /**
   * Constant: pin-center-h
   * {pin}
   */
  static c_pin_center_h = {vx_type: vx_ui_ui.t_pin, vx_constdef: {pkgname: 'vx/ui/ui', name: 'pin-center-h'}}

  /**
   * Constant: pin-center-v
   * {pin}
   */
  static c_pin_center_v = {vx_type: vx_ui_ui.t_pin, vx_constdef: {pkgname: 'vx/ui/ui', name: 'pin-center-v'}}

  /**
   * Constant: pin-expand
   * {pin}
   */
  static c_pin_expand = {vx_type: vx_ui_ui.t_pin, vx_constdef: {pkgname: 'vx/ui/ui', name: 'pin-expand'}}

  /**
   * Constant: pin-left
   * {pin}
   */
  static c_pin_left = {vx_type: vx_ui_ui.t_pin, vx_constdef: {pkgname: 'vx/ui/ui', name: 'pin-left'}}

  /**
   * Constant: pin-right
   * {pin}
   */
  static c_pin_right = {vx_type: vx_ui_ui.t_pin, vx_constdef: {pkgname: 'vx/ui/ui', name: 'pin-right'}}

  /**
   * Constant: pin-top
   * {pin}
   */
  static c_pin_top = {vx_type: vx_ui_ui.t_pin, vx_constdef: {pkgname: 'vx/ui/ui', name: 'pin-top'}}

  /**
   * Constant: pointtype-absolute
   * {pointtype}
   */
  static c_pointtype_absolute = {vx_type: vx_ui_ui.t_pointtype, vx_constdef: {pkgname: 'vx/ui/ui', name: 'pointtype-absolute'}}

  /**
   * Constant: pointtype-percent
   * {pointtype}
   */
  static c_pointtype_percent = {vx_type: vx_ui_ui.t_pointtype, vx_constdef: {pkgname: 'vx/ui/ui', name: 'pointtype-percent'}}

  /**
   * Constant: pointtype-relative
   * {pointtype}
   */
  static c_pointtype_relative = {vx_type: vx_ui_ui.t_pointtype, vx_constdef: {pkgname: 'vx/ui/ui', name: 'pointtype-relative'}}

  /**
   * Constant: styletype-custom
   * {styletype}
   */
  static c_styletype_custom = {vx_type: vx_ui_ui.t_styletype, vx_constdef: {pkgname: 'vx/ui/ui', name: 'styletype-custom'}}

  /**
   * Constant: styletype-shared
   * {styletype}
   */
  static c_styletype_shared = {vx_type: vx_ui_ui.t_styletype, vx_constdef: {pkgname: 'vx/ui/ui', name: 'styletype-shared'}}

  /**
   * Constant: styletype-system
   * {styletype}
   */
  static c_styletype_system = {vx_type: vx_ui_ui.t_styletype, vx_constdef: {pkgname: 'vx/ui/ui', name: 'styletype-system'}}

  /**
   * @function boolean_print
   * Create a print ready version of ui
   * @param  {ui} ui
   * @return {boolean}
   */
  static t_boolean_print = {
    vx_type: vx_core.t_type
  }
  static e_boolean_print = {
    vx_type: vx_ui_ui.t_boolean_print
  }

  // (func boolean-print)
  static f_boolean_print(context, ui) {
    let output = vx_core.e_boolean
    output = vx_core.f_let(
      {"any-1": vx_core.t_boolean, "struct-2": vx_ui_ui.t_layoutengine},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const layoutengine = vx_ui_ui.f_layoutengine_readstate(context)
        const fn_print = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_boolean_print, "struct-2": vx_ui_ui.t_layoutengine}, layoutengine, ":boolean-print")
        return vx_core.vx_any_from_func(vx_core.t_boolean, fn_print, context, ui)
      })
    )
    return output
  }

  /**
   * @function boolean_writestate_from_ui
   * @param  {ui} ui
   * @return {boolean}
   */
  static t_boolean_writestate_from_ui = {
    vx_type: vx_core.t_type
  }
  static e_boolean_writestate_from_ui = {
    vx_type: vx_ui_ui.t_boolean_writestate_from_ui
  }

  // (func boolean-writestate<-ui)
  static f_boolean_writestate_from_ui(context, ui) {
    let output = vx_core.e_boolean
    output = vx_core.f_let(
      {"any-1": vx_core.t_boolean},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const uid = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_ui_ui.t_ui}, ui, ":uid")
        return vx_state.f_boolean_writestate_from_mapname_name_value(context, ":uimap", uid, ui)
      })
    )
    return output
  }

  /**
   * @function boolean_writestate_from_uiengine
   * Writes the uiengine to state
   * @param  {uiengine} uiengine
   * @return {boolean}
   */
  static t_boolean_writestate_from_uiengine = {
    vx_type: vx_core.t_type
  }
  static e_boolean_writestate_from_uiengine = {
    vx_type: vx_ui_ui.t_boolean_writestate_from_uiengine
  }

  // (func boolean-writestate<-uiengine)
  static f_boolean_writestate_from_uiengine(context, uiengine) {
    let output = vx_core.e_boolean
    output = vx_state.f_boolean_writestate_from_name_value(context, ":uiengine", uiengine)
    return output
  }

  /**
   * @function fontfacemap_from_fontfacelist
   * Returns a fontfacemap from a fontfacelist
   * @param  {fontfacelist} fontfacelist
   * @return {fontfacemap}
   */
  static t_fontfacemap_from_fontfacelist = {
    vx_type: vx_core.t_type
  }
  static e_fontfacemap_from_fontfacelist = {
    vx_type: vx_ui_ui.t_fontfacemap_from_fontfacelist
  }

  // (func fontfacemap<-fontfacelist)
  static f_fontfacemap_from_fontfacelist(fontfacelist) {
    let output = vx_ui_ui.e_fontfacemap
    output = vx_core.f_map_from_list(
      {"any-1": vx_ui_ui.t_fontface, "any-2": vx_ui_ui.t_fontface, "list-2": vx_ui_ui.t_fontfacelist, "map-1": vx_ui_ui.t_fontfacemap, "struct-2": vx_ui_ui.t_fontface},
      fontfacelist,
      vx_core.f_new(vx_core.t_any_from_any, (fontface) => 
        vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_ui_ui.t_fontface}, fontface, ":name"))
    )
    return output
  }

  /**
   * @function int_selected_from_ui
   * Returns the position of the currently selected subui
   * @param  {ui} ui
   * @return {int}
   */
  static t_int_selected_from_ui = {
    vx_type: vx_core.t_type
  }
  static e_int_selected_from_ui = {
    vx_type: vx_ui_ui.t_int_selected_from_ui
  }

  // (func int-selected<-ui)
  static f_int_selected_from_ui(ui) {
    let output = vx_core.e_int
    output = vx_core.f_let(
      {"any-1": vx_core.t_int},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const uid = vx_ui_ui.f_string_selected_from_ui(ui)
        const uidlist = vx_ui_ui.f_stringlist_from_ui(ui)
        return vx_collection.f_int_from_stringlist_find(uidlist, uid)
      })
    )
    return output
  }

  /**
   * @function layout_from_style
   * @param  {style} style
   * @return {layout}
   */
  static t_layout_from_style = {
    vx_type: vx_core.t_type
  }
  static e_layout_from_style = {
    vx_type: vx_ui_ui.t_layout_from_style
  }

  // (func layout<-style)
  static f_layout_from_style(style) {
    let output = vx_ui_ui.e_layout
    output = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_layout, "struct-2": vx_ui_ui.t_style}, style, ":layout")
    return output
  }

  /**
   * @function layout_from_ui
   * Returns the layout from layoutengine that matches the ui
   * @param  {ui} ui
   * @return {layout}
   */
  static t_layout_from_ui = {
    vx_type: vx_core.t_type
  }
  static e_layout_from_ui = {
    vx_type: vx_ui_ui.t_layout_from_ui
  }

  // (func layout<-ui)
  static f_layout_from_ui(context, ui) {
    let output = vx_ui_ui.e_layout
    output = vx_core.f_let(
      {"any-1": vx_ui_ui.t_layout},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const layoutengine = vx_ui_ui.f_layoutengine_readstate(context)
        return vx_ui_ui.f_layout_from_ui_layoutengine(ui, layoutengine)
      })
    )
    return output
  }

  /**
   * @function layout_from_ui_layoutengine
   * Returns the layout from layoutengine that matches the ui
   * @param  {ui} ui
   * @param  {layoutengine} layoutengine
   * @return {layout}
   */
  static t_layout_from_ui_layoutengine = {
    vx_type: vx_core.t_type
  }
  static e_layout_from_ui_layoutengine = {
    vx_type: vx_ui_ui.t_layout_from_ui_layoutengine
  }

  // (func layout<-ui-layoutengine)
  static f_layout_from_ui_layoutengine(ui, layoutengine) {
    let output = vx_ui_ui.e_layout
    output = vx_core.f_let(
      {"any-1": vx_ui_ui.t_layout},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const layoutmap = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_layoutmap, "struct-2": vx_ui_ui.t_layoutengine}, layoutengine, ":layoutmap")
        const layoutelse = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_layout, "struct-2": vx_ui_ui.t_layoutengine}, layoutengine, ":layoutelse")
        return vx_ui_ui.f_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse)
      })
    )
    return output
  }

  /**
   * @function layout_from_ui_layoutmap_else
   * Returns a layout from a given ui, layoutmap, and layoutelse
   * @param  {ui} ui
   * @param  {layoutmap} layoutmap
   * @param  {layout} layoutelse
   * @return {layout}
   */
  static t_layout_from_ui_layoutmap_else = {
    vx_type: vx_core.t_type
  }
  static e_layout_from_ui_layoutmap_else = {
    vx_type: vx_ui_ui.t_layout_from_ui_layoutmap_else
  }

  // (func layout<-ui-layoutmap-else)
  static f_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse) {
    let output = vx_ui_ui.e_layout
    output = vx_core.f_let(
      {"any-1": vx_ui_ui.t_layout},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const style = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_style, "struct-2": vx_ui_ui.t_ui}, ui, ":style")
        const layout = vx_ui_ui.f_layout_from_style(style)
        const layname = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_ui_ui.t_layout}, layout, ":name")
        const layout1 = vx_core.f_any_from_map({"any-1": vx_ui_ui.t_layout, "map-1": vx_ui_ui.t_layoutmap}, layoutmap, layname)
        const layout2 = vx_core.f_if_1(
          {"any-1": vx_ui_ui.t_layout},
          vx_core.f_notempty_1(layout1),
          layout1,
          layoutelse
        )
        return layout2
      })
    )
    return output
  }

  /**
   * @function layoutengine_readstate
   * Returns the current layoutengine from state
   * @return {layoutengine}
   */
  static t_layoutengine_readstate = {
    vx_type: vx_core.t_type
  }
  static e_layoutengine_readstate = {
    vx_type: vx_ui_ui.t_layoutengine_readstate
  }

  // (func layoutengine-readstate)
  static f_layoutengine_readstate(context) {
    let output = vx_ui_ui.e_layoutengine
    output = vx_core.f_let(
      {"any-1": vx_ui_ui.t_layoutengine, "struct-2": vx_ui_ui.t_uiengine},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const uiengine = vx_ui_ui.f_uiengine_readstate(context)
        return vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_layoutengine, "struct-2": vx_ui_ui.t_uiengine}, uiengine, ":layoutengine")
      })
    )
    return output
  }

  /**
   * @function layoutmap_from_layoutlist
   * Returns an layoutmap from an layoutlist
   * @param  {layoutlist} layoutlist
   * @return {layoutmap}
   */
  static t_layoutmap_from_layoutlist = {
    vx_type: vx_core.t_type
  }
  static e_layoutmap_from_layoutlist = {
    vx_type: vx_ui_ui.t_layoutmap_from_layoutlist
  }

  // (func layoutmap<-layoutlist)
  static f_layoutmap_from_layoutlist(layoutlist) {
    let output = vx_ui_ui.e_layoutmap
    output = vx_core.f_map_from_list(
      {"any-1": vx_ui_ui.t_layout, "any-2": vx_ui_ui.t_layout, "list-2": vx_ui_ui.t_layoutlist, "map-1": vx_ui_ui.t_layoutmap, "struct-2": vx_ui_ui.t_layout},
      layoutlist,
      vx_core.f_new(vx_core.t_any_from_any, (layout) => 
        vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_ui_ui.t_layout}, layout, ":name"))
    )
    return output
  }

  /**
   * @function string_selected_from_ui
   * Return the uid of the ui with selected=true
   * @param  {ui} ui
   * @return {string}
   */
  static t_string_selected_from_ui = {
    vx_type: vx_core.t_type
  }
  static e_string_selected_from_ui = {
    vx_type: vx_ui_ui.t_string_selected_from_ui
  }

  // (func string-selected<-ui)
  static f_string_selected_from_ui(ui) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string, "struct-2": vx_ui_ui.t_ui},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const selectedui = vx_ui_ui.f_ui_selected_from_ui(ui)
        return vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_ui_ui.t_ui}, selectedui, ":uid")
      })
    )
    return output
  }

  /**
   * @function stringlist_selected_from_ui
   * Return a list of uid of the ui with selected=true
   * @param  {ui} ui
   * @return {stringlist}
   */
  static t_stringlist_selected_from_ui = {
    vx_type: vx_core.t_type
  }
  static e_stringlist_selected_from_ui = {
    vx_type: vx_ui_ui.t_stringlist_selected_from_ui
  }

  // (func stringlist-selected<-ui)
  static f_stringlist_selected_from_ui(ui) {
    let output = vx_core.e_stringlist
    output = vx_core.f_let(
      {"any-1": vx_core.t_stringlist, "any-2": vx_ui_ui.t_ui, "list-1": vx_core.t_stringlist, "list-2": vx_ui_ui.t_uilist},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const uimap = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_uimap, "struct-2": vx_ui_ui.t_ui}, ui, ":uimap")
        const uilist = vx_ui_ui.f_uilist_from_uimap(uimap)
        return vx_core.f_list_from_list_1(
          {"any-1": vx_core.t_string, "any-2": vx_ui_ui.t_ui, "list-1": vx_core.t_stringlist, "list-2": vx_ui_ui.t_uilist},
          uilist,
          vx_core.f_new(vx_core.t_any_from_any, (item) => 
            vx_core.f_if_1(
              {"any-1": vx_core.t_string},
              vx_core.f_any_from_struct({"any-1": vx_core.t_boolean, "struct-2": vx_ui_ui.t_ui}, item, ":selected"),
              vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_ui_ui.t_ui}, item, ":uid"),
              ""
            ))
        )
      })
    )
    return output
  }

  /**
   * @function stringlist_from_ui
   * Return a list of uid of the ui
   * @param  {ui} ui
   * @return {stringlist}
   */
  static t_stringlist_from_ui = {
    vx_type: vx_core.t_type
  }
  static e_stringlist_from_ui = {
    vx_type: vx_ui_ui.t_stringlist_from_ui
  }

  // (func stringlist<-ui)
  static f_stringlist_from_ui(ui) {
    let output = vx_core.e_stringlist
    output = vx_core.f_let(
      {"any-1": vx_core.t_stringlist, "map-1": vx_ui_ui.t_uimap},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const uimap = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_uimap, "struct-2": vx_ui_ui.t_ui}, ui, ":uimap")
        return vx_collection.f_stringlist_from_map(uimap)
      })
    )
    return output
  }

  /**
   * @function stylemap_from_stylelist
   * @param  {stylelist} stylelist
   * @return {stylemap}
   */
  static t_stylemap_from_stylelist = {
    vx_type: vx_core.t_type
  }
  static e_stylemap_from_stylelist = {
    vx_type: vx_ui_ui.t_stylemap_from_stylelist
  }

  // (func stylemap<-stylelist)
  static f_stylemap_from_stylelist(stylelist) {
    let output = vx_ui_ui.e_stylemap
    output = vx_core.f_map_from_list(
      {"any-1": vx_ui_ui.t_style, "any-2": vx_ui_ui.t_style, "list-2": vx_ui_ui.t_stylelist, "map-1": vx_ui_ui.t_stylemap, "struct-2": vx_ui_ui.t_style},
      stylelist,
      vx_core.f_new(vx_core.t_any_from_any, (style) => 
        vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_ui_ui.t_style}, style, ":name"))
    )
    return output
  }

  /**
   * @function stylesheet_readstate
   * Returns the current uiengine from state
   * @return {stylesheet}
   */
  static t_stylesheet_readstate = {
    vx_type: vx_core.t_type
  }
  static e_stylesheet_readstate = {
    vx_type: vx_ui_ui.t_stylesheet_readstate
  }

  // (func stylesheet-readstate)
  static f_stylesheet_readstate(context) {
    let output = vx_ui_ui.e_stylesheet
    output = vx_core.f_let(
      {"any-1": vx_ui_ui.t_stylesheet, "struct-2": vx_ui_ui.t_uiengine},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const uiengine = vx_ui_ui.f_uiengine_readstate(context)
        return vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_stylesheet, "struct-2": vx_ui_ui.t_uiengine}, uiengine, ":stylesheet")
      })
    )
    return output
  }

  /**
   * @function stylesheet_render
   * Template for rendering stylesheet
   * @param  {stylesheet} stylesheetui
   * @return {stylesheet}
   */
  static t_stylesheet_render = {
    vx_type: vx_core.t_type
  }
  static e_stylesheet_render = {
    vx_type: vx_ui_ui.t_stylesheet_render
  }

  // (func stylesheet-render)
  static f_stylesheet_render(stylesheetui) {
    let output = vx_ui_ui.e_stylesheet
    return output
  }

  /**
   * @function ui_child_from_ui_uid
   * Returns then named child from a ui.
   * @param  {ui} ui
   * @param  {string} uid
   * @return {ui}
   */
  static t_ui_child_from_ui_uid = {
    vx_type: vx_core.t_type
  }
  static e_ui_child_from_ui_uid = {
    vx_type: vx_ui_ui.t_ui_child_from_ui_uid
  }

  // (func ui-child<-ui-uid)
  static f_ui_child_from_ui_uid(ui, uid) {
    let output = vx_ui_ui.e_ui
    output = vx_core.f_let(
      {"any-1": vx_ui_ui.t_ui, "map-1": vx_ui_ui.t_uimap},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const childmap = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_uimap, "struct-2": vx_ui_ui.t_ui}, ui, ":uimap")
        return vx_core.f_any_from_map({"any-1": vx_ui_ui.t_ui, "map-1": vx_ui_ui.t_uimap}, childmap, uid)
      })
    )
    return output
  }

  /**
   * @function ui_from_from_event
   * Returns (:from event) cast as ui
   * @param  {event} event
   * @return {ui}
   */
  static t_ui_from_from_event = {
    vx_type: vx_core.t_type
  }
  static e_ui_from_from_event = {
    vx_type: vx_ui_ui.t_ui_from_from_event
  }

  // (func ui-from<-event)
  static f_ui_from_from_event(context, event) {
    let output = vx_ui_ui.e_ui
    output = vx_core.f_let(
      {"any-1": vx_ui_ui.t_ui},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const uid = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_event.t_event}, event, ":from")
        return vx_ui_ui.f_ui_readstate_from_uid(context, uid)
      })
    )
    return output
  }

  /**
   * @function ui_layout_from_ui
   * Returns a ui with a layout added to each ui.
   * @param  {ui} ui
   * @return {ui}
   */
  static t_ui_layout_from_ui = {
    vx_type: vx_core.t_type
  }
  static e_ui_layout_from_ui = {
    vx_type: vx_ui_ui.t_ui_layout_from_ui
  }

  // (func ui-layout<-ui)
  static f_ui_layout_from_ui(context, ui) {
    let output = vx_ui_ui.e_ui
    output = vx_core.f_let(
      {"any-1": vx_ui_ui.t_ui},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const uiengine = vx_ui_ui.f_uiengine_readstate(context)
        return vx_ui_ui.f_ui_layout_from_ui_uiengine(ui, uiengine)
      })
    )
    return output
  }

  /**
   * @function ui_layout_from_ui_layoutengine
   * Returns a ui with a layout added to each ui.
   * @param  {ui} ui
   * @param  {layoutengine} layoutengine
   * @return {ui}
   */
  static t_ui_layout_from_ui_layoutengine = {
    vx_type: vx_core.t_type
  }
  static e_ui_layout_from_ui_layoutengine = {
    vx_type: vx_ui_ui.t_ui_layout_from_ui_layoutengine
  }

  // (func ui-layout<-ui-layoutengine)
  static f_ui_layout_from_ui_layoutengine(ui, layoutengine) {
    let output = vx_ui_ui.e_ui
    output = vx_core.f_let(
      {"any-1": vx_ui_ui.t_ui},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const layoutmap = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_layoutmap, "struct-2": vx_ui_ui.t_layoutengine}, layoutengine, ":layoutmap")
        const layoutelse = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_layout, "struct-2": vx_ui_ui.t_layoutengine}, layoutengine, ":layoutelse")
        return vx_ui_ui.f_ui_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse)
      })
    )
    return output
  }

  /**
   * @function ui_layout_from_ui_layoutmap_else
   * Returns a ui with a layout added to each ui.
   * @param  {ui} ui
   * @param  {layoutmap} layoutmap
   * @param  {layout} layoutelse
   * @return {ui}
   */
  static t_ui_layout_from_ui_layoutmap_else = {
    vx_type: vx_core.t_type
  }
  static e_ui_layout_from_ui_layoutmap_else = {
    vx_type: vx_ui_ui.t_ui_layout_from_ui_layoutmap_else
  }

  // (func ui-layout<-ui-layoutmap-else)
  static f_ui_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse) {
    let output = vx_ui_ui.e_ui
    output = vx_core.f_let(
      {"any-1": vx_ui_ui.t_ui},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const uimap = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_uimap, "struct-2": vx_ui_ui.t_ui}, ui, ":uimap")
        const layout1 = vx_ui_ui.f_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse)
        const uimap2 = vx_ui_ui.f_uimap_layout_from_uimap_layoutmap_else(uimap, layoutmap, layoutelse)
        return vx_core.f_copy(ui, ":layout", layout1, ":uimap", uimap2)
      })
    )
    return output
  }

  /**
   * @function ui_layout_from_ui_uiengine
   * Returns a ui with a layout added to each ui.
   * @param  {ui} ui
   * @param  {uiengine} uiengine
   * @return {ui}
   */
  static t_ui_layout_from_ui_uiengine = {
    vx_type: vx_core.t_type
  }
  static e_ui_layout_from_ui_uiengine = {
    vx_type: vx_ui_ui.t_ui_layout_from_ui_uiengine
  }

  // (func ui-layout<-ui-uiengine)
  static f_ui_layout_from_ui_uiengine(ui, uiengine) {
    let output = vx_ui_ui.e_ui
    output = vx_core.f_let(
      {"any-1": vx_ui_ui.t_ui},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const layoutengine = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_layoutengine, "struct-2": vx_ui_ui.t_uiengine}, uiengine, ":layoutengine")
        return vx_ui_ui.f_ui_layout_from_ui_layoutengine(ui, layoutengine)
      })
    )
    return output
  }

  /**
   * @function ui_readstate_from_uid
   * Returns the named ui from state
   * @param  {string} uid
   * @return {ui}
   */
  static t_ui_readstate_from_uid = {
    vx_type: vx_core.t_type
  }
  static e_ui_readstate_from_uid = {
    vx_type: vx_ui_ui.t_ui_readstate_from_uid
  }

  // (func ui-readstate<-uid)
  static f_ui_readstate_from_uid(context, uid) {
    let output = vx_ui_ui.e_ui
    output = vx_state.f_any_readstate_from_mapname_name({"any-1": vx_ui_ui.t_ui}, context, ":uimap", uid)
    return output
  }

  /**
   * @function ui_render
   * @param  {ui} uiarg
   * @return {ui}
   */
  static t_ui_render = {
    vx_type: vx_core.t_type
  }
  static e_ui_render = {
    vx_type: vx_ui_ui.t_ui_render
  }

  // (func ui-render)
  static f_ui_render(uiarg) {
    let output = vx_ui_ui.e_ui
    output = vx_ui_ui.f_ui_render_from_ui_orig_parent(
      uiarg,
      vx_core.f_empty(
        vx_ui_ui.t_ui
      ),
      vx_core.f_empty(
        vx_ui_ui.t_ui
      )
    )
    return output
  }

  /**
   * @function ui_render_from_fn_render_ui_orig_parent
   * Returns a rendered ui
   * @param  {ui_render_from_ui_orig_parent} fn_render
   * @param  {ui} ui
   * @param  {ui} orig
   * @param  {ui} parent
   * @return {ui}
   */
  static t_ui_render_from_fn_render_ui_orig_parent = {
    vx_type: vx_core.t_type
  }
  static e_ui_render_from_fn_render_ui_orig_parent = {
    vx_type: vx_ui_ui.t_ui_render_from_fn_render_ui_orig_parent
  }

  // (func ui-render<-fn-render-ui-orig-parent)
  static f_ui_render_from_fn_render_ui_orig_parent(fn_render, ui, orig, parent) {
    let output = vx_ui_ui.e_ui
    output = vx_core.vx_any_from_func(vx_ui_ui.t_ui, fn_render, ui, orig, parent)
    return output
  }

  /**
   * @function ui_render_from_ui_orig_parent
   * Returns a rendered object from a UI Element.
   * @param  {ui} ui
   * @param  {ui} orig
   * @param  {ui} parent
   * @return {ui}
   */
  static t_ui_render_from_ui_orig_parent = {
    vx_type: vx_core.t_type
  }
  static e_ui_render_from_ui_orig_parent = {
    vx_type: vx_ui_ui.t_ui_render_from_ui_orig_parent
  }

  // (func ui-render<-ui-orig-parent)
  static f_ui_render_from_ui_orig_parent(ui, orig, parent) {
    let output = vx_ui_ui.e_ui
    output = vx_core.f_if_2(
      {"any-1": vx_ui_ui.t_ui},
      vx_core.f_then(
        vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eqeq(ui, orig)}),
        vx_core.f_new(vx_core.t_any_from_func, () => {return orig})
      ),
      vx_core.f_else(
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_let(
          {"any-1": vx_ui_ui.t_ui},
          [],
          vx_core.f_new(vx_core.t_any_from_func, () => {
            const uimap = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_uimap, "struct-2": vx_ui_ui.t_ui}, ui, ":uimap")
            const layout = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_layout, "struct-2": vx_ui_ui.t_ui}, ui, ":layout")
            const uiout = vx_ui_ui.f_ui_from_layout_ui_orig_parent(layout, ui, orig, parent)
            return uiout
          })
        )})
      )
    )
    return output
  }

  /**
   * @function ui_render_from_ui_parent_selected
   * Return a ui after changing selected item and writing it.
   * @param  {ui} ui
   * @param  {ui} parent
   * @param  {int} selected
   * @return {ui}
   */
  static t_ui_render_from_ui_parent_selected = {
    vx_type: vx_core.t_type
  }
  static e_ui_render_from_ui_parent_selected = {
    vx_type: vx_ui_ui.t_ui_render_from_ui_parent_selected
  }

  // (func ui-render<-ui-parent-selected)
  static f_ui_render_from_ui_parent_selected(ui, parent, selected) {
    let output = vx_ui_ui.e_ui
    output = vx_core.f_let(
      {"any-1": vx_ui_ui.t_ui},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const uichg = vx_ui_ui.f_ui_from_ui_selected(ui, selected)
        const childmap = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_uimap, "struct-2": vx_ui_ui.t_ui}, uichg, ":uimap")
        return vx_ui_ui.f_ui_render_from_ui_orig_parent(uichg, ui, parent)
      })
    )
    return output
  }

  /**
   * @function ui_selected_from_ui
   * Returns the ui of the first ui with selected=true
   * @param  {ui} ui
   * @return {ui}
   */
  static t_ui_selected_from_ui = {
    vx_type: vx_core.t_type
  }
  static e_ui_selected_from_ui = {
    vx_type: vx_ui_ui.t_ui_selected_from_ui
  }

  // (func ui-selected<-ui)
  static f_ui_selected_from_ui(ui) {
    let output = vx_ui_ui.e_ui
    output = vx_core.f_let(
      {"any-1": vx_ui_ui.t_ui, "list-1": vx_ui_ui.t_uilist},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const uilist = vx_ui_ui.f_uilist_selected_from_ui(ui)
        return vx_core.f_first_from_list({"any-1": vx_ui_ui.t_ui, "list-1": vx_ui_ui.t_uilist}, uilist)
      })
    )
    return output
  }

  /**
   * @function ui_writechild_from_ui_child
   * Returns the given ui with the child added to uimap
   * @param  {ui} ui
   * @param  {ui} child
   * @return {ui}
   */
  static t_ui_writechild_from_ui_child = {
    vx_type: vx_core.t_type
  }
  static e_ui_writechild_from_ui_child = {
    vx_type: vx_ui_ui.t_ui_writechild_from_ui_child
  }

  // (func ui-writechild<-ui-child)
  static f_ui_writechild_from_ui_child(ui, child) {
    let output = vx_ui_ui.e_ui
    output = vx_core.f_let(
      {"any-1": vx_ui_ui.t_ui},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const childid = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_ui_ui.t_ui}, child, ":uid")
        const uimap = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_uimap, "struct-2": vx_ui_ui.t_ui}, ui, ":uimap")
        const write = vx_core.f_boolean_write_from_map_name_value(uimap, childid, child)
        return ui
      })
    )
    return output
  }

  /**
   * @function ui_writechildmap_from_ui_childmap
   * Returns the given ui with the members of childmap added to uimap
   * @param  {ui} ui
   * @param  {uimap} childmap
   * @return {ui}
   */
  static t_ui_writechildmap_from_ui_childmap = {
    vx_type: vx_core.t_type
  }
  static e_ui_writechildmap_from_ui_childmap = {
    vx_type: vx_ui_ui.t_ui_writechildmap_from_ui_childmap
  }

  // (func ui-writechildmap<-ui-childmap)
  static f_ui_writechildmap_from_ui_childmap(ui, childmap) {
    let output = vx_ui_ui.e_ui
    output = vx_core.f_let(
      {"any-1": vx_ui_ui.t_ui},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const workmap = vx_core.f_map_from_map_1(
          {"any-1": vx_ui_ui.t_ui, "any-2": vx_ui_ui.t_ui, "map-1": vx_ui_ui.t_uimap, "map-2": vx_ui_ui.t_uimap},
          childmap,
          vx_core.f_new(vx_core.t_any_from_key_value, ([key, value]) => 
            vx_ui_ui.f_ui_writechild_from_ui_child(ui, value))
        )
        return ui
      })
    )
    return output
  }

  /**
   * @function ui_from_layout_ui_orig_parent
   * @param  {layout} layout
   * @param  {ui} uiarg
   * @param  {ui} uiorig
   * @param  {ui} parent
   * @return {ui}
   */
  static t_ui_from_layout_ui_orig_parent = {
    vx_type: vx_core.t_type
  }
  static e_ui_from_layout_ui_orig_parent = {
    vx_type: vx_ui_ui.t_ui_from_layout_ui_orig_parent
  }

  // (func ui<-layout-ui-orig-parent)
  static f_ui_from_layout_ui_orig_parent(layout, uiarg, uiorig, parent) {
    let output = vx_ui_ui.e_ui
    output = vx_core.f_let(
      {"any-1": vx_ui_ui.t_ui, "struct-2": vx_ui_ui.t_layout},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const name = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_ui_ui.t_layout}, layout, ":name")
        const fn_layout = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_ui_render_from_ui_orig_parent, "struct-2": vx_ui_ui.t_layout}, layout, ":fn-layout")
        const uichg = vx_core.vx_any_from_func(vx_ui_ui.t_ui, fn_layout, uiarg, uiorig, parent)
        return uichg
      })
    )
    return output
  }

  /**
   * @function ui_from_ui_selected
   * Return a ui after changing selected item and writing it.
   * @param  {ui} ui
   * @param  {int} selected
   * @return {ui}
   */
  static t_ui_from_ui_selected = {
    vx_type: vx_core.t_type
  }
  static e_ui_from_ui_selected = {
    vx_type: vx_ui_ui.t_ui_from_ui_selected
  }

  // (func ui<-ui-selected)
  static f_ui_from_ui_selected(ui, selected) {
    let output = vx_ui_ui.e_ui
    output = vx_core.f_if_2(
      {"any-1": vx_ui_ui.t_ui},
      vx_core.f_then(
        vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_lt(selected, 1)}),
        vx_core.f_new(vx_core.t_any_from_func, () => {return ui})
      ),
      vx_core.f_else(
        vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_let(
          {"any-1": vx_ui_ui.t_ui},
          [],
          vx_core.f_new(vx_core.t_any_from_func, () => {
            const uimap = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_uimap, "struct-2": vx_ui_ui.t_ui}, ui, ":uimap")
            const uilist1 = vx_ui_ui.f_uilist_from_uimap(uimap)
            const uilist2 = vx_core.f_list_from_list_intany(
              {"any-1": vx_ui_ui.t_ui, "any-2": vx_ui_ui.t_ui, "list-1": vx_ui_ui.t_uilist, "list-2": vx_ui_ui.t_uilist},
              uilist1,
              vx_core.f_new(vx_core.t_any_from_int_any, (posval, uival) => 
                vx_core.f_if_2(
                  {"any-1": vx_ui_ui.t_ui},
                  vx_core.f_then(
                    vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_eq(posval, selected)}),
                    vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(
                      uival,
                      ":selected",
                      true
                    )})
                  ),
                  vx_core.f_else(
                    vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_copy(
                      uival,
                      ":selected",
                      false
                    )})
                  )
                ))
            )
            const childmap = vx_ui_ui.f_uimap_from_uilist(uilist2)
            return vx_core.f_copy(ui, ":uimap", childmap)
          })
        )})
      )
    )
    return output
  }

  /**
   * @function uid_selected_from_ui
   * Returns the uid of the first ui with selected=true
   * @param  {ui} ui
   * @return {string}
   */
  static t_uid_selected_from_ui = {
    vx_type: vx_core.t_type
  }
  static e_uid_selected_from_ui = {
    vx_type: vx_ui_ui.t_uid_selected_from_ui
  }

  // (func uid-selected<-ui)
  static f_uid_selected_from_ui(ui) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string, "list-1": vx_core.t_stringlist},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const uidlist = vx_ui_ui.f_stringlist_selected_from_ui(ui)
        return vx_core.f_first_from_list({"any-1": vx_core.t_string, "list-1": vx_core.t_stringlist}, uidlist)
      })
    )
    return output
  }

  /**
   * @function uiengine_readstate
   * Returns the current uiengine from state
   * @return {uiengine}
   */
  static t_uiengine_readstate = {
    vx_type: vx_core.t_type
  }
  static e_uiengine_readstate = {
    vx_type: vx_ui_ui.t_uiengine_readstate
  }

  // (func uiengine-readstate)
  static f_uiengine_readstate(context) {
    let output = vx_ui_ui.e_uiengine
    output = vx_state.f_any_readstate_from_name({"any-1": vx_ui_ui.t_uiengine}, context, ":uiengine")
    return output
  }

  /**
   * @function uiengine_render
   * Returns a fully rendered ui for a given engine.
   * @param  {uiengine} uiengine
   * @return {uiengine}
   */
  static t_uiengine_render = {
    vx_type: vx_core.t_type
  }
  static e_uiengine_render = {
    vx_type: vx_ui_ui.t_uiengine_render
  }

  // (func uiengine-render)
  static f_uiengine_render(context, uiengine) {
    let output = vx_ui_ui.e_uiengine
    output = vx_core.f_let(
      {"any-1": vx_ui_ui.t_uiengine, "struct-2": vx_ui_ui.t_layoutengine},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const stylesheet = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_stylesheet, "struct-2": vx_ui_ui.t_uiengine}, uiengine, ":stylesheet")
        const ui = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_ui, "struct-2": vx_ui_ui.t_uiengine}, uiengine, ":ui")
        const layoutengine = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_layoutengine, "struct-2": vx_ui_ui.t_uiengine}, uiengine, ":layoutengine")
        const stylesheetrender = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_stylesheet_render, "struct-2": vx_ui_ui.t_layoutengine}, layoutengine, ":stylesheetrender")
        const stylesheetrend = vx_core.vx_any_from_func(vx_ui_ui.t_stylesheet, stylesheetrender, stylesheet)
        const uirenderer = vx_ui_ui.f_ui_layout_from_ui_layoutengine(ui, layoutengine)
        const uirendered = vx_ui_ui.f_ui_render(uirenderer)
        return vx_core.f_copy(uiengine, ":ui", uirendered)
      })
    )
    return output
  }

  /**
   * @function uilist_selected_from_ui
   * Return a uilist of the ui with selected=true
   * @param  {ui} uiarg
   * @return {uilist}
   */
  static t_uilist_selected_from_ui = {
    vx_type: vx_core.t_type
  }
  static e_uilist_selected_from_ui = {
    vx_type: vx_ui_ui.t_uilist_selected_from_ui
  }

  // (func uilist-selected<-ui)
  static f_uilist_selected_from_ui(uiarg) {
    let output = vx_ui_ui.e_uilist
    output = vx_core.f_let(
      {"any-1": vx_ui_ui.t_uilist, "any-2": vx_ui_ui.t_ui, "list-1": vx_ui_ui.t_uilist, "list-2": vx_ui_ui.t_uilist},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const uimap = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_uimap, "struct-2": vx_ui_ui.t_ui}, uiarg, ":uimap")
        const uilist = vx_ui_ui.f_uilist_from_uimap(uimap)
        return vx_collection.f_list_from_list_filter(
          {"any-1": vx_ui_ui.t_ui, "any-2": vx_ui_ui.t_ui, "list-1": vx_ui_ui.t_uilist, "list-2": vx_ui_ui.t_uilist},
          uilist,
          vx_core.f_new(vx_core.t_any_from_any, (item) => 
            vx_core.f_if(
              {"any-1": vx_ui_ui.t_ui},
              vx_core.f_any_from_struct({"any-1": vx_core.t_boolean, "struct-2": vx_ui_ui.t_ui}, item, ":selected"),
              item
            ))
        )
      })
    )
    return output
  }

  /**
   * @function uilist_from_uimap
   * @param  {uimap} uimap
   * @return {uilist}
   */
  static t_uilist_from_uimap = {
    vx_type: vx_core.t_type
  }
  static e_uilist_from_uimap = {
    vx_type: vx_ui_ui.t_uilist_from_uimap
  }

  // (func uilist<-uimap)
  static f_uilist_from_uimap(uimap) {
    let output = vx_ui_ui.e_uilist
    output = vx_core.f_list_from_map_1(
      {"any-1": vx_ui_ui.t_ui, "any-2": vx_ui_ui.t_ui, "list-1": vx_ui_ui.t_uilist, "map-2": vx_ui_ui.t_uimap},
      uimap,
      vx_core.f_new(vx_core.t_any_from_key_value, ([key, item]) => item)
    )
    return output
  }

  /**
   * @function uimap_layout_from_uimap_layoutmap_else
   * Returns a uimap with a renderer added to each ui.
   * @param  {uimap} uimap
   * @param  {layoutmap} layoutmap
   * @param  {layout} layoutelse
   * @return {uimap}
   */
  static t_uimap_layout_from_uimap_layoutmap_else = {
    vx_type: vx_core.t_type
  }
  static e_uimap_layout_from_uimap_layoutmap_else = {
    vx_type: vx_ui_ui.t_uimap_layout_from_uimap_layoutmap_else
  }

  // (func uimap-layout<-uimap-layoutmap-else)
  static f_uimap_layout_from_uimap_layoutmap_else(uimap, layoutmap, layoutelse) {
    let output = vx_ui_ui.e_uimap
    output = vx_core.f_map_from_map_1(
      {"any-1": vx_ui_ui.t_ui, "any-2": vx_ui_ui.t_ui, "map-1": vx_ui_ui.t_uimap, "map-2": vx_ui_ui.t_uimap},
      uimap,
      vx_core.f_new(vx_core.t_any_from_key_value, ([key, ui]) => 
        vx_ui_ui.f_ui_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse))
    )
    return output
  }

  /**
   * @function uimap_render_from_uimap_parent
   * Renders a uimap and returns a rendered uimap.
   * @param  {uimap} uimap
   * @param  {ui} parent
   * @return {uimap}
   */
  static t_uimap_render_from_uimap_parent = {
    vx_type: vx_core.t_type
  }
  static e_uimap_render_from_uimap_parent = {
    vx_type: vx_ui_ui.t_uimap_render_from_uimap_parent
  }

  // (func uimap-render<-uimap-parent)
  static f_uimap_render_from_uimap_parent(uimap, parent) {
    let output = vx_ui_ui.e_uimap
    output = vx_core.f_map_from_map_1(
      {"any-1": vx_ui_ui.t_ui, "any-2": vx_ui_ui.t_ui, "map-1": vx_ui_ui.t_uimap, "map-2": vx_ui_ui.t_uimap},
      uimap,
      vx_core.f_new(vx_core.t_any_from_key_value, ([key, val]) => 
        vx_ui_ui.f_ui_render_from_ui_orig_parent(
          val,
          vx_core.f_empty(
            vx_ui_ui.t_ui
          ),
          parent
        ))
    )
    return output
  }

  /**
   * @function uimap_from_uilist
   * @param  {uilist} ... uilist
   * @return {uimap}
   */
  static t_uimap_from_uilist = {
    vx_type: vx_core.t_type
  }
  static e_uimap_from_uilist = {
    vx_type: vx_ui_ui.t_uimap_from_uilist
  }

  // (func uimap<-uilist)
  static f_uimap_from_uilist(...uilist) {
    let output = vx_ui_ui.e_uimap
    uilist = vx_core.f_new(vx_ui_ui.t_uilist, ...uilist)
    output = vx_core.f_map_from_list(
      {"any-1": vx_ui_ui.t_ui, "any-2": vx_ui_ui.t_ui, "list-2": vx_ui_ui.t_uilist, "map-1": vx_ui_ui.t_uimap, "struct-2": vx_ui_ui.t_ui},
      uilist,
      vx_core.f_new(vx_core.t_any_from_any, (ui) => 
        vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_ui_ui.t_ui}, ui, ":uid"))
    )
    return output
  }

  /**
   * @function uimap_from_uimap_data
   * Template for creating uimap dynamically
   * @param  {uimap} uimap
   * @param  {any} data
   * @return {uimap}
   */
  static t_uimap_from_uimap_data = {
    vx_type: vx_core.t_type
  }
  static e_uimap_from_uimap_data = {
    vx_type: vx_ui_ui.t_uimap_from_uimap_data
  }

  // (func uimap<-uimap-data)
  static f_uimap_from_uimap_data(uimap, data) {
    let output = vx_ui_ui.e_uimap
    return output
  }



  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      "align-center": vx_ui_ui.c_align_center,
      "align-left": vx_ui_ui.c_align_left,
      "align-right": vx_ui_ui.c_align_right,
      "layout-app": vx_ui_ui.c_layout_app,
      "layout-background": vx_ui_ui.c_layout_background,
      "layout-button": vx_ui_ui.c_layout_button,
      "layout-combobox": vx_ui_ui.c_layout_combobox,
      "layout-else": vx_ui_ui.c_layout_else,
      "layout-flow-columns": vx_ui_ui.c_layout_flow_columns,
      "layout-flow-item": vx_ui_ui.c_layout_flow_item,
      "layout-flow-rows": vx_ui_ui.c_layout_flow_rows,
      "layout-image": vx_ui_ui.c_layout_image,
      "layout-label": vx_ui_ui.c_layout_label,
      "layout-main": vx_ui_ui.c_layout_main,
      "layout-maxpanel": vx_ui_ui.c_layout_maxpanel,
      "layout-menubar": vx_ui_ui.c_layout_menubar,
      "layout-menudrawer": vx_ui_ui.c_layout_menudrawer,
      "layout-msgbox": vx_ui_ui.c_layout_msgbox,
      "layout-navbar": vx_ui_ui.c_layout_navbar,
      "layout-navdrawer": vx_ui_ui.c_layout_navdrawer,
      "layout-panel": vx_ui_ui.c_layout_panel,
      "layout-parallax": vx_ui_ui.c_layout_parallax,
      "layout-statusbar": vx_ui_ui.c_layout_statusbar,
      "layout-statusdrawer": vx_ui_ui.c_layout_statusdrawer,
      "layout-text": vx_ui_ui.c_layout_text,
      "layout-textentry": vx_ui_ui.c_layout_textentry,
      "layout-titlebar": vx_ui_ui.c_layout_titlebar,
      "pin-bottom": vx_ui_ui.c_pin_bottom,
      "pin-center": vx_ui_ui.c_pin_center,
      "pin-center-h": vx_ui_ui.c_pin_center_h,
      "pin-center-v": vx_ui_ui.c_pin_center_v,
      "pin-expand": vx_ui_ui.c_pin_expand,
      "pin-left": vx_ui_ui.c_pin_left,
      "pin-right": vx_ui_ui.c_pin_right,
      "pin-top": vx_ui_ui.c_pin_top,
      "pointtype-absolute": vx_ui_ui.c_pointtype_absolute,
      "pointtype-percent": vx_ui_ui.c_pointtype_percent,
      "pointtype-relative": vx_ui_ui.c_pointtype_relative,
      "styletype-custom": vx_ui_ui.c_styletype_custom,
      "styletype-shared": vx_ui_ui.c_styletype_shared,
      "styletype-system": vx_ui_ui.c_styletype_system
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "align": vx_ui_ui.e_align,
      "bounds": vx_ui_ui.e_bounds,
      "cursor": vx_ui_ui.e_cursor,
      "cursor-pointer": vx_ui_ui.e_cursor_pointer,
      "font": vx_ui_ui.e_font,
      "fontface": vx_ui_ui.e_fontface,
      "fontfacelist": vx_ui_ui.e_fontfacelist,
      "fontfacemap": vx_ui_ui.e_fontfacemap,
      "fontmap": vx_ui_ui.e_fontmap,
      "fontstyle": vx_ui_ui.e_fontstyle,
      "fontstylemap": vx_ui_ui.e_fontstylemap,
      "image": vx_ui_ui.e_image,
      "layout": vx_ui_ui.e_layout,
      "layoutengine": vx_ui_ui.e_layoutengine,
      "layoutlist": vx_ui_ui.e_layoutlist,
      "layoutmap": vx_ui_ui.e_layoutmap,
      "pin": vx_ui_ui.e_pin,
      "point": vx_ui_ui.e_point,
      "pointtype": vx_ui_ui.e_pointtype,
      "style": vx_ui_ui.e_style,
      "stylelist": vx_ui_ui.e_stylelist,
      "stylemap": vx_ui_ui.e_stylemap,
      "stylesheet": vx_ui_ui.e_stylesheet,
      "styletype": vx_ui_ui.e_styletype,
      "ui": vx_ui_ui.e_ui,
      "uiengine": vx_ui_ui.e_uiengine,
      "uilist": vx_ui_ui.e_uilist,
      "uimap": vx_ui_ui.e_uimap,
      "boolean-print": vx_ui_ui.e_boolean_print,
      "boolean-writestate<-ui": vx_ui_ui.e_boolean_writestate_from_ui,
      "boolean-writestate<-uiengine": vx_ui_ui.e_boolean_writestate_from_uiengine,
      "fontfacemap<-fontfacelist": vx_ui_ui.e_fontfacemap_from_fontfacelist,
      "int-selected<-ui": vx_ui_ui.e_int_selected_from_ui,
      "layout<-style": vx_ui_ui.e_layout_from_style,
      "layout<-ui": vx_ui_ui.e_layout_from_ui,
      "layout<-ui-layoutengine": vx_ui_ui.e_layout_from_ui_layoutengine,
      "layout<-ui-layoutmap-else": vx_ui_ui.e_layout_from_ui_layoutmap_else,
      "layoutengine-readstate": vx_ui_ui.e_layoutengine_readstate,
      "layoutmap<-layoutlist": vx_ui_ui.e_layoutmap_from_layoutlist,
      "string-selected<-ui": vx_ui_ui.e_string_selected_from_ui,
      "stringlist-selected<-ui": vx_ui_ui.e_stringlist_selected_from_ui,
      "stringlist<-ui": vx_ui_ui.e_stringlist_from_ui,
      "stylemap<-stylelist": vx_ui_ui.e_stylemap_from_stylelist,
      "stylesheet-readstate": vx_ui_ui.e_stylesheet_readstate,
      "stylesheet-render": vx_ui_ui.e_stylesheet_render,
      "ui-child<-ui-uid": vx_ui_ui.e_ui_child_from_ui_uid,
      "ui-from<-event": vx_ui_ui.e_ui_from_from_event,
      "ui-layout<-ui": vx_ui_ui.e_ui_layout_from_ui,
      "ui-layout<-ui-layoutengine": vx_ui_ui.e_ui_layout_from_ui_layoutengine,
      "ui-layout<-ui-layoutmap-else": vx_ui_ui.e_ui_layout_from_ui_layoutmap_else,
      "ui-layout<-ui-uiengine": vx_ui_ui.e_ui_layout_from_ui_uiengine,
      "ui-readstate<-uid": vx_ui_ui.e_ui_readstate_from_uid,
      "ui-render": vx_ui_ui.e_ui_render,
      "ui-render<-fn-render-ui-orig-parent": vx_ui_ui.e_ui_render_from_fn_render_ui_orig_parent,
      "ui-render<-ui-orig-parent": vx_ui_ui.e_ui_render_from_ui_orig_parent,
      "ui-render<-ui-parent-selected": vx_ui_ui.e_ui_render_from_ui_parent_selected,
      "ui-selected<-ui": vx_ui_ui.e_ui_selected_from_ui,
      "ui-writechild<-ui-child": vx_ui_ui.e_ui_writechild_from_ui_child,
      "ui-writechildmap<-ui-childmap": vx_ui_ui.e_ui_writechildmap_from_ui_childmap,
      "ui<-layout-ui-orig-parent": vx_ui_ui.e_ui_from_layout_ui_orig_parent,
      "ui<-ui-selected": vx_ui_ui.e_ui_from_ui_selected,
      "uid-selected<-ui": vx_ui_ui.e_uid_selected_from_ui,
      "uiengine-readstate": vx_ui_ui.e_uiengine_readstate,
      "uiengine-render": vx_ui_ui.e_uiengine_render,
      "uilist-selected<-ui": vx_ui_ui.e_uilist_selected_from_ui,
      "uilist<-uimap": vx_ui_ui.e_uilist_from_uimap,
      "uimap-layout<-uimap-layoutmap-else": vx_ui_ui.e_uimap_layout_from_uimap_layoutmap_else,
      "uimap-render<-uimap-parent": vx_ui_ui.e_uimap_render_from_uimap_parent,
      "uimap<-uilist": vx_ui_ui.e_uimap_from_uilist,
      "uimap<-uimap-data": vx_ui_ui.e_uimap_from_uimap_data
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "boolean-print": vx_ui_ui.t_boolean_print,
      "boolean-writestate<-ui": vx_ui_ui.t_boolean_writestate_from_ui,
      "boolean-writestate<-uiengine": vx_ui_ui.t_boolean_writestate_from_uiengine,
      "fontfacemap<-fontfacelist": vx_ui_ui.t_fontfacemap_from_fontfacelist,
      "int-selected<-ui": vx_ui_ui.t_int_selected_from_ui,
      "layout<-style": vx_ui_ui.t_layout_from_style,
      "layout<-ui": vx_ui_ui.t_layout_from_ui,
      "layout<-ui-layoutengine": vx_ui_ui.t_layout_from_ui_layoutengine,
      "layout<-ui-layoutmap-else": vx_ui_ui.t_layout_from_ui_layoutmap_else,
      "layoutengine-readstate": vx_ui_ui.t_layoutengine_readstate,
      "layoutmap<-layoutlist": vx_ui_ui.t_layoutmap_from_layoutlist,
      "string-selected<-ui": vx_ui_ui.t_string_selected_from_ui,
      "stringlist-selected<-ui": vx_ui_ui.t_stringlist_selected_from_ui,
      "stringlist<-ui": vx_ui_ui.t_stringlist_from_ui,
      "stylemap<-stylelist": vx_ui_ui.t_stylemap_from_stylelist,
      "stylesheet-readstate": vx_ui_ui.t_stylesheet_readstate,
      "stylesheet-render": vx_ui_ui.t_stylesheet_render,
      "ui-child<-ui-uid": vx_ui_ui.t_ui_child_from_ui_uid,
      "ui-from<-event": vx_ui_ui.t_ui_from_from_event,
      "ui-layout<-ui": vx_ui_ui.t_ui_layout_from_ui,
      "ui-layout<-ui-layoutengine": vx_ui_ui.t_ui_layout_from_ui_layoutengine,
      "ui-layout<-ui-layoutmap-else": vx_ui_ui.t_ui_layout_from_ui_layoutmap_else,
      "ui-layout<-ui-uiengine": vx_ui_ui.t_ui_layout_from_ui_uiengine,
      "ui-readstate<-uid": vx_ui_ui.t_ui_readstate_from_uid,
      "ui-render": vx_ui_ui.t_ui_render,
      "ui-render<-fn-render-ui-orig-parent": vx_ui_ui.t_ui_render_from_fn_render_ui_orig_parent,
      "ui-render<-ui-orig-parent": vx_ui_ui.t_ui_render_from_ui_orig_parent,
      "ui-render<-ui-parent-selected": vx_ui_ui.t_ui_render_from_ui_parent_selected,
      "ui-selected<-ui": vx_ui_ui.t_ui_selected_from_ui,
      "ui-writechild<-ui-child": vx_ui_ui.t_ui_writechild_from_ui_child,
      "ui-writechildmap<-ui-childmap": vx_ui_ui.t_ui_writechildmap_from_ui_childmap,
      "ui<-layout-ui-orig-parent": vx_ui_ui.t_ui_from_layout_ui_orig_parent,
      "ui<-ui-selected": vx_ui_ui.t_ui_from_ui_selected,
      "uid-selected<-ui": vx_ui_ui.t_uid_selected_from_ui,
      "uiengine-readstate": vx_ui_ui.t_uiengine_readstate,
      "uiengine-render": vx_ui_ui.t_uiengine_render,
      "uilist-selected<-ui": vx_ui_ui.t_uilist_selected_from_ui,
      "uilist<-uimap": vx_ui_ui.t_uilist_from_uimap,
      "uimap-layout<-uimap-layoutmap-else": vx_ui_ui.t_uimap_layout_from_uimap_layoutmap_else,
      "uimap-render<-uimap-parent": vx_ui_ui.t_uimap_render_from_uimap_parent,
      "uimap<-uilist": vx_ui_ui.t_uimap_from_uilist,
      "uimap<-uimap-data": vx_ui_ui.t_uimap_from_uimap_data
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      "align": vx_ui_ui.t_align,
      "bounds": vx_ui_ui.t_bounds,
      "cursor": vx_ui_ui.t_cursor,
      "cursor-pointer": vx_ui_ui.t_cursor_pointer,
      "font": vx_ui_ui.t_font,
      "fontface": vx_ui_ui.t_fontface,
      "fontfacelist": vx_ui_ui.t_fontfacelist,
      "fontfacemap": vx_ui_ui.t_fontfacemap,
      "fontmap": vx_ui_ui.t_fontmap,
      "fontstyle": vx_ui_ui.t_fontstyle,
      "fontstylemap": vx_ui_ui.t_fontstylemap,
      "image": vx_ui_ui.t_image,
      "layout": vx_ui_ui.t_layout,
      "layoutengine": vx_ui_ui.t_layoutengine,
      "layoutlist": vx_ui_ui.t_layoutlist,
      "layoutmap": vx_ui_ui.t_layoutmap,
      "pin": vx_ui_ui.t_pin,
      "point": vx_ui_ui.t_point,
      "pointtype": vx_ui_ui.t_pointtype,
      "style": vx_ui_ui.t_style,
      "stylelist": vx_ui_ui.t_stylelist,
      "stylemap": vx_ui_ui.t_stylemap,
      "stylesheet": vx_ui_ui.t_stylesheet,
      "styletype": vx_ui_ui.t_styletype,
      "ui": vx_ui_ui.t_ui,
      "uiengine": vx_ui_ui.t_uiengine,
      "uilist": vx_ui_ui.t_uilist,
      "uimap": vx_ui_ui.t_uimap
    })
    const pkg = vx_core.vx_new_struct(vx_core.t_package, {
      "name": "vx/ui/ui",
      "constmap": constmap,
      "emptymap": emptymap,
      "funcmap": funcmap,
      "typemap": typemap
    })
    vx_core.vx_global_package_set(pkg)

    // (type align)
    vx_ui_ui.t_align['vx_type'] = vx_core.t_type
    vx_ui_ui.t_align['vx_value'] = {
      name          : "align",
      pkgname       : "vx/ui/ui",
      extends       : ":struct",
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
    vx_ui_ui.e_align['vx_type'] = vx_ui_ui.t_align
    vx_ui_ui.e_align['vx_value'] = {}

    // (type bounds)
    vx_ui_ui.t_bounds['vx_type'] = vx_core.t_type
    vx_ui_ui.t_bounds['vx_value'] = {
      name          : "bounds",
      pkgname       : "vx/ui/ui",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "left": {
          "name" : "left",
          "type" : vx_core.t_int,
          "multi": false
        },
        "right": {
          "name" : "right",
          "type" : vx_core.t_int,
          "multi": false
        },
        "top": {
          "name" : "top",
          "type" : vx_core.t_int,
          "multi": false
        },
        "bottom": {
          "name" : "bottom",
          "type" : vx_core.t_int,
          "multi": false
        }
      },
      proplast      : {
        "name" : "bottom",
        "type" : vx_core.t_int,
        "multi": false
      }
    }
    vx_ui_ui.e_bounds['vx_type'] = vx_ui_ui.t_bounds
    vx_ui_ui.e_bounds['vx_value'] = {}

    // (type cursor)
    vx_ui_ui.t_cursor['vx_type'] = vx_core.t_type
    vx_ui_ui.t_cursor['vx_value'] = {
      name          : "cursor",
      pkgname       : "vx/ui/ui",
      extends       : ":struct",
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
    vx_ui_ui.e_cursor['vx_type'] = vx_ui_ui.t_cursor
    vx_ui_ui.e_cursor['vx_value'] = {}

    // (type cursor-pointer)
    vx_ui_ui.t_cursor_pointer['vx_type'] = vx_core.t_type
    vx_ui_ui.t_cursor_pointer['vx_value'] = {
      name          : "cursor-pointer",
      pkgname       : "vx/ui/ui",
      extends       : ":cursor",
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
    vx_ui_ui.e_cursor_pointer['vx_type'] = vx_ui_ui.t_cursor_pointer
    vx_ui_ui.e_cursor_pointer['vx_value'] = {}

    // (type font)
    vx_ui_ui.t_font['vx_type'] = vx_core.t_type
    vx_ui_ui.t_font['vx_value'] = {
      name          : "font",
      pkgname       : "vx/ui/ui",
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
        "fontface": {
          "name" : "fontface",
          "type" : vx_ui_ui.t_fontface,
          "multi": false
        },
        "fontsize": {
          "name" : "fontsize",
          "type" : vx_core.t_int,
          "multi": false
        },
        "fontstyle": {
          "name" : "fontstyle",
          "type" : vx_ui_ui.t_fontstyle,
          "multi": false
        }
      },
      proplast      : {
        "name" : "fontstyle",
        "type" : vx_ui_ui.t_fontstyle,
        "multi": false
      }
    }
    vx_ui_ui.e_font['vx_type'] = vx_ui_ui.t_font
    vx_ui_ui.e_font['vx_value'] = {}

    // (type fontface)
    vx_ui_ui.t_fontface['vx_type'] = vx_core.t_type
    vx_ui_ui.t_fontface['vx_value'] = {
      name          : "fontface",
      pkgname       : "vx/ui/ui",
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
        "weight": {
          "name" : "weight",
          "type" : vx_core.t_string,
          "multi": false
        },
        "unicode": {
          "name" : "unicode",
          "type" : vx_core.t_string,
          "multi": false
        },
        "filelist": {
          "name" : "filelist",
          "type" : vx_data_file.t_filelist,
          "multi": false
        }
      },
      proplast      : {
        "name" : "filelist",
        "type" : vx_data_file.t_filelist,
        "multi": false
      }
    }
    vx_ui_ui.e_fontface['vx_type'] = vx_ui_ui.t_fontface
    vx_ui_ui.e_fontface['vx_value'] = {}

    // (type fontfacelist)
    vx_ui_ui.t_fontfacelist['vx_type'] = vx_core.t_type
    vx_ui_ui.t_fontfacelist['vx_value'] = {
      name          : "fontfacelist",
      pkgname       : "vx/ui/ui",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_ui_ui.t_fontface],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_ui_ui.e_fontfacelist['vx_type'] = vx_ui_ui.t_fontfacelist

    // (type fontfacemap)
    vx_ui_ui.t_fontfacemap['vx_type'] = vx_core.t_type
    vx_ui_ui.t_fontfacemap['vx_value'] = {
      name          : "fontfacemap",
      pkgname       : "vx/ui/ui",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_ui_ui.t_fontface],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_ui_ui.e_fontfacemap['vx_type'] = vx_ui_ui.t_fontfacemap
    vx_ui_ui.e_fontfacemap['vx_value'] = {}

    // (type fontmap)
    vx_ui_ui.t_fontmap['vx_type'] = vx_core.t_type
    vx_ui_ui.t_fontmap['vx_value'] = {
      name          : "fontmap",
      pkgname       : "vx/ui/ui",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_ui_ui.t_font],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_ui_ui.e_fontmap['vx_type'] = vx_ui_ui.t_fontmap
    vx_ui_ui.e_fontmap['vx_value'] = {}

    // (type fontstyle)
    vx_ui_ui.t_fontstyle['vx_type'] = vx_core.t_type
    vx_ui_ui.t_fontstyle['vx_value'] = {
      name          : "fontstyle",
      pkgname       : "vx/ui/ui",
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
        }
      },
      proplast      : {
        "name" : "name",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    vx_ui_ui.e_fontstyle['vx_type'] = vx_ui_ui.t_fontstyle
    vx_ui_ui.e_fontstyle['vx_value'] = {}

    // (type fontstylemap)
    vx_ui_ui.t_fontstylemap['vx_type'] = vx_core.t_type
    vx_ui_ui.t_fontstylemap['vx_value'] = {
      name          : "fontstylemap",
      pkgname       : "vx/ui/ui",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_ui_ui.t_fontstyle],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_ui_ui.e_fontstylemap['vx_type'] = vx_ui_ui.t_fontstylemap
    vx_ui_ui.e_fontstylemap['vx_value'] = {}

    // (type image)
    vx_ui_ui.t_image['vx_type'] = vx_core.t_type
    vx_ui_ui.t_image['vx_value'] = {
      name          : "image",
      pkgname       : "vx/ui/ui",
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
        "label": {
          "name" : "label",
          "type" : vx_core.t_string,
          "multi": false
        },
        "file": {
          "name" : "file",
          "type" : vx_data_file.t_file,
          "multi": false
        }
      },
      proplast      : {
        "name" : "file",
        "type" : vx_data_file.t_file,
        "multi": false
      }
    }
    vx_ui_ui.e_image['vx_type'] = vx_ui_ui.t_image
    vx_ui_ui.e_image['vx_value'] = {}

    // (type layout)
    vx_ui_ui.t_layout['vx_type'] = vx_core.t_type
    vx_ui_ui.t_layout['vx_value'] = {
      name          : "layout",
      pkgname       : "vx/ui/ui",
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
        "fn-layout": {
          "name" : "fn-layout",
          "type" : vx_ui_ui.t_ui_render_from_ui_orig_parent,
          "multi": false
        }
      },
      proplast      : {
        "name" : "fn-layout",
        "type" : vx_ui_ui.t_ui_render_from_ui_orig_parent,
        "multi": false
      }
    }
    vx_ui_ui.e_layout['vx_type'] = vx_ui_ui.t_layout
    vx_ui_ui.e_layout['vx_value'] = {}

    // (type layoutengine)
    vx_ui_ui.t_layoutengine['vx_type'] = vx_core.t_type
    vx_ui_ui.t_layoutengine['vx_value'] = {
      name          : "layoutengine",
      pkgname       : "vx/ui/ui",
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
        "boolean-print": {
          "name" : "boolean-print",
          "type" : vx_ui_ui.t_boolean_print,
          "multi": false
        },
        "layoutmap": {
          "name" : "layoutmap",
          "type" : vx_ui_ui.t_layoutmap,
          "multi": false
        },
        "layoutelse": {
          "name" : "layoutelse",
          "type" : vx_ui_ui.t_layout,
          "multi": false
        },
        "stylesheetrender": {
          "name" : "stylesheetrender",
          "type" : vx_ui_ui.t_stylesheet_render,
          "multi": false
        }
      },
      proplast      : {
        "name" : "stylesheetrender",
        "type" : vx_ui_ui.t_stylesheet_render,
        "multi": false
      }
    }
    vx_ui_ui.e_layoutengine['vx_type'] = vx_ui_ui.t_layoutengine
    vx_ui_ui.e_layoutengine['vx_value'] = {}

    // (type layoutlist)
    vx_ui_ui.t_layoutlist['vx_type'] = vx_core.t_type
    vx_ui_ui.t_layoutlist['vx_value'] = {
      name          : "layoutlist",
      pkgname       : "vx/ui/ui",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_ui_ui.t_layout],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_ui_ui.e_layoutlist['vx_type'] = vx_ui_ui.t_layoutlist

    // (type layoutmap)
    vx_ui_ui.t_layoutmap['vx_type'] = vx_core.t_type
    vx_ui_ui.t_layoutmap['vx_value'] = {
      name          : "layoutmap",
      pkgname       : "vx/ui/ui",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_ui_ui.t_layout],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_ui_ui.e_layoutmap['vx_type'] = vx_ui_ui.t_layoutmap
    vx_ui_ui.e_layoutmap['vx_value'] = {}

    // (type pin)
    vx_ui_ui.t_pin['vx_type'] = vx_core.t_type
    vx_ui_ui.t_pin['vx_value'] = {
      name          : "pin",
      pkgname       : "vx/ui/ui",
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
        }
      },
      proplast      : {
        "name" : "name",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    vx_ui_ui.e_pin['vx_type'] = vx_ui_ui.t_pin
    vx_ui_ui.e_pin['vx_value'] = {}

    // (type point)
    vx_ui_ui.t_point['vx_type'] = vx_core.t_type
    vx_ui_ui.t_point['vx_value'] = {
      name          : "point",
      pkgname       : "vx/ui/ui",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "x": {
          "name" : "x",
          "type" : vx_core.t_int,
          "multi": false
        },
        "y": {
          "name" : "y",
          "type" : vx_core.t_int,
          "multi": false
        },
        "z": {
          "name" : "z",
          "type" : vx_core.t_int,
          "multi": false
        },
        "t": {
          "name" : "t",
          "type" : vx_core.t_int,
          "multi": false
        },
        "i": {
          "name" : "i",
          "type" : vx_core.t_int,
          "multi": false
        },
        "pointtype": {
          "name" : "pointtype",
          "type" : vx_ui_ui.t_pointtype,
          "multi": false
        }
      },
      proplast      : {
        "name" : "pointtype",
        "type" : vx_ui_ui.t_pointtype,
        "multi": false
      }
    }
    vx_ui_ui.e_point['vx_type'] = vx_ui_ui.t_point
    vx_ui_ui.e_point['vx_value'] = {}

    // (type pointtype)
    vx_ui_ui.t_pointtype['vx_type'] = vx_core.t_type
    vx_ui_ui.t_pointtype['vx_value'] = {
      name          : "pointtype",
      pkgname       : "vx/ui/ui",
      extends       : ":int",
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
    vx_ui_ui.e_pointtype['vx_type'] = vx_ui_ui.t_pointtype
    vx_ui_ui.e_pointtype['vx_value'] = {}

    // (type style)
    vx_ui_ui.t_style['vx_type'] = vx_core.t_type
    vx_ui_ui.t_style['vx_value'] = {
      name          : "style",
      pkgname       : "vx/ui/ui",
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
        "align": {
          "name" : "align",
          "type" : vx_ui_ui.t_align,
          "multi": false
        },
        "boundsmargin": {
          "name" : "boundsmargin",
          "type" : vx_ui_ui.t_bounds,
          "multi": false
        },
        "boundspadding": {
          "name" : "boundspadding",
          "type" : vx_ui_ui.t_bounds,
          "multi": false
        },
        "color-background": {
          "name" : "color-background",
          "type" : vx_core.t_string,
          "multi": false
        },
        "color-border": {
          "name" : "color-border",
          "type" : vx_core.t_string,
          "multi": false
        },
        "color-font": {
          "name" : "color-font",
          "type" : vx_core.t_string,
          "multi": false
        },
        "color-hoverbkgrd": {
          "name" : "color-hoverbkgrd",
          "type" : vx_core.t_string,
          "multi": false
        },
        "cursor": {
          "name" : "cursor",
          "type" : vx_ui_ui.t_cursor,
          "multi": false
        },
        "font": {
          "name" : "font",
          "type" : vx_ui_ui.t_font,
          "multi": false
        },
        "hidden": {
          "name" : "hidden",
          "type" : vx_core.t_boolean,
          "multi": false
        },
        "image-background": {
          "name" : "image-background",
          "type" : vx_ui_ui.t_image,
          "multi": false
        },
        "layout": {
          "name" : "layout",
          "type" : vx_ui_ui.t_layout,
          "multi": false
        },
        "type": {
          "name" : "type",
          "type" : vx_ui_ui.t_styletype,
          "multi": false
        },
        "pin": {
          "name" : "pin",
          "type" : vx_ui_ui.t_pin,
          "multi": false
        },
        "pointpos": {
          "name" : "pointpos",
          "type" : vx_ui_ui.t_point,
          "multi": false
        },
        "pointrotate": {
          "name" : "pointrotate",
          "type" : vx_ui_ui.t_point,
          "multi": false
        },
        "pointsize": {
          "name" : "pointsize",
          "type" : vx_ui_ui.t_point,
          "multi": false
        },
        "scroll-x": {
          "name" : "scroll-x",
          "type" : vx_core.t_boolean,
          "multi": false
        },
        "scroll-y": {
          "name" : "scroll-y",
          "type" : vx_core.t_boolean,
          "multi": false
        }
      },
      proplast      : {
        "name" : "scroll-y",
        "type" : vx_core.t_boolean,
        "multi": false
      }
    }
    vx_ui_ui.e_style['vx_type'] = vx_ui_ui.t_style
    vx_ui_ui.e_style['vx_value'] = {}

    // (type stylelist)
    vx_ui_ui.t_stylelist['vx_type'] = vx_core.t_type
    vx_ui_ui.t_stylelist['vx_value'] = {
      name          : "stylelist",
      pkgname       : "vx/ui/ui",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_ui_ui.t_style],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_ui_ui.e_stylelist['vx_type'] = vx_ui_ui.t_stylelist

    // (type stylemap)
    vx_ui_ui.t_stylemap['vx_type'] = vx_core.t_type
    vx_ui_ui.t_stylemap['vx_value'] = {
      name          : "stylemap",
      pkgname       : "vx/ui/ui",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_ui_ui.t_style],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_ui_ui.e_stylemap['vx_type'] = vx_ui_ui.t_stylemap
    vx_ui_ui.e_stylemap['vx_value'] = {}

    // (type stylesheet)
    vx_ui_ui.t_stylesheet['vx_type'] = vx_core.t_type
    vx_ui_ui.t_stylesheet['vx_value'] = {
      name          : "stylesheet",
      pkgname       : "vx/ui/ui",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "fontfacemap": {
          "name" : "fontfacemap",
          "type" : vx_ui_ui.t_fontfacemap,
          "multi": false
        },
        "stylemap": {
          "name" : "stylemap",
          "type" : vx_ui_ui.t_stylemap,
          "multi": false
        }
      },
      proplast      : {
        "name" : "stylemap",
        "type" : vx_ui_ui.t_stylemap,
        "multi": false
      }
    }
    vx_ui_ui.e_stylesheet['vx_type'] = vx_ui_ui.t_stylesheet
    vx_ui_ui.e_stylesheet['vx_value'] = {}

    // (type styletype)
    vx_ui_ui.t_styletype['vx_type'] = vx_core.t_type
    vx_ui_ui.t_styletype['vx_value'] = {
      name          : "styletype",
      pkgname       : "vx/ui/ui",
      extends       : ":struct",
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
    vx_ui_ui.e_styletype['vx_type'] = vx_ui_ui.t_styletype
    vx_ui_ui.e_styletype['vx_value'] = {}

    // (type ui)
    vx_ui_ui.t_ui['vx_type'] = vx_core.t_type
    vx_ui_ui.t_ui['vx_value'] = {
      name          : "ui",
      pkgname       : "vx/ui/ui",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "uid": {
          "name" : "uid",
          "type" : vx_core.t_string,
          "multi": false
        },
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "layout": {
          "name" : "layout",
          "type" : vx_ui_ui.t_layout,
          "multi": false
        },
        "parent": {
          "name" : "parent",
          "type" : vx_core.t_string,
          "multi": false
        },
        "path": {
          "name" : "path",
          "type" : vx_core.t_string,
          "multi": false
        },
        "hidden": {
          "name" : "hidden",
          "type" : vx_core.t_boolean,
          "multi": false
        },
        "selected": {
          "name" : "selected",
          "type" : vx_core.t_boolean,
          "multi": false
        },
        "selectmulti": {
          "name" : "selectmulti",
          "type" : vx_core.t_boolean,
          "multi": false
        },
        "style": {
          "name" : "style",
          "type" : vx_ui_ui.t_style,
          "multi": false
        },
        "stylelist": {
          "name" : "stylelist",
          "type" : vx_ui_ui.t_stylelist,
          "multi": false
        },
        "eventmap": {
          "name" : "eventmap",
          "type" : vx_event.t_eventmap,
          "multi": false
        },
        "data": {
          "name" : "data",
          "type" : vx_core.t_any,
          "multi": false
        },
        "uimap": {
          "name" : "uimap",
          "type" : vx_ui_ui.t_uimap,
          "multi": false
        }
      },
      proplast      : {
        "name" : "uimap",
        "type" : vx_ui_ui.t_uimap,
        "multi": false
      }
    }
    vx_ui_ui.e_ui['vx_type'] = vx_ui_ui.t_ui
    vx_ui_ui.e_ui['vx_value'] = {}

    // (type uiengine)
    vx_ui_ui.t_uiengine['vx_type'] = vx_core.t_type
    vx_ui_ui.t_uiengine['vx_value'] = {
      name          : "uiengine",
      pkgname       : "vx/ui/ui",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "parentmap": {
          "name" : "parentmap",
          "type" : vx_ui_ui.t_uimap,
          "multi": false
        },
        "layoutengine": {
          "name" : "layoutengine",
          "type" : vx_ui_ui.t_layoutengine,
          "multi": false
        },
        "stylesheet": {
          "name" : "stylesheet",
          "type" : vx_ui_ui.t_stylesheet,
          "multi": false
        },
        "ui": {
          "name" : "ui",
          "type" : vx_ui_ui.t_ui,
          "multi": false
        }
      },
      proplast      : {
        "name" : "ui",
        "type" : vx_ui_ui.t_ui,
        "multi": false
      }
    }
    vx_ui_ui.e_uiengine['vx_type'] = vx_ui_ui.t_uiengine
    vx_ui_ui.e_uiengine['vx_value'] = {}

    // (type uilist)
    vx_ui_ui.t_uilist['vx_type'] = vx_core.t_type
    vx_ui_ui.t_uilist['vx_value'] = {
      name          : "uilist",
      pkgname       : "vx/ui/ui",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_ui_ui.t_ui],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_ui_ui.e_uilist['vx_type'] = vx_ui_ui.t_uilist

    // (type uimap)
    vx_ui_ui.t_uimap['vx_type'] = vx_core.t_type
    vx_ui_ui.t_uimap['vx_value'] = {
      name          : "uimap",
      pkgname       : "vx/ui/ui",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_ui_ui.t_ui],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_ui_ui.e_uimap['vx_type'] = vx_ui_ui.t_uimap
    vx_ui_ui.e_uimap['vx_value'] = {}

    // (func boolean-print)
    vx_ui_ui.t_boolean_print['vx_value'] = {
      name          : "boolean-print",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_boolean_print
    }

    // (func boolean-writestate<-ui)
    vx_ui_ui.t_boolean_writestate_from_ui['vx_value'] = {
      name          : "boolean-writestate<-ui",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_boolean_writestate_from_ui
    }

    // (func boolean-writestate<-uiengine)
    vx_ui_ui.t_boolean_writestate_from_uiengine['vx_value'] = {
      name          : "boolean-writestate<-uiengine",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_boolean_writestate_from_uiengine
    }

    // (func fontfacemap<-fontfacelist)
    vx_ui_ui.t_fontfacemap_from_fontfacelist['vx_value'] = {
      name          : "fontfacemap<-fontfacelist",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_fontfacemap_from_fontfacelist
    }

    // (func int-selected<-ui)
    vx_ui_ui.t_int_selected_from_ui['vx_value'] = {
      name          : "int-selected<-ui",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_int_selected_from_ui
    }

    // (func layout<-style)
    vx_ui_ui.t_layout_from_style['vx_value'] = {
      name          : "layout<-style",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_layout_from_style
    }

    // (func layout<-ui)
    vx_ui_ui.t_layout_from_ui['vx_value'] = {
      name          : "layout<-ui",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_layout_from_ui
    }

    // (func layout<-ui-layoutengine)
    vx_ui_ui.t_layout_from_ui_layoutengine['vx_value'] = {
      name          : "layout<-ui-layoutengine",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_layout_from_ui_layoutengine
    }

    // (func layout<-ui-layoutmap-else)
    vx_ui_ui.t_layout_from_ui_layoutmap_else['vx_value'] = {
      name          : "layout<-ui-layoutmap-else",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_layout_from_ui_layoutmap_else
    }

    // (func layoutengine-readstate)
    vx_ui_ui.t_layoutengine_readstate['vx_value'] = {
      name          : "layoutengine-readstate",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_layoutengine_readstate
    }

    // (func layoutmap<-layoutlist)
    vx_ui_ui.t_layoutmap_from_layoutlist['vx_value'] = {
      name          : "layoutmap<-layoutlist",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_layoutmap_from_layoutlist
    }

    // (func string-selected<-ui)
    vx_ui_ui.t_string_selected_from_ui['vx_value'] = {
      name          : "string-selected<-ui",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_string_selected_from_ui
    }

    // (func stringlist-selected<-ui)
    vx_ui_ui.t_stringlist_selected_from_ui['vx_value'] = {
      name          : "stringlist-selected<-ui",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_stringlist_selected_from_ui
    }

    // (func stringlist<-ui)
    vx_ui_ui.t_stringlist_from_ui['vx_value'] = {
      name          : "stringlist<-ui",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_stringlist_from_ui
    }

    // (func stylemap<-stylelist)
    vx_ui_ui.t_stylemap_from_stylelist['vx_value'] = {
      name          : "stylemap<-stylelist",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_stylemap_from_stylelist
    }

    // (func stylesheet-readstate)
    vx_ui_ui.t_stylesheet_readstate['vx_value'] = {
      name          : "stylesheet-readstate",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_stylesheet_readstate
    }

    // (func stylesheet-render)
    vx_ui_ui.t_stylesheet_render['vx_value'] = {
      name          : "stylesheet-render",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_stylesheet_render
    }

    // (func ui-child<-ui-uid)
    vx_ui_ui.t_ui_child_from_ui_uid['vx_value'] = {
      name          : "ui-child<-ui-uid",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_ui_child_from_ui_uid
    }

    // (func ui-from<-event)
    vx_ui_ui.t_ui_from_from_event['vx_value'] = {
      name          : "ui-from<-event",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_ui_from_from_event
    }

    // (func ui-layout<-ui)
    vx_ui_ui.t_ui_layout_from_ui['vx_value'] = {
      name          : "ui-layout<-ui",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_ui_layout_from_ui
    }

    // (func ui-layout<-ui-layoutengine)
    vx_ui_ui.t_ui_layout_from_ui_layoutengine['vx_value'] = {
      name          : "ui-layout<-ui-layoutengine",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_ui_layout_from_ui_layoutengine
    }

    // (func ui-layout<-ui-layoutmap-else)
    vx_ui_ui.t_ui_layout_from_ui_layoutmap_else['vx_value'] = {
      name          : "ui-layout<-ui-layoutmap-else",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_ui_layout_from_ui_layoutmap_else
    }

    // (func ui-layout<-ui-uiengine)
    vx_ui_ui.t_ui_layout_from_ui_uiengine['vx_value'] = {
      name          : "ui-layout<-ui-uiengine",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_ui_layout_from_ui_uiengine
    }

    // (func ui-readstate<-uid)
    vx_ui_ui.t_ui_readstate_from_uid['vx_value'] = {
      name          : "ui-readstate<-uid",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_ui_readstate_from_uid
    }

    // (func ui-render)
    vx_ui_ui.t_ui_render['vx_value'] = {
      name          : "ui-render",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_ui_render
    }

    // (func ui-render<-fn-render-ui-orig-parent)
    vx_ui_ui.t_ui_render_from_fn_render_ui_orig_parent['vx_value'] = {
      name          : "ui-render<-fn-render-ui-orig-parent",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_ui_render_from_fn_render_ui_orig_parent
    }

    // (func ui-render<-ui-orig-parent)
    vx_ui_ui.t_ui_render_from_ui_orig_parent['vx_value'] = {
      name          : "ui-render<-ui-orig-parent",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_ui_render_from_ui_orig_parent
    }

    // (func ui-render<-ui-parent-selected)
    vx_ui_ui.t_ui_render_from_ui_parent_selected['vx_value'] = {
      name          : "ui-render<-ui-parent-selected",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_ui_render_from_ui_parent_selected
    }

    // (func ui-selected<-ui)
    vx_ui_ui.t_ui_selected_from_ui['vx_value'] = {
      name          : "ui-selected<-ui",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_ui_selected_from_ui
    }

    // (func ui-writechild<-ui-child)
    vx_ui_ui.t_ui_writechild_from_ui_child['vx_value'] = {
      name          : "ui-writechild<-ui-child",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_ui_writechild_from_ui_child
    }

    // (func ui-writechildmap<-ui-childmap)
    vx_ui_ui.t_ui_writechildmap_from_ui_childmap['vx_value'] = {
      name          : "ui-writechildmap<-ui-childmap",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_ui_writechildmap_from_ui_childmap
    }

    // (func ui<-layout-ui-orig-parent)
    vx_ui_ui.t_ui_from_layout_ui_orig_parent['vx_value'] = {
      name          : "ui<-layout-ui-orig-parent",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_ui_from_layout_ui_orig_parent
    }

    // (func ui<-ui-selected)
    vx_ui_ui.t_ui_from_ui_selected['vx_value'] = {
      name          : "ui<-ui-selected",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_ui_from_ui_selected
    }

    // (func uid-selected<-ui)
    vx_ui_ui.t_uid_selected_from_ui['vx_value'] = {
      name          : "uid-selected<-ui",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_uid_selected_from_ui
    }

    // (func uiengine-readstate)
    vx_ui_ui.t_uiengine_readstate['vx_value'] = {
      name          : "uiengine-readstate",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_uiengine_readstate
    }

    // (func uiengine-render)
    vx_ui_ui.t_uiengine_render['vx_value'] = {
      name          : "uiengine-render",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_uiengine_render
    }

    // (func uilist-selected<-ui)
    vx_ui_ui.t_uilist_selected_from_ui['vx_value'] = {
      name          : "uilist-selected<-ui",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_uilist_selected_from_ui
    }

    // (func uilist<-uimap)
    vx_ui_ui.t_uilist_from_uimap['vx_value'] = {
      name          : "uilist<-uimap",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_uilist_from_uimap
    }

    // (func uimap-layout<-uimap-layoutmap-else)
    vx_ui_ui.t_uimap_layout_from_uimap_layoutmap_else['vx_value'] = {
      name          : "uimap-layout<-uimap-layoutmap-else",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_uimap_layout_from_uimap_layoutmap_else
    }

    // (func uimap-render<-uimap-parent)
    vx_ui_ui.t_uimap_render_from_uimap_parent['vx_value'] = {
      name          : "uimap-render<-uimap-parent",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_uimap_render_from_uimap_parent
    }

    // (func uimap<-uilist)
    vx_ui_ui.t_uimap_from_uilist['vx_value'] = {
      name          : "uimap<-uilist",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_uimap_from_uilist
    }

    // (func uimap<-uimap-data)
    vx_ui_ui.t_uimap_from_uimap_data['vx_value'] = {
      name          : "uimap<-uimap-data",
      pkgname       : "vx/ui/ui",
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
      fn            : vx_ui_ui.f_uimap_from_uimap_data
    }

    // (const layout-app)
    Object.assign(vx_ui_ui.c_layout_app, vx_core.f_new(
      vx_ui_ui.t_layout,
      ":name",
      "layout-app"
    ))

    // (const layout-background)
    Object.assign(vx_ui_ui.c_layout_background, vx_core.f_new(
      vx_ui_ui.t_layout,
      ":name",
      "layout-background"
    ))

    // (const layout-button)
    Object.assign(vx_ui_ui.c_layout_button, vx_core.f_new(
      vx_ui_ui.t_layout,
      ":name",
      "layout-button"
    ))

    // (const layout-combobox)
    Object.assign(vx_ui_ui.c_layout_combobox, vx_core.f_new(
      vx_ui_ui.t_layout,
      ":name",
      "layout-combobox"
    ))

    // (const layout-else)
    Object.assign(vx_ui_ui.c_layout_else, vx_core.f_new(
      vx_ui_ui.t_layout,
      ":name",
      "layout-else"
    ))

    // (const layout-flow-columns)
    Object.assign(vx_ui_ui.c_layout_flow_columns, vx_core.f_new(
      vx_ui_ui.t_layout,
      ":name",
      "layout-flow-columns"
    ))

    // (const layout-flow-item)
    Object.assign(vx_ui_ui.c_layout_flow_item, vx_core.f_new(
      vx_ui_ui.t_layout,
      ":name",
      "layout-flow-item"
    ))

    // (const layout-flow-rows)
    Object.assign(vx_ui_ui.c_layout_flow_rows, vx_core.f_new(
      vx_ui_ui.t_layout,
      ":name",
      "layout-flow-rows"
    ))

    // (const layout-image)
    Object.assign(vx_ui_ui.c_layout_image, vx_core.f_new(
      vx_ui_ui.t_layout,
      ":name",
      "layout-image"
    ))

    // (const layout-label)
    Object.assign(vx_ui_ui.c_layout_label, vx_core.f_new(
      vx_ui_ui.t_layout,
      ":name",
      "layout-label"
    ))

    // (const layout-main)
    Object.assign(vx_ui_ui.c_layout_main, vx_core.f_new(
      vx_ui_ui.t_layout,
      ":name",
      "layout-main"
    ))

    // (const layout-maxpanel)
    Object.assign(vx_ui_ui.c_layout_maxpanel, vx_core.f_new(
      vx_ui_ui.t_layout,
      ":name",
      "layout-maxpanel"
    ))

    // (const layout-menubar)
    Object.assign(vx_ui_ui.c_layout_menubar, vx_core.f_new(
      vx_ui_ui.t_layout,
      ":name",
      "layout-menubar"
    ))

    // (const layout-menudrawer)
    Object.assign(vx_ui_ui.c_layout_menudrawer, vx_core.f_new(
      vx_ui_ui.t_layout,
      ":name",
      "layout-menudrawer"
    ))

    // (const layout-msgbox)
    Object.assign(vx_ui_ui.c_layout_msgbox, vx_core.f_new(
      vx_ui_ui.t_layout,
      ":name",
      "layout-msgbox"
    ))

    // (const layout-navbar)
    Object.assign(vx_ui_ui.c_layout_navbar, vx_core.f_new(
      vx_ui_ui.t_layout,
      ":name",
      "layout-navbar"
    ))

    // (const layout-navdrawer)
    Object.assign(vx_ui_ui.c_layout_navdrawer, vx_core.f_new(
      vx_ui_ui.t_layout,
      ":name",
      "layout-navdrawer"
    ))

    // (const layout-panel)
    Object.assign(vx_ui_ui.c_layout_panel, vx_core.f_new(
      vx_ui_ui.t_layout,
      ":name",
      "layout-panel"
    ))

    // (const layout-parallax)
    Object.assign(vx_ui_ui.c_layout_parallax, vx_core.f_new(
      vx_ui_ui.t_layout,
      ":name",
      "layout-parallax"
    ))

    // (const layout-statusbar)
    Object.assign(vx_ui_ui.c_layout_statusbar, vx_core.f_new(
      vx_ui_ui.t_layout,
      ":name",
      "layout-statusbar"
    ))

    // (const layout-statusdrawer)
    Object.assign(vx_ui_ui.c_layout_statusdrawer, vx_core.f_new(
      vx_ui_ui.t_layout,
      ":name",
      "layout-statusdrawer"
    ))

    // (const layout-text)
    Object.assign(vx_ui_ui.c_layout_text, vx_core.f_new(
      vx_ui_ui.t_layout,
      ":name",
      "layout-text"
    ))

    // (const layout-textentry)
    Object.assign(vx_ui_ui.c_layout_textentry, vx_core.f_new(
      vx_ui_ui.t_layout,
      ":name",
      "layout-textentry"
    ))

    // (const layout-titlebar)
    Object.assign(vx_ui_ui.c_layout_titlebar, vx_core.f_new(
      vx_ui_ui.t_layout,
      ":name",
      "layout-titlebar"
    ))

    // (const pin-bottom)
    Object.assign(vx_ui_ui.c_pin_bottom, {
      
    })

    // (const pin-center)
    Object.assign(vx_ui_ui.c_pin_center, {
      
    })

    // (const pin-center-h)
    Object.assign(vx_ui_ui.c_pin_center_h, {
      
    })

    // (const pin-center-v)
    Object.assign(vx_ui_ui.c_pin_center_v, {
      
    })

    // (const pin-expand)
    Object.assign(vx_ui_ui.c_pin_expand, {
      
    })

    // (const pin-left)
    Object.assign(vx_ui_ui.c_pin_left, {
      
    })

    // (const pin-right)
    Object.assign(vx_ui_ui.c_pin_right, {
      
    })

    // (const pin-top)
    Object.assign(vx_ui_ui.c_pin_top, {
      
    })

  }
}
