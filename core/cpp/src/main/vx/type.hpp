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
  class Abstract_int_from_string_find;
  typedef Abstract_int_from_string_find* Func_int_from_string_find;
  extern Func_int_from_string_find e_int_from_string_find;
  extern Func_int_from_string_find t_int_from_string_find;
  class Abstract_int_from_string_findkeyword;
  typedef Abstract_int_from_string_findkeyword* Func_int_from_string_findkeyword;
  extern Func_int_from_string_findkeyword e_int_from_string_findkeyword;
  extern Func_int_from_string_findkeyword t_int_from_string_findkeyword;
  class Abstract_is_boolean;
  typedef Abstract_is_boolean* Func_is_boolean;
  extern Func_is_boolean e_is_boolean;
  extern Func_is_boolean t_is_boolean;
  class Abstract_is_decimal;
  typedef Abstract_is_decimal* Func_is_decimal;
  extern Func_is_decimal e_is_decimal;
  extern Func_is_decimal t_is_decimal;
  class Abstract_is_float;
  typedef Abstract_is_float* Func_is_float;
  extern Func_is_float e_is_float;
  extern Func_is_float t_is_float;
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
  class Abstract_length_from_string;
  typedef Abstract_length_from_string* Func_length_from_string;
  extern Func_length_from_string e_length_from_string;
  extern Func_length_from_string t_length_from_string;
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

  // vx_int_from_string_findkeyword(string, string)
  int vx_int_from_string_findkeyword(std::string text, std::string find);

  // vx_string_from_stringlist_join(stringlist, string)
  vx_core::Type_string vx_string_from_stringlist_join(vx_core::Type_stringlist vals, vx_core::Type_string delim);


  // (func allowtypenames<-type)
  vx_core::Type_stringlist f_allowtypenames_from_type(vx_core::Type_any type);

  // (func allowtypes<-type)
  vx_core::Type_typelist f_allowtypes_from_type(vx_core::Type_any type);

  // (func int<-string-find)
  vx_core::Type_int f_int_from_string_find(vx_core::Type_string text, vx_core::Type_string find);

  // (func int<-string-findkeyword)
  vx_core::Type_int f_int_from_string_findkeyword(vx_core::Type_string text, vx_core::Type_string find);

  // (func is-boolean)
  vx_core::Type_boolean f_is_boolean(vx_core::Type_any value);

  // (func is-decimal)
  vx_core::Type_boolean f_is_decimal(vx_core::Type_any value);

  // (func is-float)
  vx_core::Type_boolean f_is_float(vx_core::Type_any value);

  // (func is-none)
  vx_core::Type_boolean f_is_none(vx_core::Type_any value);

  // (func is-string)
  vx_core::Type_boolean f_is_string(vx_core::Type_any value);

  // (func is-type)
  vx_core::Type_boolean f_is_type(vx_core::Type_any val, vx_core::Type_any type);

  // (func is-type<-any-typelist)
  vx_core::Type_boolean f_is_type_from_any_typelist(vx_core::Type_any val, vx_core::Type_typelist typelist);

  // (func length<-string)
  vx_core::Type_int f_length_from_string(vx_core::Type_string text);

  // (func string<-int)
  vx_core::Type_string f_string_from_int(vx_core::Type_int val);

  // (func string<-string-end)
  vx_core::Type_string f_string_from_string_end(vx_core::Type_string text, vx_core::Type_int endpos);

  // (func string<-string-start)
  vx_core::Type_string f_string_from_string_start(vx_core::Type_string text, vx_core::Type_int startpos);

  // (func string<-string-start-end)
  vx_core::Type_string f_string_from_string_start_end(vx_core::Type_string text, vx_core::Type_int start, vx_core::Type_int end);

  // (func string<-stringlist-join)
  vx_core::Type_string f_string_from_stringlist_join(vx_core::Type_stringlist vals, vx_core::Type_string delim);

  // (func traitnames<-any)
  vx_core::Type_stringlist f_traitnames_from_any(vx_core::Type_any val);

  // (func traits<-any)
  vx_core::Type_typelist f_traits_from_any(vx_core::Type_any val);

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
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
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
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func is-float)
  class Abstract_is_float : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_is_float() {};
    virtual ~Abstract_is_float() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_is_float : public virtual Abstract_is_float {
  public:
    Class_is_float();
    virtual ~Class_is_float() override;
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
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func length<-string)
  class Abstract_length_from_string : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_length_from_string() {};
    virtual ~Abstract_length_from_string() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_length_from_string : public virtual Abstract_length_from_string {
  public:
    Class_length_from_string();
    virtual ~Class_length_from_string() override;
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
