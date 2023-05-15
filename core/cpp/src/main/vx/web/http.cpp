#include <memory>
#include <set>
#include <string>
#include "../../vx/core.hpp"
#include "../../vx/data/csv.hpp"
#include "../../vx/data/textblock.hpp"
#include "../../vx/data/xml.hpp"
#include "vx/web/http.hpp"

//namespace vx_web_http {

  /**
   * type: response
   * (type response)
   */
  //class Type_response {
    // ok()
    vx_core::Type_boolean vx_web_http::Class_response::ok() {
      vx_core::Type_boolean output = this->vx_p_ok;
      if (output == NULL) {
        output = vx_core::t_boolean;
      }
      return output;
    }

    // status()
    vx_core::Type_int vx_web_http::Class_response::status() {
      vx_core::Type_int output = this->vx_p_status;
      if (output == NULL) {
        output = vx_core::t_int;
      }
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_web_http::Class_response::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":ok") {
        output = this->ok();
      } else if (skey == ":status") {
        output = this->status();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_web_http::Class_response::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":ok"] = this->ok();
      output[":status"] = this->status();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_web_http::Class_response::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_web_http::e_response->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_web_http::Class_response::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_web_http::Type_response output;
      vx_web_http::Class_response* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_ok = val->ok();
      output->vx_p_status = val->status();
      std::set<std::string> validkeys;
      validkeys.insert(":ok");
      validkeys.insert(":status");
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string valstr = vx_core::any_from_any(vx_core::t_string, valsub);
            testkey = valstr->vx_string();
          }
          bool isvalidkey = vx_core::boolean_contains_from_set_val(validkeys, testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new response) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":ok") {
            if (valsubtype == vx_core::t_boolean) {
              output->vx_p_ok = vx_core::any_from_any(vx_core::t_boolean, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new response :ok " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":status") {
            if (valsubtype == vx_core::t_int) {
              output->vx_p_status = vx_core::any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new response :status " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new response) - Invalid Key: " + key);
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
          key = "";
        }
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_web_http::Class_response::vx_empty(std::shared_ptr<T> val) {return vx_web_http::e_response;}
    template <class T> std::shared_ptr<T> vx_web_http::Class_response::vx_type(std::shared_ptr<T> val) {return vx_web_http::t_response;}

    vx_core::Type_typedef vx_web_http::Class_response::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
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
        vx_core::e_argmap // properties
      );
    }

    vx_web_http::Type_response vx_web_http::e_response = std::make_shared<vx_web_http::Class_response>();
    vx_web_http::Type_response vx_web_http::t_response = std::make_shared<vx_web_http::Class_response>();
  //}
  /**
   * 
   * @async
   * @function csv_from_httpget
   * Returns a csv file from an httpget
   * @param  {string} url
   * @return {csv}
   * (func csv<-httpget)
   */
  //class Func_csv_from_httpget {

    template <class T> std::shared_ptr<T> vx_web_http::Class_csv_from_httpget::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_web_http::Func_csv_from_httpget output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_web_http::Class_csv_from_httpget::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_web_http::Func_csv_from_httpget output;
      return output;
    }

    vx_core::Type_typedef vx_web_http::Class_csv_from_httpget::vx_typedef() {return vx_web_http::t_csv_from_httpget->vx_typedef();}

    vx_core::Type_funcdef vx_web_http::Class_csv_from_httpget::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/http", // pkgname
        "csv<-httpget", // name
        0, // idx
        true, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/data/csv", // pkgname
          "csv", // name
          ":struct", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_web_http::Class_csv_from_httpget::vx_empty(std::shared_ptr<T> val) {return vx_web_http::e_csv_from_httpget;}
    template <class T> std::shared_ptr<T> vx_web_http::Class_csv_from_httpget::vx_type(std::shared_ptr<T> val) {return vx_web_http::t_csv_from_httpget;}

    vx_core::Func_any_from_any_async vx_web_http::Class_csv_from_httpget::fn_new(vx_core::Class_any_from_any_async::IFn fn) {return vx_core::e_any_from_any_async;}

    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_web_http::Class_csv_from_httpget::f_any_from_any_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      vx_core::Type_string inputval = vx_core::f_any_from_any(vx_core::t_string, value);
      std::shared_ptr<vx_core::Async<vx_data_csv::Type_csv>> future = vx_web_http::f_csv_from_httpget(inputval);
      std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> output = (vx_core::Async<std::shared_ptr<T>>)future;
      return output;
    }

    std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_web_http::Class_csv_from_httpget::vx_repl(vx_core::Type_anylist arglist) {
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> output = vx_core::async_new_from_val(vx_core::e_any);
      vx_core::Type_string url = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      std::shared_ptr<vx_core::Async<vx_data_csv::Type_csv>> future = vx_web_http::f_csv_from_httpget(url);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    std::shared_ptr<vx_core::Async<vx_data_csv::Type_csv>> vx_web_http::Class_csv_from_httpget::vx_csv_from_httpget(vx_core::Type_string url) {
      return vx_web_http::f_csv_from_httpget(url);
    }

  //}

  vx_web_http::Func_csv_from_httpget vx_web_http::e_csv_from_httpget = std::make_shared<vx_web_http::Class_csv_from_httpget>();
  vx_web_http::Func_csv_from_httpget vx_web_http::t_csv_from_httpget = std::make_shared<vx_web_http::Class_csv_from_httpget>();

  std::shared_ptr<vx_core::Async<vx_data_csv::Type_csv>> vx_web_http::f_csv_from_httpget(vx_core::Type_string url) {
    std::shared_ptr<vx_core::Async<vx_data_csv::Type_csv>> output = vx_core::async_new_from_val(vx_data_csv::e_csv);
    vx_core::f_let_async(
      vx_data_csv::t_csv,
      vx_core::t_any_from_func_async->fn_new([url]() {
        vx_core::Async<vx_data_textblock::Type_textblock>* future_textblock = vx_web_http::f_textblock_from_httpget(url, vx_core::t_string->vx_new_from_string("text/csv"));
        vx_core::Async<vx_core::Type_any>* output = vx_core::async_from_async_fn(vx_core::t_any, future_textblock, [](vx_data_textblock::Type_textblock textblock) {
          return vx_data_csv::f_csv_from_textblock(textblock);
        });
        return output;
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
  //class Func_json_from_httpget {

    template <class T> std::shared_ptr<T> vx_web_http::Class_json_from_httpget::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_web_http::Func_json_from_httpget output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_web_http::Class_json_from_httpget::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_web_http::Func_json_from_httpget output;
      return output;
    }

    vx_core::Type_typedef vx_web_http::Class_json_from_httpget::vx_typedef() {return vx_web_http::t_json_from_httpget->vx_typedef();}

    vx_core::Type_funcdef vx_web_http::Class_json_from_httpget::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/http", // pkgname
        "json<-httpget", // name
        0, // idx
        true, // async
        vx_core::Class_typedef::vx_typedef_new(
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
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_web_http::Class_json_from_httpget::vx_empty(std::shared_ptr<T> val) {return vx_web_http::e_json_from_httpget;}
    template <class T> std::shared_ptr<T> vx_web_http::Class_json_from_httpget::vx_type(std::shared_ptr<T> val) {return vx_web_http::t_json_from_httpget;}

    vx_core::Func_any_from_any_async vx_web_http::Class_json_from_httpget::fn_new(vx_core::Class_any_from_any_async::IFn fn) {return vx_core::e_any_from_any_async;}

    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_web_http::Class_json_from_httpget::f_any_from_any_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      vx_core::Type_string inputval = vx_core::f_any_from_any(vx_core::t_string, value);
      std::shared_ptr<vx_core::Async<vx_web_http::Type_response>> future = vx_web_http::f_json_from_httpget(inputval);
      std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> output = (vx_core::Async<std::shared_ptr<T>>)future;
      return output;
    }

    std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_web_http::Class_json_from_httpget::vx_repl(vx_core::Type_anylist arglist) {
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> output = vx_core::async_new_from_val(vx_core::e_any);
      vx_core::Type_string url = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      std::shared_ptr<vx_core::Async<vx_web_http::Type_response>> future = vx_web_http::f_json_from_httpget(url);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    std::shared_ptr<vx_core::Async<vx_web_http::Type_response>> vx_web_http::Class_json_from_httpget::vx_json_from_httpget(vx_core::Type_string url) {
      return vx_web_http::f_json_from_httpget(url);
    }

  //}

  vx_web_http::Func_json_from_httpget vx_web_http::e_json_from_httpget = std::make_shared<vx_web_http::Class_json_from_httpget>();
  vx_web_http::Func_json_from_httpget vx_web_http::t_json_from_httpget = std::make_shared<vx_web_http::Class_json_from_httpget>();

  std::shared_ptr<vx_core::Async<vx_web_http::Type_response>> vx_web_http::f_json_from_httpget(vx_core::Type_string url) {
    std::shared_ptr<vx_core::Async<vx_web_http::Type_response>> output = vx_core::async_new_from_val(vx_web_http::e_response);
    vx_core::f_let_async(
      vx_web_http::t_response,
      vx_core::t_any_from_func_async->fn_new([url]() {
        vx_core::Async<vx_web_http::Type_response>* future_response = vx_web_http::f_response_from_httpget(url, vx_core::t_string->vx_new_from_string("application/json"));
        vx_core::Async<vx_core::Type_any>* output = vx_core::async_from_async_fn(vx_core::t_any, future_response, [](vx_web_http::Type_response response) {
          return response;
        });
        return output;
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
  //class Func_response_from_httpget {

    template <class T> std::shared_ptr<T> vx_web_http::Class_response_from_httpget::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_web_http::Func_response_from_httpget output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_web_http::Class_response_from_httpget::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_web_http::Func_response_from_httpget output;
      return output;
    }

    vx_core::Type_typedef vx_web_http::Class_response_from_httpget::vx_typedef() {return vx_web_http::t_response_from_httpget->vx_typedef();}

    vx_core::Type_funcdef vx_web_http::Class_response_from_httpget::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/http", // pkgname
        "response<-httpget", // name
        0, // idx
        true, // async
        vx_core::Class_typedef::vx_typedef_new(
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
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_web_http::Class_response_from_httpget::vx_empty(std::shared_ptr<T> val) {return vx_web_http::e_response_from_httpget;}
    template <class T> std::shared_ptr<T> vx_web_http::Class_response_from_httpget::vx_type(std::shared_ptr<T> val) {return vx_web_http::t_response_from_httpget;}

    std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_web_http::Class_response_from_httpget::vx_repl(vx_core::Type_anylist arglist) {
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> output = vx_core::async_new_from_val(vx_core::e_any);
      vx_core::Type_string url = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_string contenttype = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      std::shared_ptr<vx_core::Async<vx_web_http::Type_response>> future = vx_web_http::f_response_from_httpget(url, contenttype);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    std::shared_ptr<vx_core::Async<vx_web_http::Type_response>> vx_web_http::Class_response_from_httpget::vx_response_from_httpget(vx_core::Type_string url, vx_core::Type_string contenttype) {
      return vx_web_http::f_response_from_httpget(url, contenttype);
    }

  //}

  vx_web_http::Func_response_from_httpget vx_web_http::e_response_from_httpget = std::make_shared<vx_web_http::Class_response_from_httpget>();
  vx_web_http::Func_response_from_httpget vx_web_http::t_response_from_httpget = std::make_shared<vx_web_http::Class_response_from_httpget>();

  std::shared_ptr<vx_core::Async<vx_web_http::Type_response>> vx_web_http::f_response_from_httpget(vx_core::Type_string url, vx_core::Type_string contenttype) {
    std::shared_ptr<vx_core::Async<vx_web_http::Type_response>> output = vx_core::async_new_from_val(vx_web_http::e_response);
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
  //class Func_text_from_httpget {

    template <class T> std::shared_ptr<T> vx_web_http::Class_text_from_httpget::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_web_http::Func_text_from_httpget output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_web_http::Class_text_from_httpget::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_web_http::Func_text_from_httpget output;
      return output;
    }

    vx_core::Type_typedef vx_web_http::Class_text_from_httpget::vx_typedef() {return vx_web_http::t_text_from_httpget->vx_typedef();}

    vx_core::Type_funcdef vx_web_http::Class_text_from_httpget::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/http", // pkgname
        "text<-httpget", // name
        0, // idx
        true, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_web_http::Class_text_from_httpget::vx_empty(std::shared_ptr<T> val) {return vx_web_http::e_text_from_httpget;}
    template <class T> std::shared_ptr<T> vx_web_http::Class_text_from_httpget::vx_type(std::shared_ptr<T> val) {return vx_web_http::t_text_from_httpget;}

    vx_core::Func_any_from_any_async vx_web_http::Class_text_from_httpget::fn_new(vx_core::Class_any_from_any_async::IFn fn) {return vx_core::e_any_from_any_async;}

    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_web_http::Class_text_from_httpget::f_any_from_any_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      vx_core::Type_string inputval = vx_core::f_any_from_any(vx_core::t_string, value);
      std::shared_ptr<vx_core::Async<vx_core::Type_string>> future = vx_web_http::f_text_from_httpget(inputval);
      std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> output = (vx_core::Async<std::shared_ptr<T>>)future;
      return output;
    }

    std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_web_http::Class_text_from_httpget::vx_repl(vx_core::Type_anylist arglist) {
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> output = vx_core::async_new_from_val(vx_core::e_any);
      vx_core::Type_string url = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      std::shared_ptr<vx_core::Async<vx_core::Type_string>> future = vx_web_http::f_text_from_httpget(url);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    std::shared_ptr<vx_core::Async<vx_core::Type_string>> vx_web_http::Class_text_from_httpget::vx_text_from_httpget(vx_core::Type_string url) {
      return vx_web_http::f_text_from_httpget(url);
    }

  //}

  vx_web_http::Func_text_from_httpget vx_web_http::e_text_from_httpget = std::make_shared<vx_web_http::Class_text_from_httpget>();
  vx_web_http::Func_text_from_httpget vx_web_http::t_text_from_httpget = std::make_shared<vx_web_http::Class_text_from_httpget>();

  std::shared_ptr<vx_core::Async<vx_core::Type_string>> vx_web_http::f_text_from_httpget(vx_core::Type_string url) {
    std::shared_ptr<vx_core::Async<vx_core::Type_string>> output = vx_core::async_new_from_val(vx_core::e_string);
    vx_core::f_let_async(
      vx_core::t_string,
      vx_core::t_any_from_func_async->fn_new([url]() {
        vx_core::Async<vx_web_http::Type_response>* future_response = vx_web_http::f_response_from_httpget(url, vx_core::t_string->vx_new_from_string("text/plain"));
        vx_core::Async<vx_core::Type_any>* output = vx_core::async_from_async_fn(vx_core::t_any, future_response, [](vx_web_http::Type_response response) {
          return vx_web_http::f_text_from_response(response);
        });
        return output;
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
  //class Func_text_from_response {

    template <class T> std::shared_ptr<T> vx_web_http::Class_text_from_response::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_web_http::Func_text_from_response output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_web_http::Class_text_from_response::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_web_http::Func_text_from_response output;
      return output;
    }

    vx_core::Type_typedef vx_web_http::Class_text_from_response::vx_typedef() {return vx_web_http::t_text_from_response->vx_typedef();}

    vx_core::Type_funcdef vx_web_http::Class_text_from_response::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/http", // pkgname
        "text<-response", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_web_http::Class_text_from_response::vx_empty(std::shared_ptr<T> val) {return vx_web_http::e_text_from_response;}
    template <class T> std::shared_ptr<T> vx_web_http::Class_text_from_response::vx_type(std::shared_ptr<T> val) {return vx_web_http::t_text_from_response;}

    vx_core::Func_any_from_any vx_web_http::Class_text_from_response::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_web_http::Class_text_from_response::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_web_http::Type_response inputval = (vx_web_http::Type_response)value;
      vx_core::Type_any outputval = vx_web_http::f_text_from_response(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_web_http::Class_text_from_response::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_http::Type_response response = vx_core::f_any_from_any(vx_web_http::t_response, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_web_http::f_text_from_response(response);
      return output;
    }

    vx_core::Type_string vx_web_http::Class_text_from_response::vx_text_from_response(vx_web_http::Type_response response) {
      return vx_web_http::f_text_from_response(response);
    }

  //}

  vx_web_http::Func_text_from_response vx_web_http::e_text_from_response = std::make_shared<vx_web_http::Class_text_from_response>();
  vx_web_http::Func_text_from_response vx_web_http::t_text_from_response = std::make_shared<vx_web_http::Class_text_from_response>();

  vx_core::Type_string vx_web_http::f_text_from_response(vx_web_http::Type_response response) {
    vx_core::Type_string output = vx_core::e_string;
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
  //class Func_textblock_from_httpget {

    template <class T> std::shared_ptr<T> vx_web_http::Class_textblock_from_httpget::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_web_http::Func_textblock_from_httpget output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_web_http::Class_textblock_from_httpget::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_web_http::Func_textblock_from_httpget output;
      return output;
    }

    vx_core::Type_typedef vx_web_http::Class_textblock_from_httpget::vx_typedef() {return vx_web_http::t_textblock_from_httpget->vx_typedef();}

    vx_core::Type_funcdef vx_web_http::Class_textblock_from_httpget::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/http", // pkgname
        "textblock<-httpget", // name
        0, // idx
        true, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
          ":struct", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_web_http::Class_textblock_from_httpget::vx_empty(std::shared_ptr<T> val) {return vx_web_http::e_textblock_from_httpget;}
    template <class T> std::shared_ptr<T> vx_web_http::Class_textblock_from_httpget::vx_type(std::shared_ptr<T> val) {return vx_web_http::t_textblock_from_httpget;}

    std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_web_http::Class_textblock_from_httpget::vx_repl(vx_core::Type_anylist arglist) {
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> output = vx_core::async_new_from_val(vx_core::e_any);
      vx_core::Type_string url = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_string contenttype = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      std::shared_ptr<vx_core::Async<vx_data_textblock::Type_textblock>> future = vx_web_http::f_textblock_from_httpget(url, contenttype);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    std::shared_ptr<vx_core::Async<vx_data_textblock::Type_textblock>> vx_web_http::Class_textblock_from_httpget::vx_textblock_from_httpget(vx_core::Type_string url, vx_core::Type_string contenttype) {
      return vx_web_http::f_textblock_from_httpget(url, contenttype);
    }

  //}

  vx_web_http::Func_textblock_from_httpget vx_web_http::e_textblock_from_httpget = std::make_shared<vx_web_http::Class_textblock_from_httpget>();
  vx_web_http::Func_textblock_from_httpget vx_web_http::t_textblock_from_httpget = std::make_shared<vx_web_http::Class_textblock_from_httpget>();

  std::shared_ptr<vx_core::Async<vx_data_textblock::Type_textblock>> vx_web_http::f_textblock_from_httpget(vx_core::Type_string url, vx_core::Type_string contenttype) {
    std::shared_ptr<vx_core::Async<vx_data_textblock::Type_textblock>> output = vx_core::async_new_from_val(vx_data_textblock::e_textblock);
    vx_core::f_let_async(
      vx_data_textblock::t_textblock,
      vx_core::t_any_from_func_async->fn_new([url, contenttype]() {
        vx_core::Async<vx_web_http::Type_response>* future_response = vx_web_http::f_response_from_httpget(url, contenttype);
        vx_core::Async<vx_core::Type_any>* output = vx_core::async_from_async_fn(vx_core::t_any, future_response, [](vx_web_http::Type_response response) {
          return vx_web_http::f_textblock_from_response(response);
        });
        return output;
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
  //class Func_textblock_from_response {

    template <class T> std::shared_ptr<T> vx_web_http::Class_textblock_from_response::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_web_http::Func_textblock_from_response output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_web_http::Class_textblock_from_response::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_web_http::Func_textblock_from_response output;
      return output;
    }

    vx_core::Type_typedef vx_web_http::Class_textblock_from_response::vx_typedef() {return vx_web_http::t_textblock_from_response->vx_typedef();}

    vx_core::Type_funcdef vx_web_http::Class_textblock_from_response::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/http", // pkgname
        "textblock<-response", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
          ":struct", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_web_http::Class_textblock_from_response::vx_empty(std::shared_ptr<T> val) {return vx_web_http::e_textblock_from_response;}
    template <class T> std::shared_ptr<T> vx_web_http::Class_textblock_from_response::vx_type(std::shared_ptr<T> val) {return vx_web_http::t_textblock_from_response;}

    vx_core::Func_any_from_any vx_web_http::Class_textblock_from_response::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_web_http::Class_textblock_from_response::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_web_http::Type_response inputval = (vx_web_http::Type_response)value;
      vx_core::Type_any outputval = vx_web_http::f_textblock_from_response(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_web_http::Class_textblock_from_response::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_http::Type_response response = vx_core::f_any_from_any(vx_web_http::t_response, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_web_http::f_textblock_from_response(response);
      return output;
    }

    vx_data_textblock::Type_textblock vx_web_http::Class_textblock_from_response::vx_textblock_from_response(vx_web_http::Type_response response) {
      return vx_web_http::f_textblock_from_response(response);
    }

  //}

  vx_web_http::Func_textblock_from_response vx_web_http::e_textblock_from_response = std::make_shared<vx_web_http::Class_textblock_from_response>();
  vx_web_http::Func_textblock_from_response vx_web_http::t_textblock_from_response = std::make_shared<vx_web_http::Class_textblock_from_response>();

  vx_data_textblock::Type_textblock vx_web_http::f_textblock_from_response(vx_web_http::Type_response response) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    output = vx_core::f_new(
      vx_data_textblock::t_textblock,
      vx_core::t_anylist->vx_new(vx_core::t_anylist, {
        vx_core::t_string->vx_new_from_string(":text"),
        vx_web_http::f_text_from_response(response)
      })
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
  //class Func_xml_from_httpget {

    template <class T> std::shared_ptr<T> vx_web_http::Class_xml_from_httpget::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_web_http::Func_xml_from_httpget output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_web_http::Class_xml_from_httpget::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_web_http::Func_xml_from_httpget output;
      return output;
    }

    vx_core::Type_typedef vx_web_http::Class_xml_from_httpget::vx_typedef() {return vx_web_http::t_xml_from_httpget->vx_typedef();}

    vx_core::Type_funcdef vx_web_http::Class_xml_from_httpget::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/http", // pkgname
        "xml<-httpget", // name
        0, // idx
        true, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
          ":struct", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_web_http::Class_xml_from_httpget::vx_empty(std::shared_ptr<T> val) {return vx_web_http::e_xml_from_httpget;}
    template <class T> std::shared_ptr<T> vx_web_http::Class_xml_from_httpget::vx_type(std::shared_ptr<T> val) {return vx_web_http::t_xml_from_httpget;}

    vx_core::Func_any_from_any_async vx_web_http::Class_xml_from_httpget::fn_new(vx_core::Class_any_from_any_async::IFn fn) {return vx_core::e_any_from_any_async;}

    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_web_http::Class_xml_from_httpget::f_any_from_any_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      vx_core::Type_string inputval = vx_core::f_any_from_any(vx_core::t_string, value);
      std::shared_ptr<vx_core::Async<vx_data_xml::Type_xml>> future = vx_web_http::f_xml_from_httpget(inputval);
      std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> output = (vx_core::Async<std::shared_ptr<T>>)future;
      return output;
    }

    std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_web_http::Class_xml_from_httpget::vx_repl(vx_core::Type_anylist arglist) {
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> output = vx_core::async_new_from_val(vx_core::e_any);
      vx_core::Type_string url = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      std::shared_ptr<vx_core::Async<vx_data_xml::Type_xml>> future = vx_web_http::f_xml_from_httpget(url);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    std::shared_ptr<vx_core::Async<vx_data_xml::Type_xml>> vx_web_http::Class_xml_from_httpget::vx_xml_from_httpget(vx_core::Type_string url) {
      return vx_web_http::f_xml_from_httpget(url);
    }

  //}

  vx_web_http::Func_xml_from_httpget vx_web_http::e_xml_from_httpget = std::make_shared<vx_web_http::Class_xml_from_httpget>();
  vx_web_http::Func_xml_from_httpget vx_web_http::t_xml_from_httpget = std::make_shared<vx_web_http::Class_xml_from_httpget>();

  std::shared_ptr<vx_core::Async<vx_data_xml::Type_xml>> vx_web_http::f_xml_from_httpget(vx_core::Type_string url) {
    std::shared_ptr<vx_core::Async<vx_data_xml::Type_xml>> output = vx_core::async_new_from_val(vx_data_xml::e_xml);
    vx_core::f_let_async(
      vx_data_xml::t_xml,
      vx_core::t_any_from_func_async->fn_new([url]() {
        vx_core::Async<vx_data_textblock::Type_textblock>* future_textblock = vx_web_http::f_textblock_from_httpget(url, vx_core::t_string->vx_new_from_string("text/xml"));
        vx_core::Async<vx_core::Type_any>* output = vx_core::async_from_async_fn(vx_core::t_any, future_textblock, [](vx_data_textblock::Type_textblock textblock) {
          return vx_data_xml::f_xml_from_textblock(textblock);
        });
        return output;
      })
    );
    return output;
  }


//}
