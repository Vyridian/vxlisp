#ifndef VX_TYPE_HPP
#define VX_TYPE_HPP
#include <string>
#include "../vx/core.hpp"

namespace vx_type {


  // forward declarations
  class Abstract_allowtypenames_from_type;
  typedef Abstract_allowtypenames_from_type* Func_allowtypenames_from_type;
  extern Func_allowtypenames_from_type e_allowtypenames_from_type;
  extern Func_allowtypenames_from_type t_allowtypenames_from_type;
  class Abstract_allowtypes_from_type;
  typedef Abstract_allowtypes_from_type* Func_allowtypes_from_type;
  extern Func_allowtypes_from_type e_allowtypes_from_type;
  extern Func_allowtypes_from_type t_allowtypes_from_type;
  class Abstract_any_from_int;
  typedef Abstract_any_from_int* Func_any_from_int;
  extern Func_any_from_int e_any_from_int;
  extern Func_any_from_int t_any_from_int;
  class Abstract_boolean_from_string_ends;
  typedef Abstract_boolean_from_string_ends* Func_boolean_from_string_ends;
  extern Func_boolean_from_string_ends e_boolean_from_string_ends;
  extern Func_boolean_from_string_ends t_boolean_from_string_ends;
  class Abstract_boolean_from_string_starts;
  typedef Abstract_boolean_from_string_starts* Func_boolean_from_string_starts;
  extern Func_boolean_from_string_starts e_boolean_from_string_starts;
  extern Func_boolean_from_string_starts t_boolean_from_string_starts;
  class Abstract_int_from_string_find;
  typedef Abstract_int_from_string_find* Func_int_from_string_find;
  extern Func_int_from_string_find e_int_from_string_find;
  extern Func_int_from_string_find t_int_from_string_find;
  class Abstract_int_from_string_findkeyword;
  typedef Abstract_int_from_string_findkeyword* Func_int_from_string_findkeyword;
  extern Func_int_from_string_findkeyword e_int_from_string_findkeyword;
  extern Func_int_from_string_findkeyword t_int_from_string_findkeyword;
  class Abstract_int_from_string_findlast;
  typedef Abstract_int_from_string_findlast* Func_int_from_string_findlast;
  extern Func_int_from_string_findlast e_int_from_string_findlast;
  extern Func_int_from_string_findlast t_int_from_string_findlast;
  class Abstract_is_boolean;
  typedef Abstract_is_boolean* Func_is_boolean;
  extern Func_is_boolean e_is_boolean;
  extern Func_is_boolean t_is_boolean;
  class Abstract_is_decimal;
  typedef Abstract_is_decimal* Func_is_decimal;
  extern Func_is_decimal e_is_decimal;
  extern Func_is_decimal t_is_decimal;
  class Abstract_is_none;
  typedef Abstract_is_none* Func_is_none;
  extern Func_is_none e_is_none;
  extern Func_is_none t_is_none;
  class Abstract_is_string;
  typedef Abstract_is_string* Func_is_string;
  extern Func_is_string e_is_string;
  extern Func_is_string t_is_string;
  class Abstract_is_type;
  typedef Abstract_is_type* Func_is_type;
  extern Func_is_type e_is_type;
  extern Func_is_type t_is_type;
  class Abstract_is_type_from_any_typelist;
  typedef Abstract_is_type_from_any_typelist* Func_is_type_from_any_typelist;
  extern Func_is_type_from_any_typelist e_is_type_from_any_typelist;
  extern Func_is_type_from_any_typelist t_is_type_from_any_typelist;
  class Abstract_string_lowercase;
  typedef Abstract_string_lowercase* Func_string_lowercase;
  extern Func_string_lowercase e_string_lowercase;
  extern Func_string_lowercase t_string_lowercase;
  class Abstract_string_outdent;
  typedef Abstract_string_outdent* Func_string_outdent;
  extern Func_string_outdent e_string_outdent;
  extern Func_string_outdent t_string_outdent;
  class Abstract_string_trim;
  typedef Abstract_string_trim* Func_string_trim;
  extern Func_string_trim e_string_trim;
  extern Func_string_trim t_string_trim;
  class Abstract_string_uppercase;
  typedef Abstract_string_uppercase* Func_string_uppercase;
  extern Func_string_uppercase e_string_uppercase;
  extern Func_string_uppercase t_string_uppercase;
  class Abstract_string_from_int;
  typedef Abstract_string_from_int* Func_string_from_int;
  extern Func_string_from_int e_string_from_int;
  extern Func_string_from_int t_string_from_int;
  class Abstract_string_from_string_end;
  typedef Abstract_string_from_string_end* Func_string_from_string_end;
  extern Func_string_from_string_end e_string_from_string_end;
  extern Func_string_from_string_end t_string_from_string_end;
  class Abstract_string_from_string_start;
  typedef Abstract_string_from_string_start* Func_string_from_string_start;
  extern Func_string_from_string_start e_string_from_string_start;
  extern Func_string_from_string_start t_string_from_string_start;
  class Abstract_string_from_string_start_end;
  typedef Abstract_string_from_string_start_end* Func_string_from_string_start_end;
  extern Func_string_from_string_start_end e_string_from_string_start_end;
  extern Func_string_from_string_start_end t_string_from_string_start_end;
  class Abstract_string_from_stringlist_join;
  typedef Abstract_string_from_stringlist_join* Func_string_from_stringlist_join;
  extern Func_string_from_stringlist_join e_string_from_stringlist_join;
  extern Func_string_from_stringlist_join t_string_from_stringlist_join;
  class Abstract_stringlist_from_string_split;
  typedef Abstract_stringlist_from_string_split* Func_stringlist_from_string_split;
  extern Func_stringlist_from_string_split e_stringlist_from_string_split;
  extern Func_stringlist_from_string_split t_stringlist_from_string_split;
  class Abstract_traitnames_from_any;
  typedef Abstract_traitnames_from_any* Func_traitnames_from_any;
  extern Func_traitnames_from_any e_traitnames_from_any;
  extern Func_traitnames_from_any t_traitnames_from_any;
  class Abstract_traits_from_any;
  typedef Abstract_traits_from_any* Func_traits_from_any;
  extern Func_traits_from_any e_traits_from_any;
  extern Func_traits_from_any t_traits_from_any;
  class Abstract_traits_from_typedef;
  typedef Abstract_traits_from_typedef* Func_traits_from_typedef;
  extern Func_traits_from_typedef e_traits_from_typedef;
  extern Func_traits_from_typedef t_traits_from_typedef;// :headerfirst
// :header

