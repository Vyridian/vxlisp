#ifndef VX_SAMPLE_HPP
#define VX_SAMPLE_HPP
#include "../vx/core.hpp"

namespace vx_sample {

  // forward declarations
  class Abstract_mytype;
  typedef Abstract_mytype* Type_mytype;
  extern Type_mytype e_mytype;
  extern Type_mytype t_mytype;
  class Class_myconst;
  typedef Class_myconst* Const_myconst;
  extern Const_myconst c_myconst;
  class Abstract_main;
  typedef Abstract_main* Func_main;
  extern Func_main e_main;
  extern Func_main t_main;
  class Abstract_myfunc;
  typedef Abstract_myfunc* Func_myfunc;
  extern Func_myfunc e_myfunc;
  extern Func_myfunc t_myfunc;
  // (func main)
  void f_main();

  // (func myfunc)
  vx_core::Type_int f_myfunc(vx_core::Type_int myarg);

  // (type mytype)
  class Abstract_mytype : public virtual vx_core::Abstract_struct {
  public:
    Abstract_mytype() {};
    virtual ~Abstract_mytype() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // mynum()
    vx_core::Type_int vx_p_mynum = NULL;
    virtual vx_core::Type_int mynum() const = 0;
    // mystr()
    vx_core::Type_string vx_p_mystr = NULL;
    virtual vx_core::Type_string mystr() const = 0;
  };
  class Class_mytype : public virtual Abstract_mytype {
  public:
    Class_mytype();
    virtual ~Class_mytype() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_int mynum() const override;
    virtual vx_core::Type_string mystr() const override;
  };

  // (const myconst)
  class Class_myconst : public vx_core::Class_int, public vx_core::vx_Abstract_const {
  public:
    static void vx_const_new(vx_sample::Const_myconst output);
    vx_core::Type_constdef vx_constdef() const;
    long vx_int() const override;
  };

  // (func main)
  class Abstract_main : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_main() {};
    virtual ~Abstract_main() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_main : public virtual Abstract_main {
  public:
    Class_main();
    virtual ~Class_main() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func myfunc)
  class Abstract_myfunc : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_myfunc() {};
    virtual ~Abstract_myfunc() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_myfunc : public virtual Abstract_myfunc {
  public:
    Class_myfunc();
    virtual ~Class_myfunc() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  class vx_Class_package : vx_core::vx_Abstract_package {
  public:
    vx_Class_package();
    void init();
    vx_core::vx_Type_mapany maptype();
    vx_core::vx_Type_mapany mapconst();
    vx_core::vx_Type_mapfunc mapfunc();
  };
  inline vx_Class_package const vx_package;

}
#endif
