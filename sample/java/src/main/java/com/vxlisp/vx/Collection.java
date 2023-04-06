package com.vxlisp.vx;

import java.util.ArrayList;
import java.util.List;


public final class Collection {

  /**
   * @function is_list
   * Returns true if the given value is a list.
   * @param  {any} val Any value
   * @return {boolean}
   * (func is-list)
   */
  public static interface Func_is_list extends Core.Func_any_from_any {
    public Core.Type_boolean f_is_list(final Core.Type_any val);
  }

  public static class Class_is_list extends Core.Class_base implements Func_is_list {

    @Override
    public Func_is_list vx_new(Object... vals) {
      Class_is_list output = new Class_is_list();
      return output;
    }

    @Override
    public Func_is_list vx_copy(Object... vals) {
      Class_is_list output = new Class_is_list();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/collection", // pkgname
        "is-list", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_is_list vx_empty() {return e_is_list;}
    @Override
    public Func_is_list vx_type() {return t_is_list;}

    @Override
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Collection.f_is_list(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Collection.f_is_list(val);
      return output;
    }

    @Override
    public Core.Type_boolean f_is_list(final Core.Type_any val) {
      return Collection.f_is_list(val);
    }

  }

  public static final Func_is_list e_is_list = new Collection.Class_is_list();
  public static final Func_is_list t_is_list = new Collection.Class_is_list();

