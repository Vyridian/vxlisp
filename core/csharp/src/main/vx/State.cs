namespace Vx;

public static class Vx_state {


  /**
   * type: valuemap
   * (type valuemap)
   */
  public interface Type_valuemap : Vx_core.Type_map {
    public Vx_core.Type_any vx_new(params Object[] vals);
    public Vx_core.Type_any vx_copy(params Object[] vals);
    public Vx_core.Type_any vx_empty();
    public Vx_core.Type_any vx_type();
  }

  public class Class_valuemap : Vx_core.Class_base, Type_valuemap {

    public Vx_core.Map<string, Vx_core.Type_any> vx_p_map = Vx_core.immutablemap(new Vx_core.LinkedHashMap<string, Vx_core.Type_any>());

    public Vx_core.Map<string, Vx_core.Type_any> vx_map() {
      Vx_core.Map<string, Vx_core.Type_any> anymap = (Vx_core.Map<string, Vx_core.Type_any>)this.vx_p_map;
      Vx_core.Map<string, Vx_core.Type_any> map = anymap.copy();
      return Vx_core.immutablemap(map);
    }

    public Vx_core.Type_boolean vx_set(Vx_core.Type_string name, Vx_core.Type_any value) {
      Vx_core.Type_boolean output = Vx_core.c_false;
      if (value is Vx_core.Type_any) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx_core.Type_any castval = (Vx_core.Type_any)value;
        Vx_core.Map<string, Vx_core.Type_any> map = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>(this.vx_p_map);
        if (castval == Vx_core.e_any) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx_core.immutablemap(map);
        output = Vx_core.c_true;
      }
      return output;
    }

