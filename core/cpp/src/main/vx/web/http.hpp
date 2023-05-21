#ifndef vx_web_http_hpp
#define vx_web_http_hpp
#include <functional>
#include <memory>
#include <set>
#include <string>
#include "../../vx/core.hpp"
#include "../../vx/data/csv.hpp"
#include "../../vx/data/textblock.hpp"
#include "../../vx/data/xml.hpp"

namespace vx_web_http {

  // forward declarations
  class Class_response;
  typedef std::shared_ptr<Class_response> Type_response;
  extern Type_response e_response;
  extern Type_response t_response;
  class Class_csv_from_httpget;
  typedef std::shared_ptr<Class_csv_from_httpget> Func_csv_from_httpget;
  extern Func_csv_from_httpget e_csv_from_httpget;
  extern Func_csv_from_httpget t_csv_from_httpget;
  class Class_json_from_httpget;
  typedef std::shared_ptr<Class_json_from_httpget> Func_json_from_httpget;
  extern Func_json_from_httpget e_json_from_httpget;
  extern Func_json_from_httpget t_json_from_httpget;
  class Class_response_from_httpget;
  typedef std::shared_ptr<Class_response_from_httpget> Func_response_from_httpget;
  extern Func_response_from_httpget e_response_from_httpget;
  extern Func_response_from_httpget t_response_from_httpget;
  class Class_text_from_httpget;
  typedef std::shared_ptr<Class_text_from_httpget> Func_text_from_httpget;
  extern Func_text_from_httpget e_text_from_httpget;
  extern Func_text_from_httpget t_text_from_httpget;
  class Class_text_from_response;
  typedef std::shared_ptr<Class_text_from_response> Func_text_from_response;
  extern Func_text_from_response e_text_from_response;
  extern Func_text_from_response t_text_from_response;
  class Class_textblock_from_httpget;
  typedef std::shared_ptr<Class_textblock_from_httpget> Func_textblock_from_httpget;
  extern Func_textblock_from_httpget e_textblock_from_httpget;
  extern Func_textblock_from_httpget t_textblock_from_httpget;
  class Class_textblock_from_response;
  typedef std::shared_ptr<Class_textblock_from_response> Func_textblock_from_response;
  extern Func_textblock_from_response e_textblock_from_response;
  extern Func_textblock_from_response t_textblock_from_response;
  class Class_xml_from_httpget;
  typedef std::shared_ptr<Class_xml_from_httpget> Func_xml_from_httpget;
  extern Func_xml_from_httpget e_xml_from_httpget;
  extern Func_xml_from_httpget t_xml_from_httpget;


  // (type response)
  class Class_response : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key);
    // ok()
    vx_core::Type_boolean vx_p_ok;
    virtual vx_core::Type_boolean ok();
    // status()
    vx_core::Type_int vx_p_status;
    virtual vx_core::Type_int status();
  };

  // (func csv<-httpget)
  class Class_csv_from_httpget : public vx_core::Class_any_from_any_async, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_async fn_new(vx_core::Class_any_from_any_async::IFn fn);
    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> f_any_from_any_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    std::shared_ptr<vx_core::Async<vx_data_csv::Type_csv>> vx_f_csv_from_httpget(vx_core::Type_string url);
  };

  // (func json<-httpget)
  class Class_json_from_httpget : public vx_core::Class_any_from_any_async, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_async fn_new(vx_core::Class_any_from_any_async::IFn fn);
    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> f_any_from_any_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    std::shared_ptr<vx_core::Async<vx_web_http::Type_response>> vx_f_json_from_httpget(vx_core::Type_string url);
  };

  // (func response<-httpget)
  class Class_response_from_httpget : public vx_core::Class_func, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    std::shared_ptr<vx_core::Async<vx_web_http::Type_response>> vx_f_response_from_httpget(vx_core::Type_string url, vx_core::Type_string contenttype);
  };

  // (func text<-httpget)
  class Class_text_from_httpget : public vx_core::Class_any_from_any_async, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_async fn_new(vx_core::Class_any_from_any_async::IFn fn);
    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> f_any_from_any_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    std::shared_ptr<vx_core::Async<vx_core::Type_string>> vx_f_text_from_httpget(vx_core::Type_string url);
  };

  // (func text<-response)
  class Class_text_from_response : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_f_text_from_response(vx_web_http::Type_response response);
  };

  // (func textblock<-httpget)
  class Class_textblock_from_httpget : public vx_core::Class_func, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    std::shared_ptr<vx_core::Async<vx_data_textblock::Type_textblock>> vx_f_textblock_from_httpget(vx_core::Type_string url, vx_core::Type_string contenttype);
  };

  // (func textblock<-response)
  class Class_textblock_from_response : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_data_textblock::Type_textblock vx_f_textblock_from_response(vx_web_http::Type_response response);
  };

  // (func xml<-httpget)
  class Class_xml_from_httpget : public vx_core::Class_any_from_any_async, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_async fn_new(vx_core::Class_any_from_any_async::IFn fn);
    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> f_any_from_any_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    std::shared_ptr<vx_core::Async<vx_data_xml::Type_xml>> vx_f_xml_from_httpget(vx_core::Type_string url);
  };

  // (func csv<-httpget)
  std::shared_ptr<vx_core::Async<vx_data_csv::Type_csv>> f_csv_from_httpget(vx_core::Type_string url);

  // (func json<-httpget)
  std::shared_ptr<vx_core::Async<vx_web_http::Type_response>> f_json_from_httpget(vx_core::Type_string url);

  // (func response<-httpget)
  std::shared_ptr<vx_core::Async<vx_web_http::Type_response>> f_response_from_httpget(vx_core::Type_string url, vx_core::Type_string contenttype);

  // (func text<-httpget)
  std::shared_ptr<vx_core::Async<vx_core::Type_string>> f_text_from_httpget(vx_core::Type_string url);

  // (func text<-response)
  vx_core::Type_string f_text_from_response(vx_web_http::Type_response response);

  // (func textblock<-httpget)
  std::shared_ptr<vx_core::Async<vx_data_textblock::Type_textblock>> f_textblock_from_httpget(vx_core::Type_string url, vx_core::Type_string contenttype);

  // (func textblock<-response)
  vx_data_textblock::Type_textblock f_textblock_from_response(vx_web_http::Type_response response);

  // (func xml<-httpget)
  std::shared_ptr<vx_core::Async<vx_data_xml::Type_xml>> f_xml_from_httpget(vx_core::Type_string url);

}
#endif
