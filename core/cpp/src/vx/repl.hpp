#pragma once
#include <any>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "../vx/core.hpp"
#include "../vx/data/textblock.hpp"

namespace vx_repl {

  // forward declarations
  class Type_liblist;
  extern Type_liblist* e_liblist;
  extern Type_liblist* t_liblist;
  class Type_repl;
  extern Type_repl* e_repl;
  extern Type_repl* t_repl;
  class Type_repllist;
  extern Type_repllist* e_repllist;
  extern Type_repllist* t_repllist;
  class Func_any_repl_from_functype_args;
  extern Func_any_repl_from_functype_args* e_any_repl_from_functype_args;
  extern Func_any_repl_from_functype_args* t_any_repl_from_functype_args;
  class Func_any_from_liblist_string;
  extern Func_any_from_liblist_string* e_any_from_liblist_string;
  extern Func_any_from_liblist_string* t_any_from_liblist_string;
  class Func_any_from_liblist_string_async;
  extern Func_any_from_liblist_string_async* e_any_from_liblist_string_async;
  extern Func_any_from_liblist_string_async* t_any_from_liblist_string_async;
  class Func_any_from_repl;
  extern Func_any_from_repl* e_any_from_repl;
  extern Func_any_from_repl* t_any_from_repl;
  class Func_any_from_repl_async;
  extern Func_any_from_repl_async* e_any_from_repl_async;
  extern Func_any_from_repl_async* t_any_from_repl_async;
  class Func_anylist_from_repllist;
  extern Func_anylist_from_repllist* e_anylist_from_repllist;
  extern Func_anylist_from_repllist* t_anylist_from_repllist;
  class Func_repl_from_liblist_string;
  extern Func_repl_from_liblist_string* e_repl_from_liblist_string;
  extern Func_repl_from_liblist_string* t_repl_from_liblist_string;


  // (type liblist)
  class Type_liblist : public virtual vx_core::Type_list {
  public:
    template<class... Args> vx_repl::Type_liblist* vx_new(Args*... args);
    template<class... Args> vx_repl::Type_liblist* vx_copy(Args*... args);
    virtual vx_repl::Type_liblist* vx_empty();
    virtual vx_repl::Type_liblist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_core::Type_string*> vx_p_list;

    // vx_liststring()
    virtual std::vector<vx_core::Type_string*> vx_liststring();
    // vx_string(index)
    virtual vx_core::Type_string* vx_string(vx_core::Type_int* index);
  };

