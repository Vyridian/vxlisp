package com.vxlisp.vx.web;

import java.util.concurrent.CompletableFuture;
import java.util.LinkedHashMap;
import java.util.Map;
import com.vxlisp.vx.*;
import com.vxlisp.vx.ui.*;

public final class Htmldoc {

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
   * @function boolean_replace_from_ui_htmltext
   * Replaces an html node with given id and text.
   * @param  {ui} ui
   * @param  {string} htmltext
   * @return {boolean}
   * (func boolean-replace<-ui-htmltext)
   */
  public static interface Func_boolean_replace_from_ui_htmltext extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean vx_boolean_replace_from_ui_htmltext(final Ui.Type_ui ui, final Core.Type_string htmltext);
  }

  public static class Class_boolean_replace_from_ui_htmltext extends Core.Class_base implements Func_boolean_replace_from_ui_htmltext {

    @Override
    public Func_boolean_replace_from_ui_htmltext vx_new(Object... vals) {
      Class_boolean_replace_from_ui_htmltext output = new Class_boolean_replace_from_ui_htmltext();
      return output;
    }

    @Override
    public Func_boolean_replace_from_ui_htmltext vx_copy(Object... vals) {
      Class_boolean_replace_from_ui_htmltext output = new Class_boolean_replace_from_ui_htmltext();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-replace<-ui-htmltext", // name
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
    public Func_boolean_replace_from_ui_htmltext vx_empty() {return e_boolean_replace_from_ui_htmltext;}
    @Override
    public Func_boolean_replace_from_ui_htmltext vx_type() {return t_boolean_replace_from_ui_htmltext;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Ui.Type_ui ui = Core.f_any_from_any(Ui.t_ui, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string htmltext = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Htmldoc.f_boolean_replace_from_ui_htmltext(ui, htmltext);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_replace_from_ui_htmltext(final Ui.Type_ui ui, final Core.Type_string htmltext) {
      return Htmldoc.f_boolean_replace_from_ui_htmltext(ui, htmltext);
    }

  }

  public static final Func_boolean_replace_from_ui_htmltext e_boolean_replace_from_ui_htmltext = new Htmldoc.Class_boolean_replace_from_ui_htmltext();
  public static final Func_boolean_replace_from_ui_htmltext t_boolean_replace_from_ui_htmltext = new Htmldoc.Class_boolean_replace_from_ui_htmltext();

  public static Core.Type_boolean f_boolean_replace_from_ui_htmltext(final Ui.Type_ui ui, final Core.Type_string htmltext) {
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
   * @function context_read
   * Reads context from document.data.context
   * @return {context}
   * (func context-read)
   */
  public static interface Func_context_read extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_context vx_context_read();
  }

  public static class Class_context_read extends Core.Class_base implements Func_context_read {

    @Override
    public Func_context_read vx_new(Object... vals) {
      Class_context_read output = new Class_context_read();
      return output;
    }

    @Override
    public Func_context_read vx_copy(Object... vals) {
      Class_context_read output = new Class_context_read();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "context-read", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "context", // name
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
    public Func_context_read vx_empty() {return e_context_read;}
    @Override
    public Func_context_read vx_type() {return t_context_read;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      output = Htmldoc.f_context_read();
      return output;
    }

    @Override
    public Core.Type_context vx_context_read() {
      return Htmldoc.f_context_read();
    }

  }

  public static final Func_context_read e_context_read = new Htmldoc.Class_context_read();
  public static final Func_context_read t_context_read = new Htmldoc.Class_context_read();

  public static Core.Type_context f_context_read() {
    Core.Type_context output = Core.e_context;
    return output;
  }

  /**
   * @function context_write
   * Writes context to document.data.context
   * @return {context}
   * (func context-write)
   */
  public static interface Func_context_write extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_context vx_context_write(final Core.Type_context context);
  }

  public static class Class_context_write extends Core.Class_base implements Func_context_write {

    @Override
    public Func_context_write vx_new(Object... vals) {
      Class_context_write output = new Class_context_write();
      return output;
    }

    @Override
    public Func_context_write vx_copy(Object... vals) {
      Class_context_write output = new Class_context_write();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "context-write", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "context", // name
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
    public Func_context_write vx_empty() {return e_context_write;}
    @Override
    public Func_context_write vx_type() {return t_context_write;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      output = Htmldoc.f_context_write(context);
      return output;
    }

    @Override
    public Core.Type_context vx_context_write(final Core.Type_context context) {
      return Htmldoc.f_context_write(context);
    }

  }

  public static final Func_context_write e_context_write = new Htmldoc.Class_context_write();
  public static final Func_context_write t_context_write = new Htmldoc.Class_context_write();

  public static Core.Type_context f_context_write(final Core.Type_context context) {
    Core.Type_context output = Core.e_context;
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

  /**
   * @function ui_readstate_from_uid
   * Returns ui component from element.
   * @param  {string} uid
   * @return {any}
   * (func ui-readstate<-uid)
   */
  public static interface Func_ui_readstate_from_uid extends Core.Func_any_from_any {
    public Core.Type_any vx_ui_readstate_from_uid(final Core.Type_string uid);
  }

  public static class Class_ui_readstate_from_uid extends Core.Class_base implements Func_ui_readstate_from_uid {

    @Override
    public Func_ui_readstate_from_uid vx_new(Object... vals) {
      Class_ui_readstate_from_uid output = new Class_ui_readstate_from_uid();
      return output;
    }

    @Override
    public Func_ui_readstate_from_uid vx_copy(Object... vals) {
      Class_ui_readstate_from_uid output = new Class_ui_readstate_from_uid();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/web/htmldoc", // pkgname
        "ui-readstate<-uid", // name
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
    public Func_ui_readstate_from_uid vx_empty() {return e_ui_readstate_from_uid;}
    @Override
    public Func_ui_readstate_from_uid vx_type() {return t_ui_readstate_from_uid;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Htmldoc.f_ui_readstate_from_uid(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string uid = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Htmldoc.f_ui_readstate_from_uid(uid);
      return output;
    }

    @Override
    public Core.Type_any vx_ui_readstate_from_uid(final Core.Type_string uid) {
      return Htmldoc.f_ui_readstate_from_uid(uid);
    }

  }

  public static final Func_ui_readstate_from_uid e_ui_readstate_from_uid = new Htmldoc.Class_ui_readstate_from_uid();
  public static final Func_ui_readstate_from_uid t_ui_readstate_from_uid = new Htmldoc.Class_ui_readstate_from_uid();

  public static Core.Type_any f_ui_readstate_from_uid(final Core.Type_string uid) {
    Core.Type_any output = Core.e_any;
    return output;
  }


  static {
    Map<String, Core.Type_any> maptype = new LinkedHashMap<>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<>();
    mapfunc.put("boolean-replace<-id-htmltext", Htmldoc.t_boolean_replace_from_id_htmltext);
    mapfunc.put("boolean-replace<-ui-htmltext", Htmldoc.t_boolean_replace_from_ui_htmltext);
    mapfunc.put("boolean-write-stylesheet<-string", Htmldoc.t_boolean_write_stylesheet_from_string);
    mapfunc.put("boolean-write<-id-htmltext", Htmldoc.t_boolean_write_from_id_htmltext);
    mapfunc.put("boolean-write<-stylesheet", Htmldoc.t_boolean_write_from_stylesheet);
    mapfunc.put("context-read", Htmldoc.t_context_read);
    mapfunc.put("context-write", Htmldoc.t_context_write);
    mapfunc.put("string<-id", Htmldoc.t_string_from_id);
    mapfunc.put("ui-readstate<-uid", Htmldoc.t_ui_readstate_from_uid);
    Core.vx_global_package_set("vx/web/htmldoc", maptype, mapconst, mapfunc);
  }

}
