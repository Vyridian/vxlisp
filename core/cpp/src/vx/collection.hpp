#pragma once
#include "../vx/core.hpp"
#include "../vx/type.hpp"

namespace vx_collection {

  // (func is-list)
  class Func_is_list : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_collection::Func_is_list* vx_new(Args*... args);
    template<typename... Args> vx_collection::Func_is_list* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_collection::Func_is_list* vx_empty();
    virtual vx_collection::Func_is_list* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_is_list(vx_core::Type_any* val);
  };
  extern Func_is_list* e_is_list;
  extern Func_is_list* t_is_list;

  // (func is-map)
  class Func_is_map : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_collection::Func_is_map* vx_new(Args*... args);
    template<typename... Args> vx_collection::Func_is_map* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_collection::Func_is_map* vx_empty();
    virtual vx_collection::Func_is_map* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_is_map(vx_core::Type_any* val);
  };
  extern Func_is_map* e_is_map;
  extern Func_is_map* t_is_map;

  // (func list<-list-end)
  class Func_list_from_list_end : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_collection::Func_list_from_list_end* vx_new(Args*... args);
    template<typename... Args> vx_collection::Func_list_from_list_end* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_collection::Func_list_from_list_end* vx_empty();
    virtual vx_collection::Func_list_from_list_end* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class X> X* vx_list_from_list_end(X* generic_any_1, X* values, vx_core::Type_int* end);
  };
  extern Func_list_from_list_end* e_list_from_list_end;
  extern Func_list_from_list_end* t_list_from_list_end;

  // (func list<-list-filtertypes)
  class Func_list_from_list_filtertypes : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_collection::Func_list_from_list_filtertypes* vx_new(Args*... args);
    template<typename... Args> vx_collection::Func_list_from_list_filtertypes* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_collection::Func_list_from_list_filtertypes* vx_empty();
    virtual vx_collection::Func_list_from_list_filtertypes* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class X, class Y> X* vx_list_from_list_filtertypes(X* generic_any_1, Y* vallist, vx_core::Type_typelist* filtertypes);
  };
  extern Func_list_from_list_filtertypes* e_list_from_list_filtertypes;
  extern Func_list_from_list_filtertypes* t_list_from_list_filtertypes;

  // (func list<-list-fn-filter)
  class Func_list_from_list_fn_filter : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_collection::Func_list_from_list_fn_filter* vx_new(Args*... args);
    template<typename... Args> vx_collection::Func_list_from_list_fn_filter* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_collection::Func_list_from_list_fn_filter* vx_empty();
    virtual vx_collection::Func_list_from_list_fn_filter* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class X, class Y> X* vx_list_from_list_fn_filter(X* generic_any_1, Y* vallist, vx_core::Func_any_from_any* fn_filter);
  };
  extern Func_list_from_list_fn_filter* e_list_from_list_fn_filter;
  extern Func_list_from_list_fn_filter* t_list_from_list_fn_filter;

  // (func list<-list-start)
  class Func_list_from_list_start : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_collection::Func_list_from_list_start* vx_new(Args*... args);
    template<typename... Args> vx_collection::Func_list_from_list_start* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_collection::Func_list_from_list_start* vx_empty();
    virtual vx_collection::Func_list_from_list_start* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class X> X* vx_list_from_list_start(X* generic_any_1, X* values, vx_core::Type_int* start);
  };
  extern Func_list_from_list_start* e_list_from_list_start;
  extern Func_list_from_list_start* t_list_from_list_start;

  // (func list<-list-start-end)
  class Func_list_from_list_start_end : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_collection::Func_list_from_list_start_end* vx_new(Args*... args);
    template<typename... Args> vx_collection::Func_list_from_list_start_end* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_collection::Func_list_from_list_start_end* vx_empty();
    virtual vx_collection::Func_list_from_list_start_end* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    template <class X> X* vx_list_from_list_start_end(X* generic_any_1, X* values, vx_core::Type_int* start, vx_core::Type_int* end);
  };
  extern Func_list_from_list_start_end* e_list_from_list_start_end;
  extern Func_list_from_list_start_end* t_list_from_list_start_end;

  // (func is-list)
  vx_core::Type_boolean* f_is_list(vx_core::Type_any* val);

  // (func is-map)
  vx_core::Type_boolean* f_is_map(vx_core::Type_any* val);

  // (func list<-list-end)
  template <class X> X* f_list_from_list_end(X* generic_any_1, X* values, vx_core::Type_int* end);

  // (func list<-list-filtertypes)
  template <class X, class Y> X* f_list_from_list_filtertypes(X* generic_any_1, Y* vallist, vx_core::Type_typelist* filtertypes);

  // (func list<-list-fn-filter)
  template <class X, class Y> X* f_list_from_list_fn_filter(X* generic_any_1, Y* vallist, vx_core::Func_any_from_any* fn_filter);

  // (func list<-list-start)
  template <class X> X* f_list_from_list_start(X* generic_any_1, X* values, vx_core::Type_int* start);

  // (func list<-list-start-end)
  template <class X> X* f_list_from_list_start_end(X* generic_any_1, X* values, vx_core::Type_int* start, vx_core::Type_int* end);

}
