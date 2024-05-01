#ifndef VX_UI_UI_HPP
#define VX_UI_UI_HPP
#include <map>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "../../vx/collection.hpp"
#include "../../vx/event.hpp"
#include "../../vx/data/file.hpp"
#include "../../vx/state.hpp"

namespace vx_ui_ui {


  // forward declarations
  class Abstract_align;
  typedef Abstract_align* Type_align;
  extern Type_align e_align;
  extern Type_align t_align;
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
  class Abstract_font;
  typedef Abstract_font* Type_font;
  extern Type_font e_font;
  extern Type_font t_font;
  class Abstract_fontface;
  typedef Abstract_fontface* Type_fontface;
  extern Type_fontface e_fontface;
  extern Type_fontface t_fontface;
  class Abstract_fontfacelist;
  typedef Abstract_fontfacelist* Type_fontfacelist;
  extern Type_fontfacelist e_fontfacelist;
  extern Type_fontfacelist t_fontfacelist;
  class Abstract_fontfacemap;
  typedef Abstract_fontfacemap* Type_fontfacemap;
  extern Type_fontfacemap e_fontfacemap;
  extern Type_fontfacemap t_fontfacemap;
  class Abstract_fontmap;
  typedef Abstract_fontmap* Type_fontmap;
  extern Type_fontmap e_fontmap;
  extern Type_fontmap t_fontmap;
  class Abstract_fontstyle;
  typedef Abstract_fontstyle* Type_fontstyle;
  extern Type_fontstyle e_fontstyle;
  extern Type_fontstyle t_fontstyle;
  class Abstract_fontstylemap;
  typedef Abstract_fontstylemap* Type_fontstylemap;
  extern Type_fontstylemap e_fontstylemap;
  extern Type_fontstylemap t_fontstylemap;
  class Abstract_image;
  typedef Abstract_image* Type_image;
  extern Type_image e_image;
  extern Type_image t_image;
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
  class Abstract_pointtype;
  typedef Abstract_pointtype* Type_pointtype;
  extern Type_pointtype e_pointtype;
  extern Type_pointtype t_pointtype;
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
  class Class_align_center;
  typedef Class_align_center* Const_align_center;
  extern Const_align_center c_align_center;
  class Class_align_left;
  typedef Class_align_left* Const_align_left;
  extern Const_align_left c_align_left;
  class Class_align_right;
  typedef Class_align_right* Const_align_right;
  extern Const_align_right c_align_right;
  class Class_layout_app;
  typedef Class_layout_app* Const_layout_app;
  extern Const_layout_app c_layout_app;
  class Class_layout_background;
  typedef Class_layout_background* Const_layout_background;
  extern Const_layout_background c_layout_background;
  class Class_layout_button;
  typedef Class_layout_button* Const_layout_button;
  extern Const_layout_button c_layout_button;
  class Class_layout_combobox;
  typedef Class_layout_combobox* Const_layout_combobox;
  extern Const_layout_combobox c_layout_combobox;
  class Class_layout_else;
  typedef Class_layout_else* Const_layout_else;
  extern Const_layout_else c_layout_else;
  class Class_layout_flow_columns;
  typedef Class_layout_flow_columns* Const_layout_flow_columns;
  extern Const_layout_flow_columns c_layout_flow_columns;
  class Class_layout_flow_item;
  typedef Class_layout_flow_item* Const_layout_flow_item;
  extern Const_layout_flow_item c_layout_flow_item;
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
  class Class_layout_titlebar;
  typedef Class_layout_titlebar* Const_layout_titlebar;
  extern Const_layout_titlebar c_layout_titlebar;
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
  class Class_pointtype_absolute;
  typedef Class_pointtype_absolute* Const_pointtype_absolute;
  extern Const_pointtype_absolute c_pointtype_absolute;
  class Class_pointtype_percent;
  typedef Class_pointtype_percent* Const_pointtype_percent;
  extern Const_pointtype_percent c_pointtype_percent;
  class Class_pointtype_relative;
  typedef Class_pointtype_relative* Const_pointtype_relative;
  extern Const_pointtype_relative c_pointtype_relative;
  class Class_styletype_custom;
  typedef Class_styletype_custom* Const_styletype_custom;
  extern Const_styletype_custom c_styletype_custom;
  class Class_styletype_shared;
  typedef Class_styletype_shared* Const_styletype_shared;
  extern Const_styletype_shared c_styletype_shared;
  class Class_styletype_system;
  typedef Class_styletype_system* Const_styletype_system;
  extern Const_styletype_system c_styletype_system;
  class Abstract_boolean_print;
  typedef Abstract_boolean_print* Func_boolean_print;
  extern Func_boolean_print e_boolean_print;
  extern Func_boolean_print t_boolean_print;
  class Abstract_boolean_writestate_from_ui;
  typedef Abstract_boolean_writestate_from_ui* Func_boolean_writestate_from_ui;
  extern Func_boolean_writestate_from_ui e_boolean_writestate_from_ui;
  extern Func_boolean_writestate_from_ui t_boolean_writestate_from_ui;
  class Abstract_boolean_writestate_from_uiengine;
  typedef Abstract_boolean_writestate_from_uiengine* Func_boolean_writestate_from_uiengine;
  extern Func_boolean_writestate_from_uiengine e_boolean_writestate_from_uiengine;
  extern Func_boolean_writestate_from_uiengine t_boolean_writestate_from_uiengine;
  class Abstract_fontfacemap_from_fontfacelist;
  typedef Abstract_fontfacemap_from_fontfacelist* Func_fontfacemap_from_fontfacelist;
  extern Func_fontfacemap_from_fontfacelist e_fontfacemap_from_fontfacelist;
  extern Func_fontfacemap_from_fontfacelist t_fontfacemap_from_fontfacelist;
  class Abstract_int_selected_from_ui;
  typedef Abstract_int_selected_from_ui* Func_int_selected_from_ui;
  extern Func_int_selected_from_ui e_int_selected_from_ui;
  extern Func_int_selected_from_ui t_int_selected_from_ui;
  class Abstract_layout_from_style;
  typedef Abstract_layout_from_style* Func_layout_from_style;
  extern Func_layout_from_style e_layout_from_style;
  extern Func_layout_from_style t_layout_from_style;
  class Abstract_layout_from_ui;
  typedef Abstract_layout_from_ui* Func_layout_from_ui;
  extern Func_layout_from_ui e_layout_from_ui;
  extern Func_layout_from_ui t_layout_from_ui;
  class Abstract_layout_from_ui_layoutengine;
  typedef Abstract_layout_from_ui_layoutengine* Func_layout_from_ui_layoutengine;
  extern Func_layout_from_ui_layoutengine e_layout_from_ui_layoutengine;
  extern Func_layout_from_ui_layoutengine t_layout_from_ui_layoutengine;
  class Abstract_layout_from_ui_layoutmap_else;
  typedef Abstract_layout_from_ui_layoutmap_else* Func_layout_from_ui_layoutmap_else;
  extern Func_layout_from_ui_layoutmap_else e_layout_from_ui_layoutmap_else;
  extern Func_layout_from_ui_layoutmap_else t_layout_from_ui_layoutmap_else;
  class Abstract_layoutengine_readstate;
  typedef Abstract_layoutengine_readstate* Func_layoutengine_readstate;
  extern Func_layoutengine_readstate e_layoutengine_readstate;
  extern Func_layoutengine_readstate t_layoutengine_readstate;
  class Abstract_layoutmap_from_layoutlist;
  typedef Abstract_layoutmap_from_layoutlist* Func_layoutmap_from_layoutlist;
  extern Func_layoutmap_from_layoutlist e_layoutmap_from_layoutlist;
  extern Func_layoutmap_from_layoutlist t_layoutmap_from_layoutlist;
  class Abstract_string_selected_from_ui;
  typedef Abstract_string_selected_from_ui* Func_string_selected_from_ui;
  extern Func_string_selected_from_ui e_string_selected_from_ui;
  extern Func_string_selected_from_ui t_string_selected_from_ui;
  class Abstract_stringlist_selected_from_ui;
  typedef Abstract_stringlist_selected_from_ui* Func_stringlist_selected_from_ui;
  extern Func_stringlist_selected_from_ui e_stringlist_selected_from_ui;
  extern Func_stringlist_selected_from_ui t_stringlist_selected_from_ui;
  class Abstract_stringlist_from_ui;
  typedef Abstract_stringlist_from_ui* Func_stringlist_from_ui;
  extern Func_stringlist_from_ui e_stringlist_from_ui;
  extern Func_stringlist_from_ui t_stringlist_from_ui;
  class Abstract_stylemap_from_stylelist;
  typedef Abstract_stylemap_from_stylelist* Func_stylemap_from_stylelist;
  extern Func_stylemap_from_stylelist e_stylemap_from_stylelist;
  extern Func_stylemap_from_stylelist t_stylemap_from_stylelist;
  class Abstract_stylesheet_readstate;
  typedef Abstract_stylesheet_readstate* Func_stylesheet_readstate;
  extern Func_stylesheet_readstate e_stylesheet_readstate;
  extern Func_stylesheet_readstate t_stylesheet_readstate;
  class Abstract_stylesheet_render;
  typedef Abstract_stylesheet_render* Func_stylesheet_render;
  extern Func_stylesheet_render e_stylesheet_render;
  extern Func_stylesheet_render t_stylesheet_render;
  class Abstract_ui_child_from_ui_uid;
  typedef Abstract_ui_child_from_ui_uid* Func_ui_child_from_ui_uid;
  extern Func_ui_child_from_ui_uid e_ui_child_from_ui_uid;
  extern Func_ui_child_from_ui_uid t_ui_child_from_ui_uid;
  class Abstract_ui_from_from_event;
  typedef Abstract_ui_from_from_event* Func_ui_from_from_event;
  extern Func_ui_from_from_event e_ui_from_from_event;
  extern Func_ui_from_from_event t_ui_from_from_event;
  class Abstract_ui_layout_from_ui;
  typedef Abstract_ui_layout_from_ui* Func_ui_layout_from_ui;
  extern Func_ui_layout_from_ui e_ui_layout_from_ui;
  extern Func_ui_layout_from_ui t_ui_layout_from_ui;
  class Abstract_ui_layout_from_ui_layoutengine;
  typedef Abstract_ui_layout_from_ui_layoutengine* Func_ui_layout_from_ui_layoutengine;
  extern Func_ui_layout_from_ui_layoutengine e_ui_layout_from_ui_layoutengine;
  extern Func_ui_layout_from_ui_layoutengine t_ui_layout_from_ui_layoutengine;
  class Abstract_ui_layout_from_ui_layoutmap_else;
  typedef Abstract_ui_layout_from_ui_layoutmap_else* Func_ui_layout_from_ui_layoutmap_else;
  extern Func_ui_layout_from_ui_layoutmap_else e_ui_layout_from_ui_layoutmap_else;
  extern Func_ui_layout_from_ui_layoutmap_else t_ui_layout_from_ui_layoutmap_else;
  class Abstract_ui_layout_from_ui_uiengine;
  typedef Abstract_ui_layout_from_ui_uiengine* Func_ui_layout_from_ui_uiengine;
  extern Func_ui_layout_from_ui_uiengine e_ui_layout_from_ui_uiengine;
  extern Func_ui_layout_from_ui_uiengine t_ui_layout_from_ui_uiengine;
  class Abstract_ui_readstate_from_uid;
  typedef Abstract_ui_readstate_from_uid* Func_ui_readstate_from_uid;
  extern Func_ui_readstate_from_uid e_ui_readstate_from_uid;
  extern Func_ui_readstate_from_uid t_ui_readstate_from_uid;
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
  class Abstract_ui_render_from_ui_parent_selected;
  typedef Abstract_ui_render_from_ui_parent_selected* Func_ui_render_from_ui_parent_selected;
  extern Func_ui_render_from_ui_parent_selected e_ui_render_from_ui_parent_selected;
  extern Func_ui_render_from_ui_parent_selected t_ui_render_from_ui_parent_selected;
  class Abstract_ui_selected_from_ui;
  typedef Abstract_ui_selected_from_ui* Func_ui_selected_from_ui;
  extern Func_ui_selected_from_ui e_ui_selected_from_ui;
  extern Func_ui_selected_from_ui t_ui_selected_from_ui;
  class Abstract_ui_writechild_from_ui_child;
  typedef Abstract_ui_writechild_from_ui_child* Func_ui_writechild_from_ui_child;
  extern Func_ui_writechild_from_ui_child e_ui_writechild_from_ui_child;
  extern Func_ui_writechild_from_ui_child t_ui_writechild_from_ui_child;
  class Abstract_ui_writechildmap_from_ui_childmap;
  typedef Abstract_ui_writechildmap_from_ui_childmap* Func_ui_writechildmap_from_ui_childmap;
  extern Func_ui_writechildmap_from_ui_childmap e_ui_writechildmap_from_ui_childmap;
  extern Func_ui_writechildmap_from_ui_childmap t_ui_writechildmap_from_ui_childmap;
  class Abstract_ui_from_layout_ui_orig_parent;
  typedef Abstract_ui_from_layout_ui_orig_parent* Func_ui_from_layout_ui_orig_parent;
  extern Func_ui_from_layout_ui_orig_parent e_ui_from_layout_ui_orig_parent;
  extern Func_ui_from_layout_ui_orig_parent t_ui_from_layout_ui_orig_parent;
  class Abstract_ui_from_ui_selected;
  typedef Abstract_ui_from_ui_selected* Func_ui_from_ui_selected;
  extern Func_ui_from_ui_selected e_ui_from_ui_selected;
  extern Func_ui_from_ui_selected t_ui_from_ui_selected;
  class Abstract_uid_selected_from_ui;
  typedef Abstract_uid_selected_from_ui* Func_uid_selected_from_ui;
  extern Func_uid_selected_from_ui e_uid_selected_from_ui;
  extern Func_uid_selected_from_ui t_uid_selected_from_ui;
  class Abstract_uiengine_readstate;
  typedef Abstract_uiengine_readstate* Func_uiengine_readstate;
  extern Func_uiengine_readstate e_uiengine_readstate;
  extern Func_uiengine_readstate t_uiengine_readstate;
  class Abstract_uiengine_render;
  typedef Abstract_uiengine_render* Func_uiengine_render;
  extern Func_uiengine_render e_uiengine_render;
  extern Func_uiengine_render t_uiengine_render;
  class Abstract_uilist_selected_from_ui;
  typedef Abstract_uilist_selected_from_ui* Func_uilist_selected_from_ui;
  extern Func_uilist_selected_from_ui e_uilist_selected_from_ui;
  extern Func_uilist_selected_from_ui t_uilist_selected_from_ui;
  class Abstract_uilist_from_uimap;
  typedef Abstract_uilist_from_uimap* Func_uilist_from_uimap;
  extern Func_uilist_from_uimap e_uilist_from_uimap;
  extern Func_uilist_from_uimap t_uilist_from_uimap;
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
  // (func boolean-print)
  vx_core::Type_boolean f_boolean_print(vx_core::Type_context context, vx_ui_ui::Type_ui ui);

