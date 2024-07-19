namespace Vx;

public static class State {


  /**
   * type: valuemap
   * (type valuemap)
   */
  public interface Type_valuemap : Vx.Core.Type_map {
  }

  public class Class_valuemap : Vx.Core.Class_base, Type_valuemap {

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = this.vx_p_map;
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (false) {
      } else if (value is Vx.Core.Type_any castval) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>(this.vx_p_map);
        if (castval == Vx.Core.e_any) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.State.Class_valuemap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Core.Type_any> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Vx.Core.e_any);
      return output;
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.State.Class_valuemap output = new Vx.State.Class_valuemap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val is Vx.Core.Type_any castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/state/valuemap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.State.Type_valuemap vx_new(params Object[] vals) {
      Vx.State.Type_valuemap output = Vx.Core.vx_copy(Vx.State.e_valuemap, vals);
      return output;
    }

    public override Vx.State.Type_valuemap vx_copy(params Object[] vals) {
      Type_valuemap output = this;
      bool ischanged = false;
      Class_valuemap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Core.Type_any> mapval = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>(val.vx_map());
      Vx.Core.Type_msg? msg = null;
      string key = "";
      Vx.Core.Type_any? msgval = null;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstring) {
            key = valstring.vx_string();
          } else if (valsub is string sval) {
            key = sval;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valinvalid) {
              msgval = valinvalid;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/state/valuemap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Core.Type_any? valany = null;
          if (false) {
          } else if (valsub is Vx.Core.Type_any valallowed) {
            valany = valallowed;
          } else if (valsub is Vx.Core.Type_any) {
            valany = valsub as Vx.Core.Type_any;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valinvalid) {
              msgval = valinvalid;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
            mapany.put("key", Vx.Core.vx_new_string(key));
            mapany.put("value", msgval);
            Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
            msg = Vx.Core.vx_msg_from_error("vx/state/valuemap", ":invalidkeyvalue", msgmap);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
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
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_valuemap work = new Class_valuemap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_valuemap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_valuemap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/state", // pkgname
        "valuemap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_any), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Func_any_readstate_from_mapname_name : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public T vx_any_readstate_from_mapname_name<T>(T generic_any_1, Vx.Core.Type_context context, Vx.Core.Type_string mapname, Vx.Core.Type_string name) where T : Vx.Core.Type_any;
  }

  public class Class_any_readstate_from_mapname_name : Vx.Core.Class_base, Func_any_readstate_from_mapname_name {

    public override Vx.State.Func_any_readstate_from_mapname_name vx_new(params Object[] vals) {
      Class_any_readstate_from_mapname_name output = new Class_any_readstate_from_mapname_name();
      return output;
    }

    public override Vx.State.Func_any_readstate_from_mapname_name vx_copy(params Object[] vals) {
      Class_any_readstate_from_mapname_name output = new Class_any_readstate_from_mapname_name();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/state", // pkgname
        "any-readstate<-mapname-name", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_readstate_from_mapname_name;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_readstate_from_mapname_name;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string mapname = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string name = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.State.f_any_readstate_from_mapname_name(generic_any_1, context, mapname, name);
      return output;
    }

    public T vx_any_readstate_from_mapname_name<T>(T generic_any_1, Vx.Core.Type_context context, Vx.Core.Type_string mapname, Vx.Core.Type_string name) where T : Vx.Core.Type_any {
      return Vx.State.f_any_readstate_from_mapname_name(generic_any_1, context, mapname, name);
    }

  }

  public static Func_any_readstate_from_mapname_name e_any_readstate_from_mapname_name = new Vx.State.Class_any_readstate_from_mapname_name();
  public static Func_any_readstate_from_mapname_name t_any_readstate_from_mapname_name = new Vx.State.Class_any_readstate_from_mapname_name();

  public static T f_any_readstate_from_mapname_name<T>(T generic_any_1, Vx.Core.Type_context context, Vx.Core.Type_string mapname, Vx.Core.Type_string name) where T : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
    output = Vx.Core.f_let(
      generic_any_1,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.State.Type_valuemap submap = Vx.State.f_valuemap_readstate_from_mapname(context, mapname);
        Vx.Core.Type_any output_1 = Vx.Core.f_any_from_map(generic_any_1, submap, name);
        return output_1;
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
  public interface Func_any_readstate_from_name : Vx.Core.Func_any_from_any_context {
    public T vx_any_readstate_from_name<T>(T generic_any_1, Vx.Core.Type_context context, Vx.Core.Type_string name) where T : Vx.Core.Type_any;
  }

  public class Class_any_readstate_from_name : Vx.Core.Class_base, Func_any_readstate_from_name {

    public override Vx.State.Func_any_readstate_from_name vx_new(params Object[] vals) {
      Class_any_readstate_from_name output = new Class_any_readstate_from_name();
      return output;
    }

    public override Vx.State.Func_any_readstate_from_name vx_copy(params Object[] vals) {
      Class_any_readstate_from_name output = new Class_any_readstate_from_name();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/state", // pkgname
        "any-readstate<-name", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any-1", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_any_readstate_from_name;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_readstate_from_name;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.State.f_any_readstate_from_name(Vx.Core.t_any, context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string name = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.State.f_any_readstate_from_name(generic_any_1, context, name);
      return output;
    }

    public T vx_any_readstate_from_name<T>(T generic_any_1, Vx.Core.Type_context context, Vx.Core.Type_string name) where T : Vx.Core.Type_any {
      return Vx.State.f_any_readstate_from_name(generic_any_1, context, name);
    }

  }

  public static Func_any_readstate_from_name e_any_readstate_from_name = new Vx.State.Class_any_readstate_from_name();
  public static Func_any_readstate_from_name t_any_readstate_from_name = new Vx.State.Class_any_readstate_from_name();

  public static T f_any_readstate_from_name<T>(T generic_any_1, Vx.Core.Type_context context, Vx.Core.Type_string name) where T : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
    output = Vx.Core.f_any_from_any(
      generic_any_1,
      Vx.State.f_value_readstate_from_name(context, name)
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
  public interface Func_boolean_removestate_from_name : Vx.Core.Func_any_from_any_context {
    public Vx.Core.Type_boolean vx_boolean_removestate_from_name(Vx.Core.Type_context context, Vx.Core.Type_string name);
  }

  public class Class_boolean_removestate_from_name : Vx.Core.Class_base, Func_boolean_removestate_from_name {

    public override Vx.State.Func_boolean_removestate_from_name vx_new(params Object[] vals) {
      Class_boolean_removestate_from_name output = new Class_boolean_removestate_from_name();
      return output;
    }

    public override Vx.State.Func_boolean_removestate_from_name vx_copy(params Object[] vals) {
      Class_boolean_removestate_from_name output = new Class_boolean_removestate_from_name();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/state", // pkgname
        "boolean-removestate<-name", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_removestate_from_name;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_removestate_from_name;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.State.f_boolean_removestate_from_name(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string name = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.State.f_boolean_removestate_from_name(context, name);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_removestate_from_name(Vx.Core.Type_context context, Vx.Core.Type_string name) {
      return Vx.State.f_boolean_removestate_from_name(context, name);
    }

  }

  public static Func_boolean_removestate_from_name e_boolean_removestate_from_name = new Vx.State.Class_boolean_removestate_from_name();
  public static Func_boolean_removestate_from_name t_boolean_removestate_from_name = new Vx.State.Class_boolean_removestate_from_name();

  public static Vx.Core.Type_boolean f_boolean_removestate_from_name(Vx.Core.Type_context context, Vx.Core.Type_string name) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_statelistenermap statelistenermap = Vx.State.f_statelistenermap_readstate(context);
        Vx.Core.Type_any output_1 = Vx.Core.f_boolean_write_from_map_name_value(
          statelistenermap,
          name,
          Vx.Core.f_empty(
            Vx.Core.t_statelistener
          )
        );
        return output_1;
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
  public interface Func_boolean_writestate_from_mapname_name_value : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_boolean_writestate_from_mapname_name_value(Vx.Core.Type_context context, Vx.Core.Type_string mapname, Vx.Core.Type_string name, Vx.Core.Type_any value);
  }

  public class Class_boolean_writestate_from_mapname_name_value : Vx.Core.Class_base, Func_boolean_writestate_from_mapname_name_value {

    public override Vx.State.Func_boolean_writestate_from_mapname_name_value vx_new(params Object[] vals) {
      Class_boolean_writestate_from_mapname_name_value output = new Class_boolean_writestate_from_mapname_name_value();
      return output;
    }

    public override Vx.State.Func_boolean_writestate_from_mapname_name_value vx_copy(params Object[] vals) {
      Class_boolean_writestate_from_mapname_name_value output = new Class_boolean_writestate_from_mapname_name_value();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/state", // pkgname
        "boolean-writestate<-mapname-name-value", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_writestate_from_mapname_name_value;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_writestate_from_mapname_name_value;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string mapname = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string name = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.State.f_boolean_writestate_from_mapname_name_value(context, mapname, name, value);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_writestate_from_mapname_name_value(Vx.Core.Type_context context, Vx.Core.Type_string mapname, Vx.Core.Type_string name, Vx.Core.Type_any value) {
      return Vx.State.f_boolean_writestate_from_mapname_name_value(context, mapname, name, value);
    }

  }

  public static Func_boolean_writestate_from_mapname_name_value e_boolean_writestate_from_mapname_name_value = new Vx.State.Class_boolean_writestate_from_mapname_name_value();
  public static Func_boolean_writestate_from_mapname_name_value t_boolean_writestate_from_mapname_name_value = new Vx.State.Class_boolean_writestate_from_mapname_name_value();

  public static Vx.Core.Type_boolean f_boolean_writestate_from_mapname_name_value(Vx.Core.Type_context context, Vx.Core.Type_string mapname, Vx.Core.Type_string name, Vx.Core.Type_any value) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.State.Type_valuemap valmap = Vx.State.f_any_readstate_from_name(Vx.State.t_valuemap, context, mapname);
        Vx.Core.Type_any output_2 = Vx.Core.f_if_2(
          Vx.Core.t_boolean,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_is_empty_1(valmap);
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Core.f_let(
                  Vx.Core.t_boolean,
                  Vx.Core.t_any_from_func.vx_fn_new(() => {
                    Vx.State.Type_valuemap valmap2 = Vx.Core.f_new(
                      Vx.State.t_valuemap,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                          name,
                          value
                      )
                    );
                    Vx.Core.Type_statelistener listener = Vx.Core.f_new(
                      Vx.Core.t_statelistener,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                          Vx.Core.vx_new_string(":name"),
                          mapname,
                          Vx.Core.vx_new_string(":value"),
                          valmap2
                      )
                    );
                    Vx.Core.Type_any output_1 = Vx.State.f_boolean_writestate_from_statelistener(context, listener);
                    return output_1;
                  })
                );
              })
            ),
            Vx.Core.f_else(
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Core.f_boolean_write_from_map_name_value(valmap, name, value);
              })
            )
          )
        );
        return output_2;
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
  public interface Func_boolean_writestate_from_name_value : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_boolean vx_boolean_writestate_from_name_value(Vx.Core.Type_context context, Vx.Core.Type_string name, Vx.Core.Type_any value);
  }

  public class Class_boolean_writestate_from_name_value : Vx.Core.Class_base, Func_boolean_writestate_from_name_value {

    public override Vx.State.Func_boolean_writestate_from_name_value vx_new(params Object[] vals) {
      Class_boolean_writestate_from_name_value output = new Class_boolean_writestate_from_name_value();
      return output;
    }

    public override Vx.State.Func_boolean_writestate_from_name_value vx_copy(params Object[] vals) {
      Class_boolean_writestate_from_name_value output = new Class_boolean_writestate_from_name_value();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/state", // pkgname
        "boolean-writestate<-name-value", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_writestate_from_name_value;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_writestate_from_name_value;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string name = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any value = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.State.f_boolean_writestate_from_name_value(context, name, value);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_writestate_from_name_value(Vx.Core.Type_context context, Vx.Core.Type_string name, Vx.Core.Type_any value) {
      return Vx.State.f_boolean_writestate_from_name_value(context, name, value);
    }

  }

  public static Func_boolean_writestate_from_name_value e_boolean_writestate_from_name_value = new Vx.State.Class_boolean_writestate_from_name_value();
  public static Func_boolean_writestate_from_name_value t_boolean_writestate_from_name_value = new Vx.State.Class_boolean_writestate_from_name_value();

  public static Vx.Core.Type_boolean f_boolean_writestate_from_name_value(Vx.Core.Type_context context, Vx.Core.Type_string name, Vx.Core.Type_any value) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_statelistener listenercur = Vx.State.f_statelistener_readstate_from_name(context, name);
        Vx.Core.Type_statelistener listenerchg = Vx.Core.f_copy(
          listenercur,
          Vx.Core.vx_new(Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":name"),
              name,
              Vx.Core.vx_new_string(":value"),
              value
          )
        );
        Vx.Core.Type_any output_1 = Vx.State.f_boolean_writestate_from_statelistener(context, listenerchg);
        return output_1;
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
  public interface Func_boolean_writestate_from_statelistener : Vx.Core.Func_any_from_any_context {
    public Vx.Core.Type_boolean vx_boolean_writestate_from_statelistener(Vx.Core.Type_context context, Vx.Core.Type_statelistener statelistener);
  }

  public class Class_boolean_writestate_from_statelistener : Vx.Core.Class_base, Func_boolean_writestate_from_statelistener {

    public override Vx.State.Func_boolean_writestate_from_statelistener vx_new(params Object[] vals) {
      Class_boolean_writestate_from_statelistener output = new Class_boolean_writestate_from_statelistener();
      return output;
    }

    public override Vx.State.Func_boolean_writestate_from_statelistener vx_copy(params Object[] vals) {
      Class_boolean_writestate_from_statelistener output = new Class_boolean_writestate_from_statelistener();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/state", // pkgname
        "boolean-writestate<-statelistener", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_boolean_writestate_from_statelistener;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_boolean_writestate_from_statelistener;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_statelistener inputval = (Vx.Core.Type_statelistener)value;
      Vx.Core.Type_any outputval = Vx.State.f_boolean_writestate_from_statelistener(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_statelistener statelistener = Vx.Core.f_any_from_any(Vx.Core.t_statelistener, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.State.f_boolean_writestate_from_statelistener(context, statelistener);
      return output;
    }

    public Vx.Core.Type_boolean vx_boolean_writestate_from_statelistener(Vx.Core.Type_context context, Vx.Core.Type_statelistener statelistener) {
      return Vx.State.f_boolean_writestate_from_statelistener(context, statelistener);
    }

  }

  public static Func_boolean_writestate_from_statelistener e_boolean_writestate_from_statelistener = new Vx.State.Class_boolean_writestate_from_statelistener();
  public static Func_boolean_writestate_from_statelistener t_boolean_writestate_from_statelistener = new Vx.State.Class_boolean_writestate_from_statelistener();

  public static Vx.Core.Type_boolean f_boolean_writestate_from_statelistener(Vx.Core.Type_context context, Vx.Core.Type_statelistener statelistener) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    output = Vx.Core.f_let(
      Vx.Core.t_boolean,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_statelistenermap statelistenermap = Vx.State.f_statelistenermap_readstate(context);
        Vx.Core.Type_string name = statelistener.name();
        Vx.Core.Type_any output_1 = Vx.Core.f_boolean_write_from_map_name_value(statelistenermap, name, statelistener);
        return output_1;
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
  public interface Func_change : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_change(Vx.State.Type_valuemap valuemap);
  }

  public class Class_change : Vx.Core.Class_base, Func_change {

    public override Vx.State.Func_change vx_new(params Object[] vals) {
      Class_change output = new Class_change();
      return output;
    }

    public override Vx.State.Func_change vx_copy(params Object[] vals) {
      Class_change output = new Class_change();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/state", // pkgname
        "change", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_change;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_change;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.State.Type_valuemap inputval = (Vx.State.Type_valuemap)value;
      Vx.Core.Type_any outputval = Vx.State.f_change(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.State.Type_valuemap valuemap = Vx.Core.f_any_from_any(Vx.State.t_valuemap, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.State.f_change(valuemap);
      return output;
    }

    public Vx.Core.Type_boolean vx_change(Vx.State.Type_valuemap valuemap) {
      return Vx.State.f_change(valuemap);
    }

  }

  public static Func_change e_change = new Vx.State.Class_change();
  public static Func_change t_change = new Vx.State.Class_change();

  public static Vx.Core.Type_boolean f_change(Vx.State.Type_valuemap valuemap) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    return output;
  }

  /**
   * @function register
   * @param  {statelistener} listener
   * @return {boolean}
   * (func register)
   */
  public interface Func_register : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_boolean vx_register(Vx.Core.Type_statelistener listener);
  }

  public class Class_register : Vx.Core.Class_base, Func_register {

    public override Vx.State.Func_register vx_new(params Object[] vals) {
      Class_register output = new Class_register();
      return output;
    }

    public override Vx.State.Func_register vx_copy(params Object[] vals) {
      Class_register output = new Class_register();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/state", // pkgname
        "register", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_register;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_register;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_statelistener inputval = (Vx.Core.Type_statelistener)value;
      Vx.Core.Type_any outputval = Vx.State.f_register(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_statelistener listener = Vx.Core.f_any_from_any(Vx.Core.t_statelistener, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.State.f_register(listener);
      return output;
    }

    public Vx.Core.Type_boolean vx_register(Vx.Core.Type_statelistener listener) {
      return Vx.State.f_register(listener);
    }

  }

  public static Func_register e_register = new Vx.State.Class_register();
  public static Func_register t_register = new Vx.State.Class_register();

  public static Vx.Core.Type_boolean f_register(Vx.Core.Type_statelistener listener) {
    Vx.Core.Type_boolean output = Vx.Core.e_boolean;
    return output;
  }

  /**
   * @function state_from_context
   * Returns the full current state
   * @return {state}
   * (func state<-context)
   */
  public interface Func_state_from_context : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_state vx_state_from_context(Vx.Core.Type_context context);
  }

  public class Class_state_from_context : Vx.Core.Class_base, Func_state_from_context {

    public override Vx.State.Func_state_from_context vx_new(params Object[] vals) {
      Class_state_from_context output = new Class_state_from_context();
      return output;
    }

    public override Vx.State.Func_state_from_context vx_copy(params Object[] vals) {
      Class_state_from_context output = new Class_state_from_context();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/state", // pkgname
        "state<-context", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "state", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_state_from_context;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_state_from_context;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.State.f_state_from_context(context);
      return output;
    }

    public Vx.Core.Type_state vx_state_from_context(Vx.Core.Type_context context) {
      return Vx.State.f_state_from_context(context);
    }

  }

  public static Func_state_from_context e_state_from_context = new Vx.State.Class_state_from_context();
  public static Func_state_from_context t_state_from_context = new Vx.State.Class_state_from_context();

  public static Vx.Core.Type_state f_state_from_context(Vx.Core.Type_context context) {
    Vx.Core.Type_state output = Vx.Core.e_state;
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
  public interface Func_statelistener_readstate_from_name : Vx.Core.Func_any_from_any_context {
    public Vx.Core.Type_statelistener vx_statelistener_readstate_from_name(Vx.Core.Type_context context, Vx.Core.Type_string name);
  }

  public class Class_statelistener_readstate_from_name : Vx.Core.Class_base, Func_statelistener_readstate_from_name {

    public override Vx.State.Func_statelistener_readstate_from_name vx_new(params Object[] vals) {
      Class_statelistener_readstate_from_name output = new Class_statelistener_readstate_from_name();
      return output;
    }

    public override Vx.State.Func_statelistener_readstate_from_name vx_copy(params Object[] vals) {
      Class_statelistener_readstate_from_name output = new Class_statelistener_readstate_from_name();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/state", // pkgname
        "statelistener-readstate<-name", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "statelistener", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_statelistener_readstate_from_name;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_statelistener_readstate_from_name;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.State.f_statelistener_readstate_from_name(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string name = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.State.f_statelistener_readstate_from_name(context, name);
      return output;
    }

    public Vx.Core.Type_statelistener vx_statelistener_readstate_from_name(Vx.Core.Type_context context, Vx.Core.Type_string name) {
      return Vx.State.f_statelistener_readstate_from_name(context, name);
    }

  }

  public static Func_statelistener_readstate_from_name e_statelistener_readstate_from_name = new Vx.State.Class_statelistener_readstate_from_name();
  public static Func_statelistener_readstate_from_name t_statelistener_readstate_from_name = new Vx.State.Class_statelistener_readstate_from_name();

  public static Vx.Core.Type_statelistener f_statelistener_readstate_from_name(Vx.Core.Type_context context, Vx.Core.Type_string name) {
    Vx.Core.Type_statelistener output = Vx.Core.e_statelistener;
    output = Vx.Core.f_let(
      Vx.Core.t_statelistener,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_statelistenermap statelistenermap = Vx.State.f_statelistenermap_readstate(context);
        Vx.Core.Type_any output_1 = Vx.Core.f_any_from_map(Vx.Core.t_statelistener, statelistenermap, name);
        return output_1;
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
  public interface Func_statelistenermap_readstate : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_statelistenermap vx_statelistenermap_readstate(Vx.Core.Type_context context);
  }

  public class Class_statelistenermap_readstate : Vx.Core.Class_base, Func_statelistenermap_readstate {

    public override Vx.State.Func_statelistenermap_readstate vx_new(params Object[] vals) {
      Class_statelistenermap_readstate output = new Class_statelistenermap_readstate();
      return output;
    }

    public override Vx.State.Func_statelistenermap_readstate vx_copy(params Object[] vals) {
      Class_statelistenermap_readstate output = new Class_statelistenermap_readstate();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/state", // pkgname
        "statelistenermap-readstate", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "statelistenermap", // name
          ":map", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_statelistener), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_statelistenermap_readstate;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_statelistenermap_readstate;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.State.f_statelistenermap_readstate(context);
      return output;
    }

    public Vx.Core.Type_statelistenermap vx_statelistenermap_readstate(Vx.Core.Type_context context) {
      return Vx.State.f_statelistenermap_readstate(context);
    }

  }

  public static Func_statelistenermap_readstate e_statelistenermap_readstate = new Vx.State.Class_statelistenermap_readstate();
  public static Func_statelistenermap_readstate t_statelistenermap_readstate = new Vx.State.Class_statelistenermap_readstate();

  public static Vx.Core.Type_statelistenermap f_statelistenermap_readstate(Vx.Core.Type_context context) {
    Vx.Core.Type_statelistenermap output = Vx.Core.e_statelistenermap;
    output = Vx.Core.f_let(
      Vx.Core.t_statelistenermap,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_state state = Vx.State.f_state_from_context(context);
        Vx.Core.Type_any output_1 = state.statelistenermap();
        return output_1;
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
  public interface Func_value_readstate_from_name : Vx.Core.Func_any_from_any_context {
    public Vx.Core.Type_any vx_value_readstate_from_name(Vx.Core.Type_context context, Vx.Core.Type_string name);
  }

  public class Class_value_readstate_from_name : Vx.Core.Class_base, Func_value_readstate_from_name {

    public override Vx.State.Func_value_readstate_from_name vx_new(params Object[] vals) {
      Class_value_readstate_from_name output = new Class_value_readstate_from_name();
      return output;
    }

    public override Vx.State.Func_value_readstate_from_name vx_copy(params Object[] vals) {
      Class_value_readstate_from_name output = new Class_value_readstate_from_name();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/state", // pkgname
        "value-readstate<-name", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "any", // name
          "", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_value_readstate_from_name;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_value_readstate_from_name;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.State.f_value_readstate_from_name(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string name = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.State.f_value_readstate_from_name(context, name);
      return output;
    }

    public Vx.Core.Type_any vx_value_readstate_from_name(Vx.Core.Type_context context, Vx.Core.Type_string name) {
      return Vx.State.f_value_readstate_from_name(context, name);
    }

  }

  public static Func_value_readstate_from_name e_value_readstate_from_name = new Vx.State.Class_value_readstate_from_name();
  public static Func_value_readstate_from_name t_value_readstate_from_name = new Vx.State.Class_value_readstate_from_name();

  public static Vx.Core.Type_any f_value_readstate_from_name(Vx.Core.Type_context context, Vx.Core.Type_string name) {
    Vx.Core.Type_any output = Vx.Core.e_any;
    output = Vx.Core.f_let(
      Vx.Core.t_any,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_statelistener statelistener = Vx.State.f_statelistener_readstate_from_name(context, name);
        Vx.Core.Type_any output_1 = statelistener.value();
        return output_1;
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
  public interface Func_valuemap_readstate_from_mapname : Vx.Core.Func_any_from_any_context {
    public Vx.State.Type_valuemap vx_valuemap_readstate_from_mapname(Vx.Core.Type_context context, Vx.Core.Type_string mapname);
  }

  public class Class_valuemap_readstate_from_mapname : Vx.Core.Class_base, Func_valuemap_readstate_from_mapname {

    public override Vx.State.Func_valuemap_readstate_from_mapname vx_new(params Object[] vals) {
      Class_valuemap_readstate_from_mapname output = new Class_valuemap_readstate_from_mapname();
      return output;
    }

    public override Vx.State.Func_valuemap_readstate_from_mapname vx_copy(params Object[] vals) {
      Class_valuemap_readstate_from_mapname output = new Class_valuemap_readstate_from_mapname();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/state", // pkgname
        "valuemap-readstate<-mapname", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/state", // pkgname
          "valuemap", // name
          ":map", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_any), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_valuemap_readstate_from_mapname;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_valuemap_readstate_from_mapname;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.State.f_valuemap_readstate_from_mapname(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string mapname = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.State.f_valuemap_readstate_from_mapname(context, mapname);
      return output;
    }

    public Vx.State.Type_valuemap vx_valuemap_readstate_from_mapname(Vx.Core.Type_context context, Vx.Core.Type_string mapname) {
      return Vx.State.f_valuemap_readstate_from_mapname(context, mapname);
    }

  }

  public static Func_valuemap_readstate_from_mapname e_valuemap_readstate_from_mapname = new Vx.State.Class_valuemap_readstate_from_mapname();
  public static Func_valuemap_readstate_from_mapname t_valuemap_readstate_from_mapname = new Vx.State.Class_valuemap_readstate_from_mapname();

  public static Vx.State.Type_valuemap f_valuemap_readstate_from_mapname(Vx.Core.Type_context context, Vx.Core.Type_string mapname) {
    Vx.State.Type_valuemap output = Vx.State.e_valuemap;
    output = Vx.Core.f_let(
      Vx.State.t_valuemap,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_any value = Vx.State.f_value_readstate_from_name(context, mapname);
        Vx.State.Type_valuemap valmap = Vx.Core.f_any_from_any(Vx.State.t_valuemap, value);
        Vx.Core.Type_any output_1 = valmap;
        return output_1;
      })
    );
    return output;
  }


  public static class PackageRunOnce {
    public static void RunOnce() {
    Vx.Core.Map<string, Vx.Core.Type_any> maptype = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_any> mapconst = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_func> mapfunc = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>();
    maptype.put("valuemap", Vx.State.t_valuemap);
    mapfunc.put("any-readstate<-mapname-name", Vx.State.t_any_readstate_from_mapname_name);
    mapfunc.put("any-readstate<-name", Vx.State.t_any_readstate_from_name);
    mapfunc.put("boolean-removestate<-name", Vx.State.t_boolean_removestate_from_name);
    mapfunc.put("boolean-writestate<-mapname-name-value", Vx.State.t_boolean_writestate_from_mapname_name_value);
    mapfunc.put("boolean-writestate<-name-value", Vx.State.t_boolean_writestate_from_name_value);
    mapfunc.put("boolean-writestate<-statelistener", Vx.State.t_boolean_writestate_from_statelistener);
    mapfunc.put("change", Vx.State.t_change);
    mapfunc.put("register", Vx.State.t_register);
    mapfunc.put("state<-context", Vx.State.t_state_from_context);
    mapfunc.put("statelistener-readstate<-name", Vx.State.t_statelistener_readstate_from_name);
    mapfunc.put("statelistenermap-readstate", Vx.State.t_statelistenermap_readstate);
    mapfunc.put("value-readstate<-name", Vx.State.t_value_readstate_from_name);
    mapfunc.put("valuemap-readstate<-mapname", Vx.State.t_valuemap_readstate_from_mapname);
    Vx.Core.vx_global_package_set("vx/state", maptype, mapconst, mapfunc);
    }
  }

}
