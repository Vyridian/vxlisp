namespace Vx.Ui.Html;

public static class Uihtml {


  /**
   * Constant: layout-app-html
   * Html App Renderer
   * {layout}
   */
  public class Const_layout_app_html {
    public static Vx.Core.Type_constdef constdef() {
      return Vx.Core.constdef_new(
        "vx/ui/html/uihtml", // pkgname
        "layout-app-html", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_copy(
        Vx.Ui.Ui.c_layout_app,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":fn-layout"),
                Vx.Ui.Html.Uihtml.t_ui_layout_app_from_ui_orig_parent
        )
      );
      outval.vx_p_name = val.name();
      outval.vx_p_fn_layout = val.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_app_html = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-else-html
   * Html Default Renderer
   * {layout}
   */
  public class Const_layout_else_html {
    public static Vx.Core.Type_constdef constdef() {
      return Vx.Core.constdef_new(
        "vx/ui/html/uihtml", // pkgname
        "layout-else-html", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_copy(
        Vx.Ui.Ui.c_layout_else,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":fn-layout"),
                Vx.Ui.Html.Uihtml.t_ui_layout_default_from_ui_orig_parent
        )
      );
      outval.vx_p_name = val.name();
      outval.vx_p_fn_layout = val.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_else_html = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-image-html
   * Html Image Renderer
   * {layout}
   */
  public class Const_layout_image_html {
    public static Vx.Core.Type_constdef constdef() {
      return Vx.Core.constdef_new(
        "vx/ui/html/uihtml", // pkgname
        "layout-image-html", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_copy(
        Vx.Ui.Ui.c_layout_image,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":fn-layout"),
                Vx.Ui.Html.Uihtml.t_ui_layout_image_from_ui_orig_parent
        )
      );
      outval.vx_p_name = val.name();
      outval.vx_p_fn_layout = val.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_image_html = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layout-label-html
   * Html Label Renderer
   * {layout}
   */
  public class Const_layout_label_html {
    public static Vx.Core.Type_constdef constdef() {
      return Vx.Core.constdef_new(
        "vx/ui/html/uihtml", // pkgname
        "layout-label-html", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layout", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
    }

    public static void const_new(Vx.Ui.Ui.Type_layout output) {
      Vx.Ui.Ui.Class_layout outval = (Vx.Ui.Ui.Class_layout)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layout val = Vx.Core.f_copy(
        Vx.Ui.Ui.c_layout_label,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":fn-layout"),
                Vx.Ui.Html.Uihtml.t_ui_layout_label_from_ui_orig_parent
        )
      );
      outval.vx_p_name = val.name();
      outval.vx_p_fn_layout = val.fn_layout();
    }

  }

  public static Vx.Ui.Ui.Type_layout c_layout_label_html = new Vx.Ui.Ui.Class_layout();


  /**
   * Constant: layoutenginehtml
   * Html layout engine used to render html from ui and stylesheet
   * {layoutengine}
   */
  public class Const_layoutenginehtml {
    public static Vx.Core.Type_constdef constdef() {
      return Vx.Core.constdef_new(
        "vx/ui/html/uihtml", // pkgname
        "layoutenginehtml", // name
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "layoutengine", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
    }

    public static void const_new(Vx.Ui.Ui.Type_layoutengine output) {
      Vx.Ui.Ui.Class_layoutengine outval = (Vx.Ui.Ui.Class_layoutengine)output;
      outval.vx_p_constdef = constdef();
      Vx.Ui.Ui.Type_layoutengine val = Vx.Core.f_new(
        Vx.Ui.Ui.t_layoutengine,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":layoutmap"),
                Vx.Ui.Ui.f_layoutmap_from_layoutlist(
                  Vx.Core.f_new(
                    Vx.Ui.Ui.t_layoutlist,
                    Vx.Core.vx_new(Vx.Core.t_anylist,
                      Vx.Ui.Html.Uihtml.c_layout_app_html,
                      Vx.Ui.Html.Uihtml.c_layout_image_html,
                      Vx.Ui.Html.Uihtml.c_layout_label_html
                    )
                  )
                ),
                Vx.Core.vx_new_string(":layoutelse"),
                Vx.Ui.Html.Uihtml.c_layout_else_html,
                Vx.Core.vx_new_string(":boolean-print"),
                Vx.Ui.Html.Uihtml.t_boolean_print_html,
                Vx.Core.vx_new_string(":boolean-layoutremove"),
                Vx.Ui.Html.Uihtml.t_boolean_layoutremove_html,
                Vx.Core.vx_new_string(":boolean-layoutselected"),
                Vx.Ui.Html.Uihtml.t_boolean_layoutselected_html,
                Vx.Core.vx_new_string(":boolean-layoutvisible"),
                Vx.Ui.Html.Uihtml.t_boolean_layoutvisible_html,
                Vx.Core.vx_new_string(":stylesheetrender"),
                Vx.Ui.Html.Uihtml.t_stylesheet_layout_html
        )
      );
      outval.vx_p_name = val.name();
      outval.vx_p_boolean_print = val.boolean_print();
      outval.vx_p_boolean_layoutremove = val.boolean_layoutremove();
      outval.vx_p_boolean_layoutselected = val.boolean_layoutselected();
      outval.vx_p_boolean_layoutvisible = val.boolean_layoutvisible();
      outval.vx_p_layoutmap = val.layoutmap();
      outval.vx_p_layoutelse = val.layoutelse();
      outval.vx_p_stylesheetrender = val.stylesheetrender();
    }

  }

  public static Vx.Ui.Ui.Type_layoutengine c_layoutenginehtml = new Vx.Ui.Ui.Class_layoutengine();


  /**
   * Constant: style-hidden
   * {style}
   */
  public class Const_style_hidden {
    public static Vx.Core.Type_constdef constdef() {
      return Vx.Core.constdef_new(
        "vx/ui/html/uihtml", // pkgname
        "style-hidden", // name
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "style", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
    }

    public static void const_new(Vx.Web.Html.Type_style output) {
      Vx.Web.Html.Class_style outval = (Vx.Web.Html.Class_style)output;
      outval.vx_p_constdef = constdef();
      Vx.Web.Html.Type_style val = Vx.Core.f_new(
        Vx.Web.Html.t_style,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string(".style-hidden")
        )
      );
      outval.vx_p_name = val.name();
      outval.vx_p_props = val.props();
      outval.vx_p_stylelist = val.stylelist();
    }

  }

  public static Vx.Web.Html.Type_style c_style_hidden = new Vx.Web.Html.Class_style();


  /**
   * Constant: style-selected
   * {style}
   */
  public class Const_style_selected {
    public static Vx.Core.Type_constdef constdef() {
      return Vx.Core.constdef_new(
        "vx/ui/html/uihtml", // pkgname
        "style-selected", // name
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "style", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
    }

    public static void const_new(Vx.Web.Html.Type_style output) {
      Vx.Web.Html.Class_style outval = (Vx.Web.Html.Class_style)output;
      outval.vx_p_constdef = constdef();
      Vx.Web.Html.Type_style val = Vx.Core.f_new(
        Vx.Web.Html.t_style,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string(".style-selected")
        )
      );
      outval.vx_p_name = val.name();
      outval.vx_p_props = val.props();
      outval.vx_p_stylelist = val.stylelist();
    }

  }

  public static Vx.Web.Html.Type_style c_style_selected = new Vx.Web.Html.Class_style();

