package com.vxlisp.vx.web;

import java.util.ArrayList;
import java.util.concurrent.CompletableFuture;
import java.util.LinkedHashMap;
import java.util.Map;
import com.vxlisp.vx.*;
import com.vxlisp.vx.data.*;

public final class Http {


  /**
   * type: response
   * (type response)
   */
  public interface Type_response extends Core.Type_struct {
    public Http.Type_response vx_new(final Object... vals);
    public Http.Type_response vx_copy(final Object... vals);
    public Http.Type_response vx_empty();
    public Http.Type_response vx_type();
    public Core.Type_boolean ok();
    public Core.Type_int status();
  }

  public static class Class_response extends Core.Class_base implements Type_response {

    protected Core.Type_boolean vx_p_ok;

    @Override
    public Core.Type_boolean ok() {
      return this.vx_p_ok == null ? Core.e_boolean : this.vx_p_ok;
    }

    protected Core.Type_int vx_p_status;

    @Override
    public Core.Type_int status() {
      return this.vx_p_status == null ? Core.e_int : this.vx_p_status;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":ok":
        output = this.ok();
        break;
      case ":status":
        output = this.status();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":ok", this.ok());
      output.put(":status", this.status());
      return Core.immutablemap(output);
    }

    @Override
    public Type_response vx_new(final Object... vals) {return e_response.vx_copy(vals);}

