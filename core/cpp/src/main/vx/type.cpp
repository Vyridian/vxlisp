#include <memory>
#include "../vx/core.hpp"
#include "vx/type.hpp"

//namespace vx_type {
  /**
   * @function allowtypenames_from_type
   * Get the name of a given type
   * @param  {any} type
   * @return {stringlist}
   * (func allowtypenames<-type)
   */
  //class Func_allowtypenames_from_type {

    template <class T> std::shared_ptr<T> vx_type::Class_allowtypenames_from_type::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_allowtypenames_from_type output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_type::Class_allowtypenames_from_type::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_allowtypenames_from_type output;
      return output;
    }

    vx_core::Type_typedef vx_type::Class_allowtypenames_from_type::vx_typedef() {return vx_type::t_allowtypenames_from_type->vx_typedef();}

    vx_core::Type_funcdef vx_type::Class_allowtypenames_from_type::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "allowtypenames<-type", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "stringlist", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_string}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_type::Class_allowtypenames_from_type::vx_empty(std::shared_ptr<T> val) {return vx_type::e_allowtypenames_from_type;}
    template <class T> std::shared_ptr<T> vx_type::Class_allowtypenames_from_type::vx_type(std::shared_ptr<T> val) {return vx_type::t_allowtypenames_from_type;}

    vx_core::Func_any_from_any vx_type::Class_allowtypenames_from_type::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_type::Class_allowtypenames_from_type::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_type::f_allowtypenames_from_type(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_type::Class_allowtypenames_from_type::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any type = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_type::f_allowtypenames_from_type(type);
      return output;
    }

    vx_core::Type_stringlist vx_type::Class_allowtypenames_from_type::vx_f_allowtypenames_from_type(vx_core::Type_any type) {
      return vx_type::f_allowtypenames_from_type(type);
    }

  //}

  vx_type::Func_allowtypenames_from_type vx_type::e_allowtypenames_from_type = std::make_shared<vx_type::Class_allowtypenames_from_type>();
  vx_type::Func_allowtypenames_from_type vx_type::t_allowtypenames_from_type = std::make_shared<vx_type::Class_allowtypenames_from_type>();

  vx_core::Type_stringlist vx_type::f_allowtypenames_from_type(vx_core::Type_any type) {
    vx_core::Type_stringlist output = vx_core::e_stringlist;
    output = vx_core::f_typenames_from_typelist(
      vx_type::f_allowtypes_from_type(type)
    );
    return output;
  }

  /**
   * @function allowtypes_from_type
   * Get the name of a given type
   * @param  {any} type
   * @return {typelist}
   * (func allowtypes<-type)
   */
  //class Func_allowtypes_from_type {

    template <class T> std::shared_ptr<T> vx_type::Class_allowtypes_from_type::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_allowtypes_from_type output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_type::Class_allowtypes_from_type::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_allowtypes_from_type output;
      return output;
    }

    vx_core::Type_typedef vx_type::Class_allowtypes_from_type::vx_typedef() {return vx_type::t_allowtypes_from_type->vx_typedef();}

    vx_core::Type_funcdef vx_type::Class_allowtypes_from_type::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "allowtypes<-type", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "typelist", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_any}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_type::Class_allowtypes_from_type::vx_empty(std::shared_ptr<T> val) {return vx_type::e_allowtypes_from_type;}
    template <class T> std::shared_ptr<T> vx_type::Class_allowtypes_from_type::vx_type(std::shared_ptr<T> val) {return vx_type::t_allowtypes_from_type;}

    vx_core::Func_any_from_any vx_type::Class_allowtypes_from_type::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_type::Class_allowtypes_from_type::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_type::f_allowtypes_from_type(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_type::Class_allowtypes_from_type::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any type = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_type::f_allowtypes_from_type(type);
      return output;
    }

    vx_core::Type_typelist vx_type::Class_allowtypes_from_type::vx_f_allowtypes_from_type(vx_core::Type_any type) {
      return vx_type::f_allowtypes_from_type(type);
    }

  //}

  vx_type::Func_allowtypes_from_type vx_type::e_allowtypes_from_type = std::make_shared<vx_type::Class_allowtypes_from_type>();
  vx_type::Func_allowtypes_from_type vx_type::t_allowtypes_from_type = std::make_shared<vx_type::Class_allowtypes_from_type>();

  vx_core::Type_typelist vx_type::f_allowtypes_from_type(vx_core::Type_any type) {
    vx_core::Type_typelist output = vx_core::e_typelist;
    output = vx_core::f_typedef_from_type(type)->allowtypes();
    return output;
  }

  /**
   * @function is_boolean
   * @param  {any} value
   * @return {boolean}
   * (func is-boolean)
   */
  //class Func_is_boolean {

    template <class T> std::shared_ptr<T> vx_type::Class_is_boolean::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_is_boolean output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_type::Class_is_boolean::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_is_boolean output;
      return output;
    }

    vx_core::Type_typedef vx_type::Class_is_boolean::vx_typedef() {return vx_type::t_is_boolean->vx_typedef();}

    vx_core::Type_funcdef vx_type::Class_is_boolean::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "is-boolean", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_type::Class_is_boolean::vx_empty(std::shared_ptr<T> val) {return vx_type::e_is_boolean;}
    template <class T> std::shared_ptr<T> vx_type::Class_is_boolean::vx_type(std::shared_ptr<T> val) {return vx_type::t_is_boolean;}

    vx_core::Func_any_from_any vx_type::Class_is_boolean::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_type::Class_is_boolean::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_type::f_is_boolean(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_type::Class_is_boolean::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any value = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_type::f_is_boolean(value);
      return output;
    }

    vx_core::Type_boolean vx_type::Class_is_boolean::vx_f_is_boolean(vx_core::Type_any value) {
      return vx_type::f_is_boolean(value);
    }

  //}

  vx_type::Func_is_boolean vx_type::e_is_boolean = std::make_shared<vx_type::Class_is_boolean>();
  vx_type::Func_is_boolean vx_type::t_is_boolean = std::make_shared<vx_type::Class_is_boolean>();

  vx_core::Type_boolean vx_type::f_is_boolean(vx_core::Type_any value) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_core::f_eq(
      vx_core::t_string->vx_new_from_string("boolean"),
      vx_core::f_typename_from_any(value)
    );
    return output;
  }

  /**
   * @function is_decimal
   * @param  {any} value
   * @return {boolean}
   * (func is-decimal)
   */
  //class Func_is_decimal {

    template <class T> std::shared_ptr<T> vx_type::Class_is_decimal::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_is_decimal output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_type::Class_is_decimal::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_is_decimal output;
      return output;
    }

    vx_core::Type_typedef vx_type::Class_is_decimal::vx_typedef() {return vx_type::t_is_decimal->vx_typedef();}

    vx_core::Type_funcdef vx_type::Class_is_decimal::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "is-decimal", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_type::Class_is_decimal::vx_empty(std::shared_ptr<T> val) {return vx_type::e_is_decimal;}
    template <class T> std::shared_ptr<T> vx_type::Class_is_decimal::vx_type(std::shared_ptr<T> val) {return vx_type::t_is_decimal;}

    vx_core::Func_any_from_any vx_type::Class_is_decimal::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_type::Class_is_decimal::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_type::f_is_decimal(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_type::Class_is_decimal::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any value = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_type::f_is_decimal(value);
      return output;
    }

    vx_core::Type_boolean vx_type::Class_is_decimal::vx_f_is_decimal(vx_core::Type_any value) {
      return vx_type::f_is_decimal(value);
    }

  //}

  vx_type::Func_is_decimal vx_type::e_is_decimal = std::make_shared<vx_type::Class_is_decimal>();
  vx_type::Func_is_decimal vx_type::t_is_decimal = std::make_shared<vx_type::Class_is_decimal>();

  vx_core::Type_boolean vx_type::f_is_decimal(vx_core::Type_any value) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_core::f_eq(
      vx_core::t_string->vx_new_from_string("decimal"),
      vx_core::f_typename_from_any(value)
    );
    return output;
  }

  /**
   * @function is_float
   * @param  {any} value
   * @return {boolean}
   * (func is-float)
   */
  //class Func_is_float {

    template <class T> std::shared_ptr<T> vx_type::Class_is_float::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_is_float output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_type::Class_is_float::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_is_float output;
      return output;
    }

    vx_core::Type_typedef vx_type::Class_is_float::vx_typedef() {return vx_type::t_is_float->vx_typedef();}

    vx_core::Type_funcdef vx_type::Class_is_float::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "is-float", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_type::Class_is_float::vx_empty(std::shared_ptr<T> val) {return vx_type::e_is_float;}
    template <class T> std::shared_ptr<T> vx_type::Class_is_float::vx_type(std::shared_ptr<T> val) {return vx_type::t_is_float;}

    vx_core::Func_any_from_any vx_type::Class_is_float::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_type::Class_is_float::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_type::f_is_float(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_type::Class_is_float::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any value = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_type::f_is_float(value);
      return output;
    }

    vx_core::Type_boolean vx_type::Class_is_float::vx_f_is_float(vx_core::Type_any value) {
      return vx_type::f_is_float(value);
    }

  //}

  vx_type::Func_is_float vx_type::e_is_float = std::make_shared<vx_type::Class_is_float>();
  vx_type::Func_is_float vx_type::t_is_float = std::make_shared<vx_type::Class_is_float>();

  vx_core::Type_boolean vx_type::f_is_float(vx_core::Type_any value) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_core::f_eq(
      vx_core::t_string->vx_new_from_string("float"),
      vx_core::f_typename_from_any(value)
    );
    return output;
  }

  /**
   * @function is_none
   * @param  {any} value
   * @return {boolean}
   * (func is-none)
   */
  //class Func_is_none {

    template <class T> std::shared_ptr<T> vx_type::Class_is_none::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_is_none output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_type::Class_is_none::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_is_none output;
      return output;
    }

    vx_core::Type_typedef vx_type::Class_is_none::vx_typedef() {return vx_type::t_is_none->vx_typedef();}

    vx_core::Type_funcdef vx_type::Class_is_none::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "is-none", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_type::Class_is_none::vx_empty(std::shared_ptr<T> val) {return vx_type::e_is_none;}
    template <class T> std::shared_ptr<T> vx_type::Class_is_none::vx_type(std::shared_ptr<T> val) {return vx_type::t_is_none;}

    vx_core::Func_any_from_any vx_type::Class_is_none::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_type::Class_is_none::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_type::f_is_none(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_type::Class_is_none::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any value = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_type::f_is_none(value);
      return output;
    }

    vx_core::Type_boolean vx_type::Class_is_none::vx_f_is_none(vx_core::Type_any value) {
      return vx_type::f_is_none(value);
    }

  //}

  vx_type::Func_is_none vx_type::e_is_none = std::make_shared<vx_type::Class_is_none>();
  vx_type::Func_is_none vx_type::t_is_none = std::make_shared<vx_type::Class_is_none>();

  vx_core::Type_boolean vx_type::f_is_none(vx_core::Type_any value) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_core::f_eq(
      value,
      vx_core::t_none
    );
    return output;
  }

  /**
   * @function is_string
   * @param  {any} value
   * @return {boolean}
   * (func is-string)
   */
  //class Func_is_string {

    template <class T> std::shared_ptr<T> vx_type::Class_is_string::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_is_string output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_type::Class_is_string::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_is_string output;
      return output;
    }

    vx_core::Type_typedef vx_type::Class_is_string::vx_typedef() {return vx_type::t_is_string->vx_typedef();}

    vx_core::Type_funcdef vx_type::Class_is_string::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "is-string", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_type::Class_is_string::vx_empty(std::shared_ptr<T> val) {return vx_type::e_is_string;}
    template <class T> std::shared_ptr<T> vx_type::Class_is_string::vx_type(std::shared_ptr<T> val) {return vx_type::t_is_string;}

    vx_core::Func_any_from_any vx_type::Class_is_string::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_type::Class_is_string::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_type::f_is_string(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_type::Class_is_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any value = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_type::f_is_string(value);
      return output;
    }

    vx_core::Type_boolean vx_type::Class_is_string::vx_f_is_string(vx_core::Type_any value) {
      return vx_type::f_is_string(value);
    }

  //}

  vx_type::Func_is_string vx_type::e_is_string = std::make_shared<vx_type::Class_is_string>();
  vx_type::Func_is_string vx_type::t_is_string = std::make_shared<vx_type::Class_is_string>();

  vx_core::Type_boolean vx_type::f_is_string(vx_core::Type_any value) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_core::f_eq(
      vx_core::t_string->vx_new_from_string("vx/core/string"),
      vx_core::f_typename_from_any(value)
    );
    return output;
  }

  /**
   * @function is_type
   * @param  {any} val
   * @param  {any} type
   * @return {boolean}
   * (func is-type)
   */
  //class Func_is_type {

    template <class T> std::shared_ptr<T> vx_type::Class_is_type::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_is_type output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_type::Class_is_type::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_is_type output;
      return output;
    }

    vx_core::Type_typedef vx_type::Class_is_type::vx_typedef() {return vx_type::t_is_type->vx_typedef();}

    vx_core::Type_funcdef vx_type::Class_is_type::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "is-type", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_type::Class_is_type::vx_empty(std::shared_ptr<T> val) {return vx_type::e_is_type;}
    template <class T> std::shared_ptr<T> vx_type::Class_is_type::vx_type(std::shared_ptr<T> val) {return vx_type::t_is_type;}

    vx_core::Type_any vx_type::Class_is_type::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any val = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any type = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_type::f_is_type(val, type);
      return output;
    }

    vx_core::Type_boolean vx_type::Class_is_type::vx_f_is_type(vx_core::Type_any val, vx_core::Type_any type) {
      return vx_type::f_is_type(val, type);
    }

  //}

  vx_type::Func_is_type vx_type::e_is_type = std::make_shared<vx_type::Class_is_type>();
  vx_type::Func_is_type vx_type::t_is_type = std::make_shared<vx_type::Class_is_type>();

  vx_core::Type_boolean vx_type::f_is_type(vx_core::Type_any val, vx_core::Type_any type) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_core::f_or_1(
      vx_core::t_booleanlist->vx_new(vx_core::t_booleanlist, {
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
    return output;
  }

  /**
   * @function is_type_from_any_typelist
   * Returns true if val is any type in typelist.
   * @param  {any} val
   * @param  {typelist} typelist
   * @return {boolean}
   * (func is-type<-any-typelist)
   */
  //class Func_is_type_from_any_typelist {

    template <class T> std::shared_ptr<T> vx_type::Class_is_type_from_any_typelist::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_is_type_from_any_typelist output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_type::Class_is_type_from_any_typelist::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_is_type_from_any_typelist output;
      return output;
    }

    vx_core::Type_typedef vx_type::Class_is_type_from_any_typelist::vx_typedef() {return vx_type::t_is_type_from_any_typelist->vx_typedef();}

    vx_core::Type_funcdef vx_type::Class_is_type_from_any_typelist::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "is-type<-any-typelist", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_type::Class_is_type_from_any_typelist::vx_empty(std::shared_ptr<T> val) {return vx_type::e_is_type_from_any_typelist;}
    template <class T> std::shared_ptr<T> vx_type::Class_is_type_from_any_typelist::vx_type(std::shared_ptr<T> val) {return vx_type::t_is_type_from_any_typelist;}

    vx_core::Type_any vx_type::Class_is_type_from_any_typelist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any val = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_typelist typelist = vx_core::f_any_from_any(vx_core::t_typelist, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_type::f_is_type_from_any_typelist(val, typelist);
      return output;
    }

    vx_core::Type_boolean vx_type::Class_is_type_from_any_typelist::vx_f_is_type_from_any_typelist(vx_core::Type_any val, vx_core::Type_typelist typelist) {
      return vx_type::f_is_type_from_any_typelist(val, typelist);
    }

  //}

  vx_type::Func_is_type_from_any_typelist vx_type::e_is_type_from_any_typelist = std::make_shared<vx_type::Class_is_type_from_any_typelist>();
  vx_type::Func_is_type_from_any_typelist vx_type::t_is_type_from_any_typelist = std::make_shared<vx_type::Class_is_type_from_any_typelist>();

  vx_core::Type_boolean vx_type::f_is_type_from_any_typelist(vx_core::Type_any val, vx_core::Type_typelist typelist) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_core::f_any_from_list_reduce(
      vx_core::t_boolean,
      typelist,
      vx_core::t_boolean->vx_new_from_boolean(false),
      vx_core::t_any_from_reduce->fn_new([val](vx_core::Type_any result_any, vx_core::Type_any type_any) {
        vx_core::Type_boolean result = vx_core::f_any_from_any(vx_core::t_boolean, result_any);
        vx_core::Type_any type = vx_core::f_any_from_any(vx_core::t_any, type_any);
        return 
          vx_core::f_or(
            result,
            vx_type::f_is_type(val, type)
          );
      })
    );
    return output;
  }

  /**
   * @function length_from_string
   * Returns length of a string.
   * @param  {string} text
   * @return {int}
   * (func length<-string)
   */
  //class Func_length_from_string {

    template <class T> std::shared_ptr<T> vx_type::Class_length_from_string::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_length_from_string output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_type::Class_length_from_string::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_length_from_string output;
      return output;
    }

    vx_core::Type_typedef vx_type::Class_length_from_string::vx_typedef() {return vx_type::t_length_from_string->vx_typedef();}

    vx_core::Type_funcdef vx_type::Class_length_from_string::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "length<-string", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_type::Class_length_from_string::vx_empty(std::shared_ptr<T> val) {return vx_type::e_length_from_string;}
    template <class T> std::shared_ptr<T> vx_type::Class_length_from_string::vx_type(std::shared_ptr<T> val) {return vx_type::t_length_from_string;}

    vx_core::Func_any_from_any vx_type::Class_length_from_string::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_type::Class_length_from_string::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_string inputval = (vx_core::Type_string)value;
      vx_core::Type_any outputval = vx_type::f_length_from_string(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_type::Class_length_from_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_type::f_length_from_string(text);
      return output;
    }

    vx_core::Type_int vx_type::Class_length_from_string::vx_f_length_from_string(vx_core::Type_string text) {
      return vx_type::f_length_from_string(text);
    }

  //}

  vx_type::Func_length_from_string vx_type::e_length_from_string = std::make_shared<vx_type::Class_length_from_string>();
  vx_type::Func_length_from_string vx_type::t_length_from_string = std::make_shared<vx_type::Class_length_from_string>();

  vx_core::Type_int vx_type::f_length_from_string(vx_core::Type_string text) {
    vx_core::Type_int output = vx_core::e_int;
    return output;
  }

  /**
   * @function string_from_int
   * Function Type converting int to string
   * @param  {int} val
   * @return {string}
   * (func string<-int)
   */
  //class Func_string_from_int {

    template <class T> std::shared_ptr<T> vx_type::Class_string_from_int::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_string_from_int output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_type::Class_string_from_int::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_string_from_int output;
      return output;
    }

    vx_core::Type_typedef vx_type::Class_string_from_int::vx_typedef() {return vx_type::t_string_from_int->vx_typedef();}

    vx_core::Type_funcdef vx_type::Class_string_from_int::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "string<-int", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_type::Class_string_from_int::vx_empty(std::shared_ptr<T> val) {return vx_type::e_string_from_int;}
    template <class T> std::shared_ptr<T> vx_type::Class_string_from_int::vx_type(std::shared_ptr<T> val) {return vx_type::t_string_from_int;}

    vx_core::Func_any_from_any vx_type::Class_string_from_int::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_type::Class_string_from_int::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_int inputval = (vx_core::Type_int)value;
      vx_core::Type_any outputval = vx_type::f_string_from_int(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_type::Class_string_from_int::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_int val = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_type::f_string_from_int(val);
      return output;
    }

    vx_core::Type_string vx_type::Class_string_from_int::vx_f_string_from_int(vx_core::Type_int val) {
      return vx_type::f_string_from_int(val);
    }

  //}

  vx_type::Func_string_from_int vx_type::e_string_from_int = std::make_shared<vx_type::Class_string_from_int>();
  vx_type::Func_string_from_int vx_type::t_string_from_int = std::make_shared<vx_type::Class_string_from_int>();

  vx_core::Type_string vx_type::f_string_from_int(vx_core::Type_int val) {
    vx_core::Type_string output = vx_core::e_string;
    output = vx_core::f_switch(
      vx_core::t_string,
      val,
      vx_core::t_thenelselist->vx_new(vx_core::t_thenelselist, {
        vx_core::f_case_1(
          vx_core::c_infinity,
          vx_core::t_any_from_func->fn_new([]() {
            return vx_core::t_string->vx_new_from_string("infinity");
          })
        ),
        vx_core::f_case_1(
          vx_core::c_neginfinity,
          vx_core::t_any_from_func->fn_new([]() {
            return vx_core::t_string->vx_new_from_string("neginfinity");
          })
        ),
        vx_core::f_case_1(
          vx_core::c_notanumber,
          vx_core::t_any_from_func->fn_new([]() {
            return vx_core::t_string->vx_new_from_string("notanumber");
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func->fn_new([val]() {
            return vx_core::f_new(
              vx_core::t_string,
              vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                val
              })
            );
          })
        )
      })
    );
    return output;
  }

  /**
   * @function string_from_string_end
   * Returns a substring between 0 end position.
   * @param  {string} text
   * @param  {int} endpos
   * @return {string}
   * (func string<-string-end)
   */
  //class Func_string_from_string_end {

    template <class T> std::shared_ptr<T> vx_type::Class_string_from_string_end::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_string_from_string_end output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_type::Class_string_from_string_end::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_string_from_string_end output;
      return output;
    }

    vx_core::Type_typedef vx_type::Class_string_from_string_end::vx_typedef() {return vx_type::t_string_from_string_end->vx_typedef();}

    vx_core::Type_funcdef vx_type::Class_string_from_string_end::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "string<-string-end", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_type::Class_string_from_string_end::vx_empty(std::shared_ptr<T> val) {return vx_type::e_string_from_string_end;}
    template <class T> std::shared_ptr<T> vx_type::Class_string_from_string_end::vx_type(std::shared_ptr<T> val) {return vx_type::t_string_from_string_end;}

    vx_core::Type_any vx_type::Class_string_from_string_end::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int endpos = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_type::f_string_from_string_end(text, endpos);
      return output;
    }

    vx_core::Type_string vx_type::Class_string_from_string_end::vx_f_string_from_string_end(vx_core::Type_string text, vx_core::Type_int endpos) {
      return vx_type::f_string_from_string_end(text, endpos);
    }

  //}

  vx_type::Func_string_from_string_end vx_type::e_string_from_string_end = std::make_shared<vx_type::Class_string_from_string_end>();
  vx_type::Func_string_from_string_end vx_type::t_string_from_string_end = std::make_shared<vx_type::Class_string_from_string_end>();

  vx_core::Type_string vx_type::f_string_from_string_end(vx_core::Type_string text, vx_core::Type_int endpos) {
    vx_core::Type_string output = vx_core::e_string;
    output = vx_type::f_string_from_string_start_end(text, vx_core::t_int->vx_new_from_int(0), endpos);
    return output;
  }

  /**
   * @function string_from_string_start
   * Returns a substring between start string end.
   * @param  {string} text
   * @param  {int} startpos
   * @return {string}
   * (func string<-string-start)
   */
  //class Func_string_from_string_start {

    template <class T> std::shared_ptr<T> vx_type::Class_string_from_string_start::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_string_from_string_start output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_type::Class_string_from_string_start::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_string_from_string_start output;
      return output;
    }

    vx_core::Type_typedef vx_type::Class_string_from_string_start::vx_typedef() {return vx_type::t_string_from_string_start->vx_typedef();}

    vx_core::Type_funcdef vx_type::Class_string_from_string_start::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "string<-string-start", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_type::Class_string_from_string_start::vx_empty(std::shared_ptr<T> val) {return vx_type::e_string_from_string_start;}
    template <class T> std::shared_ptr<T> vx_type::Class_string_from_string_start::vx_type(std::shared_ptr<T> val) {return vx_type::t_string_from_string_start;}

    vx_core::Type_any vx_type::Class_string_from_string_start::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int startpos = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_type::f_string_from_string_start(text, startpos);
      return output;
    }

    vx_core::Type_string vx_type::Class_string_from_string_start::vx_f_string_from_string_start(vx_core::Type_string text, vx_core::Type_int startpos) {
      return vx_type::f_string_from_string_start(text, startpos);
    }

  //}

  vx_type::Func_string_from_string_start vx_type::e_string_from_string_start = std::make_shared<vx_type::Class_string_from_string_start>();
  vx_type::Func_string_from_string_start vx_type::t_string_from_string_start = std::make_shared<vx_type::Class_string_from_string_start>();

  vx_core::Type_string vx_type::f_string_from_string_start(vx_core::Type_string text, vx_core::Type_int startpos) {
    vx_core::Type_string output = vx_core::e_string;
    output = vx_type::f_string_from_string_start_end(
      text,
      startpos,
      vx_type::f_length_from_string(text)
    );
    return output;
  }

  /**
   * @function string_from_string_start_end
   * Returns a substring between start and end positions.
   * @param  {string} text
   * @param  {int} start
   * @param  {int} end
   * @return {string}
   * (func string<-string-start-end)
   */
  //class Func_string_from_string_start_end {

    template <class T> std::shared_ptr<T> vx_type::Class_string_from_string_start_end::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_string_from_string_start_end output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_type::Class_string_from_string_start_end::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_string_from_string_start_end output;
      return output;
    }

    vx_core::Type_typedef vx_type::Class_string_from_string_start_end::vx_typedef() {return vx_type::t_string_from_string_start_end->vx_typedef();}

    vx_core::Type_funcdef vx_type::Class_string_from_string_start_end::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "string<-string-start-end", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_type::Class_string_from_string_start_end::vx_empty(std::shared_ptr<T> val) {return vx_type::e_string_from_string_start_end;}
    template <class T> std::shared_ptr<T> vx_type::Class_string_from_string_start_end::vx_type(std::shared_ptr<T> val) {return vx_type::t_string_from_string_start_end;}

    vx_core::Type_any vx_type::Class_string_from_string_start_end::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int start = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(1)));
      vx_core::Type_int end = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(2)));
      output = vx_type::f_string_from_string_start_end(text, start, end);
      return output;
    }

    vx_core::Type_string vx_type::Class_string_from_string_start_end::vx_f_string_from_string_start_end(vx_core::Type_string text, vx_core::Type_int start, vx_core::Type_int end) {
      return vx_type::f_string_from_string_start_end(text, start, end);
    }

  //}

  vx_type::Func_string_from_string_start_end vx_type::e_string_from_string_start_end = std::make_shared<vx_type::Class_string_from_string_start_end>();
  vx_type::Func_string_from_string_start_end vx_type::t_string_from_string_start_end = std::make_shared<vx_type::Class_string_from_string_start_end>();

  vx_core::Type_string vx_type::f_string_from_string_start_end(vx_core::Type_string text, vx_core::Type_int start, vx_core::Type_int end) {
    vx_core::Type_string output = vx_core::e_string;
    return output;
  }

  /**
   * @function string_from_stringlist_join
   * @param  {stringlist} vals
   * @param  {string} delim
   * @return {string}
   * (func string<-stringlist-join)
   */
  //class Func_string_from_stringlist_join {

    template <class T> std::shared_ptr<T> vx_type::Class_string_from_stringlist_join::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_string_from_stringlist_join output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_type::Class_string_from_stringlist_join::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_string_from_stringlist_join output;
      return output;
    }

    vx_core::Type_typedef vx_type::Class_string_from_stringlist_join::vx_typedef() {return vx_type::t_string_from_stringlist_join->vx_typedef();}

    vx_core::Type_funcdef vx_type::Class_string_from_stringlist_join::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "string<-stringlist-join", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_type::Class_string_from_stringlist_join::vx_empty(std::shared_ptr<T> val) {return vx_type::e_string_from_stringlist_join;}
    template <class T> std::shared_ptr<T> vx_type::Class_string_from_stringlist_join::vx_type(std::shared_ptr<T> val) {return vx_type::t_string_from_stringlist_join;}

    vx_core::Type_any vx_type::Class_string_from_stringlist_join::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_stringlist vals = vx_core::f_any_from_any(vx_core::t_stringlist, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_string delim = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_type::f_string_from_stringlist_join(vals, delim);
      return output;
    }

    vx_core::Type_string vx_type::Class_string_from_stringlist_join::vx_f_string_from_stringlist_join(vx_core::Type_stringlist vals, vx_core::Type_string delim) {
      return vx_type::f_string_from_stringlist_join(vals, delim);
    }

  //}

  vx_type::Func_string_from_stringlist_join vx_type::e_string_from_stringlist_join = std::make_shared<vx_type::Class_string_from_stringlist_join>();
  vx_type::Func_string_from_stringlist_join vx_type::t_string_from_stringlist_join = std::make_shared<vx_type::Class_string_from_stringlist_join>();

  vx_core::Type_string vx_type::f_string_from_stringlist_join(vx_core::Type_stringlist vals, vx_core::Type_string delim) {
    vx_core::Type_string output = vx_core::e_string;
    return output;
  }

  /**
   * @function traitnames_from_any
   * Get the trait names of a given type
   * @param  {any} val
   * @return {stringlist}
   * (func traitnames<-any)
   */
  //class Func_traitnames_from_any {

    template <class T> std::shared_ptr<T> vx_type::Class_traitnames_from_any::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_traitnames_from_any output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_type::Class_traitnames_from_any::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_traitnames_from_any output;
      return output;
    }

    vx_core::Type_typedef vx_type::Class_traitnames_from_any::vx_typedef() {return vx_type::t_traitnames_from_any->vx_typedef();}

    vx_core::Type_funcdef vx_type::Class_traitnames_from_any::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "traitnames<-any", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "stringlist", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_string}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_type::Class_traitnames_from_any::vx_empty(std::shared_ptr<T> val) {return vx_type::e_traitnames_from_any;}
    template <class T> std::shared_ptr<T> vx_type::Class_traitnames_from_any::vx_type(std::shared_ptr<T> val) {return vx_type::t_traitnames_from_any;}

    vx_core::Func_any_from_any vx_type::Class_traitnames_from_any::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_type::Class_traitnames_from_any::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_type::f_traitnames_from_any(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_type::Class_traitnames_from_any::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any val = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_type::f_traitnames_from_any(val);
      return output;
    }

    vx_core::Type_stringlist vx_type::Class_traitnames_from_any::vx_f_traitnames_from_any(vx_core::Type_any val) {
      return vx_type::f_traitnames_from_any(val);
    }

  //}

  vx_type::Func_traitnames_from_any vx_type::e_traitnames_from_any = std::make_shared<vx_type::Class_traitnames_from_any>();
  vx_type::Func_traitnames_from_any vx_type::t_traitnames_from_any = std::make_shared<vx_type::Class_traitnames_from_any>();

  vx_core::Type_stringlist vx_type::f_traitnames_from_any(vx_core::Type_any val) {
    vx_core::Type_stringlist output = vx_core::e_stringlist;
    output = vx_core::f_typenames_from_typelist(
      vx_type::f_traits_from_any(val)
    );
    return output;
  }

  /**
   * @function traits_from_any
   * Get the traits of a given value
   * @param  {any} val
   * @return {typelist}
   * (func traits<-any)
   */
  //class Func_traits_from_any {

    template <class T> std::shared_ptr<T> vx_type::Class_traits_from_any::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_traits_from_any output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_type::Class_traits_from_any::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_traits_from_any output;
      return output;
    }

    vx_core::Type_typedef vx_type::Class_traits_from_any::vx_typedef() {return vx_type::t_traits_from_any->vx_typedef();}

    vx_core::Type_funcdef vx_type::Class_traits_from_any::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "traits<-any", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "typelist", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_any}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_type::Class_traits_from_any::vx_empty(std::shared_ptr<T> val) {return vx_type::e_traits_from_any;}
    template <class T> std::shared_ptr<T> vx_type::Class_traits_from_any::vx_type(std::shared_ptr<T> val) {return vx_type::t_traits_from_any;}

    vx_core::Func_any_from_any vx_type::Class_traits_from_any::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_type::Class_traits_from_any::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_type::f_traits_from_any(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_type::Class_traits_from_any::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any val = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_type::f_traits_from_any(val);
      return output;
    }

    vx_core::Type_typelist vx_type::Class_traits_from_any::vx_f_traits_from_any(vx_core::Type_any val) {
      return vx_type::f_traits_from_any(val);
    }

  //}

  vx_type::Func_traits_from_any vx_type::e_traits_from_any = std::make_shared<vx_type::Class_traits_from_any>();
  vx_type::Func_traits_from_any vx_type::t_traits_from_any = std::make_shared<vx_type::Class_traits_from_any>();

  vx_core::Type_typelist vx_type::f_traits_from_any(vx_core::Type_any val) {
    vx_core::Type_typelist output = vx_core::e_typelist;
    output = vx_core::f_traits_from_typedef(
      vx_core::f_typedef_from_any(val)
    );
    return output;
  }

  /**
   * @function traits_from_typedef
   * Get the traits of a given typedef
   * @param  {typedef} vtypedef
   * @return {typelist}
   * (func traits<-typedef)
   */
  //class Func_traits_from_typedef {

    template <class T> std::shared_ptr<T> vx_type::Class_traits_from_typedef::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_traits_from_typedef output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_type::Class_traits_from_typedef::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_type::Func_traits_from_typedef output;
      return output;
    }

    vx_core::Type_typedef vx_type::Class_traits_from_typedef::vx_typedef() {return vx_type::t_traits_from_typedef->vx_typedef();}

    vx_core::Type_funcdef vx_type::Class_traits_from_typedef::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/type", // pkgname
        "traits<-typedef", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "typelist", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_any}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_type::Class_traits_from_typedef::vx_empty(std::shared_ptr<T> val) {return vx_type::e_traits_from_typedef;}
    template <class T> std::shared_ptr<T> vx_type::Class_traits_from_typedef::vx_type(std::shared_ptr<T> val) {return vx_type::t_traits_from_typedef;}

    vx_core::Func_any_from_any vx_type::Class_traits_from_typedef::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_type::Class_traits_from_typedef::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_typedef inputval = (vx_core::Type_typedef)value;
      vx_core::Type_any outputval = vx_type::f_traits_from_typedef(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_type::Class_traits_from_typedef::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_typedef vtypedef = vx_core::f_any_from_any(vx_core::t_typedef, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_type::f_traits_from_typedef(vtypedef);
      return output;
    }

    vx_core::Type_typelist vx_type::Class_traits_from_typedef::vx_f_traits_from_typedef(vx_core::Type_typedef vtypedef) {
      return vx_type::f_traits_from_typedef(vtypedef);
    }

  //}

  vx_type::Func_traits_from_typedef vx_type::e_traits_from_typedef = std::make_shared<vx_type::Class_traits_from_typedef>();
  vx_type::Func_traits_from_typedef vx_type::t_traits_from_typedef = std::make_shared<vx_type::Class_traits_from_typedef>();

  vx_core::Type_typelist vx_type::f_traits_from_typedef(vx_core::Type_typedef vtypedef) {
    vx_core::Type_typelist output = vx_core::e_typelist;
    output = vtypedef->traits();
    return output;
  }


//}
