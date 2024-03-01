#ifndef VX_STATE_HPP
#define VX_STATE_HPP
#include "../vx/core.hpp"

namespace vx_state {


  // forward declarations
  class Abstract_valuemap;
  typedef Abstract_valuemap* Type_valuemap;
  extern Type_valuemap e_valuemap;
  extern Type_valuemap t_valuemap;
  class Abstract_any_readstate_from_mapname_name;
  typedef Abstract_any_readstate_from_mapname_name* Func_any_readstate_from_mapname_name;
  extern Func_any_readstate_from_mapname_name e_any_readstate_from_mapname_name;
  extern Func_any_readstate_from_mapname_name t_any_readstate_from_mapname_name;
  class Abstract_any_readstate_from_name;
  typedef Abstract_any_readstate_from_name* Func_any_readstate_from_name;
  extern Func_any_readstate_from_name e_any_readstate_from_name;
  extern Func_any_readstate_from_name t_any_readstate_from_name;
  class Abstract_boolean_writestate_from_mapname_name_value;
  typedef Abstract_boolean_writestate_from_mapname_name_value* Func_boolean_writestate_from_mapname_name_value;
  extern Func_boolean_writestate_from_mapname_name_value e_boolean_writestate_from_mapname_name_value;
  extern Func_boolean_writestate_from_mapname_name_value t_boolean_writestate_from_mapname_name_value;
  class Abstract_boolean_writestate_from_name_value;
  typedef Abstract_boolean_writestate_from_name_value* Func_boolean_writestate_from_name_value;
  extern Func_boolean_writestate_from_name_value e_boolean_writestate_from_name_value;
  extern Func_boolean_writestate_from_name_value t_boolean_writestate_from_name_value;
  class Abstract_boolean_writestate_from_statelistener;
  typedef Abstract_boolean_writestate_from_statelistener* Func_boolean_writestate_from_statelistener;
  extern Func_boolean_writestate_from_statelistener e_boolean_writestate_from_statelistener;
  extern Func_boolean_writestate_from_statelistener t_boolean_writestate_from_statelistener;
  class Abstract_change;
  typedef Abstract_change* Func_change;
  extern Func_change e_change;
  extern Func_change t_change;
  class Abstract_register;
  typedef Abstract_register* Func_register;
  extern Func_register e_register;
  extern Func_register t_register;
  class Abstract_state_from_context;
  typedef Abstract_state_from_context* Func_state_from_context;
  extern Func_state_from_context e_state_from_context;
  extern Func_state_from_context t_state_from_context;
  class Abstract_statelistener_readstate_from_name;
  typedef Abstract_statelistener_readstate_from_name* Func_statelistener_readstate_from_name;
  extern Func_statelistener_readstate_from_name e_statelistener_readstate_from_name;
  extern Func_statelistener_readstate_from_name t_statelistener_readstate_from_name;
  class Abstract_statelistenermap_readstate;
  typedef Abstract_statelistenermap_readstate* Func_statelistenermap_readstate;
  extern Func_statelistenermap_readstate e_statelistenermap_readstate;
  extern Func_statelistenermap_readstate t_statelistenermap_readstate;
  class Abstract_value_readstate_from_name;
  typedef Abstract_value_readstate_from_name* Func_value_readstate_from_name;
  extern Func_value_readstate_from_name e_value_readstate_from_name;
  extern Func_value_readstate_from_name t_value_readstate_from_name;
  class Abstract_valuemap_readstate_from_mapname;
  typedef Abstract_valuemap_readstate_from_mapname* Func_valuemap_readstate_from_mapname;
  extern Func_valuemap_readstate_from_mapname e_valuemap_readstate_from_mapname;
  extern Func_valuemap_readstate_from_mapname t_valuemap_readstate_from_mapname;
  // (func boolean-writestate<-mapname-name-value)
  vx_core::Type_boolean f_boolean_writestate_from_mapname_name_value(vx_core::Type_context context, vx_core::Type_string mapname, vx_core::Type_string name, vx_core::Type_any value);

  // (func boolean-writestate<-name-value)
  vx_core::Type_boolean f_boolean_writestate_from_name_value(vx_core::Type_context context, vx_core::Type_string name, vx_core::Type_any value);

  // (func boolean-writestate<-statelistener)
  vx_core::Type_boolean f_boolean_writestate_from_statelistener(vx_core::Type_context context, vx_core::Type_statelistener statelistener);

  // (func change)
  vx_core::Type_boolean f_change(vx_state::Type_valuemap valuemap);

  // (func register)
  vx_core::Type_boolean f_register(vx_core::Type_statelistener listener);

  // (func state<-context)
  vx_core::Type_state f_state_from_context(vx_core::Type_context context);

  // (func statelistener-readstate<-name)
  vx_core::Type_statelistener f_statelistener_readstate_from_name(vx_core::Type_context context, vx_core::Type_string name);

  // (func statelistenermap-readstate)
  vx_core::Type_statelistenermap f_statelistenermap_readstate(vx_core::Type_context context);

  // (func value-readstate<-name)
  vx_core::Type_any f_value_readstate_from_name(vx_core::Type_context context, vx_core::Type_string name);

  // (func valuemap-readstate<-mapname)
  vx_state::Type_valuemap f_valuemap_readstate_from_mapname(vx_core::Type_context context, vx_core::Type_string mapname);

  // (type valuemap)
  class Abstract_valuemap : public virtual vx_core::Abstract_map {
  public:
    Abstract_valuemap() {};
    virtual ~Abstract_valuemap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
  };
  class Class_valuemap : public virtual Abstract_valuemap {
  public:
    Class_valuemap();
    virtual ~Class_valuemap() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const override;
  };

