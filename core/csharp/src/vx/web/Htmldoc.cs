namespace Vx.Web;

public static class Htmldoc {

  /**
   * @function boolean_print_from_id_stylesheettext
   * Print the contents of the given id.
   * @param  {string} id
   * @param  {string} stylesheettext
   * @return {boolean}
   * (func boolean-print<-id-stylesheettext)
   */
  public interface Func_boolean_print_from_id_stylesheettext : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_boolean_print_from_id_stylesheettext(Vx.Core.Type_string id, Vx.Core.Type_string stylesheettext);
  }

  public class Class_boolean_print_from_id_stylesheettext : Vx.Core.Class_base, Func_boolean_print_from_id_stylesheettext {

    public override Vx.Web.Htmldoc.Func_boolean_print_from_id_stylesheettext vx_new(params object[] vals) {
      Vx.Web.Htmldoc.Class_boolean_print_from_id_stylesheettext output = new Vx.Web.Htmldoc.Class_boolean_print_from_id_stylesheettext();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Web.Htmldoc.Class_boolean_print_from_id_stylesheettext output = new Vx.Web.Htmldoc.Class_boolean_print_from_id_stylesheettext();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-print<-id-stylesheettext", // name
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.e_boolean_print_from_id_stylesheettext;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.t_boolean_print_from_id_stylesheettext;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string id = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string stylesheettext = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Htmldoc.f_boolean_print_from_id_stylesheettext(id, stylesheettext);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_print_from_id_stylesheettext(Vx.Core.Type_string id, Vx.Core.Type_string stylesheettext) {
      return Vx.Web.Htmldoc.f_boolean_print_from_id_stylesheettext(id, stylesheettext);
    }

  }

  public static Vx.Web.Htmldoc.Func_boolean_print_from_id_stylesheettext e_boolean_print_from_id_stylesheettext = new Vx.Web.Htmldoc.Class_boolean_print_from_id_stylesheettext();
  public static Vx.Web.Htmldoc.Func_boolean_print_from_id_stylesheettext t_boolean_print_from_id_stylesheettext = new Vx.Web.Htmldoc.Class_boolean_print_from_id_stylesheettext();

  public static Vx.Core.Type_boolean f_boolean_print_from_id_stylesheettext(Vx.Core.Type_string id, Vx.Core.Type_string stylesheettext) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    return output;
  }

  /**
   * @function boolean_remove_from_id
   * Removes an html node with given id.
   * @param  {string} id
   * @return {boolean}
   * (func boolean-remove<-id)
   */
  public interface Func_boolean_remove_from_id : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_boolean_remove_from_id(Vx.Core.Type_string id);
  }

  public class Class_boolean_remove_from_id : Vx.Core.Class_base, Func_boolean_remove_from_id {

    public override Vx.Web.Htmldoc.Func_boolean_remove_from_id vx_new(params object[] vals) {
      Vx.Web.Htmldoc.Class_boolean_remove_from_id output = new Vx.Web.Htmldoc.Class_boolean_remove_from_id();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Web.Htmldoc.Class_boolean_remove_from_id output = new Vx.Web.Htmldoc.Class_boolean_remove_from_id();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-remove<-id", // name
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.e_boolean_remove_from_id;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.t_boolean_remove_from_id;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Web.Htmldoc.f_boolean_remove_from_id(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string id = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Web.Htmldoc.f_boolean_remove_from_id(id);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_remove_from_id(Vx.Core.Type_string id) {
      return Vx.Web.Htmldoc.f_boolean_remove_from_id(id);
    }

  }

  public static Vx.Web.Htmldoc.Func_boolean_remove_from_id e_boolean_remove_from_id = new Vx.Web.Htmldoc.Class_boolean_remove_from_id();
  public static Vx.Web.Htmldoc.Func_boolean_remove_from_id t_boolean_remove_from_id = new Vx.Web.Htmldoc.Class_boolean_remove_from_id();

  public static Vx.Core.Type_boolean f_boolean_remove_from_id(Vx.Core.Type_string id) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    return output;
  }

  /**
   * @function boolean_replace_from_id_htmltext
   * Replaces an html node with given id and text.
   * @param  {string} id
   * @param  {string} htmltext
   * @return {boolean}
   * (func boolean-replace<-id-htmltext)
   */
  public interface Func_boolean_replace_from_id_htmltext : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_boolean_replace_from_id_htmltext(Vx.Core.Type_string id, Vx.Core.Type_string htmltext);
  }

  public class Class_boolean_replace_from_id_htmltext : Vx.Core.Class_base, Func_boolean_replace_from_id_htmltext {

    public override Vx.Web.Htmldoc.Func_boolean_replace_from_id_htmltext vx_new(params object[] vals) {
      Vx.Web.Htmldoc.Class_boolean_replace_from_id_htmltext output = new Vx.Web.Htmldoc.Class_boolean_replace_from_id_htmltext();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Web.Htmldoc.Class_boolean_replace_from_id_htmltext output = new Vx.Web.Htmldoc.Class_boolean_replace_from_id_htmltext();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-replace<-id-htmltext", // name
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.e_boolean_replace_from_id_htmltext;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.t_boolean_replace_from_id_htmltext;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string id = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string htmltext = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Htmldoc.f_boolean_replace_from_id_htmltext(id, htmltext);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_replace_from_id_htmltext(Vx.Core.Type_string id, Vx.Core.Type_string htmltext) {
      return Vx.Web.Htmldoc.f_boolean_replace_from_id_htmltext(id, htmltext);
    }

  }

  public static Vx.Web.Htmldoc.Func_boolean_replace_from_id_htmltext e_boolean_replace_from_id_htmltext = new Vx.Web.Htmldoc.Class_boolean_replace_from_id_htmltext();
  public static Vx.Web.Htmldoc.Func_boolean_replace_from_id_htmltext t_boolean_replace_from_id_htmltext = new Vx.Web.Htmldoc.Class_boolean_replace_from_id_htmltext();

  public static Vx.Core.Type_boolean f_boolean_replace_from_id_htmltext(Vx.Core.Type_string id, Vx.Core.Type_string htmltext) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    return output;
  }

  /**
   * @function boolean_replace_from_id_parent_htmltext
   * Replaces an html node with given id, parentid, and text.
   * @param  {string} id
   * @param  {string} parent
   * @param  {string} htmltext
   * @return {boolean}
   * (func boolean-replace<-id-parent-htmltext)
   */
  public interface Func_boolean_replace_from_id_parent_htmltext : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_boolean_replace_from_id_parent_htmltext(Vx.Core.Type_string id, Vx.Core.Type_string parent, Vx.Core.Type_string htmltext);
  }

  public class Class_boolean_replace_from_id_parent_htmltext : Vx.Core.Class_base, Func_boolean_replace_from_id_parent_htmltext {

    public override Vx.Web.Htmldoc.Func_boolean_replace_from_id_parent_htmltext vx_new(params object[] vals) {
      Vx.Web.Htmldoc.Class_boolean_replace_from_id_parent_htmltext output = new Vx.Web.Htmldoc.Class_boolean_replace_from_id_parent_htmltext();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Web.Htmldoc.Class_boolean_replace_from_id_parent_htmltext output = new Vx.Web.Htmldoc.Class_boolean_replace_from_id_parent_htmltext();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-replace<-id-parent-htmltext", // name
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.e_boolean_replace_from_id_parent_htmltext;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.t_boolean_replace_from_id_parent_htmltext;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string id = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string parent = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Type_string htmltext = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Web.Htmldoc.f_boolean_replace_from_id_parent_htmltext(id, parent, htmltext);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_replace_from_id_parent_htmltext(Vx.Core.Type_string id, Vx.Core.Type_string parent, Vx.Core.Type_string htmltext) {
      return Vx.Web.Htmldoc.f_boolean_replace_from_id_parent_htmltext(id, parent, htmltext);
    }

  }

  public static Vx.Web.Htmldoc.Func_boolean_replace_from_id_parent_htmltext e_boolean_replace_from_id_parent_htmltext = new Vx.Web.Htmldoc.Class_boolean_replace_from_id_parent_htmltext();
  public static Vx.Web.Htmldoc.Func_boolean_replace_from_id_parent_htmltext t_boolean_replace_from_id_parent_htmltext = new Vx.Web.Htmldoc.Class_boolean_replace_from_id_parent_htmltext();

  public static Vx.Core.Type_boolean f_boolean_replace_from_id_parent_htmltext(Vx.Core.Type_string id, Vx.Core.Type_string parent, Vx.Core.Type_string htmltext) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    return output;
  }

  /**
   * 
   * @async
   * @function boolean_write_stylesheet_from_string
   * Writes a css stylesheet.
   * @param  {string} text
   * @return {boolean}
   * (func boolean-write-stylesheet<-string)
   */
  public interface Func_boolean_write_stylesheet_from_string : Vx.Core.Func_any_from_any_async {
    public Task<Vx.Core.Type_boolean> vx_boolean_write_stylesheet_from_string(Vx.Core.Type_string text);
  }

  public class Class_boolean_write_stylesheet_from_string : Vx.Core.Class_base, Func_boolean_write_stylesheet_from_string {

    public override Vx.Web.Htmldoc.Func_boolean_write_stylesheet_from_string vx_new(params object[] vals) {
      Vx.Web.Htmldoc.Class_boolean_write_stylesheet_from_string output = new Vx.Web.Htmldoc.Class_boolean_write_stylesheet_from_string();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Web.Htmldoc.Class_boolean_write_stylesheet_from_string output = new Vx.Web.Htmldoc.Class_boolean_write_stylesheet_from_string();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-write-stylesheet<-string", // name
        0, // idx
        true, // async
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.e_boolean_write_stylesheet_from_string;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.t_boolean_write_stylesheet_from_string;
      return output;
    }

    public Vx.Core.Func_any_from_any_async vx_fn_new(Vx.Core.Class_any_from_any_async.IFn fn) {
      return Vx.Core.e_any_from_any_async;
    }

    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      Vx.Core.Type_string inputval = Vx.Core.f_any_from_any(Vx.Core.t_string, value);
      Task<Vx.Core.Type_boolean> future = Vx.Web.Htmldoc.f_boolean_write_stylesheet_from_string(inputval);
      Task<T> output = Vx.Core.vx_async_from_async(generic_any_1, future);
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_from_value(Vx.Core.e_any);
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Task<Vx.Core.Type_boolean> future = Vx.Web.Htmldoc.f_boolean_write_stylesheet_from_string(text);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<Vx.Core.Type_boolean> vx_boolean_write_stylesheet_from_string(Vx.Core.Type_string text) {
      return Vx.Web.Htmldoc.f_boolean_write_stylesheet_from_string(text);
    }

  }

  public static Vx.Web.Htmldoc.Func_boolean_write_stylesheet_from_string e_boolean_write_stylesheet_from_string = new Vx.Web.Htmldoc.Class_boolean_write_stylesheet_from_string();
  public static Vx.Web.Htmldoc.Func_boolean_write_stylesheet_from_string t_boolean_write_stylesheet_from_string = new Vx.Web.Htmldoc.Class_boolean_write_stylesheet_from_string();

  public static Task<Vx.Core.Type_boolean> f_boolean_write_stylesheet_from_string(Vx.Core.Type_string text) {
    Task<Vx.Core.Type_boolean> output = Vx.Core.vx_async_new_from_value(Vx.Core.e_boolean);
    return output;
  }

  /**
   * @function boolean_write_from_id_attribute_value
   * Writes to an html node with given id and attribute name and value.
   * @param  {string} id
   * @param  {string} attribute
   * @param  {string} value
   * @return {boolean}
   * (func boolean-write<-id-attribute-value)
   */
  public interface Func_boolean_write_from_id_attribute_value : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_boolean_write_from_id_attribute_value(Vx.Core.Type_string id, Vx.Core.Type_string attribute, Vx.Core.Type_string value);
  }

  public class Class_boolean_write_from_id_attribute_value : Vx.Core.Class_base, Func_boolean_write_from_id_attribute_value {

    public override Vx.Web.Htmldoc.Func_boolean_write_from_id_attribute_value vx_new(params object[] vals) {
      Vx.Web.Htmldoc.Class_boolean_write_from_id_attribute_value output = new Vx.Web.Htmldoc.Class_boolean_write_from_id_attribute_value();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Web.Htmldoc.Class_boolean_write_from_id_attribute_value output = new Vx.Web.Htmldoc.Class_boolean_write_from_id_attribute_value();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-write<-id-attribute-value", // name
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.e_boolean_write_from_id_attribute_value;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.t_boolean_write_from_id_attribute_value;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string id = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string attribute = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Type_string value = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Web.Htmldoc.f_boolean_write_from_id_attribute_value(id, attribute, value);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_write_from_id_attribute_value(Vx.Core.Type_string id, Vx.Core.Type_string attribute, Vx.Core.Type_string value) {
      return Vx.Web.Htmldoc.f_boolean_write_from_id_attribute_value(id, attribute, value);
    }

  }

  public static Vx.Web.Htmldoc.Func_boolean_write_from_id_attribute_value e_boolean_write_from_id_attribute_value = new Vx.Web.Htmldoc.Class_boolean_write_from_id_attribute_value();
  public static Vx.Web.Htmldoc.Func_boolean_write_from_id_attribute_value t_boolean_write_from_id_attribute_value = new Vx.Web.Htmldoc.Class_boolean_write_from_id_attribute_value();

  public static Vx.Core.Type_boolean f_boolean_write_from_id_attribute_value(Vx.Core.Type_string id, Vx.Core.Type_string attribute, Vx.Core.Type_string value) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    return output;
  }

  /**
   * @function boolean_write_from_id_htmltext
   * Writes to an html node with given id and text.
   * @param  {string} id
   * @param  {string} htmltext
   * @return {boolean}
   * (func boolean-write<-id-htmltext)
   */
  public interface Func_boolean_write_from_id_htmltext : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_boolean_write_from_id_htmltext(Vx.Core.Type_string id, Vx.Core.Type_string htmltext);
  }

  public class Class_boolean_write_from_id_htmltext : Vx.Core.Class_base, Func_boolean_write_from_id_htmltext {

    public override Vx.Web.Htmldoc.Func_boolean_write_from_id_htmltext vx_new(params object[] vals) {
      Vx.Web.Htmldoc.Class_boolean_write_from_id_htmltext output = new Vx.Web.Htmldoc.Class_boolean_write_from_id_htmltext();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Web.Htmldoc.Class_boolean_write_from_id_htmltext output = new Vx.Web.Htmldoc.Class_boolean_write_from_id_htmltext();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-write<-id-htmltext", // name
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.e_boolean_write_from_id_htmltext;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.t_boolean_write_from_id_htmltext;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string id = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string htmltext = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Htmldoc.f_boolean_write_from_id_htmltext(id, htmltext);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_write_from_id_htmltext(Vx.Core.Type_string id, Vx.Core.Type_string htmltext) {
      return Vx.Web.Htmldoc.f_boolean_write_from_id_htmltext(id, htmltext);
    }

  }

  public static Vx.Web.Htmldoc.Func_boolean_write_from_id_htmltext e_boolean_write_from_id_htmltext = new Vx.Web.Htmldoc.Class_boolean_write_from_id_htmltext();
  public static Vx.Web.Htmldoc.Func_boolean_write_from_id_htmltext t_boolean_write_from_id_htmltext = new Vx.Web.Htmldoc.Class_boolean_write_from_id_htmltext();

  public static Vx.Core.Type_boolean f_boolean_write_from_id_htmltext(Vx.Core.Type_string id, Vx.Core.Type_string htmltext) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    return output;
  }

  /**
   * @function boolean_write_from_id_visible
   * Writes to an html node changing its visibility.
   * @param  {string} id
   * @param  {boolean} visible
   * @return {boolean}
   * (func boolean-write<-id-visible)
   */
  public interface Func_boolean_write_from_id_visible : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_boolean_write_from_id_visible(Vx.Core.Type_string id, Vx.Core.Type_boolean visible);
  }

  public class Class_boolean_write_from_id_visible : Vx.Core.Class_base, Func_boolean_write_from_id_visible {

    public override Vx.Web.Htmldoc.Func_boolean_write_from_id_visible vx_new(params object[] vals) {
      Vx.Web.Htmldoc.Class_boolean_write_from_id_visible output = new Vx.Web.Htmldoc.Class_boolean_write_from_id_visible();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Web.Htmldoc.Class_boolean_write_from_id_visible output = new Vx.Web.Htmldoc.Class_boolean_write_from_id_visible();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-write<-id-visible", // name
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.e_boolean_write_from_id_visible;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.t_boolean_write_from_id_visible;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string id = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_boolean visible = Vx.Core.f_any_from_any(Vx.Core.t_boolean, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Web.Htmldoc.f_boolean_write_from_id_visible(id, visible);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_write_from_id_visible(Vx.Core.Type_string id, Vx.Core.Type_boolean visible) {
      return Vx.Web.Htmldoc.f_boolean_write_from_id_visible(id, visible);
    }

  }

  public static Vx.Web.Htmldoc.Func_boolean_write_from_id_visible e_boolean_write_from_id_visible = new Vx.Web.Htmldoc.Class_boolean_write_from_id_visible();
  public static Vx.Web.Htmldoc.Func_boolean_write_from_id_visible t_boolean_write_from_id_visible = new Vx.Web.Htmldoc.Class_boolean_write_from_id_visible();

  public static Vx.Core.Type_boolean f_boolean_write_from_id_visible(Vx.Core.Type_string id, Vx.Core.Type_boolean visible) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    return output;
  }

  /**
   * 
   * @async
   * @function boolean_write_from_stylesheet
   * Writes a css stylesheet.
   * @param  {stylesheet} stylesheet
   * @return {boolean}
   * (func boolean-write<-stylesheet)
   */
  public interface Func_boolean_write_from_stylesheet : Vx.Core.Func_any_from_any_async {
    public Task<Vx.Core.Type_boolean> vx_boolean_write_from_stylesheet(Vx.Web.Html.Type_stylesheet stylesheet);
  }

  public class Class_boolean_write_from_stylesheet : Vx.Core.Class_base, Func_boolean_write_from_stylesheet {

    public override Vx.Web.Htmldoc.Func_boolean_write_from_stylesheet vx_new(params object[] vals) {
      Vx.Web.Htmldoc.Class_boolean_write_from_stylesheet output = new Vx.Web.Htmldoc.Class_boolean_write_from_stylesheet();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Web.Htmldoc.Class_boolean_write_from_stylesheet output = new Vx.Web.Htmldoc.Class_boolean_write_from_stylesheet();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-write<-stylesheet", // name
        0, // idx
        true, // async
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.e_boolean_write_from_stylesheet;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.t_boolean_write_from_stylesheet;
      return output;
    }

    public Vx.Core.Func_any_from_any_async vx_fn_new(Vx.Core.Class_any_from_any_async.IFn fn) {
      return Vx.Core.e_any_from_any_async;
    }

    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      Vx.Web.Html.Type_stylesheet inputval = Vx.Core.f_any_from_any(Vx.Web.Html.t_stylesheet, value);
      Task<Vx.Core.Type_boolean> future = Vx.Web.Htmldoc.f_boolean_write_from_stylesheet(inputval);
      Task<T> output = Vx.Core.vx_async_from_async(generic_any_1, future);
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_from_value(Vx.Core.e_any);
      Vx.Web.Html.Type_stylesheet stylesheet = Vx.Core.f_any_from_any(Vx.Web.Html.t_stylesheet, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Task<Vx.Core.Type_boolean> future = Vx.Web.Htmldoc.f_boolean_write_from_stylesheet(stylesheet);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<Vx.Core.Type_boolean> vx_boolean_write_from_stylesheet(Vx.Web.Html.Type_stylesheet stylesheet) {
      return Vx.Web.Htmldoc.f_boolean_write_from_stylesheet(stylesheet);
    }

  }

  public static Vx.Web.Htmldoc.Func_boolean_write_from_stylesheet e_boolean_write_from_stylesheet = new Vx.Web.Htmldoc.Class_boolean_write_from_stylesheet();
  public static Vx.Web.Htmldoc.Func_boolean_write_from_stylesheet t_boolean_write_from_stylesheet = new Vx.Web.Htmldoc.Class_boolean_write_from_stylesheet();

  public static Task<Vx.Core.Type_boolean> f_boolean_write_from_stylesheet(Vx.Web.Html.Type_stylesheet stylesheet) {
    Task<Vx.Core.Type_boolean> output = Vx.Core.vx_async_new_from_value(Vx.Core.e_boolean);
    output = Vx.Core.f_let_async(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func_async.vx_fn_new(() => {
        Vx.Core.Type_string text = Vx.Web.Htmldoc.f_string_from_stylesheet(stylesheet);
        Task<Vx.Core.Type_boolean> future_iswrite = Vx.Web.Htmldoc.f_boolean_write_stylesheet_from_string(text);
        Task<Vx.Core.Type_any> output_1 = Vx.Core.vx_async_from_async_fn(future_iswrite, (iswrite) => {
          Vx.Core.Type_any output_2 = iswrite;
          return output_2;
        });
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function boolean_writeevents_from_ui
   * Writes the eventmap from ui into dom.
   * @param  {ui} ui
   * @return {boolean}
   * (func boolean-writeevents<-ui)
   */
  public interface Func_boolean_writeevents_from_ui : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_boolean_writeevents_from_ui(Vx.Ui.Ui.Type_ui ui);
  }

  public class Class_boolean_writeevents_from_ui : Vx.Core.Class_base, Func_boolean_writeevents_from_ui {

    public override Vx.Web.Htmldoc.Func_boolean_writeevents_from_ui vx_new(params object[] vals) {
      Vx.Web.Htmldoc.Class_boolean_writeevents_from_ui output = new Vx.Web.Htmldoc.Class_boolean_writeevents_from_ui();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Web.Htmldoc.Class_boolean_writeevents_from_ui output = new Vx.Web.Htmldoc.Class_boolean_writeevents_from_ui();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-writeevents<-ui", // name
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.e_boolean_writeevents_from_ui;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.t_boolean_writeevents_from_ui;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Ui.Ui.Type_ui inputval = (Vx.Ui.Ui.Type_ui)value;
      Vx.Core.Type_any outputval = Vx.Web.Htmldoc.f_boolean_writeevents_from_ui(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Ui.Ui.Type_ui ui = Vx.Core.f_any_from_any(Vx.Ui.Ui.t_ui, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Web.Htmldoc.f_boolean_writeevents_from_ui(ui);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_writeevents_from_ui(Vx.Ui.Ui.Type_ui ui) {
      return Vx.Web.Htmldoc.f_boolean_writeevents_from_ui(ui);
    }

  }

  public static Vx.Web.Htmldoc.Func_boolean_writeevents_from_ui e_boolean_writeevents_from_ui = new Vx.Web.Htmldoc.Class_boolean_writeevents_from_ui();
  public static Vx.Web.Htmldoc.Func_boolean_writeevents_from_ui t_boolean_writeevents_from_ui = new Vx.Web.Htmldoc.Class_boolean_writeevents_from_ui();

  public static Vx.Core.Type_boolean f_boolean_writeevents_from_ui(Vx.Ui.Ui.Type_ui ui) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    return output;
  }

  /**
   * @function context_read
   * Reads context from document.data.context
   * @return {context}
   * (func context-read)
   */
  public interface Func_context_read : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_context vx_context_read();
  }

  public class Class_context_read : Vx.Core.Class_base, Func_context_read {

    public override Vx.Web.Htmldoc.Func_context_read vx_new(params object[] vals) {
      Vx.Web.Htmldoc.Class_context_read output = new Vx.Web.Htmldoc.Class_context_read();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Web.Htmldoc.Class_context_read output = new Vx.Web.Htmldoc.Class_context_read();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "context-read", // name
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.e_context_read;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.t_context_read;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      output = Vx.Web.Htmldoc.f_context_read();
      return output;
    }

    public Vx.Core.Type_context vx_context_read() {
      return Vx.Web.Htmldoc.f_context_read();
    }

  }

  public static Vx.Web.Htmldoc.Func_context_read e_context_read = new Vx.Web.Htmldoc.Class_context_read();
  public static Vx.Web.Htmldoc.Func_context_read t_context_read = new Vx.Web.Htmldoc.Class_context_read();

  public static Vx.Core.Type_context f_context_read() {
    Vx.Core.Type_context output = Vx.Core.e_context;
    return output;
  }

  /**
   * @function context_write
   * Writes context to document.data.context
   * @return {context}
   * (func context-write)
   */
  public interface Func_context_write : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_context vx_context_write(Vx.Core.Type_context context);
  }

  public class Class_context_write : Vx.Core.Class_base, Func_context_write {

    public override Vx.Web.Htmldoc.Func_context_write vx_new(params object[] vals) {
      Vx.Web.Htmldoc.Class_context_write output = new Vx.Web.Htmldoc.Class_context_write();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Web.Htmldoc.Class_context_write output = new Vx.Web.Htmldoc.Class_context_write();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.e_context_write;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.t_context_write;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Web.Htmldoc.f_context_write(context);
      return output;
    }

    public Vx.Core.Type_context vx_context_write(Vx.Core.Type_context context) {
      return Vx.Web.Htmldoc.f_context_write(context);
    }

  }

  public static Vx.Web.Htmldoc.Func_context_write e_context_write = new Vx.Web.Htmldoc.Class_context_write();
  public static Vx.Web.Htmldoc.Func_context_write t_context_write = new Vx.Web.Htmldoc.Class_context_write();

  public static Vx.Core.Type_context f_context_write(Vx.Core.Type_context context) {
    Vx.Core.Type_context output = Vx.Core.e_context;
    return output;
  }

  /**
   * @function string_from_id
   * Reads the value of an html node by id.
   * @param  {string} id
   * @return {string}
   * (func string<-id)
   */
  public interface Func_string_from_id : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_string_from_id(Vx.Core.Type_string id);
  }

  public class Class_string_from_id : Vx.Core.Class_base, Func_string_from_id {

    public override Vx.Web.Htmldoc.Func_string_from_id vx_new(params object[] vals) {
      Vx.Web.Htmldoc.Class_string_from_id output = new Vx.Web.Htmldoc.Class_string_from_id();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Web.Htmldoc.Class_string_from_id output = new Vx.Web.Htmldoc.Class_string_from_id();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "string<-id", // name
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.e_string_from_id;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.t_string_from_id;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Web.Htmldoc.f_string_from_id(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string id = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Web.Htmldoc.f_string_from_id(id);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_id(Vx.Core.Type_string id) {
      return Vx.Web.Htmldoc.f_string_from_id(id);
    }

  }

  public static Vx.Web.Htmldoc.Func_string_from_id e_string_from_id = new Vx.Web.Htmldoc.Class_string_from_id();
  public static Vx.Web.Htmldoc.Func_string_from_id t_string_from_id = new Vx.Web.Htmldoc.Class_string_from_id();

  public static Vx.Core.Type_string f_string_from_id(Vx.Core.Type_string id) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    return output;
  }

  /**
   * @function string_from_stylesheet
   * Returns string from a given stylesheet
   * @param  {stylesheet} stylesheet
   * @return {string}
   * (func string<-stylesheet)
   */
  public interface Func_string_from_stylesheet : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_string_from_stylesheet(Vx.Web.Html.Type_stylesheet stylesheet);
  }

  public class Class_string_from_stylesheet : Vx.Core.Class_base, Func_string_from_stylesheet {

    public override Vx.Web.Htmldoc.Func_string_from_stylesheet vx_new(params object[] vals) {
      Vx.Web.Htmldoc.Class_string_from_stylesheet output = new Vx.Web.Htmldoc.Class_string_from_stylesheet();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Web.Htmldoc.Class_string_from_stylesheet output = new Vx.Web.Htmldoc.Class_string_from_stylesheet();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "string<-stylesheet", // name
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.e_string_from_stylesheet;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.t_string_from_stylesheet;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Web.Html.Type_stylesheet inputval = (Vx.Web.Html.Type_stylesheet)value;
      Vx.Core.Type_any outputval = Vx.Web.Htmldoc.f_string_from_stylesheet(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_stylesheet stylesheet = Vx.Core.f_any_from_any(Vx.Web.Html.t_stylesheet, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Web.Htmldoc.f_string_from_stylesheet(stylesheet);
      return output;
    }

    public Vx.Core.Type_string vx_string_from_stylesheet(Vx.Web.Html.Type_stylesheet stylesheet) {
      return Vx.Web.Htmldoc.f_string_from_stylesheet(stylesheet);
    }

  }

  public static Vx.Web.Htmldoc.Func_string_from_stylesheet e_string_from_stylesheet = new Vx.Web.Htmldoc.Class_string_from_stylesheet();
  public static Vx.Web.Htmldoc.Func_string_from_stylesheet t_string_from_stylesheet = new Vx.Web.Htmldoc.Class_string_from_stylesheet();

  public static Vx.Core.Type_string f_string_from_stylesheet(Vx.Web.Html.Type_stylesheet stylesheet) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Web.Html.Type_stylelist stylelist = Vx.Web.Html.f_styles_from_stylesheet(stylesheet);
        Vx.Core.Type_string text = Vx.Web.Html.f_string_from_stylelist_indent(stylelist, Vx.Core.vx_new_int(0));
        Vx.Core.Type_any output_1 = text;
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function ui_readstate_from_uid
   * Returns ui component from element.
   * @param  {string} uid
   * @return {any}
   * (func ui-readstate<-uid)
   */
  public interface Func_ui_readstate_from_uid : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_any vx_ui_readstate_from_uid(Vx.Core.Type_string uid);
  }

  public class Class_ui_readstate_from_uid : Vx.Core.Class_base, Func_ui_readstate_from_uid {

    public override Vx.Web.Htmldoc.Func_ui_readstate_from_uid vx_new(params object[] vals) {
      Vx.Web.Htmldoc.Class_ui_readstate_from_uid output = new Vx.Web.Htmldoc.Class_ui_readstate_from_uid();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Web.Htmldoc.Class_ui_readstate_from_uid output = new Vx.Web.Htmldoc.Class_ui_readstate_from_uid();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "ui-readstate<-uid", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any", // name
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.e_ui_readstate_from_uid;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Web.Htmldoc.t_ui_readstate_from_uid;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Web.Htmldoc.f_ui_readstate_from_uid(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string uid = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Web.Htmldoc.f_ui_readstate_from_uid(uid);
      return output;
    }

    public Vx.Core.Type_any vx_ui_readstate_from_uid(Vx.Core.Type_string uid) {
      return Vx.Web.Htmldoc.f_ui_readstate_from_uid(uid);
    }

  }

  public static Vx.Web.Htmldoc.Func_ui_readstate_from_uid e_ui_readstate_from_uid = new Vx.Web.Htmldoc.Class_ui_readstate_from_uid();
  public static Vx.Web.Htmldoc.Func_ui_readstate_from_uid t_ui_readstate_from_uid = new Vx.Web.Htmldoc.Class_ui_readstate_from_uid();

  public static Vx.Core.Type_any f_ui_readstate_from_uid(Vx.Core.Type_string uid) {
    Vx.Core.Type_any output = Vx.Core.e_any;
    return output;
  }


  public static class PackageRunOnce {
    public static bool RunOnce() {
    Vx.Core.Map<string, Vx.Core.Type_any> maptype = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_any> mapconst = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_func> mapfunc = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>();
    mapfunc.put("boolean-print<-id-stylesheettext", Vx.Web.Htmldoc.t_boolean_print_from_id_stylesheettext);
    mapfunc.put("boolean-remove<-id", Vx.Web.Htmldoc.t_boolean_remove_from_id);
    mapfunc.put("boolean-replace<-id-htmltext", Vx.Web.Htmldoc.t_boolean_replace_from_id_htmltext);
    mapfunc.put("boolean-replace<-id-parent-htmltext", Vx.Web.Htmldoc.t_boolean_replace_from_id_parent_htmltext);
    mapfunc.put("boolean-write-stylesheet<-string", Vx.Web.Htmldoc.t_boolean_write_stylesheet_from_string);
    mapfunc.put("boolean-write<-id-attribute-value", Vx.Web.Htmldoc.t_boolean_write_from_id_attribute_value);
    mapfunc.put("boolean-write<-id-htmltext", Vx.Web.Htmldoc.t_boolean_write_from_id_htmltext);
    mapfunc.put("boolean-write<-id-visible", Vx.Web.Htmldoc.t_boolean_write_from_id_visible);
    mapfunc.put("boolean-write<-stylesheet", Vx.Web.Htmldoc.t_boolean_write_from_stylesheet);
    mapfunc.put("boolean-writeevents<-ui", Vx.Web.Htmldoc.t_boolean_writeevents_from_ui);
    mapfunc.put("context-read", Vx.Web.Htmldoc.t_context_read);
    mapfunc.put("context-write", Vx.Web.Htmldoc.t_context_write);
    mapfunc.put("string<-id", Vx.Web.Htmldoc.t_string_from_id);
    mapfunc.put("string<-stylesheet", Vx.Web.Htmldoc.t_string_from_stylesheet);
    mapfunc.put("ui-readstate<-uid", Vx.Web.Htmldoc.t_ui_readstate_from_uid);
    Vx.Core.vx_global_package_set("vx/web/htmldoc", maptype, mapconst, mapfunc);
      return true;
    }
  }

  public static bool ranonce = PackageRunOnce.RunOnce();

}
