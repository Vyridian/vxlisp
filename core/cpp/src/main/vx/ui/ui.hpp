#ifndef VX_UI_UI_HPP
#define VX_UI_UI_HPP
#include <map>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "../../vx/event.hpp"
#include "../../vx/data/file.hpp"

namespace vx_ui_ui {


  // forward declarations
  class Abstract_bounds;
  typedef Abstract_bounds* Type_bounds;
  extern Type_bounds e_bounds;
  extern Type_bounds t_bounds;
  class Abstract_cursor;
  typedef Abstract_cursor* Type_cursor;
  extern Type_cursor e_cursor;
  extern Type_cursor t_cursor;
  class Abstract_cursor_pointer;
  typedef Abstract_cursor_pointer* Type_cursor_pointer;
  extern Type_cursor_pointer e_cursor_pointer;
  extern Type_cursor_pointer t_cursor_pointer;
  class Abstract_layout;
  typedef Abstract_layout* Type_layout;
  extern Type_layout e_layout;
  extern Type_layout t_layout;
  class Abstract_layoutengine;
  typedef Abstract_layoutengine* Type_layoutengine;
  extern Type_layoutengine e_layoutengine;
  extern Type_layoutengine t_layoutengine;
  class Abstract_layoutlist;
  typedef Abstract_layoutlist* Type_layoutlist;
  extern Type_layoutlist e_layoutlist;
  extern Type_layoutlist t_layoutlist;
  class Abstract_layoutmap;
  typedef Abstract_layoutmap* Type_layoutmap;
  extern Type_layoutmap e_layoutmap;
  extern Type_layoutmap t_layoutmap;
  class Abstract_pin;
  typedef Abstract_pin* Type_pin;
  extern Type_pin e_pin;
  extern Type_pin t_pin;
  class Abstract_point;
  typedef Abstract_point* Type_point;
  extern Type_point e_point;
  extern Type_point t_point;
  class Abstract_pointstyle;
  typedef Abstract_pointstyle* Type_pointstyle;
  extern Type_pointstyle e_pointstyle;
  extern Type_pointstyle t_pointstyle;
  class Abstract_render;
  typedef Abstract_render* Type_render;
  extern Type_render e_render;
  extern Type_render t_render;
  class Abstract_rendermap;
  typedef Abstract_rendermap* Type_rendermap;
  extern Type_rendermap e_rendermap;
  extern Type_rendermap t_rendermap;
  class Abstract_style;
  typedef Abstract_style* Type_style;
  extern Type_style e_style;
  extern Type_style t_style;
  class Abstract_stylelist;
  typedef Abstract_stylelist* Type_stylelist;
  extern Type_stylelist e_stylelist;
  extern Type_stylelist t_stylelist;
  class Abstract_stylemap;
  typedef Abstract_stylemap* Type_stylemap;
  extern Type_stylemap e_stylemap;
  extern Type_stylemap t_stylemap;
  class Abstract_stylesheet;
  typedef Abstract_stylesheet* Type_stylesheet;
  extern Type_stylesheet e_stylesheet;
  extern Type_stylesheet t_stylesheet;
  class Abstract_styletype;
  typedef Abstract_styletype* Type_styletype;
  extern Type_styletype e_styletype;
  extern Type_styletype t_styletype;
  class Abstract_ui;
  typedef Abstract_ui* Type_ui;
  extern Type_ui e_ui;
  extern Type_ui t_ui;
  class Abstract_uiengine;
  typedef Abstract_uiengine* Type_uiengine;
  extern Type_uiengine e_uiengine;
  extern Type_uiengine t_uiengine;
  class Abstract_uilist;
  typedef Abstract_uilist* Type_uilist;
  extern Type_uilist e_uilist;
  extern Type_uilist t_uilist;
  class Abstract_uimap;
  typedef Abstract_uimap* Type_uimap;
  extern Type_uimap e_uimap;
  extern Type_uimap t_uimap;
  class Class_layout_app;
  typedef Class_layout_app* Const_layout_app;
  extern Const_layout_app c_layout_app;
  class Class_layout_background;
  typedef Class_layout_background* Const_layout_background;
  extern Const_layout_background c_layout_background;
  class Class_layout_combobox;
  typedef Class_layout_combobox* Const_layout_combobox;
  extern Const_layout_combobox c_layout_combobox;
  class Class_layout_else;
  typedef Class_layout_else* Const_layout_else;
  extern Const_layout_else c_layout_else;
  class Class_layout_flow_columns;
  typedef Class_layout_flow_columns* Const_layout_flow_columns;
  extern Const_layout_flow_columns c_layout_flow_columns;
  class Class_layout_flow_rows;
  typedef Class_layout_flow_rows* Const_layout_flow_rows;
  extern Const_layout_flow_rows c_layout_flow_rows;
  class Class_layout_image;
  typedef Class_layout_image* Const_layout_image;
  extern Const_layout_image c_layout_image;
  class Class_layout_label;
  typedef Class_layout_label* Const_layout_label;
  extern Const_layout_label c_layout_label;
  class Class_layout_main;
  typedef Class_layout_main* Const_layout_main;
  extern Const_layout_main c_layout_main;
  class Class_layout_maxpanel;
  typedef Class_layout_maxpanel* Const_layout_maxpanel;
  extern Const_layout_maxpanel c_layout_maxpanel;
  class Class_layout_menubar;
  typedef Class_layout_menubar* Const_layout_menubar;
  extern Const_layout_menubar c_layout_menubar;
  class Class_layout_menudrawer;
  typedef Class_layout_menudrawer* Const_layout_menudrawer;
  extern Const_layout_menudrawer c_layout_menudrawer;
  class Class_layout_msgbox;
  typedef Class_layout_msgbox* Const_layout_msgbox;
  extern Const_layout_msgbox c_layout_msgbox;
  class Class_layout_navbar;
  typedef Class_layout_navbar* Const_layout_navbar;
  extern Const_layout_navbar c_layout_navbar;
  class Class_layout_navdrawer;
  typedef Class_layout_navdrawer* Const_layout_navdrawer;
  extern Const_layout_navdrawer c_layout_navdrawer;
  class Class_layout_panel;
  typedef Class_layout_panel* Const_layout_panel;
  extern Const_layout_panel c_layout_panel;
  class Class_layout_parallax;
  typedef Class_layout_parallax* Const_layout_parallax;
  extern Const_layout_parallax c_layout_parallax;
  class Class_layout_statusbar;
  typedef Class_layout_statusbar* Const_layout_statusbar;
  extern Const_layout_statusbar c_layout_statusbar;
  class Class_layout_statusdrawer;
  typedef Class_layout_statusdrawer* Const_layout_statusdrawer;
  extern Const_layout_statusdrawer c_layout_statusdrawer;
  class Class_layout_text;
  typedef Class_layout_text* Const_layout_text;
  extern Const_layout_text c_layout_text;
  class Class_layout_textentry;
  typedef Class_layout_textentry* Const_layout_textentry;
  extern Const_layout_textentry c_layout_textentry;
  class Class_pin_bottom;
  typedef Class_pin_bottom* Const_pin_bottom;
  extern Const_pin_bottom c_pin_bottom;
  class Class_pin_center;
  typedef Class_pin_center* Const_pin_center;
  extern Const_pin_center c_pin_center;
  class Class_pin_center_h;
  typedef Class_pin_center_h* Const_pin_center_h;
  extern Const_pin_center_h c_pin_center_h;
  class Class_pin_center_v;
  typedef Class_pin_center_v* Const_pin_center_v;
  extern Const_pin_center_v c_pin_center_v;
  class Class_pin_expand;
  typedef Class_pin_expand* Const_pin_expand;
  extern Const_pin_expand c_pin_expand;
  class Class_pin_left;
  typedef Class_pin_left* Const_pin_left;
  extern Const_pin_left c_pin_left;
  class Class_pin_right;
  typedef Class_pin_right* Const_pin_right;
  extern Const_pin_right c_pin_right;
  class Class_pin_top;
  typedef Class_pin_top* Const_pin_top;
  extern Const_pin_top c_pin_top;
  class Class_styletype_custom;
  typedef Class_styletype_custom* Const_styletype_custom;
  extern Const_styletype_custom c_styletype_custom;
  class Class_styletype_shared;
  typedef Class_styletype_shared* Const_styletype_shared;
  extern Const_styletype_shared c_styletype_shared;
  class Class_styletype_system;
  typedef Class_styletype_system* Const_styletype_system;
  extern Const_styletype_system c_styletype_system;
  class Abstract_layout_from_style;
  typedef Abstract_layout_from_style* Func_layout_from_style;
  extern Func_layout_from_style e_layout_from_style;
  extern Func_layout_from_style t_layout_from_style;
  class Abstract_layoutmap_from_layoutlist;
  typedef Abstract_layoutmap_from_layoutlist* Func_layoutmap_from_layoutlist;
  extern Func_layoutmap_from_layoutlist e_layoutmap_from_layoutlist;
  extern Func_layoutmap_from_layoutlist t_layoutmap_from_layoutlist;
  class Abstract_stylemap_from_stylelist;
  typedef Abstract_stylemap_from_stylelist* Func_stylemap_from_stylelist;
  extern Func_stylemap_from_stylelist e_stylemap_from_stylelist;
  extern Func_stylemap_from_stylelist t_stylemap_from_stylelist;
  class Abstract_stylesheet_render;
  typedef Abstract_stylesheet_render* Func_stylesheet_render;
  extern Func_stylesheet_render e_stylesheet_render;
  extern Func_stylesheet_render t_stylesheet_render;
  class Abstract_ui_layout_from_ui_layoutmap_else;
  typedef Abstract_ui_layout_from_ui_layoutmap_else* Func_ui_layout_from_ui_layoutmap_else;
  extern Func_ui_layout_from_ui_layoutmap_else e_ui_layout_from_ui_layoutmap_else;
  extern Func_ui_layout_from_ui_layoutmap_else t_ui_layout_from_ui_layoutmap_else;
  class Abstract_ui_render;
  typedef Abstract_ui_render* Func_ui_render;
  extern Func_ui_render e_ui_render;
  extern Func_ui_render t_ui_render;
  class Abstract_ui_render_from_fn_render_ui_orig_parent;
  typedef Abstract_ui_render_from_fn_render_ui_orig_parent* Func_ui_render_from_fn_render_ui_orig_parent;
  extern Func_ui_render_from_fn_render_ui_orig_parent e_ui_render_from_fn_render_ui_orig_parent;
  extern Func_ui_render_from_fn_render_ui_orig_parent t_ui_render_from_fn_render_ui_orig_parent;
  class Abstract_ui_render_from_ui_orig_parent;
  typedef Abstract_ui_render_from_ui_orig_parent* Func_ui_render_from_ui_orig_parent;
  extern Func_ui_render_from_ui_orig_parent e_ui_render_from_ui_orig_parent;
  extern Func_ui_render_from_ui_orig_parent t_ui_render_from_ui_orig_parent;
  class Abstract_ui_from_renderer_ui_orig_parent;
  typedef Abstract_ui_from_renderer_ui_orig_parent* Func_ui_from_renderer_ui_orig_parent;
  extern Func_ui_from_renderer_ui_orig_parent e_ui_from_renderer_ui_orig_parent;
  extern Func_ui_from_renderer_ui_orig_parent t_ui_from_renderer_ui_orig_parent;
  class Abstract_uiengine_render;
  typedef Abstract_uiengine_render* Func_uiengine_render;
  extern Func_uiengine_render e_uiengine_render;
  extern Func_uiengine_render t_uiengine_render;
  class Abstract_uimap_layout_from_uimap_layoutmap_else;
  typedef Abstract_uimap_layout_from_uimap_layoutmap_else* Func_uimap_layout_from_uimap_layoutmap_else;
  extern Func_uimap_layout_from_uimap_layoutmap_else e_uimap_layout_from_uimap_layoutmap_else;
  extern Func_uimap_layout_from_uimap_layoutmap_else t_uimap_layout_from_uimap_layoutmap_else;
  class Abstract_uimap_render_from_uimap_parent;
  typedef Abstract_uimap_render_from_uimap_parent* Func_uimap_render_from_uimap_parent;
  extern Func_uimap_render_from_uimap_parent e_uimap_render_from_uimap_parent;
  extern Func_uimap_render_from_uimap_parent t_uimap_render_from_uimap_parent;
  class Abstract_uimap_from_uilist;
  typedef Abstract_uimap_from_uilist* Func_uimap_from_uilist;
  extern Func_uimap_from_uilist e_uimap_from_uilist;
  extern Func_uimap_from_uilist t_uimap_from_uilist;
  class Abstract_uimap_from_uimap_data;
  typedef Abstract_uimap_from_uimap_data* Func_uimap_from_uimap_data;
  extern Func_uimap_from_uimap_data e_uimap_from_uimap_data;
  extern Func_uimap_from_uimap_data t_uimap_from_uimap_data;
  // (func layout<-style)
  vx_ui_ui::Type_layout f_layout_from_style(vx_ui_ui::Type_style style);