  // (func any-readstate<-mapname-name)
  class Abstract_any_readstate_from_mapname_name : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_readstate_from_mapname_name() {};
    virtual ~Abstract_any_readstate_from_mapname_name() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_readstate_from_mapname_name : public virtual Abstract_any_readstate_from_mapname_name {
  public:
    Class_any_readstate_from_mapname_name();
    virtual ~Class_any_readstate_from_mapname_name() override;
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

  // (func any-readstate<-name)
  class Abstract_any_readstate_from_name : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_readstate_from_name() {};
    virtual ~Abstract_any_readstate_from_name() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_readstate_from_name : public virtual Abstract_any_readstate_from_name {
  public:
    Class_any_readstate_from_name();
    virtual ~Class_any_readstate_from_name() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func boolean-writestate<-mapname-name-value)
  class Abstract_boolean_writestate_from_mapname_name_value : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_boolean_writestate_from_mapname_name_value() {};
    virtual ~Abstract_boolean_writestate_from_mapname_name_value() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_boolean_writestate_from_mapname_name_value : public virtual Abstract_boolean_writestate_from_mapname_name_value {
  public:
    Class_boolean_writestate_from_mapname_name_value();
    virtual ~Class_boolean_writestate_from_mapname_name_value() override;
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

  // (func boolean-writestate<-name-value)
  class Abstract_boolean_writestate_from_name_value : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_boolean_writestate_from_name_value() {};
    virtual ~Abstract_boolean_writestate_from_name_value() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_boolean_writestate_from_name_value : public virtual Abstract_boolean_writestate_from_name_value {
  public:
    Class_boolean_writestate_from_name_value();
    virtual ~Class_boolean_writestate_from_name_value() override;
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

  // (func boolean-writestate<-statelistener)
  class Abstract_boolean_writestate_from_statelistener : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_boolean_writestate_from_statelistener() {};
    virtual ~Abstract_boolean_writestate_from_statelistener() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_boolean_writestate_from_statelistener : public virtual Abstract_boolean_writestate_from_statelistener {
  public:
    Class_boolean_writestate_from_statelistener();
    virtual ~Class_boolean_writestate_from_statelistener() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func change)
  class Abstract_change : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_change() {};
    virtual ~Abstract_change() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_change : public virtual Abstract_change {
  public:
    Class_change();
    virtual ~Class_change() override;
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

  // (func register)
  class Abstract_register : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_register() {};
    virtual ~Abstract_register() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_register : public virtual Abstract_register {
  public:
    Class_register();
    virtual ~Class_register() override;
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

  // (func state<-context)
  class Abstract_state_from_context : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_state_from_context() {};
    virtual ~Abstract_state_from_context() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_state_from_context : public virtual Abstract_state_from_context {
  public:
    Class_state_from_context();
    virtual ~Class_state_from_context() override;
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

  // (func statelistener-readstate<-name)
  class Abstract_statelistener_readstate_from_name : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_statelistener_readstate_from_name() {};
    virtual ~Abstract_statelistener_readstate_from_name() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_statelistener_readstate_from_name : public virtual Abstract_statelistener_readstate_from_name {
  public:
    Class_statelistener_readstate_from_name();
    virtual ~Class_statelistener_readstate_from_name() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func statelistenermap-readstate)
  class Abstract_statelistenermap_readstate : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_statelistenermap_readstate() {};
    virtual ~Abstract_statelistenermap_readstate() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_statelistenermap_readstate : public virtual Abstract_statelistenermap_readstate {
  public:
    Class_statelistenermap_readstate();
    virtual ~Class_statelistenermap_readstate() override;
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

  // (func value-readstate<-name)
  class Abstract_value_readstate_from_name : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_value_readstate_from_name() {};
    virtual ~Abstract_value_readstate_from_name() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_value_readstate_from_name : public virtual Abstract_value_readstate_from_name {
  public:
    Class_value_readstate_from_name();
    virtual ~Class_value_readstate_from_name() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func valuemap-readstate<-mapname)
  class Abstract_valuemap_readstate_from_mapname : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_valuemap_readstate_from_mapname() {};
    virtual ~Abstract_valuemap_readstate_from_mapname() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_valuemap_readstate_from_mapname : public virtual Abstract_valuemap_readstate_from_mapname {
  public:
    Class_valuemap_readstate_from_mapname();
    virtual ~Class_valuemap_readstate_from_mapname() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func any-readstate<-mapname-name)
  template <class T> T* f_any_readstate_from_mapname_name(T* generic_any_1, vx_core::Type_context context, vx_core::Type_string mapname, vx_core::Type_string name) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve({mapname, name});
    output = vx_core::f_let(
      generic_any_1,
      vx_core::t_any_from_func->vx_fn_new({context, mapname, generic_any_1, name}, [context, mapname, generic_any_1, name]() {
        vx_state::Type_valuemap submap = vx_state::f_valuemap_readstate_from_mapname(context, mapname);
        vx_core::vx_ref_plus(submap);
        vx_core::Type_any output_1 = vx_core::f_any_from_map(generic_any_1, submap, name);
        vx_core::vx_release_one_except(submap, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({mapname, name}, output);
    return output;
  }

  // (func any-readstate<-name)
  template <class T> T* f_any_readstate_from_name(T* generic_any_1, vx_core::Type_context context, vx_core::Type_string name) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve(name);
    output = vx_core::f_any_from_any(
      generic_any_1,
      vx_state::f_value_readstate_from_name(context, name)
    );
    vx_core::vx_release_one_except(name, output);
    return output;
  }

  class vx_Class_package {
  public:
    vx_Class_package();
    void init();
  };
  inline vx_Class_package const vx_package;

}

#endif
