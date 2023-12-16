#include "../../vx/core.hpp"
#include "../../vx/web/html.hpp"
#include "htmldoc.hpp"

namespace vx_web_htmldoc {


  // (func boolean-write<-id-htmltext)
  vx_core::Type_boolean f_boolean_write_from_id_htmltext(vx_core::Type_string id, vx_core::Type_string htmltext) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve({id, htmltext});
    vx_core::vx_release_one_except({id, htmltext}, output);
    return output;
  }

  // (func boolean-write<-id-htmltext)
  // class Class_boolean_write_from_id_htmltext {
    Abstract_boolean_write_from_id_htmltext::~Abstract_boolean_write_from_id_htmltext() {}

    Class_boolean_write_from_id_htmltext::Class_boolean_write_from_id_htmltext() : Abstract_boolean_write_from_id_htmltext::Abstract_boolean_write_from_id_htmltext() {
      vx_core::refcount += 1;
    }

    Class_boolean_write_from_id_htmltext::~Class_boolean_write_from_id_htmltext() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_boolean_write_from_id_htmltext::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_boolean_write_from_id_htmltext output = vx_web_htmldoc::e_boolean_write_from_id_htmltext;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_boolean_write_from_id_htmltext::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_boolean_write_from_id_htmltext output = vx_web_htmldoc::e_boolean_write_from_id_htmltext;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_boolean_write_from_id_htmltext::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-write<-id-htmltext", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_boolean_write_from_id_htmltext::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_boolean_write_from_id_htmltext::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-write<-id-htmltext", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_boolean_write_from_id_htmltext::vx_empty() const {return vx_web_htmldoc::e_boolean_write_from_id_htmltext;}
    vx_core::Type_any Class_boolean_write_from_id_htmltext::vx_type() const {return vx_web_htmldoc::t_boolean_write_from_id_htmltext;}
    vx_core::Type_msgblock Class_boolean_write_from_id_htmltext::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_write_from_id_htmltext::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_boolean_write_from_id_htmltext::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string id = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string htmltext = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_htmldoc::f_boolean_write_from_id_htmltext(id, htmltext);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func boolean-write<-stylesheet)
  vx_core::vx_Type_async f_boolean_write_from_stylesheet(vx_web_html::Type_stylesheet stylesheet) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve(stylesheet);
    vx_core::vx_release_one(stylesheet);
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_core::e_boolean);
    }
    return output;
  }

  // (func boolean-write<-stylesheet)
  // class Class_boolean_write_from_stylesheet {
    Abstract_boolean_write_from_stylesheet::~Abstract_boolean_write_from_stylesheet() {}

    Class_boolean_write_from_stylesheet::Class_boolean_write_from_stylesheet() : Abstract_boolean_write_from_stylesheet::Abstract_boolean_write_from_stylesheet() {
      vx_core::refcount += 1;
    }

    Class_boolean_write_from_stylesheet::~Class_boolean_write_from_stylesheet() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_boolean_write_from_stylesheet::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_boolean_write_from_stylesheet output = vx_web_htmldoc::e_boolean_write_from_stylesheet;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_boolean_write_from_stylesheet::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_boolean_write_from_stylesheet output = vx_web_htmldoc::e_boolean_write_from_stylesheet;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_boolean_write_from_stylesheet::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-write<-stylesheet", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_boolean_write_from_stylesheet::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_boolean_write_from_stylesheet::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-write<-stylesheet", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_boolean_write_from_stylesheet::vx_empty() const {return vx_web_htmldoc::e_boolean_write_from_stylesheet;}
    vx_core::Type_any Class_boolean_write_from_stylesheet::vx_type() const {return vx_web_htmldoc::t_boolean_write_from_stylesheet;}
    vx_core::Type_msgblock Class_boolean_write_from_stylesheet::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_write_from_stylesheet::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_async Class_boolean_write_from_stylesheet::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const {
      return vx_core::e_any_from_any_async;
    }

    vx_core::vx_Type_async Class_boolean_write_from_stylesheet::vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const {
      vx_web_html::Type_stylesheet inputval = vx_core::vx_any_from_any(vx_web_html::t_stylesheet, val);
      vx_core::vx_Type_async output = vx_web_htmldoc::f_boolean_write_from_stylesheet(inputval);
      vx_core::vx_release(val);
      return output;
    }

    vx_core::vx_Type_async Class_boolean_write_from_stylesheet::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_value(vx_core::e_any);
      vx_web_html::Type_stylesheet stylesheet = vx_core::vx_any_from_any(vx_web_html::t_stylesheet, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_htmldoc::f_boolean_write_from_stylesheet(stylesheet);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  // (func string<-id)
  vx_core::Type_string f_string_from_id(vx_core::Type_string id) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve(id);
    vx_core::vx_release_one_except(id, output);
    return output;
  }

  // (func string<-id)
  // class Class_string_from_id {
    Abstract_string_from_id::~Abstract_string_from_id() {}

    Class_string_from_id::Class_string_from_id() : Abstract_string_from_id::Abstract_string_from_id() {
      vx_core::refcount += 1;
    }

    Class_string_from_id::~Class_string_from_id() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_id::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_string_from_id output = vx_web_htmldoc::e_string_from_id;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_id::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_string_from_id output = vx_web_htmldoc::e_string_from_id;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_id::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/htmldoc", // pkgname
        "string<-id", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_string_from_id::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_id::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/htmldoc", // pkgname
        "string<-id", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_id::vx_empty() const {return vx_web_htmldoc::e_string_from_id;}
    vx_core::Type_any Class_string_from_id::vx_type() const {return vx_web_htmldoc::t_string_from_id;}
    vx_core::Type_msgblock Class_string_from_id::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_id::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_string_from_id::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_string_from_id::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      output = vx_web_htmldoc::f_string_from_id(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_string_from_id::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string id = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_htmldoc::f_string_from_id(id);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_web_htmldoc::Func_boolean_write_from_id_htmltext e_boolean_write_from_id_htmltext = NULL;
  vx_web_htmldoc::Func_boolean_write_from_id_htmltext t_boolean_write_from_id_htmltext = NULL;
  vx_web_htmldoc::Func_boolean_write_from_stylesheet e_boolean_write_from_stylesheet = NULL;
  vx_web_htmldoc::Func_boolean_write_from_stylesheet t_boolean_write_from_stylesheet = NULL;
  vx_web_htmldoc::Func_string_from_id e_string_from_id = NULL;
  vx_web_htmldoc::Func_string_from_id t_string_from_id = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_web_htmldoc::e_boolean_write_from_id_htmltext = new vx_web_htmldoc::Class_boolean_write_from_id_htmltext();
      vx_core::vx_reserve_empty(vx_web_htmldoc::e_boolean_write_from_id_htmltext);
      vx_web_htmldoc::t_boolean_write_from_id_htmltext = new vx_web_htmldoc::Class_boolean_write_from_id_htmltext();
      vx_core::vx_reserve_type(vx_web_htmldoc::t_boolean_write_from_id_htmltext);
      vx_web_htmldoc::e_boolean_write_from_stylesheet = new vx_web_htmldoc::Class_boolean_write_from_stylesheet();
      vx_core::vx_reserve_empty(vx_web_htmldoc::e_boolean_write_from_stylesheet);
      vx_web_htmldoc::t_boolean_write_from_stylesheet = new vx_web_htmldoc::Class_boolean_write_from_stylesheet();
      vx_core::vx_reserve_type(vx_web_htmldoc::t_boolean_write_from_stylesheet);
      vx_web_htmldoc::e_string_from_id = new vx_web_htmldoc::Class_string_from_id();
      vx_core::vx_reserve_empty(vx_web_htmldoc::e_string_from_id);
      vx_web_htmldoc::t_string_from_id = new vx_web_htmldoc::Class_string_from_id();
      vx_core::vx_reserve_type(vx_web_htmldoc::t_string_from_id);
      vx_core::vx_Type_mapany maptype;
      vx_core::vx_Type_mapany mapconst;
      vx_core::vx_Type_mapfunc mapfunc;
      vx_core::vx_Type_mapany mapempty;
      mapfunc["boolean-write<-id-htmltext"] = vx_web_htmldoc::t_boolean_write_from_id_htmltext;
      mapfunc["boolean-write<-stylesheet"] = vx_web_htmldoc::t_boolean_write_from_stylesheet;
      mapfunc["string<-id"] = vx_web_htmldoc::t_string_from_id;
      vx_core::vx_global_package_set("vx/web/htmldoc", maptype, mapconst, mapfunc);
	   }
  // }

}
