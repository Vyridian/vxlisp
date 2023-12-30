#ifndef VX_TRANSLATE_HPP
#define VX_TRANSLATE_HPP
#include "../vx/core.hpp"
#include "../vx/data/csv.hpp"
#include "../vx/data/file.hpp"

namespace vx_translate {

  // forward declarations
  class Abstract_session_from_session_name;
  typedef Abstract_session_from_session_name* Func_session_from_session_name;
  extern Func_session_from_session_name e_session_from_session_name;
  extern Func_session_from_session_name t_session_from_session_name;
  class Abstract_session_from_session_translation;
  typedef Abstract_session_from_session_translation* Func_session_from_session_translation;
  extern Func_session_from_session_translation e_session_from_session_translation;
  extern Func_session_from_session_translation t_session_from_session_translation;
  class Abstract_session_from_session_translationmap_name;
  typedef Abstract_session_from_session_translationmap_name* Func_session_from_session_translationmap_name;
  extern Func_session_from_session_translationmap_name e_session_from_session_translationmap_name;
  extern Func_session_from_session_translationmap_name t_session_from_session_translationmap_name;
  class Abstract_translate;
  typedef Abstract_translate* Func_translate;
  extern Func_translate e_translate;
  extern Func_translate t_translate;
  class Abstract_translate_from_translation_string;
  typedef Abstract_translate_from_translation_string* Func_translate_from_translation_string;
  extern Func_translate_from_translation_string e_translate_from_translation_string;
  extern Func_translate_from_translation_string t_translate_from_translation_string;
  class Abstract_translate_from_translationmap_name_string;
  typedef Abstract_translate_from_translationmap_name_string* Func_translate_from_translationmap_name_string;
  extern Func_translate_from_translationmap_name_string e_translate_from_translationmap_name_string;
  extern Func_translate_from_translationmap_name_string t_translate_from_translationmap_name_string;
  class Abstract_translation_load_session;
  typedef Abstract_translation_load_session* Func_translation_load_session;
  extern Func_translation_load_session e_translation_load_session;
  extern Func_translation_load_session t_translation_load_session;
  class Abstract_translation_from_context;
  typedef Abstract_translation_from_context* Func_translation_from_context;
  extern Func_translation_from_context e_translation_from_context;
  extern Func_translation_from_context t_translation_from_context;
  class Abstract_translation_from_session_name;
  typedef Abstract_translation_from_session_name* Func_translation_from_session_name;
  extern Func_translation_from_session_name e_translation_from_session_name;
  extern Func_translation_from_session_name t_translation_from_session_name;
  class Abstract_translationmap_from_translations;
  typedef Abstract_translationmap_from_translations* Func_translationmap_from_translations;
  extern Func_translationmap_from_translations e_translationmap_from_translations;
  extern Func_translationmap_from_translations t_translationmap_from_translations;
  // (func session<-session-name)
  vx_core::Type_session f_session_from_session_name(vx_core::Type_session session, vx_core::Type_string name);

  // (func session<-session-translation)
  vx_core::Type_session f_session_from_session_translation(vx_core::Type_session session, vx_core::Type_translation translation);

  // (func session<-session-translationmap-name)
  vx_core::Type_session f_session_from_session_translationmap_name(vx_core::Type_session session, vx_core::Type_translationmap translationmap, vx_core::Type_string name);

  // (func translate)
  vx_core::Type_string f_translate(vx_core::Type_context context, vx_core::Type_string text);

  // (func translate<-translation-string)
  vx_core::Type_string f_translate_from_translation_string(vx_core::Type_translation translation, vx_core::Type_string text);

  // (func translate<-translationmap-name-string)
  vx_core::Type_string f_translate_from_translationmap_name_string(vx_core::Type_translationmap translationmap, vx_core::Type_string name, vx_core::Type_string text);

  // (func translation-load-session)
  vx_core::Type_translation f_translation_load_session(vx_core::Type_context context, vx_core::Type_translation translation);