  // vx_int_from_string_find(string, string)
  int vx_int_from_string_find(std::string text, std::string find);

  // vx_int_from_string_find(string, string)
  vx_core::Type_int vx_int_from_string_find(vx_core::Type_string text, vx_core::Type_string find);

  // vx_int_from_string_findkeyword(string, string)
  int vx_int_from_string_findkeyword(std::string text, std::string find);

  // vx_int_from_string_findkeyword(string, string)
  vx_core::Type_int vx_int_from_string_findkeyword(vx_core::Type_string text, vx_core::Type_string find);

  // vx_int_from_string_findlast(string, string)
  int vx_int_from_string_findlast(std::string text, std::string find);

  // vx_int_from_string_findlast(string, string)
  vx_core::Type_int vx_int_from_string_findlast(vx_core::Type_string text, vx_core::Type_string findlast);

  // vx_string_from_stringlist_join(stringlist, string)
  vx_core::Type_string vx_string_from_stringlist_join(vx_core::Type_stringlist vals, vx_core::Type_string delim);

  // vx_string_lowercase(string)
  vx_core::Type_string vx_string_lowercase(vx_core::Type_string text);

  // vx_string_trim(string)
  vx_core::Type_string vx_string_trim(vx_core::Type_string text);

  // vx_string_uppercase(string)
  vx_core::Type_string vx_string_uppercase(vx_core::Type_string text);

  // vx_stringlist_from_string_split(string, string)
  vx_core::Type_stringlist vx_stringlist_from_string_split(vx_core::Type_string text, vx_core::Type_string delim);