  // (func layoutmap<-layoutlist)
  vx_ui_ui::Type_layoutmap f_layoutmap_from_layoutlist(vx_ui_ui::Type_layoutlist layoutlist);

  // (func stylemap<-stylelist)
  vx_ui_ui::Type_stylemap f_stylemap_from_stylelist(vx_ui_ui::Type_stylelist stylelist);

  // (func stylesheet-render)
  vx_ui_ui::Type_stylesheet f_stylesheet_render(vx_ui_ui::Type_stylesheet stylesheetui);

  // (func ui-layout<-ui-layoutmap-else)
  vx_ui_ui::Type_ui f_ui_layout_from_ui_layoutmap_else(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_layoutmap layoutmap, vx_ui_ui::Type_layout layoutelse);

  // (func ui-render)
  vx_ui_ui::Type_ui f_ui_render(vx_ui_ui::Type_ui uiarg);

  // (func ui-render<-fn-render-ui-orig-parent)
  vx_ui_ui::Type_render f_ui_render_from_fn_render_ui_orig_parent(vx_ui_ui::Func_ui_render_from_ui_orig_parent fn_render, vx_ui_ui::Type_ui ui, vx_ui_ui::Type_ui orig, vx_ui_ui::Type_ui parent);

  // (func ui-render<-ui-orig-parent)
  vx_ui_ui::Type_ui f_ui_render_from_ui_orig_parent(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_ui orig, vx_ui_ui::Type_ui parent);

