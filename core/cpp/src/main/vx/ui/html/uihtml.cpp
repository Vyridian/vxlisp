#include "../../../vx/core.hpp"
#include "../../../vx/web/html.hpp"
#include "../../../vx/web/htmldoc.hpp"
#include "../../../vx/event.hpp"
#include "../../../vx/ui/ui.hpp"
#include "uihtml.hpp"

namespace vx_ui_html_uihtml {



  // (const layout-app-html)
  // class Class_layout_app_html {
    // vx_const_new()
    void vx_ui_html_uihtml::Class_layout_app_html::vx_const_new(vx_ui_html_uihtml::Const_layout_app_html output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/html/uihtml", "layout-app-html");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_copy(
        vx_ui_ui::t_layout,
        vx_ui_ui::c_layout_app,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":fn-layout"),
          vx_ui_html_uihtml::t_ui_render_app_from_ui_orig_parent
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_fn_layout = val->fn_layout();
      vx_core::vx_reserve(output->vx_p_fn_layout);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const layout-else-html)
  // class Class_layout_else_html {
    // vx_const_new()
    void vx_ui_html_uihtml::Class_layout_else_html::vx_const_new(vx_ui_html_uihtml::Const_layout_else_html output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/html/uihtml", "layout-else-html");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_copy(
        vx_ui_ui::t_layout,
        vx_ui_ui::c_layout_else,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":fn-layout"),
          vx_ui_html_uihtml::t_ui_render_default_from_ui_orig_parent
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_fn_layout = val->fn_layout();
      vx_core::vx_reserve(output->vx_p_fn_layout);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const layout-label-html)
  // class Class_layout_label_html {
    // vx_const_new()
    void vx_ui_html_uihtml::Class_layout_label_html::vx_const_new(vx_ui_html_uihtml::Const_layout_label_html output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/html/uihtml", "layout-label-html");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_copy(
        vx_ui_ui::t_layout,
        vx_ui_ui::c_layout_label,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":fn-layout"),
          vx_ui_html_uihtml::t_ui_render_label_from_ui_orig_parent
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_fn_layout = val->fn_layout();
      vx_core::vx_reserve(output->vx_p_fn_layout);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const layoutenginehtml)
  // class Class_layoutenginehtml {
    // vx_const_new()
    void vx_ui_html_uihtml::Class_layoutenginehtml::vx_const_new(vx_ui_html_uihtml::Const_layoutenginehtml output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/html/uihtml", "layoutenginehtml");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layoutengine val = vx_core::f_new(
        vx_ui_ui::t_layoutengine,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":layoutmap"),
          vx_ui_ui::f_layoutmap_from_layoutlist(
            vx_core::f_new(
              vx_ui_ui::t_layoutlist,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_ui_html_uihtml::c_layout_app_html,
                vx_ui_html_uihtml::c_layout_label_html
              })
            )
          ),
          vx_core::vx_new_string(":layoutelse"),
          vx_ui_html_uihtml::c_layout_else_html,
          vx_core::vx_new_string(":stylesheetrender"),
          vx_ui_html_uihtml::t_stylesheet_render_html
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_layoutmap = val->layoutmap();
      vx_core::vx_reserve(output->vx_p_layoutmap);
      output->vx_p_layoutelse = val->layoutelse();
      vx_core::vx_reserve(output->vx_p_layoutelse);
      output->vx_p_stylesheetrender = val->stylesheetrender();
      vx_core::vx_reserve(output->vx_p_stylesheetrender);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (func divchild<-ui)
  vx_web_html::Type_divchild f_divchild_from_ui(vx_ui_ui::Type_ui ui) {
    vx_web_html::Type_divchild output = vx_web_html::e_divchild;
    vx_core::vx_reserve(ui);
    output = vx_core::f_let(
      vx_web_html::t_div,
      vx_core::t_any_from_func->vx_fn_new({ui}, [ui]() {
        vx_core::Type_string uid = ui->uid();
        vx_core::vx_ref_plus(uid);
        vx_ui_ui::Type_uimap uimapchild = ui->uimap();
        vx_core::vx_ref_plus(uimapchild);
        vx_ui_ui::Type_style uistyle = ui->style();
        vx_core::vx_ref_plus(uistyle);
        vx_ui_ui::Type_stylelist uistyles = ui->stylelist();
        vx_core::vx_ref_plus(uistyles);
        vx_web_html::Type_style styleunique = vx_ui_html_uihtml::f_style_from_style(uistyle);
        vx_core::vx_ref_plus(styleunique);
        vx_web_html::Type_stylelist htmlstyles = vx_ui_html_uihtml::f_stylelist_from_stylelist(uistyles);
        vx_core::vx_ref_plus(htmlstyles);
        vx_web_html::Type_div output_1 = vx_core::f_new(
          vx_web_html::t_div,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":id"),
            uid,
            vx_core::vx_new_string(":style-unique"),
            styleunique,
            vx_core::vx_new_string(":stylelist"),
            htmlstyles
          })
        );
        vx_core::vx_release_one_except({uid, uimapchild, uistyle, uistyles, styleunique, htmlstyles}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(ui, output);
    return output;
  }

  // (func divchild<-ui)
  // class Class_divchild_from_ui {
    Abstract_divchild_from_ui::~Abstract_divchild_from_ui() {}

    Class_divchild_from_ui::Class_divchild_from_ui() : Abstract_divchild_from_ui::Abstract_divchild_from_ui() {
      vx_core::refcount += 1;
    }

    Class_divchild_from_ui::~Class_divchild_from_ui() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_divchild_from_ui::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_divchild_from_ui output = vx_ui_html_uihtml::e_divchild_from_ui;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_divchild_from_ui::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_divchild_from_ui output = vx_ui_html_uihtml::e_divchild_from_ui;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_divchild_from_ui::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "divchild<-ui", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_divchild_from_ui::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_divchild_from_ui::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "divchild<-ui", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_divchild_from_ui::vx_empty() const {return vx_ui_html_uihtml::e_divchild_from_ui;}
    vx_core::Type_any Class_divchild_from_ui::vx_type() const {return vx_ui_html_uihtml::t_divchild_from_ui;}
    vx_core::Type_msgblock Class_divchild_from_ui::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_divchild_from_ui::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_divchild_from_ui::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_divchild_from_ui::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui inputval = vx_core::vx_any_from_any(vx_ui_ui::t_ui, val);
      output = vx_ui_html_uihtml::f_divchild_from_ui(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_divchild_from_ui::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_html_uihtml::f_divchild_from_ui(ui);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func divchildlist<-uimap)
  vx_web_html::Type_divchildlist f_divchildlist_from_uimap(vx_ui_ui::Type_uimap uimap) {
    vx_web_html::Type_divchildlist output = vx_web_html::e_divchildlist;
    vx_core::vx_reserve(uimap);
    output = vx_core::f_list_from_map(
      vx_web_html::t_divchildlist,
      uimap,
      vx_core::t_any_from_key_value->vx_fn_new({}, [](vx_core::Type_any key_any, vx_core::Type_any value_any) {
        vx_core::Type_string key = vx_core::vx_any_from_any(vx_core::t_string, key_any);
        vx_ui_ui::Type_ui value = vx_core::vx_any_from_any(vx_ui_ui::t_ui, value_any);
        vx_core::Type_any output_1 = 
          vx_core::f_new(
            vx_web_html::t_div,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_core::vx_new_string(":id"),
              key
            })
          );
        return output_1;
      })
    );
    vx_core::vx_release_one_except(uimap, output);
    return output;
  }

  // (func divchildlist<-uimap)
  // class Class_divchildlist_from_uimap {
    Abstract_divchildlist_from_uimap::~Abstract_divchildlist_from_uimap() {}

    Class_divchildlist_from_uimap::Class_divchildlist_from_uimap() : Abstract_divchildlist_from_uimap::Abstract_divchildlist_from_uimap() {
      vx_core::refcount += 1;
    }

    Class_divchildlist_from_uimap::~Class_divchildlist_from_uimap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_divchildlist_from_uimap::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_divchildlist_from_uimap output = vx_ui_html_uihtml::e_divchildlist_from_uimap;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_divchildlist_from_uimap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_divchildlist_from_uimap output = vx_ui_html_uihtml::e_divchildlist_from_uimap;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_divchildlist_from_uimap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "divchildlist<-uimap", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_divchildlist_from_uimap::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_divchildlist_from_uimap::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "divchildlist<-uimap", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_divchildlist_from_uimap::vx_empty() const {return vx_ui_html_uihtml::e_divchildlist_from_uimap;}
    vx_core::Type_any Class_divchildlist_from_uimap::vx_type() const {return vx_ui_html_uihtml::t_divchildlist_from_uimap;}
    vx_core::Type_msgblock Class_divchildlist_from_uimap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_divchildlist_from_uimap::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_divchildlist_from_uimap::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_divchildlist_from_uimap::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_uimap inputval = vx_core::vx_any_from_any(vx_ui_ui::t_uimap, val);
      output = vx_ui_html_uihtml::f_divchildlist_from_uimap(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_divchildlist_from_uimap::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_uimap uimap = vx_core::vx_any_from_any(vx_ui_ui::t_uimap, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_html_uihtml::f_divchildlist_from_uimap(uimap);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func node-app<-ui-orig-parent)
  vx_web_html::Type_node f_node_app_from_ui_orig_parent(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_ui orig, vx_ui_ui::Type_ui parent) {
    vx_web_html::Type_node output = vx_web_html::e_node;
    vx_core::vx_reserve({ui, orig, parent});
    output = vx_core::f_empty(
      vx_web_html::t_div
    );
    vx_core::vx_release_one_except({ui, orig, parent}, output);
    return output;
  }

  // (func node-app<-ui-orig-parent)
  // class Class_node_app_from_ui_orig_parent {
    Abstract_node_app_from_ui_orig_parent::~Abstract_node_app_from_ui_orig_parent() {}

    Class_node_app_from_ui_orig_parent::Class_node_app_from_ui_orig_parent() : Abstract_node_app_from_ui_orig_parent::Abstract_node_app_from_ui_orig_parent() {
      vx_core::refcount += 1;
    }

    Class_node_app_from_ui_orig_parent::~Class_node_app_from_ui_orig_parent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_node_app_from_ui_orig_parent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_node_app_from_ui_orig_parent output = vx_ui_html_uihtml::e_node_app_from_ui_orig_parent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_node_app_from_ui_orig_parent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_node_app_from_ui_orig_parent output = vx_ui_html_uihtml::e_node_app_from_ui_orig_parent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_node_app_from_ui_orig_parent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "node-app<-ui-orig-parent", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_node_app_from_ui_orig_parent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_node_app_from_ui_orig_parent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "node-app<-ui-orig-parent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_node_app_from_ui_orig_parent::vx_empty() const {return vx_ui_html_uihtml::e_node_app_from_ui_orig_parent;}
    vx_core::Type_any Class_node_app_from_ui_orig_parent::vx_type() const {return vx_ui_html_uihtml::t_node_app_from_ui_orig_parent;}
    vx_core::Type_msgblock Class_node_app_from_ui_orig_parent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_node_app_from_ui_orig_parent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_node_app_from_ui_orig_parent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_ui orig = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_ui_ui::Type_ui parent = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_ui_html_uihtml::f_node_app_from_ui_orig_parent(ui, orig, parent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func node-render<-node-ui)
  vx_web_html::Type_node f_node_render_from_node_ui(vx_web_html::Type_node node, vx_ui_ui::Type_ui ui) {
    vx_web_html::Type_node output = vx_web_html::e_node;
    vx_core::vx_reserve({node, ui});
    output = vx_core::f_let(
      vx_web_html::t_node,
      vx_core::t_any_from_func->vx_fn_new({ui, node}, [ui, node]() {
        vx_core::Type_string uid = ui->uid();
        vx_core::vx_ref_plus(uid);
        vx_event::Type_eventmap eventmap = ui->eventmap();
        vx_core::vx_ref_plus(eventmap);
        vx_core::Type_string htmltext = vx_web_html::f_string_from_node_indent(node, vx_core::vx_new_int(2));
        vx_core::vx_ref_plus(htmltext);
        vx_core::Type_boolean htmldone = vx_web_htmldoc::f_boolean_replace_from_id_htmltext_data_eventmap(uid, htmltext, ui, eventmap);
        vx_core::vx_ref_plus(htmldone);
        vx_web_html::Type_node output_1 = node;
        vx_core::vx_release_one_except({uid, eventmap, htmltext, htmldone}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({node, ui}, output);
    return output;
  }

  // (func node-render<-node-ui)
  // class Class_node_render_from_node_ui {
    Abstract_node_render_from_node_ui::~Abstract_node_render_from_node_ui() {}

    Class_node_render_from_node_ui::Class_node_render_from_node_ui() : Abstract_node_render_from_node_ui::Abstract_node_render_from_node_ui() {
      vx_core::refcount += 1;
    }

    Class_node_render_from_node_ui::~Class_node_render_from_node_ui() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_node_render_from_node_ui::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_node_render_from_node_ui output = vx_ui_html_uihtml::e_node_render_from_node_ui;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_node_render_from_node_ui::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_node_render_from_node_ui output = vx_ui_html_uihtml::e_node_render_from_node_ui;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_node_render_from_node_ui::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "node-render<-node-ui", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_node_render_from_node_ui::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_node_render_from_node_ui::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "node-render<-node-ui", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_node_render_from_node_ui::vx_empty() const {return vx_ui_html_uihtml::e_node_render_from_node_ui;}
    vx_core::Type_any Class_node_render_from_node_ui::vx_type() const {return vx_ui_html_uihtml::t_node_render_from_node_ui;}
    vx_core::Type_msgblock Class_node_render_from_node_ui::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_node_render_from_node_ui::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_node_render_from_node_ui::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_node node = vx_core::vx_any_from_any(vx_web_html::t_node, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_ui_html_uihtml::f_node_render_from_node_ui(node, ui);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string-stylename<-name-styletype)
  vx_core::Type_string f_string_stylename_from_name_styletype(vx_core::Type_string name, vx_ui_ui::Type_styletype styletype) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({name, styletype});
    output = vx_core::f_if_2(
      vx_core::t_string,
      vx_core::vx_new(vx_core::t_thenelselist, {
        vx_core::f_then(
          vx_core::t_boolean_from_func->vx_fn_new({name}, [name]() {
            vx_core::Type_boolean output_1 = vx_core::f_eq(vx_core::vx_new_string(""), name);
            return output_1;
          }),
          vx_core::t_any_from_func->vx_fn_new({}, []() {
            vx_core::Type_string output_1 = vx_core::vx_new_string("");
            return output_1;
          })
        ),
        vx_core::f_then(
          vx_core::t_boolean_from_func->vx_fn_new({styletype}, [styletype]() {
            vx_core::Type_boolean output_1 = vx_core::f_eqeq(
              styletype,
              vx_ui_ui::c_styletype_shared
            );
            return output_1;
          }),
          vx_core::t_any_from_func->vx_fn_new({name}, [name]() {
            vx_core::Type_string output_1 = vx_core::f_new(
              vx_core::t_string,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string("."),
                name
              })
            );
            return output_1;
          })
        ),
        vx_core::f_then(
          vx_core::t_boolean_from_func->vx_fn_new({styletype}, [styletype]() {
            vx_core::Type_boolean output_1 = vx_core::f_eqeq(
              styletype,
              vx_ui_ui::c_styletype_system
            );
            return output_1;
          }),
          vx_core::t_any_from_func->vx_fn_new({name}, [name]() {
            vx_core::Type_any output_1 = name;
            return output_1;
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func->vx_fn_new({name}, [name]() {
            vx_core::Type_string output_1 = vx_core::f_new(
              vx_core::t_string,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string("#"),
                name
              })
            );
            return output_1;
          })
        )
      })
    );
    vx_core::vx_release_one_except({name, styletype}, output);
    return output;
  }

  // (func string-stylename<-name-styletype)
  // class Class_string_stylename_from_name_styletype {
    Abstract_string_stylename_from_name_styletype::~Abstract_string_stylename_from_name_styletype() {}

    Class_string_stylename_from_name_styletype::Class_string_stylename_from_name_styletype() : Abstract_string_stylename_from_name_styletype::Abstract_string_stylename_from_name_styletype() {
      vx_core::refcount += 1;
    }

    Class_string_stylename_from_name_styletype::~Class_string_stylename_from_name_styletype() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_stylename_from_name_styletype::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_string_stylename_from_name_styletype output = vx_ui_html_uihtml::e_string_stylename_from_name_styletype;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_stylename_from_name_styletype::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_string_stylename_from_name_styletype output = vx_ui_html_uihtml::e_string_stylename_from_name_styletype;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_stylename_from_name_styletype::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "string-stylename<-name-styletype", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_string_stylename_from_name_styletype::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_stylename_from_name_styletype::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "string-stylename<-name-styletype", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_stylename_from_name_styletype::vx_empty() const {return vx_ui_html_uihtml::e_string_stylename_from_name_styletype;}
    vx_core::Type_any Class_string_stylename_from_name_styletype::vx_type() const {return vx_ui_html_uihtml::t_string_stylename_from_name_styletype;}
    vx_core::Type_msgblock Class_string_stylename_from_name_styletype::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_stylename_from_name_styletype::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_stylename_from_name_styletype::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string name = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_styletype styletype = vx_core::vx_any_from_any(vx_ui_ui::t_styletype, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_ui_html_uihtml::f_string_stylename_from_name_styletype(name, styletype);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func style<-style)
  vx_web_html::Type_style f_style_from_style(vx_ui_ui::Type_style uistyle) {
    vx_web_html::Type_style output = vx_web_html::e_style;
    vx_core::vx_reserve(uistyle);
    output = vx_core::f_if_2(
      vx_web_html::t_style,
      vx_core::vx_new(vx_core::t_thenelselist, {
        vx_core::f_then(
          vx_core::t_boolean_from_func->vx_fn_new({uistyle}, [uistyle]() {
            vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(uistyle);
            return output_1;
          }),
          vx_core::t_any_from_func->vx_fn_new({}, []() {
            vx_core::Type_any output_1 = vx_core::f_empty(
              vx_web_html::t_style
            );
            return output_1;
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func->vx_fn_new({uistyle}, [uistyle]() {
            vx_web_html::Type_style output_1 = vx_core::f_let(
              vx_web_html::t_style,
              vx_core::t_any_from_func->vx_fn_new({uistyle}, [uistyle]() {
                vx_ui_ui::Type_layout layout = uistyle->layout();
                vx_core::vx_ref_plus(layout);
                vx_core::Type_string name = uistyle->name();
                vx_core::vx_ref_plus(name);
                vx_ui_ui::Type_pin pin = uistyle->pin();
                vx_core::vx_ref_plus(pin);
                vx_ui_ui::Type_point pointpos = uistyle->pointpos();
                vx_core::vx_ref_plus(pointpos);
                vx_ui_ui::Type_point pointsize = uistyle->pointsize();
                vx_core::vx_ref_plus(pointsize);
                vx_ui_ui::Type_styletype styletype = uistyle->type();
                vx_core::vx_ref_plus(styletype);
                vx_core::Type_string color_background = uistyle->color_background();
                vx_core::vx_ref_plus(color_background);
                vx_core::Type_string color_hoverbkgrd = uistyle->color_hoverbkgrd();
                vx_core::vx_ref_plus(color_hoverbkgrd);
                vx_core::Type_int posx = pointpos->x();
                vx_core::vx_ref_plus(posx);
                vx_core::Type_int posy = pointpos->y();
                vx_core::vx_ref_plus(posy);
                vx_core::Type_int sizex = pointsize->x();
                vx_core::vx_ref_plus(sizex);
                vx_core::Type_int sizey = pointsize->y();
                vx_core::vx_ref_plus(sizey);
                vx_core::Type_string stylename = vx_ui_html_uihtml::f_string_stylename_from_name_styletype(name, styletype);
                vx_core::vx_ref_plus(stylename);
                vx_core::Type_string backgroundcolor = vx_core::f_if_2(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({color_background}, [color_background]() {
                        vx_core::Type_boolean output_1 = vx_core::f_notempty(color_background);
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({color_background}, [color_background]() {
                        vx_core::Type_string output_1 = vx_core::f_new(
                          vx_core::t_string,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string("#"),
                            color_background
                          })
                        );
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(backgroundcolor);
                vx_core::Type_string position = vx_core::f_if_2(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({layout}, [layout]() {
                        vx_core::Type_boolean output_1 = vx_core::f_or_1(
                          vx_core::vx_new(vx_core::t_booleanlist, {
                            vx_core::f_eqeq(
                              layout,
                              vx_ui_ui::c_layout_app
                            ),
                            vx_core::f_eqeq(
                              layout,
                              vx_ui_ui::c_layout_background
                            ),
                            vx_core::f_eqeq(
                              layout,
                              vx_ui_ui::c_layout_main
                            ),
                            vx_core::f_eqeq(
                              layout,
                              vx_ui_ui::c_layout_navbar
                            ),
                            vx_core::f_eqeq(
                              layout,
                              vx_ui_ui::c_layout_parallax
                            ),
                            vx_core::f_eqeq(
                              layout,
                              vx_ui_ui::c_layout_statusbar
                            )
                          })
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("fixed");
                        return output_1;
                      })
                    ),
                    vx_core::f_else(
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("relative");
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(position);
                vx_core::Type_string top = vx_core::f_if_2(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({pin}, [pin]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(
                          pin,
                          vx_ui_ui::c_pin_expand
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({posy}, [posy]() {
                        vx_core::Type_string output_1 = vx_core::f_new(
                          vx_core::t_string,
                          vx_core::vx_new(vx_core::t_anylist, {
                            posy,
                            vx_core::vx_new_string("mm")
                          })
                        );
                        return output_1;
                      })
                    ),
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({posy}, [posy]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(vx_core::vx_new_int(0), posy);
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("");
                        return output_1;
                      })
                    ),
                    vx_core::f_else(
                      vx_core::t_any_from_func->vx_fn_new({posy}, [posy]() {
                        vx_core::Type_string output_1 = vx_core::f_new(
                          vx_core::t_string,
                          vx_core::vx_new(vx_core::t_anylist, {
                            posy,
                            vx_core::vx_new_string("mm")
                          })
                        );
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(top);
                vx_core::Type_string bottom = vx_core::f_if_2(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({pin}, [pin]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(
                          pin,
                          vx_ui_ui::c_pin_expand
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("");
                        return output_1;
                      })
                    ),
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({pin}, [pin]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(
                          pin,
                          vx_ui_ui::c_pin_bottom
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("0mm");
                        return output_1;
                      })
                    ),
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({pin}, [pin]() {
                        vx_core::Type_boolean output_1 = vx_core::f_or(
                          vx_core::f_eqeq(
                            pin,
                            vx_ui_ui::c_pin_left
                          ),
                          vx_core::f_eqeq(
                            pin,
                            vx_ui_ui::c_pin_center_v
                          )
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({sizey}, [sizey]() {
                        vx_core::Type_string output_1 = vx_core::f_new(
                          vx_core::t_string,
                          vx_core::vx_new(vx_core::t_anylist, {
                            sizey,
                            vx_core::vx_new_string("mm")
                          })
                        );
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(bottom);
                vx_core::Type_string left = vx_core::f_if_2(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({pin}, [pin]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(
                          pin,
                          vx_ui_ui::c_pin_expand
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("");
                        return output_1;
                      })
                    ),
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({pin}, [pin]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(
                          pin,
                          vx_ui_ui::c_pin_bottom
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({posx}, [posx]() {
                        vx_core::Type_string output_1 = vx_core::f_new(
                          vx_core::t_string,
                          vx_core::vx_new(vx_core::t_anylist, {
                            posx,
                            vx_core::vx_new_string("mm")
                          })
                        );
                        return output_1;
                      })
                    ),
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({posx}, [posx]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(vx_core::vx_new_int(0), posx);
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("");
                        return output_1;
                      })
                    ),
                    vx_core::f_else(
                      vx_core::t_any_from_func->vx_fn_new({posx}, [posx]() {
                        vx_core::Type_string output_1 = vx_core::f_new(
                          vx_core::t_string,
                          vx_core::vx_new(vx_core::t_anylist, {
                            posx,
                            vx_core::vx_new_string("mm")
                          })
                        );
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(left);
                vx_core::Type_string right = vx_core::f_if_2(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({pin}, [pin]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(
                          pin,
                          vx_ui_ui::c_pin_expand
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("");
                        return output_1;
                      })
                    ),
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({pin}, [pin]() {
                        vx_core::Type_boolean output_1 = vx_core::f_or_1(
                          vx_core::vx_new(vx_core::t_booleanlist, {
                            vx_core::f_eqeq(
                              pin,
                              vx_ui_ui::c_pin_top
                            ),
                            vx_core::f_eqeq(
                              pin,
                              vx_ui_ui::c_pin_bottom
                            ),
                            vx_core::f_eqeq(
                              pin,
                              vx_ui_ui::c_pin_center_v
                            )
                          })
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({sizex}, [sizex]() {
                        vx_core::Type_string output_1 = vx_core::f_new(
                          vx_core::t_string,
                          vx_core::vx_new(vx_core::t_anylist, {
                            sizex,
                            vx_core::vx_new_string("mm")
                          })
                        );
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(right);
                vx_core::Type_string height = vx_core::f_if_2(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({pin}, [pin]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(
                          pin,
                          vx_ui_ui::c_pin_expand
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("100%");
                        return output_1;
                      })
                    ),
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({pin}, [pin]() {
                        vx_core::Type_boolean output_1 = vx_core::f_or_1(
                          vx_core::vx_new(vx_core::t_booleanlist, {
                            vx_core::f_eqeq(
                              pin,
                              vx_ui_ui::c_pin_left
                            ),
                            vx_core::f_eqeq(
                              pin,
                              vx_ui_ui::c_pin_right
                            ),
                            vx_core::f_eqeq(
                              pin,
                              vx_ui_ui::c_pin_center_v
                            )
                          })
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("");
                        return output_1;
                      })
                    ),
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({sizey}, [sizey]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(vx_core::vx_new_int(0), sizey);
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("");
                        return output_1;
                      })
                    ),
                    vx_core::f_else(
                      vx_core::t_any_from_func->vx_fn_new({sizey}, [sizey]() {
                        vx_core::Type_string output_1 = vx_core::f_new(
                          vx_core::t_string,
                          vx_core::vx_new(vx_core::t_anylist, {
                            sizey,
                            vx_core::vx_new_string("mm")
                          })
                        );
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(height);
                vx_core::Type_string width = vx_core::f_if_2(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({pin}, [pin]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(
                          pin,
                          vx_ui_ui::c_pin_expand
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("100%");
                        return output_1;
                      })
                    ),
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({pin}, [pin]() {
                        vx_core::Type_boolean output_1 = vx_core::f_or_1(
                          vx_core::vx_new(vx_core::t_booleanlist, {
                            vx_core::f_eqeq(
                              pin,
                              vx_ui_ui::c_pin_top
                            ),
                            vx_core::f_eqeq(
                              pin,
                              vx_ui_ui::c_pin_bottom
                            ),
                            vx_core::f_eqeq(
                              pin,
                              vx_ui_ui::c_pin_center_v
                            )
                          })
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("");
                        return output_1;
                      })
                    ),
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({sizex}, [sizex]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(vx_core::vx_new_int(0), sizex);
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("");
                        return output_1;
                      })
                    ),
                    vx_core::f_else(
                      vx_core::t_any_from_func->vx_fn_new({sizex}, [sizex]() {
                        vx_core::Type_string output_1 = vx_core::f_new(
                          vx_core::t_string,
                          vx_core::vx_new(vx_core::t_anylist, {
                            sizex,
                            vx_core::vx_new_string("mm")
                          })
                        );
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(width);
                vx_core::Type_string display = vx_core::f_if_2(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({layout}, [layout]() {
                        vx_core::Type_boolean output_1 = vx_core::f_or(
                          vx_core::f_eqeq(
                            layout,
                            vx_ui_ui::c_layout_flow_columns
                          ),
                          vx_core::f_eqeq(
                            layout,
                            vx_ui_ui::c_layout_flow_rows
                          )
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("flex");
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(display);
                vx_core::Type_string flexflow = vx_core::f_if_2(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({layout}, [layout]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(
                          layout,
                          vx_ui_ui::c_layout_flow_columns
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("column wrap");
                        return output_1;
                      })
                    ),
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({layout}, [layout]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(
                          layout,
                          vx_ui_ui::c_layout_flow_rows
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("row wrap");
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(flexflow);
                vx_core::Type_string aligncontent = vx_core::f_if_2(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({layout}, [layout]() {
                        vx_core::Type_boolean output_1 = vx_core::f_or(
                          vx_core::f_eqeq(
                            layout,
                            vx_ui_ui::c_layout_flow_columns
                          ),
                          vx_core::f_eqeq(
                            layout,
                            vx_ui_ui::c_layout_flow_rows
                          )
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("flex-start");
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(aligncontent);
                vx_core::Type_string gap = vx_core::f_if_2(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({layout}, [layout]() {
                        vx_core::Type_boolean output_1 = vx_core::f_or(
                          vx_core::f_eqeq(
                            layout,
                            vx_ui_ui::c_layout_flow_columns
                          ),
                          vx_core::f_eqeq(
                            layout,
                            vx_ui_ui::c_layout_flow_rows
                          )
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("1mm");
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(gap);
                vx_core::Type_string overflowx = vx_core::f_if_2(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({layout}, [layout]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(
                          layout,
                          vx_ui_ui::c_layout_flow_rows
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("scroll");
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(overflowx);
                vx_core::Type_string overflowy = vx_core::f_if_2(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({layout}, [layout]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(
                          layout,
                          vx_ui_ui::c_layout_flow_columns
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("scroll");
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(overflowy);
                vx_core::Type_string hoverbkgrdcolor = vx_core::f_if_2(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({color_hoverbkgrd}, [color_hoverbkgrd]() {
                        vx_core::Type_boolean output_1 = vx_core::f_ne(vx_core::vx_new_string(""), color_hoverbkgrd);
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({color_hoverbkgrd}, [color_hoverbkgrd]() {
                        vx_core::Type_string output_1 = vx_core::f_new(
                          vx_core::t_string,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string("#"),
                            color_hoverbkgrd
                          })
                        );
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(hoverbkgrdcolor);
                vx_web_html::Type_propmap props = vx_core::f_new(
                  vx_web_html::t_propmap,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":background-color"),
                    backgroundcolor,
                    vx_core::vx_new_string(":display"),
                    display,
                    vx_core::vx_new_string(":flex-flow"),
                    flexflow,
                    vx_core::vx_new_string(":align-content"),
                    aligncontent,
                    vx_core::vx_new_string(":gap"),
                    gap,
                    vx_core::vx_new_string(":position"),
                    position,
                    vx_core::vx_new_string(":top"),
                    top,
                    vx_core::vx_new_string(":bottom"),
                    bottom,
                    vx_core::vx_new_string(":left"),
                    left,
                    vx_core::vx_new_string(":right"),
                    right,
                    vx_core::vx_new_string(":height"),
                    height,
                    vx_core::vx_new_string(":width"),
                    width,
                    vx_core::vx_new_string(":overflow-x"),
                    overflowx,
                    vx_core::vx_new_string(":overflow-y"),
                    overflowy
                  })
                );
                vx_core::vx_ref_plus(props);
                vx_web_html::Type_propmap hoverprops = vx_core::f_new(
                  vx_web_html::t_propmap,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":background-color"),
                    hoverbkgrdcolor
                  })
                );
                vx_core::vx_ref_plus(hoverprops);
                vx_web_html::Type_subpropmap subprops = vx_core::f_new(
                  vx_web_html::t_subpropmap,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string("&:hover"),
                    hoverprops
                  })
                );
                vx_core::vx_ref_plus(subprops);
                vx_web_html::Type_style output_1 = vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":name"),
                    stylename,
                    vx_core::vx_new_string(":props"),
                    props
                  })
                );
                vx_core::vx_release_one_except({layout, name, pin, pointpos, pointsize, styletype, color_background, color_hoverbkgrd, posx, posy, sizex, sizey, stylename, backgroundcolor, position, top, bottom, left, right, height, width, display, flexflow, aligncontent, gap, overflowx, overflowy, hoverbkgrdcolor, props, hoverprops, subprops}, output_1);
                return output_1;
              })
            );
            return output_1;
          })
        )
      })
    );
    vx_core::vx_release_one_except(uistyle, output);
    return output;
  }

  // (func style<-style)
  // class Class_style_from_style {
    Abstract_style_from_style::~Abstract_style_from_style() {}

    Class_style_from_style::Class_style_from_style() : Abstract_style_from_style::Abstract_style_from_style() {
      vx_core::refcount += 1;
    }

    Class_style_from_style::~Class_style_from_style() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_style_from_style::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_style_from_style output = vx_ui_html_uihtml::e_style_from_style;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_style_from_style::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_style_from_style output = vx_ui_html_uihtml::e_style_from_style;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_style_from_style::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "style<-style", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_style_from_style::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_style_from_style::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "style<-style", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_style_from_style::vx_empty() const {return vx_ui_html_uihtml::e_style_from_style;}
    vx_core::Type_any Class_style_from_style::vx_type() const {return vx_ui_html_uihtml::t_style_from_style;}
    vx_core::Type_msgblock Class_style_from_style::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_style_from_style::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_style_from_style::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_style_from_style::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_style inputval = vx_core::vx_any_from_any(vx_ui_ui::t_style, val);
      output = vx_ui_html_uihtml::f_style_from_style(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_style_from_style::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_style uistyle = vx_core::vx_any_from_any(vx_ui_ui::t_style, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_html_uihtml::f_style_from_style(uistyle);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func stylelist<-stylelist)
  vx_web_html::Type_stylelist f_stylelist_from_stylelist(vx_ui_ui::Type_stylelist uistylelist) {
    vx_web_html::Type_stylelist output = vx_web_html::e_stylelist;
    vx_core::vx_reserve(uistylelist);
    output = vx_core::f_list_from_list(
      vx_web_html::t_stylelist,
      uistylelist,
      vx_core::t_any_from_any->vx_fn_new({}, [](vx_core::Type_any uistyle_any) {
        vx_ui_ui::Type_style uistyle = vx_core::vx_any_from_any(vx_ui_ui::t_style, uistyle_any);
        vx_core::Type_any output_1 = vx_ui_html_uihtml::f_style_from_style(uistyle);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(uistylelist, output);
    return output;
  }

  // (func stylelist<-stylelist)
  // class Class_stylelist_from_stylelist {
    Abstract_stylelist_from_stylelist::~Abstract_stylelist_from_stylelist() {}

    Class_stylelist_from_stylelist::Class_stylelist_from_stylelist() : Abstract_stylelist_from_stylelist::Abstract_stylelist_from_stylelist() {
      vx_core::refcount += 1;
    }

    Class_stylelist_from_stylelist::~Class_stylelist_from_stylelist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_stylelist_from_stylelist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_stylelist_from_stylelist output = vx_ui_html_uihtml::e_stylelist_from_stylelist;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_stylelist_from_stylelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_stylelist_from_stylelist output = vx_ui_html_uihtml::e_stylelist_from_stylelist;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_stylelist_from_stylelist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylelist<-stylelist", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_stylelist_from_stylelist::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_stylelist_from_stylelist::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylelist<-stylelist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_stylelist_from_stylelist::vx_empty() const {return vx_ui_html_uihtml::e_stylelist_from_stylelist;}
    vx_core::Type_any Class_stylelist_from_stylelist::vx_type() const {return vx_ui_html_uihtml::t_stylelist_from_stylelist;}
    vx_core::Type_msgblock Class_stylelist_from_stylelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_stylelist_from_stylelist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_stylelist_from_stylelist::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_stylelist_from_stylelist::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_stylelist inputval = vx_core::vx_any_from_any(vx_ui_ui::t_stylelist, val);
      output = vx_ui_html_uihtml::f_stylelist_from_stylelist(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_stylelist_from_stylelist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_stylelist uistylelist = vx_core::vx_any_from_any(vx_ui_ui::t_stylelist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_html_uihtml::f_stylelist_from_stylelist(uistylelist);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func stylelist<-stylemap)
  vx_web_html::Type_stylelist f_stylelist_from_stylemap(vx_ui_ui::Type_stylemap uistylemap) {
    vx_web_html::Type_stylelist output = vx_web_html::e_stylelist;
    vx_core::vx_reserve(uistylemap);
    output = vx_core::f_list_from_map(
      vx_web_html::t_stylelist,
      uistylemap,
      vx_core::t_any_from_key_value->vx_fn_new({}, [](vx_core::Type_any key_any, vx_core::Type_any value_any) {
        vx_core::Type_string key = vx_core::vx_any_from_any(vx_core::t_string, key_any);
        vx_ui_ui::Type_style value = vx_core::vx_any_from_any(vx_ui_ui::t_style, value_any);
        vx_core::Type_any output_1 = 
          vx_ui_html_uihtml::f_style_from_style(value);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(uistylemap, output);
    return output;
  }

  // (func stylelist<-stylemap)
  // class Class_stylelist_from_stylemap {
    Abstract_stylelist_from_stylemap::~Abstract_stylelist_from_stylemap() {}

    Class_stylelist_from_stylemap::Class_stylelist_from_stylemap() : Abstract_stylelist_from_stylemap::Abstract_stylelist_from_stylemap() {
      vx_core::refcount += 1;
    }

    Class_stylelist_from_stylemap::~Class_stylelist_from_stylemap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_stylelist_from_stylemap::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_stylelist_from_stylemap output = vx_ui_html_uihtml::e_stylelist_from_stylemap;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_stylelist_from_stylemap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_stylelist_from_stylemap output = vx_ui_html_uihtml::e_stylelist_from_stylemap;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_stylelist_from_stylemap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylelist<-stylemap", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_stylelist_from_stylemap::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_stylelist_from_stylemap::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylelist<-stylemap", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_stylelist_from_stylemap::vx_empty() const {return vx_ui_html_uihtml::e_stylelist_from_stylemap;}
    vx_core::Type_any Class_stylelist_from_stylemap::vx_type() const {return vx_ui_html_uihtml::t_stylelist_from_stylemap;}
    vx_core::Type_msgblock Class_stylelist_from_stylemap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_stylelist_from_stylemap::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_stylelist_from_stylemap::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_stylelist_from_stylemap::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_stylemap inputval = vx_core::vx_any_from_any(vx_ui_ui::t_stylemap, val);
      output = vx_ui_html_uihtml::f_stylelist_from_stylemap(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_stylelist_from_stylemap::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_stylemap uistylemap = vx_core::vx_any_from_any(vx_ui_ui::t_stylemap, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_html_uihtml::f_stylelist_from_stylemap(uistylemap);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func stylemap<-stylemap)
  vx_web_html::Type_stylemap f_stylemap_from_stylemap(vx_ui_ui::Type_stylemap uistylemap) {
    vx_web_html::Type_stylemap output = vx_web_html::e_stylemap;
    vx_core::vx_reserve(uistylemap);
    output = vx_core::f_map_from_map(
      vx_web_html::t_stylemap,
      uistylemap,
      vx_core::t_any_from_key_value->vx_fn_new({}, [](vx_core::Type_any key_any, vx_core::Type_any value_any) {
        vx_core::Type_string key = vx_core::vx_any_from_any(vx_core::t_string, key_any);
        vx_ui_ui::Type_style value = vx_core::vx_any_from_any(vx_ui_ui::t_style, value_any);
        vx_core::Type_any output_1 = 
          vx_ui_html_uihtml::f_style_from_style(value);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(uistylemap, output);
    return output;
  }

  // (func stylemap<-stylemap)
  // class Class_stylemap_from_stylemap {
    Abstract_stylemap_from_stylemap::~Abstract_stylemap_from_stylemap() {}

    Class_stylemap_from_stylemap::Class_stylemap_from_stylemap() : Abstract_stylemap_from_stylemap::Abstract_stylemap_from_stylemap() {
      vx_core::refcount += 1;
    }

    Class_stylemap_from_stylemap::~Class_stylemap_from_stylemap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_stylemap_from_stylemap::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_stylemap_from_stylemap output = vx_ui_html_uihtml::e_stylemap_from_stylemap;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_stylemap_from_stylemap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_stylemap_from_stylemap output = vx_ui_html_uihtml::e_stylemap_from_stylemap;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_stylemap_from_stylemap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylemap<-stylemap", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_stylemap_from_stylemap::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_stylemap_from_stylemap::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylemap<-stylemap", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_stylemap_from_stylemap::vx_empty() const {return vx_ui_html_uihtml::e_stylemap_from_stylemap;}
    vx_core::Type_any Class_stylemap_from_stylemap::vx_type() const {return vx_ui_html_uihtml::t_stylemap_from_stylemap;}
    vx_core::Type_msgblock Class_stylemap_from_stylemap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_stylemap_from_stylemap::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_stylemap_from_stylemap::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_stylemap_from_stylemap::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_stylemap inputval = vx_core::vx_any_from_any(vx_ui_ui::t_stylemap, val);
      output = vx_ui_html_uihtml::f_stylemap_from_stylemap(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_stylemap_from_stylemap::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_stylemap uistylemap = vx_core::vx_any_from_any(vx_ui_ui::t_stylemap, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_html_uihtml::f_stylemap_from_stylemap(uistylemap);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func stylesheet-render-html)
  vx_core::vx_Type_async f_stylesheet_render_html(vx_ui_ui::Type_stylesheet stylesheetui) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve(stylesheetui);
    output = vx_core::f_let_async(
      vx_ui_ui::t_stylesheet,
      vx_core::t_any_from_func_async->vx_fn_new({stylesheetui}, [stylesheetui]() {
        vx_web_html::Type_stylesheet stylesheethtml = vx_ui_html_uihtml::f_stylesheet_from_stylesheet(stylesheetui);
        vx_core::vx_ref_plus(stylesheethtml);
        vx_core::vx_Type_async future_write = vx_web_htmldoc::f_boolean_write_from_stylesheet(stylesheethtml);
        vx_core::vx_Type_fn_any_from_any fn_any_any_write = [stylesheetui](vx_core::Type_any any_write) {
          vx_core::Type_boolean write = vx_core::vx_any_from_any(vx_core::t_boolean, any_write);
          vx_core::vx_ref_plus(write);
          vx_core::Type_any output_2 = stylesheetui;
          vx_core::vx_release_one_except(write, output_2);
          return output_2;
        };
        vx_core::vx_Type_async output_1 = vx_core::vx_async_from_async_fn(future_write, vx_core::t_boolean, {stylesheetui}, fn_any_any_write);
        vx_core::vx_release_one(stylesheethtml);
        return output_1;
      })
    );
    vx_core::vx_release_one(stylesheetui);
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_ui_ui::e_stylesheet);
    }
    return output;
  }

  // (func stylesheet-render-html)
  // class Class_stylesheet_render_html {
    Abstract_stylesheet_render_html::~Abstract_stylesheet_render_html() {}

    Class_stylesheet_render_html::Class_stylesheet_render_html() : Abstract_stylesheet_render_html::Abstract_stylesheet_render_html() {
      vx_core::refcount += 1;
    }

    Class_stylesheet_render_html::~Class_stylesheet_render_html() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_stylesheet_render_html::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_stylesheet_render_html output = vx_ui_html_uihtml::e_stylesheet_render_html;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_stylesheet_render_html::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_stylesheet_render_html output = vx_ui_html_uihtml::e_stylesheet_render_html;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_stylesheet_render_html::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylesheet-render-html", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_stylesheet_render_html::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_stylesheet_render_html::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylesheet-render-html", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_stylesheet_render_html::vx_empty() const {return vx_ui_html_uihtml::e_stylesheet_render_html;}
    vx_core::Type_any Class_stylesheet_render_html::vx_type() const {return vx_ui_html_uihtml::t_stylesheet_render_html;}
    vx_core::Type_msgblock Class_stylesheet_render_html::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_stylesheet_render_html::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_async Class_stylesheet_render_html::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const {
      return vx_core::e_any_from_any_async;
    }

    vx_core::vx_Type_async Class_stylesheet_render_html::vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const {
      vx_ui_ui::Type_stylesheet inputval = vx_core::vx_any_from_any(vx_ui_ui::t_stylesheet, val);
      vx_core::vx_Type_async output = vx_ui_html_uihtml::f_stylesheet_render_html(inputval);
      vx_core::vx_release(val);
      return output;
    }

    vx_core::vx_Type_async Class_stylesheet_render_html::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_value(vx_core::e_any);
      vx_ui_ui::Type_stylesheet stylesheetui = vx_core::vx_any_from_any(vx_ui_ui::t_stylesheet, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_html_uihtml::f_stylesheet_render_html(stylesheetui);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  // (func stylesheet<-stylesheet)
  vx_web_html::Type_stylesheet f_stylesheet_from_stylesheet(vx_ui_ui::Type_stylesheet uistylesheet) {
    vx_web_html::Type_stylesheet output = vx_web_html::e_stylesheet;
    vx_core::vx_reserve(uistylesheet);
    output = vx_core::f_let(
      vx_web_html::t_stylesheet,
      vx_core::t_any_from_func->vx_fn_new({uistylesheet}, [uistylesheet]() {
        vx_ui_ui::Type_stylemap uistylemap = uistylesheet->stylemap();
        vx_core::vx_ref_plus(uistylemap);
        vx_web_html::Type_stylelist stylelist = vx_ui_html_uihtml::f_stylelist_from_stylemap(uistylemap);
        vx_core::vx_ref_plus(stylelist);
        vx_web_html::Type_stylesheet output_1 = vx_core::f_new(
          vx_web_html::t_stylesheet,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":styles"),
            stylelist
          })
        );
        vx_core::vx_release_one_except({uistylemap, stylelist}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(uistylesheet, output);
    return output;
  }

  // (func stylesheet<-stylesheet)
  // class Class_stylesheet_from_stylesheet {
    Abstract_stylesheet_from_stylesheet::~Abstract_stylesheet_from_stylesheet() {}

    Class_stylesheet_from_stylesheet::Class_stylesheet_from_stylesheet() : Abstract_stylesheet_from_stylesheet::Abstract_stylesheet_from_stylesheet() {
      vx_core::refcount += 1;
    }

    Class_stylesheet_from_stylesheet::~Class_stylesheet_from_stylesheet() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_stylesheet_from_stylesheet::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_stylesheet_from_stylesheet output = vx_ui_html_uihtml::e_stylesheet_from_stylesheet;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_stylesheet_from_stylesheet::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_stylesheet_from_stylesheet output = vx_ui_html_uihtml::e_stylesheet_from_stylesheet;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_stylesheet_from_stylesheet::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylesheet<-stylesheet", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_stylesheet_from_stylesheet::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_stylesheet_from_stylesheet::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylesheet<-stylesheet", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_stylesheet_from_stylesheet::vx_empty() const {return vx_ui_html_uihtml::e_stylesheet_from_stylesheet;}
    vx_core::Type_any Class_stylesheet_from_stylesheet::vx_type() const {return vx_ui_html_uihtml::t_stylesheet_from_stylesheet;}
    vx_core::Type_msgblock Class_stylesheet_from_stylesheet::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_stylesheet_from_stylesheet::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_stylesheet_from_stylesheet::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_stylesheet_from_stylesheet::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_stylesheet inputval = vx_core::vx_any_from_any(vx_ui_ui::t_stylesheet, val);
      output = vx_ui_html_uihtml::f_stylesheet_from_stylesheet(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_stylesheet_from_stylesheet::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_stylesheet uistylesheet = vx_core::vx_any_from_any(vx_ui_ui::t_stylesheet, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_html_uihtml::f_stylesheet_from_stylesheet(uistylesheet);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func ui-render-app<-ui-orig-parent)
  vx_ui_ui::Type_ui f_ui_render_app_from_ui_orig_parent(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_ui orig, vx_ui_ui::Type_ui parent) {
    vx_ui_ui::Type_ui output = vx_ui_ui::e_ui;
    vx_core::vx_reserve({ui, orig, parent});
    output = vx_core::f_let(
      vx_ui_ui::t_ui,
      vx_core::t_any_from_func->vx_fn_new({ui}, [ui]() {
        vx_core::Type_string uid = ui->uid();
        vx_core::vx_ref_plus(uid);
        vx_ui_ui::Type_uimap uimap = ui->uimap();
        vx_core::vx_ref_plus(uimap);
        vx_web_html::Type_divchildlist children = vx_ui_html_uihtml::f_divchildlist_from_uimap(uimap);
        vx_core::vx_ref_plus(children);
        vx_web_html::Type_node node = vx_core::f_new(
          vx_web_html::t_div,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":id"),
            uid,
            vx_core::vx_new_string(":nodes"),
            children
          })
        );
        vx_core::vx_ref_plus(node);
        vx_web_html::Type_node nodechg = vx_ui_html_uihtml::f_node_render_from_node_ui(node, ui);
        vx_core::vx_ref_plus(nodechg);
        vx_ui_ui::Type_uimap uimapchg = vx_ui_ui::f_uimap_render_from_uimap_parent(uimap, ui);
        vx_core::vx_ref_plus(uimapchg);
        vx_ui_ui::Type_ui output_1 = vx_core::f_new(
          vx_ui_ui::t_ui,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":uimap"),
            uimapchg
          })
        );
        vx_core::vx_release_one_except({uid, uimap, children, node, nodechg, uimapchg}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({ui, orig, parent}, output);
    return output;
  }

  // (func ui-render-app<-ui-orig-parent)
  // class Class_ui_render_app_from_ui_orig_parent {
    Abstract_ui_render_app_from_ui_orig_parent::~Abstract_ui_render_app_from_ui_orig_parent() {}

    Class_ui_render_app_from_ui_orig_parent::Class_ui_render_app_from_ui_orig_parent() : Abstract_ui_render_app_from_ui_orig_parent::Abstract_ui_render_app_from_ui_orig_parent() {
      vx_core::refcount += 1;
    }

    Class_ui_render_app_from_ui_orig_parent::~Class_ui_render_app_from_ui_orig_parent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_ui_render_app_from_ui_orig_parent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_ui_render_app_from_ui_orig_parent output = vx_ui_html_uihtml::e_ui_render_app_from_ui_orig_parent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_ui_render_app_from_ui_orig_parent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_ui_render_app_from_ui_orig_parent output = vx_ui_html_uihtml::e_ui_render_app_from_ui_orig_parent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_ui_render_app_from_ui_orig_parent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "ui-render-app<-ui-orig-parent", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_ui_render_app_from_ui_orig_parent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_ui_render_app_from_ui_orig_parent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "ui-render-app<-ui-orig-parent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_ui_render_app_from_ui_orig_parent::vx_empty() const {return vx_ui_html_uihtml::e_ui_render_app_from_ui_orig_parent;}
    vx_core::Type_any Class_ui_render_app_from_ui_orig_parent::vx_type() const {return vx_ui_html_uihtml::t_ui_render_app_from_ui_orig_parent;}
    vx_core::Type_msgblock Class_ui_render_app_from_ui_orig_parent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ui_render_app_from_ui_orig_parent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_ui_render_app_from_ui_orig_parent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_ui orig = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_ui_ui::Type_ui parent = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_ui_html_uihtml::f_ui_render_app_from_ui_orig_parent(ui, orig, parent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func ui-render-default<-ui-orig-parent)
  vx_ui_ui::Type_ui f_ui_render_default_from_ui_orig_parent(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_ui orig, vx_ui_ui::Type_ui parent) {
    vx_ui_ui::Type_ui output = vx_ui_ui::e_ui;
    vx_core::vx_reserve({ui, orig, parent});
    output = vx_core::f_let(
      vx_ui_ui::t_ui,
      vx_core::t_any_from_func->vx_fn_new({ui}, [ui]() {
        vx_core::Type_string uid = ui->uid();
        vx_core::vx_ref_plus(uid);
        vx_ui_ui::Type_uimap uimap = ui->uimap();
        vx_core::vx_ref_plus(uimap);
        vx_ui_ui::Type_style uistyle = ui->style();
        vx_core::vx_ref_plus(uistyle);
        vx_ui_ui::Type_stylelist uistyles = ui->stylelist();
        vx_core::vx_ref_plus(uistyles);
        vx_web_html::Type_style style = vx_ui_html_uihtml::f_style_from_style(uistyle);
        vx_core::vx_ref_plus(style);
        vx_web_html::Type_stylelist styles = vx_ui_html_uihtml::f_stylelist_from_stylelist(uistyles);
        vx_core::vx_ref_plus(styles);
        vx_web_html::Type_divchildlist children = vx_ui_html_uihtml::f_divchildlist_from_uimap(uimap);
        vx_core::vx_ref_plus(children);
        vx_web_html::Type_node node = vx_core::f_new(
          vx_web_html::t_div,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":id"),
            uid,
            vx_core::vx_new_string(":style-unique"),
            style,
            vx_core::vx_new_string(":stylelist"),
            styles,
            vx_core::vx_new_string(":nodes"),
            children
          })
        );
        vx_core::vx_ref_plus(node);
        vx_web_html::Type_node nodechg = vx_ui_html_uihtml::f_node_render_from_node_ui(node, ui);
        vx_core::vx_ref_plus(nodechg);
        vx_ui_ui::Type_uimap uimapchg = vx_ui_ui::f_uimap_render_from_uimap_parent(uimap, ui);
        vx_core::vx_ref_plus(uimapchg);
        vx_ui_ui::Type_ui output_1 = vx_core::f_new(
          vx_ui_ui::t_ui,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":uimap"),
            uimapchg
          })
        );
        vx_core::vx_release_one_except({uid, uimap, uistyle, uistyles, style, styles, children, node, nodechg, uimapchg}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({ui, orig, parent}, output);
    return output;
  }

  // (func ui-render-default<-ui-orig-parent)
  // class Class_ui_render_default_from_ui_orig_parent {
    Abstract_ui_render_default_from_ui_orig_parent::~Abstract_ui_render_default_from_ui_orig_parent() {}

    Class_ui_render_default_from_ui_orig_parent::Class_ui_render_default_from_ui_orig_parent() : Abstract_ui_render_default_from_ui_orig_parent::Abstract_ui_render_default_from_ui_orig_parent() {
      vx_core::refcount += 1;
    }

    Class_ui_render_default_from_ui_orig_parent::~Class_ui_render_default_from_ui_orig_parent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_ui_render_default_from_ui_orig_parent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_ui_render_default_from_ui_orig_parent output = vx_ui_html_uihtml::e_ui_render_default_from_ui_orig_parent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_ui_render_default_from_ui_orig_parent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_ui_render_default_from_ui_orig_parent output = vx_ui_html_uihtml::e_ui_render_default_from_ui_orig_parent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_ui_render_default_from_ui_orig_parent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "ui-render-default<-ui-orig-parent", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_ui_render_default_from_ui_orig_parent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_ui_render_default_from_ui_orig_parent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "ui-render-default<-ui-orig-parent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_ui_render_default_from_ui_orig_parent::vx_empty() const {return vx_ui_html_uihtml::e_ui_render_default_from_ui_orig_parent;}
    vx_core::Type_any Class_ui_render_default_from_ui_orig_parent::vx_type() const {return vx_ui_html_uihtml::t_ui_render_default_from_ui_orig_parent;}
    vx_core::Type_msgblock Class_ui_render_default_from_ui_orig_parent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ui_render_default_from_ui_orig_parent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_ui_render_default_from_ui_orig_parent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_ui orig = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_ui_ui::Type_ui parent = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_ui_html_uihtml::f_ui_render_default_from_ui_orig_parent(ui, orig, parent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func ui-render-label<-ui-orig-parent)
  vx_ui_ui::Type_ui f_ui_render_label_from_ui_orig_parent(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_ui orig, vx_ui_ui::Type_ui parent) {
    vx_ui_ui::Type_ui output = vx_ui_ui::e_ui;
    vx_core::vx_reserve({ui, orig, parent});
    output = vx_core::f_let(
      vx_ui_ui::t_ui,
      vx_core::t_any_from_func->vx_fn_new({ui}, [ui]() {
        vx_core::Type_string uid = ui->uid();
        vx_core::vx_ref_plus(uid);
        vx_core::Type_any data = ui->data();
        vx_core::vx_ref_plus(data);
        vx_ui_ui::Type_uimap uimap = ui->uimap();
        vx_core::vx_ref_plus(uimap);
        vx_ui_ui::Type_style uistyle = ui->style();
        vx_core::vx_ref_plus(uistyle);
        vx_ui_ui::Type_stylelist uistyles = ui->stylelist();
        vx_core::vx_ref_plus(uistyles);
        vx_web_html::Type_style style = vx_ui_html_uihtml::f_style_from_style(uistyle);
        vx_core::vx_ref_plus(style);
        vx_web_html::Type_stylelist styles = vx_ui_html_uihtml::f_stylelist_from_stylelist(uistyles);
        vx_core::vx_ref_plus(styles);
        vx_core::Type_any datatype = vx_core::f_type_from_any(data);
        vx_core::vx_ref_plus(datatype);
        vx_core::Type_string text = vx_core::f_if_2(
          vx_core::t_string,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({datatype}, [datatype]() {
                vx_core::Type_boolean output_1 = vx_core::f_eq(
                  datatype,
                  vx_core::t_string
                );
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({data}, [data]() {
                vx_core::Type_string output_1 = vx_core::f_any_from_any(vx_core::t_string, data);
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({data}, [data]() {
                vx_core::Type_string output_1 = vx_core::f_string_from_any(data);
                return output_1;
              })
            )
          })
        );
        vx_core::vx_ref_plus(text);
        vx_web_html::Type_node node = vx_core::f_new(
          vx_web_html::t_p,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":id"),
            uid,
            vx_core::vx_new_string(":style-unique"),
            style,
            vx_core::vx_new_string(":stylelist"),
            styles,
            vx_core::vx_new_string(":text"),
            text
          })
        );
        vx_core::vx_ref_plus(node);
        vx_web_html::Type_node nodechg = vx_ui_html_uihtml::f_node_render_from_node_ui(node, ui);
        vx_core::vx_ref_plus(nodechg);
        vx_ui_ui::Type_uimap uimapchg = vx_ui_ui::f_uimap_render_from_uimap_parent(uimap, ui);
        vx_core::vx_ref_plus(uimapchg);
        vx_ui_ui::Type_ui output_1 = vx_core::f_new(
          vx_ui_ui::t_ui,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":uimap"),
            uimapchg
          })
        );
        vx_core::vx_release_one_except({uid, data, uimap, uistyle, uistyles, style, styles, datatype, text, node, nodechg, uimapchg}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({ui, orig, parent}, output);
    return output;
  }

  // (func ui-render-label<-ui-orig-parent)
  // class Class_ui_render_label_from_ui_orig_parent {
    Abstract_ui_render_label_from_ui_orig_parent::~Abstract_ui_render_label_from_ui_orig_parent() {}

    Class_ui_render_label_from_ui_orig_parent::Class_ui_render_label_from_ui_orig_parent() : Abstract_ui_render_label_from_ui_orig_parent::Abstract_ui_render_label_from_ui_orig_parent() {
      vx_core::refcount += 1;
    }

    Class_ui_render_label_from_ui_orig_parent::~Class_ui_render_label_from_ui_orig_parent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_ui_render_label_from_ui_orig_parent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_ui_render_label_from_ui_orig_parent output = vx_ui_html_uihtml::e_ui_render_label_from_ui_orig_parent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_ui_render_label_from_ui_orig_parent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_ui_render_label_from_ui_orig_parent output = vx_ui_html_uihtml::e_ui_render_label_from_ui_orig_parent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_ui_render_label_from_ui_orig_parent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "ui-render-label<-ui-orig-parent", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_ui_render_label_from_ui_orig_parent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_ui_render_label_from_ui_orig_parent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "ui-render-label<-ui-orig-parent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_ui_render_label_from_ui_orig_parent::vx_empty() const {return vx_ui_html_uihtml::e_ui_render_label_from_ui_orig_parent;}
    vx_core::Type_any Class_ui_render_label_from_ui_orig_parent::vx_type() const {return vx_ui_html_uihtml::t_ui_render_label_from_ui_orig_parent;}
    vx_core::Type_msgblock Class_ui_render_label_from_ui_orig_parent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ui_render_label_from_ui_orig_parent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_ui_render_label_from_ui_orig_parent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_ui orig = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_ui_ui::Type_ui parent = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_ui_html_uihtml::f_ui_render_label_from_ui_orig_parent(ui, orig, parent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_ui_html_uihtml::Const_layout_app_html c_layout_app_html = NULL;
  vx_ui_html_uihtml::Const_layout_else_html c_layout_else_html = NULL;
  vx_ui_html_uihtml::Const_layout_label_html c_layout_label_html = NULL;
  vx_ui_html_uihtml::Const_layoutenginehtml c_layoutenginehtml = NULL;
  vx_ui_html_uihtml::Func_divchild_from_ui e_divchild_from_ui = NULL;
  vx_ui_html_uihtml::Func_divchild_from_ui t_divchild_from_ui = NULL;
  vx_ui_html_uihtml::Func_divchildlist_from_uimap e_divchildlist_from_uimap = NULL;
  vx_ui_html_uihtml::Func_divchildlist_from_uimap t_divchildlist_from_uimap = NULL;
  vx_ui_html_uihtml::Func_node_app_from_ui_orig_parent e_node_app_from_ui_orig_parent = NULL;
  vx_ui_html_uihtml::Func_node_app_from_ui_orig_parent t_node_app_from_ui_orig_parent = NULL;
  vx_ui_html_uihtml::Func_node_render_from_node_ui e_node_render_from_node_ui = NULL;
  vx_ui_html_uihtml::Func_node_render_from_node_ui t_node_render_from_node_ui = NULL;
  vx_ui_html_uihtml::Func_string_stylename_from_name_styletype e_string_stylename_from_name_styletype = NULL;
  vx_ui_html_uihtml::Func_string_stylename_from_name_styletype t_string_stylename_from_name_styletype = NULL;
  vx_ui_html_uihtml::Func_style_from_style e_style_from_style = NULL;
  vx_ui_html_uihtml::Func_style_from_style t_style_from_style = NULL;
  vx_ui_html_uihtml::Func_stylelist_from_stylelist e_stylelist_from_stylelist = NULL;
  vx_ui_html_uihtml::Func_stylelist_from_stylelist t_stylelist_from_stylelist = NULL;
  vx_ui_html_uihtml::Func_stylelist_from_stylemap e_stylelist_from_stylemap = NULL;
  vx_ui_html_uihtml::Func_stylelist_from_stylemap t_stylelist_from_stylemap = NULL;
  vx_ui_html_uihtml::Func_stylemap_from_stylemap e_stylemap_from_stylemap = NULL;
  vx_ui_html_uihtml::Func_stylemap_from_stylemap t_stylemap_from_stylemap = NULL;
  vx_ui_html_uihtml::Func_stylesheet_render_html e_stylesheet_render_html = NULL;
  vx_ui_html_uihtml::Func_stylesheet_render_html t_stylesheet_render_html = NULL;
  vx_ui_html_uihtml::Func_stylesheet_from_stylesheet e_stylesheet_from_stylesheet = NULL;
  vx_ui_html_uihtml::Func_stylesheet_from_stylesheet t_stylesheet_from_stylesheet = NULL;
  vx_ui_html_uihtml::Func_ui_render_app_from_ui_orig_parent e_ui_render_app_from_ui_orig_parent = NULL;
  vx_ui_html_uihtml::Func_ui_render_app_from_ui_orig_parent t_ui_render_app_from_ui_orig_parent = NULL;
  vx_ui_html_uihtml::Func_ui_render_default_from_ui_orig_parent e_ui_render_default_from_ui_orig_parent = NULL;
  vx_ui_html_uihtml::Func_ui_render_default_from_ui_orig_parent t_ui_render_default_from_ui_orig_parent = NULL;
  vx_ui_html_uihtml::Func_ui_render_label_from_ui_orig_parent e_ui_render_label_from_ui_orig_parent = NULL;
  vx_ui_html_uihtml::Func_ui_render_label_from_ui_orig_parent t_ui_render_label_from_ui_orig_parent = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_ui_html_uihtml::c_layout_app_html = new vx_ui_html_uihtml::Class_layout_app_html();
      vx_ui_html_uihtml::c_layout_else_html = new vx_ui_html_uihtml::Class_layout_else_html();
      vx_ui_html_uihtml::c_layout_label_html = new vx_ui_html_uihtml::Class_layout_label_html();
      vx_ui_html_uihtml::c_layoutenginehtml = new vx_ui_html_uihtml::Class_layoutenginehtml();
      vx_ui_html_uihtml::e_divchild_from_ui = new vx_ui_html_uihtml::Class_divchild_from_ui();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_divchild_from_ui);
      vx_ui_html_uihtml::t_divchild_from_ui = new vx_ui_html_uihtml::Class_divchild_from_ui();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_divchild_from_ui);
      vx_ui_html_uihtml::e_divchildlist_from_uimap = new vx_ui_html_uihtml::Class_divchildlist_from_uimap();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_divchildlist_from_uimap);
      vx_ui_html_uihtml::t_divchildlist_from_uimap = new vx_ui_html_uihtml::Class_divchildlist_from_uimap();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_divchildlist_from_uimap);
      vx_ui_html_uihtml::e_node_app_from_ui_orig_parent = new vx_ui_html_uihtml::Class_node_app_from_ui_orig_parent();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_node_app_from_ui_orig_parent);
      vx_ui_html_uihtml::t_node_app_from_ui_orig_parent = new vx_ui_html_uihtml::Class_node_app_from_ui_orig_parent();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_node_app_from_ui_orig_parent);
      vx_ui_html_uihtml::e_node_render_from_node_ui = new vx_ui_html_uihtml::Class_node_render_from_node_ui();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_node_render_from_node_ui);
      vx_ui_html_uihtml::t_node_render_from_node_ui = new vx_ui_html_uihtml::Class_node_render_from_node_ui();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_node_render_from_node_ui);
      vx_ui_html_uihtml::e_string_stylename_from_name_styletype = new vx_ui_html_uihtml::Class_string_stylename_from_name_styletype();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_string_stylename_from_name_styletype);
      vx_ui_html_uihtml::t_string_stylename_from_name_styletype = new vx_ui_html_uihtml::Class_string_stylename_from_name_styletype();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_string_stylename_from_name_styletype);
      vx_ui_html_uihtml::e_style_from_style = new vx_ui_html_uihtml::Class_style_from_style();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_style_from_style);
      vx_ui_html_uihtml::t_style_from_style = new vx_ui_html_uihtml::Class_style_from_style();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_style_from_style);
      vx_ui_html_uihtml::e_stylelist_from_stylelist = new vx_ui_html_uihtml::Class_stylelist_from_stylelist();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_stylelist_from_stylelist);
      vx_ui_html_uihtml::t_stylelist_from_stylelist = new vx_ui_html_uihtml::Class_stylelist_from_stylelist();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_stylelist_from_stylelist);
      vx_ui_html_uihtml::e_stylelist_from_stylemap = new vx_ui_html_uihtml::Class_stylelist_from_stylemap();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_stylelist_from_stylemap);
      vx_ui_html_uihtml::t_stylelist_from_stylemap = new vx_ui_html_uihtml::Class_stylelist_from_stylemap();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_stylelist_from_stylemap);
      vx_ui_html_uihtml::e_stylemap_from_stylemap = new vx_ui_html_uihtml::Class_stylemap_from_stylemap();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_stylemap_from_stylemap);
      vx_ui_html_uihtml::t_stylemap_from_stylemap = new vx_ui_html_uihtml::Class_stylemap_from_stylemap();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_stylemap_from_stylemap);
      vx_ui_html_uihtml::e_stylesheet_render_html = new vx_ui_html_uihtml::Class_stylesheet_render_html();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_stylesheet_render_html);
      vx_ui_html_uihtml::t_stylesheet_render_html = new vx_ui_html_uihtml::Class_stylesheet_render_html();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_stylesheet_render_html);
      vx_ui_html_uihtml::e_stylesheet_from_stylesheet = new vx_ui_html_uihtml::Class_stylesheet_from_stylesheet();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_stylesheet_from_stylesheet);
      vx_ui_html_uihtml::t_stylesheet_from_stylesheet = new vx_ui_html_uihtml::Class_stylesheet_from_stylesheet();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_stylesheet_from_stylesheet);
      vx_ui_html_uihtml::e_ui_render_app_from_ui_orig_parent = new vx_ui_html_uihtml::Class_ui_render_app_from_ui_orig_parent();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_ui_render_app_from_ui_orig_parent);
      vx_ui_html_uihtml::t_ui_render_app_from_ui_orig_parent = new vx_ui_html_uihtml::Class_ui_render_app_from_ui_orig_parent();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_ui_render_app_from_ui_orig_parent);
      vx_ui_html_uihtml::e_ui_render_default_from_ui_orig_parent = new vx_ui_html_uihtml::Class_ui_render_default_from_ui_orig_parent();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_ui_render_default_from_ui_orig_parent);
      vx_ui_html_uihtml::t_ui_render_default_from_ui_orig_parent = new vx_ui_html_uihtml::Class_ui_render_default_from_ui_orig_parent();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_ui_render_default_from_ui_orig_parent);
      vx_ui_html_uihtml::e_ui_render_label_from_ui_orig_parent = new vx_ui_html_uihtml::Class_ui_render_label_from_ui_orig_parent();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_ui_render_label_from_ui_orig_parent);
      vx_ui_html_uihtml::t_ui_render_label_from_ui_orig_parent = new vx_ui_html_uihtml::Class_ui_render_label_from_ui_orig_parent();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_ui_render_label_from_ui_orig_parent);
      vx_ui_html_uihtml::Class_layout_app_html::vx_const_new(vx_ui_html_uihtml::c_layout_app_html);
      vx_ui_html_uihtml::Class_layout_else_html::vx_const_new(vx_ui_html_uihtml::c_layout_else_html);
      vx_ui_html_uihtml::Class_layout_label_html::vx_const_new(vx_ui_html_uihtml::c_layout_label_html);
      vx_ui_html_uihtml::Class_layoutenginehtml::vx_const_new(vx_ui_html_uihtml::c_layoutenginehtml);
      vx_core::vx_Type_mapany maptype;
      vx_core::vx_Type_mapany mapconst;
      vx_core::vx_Type_mapfunc mapfunc;
      vx_core::vx_Type_mapany mapempty;
      mapconst["layout-app-html"] = vx_ui_html_uihtml::c_layout_app_html;
      mapconst["layout-else-html"] = vx_ui_html_uihtml::c_layout_else_html;
      mapconst["layout-label-html"] = vx_ui_html_uihtml::c_layout_label_html;
      mapconst["layoutenginehtml"] = vx_ui_html_uihtml::c_layoutenginehtml;
      mapfunc["divchild<-ui"] = vx_ui_html_uihtml::t_divchild_from_ui;
      mapfunc["divchildlist<-uimap"] = vx_ui_html_uihtml::t_divchildlist_from_uimap;
      mapfunc["node-app<-ui-orig-parent"] = vx_ui_html_uihtml::t_node_app_from_ui_orig_parent;
      mapfunc["node-render<-node-ui"] = vx_ui_html_uihtml::t_node_render_from_node_ui;
      mapfunc["string-stylename<-name-styletype"] = vx_ui_html_uihtml::t_string_stylename_from_name_styletype;
      mapfunc["style<-style"] = vx_ui_html_uihtml::t_style_from_style;
      mapfunc["stylelist<-stylelist"] = vx_ui_html_uihtml::t_stylelist_from_stylelist;
      mapfunc["stylelist<-stylemap"] = vx_ui_html_uihtml::t_stylelist_from_stylemap;
      mapfunc["stylemap<-stylemap"] = vx_ui_html_uihtml::t_stylemap_from_stylemap;
      mapfunc["stylesheet-render-html"] = vx_ui_html_uihtml::t_stylesheet_render_html;
      mapfunc["stylesheet<-stylesheet"] = vx_ui_html_uihtml::t_stylesheet_from_stylesheet;
      mapfunc["ui-render-app<-ui-orig-parent"] = vx_ui_html_uihtml::t_ui_render_app_from_ui_orig_parent;
      mapfunc["ui-render-default<-ui-orig-parent"] = vx_ui_html_uihtml::t_ui_render_default_from_ui_orig_parent;
      mapfunc["ui-render-label<-ui-orig-parent"] = vx_ui_html_uihtml::t_ui_render_label_from_ui_orig_parent;
      vx_core::vx_global_package_set("vx/ui/html/uihtml", maptype, mapconst, mapfunc);
	   }
  // }

}
