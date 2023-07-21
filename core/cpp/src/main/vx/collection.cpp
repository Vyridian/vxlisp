#include "../vx/core.hpp"
#include "../vx/type.hpp"
#include "collection.hpp"

namespace vx_collection {
// :body


  // (func list<-list-fn-filter)
  // class Class_list_from_list_fn_filter {
    Abstract_list_from_list_fn_filter::~Abstract_list_from_list_fn_filter() {}

    Class_list_from_list_fn_filter::Class_list_from_list_fn_filter() : Abstract_list_from_list_fn_filter::Abstract_list_from_list_fn_filter() {
      vx_core::refcount += 1;
    }
    Class_list_from_list_fn_filter::~Class_list_from_list_fn_filter() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_list_from_list_fn_filter::vx_new(vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_list_fn_filter output = vx_collection::e_list_from_list_fn_filter();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_list_from_list_fn_filter::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_list_fn_filter output = vx_collection::e_list_from_list_fn_filter();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_typedef Class_list_from_list_fn_filter::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "list-1", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_any()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_list_from_list_fn_filter::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/collection", // pkgname
        "list<-list-fn-filter", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_list_from_list_fn_filter::vx_empty() const {return vx_collection::e_list_from_list_fn_filter();}
    vx_core::Type_any Class_list_from_list_fn_filter::vx_type() const {return vx_collection::t_list_from_list_fn_filter();}
    vx_core::Type_msgblock Class_list_from_list_fn_filter::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_list_from_list_fn_filter::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_list_from_list_fn_filter::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_list generic_list_1 = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_list vallist = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_any fn_filter = vx_core::vx_any_from_any(vx_core::t_any_from_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_collection::f_list_from_list_fn_filter(generic_list_1, vallist, fn_filter);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  // (func list<-list-start-end)
  // class Class_list_from_list_start_end {
    Abstract_list_from_list_start_end::~Abstract_list_from_list_start_end() {}

    Class_list_from_list_start_end::Class_list_from_list_start_end() : Abstract_list_from_list_start_end::Abstract_list_from_list_start_end() {
      vx_core::refcount += 1;
    }
    Class_list_from_list_start_end::~Class_list_from_list_start_end() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_list_from_list_start_end::vx_new(vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_list_start_end output = vx_collection::e_list_from_list_start_end();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_list_from_list_start_end::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_list_start_end output = vx_collection::e_list_from_list_start_end();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_typedef Class_list_from_list_start_end::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "list-1", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_any()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_list_from_list_start_end::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/collection", // pkgname
        "list<-list-start-end", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_list_from_list_start_end::vx_empty() const {return vx_collection::e_list_from_list_start_end();}
    vx_core::Type_any Class_list_from_list_start_end::vx_type() const {return vx_collection::t_list_from_list_start_end();}
    vx_core::Type_msgblock Class_list_from_list_start_end::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_list_from_list_start_end::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_list_from_list_start_end::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_list generic_list_1 = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_list values = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int start = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_int end = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_collection::f_list_from_list_start_end(generic_list_1, values, start, end);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  // (func is-list)
  vx_core::Type_boolean f_is_list(vx_core::Type_any val) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    output = vx_core::f_eq(
      vx_core::vx_new_string(":list"),
      vx_core::f_extends_from_any(val)
    );
    vx_core::vx_release(val);
    return output;
  }

  // (func is-list)
  // class Class_is_list {
    Abstract_is_list::~Abstract_is_list() {}

    Class_is_list::Class_is_list() : Abstract_is_list::Abstract_is_list() {
      vx_core::refcount += 1;
    }
    Class_is_list::~Class_is_list() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_is_list::vx_new(vx_core::vx_Type_listany vals) const {
      vx_collection::Func_is_list output = vx_collection::e_is_list();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_is_list::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_collection::Func_is_list output = vx_collection::e_is_list();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_typedef Class_is_list::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_is_list::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/collection", // pkgname
        "is-list", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_is_list::vx_empty() const {return vx_collection::e_is_list();}
    vx_core::Type_any Class_is_list::vx_type() const {return vx_collection::t_is_list();}
    vx_core::Type_msgblock Class_is_list::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_is_list::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_is_list::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_is_list::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any(), val);
      output = vx_collection::f_is_list(inputval);
      vx_core::vx_release(val);
      return output;
    }

    vx_core::Type_any Class_is_list::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any val = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_collection::f_is_list(val);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  // (func is-map)
  vx_core::Type_boolean f_is_map(vx_core::Type_any val) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    output = vx_core::f_eq(
      vx_core::vx_new_string(":map"),
      vx_core::f_extends_from_any(val)
    );
    vx_core::vx_release(val);
    return output;
  }

