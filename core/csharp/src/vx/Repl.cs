namespace Vx;

public static class Repl {


  /**
   * type: liblist
   * List of library names
   * (type liblist)
   */
  public interface Type_liblist : Vx.Core.Type_list {
    public List<Vx.Core.Type_string> vx_liststring();
    public Vx.Core.Type_string vx_string(Vx.Core.Type_int index);
  }

  public class Class_liblist : Vx.Core.Class_base, Type_liblist {

    public List<Vx.Core.Type_string> vx_p_list = Vx.Core.immutablelist(new List<Vx.Core.Type_string>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Core.Type_string vx_string(Vx.Core.Type_int index) {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Repl.Class_liblist list = this;
      int iindex = index.vx_int();
      List<Vx.Core.Type_string> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Core.Type_string> vx_liststring() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_string(index);
    }

    public override Vx.Repl.Type_liblist vx_new(params Object[] vals) {
      Vx.Repl.Type_liblist output = Vx.Core.vx_copy(Vx.Repl.e_liblist, vals);
      return output;
    }

    public override Vx.Repl.Type_liblist vx_copy(params Object[] vals) {
      Type_liblist output = this;
      bool ischanged = false;
      Class_liblist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Core.Type_string> listval = new List<Vx.Core.Type_string>(val.vx_liststring());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_string allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Core.Type_string) {
          ischanged = true;
          listval.Add(Vx.Core.vx_new(Vx.Core.t_string, valsub));
        } else if (valsub is Vx.Repl.Type_liblist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_liststring());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (false) {
            } else if (item is Vx.Core.Type_string valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/repl/liblist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/repl/liblist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_liblist work = new Class_liblist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_liblist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_liblist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/repl", // pkgname
        "liblist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_string), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_repl : Vx.Core.Type_struct {
    public Vx.Core.Type_string name();
    public Vx.Core.Type_any type();
    public Vx.Repl.Type_repllist repllist();
    public Vx.Core.Type_boolean async();
    public Vx.Core.Type_any val();
    public Vx.Core.Type_string doc();
  }

  public class Class_repl : Vx.Core.Class_base, Type_repl {

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Vx.Core.Type_any? vx_p_type = null;

    public Vx.Core.Type_any type() {
      Vx.Core.Type_any output = Vx.Core.e_any;
      if (this.vx_p_type != null) {
        output = this.vx_p_type;
      }
      return output;
    }

    public Vx.Repl.Type_repllist? vx_p_repllist = null;

    public Vx.Repl.Type_repllist repllist() {
      Vx.Repl.Type_repllist output = Vx.Repl.e_repllist;
      if (this.vx_p_repllist != null) {
        output = this.vx_p_repllist;
      }
      return output;
    }

    public Vx.Core.Type_boolean? vx_p_async = null;

    public Vx.Core.Type_boolean async() {
      Vx.Core.Type_boolean output = Vx.Core.e_boolean;
      if (this.vx_p_async != null) {
        output = this.vx_p_async;
      }
      return output;
    }

    public Vx.Core.Type_any? vx_p_val = null;

    public Vx.Core.Type_any val() {
      Vx.Core.Type_any output = Vx.Core.e_any;
      if (this.vx_p_val != null) {
        output = this.vx_p_val;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_doc = null;

    public Vx.Core.Type_string doc() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_doc != null) {
        output = this.vx_p_doc;
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":name", this.name());
      output.put(":type", this.type());
      output.put(":repllist", this.repllist());
      output.put(":async", this.async());
      output.put(":val", this.val());
      output.put(":doc", this.doc());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Repl.Type_repl vx_new(params Object[] vals) {
      Vx.Repl.Type_repl output = Vx.Core.vx_copy(Vx.Repl.e_repl, vals);
      return output;
    }

    public override Vx.Repl.Type_repl vx_copy(params Object[] vals) {
      Type_repl output = this;
      bool ischanged = false;
      Class_repl val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_name = val.name();
      Vx.Core.Type_any vx_p_type = val.type();
      Vx.Repl.Type_repllist vx_p_repllist = val.repllist();
      Vx.Core.Type_boolean vx_p_async = val.async();
      Vx.Core.Type_any vx_p_val = val.val();
      Vx.Core.Type_string vx_p_doc = val.doc();
      List<string> validkeys = new List<string>();
      validkeys.Add(":name");
      validkeys.Add(":type");
      validkeys.Add(":repllist");
      validkeys.Add(":async");
      validkeys.Add(":val");
      validkeys.Add(":doc");
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
            msg = Vx.Core.vx_msg_from_error("vx/repl/repl", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/repl/repl", ":invalidkey", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/repl/repl", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":type":
            if (valsub == vx_p_type) {
            } else if (valsub is Vx.Core.Type_any valtype) {
              ischanged = true;
              vx_p_type = valtype;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("type"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/repl/repl", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":repllist":
            if (valsub == vx_p_repllist) {
            } else if (valsub is Vx.Repl.Type_repllist valrepllist) {
              ischanged = true;
              vx_p_repllist = valrepllist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("repllist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/repl/repl", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":async":
            if (valsub == vx_p_async) {
            } else if (valsub is Vx.Core.Type_boolean valasync) {
              ischanged = true;
              vx_p_async = valasync;
            } else if (valsub is bool) {
              ischanged = true;
              vx_p_async = Vx.Core.vx_new(Vx.Core.t_boolean, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("async"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/repl/repl", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":val":
            if (valsub == vx_p_val) {
            } else if (valsub is Vx.Core.Type_any valval) {
              ischanged = true;
              vx_p_val = valval;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("val"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/repl/repl", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":doc":
            if (valsub == vx_p_doc) {
            } else if (valsub is Vx.Core.Type_string valdoc) {
              ischanged = true;
              vx_p_doc = valdoc;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_doc = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("doc"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/repl/repl", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/repl/repl", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_repl work = new Class_repl();
        work.vx_p_name = vx_p_name;
        work.vx_p_type = vx_p_type;
        work.vx_p_repllist = vx_p_repllist;
        work.vx_p_async = vx_p_async;
        work.vx_p_val = vx_p_val;
        work.vx_p_doc = vx_p_doc;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_repl;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_repl;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/repl", // pkgname
        "repl", // name
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

  public static Type_repl e_repl = new Class_repl();
  public static Type_repl t_repl = new Class_repl();

  /**
   * type: replarglist
   * Builder for a repllist
   * (type replarglist)
   */
  public interface Type_replarglist : Vx.Core.Type_struct {
    public Vx.Core.Type_string key();
    public Vx.Repl.Type_repl current();
    public Vx.Repl.Type_repllist repllist();
  }

  public class Class_replarglist : Vx.Core.Class_base, Type_replarglist {

    public Vx.Core.Type_string? vx_p_key = null;

    public Vx.Core.Type_string key() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_key != null) {
        output = this.vx_p_key;
      }
      return output;
    }

    public Vx.Repl.Type_repl? vx_p_current = null;

    public Vx.Repl.Type_repl current() {
      Vx.Repl.Type_repl output = Vx.Repl.e_repl;
      if (this.vx_p_current != null) {
        output = this.vx_p_current;
      }
      return output;
    }

    public Vx.Repl.Type_repllist? vx_p_repllist = null;

    public Vx.Repl.Type_repllist repllist() {
      Vx.Repl.Type_repllist output = Vx.Repl.e_repllist;
      if (this.vx_p_repllist != null) {
        output = this.vx_p_repllist;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":key", this.key());
      output.put(":current", this.current());
      output.put(":repllist", this.repllist());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Repl.Type_replarglist vx_new(params Object[] vals) {
      Vx.Repl.Type_replarglist output = Vx.Core.vx_copy(Vx.Repl.e_replarglist, vals);
      return output;
    }

    public override Vx.Repl.Type_replarglist vx_copy(params Object[] vals) {
      Type_replarglist output = this;
      bool ischanged = false;
      Class_replarglist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_key = val.key();
      Vx.Repl.Type_repl vx_p_current = val.current();
      Vx.Repl.Type_repllist vx_p_repllist = val.repllist();
      List<string> validkeys = new List<string>();
      validkeys.Add(":key");
      validkeys.Add(":current");
      validkeys.Add(":repllist");
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
            msg = Vx.Core.vx_msg_from_error("vx/repl/replarglist", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/repl/replarglist", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":key":
            if (valsub == vx_p_key) {
            } else if (valsub is Vx.Core.Type_string valkey) {
              ischanged = true;
              vx_p_key = valkey;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_key = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("key"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/repl/replarglist", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":current":
            if (valsub == vx_p_current) {
            } else if (valsub is Vx.Repl.Type_repl valcurrent) {
              ischanged = true;
              vx_p_current = valcurrent;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("current"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/repl/replarglist", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":repllist":
            if (valsub == vx_p_repllist) {
            } else if (valsub is Vx.Repl.Type_repllist valrepllist) {
              ischanged = true;
              vx_p_repllist = valrepllist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("repllist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/repl/replarglist", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/repl/replarglist", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_replarglist work = new Class_replarglist();
        work.vx_p_key = vx_p_key;
        work.vx_p_current = vx_p_current;
        work.vx_p_repllist = vx_p_repllist;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_replarglist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_replarglist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/repl", // pkgname
        "replarglist", // name
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

  public static Type_replarglist e_replarglist = new Class_replarglist();
  public static Type_replarglist t_replarglist = new Class_replarglist();

  /**
   * type: repllist
   * List of repl
   * (type repllist)
   */
  public interface Type_repllist : Vx.Core.Type_list {
    public List<Vx.Repl.Type_repl> vx_listrepl();
    public Vx.Repl.Type_repl vx_repl(Vx.Core.Type_int index);
  }

  public class Class_repllist : Vx.Core.Class_base, Type_repllist {

    public List<Vx.Repl.Type_repl> vx_p_list = Vx.Core.immutablelist(new List<Vx.Repl.Type_repl>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Repl.Type_repl vx_repl(Vx.Core.Type_int index) {
      Vx.Repl.Type_repl output = Vx.Repl.e_repl;
      Vx.Repl.Class_repllist list = this;
      int iindex = index.vx_int();
      List<Vx.Repl.Type_repl> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Repl.Type_repl> vx_listrepl() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_repl(index);
    }

    public override Vx.Repl.Type_repllist vx_new(params Object[] vals) {
      Vx.Repl.Type_repllist output = Vx.Core.vx_copy(Vx.Repl.e_repllist, vals);
      return output;
    }

    public override Vx.Repl.Type_repllist vx_copy(params Object[] vals) {
      Type_repllist output = this;
      bool ischanged = false;
      Class_repllist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Repl.Type_repl> listval = new List<Vx.Repl.Type_repl>(val.vx_listrepl());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Repl.Type_repl allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Repl.Type_repl) {
          ischanged = true;
          listval.Add((Vx.Repl.Type_repl)valsub);
        } else if (valsub is Vx.Repl.Type_repllist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listrepl());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (false) {
            } else if (item is Vx.Repl.Type_repl valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/repl/repllist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/repl/repllist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_repllist work = new Class_repllist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_repllist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_repllist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/repl", // pkgname
        "repllist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Repl.t_repl), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public class Const_delimvxlisp : Vx.Data.Textblock.Class_delim, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/repl", // pkgname
        "delimvxlisp", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimvxlisp output) {
      Vx.Data.Textblock.Type_delim val = Vx.Core.f_new(
        Vx.Data.Textblock.t_delim,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("delimvxlisp"),
                Vx.Core.vx_new_string(":delimlist"),
                Vx.Core.f_new(
                  Vx.Data.Textblock.t_delimlist,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Repl.c_delimvxlispparen,
                    Vx.Data.Textblock.c_delimcomment,
                    Vx.Data.Textblock.c_delimcommentblock
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
  public class Const_delimvxlispbracket : Vx.Data.Textblock.Class_delim, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/repl", // pkgname
        "delimvxlispbracket", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimvxlispbracket output) {
      Vx.Data.Textblock.Type_delim val = Vx.Core.f_copy(
        Vx.Data.Textblock.c_delimbracketsquare,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("delimvxlispbracketsquare"),
                Vx.Core.vx_new_string(":delimlist"),
                Vx.Core.f_new(
                  Vx.Data.Textblock.t_delimlist,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Data.Textblock.c_delimcomment,
                    Vx.Data.Textblock.c_delimcommentblock,
                    Vx.Data.Textblock.c_delimquote,
                    Vx.Data.Textblock.c_delimquoteblock,
                    Vx.Data.Textblock.c_delimwhitespace,
                    Vx.Repl.c_delimvxlispparen
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
  public class Const_delimvxlispparen : Vx.Data.Textblock.Class_delim, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/repl", // pkgname
        "delimvxlispparen", // name
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimvxlispparen output) {
      Vx.Data.Textblock.Type_delim val = Vx.Core.f_copy(
        Vx.Data.Textblock.c_delimparen,
        Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("delimvxlispparen"),
                Vx.Core.vx_new_string(":delimlist"),
                Vx.Core.f_new(
                  Vx.Data.Textblock.t_delimlist,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Data.Textblock.c_delimcomment,
                    Vx.Data.Textblock.c_delimcommentblock,
                    Vx.Data.Textblock.c_delimquote,
                    Vx.Data.Textblock.c_delimquoteblock,
                    Vx.Data.Textblock.c_delimwhitespace,
                    Vx.Repl.c_delimvxlispbracket,
                    Vx.Repl.c_delimvxlispparen
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
  public interface Func_any_repl_from_functype_args : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_any vx_any_repl_from_functype_args(Vx.Core.Type_any type, Vx.Core.Type_anylist args);
  }

  public class Class_any_repl_from_functype_args : Vx.Core.Class_base, Func_any_repl_from_functype_args {

    public override Vx.Repl.Func_any_repl_from_functype_args vx_new(params Object[] vals) {
      Class_any_repl_from_functype_args output = new Class_any_repl_from_functype_args();
      return output;
    }

    public override Vx.Repl.Func_any_repl_from_functype_args vx_copy(params Object[] vals) {
      Class_any_repl_from_functype_args output = new Class_any_repl_from_functype_args();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/repl", // pkgname
        "any-repl<-functype-args", // name
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
      return e_any_repl_from_functype_args;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_repl_from_functype_args;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any type = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_anylist args = Vx.Core.f_any_from_any(Vx.Core.t_anylist, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Repl.f_any_repl_from_functype_args(type, args);
      return output;
    }

    public Vx.Core.Type_any vx_any_repl_from_functype_args(Vx.Core.Type_any type, Vx.Core.Type_anylist args) {
      return Vx.Repl.f_any_repl_from_functype_args(type, args);
    }

  }

  public static Func_any_repl_from_functype_args e_any_repl_from_functype_args = new Vx.Repl.Class_any_repl_from_functype_args();
  public static Func_any_repl_from_functype_args t_any_repl_from_functype_args = new Vx.Repl.Class_any_repl_from_functype_args();

  public static Vx.Core.Type_any f_any_repl_from_functype_args(Vx.Core.Type_any type, Vx.Core.Type_anylist args) {
    Vx.Core.Type_any output = Vx.Core.e_any;
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
  public interface Func_any_from_liblist_string : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_any vx_any_from_liblist_string(Vx.Core.Type_context context, Vx.Repl.Type_liblist liblist, Vx.Core.Type_string text);
  }

  public class Class_any_from_liblist_string : Vx.Core.Class_base, Func_any_from_liblist_string {

    public override Vx.Repl.Func_any_from_liblist_string vx_new(params Object[] vals) {
      Class_any_from_liblist_string output = new Class_any_from_liblist_string();
      return output;
    }

    public override Vx.Repl.Func_any_from_liblist_string vx_copy(params Object[] vals) {
      Class_any_from_liblist_string output = new Class_any_from_liblist_string();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/repl", // pkgname
        "any<-liblist-string", // name
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
      return e_any_from_liblist_string;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_liblist_string;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Repl.Type_liblist liblist = Vx.Core.f_any_from_any(Vx.Repl.t_liblist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Repl.f_any_from_liblist_string(context, liblist, text);
      return output;
    }

    public Vx.Core.Type_any vx_any_from_liblist_string(Vx.Core.Type_context context, Vx.Repl.Type_liblist liblist, Vx.Core.Type_string text) {
      return Vx.Repl.f_any_from_liblist_string(context, liblist, text);
    }

  }

  public static Func_any_from_liblist_string e_any_from_liblist_string = new Vx.Repl.Class_any_from_liblist_string();
  public static Func_any_from_liblist_string t_any_from_liblist_string = new Vx.Repl.Class_any_from_liblist_string();

  public static Vx.Core.Type_any f_any_from_liblist_string(Vx.Core.Type_context context, Vx.Repl.Type_liblist liblist, Vx.Core.Type_string text) {
    Vx.Core.Type_any output = Vx.Core.e_any;
    output = Vx.Core.f_let(
      Vx.Core.t_any,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Repl.Type_repl repl = Vx.Repl.f_repl_from_liblist_string(liblist, text);
        Vx.Core.Type_any output_1 = Vx.Repl.f_any_from_repl(context, repl);
        return output_1;
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
  public interface Func_any_from_macro : Vx.Core.Func_any_from_any_context {
    public T vx_any_from_macro<T>(T generic_any_1, Vx.Core.Type_context context, Vx.Core.Type_anylist anylist) where T : Vx.Core.Type_any;
  }

  public class Class_any_from_macro : Vx.Core.Class_base, Func_any_from_macro {

    public override Vx.Repl.Func_any_from_macro vx_new(params Object[] vals) {
      Class_any_from_macro output = new Class_any_from_macro();
      return output;
    }

    public override Vx.Repl.Func_any_from_macro vx_copy(params Object[] vals) {
      Class_any_from_macro output = new Class_any_from_macro();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/repl", // pkgname
        "any<-macro", // name
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
      return e_any_from_macro;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_macro;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_anylist inputval = (Vx.Core.Type_anylist)value;
      Vx.Core.Type_any outputval = Vx.Repl.f_any_from_macro(Vx.Core.t_any, context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any generic_any_1 = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_anylist anylist = Vx.Core.f_any_from_any(Vx.Core.t_anylist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Repl.f_any_from_macro(generic_any_1, context, anylist);
      return output;
    }

    public T vx_any_from_macro<T>(T generic_any_1, Vx.Core.Type_context context, Vx.Core.Type_anylist anylist) where T : Vx.Core.Type_any {
      return Vx.Repl.f_any_from_macro(generic_any_1, context, anylist);
    }

  }

  public static Func_any_from_macro e_any_from_macro = new Vx.Repl.Class_any_from_macro();
  public static Func_any_from_macro t_any_from_macro = new Vx.Repl.Class_any_from_macro();

  public static T f_any_from_macro<T>(T generic_any_1, Vx.Core.Type_context context, Vx.Core.Type_anylist anylist) where T : Vx.Core.Type_any {
    T output = Vx.Core.f_empty(generic_any_1);
    output = Vx.Core.f_let(
      generic_any_1,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Repl.Type_repl repl = Vx.Repl.f_repl_from_macro(context, anylist);
        Vx.Core.Type_any val = Vx.Repl.f_any_from_repl(context, repl);
        Vx.Core.Type_any output_1 = Vx.Core.f_any_from_any(generic_any_1, val);
        return output_1;
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
  public interface Func_any_from_repl : Vx.Core.Func_any_from_any_context {
    public Vx.Core.Type_any vx_any_from_repl(Vx.Core.Type_context context, Vx.Repl.Type_repl repl);
  }

  public class Class_any_from_repl : Vx.Core.Class_base, Func_any_from_repl {

    public override Vx.Repl.Func_any_from_repl vx_new(params Object[] vals) {
      Class_any_from_repl output = new Class_any_from_repl();
      return output;
    }

    public override Vx.Repl.Func_any_from_repl vx_copy(params Object[] vals) {
      Class_any_from_repl output = new Class_any_from_repl();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/repl", // pkgname
        "any<-repl", // name
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
      return e_any_from_repl;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_repl;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Repl.Type_repl inputval = (Vx.Repl.Type_repl)value;
      Vx.Core.Type_any outputval = Vx.Repl.f_any_from_repl(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Repl.Type_repl repl = Vx.Core.f_any_from_any(Vx.Repl.t_repl, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Repl.f_any_from_repl(context, repl);
      return output;
    }

    public Vx.Core.Type_any vx_any_from_repl(Vx.Core.Type_context context, Vx.Repl.Type_repl repl) {
      return Vx.Repl.f_any_from_repl(context, repl);
    }

  }

  public static Func_any_from_repl e_any_from_repl = new Vx.Repl.Class_any_from_repl();
  public static Func_any_from_repl t_any_from_repl = new Vx.Repl.Class_any_from_repl();

  public static Vx.Core.Type_any f_any_from_repl(Vx.Core.Type_context context, Vx.Repl.Type_repl repl) {
    Vx.Core.Type_any output = Vx.Core.e_any;
    output = Vx.Core.f_let(
      Vx.Core.t_any,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_any val = repl.val();
        Vx.Core.Type_any repltype = repl.type();
        Vx.Repl.Type_repllist repllist = repl.repllist();
        Vx.Core.Type_anylist args = Vx.Repl.f_anylist_from_repllist(context, repllist);
        Vx.Core.Type_any output_1 = Vx.Core.f_if_2(
          Vx.Core.t_any,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_notempty_1(val);
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return val;
              })
            ),
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_is_func(repltype);
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Repl.f_any_repl_from_functype_args(repltype, args);
              })
            ),
            Vx.Core.f_else(
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Core.f_new(repltype, args);
              })
            )
          )
        );
        return output_1;
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
  public interface Func_any_from_script : Vx.Core.Func_any_from_any_context {
    public Vx.Core.Type_any vx_any_from_script(Vx.Core.Type_context context, Vx.Core.Type_string script);
  }

  public class Class_any_from_script : Vx.Core.Class_base, Func_any_from_script {

    public override Vx.Repl.Func_any_from_script vx_new(params Object[] vals) {
      Class_any_from_script output = new Class_any_from_script();
      return output;
    }

    public override Vx.Repl.Func_any_from_script vx_copy(params Object[] vals) {
      Class_any_from_script output = new Class_any_from_script();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/repl", // pkgname
        "any<-script", // name
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
      return e_any_from_script;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_any_from_script;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Repl.f_any_from_script(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string script = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Repl.f_any_from_script(context, script);
      return output;
    }

    public Vx.Core.Type_any vx_any_from_script(Vx.Core.Type_context context, Vx.Core.Type_string script) {
      return Vx.Repl.f_any_from_script(context, script);
    }

  }

  public static Func_any_from_script e_any_from_script = new Vx.Repl.Class_any_from_script();
  public static Func_any_from_script t_any_from_script = new Vx.Repl.Class_any_from_script();

  public static Vx.Core.Type_any f_any_from_script(Vx.Core.Type_context context, Vx.Core.Type_string script) {
    Vx.Core.Type_any output = Vx.Core.e_any;
    output = Vx.Core.f_let(
      Vx.Core.t_any,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Data.Textblock.Type_textblock textblock = Vx.Repl.f_textblock_from_script(script);
        Vx.Repl.Type_repl repl = Vx.Repl.f_repl_from_textblock(textblock);
        Vx.Core.Type_any output_1 = Vx.Repl.f_any_from_repl(context, repl);
        return output_1;
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
  public interface Func_anylist_from_repllist : Vx.Core.Func_any_from_any_context {
    public Vx.Core.Type_anylist vx_anylist_from_repllist(Vx.Core.Type_context context, Vx.Repl.Type_repllist repllist);
  }

  public class Class_anylist_from_repllist : Vx.Core.Class_base, Func_anylist_from_repllist {

    public override Vx.Repl.Func_anylist_from_repllist vx_new(params Object[] vals) {
      Class_anylist_from_repllist output = new Class_anylist_from_repllist();
      return output;
    }

    public override Vx.Repl.Func_anylist_from_repllist vx_copy(params Object[] vals) {
      Class_anylist_from_repllist output = new Class_anylist_from_repllist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/repl", // pkgname
        "anylist<-repllist", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "anylist", // name
          ":list", // extends
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
      return e_anylist_from_repllist;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_anylist_from_repllist;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Repl.Type_repllist inputval = (Vx.Repl.Type_repllist)value;
      Vx.Core.Type_any outputval = Vx.Repl.f_anylist_from_repllist(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Repl.Type_repllist repllist = Vx.Core.f_any_from_any(Vx.Repl.t_repllist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Repl.f_anylist_from_repllist(context, repllist);
      return output;
    }

    public Vx.Core.Type_anylist vx_anylist_from_repllist(Vx.Core.Type_context context, Vx.Repl.Type_repllist repllist) {
      return Vx.Repl.f_anylist_from_repllist(context, repllist);
    }

  }

  public static Func_anylist_from_repllist e_anylist_from_repllist = new Vx.Repl.Class_anylist_from_repllist();
  public static Func_anylist_from_repllist t_anylist_from_repllist = new Vx.Repl.Class_anylist_from_repllist();

  public static Vx.Core.Type_anylist f_anylist_from_repllist(Vx.Core.Type_context context, Vx.Repl.Type_repllist repllist) {
    Vx.Core.Type_anylist output = Vx.Core.e_anylist;
    output = Vx.Core.f_list_from_list_1(
      Vx.Core.t_anylist,
      repllist,
      Vx.Core.t_any_from_any.vx_fn_new((repl_any) => {
        Vx.Repl.Type_repl repl = Vx.Core.f_any_from_any(Vx.Repl.t_repl, repl_any);
        Vx.Core.Type_any output_1 = 
          Vx.Repl.f_any_from_repl(context, repl);
        return output_1;
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
  public interface Func_argmap_from_textblock_argmap : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_argmap vx_argmap_from_textblock_argmap(Vx.Data.Textblock.Type_textblock textblock, Vx.Core.Type_argmap argmap);
  }

  public class Class_argmap_from_textblock_argmap : Vx.Core.Class_base, Func_argmap_from_textblock_argmap {

    public override Vx.Repl.Func_argmap_from_textblock_argmap vx_new(params Object[] vals) {
      Class_argmap_from_textblock_argmap output = new Class_argmap_from_textblock_argmap();
      return output;
    }

    public override Vx.Repl.Func_argmap_from_textblock_argmap vx_copy(params Object[] vals) {
      Class_argmap_from_textblock_argmap output = new Class_argmap_from_textblock_argmap();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/repl", // pkgname
        "argmap<-textblock-argmap", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "argmap", // name
          ":map", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_arg), // allowtypes
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
      return e_argmap_from_textblock_argmap;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_argmap_from_textblock_argmap;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_textblock textblock = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_argmap argmap = Vx.Core.f_any_from_any(Vx.Core.t_argmap, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Repl.f_argmap_from_textblock_argmap(textblock, argmap);
      return output;
    }

    public Vx.Core.Type_argmap vx_argmap_from_textblock_argmap(Vx.Data.Textblock.Type_textblock textblock, Vx.Core.Type_argmap argmap) {
      return Vx.Repl.f_argmap_from_textblock_argmap(textblock, argmap);
    }

  }

  public static Func_argmap_from_textblock_argmap e_argmap_from_textblock_argmap = new Vx.Repl.Class_argmap_from_textblock_argmap();
  public static Func_argmap_from_textblock_argmap t_argmap_from_textblock_argmap = new Vx.Repl.Class_argmap_from_textblock_argmap();

  public static Vx.Core.Type_argmap f_argmap_from_textblock_argmap(Vx.Data.Textblock.Type_textblock textblock, Vx.Core.Type_argmap argmap) {
    Vx.Core.Type_argmap output = Vx.Core.e_argmap;
    output = Vx.Core.f_if_1(
      Vx.Core.t_argmap,
      Vx.Core.f_ne(
        Vx.Core.vx_new_string("delimbracketsquare"),
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
  public interface Func_const_from_string : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_any vx_const_from_string(Vx.Core.Type_string text);
  }

  public class Class_const_from_string : Vx.Core.Class_base, Func_const_from_string {

    public override Vx.Repl.Func_const_from_string vx_new(params Object[] vals) {
      Class_const_from_string output = new Class_const_from_string();
      return output;
    }

    public override Vx.Repl.Func_const_from_string vx_copy(params Object[] vals) {
      Class_const_from_string output = new Class_const_from_string();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/repl", // pkgname
        "const<-string", // name
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
      return e_const_from_string;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_const_from_string;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Repl.f_const_from_string(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Repl.f_const_from_string(text);
      return output;
    }

    public Vx.Core.Type_any vx_const_from_string(Vx.Core.Type_string text) {
      return Vx.Repl.f_const_from_string(text);
    }

  }

  public static Func_const_from_string e_const_from_string = new Vx.Repl.Class_const_from_string();
  public static Func_const_from_string t_const_from_string = new Vx.Repl.Class_const_from_string();

  public static Vx.Core.Type_any f_const_from_string(Vx.Core.Type_string text) {
    Vx.Core.Type_any output = Vx.Core.e_any;
    output = Vx.Core.f_let(
      Vx.Core.t_any,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_int pkgpos = Vx.Type.f_int_from_string_findlast(text, Vx.Core.vx_new_string("/"));
        Vx.Core.Type_string pkgname = Vx.Core.f_if_1(
          Vx.Core.t_string,
          Vx.Core.f_eq(Vx.Core.vx_new_int(0), pkgpos),
          Vx.Core.vx_new_string("vx/core"),
          Vx.Type.f_string_from_string_end(
            text,
            Vx.Core.f_minus1(pkgpos)
          )
        );
        Vx.Core.Type_string name = Vx.Core.f_if_1(
          Vx.Core.t_string,
          Vx.Core.f_eq(Vx.Core.vx_new_int(0), pkgpos),
          text,
          Vx.Type.f_string_from_string_start(
            text,
            Vx.Core.f_plus1(pkgpos)
          )
        );
        Vx.Core.Type_package pkg = Vx.Core.f_package_global_from_name(pkgname);
        Vx.Core.Type_constmap constmap = pkg.constmap();
        Vx.Core.Type_any constval = Vx.Core.f_any_from_map(Vx.Core.t_any, constmap, name);
        Vx.Core.Type_any output_1 = Vx.Core.f_if_1(
          Vx.Core.t_any,
          Vx.Core.f_notempty_1(constval),
          constval,
          Vx.Core.f_empty(
            Vx.Core.t_any
          )
        );
        return output_1;
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
  public interface Func_repl_bracket_from_textblock_argmap : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Repl.Type_repl vx_repl_bracket_from_textblock_argmap(Vx.Data.Textblock.Type_textblock textblock, Vx.Core.Type_argmap argmap);
  }

  public class Class_repl_bracket_from_textblock_argmap : Vx.Core.Class_base, Func_repl_bracket_from_textblock_argmap {

    public override Vx.Repl.Func_repl_bracket_from_textblock_argmap vx_new(params Object[] vals) {
      Class_repl_bracket_from_textblock_argmap output = new Class_repl_bracket_from_textblock_argmap();
      return output;
    }

    public override Vx.Repl.Func_repl_bracket_from_textblock_argmap vx_copy(params Object[] vals) {
      Class_repl_bracket_from_textblock_argmap output = new Class_repl_bracket_from_textblock_argmap();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/repl", // pkgname
        "repl-bracket<-textblock-argmap", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_bracket_from_textblock_argmap;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_repl_bracket_from_textblock_argmap;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_textblock textblock = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_argmap argmap = Vx.Core.f_any_from_any(Vx.Core.t_argmap, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Repl.f_repl_bracket_from_textblock_argmap(textblock, argmap);
      return output;
    }

    public Vx.Repl.Type_repl vx_repl_bracket_from_textblock_argmap(Vx.Data.Textblock.Type_textblock textblock, Vx.Core.Type_argmap argmap) {
      return Vx.Repl.f_repl_bracket_from_textblock_argmap(textblock, argmap);
    }

  }

  public static Func_repl_bracket_from_textblock_argmap e_repl_bracket_from_textblock_argmap = new Vx.Repl.Class_repl_bracket_from_textblock_argmap();
  public static Func_repl_bracket_from_textblock_argmap t_repl_bracket_from_textblock_argmap = new Vx.Repl.Class_repl_bracket_from_textblock_argmap();

  public static Vx.Repl.Type_repl f_repl_bracket_from_textblock_argmap(Vx.Data.Textblock.Type_textblock textblock, Vx.Core.Type_argmap argmap) {
    Vx.Repl.Type_repl output = Vx.Repl.e_repl;
    output = Vx.Core.f_empty(
      Vx.Repl.t_repl
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
  public interface Func_repl_empty_from_textblock_argmap : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Repl.Type_repl vx_repl_empty_from_textblock_argmap(Vx.Data.Textblock.Type_textblock textblock, Vx.Core.Type_argmap argmap);
  }

  public class Class_repl_empty_from_textblock_argmap : Vx.Core.Class_base, Func_repl_empty_from_textblock_argmap {

    public override Vx.Repl.Func_repl_empty_from_textblock_argmap vx_new(params Object[] vals) {
      Class_repl_empty_from_textblock_argmap output = new Class_repl_empty_from_textblock_argmap();
      return output;
    }

    public override Vx.Repl.Func_repl_empty_from_textblock_argmap vx_copy(params Object[] vals) {
      Class_repl_empty_from_textblock_argmap output = new Class_repl_empty_from_textblock_argmap();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/repl", // pkgname
        "repl-empty<-textblock-argmap", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_empty_from_textblock_argmap;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_repl_empty_from_textblock_argmap;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_textblock textblock = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_argmap argmap = Vx.Core.f_any_from_any(Vx.Core.t_argmap, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Repl.f_repl_empty_from_textblock_argmap(textblock, argmap);
      return output;
    }

    public Vx.Repl.Type_repl vx_repl_empty_from_textblock_argmap(Vx.Data.Textblock.Type_textblock textblock, Vx.Core.Type_argmap argmap) {
      return Vx.Repl.f_repl_empty_from_textblock_argmap(textblock, argmap);
    }

  }

  public static Func_repl_empty_from_textblock_argmap e_repl_empty_from_textblock_argmap = new Vx.Repl.Class_repl_empty_from_textblock_argmap();
  public static Func_repl_empty_from_textblock_argmap t_repl_empty_from_textblock_argmap = new Vx.Repl.Class_repl_empty_from_textblock_argmap();

  public static Vx.Repl.Type_repl f_repl_empty_from_textblock_argmap(Vx.Data.Textblock.Type_textblock textblock, Vx.Core.Type_argmap argmap) {
    Vx.Repl.Type_repl output = Vx.Repl.e_repl;
    output = Vx.Core.f_let(
      Vx.Repl.t_repl,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Data.Textblock.Type_textblocklist children = textblock.children();
        Vx.Core.Type_int len = Vx.Core.f_length_1(children);
        Vx.Core.Type_any output_1 = Vx.Core.f_switch(
          Vx.Repl.t_repl,
          len,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
            Vx.Core.f_case_1(
              Vx.Core.vx_new_int(0),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Repl.f_repl_from_string_argmap(
                  textblock.text(),
                  argmap
                );
              })
            ),
            Vx.Core.f_case_1(
              Vx.Core.vx_new_int(1),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Repl.f_repl_from_textblock_argmap(
                  Vx.Core.f_any_from_list(Vx.Data.Textblock.t_textblock, children, Vx.Core.vx_new_int(1)),
                  argmap
                );
              })
            ),
            Vx.Core.f_else(
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Core.f_new(
                  Vx.Repl.t_repl,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                      Vx.Core.f_msg_from_error(Vx.Core.vx_new_string("Empty delim cannot have more than one child."))
                  )
                );
              })
            )
          )
        );
        return output_1;
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
  public interface Func_repl_paren_from_textblock_argmap : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Repl.Type_repl vx_repl_paren_from_textblock_argmap(Vx.Data.Textblock.Type_textblock textblock, Vx.Core.Type_argmap argmap);
  }

  public class Class_repl_paren_from_textblock_argmap : Vx.Core.Class_base, Func_repl_paren_from_textblock_argmap {

    public override Vx.Repl.Func_repl_paren_from_textblock_argmap vx_new(params Object[] vals) {
      Class_repl_paren_from_textblock_argmap output = new Class_repl_paren_from_textblock_argmap();
      return output;
    }

    public override Vx.Repl.Func_repl_paren_from_textblock_argmap vx_copy(params Object[] vals) {
      Class_repl_paren_from_textblock_argmap output = new Class_repl_paren_from_textblock_argmap();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/repl", // pkgname
        "repl-paren<-textblock-argmap", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_paren_from_textblock_argmap;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_repl_paren_from_textblock_argmap;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_textblock textblock = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_argmap argmap = Vx.Core.f_any_from_any(Vx.Core.t_argmap, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Repl.f_repl_paren_from_textblock_argmap(textblock, argmap);
      return output;
    }

    public Vx.Repl.Type_repl vx_repl_paren_from_textblock_argmap(Vx.Data.Textblock.Type_textblock textblock, Vx.Core.Type_argmap argmap) {
      return Vx.Repl.f_repl_paren_from_textblock_argmap(textblock, argmap);
    }

  }

  public static Func_repl_paren_from_textblock_argmap e_repl_paren_from_textblock_argmap = new Vx.Repl.Class_repl_paren_from_textblock_argmap();
  public static Func_repl_paren_from_textblock_argmap t_repl_paren_from_textblock_argmap = new Vx.Repl.Class_repl_paren_from_textblock_argmap();

  public static Vx.Repl.Type_repl f_repl_paren_from_textblock_argmap(Vx.Data.Textblock.Type_textblock textblock, Vx.Core.Type_argmap argmap) {
    Vx.Repl.Type_repl output = Vx.Repl.e_repl;
    output = Vx.Core.f_let(
      Vx.Repl.t_repl,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Data.Textblock.Type_textblocklist childlst = textblock.children();
        Vx.Data.Textblock.Type_textblocklist children = Vx.Data.Textblock.f_textblocklist_from_textblocklist_remove(
          childlst,
          Vx.Data.Textblock.c_delimwhitespace
        );
        Vx.Data.Textblock.Type_textblock tbfunc = Vx.Core.f_any_from_list(Vx.Data.Textblock.t_textblock, children, Vx.Core.vx_new_int(1));
        Vx.Core.Type_string sfunc = tbfunc.text();
        Vx.Repl.Type_repl replfunc = Vx.Repl.f_repl_from_string_argmap(sfunc, argmap);
        Vx.Core.Type_any typefunc = replfunc.type();
        Vx.Core.Type_int posarg = Vx.Core.f_switch(
          Vx.Core.t_int,
          typefunc,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
              Vx.Core.f_case_1(
                Vx.Core.t_let,
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Core.vx_new_int(3);
                })
              ),
              Vx.Core.f_case_1(
                Vx.Core.t_fn,
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Core.vx_new_int(3);
                })
              ),
              Vx.Core.f_else(
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Core.vx_new_int(2);
                })
              )
          )
        );
        Vx.Core.Type_argmap argmap2 = Vx.Core.f_switch(
          Vx.Core.t_argmap,
          typefunc,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
              Vx.Core.f_case_1(
                Vx.Core.t_let,
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Repl.f_argmap_from_textblock_argmap(
                    Vx.Core.f_any_from_list(Vx.Data.Textblock.t_textblock, children, Vx.Core.vx_new_int(3)),
                    argmap
                  );
                })
              ),
              Vx.Core.f_case_1(
                Vx.Core.t_fn,
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return Vx.Repl.f_argmap_from_textblock_argmap(
                    Vx.Core.f_any_from_list(Vx.Data.Textblock.t_textblock, children, Vx.Core.vx_new_int(3)),
                    argmap
                  );
                })
              ),
              Vx.Core.f_else(
                Vx.Core.t_any_from_func.vx_fn_new(() => {
                  return argmap;
                })
              )
          )
        );
        Vx.Data.Textblock.Type_textblocklist tbargs = Vx.Collection.f_list_from_list_start(Vx.Data.Textblock.t_textblocklist, children, posarg);
        Vx.Repl.Type_repllist replargs = Vx.Repl.f_repllist_from_textblocklist_argmap(tbargs, argmap);
        Vx.Core.Type_any output_1 = Vx.Core.f_copy(
          replfunc,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":repllist"),
            replargs
          )
        );
        return output_1;
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
  public interface Func_repl_from_liblist_string : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Repl.Type_repl vx_repl_from_liblist_string(Vx.Repl.Type_liblist liblist, Vx.Core.Type_string text);
  }

  public class Class_repl_from_liblist_string : Vx.Core.Class_base, Func_repl_from_liblist_string {

    public override Vx.Repl.Func_repl_from_liblist_string vx_new(params Object[] vals) {
      Class_repl_from_liblist_string output = new Class_repl_from_liblist_string();
      return output;
    }

    public override Vx.Repl.Func_repl_from_liblist_string vx_copy(params Object[] vals) {
      Class_repl_from_liblist_string output = new Class_repl_from_liblist_string();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/repl", // pkgname
        "repl<-liblist-string", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_from_liblist_string;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_repl_from_liblist_string;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Repl.Type_liblist liblist = Vx.Core.f_any_from_any(Vx.Repl.t_liblist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Repl.f_repl_from_liblist_string(liblist, text);
      return output;
    }

    public Vx.Repl.Type_repl vx_repl_from_liblist_string(Vx.Repl.Type_liblist liblist, Vx.Core.Type_string text) {
      return Vx.Repl.f_repl_from_liblist_string(liblist, text);
    }

  }

  public static Func_repl_from_liblist_string e_repl_from_liblist_string = new Vx.Repl.Class_repl_from_liblist_string();
  public static Func_repl_from_liblist_string t_repl_from_liblist_string = new Vx.Repl.Class_repl_from_liblist_string();

  public static Vx.Repl.Type_repl f_repl_from_liblist_string(Vx.Repl.Type_liblist liblist, Vx.Core.Type_string text) {
    Vx.Repl.Type_repl output = Vx.Repl.e_repl;
    return output;
  }

  /**
   * @function repl_from_macro
   * A function that joins any number of values into a string and then parses it.
   * @param  {anylist} anylist
   * @return {repl}
   * (func repl<-macro)
   */
  public interface Func_repl_from_macro : Vx.Core.Func_any_from_any_context {
    public Vx.Repl.Type_repl vx_repl_from_macro(Vx.Core.Type_context context, Vx.Core.Type_anylist anylist);
  }

  public class Class_repl_from_macro : Vx.Core.Class_base, Func_repl_from_macro {

    public override Vx.Repl.Func_repl_from_macro vx_new(params Object[] vals) {
      Class_repl_from_macro output = new Class_repl_from_macro();
      return output;
    }

    public override Vx.Repl.Func_repl_from_macro vx_copy(params Object[] vals) {
      Class_repl_from_macro output = new Class_repl_from_macro();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/repl", // pkgname
        "repl<-macro", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_from_macro;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_repl_from_macro;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_anylist inputval = (Vx.Core.Type_anylist)value;
      Vx.Core.Type_any outputval = Vx.Repl.f_repl_from_macro(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_anylist anylist = Vx.Core.f_any_from_any(Vx.Core.t_anylist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Repl.f_repl_from_macro(context, anylist);
      return output;
    }

    public Vx.Repl.Type_repl vx_repl_from_macro(Vx.Core.Type_context context, Vx.Core.Type_anylist anylist) {
      return Vx.Repl.f_repl_from_macro(context, anylist);
    }

  }

  public static Func_repl_from_macro e_repl_from_macro = new Vx.Repl.Class_repl_from_macro();
  public static Func_repl_from_macro t_repl_from_macro = new Vx.Repl.Class_repl_from_macro();

  public static Vx.Repl.Type_repl f_repl_from_macro(Vx.Core.Type_context context, Vx.Core.Type_anylist anylist) {
    Vx.Repl.Type_repl output = Vx.Repl.e_repl;
    output = Vx.Core.f_let(
      Vx.Repl.t_repl,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_stringlist textlist = Vx.Core.f_list_from_list_1(
          Vx.Core.t_stringlist,
          anylist,
          Vx.Core.t_any_from_any.vx_fn_new((item_any) => {
            Vx.Core.Type_any item = Vx.Core.f_any_from_any(Vx.Core.t_any, item_any);
            Vx.Core.Type_any output_1 = 
                Vx.Core.f_let(
                  Vx.Core.t_string,
                  Vx.Core.t_any_from_func.vx_fn_new(() => {
                    Vx.Core.Type_any typ = Vx.Core.f_type_from_any(item);
                    Vx.Core.Type_any output_2 = Vx.Core.f_switch(
                      Vx.Core.t_string,
                      typ,
                      Vx.Core.vx_new(Vx.Core.t_thenelselist,
                        Vx.Core.f_case_1(
                          Vx.Core.t_string,
                          Vx.Core.t_any_from_func.vx_fn_new(() => {
                            return Vx.Core.f_any_from_any(Vx.Core.t_string, item);
                          })
                        ),
                        Vx.Core.f_else(
                          Vx.Core.t_any_from_func.vx_fn_new(() => {
                            return Vx.Core.f_string_from_any(item);
                          })
                        )
                      )
                    );
                    return output_2;
                  })
                );
            return output_1;
          })
        );
        Vx.Core.Type_string script = Vx.Type.f_string_from_stringlist_join(textlist, Vx.Core.vx_new_string(""));
        Vx.Data.Textblock.Type_textblock tb = Vx.Repl.f_textblock_from_script(script);
        Vx.Core.Type_any output_3 = Vx.Repl.f_repl_from_textblock(tb);
        return output_3;
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
  public interface Func_repl_from_script : Vx.Core.Func_any_from_any {
    public Vx.Repl.Type_repl vx_repl_from_script(Vx.Core.Type_string script);
  }

  public class Class_repl_from_script : Vx.Core.Class_base, Func_repl_from_script {

    public override Vx.Repl.Func_repl_from_script vx_new(params Object[] vals) {
      Class_repl_from_script output = new Class_repl_from_script();
      return output;
    }

    public override Vx.Repl.Func_repl_from_script vx_copy(params Object[] vals) {
      Class_repl_from_script output = new Class_repl_from_script();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/repl", // pkgname
        "repl<-script", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_from_script;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_repl_from_script;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Repl.f_repl_from_script(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string script = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Repl.f_repl_from_script(script);
      return output;
    }

    public Vx.Repl.Type_repl vx_repl_from_script(Vx.Core.Type_string script) {
      return Vx.Repl.f_repl_from_script(script);
    }

  }

  public static Func_repl_from_script e_repl_from_script = new Vx.Repl.Class_repl_from_script();
  public static Func_repl_from_script t_repl_from_script = new Vx.Repl.Class_repl_from_script();

  public static Vx.Repl.Type_repl f_repl_from_script(Vx.Core.Type_string script) {
    Vx.Repl.Type_repl output = Vx.Repl.e_repl;
    output = Vx.Core.f_let(
      Vx.Repl.t_repl,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Data.Textblock.Type_textblock textblock = Vx.Repl.f_textblock_from_script(script);
        Vx.Core.Type_any output_1 = Vx.Repl.f_repl_from_textblock(textblock);
        return output_1;
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
  public interface Func_repl_from_string_argmap : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Repl.Type_repl vx_repl_from_string_argmap(Vx.Core.Type_string text, Vx.Core.Type_argmap argmap);
  }

  public class Class_repl_from_string_argmap : Vx.Core.Class_base, Func_repl_from_string_argmap {

    public override Vx.Repl.Func_repl_from_string_argmap vx_new(params Object[] vals) {
      Class_repl_from_string_argmap output = new Class_repl_from_string_argmap();
      return output;
    }

    public override Vx.Repl.Func_repl_from_string_argmap vx_copy(params Object[] vals) {
      Class_repl_from_string_argmap output = new Class_repl_from_string_argmap();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/repl", // pkgname
        "repl<-string-argmap", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_from_string_argmap;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_repl_from_string_argmap;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_argmap argmap = Vx.Core.f_any_from_any(Vx.Core.t_argmap, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Repl.f_repl_from_string_argmap(text, argmap);
      return output;
    }

    public Vx.Repl.Type_repl vx_repl_from_string_argmap(Vx.Core.Type_string text, Vx.Core.Type_argmap argmap) {
      return Vx.Repl.f_repl_from_string_argmap(text, argmap);
    }

  }

  public static Func_repl_from_string_argmap e_repl_from_string_argmap = new Vx.Repl.Class_repl_from_string_argmap();
  public static Func_repl_from_string_argmap t_repl_from_string_argmap = new Vx.Repl.Class_repl_from_string_argmap();

  public static Vx.Repl.Type_repl f_repl_from_string_argmap(Vx.Core.Type_string text, Vx.Core.Type_argmap argmap) {
    Vx.Repl.Type_repl output = Vx.Repl.e_repl;
    output = Vx.Core.f_if_2(
      Vx.Repl.t_repl,
      Vx.Core.vx_new(Vx.Core.t_thenelselist,
        Vx.Core.f_then(
          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
            return Vx.Core.f_and(
              Vx.Type.f_boolean_from_string_starts(
                text,
                Vx.Core.c_quote
              ),
              Vx.Type.f_boolean_from_string_ends(
                text,
                Vx.Core.c_quote
              )
            );
          }),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.f_new(
              Vx.Repl.t_repl,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                  Vx.Core.vx_new_string(":val"),
                  Vx.Type.f_string_from_string_start_end(text, Vx.Core.vx_new_int(2), Vx.Core.vx_new_int(-1))
              )
            );
          })
        ),
        Vx.Core.f_then(
          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
            return Vx.Core.f_is_int(text);
          }),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.f_new(
              Vx.Repl.t_repl,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                  Vx.Core.vx_new_string(":val"),
                  Vx.Core.f_int_from_string(text)
              )
            );
          })
        ),
        Vx.Core.f_then(
          Vx.Core.t_boolean_from_func.vx_fn_new(() => {
            return Vx.Core.f_is_float(text);
          }),
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.f_new(
              Vx.Repl.t_repl,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                  Vx.Core.vx_new_string(":val"),
                  Vx.Core.f_float_from_string(text)
              )
            );
          })
        ),
        Vx.Core.f_else(
          Vx.Core.t_any_from_func.vx_fn_new(() => {
            return Vx.Core.f_let(
              Vx.Repl.t_repl,
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                Vx.Core.Type_any arg = Vx.Core.f_any_from_map(Vx.Core.t_any, argmap, text);
                Vx.Core.Type_any output_3 = Vx.Core.f_if_2(
                  Vx.Repl.t_repl,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                    Vx.Core.f_then(
                      Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                        return Vx.Core.f_notempty_1(arg);
                      }),
                      Vx.Core.t_any_from_func.vx_fn_new(() => {
                        return Vx.Core.f_new(
                          Vx.Repl.t_repl,
                          Vx.Core.vx_new(Vx.Core.t_anylist,
                              Vx.Core.vx_new_string(":val"),
                              arg
                          )
                        );
                      })
                    ),
                    Vx.Core.f_else(
                      Vx.Core.t_any_from_func.vx_fn_new(() => {
                        return Vx.Core.f_let(
                          Vx.Repl.t_repl,
                          Vx.Core.t_any_from_func.vx_fn_new(() => {
                            Vx.Core.Type_any cnst = Vx.Repl.f_const_from_string(text);
                            Vx.Core.Type_any output_2 = Vx.Core.f_if_2(
                              Vx.Repl.t_repl,
                              Vx.Core.vx_new(Vx.Core.t_thenelselist,
                                Vx.Core.f_then(
                                  Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                                    return Vx.Core.f_notempty_1(cnst);
                                  }),
                                  Vx.Core.t_any_from_func.vx_fn_new(() => {
                                    return Vx.Core.f_new(
                                      Vx.Repl.t_repl,
                                      Vx.Core.vx_new(Vx.Core.t_anylist,
                                          Vx.Core.vx_new_string(":val"),
                                          cnst
                                      )
                                    );
                                  })
                                ),
                                Vx.Core.f_else(
                                  Vx.Core.t_any_from_func.vx_fn_new(() => {
                                    return Vx.Core.f_let(
                                      Vx.Repl.t_repl,
                                      Vx.Core.t_any_from_func.vx_fn_new(() => {
                                        Vx.Core.Type_any typefunc = Vx.Repl.f_typefunc_from_string(text);
                                        Vx.Core.Type_any output_1 = Vx.Core.f_if_2(
                                          Vx.Repl.t_repl,
                                          Vx.Core.vx_new(Vx.Core.t_thenelselist,
                                            Vx.Core.f_then(
                                              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                                                return Vx.Core.f_notempty_1(typefunc);
                                              }),
                                              Vx.Core.t_any_from_func.vx_fn_new(() => {
                                                return Vx.Core.f_new(
                                                  Vx.Repl.t_repl,
                                                  Vx.Core.vx_new(Vx.Core.t_anylist,
                                                      Vx.Core.vx_new_string(":type"),
                                                      typefunc
                                                  )
                                                );
                                              })
                                            ),
                                            Vx.Core.f_else(
                                              Vx.Core.t_any_from_func.vx_fn_new(() => {
                                                return Vx.Core.f_new(
                                                  Vx.Repl.t_repl,
                                                  Vx.Core.vx_new(Vx.Core.t_anylist,
                                                      Vx.Core.f_msg_from_error_1(Vx.Core.vx_new_string(":repltypenotfound"), text)
                                                  )
                                                );
                                              })
                                            )
                                          )
                                        );
                                        return output_1;
                                      })
                                    );
                                  })
                                )
                              )
                            );
                            return output_2;
                          })
                        );
                      })
                    )
                  )
                );
                return output_3;
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
  public interface Func_repl_from_textblock : Vx.Core.Func_any_from_any {
    public Vx.Repl.Type_repl vx_repl_from_textblock(Vx.Data.Textblock.Type_textblock textblock);
  }

  public class Class_repl_from_textblock : Vx.Core.Class_base, Func_repl_from_textblock {

    public override Vx.Repl.Func_repl_from_textblock vx_new(params Object[] vals) {
      Class_repl_from_textblock output = new Class_repl_from_textblock();
      return output;
    }

    public override Vx.Repl.Func_repl_from_textblock vx_copy(params Object[] vals) {
      Class_repl_from_textblock output = new Class_repl_from_textblock();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/repl", // pkgname
        "repl<-textblock", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_from_textblock;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_repl_from_textblock;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Data.Textblock.Type_textblock inputval = (Vx.Data.Textblock.Type_textblock)value;
      Vx.Core.Type_any outputval = Vx.Repl.f_repl_from_textblock(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_textblock textblock = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Repl.f_repl_from_textblock(textblock);
      return output;
    }

    public Vx.Repl.Type_repl vx_repl_from_textblock(Vx.Data.Textblock.Type_textblock textblock) {
      return Vx.Repl.f_repl_from_textblock(textblock);
    }

  }

  public static Func_repl_from_textblock e_repl_from_textblock = new Vx.Repl.Class_repl_from_textblock();
  public static Func_repl_from_textblock t_repl_from_textblock = new Vx.Repl.Class_repl_from_textblock();

  public static Vx.Repl.Type_repl f_repl_from_textblock(Vx.Data.Textblock.Type_textblock textblock) {
    Vx.Repl.Type_repl output = Vx.Repl.e_repl;
    output = Vx.Repl.f_repl_from_textblock_argmap(
      textblock,
      Vx.Core.f_empty(
        Vx.Core.t_argmap
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
  public interface Func_repl_from_textblock_argmap : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Repl.Type_repl vx_repl_from_textblock_argmap(Vx.Data.Textblock.Type_textblock textblock, Vx.Core.Type_argmap argmap);
  }

  public class Class_repl_from_textblock_argmap : Vx.Core.Class_base, Func_repl_from_textblock_argmap {

    public override Vx.Repl.Func_repl_from_textblock_argmap vx_new(params Object[] vals) {
      Class_repl_from_textblock_argmap output = new Class_repl_from_textblock_argmap();
      return output;
    }

    public override Vx.Repl.Func_repl_from_textblock_argmap vx_copy(params Object[] vals) {
      Class_repl_from_textblock_argmap output = new Class_repl_from_textblock_argmap();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/repl", // pkgname
        "repl<-textblock-argmap", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_from_textblock_argmap;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_repl_from_textblock_argmap;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_textblock textblock = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_argmap argmap = Vx.Core.f_any_from_any(Vx.Core.t_argmap, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Repl.f_repl_from_textblock_argmap(textblock, argmap);
      return output;
    }

    public Vx.Repl.Type_repl vx_repl_from_textblock_argmap(Vx.Data.Textblock.Type_textblock textblock, Vx.Core.Type_argmap argmap) {
      return Vx.Repl.f_repl_from_textblock_argmap(textblock, argmap);
    }

  }

  public static Func_repl_from_textblock_argmap e_repl_from_textblock_argmap = new Vx.Repl.Class_repl_from_textblock_argmap();
  public static Func_repl_from_textblock_argmap t_repl_from_textblock_argmap = new Vx.Repl.Class_repl_from_textblock_argmap();

  public static Vx.Repl.Type_repl f_repl_from_textblock_argmap(Vx.Data.Textblock.Type_textblock textblock, Vx.Core.Type_argmap argmap) {
    Vx.Repl.Type_repl output = Vx.Repl.e_repl;
    output = Vx.Core.f_let(
      Vx.Repl.t_repl,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Data.Textblock.Type_delim delim = textblock.delim();
        Vx.Core.Type_string starttext = delim.starttext();
        Vx.Core.Type_any output_1 = Vx.Core.f_switch(
          Vx.Repl.t_repl,
          starttext,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
            Vx.Core.f_case_1(
              Vx.Core.vx_new_string(""),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Repl.f_repl_empty_from_textblock_argmap(textblock, argmap);
              })
            ),
            Vx.Core.f_case_1(
              Vx.Data.Textblock.c_delimparen.starttext(),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Repl.f_repl_paren_from_textblock_argmap(textblock, argmap);
              })
            ),
            Vx.Core.f_case_1(
              Vx.Data.Textblock.c_delimbracketsquare.starttext(),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Repl.f_repl_bracket_from_textblock_argmap(textblock, argmap);
              })
            )
          )
        );
        return output_1;
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
  public interface Func_replarglist_from_replarglist_textblock_argmap : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Repl.Type_replarglist vx_replarglist_from_replarglist_textblock_argmap(Vx.Repl.Type_replarglist replargs, Vx.Data.Textblock.Type_textblock tb, Vx.Core.Type_argmap argmap);
  }

  public class Class_replarglist_from_replarglist_textblock_argmap : Vx.Core.Class_base, Func_replarglist_from_replarglist_textblock_argmap {

    public override Vx.Repl.Func_replarglist_from_replarglist_textblock_argmap vx_new(params Object[] vals) {
      Class_replarglist_from_replarglist_textblock_argmap output = new Class_replarglist_from_replarglist_textblock_argmap();
      return output;
    }

    public override Vx.Repl.Func_replarglist_from_replarglist_textblock_argmap vx_copy(params Object[] vals) {
      Class_replarglist_from_replarglist_textblock_argmap output = new Class_replarglist_from_replarglist_textblock_argmap();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/repl", // pkgname
        "replarglist<-replarglist-textblock-argmap", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/repl", // pkgname
          "replarglist", // name
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
      return e_replarglist_from_replarglist_textblock_argmap;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_replarglist_from_replarglist_textblock_argmap;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Repl.Type_replarglist replargs = Vx.Core.f_any_from_any(Vx.Repl.t_replarglist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Data.Textblock.Type_textblock tb = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Type_argmap argmap = Vx.Core.f_any_from_any(Vx.Core.t_argmap, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Repl.f_replarglist_from_replarglist_textblock_argmap(replargs, tb, argmap);
      return output;
    }

    public Vx.Repl.Type_replarglist vx_replarglist_from_replarglist_textblock_argmap(Vx.Repl.Type_replarglist replargs, Vx.Data.Textblock.Type_textblock tb, Vx.Core.Type_argmap argmap) {
      return Vx.Repl.f_replarglist_from_replarglist_textblock_argmap(replargs, tb, argmap);
    }

  }

  public static Func_replarglist_from_replarglist_textblock_argmap e_replarglist_from_replarglist_textblock_argmap = new Vx.Repl.Class_replarglist_from_replarglist_textblock_argmap();
  public static Func_replarglist_from_replarglist_textblock_argmap t_replarglist_from_replarglist_textblock_argmap = new Vx.Repl.Class_replarglist_from_replarglist_textblock_argmap();

  public static Vx.Repl.Type_replarglist f_replarglist_from_replarglist_textblock_argmap(Vx.Repl.Type_replarglist replargs, Vx.Data.Textblock.Type_textblock tb, Vx.Core.Type_argmap argmap) {
    Vx.Repl.Type_replarglist output = Vx.Repl.e_replarglist;
    output = Vx.Core.f_let(
      Vx.Repl.t_replarglist,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string key = replargs.key();
        Vx.Repl.Type_repl current = replargs.current();
        Vx.Repl.Type_repllist repllist = replargs.repllist();
        Vx.Repl.Type_repllist currlist = current.repllist();
        Vx.Core.Type_string text = Vx.Data.Textblock.t_textblock.text();
        Vx.Core.Type_any output_1 = Vx.Core.f_if_2(
          Vx.Repl.t_replarglist,
          Vx.Core.vx_new(Vx.Core.t_thenelselist,
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_eq(key, Vx.Core.vx_new_string(""));
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Core.f_if_2(
                  Vx.Repl.t_replarglist,
                  Vx.Core.vx_new(Vx.Core.t_thenelselist,
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_eq_1(Vx.Core.vx_new(Vx.Core.t_anylist,
                            text));
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.f_copy(
                            replargs,
                            Vx.Core.vx_new(Vx.Core.t_anylist,
                                Vx.Core.vx_new_string(":key"),
                                text
                            )
                          );
                        })
                      ),
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_eq(text, Vx.Core.vx_new_string(":="));
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.f_copy(
                            replargs,
                            Vx.Core.vx_new(Vx.Core.t_anylist,
                                Vx.Core.vx_new_string(":key"),
                                text
                            )
                          );
                        })
                      ),
                      Vx.Core.f_then(
                        Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                          return Vx.Core.f_eq(text, Vx.Core.vx_new_string(":doc"));
                        }),
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.f_copy(
                            replargs,
                            Vx.Core.vx_new(Vx.Core.t_anylist,
                                Vx.Core.vx_new_string(":key"),
                                text
                            )
                          );
                        })
                      ),
                      Vx.Core.f_else(
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          return Vx.Core.f_copy(
                            replargs,
                            Vx.Core.vx_new(Vx.Core.t_anylist,
                                Vx.Core.vx_new_string(":current"),
                                Vx.Core.f_new(
                                  Vx.Repl.t_repl,
                                  Vx.Core.vx_new(Vx.Core.t_anylist,
                                    Vx.Core.vx_new_string(":name"),
                                    text
                                  )
                                ),
                                Vx.Core.vx_new_string(":repllist"),
                                Vx.Core.f_copy(repllist, Vx.Core.vx_new(Vx.Core.t_anylist,
                                  current))
                            )
                          );
                        })
                      )
                  )
                );
              })
            ),
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_eq_1(Vx.Core.vx_new(Vx.Core.t_anylist,
                  key));
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Core.f_copy(
                  replargs,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                      Vx.Core.vx_new_string(":key"),
                      Vx.Core.vx_new_string(""),
                      Vx.Core.vx_new_string(":current"),
                      Vx.Core.f_copy(
                        current,
                        Vx.Core.vx_new(Vx.Core.t_anylist,
                          Vx.Core.vx_new_string(":type"),
                          text
                        )
                      )
                  )
                );
              })
            ),
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_eq(key, Vx.Core.vx_new_string(":="));
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Core.f_copy(
                  replargs,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                      Vx.Core.vx_new_string(":key"),
                      Vx.Core.vx_new_string(""),
                      Vx.Core.vx_new_string(":current"),
                      Vx.Core.f_copy(
                        current,
                        Vx.Core.vx_new(Vx.Core.t_anylist,
                          Vx.Core.vx_new_string(":repllist"),
                          Vx.Core.f_copy(
                            currlist,
                            Vx.Core.vx_new(Vx.Core.t_anylist,
                              Vx.Repl.f_repl_from_textblock_argmap(tb, argmap)
                            )
                          )
                        )
                      )
                  )
                );
              })
            ),
            Vx.Core.f_then(
              Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                return Vx.Core.f_eq(key, Vx.Core.vx_new_string(":doc"));
              }),
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return Vx.Core.f_copy(
                  replargs,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                      Vx.Core.vx_new_string(":key"),
                      Vx.Core.vx_new_string(""),
                      Vx.Core.vx_new_string(":current"),
                      Vx.Core.f_copy(
                        current,
                        Vx.Core.vx_new(Vx.Core.t_anylist,
                          Vx.Core.vx_new_string(":doc"),
                          text
                        )
                      )
                  )
                );
              })
            ),
            Vx.Core.f_else(
              Vx.Core.t_any_from_func.vx_fn_new(() => {
                return replargs;
              })
            )
          )
        );
        return output_1;
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
  public interface Func_repllist_from_textblocklist_argmap : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Repl.Type_repllist vx_repllist_from_textblocklist_argmap(Vx.Data.Textblock.Type_textblocklist textblocklist, Vx.Core.Type_argmap argmap);
  }

