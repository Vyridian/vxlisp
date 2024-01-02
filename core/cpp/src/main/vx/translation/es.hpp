#ifndef VX_TRANSLATION_ES_HPP
#define VX_TRANSLATION_ES_HPP
#include "../../vx/core.hpp"
#include "../../vx/translate.hpp"

namespace vx_translation_es {


  // forward declarations
  class Abstract_translation_es;
  typedef Abstract_translation_es* Func_translation_es;
  extern Func_translation_es e_translation_es;
  extern Func_translation_es t_translation_es;
  class Abstract_words;
  typedef Abstract_words* Func_words;
  extern Func_words e_words;
  extern Func_words t_words;
  // (func translation-es)
  vx_core::Type_translation f_translation_es();

  // (func words)
  vx_core::Type_stringmap f_words();

  // (func translation-es)
  class Abstract_translation_es : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_translation_es() {};
    virtual ~Abstract_translation_es() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_translation_es : public virtual Abstract_translation_es {
  public:
    Class_translation_es();
    virtual ~Class_translation_es() override;
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