  // (func boolean-writestate<-ui)
  vx_core::Type_boolean f_boolean_writestate_from_ui(vx_core::Type_context context, vx_ui_ui::Type_ui ui);

  // (func boolean-writestate<-uiengine)
  vx_core::Type_boolean f_boolean_writestate_from_uiengine(vx_core::Type_context context, vx_ui_ui::Type_uiengine uiengine);

  // (func fontfacemap<-fontfacelist)
  vx_ui_ui::Type_fontfacemap f_fontfacemap_from_fontfacelist(vx_ui_ui::Type_fontfacelist fontfacelist);

  // (func int-selected<-ui)
  vx_core::Type_int f_int_selected_from_ui(vx_ui_ui::Type_ui ui);

  // (func layout<-style)
  vx_ui_ui::Type_layout f_layout_from_style(vx_ui_ui::Type_style style);

  // (func layout<-ui)
  vx_ui_ui::Type_layout f_layout_from_ui(vx_core::Type_context context, vx_ui_ui::Type_ui ui);

  // (func layout<-ui-layoutengine)
  vx_ui_ui::Type_layout f_layout_from_ui_layoutengine(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_layoutengine layoutengine);

  // (func layout<-ui-layoutmap-else)
  vx_ui_ui::Type_layout f_layout_from_ui_layoutmap_else(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_layoutmap layoutmap, vx_ui_ui::Type_layout layoutelse);

