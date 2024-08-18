#ifndef VX_REPL_HPP
#define VX_REPL_HPP
#include <string>
#include <vector>
#include "../vx/core.hpp"
#include "../vx/collection.hpp"
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
  class Abstract_replarglist;
  typedef Abstract_replarglist* Type_replarglist;
  extern Type_replarglist e_replarglist;
  extern Type_replarglist t_replarglist;
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
  class Abstract_any_from_macro;
  typedef Abstract_any_from_macro* Func_any_from_macro;
  extern Func_any_from_macro e_any_from_macro;
  extern Func_any_from_macro t_any_from_macro;
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
  class Abstract_argmap_from_textblock_argmap;
  typedef Abstract_argmap_from_textblock_argmap* Func_argmap_from_textblock_argmap;
  extern Func_argmap_from_textblock_argmap e_argmap_from_textblock_argmap;
  extern Func_argmap_from_textblock_argmap t_argmap_from_textblock_argmap;
  class Abstract_const_from_string;
  typedef Abstract_const_from_string* Func_const_from_string;
  extern Func_const_from_string e_const_from_string;
  extern Func_const_from_string t_const_from_string;
  class Abstract_repl_bracket_from_textblock_argmap;
  typedef Abstract_repl_bracket_from_textblock_argmap* Func_repl_bracket_from_textblock_argmap;
  extern Func_repl_bracket_from_textblock_argmap e_repl_bracket_from_textblock_argmap;
  extern Func_repl_bracket_from_textblock_argmap t_repl_bracket_from_textblock_argmap;
  class Abstract_repl_empty_from_textblock_argmap;
  typedef Abstract_repl_empty_from_textblock_argmap* Func_repl_empty_from_textblock_argmap;
  extern Func_repl_empty_from_textblock_argmap e_repl_empty_from_textblock_argmap;
  extern Func_repl_empty_from_textblock_argmap t_repl_empty_from_textblock_argmap;
  class Abstract_repl_paren_from_textblock_argmap;
  typedef Abstract_repl_paren_from_textblock_argmap* Func_repl_paren_from_textblock_argmap;
  extern Func_repl_paren_from_textblock_argmap e_repl_paren_from_textblock_argmap;
  extern Func_repl_paren_from_textblock_argmap t_repl_paren_from_textblock_argmap;
  class Abstract_repl_from_liblist_string;
  typedef Abstract_repl_from_liblist_string* Func_repl_from_liblist_string;
  extern Func_repl_from_liblist_string e_repl_from_liblist_string;
  extern Func_repl_from_liblist_string t_repl_from_liblist_string;
  class Abstract_repl_from_macro;
  typedef Abstract_repl_from_macro* Func_repl_from_macro;
  extern Func_repl_from_macro e_repl_from_macro;
  extern Func_repl_from_macro t_repl_from_macro;
  class Abstract_repl_from_script;
  typedef Abstract_repl_from_script* Func_repl_from_script;
  extern Func_repl_from_script e_repl_from_script;
  extern Func_repl_from_script t_repl_from_script;
  class Abstract_repl_from_string_argmap;
  typedef Abstract_repl_from_string_argmap* Func_repl_from_string_argmap;
  extern Func_repl_from_string_argmap e_repl_from_string_argmap;
  extern Func_repl_from_string_argmap t_repl_from_string_argmap;
  class Abstract_repl_from_textblock;
  typedef Abstract_repl_from_textblock* Func_repl_from_textblock;
  extern Func_repl_from_textblock e_repl_from_textblock;
  extern Func_repl_from_textblock t_repl_from_textblock;
  class Abstract_repl_from_textblock_argmap;
  typedef Abstract_repl_from_textblock_argmap* Func_repl_from_textblock_argmap;
  extern Func_repl_from_textblock_argmap e_repl_from_textblock_argmap;
  extern Func_repl_from_textblock_argmap t_repl_from_textblock_argmap;
  class Abstract_replarglist_from_replarglist_textblock_argmap;
  typedef Abstract_replarglist_from_replarglist_textblock_argmap* Func_replarglist_from_replarglist_textblock_argmap;
  extern Func_replarglist_from_replarglist_textblock_argmap e_replarglist_from_replarglist_textblock_argmap;
  extern Func_replarglist_from_replarglist_textblock_argmap t_replarglist_from_replarglist_textblock_argmap;
  class Abstract_repllist_from_textblocklist_argmap;
  typedef Abstract_repllist_from_textblocklist_argmap* Func_repllist_from_textblocklist_argmap;
  extern Func_repllist_from_textblocklist_argmap e_repllist_from_textblocklist_argmap;
  extern Func_repllist_from_textblocklist_argmap t_repllist_from_textblocklist_argmap;
  class Abstract_textblock_from_script;
  typedef Abstract_textblock_from_script* Func_textblock_from_script;
  extern Func_textblock_from_script e_textblock_from_script;
  extern Func_textblock_from_script t_textblock_from_script;
  class Abstract_typefunc_from_string;
  typedef Abstract_typefunc_from_string* Func_typefunc_from_string;
  extern Func_typefunc_from_string e_typefunc_from_string;
  extern Func_typefunc_from_string t_typefunc_from_string;// :headerfirst
