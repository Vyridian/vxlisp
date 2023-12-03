#ifndef VX_REPL_HPP
#define VX_REPL_HPP
#include <string>
#include <vector>
#include "../vx/core.hpp"
#include "../vx/type.hpp"
#include "../vx/data/textblock.hpp"

namespace vx_repl {

  // forward declarations
  class Abstract_liblist;
  typedef Abstract_liblist* Type_liblist;
  extern Type_liblist e_liblist;
  extern Type_liblist t_liblist;
  class Abstract_repl;
  typedef Abstract_repl* Type_repl;
  extern Type_repl e_repl;
  extern Type_repl t_repl;
  class Abstract_repllist;
  typedef Abstract_repllist* Type_repllist;
  extern Type_repllist e_repllist;
  extern Type_repllist t_repllist;
  class Class_delimvxlisp;
  typedef Class_delimvxlisp* Const_delimvxlisp;
  extern Const_delimvxlisp c_delimvxlisp;
  class Class_delimvxlispbracket;
  typedef Class_delimvxlispbracket* Const_delimvxlispbracket;
  extern Const_delimvxlispbracket c_delimvxlispbracket;
  class Class_delimvxlispparen;
  typedef Class_delimvxlispparen* Const_delimvxlispparen;
  extern Const_delimvxlispparen c_delimvxlispparen;
  class Abstract_any_repl_from_functype_args;
  typedef Abstract_any_repl_from_functype_args* Func_any_repl_from_functype_args;
  extern Func_any_repl_from_functype_args e_any_repl_from_functype_args;
  extern Func_any_repl_from_functype_args t_any_repl_from_functype_args;
  class Abstract_any_from_liblist_string;
  typedef Abstract_any_from_liblist_string* Func_any_from_liblist_string;
  extern Func_any_from_liblist_string e_any_from_liblist_string;
  extern Func_any_from_liblist_string t_any_from_liblist_string;
  class Abstract_any_from_repl;
  typedef Abstract_any_from_repl* Func_any_from_repl;
  extern Func_any_from_repl e_any_from_repl;
  extern Func_any_from_repl t_any_from_repl;
  class Abstract_any_from_script;
  typedef Abstract_any_from_script* Func_any_from_script;
  extern Func_any_from_script e_any_from_script;
  extern Func_any_from_script t_any_from_script;
  class Abstract_anylist_from_repllist;
  typedef Abstract_anylist_from_repllist* Func_anylist_from_repllist;
  extern Func_anylist_from_repllist e_anylist_from_repllist;
  extern Func_anylist_from_repllist t_anylist_from_repllist;
  class Abstract_macro;
  typedef Abstract_macro* Func_macro;
  extern Func_macro e_macro;
  extern Func_macro t_macro;
  class Abstract_repl_from_liblist_string;
  typedef Abstract_repl_from_liblist_string* Func_repl_from_liblist_string;
  extern Func_repl_from_liblist_string e_repl_from_liblist_string;
  extern Func_repl_from_liblist_string t_repl_from_liblist_string;
  class Abstract_repl_from_textblock;
  typedef Abstract_repl_from_textblock* Func_repl_from_textblock;
  extern Func_repl_from_textblock e_repl_from_textblock;
  extern Func_repl_from_textblock t_repl_from_textblock;
  class Abstract_textblock_repl_from_script;
  typedef Abstract_textblock_repl_from_script* Func_textblock_repl_from_script;
  extern Func_textblock_repl_from_script e_textblock_repl_from_script;
  extern Func_textblock_repl_from_script t_textblock_repl_from_script;// :headerfirst
// :header

  // vx_string_from_listarg(type, liststring, context)
  std::string vx_string_from_listarg(vx_core::Type_any type, std::vector<std::string> listarg, vx_core::Type_context context);


  // (func any-repl<-functype-args)
  vx_core::Type_any f_any_repl_from_functype_args(vx_core::Type_any type, vx_core::Type_anylist args);

  // (func any<-liblist-string)
  vx_core::Type_any f_any_from_liblist_string(vx_repl::Type_liblist liblist, vx_core::Type_string text, vx_core::Type_context context);

  // (func any<-repl)
  vx_core::Type_any f_any_from_repl(vx_repl::Type_repl repl, vx_core::Type_context context);