  /**
   * @function boolean_layoutremove_html
   * Removes html node with a given ui.
   * @param  {ui} ui
   * @return {boolean}
   * (func boolean-layoutremove-html)
   */
  public interface Func_boolean_layoutremove_html : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_boolean_layoutremove_html(Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_boolean_layoutremove_html : Vx.Core.Class_base, Func_boolean_layoutremove_html {

    public override Vx.Ui.Html.Uihtml.Func_boolean_layoutremove_html vx_new(params object[] vals) {
      Class_boolean_layoutremove_html output = new Class_boolean_layoutremove_html();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_boolean_layoutremove_html vx_copy(params object[] vals) {
      Class_boolean_layoutremove_html output = new Class_boolean_layoutremove_html();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "boolean-layoutremove-html", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_layoutremove_html;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_layoutremove_html;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Html.Uihtml.f_boolean_layoutremove_html(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Html.Uihtml.f_boolean_layoutremove_html(ui);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_layoutremove_html(Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Html.Uihtml.f_boolean_layoutremove_html(ui);
    }

  }

  public static Func_boolean_layoutremove_html e_boolean_layoutremove_html = new Vx.Ui.Html.Uihtml.Class_boolean_layoutremove_html();
  public static Func_boolean_layoutremove_html t_boolean_layoutremove_html = new Vx.Ui.Html.Uihtml.Class_boolean_layoutremove_html();

  public static Vx.Core.Type_boolean f_boolean_layoutremove_html(Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string id = ui.uid();
        Vx.Core.Type_any output_1 = Vx.Web.Htmldoc.f_boolean_remove_from_id(id);
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function boolean_layoutselected_html
   * Removes html node with a given ui.
   * @param  {ui} ui
   * @return {boolean}
   * (func boolean-layoutselected-html)
   */
  public interface Func_boolean_layoutselected_html : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_boolean_layoutselected_html(Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_boolean_layoutselected_html : Vx.Core.Class_base, Func_boolean_layoutselected_html {

    public override Vx.Ui.Html.Uihtml.Func_boolean_layoutselected_html vx_new(params object[] vals) {
      Class_boolean_layoutselected_html output = new Class_boolean_layoutselected_html();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_boolean_layoutselected_html vx_copy(params object[] vals) {
      Class_boolean_layoutselected_html output = new Class_boolean_layoutselected_html();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "boolean-layoutselected-html", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_layoutselected_html;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_layoutselected_html;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Html.Uihtml.f_boolean_layoutselected_html(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Html.Uihtml.f_boolean_layoutselected_html(ui);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_layoutselected_html(Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Html.Uihtml.f_boolean_layoutselected_html(ui);
    }

  }

  public static Func_boolean_layoutselected_html e_boolean_layoutselected_html = new Vx.Ui.Html.Uihtml.Class_boolean_layoutselected_html();
  public static Func_boolean_layoutselected_html t_boolean_layoutselected_html = new Vx.Ui.Html.Uihtml.Class_boolean_layoutselected_html();

  public static Vx.Core.Type_boolean f_boolean_layoutselected_html(Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Ui.Html.Uihtml.f_boolean_writeclass_from_ui(ui);
    return output;
  }

  /**
   * @function boolean_layoutvisible_html
   * Removes html node with a given ui.
   * @param  {ui} ui
   * @return {boolean}
   * (func boolean-layoutvisible-html)
   */
  public interface Func_boolean_layoutvisible_html : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_boolean_layoutvisible_html(Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_boolean_layoutvisible_html : Vx.Core.Class_base, Func_boolean_layoutvisible_html {

    public override Vx.Ui.Html.Uihtml.Func_boolean_layoutvisible_html vx_new(params object[] vals) {
      Class_boolean_layoutvisible_html output = new Class_boolean_layoutvisible_html();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_boolean_layoutvisible_html vx_copy(params object[] vals) {
      Class_boolean_layoutvisible_html output = new Class_boolean_layoutvisible_html();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "boolean-layoutvisible-html", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_layoutvisible_html;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_layoutvisible_html;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Html.Uihtml.f_boolean_layoutvisible_html(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Html.Uihtml.f_boolean_layoutvisible_html(ui);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_layoutvisible_html(Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Html.Uihtml.f_boolean_layoutvisible_html(ui);
    }

  }

  public static Func_boolean_layoutvisible_html e_boolean_layoutvisible_html = new Vx.Ui.Html.Uihtml.Class_boolean_layoutvisible_html();
  public static Func_boolean_layoutvisible_html t_boolean_layoutvisible_html = new Vx.Ui.Html.Uihtml.Class_boolean_layoutvisible_html();

  public static Vx.Core.Type_boolean f_boolean_layoutvisible_html(Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Ui.Html.Uihtml.f_boolean_writeclass_from_ui(ui);
    return output;
  }

  /**
   * @function boolean_print_html
   * Create a print ready version of ui
   * @param  {ui} ui
   * @return {boolean}
   * (func boolean-print-html)
   */
  public interface Func_boolean_print_html : Vx.Core.Func_any_from_any_context {
    public Vx.Core.Type_boolean vx_boolean_print_html(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_boolean_print_html : Vx.Core.Class_base, Func_boolean_print_html {

    public override Vx.Ui.Html.Uihtml.Func_boolean_print_html vx_new(params object[] vals) {
      Class_boolean_print_html output = new Class_boolean_print_html();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_boolean_print_html vx_copy(params object[] vals) {
      Class_boolean_print_html output = new Class_boolean_print_html();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "boolean-print-html", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_print_html;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_print_html;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Html.Uihtml.f_boolean_print_html(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Html.Uihtml.f_boolean_print_html(context, ui);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_print_html(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Html.Uihtml.f_boolean_print_html(context, ui);
    }

  }

  public static Func_boolean_print_html e_boolean_print_html = new Vx.Ui.Html.Uihtml.Class_boolean_print_html();
  public static Func_boolean_print_html t_boolean_print_html = new Vx.Ui.Html.Uihtml.Class_boolean_print_html();

  public static Vx.Core.Type_boolean f_boolean_print_html(Vx.Core.Type_context context, Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string uid = ui.uid();
        Vx.Ui.Ui.Type_stylesheet stylesheetui = Vx.Ui.Ui.f_stylesheet_readstate(context);
        Vx.Web.Html.Type_stylesheet stylesheethtml = Vx.Ui.Html.Uihtml.f_stylesheet_from_stylesheet(stylesheetui);
        Vx.Core.Type_string styletext = Vx.Web.Html.f_string_from_stylesheet_indent(stylesheethtml, Vx.Core.vx_new_int(0));
        Vx.Core.Type_any output_1 = Vx.Web.Htmldoc.f_boolean_print_from_id_stylesheettext(uid, styletext);
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function boolean_writeclass_from_ui
   * Writes to an html node adding or removing the given hidden class.
   * @param  {ui} ui
   * @return {boolean}
   * (func boolean-writeclass<-ui)
   */
  public interface Func_boolean_writeclass_from_ui : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_boolean_writeclass_from_ui(Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_boolean_writeclass_from_ui : Vx.Core.Class_base, Func_boolean_writeclass_from_ui {

    public override Vx.Ui.Html.Uihtml.Func_boolean_writeclass_from_ui vx_new(params object[] vals) {
      Class_boolean_writeclass_from_ui output = new Class_boolean_writeclass_from_ui();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_boolean_writeclass_from_ui vx_copy(params object[] vals) {
      Class_boolean_writeclass_from_ui output = new Class_boolean_writeclass_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "boolean-writeclass<-ui", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_writeclass_from_ui;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_writeclass_from_ui;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Html.Uihtml.f_boolean_writeclass_from_ui(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Html.Uihtml.f_boolean_writeclass_from_ui(ui);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_writeclass_from_ui(Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Html.Uihtml.f_boolean_writeclass_from_ui(ui);
    }

  }

  public static Func_boolean_writeclass_from_ui e_boolean_writeclass_from_ui = new Vx.Ui.Html.Uihtml.Class_boolean_writeclass_from_ui();
  public static Func_boolean_writeclass_from_ui t_boolean_writeclass_from_ui = new Vx.Ui.Html.Uihtml.Class_boolean_writeclass_from_ui();

  public static Vx.Core.Type_boolean f_boolean_writeclass_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string id = ui.uid();
        Vx.Core.Type_string sclass = Vx.Ui.Html.Uihtml.f_string_class_from_ui(ui);
        Vx.Core.Type_any output_1 = Vx.Web.Htmldoc.f_boolean_write_from_id_attribute_value(id, Vx.Core.vx_new_string("class"), sclass);
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function boolean_writeeventsall_from_ui
   * Write the events for ui and subui to the dom.
   * @param  {ui} ui
   * @return {boolean}
   * (func boolean-writeeventsall<-ui)
   */
  public interface Func_boolean_writeeventsall_from_ui : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_boolean_writeeventsall_from_ui(Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_boolean_writeeventsall_from_ui : Vx.Core.Class_base, Func_boolean_writeeventsall_from_ui {

    public override Vx.Ui.Html.Uihtml.Func_boolean_writeeventsall_from_ui vx_new(params object[] vals) {
      Class_boolean_writeeventsall_from_ui output = new Class_boolean_writeeventsall_from_ui();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_boolean_writeeventsall_from_ui vx_copy(params object[] vals) {
      Class_boolean_writeeventsall_from_ui output = new Class_boolean_writeeventsall_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "boolean-writeeventsall<-ui", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_writeeventsall_from_ui;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_writeeventsall_from_ui;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Html.Uihtml.f_boolean_writeeventsall_from_ui(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Html.Uihtml.f_boolean_writeeventsall_from_ui(ui);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_writeeventsall_from_ui(Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Html.Uihtml.f_boolean_writeeventsall_from_ui(ui);
    }

  }

  public static Func_boolean_writeeventsall_from_ui e_boolean_writeeventsall_from_ui = new Vx.Ui.Html.Uihtml.Class_boolean_writeeventsall_from_ui();
  public static Func_boolean_writeeventsall_from_ui t_boolean_writeeventsall_from_ui = new Vx.Ui.Html.Uihtml.Class_boolean_writeeventsall_from_ui();

  public static Vx.Core.Type_boolean f_boolean_writeeventsall_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap uimap = ui.uimap();
        Vx.Core.Type_boolean iswrite1 = Vx.Web.Htmldoc.f_boolean_writeevents_from_ui(ui);
        Vx.Core.Type_boolean iswrite2 = Vx.Ui.Html.Uihtml.f_boolean_writeeventsall_from_uimap(uimap);
        Vx.Core.Type_any output_1 = Vx.Core.f_and(iswrite1, iswrite2);
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function boolean_writeeventsall_from_uimap
   * Write the events for each ui and subui to the dom.
   * @param  {uimap} uimap
   * @return {boolean}
   * (func boolean-writeeventsall<-uimap)
   */
  public interface Func_boolean_writeeventsall_from_uimap : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_boolean_writeeventsall_from_uimap(Vx.Ui.Ui.Type_uimap uimap);
  }

  public class Class_boolean_writeeventsall_from_uimap : Vx.Core.Class_base, Func_boolean_writeeventsall_from_uimap {

    public override Vx.Ui.Html.Uihtml.Func_boolean_writeeventsall_from_uimap vx_new(params object[] vals) {
      Class_boolean_writeeventsall_from_uimap output = new Class_boolean_writeeventsall_from_uimap();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_boolean_writeeventsall_from_uimap vx_copy(params object[] vals) {
      Class_boolean_writeeventsall_from_uimap output = new Class_boolean_writeeventsall_from_uimap();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "boolean-writeeventsall<-uimap", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_writeeventsall_from_uimap;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_writeeventsall_from_uimap;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_uimap inputval = (Vx.Ui.Ui.Type_uimap)value;
      Vx.Core.Type_any outputval = Vx.Ui.Html.Uihtml.f_boolean_writeeventsall_from_uimap(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_uimap uimap = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_uimap, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Html.Uihtml.f_boolean_writeeventsall_from_uimap(uimap);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_writeeventsall_from_uimap(Vx.Ui.Ui.Type_uimap uimap) {
      return Vx.Ui.Html.Uihtml.f_boolean_writeeventsall_from_uimap(uimap);
    }

  }

  public static Func_boolean_writeeventsall_from_uimap e_boolean_writeeventsall_from_uimap = new Vx.Ui.Html.Uihtml.Class_boolean_writeeventsall_from_uimap();
  public static Func_boolean_writeeventsall_from_uimap t_boolean_writeeventsall_from_uimap = new Vx.Ui.Html.Uihtml.Class_boolean_writeeventsall_from_uimap();

  public static Vx.Core.Type_boolean f_boolean_writeeventsall_from_uimap(Vx.Ui.Ui.Type_uimap uimap) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_booleanlist boollist = Vx.Core.f_list_from_map_1(
          Vx.Core.t_booleanlist,
          uimap,
          Vx.Core.t_any_from_key_value.vx_fn_new((key_any, value_any) => {
            Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, key_any);
            Vx.Ui.Ui.Type_ui value = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, value_any);
            Vx.Core.Type_any output_1 = 
                Vx.Ui.Html.Uihtml.f_boolean_writeeventsall_from_ui(value);
            return output_1;
          })
        );
        Vx.Core.Type_any output_2 = Vx.Core.f_and_1(boollist);
        return output_2;
      })
    );
    return output;
  }

  /**
   * @function boolean_writeselected_from_ui
   * Writes to an html node adding or removing the selected class.
   * @param  {ui} ui
   * @return {boolean}
   * (func boolean-writeselected<-ui)
   */
  public interface Func_boolean_writeselected_from_ui : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_boolean_writeselected_from_ui(Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_boolean_writeselected_from_ui : Vx.Core.Class_base, Func_boolean_writeselected_from_ui {

    public override Vx.Ui.Html.Uihtml.Func_boolean_writeselected_from_ui vx_new(params object[] vals) {
      Class_boolean_writeselected_from_ui output = new Class_boolean_writeselected_from_ui();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_boolean_writeselected_from_ui vx_copy(params object[] vals) {
      Class_boolean_writeselected_from_ui output = new Class_boolean_writeselected_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "boolean-writeselected<-ui", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_writeselected_from_ui;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_writeselected_from_ui;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Html.Uihtml.f_boolean_writeselected_from_ui(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Html.Uihtml.f_boolean_writeselected_from_ui(ui);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_writeselected_from_ui(Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Html.Uihtml.f_boolean_writeselected_from_ui(ui);
    }

  }

  public static Func_boolean_writeselected_from_ui e_boolean_writeselected_from_ui = new Vx.Ui.Html.Uihtml.Class_boolean_writeselected_from_ui();
  public static Func_boolean_writeselected_from_ui t_boolean_writeselected_from_ui = new Vx.Ui.Html.Uihtml.Class_boolean_writeselected_from_ui();

  public static Vx.Core.Type_boolean f_boolean_writeselected_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Ui.Html.Uihtml.f_boolean_writeclass_from_ui(ui);
    return output;
  }

  /**
   * @function boolean_writevisible_from_ui
   * Writes to an html node adding or removing the hidden class.
   * @param  {ui} ui
   * @return {boolean}
   * (func boolean-writevisible<-ui)
   */
  public interface Func_boolean_writevisible_from_ui : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_boolean_writevisible_from_ui(Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_boolean_writevisible_from_ui : Vx.Core.Class_base, Func_boolean_writevisible_from_ui {

    public override Vx.Ui.Html.Uihtml.Func_boolean_writevisible_from_ui vx_new(params object[] vals) {
      Class_boolean_writevisible_from_ui output = new Class_boolean_writevisible_from_ui();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_boolean_writevisible_from_ui vx_copy(params object[] vals) {
      Class_boolean_writevisible_from_ui output = new Class_boolean_writevisible_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "boolean-writevisible<-ui", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_writevisible_from_ui;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_writevisible_from_ui;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Html.Uihtml.f_boolean_writevisible_from_ui(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Html.Uihtml.f_boolean_writevisible_from_ui(ui);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_writevisible_from_ui(Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Html.Uihtml.f_boolean_writevisible_from_ui(ui);
    }

  }

  public static Func_boolean_writevisible_from_ui e_boolean_writevisible_from_ui = new Vx.Ui.Html.Uihtml.Class_boolean_writevisible_from_ui();
  public static Func_boolean_writevisible_from_ui t_boolean_writevisible_from_ui = new Vx.Ui.Html.Uihtml.Class_boolean_writevisible_from_ui();

  public static Vx.Core.Type_boolean f_boolean_writevisible_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Ui.Html.Uihtml.f_boolean_writeclass_from_ui(ui);
    return output;
  }

  /**
   * @function context_write
   * @return {context}
   * (func context-write)
   */
  public interface Func_context_write : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_context vx_context_write(Vx.Core.Type_context context);
  }

  public class Class_context_write : Vx.Core.Class_base, Func_context_write {

    public override Vx.Ui.Html.Uihtml.Func_context_write vx_new(params object[] vals) {
      Class_context_write output = new Class_context_write();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_context_write vx_copy(params object[] vals) {
      Class_context_write output = new Class_context_write();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "context-write", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "context", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_context_write;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_context_write;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Html.Uihtml.f_context_write(context);
      return output;
    }

    public Vx.Core.Type_context vx_context_write(Vx.Core.Type_context context) {
      return Vx.Ui.Html.Uihtml.f_context_write(context);
    }

  }

  public static Func_context_write e_context_write = new Vx.Ui.Html.Uihtml.Class_context_write();
  public static Func_context_write t_context_write = new Vx.Ui.Html.Uihtml.Class_context_write();

  public static Vx.Core.Type_context f_context_write(Vx.Core.Type_context context) {
    Vx.Core.Type_context output = Vx.Core.e_context;
    output = Vx.Web.Htmldoc.f_context_write(context);
    return output;
  }

  /**
   * @function divchild_from_ui
   * Returns a divchild from a ui
   * @param  {ui} ui
   * @return {divchild}
   * (func divchild<-ui)
   */
  public interface Func_divchild_from_ui : Vx.Core.Func_any_from_any {
    public Vx.Web.Html.Type_divchild vx_divchild_from_ui(Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_divchild_from_ui : Vx.Core.Class_base, Func_divchild_from_ui {

    public override Vx.Ui.Html.Uihtml.Func_divchild_from_ui vx_new(params object[] vals) {
      Class_divchild_from_ui output = new Class_divchild_from_ui();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_divchild_from_ui vx_copy(params object[] vals) {
      Class_divchild_from_ui output = new Class_divchild_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "divchild<-ui", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "divchild", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_divchild_from_ui;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_divchild_from_ui;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Html.Uihtml.f_divchild_from_ui(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Html.Uihtml.f_divchild_from_ui(ui);
      return output;
    }

    public Vx.Web.Html.Type_divchild vx_divchild_from_ui(Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Html.Uihtml.f_divchild_from_ui(ui);
    }

  }

  public static Func_divchild_from_ui e_divchild_from_ui = new Vx.Ui.Html.Uihtml.Class_divchild_from_ui();
  public static Func_divchild_from_ui t_divchild_from_ui = new Vx.Ui.Html.Uihtml.Class_divchild_from_ui();

  public static Vx.Web.Html.Type_divchild f_divchild_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Web.Html.Type_divchild output = Vx.Web.Html.e_divchild;
    output = Vx.Core.f_let(
      Vx.Web.Html.t_div,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string uid = ui.uid();
        Vx.Ui.Ui.Type_uimap uimapchild = ui.uimap();
        Vx.Ui.Ui.Type_style uistyle = ui.style();
        Vx.Ui.Ui.Type_stylelist uistyles = ui.stylelist();
        Vx.Web.Html.Type_style styleunique = Vx.Ui.Html.Uihtml.f_style_from_style(uistyle);
        Vx.Web.Html.Type_stylelist htmlstyles = Vx.Ui.Html.Uihtml.f_stylelist_from_stylelist(uistyles);
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Web.Html.t_div,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":id"),
            uid,
            Vx.Core.vx_new_string(":style-unique"),
            styleunique,
            Vx.Core.vx_new_string(":stylelist"),
            htmlstyles
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function divchildlist_from_uimap
   * Returns a divchildlist of divs from a uimap
   * @param  {uimap} uimap
   * @return {divchildlist}
   * (func divchildlist<-uimap)
   */
  public interface Func_divchildlist_from_uimap : Vx.Core.Func_any_from_any {
    public Vx.Web.Html.Type_divchildlist vx_divchildlist_from_uimap(Vx.Ui.Ui.Type_uimap uimap);
  }

  public class Class_divchildlist_from_uimap : Vx.Core.Class_base, Func_divchildlist_from_uimap {

    public override Vx.Ui.Html.Uihtml.Func_divchildlist_from_uimap vx_new(params object[] vals) {
      Class_divchildlist_from_uimap output = new Class_divchildlist_from_uimap();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_divchildlist_from_uimap vx_copy(params object[] vals) {
      Class_divchildlist_from_uimap output = new Class_divchildlist_from_uimap();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "divchildlist<-uimap", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "divchildlist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_divchild), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_divchildlist_from_uimap;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_divchildlist_from_uimap;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_uimap inputval = (Vx.Ui.Ui.Type_uimap)value;
      Vx.Core.Type_any outputval = Vx.Ui.Html.Uihtml.f_divchildlist_from_uimap(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_uimap uimap = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_uimap, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Html.Uihtml.f_divchildlist_from_uimap(uimap);
      return output;
    }

    public Vx.Web.Html.Type_divchildlist vx_divchildlist_from_uimap(Vx.Ui.Ui.Type_uimap uimap) {
      return Vx.Ui.Html.Uihtml.f_divchildlist_from_uimap(uimap);
    }

  }

  public static Func_divchildlist_from_uimap e_divchildlist_from_uimap = new Vx.Ui.Html.Uihtml.Class_divchildlist_from_uimap();
  public static Func_divchildlist_from_uimap t_divchildlist_from_uimap = new Vx.Ui.Html.Uihtml.Class_divchildlist_from_uimap();

  public static Vx.Web.Html.Type_divchildlist f_divchildlist_from_uimap(Vx.Ui.Ui.Type_uimap uimap) {
    Vx.Web.Html.Type_divchildlist output = Vx.Web.Html.e_divchildlist;
    output = Vx.Core.f_list_from_map_1(
      Vx.Web.Html.t_divchildlist,
      uimap,
      Vx.Core.t_any_from_key_value.vx_fn_new((key_any, value_any) => {
        Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, key_any);
        Vx.Ui.Ui.Type_ui value = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, value_any);
        Vx.Core.Type_any output_1 = 
          Vx.Core.f_let(
            Vx.Web.Html.t_div,
            Vx.Core.t_any_from_func.vx_fn_new(() => {
              Vx.Core.Type_string uid = value.uid();
              Vx.Core.Type_any output_2 = Vx.Core.f_new(
                Vx.Web.Html.t_div,
                Vx.Core.vx_new(Vx.Core.t_anylist,
                  Vx.Core.vx_new_string(":id"),
                  uid
                )
              );
              return output_2;
            })
          );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function divchildlist_from_uimap 1
   * Returns a divchildlist of divs from a uimap
   * @param  {uimap} uimap
   * @return {divchildlist}
   * (func divchildlist<-uimap)
   */
  public interface Func_divchildlist_from_uimap_1 : Vx.Core.Func_any_from_any {
    public Vx.Web.Html.Type_divchildlist vx_divchildlist_from_uimap_1(Vx.Ui.Ui.Type_uimap uimap);
  }

  public class Class_divchildlist_from_uimap_1 : Vx.Core.Class_base, Func_divchildlist_from_uimap_1 {

    public override Vx.Ui.Html.Uihtml.Func_divchildlist_from_uimap_1 vx_new(params object[] vals) {
      Class_divchildlist_from_uimap_1 output = new Class_divchildlist_from_uimap_1();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_divchildlist_from_uimap_1 vx_copy(params object[] vals) {
      Class_divchildlist_from_uimap_1 output = new Class_divchildlist_from_uimap_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "divchildlist<-uimap", // name
        1, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "divchildlist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_divchild), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_divchildlist_from_uimap_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_divchildlist_from_uimap_1;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_uimap inputval = (Vx.Ui.Ui.Type_uimap)value;
      Vx.Core.Type_any outputval = Vx.Ui.Html.Uihtml.f_divchildlist_from_uimap_1(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_uimap uimap = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_uimap, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Html.Uihtml.f_divchildlist_from_uimap_1(uimap);
      return output;
    }

    public Vx.Web.Html.Type_divchildlist vx_divchildlist_from_uimap_1(Vx.Ui.Ui.Type_uimap uimap) {
      return Vx.Ui.Html.Uihtml.f_divchildlist_from_uimap_1(uimap);
    }

  }

  public static Func_divchildlist_from_uimap_1 e_divchildlist_from_uimap_1 = new Vx.Ui.Html.Uihtml.Class_divchildlist_from_uimap_1();
  public static Func_divchildlist_from_uimap_1 t_divchildlist_from_uimap_1 = new Vx.Ui.Html.Uihtml.Class_divchildlist_from_uimap_1();

  public static Vx.Web.Html.Type_divchildlist f_divchildlist_from_uimap_1(Vx.Ui.Ui.Type_uimap uimap) {
    Vx.Web.Html.Type_divchildlist output = Vx.Web.Html.e_divchildlist;
    output = Vx.Core.f_list_from_map_1(
      Vx.Web.Html.t_divchildlist,
      uimap,
      Vx.Core.t_any_from_key_value.vx_fn_new((key_any, value_any) => {
        Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, key_any);
        Vx.Ui.Ui.Type_ui value = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, value_any);
        Vx.Core.Type_any output_1 = 
          Vx.Core.f_let(
            Vx.Web.Html.t_div,
            Vx.Core.t_any_from_func.vx_fn_new(() => {
              Vx.Core.Type_string uid = value.uid();
              Vx.Core.Type_any output_2 = Vx.Core.f_new(
                Vx.Web.Html.t_div,
                Vx.Core.vx_new(Vx.Core.t_anylist,
                  Vx.Core.vx_new_string(":id"),
                  uid
                )
              );
              return output_2;
            })
          );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function divchildlist_from_uimap_origmap_parent
   * Returns a divchildlist of divs from a uimap
   * @param  {uimap} uimap
   * @param  {uimap} origmap
   * @param  {ui} parent
   * @return {divchildlist}
   * (func divchildlist<-uimap-origmap-parent)
   */
  public interface Func_divchildlist_from_uimap_origmap_parent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Web.Html.Type_divchildlist vx_divchildlist_from_uimap_origmap_parent(Vx.Ui.Ui.Type_uimap uimap, Vx.Ui.Ui.Type_uimap origmap, Vx.Ui.Ui.Type_ui parent);
  }

  public class Class_divchildlist_from_uimap_origmap_parent : Vx.Core.Class_base, Func_divchildlist_from_uimap_origmap_parent {

    public override Vx.Ui.Html.Uihtml.Func_divchildlist_from_uimap_origmap_parent vx_new(params object[] vals) {
      Class_divchildlist_from_uimap_origmap_parent output = new Class_divchildlist_from_uimap_origmap_parent();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_divchildlist_from_uimap_origmap_parent vx_copy(params object[] vals) {
      Class_divchildlist_from_uimap_origmap_parent output = new Class_divchildlist_from_uimap_origmap_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "divchildlist<-uimap-origmap-parent", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "divchildlist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_divchild), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_divchildlist_from_uimap_origmap_parent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_divchildlist_from_uimap_origmap_parent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_uimap uimap = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_uimap, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_uimap origmap = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_uimap, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Ui.Ui.Type_ui parent = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Ui.Html.Uihtml.f_divchildlist_from_uimap_origmap_parent(uimap, origmap, parent);
      return output;
    }

    public Vx.Web.Html.Type_divchildlist vx_divchildlist_from_uimap_origmap_parent(Vx.Ui.Ui.Type_uimap uimap, Vx.Ui.Ui.Type_uimap origmap, Vx.Ui.Ui.Type_ui parent) {
      return Vx.Ui.Html.Uihtml.f_divchildlist_from_uimap_origmap_parent(uimap, origmap, parent);
    }

  }

  public static Func_divchildlist_from_uimap_origmap_parent e_divchildlist_from_uimap_origmap_parent = new Vx.Ui.Html.Uihtml.Class_divchildlist_from_uimap_origmap_parent();
  public static Func_divchildlist_from_uimap_origmap_parent t_divchildlist_from_uimap_origmap_parent = new Vx.Ui.Html.Uihtml.Class_divchildlist_from_uimap_origmap_parent();

  public static Vx.Web.Html.Type_divchildlist f_divchildlist_from_uimap_origmap_parent(Vx.Ui.Ui.Type_uimap uimap, Vx.Ui.Ui.Type_uimap origmap, Vx.Ui.Ui.Type_ui parent) {
    Vx.Web.Html.Type_divchildlist output = Vx.Web.Html.e_divchildlist;
    output = Vx.Core.f_list_from_map_1(
      Vx.Web.Html.t_divchildlist,
      uimap,
      Vx.Core.t_any_from_key_value.vx_fn_new((key_any, value_any) => {
        Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, key_any);
        Vx.Ui.Ui.Type_ui value = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, value_any);
        Vx.Core.Type_any output_1 = 
          Vx.Core.f_let(
            Vx.Web.Html.t_node,
            Vx.Core.t_any_from_func.vx_fn_new(() => {
              Vx.Ui.Ui.Type_ui origvalue = Vx.Core.f_any_from_map(Vx.Ui.Ui.t_ui, origmap, key);
              Vx.Core.Type_any output_2 = Vx.Ui.Html.Uihtml.f_node_from_ui_orig_parent(value, origvalue, parent);
              return output_2;
            })
          );
        return output_1;
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
  public interface Func_node_app_from_ui_orig_parent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Web.Html.Type_node vx_node_app_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent);
  }

  public class Class_node_app_from_ui_orig_parent : Vx.Core.Class_base, Func_node_app_from_ui_orig_parent {

    public override Vx.Ui.Html.Uihtml.Func_node_app_from_ui_orig_parent vx_new(params object[] vals) {
      Class_node_app_from_ui_orig_parent output = new Class_node_app_from_ui_orig_parent();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_node_app_from_ui_orig_parent vx_copy(params object[] vals) {
      Class_node_app_from_ui_orig_parent output = new Class_node_app_from_ui_orig_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "node-app<-ui-orig-parent", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "node", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_node_app_from_ui_orig_parent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_node_app_from_ui_orig_parent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui orig = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Ui.Ui.Type_ui parent = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Ui.Html.Uihtml.f_node_app_from_ui_orig_parent(ui, orig, parent);
      return output;
    }

    public Vx.Web.Html.Type_node vx_node_app_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent) {
      return Vx.Ui.Html.Uihtml.f_node_app_from_ui_orig_parent(ui, orig, parent);
    }

  }

  public static Func_node_app_from_ui_orig_parent e_node_app_from_ui_orig_parent = new Vx.Ui.Html.Uihtml.Class_node_app_from_ui_orig_parent();
  public static Func_node_app_from_ui_orig_parent t_node_app_from_ui_orig_parent = new Vx.Ui.Html.Uihtml.Class_node_app_from_ui_orig_parent();

  public static Vx.Web.Html.Type_node f_node_app_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent) {
    Vx.Web.Html.Type_node output = Vx.Web.Html.e_node;
    output = Vx.Core.f_let(
      Vx.Web.Html.t_node,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string uid = ui.uid();
        Vx.Ui.Ui.Type_uimap uimap = ui.uimap();
        Vx.Ui.Ui.Type_uimap origmap = orig.uimap();
        Vx.Web.Html.Type_divchildlist children = Vx.Ui.Html.Uihtml.f_divchildlist_from_uimap_origmap_parent(uimap, origmap, ui);
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Web.Html.t_div,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":id"),
            uid,
            Vx.Core.vx_new_string(":nodes"),
            children
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function node_default_from_ui_orig_parent
   * @param  {ui} ui
   * @param  {ui} orig
   * @param  {ui} parent
   * @return {node}
   * (func node-default<-ui-orig-parent)
   */
  public interface Func_node_default_from_ui_orig_parent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Web.Html.Type_node vx_node_default_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent);
  }

  public class Class_node_default_from_ui_orig_parent : Vx.Core.Class_base, Func_node_default_from_ui_orig_parent {

    public override Vx.Ui.Html.Uihtml.Func_node_default_from_ui_orig_parent vx_new(params object[] vals) {
      Class_node_default_from_ui_orig_parent output = new Class_node_default_from_ui_orig_parent();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_node_default_from_ui_orig_parent vx_copy(params object[] vals) {
      Class_node_default_from_ui_orig_parent output = new Class_node_default_from_ui_orig_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "node-default<-ui-orig-parent", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "node", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_node_default_from_ui_orig_parent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_node_default_from_ui_orig_parent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui orig = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Ui.Ui.Type_ui parent = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Ui.Html.Uihtml.f_node_default_from_ui_orig_parent(ui, orig, parent);
      return output;
    }

    public Vx.Web.Html.Type_node vx_node_default_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent) {
      return Vx.Ui.Html.Uihtml.f_node_default_from_ui_orig_parent(ui, orig, parent);
    }

  }

  public static Func_node_default_from_ui_orig_parent e_node_default_from_ui_orig_parent = new Vx.Ui.Html.Uihtml.Class_node_default_from_ui_orig_parent();
  public static Func_node_default_from_ui_orig_parent t_node_default_from_ui_orig_parent = new Vx.Ui.Html.Uihtml.Class_node_default_from_ui_orig_parent();

  public static Vx.Web.Html.Type_node f_node_default_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent) {
    Vx.Web.Html.Type_node output = Vx.Web.Html.e_node;
    output = Vx.Core.f_let(
      Vx.Web.Html.t_node,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string uid = ui.uid();
        Vx.Ui.Ui.Type_uimap uimap = ui.uimap();
        Vx.Ui.Ui.Type_style uistyle = ui.style();
        Vx.Ui.Ui.Type_uimap origmap = orig.uimap();
        Vx.Web.Html.Type_style style = Vx.Ui.Html.Uihtml.f_style_from_style(uistyle);
        Vx.Web.Html.Type_stylelist styles = Vx.Ui.Html.Uihtml.f_stylelist_extra_from_ui(ui);
        Vx.Web.Html.Type_divchildlist children = Vx.Ui.Html.Uihtml.f_divchildlist_from_uimap_origmap_parent(uimap, origmap, ui);
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Web.Html.t_div,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":id"),
            uid,
            Vx.Core.vx_new_string(":style-unique"),
            style,
            Vx.Core.vx_new_string(":stylelist"),
            styles,
            Vx.Core.vx_new_string(":nodes"),
            children
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function node_image_from_ui_orig_parent
   * @param  {ui} ui
   * @param  {ui} orig
   * @param  {ui} parent
   * @return {node}
   * (func node-image<-ui-orig-parent)
   */
  public interface Func_node_image_from_ui_orig_parent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Web.Html.Type_node vx_node_image_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent);
  }

  public class Class_node_image_from_ui_orig_parent : Vx.Core.Class_base, Func_node_image_from_ui_orig_parent {

    public override Vx.Ui.Html.Uihtml.Func_node_image_from_ui_orig_parent vx_new(params object[] vals) {
      Class_node_image_from_ui_orig_parent output = new Class_node_image_from_ui_orig_parent();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_node_image_from_ui_orig_parent vx_copy(params object[] vals) {
      Class_node_image_from_ui_orig_parent output = new Class_node_image_from_ui_orig_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "node-image<-ui-orig-parent", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "node", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_node_image_from_ui_orig_parent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_node_image_from_ui_orig_parent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui orig = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Ui.Ui.Type_ui parent = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Ui.Html.Uihtml.f_node_image_from_ui_orig_parent(ui, orig, parent);
      return output;
    }

    public Vx.Web.Html.Type_node vx_node_image_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent) {
      return Vx.Ui.Html.Uihtml.f_node_image_from_ui_orig_parent(ui, orig, parent);
    }

  }

  public static Func_node_image_from_ui_orig_parent e_node_image_from_ui_orig_parent = new Vx.Ui.Html.Uihtml.Class_node_image_from_ui_orig_parent();
  public static Func_node_image_from_ui_orig_parent t_node_image_from_ui_orig_parent = new Vx.Ui.Html.Uihtml.Class_node_image_from_ui_orig_parent();

  public static Vx.Web.Html.Type_node f_node_image_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent) {
    Vx.Web.Html.Type_node output = Vx.Web.Html.e_node;
    output = Vx.Core.f_let(
      Vx.Web.Html.t_node,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string uid = ui.uid();
        Vx.Ui.Ui.Type_style uistyle = ui.style();
        Vx.Core.Type_any data = ui.data();
        Vx.Data.File.Type_file file = Vx.Core.f_any_from_any(Vx.Data.File.t_file, data);
        Vx.Core.Type_string path = Vx.Data.File.f_pathfull_from_file(file);
        Vx.Web.Html.Type_style style = Vx.Ui.Html.Uihtml.f_style_from_style(uistyle);
        Vx.Web.Html.Type_stylelist styles = Vx.Ui.Html.Uihtml.f_stylelist_extra_from_ui(ui);
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Web.Html.t_img,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":id"),
            uid,
            Vx.Core.vx_new_string(":style-unique"),
            style,
            Vx.Core.vx_new_string(":stylelist"),
            styles,
            Vx.Core.vx_new_string(":src"),
            path
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function node_label_from_ui_orig_parent
   * @param  {ui} ui
   * @param  {ui} orig
   * @param  {ui} parent
   * @return {node}
   * (func node-label<-ui-orig-parent)
   */
  public interface Func_node_label_from_ui_orig_parent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Web.Html.Type_node vx_node_label_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent);
  }

  public class Class_node_label_from_ui_orig_parent : Vx.Core.Class_base, Func_node_label_from_ui_orig_parent {

    public override Vx.Ui.Html.Uihtml.Func_node_label_from_ui_orig_parent vx_new(params object[] vals) {
      Class_node_label_from_ui_orig_parent output = new Class_node_label_from_ui_orig_parent();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_node_label_from_ui_orig_parent vx_copy(params object[] vals) {
      Class_node_label_from_ui_orig_parent output = new Class_node_label_from_ui_orig_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "node-label<-ui-orig-parent", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "node", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_node_label_from_ui_orig_parent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_node_label_from_ui_orig_parent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui orig = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Ui.Ui.Type_ui parent = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Ui.Html.Uihtml.f_node_label_from_ui_orig_parent(ui, orig, parent);
      return output;
    }

    public Vx.Web.Html.Type_node vx_node_label_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent) {
      return Vx.Ui.Html.Uihtml.f_node_label_from_ui_orig_parent(ui, orig, parent);
    }

  }

  public static Func_node_label_from_ui_orig_parent e_node_label_from_ui_orig_parent = new Vx.Ui.Html.Uihtml.Class_node_label_from_ui_orig_parent();
  public static Func_node_label_from_ui_orig_parent t_node_label_from_ui_orig_parent = new Vx.Ui.Html.Uihtml.Class_node_label_from_ui_orig_parent();

  public static Vx.Web.Html.Type_node f_node_label_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent) {
    Vx.Web.Html.Type_node output = Vx.Web.Html.e_node;
    output = Vx.Core.f_let(
      Vx.Web.Html.t_node,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string uid = ui.uid();
        Vx.Core.Type_any data = ui.data();
        Vx.Ui.Ui.Type_uimap uimap = ui.uimap();
        Vx.Ui.Ui.Type_style uistyle = ui.style();
        Vx.Ui.Ui.Type_stylelist uistyles = ui.stylelist();
        Vx.Core.Type_any datatype = Vx.Core.f_type_from_any(data);
        Vx.Web.Html.Type_style style = Vx.Ui.Html.Uihtml.f_style_from_style(uistyle);
        Vx.Web.Html.Type_stylelist styles = Vx.Ui.Html.Uihtml.f_stylelist_from_stylelist(uistyles);
        Vx.Core.Type_string text = Vx.Core.f_if_2(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
              Vx.Core.f_then(
                Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                  return Vx.Core.f_eqeq(
                    datatype,
                    Vx.Core.t_string
                  );
                }),
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Core.f_any_from_any(Vx.Core.t_string, data);
                })
              ),
              Vx.Core.f_else(
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Core.f_string_from_any(data);
                })
              )
          )
        );
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Web.Html.t_p,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":id"),
            uid,
            Vx.Core.vx_new_string(":style-unique"),
            style,
            Vx.Core.vx_new_string(":stylelist"),
            styles,
            Vx.Core.vx_new_string(":text"),
            text
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function node_layout_from_node_ui_parent
   * @param  {node} node
   * @param  {ui} ui
   * @param  {ui} parent
   * @return {node}
   * (func node-layout<-node-ui-parent)
   */
  public interface Func_node_layout_from_node_ui_parent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Web.Html.Type_node vx_node_layout_from_node_ui_parent(Vx.Web.Html.Type_node node, Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent);
  }

  public class Class_node_layout_from_node_ui_parent : Vx.Core.Class_base, Func_node_layout_from_node_ui_parent {

    public override Vx.Ui.Html.Uihtml.Func_node_layout_from_node_ui_parent vx_new(params object[] vals) {
      Class_node_layout_from_node_ui_parent output = new Class_node_layout_from_node_ui_parent();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_node_layout_from_node_ui_parent vx_copy(params object[] vals) {
      Class_node_layout_from_node_ui_parent output = new Class_node_layout_from_node_ui_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "node-layout<-node-ui-parent", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "node", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_node_layout_from_node_ui_parent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_node_layout_from_node_ui_parent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_node node = Vx.Core.f_any_from_any(Vx.Web.Html.t_node, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Ui.Ui.Type_ui parent = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Ui.Html.Uihtml.f_node_layout_from_node_ui_parent(node, ui, parent);
      return output;
    }

    public Vx.Web.Html.Type_node vx_node_layout_from_node_ui_parent(Vx.Web.Html.Type_node node, Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent) {
      return Vx.Ui.Html.Uihtml.f_node_layout_from_node_ui_parent(node, ui, parent);
    }

  }

  public static Func_node_layout_from_node_ui_parent e_node_layout_from_node_ui_parent = new Vx.Ui.Html.Uihtml.Class_node_layout_from_node_ui_parent();
  public static Func_node_layout_from_node_ui_parent t_node_layout_from_node_ui_parent = new Vx.Ui.Html.Uihtml.Class_node_layout_from_node_ui_parent();

  public static Vx.Web.Html.Type_node f_node_layout_from_node_ui_parent(Vx.Web.Html.Type_node node, Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui parent) {
    Vx.Web.Html.Type_node output = Vx.Web.Html.e_node;
    output = Vx.Core.f_let(
      Vx.Web.Html.t_node,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string id = ui.uid();
        Vx.Core.Type_string parentid = parent.uid();
        Vx.Core.Type_string htmltext = Vx.Web.Html.f_string_from_node_indent(node, Vx.Core.vx_new_int(2));
        Vx.Core.Type_boolean htmldone = Vx.Web.Htmldoc.f_boolean_replace_from_id_parent_htmltext(id, parentid, htmltext);
        Vx.Core.Type_any output_1 = node;
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function node_from_ui_orig_parent
   * @param  {ui} ui
   * @param  {ui} orig
   * @param  {ui} parent
   * @return {node}
   * (func node<-ui-orig-parent)
   */
  public interface Func_node_from_ui_orig_parent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Web.Html.Type_node vx_node_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent);
  }

  public class Class_node_from_ui_orig_parent : Vx.Core.Class_base, Func_node_from_ui_orig_parent {

    public override Vx.Ui.Html.Uihtml.Func_node_from_ui_orig_parent vx_new(params object[] vals) {
      Class_node_from_ui_orig_parent output = new Class_node_from_ui_orig_parent();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_node_from_ui_orig_parent vx_copy(params object[] vals) {
      Class_node_from_ui_orig_parent output = new Class_node_from_ui_orig_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "node<-ui-orig-parent", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "node", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_node_from_ui_orig_parent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_node_from_ui_orig_parent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui orig = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Ui.Ui.Type_ui parent = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Ui.Html.Uihtml.f_node_from_ui_orig_parent(ui, orig, parent);
      return output;
    }

    public Vx.Web.Html.Type_node vx_node_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent) {
      return Vx.Ui.Html.Uihtml.f_node_from_ui_orig_parent(ui, orig, parent);
    }

  }

  public static Func_node_from_ui_orig_parent e_node_from_ui_orig_parent = new Vx.Ui.Html.Uihtml.Class_node_from_ui_orig_parent();
  public static Func_node_from_ui_orig_parent t_node_from_ui_orig_parent = new Vx.Ui.Html.Uihtml.Class_node_from_ui_orig_parent();

  public static Vx.Web.Html.Type_node f_node_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent) {
    Vx.Web.Html.Type_node output = Vx.Web.Html.e_node;
    output = Vx.Core.f_let(
      Vx.Web.Html.t_node,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_style style = ui.style();
        Vx.Ui.Ui.Type_layout layout = style.layout();
        Vx.Core.Type_any output_1 = Vx.Core.f_switch(
          Vx.Web.Html.t_node,
          layout,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
            Vx.Core.f_case_1(
              Vx.Ui.Ui.c_layout_image,
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Ui.Html.Uihtml.f_node_image_from_ui_orig_parent(ui, orig, parent);
              })
            ),
            Vx.Core.f_case_1(
              Vx.Ui.Ui.c_layout_label,
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Ui.Html.Uihtml.f_node_label_from_ui_orig_parent(ui, orig, parent);
              })
            ),
            Vx.Core.f_else(
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Ui.Html.Uihtml.f_node_default_from_ui_orig_parent(ui, orig, parent);
              })
            )
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_class_from_ui
   * Returns a class string given a ui.
   * @param  {ui} ui
   * @return {string}
   * (func string-class<-ui)
   */
  public interface Func_string_class_from_ui : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_string_class_from_ui(Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_string_class_from_ui : Vx.Core.Class_base, Func_string_class_from_ui {

    public override Vx.Ui.Html.Uihtml.Func_string_class_from_ui vx_new(params object[] vals) {
      Class_string_class_from_ui output = new Class_string_class_from_ui();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_string_class_from_ui vx_copy(params object[] vals) {
      Class_string_class_from_ui output = new Class_string_class_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "string-class<-ui", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_string_class_from_ui;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_class_from_ui;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Html.Uihtml.f_string_class_from_ui(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Html.Uihtml.f_string_class_from_ui(ui);
      return output;
    }

    public Vx.Core.Type_string vx_string_class_from_ui(Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Html.Uihtml.f_string_class_from_ui(ui);
    }

  }

  public static Func_string_class_from_ui e_string_class_from_ui = new Vx.Ui.Html.Uihtml.Class_string_class_from_ui();
  public static Func_string_class_from_ui t_string_class_from_ui = new Vx.Ui.Html.Uihtml.Class_string_class_from_ui();

  public static Vx.Core.Type_string f_string_class_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Web.Html.Type_stylelist htmlstyles = Vx.Ui.Html.Uihtml.f_stylelist_extra_from_ui(ui);
        Vx.Core.Type_any output_1 = Vx.Web.Html.f_string_from_stylelist(htmlstyles);
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_style_from_font
   * Returns a font css string from a logical font.
   * @param  {font} font
   * @return {string}
   * (func string-style<-font)
   */
  public interface Func_string_style_from_font : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_string_style_from_font(Vx.Ui.Ui.Type_font font);
  }

  public class Class_string_style_from_font : Vx.Core.Class_base, Func_string_style_from_font {

    public override Vx.Ui.Html.Uihtml.Func_string_style_from_font vx_new(params object[] vals) {
      Class_string_style_from_font output = new Class_string_style_from_font();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_string_style_from_font vx_copy(params object[] vals) {
      Class_string_style_from_font output = new Class_string_style_from_font();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "string-style<-font", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_string_style_from_font;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_style_from_font;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_font inputval = (Vx.Ui.Ui.Type_font)value;
      Vx.Core.Type_any outputval = Vx.Ui.Html.Uihtml.f_string_style_from_font(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_font font = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_font, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Html.Uihtml.f_string_style_from_font(font);
      return output;
    }

    public Vx.Core.Type_string vx_string_style_from_font(Vx.Ui.Ui.Type_font font) {
      return Vx.Ui.Html.Uihtml.f_string_style_from_font(font);
    }

  }

  public static Func_string_style_from_font e_string_style_from_font = new Vx.Ui.Html.Uihtml.Class_string_style_from_font();
  public static Func_string_style_from_font t_string_style_from_font = new Vx.Ui.Html.Uihtml.Class_string_style_from_font();

  public static Vx.Core.Type_string f_string_style_from_font(Vx.Ui.Ui.Type_font font) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_fontface face = font.fontface();
        Vx.Core.Type_int size = font.fontsize();
        Vx.Core.Type_string name = face.name();
        Vx.Core.Type_string ssize = Vx.Core.f_if_2(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
              Vx.Core.f_then(
                Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                  return Vx.Core.f_gt(size, Vx.Core.vx_new_int(0));
                }),
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Core.f_new(
                    Vx.Core.t_string,
                    Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.f_divide(size, Vx.Core.vx_new_int(100)),
                        Vx.Core.vx_new_string("em"),
                        Vx.Core.vx_new_string(" ")
                    )
                  );
                })
              )
          )
        );
        Vx.Core.Type_any output_1 = Vx.Core.f_if_2(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_notempty(name);
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Core.f_new(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                      ssize,
                      Vx.Core.c_quote,
                      name,
                      Vx.Core.c_quote
                  )
                );
              })
            )
          )
        );
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function string_style_from_image
   * Returns an image css string from a logical image.
   * @param  {image} image
   * @return {string}
   * (func string-style<-image)
   */
  public interface Func_string_style_from_image : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_string_style_from_image(Vx.Ui.Ui.Type_image image);
  }

  public class Class_string_style_from_image : Vx.Core.Class_base, Func_string_style_from_image {

    public override Vx.Ui.Html.Uihtml.Func_string_style_from_image vx_new(params object[] vals) {
      Class_string_style_from_image output = new Class_string_style_from_image();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_string_style_from_image vx_copy(params object[] vals) {
      Class_string_style_from_image output = new Class_string_style_from_image();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "string-style<-image", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_string_style_from_image;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_style_from_image;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_image inputval = (Vx.Ui.Ui.Type_image)value;
      Vx.Core.Type_any outputval = Vx.Ui.Html.Uihtml.f_string_style_from_image(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_image image = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_image, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Html.Uihtml.f_string_style_from_image(image);
      return output;
    }

    public Vx.Core.Type_string vx_string_style_from_image(Vx.Ui.Ui.Type_image image) {
      return Vx.Ui.Html.Uihtml.f_string_style_from_image(image);
    }

  }

  public static Func_string_style_from_image e_string_style_from_image = new Vx.Ui.Html.Uihtml.Class_string_style_from_image();
  public static Func_string_style_from_image t_string_style_from_image = new Vx.Ui.Html.Uihtml.Class_string_style_from_image();

  public static Vx.Core.Type_string f_string_style_from_image(Vx.Ui.Ui.Type_image image) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_if_2(
      Vx.Core.t_string,
      Vx.Core.vx_new(Vx.Core.t_thenelselist,
        Vx.Core.f_then(
          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
            return Vx.Core.f_notempty_1(image);
          }),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.f_let(
              Vx.Core.t_string,
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                Vx.Data.File.Type_file file = image.file();
                Vx.Core.Type_string url = Vx.Data.File.f_pathfull_from_file(file);
                Vx.Core.Type_any output_1 = Vx.Core.f_if_2(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                    Vx.Core.f_then(
                      Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                        return Vx.Core.f_notempty(url);
                      }),
                      Vx.Core.t_any_from_func.vx_fn_new(() => {
                        return Vx.Core.f_new(
                          Vx.Core.t_string,
                          Vx.Core.vx_new(Vx.Core.t_anylist,
                              Vx.Core.vx_new_string("url("),
                              url,
                              Vx.Core.vx_new_string(")")
                          )
                        );
                      })
                    )
                  )
                );
                return output_1;
              })
            );
          })
        )
      )
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
  public interface Func_string_stylename_from_name_styletype : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_string_stylename_from_name_styletype(Vx.Core.Type_string name, Vx.Ui.Ui.Type_styletype styletype);
  }

  public class Class_string_stylename_from_name_styletype : Vx.Core.Class_base, Func_string_stylename_from_name_styletype {

    public override Vx.Ui.Html.Uihtml.Func_string_stylename_from_name_styletype vx_new(params object[] vals) {
      Class_string_stylename_from_name_styletype output = new Class_string_stylename_from_name_styletype();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_string_stylename_from_name_styletype vx_copy(params object[] vals) {
      Class_string_stylename_from_name_styletype output = new Class_string_stylename_from_name_styletype();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "string-stylename<-name-styletype", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_string_stylename_from_name_styletype;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_string_stylename_from_name_styletype;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string name = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_styletype styletype = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_styletype, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Ui.Html.Uihtml.f_string_stylename_from_name_styletype(name, styletype);
      return output;
    }

    public Vx.Core.Type_string vx_string_stylename_from_name_styletype(Vx.Core.Type_string name, Vx.Ui.Ui.Type_styletype styletype) {
      return Vx.Ui.Html.Uihtml.f_string_stylename_from_name_styletype(name, styletype);
    }

  }

  public static Func_string_stylename_from_name_styletype e_string_stylename_from_name_styletype = new Vx.Ui.Html.Uihtml.Class_string_stylename_from_name_styletype();
  public static Func_string_stylename_from_name_styletype t_string_stylename_from_name_styletype = new Vx.Ui.Html.Uihtml.Class_string_stylename_from_name_styletype();

  public static Vx.Core.Type_string f_string_stylename_from_name_styletype(Vx.Core.Type_string name, Vx.Ui.Ui.Type_styletype styletype) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_if_2(
      Vx.Core.t_string,
      Vx.Core.vx_new(Vx.Core.t_thenelselist,
        Vx.Core.f_then(
          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
            return Vx.Core.f_eq(Vx.Core.vx_new_string(""), name);
          }),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.vx_new_string("");
          })
        ),
        Vx.Core.f_then(
          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
            return Vx.Core.f_eqeq(
              styletype,
              Vx.Ui.Ui.c_styletype_shared
            );
          }),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.f_new(
              Vx.Core.t_string,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                  Vx.Core.vx_new_string("."),
                  name
              )
            );
          })
        ),
        Vx.Core.f_then(
          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
            return Vx.Core.f_eqeq(
              styletype,
              Vx.Ui.Ui.c_styletype_system
            );
          }),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.f_new(
              Vx.Core.t_string,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                  Vx.Core.vx_new_string("#"),
                  name
              )
            );
          })
        ),
        Vx.Core.f_else(
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return name;
          })
        )
      )
    );
    return output;
  }

  /**
   * @function style_from_fontface
   * Returns an html style from a font
   * @param  {fontface} fontface
   * @return {style}
   * (func style<-fontface)
   */
  public interface Func_style_from_fontface : Vx.Core.Func_any_from_any {
    public Vx.Web.Html.Type_style vx_style_from_fontface(Vx.Ui.Ui.Type_fontface fontface);
  }

  public class Class_style_from_fontface : Vx.Core.Class_base, Func_style_from_fontface {

    public override Vx.Ui.Html.Uihtml.Func_style_from_fontface vx_new(params object[] vals) {
      Class_style_from_fontface output = new Class_style_from_fontface();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_style_from_fontface vx_copy(params object[] vals) {
      Class_style_from_fontface output = new Class_style_from_fontface();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "style<-fontface", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "style", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_style_from_fontface;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_style_from_fontface;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_fontface inputval = (Vx.Ui.Ui.Type_fontface)value;
      Vx.Core.Type_any outputval = Vx.Ui.Html.Uihtml.f_style_from_fontface(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_fontface fontface = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_fontface, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Html.Uihtml.f_style_from_fontface(fontface);
      return output;
    }

    public Vx.Web.Html.Type_style vx_style_from_fontface(Vx.Ui.Ui.Type_fontface fontface) {
      return Vx.Ui.Html.Uihtml.f_style_from_fontface(fontface);
    }

  }

  public static Func_style_from_fontface e_style_from_fontface = new Vx.Ui.Html.Uihtml.Class_style_from_fontface();
  public static Func_style_from_fontface t_style_from_fontface = new Vx.Ui.Html.Uihtml.Class_style_from_fontface();

  public static Vx.Web.Html.Type_style f_style_from_fontface(Vx.Ui.Ui.Type_fontface fontface) {
    Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
    output = Vx.Core.f_let(
      Vx.Web.Html.t_style,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string name = fontface.name();
        Vx.Core.Type_string weight = fontface.weight();
        Vx.Core.Type_string unicode = fontface.unicode();
        Vx.Data.File.Type_filelist files = fontface.filelist();
        Vx.Core.Type_stringlist urls = Vx.Core.f_list_from_list_1(
          Vx.Core.t_stringlist,
          files,
          Vx.Core.t_any_from_any.vx_fn_new((file_any) => {
            Vx.Data.File.Type_file file = Vx.Core.f_any_from_any(Vx.Data.File.t_file, file_any);
            Vx.Core.Type_any output_1 = 
                Vx.Core.f_new(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string("url("),
                    Vx.Data.File.f_pathfull_from_file(file),
                    Vx.Core.vx_new_string(")")
                  )
                );
            return output_1;
          })
        );
        Vx.Core.Type_string fontfamily = Vx.Core.f_new(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_anylist,
              Vx.Core.c_quote,
              name,
              Vx.Core.c_quote
          )
        );
        Vx.Core.Type_string srcurls = Vx.Type.f_string_from_stringlist_join(urls, Vx.Core.vx_new_string(","));
        Vx.Core.Type_string src = Vx.Core.f_new(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_anylist,
              srcurls,
              Vx.Core.vx_new_string(";")
          )
        );
        Vx.Web.Html.Type_propmap propmap = Vx.Core.f_new(
          Vx.Web.Html.t_propmap,
          Vx.Core.vx_new(Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":font-family"),
              fontfamily,
              Vx.Core.vx_new_string(":font-style"),
              Vx.Core.vx_new_string("normal"),
              Vx.Core.vx_new_string(":font-weight"),
              weight,
              Vx.Core.vx_new_string(":font-display"),
              Vx.Core.vx_new_string("swap"),
              Vx.Core.vx_new_string(":src"),
              src,
              Vx.Core.vx_new_string(":unicode-range"),
              unicode
          )
        );
        Vx.Core.Type_any output_2 = Vx.Core.f_new(
          Vx.Web.Html.t_style,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":name"),
            Vx.Core.vx_new_string("@font-face"),
            Vx.Core.vx_new_string(":props"),
            propmap
          )
        );
        return output_2;
      })
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
  public interface Func_style_from_style : Vx.Core.Func_any_from_any {
    public Vx.Web.Html.Type_style vx_style_from_style(Vx.Ui.Ui.Type_style uistyle);
  }

  public class Class_style_from_style : Vx.Core.Class_base, Func_style_from_style {

    public override Vx.Ui.Html.Uihtml.Func_style_from_style vx_new(params object[] vals) {
      Class_style_from_style output = new Class_style_from_style();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_style_from_style vx_copy(params object[] vals) {
      Class_style_from_style output = new Class_style_from_style();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "style<-style", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "style", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_style_from_style;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_style_from_style;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_style inputval = (Vx.Ui.Ui.Type_style)value;
      Vx.Core.Type_any outputval = Vx.Ui.Html.Uihtml.f_style_from_style(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_style uistyle = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_style, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Html.Uihtml.f_style_from_style(uistyle);
      return output;
    }

    public Vx.Web.Html.Type_style vx_style_from_style(Vx.Ui.Ui.Type_style uistyle) {
      return Vx.Ui.Html.Uihtml.f_style_from_style(uistyle);
    }

  }

  public static Func_style_from_style e_style_from_style = new Vx.Ui.Html.Uihtml.Class_style_from_style();
  public static Func_style_from_style t_style_from_style = new Vx.Ui.Html.Uihtml.Class_style_from_style();

  public static Vx.Web.Html.Type_style f_style_from_style(Vx.Ui.Ui.Type_style uistyle) {
    Vx.Web.Html.Type_style output = Vx.Web.Html.e_style;
    output = Vx.Core.f_if_2(
      Vx.Web.Html.t_style,
      Vx.Core.vx_new(Vx.Core.t_thenelselist,
        Vx.Core.f_then(
          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
            return Vx.Core.f_is_empty_1(uistyle);
          }),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.f_empty(
              Vx.Web.Html.t_style
            );
          })
        ),
        Vx.Core.f_else(
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.f_let(
              Vx.Web.Html.t_style,
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                Vx.Ui.Ui.Type_layout layout = uistyle.layout();
                Vx.Core.Type_string name = uistyle.name();
                Vx.Ui.Ui.Type_flip flip = uistyle.flip();
                Vx.Ui.Ui.Type_font font = uistyle.font();
                Vx.Ui.Ui.Type_pin pin = uistyle.pin();
                Vx.Ui.Ui.Type_point pointorigin = uistyle.pointorigin();
                Vx.Ui.Ui.Type_point pointpos = uistyle.pointpos();
                Vx.Ui.Ui.Type_point pointsize = uistyle.pointsize();
                Vx.Ui.Ui.Type_point pointrotate = uistyle.pointrotate();
                Vx.Ui.Ui.Type_styletype styletype = uistyle.type();
                Vx.Core.Type_string color_bkg = uistyle.color_bkg();
                Vx.Core.Type_string color_bkghover = uistyle.color_bkghover();
                Vx.Core.Type_string color_border = uistyle.color_border();
                Vx.Core.Type_string color_font = uistyle.color_font();
                Vx.Ui.Ui.Type_cursor cursor = uistyle.cursor();
                Vx.Core.Type_boolean hidden = uistyle.hidden();
                Vx.Ui.Ui.Type_align align = uistyle.align();
                Vx.Core.Type_boolean scroll_x = uistyle.scroll_x();
                Vx.Core.Type_boolean scroll_y = uistyle.scroll_y();
                Vx.Core.Type_int posx = pointpos.x();
                Vx.Core.Type_int posy = pointpos.y();
                Vx.Ui.Ui.Type_pointtype postype = pointpos.pointtype();
                Vx.Core.Type_int sizex = pointsize.x();
                Vx.Core.Type_int sizey = pointsize.y();
                Vx.Ui.Ui.Type_pointtype sizetype = pointsize.pointtype();
                Vx.Core.Type_string stylename = Vx.Ui.Html.Uihtml.f_string_stylename_from_name_styletype(name, styletype);
                Vx.Core.Type_string bkgcolor = Vx.Core.f_if_2(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_notempty(color_bkg);
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.f_new(
                            Vx.Core.t_string,
                            Vx.Core.vx_new(Vx.Core.t_anylist,
                                Vx.Core.vx_new_string("#"),
                                color_bkg
                            )
                          );
                        })
                      )
                  )
                );
                Vx.Core.Type_string borderwidth = Vx.Core.f_if_2(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_notempty(color_border);
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("thin");
                        })
                      )
                  )
                );
                Vx.Core.Type_string bordercolor = Vx.Core.f_if_2(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_notempty(color_border);
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.f_new(
                            Vx.Core.t_string,
                            Vx.Core.vx_new(Vx.Core.t_anylist,
                                Vx.Core.vx_new_string("#"),
                                color_border
                            )
                          );
                        })
                      )
                  )
                );
                Vx.Core.Type_string borderstyle = Vx.Core.f_if_2(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_notempty(color_border);
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.f_new(
                            Vx.Core.t_string,
                            Vx.Core.vx_new(Vx.Core.t_anylist,
                                Vx.Core.vx_new_string("solid")
                            )
                          );
                        })
                      )
                  )
                );
                Vx.Core.Type_string fontcolor = Vx.Core.f_if_2(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_notempty(color_font);
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.f_new(
                            Vx.Core.t_string,
                            Vx.Core.vx_new(Vx.Core.t_anylist,
                                Vx.Core.vx_new_string("#"),
                                color_font
                            )
                          );
                        })
                      )
                  )
                );
                Vx.Core.Type_string position = Vx.Core.f_if_2(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_or_1(
                            Vx.Core.vx_new(Vx.Core.t_booleanlist,
                                Vx.Core.f_eqeq(
                                  layout,
                                  Vx.Ui.Ui.c_layout_app
                                ),
                                Vx.Core.f_eqeq(
                                  layout,
                                  Vx.Ui.Ui.c_layout_background
                                ),
                                Vx.Core.f_eqeq(
                                  layout,
                                  Vx.Ui.Ui.c_layout_main
                                ),
                                Vx.Core.f_eqeq(
                                  layout,
                                  Vx.Ui.Ui.c_layout_navbar
                                ),
                                Vx.Core.f_eqeq(
                                  layout,
                                  Vx.Ui.Ui.c_layout_parallax
                                ),
                                Vx.Core.f_eqeq(
                                  layout,
                                  Vx.Ui.Ui.c_layout_statusbar
                                ),
                                Vx.Core.f_eqeq(
                                  layout,
                                  Vx.Ui.Ui.c_layout_titlebar
                                )
                            )
                          );
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("fixed");
                        })
                      ),
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_eqeq(
                            postype,
                            Vx.Ui.Ui.c_pointtype_relative
                          );
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("relative");
                        })
                      ),
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_eqeq(
                            postype,
                            Vx.Ui.Ui.c_pointtype_absolute
                          );
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("absolute");
                        })
                      ),
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_notempty_1(pointpos);
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("absolute");
                        })
                      ),
                      Vx.Core.f_else(
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("");
                        })
                      )
                  )
                );
                Vx.Core.Type_string top = Vx.Core.f_if_2(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_eqeq(
                            pin,
                            Vx.Ui.Ui.c_pin_expand
                          );
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.f_new(
                            Vx.Core.t_string,
                            Vx.Core.vx_new(Vx.Core.t_anylist,
                                posy,
                                Vx.Core.vx_new_string("mm")
                            )
                          );
                        })
                      ),
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_eqeq(Vx.Core.vx_new_int(0), posy);
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("");
                        })
                      ),
                      Vx.Core.f_else(
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.f_new(
                            Vx.Core.t_string,
                            Vx.Core.vx_new(Vx.Core.t_anylist,
                                posy,
                                Vx.Core.vx_new_string("mm")
                            )
                          );
                        })
                      )
                  )
                );
                Vx.Core.Type_string bottom = Vx.Core.f_if_2(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_eqeq(
                            pin,
                            Vx.Ui.Ui.c_pin_expand
                          );
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("");
                        })
                      ),
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_eqeq(
                            pin,
                            Vx.Ui.Ui.c_pin_bottom
                          );
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("0mm");
                        })
                      ),
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_or(
                            Vx.Core.f_eqeq(
                              pin,
                              Vx.Ui.Ui.c_pin_left
                            ),
                            Vx.Core.f_eqeq(
                              pin,
                              Vx.Ui.Ui.c_pin_center_v
                            )
                          );
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.f_new(
                            Vx.Core.t_string,
                            Vx.Core.vx_new(Vx.Core.t_anylist,
                                sizey,
                                Vx.Core.vx_new_string("mm")
                            )
                          );
                        })
                      )
                  )
                );
                Vx.Core.Type_string left = Vx.Core.f_if_2(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_eqeq(
                            pin,
                            Vx.Ui.Ui.c_pin_expand
                          );
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("");
                        })
                      ),
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_eqeq(
                            pin,
                            Vx.Ui.Ui.c_pin_bottom
                          );
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.f_new(
                            Vx.Core.t_string,
                            Vx.Core.vx_new(Vx.Core.t_anylist,
                                posx,
                                Vx.Core.vx_new_string("mm")
                            )
                          );
                        })
                      ),
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_eqeq(Vx.Core.vx_new_int(0), posx);
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("");
                        })
                      ),
                      Vx.Core.f_else(
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.f_new(
                            Vx.Core.t_string,
                            Vx.Core.vx_new(Vx.Core.t_anylist,
                                posx,
                                Vx.Core.vx_new_string("mm")
                            )
                          );
                        })
                      )
                  )
                );
                Vx.Core.Type_string right = Vx.Core.f_if_2(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_eqeq(
                            pin,
                            Vx.Ui.Ui.c_pin_expand
                          );
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("");
                        })
                      ),
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_or_1(
                            Vx.Core.vx_new(Vx.Core.t_booleanlist,
                                Vx.Core.f_eqeq(
                                  pin,
                                  Vx.Ui.Ui.c_pin_top
                                ),
                                Vx.Core.f_eqeq(
                                  pin,
                                  Vx.Ui.Ui.c_pin_bottom
                                ),
                                Vx.Core.f_eqeq(
                                  pin,
                                  Vx.Ui.Ui.c_pin_center_v
                                )
                            )
                          );
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.f_new(
                            Vx.Core.t_string,
                            Vx.Core.vx_new(Vx.Core.t_anylist,
                                sizex,
                                Vx.Core.vx_new_string("mm")
                            )
                          );
                        })
                      )
                  )
                );
                Vx.Core.Type_string height = Vx.Core.f_if_2(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_eqeq(
                            pin,
                            Vx.Ui.Ui.c_pin_expand
                          );
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("100%");
                        })
                      ),
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_or_1(
                            Vx.Core.vx_new(Vx.Core.t_booleanlist,
                                Vx.Core.f_eqeq(
                                  pin,
                                  Vx.Ui.Ui.c_pin_left
                                ),
                                Vx.Core.f_eqeq(
                                  pin,
                                  Vx.Ui.Ui.c_pin_right
                                ),
                                Vx.Core.f_eqeq(
                                  pin,
                                  Vx.Ui.Ui.c_pin_center_v
                                )
                            )
                          );
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("");
                        })
                      ),
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_eqeq(
                            sizetype,
                            Vx.Ui.Ui.c_pointtype_percent
                          );
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.f_new(
                            Vx.Core.t_string,
                            Vx.Core.vx_new(Vx.Core.t_anylist,
                                sizey,
                                Vx.Core.vx_new_string("%")
                            )
                          );
                        })
                      ),
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_eqeq(Vx.Core.vx_new_int(0), sizey);
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("");
                        })
                      ),
                      Vx.Core.f_else(
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.f_new(
                            Vx.Core.t_string,
                            Vx.Core.vx_new(Vx.Core.t_anylist,
                                sizey,
                                Vx.Core.vx_new_string("mm")
                            )
                          );
                        })
                      )
                  )
                );
                Vx.Core.Type_string width = Vx.Core.f_if_2(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_eqeq(
                            pin,
                            Vx.Ui.Ui.c_pin_expand
                          );
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("100%");
                        })
                      ),
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_or_1(
                            Vx.Core.vx_new(Vx.Core.t_booleanlist,
                                Vx.Core.f_eqeq(
                                  pin,
                                  Vx.Ui.Ui.c_pin_top
                                ),
                                Vx.Core.f_eqeq(
                                  pin,
                                  Vx.Ui.Ui.c_pin_bottom
                                ),
                                Vx.Core.f_eqeq(
                                  pin,
                                  Vx.Ui.Ui.c_pin_center_v
                                )
                            )
                          );
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("");
                        })
                      ),
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_eqeq(
                            sizetype,
                            Vx.Ui.Ui.c_pointtype_percent
                          );
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.f_new(
                            Vx.Core.t_string,
                            Vx.Core.vx_new(Vx.Core.t_anylist,
                                sizex,
                                Vx.Core.vx_new_string("%")
                            )
                          );
                        })
                      ),
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_eqeq(Vx.Core.vx_new_int(0), sizex);
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("");
                        })
                      ),
                      Vx.Core.f_else(
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.f_new(
                            Vx.Core.t_string,
                            Vx.Core.vx_new(Vx.Core.t_anylist,
                                sizex,
                                Vx.Core.vx_new_string("mm")
                            )
                          );
                        })
                      )
                  )
                );
                Vx.Core.Type_string display = Vx.Core.f_if_2(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return hidden;
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("none");
                        })
                      ),
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_eqeq(
                            layout,
                            Vx.Ui.Ui.c_layout_flow_item
                          );
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("inline-block");
                        })
                      )
                  )
                );
                Vx.Core.Type_string sfont = Vx.Ui.Html.Uihtml.f_string_style_from_font(font);
                Vx.Core.Type_string gap = Vx.Core.f_if_2(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_or(
                            Vx.Core.f_eqeq(
                              layout,
                              Vx.Ui.Ui.c_layout_flow_columns
                            ),
                            Vx.Core.f_eqeq(
                              layout,
                              Vx.Ui.Ui.c_layout_flow_rows
                            )
                          );
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("1mm");
                        })
                      )
                  )
                );
                Vx.Core.Type_string overflowx = Vx.Core.f_if_2(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return scroll_x;
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("auto");
                        })
                      )
                  )
                );
                Vx.Core.Type_string overflowy = Vx.Core.f_if_2(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return scroll_y;
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("auto");
                        })
                      )
                  )
                );
                Vx.Core.Type_string hoverbkgrdcolor = Vx.Core.f_if_2(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_ne(Vx.Core.vx_new_string(""), color_bkghover);
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.f_new(
                            Vx.Core.t_string,
                            Vx.Core.vx_new(Vx.Core.t_anylist,
                                Vx.Core.vx_new_string("#"),
                                color_bkghover
                            )
                          );
                        })
                      )
                  )
                );
                Vx.Core.Type_string scursor = Vx.Core.f_if_2(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_eqeq(
                            cursor,
                            Vx.Ui.Ui.t_cursor_pointer
                          );
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("pointer");
                        })
                      )
                  )
                );
                Vx.Core.Type_string textalign = Vx.Core.f_if_2(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_eqeq(
                            align,
                            Vx.Ui.Ui.c_align_left
                          );
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("left");
                        })
                      ),
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_eqeq(
                            align,
                            Vx.Ui.Ui.c_align_center
                          );
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("center");
                        })
                      ),
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_eqeq(
                            align,
                            Vx.Ui.Ui.c_align_right
                          );
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("right");
                        })
                      )
                  )
                );
                Vx.Core.Type_string transform_rotate = Vx.Core.f_if_2(
                  Vx.Core.t_string,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_is_empty_1(pointrotate);
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("");
                        })
                      ),
                      Vx.Core.f_else(
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.f_new(
                            Vx.Core.t_string,
                            Vx.Core.vx_new(Vx.Core.t_anylist,
                                Vx.Core.vx_new_string("rotate("),
                                pointrotate.x(),
                                Vx.Core.vx_new_string("deg)")
                            )
                          );
                        })
                      )
                  )
                );
                Vx.Core.Type_string transform_scale = Vx.Core.f_switch(
                  Vx.Core.t_string,
                  flip,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                      Vx.Core.f_case_1(
                        Vx.Ui.Ui.c_flip_x,
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("scale(-1, 1)");
                        })
                      ),
                      Vx.Core.f_case_1(
                        Vx.Ui.Ui.c_flip_y,
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("scale( 1,-1)");
                        })
                      ),
                      Vx.Core.f_case_1(
                        Vx.Ui.Ui.c_flip_xy,
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("scale(-1,-1)");
                        })
                      )
                  )
                );
                Vx.Core.Type_stringlist transforms = Vx.Core.f_new(
                  Vx.Core.t_stringlist,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                      transform_rotate,
                      transform_scale
                  )
                );
                Vx.Core.Type_string transform = Vx.Type.f_string_from_stringlist_join(transforms, Vx.Core.vx_new_string(" "));
                Vx.Core.Type_string transformorigin = Vx.Core.f_switch(
                  Vx.Core.t_string,
                  pointorigin,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                      Vx.Core.f_case_1(
                        Vx.Ui.Ui.c_point_center,
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("center");
                        })
                      ),
                      Vx.Core.f_case_1(
                        Vx.Ui.Ui.c_point_lefttop,
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("left top");
                        })
                      ),
                      Vx.Core.f_case_1(
                        Vx.Ui.Ui.c_point_rightbottom,
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.vx_new_string("right bottom");
                        })
                      ),
                      Vx.Core.f_else(
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.f_if_2(
                            Vx.Core.t_string,
                            Vx.Core.vx_new(Vx.Core.t_thenelselist,
                                Vx.Core.f_then(
                                  Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                                    return Vx.Core.f_is_empty_1(pointrotate);
                                  }),
                                  Vx.Core.t_any_from_func.vx_fn_new(() => {
                                    return Vx.Core.vx_new_string("");
                                  })
                                ),
                                Vx.Core.f_then(
                                  Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                                    return Vx.Core.f_eqeq(
                                      layout,
                                      Vx.Ui.Ui.c_layout_label
                                    );
                                  }),
                                  Vx.Core.t_any_from_func.vx_fn_new(() => {
                                    return Vx.Core.vx_new_string("left top");
                                  })
                                )
                            )
                          );
                        })
                      )
                  )
                );
                Vx.Web.Html.Type_propmap props = Vx.Core.f_new(
                  Vx.Web.Html.t_propmap,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                      Vx.Core.vx_new_string(":background-color"),
                      bkgcolor,
                      Vx.Core.vx_new_string(":border-color"),
                      bordercolor,
                      Vx.Core.vx_new_string(":border-style"),
                      borderstyle,
                      Vx.Core.vx_new_string(":border-width"),
                      borderwidth,
                      Vx.Core.vx_new_string(":color"),
                      fontcolor,
                      Vx.Core.vx_new_string(":cursor"),
                      scursor,
                      Vx.Core.vx_new_string(":display"),
                      display,
                      Vx.Core.vx_new_string(":font"),
                      sfont,
                      Vx.Core.vx_new_string(":gap"),
                      gap,
                      Vx.Core.vx_new_string(":position"),
                      position,
                      Vx.Core.vx_new_string(":top"),
                      top,
                      Vx.Core.vx_new_string(":bottom"),
                      bottom,
                      Vx.Core.vx_new_string(":left"),
                      left,
                      Vx.Core.vx_new_string(":right"),
                      right,
                      Vx.Core.vx_new_string(":height"),
                      height,
                      Vx.Core.vx_new_string(":width"),
                      width,
                      Vx.Core.vx_new_string(":overflow-x"),
                      overflowx,
                      Vx.Core.vx_new_string(":overflow-y"),
                      overflowy,
                      Vx.Core.vx_new_string(":text-align"),
                      textalign,
                      Vx.Core.vx_new_string(":transform"),
                      transform,
                      Vx.Core.vx_new_string(":transform-origin"),
                      transformorigin
                  )
                );
                Vx.Web.Html.Type_propmap hoverprops = Vx.Core.f_new(
                  Vx.Web.Html.t_propmap,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                      Vx.Core.vx_new_string(":background-color"),
                      hoverbkgrdcolor
                  )
                );
                Vx.Web.Html.Type_stylelist substylelist = Vx.Core.f_if_2(
                  Vx.Web.Html.t_stylelist,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_notempty_1(hoverprops);
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.f_new(
                            Vx.Web.Html.t_stylelist,
                            Vx.Core.vx_new(Vx.Core.t_anylist,
                                Vx.Core.f_new(
                                  Vx.Web.Html.t_style,
                                  Vx.Core.vx_new(Vx.Core.t_anylist,
                                    Vx.Core.vx_new_string(":name"),
                                    Vx.Core.vx_new_string("&:hover"),
                                    Vx.Core.vx_new_string(":props"),
                                    hoverprops
                                  )
                                )
                            )
                          );
                        })
                      )
                  )
                );
                Vx.Core.Type_any output_1 = Vx.Core.f_new(
                  Vx.Web.Html.t_style,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":name"),
                    stylename,
                    Vx.Core.vx_new_string(":props"),
                    props,
                    Vx.Core.vx_new_string(":stylelist"),
                    substylelist
                  )
                );
                return output_1;
              })
            );
          })
        )
      )
    );
    return output;
  }

  /**
   * @function stylelist_extra_from_ui
   * Returns a stylelist from a ui including style-hidden and style-selected
   * @param  {ui} ui
   * @return {stylelist}
   * (func stylelist-extra<-ui)
   */
  public interface Func_stylelist_extra_from_ui : Vx.Core.Func_any_from_any {
    public Vx.Web.Html.Type_stylelist vx_stylelist_extra_from_ui(Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_stylelist_extra_from_ui : Vx.Core.Class_base, Func_stylelist_extra_from_ui {

    public override Vx.Ui.Html.Uihtml.Func_stylelist_extra_from_ui vx_new(params object[] vals) {
      Class_stylelist_extra_from_ui output = new Class_stylelist_extra_from_ui();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_stylelist_extra_from_ui vx_copy(params object[] vals) {
      Class_stylelist_extra_from_ui output = new Class_stylelist_extra_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylelist-extra<-ui", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "stylelist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_style), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_stylelist_extra_from_ui;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_stylelist_extra_from_ui;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Ui.Html.Uihtml.f_stylelist_extra_from_ui(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Html.Uihtml.f_stylelist_extra_from_ui(ui);
      return output;
    }

    public Vx.Web.Html.Type_stylelist vx_stylelist_extra_from_ui(Vx.Ui.Ui.Type_ui ui) {
      return Vx.Ui.Html.Uihtml.f_stylelist_extra_from_ui(ui);
    }

  }

  public static Func_stylelist_extra_from_ui e_stylelist_extra_from_ui = new Vx.Ui.Html.Uihtml.Class_stylelist_extra_from_ui();
  public static Func_stylelist_extra_from_ui t_stylelist_extra_from_ui = new Vx.Ui.Html.Uihtml.Class_stylelist_extra_from_ui();

  public static Vx.Web.Html.Type_stylelist f_stylelist_extra_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Web.Html.Type_stylelist output = Vx.Web.Html.e_stylelist;
    output = Vx.Core.f_let(
      Vx.Web.Html.t_stylelist,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_stylelist uistyles = ui.stylelist();
        Vx.Core.Type_boolean selected = ui.selected();
        Vx.Core.Type_boolean hidden = ui.hidden();
        Vx.Web.Html.Type_stylelist styles1 = Vx.Ui.Html.Uihtml.f_stylelist_from_stylelist(uistyles);
        Vx.Web.Html.Type_stylelist styles2 = Vx.Core.f_if_2(
          Vx.Web.Html.t_stylelist,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
              Vx.Core.f_then(
                Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                  return hidden;
                }),
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Core.f_copy(
                    styles1,
                    Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Ui.Html.Uihtml.c_style_hidden
                    )
                  );
                })
              ),
              Vx.Core.f_then(
                Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                  return selected;
                }),
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Core.f_copy(
                    styles1,
                    Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Ui.Html.Uihtml.c_style_selected
                    )
                  );
                })
              ),
              Vx.Core.f_else(
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return styles1;
                })
              )
          )
        );
        Vx.Core.Type_any output_1 = styles2;
        return output_1;
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
  public interface Func_stylelist_reset : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Web.Html.Type_stylelist vx_stylelist_reset();
  }

  public class Class_stylelist_reset : Vx.Core.Class_base, Func_stylelist_reset {

    public override Vx.Ui.Html.Uihtml.Func_stylelist_reset vx_new(params object[] vals) {
      Class_stylelist_reset output = new Class_stylelist_reset();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_stylelist_reset vx_copy(params object[] vals) {
      Class_stylelist_reset output = new Class_stylelist_reset();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylelist-reset", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "stylelist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_style), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_stylelist_reset;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_stylelist_reset;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      output = Vx.Ui.Html.Uihtml.f_stylelist_reset();
      return output;
    }

    public Vx.Web.Html.Type_stylelist vx_stylelist_reset() {
      return Vx.Ui.Html.Uihtml.f_stylelist_reset();
    }

  }

  public static Func_stylelist_reset e_stylelist_reset = new Vx.Ui.Html.Uihtml.Class_stylelist_reset();
  public static Func_stylelist_reset t_stylelist_reset = new Vx.Ui.Html.Uihtml.Class_stylelist_reset();

  public static Vx.Web.Html.Type_stylelist f_stylelist_reset() {
    Vx.Web.Html.Type_stylelist output = Vx.Web.Html.e_stylelist;
    output = Vx.Core.f_new(
      Vx.Web.Html.t_stylelist,
      Vx.Core.vx_new(Vx.Core.t_anylist,
        Vx.Core.f_new(
          Vx.Web.Html.t_style,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":name"),
            Vx.Core.vx_new_string("html"),
            Vx.Core.vx_new_string(":props"),
            Vx.Core.f_new(
              Vx.Web.Html.t_propmap,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":border"),
                Vx.Core.vx_new_string("0mm"),
                Vx.Core.vx_new_string(":margin"),
                Vx.Core.vx_new_string("0mm"),
                Vx.Core.vx_new_string(":padding"),
                Vx.Core.vx_new_string("0mm")
              )
            )
          )
        ),
        Vx.Core.f_new(
          Vx.Web.Html.t_style,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":name"),
            Vx.Core.vx_new_string("body"),
            Vx.Core.vx_new_string(":props"),
            Vx.Core.f_new(
              Vx.Web.Html.t_propmap,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":border"),
                Vx.Core.vx_new_string("0mm"),
                Vx.Core.vx_new_string(":margin"),
                Vx.Core.vx_new_string("0mm"),
                Vx.Core.vx_new_string(":padding"),
                Vx.Core.vx_new_string("0mm")
              )
            )
          )
        ),
        Vx.Core.f_new(
          Vx.Web.Html.t_style,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":name"),
            Vx.Core.vx_new_string("div"),
            Vx.Core.vx_new_string(":props"),
            Vx.Core.f_new(
              Vx.Web.Html.t_propmap,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":border"),
                Vx.Core.vx_new_string("0mm"),
                Vx.Core.vx_new_string(":box-sizing"),
                Vx.Core.vx_new_string("border-box"),
                Vx.Core.vx_new_string(":margin"),
                Vx.Core.vx_new_string("0mm"),
                Vx.Core.vx_new_string(":padding"),
                Vx.Core.vx_new_string("0mm"),
                Vx.Core.vx_new_string(":position"),
                Vx.Core.vx_new_string("relative")
              )
            )
          )
        ),
        Vx.Core.f_new(
          Vx.Web.Html.t_style,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":name"),
            Vx.Core.vx_new_string("img"),
            Vx.Core.vx_new_string(":props"),
            Vx.Core.f_new(
              Vx.Web.Html.t_propmap,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":border"),
                Vx.Core.vx_new_string("0mm"),
                Vx.Core.vx_new_string(":display"),
                Vx.Core.vx_new_string("block"),
                Vx.Core.vx_new_string(":margin"),
                Vx.Core.vx_new_string("0mm"),
                Vx.Core.vx_new_string(":padding"),
                Vx.Core.vx_new_string("0mm")
              )
            )
          )
        ),
        Vx.Core.f_new(
          Vx.Web.Html.t_style,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":name"),
            Vx.Core.vx_new_string("p"),
            Vx.Core.vx_new_string(":props"),
            Vx.Core.f_new(
              Vx.Web.Html.t_propmap,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":margin-block-start"),
                Vx.Core.vx_new_string("0mm"),
                Vx.Core.vx_new_string(":margin-block-end"),
                Vx.Core.vx_new_string("0mm"),
                Vx.Core.vx_new_string(":white-space"),
                Vx.Core.vx_new_string("pre-line")
              )
            )
          )
        ),
        Vx.Core.f_new(
          Vx.Web.Html.t_style,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":name"),
            Vx.Core.vx_new_string("*"),
            Vx.Core.vx_new_string(":props"),
            Vx.Core.f_new(
              Vx.Web.Html.t_propmap,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":-webkit-print-color-adjust"),
                Vx.Core.vx_new_string("exact !important"),
                Vx.Core.vx_new_string(":color-adjust"),
                Vx.Core.vx_new_string("exact !important"),
                Vx.Core.vx_new_string(":print-color-adjust"),
                Vx.Core.vx_new_string("exact !important")
              )
            )
          )
        )
      )
    );
    return output;
  }

  /**
   * @function stylelist_from_fontfacemap
   * Returns stylelist from a fontfacemap
   * @param  {fontfacemap} fontfacemap
   * @return {stylelist}
   * (func stylelist<-fontfacemap)
   */
  public interface Func_stylelist_from_fontfacemap : Vx.Core.Func_any_from_any {
    public Vx.Web.Html.Type_stylelist vx_stylelist_from_fontfacemap(Vx.Ui.Ui.Type_fontfacemap fontfacemap);
  }

  public class Class_stylelist_from_fontfacemap : Vx.Core.Class_base, Func_stylelist_from_fontfacemap {

    public override Vx.Ui.Html.Uihtml.Func_stylelist_from_fontfacemap vx_new(params object[] vals) {
      Class_stylelist_from_fontfacemap output = new Class_stylelist_from_fontfacemap();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_stylelist_from_fontfacemap vx_copy(params object[] vals) {
      Class_stylelist_from_fontfacemap output = new Class_stylelist_from_fontfacemap();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylelist<-fontfacemap", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "stylelist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_style), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_stylelist_from_fontfacemap;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_stylelist_from_fontfacemap;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_fontfacemap inputval = (Vx.Ui.Ui.Type_fontfacemap)value;
      Vx.Core.Type_any outputval = Vx.Ui.Html.Uihtml.f_stylelist_from_fontfacemap(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_fontfacemap fontfacemap = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_fontfacemap, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Html.Uihtml.f_stylelist_from_fontfacemap(fontfacemap);
      return output;
    }

    public Vx.Web.Html.Type_stylelist vx_stylelist_from_fontfacemap(Vx.Ui.Ui.Type_fontfacemap fontfacemap) {
      return Vx.Ui.Html.Uihtml.f_stylelist_from_fontfacemap(fontfacemap);
    }

  }

  public static Func_stylelist_from_fontfacemap e_stylelist_from_fontfacemap = new Vx.Ui.Html.Uihtml.Class_stylelist_from_fontfacemap();
  public static Func_stylelist_from_fontfacemap t_stylelist_from_fontfacemap = new Vx.Ui.Html.Uihtml.Class_stylelist_from_fontfacemap();

  public static Vx.Web.Html.Type_stylelist f_stylelist_from_fontfacemap(Vx.Ui.Ui.Type_fontfacemap fontfacemap) {
    Vx.Web.Html.Type_stylelist output = Vx.Web.Html.e_stylelist;
    output = Vx.Core.f_list_from_map_1(
      Vx.Web.Html.t_stylelist,
      fontfacemap,
      Vx.Core.t_any_from_key_value.vx_fn_new((key_any, fontface_any) => {
        Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, key_any);
        Vx.Ui.Ui.Type_fontface fontface = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_fontface, fontface_any);
        Vx.Core.Type_any output_1 = 
          Vx.Ui.Html.Uihtml.f_style_from_fontface(fontface);
        return output_1;
      })
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
  public interface Func_stylelist_from_stylelist : Vx.Core.Func_any_from_any {
    public Vx.Web.Html.Type_stylelist vx_stylelist_from_stylelist(Vx.Ui.Ui.Type_stylelist uistylelist);
  }

  public class Class_stylelist_from_stylelist : Vx.Core.Class_base, Func_stylelist_from_stylelist {

    public override Vx.Ui.Html.Uihtml.Func_stylelist_from_stylelist vx_new(params object[] vals) {
      Class_stylelist_from_stylelist output = new Class_stylelist_from_stylelist();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_stylelist_from_stylelist vx_copy(params object[] vals) {
      Class_stylelist_from_stylelist output = new Class_stylelist_from_stylelist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylelist<-stylelist", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "stylelist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_style), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_stylelist_from_stylelist;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_stylelist_from_stylelist;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_stylelist inputval = (Vx.Ui.Ui.Type_stylelist)value;
      Vx.Core.Type_any outputval = Vx.Ui.Html.Uihtml.f_stylelist_from_stylelist(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_stylelist uistylelist = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_stylelist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Html.Uihtml.f_stylelist_from_stylelist(uistylelist);
      return output;
    }

    public Vx.Web.Html.Type_stylelist vx_stylelist_from_stylelist(Vx.Ui.Ui.Type_stylelist uistylelist) {
      return Vx.Ui.Html.Uihtml.f_stylelist_from_stylelist(uistylelist);
    }

  }

  public static Func_stylelist_from_stylelist e_stylelist_from_stylelist = new Vx.Ui.Html.Uihtml.Class_stylelist_from_stylelist();
  public static Func_stylelist_from_stylelist t_stylelist_from_stylelist = new Vx.Ui.Html.Uihtml.Class_stylelist_from_stylelist();

  public static Vx.Web.Html.Type_stylelist f_stylelist_from_stylelist(Vx.Ui.Ui.Type_stylelist uistylelist) {
    Vx.Web.Html.Type_stylelist output = Vx.Web.Html.e_stylelist;
    output = Vx.Core.f_list_from_list_1(
      Vx.Web.Html.t_stylelist,
      uistylelist,
      Vx.Ui.Html.Uihtml.t_style_from_style
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
  public interface Func_stylelist_from_stylemap : Vx.Core.Func_any_from_any {
    public Vx.Web.Html.Type_stylelist vx_stylelist_from_stylemap(Vx.Ui.Ui.Type_stylemap uistylemap);
  }

  public class Class_stylelist_from_stylemap : Vx.Core.Class_base, Func_stylelist_from_stylemap {

    public override Vx.Ui.Html.Uihtml.Func_stylelist_from_stylemap vx_new(params object[] vals) {
      Class_stylelist_from_stylemap output = new Class_stylelist_from_stylemap();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_stylelist_from_stylemap vx_copy(params object[] vals) {
      Class_stylelist_from_stylemap output = new Class_stylelist_from_stylemap();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylelist<-stylemap", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "stylelist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_style), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_stylelist_from_stylemap;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_stylelist_from_stylemap;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_stylemap inputval = (Vx.Ui.Ui.Type_stylemap)value;
      Vx.Core.Type_any outputval = Vx.Ui.Html.Uihtml.f_stylelist_from_stylemap(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_stylemap uistylemap = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_stylemap, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Html.Uihtml.f_stylelist_from_stylemap(uistylemap);
      return output;
    }

    public Vx.Web.Html.Type_stylelist vx_stylelist_from_stylemap(Vx.Ui.Ui.Type_stylemap uistylemap) {
      return Vx.Ui.Html.Uihtml.f_stylelist_from_stylemap(uistylemap);
    }

  }

  public static Func_stylelist_from_stylemap e_stylelist_from_stylemap = new Vx.Ui.Html.Uihtml.Class_stylelist_from_stylemap();
  public static Func_stylelist_from_stylemap t_stylelist_from_stylemap = new Vx.Ui.Html.Uihtml.Class_stylelist_from_stylemap();

  public static Vx.Web.Html.Type_stylelist f_stylelist_from_stylemap(Vx.Ui.Ui.Type_stylemap uistylemap) {
    Vx.Web.Html.Type_stylelist output = Vx.Web.Html.e_stylelist;
    output = Vx.Core.f_list_from_map_1(
      Vx.Web.Html.t_stylelist,
      uistylemap,
      Vx.Core.t_any_from_key_value.vx_fn_new((key_any, value_any) => {
        Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, key_any);
        Vx.Ui.Ui.Type_style value = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_style, value_any);
        Vx.Core.Type_any output_1 = 
          Vx.Ui.Html.Uihtml.f_style_from_style(value);
        return output_1;
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
  public interface Func_stylemap_from_stylemap : Vx.Core.Func_any_from_any {
    public Vx.Web.Html.Type_stylemap vx_stylemap_from_stylemap(Vx.Ui.Ui.Type_stylemap uistylemap);
  }

  public class Class_stylemap_from_stylemap : Vx.Core.Class_base, Func_stylemap_from_stylemap {

    public override Vx.Ui.Html.Uihtml.Func_stylemap_from_stylemap vx_new(params object[] vals) {
      Class_stylemap_from_stylemap output = new Class_stylemap_from_stylemap();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_stylemap_from_stylemap vx_copy(params object[] vals) {
      Class_stylemap_from_stylemap output = new Class_stylemap_from_stylemap();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylemap<-stylemap", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "stylemap", // name
          ":map", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_style), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_stylemap_from_stylemap;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_stylemap_from_stylemap;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_stylemap inputval = (Vx.Ui.Ui.Type_stylemap)value;
      Vx.Core.Type_any outputval = Vx.Ui.Html.Uihtml.f_stylemap_from_stylemap(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_stylemap uistylemap = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_stylemap, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Html.Uihtml.f_stylemap_from_stylemap(uistylemap);
      return output;
    }

    public Vx.Web.Html.Type_stylemap vx_stylemap_from_stylemap(Vx.Ui.Ui.Type_stylemap uistylemap) {
      return Vx.Ui.Html.Uihtml.f_stylemap_from_stylemap(uistylemap);
    }

  }

  public static Func_stylemap_from_stylemap e_stylemap_from_stylemap = new Vx.Ui.Html.Uihtml.Class_stylemap_from_stylemap();
  public static Func_stylemap_from_stylemap t_stylemap_from_stylemap = new Vx.Ui.Html.Uihtml.Class_stylemap_from_stylemap();

  public static Vx.Web.Html.Type_stylemap f_stylemap_from_stylemap(Vx.Ui.Ui.Type_stylemap uistylemap) {
    Vx.Web.Html.Type_stylemap output = Vx.Web.Html.e_stylemap;
    output = Vx.Core.f_map_from_map_1(
      Vx.Web.Html.t_stylemap,
      uistylemap,
      Vx.Core.t_any_from_key_value.vx_fn_new((key_any, value_any) => {
        Vx.Core.Type_string key = Vx.Core.f_any_from_any(Vx.Core.t_string, key_any);
        Vx.Ui.Ui.Type_style value = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_style, value_any);
        Vx.Core.Type_any output_1 = 
          Vx.Ui.Html.Uihtml.f_style_from_style(value);
        return output_1;
      })
    );
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
  public interface Func_stylesheet_layout_html : Vx.Core.Func_any_from_any_async {
    public Task<Vx.Ui.Ui.Type_stylesheet> vx_stylesheet_layout_html(Vx.Ui.Ui.Type_stylesheet stylesheetui);
  }

  public class Class_stylesheet_layout_html : Vx.Core.Class_base, Func_stylesheet_layout_html {

    public override Vx.Ui.Html.Uihtml.Func_stylesheet_layout_html vx_new(params object[] vals) {
      Class_stylesheet_layout_html output = new Class_stylesheet_layout_html();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_stylesheet_layout_html vx_copy(params object[] vals) {
      Class_stylesheet_layout_html output = new Class_stylesheet_layout_html();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylesheet-layout-html", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "stylesheet", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_stylesheet_layout_html;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_stylesheet_layout_html;
    }

    public Vx.Core.Func_any_from_any_async vx_fn_new(Vx.Core.Class_any_from_any_async.IFn fn) {
      return Vx.Core.e_any_from_any_async;
    }

    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      Vx.Ui.Ui.Type_stylesheet inputval = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_stylesheet, value);
      Task<Vx.Ui.Ui.Type_stylesheet> future = Vx.Ui.Html.Uihtml.f_stylesheet_layout_html(inputval);
      Task<T> output = Vx.Core.vx_async_from_async(generic_any_1, future);
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_from_value(Vx.Core.e_any);
      Vx.Ui.Ui.Type_stylesheet stylesheetui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_stylesheet, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Task<Vx.Ui.Ui.Type_stylesheet> future = Vx.Ui.Html.Uihtml.f_stylesheet_layout_html(stylesheetui);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<Vx.Ui.Ui.Type_stylesheet> vx_stylesheet_layout_html(Vx.Ui.Ui.Type_stylesheet stylesheetui) {
      return Vx.Ui.Html.Uihtml.f_stylesheet_layout_html(stylesheetui);
    }

  }

  public static Func_stylesheet_layout_html e_stylesheet_layout_html = new Vx.Ui.Html.Uihtml.Class_stylesheet_layout_html();
  public static Func_stylesheet_layout_html t_stylesheet_layout_html = new Vx.Ui.Html.Uihtml.Class_stylesheet_layout_html();

  public static Task<Vx.Ui.Ui.Type_stylesheet> f_stylesheet_layout_html(Vx.Ui.Ui.Type_stylesheet stylesheetui) {
    Task<Vx.Ui.Ui.Type_stylesheet> output = Vx.Core.vx_async_new_from_value(Vx.Ui.Ui.e_stylesheet);
    output = Vx.Core.f_let_async(
      Vx.Ui.Ui.t_stylesheet,
      Vx.Core.t_any_from_func_async.vx_fn_new(() => {
        Vx.Web.Html.Type_stylesheet stylesheethtml = Vx.Ui.Html.Uihtml.f_stylesheet_from_stylesheet(stylesheetui);
        Task<Vx.Core.Type_boolean> future_write = Vx.Web.Htmldoc.f_boolean_write_from_stylesheet(stylesheethtml);
        Task<Vx.Core.Type_any> output_1 = Vx.Core.vx_async_from_async_fn(future_write, (write) => {
          Vx.Core.Type_any output_2 = stylesheetui;
          return output_2;
        });
        return output_1;
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
  public interface Func_stylesheet_from_stylesheet : Vx.Core.Func_any_from_any {
    public Vx.Web.Html.Type_stylesheet vx_stylesheet_from_stylesheet(Vx.Ui.Ui.Type_stylesheet uistylesheet);
  }

  public class Class_stylesheet_from_stylesheet : Vx.Core.Class_base, Func_stylesheet_from_stylesheet {

    public override Vx.Ui.Html.Uihtml.Func_stylesheet_from_stylesheet vx_new(params object[] vals) {
      Class_stylesheet_from_stylesheet output = new Class_stylesheet_from_stylesheet();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_stylesheet_from_stylesheet vx_copy(params object[] vals) {
      Class_stylesheet_from_stylesheet output = new Class_stylesheet_from_stylesheet();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "stylesheet<-stylesheet", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "stylesheet", // name
          ":struct", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_node, Vx.Web.Html.t_headchild), // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_stylesheet_from_stylesheet;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_stylesheet_from_stylesheet;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_stylesheet inputval = (Vx.Ui.Ui.Type_stylesheet)value;
      Vx.Core.Type_any outputval = Vx.Ui.Html.Uihtml.f_stylesheet_from_stylesheet(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_stylesheet uistylesheet = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_stylesheet, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Ui.Html.Uihtml.f_stylesheet_from_stylesheet(uistylesheet);
      return output;
    }

    public Vx.Web.Html.Type_stylesheet vx_stylesheet_from_stylesheet(Vx.Ui.Ui.Type_stylesheet uistylesheet) {
      return Vx.Ui.Html.Uihtml.f_stylesheet_from_stylesheet(uistylesheet);
    }

  }

  public static Func_stylesheet_from_stylesheet e_stylesheet_from_stylesheet = new Vx.Ui.Html.Uihtml.Class_stylesheet_from_stylesheet();
  public static Func_stylesheet_from_stylesheet t_stylesheet_from_stylesheet = new Vx.Ui.Html.Uihtml.Class_stylesheet_from_stylesheet();

  public static Vx.Web.Html.Type_stylesheet f_stylesheet_from_stylesheet(Vx.Ui.Ui.Type_stylesheet uistylesheet) {
    Vx.Web.Html.Type_stylesheet output = Vx.Web.Html.e_stylesheet;
    output = Vx.Core.f_let(
      Vx.Web.Html.t_stylesheet,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_stylemap uistylemap = uistylesheet.stylemap();
        Vx.Ui.Ui.Type_fontfacemap fontfacemap = uistylesheet.fontfacemap();
        Vx.Web.Html.Type_stylelist resetlist = Vx.Ui.Html.Uihtml.f_stylelist_reset();
        Vx.Web.Html.Type_stylelist fontstyles = Vx.Ui.Html.Uihtml.f_stylelist_from_fontfacemap(fontfacemap);
        Vx.Web.Html.Type_stylelist stylelist = Vx.Ui.Html.Uihtml.f_stylelist_from_stylemap(uistylemap);
        Vx.Web.Html.Type_stylelist allstyles = Vx.Core.f_new(
          Vx.Web.Html.t_stylelist,
          Vx.Core.vx_new(Vx.Core.t_anylist,
              resetlist,
              fontstyles,
              stylelist
          )
        );
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Web.Html.t_stylesheet,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":styles"),
            allstyles
          )
        );
        return output_1;
      })
    );
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
  public interface Func_ui_layout_app_from_ui_orig_parent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_ui vx_ui_layout_app_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent);
  }

  public class Class_ui_layout_app_from_ui_orig_parent : Vx.Core.Class_base, Func_ui_layout_app_from_ui_orig_parent {

    public override Vx.Ui.Html.Uihtml.Func_ui_layout_app_from_ui_orig_parent vx_new(params object[] vals) {
      Class_ui_layout_app_from_ui_orig_parent output = new Class_ui_layout_app_from_ui_orig_parent();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_ui_layout_app_from_ui_orig_parent vx_copy(params object[] vals) {
      Class_ui_layout_app_from_ui_orig_parent output = new Class_ui_layout_app_from_ui_orig_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "ui-layout-app<-ui-orig-parent", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_layout_app_from_ui_orig_parent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_layout_app_from_ui_orig_parent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui orig = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Ui.Ui.Type_ui parent = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Ui.Html.Uihtml.f_ui_layout_app_from_ui_orig_parent(ui, orig, parent);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_layout_app_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent) {
      return Vx.Ui.Html.Uihtml.f_ui_layout_app_from_ui_orig_parent(ui, orig, parent);
    }

  }

  public static Func_ui_layout_app_from_ui_orig_parent e_ui_layout_app_from_ui_orig_parent = new Vx.Ui.Html.Uihtml.Class_ui_layout_app_from_ui_orig_parent();
  public static Func_ui_layout_app_from_ui_orig_parent t_ui_layout_app_from_ui_orig_parent = new Vx.Ui.Html.Uihtml.Class_ui_layout_app_from_ui_orig_parent();

  public static Vx.Ui.Ui.Type_ui f_ui_layout_app_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Web.Html.Type_node node = Vx.Ui.Html.Uihtml.f_node_app_from_ui_orig_parent(ui, orig, parent);
        Vx.Web.Html.Type_node nodechg = Vx.Ui.Html.Uihtml.f_node_layout_from_node_ui_parent(node, ui, parent);
        Vx.Core.Type_boolean iswrite = Vx.Ui.Html.Uihtml.f_boolean_writeeventsall_from_ui(ui);
        Vx.Core.Type_any output_1 = ui;
        return output_1;
      })
    );
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
  public interface Func_ui_layout_default_from_ui_orig_parent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_ui vx_ui_layout_default_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent);
  }

  public class Class_ui_layout_default_from_ui_orig_parent : Vx.Core.Class_base, Func_ui_layout_default_from_ui_orig_parent {

    public override Vx.Ui.Html.Uihtml.Func_ui_layout_default_from_ui_orig_parent vx_new(params object[] vals) {
      Class_ui_layout_default_from_ui_orig_parent output = new Class_ui_layout_default_from_ui_orig_parent();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_ui_layout_default_from_ui_orig_parent vx_copy(params object[] vals) {
      Class_ui_layout_default_from_ui_orig_parent output = new Class_ui_layout_default_from_ui_orig_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "ui-layout-default<-ui-orig-parent", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_layout_default_from_ui_orig_parent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_layout_default_from_ui_orig_parent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui orig = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Ui.Ui.Type_ui parent = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Ui.Html.Uihtml.f_ui_layout_default_from_ui_orig_parent(ui, orig, parent);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_layout_default_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent) {
      return Vx.Ui.Html.Uihtml.f_ui_layout_default_from_ui_orig_parent(ui, orig, parent);
    }

  }

  public static Func_ui_layout_default_from_ui_orig_parent e_ui_layout_default_from_ui_orig_parent = new Vx.Ui.Html.Uihtml.Class_ui_layout_default_from_ui_orig_parent();
  public static Func_ui_layout_default_from_ui_orig_parent t_ui_layout_default_from_ui_orig_parent = new Vx.Ui.Html.Uihtml.Class_ui_layout_default_from_ui_orig_parent();

  public static Vx.Ui.Ui.Type_ui f_ui_layout_default_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap uimap = ui.uimap();
        Vx.Web.Html.Type_node node = Vx.Ui.Html.Uihtml.f_node_default_from_ui_orig_parent(ui, orig, parent);
        Vx.Web.Html.Type_node nodechg = Vx.Ui.Html.Uihtml.f_node_layout_from_node_ui_parent(node, ui, parent);
        Vx.Core.Type_boolean iswrite = Vx.Ui.Html.Uihtml.f_boolean_writeeventsall_from_ui(ui);
        Vx.Core.Type_any output_1 = ui;
        return output_1;
      })
    );
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
  public interface Func_ui_layout_image_from_ui_orig_parent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_ui vx_ui_layout_image_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent);
  }

  public class Class_ui_layout_image_from_ui_orig_parent : Vx.Core.Class_base, Func_ui_layout_image_from_ui_orig_parent {

    public override Vx.Ui.Html.Uihtml.Func_ui_layout_image_from_ui_orig_parent vx_new(params object[] vals) {
      Class_ui_layout_image_from_ui_orig_parent output = new Class_ui_layout_image_from_ui_orig_parent();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_ui_layout_image_from_ui_orig_parent vx_copy(params object[] vals) {
      Class_ui_layout_image_from_ui_orig_parent output = new Class_ui_layout_image_from_ui_orig_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "ui-layout-image<-ui-orig-parent", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_layout_image_from_ui_orig_parent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_layout_image_from_ui_orig_parent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui orig = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Ui.Ui.Type_ui parent = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Ui.Html.Uihtml.f_ui_layout_image_from_ui_orig_parent(ui, orig, parent);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_layout_image_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent) {
      return Vx.Ui.Html.Uihtml.f_ui_layout_image_from_ui_orig_parent(ui, orig, parent);
    }

  }

  public static Func_ui_layout_image_from_ui_orig_parent e_ui_layout_image_from_ui_orig_parent = new Vx.Ui.Html.Uihtml.Class_ui_layout_image_from_ui_orig_parent();
  public static Func_ui_layout_image_from_ui_orig_parent t_ui_layout_image_from_ui_orig_parent = new Vx.Ui.Html.Uihtml.Class_ui_layout_image_from_ui_orig_parent();

  public static Vx.Ui.Ui.Type_ui f_ui_layout_image_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Web.Html.Type_node node = Vx.Ui.Html.Uihtml.f_node_image_from_ui_orig_parent(ui, orig, parent);
        Vx.Web.Html.Type_node nodechg = Vx.Ui.Html.Uihtml.f_node_layout_from_node_ui_parent(node, ui, parent);
        Vx.Core.Type_boolean iswrite = Vx.Ui.Html.Uihtml.f_boolean_writeeventsall_from_ui(ui);
        Vx.Core.Type_any output_1 = ui;
        return output_1;
      })
    );
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
  public interface Func_ui_layout_label_from_ui_orig_parent : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Ui.Ui.Type_ui vx_ui_layout_label_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent);
  }

  public class Class_ui_layout_label_from_ui_orig_parent : Vx.Core.Class_base, Func_ui_layout_label_from_ui_orig_parent {

    public override Vx.Ui.Html.Uihtml.Func_ui_layout_label_from_ui_orig_parent vx_new(params object[] vals) {
      Class_ui_layout_label_from_ui_orig_parent output = new Class_ui_layout_label_from_ui_orig_parent();
      return output;
    }

    public override Vx.Ui.Html.Uihtml.Func_ui_layout_label_from_ui_orig_parent vx_copy(params object[] vals) {
      Class_ui_layout_label_from_ui_orig_parent output = new Class_ui_layout_label_from_ui_orig_parent();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/ui/html/uihtml", // pkgname
        "ui-layout-label<-ui-orig-parent", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/ui/ui", // pkgname
          "ui", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_ui_layout_label_from_ui_orig_parent;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_ui_layout_label_from_ui_orig_parent;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Ui.Ui.Type_ui orig = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Ui.Ui.Type_ui parent = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Ui.Html.Uihtml.f_ui_layout_label_from_ui_orig_parent(ui, orig, parent);
      return output;
    }

    public Vx.Ui.Ui.Type_ui vx_ui_layout_label_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent) {
      return Vx.Ui.Html.Uihtml.f_ui_layout_label_from_ui_orig_parent(ui, orig, parent);
    }

  }

  public static Func_ui_layout_label_from_ui_orig_parent e_ui_layout_label_from_ui_orig_parent = new Vx.Ui.Html.Uihtml.Class_ui_layout_label_from_ui_orig_parent();
  public static Func_ui_layout_label_from_ui_orig_parent t_ui_layout_label_from_ui_orig_parent = new Vx.Ui.Html.Uihtml.Class_ui_layout_label_from_ui_orig_parent();

  public static Vx.Ui.Ui.Type_ui f_ui_layout_label_from_ui_orig_parent(Vx.Ui.Ui.Type_ui ui, Vx.Ui.Ui.Type_ui orig, Vx.Ui.Ui.Type_ui parent) {
    Vx.Ui.Ui.Type_ui output = Vx.Ui.Ui.e_ui;
    output = Vx.Core.f_let(
      Vx.Ui.Ui.t_ui,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Ui.Ui.Type_uimap uimap = ui.uimap();
        Vx.Web.Html.Type_node node = Vx.Ui.Html.Uihtml.f_node_label_from_ui_orig_parent(ui, orig, parent);
        Vx.Web.Html.Type_node nodechg = Vx.Ui.Html.Uihtml.f_node_layout_from_node_ui_parent(node, ui, parent);
        Vx.Core.Type_boolean iswrite = Vx.Ui.Html.Uihtml.f_boolean_writeeventsall_from_ui(ui);
        Vx.Core.Type_any output_1 = ui;
        return output_1;
      })
    );
    return output;
  }


  public static class PackageRunOnce {
    public static bool RunOnce() {
    Const_layout_app_html.const_new(c_layout_app_html);
    Const_layout_else_html.const_new(c_layout_else_html);
    Const_layout_image_html.const_new(c_layout_image_html);
    Const_layout_label_html.const_new(c_layout_label_html);
    Const_layoutenginehtml.const_new(c_layoutenginehtml);
    Const_style_hidden.const_new(c_style_hidden);
    Const_style_selected.const_new(c_style_selected);
    Vx.Core.Map<string, Vx.Core.Type_any> maptype = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_any> mapconst = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_func> mapfunc = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>();
    mapconst.put("layout-app-html", Vx.Ui.Html.Uihtml.c_layout_app_html);
    mapconst.put("layout-else-html", Vx.Ui.Html.Uihtml.c_layout_else_html);
    mapconst.put("layout-image-html", Vx.Ui.Html.Uihtml.c_layout_image_html);
    mapconst.put("layout-label-html", Vx.Ui.Html.Uihtml.c_layout_label_html);
    mapconst.put("layoutenginehtml", Vx.Ui.Html.Uihtml.c_layoutenginehtml);
    mapconst.put("style-hidden", Vx.Ui.Html.Uihtml.c_style_hidden);
    mapconst.put("style-selected", Vx.Ui.Html.Uihtml.c_style_selected);
    mapfunc.put("boolean-layoutremove-html", Vx.Ui.Html.Uihtml.t_boolean_layoutremove_html);
    mapfunc.put("boolean-layoutselected-html", Vx.Ui.Html.Uihtml.t_boolean_layoutselected_html);
    mapfunc.put("boolean-layoutvisible-html", Vx.Ui.Html.Uihtml.t_boolean_layoutvisible_html);
    mapfunc.put("boolean-print-html", Vx.Ui.Html.Uihtml.t_boolean_print_html);
    mapfunc.put("boolean-writeclass<-ui", Vx.Ui.Html.Uihtml.t_boolean_writeclass_from_ui);
    mapfunc.put("boolean-writeeventsall<-ui", Vx.Ui.Html.Uihtml.t_boolean_writeeventsall_from_ui);
    mapfunc.put("boolean-writeeventsall<-uimap", Vx.Ui.Html.Uihtml.t_boolean_writeeventsall_from_uimap);
    mapfunc.put("boolean-writeselected<-ui", Vx.Ui.Html.Uihtml.t_boolean_writeselected_from_ui);
    mapfunc.put("boolean-writevisible<-ui", Vx.Ui.Html.Uihtml.t_boolean_writevisible_from_ui);
    mapfunc.put("context-write", Vx.Ui.Html.Uihtml.t_context_write);
    mapfunc.put("divchild<-ui", Vx.Ui.Html.Uihtml.t_divchild_from_ui);
    mapfunc.put("divchildlist<-uimap", Vx.Ui.Html.Uihtml.t_divchildlist_from_uimap);
    mapfunc.put("divchildlist<-uimap_1", Vx.Ui.Html.Uihtml.t_divchildlist_from_uimap_1);
    mapfunc.put("divchildlist<-uimap-origmap-parent", Vx.Ui.Html.Uihtml.t_divchildlist_from_uimap_origmap_parent);
    mapfunc.put("node-app<-ui-orig-parent", Vx.Ui.Html.Uihtml.t_node_app_from_ui_orig_parent);
    mapfunc.put("node-default<-ui-orig-parent", Vx.Ui.Html.Uihtml.t_node_default_from_ui_orig_parent);
    mapfunc.put("node-image<-ui-orig-parent", Vx.Ui.Html.Uihtml.t_node_image_from_ui_orig_parent);
    mapfunc.put("node-label<-ui-orig-parent", Vx.Ui.Html.Uihtml.t_node_label_from_ui_orig_parent);
    mapfunc.put("node-layout<-node-ui-parent", Vx.Ui.Html.Uihtml.t_node_layout_from_node_ui_parent);
    mapfunc.put("node<-ui-orig-parent", Vx.Ui.Html.Uihtml.t_node_from_ui_orig_parent);
    mapfunc.put("string-class<-ui", Vx.Ui.Html.Uihtml.t_string_class_from_ui);
    mapfunc.put("string-style<-font", Vx.Ui.Html.Uihtml.t_string_style_from_font);
    mapfunc.put("string-style<-image", Vx.Ui.Html.Uihtml.t_string_style_from_image);
    mapfunc.put("string-stylename<-name-styletype", Vx.Ui.Html.Uihtml.t_string_stylename_from_name_styletype);
    mapfunc.put("style<-fontface", Vx.Ui.Html.Uihtml.t_style_from_fontface);
    mapfunc.put("style<-style", Vx.Ui.Html.Uihtml.t_style_from_style);
    mapfunc.put("stylelist-extra<-ui", Vx.Ui.Html.Uihtml.t_stylelist_extra_from_ui);
    mapfunc.put("stylelist-reset", Vx.Ui.Html.Uihtml.t_stylelist_reset);
    mapfunc.put("stylelist<-fontfacemap", Vx.Ui.Html.Uihtml.t_stylelist_from_fontfacemap);
    mapfunc.put("stylelist<-stylelist", Vx.Ui.Html.Uihtml.t_stylelist_from_stylelist);
    mapfunc.put("stylelist<-stylemap", Vx.Ui.Html.Uihtml.t_stylelist_from_stylemap);
    mapfunc.put("stylemap<-stylemap", Vx.Ui.Html.Uihtml.t_stylemap_from_stylemap);
    mapfunc.put("stylesheet-layout-html", Vx.Ui.Html.Uihtml.t_stylesheet_layout_html);
    mapfunc.put("stylesheet<-stylesheet", Vx.Ui.Html.Uihtml.t_stylesheet_from_stylesheet);
    mapfunc.put("ui-layout-app<-ui-orig-parent", Vx.Ui.Html.Uihtml.t_ui_layout_app_from_ui_orig_parent);
    mapfunc.put("ui-layout-default<-ui-orig-parent", Vx.Ui.Html.Uihtml.t_ui_layout_default_from_ui_orig_parent);
    mapfunc.put("ui-layout-image<-ui-orig-parent", Vx.Ui.Html.Uihtml.t_ui_layout_image_from_ui_orig_parent);
    mapfunc.put("ui-layout-label<-ui-orig-parent", Vx.Ui.Html.Uihtml.t_ui_layout_label_from_ui_orig_parent);
    Vx.Core.vx_global_package_set("vx/ui/html/uihtml", maptype, mapconst, mapfunc);
      return true;
    }
  }

  public static bool ranonce = PackageRunOnce.RunOnce();

}