// :header

  // vx_string_from_listarg(context, type, liststring)
  std::string vx_string_from_listarg(vx_core::Type_context context, vx_core::Type_any type, std::vector<std::string> listarg);


  // (func any-repl<-functype-args)
  vx_core::Type_any f_any_repl_from_functype_args(vx_core::Type_any type, vx_core::Type_anylist args);

  // (func any<-liblist-string)
  vx_core::Type_any f_any_from_liblist_string(vx_core::Type_context context, vx_repl::Type_liblist liblist, vx_core::Type_string text);

  // (func any<-repl)
  vx_core::Type_any f_any_from_repl(vx_core::Type_context context, vx_repl::Type_repl repl);

  // (func any<-script)
  vx_core::Type_any f_any_from_script(vx_core::Type_context context, vx_core::Type_string script);

  // (func anylist<-repllist)
  vx_core::Type_anylist f_anylist_from_repllist(vx_core::Type_context context, vx_repl::Type_repllist repllist);

  // (func argmap<-textblock-argmap)
  vx_core::Type_argmap f_argmap_from_textblock_argmap(vx_data_textblock::Type_textblock textblock, vx_core::Type_argmap argmap);

  // (func const<-string)
  vx_core::Type_any f_const_from_string(vx_core::Type_string text);

  // (func repl-bracket<-textblock-argmap)
  vx_repl::Type_repl f_repl_bracket_from_textblock_argmap(vx_data_textblock::Type_textblock textblock, vx_core::Type_argmap argmap);

  // (func repl-empty<-textblock-argmap)
  vx_repl::Type_repl f_repl_empty_from_textblock_argmap(vx_data_textblock::Type_textblock textblock, vx_core::Type_argmap argmap);

  // (func repl-paren<-textblock-argmap)
  vx_repl::Type_repl f_repl_paren_from_textblock_argmap(vx_data_textblock::Type_textblock textblock, vx_core::Type_argmap argmap);

  // (func repl<-liblist-string)
  vx_repl::Type_repl f_repl_from_liblist_string(vx_repl::Type_liblist liblist, vx_core::Type_string text);

  // (func repl<-macro)
  vx_repl::Type_repl f_repl_from_macro(vx_core::Type_context context, vx_core::Type_anylist anylist);

  // (func repl<-script)
  vx_repl::Type_repl f_repl_from_script(vx_core::Type_string script);

  // (func repl<-string-argmap)
  vx_repl::Type_repl f_repl_from_string_argmap(vx_core::Type_string text, vx_core::Type_argmap argmap);

  // (func repl<-textblock)
  vx_repl::Type_repl f_repl_from_textblock(vx_data_textblock::Type_textblock textblock);

  // (func repl<-textblock-argmap)
  vx_repl::Type_repl f_repl_from_textblock_argmap(vx_data_textblock::Type_textblock textblock, vx_core::Type_argmap argmap);

  // (func replarglist<-replarglist-textblock-argmap)
  vx_repl::Type_replarglist f_replarglist_from_replarglist_textblock_argmap(vx_repl::Type_replarglist replargs, vx_data_textblock::Type_textblock tb, vx_core::Type_argmap argmap);

  // (func repllist<-textblocklist-argmap)
  vx_repl::Type_repllist f_repllist_from_textblocklist_argmap(vx_data_textblock::Type_textblocklist textblocklist, vx_core::Type_argmap argmap);

  // (func textblock<-script)
  vx_data_textblock::Type_textblock f_textblock_from_script(vx_core::Type_string script);

  // (func typefunc<-string)
  vx_core::Type_any f_typefunc_from_string(vx_core::Type_string text);

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
    virtual vx_core::Type_constdef vx_constdef() const override;
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
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
    // type()
    vx_core::Type_any vx_p_type = NULL;
    virtual vx_core::Type_any type() const = 0;
    // repllist()
    vx_repl::Type_repllist vx_p_repllist = NULL;
    virtual vx_repl::Type_repllist repllist() const = 0;
    // async()
    vx_core::Type_boolean vx_p_async = NULL;
    virtual vx_core::Type_boolean async() const = 0;
    // value()
    vx_core::Type_any vx_p_value = NULL;
    virtual vx_core::Type_any value() const = 0;
    // doc()
    vx_core::Type_string vx_p_doc = NULL;
    virtual vx_core::Type_string doc() const = 0;
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
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string name() const override;
    virtual vx_core::Type_any type() const override;
    virtual vx_repl::Type_repllist repllist() const override;
    virtual vx_core::Type_boolean async() const override;
    virtual vx_core::Type_any value() const override;
    virtual vx_core::Type_string doc() const override;
  };

  // (type replarglist)
  class Abstract_replarglist : public virtual vx_core::Abstract_struct {
  public:
    Abstract_replarglist() {};
    virtual ~Abstract_replarglist() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // key()
    vx_core::Type_string vx_p_key = NULL;
    virtual vx_core::Type_string key() const = 0;
    // current()
    vx_repl::Type_repl vx_p_current = NULL;
    virtual vx_repl::Type_repl current() const = 0;
    // repllist()
    vx_repl::Type_repllist vx_p_repllist = NULL;
    virtual vx_repl::Type_repllist repllist() const = 0;
  };
  class Class_replarglist : public virtual Abstract_replarglist {
  public:
    Class_replarglist();
    virtual ~Class_replarglist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string key() const override;
    virtual vx_repl::Type_repl current() const override;
    virtual vx_repl::Type_repllist repllist() const override;
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
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
    virtual std::vector<vx_repl::Type_repl> vx_listrepl() const override;
    virtual vx_repl::Type_repl vx_get_repl(vx_core::Type_int index) const override;
  };

  // (const delimvxlisp)
  class Class_delimvxlisp : public vx_data_textblock::Class_delim {
  public:
    static void vx_const_new(vx_repl::Const_delimvxlisp output);
  };

  // (const delimvxlispbracket)
  class Class_delimvxlispbracket : public vx_data_textblock::Class_delim {
  public:
    static void vx_const_new(vx_repl::Const_delimvxlispbracket output);
  };

  // (const delimvxlispparen)
  class Class_delimvxlispparen : public vx_data_textblock::Class_delim {
  public:
    static void vx_const_new(vx_repl::Const_delimvxlispparen output);
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
    virtual vx_core::Type_constdef vx_constdef() const override;
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
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func any<-macro)
  class Abstract_any_from_macro : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_macro() {};
    virtual ~Abstract_any_from_macro() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_macro : public virtual Abstract_any_from_macro {
  public:
    Class_any_from_macro();
    virtual ~Class_any_from_macro() override;
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

  // (func any<-repl)
  class Abstract_any_from_repl : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_repl() {};
    virtual ~Abstract_any_from_repl() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
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
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func any<-script)
  class Abstract_any_from_script : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_script() {};
    virtual ~Abstract_any_from_script() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
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
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func anylist<-repllist)
  class Abstract_anylist_from_repllist : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_anylist_from_repllist() {};
    virtual ~Abstract_anylist_from_repllist() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
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
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func argmap<-textblock-argmap)
  class Abstract_argmap_from_textblock_argmap : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_argmap_from_textblock_argmap() {};
    virtual ~Abstract_argmap_from_textblock_argmap() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_argmap_from_textblock_argmap : public virtual Abstract_argmap_from_textblock_argmap {
  public:
    Class_argmap_from_textblock_argmap();
    virtual ~Class_argmap_from_textblock_argmap() override;
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

  // (func const<-string)
  class Abstract_const_from_string : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_const_from_string() {};
    virtual ~Abstract_const_from_string() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_const_from_string : public virtual Abstract_const_from_string {
  public:
    Class_const_from_string();
    virtual ~Class_const_from_string() override;
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

  // (func repl-bracket<-textblock-argmap)
  class Abstract_repl_bracket_from_textblock_argmap : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_repl_bracket_from_textblock_argmap() {};
    virtual ~Abstract_repl_bracket_from_textblock_argmap() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_repl_bracket_from_textblock_argmap : public virtual Abstract_repl_bracket_from_textblock_argmap {
  public:
    Class_repl_bracket_from_textblock_argmap();
    virtual ~Class_repl_bracket_from_textblock_argmap() override;
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

  // (func repl-empty<-textblock-argmap)
  class Abstract_repl_empty_from_textblock_argmap : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_repl_empty_from_textblock_argmap() {};
    virtual ~Abstract_repl_empty_from_textblock_argmap() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_repl_empty_from_textblock_argmap : public virtual Abstract_repl_empty_from_textblock_argmap {
  public:
    Class_repl_empty_from_textblock_argmap();
    virtual ~Class_repl_empty_from_textblock_argmap() override;
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

  // (func repl-paren<-textblock-argmap)
  class Abstract_repl_paren_from_textblock_argmap : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_repl_paren_from_textblock_argmap() {};
    virtual ~Abstract_repl_paren_from_textblock_argmap() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_repl_paren_from_textblock_argmap : public virtual Abstract_repl_paren_from_textblock_argmap {
  public:
    Class_repl_paren_from_textblock_argmap();
    virtual ~Class_repl_paren_from_textblock_argmap() override;
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
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func repl<-macro)
  class Abstract_repl_from_macro : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_repl_from_macro() {};
    virtual ~Abstract_repl_from_macro() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_repl_from_macro : public virtual Abstract_repl_from_macro {
  public:
    Class_repl_from_macro();
    virtual ~Class_repl_from_macro() override;
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

  // (func repl<-script)
  class Abstract_repl_from_script : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_repl_from_script() {};
    virtual ~Abstract_repl_from_script() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_repl_from_script : public virtual Abstract_repl_from_script {
  public:
    Class_repl_from_script();
    virtual ~Class_repl_from_script() override;
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

  // (func repl<-string-argmap)
  class Abstract_repl_from_string_argmap : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_repl_from_string_argmap() {};
    virtual ~Abstract_repl_from_string_argmap() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_repl_from_string_argmap : public virtual Abstract_repl_from_string_argmap {
  public:
    Class_repl_from_string_argmap();
    virtual ~Class_repl_from_string_argmap() override;
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
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func repl<-textblock-argmap)
  class Abstract_repl_from_textblock_argmap : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_repl_from_textblock_argmap() {};
    virtual ~Abstract_repl_from_textblock_argmap() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_repl_from_textblock_argmap : public virtual Abstract_repl_from_textblock_argmap {
  public:
    Class_repl_from_textblock_argmap();
    virtual ~Class_repl_from_textblock_argmap() override;
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

  // (func replarglist<-replarglist-textblock-argmap)
  class Abstract_replarglist_from_replarglist_textblock_argmap : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_replarglist_from_replarglist_textblock_argmap() {};
    virtual ~Abstract_replarglist_from_replarglist_textblock_argmap() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_replarglist_from_replarglist_textblock_argmap : public virtual Abstract_replarglist_from_replarglist_textblock_argmap {
  public:
    Class_replarglist_from_replarglist_textblock_argmap();
    virtual ~Class_replarglist_from_replarglist_textblock_argmap() override;
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

  // (func repllist<-textblocklist-argmap)
  class Abstract_repllist_from_textblocklist_argmap : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_repllist_from_textblocklist_argmap() {};
    virtual ~Abstract_repllist_from_textblocklist_argmap() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_repllist_from_textblocklist_argmap : public virtual Abstract_repllist_from_textblocklist_argmap {
  public:
    Class_repllist_from_textblocklist_argmap();
    virtual ~Class_repllist_from_textblocklist_argmap() override;
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

  // (func textblock<-script)
  class Abstract_textblock_from_script : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_textblock_from_script() {};
    virtual ~Abstract_textblock_from_script() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_textblock_from_script : public virtual Abstract_textblock_from_script {
  public:
    Class_textblock_from_script();
    virtual ~Class_textblock_from_script() override;
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

  // (func typefunc<-string)
  class Abstract_typefunc_from_string : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_typefunc_from_string() {};
    virtual ~Abstract_typefunc_from_string() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_typefunc_from_string : public virtual Abstract_typefunc_from_string {
  public:
    Class_typefunc_from_string();
    virtual ~Class_typefunc_from_string() override;
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

  // (func any<-macro)
  template <class T> T* f_any_from_macro(T* generic_any_1, vx_core::Type_context context, vx_core::Type_anylist anylist) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve(anylist);
    output = vx_core::f_let(
      generic_any_1,
      vx_core::t_any_from_func->vx_fn_new({context, anylist, generic_any_1}, [context, anylist, generic_any_1]() {
        vx_repl::Type_repl repl = vx_repl::f_repl_from_macro(context, anylist);
        vx_core::vx_ref_plus(repl);
        vx_core::Type_any value = vx_repl::f_any_from_repl(context, repl);
        vx_core::vx_ref_plus(value);
        vx_core::Type_any output_1 = vx_core::f_any_from_any(generic_any_1, value);
        vx_core::vx_release_one_except({repl, value}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(anylist, output);
    return output;
  }

  class vx_Class_package {
  public:
    vx_Class_package();
    void init();
  };
  inline vx_Class_package const vx_package;

}

#endif
