#include <map>
#include <string>
#include "../../vx/core.hpp"
#include "../../vx/data/csv.hpp"
#include "../../vx/data/textblock.hpp"
#include "../../vx/data/xml.hpp"
#include "http.hpp"

namespace vx_web_http {


  // (type response)
  // class Class_response {
    Abstract_response::~Abstract_response() {}

    Class_response::Class_response() : Abstract_response::Abstract_response() {
      vx_core::refcount += 1;
    }

    Class_response::~Class_response() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_ok,
        this->vx_p_status
      });
    }

    // ok()
    vx_core::Type_boolean Class_response::ok() const {
      vx_core::Type_boolean output = this->vx_p_ok;
      if (!output) {
        output = vx_core::e_boolean;
      }
      return output;
    }

    // status()
    vx_core::Type_int Class_response::status() const {
      vx_core::Type_int output = this->vx_p_status;
      if (!output) {
        output = vx_core::e_int;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_response::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":ok") {
        output = this->ok();
      } else if (skey == ":status") {
        output = this->status();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_response::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":ok"] = this->ok();
      output[":status"] = this->status();
      return output;
    }

    vx_core::Type_any Class_response::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_http::e_response, vals);
    }

    vx_core::Type_any Class_response::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_http::Type_response output = vx_web_http::e_response;
      bool ischanged = false;
      if (copyval->vx_p_constname != "") {
        ischanged = true;
      }
      vx_web_http::Type_response val = vx_core::vx_any_from_any(vx_web_http::t_response, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_boolean vx_p_ok = val->ok();
      vx_core::Type_int vx_p_status = val->status();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            testkey = valstr->vx_string();
          }
          if (false) {
          } else if (testkey == ":ok") {
            key = testkey;
          } else if (testkey == ":status") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new response) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":ok") {
            if (vx_p_ok == valsub) {
            } else if (valsubtype == vx_core::t_boolean) {
              ischanged = true;
              vx_p_ok = vx_core::vx_any_from_any(vx_core::t_boolean, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new response :ok " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":status") {
            if (vx_p_status == valsub) {
            } else if (valsubtype == vx_core::t_int) {
              ischanged = true;
              vx_p_status = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new response :status " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new response) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_http::Class_response();
        if (output->vx_p_ok != vx_p_ok) {
          if (output->vx_p_ok) {
            vx_core::vx_release_one(output->vx_p_ok);
          }
          output->vx_p_ok = vx_p_ok;
          vx_core::vx_reserve(vx_p_ok);
        }
        if (output->vx_p_status != vx_p_status) {
          if (output->vx_p_status) {
            vx_core::vx_release_one(output->vx_p_status);
          }
          output->vx_p_status = vx_p_status;
          vx_core::vx_reserve(vx_p_status);
        }
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_response::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_http::Class_response::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_response::vx_empty() const {return vx_web_http::e_response;}
    vx_core::Type_any Class_response::vx_type() const {return vx_web_http::t_response;}

    vx_core::Type_typedef Class_response::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/http", // pkgname
        "response", // name
        ":struct", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "ok", // name
            vx_core::t_boolean // type
          ),
          vx_core::vx_new_arg(
            "status", // name
            vx_core::t_int // type
          )
        }) // properties
      );
      return output;
    }

  //}

  // (func csv<-httpget)
  vx_core::vx_Type_async f_csv_from_httpget(vx_core::Type_string url) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve(url);
    output = vx_core::f_let_async(
      vx_data_csv::t_csv,
      vx_core::t_any_from_func_async->vx_fn_new({url}, [url]() {
        vx_core::vx_Type_async future_textblock = vx_web_http::f_textblock_from_httpget(url, vx_core::vx_new_string("text/csv"));
        vx_core::vx_Type_fn_any_from_any fn_any_any_textblock = [](vx_core::Type_any any_textblock) {
          vx_data_textblock::Type_textblock textblock = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, any_textblock);
          vx_core::vx_ref_plus(textblock);
          vx_core::Type_any output_2 = vx_data_csv::f_csv_from_textblock(textblock);
          vx_core::vx_release_one_except(textblock, output_2);
          return output_2;
        };
        vx_core::vx_Type_async output_1 = vx_core::vx_async_from_async_fn(future_textblock, vx_data_textblock::t_textblock, {}, fn_any_any_textblock);
        return output_1;
      })
    );
    vx_core::vx_release_one(url);
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_data_csv::e_csv);
    }
    return output;
  }

  // (func csv<-httpget)
  // class Class_csv_from_httpget {
    Abstract_csv_from_httpget::~Abstract_csv_from_httpget() {}

    Class_csv_from_httpget::Class_csv_from_httpget() : Abstract_csv_from_httpget::Abstract_csv_from_httpget() {
      vx_core::refcount += 1;
    }

    Class_csv_from_httpget::~Class_csv_from_httpget() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_csv_from_httpget::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_http::Func_csv_from_httpget output = vx_web_http::e_csv_from_httpget;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_csv_from_httpget::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_http::Func_csv_from_httpget output = vx_web_http::e_csv_from_httpget;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_csv_from_httpget::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/http", // pkgname
        "csv<-httpget", // name
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

    vx_core::Type_funcdef Class_csv_from_httpget::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/http", // pkgname
        "csv<-httpget", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_csv_from_httpget::vx_empty() const {return vx_web_http::e_csv_from_httpget;}
    vx_core::Type_any Class_csv_from_httpget::vx_type() const {return vx_web_http::t_csv_from_httpget;}
    vx_core::Type_msgblock Class_csv_from_httpget::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_csv_from_httpget::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_async Class_csv_from_httpget::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const {
      return vx_core::e_any_from_any_async;
    }

    vx_core::vx_Type_async Class_csv_from_httpget::vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const {
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      vx_core::vx_Type_async output = vx_web_http::f_csv_from_httpget(inputval);
      vx_core::vx_release(val);
      return output;
    }

    vx_core::vx_Type_async Class_csv_from_httpget::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_value(vx_core::e_any);
      vx_core::Type_string url = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_http::f_csv_from_httpget(url);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  // (func json<-httpget)
  vx_core::vx_Type_async f_json_from_httpget(vx_core::Type_string url) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve(url);
    output = vx_core::f_let_async(
      vx_web_http::t_response,
      vx_core::t_any_from_func_async->vx_fn_new({url}, [url]() {
        vx_core::vx_Type_async future_response = vx_web_http::f_response_from_httpget(url, vx_core::vx_new_string("application/json"));
        vx_core::vx_Type_fn_any_from_any fn_any_any_response = [](vx_core::Type_any any_response) {
          vx_web_http::Type_response response = vx_core::vx_any_from_any(vx_web_http::t_response, any_response);
          vx_core::vx_ref_plus(response);
          vx_core::Type_any output_2 = response;
          vx_core::vx_release_one_except(response, output_2);
          return output_2;
        };
        vx_core::vx_Type_async output_1 = vx_core::vx_async_from_async_fn(future_response, vx_web_http::t_response, {}, fn_any_any_response);
        return output_1;
      })
    );
    vx_core::vx_release_one(url);
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_web_http::e_response);
    }
    return output;
  }

  // (func json<-httpget)
  // class Class_json_from_httpget {
    Abstract_json_from_httpget::~Abstract_json_from_httpget() {}

    Class_json_from_httpget::Class_json_from_httpget() : Abstract_json_from_httpget::Abstract_json_from_httpget() {
      vx_core::refcount += 1;
    }

    Class_json_from_httpget::~Class_json_from_httpget() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_json_from_httpget::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_http::Func_json_from_httpget output = vx_web_http::e_json_from_httpget;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_json_from_httpget::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_http::Func_json_from_httpget output = vx_web_http::e_json_from_httpget;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_json_from_httpget::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/http", // pkgname
        "json<-httpget", // name
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

    vx_core::Type_funcdef Class_json_from_httpget::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/http", // pkgname
        "json<-httpget", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_json_from_httpget::vx_empty() const {return vx_web_http::e_json_from_httpget;}
    vx_core::Type_any Class_json_from_httpget::vx_type() const {return vx_web_http::t_json_from_httpget;}
    vx_core::Type_msgblock Class_json_from_httpget::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_json_from_httpget::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_async Class_json_from_httpget::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const {
      return vx_core::e_any_from_any_async;
    }

    vx_core::vx_Type_async Class_json_from_httpget::vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const {
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      vx_core::vx_Type_async output = vx_web_http::f_json_from_httpget(inputval);
      vx_core::vx_release(val);
      return output;
    }

    vx_core::vx_Type_async Class_json_from_httpget::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_value(vx_core::e_any);
      vx_core::Type_string url = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_http::f_json_from_httpget(url);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  // (func response<-httpget)
  vx_core::vx_Type_async f_response_from_httpget(vx_core::Type_string url, vx_core::Type_string contenttype) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve({url, contenttype});
    vx_core::vx_release_one({url, contenttype});
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_web_http::e_response);
    }
    return output;
  }

  // (func response<-httpget)
  // class Class_response_from_httpget {
    Abstract_response_from_httpget::~Abstract_response_from_httpget() {}

    Class_response_from_httpget::Class_response_from_httpget() : Abstract_response_from_httpget::Abstract_response_from_httpget() {
      vx_core::refcount += 1;
    }

    Class_response_from_httpget::~Class_response_from_httpget() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_response_from_httpget::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_http::Func_response_from_httpget output = vx_web_http::e_response_from_httpget;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_response_from_httpget::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_http::Func_response_from_httpget output = vx_web_http::e_response_from_httpget;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_response_from_httpget::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/http", // pkgname
        "response<-httpget", // name
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

    vx_core::Type_funcdef Class_response_from_httpget::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/http", // pkgname
        "response<-httpget", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_response_from_httpget::vx_empty() const {return vx_web_http::e_response_from_httpget;}
    vx_core::Type_any Class_response_from_httpget::vx_type() const {return vx_web_http::t_response_from_httpget;}
    vx_core::Type_msgblock Class_response_from_httpget::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_response_from_httpget::vx_dispose() {return vx_core::emptylistany;}

    vx_core::vx_Type_async Class_response_from_httpget::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_value(vx_core::e_any);
      vx_core::Type_string url = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string contenttype = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_http::f_response_from_httpget(url, contenttype);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  // (func text<-httpget)
  vx_core::vx_Type_async f_text_from_httpget(vx_core::Type_string url) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve(url);
    output = vx_core::f_let_async(
      vx_core::t_string,
      vx_core::t_any_from_func_async->vx_fn_new({url}, [url]() {
        vx_core::vx_Type_async future_response = vx_web_http::f_response_from_httpget(url, vx_core::vx_new_string("text/plain"));
        vx_core::vx_Type_fn_any_from_any fn_any_any_response = [](vx_core::Type_any any_response) {
          vx_web_http::Type_response response = vx_core::vx_any_from_any(vx_web_http::t_response, any_response);
          vx_core::vx_ref_plus(response);
          vx_core::Type_any output_2 = vx_web_http::f_text_from_response(response);
          vx_core::vx_release_one_except(response, output_2);
          return output_2;
        };
        vx_core::vx_Type_async output_1 = vx_core::vx_async_from_async_fn(future_response, vx_web_http::t_response, {}, fn_any_any_response);
        return output_1;
      })
    );
    vx_core::vx_release_one(url);
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_core::e_string);
    }
    return output;
  }

  // (func text<-httpget)
  // class Class_text_from_httpget {
    Abstract_text_from_httpget::~Abstract_text_from_httpget() {}

    Class_text_from_httpget::Class_text_from_httpget() : Abstract_text_from_httpget::Abstract_text_from_httpget() {
      vx_core::refcount += 1;
    }

    Class_text_from_httpget::~Class_text_from_httpget() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_text_from_httpget::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_http::Func_text_from_httpget output = vx_web_http::e_text_from_httpget;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_text_from_httpget::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_http::Func_text_from_httpget output = vx_web_http::e_text_from_httpget;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_text_from_httpget::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/http", // pkgname
        "text<-httpget", // name
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

    vx_core::Type_funcdef Class_text_from_httpget::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/http", // pkgname
        "text<-httpget", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_text_from_httpget::vx_empty() const {return vx_web_http::e_text_from_httpget;}
    vx_core::Type_any Class_text_from_httpget::vx_type() const {return vx_web_http::t_text_from_httpget;}
    vx_core::Type_msgblock Class_text_from_httpget::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_text_from_httpget::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_async Class_text_from_httpget::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const {
      return vx_core::e_any_from_any_async;
    }

    vx_core::vx_Type_async Class_text_from_httpget::vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const {
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      vx_core::vx_Type_async output = vx_web_http::f_text_from_httpget(inputval);
      vx_core::vx_release(val);
      return output;
    }

    vx_core::vx_Type_async Class_text_from_httpget::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_value(vx_core::e_any);
      vx_core::Type_string url = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_http::f_text_from_httpget(url);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  // (func text<-response)
  vx_core::Type_string f_text_from_response(vx_web_http::Type_response response) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve(response);
    vx_core::vx_release_one_except(response, output);
    return output;
  }

  // (func text<-response)
  // class Class_text_from_response {
    Abstract_text_from_response::~Abstract_text_from_response() {}

    Class_text_from_response::Class_text_from_response() : Abstract_text_from_response::Abstract_text_from_response() {
      vx_core::refcount += 1;
    }

    Class_text_from_response::~Class_text_from_response() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_text_from_response::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_http::Func_text_from_response output = vx_web_http::e_text_from_response;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_text_from_response::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_http::Func_text_from_response output = vx_web_http::e_text_from_response;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_text_from_response::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/http", // pkgname
        "text<-response", // name
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

    vx_core::Type_funcdef Class_text_from_response::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/http", // pkgname
        "text<-response", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_text_from_response::vx_empty() const {return vx_web_http::e_text_from_response;}
    vx_core::Type_any Class_text_from_response::vx_type() const {return vx_web_http::t_text_from_response;}
    vx_core::Type_msgblock Class_text_from_response::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_text_from_response::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_text_from_response::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_text_from_response::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_http::Type_response inputval = vx_core::vx_any_from_any(vx_web_http::t_response, val);
      output = vx_web_http::f_text_from_response(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_text_from_response::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_http::Type_response response = vx_core::vx_any_from_any(vx_web_http::t_response, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_http::f_text_from_response(response);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock<-httpget)
  vx_core::vx_Type_async f_textblock_from_httpget(vx_core::Type_string url, vx_core::Type_string contenttype) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve({url, contenttype});
    output = vx_core::f_let_async(
      vx_data_textblock::t_textblock,
      vx_core::t_any_from_func_async->vx_fn_new({url, contenttype}, [url, contenttype]() {
        vx_core::vx_Type_async future_response = vx_web_http::f_response_from_httpget(url, contenttype);
        vx_core::vx_Type_fn_any_from_any fn_any_any_response = [](vx_core::Type_any any_response) {
          vx_web_http::Type_response response = vx_core::vx_any_from_any(vx_web_http::t_response, any_response);
          vx_core::vx_ref_plus(response);
          vx_core::Type_any output_2 = vx_web_http::f_textblock_from_response(response);
          vx_core::vx_release_one_except(response, output_2);
          return output_2;
        };
        vx_core::vx_Type_async output_1 = vx_core::vx_async_from_async_fn(future_response, vx_web_http::t_response, {}, fn_any_any_response);
        return output_1;
      })
    );
    vx_core::vx_release_one({url, contenttype});
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_data_textblock::e_textblock);
    }
    return output;
  }

  // (func textblock<-httpget)
  // class Class_textblock_from_httpget {
    Abstract_textblock_from_httpget::~Abstract_textblock_from_httpget() {}

    Class_textblock_from_httpget::Class_textblock_from_httpget() : Abstract_textblock_from_httpget::Abstract_textblock_from_httpget() {
      vx_core::refcount += 1;
    }

    Class_textblock_from_httpget::~Class_textblock_from_httpget() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_from_httpget::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_http::Func_textblock_from_httpget output = vx_web_http::e_textblock_from_httpget;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_from_httpget::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_http::Func_textblock_from_httpget output = vx_web_http::e_textblock_from_httpget;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_from_httpget::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/http", // pkgname
        "textblock<-httpget", // name
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

    vx_core::Type_funcdef Class_textblock_from_httpget::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/http", // pkgname
        "textblock<-httpget", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_from_httpget::vx_empty() const {return vx_web_http::e_textblock_from_httpget;}
    vx_core::Type_any Class_textblock_from_httpget::vx_type() const {return vx_web_http::t_textblock_from_httpget;}
    vx_core::Type_msgblock Class_textblock_from_httpget::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_from_httpget::vx_dispose() {return vx_core::emptylistany;}

    vx_core::vx_Type_async Class_textblock_from_httpget::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_value(vx_core::e_any);
      vx_core::Type_string url = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string contenttype = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_http::f_textblock_from_httpget(url, contenttype);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  // (func textblock<-response)
  vx_data_textblock::Type_textblock f_textblock_from_response(vx_web_http::Type_response response) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve(response);
    output = vx_core::f_new(
      vx_data_textblock::t_textblock,
      vx_core::vx_new(vx_core::t_anylist, {
        vx_core::vx_new_string(":text"),
        vx_web_http::f_text_from_response(response)
      })
    );
    vx_core::vx_release_one_except(response, output);
    return output;
  }

  // (func textblock<-response)
  // class Class_textblock_from_response {
    Abstract_textblock_from_response::~Abstract_textblock_from_response() {}

    Class_textblock_from_response::Class_textblock_from_response() : Abstract_textblock_from_response::Abstract_textblock_from_response() {
      vx_core::refcount += 1;
    }

    Class_textblock_from_response::~Class_textblock_from_response() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_from_response::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_http::Func_textblock_from_response output = vx_web_http::e_textblock_from_response;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_from_response::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_http::Func_textblock_from_response output = vx_web_http::e_textblock_from_response;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_from_response::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/http", // pkgname
        "textblock<-response", // name
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

    vx_core::Type_funcdef Class_textblock_from_response::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/http", // pkgname
        "textblock<-response", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_from_response::vx_empty() const {return vx_web_http::e_textblock_from_response;}
    vx_core::Type_any Class_textblock_from_response::vx_type() const {return vx_web_http::t_textblock_from_response;}
    vx_core::Type_msgblock Class_textblock_from_response::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_from_response::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_textblock_from_response::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_textblock_from_response::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_http::Type_response inputval = vx_core::vx_any_from_any(vx_web_http::t_response, val);
      output = vx_web_http::f_textblock_from_response(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_textblock_from_response::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_http::Type_response response = vx_core::vx_any_from_any(vx_web_http::t_response, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_http::f_textblock_from_response(response);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func xml<-httpget)
  vx_core::vx_Type_async f_xml_from_httpget(vx_core::Type_string url) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve(url);
    output = vx_core::f_let_async(
      vx_data_xml::t_xml,
      vx_core::t_any_from_func_async->vx_fn_new({url}, [url]() {
        vx_core::vx_Type_async future_textblock = vx_web_http::f_textblock_from_httpget(url, vx_core::vx_new_string("text/xml"));
        vx_core::vx_Type_fn_any_from_any fn_any_any_textblock = [](vx_core::Type_any any_textblock) {
          vx_data_textblock::Type_textblock textblock = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, any_textblock);
          vx_core::vx_ref_plus(textblock);
          vx_core::Type_any output_2 = vx_data_xml::f_xml_from_textblock(textblock);
          vx_core::vx_release_one_except(textblock, output_2);
          return output_2;
        };
        vx_core::vx_Type_async output_1 = vx_core::vx_async_from_async_fn(future_textblock, vx_data_textblock::t_textblock, {}, fn_any_any_textblock);
        return output_1;
      })
    );
    vx_core::vx_release_one(url);
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_data_xml::e_xml);
    }
    return output;
  }

  // (func xml<-httpget)
  // class Class_xml_from_httpget {
    Abstract_xml_from_httpget::~Abstract_xml_from_httpget() {}

    Class_xml_from_httpget::Class_xml_from_httpget() : Abstract_xml_from_httpget::Abstract_xml_from_httpget() {
      vx_core::refcount += 1;
    }

    Class_xml_from_httpget::~Class_xml_from_httpget() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_xml_from_httpget::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_http::Func_xml_from_httpget output = vx_web_http::e_xml_from_httpget;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_xml_from_httpget::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_http::Func_xml_from_httpget output = vx_web_http::e_xml_from_httpget;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_xml_from_httpget::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/http", // pkgname
        "xml<-httpget", // name
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

    vx_core::Type_funcdef Class_xml_from_httpget::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/http", // pkgname
        "xml<-httpget", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_xml_from_httpget::vx_empty() const {return vx_web_http::e_xml_from_httpget;}
    vx_core::Type_any Class_xml_from_httpget::vx_type() const {return vx_web_http::t_xml_from_httpget;}
    vx_core::Type_msgblock Class_xml_from_httpget::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_xml_from_httpget::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_async Class_xml_from_httpget::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const {
      return vx_core::e_any_from_any_async;
    }

    vx_core::vx_Type_async Class_xml_from_httpget::vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const {
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      vx_core::vx_Type_async output = vx_web_http::f_xml_from_httpget(inputval);
      vx_core::vx_release(val);
      return output;
    }

    vx_core::vx_Type_async Class_xml_from_httpget::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_value(vx_core::e_any);
      vx_core::Type_string url = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_http::f_xml_from_httpget(url);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  vx_web_http::Type_response e_response = NULL;
  vx_web_http::Type_response t_response = NULL;
  vx_web_http::Func_csv_from_httpget e_csv_from_httpget = NULL;
  vx_web_http::Func_csv_from_httpget t_csv_from_httpget = NULL;
  vx_web_http::Func_json_from_httpget e_json_from_httpget = NULL;
  vx_web_http::Func_json_from_httpget t_json_from_httpget = NULL;
  vx_web_http::Func_response_from_httpget e_response_from_httpget = NULL;
  vx_web_http::Func_response_from_httpget t_response_from_httpget = NULL;
  vx_web_http::Func_text_from_httpget e_text_from_httpget = NULL;
  vx_web_http::Func_text_from_httpget t_text_from_httpget = NULL;
  vx_web_http::Func_text_from_response e_text_from_response = NULL;
  vx_web_http::Func_text_from_response t_text_from_response = NULL;
  vx_web_http::Func_textblock_from_httpget e_textblock_from_httpget = NULL;
  vx_web_http::Func_textblock_from_httpget t_textblock_from_httpget = NULL;
  vx_web_http::Func_textblock_from_response e_textblock_from_response = NULL;
  vx_web_http::Func_textblock_from_response t_textblock_from_response = NULL;
  vx_web_http::Func_xml_from_httpget e_xml_from_httpget = NULL;
  vx_web_http::Func_xml_from_httpget t_xml_from_httpget = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_web_http::e_response = new Class_response();
      vx_core::vx_reserve_empty(vx_web_http::e_response);
      vx_web_http::t_response = new Class_response();
      vx_core::vx_reserve_type(vx_web_http::t_response);
      vx_web_http::e_csv_from_httpget = new vx_web_http::Class_csv_from_httpget();
      vx_core::vx_reserve_empty(vx_web_http::e_csv_from_httpget);
      vx_web_http::t_csv_from_httpget = new vx_web_http::Class_csv_from_httpget();
      vx_core::vx_reserve_type(vx_web_http::t_csv_from_httpget);
      vx_web_http::e_json_from_httpget = new vx_web_http::Class_json_from_httpget();
      vx_core::vx_reserve_empty(vx_web_http::e_json_from_httpget);
      vx_web_http::t_json_from_httpget = new vx_web_http::Class_json_from_httpget();
      vx_core::vx_reserve_type(vx_web_http::t_json_from_httpget);
      vx_web_http::e_response_from_httpget = new vx_web_http::Class_response_from_httpget();
      vx_core::vx_reserve_empty(vx_web_http::e_response_from_httpget);
      vx_web_http::t_response_from_httpget = new vx_web_http::Class_response_from_httpget();
      vx_core::vx_reserve_type(vx_web_http::t_response_from_httpget);
      vx_web_http::e_text_from_httpget = new vx_web_http::Class_text_from_httpget();
      vx_core::vx_reserve_empty(vx_web_http::e_text_from_httpget);
      vx_web_http::t_text_from_httpget = new vx_web_http::Class_text_from_httpget();
      vx_core::vx_reserve_type(vx_web_http::t_text_from_httpget);
      vx_web_http::e_text_from_response = new vx_web_http::Class_text_from_response();
      vx_core::vx_reserve_empty(vx_web_http::e_text_from_response);
      vx_web_http::t_text_from_response = new vx_web_http::Class_text_from_response();
      vx_core::vx_reserve_type(vx_web_http::t_text_from_response);
      vx_web_http::e_textblock_from_httpget = new vx_web_http::Class_textblock_from_httpget();
      vx_core::vx_reserve_empty(vx_web_http::e_textblock_from_httpget);
      vx_web_http::t_textblock_from_httpget = new vx_web_http::Class_textblock_from_httpget();
      vx_core::vx_reserve_type(vx_web_http::t_textblock_from_httpget);
      vx_web_http::e_textblock_from_response = new vx_web_http::Class_textblock_from_response();
      vx_core::vx_reserve_empty(vx_web_http::e_textblock_from_response);
      vx_web_http::t_textblock_from_response = new vx_web_http::Class_textblock_from_response();
      vx_core::vx_reserve_type(vx_web_http::t_textblock_from_response);
      vx_web_http::e_xml_from_httpget = new vx_web_http::Class_xml_from_httpget();
      vx_core::vx_reserve_empty(vx_web_http::e_xml_from_httpget);
      vx_web_http::t_xml_from_httpget = new vx_web_http::Class_xml_from_httpget();
      vx_core::vx_reserve_type(vx_web_http::t_xml_from_httpget);
    }
    vx_core::vx_Type_mapany vx_Class_package::maptype() {
      vx_core::vx_Type_mapany output;
      output["anylist"] = vx_core::t_anylist;
      return output;
    }
    vx_core::vx_Type_mapany vx_Class_package::mapconst() {
      vx_core::vx_Type_mapany output;
      return output;
    }
    std::map<std::string, vx_core::Type_func> vx_Class_package::mapfunc() {
      vx_core::vx_Type_mapfunc output;
      return output;
    }
  // }

}
