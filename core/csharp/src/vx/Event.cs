namespace Vx;

public static class Event {


  /**
   * type: event
   * Generic Event
   * (type event)
   */
  public interface Type_event : Vx.Core.Type_struct {
    public Vx.Core.Type_string name();
    public Vx.Core.Type_string from();
    public Vx.Core.Type_string to();
    public Vx.Core.Type_anymap datamap();
    public Vx.Event.Func_event_from_event event_from_event();
    public Vx.Event.Func_event_from_event_async event_from_event_async();
  }

  public class Class_event : Vx.Core.Class_base, Type_event {

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_from = null;

    public Vx.Core.Type_string from() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_from != null) {
        output = this.vx_p_from;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_to = null;

    public Vx.Core.Type_string to() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_to != null) {
        output = this.vx_p_to;
      }
      return output;
    }

    public Vx.Core.Type_anymap? vx_p_datamap = null;

    public Vx.Core.Type_anymap datamap() {
      Vx.Core.Type_anymap output = Vx.Core.e_anymap;
      if (this.vx_p_datamap != null) {
        output = this.vx_p_datamap;
      }
      return output;
    }

    public Vx.Event.Func_event_from_event? vx_p_event_from_event = null;

    public Vx.Event.Func_event_from_event event_from_event() {
      Vx.Event.Func_event_from_event output = Vx.Event.e_event_from_event;
      if (this.vx_p_event_from_event != null) {
        output = this.vx_p_event_from_event;
      }
      return output;
    }

    public Vx.Event.Func_event_from_event_async? vx_p_event_from_event_async = null;

    public Vx.Event.Func_event_from_event_async event_from_event_async() {
      Vx.Event.Func_event_from_event_async output = Vx.Event.e_event_from_event_async;
      if (this.vx_p_event_from_event_async != null) {
        output = this.vx_p_event_from_event_async;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":name", this.name());
      output.put(":from", this.from());
      output.put(":to", this.to());
      output.put(":datamap", this.datamap());
      output.put(":event<-event", this.event_from_event());
      output.put(":event<-event-async", this.event_from_event_async());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Event.Type_event vx_new(params Object[] vals) {
      Vx.Event.Type_event output = Vx.Core.vx_copy(Vx.Event.e_event, vals);
      return output;
    }

    public override Vx.Event.Type_event vx_copy(params Object[] vals) {
      Type_event output = this;
      bool ischanged = false;
      Class_event val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_name = val.name();
      Vx.Core.Type_string vx_p_from = val.from();
      Vx.Core.Type_string vx_p_to = val.to();
      Vx.Core.Type_anymap vx_p_datamap = val.datamap();
      Vx.Event.Func_event_from_event vx_p_event_from_event = val.event_from_event();
      Vx.Event.Func_event_from_event_async vx_p_event_from_event_async = val.event_from_event_async();
      List<string> validkeys = new List<string>();
      validkeys.Add(":name");
      validkeys.Add(":from");
      validkeys.Add(":to");
      validkeys.Add(":datamap");
      validkeys.Add(":event<-event");
      validkeys.Add(":event<-event-async");
      string key = "";
      Vx.Core.Type_msg msg;
      Vx.Core.Type_any msgval;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (false) {
          } else if (valsub is Vx.Core.Type_string valstr) {
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string sval) {
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub is Vx.Core.Type_any valmsg) {
              msgval = valmsg;
            } else {
              msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
            }
            msg = Vx.Core.vx_msg_from_error("vx/event/event", ":invalidkeytype", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.StartsWith(":")) {
              testkey = ":" + testkey;
            }
            bool isvalidkey = validkeys.Contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Vx.Core.vx_new_string(testkey);
              msg = Vx.Core.vx_msg_from_error("vx/event/event", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is Vx.Core.Type_string valname) {
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":from":
            if (valsub == vx_p_from) {
            } else if (valsub is Vx.Core.Type_string valfrom) {
              ischanged = true;
              vx_p_from = valfrom;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_from = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("from"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":to":
            if (valsub == vx_p_to) {
            } else if (valsub is Vx.Core.Type_string valto) {
              ischanged = true;
              vx_p_to = valto;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_to = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("to"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":datamap":
            if (valsub == vx_p_datamap) {
            } else if (valsub is Vx.Core.Type_anymap valdatamap) {
              ischanged = true;
              vx_p_datamap = valdatamap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("datamap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":event<-event":
            if (valsub == vx_p_event_from_event) {
            } else if (valsub is Vx.Event.Func_event_from_event valevent_from_event) {
              ischanged = true;
              vx_p_event_from_event = valevent_from_event;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("event<-event"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":event<-event-async":
            if (valsub == vx_p_event_from_event_async) {
            } else if (valsub is Vx.Event.Func_event_from_event_async valevent_from_event_async) {
              ischanged = true;
              vx_p_event_from_event_async = valevent_from_event_async;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("event<-event-async"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/event/event", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_event work = new Class_event();
        work.vx_p_name = vx_p_name;
        work.vx_p_from = vx_p_from;
        work.vx_p_to = vx_p_to;
        work.vx_p_datamap = vx_p_datamap;
        work.vx_p_event_from_event = vx_p_event_from_event;
        work.vx_p_event_from_event_async = vx_p_event_from_event_async;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_event;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_event;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/event", // pkgname
        "event", // name
        ":struct", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.e_typelist, // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
    }

  }

  public static Type_event e_event = new Class_event();
  public static Type_event t_event = new Class_event();

  /**
   * type: eventlist
   * Map of event
   * (type eventlist)
   */
  public interface Type_eventlist : Vx.Core.Type_list {
    public List<Vx.Event.Type_event> vx_listevent();
    public Vx.Event.Type_event vx_event(Vx.Core.Type_int index);
  }

  public class Class_eventlist : Vx.Core.Class_base, Type_eventlist {

    public List<Vx.Event.Type_event> vx_p_list = Vx.Core.immutablelist(new List<Vx.Event.Type_event>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Event.Type_event vx_event(Vx.Core.Type_int index) {
      Vx.Event.Type_event output = Vx.Event.e_event;
      Vx.Event.Class_eventlist list = this;
      int iindex = index.vx_int();
      List<Vx.Event.Type_event> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Event.Type_event> vx_listevent() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_event(index);
    }

    public override Vx.Event.Type_eventlist vx_new(params Object[] vals) {
      Vx.Event.Type_eventlist output = Vx.Core.vx_copy(Vx.Event.e_eventlist, vals);
      return output;
    }

    public override Vx.Event.Type_eventlist vx_copy(params Object[] vals) {
      Type_eventlist output = this;
      bool ischanged = false;
      Class_eventlist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Event.Type_event> listval = new List<Vx.Event.Type_event>(val.vx_listevent());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Event.Type_event allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Event.Type_event) {
          ischanged = true;
          listval.Add((Vx.Event.Type_event)valsub);
        } else if (valsub is Vx.Event.Type_eventlist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listevent());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (false) {
            } else if (item is Vx.Event.Type_event valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/event/eventlist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/event/eventlist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_eventlist work = new Class_eventlist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_eventlist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_eventlist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/event", // pkgname
        "eventlist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Event.t_event), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
    }

  }

  public static Type_eventlist e_eventlist = new Class_eventlist();
  public static Type_eventlist t_eventlist = new Class_eventlist();

  /**
   * type: eventmap
   * Map of event
   * (type eventmap)
   */
  public interface Type_eventmap : Vx.Core.Type_map {
    public Vx.Core.Map<string, Vx.Event.Type_event> vx_mapevent();
    public Vx.Event.Type_event vx_event(Vx.Core.Type_string key);
  }

  public class Class_eventmap : Vx.Core.Class_base, Type_eventmap {

    public Vx.Core.Map<string, Vx.Event.Type_event> vx_p_map = Vx.Core.immutablemap(new Vx.Core.LinkedHashMap<string, Vx.Event.Type_event>());

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> anymap = Vx.Core.vx_map_from_map<Vx.Core.Type_any, Vx.Event.Type_event>(this.vx_p_map);
      Vx.Core.Map<string, Vx.Core.Type_any> map = anymap.copy();
      return Vx.Core.immutablemap(map);
    }

    public Vx.Core.Type_boolean vx_set(Vx.Core.Type_string name, Vx.Core.Type_any value) {
      Vx.Core.Type_boolean output = Vx.Core.c_false;
      if (false) {
      } else if (value is Vx.Event.Type_event castval) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx.Core.Map<string, Vx.Event.Type_event> map = new Vx.Core.LinkedHashMap<string, Vx.Event.Type_event>(this.vx_p_map);
        if (castval == Vx.Event.e_event) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx.Core.immutablemap(map);
        output = Vx.Core.c_true;
      }
      return output;
    }

    public Vx.Event.Type_event vx_event(Vx.Core.Type_string key) {
      Vx.Event.Type_event output = Vx.Event.e_event;
      Vx.Event.Class_eventmap map = this;
      string skey = key.vx_string();
      Vx.Core.Map<string, Vx.Event.Type_event> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Vx.Event.e_event);
      return output;
    }

    public Vx.Core.Map<string, Vx.Event.Type_event> vx_mapevent() {
      return vx_p_map;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      return this.vx_event(key);
    }

    public Vx.Core.Type_map vx_new_from_map(Vx.Core.Map<string, Vx.Core.Type_any> mapval) {
      Vx.Event.Class_eventmap output = new Vx.Event.Class_eventmap();
      Vx.Core.Type_msgblock msgblock = Vx.Core.e_msgblock;
      Vx.Core.Map<string, Vx.Event.Type_event> map = new Vx.Core.LinkedHashMap<string, Vx.Event.Type_event>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx.Core.Type_any val = mapval.get(key);
        if (false) {
        } else if (val is Vx.Event.Type_event castval) {
          map.put(key, castval);
        } else {
          Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_error("vx/event/eventmap", ":invalidvalue", val);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx.Core.immutablemap(map);
      if (msgblock != Vx.Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx.Event.Type_eventmap vx_new(params Object[] vals) {
      Vx.Event.Type_eventmap output = Vx.Core.vx_copy(Vx.Event.e_eventmap, vals);
      return output;
    }

    public override Vx.Event.Type_eventmap vx_copy(params Object[] vals) {
      Type_eventmap output = this;
      bool ischanged = false;
      Class_eventmap val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Map<string, Vx.Event.Type_event> mapval = new Vx.Core.LinkedHashMap<string, Vx.Event.Type_event>(val.vx_mapevent());
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
            msg = Vx.Core.vx_msg_from_error("vx/event/eventmap", ":keyexpected", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
        } else {
          Vx.Event.Type_event? valany = null;
          if (false) {
          } else if (valsub is Vx.Event.Type_event valallowed) {
            valany = valallowed;
          } else if (valsub is Vx.Event.Type_event) {
            valany = valsub as Vx.Event.Type_event;
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
            msg = Vx.Core.vx_msg_from_error("vx/event/eventmap", ":invalidkeyvalue", msgmap);
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
        Class_eventmap work = new Class_eventmap();
        work.vx_p_map = Vx.Core.immutablemap(mapval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_eventmap;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_eventmap;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/event", // pkgname
        "eventmap", // name
        ":map", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Event.t_event), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
      );
    }

  }

  public static Type_eventmap e_eventmap = new Class_eventmap();
  public static Type_eventmap t_eventmap = new Class_eventmap();

  /**
   * Constant: event-change
   * Change Event
   * {event}
   */
  public class Const_event_change : Vx.Event.Class_event, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/event", // pkgname
        "event-change", // name
        Vx.Core.typedef_new(
          "vx/event", // pkgname
          "event", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_event_change output) {
      Vx.Event.Type_event val = Vx.Core.f_new(
        Vx.Event.t_event,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("change")
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

  public static Const_event_change c_event_change = new Const_event_change();


  /**
   * Constant: event-click
   * Click Event
   * {event}
   */
  public class Const_event_click : Vx.Event.Class_event, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/event", // pkgname
        "event-click", // name
        Vx.Core.typedef_new(
          "vx/event", // pkgname
          "event", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_event_click output) {
      Vx.Event.Type_event val = Vx.Core.f_new(
        Vx.Event.t_event,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("click")
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

  public static Const_event_click c_event_click = new Const_event_click();


  /**
   * Constant: event-move
   * Move Event
   * {event}
   */
  public class Const_event_move : Vx.Event.Class_event, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/event", // pkgname
        "event-move", // name
        Vx.Core.typedef_new(
          "vx/event", // pkgname
          "event", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_event_move output) {
      Vx.Event.Type_event val = Vx.Core.f_new(
        Vx.Event.t_event,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("move")
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

  public static Const_event_move c_event_move = new Const_event_move();


  /**
   * Constant: event-select
   * Move Event
   * {event}
   */
  public class Const_event_select : Vx.Event.Class_event, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/event", // pkgname
        "event-select", // name
        Vx.Core.typedef_new(
          "vx/event", // pkgname
          "event", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_event_select output) {
      Vx.Event.Type_event val = Vx.Core.f_new(
        Vx.Event.t_event,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("move")
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

  public static Const_event_select c_event_select = new Const_event_select();

  /**
   * @function any_from_from_event
   * @param  {event} evt
   * @return {any-1}
   * (func any-from<-event)
   */
  public interface Func_any_from_from_event : Vx.Core.Func_any_from_any {
    public T vx_any_from_from_event<T>(T generic_any_1, Vx.Event.Type_event evt) where T : Vx.Core.Type_any;
  }

  public class Class_any_from_from_event : Vx.Core.Class_base, Func_any_from_from_event {

    public override Vx.Event.Func_any_from_from_event vx_new(params Object[] vals) {
      Class_any_from_from_event output = new Class_any_from_from_event();
      return output;
    }

    public override Vx.Event.Func_any_from_from_event vx_copy(params Object[] vals) {
      Class_any_from_from_event output = new Class_any_from_from_event();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/event", // pkgname
        "any-from<-event", // name
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
      return e_any_from_from_event;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_from_event;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Event.Type_event inputval = (Vx.Event.Type_event)value;
      Vx.Core.Type_any outputval = Vx.Event.f_any_from_from_event(Vx.Core.t_any, inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Event.Type_event evt = Vx.Core.f_any_from_any(Vx.Event.t_event, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Event.f_any_from_from_event(generic_any_1, evt);
      return output;
    }

    public T vx_any_from_from_event<T>(T generic_any_1, Vx.Event.Type_event evt) where T : Vx.Core.Type_any {
      return Vx.Event.f_any_from_from_event(generic_any_1, evt);
    }

  }

  public static Func_any_from_from_event e_any_from_from_event = new Vx.Event.Class_any_from_from_event();
  public static Func_any_from_from_event t_any_from_from_event = new Vx.Event.Class_any_from_from_event();

  public static T f_any_from_from_event<T>(T generic_any_1, Vx.Event.Type_event evt) where T : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
    output = Vx.Core.f_let(
      generic_any_1,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_any value = evt.from();
        Vx.Core.Type_any output_1 = Vx.Core.f_any_from_any(generic_any_1, value);
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
  public interface Func_event_from_event : Vx.Core.Func_any_from_any_context {
    public Vx.Event.Type_event vx_event_from_event(Vx.Core.Type_context context, Vx.Event.Type_event evt);
  }

  public class Class_event_from_event : Vx.Core.Class_base, Func_event_from_event {

    public override Vx.Event.Func_event_from_event vx_new(params Object[] vals) {
      Class_event_from_event output = new Class_event_from_event();
      return output;
    }

    public override Vx.Event.Func_event_from_event vx_copy(params Object[] vals) {
      Class_event_from_event output = new Class_event_from_event();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/event", // pkgname
        "event<-event", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/event", // pkgname
          "event", // name
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
      return e_event_from_event;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_event_from_event;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Event.Type_event inputval = (Vx.Event.Type_event)value;
      Vx.Core.Type_any outputval = Vx.Event.f_event_from_event(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Event.Type_event evt = Vx.Core.f_any_from_any(Vx.Event.t_event, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Event.f_event_from_event(context, evt);
      return output;
    }

    public Vx.Event.Type_event vx_event_from_event(Vx.Core.Type_context context, Vx.Event.Type_event evt) {
      return Vx.Event.f_event_from_event(context, evt);
    }

  }

  public static Func_event_from_event e_event_from_event = new Vx.Event.Class_event_from_event();
  public static Func_event_from_event t_event_from_event = new Vx.Event.Class_event_from_event();

  public static Vx.Event.Type_event f_event_from_event(Vx.Core.Type_context context, Vx.Event.Type_event evt) {
    Vx.Event.Type_event output = Vx.Event.e_event;
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
  public interface Func_event_from_event_async : Vx.Core.Func_any_from_any_context_async {
    public Task<Vx.Event.Type_event> vx_event_from_event_async(Vx.Core.Type_context context, Vx.Event.Type_event evt);
  }

  public class Class_event_from_event_async : Vx.Core.Class_base, Func_event_from_event_async {

    public override Vx.Event.Func_event_from_event_async vx_new(params Object[] vals) {
      Class_event_from_event_async output = new Class_event_from_event_async();
      return output;
    }

    public override Vx.Event.Func_event_from_event_async vx_copy(params Object[] vals) {
      Class_event_from_event_async output = new Class_event_from_event_async();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/event", // pkgname
        "event<-event-async", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/event", // pkgname
          "event", // name
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
      return e_event_from_event_async;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_event_from_event_async;
    }

    public Vx.Core.Func_any_from_any_context_async vx_fn_new(Vx.Core.Class_any_from_any_context_async.IFn fn) {
      return Vx.Core.e_any_from_any_context_async;
    }

    public Task<T> vx_any_from_any_context_async<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      Vx.Event.Type_event inputval = Vx.Core.f_any_from_any(Vx.Event.t_event, value);
      Task<Vx.Event.Type_event> future = Vx.Event.f_event_from_event_async(context, inputval);
      Task<T> output = Vx.Core.vx_async_from_async(generic_any_1, future);
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_completed(Vx.Core.e_any);
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Event.Type_event evt = Vx.Core.f_any_from_any(Vx.Event.t_event, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Task<Vx.Event.Type_event> future = Vx.Event.f_event_from_event_async(context, evt);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<Vx.Event.Type_event> vx_event_from_event_async(Vx.Core.Type_context context, Vx.Event.Type_event evt) {
      return Vx.Event.f_event_from_event_async(context, evt);
    }

  }

  public static Func_event_from_event_async e_event_from_event_async = new Vx.Event.Class_event_from_event_async();
  public static Func_event_from_event_async t_event_from_event_async = new Vx.Event.Class_event_from_event_async();

  public static Task<Vx.Event.Type_event> f_event_from_event_async(Vx.Core.Type_context context, Vx.Event.Type_event evt) {
    Task<Vx.Event.Type_event> output = Vx.Core.vx_async_new_completed(Vx.Event.e_event);
    return output;
  }

  /**
   * @function eventmap_from_eventlist
   * Returns an eventmap from an eventlist
   * @param  {eventlist} eventlist
   * @return {eventmap}
   * (func eventmap<-eventlist)
   */
  public interface Func_eventmap_from_eventlist : Vx.Core.Func_any_from_any {
    public Vx.Event.Type_eventmap vx_eventmap_from_eventlist(Vx.Event.Type_eventlist eventlist);
  }

  public class Class_eventmap_from_eventlist : Vx.Core.Class_base, Func_eventmap_from_eventlist {

    public override Vx.Event.Func_eventmap_from_eventlist vx_new(params Object[] vals) {
      Class_eventmap_from_eventlist output = new Class_eventmap_from_eventlist();
      return output;
    }

    public override Vx.Event.Func_eventmap_from_eventlist vx_copy(params Object[] vals) {
      Class_eventmap_from_eventlist output = new Class_eventmap_from_eventlist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/event", // pkgname
        "eventmap<-eventlist", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/event", // pkgname
          "eventmap", // name
          ":map", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Event.t_event), // allowtypes
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
      return e_eventmap_from_eventlist;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_eventmap_from_eventlist;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Event.Type_eventlist inputval = (Vx.Event.Type_eventlist)value;
      Vx.Core.Type_any outputval = Vx.Event.f_eventmap_from_eventlist(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Event.Type_eventlist eventlist = Vx.Core.f_any_from_any(Vx.Event.t_eventlist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Event.f_eventmap_from_eventlist(eventlist);
      return output;
    }

    public Vx.Event.Type_eventmap vx_eventmap_from_eventlist(Vx.Event.Type_eventlist eventlist) {
      return Vx.Event.f_eventmap_from_eventlist(eventlist);
    }

  }

  public static Func_eventmap_from_eventlist e_eventmap_from_eventlist = new Vx.Event.Class_eventmap_from_eventlist();
  public static Func_eventmap_from_eventlist t_eventmap_from_eventlist = new Vx.Event.Class_eventmap_from_eventlist();

  public static Vx.Event.Type_eventmap f_eventmap_from_eventlist(Vx.Event.Type_eventlist eventlist) {
    Vx.Event.Type_eventmap output = Vx.Event.e_eventmap;
    output = Vx.Core.f_map_from_list(
      Vx.Event.t_eventmap,
      eventlist,
      Vx.Core.t_any_from_any.vx_fn_new((evt_any) => {
        Vx.Event.Type_event evt = Vx.Core.f_any_from_any(Vx.Event.t_event, evt_any);
        Vx.Core.Type_any output_1 = 
          evt.name();
        return output_1;
      })
    );
    return output;
  }


  public static class PackageRunOnce {
    public static void RunOnce() {
    Const_event_change.const_new(c_event_change);
    Const_event_click.const_new(c_event_click);
    Const_event_move.const_new(c_event_move);
    Const_event_select.const_new(c_event_select);
    Vx.Core.Map<string, Vx.Core.Type_any> maptype = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_any> mapconst = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_func> mapfunc = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>();
    maptype.put("event", Vx.Event.t_event);
    maptype.put("eventlist", Vx.Event.t_eventlist);
    maptype.put("eventmap", Vx.Event.t_eventmap);
    mapconst.put("event-change", Vx.Event.c_event_change);
    mapconst.put("event-click", Vx.Event.c_event_click);
    mapconst.put("event-move", Vx.Event.c_event_move);
    mapconst.put("event-select", Vx.Event.c_event_select);
    mapfunc.put("any-from<-event", Vx.Event.t_any_from_from_event);
    mapfunc.put("event<-event", Vx.Event.t_event_from_event);
    mapfunc.put("event<-event-async", Vx.Event.t_event_from_event_async);
    mapfunc.put("eventmap<-eventlist", Vx.Event.t_eventmap_from_eventlist);
    Vx.Core.vx_global_package_set("vx/event", maptype, mapconst, mapfunc);
    }
  }

}