  // (func ui<-renderer-ui-orig-parent)
  vx_ui_ui::Type_ui f_ui_from_renderer_ui_orig_parent(vx_ui_ui::Type_layout renderer, vx_ui_ui::Type_ui uiarg, vx_ui_ui::Type_ui uiorig, vx_ui_ui::Type_ui parent);

  // (func uiengine-render)
  vx_ui_ui::Type_uiengine f_uiengine_render(vx_ui_ui::Type_uiengine uiengine);

  // (func uimap-layout<-uimap-layoutmap-else)
  vx_ui_ui::Type_uimap f_uimap_layout_from_uimap_layoutmap_else(vx_ui_ui::Type_uimap uimap, vx_ui_ui::Type_layoutmap layoutmap, vx_ui_ui::Type_layout layoutelse);

  // (func uimap-render<-uimap-parent)
  vx_ui_ui::Type_uimap f_uimap_render_from_uimap_parent(vx_ui_ui::Type_uimap uimap, vx_ui_ui::Type_ui parent);

  // (func uimap<-uilist)
  vx_ui_ui::Type_uimap f_uimap_from_uilist(vx_ui_ui::Type_uilist uilist);

  // (func uimap<-uimap-data)
  vx_ui_ui::Type_uimap f_uimap_from_uimap_data(vx_ui_ui::Type_uimap uimap, vx_core::Type_any data);

  // (type bounds)
  class Abstract_bounds : public virtual vx_core::Abstract_struct {
  public:
    Abstract_bounds() {};
    virtual ~Abstract_bounds() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // left()
    vx_core::Type_int vx_p_left = NULL;
    virtual vx_core::Type_int left() const = 0;
    // right()
    vx_core::Type_int vx_p_right = NULL;
    virtual vx_core::Type_int right() const = 0;
    // top()
    vx_core::Type_int vx_p_top = NULL;
    virtual vx_core::Type_int top() const = 0;
    // bottom()
    vx_core::Type_int vx_p_bottom = NULL;
    virtual vx_core::Type_int bottom() const = 0;
  };
  class Class_bounds : public virtual Abstract_bounds {
  public:
    Class_bounds();
    virtual ~Class_bounds() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_int left() const override;
    virtual vx_core::Type_int right() const override;
    virtual vx_core::Type_int top() const override;
    virtual vx_core::Type_int bottom() const override;
  };

  // (type cursor)
  class Abstract_cursor : public virtual vx_core::Abstract_struct {
  public:
    Abstract_cursor() {};
    virtual ~Abstract_cursor() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
  };
  class Class_cursor : public virtual Abstract_cursor {
  public:
    Class_cursor();
    virtual ~Class_cursor() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
  };

