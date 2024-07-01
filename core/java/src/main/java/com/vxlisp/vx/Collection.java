package com.vxlisp.vx;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

public final class Collection {

  public static <T extends Core.Type_any> T vx_any_from_for_until_loop_max(T generic_any_1, T start, Core.Func_boolean_from_any fn_until, Core.Func_any_from_any fn_loop, Core.Type_int max) {
    T output = start;
    boolean iscontinue = true;
    int icount = 0;
    int imax = max.vx_int();
    while (iscontinue) {
      if (icount >= imax) {
        String path = "vx/collection/any<-for-until-loop-max";
        String code = ":loopmaximumexceeded";
        Core.Type_int details = Core.vx_new_int(icount);
        Core.Type_msg msg = Core.vx_msg_from_error(path, code, details);
        output = Core.vx_copy(output, msg);
        iscontinue = false;
      } else {
        icount += 1;
        output = fn_loop.vx_any_from_any(generic_any_1, output);
        Core.Type_boolean valcontinue = fn_until.vx_boolean_from_any(output);
        iscontinue = !valcontinue.vx_boolean();
      }
    }
    return output;
  }

  public static <T extends Core.Type_any> T vx_any_from_for_while_loop_max(T generic_any_1, T start, Core.Func_boolean_from_any fn_while, Core.Func_any_from_any fn_loop, Core.Type_int max) {
    T output = start;
    boolean iscontinue = true;
    int icount = 0;
    int imax = max.vx_int();
    while (iscontinue) {
      if (icount >= imax) {
        String path = "vx/collection/any<-for-while-loop-max";
        String code = ":loopmaximumexceeded";
        Core.Type_int details = Core.vx_new_int(icount);
        Core.Type_msg msg = Core.vx_msg_from_error(path, code, details);
        output = Core.vx_copy(output, msg);
        iscontinue = false;
      } else {
        icount += 1;
        Core.Type_boolean valcontinue = fn_while.vx_boolean_from_any(output);
        iscontinue = valcontinue.vx_boolean();
        if (iscontinue) {
          output = fn_loop.vx_any_from_any(generic_any_1, output);
        }
      }
    }
    return output;
  }

  public static <T extends Core.Type_list> T vx_list_from_for_end_loop(T generic_list_1, Core.Type_int start, Core.Type_int end, Core.Func_any_from_int fn_loop) {
    T output = Core.f_empty(generic_list_1);
    List<Core.Type_any> listvals = new ArrayList<>();
    int istart = start.vx_int();
    int iend = end.vx_int();
    if (istart <= iend) {
      for (int i = istart; i <= iend; i++) {
        Core.Type_any val = fn_loop.vx_any_from_int(Core.t_any, Core.vx_new_int(i));
        listvals.add(val);
      }
    } else {
      for (int i = istart; i >= iend; i--) {
        Core.Type_any val = fn_loop.vx_any_from_int(Core.t_any, Core.vx_new_int(i));
        listvals.add(val);
      }
    }
    if (listvals.size() > 0) {
      Core.Type_anylist anylist = Core.vx_new(Core.t_anylist, listvals);
      output = Core.f_new(generic_list_1, anylist);
    }
    return output;
  }

  public static <T extends Core.Type_list> T vx_list_from_for_while_loop_max(T generic_list_1, Core.Type_any start, Core.Func_boolean_from_any fn_while, Core.Func_any_from_any fn_loop, Core.Type_int max) {
    T output = Core.f_empty(generic_list_1);
    List<Core.Type_any> listvals = new ArrayList<>();
    boolean iscontinue = true;
    int icount = 0;
    int imax = max.vx_int();
    Core.Type_any work = start;
    while (iscontinue) {
      if (icount >= imax) {
        String path = "vx/collection/list<-for-until-loop-max";
        String code = ":loopmaximumexceeded";
        Core.Type_int details = Core.vx_new_int(icount);
        Core.Type_msg msg = Core.vx_msg_from_error(path, code, details);
        output = Core.vx_copy(output, msg);
        iscontinue = false;
      } else {
        Core.Type_boolean valwhile = fn_while.vx_boolean_from_any(work);
        iscontinue = !valwhile.vx_boolean();
        if (iscontinue) {
          icount += 1;
          work = fn_loop.vx_any_from_any(Core.t_any, work);
          listvals.add(work);
        }
      }
    }
    if (listvals.size() > 0) {
      Core.Type_anylist anylist = Core.vx_new(Core.t_anylist, listvals);
      output = Core.f_new(generic_list_1, anylist);
    }
    return output;
  }

  public static <T extends Core.Type_list> T vx_list_from_list_filter(T generic_list_1, Core.Type_list vallist, Core.Func_any_from_any fn_filter) {
    T output = Core.f_empty(generic_list_1);
    List<Core.Type_any> listval = vallist.vx_list();
    List<Core.Type_any> items = new ArrayList<>();
    for (Core.Type_any val : listval) {
      Core.Type_any newval = fn_filter.vx_any_from_any(Core.t_any, val);
      Core.Type_boolean isempty = Core.f_is_empty_1(newval);
      if (!isempty.vx_boolean()) {
        items.add(newval);
      }
    }
    output = Core.vx_new(generic_list_1, items);
    return output;
  }