    public Vx_core.Type_any vx_any(Vx_core.Type_string key) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_state.Class_valuemap map = this;
      string skey = key.vx_string();
      Vx_core.Map<string, Vx_core.Type_any> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Vx_core.e_any);
      return output;
    }

    public Vx_core.Type_map vx_new_from_map(Vx_core.Map<string, Vx_core.Type_any> mapval) {
      Vx_state.Class_valuemap output = new Vx_state.Class_valuemap();
      Vx_core.Type_msgblock msgblock = Vx_core.e_msgblock;
      Vx_core.Map<string, Vx_core.Type_any> map = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx_core.Type_any val = mapval.get(key);
        if (val is Vx_core.Type_any) {
          Vx_core.Type_any castval = (Vx_core.Type_any)val;
          map.put(key, castval);
        } else {
          Vx_core.Type_msg msg = Vx_core.vx_msg_from_error("vx/state/valuemap", ":invalidvalue", val);
          msgblock = Vx_core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx_core.immutablemap(map);
      if (msgblock != Vx_core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx_state.Type_valuemap vx_new(params Object[] vals) {
      return Vx_core.vx_copy(
       e_valuemap,
       vals);
    }

    public override Vx_state.Type_valuemap vx_copy(params Object[] vals) {
      Type_valuemap output = this;
      bool ischanged = false;
      Class_valuemap val = this;
      Vx_core.Type_msgblock msgblock = Vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx_core.vx_Type_const) {
        ischanged = true;
      }
      Vx_core.Map<string, Vx_core.Type_any> mapval = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>(val.vx_map());
      Vx_core.Type_msg msg;
      string key = "";
      Vx_core.Type_any msgval;
      foreach (Object valsub in vals) {
        if (valsub is Vx_core.Type_msgblock) {
          msgblock = Vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx_core.Type_msg) {
          msgblock = Vx_core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          if (valsub is Vx_core.Type_string) {
            Vx_core.Type_string valstring = valsub as Vx_core.Type_string;
            key = valstring.vx_string();
          } else if (valsub is string) {
            key = valsub as string;
          } else {
            if (valsub is Vx_core.Type_any) {
              msgval = valsub as Vx_core.Type_any;
            } else {
              msgval = Vx_core.vx_new_string(valsub.ToString());
            }
            msg = Vx_core.vx_msg_from_error("vx/state/valuemap", ":keyexpected", msgval);
            msgblock = Vx_core.vx_copy(msgblock, msg);
          }
        } else {
          Vx_core.Type_any valany = null;
          if (valsub is Vx_core.Type_any) {
            valany = (Vx_core.Type_any)valsub;
          } else if (valsub is Vx_core.Type_any) {
            valany = valsub as Vx_core.Type_any;
          } else {
            if (valsub is Vx_core.Type_any) {
              msgval = valsub as Vx_core.Type_any;
            } else {
              msgval = Vx_core.vx_new_string(valsub.ToString());
            }
            Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
            mapany.put("key", Vx_core.vx_new_string(key));
            mapany.put("value", msgval);
            Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
            msg = Vx_core.vx_msg_from_error("vx/state/valuemap", ":invalidkeyvalue", msgmap);
            msgblock = Vx_core.vx_copy(msgblock, msg);
          }
          if (valany != null) {
            ischanged = true;
            if (key.StartsWith(":")) {
              key = key.Substring(1);
            }
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Vx_core.e_msgblock)) {
        Class_valuemap work = new Class_valuemap();
        work.vx_p_map = Vx_core.immutablemap(mapval);
        if (msgblock != Vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx_core.Type_any vx_empty() {
      return e_valuemap;
    }
    public override Vx_core.Type_any vx_type() {
      return t_valuemap;
    }

    public override Vx_core.Type_typedef vx_typedef() {
      return Vx_core.typedef_new(
        "vx/state", // pkgname
        "valuemap", // name
        ":map", // extends
        Vx_core.e_typelist, // traits
        Vx_core.vx_new(Vx_core.t_typelist, Vx_core.t_any), // allowtypes
        Vx_core.e_typelist, // disallowtypes
        Vx_core.e_funclist, // allowfuncs
        Vx_core.e_funclist, // disallowfuncs
        Vx_core.e_anylist, // allowvalues
        Vx_core.e_anylist, // disallowvalues
        Vx_core.e_argmap // properties
      );
    }

  }

  public static Type_valuemap e_valuemap = new Class_valuemap();
  public static Type_valuemap t_valuemap = new Class_valuemap();
  /**
   * @function any_readstate_from_mapname_name
   * Returns the named state value
   * @param  {string} mapname
   * @param  {string} name
   * @return {any-1}
   * (func any-readstate<-mapname-name)
   */
  public interface Func_any_readstate_from_mapname_name : Vx_core.Type_func, Vx_core.Type_replfunc {
    public T vx_any_readstate_from_mapname_name<T>(T generic_any_1, Vx_core.Type_context context, Vx_core.Type_string mapname, Vx_core.Type_string name) where T : Vx_core.Type_any;
  }

  public class Class_any_readstate_from_mapname_name : Vx_core.Class_base, Func_any_readstate_from_mapname_name {

    public override Vx_state.Func_any_readstate_from_mapname_name vx_new(params Object[] vals) {
      Class_any_readstate_from_mapname_name output = new Class_any_readstate_from_mapname_name();
      return output;
    }

    public override Vx_state.Func_any_readstate_from_mapname_name vx_copy(params Object[] vals) {
      Class_any_readstate_from_mapname_name output = new Class_any_readstate_from_mapname_name();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/state", // pkgname
        "any-readstate<-mapname-name", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          Vx_core.e_typelist, // traits
          Vx_core.e_typelist, // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx_core.Type_any vx_empty() {
      return e_any_readstate_from_mapname_name;
    }

    public override Vx_core.Type_any vx_type() {
      return t_any_readstate_from_mapname_name;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_any generic_any_1 = Vx_core.f_any_from_any(Vx_core.t_any, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_string mapname = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_string name = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(1)));
      output = Vx_state.f_any_readstate_from_mapname_name(generic_any_1, context, mapname, name);
      return output;
    }

    public T vx_any_readstate_from_mapname_name<T>(T generic_any_1, Vx_core.Type_context context, Vx_core.Type_string mapname, Vx_core.Type_string name) where T : Vx_core.Type_any {
      return Vx_state.f_any_readstate_from_mapname_name(generic_any_1, context, mapname, name);
    }

  }

  public static Func_any_readstate_from_mapname_name e_any_readstate_from_mapname_name = new Vx_state.Class_any_readstate_from_mapname_name();
  public static Func_any_readstate_from_mapname_name t_any_readstate_from_mapname_name = new Vx_state.Class_any_readstate_from_mapname_name();

  public static T f_any_readstate_from_mapname_name<T>(T generic_any_1, Vx_core.Type_context context, Vx_core.Type_string mapname, Vx_core.Type_string name) where T : Vx_core.Type_any {
    T output = Vx_core.f_empty(generic_any_1);
    output = Vx_core.f_let(
      generic_any_1,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_state.Type_valuemap submap = Vx_state.f_valuemap_readstate_from_mapname(context, mapname);
        return Vx_core.f_any_from_map(generic_any_1, submap, name);
      })
    );
    return output;
  }

  /**
   * @function any_readstate_from_name
   * Returns the named state value
   * @param  {string} name
   * @return {any-1}
   * (func any-readstate<-name)
   */
  public interface Func_any_readstate_from_name : Vx_core.Func_any_from_any_context {
    public T vx_any_readstate_from_name<T>(T generic_any_1, Vx_core.Type_context context, Vx_core.Type_string name) where T : Vx_core.Type_any;
  }

  public class Class_any_readstate_from_name : Vx_core.Class_base, Func_any_readstate_from_name {

    public override Vx_state.Func_any_readstate_from_name vx_new(params Object[] vals) {
      Class_any_readstate_from_name output = new Class_any_readstate_from_name();
      return output;
    }

    public override Vx_state.Func_any_readstate_from_name vx_copy(params Object[] vals) {
      Class_any_readstate_from_name output = new Class_any_readstate_from_name();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/state", // pkgname
        "any-readstate<-name", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          Vx_core.e_typelist, // traits
          Vx_core.e_typelist, // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx_core.Type_any vx_empty() {
      return e_any_readstate_from_name;
    }

    public override Vx_core.Type_any vx_type() {
      return t_any_readstate_from_name;
    }

    public Vx_core.Func_any_from_any_context vx_fn_new(Vx_core.Class_any_from_any_context.IFn fn) {
      return Vx_core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx_core.Type_context context, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_core.Type_string inputval = (Vx_core.Type_string)value;
      Vx_core.Type_any outputval = Vx_state.f_any_readstate_from_name(Vx_core.t_any, context, inputval);
      output = Vx_core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_any generic_any_1 = Vx_core.f_any_from_any(Vx_core.t_any, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_string name = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_state.f_any_readstate_from_name(generic_any_1, context, name);
      return output;
    }

    public T vx_any_readstate_from_name<T>(T generic_any_1, Vx_core.Type_context context, Vx_core.Type_string name) where T : Vx_core.Type_any {
      return Vx_state.f_any_readstate_from_name(generic_any_1, context, name);
    }

  }

  public static Func_any_readstate_from_name e_any_readstate_from_name = new Vx_state.Class_any_readstate_from_name();
  public static Func_any_readstate_from_name t_any_readstate_from_name = new Vx_state.Class_any_readstate_from_name();

  public static T f_any_readstate_from_name<T>(T generic_any_1, Vx_core.Type_context context, Vx_core.Type_string name) where T : Vx_core.Type_any {
    T output = Vx_core.f_empty(generic_any_1);
    output = Vx_core.f_any_from_any(
      generic_any_1,
      Vx_state.f_value_readstate_from_name(context, name)
    );
    return output;
  }

  /**
   * @function boolean_removestate_from_name
   * Returns true if named statelistener was removed.
   * @param  {string} name
   * @return {boolean}
   * (func boolean-removestate<-name)
   */
  public interface Func_boolean_removestate_from_name : Vx_core.Func_any_from_any_context {
    public Vx_core.Type_boolean vx_boolean_removestate_from_name(Vx_core.Type_context context, Vx_core.Type_string name);
  }

  public class Class_boolean_removestate_from_name : Vx_core.Class_base, Func_boolean_removestate_from_name {

    public override Vx_state.Func_boolean_removestate_from_name vx_new(params Object[] vals) {
      Class_boolean_removestate_from_name output = new Class_boolean_removestate_from_name();
      return output;
    }

    public override Vx_state.Func_boolean_removestate_from_name vx_copy(params Object[] vals) {
      Class_boolean_removestate_from_name output = new Class_boolean_removestate_from_name();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/state", // pkgname
        "boolean-removestate<-name", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx_core.e_typelist, // traits
          Vx_core.e_typelist, // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx_core.Type_any vx_empty() {
      return e_boolean_removestate_from_name;
    }

    public override Vx_core.Type_any vx_type() {
      return t_boolean_removestate_from_name;
    }

    public Vx_core.Func_any_from_any_context vx_fn_new(Vx_core.Class_any_from_any_context.IFn fn) {
      return Vx_core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx_core.Type_context context, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_core.Type_string inputval = (Vx_core.Type_string)value;
      Vx_core.Type_any outputval = Vx_state.f_boolean_removestate_from_name(context, inputval);
      output = Vx_core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_string name = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_state.f_boolean_removestate_from_name(context, name);
      return output;
    }

    public Vx_core.Type_boolean vx_boolean_removestate_from_name(Vx_core.Type_context context, Vx_core.Type_string name) {
      return Vx_state.f_boolean_removestate_from_name(context, name);
    }

  }

  public static Func_boolean_removestate_from_name e_boolean_removestate_from_name = new Vx_state.Class_boolean_removestate_from_name();
  public static Func_boolean_removestate_from_name t_boolean_removestate_from_name = new Vx_state.Class_boolean_removestate_from_name();

  public static Vx_core.Type_boolean f_boolean_removestate_from_name(Vx_core.Type_context context, Vx_core.Type_string name) {
    Vx_core.Type_boolean output = Vx_core.e_boolean;
    output = Vx_core.f_let(
      Vx_core.t_boolean,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_core.Type_statelistenermap statelistenermap = Vx_state.f_statelistenermap_readstate(context);
        return Vx_core.f_boolean_write_from_map_name_value(
          statelistenermap,
          name,
          Vx_core.f_empty(
            Vx_core.t_statelistener
          )
        );
      })
    );
    return output;
  }

  /**
   * @function boolean_writestate_from_mapname_name_value
   * Returns the named state value and changes it to the new value
   * @param  {string} mapname
   * @param  {string} name
   * @param  {any} value
   * @return {boolean}
   * (func boolean-writestate<-mapname-name-value)
   */
  public interface Func_boolean_writestate_from_mapname_name_value : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_core.Type_boolean vx_boolean_writestate_from_mapname_name_value(Vx_core.Type_context context, Vx_core.Type_string mapname, Vx_core.Type_string name, Vx_core.Type_any value);
  }

  public class Class_boolean_writestate_from_mapname_name_value : Vx_core.Class_base, Func_boolean_writestate_from_mapname_name_value {

    public override Vx_state.Func_boolean_writestate_from_mapname_name_value vx_new(params Object[] vals) {
      Class_boolean_writestate_from_mapname_name_value output = new Class_boolean_writestate_from_mapname_name_value();
      return output;
    }

    public override Vx_state.Func_boolean_writestate_from_mapname_name_value vx_copy(params Object[] vals) {
      Class_boolean_writestate_from_mapname_name_value output = new Class_boolean_writestate_from_mapname_name_value();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/state", // pkgname
        "boolean-writestate<-mapname-name-value", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx_core.e_typelist, // traits
          Vx_core.e_typelist, // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx_core.Type_any vx_empty() {
      return e_boolean_writestate_from_mapname_name_value;
    }

    public override Vx_core.Type_any vx_type() {
      return t_boolean_writestate_from_mapname_name_value;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_string mapname = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_string name = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(1)));
      Vx_core.Type_any value = Vx_core.f_any_from_any(Vx_core.t_any, arglist.vx_any(Vx_core.vx_new_int(2)));
      output = Vx_state.f_boolean_writestate_from_mapname_name_value(context, mapname, name, value);
      return output;
    }

    public Vx_core.Type_boolean vx_boolean_writestate_from_mapname_name_value(Vx_core.Type_context context, Vx_core.Type_string mapname, Vx_core.Type_string name, Vx_core.Type_any value) {
      return Vx_state.f_boolean_writestate_from_mapname_name_value(context, mapname, name, value);
    }

  }

  public static Func_boolean_writestate_from_mapname_name_value e_boolean_writestate_from_mapname_name_value = new Vx_state.Class_boolean_writestate_from_mapname_name_value();
  public static Func_boolean_writestate_from_mapname_name_value t_boolean_writestate_from_mapname_name_value = new Vx_state.Class_boolean_writestate_from_mapname_name_value();

  public static Vx_core.Type_boolean f_boolean_writestate_from_mapname_name_value(Vx_core.Type_context context, Vx_core.Type_string mapname, Vx_core.Type_string name, Vx_core.Type_any value) {
    Vx_core.Type_boolean output = Vx_core.e_boolean;
    output = Vx_core.f_let(
      Vx_core.t_boolean,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_state.Type_valuemap valmap = Vx_state.f_any_readstate_from_name(Vx_state.t_valuemap, context, mapname);
        return Vx_core.f_if_2(
          Vx_core.t_boolean,
          Vx_core.vx_new(Vx_core.t_thenelselist,
            Vx_core.f_then(
              Vx_core.t_boolean_from_func.vx_fn_new(() => {
                return Vx_core.f_is_empty_1(valmap);
              }),
              Vx_core.t_any_from_func.vx_fn_new(() => {
                return Vx_core.f_let(
                  Vx_core.t_boolean,
                  Vx_core.t_any_from_func.vx_fn_new(() => {
                    Vx_state.Type_valuemap valmap2 = Vx_core.f_new(
                      Vx_state.t_valuemap,
                      Vx_core.vx_new(Vx_core.t_anylist,
                          name,
                          value
                      )
                    );
                    Vx_core.Type_statelistener listener = Vx_core.f_new(
                      Vx_core.t_statelistener,
                      Vx_core.vx_new(Vx_core.t_anylist,
                          Vx_core.vx_new_string(":name"),
                          mapname,
                          Vx_core.vx_new_string(":value"),
                          valmap2
                      )
                    );
                    return Vx_state.f_boolean_writestate_from_statelistener(context, listener);
                  })
                );
              })
            ),
            Vx_core.f_else(
              Vx_core.t_any_from_func.vx_fn_new(() => {
                return Vx_core.f_boolean_write_from_map_name_value(valmap, name, value);
              })
            )
          )
        );
      })
    );
    return output;
  }

  /**
   * @function boolean_writestate_from_name_value
   * Returns the named state value and changes it to the new value
   * @param  {string} name
   * @param  {any} value
   * @return {boolean}
   * (func boolean-writestate<-name-value)
   */
  public interface Func_boolean_writestate_from_name_value : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_core.Type_boolean vx_boolean_writestate_from_name_value(Vx_core.Type_context context, Vx_core.Type_string name, Vx_core.Type_any value);
  }

  public class Class_boolean_writestate_from_name_value : Vx_core.Class_base, Func_boolean_writestate_from_name_value {

    public override Vx_state.Func_boolean_writestate_from_name_value vx_new(params Object[] vals) {
      Class_boolean_writestate_from_name_value output = new Class_boolean_writestate_from_name_value();
      return output;
    }

    public override Vx_state.Func_boolean_writestate_from_name_value vx_copy(params Object[] vals) {
      Class_boolean_writestate_from_name_value output = new Class_boolean_writestate_from_name_value();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/state", // pkgname
        "boolean-writestate<-name-value", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx_core.e_typelist, // traits
          Vx_core.e_typelist, // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx_core.Type_any vx_empty() {
      return e_boolean_writestate_from_name_value;
    }

    public override Vx_core.Type_any vx_type() {
      return t_boolean_writestate_from_name_value;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_string name = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_any value = Vx_core.f_any_from_any(Vx_core.t_any, arglist.vx_any(Vx_core.vx_new_int(1)));
      output = Vx_state.f_boolean_writestate_from_name_value(context, name, value);
      return output;
    }

    public Vx_core.Type_boolean vx_boolean_writestate_from_name_value(Vx_core.Type_context context, Vx_core.Type_string name, Vx_core.Type_any value) {
      return Vx_state.f_boolean_writestate_from_name_value(context, name, value);
    }

  }

  public static Func_boolean_writestate_from_name_value e_boolean_writestate_from_name_value = new Vx_state.Class_boolean_writestate_from_name_value();
  public static Func_boolean_writestate_from_name_value t_boolean_writestate_from_name_value = new Vx_state.Class_boolean_writestate_from_name_value();

  public static Vx_core.Type_boolean f_boolean_writestate_from_name_value(Vx_core.Type_context context, Vx_core.Type_string name, Vx_core.Type_any value) {
    Vx_core.Type_boolean output = Vx_core.e_boolean;
    output = Vx_core.f_let(
      Vx_core.t_boolean,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_core.Type_statelistener listenercur = Vx_state.f_statelistener_readstate_from_name(context, name);
        Vx_core.Type_statelistener listenerchg = Vx_core.f_copy(
          listenercur,
          Vx_core.vx_new(Vx_core.t_anylist,
              Vx_core.vx_new_string(":name"),
              name,
              Vx_core.vx_new_string(":value"),
              value
          )
        );
        return Vx_state.f_boolean_writestate_from_statelistener(context, listenerchg);
      })
    );
    return output;
  }

  /**
   * @function boolean_writestate_from_statelistener
   * Writes statelistener into state
   * @param  {statelistener} statelistener
   * @return {boolean}
   * (func boolean-writestate<-statelistener)
   */
  public interface Func_boolean_writestate_from_statelistener : Vx_core.Func_any_from_any_context {
    public Vx_core.Type_boolean vx_boolean_writestate_from_statelistener(Vx_core.Type_context context, Vx_core.Type_statelistener statelistener);
  }

  public class Class_boolean_writestate_from_statelistener : Vx_core.Class_base, Func_boolean_writestate_from_statelistener {

    public override Vx_state.Func_boolean_writestate_from_statelistener vx_new(params Object[] vals) {
      Class_boolean_writestate_from_statelistener output = new Class_boolean_writestate_from_statelistener();
      return output;
    }

    public override Vx_state.Func_boolean_writestate_from_statelistener vx_copy(params Object[] vals) {
      Class_boolean_writestate_from_statelistener output = new Class_boolean_writestate_from_statelistener();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/state", // pkgname
        "boolean-writestate<-statelistener", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx_core.e_typelist, // traits
          Vx_core.e_typelist, // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx_core.Type_any vx_empty() {
      return e_boolean_writestate_from_statelistener;
    }

    public override Vx_core.Type_any vx_type() {
      return t_boolean_writestate_from_statelistener;
    }

    public Vx_core.Func_any_from_any_context vx_fn_new(Vx_core.Class_any_from_any_context.IFn fn) {
      return Vx_core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx_core.Type_context context, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_core.Type_statelistener inputval = (Vx_core.Type_statelistener)value;
      Vx_core.Type_any outputval = Vx_state.f_boolean_writestate_from_statelistener(context, inputval);
      output = Vx_core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_statelistener statelistener = Vx_core.f_any_from_any(Vx_core.t_statelistener, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_state.f_boolean_writestate_from_statelistener(context, statelistener);
      return output;
    }

    public Vx_core.Type_boolean vx_boolean_writestate_from_statelistener(Vx_core.Type_context context, Vx_core.Type_statelistener statelistener) {
      return Vx_state.f_boolean_writestate_from_statelistener(context, statelistener);
    }

  }

  public static Func_boolean_writestate_from_statelistener e_boolean_writestate_from_statelistener = new Vx_state.Class_boolean_writestate_from_statelistener();
  public static Func_boolean_writestate_from_statelistener t_boolean_writestate_from_statelistener = new Vx_state.Class_boolean_writestate_from_statelistener();

  public static Vx_core.Type_boolean f_boolean_writestate_from_statelistener(Vx_core.Type_context context, Vx_core.Type_statelistener statelistener) {
    Vx_core.Type_boolean output = Vx_core.e_boolean;
    output = Vx_core.f_let(
      Vx_core.t_boolean,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_core.Type_statelistenermap statelistenermap = Vx_state.f_statelistenermap_readstate(context);
        Vx_core.Type_string name = statelistener.name();
        return Vx_core.f_boolean_write_from_map_name_value(statelistenermap, name, statelistener);
      })
    );
    return output;
  }

  /**
   * @function change
   * Changes the current state
   * @param  {valuemap} valuemap
   * @return {boolean}
   * (func change)
   */
  public interface Func_change : Vx_core.Func_any_from_any {
    public Vx_core.Type_boolean vx_change(Vx_state.Type_valuemap valuemap);
  }

  public class Class_change : Vx_core.Class_base, Func_change {

    public override Vx_state.Func_change vx_new(params Object[] vals) {
      Class_change output = new Class_change();
      return output;
    }

    public override Vx_state.Func_change vx_copy(params Object[] vals) {
      Class_change output = new Class_change();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/state", // pkgname
        "change", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx_core.e_typelist, // traits
          Vx_core.e_typelist, // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx_core.Type_any vx_empty() {
      return e_change;
    }

    public override Vx_core.Type_any vx_type() {
      return t_change;
    }

    public Vx_core.Func_any_from_any vx_fn_new(Vx_core.Class_any_from_any.IFn fn) {
      return Vx_core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_state.Type_valuemap inputval = (Vx_state.Type_valuemap)value;
      Vx_core.Type_any outputval = Vx_state.f_change(inputval);
      output = Vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_state.Type_valuemap valuemap = Vx_core.f_any_from_any(Vx_state.t_valuemap, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_state.f_change(valuemap);
      return output;
    }

    public Vx_core.Type_boolean vx_change(Vx_state.Type_valuemap valuemap) {
      return Vx_state.f_change(valuemap);
    }

  }

  public static Func_change e_change = new Vx_state.Class_change();
  public static Func_change t_change = new Vx_state.Class_change();

  public static Vx_core.Type_boolean f_change(Vx_state.Type_valuemap valuemap) {
    Vx_core.Type_boolean output = Vx_core.e_boolean;
    return output;
  }

  /**
   * @function register
   * @param  {statelistener} listener
   * @return {boolean}
   * (func register)
   */
  public interface Func_register : Vx_core.Func_any_from_any {
    public Vx_core.Type_boolean vx_register(Vx_core.Type_statelistener listener);
  }

  public class Class_register : Vx_core.Class_base, Func_register {

    public override Vx_state.Func_register vx_new(params Object[] vals) {
      Class_register output = new Class_register();
      return output;
    }

    public override Vx_state.Func_register vx_copy(params Object[] vals) {
      Class_register output = new Class_register();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/state", // pkgname
        "register", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx_core.e_typelist, // traits
          Vx_core.e_typelist, // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx_core.Type_any vx_empty() {
      return e_register;
    }

    public override Vx_core.Type_any vx_type() {
      return t_register;
    }

    public Vx_core.Func_any_from_any vx_fn_new(Vx_core.Class_any_from_any.IFn fn) {
      return Vx_core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_core.Type_statelistener inputval = (Vx_core.Type_statelistener)value;
      Vx_core.Type_any outputval = Vx_state.f_register(inputval);
      output = Vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_statelistener listener = Vx_core.f_any_from_any(Vx_core.t_statelistener, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_state.f_register(listener);
      return output;
    }

    public Vx_core.Type_boolean vx_register(Vx_core.Type_statelistener listener) {
      return Vx_state.f_register(listener);
    }

  }

  public static Func_register e_register = new Vx_state.Class_register();
  public static Func_register t_register = new Vx_state.Class_register();

  public static Vx_core.Type_boolean f_register(Vx_core.Type_statelistener listener) {
    Vx_core.Type_boolean output = Vx_core.e_boolean;
    return output;
  }

  /**
   * @function state_from_context
   * Returns the full current state
   * @return {state}
   * (func state<-context)
   */
  public interface Func_state_from_context : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_core.Type_state vx_state_from_context(Vx_core.Type_context context);
  }

  public class Class_state_from_context : Vx_core.Class_base, Func_state_from_context {

    public override Vx_state.Func_state_from_context vx_new(params Object[] vals) {
      Class_state_from_context output = new Class_state_from_context();
      return output;
    }

    public override Vx_state.Func_state_from_context vx_copy(params Object[] vals) {
      Class_state_from_context output = new Class_state_from_context();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/state", // pkgname
        "state<-context", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "state", // name
          ":struct", // extends
          Vx_core.e_typelist, // traits
          Vx_core.e_typelist, // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx_core.Type_any vx_empty() {
      return e_state_from_context;
    }

    public override Vx_core.Type_any vx_type() {
      return t_state_from_context;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_state.f_state_from_context(context);
      return output;
    }

    public Vx_core.Type_state vx_state_from_context(Vx_core.Type_context context) {
      return Vx_state.f_state_from_context(context);
    }

  }

  public static Func_state_from_context e_state_from_context = new Vx_state.Class_state_from_context();
  public static Func_state_from_context t_state_from_context = new Vx_state.Class_state_from_context();

  public static Vx_core.Type_state f_state_from_context(Vx_core.Type_context context) {
    Vx_core.Type_state output = Vx_core.e_state;
    output = context.state();
    return output;
  }

  /**
   * @function statelistener_readstate_from_name
   * Returns the named statelistener
   * @param  {string} name
   * @return {statelistener}
   * (func statelistener-readstate<-name)
   */
  public interface Func_statelistener_readstate_from_name : Vx_core.Func_any_from_any_context {
    public Vx_core.Type_statelistener vx_statelistener_readstate_from_name(Vx_core.Type_context context, Vx_core.Type_string name);
  }

  public class Class_statelistener_readstate_from_name : Vx_core.Class_base, Func_statelistener_readstate_from_name {

    public override Vx_state.Func_statelistener_readstate_from_name vx_new(params Object[] vals) {
      Class_statelistener_readstate_from_name output = new Class_statelistener_readstate_from_name();
      return output;
    }

    public override Vx_state.Func_statelistener_readstate_from_name vx_copy(params Object[] vals) {
      Class_statelistener_readstate_from_name output = new Class_statelistener_readstate_from_name();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/state", // pkgname
        "statelistener-readstate<-name", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "statelistener", // name
          ":struct", // extends
          Vx_core.e_typelist, // traits
          Vx_core.e_typelist, // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx_core.Type_any vx_empty() {
      return e_statelistener_readstate_from_name;
    }

    public override Vx_core.Type_any vx_type() {
      return t_statelistener_readstate_from_name;
    }

    public Vx_core.Func_any_from_any_context vx_fn_new(Vx_core.Class_any_from_any_context.IFn fn) {
      return Vx_core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx_core.Type_context context, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_core.Type_string inputval = (Vx_core.Type_string)value;
      Vx_core.Type_any outputval = Vx_state.f_statelistener_readstate_from_name(context, inputval);
      output = Vx_core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_string name = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_state.f_statelistener_readstate_from_name(context, name);
      return output;
    }

    public Vx_core.Type_statelistener vx_statelistener_readstate_from_name(Vx_core.Type_context context, Vx_core.Type_string name) {
      return Vx_state.f_statelistener_readstate_from_name(context, name);
    }

  }

  public static Func_statelistener_readstate_from_name e_statelistener_readstate_from_name = new Vx_state.Class_statelistener_readstate_from_name();
  public static Func_statelistener_readstate_from_name t_statelistener_readstate_from_name = new Vx_state.Class_statelistener_readstate_from_name();

  public static Vx_core.Type_statelistener f_statelistener_readstate_from_name(Vx_core.Type_context context, Vx_core.Type_string name) {
    Vx_core.Type_statelistener output = Vx_core.e_statelistener;
    output = Vx_core.f_let(
      Vx_core.t_statelistener,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_core.Type_statelistenermap statelistenermap = Vx_state.f_statelistenermap_readstate(context);
        return Vx_core.f_any_from_map(Vx_core.t_statelistener, statelistenermap, name);
      })
    );
    return output;
  }

  /**
   * @function statelistenermap_readstate
   * Returns the current state valuemap
   * @return {statelistenermap}
   * (func statelistenermap-readstate)
   */
  public interface Func_statelistenermap_readstate : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_core.Type_statelistenermap vx_statelistenermap_readstate(Vx_core.Type_context context);
  }

  public class Class_statelistenermap_readstate : Vx_core.Class_base, Func_statelistenermap_readstate {

    public override Vx_state.Func_statelistenermap_readstate vx_new(params Object[] vals) {
      Class_statelistenermap_readstate output = new Class_statelistenermap_readstate();
      return output;
    }

    public override Vx_state.Func_statelistenermap_readstate vx_copy(params Object[] vals) {
      Class_statelistenermap_readstate output = new Class_statelistenermap_readstate();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/state", // pkgname
        "statelistenermap-readstate", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "statelistenermap", // name
          ":map", // extends
          Vx_core.e_typelist, // traits
          Vx_core.vx_new(Vx_core.t_typelist, Vx_core.t_statelistener), // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx_core.Type_any vx_empty() {
      return e_statelistenermap_readstate;
    }

    public override Vx_core.Type_any vx_type() {
      return t_statelistenermap_readstate;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_state.f_statelistenermap_readstate(context);
      return output;
    }

    public Vx_core.Type_statelistenermap vx_statelistenermap_readstate(Vx_core.Type_context context) {
      return Vx_state.f_statelistenermap_readstate(context);
    }

  }

  public static Func_statelistenermap_readstate e_statelistenermap_readstate = new Vx_state.Class_statelistenermap_readstate();
  public static Func_statelistenermap_readstate t_statelistenermap_readstate = new Vx_state.Class_statelistenermap_readstate();

  public static Vx_core.Type_statelistenermap f_statelistenermap_readstate(Vx_core.Type_context context) {
    Vx_core.Type_statelistenermap output = Vx_core.e_statelistenermap;
    output = Vx_core.f_let(
      Vx_core.t_statelistenermap,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_core.Type_state state = Vx_state.f_state_from_context(context);
        return state.statelistenermap();
      })
    );
    return output;
  }

  /**
   * @function value_readstate_from_name
   * Returns the named state value
   * @param  {string} name
   * @return {any}
   * (func value-readstate<-name)
   */
  public interface Func_value_readstate_from_name : Vx_core.Func_any_from_any_context {
    public Vx_core.Type_any vx_value_readstate_from_name(Vx_core.Type_context context, Vx_core.Type_string name);
  }

  public class Class_value_readstate_from_name : Vx_core.Class_base, Func_value_readstate_from_name {

    public override Vx_state.Func_value_readstate_from_name vx_new(params Object[] vals) {
      Class_value_readstate_from_name output = new Class_value_readstate_from_name();
      return output;
    }

    public override Vx_state.Func_value_readstate_from_name vx_copy(params Object[] vals) {
      Class_value_readstate_from_name output = new Class_value_readstate_from_name();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/state", // pkgname
        "value-readstate<-name", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "any", // name
          "", // extends
          Vx_core.e_typelist, // traits
          Vx_core.e_typelist, // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx_core.Type_any vx_empty() {
      return e_value_readstate_from_name;
    }

    public override Vx_core.Type_any vx_type() {
      return t_value_readstate_from_name;
    }

    public Vx_core.Func_any_from_any_context vx_fn_new(Vx_core.Class_any_from_any_context.IFn fn) {
      return Vx_core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx_core.Type_context context, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_core.Type_string inputval = (Vx_core.Type_string)value;
      Vx_core.Type_any outputval = Vx_state.f_value_readstate_from_name(context, inputval);
      output = Vx_core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_string name = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_state.f_value_readstate_from_name(context, name);
      return output;
    }

    public Vx_core.Type_any vx_value_readstate_from_name(Vx_core.Type_context context, Vx_core.Type_string name) {
      return Vx_state.f_value_readstate_from_name(context, name);
    }

  }

  public static Func_value_readstate_from_name e_value_readstate_from_name = new Vx_state.Class_value_readstate_from_name();
  public static Func_value_readstate_from_name t_value_readstate_from_name = new Vx_state.Class_value_readstate_from_name();

  public static Vx_core.Type_any f_value_readstate_from_name(Vx_core.Type_context context, Vx_core.Type_string name) {
    Vx_core.Type_any output = Vx_core.e_any;
    output = Vx_core.f_let(
      Vx_core.t_any,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_core.Type_statelistener statelistener = Vx_state.f_statelistener_readstate_from_name(context, name);
        return statelistener.value();
      })
    );
    return output;
  }

  /**
   * @function valuemap_readstate_from_mapname
   * Returns the current state valuemap
   * @param  {string} mapname
   * @return {valuemap}
   * (func valuemap-readstate<-mapname)
   */
  public interface Func_valuemap_readstate_from_mapname : Vx_core.Func_any_from_any_context {
    public Vx_state.Type_valuemap vx_valuemap_readstate_from_mapname(Vx_core.Type_context context, Vx_core.Type_string mapname);
  }

  public class Class_valuemap_readstate_from_mapname : Vx_core.Class_base, Func_valuemap_readstate_from_mapname {

    public override Vx_state.Func_valuemap_readstate_from_mapname vx_new(params Object[] vals) {
      Class_valuemap_readstate_from_mapname output = new Class_valuemap_readstate_from_mapname();
      return output;
    }

    public override Vx_state.Func_valuemap_readstate_from_mapname vx_copy(params Object[] vals) {
      Class_valuemap_readstate_from_mapname output = new Class_valuemap_readstate_from_mapname();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/state", // pkgname
        "valuemap-readstate<-mapname", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/state", // pkgname
          "valuemap", // name
          ":map", // extends
          Vx_core.e_typelist, // traits
          Vx_core.vx_new(Vx_core.t_typelist, Vx_core.t_any), // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx_core.Type_any vx_empty() {
      return e_valuemap_readstate_from_mapname;
    }

    public override Vx_core.Type_any vx_type() {
      return t_valuemap_readstate_from_mapname;
    }

    public Vx_core.Func_any_from_any_context vx_fn_new(Vx_core.Class_any_from_any_context.IFn fn) {
      return Vx_core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx_core.Type_context context, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_core.Type_string inputval = (Vx_core.Type_string)value;
      Vx_core.Type_any outputval = Vx_state.f_valuemap_readstate_from_mapname(context, inputval);
      output = Vx_core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_string mapname = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_state.f_valuemap_readstate_from_mapname(context, mapname);
      return output;
    }

    public Vx_state.Type_valuemap vx_valuemap_readstate_from_mapname(Vx_core.Type_context context, Vx_core.Type_string mapname) {
      return Vx_state.f_valuemap_readstate_from_mapname(context, mapname);
    }

  }

  public static Func_valuemap_readstate_from_mapname e_valuemap_readstate_from_mapname = new Vx_state.Class_valuemap_readstate_from_mapname();
  public static Func_valuemap_readstate_from_mapname t_valuemap_readstate_from_mapname = new Vx_state.Class_valuemap_readstate_from_mapname();

  public static Vx_state.Type_valuemap f_valuemap_readstate_from_mapname(Vx_core.Type_context context, Vx_core.Type_string mapname) {
    Vx_state.Type_valuemap output = Vx_state.e_valuemap;
    output = Vx_core.f_let(
      Vx_state.t_valuemap,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_core.Type_any value = Vx_state.f_value_readstate_from_name(context, mapname);
        Vx_state.Type_valuemap valmap = Vx_core.f_any_from_any(Vx_state.t_valuemap, value);
        return valmap;
      })
    );
    return output;
  }


  public static class PackageRunOnce {
    public static void RunOnce() {
    Vx_core.Map<string, Vx_core.Type_any> maptype = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
    Vx_core.Map<string, Vx_core.Type_any> mapconst = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
    Vx_core.Map<string, Vx_core.Type_func> mapfunc = new Vx_core.LinkedHashMap<string, Vx_core.Type_func>();
    maptype.put("valuemap", Vx_state.t_valuemap);
    mapfunc.put("any-readstate<-mapname-name", Vx_state.t_any_readstate_from_mapname_name);
    mapfunc.put("any-readstate<-name", Vx_state.t_any_readstate_from_name);
    mapfunc.put("boolean-removestate<-name", Vx_state.t_boolean_removestate_from_name);
    mapfunc.put("boolean-writestate<-mapname-name-value", Vx_state.t_boolean_writestate_from_mapname_name_value);
    mapfunc.put("boolean-writestate<-name-value", Vx_state.t_boolean_writestate_from_name_value);
    mapfunc.put("boolean-writestate<-statelistener", Vx_state.t_boolean_writestate_from_statelistener);
    mapfunc.put("change", Vx_state.t_change);
    mapfunc.put("register", Vx_state.t_register);
    mapfunc.put("state<-context", Vx_state.t_state_from_context);
    mapfunc.put("statelistener-readstate<-name", Vx_state.t_statelistener_readstate_from_name);
    mapfunc.put("statelistenermap-readstate", Vx_state.t_statelistenermap_readstate);
    mapfunc.put("value-readstate<-name", Vx_state.t_value_readstate_from_name);
    mapfunc.put("valuemap-readstate<-mapname", Vx_state.t_valuemap_readstate_from_mapname);
    Vx_core.vx_global_package_set("vx/state", maptype, mapconst, mapfunc);
    }
  }

}