  // (type cursor-pointer)
  class Abstract_cursor_pointer : public virtual vx_core::Abstract_any {
  public:
    Abstract_cursor_pointer() {};
    virtual ~Abstract_cursor_pointer() = 0;
  };
  class Class_cursor_pointer : public virtual Abstract_cursor_pointer {
  public:
    Class_cursor_pointer();
    virtual ~Class_cursor_pointer() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type layout)
  class Abstract_layout : public virtual vx_core::Abstract_struct {
  public:
    Abstract_layout() {};
    virtual ~Abstract_layout() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
    // fn-layout()
    vx_ui_ui::Func_ui_render_from_ui_orig_parent vx_p_fn_layout = NULL;
    virtual vx_ui_ui::Func_ui_render_from_ui_orig_parent fn_layout() const = 0;
  };
  class Class_layout : public virtual Abstract_layout {
  public:
    Class_layout();
    virtual ~Class_layout() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string name() const override;
    virtual vx_ui_ui::Func_ui_render_from_ui_orig_parent fn_layout() const override;
  };

  // (type layoutengine)
  class Abstract_layoutengine : public virtual vx_core::Abstract_struct {
  public:
    Abstract_layoutengine() {};
    virtual ~Abstract_layoutengine() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
    // layoutmap()
    vx_ui_ui::Type_layoutmap vx_p_layoutmap = NULL;
    virtual vx_ui_ui::Type_layoutmap layoutmap() const = 0;
    // layoutelse()
    vx_ui_ui::Type_layout vx_p_layoutelse = NULL;
    virtual vx_ui_ui::Type_layout layoutelse() const = 0;
    // stylesheetrender()
    vx_ui_ui::Func_stylesheet_render vx_p_stylesheetrender = NULL;
    virtual vx_ui_ui::Func_stylesheet_render stylesheetrender() const = 0;
  };
  class Class_layoutengine : public virtual Abstract_layoutengine {
  public:
    Class_layoutengine();
    virtual ~Class_layoutengine() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string name() const override;
    virtual vx_ui_ui::Type_layoutmap layoutmap() const override;
    virtual vx_ui_ui::Type_layout layoutelse() const override;
    virtual vx_ui_ui::Func_stylesheet_render stylesheetrender() const override;
  };

  // (type layoutlist)
  class Abstract_layoutlist : public virtual vx_core::Abstract_list {
  public:
    Abstract_layoutlist() {};
    virtual ~Abstract_layoutlist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_ui_ui::Type_layout> vx_p_list;
    // vx_listlayout()
    virtual std::vector<vx_ui_ui::Type_layout> vx_listlayout() const = 0;
    // vx_get_layout(index)
    virtual vx_ui_ui::Type_layout vx_get_layout(vx_core::Type_int index) const = 0;
  };
  class Class_layoutlist : public virtual Abstract_layoutlist {
  public:
    Class_layoutlist();
    virtual ~Class_layoutlist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
    virtual std::vector<vx_ui_ui::Type_layout> vx_listlayout() const override;
    virtual vx_ui_ui::Type_layout vx_get_layout(vx_core::Type_int index) const override;
  };

  // (type layoutmap)
  class Abstract_layoutmap : public virtual vx_core::Abstract_map {
  public:
    Abstract_layoutmap() {};
    virtual ~Abstract_layoutmap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
    std::map<std::string, vx_ui_ui::Type_layout> vx_p_map;
    // vx_maplayout()
    virtual std::map<std::string, vx_ui_ui::Type_layout> vx_maplayout() const = 0;
    // vx_get_layout(key)
    virtual vx_ui_ui::Type_layout vx_get_layout(vx_core::Type_string key) const = 0;
  };
  class Class_layoutmap : public virtual Abstract_layoutmap {
  public:
    Class_layoutmap();
    virtual ~Class_layoutmap() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const override;
    virtual std::map<std::string, vx_ui_ui::Type_layout> vx_maplayout() const override;
    virtual vx_ui_ui::Type_layout vx_get_layout(vx_core::Type_string key) const override;
  };

  // (type pin)
  class Abstract_pin : public virtual vx_core::Abstract_struct {
  public:
    Abstract_pin() {};
    virtual ~Abstract_pin() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
  };
  class Class_pin : public virtual Abstract_pin {
  public:
    Class_pin();
    virtual ~Class_pin() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string name() const override;
  };

  // (type point)
  class Abstract_point : public virtual vx_core::Abstract_struct {
  public:
    Abstract_point() {};
    virtual ~Abstract_point() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // x()
    vx_core::Type_int vx_p_x = NULL;
    virtual vx_core::Type_int x() const = 0;
    // y()
    vx_core::Type_int vx_p_y = NULL;
    virtual vx_core::Type_int y() const = 0;
    // z()
    vx_core::Type_int vx_p_z = NULL;
    virtual vx_core::Type_int z() const = 0;
    // t()
    vx_core::Type_int vx_p_t = NULL;
    virtual vx_core::Type_int t() const = 0;
    // i()
    vx_core::Type_int vx_p_i = NULL;
    virtual vx_core::Type_int i() const = 0;
    // ispercent()
    vx_core::Type_boolean vx_p_ispercent = NULL;
    virtual vx_core::Type_boolean ispercent() const = 0;
    // pointstyle()
    vx_ui_ui::Type_pointstyle vx_p_pointstyle = NULL;
    virtual vx_ui_ui::Type_pointstyle pointstyle() const = 0;
  };
  class Class_point : public virtual Abstract_point {
  public:
    Class_point();
    virtual ~Class_point() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_int x() const override;
    virtual vx_core::Type_int y() const override;
    virtual vx_core::Type_int z() const override;
    virtual vx_core::Type_int t() const override;
    virtual vx_core::Type_int i() const override;
    virtual vx_core::Type_boolean ispercent() const override;
    virtual vx_ui_ui::Type_pointstyle pointstyle() const override;
  };

