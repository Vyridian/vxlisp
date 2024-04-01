#ifndef VX_UI_HTML_UIHTML_HPP
#define VX_UI_HTML_UIHTML_HPP
#include "../../../vx/core.hpp"
#include "../../../vx/data/file.hpp"
#include "../../../vx/web/html.hpp"
#include "../../../vx/web/htmldoc.hpp"
#include "../../../vx/event.hpp"
#include "../../../vx/type.hpp"
#include "../../../vx/ui/ui.hpp"

namespace vx_ui_html_uihtml {


  // forward declarations
  class Class_layout_app_html;
  typedef Class_layout_app_html* Const_layout_app_html;
  extern Const_layout_app_html c_layout_app_html;
  class Class_layout_else_html;
  typedef Class_layout_else_html* Const_layout_else_html;
  extern Const_layout_else_html c_layout_else_html;
  class Class_layout_label_html;
  typedef Class_layout_label_html* Const_layout_label_html;
  extern Const_layout_label_html c_layout_label_html;
  class Class_layoutenginehtml;
  typedef Class_layoutenginehtml* Const_layoutenginehtml;
  extern Const_layoutenginehtml c_layoutenginehtml;
  class Class_style_hidden;
  typedef Class_style_hidden* Const_style_hidden;
  extern Const_style_hidden c_style_hidden;
  class Class_style_selected;
  typedef Class_style_selected* Const_style_selected;
  extern Const_style_selected c_style_selected;
  class Abstract_boolean_print_html;
  typedef Abstract_boolean_print_html* Func_boolean_print_html;
  extern Func_boolean_print_html e_boolean_print_html;
  extern Func_boolean_print_html t_boolean_print_html;
  class Abstract_context_write;
  typedef Abstract_context_write* Func_context_write;
  extern Func_context_write e_context_write;
  extern Func_context_write t_context_write;
  class Abstract_divchild_from_ui;
  typedef Abstract_divchild_from_ui* Func_divchild_from_ui;
  extern Func_divchild_from_ui e_divchild_from_ui;
  extern Func_divchild_from_ui t_divchild_from_ui;
  class Abstract_divchildlist_from_uimap;
  typedef Abstract_divchildlist_from_uimap* Func_divchildlist_from_uimap;
  extern Func_divchildlist_from_uimap e_divchildlist_from_uimap;
  extern Func_divchildlist_from_uimap t_divchildlist_from_uimap;
  class Abstract_node_app_from_ui_orig_parent;
  typedef Abstract_node_app_from_ui_orig_parent* Func_node_app_from_ui_orig_parent;
  extern Func_node_app_from_ui_orig_parent e_node_app_from_ui_orig_parent;
  extern Func_node_app_from_ui_orig_parent t_node_app_from_ui_orig_parent;
  class Abstract_node_render_from_node_ui;
  typedef Abstract_node_render_from_node_ui* Func_node_render_from_node_ui;
  extern Func_node_render_from_node_ui e_node_render_from_node_ui;
  extern Func_node_render_from_node_ui t_node_render_from_node_ui;
  class Abstract_string_style_from_font;
  typedef Abstract_string_style_from_font* Func_string_style_from_font;
  extern Func_string_style_from_font e_string_style_from_font;
  extern Func_string_style_from_font t_string_style_from_font;
  class Abstract_string_style_from_image;
  typedef Abstract_string_style_from_image* Func_string_style_from_image;
  extern Func_string_style_from_image e_string_style_from_image;
  extern Func_string_style_from_image t_string_style_from_image;
  class Abstract_string_stylename_from_name_styletype;
  typedef Abstract_string_stylename_from_name_styletype* Func_string_stylename_from_name_styletype;
  extern Func_string_stylename_from_name_styletype e_string_stylename_from_name_styletype;
  extern Func_string_stylename_from_name_styletype t_string_stylename_from_name_styletype;
  class Abstract_style_from_fontface;
  typedef Abstract_style_from_fontface* Func_style_from_fontface;
  extern Func_style_from_fontface e_style_from_fontface;
  extern Func_style_from_fontface t_style_from_fontface;
  class Abstract_style_from_style;
  typedef Abstract_style_from_style* Func_style_from_style;
  extern Func_style_from_style e_style_from_style;
  extern Func_style_from_style t_style_from_style;
  class Abstract_stylelist_extra_from_ui;
  typedef Abstract_stylelist_extra_from_ui* Func_stylelist_extra_from_ui;
  extern Func_stylelist_extra_from_ui e_stylelist_extra_from_ui;
  extern Func_stylelist_extra_from_ui t_stylelist_extra_from_ui;
  class Abstract_stylelist_reset;
  typedef Abstract_stylelist_reset* Func_stylelist_reset;
  extern Func_stylelist_reset e_stylelist_reset;
  extern Func_stylelist_reset t_stylelist_reset;
  class Abstract_stylelist_from_fontfacemap;
  typedef Abstract_stylelist_from_fontfacemap* Func_stylelist_from_fontfacemap;
  extern Func_stylelist_from_fontfacemap e_stylelist_from_fontfacemap;
  extern Func_stylelist_from_fontfacemap t_stylelist_from_fontfacemap;
  class Abstract_stylelist_from_stylelist;
  typedef Abstract_stylelist_from_stylelist* Func_stylelist_from_stylelist;
  extern Func_stylelist_from_stylelist e_stylelist_from_stylelist;
  extern Func_stylelist_from_stylelist t_stylelist_from_stylelist;
  class Abstract_stylelist_from_stylemap;
  typedef Abstract_stylelist_from_stylemap* Func_stylelist_from_stylemap;
  extern Func_stylelist_from_stylemap e_stylelist_from_stylemap;
  extern Func_stylelist_from_stylemap t_stylelist_from_stylemap;
  class Abstract_stylemap_from_stylemap;
  typedef Abstract_stylemap_from_stylemap* Func_stylemap_from_stylemap;
  extern Func_stylemap_from_stylemap e_stylemap_from_stylemap;
  extern Func_stylemap_from_stylemap t_stylemap_from_stylemap;
  class Abstract_stylesheet_render_html;
  typedef Abstract_stylesheet_render_html* Func_stylesheet_render_html;
  extern Func_stylesheet_render_html e_stylesheet_render_html;
  extern Func_stylesheet_render_html t_stylesheet_render_html;
  class Abstract_stylesheet_from_stylesheet;
  typedef Abstract_stylesheet_from_stylesheet* Func_stylesheet_from_stylesheet;
  extern Func_stylesheet_from_stylesheet e_stylesheet_from_stylesheet;
  extern Func_stylesheet_from_stylesheet t_stylesheet_from_stylesheet;
  class Abstract_ui_render_app_from_ui_orig_parent;
  typedef Abstract_ui_render_app_from_ui_orig_parent* Func_ui_render_app_from_ui_orig_parent;
  extern Func_ui_render_app_from_ui_orig_parent e_ui_render_app_from_ui_orig_parent;
  extern Func_ui_render_app_from_ui_orig_parent t_ui_render_app_from_ui_orig_parent;
  class Abstract_ui_render_default_from_ui_orig_parent;
  typedef Abstract_ui_render_default_from_ui_orig_parent* Func_ui_render_default_from_ui_orig_parent;
  extern Func_ui_render_default_from_ui_orig_parent e_ui_render_default_from_ui_orig_parent;
  extern Func_ui_render_default_from_ui_orig_parent t_ui_render_default_from_ui_orig_parent;
  class Abstract_ui_render_label_from_ui_orig_parent;
  typedef Abstract_ui_render_label_from_ui_orig_parent* Func_ui_render_label_from_ui_orig_parent;
  extern Func_ui_render_label_from_ui_orig_parent e_ui_render_label_from_ui_orig_parent;
  extern Func_ui_render_label_from_ui_orig_parent t_ui_render_label_from_ui_orig_parent;
  // (func boolean-print-html)
  vx_core::Type_boolean f_boolean_print_html(vx_core::Type_context context, vx_ui_ui::Type_ui ui);