  public class Class_repllist_from_textblocklist_argmap : Vx.Core.Class_base, Func_repllist_from_textblocklist_argmap {

    public override Vx.Repl.Func_repllist_from_textblocklist_argmap vx_new(params Object[] vals) {
      Class_repllist_from_textblocklist_argmap output = new Class_repllist_from_textblocklist_argmap();
      return output;
    }

    public override Vx.Repl.Func_repllist_from_textblocklist_argmap vx_copy(params Object[] vals) {
      Class_repllist_from_textblocklist_argmap output = new Class_repllist_from_textblocklist_argmap();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/repl", // pkgname
        "repllist<-textblocklist-argmap", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/repl", // pkgname
          "repllist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Repl.t_repl), // allowtypes
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
      return e_repllist_from_textblocklist_argmap;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_repllist_from_textblocklist_argmap;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Data.Textblock.Type_textblocklist textblocklist = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblocklist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_argmap argmap = Vx.Core.f_any_from_any(Vx.Core.t_argmap, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Repl.f_repllist_from_textblocklist_argmap(textblocklist, argmap);
      return output;
    }

    public Vx.Repl.Type_repllist vx_repllist_from_textblocklist_argmap(Vx.Data.Textblock.Type_textblocklist textblocklist, Vx.Core.Type_argmap argmap) {
      return Vx.Repl.f_repllist_from_textblocklist_argmap(textblocklist, argmap);
    }

  }

