namespace Vx;

using Vx;

public static class Vx_repl {


  /**
   * type: liblist
   * List of library names
   * (type liblist)
   */
  public interface Type_liblist : Vx_core.Type_list {
    public Vx_core.Type_any vx_new(params Object[] vals);
    public Vx_core.Type_any vx_copy(params Object[] vals);
    public Vx_core.Type_any vx_empty();
    public Vx_core.Type_any vx_type();
    public List<Vx_core.Type_string> vx_liststring();
    public Vx_core.Type_string vx_string(Vx_core.Type_int index);
  }

  public class Class_liblist : Vx_core.Class_base, Type_liblist {

    public List<Vx_core.Type_string> vx_p_list = Vx_core.immutablelist(new List<Vx_core.Type_string>());

    public List<Vx_core.Type_any> vx_list() {
      List<Vx_core.Type_any> output = Vx_core.immutablelist(
        new List<Vx_core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx_core.Type_string vx_string(Vx_core.Type_int index) {
      Vx_core.Type_string output = Vx_core.e_string;
      Vx_repl.Class_liblist list = this;
      int iindex = index.vx_int();
      List<Vx_core.Type_string> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx_core.Type_string> vx_liststring() {
      return vx_p_list;
    }

    public Vx_core.Type_any vx_any(Vx_core.Type_int index) {
      return this.vx_string(index);
    }

    public override Vx_repl.Type_liblist vx_new(params Object[] vals) {
      return Vx_core.vx_copy(
       e_liblist,
       vals);
    }

    public override Vx_repl.Type_liblist vx_copy(params Object[] vals) {
      Type_liblist output = this;
      bool ischanged = false;
      Class_liblist val = this;
      Vx_core.Type_msgblock msgblock = Vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx_core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx_core.Type_string> listval = new List<Vx_core.Type_string>(val.vx_liststring());
      Vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx_core.Type_msgblock) {
          msgblock = Vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx_core.Type_msg) {
          msgblock = Vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx_core.Type_string) {
          Vx_core.Type_string anysub = valsub as Vx_core.Type_string;
          ischanged = true;
          listval.Add(anysub);
        } else if (valsub is Vx_core.Type_string) {
          ischanged = true;
          listval.Add(Vx_core.vx_new(Vx_core.t_string, valsub));
        } else if (valsub is Vx_repl.Type_liblist) {
          Type_liblist multi = (Type_liblist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_liststring());
        } else if (valsub is List<object>) {
          List<object> listunknown = valsub as List<object>;
          foreach (Object item in listunknown) {
            if (item is Vx_core.Type_string) {
              Vx_core.Type_string valitem = (Vx_core.Type_string)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx_core.Type_any) {
          Vx_core.Type_any anysub = valsub as Vx_core.Type_any;
          msg = Vx_core.vx_msg_from_error("vx/repl/liblist", ":invalidtype", anysub);
          msgblock = Vx_core.vx_copy(msgblock, msg);
        } else {
          msg = Vx_core.vx_msg_from_error("vx/repl/liblist", ":invalidtype", Vx_core.vx_new_string(valsub.ToString()));
          msgblock = Vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx_core.e_msgblock)) {
        Class_liblist work = new Class_liblist();
        work.vx_p_list = Vx_core.immutablelist(listval);
        if (msgblock != Vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx_core.Type_any vx_empty() {
      return e_liblist;
    }
    public override Vx_core.Type_any vx_type() {
      return t_liblist;
    }

    public override Vx_core.Type_typedef vx_typedef() {
      return Vx_core.typedef_new(
        "vx/repl", // pkgname
        "liblist", // name
        ":list", // extends
        Vx_core.e_typelist, // traits
        Vx_core.vx_new(Vx_core.t_typelist, Vx_core.t_string), // allowtypes
        Vx_core.e_typelist, // disallowtypes
        Vx_core.e_funclist, // allowfuncs
        Vx_core.e_funclist, // disallowfuncs
        Vx_core.e_anylist, // allowvalues
        Vx_core.e_anylist, // disallowvalues
        Vx_core.e_argmap // properties
      );
    }

  }

  public static Type_liblist e_liblist = new Class_liblist();
  public static Type_liblist t_liblist = new Class_liblist();

  /**
   * type: repl
   * Repl structure
   * (type repl)
   */
  public interface Type_repl : Vx_core.Type_struct {
    public Vx_core.Type_any vx_new(params Object[] vals);
    public Vx_core.Type_any vx_copy(params Object[] vals);
    public Vx_core.Type_any vx_empty();
    public Vx_core.Type_any vx_type();
    public Vx_core.Type_string name();
    public Vx_core.Type_any type();
    public Vx_repl.Type_repllist repllist();
    public Vx_core.Type_boolean async();
    public Vx_core.Type_any val();
    public Vx_core.Type_string doc();
  }

  public class Class_repl : Vx_core.Class_base, Type_repl {

    public Vx_core.Type_string vx_p_name;

    public Vx_core.Type_string name() {
      Vx_core.Type_string output = Vx_core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx_core.Type_any vx_p_type;

    public Vx_core.Type_any type() {
      Vx_core.Type_any output = Vx_core.e_any;
      if (this.vx_p_type != null) {
        output = this.vx_p_type;
      }
      return output;
    }

    public Vx_repl.Type_repllist vx_p_repllist;

    public Vx_repl.Type_repllist repllist() {
      Vx_repl.Type_repllist output = Vx_repl.e_repllist;
      if (this.vx_p_repllist != null) {
        output = this.vx_p_repllist;
      }
      return output;
    }

    public Vx_core.Type_boolean vx_p_async;

    public Vx_core.Type_boolean async() {
      Vx_core.Type_boolean output = Vx_core.e_boolean;
      if (this.vx_p_async != null) {
        output = this.vx_p_async;
      }
      return output;
    }

    public Vx_core.Type_any vx_p_val;

    public Vx_core.Type_any val() {
      Vx_core.Type_any output = Vx_core.e_any;
      if (this.vx_p_val != null) {
        output = this.vx_p_val;
      }
      return output;
    }

    public Vx_core.Type_string vx_p_doc;

    public Vx_core.Type_string doc() {
      Vx_core.Type_string output = Vx_core.e_string;
      if (this.vx_p_doc != null) {
        output = this.vx_p_doc;
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
      case ":type":
        output = this.type();
        break;
      case ":repllist":
        output = this.repllist();
        break;
      case ":async":
        output = this.async();
        break;
      case ":val":
        output = this.val();
        break;
      case ":doc":
        output = this.doc();
        break;
      }
      return output;
    }

    public Vx_core.Map<string, Vx_core.Type_any> vx_map() {
      Vx_core.Map<string, Vx_core.Type_any> output = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
      output.put(":name", this.name());
      output.put(":type", this.type());
      output.put(":repllist", this.repllist());
      output.put(":async", this.async());
      output.put(":val", this.val());
      output.put(":doc", this.doc());
      return Vx_core.immutablemap(output);
    }

    public override Vx_repl.Type_repl vx_new(params Object[] vals) {
      return Vx_core.vx_copy(
       e_repl,
       vals);
    }

    public override Vx_repl.Type_repl vx_copy(params Object[] vals) {
      Type_repl output = this;
      bool ischanged = false;
      Class_repl val = this;
      Vx_core.Type_msgblock msgblock = Vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx_core.vx_Type_const) {
        ischanged = true;
      }
      Vx_core.Type_string vx_p_name = val.name();
      Vx_core.Type_any vx_p_type = val.type();
      Vx_repl.Type_repllist vx_p_repllist = val.repllist();
      Vx_core.Type_boolean vx_p_async = val.async();
      Vx_core.Type_any vx_p_val = val.val();
      Vx_core.Type_string vx_p_doc = val.doc();
      List<string> validkeys = new List<string>();
      validkeys.Add(":name");
      validkeys.Add(":type");
      validkeys.Add(":repllist");
      validkeys.Add(":async");
      validkeys.Add(":val");
      validkeys.Add(":doc");
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
            msg = Vx_core.vx_msg_from_error("vx/repl/repl", ":invalidkeytype", msgval);
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
              msg = Vx_core.vx_msg_from_error("vx/repl/repl", ":invalidkey", msgval);
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
              msg = Vx_core.vx_msg_from_error("vx/repl/repl", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":type":
            if (valsub == vx_p_type) {
            } else if (valsub is Vx_core.Type_any) {
              ischanged = true;
              vx_p_type = (Vx_core.Type_any)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("type"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/repl/repl", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":repllist":
            if (valsub == vx_p_repllist) {
            } else if (valsub is Vx_repl.Type_repllist) {
              ischanged = true;
              vx_p_repllist = (Vx_repl.Type_repllist)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("repllist"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/repl/repl", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":async":
            if (valsub == vx_p_async) {
            } else if (valsub is Vx_core.Type_boolean) {
              ischanged = true;
              vx_p_async = (Vx_core.Type_boolean)valsub;
            } else if (valsub is bool) {
              ischanged = true;
              vx_p_async = Vx_core.vx_new(Vx_core.t_boolean, valsub);
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("async"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/repl/repl", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":val":
            if (valsub == vx_p_val) {
            } else if (valsub is Vx_core.Type_any) {
              ischanged = true;
              vx_p_val = (Vx_core.Type_any)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("val"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/repl/repl", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":doc":
            if (valsub == vx_p_doc) {
            } else if (valsub is Vx_core.Type_string) {
              ischanged = true;
              vx_p_doc = (Vx_core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_doc = Vx_core.vx_new(Vx_core.t_string, valsub);
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("doc"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/repl/repl", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx_core.vx_new_string(key);
            msg = Vx_core.vx_msg_from_error("vx/repl/repl", ":invalidkey", msgval);
            msgblock = Vx_core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx_core.e_msgblock)) {
        Class_repl work = new Class_repl();
        work.vx_p_name = vx_p_name;
        work.vx_p_type = vx_p_type;
        work.vx_p_repllist = vx_p_repllist;
        work.vx_p_async = vx_p_async;
        work.vx_p_val = vx_p_val;
        work.vx_p_doc = vx_p_doc;
        if (msgblock != Vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx_core.Type_any vx_empty() {
      return e_repl;
    }
    public override Vx_core.Type_any vx_type() {
      return t_repl;
    }

    public override Vx_core.Type_typedef vx_typedef() {
      return Vx_core.typedef_new(
        "vx/repl", // pkgname
        "repl", // name
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

  public static Type_repl e_repl = new Class_repl();
  public static Type_repl t_repl = new Class_repl();

  /**
   * type: replarglist
   * Builder for a repllist
   * (type replarglist)
   */
  public interface Type_replarglist : Vx_core.Type_struct {
    public Vx_core.Type_any vx_new(params Object[] vals);
    public Vx_core.Type_any vx_copy(params Object[] vals);
    public Vx_core.Type_any vx_empty();
    public Vx_core.Type_any vx_type();
    public Vx_core.Type_string key();
    public Vx_repl.Type_repl current();
    public Vx_repl.Type_repllist repllist();
  }

  public class Class_replarglist : Vx_core.Class_base, Type_replarglist {

    public Vx_core.Type_string vx_p_key;

    public Vx_core.Type_string key() {
      Vx_core.Type_string output = Vx_core.e_string;
      if (this.vx_p_key != null) {
        output = this.vx_p_key;
      }
      return output;
    }

    public Vx_repl.Type_repl vx_p_current;

    public Vx_repl.Type_repl current() {
      Vx_repl.Type_repl output = Vx_repl.e_repl;
      if (this.vx_p_current != null) {
        output = this.vx_p_current;
      }
      return output;
    }

    public Vx_repl.Type_repllist vx_p_repllist;

    public Vx_repl.Type_repllist repllist() {
      Vx_repl.Type_repllist output = Vx_repl.e_repllist;
      if (this.vx_p_repllist != null) {
        output = this.vx_p_repllist;
      }
      return output;
    }

    public Vx_core.Type_any vx_any(Vx_core.Type_string key) {
      Vx_core.Type_any output = Vx_core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":key":
        output = this.key();
        break;
      case ":current":
        output = this.current();
        break;
      case ":repllist":
        output = this.repllist();
        break;
      }
      return output;
    }

    public Vx_core.Map<string, Vx_core.Type_any> vx_map() {
      Vx_core.Map<string, Vx_core.Type_any> output = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
      output.put(":key", this.key());
      output.put(":current", this.current());
      output.put(":repllist", this.repllist());
      return Vx_core.immutablemap(output);
    }

    public override Vx_repl.Type_replarglist vx_new(params Object[] vals) {
      return Vx_core.vx_copy(
       e_replarglist,
       vals);
    }

    public override Vx_repl.Type_replarglist vx_copy(params Object[] vals) {
      Type_replarglist output = this;
      bool ischanged = false;
      Class_replarglist val = this;
      Vx_core.Type_msgblock msgblock = Vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx_core.vx_Type_const) {
        ischanged = true;
      }
      Vx_core.Type_string vx_p_key = val.key();
      Vx_repl.Type_repl vx_p_current = val.current();
      Vx_repl.Type_repllist vx_p_repllist = val.repllist();
      List<string> validkeys = new List<string>();
      validkeys.Add(":key");
      validkeys.Add(":current");
      validkeys.Add(":repllist");
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
            msg = Vx_core.vx_msg_from_error("vx/repl/replarglist", ":invalidkeytype", msgval);
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
              msg = Vx_core.vx_msg_from_error("vx/repl/replarglist", ":invalidkey", msgval);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":key":
            if (valsub == vx_p_key) {
            } else if (valsub is Vx_core.Type_string) {
              ischanged = true;
              vx_p_key = (Vx_core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_key = Vx_core.vx_new(Vx_core.t_string, valsub);
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("key"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/repl/replarglist", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":current":
            if (valsub == vx_p_current) {
            } else if (valsub is Vx_repl.Type_repl) {
              ischanged = true;
              vx_p_current = (Vx_repl.Type_repl)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("current"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/repl/replarglist", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":repllist":
            if (valsub == vx_p_repllist) {
            } else if (valsub is Vx_repl.Type_repllist) {
              ischanged = true;
              vx_p_repllist = (Vx_repl.Type_repllist)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("repllist"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/repl/replarglist", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx_core.vx_new_string(key);
            msg = Vx_core.vx_msg_from_error("vx/repl/replarglist", ":invalidkey", msgval);
            msgblock = Vx_core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx_core.e_msgblock)) {
        Class_replarglist work = new Class_replarglist();
        work.vx_p_key = vx_p_key;
        work.vx_p_current = vx_p_current;
        work.vx_p_repllist = vx_p_repllist;
        if (msgblock != Vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx_core.Type_any vx_empty() {
      return e_replarglist;
    }
    public override Vx_core.Type_any vx_type() {
      return t_replarglist;
    }

    public override Vx_core.Type_typedef vx_typedef() {
      return Vx_core.typedef_new(
        "vx/repl", // pkgname
        "replarglist", // name
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

  public static Type_replarglist e_replarglist = new Class_replarglist();
  public static Type_replarglist t_replarglist = new Class_replarglist();

  /**
   * type: repllist
   * List of repl
   * (type repllist)
   */
  public interface Type_repllist : Vx_core.Type_list {
    public Vx_core.Type_any vx_new(params Object[] vals);
    public Vx_core.Type_any vx_copy(params Object[] vals);
    public Vx_core.Type_any vx_empty();
    public Vx_core.Type_any vx_type();
    public List<Vx_repl.Type_repl> vx_listrepl();
    public Vx_repl.Type_repl vx_repl(Vx_core.Type_int index);
  }

  public class Class_repllist : Vx_core.Class_base, Type_repllist {

    public List<Vx_repl.Type_repl> vx_p_list = Vx_core.immutablelist(new List<Vx_repl.Type_repl>());

    public List<Vx_core.Type_any> vx_list() {
      List<Vx_core.Type_any> output = Vx_core.immutablelist(
        new List<Vx_core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx_repl.Type_repl vx_repl(Vx_core.Type_int index) {
      Vx_repl.Type_repl output = Vx_repl.e_repl;
      Vx_repl.Class_repllist list = this;
      int iindex = index.vx_int();
      List<Vx_repl.Type_repl> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx_repl.Type_repl> vx_listrepl() {
      return vx_p_list;
    }

    public Vx_core.Type_any vx_any(Vx_core.Type_int index) {
      return this.vx_repl(index);
    }

    public override Vx_repl.Type_repllist vx_new(params Object[] vals) {
      return Vx_core.vx_copy(
       e_repllist,
       vals);
    }

    public override Vx_repl.Type_repllist vx_copy(params Object[] vals) {
      Type_repllist output = this;
      bool ischanged = false;
      Class_repllist val = this;
      Vx_core.Type_msgblock msgblock = Vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx_core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx_repl.Type_repl> listval = new List<Vx_repl.Type_repl>(val.vx_listrepl());
      Vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx_core.Type_msgblock) {
          msgblock = Vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx_core.Type_msg) {
          msgblock = Vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx_repl.Type_repl) {
          Vx_repl.Type_repl anysub = valsub as Vx_repl.Type_repl;
          ischanged = true;
          listval.Add(anysub);
        } else if (valsub is Vx_repl.Type_repl) {
          ischanged = true;
          listval.Add((Vx_repl.Type_repl)valsub);
        } else if (valsub is Vx_repl.Type_repllist) {
          Type_repllist multi = (Type_repllist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_listrepl());
        } else if (valsub is List<object>) {
          List<object> listunknown = valsub as List<object>;
          foreach (Object item in listunknown) {
            if (item is Vx_repl.Type_repl) {
              Vx_repl.Type_repl valitem = (Vx_repl.Type_repl)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx_core.Type_any) {
          Vx_core.Type_any anysub = valsub as Vx_core.Type_any;
          msg = Vx_core.vx_msg_from_error("vx/repl/repllist", ":invalidtype", anysub);
          msgblock = Vx_core.vx_copy(msgblock, msg);
        } else {
          msg = Vx_core.vx_msg_from_error("vx/repl/repllist", ":invalidtype", Vx_core.vx_new_string(valsub.ToString()));
          msgblock = Vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx_core.e_msgblock)) {
        Class_repllist work = new Class_repllist();
        work.vx_p_list = Vx_core.immutablelist(listval);
        if (msgblock != Vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx_core.Type_any vx_empty() {
      return e_repllist;
    }
    public override Vx_core.Type_any vx_type() {
      return t_repllist;
    }

    public override Vx_core.Type_typedef vx_typedef() {
      return Vx_core.typedef_new(
        "vx/repl", // pkgname
        "repllist", // name
        ":list", // extends
        Vx_core.e_typelist, // traits
        Vx_core.vx_new(Vx_core.t_typelist, Vx_repl.t_repl), // allowtypes
        Vx_core.e_typelist, // disallowtypes
        Vx_core.e_funclist, // allowfuncs
        Vx_core.e_funclist, // disallowfuncs
        Vx_core.e_anylist, // allowvalues
        Vx_core.e_anylist, // disallowvalues
        Vx_core.e_argmap // properties
      );
    }

  }

  public static Type_repllist e_repllist = new Class_repllist();
  public static Type_repllist t_repllist = new Class_repllist();

  /**
   * Constant: delimvxlisp
   * vxlisp File Delimiters
   * {delim}
   */
  public class Const_delimvxlisp : Vx_data_textblock.Class_delim, Vx_core.vx_Type_const {
    
    public Vx_core.Type_constdef vx_constdef() {
      return Vx_core.constdef_new(
        "vx/repl", // pkgname
        "delimvxlisp", // name
        Vx_core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimvxlisp output) {
      Vx_data_textblock.Type_delim val = Vx_core.f_new(
        Vx_data_textblock.t_delim,
        Vx_core.vx_new(Vx_core.t_anylist,
                Vx_core.vx_new_string(":name"),
                Vx_core.vx_new_string("delimvxlisp"),
                Vx_core.vx_new_string(":delimlist"),
                Vx_core.f_new(
                  Vx_data_textblock.t_delimlist,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_repl.c_delimvxlispparen,
                    Vx_data_textblock.c_delimcomment,
                    Vx_data_textblock.c_delimcommentblock
                  )
                )
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static Const_delimvxlisp c_delimvxlisp = new Const_delimvxlisp();


  /**
   * Constant: delimvxlispbracket
   * vxlisp Square Bracket Delimiters
   * {delim}
   */
  public class Const_delimvxlispbracket : Vx_data_textblock.Class_delim, Vx_core.vx_Type_const {
    
    public Vx_core.Type_constdef vx_constdef() {
      return Vx_core.constdef_new(
        "vx/repl", // pkgname
        "delimvxlispbracket", // name
        Vx_core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimvxlispbracket output) {
      Vx_data_textblock.Type_delim val = Vx_core.f_copy(
        Vx_data_textblock.c_delimbracketsquare,
        Vx_core.vx_new(Vx_core.t_anylist,
                Vx_core.vx_new_string(":name"),
                Vx_core.vx_new_string("delimvxlispbracketsquare"),
                Vx_core.vx_new_string(":delimlist"),
                Vx_core.f_new(
                  Vx_data_textblock.t_delimlist,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_data_textblock.c_delimcomment,
                    Vx_data_textblock.c_delimcommentblock,
                    Vx_data_textblock.c_delimquote,
                    Vx_data_textblock.c_delimquoteblock,
                    Vx_data_textblock.c_delimwhitespace,
                    Vx_repl.c_delimvxlispparen
                  )
                )
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static Const_delimvxlispbracket c_delimvxlispbracket = new Const_delimvxlispbracket();


  /**
   * Constant: delimvxlispparen
   * vxlisp Paren Delimiters
   * {delim}
   */
  public class Const_delimvxlispparen : Vx_data_textblock.Class_delim, Vx_core.vx_Type_const {
    
    public Vx_core.Type_constdef vx_constdef() {
      return Vx_core.constdef_new(
        "vx/repl", // pkgname
        "delimvxlispparen", // name
        Vx_core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimvxlispparen output) {
      Vx_data_textblock.Type_delim val = Vx_core.f_copy(
        Vx_data_textblock.c_delimparen,
        Vx_core.vx_new(Vx_core.t_anylist,
                Vx_core.vx_new_string(":name"),
                Vx_core.vx_new_string("delimvxlispparen"),
                Vx_core.vx_new_string(":delimlist"),
                Vx_core.f_new(
                  Vx_data_textblock.t_delimlist,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_data_textblock.c_delimcomment,
                    Vx_data_textblock.c_delimcommentblock,
                    Vx_data_textblock.c_delimquote,
                    Vx_data_textblock.c_delimquoteblock,
                    Vx_data_textblock.c_delimwhitespace,
                    Vx_repl.c_delimvxlispbracket,
                    Vx_repl.c_delimvxlispparen
                  )
                )
        )
      );
      output.vx_p_name = val.name();
      output.vx_p_starttext = val.starttext();
      output.vx_p_endtext = val.endtext();
      output.vx_p_pos = val.pos();
      output.vx_p_delimlist = val.delimlist();
    }


  }

  public static Const_delimvxlispparen c_delimvxlispparen = new Const_delimvxlispparen();

  /**
   * @function any_repl_from_functype_args
   * Returns any from a repl func and args.
   * @param  {any} type
   * @param  {anylist} args
   * @return {any}
   * (func any-repl<-functype-args)
   */
  public interface Func_any_repl_from_functype_args : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_core.Type_any vx_any_repl_from_functype_args(Vx_core.Type_any type, Vx_core.Type_anylist args);
  }

  public class Class_any_repl_from_functype_args : Vx_core.Class_base, Func_any_repl_from_functype_args {

    public override Vx_repl.Func_any_repl_from_functype_args vx_new(params Object[] vals) {
      Class_any_repl_from_functype_args output = new Class_any_repl_from_functype_args();
      return output;
    }

    public override Vx_repl.Func_any_repl_from_functype_args vx_copy(params Object[] vals) {
      Class_any_repl_from_functype_args output = new Class_any_repl_from_functype_args();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/repl", // pkgname
        "any-repl<-functype-args", // name
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
      return e_any_repl_from_functype_args;
    }

    public override Vx_core.Type_any vx_type() {
      return t_any_repl_from_functype_args;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_any type = Vx_core.f_any_from_any(Vx_core.t_any, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_anylist args = Vx_core.f_any_from_any(Vx_core.t_anylist, arglist.vx_any(Vx_core.vx_new_int(1)));
      output = Vx_repl.f_any_repl_from_functype_args(type, args);
      return output;
    }

    public Vx_core.Type_any vx_any_repl_from_functype_args(Vx_core.Type_any type, Vx_core.Type_anylist args) {
      return Vx_repl.f_any_repl_from_functype_args(type, args);
    }

  }

  public static Func_any_repl_from_functype_args e_any_repl_from_functype_args = new Vx_repl.Class_any_repl_from_functype_args();
  public static Func_any_repl_from_functype_args t_any_repl_from_functype_args = new Vx_repl.Class_any_repl_from_functype_args();

  public static Vx_core.Type_any f_any_repl_from_functype_args(Vx_core.Type_any type, Vx_core.Type_anylist args) {
    Vx_core.Type_any output = Vx_core.e_any;
    return output;
  }

  /**
   * @function any_from_liblist_string
   * Run an arbitrary program in the REPL.
   * @param  {liblist} liblist
   * @param  {string} text Program to run
   * @return {any}
   * (func any<-liblist-string)
   */
  public interface Func_any_from_liblist_string : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_core.Type_any vx_any_from_liblist_string(Vx_core.Type_context context, Vx_repl.Type_liblist liblist, Vx_core.Type_string text);
  }

  public class Class_any_from_liblist_string : Vx_core.Class_base, Func_any_from_liblist_string {

    public override Vx_repl.Func_any_from_liblist_string vx_new(params Object[] vals) {
      Class_any_from_liblist_string output = new Class_any_from_liblist_string();
      return output;
    }

    public override Vx_repl.Func_any_from_liblist_string vx_copy(params Object[] vals) {
      Class_any_from_liblist_string output = new Class_any_from_liblist_string();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/repl", // pkgname
        "any<-liblist-string", // name
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
      return e_any_from_liblist_string;
    }

    public override Vx_core.Type_any vx_type() {
      return t_any_from_liblist_string;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_repl.Type_liblist liblist = Vx_core.f_any_from_any(Vx_repl.t_liblist, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_string text = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(1)));
      output = Vx_repl.f_any_from_liblist_string(context, liblist, text);
      return output;
    }

    public Vx_core.Type_any vx_any_from_liblist_string(Vx_core.Type_context context, Vx_repl.Type_liblist liblist, Vx_core.Type_string text) {
      return Vx_repl.f_any_from_liblist_string(context, liblist, text);
    }

  }

  public static Func_any_from_liblist_string e_any_from_liblist_string = new Vx_repl.Class_any_from_liblist_string();
  public static Func_any_from_liblist_string t_any_from_liblist_string = new Vx_repl.Class_any_from_liblist_string();

  public static Vx_core.Type_any f_any_from_liblist_string(Vx_core.Type_context context, Vx_repl.Type_liblist liblist, Vx_core.Type_string text) {
    Vx_core.Type_any output = Vx_core.e_any;
    output = Vx_core.f_let(
      Vx_core.t_any,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_repl.Type_repl repl = Vx_repl.f_repl_from_liblist_string(liblist, text);
        return Vx_repl.f_any_from_repl(context, repl);
      })
    );
    return output;
  }

  /**
   * @function any_from_macro
   * A function that joins any number of values into a string and then parses and evaluates it.
   * @param  {anylist} anylist
   * @return {any-1}
   * (func any<-macro)
   */
  public interface Func_any_from_macro : Vx_core.Func_any_from_any_context {
    public T vx_any_from_macro<T>(T generic_any_1, Vx_core.Type_context context, Vx_core.Type_anylist anylist) where T : Vx_core.Type_any;
  }

  public class Class_any_from_macro : Vx_core.Class_base, Func_any_from_macro {

    public override Vx_repl.Func_any_from_macro vx_new(params Object[] vals) {
      Class_any_from_macro output = new Class_any_from_macro();
      return output;
    }

    public override Vx_repl.Func_any_from_macro vx_copy(params Object[] vals) {
      Class_any_from_macro output = new Class_any_from_macro();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/repl", // pkgname
        "any<-macro", // name
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
      return e_any_from_macro;
    }

    public override Vx_core.Type_any vx_type() {
      return t_any_from_macro;
    }

    public Vx_core.Func_any_from_any_context vx_fn_new(Vx_core.Class_any_from_any_context.IFn fn) {
      return Vx_core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx_core.Type_context context, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_core.Type_anylist inputval = (Vx_core.Type_anylist)value;
      Vx_core.Type_any outputval = Vx_repl.f_any_from_macro(Vx_core.t_any, context, inputval);
      output = Vx_core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_any generic_any_1 = Vx_core.f_any_from_any(Vx_core.t_any, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_anylist anylist = Vx_core.f_any_from_any(Vx_core.t_anylist, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_repl.f_any_from_macro(generic_any_1, context, anylist);
      return output;
    }

    public T vx_any_from_macro<T>(T generic_any_1, Vx_core.Type_context context, Vx_core.Type_anylist anylist) where T : Vx_core.Type_any {
      return Vx_repl.f_any_from_macro(generic_any_1, context, anylist);
    }

  }

  public static Func_any_from_macro e_any_from_macro = new Vx_repl.Class_any_from_macro();
  public static Func_any_from_macro t_any_from_macro = new Vx_repl.Class_any_from_macro();

  public static T f_any_from_macro<T>(T generic_any_1, Vx_core.Type_context context, Vx_core.Type_anylist anylist) where T : Vx_core.Type_any {
    T output = Vx_core.f_empty(generic_any_1);
    output = Vx_core.f_let(
      generic_any_1,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_repl.Type_repl repl = Vx_repl.f_repl_from_macro(context, anylist);
        Vx_core.Type_any val = Vx_repl.f_any_from_repl(context, repl);
        return Vx_core.f_any_from_any(generic_any_1, val);
      })
    );
    return output;
  }

  /**
   * @function any_from_repl
   * Run an arbitrary program in the REPL.
   * @param  {repl} repl
   * @return {any}
   * (func any<-repl)
   */
  public interface Func_any_from_repl : Vx_core.Func_any_from_any_context {
    public Vx_core.Type_any vx_any_from_repl(Vx_core.Type_context context, Vx_repl.Type_repl repl);
  }

  public class Class_any_from_repl : Vx_core.Class_base, Func_any_from_repl {

    public override Vx_repl.Func_any_from_repl vx_new(params Object[] vals) {
      Class_any_from_repl output = new Class_any_from_repl();
      return output;
    }

    public override Vx_repl.Func_any_from_repl vx_copy(params Object[] vals) {
      Class_any_from_repl output = new Class_any_from_repl();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/repl", // pkgname
        "any<-repl", // name
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
      return e_any_from_repl;
    }

    public override Vx_core.Type_any vx_type() {
      return t_any_from_repl;
    }

    public Vx_core.Func_any_from_any_context vx_fn_new(Vx_core.Class_any_from_any_context.IFn fn) {
      return Vx_core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx_core.Type_context context, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_repl.Type_repl inputval = (Vx_repl.Type_repl)value;
      Vx_core.Type_any outputval = Vx_repl.f_any_from_repl(context, inputval);
      output = Vx_core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_repl.Type_repl repl = Vx_core.f_any_from_any(Vx_repl.t_repl, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_repl.f_any_from_repl(context, repl);
      return output;
    }

    public Vx_core.Type_any vx_any_from_repl(Vx_core.Type_context context, Vx_repl.Type_repl repl) {
      return Vx_repl.f_any_from_repl(context, repl);
    }

  }

  public static Func_any_from_repl e_any_from_repl = new Vx_repl.Class_any_from_repl();
  public static Func_any_from_repl t_any_from_repl = new Vx_repl.Class_any_from_repl();

  public static Vx_core.Type_any f_any_from_repl(Vx_core.Type_context context, Vx_repl.Type_repl repl) {
    Vx_core.Type_any output = Vx_core.e_any;
    output = Vx_core.f_let(
      Vx_core.t_any,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_core.Type_any val = repl.val();
        Vx_core.Type_any repltype = repl.type();
        Vx_repl.Type_repllist repllist = repl.repllist();
        Vx_core.Type_anylist args = Vx_repl.f_anylist_from_repllist(context, repllist);
        return Vx_core.f_if_2(
          Vx_core.t_any,
          Vx_core.vx_new(Vx_core.t_thenelselist,
            Vx_core.f_then(
              Vx_core.t_boolean_from_func.vx_fn_new(() => {
                return Vx_core.f_notempty_1(val);
              }),
              Vx_core.t_any_from_func.vx_fn_new(() => {
                return val;
              })
            ),
            Vx_core.f_then(
              Vx_core.t_boolean_from_func.vx_fn_new(() => {
                return Vx_core.f_is_func(repltype);
              }),
              Vx_core.t_any_from_func.vx_fn_new(() => {
                return Vx_repl.f_any_repl_from_functype_args(repltype, args);
              })
            ),
            Vx_core.f_else(
              Vx_core.t_any_from_func.vx_fn_new(() => {
                return Vx_core.f_new(repltype, args);
              })
            )
          )
        );
      })
    );
    return output;
  }

  /**
   * @function any_from_script
   * Run an arbitrary script.
   * @param  {string} script
   * @return {any}
   * (func any<-script)
   */
  public interface Func_any_from_script : Vx_core.Func_any_from_any_context {
    public Vx_core.Type_any vx_any_from_script(Vx_core.Type_context context, Vx_core.Type_string script);
  }

  public class Class_any_from_script : Vx_core.Class_base, Func_any_from_script {

    public override Vx_repl.Func_any_from_script vx_new(params Object[] vals) {
      Class_any_from_script output = new Class_any_from_script();
      return output;
    }

    public override Vx_repl.Func_any_from_script vx_copy(params Object[] vals) {
      Class_any_from_script output = new Class_any_from_script();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/repl", // pkgname
        "any<-script", // name
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
      return e_any_from_script;
    }

    public override Vx_core.Type_any vx_type() {
      return t_any_from_script;
    }

    public Vx_core.Func_any_from_any_context vx_fn_new(Vx_core.Class_any_from_any_context.IFn fn) {
      return Vx_core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx_core.Type_context context, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_core.Type_string inputval = (Vx_core.Type_string)value;
      Vx_core.Type_any outputval = Vx_repl.f_any_from_script(context, inputval);
      output = Vx_core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_string script = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_repl.f_any_from_script(context, script);
      return output;
    }

    public Vx_core.Type_any vx_any_from_script(Vx_core.Type_context context, Vx_core.Type_string script) {
      return Vx_repl.f_any_from_script(context, script);
    }

  }

  public static Func_any_from_script e_any_from_script = new Vx_repl.Class_any_from_script();
  public static Func_any_from_script t_any_from_script = new Vx_repl.Class_any_from_script();

  public static Vx_core.Type_any f_any_from_script(Vx_core.Type_context context, Vx_core.Type_string script) {
    Vx_core.Type_any output = Vx_core.e_any;
    output = Vx_core.f_let(
      Vx_core.t_any,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_data_textblock.Type_textblock textblock = Vx_repl.f_textblock_from_script(script);
        Vx_repl.Type_repl repl = Vx_repl.f_repl_from_textblock(textblock);
        return Vx_repl.f_any_from_repl(context, repl);
      })
    );
    return output;
  }

  /**
   * @function anylist_from_repllist
   * Run an arbitrary program in the REPL.
   * @param  {repllist} repllist
   * @return {anylist}
   * (func anylist<-repllist)
   */
  public interface Func_anylist_from_repllist : Vx_core.Func_any_from_any_context {
    public Vx_core.Type_anylist vx_anylist_from_repllist(Vx_core.Type_context context, Vx_repl.Type_repllist repllist);
  }

  public class Class_anylist_from_repllist : Vx_core.Class_base, Func_anylist_from_repllist {

    public override Vx_repl.Func_anylist_from_repllist vx_new(params Object[] vals) {
      Class_anylist_from_repllist output = new Class_anylist_from_repllist();
      return output;
    }

    public override Vx_repl.Func_anylist_from_repllist vx_copy(params Object[] vals) {
      Class_anylist_from_repllist output = new Class_anylist_from_repllist();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/repl", // pkgname
        "anylist<-repllist", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "anylist", // name
          ":list", // extends
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
      return e_anylist_from_repllist;
    }

    public override Vx_core.Type_any vx_type() {
      return t_anylist_from_repllist;
    }

    public Vx_core.Func_any_from_any_context vx_fn_new(Vx_core.Class_any_from_any_context.IFn fn) {
      return Vx_core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx_core.Type_context context, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_repl.Type_repllist inputval = (Vx_repl.Type_repllist)value;
      Vx_core.Type_any outputval = Vx_repl.f_anylist_from_repllist(context, inputval);
      output = Vx_core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_repl.Type_repllist repllist = Vx_core.f_any_from_any(Vx_repl.t_repllist, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_repl.f_anylist_from_repllist(context, repllist);
      return output;
    }

    public Vx_core.Type_anylist vx_anylist_from_repllist(Vx_core.Type_context context, Vx_repl.Type_repllist repllist) {
      return Vx_repl.f_anylist_from_repllist(context, repllist);
    }

  }

  public static Func_anylist_from_repllist e_anylist_from_repllist = new Vx_repl.Class_anylist_from_repllist();
  public static Func_anylist_from_repllist t_anylist_from_repllist = new Vx_repl.Class_anylist_from_repllist();

  public static Vx_core.Type_anylist f_anylist_from_repllist(Vx_core.Type_context context, Vx_repl.Type_repllist repllist) {
    Vx_core.Type_anylist output = Vx_core.e_anylist;
    output = Vx_core.f_list_from_list_1(
      Vx_core.t_anylist,
      repllist,
      Vx_core.t_any_from_any.vx_fn_new((repl_any) => {
        Vx_repl.Type_repl repl = Vx_core.f_any_from_any(Vx_repl.t_repl, repl_any);
        return 
        Vx_repl.f_any_from_repl(context, repl);
      })
    );
    return output;
  }

  /**
   * @function argmap_from_textblock_argmap
   * Returns an argmap with parsed args from textblock added.
   * @param  {textblock} textblock
   * @param  {argmap} argmap
   * @return {argmap}
   * (func argmap<-textblock-argmap)
   */
  public interface Func_argmap_from_textblock_argmap : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_core.Type_argmap vx_argmap_from_textblock_argmap(Vx_data_textblock.Type_textblock textblock, Vx_core.Type_argmap argmap);
  }

  public class Class_argmap_from_textblock_argmap : Vx_core.Class_base, Func_argmap_from_textblock_argmap {

    public override Vx_repl.Func_argmap_from_textblock_argmap vx_new(params Object[] vals) {
      Class_argmap_from_textblock_argmap output = new Class_argmap_from_textblock_argmap();
      return output;
    }

    public override Vx_repl.Func_argmap_from_textblock_argmap vx_copy(params Object[] vals) {
      Class_argmap_from_textblock_argmap output = new Class_argmap_from_textblock_argmap();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/repl", // pkgname
        "argmap<-textblock-argmap", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "argmap", // name
          ":map", // extends
          Vx_core.e_typelist, // traits
          Vx_core.vx_new(Vx_core.t_typelist, Vx_core.t_arg), // allowtypes
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
      return e_argmap_from_textblock_argmap;
    }

    public override Vx_core.Type_any vx_type() {
      return t_argmap_from_textblock_argmap;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_data_textblock.Type_textblock textblock = Vx_core.f_any_from_any(Vx_data_textblock.t_textblock, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_argmap argmap = Vx_core.f_any_from_any(Vx_core.t_argmap, arglist.vx_any(Vx_core.vx_new_int(1)));
      output = Vx_repl.f_argmap_from_textblock_argmap(textblock, argmap);
      return output;
    }

    public Vx_core.Type_argmap vx_argmap_from_textblock_argmap(Vx_data_textblock.Type_textblock textblock, Vx_core.Type_argmap argmap) {
      return Vx_repl.f_argmap_from_textblock_argmap(textblock, argmap);
    }

  }

  public static Func_argmap_from_textblock_argmap e_argmap_from_textblock_argmap = new Vx_repl.Class_argmap_from_textblock_argmap();
  public static Func_argmap_from_textblock_argmap t_argmap_from_textblock_argmap = new Vx_repl.Class_argmap_from_textblock_argmap();

  public static Vx_core.Type_argmap f_argmap_from_textblock_argmap(Vx_data_textblock.Type_textblock textblock, Vx_core.Type_argmap argmap) {
    Vx_core.Type_argmap output = Vx_core.e_argmap;
    output = Vx_core.f_if_1(
      Vx_core.t_argmap,
      Vx_core.f_ne(
        Vx_core.vx_new_string("delimbracketsquare"),
        textblock.delim().name()
      ),
      argmap,
      argmap
    );
    return output;
  }

  /**
   * @function const_from_string
   * Returns a constant from a fully qualified name.
   * @param  {string} text
   * @return {any}
   * (func const<-string)
   */
  public interface Func_const_from_string : Vx_core.Func_any_from_any {
    public Vx_core.Type_any vx_const_from_string(Vx_core.Type_string text);
  }

  public class Class_const_from_string : Vx_core.Class_base, Func_const_from_string {

    public override Vx_repl.Func_const_from_string vx_new(params Object[] vals) {
      Class_const_from_string output = new Class_const_from_string();
      return output;
    }

    public override Vx_repl.Func_const_from_string vx_copy(params Object[] vals) {
      Class_const_from_string output = new Class_const_from_string();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/repl", // pkgname
        "const<-string", // name
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
      return e_const_from_string;
    }

    public override Vx_core.Type_any vx_type() {
      return t_const_from_string;
    }

    public Vx_core.Func_any_from_any vx_fn_new(Vx_core.Class_any_from_any.IFn fn) {
      return Vx_core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_core.Type_string inputval = (Vx_core.Type_string)value;
      Vx_core.Type_any outputval = Vx_repl.f_const_from_string(inputval);
      output = Vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_string text = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_repl.f_const_from_string(text);
      return output;
    }

    public Vx_core.Type_any vx_const_from_string(Vx_core.Type_string text) {
      return Vx_repl.f_const_from_string(text);
    }

  }

  public static Func_const_from_string e_const_from_string = new Vx_repl.Class_const_from_string();
  public static Func_const_from_string t_const_from_string = new Vx_repl.Class_const_from_string();

  public static Vx_core.Type_any f_const_from_string(Vx_core.Type_string text) {
    Vx_core.Type_any output = Vx_core.e_any;
    output = Vx_core.f_let(
      Vx_core.t_any,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_core.Type_int pkgpos = Vx_type.f_int_from_string_findlast(text, Vx_core.vx_new_string("/"));
        Vx_core.Type_string pkgname = Vx_core.f_if_1(
          Vx_core.t_string,
          Vx_core.f_eq(Vx_core.vx_new_int(0), pkgpos),
          Vx_core.vx_new_string("vx/core"),
          Vx_type.f_string_from_string_end(
            text,
            Vx_core.f_minus1(pkgpos)
          )
        );
        Vx_core.Type_string name = Vx_core.f_if_1(
          Vx_core.t_string,
          Vx_core.f_eq(Vx_core.vx_new_int(0), pkgpos),
          text,
          Vx_type.f_string_from_string_start(
            text,
            Vx_core.f_plus1(pkgpos)
          )
        );
        Vx_core.Type_package pkg = Vx_core.f_package_global_from_name(pkgname);
        Vx_core.Type_constmap constmap = pkg.constmap();
        Vx_core.Type_any constval = Vx_core.f_any_from_map(Vx_core.t_any, constmap, name);
        return Vx_core.f_if_1(
          Vx_core.t_any,
          Vx_core.f_notempty_1(constval),
          constval,
          Vx_core.f_empty(
            Vx_core.t_any
          )
        );
      })
    );
    return output;
  }

  /**
   * @function repl_bracket_from_textblock_argmap
   * Returns a repl from a squarebracket parsed textblock
   * @param  {textblock} textblock
   * @param  {argmap} argmap
   * @return {repl}
   * (func repl-bracket<-textblock-argmap)
   */
  public interface Func_repl_bracket_from_textblock_argmap : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_repl.Type_repl vx_repl_bracket_from_textblock_argmap(Vx_data_textblock.Type_textblock textblock, Vx_core.Type_argmap argmap);
  }

  public class Class_repl_bracket_from_textblock_argmap : Vx_core.Class_base, Func_repl_bracket_from_textblock_argmap {

    public override Vx_repl.Func_repl_bracket_from_textblock_argmap vx_new(params Object[] vals) {
      Class_repl_bracket_from_textblock_argmap output = new Class_repl_bracket_from_textblock_argmap();
      return output;
    }

    public override Vx_repl.Func_repl_bracket_from_textblock_argmap vx_copy(params Object[] vals) {
      Class_repl_bracket_from_textblock_argmap output = new Class_repl_bracket_from_textblock_argmap();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/repl", // pkgname
        "repl-bracket<-textblock-argmap", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_bracket_from_textblock_argmap;
    }

    public override Vx_core.Type_any vx_type() {
      return t_repl_bracket_from_textblock_argmap;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_data_textblock.Type_textblock textblock = Vx_core.f_any_from_any(Vx_data_textblock.t_textblock, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_argmap argmap = Vx_core.f_any_from_any(Vx_core.t_argmap, arglist.vx_any(Vx_core.vx_new_int(1)));
      output = Vx_repl.f_repl_bracket_from_textblock_argmap(textblock, argmap);
      return output;
    }

    public Vx_repl.Type_repl vx_repl_bracket_from_textblock_argmap(Vx_data_textblock.Type_textblock textblock, Vx_core.Type_argmap argmap) {
      return Vx_repl.f_repl_bracket_from_textblock_argmap(textblock, argmap);
    }

  }

  public static Func_repl_bracket_from_textblock_argmap e_repl_bracket_from_textblock_argmap = new Vx_repl.Class_repl_bracket_from_textblock_argmap();
  public static Func_repl_bracket_from_textblock_argmap t_repl_bracket_from_textblock_argmap = new Vx_repl.Class_repl_bracket_from_textblock_argmap();

  public static Vx_repl.Type_repl f_repl_bracket_from_textblock_argmap(Vx_data_textblock.Type_textblock textblock, Vx_core.Type_argmap argmap) {
    Vx_repl.Type_repl output = Vx_repl.e_repl;
    output = Vx_core.f_empty(
      Vx_repl.t_repl
    );
    return output;
  }

  /**
   * @function repl_empty_from_textblock_argmap
   * Returns a repl from an empty delim textblock
   * @param  {textblock} textblock
   * @param  {argmap} argmap
   * @return {repl}
   * (func repl-empty<-textblock-argmap)
   */
  public interface Func_repl_empty_from_textblock_argmap : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_repl.Type_repl vx_repl_empty_from_textblock_argmap(Vx_data_textblock.Type_textblock textblock, Vx_core.Type_argmap argmap);
  }

  public class Class_repl_empty_from_textblock_argmap : Vx_core.Class_base, Func_repl_empty_from_textblock_argmap {

    public override Vx_repl.Func_repl_empty_from_textblock_argmap vx_new(params Object[] vals) {
      Class_repl_empty_from_textblock_argmap output = new Class_repl_empty_from_textblock_argmap();
      return output;
    }

    public override Vx_repl.Func_repl_empty_from_textblock_argmap vx_copy(params Object[] vals) {
      Class_repl_empty_from_textblock_argmap output = new Class_repl_empty_from_textblock_argmap();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/repl", // pkgname
        "repl-empty<-textblock-argmap", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_empty_from_textblock_argmap;
    }

    public override Vx_core.Type_any vx_type() {
      return t_repl_empty_from_textblock_argmap;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_data_textblock.Type_textblock textblock = Vx_core.f_any_from_any(Vx_data_textblock.t_textblock, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_argmap argmap = Vx_core.f_any_from_any(Vx_core.t_argmap, arglist.vx_any(Vx_core.vx_new_int(1)));
      output = Vx_repl.f_repl_empty_from_textblock_argmap(textblock, argmap);
      return output;
    }

    public Vx_repl.Type_repl vx_repl_empty_from_textblock_argmap(Vx_data_textblock.Type_textblock textblock, Vx_core.Type_argmap argmap) {
      return Vx_repl.f_repl_empty_from_textblock_argmap(textblock, argmap);
    }

  }

  public static Func_repl_empty_from_textblock_argmap e_repl_empty_from_textblock_argmap = new Vx_repl.Class_repl_empty_from_textblock_argmap();
  public static Func_repl_empty_from_textblock_argmap t_repl_empty_from_textblock_argmap = new Vx_repl.Class_repl_empty_from_textblock_argmap();

  public static Vx_repl.Type_repl f_repl_empty_from_textblock_argmap(Vx_data_textblock.Type_textblock textblock, Vx_core.Type_argmap argmap) {
    Vx_repl.Type_repl output = Vx_repl.e_repl;
    output = Vx_core.f_let(
      Vx_repl.t_repl,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_data_textblock.Type_textblocklist children = textblock.children();
        Vx_core.Type_int len = Vx_core.f_length_1(children);
        return Vx_core.f_switch(
          Vx_repl.t_repl,
          len,
          Vx_core.vx_new(Vx_core.t_thenelselist,
            Vx_core.f_case_1(
              Vx_core.vx_new_int(0),
              Vx_core.t_any_from_func.vx_fn_new(() => {
                return Vx_repl.f_repl_from_string_argmap(
                  textblock.text(),
                  argmap
                );
              })
            ),
            Vx_core.f_case_1(
              Vx_core.vx_new_int(1),
              Vx_core.t_any_from_func.vx_fn_new(() => {
                return Vx_repl.f_repl_from_textblock_argmap(
                  Vx_core.f_any_from_list(Vx_data_textblock.t_textblock, children, Vx_core.vx_new_int(1)),
                  argmap
                );
              })
            ),
            Vx_core.f_else(
              Vx_core.t_any_from_func.vx_fn_new(() => {
                return Vx_core.f_new(
                  Vx_repl.t_repl,
                  Vx_core.vx_new(Vx_core.t_anylist,
                      Vx_core.f_msg_from_error(Vx_core.vx_new_string("Empty delim cannot have more than one child."))
                  )
                );
              })
            )
          )
        );
      })
    );
    return output;
  }

  /**
   * @function repl_paren_from_textblock_argmap
   * Returns a repl from a parsed textblock
   * @param  {textblock} textblock
   * @param  {argmap} argmap
   * @return {repl}
   * (func repl-paren<-textblock-argmap)
   */
  public interface Func_repl_paren_from_textblock_argmap : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_repl.Type_repl vx_repl_paren_from_textblock_argmap(Vx_data_textblock.Type_textblock textblock, Vx_core.Type_argmap argmap);
  }

  public class Class_repl_paren_from_textblock_argmap : Vx_core.Class_base, Func_repl_paren_from_textblock_argmap {

    public override Vx_repl.Func_repl_paren_from_textblock_argmap vx_new(params Object[] vals) {
      Class_repl_paren_from_textblock_argmap output = new Class_repl_paren_from_textblock_argmap();
      return output;
    }

    public override Vx_repl.Func_repl_paren_from_textblock_argmap vx_copy(params Object[] vals) {
      Class_repl_paren_from_textblock_argmap output = new Class_repl_paren_from_textblock_argmap();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/repl", // pkgname
        "repl-paren<-textblock-argmap", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_paren_from_textblock_argmap;
    }

    public override Vx_core.Type_any vx_type() {
      return t_repl_paren_from_textblock_argmap;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_data_textblock.Type_textblock textblock = Vx_core.f_any_from_any(Vx_data_textblock.t_textblock, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_argmap argmap = Vx_core.f_any_from_any(Vx_core.t_argmap, arglist.vx_any(Vx_core.vx_new_int(1)));
      output = Vx_repl.f_repl_paren_from_textblock_argmap(textblock, argmap);
      return output;
    }

    public Vx_repl.Type_repl vx_repl_paren_from_textblock_argmap(Vx_data_textblock.Type_textblock textblock, Vx_core.Type_argmap argmap) {
      return Vx_repl.f_repl_paren_from_textblock_argmap(textblock, argmap);
    }

  }

  public static Func_repl_paren_from_textblock_argmap e_repl_paren_from_textblock_argmap = new Vx_repl.Class_repl_paren_from_textblock_argmap();
  public static Func_repl_paren_from_textblock_argmap t_repl_paren_from_textblock_argmap = new Vx_repl.Class_repl_paren_from_textblock_argmap();

  public static Vx_repl.Type_repl f_repl_paren_from_textblock_argmap(Vx_data_textblock.Type_textblock textblock, Vx_core.Type_argmap argmap) {
    Vx_repl.Type_repl output = Vx_repl.e_repl;
    output = Vx_core.f_let(
      Vx_repl.t_repl,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_data_textblock.Type_textblocklist childlst = textblock.children();
        Vx_data_textblock.Type_textblocklist children = Vx_data_textblock.f_textblocklist_from_textblocklist_remove(
          childlst,
          Vx_data_textblock.c_delimwhitespace
        );
        Vx_data_textblock.Type_textblock tbfunc = Vx_core.f_any_from_list(Vx_data_textblock.t_textblock, children, Vx_core.vx_new_int(1));
        Vx_core.Type_string sfunc = tbfunc.text();
        Vx_repl.Type_repl replfunc = Vx_repl.f_repl_from_string_argmap(sfunc, argmap);
        Vx_core.Type_any typefunc = replfunc.type();
        Vx_core.Type_int posarg = Vx_core.f_switch(
          Vx_core.t_int,
          typefunc,
          Vx_core.vx_new(Vx_core.t_thenelselist,
              Vx_core.f_case_1(
                Vx_core.t_let,
                Vx_core.t_any_from_func.vx_fn_new(() => {
                  return Vx_core.vx_new_int(3);
                })
              ),
              Vx_core.f_case_1(
                Vx_core.t_fn,
                Vx_core.t_any_from_func.vx_fn_new(() => {
                  return Vx_core.vx_new_int(3);
                })
              ),
              Vx_core.f_else(
                Vx_core.t_any_from_func.vx_fn_new(() => {
                  return Vx_core.vx_new_int(2);
                })
              )
          )
        );
        Vx_core.Type_argmap argmap2 = Vx_core.f_switch(
          Vx_core.t_argmap,
          typefunc,
          Vx_core.vx_new(Vx_core.t_thenelselist,
              Vx_core.f_case_1(
                Vx_core.t_let,
                Vx_core.t_any_from_func.vx_fn_new(() => {
                  return Vx_repl.f_argmap_from_textblock_argmap(
                    Vx_core.f_any_from_list(Vx_data_textblock.t_textblock, children, Vx_core.vx_new_int(3)),
                    argmap
                  );
                })
              ),
              Vx_core.f_case_1(
                Vx_core.t_fn,
                Vx_core.t_any_from_func.vx_fn_new(() => {
                  return Vx_repl.f_argmap_from_textblock_argmap(
                    Vx_core.f_any_from_list(Vx_data_textblock.t_textblock, children, Vx_core.vx_new_int(3)),
                    argmap
                  );
                })
              ),
              Vx_core.f_else(
                Vx_core.t_any_from_func.vx_fn_new(() => {
                  return argmap;
                })
              )
          )
        );
        Vx_data_textblock.Type_textblocklist tbargs = Vx_collection.f_list_from_list_start(Vx_data_textblock.t_textblocklist, children, posarg);
        Vx_repl.Type_repllist replargs = Vx_repl.f_repllist_from_textblocklist_argmap(tbargs, argmap);
        return Vx_core.f_copy(
          replfunc,
          Vx_core.vx_new(Vx_core.t_anylist,
            Vx_core.vx_new_string(":repllist"),
            replargs
          )
        );
      })
    );
    return output;
  }

  /**
   * @function repl_from_liblist_string
   * Returns a repl from the given text.
   * @param  {liblist} liblist
   * @param  {string} text Program to run
   * @return {repl}
   * (func repl<-liblist-string)
   */
  public interface Func_repl_from_liblist_string : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_repl.Type_repl vx_repl_from_liblist_string(Vx_repl.Type_liblist liblist, Vx_core.Type_string text);
  }

  public class Class_repl_from_liblist_string : Vx_core.Class_base, Func_repl_from_liblist_string {

    public override Vx_repl.Func_repl_from_liblist_string vx_new(params Object[] vals) {
      Class_repl_from_liblist_string output = new Class_repl_from_liblist_string();
      return output;
    }

    public override Vx_repl.Func_repl_from_liblist_string vx_copy(params Object[] vals) {
      Class_repl_from_liblist_string output = new Class_repl_from_liblist_string();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/repl", // pkgname
        "repl<-liblist-string", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_from_liblist_string;
    }

    public override Vx_core.Type_any vx_type() {
      return t_repl_from_liblist_string;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_repl.Type_liblist liblist = Vx_core.f_any_from_any(Vx_repl.t_liblist, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_string text = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(1)));
      output = Vx_repl.f_repl_from_liblist_string(liblist, text);
      return output;
    }

    public Vx_repl.Type_repl vx_repl_from_liblist_string(Vx_repl.Type_liblist liblist, Vx_core.Type_string text) {
      return Vx_repl.f_repl_from_liblist_string(liblist, text);
    }

  }

  public static Func_repl_from_liblist_string e_repl_from_liblist_string = new Vx_repl.Class_repl_from_liblist_string();
  public static Func_repl_from_liblist_string t_repl_from_liblist_string = new Vx_repl.Class_repl_from_liblist_string();

  public static Vx_repl.Type_repl f_repl_from_liblist_string(Vx_repl.Type_liblist liblist, Vx_core.Type_string text) {
    Vx_repl.Type_repl output = Vx_repl.e_repl;
    return output;
  }

  /**
   * @function repl_from_macro
   * A function that joins any number of values into a string and then parses it.
   * @param  {anylist} anylist
   * @return {repl}
   * (func repl<-macro)
   */
  public interface Func_repl_from_macro : Vx_core.Func_any_from_any_context {
    public Vx_repl.Type_repl vx_repl_from_macro(Vx_core.Type_context context, Vx_core.Type_anylist anylist);
  }

  public class Class_repl_from_macro : Vx_core.Class_base, Func_repl_from_macro {

    public override Vx_repl.Func_repl_from_macro vx_new(params Object[] vals) {
      Class_repl_from_macro output = new Class_repl_from_macro();
      return output;
    }

    public override Vx_repl.Func_repl_from_macro vx_copy(params Object[] vals) {
      Class_repl_from_macro output = new Class_repl_from_macro();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/repl", // pkgname
        "repl<-macro", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_from_macro;
    }

    public override Vx_core.Type_any vx_type() {
      return t_repl_from_macro;
    }

    public Vx_core.Func_any_from_any_context vx_fn_new(Vx_core.Class_any_from_any_context.IFn fn) {
      return Vx_core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx_core.Type_context context, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_core.Type_anylist inputval = (Vx_core.Type_anylist)value;
      Vx_core.Type_any outputval = Vx_repl.f_repl_from_macro(context, inputval);
      output = Vx_core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_anylist anylist = Vx_core.f_any_from_any(Vx_core.t_anylist, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_repl.f_repl_from_macro(context, anylist);
      return output;
    }

    public Vx_repl.Type_repl vx_repl_from_macro(Vx_core.Type_context context, Vx_core.Type_anylist anylist) {
      return Vx_repl.f_repl_from_macro(context, anylist);
    }

  }

  public static Func_repl_from_macro e_repl_from_macro = new Vx_repl.Class_repl_from_macro();
  public static Func_repl_from_macro t_repl_from_macro = new Vx_repl.Class_repl_from_macro();

  public static Vx_repl.Type_repl f_repl_from_macro(Vx_core.Type_context context, Vx_core.Type_anylist anylist) {
    Vx_repl.Type_repl output = Vx_repl.e_repl;
    output = Vx_core.f_let(
      Vx_repl.t_repl,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_core.Type_stringlist textlist = Vx_core.f_list_from_list_1(
          Vx_core.t_stringlist,
          anylist,
          Vx_core.t_any_from_any.vx_fn_new((item_any) => {
            Vx_core.Type_any item = Vx_core.f_any_from_any(Vx_core.t_any, item_any);
            return 
              Vx_core.f_let(
                Vx_core.t_string,
                Vx_core.t_any_from_func.vx_fn_new(() => {
                  Vx_core.Type_any typ = Vx_core.f_type_from_any(item);
                  return Vx_core.f_switch(
                    Vx_core.t_string,
                    typ,
                    Vx_core.vx_new(Vx_core.t_thenelselist,
                      Vx_core.f_case_1(
                        Vx_core.t_string,
                        Vx_core.t_any_from_func.vx_fn_new(() => {
                          return Vx_core.f_any_from_any(Vx_core.t_string, item);
                        })
                      ),
                      Vx_core.f_else(
                        Vx_core.t_any_from_func.vx_fn_new(() => {
                          return Vx_core.f_string_from_any(item);
                        })
                      )
                    )
                  );
                })
              );
          })
        );
        Vx_core.Type_string script = Vx_type.f_string_from_stringlist_join(textlist, Vx_core.vx_new_string(""));
        Vx_data_textblock.Type_textblock tb = Vx_repl.f_textblock_from_script(script);
        return Vx_repl.f_repl_from_textblock(tb);
      })
    );
    return output;
  }

  /**
   * @function repl_from_script
   * Returns a parsed repl from a string
   * @param  {string} script
   * @return {repl}
   * (func repl<-script)
   */
  public interface Func_repl_from_script : Vx_core.Func_any_from_any {
    public Vx_repl.Type_repl vx_repl_from_script(Vx_core.Type_string script);
  }

  public class Class_repl_from_script : Vx_core.Class_base, Func_repl_from_script {

    public override Vx_repl.Func_repl_from_script vx_new(params Object[] vals) {
      Class_repl_from_script output = new Class_repl_from_script();
      return output;
    }

    public override Vx_repl.Func_repl_from_script vx_copy(params Object[] vals) {
      Class_repl_from_script output = new Class_repl_from_script();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/repl", // pkgname
        "repl<-script", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_from_script;
    }

    public override Vx_core.Type_any vx_type() {
      return t_repl_from_script;
    }

    public Vx_core.Func_any_from_any vx_fn_new(Vx_core.Class_any_from_any.IFn fn) {
      return Vx_core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_core.Type_string inputval = (Vx_core.Type_string)value;
      Vx_core.Type_any outputval = Vx_repl.f_repl_from_script(inputval);
      output = Vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_string script = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_repl.f_repl_from_script(script);
      return output;
    }

    public Vx_repl.Type_repl vx_repl_from_script(Vx_core.Type_string script) {
      return Vx_repl.f_repl_from_script(script);
    }

  }

  public static Func_repl_from_script e_repl_from_script = new Vx_repl.Class_repl_from_script();
  public static Func_repl_from_script t_repl_from_script = new Vx_repl.Class_repl_from_script();

  public static Vx_repl.Type_repl f_repl_from_script(Vx_core.Type_string script) {
    Vx_repl.Type_repl output = Vx_repl.e_repl;
    output = Vx_core.f_let(
      Vx_repl.t_repl,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_data_textblock.Type_textblock textblock = Vx_repl.f_textblock_from_script(script);
        return Vx_repl.f_repl_from_textblock(textblock);
      })
    );
    return output;
  }

  /**
   * @function repl_from_string_argmap
   * Returns a function, type, const or primitive from given string.
   * @param  {string} text
   * @param  {argmap} argmap
   * @return {repl}
   * (func repl<-string-argmap)
   */
  public interface Func_repl_from_string_argmap : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_repl.Type_repl vx_repl_from_string_argmap(Vx_core.Type_string text, Vx_core.Type_argmap argmap);
  }

  public class Class_repl_from_string_argmap : Vx_core.Class_base, Func_repl_from_string_argmap {

    public override Vx_repl.Func_repl_from_string_argmap vx_new(params Object[] vals) {
      Class_repl_from_string_argmap output = new Class_repl_from_string_argmap();
      return output;
    }

    public override Vx_repl.Func_repl_from_string_argmap vx_copy(params Object[] vals) {
      Class_repl_from_string_argmap output = new Class_repl_from_string_argmap();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/repl", // pkgname
        "repl<-string-argmap", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_from_string_argmap;
    }

    public override Vx_core.Type_any vx_type() {
      return t_repl_from_string_argmap;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_string text = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_argmap argmap = Vx_core.f_any_from_any(Vx_core.t_argmap, arglist.vx_any(Vx_core.vx_new_int(1)));
      output = Vx_repl.f_repl_from_string_argmap(text, argmap);
      return output;
    }

    public Vx_repl.Type_repl vx_repl_from_string_argmap(Vx_core.Type_string text, Vx_core.Type_argmap argmap) {
      return Vx_repl.f_repl_from_string_argmap(text, argmap);
    }

  }

  public static Func_repl_from_string_argmap e_repl_from_string_argmap = new Vx_repl.Class_repl_from_string_argmap();
  public static Func_repl_from_string_argmap t_repl_from_string_argmap = new Vx_repl.Class_repl_from_string_argmap();

  public static Vx_repl.Type_repl f_repl_from_string_argmap(Vx_core.Type_string text, Vx_core.Type_argmap argmap) {
    Vx_repl.Type_repl output = Vx_repl.e_repl;
    output = Vx_core.f_if_2(
      Vx_repl.t_repl,
      Vx_core.vx_new(Vx_core.t_thenelselist,
        Vx_core.f_then(
          Vx_core.t_boolean_from_func.vx_fn_new(() => {
            return Vx_core.f_and(
              Vx_type.f_boolean_from_string_starts(
                text,
                Vx_core.c_quote
              ),
              Vx_type.f_boolean_from_string_ends(
                text,
                Vx_core.c_quote
              )
            );
          }),
          Vx_core.t_any_from_func.vx_fn_new(() => {
            return Vx_core.f_new(
              Vx_repl.t_repl,
              Vx_core.vx_new(Vx_core.t_anylist,
                  Vx_core.vx_new_string(":val"),
                  Vx_type.f_string_from_string_start_end(text, Vx_core.vx_new_int(2), Vx_core.vx_new_int(-1))
              )
            );
          })
        ),
        Vx_core.f_then(
          Vx_core.t_boolean_from_func.vx_fn_new(() => {
            return Vx_core.f_is_int(text);
          }),
          Vx_core.t_any_from_func.vx_fn_new(() => {
            return Vx_core.f_new(
              Vx_repl.t_repl,
              Vx_core.vx_new(Vx_core.t_anylist,
                  Vx_core.vx_new_string(":val"),
                  Vx_core.f_int_from_string(text)
              )
            );
          })
        ),
        Vx_core.f_then(
          Vx_core.t_boolean_from_func.vx_fn_new(() => {
            return Vx_core.f_is_float(text);
          }),
          Vx_core.t_any_from_func.vx_fn_new(() => {
            return Vx_core.f_new(
              Vx_repl.t_repl,
              Vx_core.vx_new(Vx_core.t_anylist,
                  Vx_core.vx_new_string(":val"),
                  Vx_core.f_float_from_string(text)
              )
            );
          })
        ),
        Vx_core.f_else(
          Vx_core.t_any_from_func.vx_fn_new(() => {
            return Vx_core.f_let(
              Vx_repl.t_repl,
              Vx_core.t_any_from_func.vx_fn_new(() => {
                Vx_core.Type_any arg = Vx_core.f_any_from_map(Vx_core.t_any, argmap, text);
                return Vx_core.f_if_2(
                  Vx_repl.t_repl,
                  Vx_core.vx_new(Vx_core.t_thenelselist,
                    Vx_core.f_then(
                      Vx_core.t_boolean_from_func.vx_fn_new(() => {
                        return Vx_core.f_notempty_1(arg);
                      }),
                      Vx_core.t_any_from_func.vx_fn_new(() => {
                        return Vx_core.f_new(
                          Vx_repl.t_repl,
                          Vx_core.vx_new(Vx_core.t_anylist,
                              Vx_core.vx_new_string(":val"),
                              arg
                          )
                        );
                      })
                    ),
                    Vx_core.f_else(
                      Vx_core.t_any_from_func.vx_fn_new(() => {
                        return Vx_core.f_let(
                          Vx_repl.t_repl,
                          Vx_core.t_any_from_func.vx_fn_new(() => {
                            Vx_core.Type_any cnst = Vx_repl.f_const_from_string(text);
                            return Vx_core.f_if_2(
                              Vx_repl.t_repl,
                              Vx_core.vx_new(Vx_core.t_thenelselist,
                                Vx_core.f_then(
                                  Vx_core.t_boolean_from_func.vx_fn_new(() => {
                                    return Vx_core.f_notempty_1(cnst);
                                  }),
                                  Vx_core.t_any_from_func.vx_fn_new(() => {
                                    return Vx_core.f_new(
                                      Vx_repl.t_repl,
                                      Vx_core.vx_new(Vx_core.t_anylist,
                                          Vx_core.vx_new_string(":val"),
                                          cnst
                                      )
                                    );
                                  })
                                ),
                                Vx_core.f_else(
                                  Vx_core.t_any_from_func.vx_fn_new(() => {
                                    return Vx_core.f_let(
                                      Vx_repl.t_repl,
                                      Vx_core.t_any_from_func.vx_fn_new(() => {
                                        Vx_core.Type_any typefunc = Vx_repl.f_typefunc_from_string(text);
                                        return Vx_core.f_if_2(
                                          Vx_repl.t_repl,
                                          Vx_core.vx_new(Vx_core.t_thenelselist,
                                            Vx_core.f_then(
                                              Vx_core.t_boolean_from_func.vx_fn_new(() => {
                                                return Vx_core.f_notempty_1(typefunc);
                                              }),
                                              Vx_core.t_any_from_func.vx_fn_new(() => {
                                                return Vx_core.f_new(
                                                  Vx_repl.t_repl,
                                                  Vx_core.vx_new(Vx_core.t_anylist,
                                                      Vx_core.vx_new_string(":type"),
                                                      typefunc
                                                  )
                                                );
                                              })
                                            ),
                                            Vx_core.f_else(
                                              Vx_core.t_any_from_func.vx_fn_new(() => {
                                                return Vx_core.f_new(
                                                  Vx_repl.t_repl,
                                                  Vx_core.vx_new(Vx_core.t_anylist,
                                                      Vx_core.f_msg_from_error_1(Vx_core.vx_new_string(":repltypenotfound"), text)
                                                  )
                                                );
                                              })
                                            )
                                          )
                                        );
                                      })
                                    );
                                  })
                                )
                              )
                            );
                          })
                        );
                      })
                    )
                  )
                );
              })
            );
          })
        )
      )
    );
    return output;
  }

  /**
   * @function repl_from_textblock
   * Returns a repl from a parsed textblock
   * @param  {textblock} textblock
   * @return {repl}
   * (func repl<-textblock)
   */
  public interface Func_repl_from_textblock : Vx_core.Func_any_from_any {
    public Vx_repl.Type_repl vx_repl_from_textblock(Vx_data_textblock.Type_textblock textblock);
  }

  public class Class_repl_from_textblock : Vx_core.Class_base, Func_repl_from_textblock {

    public override Vx_repl.Func_repl_from_textblock vx_new(params Object[] vals) {
      Class_repl_from_textblock output = new Class_repl_from_textblock();
      return output;
    }

    public override Vx_repl.Func_repl_from_textblock vx_copy(params Object[] vals) {
      Class_repl_from_textblock output = new Class_repl_from_textblock();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/repl", // pkgname
        "repl<-textblock", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_from_textblock;
    }

    public override Vx_core.Type_any vx_type() {
      return t_repl_from_textblock;
    }

    public Vx_core.Func_any_from_any vx_fn_new(Vx_core.Class_any_from_any.IFn fn) {
      return Vx_core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_data_textblock.Type_textblock inputval = (Vx_data_textblock.Type_textblock)value;
      Vx_core.Type_any outputval = Vx_repl.f_repl_from_textblock(inputval);
      output = Vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_data_textblock.Type_textblock textblock = Vx_core.f_any_from_any(Vx_data_textblock.t_textblock, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_repl.f_repl_from_textblock(textblock);
      return output;
    }

    public Vx_repl.Type_repl vx_repl_from_textblock(Vx_data_textblock.Type_textblock textblock) {
      return Vx_repl.f_repl_from_textblock(textblock);
    }

  }

  public static Func_repl_from_textblock e_repl_from_textblock = new Vx_repl.Class_repl_from_textblock();
  public static Func_repl_from_textblock t_repl_from_textblock = new Vx_repl.Class_repl_from_textblock();

  public static Vx_repl.Type_repl f_repl_from_textblock(Vx_data_textblock.Type_textblock textblock) {
    Vx_repl.Type_repl output = Vx_repl.e_repl;
    output = Vx_repl.f_repl_from_textblock_argmap(
      textblock,
      Vx_core.f_empty(
        Vx_core.t_argmap
      )
    );
    return output;
  }

  /**
   * @function repl_from_textblock_argmap
   * Returns a repl from a parsed textblock
   * @param  {textblock} textblock
   * @param  {argmap} argmap
   * @return {repl}
   * (func repl<-textblock-argmap)
   */
  public interface Func_repl_from_textblock_argmap : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_repl.Type_repl vx_repl_from_textblock_argmap(Vx_data_textblock.Type_textblock textblock, Vx_core.Type_argmap argmap);
  }

  public class Class_repl_from_textblock_argmap : Vx_core.Class_base, Func_repl_from_textblock_argmap {

    public override Vx_repl.Func_repl_from_textblock_argmap vx_new(params Object[] vals) {
      Class_repl_from_textblock_argmap output = new Class_repl_from_textblock_argmap();
      return output;
    }

    public override Vx_repl.Func_repl_from_textblock_argmap vx_copy(params Object[] vals) {
      Class_repl_from_textblock_argmap output = new Class_repl_from_textblock_argmap();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/repl", // pkgname
        "repl<-textblock-argmap", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_from_textblock_argmap;
    }

    public override Vx_core.Type_any vx_type() {
      return t_repl_from_textblock_argmap;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_data_textblock.Type_textblock textblock = Vx_core.f_any_from_any(Vx_data_textblock.t_textblock, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_argmap argmap = Vx_core.f_any_from_any(Vx_core.t_argmap, arglist.vx_any(Vx_core.vx_new_int(1)));
      output = Vx_repl.f_repl_from_textblock_argmap(textblock, argmap);
      return output;
    }

    public Vx_repl.Type_repl vx_repl_from_textblock_argmap(Vx_data_textblock.Type_textblock textblock, Vx_core.Type_argmap argmap) {
      return Vx_repl.f_repl_from_textblock_argmap(textblock, argmap);
    }

  }

  public static Func_repl_from_textblock_argmap e_repl_from_textblock_argmap = new Vx_repl.Class_repl_from_textblock_argmap();
  public static Func_repl_from_textblock_argmap t_repl_from_textblock_argmap = new Vx_repl.Class_repl_from_textblock_argmap();

  public static Vx_repl.Type_repl f_repl_from_textblock_argmap(Vx_data_textblock.Type_textblock textblock, Vx_core.Type_argmap argmap) {
    Vx_repl.Type_repl output = Vx_repl.e_repl;
    output = Vx_core.f_let(
      Vx_repl.t_repl,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_data_textblock.Type_delim delim = textblock.delim();
        Vx_core.Type_string starttext = delim.starttext();
        return Vx_core.f_switch(
          Vx_repl.t_repl,
          starttext,
          Vx_core.vx_new(Vx_core.t_thenelselist,
            Vx_core.f_case_1(
              Vx_core.vx_new_string(""),
              Vx_core.t_any_from_func.vx_fn_new(() => {
                return Vx_repl.f_repl_empty_from_textblock_argmap(textblock, argmap);
              })
            ),
            Vx_core.f_case_1(
              Vx_data_textblock.c_delimparen.starttext(),
              Vx_core.t_any_from_func.vx_fn_new(() => {
                return Vx_repl.f_repl_paren_from_textblock_argmap(textblock, argmap);
              })
            ),
            Vx_core.f_case_1(
              Vx_data_textblock.c_delimbracketsquare.starttext(),
              Vx_core.t_any_from_func.vx_fn_new(() => {
                return Vx_repl.f_repl_bracket_from_textblock_argmap(textblock, argmap);
              })
            )
          )
        );
      })
    );
    return output;
  }

  /**
   * @function replarglist_from_replarglist_textblock_argmap
   * Returns a modified replarglist from by applying a textblock
   * @param  {replarglist} replargs
   * @param  {textblock} tb
   * @param  {argmap} argmap
   * @return {replarglist}
   * (func replarglist<-replarglist-textblock-argmap)
   */
  public interface Func_replarglist_from_replarglist_textblock_argmap : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_repl.Type_replarglist vx_replarglist_from_replarglist_textblock_argmap(Vx_repl.Type_replarglist replargs, Vx_data_textblock.Type_textblock tb, Vx_core.Type_argmap argmap);
  }

  public class Class_replarglist_from_replarglist_textblock_argmap : Vx_core.Class_base, Func_replarglist_from_replarglist_textblock_argmap {

    public override Vx_repl.Func_replarglist_from_replarglist_textblock_argmap vx_new(params Object[] vals) {
      Class_replarglist_from_replarglist_textblock_argmap output = new Class_replarglist_from_replarglist_textblock_argmap();
      return output;
    }

    public override Vx_repl.Func_replarglist_from_replarglist_textblock_argmap vx_copy(params Object[] vals) {
      Class_replarglist_from_replarglist_textblock_argmap output = new Class_replarglist_from_replarglist_textblock_argmap();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/repl", // pkgname
        "replarglist<-replarglist-textblock-argmap", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/repl", // pkgname
          "replarglist", // name
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
      return e_replarglist_from_replarglist_textblock_argmap;
    }

    public override Vx_core.Type_any vx_type() {
      return t_replarglist_from_replarglist_textblock_argmap;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_repl.Type_replarglist replargs = Vx_core.f_any_from_any(Vx_repl.t_replarglist, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_data_textblock.Type_textblock tb = Vx_core.f_any_from_any(Vx_data_textblock.t_textblock, arglist.vx_any(Vx_core.vx_new_int(1)));
      Vx_core.Type_argmap argmap = Vx_core.f_any_from_any(Vx_core.t_argmap, arglist.vx_any(Vx_core.vx_new_int(2)));
      output = Vx_repl.f_replarglist_from_replarglist_textblock_argmap(replargs, tb, argmap);
      return output;
    }

    public Vx_repl.Type_replarglist vx_replarglist_from_replarglist_textblock_argmap(Vx_repl.Type_replarglist replargs, Vx_data_textblock.Type_textblock tb, Vx_core.Type_argmap argmap) {
      return Vx_repl.f_replarglist_from_replarglist_textblock_argmap(replargs, tb, argmap);
    }

  }

  public static Func_replarglist_from_replarglist_textblock_argmap e_replarglist_from_replarglist_textblock_argmap = new Vx_repl.Class_replarglist_from_replarglist_textblock_argmap();
  public static Func_replarglist_from_replarglist_textblock_argmap t_replarglist_from_replarglist_textblock_argmap = new Vx_repl.Class_replarglist_from_replarglist_textblock_argmap();

  public static Vx_repl.Type_replarglist f_replarglist_from_replarglist_textblock_argmap(Vx_repl.Type_replarglist replargs, Vx_data_textblock.Type_textblock tb, Vx_core.Type_argmap argmap) {
    Vx_repl.Type_replarglist output = Vx_repl.e_replarglist;
    output = Vx_core.f_let(
      Vx_repl.t_replarglist,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_core.Type_string key = replargs.key();
        Vx_repl.Type_repl current = replargs.current();
        Vx_repl.Type_repllist repllist = replargs.repllist();
        Vx_repl.Type_repllist currlist = current.repllist();
        Vx_core.Type_string text = Vx_data_textblock.t_textblock.text();
        return Vx_core.f_if_2(
          Vx_repl.t_replarglist,
          Vx_core.vx_new(Vx_core.t_thenelselist,
            Vx_core.f_then(
              Vx_core.t_boolean_from_func.vx_fn_new(() => {
                return Vx_core.f_eq(key, Vx_core.vx_new_string(""));
              }),
              Vx_core.t_any_from_func.vx_fn_new(() => {
                return Vx_core.f_if_2(
                  Vx_repl.t_replarglist,
                  Vx_core.vx_new(Vx_core.t_thenelselist,
                      Vx_core.f_then(
                        Vx_core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx_core.f_eq_1(Vx_core.vx_new(Vx_core.t_anylist,
                            text));
                        }),
                        Vx_core.t_any_from_func.vx_fn_new(() => {
                          return Vx_core.f_copy(
                            replargs,
                            Vx_core.vx_new(Vx_core.t_anylist,
                                Vx_core.vx_new_string(":key"),
                                text
                            )
                          );
                        })
                      ),
                      Vx_core.f_then(
                        Vx_core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx_core.f_eq(text, Vx_core.vx_new_string(":="));
                        }),
                        Vx_core.t_any_from_func.vx_fn_new(() => {
                          return Vx_core.f_copy(
                            replargs,
                            Vx_core.vx_new(Vx_core.t_anylist,
                                Vx_core.vx_new_string(":key"),
                                text
                            )
                          );
                        })
                      ),
                      Vx_core.f_then(
                        Vx_core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx_core.f_eq(text, Vx_core.vx_new_string(":doc"));
                        }),
                        Vx_core.t_any_from_func.vx_fn_new(() => {
                          return Vx_core.f_copy(
                            replargs,
                            Vx_core.vx_new(Vx_core.t_anylist,
                                Vx_core.vx_new_string(":key"),
                                text
                            )
                          );
                        })
                      ),
                      Vx_core.f_else(
                        Vx_core.t_any_from_func.vx_fn_new(() => {
                          return Vx_core.f_copy(
                            replargs,
                            Vx_core.vx_new(Vx_core.t_anylist,
                                Vx_core.vx_new_string(":current"),
                                Vx_core.f_new(
                                  Vx_repl.t_repl,
                                  Vx_core.vx_new(Vx_core.t_anylist,
                                    Vx_core.vx_new_string(":name"),
                                    text
                                  )
                                ),
                                Vx_core.vx_new_string(":repllist"),
                                Vx_core.f_copy(repllist, Vx_core.vx_new(Vx_core.t_anylist,
                                  current))
                            )
                          );
                        })
                      )
                  )
                );
              })
            ),
            Vx_core.f_then(
              Vx_core.t_boolean_from_func.vx_fn_new(() => {
                return Vx_core.f_eq_1(Vx_core.vx_new(Vx_core.t_anylist,
                  key));
              }),
              Vx_core.t_any_from_func.vx_fn_new(() => {
                return Vx_core.f_copy(
                  replargs,
                  Vx_core.vx_new(Vx_core.t_anylist,
                      Vx_core.vx_new_string(":key"),
                      Vx_core.vx_new_string(""),
                      Vx_core.vx_new_string(":current"),
                      Vx_core.f_copy(
                        current,
                        Vx_core.vx_new(Vx_core.t_anylist,
                          Vx_core.vx_new_string(":type"),
                          text
                        )
                      )
                  )
                );
              })
            ),
            Vx_core.f_then(
              Vx_core.t_boolean_from_func.vx_fn_new(() => {
                return Vx_core.f_eq(key, Vx_core.vx_new_string(":="));
              }),
              Vx_core.t_any_from_func.vx_fn_new(() => {
                return Vx_core.f_copy(
                  replargs,
                  Vx_core.vx_new(Vx_core.t_anylist,
                      Vx_core.vx_new_string(":key"),
                      Vx_core.vx_new_string(""),
                      Vx_core.vx_new_string(":current"),
                      Vx_core.f_copy(
                        current,
                        Vx_core.vx_new(Vx_core.t_anylist,
                          Vx_core.vx_new_string(":repllist"),
                          Vx_core.f_copy(
                            currlist,
                            Vx_core.vx_new(Vx_core.t_anylist,
                              Vx_repl.f_repl_from_textblock_argmap(tb, argmap)
                            )
                          )
                        )
                      )
                  )
                );
              })
            ),
            Vx_core.f_then(
              Vx_core.t_boolean_from_func.vx_fn_new(() => {
                return Vx_core.f_eq(key, Vx_core.vx_new_string(":doc"));
              }),
              Vx_core.t_any_from_func.vx_fn_new(() => {
                return Vx_core.f_copy(
                  replargs,
                  Vx_core.vx_new(Vx_core.t_anylist,
                      Vx_core.vx_new_string(":key"),
                      Vx_core.vx_new_string(""),
                      Vx_core.vx_new_string(":current"),
                      Vx_core.f_copy(
                        current,
                        Vx_core.vx_new(Vx_core.t_anylist,
                          Vx_core.vx_new_string(":doc"),
                          text
                        )
                      )
                  )
                );
              })
            ),
            Vx_core.f_else(
              Vx_core.t_any_from_func.vx_fn_new(() => {
                return replargs;
              })
            )
          )
        );
      })
    );
    return output;
  }

  /**
   * @function repllist_from_textblocklist_argmap
   * Returns a repllist from a parsed textblocklist
   * @param  {textblocklist} textblocklist
   * @param  {argmap} argmap
   * @return {repllist}
   * (func repllist<-textblocklist-argmap)
   */
  public interface Func_repllist_from_textblocklist_argmap : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_repl.Type_repllist vx_repllist_from_textblocklist_argmap(Vx_data_textblock.Type_textblocklist textblocklist, Vx_core.Type_argmap argmap);
  }

  public class Class_repllist_from_textblocklist_argmap : Vx_core.Class_base, Func_repllist_from_textblocklist_argmap {

    public override Vx_repl.Func_repllist_from_textblocklist_argmap vx_new(params Object[] vals) {
      Class_repllist_from_textblocklist_argmap output = new Class_repllist_from_textblocklist_argmap();
      return output;
    }

    public override Vx_repl.Func_repllist_from_textblocklist_argmap vx_copy(params Object[] vals) {
      Class_repllist_from_textblocklist_argmap output = new Class_repllist_from_textblocklist_argmap();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/repl", // pkgname
        "repllist<-textblocklist-argmap", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/repl", // pkgname
          "repllist", // name
          ":list", // extends
          Vx_core.e_typelist, // traits
          Vx_core.vx_new(Vx_core.t_typelist, Vx_repl.t_repl), // allowtypes
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
      return e_repllist_from_textblocklist_argmap;
    }

    public override Vx_core.Type_any vx_type() {
      return t_repllist_from_textblocklist_argmap;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_data_textblock.Type_textblocklist textblocklist = Vx_core.f_any_from_any(Vx_data_textblock.t_textblocklist, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_argmap argmap = Vx_core.f_any_from_any(Vx_core.t_argmap, arglist.vx_any(Vx_core.vx_new_int(1)));
      output = Vx_repl.f_repllist_from_textblocklist_argmap(textblocklist, argmap);
      return output;
    }

    public Vx_repl.Type_repllist vx_repllist_from_textblocklist_argmap(Vx_data_textblock.Type_textblocklist textblocklist, Vx_core.Type_argmap argmap) {
      return Vx_repl.f_repllist_from_textblocklist_argmap(textblocklist, argmap);
    }

  }

  public static Func_repllist_from_textblocklist_argmap e_repllist_from_textblocklist_argmap = new Vx_repl.Class_repllist_from_textblocklist_argmap();
  public static Func_repllist_from_textblocklist_argmap t_repllist_from_textblocklist_argmap = new Vx_repl.Class_repllist_from_textblocklist_argmap();

  public static Vx_repl.Type_repllist f_repllist_from_textblocklist_argmap(Vx_data_textblock.Type_textblocklist textblocklist, Vx_core.Type_argmap argmap) {
    Vx_repl.Type_repllist output = Vx_repl.e_repllist;
    output = Vx_core.f_list_from_list_1(
      Vx_repl.t_repllist,
      textblocklist,
      Vx_core.t_any_from_any.vx_fn_new((textblock_any) => {
        Vx_data_textblock.Type_textblock textblock = Vx_core.f_any_from_any(Vx_data_textblock.t_textblock, textblock_any);
        return 
        Vx_repl.f_repl_from_textblock(textblock);
      })
    );
    return output;
  }

  /**
   * @function textblock_from_script
   * Returns a parsed textblock from a string
   * @param  {string} script
   * @return {textblock}
   * (func textblock<-script)
   */
  public interface Func_textblock_from_script : Vx_core.Func_any_from_any {
    public Vx_data_textblock.Type_textblock vx_textblock_from_script(Vx_core.Type_string script);
  }

  public class Class_textblock_from_script : Vx_core.Class_base, Func_textblock_from_script {

    public override Vx_repl.Func_textblock_from_script vx_new(params Object[] vals) {
      Class_textblock_from_script output = new Class_textblock_from_script();
      return output;
    }

    public override Vx_repl.Func_textblock_from_script vx_copy(params Object[] vals) {
      Class_textblock_from_script output = new Class_textblock_from_script();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/repl", // pkgname
        "textblock<-script", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
      return e_textblock_from_script;
    }

    public override Vx_core.Type_any vx_type() {
      return t_textblock_from_script;
    }

    public Vx_core.Func_any_from_any vx_fn_new(Vx_core.Class_any_from_any.IFn fn) {
      return Vx_core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_core.Type_string inputval = (Vx_core.Type_string)value;
      Vx_core.Type_any outputval = Vx_repl.f_textblock_from_script(inputval);
      output = Vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_string script = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_repl.f_textblock_from_script(script);
      return output;
    }

    public Vx_data_textblock.Type_textblock vx_textblock_from_script(Vx_core.Type_string script) {
      return Vx_repl.f_textblock_from_script(script);
    }

  }

  public static Func_textblock_from_script e_textblock_from_script = new Vx_repl.Class_textblock_from_script();
  public static Func_textblock_from_script t_textblock_from_script = new Vx_repl.Class_textblock_from_script();

  public static Vx_data_textblock.Type_textblock f_textblock_from_script(Vx_core.Type_string script) {
    Vx_data_textblock.Type_textblock output = Vx_data_textblock.e_textblock;
    output = Vx_data_textblock.f_textblock_parse_from_string_delim(
      script,
      Vx_repl.c_delimvxlisp
    );
    return output;
  }

  /**
   * @function typefunc_from_string
   * Returns a type, or func from a fully qualified name.
   * @param  {string} text
   * @return {any}
   * (func typefunc<-string)
   */
  public interface Func_typefunc_from_string : Vx_core.Func_any_from_any {
    public Vx_core.Type_any vx_typefunc_from_string(Vx_core.Type_string text);
  }

  public class Class_typefunc_from_string : Vx_core.Class_base, Func_typefunc_from_string {

    public override Vx_repl.Func_typefunc_from_string vx_new(params Object[] vals) {
      Class_typefunc_from_string output = new Class_typefunc_from_string();
      return output;
    }

    public override Vx_repl.Func_typefunc_from_string vx_copy(params Object[] vals) {
      Class_typefunc_from_string output = new Class_typefunc_from_string();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/repl", // pkgname
        "typefunc<-string", // name
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
      return e_typefunc_from_string;
    }

    public override Vx_core.Type_any vx_type() {
      return t_typefunc_from_string;
    }

    public Vx_core.Func_any_from_any vx_fn_new(Vx_core.Class_any_from_any.IFn fn) {
      return Vx_core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_core.Type_string inputval = (Vx_core.Type_string)value;
      Vx_core.Type_any outputval = Vx_repl.f_typefunc_from_string(inputval);
      output = Vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_string text = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_repl.f_typefunc_from_string(text);
      return output;
    }

    public Vx_core.Type_any vx_typefunc_from_string(Vx_core.Type_string text) {
      return Vx_repl.f_typefunc_from_string(text);
    }

  }

  public static Func_typefunc_from_string e_typefunc_from_string = new Vx_repl.Class_typefunc_from_string();
  public static Func_typefunc_from_string t_typefunc_from_string = new Vx_repl.Class_typefunc_from_string();

  public static Vx_core.Type_any f_typefunc_from_string(Vx_core.Type_string text) {
    Vx_core.Type_any output = Vx_core.e_any;
    output = Vx_core.f_let(
      Vx_core.t_any,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_core.Type_int pkgpos = Vx_type.f_int_from_string_findlast(text, Vx_core.vx_new_string("/"));
        Vx_core.Type_string pkgname = Vx_core.f_if_1(
          Vx_core.t_string,
          Vx_core.f_eq(Vx_core.vx_new_int(0), pkgpos),
          Vx_core.vx_new_string("vx/core"),
          Vx_type.f_string_from_string_end(
            text,
            Vx_core.f_minus1(pkgpos)
          )
        );
        Vx_core.Type_string name = Vx_core.f_if_1(
          Vx_core.t_string,
          Vx_core.f_eq(Vx_core.vx_new_int(0), pkgpos),
          text,
          Vx_type.f_string_from_string_start(
            text,
            Vx_core.f_plus1(pkgpos)
          )
        );
        Vx_core.Type_package pkg = Vx_core.f_package_global_from_name(pkgname);
        Vx_core.Type_typemap typemap = pkg.typemap();
        Vx_core.Type_any typeval = Vx_core.f_any_from_map(Vx_core.t_any, typemap, name);
        return Vx_core.f_if_1(
          Vx_core.t_any,
          Vx_core.f_notempty_1(typeval),
          typeval,
          Vx_core.f_let(
            Vx_core.t_any,
            Vx_core.t_any_from_func.vx_fn_new(() => {
              Vx_core.Type_funcmap funcmap = pkg.funcmap();
              Vx_core.Type_any funcval = Vx_core.f_any_from_map(Vx_core.t_any, funcmap, name);
              return Vx_core.f_if_1(
                Vx_core.t_any,
                Vx_core.f_notempty_1(funcval),
                funcval,
                Vx_core.f_empty(
                  Vx_core.t_any
                )
              );
            })
          )
        );
      })
    );
    return output;
  }


  public static class PackageRunOnce {
    public static void RunOnce() {
    Const_delimvxlisp.const_new(c_delimvxlisp);
    Const_delimvxlispbracket.const_new(c_delimvxlispbracket);
    Const_delimvxlispparen.const_new(c_delimvxlispparen);
    Vx_core.Map<string, Vx_core.Type_any> maptype = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
    Vx_core.Map<string, Vx_core.Type_any> mapconst = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
    Vx_core.Map<string, Vx_core.Type_func> mapfunc = new Vx_core.LinkedHashMap<string, Vx_core.Type_func>();
    maptype.put("liblist", Vx_repl.t_liblist);
    maptype.put("repl", Vx_repl.t_repl);
    maptype.put("replarglist", Vx_repl.t_replarglist);
    maptype.put("repllist", Vx_repl.t_repllist);
    mapconst.put("delimvxlisp", Vx_repl.c_delimvxlisp);
    mapconst.put("delimvxlispbracket", Vx_repl.c_delimvxlispbracket);
    mapconst.put("delimvxlispparen", Vx_repl.c_delimvxlispparen);
    mapfunc.put("any-repl<-functype-args", Vx_repl.t_any_repl_from_functype_args);
    mapfunc.put("any<-liblist-string", Vx_repl.t_any_from_liblist_string);
    mapfunc.put("any<-macro", Vx_repl.t_any_from_macro);
    mapfunc.put("any<-repl", Vx_repl.t_any_from_repl);
    mapfunc.put("any<-script", Vx_repl.t_any_from_script);
    mapfunc.put("anylist<-repllist", Vx_repl.t_anylist_from_repllist);
    mapfunc.put("argmap<-textblock-argmap", Vx_repl.t_argmap_from_textblock_argmap);
    mapfunc.put("const<-string", Vx_repl.t_const_from_string);
    mapfunc.put("repl-bracket<-textblock-argmap", Vx_repl.t_repl_bracket_from_textblock_argmap);
    mapfunc.put("repl-empty<-textblock-argmap", Vx_repl.t_repl_empty_from_textblock_argmap);
    mapfunc.put("repl-paren<-textblock-argmap", Vx_repl.t_repl_paren_from_textblock_argmap);
    mapfunc.put("repl<-liblist-string", Vx_repl.t_repl_from_liblist_string);
    mapfunc.put("repl<-macro", Vx_repl.t_repl_from_macro);
    mapfunc.put("repl<-script", Vx_repl.t_repl_from_script);
    mapfunc.put("repl<-string-argmap", Vx_repl.t_repl_from_string_argmap);
    mapfunc.put("repl<-textblock", Vx_repl.t_repl_from_textblock);
    mapfunc.put("repl<-textblock-argmap", Vx_repl.t_repl_from_textblock_argmap);
    mapfunc.put("replarglist<-replarglist-textblock-argmap", Vx_repl.t_replarglist_from_replarglist_textblock_argmap);
    mapfunc.put("repllist<-textblocklist-argmap", Vx_repl.t_repllist_from_textblocklist_argmap);
    mapfunc.put("textblock<-script", Vx_repl.t_textblock_from_script);
    mapfunc.put("typefunc<-string", Vx_repl.t_typefunc_from_string);
    Vx_core.vx_global_package_set("vx/repl", maptype, mapconst, mapfunc);
    }
  }

}