  // (func is-map)
  // class Class_is_map {
    Abstract_is_map::~Abstract_is_map() {}

    Class_is_map::Class_is_map() : Abstract_is_map::Abstract_is_map() {
      vx_core::refcount += 1;
    }
    Class_is_map::~Class_is_map() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_is_map::vx_new(vx_core::vx_Type_listany vals) const {
      vx_collection::Func_is_map output = vx_collection::e_is_map();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_is_map::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_collection::Func_is_map output = vx_collection::e_is_map();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_typedef Class_is_map::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_is_map::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/collection", // pkgname
        "is-map", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_is_map::vx_empty() const {return vx_collection::e_is_map();}
    vx_core::Type_any Class_is_map::vx_type() const {return vx_collection::t_is_map();}
    vx_core::Type_msgblock Class_is_map::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_is_map::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_is_map::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_is_map::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any(), val);
      output = vx_collection::f_is_map(inputval);
      vx_core::vx_release(val);
      return output;
    }

    vx_core::Type_any Class_is_map::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any val = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_collection::f_is_map(val);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  // (func list<-list-end)
  // class Class_list_from_list_end {
    Abstract_list_from_list_end::~Abstract_list_from_list_end() {}

    Class_list_from_list_end::Class_list_from_list_end() : Abstract_list_from_list_end::Abstract_list_from_list_end() {
      vx_core::refcount += 1;
    }
    Class_list_from_list_end::~Class_list_from_list_end() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_list_from_list_end::vx_new(vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_list_end output = vx_collection::e_list_from_list_end();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_list_from_list_end::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_list_end output = vx_collection::e_list_from_list_end();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_typedef Class_list_from_list_end::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "list-1", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_any()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_list_from_list_end::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/collection", // pkgname
        "list<-list-end", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_list_from_list_end::vx_empty() const {return vx_collection::e_list_from_list_end();}
    vx_core::Type_any Class_list_from_list_end::vx_type() const {return vx_collection::t_list_from_list_end();}
    vx_core::Type_msgblock Class_list_from_list_end::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_list_from_list_end::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_list_from_list_end::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_list generic_list_1 = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_list values = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int end = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_collection::f_list_from_list_end(generic_list_1, values, end);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  // (func list<-list-filtertypes)
  // class Class_list_from_list_filtertypes {
    Abstract_list_from_list_filtertypes::~Abstract_list_from_list_filtertypes() {}

    Class_list_from_list_filtertypes::Class_list_from_list_filtertypes() : Abstract_list_from_list_filtertypes::Abstract_list_from_list_filtertypes() {
      vx_core::refcount += 1;
    }
    Class_list_from_list_filtertypes::~Class_list_from_list_filtertypes() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_list_from_list_filtertypes::vx_new(vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_list_filtertypes output = vx_collection::e_list_from_list_filtertypes();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_list_from_list_filtertypes::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_list_filtertypes output = vx_collection::e_list_from_list_filtertypes();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_typedef Class_list_from_list_filtertypes::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "list-1", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_any()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_list_from_list_filtertypes::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/collection", // pkgname
        "list<-list-filtertypes", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_list_from_list_filtertypes::vx_empty() const {return vx_collection::e_list_from_list_filtertypes();}
    vx_core::Type_any Class_list_from_list_filtertypes::vx_type() const {return vx_collection::t_list_from_list_filtertypes();}
    vx_core::Type_msgblock Class_list_from_list_filtertypes::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_list_from_list_filtertypes::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_list_from_list_filtertypes::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_list generic_list_1 = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_list vallist = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_typelist filtertypes = vx_core::vx_any_from_any(vx_core::t_typelist(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_collection::f_list_from_list_filtertypes(generic_list_1, vallist, filtertypes);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  // (func list<-list-start)
  // class Class_list_from_list_start {
    Abstract_list_from_list_start::~Abstract_list_from_list_start() {}

    Class_list_from_list_start::Class_list_from_list_start() : Abstract_list_from_list_start::Abstract_list_from_list_start() {
      vx_core::refcount += 1;
    }
    Class_list_from_list_start::~Class_list_from_list_start() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_list_from_list_start::vx_new(vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_list_start output = vx_collection::e_list_from_list_start();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_list_from_list_start::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_list_start output = vx_collection::e_list_from_list_start();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_typedef Class_list_from_list_start::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "list-1", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_any()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_list_from_list_start::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/collection", // pkgname
        "list<-list-start", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_list_from_list_start::vx_empty() const {return vx_collection::e_list_from_list_start();}
    vx_core::Type_any Class_list_from_list_start::vx_type() const {return vx_collection::t_list_from_list_start();}
    vx_core::Type_msgblock Class_list_from_list_start::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_list_from_list_start::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_list_from_list_start::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_list generic_list_1 = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_list values = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int start = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_collection::f_list_from_list_start(generic_list_1, values, start);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  vx_collection::vx_Class_package* vx_package = new vx_collection::vx_Class_package();

  // (func list<-list-fn-filter)
  vx_collection::Func_list_from_list_fn_filter e_list_from_list_fn_filter() {
    vx_collection::Func_list_from_list_fn_filter output = vx_collection::vx_package->e_list_from_list_fn_filter;
    if (output == NULL) {
      output = new vx_collection::Class_list_from_list_fn_filter();
      vx_core::vx_reserve_empty(output);
      vx_collection::vx_package->e_list_from_list_fn_filter = output;
    }
    return output;
  }
  vx_collection::Func_list_from_list_fn_filter t_list_from_list_fn_filter() {
    vx_collection::Func_list_from_list_fn_filter output = vx_collection::vx_package->t_list_from_list_fn_filter;
    if (output == NULL) {
      output = new vx_collection::Class_list_from_list_fn_filter();
      vx_core::vx_reserve_type(output);
      vx_collection::vx_package->t_list_from_list_fn_filter = output;
    }
    return output;
  }

  // (func list<-list-start-end)
  vx_collection::Func_list_from_list_start_end e_list_from_list_start_end() {
    vx_collection::Func_list_from_list_start_end output = vx_collection::vx_package->e_list_from_list_start_end;
    if (output == NULL) {
      output = new vx_collection::Class_list_from_list_start_end();
      vx_core::vx_reserve_empty(output);
      vx_collection::vx_package->e_list_from_list_start_end = output;
    }
    return output;
  }
  vx_collection::Func_list_from_list_start_end t_list_from_list_start_end() {
    vx_collection::Func_list_from_list_start_end output = vx_collection::vx_package->t_list_from_list_start_end;
    if (output == NULL) {
      output = new vx_collection::Class_list_from_list_start_end();
      vx_core::vx_reserve_type(output);
      vx_collection::vx_package->t_list_from_list_start_end = output;
    }
    return output;
  }

  // (func is-list)
  vx_collection::Func_is_list e_is_list() {
    vx_collection::Func_is_list output = vx_collection::vx_package->e_is_list;
    if (output == NULL) {
      output = new vx_collection::Class_is_list();
      vx_core::vx_reserve_empty(output);
      vx_collection::vx_package->e_is_list = output;
    }
    return output;
  }
  vx_collection::Func_is_list t_is_list() {
    vx_collection::Func_is_list output = vx_collection::vx_package->t_is_list;
    if (output == NULL) {
      output = new vx_collection::Class_is_list();
      vx_core::vx_reserve_type(output);
      vx_collection::vx_package->t_is_list = output;
    }
    return output;
  }

  // (func is-map)
  vx_collection::Func_is_map e_is_map() {
    vx_collection::Func_is_map output = vx_collection::vx_package->e_is_map;
    if (output == NULL) {
      output = new vx_collection::Class_is_map();
      vx_core::vx_reserve_empty(output);
      vx_collection::vx_package->e_is_map = output;
    }
    return output;
  }
  vx_collection::Func_is_map t_is_map() {
    vx_collection::Func_is_map output = vx_collection::vx_package->t_is_map;
    if (output == NULL) {
      output = new vx_collection::Class_is_map();
      vx_core::vx_reserve_type(output);
      vx_collection::vx_package->t_is_map = output;
    }
    return output;
  }

  // (func list<-list-end)
  vx_collection::Func_list_from_list_end e_list_from_list_end() {
    vx_collection::Func_list_from_list_end output = vx_collection::vx_package->e_list_from_list_end;
    if (output == NULL) {
      output = new vx_collection::Class_list_from_list_end();
      vx_core::vx_reserve_empty(output);
      vx_collection::vx_package->e_list_from_list_end = output;
    }
    return output;
  }
  vx_collection::Func_list_from_list_end t_list_from_list_end() {
    vx_collection::Func_list_from_list_end output = vx_collection::vx_package->t_list_from_list_end;
    if (output == NULL) {
      output = new vx_collection::Class_list_from_list_end();
      vx_core::vx_reserve_type(output);
      vx_collection::vx_package->t_list_from_list_end = output;
    }
    return output;
  }

  // (func list<-list-filtertypes)
  vx_collection::Func_list_from_list_filtertypes e_list_from_list_filtertypes() {
    vx_collection::Func_list_from_list_filtertypes output = vx_collection::vx_package->e_list_from_list_filtertypes;
    if (output == NULL) {
      output = new vx_collection::Class_list_from_list_filtertypes();
      vx_core::vx_reserve_empty(output);
      vx_collection::vx_package->e_list_from_list_filtertypes = output;
    }
    return output;
  }
  vx_collection::Func_list_from_list_filtertypes t_list_from_list_filtertypes() {
    vx_collection::Func_list_from_list_filtertypes output = vx_collection::vx_package->t_list_from_list_filtertypes;
    if (output == NULL) {
      output = new vx_collection::Class_list_from_list_filtertypes();
      vx_core::vx_reserve_type(output);
      vx_collection::vx_package->t_list_from_list_filtertypes = output;
    }
    return output;
  }

  // (func list<-list-start)
  vx_collection::Func_list_from_list_start e_list_from_list_start() {
    vx_collection::Func_list_from_list_start output = vx_collection::vx_package->e_list_from_list_start;
    if (output == NULL) {
      output = new vx_collection::Class_list_from_list_start();
      vx_core::vx_reserve_empty(output);
      vx_collection::vx_package->e_list_from_list_start = output;
    }
    return output;
  }
  vx_collection::Func_list_from_list_start t_list_from_list_start() {
    vx_collection::Func_list_from_list_start output = vx_collection::vx_package->t_list_from_list_start;
    if (output == NULL) {
      output = new vx_collection::Class_list_from_list_start();
      vx_core::vx_reserve_type(output);
      vx_collection::vx_package->t_list_from_list_start = output;
    }
    return output;
  }

}
