#pragma once
#include <any>
#include <map>
#include <set>
#include <string>
#include "../vx/core.hpp"

namespace vx_sample {

  // forward declarations
  class Type_mytype;
  extern Type_mytype* e_mytype;
  extern Type_mytype* t_mytype;
  class Const_myconst;
  extern Const_myconst* c_myconst;
  class Func_main;
  extern Func_main* e_main;
  extern Func_main* t_main;
  class Func_myfunc;
  extern Func_myfunc* e_myfunc;
  extern Func_myfunc* t_myfunc;


  // (type mytype)
  class Type_mytype : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_sample::Type_mytype* vx_new(Args*... args);
    template<class... Args> vx_sample::Type_mytype* vx_copy(Args*... args);
    virtual vx_sample::Type_mytype* vx_empty();
    virtual vx_sample::Type_mytype* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // mynum()
    vx_core::Type_int* vx_p_mynum;
    virtual vx_core::Type_int* mynum();
    // mystr()
    vx_core::Type_string* vx_p_mystr;
    virtual vx_core::Type_string* mystr();
  };

  // (const myconst)
  class Const_myconst : public vx_core::Type_int {
  public:
    vx_core::Type_constdef* vx_constdef();
    static Const_myconst* vx_const_new();
  };

  // (func main)
  class Func_main : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_sample::Func_main* vx_new(Args*... args);
    template<class... Args> vx_sample::Func_main* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_sample::Func_main* vx_empty();
    virtual vx_sample::Func_main* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    void* vx_main();
  };

  // (func myfunc)
  class Func_myfunc : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_sample::Func_myfunc* vx_new(Args*... args);
    template<class... Args> vx_sample::Func_myfunc* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_sample::Func_myfunc* vx_empty();
    virtual vx_sample::Func_myfunc* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_int* vx_myfunc(vx_core::Type_int* myarg);
  };

  // (func main)
  void* f_main();

  // (func myfunc)
  vx_core::Type_int* f_myfunc(vx_core::Type_int* myarg);

}