  // (func context-write)
  vx_core::Type_context f_context_write(vx_core::Type_context context);

  // (func divchild<-ui)
  vx_web_html::Type_divchild f_divchild_from_ui(vx_ui_ui::Type_ui ui);

  // (func divchildlist<-uimap)
  vx_web_html::Type_divchildlist f_divchildlist_from_uimap(vx_ui_ui::Type_uimap uimap);

  // (func node-app<-ui-orig-parent)
  vx_web_html::Type_node f_node_app_from_ui_orig_parent(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_ui orig, vx_ui_ui::Type_ui parent);

  // (func node-render<-node-ui)
  vx_web_html::Type_node f_node_render_from_node_ui(vx_web_html::Type_node node, vx_ui_ui::Type_ui ui);

  // (func string-style<-font)
  vx_core::Type_string f_string_style_from_font(vx_ui_ui::Type_font font);

  // (func string-style<-image)
  vx_core::Type_string f_string_style_from_image(vx_ui_ui::Type_image image);

  // (func string-stylename<-name-styletype)
  vx_core::Type_string f_string_stylename_from_name_styletype(vx_core::Type_string name, vx_ui_ui::Type_styletype styletype);

  // (func style<-fontface)
  vx_web_html::Type_style f_style_from_fontface(vx_ui_ui::Type_fontface fontface);