  // (func translation<-context)
  vx_core::Type_translation f_translation_from_context(vx_core::Type_context context);

  // (func translation<-session-name)
  vx_core::Type_translation f_translation_from_session_name(vx_core::Type_session session, vx_core::Type_string name);

  // (func translationmap<-translations)
  vx_core::Type_translationmap f_translationmap_from_translations(vx_core::Type_translationlist translations);

  // (func session<-session-name)
  class Abstract_session_from_session_name : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_session_from_session_name() {};
    virtual ~Abstract_session_from_session_name() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_session_from_session_name : public virtual Abstract_session_from_session_name {
  public:
    Class_session_from_session_name();
    virtual ~Class_session_from_session_name() override;
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

  // (func session<-session-translation)
  class Abstract_session_from_session_translation : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_session_from_session_translation() {};
    virtual ~Abstract_session_from_session_translation() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_session_from_session_translation : public virtual Abstract_session_from_session_translation {
  public:
    Class_session_from_session_translation();
    virtual ~Class_session_from_session_translation() override;
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

  // (func session<-session-translationmap-name)
  class Abstract_session_from_session_translationmap_name : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_session_from_session_translationmap_name() {};
    virtual ~Abstract_session_from_session_translationmap_name() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_session_from_session_translationmap_name : public virtual Abstract_session_from_session_translationmap_name {
  public:
    Class_session_from_session_translationmap_name();
    virtual ~Class_session_from_session_translationmap_name() override;
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

  // (func translate)
  class Abstract_translate : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_translate() {};
    virtual ~Abstract_translate() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_translate : public virtual Abstract_translate {
  public:
    Class_translate();
    virtual ~Class_translate() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func translate<-translation-string)
  class Abstract_translate_from_translation_string : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_translate_from_translation_string() {};
    virtual ~Abstract_translate_from_translation_string() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_translate_from_translation_string : public virtual Abstract_translate_from_translation_string {
  public:
    Class_translate_from_translation_string();
    virtual ~Class_translate_from_translation_string() override;
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

  // (func translate<-translationmap-name-string)
  class Abstract_translate_from_translationmap_name_string : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_translate_from_translationmap_name_string() {};
    virtual ~Abstract_translate_from_translationmap_name_string() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_translate_from_translationmap_name_string : public virtual Abstract_translate_from_translationmap_name_string {
  public:
    Class_translate_from_translationmap_name_string();
    virtual ~Class_translate_from_translationmap_name_string() override;
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

  // (func translation-load-session)
  class Abstract_translation_load_session : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_translation_load_session() {};
    virtual ~Abstract_translation_load_session() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_translation_load_session : public virtual Abstract_translation_load_session {
  public:
    Class_translation_load_session();
    virtual ~Class_translation_load_session() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func translation<-context)
  class Abstract_translation_from_context : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_translation_from_context() {};
    virtual ~Abstract_translation_from_context() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_translation_from_context : public virtual Abstract_translation_from_context {
  public:
    Class_translation_from_context();
    virtual ~Class_translation_from_context() override;
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

  // (func translation<-session-name)
  class Abstract_translation_from_session_name : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_translation_from_session_name() {};
    virtual ~Abstract_translation_from_session_name() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_translation_from_session_name : public virtual Abstract_translation_from_session_name {
  public:
    Class_translation_from_session_name();
    virtual ~Class_translation_from_session_name() override;
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

  // (func translationmap<-translations)
  class Abstract_translationmap_from_translations : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_translationmap_from_translations() {};
    virtual ~Abstract_translationmap_from_translations() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_translationmap_from_translations : public virtual Abstract_translationmap_from_translations {
  public:
    Class_translationmap_from_translations();
    virtual ~Class_translationmap_from_translations() override;
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

  class vx_Class_package {
  public:
    vx_Class_package();
    void init();
  };
  inline vx_Class_package const vx_package;

}
#endif