  // (type pointstyle)
  class Abstract_pointstyle : public virtual vx_core::Abstract_struct {
  public:
    Abstract_pointstyle() {};
    virtual ~Abstract_pointstyle() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
  };
  class Class_pointstyle : public virtual Abstract_pointstyle {
  public:
    Class_pointstyle();
    virtual ~Class_pointstyle() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
  };

  // (type render)
  class Abstract_render : public virtual vx_core::Abstract_struct {
  public:
    Abstract_render() {};
    virtual ~Abstract_render() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
  };
  class Class_render : public virtual Abstract_render {
  public:
    Class_render();
    virtual ~Class_render() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
  };

  // (type rendermap)
  class Abstract_rendermap : public virtual vx_core::Abstract_map {
  public:
    Abstract_rendermap() {};
    virtual ~Abstract_rendermap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
    std::map<std::string, vx_ui_ui::Type_render> vx_p_map;
    // vx_maprender()
    virtual std::map<std::string, vx_ui_ui::Type_render> vx_maprender() const = 0;
    // vx_get_render(key)
    virtual vx_ui_ui::Type_render vx_get_render(vx_core::Type_string key) const = 0;
  };
  class Class_rendermap : public virtual Abstract_rendermap {
  public:
    Class_rendermap();
    virtual ~Class_rendermap() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const override;
    virtual std::map<std::string, vx_ui_ui::Type_render> vx_maprender() const override;
    virtual vx_ui_ui::Type_render vx_get_render(vx_core::Type_string key) const override;
  };

  // (type style)
  class Abstract_style : public virtual vx_core::Abstract_struct {
  public:
    Abstract_style() {};
    virtual ~Abstract_style() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
    // boundsmargin()
    vx_ui_ui::Type_bounds vx_p_boundsmargin = NULL;
    virtual vx_ui_ui::Type_bounds boundsmargin() const = 0;
    // boundspadding()
    vx_ui_ui::Type_bounds vx_p_boundspadding = NULL;
    virtual vx_ui_ui::Type_bounds boundspadding() const = 0;
    // color-background()
    vx_core::Type_string vx_p_color_background = NULL;
    virtual vx_core::Type_string color_background() const = 0;
    // color-hoverbkgrd()
    vx_core::Type_string vx_p_color_hoverbkgrd = NULL;
    virtual vx_core::Type_string color_hoverbkgrd() const = 0;
    // cursor()
    vx_ui_ui::Type_cursor vx_p_cursor = NULL;
    virtual vx_ui_ui::Type_cursor cursor() const = 0;
    // image-background()
    vx_data_file::Type_file vx_p_image_background = NULL;
    virtual vx_data_file::Type_file image_background() const = 0;
    // layout()
    vx_ui_ui::Type_layout vx_p_layout = NULL;
    virtual vx_ui_ui::Type_layout layout() const = 0;
    // type()
    vx_ui_ui::Type_styletype vx_p_type = NULL;
    virtual vx_ui_ui::Type_styletype type() const = 0;
    // pin()
    vx_ui_ui::Type_pin vx_p_pin = NULL;
    virtual vx_ui_ui::Type_pin pin() const = 0;
    // pointpos()
    vx_ui_ui::Type_point vx_p_pointpos = NULL;
    virtual vx_ui_ui::Type_point pointpos() const = 0;
    // pointsize()
    vx_ui_ui::Type_point vx_p_pointsize = NULL;
    virtual vx_ui_ui::Type_point pointsize() const = 0;
  };
  class Class_style : public virtual Abstract_style {
  public:
    Class_style();
    virtual ~Class_style() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string name() const override;
    virtual vx_ui_ui::Type_bounds boundsmargin() const override;
    virtual vx_ui_ui::Type_bounds boundspadding() const override;
    virtual vx_core::Type_string color_background() const override;
    virtual vx_core::Type_string color_hoverbkgrd() const override;
    virtual vx_ui_ui::Type_cursor cursor() const override;
    virtual vx_data_file::Type_file image_background() const override;
    virtual vx_ui_ui::Type_layout layout() const override;
    virtual vx_ui_ui::Type_styletype type() const override;
    virtual vx_ui_ui::Type_pin pin() const override;
    virtual vx_ui_ui::Type_point pointpos() const override;
    virtual vx_ui_ui::Type_point pointsize() const override;
  };

  // (type stylelist)
  class Abstract_stylelist : public virtual vx_core::Abstract_list {
  public:
    Abstract_stylelist() {};
    virtual ~Abstract_stylelist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_ui_ui::Type_style> vx_p_list;
    // vx_liststyle()
    virtual std::vector<vx_ui_ui::Type_style> vx_liststyle() const = 0;
    // vx_get_style(index)
    virtual vx_ui_ui::Type_style vx_get_style(vx_core::Type_int index) const = 0;
  };
  class Class_stylelist : public virtual Abstract_stylelist {
  public:
    Class_stylelist();
    virtual ~Class_stylelist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
    virtual std::vector<vx_ui_ui::Type_style> vx_liststyle() const override;
    virtual vx_ui_ui::Type_style vx_get_style(vx_core::Type_int index) const override;
  };

