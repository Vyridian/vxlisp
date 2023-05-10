#pragma once
#include <any>
#include <map>
#include <set>
#include <string>
#include "../../vx/core.hpp"
#include "../../vx/data/csv.hpp"
#include "../../vx/data/textblock.hpp"
#include "../../vx/data/xml.hpp"

namespace vx_web_http {

  // forward declarations
  class Type_response;
  extern Type_response* e_response;
  extern Type_response* t_response;
  class Func_csv_from_httpget;
  extern Func_csv_from_httpget* e_csv_from_httpget;
  extern Func_csv_from_httpget* t_csv_from_httpget;
  class Func_json_from_httpget;
  extern Func_json_from_httpget* e_json_from_httpget;
  extern Func_json_from_httpget* t_json_from_httpget;
  class Func_response_from_httpget;
  extern Func_response_from_httpget* e_response_from_httpget;
  extern Func_response_from_httpget* t_response_from_httpget;
  class Func_text_from_httpget;
  extern Func_text_from_httpget* e_text_from_httpget;
  extern Func_text_from_httpget* t_text_from_httpget;
  class Func_text_from_response;
  extern Func_text_from_response* e_text_from_response;
  extern Func_text_from_response* t_text_from_response;
  class Func_textblock_from_httpget;
  extern Func_textblock_from_httpget* e_textblock_from_httpget;
  extern Func_textblock_from_httpget* t_textblock_from_httpget;
  class Func_textblock_from_response;
  extern Func_textblock_from_response* e_textblock_from_response;
  extern Func_textblock_from_response* t_textblock_from_response;
  class Func_xml_from_httpget;
  extern Func_xml_from_httpget* e_xml_from_httpget;
  extern Func_xml_from_httpget* t_xml_from_httpget;


