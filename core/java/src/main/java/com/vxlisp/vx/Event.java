package com.vxlisp.vx;

import java.util.ArrayList;
import java.util.concurrent.CompletableFuture;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

public final class Event {


  /**
   * type: event
   * Generic Event
   * (type event)
   */
  public interface Type_event extends Core.Type_struct {
    public Event.Type_event vx_new(final Object... vals);
    public Event.Type_event vx_copy(final Object... vals);
    public Event.Type_event vx_empty();
    public Event.Type_event vx_type();
    public Core.Type_string name();
    public Core.Type_string from();
    public Core.Type_string to();
    public Core.Type_anymap datamap();
    public Event.Func_event_from_event event_from_event();
    public Event.Func_event_from_event_async event_from_event_async();
  }

  public static class Class_event extends Core.Class_base implements Type_event {

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_string vx_p_from;

    @Override
    public Core.Type_string from() {
      return this.vx_p_from == null ? Core.e_string : this.vx_p_from;
    }

    protected Core.Type_string vx_p_to;

    @Override
    public Core.Type_string to() {
      return this.vx_p_to == null ? Core.e_string : this.vx_p_to;
    }

    protected Core.Type_anymap vx_p_datamap;

    @Override
    public Core.Type_anymap datamap() {
      return this.vx_p_datamap == null ? Core.e_anymap : this.vx_p_datamap;
    }

    protected Event.Func_event_from_event vx_p_event_from_event;

    @Override
    public Event.Func_event_from_event event_from_event() {
      return this.vx_p_event_from_event == null ? Event.e_event_from_event : this.vx_p_event_from_event;
    }

    protected Event.Func_event_from_event_async vx_p_event_from_event_async;

    @Override
    public Event.Func_event_from_event_async event_from_event_async() {
      return this.vx_p_event_from_event_async == null ? Event.e_event_from_event_async : this.vx_p_event_from_event_async;
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
      case ":datamap":
        output = this.datamap();
        break;
      case ":event<-event":
        output = this.event_from_event();
        break;
      case ":event<-event-async":
        output = this.event_from_event_async();
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
      output.put(":datamap", this.datamap());
      output.put(":event<-event", this.event_from_event());
      output.put(":event<-event-async", this.event_from_event_async());
      return Core.immutablemap(output);
    }

    @Override
    public Type_event vx_new(final Object... vals) {
      return e_event.vx_copy(vals);
    }

