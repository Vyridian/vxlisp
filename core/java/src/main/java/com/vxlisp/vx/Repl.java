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
    public List<Core.Type_string> vx_liststring();
    public Core.Type_string vx_string(final Core.Type_int index);
  }

  public static class Class_liblist extends Core.Class_base implements Type_liblist {

    public List<Core.Type_string> vx_p_list = Core.immutablelist(
      new ArrayList<Core.Type_string>()
    );

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(
        new ArrayList<Core.Type_any>(this.vx_p_list)
      );
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
      List<Core.Type_string> output = this.vx_p_list;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Core.Type_string output = this.vx_string(index);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Repl.Type_liblist output = Core.vx_copy(Repl.e_liblist, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Repl.Type_liblist output = this;
      boolean ischanged = false;
      Repl.Class_liblist value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      List<Core.Type_string> listval = new ArrayList<Core.Type_string>(value.vx_liststring());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_string) {
          Core.Type_string allowsub = (Core.Type_string)valsub;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof String) {
          ischanged = true;
          listval.add(Core.vx_new(Core.t_string, valsub));
        } else if (valsub instanceof Repl.Type_liblist) {
          Repl.Type_liblist multi = (Repl.Type_liblist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_liststring());
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof Core.Type_string) {
              Core.Type_string valitem = (Core.Type_string)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/repl/liblist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/repl/liblist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Repl.Class_liblist work = new Repl.Class_liblist();
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
      Core.Type_any output = Repl.e_liblist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Repl.t_liblist;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Repl.Type_liblist e_liblist = new Repl.Class_liblist();
  public static final Repl.Type_liblist t_liblist = new Repl.Class_liblist();

  /**
   * type: repl
   * Repl structure
   * (type repl)
   */
  public interface Type_repl extends Core.Type_struct {
    public Core.Type_string name();
    public Core.Type_any type();
    public Repl.Type_repllist repllist();
    public Core.Type_boolean async();
    public Core.Type_any value();
    public Core.Type_string doc();
  }

  public static class Class_repl extends Core.Class_base implements Type_repl {

    public Core.Type_string vx_p_name = null;

    @Override
    public Core.Type_string name() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_name;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_any vx_p_type = null;

    @Override
    public Core.Type_any type() {
      Core.Type_any output = Core.e_any;
      Core.Type_any testnull = vx_p_type;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Repl.Type_repllist vx_p_repllist = null;

    @Override
    public Repl.Type_repllist repllist() {
      Repl.Type_repllist output = Repl.e_repllist;
      Repl.Type_repllist testnull = vx_p_repllist;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_boolean vx_p_async = null;

    @Override
    public Core.Type_boolean async() {
      Core.Type_boolean output = Core.e_boolean;
      Core.Type_boolean testnull = vx_p_async;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_any vx_p_value = null;

    @Override
    public Core.Type_any value() {
      Core.Type_any output = Core.e_any;
      Core.Type_any testnull = vx_p_value;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_string vx_p_doc = null;

    @Override
    public Core.Type_string doc() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_doc;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      if (false) {
      } else if ((skey.equals(":name"))) {
        output = this.name();
      } else if ((skey.equals(":type"))) {
        output = this.type();
      } else if ((skey.equals(":repllist"))) {
        output = this.repllist();
      } else if ((skey.equals(":async"))) {
        output = this.async();
      } else if ((skey.equals(":value"))) {
        output = this.value();
      } else if ((skey.equals(":doc"))) {
        output = this.doc();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":name", this.name());
      map.put(":type", this.type());
      map.put(":repllist", this.repllist());
      map.put(":async", this.async());
      map.put(":value", this.value());
      map.put(":doc", this.doc());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Repl.Type_repl output = Core.vx_copy(Repl.e_repl, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Repl.Type_repl output = this;
      boolean ischanged = false;
      Repl.Class_repl value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_name = value.name();
      Core.Type_any vx_p_type = value.type();
      Repl.Type_repllist vx_p_repllist = value.repllist();
      Core.Type_boolean vx_p_async = value.async();
      Core.Type_any vx_p_value = value.value();
      Core.Type_string vx_p_doc = value.doc();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":name");
      validkeys.add(":type");
      validkeys.add(":repllist");
      validkeys.add(":async");
      validkeys.add(":value");
      validkeys.add(":doc");
      String key = "";
      Core.Type_msg msg = Core.e_msg;
      Core.Type_any msgval = Core.e_any;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          boolean istestkey = false;
          String testkey = "";
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            String sval = (String)valsub;
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
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
              msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/repl/repl", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":name"))) {
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valname = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
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
          } else if ((key.equals(":type"))) {
            if (valsub == vx_p_type) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valtype = (Core.Type_any)valsub;
              ischanged = true;
              vx_p_type = valtype;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
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
          } else if ((key.equals(":repllist"))) {
            if (valsub == vx_p_repllist) {
            } else if (valsub instanceof Repl.Type_repllist) {
              Repl.Type_repllist valrepllist = (Repl.Type_repllist)valsub;
              ischanged = true;
              vx_p_repllist = valrepllist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
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
          } else if ((key.equals(":async"))) {
            if (valsub == vx_p_async) {
            } else if (valsub instanceof Core.Type_boolean) {
              Core.Type_boolean valasync = (Core.Type_boolean)valsub;
              ischanged = true;
              vx_p_async = valasync;
            } else if (valsub instanceof Boolean) {
              ischanged = true;
              vx_p_async = Core.vx_new(Core.t_boolean, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
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
          } else if ((key.equals(":value"))) {
            if (valsub == vx_p_value) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valvalue = (Core.Type_any)valsub;
              ischanged = true;
              vx_p_value = valvalue;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("value"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/repl/repl", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":doc"))) {
            if (valsub == vx_p_doc) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valdoc = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_doc = valdoc;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_doc = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
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
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/repl/repl", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Repl.Class_repl work = new Repl.Class_repl();
        work.vx_p_name = vx_p_name;
        work.vx_p_type = vx_p_type;
        work.vx_p_repllist = vx_p_repllist;
        work.vx_p_async = vx_p_async;
        work.vx_p_value = vx_p_value;
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
      Core.Type_any output = Repl.e_repl;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Repl.t_repl;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Repl.Type_repl e_repl = new Repl.Class_repl();
  public static final Repl.Type_repl t_repl = new Repl.Class_repl();

  /**
   * type: replarglist
   * Builder for a repllist
   * (type replarglist)
   */
  public interface Type_replarglist extends Core.Type_struct {
    public Core.Type_string key();
    public Repl.Type_repl current();
    public Repl.Type_repllist repllist();
  }

  public static class Class_replarglist extends Core.Class_base implements Type_replarglist {

    public Core.Type_string vx_p_key = null;

    @Override
    public Core.Type_string key() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_key;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Repl.Type_repl vx_p_current = null;

    @Override
    public Repl.Type_repl current() {
      Repl.Type_repl output = Repl.e_repl;
      Repl.Type_repl testnull = vx_p_current;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Repl.Type_repllist vx_p_repllist = null;

    @Override
    public Repl.Type_repllist repllist() {
      Repl.Type_repllist output = Repl.e_repllist;
      Repl.Type_repllist testnull = vx_p_repllist;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      if (false) {
      } else if ((skey.equals(":key"))) {
        output = this.key();
      } else if ((skey.equals(":current"))) {
        output = this.current();
      } else if ((skey.equals(":repllist"))) {
        output = this.repllist();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":key", this.key());
      map.put(":current", this.current());
      map.put(":repllist", this.repllist());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Repl.Type_replarglist output = Core.vx_copy(Repl.e_replarglist, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Repl.Type_replarglist output = this;
      boolean ischanged = false;
      Repl.Class_replarglist value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_key = value.key();
      Repl.Type_repl vx_p_current = value.current();
      Repl.Type_repllist vx_p_repllist = value.repllist();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":key");
      validkeys.add(":current");
      validkeys.add(":repllist");
      String key = "";
      Core.Type_msg msg = Core.e_msg;
      Core.Type_any msgval = Core.e_any;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (key.equals("")) {
          boolean istestkey = false;
          String testkey = "";
          if (false) {
          } else if (valsub instanceof Core.Type_string) {
            Core.Type_string valstr = (Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub instanceof String) {
            String sval = (String)valsub;
            testkey = sval;
            istestkey = true;
          } else {
            if (false) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valmsg = (Core.Type_any)valsub;
              msgval = valmsg;
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
              msgval = Core.vx_new_string(testkey);
              msg = Core.vx_msg_from_error("vx/repl/replarglist", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":key"))) {
            if (valsub == vx_p_key) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valkey = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_key = valkey;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_key = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
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
          } else if ((key.equals(":current"))) {
            if (valsub == vx_p_current) {
            } else if (valsub instanceof Repl.Type_repl) {
              Repl.Type_repl valcurrent = (Repl.Type_repl)valsub;
              ischanged = true;
              vx_p_current = valcurrent;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
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
          } else if ((key.equals(":repllist"))) {
            if (valsub == vx_p_repllist) {
            } else if (valsub instanceof Repl.Type_repllist) {
              Repl.Type_repllist valrepllist = (Repl.Type_repllist)valsub;
              ischanged = true;
              vx_p_repllist = valrepllist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
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
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/repl/replarglist", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Repl.Class_replarglist work = new Repl.Class_replarglist();
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
      Core.Type_any output = Repl.e_replarglist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Repl.t_replarglist;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Repl.Type_replarglist e_replarglist = new Repl.Class_replarglist();
  public static final Repl.Type_replarglist t_replarglist = new Repl.Class_replarglist();

  /**
   * type: repllist
   * List of repl
   * (type repllist)
   */
  public interface Type_repllist extends Core.Type_list {
    public List<Repl.Type_repl> vx_listrepl();
    public Repl.Type_repl vx_repl(final Core.Type_int index);
  }

  public static class Class_repllist extends Core.Class_base implements Type_repllist {

    public List<Repl.Type_repl> vx_p_list = Core.immutablelist(
      new ArrayList<Repl.Type_repl>()
    );

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(
        new ArrayList<Core.Type_any>(this.vx_p_list)
      );
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
      List<Repl.Type_repl> output = this.vx_p_list;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Repl.Type_repl output = this.vx_repl(index);
      return output;
    }

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Repl.Type_repllist output = Core.vx_copy(Repl.e_repllist, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Repl.Type_repllist output = this;
      boolean ischanged = false;
      Repl.Class_repllist value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      List<Repl.Type_repl> listval = new ArrayList<Repl.Type_repl>(value.vx_listrepl());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Repl.Type_repl) {
          Repl.Type_repl allowsub = (Repl.Type_repl)valsub;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Repl.Type_repl) {
          ischanged = true;
          listval.add((Repl.Type_repl)valsub);
        } else if (valsub instanceof Repl.Type_repllist) {
          Repl.Type_repllist multi = (Repl.Type_repllist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listrepl());
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof Repl.Type_repl) {
              Repl.Type_repl valitem = (Repl.Type_repl)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/repl/repllist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/repl/repllist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Repl.Class_repllist work = new Repl.Class_repllist();
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
      Core.Type_any output = Repl.e_repllist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Repl.t_repllist;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Repl.Type_repllist e_repllist = new Repl.Class_repllist();
  public static final Repl.Type_repllist t_repllist = new Repl.Class_repllist();

  /**
   * Constant: delimvxlisp
   * vxlisp File Delimiters
   * {delim}
   */
  public static class Const_delimvxlisp {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Textblock.Type_delim output) {
      Textblock.Class_delim outval = (Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delim value = Core.f_new(
        Textblock.t_delim,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("delimvxlisp"),
          Core.vx_new_string(":delimlist"),
          Core.f_new(
            Textblock.t_delimlist,
            Core.vx_new(
              Core.t_anylist,
              Repl.c_delimvxlispparen,
              Textblock.c_delimcomment,
              Textblock.c_delimcommentblock
            )
          )
        )
      );
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static final Textblock.Type_delim c_delimvxlisp = new Textblock.Class_delim();


  /**
   * Constant: delimvxlispbracket
   * vxlisp Square Bracket Delimiters
   * {delim}
   */
  public static class Const_delimvxlispbracket {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Textblock.Type_delim output) {
      Textblock.Class_delim outval = (Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delim value = Core.f_copy(
        Textblock.c_delimbracketsquare,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("delimvxlispbracketsquare"),
          Core.vx_new_string(":delimlist"),
          Core.f_new(
            Textblock.t_delimlist,
            Core.vx_new(
              Core.t_anylist,
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
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static final Textblock.Type_delim c_delimvxlispbracket = new Textblock.Class_delim();


  /**
   * Constant: delimvxlispparen
   * vxlisp Paren Delimiters
   * {delim}
   */
  public static class Const_delimvxlispparen {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Textblock.Type_delim output) {
      Textblock.Class_delim outval = (Textblock.Class_delim)output;
      outval.vx_p_constdef = constdef();
      Textblock.Type_delim value = Core.f_copy(
        Textblock.c_delimparen,
        Core.vx_new(
          Core.t_anylist,
          Core.vx_new_string(":name"),
          Core.vx_new_string("delimvxlispparen"),
          Core.vx_new_string(":delimlist"),
          Core.f_new(
            Textblock.t_delimlist,
            Core.vx_new(
              Core.t_anylist,
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
      outval.vx_p_name = value.name();
      outval.vx_p_starttext = value.starttext();
      outval.vx_p_endtext = value.endtext();
      outval.vx_p_pos = value.pos();
      outval.vx_p_delimlist = value.delimlist();
    }

  }

  public static final Textblock.Type_delim c_delimvxlispparen = new Textblock.Class_delim();

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
    public Core.Type_any vx_new(final Object... vals) {
      Repl.Class_any_repl_from_functype_args output = new Repl.Class_any_repl_from_functype_args();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Repl.Class_any_repl_from_functype_args output = new Repl.Class_any_repl_from_functype_args();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Repl.e_any_repl_from_functype_args;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Repl.t_any_repl_from_functype_args;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any type = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_anylist args = Core.f_any_from_any(Core.t_anylist, arglist.vx_any(Core.vx_new_int(1)));
      output = Repl.f_any_repl_from_functype_args(type, args);
      return output;
    }

    @Override
    public Core.Type_any vx_any_repl_from_functype_args(final Core.Type_any type, final Core.Type_anylist args) {
      Core.Type_any output = Repl.f_any_repl_from_functype_args(type, args);
      return output;
    }

  }

  public static final Repl.Func_any_repl_from_functype_args e_any_repl_from_functype_args = new Repl.Class_any_repl_from_functype_args();
  public static final Repl.Func_any_repl_from_functype_args t_any_repl_from_functype_args = new Repl.Class_any_repl_from_functype_args();

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
    public Core.Type_any vx_new(final Object... vals) {
      Repl.Class_any_from_liblist_string output = new Repl.Class_any_from_liblist_string();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Repl.Class_any_from_liblist_string output = new Repl.Class_any_from_liblist_string();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Repl.e_any_from_liblist_string;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Repl.t_any_from_liblist_string;
      return output;
    }

    @Override
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
      Core.Type_any output = Repl.f_any_from_liblist_string(context, liblist, text);
      return output;
    }

  }

  public static final Repl.Func_any_from_liblist_string e_any_from_liblist_string = new Repl.Class_any_from_liblist_string();
  public static final Repl.Func_any_from_liblist_string t_any_from_liblist_string = new Repl.Class_any_from_liblist_string();

  public static Core.Type_any f_any_from_liblist_string(final Core.Type_context context, final Repl.Type_liblist liblist, final Core.Type_string text) {
    Core.Type_any output = Core.e_any;
    output = Core.f_let(
      Core.t_any,
      Core.t_any_from_func.vx_fn_new(() -> {
        Repl.Type_repl repl = Repl.f_repl_from_liblist_string(
          liblist,
          text
        );
        Core.Type_any output_1 = Repl.f_any_from_repl(
          context,
          repl
        );
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
  public interface Func_any_from_macro extends Core.Func_any_from_any_context {
    public <T extends Core.Type_any> T vx_any_from_macro(final T generic_any_1, final Core.Type_context context, final Core.Type_anylist anylist);
  }

  public static class Class_any_from_macro extends Core.Class_base implements Func_any_from_macro {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Repl.Class_any_from_macro output = new Repl.Class_any_from_macro();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Repl.Class_any_from_macro output = new Repl.Class_any_from_macro();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Repl.e_any_from_macro;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Repl.t_any_from_macro;
      return output;
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

    @Override
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
      T output = Repl.f_any_from_macro(generic_any_1, context, anylist);
      return output;
    }

  }

  public static final Repl.Func_any_from_macro e_any_from_macro = new Repl.Class_any_from_macro();
  public static final Repl.Func_any_from_macro t_any_from_macro = new Repl.Class_any_from_macro();

  public static <T extends Core.Type_any> T f_any_from_macro(final T generic_any_1, final Core.Type_context context, final Core.Type_anylist anylist) {
    T output = Core.f_empty(generic_any_1);
    output = Core.f_let(
      generic_any_1,
      Core.t_any_from_func.vx_fn_new(() -> {
        Repl.Type_repl repl = Repl.f_repl_from_macro(
          context,
          anylist
        );
        Core.Type_any value = Repl.f_any_from_repl(
          context,
          repl
        );
        Core.Type_any output_1 = Core.f_any_from_any(
          generic_any_1,
          value
        );
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
  public interface Func_any_from_repl extends Core.Func_any_from_any_context {
    public Core.Type_any vx_any_from_repl(final Core.Type_context context, final Repl.Type_repl repl);
  }

  public static class Class_any_from_repl extends Core.Class_base implements Func_any_from_repl {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Repl.Class_any_from_repl output = new Repl.Class_any_from_repl();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Repl.Class_any_from_repl output = new Repl.Class_any_from_repl();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Repl.e_any_from_repl;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Repl.t_any_from_repl;
      return output;
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

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Repl.Type_repl repl = Core.f_any_from_any(Repl.t_repl, arglist.vx_any(Core.vx_new_int(0)));
      output = Repl.f_any_from_repl(context, repl);
      return output;
    }

    @Override
    public Core.Type_any vx_any_from_repl(final Core.Type_context context, final Repl.Type_repl repl) {
      Core.Type_any output = Repl.f_any_from_repl(context, repl);
      return output;
    }

  }

  public static final Repl.Func_any_from_repl e_any_from_repl = new Repl.Class_any_from_repl();
  public static final Repl.Func_any_from_repl t_any_from_repl = new Repl.Class_any_from_repl();

  public static Core.Type_any f_any_from_repl(final Core.Type_context context, final Repl.Type_repl repl) {
    Core.Type_any output = Core.e_any;
    output = Core.f_let(
      Core.t_any,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_any value = repl.value();
        Core.Type_any repltype = repl.type();
        Repl.Type_repllist repllist = repl.repllist();
        Core.Type_anylist args = Repl.f_anylist_from_repllist(
          context,
          repllist
        );
        Core.Type_any output_1 = Core.f_if_2(
          Core.t_any,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_2 = Core.f_notempty_1(
                  value
                );
                return output_2;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_3 = value;
                return output_3;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_4 = Core.f_is_func(
                  repltype
                );
                return output_4;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_5 = Repl.f_any_repl_from_functype_args(
                  repltype,
                  args
                );
                return output_5;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_6 = Core.f_new(
                  repltype,
                  args
                );
                return output_6;
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
  public interface Func_any_from_script extends Core.Func_any_from_any_context {
    public Core.Type_any vx_any_from_script(final Core.Type_context context, final Core.Type_string script);
  }

  public static class Class_any_from_script extends Core.Class_base implements Func_any_from_script {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Repl.Class_any_from_script output = new Repl.Class_any_from_script();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Repl.Class_any_from_script output = new Repl.Class_any_from_script();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Repl.e_any_from_script;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Repl.t_any_from_script;
      return output;
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

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string script = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Repl.f_any_from_script(context, script);
      return output;
    }

    @Override
    public Core.Type_any vx_any_from_script(final Core.Type_context context, final Core.Type_string script) {
      Core.Type_any output = Repl.f_any_from_script(context, script);
      return output;
    }

  }

  public static final Repl.Func_any_from_script e_any_from_script = new Repl.Class_any_from_script();
  public static final Repl.Func_any_from_script t_any_from_script = new Repl.Class_any_from_script();

  public static Core.Type_any f_any_from_script(final Core.Type_context context, final Core.Type_string script) {
    Core.Type_any output = Core.e_any;
    output = Core.f_let(
      Core.t_any,
      Core.t_any_from_func.vx_fn_new(() -> {
        Textblock.Type_textblock textblock = Repl.f_textblock_from_script(
          script
        );
        Repl.Type_repl repl = Repl.f_repl_from_textblock(
          textblock
        );
        Core.Type_any output_1 = Repl.f_any_from_repl(
          context,
          repl
        );
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
  public interface Func_anylist_from_repllist extends Core.Func_any_from_any_context {
    public Core.Type_anylist vx_anylist_from_repllist(final Core.Type_context context, final Repl.Type_repllist repllist);
  }

  public static class Class_anylist_from_repllist extends Core.Class_base implements Func_anylist_from_repllist {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Repl.Class_anylist_from_repllist output = new Repl.Class_anylist_from_repllist();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Repl.Class_anylist_from_repllist output = new Repl.Class_anylist_from_repllist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Repl.e_anylist_from_repllist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Repl.t_anylist_from_repllist;
      return output;
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

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Repl.Type_repllist repllist = Core.f_any_from_any(Repl.t_repllist, arglist.vx_any(Core.vx_new_int(0)));
      output = Repl.f_anylist_from_repllist(context, repllist);
      return output;
    }

    @Override
    public Core.Type_anylist vx_anylist_from_repllist(final Core.Type_context context, final Repl.Type_repllist repllist) {
      Core.Type_anylist output = Repl.f_anylist_from_repllist(context, repllist);
      return output;
    }

  }

  public static final Repl.Func_anylist_from_repllist e_anylist_from_repllist = new Repl.Class_anylist_from_repllist();
  public static final Repl.Func_anylist_from_repllist t_anylist_from_repllist = new Repl.Class_anylist_from_repllist();

  public static Core.Type_anylist f_anylist_from_repllist(final Core.Type_context context, final Repl.Type_repllist repllist) {
    Core.Type_anylist output = Core.e_anylist;
    output = Core.f_list_from_list_1(
      Core.t_anylist,
      repllist,
      Core.t_any_from_any.vx_fn_new((repl_any) -> {
        Repl.Type_repl repl = Core.f_any_from_any(Repl.t_repl, repl_any);
        Core.Type_any output_1 = Repl.f_any_from_repl(
          context,
          repl
        );
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
  public interface Func_argmap_from_textblock_argmap extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_argmap vx_argmap_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap);
  }

  public static class Class_argmap_from_textblock_argmap extends Core.Class_base implements Func_argmap_from_textblock_argmap {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Repl.Class_argmap_from_textblock_argmap output = new Repl.Class_argmap_from_textblock_argmap();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Repl.Class_argmap_from_textblock_argmap output = new Repl.Class_argmap_from_textblock_argmap();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Repl.e_argmap_from_textblock_argmap;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Repl.t_argmap_from_textblock_argmap;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_argmap argmap = Core.f_any_from_any(Core.t_argmap, arglist.vx_any(Core.vx_new_int(1)));
      output = Repl.f_argmap_from_textblock_argmap(textblock, argmap);
      return output;
    }

    @Override
    public Core.Type_argmap vx_argmap_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap) {
      Core.Type_argmap output = Repl.f_argmap_from_textblock_argmap(textblock, argmap);
      return output;
    }

  }

  public static final Repl.Func_argmap_from_textblock_argmap e_argmap_from_textblock_argmap = new Repl.Class_argmap_from_textblock_argmap();
  public static final Repl.Func_argmap_from_textblock_argmap t_argmap_from_textblock_argmap = new Repl.Class_argmap_from_textblock_argmap();

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
    public Core.Type_any vx_new(final Object... vals) {
      Repl.Class_const_from_string output = new Repl.Class_const_from_string();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Repl.Class_const_from_string output = new Repl.Class_const_from_string();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Repl.e_const_from_string;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Repl.t_const_from_string;
      return output;
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

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Repl.f_const_from_string(text);
      return output;
    }

    @Override
    public Core.Type_any vx_const_from_string(final Core.Type_string text) {
      Core.Type_any output = Repl.f_const_from_string(text);
      return output;
    }

  }

  public static final Repl.Func_const_from_string e_const_from_string = new Repl.Class_const_from_string();
  public static final Repl.Func_const_from_string t_const_from_string = new Repl.Class_const_from_string();

  public static Core.Type_any f_const_from_string(final Core.Type_string text) {
    Core.Type_any output = Core.e_any;
    output = Core.f_let(
      Core.t_any,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_int pkgpos = Type.f_int_from_string_findlast(
          text,
          Core.vx_new_string("/")
        );
        Core.Type_string pkgname = Core.f_if_1(
          Core.t_string,
          Core.f_eq(
            Core.vx_new_int(0),
            pkgpos
          ),
          Core.vx_new_string("vx/core"),
          Type.f_string_from_string_end(
            text,
            Core.f_minus1(
              pkgpos
            )
          )
        );
        Core.Type_string name = Core.f_if_1(
          Core.t_string,
          Core.f_eq(
            Core.vx_new_int(0),
            pkgpos
          ),
          text,
          Type.f_string_from_string_start(
            text,
            Core.f_plus1(
              pkgpos
            )
          )
        );
        Core.Type_package pkg = Core.f_package_global_from_name(
          pkgname
        );
        Core.Type_constmap constmap = pkg.constmap();
        Core.Type_any constval = Core.f_any_from_map(
          Core.t_any,
          constmap,
          name
        );
        Core.Type_any output_1 = Core.f_if_1(
          Core.t_any,
          Core.f_notempty_1(
            constval
          ),
          constval,
          Core.f_empty(
            Core.t_any
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
  public interface Func_repl_bracket_from_textblock_argmap extends Core.Type_func, Core.Type_replfunc {
    public Repl.Type_repl vx_repl_bracket_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap);
  }

  public static class Class_repl_bracket_from_textblock_argmap extends Core.Class_base implements Func_repl_bracket_from_textblock_argmap {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Repl.Class_repl_bracket_from_textblock_argmap output = new Repl.Class_repl_bracket_from_textblock_argmap();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Repl.Class_repl_bracket_from_textblock_argmap output = new Repl.Class_repl_bracket_from_textblock_argmap();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Repl.e_repl_bracket_from_textblock_argmap;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Repl.t_repl_bracket_from_textblock_argmap;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_argmap argmap = Core.f_any_from_any(Core.t_argmap, arglist.vx_any(Core.vx_new_int(1)));
      output = Repl.f_repl_bracket_from_textblock_argmap(textblock, argmap);
      return output;
    }

    @Override
    public Repl.Type_repl vx_repl_bracket_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap) {
      Repl.Type_repl output = Repl.f_repl_bracket_from_textblock_argmap(textblock, argmap);
      return output;
    }

  }

  public static final Repl.Func_repl_bracket_from_textblock_argmap e_repl_bracket_from_textblock_argmap = new Repl.Class_repl_bracket_from_textblock_argmap();
  public static final Repl.Func_repl_bracket_from_textblock_argmap t_repl_bracket_from_textblock_argmap = new Repl.Class_repl_bracket_from_textblock_argmap();

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
    public Core.Type_any vx_new(final Object... vals) {
      Repl.Class_repl_empty_from_textblock_argmap output = new Repl.Class_repl_empty_from_textblock_argmap();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Repl.Class_repl_empty_from_textblock_argmap output = new Repl.Class_repl_empty_from_textblock_argmap();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Repl.e_repl_empty_from_textblock_argmap;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Repl.t_repl_empty_from_textblock_argmap;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_argmap argmap = Core.f_any_from_any(Core.t_argmap, arglist.vx_any(Core.vx_new_int(1)));
      output = Repl.f_repl_empty_from_textblock_argmap(textblock, argmap);
      return output;
    }

    @Override
    public Repl.Type_repl vx_repl_empty_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap) {
      Repl.Type_repl output = Repl.f_repl_empty_from_textblock_argmap(textblock, argmap);
      return output;
    }

  }

  public static final Repl.Func_repl_empty_from_textblock_argmap e_repl_empty_from_textblock_argmap = new Repl.Class_repl_empty_from_textblock_argmap();
  public static final Repl.Func_repl_empty_from_textblock_argmap t_repl_empty_from_textblock_argmap = new Repl.Class_repl_empty_from_textblock_argmap();

  public static Repl.Type_repl f_repl_empty_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap) {
    Repl.Type_repl output = Repl.e_repl;
    output = Core.f_let(
      Repl.t_repl,
      Core.t_any_from_func.vx_fn_new(() -> {
        Textblock.Type_textblocklist children = textblock.children();
        Core.Type_int len = Core.f_length_1(
          children
        );
        Core.Type_any output_1 = Core.f_switch(
          Repl.t_repl,
          len,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_case_1(
              Core.vx_new_int(0),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_2 = Repl.f_repl_from_string_argmap(
                  textblock.text(),
                  argmap
                );
                return output_2;
              })
            ),
            Core.f_case_1(
              Core.vx_new_int(1),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_3 = Repl.f_repl_from_textblock_argmap(
                  Core.f_any_from_list(
                    Textblock.t_textblock,
                    children,
                    Core.vx_new_int(1)
                  ),
                  argmap
                );
                return output_3;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_4 = Core.f_new(
                  Repl.t_repl,
                  Core.vx_new(
                    Core.t_anylist,
                    Core.f_msg_from_error(
                      Core.vx_new_string("Empty delim cannot have more than one child.")
                    )
                  )
                );
                return output_4;
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
  public interface Func_repl_paren_from_textblock_argmap extends Core.Type_func, Core.Type_replfunc {
    public Repl.Type_repl vx_repl_paren_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap);
  }

  public static class Class_repl_paren_from_textblock_argmap extends Core.Class_base implements Func_repl_paren_from_textblock_argmap {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Repl.Class_repl_paren_from_textblock_argmap output = new Repl.Class_repl_paren_from_textblock_argmap();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Repl.Class_repl_paren_from_textblock_argmap output = new Repl.Class_repl_paren_from_textblock_argmap();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Repl.e_repl_paren_from_textblock_argmap;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Repl.t_repl_paren_from_textblock_argmap;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_argmap argmap = Core.f_any_from_any(Core.t_argmap, arglist.vx_any(Core.vx_new_int(1)));
      output = Repl.f_repl_paren_from_textblock_argmap(textblock, argmap);
      return output;
    }

    @Override
    public Repl.Type_repl vx_repl_paren_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap) {
      Repl.Type_repl output = Repl.f_repl_paren_from_textblock_argmap(textblock, argmap);
      return output;
    }

  }

  public static final Repl.Func_repl_paren_from_textblock_argmap e_repl_paren_from_textblock_argmap = new Repl.Class_repl_paren_from_textblock_argmap();
  public static final Repl.Func_repl_paren_from_textblock_argmap t_repl_paren_from_textblock_argmap = new Repl.Class_repl_paren_from_textblock_argmap();

  public static Repl.Type_repl f_repl_paren_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap) {
    Repl.Type_repl output = Repl.e_repl;
    output = Core.f_let(
      Repl.t_repl,
      Core.t_any_from_func.vx_fn_new(() -> {
        Textblock.Type_textblocklist childlst = textblock.children();
        Textblock.Type_textblocklist children = Textblock.f_textblocklist_from_textblocklist_remove(
          childlst,
          Textblock.c_delimwhitespace
        );
        Textblock.Type_textblock tbfunc = Core.f_any_from_list(
          Textblock.t_textblock,
          children,
          Core.vx_new_int(1)
        );
        Core.Type_string sfunc = tbfunc.text();
        Repl.Type_repl replfunc = Repl.f_repl_from_string_argmap(
          sfunc,
          argmap
        );
        Core.Type_any typefunc = replfunc.type();
        Core.Type_int posarg = Core.f_switch(
          Core.t_int,
          typefunc,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_case_1(
              Core.t_let,
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_2 = Core.vx_new_int(3);
                return output_2;
              })
            ),
            Core.f_case_1(
              Core.t_fn,
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_3 = Core.vx_new_int(3);
                return output_3;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_4 = Core.vx_new_int(2);
                return output_4;
              })
            )
          )
        );
        Core.Type_argmap argmap2 = Core.f_switch(
          Core.t_argmap,
          typefunc,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_case_1(
              Core.t_let,
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_5 = Repl.f_argmap_from_textblock_argmap(
                  Core.f_any_from_list(
                    Textblock.t_textblock,
                    children,
                    Core.vx_new_int(3)
                  ),
                  argmap
                );
                return output_5;
              })
            ),
            Core.f_case_1(
              Core.t_fn,
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_6 = Repl.f_argmap_from_textblock_argmap(
                  Core.f_any_from_list(
                    Textblock.t_textblock,
                    children,
                    Core.vx_new_int(3)
                  ),
                  argmap
                );
                return output_6;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_7 = argmap;
                return output_7;
              })
            )
          )
        );
        Textblock.Type_textblocklist tbargs = Collection.f_list_from_list_start(
          Textblock.t_textblocklist,
          children,
          posarg
        );
        Repl.Type_repllist replargs = Repl.f_repllist_from_textblocklist_argmap(
          tbargs,
          argmap
        );
        Core.Type_any output_1 = Core.f_copy(
          replfunc,
          Core.vx_new(
            Core.t_anylist,
            Core.vx_new_string(":repllist"),
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
  public interface Func_repl_from_liblist_string extends Core.Type_func, Core.Type_replfunc {
    public Repl.Type_repl vx_repl_from_liblist_string(final Repl.Type_liblist liblist, final Core.Type_string text);
  }

  public static class Class_repl_from_liblist_string extends Core.Class_base implements Func_repl_from_liblist_string {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Repl.Class_repl_from_liblist_string output = new Repl.Class_repl_from_liblist_string();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Repl.Class_repl_from_liblist_string output = new Repl.Class_repl_from_liblist_string();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Repl.e_repl_from_liblist_string;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Repl.t_repl_from_liblist_string;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Repl.Type_liblist liblist = Core.f_any_from_any(Repl.t_liblist, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Repl.f_repl_from_liblist_string(liblist, text);
      return output;
    }

    @Override
    public Repl.Type_repl vx_repl_from_liblist_string(final Repl.Type_liblist liblist, final Core.Type_string text) {
      Repl.Type_repl output = Repl.f_repl_from_liblist_string(liblist, text);
      return output;
    }

  }

  public static final Repl.Func_repl_from_liblist_string e_repl_from_liblist_string = new Repl.Class_repl_from_liblist_string();
  public static final Repl.Func_repl_from_liblist_string t_repl_from_liblist_string = new Repl.Class_repl_from_liblist_string();

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
    public Core.Type_any vx_new(final Object... vals) {
      Repl.Class_repl_from_macro output = new Repl.Class_repl_from_macro();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Repl.Class_repl_from_macro output = new Repl.Class_repl_from_macro();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Repl.e_repl_from_macro;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Repl.t_repl_from_macro;
      return output;
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

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_anylist anylist = Core.f_any_from_any(Core.t_anylist, arglist.vx_any(Core.vx_new_int(0)));
      output = Repl.f_repl_from_macro(context, anylist);
      return output;
    }

    @Override
    public Repl.Type_repl vx_repl_from_macro(final Core.Type_context context, final Core.Type_anylist anylist) {
      Repl.Type_repl output = Repl.f_repl_from_macro(context, anylist);
      return output;
    }

  }

  public static final Repl.Func_repl_from_macro e_repl_from_macro = new Repl.Class_repl_from_macro();
  public static final Repl.Func_repl_from_macro t_repl_from_macro = new Repl.Class_repl_from_macro();

  public static Repl.Type_repl f_repl_from_macro(final Core.Type_context context, final Core.Type_anylist anylist) {
    Repl.Type_repl output = Repl.e_repl;
    output = Core.f_let(
      Repl.t_repl,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_stringlist textlist = Core.f_list_from_list_1(
          Core.t_stringlist,
          anylist,
          Core.t_any_from_any.vx_fn_new((item_any) -> {
            Core.Type_any item = Core.f_any_from_any(Core.t_any, item_any);
            Core.Type_any output_2 = Core.f_let(
              Core.t_string,
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any typ = Core.f_type_from_any(
                  item
                );
                Core.Type_any output_3 = Core.f_switch(
                  Core.t_string,
                  typ,
                  Core.vx_new(
                    Core.t_thenelselist,
                    Core.f_case_1(
                      Core.t_string,
                      Core.t_any_from_func.vx_fn_new(() -> {
                        Core.Type_any output_4 = Core.f_any_from_any(
                          Core.t_string,
                          item
                        );
                        return output_4;
                      })
                    ),
                    Core.f_else(
                      Core.t_any_from_func.vx_fn_new(() -> {
                        Core.Type_any output_5 = Core.f_string_from_any(
                          item
                        );
                        return output_5;
                      })
                    )
                  )
                );
                return output_3;
              })
            );
            return output_2;
          })
        );
        Core.Type_string script = Type.f_string_from_stringlist_join(
          textlist,
          Core.vx_new_string("")
        );
        Textblock.Type_textblock tb = Repl.f_textblock_from_script(
          script
        );
        Core.Type_any output_1 = Repl.f_repl_from_textblock(
          tb
        );
        return output_1;
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
    public Core.Type_any vx_new(final Object... vals) {
      Repl.Class_repl_from_script output = new Repl.Class_repl_from_script();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Repl.Class_repl_from_script output = new Repl.Class_repl_from_script();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Repl.e_repl_from_script;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Repl.t_repl_from_script;
      return output;
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

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string script = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Repl.f_repl_from_script(script);
      return output;
    }

    @Override
    public Repl.Type_repl vx_repl_from_script(final Core.Type_string script) {
      Repl.Type_repl output = Repl.f_repl_from_script(script);
      return output;
    }

  }

  public static final Repl.Func_repl_from_script e_repl_from_script = new Repl.Class_repl_from_script();
  public static final Repl.Func_repl_from_script t_repl_from_script = new Repl.Class_repl_from_script();

  public static Repl.Type_repl f_repl_from_script(final Core.Type_string script) {
    Repl.Type_repl output = Repl.e_repl;
    output = Core.f_let(
      Repl.t_repl,
      Core.t_any_from_func.vx_fn_new(() -> {
        Textblock.Type_textblock textblock = Repl.f_textblock_from_script(
          script
        );
        Core.Type_any output_1 = Repl.f_repl_from_textblock(
          textblock
        );
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
  public interface Func_repl_from_string_argmap extends Core.Type_func, Core.Type_replfunc {
    public Repl.Type_repl vx_repl_from_string_argmap(final Core.Type_string text, final Core.Type_argmap argmap);
  }

  public static class Class_repl_from_string_argmap extends Core.Class_base implements Func_repl_from_string_argmap {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Repl.Class_repl_from_string_argmap output = new Repl.Class_repl_from_string_argmap();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Repl.Class_repl_from_string_argmap output = new Repl.Class_repl_from_string_argmap();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Repl.e_repl_from_string_argmap;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Repl.t_repl_from_string_argmap;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_argmap argmap = Core.f_any_from_any(Core.t_argmap, arglist.vx_any(Core.vx_new_int(1)));
      output = Repl.f_repl_from_string_argmap(text, argmap);
      return output;
    }

    @Override
    public Repl.Type_repl vx_repl_from_string_argmap(final Core.Type_string text, final Core.Type_argmap argmap) {
      Repl.Type_repl output = Repl.f_repl_from_string_argmap(text, argmap);
      return output;
    }

  }

  public static final Repl.Func_repl_from_string_argmap e_repl_from_string_argmap = new Repl.Class_repl_from_string_argmap();
  public static final Repl.Func_repl_from_string_argmap t_repl_from_string_argmap = new Repl.Class_repl_from_string_argmap();

  public static Repl.Type_repl f_repl_from_string_argmap(final Core.Type_string text, final Core.Type_argmap argmap) {
    Repl.Type_repl output = Repl.e_repl;
    output = Core.f_if_2(
      Repl.t_repl,
      Core.vx_new(
        Core.t_thenelselist,
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            Core.Type_any output_1 = Core.f_and(
              Type.f_boolean_from_string_starts(
                text,
                Core.c_quote
              ),
              Type.f_boolean_from_string_ends(
                text,
                Core.c_quote
              )
            );
            return output_1;
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_2 = Core.f_new(
              Repl.t_repl,
              Core.vx_new(
                Core.t_anylist,
                Core.vx_new_string(":value"),
                Type.f_string_from_string_start_end(
                  text,
                  Core.vx_new_int(2),
                  Core.vx_new_int(-1)
                )
              )
            );
            return output_2;
          })
        ),
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            Core.Type_any output_3 = Core.f_is_int(
              text
            );
            return output_3;
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_4 = Core.f_new(
              Repl.t_repl,
              Core.vx_new(
                Core.t_anylist,
                Core.vx_new_string(":value"),
                Core.f_int_from_string(
                  text
                )
              )
            );
            return output_4;
          })
        ),
        Core.f_then(
          Core.t_boolean_from_func.vx_fn_new(() -> {
            Core.Type_any output_5 = Core.f_is_float(
              text
            );
            return output_5;
          }),
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_6 = Core.f_new(
              Repl.t_repl,
              Core.vx_new(
                Core.t_anylist,
                Core.vx_new_string(":value"),
                Core.f_float_from_string(
                  text
                )
              )
            );
            return output_6;
          })
        ),
        Core.f_else(
          Core.t_any_from_func.vx_fn_new(() -> {
            Core.Type_any output_7 = Core.f_let(
              Repl.t_repl,
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any arg = Core.f_any_from_map(
                  Core.t_any,
                  argmap,
                  text
                );
                Core.Type_any output_8 = Core.f_if_2(
                  Repl.t_repl,
                  Core.vx_new(
                    Core.t_thenelselist,
                    Core.f_then(
                      Core.t_boolean_from_func.vx_fn_new(() -> {
                        Core.Type_any output_9 = Core.f_notempty_1(
                          arg
                        );
                        return output_9;
                      }),
                      Core.t_any_from_func.vx_fn_new(() -> {
                        Core.Type_any output_10 = Core.f_new(
                          Repl.t_repl,
                          Core.vx_new(
                            Core.t_anylist,
                            Core.vx_new_string(":value"),
                            arg
                          )
                        );
                        return output_10;
                      })
                    ),
                    Core.f_else(
                      Core.t_any_from_func.vx_fn_new(() -> {
                        Core.Type_any output_11 = Core.f_let(
                          Repl.t_repl,
                          Core.t_any_from_func.vx_fn_new(() -> {
                            Core.Type_any cnst = Repl.f_const_from_string(
                              text
                            );
                            Core.Type_any output_12 = Core.f_if_2(
                              Repl.t_repl,
                              Core.vx_new(
                                Core.t_thenelselist,
                                Core.f_then(
                                  Core.t_boolean_from_func.vx_fn_new(() -> {
                                    Core.Type_any output_13 = Core.f_notempty_1(
                                      cnst
                                    );
                                    return output_13;
                                  }),
                                  Core.t_any_from_func.vx_fn_new(() -> {
                                    Core.Type_any output_14 = Core.f_new(
                                      Repl.t_repl,
                                      Core.vx_new(
                                        Core.t_anylist,
                                        Core.vx_new_string(":value"),
                                        cnst
                                      )
                                    );
                                    return output_14;
                                  })
                                ),
                                Core.f_else(
                                  Core.t_any_from_func.vx_fn_new(() -> {
                                    Core.Type_any output_15 = Core.f_let(
                                      Repl.t_repl,
                                      Core.t_any_from_func.vx_fn_new(() -> {
                                        Core.Type_any typefunc = Repl.f_typefunc_from_string(
                                          text
                                        );
                                        Core.Type_any output_16 = Core.f_if_2(
                                          Repl.t_repl,
                                          Core.vx_new(
                                            Core.t_thenelselist,
                                            Core.f_then(
                                              Core.t_boolean_from_func.vx_fn_new(() -> {
                                                Core.Type_any output_17 = Core.f_notempty_1(
                                                  typefunc
                                                );
                                                return output_17;
                                              }),
                                              Core.t_any_from_func.vx_fn_new(() -> {
                                                Core.Type_any output_18 = Core.f_new(
                                                  Repl.t_repl,
                                                  Core.vx_new(
                                                    Core.t_anylist,
                                                    Core.vx_new_string(":type"),
                                                    typefunc
                                                  )
                                                );
                                                return output_18;
                                              })
                                            ),
                                            Core.f_else(
                                              Core.t_any_from_func.vx_fn_new(() -> {
                                                Core.Type_any output_19 = Core.f_new(
                                                  Repl.t_repl,
                                                  Core.vx_new(
                                                    Core.t_anylist,
                                                    Core.f_msg_from_error_1(
                                                      Core.vx_new_string(":repltypenotfound"),
                                                      text
                                                    )
                                                  )
                                                );
                                                return output_19;
                                              })
                                            )
                                          )
                                        );
                                        return output_16;
                                      })
                                    );
                                    return output_15;
                                  })
                                )
                              )
                            );
                            return output_12;
                          })
                        );
                        return output_11;
                      })
                    )
                  )
                );
                return output_8;
              })
            );
            return output_7;
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
    public Core.Type_any vx_new(final Object... vals) {
      Repl.Class_repl_from_textblock output = new Repl.Class_repl_from_textblock();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Repl.Class_repl_from_textblock output = new Repl.Class_repl_from_textblock();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Repl.e_repl_from_textblock;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Repl.t_repl_from_textblock;
      return output;
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

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      output = Repl.f_repl_from_textblock(textblock);
      return output;
    }

    @Override
    public Repl.Type_repl vx_repl_from_textblock(final Textblock.Type_textblock textblock) {
      Repl.Type_repl output = Repl.f_repl_from_textblock(textblock);
      return output;
    }

  }

  public static final Repl.Func_repl_from_textblock e_repl_from_textblock = new Repl.Class_repl_from_textblock();
  public static final Repl.Func_repl_from_textblock t_repl_from_textblock = new Repl.Class_repl_from_textblock();

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
    public Core.Type_any vx_new(final Object... vals) {
      Repl.Class_repl_from_textblock_argmap output = new Repl.Class_repl_from_textblock_argmap();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Repl.Class_repl_from_textblock_argmap output = new Repl.Class_repl_from_textblock_argmap();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Repl.e_repl_from_textblock_argmap;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Repl.t_repl_from_textblock_argmap;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_argmap argmap = Core.f_any_from_any(Core.t_argmap, arglist.vx_any(Core.vx_new_int(1)));
      output = Repl.f_repl_from_textblock_argmap(textblock, argmap);
      return output;
    }

    @Override
    public Repl.Type_repl vx_repl_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap) {
      Repl.Type_repl output = Repl.f_repl_from_textblock_argmap(textblock, argmap);
      return output;
    }

  }

  public static final Repl.Func_repl_from_textblock_argmap e_repl_from_textblock_argmap = new Repl.Class_repl_from_textblock_argmap();
  public static final Repl.Func_repl_from_textblock_argmap t_repl_from_textblock_argmap = new Repl.Class_repl_from_textblock_argmap();

  public static Repl.Type_repl f_repl_from_textblock_argmap(final Textblock.Type_textblock textblock, final Core.Type_argmap argmap) {
    Repl.Type_repl output = Repl.e_repl;
    output = Core.f_let(
      Repl.t_repl,
      Core.t_any_from_func.vx_fn_new(() -> {
        Textblock.Type_delim delim = textblock.delim();
        Core.Type_string starttext = delim.starttext();
        Core.Type_any output_1 = Core.f_switch(
          Repl.t_repl,
          starttext,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_case_1(
              Core.vx_new_string(""),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_2 = Repl.f_repl_empty_from_textblock_argmap(
                  textblock,
                  argmap
                );
                return output_2;
              })
            ),
            Core.f_case_1(
              Textblock.c_delimparen.starttext(),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_3 = Repl.f_repl_paren_from_textblock_argmap(
                  textblock,
                  argmap
                );
                return output_3;
              })
            ),
            Core.f_case_1(
              Textblock.c_delimbracketsquare.starttext(),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_4 = Repl.f_repl_bracket_from_textblock_argmap(
                  textblock,
                  argmap
                );
                return output_4;
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
  public interface Func_replarglist_from_replarglist_textblock_argmap extends Core.Type_func, Core.Type_replfunc {
    public Repl.Type_replarglist vx_replarglist_from_replarglist_textblock_argmap(final Repl.Type_replarglist replargs, final Textblock.Type_textblock tb, final Core.Type_argmap argmap);
  }

  public static class Class_replarglist_from_replarglist_textblock_argmap extends Core.Class_base implements Func_replarglist_from_replarglist_textblock_argmap {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Repl.Class_replarglist_from_replarglist_textblock_argmap output = new Repl.Class_replarglist_from_replarglist_textblock_argmap();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Repl.Class_replarglist_from_replarglist_textblock_argmap output = new Repl.Class_replarglist_from_replarglist_textblock_argmap();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Repl.e_replarglist_from_replarglist_textblock_argmap;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Repl.t_replarglist_from_replarglist_textblock_argmap;
      return output;
    }

    @Override
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
      Repl.Type_replarglist output = Repl.f_replarglist_from_replarglist_textblock_argmap(replargs, tb, argmap);
      return output;
    }

  }

  public static final Repl.Func_replarglist_from_replarglist_textblock_argmap e_replarglist_from_replarglist_textblock_argmap = new Repl.Class_replarglist_from_replarglist_textblock_argmap();
  public static final Repl.Func_replarglist_from_replarglist_textblock_argmap t_replarglist_from_replarglist_textblock_argmap = new Repl.Class_replarglist_from_replarglist_textblock_argmap();

  public static Repl.Type_replarglist f_replarglist_from_replarglist_textblock_argmap(final Repl.Type_replarglist replargs, final Textblock.Type_textblock tb, final Core.Type_argmap argmap) {
    Repl.Type_replarglist output = Repl.e_replarglist;
    output = Core.f_let(
      Repl.t_replarglist,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_string key = replargs.key();
        Repl.Type_repl current = replargs.current();
        Repl.Type_repllist repllist = replargs.repllist();
        Repl.Type_repllist currlist = current.repllist();
        Core.Type_string text = Textblock.t_textblock.text();
        Core.Type_any output_1 = Core.f_if_2(
          Repl.t_replarglist,
          Core.vx_new(
            Core.t_thenelselist,
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_2 = Core.f_eq(
                  key,
                  Core.vx_new_string("")
                );
                return output_2;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_3 = Core.f_if_2(
                  Repl.t_replarglist,
                  Core.vx_new(
                    Core.t_thenelselist,
                    Core.f_then(
                      Core.t_boolean_from_func.vx_fn_new(() -> {
                        Core.Type_any output_4 = Core.f_eq_1(
                          Core.vx_new(
                            Core.t_anylist,
                            text
                          )
                        );
                        return output_4;
                      }),
                      Core.t_any_from_func.vx_fn_new(() -> {
                        Core.Type_any output_5 = Core.f_copy(
                          replargs,
                          Core.vx_new(
                            Core.t_anylist,
                            Core.vx_new_string(":key"),
                            text
                          )
                        );
                        return output_5;
                      })
                    ),
                    Core.f_then(
                      Core.t_boolean_from_func.vx_fn_new(() -> {
                        Core.Type_any output_6 = Core.f_eq(
                          text,
                          Core.vx_new_string(":=")
                        );
                        return output_6;
                      }),
                      Core.t_any_from_func.vx_fn_new(() -> {
                        Core.Type_any output_7 = Core.f_copy(
                          replargs,
                          Core.vx_new(
                            Core.t_anylist,
                            Core.vx_new_string(":key"),
                            text
                          )
                        );
                        return output_7;
                      })
                    ),
                    Core.f_then(
                      Core.t_boolean_from_func.vx_fn_new(() -> {
                        Core.Type_any output_8 = Core.f_eq(
                          text,
                          Core.vx_new_string(":doc")
                        );
                        return output_8;
                      }),
                      Core.t_any_from_func.vx_fn_new(() -> {
                        Core.Type_any output_9 = Core.f_copy(
                          replargs,
                          Core.vx_new(
                            Core.t_anylist,
                            Core.vx_new_string(":key"),
                            text
                          )
                        );
                        return output_9;
                      })
                    ),
                    Core.f_else(
                      Core.t_any_from_func.vx_fn_new(() -> {
                        Core.Type_any output_10 = Core.f_copy(
                          replargs,
                          Core.vx_new(
                            Core.t_anylist,
                            Core.vx_new_string(":current"),
                            Core.f_new(
                              Repl.t_repl,
                              Core.vx_new(
                                Core.t_anylist,
                                Core.vx_new_string(":name"),
                                text
                              )
                            ),
                            Core.vx_new_string(":repllist"),
                            Core.f_copy(
                              repllist,
                              Core.vx_new(
                                Core.t_anylist,
                                current
                              )
                            )
                          )
                        );
                        return output_10;
                      })
                    )
                  )
                );
                return output_3;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_11 = Core.f_eq_1(
                  Core.vx_new(
                    Core.t_anylist,
                    key
                  )
                );
                return output_11;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_12 = Core.f_copy(
                  replargs,
                  Core.vx_new(
                    Core.t_anylist,
                    Core.vx_new_string(":key"),
                    Core.vx_new_string(""),
                    Core.vx_new_string(":current"),
                    Core.f_copy(
                      current,
                      Core.vx_new(
                        Core.t_anylist,
                        Core.vx_new_string(":type"),
                        text
                      )
                    )
                  )
                );
                return output_12;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_13 = Core.f_eq(
                  key,
                  Core.vx_new_string(":=")
                );
                return output_13;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_14 = Core.f_copy(
                  replargs,
                  Core.vx_new(
                    Core.t_anylist,
                    Core.vx_new_string(":key"),
                    Core.vx_new_string(""),
                    Core.vx_new_string(":current"),
                    Core.f_copy(
                      current,
                      Core.vx_new(
                        Core.t_anylist,
                        Core.vx_new_string(":repllist"),
                        Core.f_copy(
                          currlist,
                          Core.vx_new(
                            Core.t_anylist,
                            Repl.f_repl_from_textblock_argmap(
                              tb,
                              argmap
                            )
                          )
                        )
                      )
                    )
                  )
                );
                return output_14;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.vx_fn_new(() -> {
                Core.Type_any output_15 = Core.f_eq(
                  key,
                  Core.vx_new_string(":doc")
                );
                return output_15;
              }),
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_16 = Core.f_copy(
                  replargs,
                  Core.vx_new(
                    Core.t_anylist,
                    Core.vx_new_string(":key"),
                    Core.vx_new_string(""),
                    Core.vx_new_string(":current"),
                    Core.f_copy(
                      current,
                      Core.vx_new(
                        Core.t_anylist,
                        Core.vx_new_string(":doc"),
                        text
                      )
                    )
                  )
                );
                return output_16;
              })
            ),
            Core.f_else(
              Core.t_any_from_func.vx_fn_new(() -> {
                Core.Type_any output_17 = replargs;
                return output_17;
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
  public interface Func_repllist_from_textblocklist_argmap extends Core.Type_func, Core.Type_replfunc {
    public Repl.Type_repllist vx_repllist_from_textblocklist_argmap(final Textblock.Type_textblocklist textblocklist, final Core.Type_argmap argmap);
  }

  public static class Class_repllist_from_textblocklist_argmap extends Core.Class_base implements Func_repllist_from_textblocklist_argmap {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Repl.Class_repllist_from_textblocklist_argmap output = new Repl.Class_repllist_from_textblocklist_argmap();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Repl.Class_repllist_from_textblocklist_argmap output = new Repl.Class_repllist_from_textblocklist_argmap();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Repl.e_repllist_from_textblocklist_argmap;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Repl.t_repllist_from_textblocklist_argmap;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Textblock.Type_textblocklist textblocklist = Core.f_any_from_any(Textblock.t_textblocklist, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_argmap argmap = Core.f_any_from_any(Core.t_argmap, arglist.vx_any(Core.vx_new_int(1)));
      output = Repl.f_repllist_from_textblocklist_argmap(textblocklist, argmap);
      return output;
    }

    @Override
    public Repl.Type_repllist vx_repllist_from_textblocklist_argmap(final Textblock.Type_textblocklist textblocklist, final Core.Type_argmap argmap) {
      Repl.Type_repllist output = Repl.f_repllist_from_textblocklist_argmap(textblocklist, argmap);
      return output;
    }

  }

  public static final Repl.Func_repllist_from_textblocklist_argmap e_repllist_from_textblocklist_argmap = new Repl.Class_repllist_from_textblocklist_argmap();
  public static final Repl.Func_repllist_from_textblocklist_argmap t_repllist_from_textblocklist_argmap = new Repl.Class_repllist_from_textblocklist_argmap();

  public static Repl.Type_repllist f_repllist_from_textblocklist_argmap(final Textblock.Type_textblocklist textblocklist, final Core.Type_argmap argmap) {
    Repl.Type_repllist output = Repl.e_repllist;
    output = Core.f_list_from_list_1(
      Repl.t_repllist,
      textblocklist,
      Core.t_any_from_any.vx_fn_new((textblock_any) -> {
        Textblock.Type_textblock textblock = Core.f_any_from_any(Textblock.t_textblock, textblock_any);
        Core.Type_any output_1 = Repl.f_repl_from_textblock(
          textblock
        );
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
  public interface Func_textblock_from_script extends Core.Func_any_from_any {
    public Textblock.Type_textblock vx_textblock_from_script(final Core.Type_string script);
  }

  public static class Class_textblock_from_script extends Core.Class_base implements Func_textblock_from_script {

    @Override
    public Core.Type_any vx_new(final Object... vals) {
      Repl.Class_textblock_from_script output = new Repl.Class_textblock_from_script();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Repl.Class_textblock_from_script output = new Repl.Class_textblock_from_script();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Repl.e_textblock_from_script;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Repl.t_textblock_from_script;
      return output;
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

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string script = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Repl.f_textblock_from_script(script);
      return output;
    }

    @Override
    public Textblock.Type_textblock vx_textblock_from_script(final Core.Type_string script) {
      Textblock.Type_textblock output = Repl.f_textblock_from_script(script);
      return output;
    }

  }

  public static final Repl.Func_textblock_from_script e_textblock_from_script = new Repl.Class_textblock_from_script();
  public static final Repl.Func_textblock_from_script t_textblock_from_script = new Repl.Class_textblock_from_script();

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
    public Core.Type_any vx_new(final Object... vals) {
      Repl.Class_typefunc_from_string output = new Repl.Class_typefunc_from_string();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Repl.Class_typefunc_from_string output = new Repl.Class_typefunc_from_string();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.t_func.vx_typedef();
      return output;
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      Core.Type_funcdef output = Core.funcdef_new(
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
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Repl.e_typefunc_from_string;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Repl.t_typefunc_from_string;
      return output;
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

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Repl.f_typefunc_from_string(text);
      return output;
    }

    @Override
    public Core.Type_any vx_typefunc_from_string(final Core.Type_string text) {
      Core.Type_any output = Repl.f_typefunc_from_string(text);
      return output;
    }

  }

  public static final Repl.Func_typefunc_from_string e_typefunc_from_string = new Repl.Class_typefunc_from_string();
  public static final Repl.Func_typefunc_from_string t_typefunc_from_string = new Repl.Class_typefunc_from_string();

  public static Core.Type_any f_typefunc_from_string(final Core.Type_string text) {
    Core.Type_any output = Core.e_any;
    output = Core.f_let(
      Core.t_any,
      Core.t_any_from_func.vx_fn_new(() -> {
        Core.Type_int pkgpos = Type.f_int_from_string_findlast(
          text,
          Core.vx_new_string("/")
        );
        Core.Type_string pkgname = Core.f_if_1(
          Core.t_string,
          Core.f_eq(
            Core.vx_new_int(0),
            pkgpos
          ),
          Core.vx_new_string("vx/core"),
          Type.f_string_from_string_end(
            text,
            Core.f_minus1(
              pkgpos
            )
          )
        );
        Core.Type_string name = Core.f_if_1(
          Core.t_string,
          Core.f_eq(
            Core.vx_new_int(0),
            pkgpos
          ),
          text,
          Type.f_string_from_string_start(
            text,
            Core.f_plus1(
              pkgpos
            )
          )
        );
        Core.Type_package pkg = Core.f_package_global_from_name(
          pkgname
        );
        Core.Type_typemap typemap = pkg.typemap();
        Core.Type_any typeval = Core.f_any_from_map(
          Core.t_any,
          typemap,
          name
        );
        Core.Type_any output_1 = Core.f_if_1(
          Core.t_any,
          Core.f_notempty_1(
            typeval
          ),
          typeval,
          Core.f_let(
            Core.t_any,
            Core.t_any_from_func.vx_fn_new(() -> {
              Core.Type_funcmap funcmap = pkg.funcmap();
              Core.Type_any funcval = Core.f_any_from_map(
                Core.t_any,
                funcmap,
                name
              );
              Core.Type_any output_2 = Core.f_if_1(
                Core.t_any,
                Core.f_notempty_1(
                  funcval
                ),
                funcval,
                Core.f_empty(
                  Core.t_any
                )
              );
              return output_2;
            })
          )
        );
        return output_1;
      })
    );
    return output;
  }


  static {
    Const_delimvxlisp.const_new(c_delimvxlisp);
    Const_delimvxlispbracket.const_new(c_delimvxlispbracket);
    Const_delimvxlispparen.const_new(c_delimvxlispparen);
    Map<String, Core.Type_any> maptype = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<String, Core.Type_func>();
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
