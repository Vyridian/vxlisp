#ifndef VX_WEB_HTMLDOC_HPP
#define VX_WEB_HTMLDOC_HPP
#include "../../vx/core.hpp"
#include "../../vx/event.hpp"
#include "../../vx/web/html.hpp"

namespace vx_web_htmldoc {


  // forward declarations
  class Abstract_any_data_from_id;
  typedef Abstract_any_data_from_id* Func_any_data_from_id;
  extern Func_any_data_from_id e_any_data_from_id;
  extern Func_any_data_from_id t_any_data_from_id;
  class Abstract_boolean_replace_from_id_htmltext;
  typedef Abstract_boolean_replace_from_id_htmltext* Func_boolean_replace_from_id_htmltext;
  extern Func_boolean_replace_from_id_htmltext e_boolean_replace_from_id_htmltext;
  extern Func_boolean_replace_from_id_htmltext t_boolean_replace_from_id_htmltext;
  class Abstract_boolean_replace_from_id_htmltext_data_eventmap;
  typedef Abstract_boolean_replace_from_id_htmltext_data_eventmap* Func_boolean_replace_from_id_htmltext_data_eventmap;
  extern Func_boolean_replace_from_id_htmltext_data_eventmap e_boolean_replace_from_id_htmltext_data_eventmap;
  extern Func_boolean_replace_from_id_htmltext_data_eventmap t_boolean_replace_from_id_htmltext_data_eventmap;
  class Abstract_boolean_write_stylesheet_from_string;
  typedef Abstract_boolean_write_stylesheet_from_string* Func_boolean_write_stylesheet_from_string;
  extern Func_boolean_write_stylesheet_from_string e_boolean_write_stylesheet_from_string;
  extern Func_boolean_write_stylesheet_from_string t_boolean_write_stylesheet_from_string;
  class Abstract_boolean_write_from_id_htmltext;
  typedef Abstract_boolean_write_from_id_htmltext* Func_boolean_write_from_id_htmltext;
  extern Func_boolean_write_from_id_htmltext e_boolean_write_from_id_htmltext;
  extern Func_boolean_write_from_id_htmltext t_boolean_write_from_id_htmltext;
  class Abstract_boolean_write_from_stylesheet;
  typedef Abstract_boolean_write_from_stylesheet* Func_boolean_write_from_stylesheet;
  extern Func_boolean_write_from_stylesheet e_boolean_write_from_stylesheet;
  extern Func_boolean_write_from_stylesheet t_boolean_write_from_stylesheet;
  class Abstract_string_from_id;
  typedef Abstract_string_from_id* Func_string_from_id;
  extern Func_string_from_id e_string_from_id;
  extern Func_string_from_id t_string_from_id;
  // (func any-data<-id)
  vx_core::Type_any f_any_data_from_id(vx_core::Type_string id);

  // (func boolean-replace<-id-htmltext)
  vx_core::Type_boolean f_boolean_replace_from_id_htmltext(vx_core::Type_string id, vx_core::Type_string htmltext);

  // (func boolean-replace<-id-htmltext-data-eventmap)
  vx_core::Type_boolean f_boolean_replace_from_id_htmltext_data_eventmap(vx_core::Type_string id, vx_core::Type_string htmltext, vx_core::Type_any data, vx_event::Type_eventmap eventmap);

  // (func boolean-write-stylesheet<-string)
  vx_core::vx_Type_async f_boolean_write_stylesheet_from_string(vx_core::Type_string text);

  // (func boolean-write<-id-htmltext)
  vx_core::Type_boolean f_boolean_write_from_id_htmltext(vx_core::Type_string id, vx_core::Type_string htmltext);

  // (func boolean-write<-stylesheet)
  vx_core::vx_Type_async f_boolean_write_from_stylesheet(vx_web_html::Type_stylesheet stylesheet);

  // (func string<-id)
  vx_core::Type_string f_string_from_id(vx_core::Type_string id);

  // (func any-data<-id)
  class Abstract_any_data_from_id : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_data_from_id() {};
    virtual ~Abstract_any_data_from_id() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_data_from_id : public virtual Abstract_any_data_from_id {
  public:
    Class_any_data_from_id();
    virtual ~Class_any_data_from_id() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func boolean-replace<-id-htmltext)
  class Abstract_boolean_replace_from_id_htmltext : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_boolean_replace_from_id_htmltext() {};
    virtual ~Abstract_boolean_replace_from_id_htmltext() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_boolean_replace_from_id_htmltext : public virtual Abstract_boolean_replace_from_id_htmltext {
  public:
    Class_boolean_replace_from_id_htmltext();
    virtual ~Class_boolean_replace_from_id_htmltext() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func boolean-replace<-id-htmltext-data-eventmap)
  class Abstract_boolean_replace_from_id_htmltext_data_eventmap : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_boolean_replace_from_id_htmltext_data_eventmap() {};
    virtual ~Abstract_boolean_replace_from_id_htmltext_data_eventmap() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_boolean_replace_from_id_htmltext_data_eventmap : public virtual Abstract_boolean_replace_from_id_htmltext_data_eventmap {
  public:
    Class_boolean_replace_from_id_htmltext_data_eventmap();
    virtual ~Class_boolean_replace_from_id_htmltext_data_eventmap() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func boolean-write-stylesheet<-string)
  class Abstract_boolean_write_stylesheet_from_string : public vx_core::Abstract_any_from_any_async, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_boolean_write_stylesheet_from_string() {};
    virtual ~Abstract_boolean_write_stylesheet_from_string() = 0;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const override = 0;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const override = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_boolean_write_stylesheet_from_string : public virtual Abstract_boolean_write_stylesheet_from_string {
  public:
    Class_boolean_write_stylesheet_from_string();
    virtual ~Class_boolean_write_stylesheet_from_string() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const override;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const override;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func boolean-write<-id-htmltext)
  class Abstract_boolean_write_from_id_htmltext : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_boolean_write_from_id_htmltext() {};
    virtual ~Abstract_boolean_write_from_id_htmltext() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_boolean_write_from_id_htmltext : public virtual Abstract_boolean_write_from_id_htmltext {
  public:
    Class_boolean_write_from_id_htmltext();
    virtual ~Class_boolean_write_from_id_htmltext() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func boolean-write<-stylesheet)
  class Abstract_boolean_write_from_stylesheet : public vx_core::Abstract_any_from_any_async, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_boolean_write_from_stylesheet() {};
    virtual ~Abstract_boolean_write_from_stylesheet() = 0;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const override = 0;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const override = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_boolean_write_from_stylesheet : public virtual Abstract_boolean_write_from_stylesheet {
  public:
    Class_boolean_write_from_stylesheet();
    virtual ~Class_boolean_write_from_stylesheet() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const override;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const override;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func string<-id)
  class Abstract_string_from_id : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_id() {};
    virtual ~Abstract_string_from_id() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_id : public virtual Abstract_string_from_id {
  public:
    Class_string_from_id();
    virtual ~Class_string_from_id() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  class vx_Class_package {
  public:
    vx_Class_package();
    void init();
  };
  inline vx_Class_package const vx_package;

}

#endif
