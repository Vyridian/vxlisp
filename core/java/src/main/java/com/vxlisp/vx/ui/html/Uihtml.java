package com.vxlisp.vx.ui.html;

import java.util.concurrent.CompletableFuture;
import java.util.LinkedHashMap;
import java.util.Map;
import com.vxlisp.vx.*;
import com.vxlisp.vx.web.*;
import com.vxlisp.vx.ui.*;

public final class Uihtml {


  /**
   * Constant: layout-app-html
   * Html App Renderer
   * {layout}
   */
  public static class Const_layout_app_html extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/ui/html/uihtml", // pkgname
        "layout-app-html", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_layout_app_html output) {
      Ui.Type_layout val = Core.f_copy(
        Ui.c_layout_app,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":fn-layout"),
                Uihtml.t_ui_render_app_from_ui_orig_parent
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_app_html c_layout_app_html = new Const_layout_app_html();


  /**
   * Constant: layout-else-html
   * Html Default Renderer
   * {layout}
   */
  public static class Const_layout_else_html extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/ui/html/uihtml", // pkgname
        "layout-else-html", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_layout_else_html output) {
      Ui.Type_layout val = Core.f_copy(
        Ui.c_layout_else,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":fn-layout"),
                Uihtml.t_ui_render_default_from_ui_orig_parent
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_else_html c_layout_else_html = new Const_layout_else_html();


  /**
   * Constant: layout-label-html
   * Html Label Renderer
   * {layout}
   */
  public static class Const_layout_label_html extends Ui.Class_layout implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/ui/html/uihtml", // pkgname
        "layout-label-html", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_layout_label_html output) {
      Ui.Type_layout val = Core.f_copy(
        Ui.c_layout_label,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":fn-layout"),
                Uihtml.t_ui_render_label_from_ui_orig_parent
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_fn_layout = val.fn_layout();
    }


  }

  public static final Const_layout_label_html c_layout_label_html = new Const_layout_label_html();


  /**
   * Constant: layoutenginehtml
   * {layoutengine}
   */
  public static class Const_layoutenginehtml extends Ui.Class_layoutengine implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/ui/html/uihtml", // pkgname
        "layoutenginehtml", // name
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layoutengine", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_layoutenginehtml output) {
      Ui.Type_layoutengine val = Core.f_new(
        Ui.t_layoutengine,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":layoutmap"),
                Ui.f_layoutmap_from_layoutlist(
                  Core.f_new(
                    Ui.t_layoutlist,
                    Core.t_anylist.vx_new(
                      Uihtml.c_layout_app_html,
                      Uihtml.c_layout_label_html
                    )
                  )
                ),
                Core.vx_new_string(":layoutelse"),
                Uihtml.c_layout_else_html,
                Core.vx_new_string(":stylesheetrender"),
                Uihtml.t_stylesheet_render_html
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_layoutmap = val.layoutmap();
      output.vx_p_layoutelse = val.layoutelse();
      output.vx_p_stylesheetrender = val.stylesheetrender();
    }


  }

  public static final Const_layoutenginehtml c_layoutenginehtml = new Const_layoutenginehtml();

  /**
   * @function divchild_from_ui
   * Returns a divchildlist of empty divs from a uimap
   * @param  {ui} ui
   * @return {divchild}
   * (func divchild<-ui)
   */
  public static interface Func_divchild_from_ui extends Core.Func_any_from_any {
    public Html.Type_divchild vx_divchild_from_ui(final Ui.Type_ui ui);
  }

  public static class Class_divchild_from_ui extends Core.Class_base implements Func_divchild_from_ui {

    @Override
    public Func_divchild_from_ui vx_new(Object... vals) {
      Class_divchild_from_ui output = new Class_divchild_from_ui();
      return output;
    }

    @Override
    public Func_divchild_from_ui vx_copy(Object... vals) {
      Class_divchild_from_ui output = new Class_divchild_from_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "divchild<-ui", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/web/html", // pkgname
          "divchild", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_divchild_from_ui vx_empty() {return e_divchild_from_ui;}
    @Override
    public Func_divchild_from_ui vx_type() {return t_divchild_from_ui;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_ui inputval = (Ui.Type_ui)value;
      Core.Type_any outputval = Uihtml.f_divchild_from_ui(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      output = Uihtml.f_divchild_from_ui(ui);
      return output;
    }

    @Override
    public Html.Type_divchild vx_divchild_from_ui(final Ui.Type_ui ui) {
      return Uihtml.f_divchild_from_ui(ui);
    }

  }

  public static final Func_divchild_from_ui e_divchild_from_ui = new Uihtml.Class_divchild_from_ui();
  public static final Func_divchild_from_ui t_divchild_from_ui = new Uihtml.Class_divchild_from_ui();

  public static Html.Type_divchild f_divchild_from_ui(final Ui.Type_ui ui) {
    Html.Type_divchild output = Html.e_divchild;
    output = Core.f_let(
      Html.t_div,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string uid = ui.uid();
        final Ui.Type_uimap uimapchild = ui.uimap();
        final Ui.Type_style uistyle = ui.style();
        final Ui.Type_stylelist uistyles = ui.stylelist();
        final Html.Type_style styleunique = Uihtml.f_style_from_style(uistyle);
        final Html.Type_stylelist htmlstyles = Uihtml.f_stylelist_from_stylelist(uistyles);
        return Core.f_new(
          Html.t_div,
          Core.t_anylist.vx_new(
            Core.vx_new_string(":id"),
            uid,
            Core.vx_new_string(":style-unique"),
            styleunique,
            Core.vx_new_string(":stylelist"),
            htmlstyles
          )
        );
      })
    );
    return output;
  }

  /**
   * @function divchildlist_from_uimap
   * Returns a divchildlist of empty divs from a uimap
   * @param  {uimap} uimap
   * @return {divchildlist}
   * (func divchildlist<-uimap)
   */
  public static interface Func_divchildlist_from_uimap extends Core.Func_any_from_any {
    public Html.Type_divchildlist vx_divchildlist_from_uimap(final Ui.Type_uimap uimap);
  }

  public static class Class_divchildlist_from_uimap extends Core.Class_base implements Func_divchildlist_from_uimap {

    @Override
    public Func_divchildlist_from_uimap vx_new(Object... vals) {
      Class_divchildlist_from_uimap output = new Class_divchildlist_from_uimap();
      return output;
    }

    @Override
    public Func_divchildlist_from_uimap vx_copy(Object... vals) {
      Class_divchildlist_from_uimap output = new Class_divchildlist_from_uimap();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "divchildlist<-uimap", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/web/html", // pkgname
          "divchildlist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Html.t_divchild), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_divchildlist_from_uimap vx_empty() {return e_divchildlist_from_uimap;}
    @Override
    public Func_divchildlist_from_uimap vx_type() {return t_divchildlist_from_uimap;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_uimap inputval = (Ui.Type_uimap)value;
      Core.Type_any outputval = Uihtml.f_divchildlist_from_uimap(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_uimap uimap = Core.f_any_from_any(Ui.t_uimap, arglist.vx_any(Core.vx_new_int(0)));
      output = Uihtml.f_divchildlist_from_uimap(uimap);
      return output;
    }

    @Override
    public Html.Type_divchildlist vx_divchildlist_from_uimap(final Ui.Type_uimap uimap) {
      return Uihtml.f_divchildlist_from_uimap(uimap);
    }

  }

  public static final Func_divchildlist_from_uimap e_divchildlist_from_uimap = new Uihtml.Class_divchildlist_from_uimap();
  public static final Func_divchildlist_from_uimap t_divchildlist_from_uimap = new Uihtml.Class_divchildlist_from_uimap();

  public static Html.Type_divchildlist f_divchildlist_from_uimap(final Ui.Type_uimap uimap) {
    Html.Type_divchildlist output = Html.e_divchildlist;
    output = Core.f_list_from_map(
      Html.t_divchildlist,
      uimap,
      Core.t_any_from_key_value.vx_fn_new((key_any, value_any) -> {
        Core.Type_string key = Core.f_any_from_any(Core.t_string, key_any);
        Ui.Type_ui value = Core.f_any_from_any(Ui.t_ui, value_any);
        return 
          Core.f_new(
            Html.t_div,
            Core.t_anylist.vx_new(
              Core.vx_new_string(":id"),
              key
            )
          );
      })
    );
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
  public static interface Func_node_app_from_ui_orig_parent extends Core.Type_func, Core.Type_replfunc {
    public Html.Type_node vx_node_app_from_ui_orig_parent(final Ui.Type_ui ui, final Ui.Type_ui orig, final Ui.Type_ui parent);
  }

  public static class Class_node_app_from_ui_orig_parent extends Core.Class_base implements Func_node_app_from_ui_orig_parent {

    @Override
    public Func_node_app_from_ui_orig_parent vx_new(Object... vals) {
      Class_node_app_from_ui_orig_parent output = new Class_node_app_from_ui_orig_parent();
      return output;
    }

    @Override
    public Func_node_app_from_ui_orig_parent vx_copy(Object... vals) {
      Class_node_app_from_ui_orig_parent output = new Class_node_app_from_ui_orig_parent();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "node-app<-ui-orig-parent", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/web/html", // pkgname
          "node", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_node_app_from_ui_orig_parent vx_empty() {return e_node_app_from_ui_orig_parent;}
    @Override
    public Func_node_app_from_ui_orig_parent vx_type() {return t_node_app_from_ui_orig_parent;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui orig = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(1)));
      Ui.Type_ui parent = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(2)));
      output = Uihtml.f_node_app_from_ui_orig_parent(ui, orig, parent);
      return output;
    }

    @Override
    public Html.Type_node vx_node_app_from_ui_orig_parent(final Ui.Type_ui ui, final Ui.Type_ui orig, final Ui.Type_ui parent) {
      return Uihtml.f_node_app_from_ui_orig_parent(ui, orig, parent);
    }

  }

  public static final Func_node_app_from_ui_orig_parent e_node_app_from_ui_orig_parent = new Uihtml.Class_node_app_from_ui_orig_parent();
  public static final Func_node_app_from_ui_orig_parent t_node_app_from_ui_orig_parent = new Uihtml.Class_node_app_from_ui_orig_parent();

  public static Html.Type_node f_node_app_from_ui_orig_parent(final Ui.Type_ui ui, final Ui.Type_ui orig, final Ui.Type_ui parent) {
    Html.Type_node output = Html.e_node;
    output = Core.f_empty(
      Html.t_div
    );
    return output;
  }

  /**
   * @function node_render_from_node_ui
   * @param  {node} node
   * @param  {ui} ui
   * @return {node}
   * (func node-render<-node-ui)
   */
  public static interface Func_node_render_from_node_ui extends Core.Type_func, Core.Type_replfunc {
    public Html.Type_node vx_node_render_from_node_ui(final Html.Type_node node, final Ui.Type_ui ui);
  }

  public static class Class_node_render_from_node_ui extends Core.Class_base implements Func_node_render_from_node_ui {

    @Override
    public Func_node_render_from_node_ui vx_new(Object... vals) {
      Class_node_render_from_node_ui output = new Class_node_render_from_node_ui();
      return output;
    }

    @Override
    public Func_node_render_from_node_ui vx_copy(Object... vals) {
      Class_node_render_from_node_ui output = new Class_node_render_from_node_ui();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "node-render<-node-ui", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/web/html", // pkgname
          "node", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_node_render_from_node_ui vx_empty() {return e_node_render_from_node_ui;}
    @Override
    public Func_node_render_from_node_ui vx_type() {return t_node_render_from_node_ui;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_node node = Core.f_any_from_any(Html.t_node, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(1)));
      output = Uihtml.f_node_render_from_node_ui(node, ui);
      return output;
    }

    @Override
    public Html.Type_node vx_node_render_from_node_ui(final Html.Type_node node, final Ui.Type_ui ui) {
      return Uihtml.f_node_render_from_node_ui(node, ui);
    }

  }

  public static final Func_node_render_from_node_ui e_node_render_from_node_ui = new Uihtml.Class_node_render_from_node_ui();
  public static final Func_node_render_from_node_ui t_node_render_from_node_ui = new Uihtml.Class_node_render_from_node_ui();

  public static Html.Type_node f_node_render_from_node_ui(final Html.Type_node node, final Ui.Type_ui ui) {
    Html.Type_node output = Html.e_node;
    output = Core.f_let(
      Html.t_node,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string uid = ui.uid();
        final Event.Type_eventmap eventmap = ui.eventmap();
        final Core.Type_string htmltext = Html.f_string_from_node_indent(node, Core.vx_new_int(2));
        final Core.Type_boolean htmldone = Htmldoc.f_boolean_replace_from_id_htmltext_data_eventmap(uid, htmltext, ui, eventmap);
        return node;
      })
    );
    return output;
  }

  /**
   * @function string_stylename_from_name_styletype
   * @param  {string} name
   * @param  {styletype} styletype
   * @return {string}
   * (func string-stylename<-name-styletype)
   */
  public static interface Func_string_stylename_from_name_styletype extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_string_stylename_from_name_styletype(final Core.Type_string name, final Ui.Type_styletype styletype);
  }

  public static class Class_string_stylename_from_name_styletype extends Core.Class_base implements Func_string_stylename_from_name_styletype {

    @Override
    public Func_string_stylename_from_name_styletype vx_new(Object... vals) {
      Class_string_stylename_from_name_styletype output = new Class_string_stylename_from_name_styletype();
      return output;
    }

    @Override
    public Func_string_stylename_from_name_styletype vx_copy(Object... vals) {
      Class_string_stylename_from_name_styletype output = new Class_string_stylename_from_name_styletype();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "string-stylename<-name-styletype", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_string_stylename_from_name_styletype vx_empty() {return e_string_stylename_from_name_styletype;}
    @Override
    public Func_string_stylename_from_name_styletype vx_type() {return t_string_stylename_from_name_styletype;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string name = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_styletype styletype = Core.f_any_from_any(Ui.t_styletype, arglist.vx_any(Core.vx_new_int(1)));
      output = Uihtml.f_string_stylename_from_name_styletype(name, styletype);
      return output;
    }

    @Override
    public Core.Type_string vx_string_stylename_from_name_styletype(final Core.Type_string name, final Ui.Type_styletype styletype) {
      return Uihtml.f_string_stylename_from_name_styletype(name, styletype);
    }

  }

  public static final Func_string_stylename_from_name_styletype e_string_stylename_from_name_styletype = new Uihtml.Class_string_stylename_from_name_styletype();
  public static final Func_string_stylename_from_name_styletype t_string_stylename_from_name_styletype = new Uihtml.Class_string_stylename_from_name_styletype();

  public static Core.Type_string f_string_stylename_from_name_styletype(final Core.Type_string name, final Ui.Type_styletype styletype) {
    Core.Type_string output = Core.e_string;
    output = Core.f_if_2(
      Core.t_string,
      Core.t_thenelselist.vx_new(
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            return Core.f_eq(Core.vx_new_string(""), name);
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.vx_new_string("");
          })
        ),
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            return Core.f_eqeq(
              styletype,
              Ui.c_styletype_shared
            );
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.f_new(
              Core.t_string,
              Core.t_anylist.vx_new(
                  Core.vx_new_string("."),
                  name
              )
            );
          })
        ),
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            return Core.f_eqeq(
              styletype,
              Ui.c_styletype_system
            );
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            return name;
          })
        ),
        Core.f_else(
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.f_new(
              Core.t_string,
              Core.t_anylist.vx_new(
                  Core.vx_new_string("#"),
                  name
              )
            );
          })
        )
      )
    );
    return output;
  }

  /**
   * @function style_from_style
   * Returns a htmlstyle from a uistyle
   * @param  {style} uistyle
   * @return {style}
   * (func style<-style)
   */
  public static interface Func_style_from_style extends Core.Func_any_from_any {
    public Html.Type_style vx_style_from_style(final Ui.Type_style uistyle);
  }

  public static class Class_style_from_style extends Core.Class_base implements Func_style_from_style {

    @Override
    public Func_style_from_style vx_new(Object... vals) {
      Class_style_from_style output = new Class_style_from_style();
      return output;
    }

    @Override
    public Func_style_from_style vx_copy(Object... vals) {
      Class_style_from_style output = new Class_style_from_style();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "style<-style", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/web/html", // pkgname
          "style", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_style_from_style vx_empty() {return e_style_from_style;}
    @Override
    public Func_style_from_style vx_type() {return t_style_from_style;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_style inputval = (Ui.Type_style)value;
      Core.Type_any outputval = Uihtml.f_style_from_style(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_style uistyle = Core.f_any_from_any(Ui.t_style, arglist.vx_any(Core.vx_new_int(0)));
      output = Uihtml.f_style_from_style(uistyle);
      return output;
    }

    @Override
    public Html.Type_style vx_style_from_style(final Ui.Type_style uistyle) {
      return Uihtml.f_style_from_style(uistyle);
    }

  }

  public static final Func_style_from_style e_style_from_style = new Uihtml.Class_style_from_style();
  public static final Func_style_from_style t_style_from_style = new Uihtml.Class_style_from_style();

  public static Html.Type_style f_style_from_style(final Ui.Type_style uistyle) {
    Html.Type_style output = Html.e_style;
    output = Core.f_if_2(
      Html.t_style,
      Core.t_thenelselist.vx_new(
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            return Core.f_is_empty_1(uistyle);
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.f_empty(
              Html.t_style
            );
          })
        ),
        Core.f_else(
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.f_let(
              Html.t_style,
              Core.t_any_from_func.vx_fn_new(() -> {
                final Ui.Type_layout layout = uistyle.layout();
                final Core.Type_string name = uistyle.name();
                final Ui.Type_pin pin = uistyle.pin();
                final Ui.Type_point pointpos = uistyle.pointpos();
                final Ui.Type_point pointsize = uistyle.pointsize();
                final Ui.Type_styletype styletype = uistyle.type();
                final Core.Type_string color_background = uistyle.color_background();
                final Core.Type_string color_hoverbkgrd = uistyle.color_hoverbkgrd();
                final Core.Type_int posx = pointpos.x();
                final Core.Type_int posy = pointpos.y();
                final Core.Type_int sizex = pointsize.x();
                final Core.Type_int sizey = pointsize.y();
                final Core.Type_string stylename = Uihtml.f_string_stylename_from_name_styletype(name, styletype);
                final Core.Type_string backgroundcolor = Core.f_if_2(
                  Core.t_string,
                  Core.t_thenelselist.vx_new(
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_notempty(color_background);
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.f_new(
                            Core.t_string,
                            Core.t_anylist.vx_new(
                                Core.vx_new_string("#"),
                                color_background
                            )
                          );
                        })
                      )
                  )
                );
                final Core.Type_string position = Core.f_if_2(
                  Core.t_string,
                  Core.t_thenelselist.vx_new(
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_or_1(
                            Core.t_booleanlist.vx_new(
                                Core.f_eqeq(
                                  layout,
                                  Ui.c_layout_app
                                ),
                                Core.f_eqeq(
                                  layout,
                                  Ui.c_layout_background
                                ),
                                Core.f_eqeq(
                                  layout,
                                  Ui.c_layout_main
                                ),
                                Core.f_eqeq(
                                  layout,
                                  Ui.c_layout_navbar
                                ),
                                Core.f_eqeq(
                                  layout,
                                  Ui.c_layout_parallax
                                ),
                                Core.f_eqeq(
                                  layout,
                                  Ui.c_layout_statusbar
                                )
                            )
                          );
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.vx_new_string("fixed");
                        })
                      ),
                      Core.f_else(
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.vx_new_string("relative");
                        })
                      )
                  )
                );
                final Core.Type_string top = Core.f_if_2(
                  Core.t_string,
                  Core.t_thenelselist.vx_new(
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_eqeq(
                            pin,
                            Ui.c_pin_expand
                          );
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.f_new(
                            Core.t_string,
                            Core.t_anylist.vx_new(
                                posy,
                                Core.vx_new_string("mm")
                            )
                          );
                        })
                      ),
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_eqeq(Core.vx_new_int(0), posy);
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.vx_new_string("");
                        })
                      ),
                      Core.f_else(
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.f_new(
                            Core.t_string,
                            Core.t_anylist.vx_new(
                                posy,
                                Core.vx_new_string("mm")
                            )
                          );
                        })
                      )
                  )
                );
                final Core.Type_string bottom = Core.f_if_2(
                  Core.t_string,
                  Core.t_thenelselist.vx_new(
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_eqeq(
                            pin,
                            Ui.c_pin_expand
                          );
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.vx_new_string("");
                        })
                      ),
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_eqeq(
                            pin,
                            Ui.c_pin_bottom
                          );
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.vx_new_string("0mm");
                        })
                      ),
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_or(
                            Core.f_eqeq(
                              pin,
                              Ui.c_pin_left
                            ),
                            Core.f_eqeq(
                              pin,
                              Ui.c_pin_center_v
                            )
                          );
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.f_new(
                            Core.t_string,
                            Core.t_anylist.vx_new(
                                sizey,
                                Core.vx_new_string("mm")
                            )
                          );
                        })
                      )
                  )
                );
                final Core.Type_string left = Core.f_if_2(
                  Core.t_string,
                  Core.t_thenelselist.vx_new(
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_eqeq(
                            pin,
                            Ui.c_pin_expand
                          );
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.vx_new_string("");
                        })
                      ),
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_eqeq(
                            pin,
                            Ui.c_pin_bottom
                          );
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.f_new(
                            Core.t_string,
                            Core.t_anylist.vx_new(
                                posx,
                                Core.vx_new_string("mm")
                            )
                          );
                        })
                      ),
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_eqeq(Core.vx_new_int(0), posx);
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.vx_new_string("");
                        })
                      ),
                      Core.f_else(
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.f_new(
                            Core.t_string,
                            Core.t_anylist.vx_new(
                                posx,
                                Core.vx_new_string("mm")
                            )
                          );
                        })
                      )
                  )
                );
                final Core.Type_string right = Core.f_if_2(
                  Core.t_string,
                  Core.t_thenelselist.vx_new(
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_eqeq(
                            pin,
                            Ui.c_pin_expand
                          );
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.vx_new_string("");
                        })
                      ),
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_or_1(
                            Core.t_booleanlist.vx_new(
                                Core.f_eqeq(
                                  pin,
                                  Ui.c_pin_top
                                ),
                                Core.f_eqeq(
                                  pin,
                                  Ui.c_pin_bottom
                                ),
                                Core.f_eqeq(
                                  pin,
                                  Ui.c_pin_center_v
                                )
                            )
                          );
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.f_new(
                            Core.t_string,
                            Core.t_anylist.vx_new(
                                sizex,
                                Core.vx_new_string("mm")
                            )
                          );
                        })
                      )
                  )
                );
                final Core.Type_string height = Core.f_if_2(
                  Core.t_string,
                  Core.t_thenelselist.vx_new(
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_eqeq(
                            pin,
                            Ui.c_pin_expand
                          );
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.vx_new_string("100%");
                        })
                      ),
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_or_1(
                            Core.t_booleanlist.vx_new(
                                Core.f_eqeq(
                                  pin,
                                  Ui.c_pin_left
                                ),
                                Core.f_eqeq(
                                  pin,
                                  Ui.c_pin_right
                                ),
                                Core.f_eqeq(
                                  pin,
                                  Ui.c_pin_center_v
                                )
                            )
                          );
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.vx_new_string("");
                        })
                      ),
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_eqeq(Core.vx_new_int(0), sizey);
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.vx_new_string("");
                        })
                      ),
                      Core.f_else(
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.f_new(
                            Core.t_string,
                            Core.t_anylist.vx_new(
                                sizey,
                                Core.vx_new_string("mm")
                            )
                          );
                        })
                      )
                  )
                );
                final Core.Type_string width = Core.f_if_2(
                  Core.t_string,
                  Core.t_thenelselist.vx_new(
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_eqeq(
                            pin,
                            Ui.c_pin_expand
                          );
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.vx_new_string("100%");
                        })
                      ),
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_or_1(
                            Core.t_booleanlist.vx_new(
                                Core.f_eqeq(
                                  pin,
                                  Ui.c_pin_top
                                ),
                                Core.f_eqeq(
                                  pin,
                                  Ui.c_pin_bottom
                                ),
                                Core.f_eqeq(
                                  pin,
                                  Ui.c_pin_center_v
                                )
                            )
                          );
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.vx_new_string("");
                        })
                      ),
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_eqeq(Core.vx_new_int(0), sizex);
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.vx_new_string("");
                        })
                      ),
                      Core.f_else(
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.f_new(
                            Core.t_string,
                            Core.t_anylist.vx_new(
                                sizex,
                                Core.vx_new_string("mm")
                            )
                          );
                        })
                      )
                  )
                );
                final Core.Type_string display = Core.f_if_2(
                  Core.t_string,
                  Core.t_thenelselist.vx_new(
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_or(
                            Core.f_eqeq(
                              layout,
                              Ui.c_layout_flow_columns
                            ),
                            Core.f_eqeq(
                              layout,
                              Ui.c_layout_flow_rows
                            )
                          );
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.vx_new_string("flex");
                        })
                      )
                  )
                );
                final Core.Type_string flexflow = Core.f_if_2(
                  Core.t_string,
                  Core.t_thenelselist.vx_new(
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_eqeq(
                            layout,
                            Ui.c_layout_flow_columns
                          );
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.vx_new_string("column wrap");
                        })
                      ),
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_eqeq(
                            layout,
                            Ui.c_layout_flow_rows
                          );
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.vx_new_string("row wrap");
                        })
                      )
                  )
                );
                final Core.Type_string aligncontent = Core.f_if_2(
                  Core.t_string,
                  Core.t_thenelselist.vx_new(
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_or(
                            Core.f_eqeq(
                              layout,
                              Ui.c_layout_flow_columns
                            ),
                            Core.f_eqeq(
                              layout,
                              Ui.c_layout_flow_rows
                            )
                          );
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.vx_new_string("flex-start");
                        })
                      )
                  )
                );
                final Core.Type_string gap = Core.f_if_2(
                  Core.t_string,
                  Core.t_thenelselist.vx_new(
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_or(
                            Core.f_eqeq(
                              layout,
                              Ui.c_layout_flow_columns
                            ),
                            Core.f_eqeq(
                              layout,
                              Ui.c_layout_flow_rows
                            )
                          );
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.vx_new_string("1mm");
                        })
                      )
                  )
                );
                final Core.Type_string overflowx = Core.f_if_2(
                  Core.t_string,
                  Core.t_thenelselist.vx_new(
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_eqeq(
                            layout,
                            Ui.c_layout_flow_rows
                          );
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.vx_new_string("scroll");
                        })
                      )
                  )
                );
                final Core.Type_string overflowy = Core.f_if_2(
                  Core.t_string,
                  Core.t_thenelselist.vx_new(
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_eqeq(
                            layout,
                            Ui.c_layout_flow_columns
                          );
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.vx_new_string("scroll");
                        })
                      )
                  )
                );
                final Core.Type_string hoverbkgrdcolor = Core.f_if_2(
                  Core.t_string,
                  Core.t_thenelselist.vx_new(
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_ne(Core.vx_new_string(""), color_hoverbkgrd);
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.f_new(
                            Core.t_string,
                            Core.t_anylist.vx_new(
                                Core.vx_new_string("#"),
                                color_hoverbkgrd
                            )
                          );
                        })
                      )
                  )
                );
                final Html.Type_propmap props = Core.f_new(
                  Html.t_propmap,
                  Core.t_anylist.vx_new(
                      Core.vx_new_string(":background-color"),
                      backgroundcolor,
                      Core.vx_new_string(":display"),
                      display,
                      Core.vx_new_string(":flex-flow"),
                      flexflow,
                      Core.vx_new_string(":align-content"),
                      aligncontent,
                      Core.vx_new_string(":gap"),
                      gap,
                      Core.vx_new_string(":position"),
                      position,
                      Core.vx_new_string(":top"),
                      top,
                      Core.vx_new_string(":bottom"),
                      bottom,
                      Core.vx_new_string(":left"),
                      left,
                      Core.vx_new_string(":right"),
                      right,
                      Core.vx_new_string(":height"),
                      height,
                      Core.vx_new_string(":width"),
                      width,
                      Core.vx_new_string(":overflow-x"),
                      overflowx,
                      Core.vx_new_string(":overflow-y"),
                      overflowy
                  )
                );
                final Html.Type_propmap hoverprops = Core.f_new(
                  Html.t_propmap,
                  Core.t_anylist.vx_new(
                      Core.vx_new_string(":background-color"),
                      hoverbkgrdcolor
                  )
                );
                final Html.Type_subpropmap subprops = Core.f_new(
                  Html.t_subpropmap,
                  Core.t_anylist.vx_new(
                      Core.vx_new_string("&:hover"),
                      hoverprops
                  )
                );
                return Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":name"),
                    stylename,
                    Core.vx_new_string(":props"),
                    props
                  )
                );
              })
            );
          })
        )
      )
    );
    return output;
  }

  /**
   * @function stylelist_from_stylelist
   * Returns a htmlstylelist from a uistylemap
   * @param  {stylelist} uistylelist
   * @return {stylelist}
   * (func stylelist<-stylelist)
   */
  public static interface Func_stylelist_from_stylelist extends Core.Func_any_from_any {
    public Html.Type_stylelist vx_stylelist_from_stylelist(final Ui.Type_stylelist uistylelist);
  }

  public static class Class_stylelist_from_stylelist extends Core.Class_base implements Func_stylelist_from_stylelist {

    @Override
    public Func_stylelist_from_stylelist vx_new(Object... vals) {
      Class_stylelist_from_stylelist output = new Class_stylelist_from_stylelist();
      return output;
    }

    @Override
    public Func_stylelist_from_stylelist vx_copy(Object... vals) {
      Class_stylelist_from_stylelist output = new Class_stylelist_from_stylelist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylelist<-stylelist", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/web/html", // pkgname
          "stylelist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Html.t_style), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_stylelist_from_stylelist vx_empty() {return e_stylelist_from_stylelist;}
    @Override
    public Func_stylelist_from_stylelist vx_type() {return t_stylelist_from_stylelist;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_stylelist inputval = (Ui.Type_stylelist)value;
      Core.Type_any outputval = Uihtml.f_stylelist_from_stylelist(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_stylelist uistylelist = Core.f_any_from_any(Ui.t_stylelist, arglist.vx_any(Core.vx_new_int(0)));
      output = Uihtml.f_stylelist_from_stylelist(uistylelist);
      return output;
    }

    @Override
    public Html.Type_stylelist vx_stylelist_from_stylelist(final Ui.Type_stylelist uistylelist) {
      return Uihtml.f_stylelist_from_stylelist(uistylelist);
    }

  }

  public static final Func_stylelist_from_stylelist e_stylelist_from_stylelist = new Uihtml.Class_stylelist_from_stylelist();
  public static final Func_stylelist_from_stylelist t_stylelist_from_stylelist = new Uihtml.Class_stylelist_from_stylelist();

  public static Html.Type_stylelist f_stylelist_from_stylelist(final Ui.Type_stylelist uistylelist) {
    Html.Type_stylelist output = Html.e_stylelist;
    output = Core.f_list_from_list(
      Html.t_stylelist,
      uistylelist,
      Uihtml.t_style_from_style
    );
    return output;
  }

  /**
   * @function stylelist_from_stylemap
   * Returns a htmlstylelist from a uistylemap
   * @param  {stylemap} uistylemap
   * @return {stylelist}
   * (func stylelist<-stylemap)
   */
  public static interface Func_stylelist_from_stylemap extends Core.Func_any_from_any {
    public Html.Type_stylelist vx_stylelist_from_stylemap(final Ui.Type_stylemap uistylemap);
  }

  public static class Class_stylelist_from_stylemap extends Core.Class_base implements Func_stylelist_from_stylemap {

    @Override
    public Func_stylelist_from_stylemap vx_new(Object... vals) {
      Class_stylelist_from_stylemap output = new Class_stylelist_from_stylemap();
      return output;
    }

    @Override
    public Func_stylelist_from_stylemap vx_copy(Object... vals) {
      Class_stylelist_from_stylemap output = new Class_stylelist_from_stylemap();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylelist<-stylemap", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/web/html", // pkgname
          "stylelist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Html.t_style), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_stylelist_from_stylemap vx_empty() {return e_stylelist_from_stylemap;}
    @Override
    public Func_stylelist_from_stylemap vx_type() {return t_stylelist_from_stylemap;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_stylemap inputval = (Ui.Type_stylemap)value;
      Core.Type_any outputval = Uihtml.f_stylelist_from_stylemap(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_stylemap uistylemap = Core.f_any_from_any(Ui.t_stylemap, arglist.vx_any(Core.vx_new_int(0)));
      output = Uihtml.f_stylelist_from_stylemap(uistylemap);
      return output;
    }

    @Override
    public Html.Type_stylelist vx_stylelist_from_stylemap(final Ui.Type_stylemap uistylemap) {
      return Uihtml.f_stylelist_from_stylemap(uistylemap);
    }

  }

  public static final Func_stylelist_from_stylemap e_stylelist_from_stylemap = new Uihtml.Class_stylelist_from_stylemap();
  public static final Func_stylelist_from_stylemap t_stylelist_from_stylemap = new Uihtml.Class_stylelist_from_stylemap();

  public static Html.Type_stylelist f_stylelist_from_stylemap(final Ui.Type_stylemap uistylemap) {
    Html.Type_stylelist output = Html.e_stylelist;
    output = Core.f_list_from_map(
      Html.t_stylelist,
      uistylemap,
      Core.t_any_from_key_value.vx_fn_new((key_any, value_any) -> {
        Core.Type_string key = Core.f_any_from_any(Core.t_string, key_any);
        Ui.Type_style value = Core.f_any_from_any(Ui.t_style, value_any);
        return 
          Uihtml.f_style_from_style(value);
      })
    );
    return output;
  }

  /**
   * @function stylemap_from_stylemap
   * Returns a htmlstylesheet from a uistylesheet
   * @param  {stylemap} uistylemap
   * @return {stylemap}
   * (func stylemap<-stylemap)
   */
  public static interface Func_stylemap_from_stylemap extends Core.Func_any_from_any {
    public Html.Type_stylemap vx_stylemap_from_stylemap(final Ui.Type_stylemap uistylemap);
  }

  public static class Class_stylemap_from_stylemap extends Core.Class_base implements Func_stylemap_from_stylemap {

    @Override
    public Func_stylemap_from_stylemap vx_new(Object... vals) {
      Class_stylemap_from_stylemap output = new Class_stylemap_from_stylemap();
      return output;
    }

    @Override
    public Func_stylemap_from_stylemap vx_copy(Object... vals) {
      Class_stylemap_from_stylemap output = new Class_stylemap_from_stylemap();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylemap<-stylemap", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/web/html", // pkgname
          "stylemap", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Html.t_style), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_stylemap_from_stylemap vx_empty() {return e_stylemap_from_stylemap;}
    @Override
    public Func_stylemap_from_stylemap vx_type() {return t_stylemap_from_stylemap;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_stylemap inputval = (Ui.Type_stylemap)value;
      Core.Type_any outputval = Uihtml.f_stylemap_from_stylemap(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_stylemap uistylemap = Core.f_any_from_any(Ui.t_stylemap, arglist.vx_any(Core.vx_new_int(0)));
      output = Uihtml.f_stylemap_from_stylemap(uistylemap);
      return output;
    }

    @Override
    public Html.Type_stylemap vx_stylemap_from_stylemap(final Ui.Type_stylemap uistylemap) {
      return Uihtml.f_stylemap_from_stylemap(uistylemap);
    }

  }

  public static final Func_stylemap_from_stylemap e_stylemap_from_stylemap = new Uihtml.Class_stylemap_from_stylemap();
  public static final Func_stylemap_from_stylemap t_stylemap_from_stylemap = new Uihtml.Class_stylemap_from_stylemap();

  public static Html.Type_stylemap f_stylemap_from_stylemap(final Ui.Type_stylemap uistylemap) {
    Html.Type_stylemap output = Html.e_stylemap;
    output = Core.f_map_from_map(
      Html.t_stylemap,
      uistylemap,
      Core.t_any_from_key_value.vx_fn_new((key_any, value_any) -> {
        Core.Type_string key = Core.f_any_from_any(Core.t_string, key_any);
        Ui.Type_style value = Core.f_any_from_any(Ui.t_style, value_any);
        return 
          Uihtml.f_style_from_style(value);
      })
    );
    return output;
  }

  /**
   * 
   * @async
   * @function stylesheet_render_html
   * @param  {stylesheet} stylesheetui
   * @return {stylesheet}
   * (func stylesheet-render-html)
   */
  public static interface Func_stylesheet_render_html extends Core.Func_any_from_any_async {
    public CompletableFuture<Ui.Type_stylesheet> vx_stylesheet_render_html(final Ui.Type_stylesheet stylesheetui);
  }

  public static class Class_stylesheet_render_html extends Core.Class_base implements Func_stylesheet_render_html {

    @Override
    public Func_stylesheet_render_html vx_new(Object... vals) {
      Class_stylesheet_render_html output = new Class_stylesheet_render_html();
      return output;
    }

    @Override
    public Func_stylesheet_render_html vx_copy(Object... vals) {
      Class_stylesheet_render_html output = new Class_stylesheet_render_html();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylesheet-render-html", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "stylesheet", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_stylesheet_render_html vx_empty() {return e_stylesheet_render_html;}
    @Override
    public Func_stylesheet_render_html vx_type() {return t_stylesheet_render_html;}

    @Override
    public Core.Func_any_from_any_async vx_fn_new(Core.Class_any_from_any_async.IFn fn) {return Core.e_any_from_any_async;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> vx_any_from_any_async(final T generic_any_1, final U value) {
      Ui.Type_stylesheet inputval = Core.f_any_from_any(Ui.t_stylesheet, value);
      CompletableFuture<Ui.Type_stylesheet> future = Uihtml.f_stylesheet_render_html(inputval);
      @SuppressWarnings("unchecked")
      CompletableFuture<T> output = (CompletableFuture<T>)future;
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Ui.Type_stylesheet stylesheetui = Core.f_any_from_any(Ui.t_stylesheet, arglist.vx_any(Core.vx_new_int(0)));
      CompletableFuture<Ui.Type_stylesheet> future = Uihtml.f_stylesheet_render_html(stylesheetui);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Ui.Type_stylesheet> vx_stylesheet_render_html(final Ui.Type_stylesheet stylesheetui) {
      return Uihtml.f_stylesheet_render_html(stylesheetui);
    }

  }

  public static final Func_stylesheet_render_html e_stylesheet_render_html = new Uihtml.Class_stylesheet_render_html();
  public static final Func_stylesheet_render_html t_stylesheet_render_html = new Uihtml.Class_stylesheet_render_html();

  public static CompletableFuture<Ui.Type_stylesheet> f_stylesheet_render_html(final Ui.Type_stylesheet stylesheetui) {
    CompletableFuture<Ui.Type_stylesheet> output = Core.async_new_completed(Ui.e_stylesheet);
    output = Core.f_let_async(
      Ui.t_stylesheet,
      Core.t_any_from_func_async.vx_fn_new(() -> {
        final Html.Type_stylesheet stylesheethtml = Uihtml.f_stylesheet_from_stylesheet(stylesheetui);
        final CompletableFuture<Core.Type_boolean> future_write = Htmldoc.f_boolean_write_from_stylesheet(stylesheethtml);
        return Core.async_from_async_fn(future_write, (write) -> {
          return stylesheetui;
        });
      })
    );
    return output;
  }

  /**
   * @function stylesheet_from_stylesheet
   * Returns a htmlstylesheet from a uistylesheet
   * @param  {stylesheet} uistylesheet
   * @return {stylesheet}
   * (func stylesheet<-stylesheet)
   */
  public static interface Func_stylesheet_from_stylesheet extends Core.Func_any_from_any {
    public Html.Type_stylesheet vx_stylesheet_from_stylesheet(final Ui.Type_stylesheet uistylesheet);
  }

  public static class Class_stylesheet_from_stylesheet extends Core.Class_base implements Func_stylesheet_from_stylesheet {

    @Override
    public Func_stylesheet_from_stylesheet vx_new(Object... vals) {
      Class_stylesheet_from_stylesheet output = new Class_stylesheet_from_stylesheet();
      return output;
    }

    @Override
    public Func_stylesheet_from_stylesheet vx_copy(Object... vals) {
      Class_stylesheet_from_stylesheet output = new Class_stylesheet_from_stylesheet();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylesheet<-stylesheet", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/web/html", // pkgname
          "stylesheet", // name
          ":struct", // extends
          Core.t_typelist.vx_new(Html.t_node, Html.t_headchild), // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_stylesheet_from_stylesheet vx_empty() {return e_stylesheet_from_stylesheet;}
    @Override
    public Func_stylesheet_from_stylesheet vx_type() {return t_stylesheet_from_stylesheet;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Ui.Type_stylesheet inputval = (Ui.Type_stylesheet)value;
      Core.Type_any outputval = Uihtml.f_stylesheet_from_stylesheet(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_stylesheet uistylesheet = Core.f_any_from_any(Ui.t_stylesheet, arglist.vx_any(Core.vx_new_int(0)));
      output = Uihtml.f_stylesheet_from_stylesheet(uistylesheet);
      return output;
    }

    @Override
    public Html.Type_stylesheet vx_stylesheet_from_stylesheet(final Ui.Type_stylesheet uistylesheet) {
      return Uihtml.f_stylesheet_from_stylesheet(uistylesheet);
    }

  }

  public static final Func_stylesheet_from_stylesheet e_stylesheet_from_stylesheet = new Uihtml.Class_stylesheet_from_stylesheet();
  public static final Func_stylesheet_from_stylesheet t_stylesheet_from_stylesheet = new Uihtml.Class_stylesheet_from_stylesheet();

  public static Html.Type_stylesheet f_stylesheet_from_stylesheet(final Ui.Type_stylesheet uistylesheet) {
    Html.Type_stylesheet output = Html.e_stylesheet;
    output = Core.f_let(
      Html.t_stylesheet,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Ui.Type_stylemap uistylemap = uistylesheet.stylemap();
        final Html.Type_stylelist stylelist = Uihtml.f_stylelist_from_stylemap(uistylemap);
        return Core.f_new(
          Html.t_stylesheet,
          Core.t_anylist.vx_new(
            Core.vx_new_string(":styles"),
            stylelist
          )
        );
      })
    );
    return output;
  }

  /**
   * @function ui_render_app_from_ui_orig_parent
   * @param  {ui} ui
   * @param  {ui} orig
   * @param  {ui} parent
   * @return {ui}
   * (func ui-render-app<-ui-orig-parent)
   */
  public static interface Func_ui_render_app_from_ui_orig_parent extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_render_app_from_ui_orig_parent(final Ui.Type_ui ui, final Ui.Type_ui orig, final Ui.Type_ui parent);
  }

  public static class Class_ui_render_app_from_ui_orig_parent extends Core.Class_base implements Func_ui_render_app_from_ui_orig_parent {

    @Override
    public Func_ui_render_app_from_ui_orig_parent vx_new(Object... vals) {
      Class_ui_render_app_from_ui_orig_parent output = new Class_ui_render_app_from_ui_orig_parent();
      return output;
    }

    @Override
    public Func_ui_render_app_from_ui_orig_parent vx_copy(Object... vals) {
      Class_ui_render_app_from_ui_orig_parent output = new Class_ui_render_app_from_ui_orig_parent();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "ui-render-app<-ui-orig-parent", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_ui_render_app_from_ui_orig_parent vx_empty() {return e_ui_render_app_from_ui_orig_parent;}
    @Override
    public Func_ui_render_app_from_ui_orig_parent vx_type() {return t_ui_render_app_from_ui_orig_parent;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui orig = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(1)));
      Ui.Type_ui parent = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(2)));
      output = Uihtml.f_ui_render_app_from_ui_orig_parent(ui, orig, parent);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_render_app_from_ui_orig_parent(final Ui.Type_ui ui, final Ui.Type_ui orig, final Ui.Type_ui parent) {
      return Uihtml.f_ui_render_app_from_ui_orig_parent(ui, orig, parent);
    }

  }

  public static final Func_ui_render_app_from_ui_orig_parent e_ui_render_app_from_ui_orig_parent = new Uihtml.Class_ui_render_app_from_ui_orig_parent();
  public static final Func_ui_render_app_from_ui_orig_parent t_ui_render_app_from_ui_orig_parent = new Uihtml.Class_ui_render_app_from_ui_orig_parent();

  public static Ui.Type_ui f_ui_render_app_from_ui_orig_parent(final Ui.Type_ui ui, final Ui.Type_ui orig, final Ui.Type_ui parent) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string uid = ui.uid();
        final Ui.Type_uimap uimap = ui.uimap();
        final Html.Type_divchildlist children = Uihtml.f_divchildlist_from_uimap(uimap);
        final Html.Type_node node = Core.f_new(
          Html.t_div,
          Core.t_anylist.vx_new(
              Core.vx_new_string(":id"),
              uid,
              Core.vx_new_string(":nodes"),
              children
          )
        );
        final Html.Type_node nodechg = Uihtml.f_node_render_from_node_ui(node, ui);
        final Ui.Type_uimap uimapchg = Ui.f_uimap_render_from_uimap_parent(uimap, ui);
        return Core.f_new(
          Ui.t_ui,
          Core.t_anylist.vx_new(
            Core.vx_new_string(":uimap"),
            uimapchg
          )
        );
      })
    );
    return output;
  }

  /**
   * @function ui_render_default_from_ui_orig_parent
   * @param  {ui} ui
   * @param  {ui} orig
   * @param  {ui} parent
   * @return {ui}
   * (func ui-render-default<-ui-orig-parent)
   */
  public static interface Func_ui_render_default_from_ui_orig_parent extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_render_default_from_ui_orig_parent(final Ui.Type_ui ui, final Ui.Type_ui orig, final Ui.Type_ui parent);
  }

  public static class Class_ui_render_default_from_ui_orig_parent extends Core.Class_base implements Func_ui_render_default_from_ui_orig_parent {

    @Override
    public Func_ui_render_default_from_ui_orig_parent vx_new(Object... vals) {
      Class_ui_render_default_from_ui_orig_parent output = new Class_ui_render_default_from_ui_orig_parent();
      return output;
    }

    @Override
    public Func_ui_render_default_from_ui_orig_parent vx_copy(Object... vals) {
      Class_ui_render_default_from_ui_orig_parent output = new Class_ui_render_default_from_ui_orig_parent();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "ui-render-default<-ui-orig-parent", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_ui_render_default_from_ui_orig_parent vx_empty() {return e_ui_render_default_from_ui_orig_parent;}
    @Override
    public Func_ui_render_default_from_ui_orig_parent vx_type() {return t_ui_render_default_from_ui_orig_parent;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui orig = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(1)));
      Ui.Type_ui parent = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(2)));
      output = Uihtml.f_ui_render_default_from_ui_orig_parent(ui, orig, parent);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_render_default_from_ui_orig_parent(final Ui.Type_ui ui, final Ui.Type_ui orig, final Ui.Type_ui parent) {
      return Uihtml.f_ui_render_default_from_ui_orig_parent(ui, orig, parent);
    }

  }

  public static final Func_ui_render_default_from_ui_orig_parent e_ui_render_default_from_ui_orig_parent = new Uihtml.Class_ui_render_default_from_ui_orig_parent();
  public static final Func_ui_render_default_from_ui_orig_parent t_ui_render_default_from_ui_orig_parent = new Uihtml.Class_ui_render_default_from_ui_orig_parent();

  public static Ui.Type_ui f_ui_render_default_from_ui_orig_parent(final Ui.Type_ui ui, final Ui.Type_ui orig, final Ui.Type_ui parent) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string uid = ui.uid();
        final Ui.Type_uimap uimap = ui.uimap();
        final Ui.Type_style uistyle = ui.style();
        final Ui.Type_stylelist uistyles = ui.stylelist();
        final Html.Type_style style = Uihtml.f_style_from_style(uistyle);
        final Html.Type_stylelist styles = Uihtml.f_stylelist_from_stylelist(uistyles);
        final Html.Type_divchildlist children = Uihtml.f_divchildlist_from_uimap(uimap);
        final Html.Type_node node = Core.f_new(
          Html.t_div,
          Core.t_anylist.vx_new(
              Core.vx_new_string(":id"),
              uid,
              Core.vx_new_string(":style-unique"),
              style,
              Core.vx_new_string(":stylelist"),
              styles,
              Core.vx_new_string(":nodes"),
              children
          )
        );
        final Html.Type_node nodechg = Uihtml.f_node_render_from_node_ui(node, ui);
        final Ui.Type_uimap uimapchg = Ui.f_uimap_render_from_uimap_parent(uimap, ui);
        return Core.f_new(
          Ui.t_ui,
          Core.t_anylist.vx_new(
            Core.vx_new_string(":uimap"),
            uimapchg
          )
        );
      })
    );
    return output;
  }

  /**
   * @function ui_render_label_from_ui_orig_parent
   * @param  {ui} ui
   * @param  {ui} orig
   * @param  {ui} parent
   * @return {ui}
   * (func ui-render-label<-ui-orig-parent)
   */
  public static interface Func_ui_render_label_from_ui_orig_parent extends Core.Type_func, Core.Type_replfunc {
    public Ui.Type_ui vx_ui_render_label_from_ui_orig_parent(final Ui.Type_ui ui, final Ui.Type_ui orig, final Ui.Type_ui parent);
  }

  public static class Class_ui_render_label_from_ui_orig_parent extends Core.Class_base implements Func_ui_render_label_from_ui_orig_parent {

    @Override
    public Func_ui_render_label_from_ui_orig_parent vx_new(Object... vals) {
      Class_ui_render_label_from_ui_orig_parent output = new Class_ui_render_label_from_ui_orig_parent();
      return output;
    }

    @Override
    public Func_ui_render_label_from_ui_orig_parent vx_copy(Object... vals) {
      Class_ui_render_label_from_ui_orig_parent output = new Class_ui_render_label_from_ui_orig_parent();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "ui-render-label<-ui-orig-parent", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_ui_render_label_from_ui_orig_parent vx_empty() {return e_ui_render_label_from_ui_orig_parent;}
    @Override
    public Func_ui_render_label_from_ui_orig_parent vx_type() {return t_ui_render_label_from_ui_orig_parent;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Ui.Type_ui orig = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(1)));
      Ui.Type_ui parent = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(2)));
      output = Uihtml.f_ui_render_label_from_ui_orig_parent(ui, orig, parent);
      return output;
    }

    @Override
    public Ui.Type_ui vx_ui_render_label_from_ui_orig_parent(final Ui.Type_ui ui, final Ui.Type_ui orig, final Ui.Type_ui parent) {
      return Uihtml.f_ui_render_label_from_ui_orig_parent(ui, orig, parent);
    }

  }

  public static final Func_ui_render_label_from_ui_orig_parent e_ui_render_label_from_ui_orig_parent = new Uihtml.Class_ui_render_label_from_ui_orig_parent();
  public static final Func_ui_render_label_from_ui_orig_parent t_ui_render_label_from_ui_orig_parent = new Uihtml.Class_ui_render_label_from_ui_orig_parent();

  public static Ui.Type_ui f_ui_render_label_from_ui_orig_parent(final Ui.Type_ui ui, final Ui.Type_ui orig, final Ui.Type_ui parent) {
    Ui.Type_ui output = Ui.e_ui;
    output = Core.f_let(
      Ui.t_ui,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string uid = ui.uid();
        final Core.Type_any data = ui.data();
        final Ui.Type_uimap uimap = ui.uimap();
        final Ui.Type_style uistyle = ui.style();
        final Ui.Type_stylelist uistyles = ui.stylelist();
        final Html.Type_style style = Uihtml.f_style_from_style(uistyle);
        final Html.Type_stylelist styles = Uihtml.f_stylelist_from_stylelist(uistyles);
        final Core.Type_any datatype = Core.f_type_from_any(data);
        final Core.Type_string text = Core.f_if_2(
          Core.t_string,
          Core.t_thenelselist.vx_new(
              Core.f_then(
                Core.t_boolean_from_func.vx_fn_new(() -> {
                  return Core.f_eq(
                    datatype,
                    Core.t_string
                  );
                }),
                Core.t_any_from_func.vx_fn_new(() -> {
                  return Core.f_any_from_any(Core.t_string, data);
                })
              ),
              Core.f_else(
                Core.t_any_from_func.vx_fn_new(() -> {
                  return Core.f_string_from_any(data);
                })
              )
          )
        );
        final Html.Type_node node = Core.f_new(
          Html.t_p,
          Core.t_anylist.vx_new(
              Core.vx_new_string(":id"),
              uid,
              Core.vx_new_string(":style-unique"),
              style,
              Core.vx_new_string(":stylelist"),
              styles,
              Core.vx_new_string(":text"),
              text
          )
        );
        final Html.Type_node nodechg = Uihtml.f_node_render_from_node_ui(node, ui);
        final Ui.Type_uimap uimapchg = Ui.f_uimap_render_from_uimap_parent(uimap, ui);
        return Core.f_new(
          Ui.t_ui,
          Core.t_anylist.vx_new(
            Core.vx_new_string(":uimap"),
            uimapchg
          )
        );
      })
    );
    return output;
  }


  static {
    Const_layout_app_html.const_new(c_layout_app_html);
    Const_layout_else_html.const_new(c_layout_else_html);
    Const_layout_label_html.const_new(c_layout_label_html);
    Const_layoutenginehtml.const_new(c_layoutenginehtml);
    Map<String, Core.Type_any> maptype = new LinkedHashMap<>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<>();
    mapconst.put("layout-app-html", Uihtml.c_layout_app_html);
    mapconst.put("layout-else-html", Uihtml.c_layout_else_html);
    mapconst.put("layout-label-html", Uihtml.c_layout_label_html);
    mapconst.put("layoutenginehtml", Uihtml.c_layoutenginehtml);
    mapfunc.put("divchild<-ui", Uihtml.t_divchild_from_ui);
    mapfunc.put("divchildlist<-uimap", Uihtml.t_divchildlist_from_uimap);
    mapfunc.put("node-app<-ui-orig-parent", Uihtml.t_node_app_from_ui_orig_parent);
    mapfunc.put("node-render<-node-ui", Uihtml.t_node_render_from_node_ui);
    mapfunc.put("string-stylename<-name-styletype", Uihtml.t_string_stylename_from_name_styletype);
    mapfunc.put("style<-style", Uihtml.t_style_from_style);
    mapfunc.put("stylelist<-stylelist", Uihtml.t_stylelist_from_stylelist);
    mapfunc.put("stylelist<-stylemap", Uihtml.t_stylelist_from_stylemap);
    mapfunc.put("stylemap<-stylemap", Uihtml.t_stylemap_from_stylemap);
    mapfunc.put("stylesheet-render-html", Uihtml.t_stylesheet_render_html);
    mapfunc.put("stylesheet<-stylesheet", Uihtml.t_stylesheet_from_stylesheet);
    mapfunc.put("ui-render-app<-ui-orig-parent", Uihtml.t_ui_render_app_from_ui_orig_parent);
    mapfunc.put("ui-render-default<-ui-orig-parent", Uihtml.t_ui_render_default_from_ui_orig_parent);
    mapfunc.put("ui-render-label<-ui-orig-parent", Uihtml.t_ui_render_label_from_ui_orig_parent);
    Core.vx_global_package_set("vx/ui/html/uihtml", maptype, mapconst, mapfunc);
  }

}
