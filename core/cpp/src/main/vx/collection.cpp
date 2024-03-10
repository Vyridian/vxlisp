#include "../vx/core.hpp"
#include "../vx/type.hpp"
#include "collection.hpp"

namespace vx_collection {

// :body

  // vx_any_from_for_until_loop_max(generic_any_1, start, fn-until, fn-loop, max)
  vx_core::Type_any vx_any_from_for_until_loop_max(vx_core::Type_any generic_any_1, vx_core::Type_any start, vx_core::Func_boolean_from_any fn_until, vx_core::Func_any_from_any fn_loop, vx_core::Type_int max) {
		  vx_core::Type_any output = start;
    bool iscontinue = true;
    int icount = 0;
    int imax = max->vx_int();
		  vx_core::Type_any current = start;
    while (iscontinue) {
      if (icount >= imax) {
        iscontinue = false;
      } else {
        icount += 1;
        vx_core::Type_any previous = current;
        vx_core::vx_reserve(previous);
        current = fn_loop->vx_any_from_any(previous);
        vx_core::vx_release_one_except(previous, current);
        vx_core::vx_ref_plus(current);
        vx_core::Type_boolean valcontinue = fn_until->vx_boolean_from_any(current);
        vx_core::vx_ref_minus(current);
        iscontinue = !valcontinue->vx_boolean();
        vx_core::vx_release(valcontinue);
        output = current;
      }
    }
    vx_core::vx_release_except({start, fn_until, fn_loop, max}, output);
	  	return output;
	 }

  // vx_any_from_for_while_loop_max(generic_any_1, start, fn-while, fn-loop, max)
  vx_core::Type_any vx_any_from_for_while_loop_max(vx_core::Type_any generic_any_1, vx_core::Type_any start, vx_core::Func_boolean_from_any fn_while, vx_core::Func_any_from_any fn_loop, vx_core::Type_int max) {
		vx_core::Type_any output = start;
    bool iscontinue = true;
    long icount = 0;
    long imax = max->vx_int();
		  vx_core::Type_any current = start;
    while (iscontinue) {
      if (icount >= imax) {
        iscontinue = false;
      } else {
        icount += 1;
        vx_core::vx_ref_plus(current);
        vx_core::Type_boolean valcontinue = fn_while->vx_boolean_from_any(current);
        vx_core::vx_ref_minus(current);
        iscontinue = valcontinue->vx_boolean();
        vx_core::vx_release_except(valcontinue, current);
        if (iscontinue) {
          vx_core::Type_any previous = current;
          vx_core::vx_reserve(previous);
          current = fn_loop->vx_any_from_any(previous);
          vx_core::vx_release_one_except(previous, current);
        }
      }
    }
    output = current;
    vx_core::vx_release_except({start, fn_while, fn_loop, max}, output);
		  return output;
 	}

  // vx_list_from_for_end_loop(generic_list_1, start, end, fn-loop)
  vx_core::Type_any vx_list_from_for_end_loop(vx_core::Type_any generic_list_1, vx_core::Type_int start, vx_core::Type_int end, vx_core::Func_any_from_int fn_loop) {
  		vx_core::Type_any output = vx_core::f_empty(generic_list_1);
    vx_core::vx_Type_listany listvals;
    long istart = start->vx_int();
    long iend = end->vx_int();
    if (istart <= iend) {
      for (int i = istart; i <= iend; i++) {
        vx_core::Type_any val = fn_loop->vx_any_from_int(vx_core::vx_new_int(i));
        listvals.push_back(val);
      }
    } else {
      for (int i = istart; i >= iend; i--) {
        vx_core::Type_any val = fn_loop->vx_any_from_int(vx_core::vx_new_int(i));
        listvals.push_back(val);
      }
    }
    if (listvals.size() > 0) {
      output = generic_list_1->vx_new(listvals);
    }
    vx_core::vx_release_except({start, end, fn_loop}, output);
		  return output;
	 }

