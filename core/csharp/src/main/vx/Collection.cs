namespace vx;

public static class vx_collection {

  /**
   * @function any_from_for_until_loop
   * Returns a value using an until loop. Maximum 10000 times.
   * @param  {any-1} start
   * @param  {boolean<-any} fn-until
   * @param  {any<-any} fn-loop
   * @return {any-1}
   * (func any<-for-until-loop)
   */
  public interface Func_any_from_for_until_loop : vx_core.Type_func, vx_core.Type_replfunc {
    public T vx_any_from_for_until_loop<T>(T generic_any_1, T start, vx_core.Func_boolean_from_any fn_until, vx_core.Func_any_from_any fn_loop) where T : vx_core.Type_any;
  }

  public class Class_any_from_for_until_loop : vx_core.Class_base, Func_any_from_for_until_loop {

    public override vx_collection.Func_any_from_for_until_loop vx_new(params Object[] vals) {
      Class_any_from_for_until_loop output = new Class_any_from_for_until_loop();
      return output;
    }

    public override vx_collection.Func_any_from_for_until_loop vx_copy(params Object[] vals) {
      Class_any_from_for_until_loop output = new Class_any_from_for_until_loop();
      return output;
    }

    public vx_core.Type_typedef vx_typedef() {
      return vx_core.t_func.vx_typedef();
    }

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/collection", // pkgname
        "any<-for-until-loop", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override vx_core.Type_any vx_empty() {
      return e_any_from_for_until_loop;
    }

    public override vx_core.Type_any vx_type() {
      return t_any_from_for_until_loop;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any start = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Func_boolean_from_any fn_until = vx_core.f_any_from_any(vx_core.t_boolean_from_any, arglist.vx_any(vx_core.vx_new_int(1)));
      vx_core.Func_any_from_any fn_loop = vx_core.f_any_from_any(vx_core.t_any_from_any, arglist.vx_any(vx_core.vx_new_int(2)));
      output = vx_collection.f_any_from_for_until_loop(generic_any_1, start, fn_until, fn_loop);
      return output;
    }

    public T vx_any_from_for_until_loop<T>(T generic_any_1, T start, vx_core.Func_boolean_from_any fn_until, vx_core.Func_any_from_any fn_loop) where T : vx_core.Type_any {
      return vx_collection.f_any_from_for_until_loop(generic_any_1, start, fn_until, fn_loop);
    }

  }

  public static Func_any_from_for_until_loop e_any_from_for_until_loop = new vx_collection.Class_any_from_for_until_loop();
  public static Func_any_from_for_until_loop t_any_from_for_until_loop = new vx_collection.Class_any_from_for_until_loop();

  public static T f_any_from_for_until_loop<T>(T generic_any_1, T start, vx_core.Func_boolean_from_any fn_until, vx_core.Func_any_from_any fn_loop) where T : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
    output = vx_collection.f_any_from_for_until_loop_max(generic_any_1, start, fn_until, fn_loop, vx_core.vx_new_int(10000));
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
  public interface Func_any_from_for_until_loop_max : vx_core.Type_func, vx_core.Type_replfunc {
    public T vx_any_from_for_until_loop_max<T>(T generic_any_1, T start, vx_core.Func_boolean_from_any fn_until, vx_core.Func_any_from_any fn_loop, vx_core.Type_int max) where T : vx_core.Type_any;
  }

  public class Class_any_from_for_until_loop_max : vx_core.Class_base, Func_any_from_for_until_loop_max {

    public override vx_collection.Func_any_from_for_until_loop_max vx_new(params Object[] vals) {
      Class_any_from_for_until_loop_max output = new Class_any_from_for_until_loop_max();
      return output;
    }

    public override vx_collection.Func_any_from_for_until_loop_max vx_copy(params Object[] vals) {
      Class_any_from_for_until_loop_max output = new Class_any_from_for_until_loop_max();
      return output;
    }

    public vx_core.Type_typedef vx_typedef() {
      return vx_core.t_func.vx_typedef();
    }

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/collection", // pkgname
        "any<-for-until-loop-max", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override vx_core.Type_any vx_empty() {
      return e_any_from_for_until_loop_max;
    }

