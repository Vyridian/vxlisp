#include <string>
#include "../vx/core.hpp"
#include "type.hpp"

namespace vx_type {
// :body

  // vx_string_from_stringlist_join(stringlist, string)
  vx_core::Type_string vx_string_from_stringlist_join(vx_core::Type_stringlist vals, vx_core::Type_string delim) {
    bool isfirst = true;
    std::string str = "";
    std::string sdelim = delim->vx_string();
    for (vx_core::Type_string substr : vals->vx_p_list) {
      std::string ssub = substr->vx_string();
      if (isfirst) {
        str = ssub;
      } else {
        str += sdelim + ssub;
      }
      isfirst = false;
    }
    vx_core::Type_string output = vx_core::vx_new_string(str);
    return output;
	}


  // (func allowtypenames<-type)
  vx_core::Type_stringlist f_allowtypenames_from_type(vx_core::Type_any type) {
    vx_core::Type_stringlist output = vx_core::e_stringlist;
    vx_core::vx_reserve(type);
    output = vx_core::f_typenames_from_typelist(
      vx_type::f_allowtypes_from_type(type)
    );
    vx_core::vx_release_one_except(type, output);
    return output;
  }

  // (func allowtypenames<-type)
  // class Class_allowtypenames_from_type {
    Abstract_allowtypenames_from_type::~Abstract_allowtypenames_from_type() {}

    Class_allowtypenames_from_type::Class_allowtypenames_from_type() : Abstract_allowtypenames_from_type::Abstract_allowtypenames_from_type() {
      vx_core::refcount += 1;
    }

    Class_allowtypenames_from_type::~Class_allowtypenames_from_type() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_allowtypenames_from_type::vx_new(vx_core::vx_Type_listany vals) const {
      vx_type::Func_allowtypenames_from_type output = vx_type::e_allowtypenames_from_type;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_allowtypenames_from_type::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_type::Func_allowtypenames_from_type output = vx_type::e_allowtypenames_from_type;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_allowtypenames_from_type::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/type", // pkgname
        "allowtypenames<-type", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_allowtypenames_from_type::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "allowtypenames<-type", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_allowtypenames_from_type::vx_empty() const {return vx_type::e_allowtypenames_from_type;}
    vx_core::Type_any Class_allowtypenames_from_type::vx_type() const {return vx_type::t_allowtypenames_from_type;}
    vx_core::Type_msgblock Class_allowtypenames_from_type::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_allowtypenames_from_type::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_allowtypenames_from_type::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_allowtypenames_from_type::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any, val);
      output = vx_type::f_allowtypenames_from_type(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_allowtypenames_from_type::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any type = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_type::f_allowtypenames_from_type(type);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func allowtypes<-type)
  vx_core::Type_typelist f_allowtypes_from_type(vx_core::Type_any type) {
    vx_core::Type_typelist output = vx_core::e_typelist;
    vx_core::vx_reserve(type);
    output = vx_core::f_any_from_struct(
      vx_core::t_typelist,
      vx_core::f_typedef_from_type(type),
      vx_core::vx_new_string(":allowtypes")
    );
    vx_core::vx_release_one_except(type, output);
    return output;
  }

  // (func allowtypes<-type)
  // class Class_allowtypes_from_type {
    Abstract_allowtypes_from_type::~Abstract_allowtypes_from_type() {}

    Class_allowtypes_from_type::Class_allowtypes_from_type() : Abstract_allowtypes_from_type::Abstract_allowtypes_from_type() {
      vx_core::refcount += 1;
    }

