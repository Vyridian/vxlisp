namespace Vx.Web;

public static class Http {


  /**
   * type: response
   * (type response)
   */
  public interface Type_response : Vx.Core.Type_struct {
    public Vx.Core.Type_boolean ok();
    public Vx.Core.Type_int status();
  }

  public class Class_response : Vx.Core.Class_base, Type_response {

    public Vx.Core.Type_boolean? vx_p_ok = null;

    public Vx.Core.Type_boolean ok() {
      Vx.Core.Type_boolean output = Vx.Core.e_boolean;
      if (this.vx_p_ok != null) {
        output = this.vx_p_ok;
      }
      return output;
    }

    public Vx.Core.Type_int? vx_p_status = null;

    public Vx.Core.Type_int status() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_status != null) {
        output = this.vx_p_status;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":ok", this.ok());
      output.put(":status", this.status());
      output = Vx.Core.immutablemap(output);
      return output;
    }

    public override Vx.Web.Http.Type_response vx_new(params object[] vals) {
      Vx.Web.Http.Type_response output = Vx.Core.vx_copy(Vx.Web.Http.e_response, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Web.Http.Type_response output = this;
      bool ischanged = false;
      Vx.Web.Http.Class_response value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_boolean vx_p_ok = value.ok();
      Vx.Core.Type_int vx_p_status = value.status();
      List<string> validkeys = new List<string>();
      validkeys.Add(":ok");
      validkeys.Add(":status");
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/web/http/response", ":invalidkeytype", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.StartsWith(":")) {
              testkey = ":" + testkey;
            }
            bool isvalidkey = validkeys.Contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Vx.Core.vx_new_string(testkey);
              msg = Vx.Core.vx_msg_from_error("vx/web/http/response", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":ok":
            if (valsub == vx_p_ok) {
            } else if (valsub is Vx.Core.Type_boolean valok) {
              ischanged = true;
              vx_p_ok = valok;
            } else if (valsub is bool) {
              ischanged = true;
              vx_p_ok = Vx.Core.vx_new(Vx.Core.t_boolean, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("ok"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/http/response", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":status":
            if (valsub == vx_p_status) {
            } else if (valsub is Vx.Core.Type_int valstatus) {
              ischanged = true;
              vx_p_status = valstatus;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_status = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("status"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/web/http/response", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/web/http/response", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Web.Http.Class_response work = new Vx.Web.Http.Class_response();
        work.vx_p_ok = vx_p_ok;
        work.vx_p_status = vx_p_status;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Web.Http.e_response;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Web.Http.t_response;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/web/http", // pkgname
        "response", // name
        ":struct", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.e_typelist, // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
      return output;
    }

  }

  public static Vx.Web.Http.Type_response e_response = new Vx.Web.Http.Class_response();
  public static Vx.Web.Http.Type_response t_response = new Vx.Web.Http.Class_response();
  /**
   * 
   * @async
   * @function csv_from_httpget
   * Returns a csv file from an httpget
   * @param  {string} url
   * @return {csv}
   * (func csv<-httpget)
   */
  public interface Func_csv_from_httpget : Vx.Core.Func_any_from_any_async {
    public Task<Vx.Data.Csv.Type_csv> vx_csv_from_httpget(Vx.Core.Type_string url);
  }

  public class Class_csv_from_httpget : Vx.Core.Class_base, Func_csv_from_httpget {

    public override Vx.Web.Http.Func_csv_from_httpget vx_new(params object[] vals) {
      Vx.Web.Http.Class_csv_from_httpget output = new Vx.Web.Http.Class_csv_from_httpget();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Web.Http.Class_csv_from_httpget output = new Vx.Web.Http.Class_csv_from_httpget();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/web/http", // pkgname
        "csv<-httpget", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/data/csv", // pkgname
          "csv", // name
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
      Vx.Core.Type_any output = Vx.Web.Http.e_csv_from_httpget;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Web.Http.t_csv_from_httpget;
      return output;
    }

    public Vx.Core.Func_any_from_any_async vx_fn_new(Vx.Core.Class_any_from_any_async.IFn fn) {
      return Vx.Core.e_any_from_any_async;
    }

    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      Vx.Core.Type_string inputval = Vx.Core.f_any_from_any(Vx.Core.t_string, value);
      Task<Vx.Data.Csv.Type_csv> future = Vx.Web.Http.f_csv_from_httpget(inputval);
      Task<T> output = Vx.Core.vx_async_from_async(generic_any_1, future);
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_from_value(Vx.Core.e_any);
      Vx.Core.Type_string url = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Task<Vx.Data.Csv.Type_csv> future = Vx.Web.Http.f_csv_from_httpget(url);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<Vx.Data.Csv.Type_csv> vx_csv_from_httpget(Vx.Core.Type_string url) {
      return Vx.Web.Http.f_csv_from_httpget(url);
    }

  }

  public static Vx.Web.Http.Func_csv_from_httpget e_csv_from_httpget = new Vx.Web.Http.Class_csv_from_httpget();
  public static Vx.Web.Http.Func_csv_from_httpget t_csv_from_httpget = new Vx.Web.Http.Class_csv_from_httpget();

  public static Task<Vx.Data.Csv.Type_csv> f_csv_from_httpget(Vx.Core.Type_string url) {
    Task<Vx.Data.Csv.Type_csv> output = Vx.Core.vx_async_new_from_value(Vx.Data.Csv.e_csv);
    output = Vx.Core.f_let_async(
      Vx.Data.Csv.t_csv,
      Vx.Core.t_any_from_func_async.vx_fn_new(() => {
        Task<Vx.Data.Textblock.Type_textblock> future_textblock = Vx.Web.Http.f_textblock_from_httpget(url, Vx.Core.vx_new_string("text/csv"));
        Task<Vx.Core.Type_any> output_1 = Vx.Core.vx_async_from_async_fn(future_textblock, (textblock) => {
          Vx.Core.Type_any output_2 = Vx.Data.Csv.f_csv_from_textblock(textblock);
          return output_2;
        });
        return output_1;
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
  public interface Func_json_from_httpget : Vx.Core.Func_any_from_any_async {
    public Task<Vx.Web.Http.Type_response> vx_json_from_httpget(Vx.Core.Type_string url);
  }

  public class Class_json_from_httpget : Vx.Core.Class_base, Func_json_from_httpget {

    public override Vx.Web.Http.Func_json_from_httpget vx_new(params object[] vals) {
      Vx.Web.Http.Class_json_from_httpget output = new Vx.Web.Http.Class_json_from_httpget();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Web.Http.Class_json_from_httpget output = new Vx.Web.Http.Class_json_from_httpget();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/web/http", // pkgname
        "json<-httpget", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/web/http", // pkgname
          "response", // name
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
      Vx.Core.Type_any output = Vx.Web.Http.e_json_from_httpget;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Web.Http.t_json_from_httpget;
      return output;
    }

    public Vx.Core.Func_any_from_any_async vx_fn_new(Vx.Core.Class_any_from_any_async.IFn fn) {
      return Vx.Core.e_any_from_any_async;
    }

    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      Vx.Core.Type_string inputval = Vx.Core.f_any_from_any(Vx.Core.t_string, value);
      Task<Vx.Web.Http.Type_response> future = Vx.Web.Http.f_json_from_httpget(inputval);
      Task<T> output = Vx.Core.vx_async_from_async(generic_any_1, future);
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_from_value(Vx.Core.e_any);
      Vx.Core.Type_string url = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Task<Vx.Web.Http.Type_response> future = Vx.Web.Http.f_json_from_httpget(url);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<Vx.Web.Http.Type_response> vx_json_from_httpget(Vx.Core.Type_string url) {
      return Vx.Web.Http.f_json_from_httpget(url);
    }

  }

  public static Vx.Web.Http.Func_json_from_httpget e_json_from_httpget = new Vx.Web.Http.Class_json_from_httpget();
  public static Vx.Web.Http.Func_json_from_httpget t_json_from_httpget = new Vx.Web.Http.Class_json_from_httpget();

  public static Task<Vx.Web.Http.Type_response> f_json_from_httpget(Vx.Core.Type_string url) {
    Task<Vx.Web.Http.Type_response> output = Vx.Core.vx_async_new_from_value(Vx.Web.Http.e_response);
    output = Vx.Core.f_let_async(
      Vx.Web.Http.t_response,
      Vx.Core.t_any_from_func_async.vx_fn_new(() => {
        Task<Vx.Web.Http.Type_response> future_response = Vx.Web.Http.f_response_from_httpget(url, Vx.Core.vx_new_string("application/json"));
        Task<Vx.Core.Type_any> output_1 = Vx.Core.vx_async_from_async_fn(future_response, (response) => {
          Vx.Core.Type_any output_2 = response;
          return output_2;
        });
        return output_1;
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
  public interface Func_response_from_httpget : Vx.Core.Type_func, Vx.Core.Type_replfunc_async {
    public Task<Vx.Web.Http.Type_response> vx_response_from_httpget(Vx.Core.Type_string url, Vx.Core.Type_string contenttype);
  }

  public class Class_response_from_httpget : Vx.Core.Class_base, Func_response_from_httpget {

    public override Vx.Web.Http.Func_response_from_httpget vx_new(params object[] vals) {
      Vx.Web.Http.Class_response_from_httpget output = new Vx.Web.Http.Class_response_from_httpget();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Web.Http.Class_response_from_httpget output = new Vx.Web.Http.Class_response_from_httpget();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/web/http", // pkgname
        "response<-httpget", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/web/http", // pkgname
          "response", // name
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
      Vx.Core.Type_any output = Vx.Web.Http.e_response_from_httpget;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Web.Http.t_response_from_httpget;
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_from_value(Vx.Core.e_any);
      Vx.Core.Type_string url = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string contenttype = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Task<Vx.Web.Http.Type_response> future = Vx.Web.Http.f_response_from_httpget(url, contenttype);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<Vx.Web.Http.Type_response> vx_response_from_httpget(Vx.Core.Type_string url, Vx.Core.Type_string contenttype) {
      return Vx.Web.Http.f_response_from_httpget(url, contenttype);
    }

  }

  public static Vx.Web.Http.Func_response_from_httpget e_response_from_httpget = new Vx.Web.Http.Class_response_from_httpget();
  public static Vx.Web.Http.Func_response_from_httpget t_response_from_httpget = new Vx.Web.Http.Class_response_from_httpget();

  public static Task<Vx.Web.Http.Type_response> f_response_from_httpget(Vx.Core.Type_string url, Vx.Core.Type_string contenttype) {
    Task<Vx.Web.Http.Type_response> output = Vx.Core.vx_async_new_from_value(Vx.Web.Http.e_response);
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
  public interface Func_text_from_httpget : Vx.Core.Func_any_from_any_async {
    public Task<Vx.Core.Type_string> vx_text_from_httpget(Vx.Core.Type_string url);
  }

  public class Class_text_from_httpget : Vx.Core.Class_base, Func_text_from_httpget {

    public override Vx.Web.Http.Func_text_from_httpget vx_new(params object[] vals) {
      Vx.Web.Http.Class_text_from_httpget output = new Vx.Web.Http.Class_text_from_httpget();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Web.Http.Class_text_from_httpget output = new Vx.Web.Http.Class_text_from_httpget();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/web/http", // pkgname
        "text<-httpget", // name
        0, // idx
        true, // async
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
      Vx.Core.Type_any output = Vx.Web.Http.e_text_from_httpget;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Web.Http.t_text_from_httpget;
      return output;
    }

    public Vx.Core.Func_any_from_any_async vx_fn_new(Vx.Core.Class_any_from_any_async.IFn fn) {
      return Vx.Core.e_any_from_any_async;
    }

    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      Vx.Core.Type_string inputval = Vx.Core.f_any_from_any(Vx.Core.t_string, value);
      Task<Vx.Core.Type_string> future = Vx.Web.Http.f_text_from_httpget(inputval);
      Task<T> output = Vx.Core.vx_async_from_async(generic_any_1, future);
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_from_value(Vx.Core.e_any);
      Vx.Core.Type_string url = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Task<Vx.Core.Type_string> future = Vx.Web.Http.f_text_from_httpget(url);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<Vx.Core.Type_string> vx_text_from_httpget(Vx.Core.Type_string url) {
      return Vx.Web.Http.f_text_from_httpget(url);
    }

  }

  public static Vx.Web.Http.Func_text_from_httpget e_text_from_httpget = new Vx.Web.Http.Class_text_from_httpget();
  public static Vx.Web.Http.Func_text_from_httpget t_text_from_httpget = new Vx.Web.Http.Class_text_from_httpget();

  public static Task<Vx.Core.Type_string> f_text_from_httpget(Vx.Core.Type_string url) {
    Task<Vx.Core.Type_string> output = Vx.Core.vx_async_new_from_value(Vx.Core.e_string);
    output = Vx.Core.f_let_async(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func_async.vx_fn_new(() => {
        Task<Vx.Web.Http.Type_response> future_response = Vx.Web.Http.f_response_from_httpget(url, Vx.Core.vx_new_string("text/plain"));
        Task<Vx.Core.Type_any> output_1 = Vx.Core.vx_async_from_async_fn(future_response, (response) => {
          Vx.Core.Type_any output_2 = Vx.Web.Http.f_text_from_response(response);
          return output_2;
        });
        return output_1;
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
  public interface Func_text_from_response : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_string vx_text_from_response(Vx.Web.Http.Type_response response);
  }

  public class Class_text_from_response : Vx.Core.Class_base, Func_text_from_response {

    public override Vx.Web.Http.Func_text_from_response vx_new(params object[] vals) {
      Vx.Web.Http.Class_text_from_response output = new Vx.Web.Http.Class_text_from_response();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Web.Http.Class_text_from_response output = new Vx.Web.Http.Class_text_from_response();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/web/http", // pkgname
        "text<-response", // name
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
      Vx.Core.Type_any output = Vx.Web.Http.e_text_from_response;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Web.Http.t_text_from_response;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Web.Http.Type_response inputval = (Vx.Web.Http.Type_response)value;
      Vx.Core.Type_any outputval = Vx.Web.Http.f_text_from_response(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Http.Type_response response = Vx.Core.f_any_from_any(Vx.Web.Http.t_response, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Web.Http.f_text_from_response(response);
      return output;
    }

    public Vx.Core.Type_string vx_text_from_response(Vx.Web.Http.Type_response response) {
      return Vx.Web.Http.f_text_from_response(response);
    }

  }

  public static Vx.Web.Http.Func_text_from_response e_text_from_response = new Vx.Web.Http.Class_text_from_response();
  public static Vx.Web.Http.Func_text_from_response t_text_from_response = new Vx.Web.Http.Class_text_from_response();

  public static Vx.Core.Type_string f_text_from_response(Vx.Web.Http.Type_response response) {
    Vx.Core.Type_string output = Vx.Core.e_string;
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
  public interface Func_textblock_from_httpget : Vx.Core.Type_func, Vx.Core.Type_replfunc_async {
    public Task<Vx.Data.Textblock.Type_textblock> vx_textblock_from_httpget(Vx.Core.Type_string url, Vx.Core.Type_string contenttype);
  }

  public class Class_textblock_from_httpget : Vx.Core.Class_base, Func_textblock_from_httpget {

    public override Vx.Web.Http.Func_textblock_from_httpget vx_new(params object[] vals) {
      Vx.Web.Http.Class_textblock_from_httpget output = new Vx.Web.Http.Class_textblock_from_httpget();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Web.Http.Class_textblock_from_httpget output = new Vx.Web.Http.Class_textblock_from_httpget();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/web/http", // pkgname
        "textblock<-httpget", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
      Vx.Core.Type_any output = Vx.Web.Http.e_textblock_from_httpget;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Web.Http.t_textblock_from_httpget;
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_from_value(Vx.Core.e_any);
      Vx.Core.Type_string url = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string contenttype = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Task<Vx.Data.Textblock.Type_textblock> future = Vx.Web.Http.f_textblock_from_httpget(url, contenttype);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<Vx.Data.Textblock.Type_textblock> vx_textblock_from_httpget(Vx.Core.Type_string url, Vx.Core.Type_string contenttype) {
      return Vx.Web.Http.f_textblock_from_httpget(url, contenttype);
    }

  }

  public static Vx.Web.Http.Func_textblock_from_httpget e_textblock_from_httpget = new Vx.Web.Http.Class_textblock_from_httpget();
  public static Vx.Web.Http.Func_textblock_from_httpget t_textblock_from_httpget = new Vx.Web.Http.Class_textblock_from_httpget();

  public static Task<Vx.Data.Textblock.Type_textblock> f_textblock_from_httpget(Vx.Core.Type_string url, Vx.Core.Type_string contenttype) {
    Task<Vx.Data.Textblock.Type_textblock> output = Vx.Core.vx_async_new_from_value(Vx.Data.Textblock.e_textblock);
    output = Vx.Core.f_let_async(
      Vx.Data.Textblock.t_textblock,
      Vx.Core.t_any_from_func_async.vx_fn_new(() => {
        Task<Vx.Web.Http.Type_response> future_response = Vx.Web.Http.f_response_from_httpget(url, contenttype);
        Task<Vx.Core.Type_any> output_1 = Vx.Core.vx_async_from_async_fn(future_response, (response) => {
          Vx.Core.Type_any output_2 = Vx.Web.Http.f_textblock_from_response(response);
          return output_2;
        });
        return output_1;
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
  public interface Func_textblock_from_response : Vx.Core.Func_any_from_any {
    public Vx.Data.Textblock.Type_textblock vx_textblock_from_response(Vx.Web.Http.Type_response response);
  }

  public class Class_textblock_from_response : Vx.Core.Class_base, Func_textblock_from_response {

    public override Vx.Web.Http.Func_textblock_from_response vx_new(params object[] vals) {
      Vx.Web.Http.Class_textblock_from_response output = new Vx.Web.Http.Class_textblock_from_response();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Web.Http.Class_textblock_from_response output = new Vx.Web.Http.Class_textblock_from_response();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/web/http", // pkgname
        "textblock<-response", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
      Vx.Core.Type_any output = Vx.Web.Http.e_textblock_from_response;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Web.Http.t_textblock_from_response;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Web.Http.Type_response inputval = (Vx.Web.Http.Type_response)value;
      Vx.Core.Type_any outputval = Vx.Web.Http.f_textblock_from_response(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Http.Type_response response = Vx.Core.f_any_from_any(Vx.Web.Http.t_response, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Web.Http.f_textblock_from_response(response);
      return output;
    }

    public Vx.Data.Textblock.Type_textblock vx_textblock_from_response(Vx.Web.Http.Type_response response) {
      return Vx.Web.Http.f_textblock_from_response(response);
    }

  }

  public static Vx.Web.Http.Func_textblock_from_response e_textblock_from_response = new Vx.Web.Http.Class_textblock_from_response();
  public static Vx.Web.Http.Func_textblock_from_response t_textblock_from_response = new Vx.Web.Http.Class_textblock_from_response();

  public static Vx.Data.Textblock.Type_textblock f_textblock_from_response(Vx.Web.Http.Type_response response) {
    Vx.Data.Textblock.Type_textblock output = Vx.Data.Textblock.e_textblock;
    output = Vx.Core.f_new(
      Vx.Data.Textblock.t_textblock,
      Vx.Core.vx_new(
        Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":text"),
        Vx.Web.Http.f_text_from_response(response)
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
  public interface Func_xml_from_httpget : Vx.Core.Func_any_from_any_async {
    public Task<Vx.Data.Xml.Type_xml> vx_xml_from_httpget(Vx.Core.Type_string url);
  }

  public class Class_xml_from_httpget : Vx.Core.Class_base, Func_xml_from_httpget {

    public override Vx.Web.Http.Func_xml_from_httpget vx_new(params object[] vals) {
      Vx.Web.Http.Class_xml_from_httpget output = new Vx.Web.Http.Class_xml_from_httpget();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Web.Http.Class_xml_from_httpget output = new Vx.Web.Http.Class_xml_from_httpget();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/web/http", // pkgname
        "xml<-httpget", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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
      Vx.Core.Type_any output = Vx.Web.Http.e_xml_from_httpget;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Web.Http.t_xml_from_httpget;
      return output;
    }

    public Vx.Core.Func_any_from_any_async vx_fn_new(Vx.Core.Class_any_from_any_async.IFn fn) {
      return Vx.Core.e_any_from_any_async;
    }

    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      Vx.Core.Type_string inputval = Vx.Core.f_any_from_any(Vx.Core.t_string, value);
      Task<Vx.Data.Xml.Type_xml> future = Vx.Web.Http.f_xml_from_httpget(inputval);
      Task<T> output = Vx.Core.vx_async_from_async(generic_any_1, future);
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_from_value(Vx.Core.e_any);
      Vx.Core.Type_string url = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Task<Vx.Data.Xml.Type_xml> future = Vx.Web.Http.f_xml_from_httpget(url);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<Vx.Data.Xml.Type_xml> vx_xml_from_httpget(Vx.Core.Type_string url) {
      return Vx.Web.Http.f_xml_from_httpget(url);
    }

  }

  public static Vx.Web.Http.Func_xml_from_httpget e_xml_from_httpget = new Vx.Web.Http.Class_xml_from_httpget();
  public static Vx.Web.Http.Func_xml_from_httpget t_xml_from_httpget = new Vx.Web.Http.Class_xml_from_httpget();

  public static Task<Vx.Data.Xml.Type_xml> f_xml_from_httpget(Vx.Core.Type_string url) {
    Task<Vx.Data.Xml.Type_xml> output = Vx.Core.vx_async_new_from_value(Vx.Data.Xml.e_xml);
    output = Vx.Core.f_let_async(
      Vx.Data.Xml.t_xml,
      Vx.Core.t_any_from_func_async.vx_fn_new(() => {
        Task<Vx.Data.Textblock.Type_textblock> future_textblock = Vx.Web.Http.f_textblock_from_httpget(url, Vx.Core.vx_new_string("text/xml"));
        Task<Vx.Core.Type_any> output_1 = Vx.Core.vx_async_from_async_fn(future_textblock, (textblock) => {
          Vx.Core.Type_any output_2 = Vx.Data.Xml.f_xml_from_textblock(textblock);
          return output_2;
        });
        return output_1;
      })
    );
    return output;
  }


  public static class PackageRunOnce {
    public static bool RunOnce() {
    Vx.Core.Map<string, Vx.Core.Type_any> maptype = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_any> mapconst = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_func> mapfunc = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>();
    maptype.put("response", Vx.Web.Http.t_response);
    mapfunc.put("csv<-httpget", Vx.Web.Http.t_csv_from_httpget);
    mapfunc.put("json<-httpget", Vx.Web.Http.t_json_from_httpget);
    mapfunc.put("response<-httpget", Vx.Web.Http.t_response_from_httpget);
    mapfunc.put("text<-httpget", Vx.Web.Http.t_text_from_httpget);
    mapfunc.put("text<-response", Vx.Web.Http.t_text_from_response);
    mapfunc.put("textblock<-httpget", Vx.Web.Http.t_textblock_from_httpget);
    mapfunc.put("textblock<-response", Vx.Web.Http.t_textblock_from_response);
    mapfunc.put("xml<-httpget", Vx.Web.Http.t_xml_from_httpget);
    Vx.Core.vx_global_package_set("vx/web/http", maptype, mapconst, mapfunc);
      return true;
    }
  }

  public static bool ranonce = PackageRunOnce.RunOnce();

}
