#ifndef vx_sample_hpp
#define vx_sample_hpp
#include <memory>
#include <set>
#include <string>
#include "../vx/core.hpp"

namespace vx_sample {

  // forward declarations
  class Class_mytype;
  typedef std::shared_ptr<Class_mytype> Type_mytype;
  extern Type_mytype e_mytype;
  extern Type_mytype t_mytype;
  class Class_myconst;
  typedef std::shared_ptr<Class_myconst> Const_myconst;
  extern Const_myconst c_myconst;
  class Class_main;
  typedef std::shared_ptr<Class_main> Func_main;
  extern Func_main e_main;
  extern Func_main t_main;
  class Class_myfunc;
  typedef std::shared_ptr<Class_myfunc> Func_myfunc;
  extern Func_myfunc e_myfunc;
  extern Func_myfunc t_myfunc;


  // (type mytype)
  class Class_mytype : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key);
    // mynum()
    vx_core::Type_int vx_p_mynum;
    virtual vx_core::Type_int mynum();
    // mystr()
    vx_core::Type_string vx_p_mystr;
    virtual vx_core::Type_string mystr();
  };

  // (const myconst)
  class Class_myconst : public vx_core::Class_int {
  public:
    vx_core::Type_constdef vx_constdef();
    static vx_sample::Const_myconst vx_const_new();
    int vx_int();
  };

  // (func main)
  class Class_main : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    void vx_f_main();
  };

  // (func myfunc)
  class Class_myfunc : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_int vx_f_myfunc(vx_core::Type_int myarg);
  };

  // (func main)
  void f_main();

  // (func myfunc)
  vx_core::Type_int f_myfunc(vx_core::Type_int myarg);

}
#endif
