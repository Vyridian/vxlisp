#include "../../../vx/core.hpp"
#include "../../../vx/data/file.hpp"
#include "../../../vx/web/html.hpp"
#include "../../../vx/web/htmldoc.hpp"
#include "../../../vx/event.hpp"
#include "../../../vx/type.hpp"
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
          vx_ui_html_uihtml::t_ui_layout_app_from_ui_orig_parent
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
          vx_ui_html_uihtml::t_ui_layout_default_from_ui_orig_parent
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

  // (const layout-image-html)
  // class Class_layout_image_html {
    // vx_const_new()
    void vx_ui_html_uihtml::Class_layout_image_html::vx_const_new(vx_ui_html_uihtml::Const_layout_image_html output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/html/uihtml", "layout-image-html");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_copy(
        vx_ui_ui::t_layout,
        vx_ui_ui::c_layout_image,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":fn-layout"),
          vx_ui_html_uihtml::t_ui_layout_image_from_ui_orig_parent
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
          vx_ui_html_uihtml::t_ui_layout_label_from_ui_orig_parent
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
                vx_ui_html_uihtml::c_layout_image_html,
                vx_ui_html_uihtml::c_layout_label_html
              })
            )
          ),
          vx_core::vx_new_string(":layoutelse"),
          vx_ui_html_uihtml::c_layout_else_html,
          vx_core::vx_new_string(":boolean-print"),
          vx_ui_html_uihtml::t_boolean_print_html,
          vx_core::vx_new_string(":stylesheetrender"),
          vx_ui_html_uihtml::t_stylesheet_layout_html
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_boolean_print = val->boolean_print();
      vx_core::vx_reserve(output->vx_p_boolean_print);
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

  // (const style-hidden)
  // class Class_style_hidden {
    // vx_const_new()
    void vx_ui_html_uihtml::Class_style_hidden::vx_const_new(vx_ui_html_uihtml::Const_style_hidden output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/html/uihtml", "style-hidden");
      long irefcount = vx_core::refcount;
      vx_web_html::Type_style val = vx_core::f_new(
        vx_web_html::t_style,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string(".style-hidden")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_props = val->props();
      vx_core::vx_reserve(output->vx_p_props);
      output->vx_p_stylelist = val->stylelist();
      vx_core::vx_reserve(output->vx_p_stylelist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const style-selected)
  // class Class_style_selected {
    // vx_const_new()
    void vx_ui_html_uihtml::Class_style_selected::vx_const_new(vx_ui_html_uihtml::Const_style_selected output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/html/uihtml", "style-selected");
      long irefcount = vx_core::refcount;
      vx_web_html::Type_style val = vx_core::f_new(
        vx_web_html::t_style,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string(".style-selected")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_props = val->props();
      vx_core::vx_reserve(output->vx_p_props);
      output->vx_p_stylelist = val->stylelist();
      vx_core::vx_reserve(output->vx_p_stylelist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (func boolean-print-html)
  vx_core::Type_boolean f_boolean_print_html(vx_core::Type_context context, vx_ui_ui::Type_ui ui) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve(ui);
    output = vx_core::f_let(
      vx_core::t_boolean,
      vx_core::t_any_from_func->vx_fn_new({ui, context}, [ui, context]() {
        vx_core::Type_string uid = ui->uid();
        vx_core::vx_ref_plus(uid);
        vx_ui_ui::Type_stylesheet stylesheetui = vx_ui_ui::f_stylesheet_readstate(context);
        vx_core::vx_ref_plus(stylesheetui);
        vx_web_html::Type_stylesheet stylesheethtml = vx_ui_html_uihtml::f_stylesheet_from_stylesheet(stylesheetui);
        vx_core::vx_ref_plus(stylesheethtml);
        vx_core::Type_string styletext = vx_web_html::f_string_from_stylesheet_indent(stylesheethtml, vx_core::vx_new_int(0));
        vx_core::vx_ref_plus(styletext);
        vx_core::Type_boolean output_1 = vx_web_htmldoc::f_boolean_print_from_id_stylesheettext(uid, styletext);
        vx_core::vx_release_one_except({uid, stylesheetui, stylesheethtml, styletext}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(ui, output);
    return output;
  }
  /**
   * @function boolean_print_html
   * Create a print ready version of ui
   * @param  {ui} ui
   * @return {boolean}
   * (func boolean-print-html)
   */
  // (func boolean-print-html)
  // class Class_boolean_print_html {
    Abstract_boolean_print_html::~Abstract_boolean_print_html() {}

    Class_boolean_print_html::Class_boolean_print_html() : Abstract_boolean_print_html::Abstract_boolean_print_html() {
      vx_core::refcount += 1;
    }

    Class_boolean_print_html::~Class_boolean_print_html() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_boolean_print_html::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_boolean_print_html output = vx_ui_html_uihtml::e_boolean_print_html;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_boolean_print_html::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_boolean_print_html output = vx_ui_html_uihtml::e_boolean_print_html;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_boolean_print_html::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "boolean-print-html", // name
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

    vx_core::Type_constdef Class_boolean_print_html::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_boolean_print_html::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "boolean-print-html", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_boolean_print_html::vx_empty() const {return vx_ui_html_uihtml::e_boolean_print_html;}
    vx_core::Type_any Class_boolean_print_html::vx_type() const {return vx_ui_html_uihtml::t_boolean_print_html;}
    vx_core::Type_msgblock Class_boolean_print_html::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_print_html::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_boolean_print_html::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_boolean_print_html::vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui inputval = vx_core::vx_any_from_any(vx_ui_ui::t_ui, val);
      output = vx_ui_html_uihtml::f_boolean_print_html(context, inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_boolean_print_html::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_html_uihtml::f_boolean_print_html(context, ui);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func context-write)
  vx_core::Type_context f_context_write(vx_core::Type_context context) {
    vx_core::Type_context output = vx_core::e_context;
    output = vx_web_htmldoc::f_context_write(context);
    return output;
  }
  /**
   * @function context_write
   * @return {context}
   * (func context-write)
   */
  // (func context-write)
  // class Class_context_write {
    Abstract_context_write::~Abstract_context_write() {}

    Class_context_write::Class_context_write() : Abstract_context_write::Abstract_context_write() {
      vx_core::refcount += 1;
    }

    Class_context_write::~Class_context_write() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_context_write::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_context_write output = vx_ui_html_uihtml::e_context_write;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_context_write::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_context_write output = vx_ui_html_uihtml::e_context_write;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_context_write::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "context-write", // name
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

    vx_core::Type_constdef Class_context_write::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_context_write::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "context-write", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_context_write::vx_empty() const {return vx_ui_html_uihtml::e_context_write;}
    vx_core::Type_any Class_context_write::vx_type() const {return vx_ui_html_uihtml::t_context_write;}
    vx_core::Type_msgblock Class_context_write::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_context_write::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_context_write::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_html_uihtml::f_context_write(context);
      vx_core::vx_release_except(arglist, output);
      return output;
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
  /**
   * @function divchild_from_ui
   * Returns a divchildlist of empty divs from a uimap
   * @param  {ui} ui
   * @return {divchild}
   * (func divchild<-ui)
   */
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
    output = vx_core::f_list_from_map_1(
      vx_web_html::t_divchildlist,
      uimap,
      vx_core::t_any_from_key_value->vx_fn_new({}, [](vx_core::Type_any key_any, vx_core::Type_any value_any) {
        vx_core::Type_string key = vx_core::vx_any_from_any(vx_core::t_string, key_any);
        vx_ui_ui::Type_ui value = vx_core::vx_any_from_any(vx_ui_ui::t_ui, value_any);
        vx_core::Type_any output_1 = 
          vx_core::f_let(
            vx_web_html::t_div,
            vx_core::t_any_from_func->vx_fn_new({value}, [value]() {
              vx_core::Type_string uid = value->uid();
              vx_core::vx_ref_plus(uid);
              vx_web_html::Type_div output_1 = vx_core::f_new(
                vx_web_html::t_div,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":id"),
                  uid
                })
              );
              vx_core::vx_release_one_except(uid, output_1);
              return output_1;
            })
          );
        return output_1;
      })
    );
    vx_core::vx_release_one_except(uimap, output);
    return output;
  }
  /**
   * @function divchildlist_from_uimap
   * Returns a divchildlist of empty divs from a uimap
   * @param  {uimap} uimap
   * @return {divchildlist}
   * (func divchildlist<-uimap)
   */
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
  /**
   * @function node_app_from_ui_orig_parent
   * @param  {ui} ui
   * @param  {ui} orig
   * @param  {ui} parent
   * @return {node}
   * (func node-app<-ui-orig-parent)
   */
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

  // (func node-layout<-node-ui)
  vx_web_html::Type_node f_node_layout_from_node_ui(vx_web_html::Type_node node, vx_ui_ui::Type_ui ui) {
    vx_web_html::Type_node output = vx_web_html::e_node;
    vx_core::vx_reserve({node, ui});
    output = vx_core::f_let(
      vx_web_html::t_node,
      vx_core::t_any_from_func->vx_fn_new({node, ui}, [node, ui]() {
        vx_core::Type_string htmltext = vx_web_html::f_string_from_node_indent(node, vx_core::vx_new_int(2));
        vx_core::vx_ref_plus(htmltext);
        vx_core::Type_boolean htmldone = vx_web_htmldoc::f_boolean_replace_from_ui_htmltext(ui, htmltext);
        vx_core::vx_ref_plus(htmldone);
        vx_web_html::Type_node output_1 = node;
        vx_core::vx_release_one_except({htmltext, htmldone}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({node, ui}, output);
    return output;
  }
  /**
   * @function node_layout_from_node_ui
   * @param  {node} node
   * @param  {ui} ui
   * @return {node}
   * (func node-layout<-node-ui)
   */
  // (func node-layout<-node-ui)
  // class Class_node_layout_from_node_ui {
    Abstract_node_layout_from_node_ui::~Abstract_node_layout_from_node_ui() {}

    Class_node_layout_from_node_ui::Class_node_layout_from_node_ui() : Abstract_node_layout_from_node_ui::Abstract_node_layout_from_node_ui() {
      vx_core::refcount += 1;
    }

    Class_node_layout_from_node_ui::~Class_node_layout_from_node_ui() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_node_layout_from_node_ui::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_node_layout_from_node_ui output = vx_ui_html_uihtml::e_node_layout_from_node_ui;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_node_layout_from_node_ui::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_node_layout_from_node_ui output = vx_ui_html_uihtml::e_node_layout_from_node_ui;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_node_layout_from_node_ui::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "node-layout<-node-ui", // name
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

    vx_core::Type_constdef Class_node_layout_from_node_ui::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_node_layout_from_node_ui::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "node-layout<-node-ui", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_node_layout_from_node_ui::vx_empty() const {return vx_ui_html_uihtml::e_node_layout_from_node_ui;}
    vx_core::Type_any Class_node_layout_from_node_ui::vx_type() const {return vx_ui_html_uihtml::t_node_layout_from_node_ui;}
    vx_core::Type_msgblock Class_node_layout_from_node_ui::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_node_layout_from_node_ui::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_node_layout_from_node_ui::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_node node = vx_core::vx_any_from_any(vx_web_html::t_node, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_ui_html_uihtml::f_node_layout_from_node_ui(node, ui);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string-style<-font)
  vx_core::Type_string f_string_style_from_font(vx_ui_ui::Type_font font) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve(font);
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({font}, [font]() {
        vx_ui_ui::Type_fontface face = font->fontface();
        vx_core::vx_ref_plus(face);
        vx_core::Type_int size = font->fontsize();
        vx_core::vx_ref_plus(size);
        vx_core::Type_string name = face->name();
        vx_core::vx_ref_plus(name);
        vx_core::Type_string ssize = vx_core::f_if_2(
          vx_core::t_string,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({size}, [size]() {
                vx_core::Type_boolean output_1 = vx_core::f_gt(size, vx_core::vx_new_int(0));
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({size}, [size]() {
                vx_core::Type_string output_1 = vx_core::f_new(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::f_divide(size, vx_core::vx_new_int(100)),
                    vx_core::vx_new_string("em"),
                    vx_core::vx_new_string(" ")
                  })
                );
                return output_1;
              })
            )
          })
        );
        vx_core::vx_ref_plus(ssize);
        vx_core::Type_string output_1 = vx_core::f_if_2(
          vx_core::t_string,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({name}, [name]() {
                vx_core::Type_boolean output_1 = vx_core::f_notempty(name);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({ssize, name}, [ssize, name]() {
                vx_core::Type_string output_1 = vx_core::f_new(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_anylist, {
                    ssize,
                    vx_core::c_quote,
                    name,
                    vx_core::c_quote
                  })
                );
                return output_1;
              })
            )
          })
        );
        vx_core::vx_release_one_except({face, size, name, ssize}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(font, output);
    return output;
  }
  /**
   * @function string_style_from_font
   * Returns a font css string from a logical font.
   * @param  {font} font
   * @return {string}
   * (func string-style<-font)
   */
  // (func string-style<-font)
  // class Class_string_style_from_font {
    Abstract_string_style_from_font::~Abstract_string_style_from_font() {}

    Class_string_style_from_font::Class_string_style_from_font() : Abstract_string_style_from_font::Abstract_string_style_from_font() {
      vx_core::refcount += 1;
    }

    Class_string_style_from_font::~Class_string_style_from_font() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_style_from_font::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_string_style_from_font output = vx_ui_html_uihtml::e_string_style_from_font;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_style_from_font::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_string_style_from_font output = vx_ui_html_uihtml::e_string_style_from_font;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_style_from_font::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "string-style<-font", // name
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

    vx_core::Type_constdef Class_string_style_from_font::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_style_from_font::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "string-style<-font", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_style_from_font::vx_empty() const {return vx_ui_html_uihtml::e_string_style_from_font;}
    vx_core::Type_any Class_string_style_from_font::vx_type() const {return vx_ui_html_uihtml::t_string_style_from_font;}
    vx_core::Type_msgblock Class_string_style_from_font::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_style_from_font::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_string_style_from_font::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_string_style_from_font::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_font inputval = vx_core::vx_any_from_any(vx_ui_ui::t_font, val);
      output = vx_ui_html_uihtml::f_string_style_from_font(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_string_style_from_font::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_font font = vx_core::vx_any_from_any(vx_ui_ui::t_font, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_html_uihtml::f_string_style_from_font(font);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string-style<-image)
  vx_core::Type_string f_string_style_from_image(vx_ui_ui::Type_image image) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve(image);
    output = vx_core::f_if_2(
      vx_core::t_string,
      vx_core::vx_new(vx_core::t_thenelselist, {
        vx_core::f_then(
          vx_core::t_boolean_from_func->vx_fn_new({image}, [image]() {
            vx_core::Type_boolean output_1 = vx_core::f_notempty_1(image);
            return output_1;
          }),
          vx_core::t_any_from_func->vx_fn_new({image}, [image]() {
            vx_core::Type_string output_1 = vx_core::f_let(
              vx_core::t_string,
              vx_core::t_any_from_func->vx_fn_new({image}, [image]() {
                vx_data_file::Type_file file = image->file();
                vx_core::vx_ref_plus(file);
                vx_core::Type_string url = vx_data_file::f_pathfull_from_file(file);
                vx_core::vx_ref_plus(url);
                vx_core::Type_string output_1 = vx_core::f_if_2(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({url}, [url]() {
                        vx_core::Type_boolean output_1 = vx_core::f_notempty(url);
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({url}, [url]() {
                        vx_core::Type_string output_1 = vx_core::f_new(
                          vx_core::t_string,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string("url("),
                            url,
                            vx_core::vx_new_string(")")
                          })
                        );
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_release_one_except({file, url}, output_1);
                return output_1;
              })
            );
            return output_1;
          })
        )
      })
    );
    vx_core::vx_release_one_except(image, output);
    return output;
  }
  /**
   * @function string_style_from_image
   * Returns an image css string from a logical image.
   * @param  {image} image
   * @return {string}
   * (func string-style<-image)
   */
  // (func string-style<-image)
  // class Class_string_style_from_image {
    Abstract_string_style_from_image::~Abstract_string_style_from_image() {}

    Class_string_style_from_image::Class_string_style_from_image() : Abstract_string_style_from_image::Abstract_string_style_from_image() {
      vx_core::refcount += 1;
    }

    Class_string_style_from_image::~Class_string_style_from_image() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_style_from_image::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_string_style_from_image output = vx_ui_html_uihtml::e_string_style_from_image;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_style_from_image::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_string_style_from_image output = vx_ui_html_uihtml::e_string_style_from_image;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_style_from_image::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "string-style<-image", // name
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

    vx_core::Type_constdef Class_string_style_from_image::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_style_from_image::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "string-style<-image", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_style_from_image::vx_empty() const {return vx_ui_html_uihtml::e_string_style_from_image;}
    vx_core::Type_any Class_string_style_from_image::vx_type() const {return vx_ui_html_uihtml::t_string_style_from_image;}
    vx_core::Type_msgblock Class_string_style_from_image::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_style_from_image::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_string_style_from_image::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_string_style_from_image::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_image inputval = vx_core::vx_any_from_any(vx_ui_ui::t_image, val);
      output = vx_ui_html_uihtml::f_string_style_from_image(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_string_style_from_image::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_image image = vx_core::vx_any_from_any(vx_ui_ui::t_image, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_html_uihtml::f_string_style_from_image(image);
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
            vx_core::Type_string output_1 = vx_core::f_new(
              vx_core::t_string,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string("#"),
                name
              })
            );
            return output_1;
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func->vx_fn_new({name}, [name]() {
            vx_core::Type_any output_1 = name;
            return output_1;
          })
        )
      })
    );
    vx_core::vx_release_one_except({name, styletype}, output);
    return output;
  }
  /**
   * @function string_stylename_from_name_styletype
   * @param  {string} name
   * @param  {styletype} styletype
   * @return {string}
   * (func string-stylename<-name-styletype)
   */
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

  // (func style<-fontface)
  vx_web_html::Type_style f_style_from_fontface(vx_ui_ui::Type_fontface fontface) {
    vx_web_html::Type_style output = vx_web_html::e_style;
    vx_core::vx_reserve(fontface);
    output = vx_core::f_let(
      vx_web_html::t_style,
      vx_core::t_any_from_func->vx_fn_new({fontface}, [fontface]() {
        vx_core::Type_string name = fontface->name();
        vx_core::vx_ref_plus(name);
        vx_core::Type_string weight = fontface->weight();
        vx_core::vx_ref_plus(weight);
        vx_core::Type_string unicode = fontface->unicode();
        vx_core::vx_ref_plus(unicode);
        vx_data_file::Type_filelist files = fontface->filelist();
        vx_core::vx_ref_plus(files);
        vx_core::Type_stringlist urls = vx_core::f_list_from_list_1(
          vx_core::t_stringlist,
          files,
          vx_core::t_any_from_any->vx_fn_new({}, [](vx_core::Type_any file_any) {
            vx_data_file::Type_file file = vx_core::vx_any_from_any(vx_data_file::t_file, file_any);
            vx_core::Type_any output_1 = 
              vx_core::f_new(
                vx_core::t_string,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string("url("),
                  vx_data_file::f_pathfull_from_file(file),
                  vx_core::vx_new_string(")")
                })
              );
            return output_1;
          })
        );
        vx_core::vx_ref_plus(urls);
        vx_core::Type_string fontfamily = vx_core::f_new(
          vx_core::t_string,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::c_quote,
            name,
            vx_core::c_quote
          })
        );
        vx_core::vx_ref_plus(fontfamily);
        vx_core::Type_string srcurls = vx_type::f_string_from_stringlist_join(urls, vx_core::vx_new_string(","));
        vx_core::vx_ref_plus(srcurls);
        vx_core::Type_string src = vx_core::f_new(
          vx_core::t_string,
          vx_core::vx_new(vx_core::t_anylist, {
            srcurls,
            vx_core::vx_new_string(";")
          })
        );
        vx_core::vx_ref_plus(src);
        vx_web_html::Type_propmap propmap = vx_core::f_new(
          vx_web_html::t_propmap,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":font-family"),
            fontfamily,
            vx_core::vx_new_string(":font-style"),
            vx_core::vx_new_string("normal"),
            vx_core::vx_new_string(":font-weight"),
            weight,
            vx_core::vx_new_string(":font-display"),
            vx_core::vx_new_string("swap"),
            vx_core::vx_new_string(":src"),
            src,
            vx_core::vx_new_string(":unicode-range"),
            unicode
          })
        );
        vx_core::vx_ref_plus(propmap);
        vx_web_html::Type_style output_1 = vx_core::f_new(
          vx_web_html::t_style,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":name"),
            vx_core::vx_new_string("@font-face"),
            vx_core::vx_new_string(":props"),
            propmap
          })
        );
        vx_core::vx_release_one_except({name, weight, unicode, files, urls, fontfamily, srcurls, src, propmap}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(fontface, output);
    return output;
  }
  /**
   * @function style_from_fontface
   * Returns an html style from a font
   * @param  {fontface} fontface
   * @return {style}
   * (func style<-fontface)
   */
  // (func style<-fontface)
  // class Class_style_from_fontface {
    Abstract_style_from_fontface::~Abstract_style_from_fontface() {}

    Class_style_from_fontface::Class_style_from_fontface() : Abstract_style_from_fontface::Abstract_style_from_fontface() {
      vx_core::refcount += 1;
    }

    Class_style_from_fontface::~Class_style_from_fontface() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_style_from_fontface::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_style_from_fontface output = vx_ui_html_uihtml::e_style_from_fontface;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_style_from_fontface::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_style_from_fontface output = vx_ui_html_uihtml::e_style_from_fontface;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_style_from_fontface::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "style<-fontface", // name
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

    vx_core::Type_constdef Class_style_from_fontface::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_style_from_fontface::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "style<-fontface", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_style_from_fontface::vx_empty() const {return vx_ui_html_uihtml::e_style_from_fontface;}
    vx_core::Type_any Class_style_from_fontface::vx_type() const {return vx_ui_html_uihtml::t_style_from_fontface;}
    vx_core::Type_msgblock Class_style_from_fontface::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_style_from_fontface::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_style_from_fontface::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_style_from_fontface::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_fontface inputval = vx_core::vx_any_from_any(vx_ui_ui::t_fontface, val);
      output = vx_ui_html_uihtml::f_style_from_fontface(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_style_from_fontface::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_fontface fontface = vx_core::vx_any_from_any(vx_ui_ui::t_fontface, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_html_uihtml::f_style_from_fontface(fontface);
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
                vx_ui_ui::Type_font font = uistyle->font();
                vx_core::vx_ref_plus(font);
                vx_ui_ui::Type_pin pin = uistyle->pin();
                vx_core::vx_ref_plus(pin);
                vx_ui_ui::Type_point pointpos = uistyle->pointpos();
                vx_core::vx_ref_plus(pointpos);
                vx_ui_ui::Type_point pointsize = uistyle->pointsize();
                vx_core::vx_ref_plus(pointsize);
                vx_ui_ui::Type_point pointrotate = uistyle->pointrotate();
                vx_core::vx_ref_plus(pointrotate);
                vx_ui_ui::Type_styletype styletype = uistyle->type();
                vx_core::vx_ref_plus(styletype);
                vx_core::Type_string color_bkg = uistyle->color_background();
                vx_core::vx_ref_plus(color_bkg);
                vx_core::Type_string color_border = uistyle->color_border();
                vx_core::vx_ref_plus(color_border);
                vx_core::Type_string color_font = uistyle->color_font();
                vx_core::vx_ref_plus(color_font);
                vx_core::Type_string color_hoverbkg = uistyle->color_hoverbkgrd();
                vx_core::vx_ref_plus(color_hoverbkg);
                vx_ui_ui::Type_cursor cursor = uistyle->cursor();
                vx_core::vx_ref_plus(cursor);
                vx_core::Type_boolean hidden = uistyle->hidden();
                vx_core::vx_ref_plus(hidden);
                vx_ui_ui::Type_align align = uistyle->align();
                vx_core::vx_ref_plus(align);
                vx_core::Type_boolean scroll_x = uistyle->scroll_x();
                vx_core::vx_ref_plus(scroll_x);
                vx_core::Type_boolean scroll_y = uistyle->scroll_y();
                vx_core::vx_ref_plus(scroll_y);
                vx_core::Type_int posx = pointpos->x();
                vx_core::vx_ref_plus(posx);
                vx_core::Type_int posy = pointpos->y();
                vx_core::vx_ref_plus(posy);
                vx_ui_ui::Type_pointtype postype = pointpos->pointtype();
                vx_core::vx_ref_plus(postype);
                vx_core::Type_int sizex = pointsize->x();
                vx_core::vx_ref_plus(sizex);
                vx_core::Type_int sizey = pointsize->y();
                vx_core::vx_ref_plus(sizey);
                vx_ui_ui::Type_pointtype sizetype = pointsize->pointtype();
                vx_core::vx_ref_plus(sizetype);
                vx_core::Type_string stylename = vx_ui_html_uihtml::f_string_stylename_from_name_styletype(name, styletype);
                vx_core::vx_ref_plus(stylename);
                vx_core::Type_string bkgcolor = vx_core::f_if_2(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({color_bkg}, [color_bkg]() {
                        vx_core::Type_boolean output_1 = vx_core::f_notempty(color_bkg);
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({color_bkg}, [color_bkg]() {
                        vx_core::Type_string output_1 = vx_core::f_new(
                          vx_core::t_string,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string("#"),
                            color_bkg
                          })
                        );
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(bkgcolor);
                vx_core::Type_string borderwidth = vx_core::f_if_2(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({color_border}, [color_border]() {
                        vx_core::Type_boolean output_1 = vx_core::f_notempty(color_border);
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("thin");
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(borderwidth);
                vx_core::Type_string bordercolor = vx_core::f_if_2(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({color_border}, [color_border]() {
                        vx_core::Type_boolean output_1 = vx_core::f_notempty(color_border);
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({color_border}, [color_border]() {
                        vx_core::Type_string output_1 = vx_core::f_new(
                          vx_core::t_string,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string("#"),
                            color_border
                          })
                        );
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(bordercolor);
                vx_core::Type_string borderstyle = vx_core::f_if_2(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({color_border}, [color_border]() {
                        vx_core::Type_boolean output_1 = vx_core::f_notempty(color_border);
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::f_new(
                          vx_core::t_string,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string("solid")
                          })
                        );
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(borderstyle);
                vx_core::Type_string fontcolor = vx_core::f_if_2(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({color_font}, [color_font]() {
                        vx_core::Type_boolean output_1 = vx_core::f_notempty(color_font);
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({color_font}, [color_font]() {
                        vx_core::Type_string output_1 = vx_core::f_new(
                          vx_core::t_string,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string("#"),
                            color_font
                          })
                        );
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(fontcolor);
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
                            ),
                            vx_core::f_eqeq(
                              layout,
                              vx_ui_ui::c_layout_titlebar
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
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({postype}, [postype]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(
                          postype,
                          vx_ui_ui::c_pointtype_relative
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("relative");
                        return output_1;
                      })
                    ),
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({postype}, [postype]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(
                          postype,
                          vx_ui_ui::c_pointtype_absolute
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("absolute");
                        return output_1;
                      })
                    ),
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({pointpos}, [pointpos]() {
                        vx_core::Type_boolean output_1 = vx_core::f_notempty_1(pointpos);
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("absolute");
                        return output_1;
                      })
                    ),
                    vx_core::f_else(
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("");
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
                      vx_core::t_boolean_from_func->vx_fn_new({sizetype}, [sizetype]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(
                          sizetype,
                          vx_ui_ui::c_pointtype_percent
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({sizey}, [sizey]() {
                        vx_core::Type_string output_1 = vx_core::f_new(
                          vx_core::t_string,
                          vx_core::vx_new(vx_core::t_anylist, {
                            sizey,
                            vx_core::vx_new_string("%")
                          })
                        );
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
                      vx_core::t_boolean_from_func->vx_fn_new({sizetype}, [sizetype]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(
                          sizetype,
                          vx_ui_ui::c_pointtype_percent
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({sizex}, [sizex]() {
                        vx_core::Type_string output_1 = vx_core::f_new(
                          vx_core::t_string,
                          vx_core::vx_new(vx_core::t_anylist, {
                            sizex,
                            vx_core::vx_new_string("%")
                          })
                        );
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
                      vx_core::t_boolean_from_func->vx_fn_new({hidden}, [hidden]() {
                        vx_core::Type_boolean output_1 = hidden;
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("none");
                        return output_1;
                      })
                    ),
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({layout}, [layout]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(
                          layout,
                          vx_ui_ui::c_layout_flow_item
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("inline-block");
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(display);
                vx_core::Type_string sfont = vx_ui_html_uihtml::f_string_style_from_font(font);
                vx_core::vx_ref_plus(sfont);
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
                      vx_core::t_boolean_from_func->vx_fn_new({scroll_x}, [scroll_x]() {
                        vx_core::Type_boolean output_1 = scroll_x;
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("auto");
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
                      vx_core::t_boolean_from_func->vx_fn_new({scroll_y}, [scroll_y]() {
                        vx_core::Type_boolean output_1 = scroll_y;
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("auto");
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
                      vx_core::t_boolean_from_func->vx_fn_new({color_hoverbkg}, [color_hoverbkg]() {
                        vx_core::Type_boolean output_1 = vx_core::f_ne(vx_core::vx_new_string(""), color_hoverbkg);
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({color_hoverbkg}, [color_hoverbkg]() {
                        vx_core::Type_string output_1 = vx_core::f_new(
                          vx_core::t_string,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string("#"),
                            color_hoverbkg
                          })
                        );
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(hoverbkgrdcolor);
                vx_core::Type_string scursor = vx_core::f_if_2(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({cursor}, [cursor]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(
                          cursor,
                          vx_ui_ui::t_cursor_pointer
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("pointer");
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(scursor);
                vx_core::Type_string textalign = vx_core::f_if_2(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({align}, [align]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(
                          align,
                          vx_ui_ui::c_align_left
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("left");
                        return output_1;
                      })
                    ),
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({align}, [align]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(
                          align,
                          vx_ui_ui::c_align_center
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("center");
                        return output_1;
                      })
                    ),
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({align}, [align]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(
                          align,
                          vx_ui_ui::c_align_right
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("right");
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(textalign);
                vx_core::Type_string transform = vx_core::f_if_2(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({pointrotate}, [pointrotate]() {
                        vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(pointrotate);
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("");
                        return output_1;
                      })
                    ),
                    vx_core::f_else(
                      vx_core::t_any_from_func->vx_fn_new({pointrotate}, [pointrotate]() {
                        vx_core::Type_string output_1 = vx_core::f_new(
                          vx_core::t_string,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string("rotate("),
                            pointrotate->x(),
                            vx_core::vx_new_string("deg)")
                          })
                        );
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(transform);
                vx_core::Type_string transformorigin = vx_core::f_if_2(
                  vx_core::t_string,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({pointrotate}, [pointrotate]() {
                        vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(pointrotate);
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("");
                        return output_1;
                      })
                    ),
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({layout}, [layout]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eqeq(
                          layout,
                          vx_ui_ui::c_layout_label
                        );
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({}, []() {
                        vx_core::Type_string output_1 = vx_core::vx_new_string("left top");
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(transformorigin);
                vx_web_html::Type_propmap props = vx_core::f_new(
                  vx_web_html::t_propmap,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":background-color"),
                    bkgcolor,
                    vx_core::vx_new_string(":border-color"),
                    bordercolor,
                    vx_core::vx_new_string(":border-style"),
                    borderstyle,
                    vx_core::vx_new_string(":border-width"),
                    borderwidth,
                    vx_core::vx_new_string(":color"),
                    fontcolor,
                    vx_core::vx_new_string(":cursor"),
                    scursor,
                    vx_core::vx_new_string(":display"),
                    display,
                    vx_core::vx_new_string(":font"),
                    sfont,
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
                    overflowy,
                    vx_core::vx_new_string(":text-align"),
                    textalign,
                    vx_core::vx_new_string(":transform"),
                    transform,
                    vx_core::vx_new_string(":transform-origin"),
                    transformorigin
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
                vx_web_html::Type_stylelist substylelist = vx_core::f_if_2(
                  vx_web_html::t_stylelist,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({hoverprops}, [hoverprops]() {
                        vx_core::Type_boolean output_1 = vx_core::f_notempty_1(hoverprops);
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({hoverprops}, [hoverprops]() {
                        vx_web_html::Type_stylelist output_1 = vx_core::f_new(
                          vx_web_html::t_stylelist,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::f_new(
                              vx_web_html::t_style,
                              vx_core::vx_new(vx_core::t_anylist, {
                                vx_core::vx_new_string(":name"),
                                vx_core::vx_new_string("&:hover"),
                                vx_core::vx_new_string(":props"),
                                hoverprops
                              })
                            )
                          })
                        );
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_ref_plus(substylelist);
                vx_web_html::Type_style output_1 = vx_core::f_new(
                  vx_web_html::t_style,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":name"),
                    stylename,
                    vx_core::vx_new_string(":props"),
                    props,
                    vx_core::vx_new_string(":stylelist"),
                    substylelist
                  })
                );
                vx_core::vx_release_one_except({layout, name, font, pin, pointpos, pointsize, pointrotate, styletype, color_bkg, color_border, color_font, color_hoverbkg, cursor, hidden, align, scroll_x, scroll_y, posx, posy, postype, sizex, sizey, sizetype, stylename, bkgcolor, borderwidth, bordercolor, borderstyle, fontcolor, position, top, bottom, left, right, height, width, display, sfont, gap, overflowx, overflowy, hoverbkgrdcolor, scursor, textalign, transform, transformorigin, props, hoverprops, substylelist}, output_1);
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
  /**
   * @function style_from_style
   * Returns a htmlstyle from a uistyle
   * @param  {style} uistyle
   * @return {style}
   * (func style<-style)
   */
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

  // (func stylelist-extra<-ui)
  vx_web_html::Type_stylelist f_stylelist_extra_from_ui(vx_ui_ui::Type_ui ui) {
    vx_web_html::Type_stylelist output = vx_web_html::e_stylelist;
    vx_core::vx_reserve(ui);
    output = vx_core::f_let(
      vx_web_html::t_stylelist,
      vx_core::t_any_from_func->vx_fn_new({ui}, [ui]() {
        vx_ui_ui::Type_stylelist uistyles = ui->stylelist();
        vx_core::vx_ref_plus(uistyles);
        vx_core::Type_boolean selected = ui->selected();
        vx_core::vx_ref_plus(selected);
        vx_core::Type_boolean hidden = ui->hidden();
        vx_core::vx_ref_plus(hidden);
        vx_web_html::Type_stylelist styles1 = vx_ui_html_uihtml::f_stylelist_from_stylelist(uistyles);
        vx_core::vx_ref_plus(styles1);
        vx_web_html::Type_stylelist styles2 = vx_core::f_if_2(
          vx_web_html::t_stylelist,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({hidden}, [hidden]() {
                vx_core::Type_boolean output_1 = hidden;
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({styles1}, [styles1]() {
                vx_core::Type_any output_1 = vx_core::f_copy(
                  vx_web_html::t_stylelist,
                  styles1,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_ui_html_uihtml::c_style_hidden
                  })
                );
                return output_1;
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({selected}, [selected]() {
                vx_core::Type_boolean output_1 = selected;
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({styles1}, [styles1]() {
                vx_core::Type_any output_1 = vx_core::f_copy(
                  vx_web_html::t_stylelist,
                  styles1,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_ui_html_uihtml::c_style_selected
                  })
                );
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({styles1}, [styles1]() {
                vx_core::Type_any output_1 = styles1;
                return output_1;
              })
            )
          })
        );
        vx_core::vx_ref_plus(styles2);
        vx_web_html::Type_stylelist output_1 = styles2;
        vx_core::vx_release_one_except({uistyles, selected, hidden, styles1, styles2}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(ui, output);
    return output;
  }
  /**
   * @function stylelist_extra_from_ui
   * Returns a stylelist from a ui including style-hidden and style-selected
   * @param  {ui} ui
   * @return {stylelist}
   * (func stylelist-extra<-ui)
   */
  // (func stylelist-extra<-ui)
  // class Class_stylelist_extra_from_ui {
    Abstract_stylelist_extra_from_ui::~Abstract_stylelist_extra_from_ui() {}

    Class_stylelist_extra_from_ui::Class_stylelist_extra_from_ui() : Abstract_stylelist_extra_from_ui::Abstract_stylelist_extra_from_ui() {
      vx_core::refcount += 1;
    }

    Class_stylelist_extra_from_ui::~Class_stylelist_extra_from_ui() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_stylelist_extra_from_ui::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_stylelist_extra_from_ui output = vx_ui_html_uihtml::e_stylelist_extra_from_ui;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_stylelist_extra_from_ui::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_stylelist_extra_from_ui output = vx_ui_html_uihtml::e_stylelist_extra_from_ui;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_stylelist_extra_from_ui::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylelist-extra<-ui", // name
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

    vx_core::Type_constdef Class_stylelist_extra_from_ui::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_stylelist_extra_from_ui::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylelist-extra<-ui", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_stylelist_extra_from_ui::vx_empty() const {return vx_ui_html_uihtml::e_stylelist_extra_from_ui;}
    vx_core::Type_any Class_stylelist_extra_from_ui::vx_type() const {return vx_ui_html_uihtml::t_stylelist_extra_from_ui;}
    vx_core::Type_msgblock Class_stylelist_extra_from_ui::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_stylelist_extra_from_ui::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_stylelist_extra_from_ui::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_stylelist_extra_from_ui::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui inputval = vx_core::vx_any_from_any(vx_ui_ui::t_ui, val);
      output = vx_ui_html_uihtml::f_stylelist_extra_from_ui(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_stylelist_extra_from_ui::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_html_uihtml::f_stylelist_extra_from_ui(ui);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func stylelist-reset)
  vx_web_html::Type_stylelist f_stylelist_reset() {
    vx_web_html::Type_stylelist output = vx_web_html::e_stylelist;
    output = vx_core::f_new(
      vx_web_html::t_stylelist,
      vx_core::vx_new(vx_core::t_anylist, {
        vx_core::f_new(
          vx_web_html::t_style,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":name"),
            vx_core::vx_new_string("html"),
            vx_core::vx_new_string(":props"),
            vx_core::f_new(
              vx_web_html::t_propmap,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":border"),
                vx_core::vx_new_string("0mm"),
                vx_core::vx_new_string(":margin"),
                vx_core::vx_new_string("0mm"),
                vx_core::vx_new_string(":padding"),
                vx_core::vx_new_string("0mm")
              })
            )
          })
        ),
        vx_core::f_new(
          vx_web_html::t_style,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":name"),
            vx_core::vx_new_string("body"),
            vx_core::vx_new_string(":props"),
            vx_core::f_new(
              vx_web_html::t_propmap,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":border"),
                vx_core::vx_new_string("0mm"),
                vx_core::vx_new_string(":margin"),
                vx_core::vx_new_string("0mm"),
                vx_core::vx_new_string(":padding"),
                vx_core::vx_new_string("0mm")
              })
            )
          })
        ),
        vx_core::f_new(
          vx_web_html::t_style,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":name"),
            vx_core::vx_new_string("div"),
            vx_core::vx_new_string(":props"),
            vx_core::f_new(
              vx_web_html::t_propmap,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":border"),
                vx_core::vx_new_string("0mm"),
                vx_core::vx_new_string(":box-sizing"),
                vx_core::vx_new_string("border-box"),
                vx_core::vx_new_string(":margin"),
                vx_core::vx_new_string("0mm"),
                vx_core::vx_new_string(":padding"),
                vx_core::vx_new_string("0mm"),
                vx_core::vx_new_string(":position"),
                vx_core::vx_new_string("relative")
              })
            )
          })
        ),
        vx_core::f_new(
          vx_web_html::t_style,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":name"),
            vx_core::vx_new_string("img"),
            vx_core::vx_new_string(":props"),
            vx_core::f_new(
              vx_web_html::t_propmap,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":border"),
                vx_core::vx_new_string("0mm"),
                vx_core::vx_new_string(":display"),
                vx_core::vx_new_string("block"),
                vx_core::vx_new_string(":margin"),
                vx_core::vx_new_string("0mm"),
                vx_core::vx_new_string(":padding"),
                vx_core::vx_new_string("0mm")
              })
            )
          })
        ),
        vx_core::f_new(
          vx_web_html::t_style,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":name"),
            vx_core::vx_new_string("p"),
            vx_core::vx_new_string(":props"),
            vx_core::f_new(
              vx_web_html::t_propmap,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":margin-block-start"),
                vx_core::vx_new_string("0mm"),
                vx_core::vx_new_string(":margin-block-end"),
                vx_core::vx_new_string("0mm"),
                vx_core::vx_new_string(":white-space"),
                vx_core::vx_new_string("pre-line")
              })
            )
          })
        ),
        vx_core::f_new(
          vx_web_html::t_style,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":name"),
            vx_core::vx_new_string("*"),
            vx_core::vx_new_string(":props"),
            vx_core::f_new(
              vx_web_html::t_propmap,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":-webkit-print-color-adjust"),
                vx_core::vx_new_string("exact !important"),
                vx_core::vx_new_string(":color-adjust"),
                vx_core::vx_new_string("exact !important"),
                vx_core::vx_new_string(":print-color-adjust"),
                vx_core::vx_new_string("exact !important")
              })
            )
          })
        )
      })
    );
    return output;
  }
  /**
   * @function stylelist_reset
   * Returns the initial reset styles for ui framework
   * @return {stylelist}
   * (func stylelist-reset)
   */
  // (func stylelist-reset)
  // class Class_stylelist_reset {
    Abstract_stylelist_reset::~Abstract_stylelist_reset() {}

    Class_stylelist_reset::Class_stylelist_reset() : Abstract_stylelist_reset::Abstract_stylelist_reset() {
      vx_core::refcount += 1;
    }

    Class_stylelist_reset::~Class_stylelist_reset() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_stylelist_reset::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_stylelist_reset output = vx_ui_html_uihtml::e_stylelist_reset;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_stylelist_reset::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_stylelist_reset output = vx_ui_html_uihtml::e_stylelist_reset;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_stylelist_reset::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylelist-reset", // name
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

    vx_core::Type_constdef Class_stylelist_reset::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_stylelist_reset::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylelist-reset", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_stylelist_reset::vx_empty() const {return vx_ui_html_uihtml::e_stylelist_reset;}
    vx_core::Type_any Class_stylelist_reset::vx_type() const {return vx_ui_html_uihtml::t_stylelist_reset;}
    vx_core::Type_msgblock Class_stylelist_reset::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_stylelist_reset::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_stylelist_reset::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      output = vx_ui_html_uihtml::f_stylelist_reset();
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func stylelist<-fontfacemap)
  vx_web_html::Type_stylelist f_stylelist_from_fontfacemap(vx_ui_ui::Type_fontfacemap fontfacemap) {
    vx_web_html::Type_stylelist output = vx_web_html::e_stylelist;
    vx_core::vx_reserve(fontfacemap);
    output = vx_core::f_list_from_map_1(
      vx_web_html::t_stylelist,
      fontfacemap,
      vx_core::t_any_from_key_value->vx_fn_new({}, [](vx_core::Type_any key_any, vx_core::Type_any fontface_any) {
        vx_core::Type_string key = vx_core::vx_any_from_any(vx_core::t_string, key_any);
        vx_ui_ui::Type_fontface fontface = vx_core::vx_any_from_any(vx_ui_ui::t_fontface, fontface_any);
        vx_core::Type_any output_1 = 
          vx_ui_html_uihtml::f_style_from_fontface(fontface);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(fontfacemap, output);
    return output;
  }
  /**
   * @function stylelist_from_fontfacemap
   * Returns stylelist from a fontfacemap
   * @param  {fontfacemap} fontfacemap
   * @return {stylelist}
   * (func stylelist<-fontfacemap)
   */
  // (func stylelist<-fontfacemap)
  // class Class_stylelist_from_fontfacemap {
    Abstract_stylelist_from_fontfacemap::~Abstract_stylelist_from_fontfacemap() {}

    Class_stylelist_from_fontfacemap::Class_stylelist_from_fontfacemap() : Abstract_stylelist_from_fontfacemap::Abstract_stylelist_from_fontfacemap() {
      vx_core::refcount += 1;
    }

    Class_stylelist_from_fontfacemap::~Class_stylelist_from_fontfacemap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_stylelist_from_fontfacemap::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_stylelist_from_fontfacemap output = vx_ui_html_uihtml::e_stylelist_from_fontfacemap;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_stylelist_from_fontfacemap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_stylelist_from_fontfacemap output = vx_ui_html_uihtml::e_stylelist_from_fontfacemap;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_stylelist_from_fontfacemap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylelist<-fontfacemap", // name
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

    vx_core::Type_constdef Class_stylelist_from_fontfacemap::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_stylelist_from_fontfacemap::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylelist<-fontfacemap", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_stylelist_from_fontfacemap::vx_empty() const {return vx_ui_html_uihtml::e_stylelist_from_fontfacemap;}
    vx_core::Type_any Class_stylelist_from_fontfacemap::vx_type() const {return vx_ui_html_uihtml::t_stylelist_from_fontfacemap;}
    vx_core::Type_msgblock Class_stylelist_from_fontfacemap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_stylelist_from_fontfacemap::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_stylelist_from_fontfacemap::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_stylelist_from_fontfacemap::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_fontfacemap inputval = vx_core::vx_any_from_any(vx_ui_ui::t_fontfacemap, val);
      output = vx_ui_html_uihtml::f_stylelist_from_fontfacemap(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_stylelist_from_fontfacemap::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_fontfacemap fontfacemap = vx_core::vx_any_from_any(vx_ui_ui::t_fontfacemap, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_html_uihtml::f_stylelist_from_fontfacemap(fontfacemap);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func stylelist<-stylelist)
  vx_web_html::Type_stylelist f_stylelist_from_stylelist(vx_ui_ui::Type_stylelist uistylelist) {
    vx_web_html::Type_stylelist output = vx_web_html::e_stylelist;
    vx_core::vx_reserve(uistylelist);
    output = vx_core::f_list_from_list_1(
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
  /**
   * @function stylelist_from_stylelist
   * Returns a htmlstylelist from a uistylemap
   * @param  {stylelist} uistylelist
   * @return {stylelist}
   * (func stylelist<-stylelist)
   */
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
    output = vx_core::f_list_from_map_1(
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
  /**
   * @function stylelist_from_stylemap
   * Returns a htmlstylelist from a uistylemap
   * @param  {stylemap} uistylemap
   * @return {stylelist}
   * (func stylelist<-stylemap)
   */
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
    output = vx_core::f_map_from_map_1(
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
  /**
   * @function stylemap_from_stylemap
   * Returns a htmlstylesheet from a uistylesheet
   * @param  {stylemap} uistylemap
   * @return {stylemap}
   * (func stylemap<-stylemap)
   */
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

  // (func stylesheet-layout-html)
  vx_core::vx_Type_async f_stylesheet_layout_html(vx_ui_ui::Type_stylesheet stylesheetui) {
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
  /**
   * 
   * @async
   * @function stylesheet_layout_html
   * @param  {stylesheet} stylesheetui
   * @return {stylesheet}
   * (func stylesheet-layout-html)
   */
  // (func stylesheet-layout-html)
  // class Class_stylesheet_layout_html {
    Abstract_stylesheet_layout_html::~Abstract_stylesheet_layout_html() {}

    Class_stylesheet_layout_html::Class_stylesheet_layout_html() : Abstract_stylesheet_layout_html::Abstract_stylesheet_layout_html() {
      vx_core::refcount += 1;
    }

    Class_stylesheet_layout_html::~Class_stylesheet_layout_html() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_stylesheet_layout_html::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_stylesheet_layout_html output = vx_ui_html_uihtml::e_stylesheet_layout_html;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_stylesheet_layout_html::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_stylesheet_layout_html output = vx_ui_html_uihtml::e_stylesheet_layout_html;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_stylesheet_layout_html::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylesheet-layout-html", // name
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

    vx_core::Type_constdef Class_stylesheet_layout_html::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_stylesheet_layout_html::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylesheet-layout-html", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_stylesheet_layout_html::vx_empty() const {return vx_ui_html_uihtml::e_stylesheet_layout_html;}
    vx_core::Type_any Class_stylesheet_layout_html::vx_type() const {return vx_ui_html_uihtml::t_stylesheet_layout_html;}
    vx_core::Type_msgblock Class_stylesheet_layout_html::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_stylesheet_layout_html::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_async Class_stylesheet_layout_html::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const {
      return vx_core::e_any_from_any_async;
    }

    vx_core::vx_Type_async Class_stylesheet_layout_html::vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const {
      vx_ui_ui::Type_stylesheet inputval = vx_core::vx_any_from_any(vx_ui_ui::t_stylesheet, val);
      vx_core::vx_Type_async output = vx_ui_html_uihtml::f_stylesheet_layout_html(inputval);
      vx_core::vx_release(val);
      return output;
    }

    vx_core::vx_Type_async Class_stylesheet_layout_html::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_value(vx_core::e_any);
      vx_ui_ui::Type_stylesheet stylesheetui = vx_core::vx_any_from_any(vx_ui_ui::t_stylesheet, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_html_uihtml::f_stylesheet_layout_html(stylesheetui);
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
        vx_ui_ui::Type_fontfacemap fontfacemap = uistylesheet->fontfacemap();
        vx_core::vx_ref_plus(fontfacemap);
        vx_web_html::Type_stylelist resetlist = vx_ui_html_uihtml::f_stylelist_reset();
        vx_core::vx_ref_plus(resetlist);
        vx_web_html::Type_stylelist fontstyles = vx_ui_html_uihtml::f_stylelist_from_fontfacemap(fontfacemap);
        vx_core::vx_ref_plus(fontstyles);
        vx_web_html::Type_stylelist stylelist = vx_ui_html_uihtml::f_stylelist_from_stylemap(uistylemap);
        vx_core::vx_ref_plus(stylelist);
        vx_web_html::Type_stylelist allstyles = vx_core::f_new(
          vx_web_html::t_stylelist,
          vx_core::vx_new(vx_core::t_anylist, {
            resetlist,
            fontstyles,
            stylelist
          })
        );
        vx_core::vx_ref_plus(allstyles);
        vx_web_html::Type_stylesheet output_1 = vx_core::f_new(
          vx_web_html::t_stylesheet,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":styles"),
            allstyles
          })
        );
        vx_core::vx_release_one_except({uistylemap, fontfacemap, resetlist, fontstyles, stylelist, allstyles}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(uistylesheet, output);
    return output;
  }
  /**
   * @function stylesheet_from_stylesheet
   * Returns a htmlstylesheet from a uistylesheet
   * @param  {stylesheet} uistylesheet
   * @return {stylesheet}
   * (func stylesheet<-stylesheet)
   */
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

  // (func ui-layout-app<-ui-orig-parent)
  vx_ui_ui::Type_ui f_ui_layout_app_from_ui_orig_parent(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_ui orig, vx_ui_ui::Type_ui parent) {
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
        vx_web_html::Type_node nodechg = vx_ui_html_uihtml::f_node_layout_from_node_ui(node, ui);
        vx_core::vx_ref_plus(nodechg);
        vx_ui_ui::Type_uimap uimapchg = vx_ui_ui::f_uimap_layout_from_uimap_parent(uimap, ui);
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
  /**
   * @function ui_layout_app_from_ui_orig_parent
   * @param  {ui} ui
   * @param  {ui} orig
   * @param  {ui} parent
   * @return {ui}
   * (func ui-layout-app<-ui-orig-parent)
   */
  // (func ui-layout-app<-ui-orig-parent)
  // class Class_ui_layout_app_from_ui_orig_parent {
    Abstract_ui_layout_app_from_ui_orig_parent::~Abstract_ui_layout_app_from_ui_orig_parent() {}

    Class_ui_layout_app_from_ui_orig_parent::Class_ui_layout_app_from_ui_orig_parent() : Abstract_ui_layout_app_from_ui_orig_parent::Abstract_ui_layout_app_from_ui_orig_parent() {
      vx_core::refcount += 1;
    }

    Class_ui_layout_app_from_ui_orig_parent::~Class_ui_layout_app_from_ui_orig_parent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_ui_layout_app_from_ui_orig_parent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_ui_layout_app_from_ui_orig_parent output = vx_ui_html_uihtml::e_ui_layout_app_from_ui_orig_parent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_ui_layout_app_from_ui_orig_parent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_ui_layout_app_from_ui_orig_parent output = vx_ui_html_uihtml::e_ui_layout_app_from_ui_orig_parent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_ui_layout_app_from_ui_orig_parent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "ui-layout-app<-ui-orig-parent", // name
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

    vx_core::Type_constdef Class_ui_layout_app_from_ui_orig_parent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_ui_layout_app_from_ui_orig_parent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "ui-layout-app<-ui-orig-parent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_ui_layout_app_from_ui_orig_parent::vx_empty() const {return vx_ui_html_uihtml::e_ui_layout_app_from_ui_orig_parent;}
    vx_core::Type_any Class_ui_layout_app_from_ui_orig_parent::vx_type() const {return vx_ui_html_uihtml::t_ui_layout_app_from_ui_orig_parent;}
    vx_core::Type_msgblock Class_ui_layout_app_from_ui_orig_parent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ui_layout_app_from_ui_orig_parent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_ui_layout_app_from_ui_orig_parent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_ui orig = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_ui_ui::Type_ui parent = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_ui_html_uihtml::f_ui_layout_app_from_ui_orig_parent(ui, orig, parent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func ui-layout-default<-ui-orig-parent)
  vx_ui_ui::Type_ui f_ui_layout_default_from_ui_orig_parent(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_ui orig, vx_ui_ui::Type_ui parent) {
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
        vx_web_html::Type_style style = vx_ui_html_uihtml::f_style_from_style(uistyle);
        vx_core::vx_ref_plus(style);
        vx_web_html::Type_stylelist styles = vx_ui_html_uihtml::f_stylelist_extra_from_ui(ui);
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
        vx_web_html::Type_node nodechg = vx_ui_html_uihtml::f_node_layout_from_node_ui(node, ui);
        vx_core::vx_ref_plus(nodechg);
        vx_ui_ui::Type_uimap uimapchg = vx_ui_ui::f_uimap_layout_from_uimap_parent(uimap, ui);
        vx_core::vx_ref_plus(uimapchg);
        vx_ui_ui::Type_ui output_1 = vx_core::f_new(
          vx_ui_ui::t_ui,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":uimap"),
            uimapchg
          })
        );
        vx_core::vx_release_one_except({uid, uimap, uistyle, style, styles, children, node, nodechg, uimapchg}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({ui, orig, parent}, output);
    return output;
  }
  /**
   * @function ui_layout_default_from_ui_orig_parent
   * @param  {ui} ui
   * @param  {ui} orig
   * @param  {ui} parent
   * @return {ui}
   * (func ui-layout-default<-ui-orig-parent)
   */
  // (func ui-layout-default<-ui-orig-parent)
  // class Class_ui_layout_default_from_ui_orig_parent {
    Abstract_ui_layout_default_from_ui_orig_parent::~Abstract_ui_layout_default_from_ui_orig_parent() {}

    Class_ui_layout_default_from_ui_orig_parent::Class_ui_layout_default_from_ui_orig_parent() : Abstract_ui_layout_default_from_ui_orig_parent::Abstract_ui_layout_default_from_ui_orig_parent() {
      vx_core::refcount += 1;
    }

    Class_ui_layout_default_from_ui_orig_parent::~Class_ui_layout_default_from_ui_orig_parent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_ui_layout_default_from_ui_orig_parent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_ui_layout_default_from_ui_orig_parent output = vx_ui_html_uihtml::e_ui_layout_default_from_ui_orig_parent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_ui_layout_default_from_ui_orig_parent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_ui_layout_default_from_ui_orig_parent output = vx_ui_html_uihtml::e_ui_layout_default_from_ui_orig_parent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_ui_layout_default_from_ui_orig_parent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "ui-layout-default<-ui-orig-parent", // name
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

    vx_core::Type_constdef Class_ui_layout_default_from_ui_orig_parent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_ui_layout_default_from_ui_orig_parent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "ui-layout-default<-ui-orig-parent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_ui_layout_default_from_ui_orig_parent::vx_empty() const {return vx_ui_html_uihtml::e_ui_layout_default_from_ui_orig_parent;}
    vx_core::Type_any Class_ui_layout_default_from_ui_orig_parent::vx_type() const {return vx_ui_html_uihtml::t_ui_layout_default_from_ui_orig_parent;}
    vx_core::Type_msgblock Class_ui_layout_default_from_ui_orig_parent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ui_layout_default_from_ui_orig_parent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_ui_layout_default_from_ui_orig_parent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_ui orig = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_ui_ui::Type_ui parent = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_ui_html_uihtml::f_ui_layout_default_from_ui_orig_parent(ui, orig, parent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func ui-layout-image<-ui-orig-parent)
  vx_ui_ui::Type_ui f_ui_layout_image_from_ui_orig_parent(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_ui orig, vx_ui_ui::Type_ui parent) {
    vx_ui_ui::Type_ui output = vx_ui_ui::e_ui;
    vx_core::vx_reserve({ui, orig, parent});
    output = vx_core::f_let(
      vx_ui_ui::t_ui,
      vx_core::t_any_from_func->vx_fn_new({ui}, [ui]() {
        vx_core::Type_string uid = ui->uid();
        vx_core::vx_ref_plus(uid);
        vx_ui_ui::Type_style uistyle = ui->style();
        vx_core::vx_ref_plus(uistyle);
        vx_core::Type_any data = ui->data();
        vx_core::vx_ref_plus(data);
        vx_data_file::Type_file file = vx_core::f_any_from_any(vx_data_file::t_file, data);
        vx_core::vx_ref_plus(file);
        vx_core::Type_string path = vx_data_file::f_pathfull_from_file(file);
        vx_core::vx_ref_plus(path);
        vx_web_html::Type_style style = vx_ui_html_uihtml::f_style_from_style(uistyle);
        vx_core::vx_ref_plus(style);
        vx_web_html::Type_stylelist styles = vx_ui_html_uihtml::f_stylelist_extra_from_ui(ui);
        vx_core::vx_ref_plus(styles);
        vx_web_html::Type_node node = vx_core::f_new(
          vx_web_html::t_img,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":id"),
            uid,
            vx_core::vx_new_string(":style-unique"),
            style,
            vx_core::vx_new_string(":stylelist"),
            styles,
            vx_core::vx_new_string(":src"),
            path
          })
        );
        vx_core::vx_ref_plus(node);
        vx_web_html::Type_node nodechg = vx_ui_html_uihtml::f_node_layout_from_node_ui(node, ui);
        vx_core::vx_ref_plus(nodechg);
        vx_ui_ui::Type_ui output_1 = ui;
        vx_core::vx_release_one_except({uid, uistyle, data, file, path, style, styles, node, nodechg}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({ui, orig, parent}, output);
    return output;
  }
  /**
   * @function ui_layout_image_from_ui_orig_parent
   * @param  {ui} ui
   * @param  {ui} orig
   * @param  {ui} parent
   * @return {ui}
   * (func ui-layout-image<-ui-orig-parent)
   */
  // (func ui-layout-image<-ui-orig-parent)
  // class Class_ui_layout_image_from_ui_orig_parent {
    Abstract_ui_layout_image_from_ui_orig_parent::~Abstract_ui_layout_image_from_ui_orig_parent() {}

    Class_ui_layout_image_from_ui_orig_parent::Class_ui_layout_image_from_ui_orig_parent() : Abstract_ui_layout_image_from_ui_orig_parent::Abstract_ui_layout_image_from_ui_orig_parent() {
      vx_core::refcount += 1;
    }

    Class_ui_layout_image_from_ui_orig_parent::~Class_ui_layout_image_from_ui_orig_parent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_ui_layout_image_from_ui_orig_parent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_ui_layout_image_from_ui_orig_parent output = vx_ui_html_uihtml::e_ui_layout_image_from_ui_orig_parent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_ui_layout_image_from_ui_orig_parent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_ui_layout_image_from_ui_orig_parent output = vx_ui_html_uihtml::e_ui_layout_image_from_ui_orig_parent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_ui_layout_image_from_ui_orig_parent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "ui-layout-image<-ui-orig-parent", // name
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

    vx_core::Type_constdef Class_ui_layout_image_from_ui_orig_parent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_ui_layout_image_from_ui_orig_parent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "ui-layout-image<-ui-orig-parent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_ui_layout_image_from_ui_orig_parent::vx_empty() const {return vx_ui_html_uihtml::e_ui_layout_image_from_ui_orig_parent;}
    vx_core::Type_any Class_ui_layout_image_from_ui_orig_parent::vx_type() const {return vx_ui_html_uihtml::t_ui_layout_image_from_ui_orig_parent;}
    vx_core::Type_msgblock Class_ui_layout_image_from_ui_orig_parent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ui_layout_image_from_ui_orig_parent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_ui_layout_image_from_ui_orig_parent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_ui orig = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_ui_ui::Type_ui parent = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_ui_html_uihtml::f_ui_layout_image_from_ui_orig_parent(ui, orig, parent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func ui-layout-label<-ui-orig-parent)
  vx_ui_ui::Type_ui f_ui_layout_label_from_ui_orig_parent(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_ui orig, vx_ui_ui::Type_ui parent) {
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
        vx_core::Type_any datatype = vx_core::f_type_from_any(data);
        vx_core::vx_ref_plus(datatype);
        vx_web_html::Type_style style = vx_ui_html_uihtml::f_style_from_style(uistyle);
        vx_core::vx_ref_plus(style);
        vx_web_html::Type_stylelist styles = vx_ui_html_uihtml::f_stylelist_from_stylelist(uistyles);
        vx_core::vx_ref_plus(styles);
        vx_core::Type_string text = vx_core::f_if_2(
          vx_core::t_string,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({datatype}, [datatype]() {
                vx_core::Type_boolean output_1 = vx_core::f_eqeq(
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
        vx_web_html::Type_node nodechg = vx_ui_html_uihtml::f_node_layout_from_node_ui(node, ui);
        vx_core::vx_ref_plus(nodechg);
        vx_ui_ui::Type_uimap uimapchg = vx_ui_ui::f_uimap_layout_from_uimap_parent(uimap, ui);
        vx_core::vx_ref_plus(uimapchg);
        vx_ui_ui::Type_ui output_1 = vx_core::f_new(
          vx_ui_ui::t_ui,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":uimap"),
            uimapchg
          })
        );
        vx_core::vx_release_one_except({uid, data, uimap, uistyle, uistyles, datatype, style, styles, text, node, nodechg, uimapchg}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({ui, orig, parent}, output);
    return output;
  }
  /**
   * @function ui_layout_label_from_ui_orig_parent
   * @param  {ui} ui
   * @param  {ui} orig
   * @param  {ui} parent
   * @return {ui}
   * (func ui-layout-label<-ui-orig-parent)
   */
  // (func ui-layout-label<-ui-orig-parent)
  // class Class_ui_layout_label_from_ui_orig_parent {
    Abstract_ui_layout_label_from_ui_orig_parent::~Abstract_ui_layout_label_from_ui_orig_parent() {}

    Class_ui_layout_label_from_ui_orig_parent::Class_ui_layout_label_from_ui_orig_parent() : Abstract_ui_layout_label_from_ui_orig_parent::Abstract_ui_layout_label_from_ui_orig_parent() {
      vx_core::refcount += 1;
    }

    Class_ui_layout_label_from_ui_orig_parent::~Class_ui_layout_label_from_ui_orig_parent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_ui_layout_label_from_ui_orig_parent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_ui_layout_label_from_ui_orig_parent output = vx_ui_html_uihtml::e_ui_layout_label_from_ui_orig_parent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_ui_layout_label_from_ui_orig_parent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_html_uihtml::Func_ui_layout_label_from_ui_orig_parent output = vx_ui_html_uihtml::e_ui_layout_label_from_ui_orig_parent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_ui_layout_label_from_ui_orig_parent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/html/uihtml", // pkgname
        "ui-layout-label<-ui-orig-parent", // name
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

    vx_core::Type_constdef Class_ui_layout_label_from_ui_orig_parent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_ui_layout_label_from_ui_orig_parent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "ui-layout-label<-ui-orig-parent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_ui_layout_label_from_ui_orig_parent::vx_empty() const {return vx_ui_html_uihtml::e_ui_layout_label_from_ui_orig_parent;}
    vx_core::Type_any Class_ui_layout_label_from_ui_orig_parent::vx_type() const {return vx_ui_html_uihtml::t_ui_layout_label_from_ui_orig_parent;}
    vx_core::Type_msgblock Class_ui_layout_label_from_ui_orig_parent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ui_layout_label_from_ui_orig_parent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_ui_layout_label_from_ui_orig_parent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_ui orig = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_ui_ui::Type_ui parent = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_ui_html_uihtml::f_ui_layout_label_from_ui_orig_parent(ui, orig, parent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_ui_html_uihtml::Const_layout_app_html c_layout_app_html = NULL;
  vx_ui_html_uihtml::Const_layout_else_html c_layout_else_html = NULL;
  vx_ui_html_uihtml::Const_layout_image_html c_layout_image_html = NULL;
  vx_ui_html_uihtml::Const_layout_label_html c_layout_label_html = NULL;
  vx_ui_html_uihtml::Const_layoutenginehtml c_layoutenginehtml = NULL;
  vx_ui_html_uihtml::Const_style_hidden c_style_hidden = NULL;
  vx_ui_html_uihtml::Const_style_selected c_style_selected = NULL;
  vx_ui_html_uihtml::Func_boolean_print_html e_boolean_print_html = NULL;
  vx_ui_html_uihtml::Func_boolean_print_html t_boolean_print_html = NULL;
  vx_ui_html_uihtml::Func_context_write e_context_write = NULL;
  vx_ui_html_uihtml::Func_context_write t_context_write = NULL;
  vx_ui_html_uihtml::Func_divchild_from_ui e_divchild_from_ui = NULL;
  vx_ui_html_uihtml::Func_divchild_from_ui t_divchild_from_ui = NULL;
  vx_ui_html_uihtml::Func_divchildlist_from_uimap e_divchildlist_from_uimap = NULL;
  vx_ui_html_uihtml::Func_divchildlist_from_uimap t_divchildlist_from_uimap = NULL;
  vx_ui_html_uihtml::Func_node_app_from_ui_orig_parent e_node_app_from_ui_orig_parent = NULL;
  vx_ui_html_uihtml::Func_node_app_from_ui_orig_parent t_node_app_from_ui_orig_parent = NULL;
  vx_ui_html_uihtml::Func_node_layout_from_node_ui e_node_layout_from_node_ui = NULL;
  vx_ui_html_uihtml::Func_node_layout_from_node_ui t_node_layout_from_node_ui = NULL;
  vx_ui_html_uihtml::Func_string_style_from_font e_string_style_from_font = NULL;
  vx_ui_html_uihtml::Func_string_style_from_font t_string_style_from_font = NULL;
  vx_ui_html_uihtml::Func_string_style_from_image e_string_style_from_image = NULL;
  vx_ui_html_uihtml::Func_string_style_from_image t_string_style_from_image = NULL;
  vx_ui_html_uihtml::Func_string_stylename_from_name_styletype e_string_stylename_from_name_styletype = NULL;
  vx_ui_html_uihtml::Func_string_stylename_from_name_styletype t_string_stylename_from_name_styletype = NULL;
  vx_ui_html_uihtml::Func_style_from_fontface e_style_from_fontface = NULL;
  vx_ui_html_uihtml::Func_style_from_fontface t_style_from_fontface = NULL;
  vx_ui_html_uihtml::Func_style_from_style e_style_from_style = NULL;
  vx_ui_html_uihtml::Func_style_from_style t_style_from_style = NULL;
  vx_ui_html_uihtml::Func_stylelist_extra_from_ui e_stylelist_extra_from_ui = NULL;
  vx_ui_html_uihtml::Func_stylelist_extra_from_ui t_stylelist_extra_from_ui = NULL;
  vx_ui_html_uihtml::Func_stylelist_reset e_stylelist_reset = NULL;
  vx_ui_html_uihtml::Func_stylelist_reset t_stylelist_reset = NULL;
  vx_ui_html_uihtml::Func_stylelist_from_fontfacemap e_stylelist_from_fontfacemap = NULL;
  vx_ui_html_uihtml::Func_stylelist_from_fontfacemap t_stylelist_from_fontfacemap = NULL;
  vx_ui_html_uihtml::Func_stylelist_from_stylelist e_stylelist_from_stylelist = NULL;
  vx_ui_html_uihtml::Func_stylelist_from_stylelist t_stylelist_from_stylelist = NULL;
  vx_ui_html_uihtml::Func_stylelist_from_stylemap e_stylelist_from_stylemap = NULL;
  vx_ui_html_uihtml::Func_stylelist_from_stylemap t_stylelist_from_stylemap = NULL;
  vx_ui_html_uihtml::Func_stylemap_from_stylemap e_stylemap_from_stylemap = NULL;
  vx_ui_html_uihtml::Func_stylemap_from_stylemap t_stylemap_from_stylemap = NULL;
  vx_ui_html_uihtml::Func_stylesheet_layout_html e_stylesheet_layout_html = NULL;
  vx_ui_html_uihtml::Func_stylesheet_layout_html t_stylesheet_layout_html = NULL;
  vx_ui_html_uihtml::Func_stylesheet_from_stylesheet e_stylesheet_from_stylesheet = NULL;
  vx_ui_html_uihtml::Func_stylesheet_from_stylesheet t_stylesheet_from_stylesheet = NULL;
  vx_ui_html_uihtml::Func_ui_layout_app_from_ui_orig_parent e_ui_layout_app_from_ui_orig_parent = NULL;
  vx_ui_html_uihtml::Func_ui_layout_app_from_ui_orig_parent t_ui_layout_app_from_ui_orig_parent = NULL;
  vx_ui_html_uihtml::Func_ui_layout_default_from_ui_orig_parent e_ui_layout_default_from_ui_orig_parent = NULL;
  vx_ui_html_uihtml::Func_ui_layout_default_from_ui_orig_parent t_ui_layout_default_from_ui_orig_parent = NULL;
  vx_ui_html_uihtml::Func_ui_layout_image_from_ui_orig_parent e_ui_layout_image_from_ui_orig_parent = NULL;
  vx_ui_html_uihtml::Func_ui_layout_image_from_ui_orig_parent t_ui_layout_image_from_ui_orig_parent = NULL;
  vx_ui_html_uihtml::Func_ui_layout_label_from_ui_orig_parent e_ui_layout_label_from_ui_orig_parent = NULL;
  vx_ui_html_uihtml::Func_ui_layout_label_from_ui_orig_parent t_ui_layout_label_from_ui_orig_parent = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_ui_html_uihtml::c_layout_app_html = new vx_ui_html_uihtml::Class_layout_app_html();
      vx_ui_html_uihtml::c_layout_else_html = new vx_ui_html_uihtml::Class_layout_else_html();
      vx_ui_html_uihtml::c_layout_image_html = new vx_ui_html_uihtml::Class_layout_image_html();
      vx_ui_html_uihtml::c_layout_label_html = new vx_ui_html_uihtml::Class_layout_label_html();
      vx_ui_html_uihtml::c_layoutenginehtml = new vx_ui_html_uihtml::Class_layoutenginehtml();
      vx_ui_html_uihtml::c_style_hidden = new vx_ui_html_uihtml::Class_style_hidden();
      vx_ui_html_uihtml::c_style_selected = new vx_ui_html_uihtml::Class_style_selected();
      vx_ui_html_uihtml::e_boolean_print_html = new vx_ui_html_uihtml::Class_boolean_print_html();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_boolean_print_html);
      vx_ui_html_uihtml::t_boolean_print_html = new vx_ui_html_uihtml::Class_boolean_print_html();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_boolean_print_html);
      vx_ui_html_uihtml::e_context_write = new vx_ui_html_uihtml::Class_context_write();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_context_write);
      vx_ui_html_uihtml::t_context_write = new vx_ui_html_uihtml::Class_context_write();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_context_write);
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
      vx_ui_html_uihtml::e_node_layout_from_node_ui = new vx_ui_html_uihtml::Class_node_layout_from_node_ui();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_node_layout_from_node_ui);
      vx_ui_html_uihtml::t_node_layout_from_node_ui = new vx_ui_html_uihtml::Class_node_layout_from_node_ui();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_node_layout_from_node_ui);
      vx_ui_html_uihtml::e_string_style_from_font = new vx_ui_html_uihtml::Class_string_style_from_font();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_string_style_from_font);
      vx_ui_html_uihtml::t_string_style_from_font = new vx_ui_html_uihtml::Class_string_style_from_font();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_string_style_from_font);
      vx_ui_html_uihtml::e_string_style_from_image = new vx_ui_html_uihtml::Class_string_style_from_image();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_string_style_from_image);
      vx_ui_html_uihtml::t_string_style_from_image = new vx_ui_html_uihtml::Class_string_style_from_image();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_string_style_from_image);
      vx_ui_html_uihtml::e_string_stylename_from_name_styletype = new vx_ui_html_uihtml::Class_string_stylename_from_name_styletype();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_string_stylename_from_name_styletype);
      vx_ui_html_uihtml::t_string_stylename_from_name_styletype = new vx_ui_html_uihtml::Class_string_stylename_from_name_styletype();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_string_stylename_from_name_styletype);
      vx_ui_html_uihtml::e_style_from_fontface = new vx_ui_html_uihtml::Class_style_from_fontface();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_style_from_fontface);
      vx_ui_html_uihtml::t_style_from_fontface = new vx_ui_html_uihtml::Class_style_from_fontface();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_style_from_fontface);
      vx_ui_html_uihtml::e_style_from_style = new vx_ui_html_uihtml::Class_style_from_style();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_style_from_style);
      vx_ui_html_uihtml::t_style_from_style = new vx_ui_html_uihtml::Class_style_from_style();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_style_from_style);
      vx_ui_html_uihtml::e_stylelist_extra_from_ui = new vx_ui_html_uihtml::Class_stylelist_extra_from_ui();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_stylelist_extra_from_ui);
      vx_ui_html_uihtml::t_stylelist_extra_from_ui = new vx_ui_html_uihtml::Class_stylelist_extra_from_ui();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_stylelist_extra_from_ui);
      vx_ui_html_uihtml::e_stylelist_reset = new vx_ui_html_uihtml::Class_stylelist_reset();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_stylelist_reset);
      vx_ui_html_uihtml::t_stylelist_reset = new vx_ui_html_uihtml::Class_stylelist_reset();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_stylelist_reset);
      vx_ui_html_uihtml::e_stylelist_from_fontfacemap = new vx_ui_html_uihtml::Class_stylelist_from_fontfacemap();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_stylelist_from_fontfacemap);
      vx_ui_html_uihtml::t_stylelist_from_fontfacemap = new vx_ui_html_uihtml::Class_stylelist_from_fontfacemap();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_stylelist_from_fontfacemap);
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
      vx_ui_html_uihtml::e_stylesheet_layout_html = new vx_ui_html_uihtml::Class_stylesheet_layout_html();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_stylesheet_layout_html);
      vx_ui_html_uihtml::t_stylesheet_layout_html = new vx_ui_html_uihtml::Class_stylesheet_layout_html();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_stylesheet_layout_html);
      vx_ui_html_uihtml::e_stylesheet_from_stylesheet = new vx_ui_html_uihtml::Class_stylesheet_from_stylesheet();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_stylesheet_from_stylesheet);
      vx_ui_html_uihtml::t_stylesheet_from_stylesheet = new vx_ui_html_uihtml::Class_stylesheet_from_stylesheet();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_stylesheet_from_stylesheet);
      vx_ui_html_uihtml::e_ui_layout_app_from_ui_orig_parent = new vx_ui_html_uihtml::Class_ui_layout_app_from_ui_orig_parent();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_ui_layout_app_from_ui_orig_parent);
      vx_ui_html_uihtml::t_ui_layout_app_from_ui_orig_parent = new vx_ui_html_uihtml::Class_ui_layout_app_from_ui_orig_parent();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_ui_layout_app_from_ui_orig_parent);
      vx_ui_html_uihtml::e_ui_layout_default_from_ui_orig_parent = new vx_ui_html_uihtml::Class_ui_layout_default_from_ui_orig_parent();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_ui_layout_default_from_ui_orig_parent);
      vx_ui_html_uihtml::t_ui_layout_default_from_ui_orig_parent = new vx_ui_html_uihtml::Class_ui_layout_default_from_ui_orig_parent();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_ui_layout_default_from_ui_orig_parent);
      vx_ui_html_uihtml::e_ui_layout_image_from_ui_orig_parent = new vx_ui_html_uihtml::Class_ui_layout_image_from_ui_orig_parent();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_ui_layout_image_from_ui_orig_parent);
      vx_ui_html_uihtml::t_ui_layout_image_from_ui_orig_parent = new vx_ui_html_uihtml::Class_ui_layout_image_from_ui_orig_parent();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_ui_layout_image_from_ui_orig_parent);
      vx_ui_html_uihtml::e_ui_layout_label_from_ui_orig_parent = new vx_ui_html_uihtml::Class_ui_layout_label_from_ui_orig_parent();
      vx_core::vx_reserve_empty(vx_ui_html_uihtml::e_ui_layout_label_from_ui_orig_parent);
      vx_ui_html_uihtml::t_ui_layout_label_from_ui_orig_parent = new vx_ui_html_uihtml::Class_ui_layout_label_from_ui_orig_parent();
      vx_core::vx_reserve_type(vx_ui_html_uihtml::t_ui_layout_label_from_ui_orig_parent);
      vx_ui_html_uihtml::Class_layout_app_html::vx_const_new(vx_ui_html_uihtml::c_layout_app_html);
      vx_ui_html_uihtml::Class_layout_else_html::vx_const_new(vx_ui_html_uihtml::c_layout_else_html);
      vx_ui_html_uihtml::Class_layout_image_html::vx_const_new(vx_ui_html_uihtml::c_layout_image_html);
      vx_ui_html_uihtml::Class_layout_label_html::vx_const_new(vx_ui_html_uihtml::c_layout_label_html);
      vx_ui_html_uihtml::Class_layoutenginehtml::vx_const_new(vx_ui_html_uihtml::c_layoutenginehtml);
      vx_ui_html_uihtml::Class_style_hidden::vx_const_new(vx_ui_html_uihtml::c_style_hidden);
      vx_ui_html_uihtml::Class_style_selected::vx_const_new(vx_ui_html_uihtml::c_style_selected);
      vx_core::vx_Type_mapany maptype;
      vx_core::vx_Type_mapany mapconst;
      vx_core::vx_Type_mapfunc mapfunc;
      vx_core::vx_Type_mapany mapempty;
      mapconst["layout-app-html"] = vx_ui_html_uihtml::c_layout_app_html;
      mapconst["layout-else-html"] = vx_ui_html_uihtml::c_layout_else_html;
      mapconst["layout-image-html"] = vx_ui_html_uihtml::c_layout_image_html;
      mapconst["layout-label-html"] = vx_ui_html_uihtml::c_layout_label_html;
      mapconst["layoutenginehtml"] = vx_ui_html_uihtml::c_layoutenginehtml;
      mapconst["style-hidden"] = vx_ui_html_uihtml::c_style_hidden;
      mapconst["style-selected"] = vx_ui_html_uihtml::c_style_selected;
      mapfunc["boolean-print-html"] = vx_ui_html_uihtml::t_boolean_print_html;
      mapfunc["context-write"] = vx_ui_html_uihtml::t_context_write;
      mapfunc["divchild<-ui"] = vx_ui_html_uihtml::t_divchild_from_ui;
      mapfunc["divchildlist<-uimap"] = vx_ui_html_uihtml::t_divchildlist_from_uimap;
      mapfunc["node-app<-ui-orig-parent"] = vx_ui_html_uihtml::t_node_app_from_ui_orig_parent;
      mapfunc["node-layout<-node-ui"] = vx_ui_html_uihtml::t_node_layout_from_node_ui;
      mapfunc["string-style<-font"] = vx_ui_html_uihtml::t_string_style_from_font;
      mapfunc["string-style<-image"] = vx_ui_html_uihtml::t_string_style_from_image;
      mapfunc["string-stylename<-name-styletype"] = vx_ui_html_uihtml::t_string_stylename_from_name_styletype;
      mapfunc["style<-fontface"] = vx_ui_html_uihtml::t_style_from_fontface;
      mapfunc["style<-style"] = vx_ui_html_uihtml::t_style_from_style;
      mapfunc["stylelist-extra<-ui"] = vx_ui_html_uihtml::t_stylelist_extra_from_ui;
      mapfunc["stylelist-reset"] = vx_ui_html_uihtml::t_stylelist_reset;
      mapfunc["stylelist<-fontfacemap"] = vx_ui_html_uihtml::t_stylelist_from_fontfacemap;
      mapfunc["stylelist<-stylelist"] = vx_ui_html_uihtml::t_stylelist_from_stylelist;
      mapfunc["stylelist<-stylemap"] = vx_ui_html_uihtml::t_stylelist_from_stylemap;
      mapfunc["stylemap<-stylemap"] = vx_ui_html_uihtml::t_stylemap_from_stylemap;
      mapfunc["stylesheet-layout-html"] = vx_ui_html_uihtml::t_stylesheet_layout_html;
      mapfunc["stylesheet<-stylesheet"] = vx_ui_html_uihtml::t_stylesheet_from_stylesheet;
      mapfunc["ui-layout-app<-ui-orig-parent"] = vx_ui_html_uihtml::t_ui_layout_app_from_ui_orig_parent;
      mapfunc["ui-layout-default<-ui-orig-parent"] = vx_ui_html_uihtml::t_ui_layout_default_from_ui_orig_parent;
      mapfunc["ui-layout-image<-ui-orig-parent"] = vx_ui_html_uihtml::t_ui_layout_image_from_ui_orig_parent;
      mapfunc["ui-layout-label<-ui-orig-parent"] = vx_ui_html_uihtml::t_ui_layout_label_from_ui_orig_parent;
      vx_core::vx_global_package_set("vx/ui/html/uihtml", maptype, mapconst, mapfunc);
	   }
  // }

}
