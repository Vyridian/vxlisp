package com.vxlisp.vx;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.Map;


public final class Event {


  /**
   * type: event
   * Generic event
   * (type event)
   */
  public interface Type_event extends Core.Type_struct {
    public Event.Type_event vx_new(final Object... vals);
    public Event.Type_event vx_copy(final Object... vals);
    public Event.Type_event vx_empty();
    public Event.Type_event vx_type();
    public Core.Type_string name();
    public Core.Type_any from();
    public Core.Type_any to();
    public Core.Func_any_from_any fn_any_from_any();
    public Event.Func_any_from_from_to fn_any_from_from_to();
  }

  public static class Class_event extends Core.Class_base implements Type_event {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_any vx_p_from;

    @Override
    public Core.Type_any from() {
      return this.vx_p_from == null ? Core.e_any : this.vx_p_from;
    }

    protected Core.Type_any vx_p_to;

    @Override
    public Core.Type_any to() {
      return this.vx_p_to == null ? Core.e_any : this.vx_p_to;
    }

    protected Core.Func_any_from_any vx_p_fn_any_from_any;

    @Override
    public Core.Func_any_from_any fn_any_from_any() {
      return this.vx_p_fn_any_from_any == null ? Core.e_any_from_any : this.vx_p_fn_any_from_any;
    }

    protected Event.Func_any_from_from_to vx_p_fn_any_from_from_to;

    @Override
    public Event.Func_any_from_from_to fn_any_from_from_to() {
      return this.vx_p_fn_any_from_from_to == null ? Event.e_any_from_from_to : this.vx_p_fn_any_from_from_to;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":name":
        output = this.name();
        break;
      case ":from":
        output = this.from();
        break;
      case ":to":
        output = this.to();
        break;
      case ":fn-any<-any":
        output = this.fn_any_from_any();
        break;
      case ":fn-any<-from-to":
        output = this.fn_any_from_from_to();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":name", this.name());
      output.put(":from", this.from());
      output.put(":to", this.to());
      output.put(":fn-any<-any", this.fn_any_from_any());
      output.put(":fn-any<-from-to", this.fn_any_from_from_to());
      return Core.immutablemap(output);
    }

    @Override
    public Type_event vx_new(final Object... vals) {return e_event.vx_copy(vals);}