  // (func layoutengine-readstate)
  vx_ui_ui::Type_layoutengine f_layoutengine_readstate(vx_core::Type_context context);

  // (func layoutmap<-layoutlist)
  vx_ui_ui::Type_layoutmap f_layoutmap_from_layoutlist(vx_ui_ui::Type_layoutlist layoutlist);

  // (func string-selected<-ui)
  vx_core::Type_string f_string_selected_from_ui(vx_ui_ui::Type_ui ui);

  // (func stringlist-selected<-ui)
  vx_core::Type_stringlist f_stringlist_selected_from_ui(vx_ui_ui::Type_ui ui);

  // (func stringlist<-ui)
  vx_core::Type_stringlist f_stringlist_from_ui(vx_ui_ui::Type_ui ui);

  // (func stylemap<-stylelist)
  vx_ui_ui::Type_stylemap f_stylemap_from_stylelist(vx_ui_ui::Type_stylelist stylelist);

  // (func stylesheet-readstate)
  vx_ui_ui::Type_stylesheet f_stylesheet_readstate(vx_core::Type_context context);

  // (func stylesheet-render)
  vx_ui_ui::Type_stylesheet f_stylesheet_render(vx_ui_ui::Type_stylesheet stylesheetui);

  // (func ui-child<-ui-uid)
  vx_ui_ui::Type_ui f_ui_child_from_ui_uid(vx_ui_ui::Type_ui ui, vx_core::Type_string uid);

  // (func ui-from<-event)
  vx_ui_ui::Type_ui f_ui_from_from_event(vx_core::Type_context context, vx_event::Type_event event);

  // (func ui-layout<-ui)
  vx_ui_ui::Type_ui f_ui_layout_from_ui(vx_core::Type_context context, vx_ui_ui::Type_ui ui);

  // (func ui-layout<-ui-layoutengine)
  vx_ui_ui::Type_ui f_ui_layout_from_ui_layoutengine(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_layoutengine layoutengine);