    Class_allowtypes_from_type::~Class_allowtypes_from_type() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_allowtypes_from_type::vx_new(vx_core::vx_Type_listany vals) const {
      vx_type::Func_allowtypes_from_type output = vx_type::e_allowtypes_from_type;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_allowtypes_from_type::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_type::Func_allowtypes_from_type output = vx_type::e_allowtypes_from_type;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_allowtypes_from_type::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/type", // pkgname
        "allowtypes<-type", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_allowtypes_from_type::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "allowtypes<-type", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_allowtypes_from_type::vx_empty() const {return vx_type::e_allowtypes_from_type;}
    vx_core::Type_any Class_allowtypes_from_type::vx_type() const {return vx_type::t_allowtypes_from_type;}
    vx_core::Type_msgblock Class_allowtypes_from_type::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_allowtypes_from_type::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_allowtypes_from_type::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_allowtypes_from_type::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any, val);
      output = vx_type::f_allowtypes_from_type(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_allowtypes_from_type::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any type = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_type::f_allowtypes_from_type(type);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func is-boolean)
  vx_core::Type_boolean f_is_boolean(vx_core::Type_any value) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve(value);
    output = vx_core::f_eq(
      vx_core::vx_new_string("boolean"),
      vx_core::f_typename_from_any(value)
    );
    vx_core::vx_release_one_except(value, output);
    return output;
  }

  // (func is-boolean)
  // class Class_is_boolean {
    Abstract_is_boolean::~Abstract_is_boolean() {}

    Class_is_boolean::Class_is_boolean() : Abstract_is_boolean::Abstract_is_boolean() {
      vx_core::refcount += 1;
    }

    Class_is_boolean::~Class_is_boolean() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_is_boolean::vx_new(vx_core::vx_Type_listany vals) const {
      vx_type::Func_is_boolean output = vx_type::e_is_boolean;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_is_boolean::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_type::Func_is_boolean output = vx_type::e_is_boolean;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_is_boolean::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/type", // pkgname
        "is-boolean", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_is_boolean::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "is-boolean", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_is_boolean::vx_empty() const {return vx_type::e_is_boolean;}
    vx_core::Type_any Class_is_boolean::vx_type() const {return vx_type::t_is_boolean;}
    vx_core::Type_msgblock Class_is_boolean::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_is_boolean::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_is_boolean::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_is_boolean::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any, val);
      output = vx_type::f_is_boolean(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_is_boolean::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_type::f_is_boolean(value);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func is-decimal)
  vx_core::Type_boolean f_is_decimal(vx_core::Type_any value) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve(value);
    output = vx_core::f_eq(
      vx_core::vx_new_string("decimal"),
      vx_core::f_typename_from_any(value)
    );
    vx_core::vx_release_one_except(value, output);
    return output;
  }

  // (func is-decimal)
  // class Class_is_decimal {
    Abstract_is_decimal::~Abstract_is_decimal() {}

    Class_is_decimal::Class_is_decimal() : Abstract_is_decimal::Abstract_is_decimal() {
      vx_core::refcount += 1;
    }

    Class_is_decimal::~Class_is_decimal() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_is_decimal::vx_new(vx_core::vx_Type_listany vals) const {
      vx_type::Func_is_decimal output = vx_type::e_is_decimal;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_is_decimal::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_type::Func_is_decimal output = vx_type::e_is_decimal;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_is_decimal::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/type", // pkgname
        "is-decimal", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_is_decimal::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "is-decimal", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_is_decimal::vx_empty() const {return vx_type::e_is_decimal;}
    vx_core::Type_any Class_is_decimal::vx_type() const {return vx_type::t_is_decimal;}
    vx_core::Type_msgblock Class_is_decimal::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_is_decimal::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_is_decimal::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_is_decimal::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any, val);
      output = vx_type::f_is_decimal(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_is_decimal::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_type::f_is_decimal(value);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func is-float)
  vx_core::Type_boolean f_is_float(vx_core::Type_any value) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve(value);
    output = vx_core::f_eq(
      vx_core::vx_new_string("float"),
      vx_core::f_typename_from_any(value)
    );
    vx_core::vx_release_one_except(value, output);
    return output;
  }

  // (func is-float)
  // class Class_is_float {
    Abstract_is_float::~Abstract_is_float() {}

    Class_is_float::Class_is_float() : Abstract_is_float::Abstract_is_float() {
      vx_core::refcount += 1;
    }

    Class_is_float::~Class_is_float() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_is_float::vx_new(vx_core::vx_Type_listany vals) const {
      vx_type::Func_is_float output = vx_type::e_is_float;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_is_float::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_type::Func_is_float output = vx_type::e_is_float;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_is_float::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/type", // pkgname
        "is-float", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_is_float::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "is-float", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_is_float::vx_empty() const {return vx_type::e_is_float;}
    vx_core::Type_any Class_is_float::vx_type() const {return vx_type::t_is_float;}
    vx_core::Type_msgblock Class_is_float::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_is_float::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_is_float::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_is_float::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any, val);
      output = vx_type::f_is_float(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_is_float::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_type::f_is_float(value);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func is-none)
  vx_core::Type_boolean f_is_none(vx_core::Type_any value) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve(value);
    output = vx_core::f_eq(
      value,
      vx_core::t_none
    );
    vx_core::vx_release_one_except(value, output);
    return output;
  }

  // (func is-none)
  // class Class_is_none {
    Abstract_is_none::~Abstract_is_none() {}

    Class_is_none::Class_is_none() : Abstract_is_none::Abstract_is_none() {
      vx_core::refcount += 1;
    }

    Class_is_none::~Class_is_none() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_is_none::vx_new(vx_core::vx_Type_listany vals) const {
      vx_type::Func_is_none output = vx_type::e_is_none;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_is_none::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_type::Func_is_none output = vx_type::e_is_none;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_is_none::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/type", // pkgname
        "is-none", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_is_none::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "is-none", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_is_none::vx_empty() const {return vx_type::e_is_none;}
    vx_core::Type_any Class_is_none::vx_type() const {return vx_type::t_is_none;}
    vx_core::Type_msgblock Class_is_none::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_is_none::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_is_none::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_is_none::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any, val);
      output = vx_type::f_is_none(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_is_none::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_type::f_is_none(value);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func is-string)
  vx_core::Type_boolean f_is_string(vx_core::Type_any value) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve(value);
    output = vx_core::f_eq(
      vx_core::vx_new_string("vx/core/string"),
      vx_core::f_typename_from_any(value)
    );
    vx_core::vx_release_one_except(value, output);
    return output;
  }

  // (func is-string)
  // class Class_is_string {
    Abstract_is_string::~Abstract_is_string() {}

    Class_is_string::Class_is_string() : Abstract_is_string::Abstract_is_string() {
      vx_core::refcount += 1;
    }

    Class_is_string::~Class_is_string() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_is_string::vx_new(vx_core::vx_Type_listany vals) const {
      vx_type::Func_is_string output = vx_type::e_is_string;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_is_string::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_type::Func_is_string output = vx_type::e_is_string;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_is_string::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/type", // pkgname
        "is-string", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_is_string::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "is-string", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_is_string::vx_empty() const {return vx_type::e_is_string;}
    vx_core::Type_any Class_is_string::vx_type() const {return vx_type::t_is_string;}
    vx_core::Type_msgblock Class_is_string::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_is_string::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_is_string::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_is_string::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any, val);
      output = vx_type::f_is_string(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_is_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_type::f_is_string(value);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func is-type)
  vx_core::Type_boolean f_is_type(vx_core::Type_any val, vx_core::Type_any type) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve({val, type});
    output = vx_core::f_or_1(
      vx_core::vx_new(vx_core::t_booleanlist, {
        vx_core::f_eq(
          vx_core::f_typename_from_type(type),
          vx_core::f_typename_from_any(val)
        ),
        vx_core::f_contains_1(
          vx_type::f_allowtypenames_from_type(type),
          vx_core::f_typename_from_any(val)
        ),
        vx_core::f_contains_1(
          vx_type::f_traitnames_from_any(val),
          vx_core::f_typename_from_type(type)
        )
      })
    );
    vx_core::vx_release_one_except({val, type}, output);
    return output;
  }

  // (func is-type)
  // class Class_is_type {
    Abstract_is_type::~Abstract_is_type() {}

    Class_is_type::Class_is_type() : Abstract_is_type::Abstract_is_type() {
      vx_core::refcount += 1;
    }

    Class_is_type::~Class_is_type() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_is_type::vx_new(vx_core::vx_Type_listany vals) const {
      vx_type::Func_is_type output = vx_type::e_is_type;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_is_type::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_type::Func_is_type output = vx_type::e_is_type;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_is_type::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/type", // pkgname
        "is-type", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_is_type::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "is-type", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_is_type::vx_empty() const {return vx_type::e_is_type;}
    vx_core::Type_any Class_is_type::vx_type() const {return vx_type::t_is_type;}
    vx_core::Type_msgblock Class_is_type::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_is_type::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_is_type::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any val = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any type = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_type::f_is_type(val, type);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func is-type<-any-typelist)
  vx_core::Type_boolean f_is_type_from_any_typelist(vx_core::Type_any val, vx_core::Type_typelist typelist) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve({val, typelist});
    output = vx_core::f_any_from_list_reduce(
      vx_core::t_boolean,
      typelist,
      vx_core::vx_new_boolean(false),
      vx_core::t_any_from_reduce->vx_fn_new({val}, [val](vx_core::Type_any result_any, vx_core::Type_any type_any) {
        vx_core::Type_boolean result = vx_core::vx_any_from_any(vx_core::t_boolean, result_any);
        vx_core::Type_any type = vx_core::vx_any_from_any(vx_core::t_any, type_any);
        vx_core::Type_any output_1 = 
          vx_core::f_or(
            result,
            vx_type::f_is_type(val, type)
          );
        return output_1;
      })
    );
    vx_core::vx_release_one_except({val, typelist}, output);
    return output;
  }

  // (func is-type<-any-typelist)
  // class Class_is_type_from_any_typelist {
    Abstract_is_type_from_any_typelist::~Abstract_is_type_from_any_typelist() {}

    Class_is_type_from_any_typelist::Class_is_type_from_any_typelist() : Abstract_is_type_from_any_typelist::Abstract_is_type_from_any_typelist() {
      vx_core::refcount += 1;
    }

    Class_is_type_from_any_typelist::~Class_is_type_from_any_typelist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_is_type_from_any_typelist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_type::Func_is_type_from_any_typelist output = vx_type::e_is_type_from_any_typelist;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_is_type_from_any_typelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_type::Func_is_type_from_any_typelist output = vx_type::e_is_type_from_any_typelist;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_is_type_from_any_typelist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/type", // pkgname
        "is-type<-any-typelist", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_is_type_from_any_typelist::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "is-type<-any-typelist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_is_type_from_any_typelist::vx_empty() const {return vx_type::e_is_type_from_any_typelist;}
    vx_core::Type_any Class_is_type_from_any_typelist::vx_type() const {return vx_type::t_is_type_from_any_typelist;}
    vx_core::Type_msgblock Class_is_type_from_any_typelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_is_type_from_any_typelist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_is_type_from_any_typelist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any val = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_typelist typelist = vx_core::vx_any_from_any(vx_core::t_typelist, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_type::f_is_type_from_any_typelist(val, typelist);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func length<-string)
  vx_core::Type_int f_length_from_string(vx_core::Type_string text) {
    vx_core::Type_int output = vx_core::e_int;
    vx_core::vx_reserve(text);
    long len = text->vx_string().length();
    output = vx_core::vx_new_int(len);
    vx_core::vx_release_one_except(text, output);
    return output;
  }

  // (func length<-string)
  // class Class_length_from_string {
    Abstract_length_from_string::~Abstract_length_from_string() {}

    Class_length_from_string::Class_length_from_string() : Abstract_length_from_string::Abstract_length_from_string() {
      vx_core::refcount += 1;
    }

    Class_length_from_string::~Class_length_from_string() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_length_from_string::vx_new(vx_core::vx_Type_listany vals) const {
      vx_type::Func_length_from_string output = vx_type::e_length_from_string;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_length_from_string::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_type::Func_length_from_string output = vx_type::e_length_from_string;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_length_from_string::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/type", // pkgname
        "length<-string", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_length_from_string::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "length<-string", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_length_from_string::vx_empty() const {return vx_type::e_length_from_string;}
    vx_core::Type_any Class_length_from_string::vx_type() const {return vx_type::t_length_from_string;}
    vx_core::Type_msgblock Class_length_from_string::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_length_from_string::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_length_from_string::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_length_from_string::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      output = vx_type::f_length_from_string(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_length_from_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_type::f_length_from_string(text);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-int)
  vx_core::Type_string f_string_from_int(vx_core::Type_int val) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve(val);
    output = vx_core::f_switch(
      vx_core::t_string,
      val,
      vx_core::vx_new(vx_core::t_thenelselist, {
        vx_core::f_case_1(
          vx_core::c_infinity(),
          vx_core::t_any_from_func->vx_fn_new({}, []() {
            vx_core::Type_string output_1 = vx_core::vx_new_string("infinity");
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_core::c_neginfinity(),
          vx_core::t_any_from_func->vx_fn_new({}, []() {
            vx_core::Type_string output_1 = vx_core::vx_new_string("neginfinity");
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_core::c_notanumber(),
          vx_core::t_any_from_func->vx_fn_new({}, []() {
            vx_core::Type_string output_1 = vx_core::vx_new_string("notanumber");
            return output_1;
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func->vx_fn_new({val}, [val]() {
            vx_core::Type_string output_1 = vx_core::f_new(
              vx_core::t_string,
              vx_core::vx_new(vx_core::t_anylist, {
                val
              })
            );
            return output_1;
          })
        )
      })
    );
    vx_core::vx_release_one_except(val, output);
    return output;
  }

  // (func string<-int)
  // class Class_string_from_int {
    Abstract_string_from_int::~Abstract_string_from_int() {}

    Class_string_from_int::Class_string_from_int() : Abstract_string_from_int::Abstract_string_from_int() {
      vx_core::refcount += 1;
    }

    Class_string_from_int::~Class_string_from_int() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_int::vx_new(vx_core::vx_Type_listany vals) const {
      vx_type::Func_string_from_int output = vx_type::e_string_from_int;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_int::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_type::Func_string_from_int output = vx_type::e_string_from_int;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_int::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/type", // pkgname
        "string<-int", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_string_from_int::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "string<-int", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_int::vx_empty() const {return vx_type::e_string_from_int;}
    vx_core::Type_any Class_string_from_int::vx_type() const {return vx_type::t_string_from_int;}
    vx_core::Type_msgblock Class_string_from_int::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_int::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_string_from_int::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_string_from_int::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_int inputval = vx_core::vx_any_from_any(vx_core::t_int, val);
      output = vx_type::f_string_from_int(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_string_from_int::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_int val = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_type::f_string_from_int(val);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-string-end)
  vx_core::Type_string f_string_from_string_end(vx_core::Type_string text, vx_core::Type_int endpos) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({text, endpos});
    output = vx_type::f_string_from_string_start_end(text, vx_core::vx_new_int(0), endpos);
    vx_core::vx_release_one_except({text, endpos}, output);
    return output;
  }

  // (func string<-string-end)
  // class Class_string_from_string_end {
    Abstract_string_from_string_end::~Abstract_string_from_string_end() {}

    Class_string_from_string_end::Class_string_from_string_end() : Abstract_string_from_string_end::Abstract_string_from_string_end() {
      vx_core::refcount += 1;
    }

    Class_string_from_string_end::~Class_string_from_string_end() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_string_end::vx_new(vx_core::vx_Type_listany vals) const {
      vx_type::Func_string_from_string_end output = vx_type::e_string_from_string_end;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_string_end::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_type::Func_string_from_string_end output = vx_type::e_string_from_string_end;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_string_end::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/type", // pkgname
        "string<-string-end", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_string_from_string_end::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "string<-string-end", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_string_end::vx_empty() const {return vx_type::e_string_from_string_end;}
    vx_core::Type_any Class_string_from_string_end::vx_type() const {return vx_type::t_string_from_string_end;}
    vx_core::Type_msgblock Class_string_from_string_end::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_string_end::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_string_end::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int endpos = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_type::f_string_from_string_end(text, endpos);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-string-start)
  vx_core::Type_string f_string_from_string_start(vx_core::Type_string text, vx_core::Type_int startpos) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({text, startpos});
    output = vx_type::f_string_from_string_start_end(
      text,
      startpos,
      vx_type::f_length_from_string(text)
    );
    vx_core::vx_release_one_except({text, startpos}, output);
    return output;
  }

  // (func string<-string-start)
  // class Class_string_from_string_start {
    Abstract_string_from_string_start::~Abstract_string_from_string_start() {}

    Class_string_from_string_start::Class_string_from_string_start() : Abstract_string_from_string_start::Abstract_string_from_string_start() {
      vx_core::refcount += 1;
    }

    Class_string_from_string_start::~Class_string_from_string_start() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_string_start::vx_new(vx_core::vx_Type_listany vals) const {
      vx_type::Func_string_from_string_start output = vx_type::e_string_from_string_start;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_string_start::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_type::Func_string_from_string_start output = vx_type::e_string_from_string_start;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_string_start::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/type", // pkgname
        "string<-string-start", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_string_from_string_start::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "string<-string-start", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_string_start::vx_empty() const {return vx_type::e_string_from_string_start;}
    vx_core::Type_any Class_string_from_string_start::vx_type() const {return vx_type::t_string_from_string_start;}
    vx_core::Type_msgblock Class_string_from_string_start::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_string_start::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_string_start::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int startpos = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_type::f_string_from_string_start(text, startpos);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-string-start-end)
  vx_core::Type_string f_string_from_string_start_end(vx_core::Type_string text, vx_core::Type_int start, vx_core::Type_int end) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({text, start, end});
    std::string str = vx_core::vx_string_from_string_start_end(text->vx_string(), start->vx_int(), end->vx_int());
    output = vx_core::vx_new_string(str);
    vx_core::vx_release_one_except({text, start, end}, output);
    return output;
  }

  // (func string<-string-start-end)
  // class Class_string_from_string_start_end {
    Abstract_string_from_string_start_end::~Abstract_string_from_string_start_end() {}

    Class_string_from_string_start_end::Class_string_from_string_start_end() : Abstract_string_from_string_start_end::Abstract_string_from_string_start_end() {
      vx_core::refcount += 1;
    }

    Class_string_from_string_start_end::~Class_string_from_string_start_end() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_string_start_end::vx_new(vx_core::vx_Type_listany vals) const {
      vx_type::Func_string_from_string_start_end output = vx_type::e_string_from_string_start_end;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_string_start_end::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_type::Func_string_from_string_start_end output = vx_type::e_string_from_string_start_end;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_string_start_end::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/type", // pkgname
        "string<-string-start-end", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_string_from_string_start_end::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "string<-string-start-end", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_string_start_end::vx_empty() const {return vx_type::e_string_from_string_start_end;}
    vx_core::Type_any Class_string_from_string_start_end::vx_type() const {return vx_type::t_string_from_string_start_end;}
    vx_core::Type_msgblock Class_string_from_string_start_end::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_string_start_end::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_string_start_end::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int start = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_int end = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_type::f_string_from_string_start_end(text, start, end);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-stringlist-join)
  vx_core::Type_string f_string_from_stringlist_join(vx_core::Type_stringlist vals, vx_core::Type_string delim) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({vals, delim});
    output = vx_type::vx_string_from_stringlist_join(vals, delim);
    vx_core::vx_release_one_except({vals, delim}, output);
    return output;
  }

  // (func string<-stringlist-join)
  // class Class_string_from_stringlist_join {
    Abstract_string_from_stringlist_join::~Abstract_string_from_stringlist_join() {}

    Class_string_from_stringlist_join::Class_string_from_stringlist_join() : Abstract_string_from_stringlist_join::Abstract_string_from_stringlist_join() {
      vx_core::refcount += 1;
    }

    Class_string_from_stringlist_join::~Class_string_from_stringlist_join() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_stringlist_join::vx_new(vx_core::vx_Type_listany vals) const {
      vx_type::Func_string_from_stringlist_join output = vx_type::e_string_from_stringlist_join;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_stringlist_join::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_type::Func_string_from_stringlist_join output = vx_type::e_string_from_stringlist_join;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_stringlist_join::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/type", // pkgname
        "string<-stringlist-join", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_string_from_stringlist_join::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "string<-stringlist-join", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_stringlist_join::vx_empty() const {return vx_type::e_string_from_stringlist_join;}
    vx_core::Type_any Class_string_from_stringlist_join::vx_type() const {return vx_type::t_string_from_stringlist_join;}
    vx_core::Type_msgblock Class_string_from_stringlist_join::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_stringlist_join::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_stringlist_join::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_stringlist vals = vx_core::vx_any_from_any(vx_core::t_stringlist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string delim = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_type::f_string_from_stringlist_join(vals, delim);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func traitnames<-any)
  vx_core::Type_stringlist f_traitnames_from_any(vx_core::Type_any val) {
    vx_core::Type_stringlist output = vx_core::e_stringlist;
    vx_core::vx_reserve(val);
    output = vx_core::f_typenames_from_typelist(
      vx_type::f_traits_from_any(val)
    );
    vx_core::vx_release_one_except(val, output);
    return output;
  }

  // (func traitnames<-any)
  // class Class_traitnames_from_any {
    Abstract_traitnames_from_any::~Abstract_traitnames_from_any() {}

    Class_traitnames_from_any::Class_traitnames_from_any() : Abstract_traitnames_from_any::Abstract_traitnames_from_any() {
      vx_core::refcount += 1;
    }

    Class_traitnames_from_any::~Class_traitnames_from_any() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_traitnames_from_any::vx_new(vx_core::vx_Type_listany vals) const {
      vx_type::Func_traitnames_from_any output = vx_type::e_traitnames_from_any;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_traitnames_from_any::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_type::Func_traitnames_from_any output = vx_type::e_traitnames_from_any;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_traitnames_from_any::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/type", // pkgname
        "traitnames<-any", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_traitnames_from_any::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "traitnames<-any", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_traitnames_from_any::vx_empty() const {return vx_type::e_traitnames_from_any;}
    vx_core::Type_any Class_traitnames_from_any::vx_type() const {return vx_type::t_traitnames_from_any;}
    vx_core::Type_msgblock Class_traitnames_from_any::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_traitnames_from_any::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_traitnames_from_any::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_traitnames_from_any::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any, val);
      output = vx_type::f_traitnames_from_any(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_traitnames_from_any::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any val = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_type::f_traitnames_from_any(val);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func traits<-any)
  vx_core::Type_typelist f_traits_from_any(vx_core::Type_any val) {
    vx_core::Type_typelist output = vx_core::e_typelist;
    vx_core::vx_reserve(val);
    output = vx_core::f_traits_from_typedef(
      vx_core::f_typedef_from_any(val)
    );
    vx_core::vx_release_one_except(val, output);
    return output;
  }

  // (func traits<-any)
  // class Class_traits_from_any {
    Abstract_traits_from_any::~Abstract_traits_from_any() {}

    Class_traits_from_any::Class_traits_from_any() : Abstract_traits_from_any::Abstract_traits_from_any() {
      vx_core::refcount += 1;
    }

    Class_traits_from_any::~Class_traits_from_any() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_traits_from_any::vx_new(vx_core::vx_Type_listany vals) const {
      vx_type::Func_traits_from_any output = vx_type::e_traits_from_any;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_traits_from_any::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_type::Func_traits_from_any output = vx_type::e_traits_from_any;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_traits_from_any::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/type", // pkgname
        "traits<-any", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_traits_from_any::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "traits<-any", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_traits_from_any::vx_empty() const {return vx_type::e_traits_from_any;}
    vx_core::Type_any Class_traits_from_any::vx_type() const {return vx_type::t_traits_from_any;}
    vx_core::Type_msgblock Class_traits_from_any::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_traits_from_any::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_traits_from_any::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_traits_from_any::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any, val);
      output = vx_type::f_traits_from_any(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_traits_from_any::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any val = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_type::f_traits_from_any(val);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func traits<-typedef)
  vx_core::Type_typelist f_traits_from_typedef(vx_core::Type_typedef vtypedef) {
    vx_core::Type_typelist output = vx_core::e_typelist;
    vx_core::vx_reserve(vtypedef);
    output = vtypedef->traits();
    vx_core::vx_release_one_except(vtypedef, output);
    return output;
  }

  // (func traits<-typedef)
  // class Class_traits_from_typedef {
    Abstract_traits_from_typedef::~Abstract_traits_from_typedef() {}

    Class_traits_from_typedef::Class_traits_from_typedef() : Abstract_traits_from_typedef::Abstract_traits_from_typedef() {
      vx_core::refcount += 1;
    }

    Class_traits_from_typedef::~Class_traits_from_typedef() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_traits_from_typedef::vx_new(vx_core::vx_Type_listany vals) const {
      vx_type::Func_traits_from_typedef output = vx_type::e_traits_from_typedef;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_traits_from_typedef::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_type::Func_traits_from_typedef output = vx_type::e_traits_from_typedef;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_traits_from_typedef::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/type", // pkgname
        "traits<-typedef", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_traits_from_typedef::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "traits<-typedef", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_traits_from_typedef::vx_empty() const {return vx_type::e_traits_from_typedef;}
    vx_core::Type_any Class_traits_from_typedef::vx_type() const {return vx_type::t_traits_from_typedef;}
    vx_core::Type_msgblock Class_traits_from_typedef::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_traits_from_typedef::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_traits_from_typedef::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_traits_from_typedef::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_typedef inputval = vx_core::vx_any_from_any(vx_core::t_typedef, val);
      output = vx_type::f_traits_from_typedef(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_traits_from_typedef::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_typedef vtypedef = vx_core::vx_any_from_any(vx_core::t_typedef, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_type::f_traits_from_typedef(vtypedef);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_type::vx_Class_package* vx_package = new vx_type::vx_Class_package();

  // (func allowtypenames<-type)
  vx_type::Func_allowtypenames_from_type vx_e_allowtypenames_from_type() {
    vx_type::Func_allowtypenames_from_type output = new vx_type::Class_allowtypenames_from_type();
    vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_type::Func_allowtypenames_from_type vx_t_allowtypenames_from_type() {
    vx_type::Func_allowtypenames_from_type output = new vx_type::Class_allowtypenames_from_type();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_type::Func_allowtypenames_from_type e_allowtypenames_from_type = vx_e_allowtypenames_from_type();
  vx_type::Func_allowtypenames_from_type t_allowtypenames_from_type = vx_t_allowtypenames_from_type();

  // (func allowtypes<-type)
  vx_type::Func_allowtypes_from_type vx_e_allowtypes_from_type() {
    vx_type::Func_allowtypes_from_type output = new vx_type::Class_allowtypes_from_type();
    vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_type::Func_allowtypes_from_type vx_t_allowtypes_from_type() {
    vx_type::Func_allowtypes_from_type output = new vx_type::Class_allowtypes_from_type();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_type::Func_allowtypes_from_type e_allowtypes_from_type = vx_e_allowtypes_from_type();
  vx_type::Func_allowtypes_from_type t_allowtypes_from_type = vx_t_allowtypes_from_type();

  // (func is-boolean)
  vx_type::Func_is_boolean vx_e_is_boolean() {
    vx_type::Func_is_boolean output = new vx_type::Class_is_boolean();
    vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_type::Func_is_boolean vx_t_is_boolean() {
    vx_type::Func_is_boolean output = new vx_type::Class_is_boolean();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_type::Func_is_boolean e_is_boolean = vx_e_is_boolean();
  vx_type::Func_is_boolean t_is_boolean = vx_t_is_boolean();

  // (func is-decimal)
  vx_type::Func_is_decimal vx_e_is_decimal() {
    vx_type::Func_is_decimal output = new vx_type::Class_is_decimal();
    vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_type::Func_is_decimal vx_t_is_decimal() {
    vx_type::Func_is_decimal output = new vx_type::Class_is_decimal();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_type::Func_is_decimal e_is_decimal = vx_e_is_decimal();
  vx_type::Func_is_decimal t_is_decimal = vx_t_is_decimal();

  // (func is-float)
  vx_type::Func_is_float vx_e_is_float() {
    vx_type::Func_is_float output = new vx_type::Class_is_float();
    vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_type::Func_is_float vx_t_is_float() {
    vx_type::Func_is_float output = new vx_type::Class_is_float();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_type::Func_is_float e_is_float = vx_e_is_float();
  vx_type::Func_is_float t_is_float = vx_t_is_float();

  // (func is-none)
  vx_type::Func_is_none vx_e_is_none() {
    vx_type::Func_is_none output = new vx_type::Class_is_none();
    vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_type::Func_is_none vx_t_is_none() {
    vx_type::Func_is_none output = new vx_type::Class_is_none();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_type::Func_is_none e_is_none = vx_e_is_none();
  vx_type::Func_is_none t_is_none = vx_t_is_none();

  // (func is-string)
  vx_type::Func_is_string vx_e_is_string() {
    vx_type::Func_is_string output = new vx_type::Class_is_string();
    vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_type::Func_is_string vx_t_is_string() {
    vx_type::Func_is_string output = new vx_type::Class_is_string();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_type::Func_is_string e_is_string = vx_e_is_string();
  vx_type::Func_is_string t_is_string = vx_t_is_string();

  // (func is-type)
  vx_type::Func_is_type vx_e_is_type() {
    vx_type::Func_is_type output = new vx_type::Class_is_type();
    vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_type::Func_is_type vx_t_is_type() {
    vx_type::Func_is_type output = new vx_type::Class_is_type();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_type::Func_is_type e_is_type = vx_e_is_type();
  vx_type::Func_is_type t_is_type = vx_t_is_type();

  // (func is-type<-any-typelist)
  vx_type::Func_is_type_from_any_typelist vx_e_is_type_from_any_typelist() {
    vx_type::Func_is_type_from_any_typelist output = new vx_type::Class_is_type_from_any_typelist();
    vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_type::Func_is_type_from_any_typelist vx_t_is_type_from_any_typelist() {
    vx_type::Func_is_type_from_any_typelist output = new vx_type::Class_is_type_from_any_typelist();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_type::Func_is_type_from_any_typelist e_is_type_from_any_typelist = vx_e_is_type_from_any_typelist();
  vx_type::Func_is_type_from_any_typelist t_is_type_from_any_typelist = vx_t_is_type_from_any_typelist();

  // (func length<-string)
  vx_type::Func_length_from_string vx_e_length_from_string() {
    vx_type::Func_length_from_string output = new vx_type::Class_length_from_string();
    vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_type::Func_length_from_string vx_t_length_from_string() {
    vx_type::Func_length_from_string output = new vx_type::Class_length_from_string();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_type::Func_length_from_string e_length_from_string = vx_e_length_from_string();
  vx_type::Func_length_from_string t_length_from_string = vx_t_length_from_string();

  // (func string<-int)
  vx_type::Func_string_from_int vx_e_string_from_int() {
    vx_type::Func_string_from_int output = new vx_type::Class_string_from_int();
    vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_type::Func_string_from_int vx_t_string_from_int() {
    vx_type::Func_string_from_int output = new vx_type::Class_string_from_int();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_type::Func_string_from_int e_string_from_int = vx_e_string_from_int();
  vx_type::Func_string_from_int t_string_from_int = vx_t_string_from_int();

  // (func string<-string-end)
  vx_type::Func_string_from_string_end vx_e_string_from_string_end() {
    vx_type::Func_string_from_string_end output = new vx_type::Class_string_from_string_end();
    vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_type::Func_string_from_string_end vx_t_string_from_string_end() {
    vx_type::Func_string_from_string_end output = new vx_type::Class_string_from_string_end();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_type::Func_string_from_string_end e_string_from_string_end = vx_e_string_from_string_end();
  vx_type::Func_string_from_string_end t_string_from_string_end = vx_t_string_from_string_end();

  // (func string<-string-start)
  vx_type::Func_string_from_string_start vx_e_string_from_string_start() {
    vx_type::Func_string_from_string_start output = new vx_type::Class_string_from_string_start();
    vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_type::Func_string_from_string_start vx_t_string_from_string_start() {
    vx_type::Func_string_from_string_start output = new vx_type::Class_string_from_string_start();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_type::Func_string_from_string_start e_string_from_string_start = vx_e_string_from_string_start();
  vx_type::Func_string_from_string_start t_string_from_string_start = vx_t_string_from_string_start();

  // (func string<-string-start-end)
  vx_type::Func_string_from_string_start_end vx_e_string_from_string_start_end() {
    vx_type::Func_string_from_string_start_end output = new vx_type::Class_string_from_string_start_end();
    vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_type::Func_string_from_string_start_end vx_t_string_from_string_start_end() {
    vx_type::Func_string_from_string_start_end output = new vx_type::Class_string_from_string_start_end();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_type::Func_string_from_string_start_end e_string_from_string_start_end = vx_e_string_from_string_start_end();
  vx_type::Func_string_from_string_start_end t_string_from_string_start_end = vx_t_string_from_string_start_end();

  // (func string<-stringlist-join)
  vx_type::Func_string_from_stringlist_join vx_e_string_from_stringlist_join() {
    vx_type::Func_string_from_stringlist_join output = new vx_type::Class_string_from_stringlist_join();
    vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_type::Func_string_from_stringlist_join vx_t_string_from_stringlist_join() {
    vx_type::Func_string_from_stringlist_join output = new vx_type::Class_string_from_stringlist_join();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_type::Func_string_from_stringlist_join e_string_from_stringlist_join = vx_e_string_from_stringlist_join();
  vx_type::Func_string_from_stringlist_join t_string_from_stringlist_join = vx_t_string_from_stringlist_join();

  // (func traitnames<-any)
  vx_type::Func_traitnames_from_any vx_e_traitnames_from_any() {
    vx_type::Func_traitnames_from_any output = new vx_type::Class_traitnames_from_any();
    vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_type::Func_traitnames_from_any vx_t_traitnames_from_any() {
    vx_type::Func_traitnames_from_any output = new vx_type::Class_traitnames_from_any();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_type::Func_traitnames_from_any e_traitnames_from_any = vx_e_traitnames_from_any();
  vx_type::Func_traitnames_from_any t_traitnames_from_any = vx_t_traitnames_from_any();

  // (func traits<-any)
  vx_type::Func_traits_from_any vx_e_traits_from_any() {
    vx_type::Func_traits_from_any output = new vx_type::Class_traits_from_any();
    vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_type::Func_traits_from_any vx_t_traits_from_any() {
    vx_type::Func_traits_from_any output = new vx_type::Class_traits_from_any();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_type::Func_traits_from_any e_traits_from_any = vx_e_traits_from_any();
  vx_type::Func_traits_from_any t_traits_from_any = vx_t_traits_from_any();

  // (func traits<-typedef)
  vx_type::Func_traits_from_typedef vx_e_traits_from_typedef() {
    vx_type::Func_traits_from_typedef output = new vx_type::Class_traits_from_typedef();
    vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_type::Func_traits_from_typedef vx_t_traits_from_typedef() {
    vx_type::Func_traits_from_typedef output = new vx_type::Class_traits_from_typedef();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_type::Func_traits_from_typedef e_traits_from_typedef = vx_e_traits_from_typedef();
  vx_type::Func_traits_from_typedef t_traits_from_typedef = vx_t_traits_from_typedef();

}
