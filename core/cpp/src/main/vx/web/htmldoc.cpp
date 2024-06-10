#include "../../vx/core.hpp"
#include "../../vx/event.hpp"
#include "../../vx/web/html.hpp"
#include "../../vx/ui/ui.hpp"
#include "htmldoc.hpp"

namespace vx_web_htmldoc {



  // (func boolean-print<-id-stylesheettext)
  vx_core::Type_boolean f_boolean_print_from_id_stylesheettext(vx_core::Type_string id, vx_core::Type_string stylesheettext) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve({id, stylesheettext});
    vx_core::vx_release_one_except({id, stylesheettext}, output);
    return output;
  }
  /**
   * @function boolean_print_from_id_stylesheettext
   * Print the contents of the given id.
   * @param  {string} id
   * @param  {string} stylesheettext
   * @return {boolean}
   * (func boolean-print<-id-stylesheettext)
   */
  // (func boolean-print<-id-stylesheettext)
  // class Class_boolean_print_from_id_stylesheettext {
    Abstract_boolean_print_from_id_stylesheettext::~Abstract_boolean_print_from_id_stylesheettext() {}

    Class_boolean_print_from_id_stylesheettext::Class_boolean_print_from_id_stylesheettext() : Abstract_boolean_print_from_id_stylesheettext::Abstract_boolean_print_from_id_stylesheettext() {
      vx_core::refcount += 1;
    }

    Class_boolean_print_from_id_stylesheettext::~Class_boolean_print_from_id_stylesheettext() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_boolean_print_from_id_stylesheettext::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_boolean_print_from_id_stylesheettext output = vx_web_htmldoc::e_boolean_print_from_id_stylesheettext;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_boolean_print_from_id_stylesheettext::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_boolean_print_from_id_stylesheettext output = vx_web_htmldoc::e_boolean_print_from_id_stylesheettext;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_boolean_print_from_id_stylesheettext::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-print<-id-stylesheettext", // name
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

    vx_core::Type_constdef Class_boolean_print_from_id_stylesheettext::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_boolean_print_from_id_stylesheettext::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-print<-id-stylesheettext", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_boolean_print_from_id_stylesheettext::vx_empty() const {return vx_web_htmldoc::e_boolean_print_from_id_stylesheettext;}
    vx_core::Type_any Class_boolean_print_from_id_stylesheettext::vx_type() const {return vx_web_htmldoc::t_boolean_print_from_id_stylesheettext;}
    vx_core::Type_msgblock Class_boolean_print_from_id_stylesheettext::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_print_from_id_stylesheettext::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_boolean_print_from_id_stylesheettext::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string id = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string stylesheettext = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_htmldoc::f_boolean_print_from_id_stylesheettext(id, stylesheettext);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func boolean-remove<-id)
  vx_core::Type_boolean f_boolean_remove_from_id(vx_core::Type_string id) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve(id);
    vx_core::vx_release_one_except(id, output);
    return output;
  }
  /**
   * @function boolean_remove_from_id
   * Removes an html node with given id.
   * @param  {string} id
   * @return {boolean}
   * (func boolean-remove<-id)
   */
  // (func boolean-remove<-id)
  // class Class_boolean_remove_from_id {
    Abstract_boolean_remove_from_id::~Abstract_boolean_remove_from_id() {}

    Class_boolean_remove_from_id::Class_boolean_remove_from_id() : Abstract_boolean_remove_from_id::Abstract_boolean_remove_from_id() {
      vx_core::refcount += 1;
    }

    Class_boolean_remove_from_id::~Class_boolean_remove_from_id() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_boolean_remove_from_id::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_boolean_remove_from_id output = vx_web_htmldoc::e_boolean_remove_from_id;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_boolean_remove_from_id::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_boolean_remove_from_id output = vx_web_htmldoc::e_boolean_remove_from_id;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_boolean_remove_from_id::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-remove<-id", // name
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

    vx_core::Type_constdef Class_boolean_remove_from_id::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_boolean_remove_from_id::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-remove<-id", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_boolean_remove_from_id::vx_empty() const {return vx_web_htmldoc::e_boolean_remove_from_id;}
    vx_core::Type_any Class_boolean_remove_from_id::vx_type() const {return vx_web_htmldoc::t_boolean_remove_from_id;}
    vx_core::Type_msgblock Class_boolean_remove_from_id::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_remove_from_id::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_boolean_remove_from_id::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_boolean_remove_from_id::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      output = vx_web_htmldoc::f_boolean_remove_from_id(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_boolean_remove_from_id::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string id = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_htmldoc::f_boolean_remove_from_id(id);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func boolean-replace<-id-htmltext)
  vx_core::Type_boolean f_boolean_replace_from_id_htmltext(vx_core::Type_string id, vx_core::Type_string htmltext) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve({id, htmltext});
    vx_core::vx_release_one_except({id, htmltext}, output);
    return output;
  }
  /**
   * @function boolean_replace_from_id_htmltext
   * Replaces an html node with given id and text.
   * @param  {string} id
   * @param  {string} htmltext
   * @return {boolean}
   * (func boolean-replace<-id-htmltext)
   */
  // (func boolean-replace<-id-htmltext)
  // class Class_boolean_replace_from_id_htmltext {
    Abstract_boolean_replace_from_id_htmltext::~Abstract_boolean_replace_from_id_htmltext() {}

    Class_boolean_replace_from_id_htmltext::Class_boolean_replace_from_id_htmltext() : Abstract_boolean_replace_from_id_htmltext::Abstract_boolean_replace_from_id_htmltext() {
      vx_core::refcount += 1;
    }

    Class_boolean_replace_from_id_htmltext::~Class_boolean_replace_from_id_htmltext() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_boolean_replace_from_id_htmltext::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_boolean_replace_from_id_htmltext output = vx_web_htmldoc::e_boolean_replace_from_id_htmltext;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_boolean_replace_from_id_htmltext::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_boolean_replace_from_id_htmltext output = vx_web_htmldoc::e_boolean_replace_from_id_htmltext;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_boolean_replace_from_id_htmltext::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-replace<-id-htmltext", // name
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

    vx_core::Type_constdef Class_boolean_replace_from_id_htmltext::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_boolean_replace_from_id_htmltext::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-replace<-id-htmltext", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_boolean_replace_from_id_htmltext::vx_empty() const {return vx_web_htmldoc::e_boolean_replace_from_id_htmltext;}
    vx_core::Type_any Class_boolean_replace_from_id_htmltext::vx_type() const {return vx_web_htmldoc::t_boolean_replace_from_id_htmltext;}
    vx_core::Type_msgblock Class_boolean_replace_from_id_htmltext::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_replace_from_id_htmltext::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_boolean_replace_from_id_htmltext::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string id = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string htmltext = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_htmldoc::f_boolean_replace_from_id_htmltext(id, htmltext);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func boolean-replace<-id-parent-htmltext)
  vx_core::Type_boolean f_boolean_replace_from_id_parent_htmltext(vx_core::Type_string id, vx_core::Type_string parent, vx_core::Type_string htmltext) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve({id, parent, htmltext});
    vx_core::vx_release_one_except({id, parent, htmltext}, output);
    return output;
  }
  /**
   * @function boolean_replace_from_id_parent_htmltext
   * Replaces an html node with given id, parentid, and text.
   * @param  {string} id
   * @param  {string} parent
   * @param  {string} htmltext
   * @return {boolean}
   * (func boolean-replace<-id-parent-htmltext)
   */
  // (func boolean-replace<-id-parent-htmltext)
  // class Class_boolean_replace_from_id_parent_htmltext {
    Abstract_boolean_replace_from_id_parent_htmltext::~Abstract_boolean_replace_from_id_parent_htmltext() {}

    Class_boolean_replace_from_id_parent_htmltext::Class_boolean_replace_from_id_parent_htmltext() : Abstract_boolean_replace_from_id_parent_htmltext::Abstract_boolean_replace_from_id_parent_htmltext() {
      vx_core::refcount += 1;
    }

    Class_boolean_replace_from_id_parent_htmltext::~Class_boolean_replace_from_id_parent_htmltext() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_boolean_replace_from_id_parent_htmltext::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_boolean_replace_from_id_parent_htmltext output = vx_web_htmldoc::e_boolean_replace_from_id_parent_htmltext;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_boolean_replace_from_id_parent_htmltext::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_boolean_replace_from_id_parent_htmltext output = vx_web_htmldoc::e_boolean_replace_from_id_parent_htmltext;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_boolean_replace_from_id_parent_htmltext::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-replace<-id-parent-htmltext", // name
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

    vx_core::Type_constdef Class_boolean_replace_from_id_parent_htmltext::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_boolean_replace_from_id_parent_htmltext::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-replace<-id-parent-htmltext", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_boolean_replace_from_id_parent_htmltext::vx_empty() const {return vx_web_htmldoc::e_boolean_replace_from_id_parent_htmltext;}
    vx_core::Type_any Class_boolean_replace_from_id_parent_htmltext::vx_type() const {return vx_web_htmldoc::t_boolean_replace_from_id_parent_htmltext;}
    vx_core::Type_msgblock Class_boolean_replace_from_id_parent_htmltext::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_replace_from_id_parent_htmltext::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_boolean_replace_from_id_parent_htmltext::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string id = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string parent = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_string htmltext = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_web_htmldoc::f_boolean_replace_from_id_parent_htmltext(id, parent, htmltext);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func boolean-write-stylesheet<-string)
  vx_core::vx_Type_async f_boolean_write_stylesheet_from_string(vx_core::Type_string text) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve(text);
    vx_core::vx_release_one(text);
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_core::e_boolean);
    }
    return output;
  }
  /**
   * 
   * @async
   * @function boolean_write_stylesheet_from_string
   * Writes a css stylesheet.
   * @param  {string} text
   * @return {boolean}
   * (func boolean-write-stylesheet<-string)
   */
  // (func boolean-write-stylesheet<-string)
  // class Class_boolean_write_stylesheet_from_string {
    Abstract_boolean_write_stylesheet_from_string::~Abstract_boolean_write_stylesheet_from_string() {}

    Class_boolean_write_stylesheet_from_string::Class_boolean_write_stylesheet_from_string() : Abstract_boolean_write_stylesheet_from_string::Abstract_boolean_write_stylesheet_from_string() {
      vx_core::refcount += 1;
    }

    Class_boolean_write_stylesheet_from_string::~Class_boolean_write_stylesheet_from_string() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_boolean_write_stylesheet_from_string::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_boolean_write_stylesheet_from_string output = vx_web_htmldoc::e_boolean_write_stylesheet_from_string;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_boolean_write_stylesheet_from_string::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_boolean_write_stylesheet_from_string output = vx_web_htmldoc::e_boolean_write_stylesheet_from_string;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_boolean_write_stylesheet_from_string::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-write-stylesheet<-string", // name
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

    vx_core::Type_constdef Class_boolean_write_stylesheet_from_string::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_boolean_write_stylesheet_from_string::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-write-stylesheet<-string", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_boolean_write_stylesheet_from_string::vx_empty() const {return vx_web_htmldoc::e_boolean_write_stylesheet_from_string;}
    vx_core::Type_any Class_boolean_write_stylesheet_from_string::vx_type() const {return vx_web_htmldoc::t_boolean_write_stylesheet_from_string;}
    vx_core::Type_msgblock Class_boolean_write_stylesheet_from_string::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_write_stylesheet_from_string::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_async Class_boolean_write_stylesheet_from_string::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const {
      return vx_core::e_any_from_any_async;
    }

    vx_core::vx_Type_async Class_boolean_write_stylesheet_from_string::vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const {
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      vx_core::vx_Type_async output = vx_web_htmldoc::f_boolean_write_stylesheet_from_string(inputval);
      vx_core::vx_release(val);
      return output;
    }

    vx_core::vx_Type_async Class_boolean_write_stylesheet_from_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_value(vx_core::e_any);
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_htmldoc::f_boolean_write_stylesheet_from_string(text);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  // (func boolean-write<-id-attribute-value)
  vx_core::Type_boolean f_boolean_write_from_id_attribute_value(vx_core::Type_string id, vx_core::Type_string attribute, vx_core::Type_string value) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve({id, attribute, value});
    vx_core::vx_release_one_except({id, attribute, value}, output);
    return output;
  }
  /**
   * @function boolean_write_from_id_attribute_value
   * Writes to an html node with given id and attribute name and value.
   * @param  {string} id
   * @param  {string} attribute
   * @param  {string} value
   * @return {boolean}
   * (func boolean-write<-id-attribute-value)
   */
  // (func boolean-write<-id-attribute-value)
  // class Class_boolean_write_from_id_attribute_value {
    Abstract_boolean_write_from_id_attribute_value::~Abstract_boolean_write_from_id_attribute_value() {}

    Class_boolean_write_from_id_attribute_value::Class_boolean_write_from_id_attribute_value() : Abstract_boolean_write_from_id_attribute_value::Abstract_boolean_write_from_id_attribute_value() {
      vx_core::refcount += 1;
    }

    Class_boolean_write_from_id_attribute_value::~Class_boolean_write_from_id_attribute_value() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_boolean_write_from_id_attribute_value::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_boolean_write_from_id_attribute_value output = vx_web_htmldoc::e_boolean_write_from_id_attribute_value;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_boolean_write_from_id_attribute_value::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_boolean_write_from_id_attribute_value output = vx_web_htmldoc::e_boolean_write_from_id_attribute_value;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_boolean_write_from_id_attribute_value::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-write<-id-attribute-value", // name
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

    vx_core::Type_constdef Class_boolean_write_from_id_attribute_value::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_boolean_write_from_id_attribute_value::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-write<-id-attribute-value", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_boolean_write_from_id_attribute_value::vx_empty() const {return vx_web_htmldoc::e_boolean_write_from_id_attribute_value;}
    vx_core::Type_any Class_boolean_write_from_id_attribute_value::vx_type() const {return vx_web_htmldoc::t_boolean_write_from_id_attribute_value;}
    vx_core::Type_msgblock Class_boolean_write_from_id_attribute_value::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_write_from_id_attribute_value::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_boolean_write_from_id_attribute_value::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string id = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string attribute = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_string value = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_web_htmldoc::f_boolean_write_from_id_attribute_value(id, attribute, value);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func boolean-write<-id-htmltext)
  vx_core::Type_boolean f_boolean_write_from_id_htmltext(vx_core::Type_string id, vx_core::Type_string htmltext) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve({id, htmltext});
    vx_core::vx_release_one_except({id, htmltext}, output);
    return output;
  }
  /**
   * @function boolean_write_from_id_htmltext
   * Writes to an html node with given id and text.
   * @param  {string} id
   * @param  {string} htmltext
   * @return {boolean}
   * (func boolean-write<-id-htmltext)
   */
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

  // (func boolean-write<-id-visible)
  vx_core::Type_boolean f_boolean_write_from_id_visible(vx_core::Type_string id, vx_core::Type_boolean visible) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve({id, visible});
    vx_core::vx_release_one_except({id, visible}, output);
    return output;
  }
  /**
   * @function boolean_write_from_id_visible
   * Writes to an html node changing its visibility.
   * @param  {string} id
   * @param  {boolean} visible
   * @return {boolean}
   * (func boolean-write<-id-visible)
   */
  // (func boolean-write<-id-visible)
  // class Class_boolean_write_from_id_visible {
    Abstract_boolean_write_from_id_visible::~Abstract_boolean_write_from_id_visible() {}

    Class_boolean_write_from_id_visible::Class_boolean_write_from_id_visible() : Abstract_boolean_write_from_id_visible::Abstract_boolean_write_from_id_visible() {
      vx_core::refcount += 1;
    }

    Class_boolean_write_from_id_visible::~Class_boolean_write_from_id_visible() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_boolean_write_from_id_visible::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_boolean_write_from_id_visible output = vx_web_htmldoc::e_boolean_write_from_id_visible;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_boolean_write_from_id_visible::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_boolean_write_from_id_visible output = vx_web_htmldoc::e_boolean_write_from_id_visible;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_boolean_write_from_id_visible::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-write<-id-visible", // name
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

    vx_core::Type_constdef Class_boolean_write_from_id_visible::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_boolean_write_from_id_visible::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-write<-id-visible", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_boolean_write_from_id_visible::vx_empty() const {return vx_web_htmldoc::e_boolean_write_from_id_visible;}
    vx_core::Type_any Class_boolean_write_from_id_visible::vx_type() const {return vx_web_htmldoc::t_boolean_write_from_id_visible;}
    vx_core::Type_msgblock Class_boolean_write_from_id_visible::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_write_from_id_visible::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_boolean_write_from_id_visible::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string id = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_boolean visible = vx_core::vx_any_from_any(vx_core::t_boolean, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_htmldoc::f_boolean_write_from_id_visible(id, visible);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func boolean-write<-stylesheet)
  vx_core::vx_Type_async f_boolean_write_from_stylesheet(vx_web_html::Type_stylesheet stylesheet) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve(stylesheet);
    output = vx_core::f_let_async(
      vx_core::t_boolean,
      vx_core::t_any_from_func_async->vx_fn_new({stylesheet}, [stylesheet]() {
        vx_core::Type_string text = vx_web_htmldoc::f_string_from_stylesheet(stylesheet);
        vx_core::vx_ref_plus(text);
        vx_core::vx_Type_async future_iswrite = vx_web_htmldoc::f_boolean_write_stylesheet_from_string(text);
        vx_core::vx_Type_fn_any_from_any fn_any_any_iswrite = [](vx_core::Type_any any_iswrite) {
          vx_core::Type_boolean iswrite = vx_core::vx_any_from_any(vx_core::t_boolean, any_iswrite);
          vx_core::vx_ref_plus(iswrite);
          vx_core::Type_any output_2 = iswrite;
          vx_core::vx_release_one_except(iswrite, output_2);
          return output_2;
        };
        vx_core::vx_Type_async output_1 = vx_core::vx_async_from_async_fn(future_iswrite, vx_core::t_boolean, {}, fn_any_any_iswrite);
        vx_core::vx_release_one(text);
        return output_1;
      })
    );
    vx_core::vx_release_one(stylesheet);
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_core::e_boolean);
    }
    return output;
  }
  /**
   * 
   * @async
   * @function boolean_write_from_stylesheet
   * Writes a css stylesheet.
   * @param  {stylesheet} stylesheet
   * @return {boolean}
   * (func boolean-write<-stylesheet)
   */
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

  // (func boolean-writeevents<-ui)
  vx_core::Type_boolean f_boolean_writeevents_from_ui(vx_ui_ui::Type_ui ui) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve(ui);
    vx_core::vx_release_one_except(ui, output);
    return output;
  }
  /**
   * @function boolean_writeevents_from_ui
   * Writes the eventmap from ui into dom.
   * @param  {ui} ui
   * @return {boolean}
   * (func boolean-writeevents<-ui)
   */
  // (func boolean-writeevents<-ui)
  // class Class_boolean_writeevents_from_ui {
    Abstract_boolean_writeevents_from_ui::~Abstract_boolean_writeevents_from_ui() {}

    Class_boolean_writeevents_from_ui::Class_boolean_writeevents_from_ui() : Abstract_boolean_writeevents_from_ui::Abstract_boolean_writeevents_from_ui() {
      vx_core::refcount += 1;
    }

    Class_boolean_writeevents_from_ui::~Class_boolean_writeevents_from_ui() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_boolean_writeevents_from_ui::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_boolean_writeevents_from_ui output = vx_web_htmldoc::e_boolean_writeevents_from_ui;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_boolean_writeevents_from_ui::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_boolean_writeevents_from_ui output = vx_web_htmldoc::e_boolean_writeevents_from_ui;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_boolean_writeevents_from_ui::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-writeevents<-ui", // name
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

    vx_core::Type_constdef Class_boolean_writeevents_from_ui::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_boolean_writeevents_from_ui::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/htmldoc", // pkgname
        "boolean-writeevents<-ui", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_boolean_writeevents_from_ui::vx_empty() const {return vx_web_htmldoc::e_boolean_writeevents_from_ui;}
    vx_core::Type_any Class_boolean_writeevents_from_ui::vx_type() const {return vx_web_htmldoc::t_boolean_writeevents_from_ui;}
    vx_core::Type_msgblock Class_boolean_writeevents_from_ui::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_writeevents_from_ui::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_boolean_writeevents_from_ui::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_boolean_writeevents_from_ui::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui inputval = vx_core::vx_any_from_any(vx_ui_ui::t_ui, val);
      output = vx_web_htmldoc::f_boolean_writeevents_from_ui(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_boolean_writeevents_from_ui::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_htmldoc::f_boolean_writeevents_from_ui(ui);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func context-read)
  vx_core::Type_context f_context_read() {
    vx_core::Type_context output = vx_core::e_context;
    return output;
  }
  /**
   * @function context_read
   * Reads context from document.data.context
   * @return {context}
   * (func context-read)
   */
  // (func context-read)
  // class Class_context_read {
    Abstract_context_read::~Abstract_context_read() {}

    Class_context_read::Class_context_read() : Abstract_context_read::Abstract_context_read() {
      vx_core::refcount += 1;
    }

    Class_context_read::~Class_context_read() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_context_read::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_context_read output = vx_web_htmldoc::e_context_read;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_context_read::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_context_read output = vx_web_htmldoc::e_context_read;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_context_read::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/htmldoc", // pkgname
        "context-read", // name
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

    vx_core::Type_constdef Class_context_read::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_context_read::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/htmldoc", // pkgname
        "context-read", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_context_read::vx_empty() const {return vx_web_htmldoc::e_context_read;}
    vx_core::Type_any Class_context_read::vx_type() const {return vx_web_htmldoc::t_context_read;}
    vx_core::Type_msgblock Class_context_read::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_context_read::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_context_read::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      output = vx_web_htmldoc::f_context_read();
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func context-write)
  vx_core::Type_context f_context_write(vx_core::Type_context context) {
    vx_core::Type_context output = vx_core::e_context;
    return output;
  }
  /**
   * @function context_write
   * Writes context to document.data.context
   * @return {context}
   * (func context-write)
   */
  // (func context-write)
  // class Class_context_write {
    Abstract_context_write::~Abstract_context_write() {}

    Class_context_write::Class_context_write() : Abstract_context_write::Abstract_context_write() {
      vx_core::refcount += 1;
    }

    Class_context_write::~Class_context_write() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_context_write::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_context_write output = vx_web_htmldoc::e_context_write;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_context_write::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_context_write output = vx_web_htmldoc::e_context_write;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_context_write::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/htmldoc", // pkgname
        "context-write", // name
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

    vx_core::Type_constdef Class_context_write::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_context_write::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/htmldoc", // pkgname
        "context-write", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_context_write::vx_empty() const {return vx_web_htmldoc::e_context_write;}
    vx_core::Type_any Class_context_write::vx_type() const {return vx_web_htmldoc::t_context_write;}
    vx_core::Type_msgblock Class_context_write::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_context_write::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_context_write::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_htmldoc::f_context_write(context);
      vx_core::vx_release_except(arglist, output);
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
  /**
   * @function string_from_id
   * Reads the value of an html node by id.
   * @param  {string} id
   * @return {string}
   * (func string<-id)
   */
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

  // (func string<-stylesheet)
  vx_core::Type_string f_string_from_stylesheet(vx_web_html::Type_stylesheet stylesheet) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve(stylesheet);
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({stylesheet}, [stylesheet]() {
        vx_web_html::Type_stylelist stylelist = vx_web_html::f_styles_from_stylesheet(stylesheet);
        vx_core::vx_ref_plus(stylelist);
        vx_core::Type_string text = vx_web_html::f_string_from_stylelist_indent(stylelist, vx_core::vx_new_int(0));
        vx_core::vx_ref_plus(text);
        vx_core::Type_string output_1 = text;
        vx_core::vx_release_one_except({stylelist, text}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(stylesheet, output);
    return output;
  }
  /**
   * @function string_from_stylesheet
   * Returns string from a given stylesheet
   * @param  {stylesheet} stylesheet
   * @return {string}
   * (func string<-stylesheet)
   */
  // (func string<-stylesheet)
  // class Class_string_from_stylesheet {
    Abstract_string_from_stylesheet::~Abstract_string_from_stylesheet() {}

    Class_string_from_stylesheet::Class_string_from_stylesheet() : Abstract_string_from_stylesheet::Abstract_string_from_stylesheet() {
      vx_core::refcount += 1;
    }

    Class_string_from_stylesheet::~Class_string_from_stylesheet() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_stylesheet::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_string_from_stylesheet output = vx_web_htmldoc::e_string_from_stylesheet;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_stylesheet::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_string_from_stylesheet output = vx_web_htmldoc::e_string_from_stylesheet;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_stylesheet::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/htmldoc", // pkgname
        "string<-stylesheet", // name
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

    vx_core::Type_constdef Class_string_from_stylesheet::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_stylesheet::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/htmldoc", // pkgname
        "string<-stylesheet", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_stylesheet::vx_empty() const {return vx_web_htmldoc::e_string_from_stylesheet;}
    vx_core::Type_any Class_string_from_stylesheet::vx_type() const {return vx_web_htmldoc::t_string_from_stylesheet;}
    vx_core::Type_msgblock Class_string_from_stylesheet::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_stylesheet::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_string_from_stylesheet::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_string_from_stylesheet::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_stylesheet inputval = vx_core::vx_any_from_any(vx_web_html::t_stylesheet, val);
      output = vx_web_htmldoc::f_string_from_stylesheet(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_string_from_stylesheet::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_stylesheet stylesheet = vx_core::vx_any_from_any(vx_web_html::t_stylesheet, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_htmldoc::f_string_from_stylesheet(stylesheet);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func ui-readstate<-uid)
  vx_core::Type_any f_ui_readstate_from_uid(vx_core::Type_string uid) {
    vx_core::Type_any output = vx_core::e_any;
    vx_core::vx_reserve(uid);
    vx_core::vx_release_one_except(uid, output);
    return output;
  }
  /**
   * @function ui_readstate_from_uid
   * Returns ui component from element.
   * @param  {string} uid
   * @return {any}
   * (func ui-readstate<-uid)
   */
  // (func ui-readstate<-uid)
  // class Class_ui_readstate_from_uid {
    Abstract_ui_readstate_from_uid::~Abstract_ui_readstate_from_uid() {}

    Class_ui_readstate_from_uid::Class_ui_readstate_from_uid() : Abstract_ui_readstate_from_uid::Abstract_ui_readstate_from_uid() {
      vx_core::refcount += 1;
    }

    Class_ui_readstate_from_uid::~Class_ui_readstate_from_uid() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_ui_readstate_from_uid::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_ui_readstate_from_uid output = vx_web_htmldoc::e_ui_readstate_from_uid;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_ui_readstate_from_uid::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_htmldoc::Func_ui_readstate_from_uid output = vx_web_htmldoc::e_ui_readstate_from_uid;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_ui_readstate_from_uid::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/htmldoc", // pkgname
        "ui-readstate<-uid", // name
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

    vx_core::Type_constdef Class_ui_readstate_from_uid::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_ui_readstate_from_uid::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/htmldoc", // pkgname
        "ui-readstate<-uid", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_ui_readstate_from_uid::vx_empty() const {return vx_web_htmldoc::e_ui_readstate_from_uid;}
    vx_core::Type_any Class_ui_readstate_from_uid::vx_type() const {return vx_web_htmldoc::t_ui_readstate_from_uid;}
    vx_core::Type_msgblock Class_ui_readstate_from_uid::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ui_readstate_from_uid::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_ui_readstate_from_uid::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_ui_readstate_from_uid::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      output = vx_web_htmldoc::f_ui_readstate_from_uid(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_ui_readstate_from_uid::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string uid = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_htmldoc::f_ui_readstate_from_uid(uid);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_web_htmldoc::Func_boolean_print_from_id_stylesheettext e_boolean_print_from_id_stylesheettext = NULL;
  vx_web_htmldoc::Func_boolean_print_from_id_stylesheettext t_boolean_print_from_id_stylesheettext = NULL;
  vx_web_htmldoc::Func_boolean_remove_from_id e_boolean_remove_from_id = NULL;
  vx_web_htmldoc::Func_boolean_remove_from_id t_boolean_remove_from_id = NULL;
  vx_web_htmldoc::Func_boolean_replace_from_id_htmltext e_boolean_replace_from_id_htmltext = NULL;
  vx_web_htmldoc::Func_boolean_replace_from_id_htmltext t_boolean_replace_from_id_htmltext = NULL;
  vx_web_htmldoc::Func_boolean_replace_from_id_parent_htmltext e_boolean_replace_from_id_parent_htmltext = NULL;
  vx_web_htmldoc::Func_boolean_replace_from_id_parent_htmltext t_boolean_replace_from_id_parent_htmltext = NULL;
  vx_web_htmldoc::Func_boolean_write_stylesheet_from_string e_boolean_write_stylesheet_from_string = NULL;
  vx_web_htmldoc::Func_boolean_write_stylesheet_from_string t_boolean_write_stylesheet_from_string = NULL;
  vx_web_htmldoc::Func_boolean_write_from_id_attribute_value e_boolean_write_from_id_attribute_value = NULL;
  vx_web_htmldoc::Func_boolean_write_from_id_attribute_value t_boolean_write_from_id_attribute_value = NULL;
  vx_web_htmldoc::Func_boolean_write_from_id_htmltext e_boolean_write_from_id_htmltext = NULL;
  vx_web_htmldoc::Func_boolean_write_from_id_htmltext t_boolean_write_from_id_htmltext = NULL;
  vx_web_htmldoc::Func_boolean_write_from_id_visible e_boolean_write_from_id_visible = NULL;
  vx_web_htmldoc::Func_boolean_write_from_id_visible t_boolean_write_from_id_visible = NULL;
  vx_web_htmldoc::Func_boolean_write_from_stylesheet e_boolean_write_from_stylesheet = NULL;
  vx_web_htmldoc::Func_boolean_write_from_stylesheet t_boolean_write_from_stylesheet = NULL;
  vx_web_htmldoc::Func_boolean_writeevents_from_ui e_boolean_writeevents_from_ui = NULL;
  vx_web_htmldoc::Func_boolean_writeevents_from_ui t_boolean_writeevents_from_ui = NULL;
  vx_web_htmldoc::Func_context_read e_context_read = NULL;
  vx_web_htmldoc::Func_context_read t_context_read = NULL;
  vx_web_htmldoc::Func_context_write e_context_write = NULL;
  vx_web_htmldoc::Func_context_write t_context_write = NULL;
  vx_web_htmldoc::Func_string_from_id e_string_from_id = NULL;
  vx_web_htmldoc::Func_string_from_id t_string_from_id = NULL;
  vx_web_htmldoc::Func_string_from_stylesheet e_string_from_stylesheet = NULL;
  vx_web_htmldoc::Func_string_from_stylesheet t_string_from_stylesheet = NULL;
  vx_web_htmldoc::Func_ui_readstate_from_uid e_ui_readstate_from_uid = NULL;
  vx_web_htmldoc::Func_ui_readstate_from_uid t_ui_readstate_from_uid = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_web_htmldoc::e_boolean_print_from_id_stylesheettext = new vx_web_htmldoc::Class_boolean_print_from_id_stylesheettext();
      vx_core::vx_reserve_empty(vx_web_htmldoc::e_boolean_print_from_id_stylesheettext);
      vx_web_htmldoc::t_boolean_print_from_id_stylesheettext = new vx_web_htmldoc::Class_boolean_print_from_id_stylesheettext();
      vx_core::vx_reserve_type(vx_web_htmldoc::t_boolean_print_from_id_stylesheettext);
      vx_web_htmldoc::e_boolean_remove_from_id = new vx_web_htmldoc::Class_boolean_remove_from_id();
      vx_core::vx_reserve_empty(vx_web_htmldoc::e_boolean_remove_from_id);
      vx_web_htmldoc::t_boolean_remove_from_id = new vx_web_htmldoc::Class_boolean_remove_from_id();
      vx_core::vx_reserve_type(vx_web_htmldoc::t_boolean_remove_from_id);
      vx_web_htmldoc::e_boolean_replace_from_id_htmltext = new vx_web_htmldoc::Class_boolean_replace_from_id_htmltext();
      vx_core::vx_reserve_empty(vx_web_htmldoc::e_boolean_replace_from_id_htmltext);
      vx_web_htmldoc::t_boolean_replace_from_id_htmltext = new vx_web_htmldoc::Class_boolean_replace_from_id_htmltext();
      vx_core::vx_reserve_type(vx_web_htmldoc::t_boolean_replace_from_id_htmltext);
      vx_web_htmldoc::e_boolean_replace_from_id_parent_htmltext = new vx_web_htmldoc::Class_boolean_replace_from_id_parent_htmltext();
      vx_core::vx_reserve_empty(vx_web_htmldoc::e_boolean_replace_from_id_parent_htmltext);
      vx_web_htmldoc::t_boolean_replace_from_id_parent_htmltext = new vx_web_htmldoc::Class_boolean_replace_from_id_parent_htmltext();
      vx_core::vx_reserve_type(vx_web_htmldoc::t_boolean_replace_from_id_parent_htmltext);
      vx_web_htmldoc::e_boolean_write_stylesheet_from_string = new vx_web_htmldoc::Class_boolean_write_stylesheet_from_string();
      vx_core::vx_reserve_empty(vx_web_htmldoc::e_boolean_write_stylesheet_from_string);
      vx_web_htmldoc::t_boolean_write_stylesheet_from_string = new vx_web_htmldoc::Class_boolean_write_stylesheet_from_string();
      vx_core::vx_reserve_type(vx_web_htmldoc::t_boolean_write_stylesheet_from_string);
      vx_web_htmldoc::e_boolean_write_from_id_attribute_value = new vx_web_htmldoc::Class_boolean_write_from_id_attribute_value();
      vx_core::vx_reserve_empty(vx_web_htmldoc::e_boolean_write_from_id_attribute_value);
      vx_web_htmldoc::t_boolean_write_from_id_attribute_value = new vx_web_htmldoc::Class_boolean_write_from_id_attribute_value();
      vx_core::vx_reserve_type(vx_web_htmldoc::t_boolean_write_from_id_attribute_value);
      vx_web_htmldoc::e_boolean_write_from_id_htmltext = new vx_web_htmldoc::Class_boolean_write_from_id_htmltext();
      vx_core::vx_reserve_empty(vx_web_htmldoc::e_boolean_write_from_id_htmltext);
      vx_web_htmldoc::t_boolean_write_from_id_htmltext = new vx_web_htmldoc::Class_boolean_write_from_id_htmltext();
      vx_core::vx_reserve_type(vx_web_htmldoc::t_boolean_write_from_id_htmltext);
      vx_web_htmldoc::e_boolean_write_from_id_visible = new vx_web_htmldoc::Class_boolean_write_from_id_visible();
      vx_core::vx_reserve_empty(vx_web_htmldoc::e_boolean_write_from_id_visible);
      vx_web_htmldoc::t_boolean_write_from_id_visible = new vx_web_htmldoc::Class_boolean_write_from_id_visible();
      vx_core::vx_reserve_type(vx_web_htmldoc::t_boolean_write_from_id_visible);
      vx_web_htmldoc::e_boolean_write_from_stylesheet = new vx_web_htmldoc::Class_boolean_write_from_stylesheet();
      vx_core::vx_reserve_empty(vx_web_htmldoc::e_boolean_write_from_stylesheet);
      vx_web_htmldoc::t_boolean_write_from_stylesheet = new vx_web_htmldoc::Class_boolean_write_from_stylesheet();
      vx_core::vx_reserve_type(vx_web_htmldoc::t_boolean_write_from_stylesheet);
      vx_web_htmldoc::e_boolean_writeevents_from_ui = new vx_web_htmldoc::Class_boolean_writeevents_from_ui();
      vx_core::vx_reserve_empty(vx_web_htmldoc::e_boolean_writeevents_from_ui);
      vx_web_htmldoc::t_boolean_writeevents_from_ui = new vx_web_htmldoc::Class_boolean_writeevents_from_ui();
      vx_core::vx_reserve_type(vx_web_htmldoc::t_boolean_writeevents_from_ui);
      vx_web_htmldoc::e_context_read = new vx_web_htmldoc::Class_context_read();
      vx_core::vx_reserve_empty(vx_web_htmldoc::e_context_read);
      vx_web_htmldoc::t_context_read = new vx_web_htmldoc::Class_context_read();
      vx_core::vx_reserve_type(vx_web_htmldoc::t_context_read);
      vx_web_htmldoc::e_context_write = new vx_web_htmldoc::Class_context_write();
      vx_core::vx_reserve_empty(vx_web_htmldoc::e_context_write);
      vx_web_htmldoc::t_context_write = new vx_web_htmldoc::Class_context_write();
      vx_core::vx_reserve_type(vx_web_htmldoc::t_context_write);
      vx_web_htmldoc::e_string_from_id = new vx_web_htmldoc::Class_string_from_id();
      vx_core::vx_reserve_empty(vx_web_htmldoc::e_string_from_id);
      vx_web_htmldoc::t_string_from_id = new vx_web_htmldoc::Class_string_from_id();
      vx_core::vx_reserve_type(vx_web_htmldoc::t_string_from_id);
      vx_web_htmldoc::e_string_from_stylesheet = new vx_web_htmldoc::Class_string_from_stylesheet();
      vx_core::vx_reserve_empty(vx_web_htmldoc::e_string_from_stylesheet);
      vx_web_htmldoc::t_string_from_stylesheet = new vx_web_htmldoc::Class_string_from_stylesheet();
      vx_core::vx_reserve_type(vx_web_htmldoc::t_string_from_stylesheet);
      vx_web_htmldoc::e_ui_readstate_from_uid = new vx_web_htmldoc::Class_ui_readstate_from_uid();
      vx_core::vx_reserve_empty(vx_web_htmldoc::e_ui_readstate_from_uid);
      vx_web_htmldoc::t_ui_readstate_from_uid = new vx_web_htmldoc::Class_ui_readstate_from_uid();
      vx_core::vx_reserve_type(vx_web_htmldoc::t_ui_readstate_from_uid);
      vx_core::vx_Type_mapany maptype;
      vx_core::vx_Type_mapany mapconst;
      vx_core::vx_Type_mapfunc mapfunc;
      vx_core::vx_Type_mapany mapempty;
      mapfunc["boolean-print<-id-stylesheettext"] = vx_web_htmldoc::t_boolean_print_from_id_stylesheettext;
      mapfunc["boolean-remove<-id"] = vx_web_htmldoc::t_boolean_remove_from_id;
      mapfunc["boolean-replace<-id-htmltext"] = vx_web_htmldoc::t_boolean_replace_from_id_htmltext;
      mapfunc["boolean-replace<-id-parent-htmltext"] = vx_web_htmldoc::t_boolean_replace_from_id_parent_htmltext;
      mapfunc["boolean-write-stylesheet<-string"] = vx_web_htmldoc::t_boolean_write_stylesheet_from_string;
      mapfunc["boolean-write<-id-attribute-value"] = vx_web_htmldoc::t_boolean_write_from_id_attribute_value;
      mapfunc["boolean-write<-id-htmltext"] = vx_web_htmldoc::t_boolean_write_from_id_htmltext;
      mapfunc["boolean-write<-id-visible"] = vx_web_htmldoc::t_boolean_write_from_id_visible;
      mapfunc["boolean-write<-stylesheet"] = vx_web_htmldoc::t_boolean_write_from_stylesheet;
      mapfunc["boolean-writeevents<-ui"] = vx_web_htmldoc::t_boolean_writeevents_from_ui;
      mapfunc["context-read"] = vx_web_htmldoc::t_context_read;
      mapfunc["context-write"] = vx_web_htmldoc::t_context_write;
      mapfunc["string<-id"] = vx_web_htmldoc::t_string_from_id;
      mapfunc["string<-stylesheet"] = vx_web_htmldoc::t_string_from_stylesheet;
      mapfunc["ui-readstate<-uid"] = vx_web_htmldoc::t_ui_readstate_from_uid;
      vx_core::vx_global_package_set("vx/web/htmldoc", maptype, mapconst, mapfunc);
	   }
  // }

}
