#include <map>
#include <string>
#include "../vx/core.hpp"
#include "../vx/type.hpp"
#include "collection.hpp"

namespace vx_collection {
// :body

  // vx_list_from_list_fn_filter(generic_list_1, list, fn-any<-any)
  vx_core::Type_any vx_list_from_list_fn_filter(vx_core::Type_any generic_list_1, vx_core::Type_list vallist, vx_core::Func_any_from_any fn_filter) {
		vx_core::Type_any output = vx_core::vx_empty(generic_list_1);
    vx_core::vx_Type_listany listval = vallist->vx_list();
    vx_core::vx_Type_listany items;
    for (vx_core::Type_any val : listval) {
      vx_core::Type_any newval = fn_filter->vx_any_from_any(val);
      vx_core::vx_ref_plus(newval);
      vx_core::Type_boolean isempty = vx_core::f_is_empty_1(newval);
      vx_core::vx_ref_minus(newval);
      if (!isempty->vx_boolean()) {
        items.push_back(newval);
      }
      vx_core::vx_release(isempty);
    }
    output = generic_list_1->vx_new(items);
    vx_core::vx_release_except({vallist, fn_filter}, output);
		return output;
	}

  // vx_list_from_list_start_end(generic_list_1, list, int, int)
  vx_core::Type_any vx_list_from_list_start_end(vx_core::Type_any generic_list_1, vx_core::Type_list values, vx_core::Type_int start, vx_core::Type_int end) {
		vx_core::Type_any output = vx_core::vx_empty(generic_list_1);
    long istart = start->vx_int();
    long iend = end->vx_int();
    vx_core::vx_Type_listany listval = values->vx_list();
    long isize = vx_core::vx_int_from_sizet(listval.size());
    if (isize > 0) {
      if (istart < 0) {
        istart = 0;
      }
      if (iend > isize) {
        iend = isize;
      }
			auto first = listval.begin() + istart;
      auto last = listval.begin() + iend;
      vx_core::vx_Type_listany listsub = std::vector(first, last);
      output = generic_list_1->vx_new(listsub);
    }
		return output;
	}


  // (func list<-list-fn-filter)
  // class Class_list_from_list_fn_filter {
    Abstract_list_from_list_fn_filter::~Abstract_list_from_list_fn_filter() {}

    Class_list_from_list_fn_filter::Class_list_from_list_fn_filter() : Abstract_list_from_list_fn_filter::Abstract_list_from_list_fn_filter() {
      vx_core::refcount += 1;
    }

