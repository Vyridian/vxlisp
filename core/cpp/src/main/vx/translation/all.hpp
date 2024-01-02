#ifndef VX_TRANSLATION_ALL_HPP
#define VX_TRANSLATION_ALL_HPP
#include "../../vx/core.hpp"
#include "../../vx/translate.hpp"
#include "../../vx/translation/en.hpp"
#include "../../vx/translation/es.hpp"

namespace vx_translation_all {


  // forward declarations
  class Abstract_context_all;
  typedef Abstract_context_all* Func_context_all;
  extern Func_context_all e_context_all;
  extern Func_context_all t_context_all;
  class Abstract_translationmap_all;
  typedef Abstract_translationmap_all* Func_translationmap_all;
  extern Func_translationmap_all e_translationmap_all;
  extern Func_translationmap_all t_translationmap_all;
  // (func context-all)
  vx_core::Type_context f_context_all(vx_core::Type_anylist args);

  // (func translationmap-all)
  vx_core::Type_translationmap f_translationmap_all();

  // (func context-all)
  class Abstract_context_all : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_context_all() {};
    virtual ~Abstract_context_all() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_context_all : public virtual Abstract_context_all {
  public:
    Class_context_all();
    virtual ~Class_context_all() override;
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

  // (func translationmap-all)
  class Abstract_translationmap_all : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_translationmap_all() {};
    virtual ~Abstract_translationmap_all() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_translationmap_all : public virtual Abstract_translationmap_all {
  public:
    Class_translationmap_all();
    virtual ~Class_translationmap_all() override;
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