  // (func any<-script)
  vx_core::Type_any f_any_from_script(vx_core::Type_string script, vx_core::Type_context context);

  // (func anylist<-repllist)
  vx_core::Type_anylist f_anylist_from_repllist(vx_repl::Type_repllist repllist, vx_core::Type_context context);

  // (func repl<-liblist-string)
  vx_repl::Type_repl f_repl_from_liblist_string(vx_repl::Type_liblist liblist, vx_core::Type_string text);

  // (func repl<-textblock)
  vx_repl::Type_repl f_repl_from_textblock(vx_data_textblock::Type_textblock textblock);

  // (func textblock-repl<-script)
  vx_data_textblock::Type_textblock f_textblock_repl_from_script(vx_core::Type_string script);

  // (type liblist)
  class Abstract_liblist : public virtual vx_core::Abstract_list {
  public:
    Abstract_liblist() {};
    virtual ~Abstract_liblist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_core::Type_string> vx_p_list;
    // vx_liststring()
    virtual std::vector<vx_core::Type_string> vx_liststring() const = 0;
    // vx_get_string(index)
    virtual vx_core::Type_string vx_get_string(vx_core::Type_int index) const = 0;
  };
  class Class_liblist : public virtual Abstract_liblist {
  public:
    Class_liblist();
    virtual ~Class_liblist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
    virtual std::vector<vx_core::Type_string> vx_liststring() const override;
    virtual vx_core::Type_string vx_get_string(vx_core::Type_int index) const override;
  };

  // (type repl)
  class Abstract_repl : public virtual vx_core::Abstract_struct {
  public:
    Abstract_repl() {};
    virtual ~Abstract_repl() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // type()
    vx_core::Type_any vx_p_type = NULL;
    virtual vx_core::Type_any type() const = 0;
    // repllist()
    vx_repl::Type_repllist vx_p_repllist = NULL;
    virtual vx_repl::Type_repllist repllist() const = 0;
    // async()
    vx_core::Type_boolean vx_p_async = NULL;
    virtual vx_core::Type_boolean async() const = 0;
    // val()
    vx_core::Type_any vx_p_val = NULL;
    virtual vx_core::Type_any val() const = 0;
  };
  class Class_repl : public virtual Abstract_repl {
  public:
    Class_repl();
    virtual ~Class_repl() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_any type() const override;
    virtual vx_repl::Type_repllist repllist() const override;
    virtual vx_core::Type_boolean async() const override;
    virtual vx_core::Type_any val() const override;
  };

  // (type repllist)
  class Abstract_repllist : public virtual vx_core::Abstract_list {
  public:
    Abstract_repllist() {};
    virtual ~Abstract_repllist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_repl::Type_repl> vx_p_list;
    // vx_listrepl()
    virtual std::vector<vx_repl::Type_repl> vx_listrepl() const = 0;
    // vx_get_repl(index)
    virtual vx_repl::Type_repl vx_get_repl(vx_core::Type_int index) const = 0;
  };
  class Class_repllist : public virtual Abstract_repllist {
  public:
    Class_repllist();
    virtual ~Class_repllist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
    virtual std::vector<vx_repl::Type_repl> vx_listrepl() const override;
    virtual vx_repl::Type_repl vx_get_repl(vx_core::Type_int index) const override;
  };

  // (const delimvxlisp)
  class Class_delimvxlisp : public vx_data_textblock::Class_delim, public vx_core::vx_Abstract_const {
  public:
    static void vx_const_new(vx_repl::Const_delimvxlisp output);
    vx_core::Type_constdef vx_constdef() const;
  };

  // (const delimvxlispbracket)
  class Class_delimvxlispbracket : public vx_data_textblock::Class_delim, public vx_core::vx_Abstract_const {
  public:
    static void vx_const_new(vx_repl::Const_delimvxlispbracket output);
    vx_core::Type_constdef vx_constdef() const;
  };

  // (const delimvxlispparen)
  class Class_delimvxlispparen : public vx_data_textblock::Class_delim, public vx_core::vx_Abstract_const {
  public:
    static void vx_const_new(vx_repl::Const_delimvxlispparen output);
    vx_core::Type_constdef vx_constdef() const;
  };