  // (type stylemap)
  class Abstract_stylemap : public virtual vx_core::Abstract_map {
  public:
    Abstract_stylemap() {};
    virtual ~Abstract_stylemap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
    std::map<std::string, vx_ui_ui::Type_style> vx_p_map;
    // vx_mapstyle()
    virtual std::map<std::string, vx_ui_ui::Type_style> vx_mapstyle() const = 0;
    // vx_get_style(key)
    virtual vx_ui_ui::Type_style vx_get_style(vx_core::Type_string key) const = 0;
  };
  class Class_stylemap : public virtual Abstract_stylemap {
  public:
    Class_stylemap();
    virtual ~Class_stylemap() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const override;
    virtual std::map<std::string, vx_ui_ui::Type_style> vx_mapstyle() const override;
    virtual vx_ui_ui::Type_style vx_get_style(vx_core::Type_string key) const override;
  };

  // (type stylesheet)
  class Abstract_stylesheet : public virtual vx_core::Abstract_struct {
  public:
    Abstract_stylesheet() {};
    virtual ~Abstract_stylesheet() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // stylemap()
    vx_ui_ui::Type_stylemap vx_p_stylemap = NULL;
    virtual vx_ui_ui::Type_stylemap stylemap() const = 0;
  };
  class Class_stylesheet : public virtual Abstract_stylesheet {
  public:
    Class_stylesheet();
    virtual ~Class_stylesheet() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_ui_ui::Type_stylemap stylemap() const override;
  };

  // (type styletype)
  class Abstract_styletype : public virtual vx_core::Abstract_struct {
  public:
    Abstract_styletype() {};
    virtual ~Abstract_styletype() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
  };
  class Class_styletype : public virtual Abstract_styletype {
  public:
    Class_styletype();
    virtual ~Class_styletype() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
  };

  // (type ui)
  class Abstract_ui : public virtual vx_core::Abstract_struct {
  public:
    Abstract_ui() {};
    virtual ~Abstract_ui() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // data()
    vx_core::Type_any vx_p_data = NULL;
    virtual vx_core::Type_any data() const = 0;
    // eventmap()
    vx_event::Type_eventmap vx_p_eventmap = NULL;
    virtual vx_event::Type_eventmap eventmap() const = 0;
    // fn-uimap-data()
    vx_ui_ui::Func_uimap_from_uimap_data vx_p_fn_uimap_data = NULL;
    virtual vx_ui_ui::Func_uimap_from_uimap_data fn_uimap_data() const = 0;
    // path()
    vx_core::Type_string vx_p_path = NULL;
    virtual vx_core::Type_string path() const = 0;
    // render()
    vx_ui_ui::Type_render vx_p_render = NULL;
    virtual vx_ui_ui::Type_render render() const = 0;
    // renderer()
    vx_ui_ui::Type_layout vx_p_renderer = NULL;
    virtual vx_ui_ui::Type_layout renderer() const = 0;
    // style()
    vx_ui_ui::Type_style vx_p_style = NULL;
    virtual vx_ui_ui::Type_style style() const = 0;
    // stylelist()
    vx_ui_ui::Type_stylelist vx_p_stylelist = NULL;
    virtual vx_ui_ui::Type_stylelist stylelist() const = 0;
    // stylesheet()
    vx_ui_ui::Type_stylesheet vx_p_stylesheet = NULL;
    virtual vx_ui_ui::Type_stylesheet stylesheet() const = 0;
    // uid()
    vx_core::Type_string vx_p_uid = NULL;
    virtual vx_core::Type_string uid() const = 0;
    // uimap()
    vx_ui_ui::Type_uimap vx_p_uimap = NULL;
    virtual vx_ui_ui::Type_uimap uimap() const = 0;
  };
  class Class_ui : public virtual Abstract_ui {
  public:
    Class_ui();
    virtual ~Class_ui() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_any data() const override;
    virtual vx_event::Type_eventmap eventmap() const override;
    virtual vx_ui_ui::Func_uimap_from_uimap_data fn_uimap_data() const override;
    virtual vx_core::Type_string path() const override;
    virtual vx_ui_ui::Type_render render() const override;
    virtual vx_ui_ui::Type_layout renderer() const override;
    virtual vx_ui_ui::Type_style style() const override;
    virtual vx_ui_ui::Type_stylelist stylelist() const override;
    virtual vx_ui_ui::Type_stylesheet stylesheet() const override;
    virtual vx_core::Type_string uid() const override;
    virtual vx_ui_ui::Type_uimap uimap() const override;
  };

  // (type uiengine)
  class Abstract_uiengine : public virtual vx_core::Abstract_struct {
  public:
    Abstract_uiengine() {};
    virtual ~Abstract_uiengine() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // parentmap()
    vx_ui_ui::Type_uimap vx_p_parentmap = NULL;
    virtual vx_ui_ui::Type_uimap parentmap() const = 0;
    // layoutengine()
    vx_ui_ui::Type_layoutengine vx_p_layoutengine = NULL;
    virtual vx_ui_ui::Type_layoutengine layoutengine() const = 0;
    // stylesheet()
    vx_ui_ui::Type_stylesheet vx_p_stylesheet = NULL;
    virtual vx_ui_ui::Type_stylesheet stylesheet() const = 0;
    // ui()
    vx_ui_ui::Type_ui vx_p_ui = NULL;
    virtual vx_ui_ui::Type_ui ui() const = 0;
  };
  class Class_uiengine : public virtual Abstract_uiengine {
  public:
    Class_uiengine();
    virtual ~Class_uiengine() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_ui_ui::Type_uimap parentmap() const override;
    virtual vx_ui_ui::Type_layoutengine layoutengine() const override;
    virtual vx_ui_ui::Type_stylesheet stylesheet() const override;
    virtual vx_ui_ui::Type_ui ui() const override;
  };

