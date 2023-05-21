#ifndef vx_collection_hpp
#define vx_collection_hpp
#include <memory>
#include "../vx/core.hpp"
#include "../vx/type.hpp"

namespace vx_collection {

  // forward declarations
  class Class_is_list;
  typedef std::shared_ptr<Class_is_list> Func_is_list;
  extern Func_is_list e_is_list;
  extern Func_is_list t_is_list;
  class Class_is_map;
  typedef std::shared_ptr<Class_is_map> Func_is_map;
  extern Func_is_map e_is_map;
  extern Func_is_map t_is_map;
  class Class_list_from_list_end;
  typedef std::shared_ptr<Class_list_from_list_end> Func_list_from_list_end;
  extern Func_list_from_list_end e_list_from_list_end;
  extern Func_list_from_list_end t_list_from_list_end;
  class Class_list_from_list_filtertypes;
  typedef std::shared_ptr<Class_list_from_list_filtertypes> Func_list_from_list_filtertypes;
  extern Func_list_from_list_filtertypes e_list_from_list_filtertypes;
  extern Func_list_from_list_filtertypes t_list_from_list_filtertypes;
  class Class_list_from_list_fn_filter;
  typedef std::shared_ptr<Class_list_from_list_fn_filter> Func_list_from_list_fn_filter;
  extern Func_list_from_list_fn_filter e_list_from_list_fn_filter;
  extern Func_list_from_list_fn_filter t_list_from_list_fn_filter;
  class Class_list_from_list_start;
  typedef std::shared_ptr<Class_list_from_list_start> Func_list_from_list_start;
  extern Func_list_from_list_start e_list_from_list_start;
  extern Func_list_from_list_start t_list_from_list_start;
  class Class_list_from_list_start_end;
  typedef std::shared_ptr<Class_list_from_list_start_end> Func_list_from_list_start_end;
  extern Func_list_from_list_start_end e_list_from_list_start_end;
  extern Func_list_from_list_start_end t_list_from_list_start_end;


  // (func is-list)
  class Class_is_list : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_boolean vx_f_is_list(vx_core::Type_any val);
  };

  // (func is-map)
  class Class_is_map : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_boolean vx_f_is_map(vx_core::Type_any val);
  };

  // (func list<-list-end)
  class Class_list_from_list_end : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class X> std::shared_ptr<X> vx_f_list_from_list_end(std::shared_ptr<X> generic_any_1, std::shared_ptr<X> values, vx_core::Type_int end);
  };

  // (func list<-list-filtertypes)
  class Class_list_from_list_filtertypes : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class X, class Y> std::shared_ptr<X> vx_f_list_from_list_filtertypes(std::shared_ptr<X> generic_any_1, std::shared_ptr<Y> vallist, vx_core::Type_typelist filtertypes);
  };

  // (func list<-list-fn-filter)
  class Class_list_from_list_fn_filter : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class X, class Y> std::shared_ptr<X> vx_f_list_from_list_fn_filter(std::shared_ptr<X> generic_any_1, std::shared_ptr<Y> vallist, vx_core::Func_any_from_any fn_filter);
  };

  // (func list<-list-start)
  class Class_list_from_list_start : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class X> std::shared_ptr<X> vx_f_list_from_list_start(std::shared_ptr<X> generic_any_1, std::shared_ptr<X> values, vx_core::Type_int start);
  };

  // (func list<-list-start-end)
  class Class_list_from_list_start_end : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    template <class X> std::shared_ptr<X> vx_f_list_from_list_start_end(std::shared_ptr<X> generic_any_1, std::shared_ptr<X> values, vx_core::Type_int start, vx_core::Type_int end);
  };

  // (func is-list)
  vx_core::Type_boolean f_is_list(vx_core::Type_any val);

  // (func is-map)
  vx_core::Type_boolean f_is_map(vx_core::Type_any val);

  // (func list<-list-end)
  template <class X> std::shared_ptr<X> f_list_from_list_end(std::shared_ptr<X> generic_any_1, std::shared_ptr<X> values, vx_core::Type_int end);

  // (func list<-list-filtertypes)
  template <class X, class Y> std::shared_ptr<X> f_list_from_list_filtertypes(std::shared_ptr<X> generic_any_1, std::shared_ptr<Y> vallist, vx_core::Type_typelist filtertypes);

  // (func list<-list-fn-filter)
  template <class X, class Y> std::shared_ptr<X> f_list_from_list_fn_filter(std::shared_ptr<X> generic_any_1, std::shared_ptr<Y> vallist, vx_core::Func_any_from_any fn_filter);

  // (func list<-list-start)
  template <class X> std::shared_ptr<X> f_list_from_list_start(std::shared_ptr<X> generic_any_1, std::shared_ptr<X> values, vx_core::Type_int start);

  // (func list<-list-start-end)
  template <class X> std::shared_ptr<X> f_list_from_list_start_end(std::shared_ptr<X> generic_any_1, std::shared_ptr<X> values, vx_core::Type_int start, vx_core::Type_int end);

}
#endif