    @Override
    public Type_event vx_copy(final Object... vals) {
      Type_event output = this;
      boolean ischanged = false;
      Class_event val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = val.name();
      Core.Type_string vx_p_from = val.from();
      Core.Type_string vx_p_to = val.to();
      Core.Type_anymap vx_p_datamap = val.datamap();
      Event.Func_event_from_event vx_p_event_from_event = val.event_from_event();
      Event.Func_event_from_event_async vx_p_event_from_event_async = val.event_from_event_async();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":from");
      validkeys.add(":to");
      validkeys.add(":datamap");
      validkeys.add(":event<-event");
      validkeys.add(":event<-event-async");
      String key = "";
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/event/event", ":invalidkeytype", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              Core.Type_any msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/event/event", ":invalidkey", msgval);
              msgblock = msgblock.vx_copy(msg);
            }
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
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":from":
            if (valsub == vx_p_from) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_from = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_from = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("from"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":to":
            if (valsub == vx_p_to) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_to = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_to = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("to"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":datamap":
            if (valsub == vx_p_datamap) {
            } else if (valsub instanceof Core.Type_anymap) {
              ischanged = true;
              vx_p_datamap = (Core.Type_anymap)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("datamap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":event<-event":
            if (valsub == vx_p_event_from_event) {
            } else if (valsub instanceof Event.Func_event_from_event) {
              ischanged = true;
              vx_p_event_from_event = (Event.Func_event_from_event)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("event<-event"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":event<-event-async":
            if (valsub == vx_p_event_from_event_async) {
            } else if (valsub instanceof Event.Func_event_from_event_async) {
              ischanged = true;
              vx_p_event_from_event_async = (Event.Func_event_from_event_async)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("event<-event-async"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/event/event", ":invalidkey", msgval);
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
        work.vx_p_datamap = vx_p_datamap;
        work.vx_p_event_from_event = vx_p_event_from_event;
        work.vx_p_event_from_event_async = vx_p_event_from_event_async;
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
   * type: eventlist
   * Map of event
   * (type eventlist)
   */
  public interface Type_eventlist extends Core.Type_list {
    public Event.Type_eventlist vx_new(final Object... vals);
    public Event.Type_eventlist vx_copy(final Object... vals);
    public Event.Type_eventlist vx_empty();
    public Event.Type_eventlist vx_type();
    public List<Event.Type_event> vx_listevent();
    public Event.Type_event vx_event(final Core.Type_int index);
  }

  public static class Class_eventlist extends Core.Class_base implements Type_eventlist {

    protected List<Event.Type_event> vx_p_list = Core.immutablelist(new ArrayList<Event.Type_event>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Event.Type_event vx_event(final Core.Type_int index) {
      Event.Type_event output = Event.e_event;
      Class_eventlist list = this;
      int iindex = index.vx_int();
      List<Event.Type_event> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Event.Type_event> vx_listevent() {return vx_p_list;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_event(index);
    }

    @Override
    public Type_eventlist vx_new(final Object... vals) {
      return e_eventlist.vx_copy(vals);
    }

    @Override
    public Type_eventlist vx_copy(final Object... vals) {
      Type_eventlist output = this;
      boolean ischanged = false;
      Class_eventlist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      List<Event.Type_event> listval = new ArrayList<>(val.vx_listevent());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Event.Type_event) {
          ischanged = true;
          listval.add((Event.Type_event)valsub);
        } else if (valsub instanceof Event.Type_event) {
          ischanged = true;
          listval.add((Event.Type_event)valsub);
        } else if (valsub instanceof Type_eventlist) {
          Type_eventlist multi = (Type_eventlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listevent());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Event.Type_event) {
              Event.Type_event valitem = (Event.Type_event)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anysub = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/event/eventlist", ":invalidtype", anysub);
          msgblock = msgblock.vx_copy(msg);
        } else {
          msg = Core.vx_msg_from_error("vx/event/eventlist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_eventlist work = new Class_eventlist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_eventlist vx_empty() {return e_eventlist;}
    @Override
    public Type_eventlist vx_type() {return t_eventlist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/event", // pkgname
        "eventlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Event.t_event), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_eventlist e_eventlist = new Class_eventlist();
  public static final Type_eventlist t_eventlist = new Class_eventlist();

  /**
   * type: eventmap
   * Map of event
   * (type eventmap)
   */
  public interface Type_eventmap extends Core.Type_map {
    public Event.Type_eventmap vx_new(final Object... vals);
    public Event.Type_eventmap vx_copy(final Object... vals);
    public Event.Type_eventmap vx_empty();
    public Event.Type_eventmap vx_type();
    public Map<String, Event.Type_event> vx_mapevent();
    public Event.Type_event vx_event(final Core.Type_string key);
  }

  public static class Class_eventmap extends Core.Class_base implements Type_eventmap {

    protected Map<String, Event.Type_event> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Event.Type_event>());

    @Override
    public Map<String, Core.Type_any> vx_map() {return Core.immutablemap(new LinkedHashMap<String, Core.Type_any>(this.vx_p_map));}

    @Override
    public Event.Type_event vx_event(final Core.Type_string key) {
      Event.Type_event output = Event.e_event;
      Class_eventmap map = this;
      String skey = key.vx_string();
      Map<String, Event.Type_event> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Event.e_event);
      return output;
    }

    @Override
    public Map<String, Event.Type_event> vx_mapevent() {return vx_p_map;}

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_event(key);
    }

    @Override
    public Type_eventmap vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Class_eventmap output = new Class_eventmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Event.Type_event> map = new LinkedHashMap<>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (val instanceof Event.Type_event) {
          Event.Type_event castval = (Event.Type_event)val;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/event/eventmap", ":invalidvalue", val);
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
    public Type_eventmap vx_new(final Object... vals) {
      return e_eventmap.vx_copy(vals);
    }

    @Override
    public Type_eventmap vx_copy(final Object... vals) {
      Type_eventmap output = this;
      boolean ischanged = false;
      Class_eventmap val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Map<String, Event.Type_event> mapval = new LinkedHashMap<>(val.vx_mapevent());
      Core.Type_msg msg;
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
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/event/eventmap", ":keyexpected", msgval);
            msgblock = Core.t_msgblock.vx_copy(msgblock, msg);
          }
        } else {
          Event.Type_event valany = null;
          if (valsub instanceof Event.Type_event) {
            valany = (Event.Type_event)valsub;
          } else if (valsub instanceof Event.Type_event) {
            valany = (Event.Type_event)valsub;
          } else {
            Core.Type_any msgval;
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
            mapany.put("key", Core.vx_new_string(key));
            mapany.put("value", msgval);
            Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
            msg = Core.vx_msg_from_error("vx/event/eventmap", ":invalidkeyvalue", msgmap);
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
        Class_eventmap work = new Class_eventmap();
        work.vx_p_map = Core.immutablemap(mapval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_eventmap vx_empty() {return e_eventmap;}
    @Override
    public Type_eventmap vx_type() {return t_eventmap;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/event", // pkgname
        "eventmap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Event.t_event), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_eventmap e_eventmap = new Class_eventmap();
  public static final Type_eventmap t_eventmap = new Class_eventmap();

  /**
   * Constant: event-change
   * Change Event
   * {event}
   */
  public static class Const_event_change extends Event.Class_event implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/event", // pkgname
        "event-change", // name
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

    public static void const_new(Const_event_change output) {
      Event.Type_event val = Core.f_new(
        Event.t_event,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("change")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_from = val.from();
      output.vx_p_to = val.to();
      output.vx_p_datamap = val.datamap();
      output.vx_p_event_from_event = val.event_from_event();
      output.vx_p_event_from_event_async = val.event_from_event_async();
    }


  }

  public static final Const_event_change c_event_change = new Const_event_change();


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
                Core.vx_new_string("click")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_from = val.from();
      output.vx_p_to = val.to();
      output.vx_p_datamap = val.datamap();
      output.vx_p_event_from_event = val.event_from_event();
      output.vx_p_event_from_event_async = val.event_from_event_async();
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
                Core.vx_new_string("move")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_from = val.from();
      output.vx_p_to = val.to();
      output.vx_p_datamap = val.datamap();
      output.vx_p_event_from_event = val.event_from_event();
      output.vx_p_event_from_event_async = val.event_from_event_async();
    }


  }

  public static final Const_event_move c_event_move = new Const_event_move();


  /**
   * Constant: event-select
   * Move Event
   * {event}
   */
  public static class Const_event_select extends Event.Class_event implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/event", // pkgname
        "event-select", // name
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

    public static void const_new(Const_event_select output) {
      Event.Type_event val = Core.f_new(
        Event.t_event,
        Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("move")
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_from = val.from();
      output.vx_p_to = val.to();
      output.vx_p_datamap = val.datamap();
      output.vx_p_event_from_event = val.event_from_event();
      output.vx_p_event_from_event_async = val.event_from_event_async();
    }


  }

  public static final Const_event_select c_event_select = new Const_event_select();

  /**
   * @function any_from_from_event
   * @param  {event} event
   * @return {any-1}
   * (func any-from<-event)
   */
  public static interface Func_any_from_from_event extends Core.Func_any_from_any {
    public <T extends Core.Type_any> T vx_any_from_from_event(final T generic_any_1, final Event.Type_event event);
  }

  public static class Class_any_from_from_event extends Core.Class_base implements Func_any_from_from_event {

    @Override
    public Func_any_from_from_event vx_new(Object... vals) {
      Class_any_from_from_event output = new Class_any_from_from_event();
      return output;
    }

    @Override
    public Func_any_from_from_event vx_copy(Object... vals) {
      Class_any_from_from_event output = new Class_any_from_from_event();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/event", // pkgname
        "any-from<-event", // name
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
    public Func_any_from_from_event vx_empty() {return e_any_from_from_event;}
    @Override
    public Func_any_from_from_event vx_type() {return t_any_from_from_event;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Event.Type_event inputval = (Event.Type_event)value;
      Core.Type_any outputval = Event.f_any_from_from_event(Core.t_any, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Event.Type_event event = Core.f_any_from_any(Event.t_event, arglist.vx_any(Core.vx_new_int(0)));
      output = Event.f_any_from_from_event(generic_any_1, event);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T vx_any_from_from_event(final T generic_any_1, final Event.Type_event event) {
      return Event.f_any_from_from_event(generic_any_1, event);
    }

  }

  public static final Func_any_from_from_event e_any_from_from_event = new Event.Class_any_from_from_event();
  public static final Func_any_from_from_event t_any_from_from_event = new Event.Class_any_from_from_event();

  public static <T extends Core.Type_any> T f_any_from_from_event(final T generic_any_1, final Event.Type_event event) {
    T output = Core.f_empty(generic_any_1);
    output = Core.f_let(
      generic_any_1,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_any value = event.from();
        return Core.f_any_from_any(generic_any_1, value);
      })
    );
    return output;
  }

  /**
   * @function event_from_event
   * Template for triggering ui events
   * @param  {event} event
   * @return {event}
   * (func event<-event)
   */
  public static interface Func_event_from_event extends Core.Func_any_from_any_context {
    public Event.Type_event vx_event_from_event(final Core.Type_context context, final Event.Type_event event);
  }

  public static class Class_event_from_event extends Core.Class_base implements Func_event_from_event {

    @Override
    public Func_event_from_event vx_new(Object... vals) {
      Class_event_from_event output = new Class_event_from_event();
      return output;
    }

    @Override
    public Func_event_from_event vx_copy(Object... vals) {
      Class_event_from_event output = new Class_event_from_event();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/event", // pkgname
        "event<-event", // name
        0, // idx
        false, // async
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
        ) // typedef
      );
    }

    @Override
    public Func_event_from_event vx_empty() {return e_event_from_event;}
    @Override
    public Func_event_from_event vx_type() {return t_event_from_event;}

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Event.Type_event inputval = (Event.Type_event)value;
      Core.Type_any outputval = Event.f_event_from_event(context, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Event.Type_event event = Core.f_any_from_any(Event.t_event, arglist.vx_any(Core.vx_new_int(0)));
      output = Event.f_event_from_event(context, event);
      return output;
    }

    @Override
    public Event.Type_event vx_event_from_event(final Core.Type_context context, final Event.Type_event event) {
      return Event.f_event_from_event(context, event);
    }

  }

  public static final Func_event_from_event e_event_from_event = new Event.Class_event_from_event();
  public static final Func_event_from_event t_event_from_event = new Event.Class_event_from_event();

  public static Event.Type_event f_event_from_event(final Core.Type_context context, final Event.Type_event event) {
    Event.Type_event output = Event.e_event;
    output = event;
    return output;
  }

  /**
   * 
   * @async
   * @function event_from_event_async
   * Template for triggering ui asynchronous events
   * @param  {event} event
   * @return {event}
   * (func event<-event-async)
   */
  public static interface Func_event_from_event_async extends Core.Func_any_from_any_context_async {
    public CompletableFuture<Event.Type_event> vx_event_from_event_async(final Core.Type_context context, final Event.Type_event event);
  }

  public static class Class_event_from_event_async extends Core.Class_base implements Func_event_from_event_async {

    @Override
    public Func_event_from_event_async vx_new(Object... vals) {
      Class_event_from_event_async output = new Class_event_from_event_async();
      return output;
    }

    @Override
    public Func_event_from_event_async vx_copy(Object... vals) {
      Class_event_from_event_async output = new Class_event_from_event_async();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/event", // pkgname
        "event<-event-async", // name
        0, // idx
        true, // async
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
        ) // typedef
      );
    }

    @Override
    public Func_event_from_event_async vx_empty() {return e_event_from_event_async;}
    @Override
    public Func_event_from_event_async vx_type() {return t_event_from_event_async;}

    @Override
    public Core.Func_any_from_any_context_async vx_fn_new(Core.Class_any_from_any_context_async.IFn fn) {return Core.e_any_from_any_context_async;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> vx_any_from_any_context_async(final T generic_any_1, final Core.Type_context context, final U value) {
      Event.Type_event inputval = Core.f_any_from_any(Event.t_event, value);
      CompletableFuture<Event.Type_event> future = Event.f_event_from_event_async(context, inputval);
      @SuppressWarnings("unchecked")
      CompletableFuture<T> output = (CompletableFuture<T>)future;
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Event.Type_event event = Core.f_any_from_any(Event.t_event, arglist.vx_any(Core.vx_new_int(0)));
      CompletableFuture<Event.Type_event> future = Event.f_event_from_event_async(context, event);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Event.Type_event> vx_event_from_event_async(final Core.Type_context context, final Event.Type_event event) {
      return Event.f_event_from_event_async(context, event);
    }

  }

  public static final Func_event_from_event_async e_event_from_event_async = new Event.Class_event_from_event_async();
  public static final Func_event_from_event_async t_event_from_event_async = new Event.Class_event_from_event_async();

  public static CompletableFuture<Event.Type_event> f_event_from_event_async(final Core.Type_context context, final Event.Type_event event) {
    CompletableFuture<Event.Type_event> output = Core.async_new_completed(Event.e_event);
    return output;
  }

  /**
   * @function eventmap_from_eventlist
   * Returns an eventmap from an eventlist
   * @param  {eventlist} eventlist
   * @return {eventmap}
   * (func eventmap<-eventlist)
   */
  public static interface Func_eventmap_from_eventlist extends Core.Func_any_from_any {
    public Event.Type_eventmap vx_eventmap_from_eventlist(final Event.Type_eventlist eventlist);
  }

  public static class Class_eventmap_from_eventlist extends Core.Class_base implements Func_eventmap_from_eventlist {

    @Override
    public Func_eventmap_from_eventlist vx_new(Object... vals) {
      Class_eventmap_from_eventlist output = new Class_eventmap_from_eventlist();
      return output;
    }

    @Override
    public Func_eventmap_from_eventlist vx_copy(Object... vals) {
      Class_eventmap_from_eventlist output = new Class_eventmap_from_eventlist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/event", // pkgname
        "eventmap<-eventlist", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/event", // pkgname
          "eventmap", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Event.t_event), // allowtypes
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
    public Func_eventmap_from_eventlist vx_empty() {return e_eventmap_from_eventlist;}
    @Override
    public Func_eventmap_from_eventlist vx_type() {return t_eventmap_from_eventlist;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Event.Type_eventlist inputval = (Event.Type_eventlist)value;
      Core.Type_any outputval = Event.f_eventmap_from_eventlist(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Event.Type_eventlist eventlist = Core.f_any_from_any(Event.t_eventlist, arglist.vx_any(Core.vx_new_int(0)));
      output = Event.f_eventmap_from_eventlist(eventlist);
      return output;
    }

    @Override
    public Event.Type_eventmap vx_eventmap_from_eventlist(final Event.Type_eventlist eventlist) {
      return Event.f_eventmap_from_eventlist(eventlist);
    }

  }

  public static final Func_eventmap_from_eventlist e_eventmap_from_eventlist = new Event.Class_eventmap_from_eventlist();
  public static final Func_eventmap_from_eventlist t_eventmap_from_eventlist = new Event.Class_eventmap_from_eventlist();

  public static Event.Type_eventmap f_eventmap_from_eventlist(final Event.Type_eventlist eventlist) {
    Event.Type_eventmap output = Event.e_eventmap;
    output = Core.f_map_from_list(
      Event.t_eventmap,
      eventlist,
      Core.t_any_from_any.vx_fn_new((event_any) -> {
        Event.Type_event event = Core.f_any_from_any(Event.t_event, event_any);
        return 
          event.name();
      })
    );
    return output;
  }


  static {
    Const_event_change.const_new(c_event_change);
    Const_event_click.const_new(c_event_click);
    Const_event_move.const_new(c_event_move);
    Const_event_select.const_new(c_event_select);
    Map<String, Core.Type_any> maptype = new LinkedHashMap<>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<>();
    maptype.put("event", Event.t_event);
    maptype.put("eventlist", Event.t_eventlist);
    maptype.put("eventmap", Event.t_eventmap);
    mapconst.put("event-change", Event.c_event_change);
    mapconst.put("event-click", Event.c_event_click);
    mapconst.put("event-move", Event.c_event_move);
    mapconst.put("event-select", Event.c_event_select);
    mapfunc.put("any-from<-event", Event.t_any_from_from_event);
    mapfunc.put("event<-event", Event.t_event_from_event);
    mapfunc.put("event<-event-async", Event.t_event_from_event_async);
    mapfunc.put("eventmap<-eventlist", Event.t_eventmap_from_eventlist);
    Core.vx_global_package_set("vx/event", maptype, mapconst, mapfunc);
  }

}
