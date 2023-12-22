package com.vxlisp.vx;

import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Set;

public final class State {


  /**
   * type: value-map
   * (type value-map)
   */
  public interface Type_value_map extends Core.Type_map {
    public State.Type_value_map vx_new(final Object... vals);
    public State.Type_value_map vx_copy(final Object... vals);
    public State.Type_value_map vx_empty();
    public State.Type_value_map vx_type();
  }

  public static class Class_value_map extends Core.Class_base implements Type_value_map {

    protected Map<String, Core.Type_any> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Core.Type_any>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vx_p_map));}

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      Class_value_map map = this;
      String skey = key.vx_string();
      Map<String, Core.Type_any> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Core.e_any);
      return output;
    }

    @Override
    public Type_value_map vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Class_value_map output = new Class_value_map();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Core.Type_any> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Core.Type_any) {
          Core.Type_any castval = (Core.Type_any)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_error("(value_map) Invalid Value: " + val.toString() + "");
          msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_value_map vx_new(final Object... vals) {return e_value_map.vx_copy(vals);}

    @Override
    public Type_value_map vx_copy(final Object... vals) {
      Type_value_map output = this;
      boolean ischanged = false;
      Class_value_map val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, Core.Type_any> mapval = new LinkedHashMap<>(val.vx_map());
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.t_msgblock.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            key = (String)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Key Expected: " + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
        } else {
          Core.Type_any valany = null;
          if (valsub instanceof Core.Type_any) {
            valany = (Core.Type_any)valsub;
          } else if (valsub instanceof Core.Type_any) {
            valany = (Core.Type_any)valsub;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("Invalid Key/Value: " + key + " "  + valsub.toString() + "");
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
          if (valany != null) {
            ischanged = true;
            if (key.startsWith(":")) {
              key = key.substring(1);
            }
            mapval.put(key, valany);
            key = "";
          }
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_value_map work = new Class_value_map();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_value_map vx_empty() {return e_value_map;}
    @Override
    public Type_value_map vx_type() {return t_value_map;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/state", // pkgname
        "value-map", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_any), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_value_map e_value_map = new Class_value_map();
  public static final Type_value_map t_value_map = new Class_value_map();
  /**
   * @function change
   * Changes the current state
   * @param  {value-map} valuemap
   * @return {boolean}
   * (func change)
   */
  public static interface Func_change extends Core.Func_any_from_any {
    public Core.Type_boolean vx_change(final State.Type_value_map valuemap);
  }

  public static class Class_change extends Core.Class_base implements Func_change {

    @Override
    public Func_change vx_new(Object... vals) {
      Class_change output = new Class_change();
      return output;
    }

    @Override
    public Func_change vx_copy(Object... vals) {
      Class_change output = new Class_change();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/state", // pkgname
        "change", // name
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
    public Func_change vx_empty() {return e_change;}
    @Override
    public Func_change vx_type() {return t_change;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      State.Type_value_map inputval = (State.Type_value_map)value;
      Core.Type_any outputval = State.f_change(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      State.Type_value_map valuemap = Core.f_any_from_any(State.t_value_map, arglist.vx_any(Core.vx_new_int(0)));
      output = State.f_change(valuemap);
      return output;
    }

    @Override
    public Core.Type_boolean vx_change(final State.Type_value_map valuemap) {
      return State.f_change(valuemap);
    }

  }

  public static final Func_change e_change = new State.Class_change();
  public static final Func_change t_change = new State.Class_change();

  public static Core.Type_boolean f_change(final State.Type_value_map valuemap) {
    Core.Type_boolean output = Core.e_boolean;
    return output;
  }

  /**
   * @function register
   * @param  {statelistener} listener
   * @return {boolean}
   * (func register)
   */
  public static interface Func_register extends Core.Func_any_from_any {
    public Core.Type_boolean vx_register(final Core.Type_statelistener listener);
  }

  public static class Class_register extends Core.Class_base implements Func_register {

    @Override
    public Func_register vx_new(Object... vals) {
      Class_register output = new Class_register();
      return output;
    }

    @Override
    public Func_register vx_copy(Object... vals) {
      Class_register output = new Class_register();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/state", // pkgname
        "register", // name
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
    public Func_register vx_empty() {return e_register;}
    @Override
    public Func_register vx_type() {return t_register;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_statelistener inputval = (Core.Type_statelistener)value;
      Core.Type_any outputval = State.f_register(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_statelistener listener = Core.f_any_from_any(Core.t_statelistener, arglist.vx_any(Core.vx_new_int(0)));
      output = State.f_register(listener);
      return output;
    }

    @Override
    public Core.Type_boolean vx_register(final Core.Type_statelistener listener) {
      return State.f_register(listener);
    }

  }

  public static final Func_register e_register = new State.Class_register();
  public static final Func_register t_register = new State.Class_register();

  public static Core.Type_boolean f_register(final Core.Type_statelistener listener) {
    Core.Type_boolean output = Core.e_boolean;
    return output;
  }


  static {
    Map<String, Core.Type_any> maptype = new LinkedHashMap<>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<>();
    maptype.put("value-map", State.t_value_map);
    mapfunc.put("change", State.t_change);
    mapfunc.put("register", State.t_register);
    Core.vx_global_package_set("vx/state", maptype, mapconst, mapfunc);
  }

}