  // (func ui-layout<-ui-layoutmap-else)
  vx_ui_ui::Type_ui f_ui_layout_from_ui_layoutmap_else(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_layoutmap layoutmap, vx_ui_ui::Type_layout layoutelse);

  // (func ui-layout<-ui-uiengine)
  vx_ui_ui::Type_ui f_ui_layout_from_ui_uiengine(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_uiengine uiengine);

  // (func ui-readstate<-uid)
  vx_ui_ui::Type_ui f_ui_readstate_from_uid(vx_core::Type_context context, vx_core::Type_string uid);

  // (func ui-render)
  vx_ui_ui::Type_ui f_ui_render(vx_ui_ui::Type_ui uiarg);

  // (func ui-render<-fn-render-ui-orig-parent)
  vx_ui_ui::Type_ui f_ui_render_from_fn_render_ui_orig_parent(vx_ui_ui::Func_ui_render_from_ui_orig_parent fn_render, vx_ui_ui::Type_ui ui, vx_ui_ui::Type_ui orig, vx_ui_ui::Type_ui parent);

  // (func ui-render<-ui-orig-parent)
  vx_ui_ui::Type_ui f_ui_render_from_ui_orig_parent(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_ui orig, vx_ui_ui::Type_ui parent);

  // (func ui-render<-ui-parent-selected)
  vx_ui_ui::Type_ui f_ui_render_from_ui_parent_selected(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_ui parent, vx_core::Type_int selected);

  // (func ui-selected<-ui)
  vx_ui_ui::Type_ui f_ui_selected_from_ui(vx_ui_ui::Type_ui ui);

  // (func ui-writechild<-ui-child)
  vx_ui_ui::Type_ui f_ui_writechild_from_ui_child(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_ui child);

  // (func ui-writechildmap<-ui-childmap)
  vx_ui_ui::Type_ui f_ui_writechildmap_from_ui_childmap(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_uimap childmap);

  // (func ui<-layout-ui-orig-parent)
  vx_ui_ui::Type_ui f_ui_from_layout_ui_orig_parent(vx_ui_ui::Type_layout layout, vx_ui_ui::Type_ui uiarg, vx_ui_ui::Type_ui uiorig, vx_ui_ui::Type_ui parent);

  // (func ui<-ui-selected)
  vx_ui_ui::Type_ui f_ui_from_ui_selected(vx_ui_ui::Type_ui ui, vx_core::Type_int selected);

  // (func uid-selected<-ui)
  vx_core::Type_string f_uid_selected_from_ui(vx_ui_ui::Type_ui ui);

  // (func uiengine-readstate)
  vx_ui_ui::Type_uiengine f_uiengine_readstate(vx_core::Type_context context);

  // (func uiengine-render)
  vx_ui_ui::Type_uiengine f_uiengine_render(vx_core::Type_context context, vx_ui_ui::Type_uiengine uiengine);

  // (func uilist-selected<-ui)
  vx_ui_ui::Type_uilist f_uilist_selected_from_ui(vx_ui_ui::Type_ui uiarg);

  // (func uilist<-uimap)
  vx_ui_ui::Type_uilist f_uilist_from_uimap(vx_ui_ui::Type_uimap uimap);

  // (func uimap-layout<-uimap-layoutmap-else)
  vx_ui_ui::Type_uimap f_uimap_layout_from_uimap_layoutmap_else(vx_ui_ui::Type_uimap uimap, vx_ui_ui::Type_layoutmap layoutmap, vx_ui_ui::Type_layout layoutelse);

  // (func uimap-render<-uimap-parent)
  vx_ui_ui::Type_uimap f_uimap_render_from_uimap_parent(vx_ui_ui::Type_uimap uimap, vx_ui_ui::Type_ui parent);

  // (func uimap<-uilist)
  vx_ui_ui::Type_uimap f_uimap_from_uilist(vx_ui_ui::Type_uilist uilist);

  // (func uimap<-uimap-data)
  vx_ui_ui::Type_uimap f_uimap_from_uimap_data(vx_ui_ui::Type_uimap uimap, vx_core::Type_any data);

  // (type align)
  class Abstract_align : public virtual vx_core::Abstract_struct {
  public:
    Abstract_align() {};
    virtual ~Abstract_align() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
  };
  class Class_align : public virtual Abstract_align {
  public:
    Class_align();
    virtual ~Class_align() override;
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

  // (type font)
  class Abstract_font : public virtual vx_core::Abstract_struct {
  public:
    Abstract_font() {};
    virtual ~Abstract_font() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
    // fontface()
    vx_ui_ui::Type_fontface vx_p_fontface = NULL;
    virtual vx_ui_ui::Type_fontface fontface() const = 0;
    // fontsize()
    vx_core::Type_int vx_p_fontsize = NULL;
    virtual vx_core::Type_int fontsize() const = 0;
    // fontstyle()
    vx_ui_ui::Type_fontstyle vx_p_fontstyle = NULL;
    virtual vx_ui_ui::Type_fontstyle fontstyle() const = 0;
  };
  class Class_font : public virtual Abstract_font {
  public:
    Class_font();
    virtual ~Class_font() override;
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
    virtual vx_ui_ui::Type_fontface fontface() const override;
    virtual vx_core::Type_int fontsize() const override;
    virtual vx_ui_ui::Type_fontstyle fontstyle() const override;
  };

  // (type fontface)
  class Abstract_fontface : public virtual vx_core::Abstract_struct {
  public:
    Abstract_fontface() {};
    virtual ~Abstract_fontface() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
    // weight()
    vx_core::Type_string vx_p_weight = NULL;
    virtual vx_core::Type_string weight() const = 0;
    // unicode()
    vx_core::Type_string vx_p_unicode = NULL;
    virtual vx_core::Type_string unicode() const = 0;
    // filelist()
    vx_data_file::Type_filelist vx_p_filelist = NULL;
    virtual vx_data_file::Type_filelist filelist() const = 0;
  };
  class Class_fontface : public virtual Abstract_fontface {
  public:
    Class_fontface();
    virtual ~Class_fontface() override;
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
    virtual vx_core::Type_string weight() const override;
    virtual vx_core::Type_string unicode() const override;
    virtual vx_data_file::Type_filelist filelist() const override;
  };