  // (func style<-style)
  vx_web_html::Type_style f_style_from_style(vx_ui_ui::Type_style uistyle);

  // (func stylelist-extra<-ui)
  vx_web_html::Type_stylelist f_stylelist_extra_from_ui(vx_ui_ui::Type_ui ui);

  // (func stylelist-reset)
  vx_web_html::Type_stylelist f_stylelist_reset();

  // (func stylelist<-fontfacemap)
  vx_web_html::Type_stylelist f_stylelist_from_fontfacemap(vx_ui_ui::Type_fontfacemap fontfacemap);

  // (func stylelist<-stylelist)
  vx_web_html::Type_stylelist f_stylelist_from_stylelist(vx_ui_ui::Type_stylelist uistylelist);

  // (func stylelist<-stylemap)
  vx_web_html::Type_stylelist f_stylelist_from_stylemap(vx_ui_ui::Type_stylemap uistylemap);

  // (func stylemap<-stylemap)
  vx_web_html::Type_stylemap f_stylemap_from_stylemap(vx_ui_ui::Type_stylemap uistylemap);

  // (func stylesheet-render-html)
  vx_core::vx_Type_async f_stylesheet_render_html(vx_ui_ui::Type_stylesheet stylesheetui);

  // (func stylesheet<-stylesheet)
  vx_web_html::Type_stylesheet f_stylesheet_from_stylesheet(vx_ui_ui::Type_stylesheet uistylesheet);

  // (func ui-render-app<-ui-orig-parent)
  vx_ui_ui::Type_ui f_ui_render_app_from_ui_orig_parent(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_ui orig, vx_ui_ui::Type_ui parent);

  // (func ui-render-default<-ui-orig-parent)
  vx_ui_ui::Type_ui f_ui_render_default_from_ui_orig_parent(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_ui orig, vx_ui_ui::Type_ui parent);

  // (func ui-render-label<-ui-orig-parent)
  vx_ui_ui::Type_ui f_ui_render_label_from_ui_orig_parent(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_ui orig, vx_ui_ui::Type_ui parent);