    @Override
    public Type_event vx_copy(final Object... vals) {
      Type_event output = this;
      boolean ischanged = false;
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Type_event val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      Core.Type_string vx_p_name = val.name();
      Core.Type_any vx_p_from = val.from();
      Core.Type_any vx_p_to = val.to();
      Core.Func_any_from_any vx_p_fn_any_from_any = val.fn_any_from_any();
      Event.Func_any_from_from_to vx_p_fn_any_from_from_to = val.fn_any_from_from_to();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":from");
      validkeys.add(":to");
      validkeys.add(":fn-any<-any");
      validkeys.add(":fn-any<-from-to");
      String key = "";
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
          }
          boolean isvalidkey = validkeys.contains(testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            Core.Type_msg msg = Core.vx_msg_error("(new event) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new event :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":from":
            if (valsub == vx_p_from) {
            } else if (valsub instanceof Core.Type_any) {
              ischanged = true;
              vx_p_from = (Core.Type_any)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new event :from " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":to":
            if (valsub == vx_p_to) {
            } else if (valsub instanceof Core.Type_any) {
              ischanged = true;
              vx_p_to = (Core.Type_any)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new event :to " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":fn-any<-any":
            if (valsub == vx_p_fn_any_from_any) {
            } else if (valsub instanceof Core.Func_any_from_any) {
              ischanged = true;
              vx_p_fn_any_from_any = (Core.Func_any_from_any)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new event :fn-any<-any " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":fn-any<-from-to":
            if (valsub == vx_p_fn_any_from_from_to) {
            } else if (valsub instanceof Event.Func_any_from_from_to) {
              ischanged = true;
              vx_p_fn_any_from_from_to = (Event.Func_any_from_from_to)valsub;
            } else {
              Core.Type_msg msg = Core.vx_msg_error("(new event :fn-any<-from-to " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.vx_msg_error("(new event) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_event work = new Class_event();
        work.vx_p_name = vx_p_name;
        work.vx_p_from = vx_p_from;
        work.vx_p_to = vx_p_to;
        work.vx_p_fn_any_from_any = vx_p_fn_any_from_any;
        work.vx_p_fn_any_from_from_to = vx_p_fn_any_from_from_to;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_event vx_empty() {return e_event;}
    @Override
    public Type_event vx_type() {return t_event;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/event", // pkgname
        "event", // name
        ":struct", // extends
        Core.e_typelist, // traits
        Core.e_typelist, // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_event e_event = new Class_event();
  public static final Type_event t_event = new Class_event();

  /**
   * Constant: event-click
   * Click Event
   * {event}
   */
  public static class Const_event_click extends Event.Class_event implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/event", // pkgname
        "event-click", // name
        Core.typedef_new(
          "vx/event", // pkgname
          "event", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_event_click output) {
      Event.Type_event val = Core.f_new(
        Event.t_event,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string(":click")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_from = val.from();
      output.vx_p_to = val.to();
      output.vx_p_fn_any_from_any = val.fn_any_from_any();
      output.vx_p_fn_any_from_from_to = val.fn_any_from_from_to();
    }


  }

  public static final Const_event_click c_event_click = new Const_event_click();


  /**
   * Constant: event-move
   * Move Event
   * {event}
   */
  public static class Const_event_move extends Event.Class_event implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/event", // pkgname
        "event-move", // name
        Core.typedef_new(
          "vx/event", // pkgname
          "event", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_event_move output) {
      Event.Type_event val = Core.f_new(
        Event.t_event,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string(":move")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_from = val.from();
      output.vx_p_to = val.to();
      output.vx_p_fn_any_from_any = val.fn_any_from_any();
      output.vx_p_fn_any_from_from_to = val.fn_any_from_from_to();
    }


  }

  public static final Const_event_move c_event_move = new Const_event_move();

  /**
   * @function any_from_from_to
   * From to handling function.
   * @param  {any} from
   * @param  {any} to
   * @return {any-1}
   * (func any<-from-to)
   */
  public static interface Func_any_from_from_to extends Core.Type_func, Core.Type_replfunc {
    public <T extends Core.Type_any> T f_any_from_from_to(final T generic_any_1, final Core.Type_any from, final Core.Type_any to);
  }

  public static class Class_any_from_from_to extends Core.Class_base implements Func_any_from_from_to {

    @Override
    public Func_any_from_from_to vx_new(Object... vals) {
      Class_any_from_from_to output = new Class_any_from_from_to();
      return output;
    }

    @Override
    public Func_any_from_from_to vx_copy(Object... vals) {
      Class_any_from_from_to output = new Class_any_from_from_to();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/event", // pkgname
        "any<-from-to", // name
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
    public Func_any_from_from_to vx_empty() {return e_any_from_from_to;}
    @Override
    public Func_any_from_from_to vx_type() {return t_any_from_from_to;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any from = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any to = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Event.f_any_from_from_to(generic_any_1, from, to);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T f_any_from_from_to(final T generic_any_1, final Core.Type_any from, final Core.Type_any to) {
      return Event.f_any_from_from_to(generic_any_1, from, to);
    }

  }

  public static final Func_any_from_from_to e_any_from_from_to = new Event.Class_any_from_from_to();
  public static final Func_any_from_from_to t_any_from_from_to = new Event.Class_any_from_from_to();

  public static <T extends Core.Type_any> T f_any_from_from_to(final T generic_any_1, final Core.Type_any from, final Core.Type_any to) {
    T output = Core.f_empty(generic_any_1);
    return output;
  }


  static {
    Const_event_click.const_new(c_event_click);
    Const_event_move.const_new(c_event_move);
    Map<String, Core.Type_any> maptype = new LinkedHashMap<>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<>();
    maptype.put("event", Event.t_event);
    mapconst.put("event-click", Event.c_event_click);
    mapconst.put("event-move", Event.c_event_move);
    mapfunc.put("any<-from-to", Event.t_any_from_from_to);
    Core.vx_global_package_set("vx/event", maptype, mapconst, mapfunc);
  }

}
