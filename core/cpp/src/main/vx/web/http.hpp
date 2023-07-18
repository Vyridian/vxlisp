#ifndef vx_web_http_hpp
#define vx_web_http_hpp
#include "../../vx/core.hpp"
#include "../../vx/data/csv.hpp"
#include "../../vx/data/textblock.hpp"
#include "../../vx/data/xml.hpp"

namespace vx_web_http {

  // forward declarations
  class Abstract_response;
  typedef Abstract_response* Type_response;
  extern Type_response e_response();
  extern Type_response t_response();
  class Abstract_csv_from_httpget;
  typedef Abstract_csv_from_httpget* Func_csv_from_httpget;
  extern Func_csv_from_httpget e_csv_from_httpget();
  extern Func_csv_from_httpget t_csv_from_httpget();
  class Abstract_json_from_httpget;
  typedef Abstract_json_from_httpget* Func_json_from_httpget;
  extern Func_json_from_httpget e_json_from_httpget();
  extern Func_json_from_httpget t_json_from_httpget();
  class Abstract_response_from_httpget;
  typedef Abstract_response_from_httpget* Func_response_from_httpget;
  extern Func_response_from_httpget e_response_from_httpget();
  extern Func_response_from_httpget t_response_from_httpget();
  class Abstract_text_from_httpget;
  typedef Abstract_text_from_httpget* Func_text_from_httpget;
  extern Func_text_from_httpget e_text_from_httpget();
  extern Func_text_from_httpget t_text_from_httpget();
  class Abstract_text_from_response;
  typedef Abstract_text_from_response* Func_text_from_response;
  extern Func_text_from_response e_text_from_response();
  extern Func_text_from_response t_text_from_response();
  class Abstract_textblock_from_httpget;
  typedef Abstract_textblock_from_httpget* Func_textblock_from_httpget;
  extern Func_textblock_from_httpget e_textblock_from_httpget();
  extern Func_textblock_from_httpget t_textblock_from_httpget();
  class Abstract_textblock_from_response;
  typedef Abstract_textblock_from_response* Func_textblock_from_response;
  extern Func_textblock_from_response e_textblock_from_response();
  extern Func_textblock_from_response t_textblock_from_response();
  class Abstract_xml_from_httpget;
  typedef Abstract_xml_from_httpget* Func_xml_from_httpget;
  extern Func_xml_from_httpget e_xml_from_httpget();
  extern Func_xml_from_httpget t_xml_from_httpget();

  class vx_Class_package {
  public:
    vx_web_http::Type_response e_response;
    vx_web_http::Type_response t_response;
    vx_web_http::Func_csv_from_httpget e_csv_from_httpget;
    vx_web_http::Func_csv_from_httpget t_csv_from_httpget;
    vx_web_http::Func_json_from_httpget e_json_from_httpget;
    vx_web_http::Func_json_from_httpget t_json_from_httpget;
    vx_web_http::Func_response_from_httpget e_response_from_httpget;
    vx_web_http::Func_response_from_httpget t_response_from_httpget;
    vx_web_http::Func_text_from_httpget e_text_from_httpget;
    vx_web_http::Func_text_from_httpget t_text_from_httpget;
    vx_web_http::Func_text_from_response e_text_from_response;
    vx_web_http::Func_text_from_response t_text_from_response;
    vx_web_http::Func_textblock_from_httpget e_textblock_from_httpget;
    vx_web_http::Func_textblock_from_httpget t_textblock_from_httpget;
    vx_web_http::Func_textblock_from_response e_textblock_from_response;
    vx_web_http::Func_textblock_from_response t_textblock_from_response;
    vx_web_http::Func_xml_from_httpget e_xml_from_httpget;
    vx_web_http::Func_xml_from_httpget t_xml_from_httpget;
  };


  // (func csv<-httpget)
  vx_core::vx_Type_async f_csv_from_httpget(vx_core::Type_string url);

  // (func json<-httpget)
  vx_core::vx_Type_async f_json_from_httpget(vx_core::Type_string url);

  // (func response<-httpget)
  vx_core::vx_Type_async f_response_from_httpget(vx_core::Type_string url, vx_core::Type_string contenttype);

  // (func text<-httpget)
  vx_core::vx_Type_async f_text_from_httpget(vx_core::Type_string url);

  // (func text<-response)
  vx_core::Type_string f_text_from_response(vx_web_http::Type_response response);

