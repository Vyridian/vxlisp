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
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Core.Type_string name();
    public Core.Type_string from();
    public Core.Type_string to();
    public Core.Type_anymap datamap();
    public Event.Func_event_from_event event_from_event();
    public Event.Func_event_from_event_async event_from_event_async();
  }

  public static class Class_event extends Core.Class_base implements Type_event {

    public Core.Type_string vx_p_name = null;

    @Override
    public Core.Type_string name() {
      Core.Type_string output = Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Core.Type_string vx_p_from = null;

    @Override
    public Core.Type_string from() {
      Core.Type_string output = Core.e_string;
      if (this.vx_p_from != null) {
        output = this.vx_p_from;
      }
      return output;
    }

    public Core.Type_string vx_p_to = null;

    @Override
    public Core.Type_string to() {
      Core.Type_string output = Core.e_string;
      if (this.vx_p_to != null) {
        output = this.vx_p_to;
      }
      return output;
    }

    public Core.Type_anymap vx_p_datamap = null;

    @Override
    public Core.Type_anymap datamap() {
      Core.Type_anymap output = Core.e_anymap;
      if (this.vx_p_datamap != null) {
        output = this.vx_p_datamap;
      }
      return output;
    }

    public Event.Func_event_from_event vx_p_event_from_event = null;

    @Override
    public Event.Func_event_from_event event_from_event() {
      Event.Func_event_from_event output = Event.e_event_from_event;
      if (this.vx_p_event_from_event != null) {
        output = this.vx_p_event_from_event;
      }
      return output;
    }

    public Event.Func_event_from_event_async vx_p_event_from_event_async = null;

    @Override
    public Event.Func_event_from_event_async event_from_event_async() {
      Event.Func_event_from_event_async output = Event.e_event_from_event_async;
      if (this.vx_p_event_from_event_async != null) {
        output = this.vx_p_event_from_event_async;
      }
      return output;
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
      Map<String, Core.Type_any> output = new LinkedHashMap<String, Core.Type_any>();
      output.put(":name", this.name());
      output.put(":from", this.from());
      output.put(":to", this.to());
      output.put(":datamap", this.datamap());
      output.put(":event<-event", this.event_from_event());
      output.put(":event<-event-async", this.event_from_event_async());
      return Core.immutablemap(output);
    }

    @Override
    public Event.Type_event vx_new(final Object... vals) {
      Event.Type_event output = Core.vx_copy(Event.e_event, vals);
      return output;
    }

    @Override
    public Event.Type_event vx_copy(final Object... vals) {
      Type_event output = this;
      boolean ischanged = false;
      Class_event val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = val.name();
      Core.Type_string vx_p_from = val.from();
      Core.Type_string vx_p_to = val.to();
      Core.Type_anymap vx_p_datamap = val.datamap();
      Event.Func_event_from_event vx_p_event_from_event = val.event_from_event();
      Event.Func_event_from_event_async vx_p_event_from_event_async = val.event_from_event_async();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":name");
      validkeys.add(":from");
      validkeys.add(":to");
      validkeys.add(":datamap");
      validkeys.add(":event<-event");
      validkeys.add(":event<-event-async");
      String key = "";
      Core.Type_msg msg;
      Core.Type_any msgval;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          boolean istestkey = false;
          String testkey = "";
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            String sval = (String)valsub;;
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;;
              msgval = valmsg;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/event/event", ":invalidkeytype", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.startsWith(":")) {
              testkey = ":" + testkey;
            }
            boolean isvalidkey = validkeys.contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/event/event", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valname = (Core.Type_string)valsub;;
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":from":
            if (valsub == vx_p_from) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valfrom = (Core.Type_string)valsub;;
              ischanged = true;
              vx_p_from = valfrom;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_from = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("from"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":to":
            if (valsub == vx_p_to) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valto = (Core.Type_string)valsub;;
              ischanged = true;
              vx_p_to = valto;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_to = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("to"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":datamap":
            if (valsub == vx_p_datamap) {
            } else if (valsub instanceof Core.Type_anymap) {
              Core.Type_anymap valdatamap = (Core.Type_anymap)valsub;;
              ischanged = true;
              vx_p_datamap = valdatamap;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("datamap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":event<-event":
            if (valsub == vx_p_event_from_event) {
            } else if (valsub instanceof Event.Func_event_from_event) {
              Event.Func_event_from_event valevent_from_event = (Event.Func_event_from_event)valsub;;
              ischanged = true;
              vx_p_event_from_event = valevent_from_event;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("event<-event"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":event<-event-async":
            if (valsub == vx_p_event_from_event_async) {
            } else if (valsub instanceof Event.Func_event_from_event_async) {
              Event.Func_event_from_event_async valevent_from_event_async = (Event.Func_event_from_event_async)valsub;;
              ischanged = true;
              vx_p_event_from_event_async = valevent_from_event_async;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("event<-event-async"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/event/event", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
            break;
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
    public Core.Type_any vx_empty() {
      return e_event;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_event;
    }

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
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public List<Event.Type_event> vx_listevent();
    public Event.Type_event vx_event(final Core.Type_int index);
  }

  public static class Class_eventlist extends Core.Class_base implements Type_eventlist {

    public List<Event.Type_event> vx_p_list = Core.immutablelist(new ArrayList<Event.Type_event>());

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(
        new ArrayList<Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    @Override
    public Event.Type_event vx_event(final Core.Type_int index) {
      Event.Type_event output = Event.e_event;
      Event.Class_eventlist list = this;
      int iindex = index.vx_int();
      List<Event.Type_event> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Event.Type_event> vx_listevent() {
      return vx_p_list;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_event(index);
    }

    @Override
    public Event.Type_eventlist vx_new(final Object... vals) {
      Event.Type_eventlist output = Core.vx_copy(Event.e_eventlist, vals);
      return output;
    }

    @Override
    public Event.Type_eventlist vx_copy(final Object... vals) {
      Type_eventlist output = this;
      boolean ischanged = false;
      Class_eventlist val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      List<Event.Type_event> listval = new ArrayList<Event.Type_event>(val.vx_listevent());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Event.Type_event) {
          Event.Type_event allowsub = (Event.Type_event)valsub;;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Event.Type_event) {
          ischanged = true;
          listval.add((Event.Type_event)valsub);
        } else if (valsub instanceof Event.Type_eventlist) {
          Event.Type_eventlist multi = (Event.Type_eventlist)valsub;;
          ischanged = true;
          listval.addAll(multi.vx_listevent());
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof Event.Type_event) {
              Event.Type_event valitem = (Event.Type_event)item;;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;;
          msg = Core.vx_msg_from_error("vx/event/eventlist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/event/eventlist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
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
    public Core.Type_any vx_empty() {
      return e_eventlist;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_eventlist;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/event", // pkgname
        "eventlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Event.t_event), // allowtypes
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
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Map<String, Event.Type_event> vx_mapevent();
    public Event.Type_event vx_event(final Core.Type_string key);
  }

  public static class Class_eventmap extends Core.Class_base implements Type_eventmap {

    public Map<String, Event.Type_event> vx_p_map = Core.immutablemap(new LinkedHashMap<String, Event.Type_event>());

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>(this.vx_p_map);
      return Core.immutablemap(map);
    }

    @Override
    public Core.Type_boolean vx_set(final Core.Type_string name, final Core.Type_any value) {
      Core.Type_boolean output = Core.c_false;
      if (false) {
      } else if (value instanceof Event.Type_event) {
        Event.Type_event castval = (Event.Type_event)value;;
        String key = name.vx_string();
        if (key.startsWith(":")) {
          key = key.substring(1);
        }
        Map<String, Event.Type_event> map = new LinkedHashMap<String, Event.Type_event>(this.vx_p_map);
        if (castval == Event.e_event) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Core.immutablemap(map);
        output = Core.c_true;
      }
      return output;
    }

    @Override
    public Event.Type_event vx_event(final Core.Type_string key) {
      Event.Type_event output = Event.e_event;
      Event.Class_eventmap map = this;
      String skey = key.vx_string();
      Map<String, Event.Type_event> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Event.e_event);
      return output;
    }

    @Override
    public Map<String, Event.Type_event> vx_mapevent() {
      return vx_p_map;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      return this.vx_event(key);
    }

    @Override
    public Core.Type_map vx_new_from_map(final Map<String, Core.Type_any> mapval) {
      Event.Class_eventmap output = new Event.Class_eventmap();
      Core.Type_msgblock msgblock = Core.e_msgblock;
      Map<String, Event.Type_event> map = new LinkedHashMap<String, Event.Type_event>();
      Set<String> keys = mapval.keySet();
      for (String key : keys) {
        Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val instanceof Event.Type_event) {
          Event.Type_event castval = (Event.Type_event)val;;
          map.put(key, castval);
        } else {
          Core.Type_msg msg = Core.vx_msg_from_error("vx/event/eventmap", ":invalidvalue", val);
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Core.immutablemap(map);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Event.Type_eventmap vx_new(final Object... vals) {
      Event.Type_eventmap output = Core.vx_copy(Event.e_eventmap, vals);
      return output;
    }

    @Override
    public Event.Type_eventmap vx_copy(final Object... vals) {
      Type_eventmap output = this;
      boolean ischanged = false;
      Class_eventmap val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Map<String, Event.Type_event> mapval = new LinkedHashMap<String, Event.Type_event>(val.vx_mapevent());
      Core.Type_msg msg = null;
      String key = "";
      Core.Type_any msgval = null;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstring = (Core.Type_string)valsub;;
            key = valstring.vx_string();
          } else if (valsub instanceof String) {
            String sval = (String)valsub;;
            key = sval;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valinvalid = (Core.Type_any)valsub;;
              msgval = valinvalid;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/event/eventmap", ":keyexpected", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
        } else {
          Event.Type_event valany = null;
          if (false) {
          } else if (valsub instanceof Event.Type_event) {
            Event.Type_event valallowed = (Event.Type_event)valsub;;
            valany = valallowed;
          } else if (valsub instanceof Event.Type_event) {
            valany = (Event.Type_event)valsub;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valinvalid = (Core.Type_any)valsub;;
              msgval = valinvalid;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
            mapany.put("key", Core.vx_new_string(key));
            mapany.put("value", msgval);
            Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
            msg = Core.vx_msg_from_error("vx/event/eventmap", ":invalidkeyvalue", msgmap);
            msgblock = Core.vx_copy(msgblock, msg);
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
    public Core.Type_any vx_empty() {
      return e_eventmap;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_eventmap;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/event", // pkgname
        "eventmap", // name
        ":map", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Event.t_event), // allowtypes
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
  public static class Const_event_change {
    public static Core.Type_constdef constdef() {
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

    public static void const_new(Event.Type_event output) {
      Event.Class_event outval = (Event.Class_event)output;
      outval.vx_p_constdef = constdef();
      Event.Type_event val = Core.f_new(
        Event.t_event,
        Core.vx_new(Core.t_anylist,
                Core.vx_new_string(":name"),
                Core.vx_new_string("change")
        )
      );
      outval.vx_p_name = val.name();
      outval.vx_p_from = val.from();
      outval.vx_p_to = val.to();
      outval.vx_p_datamap = val.datamap();
      outval.vx_p_event_from_event = val.event_from_event();
      outval.vx_p_event_from_event_async = val.event_from_event_async();
    }

  }

  public static final Event.Type_event c_event_change = new Event.Class_event();


  /**
   * Constant: event-click
   * Click Event
   * {event}
   */
  public static class Const_event_click {
    public static Core.Type_constdef constdef() {
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

    public static void const_new(Event.Type_event output) {
      Event.Class_event outval = (Event.Class_event)output;
      outval.vx_p_constdef = constdef();
      Event.Type_event val = Core.f_new(
        Event.t_event,
        Core.vx_new(Core.t_anylist,
                Core.vx_new_string(":name"),
                Core.vx_new_string("click")
        )
      );
      outval.vx_p_name = val.name();
      outval.vx_p_from = val.from();
      outval.vx_p_to = val.to();
      outval.vx_p_datamap = val.datamap();
      outval.vx_p_event_from_event = val.event_from_event();
      outval.vx_p_event_from_event_async = val.event_from_event_async();
    }

  }

  public static final Event.Type_event c_event_click = new Event.Class_event();


  /**
   * Constant: event-move
   * Move Event
   * {event}
   */
  public static class Const_event_move {
    public static Core.Type_constdef constdef() {
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

    public static void const_new(Event.Type_event output) {
      Event.Class_event outval = (Event.Class_event)output;
      outval.vx_p_constdef = constdef();
      Event.Type_event val = Core.f_new(
        Event.t_event,
        Core.vx_new(Core.t_anylist,
                Core.vx_new_string(":name"),
                Core.vx_new_string("move")
        )
      );
      outval.vx_p_name = val.name();
      outval.vx_p_from = val.from();
      outval.vx_p_to = val.to();
      outval.vx_p_datamap = val.datamap();
      outval.vx_p_event_from_event = val.event_from_event();
      outval.vx_p_event_from_event_async = val.event_from_event_async();
    }

  }

  public static final Event.Type_event c_event_move = new Event.Class_event();


  /**
   * Constant: event-select
   * Move Event
   * {event}
   */
  public static class Const_event_select {
    public static Core.Type_constdef constdef() {
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

    public static void const_new(Event.Type_event output) {
      Event.Class_event outval = (Event.Class_event)output;
      outval.vx_p_constdef = constdef();
      Event.Type_event val = Core.f_new(
        Event.t_event,
        Core.vx_new(Core.t_anylist,
                Core.vx_new_string(":name"),
                Core.vx_new_string("move")
        )
      );
      outval.vx_p_name = val.name();
      outval.vx_p_from = val.from();
      outval.vx_p_to = val.to();
      outval.vx_p_datamap = val.datamap();
      outval.vx_p_event_from_event = val.event_from_event();
      outval.vx_p_event_from_event_async = val.event_from_event_async();
    }

  }

  public static final Event.Type_event c_event_select = new Event.Class_event();

  /**
   * @function any_from_from_event
   * @param  {event} evt
   * @return {any-1}
   * (func any-from<-event)
   */
  public interface Func_any_from_from_event extends Core.Func_any_from_any {
    public <T extends Core.Type_any> T vx_any_from_from_event(final T generic_any_1, final Event.Type_event evt);
  }

  public static class Class_any_from_from_event extends Core.Class_base implements Func_any_from_from_event {

    @Override
    public Event.Func_any_from_from_event vx_new(final Object... vals) {
      Class_any_from_from_event output = new Class_any_from_from_event();
      return output;
    }

    @Override
    public Event.Func_any_from_from_event vx_copy(final Object... vals) {
      Class_any_from_from_event output = new Class_any_from_from_event();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

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
    public Core.Type_any vx_empty() {
      return e_any_from_from_event;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_any_from_from_event;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

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
      Event.Type_event evt = Core.f_any_from_any(Event.t_event, arglist.vx_any(Core.vx_new_int(0)));
      output = Event.f_any_from_from_event(generic_any_1, evt);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T vx_any_from_from_event(final T generic_any_1, final Event.Type_event evt) {
      return Event.f_any_from_from_event(generic_any_1, evt);
    }

  }

  public static final Func_any_from_from_event e_any_from_from_event = new Event.Class_any_from_from_event();
  public static final Func_any_from_from_event t_any_from_from_event = new Event.Class_any_from_from_event();

  public static <T extends Core.Type_any> T f_any_from_from_event(final T generic_any_1, final Event.Type_event evt) {
    T output = Core.f_empty(generic_any_1);
    output = Core.f_let(
      generic_any_1,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_any value = evt.from();
        Core.Type_any output_1 = Core.f_any_from_any(generic_any_1, value);
        return output_1;
      })
    );
    return output;
  }

  /**
   * @function event_from_event
   * Template for triggering ui events
   * @param  {event} evt
   * @return {event}
   * (func event<-event)
   */
  public interface Func_event_from_event extends Core.Func_any_from_any_context {
    public Event.Type_event vx_event_from_event(final Core.Type_context context, final Event.Type_event evt);
  }

  public static class Class_event_from_event extends Core.Class_base implements Func_event_from_event {

    @Override
    public Event.Func_event_from_event vx_new(final Object... vals) {
      Class_event_from_event output = new Class_event_from_event();
      return output;
    }

    @Override
    public Event.Func_event_from_event vx_copy(final Object... vals) {
      Class_event_from_event output = new Class_event_from_event();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

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
    public Core.Type_any vx_empty() {
      return e_event_from_event;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_event_from_event;
    }

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {
      return Core.e_any_from_any_context;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Event.Type_event inputval = (Event.Type_event)value;
      Core.Type_any outputval = Event.f_event_from_event(context, inputval);
      output = Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Event.Type_event evt = Core.f_any_from_any(Event.t_event, arglist.vx_any(Core.vx_new_int(0)));
      output = Event.f_event_from_event(context, evt);
      return output;
    }

    @Override
    public Event.Type_event vx_event_from_event(final Core.Type_context context, final Event.Type_event evt) {
      return Event.f_event_from_event(context, evt);
    }

  }

  public static final Func_event_from_event e_event_from_event = new Event.Class_event_from_event();
  public static final Func_event_from_event t_event_from_event = new Event.Class_event_from_event();

  public static Event.Type_event f_event_from_event(final Core.Type_context context, final Event.Type_event evt) {
    Event.Type_event output = Event.e_event;
    output = evt;
    return output;
  }

  /**
   * 
   * @async
   * @function event_from_event_async
   * Template for triggering ui asynchronous events
   * @param  {event} evt
   * @return {event}
   * (func event<-event-async)
   */
  public interface Func_event_from_event_async extends Core.Func_any_from_any_context_async {
    public CompletableFuture<Event.Type_event> vx_event_from_event_async(final Core.Type_context context, final Event.Type_event evt);
  }

  public static class Class_event_from_event_async extends Core.Class_base implements Func_event_from_event_async {

    @Override
    public Event.Func_event_from_event_async vx_new(final Object... vals) {
      Class_event_from_event_async output = new Class_event_from_event_async();
      return output;
    }

    @Override
    public Event.Func_event_from_event_async vx_copy(final Object... vals) {
      Class_event_from_event_async output = new Class_event_from_event_async();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

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
    public Core.Type_any vx_empty() {
      return e_event_from_event_async;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_event_from_event_async;
    }

    @Override
    public Core.Func_any_from_any_context_async vx_fn_new(Core.Class_any_from_any_context_async.IFn fn) {
      return Core.e_any_from_any_context_async;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> vx_any_from_any_context_async(final T generic_any_1, final Core.Type_context context, final U value) {
      Event.Type_event inputval = Core.f_any_from_any(Event.t_event, value);
      CompletableFuture<Event.Type_event> future = Event.f_event_from_event_async(context, inputval);
      @SuppressWarnings("unchecked")
      CompletableFuture<T> output = (CompletableFuture<T>)future;
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = Core.vx_async_new_completed(Core.e_any);
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Event.Type_event evt = Core.f_any_from_any(Event.t_event, arglist.vx_any(Core.vx_new_int(0)));
      CompletableFuture<Event.Type_event> future = Event.f_event_from_event_async(context, evt);
      output = Core.vx_async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Event.Type_event> vx_event_from_event_async(final Core.Type_context context, final Event.Type_event evt) {
      return Event.f_event_from_event_async(context, evt);
    }

  }

  public static final Func_event_from_event_async e_event_from_event_async = new Event.Class_event_from_event_async();
  public static final Func_event_from_event_async t_event_from_event_async = new Event.Class_event_from_event_async();

  public static CompletableFuture<Event.Type_event> f_event_from_event_async(final Core.Type_context context, final Event.Type_event evt) {
    CompletableFuture<Event.Type_event> output = Core.vx_async_new_completed(Event.e_event);
    return output;
  }

  /**
   * @function eventmap_from_eventlist
   * Returns an eventmap from an eventlist
   * @param  {eventlist} eventlist
   * @return {eventmap}
   * (func eventmap<-eventlist)
   */
  public interface Func_eventmap_from_eventlist extends Core.Func_any_from_any {
    public Event.Type_eventmap vx_eventmap_from_eventlist(final Event.Type_eventlist eventlist);
  }

  public static class Class_eventmap_from_eventlist extends Core.Class_base implements Func_eventmap_from_eventlist {

    @Override
    public Event.Func_eventmap_from_eventlist vx_new(final Object... vals) {
      Class_eventmap_from_eventlist output = new Class_eventmap_from_eventlist();
      return output;
    }

    @Override
    public Event.Func_eventmap_from_eventlist vx_copy(final Object... vals) {
      Class_eventmap_from_eventlist output = new Class_eventmap_from_eventlist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

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
          Core.vx_new(Core.t_typelist, Event.t_event), // allowtypes
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
      return e_eventmap_from_eventlist;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_eventmap_from_eventlist;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

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
      Core.t_any_from_any.vx_fn_new((evt_any) -> {
        Event.Type_event evt = Core.f_any_from_any(Event.t_event, evt_any);
        Core.Type_any output_1 = 
          evt.name();
        return output_1;
      })
    );
    return output;
  }


  static {
    Const_event_change.const_new(c_event_change);
    Const_event_click.const_new(c_event_click);
    Const_event_move.const_new(c_event_move);
    Const_event_select.const_new(c_event_select);
    Map<String, Core.Type_any> maptype = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<String, Core.Type_func>();
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