  public static Func_repllist_from_textblocklist_argmap e_repllist_from_textblocklist_argmap = new Vx.Repl.Class_repllist_from_textblocklist_argmap();
  public static Func_repllist_from_textblocklist_argmap t_repllist_from_textblocklist_argmap = new Vx.Repl.Class_repllist_from_textblocklist_argmap();

  public static Vx.Repl.Type_repllist f_repllist_from_textblocklist_argmap(Vx.Data.Textblock.Type_textblocklist textblocklist, Vx.Core.Type_argmap argmap) {
    Vx.Repl.Type_repllist output = Vx.Repl.e_repllist;
    output = Vx.Core.f_list_from_list_1(
      Vx.Repl.t_repllist,
      textblocklist,
      Vx.Core.t_any_from_any.vx_fn_new((textblock_any) => {
        Vx.Data.Textblock.Type_textblock textblock = Vx.Core.f_any_from_any(Vx.Data.Textblock.t_textblock, textblock_any);
        Vx.Core.Type_any output_1 = 
          Vx.Repl.f_repl_from_textblock(textblock);
        return output_1;
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
  public interface Func_textblock_from_script : Vx.Core.Func_any_from_any {
    public Vx.Data.Textblock.Type_textblock vx_textblock_from_script(Vx.Core.Type_string script);
  }

  public class Class_textblock_from_script : Vx.Core.Class_base, Func_textblock_from_script {

    public override Vx.Repl.Func_textblock_from_script vx_new(params Object[] vals) {
      Class_textblock_from_script output = new Class_textblock_from_script();
      return output;
    }

    public override Vx.Repl.Func_textblock_from_script vx_copy(params Object[] vals) {
      Class_textblock_from_script output = new Class_textblock_from_script();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/repl", // pkgname
        "textblock<-script", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
      return e_textblock_from_script;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_textblock_from_script;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Repl.f_textblock_from_script(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string script = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Repl.f_textblock_from_script(script);
      return output;
    }

    public Vx.Data.Textblock.Type_textblock vx_textblock_from_script(Vx.Core.Type_string script) {
      return Vx.Repl.f_textblock_from_script(script);
    }

  }

  public static Func_textblock_from_script e_textblock_from_script = new Vx.Repl.Class_textblock_from_script();
  public static Func_textblock_from_script t_textblock_from_script = new Vx.Repl.Class_textblock_from_script();

  public static Vx.Data.Textblock.Type_textblock f_textblock_from_script(Vx.Core.Type_string script) {
    Vx.Data.Textblock.Type_textblock output = Vx.Data.Textblock.e_textblock;
    output = Vx.Data.Textblock.f_textblock_parse_from_string_delim(
      script,
      Vx.Repl.c_delimvxlisp
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
  public interface Func_typefunc_from_string : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_any vx_typefunc_from_string(Vx.Core.Type_string text);
  }

  public class Class_typefunc_from_string : Vx.Core.Class_base, Func_typefunc_from_string {

    public override Vx.Repl.Func_typefunc_from_string vx_new(params Object[] vals) {
      Class_typefunc_from_string output = new Class_typefunc_from_string();
      return output;
    }

    public override Vx.Repl.Func_typefunc_from_string vx_copy(params Object[] vals) {
      Class_typefunc_from_string output = new Class_typefunc_from_string();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/repl", // pkgname
        "typefunc<-string", // name
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
      return e_typefunc_from_string;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_typefunc_from_string;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Repl.f_typefunc_from_string(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Repl.f_typefunc_from_string(text);
      return output;
    }

    public Vx.Core.Type_any vx_typefunc_from_string(Vx.Core.Type_string text) {
      return Vx.Repl.f_typefunc_from_string(text);
    }

  }

  public static Func_typefunc_from_string e_typefunc_from_string = new Vx.Repl.Class_typefunc_from_string();
  public static Func_typefunc_from_string t_typefunc_from_string = new Vx.Repl.Class_typefunc_from_string();

  public static Vx.Core.Type_any f_typefunc_from_string(Vx.Core.Type_string text) {
    Vx.Core.Type_any output = Vx.Core.e_any;
    output = Vx.Core.f_let(
      Vx.Core.t_any,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_int pkgpos = Vx.Type.f_int_from_string_findlast(text, Vx.Core.vx_new_string("/"));
        Vx.Core.Type_string pkgname = Vx.Core.f_if_1(
          Vx.Core.t_string,
          Vx.Core.f_eq(Vx.Core.vx_new_int(0), pkgpos),
          Vx.Core.vx_new_string("vx/core"),
          Vx.Type.f_string_from_string_end(
            text,
            Vx.Core.f_minus1(pkgpos)
          )
        );
        Vx.Core.Type_string name = Vx.Core.f_if_1(
          Vx.Core.t_string,
          Vx.Core.f_eq(Vx.Core.vx_new_int(0), pkgpos),
          text,
          Vx.Type.f_string_from_string_start(
            text,
            Vx.Core.f_plus1(pkgpos)
          )
        );
        Vx.Core.Type_package pkg = Vx.Core.f_package_global_from_name(pkgname);
        Vx.Core.Type_typemap typemap = pkg.typemap();
        Vx.Core.Type_any typeval = Vx.Core.f_any_from_map(Vx.Core.t_any, typemap, name);
        Vx.Core.Type_any output_2 = Vx.Core.f_if_1(
          Vx.Core.t_any,
          Vx.Core.f_notempty_1(typeval),
          typeval,
          Vx.Core.f_let(
            Vx.Core.t_any,
            Vx.Core.t_any_from_func.vx_fn_new(() => {
              Vx.Core.Type_funcmap funcmap = pkg.funcmap();
              Vx.Core.Type_any funcval = Vx.Core.f_any_from_map(Vx.Core.t_any, funcmap, name);
              Vx.Core.Type_any output_1 = Vx.Core.f_if_1(
                Vx.Core.t_any,
                Vx.Core.f_notempty_1(funcval),
                funcval,
                Vx.Core.f_empty(
                  Vx.Core.t_any
                )
              );
              return output_1;
            })
          )
        );
        return output_2;
      })
    );
    return output;
  }


  public static class PackageRunOnce {
    public static void RunOnce() {
    Const_delimvxlisp.const_new(c_delimvxlisp);
    Const_delimvxlispbracket.const_new(c_delimvxlispbracket);
    Const_delimvxlispparen.const_new(c_delimvxlispparen);
    Vx.Core.Map<string, Vx.Core.Type_any> maptype = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_any> mapconst = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_func> mapfunc = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>();
    maptype.put("liblist", Vx.Repl.t_liblist);
    maptype.put("repl", Vx.Repl.t_repl);
    maptype.put("replarglist", Vx.Repl.t_replarglist);
    maptype.put("repllist", Vx.Repl.t_repllist);
    mapconst.put("delimvxlisp", Vx.Repl.c_delimvxlisp);
    mapconst.put("delimvxlispbracket", Vx.Repl.c_delimvxlispbracket);
    mapconst.put("delimvxlispparen", Vx.Repl.c_delimvxlispparen);
    mapfunc.put("any-repl<-functype-args", Vx.Repl.t_any_repl_from_functype_args);
    mapfunc.put("any<-liblist-string", Vx.Repl.t_any_from_liblist_string);
    mapfunc.put("any<-macro", Vx.Repl.t_any_from_macro);
    mapfunc.put("any<-repl", Vx.Repl.t_any_from_repl);
    mapfunc.put("any<-script", Vx.Repl.t_any_from_script);
    mapfunc.put("anylist<-repllist", Vx.Repl.t_anylist_from_repllist);
    mapfunc.put("argmap<-textblock-argmap", Vx.Repl.t_argmap_from_textblock_argmap);
    mapfunc.put("const<-string", Vx.Repl.t_const_from_string);
    mapfunc.put("repl-bracket<-textblock-argmap", Vx.Repl.t_repl_bracket_from_textblock_argmap);
    mapfunc.put("repl-empty<-textblock-argmap", Vx.Repl.t_repl_empty_from_textblock_argmap);
    mapfunc.put("repl-paren<-textblock-argmap", Vx.Repl.t_repl_paren_from_textblock_argmap);
    mapfunc.put("repl<-liblist-string", Vx.Repl.t_repl_from_liblist_string);
    mapfunc.put("repl<-macro", Vx.Repl.t_repl_from_macro);
    mapfunc.put("repl<-script", Vx.Repl.t_repl_from_script);
    mapfunc.put("repl<-string-argmap", Vx.Repl.t_repl_from_string_argmap);
    mapfunc.put("repl<-textblock", Vx.Repl.t_repl_from_textblock);
    mapfunc.put("repl<-textblock-argmap", Vx.Repl.t_repl_from_textblock_argmap);
    mapfunc.put("replarglist<-replarglist-textblock-argmap", Vx.Repl.t_replarglist_from_replarglist_textblock_argmap);
    mapfunc.put("repllist<-textblocklist-argmap", Vx.Repl.t_repllist_from_textblocklist_argmap);
    mapfunc.put("textblock<-script", Vx.Repl.t_textblock_from_script);
    mapfunc.put("typefunc<-string", Vx.Repl.t_typefunc_from_string);
    Vx.Core.vx_global_package_set("vx/repl", maptype, mapconst, mapfunc);
    }
  }

}