    Class_list_from_list_fn_filter::~Class_list_from_list_fn_filter() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_list_from_list_fn_filter::vx_new(vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_list_fn_filter output = vx_collection::e_list_from_list_fn_filter;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_list_from_list_fn_filter::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_list_fn_filter output = vx_collection::e_list_from_list_fn_filter;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_list_from_list_fn_filter::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/collection", // pkgname
        "list<-list-fn-filter", // name
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

    vx_core::Type_any Class_list_from_list_fn_filter::vx_empty() const {return vx_collection::e_list_from_list_fn_filter;}
    vx_core::Type_any Class_list_from_list_fn_filter::vx_type() const {return vx_collection::t_list_from_list_fn_filter;}
    vx_core::Type_msgblock Class_list_from_list_fn_filter::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_list_from_list_fn_filter::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_list_from_list_fn_filter::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_list generic_list_1 = vx_core::vx_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_list vallist = vx_core::vx_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_any fn_filter = vx_core::vx_any_from_any(vx_core::t_any_from_any, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_collection::f_list_from_list_fn_filter(generic_list_1, vallist, fn_filter);
      vx_core::vx_release_except(arglist, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_list_from_list_start_end::vx_new(vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_list_start_end output = vx_collection::e_list_from_list_start_end;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_list_from_list_start_end::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_list_start_end output = vx_collection::e_list_from_list_start_end;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_list_from_list_start_end::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/collection", // pkgname
        "list<-list-start-end", // name
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

    vx_core::Type_any Class_list_from_list_start_end::vx_empty() const {return vx_collection::e_list_from_list_start_end;}
    vx_core::Type_any Class_list_from_list_start_end::vx_type() const {return vx_collection::t_list_from_list_start_end;}
    vx_core::Type_msgblock Class_list_from_list_start_end::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_list_from_list_start_end::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_list_from_list_start_end::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_list generic_list_1 = vx_core::vx_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_list values = vx_core::vx_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int start = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_int end = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_collection::f_list_from_list_start_end(generic_list_1, values, start, end);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func is-list)
  vx_core::Type_boolean f_is_list(vx_core::Type_any val) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve(val);
    output = vx_core::f_eq(
      vx_core::vx_new_string(":list"),
      vx_core::f_extends_from_any(val)
    );
    vx_core::vx_release_one_except(val, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_is_list::vx_new(vx_core::vx_Type_listany vals) const {
      vx_collection::Func_is_list output = vx_collection::e_is_list;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_is_list::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_collection::Func_is_list output = vx_collection::e_is_list;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_is_list::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/collection", // pkgname
        "is-list", // name
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

    vx_core::Type_any Class_is_list::vx_empty() const {return vx_collection::e_is_list;}
    vx_core::Type_any Class_is_list::vx_type() const {return vx_collection::t_is_list;}
    vx_core::Type_msgblock Class_is_list::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_is_list::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_is_list::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_is_list::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any, val);
      output = vx_collection::f_is_list(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_is_list::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any val = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_collection::f_is_list(val);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func is-map)
  vx_core::Type_boolean f_is_map(vx_core::Type_any val) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve(val);
    output = vx_core::f_eq(
      vx_core::vx_new_string(":map"),
      vx_core::f_extends_from_any(val)
    );
    vx_core::vx_release_one_except(val, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_is_map::vx_new(vx_core::vx_Type_listany vals) const {
      vx_collection::Func_is_map output = vx_collection::e_is_map;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_is_map::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_collection::Func_is_map output = vx_collection::e_is_map;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_is_map::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/collection", // pkgname
        "is-map", // name
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

    vx_core::Type_any Class_is_map::vx_empty() const {return vx_collection::e_is_map;}
    vx_core::Type_any Class_is_map::vx_type() const {return vx_collection::t_is_map;}
    vx_core::Type_msgblock Class_is_map::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_is_map::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_is_map::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_is_map::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any, val);
      output = vx_collection::f_is_map(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_is_map::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any val = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_collection::f_is_map(val);
      vx_core::vx_release_except(arglist, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_list_from_list_end::vx_new(vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_list_end output = vx_collection::e_list_from_list_end;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_list_from_list_end::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_list_end output = vx_collection::e_list_from_list_end;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_list_from_list_end::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/collection", // pkgname
        "list<-list-end", // name
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

    vx_core::Type_any Class_list_from_list_end::vx_empty() const {return vx_collection::e_list_from_list_end;}
    vx_core::Type_any Class_list_from_list_end::vx_type() const {return vx_collection::t_list_from_list_end;}
    vx_core::Type_msgblock Class_list_from_list_end::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_list_from_list_end::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_list_from_list_end::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_list generic_list_1 = vx_core::vx_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_list values = vx_core::vx_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int end = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_collection::f_list_from_list_end(generic_list_1, values, end);
      vx_core::vx_release_except(arglist, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_list_from_list_filtertypes::vx_new(vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_list_filtertypes output = vx_collection::e_list_from_list_filtertypes;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_list_from_list_filtertypes::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_list_filtertypes output = vx_collection::e_list_from_list_filtertypes;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_list_from_list_filtertypes::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/collection", // pkgname
        "list<-list-filtertypes", // name
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

    vx_core::Type_any Class_list_from_list_filtertypes::vx_empty() const {return vx_collection::e_list_from_list_filtertypes;}
    vx_core::Type_any Class_list_from_list_filtertypes::vx_type() const {return vx_collection::t_list_from_list_filtertypes;}
    vx_core::Type_msgblock Class_list_from_list_filtertypes::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_list_from_list_filtertypes::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_list_from_list_filtertypes::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_list generic_list_1 = vx_core::vx_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_list vallist = vx_core::vx_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_typelist filtertypes = vx_core::vx_any_from_any(vx_core::t_typelist, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_collection::f_list_from_list_filtertypes(generic_list_1, vallist, filtertypes);
      vx_core::vx_release_except(arglist, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_list_from_list_start::vx_new(vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_list_start output = vx_collection::e_list_from_list_start;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_list_from_list_start::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_list_start output = vx_collection::e_list_from_list_start;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_list_from_list_start::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/collection", // pkgname
        "list<-list-start", // name
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

    vx_core::Type_any Class_list_from_list_start::vx_empty() const {return vx_collection::e_list_from_list_start;}
    vx_core::Type_any Class_list_from_list_start::vx_type() const {return vx_collection::t_list_from_list_start;}
    vx_core::Type_msgblock Class_list_from_list_start::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_list_from_list_start::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_list_from_list_start::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_list generic_list_1 = vx_core::vx_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_list values = vx_core::vx_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int start = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_collection::f_list_from_list_start(generic_list_1, values, start);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_collection::Func_list_from_list_fn_filter e_list_from_list_fn_filter = NULL;
  vx_collection::Func_list_from_list_fn_filter t_list_from_list_fn_filter = NULL;
  vx_collection::Func_list_from_list_start_end e_list_from_list_start_end = NULL;
  vx_collection::Func_list_from_list_start_end t_list_from_list_start_end = NULL;
  vx_collection::Func_is_list e_is_list = NULL;
  vx_collection::Func_is_list t_is_list = NULL;
  vx_collection::Func_is_map e_is_map = NULL;
  vx_collection::Func_is_map t_is_map = NULL;
  vx_collection::Func_list_from_list_end e_list_from_list_end = NULL;
  vx_collection::Func_list_from_list_end t_list_from_list_end = NULL;
  vx_collection::Func_list_from_list_filtertypes e_list_from_list_filtertypes = NULL;
  vx_collection::Func_list_from_list_filtertypes t_list_from_list_filtertypes = NULL;
  vx_collection::Func_list_from_list_start e_list_from_list_start = NULL;
  vx_collection::Func_list_from_list_start t_list_from_list_start = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_collection::e_list_from_list_fn_filter = new vx_collection::Class_list_from_list_fn_filter();
      vx_core::vx_reserve_empty(vx_collection::e_list_from_list_fn_filter);
      vx_collection::t_list_from_list_fn_filter = new vx_collection::Class_list_from_list_fn_filter();
      vx_core::vx_reserve_type(vx_collection::t_list_from_list_fn_filter);
      vx_collection::e_list_from_list_start_end = new vx_collection::Class_list_from_list_start_end();
      vx_core::vx_reserve_empty(vx_collection::e_list_from_list_start_end);
      vx_collection::t_list_from_list_start_end = new vx_collection::Class_list_from_list_start_end();
      vx_core::vx_reserve_type(vx_collection::t_list_from_list_start_end);
      vx_collection::e_is_list = new vx_collection::Class_is_list();
      vx_core::vx_reserve_empty(vx_collection::e_is_list);
      vx_collection::t_is_list = new vx_collection::Class_is_list();
      vx_core::vx_reserve_type(vx_collection::t_is_list);
      vx_collection::e_is_map = new vx_collection::Class_is_map();
      vx_core::vx_reserve_empty(vx_collection::e_is_map);
      vx_collection::t_is_map = new vx_collection::Class_is_map();
      vx_core::vx_reserve_type(vx_collection::t_is_map);
      vx_collection::e_list_from_list_end = new vx_collection::Class_list_from_list_end();
      vx_core::vx_reserve_empty(vx_collection::e_list_from_list_end);
      vx_collection::t_list_from_list_end = new vx_collection::Class_list_from_list_end();
      vx_core::vx_reserve_type(vx_collection::t_list_from_list_end);
      vx_collection::e_list_from_list_filtertypes = new vx_collection::Class_list_from_list_filtertypes();
      vx_core::vx_reserve_empty(vx_collection::e_list_from_list_filtertypes);
      vx_collection::t_list_from_list_filtertypes = new vx_collection::Class_list_from_list_filtertypes();
      vx_core::vx_reserve_type(vx_collection::t_list_from_list_filtertypes);
      vx_collection::e_list_from_list_start = new vx_collection::Class_list_from_list_start();
      vx_core::vx_reserve_empty(vx_collection::e_list_from_list_start);
      vx_collection::t_list_from_list_start = new vx_collection::Class_list_from_list_start();
      vx_core::vx_reserve_type(vx_collection::t_list_from_list_start);
    }
    vx_core::vx_Type_mapany vx_Class_package::maptype() {
      vx_core::vx_Type_mapany output;
      output["anylist"] = vx_core::t_anylist;
      return output;
    }
    vx_core::vx_Type_mapany vx_Class_package::mapconst() {
      vx_core::vx_Type_mapany output;
      return output;
    }
    std::map<std::string, vx_core::Type_func> vx_Class_package::mapfunc() {
      vx_core::vx_Type_mapfunc output;
      return output;
    }
  // }

}