  // vx_list_from_for_while_loop_max(generic_list_1, start, fn-while, fn-loop, max)
  vx_core::Type_any vx_list_from_for_while_loop_max(vx_core::Type_any generic_list_1, vx_core::Type_any start, vx_core::Func_boolean_from_any fn_while, vx_core::Func_any_from_any fn_loop, vx_core::Type_int max) {
		  vx_core::Type_any output = vx_core::f_empty(generic_list_1);
    vx_core::vx_Type_listany listvals;
    bool iscontinue = true;
    long icount = 0;
    long imax = max->vx_int();
    vx_core::Type_any work = start;
    while (iscontinue) {
      if (icount >= imax) {
        iscontinue = false;
      } else {
        vx_core::Type_boolean valwhile = fn_while->vx_boolean_from_any(work);
        iscontinue = !valwhile->vx_boolean();
        if (iscontinue) {
          icount += 1;
          work = fn_loop->vx_any_from_any(work);
          listvals.push_back(work);
        }
        vx_core::vx_release(valwhile);
      }
    }
    if (listvals.size() > 0) {
      output = generic_list_1->vx_new(listvals);
    }
    vx_core::vx_release_except({start, fn_while, fn_loop, max}, output);
		  return output;
 	}

  // vx_list_from_list_filter(generic_list_1, list, fn-any<-any)
  vx_core::Type_any vx_list_from_list_filter(vx_core::Type_any generic_list_1, vx_core::Type_list vallist, vx_core::Func_any_from_any fn_filter) {
    vx_core::vx_reserve({vallist, fn_filter});
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
    vx_core::vx_release_one_except({vallist, fn_filter}, output);
		  return output;
 	}

  // vx_list_from_list_start_end(generic_list_1, list, int, int)
  vx_core::Type_any vx_list_from_list_start_end(vx_core::Type_any generic_list_1, vx_core::Type_list values, vx_core::Type_int start, vx_core::Type_int end) {
	  	vx_core::Type_any output = vx_core::vx_empty(generic_list_1);
    long istart = start->vx_int();
    long iend = end->vx_int();
    vx_core::vx_Type_listany listval = values->vx_list();
    long maxlen = vx_core::vx_int_from_sizet(listval.size());
    if (iend < 0) {
      iend += maxlen;
    }
    if (istart < 1) {
    } else if (istart > iend) {
    } else if (istart > maxlen) {
    } else {
      if (iend >= maxlen) {
        iend = maxlen;
      }
	   		auto first = listval.begin() + istart - 1;
      auto last = listval.begin() + iend;
      vx_core::vx_Type_listany listsub = std::vector(first, last);
      output = generic_list_1->vx_new(listsub);
    }
    vx_core::vx_release_except({values, start, end}, output);
		  return output;
	}

  /**
   * @function any_from_for_until_loop_max
   * Returns a value using a until loop.
   * output : any-1 := start
   * count : int := 0
   * (while continue
   *   continue : boolean := (count <= max)
   *   (if continue
   *     count += 1
   *     output = (fn-loop output)
   *     continue = (fn-until output)))
   * @param  {any-1} start
   * @param  {boolean<-any} fn-until
   * @param  {any<-any} fn-loop
   * @param  {int} max
   * @return {any-1}
   * (func any<-for-until-loop-max)
   */
  // (func any<-for-until-loop-max)
  // class Class_any_from_for_until_loop_max {
    Abstract_any_from_for_until_loop_max::~Abstract_any_from_for_until_loop_max() {}

    Class_any_from_for_until_loop_max::Class_any_from_for_until_loop_max() : Abstract_any_from_for_until_loop_max::Abstract_any_from_for_until_loop_max() {
      vx_core::refcount += 1;
    }