    public override vx_core.Type_any vx_type() {
      return t_any_from_for_until_loop_max;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any start = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Func_boolean_from_any fn_until = vx_core.f_any_from_any(vx_core.t_boolean_from_any, arglist.vx_any(vx_core.vx_new_int(1)));
      vx_core.Func_any_from_any fn_loop = vx_core.f_any_from_any(vx_core.t_any_from_any, arglist.vx_any(vx_core.vx_new_int(2)));
      vx_core.Type_int max = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(3)));
      output = vx_collection.f_any_from_for_until_loop_max(generic_any_1, start, fn_until, fn_loop, max);
      return output;
    }

    public T vx_any_from_for_until_loop_max<T>(T generic_any_1, T start, vx_core.Func_boolean_from_any fn_until, vx_core.Func_any_from_any fn_loop, vx_core.Type_int max) where T : vx_core.Type_any {
      return vx_collection.f_any_from_for_until_loop_max(generic_any_1, start, fn_until, fn_loop, max);
    }

  }

  public static Func_any_from_for_until_loop_max e_any_from_for_until_loop_max = new vx_collection.Class_any_from_for_until_loop_max();
  public static Func_any_from_for_until_loop_max t_any_from_for_until_loop_max = new vx_collection.Class_any_from_for_until_loop_max();

  public static T f_any_from_for_until_loop_max<T>(T generic_any_1, T start, vx_core.Func_boolean_from_any fn_until, vx_core.Func_any_from_any fn_loop, vx_core.Type_int max) where T : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
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
  public interface Func_any_from_for_while_loop : vx_core.Type_func, vx_core.Type_replfunc {
    public T vx_any_from_for_while_loop<T>(T generic_any_1, T start, vx_core.Func_boolean_from_any fn_while, vx_core.Func_any_from_any fn_loop) where T : vx_core.Type_any;
  }

  public class Class_any_from_for_while_loop : vx_core.Class_base, Func_any_from_for_while_loop {

    public override vx_collection.Func_any_from_for_while_loop vx_new(params Object[] vals) {
      Class_any_from_for_while_loop output = new Class_any_from_for_while_loop();
      return output;
    }

    public override vx_collection.Func_any_from_for_while_loop vx_copy(params Object[] vals) {
      Class_any_from_for_while_loop output = new Class_any_from_for_while_loop();
      return output;
    }

    public vx_core.Type_typedef vx_typedef() {
      return vx_core.t_func.vx_typedef();
    }

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/collection", // pkgname
        "any<-for-while-loop", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override vx_core.Type_any vx_empty() {
      return e_any_from_for_while_loop;
    }

    public override vx_core.Type_any vx_type() {
      return t_any_from_for_while_loop;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any start = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Func_boolean_from_any fn_while = vx_core.f_any_from_any(vx_core.t_boolean_from_any, arglist.vx_any(vx_core.vx_new_int(1)));
      vx_core.Func_any_from_any fn_loop = vx_core.f_any_from_any(vx_core.t_any_from_any, arglist.vx_any(vx_core.vx_new_int(2)));
      output = vx_collection.f_any_from_for_while_loop(generic_any_1, start, fn_while, fn_loop);
      return output;
    }

    public T vx_any_from_for_while_loop<T>(T generic_any_1, T start, vx_core.Func_boolean_from_any fn_while, vx_core.Func_any_from_any fn_loop) where T : vx_core.Type_any {
      return vx_collection.f_any_from_for_while_loop(generic_any_1, start, fn_while, fn_loop);
    }

  }

  public static Func_any_from_for_while_loop e_any_from_for_while_loop = new vx_collection.Class_any_from_for_while_loop();
  public static Func_any_from_for_while_loop t_any_from_for_while_loop = new vx_collection.Class_any_from_for_while_loop();

  public static T f_any_from_for_while_loop<T>(T generic_any_1, T start, vx_core.Func_boolean_from_any fn_while, vx_core.Func_any_from_any fn_loop) where T : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
    output = vx_collection.f_any_from_for_while_loop_max(generic_any_1, start, fn_while, fn_loop, vx_core.vx_new_int(1000));
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
  public interface Func_any_from_for_while_loop_max : vx_core.Type_func, vx_core.Type_replfunc {
    public T vx_any_from_for_while_loop_max<T>(T generic_any_1, T start, vx_core.Func_boolean_from_any fn_while, vx_core.Func_any_from_any fn_loop, vx_core.Type_int max) where T : vx_core.Type_any;
  }

  public class Class_any_from_for_while_loop_max : vx_core.Class_base, Func_any_from_for_while_loop_max {

    public override vx_collection.Func_any_from_for_while_loop_max vx_new(params Object[] vals) {
      Class_any_from_for_while_loop_max output = new Class_any_from_for_while_loop_max();
      return output;
    }

    public override vx_collection.Func_any_from_for_while_loop_max vx_copy(params Object[] vals) {
      Class_any_from_for_while_loop_max output = new Class_any_from_for_while_loop_max();
      return output;
    }

    public vx_core.Type_typedef vx_typedef() {
      return vx_core.t_func.vx_typedef();
    }

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/collection", // pkgname
        "any<-for-while-loop-max", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override vx_core.Type_any vx_empty() {
      return e_any_from_for_while_loop_max;
    }

    public override vx_core.Type_any vx_type() {
      return t_any_from_for_while_loop_max;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any start = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Func_boolean_from_any fn_while = vx_core.f_any_from_any(vx_core.t_boolean_from_any, arglist.vx_any(vx_core.vx_new_int(1)));
      vx_core.Func_any_from_any fn_loop = vx_core.f_any_from_any(vx_core.t_any_from_any, arglist.vx_any(vx_core.vx_new_int(2)));
      vx_core.Type_int max = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(3)));
      output = vx_collection.f_any_from_for_while_loop_max(generic_any_1, start, fn_while, fn_loop, max);
      return output;
    }

    public T vx_any_from_for_while_loop_max<T>(T generic_any_1, T start, vx_core.Func_boolean_from_any fn_while, vx_core.Func_any_from_any fn_loop, vx_core.Type_int max) where T : vx_core.Type_any {
      return vx_collection.f_any_from_for_while_loop_max(generic_any_1, start, fn_while, fn_loop, max);
    }

  }

  public static Func_any_from_for_while_loop_max e_any_from_for_while_loop_max = new vx_collection.Class_any_from_for_while_loop_max();
  public static Func_any_from_for_while_loop_max t_any_from_for_while_loop_max = new vx_collection.Class_any_from_for_while_loop_max();

  public static T f_any_from_for_while_loop_max<T>(T generic_any_1, T start, vx_core.Func_boolean_from_any fn_while, vx_core.Func_any_from_any fn_loop, vx_core.Type_int max) where T : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
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
  public interface Func_any_from_map_pos : vx_core.Type_func, vx_core.Type_replfunc {
    public T vx_any_from_map_pos<N, T>(T generic_any_1, N map, vx_core.Type_int pos) where N : vx_core.Type_map where T : vx_core.Type_any;
  }

  public class Class_any_from_map_pos : vx_core.Class_base, Func_any_from_map_pos {

    public override vx_collection.Func_any_from_map_pos vx_new(params Object[] vals) {
      Class_any_from_map_pos output = new Class_any_from_map_pos();
      return output;
    }

    public override vx_collection.Func_any_from_map_pos vx_copy(params Object[] vals) {
      Class_any_from_map_pos output = new Class_any_from_map_pos();
      return output;
    }

    public vx_core.Type_typedef vx_typedef() {
      return vx_core.t_func.vx_typedef();
    }

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/collection", // pkgname
        "any<-map-pos", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override vx_core.Type_any vx_empty() {
      return e_any_from_map_pos;
    }

    public override vx_core.Type_any vx_type() {
      return t_any_from_map_pos;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any generic_any_1 = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_map map = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_int pos = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_collection.f_any_from_map_pos(generic_any_1, map, pos);
      return output;
    }

    public T vx_any_from_map_pos<N, T>(T generic_any_1, N map, vx_core.Type_int pos) where N : vx_core.Type_map where T : vx_core.Type_any {
      return vx_collection.f_any_from_map_pos(generic_any_1, map, pos);
    }

  }

  public static Func_any_from_map_pos e_any_from_map_pos = new vx_collection.Class_any_from_map_pos();
  public static Func_any_from_map_pos t_any_from_map_pos = new vx_collection.Class_any_from_map_pos();

  public static T f_any_from_map_pos<N, T>(T generic_any_1, N map, vx_core.Type_int pos) where N : vx_core.Type_map where T : vx_core.Type_any {
    T output = vx_core.f_empty(generic_any_1);
    output = vx_core.f_let(
      generic_any_1,
      vx_core.t_any_from_func.vx_fn_new(() => {
        vx_core.Type_stringlist keys = vx_core.f_stringlist_from_map(map);
        vx_core.Type_string key = vx_core.f_any_from_list(vx_core.t_string, keys, pos);
        return vx_core.f_any_from_map(generic_any_1, map, key);
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
  public interface Func_boolean_write_from_map_removekey : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_boolean vx_boolean_write_from_map_removekey(vx_core.Type_map valuemap, vx_core.Type_string key);
  }

  public class Class_boolean_write_from_map_removekey : vx_core.Class_base, Func_boolean_write_from_map_removekey {

    public override vx_collection.Func_boolean_write_from_map_removekey vx_new(params Object[] vals) {
      Class_boolean_write_from_map_removekey output = new Class_boolean_write_from_map_removekey();
      return output;
    }

    public override vx_collection.Func_boolean_write_from_map_removekey vx_copy(params Object[] vals) {
      Class_boolean_write_from_map_removekey output = new Class_boolean_write_from_map_removekey();
      return output;
    }

    public vx_core.Type_typedef vx_typedef() {
      return vx_core.t_func.vx_typedef();
    }

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/collection", // pkgname
        "boolean-write<-map-removekey", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override vx_core.Type_any vx_empty() {
      return e_boolean_write_from_map_removekey;
    }

    public override vx_core.Type_any vx_type() {
      return t_boolean_write_from_map_removekey;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_map valuemap = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_string key = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_collection.f_boolean_write_from_map_removekey(valuemap, key);
      return output;
    }

    public vx_core.Type_boolean vx_boolean_write_from_map_removekey(vx_core.Type_map valuemap, vx_core.Type_string key) {
      return vx_collection.f_boolean_write_from_map_removekey(valuemap, key);
    }

  }

  public static Func_boolean_write_from_map_removekey e_boolean_write_from_map_removekey = new vx_collection.Class_boolean_write_from_map_removekey();
  public static Func_boolean_write_from_map_removekey t_boolean_write_from_map_removekey = new vx_collection.Class_boolean_write_from_map_removekey();

  public static vx_core.Type_boolean f_boolean_write_from_map_removekey(vx_core.Type_map valuemap, vx_core.Type_string key) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    output = vx_core.f_boolean_write_from_map_name_value(
      valuemap,
      key,
      vx_core.f_empty(
        vx_core.t_any
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
  public interface Func_boolean_write_from_map_removekeys : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_boolean vx_boolean_write_from_map_removekeys(vx_core.Type_map valuemap, vx_core.Type_stringlist keys);
  }

  public class Class_boolean_write_from_map_removekeys : vx_core.Class_base, Func_boolean_write_from_map_removekeys {

    public override vx_collection.Func_boolean_write_from_map_removekeys vx_new(params Object[] vals) {
      Class_boolean_write_from_map_removekeys output = new Class_boolean_write_from_map_removekeys();
      return output;
    }

    public override vx_collection.Func_boolean_write_from_map_removekeys vx_copy(params Object[] vals) {
      Class_boolean_write_from_map_removekeys output = new Class_boolean_write_from_map_removekeys();
      return output;
    }

    public vx_core.Type_typedef vx_typedef() {
      return vx_core.t_func.vx_typedef();
    }

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/collection", // pkgname
        "boolean-write<-map-removekeys", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override vx_core.Type_any vx_empty() {
      return e_boolean_write_from_map_removekeys;
    }

    public override vx_core.Type_any vx_type() {
      return t_boolean_write_from_map_removekeys;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_map valuemap = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_stringlist keys = vx_core.f_any_from_any(vx_core.t_stringlist, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_collection.f_boolean_write_from_map_removekeys(valuemap, keys);
      return output;
    }

    public vx_core.Type_boolean vx_boolean_write_from_map_removekeys(vx_core.Type_map valuemap, vx_core.Type_stringlist keys) {
      return vx_collection.f_boolean_write_from_map_removekeys(valuemap, keys);
    }

  }

  public static Func_boolean_write_from_map_removekeys e_boolean_write_from_map_removekeys = new vx_collection.Class_boolean_write_from_map_removekeys();
  public static Func_boolean_write_from_map_removekeys t_boolean_write_from_map_removekeys = new vx_collection.Class_boolean_write_from_map_removekeys();

  public static vx_core.Type_boolean f_boolean_write_from_map_removekeys(vx_core.Type_map valuemap, vx_core.Type_stringlist keys) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    output = vx_core.f_let(
      vx_core.t_boolean,
      vx_core.t_any_from_func.vx_fn_new(() => {
        vx_core.Type_booleanlist writelist = vx_core.f_list_from_list_1(
          vx_core.t_booleanlist,
          keys,
          vx_core.t_any_from_any.vx_fn_new((key_any) => {
            vx_core.Type_string key = vx_core.f_any_from_any(vx_core.t_string, key_any);
            return 
              vx_collection.f_boolean_write_from_map_removekey(valuemap, key);
          })
        );
        return vx_core.f_and_1(writelist);
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
  public interface Func_int_from_map_key : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_int vx_int_from_map_key(vx_core.Type_map map, vx_core.Type_string key);
  }

  public class Class_int_from_map_key : vx_core.Class_base, Func_int_from_map_key {

    public override vx_collection.Func_int_from_map_key vx_new(params Object[] vals) {
      Class_int_from_map_key output = new Class_int_from_map_key();
      return output;
    }

    public override vx_collection.Func_int_from_map_key vx_copy(params Object[] vals) {
      Class_int_from_map_key output = new Class_int_from_map_key();
      return output;
    }

    public vx_core.Type_typedef vx_typedef() {
      return vx_core.t_func.vx_typedef();
    }

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/collection", // pkgname
        "int<-map-key", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override vx_core.Type_any vx_empty() {
      return e_int_from_map_key;
    }

    public override vx_core.Type_any vx_type() {
      return t_int_from_map_key;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_map map = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_string key = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_collection.f_int_from_map_key(map, key);
      return output;
    }

    public vx_core.Type_int vx_int_from_map_key(vx_core.Type_map map, vx_core.Type_string key) {
      return vx_collection.f_int_from_map_key(map, key);
    }

  }

  public static Func_int_from_map_key e_int_from_map_key = new vx_collection.Class_int_from_map_key();
  public static Func_int_from_map_key t_int_from_map_key = new vx_collection.Class_int_from_map_key();

  public static vx_core.Type_int f_int_from_map_key(vx_core.Type_map map, vx_core.Type_string key) {
    vx_core.Type_int output = vx_core.e_int;
    output = vx_core.f_let(
      vx_core.t_int,
      vx_core.t_any_from_func.vx_fn_new(() => {
        vx_core.Type_stringlist keys = vx_core.f_stringlist_from_map(map);
        return vx_collection.f_int_from_stringlist_find(keys, key);
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
  public interface Func_int_from_stringlist_find : vx_core.Type_func, vx_core.Type_replfunc {
    public vx_core.Type_int vx_int_from_stringlist_find(vx_core.Type_stringlist stringlist, vx_core.Type_string find);
  }

  public class Class_int_from_stringlist_find : vx_core.Class_base, Func_int_from_stringlist_find {

    public override vx_collection.Func_int_from_stringlist_find vx_new(params Object[] vals) {
      Class_int_from_stringlist_find output = new Class_int_from_stringlist_find();
      return output;
    }

    public override vx_collection.Func_int_from_stringlist_find vx_copy(params Object[] vals) {
      Class_int_from_stringlist_find output = new Class_int_from_stringlist_find();
      return output;
    }

    public vx_core.Type_typedef vx_typedef() {
      return vx_core.t_func.vx_typedef();
    }

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/collection", // pkgname
        "int<-stringlist-find", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override vx_core.Type_any vx_empty() {
      return e_int_from_stringlist_find;
    }

    public override vx_core.Type_any vx_type() {
      return t_int_from_stringlist_find;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_stringlist stringlist = vx_core.f_any_from_any(vx_core.t_stringlist, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_string find = vx_core.f_any_from_any(vx_core.t_string, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_collection.f_int_from_stringlist_find(stringlist, find);
      return output;
    }

    public vx_core.Type_int vx_int_from_stringlist_find(vx_core.Type_stringlist stringlist, vx_core.Type_string find) {
      return vx_collection.f_int_from_stringlist_find(stringlist, find);
    }

  }

  public static Func_int_from_stringlist_find e_int_from_stringlist_find = new vx_collection.Class_int_from_stringlist_find();
  public static Func_int_from_stringlist_find t_int_from_stringlist_find = new vx_collection.Class_int_from_stringlist_find();

  public static vx_core.Type_int f_int_from_stringlist_find(vx_core.Type_stringlist stringlist, vx_core.Type_string find) {
    vx_core.Type_int output = vx_core.e_int;
    output = vx_core.f_let(
      vx_core.t_int,
      vx_core.t_any_from_func.vx_fn_new(() => {
        vx_core.Type_intlist poslist = vx_core.f_list_from_list_intany(
          vx_core.t_intlist,
          stringlist,
          vx_core.t_any_from_int_any.vx_fn_new((pos_any, value_any) => {
            vx_core.Type_int pos = vx_core.f_any_from_any(vx_core.t_int, pos_any);
            vx_core.Type_string value = vx_core.f_any_from_any(vx_core.t_string, value_any);
            return 
              vx_core.f_if_1(
                vx_core.t_int,
                vx_core.f_eq(find, value),
                pos,
                vx_core.vx_new_int(0)
              );
          })
        );
        vx_core.Type_intlist gt0list = vx_collection.f_list_from_list_filter(
          vx_core.t_intlist,
          poslist,
          vx_core.t_any_from_any.vx_fn_new((item_any) => {
            vx_core.Type_int item = vx_core.f_any_from_any(vx_core.t_int, item_any);
            return item;
          })
        );
        return vx_core.f_first_from_list(vx_core.t_int, gt0list);
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
  public interface Func_is_list : vx_core.Func_any_from_any {
    public vx_core.Type_boolean vx_is_list(vx_core.Type_any val);
  }

  public class Class_is_list : vx_core.Class_base, Func_is_list {

    public override vx_collection.Func_is_list vx_new(params Object[] vals) {
      Class_is_list output = new Class_is_list();
      return output;
    }

    public override vx_collection.Func_is_list vx_copy(params Object[] vals) {
      Class_is_list output = new Class_is_list();
      return output;
    }

    public vx_core.Type_typedef vx_typedef() {
      return vx_core.t_func.vx_typedef();
    }

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/collection", // pkgname
        "is-list", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override vx_core.Type_any vx_empty() {
      return e_is_list;
    }

    public override vx_core.Type_any vx_type() {
      return t_is_list;
    }

    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : vx_core.Type_any where U : vx_core.Type_any {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_any inputval = (vx_core.Type_any)value;
      vx_core.Type_any outputval = vx_collection.f_is_list(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any val = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_collection.f_is_list(val);
      return output;
    }

    public vx_core.Type_boolean vx_is_list(vx_core.Type_any val) {
      return vx_collection.f_is_list(val);
    }

  }

  public static Func_is_list e_is_list = new vx_collection.Class_is_list();
  public static Func_is_list t_is_list = new vx_collection.Class_is_list();

  public static vx_core.Type_boolean f_is_list(vx_core.Type_any val) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    output = vx_core.f_eq(
      vx_core.vx_new_string(":list"),
      vx_core.f_extends_from_any(val)
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
  public interface Func_is_map : vx_core.Func_any_from_any {
    public vx_core.Type_boolean vx_is_map(vx_core.Type_any val);
  }

  public class Class_is_map : vx_core.Class_base, Func_is_map {

    public override vx_collection.Func_is_map vx_new(params Object[] vals) {
      Class_is_map output = new Class_is_map();
      return output;
    }

    public override vx_collection.Func_is_map vx_copy(params Object[] vals) {
      Class_is_map output = new Class_is_map();
      return output;
    }

    public vx_core.Type_typedef vx_typedef() {
      return vx_core.t_func.vx_typedef();
    }

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/collection", // pkgname
        "is-map", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override vx_core.Type_any vx_empty() {
      return e_is_map;
    }

    public override vx_core.Type_any vx_type() {
      return t_is_map;
    }

    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : vx_core.Type_any where U : vx_core.Type_any {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_any inputval = (vx_core.Type_any)value;
      vx_core.Type_any outputval = vx_collection.f_is_map(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_any val = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_collection.f_is_map(val);
      return output;
    }

    public vx_core.Type_boolean vx_is_map(vx_core.Type_any val) {
      return vx_collection.f_is_map(val);
    }

  }

  public static Func_is_map e_is_map = new vx_collection.Class_is_map();
  public static Func_is_map t_is_map = new vx_collection.Class_is_map();

  public static vx_core.Type_boolean f_is_map(vx_core.Type_any val) {
    vx_core.Type_boolean output = vx_core.e_boolean;
    output = vx_core.f_eq(
      vx_core.vx_new_string(":map"),
      vx_core.f_extends_from_any(val)
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
  public interface Func_list_from_for_end_loop : vx_core.Type_func, vx_core.Type_replfunc {
    public X vx_list_from_for_end_loop<X>(X generic_any_1, vx_core.Type_int start, vx_core.Type_int end, vx_core.Func_any_from_int fn_loop) where X : vx_core.Type_list;
  }

  public class Class_list_from_for_end_loop : vx_core.Class_base, Func_list_from_for_end_loop {

    public override vx_collection.Func_list_from_for_end_loop vx_new(params Object[] vals) {
      Class_list_from_for_end_loop output = new Class_list_from_for_end_loop();
      return output;
    }

    public override vx_collection.Func_list_from_for_end_loop vx_copy(params Object[] vals) {
      Class_list_from_for_end_loop output = new Class_list_from_for_end_loop();
      return output;
    }

    public vx_core.Type_typedef vx_typedef() {
      return vx_core.t_func.vx_typedef();
    }

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/collection", // pkgname
        "list<-for-end-loop", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override vx_core.Type_any vx_empty() {
      return e_list_from_for_end_loop;
    }

    public override vx_core.Type_any vx_type() {
      return t_list_from_for_end_loop;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_list generic_list_1 = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_int start = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_int end = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)));
      vx_core.Func_any_from_int fn_loop = vx_core.f_any_from_any(vx_core.t_any_from_int, arglist.vx_any(vx_core.vx_new_int(2)));
      output = vx_collection.f_list_from_for_end_loop(generic_list_1, start, end, fn_loop);
      return output;
    }

    public X vx_list_from_for_end_loop<X>(X generic_list_1, vx_core.Type_int start, vx_core.Type_int end, vx_core.Func_any_from_int fn_loop) where X : vx_core.Type_list {
      return vx_collection.f_list_from_for_end_loop(generic_list_1, start, end, fn_loop);
    }

  }

  public static Func_list_from_for_end_loop e_list_from_for_end_loop = new vx_collection.Class_list_from_for_end_loop();
  public static Func_list_from_for_end_loop t_list_from_for_end_loop = new vx_collection.Class_list_from_for_end_loop();

  public static X f_list_from_for_end_loop<X>(X generic_list_1, vx_core.Type_int start, vx_core.Type_int end, vx_core.Func_any_from_int fn_loop) where X : vx_core.Type_list {
    X output = vx_core.f_empty(generic_list_1);
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
  public interface Func_list_from_for_while_loop : vx_core.Type_func, vx_core.Type_replfunc {
    public X vx_list_from_for_while_loop<T, X>(X generic_any_1, T start, vx_core.Func_boolean_from_any fn_while, vx_core.Func_any_from_any fn_loop) where T : vx_core.Type_any where X : vx_core.Type_list;
  }

  public class Class_list_from_for_while_loop : vx_core.Class_base, Func_list_from_for_while_loop {

    public override vx_collection.Func_list_from_for_while_loop vx_new(params Object[] vals) {
      Class_list_from_for_while_loop output = new Class_list_from_for_while_loop();
      return output;
    }

    public override vx_collection.Func_list_from_for_while_loop vx_copy(params Object[] vals) {
      Class_list_from_for_while_loop output = new Class_list_from_for_while_loop();
      return output;
    }

    public vx_core.Type_typedef vx_typedef() {
      return vx_core.t_func.vx_typedef();
    }

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/collection", // pkgname
        "list<-for-while-loop", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override vx_core.Type_any vx_empty() {
      return e_list_from_for_while_loop;
    }

    public override vx_core.Type_any vx_type() {
      return t_list_from_for_while_loop;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_list generic_list_1 = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any start = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Func_boolean_from_any fn_while = vx_core.f_any_from_any(vx_core.t_boolean_from_any, arglist.vx_any(vx_core.vx_new_int(1)));
      vx_core.Func_any_from_any fn_loop = vx_core.f_any_from_any(vx_core.t_any_from_any, arglist.vx_any(vx_core.vx_new_int(2)));
      output = vx_collection.f_list_from_for_while_loop(generic_list_1, start, fn_while, fn_loop);
      return output;
    }

    public X vx_list_from_for_while_loop<T, X>(X generic_list_1, T start, vx_core.Func_boolean_from_any fn_while, vx_core.Func_any_from_any fn_loop) where T : vx_core.Type_any where X : vx_core.Type_list {
      return vx_collection.f_list_from_for_while_loop(generic_list_1, start, fn_while, fn_loop);
    }

  }

  public static Func_list_from_for_while_loop e_list_from_for_while_loop = new vx_collection.Class_list_from_for_while_loop();
  public static Func_list_from_for_while_loop t_list_from_for_while_loop = new vx_collection.Class_list_from_for_while_loop();

  public static X f_list_from_for_while_loop<T, X>(X generic_list_1, T start, vx_core.Func_boolean_from_any fn_while, vx_core.Func_any_from_any fn_loop) where T : vx_core.Type_any where X : vx_core.Type_list {
    X output = vx_core.f_empty(generic_list_1);
    output = vx_collection.f_list_from_for_while_loop_max(generic_list_1, start, fn_while, fn_loop, vx_core.vx_new_int(1000));
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
  public interface Func_list_from_for_while_loop_max : vx_core.Type_func, vx_core.Type_replfunc {
    public X vx_list_from_for_while_loop_max<T, X>(X generic_any_1, T start, vx_core.Func_boolean_from_any fn_while, vx_core.Func_any_from_any fn_loop, vx_core.Type_int max) where T : vx_core.Type_any where X : vx_core.Type_list;
  }

  public class Class_list_from_for_while_loop_max : vx_core.Class_base, Func_list_from_for_while_loop_max {

    public override vx_collection.Func_list_from_for_while_loop_max vx_new(params Object[] vals) {
      Class_list_from_for_while_loop_max output = new Class_list_from_for_while_loop_max();
      return output;
    }

    public override vx_collection.Func_list_from_for_while_loop_max vx_copy(params Object[] vals) {
      Class_list_from_for_while_loop_max output = new Class_list_from_for_while_loop_max();
      return output;
    }

    public vx_core.Type_typedef vx_typedef() {
      return vx_core.t_func.vx_typedef();
    }

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/collection", // pkgname
        "list<-for-while-loop-max", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override vx_core.Type_any vx_empty() {
      return e_list_from_for_while_loop_max;
    }

    public override vx_core.Type_any vx_type() {
      return t_list_from_for_while_loop_max;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_list generic_list_1 = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_any start = vx_core.f_any_from_any(vx_core.t_any, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Func_boolean_from_any fn_while = vx_core.f_any_from_any(vx_core.t_boolean_from_any, arglist.vx_any(vx_core.vx_new_int(1)));
      vx_core.Func_any_from_any fn_loop = vx_core.f_any_from_any(vx_core.t_any_from_any, arglist.vx_any(vx_core.vx_new_int(2)));
      vx_core.Type_int max = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(3)));
      output = vx_collection.f_list_from_for_while_loop_max(generic_list_1, start, fn_while, fn_loop, max);
      return output;
    }

    public X vx_list_from_for_while_loop_max<T, X>(X generic_list_1, T start, vx_core.Func_boolean_from_any fn_while, vx_core.Func_any_from_any fn_loop, vx_core.Type_int max) where T : vx_core.Type_any where X : vx_core.Type_list {
      return vx_collection.f_list_from_for_while_loop_max(generic_list_1, start, fn_while, fn_loop, max);
    }

  }

  public static Func_list_from_for_while_loop_max e_list_from_for_while_loop_max = new vx_collection.Class_list_from_for_while_loop_max();
  public static Func_list_from_for_while_loop_max t_list_from_for_while_loop_max = new vx_collection.Class_list_from_for_while_loop_max();

  public static X f_list_from_for_while_loop_max<T, X>(X generic_list_1, T start, vx_core.Func_boolean_from_any fn_while, vx_core.Func_any_from_any fn_loop, vx_core.Type_int max) where T : vx_core.Type_any where X : vx_core.Type_list {
    X output = vx_core.f_empty(generic_list_1);
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
  public interface Func_list_from_list_end : vx_core.Type_func, vx_core.Type_replfunc {
    public X vx_list_from_list_end<X>(X generic_any_1, X values, vx_core.Type_int end) where X : vx_core.Type_list;
  }

  public class Class_list_from_list_end : vx_core.Class_base, Func_list_from_list_end {

    public override vx_collection.Func_list_from_list_end vx_new(params Object[] vals) {
      Class_list_from_list_end output = new Class_list_from_list_end();
      return output;
    }

    public override vx_collection.Func_list_from_list_end vx_copy(params Object[] vals) {
      Class_list_from_list_end output = new Class_list_from_list_end();
      return output;
    }

    public vx_core.Type_typedef vx_typedef() {
      return vx_core.t_func.vx_typedef();
    }

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/collection", // pkgname
        "list<-list-end", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override vx_core.Type_any vx_empty() {
      return e_list_from_list_end;
    }

    public override vx_core.Type_any vx_type() {
      return t_list_from_list_end;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_list generic_list_1 = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_list values = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_int end = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_collection.f_list_from_list_end(generic_list_1, values, end);
      return output;
    }

    public X vx_list_from_list_end<X>(X generic_list_1, X values, vx_core.Type_int end) where X : vx_core.Type_list {
      return vx_collection.f_list_from_list_end(generic_list_1, values, end);
    }

  }

  public static Func_list_from_list_end e_list_from_list_end = new vx_collection.Class_list_from_list_end();
  public static Func_list_from_list_end t_list_from_list_end = new vx_collection.Class_list_from_list_end();

  public static X f_list_from_list_end<X>(X generic_list_1, X values, vx_core.Type_int end) where X : vx_core.Type_list {
    X output = vx_core.f_empty(generic_list_1);
    output = vx_collection.f_list_from_list_start_end(generic_list_1, values, vx_core.vx_new_int(1), end);
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
  public interface Func_list_from_list_filter : vx_core.Type_func, vx_core.Type_replfunc {
    public X vx_list_from_list_filter<X, Y>(X generic_any_1, Y vallist, vx_core.Func_any_from_any fn_filter) where X : vx_core.Type_list where Y : vx_core.Type_list;
  }

  public class Class_list_from_list_filter : vx_core.Class_base, Func_list_from_list_filter {

    public override vx_collection.Func_list_from_list_filter vx_new(params Object[] vals) {
      Class_list_from_list_filter output = new Class_list_from_list_filter();
      return output;
    }

    public override vx_collection.Func_list_from_list_filter vx_copy(params Object[] vals) {
      Class_list_from_list_filter output = new Class_list_from_list_filter();
      return output;
    }

    public vx_core.Type_typedef vx_typedef() {
      return vx_core.t_func.vx_typedef();
    }

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/collection", // pkgname
        "list<-list-filter", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override vx_core.Type_any vx_empty() {
      return e_list_from_list_filter;
    }

    public override vx_core.Type_any vx_type() {
      return t_list_from_list_filter;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_list generic_list_1 = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_list vallist = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Func_any_from_any fn_filter = vx_core.f_any_from_any(vx_core.t_any_from_any, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_collection.f_list_from_list_filter(generic_list_1, vallist, fn_filter);
      return output;
    }

    public X vx_list_from_list_filter<X, Y>(X generic_list_1, Y vallist, vx_core.Func_any_from_any fn_filter) where X : vx_core.Type_list where Y : vx_core.Type_list {
      return vx_collection.f_list_from_list_filter(generic_list_1, vallist, fn_filter);
    }

  }

  public static Func_list_from_list_filter e_list_from_list_filter = new vx_collection.Class_list_from_list_filter();
  public static Func_list_from_list_filter t_list_from_list_filter = new vx_collection.Class_list_from_list_filter();

  public static X f_list_from_list_filter<X, Y>(X generic_list_1, Y vallist, vx_core.Func_any_from_any fn_filter) where X : vx_core.Type_list where Y : vx_core.Type_list {
    X output = vx_core.f_empty(generic_list_1);
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
  public interface Func_list_from_list_filtertypes : vx_core.Type_func, vx_core.Type_replfunc {
    public X vx_list_from_list_filtertypes<X, Y>(X generic_any_1, Y vallist, vx_core.Type_typelist filtertypes) where X : vx_core.Type_list where Y : vx_core.Type_list;
  }

  public class Class_list_from_list_filtertypes : vx_core.Class_base, Func_list_from_list_filtertypes {

    public override vx_collection.Func_list_from_list_filtertypes vx_new(params Object[] vals) {
      Class_list_from_list_filtertypes output = new Class_list_from_list_filtertypes();
      return output;
    }

    public override vx_collection.Func_list_from_list_filtertypes vx_copy(params Object[] vals) {
      Class_list_from_list_filtertypes output = new Class_list_from_list_filtertypes();
      return output;
    }

    public vx_core.Type_typedef vx_typedef() {
      return vx_core.t_func.vx_typedef();
    }

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/collection", // pkgname
        "list<-list-filtertypes", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override vx_core.Type_any vx_empty() {
      return e_list_from_list_filtertypes;
    }

    public override vx_core.Type_any vx_type() {
      return t_list_from_list_filtertypes;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_list generic_list_1 = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_list vallist = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_typelist filtertypes = vx_core.f_any_from_any(vx_core.t_typelist, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_collection.f_list_from_list_filtertypes(generic_list_1, vallist, filtertypes);
      return output;
    }

    public X vx_list_from_list_filtertypes<X, Y>(X generic_list_1, Y vallist, vx_core.Type_typelist filtertypes) where X : vx_core.Type_list where Y : vx_core.Type_list {
      return vx_collection.f_list_from_list_filtertypes(generic_list_1, vallist, filtertypes);
    }

  }

  public static Func_list_from_list_filtertypes e_list_from_list_filtertypes = new vx_collection.Class_list_from_list_filtertypes();
  public static Func_list_from_list_filtertypes t_list_from_list_filtertypes = new vx_collection.Class_list_from_list_filtertypes();

  public static X f_list_from_list_filtertypes<X, Y>(X generic_list_1, Y vallist, vx_core.Type_typelist filtertypes) where X : vx_core.Type_list where Y : vx_core.Type_list {
    X output = vx_core.f_empty(generic_list_1);
    output = vx_collection.f_list_from_list_filter(
      generic_list_1,
      vallist,
      vx_core.t_any_from_any.vx_fn_new((val_any) => {
        vx_core.Type_any val = vx_core.f_any_from_any(vx_core.t_any, val_any);
        return 
        vx_core.f_if(
          vx_core.t_any,
          vx_type.f_is_type_from_any_typelist(val, filtertypes),
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
  public interface Func_list_from_list_start : vx_core.Type_func, vx_core.Type_replfunc {
    public X vx_list_from_list_start<X>(X generic_any_1, X values, vx_core.Type_int start) where X : vx_core.Type_list;
  }

  public class Class_list_from_list_start : vx_core.Class_base, Func_list_from_list_start {

    public override vx_collection.Func_list_from_list_start vx_new(params Object[] vals) {
      Class_list_from_list_start output = new Class_list_from_list_start();
      return output;
    }

    public override vx_collection.Func_list_from_list_start vx_copy(params Object[] vals) {
      Class_list_from_list_start output = new Class_list_from_list_start();
      return output;
    }

    public vx_core.Type_typedef vx_typedef() {
      return vx_core.t_func.vx_typedef();
    }

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/collection", // pkgname
        "list<-list-start", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override vx_core.Type_any vx_empty() {
      return e_list_from_list_start;
    }

    public override vx_core.Type_any vx_type() {
      return t_list_from_list_start;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_list generic_list_1 = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_list values = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_int start = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_collection.f_list_from_list_start(generic_list_1, values, start);
      return output;
    }

    public X vx_list_from_list_start<X>(X generic_list_1, X values, vx_core.Type_int start) where X : vx_core.Type_list {
      return vx_collection.f_list_from_list_start(generic_list_1, values, start);
    }

  }

  public static Func_list_from_list_start e_list_from_list_start = new vx_collection.Class_list_from_list_start();
  public static Func_list_from_list_start t_list_from_list_start = new vx_collection.Class_list_from_list_start();

  public static X f_list_from_list_start<X>(X generic_list_1, X values, vx_core.Type_int start) where X : vx_core.Type_list {
    X output = vx_core.f_empty(generic_list_1);
    output = vx_collection.f_list_from_list_start_end(
      generic_list_1,
      values,
      start,
      vx_core.f_length_1(values)
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
  public interface Func_list_from_list_start_end : vx_core.Type_func, vx_core.Type_replfunc {
    public X vx_list_from_list_start_end<X>(X generic_any_1, X values, vx_core.Type_int start, vx_core.Type_int end) where X : vx_core.Type_list;
  }

  public class Class_list_from_list_start_end : vx_core.Class_base, Func_list_from_list_start_end {

    public override vx_collection.Func_list_from_list_start_end vx_new(params Object[] vals) {
      Class_list_from_list_start_end output = new Class_list_from_list_start_end();
      return output;
    }

    public override vx_collection.Func_list_from_list_start_end vx_copy(params Object[] vals) {
      Class_list_from_list_start_end output = new Class_list_from_list_start_end();
      return output;
    }

    public vx_core.Type_typedef vx_typedef() {
      return vx_core.t_func.vx_typedef();
    }

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/collection", // pkgname
        "list<-list-start-end", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override vx_core.Type_any vx_empty() {
      return e_list_from_list_start_end;
    }

    public override vx_core.Type_any vx_type() {
      return t_list_from_list_start_end;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_list generic_list_1 = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_list values = vx_core.f_any_from_any(vx_core.t_list, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_int start = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)));
      vx_core.Type_int end = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(2)));
      output = vx_collection.f_list_from_list_start_end(generic_list_1, values, start, end);
      return output;
    }

    public X vx_list_from_list_start_end<X>(X generic_list_1, X values, vx_core.Type_int start, vx_core.Type_int end) where X : vx_core.Type_list {
      return vx_collection.f_list_from_list_start_end(generic_list_1, values, start, end);
    }

  }

  public static Func_list_from_list_start_end e_list_from_list_start_end = new vx_collection.Class_list_from_list_start_end();
  public static Func_list_from_list_start_end t_list_from_list_start_end = new vx_collection.Class_list_from_list_start_end();

  public static X f_list_from_list_start_end<X>(X generic_list_1, X values, vx_core.Type_int start, vx_core.Type_int end) where X : vx_core.Type_list {
    X output = vx_core.f_empty(generic_list_1);
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
  public interface Func_map_from_map_end : vx_core.Type_func, vx_core.Type_replfunc {
    public N vx_map_from_map_end<N>(N generic_any_1, N valuemap, vx_core.Type_int end) where N : vx_core.Type_map;
  }

  public class Class_map_from_map_end : vx_core.Class_base, Func_map_from_map_end {

    public override vx_collection.Func_map_from_map_end vx_new(params Object[] vals) {
      Class_map_from_map_end output = new Class_map_from_map_end();
      return output;
    }

    public override vx_collection.Func_map_from_map_end vx_copy(params Object[] vals) {
      Class_map_from_map_end output = new Class_map_from_map_end();
      return output;
    }

    public vx_core.Type_typedef vx_typedef() {
      return vx_core.t_func.vx_typedef();
    }

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/collection", // pkgname
        "map<-map-end", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "map-1", // name
          ":map", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override vx_core.Type_any vx_empty() {
      return e_map_from_map_end;
    }

    public override vx_core.Type_any vx_type() {
      return t_map_from_map_end;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_map generic_map_1 = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_map valuemap = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_int end = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_collection.f_map_from_map_end(generic_map_1, valuemap, end);
      return output;
    }

    public N vx_map_from_map_end<N>(N generic_map_1, N valuemap, vx_core.Type_int end) where N : vx_core.Type_map {
      return vx_collection.f_map_from_map_end(generic_map_1, valuemap, end);
    }

  }

  public static Func_map_from_map_end e_map_from_map_end = new vx_collection.Class_map_from_map_end();
  public static Func_map_from_map_end t_map_from_map_end = new vx_collection.Class_map_from_map_end();

  public static N f_map_from_map_end<N>(N generic_map_1, N valuemap, vx_core.Type_int end) where N : vx_core.Type_map {
    N output = vx_core.f_empty(generic_map_1);
    output = vx_collection.f_map_from_map_start_end(generic_map_1, valuemap, vx_core.vx_new_int(1), end);
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
  public interface Func_map_from_map_keys : vx_core.Type_func, vx_core.Type_replfunc {
    public N vx_map_from_map_keys<N>(N generic_any_1, N valuemap, vx_core.Type_stringlist keys) where N : vx_core.Type_map;
  }

  public class Class_map_from_map_keys : vx_core.Class_base, Func_map_from_map_keys {

    public override vx_collection.Func_map_from_map_keys vx_new(params Object[] vals) {
      Class_map_from_map_keys output = new Class_map_from_map_keys();
      return output;
    }

    public override vx_collection.Func_map_from_map_keys vx_copy(params Object[] vals) {
      Class_map_from_map_keys output = new Class_map_from_map_keys();
      return output;
    }

    public vx_core.Type_typedef vx_typedef() {
      return vx_core.t_func.vx_typedef();
    }

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/collection", // pkgname
        "map<-map-keys", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "map-1", // name
          ":map", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override vx_core.Type_any vx_empty() {
      return e_map_from_map_keys;
    }

    public override vx_core.Type_any vx_type() {
      return t_map_from_map_keys;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_map generic_map_1 = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_map valuemap = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_stringlist keys = vx_core.f_any_from_any(vx_core.t_stringlist, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_collection.f_map_from_map_keys(generic_map_1, valuemap, keys);
      return output;
    }

    public N vx_map_from_map_keys<N>(N generic_map_1, N valuemap, vx_core.Type_stringlist keys) where N : vx_core.Type_map {
      return vx_collection.f_map_from_map_keys(generic_map_1, valuemap, keys);
    }

  }

  public static Func_map_from_map_keys e_map_from_map_keys = new vx_collection.Class_map_from_map_keys();
  public static Func_map_from_map_keys t_map_from_map_keys = new vx_collection.Class_map_from_map_keys();

  public static N f_map_from_map_keys<N>(N generic_map_1, N valuemap, vx_core.Type_stringlist keys) where N : vx_core.Type_map {
    N output = vx_core.f_empty(generic_map_1);
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
  public interface Func_map_from_map_start : vx_core.Type_func, vx_core.Type_replfunc {
    public N vx_map_from_map_start<N>(N generic_any_1, N valuemap, vx_core.Type_int start) where N : vx_core.Type_map;
  }

  public class Class_map_from_map_start : vx_core.Class_base, Func_map_from_map_start {

    public override vx_collection.Func_map_from_map_start vx_new(params Object[] vals) {
      Class_map_from_map_start output = new Class_map_from_map_start();
      return output;
    }

    public override vx_collection.Func_map_from_map_start vx_copy(params Object[] vals) {
      Class_map_from_map_start output = new Class_map_from_map_start();
      return output;
    }

    public vx_core.Type_typedef vx_typedef() {
      return vx_core.t_func.vx_typedef();
    }

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/collection", // pkgname
        "map<-map-start", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "map-1", // name
          ":map", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override vx_core.Type_any vx_empty() {
      return e_map_from_map_start;
    }

    public override vx_core.Type_any vx_type() {
      return t_map_from_map_start;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_map generic_map_1 = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_map valuemap = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_int start = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)));
      output = vx_collection.f_map_from_map_start(generic_map_1, valuemap, start);
      return output;
    }

    public N vx_map_from_map_start<N>(N generic_map_1, N valuemap, vx_core.Type_int start) where N : vx_core.Type_map {
      return vx_collection.f_map_from_map_start(generic_map_1, valuemap, start);
    }

  }

  public static Func_map_from_map_start e_map_from_map_start = new vx_collection.Class_map_from_map_start();
  public static Func_map_from_map_start t_map_from_map_start = new vx_collection.Class_map_from_map_start();

  public static N f_map_from_map_start<N>(N generic_map_1, N valuemap, vx_core.Type_int start) where N : vx_core.Type_map {
    N output = vx_core.f_empty(generic_map_1);
    output = vx_collection.f_map_from_map_start_end(
      generic_map_1,
      valuemap,
      start,
      vx_core.f_length_2(valuemap)
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
  public interface Func_map_from_map_start_end : vx_core.Type_func, vx_core.Type_replfunc {
    public N vx_map_from_map_start_end<N>(N generic_any_1, N valuemap, vx_core.Type_int start, vx_core.Type_int end) where N : vx_core.Type_map;
  }

  public class Class_map_from_map_start_end : vx_core.Class_base, Func_map_from_map_start_end {

    public override vx_collection.Func_map_from_map_start_end vx_new(params Object[] vals) {
      Class_map_from_map_start_end output = new Class_map_from_map_start_end();
      return output;
    }

    public override vx_collection.Func_map_from_map_start_end vx_copy(params Object[] vals) {
      Class_map_from_map_start_end output = new Class_map_from_map_start_end();
      return output;
    }

    public vx_core.Type_typedef vx_typedef() {
      return vx_core.t_func.vx_typedef();
    }

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/collection", // pkgname
        "map<-map-start-end", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "map-1", // name
          ":map", // extends
          vx_core.e_typelist, // traits
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_any), // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override vx_core.Type_any vx_empty() {
      return e_map_from_map_start_end;
    }

    public override vx_core.Type_any vx_type() {
      return t_map_from_map_start_end;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_map generic_map_1 = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_map valuemap = vx_core.f_any_from_any(vx_core.t_map, arglist.vx_any(vx_core.vx_new_int(0)));
      vx_core.Type_int start = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(1)));
      vx_core.Type_int end = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(2)));
      output = vx_collection.f_map_from_map_start_end(generic_map_1, valuemap, start, end);
      return output;
    }

    public N vx_map_from_map_start_end<N>(N generic_map_1, N valuemap, vx_core.Type_int start, vx_core.Type_int end) where N : vx_core.Type_map {
      return vx_collection.f_map_from_map_start_end(generic_map_1, valuemap, start, end);
    }

  }

  public static Func_map_from_map_start_end e_map_from_map_start_end = new vx_collection.Class_map_from_map_start_end();
  public static Func_map_from_map_start_end t_map_from_map_start_end = new vx_collection.Class_map_from_map_start_end();

  public static N f_map_from_map_start_end<N>(N generic_map_1, N valuemap, vx_core.Type_int start, vx_core.Type_int end) where N : vx_core.Type_map {
    N output = vx_core.f_empty(generic_map_1);
    output = vx_core.f_let(
      generic_map_1,
      vx_core.t_any_from_func.vx_fn_new(() => {
        vx_core.Type_stringlist keys1 = vx_core.f_stringlist_from_map(valuemap);
        vx_core.Type_stringlist keys2 = vx_collection.f_list_from_list_start_end(vx_core.t_stringlist, keys1, start, end);
        return vx_collection.f_map_from_map_keys(generic_map_1, valuemap, keys2);
      })
    );
    return output;
  }


  public static class PackageRunOnce {
    public static void RunOnce() {
    vx_core.Map<string, vx_core.Type_any> maptype = new vx_core.LinkedHashMap<string, vx_core.Type_any>();
    vx_core.Map<string, vx_core.Type_any> mapconst = new vx_core.LinkedHashMap<string, vx_core.Type_any>();
    vx_core.Map<string, vx_core.Type_func> mapfunc = new vx_core.LinkedHashMap<string, vx_core.Type_func>();
    mapfunc.put("any<-for-until-loop", vx_collection.t_any_from_for_until_loop);
    mapfunc.put("any<-for-until-loop-max", vx_collection.t_any_from_for_until_loop_max);
    mapfunc.put("any<-for-while-loop", vx_collection.t_any_from_for_while_loop);
    mapfunc.put("any<-for-while-loop-max", vx_collection.t_any_from_for_while_loop_max);
    mapfunc.put("any<-map-pos", vx_collection.t_any_from_map_pos);
    mapfunc.put("boolean-write<-map-removekey", vx_collection.t_boolean_write_from_map_removekey);
    mapfunc.put("boolean-write<-map-removekeys", vx_collection.t_boolean_write_from_map_removekeys);
    mapfunc.put("int<-map-key", vx_collection.t_int_from_map_key);
    mapfunc.put("int<-stringlist-find", vx_collection.t_int_from_stringlist_find);
    mapfunc.put("is-list", vx_collection.t_is_list);
    mapfunc.put("is-map", vx_collection.t_is_map);
    mapfunc.put("list<-for-end-loop", vx_collection.t_list_from_for_end_loop);
    mapfunc.put("list<-for-while-loop", vx_collection.t_list_from_for_while_loop);
    mapfunc.put("list<-for-while-loop-max", vx_collection.t_list_from_for_while_loop_max);
    mapfunc.put("list<-list-end", vx_collection.t_list_from_list_end);
    mapfunc.put("list<-list-filter", vx_collection.t_list_from_list_filter);
    mapfunc.put("list<-list-filtertypes", vx_collection.t_list_from_list_filtertypes);
    mapfunc.put("list<-list-start", vx_collection.t_list_from_list_start);
    mapfunc.put("list<-list-start-end", vx_collection.t_list_from_list_start_end);
    mapfunc.put("map<-map-end", vx_collection.t_map_from_map_end);
    mapfunc.put("map<-map-keys", vx_collection.t_map_from_map_keys);
    mapfunc.put("map<-map-start", vx_collection.t_map_from_map_start);
    mapfunc.put("map<-map-start-end", vx_collection.t_map_from_map_start_end);
    vx_core.vx_global_package_set("vx/collection", maptype, mapconst, mapfunc);
    }
  }

}