  // (func textblock<-httpget)
  vx_core::vx_Type_async f_textblock_from_httpget(vx_core::Type_string url, vx_core::Type_string contenttype);

  // (func textblock<-response)
  vx_data_textblock::Type_textblock f_textblock_from_response(vx_web_http::Type_response response);

  // (func xml<-httpget)
  vx_core::vx_Type_async f_xml_from_httpget(vx_core::Type_string url);

  // (type response)
  class Abstract_response : public virtual vx_core::Abstract_struct {
  public:
    Abstract_response() {};
    virtual ~Abstract_response() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // ok()
    vx_core::Type_boolean vx_p_ok = NULL;
    virtual vx_core::Type_boolean ok() const = 0;
    // status()
    vx_core::Type_int vx_p_status = NULL;
    virtual vx_core::Type_int status() const = 0;
  };
  class Class_response : public virtual Abstract_response {
  public:
    Class_response();
    virtual ~Class_response() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_boolean ok() const override;
    virtual vx_core::Type_int status() const override;
  };

  // (func csv<-httpget)
  class Abstract_csv_from_httpget : public vx_core::Abstract_any_from_any_async, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_csv_from_httpget() {};
    virtual ~Abstract_csv_from_httpget() = 0;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::Abstract_any_from_any_async::IFn fn) const override = 0;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any val) const override = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_csv_from_httpget : public virtual Abstract_csv_from_httpget {
  public:
    Class_csv_from_httpget();
    virtual ~Class_csv_from_httpget() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::Abstract_any_from_any_async::IFn fn) const override;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any val) const override;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func json<-httpget)
  class Abstract_json_from_httpget : public vx_core::Abstract_any_from_any_async, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_json_from_httpget() {};
    virtual ~Abstract_json_from_httpget() = 0;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::Abstract_any_from_any_async::IFn fn) const override = 0;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any val) const override = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_json_from_httpget : public virtual Abstract_json_from_httpget {
  public:
    Class_json_from_httpget();
    virtual ~Class_json_from_httpget() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::Abstract_any_from_any_async::IFn fn) const override;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any val) const override;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func response<-httpget)
  class Abstract_response_from_httpget : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_response_from_httpget() {};
    virtual ~Abstract_response_from_httpget() = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_response_from_httpget : public virtual Abstract_response_from_httpget {
  public:
    Class_response_from_httpget();
    virtual ~Class_response_from_httpget() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func text<-httpget)
  class Abstract_text_from_httpget : public vx_core::Abstract_any_from_any_async, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_text_from_httpget() {};
    virtual ~Abstract_text_from_httpget() = 0;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::Abstract_any_from_any_async::IFn fn) const override = 0;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any val) const override = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_text_from_httpget : public virtual Abstract_text_from_httpget {
  public:
    Class_text_from_httpget();
    virtual ~Class_text_from_httpget() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::Abstract_any_from_any_async::IFn fn) const override;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any val) const override;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func text<-response)
  class Abstract_text_from_response : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_text_from_response() {};
    virtual ~Abstract_text_from_response() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_text_from_response : public virtual Abstract_text_from_response {
  public:
    Class_text_from_response();
    virtual ~Class_text_from_response() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func textblock<-httpget)
  class Abstract_textblock_from_httpget : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_textblock_from_httpget() {};
    virtual ~Abstract_textblock_from_httpget() = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_textblock_from_httpget : public virtual Abstract_textblock_from_httpget {
  public:
    Class_textblock_from_httpget();
    virtual ~Class_textblock_from_httpget() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func textblock<-response)
  class Abstract_textblock_from_response : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_textblock_from_response() {};
    virtual ~Abstract_textblock_from_response() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_textblock_from_response : public virtual Abstract_textblock_from_response {
  public:
    Class_textblock_from_response();
    virtual ~Class_textblock_from_response() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func xml<-httpget)
  class Abstract_xml_from_httpget : public vx_core::Abstract_any_from_any_async, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_xml_from_httpget() {};
    virtual ~Abstract_xml_from_httpget() = 0;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::Abstract_any_from_any_async::IFn fn) const override = 0;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any val) const override = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_xml_from_httpget : public virtual Abstract_xml_from_httpget {
  public:
    Class_xml_from_httpget();
    virtual ~Class_xml_from_httpget() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::Abstract_any_from_any_async::IFn fn) const override;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any val) const override;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

}
#endif