    Class_any_from_for_until_loop_max::~Class_any_from_for_until_loop_max() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_any_from_for_until_loop_max::vx_new(vx_core::vx_Type_listany vals) const {
      vx_collection::Func_any_from_for_until_loop_max output = vx_collection::e_any_from_for_until_loop_max;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_any_from_for_until_loop_max::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_collection::Func_any_from_for_until_loop_max output = vx_collection::e_any_from_for_until_loop_max;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_any_from_for_until_loop_max::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/collection", // pkgname
        "any<-for-until-loop-max", // name
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

    vx_core::Type_constdef Class_any_from_for_until_loop_max::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_any_from_for_until_loop_max::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/collection", // pkgname
        "any<-for-until-loop-max", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_any_from_for_until_loop_max::vx_empty() const {return vx_collection::e_any_from_for_until_loop_max;}
    vx_core::Type_any Class_any_from_for_until_loop_max::vx_type() const {return vx_collection::t_any_from_for_until_loop_max;}
    vx_core::Type_msgblock Class_any_from_for_until_loop_max::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_for_until_loop_max::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_any_from_for_until_loop_max::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any start = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_boolean_from_any fn_until = vx_core::vx_any_from_any(vx_core::t_boolean_from_any, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Func_any_from_any fn_loop = vx_core::vx_any_from_any(vx_core::t_any_from_any, arglist->vx_get_any(vx_core::vx_new_int(2)));
      vx_core::Type_int max = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(3)));
      output = vx_collection::f_any_from_for_until_loop_max(generic_any_1, start, fn_until, fn_loop, max);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}
  /**
   * @function any_from_for_until_loop
   * Returns a value using an until loop. Maximum 10000 times.
   * @param  {any-1} start
   * @param  {boolean<-any} fn-until
   * @param  {any<-any} fn-loop
   * @return {any-1}
   * (func any<-for-until-loop)
   */
  // (func any<-for-until-loop)
  // class Class_any_from_for_until_loop {
    Abstract_any_from_for_until_loop::~Abstract_any_from_for_until_loop() {}

    Class_any_from_for_until_loop::Class_any_from_for_until_loop() : Abstract_any_from_for_until_loop::Abstract_any_from_for_until_loop() {
      vx_core::refcount += 1;
    }

    Class_any_from_for_until_loop::~Class_any_from_for_until_loop() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_any_from_for_until_loop::vx_new(vx_core::vx_Type_listany vals) const {
      vx_collection::Func_any_from_for_until_loop output = vx_collection::e_any_from_for_until_loop;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_any_from_for_until_loop::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_collection::Func_any_from_for_until_loop output = vx_collection::e_any_from_for_until_loop;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_any_from_for_until_loop::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/collection", // pkgname
        "any<-for-until-loop", // name
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

    vx_core::Type_constdef Class_any_from_for_until_loop::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_any_from_for_until_loop::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/collection", // pkgname
        "any<-for-until-loop", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_any_from_for_until_loop::vx_empty() const {return vx_collection::e_any_from_for_until_loop;}
    vx_core::Type_any Class_any_from_for_until_loop::vx_type() const {return vx_collection::t_any_from_for_until_loop;}
    vx_core::Type_msgblock Class_any_from_for_until_loop::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_for_until_loop::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_any_from_for_until_loop::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any start = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_boolean_from_any fn_until = vx_core::vx_any_from_any(vx_core::t_boolean_from_any, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Func_any_from_any fn_loop = vx_core::vx_any_from_any(vx_core::t_any_from_any, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_collection::f_any_from_for_until_loop(generic_any_1, start, fn_until, fn_loop);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}
  /**
   * @function any_from_for_while_loop_max
   * Returns a value using a while loop.
   * output : any-1 := start
   * count : int := 0
   * (while continue
   *  continue : boolean := (count <= max)
   *  (if continue
   *   continue = (fn-while output)
   *   (if continue
   *    count += 1
   *    output = (fn-loop output))))
   * @param  {any-1} start
   * @param  {boolean<-any} fn-while
   * @param  {any<-any} fn-loop
   * @param  {int} max
   * @return {any-1}
   * (func any<-for-while-loop-max)
   */
  // (func any<-for-while-loop-max)
  // class Class_any_from_for_while_loop_max {
    Abstract_any_from_for_while_loop_max::~Abstract_any_from_for_while_loop_max() {}

    Class_any_from_for_while_loop_max::Class_any_from_for_while_loop_max() : Abstract_any_from_for_while_loop_max::Abstract_any_from_for_while_loop_max() {
      vx_core::refcount += 1;
    }

    Class_any_from_for_while_loop_max::~Class_any_from_for_while_loop_max() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_any_from_for_while_loop_max::vx_new(vx_core::vx_Type_listany vals) const {
      vx_collection::Func_any_from_for_while_loop_max output = vx_collection::e_any_from_for_while_loop_max;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_any_from_for_while_loop_max::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_collection::Func_any_from_for_while_loop_max output = vx_collection::e_any_from_for_while_loop_max;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_any_from_for_while_loop_max::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/collection", // pkgname
        "any<-for-while-loop-max", // name
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

    vx_core::Type_constdef Class_any_from_for_while_loop_max::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_any_from_for_while_loop_max::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/collection", // pkgname
        "any<-for-while-loop-max", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_any_from_for_while_loop_max::vx_empty() const {return vx_collection::e_any_from_for_while_loop_max;}
    vx_core::Type_any Class_any_from_for_while_loop_max::vx_type() const {return vx_collection::t_any_from_for_while_loop_max;}
    vx_core::Type_msgblock Class_any_from_for_while_loop_max::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_for_while_loop_max::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_any_from_for_while_loop_max::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any start = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_boolean_from_any fn_while = vx_core::vx_any_from_any(vx_core::t_boolean_from_any, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Func_any_from_any fn_loop = vx_core::vx_any_from_any(vx_core::t_any_from_any, arglist->vx_get_any(vx_core::vx_new_int(2)));
      vx_core::Type_int max = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(3)));
      output = vx_collection::f_any_from_for_while_loop_max(generic_any_1, start, fn_while, fn_loop, max);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}
  /**
   * @function any_from_for_while_loop
   * Returns a value using a while loop. Maximum 1000 times.
   * @param  {any-1} start
   * @param  {boolean<-any} fn-while
   * @param  {any<-any} fn-loop
   * @return {any-1}
   * (func any<-for-while-loop)
   */
  // (func any<-for-while-loop)
  // class Class_any_from_for_while_loop {
    Abstract_any_from_for_while_loop::~Abstract_any_from_for_while_loop() {}

    Class_any_from_for_while_loop::Class_any_from_for_while_loop() : Abstract_any_from_for_while_loop::Abstract_any_from_for_while_loop() {
      vx_core::refcount += 1;
    }

    Class_any_from_for_while_loop::~Class_any_from_for_while_loop() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_any_from_for_while_loop::vx_new(vx_core::vx_Type_listany vals) const {
      vx_collection::Func_any_from_for_while_loop output = vx_collection::e_any_from_for_while_loop;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_any_from_for_while_loop::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_collection::Func_any_from_for_while_loop output = vx_collection::e_any_from_for_while_loop;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_any_from_for_while_loop::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/collection", // pkgname
        "any<-for-while-loop", // name
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

    vx_core::Type_constdef Class_any_from_for_while_loop::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_any_from_for_while_loop::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/collection", // pkgname
        "any<-for-while-loop", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_any_from_for_while_loop::vx_empty() const {return vx_collection::e_any_from_for_while_loop;}
    vx_core::Type_any Class_any_from_for_while_loop::vx_type() const {return vx_collection::t_any_from_for_while_loop;}
    vx_core::Type_msgblock Class_any_from_for_while_loop::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_for_while_loop::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_any_from_for_while_loop::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any start = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_boolean_from_any fn_while = vx_core::vx_any_from_any(vx_core::t_boolean_from_any, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Func_any_from_any fn_loop = vx_core::vx_any_from_any(vx_core::t_any_from_any, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_collection::f_any_from_for_while_loop(generic_any_1, start, fn_while, fn_loop);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}
  /**
   * @function list_from_for_while_loop_max
   * Returns a list of any-1 using a while loop.
   * 1. output : list-1 := (empty list-1)
   * 2. value : any-1 := start.
   * 3. value : any-1 := (fn-loop value).
   * 4. check : boolean := (fn-while value).
   * 5. if (= check true) output := (copy output value), Go to 3 (Maximum max times).
   * 6. else end.
   * @param  {any-1} start
   * @param  {boolean<-any} fn-while
   * @param  {any<-any} fn-loop
   * @param  {int} max
   * @return {list-1}
   * (func list<-for-while-loop-max)
   */
  // (func list<-for-while-loop-max)
  // class Class_list_from_for_while_loop_max {
    Abstract_list_from_for_while_loop_max::~Abstract_list_from_for_while_loop_max() {}

    Class_list_from_for_while_loop_max::Class_list_from_for_while_loop_max() : Abstract_list_from_for_while_loop_max::Abstract_list_from_for_while_loop_max() {
      vx_core::refcount += 1;
    }

    Class_list_from_for_while_loop_max::~Class_list_from_for_while_loop_max() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_list_from_for_while_loop_max::vx_new(vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_for_while_loop_max output = vx_collection::e_list_from_for_while_loop_max;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_list_from_for_while_loop_max::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_for_while_loop_max output = vx_collection::e_list_from_for_while_loop_max;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_list_from_for_while_loop_max::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/collection", // pkgname
        "list<-for-while-loop-max", // name
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

    vx_core::Type_constdef Class_list_from_for_while_loop_max::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_list_from_for_while_loop_max::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/collection", // pkgname
        "list<-for-while-loop-max", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_list_from_for_while_loop_max::vx_empty() const {return vx_collection::e_list_from_for_while_loop_max;}
    vx_core::Type_any Class_list_from_for_while_loop_max::vx_type() const {return vx_collection::t_list_from_for_while_loop_max;}
    vx_core::Type_msgblock Class_list_from_for_while_loop_max::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_list_from_for_while_loop_max::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_list_from_for_while_loop_max::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_list generic_list_1 = vx_core::vx_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any start = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_boolean_from_any fn_while = vx_core::vx_any_from_any(vx_core::t_boolean_from_any, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Func_any_from_any fn_loop = vx_core::vx_any_from_any(vx_core::t_any_from_any, arglist->vx_get_any(vx_core::vx_new_int(2)));
      vx_core::Type_int max = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(3)));
      output = vx_collection::f_list_from_for_while_loop_max(generic_list_1, start, fn_while, fn_loop, max);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}
  /**
   * @function list_from_for_while_loop
   * Returns a list of any-1 using a while loop. Max: 1000
   * @param  {any-1} start
   * @param  {boolean<-any} fn-while
   * @param  {any<-any} fn-loop
   * @return {list-1}
   * (func list<-for-while-loop)
   */
  // (func list<-for-while-loop)
  // class Class_list_from_for_while_loop {
    Abstract_list_from_for_while_loop::~Abstract_list_from_for_while_loop() {}

    Class_list_from_for_while_loop::Class_list_from_for_while_loop() : Abstract_list_from_for_while_loop::Abstract_list_from_for_while_loop() {
      vx_core::refcount += 1;
    }

    Class_list_from_for_while_loop::~Class_list_from_for_while_loop() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_list_from_for_while_loop::vx_new(vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_for_while_loop output = vx_collection::e_list_from_for_while_loop;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_list_from_for_while_loop::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_for_while_loop output = vx_collection::e_list_from_for_while_loop;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_list_from_for_while_loop::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/collection", // pkgname
        "list<-for-while-loop", // name
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

    vx_core::Type_constdef Class_list_from_for_while_loop::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_list_from_for_while_loop::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/collection", // pkgname
        "list<-for-while-loop", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_list_from_for_while_loop::vx_empty() const {return vx_collection::e_list_from_for_while_loop;}
    vx_core::Type_any Class_list_from_for_while_loop::vx_type() const {return vx_collection::t_list_from_for_while_loop;}
    vx_core::Type_msgblock Class_list_from_for_while_loop::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_list_from_for_while_loop::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_list_from_for_while_loop::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_list generic_list_1 = vx_core::vx_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any start = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_boolean_from_any fn_while = vx_core::vx_any_from_any(vx_core::t_boolean_from_any, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Func_any_from_any fn_loop = vx_core::vx_any_from_any(vx_core::t_any_from_any, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_collection::f_list_from_for_while_loop(generic_list_1, start, fn_while, fn_loop);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}
  /**
   * @function list_from_list_filter
   * Filter List to only include non-empty values
   * @param  {list-2} vallist
   * @param  {any<-any} fn-filter
   * @return {list-1}
   * (func list<-list-filter)
   */
  // (func list<-list-filter)
  // class Class_list_from_list_filter {
    Abstract_list_from_list_filter::~Abstract_list_from_list_filter() {}

    Class_list_from_list_filter::Class_list_from_list_filter() : Abstract_list_from_list_filter::Abstract_list_from_list_filter() {
      vx_core::refcount += 1;
    }

    Class_list_from_list_filter::~Class_list_from_list_filter() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_list_from_list_filter::vx_new(vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_list_filter output = vx_collection::e_list_from_list_filter;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_list_from_list_filter::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_list_filter output = vx_collection::e_list_from_list_filter;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_list_from_list_filter::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/collection", // pkgname
        "list<-list-filter", // name
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

    vx_core::Type_constdef Class_list_from_list_filter::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_list_from_list_filter::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/collection", // pkgname
        "list<-list-filter", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_list_from_list_filter::vx_empty() const {return vx_collection::e_list_from_list_filter;}
    vx_core::Type_any Class_list_from_list_filter::vx_type() const {return vx_collection::t_list_from_list_filter;}
    vx_core::Type_msgblock Class_list_from_list_filter::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_list_from_list_filter::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_list_from_list_filter::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_list generic_list_1 = vx_core::vx_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_list vallist = vx_core::vx_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_any fn_filter = vx_core::vx_any_from_any(vx_core::t_any_from_any, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_collection::f_list_from_list_filter(generic_list_1, vallist, fn_filter);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}
  /**
   * @function list_from_list_start_end
   * Returns a list from another list
   * @param  {list-1} values
   * @param  {int} start
   * @param  {int} end
   * @return {list-1}
   * (func list<-list-start-end)
   */
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

    vx_core::Type_constdef Class_list_from_list_start_end::vx_constdef() const {return this->vx_p_constdef;}

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
  /**
   * @function is_list
   * Returns true if the given value is a list.
   * @param  {any} val Any value
   * @return {boolean}
   * (func is-list)
   */
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

    vx_core::Type_constdef Class_is_list::vx_constdef() const {return this->vx_p_constdef;}

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
  /**
   * @function is_map
   * Returns true if the given value is a map.
   * @param  {any} val Any value
   * @return {boolean}
   * (func is-map)
   */
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

    vx_core::Type_constdef Class_is_map::vx_constdef() const {return this->vx_p_constdef;}

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
  /**
   * @function list_from_for_end_loop
   * Returns a list of any-1 by iterating i from for to next where each item is (loop i).
   * This is similar to a for next loop in other languages.
   * output : list-1 := (empty list-1)
   * (if start <= end
   *  (for i=start to end
   *   val : any-1 := (fn-loop i)
   *   output += val)
   *  (else
   *   (for i=start to end; i--
   *    val : any-1 := (fn-loop i)
   *    output += val)
   *  ))
   * @param  {int} start
   * @param  {int} end
   * @param  {any<-int} fn-loop
   * @return {list-1}
   * (func list<-for-end-loop)
   */
  // (func list<-for-end-loop)
  // class Class_list_from_for_end_loop {
    Abstract_list_from_for_end_loop::~Abstract_list_from_for_end_loop() {}

    Class_list_from_for_end_loop::Class_list_from_for_end_loop() : Abstract_list_from_for_end_loop::Abstract_list_from_for_end_loop() {
      vx_core::refcount += 1;
    }

    Class_list_from_for_end_loop::~Class_list_from_for_end_loop() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_list_from_for_end_loop::vx_new(vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_for_end_loop output = vx_collection::e_list_from_for_end_loop;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_list_from_for_end_loop::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_collection::Func_list_from_for_end_loop output = vx_collection::e_list_from_for_end_loop;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_list_from_for_end_loop::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/collection", // pkgname
        "list<-for-end-loop", // name
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

    vx_core::Type_constdef Class_list_from_for_end_loop::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_list_from_for_end_loop::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/collection", // pkgname
        "list<-for-end-loop", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_list_from_for_end_loop::vx_empty() const {return vx_collection::e_list_from_for_end_loop;}
    vx_core::Type_any Class_list_from_for_end_loop::vx_type() const {return vx_collection::t_list_from_for_end_loop;}
    vx_core::Type_msgblock Class_list_from_for_end_loop::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_list_from_for_end_loop::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_list_from_for_end_loop::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_list generic_list_1 = vx_core::vx_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int start = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int end = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Func_any_from_int fn_loop = vx_core::vx_any_from_any(vx_core::t_any_from_int, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_collection::f_list_from_for_end_loop(generic_list_1, start, end, fn_loop);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}
  /**
   * @function list_from_list_end
   * Returns a sub list from positions 0 to end.
   * @param  {list-1} values
   * @param  {int} end
   * @return {list-1}
   * (func list<-list-end)
   */
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

    vx_core::Type_constdef Class_list_from_list_end::vx_constdef() const {return this->vx_p_constdef;}

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
  /**
   * @function list_from_list_filtertypes
   * Filter List to only include matching types
   * @param  {list-2} vallist
   * @param  {typelist} filtertypes
   * @return {list-1}
   * (func list<-list-filtertypes)
   */
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

    vx_core::Type_constdef Class_list_from_list_filtertypes::vx_constdef() const {return this->vx_p_constdef;}

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
  /**
   * @function list_from_list_start
   * Returns a sub list from start to list end.
   * @param  {list-1} values
   * @param  {int} start
   * @return {list-1}
   * (func list<-list-start)
   */
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

    vx_core::Type_constdef Class_list_from_list_start::vx_constdef() const {return this->vx_p_constdef;}

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

  vx_collection::Func_any_from_for_until_loop_max e_any_from_for_until_loop_max = NULL;
  vx_collection::Func_any_from_for_until_loop_max t_any_from_for_until_loop_max = NULL;
  vx_collection::Func_any_from_for_until_loop e_any_from_for_until_loop = NULL;
  vx_collection::Func_any_from_for_until_loop t_any_from_for_until_loop = NULL;
  vx_collection::Func_any_from_for_while_loop_max e_any_from_for_while_loop_max = NULL;
  vx_collection::Func_any_from_for_while_loop_max t_any_from_for_while_loop_max = NULL;
  vx_collection::Func_any_from_for_while_loop e_any_from_for_while_loop = NULL;
  vx_collection::Func_any_from_for_while_loop t_any_from_for_while_loop = NULL;
  vx_collection::Func_list_from_for_while_loop_max e_list_from_for_while_loop_max = NULL;
  vx_collection::Func_list_from_for_while_loop_max t_list_from_for_while_loop_max = NULL;
  vx_collection::Func_list_from_for_while_loop e_list_from_for_while_loop = NULL;
  vx_collection::Func_list_from_for_while_loop t_list_from_for_while_loop = NULL;
  vx_collection::Func_list_from_list_filter e_list_from_list_filter = NULL;
  vx_collection::Func_list_from_list_filter t_list_from_list_filter = NULL;
  vx_collection::Func_list_from_list_start_end e_list_from_list_start_end = NULL;
  vx_collection::Func_list_from_list_start_end t_list_from_list_start_end = NULL;
  vx_collection::Func_is_list e_is_list = NULL;
  vx_collection::Func_is_list t_is_list = NULL;
  vx_collection::Func_is_map e_is_map = NULL;
  vx_collection::Func_is_map t_is_map = NULL;
  vx_collection::Func_list_from_for_end_loop e_list_from_for_end_loop = NULL;
  vx_collection::Func_list_from_for_end_loop t_list_from_for_end_loop = NULL;
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
      vx_collection::e_any_from_for_until_loop_max = new vx_collection::Class_any_from_for_until_loop_max();
      vx_core::vx_reserve_empty(vx_collection::e_any_from_for_until_loop_max);
      vx_collection::t_any_from_for_until_loop_max = new vx_collection::Class_any_from_for_until_loop_max();
      vx_core::vx_reserve_type(vx_collection::t_any_from_for_until_loop_max);
      vx_collection::e_any_from_for_until_loop = new vx_collection::Class_any_from_for_until_loop();
      vx_core::vx_reserve_empty(vx_collection::e_any_from_for_until_loop);
      vx_collection::t_any_from_for_until_loop = new vx_collection::Class_any_from_for_until_loop();
      vx_core::vx_reserve_type(vx_collection::t_any_from_for_until_loop);
      vx_collection::e_any_from_for_while_loop_max = new vx_collection::Class_any_from_for_while_loop_max();
      vx_core::vx_reserve_empty(vx_collection::e_any_from_for_while_loop_max);
      vx_collection::t_any_from_for_while_loop_max = new vx_collection::Class_any_from_for_while_loop_max();
      vx_core::vx_reserve_type(vx_collection::t_any_from_for_while_loop_max);
      vx_collection::e_any_from_for_while_loop = new vx_collection::Class_any_from_for_while_loop();
      vx_core::vx_reserve_empty(vx_collection::e_any_from_for_while_loop);
      vx_collection::t_any_from_for_while_loop = new vx_collection::Class_any_from_for_while_loop();
      vx_core::vx_reserve_type(vx_collection::t_any_from_for_while_loop);
      vx_collection::e_list_from_for_while_loop_max = new vx_collection::Class_list_from_for_while_loop_max();
      vx_core::vx_reserve_empty(vx_collection::e_list_from_for_while_loop_max);
      vx_collection::t_list_from_for_while_loop_max = new vx_collection::Class_list_from_for_while_loop_max();
      vx_core::vx_reserve_type(vx_collection::t_list_from_for_while_loop_max);
      vx_collection::e_list_from_for_while_loop = new vx_collection::Class_list_from_for_while_loop();
      vx_core::vx_reserve_empty(vx_collection::e_list_from_for_while_loop);
      vx_collection::t_list_from_for_while_loop = new vx_collection::Class_list_from_for_while_loop();
      vx_core::vx_reserve_type(vx_collection::t_list_from_for_while_loop);
      vx_collection::e_list_from_list_filter = new vx_collection::Class_list_from_list_filter();
      vx_core::vx_reserve_empty(vx_collection::e_list_from_list_filter);
      vx_collection::t_list_from_list_filter = new vx_collection::Class_list_from_list_filter();
      vx_core::vx_reserve_type(vx_collection::t_list_from_list_filter);
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
      vx_collection::e_list_from_for_end_loop = new vx_collection::Class_list_from_for_end_loop();
      vx_core::vx_reserve_empty(vx_collection::e_list_from_for_end_loop);
      vx_collection::t_list_from_for_end_loop = new vx_collection::Class_list_from_for_end_loop();
      vx_core::vx_reserve_type(vx_collection::t_list_from_for_end_loop);
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
      vx_core::vx_Type_mapany maptype;
      vx_core::vx_Type_mapany mapconst;
      vx_core::vx_Type_mapfunc mapfunc;
      vx_core::vx_Type_mapany mapempty;
      mapfunc["any<-for-until-loop-max"] = vx_collection::t_any_from_for_until_loop_max;
      mapfunc["any<-for-until-loop"] = vx_collection::t_any_from_for_until_loop;
      mapfunc["any<-for-while-loop-max"] = vx_collection::t_any_from_for_while_loop_max;
      mapfunc["any<-for-while-loop"] = vx_collection::t_any_from_for_while_loop;
      mapfunc["list<-for-while-loop-max"] = vx_collection::t_list_from_for_while_loop_max;
      mapfunc["list<-for-while-loop"] = vx_collection::t_list_from_for_while_loop;
      mapfunc["list<-list-filter"] = vx_collection::t_list_from_list_filter;
      mapfunc["list<-list-start-end"] = vx_collection::t_list_from_list_start_end;
      mapfunc["is-list"] = vx_collection::t_is_list;
      mapfunc["is-map"] = vx_collection::t_is_map;
      mapfunc["list<-for-end-loop"] = vx_collection::t_list_from_for_end_loop;
      mapfunc["list<-list-end"] = vx_collection::t_list_from_list_end;
      mapfunc["list<-list-filtertypes"] = vx_collection::t_list_from_list_filtertypes;
      mapfunc["list<-list-start"] = vx_collection::t_list_from_list_start;
      vx_core::vx_global_package_set("vx/collection", maptype, mapconst, mapfunc);
	   }
  // }

}
