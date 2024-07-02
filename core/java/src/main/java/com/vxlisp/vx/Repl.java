package com.vxlisp.vx;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import com.vxlisp.vx.data.*;
import java.util.concurrent.CompletableFuture;

public final class Repl {

  // vx_string_from_listarg(type, context, liststring)
  public static String vx_string_from_listarg(Core.Type_any type, Core.Type_context context, List<String> listarg) {
    String output = "";
    List<Core.Type_any> listrepl = new ArrayList<>();
    boolean isfirst = true;
    for (String sarg : listarg) {
      if (isfirst) {
        isfirst = false;
      } else {
        Core.Type_any replval;
        if (Core.vx_is_int(sarg)) {
          replval = Core.vx_new_int(Core.vx_int_from_string(sarg));
        } else if (Core.vx_is_float(sarg)) {
          replval = Core.vx_new_float(Core.vx_float_from_string(sarg));
        } else {
          replval = Core.vx_new_string(sarg);
        }
        Repl.Type_repl argrepl = Core.vx_new(Repl.t_repl,
          Core.vx_new_string(":val"), replval
        );
        listrepl.add(argrepl);
      }
    }
    Repl.Type_repl repl = Core.vx_new(Repl.t_repl,
      Core.vx_new_string(":type"), type,
      Core.vx_new_string(":repllist"), Core.vx_new(Repl.t_repllist, listrepl)
    );
    Core.Type_any any = Repl.f_any_from_repl(context, repl);
    Core.Type_any anytype = any.vx_type();
    if (anytype == Core.t_string) {
      Core.Type_string text = Core.f_any_from_any(Core.t_string, any);
      output = text.vx_string();
    } else {
      output = Core.vx_string_from_any(any);
    }
    return output;
  }

  /**
   * type: liblist
   * List of library names
   * (type liblist)
   */
  public interface Type_liblist extends Core.Type_list {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public List<Core.Type_string> vx_liststring();
    public Core.Type_string vx_string(final Core.Type_int index);
  }

  public static class Class_liblist extends Core.Class_base implements Type_liblist {