  // (type fontfacelist)
  class Abstract_fontfacelist : public virtual vx_core::Abstract_list {
  public:
    Abstract_fontfacelist() {};
    virtual ~Abstract_fontfacelist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_ui_ui::Type_fontface> vx_p_list;
    // vx_listfontface()
    virtual std::vector<vx_ui_ui::Type_fontface> vx_listfontface() const = 0;
    // vx_get_fontface(index)
    virtual vx_ui_ui::Type_fontface vx_get_fontface(vx_core::Type_int index) const = 0;
  };
  class Class_fontfacelist : public virtual Abstract_fontfacelist {
  public:
    Class_fontfacelist();
    virtual ~Class_fontfacelist() override;
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
    virtual std::vector<vx_ui_ui::Type_fontface> vx_listfontface() const override;
    virtual vx_ui_ui::Type_fontface vx_get_fontface(vx_core::Type_int index) const override;
  };

  // (type fontfacemap)
  class Abstract_fontfacemap : public virtual vx_core::Abstract_map {
  public:
    Abstract_fontfacemap() {};
    virtual ~Abstract_fontfacemap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
    std::map<std::string, vx_ui_ui::Type_fontface> vx_p_map;
    // vx_mapfontface()
    virtual std::map<std::string, vx_ui_ui::Type_fontface> vx_mapfontface() const = 0;
    // vx_get_fontface(key)
    virtual vx_ui_ui::Type_fontface vx_get_fontface(vx_core::Type_string key) const = 0;
  };
  class Class_fontfacemap : public virtual Abstract_fontfacemap {
  public:
    Class_fontfacemap();
    virtual ~Class_fontfacemap() override;
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
    virtual std::map<std::string, vx_ui_ui::Type_fontface> vx_mapfontface() const override;
    virtual vx_ui_ui::Type_fontface vx_get_fontface(vx_core::Type_string key) const override;
  };

  // (type fontmap)
  class Abstract_fontmap : public virtual vx_core::Abstract_map {
  public:
    Abstract_fontmap() {};
    virtual ~Abstract_fontmap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
    std::map<std::string, vx_ui_ui::Type_font> vx_p_map;
    // vx_mapfont()
    virtual std::map<std::string, vx_ui_ui::Type_font> vx_mapfont() const = 0;
    // vx_get_font(key)
    virtual vx_ui_ui::Type_font vx_get_font(vx_core::Type_string key) const = 0;
  };
  class Class_fontmap : public virtual Abstract_fontmap {
  public:
    Class_fontmap();
    virtual ~Class_fontmap() override;
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
    virtual std::map<std::string, vx_ui_ui::Type_font> vx_mapfont() const override;
    virtual vx_ui_ui::Type_font vx_get_font(vx_core::Type_string key) const override;
  };

  // (type fontstyle)
  class Abstract_fontstyle : public virtual vx_core::Abstract_struct {
  public:
    Abstract_fontstyle() {};
    virtual ~Abstract_fontstyle() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
  };
  class Class_fontstyle : public virtual Abstract_fontstyle {
  public:
    Class_fontstyle();
    virtual ~Class_fontstyle() override;
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

  // (type fontstylemap)
  class Abstract_fontstylemap : public virtual vx_core::Abstract_map {
  public:
    Abstract_fontstylemap() {};
    virtual ~Abstract_fontstylemap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
    std::map<std::string, vx_ui_ui::Type_fontstyle> vx_p_map;
    // vx_mapfontstyle()
    virtual std::map<std::string, vx_ui_ui::Type_fontstyle> vx_mapfontstyle() const = 0;
    // vx_get_fontstyle(key)
    virtual vx_ui_ui::Type_fontstyle vx_get_fontstyle(vx_core::Type_string key) const = 0;
  };
  class Class_fontstylemap : public virtual Abstract_fontstylemap {
  public:
    Class_fontstylemap();
    virtual ~Class_fontstylemap() override;
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
    virtual std::map<std::string, vx_ui_ui::Type_fontstyle> vx_mapfontstyle() const override;
    virtual vx_ui_ui::Type_fontstyle vx_get_fontstyle(vx_core::Type_string key) const override;
  };

  // (type image)
  class Abstract_image : public virtual vx_core::Abstract_struct {
  public:
    Abstract_image() {};
    virtual ~Abstract_image() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
    // label()
    vx_core::Type_string vx_p_label = NULL;
    virtual vx_core::Type_string label() const = 0;
    // file()
    vx_data_file::Type_file vx_p_file = NULL;
    virtual vx_data_file::Type_file file() const = 0;
  };
  class Class_image : public virtual Abstract_image {
  public:
    Class_image();
    virtual ~Class_image() override;
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
    virtual vx_core::Type_string label() const override;
    virtual vx_data_file::Type_file file() const override;
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
    // boolean-print()
    vx_ui_ui::Func_boolean_print vx_p_boolean_print = NULL;
    virtual vx_ui_ui::Func_boolean_print boolean_print() const = 0;
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
    virtual vx_ui_ui::Func_boolean_print boolean_print() const override;
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
    // pointtype()
    vx_ui_ui::Type_pointtype vx_p_pointtype = NULL;
    virtual vx_ui_ui::Type_pointtype pointtype() const = 0;
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
    virtual vx_ui_ui::Type_pointtype pointtype() const override;
  };