  // (const layout-app-html)
  class Class_layout_app_html : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_html_uihtml::Const_layout_app_html output);
  };

  // (const layout-else-html)
  class Class_layout_else_html : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_html_uihtml::Const_layout_else_html output);
  };

  // (const layout-label-html)
  class Class_layout_label_html : public vx_ui_ui::Class_layout {
  public:
    static void vx_const_new(vx_ui_html_uihtml::Const_layout_label_html output);
  };

  // (const layoutenginehtml)
  class Class_layoutenginehtml : public vx_ui_ui::Class_layoutengine {
  public:
    static void vx_const_new(vx_ui_html_uihtml::Const_layoutenginehtml output);
  };

  // (const style-hidden)
  class Class_style_hidden : public vx_web_html::Class_style {
  public:
    static void vx_const_new(vx_ui_html_uihtml::Const_style_hidden output);
  };

  // (const style-selected)
  class Class_style_selected : public vx_web_html::Class_style {
  public:
    static void vx_const_new(vx_ui_html_uihtml::Const_style_selected output);
  };

  // (func boolean-print-html)
  class Abstract_boolean_print_html : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_boolean_print_html() {};
    virtual ~Abstract_boolean_print_html() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_boolean_print_html : public virtual Abstract_boolean_print_html {
  public:
    Class_boolean_print_html();
    virtual ~Class_boolean_print_html() override;
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

  // (func context-write)
  class Abstract_context_write : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_context_write() {};
    virtual ~Abstract_context_write() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_context_write : public virtual Abstract_context_write {
  public:
    Class_context_write();
    virtual ~Class_context_write() override;
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

  // (func divchild<-ui)
  class Abstract_divchild_from_ui : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_divchild_from_ui() {};
    virtual ~Abstract_divchild_from_ui() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_divchild_from_ui : public virtual Abstract_divchild_from_ui {
  public:
    Class_divchild_from_ui();
    virtual ~Class_divchild_from_ui() override;
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

  // (func divchildlist<-uimap)
  class Abstract_divchildlist_from_uimap : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_divchildlist_from_uimap() {};
    virtual ~Abstract_divchildlist_from_uimap() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_divchildlist_from_uimap : public virtual Abstract_divchildlist_from_uimap {
  public:
    Class_divchildlist_from_uimap();
    virtual ~Class_divchildlist_from_uimap() override;
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

  // (func node-app<-ui-orig-parent)
  class Abstract_node_app_from_ui_orig_parent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_node_app_from_ui_orig_parent() {};
    virtual ~Abstract_node_app_from_ui_orig_parent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_node_app_from_ui_orig_parent : public virtual Abstract_node_app_from_ui_orig_parent {
  public:
    Class_node_app_from_ui_orig_parent();
    virtual ~Class_node_app_from_ui_orig_parent() override;
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

  // (func node-render<-node-ui)
  class Abstract_node_render_from_node_ui : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_node_render_from_node_ui() {};
    virtual ~Abstract_node_render_from_node_ui() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_node_render_from_node_ui : public virtual Abstract_node_render_from_node_ui {
  public:
    Class_node_render_from_node_ui();
    virtual ~Class_node_render_from_node_ui() override;
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

  // (func string-style<-font)
  class Abstract_string_style_from_font : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_style_from_font() {};
    virtual ~Abstract_string_style_from_font() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_style_from_font : public virtual Abstract_string_style_from_font {
  public:
    Class_string_style_from_font();
    virtual ~Class_string_style_from_font() override;
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

  // (func string-style<-image)
  class Abstract_string_style_from_image : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_style_from_image() {};
    virtual ~Abstract_string_style_from_image() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_style_from_image : public virtual Abstract_string_style_from_image {
  public:
    Class_string_style_from_image();
    virtual ~Class_string_style_from_image() override;
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

  // (func string-stylename<-name-styletype)
  class Abstract_string_stylename_from_name_styletype : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_stylename_from_name_styletype() {};
    virtual ~Abstract_string_stylename_from_name_styletype() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_stylename_from_name_styletype : public virtual Abstract_string_stylename_from_name_styletype {
  public:
    Class_string_stylename_from_name_styletype();
    virtual ~Class_string_stylename_from_name_styletype() override;
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

  // (func style<-fontface)
  class Abstract_style_from_fontface : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_style_from_fontface() {};
    virtual ~Abstract_style_from_fontface() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_style_from_fontface : public virtual Abstract_style_from_fontface {
  public:
    Class_style_from_fontface();
    virtual ~Class_style_from_fontface() override;
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

  // (func style<-style)
  class Abstract_style_from_style : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_style_from_style() {};
    virtual ~Abstract_style_from_style() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_style_from_style : public virtual Abstract_style_from_style {
  public:
    Class_style_from_style();
    virtual ~Class_style_from_style() override;
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

  // (func stylelist-extra<-ui)
  class Abstract_stylelist_extra_from_ui : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_stylelist_extra_from_ui() {};
    virtual ~Abstract_stylelist_extra_from_ui() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_stylelist_extra_from_ui : public virtual Abstract_stylelist_extra_from_ui {
  public:
    Class_stylelist_extra_from_ui();
    virtual ~Class_stylelist_extra_from_ui() override;
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

  // (func stylelist-reset)
  class Abstract_stylelist_reset : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_stylelist_reset() {};
    virtual ~Abstract_stylelist_reset() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_stylelist_reset : public virtual Abstract_stylelist_reset {
  public:
    Class_stylelist_reset();
    virtual ~Class_stylelist_reset() override;
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

  // (func stylelist<-fontfacemap)
  class Abstract_stylelist_from_fontfacemap : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_stylelist_from_fontfacemap() {};
    virtual ~Abstract_stylelist_from_fontfacemap() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_stylelist_from_fontfacemap : public virtual Abstract_stylelist_from_fontfacemap {
  public:
    Class_stylelist_from_fontfacemap();
    virtual ~Class_stylelist_from_fontfacemap() override;
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

  // (func stylelist<-stylelist)
  class Abstract_stylelist_from_stylelist : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_stylelist_from_stylelist() {};
    virtual ~Abstract_stylelist_from_stylelist() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_stylelist_from_stylelist : public virtual Abstract_stylelist_from_stylelist {
  public:
    Class_stylelist_from_stylelist();
    virtual ~Class_stylelist_from_stylelist() override;
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

  // (func stylelist<-stylemap)
  class Abstract_stylelist_from_stylemap : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_stylelist_from_stylemap() {};
    virtual ~Abstract_stylelist_from_stylemap() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_stylelist_from_stylemap : public virtual Abstract_stylelist_from_stylemap {
  public:
    Class_stylelist_from_stylemap();
    virtual ~Class_stylelist_from_stylemap() override;
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

  // (func stylemap<-stylemap)
  class Abstract_stylemap_from_stylemap : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_stylemap_from_stylemap() {};
    virtual ~Abstract_stylemap_from_stylemap() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_stylemap_from_stylemap : public virtual Abstract_stylemap_from_stylemap {
  public:
    Class_stylemap_from_stylemap();
    virtual ~Class_stylemap_from_stylemap() override;
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

  // (func stylesheet-render-html)
  class Abstract_stylesheet_render_html : public vx_core::Abstract_any_from_any_async, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_stylesheet_render_html() {};
    virtual ~Abstract_stylesheet_render_html() = 0;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const override = 0;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const override = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_stylesheet_render_html : public virtual Abstract_stylesheet_render_html {
  public:
    Class_stylesheet_render_html();
    virtual ~Class_stylesheet_render_html() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const override;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const override;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func stylesheet<-stylesheet)
  class Abstract_stylesheet_from_stylesheet : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_stylesheet_from_stylesheet() {};
    virtual ~Abstract_stylesheet_from_stylesheet() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_stylesheet_from_stylesheet : public virtual Abstract_stylesheet_from_stylesheet {
  public:
    Class_stylesheet_from_stylesheet();
    virtual ~Class_stylesheet_from_stylesheet() override;
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

  // (func ui-render-app<-ui-orig-parent)
  class Abstract_ui_render_app_from_ui_orig_parent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_ui_render_app_from_ui_orig_parent() {};
    virtual ~Abstract_ui_render_app_from_ui_orig_parent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_ui_render_app_from_ui_orig_parent : public virtual Abstract_ui_render_app_from_ui_orig_parent {
  public:
    Class_ui_render_app_from_ui_orig_parent();
    virtual ~Class_ui_render_app_from_ui_orig_parent() override;
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

  // (func ui-render-default<-ui-orig-parent)
  class Abstract_ui_render_default_from_ui_orig_parent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_ui_render_default_from_ui_orig_parent() {};
    virtual ~Abstract_ui_render_default_from_ui_orig_parent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_ui_render_default_from_ui_orig_parent : public virtual Abstract_ui_render_default_from_ui_orig_parent {
  public:
    Class_ui_render_default_from_ui_orig_parent();
    virtual ~Class_ui_render_default_from_ui_orig_parent() override;
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

  // (func ui-render-label<-ui-orig-parent)
  class Abstract_ui_render_label_from_ui_orig_parent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_ui_render_label_from_ui_orig_parent() {};
    virtual ~Abstract_ui_render_label_from_ui_orig_parent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_ui_render_label_from_ui_orig_parent : public virtual Abstract_ui_render_label_from_ui_orig_parent {
  public:
    Class_ui_render_label_from_ui_orig_parent();
    virtual ~Class_ui_render_label_from_ui_orig_parent() override;
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