  // (type uilist)
  class Abstract_uilist : public virtual vx_core::Abstract_list {
  public:
    Abstract_uilist() {};
    virtual ~Abstract_uilist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_ui_ui::Type_ui> vx_p_list;
    // vx_listui()
    virtual std::vector<vx_ui_ui::Type_ui> vx_listui() const = 0;
    // vx_get_ui(index)
    virtual vx_ui_ui::Type_ui vx_get_ui(vx_core::Type_int index) const = 0;
  };
  class Class_uilist : public virtual Abstract_uilist {
  public:
    Class_uilist();
    virtual ~Class_uilist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
    virtual std::vector<vx_ui_ui::Type_ui> vx_listui() const override;
    virtual vx_ui_ui::Type_ui vx_get_ui(vx_core::Type_int index) const override;
  };

  // (type uimap)
  class Abstract_uimap : public virtual vx_core::Abstract_map {
  public:
    Abstract_uimap() {};
    virtual ~Abstract_uimap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
    std::map<std::string, vx_ui_ui::Type_ui> vx_p_map;
    // vx_mapui()
    virtual std::map<std::string, vx_ui_ui::Type_ui> vx_mapui() const = 0;
    // vx_get_ui(key)
    virtual vx_ui_ui::Type_ui vx_get_ui(vx_core::Type_string key) const = 0;
  };
  class Class_uimap : public virtual Abstract_uimap {
  public:
    Class_uimap();
    virtual ~Class_uimap() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const override;
    virtual std::map<std::string, vx_ui_ui::Type_ui> vx_mapui() const override;
    virtual vx_ui_ui::Type_ui vx_get_ui(vx_core::Type_string key) const override;
  };

