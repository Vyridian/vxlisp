#ifndef VX_TRANSLATION_EN_HPP
#define VX_TRANSLATION_EN_HPP
#include "../../vx/core.hpp"
#include "../../vx/data/file.hpp"
#include "../../vx/translate.hpp"

namespace vx_translation_en {


  // forward declarations
  class Abstract_context_en;
  typedef Abstract_context_en* Func_context_en;
  extern Func_context_en e_context_en;
  extern Func_context_en t_context_en;
  class Abstract_context_test;
  typedef Abstract_context_test* Func_context_test;
  extern Func_context_test e_context_test;
  extern Func_context_test t_context_test;
  class Abstract_securitydata_test;
  typedef Abstract_securitydata_test* Func_securitydata_test;
  extern Func_securitydata_test e_securitydata_test;
  extern Func_securitydata_test t_securitydata_test;
  class Abstract_translation_en;
  typedef Abstract_translation_en* Func_translation_en;
  extern Func_translation_en e_translation_en;
  extern Func_translation_en t_translation_en;
  class Abstract_words;
  typedef Abstract_words* Func_words;
  extern Func_words e_words;
  extern Func_words t_words;
  // (func context-en)
  vx_core::Type_context f_context_en(vx_core::Type_anylist args);

  // (func context-test)
  vx_core::Type_context f_context_test(vx_core::Type_anylist args);

  // (func securitydata-test)
  vx_core::Type_security f_securitydata_test();

  // (func translation-en)
  vx_core::Type_translation f_translation_en();

  // (func words)
  vx_core::Type_stringmap f_words();

  // (func context-en)
  class Abstract_context_en : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_context_en() {};
    virtual ~Abstract_context_en() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_context_en : public virtual Abstract_context_en {
  public:
    Class_context_en();
    virtual ~Class_context_en() override;
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

  // (func context-test)
  class Abstract_context_test : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_context_test() {};
    virtual ~Abstract_context_test() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_context_test : public virtual Abstract_context_test {
  public:
    Class_context_test();
    virtual ~Class_context_test() override;
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

  // (func securitydata-test)
  class Abstract_securitydata_test : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_securitydata_test() {};
    virtual ~Abstract_securitydata_test() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_securitydata_test : public virtual Abstract_securitydata_test {
  public:
    Class_securitydata_test();
    virtual ~Class_securitydata_test() override;
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

  // (func translation-en)
  class Abstract_translation_en : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_translation_en() {};
    virtual ~Abstract_translation_en() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_translation_en : public virtual Abstract_translation_en {
  public:
    Class_translation_en();
    virtual ~Class_translation_en() override;
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

  // (func words)
  class Abstract_words : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_words() {};
    virtual ~Abstract_words() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_words : public virtual Abstract_words {
  public:
    Class_words();
    virtual ~Class_words() override;
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

  class vx_Class_package {
  public:
    vx_Class_package();
    void init();
  };
  inline vx_Class_package const vx_package;

}

#endif