  // (func allowtypenames<-type)
  vx_core::Type_stringlist f_allowtypenames_from_type(vx_core::Type_any type);

  // (func allowtypes<-type)
  vx_core::Type_typelist f_allowtypes_from_type(vx_core::Type_any type);

  // (func boolean<-string-ends)
  vx_core::Type_boolean f_boolean_from_string_ends(vx_core::Type_string text, vx_core::Type_string ends);

  // (func boolean<-string-starts)
  vx_core::Type_boolean f_boolean_from_string_starts(vx_core::Type_string text, vx_core::Type_string starts);

  // (func int<-string-find)
  vx_core::Type_int f_int_from_string_find(vx_core::Type_string text, vx_core::Type_string find);

  // (func int<-string-findkeyword)
  vx_core::Type_int f_int_from_string_findkeyword(vx_core::Type_string text, vx_core::Type_string find);

  // (func int<-string-findlast)
  vx_core::Type_int f_int_from_string_findlast(vx_core::Type_string text, vx_core::Type_string findlast);

  // (func is-boolean)
  vx_core::Type_boolean f_is_boolean(vx_core::Type_any value);

  // (func is-decimal)
  vx_core::Type_boolean f_is_decimal(vx_core::Type_any value);

  // (func is-none)
  vx_core::Type_boolean f_is_none(vx_core::Type_any value);

  // (func is-string)
  vx_core::Type_boolean f_is_string(vx_core::Type_any value);

  // (func is-type)
  vx_core::Type_boolean f_is_type(vx_core::Type_any value, vx_core::Type_any type);

  // (func is-type<-any-typelist)
  vx_core::Type_boolean f_is_type_from_any_typelist(vx_core::Type_any value, vx_core::Type_typelist typelist);

  // (func string-lowercase)
  vx_core::Type_string f_string_lowercase(vx_core::Type_string text);

  // (func string-outdent)
  vx_core::Type_string f_string_outdent(vx_core::Type_string text);

  // (func string-trim)
  vx_core::Type_string f_string_trim(vx_core::Type_string text);

  // (func string-uppercase)
  vx_core::Type_string f_string_uppercase(vx_core::Type_string text);

  // (func string<-int)
  vx_core::Type_string f_string_from_int(vx_core::Type_int value);

  // (func string<-string-end)
  vx_core::Type_string f_string_from_string_end(vx_core::Type_string text, vx_core::Type_int endpos);

  // (func string<-string-start)
  vx_core::Type_string f_string_from_string_start(vx_core::Type_string text, vx_core::Type_int startpos);

  // (func string<-string-start-end)
  vx_core::Type_string f_string_from_string_start_end(vx_core::Type_string text, vx_core::Type_int start, vx_core::Type_int end);

  // (func string<-stringlist-join)
  vx_core::Type_string f_string_from_stringlist_join(vx_core::Type_stringlist vals, vx_core::Type_string delim);

  // (func stringlist<-string-split)
  vx_core::Type_stringlist f_stringlist_from_string_split(vx_core::Type_string text, vx_core::Type_string delim);

  // (func traitnames<-any)
  vx_core::Type_stringlist f_traitnames_from_any(vx_core::Type_any value);

  // (func traits<-any)
  vx_core::Type_typelist f_traits_from_any(vx_core::Type_any value);

  // (func traits<-typedef)
  vx_core::Type_typelist f_traits_from_typedef(vx_core::Type_typedef vtypedef);

