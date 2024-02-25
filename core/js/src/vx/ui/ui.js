'strict mode'

import vx_core from "../../vx/core.js"
import vx_event from "../../vx/event.js"
import vx_data_file from "../../vx/data/file.js"


export default class vx_ui_ui {


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
   * type: pointstyle
   * Universal Point Style
   */
  static t_pointstyle = {}
  static e_pointstyle = {vx_type: vx_ui_ui.t_pointstyle}

  /**
   * type: render
   * Universal Rendered UI
   */
  static t_render = {}
  static e_render = {vx_type: vx_ui_ui.t_render}

  /**
   * type: rendermap
   * Map of render
   */
  static t_rendermap = {}
  static e_rendermap = {vx_type: vx_ui_ui.t_rendermap}

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
   * @function layoutmap_from_layoutlist
   * Returns an renderermap from an rendererlist
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
   * @function ui_layout_from_ui_layoutmap_else
   * Returns a ui with a renderer added to each ui.
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
        const style = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_style, "struct-2": vx_ui_ui.t_ui}, ui, ":style")
        const uimap = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_uimap, "struct-2": vx_ui_ui.t_ui}, ui, ":uimap")
        const layout = vx_ui_ui.f_layout_from_style(style)
        const layname = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_ui_ui.t_layout}, layout, ":name")
        const renderer1 = vx_core.f_any_from_map({"any-1": vx_ui_ui.t_layout, "map-1": vx_ui_ui.t_layoutmap}, layoutmap, layname)
        const renderer = vx_core.f_if_1(
          {"any-1": vx_ui_ui.t_layout},
          vx_core.f_notempty_1(renderer1),
          renderer1,
          layoutelse
        )
        const uimaprend = vx_ui_ui.f_uimap_layout_from_uimap_layoutmap_else(uimap, layoutmap, layoutelse)
        return vx_core.f_copy(ui, ":renderer", renderer, ":uimap", uimaprend)
      })
    )
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
   * @param  {ui_render_from_ui_orig_parent} fn_render
   * @param  {ui} ui
   * @param  {ui} orig
   * @param  {ui} parent
   * @return {render}
   */
  static t_ui_render_from_fn_render_ui_orig_parent = {
    vx_type: vx_core.t_type
  }
  static e_ui_render_from_fn_render_ui_orig_parent = {
    vx_type: vx_ui_ui.t_ui_render_from_fn_render_ui_orig_parent
  }

  // (func ui-render<-fn-render-ui-orig-parent)
  static f_ui_render_from_fn_render_ui_orig_parent(fn_render, ui, orig, parent) {
    let output = vx_ui_ui.e_render
    output = vx_core.vx_any_from_func(vx_ui_ui.t_render, fn_render, ui, orig, parent)
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
            const renderer = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_layout, "struct-2": vx_ui_ui.t_ui}, ui, ":renderer")
            const uiout = vx_ui_ui.f_ui_from_renderer_ui_orig_parent(renderer, ui, orig, parent)
            return uiout
          })
        )})
      )
    )
    return output
  }

  /**
   * @function ui_from_renderer_ui_orig_parent
   * @param  {layout} renderer
   * @param  {ui} uiarg
   * @param  {ui} uiorig
   * @param  {ui} parent
   * @return {ui}
   */
  static t_ui_from_renderer_ui_orig_parent = {
    vx_type: vx_core.t_type
  }
  static e_ui_from_renderer_ui_orig_parent = {
    vx_type: vx_ui_ui.t_ui_from_renderer_ui_orig_parent
  }

  // (func ui<-renderer-ui-orig-parent)
  static f_ui_from_renderer_ui_orig_parent(renderer, uiarg, uiorig, parent) {
    let output = vx_ui_ui.e_ui
    output = vx_core.f_let(
      {"any-1": vx_ui_ui.t_ui, "struct-2": vx_ui_ui.t_layout},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const fn_layout = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_ui_render_from_ui_orig_parent, "struct-2": vx_ui_ui.t_layout}, renderer, ":fn-layout")
        const uichg = vx_core.vx_any_from_func(vx_ui_ui.t_ui, fn_layout, uiarg, uiorig, parent)
        return uichg
      })
    )
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
  static f_uiengine_render(uiengine) {
    let output = vx_ui_ui.e_uiengine
    output = vx_core.f_let(
      {"any-1": vx_ui_ui.t_uiengine, "struct-2": vx_ui_ui.t_layoutengine},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const stylesheet = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_stylesheet, "struct-2": vx_ui_ui.t_uiengine}, uiengine, ":stylesheet")
        const ui = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_ui, "struct-2": vx_ui_ui.t_uiengine}, uiengine, ":ui")
        const layoutengine = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_layoutengine, "struct-2": vx_ui_ui.t_uiengine}, uiengine, ":layoutengine")
        const layoutmap = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_layoutmap, "struct-2": vx_ui_ui.t_layoutengine}, layoutengine, ":layoutmap")
        const layoutelse = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_layout, "struct-2": vx_ui_ui.t_layoutengine}, layoutengine, ":layoutelse")
        const stylesheetrender = vx_core.f_any_from_struct({"any-1": vx_ui_ui.t_stylesheet_render, "struct-2": vx_ui_ui.t_layoutengine}, layoutengine, ":stylesheetrender")
        const stylesheetrend = vx_core.vx_any_from_func(vx_ui_ui.t_stylesheet, stylesheetrender, stylesheet)
        const uirenderer = vx_ui_ui.f_ui_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse)
        const uirendered = vx_ui_ui.f_ui_render(uirenderer)
        return vx_core.f_copy(uiengine, ":ui", uirendered)
      })
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
    output = vx_core.f_map_from_map(
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
    output = vx_core.f_map_from_map(
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
   * @param  {uilist} uilist
   * @return {uimap}
   */
  static t_uimap_from_uilist = {
    vx_type: vx_core.t_type
  }
  static e_uimap_from_uilist = {
    vx_type: vx_ui_ui.t_uimap_from_uilist
  }

  // (func uimap<-uilist)
  static f_uimap_from_uilist(uilist) {
    let output = vx_ui_ui.e_uimap
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
      "layout-app": vx_ui_ui.c_layout_app,
      "layout-background": vx_ui_ui.c_layout_background,
      "layout-combobox": vx_ui_ui.c_layout_combobox,
      "layout-else": vx_ui_ui.c_layout_else,
      "layout-flow-columns": vx_ui_ui.c_layout_flow_columns,
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
      "pin-bottom": vx_ui_ui.c_pin_bottom,
      "pin-center": vx_ui_ui.c_pin_center,
      "pin-center-h": vx_ui_ui.c_pin_center_h,
      "pin-center-v": vx_ui_ui.c_pin_center_v,
      "pin-expand": vx_ui_ui.c_pin_expand,
      "pin-left": vx_ui_ui.c_pin_left,
      "pin-right": vx_ui_ui.c_pin_right,
      "pin-top": vx_ui_ui.c_pin_top,
      "styletype-custom": vx_ui_ui.c_styletype_custom,
      "styletype-shared": vx_ui_ui.c_styletype_shared,
      "styletype-system": vx_ui_ui.c_styletype_system
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "bounds": vx_ui_ui.e_bounds,
      "cursor": vx_ui_ui.e_cursor,
      "cursor-pointer": vx_ui_ui.e_cursor_pointer,
      "layout": vx_ui_ui.e_layout,
      "layoutengine": vx_ui_ui.e_layoutengine,
      "layoutlist": vx_ui_ui.e_layoutlist,
      "layoutmap": vx_ui_ui.e_layoutmap,
      "pin": vx_ui_ui.e_pin,
      "point": vx_ui_ui.e_point,
      "pointstyle": vx_ui_ui.e_pointstyle,
      "render": vx_ui_ui.e_render,
      "rendermap": vx_ui_ui.e_rendermap,
      "style": vx_ui_ui.e_style,
      "stylelist": vx_ui_ui.e_stylelist,
      "stylemap": vx_ui_ui.e_stylemap,
      "stylesheet": vx_ui_ui.e_stylesheet,
      "styletype": vx_ui_ui.e_styletype,
      "ui": vx_ui_ui.e_ui,
      "uiengine": vx_ui_ui.e_uiengine,
      "uilist": vx_ui_ui.e_uilist,
      "uimap": vx_ui_ui.e_uimap,
      "layout<-style": vx_ui_ui.e_layout_from_style,
      "layoutmap<-layoutlist": vx_ui_ui.e_layoutmap_from_layoutlist,
      "stylemap<-stylelist": vx_ui_ui.e_stylemap_from_stylelist,
      "stylesheet-render": vx_ui_ui.e_stylesheet_render,
      "ui-layout<-ui-layoutmap-else": vx_ui_ui.e_ui_layout_from_ui_layoutmap_else,
      "ui-render": vx_ui_ui.e_ui_render,
      "ui-render<-fn-render-ui-orig-parent": vx_ui_ui.e_ui_render_from_fn_render_ui_orig_parent,
      "ui-render<-ui-orig-parent": vx_ui_ui.e_ui_render_from_ui_orig_parent,
      "ui<-renderer-ui-orig-parent": vx_ui_ui.e_ui_from_renderer_ui_orig_parent,
      "uiengine-render": vx_ui_ui.e_uiengine_render,
      "uimap-layout<-uimap-layoutmap-else": vx_ui_ui.e_uimap_layout_from_uimap_layoutmap_else,
      "uimap-render<-uimap-parent": vx_ui_ui.e_uimap_render_from_uimap_parent,
      "uimap<-uilist": vx_ui_ui.e_uimap_from_uilist,
      "uimap<-uimap-data": vx_ui_ui.e_uimap_from_uimap_data
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "layout<-style": vx_ui_ui.t_layout_from_style,
      "layoutmap<-layoutlist": vx_ui_ui.t_layoutmap_from_layoutlist,
      "stylemap<-stylelist": vx_ui_ui.t_stylemap_from_stylelist,
      "stylesheet-render": vx_ui_ui.t_stylesheet_render,
      "ui-layout<-ui-layoutmap-else": vx_ui_ui.t_ui_layout_from_ui_layoutmap_else,
      "ui-render": vx_ui_ui.t_ui_render,
      "ui-render<-fn-render-ui-orig-parent": vx_ui_ui.t_ui_render_from_fn_render_ui_orig_parent,
      "ui-render<-ui-orig-parent": vx_ui_ui.t_ui_render_from_ui_orig_parent,
      "ui<-renderer-ui-orig-parent": vx_ui_ui.t_ui_from_renderer_ui_orig_parent,
      "uiengine-render": vx_ui_ui.t_uiengine_render,
      "uimap-layout<-uimap-layoutmap-else": vx_ui_ui.t_uimap_layout_from_uimap_layoutmap_else,
      "uimap-render<-uimap-parent": vx_ui_ui.t_uimap_render_from_uimap_parent,
      "uimap<-uilist": vx_ui_ui.t_uimap_from_uilist,
      "uimap<-uimap-data": vx_ui_ui.t_uimap_from_uimap_data
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      "bounds": vx_ui_ui.t_bounds,
      "cursor": vx_ui_ui.t_cursor,
      "cursor-pointer": vx_ui_ui.t_cursor_pointer,
      "layout": vx_ui_ui.t_layout,
      "layoutengine": vx_ui_ui.t_layoutengine,
      "layoutlist": vx_ui_ui.t_layoutlist,
      "layoutmap": vx_ui_ui.t_layoutmap,
      "pin": vx_ui_ui.t_pin,
      "point": vx_ui_ui.t_point,
      "pointstyle": vx_ui_ui.t_pointstyle,
      "render": vx_ui_ui.t_render,
      "rendermap": vx_ui_ui.t_rendermap,
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
        "ispercent": {
          "name" : "ispercent",
          "type" : vx_core.t_boolean,
          "multi": false
        },
        "pointstyle": {
          "name" : "pointstyle",
          "type" : vx_ui_ui.t_pointstyle,
          "multi": false
        }
      },
      proplast      : {
        "name" : "pointstyle",
        "type" : vx_ui_ui.t_pointstyle,
        "multi": false
      }
    }
    vx_ui_ui.e_point['vx_type'] = vx_ui_ui.t_point
    vx_ui_ui.e_point['vx_value'] = {}

    // (type pointstyle)
    vx_ui_ui.t_pointstyle['vx_type'] = vx_core.t_type
    vx_ui_ui.t_pointstyle['vx_value'] = {
      name          : "pointstyle",
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
    vx_ui_ui.e_pointstyle['vx_type'] = vx_ui_ui.t_pointstyle
    vx_ui_ui.e_pointstyle['vx_value'] = {}

    // (type render)
    vx_ui_ui.t_render['vx_type'] = vx_core.t_type
    vx_ui_ui.t_render['vx_value'] = {
      name          : "render",
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
    vx_ui_ui.e_render['vx_type'] = vx_ui_ui.t_render
    vx_ui_ui.e_render['vx_value'] = {}

    // (type rendermap)
    vx_ui_ui.t_rendermap['vx_type'] = vx_core.t_type
    vx_ui_ui.t_rendermap['vx_value'] = {
      name          : "rendermap",
      pkgname       : "vx/ui/ui",
      extends       : ":map",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_ui_ui.t_render],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_ui_ui.e_rendermap['vx_type'] = vx_ui_ui.t_rendermap
    vx_ui_ui.e_rendermap['vx_value'] = {}

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
        "image-background": {
          "name" : "image-background",
          "type" : vx_data_file.t_file,
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
        "pointsize": {
          "name" : "pointsize",
          "type" : vx_ui_ui.t_point,
          "multi": false
        }
      },
      proplast      : {
        "name" : "pointsize",
        "type" : vx_ui_ui.t_point,
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
        "data": {
          "name" : "data",
          "type" : vx_core.t_any,
          "multi": false
        },
        "eventmap": {
          "name" : "eventmap",
          "type" : vx_event.t_eventmap,
          "multi": false
        },
        "fn-uimap-data": {
          "name" : "fn-uimap-data",
          "type" : vx_ui_ui.t_uimap_from_uimap_data,
          "multi": false
        },
        "path": {
          "name" : "path",
          "type" : vx_core.t_string,
          "multi": false
        },
        "render": {
          "name" : "render",
          "type" : vx_ui_ui.t_render,
          "multi": false
        },
        "renderer": {
          "name" : "renderer",
          "type" : vx_ui_ui.t_layout,
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
        "stylesheet": {
          "name" : "stylesheet",
          "type" : vx_ui_ui.t_stylesheet,
          "multi": false
        },
        "uid": {
          "name" : "uid",
          "type" : vx_core.t_string,
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

    // (func ui<-renderer-ui-orig-parent)
    vx_ui_ui.t_ui_from_renderer_ui_orig_parent['vx_value'] = {
      name          : "ui<-renderer-ui-orig-parent",
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
      fn            : vx_ui_ui.f_ui_from_renderer_ui_orig_parent
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