  public static Core.Type_boolean f_is_list(final Core.Type_any val) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_eq(
      Core.t_string.vx_new_from_string(":list"),
      Core.f_extends_from_any(val)
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
  public static interface Func_is_map extends Core.Func_any_from_any {
    public Core.Type_boolean f_is_map(final Core.Type_any val);
  }

  public static class Class_is_map extends Core.Class_base implements Func_is_map {

    @Override
    public Func_is_map vx_new(Object... vals) {
      Class_is_map output = new Class_is_map();
      return output;
    }

    @Override
    public Func_is_map vx_copy(Object... vals) {
      Class_is_map output = new Class_is_map();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/collection", // pkgname
        "is-map", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_is_map vx_empty() {return e_is_map;}
    @Override
    public Func_is_map vx_type() {return t_is_map;}

    @Override
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Collection.f_is_map(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Collection.f_is_map(val);
      return output;
    }

    @Override
    public Core.Type_boolean f_is_map(final Core.Type_any val) {
      return Collection.f_is_map(val);
    }

  }

  public static final Func_is_map e_is_map = new Collection.Class_is_map();
  public static final Func_is_map t_is_map = new Collection.Class_is_map();

  public static Core.Type_boolean f_is_map(final Core.Type_any val) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_eq(
      Core.t_string.vx_new_from_string(":map"),
      Core.f_extends_from_any(val)
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
  public static interface Func_list_from_list_end extends Core.Type_func, Core.Type_replfunc {
    public <X extends Core.Type_list> X f_list_from_list_end(final X generic_any_1, final X values, final Core.Type_int end);
  }

  public static class Class_list_from_list_end extends Core.Class_base implements Func_list_from_list_end {

    @Override
    public Func_list_from_list_end vx_new(Object... vals) {
      Class_list_from_list_end output = new Class_list_from_list_end();
      return output;
    }

    @Override
    public Func_list_from_list_end vx_copy(Object... vals) {
      Class_list_from_list_end output = new Class_list_from_list_end();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/collection", // pkgname
        "list<-list-end", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_any), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_list_from_list_end vx_empty() {return e_list_from_list_end;}
    @Override
    public Func_list_from_list_end vx_type() {return t_list_from_list_end;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_list generic_list_1 = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_list values = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_int end = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      output = Collection.f_list_from_list_end(generic_list_1, values, end);
      return output;
    }

    @Override
    public <X extends Core.Type_list> X f_list_from_list_end(final X generic_list_1, final X values, final Core.Type_int end) {
      return Collection.f_list_from_list_end(generic_list_1, values, end);
    }

  }

  public static final Func_list_from_list_end e_list_from_list_end = new Collection.Class_list_from_list_end();
  public static final Func_list_from_list_end t_list_from_list_end = new Collection.Class_list_from_list_end();

  public static <X extends Core.Type_list> X f_list_from_list_end(final X generic_list_1, final X values, final Core.Type_int end) {
    X output = Core.f_empty(generic_list_1);
    output = Collection.f_list_from_list_start_end(generic_list_1, values, Core.t_int.vx_new_from_int(0), end);
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
  public static interface Func_list_from_list_filtertypes extends Core.Type_func, Core.Type_replfunc {
    public <X extends Core.Type_list, Y extends Core.Type_list> X f_list_from_list_filtertypes(final X generic_any_1, final Y vallist, final Core.Type_typelist filtertypes);
  }

  public static class Class_list_from_list_filtertypes extends Core.Class_base implements Func_list_from_list_filtertypes {

    @Override
    public Func_list_from_list_filtertypes vx_new(Object... vals) {
      Class_list_from_list_filtertypes output = new Class_list_from_list_filtertypes();
      return output;
    }

    @Override
    public Func_list_from_list_filtertypes vx_copy(Object... vals) {
      Class_list_from_list_filtertypes output = new Class_list_from_list_filtertypes();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/collection", // pkgname
        "list<-list-filtertypes", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_any), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_list_from_list_filtertypes vx_empty() {return e_list_from_list_filtertypes;}
    @Override
    public Func_list_from_list_filtertypes vx_type() {return t_list_from_list_filtertypes;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_list generic_list_1 = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_list vallist = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_typelist filtertypes = Core.f_any_from_any(Core.t_typelist, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      output = Collection.f_list_from_list_filtertypes(generic_list_1, vallist, filtertypes);
      return output;
    }

    @Override
    public <X extends Core.Type_list, Y extends Core.Type_list> X f_list_from_list_filtertypes(final X generic_list_1, final Y vallist, final Core.Type_typelist filtertypes) {
      return Collection.f_list_from_list_filtertypes(generic_list_1, vallist, filtertypes);
    }

  }

  public static final Func_list_from_list_filtertypes e_list_from_list_filtertypes = new Collection.Class_list_from_list_filtertypes();
  public static final Func_list_from_list_filtertypes t_list_from_list_filtertypes = new Collection.Class_list_from_list_filtertypes();

  public static <X extends Core.Type_list, Y extends Core.Type_list> X f_list_from_list_filtertypes(final X generic_list_1, final Y vallist, final Core.Type_typelist filtertypes) {
    X output = Core.f_empty(generic_list_1);
    output = Collection.f_list_from_list_fn_filter(
      generic_list_1,
      vallist,
      Core.t_any_from_any.fn_new((val_any) -> {
        Core.Type_any val = Core.f_any_from_any(Core.t_any, val_any);
        return 
          Core.f_if(
            Core.t_any,
            Type.f_is_type_from_any_typelist(val, filtertypes),
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
  public static interface Func_list_from_list_fn_filter extends Core.Type_func, Core.Type_replfunc {
    public <X extends Core.Type_list, Y extends Core.Type_list> X f_list_from_list_fn_filter(final X generic_any_1, final Y vallist, final Core.Func_any_from_any fn_filter);
  }

  public static class Class_list_from_list_fn_filter extends Core.Class_base implements Func_list_from_list_fn_filter {

    @Override
    public Func_list_from_list_fn_filter vx_new(Object... vals) {
      Class_list_from_list_fn_filter output = new Class_list_from_list_fn_filter();
      return output;
    }

    @Override
    public Func_list_from_list_fn_filter vx_copy(Object... vals) {
      Class_list_from_list_fn_filter output = new Class_list_from_list_fn_filter();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/collection", // pkgname
        "list<-list-fn-filter", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_any), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_list_from_list_fn_filter vx_empty() {return e_list_from_list_fn_filter;}
    @Override
    public Func_list_from_list_fn_filter vx_type() {return t_list_from_list_fn_filter;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_list generic_list_1 = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_list vallist = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Func_any_from_any fn_filter = Core.f_any_from_any(Core.t_any_from_any, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      output = Collection.f_list_from_list_fn_filter(generic_list_1, vallist, fn_filter);
      return output;
    }

    @Override
    public <X extends Core.Type_list, Y extends Core.Type_list> X f_list_from_list_fn_filter(final X generic_list_1, final Y vallist, final Core.Func_any_from_any fn_filter) {
      return Collection.f_list_from_list_fn_filter(generic_list_1, vallist, fn_filter);
    }

  }

  public static final Func_list_from_list_fn_filter e_list_from_list_fn_filter = new Collection.Class_list_from_list_fn_filter();
  public static final Func_list_from_list_fn_filter t_list_from_list_fn_filter = new Collection.Class_list_from_list_fn_filter();

  public static <X extends Core.Type_list, Y extends Core.Type_list> X f_list_from_list_fn_filter(final X generic_list_1, final Y vallist, final Core.Func_any_from_any fn_filter) {
    X output = Core.f_empty(generic_list_1);
    List<Core.Type_any> listval = vallist.vx_list();
    List<Core.Type_any> items = new ArrayList<>();
    for (Core.Type_any val : listval) {
      Core.Type_any newval = fn_filter.f_any_from_any(Core.t_any, val);
      Core.Type_boolean isempty = Core.f_is_empty_1(newval);
      if (!isempty.vx_boolean()) {
        items.add(newval);
      }
    }
    Core.Type_any work = generic_list_1.vx_new(items);
    output = Core.f_any_from_any(generic_list_1, work);
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
  public static interface Func_list_from_list_start extends Core.Type_func, Core.Type_replfunc {
    public <X extends Core.Type_list> X f_list_from_list_start(final X generic_any_1, final X values, final Core.Type_int start);
  }

  public static class Class_list_from_list_start extends Core.Class_base implements Func_list_from_list_start {

    @Override
    public Func_list_from_list_start vx_new(Object... vals) {
      Class_list_from_list_start output = new Class_list_from_list_start();
      return output;
    }

    @Override
    public Func_list_from_list_start vx_copy(Object... vals) {
      Class_list_from_list_start output = new Class_list_from_list_start();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/collection", // pkgname
        "list<-list-start", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_any), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_list_from_list_start vx_empty() {return e_list_from_list_start;}
    @Override
    public Func_list_from_list_start vx_type() {return t_list_from_list_start;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_list generic_list_1 = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_list values = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_int start = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      output = Collection.f_list_from_list_start(generic_list_1, values, start);
      return output;
    }

    @Override
    public <X extends Core.Type_list> X f_list_from_list_start(final X generic_list_1, final X values, final Core.Type_int start) {
      return Collection.f_list_from_list_start(generic_list_1, values, start);
    }

  }

  public static final Func_list_from_list_start e_list_from_list_start = new Collection.Class_list_from_list_start();
  public static final Func_list_from_list_start t_list_from_list_start = new Collection.Class_list_from_list_start();

  public static <X extends Core.Type_list> X f_list_from_list_start(final X generic_list_1, final X values, final Core.Type_int start) {
    X output = Core.f_empty(generic_list_1);
    output = Collection.f_list_from_list_start_end(
      generic_list_1,
      values,
      start,
      Core.f_length_from_list(values)
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
  public static interface Func_list_from_list_start_end extends Core.Type_func, Core.Type_replfunc {
    public <X extends Core.Type_list> X f_list_from_list_start_end(final X generic_any_1, final X values, final Core.Type_int start, final Core.Type_int end);
  }

  public static class Class_list_from_list_start_end extends Core.Class_base implements Func_list_from_list_start_end {

    @Override
    public Func_list_from_list_start_end vx_new(Object... vals) {
      Class_list_from_list_start_end output = new Class_list_from_list_start_end();
      return output;
    }

    @Override
    public Func_list_from_list_start_end vx_copy(Object... vals) {
      Class_list_from_list_start_end output = new Class_list_from_list_start_end();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/collection", // pkgname
        "list<-list-start-end", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_any), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Func_list_from_list_start_end vx_empty() {return e_list_from_list_start_end;}
    @Override
    public Func_list_from_list_start_end vx_type() {return t_list_from_list_start_end;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_list generic_list_1 = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_list values = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_int start = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      Core.Type_int end = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.t_int.vx_new_from_int(2)));
      output = Collection.f_list_from_list_start_end(generic_list_1, values, start, end);
      return output;
    }

    @Override
    public <X extends Core.Type_list> X f_list_from_list_start_end(final X generic_list_1, final X values, final Core.Type_int start, final Core.Type_int end) {
      return Collection.f_list_from_list_start_end(generic_list_1, values, start, end);
    }

  }

  public static final Func_list_from_list_start_end e_list_from_list_start_end = new Collection.Class_list_from_list_start_end();
  public static final Func_list_from_list_start_end t_list_from_list_start_end = new Collection.Class_list_from_list_start_end();

  public static <X extends Core.Type_list> X f_list_from_list_start_end(final X generic_list_1, final X values, final Core.Type_int start, final Core.Type_int end) {
    X output = Core.f_empty(generic_list_1);
    int istart = start.vx_int();
    int iend = end.vx_int();
    List<Core.Type_any> listval = values.vx_list();
    int isize = listval.size();
    if (isize > 0) {
      if (istart < 0) {
        istart = 0;
      }
      if (iend > isize) {
        iend = isize;
      }
      List<Core.Type_any> listsub = listval.subList(istart, iend);
      Core.Type_any work = generic_list_1.vx_new(listsub);
      output = Core.f_any_from_any(generic_list_1, work);
    };
    return output;
  }


}