  // (type pointtype)
  class Abstract_pointtype : public virtual vx_core::Abstract_any {
  public:
    Abstract_pointtype() {};
    virtual ~Abstract_pointtype() = 0;
  };
  class Class_pointtype : public virtual Abstract_pointtype {
  public:
    Class_pointtype();
    virtual ~Class_pointtype() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
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
    // align()
    vx_ui_ui::Type_align vx_p_align = NULL;
    virtual vx_ui_ui::Type_align align() const = 0;
    // boundsmargin()
    vx_ui_ui::Type_bounds vx_p_boundsmargin = NULL;
    virtual vx_ui_ui::Type_bounds boundsmargin() const = 0;
    // boundspadding()
    vx_ui_ui::Type_bounds vx_p_boundspadding = NULL;
    virtual vx_ui_ui::Type_bounds boundspadding() const = 0;
    // color-background()
    vx_core::Type_string vx_p_color_background = NULL;
    virtual vx_core::Type_string color_background() const = 0;
    // color-border()
    vx_core::Type_string vx_p_color_border = NULL;
    virtual vx_core::Type_string color_border() const = 0;
    // color-font()
    vx_core::Type_string vx_p_color_font = NULL;
    virtual vx_core::Type_string color_font() const = 0;
    // color-hoverbkgrd()
    vx_core::Type_string vx_p_color_hoverbkgrd = NULL;
    virtual vx_core::Type_string color_hoverbkgrd() const = 0;
    // cursor()
    vx_ui_ui::Type_cursor vx_p_cursor = NULL;
    virtual vx_ui_ui::Type_cursor cursor() const = 0;
    // font()
    vx_ui_ui::Type_font vx_p_font = NULL;
    virtual vx_ui_ui::Type_font font() const = 0;
    // hidden()
    vx_core::Type_boolean vx_p_hidden = NULL;
    virtual vx_core::Type_boolean hidden() const = 0;
    // image-background()
    vx_ui_ui::Type_image vx_p_image_background = NULL;
    virtual vx_ui_ui::Type_image image_background() const = 0;
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
    // pointrotate()
    vx_ui_ui::Type_point vx_p_pointrotate = NULL;
    virtual vx_ui_ui::Type_point pointrotate() const = 0;
    // pointsize()
    vx_ui_ui::Type_point vx_p_pointsize = NULL;
    virtual vx_ui_ui::Type_point pointsize() const = 0;
    // scroll-x()
    vx_core::Type_boolean vx_p_scroll_x = NULL;
    virtual vx_core::Type_boolean scroll_x() const = 0;
    // scroll-y()
    vx_core::Type_boolean vx_p_scroll_y = NULL;
    virtual vx_core::Type_boolean scroll_y() const = 0;
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
    virtual vx_ui_ui::Type_align align() const override;
    virtual vx_ui_ui::Type_bounds boundsmargin() const override;
    virtual vx_ui_ui::Type_bounds boundspadding() const override;
    virtual vx_core::Type_string color_background() const override;
    virtual vx_core::Type_string color_border() const override;
    virtual vx_core::Type_string color_font() const override;
    virtual vx_core::Type_string color_hoverbkgrd() const override;
    virtual vx_ui_ui::Type_cursor cursor() const override;
    virtual vx_ui_ui::Type_font font() const override;
    virtual vx_core::Type_boolean hidden() const override;
    virtual vx_ui_ui::Type_image image_background() const override;
    virtual vx_ui_ui::Type_layout layout() const override;
    virtual vx_ui_ui::Type_styletype type() const override;
    virtual vx_ui_ui::Type_pin pin() const override;
    virtual vx_ui_ui::Type_point pointpos() const override;
    virtual vx_ui_ui::Type_point pointrotate() const override;
    virtual vx_ui_ui::Type_point pointsize() const override;
    virtual vx_core::Type_boolean scroll_x() const override;
    virtual vx_core::Type_boolean scroll_y() const override;
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
    // fontfacemap()
    vx_ui_ui::Type_fontfacemap vx_p_fontfacemap = NULL;
    virtual vx_ui_ui::Type_fontfacemap fontfacemap() const = 0;
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
    virtual vx_ui_ui::Type_fontfacemap fontfacemap() const override;
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
    // uid()
    vx_core::Type_string vx_p_uid = NULL;
    virtual vx_core::Type_string uid() const = 0;
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
    // layout()
    vx_ui_ui::Type_layout vx_p_layout = NULL;
    virtual vx_ui_ui::Type_layout layout() const = 0;
    // parent()
    vx_core::Type_string vx_p_parent = NULL;
    virtual vx_core::Type_string parent() const = 0;
    // path()
    vx_core::Type_string vx_p_path = NULL;
    virtual vx_core::Type_string path() const = 0;
    // hidden()
    vx_core::Type_boolean vx_p_hidden = NULL;
    virtual vx_core::Type_boolean hidden() const = 0;
    // selected()
    vx_core::Type_boolean vx_p_selected = NULL;
    virtual vx_core::Type_boolean selected() const = 0;
    // selectmulti()
    vx_core::Type_boolean vx_p_selectmulti = NULL;
    virtual vx_core::Type_boolean selectmulti() const = 0;
    // style()
    vx_ui_ui::Type_style vx_p_style = NULL;
    virtual vx_ui_ui::Type_style style() const = 0;
    // stylelist()
    vx_ui_ui::Type_stylelist vx_p_stylelist = NULL;
    virtual vx_ui_ui::Type_stylelist stylelist() const = 0;
    // eventmap()
    vx_event::Type_eventmap vx_p_eventmap = NULL;
    virtual vx_event::Type_eventmap eventmap() const = 0;
    // data()
    vx_core::Type_any vx_p_data = NULL;
    virtual vx_core::Type_any data() const = 0;
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
    virtual vx_core::Type_string uid() const override;
    virtual vx_core::Type_string name() const override;
    virtual vx_ui_ui::Type_layout layout() const override;
    virtual vx_core::Type_string parent() const override;
    virtual vx_core::Type_string path() const override;
    virtual vx_core::Type_boolean hidden() const override;
    virtual vx_core::Type_boolean selected() const override;
    virtual vx_core::Type_boolean selectmulti() const override;
    virtual vx_ui_ui::Type_style style() const override;
    virtual vx_ui_ui::Type_stylelist stylelist() const override;
    virtual vx_event::Type_eventmap eventmap() const override;
    virtual vx_core::Type_any data() const override;
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

  // (const align-center)
  class Class_align_center : public vx_ui_ui::Class_align {
  public:
    static void vx_const_new(vx_ui_ui::Const_align_center output);
  };

  // (const align-left)
  class Class_align_left : public vx_ui_ui::Class_align {
  public:
    static void vx_const_new(vx_ui_ui::Const_align_left output);
  };

  // (const align-right)
  class Class_align_right : public vx_ui_ui::Class_align {
  public:
    static void vx_const_new(vx_ui_ui::Const_align_right output);
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

  // (const layout-button)
  class Class_layout_button : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_ui::Const_layout_button output);
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

  // (const layout-flow-item)
  class Class_layout_flow_item : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_ui::Const_layout_flow_item output);
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

