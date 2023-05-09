#pragma once
#include <any>
#include <map>
#include <string>
#include "../vx/core.hpp"

namespace vx_state {

  // (type value-map)
  class Type_value_map : public virtual vx_core::Type_map {
  public:
    template<typename... Args> vx_state::Type_value_map* vx_new(Args*... args);
    template<typename... Args> vx_state::Type_value_map* vx_copy(Args*... args);
    virtual vx_state::Type_value_map* vx_empty();
    virtual vx_state::Type_value_map* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
  };
  extern vx_state::Type_value_map* e_value_map;
  extern vx_state::Type_value_map* t_value_map;

  // (func change)
  class Func_change : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_state::Func_change* vx_new(Args*... args);
    template<typename... Args> vx_state::Func_change* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_state::Func_change* vx_empty();
    virtual vx_state::Func_change* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_change(vx_state::Type_value_map* valuemap);
  };
  extern Func_change* e_change;
  extern Func_change* t_change;

  // (func register)
  class Func_register : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_state::Func_register* vx_new(Args*... args);
    template<typename... Args> vx_state::Func_register* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_state::Func_register* vx_empty();
    virtual vx_state::Func_register* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_register(vx_core::Type_statelistener* listener);
  };
  extern Func_register* e_register;
  extern Func_register* t_register;

  // (func change)
  vx_core::Type_boolean* f_change(vx_state::Type_value_map* valuemap);

  // (func register)
  vx_core::Type_boolean* f_register(vx_core::Type_statelistener* listener);

}