    public List<Core.Type_string> vx_p_list = Core.immutablelist(new ArrayList<Core.Type_string>());

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));
      return output;
    }

    @Override
    public Core.Type_string vx_string(final Core.Type_int index) {
      Core.Type_string output = Core.e_string;
      Repl.Class_liblist list = this;
      int iindex = index.vx_int();
      List<Core.Type_string> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Core.Type_string> vx_liststring() {
      return vx_p_list;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_string(index);
    }

    @Override
    public Repl.Type_liblist vx_new(final Object... vals) {
      return Core.vx_copy(
       e_liblist,
       vals);
    }

    @Override
    public Repl.Type_liblist vx_copy(final Object... vals) {
      Type_liblist output = this;
      boolean ischanged = false;
      Class_liblist val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      List<Core.Type_string> listval = new ArrayList<Core.Type_string>(val.vx_liststring());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_string) {
          Core.Type_string anysub = (Core.Type_string)valsub;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub instanceof String) {
          ischanged = true;
          listval.add(Core.vx_new(Core.t_string, valsub));
        } else if (valsub instanceof Repl.Type_liblist) {
          Type_liblist multi = (Type_liblist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_liststring());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Core.Type_string) {
              Core.Type_string valitem = (Core.Type_string)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anysub = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/repl/liblist", ":invalidtype", anysub);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/repl/liblist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_liblist work = new Class_liblist();
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
      return e_liblist;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_liblist;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/repl", // pkgname
        "liblist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Core.t_string), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_liblist e_liblist = new Class_liblist();
  public static final Type_liblist t_liblist = new Class_liblist();

  /**
   * type: repl
   * Repl structure
   * (type repl)
   */
  public interface Type_repl extends Core.Type_struct {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Core.Type_string name();
    public Core.Type_any type();
    public Repl.Type_repllist repllist();
    public Core.Type_boolean async();
    public Core.Type_any val();
    public Core.Type_string doc();
  }

  public static class Class_repl extends Core.Class_base implements Type_repl {

    public Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    public Core.Type_any vx_p_type;

    @Override
    public Core.Type_any type() {
      return this.vx_p_type == null ? Core.e_any : this.vx_p_type;
    }

    public Repl.Type_repllist vx_p_repllist;

    @Override
    public Repl.Type_repllist repllist() {
      return this.vx_p_repllist == null ? Repl.e_repllist : this.vx_p_repllist;
    }

    public Core.Type_boolean vx_p_async;

    @Override
    public Core.Type_boolean async() {
      return this.vx_p_async == null ? Core.e_boolean : this.vx_p_async;
    }

    public Core.Type_any vx_p_val;

    @Override
    public Core.Type_any val() {
      return this.vx_p_val == null ? Core.e_any : this.vx_p_val;
    }

    public Core.Type_string vx_p_doc;

    @Override
    public Core.Type_string doc() {
      return this.vx_p_doc == null ? Core.e_string : this.vx_p_doc;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
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

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<String, Core.Type_any>();
      output.put(":name", this.name());
      output.put(":type", this.type());
      output.put(":repllist", this.repllist());
      output.put(":async", this.async());
      output.put(":val", this.val());
      output.put(":doc", this.doc());
      return Core.immutablemap(output);
    }

    @Override
    public Repl.Type_repl vx_new(final Object... vals) {
      return Core.vx_copy(
       e_repl,
       vals);
    }

    @Override
    public Repl.Type_repl vx_copy(final Object... vals) {
      Type_repl output = this;
      boolean ischanged = false;
      Class_repl val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = val.name();
      Core.Type_any vx_p_type = val.type();
      Repl.Type_repllist vx_p_repllist = val.repllist();
      Core.Type_boolean vx_p_async = val.async();
      Core.Type_any vx_p_val = val.val();
      Core.Type_string vx_p_doc = val.doc();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":name");
      validkeys.add(":type");
      validkeys.add(":repllist");
      validkeys.add(":async");
      validkeys.add(":val");
      validkeys.add(":doc");
      String key = "";
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
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
            msg = Core.vx_msg_from_error("vx/repl/repl", ":invalidkeytype", msgval);
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
              Core.Type_any msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/repl/repl", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
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
              vx_p_name = Core.vx_new(Core.t_string, valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/repl/repl", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":type":
            if (valsub == vx_p_type) {
            } else if (valsub instanceof Core.Type_any) {
              ischanged = true;
              vx_p_type = (Core.Type_any)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("type"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/repl/repl", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":repllist":
            if (valsub == vx_p_repllist) {
            } else if (valsub instanceof Repl.Type_repllist) {
              ischanged = true;
              vx_p_repllist = (Repl.Type_repllist)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("repllist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/repl/repl", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":async":
            if (valsub == vx_p_async) {
            } else if (valsub instanceof Core.Type_boolean) {
              ischanged = true;
              vx_p_async = (Core.Type_boolean)valsub;
            } else if (valsub instanceof Boolean) {
              ischanged = true;
              vx_p_async = Core.vx_new(Core.t_boolean, valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("async"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/repl/repl", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":val":
            if (valsub == vx_p_val) {
            } else if (valsub instanceof Core.Type_any) {
              ischanged = true;
              vx_p_val = (Core.Type_any)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("val"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/repl/repl", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":doc":
            if (valsub == vx_p_doc) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_doc = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_doc = Core.vx_new(Core.t_string, valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("doc"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/repl/repl", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/repl/repl", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_repl work = new Class_repl();
        work.vx_p_name = vx_p_name;
        work.vx_p_type = vx_p_type;
        work.vx_p_repllist = vx_p_repllist;
        work.vx_p_async = vx_p_async;
        work.vx_p_val = vx_p_val;
        work.vx_p_doc = vx_p_doc;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_repl;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_repl;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/repl", // pkgname
        "repl", // name
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

  public static final Type_repl e_repl = new Class_repl();
  public static final Type_repl t_repl = new Class_repl();

  /**
   * type: replarglist
   * Builder for a repllist
   * (type replarglist)
   */
  public interface Type_replarglist extends Core.Type_struct {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Core.Type_string key();
    public Repl.Type_repl current();
    public Repl.Type_repllist repllist();
  }

  public static class Class_replarglist extends Core.Class_base implements Type_replarglist {

    public Core.Type_string vx_p_key;

    @Override
    public Core.Type_string key() {
      return this.vx_p_key == null ? Core.e_string : this.vx_p_key;
    }

    public Repl.Type_repl vx_p_current;

    @Override
    public Repl.Type_repl current() {
      return this.vx_p_current == null ? Repl.e_repl : this.vx_p_current;
    }

    public Repl.Type_repllist vx_p_repllist;

    @Override
    public Repl.Type_repllist repllist() {
      return this.vx_p_repllist == null ? Repl.e_repllist : this.vx_p_repllist;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
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

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<String, Core.Type_any>();
      output.put(":key", this.key());
      output.put(":current", this.current());
      output.put(":repllist", this.repllist());
      return Core.immutablemap(output);
    }

    @Override
    public Repl.Type_replarglist vx_new(final Object... vals) {
      return Core.vx_copy(
       e_replarglist,
       vals);
    }

    @Override
    public Repl.Type_replarglist vx_copy(final Object... vals) {
      Type_replarglist output = this;
      boolean ischanged = false;
      Class_replarglist val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_key = val.key();
      Repl.Type_repl vx_p_current = val.current();
      Repl.Type_repllist vx_p_repllist = val.repllist();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":key");
      validkeys.add(":current");
      validkeys.add(":repllist");
      String key = "";
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
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
            msg = Core.vx_msg_from_error("vx/repl/replarglist", ":invalidkeytype", msgval);
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
              Core.Type_any msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/repl/replarglist", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":key":
            if (valsub == vx_p_key) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_key = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_key = Core.vx_new(Core.t_string, valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("key"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/repl/replarglist", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":current":
            if (valsub == vx_p_current) {
            } else if (valsub instanceof Repl.Type_repl) {
              ischanged = true;
              vx_p_current = (Repl.Type_repl)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("current"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/repl/replarglist", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":repllist":
            if (valsub == vx_p_repllist) {
            } else if (valsub instanceof Repl.Type_repllist) {
              ischanged = true;
              vx_p_repllist = (Repl.Type_repllist)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("repllist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/repl/replarglist", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/repl/replarglist", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_replarglist work = new Class_replarglist();
        work.vx_p_key = vx_p_key;
        work.vx_p_current = vx_p_current;
        work.vx_p_repllist = vx_p_repllist;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_replarglist;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_replarglist;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/repl", // pkgname
        "replarglist", // name
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

  public static final Type_replarglist e_replarglist = new Class_replarglist();
  public static final Type_replarglist t_replarglist = new Class_replarglist();

  /**
   * type: repllist
   * List of repl
   * (type repllist)
   */
  public interface Type_repllist extends Core.Type_list {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public List<Repl.Type_repl> vx_listrepl();
    public Repl.Type_repl vx_repl(final Core.Type_int index);
  }

  public static class Class_repllist extends Core.Class_base implements Type_repllist {

    public List<Repl.Type_repl> vx_p_list = Core.immutablelist(new ArrayList<Repl.Type_repl>());

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));
      return output;
    }

    @Override
    public Repl.Type_repl vx_repl(final Core.Type_int index) {
      Repl.Type_repl output = Repl.e_repl;
      Repl.Class_repllist list = this;
      int iindex = index.vx_int();
      List<Repl.Type_repl> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Repl.Type_repl> vx_listrepl() {
      return vx_p_list;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_repl(index);
    }

    @Override
    public Repl.Type_repllist vx_new(final Object... vals) {
      return Core.vx_copy(
       e_repllist,
       vals);
    }

    @Override
    public Repl.Type_repllist vx_copy(final Object... vals) {
      Type_repllist output = this;
      boolean ischanged = false;
      Class_repllist val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      List<Repl.Type_repl> listval = new ArrayList<Repl.Type_repl>(val.vx_listrepl());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Repl.Type_repl) {
          Repl.Type_repl anysub = (Repl.Type_repl)valsub;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub instanceof Repl.Type_repl) {
          ischanged = true;
          listval.add((Repl.Type_repl)valsub);
        } else if (valsub instanceof Repl.Type_repllist) {
          Type_repllist multi = (Type_repllist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listrepl());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Repl.Type_repl) {
              Repl.Type_repl valitem = (Repl.Type_repl)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anysub = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/repl/repllist", ":invalidtype", anysub);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/repl/repllist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_repllist work = new Class_repllist();
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
      return e_repllist;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_repllist;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/repl", // pkgname
        "repllist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Repl.t_repl), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_repllist e_repllist = new Class_repllist();
  public static final Type_repllist t_repllist = new Class_repllist();

  /**
   * Constant: delimvxlisp
   * vxlisp File Delimiters
   * {delim}
   */
  public static class Const_delimvxlisp extends Textblock.Class_delim implements Core.vx_Type_const {
    
    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/repl", // pkgname
        "delimvxlisp", // name
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimvxlisp output) {
      Textblock.Type_delim val = Core.f_new(
        Textblock.t_delim,
        Core.vx_new(Core.t_anylist,
                Core.vx_new_string(":name"),
                Core.vx_new_string("delimvxlisp"),
                Core.vx_new_string(":delimlist"),
                Core.f_new(
                  Textblock.t_delimlist,
                  Core.vx_new(Core.t_anylist,
                    Repl.c_delimvxlispparen,
                    Textblock.c_delimcomment,
                    Textblock.c_delimcommentblock
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

  public static final Const_delimvxlisp c_delimvxlisp = new Const_delimvxlisp();


  /**
   * Constant: delimvxlispbracket
   * vxlisp Square Bracket Delimiters
   * {delim}
   */
  public static class Const_delimvxlispbracket extends Textblock.Class_delim implements Core.vx_Type_const {
    
    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/repl", // pkgname
        "delimvxlispbracket", // name
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimvxlispbracket output) {
      Textblock.Type_delim val = Core.f_copy(
        Textblock.c_delimbracketsquare,
        Core.vx_new(Core.t_anylist,
                Core.vx_new_string(":name"),
                Core.vx_new_string("delimvxlispbracketsquare"),
                Core.vx_new_string(":delimlist"),
                Core.f_new(
                  Textblock.t_delimlist,
                  Core.vx_new(Core.t_anylist,
                    Textblock.c_delimcomment,
                    Textblock.c_delimcommentblock,
                    Textblock.c_delimquote,
                    Textblock.c_delimquoteblock,
                    Textblock.c_delimwhitespace,
                    Repl.c_delimvxlispparen
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

  public static final Const_delimvxlispbracket c_delimvxlispbracket = new Const_delimvxlispbracket();


  /**
   * Constant: delimvxlispparen
   * vxlisp Paren Delimiters
   * {delim}
   */
  public static class Const_delimvxlispparen extends Textblock.Class_delim implements Core.vx_Type_const {
    
    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/repl", // pkgname
        "delimvxlispparen", // name
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "delim", // name
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

    public static void const_new(Const_delimvxlispparen output) {
      Textblock.Type_delim val = Core.f_copy(
        Textblock.c_delimparen,
        Core.vx_new(Core.t_anylist,
                Core.vx_new_string(":name"),
                Core.vx_new_string("delimvxlispparen"),
                Core.vx_new_string(":delimlist"),
                Core.f_new(
                  Textblock.t_delimlist,
                  Core.vx_new(Core.t_anylist,
                    Textblock.c_delimcomment,
                    Textblock.c_delimcommentblock,
                    Textblock.c_delimquote,
                    Textblock.c_delimquoteblock,
                    Textblock.c_delimwhitespace,
                    Repl.c_delimvxlispbracket,
                    Repl.c_delimvxlispparen
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

  public static final Const_delimvxlispparen c_delimvxlispparen = new Const_delimvxlispparen();

  /**
   * @function any_repl_from_functype_args
   * Returns any from a repl func and args.
   * @param  {any} type
   * @param  {anylist} args
   * @return {any}
   * (func any-repl<-functype-args)
   */
  public interface Func_any_repl_from_functype_args extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_any vx_any_repl_from_functype_args(final Core.Type_any type, final Core.Type_anylist args);
  }

  public static class Class_any_repl_from_functype_args extends Core.Class_base implements Func_any_repl_from_functype_args {

    @Override
    public Repl.Func_any_repl_from_functype_args vx_new(final Object... vals) {
      Class_any_repl_from_functype_args output = new Class_any_repl_from_functype_args();
      return output;
    }

    @Override
    public Repl.Func_any_repl_from_functype_args vx_copy(final Object... vals) {
      Class_any_repl_from_functype_args output = new Class_any_repl_from_functype_args();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/repl", // pkgname
        "any-repl<-functype-args", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any", // name
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
      return e_any_repl_from_functype_args;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_any_repl_from_functype_args;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any type = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_anylist args = Core.f_any_from_any(Core.t_anylist, arglist.vx_any(Core.vx_new_int(1)));
      output = Repl.f_any_repl_from_functype_args(type, args);
      return output;
    }

    @Override
    public Core.Type_any vx_any_repl_from_functype_args(final Core.Type_any type, final Core.Type_anylist args) {
      return Repl.f_any_repl_from_functype_args(type, args);
    }

  }

  public static final Func_any_repl_from_functype_args e_any_repl_from_functype_args = new Repl.Class_any_repl_from_functype_args();
  public static final Func_any_repl_from_functype_args t_any_repl_from_functype_args = new Repl.Class_any_repl_from_functype_args();

  public static Core.Type_any f_any_repl_from_functype_args(final Core.Type_any type, final Core.Type_anylist args) {
    Core.Type_any output = Core.e_any;
    if (type instanceof Core.Type_replfunc) {
      Core.Type_replfunc replfunc = (Core.Type_replfunc)type;
      output = replfunc.vx_repl(args);
    };
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
  public interface Func_any_from_liblist_string extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_any vx_any_from_liblist_string(final Core.Type_context context, final Repl.Type_liblist liblist, final Core.Type_string text);
  }

  public static class Class_any_from_liblist_string extends Core.Class_base implements Func_any_from_liblist_string {

    @Override
    public Repl.Func_any_from_liblist_string vx_new(final Object... vals) {
      Class_any_from_liblist_string output = new Class_any_from_liblist_string();
      return output;
    }

    @Override
    public Repl.Func_any_from_liblist_string vx_copy(final Object... vals) {
      Class_any_from_liblist_string output = new Class_any_from_liblist_string();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/repl", // pkgname
        "any<-liblist-string", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any", // name
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
      return e_any_from_liblist_string;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_any_from_liblist_string;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Repl.Type_liblist liblist = Core.f_any_from_any(Repl.t_liblist, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Repl.f_any_from_liblist_string(context, liblist, text);
      return output;
    }

    @Override
    public Core.Type_any vx_any_from_liblist_string(final Core.Type_context context, final Repl.Type_liblist liblist, final Core.Type_string text) {
      return Repl.f_any_from_liblist_string(context, liblist, text);
    }

  }

  public static final Func_any_from_liblist_string e_any_from_liblist_string = new Repl.Class_any_from_liblist_string();
  public static final Func_any_from_liblist_string t_any_from_liblist_string = new Repl.Class_any_from_liblist_string();

  public static Core.Type_any f_any_from_liblist_string(final Core.Type_context context, final Repl.Type_liblist liblist, final Core.Type_string text) {
    Core.Type_any output = Core.e_any;
    output = Core.f_let(
      Core.t_any,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Repl.Type_repl repl = Repl.f_repl_from_liblist_string(liblist, text);
        return Repl.f_any_from_repl(context, repl);
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
  public interface Func_any_from_macro extends Core.Func_any_from_any_context {
    public <T extends Core.Type_any> T vx_any_from_macro(final T generic_any_1, final Core.Type_context context, final Core.Type_anylist anylist);
  }

  public static class Class_any_from_macro extends Core.Class_base implements Func_any_from_macro {

    @Override
    public Repl.Func_any_from_macro vx_new(final Object... vals) {
      Class_any_from_macro output = new Class_any_from_macro();
      return output;
    }

    @Override
    public Repl.Func_any_from_macro vx_copy(final Object... vals) {
      Class_any_from_macro output = new Class_any_from_macro();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/repl", // pkgname
        "any<-macro", // name
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
      return e_any_from_macro;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_any_from_macro;
    }

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {
      return Core.e_any_from_any_context;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_anylist inputval = (Core.Type_anylist)value;
      Core.Type_any outputval = Repl.f_any_from_macro(Core.t_any, context, inputval);
      output = Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any generic_any_1 = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_anylist anylist = Core.f_any_from_any(Core.t_anylist, arglist.vx_any(Core.vx_new_int(0)));
      output = Repl.f_any_from_macro(generic_any_1, context, anylist);
      return output;
    }

    @Override
    public <T extends Core.Type_any> T vx_any_from_macro(final T generic_any_1, final Core.Type_context context, final Core.Type_anylist anylist) {
      return Repl.f_any_from_macro(generic_any_1, context, anylist);
    }

  }

  public static final Func_any_from_macro e_any_from_macro = new Repl.Class_any_from_macro();
  public static final Func_any_from_macro t_any_from_macro = new Repl.Class_any_from_macro();

  public static <T extends Core.Type_any> T f_any_from_macro(final T generic_any_1, final Core.Type_context context, final Core.Type_anylist anylist) {
    T output = Core.f_empty(generic_any_1);
    output = Core.f_let(
      generic_any_1,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Repl.Type_repl repl = Repl.f_repl_from_macro(context, anylist);
        final Core.Type_any val = Repl.f_any_from_repl(context, repl);
        return Core.f_any_from_any(generic_any_1, val);
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
  public interface Func_any_from_repl extends Core.Func_any_from_any_context {
    public Core.Type_any vx_any_from_repl(final Core.Type_context context, final Repl.Type_repl repl);
  }

  public static class Class_any_from_repl extends Core.Class_base implements Func_any_from_repl {

    @Override
    public Repl.Func_any_from_repl vx_new(final Object... vals) {
      Class_any_from_repl output = new Class_any_from_repl();
      return output;
    }

    @Override
    public Repl.Func_any_from_repl vx_copy(final Object... vals) {
      Class_any_from_repl output = new Class_any_from_repl();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/repl", // pkgname
        "any<-repl", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any", // name
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
      return e_any_from_repl;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_any_from_repl;
    }

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {
      return Core.e_any_from_any_context;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Repl.Type_repl inputval = (Repl.Type_repl)value;
      Core.Type_any outputval = Repl.f_any_from_repl(context, inputval);
      output = Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Repl.Type_repl repl = Core.f_any_from_any(Repl.t_repl, arglist.vx_any(Core.vx_new_int(0)));
      output = Repl.f_any_from_repl(context, repl);
      return output;
    }

    @Override
    public Core.Type_any vx_any_from_repl(final Core.Type_context context, final Repl.Type_repl repl) {
      return Repl.f_any_from_repl(context, repl);
    }

  }

  public static final Func_any_from_repl e_any_from_repl = new Repl.Class_any_from_repl();
  public static final Func_any_from_repl t_any_from_repl = new Repl.Class_any_from_repl();

  public static Core.Type_any f_any_from_repl(final Core.Type_context context, final Repl.Type_repl repl) {
    Core.Type_any output = Core.e_any;
    output = Core.f_let(
      Core.t_any,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_any val = repl.val();
        final Core.Type_any repltype = repl.type();
        final Repl.Type_repllist repllist = repl.repllist();
        final Core.Type_anylist args = Repl.f_anylist_from_repllist(context, repllist);
        return Core.f_if_2(
          Core.t_any,
          Core.vx_new(Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_notempty_1(val);
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return val;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_is_func(repltype);
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Repl.f_any_repl_from_functype_args(repltype, args);
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_new(repltype, args);
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
  public interface Func_any_from_script extends Core.Func_any_from_any_context {
    public Core.Type_any vx_any_from_script(final Core.Type_context context, final Core.Type_string script);
  }

  public static class Class_any_from_script extends Core.Class_base implements Func_any_from_script {

    @Override
    public Repl.Func_any_from_script vx_new(final Object... vals) {
      Class_any_from_script output = new Class_any_from_script();
      return output;
    }

    @Override
    public Repl.Func_any_from_script vx_copy(final Object... vals) {
      Class_any_from_script output = new Class_any_from_script();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/repl", // pkgname
        "any<-script", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any", // name
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
      return e_any_from_script;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_any_from_script;
    }

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {
      return Core.e_any_from_any_context;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Repl.f_any_from_script(context, inputval);
      output = Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string script = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Repl.f_any_from_script(context, script);
      return output;
    }

    @Override
    public Core.Type_any vx_any_from_script(final Core.Type_context context, final Core.Type_string script) {
      return Repl.f_any_from_script(context, script);
    }

  }

  public static final Func_any_from_script e_any_from_script = new Repl.Class_any_from_script();
  public static final Func_any_from_script t_any_from_script = new Repl.Class_any_from_script();

  public static Core.Type_any f_any_from_script(final Core.Type_context context, final Core.Type_string script) {
    Core.Type_any output = Core.e_any;
    output = Core.f_let(
      Core.t_any,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Textblock.Type_textblock textblock = Repl.f_textblock_from_script(script);
        final Repl.Type_repl repl = Repl.f_repl_from_textblock(textblock);
        return Repl.f_any_from_repl(context, repl);
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
  public interface Func_anylist_from_repllist extends Core.Func_any_from_any_context {
    public Core.Type_anylist vx_anylist_from_repllist(final Core.Type_context context, final Repl.Type_repllist repllist);
  }

  public static class Class_anylist_from_repllist extends Core.Class_base implements Func_anylist_from_repllist {

    @Override
    public Repl.Func_anylist_from_repllist vx_new(final Object... vals) {
      Class_anylist_from_repllist output = new Class_anylist_from_repllist();
      return output;
    }

    @Override
    public Repl.Func_anylist_from_repllist vx_copy(final Object... vals) {
      Class_anylist_from_repllist output = new Class_anylist_from_repllist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/repl", // pkgname
        "anylist<-repllist", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "anylist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Core.t_any), // allowtypes
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
      return e_anylist_from_repllist;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_anylist_from_repllist;
    }

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {
      return Core.e_any_from_any_context;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Repl.Type_repllist inputval = (Repl.Type_repllist)value;
      Core.Type_any outputval = Repl.f_anylist_from_repllist(context, inputval);
      output = Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Repl.Type_repllist repllist = Core.f_any_from_any(Repl.t_repllist, arglist.vx_any(Core.vx_new_int(0)));
      output = Repl.f_anylist_from_repllist(context, repllist);
      return output;
    }

    @Override
    public Core.Type_anylist vx_anylist_from_repllist(final Core.Type_context context, final Repl.Type_repllist repllist) {
      return Repl.f_anylist_from_repllist(context, repllist);
    }

  }

  public static final Func_anylist_from_repllist e_anylist_from_repllist = new Repl.Class_anylist_from_repllist();
  public static final Func_anylist_from_repllist t_anylist_from_repllist = new Repl.Class_anylist_from_repllist();

  public static Core.Type_anylist f_anylist_from_repllist(final Core.Type_context context, final Repl.Type_repllist repllist) {
    Core.Type_anylist output = Core.e_anylist;
    output = Core.f_list_from_list_1(
      Core.t_anylist,
      repllist,
      Core.t_any_from_any.vx_fn_new((repl_any) -> {
        Repl.Type_repl repl = Core.f_any_from_any(Repl.t_repl, repl_any);
        return 
        Repl.f_any_from_repl(context, repl);
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
  public interface Func_argmap_from_textblock_argmap extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_argmap vx_argmap_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap);
  }

  public static class Class_argmap_from_textblock_argmap extends Core.Class_base implements Func_argmap_from_textblock_argmap {

    @Override
    public Repl.Func_argmap_from_textblock_argmap vx_new(final Object... vals) {
      Class_argmap_from_textblock_argmap output = new Class_argmap_from_textblock_argmap();
      return output;
    }

    @Override
    public Repl.Func_argmap_from_textblock_argmap vx_copy(final Object... vals) {
      Class_argmap_from_textblock_argmap output = new Class_argmap_from_textblock_argmap();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/repl", // pkgname
        "argmap<-textblock-argmap", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "argmap", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Core.t_arg), // allowtypes
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
      return e_argmap_from_textblock_argmap;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_argmap_from_textblock_argmap;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_argmap argmap = Core.f_any_from_any(Core.t_argmap, arglist.vx_any(Core.vx_new_int(1)));
      output = Repl.f_argmap_from_textblock_argmap(textblock, argmap);
      return output;
    }

    @Override
    public Core.Type_argmap vx_argmap_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap) {
      return Repl.f_argmap_from_textblock_argmap(textblock, argmap);
    }

  }

  public static final Func_argmap_from_textblock_argmap e_argmap_from_textblock_argmap = new Repl.Class_argmap_from_textblock_argmap();
  public static final Func_argmap_from_textblock_argmap t_argmap_from_textblock_argmap = new Repl.Class_argmap_from_textblock_argmap();

  public static Core.Type_argmap f_argmap_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap) {
    Core.Type_argmap output = Core.e_argmap;
    output = Core.f_if_1(
      Core.t_argmap,
      Core.f_ne(
        Core.vx_new_string("delimbracketsquare"),
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
  public interface Func_const_from_string extends Core.Func_any_from_any {
    public Core.Type_any vx_const_from_string(final Core.Type_string text);
  }

  public static class Class_const_from_string extends Core.Class_base implements Func_const_from_string {

    @Override
    public Repl.Func_const_from_string vx_new(final Object... vals) {
      Class_const_from_string output = new Class_const_from_string();
      return output;
    }

    @Override
    public Repl.Func_const_from_string vx_copy(final Object... vals) {
      Class_const_from_string output = new Class_const_from_string();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/repl", // pkgname
        "const<-string", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any", // name
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
      return e_const_from_string;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_const_from_string;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Repl.f_const_from_string(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Repl.f_const_from_string(text);
      return output;
    }

    @Override
    public Core.Type_any vx_const_from_string(final Core.Type_string text) {
      return Repl.f_const_from_string(text);
    }

  }

  public static final Func_const_from_string e_const_from_string = new Repl.Class_const_from_string();
  public static final Func_const_from_string t_const_from_string = new Repl.Class_const_from_string();

  public static Core.Type_any f_const_from_string(final Core.Type_string text) {
    Core.Type_any output = Core.e_any;
    output = Core.f_let(
      Core.t_any,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_int pkgpos = Type.f_int_from_string_findlast(text, Core.vx_new_string("/"));
        final Core.Type_string pkgname = Core.f_if_1(
          Core.t_string,
          Core.f_eq(Core.vx_new_int(0), pkgpos),
          Core.vx_new_string("vx/core"),
          Type.f_string_from_string_end(
            text,
            Core.f_minus1(pkgpos)
          )
        );
        final Core.Type_string name = Core.f_if_1(
          Core.t_string,
          Core.f_eq(Core.vx_new_int(0), pkgpos),
          text,
          Type.f_string_from_string_start(
            text,
            Core.f_plus1(pkgpos)
          )
        );
        final Core.Type_package pkg = Core.f_package_global_from_name(pkgname);
        final Core.Type_constmap constmap = pkg.constmap();
        final Core.Type_any constval = Core.f_any_from_map(Core.t_any, constmap, name);
        return Core.f_if_1(
          Core.t_any,
          Core.f_notempty_1(constval),
          constval,
          Core.f_empty(
            Core.t_any
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
  public interface Func_repl_bracket_from_textblock_argmap extends Core.Type_func, Core.Type_replfunc {
    public Repl.Type_repl vx_repl_bracket_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap);
  }

  public static class Class_repl_bracket_from_textblock_argmap extends Core.Class_base implements Func_repl_bracket_from_textblock_argmap {

    @Override
    public Repl.Func_repl_bracket_from_textblock_argmap vx_new(final Object... vals) {
      Class_repl_bracket_from_textblock_argmap output = new Class_repl_bracket_from_textblock_argmap();
      return output;
    }

    @Override
    public Repl.Func_repl_bracket_from_textblock_argmap vx_copy(final Object... vals) {
      Class_repl_bracket_from_textblock_argmap output = new Class_repl_bracket_from_textblock_argmap();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/repl", // pkgname
        "repl-bracket<-textblock-argmap", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_bracket_from_textblock_argmap;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_repl_bracket_from_textblock_argmap;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_argmap argmap = Core.f_any_from_any(Core.t_argmap, arglist.vx_any(Core.vx_new_int(1)));
      output = Repl.f_repl_bracket_from_textblock_argmap(textblock, argmap);
      return output;
    }

    @Override
    public Repl.Type_repl vx_repl_bracket_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap) {
      return Repl.f_repl_bracket_from_textblock_argmap(textblock, argmap);
    }

  }

  public static final Func_repl_bracket_from_textblock_argmap e_repl_bracket_from_textblock_argmap = new Repl.Class_repl_bracket_from_textblock_argmap();
  public static final Func_repl_bracket_from_textblock_argmap t_repl_bracket_from_textblock_argmap = new Repl.Class_repl_bracket_from_textblock_argmap();

  public static Repl.Type_repl f_repl_bracket_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap) {
    Repl.Type_repl output = Repl.e_repl;
    output = Core.f_empty(
      Repl.t_repl
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
  public interface Func_repl_empty_from_textblock_argmap extends Core.Type_func, Core.Type_replfunc {
    public Repl.Type_repl vx_repl_empty_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap);
  }

  public static class Class_repl_empty_from_textblock_argmap extends Core.Class_base implements Func_repl_empty_from_textblock_argmap {

    @Override
    public Repl.Func_repl_empty_from_textblock_argmap vx_new(final Object... vals) {
      Class_repl_empty_from_textblock_argmap output = new Class_repl_empty_from_textblock_argmap();
      return output;
    }

    @Override
    public Repl.Func_repl_empty_from_textblock_argmap vx_copy(final Object... vals) {
      Class_repl_empty_from_textblock_argmap output = new Class_repl_empty_from_textblock_argmap();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/repl", // pkgname
        "repl-empty<-textblock-argmap", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_empty_from_textblock_argmap;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_repl_empty_from_textblock_argmap;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_argmap argmap = Core.f_any_from_any(Core.t_argmap, arglist.vx_any(Core.vx_new_int(1)));
      output = Repl.f_repl_empty_from_textblock_argmap(textblock, argmap);
      return output;
    }

    @Override
    public Repl.Type_repl vx_repl_empty_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap) {
      return Repl.f_repl_empty_from_textblock_argmap(textblock, argmap);
    }

  }

  public static final Func_repl_empty_from_textblock_argmap e_repl_empty_from_textblock_argmap = new Repl.Class_repl_empty_from_textblock_argmap();
  public static final Func_repl_empty_from_textblock_argmap t_repl_empty_from_textblock_argmap = new Repl.Class_repl_empty_from_textblock_argmap();

  public static Repl.Type_repl f_repl_empty_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap) {
    Repl.Type_repl output = Repl.e_repl;
    output = Core.f_let(
      Repl.t_repl,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Textblock.Type_textblocklist children = textblock.children();
        final Core.Type_int len = Core.f_length_1(children);
        return Core.f_switch(
          Repl.t_repl,
          len,
          Core.vx_new(Core.t_thenelselist,
            Core.f_case_1(
              Core.vx_new_int(0),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Repl.f_repl_from_string_argmap(
                  textblock.text(),
                  argmap
                );
              })
            ),
            Core.f_case_1(
              Core.vx_new_int(1),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Repl.f_repl_from_textblock_argmap(
                  Core.f_any_from_list(Textblock.t_textblock, children, Core.vx_new_int(1)),
                  argmap
                );
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_new(
                  Repl.t_repl,
                  Core.vx_new(Core.t_anylist,
                      Core.f_msg_from_error(Core.vx_new_string("Empty delim cannot have more than one child."))
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
  public interface Func_repl_paren_from_textblock_argmap extends Core.Type_func, Core.Type_replfunc {
    public Repl.Type_repl vx_repl_paren_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap);
  }

  public static class Class_repl_paren_from_textblock_argmap extends Core.Class_base implements Func_repl_paren_from_textblock_argmap {

    @Override
    public Repl.Func_repl_paren_from_textblock_argmap vx_new(final Object... vals) {
      Class_repl_paren_from_textblock_argmap output = new Class_repl_paren_from_textblock_argmap();
      return output;
    }

    @Override
    public Repl.Func_repl_paren_from_textblock_argmap vx_copy(final Object... vals) {
      Class_repl_paren_from_textblock_argmap output = new Class_repl_paren_from_textblock_argmap();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/repl", // pkgname
        "repl-paren<-textblock-argmap", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_paren_from_textblock_argmap;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_repl_paren_from_textblock_argmap;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_argmap argmap = Core.f_any_from_any(Core.t_argmap, arglist.vx_any(Core.vx_new_int(1)));
      output = Repl.f_repl_paren_from_textblock_argmap(textblock, argmap);
      return output;
    }

    @Override
    public Repl.Type_repl vx_repl_paren_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap) {
      return Repl.f_repl_paren_from_textblock_argmap(textblock, argmap);
    }

  }

  public static final Func_repl_paren_from_textblock_argmap e_repl_paren_from_textblock_argmap = new Repl.Class_repl_paren_from_textblock_argmap();
  public static final Func_repl_paren_from_textblock_argmap t_repl_paren_from_textblock_argmap = new Repl.Class_repl_paren_from_textblock_argmap();

  public static Repl.Type_repl f_repl_paren_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap) {
    Repl.Type_repl output = Repl.e_repl;
    output = Core.f_let(
      Repl.t_repl,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Textblock.Type_textblocklist childlst = textblock.children();
        final Textblock.Type_textblocklist children = Textblock.f_textblocklist_from_textblocklist_remove(
          childlst,
          Textblock.c_delimwhitespace
        );
        final Textblock.Type_textblock tbfunc = Core.f_any_from_list(Textblock.t_textblock, children, Core.vx_new_int(1));
        final Core.Type_string sfunc = tbfunc.text();
        final Repl.Type_repl replfunc = Repl.f_repl_from_string_argmap(sfunc, argmap);
        final Core.Type_any typefunc = replfunc.type();
        final Core.Type_int posarg = Core.f_switch(
          Core.t_int,
          typefunc,
          Core.vx_new(Core.t_thenelselist,
              Core.f_case_1(
                Core.t_let,
                Core.t_any_from_func.vx_fn_new(() -> {
                  return Core.vx_new_int(3);
                })
              ),
              Core.f_case_1(
                Core.t_fn,
                Core.t_any_from_func.vx_fn_new(() -> {
                  return Core.vx_new_int(3);
                })
              ),
              Core.f_else(
                Core.t_any_from_func.vx_fn_new(() -> {
                  return Core.vx_new_int(2);
                })
              )
          )
        );
        final Core.Type_argmap argmap2 = Core.f_switch(
          Core.t_argmap,
          typefunc,
          Core.vx_new(Core.t_thenelselist,
              Core.f_case_1(
                Core.t_let,
                Core.t_any_from_func.vx_fn_new(() -> {
                  return Repl.f_argmap_from_textblock_argmap(
                    Core.f_any_from_list(Textblock.t_textblock, children, Core.vx_new_int(3)),
                    argmap
                  );
                })
              ),
              Core.f_case_1(
                Core.t_fn,
                Core.t_any_from_func.vx_fn_new(() -> {
                  return Repl.f_argmap_from_textblock_argmap(
                    Core.f_any_from_list(Textblock.t_textblock, children, Core.vx_new_int(3)),
                    argmap
                  );
                })
              ),
              Core.f_else(
                Core.t_any_from_func.vx_fn_new(() -> {
                  return argmap;
                })
              )
          )
        );
        final Textblock.Type_textblocklist tbargs = Collection.f_list_from_list_start(Textblock.t_textblocklist, children, posarg);
        final Repl.Type_repllist replargs = Repl.f_repllist_from_textblocklist_argmap(tbargs, argmap);
        return Core.f_copy(
          replfunc,
          Core.vx_new(Core.t_anylist,
            Core.vx_new_string(":repllist"),
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
  public interface Func_repl_from_liblist_string extends Core.Type_func, Core.Type_replfunc {
    public Repl.Type_repl vx_repl_from_liblist_string(final Repl.Type_liblist liblist, final Core.Type_string text);
  }

  public static class Class_repl_from_liblist_string extends Core.Class_base implements Func_repl_from_liblist_string {

    @Override
    public Repl.Func_repl_from_liblist_string vx_new(final Object... vals) {
      Class_repl_from_liblist_string output = new Class_repl_from_liblist_string();
      return output;
    }

    @Override
    public Repl.Func_repl_from_liblist_string vx_copy(final Object... vals) {
      Class_repl_from_liblist_string output = new Class_repl_from_liblist_string();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/repl", // pkgname
        "repl<-liblist-string", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_from_liblist_string;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_repl_from_liblist_string;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Repl.Type_liblist liblist = Core.f_any_from_any(Repl.t_liblist, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Repl.f_repl_from_liblist_string(liblist, text);
      return output;
    }

    @Override
    public Repl.Type_repl vx_repl_from_liblist_string(final Repl.Type_liblist liblist, final Core.Type_string text) {
      return Repl.f_repl_from_liblist_string(liblist, text);
    }

  }

  public static final Func_repl_from_liblist_string e_repl_from_liblist_string = new Repl.Class_repl_from_liblist_string();
  public static final Func_repl_from_liblist_string t_repl_from_liblist_string = new Repl.Class_repl_from_liblist_string();

  public static Repl.Type_repl f_repl_from_liblist_string(final Repl.Type_liblist liblist, final Core.Type_string text) {
    Repl.Type_repl output = Repl.e_repl;
    return output;
  }

  /**
   * @function repl_from_macro
   * A function that joins any number of values into a string and then parses it.
   * @param  {anylist} anylist
   * @return {repl}
   * (func repl<-macro)
   */
  public interface Func_repl_from_macro extends Core.Func_any_from_any_context {
    public Repl.Type_repl vx_repl_from_macro(final Core.Type_context context, final Core.Type_anylist anylist);
  }

  public static class Class_repl_from_macro extends Core.Class_base implements Func_repl_from_macro {

    @Override
    public Repl.Func_repl_from_macro vx_new(final Object... vals) {
      Class_repl_from_macro output = new Class_repl_from_macro();
      return output;
    }

    @Override
    public Repl.Func_repl_from_macro vx_copy(final Object... vals) {
      Class_repl_from_macro output = new Class_repl_from_macro();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/repl", // pkgname
        "repl<-macro", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_from_macro;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_repl_from_macro;
    }

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {
      return Core.e_any_from_any_context;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_anylist inputval = (Core.Type_anylist)value;
      Core.Type_any outputval = Repl.f_repl_from_macro(context, inputval);
      output = Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_anylist anylist = Core.f_any_from_any(Core.t_anylist, arglist.vx_any(Core.vx_new_int(0)));
      output = Repl.f_repl_from_macro(context, anylist);
      return output;
    }

    @Override
    public Repl.Type_repl vx_repl_from_macro(final Core.Type_context context, final Core.Type_anylist anylist) {
      return Repl.f_repl_from_macro(context, anylist);
    }

  }

  public static final Func_repl_from_macro e_repl_from_macro = new Repl.Class_repl_from_macro();
  public static final Func_repl_from_macro t_repl_from_macro = new Repl.Class_repl_from_macro();

  public static Repl.Type_repl f_repl_from_macro(final Core.Type_context context, final Core.Type_anylist anylist) {
    Repl.Type_repl output = Repl.e_repl;
    output = Core.f_let(
      Repl.t_repl,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_stringlist textlist = Core.f_list_from_list_1(
          Core.t_stringlist,
          anylist,
          Core.t_any_from_any.vx_fn_new((item_any) -> {
            Core.Type_any item = Core.f_any_from_any(Core.t_any, item_any);
            return 
              Core.f_let(
                Core.t_string,
                Core.t_any_from_func.vx_fn_new(() -> {
                  final Core.Type_any typ = Core.f_type_from_any(item);
                  return Core.f_switch(
                    Core.t_string,
                    typ,
                    Core.vx_new(Core.t_thenelselist,
                      Core.f_case_1(
                        Core.t_string,
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.f_any_from_any(Core.t_string, item);
                        })
                      ),
                      Core.f_else(
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.f_string_from_any(item);
                        })
                      )
                    )
                  );
                })
              );
          })
        );
        final Core.Type_string script = Type.f_string_from_stringlist_join(textlist, Core.vx_new_string(""));
        final Textblock.Type_textblock tb = Repl.f_textblock_from_script(script);
        return Repl.f_repl_from_textblock(tb);
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
  public interface Func_repl_from_script extends Core.Func_any_from_any {
    public Repl.Type_repl vx_repl_from_script(final Core.Type_string script);
  }

  public static class Class_repl_from_script extends Core.Class_base implements Func_repl_from_script {

    @Override
    public Repl.Func_repl_from_script vx_new(final Object... vals) {
      Class_repl_from_script output = new Class_repl_from_script();
      return output;
    }

    @Override
    public Repl.Func_repl_from_script vx_copy(final Object... vals) {
      Class_repl_from_script output = new Class_repl_from_script();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/repl", // pkgname
        "repl<-script", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_from_script;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_repl_from_script;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Repl.f_repl_from_script(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string script = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Repl.f_repl_from_script(script);
      return output;
    }

    @Override
    public Repl.Type_repl vx_repl_from_script(final Core.Type_string script) {
      return Repl.f_repl_from_script(script);
    }

  }

  public static final Func_repl_from_script e_repl_from_script = new Repl.Class_repl_from_script();
  public static final Func_repl_from_script t_repl_from_script = new Repl.Class_repl_from_script();

  public static Repl.Type_repl f_repl_from_script(final Core.Type_string script) {
    Repl.Type_repl output = Repl.e_repl;
    output = Core.f_let(
      Repl.t_repl,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Textblock.Type_textblock textblock = Repl.f_textblock_from_script(script);
        return Repl.f_repl_from_textblock(textblock);
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
  public interface Func_repl_from_string_argmap extends Core.Type_func, Core.Type_replfunc {
    public Repl.Type_repl vx_repl_from_string_argmap(final Core.Type_string text, final Core.Type_argmap argmap);
  }

  public static class Class_repl_from_string_argmap extends Core.Class_base implements Func_repl_from_string_argmap {

    @Override
    public Repl.Func_repl_from_string_argmap vx_new(final Object... vals) {
      Class_repl_from_string_argmap output = new Class_repl_from_string_argmap();
      return output;
    }

    @Override
    public Repl.Func_repl_from_string_argmap vx_copy(final Object... vals) {
      Class_repl_from_string_argmap output = new Class_repl_from_string_argmap();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/repl", // pkgname
        "repl<-string-argmap", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_from_string_argmap;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_repl_from_string_argmap;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_argmap argmap = Core.f_any_from_any(Core.t_argmap, arglist.vx_any(Core.vx_new_int(1)));
      output = Repl.f_repl_from_string_argmap(text, argmap);
      return output;
    }

    @Override
    public Repl.Type_repl vx_repl_from_string_argmap(final Core.Type_string text, final Core.Type_argmap argmap) {
      return Repl.f_repl_from_string_argmap(text, argmap);
    }

  }

  public static final Func_repl_from_string_argmap e_repl_from_string_argmap = new Repl.Class_repl_from_string_argmap();
  public static final Func_repl_from_string_argmap t_repl_from_string_argmap = new Repl.Class_repl_from_string_argmap();

  public static Repl.Type_repl f_repl_from_string_argmap(final Core.Type_string text, final Core.Type_argmap argmap) {
    Repl.Type_repl output = Repl.e_repl;
    output = Core.f_if_2(
      Repl.t_repl,
      Core.vx_new(Core.t_thenelselist,
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            return Core.f_and(
              Type.f_boolean_from_string_starts(
                text,
                Core.c_quote
              ),
              Type.f_boolean_from_string_ends(
                text,
                Core.c_quote
              )
            );
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.f_new(
              Repl.t_repl,
              Core.vx_new(Core.t_anylist,
                  Core.vx_new_string(":val"),
                  Type.f_string_from_string_start_end(text, Core.vx_new_int(2), Core.vx_new_int(-1))
              )
            );
          })
        ),
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            return Core.f_is_int(text);
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.f_new(
              Repl.t_repl,
              Core.vx_new(Core.t_anylist,
                  Core.vx_new_string(":val"),
                  Core.f_int_from_string(text)
              )
            );
          })
        ),
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            return Core.f_is_float(text);
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.f_new(
              Repl.t_repl,
              Core.vx_new(Core.t_anylist,
                  Core.vx_new_string(":val"),
                  Core.f_float_from_string(text)
              )
            );
          })
        ),
        Core.f_else(
          Core.t_any_from_func.vx_fn_new(() -> {
            return Core.f_let(
              Repl.t_repl,
              Core.t_any_from_func.vx_fn_new(() -> {
                final Core.Type_any arg = Core.f_any_from_map(Core.t_any, argmap, text);
                return Core.f_if_2(
                  Repl.t_repl,
                  Core.vx_new(Core.t_thenelselist,
                    Core.f_then(
                      Core.t_boolean_from_func.vx_fn_new(() -> {
                        return Core.f_notempty_1(arg);
                      }),
                      Core.t_any_from_func.vx_fn_new(() -> {
                        return Core.f_new(
                          Repl.t_repl,
                          Core.vx_new(Core.t_anylist,
                              Core.vx_new_string(":val"),
                              arg
                          )
                        );
                      })
                    ),
                    Core.f_else(
                      Core.t_any_from_func.vx_fn_new(() -> {
                        return Core.f_let(
                          Repl.t_repl,
                          Core.t_any_from_func.vx_fn_new(() -> {
                            final Core.Type_any cnst = Repl.f_const_from_string(text);
                            return Core.f_if_2(
                              Repl.t_repl,
                              Core.vx_new(Core.t_thenelselist,
                                Core.f_then(
                                  Core.t_boolean_from_func.vx_fn_new(() -> {
                                    return Core.f_notempty_1(cnst);
                                  }),
                                  Core.t_any_from_func.vx_fn_new(() -> {
                                    return Core.f_new(
                                      Repl.t_repl,
                                      Core.vx_new(Core.t_anylist,
                                          Core.vx_new_string(":val"),
                                          cnst
                                      )
                                    );
                                  })
                                ),
                                Core.f_else(
                                  Core.t_any_from_func.vx_fn_new(() -> {
                                    return Core.f_let(
                                      Repl.t_repl,
                                      Core.t_any_from_func.vx_fn_new(() -> {
                                        final Core.Type_any typefunc = Repl.f_typefunc_from_string(text);
                                        return Core.f_if_2(
                                          Repl.t_repl,
                                          Core.vx_new(Core.t_thenelselist,
                                            Core.f_then(
                                              Core.t_boolean_from_func.vx_fn_new(() -> {
                                                return Core.f_notempty_1(typefunc);
                                              }),
                                              Core.t_any_from_func.vx_fn_new(() -> {
                                                return Core.f_new(
                                                  Repl.t_repl,
                                                  Core.vx_new(Core.t_anylist,
                                                      Core.vx_new_string(":type"),
                                                      typefunc
                                                  )
                                                );
                                              })
                                            ),
                                            Core.f_else(
                                              Core.t_any_from_func.vx_fn_new(() -> {
                                                return Core.f_new(
                                                  Repl.t_repl,
                                                  Core.vx_new(Core.t_anylist,
                                                      Core.f_msg_from_error_1(Core.vx_new_string(":repltypenotfound"), text)
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
  public interface Func_repl_from_textblock extends Core.Func_any_from_any {
    public Repl.Type_repl vx_repl_from_textblock(final Textblock.Type_textblock textblock);
  }

  public static class Class_repl_from_textblock extends Core.Class_base implements Func_repl_from_textblock {

    @Override
    public Repl.Func_repl_from_textblock vx_new(final Object... vals) {
      Class_repl_from_textblock output = new Class_repl_from_textblock();
      return output;
    }

    @Override
    public Repl.Func_repl_from_textblock vx_copy(final Object... vals) {
      Class_repl_from_textblock output = new Class_repl_from_textblock();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/repl", // pkgname
        "repl<-textblock", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_from_textblock;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_repl_from_textblock;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Textblock.Type_textblock inputval = (Textblock.Type_textblock)value;
      Core.Type_any outputval = Repl.f_repl_from_textblock(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Repl.f_repl_from_textblock(textblock);
      return output;
    }

    @Override
    public Repl.Type_repl vx_repl_from_textblock(final Textblock.Type_textblock textblock) {
      return Repl.f_repl_from_textblock(textblock);
    }

  }

  public static final Func_repl_from_textblock e_repl_from_textblock = new Repl.Class_repl_from_textblock();
  public static final Func_repl_from_textblock t_repl_from_textblock = new Repl.Class_repl_from_textblock();

  public static Repl.Type_repl f_repl_from_textblock(final Textblock.Type_textblock textblock) {
    Repl.Type_repl output = Repl.e_repl;
    output = Repl.f_repl_from_textblock_argmap(
      textblock,
      Core.f_empty(
        Core.t_argmap
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
  public interface Func_repl_from_textblock_argmap extends Core.Type_func, Core.Type_replfunc {
    public Repl.Type_repl vx_repl_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap);
  }

  public static class Class_repl_from_textblock_argmap extends Core.Class_base implements Func_repl_from_textblock_argmap {

    @Override
    public Repl.Func_repl_from_textblock_argmap vx_new(final Object... vals) {
      Class_repl_from_textblock_argmap output = new Class_repl_from_textblock_argmap();
      return output;
    }

    @Override
    public Repl.Func_repl_from_textblock_argmap vx_copy(final Object... vals) {
      Class_repl_from_textblock_argmap output = new Class_repl_from_textblock_argmap();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/repl", // pkgname
        "repl<-textblock-argmap", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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
      return e_repl_from_textblock_argmap;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_repl_from_textblock_argmap;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_argmap argmap = Core.f_any_from_any(Core.t_argmap, arglist.vx_any(Core.vx_new_int(1)));
      output = Repl.f_repl_from_textblock_argmap(textblock, argmap);
      return output;
    }

    @Override
    public Repl.Type_repl vx_repl_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap) {
      return Repl.f_repl_from_textblock_argmap(textblock, argmap);
    }

  }

  public static final Func_repl_from_textblock_argmap e_repl_from_textblock_argmap = new Repl.Class_repl_from_textblock_argmap();
  public static final Func_repl_from_textblock_argmap t_repl_from_textblock_argmap = new Repl.Class_repl_from_textblock_argmap();

  public static Repl.Type_repl f_repl_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap) {
    Repl.Type_repl output = Repl.e_repl;
    output = Core.f_let(
      Repl.t_repl,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Textblock.Type_delim delim = textblock.delim();
        final Core.Type_string starttext = delim.starttext();
        return Core.f_switch(
          Repl.t_repl,
          starttext,
          Core.vx_new(Core.t_thenelselist,
            Core.f_case_1(
              Core.vx_new_string(""),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Repl.f_repl_empty_from_textblock_argmap(textblock, argmap);
              })
            ),
            Core.f_case_1(
              Textblock.c_delimparen.starttext(),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Repl.f_repl_paren_from_textblock_argmap(textblock, argmap);
              })
            ),
            Core.f_case_1(
              Textblock.c_delimbracketsquare.starttext(),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Repl.f_repl_bracket_from_textblock_argmap(textblock, argmap);
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
  public interface Func_replarglist_from_replarglist_textblock_argmap extends Core.Type_func, Core.Type_replfunc {
    public Repl.Type_replarglist vx_replarglist_from_replarglist_textblock_argmap(final Repl.Type_replarglist replargs, final Textblock.Type_textblock tb, final Core.Type_argmap argmap);
  }

  public static class Class_replarglist_from_replarglist_textblock_argmap extends Core.Class_base implements Func_replarglist_from_replarglist_textblock_argmap {

    @Override
    public Repl.Func_replarglist_from_replarglist_textblock_argmap vx_new(final Object... vals) {
      Class_replarglist_from_replarglist_textblock_argmap output = new Class_replarglist_from_replarglist_textblock_argmap();
      return output;
    }

    @Override
    public Repl.Func_replarglist_from_replarglist_textblock_argmap vx_copy(final Object... vals) {
      Class_replarglist_from_replarglist_textblock_argmap output = new Class_replarglist_from_replarglist_textblock_argmap();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/repl", // pkgname
        "replarglist<-replarglist-textblock-argmap", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/repl", // pkgname
          "replarglist", // name
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
      return e_replarglist_from_replarglist_textblock_argmap;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_replarglist_from_replarglist_textblock_argmap;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Repl.Type_replarglist replargs = Core.f_any_from_any(Repl.t_replarglist, arglist.vx_any(Core.vx_new_int(0)));
      Textblock.Type_textblock tb = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(1)));
      Core.Type_argmap argmap = Core.f_any_from_any(Core.t_argmap, arglist.vx_any(Core.vx_new_int(2)));
      output = Repl.f_replarglist_from_replarglist_textblock_argmap(replargs, tb, argmap);
      return output;
    }

    @Override
    public Repl.Type_replarglist vx_replarglist_from_replarglist_textblock_argmap(final Repl.Type_replarglist replargs, final Textblock.Type_textblock tb, final Core.Type_argmap argmap) {
      return Repl.f_replarglist_from_replarglist_textblock_argmap(replargs, tb, argmap);
    }

  }

  public static final Func_replarglist_from_replarglist_textblock_argmap e_replarglist_from_replarglist_textblock_argmap = new Repl.Class_replarglist_from_replarglist_textblock_argmap();
  public static final Func_replarglist_from_replarglist_textblock_argmap t_replarglist_from_replarglist_textblock_argmap = new Repl.Class_replarglist_from_replarglist_textblock_argmap();

  public static Repl.Type_replarglist f_replarglist_from_replarglist_textblock_argmap(final Repl.Type_replarglist replargs, final Textblock.Type_textblock tb, final Core.Type_argmap argmap) {
    Repl.Type_replarglist output = Repl.e_replarglist;
    output = Core.f_let(
      Repl.t_replarglist,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string key = replargs.key();
        final Repl.Type_repl current = replargs.current();
        final Repl.Type_repllist repllist = replargs.repllist();
        final Repl.Type_repllist currlist = current.repllist();
        final Core.Type_string text = Textblock.t_textblock.text();
        return Core.f_if_2(
          Repl.t_replarglist,
          Core.vx_new(Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_eq(key, Core.vx_new_string(""));
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_if_2(
                  Repl.t_replarglist,
                  Core.vx_new(Core.t_thenelselist,
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_eq_1(Core.vx_new(Core.t_anylist,
                            text));
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.f_copy(
                            replargs,
                            Core.vx_new(Core.t_anylist,
                                Core.vx_new_string(":key"),
                                text
                            )
                          );
                        })
                      ),
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_eq(text, Core.vx_new_string(":="));
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.f_copy(
                            replargs,
                            Core.vx_new(Core.t_anylist,
                                Core.vx_new_string(":key"),
                                text
                            )
                          );
                        })
                      ),
                      Core.f_then(
                        Core.t_boolean_from_func.vx_fn_new(() -> {
                          return Core.f_eq(text, Core.vx_new_string(":doc"));
                        }),
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.f_copy(
                            replargs,
                            Core.vx_new(Core.t_anylist,
                                Core.vx_new_string(":key"),
                                text
                            )
                          );
                        })
                      ),
                      Core.f_else(
                        Core.t_any_from_func.vx_fn_new(() -> {
                          return Core.f_copy(
                            replargs,
                            Core.vx_new(Core.t_anylist,
                                Core.vx_new_string(":current"),
                                Core.f_new(
                                  Repl.t_repl,
                                  Core.vx_new(Core.t_anylist,
                                    Core.vx_new_string(":name"),
                                    text
                                  )
                                ),
                                Core.vx_new_string(":repllist"),
                                Core.f_copy(repllist, Core.vx_new(Core.t_anylist,
                                  current))
                            )
                          );
                        })
                      )
                  )
                );
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_eq_1(Core.vx_new(Core.t_anylist,
                  key));
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_copy(
                  replargs,
                  Core.vx_new(Core.t_anylist,
                      Core.vx_new_string(":key"),
                      Core.vx_new_string(""),
                      Core.vx_new_string(":current"),
                      Core.f_copy(
                        current,
                        Core.vx_new(Core.t_anylist,
                          Core.vx_new_string(":type"),
                          text
                        )
                      )
                  )
                );
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_eq(key, Core.vx_new_string(":="));
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_copy(
                  replargs,
                  Core.vx_new(Core.t_anylist,
                      Core.vx_new_string(":key"),
                      Core.vx_new_string(""),
                      Core.vx_new_string(":current"),
                      Core.f_copy(
                        current,
                        Core.vx_new(Core.t_anylist,
                          Core.vx_new_string(":repllist"),
                          Core.f_copy(
                            currlist,
                            Core.vx_new(Core.t_anylist,
                              Repl.f_repl_from_textblock_argmap(tb, argmap)
                            )
                          )
                        )
                      )
                  )
                );
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                return Core.f_eq(key, Core.vx_new_string(":doc"));
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                return Core.f_copy(
                  replargs,
                  Core.vx_new(Core.t_anylist,
                      Core.vx_new_string(":key"),
                      Core.vx_new_string(""),
                      Core.vx_new_string(":current"),
                      Core.f_copy(
                        current,
                        Core.vx_new(Core.t_anylist,
                          Core.vx_new_string(":doc"),
                          text
                        )
                      )
                  )
                );
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
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
  public interface Func_repllist_from_textblocklist_argmap extends Core.Type_func, Core.Type_replfunc {
    public Repl.Type_repllist vx_repllist_from_textblocklist_argmap(final Textblock.Type_textblocklist textblocklist, final Core.Type_argmap argmap);
  }

  public static class Class_repllist_from_textblocklist_argmap extends Core.Class_base implements Func_repllist_from_textblocklist_argmap {

    @Override
    public Repl.Func_repllist_from_textblocklist_argmap vx_new(final Object... vals) {
      Class_repllist_from_textblocklist_argmap output = new Class_repllist_from_textblocklist_argmap();
      return output;
    }

    @Override
    public Repl.Func_repllist_from_textblocklist_argmap vx_copy(final Object... vals) {
      Class_repllist_from_textblocklist_argmap output = new Class_repllist_from_textblocklist_argmap();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/repl", // pkgname
        "repllist<-textblocklist-argmap", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/repl", // pkgname
          "repllist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Repl.t_repl), // allowtypes
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
      return e_repllist_from_textblocklist_argmap;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_repllist_from_textblocklist_argmap;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblocklist textblocklist = Core.f_any_from_any(Textblock.t_textblocklist, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_argmap argmap = Core.f_any_from_any(Core.t_argmap, arglist.vx_any(Core.vx_new_int(1)));
      output = Repl.f_repllist_from_textblocklist_argmap(textblocklist, argmap);
      return output;
    }

    @Override
    public Repl.Type_repllist vx_repllist_from_textblocklist_argmap(final Textblock.Type_textblocklist textblocklist, final Core.Type_argmap argmap) {
      return Repl.f_repllist_from_textblocklist_argmap(textblocklist, argmap);
    }

  }

  public static final Func_repllist_from_textblocklist_argmap e_repllist_from_textblocklist_argmap = new Repl.Class_repllist_from_textblocklist_argmap();
  public static final Func_repllist_from_textblocklist_argmap t_repllist_from_textblocklist_argmap = new Repl.Class_repllist_from_textblocklist_argmap();

  public static Repl.Type_repllist f_repllist_from_textblocklist_argmap(final Textblock.Type_textblocklist textblocklist, final Core.Type_argmap argmap) {
    Repl.Type_repllist output = Repl.e_repllist;
    output = Core.f_list_from_list_1(
      Repl.t_repllist,
      textblocklist,
      Core.t_any_from_any.vx_fn_new((textblock_any) -> {
        Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, textblock_any);
        return 
        Repl.f_repl_from_textblock(textblock);
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
  public interface Func_textblock_from_script extends Core.Func_any_from_any {
    public Textblock.Type_textblock vx_textblock_from_script(final Core.Type_string script);
  }

  public static class Class_textblock_from_script extends Core.Class_base implements Func_textblock_from_script {

    @Override
    public Repl.Func_textblock_from_script vx_new(final Object... vals) {
      Class_textblock_from_script output = new Class_textblock_from_script();
      return output;
    }

    @Override
    public Repl.Func_textblock_from_script vx_copy(final Object... vals) {
      Class_textblock_from_script output = new Class_textblock_from_script();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/repl", // pkgname
        "textblock<-script", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/textblock", // pkgname
          "textblock", // name
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
      return e_textblock_from_script;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_textblock_from_script;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Repl.f_textblock_from_script(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string script = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Repl.f_textblock_from_script(script);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_from_script(final Core.Type_string script) {
      return Repl.f_textblock_from_script(script);
    }

  }

  public static final Func_textblock_from_script e_textblock_from_script = new Repl.Class_textblock_from_script();
  public static final Func_textblock_from_script t_textblock_from_script = new Repl.Class_textblock_from_script();

  public static Textblock.Type_textblock f_textblock_from_script(final Core.Type_string script) {
    Textblock.Type_textblock output = Textblock.e_textblock;
    output = Textblock.f_textblock_parse_from_string_delim(
      script,
      Repl.c_delimvxlisp
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
  public interface Func_typefunc_from_string extends Core.Func_any_from_any {
    public Core.Type_any vx_typefunc_from_string(final Core.Type_string text);
  }

  public static class Class_typefunc_from_string extends Core.Class_base implements Func_typefunc_from_string {

    @Override
    public Repl.Func_typefunc_from_string vx_new(final Object... vals) {
      Class_typefunc_from_string output = new Class_typefunc_from_string();
      return output;
    }

    @Override
    public Repl.Func_typefunc_from_string vx_copy(final Object... vals) {
      Class_typefunc_from_string output = new Class_typefunc_from_string();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/repl", // pkgname
        "typefunc<-string", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "any", // name
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
      return e_typefunc_from_string;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_typefunc_from_string;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Repl.f_typefunc_from_string(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Repl.f_typefunc_from_string(text);
      return output;
    }

    @Override
    public Core.Type_any vx_typefunc_from_string(final Core.Type_string text) {
      return Repl.f_typefunc_from_string(text);
    }

  }

  public static final Func_typefunc_from_string e_typefunc_from_string = new Repl.Class_typefunc_from_string();
  public static final Func_typefunc_from_string t_typefunc_from_string = new Repl.Class_typefunc_from_string();

  public static Core.Type_any f_typefunc_from_string(final Core.Type_string text) {
    Core.Type_any output = Core.e_any;
    output = Core.f_let(
      Core.t_any,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_int pkgpos = Type.f_int_from_string_findlast(text, Core.vx_new_string("/"));
        final Core.Type_string pkgname = Core.f_if_1(
          Core.t_string,
          Core.f_eq(Core.vx_new_int(0), pkgpos),
          Core.vx_new_string("vx/core"),
          Type.f_string_from_string_end(
            text,
            Core.f_minus1(pkgpos)
          )
        );
        final Core.Type_string name = Core.f_if_1(
          Core.t_string,
          Core.f_eq(Core.vx_new_int(0), pkgpos),
          text,
          Type.f_string_from_string_start(
            text,
            Core.f_plus1(pkgpos)
          )
        );
        final Core.Type_package pkg = Core.f_package_global_from_name(pkgname);
        final Core.Type_typemap typemap = pkg.typemap();
        final Core.Type_any typeval = Core.f_any_from_map(Core.t_any, typemap, name);
        return Core.f_if_1(
          Core.t_any,
          Core.f_notempty_1(typeval),
          typeval,
          Core.f_let(
            Core.t_any,
            Core.t_any_from_func.vx_fn_new(() -> {
              final Core.Type_funcmap funcmap = pkg.funcmap();
              final Core.Type_any funcval = Core.f_any_from_map(Core.t_any, funcmap, name);
              return Core.f_if_1(
                Core.t_any,
                Core.f_notempty_1(funcval),
                funcval,
                Core.f_empty(
                  Core.t_any
                )
              );
            })
          )
        );
      })
    );
    return output;
  }


  static {
    Const_delimvxlisp.const_new(c_delimvxlisp);
    Const_delimvxlispbracket.const_new(c_delimvxlispbracket);
    Const_delimvxlispparen.const_new(c_delimvxlispparen);
    Map<String, Core.Type_any> maptype = new LinkedHashMap<>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<>();
    maptype.put("liblist", Repl.t_liblist);
    maptype.put("repl", Repl.t_repl);
    maptype.put("replarglist", Repl.t_replarglist);
    maptype.put("repllist", Repl.t_repllist);
    mapconst.put("delimvxlisp", Repl.c_delimvxlisp);
    mapconst.put("delimvxlispbracket", Repl.c_delimvxlispbracket);
    mapconst.put("delimvxlispparen", Repl.c_delimvxlispparen);
    mapfunc.put("any-repl<-functype-args", Repl.t_any_repl_from_functype_args);
    mapfunc.put("any<-liblist-string", Repl.t_any_from_liblist_string);
    mapfunc.put("any<-macro", Repl.t_any_from_macro);
    mapfunc.put("any<-repl", Repl.t_any_from_repl);
    mapfunc.put("any<-script", Repl.t_any_from_script);
    mapfunc.put("anylist<-repllist", Repl.t_anylist_from_repllist);
    mapfunc.put("argmap<-textblock-argmap", Repl.t_argmap_from_textblock_argmap);
    mapfunc.put("const<-string", Repl.t_const_from_string);
    mapfunc.put("repl-bracket<-textblock-argmap", Repl.t_repl_bracket_from_textblock_argmap);
    mapfunc.put("repl-empty<-textblock-argmap", Repl.t_repl_empty_from_textblock_argmap);
    mapfunc.put("repl-paren<-textblock-argmap", Repl.t_repl_paren_from_textblock_argmap);
    mapfunc.put("repl<-liblist-string", Repl.t_repl_from_liblist_string);
    mapfunc.put("repl<-macro", Repl.t_repl_from_macro);
    mapfunc.put("repl<-script", Repl.t_repl_from_script);
    mapfunc.put("repl<-string-argmap", Repl.t_repl_from_string_argmap);
    mapfunc.put("repl<-textblock", Repl.t_repl_from_textblock);
    mapfunc.put("repl<-textblock-argmap", Repl.t_repl_from_textblock_argmap);
    mapfunc.put("replarglist<-replarglist-textblock-argmap", Repl.t_replarglist_from_replarglist_textblock_argmap);
    mapfunc.put("repllist<-textblocklist-argmap", Repl.t_repllist_from_textblocklist_argmap);
    mapfunc.put("textblock<-script", Repl.t_textblock_from_script);
    mapfunc.put("typefunc<-string", Repl.t_typefunc_from_string);
    Core.vx_global_package_set("vx/repl", maptype, mapconst, mapfunc);
  }

}