  // (const layout-titlebar)
  class Class_layout_titlebar : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_ui::Const_layout_titlebar output);
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

  // (const pointtype-absolute)
  class Class_pointtype_absolute : public vx_ui_ui::Class_pointtype {
  public:
    static void vx_const_new(vx_ui_ui::Const_pointtype_absolute output);
  };

  // (const pointtype-percent)
  class Class_pointtype_percent : public vx_ui_ui::Class_pointtype {
  public:
    static void vx_const_new(vx_ui_ui::Const_pointtype_percent output);
  };

  // (const pointtype-relative)
  class Class_pointtype_relative : public vx_ui_ui::Class_pointtype {
  public:
    static void vx_const_new(vx_ui_ui::Const_pointtype_relative output);
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

  // (func boolean-print)
  class Abstract_boolean_print : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_boolean_print() {};
    virtual ~Abstract_boolean_print() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_boolean_print : public virtual Abstract_boolean_print {
  public:
    Class_boolean_print();
    virtual ~Class_boolean_print() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func boolean-writestate<-ui)
  class Abstract_boolean_writestate_from_ui : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_boolean_writestate_from_ui() {};
    virtual ~Abstract_boolean_writestate_from_ui() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_boolean_writestate_from_ui : public virtual Abstract_boolean_writestate_from_ui {
  public:
    Class_boolean_writestate_from_ui();
    virtual ~Class_boolean_writestate_from_ui() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func boolean-writestate<-uiengine)
  class Abstract_boolean_writestate_from_uiengine : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_boolean_writestate_from_uiengine() {};
    virtual ~Abstract_boolean_writestate_from_uiengine() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_boolean_writestate_from_uiengine : public virtual Abstract_boolean_writestate_from_uiengine {
  public:
    Class_boolean_writestate_from_uiengine();
    virtual ~Class_boolean_writestate_from_uiengine() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func fontfacemap<-fontfacelist)
  class Abstract_fontfacemap_from_fontfacelist : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_fontfacemap_from_fontfacelist() {};
    virtual ~Abstract_fontfacemap_from_fontfacelist() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_fontfacemap_from_fontfacelist : public virtual Abstract_fontfacemap_from_fontfacelist {
  public:
    Class_fontfacemap_from_fontfacelist();
    virtual ~Class_fontfacemap_from_fontfacelist() override;
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

  // (func int-selected<-ui)
  class Abstract_int_selected_from_ui : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_int_selected_from_ui() {};
    virtual ~Abstract_int_selected_from_ui() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_int_selected_from_ui : public virtual Abstract_int_selected_from_ui {
  public:
    Class_int_selected_from_ui();
    virtual ~Class_int_selected_from_ui() override;
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

  // (func layout<-ui)
  class Abstract_layout_from_ui : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_layout_from_ui() {};
    virtual ~Abstract_layout_from_ui() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_layout_from_ui : public virtual Abstract_layout_from_ui {
  public:
    Class_layout_from_ui();
    virtual ~Class_layout_from_ui() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func layout<-ui-layoutengine)
  class Abstract_layout_from_ui_layoutengine : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_layout_from_ui_layoutengine() {};
    virtual ~Abstract_layout_from_ui_layoutengine() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_layout_from_ui_layoutengine : public virtual Abstract_layout_from_ui_layoutengine {
  public:
    Class_layout_from_ui_layoutengine();
    virtual ~Class_layout_from_ui_layoutengine() override;
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

  // (func layout<-ui-layoutmap-else)
  class Abstract_layout_from_ui_layoutmap_else : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_layout_from_ui_layoutmap_else() {};
    virtual ~Abstract_layout_from_ui_layoutmap_else() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_layout_from_ui_layoutmap_else : public virtual Abstract_layout_from_ui_layoutmap_else {
  public:
    Class_layout_from_ui_layoutmap_else();
    virtual ~Class_layout_from_ui_layoutmap_else() override;
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

  // (func layoutengine-readstate)
  class Abstract_layoutengine_readstate : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_layoutengine_readstate() {};
    virtual ~Abstract_layoutengine_readstate() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_layoutengine_readstate : public virtual Abstract_layoutengine_readstate {
  public:
    Class_layoutengine_readstate();
    virtual ~Class_layoutengine_readstate() override;
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

  // (func string-selected<-ui)
  class Abstract_string_selected_from_ui : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_selected_from_ui() {};
    virtual ~Abstract_string_selected_from_ui() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_selected_from_ui : public virtual Abstract_string_selected_from_ui {
  public:
    Class_string_selected_from_ui();
    virtual ~Class_string_selected_from_ui() override;
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

  // (func stringlist-selected<-ui)
  class Abstract_stringlist_selected_from_ui : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_stringlist_selected_from_ui() {};
    virtual ~Abstract_stringlist_selected_from_ui() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_stringlist_selected_from_ui : public virtual Abstract_stringlist_selected_from_ui {
  public:
    Class_stringlist_selected_from_ui();
    virtual ~Class_stringlist_selected_from_ui() override;
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

  // (func stringlist<-ui)
  class Abstract_stringlist_from_ui : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_stringlist_from_ui() {};
    virtual ~Abstract_stringlist_from_ui() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_stringlist_from_ui : public virtual Abstract_stringlist_from_ui {
  public:
    Class_stringlist_from_ui();
    virtual ~Class_stringlist_from_ui() override;
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

  // (func stylesheet-readstate)
  class Abstract_stylesheet_readstate : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_stylesheet_readstate() {};
    virtual ~Abstract_stylesheet_readstate() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_stylesheet_readstate : public virtual Abstract_stylesheet_readstate {
  public:
    Class_stylesheet_readstate();
    virtual ~Class_stylesheet_readstate() override;
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

  // (func ui-child<-ui-uid)
  class Abstract_ui_child_from_ui_uid : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_ui_child_from_ui_uid() {};
    virtual ~Abstract_ui_child_from_ui_uid() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_ui_child_from_ui_uid : public virtual Abstract_ui_child_from_ui_uid {
  public:
    Class_ui_child_from_ui_uid();
    virtual ~Class_ui_child_from_ui_uid() override;
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

  // (func ui-from<-event)
  class Abstract_ui_from_from_event : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_ui_from_from_event() {};
    virtual ~Abstract_ui_from_from_event() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_ui_from_from_event : public virtual Abstract_ui_from_from_event {
  public:
    Class_ui_from_from_event();
    virtual ~Class_ui_from_from_event() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func ui-layout<-ui)
  class Abstract_ui_layout_from_ui : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_ui_layout_from_ui() {};
    virtual ~Abstract_ui_layout_from_ui() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_ui_layout_from_ui : public virtual Abstract_ui_layout_from_ui {
  public:
    Class_ui_layout_from_ui();
    virtual ~Class_ui_layout_from_ui() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func ui-layout<-ui-layoutengine)
  class Abstract_ui_layout_from_ui_layoutengine : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_ui_layout_from_ui_layoutengine() {};
    virtual ~Abstract_ui_layout_from_ui_layoutengine() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_ui_layout_from_ui_layoutengine : public virtual Abstract_ui_layout_from_ui_layoutengine {
  public:
    Class_ui_layout_from_ui_layoutengine();
    virtual ~Class_ui_layout_from_ui_layoutengine() override;
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

  // (func ui-layout<-ui-uiengine)
  class Abstract_ui_layout_from_ui_uiengine : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_ui_layout_from_ui_uiengine() {};
    virtual ~Abstract_ui_layout_from_ui_uiengine() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_ui_layout_from_ui_uiengine : public virtual Abstract_ui_layout_from_ui_uiengine {
  public:
    Class_ui_layout_from_ui_uiengine();
    virtual ~Class_ui_layout_from_ui_uiengine() override;
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

  // (func ui-readstate<-uid)
  class Abstract_ui_readstate_from_uid : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_ui_readstate_from_uid() {};
    virtual ~Abstract_ui_readstate_from_uid() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_ui_readstate_from_uid : public virtual Abstract_ui_readstate_from_uid {
  public:
    Class_ui_readstate_from_uid();
    virtual ~Class_ui_readstate_from_uid() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override;
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

  // (func ui-render<-ui-parent-selected)
  class Abstract_ui_render_from_ui_parent_selected : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_ui_render_from_ui_parent_selected() {};
    virtual ~Abstract_ui_render_from_ui_parent_selected() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_ui_render_from_ui_parent_selected : public virtual Abstract_ui_render_from_ui_parent_selected {
  public:
    Class_ui_render_from_ui_parent_selected();
    virtual ~Class_ui_render_from_ui_parent_selected() override;
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

  // (func ui-selected<-ui)
  class Abstract_ui_selected_from_ui : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_ui_selected_from_ui() {};
    virtual ~Abstract_ui_selected_from_ui() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_ui_selected_from_ui : public virtual Abstract_ui_selected_from_ui {
  public:
    Class_ui_selected_from_ui();
    virtual ~Class_ui_selected_from_ui() override;
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

  // (func ui-writechild<-ui-child)
  class Abstract_ui_writechild_from_ui_child : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_ui_writechild_from_ui_child() {};
    virtual ~Abstract_ui_writechild_from_ui_child() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_ui_writechild_from_ui_child : public virtual Abstract_ui_writechild_from_ui_child {
  public:
    Class_ui_writechild_from_ui_child();
    virtual ~Class_ui_writechild_from_ui_child() override;
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

  // (func ui-writechildmap<-ui-childmap)
  class Abstract_ui_writechildmap_from_ui_childmap : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_ui_writechildmap_from_ui_childmap() {};
    virtual ~Abstract_ui_writechildmap_from_ui_childmap() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_ui_writechildmap_from_ui_childmap : public virtual Abstract_ui_writechildmap_from_ui_childmap {
  public:
    Class_ui_writechildmap_from_ui_childmap();
    virtual ~Class_ui_writechildmap_from_ui_childmap() override;
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

  // (func ui<-layout-ui-orig-parent)
  class Abstract_ui_from_layout_ui_orig_parent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_ui_from_layout_ui_orig_parent() {};
    virtual ~Abstract_ui_from_layout_ui_orig_parent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_ui_from_layout_ui_orig_parent : public virtual Abstract_ui_from_layout_ui_orig_parent {
  public:
    Class_ui_from_layout_ui_orig_parent();
    virtual ~Class_ui_from_layout_ui_orig_parent() override;
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

  // (func ui<-ui-selected)
  class Abstract_ui_from_ui_selected : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_ui_from_ui_selected() {};
    virtual ~Abstract_ui_from_ui_selected() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_ui_from_ui_selected : public virtual Abstract_ui_from_ui_selected {
  public:
    Class_ui_from_ui_selected();
    virtual ~Class_ui_from_ui_selected() override;
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

  // (func uid-selected<-ui)
  class Abstract_uid_selected_from_ui : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_uid_selected_from_ui() {};
    virtual ~Abstract_uid_selected_from_ui() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_uid_selected_from_ui : public virtual Abstract_uid_selected_from_ui {
  public:
    Class_uid_selected_from_ui();
    virtual ~Class_uid_selected_from_ui() override;
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

  // (func uiengine-readstate)
  class Abstract_uiengine_readstate : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_uiengine_readstate() {};
    virtual ~Abstract_uiengine_readstate() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_uiengine_readstate : public virtual Abstract_uiengine_readstate {
  public:
    Class_uiengine_readstate();
    virtual ~Class_uiengine_readstate() override;
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
  class Abstract_uiengine_render : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_uiengine_render() {};
    virtual ~Abstract_uiengine_render() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
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
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func uilist-selected<-ui)
  class Abstract_uilist_selected_from_ui : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_uilist_selected_from_ui() {};
    virtual ~Abstract_uilist_selected_from_ui() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_uilist_selected_from_ui : public virtual Abstract_uilist_selected_from_ui {
  public:
    Class_uilist_selected_from_ui();
    virtual ~Class_uilist_selected_from_ui() override;
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

  // (func uilist<-uimap)
  class Abstract_uilist_from_uimap : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_uilist_from_uimap() {};
    virtual ~Abstract_uilist_from_uimap() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_uilist_from_uimap : public virtual Abstract_uilist_from_uimap {
  public:
    Class_uilist_from_uimap();
    virtual ~Class_uilist_from_uimap() override;
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