  // (func any-repl<-functype-args)
  class Abstract_any_repl_from_functype_args : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_repl_from_functype_args() {};
    virtual ~Abstract_any_repl_from_functype_args() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_repl_from_functype_args : public virtual Abstract_any_repl_from_functype_args {
  public:
    Class_any_repl_from_functype_args();
    virtual ~Class_any_repl_from_functype_args() override;
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

  // (func any<-liblist-string)
  class Abstract_any_from_liblist_string : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_liblist_string() {};
    virtual ~Abstract_any_from_liblist_string() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_liblist_string : public virtual Abstract_any_from_liblist_string {
  public:
    Class_any_from_liblist_string();
    virtual ~Class_any_from_liblist_string() override;
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

  // (func any<-repl)
  class Abstract_any_from_repl : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_repl() {};
    virtual ~Abstract_any_from_repl() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_repl : public virtual Abstract_any_from_repl {
  public:
    Class_any_from_repl();
    virtual ~Class_any_from_repl() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func any<-script)
  class Abstract_any_from_script : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_script() {};
    virtual ~Abstract_any_from_script() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_script : public virtual Abstract_any_from_script {
  public:
    Class_any_from_script();
    virtual ~Class_any_from_script() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func anylist<-repllist)
  class Abstract_anylist_from_repllist : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_anylist_from_repllist() {};
    virtual ~Abstract_anylist_from_repllist() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_anylist_from_repllist : public virtual Abstract_anylist_from_repllist {
  public:
    Class_anylist_from_repllist();
    virtual ~Class_anylist_from_repllist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func macro)
  class Abstract_macro : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_macro() {};
    virtual ~Abstract_macro() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_macro : public virtual Abstract_macro {
  public:
    Class_macro();
    virtual ~Class_macro() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func repl<-liblist-string)
  class Abstract_repl_from_liblist_string : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_repl_from_liblist_string() {};
    virtual ~Abstract_repl_from_liblist_string() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_repl_from_liblist_string : public virtual Abstract_repl_from_liblist_string {
  public:
    Class_repl_from_liblist_string();
    virtual ~Class_repl_from_liblist_string() override;
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

  // (func repl<-textblock)
  class Abstract_repl_from_textblock : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_repl_from_textblock() {};
    virtual ~Abstract_repl_from_textblock() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_repl_from_textblock : public virtual Abstract_repl_from_textblock {
  public:
    Class_repl_from_textblock();
    virtual ~Class_repl_from_textblock() override;
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

  // (func textblock-repl<-script)
  class Abstract_textblock_repl_from_script : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_textblock_repl_from_script() {};
    virtual ~Abstract_textblock_repl_from_script() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_textblock_repl_from_script : public virtual Abstract_textblock_repl_from_script {
  public:
    Class_textblock_repl_from_script();
    virtual ~Class_textblock_repl_from_script() override;
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

  // (func macro)
  template <class T> T* f_macro(T* generic_any_1, vx_core::Type_anylist anylist, vx_core::Type_context context) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve(anylist);
    output = vx_core::f_let(
      generic_any_1,
      vx_core::t_any_from_func->vx_fn_new({anylist, generic_any_1, context}, [anylist, generic_any_1, context]() {
        vx_core::Type_stringlist textlist = vx_core::f_list_from_list(
          vx_core::t_stringlist,
          anylist,
          vx_core::t_any_from_any->vx_fn_new({}, [](vx_core::Type_any item) {
            vx_core::Type_any output_1 = 
              vx_core::f_string_from_any(item);
            return output_1;
          })
        );
        vx_core::vx_ref_plus(textlist);
        vx_core::Type_string script = vx_type::f_string_from_stringlist_join(textlist, vx_core::vx_new_string(""));
        vx_core::vx_ref_plus(script);
        vx_data_textblock::Type_textblock tb = vx_repl::f_textblock_repl_from_script(script);
        vx_core::vx_ref_plus(tb);
        vx_repl::Type_repl repl = vx_repl::f_repl_from_textblock(tb);
        vx_core::vx_ref_plus(repl);
        vx_core::Type_any output_1 = vx_core::f_any_from_any(
          generic_any_1,
          vx_repl::f_any_from_repl(repl, context)
        );
        vx_core::vx_release_one_except({textlist, script, tb, repl}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(anylist, output);
    return output;
  }

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