  // (type response)
  class Type_response : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_web_http::Type_response* vx_new(Args*... args);
    template<class... Args> vx_web_http::Type_response* vx_copy(Args*... args);
    virtual vx_web_http::Type_response* vx_empty();
    virtual vx_web_http::Type_response* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // ok()
    vx_core::Type_boolean* vx_p_ok;
    virtual vx_core::Type_boolean* ok();
    // status()
    vx_core::Type_int* vx_p_status;
    virtual vx_core::Type_int* status();
  };

  // (func csv<-httpget)
  class Func_csv_from_httpget : public vx_core::Func_any_from_any_async, public virtual vx_core::Type_replfunc_async {
  public:
    template<class... Args> vx_web_http::Func_csv_from_httpget* vx_new(Args*... args);
    template<class... Args> vx_web_http::Func_csv_from_httpget* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_http::Func_csv_from_httpget* vx_empty();
    virtual vx_web_http::Func_csv_from_httpget* vx_type();
    virtual vx_core::Func_any_from_any_async* fn_new(vx_core::Func_any_from_any_async::IFn fn);
    template <class T, class U> vx_core::Async<T*>* f_any_from_any_async(T* generic_any_1, U* value);
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Async<vx_data_csv::Type_csv*>* vx_csv_from_httpget(vx_core::Type_string* url);
  };

  // (func json<-httpget)
  class Func_json_from_httpget : public vx_core::Func_any_from_any_async, public virtual vx_core::Type_replfunc_async {
  public:
    template<class... Args> vx_web_http::Func_json_from_httpget* vx_new(Args*... args);
    template<class... Args> vx_web_http::Func_json_from_httpget* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_http::Func_json_from_httpget* vx_empty();
    virtual vx_web_http::Func_json_from_httpget* vx_type();
    virtual vx_core::Func_any_from_any_async* fn_new(vx_core::Func_any_from_any_async::IFn fn);
    template <class T, class U> vx_core::Async<T*>* f_any_from_any_async(T* generic_any_1, U* value);
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Async<vx_web_http::Type_response*>* vx_json_from_httpget(vx_core::Type_string* url);
  };

  // (func response<-httpget)
  class Func_response_from_httpget : public vx_core::Type_func, public virtual vx_core::Type_replfunc_async {
  public:
    template<class... Args> vx_web_http::Func_response_from_httpget* vx_new(Args*... args);
    template<class... Args> vx_web_http::Func_response_from_httpget* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_http::Func_response_from_httpget* vx_empty();
    virtual vx_web_http::Func_response_from_httpget* vx_type();
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Async<vx_web_http::Type_response*>* vx_response_from_httpget(vx_core::Type_string* url, vx_core::Type_string* contenttype);
  };

  // (func text<-httpget)
  class Func_text_from_httpget : public vx_core::Func_any_from_any_async, public virtual vx_core::Type_replfunc_async {
  public:
    template<class... Args> vx_web_http::Func_text_from_httpget* vx_new(Args*... args);
    template<class... Args> vx_web_http::Func_text_from_httpget* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_http::Func_text_from_httpget* vx_empty();
    virtual vx_web_http::Func_text_from_httpget* vx_type();
    virtual vx_core::Func_any_from_any_async* fn_new(vx_core::Func_any_from_any_async::IFn fn);
    template <class T, class U> vx_core::Async<T*>* f_any_from_any_async(T* generic_any_1, U* value);
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Async<vx_core::Type_string*>* vx_text_from_httpget(vx_core::Type_string* url);
  };

  // (func text<-response)
  class Func_text_from_response : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_web_http::Func_text_from_response* vx_new(Args*... args);
    template<class... Args> vx_web_http::Func_text_from_response* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_http::Func_text_from_response* vx_empty();
    virtual vx_web_http::Func_text_from_response* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_text_from_response(vx_web_http::Type_response* response);
  };

  // (func textblock<-httpget)
  class Func_textblock_from_httpget : public vx_core::Type_func, public virtual vx_core::Type_replfunc_async {
  public:
    template<class... Args> vx_web_http::Func_textblock_from_httpget* vx_new(Args*... args);
    template<class... Args> vx_web_http::Func_textblock_from_httpget* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_http::Func_textblock_from_httpget* vx_empty();
    virtual vx_web_http::Func_textblock_from_httpget* vx_type();
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Async<vx_data_textblock::Type_textblock*>* vx_textblock_from_httpget(vx_core::Type_string* url, vx_core::Type_string* contenttype);
  };

  // (func textblock<-response)
  class Func_textblock_from_response : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_web_http::Func_textblock_from_response* vx_new(Args*... args);
    template<class... Args> vx_web_http::Func_textblock_from_response* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_http::Func_textblock_from_response* vx_empty();
    virtual vx_web_http::Func_textblock_from_response* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_data_textblock::Type_textblock* vx_textblock_from_response(vx_web_http::Type_response* response);
  };

  // (func xml<-httpget)
  class Func_xml_from_httpget : public vx_core::Func_any_from_any_async, public virtual vx_core::Type_replfunc_async {
  public:
    template<class... Args> vx_web_http::Func_xml_from_httpget* vx_new(Args*... args);
    template<class... Args> vx_web_http::Func_xml_from_httpget* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_http::Func_xml_from_httpget* vx_empty();
    virtual vx_web_http::Func_xml_from_httpget* vx_type();
    virtual vx_core::Func_any_from_any_async* fn_new(vx_core::Func_any_from_any_async::IFn fn);
    template <class T, class U> vx_core::Async<T*>* f_any_from_any_async(T* generic_any_1, U* value);
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Async<vx_data_xml::Type_xml*>* vx_xml_from_httpget(vx_core::Type_string* url);
  };

  // (func csv<-httpget)
  vx_core::Async<vx_data_csv::Type_csv*>* f_csv_from_httpget(vx_core::Type_string* url);

  // (func json<-httpget)
  vx_core::Async<vx_web_http::Type_response*>* f_json_from_httpget(vx_core::Type_string* url);

  // (func response<-httpget)
  vx_core::Async<vx_web_http::Type_response*>* f_response_from_httpget(vx_core::Type_string* url, vx_core::Type_string* contenttype);

  // (func text<-httpget)
  vx_core::Async<vx_core::Type_string*>* f_text_from_httpget(vx_core::Type_string* url);

  // (func text<-response)
  vx_core::Type_string* f_text_from_response(vx_web_http::Type_response* response);

  // (func textblock<-httpget)
  vx_core::Async<vx_data_textblock::Type_textblock*>* f_textblock_from_httpget(vx_core::Type_string* url, vx_core::Type_string* contenttype);

  // (func textblock<-response)
  vx_data_textblock::Type_textblock* f_textblock_from_response(vx_web_http::Type_response* response);

  // (func xml<-httpget)
  vx_core::Async<vx_data_xml::Type_xml*>* f_xml_from_httpget(vx_core::Type_string* url);

}
