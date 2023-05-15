#pragma once
#include <memory>
#include <set>
#include <string>
#include <vector>
#include "../vx/core.hpp"
#include "../vx/data/textblock.hpp"

namespace vx_repl {

  // forward declarations
  class Class_liblist;
  typedef std::shared_ptr<Class_liblist> Type_liblist;
  extern Type_liblist e_liblist;
  extern Type_liblist t_liblist;
  class Class_repl;
  typedef std::shared_ptr<Class_repl> Type_repl;
  extern Type_repl e_repl;
  extern Type_repl t_repl;
  class Class_repllist;
  typedef std::shared_ptr<Class_repllist> Type_repllist;
  extern Type_repllist e_repllist;
  extern Type_repllist t_repllist;
  class Class_any_repl_from_functype_args;
  typedef std::shared_ptr<Class_any_repl_from_functype_args> Func_any_repl_from_functype_args;
  extern Func_any_repl_from_functype_args e_any_repl_from_functype_args;
  extern Func_any_repl_from_functype_args t_any_repl_from_functype_args;
  class Class_any_from_liblist_string;
  typedef std::shared_ptr<Class_any_from_liblist_string> Func_any_from_liblist_string;
  extern Func_any_from_liblist_string e_any_from_liblist_string;
  extern Func_any_from_liblist_string t_any_from_liblist_string;
  class Class_any_from_liblist_string_async;
  typedef std::shared_ptr<Class_any_from_liblist_string_async> Func_any_from_liblist_string_async;
  extern Func_any_from_liblist_string_async e_any_from_liblist_string_async;
  extern Func_any_from_liblist_string_async t_any_from_liblist_string_async;
  class Class_any_from_repl;
  typedef std::shared_ptr<Class_any_from_repl> Func_any_from_repl;
  extern Func_any_from_repl e_any_from_repl;
  extern Func_any_from_repl t_any_from_repl;
  class Class_any_from_repl_async;
  typedef std::shared_ptr<Class_any_from_repl_async> Func_any_from_repl_async;
  extern Func_any_from_repl_async e_any_from_repl_async;
  extern Func_any_from_repl_async t_any_from_repl_async;
  class Class_anylist_from_repllist;
  typedef std::shared_ptr<Class_anylist_from_repllist> Func_anylist_from_repllist;
  extern Func_anylist_from_repllist e_anylist_from_repllist;
  extern Func_anylist_from_repllist t_anylist_from_repllist;
  class Class_repl_from_liblist_string;
  typedef std::shared_ptr<Class_repl_from_liblist_string> Func_repl_from_liblist_string;
  extern Func_repl_from_liblist_string e_repl_from_liblist_string;
  extern Func_repl_from_liblist_string t_repl_from_liblist_string;


  // (type liblist)
  class Class_liblist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_core::Type_string> vx_p_list;

    // vx_liststring()
    virtual std::vector<vx_core::Type_string> vx_liststring();
    // vx_string(index)
    virtual vx_core::Type_string vx_string(vx_core::Type_int index);
  };

  // (type repl)
  class Class_repl : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // type()
    vx_core::Type_any vx_p_type;
    virtual vx_core::Type_any type();
    // repllist()
    vx_repl::Type_repllist vx_p_repllist;
    virtual vx_repl::Type_repllist repllist();
    // async()
    vx_core::Type_boolean vx_p_async;
    virtual vx_core::Type_boolean async();
    // val()
    vx_core::Type_any vx_p_val;
    virtual vx_core::Type_any val();
  };

  // (type repllist)
  class Class_repllist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_repl::Type_repl> vx_p_list;

    // vx_listrepl()
    virtual std::vector<vx_repl::Type_repl> vx_listrepl();
    // vx_repl(index)
    virtual vx_repl::Type_repl vx_repl(vx_core::Type_int index);
  };

  // (func any-repl<-functype-args)
  class Class_any_repl_from_functype_args : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_any vx_any_repl_from_functype_args(vx_core::Type_any type, vx_core::Type_anylist args);
  };

  // (func any<-liblist-string)
  class Class_any_from_liblist_string : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_any vx_any_from_liblist_string(vx_repl::Type_liblist liblist, vx_core::Type_string text, vx_core::Type_context context);
  };

  // (func any<-liblist-string-async)
  class Class_any_from_liblist_string_async : public vx_core::Class_func, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_any_from_liblist_string_async(vx_repl::Type_liblist liblist, vx_core::Type_string text, vx_core::Type_context context);
  };

  // (func any<-repl)
  class Class_any_from_repl : public vx_core::Class_any_from_any_context, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_context fn_new(vx_core::Class_any_from_any_context::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any_context(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value, vx_core::Type_context context);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_any vx_any_from_repl(vx_repl::Type_repl repl, vx_core::Type_context context);
  };

  // (func any<-repl-async)
  class Class_any_from_repl_async : public vx_core::Class_any_from_any_context_async, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_context_async fn_new(vx_core::Class_any_from_any_context_async::IFn fn);
    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> f_any_from_any_context_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value, vx_core::Type_context context);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_any_from_repl_async(vx_repl::Type_repl repl, vx_core::Type_context context);
  };

  // (func anylist<-repllist)
  class Class_anylist_from_repllist : public vx_core::Class_any_from_any_context, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_context fn_new(vx_core::Class_any_from_any_context::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any_context(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value, vx_core::Type_context context);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_anylist vx_anylist_from_repllist(vx_repl::Type_repllist repllist, vx_core::Type_context context);
  };

  // (func repl<-liblist-string)
  class Class_repl_from_liblist_string : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_repl::Type_repl vx_repl_from_liblist_string(vx_repl::Type_liblist liblist, vx_core::Type_string text);
  };

  // (func any-repl<-functype-args)
  vx_core::Type_any f_any_repl_from_functype_args(vx_core::Type_any type, vx_core::Type_anylist args);

  // (func any<-liblist-string)
  vx_core::Type_any f_any_from_liblist_string(vx_repl::Type_liblist liblist, vx_core::Type_string text, vx_core::Type_context context);

  // (func any<-liblist-string-async)
  std::shared_ptr<vx_core::Async<vx_core::Type_any>> f_any_from_liblist_string_async(vx_repl::Type_liblist liblist, vx_core::Type_string text, vx_core::Type_context context);

  // (func any<-repl)
  vx_core::Type_any f_any_from_repl(vx_repl::Type_repl repl, vx_core::Type_context context);

  // (func any<-repl-async)
  std::shared_ptr<vx_core::Async<vx_core::Type_any>> f_any_from_repl_async(vx_repl::Type_repl repl, vx_core::Type_context context);

  // (func anylist<-repllist)
  vx_core::Type_anylist f_anylist_from_repllist(vx_repl::Type_repllist repllist, vx_core::Type_context context);

  // (func repl<-liblist-string)
  vx_repl::Type_repl f_repl_from_liblist_string(vx_repl::Type_liblist liblist, vx_core::Type_string text);

}
