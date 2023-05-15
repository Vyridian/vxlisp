#pragma once
#include <map>
#include <memory>
#include <string>
#include "../vx/core.hpp"

namespace vx_state {

  // forward declarations
  class Class_value_map;
  typedef std::shared_ptr<Class_value_map> Type_value_map;
  extern Type_value_map e_value_map;
  extern Type_value_map t_value_map;
  class Class_change;
  typedef std::shared_ptr<Class_change> Func_change;
  extern Func_change e_change;
  extern Func_change t_change;
  class Class_register;
  typedef std::shared_ptr<Class_register> Func_register;
  extern Func_register e_register;
  extern Func_register t_register;


  // (type value-map)
  class Class_value_map : public virtual vx_core::Class_map {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key) override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() override;
    // vx_new_from_map(T, Map<T>)
    template <class T> std::shared_ptr<T> vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval);
  };

  // (func change)
  class Class_change : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_boolean vx_change(vx_state::Type_value_map valuemap);
  };

  // (func register)
  class Class_register : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_boolean vx_register(vx_core::Type_statelistener listener);
  };

  // (func change)
  vx_core::Type_boolean f_change(vx_state::Type_value_map valuemap);

  // (func register)
  vx_core::Type_boolean f_register(vx_core::Type_statelistener listener);

}