  // (const layout-app)
  class Class_layout_app : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_ui::Const_layout_app output);
  };

  // (const layout-background)
  class Class_layout_background : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_ui::Const_layout_background output);
  };

  // (const layout-combobox)
  class Class_layout_combobox : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_ui::Const_layout_combobox output);
  };

  // (const layout-else)
  class Class_layout_else : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_ui::Const_layout_else output);
  };

  // (const layout-flow-columns)
  class Class_layout_flow_columns : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_ui::Const_layout_flow_columns output);
  };

  // (const layout-flow-rows)
  class Class_layout_flow_rows : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_ui::Const_layout_flow_rows output);
  };

  // (const layout-image)
  class Class_layout_image : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_ui::Const_layout_image output);
  };

  // (const layout-label)
  class Class_layout_label : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_ui::Const_layout_label output);
  };

  // (const layout-main)
  class Class_layout_main : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_ui::Const_layout_main output);
  };

  // (const layout-maxpanel)
  class Class_layout_maxpanel : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_ui::Const_layout_maxpanel output);
  };

  // (const layout-menubar)
  class Class_layout_menubar : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_ui::Const_layout_menubar output);
  };

  // (const layout-menudrawer)
  class Class_layout_menudrawer : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_ui::Const_layout_menudrawer output);
  };

  // (const layout-msgbox)
  class Class_layout_msgbox : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_ui::Const_layout_msgbox output);
  };

  // (const layout-navbar)
  class Class_layout_navbar : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_ui::Const_layout_navbar output);
  };

  // (const layout-navdrawer)
  class Class_layout_navdrawer : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_ui::Const_layout_navdrawer output);
  };

  // (const layout-panel)
  class Class_layout_panel : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_ui::Const_layout_panel output);
  };

  // (const layout-parallax)
  class Class_layout_parallax : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_ui::Const_layout_parallax output);
  };

  // (const layout-statusbar)
  class Class_layout_statusbar : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_ui::Const_layout_statusbar output);
  };

  // (const layout-statusdrawer)
  class Class_layout_statusdrawer : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_ui::Const_layout_statusdrawer output);
  };

  // (const layout-text)
  class Class_layout_text : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_ui::Const_layout_text output);
  };

  // (const layout-textentry)
  class Class_layout_textentry : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_ui::Const_layout_textentry output);
  };

  // (const pin-bottom)
  class Class_pin_bottom : public vx_ui_ui::Class_pin {
  public:
    static void vx_const_new(vx_ui_ui::Const_pin_bottom output);
  };

  // (const pin-center)
  class Class_pin_center : public vx_ui_ui::Class_pin {
  public:
    static void vx_const_new(vx_ui_ui::Const_pin_center output);
  };

  // (const pin-center-h)
  class Class_pin_center_h : public vx_ui_ui::Class_pin {
  public:
    static void vx_const_new(vx_ui_ui::Const_pin_center_h output);
  };

  // (const pin-center-v)
  class Class_pin_center_v : public vx_ui_ui::Class_pin {
  public:
    static void vx_const_new(vx_ui_ui::Const_pin_center_v output);
  };

  // (const pin-expand)
  class Class_pin_expand : public vx_ui_ui::Class_pin {
  public:
    static void vx_const_new(vx_ui_ui::Const_pin_expand output);
  };

  // (const pin-left)
  class Class_pin_left : public vx_ui_ui::Class_pin {
  public:
    static void vx_const_new(vx_ui_ui::Const_pin_left output);
  };

  // (const pin-right)
  class Class_pin_right : public vx_ui_ui::Class_pin {
  public:
    static void vx_const_new(vx_ui_ui::Const_pin_right output);
  };

  // (const pin-top)
  class Class_pin_top : public vx_ui_ui::Class_pin {
  public:
    static void vx_const_new(vx_ui_ui::Const_pin_top output);
  };

  // (const styletype-custom)
  class Class_styletype_custom : public vx_ui_ui::Class_styletype {
  public:
    static void vx_const_new(vx_ui_ui::Const_styletype_custom output);
  };

  // (const styletype-shared)
  class Class_styletype_shared : public vx_ui_ui::Class_styletype {
  public:
    static void vx_const_new(vx_ui_ui::Const_styletype_shared output);
  };

  // (const styletype-system)
  class Class_styletype_system : public vx_ui_ui::Class_styletype {
  public:
    static void vx_const_new(vx_ui_ui::Const_styletype_system output);
  };

  // (func layout<-style)
  class Abstract_layout_from_style : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_layout_from_style() {};
    virtual ~Abstract_layout_from_style() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_layout_from_style : public virtual Abstract_layout_from_style {
  public:
    Class_layout_from_style();
    virtual ~Class_layout_from_style() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func layoutmap<-layoutlist)
  class Abstract_layoutmap_from_layoutlist : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_layoutmap_from_layoutlist() {};
    virtual ~Abstract_layoutmap_from_layoutlist() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_layoutmap_from_layoutlist : public virtual Abstract_layoutmap_from_layoutlist {
  public:
    Class_layoutmap_from_layoutlist();
    virtual ~Class_layoutmap_from_layoutlist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func stylemap<-stylelist)
  class Abstract_stylemap_from_stylelist : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_stylemap_from_stylelist() {};
    virtual ~Abstract_stylemap_from_stylelist() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_stylemap_from_stylelist : public virtual Abstract_stylemap_from_stylelist {
  public:
    Class_stylemap_from_stylelist();
    virtual ~Class_stylemap_from_stylelist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func stylesheet-render)
  class Abstract_stylesheet_render : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_stylesheet_render() {};
    virtual ~Abstract_stylesheet_render() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_stylesheet_render : public virtual Abstract_stylesheet_render {
  public:
    Class_stylesheet_render();
    virtual ~Class_stylesheet_render() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func ui-layout<-ui-layoutmap-else)
  class Abstract_ui_layout_from_ui_layoutmap_else : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_ui_layout_from_ui_layoutmap_else() {};
    virtual ~Abstract_ui_layout_from_ui_layoutmap_else() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_ui_layout_from_ui_layoutmap_else : public virtual Abstract_ui_layout_from_ui_layoutmap_else {
  public:
    Class_ui_layout_from_ui_layoutmap_else();
    virtual ~Class_ui_layout_from_ui_layoutmap_else() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func ui-render)
  class Abstract_ui_render : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_ui_render() {};
    virtual ~Abstract_ui_render() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_ui_render : public virtual Abstract_ui_render {
  public:
    Class_ui_render();
    virtual ~Class_ui_render() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func ui-render<-fn-render-ui-orig-parent)
  class Abstract_ui_render_from_fn_render_ui_orig_parent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_ui_render_from_fn_render_ui_orig_parent() {};
    virtual ~Abstract_ui_render_from_fn_render_ui_orig_parent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_ui_render_from_fn_render_ui_orig_parent : public virtual Abstract_ui_render_from_fn_render_ui_orig_parent {
  public:
    Class_ui_render_from_fn_render_ui_orig_parent();
    virtual ~Class_ui_render_from_fn_render_ui_orig_parent() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func ui-render<-ui-orig-parent)
  class Abstract_ui_render_from_ui_orig_parent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_ui_render_from_ui_orig_parent() {};
    virtual ~Abstract_ui_render_from_ui_orig_parent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_ui_render_from_ui_orig_parent : public virtual Abstract_ui_render_from_ui_orig_parent {
  public:
    Class_ui_render_from_ui_orig_parent();
    virtual ~Class_ui_render_from_ui_orig_parent() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func ui<-renderer-ui-orig-parent)
  class Abstract_ui_from_renderer_ui_orig_parent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_ui_from_renderer_ui_orig_parent() {};
    virtual ~Abstract_ui_from_renderer_ui_orig_parent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_ui_from_renderer_ui_orig_parent : public virtual Abstract_ui_from_renderer_ui_orig_parent {
  public:
    Class_ui_from_renderer_ui_orig_parent();
    virtual ~Class_ui_from_renderer_ui_orig_parent() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func uiengine-render)
  class Abstract_uiengine_render : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_uiengine_render() {};
    virtual ~Abstract_uiengine_render() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_uiengine_render : public virtual Abstract_uiengine_render {
  public:
    Class_uiengine_render();
    virtual ~Class_uiengine_render() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func uimap-layout<-uimap-layoutmap-else)
  class Abstract_uimap_layout_from_uimap_layoutmap_else : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_uimap_layout_from_uimap_layoutmap_else() {};
    virtual ~Abstract_uimap_layout_from_uimap_layoutmap_else() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_uimap_layout_from_uimap_layoutmap_else : public virtual Abstract_uimap_layout_from_uimap_layoutmap_else {
  public:
    Class_uimap_layout_from_uimap_layoutmap_else();
    virtual ~Class_uimap_layout_from_uimap_layoutmap_else() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func uimap-render<-uimap-parent)
  class Abstract_uimap_render_from_uimap_parent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_uimap_render_from_uimap_parent() {};
    virtual ~Abstract_uimap_render_from_uimap_parent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_uimap_render_from_uimap_parent : public virtual Abstract_uimap_render_from_uimap_parent {
  public:
    Class_uimap_render_from_uimap_parent();
    virtual ~Class_uimap_render_from_uimap_parent() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func uimap<-uilist)
  class Abstract_uimap_from_uilist : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_uimap_from_uilist() {};
    virtual ~Abstract_uimap_from_uilist() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_uimap_from_uilist : public virtual Abstract_uimap_from_uilist {
  public:
    Class_uimap_from_uilist();
    virtual ~Class_uimap_from_uilist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func uimap<-uimap-data)
  class Abstract_uimap_from_uimap_data : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_uimap_from_uimap_data() {};
    virtual ~Abstract_uimap_from_uimap_data() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_uimap_from_uimap_data : public virtual Abstract_uimap_from_uimap_data {
  public:
    Class_uimap_from_uimap_data();
    virtual ~Class_uimap_from_uimap_data() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  class vx_Class_package {
  public:
    vx_Class_package();
    void init();
  };
  inline vx_Class_package const vx_package;

}

#endif
