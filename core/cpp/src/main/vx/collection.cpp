#include <memory>
#include "../vx/core.hpp"
#include "../vx/type.hpp"
#include "vx/collection.hpp"

//namespace vx_collection {
  /**
   * @function is_list
   * Returns true if the given value is a list.
   * @param  {any} val Any value
   * @return {boolean}
   * (func is-list)
   */
  //class Func_is_list {

    template <class T> std::shared_ptr<T> vx_collection::Class_is_list::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_collection::Func_is_list output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_collection::Class_is_list::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_collection::Func_is_list output;
      return output;
    }

    vx_core::Type_typedef vx_collection::Class_is_list::vx_typedef() {return vx_collection::t_is_list->vx_typedef();}

    vx_core::Type_funcdef vx_collection::Class_is_list::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/collection", // pkgname
        "is-list", // name
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

    template <class T> std::shared_ptr<T> vx_collection::Class_is_list::vx_empty(std::shared_ptr<T> val) {return vx_collection::e_is_list;}
    template <class T> std::shared_ptr<T> vx_collection::Class_is_list::vx_type(std::shared_ptr<T> val) {return vx_collection::t_is_list;}

    vx_core::Func_any_from_any vx_collection::Class_is_list::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_collection::Class_is_list::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_collection::f_is_list(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_collection::Class_is_list::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any val = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_collection::f_is_list(val);
      return output;
    }

    vx_core::Type_boolean vx_collection::Class_is_list::vx_f_is_list(vx_core::Type_any val) {
      return vx_collection::f_is_list(val);
    }

  //}

  vx_collection::Func_is_list vx_collection::e_is_list = std::make_shared<vx_collection::Class_is_list>();
  vx_collection::Func_is_list vx_collection::t_is_list = std::make_shared<vx_collection::Class_is_list>();

  vx_core::Type_boolean vx_collection::f_is_list(vx_core::Type_any val) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_core::f_eq(
      vx_core::t_string->vx_new_from_string(":list"),
      vx_core::f_extends_from_any(val)
    );
    return output;
  }

  /**
   * @function is_map
   * Returns true if the given value is a map.
   * @param  {any} val Any value
   * @return {boolean}
   * (func is-map)
   */
  //class Func_is_map {

    template <class T> std::shared_ptr<T> vx_collection::Class_is_map::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_collection::Func_is_map output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_collection::Class_is_map::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_collection::Func_is_map output;
      return output;
    }

    vx_core::Type_typedef vx_collection::Class_is_map::vx_typedef() {return vx_collection::t_is_map->vx_typedef();}

    vx_core::Type_funcdef vx_collection::Class_is_map::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/collection", // pkgname
        "is-map", // name
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

    template <class T> std::shared_ptr<T> vx_collection::Class_is_map::vx_empty(std::shared_ptr<T> val) {return vx_collection::e_is_map;}
    template <class T> std::shared_ptr<T> vx_collection::Class_is_map::vx_type(std::shared_ptr<T> val) {return vx_collection::t_is_map;}

    vx_core::Func_any_from_any vx_collection::Class_is_map::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_collection::Class_is_map::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_collection::f_is_map(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_collection::Class_is_map::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any val = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_collection::f_is_map(val);
      return output;
    }

    vx_core::Type_boolean vx_collection::Class_is_map::vx_f_is_map(vx_core::Type_any val) {
      return vx_collection::f_is_map(val);
    }

  //}

  vx_collection::Func_is_map vx_collection::e_is_map = std::make_shared<vx_collection::Class_is_map>();
  vx_collection::Func_is_map vx_collection::t_is_map = std::make_shared<vx_collection::Class_is_map>();

  vx_core::Type_boolean vx_collection::f_is_map(vx_core::Type_any val) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_core::f_eq(
      vx_core::t_string->vx_new_from_string(":map"),
      vx_core::f_extends_from_any(val)
    );
    return output;
  }

  /**
   * @function list_from_list_end
   * Returns a sub list from positions 0 to end.
   * @param  {list-1} values
   * @param  {int} end
   * @return {list-1}
   * (func list<-list-end)
   */
  //class Func_list_from_list_end {

    template <class T> std::shared_ptr<T> vx_collection::Class_list_from_list_end::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_collection::Func_list_from_list_end output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_collection::Class_list_from_list_end::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_collection::Func_list_from_list_end output;
      return output;
    }

    vx_core::Type_typedef vx_collection::Class_list_from_list_end::vx_typedef() {return vx_collection::t_list_from_list_end->vx_typedef();}

    vx_core::Type_funcdef vx_collection::Class_list_from_list_end::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/collection", // pkgname
        "list<-list-end", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "list-1", // name
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

    template <class T> std::shared_ptr<T> vx_collection::Class_list_from_list_end::vx_empty(std::shared_ptr<T> val) {return vx_collection::e_list_from_list_end;}
    template <class T> std::shared_ptr<T> vx_collection::Class_list_from_list_end::vx_type(std::shared_ptr<T> val) {return vx_collection::t_list_from_list_end;}

    vx_core::Type_any vx_collection::Class_list_from_list_end::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_list generic_list_1 = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_list values = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int end = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_collection::f_list_from_list_end(generic_list_1, values, end);
      return output;
    }

    template <class X> std::shared_ptr<X> vx_collection::Class_list_from_list_end::vx_f_list_from_list_end(std::shared_ptr<X> generic_list_1, std::shared_ptr<X> values, vx_core::Type_int end) {
      return vx_collection::f_list_from_list_end(generic_list_1, values, end);
    }

  //}

  vx_collection::Func_list_from_list_end vx_collection::e_list_from_list_end = std::make_shared<vx_collection::Class_list_from_list_end>();
  vx_collection::Func_list_from_list_end vx_collection::t_list_from_list_end = std::make_shared<vx_collection::Class_list_from_list_end>();

  template <class X> std::shared_ptr<X> vx_collection::f_list_from_list_end(std::shared_ptr<X> generic_list_1, std::shared_ptr<X> values, vx_core::Type_int end) {
    std::shared_ptr<X> output = vx_core::f_empty(generic_list_1);
    output = vx_collection::f_list_from_list_start_end(generic_list_1, values, vx_core::t_int->vx_new_from_int(0), end);
    return output;
  }

  /**
   * @function list_from_list_filtertypes
   * Filter List to only include matching types
   * @param  {list-2} vallist
   * @param  {typelist} filtertypes
   * @return {list-1}
   * (func list<-list-filtertypes)
   */
  //class Func_list_from_list_filtertypes {

    template <class T> std::shared_ptr<T> vx_collection::Class_list_from_list_filtertypes::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_collection::Func_list_from_list_filtertypes output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_collection::Class_list_from_list_filtertypes::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_collection::Func_list_from_list_filtertypes output;
      return output;
    }

    vx_core::Type_typedef vx_collection::Class_list_from_list_filtertypes::vx_typedef() {return vx_collection::t_list_from_list_filtertypes->vx_typedef();}

    vx_core::Type_funcdef vx_collection::Class_list_from_list_filtertypes::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/collection", // pkgname
        "list<-list-filtertypes", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "list-1", // name
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

    template <class T> std::shared_ptr<T> vx_collection::Class_list_from_list_filtertypes::vx_empty(std::shared_ptr<T> val) {return vx_collection::e_list_from_list_filtertypes;}
    template <class T> std::shared_ptr<T> vx_collection::Class_list_from_list_filtertypes::vx_type(std::shared_ptr<T> val) {return vx_collection::t_list_from_list_filtertypes;}

    vx_core::Type_any vx_collection::Class_list_from_list_filtertypes::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_list generic_list_1 = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_list vallist = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_typelist filtertypes = vx_core::f_any_from_any(vx_core::t_typelist, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_collection::f_list_from_list_filtertypes(generic_list_1, vallist, filtertypes);
      return output;
    }

    template <class X, class Y> std::shared_ptr<X> vx_collection::Class_list_from_list_filtertypes::vx_f_list_from_list_filtertypes(std::shared_ptr<X> generic_list_1, std::shared_ptr<Y> vallist, vx_core::Type_typelist filtertypes) {
      return vx_collection::f_list_from_list_filtertypes(generic_list_1, vallist, filtertypes);
    }

  //}

  vx_collection::Func_list_from_list_filtertypes vx_collection::e_list_from_list_filtertypes = std::make_shared<vx_collection::Class_list_from_list_filtertypes>();
  vx_collection::Func_list_from_list_filtertypes vx_collection::t_list_from_list_filtertypes = std::make_shared<vx_collection::Class_list_from_list_filtertypes>();

  template <class X, class Y> std::shared_ptr<X> vx_collection::f_list_from_list_filtertypes(std::shared_ptr<X> generic_list_1, std::shared_ptr<Y> vallist, vx_core::Type_typelist filtertypes) {
    std::shared_ptr<X> output = vx_core::f_empty(generic_list_1);
    output = vx_collection::f_list_from_list_fn_filter(
      generic_list_1,
      vallist,
      vx_core::t_any_from_any->fn_new([filtertypes](vx_core::Type_any val_any) {
        vx_core::Type_any val = vx_core::f_any_from_any(vx_core::t_any, val_any);
        return 
          vx_core::f_if(
            vx_core::t_any,
            vx_type::f_is_type_from_any_typelist(val, filtertypes),
            val
          );
      })
    );
    return output;
  }

  /**
   * @function list_from_list_fn_filter
   * Filter List to only include non-empty values
   * @param  {list-2} vallist
   * @param  {any<-any} fn-filter
   * @return {list-1}
   * (func list<-list-fn-filter)
   */
  //class Func_list_from_list_fn_filter {

    template <class T> std::shared_ptr<T> vx_collection::Class_list_from_list_fn_filter::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_collection::Func_list_from_list_fn_filter output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_collection::Class_list_from_list_fn_filter::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_collection::Func_list_from_list_fn_filter output;
      return output;
    }

    vx_core::Type_typedef vx_collection::Class_list_from_list_fn_filter::vx_typedef() {return vx_collection::t_list_from_list_fn_filter->vx_typedef();}

    vx_core::Type_funcdef vx_collection::Class_list_from_list_fn_filter::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/collection", // pkgname
        "list<-list-fn-filter", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "list-1", // name
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

    template <class T> std::shared_ptr<T> vx_collection::Class_list_from_list_fn_filter::vx_empty(std::shared_ptr<T> val) {return vx_collection::e_list_from_list_fn_filter;}
    template <class T> std::shared_ptr<T> vx_collection::Class_list_from_list_fn_filter::vx_type(std::shared_ptr<T> val) {return vx_collection::t_list_from_list_fn_filter;}

    vx_core::Type_any vx_collection::Class_list_from_list_fn_filter::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_list generic_list_1 = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_list vallist = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Func_any_from_any fn_filter = vx_core::f_any_from_any(vx_core::t_any_from_any, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_collection::f_list_from_list_fn_filter(generic_list_1, vallist, fn_filter);
      return output;
    }

    template <class X, class Y> std::shared_ptr<X> vx_collection::Class_list_from_list_fn_filter::vx_f_list_from_list_fn_filter(std::shared_ptr<X> generic_list_1, std::shared_ptr<Y> vallist, vx_core::Func_any_from_any fn_filter) {
      return vx_collection::f_list_from_list_fn_filter(generic_list_1, vallist, fn_filter);
    }

  //}

  vx_collection::Func_list_from_list_fn_filter vx_collection::e_list_from_list_fn_filter = std::make_shared<vx_collection::Class_list_from_list_fn_filter>();
  vx_collection::Func_list_from_list_fn_filter vx_collection::t_list_from_list_fn_filter = std::make_shared<vx_collection::Class_list_from_list_fn_filter>();

  template <class X, class Y> std::shared_ptr<X> vx_collection::f_list_from_list_fn_filter(std::shared_ptr<X> generic_list_1, std::shared_ptr<Y> vallist, vx_core::Func_any_from_any fn_filter) {
    std::shared_ptr<X> output = vx_core::f_empty(generic_list_1);
    return output;
  }

  /**
   * @function list_from_list_start
   * Returns a sub list from start to list end.
   * @param  {list-1} values
   * @param  {int} start
   * @return {list-1}
   * (func list<-list-start)
   */
  //class Func_list_from_list_start {

    template <class T> std::shared_ptr<T> vx_collection::Class_list_from_list_start::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_collection::Func_list_from_list_start output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_collection::Class_list_from_list_start::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_collection::Func_list_from_list_start output;
      return output;
    }

    vx_core::Type_typedef vx_collection::Class_list_from_list_start::vx_typedef() {return vx_collection::t_list_from_list_start->vx_typedef();}

    vx_core::Type_funcdef vx_collection::Class_list_from_list_start::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/collection", // pkgname
        "list<-list-start", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "list-1", // name
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

    template <class T> std::shared_ptr<T> vx_collection::Class_list_from_list_start::vx_empty(std::shared_ptr<T> val) {return vx_collection::e_list_from_list_start;}
    template <class T> std::shared_ptr<T> vx_collection::Class_list_from_list_start::vx_type(std::shared_ptr<T> val) {return vx_collection::t_list_from_list_start;}

    vx_core::Type_any vx_collection::Class_list_from_list_start::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_list generic_list_1 = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_list values = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int start = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_collection::f_list_from_list_start(generic_list_1, values, start);
      return output;
    }

    template <class X> std::shared_ptr<X> vx_collection::Class_list_from_list_start::vx_f_list_from_list_start(std::shared_ptr<X> generic_list_1, std::shared_ptr<X> values, vx_core::Type_int start) {
      return vx_collection::f_list_from_list_start(generic_list_1, values, start);
    }

  //}

  vx_collection::Func_list_from_list_start vx_collection::e_list_from_list_start = std::make_shared<vx_collection::Class_list_from_list_start>();
  vx_collection::Func_list_from_list_start vx_collection::t_list_from_list_start = std::make_shared<vx_collection::Class_list_from_list_start>();

  template <class X> std::shared_ptr<X> vx_collection::f_list_from_list_start(std::shared_ptr<X> generic_list_1, std::shared_ptr<X> values, vx_core::Type_int start) {
    std::shared_ptr<X> output = vx_core::f_empty(generic_list_1);
    output = vx_collection::f_list_from_list_start_end(
      generic_list_1,
      values,
      start,
      vx_core::f_length_from_list(values)
    );
    return output;
  }

  /**
   * @function list_from_list_start_end
   * Returns a list from another list
   * @param  {list-1} values
   * @param  {int} start
   * @param  {int} end
   * @return {list-1}
   * (func list<-list-start-end)
   */
  //class Func_list_from_list_start_end {

    template <class T> std::shared_ptr<T> vx_collection::Class_list_from_list_start_end::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_collection::Func_list_from_list_start_end output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_collection::Class_list_from_list_start_end::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_collection::Func_list_from_list_start_end output;
      return output;
    }

    vx_core::Type_typedef vx_collection::Class_list_from_list_start_end::vx_typedef() {return vx_collection::t_list_from_list_start_end->vx_typedef();}

    vx_core::Type_funcdef vx_collection::Class_list_from_list_start_end::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/collection", // pkgname
        "list<-list-start-end", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "list-1", // name
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

    template <class T> std::shared_ptr<T> vx_collection::Class_list_from_list_start_end::vx_empty(std::shared_ptr<T> val) {return vx_collection::e_list_from_list_start_end;}
    template <class T> std::shared_ptr<T> vx_collection::Class_list_from_list_start_end::vx_type(std::shared_ptr<T> val) {return vx_collection::t_list_from_list_start_end;}

    vx_core::Type_any vx_collection::Class_list_from_list_start_end::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_list generic_list_1 = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_list values = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int start = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(1)));
      vx_core::Type_int end = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(2)));
      output = vx_collection::f_list_from_list_start_end(generic_list_1, values, start, end);
      return output;
    }

    template <class X> std::shared_ptr<X> vx_collection::Class_list_from_list_start_end::vx_f_list_from_list_start_end(std::shared_ptr<X> generic_list_1, std::shared_ptr<X> values, vx_core::Type_int start, vx_core::Type_int end) {
      return vx_collection::f_list_from_list_start_end(generic_list_1, values, start, end);
    }

  //}

  vx_collection::Func_list_from_list_start_end vx_collection::e_list_from_list_start_end = std::make_shared<vx_collection::Class_list_from_list_start_end>();
  vx_collection::Func_list_from_list_start_end vx_collection::t_list_from_list_start_end = std::make_shared<vx_collection::Class_list_from_list_start_end>();

  template <class X> std::shared_ptr<X> vx_collection::f_list_from_list_start_end(std::shared_ptr<X> generic_list_1, std::shared_ptr<X> values, vx_core::Type_int start, vx_core::Type_int end) {
    std::shared_ptr<X> output = vx_core::f_empty(generic_list_1);
    return output;
  }


//}
