package com.vxlisp.vx.web;

import java.util.concurrent.CompletableFuture;
import com.vxlisp.vx.*;


public final class Htmldoc {

  /**
   * @function boolean_write_from_id_htmltext
   * Writes to an html node with given id and text.
   * @param  {string} id
   * @param  {string} htmltext
   * @return {boolean}
   * (func boolean-write<-id-htmltext)
   */
  public static interface Func_boolean_write_from_id_htmltext extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean f_boolean_write_from_id_htmltext(final Core.Type_string id, final Core.Type_string htmltext);
  }

  public static class Class_boolean_write_from_id_htmltext extends Core.Class_base implements Func_boolean_write_from_id_htmltext {

    @Override
    public Func_boolean_write_from_id_htmltext vx_new(Object... vals) {
      Class_boolean_write_from_id_htmltext output = new Class_boolean_write_from_id_htmltext();
      return output;
    }

    @Override
    public Func_boolean_write_from_id_htmltext vx_copy(Object... vals) {
      Class_boolean_write_from_id_htmltext output = new Class_boolean_write_from_id_htmltext();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-write<-id-htmltext", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
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
    public Func_boolean_write_from_id_htmltext vx_empty() {return e_boolean_write_from_id_htmltext;}
    @Override
    public Func_boolean_write_from_id_htmltext vx_type() {return t_boolean_write_from_id_htmltext;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string id = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string htmltext = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Htmldoc.f_boolean_write_from_id_htmltext(id, htmltext);
      return output;
    }

    @Override
    public Core.Type_boolean f_boolean_write_from_id_htmltext(final Core.Type_string id, final Core.Type_string htmltext) {
      return Htmldoc.f_boolean_write_from_id_htmltext(id, htmltext);
    }

  }

  public static final Func_boolean_write_from_id_htmltext e_boolean_write_from_id_htmltext = new Htmldoc.Class_boolean_write_from_id_htmltext();
  public static final Func_boolean_write_from_id_htmltext t_boolean_write_from_id_htmltext = new Htmldoc.Class_boolean_write_from_id_htmltext();

  public static Core.Type_boolean f_boolean_write_from_id_htmltext(final Core.Type_string id, final Core.Type_string htmltext) {
    Core.Type_boolean output = Core.e_boolean;
    return output;
  }

  /**
   * 
   * @async
   * @function boolean_write_from_stylesheet
   * Writes to an html node with given id and text.
   * @param  {stylesheet} stylesheet
   * @return {boolean}
   * (func boolean-write<-stylesheet)
   */
  public static interface Func_boolean_write_from_stylesheet extends Core.Func_any_from_any_async {
    public CompletableFuture<Core.Type_boolean> f_boolean_write_from_stylesheet(final Html.Type_stylesheet stylesheet);
  }

  public static class Class_boolean_write_from_stylesheet extends Core.Class_base implements Func_boolean_write_from_stylesheet {

    @Override
    public Func_boolean_write_from_stylesheet vx_new(Object... vals) {
      Class_boolean_write_from_stylesheet output = new Class_boolean_write_from_stylesheet();
      return output;
    }

    @Override
    public Func_boolean_write_from_stylesheet vx_copy(Object... vals) {
      Class_boolean_write_from_stylesheet output = new Class_boolean_write_from_stylesheet();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-write<-stylesheet", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
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
    public Func_boolean_write_from_stylesheet vx_empty() {return e_boolean_write_from_stylesheet;}
    @Override
    public Func_boolean_write_from_stylesheet vx_type() {return t_boolean_write_from_stylesheet;}

    @Override
    public Core.Func_any_from_any_async vx_fn_new(Core.Class_any_from_any_async.IFn fn) {return Core.e_any_from_any_async;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_any_async(final T generic_any_1, final U value) {
      Html.Type_stylesheet inputval = Core.f_any_from_any(Html.t_stylesheet, value);
      CompletableFuture<Core.Type_boolean> future = Htmldoc.f_boolean_write_from_stylesheet(inputval);
      @SuppressWarnings("unchecked")
      CompletableFuture<T> output = (CompletableFuture<T>)future;
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Html.Type_stylesheet stylesheet = Core.f_any_from_any(Html.t_stylesheet, arglist.vx_any(Core.vx_new_int(0)));
      CompletableFuture<Core.Type_boolean> future = Htmldoc.f_boolean_write_from_stylesheet(stylesheet);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Core.Type_boolean> f_boolean_write_from_stylesheet(final Html.Type_stylesheet stylesheet) {
      return Htmldoc.f_boolean_write_from_stylesheet(stylesheet);
    }

  }

  public static final Func_boolean_write_from_stylesheet e_boolean_write_from_stylesheet = new Htmldoc.Class_boolean_write_from_stylesheet();
  public static final Func_boolean_write_from_stylesheet t_boolean_write_from_stylesheet = new Htmldoc.Class_boolean_write_from_stylesheet();

  public static CompletableFuture<Core.Type_boolean> f_boolean_write_from_stylesheet(final Html.Type_stylesheet stylesheet) {
    CompletableFuture<Core.Type_boolean> output = Core.async_new_completed(Core.e_boolean);
    return output;
  }

  /**
   * @function string_from_id
   * Reads the value of an html node by id.
   * @param  {string} id
   * @return {string}
   * (func string<-id)
   */
  public static interface Func_string_from_id extends Core.Func_any_from_any {
    public Core.Type_string f_string_from_id(final Core.Type_string id);
  }

  public static class Class_string_from_id extends Core.Class_base implements Func_string_from_id {

    @Override
    public Func_string_from_id vx_new(Object... vals) {
      Class_string_from_id output = new Class_string_from_id();
      return output;
    }

    @Override
    public Func_string_from_id vx_copy(Object... vals) {
      Class_string_from_id output = new Class_string_from_id();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "string<-id", // name
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
    public Func_string_from_id vx_empty() {return e_string_from_id;}
    @Override
    public Func_string_from_id vx_type() {return t_string_from_id;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Htmldoc.f_string_from_id(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string id = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Htmldoc.f_string_from_id(id);
      return output;
    }

    @Override
    public Core.Type_string f_string_from_id(final Core.Type_string id) {
      return Htmldoc.f_string_from_id(id);
    }

  }

  public static final Func_string_from_id e_string_from_id = new Htmldoc.Class_string_from_id();
  public static final Func_string_from_id t_string_from_id = new Htmldoc.Class_string_from_id();

  public static Core.Type_string f_string_from_id(final Core.Type_string id) {
    Core.Type_string output = Core.e_string;
    return output;
  }


  static {
  }

}