  public static <T extends Core.Type_list> T vx_list_from_list_start_end(T generic_list_1, Core.Type_list values, Core.Type_int start, Core.Type_int end) {
    T output = Core.f_empty(generic_list_1);
    int istart = start.vx_int();
    int iend = end.vx_int();
    List<Core.Type_any> listval = values.vx_list();
    int maxlen = listval.size();
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
      List<Core.Type_any> listsub = listval.subList(istart - 1, iend);
      output = Core.vx_new(generic_list_1, listsub);
    }
    return output;
  }
  
  public static <T extends Core.Type_map> T vx_map_from_map_keys(T generic_map_1, Core.Type_map valuemap, Core.Type_stringlist keys) {
    T output = Core.f_empty(generic_map_1);
    List<Core.Type_string> keylist = keys.vx_liststring();
    if (keylist.size() > 0) {
      Map<String, Core.Type_any> map = valuemap.vx_map();
      List<Core.Type_any> values = new ArrayList<>();
      for (Core.Type_string key : keylist) {
        Core.Type_any value = map.get(key.vx_string());
        values.add(key);
        values.add(value);
      }
      Core.Type_anylist anyvalues = Core.vx_new_anylist(values);
      output = Core.f_new(generic_map_1, anyvalues);
    }
    return output;
  }
  /**
   * @function any_from_for_until_loop
   * Returns a value using an until loop. Maximum 10000 times.
   * @param  {any-1} start
   * @param  {boolean<-any} fn-until
   * @param  {any<-any} fn-loop
   * @return {any-1}
   * (func any<-for-until-loop)
   */
  public interface Func_any_from_for_until_loop extends Core.Type_func, Core.Type_replfunc {
    public <T extends Core.Type_any> T vx_any_from_for_until_loop(final T generic_any_1, final T start, final Core.Func_boolean_from_any fn_until, final Core.Func_any_from_any fn_loop);
  }

  public static class Class_any_from_for_until_loop extends Core.Class_base implements Func_any_from_for_until_loop {

    @Override
    public Collection.Func_any_from_for_until_loop vx_new(final Object... vals) {
      Class_any_from_for_until_loop output = new Class_any_from_for_until_loop();
      return output;
    }

    @Override
    public Collection.Func_any_from_for_until_loop vx_copy(final Object... vals) {
      Class_any_from_for_until_loop output = new Class_any_from_for_until_loop();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/collection", // pkgname
        "any<-for-until-loop", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Core.Type_any vx_empty() {
      return e_any_from_for_until_loop;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_any_from_for_until_loop;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any start = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_boolean_from_any fn_until = Core.f_any_from_any(Core.t_boolean_from_any, arglist.vx_any(Core.vx_new_int(1)));
      Core.Func_any_from_any fn_loop = Core.f_any_from_any(Core.t_any_from_any, arglist.vx_any(Core.vx_new_int(2)));
      output = Collection.f_any_from_for_until_loop(generic_any_1, start, fn_until, fn_loop);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T vx_any_from_for_until_loop(final T generic_any_1, final T start, final Core.Func_boolean_from_any fn_until, final Core.Func_any_from_any fn_loop) {
      return Collection.f_any_from_for_until_loop(generic_any_1, start, fn_until, fn_loop);
    }

  }

  public static final Func_any_from_for_until_loop e_any_from_for_until_loop = new Collection.Class_any_from_for_until_loop();
  public static final Func_any_from_for_until_loop t_any_from_for_until_loop = new Collection.Class_any_from_for_until_loop();

  public static <T extends Core.Type_any> T f_any_from_for_until_loop(final T generic_any_1, final T start, final Core.Func_boolean_from_any fn_until, final Core.Func_any_from_any fn_loop) {
    T output = Core.f_empty(generic_any_1);
    output = Collection.f_any_from_for_until_loop_max(generic_any_1, start, fn_until, fn_loop, Core.vx_new_int(10000));
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
  public interface Func_any_from_for_until_loop_max extends Core.Type_func, Core.Type_replfunc {
    public <T extends Core.Type_any> T vx_any_from_for_until_loop_max(final T generic_any_1, final T start, final Core.Func_boolean_from_any fn_until, final Core.Func_any_from_any fn_loop, final Core.Type_int max);
  }

  public static class Class_any_from_for_until_loop_max extends Core.Class_base implements Func_any_from_for_until_loop_max {

    @Override
    public Collection.Func_any_from_for_until_loop_max vx_new(final Object... vals) {
      Class_any_from_for_until_loop_max output = new Class_any_from_for_until_loop_max();
      return output;
    }

    @Override
    public Collection.Func_any_from_for_until_loop_max vx_copy(final Object... vals) {
      Class_any_from_for_until_loop_max output = new Class_any_from_for_until_loop_max();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/collection", // pkgname
        "any<-for-until-loop-max", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Core.Type_any vx_empty() {
      return e_any_from_for_until_loop_max;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_any_from_for_until_loop_max;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any start = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_boolean_from_any fn_until = Core.f_any_from_any(Core.t_boolean_from_any, arglist.vx_any(Core.vx_new_int(1)));
      Core.Func_any_from_any fn_loop = Core.f_any_from_any(Core.t_any_from_any, arglist.vx_any(Core.vx_new_int(2)));
      Core.Type_int max = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(3)));
      output = Collection.f_any_from_for_until_loop_max(generic_any_1, start, fn_until, fn_loop, max);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T vx_any_from_for_until_loop_max(final T generic_any_1, final T start, final Core.Func_boolean_from_any fn_until, final Core.Func_any_from_any fn_loop, final Core.Type_int max) {
      return Collection.f_any_from_for_until_loop_max(generic_any_1, start, fn_until, fn_loop, max);
    }

  }

  public static final Func_any_from_for_until_loop_max e_any_from_for_until_loop_max = new Collection.Class_any_from_for_until_loop_max();
  public static final Func_any_from_for_until_loop_max t_any_from_for_until_loop_max = new Collection.Class_any_from_for_until_loop_max();

  public static <T extends Core.Type_any> T f_any_from_for_until_loop_max(final T generic_any_1, final T start, final Core.Func_boolean_from_any fn_until, final Core.Func_any_from_any fn_loop, final Core.Type_int max) {
    T output = Core.f_empty(generic_any_1);
    output = Collection.vx_any_from_for_until_loop_max(generic_any_1, start, fn_until, fn_loop, max);
    return output;
  }

  /**
   * @function any_from_for_while_loop
   * Returns a value using a while loop. Maximum 1000 times.
   * @param  {any-1} start
   * @param  {boolean<-any} fn-while
   * @param  {any<-any} fn-loop
   * @return {any-1}
   * (func any<-for-while-loop)
   */
  public interface Func_any_from_for_while_loop extends Core.Type_func, Core.Type_replfunc {
    public <T extends Core.Type_any> T vx_any_from_for_while_loop(final T generic_any_1, final T start, final Core.Func_boolean_from_any fn_while, final Core.Func_any_from_any fn_loop);
  }

  public static class Class_any_from_for_while_loop extends Core.Class_base implements Func_any_from_for_while_loop {

    @Override
    public Collection.Func_any_from_for_while_loop vx_new(final Object... vals) {
      Class_any_from_for_while_loop output = new Class_any_from_for_while_loop();
      return output;
    }

    @Override
    public Collection.Func_any_from_for_while_loop vx_copy(final Object... vals) {
      Class_any_from_for_while_loop output = new Class_any_from_for_while_loop();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/collection", // pkgname
        "any<-for-while-loop", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Core.Type_any vx_empty() {
      return e_any_from_for_while_loop;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_any_from_for_while_loop;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any start = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_boolean_from_any fn_while = Core.f_any_from_any(Core.t_boolean_from_any, arglist.vx_any(Core.vx_new_int(1)));
      Core.Func_any_from_any fn_loop = Core.f_any_from_any(Core.t_any_from_any, arglist.vx_any(Core.vx_new_int(2)));
      output = Collection.f_any_from_for_while_loop(generic_any_1, start, fn_while, fn_loop);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T vx_any_from_for_while_loop(final T generic_any_1, final T start, final Core.Func_boolean_from_any fn_while, final Core.Func_any_from_any fn_loop) {
      return Collection.f_any_from_for_while_loop(generic_any_1, start, fn_while, fn_loop);
    }

  }

  public static final Func_any_from_for_while_loop e_any_from_for_while_loop = new Collection.Class_any_from_for_while_loop();
  public static final Func_any_from_for_while_loop t_any_from_for_while_loop = new Collection.Class_any_from_for_while_loop();

  public static <T extends Core.Type_any> T f_any_from_for_while_loop(final T generic_any_1, final T start, final Core.Func_boolean_from_any fn_while, final Core.Func_any_from_any fn_loop) {
    T output = Core.f_empty(generic_any_1);
    output = Collection.f_any_from_for_while_loop_max(generic_any_1, start, fn_while, fn_loop, Core.vx_new_int(1000));
    return output;
  }

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
  public interface Func_any_from_for_while_loop_max extends Core.Type_func, Core.Type_replfunc {
    public <T extends Core.Type_any> T vx_any_from_for_while_loop_max(final T generic_any_1, final T start, final Core.Func_boolean_from_any fn_while, final Core.Func_any_from_any fn_loop, final Core.Type_int max);
  }

  public static class Class_any_from_for_while_loop_max extends Core.Class_base implements Func_any_from_for_while_loop_max {

    @Override
    public Collection.Func_any_from_for_while_loop_max vx_new(final Object... vals) {
      Class_any_from_for_while_loop_max output = new Class_any_from_for_while_loop_max();
      return output;
    }

    @Override
    public Collection.Func_any_from_for_while_loop_max vx_copy(final Object... vals) {
      Class_any_from_for_while_loop_max output = new Class_any_from_for_while_loop_max();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/collection", // pkgname
        "any<-for-while-loop-max", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Core.Type_any vx_empty() {
      return e_any_from_for_while_loop_max;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_any_from_for_while_loop_max;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any start = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_boolean_from_any fn_while = Core.f_any_from_any(Core.t_boolean_from_any, arglist.vx_any(Core.vx_new_int(1)));
      Core.Func_any_from_any fn_loop = Core.f_any_from_any(Core.t_any_from_any, arglist.vx_any(Core.vx_new_int(2)));
      Core.Type_int max = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(3)));
      output = Collection.f_any_from_for_while_loop_max(generic_any_1, start, fn_while, fn_loop, max);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T vx_any_from_for_while_loop_max(final T generic_any_1, final T start, final Core.Func_boolean_from_any fn_while, final Core.Func_any_from_any fn_loop, final Core.Type_int max) {
      return Collection.f_any_from_for_while_loop_max(generic_any_1, start, fn_while, fn_loop, max);
    }

  }

  public static final Func_any_from_for_while_loop_max e_any_from_for_while_loop_max = new Collection.Class_any_from_for_while_loop_max();
  public static final Func_any_from_for_while_loop_max t_any_from_for_while_loop_max = new Collection.Class_any_from_for_while_loop_max();

  public static <T extends Core.Type_any> T f_any_from_for_while_loop_max(final T generic_any_1, final T start, final Core.Func_boolean_from_any fn_while, final Core.Func_any_from_any fn_loop, final Core.Type_int max) {
    T output = Core.f_empty(generic_any_1);
    output = Collection.vx_any_from_for_while_loop_max(generic_any_1, start, fn_while, fn_loop, max);
    return output;
  }

  /**
   * @function any_from_map_pos
   * Returns then numbered child from a map.
   * @param  {map-1} map
   * @param  {int} pos
   * @return {any-1}
   * (func any<-map-pos)
   */
  public interface Func_any_from_map_pos extends Core.Type_func, Core.Type_replfunc {
    public <N extends Core.Type_map, T extends Core.Type_any> T vx_any_from_map_pos(final T generic_any_1, final N map, final Core.Type_int pos);
  }

  public static class Class_any_from_map_pos extends Core.Class_base implements Func_any_from_map_pos {

    @Override
    public Collection.Func_any_from_map_pos vx_new(final Object... vals) {
      Class_any_from_map_pos output = new Class_any_from_map_pos();
      return output;
    }

    @Override
    public Collection.Func_any_from_map_pos vx_copy(final Object... vals) {
      Class_any_from_map_pos output = new Class_any_from_map_pos();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/collection", // pkgname
        "any<-map-pos", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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
    public Core.Type_any vx_empty() {
      return e_any_from_map_pos;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_any_from_map_pos;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_map map = Core.f_any_from_any(Core.t_map, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int pos = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Collection.f_any_from_map_pos(generic_any_1, map, pos);
      return output;
    }

    @Override
    public <N extends Core.Type_map, T extends Core.Type_any> T vx_any_from_map_pos(final T generic_any_1, final N map, final Core.Type_int pos) {
      return Collection.f_any_from_map_pos(generic_any_1, map, pos);
    }

  }

  public static final Func_any_from_map_pos e_any_from_map_pos = new Collection.Class_any_from_map_pos();
  public static final Func_any_from_map_pos t_any_from_map_pos = new Collection.Class_any_from_map_pos();

  public static <N extends Core.Type_map, T extends Core.Type_any> T f_any_from_map_pos(final T generic_any_1, final N map, final Core.Type_int pos) {
    T output = Core.f_empty(generic_any_1);
    output = Core.f_let(
      generic_any_1,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_stringlist keys = Core.f_stringlist_from_map(map);
        final Core.Type_string key = Core.f_any_from_list(Core.t_string, keys, pos);
        return Core.f_any_from_map(generic_any_1, map, key);
      })
    );
    return output;
  }

  /**
   * @function boolean_write_from_map_removekey
   * Returns true if it alters a mutable map false if it fails.
   * @param  {map-1} valuemap
   * @param  {string} key
   * @return {boolean}
   * (func boolean-write<-map-removekey)
   */
  public interface Func_boolean_write_from_map_removekey extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean vx_boolean_write_from_map_removekey(final Core.Type_map valuemap, final Core.Type_string key);
  }

  public static class Class_boolean_write_from_map_removekey extends Core.Class_base implements Func_boolean_write_from_map_removekey {

    @Override
    public Collection.Func_boolean_write_from_map_removekey vx_new(final Object... vals) {
      Class_boolean_write_from_map_removekey output = new Class_boolean_write_from_map_removekey();
      return output;
    }

    @Override
    public Collection.Func_boolean_write_from_map_removekey vx_copy(final Object... vals) {
      Class_boolean_write_from_map_removekey output = new Class_boolean_write_from_map_removekey();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/collection", // pkgname
        "boolean-write<-map-removekey", // name
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
    public Core.Type_any vx_empty() {
      return e_boolean_write_from_map_removekey;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_boolean_write_from_map_removekey;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_map valuemap = Core.f_any_from_any(Core.t_map, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string key = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Collection.f_boolean_write_from_map_removekey(valuemap, key);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_write_from_map_removekey(final Core.Type_map valuemap, final Core.Type_string key) {
      return Collection.f_boolean_write_from_map_removekey(valuemap, key);
    }

  }

  public static final Func_boolean_write_from_map_removekey e_boolean_write_from_map_removekey = new Collection.Class_boolean_write_from_map_removekey();
  public static final Func_boolean_write_from_map_removekey t_boolean_write_from_map_removekey = new Collection.Class_boolean_write_from_map_removekey();

  public static Core.Type_boolean f_boolean_write_from_map_removekey(final Core.Type_map valuemap, final Core.Type_string key) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_boolean_write_from_map_name_value(
      valuemap,
      key,
      Core.f_empty(
        Core.t_any
      )
    );
    return output;
  }

  /**
   * @function boolean_write_from_map_removekeys
   * Returns true if it alters a mutable map false if it fails.
   * @param  {map-1} valuemap
   * @param  {stringlist} keys
   * @return {boolean}
   * (func boolean-write<-map-removekeys)
   */
  public interface Func_boolean_write_from_map_removekeys extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_boolean vx_boolean_write_from_map_removekeys(final Core.Type_map valuemap, final Core.Type_stringlist keys);
  }

  public static class Class_boolean_write_from_map_removekeys extends Core.Class_base implements Func_boolean_write_from_map_removekeys {

    @Override
    public Collection.Func_boolean_write_from_map_removekeys vx_new(final Object... vals) {
      Class_boolean_write_from_map_removekeys output = new Class_boolean_write_from_map_removekeys();
      return output;
    }

    @Override
    public Collection.Func_boolean_write_from_map_removekeys vx_copy(final Object... vals) {
      Class_boolean_write_from_map_removekeys output = new Class_boolean_write_from_map_removekeys();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/collection", // pkgname
        "boolean-write<-map-removekeys", // name
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
    public Core.Type_any vx_empty() {
      return e_boolean_write_from_map_removekeys;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_boolean_write_from_map_removekeys;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_map valuemap = Core.f_any_from_any(Core.t_map, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_stringlist keys = Core.f_any_from_any(Core.t_stringlist, arglist.vx_any(Core.vx_new_int(1)));
      output = Collection.f_boolean_write_from_map_removekeys(valuemap, keys);
      return output;
    }

    @Override
    public Core.Type_boolean vx_boolean_write_from_map_removekeys(final Core.Type_map valuemap, final Core.Type_stringlist keys) {
      return Collection.f_boolean_write_from_map_removekeys(valuemap, keys);
    }

  }

  public static final Func_boolean_write_from_map_removekeys e_boolean_write_from_map_removekeys = new Collection.Class_boolean_write_from_map_removekeys();
  public static final Func_boolean_write_from_map_removekeys t_boolean_write_from_map_removekeys = new Collection.Class_boolean_write_from_map_removekeys();

  public static Core.Type_boolean f_boolean_write_from_map_removekeys(final Core.Type_map valuemap, final Core.Type_stringlist keys) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_let(
      Core.t_boolean,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_booleanlist writelist = Core.f_list_from_list_1(
          Core.t_booleanlist,
          keys,
          Core.t_any_from_any.vx_fn_new((key_any) -> {
            Core.Type_string key = Core.f_any_from_any(Core.t_string, key_any);
            return 
              Collection.f_boolean_write_from_map_removekey(valuemap, key);
          })
        );
        return Core.f_and_1(writelist);
      })
    );
    return output;
  }

  /**
   * @function int_from_map_key
   * Returns the position of key in any map.
   * @param  {map-1} map
   * @param  {string} key
   * @return {int}
   * (func int<-map-key)
   */
  public interface Func_int_from_map_key extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_int vx_int_from_map_key(final Core.Type_map map, final Core.Type_string key);
  }

  public static class Class_int_from_map_key extends Core.Class_base implements Func_int_from_map_key {

    @Override
    public Collection.Func_int_from_map_key vx_new(final Object... vals) {
      Class_int_from_map_key output = new Class_int_from_map_key();
      return output;
    }

    @Override
    public Collection.Func_int_from_map_key vx_copy(final Object... vals) {
      Class_int_from_map_key output = new Class_int_from_map_key();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/collection", // pkgname
        "int<-map-key", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.vx_new(Core.t_typelist, Core.t_number), // traits
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
    public Core.Type_any vx_empty() {
      return e_int_from_map_key;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_int_from_map_key;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_map map = Core.f_any_from_any(Core.t_map, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string key = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Collection.f_int_from_map_key(map, key);
      return output;
    }

    @Override
    public Core.Type_int vx_int_from_map_key(final Core.Type_map map, final Core.Type_string key) {
      return Collection.f_int_from_map_key(map, key);
    }

  }

  public static final Func_int_from_map_key e_int_from_map_key = new Collection.Class_int_from_map_key();
  public static final Func_int_from_map_key t_int_from_map_key = new Collection.Class_int_from_map_key();

  public static Core.Type_int f_int_from_map_key(final Core.Type_map map, final Core.Type_string key) {
    Core.Type_int output = Core.e_int;
    output = Core.f_let(
      Core.t_int,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_stringlist keys = Core.f_stringlist_from_map(map);
        return Collection.f_int_from_stringlist_find(keys, key);
      })
    );
    return output;
  }

  /**
   * @function int_from_stringlist_find
   * Returns the position (first position is 1) of find text in a stringlist.
   * @param  {stringlist} stringlist
   * @param  {string} find
   * @return {int}
   * (func int<-stringlist-find)
   */
  public interface Func_int_from_stringlist_find extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_int vx_int_from_stringlist_find(final Core.Type_stringlist stringlist, final Core.Type_string find);
  }

  public static class Class_int_from_stringlist_find extends Core.Class_base implements Func_int_from_stringlist_find {

    @Override
    public Collection.Func_int_from_stringlist_find vx_new(final Object... vals) {
      Class_int_from_stringlist_find output = new Class_int_from_stringlist_find();
      return output;
    }

    @Override
    public Collection.Func_int_from_stringlist_find vx_copy(final Object... vals) {
      Class_int_from_stringlist_find output = new Class_int_from_stringlist_find();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/collection", // pkgname
        "int<-stringlist-find", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.vx_new(Core.t_typelist, Core.t_number), // traits
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
    public Core.Type_any vx_empty() {
      return e_int_from_stringlist_find;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_int_from_stringlist_find;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_stringlist stringlist = Core.f_any_from_any(Core.t_stringlist, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string find = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Collection.f_int_from_stringlist_find(stringlist, find);
      return output;
    }

    @Override
    public Core.Type_int vx_int_from_stringlist_find(final Core.Type_stringlist stringlist, final Core.Type_string find) {
      return Collection.f_int_from_stringlist_find(stringlist, find);
    }

  }

  public static final Func_int_from_stringlist_find e_int_from_stringlist_find = new Collection.Class_int_from_stringlist_find();
  public static final Func_int_from_stringlist_find t_int_from_stringlist_find = new Collection.Class_int_from_stringlist_find();

  public static Core.Type_int f_int_from_stringlist_find(final Core.Type_stringlist stringlist, final Core.Type_string find) {
    Core.Type_int output = Core.e_int;
    output = Core.f_let(
      Core.t_int,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_intlist poslist = Core.f_list_from_list_intany(
          Core.t_intlist,
          stringlist,
          Core.t_any_from_int_any.vx_fn_new((pos_any, value_any) -> {
            Core.Type_int pos = Core.f_any_from_any(Core.t_int, pos_any);
            Core.Type_string value = Core.f_any_from_any(Core.t_string, value_any);
            return 
              Core.f_if_1(
                Core.t_int,
                Core.f_eq(find, value),
                pos,
                Core.vx_new_int(0)
              );
          })
        );
        final Core.Type_intlist gt0list = Collection.f_list_from_list_filter(
          Core.t_intlist,
          poslist,
          Core.t_any_from_any.vx_fn_new((item_any) -> {
            Core.Type_int item = Core.f_any_from_any(Core.t_int, item_any);
            return item;
          })
        );
        return Core.f_first_from_list(Core.t_int, gt0list);
      })
    );
    return output;
  }

  /**
   * @function is_list
   * Returns true if the given value is a list.
   * @param  {any} val Any value
   * @return {boolean}
   * (func is-list)
   */
  public interface Func_is_list extends Core.Func_any_from_any {
    public Core.Type_boolean vx_is_list(final Core.Type_any val);
  }

  public static class Class_is_list extends Core.Class_base implements Func_is_list {

    @Override
    public Collection.Func_is_list vx_new(final Object... vals) {
      Class_is_list output = new Class_is_list();
      return output;
    }

    @Override
    public Collection.Func_is_list vx_copy(final Object... vals) {
      Class_is_list output = new Class_is_list();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

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
    public Core.Type_any vx_empty() {
      return e_is_list;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_is_list;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Collection.f_is_list(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Collection.f_is_list(val);
      return output;
    }

    @Override
    public Core.Type_boolean vx_is_list(final Core.Type_any val) {
      return Collection.f_is_list(val);
    }

  }

  public static final Func_is_list e_is_list = new Collection.Class_is_list();
  public static final Func_is_list t_is_list = new Collection.Class_is_list();

  public static Core.Type_boolean f_is_list(final Core.Type_any val) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_eq(
      Core.vx_new_string(":list"),
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
  public interface Func_is_map extends Core.Func_any_from_any {
    public Core.Type_boolean vx_is_map(final Core.Type_any val);
  }

  public static class Class_is_map extends Core.Class_base implements Func_is_map {

    @Override
    public Collection.Func_is_map vx_new(final Object... vals) {
      Class_is_map output = new Class_is_map();
      return output;
    }

    @Override
    public Collection.Func_is_map vx_copy(final Object... vals) {
      Class_is_map output = new Class_is_map();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

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
    public Core.Type_any vx_empty() {
      return e_is_map;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_is_map;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Collection.f_is_map(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any val = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Collection.f_is_map(val);
      return output;
    }

    @Override
    public Core.Type_boolean vx_is_map(final Core.Type_any val) {
      return Collection.f_is_map(val);
    }

  }

  public static final Func_is_map e_is_map = new Collection.Class_is_map();
  public static final Func_is_map t_is_map = new Collection.Class_is_map();

  public static Core.Type_boolean f_is_map(final Core.Type_any val) {
    Core.Type_boolean output = Core.e_boolean;
    output = Core.f_eq(
      Core.vx_new_string(":map"),
      Core.f_extends_from_any(val)
    );
    return output;
  }

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
  public interface Func_list_from_for_end_loop extends Core.Type_func, Core.Type_replfunc {
    public <X extends Core.Type_list> X vx_list_from_for_end_loop(final X generic_any_1, final Core.Type_int start, final Core.Type_int end, final Core.Func_any_from_int fn_loop);
  }

  public static class Class_list_from_for_end_loop extends Core.Class_base implements Func_list_from_for_end_loop {

    @Override
    public Collection.Func_list_from_for_end_loop vx_new(final Object... vals) {
      Class_list_from_for_end_loop output = new Class_list_from_for_end_loop();
      return output;
    }

    @Override
    public Collection.Func_list_from_for_end_loop vx_copy(final Object... vals) {
      Class_list_from_for_end_loop output = new Class_list_from_for_end_loop();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/collection", // pkgname
        "list<-for-end-loop", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Core.t_any), // allowtypes
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
    public Core.Type_any vx_empty() {
      return e_list_from_for_end_loop;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_list_from_for_end_loop;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_list generic_list_1 = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int start = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int end = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      Core.Func_any_from_int fn_loop = Core.f_any_from_any(Core.t_any_from_int, arglist.vx_any(Core.vx_new_int(2)));
      output = Collection.f_list_from_for_end_loop(generic_list_1, start, end, fn_loop);
      return output;
    }

    @Override
    public <X extends Core.Type_list> X vx_list_from_for_end_loop(final X generic_list_1, final Core.Type_int start, final Core.Type_int end, final Core.Func_any_from_int fn_loop) {
      return Collection.f_list_from_for_end_loop(generic_list_1, start, end, fn_loop);
    }

  }

  public static final Func_list_from_for_end_loop e_list_from_for_end_loop = new Collection.Class_list_from_for_end_loop();
  public static final Func_list_from_for_end_loop t_list_from_for_end_loop = new Collection.Class_list_from_for_end_loop();

  public static <X extends Core.Type_list> X f_list_from_for_end_loop(final X generic_list_1, final Core.Type_int start, final Core.Type_int end, final Core.Func_any_from_int fn_loop) {
    X output = Core.f_empty(generic_list_1);
    output = Collection.vx_list_from_for_end_loop(generic_list_1, start, end, fn_loop);
    return output;
  }

  /**
   * @function list_from_for_while_loop
   * Returns a list of any-1 using a while loop. Max: 1000
   * @param  {any-1} start
   * @param  {boolean<-any} fn-while
   * @param  {any<-any} fn-loop
   * @return {list-1}
   * (func list<-for-while-loop)
   */
  public interface Func_list_from_for_while_loop extends Core.Type_func, Core.Type_replfunc {
    public <T extends Core.Type_any, X extends Core.Type_list> X vx_list_from_for_while_loop(final X generic_any_1, final T start, final Core.Func_boolean_from_any fn_while, final Core.Func_any_from_any fn_loop);
  }

  public static class Class_list_from_for_while_loop extends Core.Class_base implements Func_list_from_for_while_loop {

    @Override
    public Collection.Func_list_from_for_while_loop vx_new(final Object... vals) {
      Class_list_from_for_while_loop output = new Class_list_from_for_while_loop();
      return output;
    }

    @Override
    public Collection.Func_list_from_for_while_loop vx_copy(final Object... vals) {
      Class_list_from_for_while_loop output = new Class_list_from_for_while_loop();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/collection", // pkgname
        "list<-for-while-loop", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Core.t_any), // allowtypes
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
    public Core.Type_any vx_empty() {
      return e_list_from_for_while_loop;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_list_from_for_while_loop;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_list generic_list_1 = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any start = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_boolean_from_any fn_while = Core.f_any_from_any(Core.t_boolean_from_any, arglist.vx_any(Core.vx_new_int(1)));
      Core.Func_any_from_any fn_loop = Core.f_any_from_any(Core.t_any_from_any, arglist.vx_any(Core.vx_new_int(2)));
      output = Collection.f_list_from_for_while_loop(generic_list_1, start, fn_while, fn_loop);
      return output;
    }

    @Override
    public <T extends Core.Type_any, X extends Core.Type_list> X vx_list_from_for_while_loop(final X generic_list_1, final T start, final Core.Func_boolean_from_any fn_while, final Core.Func_any_from_any fn_loop) {
      return Collection.f_list_from_for_while_loop(generic_list_1, start, fn_while, fn_loop);
    }

  }

  public static final Func_list_from_for_while_loop e_list_from_for_while_loop = new Collection.Class_list_from_for_while_loop();
  public static final Func_list_from_for_while_loop t_list_from_for_while_loop = new Collection.Class_list_from_for_while_loop();

  public static <T extends Core.Type_any, X extends Core.Type_list> X f_list_from_for_while_loop(final X generic_list_1, final T start, final Core.Func_boolean_from_any fn_while, final Core.Func_any_from_any fn_loop) {
    X output = Core.f_empty(generic_list_1);
    output = Collection.f_list_from_for_while_loop_max(generic_list_1, start, fn_while, fn_loop, Core.vx_new_int(1000));
    return output;
  }

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
  public interface Func_list_from_for_while_loop_max extends Core.Type_func, Core.Type_replfunc {
    public <T extends Core.Type_any, X extends Core.Type_list> X vx_list_from_for_while_loop_max(final X generic_any_1, final T start, final Core.Func_boolean_from_any fn_while, final Core.Func_any_from_any fn_loop, final Core.Type_int max);
  }

  public static class Class_list_from_for_while_loop_max extends Core.Class_base implements Func_list_from_for_while_loop_max {

    @Override
    public Collection.Func_list_from_for_while_loop_max vx_new(final Object... vals) {
      Class_list_from_for_while_loop_max output = new Class_list_from_for_while_loop_max();
      return output;
    }

    @Override
    public Collection.Func_list_from_for_while_loop_max vx_copy(final Object... vals) {
      Class_list_from_for_while_loop_max output = new Class_list_from_for_while_loop_max();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/collection", // pkgname
        "list<-for-while-loop-max", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Core.t_any), // allowtypes
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
    public Core.Type_any vx_empty() {
      return e_list_from_for_while_loop_max;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_list_from_for_while_loop_max;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_list generic_list_1 = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any start = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_boolean_from_any fn_while = Core.f_any_from_any(Core.t_boolean_from_any, arglist.vx_any(Core.vx_new_int(1)));
      Core.Func_any_from_any fn_loop = Core.f_any_from_any(Core.t_any_from_any, arglist.vx_any(Core.vx_new_int(2)));
      Core.Type_int max = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(3)));
      output = Collection.f_list_from_for_while_loop_max(generic_list_1, start, fn_while, fn_loop, max);
      return output;
    }

    @Override
    public <T extends Core.Type_any, X extends Core.Type_list> X vx_list_from_for_while_loop_max(final X generic_list_1, final T start, final Core.Func_boolean_from_any fn_while, final Core.Func_any_from_any fn_loop, final Core.Type_int max) {
      return Collection.f_list_from_for_while_loop_max(generic_list_1, start, fn_while, fn_loop, max);
    }

  }

  public static final Func_list_from_for_while_loop_max e_list_from_for_while_loop_max = new Collection.Class_list_from_for_while_loop_max();
  public static final Func_list_from_for_while_loop_max t_list_from_for_while_loop_max = new Collection.Class_list_from_for_while_loop_max();

  public static <T extends Core.Type_any, X extends Core.Type_list> X f_list_from_for_while_loop_max(final X generic_list_1, final T start, final Core.Func_boolean_from_any fn_while, final Core.Func_any_from_any fn_loop, final Core.Type_int max) {
    X output = Core.f_empty(generic_list_1);
    output = Collection.vx_list_from_for_while_loop_max(generic_list_1, start, fn_while, fn_loop, max);
    return output;
  }

  /**
   * @function list_from_list_end
   * Returns a sub list from positions 1 to end inclusive.
   * @param  {list-1} values
   * @param  {int} end
   * @return {list-1}
   * (func list<-list-end)
   */
  public interface Func_list_from_list_end extends Core.Type_func, Core.Type_replfunc {
    public <X extends Core.Type_list> X vx_list_from_list_end(final X generic_any_1, final X values, final Core.Type_int end);
  }

  public static class Class_list_from_list_end extends Core.Class_base implements Func_list_from_list_end {

    @Override
    public Collection.Func_list_from_list_end vx_new(final Object... vals) {
      Class_list_from_list_end output = new Class_list_from_list_end();
      return output;
    }

    @Override
    public Collection.Func_list_from_list_end vx_copy(final Object... vals) {
      Class_list_from_list_end output = new Class_list_from_list_end();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

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
          Core.vx_new(Core.t_typelist, Core.t_any), // allowtypes
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
    public Core.Type_any vx_empty() {
      return e_list_from_list_end;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_list_from_list_end;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_list generic_list_1 = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_list values = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int end = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Collection.f_list_from_list_end(generic_list_1, values, end);
      return output;
    }

    @Override
    public <X extends Core.Type_list> X vx_list_from_list_end(final X generic_list_1, final X values, final Core.Type_int end) {
      return Collection.f_list_from_list_end(generic_list_1, values, end);
    }

  }

  public static final Func_list_from_list_end e_list_from_list_end = new Collection.Class_list_from_list_end();
  public static final Func_list_from_list_end t_list_from_list_end = new Collection.Class_list_from_list_end();

  public static <X extends Core.Type_list> X f_list_from_list_end(final X generic_list_1, final X values, final Core.Type_int end) {
    X output = Core.f_empty(generic_list_1);
    output = Collection.f_list_from_list_start_end(generic_list_1, values, Core.vx_new_int(1), end);
    return output;
  }

  /**
   * @function list_from_list_filter
   * Filter List to only include non-empty values
   * @param  {list-2} vallist
   * @param  {any<-any} fn-filter
   * @return {list-1}
   * (func list<-list-filter)
   */
  public interface Func_list_from_list_filter extends Core.Type_func, Core.Type_replfunc {
    public <X extends Core.Type_list, Y extends Core.Type_list> X vx_list_from_list_filter(final X generic_any_1, final Y vallist, final Core.Func_any_from_any fn_filter);
  }

  public static class Class_list_from_list_filter extends Core.Class_base implements Func_list_from_list_filter {

    @Override
    public Collection.Func_list_from_list_filter vx_new(final Object... vals) {
      Class_list_from_list_filter output = new Class_list_from_list_filter();
      return output;
    }

    @Override
    public Collection.Func_list_from_list_filter vx_copy(final Object... vals) {
      Class_list_from_list_filter output = new Class_list_from_list_filter();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/collection", // pkgname
        "list<-list-filter", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Core.t_any), // allowtypes
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
    public Core.Type_any vx_empty() {
      return e_list_from_list_filter;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_list_from_list_filter;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_list generic_list_1 = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_list vallist = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_any_from_any fn_filter = Core.f_any_from_any(Core.t_any_from_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Collection.f_list_from_list_filter(generic_list_1, vallist, fn_filter);
      return output;
    }

    @Override
    public <X extends Core.Type_list, Y extends Core.Type_list> X vx_list_from_list_filter(final X generic_list_1, final Y vallist, final Core.Func_any_from_any fn_filter) {
      return Collection.f_list_from_list_filter(generic_list_1, vallist, fn_filter);
    }

  }

  public static final Func_list_from_list_filter e_list_from_list_filter = new Collection.Class_list_from_list_filter();
  public static final Func_list_from_list_filter t_list_from_list_filter = new Collection.Class_list_from_list_filter();

  public static <X extends Core.Type_list, Y extends Core.Type_list> X f_list_from_list_filter(final X generic_list_1, final Y vallist, final Core.Func_any_from_any fn_filter) {
    X output = Core.f_empty(generic_list_1);
    output = Collection.vx_list_from_list_filter(generic_list_1, vallist, fn_filter);
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
  public interface Func_list_from_list_filtertypes extends Core.Type_func, Core.Type_replfunc {
    public <X extends Core.Type_list, Y extends Core.Type_list> X vx_list_from_list_filtertypes(final X generic_any_1, final Y vallist, final Core.Type_typelist filtertypes);
  }

  public static class Class_list_from_list_filtertypes extends Core.Class_base implements Func_list_from_list_filtertypes {

    @Override
    public Collection.Func_list_from_list_filtertypes vx_new(final Object... vals) {
      Class_list_from_list_filtertypes output = new Class_list_from_list_filtertypes();
      return output;
    }

    @Override
    public Collection.Func_list_from_list_filtertypes vx_copy(final Object... vals) {
      Class_list_from_list_filtertypes output = new Class_list_from_list_filtertypes();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

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
          Core.vx_new(Core.t_typelist, Core.t_any), // allowtypes
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
    public Core.Type_any vx_empty() {
      return e_list_from_list_filtertypes;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_list_from_list_filtertypes;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_list generic_list_1 = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_list vallist = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_typelist filtertypes = Core.f_any_from_any(Core.t_typelist, arglist.vx_any(Core.vx_new_int(1)));
      output = Collection.f_list_from_list_filtertypes(generic_list_1, vallist, filtertypes);
      return output;
    }

    @Override
    public <X extends Core.Type_list, Y extends Core.Type_list> X vx_list_from_list_filtertypes(final X generic_list_1, final Y vallist, final Core.Type_typelist filtertypes) {
      return Collection.f_list_from_list_filtertypes(generic_list_1, vallist, filtertypes);
    }

  }

  public static final Func_list_from_list_filtertypes e_list_from_list_filtertypes = new Collection.Class_list_from_list_filtertypes();
  public static final Func_list_from_list_filtertypes t_list_from_list_filtertypes = new Collection.Class_list_from_list_filtertypes();

  public static <X extends Core.Type_list, Y extends Core.Type_list> X f_list_from_list_filtertypes(final X generic_list_1, final Y vallist, final Core.Type_typelist filtertypes) {
    X output = Core.f_empty(generic_list_1);
    output = Collection.f_list_from_list_filter(
      generic_list_1,
      vallist,
      Core.t_any_from_any.vx_fn_new((val_any) -> {
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
   * @function list_from_list_start
   * Returns a sub list from start to list end.
   * @param  {list-1} values
   * @param  {int} start
   * @return {list-1}
   * (func list<-list-start)
   */
  public interface Func_list_from_list_start extends Core.Type_func, Core.Type_replfunc {
    public <X extends Core.Type_list> X vx_list_from_list_start(final X generic_any_1, final X values, final Core.Type_int start);
  }

  public static class Class_list_from_list_start extends Core.Class_base implements Func_list_from_list_start {

    @Override
    public Collection.Func_list_from_list_start vx_new(final Object... vals) {
      Class_list_from_list_start output = new Class_list_from_list_start();
      return output;
    }

    @Override
    public Collection.Func_list_from_list_start vx_copy(final Object... vals) {
      Class_list_from_list_start output = new Class_list_from_list_start();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

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
          Core.vx_new(Core.t_typelist, Core.t_any), // allowtypes
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
    public Core.Type_any vx_empty() {
      return e_list_from_list_start;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_list_from_list_start;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_list generic_list_1 = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_list values = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int start = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Collection.f_list_from_list_start(generic_list_1, values, start);
      return output;
    }

    @Override
    public <X extends Core.Type_list> X vx_list_from_list_start(final X generic_list_1, final X values, final Core.Type_int start) {
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
      Core.f_length_1(values)
    );
    return output;
  }

  /**
   * @function list_from_list_start_end
   * Returns a sublist from another list
   * @param  {list-1} values
   * @param  {int} start
   * @param  {int} end
   * @return {list-1}
   * (func list<-list-start-end)
   */
  public interface Func_list_from_list_start_end extends Core.Type_func, Core.Type_replfunc {
    public <X extends Core.Type_list> X vx_list_from_list_start_end(final X generic_any_1, final X values, final Core.Type_int start, final Core.Type_int end);
  }

  public static class Class_list_from_list_start_end extends Core.Class_base implements Func_list_from_list_start_end {

    @Override
    public Collection.Func_list_from_list_start_end vx_new(final Object... vals) {
      Class_list_from_list_start_end output = new Class_list_from_list_start_end();
      return output;
    }

    @Override
    public Collection.Func_list_from_list_start_end vx_copy(final Object... vals) {
      Class_list_from_list_start_end output = new Class_list_from_list_start_end();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

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
          Core.vx_new(Core.t_typelist, Core.t_any), // allowtypes
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
    public Core.Type_any vx_empty() {
      return e_list_from_list_start_end;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_list_from_list_start_end;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_list generic_list_1 = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_list values = Core.f_any_from_any(Core.t_list, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int start = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      Core.Type_int end = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(2)));
      output = Collection.f_list_from_list_start_end(generic_list_1, values, start, end);
      return output;
    }

    @Override
    public <X extends Core.Type_list> X vx_list_from_list_start_end(final X generic_list_1, final X values, final Core.Type_int start, final Core.Type_int end) {
      return Collection.f_list_from_list_start_end(generic_list_1, values, start, end);
    }

  }

  public static final Func_list_from_list_start_end e_list_from_list_start_end = new Collection.Class_list_from_list_start_end();
  public static final Func_list_from_list_start_end t_list_from_list_start_end = new Collection.Class_list_from_list_start_end();

  public static <X extends Core.Type_list> X f_list_from_list_start_end(final X generic_list_1, final X values, final Core.Type_int start, final Core.Type_int end) {
    X output = Core.f_empty(generic_list_1);
    output = Collection.vx_list_from_list_start_end(generic_list_1, values, start, end);
    return output;
  }

  /**
   * @function map_from_map_end
   * Returns a submap from key positions 1 to end inclusive.
   * @param  {map-1} valuemap
   * @param  {int} end
   * @return {map-1}
   * (func map<-map-end)
   */
  public interface Func_map_from_map_end extends Core.Type_func, Core.Type_replfunc {
    public <N extends Core.Type_map> N vx_map_from_map_end(final N generic_any_1, final N valuemap, final Core.Type_int end);
  }

  public static class Class_map_from_map_end extends Core.Class_base implements Func_map_from_map_end {

    @Override
    public Collection.Func_map_from_map_end vx_new(final Object... vals) {
      Class_map_from_map_end output = new Class_map_from_map_end();
      return output;
    }

    @Override
    public Collection.Func_map_from_map_end vx_copy(final Object... vals) {
      Class_map_from_map_end output = new Class_map_from_map_end();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/collection", // pkgname
        "map<-map-end", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "map-1", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Core.t_any), // allowtypes
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
    public Core.Type_any vx_empty() {
      return e_map_from_map_end;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_map_from_map_end;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_map generic_map_1 = Core.f_any_from_any(Core.t_map, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_map valuemap = Core.f_any_from_any(Core.t_map, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int end = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Collection.f_map_from_map_end(generic_map_1, valuemap, end);
      return output;
    }

    @Override
    public <N extends Core.Type_map> N vx_map_from_map_end(final N generic_map_1, final N valuemap, final Core.Type_int end) {
      return Collection.f_map_from_map_end(generic_map_1, valuemap, end);
    }

  }

  public static final Func_map_from_map_end e_map_from_map_end = new Collection.Class_map_from_map_end();
  public static final Func_map_from_map_end t_map_from_map_end = new Collection.Class_map_from_map_end();

  public static <N extends Core.Type_map> N f_map_from_map_end(final N generic_map_1, final N valuemap, final Core.Type_int end) {
    N output = Core.f_empty(generic_map_1);
    output = Collection.f_map_from_map_start_end(generic_map_1, valuemap, Core.vx_new_int(1), end);
    return output;
  }

  /**
   * @function map_from_map_keys
   * Returns a submap from another map using a keylist
   * @param  {map-1} valuemap
   * @param  {stringlist} keys
   * @return {map-1}
   * (func map<-map-keys)
   */
  public interface Func_map_from_map_keys extends Core.Type_func, Core.Type_replfunc {
    public <N extends Core.Type_map> N vx_map_from_map_keys(final N generic_any_1, final N valuemap, final Core.Type_stringlist keys);
  }

  public static class Class_map_from_map_keys extends Core.Class_base implements Func_map_from_map_keys {

    @Override
    public Collection.Func_map_from_map_keys vx_new(final Object... vals) {
      Class_map_from_map_keys output = new Class_map_from_map_keys();
      return output;
    }

    @Override
    public Collection.Func_map_from_map_keys vx_copy(final Object... vals) {
      Class_map_from_map_keys output = new Class_map_from_map_keys();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/collection", // pkgname
        "map<-map-keys", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "map-1", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Core.t_any), // allowtypes
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
    public Core.Type_any vx_empty() {
      return e_map_from_map_keys;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_map_from_map_keys;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_map generic_map_1 = Core.f_any_from_any(Core.t_map, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_map valuemap = Core.f_any_from_any(Core.t_map, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_stringlist keys = Core.f_any_from_any(Core.t_stringlist, arglist.vx_any(Core.vx_new_int(1)));
      output = Collection.f_map_from_map_keys(generic_map_1, valuemap, keys);
      return output;
    }

    @Override
    public <N extends Core.Type_map> N vx_map_from_map_keys(final N generic_map_1, final N valuemap, final Core.Type_stringlist keys) {
      return Collection.f_map_from_map_keys(generic_map_1, valuemap, keys);
    }

  }

  public static final Func_map_from_map_keys e_map_from_map_keys = new Collection.Class_map_from_map_keys();
  public static final Func_map_from_map_keys t_map_from_map_keys = new Collection.Class_map_from_map_keys();

  public static <N extends Core.Type_map> N f_map_from_map_keys(final N generic_map_1, final N valuemap, final Core.Type_stringlist keys) {
    N output = Core.f_empty(generic_map_1);
    output = Collection.vx_map_from_map_keys(generic_map_1, valuemap, keys);
    return output;
  }

  /**
   * @function map_from_map_start
   * Returns a sub map from start to map end.
   * @param  {map-1} valuemap
   * @param  {int} start
   * @return {map-1}
   * (func map<-map-start)
   */
  public interface Func_map_from_map_start extends Core.Type_func, Core.Type_replfunc {
    public <N extends Core.Type_map> N vx_map_from_map_start(final N generic_any_1, final N valuemap, final Core.Type_int start);
  }

  public static class Class_map_from_map_start extends Core.Class_base implements Func_map_from_map_start {

    @Override
    public Collection.Func_map_from_map_start vx_new(final Object... vals) {
      Class_map_from_map_start output = new Class_map_from_map_start();
      return output;
    }

    @Override
    public Collection.Func_map_from_map_start vx_copy(final Object... vals) {
      Class_map_from_map_start output = new Class_map_from_map_start();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/collection", // pkgname
        "map<-map-start", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "map-1", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Core.t_any), // allowtypes
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
    public Core.Type_any vx_empty() {
      return e_map_from_map_start;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_map_from_map_start;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_map generic_map_1 = Core.f_any_from_any(Core.t_map, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_map valuemap = Core.f_any_from_any(Core.t_map, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int start = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      output = Collection.f_map_from_map_start(generic_map_1, valuemap, start);
      return output;
    }

    @Override
    public <N extends Core.Type_map> N vx_map_from_map_start(final N generic_map_1, final N valuemap, final Core.Type_int start) {
      return Collection.f_map_from_map_start(generic_map_1, valuemap, start);
    }

  }

  public static final Func_map_from_map_start e_map_from_map_start = new Collection.Class_map_from_map_start();
  public static final Func_map_from_map_start t_map_from_map_start = new Collection.Class_map_from_map_start();

  public static <N extends Core.Type_map> N f_map_from_map_start(final N generic_map_1, final N valuemap, final Core.Type_int start) {
    N output = Core.f_empty(generic_map_1);
    output = Collection.f_map_from_map_start_end(
      generic_map_1,
      valuemap,
      start,
      Core.f_length_2(valuemap)
    );
    return output;
  }

  /**
   * @function map_from_map_start_end
   * Returns a submap from another map using the index of the keylist
   * @param  {map-1} valuemap
   * @param  {int} start
   * @param  {int} end
   * @return {map-1}
   * (func map<-map-start-end)
   */
  public interface Func_map_from_map_start_end extends Core.Type_func, Core.Type_replfunc {
    public <N extends Core.Type_map> N vx_map_from_map_start_end(final N generic_any_1, final N valuemap, final Core.Type_int start, final Core.Type_int end);
  }

  public static class Class_map_from_map_start_end extends Core.Class_base implements Func_map_from_map_start_end {

    @Override
    public Collection.Func_map_from_map_start_end vx_new(final Object... vals) {
      Class_map_from_map_start_end output = new Class_map_from_map_start_end();
      return output;
    }

    @Override
    public Collection.Func_map_from_map_start_end vx_copy(final Object... vals) {
      Class_map_from_map_start_end output = new Class_map_from_map_start_end();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/collection", // pkgname
        "map<-map-start-end", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "map-1", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Core.t_any), // allowtypes
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
    public Core.Type_any vx_empty() {
      return e_map_from_map_start_end;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_map_from_map_start_end;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_map generic_map_1 = Core.f_any_from_any(Core.t_map, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_map valuemap = Core.f_any_from_any(Core.t_map, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_int start = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(1)));
      Core.Type_int end = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(2)));
      output = Collection.f_map_from_map_start_end(generic_map_1, valuemap, start, end);
      return output;
    }

    @Override
    public <N extends Core.Type_map> N vx_map_from_map_start_end(final N generic_map_1, final N valuemap, final Core.Type_int start, final Core.Type_int end) {
      return Collection.f_map_from_map_start_end(generic_map_1, valuemap, start, end);
    }

  }

  public static final Func_map_from_map_start_end e_map_from_map_start_end = new Collection.Class_map_from_map_start_end();
  public static final Func_map_from_map_start_end t_map_from_map_start_end = new Collection.Class_map_from_map_start_end();

  public static <N extends Core.Type_map> N f_map_from_map_start_end(final N generic_map_1, final N valuemap, final Core.Type_int start, final Core.Type_int end) {
    N output = Core.f_empty(generic_map_1);
    output = Core.f_let(
      generic_map_1,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_stringlist keys1 = Core.f_stringlist_from_map(valuemap);
        final Core.Type_stringlist keys2 = Collection.f_list_from_list_start_end(Core.t_stringlist, keys1, start, end);
        return Collection.f_map_from_map_keys(generic_map_1, valuemap, keys2);
      })
    );
    return output;
  }


  static {
    Map<String, Core.Type_any> maptype = new LinkedHashMap<>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<>();
    mapfunc.put("any<-for-until-loop", Collection.t_any_from_for_until_loop);
    mapfunc.put("any<-for-until-loop-max", Collection.t_any_from_for_until_loop_max);
    mapfunc.put("any<-for-while-loop", Collection.t_any_from_for_while_loop);
    mapfunc.put("any<-for-while-loop-max", Collection.t_any_from_for_while_loop_max);
    mapfunc.put("any<-map-pos", Collection.t_any_from_map_pos);
    mapfunc.put("boolean-write<-map-removekey", Collection.t_boolean_write_from_map_removekey);
    mapfunc.put("boolean-write<-map-removekeys", Collection.t_boolean_write_from_map_removekeys);
    mapfunc.put("int<-map-key", Collection.t_int_from_map_key);
    mapfunc.put("int<-stringlist-find", Collection.t_int_from_stringlist_find);
    mapfunc.put("is-list", Collection.t_is_list);
    mapfunc.put("is-map", Collection.t_is_map);
    mapfunc.put("list<-for-end-loop", Collection.t_list_from_for_end_loop);
    mapfunc.put("list<-for-while-loop", Collection.t_list_from_for_while_loop);
    mapfunc.put("list<-for-while-loop-max", Collection.t_list_from_for_while_loop_max);
    mapfunc.put("list<-list-end", Collection.t_list_from_list_end);
    mapfunc.put("list<-list-filter", Collection.t_list_from_list_filter);
    mapfunc.put("list<-list-filtertypes", Collection.t_list_from_list_filtertypes);
    mapfunc.put("list<-list-start", Collection.t_list_from_list_start);
    mapfunc.put("list<-list-start-end", Collection.t_list_from_list_start_end);
    mapfunc.put("map<-map-end", Collection.t_map_from_map_end);
    mapfunc.put("map<-map-keys", Collection.t_map_from_map_keys);
    mapfunc.put("map<-map-start", Collection.t_map_from_map_start);
    mapfunc.put("map<-map-start-end", Collection.t_map_from_map_start_end);
    Core.vx_global_package_set("vx/collection", maptype, mapconst, mapfunc);
  }

}