  // (type repl)
  class Type_repl : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_repl::Type_repl* vx_new(Args*... args);
    template<class... Args> vx_repl::Type_repl* vx_copy(Args*... args);
    virtual vx_repl::Type_repl* vx_empty();
    virtual vx_repl::Type_repl* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // type()
    vx_core::Type_any* vx_p_type;
    virtual vx_core::Type_any* type();
    // repllist()
    vx_repl::Type_repllist* vx_p_repllist;
    virtual vx_repl::Type_repllist* repllist();
    // async()
    vx_core::Type_boolean* vx_p_async;
    virtual vx_core::Type_boolean* async();
    // val()
    vx_core::Type_any* vx_p_val;
    virtual vx_core::Type_any* val();
  };

  // (type repllist)
  class Type_repllist : public virtual vx_core::Type_list {
  public:
    template<class... Args> vx_repl::Type_repllist* vx_new(Args*... args);
    template<class... Args> vx_repl::Type_repllist* vx_copy(Args*... args);
    virtual vx_repl::Type_repllist* vx_empty();
    virtual vx_repl::Type_repllist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_repl::Type_repl*> vx_p_list;

    // vx_listrepl()
    virtual std::vector<vx_repl::Type_repl*> vx_listrepl();
    // vx_repl(index)
    virtual vx_repl::Type_repl* vx_repl(vx_core::Type_int* index);
  };

  // (func any-repl<-functype-args)
  class Func_any_repl_from_functype_args : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_repl::Func_any_repl_from_functype_args* vx_new(Args*... args);
    template<class... Args> vx_repl::Func_any_repl_from_functype_args* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_repl::Func_any_repl_from_functype_args* vx_empty();
    virtual vx_repl::Func_any_repl_from_functype_args* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_any* vx_any_repl_from_functype_args(vx_core::Type_any* type, vx_core::Type_anylist* args);
  };

  // (func any<-liblist-string)
  class Func_any_from_liblist_string : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_repl::Func_any_from_liblist_string* vx_new(Args*... args);
    template<class... Args> vx_repl::Func_any_from_liblist_string* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_repl::Func_any_from_liblist_string* vx_empty();
    virtual vx_repl::Func_any_from_liblist_string* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_any* vx_any_from_liblist_string(vx_repl::Type_liblist* liblist, vx_core::Type_string* text, vx_core::Type_context* context);
  };

  // (func any<-liblist-string-async)
  class Func_any_from_liblist_string_async : public vx_core::Type_func, public virtual vx_core::Type_replfunc_async {
  public:
    template<class... Args> vx_repl::Func_any_from_liblist_string_async* vx_new(Args*... args);
    template<class... Args> vx_repl::Func_any_from_liblist_string_async* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_repl::Func_any_from_liblist_string_async* vx_empty();
    virtual vx_repl::Func_any_from_liblist_string_async* vx_type();
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Async<vx_core::Type_any*>* vx_any_from_liblist_string_async(vx_repl::Type_liblist* liblist, vx_core::Type_string* text, vx_core::Type_context* context);
  };

  // (func any<-repl)
  class Func_any_from_repl : public vx_core::Func_any_from_any_context, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_repl::Func_any_from_repl* vx_new(Args*... args);
    template<class... Args> vx_repl::Func_any_from_repl* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_repl::Func_any_from_repl* vx_empty();
    virtual vx_repl::Func_any_from_repl* vx_type();
    virtual vx_core::Func_any_from_any_context* fn_new(vx_core::Func_any_from_any_context::IFn fn);
    template <class T, class U> T* f_any_from_any_context(T* generic_any_1, U* value, vx_core::Type_context* context);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_any* vx_any_from_repl(vx_repl::Type_repl* repl, vx_core::Type_context* context);
  };

  // (func any<-repl-async)
  class Func_any_from_repl_async : public vx_core::Func_any_from_any_context_async, public virtual vx_core::Type_replfunc_async {
  public:
    template<class... Args> vx_repl::Func_any_from_repl_async* vx_new(Args*... args);
    template<class... Args> vx_repl::Func_any_from_repl_async* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_repl::Func_any_from_repl_async* vx_empty();
    virtual vx_repl::Func_any_from_repl_async* vx_type();
    virtual vx_core::Func_any_from_any_context_async* fn_new(vx_core::Func_any_from_any_context_async::IFn fn);
    template <class T, class U> vx_core::Async<T*>* f_any_from_any_context_async(T* generic_any_1, U* value, vx_core::Type_context* context);
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Async<vx_core::Type_any*>* vx_any_from_repl_async(vx_repl::Type_repl* repl, vx_core::Type_context* context);
  };

  // (func anylist<-repllist)
  class Func_anylist_from_repllist : public vx_core::Func_any_from_any_context, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_repl::Func_anylist_from_repllist* vx_new(Args*... args);
    template<class... Args> vx_repl::Func_anylist_from_repllist* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_repl::Func_anylist_from_repllist* vx_empty();
    virtual vx_repl::Func_anylist_from_repllist* vx_type();
    virtual vx_core::Func_any_from_any_context* fn_new(vx_core::Func_any_from_any_context::IFn fn);
    template <class T, class U> T* f_any_from_any_context(T* generic_any_1, U* value, vx_core::Type_context* context);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_anylist* vx_anylist_from_repllist(vx_repl::Type_repllist* repllist, vx_core::Type_context* context);
  };

  // (func repl<-liblist-string)
  class Func_repl_from_liblist_string : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_repl::Func_repl_from_liblist_string* vx_new(Args*... args);
    template<class... Args> vx_repl::Func_repl_from_liblist_string* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_repl::Func_repl_from_liblist_string* vx_empty();
    virtual vx_repl::Func_repl_from_liblist_string* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_repl::Type_repl* vx_repl_from_liblist_string(vx_repl::Type_liblist* liblist, vx_core::Type_string* text);
  };

  // (func any-repl<-functype-args)
  vx_core::Type_any* f_any_repl_from_functype_args(vx_core::Type_any* type, vx_core::Type_anylist* args);

  // (func any<-liblist-string)
  vx_core::Type_any* f_any_from_liblist_string(vx_repl::Type_liblist* liblist, vx_core::Type_string* text, vx_core::Type_context* context);

  // (func any<-liblist-string-async)
  vx_core::Async<vx_core::Type_any*>* f_any_from_liblist_string_async(vx_repl::Type_liblist* liblist, vx_core::Type_string* text, vx_core::Type_context* context);

  // (func any<-repl)
  vx_core::Type_any* f_any_from_repl(vx_repl::Type_repl* repl, vx_core::Type_context* context);

  // (func any<-repl-async)
  vx_core::Async<vx_core::Type_any*>* f_any_from_repl_async(vx_repl::Type_repl* repl, vx_core::Type_context* context);

  // (func anylist<-repllist)
  vx_core::Type_anylist* f_anylist_from_repllist(vx_repl::Type_repllist* repllist, vx_core::Type_context* context);

  // (func repl<-liblist-string)
  vx_repl::Type_repl* f_repl_from_liblist_string(vx_repl::Type_liblist* liblist, vx_core::Type_string* text);

}
