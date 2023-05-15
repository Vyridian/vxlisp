#pragma once
#include <memory>
#include "../vx/core.hpp"

namespace vx_type {

  // forward declarations
  class Class_allowtypenames_from_type;
  typedef std::shared_ptr<Class_allowtypenames_from_type> Func_allowtypenames_from_type;
  extern Func_allowtypenames_from_type e_allowtypenames_from_type;
  extern Func_allowtypenames_from_type t_allowtypenames_from_type;
  class Class_allowtypes_from_type;
  typedef std::shared_ptr<Class_allowtypes_from_type> Func_allowtypes_from_type;
  extern Func_allowtypes_from_type e_allowtypes_from_type;
  extern Func_allowtypes_from_type t_allowtypes_from_type;
  class Class_is_boolean;
  typedef std::shared_ptr<Class_is_boolean> Func_is_boolean;
  extern Func_is_boolean e_is_boolean;
  extern Func_is_boolean t_is_boolean;
  class Class_is_decimal;
  typedef std::shared_ptr<Class_is_decimal> Func_is_decimal;
  extern Func_is_decimal e_is_decimal;
  extern Func_is_decimal t_is_decimal;
  class Class_is_float;
  typedef std::shared_ptr<Class_is_float> Func_is_float;
  extern Func_is_float e_is_float;
  extern Func_is_float t_is_float;
  class Class_is_none;
  typedef std::shared_ptr<Class_is_none> Func_is_none;
  extern Func_is_none e_is_none;
  extern Func_is_none t_is_none;
  class Class_is_string;
  typedef std::shared_ptr<Class_is_string> Func_is_string;
  extern Func_is_string e_is_string;
  extern Func_is_string t_is_string;
  class Class_is_type;
  typedef std::shared_ptr<Class_is_type> Func_is_type;
  extern Func_is_type e_is_type;
  extern Func_is_type t_is_type;
  class Class_is_type_from_any_typelist;
  typedef std::shared_ptr<Class_is_type_from_any_typelist> Func_is_type_from_any_typelist;
  extern Func_is_type_from_any_typelist e_is_type_from_any_typelist;
  extern Func_is_type_from_any_typelist t_is_type_from_any_typelist;
  class Class_length_from_string;
  typedef std::shared_ptr<Class_length_from_string> Func_length_from_string;
  extern Func_length_from_string e_length_from_string;
  extern Func_length_from_string t_length_from_string;
  class Class_string_from_int;
  typedef std::shared_ptr<Class_string_from_int> Func_string_from_int;
  extern Func_string_from_int e_string_from_int;
  extern Func_string_from_int t_string_from_int;
  class Class_string_from_string_end;
  typedef std::shared_ptr<Class_string_from_string_end> Func_string_from_string_end;
  extern Func_string_from_string_end e_string_from_string_end;
  extern Func_string_from_string_end t_string_from_string_end;
  class Class_string_from_string_start;
  typedef std::shared_ptr<Class_string_from_string_start> Func_string_from_string_start;
  extern Func_string_from_string_start e_string_from_string_start;
  extern Func_string_from_string_start t_string_from_string_start;
  class Class_string_from_string_start_end;
  typedef std::shared_ptr<Class_string_from_string_start_end> Func_string_from_string_start_end;
  extern Func_string_from_string_start_end e_string_from_string_start_end;
  extern Func_string_from_string_start_end t_string_from_string_start_end;
  class Class_string_from_stringlist_join;
  typedef std::shared_ptr<Class_string_from_stringlist_join> Func_string_from_stringlist_join;
  extern Func_string_from_stringlist_join e_string_from_stringlist_join;
  extern Func_string_from_stringlist_join t_string_from_stringlist_join;
  class Class_traitnames_from_any;
  typedef std::shared_ptr<Class_traitnames_from_any> Func_traitnames_from_any;
  extern Func_traitnames_from_any e_traitnames_from_any;
  extern Func_traitnames_from_any t_traitnames_from_any;
  class Class_traits_from_any;
  typedef std::shared_ptr<Class_traits_from_any> Func_traits_from_any;
  extern Func_traits_from_any e_traits_from_any;
  extern Func_traits_from_any t_traits_from_any;
  class Class_traits_from_typedef;
  typedef std::shared_ptr<Class_traits_from_typedef> Func_traits_from_typedef;
  extern Func_traits_from_typedef e_traits_from_typedef;
  extern Func_traits_from_typedef t_traits_from_typedef;


  // (func allowtypenames<-type)
  class Class_allowtypenames_from_type : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_stringlist vx_allowtypenames_from_type(vx_core::Type_any type);
  };

  // (func allowtypes<-type)
  class Class_allowtypes_from_type : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_typelist vx_allowtypes_from_type(vx_core::Type_any type);
  };

  // (func is-boolean)
  class Class_is_boolean : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_boolean vx_is_boolean(vx_core::Type_any value);
  };

  // (func is-decimal)
  class Class_is_decimal : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_boolean vx_is_decimal(vx_core::Type_any value);
  };

  // (func is-float)
  class Class_is_float : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_boolean vx_is_float(vx_core::Type_any value);
  };

  // (func is-none)
  class Class_is_none : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_boolean vx_is_none(vx_core::Type_any value);
  };

  // (func is-string)
  class Class_is_string : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_boolean vx_is_string(vx_core::Type_any value);
  };

  // (func is-type)
  class Class_is_type : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_is_type(vx_core::Type_any val, vx_core::Type_any type);
  };

  // (func is-type<-any-typelist)
  class Class_is_type_from_any_typelist : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_is_type_from_any_typelist(vx_core::Type_any val, vx_core::Type_typelist typelist);
  };

  // (func length<-string)
  class Class_length_from_string : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_int vx_length_from_string(vx_core::Type_string text);
  };

  // (func string<-int)
  class Class_string_from_int : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_string vx_string_from_int(vx_core::Type_int val);
  };

  // (func string<-string-end)
  class Class_string_from_string_end : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_string_end(vx_core::Type_string text, vx_core::Type_int endpos);
  };

  // (func string<-string-start)
  class Class_string_from_string_start : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_string_start(vx_core::Type_string text, vx_core::Type_int startpos);
  };

  // (func string<-string-start-end)
  class Class_string_from_string_start_end : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_string_start_end(vx_core::Type_string text, vx_core::Type_int start, vx_core::Type_int end);
  };

  // (func string<-stringlist-join)
  class Class_string_from_stringlist_join : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_stringlist_join(vx_core::Type_stringlist vals, vx_core::Type_string delim);
  };

  // (func traitnames<-any)
  class Class_traitnames_from_any : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_stringlist vx_traitnames_from_any(vx_core::Type_any val);
  };

  // (func traits<-any)
  class Class_traits_from_any : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_typelist vx_traits_from_any(vx_core::Type_any val);
  };

  // (func traits<-typedef)
  class Class_traits_from_typedef : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_typelist vx_traits_from_typedef(vx_core::Type_typedef vtypedef);
  };

  // (func allowtypenames<-type)
  vx_core::Type_stringlist f_allowtypenames_from_type(vx_core::Type_any type);

  // (func allowtypes<-type)
  vx_core::Type_typelist f_allowtypes_from_type(vx_core::Type_any type);

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

}
