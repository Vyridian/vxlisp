namespace Vx;

public static class Vx_event {


  /**
   * type: event
   * Generic Event
   * (type event)
   */
  public interface Type_event : Vx_core.Type_struct {
    public Vx_core.Type_any vx_new(params Object[] vals);
    public Vx_core.Type_any vx_copy(params Object[] vals);
    public Vx_core.Type_any vx_empty();
    public Vx_core.Type_any vx_type();
    public Vx_core.Type_string name();
    public Vx_core.Type_string from();
    public Vx_core.Type_string to();
    public Vx_core.Type_anymap datamap();
    public Vx_event.Func_event_from_event event_from_event();
    public Vx_event.Func_event_from_event_async event_from_event_async();
  }

  public class Class_event : Vx_core.Class_base, Type_event {

    public Vx_core.Type_string vx_p_name;

    public Vx_core.Type_string name() {
      Vx_core.Type_string output = Vx_core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx_core.Type_string vx_p_from;

    public Vx_core.Type_string from() {
      Vx_core.Type_string output = Vx_core.e_string;
      if (this.vx_p_from != null) {
        output = this.vx_p_from;
      }
      return output;
    }

    public Vx_core.Type_string vx_p_to;

    public Vx_core.Type_string to() {
      Vx_core.Type_string output = Vx_core.e_string;
      if (this.vx_p_to != null) {
        output = this.vx_p_to;
      }
      return output;
    }

    public Vx_core.Type_anymap vx_p_datamap;

    public Vx_core.Type_anymap datamap() {
      Vx_core.Type_anymap output = Vx_core.e_anymap;
      if (this.vx_p_datamap != null) {
        output = this.vx_p_datamap;
      }
      return output;
    }

    public Vx_event.Func_event_from_event vx_p_event_from_event;

    public Vx_event.Func_event_from_event event_from_event() {
      Vx_event.Func_event_from_event output = Vx_event.e_event_from_event;
      if (this.vx_p_event_from_event != null) {
        output = this.vx_p_event_from_event;
      }
      return output;
    }

    public Vx_event.Func_event_from_event_async vx_p_event_from_event_async;

    public Vx_event.Func_event_from_event_async event_from_event_async() {
      Vx_event.Func_event_from_event_async output = Vx_event.e_event_from_event_async;
      if (this.vx_p_event_from_event_async != null) {
        output = this.vx_p_event_from_event_async;
      }
      return output;
    }

    public Vx_core.Type_any vx_any(Vx_core.Type_string key) {
      Vx_core.Type_any output = Vx_core.e_any;
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

    public Vx_core.Map<string, Vx_core.Type_any> vx_map() {
      Vx_core.Map<string, Vx_core.Type_any> output = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
      output.put(":name", this.name());
      output.put(":from", this.from());
      output.put(":to", this.to());
      output.put(":datamap", this.datamap());
      output.put(":event<-event", this.event_from_event());
      output.put(":event<-event-async", this.event_from_event_async());
      return Vx_core.immutablemap(output);
    }

    public override Vx_event.Type_event vx_new(params Object[] vals) {
      return Vx_core.vx_copy(
       e_event,
       vals);
    }

    public override Vx_event.Type_event vx_copy(params Object[] vals) {
      Type_event output = this;
      bool ischanged = false;
      Class_event val = this;
      Vx_core.Type_msgblock msgblock = Vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx_core.vx_Type_const) {
        ischanged = true;
      }
      Vx_core.Type_string vx_p_name = val.name();
      Vx_core.Type_string vx_p_from = val.from();
      Vx_core.Type_string vx_p_to = val.to();
      Vx_core.Type_anymap vx_p_datamap = val.datamap();
      Vx_event.Func_event_from_event vx_p_event_from_event = val.event_from_event();
      Vx_event.Func_event_from_event_async vx_p_event_from_event_async = val.event_from_event_async();
      List<string> validkeys = new List<string>();
      validkeys.Add(":name");
      validkeys.Add(":from");
      validkeys.Add(":to");
      validkeys.Add(":datamap");
      validkeys.Add(":event<-event");
      validkeys.Add(":event<-event-async");
      string key = "";
      Vx_core.Type_msg msg;
      Vx_core.Type_any msgval;
      foreach (Object valsub in vals) {
        if (valsub is Vx_core.Type_msgblock) {
          msgblock = Vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx_core.Type_msg) {
          msgblock = Vx_core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (valsub is Vx_core.Type_string) {
            Vx_core.Type_string valstr = (Vx_core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx_core.Type_any) {
              msgval = (Vx_core.Type_any)valsub;
            } else {
              msgval = Vx_core.vx_new_string(valsub.ToString());
            }
            msg = Vx_core.vx_msg_from_error("vx/event/event", ":invalidkeytype", msgval);
            msgblock = Vx_core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.StartsWith(":")) {
              testkey = ":" + testkey;
            }
            bool isvalidkey = validkeys.Contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = Vx_core.vx_new_string(testkey);
              msg = Vx_core.vx_msg_from_error("vx/event/event", ":invalidkey", msgval);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub is Vx_core.Type_string) {
              ischanged = true;
              vx_p_name = (Vx_core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx_core.vx_new(Vx_core.t_string, valsub);
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("name"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":from":
            if (valsub == vx_p_from) {
            } else if (valsub is Vx_core.Type_string) {
              ischanged = true;
              vx_p_from = (Vx_core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_from = Vx_core.vx_new(Vx_core.t_string, valsub);
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("from"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":to":
            if (valsub == vx_p_to) {
            } else if (valsub is Vx_core.Type_string) {
              ischanged = true;
              vx_p_to = (Vx_core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_to = Vx_core.vx_new(Vx_core.t_string, valsub);
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("to"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":datamap":
            if (valsub == vx_p_datamap) {
            } else if (valsub is Vx_core.Type_anymap) {
              ischanged = true;
              vx_p_datamap = (Vx_core.Type_anymap)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("datamap"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":event<-event":
            if (valsub == vx_p_event_from_event) {
            } else if (valsub is Vx_event.Func_event_from_event) {
              ischanged = true;
              vx_p_event_from_event = (Vx_event.Func_event_from_event)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("event<-event"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":event<-event-async":
            if (valsub == vx_p_event_from_event_async) {
            } else if (valsub is Vx_event.Func_event_from_event_async) {
              ischanged = true;
              vx_p_event_from_event_async = (Vx_event.Func_event_from_event_async)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("event<-event-async"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/event/event", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx_core.vx_new_string(key);
            msg = Vx_core.vx_msg_from_error("vx/event/event", ":invalidkey", msgval);
            msgblock = Vx_core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx_core.e_msgblock)) {
        Class_event work = new Class_event();
        work.vx_p_name = vx_p_name;
        work.vx_p_from = vx_p_from;
        work.vx_p_to = vx_p_to;
        work.vx_p_datamap = vx_p_datamap;
        work.vx_p_event_from_event = vx_p_event_from_event;
        work.vx_p_event_from_event_async = vx_p_event_from_event_async;
        if (msgblock != Vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx_core.Type_any vx_empty() {
      return e_event;
    }
    public override Vx_core.Type_any vx_type() {
      return t_event;
    }

    public override Vx_core.Type_typedef vx_typedef() {
      return Vx_core.typedef_new(
        "vx/event", // pkgname
        "event", // name
        ":struct", // extends
        Vx_core.e_typelist, // traits
        Vx_core.e_typelist, // allowtypes
        Vx_core.e_typelist, // disallowtypes
        Vx_core.e_funclist, // allowfuncs
        Vx_core.e_funclist, // disallowfuncs
        Vx_core.e_anylist, // allowvalues
        Vx_core.e_anylist, // disallowvalues
        Vx_core.e_argmap // properties
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
  public interface Type_eventlist : Vx_core.Type_list {
    public Vx_core.Type_any vx_new(params Object[] vals);
    public Vx_core.Type_any vx_copy(params Object[] vals);
    public Vx_core.Type_any vx_empty();
    public Vx_core.Type_any vx_type();
    public List<Vx_event.Type_event> vx_listevent();
    public Vx_event.Type_event vx_event(Vx_core.Type_int index);
  }

  public class Class_eventlist : Vx_core.Class_base, Type_eventlist {

    public List<Vx_event.Type_event> vx_p_list = Vx_core.immutablelist(new List<Vx_event.Type_event>());

    public List<Vx_core.Type_any> vx_list() {
      List<Vx_core.Type_any> output = Vx_core.immutablelist(
        new List<Vx_core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx_event.Type_event vx_event(Vx_core.Type_int index) {
      Vx_event.Type_event output = Vx_event.e_event;
      Vx_event.Class_eventlist list = this;
      int iindex = index.vx_int();
      List<Vx_event.Type_event> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx_event.Type_event> vx_listevent() {
      return vx_p_list;
    }

    public Vx_core.Type_any vx_any(Vx_core.Type_int index) {
      return this.vx_event(index);
    }

    public override Vx_event.Type_eventlist vx_new(params Object[] vals) {
      return Vx_core.vx_copy(
       e_eventlist,
       vals);
    }

    public override Vx_event.Type_eventlist vx_copy(params Object[] vals) {
      Type_eventlist output = this;
      bool ischanged = false;
      Class_eventlist val = this;
      Vx_core.Type_msgblock msgblock = Vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx_core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx_event.Type_event> listval = new List<Vx_event.Type_event>(val.vx_listevent());
      Vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx_core.Type_msgblock) {
          msgblock = Vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx_core.Type_msg) {
          msgblock = Vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx_event.Type_event) {
          Vx_event.Type_event anysub = valsub as Vx_event.Type_event;
          ischanged = true;
          listval.Add(anysub);
        } else if (valsub is Vx_event.Type_event) {
          ischanged = true;
          listval.Add((Vx_event.Type_event)valsub);
        } else if (valsub is Vx_event.Type_eventlist) {
          Type_eventlist multi = (Type_eventlist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_listevent());
        } else if (valsub is List<object>) {
          List<object> listunknown = valsub as List<object>;
          foreach (Object item in listunknown) {
            if (item is Vx_event.Type_event) {
              Vx_event.Type_event valitem = (Vx_event.Type_event)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx_core.Type_any) {
          Vx_core.Type_any anysub = valsub as Vx_core.Type_any;
          msg = Vx_core.vx_msg_from_error("vx/event/eventlist", ":invalidtype", anysub);
          msgblock = Vx_core.vx_copy(msgblock, msg);
        } else {
          msg = Vx_core.vx_msg_from_error("vx/event/eventlist", ":invalidtype", Vx_core.vx_new_string(valsub.ToString()));
          msgblock = Vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx_core.e_msgblock)) {
        Class_eventlist work = new Class_eventlist();
        work.vx_p_list = Vx_core.immutablelist(listval);
        if (msgblock != Vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx_core.Type_any vx_empty() {
      return e_eventlist;
    }
    public override Vx_core.Type_any vx_type() {
      return t_eventlist;
    }

    public override Vx_core.Type_typedef vx_typedef() {
      return Vx_core.typedef_new(
        "vx/event", // pkgname
        "eventlist", // name
        ":list", // extends
        Vx_core.e_typelist, // traits
        Vx_core.vx_new(Vx_core.t_typelist, Vx_event.t_event), // allowtypes
        Vx_core.e_typelist, // disallowtypes
        Vx_core.e_funclist, // allowfuncs
        Vx_core.e_funclist, // disallowfuncs
        Vx_core.e_anylist, // allowvalues
        Vx_core.e_anylist, // disallowvalues
        Vx_core.e_argmap // properties
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
  public interface Type_eventmap : Vx_core.Type_map {
    public Vx_core.Type_any vx_new(params Object[] vals);
    public Vx_core.Type_any vx_copy(params Object[] vals);
    public Vx_core.Type_any vx_empty();
    public Vx_core.Type_any vx_type();
    public Vx_core.Map<string, Vx_event.Type_event> vx_mapevent();
    public Vx_event.Type_event vx_event(Vx_core.Type_string key);
  }

  public class Class_eventmap : Vx_core.Class_base, Type_eventmap {

    public Vx_core.Map<string, Vx_event.Type_event> vx_p_map = Vx_core.immutablemap(new Vx_core.LinkedHashMap<string, Vx_event.Type_event>());

    public Vx_core.Map<string, Vx_core.Type_any> vx_map() {
      Vx_core.Map<string, Vx_core.Type_any> anymap = (Vx_core.Map<string, Vx_core.Type_any>)this.vx_p_map;
      Vx_core.Map<string, Vx_core.Type_any> map = anymap.copy();
      return Vx_core.immutablemap(map);
    }

    public Vx_core.Type_boolean vx_set(Vx_core.Type_string name, Vx_core.Type_any value) {
      Vx_core.Type_boolean output = Vx_core.c_false;
      if (value is Vx_event.Type_event) {
        string key = name.vx_string();
        if (key.StartsWith(":")) {
          key = key.Substring(1);
        }
        Vx_event.Type_event castval = (Vx_event.Type_event)value;
        Vx_core.Map<string, Vx_event.Type_event> map = new Vx_core.LinkedHashMap<string, Vx_event.Type_event>(this.vx_p_map);
        if (castval == Vx_event.e_event) {
          map.remove(key);
        } else {
          map.put(key, castval);
        }
        this.vx_p_map = Vx_core.immutablemap(map);
        output = Vx_core.c_true;
      }
      return output;
    }

    public Vx_event.Type_event vx_event(Vx_core.Type_string key) {
      Vx_event.Type_event output = Vx_event.e_event;
      Vx_event.Class_eventmap map = this;
      string skey = key.vx_string();
      Vx_core.Map<string, Vx_event.Type_event> mapval = map.vx_p_map;
      output = mapval.getOrDefault(skey, Vx_event.e_event);
      return output;
    }

    public Vx_core.Map<string, Vx_event.Type_event> vx_mapevent() {
      return vx_p_map;
    }

    public Vx_core.Type_any vx_any(Vx_core.Type_string key) {
      return this.vx_event(key);
    }

    public Vx_core.Type_map vx_new_from_map(Vx_core.Map<string, Vx_core.Type_any> mapval) {
      Vx_event.Class_eventmap output = new Vx_event.Class_eventmap();
      Vx_core.Type_msgblock msgblock = Vx_core.e_msgblock;
      Vx_core.Map<string, Vx_event.Type_event> map = new Vx_core.LinkedHashMap<string, Vx_event.Type_event>();
      List<string> keys = mapval.keys();
      foreach (string key in keys) {
        Vx_core.Type_any val = mapval.get(key);
        if (val is Vx_event.Type_event) {
          Vx_event.Type_event castval = (Vx_event.Type_event)val;
          map.put(key, castval);
        } else {
          Vx_core.Type_msg msg = Vx_core.vx_msg_from_error("vx/event/eventmap", ":invalidvalue", val);
          msgblock = Vx_core.vx_copy(msgblock, msg);
        }
      }
      output.vx_p_map = Vx_core.immutablemap(map);
      if (msgblock != Vx_core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    public override Vx_event.Type_eventmap vx_new(params Object[] vals) {
      return Vx_core.vx_copy(
       e_eventmap,
       vals);
    }

    public override Vx_event.Type_eventmap vx_copy(params Object[] vals) {
      Type_eventmap output = this;
      bool ischanged = false;
      Class_eventmap val = this;
      Vx_core.Type_msgblock msgblock = Vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx_core.vx_Type_const) {
        ischanged = true;
      }
      Vx_core.Map<string, Vx_event.Type_event> mapval = new Vx_core.LinkedHashMap<string, Vx_event.Type_event>(val.vx_mapevent());
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
            msg = Vx_core.vx_msg_from_error("vx/event/eventmap", ":keyexpected", msgval);
            msgblock = Vx_core.vx_copy(msgblock, msg);
          }
        } else {
          Vx_event.Type_event valany = null;
          if (valsub is Vx_event.Type_event) {
            valany = (Vx_event.Type_event)valsub;
          } else if (valsub is Vx_event.Type_event) {
            valany = valsub as Vx_event.Type_event;
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
            msg = Vx_core.vx_msg_from_error("vx/event/eventmap", ":invalidkeyvalue", msgmap);
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
        Class_eventmap work = new Class_eventmap();
        work.vx_p_map = Vx_core.immutablemap(mapval);
        if (msgblock != Vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx_core.Type_any vx_empty() {
      return e_eventmap;
    }
    public override Vx_core.Type_any vx_type() {
      return t_eventmap;
    }

    public override Vx_core.Type_typedef vx_typedef() {
      return Vx_core.typedef_new(
        "vx/event", // pkgname
        "eventmap", // name
        ":map", // extends
        Vx_core.e_typelist, // traits
        Vx_core.vx_new(Vx_core.t_typelist, Vx_event.t_event), // allowtypes
        Vx_core.e_typelist, // disallowtypes
        Vx_core.e_funclist, // allowfuncs
        Vx_core.e_funclist, // disallowfuncs
        Vx_core.e_anylist, // allowvalues
        Vx_core.e_anylist, // disallowvalues
        Vx_core.e_argmap // properties
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
  public class Const_event_change : Vx_event.Class_event, Vx_core.vx_Type_const {
    
    public Vx_core.Type_constdef vx_constdef() {
      return Vx_core.constdef_new(
        "vx/event", // pkgname
        "event-change", // name
        Vx_core.typedef_new(
          "vx/event", // pkgname
          "event", // name
          ":struct", // extends
          Vx_core.e_typelist, // traits
          Vx_core.e_typelist, // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_event_change output) {
      Vx_event.Type_event val = Vx_core.f_new(
        Vx_event.t_event,
        Vx_core.vx_new(Vx_core.t_anylist,
                Vx_core.vx_new_string(":name"),
                Vx_core.vx_new_string("change")
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
  public class Const_event_click : Vx_event.Class_event, Vx_core.vx_Type_const {
    
    public Vx_core.Type_constdef vx_constdef() {
      return Vx_core.constdef_new(
        "vx/event", // pkgname
        "event-click", // name
        Vx_core.typedef_new(
          "vx/event", // pkgname
          "event", // name
          ":struct", // extends
          Vx_core.e_typelist, // traits
          Vx_core.e_typelist, // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_event_click output) {
      Vx_event.Type_event val = Vx_core.f_new(
        Vx_event.t_event,
        Vx_core.vx_new(Vx_core.t_anylist,
                Vx_core.vx_new_string(":name"),
                Vx_core.vx_new_string("click")
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
  public class Const_event_move : Vx_event.Class_event, Vx_core.vx_Type_const {
    
    public Vx_core.Type_constdef vx_constdef() {
      return Vx_core.constdef_new(
        "vx/event", // pkgname
        "event-move", // name
        Vx_core.typedef_new(
          "vx/event", // pkgname
          "event", // name
          ":struct", // extends
          Vx_core.e_typelist, // traits
          Vx_core.e_typelist, // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_event_move output) {
      Vx_event.Type_event val = Vx_core.f_new(
        Vx_event.t_event,
        Vx_core.vx_new(Vx_core.t_anylist,
                Vx_core.vx_new_string(":name"),
                Vx_core.vx_new_string("move")
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
  public class Const_event_select : Vx_event.Class_event, Vx_core.vx_Type_const {
    
    public Vx_core.Type_constdef vx_constdef() {
      return Vx_core.constdef_new(
        "vx/event", // pkgname
        "event-select", // name
        Vx_core.typedef_new(
          "vx/event", // pkgname
          "event", // name
          ":struct", // extends
          Vx_core.e_typelist, // traits
          Vx_core.e_typelist, // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_event_select output) {
      Vx_event.Type_event val = Vx_core.f_new(
        Vx_event.t_event,
        Vx_core.vx_new(Vx_core.t_anylist,
                Vx_core.vx_new_string(":name"),
                Vx_core.vx_new_string("move")
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
  public interface Func_any_from_from_event : Vx_core.Func_any_from_any {
    public T vx_any_from_from_event<T>(T generic_any_1, Vx_event.Type_event evt) where T : Vx_core.Type_any;
  }

  public class Class_any_from_from_event : Vx_core.Class_base, Func_any_from_from_event {

    public override Vx_event.Func_any_from_from_event vx_new(params Object[] vals) {
      Class_any_from_from_event output = new Class_any_from_from_event();
      return output;
    }

    public override Vx_event.Func_any_from_from_event vx_copy(params Object[] vals) {
      Class_any_from_from_event output = new Class_any_from_from_event();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/event", // pkgname
        "any-from<-event", // name
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
      return e_any_from_from_event;
    }

    public override Vx_core.Type_any vx_type() {
      return t_any_from_from_event;
    }

    public Vx_core.Func_any_from_any vx_fn_new(Vx_core.Class_any_from_any.IFn fn) {
      return Vx_core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_event.Type_event inputval = (Vx_event.Type_event)value;
      Vx_core.Type_any outputval = Vx_event.f_any_from_from_event(Vx_core.t_any, inputval);
      output = Vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_any generic_any_1 = Vx_core.f_any_from_any(Vx_core.t_any, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_event.Type_event evt = Vx_core.f_any_from_any(Vx_event.t_event, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_event.f_any_from_from_event(generic_any_1, evt);
      return output;
    }

    public T vx_any_from_from_event<T>(T generic_any_1, Vx_event.Type_event evt) where T : Vx_core.Type_any {
      return Vx_event.f_any_from_from_event(generic_any_1, evt);
    }

  }

  public static Func_any_from_from_event e_any_from_from_event = new Vx_event.Class_any_from_from_event();
  public static Func_any_from_from_event t_any_from_from_event = new Vx_event.Class_any_from_from_event();

  public static T f_any_from_from_event<T>(T generic_any_1, Vx_event.Type_event evt) where T : Vx_core.Type_any {
    T output = Vx_core.f_empty(generic_any_1);
    output = Vx_core.f_let(
      generic_any_1,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_core.Type_any value = evt.from();
        return Vx_core.f_any_from_any(generic_any_1, value);
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
  public interface Func_event_from_event : Vx_core.Func_any_from_any_context {
    public Vx_event.Type_event vx_event_from_event(Vx_core.Type_context context, Vx_event.Type_event evt);
  }

  public class Class_event_from_event : Vx_core.Class_base, Func_event_from_event {

    public override Vx_event.Func_event_from_event vx_new(params Object[] vals) {
      Class_event_from_event output = new Class_event_from_event();
      return output;
    }

    public override Vx_event.Func_event_from_event vx_copy(params Object[] vals) {
      Class_event_from_event output = new Class_event_from_event();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/event", // pkgname
        "event<-event", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/event", // pkgname
          "event", // name
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
      return e_event_from_event;
    }

    public override Vx_core.Type_any vx_type() {
      return t_event_from_event;
    }

    public Vx_core.Func_any_from_any_context vx_fn_new(Vx_core.Class_any_from_any_context.IFn fn) {
      return Vx_core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx_core.Type_context context, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_event.Type_event inputval = (Vx_event.Type_event)value;
      Vx_core.Type_any outputval = Vx_event.f_event_from_event(context, inputval);
      output = Vx_core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_event.Type_event evt = Vx_core.f_any_from_any(Vx_event.t_event, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_event.f_event_from_event(context, evt);
      return output;
    }

    public Vx_event.Type_event vx_event_from_event(Vx_core.Type_context context, Vx_event.Type_event evt) {
      return Vx_event.f_event_from_event(context, evt);
    }

  }

  public static Func_event_from_event e_event_from_event = new Vx_event.Class_event_from_event();
  public static Func_event_from_event t_event_from_event = new Vx_event.Class_event_from_event();

  public static Vx_event.Type_event f_event_from_event(Vx_core.Type_context context, Vx_event.Type_event evt) {
    Vx_event.Type_event output = Vx_event.e_event;
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
  public interface Func_event_from_event_async : Vx_core.Func_any_from_any_context_async {
    public Task<Vx_event.Type_event> vx_event_from_event_async(Vx_core.Type_context context, Vx_event.Type_event evt);
  }

  public class Class_event_from_event_async : Vx_core.Class_base, Func_event_from_event_async {

    public override Vx_event.Func_event_from_event_async vx_new(params Object[] vals) {
      Class_event_from_event_async output = new Class_event_from_event_async();
      return output;
    }

    public override Vx_event.Func_event_from_event_async vx_copy(params Object[] vals) {
      Class_event_from_event_async output = new Class_event_from_event_async();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/event", // pkgname
        "event<-event-async", // name
        0, // idx
        true, // async
        Vx_core.typedef_new(
          "vx/event", // pkgname
          "event", // name
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
      return e_event_from_event_async;
    }

    public override Vx_core.Type_any vx_type() {
      return t_event_from_event_async;
    }

    public Vx_core.Func_any_from_any_context_async vx_fn_new(Vx_core.Class_any_from_any_context_async.IFn fn) {
      return Vx_core.e_any_from_any_context_async;
    }

    public Task<T> vx_any_from_any_context_async<T, U>(T generic_any_1, Vx_core.Type_context context, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      Vx_event.Type_event inputval = Vx_core.f_any_from_any(Vx_event.t_event, value);
      Task<Vx_event.Type_event> future = Vx_event.f_event_from_event_async(context, inputval);
      Task<T> output = (Task<T>)future;
      return output;
    }

    public Task<Vx_core.Type_any> vx_repl(Vx_core.Type_anylist arglist) {
      Task<Vx_core.Type_any> output = Vx_core.vx_async_new_completed(Vx_core.e_any);
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_event.Type_event evt = Vx_core.f_any_from_any(Vx_event.t_event, arglist.vx_any(Vx_core.vx_new_int(0)));
      Task<Vx_event.Type_event> future = Vx_event.f_event_from_event_async(context, evt);
      output = Vx_core.vx_async_from_async(Vx_core.t_any, future);
      return output;
    }

    public Task<Vx_event.Type_event> vx_event_from_event_async(Vx_core.Type_context context, Vx_event.Type_event evt) {
      return Vx_event.f_event_from_event_async(context, evt);
    }

  }

  public static Func_event_from_event_async e_event_from_event_async = new Vx_event.Class_event_from_event_async();
  public static Func_event_from_event_async t_event_from_event_async = new Vx_event.Class_event_from_event_async();

  public static Task<Vx_event.Type_event> f_event_from_event_async(Vx_core.Type_context context, Vx_event.Type_event evt) {
    Task<Vx_event.Type_event> output = Vx_core.vx_async_new_completed(Vx_event.e_event);
    return output;
  }

  /**
   * @function eventmap_from_eventlist
   * Returns an eventmap from an eventlist
   * @param  {eventlist} eventlist
   * @return {eventmap}
   * (func eventmap<-eventlist)
   */
  public interface Func_eventmap_from_eventlist : Vx_core.Func_any_from_any {
    public Vx_event.Type_eventmap vx_eventmap_from_eventlist(Vx_event.Type_eventlist eventlist);
  }

  public class Class_eventmap_from_eventlist : Vx_core.Class_base, Func_eventmap_from_eventlist {

    public override Vx_event.Func_eventmap_from_eventlist vx_new(params Object[] vals) {
      Class_eventmap_from_eventlist output = new Class_eventmap_from_eventlist();
      return output;
    }

    public override Vx_event.Func_eventmap_from_eventlist vx_copy(params Object[] vals) {
      Class_eventmap_from_eventlist output = new Class_eventmap_from_eventlist();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/event", // pkgname
        "eventmap<-eventlist", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/event", // pkgname
          "eventmap", // name
          ":map", // extends
          Vx_core.e_typelist, // traits
          Vx_core.vx_new(Vx_core.t_typelist, Vx_event.t_event), // allowtypes
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
      return e_eventmap_from_eventlist;
    }

    public override Vx_core.Type_any vx_type() {
      return t_eventmap_from_eventlist;
    }

    public Vx_core.Func_any_from_any vx_fn_new(Vx_core.Class_any_from_any.IFn fn) {
      return Vx_core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_event.Type_eventlist inputval = (Vx_event.Type_eventlist)value;
      Vx_core.Type_any outputval = Vx_event.f_eventmap_from_eventlist(inputval);
      output = Vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_event.Type_eventlist eventlist = Vx_core.f_any_from_any(Vx_event.t_eventlist, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_event.f_eventmap_from_eventlist(eventlist);
      return output;
    }

    public Vx_event.Type_eventmap vx_eventmap_from_eventlist(Vx_event.Type_eventlist eventlist) {
      return Vx_event.f_eventmap_from_eventlist(eventlist);
    }

  }

  public static Func_eventmap_from_eventlist e_eventmap_from_eventlist = new Vx_event.Class_eventmap_from_eventlist();
  public static Func_eventmap_from_eventlist t_eventmap_from_eventlist = new Vx_event.Class_eventmap_from_eventlist();

  public static Vx_event.Type_eventmap f_eventmap_from_eventlist(Vx_event.Type_eventlist eventlist) {
    Vx_event.Type_eventmap output = Vx_event.e_eventmap;
    output = Vx_core.f_map_from_list(
      Vx_event.t_eventmap,
      eventlist,
      Vx_core.t_any_from_any.vx_fn_new((evt_any) => {
        Vx_event.Type_event evt = Vx_core.f_any_from_any(Vx_event.t_event, evt_any);
        return 
        evt.name();
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
    Vx_core.Map<string, Vx_core.Type_any> maptype = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
    Vx_core.Map<string, Vx_core.Type_any> mapconst = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
    Vx_core.Map<string, Vx_core.Type_func> mapfunc = new Vx_core.LinkedHashMap<string, Vx_core.Type_func>();
    maptype.put("event", Vx_event.t_event);
    maptype.put("eventlist", Vx_event.t_eventlist);
    maptype.put("eventmap", Vx_event.t_eventmap);
    mapconst.put("event-change", Vx_event.c_event_change);
    mapconst.put("event-click", Vx_event.c_event_click);
    mapconst.put("event-move", Vx_event.c_event_move);
    mapconst.put("event-select", Vx_event.c_event_select);
    mapfunc.put("any-from<-event", Vx_event.t_any_from_from_event);
    mapfunc.put("event<-event", Vx_event.t_event_from_event);
    mapfunc.put("event<-event-async", Vx_event.t_event_from_event_async);
    mapfunc.put("eventmap<-eventlist", Vx_event.t_eventmap_from_eventlist);
    Vx_core.vx_global_package_set("vx/event", maptype, mapconst, mapfunc);
    }
  }

}