    @Override
    public Type_response vx_copy(final Object... vals) {
      Type_response output = this;
      boolean ischanged = false;
      Class_response val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_boolean vx_p_ok = val.ok();
      Core.Type_int vx_p_status = val.status();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":ok");
      validkeys.add(":status");
      String key = "";
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            String svalsub;
            if (valsub instanceof Core.Type_any) {
              Core.Type_any anyvalsub = (Core.Type_any)valsub;
              svalsub = Core.vx_string_from_any(anyvalsub);
            } else {
              svalsub = valsub.toString();
            }
            msg = Core.vx_msg_from_error(":invalidkeytype (new response) " + svalsub);
            msgblock = msgblock.vx_copy(msg);
          }
          if (istestkey) {
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msg = Core.vx_msg_from_error(":invalidkey (new response) " + testkey);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":ok":
            if (valsub == vx_p_ok) {
            } else if (valsub instanceof Core.Type_boolean) {
              ischanged = true;
              vx_p_ok = (Core.Type_boolean)valsub;
            } else if (valsub instanceof Boolean) {
              ischanged = true;
              vx_p_ok = Core.t_boolean.vx_new(valsub);
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new response :ok " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":status":
            if (valsub == vx_p_status) {
            } else if (valsub instanceof Core.Type_int) {
              ischanged = true;
              vx_p_status = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_status = Core.t_int.vx_new(valsub);
            } else {
              msg = Core.vx_msg_from_error(":invalidvalue (new response :status " + valsub.toString() + ")");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            msg = Core.vx_msg_from_error(":invalidkey (new response) " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_response work = new Class_response();
        work.vx_p_ok = vx_p_ok;
        work.vx_p_status = vx_p_status;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_response vx_empty() {return e_response;}
    @Override
    public Type_response vx_type() {return t_response;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/web/http", // pkgname
        "response", // name
        ":struct", // extends
        Core.e_typelist, // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_response e_response = new Class_response();
  public static final Type_response t_response = new Class_response();
  /**
   * 
   * @async
   * @function csv_from_httpget
   * Returns a csv file from an httpget
   * @param  {string} url
   * @return {csv}
   * (func csv<-httpget)
   */
  public static interface Func_csv_from_httpget extends Core.Func_any_from_any_async {
    public CompletableFuture<Csv.Type_csv> vx_csv_from_httpget(final Core.Type_string url);
  }

  public static class Class_csv_from_httpget extends Core.Class_base implements Func_csv_from_httpget {

    @Override
    public Func_csv_from_httpget vx_new(Object... vals) {
      Class_csv_from_httpget output = new Class_csv_from_httpget();
      return output;
    }

    @Override
    public Func_csv_from_httpget vx_copy(Object... vals) {
      Class_csv_from_httpget output = new Class_csv_from_httpget();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/web/http", // pkgname
        "csv<-httpget", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/data/csv", // pkgname
          "csv", // name
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
    public Func_csv_from_httpget vx_empty() {return e_csv_from_httpget;}
    @Override
    public Func_csv_from_httpget vx_type() {return t_csv_from_httpget;}

    @Override
    public Core.Func_any_from_any_async vx_fn_new(Core.Class_any_from_any_async.IFn fn) {return Core.e_any_from_any_async;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> vx_any_from_any_async(final T generic_any_1, final U value) {
      Core.Type_string inputval = Core.f_any_from_any(Core.t_string, value);
      CompletableFuture<Csv.Type_csv> future = Http.f_csv_from_httpget(inputval);
      @SuppressWarnings("unchecked")
      CompletableFuture<T> output = (CompletableFuture<T>)future;
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Core.Type_string url = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      CompletableFuture<Csv.Type_csv> future = Http.f_csv_from_httpget(url);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Csv.Type_csv> vx_csv_from_httpget(final Core.Type_string url) {
      return Http.f_csv_from_httpget(url);
    }

  }

  public static final Func_csv_from_httpget e_csv_from_httpget = new Http.Class_csv_from_httpget();
  public static final Func_csv_from_httpget t_csv_from_httpget = new Http.Class_csv_from_httpget();

  public static CompletableFuture<Csv.Type_csv> f_csv_from_httpget(final Core.Type_string url) {
    CompletableFuture<Csv.Type_csv> output = Core.async_new_completed(Csv.e_csv);
    output = Core.f_let_async(
      Csv.t_csv,
      Core.t_any_from_func_async.vx_fn_new(() -> {
        final CompletableFuture<Textblock.Type_textblock> future_textblock = Http.f_textblock_from_httpget(url, Core.vx_new_string("text/csv"));
        return Core.async_from_async_fn(future_textblock, (textblock) -> {
          return Csv.f_csv_from_textblock(textblock);
        });
      })
    );
    return output;
  }

  /**
   * 
   * @async
   * @function json_from_httpget
   * Returns a json response from an httpget
   * @param  {string} url
   * @return {response}
   * (func json<-httpget)
   */
  public static interface Func_json_from_httpget extends Core.Func_any_from_any_async {
    public CompletableFuture<Http.Type_response> vx_json_from_httpget(final Core.Type_string url);
  }

  public static class Class_json_from_httpget extends Core.Class_base implements Func_json_from_httpget {

    @Override
    public Func_json_from_httpget vx_new(Object... vals) {
      Class_json_from_httpget output = new Class_json_from_httpget();
      return output;
    }

    @Override
    public Func_json_from_httpget vx_copy(Object... vals) {
      Class_json_from_httpget output = new Class_json_from_httpget();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/web/http", // pkgname
        "json<-httpget", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/web/http", // pkgname
          "response", // name
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
    public Func_json_from_httpget vx_empty() {return e_json_from_httpget;}
    @Override
    public Func_json_from_httpget vx_type() {return t_json_from_httpget;}

    @Override
    public Core.Func_any_from_any_async vx_fn_new(Core.Class_any_from_any_async.IFn fn) {return Core.e_any_from_any_async;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> vx_any_from_any_async(final T generic_any_1, final U value) {
      Core.Type_string inputval = Core.f_any_from_any(Core.t_string, value);
      CompletableFuture<Http.Type_response> future = Http.f_json_from_httpget(inputval);
      @SuppressWarnings("unchecked")
      CompletableFuture<T> output = (CompletableFuture<T>)future;
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Core.Type_string url = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      CompletableFuture<Http.Type_response> future = Http.f_json_from_httpget(url);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Http.Type_response> vx_json_from_httpget(final Core.Type_string url) {
      return Http.f_json_from_httpget(url);
    }

  }

  public static final Func_json_from_httpget e_json_from_httpget = new Http.Class_json_from_httpget();
  public static final Func_json_from_httpget t_json_from_httpget = new Http.Class_json_from_httpget();

  public static CompletableFuture<Http.Type_response> f_json_from_httpget(final Core.Type_string url) {
    CompletableFuture<Http.Type_response> output = Core.async_new_completed(Http.e_response);
    output = Core.f_let_async(
      Http.t_response,
      Core.t_any_from_func_async.vx_fn_new(() -> {
        final CompletableFuture<Http.Type_response> future_response = Http.f_response_from_httpget(url, Core.vx_new_string("application/json"));
        return Core.async_from_async_fn(future_response, (response) -> {
          return response;
        });
      })
    );
    return output;
  }

  /**
   * 
   * @async
   * @function response_from_httpget
   * Returns a response from an httpget
   * @param  {string} url
   * @param  {string} contenttype
   * @return {response}
   * (func response<-httpget)
   */
  public static interface Func_response_from_httpget extends Core.Type_func, Core.Type_replfunc_async {
    public CompletableFuture<Http.Type_response> vx_response_from_httpget(final Core.Type_string url, final Core.Type_string contenttype);
  }

  public static class Class_response_from_httpget extends Core.Class_base implements Func_response_from_httpget {

    @Override
    public Func_response_from_httpget vx_new(Object... vals) {
      Class_response_from_httpget output = new Class_response_from_httpget();
      return output;
    }

    @Override
    public Func_response_from_httpget vx_copy(Object... vals) {
      Class_response_from_httpget output = new Class_response_from_httpget();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/web/http", // pkgname
        "response<-httpget", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/web/http", // pkgname
          "response", // name
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
    public Func_response_from_httpget vx_empty() {return e_response_from_httpget;}
    @Override
    public Func_response_from_httpget vx_type() {return t_response_from_httpget;}

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Core.Type_string url = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string contenttype = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      CompletableFuture<Http.Type_response> future = Http.f_response_from_httpget(url, contenttype);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Http.Type_response> vx_response_from_httpget(final Core.Type_string url, final Core.Type_string contenttype) {
      return Http.f_response_from_httpget(url, contenttype);
    }

  }

  public static final Func_response_from_httpget e_response_from_httpget = new Http.Class_response_from_httpget();
  public static final Func_response_from_httpget t_response_from_httpget = new Http.Class_response_from_httpget();

  public static CompletableFuture<Http.Type_response> f_response_from_httpget(final Core.Type_string url, final Core.Type_string contenttype) {
    CompletableFuture<Http.Type_response> output = Core.async_new_completed(Http.e_response);
    return output;
  }

  /**
   * 
   * @async
   * @function text_from_httpget
   * Returns string from an httpget
   * @param  {string} url
   * @return {string}
   * (func text<-httpget)
   */
  public static interface Func_text_from_httpget extends Core.Func_any_from_any_async {
    public CompletableFuture<Core.Type_string> vx_text_from_httpget(final Core.Type_string url);
  }

  public static class Class_text_from_httpget extends Core.Class_base implements Func_text_from_httpget {

    @Override
    public Func_text_from_httpget vx_new(Object... vals) {
      Class_text_from_httpget output = new Class_text_from_httpget();
      return output;
    }

    @Override
    public Func_text_from_httpget vx_copy(Object... vals) {
      Class_text_from_httpget output = new Class_text_from_httpget();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/web/http", // pkgname
        "text<-httpget", // name
        0, // idx
        true, // async
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
    public Func_text_from_httpget vx_empty() {return e_text_from_httpget;}
    @Override
    public Func_text_from_httpget vx_type() {return t_text_from_httpget;}

    @Override
    public Core.Func_any_from_any_async vx_fn_new(Core.Class_any_from_any_async.IFn fn) {return Core.e_any_from_any_async;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> vx_any_from_any_async(final T generic_any_1, final U value) {
      Core.Type_string inputval = Core.f_any_from_any(Core.t_string, value);
      CompletableFuture<Core.Type_string> future = Http.f_text_from_httpget(inputval);
      @SuppressWarnings("unchecked")
      CompletableFuture<T> output = (CompletableFuture<T>)future;
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Core.Type_string url = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      CompletableFuture<Core.Type_string> future = Http.f_text_from_httpget(url);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Core.Type_string> vx_text_from_httpget(final Core.Type_string url) {
      return Http.f_text_from_httpget(url);
    }

  }

  public static final Func_text_from_httpget e_text_from_httpget = new Http.Class_text_from_httpget();
  public static final Func_text_from_httpget t_text_from_httpget = new Http.Class_text_from_httpget();

  public static CompletableFuture<Core.Type_string> f_text_from_httpget(final Core.Type_string url) {
    CompletableFuture<Core.Type_string> output = Core.async_new_completed(Core.e_string);
    output = Core.f_let_async(
      Core.t_string,
      Core.t_any_from_func_async.vx_fn_new(() -> {
        final CompletableFuture<Http.Type_response> future_response = Http.f_response_from_httpget(url, Core.vx_new_string("text/plain"));
        return Core.async_from_async_fn(future_response, (response) -> {
          return Http.f_text_from_response(response);
        });
      })
    );
    return output;
  }

  /**
   * @function text_from_response
   * Returns a string from a response
   * @param  {response} response
   * @return {string}
   * (func text<-response)
   */
  public static interface Func_text_from_response extends Core.Func_any_from_any {
    public Core.Type_string vx_text_from_response(final Http.Type_response response);
  }

  public static class Class_text_from_response extends Core.Class_base implements Func_text_from_response {

    @Override
    public Func_text_from_response vx_new(Object... vals) {
      Class_text_from_response output = new Class_text_from_response();
      return output;
    }

    @Override
    public Func_text_from_response vx_copy(Object... vals) {
      Class_text_from_response output = new Class_text_from_response();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/web/http", // pkgname
        "text<-response", // name
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
    public Func_text_from_response vx_empty() {return e_text_from_response;}
    @Override
    public Func_text_from_response vx_type() {return t_text_from_response;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Http.Type_response inputval = (Http.Type_response)value;
      Core.Type_any outputval = Http.f_text_from_response(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Http.Type_response response = Core.f_any_from_any(Http.t_response, arglist.vx_any(Core.vx_new_int(0)));
      output = Http.f_text_from_response(response);
      return output;
    }

    @Override
    public Core.Type_string vx_text_from_response(final Http.Type_response response) {
      return Http.f_text_from_response(response);
    }

  }

  public static final Func_text_from_response e_text_from_response = new Http.Class_text_from_response();
  public static final Func_text_from_response t_text_from_response = new Http.Class_text_from_response();

  public static Core.Type_string f_text_from_response(final Http.Type_response response) {
    Core.Type_string output = Core.e_string;
    return output;
  }

  /**
   * 
   * @async
   * @function textblock_from_httpget
   * Returns a textblock from an httpget
   * @param  {string} url
   * @param  {string} contenttype
   * @return {textblock}
   * (func textblock<-httpget)
   */
  public static interface Func_textblock_from_httpget extends Core.Type_func, Core.Type_replfunc_async {
    public CompletableFuture<Textblock.Type_textblock> vx_textblock_from_httpget(final Core.Type_string url, final Core.Type_string contenttype);
  }

  public static class Class_textblock_from_httpget extends Core.Class_base implements Func_textblock_from_httpget {

    @Override
    public Func_textblock_from_httpget vx_new(Object... vals) {
      Class_textblock_from_httpget output = new Class_textblock_from_httpget();
      return output;
    }

    @Override
    public Func_textblock_from_httpget vx_copy(Object... vals) {
      Class_textblock_from_httpget output = new Class_textblock_from_httpget();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/web/http", // pkgname
        "textblock<-httpget", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
    public Func_textblock_from_httpget vx_empty() {return e_textblock_from_httpget;}
    @Override
    public Func_textblock_from_httpget vx_type() {return t_textblock_from_httpget;}

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Core.Type_string url = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string contenttype = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      CompletableFuture<Textblock.Type_textblock> future = Http.f_textblock_from_httpget(url, contenttype);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Textblock.Type_textblock> vx_textblock_from_httpget(final Core.Type_string url, final Core.Type_string contenttype) {
      return Http.f_textblock_from_httpget(url, contenttype);
    }

  }

  public static final Func_textblock_from_httpget e_textblock_from_httpget = new Http.Class_textblock_from_httpget();
  public static final Func_textblock_from_httpget t_textblock_from_httpget = new Http.Class_textblock_from_httpget();

  public static CompletableFuture<Textblock.Type_textblock> f_textblock_from_httpget(final Core.Type_string url, final Core.Type_string contenttype) {
    CompletableFuture<Textblock.Type_textblock> output = Core.async_new_completed(Textblock.e_textblock);
    output = Core.f_let_async(
      Textblock.t_textblock,
      Core.t_any_from_func_async.vx_fn_new(() -> {
        final CompletableFuture<Http.Type_response> future_response = Http.f_response_from_httpget(url, contenttype);
        return Core.async_from_async_fn(future_response, (response) -> {
          return Http.f_textblock_from_response(response);
        });
      })
    );
    return output;
  }

  /**
   * @function textblock_from_response
   * Returns a textblock from a response
   * @param  {response} response
   * @return {textblock}
   * (func textblock<-response)
   */
  public static interface Func_textblock_from_response extends Core.Func_any_from_any {
    public Textblock.Type_textblock vx_textblock_from_response(final Http.Type_response response);
  }

  public static class Class_textblock_from_response extends Core.Class_base implements Func_textblock_from_response {

    @Override
    public Func_textblock_from_response vx_new(Object... vals) {
      Class_textblock_from_response output = new Class_textblock_from_response();
      return output;
    }

    @Override
    public Func_textblock_from_response vx_copy(Object... vals) {
      Class_textblock_from_response output = new Class_textblock_from_response();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/web/http", // pkgname
        "textblock<-response", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
    public Func_textblock_from_response vx_empty() {return e_textblock_from_response;}
    @Override
    public Func_textblock_from_response vx_type() {return t_textblock_from_response;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Http.Type_response inputval = (Http.Type_response)value;
      Core.Type_any outputval = Http.f_textblock_from_response(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Http.Type_response response = Core.f_any_from_any(Http.t_response, arglist.vx_any(Core.vx_new_int(0)));
      output = Http.f_textblock_from_response(response);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_from_response(final Http.Type_response response) {
      return Http.f_textblock_from_response(response);
    }

  }

  public static final Func_textblock_from_response e_textblock_from_response = new Http.Class_textblock_from_response();
  public static final Func_textblock_from_response t_textblock_from_response = new Http.Class_textblock_from_response();

  public static Textblock.Type_textblock f_textblock_from_response(final Http.Type_response response) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Core.f_new(
      Textblock.t_textblock,
      Core.t_anylist.vx_new(
        Core.vx_new_string(":text"),
        Http.f_text_from_response(response)
      )
    );
    return output;
  }

  /**
   * 
   * @async
   * @function xml_from_httpget
   * Return Xml from an httpget
   * @param  {string} url
   * @return {xml}
   * (func xml<-httpget)
   */
  public static interface Func_xml_from_httpget extends Core.Func_any_from_any_async {
    public CompletableFuture<Xml.Type_xml> vx_xml_from_httpget(final Core.Type_string url);
  }

  public static class Class_xml_from_httpget extends Core.Class_base implements Func_xml_from_httpget {

    @Override
    public Func_xml_from_httpget vx_new(Object... vals) {
      Class_xml_from_httpget output = new Class_xml_from_httpget();
      return output;
    }

    @Override
    public Func_xml_from_httpget vx_copy(Object... vals) {
      Class_xml_from_httpget output = new Class_xml_from_httpget();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/web/http", // pkgname
        "xml<-httpget", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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
    public Func_xml_from_httpget vx_empty() {return e_xml_from_httpget;}
    @Override
    public Func_xml_from_httpget vx_type() {return t_xml_from_httpget;}

    @Override
    public Core.Func_any_from_any_async vx_fn_new(Core.Class_any_from_any_async.IFn fn) {return Core.e_any_from_any_async;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> vx_any_from_any_async(final T generic_any_1, final U value) {
      Core.Type_string inputval = Core.f_any_from_any(Core.t_string, value);
      CompletableFuture<Xml.Type_xml> future = Http.f_xml_from_httpget(inputval);
      @SuppressWarnings("unchecked")
      CompletableFuture<T> output = (CompletableFuture<T>)future;
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Core.Type_string url = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      CompletableFuture<Xml.Type_xml> future = Http.f_xml_from_httpget(url);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Xml.Type_xml> vx_xml_from_httpget(final Core.Type_string url) {
      return Http.f_xml_from_httpget(url);
    }

  }

  public static final Func_xml_from_httpget e_xml_from_httpget = new Http.Class_xml_from_httpget();
  public static final Func_xml_from_httpget t_xml_from_httpget = new Http.Class_xml_from_httpget();

  public static CompletableFuture<Xml.Type_xml> f_xml_from_httpget(final Core.Type_string url) {
    CompletableFuture<Xml.Type_xml> output = Core.async_new_completed(Xml.e_xml);
    output = Core.f_let_async(
      Xml.t_xml,
      Core.t_any_from_func_async.vx_fn_new(() -> {
        final CompletableFuture<Textblock.Type_textblock> future_textblock = Http.f_textblock_from_httpget(url, Core.vx_new_string("text/xml"));
        return Core.async_from_async_fn(future_textblock, (textblock) -> {
          return Xml.f_xml_from_textblock(textblock);
        });
      })
    );
    return output;
  }


  static {
    Map<String, Core.Type_any> maptype = new LinkedHashMap<>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<>();
    maptype.put("response", Http.t_response);
    mapfunc.put("csv<-httpget", Http.t_csv_from_httpget);
    mapfunc.put("json<-httpget", Http.t_json_from_httpget);
    mapfunc.put("response<-httpget", Http.t_response_from_httpget);
    mapfunc.put("text<-httpget", Http.t_text_from_httpget);
    mapfunc.put("text<-response", Http.t_text_from_response);
    mapfunc.put("textblock<-httpget", Http.t_textblock_from_httpget);
    mapfunc.put("textblock<-response", Http.t_textblock_from_response);
    mapfunc.put("xml<-httpget", Http.t_xml_from_httpget);
    Core.vx_global_package_set("vx/web/http", maptype, mapconst, mapfunc);
  }

}
