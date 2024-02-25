package com.vxlisp.vx.web;

import java.util.concurrent.CompletableFuture;
import java.util.LinkedHashMap;
import java.util.Map;
import com.vxlisp.vx.*;

public final class Htmldoc {

  /**
   * @function any_data_from_id
   * Returns data component from element.
   * @param  {string} id
   * @return {any}
   * (func any-data<-id)
   */
  public static interface Func_any_data_from_id extends Core.Func_any_from_any {
    public Core.Type_any vx_any_data_from_id(final Core.Type_string id);
  }

  public static class Class_any_data_from_id extends Core.Class_base implements Func_any_data_from_id {

    @Override
    public Func_any_data_from_id vx_new(Object... vals) {
      Class_any_data_from_id output = new Class_any_data_from_id();
      return output;
    }

    @Override
    public Func_any_data_from_id vx_copy(Object... vals) {
      Class_any_data_from_id output = new Class_any_data_from_id();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "any-data<-id", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any", // name
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
    public Func_any_data_from_id vx_empty() {return e_any_data_from_id;}
    @Override
    public Func_any_data_from_id vx_type() {return t_any_data_from_id;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Htmldoc.f_any_data_from_id(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string id = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Htmldoc.f_any_data_from_id(id);
      return output;
    }

    @Override
    public Core.Type_any vx_any_data_from_id(final Core.Type_string id) {
      return Htmldoc.f_any_data_from_id(id);
    }

  }

  public static final Func_any_data_from_id e_any_data_from_id = new Htmldoc.Class_any_data_from_id();
  public static final Func_any_data_from_id t_any_data_from_id = new Htmldoc.Class_any_data_from_id();

  public static Core.Type_any f_any_data_from_id(final Core.Type_string id) {
    Core.Type_any output = Core.e_any;
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
  public static interface Func_boolean_replace_from_id_htmltext extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean vx_boolean_replace_from_id_htmltext(final Core.Type_string id, final Core.Type_string htmltext);
  }

  public static class Class_boolean_replace_from_id_htmltext extends Core.Class_base implements Func_boolean_replace_from_id_htmltext {

    @Override
    public Func_boolean_replace_from_id_htmltext vx_new(Object... vals) {
      Class_boolean_replace_from_id_htmltext output = new Class_boolean_replace_from_id_htmltext();
      return output;
    }

    @Override
    public Func_boolean_replace_from_id_htmltext vx_copy(Object... vals) {
      Class_boolean_replace_from_id_htmltext output = new Class_boolean_replace_from_id_htmltext();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-replace<-id-htmltext", // name
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
    public Func_boolean_replace_from_id_htmltext vx_empty() {return e_boolean_replace_from_id_htmltext;}
    @Override
    public Func_boolean_replace_from_id_htmltext vx_type() {return t_boolean_replace_from_id_htmltext;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string id = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string htmltext = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Htmldoc.f_boolean_replace_from_id_htmltext(id, htmltext);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_replace_from_id_htmltext(final Core.Type_string id, final Core.Type_string htmltext) {
      return Htmldoc.f_boolean_replace_from_id_htmltext(id, htmltext);
    }

  }

  public static final Func_boolean_replace_from_id_htmltext e_boolean_replace_from_id_htmltext = new Htmldoc.Class_boolean_replace_from_id_htmltext();
  public static final Func_boolean_replace_from_id_htmltext t_boolean_replace_from_id_htmltext = new Htmldoc.Class_boolean_replace_from_id_htmltext();

  public static Core.Type_boolean f_boolean_replace_from_id_htmltext(final Core.Type_string id, final Core.Type_string htmltext) {
    Core.Type_boolean output = Core.e_boolean;
    return output;
  }

  /**
   * @function boolean_replace_from_id_htmltext_data_eventmap
   * Replaces an html node with given id and text.
   * @param  {string} id
   * @param  {string} htmltext
   * @param  {any} data
   * @param  {eventmap} eventmap
   * @return {boolean}
   * (func boolean-replace<-id-htmltext-data-eventmap)
   */
  public static interface Func_boolean_replace_from_id_htmltext_data_eventmap extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean vx_boolean_replace_from_id_htmltext_data_eventmap(final Core.Type_string id, final Core.Type_string htmltext, final Core.Type_any data, final Event.Type_eventmap eventmap);
  }

  public static class Class_boolean_replace_from_id_htmltext_data_eventmap extends Core.Class_base implements Func_boolean_replace_from_id_htmltext_data_eventmap {

    @Override
    public Func_boolean_replace_from_id_htmltext_data_eventmap vx_new(Object... vals) {
      Class_boolean_replace_from_id_htmltext_data_eventmap output = new Class_boolean_replace_from_id_htmltext_data_eventmap();
      return output;
    }

    @Override
    public Func_boolean_replace_from_id_htmltext_data_eventmap vx_copy(Object... vals) {
      Class_boolean_replace_from_id_htmltext_data_eventmap output = new Class_boolean_replace_from_id_htmltext_data_eventmap();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-replace<-id-htmltext-data-eventmap", // name
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
    public Func_boolean_replace_from_id_htmltext_data_eventmap vx_empty() {return e_boolean_replace_from_id_htmltext_data_eventmap;}
    @Override
    public Func_boolean_replace_from_id_htmltext_data_eventmap vx_type() {return t_boolean_replace_from_id_htmltext_data_eventmap;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string id = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string htmltext = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      Core.Type_any data = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(2)));
      Event.Type_eventmap eventmap = Core.f_any_from_any(Event.t_eventmap, arglist.vx_any(Core.vx_new_int(3)));
      output = Htmldoc.f_boolean_replace_from_id_htmltext_data_eventmap(id, htmltext, data, eventmap);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_replace_from_id_htmltext_data_eventmap(final Core.Type_string id, final Core.Type_string htmltext, final Core.Type_any data, final Event.Type_eventmap eventmap) {
      return Htmldoc.f_boolean_replace_from_id_htmltext_data_eventmap(id, htmltext, data, eventmap);
    }

  }

  public static final Func_boolean_replace_from_id_htmltext_data_eventmap e_boolean_replace_from_id_htmltext_data_eventmap = new Htmldoc.Class_boolean_replace_from_id_htmltext_data_eventmap();
  public static final Func_boolean_replace_from_id_htmltext_data_eventmap t_boolean_replace_from_id_htmltext_data_eventmap = new Htmldoc.Class_boolean_replace_from_id_htmltext_data_eventmap();

  public static Core.Type_boolean f_boolean_replace_from_id_htmltext_data_eventmap(final Core.Type_string id, final Core.Type_string htmltext, final Core.Type_any data, final Event.Type_eventmap eventmap) {
    Core.Type_boolean output = Core.e_boolean;
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
  public static interface Func_boolean_write_stylesheet_from_string extends Core.Func_any_from_any_async {
    public CompletableFuture<Core.Type_boolean> vx_boolean_write_stylesheet_from_string(final Core.Type_string text);
  }

  public static class Class_boolean_write_stylesheet_from_string extends Core.Class_base implements Func_boolean_write_stylesheet_from_string {

    @Override
    public Func_boolean_write_stylesheet_from_string vx_new(Object... vals) {
      Class_boolean_write_stylesheet_from_string output = new Class_boolean_write_stylesheet_from_string();
      return output;
    }

    @Override
    public Func_boolean_write_stylesheet_from_string vx_copy(Object... vals) {
      Class_boolean_write_stylesheet_from_string output = new Class_boolean_write_stylesheet_from_string();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-write-stylesheet<-string", // name
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
    public Func_boolean_write_stylesheet_from_string vx_empty() {return e_boolean_write_stylesheet_from_string;}
    @Override
    public Func_boolean_write_stylesheet_from_string vx_type() {return t_boolean_write_stylesheet_from_string;}

    @Override
    public Core.Func_any_from_any_async vx_fn_new(Core.Class_any_from_any_async.IFn fn) {return Core.e_any_from_any_async;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> vx_any_from_any_async(final T generic_any_1, final U value) {
      Core.Type_string inputval = Core.f_any_from_any(Core.t_string, value);
      CompletableFuture<Core.Type_boolean> future = Htmldoc.f_boolean_write_stylesheet_from_string(inputval);
      @SuppressWarnings("unchecked")
      CompletableFuture<T> output = (CompletableFuture<T>)future;
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      CompletableFuture<Core.Type_boolean> future = Htmldoc.f_boolean_write_stylesheet_from_string(text);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Core.Type_boolean> vx_boolean_write_stylesheet_from_string(final Core.Type_string text) {
      return Htmldoc.f_boolean_write_stylesheet_from_string(text);
    }

  }

  public static final Func_boolean_write_stylesheet_from_string e_boolean_write_stylesheet_from_string = new Htmldoc.Class_boolean_write_stylesheet_from_string();
  public static final Func_boolean_write_stylesheet_from_string t_boolean_write_stylesheet_from_string = new Htmldoc.Class_boolean_write_stylesheet_from_string();

  public static CompletableFuture<Core.Type_boolean> f_boolean_write_stylesheet_from_string(final Core.Type_string text) {
    CompletableFuture<Core.Type_boolean> output = Core.async_new_completed(Core.e_boolean);
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
  public static interface Func_boolean_write_from_id_htmltext extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean vx_boolean_write_from_id_htmltext(final Core.Type_string id, final Core.Type_string htmltext);
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
    public Core.Type_boolean vx_boolean_write_from_id_htmltext(final Core.Type_string id, final Core.Type_string htmltext) {
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
   * Writes a css stylesheet.
   * @param  {stylesheet} stylesheet
   * @return {boolean}
   * (func boolean-write<-stylesheet)
   */
  public static interface Func_boolean_write_from_stylesheet extends Core.Func_any_from_any_async {
    public CompletableFuture<Core.Type_boolean> vx_boolean_write_from_stylesheet(final Html.Type_stylesheet stylesheet);
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
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> vx_any_from_any_async(final T generic_any_1, final U value) {
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
    public CompletableFuture<Core.Type_boolean> vx_boolean_write_from_stylesheet(final Html.Type_stylesheet stylesheet) {
      return Htmldoc.f_boolean_write_from_stylesheet(stylesheet);
    }

  }

  public static final Func_boolean_write_from_stylesheet e_boolean_write_from_stylesheet = new Htmldoc.Class_boolean_write_from_stylesheet();
  public static final Func_boolean_write_from_stylesheet t_boolean_write_from_stylesheet = new Htmldoc.Class_boolean_write_from_stylesheet();

  public static CompletableFuture<Core.Type_boolean> f_boolean_write_from_stylesheet(final Html.Type_stylesheet stylesheet) {
    CompletableFuture<Core.Type_boolean> output = Core.async_new_completed(Core.e_boolean);
    output = Core.f_let_async(
      Core.t_boolean,
      Core.t_any_from_func_async.vx_fn_new(() -> {
        final Html.Type_stylelist stylelist = Html.f_styles_from_stylesheet(stylesheet);
        final Core.Type_string text = Html.f_string_from_stylelist_indent(stylelist, Core.vx_new_int(0));
        final CompletableFuture<Core.Type_boolean> future_iswrite = Htmldoc.f_boolean_write_stylesheet_from_string(text);
        return Core.async_from_async_fn(future_iswrite, (iswrite) -> {
          return iswrite;
        });
      })
    );
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
    public Core.Type_string vx_string_from_id(final Core.Type_string id);
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
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
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
    public Core.Type_string vx_string_from_id(final Core.Type_string id) {
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
    Map<String, Core.Type_any> maptype = new LinkedHashMap<>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<>();
    mapfunc.put("any-data<-id", Htmldoc.t_any_data_from_id);
    mapfunc.put("boolean-replace<-id-htmltext", Htmldoc.t_boolean_replace_from_id_htmltext);
    mapfunc.put("boolean-replace<-id-htmltext-data-eventmap", Htmldoc.t_boolean_replace_from_id_htmltext_data_eventmap);
    mapfunc.put("boolean-write-stylesheet<-string", Htmldoc.t_boolean_write_stylesheet_from_string);
    mapfunc.put("boolean-write<-id-htmltext", Htmldoc.t_boolean_write_from_id_htmltext);
    mapfunc.put("boolean-write<-stylesheet", Htmldoc.t_boolean_write_from_stylesheet);
    mapfunc.put("string<-id", Htmldoc.t_string_from_id);
    Core.vx_global_package_set("vx/web/htmldoc", maptype, mapconst, mapfunc);
  }

}