  // (func allowtypenames<-type)
  class Abstract_allowtypenames_from_type : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_allowtypenames_from_type() {};
    virtual ~Abstract_allowtypenames_from_type() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_allowtypenames_from_type : public virtual Abstract_allowtypenames_from_type {
  public:
    Class_allowtypenames_from_type();
    virtual ~Class_allowtypenames_from_type() override;
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

  // (func allowtypes<-type)
  class Abstract_allowtypes_from_type : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_allowtypes_from_type() {};
    virtual ~Abstract_allowtypes_from_type() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_allowtypes_from_type : public virtual Abstract_allowtypes_from_type {
  public:
    Class_allowtypes_from_type();
    virtual ~Class_allowtypes_from_type() override;
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

  // (func any<-int)
  class Abstract_any_from_int : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_int() {};
    virtual ~Abstract_any_from_int() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_int : public virtual Abstract_any_from_int {
  public:
    Class_any_from_int();
    virtual ~Class_any_from_int() override;
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

  // (func boolean<-string-ends)
  class Abstract_boolean_from_string_ends : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_boolean_from_string_ends() {};
    virtual ~Abstract_boolean_from_string_ends() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_boolean_from_string_ends : public virtual Abstract_boolean_from_string_ends {
  public:
    Class_boolean_from_string_ends();
    virtual ~Class_boolean_from_string_ends() override;
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

  // (func boolean<-string-starts)
  class Abstract_boolean_from_string_starts : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_boolean_from_string_starts() {};
    virtual ~Abstract_boolean_from_string_starts() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_boolean_from_string_starts : public virtual Abstract_boolean_from_string_starts {
  public:
    Class_boolean_from_string_starts();
    virtual ~Class_boolean_from_string_starts() override;
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

  // (func int<-string-find)
  class Abstract_int_from_string_find : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_int_from_string_find() {};
    virtual ~Abstract_int_from_string_find() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_int_from_string_find : public virtual Abstract_int_from_string_find {
  public:
    Class_int_from_string_find();
    virtual ~Class_int_from_string_find() override;
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

  // (func int<-string-findkeyword)
  class Abstract_int_from_string_findkeyword : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_int_from_string_findkeyword() {};
    virtual ~Abstract_int_from_string_findkeyword() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_int_from_string_findkeyword : public virtual Abstract_int_from_string_findkeyword {
  public:
    Class_int_from_string_findkeyword();
    virtual ~Class_int_from_string_findkeyword() override;
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

  // (func int<-string-findlast)
  class Abstract_int_from_string_findlast : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_int_from_string_findlast() {};
    virtual ~Abstract_int_from_string_findlast() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_int_from_string_findlast : public virtual Abstract_int_from_string_findlast {
  public:
    Class_int_from_string_findlast();
    virtual ~Class_int_from_string_findlast() override;
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

  // (func is-boolean)
  class Abstract_is_boolean : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_is_boolean() {};
    virtual ~Abstract_is_boolean() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_is_boolean : public virtual Abstract_is_boolean {
  public:
    Class_is_boolean();
    virtual ~Class_is_boolean() override;
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

  // (func is-decimal)
  class Abstract_is_decimal : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_is_decimal() {};
    virtual ~Abstract_is_decimal() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_is_decimal : public virtual Abstract_is_decimal {
  public:
    Class_is_decimal();
    virtual ~Class_is_decimal() override;
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

  // (func is-none)
  class Abstract_is_none : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_is_none() {};
    virtual ~Abstract_is_none() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_is_none : public virtual Abstract_is_none {
  public:
    Class_is_none();
    virtual ~Class_is_none() override;
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

  // (func is-string)
  class Abstract_is_string : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_is_string() {};
    virtual ~Abstract_is_string() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_is_string : public virtual Abstract_is_string {
  public:
    Class_is_string();
    virtual ~Class_is_string() override;
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

  // (func is-type)
  class Abstract_is_type : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_is_type() {};
    virtual ~Abstract_is_type() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_is_type : public virtual Abstract_is_type {
  public:
    Class_is_type();
    virtual ~Class_is_type() override;
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

  // (func is-type<-any-typelist)
  class Abstract_is_type_from_any_typelist : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_is_type_from_any_typelist() {};
    virtual ~Abstract_is_type_from_any_typelist() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_is_type_from_any_typelist : public virtual Abstract_is_type_from_any_typelist {
  public:
    Class_is_type_from_any_typelist();
    virtual ~Class_is_type_from_any_typelist() override;
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

  // (func string-lowercase)
  class Abstract_string_lowercase : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_lowercase() {};
    virtual ~Abstract_string_lowercase() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_lowercase : public virtual Abstract_string_lowercase {
  public:
    Class_string_lowercase();
    virtual ~Class_string_lowercase() override;
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

  // (func string-outdent)
  class Abstract_string_outdent : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_outdent() {};
    virtual ~Abstract_string_outdent() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_outdent : public virtual Abstract_string_outdent {
  public:
    Class_string_outdent();
    virtual ~Class_string_outdent() override;
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

  // (func string-trim)
  class Abstract_string_trim : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_trim() {};
    virtual ~Abstract_string_trim() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_trim : public virtual Abstract_string_trim {
  public:
    Class_string_trim();
    virtual ~Class_string_trim() override;
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

  // (func string-uppercase)
  class Abstract_string_uppercase : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_uppercase() {};
    virtual ~Abstract_string_uppercase() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_uppercase : public virtual Abstract_string_uppercase {
  public:
    Class_string_uppercase();
    virtual ~Class_string_uppercase() override;
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

  // (func string<-int)
  class Abstract_string_from_int : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_int() {};
    virtual ~Abstract_string_from_int() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_int : public virtual Abstract_string_from_int {
  public:
    Class_string_from_int();
    virtual ~Class_string_from_int() override;
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

  // (func string<-string-end)
  class Abstract_string_from_string_end : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_string_end() {};
    virtual ~Abstract_string_from_string_end() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_string_end : public virtual Abstract_string_from_string_end {
  public:
    Class_string_from_string_end();
    virtual ~Class_string_from_string_end() override;
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

  // (func string<-string-start)
  class Abstract_string_from_string_start : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_string_start() {};
    virtual ~Abstract_string_from_string_start() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_string_start : public virtual Abstract_string_from_string_start {
  public:
    Class_string_from_string_start();
    virtual ~Class_string_from_string_start() override;
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

  // (func string<-string-start-end)
  class Abstract_string_from_string_start_end : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_string_start_end() {};
    virtual ~Abstract_string_from_string_start_end() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_string_start_end : public virtual Abstract_string_from_string_start_end {
  public:
    Class_string_from_string_start_end();
    virtual ~Class_string_from_string_start_end() override;
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

  // (func string<-stringlist-join)
  class Abstract_string_from_stringlist_join : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_stringlist_join() {};
    virtual ~Abstract_string_from_stringlist_join() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_stringlist_join : public virtual Abstract_string_from_stringlist_join {
  public:
    Class_string_from_stringlist_join();
    virtual ~Class_string_from_stringlist_join() override;
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

  // (func stringlist<-string-split)
  class Abstract_stringlist_from_string_split : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_stringlist_from_string_split() {};
    virtual ~Abstract_stringlist_from_string_split() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_stringlist_from_string_split : public virtual Abstract_stringlist_from_string_split {
  public:
    Class_stringlist_from_string_split();
    virtual ~Class_stringlist_from_string_split() override;
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

  // (func traitnames<-any)
  class Abstract_traitnames_from_any : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_traitnames_from_any() {};
    virtual ~Abstract_traitnames_from_any() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_traitnames_from_any : public virtual Abstract_traitnames_from_any {
  public:
    Class_traitnames_from_any();
    virtual ~Class_traitnames_from_any() override;
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

  // (func traits<-any)
  class Abstract_traits_from_any : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_traits_from_any() {};
    virtual ~Abstract_traits_from_any() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_traits_from_any : public virtual Abstract_traits_from_any {
  public:
    Class_traits_from_any();
    virtual ~Class_traits_from_any() override;
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

  // (func traits<-typedef)
  class Abstract_traits_from_typedef : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_traits_from_typedef() {};
    virtual ~Abstract_traits_from_typedef() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_traits_from_typedef : public virtual Abstract_traits_from_typedef {
  public:
    Class_traits_from_typedef();
    virtual ~Class_traits_from_typedef() override;
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

  // (func any<-int)
  template <class T> T* f_any_from_int(T* generic_any_1, vx_core::Type_int value) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve(value);
    vx_core::vx_release_one_except(value, output);
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
