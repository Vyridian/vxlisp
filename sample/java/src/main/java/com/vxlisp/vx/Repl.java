package com.vxlisp.vx;

import java.util.ArrayList;
import java.util.concurrent.CompletableFuture;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import com.vxlisp.vx.data.*;


public final class Repl {


  /**
   * type: liblist
   * List of library names
   * (type liblist)
   */
  public interface Type_liblist extends Core.Type_list {
    public Repl.Type_liblist vx_new(final Object... vals);
    public Repl.Type_liblist vx_copy(final Object... vals);
    public Repl.Type_liblist vx_empty();
    public Repl.Type_liblist vx_type();
    public List<Core.Type_string> vx_liststring();
    public Core.Type_string vx_string(final Core.Type_int index);
  }

  public static class Class_liblist extends Core.Class_base implements Type_liblist {

    protected List<Core.Type_string> vxlist = Core.immutablelist(new ArrayList<Core.Type_string>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Core.Type_string vx_string(final Core.Type_int index) {
      Core.Type_string output = Core.e_string;
      Class_liblist list = this;
      int iindex = index.vx_int();
      List<Core.Type_string> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Core.Type_string> vx_liststring() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_string(index);
    }

    @Override
    public Type_liblist vx_new(final Object... vals) {return e_liblist.vx_copy(vals);}

    @Override
    public Type_liblist vx_copy(final Object... vals) {
      Class_liblist output = new Class_liblist();
      Type_liblist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Core.Type_string> listval = new ArrayList<>(val.vx_liststring());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_string) {
          listval.add((Core.Type_string)valsub);
        } else if (valsub instanceof String) {
          listval.add(Core.t_string.vx_new(valsub));
        } else if (valsub instanceof Type_liblist) {
          Type_liblist multi = (Type_liblist)valsub;
          listval.addAll(multi.vx_liststring());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Core.Type_string) {
              Core.Type_string valitem = (Core.Type_string)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new liblist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      output.vxlist = Core.immutablelist(listval);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_liblist vx_empty() {return e_liblist;}
    @Override
    public Type_liblist vx_type() {return t_liblist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/repl", // pkgname
        "liblist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Core.t_string), // allowtypes
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
    public Repl.Type_repl vx_new(final Object... vals);
    public Repl.Type_repl vx_copy(final Object... vals);
    public Repl.Type_repl vx_empty();
    public Repl.Type_repl vx_type();
    public Core.Type_any type();
    public Repl.Type_repllist repllist();
    public Core.Type_boolean async();
    public Core.Type_any val();
  }

  public static class Class_repl extends Core.Class_base implements Type_repl {

    protected Core.Type_any vx_p_type;

    @Override
    public Core.Type_any type() {
      return this.vx_p_type == null ? Core.e_any : this.vx_p_type;
    }

    protected Repl.Type_repllist vx_p_repllist;

    @Override
    public Repl.Type_repllist repllist() {
      return this.vx_p_repllist == null ? Repl.e_repllist : this.vx_p_repllist;
    }

    protected Core.Type_boolean vx_p_async;

    @Override
    public Core.Type_boolean async() {
      return this.vx_p_async == null ? Core.e_boolean : this.vx_p_async;
    }

    protected Core.Type_any vx_p_val;

    @Override
    public Core.Type_any val() {
      return this.vx_p_val == null ? Core.e_any : this.vx_p_val;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
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
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":type", this.type());
      output.put(":repllist", this.repllist());
      output.put(":async", this.async());
      output.put(":val", this.val());
      return Core.immutablemap(output);
    }

    @Override
    public Type_repl vx_new(final Object... vals) {return e_repl.vx_copy(vals);}

    @Override
    public Type_repl vx_copy(final Object... vals) {
      Class_repl output = new Class_repl();
      Type_repl val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_type = val.type();
      output.vx_p_repllist = val.repllist();
      output.vx_p_async = val.async();
      output.vx_p_val = val.val();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":type");
      validkeys.add(":repllist");
      validkeys.add(":async");
      validkeys.add(":val");
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new repl) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":type":
            if (valsub instanceof Core.Type_any) {
              output.vx_p_type = (Core.Type_any)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new repl :type " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":repllist":
            if (valsub instanceof Repl.Type_repllist) {
              output.vx_p_repllist = (Repl.Type_repllist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new repl :repllist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":async":
            if (valsub instanceof Core.Type_boolean) {
              output.vx_p_async = (Core.Type_boolean)valsub;
            } else if (valsub instanceof Boolean) {
              output.vx_p_async = Core.t_boolean.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new repl :async " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":val":
            if (valsub instanceof Core.Type_any) {
              output.vx_p_val = (Core.Type_any)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new repl :val " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new repl) - Invalid Key: " + key);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_repl vx_empty() {return e_repl;}
    @Override
    public Type_repl vx_type() {return t_repl;}

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
   * type: repllist
   * List of repl
   * (type repllist)
   */
  public interface Type_repllist extends Core.Type_list {
    public Repl.Type_repllist vx_new(final Object... vals);
    public Repl.Type_repllist vx_copy(final Object... vals);
    public Repl.Type_repllist vx_empty();
    public Repl.Type_repllist vx_type();
    public List<Repl.Type_repl> vx_listrepl();
    public Repl.Type_repl vx_repl(final Core.Type_int index);
  }

  public static class Class_repllist extends Core.Class_base implements Type_repllist {

    protected List<Repl.Type_repl> vxlist = Core.immutablelist(new ArrayList<Repl.Type_repl>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Repl.Type_repl vx_repl(final Core.Type_int index) {
      Repl.Type_repl output = Repl.e_repl;
      Class_repllist list = this;
      int iindex = index.vx_int();
      List<Repl.Type_repl> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Repl.Type_repl> vx_listrepl() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_repl(index);
    }

    @Override
    public Type_repllist vx_new(final Object... vals) {return e_repllist.vx_copy(vals);}

    @Override
    public Type_repllist vx_copy(final Object... vals) {
      Class_repllist output = new Class_repllist();
      Type_repllist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Repl.Type_repl> listval = new ArrayList<>(val.vx_listrepl());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Repl.Type_repl) {
          listval.add((Repl.Type_repl)valsub);
        } else if (valsub instanceof Repl.Type_repl) {
          listval.add((Repl.Type_repl)valsub);
        } else if (valsub instanceof Type_repllist) {
          Type_repllist multi = (Type_repllist)valsub;
          listval.addAll(multi.vx_listrepl());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Repl.Type_repl) {
              Repl.Type_repl valitem = (Repl.Type_repl)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new repllist) - Invalid Type: " + valsub.toString());
          msgblock = msgblock.vx_copy(msg);
        }
      }
      output.vxlist = Core.immutablelist(listval);
      if (msgblock != Core.e_msgblock) {
        output.vxmsgblock = msgblock;
      }
      return output;
    }

    @Override
    public Type_repllist vx_empty() {return e_repllist;}
    @Override
    public Type_repllist vx_type() {return t_repllist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/repl", // pkgname
        "repllist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Repl.t_repl), // allowtypes
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
   * @function any_repl_from_functype_args
   * Returns any from a repl func and args.
   * @param  {any} type
   * @param  {anylist} args
   * @return {any}
   * (func any-repl<-functype-args)
   */
  public static interface Func_any_repl_from_functype_args extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_any f_any_repl_from_functype_args(final Core.Type_any type, final Core.Type_anylist args);
  }

  public static class Class_any_repl_from_functype_args extends Core.Class_base implements Func_any_repl_from_functype_args {

    @Override
    public Func_any_repl_from_functype_args vx_new(Object... vals) {
      Class_any_repl_from_functype_args output = new Class_any_repl_from_functype_args();
      return output;
    }

    @Override
    public Func_any_repl_from_functype_args vx_copy(Object... vals) {
      Class_any_repl_from_functype_args output = new Class_any_repl_from_functype_args();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
    public Func_any_repl_from_functype_args vx_empty() {return e_any_repl_from_functype_args;}
    @Override
    public Func_any_repl_from_functype_args vx_type() {return t_any_repl_from_functype_args;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any type = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_anylist args = Core.f_any_from_any(Core.t_anylist, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      output = Repl.f_any_repl_from_functype_args(type, args);
      return output;
    }

    @Override
    public Core.Type_any f_any_repl_from_functype_args(final Core.Type_any type, final Core.Type_anylist args) {
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
  public static interface Func_any_from_liblist_string extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_any f_any_from_liblist_string(final Repl.Type_liblist liblist, final Core.Type_string text, Core.Type_context context);
  }

  public static class Class_any_from_liblist_string extends Core.Class_base implements Func_any_from_liblist_string {

    @Override
    public Func_any_from_liblist_string vx_new(Object... vals) {
      Class_any_from_liblist_string output = new Class_any_from_liblist_string();
      return output;
    }

    @Override
    public Func_any_from_liblist_string vx_copy(Object... vals) {
      Class_any_from_liblist_string output = new Class_any_from_liblist_string();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
    public Func_any_from_liblist_string vx_empty() {return e_any_from_liblist_string;}
    @Override
    public Func_any_from_liblist_string vx_type() {return t_any_from_liblist_string;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Repl.Type_liblist liblist = Core.f_any_from_any(Repl.t_liblist, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.t_int.vx_new_from_int(2)));
      output = Repl.f_any_from_liblist_string(liblist, text, context);
      return output;
    }

    @Override
    public Core.Type_any f_any_from_liblist_string(final Repl.Type_liblist liblist, final Core.Type_string text, final Core.Type_context context) {
      return Repl.f_any_from_liblist_string(liblist, text, context);
    }

  }

  public static final Func_any_from_liblist_string e_any_from_liblist_string = new Repl.Class_any_from_liblist_string();
  public static final Func_any_from_liblist_string t_any_from_liblist_string = new Repl.Class_any_from_liblist_string();

  public static Core.Type_any f_any_from_liblist_string(final Repl.Type_liblist liblist, final Core.Type_string text, final Core.Type_context context) {
    Core.Type_any output = Core.e_any;
    output = Core.f_let(
      Core.t_any,
      Core.t_any_from_func.fn_new(() -> {
        final Repl.Type_repl repl = Repl.f_repl_from_liblist_string(liblist, text);
        return Repl.f_any_from_repl(repl, context);
      })
    );
    return output;
  }

  /**
   * 
   * @async
   * @function any_from_liblist_string_async
   * Run an arbitrary program in the REPL asynchrously.
   * @param  {liblist} liblist
   * @param  {string} text Program to run
   * @return {any}
   * (func any<-liblist-string-async)
   */
  public static interface Func_any_from_liblist_string_async extends Core.Type_func, Core.Type_replfunc_async {
    public CompletableFuture<Core.Type_any> f_any_from_liblist_string_async(final Repl.Type_liblist liblist, final Core.Type_string text, Core.Type_context context);
  }

  public static class Class_any_from_liblist_string_async extends Core.Class_base implements Func_any_from_liblist_string_async {

    @Override
    public Func_any_from_liblist_string_async vx_new(Object... vals) {
      Class_any_from_liblist_string_async output = new Class_any_from_liblist_string_async();
      return output;
    }

    @Override
    public Func_any_from_liblist_string_async vx_copy(Object... vals) {
      Class_any_from_liblist_string_async output = new Class_any_from_liblist_string_async();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/repl", // pkgname
        "any<-liblist-string-async", // name
        0, // idx
        true, // async
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
    public Func_any_from_liblist_string_async vx_empty() {return e_any_from_liblist_string_async;}
    @Override
    public Func_any_from_liblist_string_async vx_type() {return t_any_from_liblist_string_async;}

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Repl.Type_liblist liblist = Core.f_any_from_any(Repl.t_liblist, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.t_int.vx_new_from_int(2)));
      CompletableFuture<Core.Type_any> future = Repl.f_any_from_liblist_string_async(liblist, text, context);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Core.Type_any> f_any_from_liblist_string_async(final Repl.Type_liblist liblist, final Core.Type_string text, final Core.Type_context context) {
      return Repl.f_any_from_liblist_string_async(liblist, text, context);
    }

  }

  public static final Func_any_from_liblist_string_async e_any_from_liblist_string_async = new Repl.Class_any_from_liblist_string_async();
  public static final Func_any_from_liblist_string_async t_any_from_liblist_string_async = new Repl.Class_any_from_liblist_string_async();

  public static CompletableFuture<Core.Type_any> f_any_from_liblist_string_async(final Repl.Type_liblist liblist, final Core.Type_string text, final Core.Type_context context) {
    CompletableFuture<Core.Type_any> output = Core.async_new_completed(Core.e_any);
    output = Core.f_let_async(
      Core.t_any,
      Core.t_any_from_func_async.fn_new(() -> {
        final Repl.Type_repl repl = Repl.f_repl_from_liblist_string(liblist, text);
        final CompletableFuture<Core.Type_any> future_val = Repl.f_any_from_repl_async(repl, context);
        return Core.async_from_async_fn(future_val, (val) -> {
          return val;
        });
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
  public static interface Func_any_from_repl extends Core.Func_any_from_any_context {
    public Core.Type_any f_any_from_repl(final Repl.Type_repl repl, Core.Type_context context);
  }

  public static class Class_any_from_repl extends Core.Class_base implements Func_any_from_repl {

    @Override
    public Func_any_from_repl vx_new(Object... vals) {
      Class_any_from_repl output = new Class_any_from_repl();
      return output;
    }

    @Override
    public Func_any_from_repl vx_copy(Object... vals) {
      Class_any_from_repl output = new Class_any_from_repl();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
    public Func_any_from_repl vx_empty() {return e_any_from_repl;}
    @Override
    public Func_any_from_repl vx_type() {return t_any_from_repl;}

    @Override
    public Core.Func_any_from_any_context fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any_context(final T generic_any_1, final U value, final Core.Type_context context) {
      T output = Core.f_empty(generic_any_1);
      Repl.Type_repl inputval = (Repl.Type_repl)value;
      Core.Type_any outputval = Repl.f_any_from_repl(inputval, context);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Repl.Type_repl repl = Core.f_any_from_any(Repl.t_repl, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      output = Repl.f_any_from_repl(repl, context);
      return output;
    }

    @Override
    public Core.Type_any f_any_from_repl(final Repl.Type_repl repl, final Core.Type_context context) {
      return Repl.f_any_from_repl(repl, context);
    }

  }

  public static final Func_any_from_repl e_any_from_repl = new Repl.Class_any_from_repl();
  public static final Func_any_from_repl t_any_from_repl = new Repl.Class_any_from_repl();

  public static Core.Type_any f_any_from_repl(final Repl.Type_repl repl, final Core.Type_context context) {
    Core.Type_any output = Core.e_any;
    output = Core.f_let(
      Core.t_any,
      Core.t_any_from_func.fn_new(() -> {
        final Core.Type_any val = repl.val();
        final Core.Type_any repltype = repl.type();
        final Repl.Type_repllist repllist = repl.repllist();
        final Core.Type_anylist args = Repl.f_anylist_from_repllist(repllist, context);
        return Core.f_if_2(
          Core.t_any,
          Core.t_thenelselist.vx_new(
            Core.f_then(
              Core.t_boolean_from_func.fn_new(() -> {
                return Core.f_notempty_1(val);
              }),
              Core.t_any_from_func.fn_new(() -> {
                return val;
              })
            ),
            Core.f_then(
              Core.t_boolean_from_func.fn_new(() -> {
                return Core.f_is_func(repltype);
              }),
              Core.t_any_from_func.fn_new(() -> {
                return Repl.f_any_repl_from_functype_args(repltype, args);
              })
            ),
            Core.f_else(
              Core.t_any_from_func.fn_new(() -> {
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
   * 
   * @async
   * @function any_from_repl_async
   * Run an arbitrary program in the REPL.
   * @param  {repl} repl
   * @return {any}
   * (func any<-repl-async)
   */
  public static interface Func_any_from_repl_async extends Core.Func_any_from_any_context_async {
    public CompletableFuture<Core.Type_any> f_any_from_repl_async(final Repl.Type_repl repl, Core.Type_context context);
  }

  public static class Class_any_from_repl_async extends Core.Class_base implements Func_any_from_repl_async {

    @Override
    public Func_any_from_repl_async vx_new(Object... vals) {
      Class_any_from_repl_async output = new Class_any_from_repl_async();
      return output;
    }

    @Override
    public Func_any_from_repl_async vx_copy(Object... vals) {
      Class_any_from_repl_async output = new Class_any_from_repl_async();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/repl", // pkgname
        "any<-repl-async", // name
        0, // idx
        true, // async
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
    public Func_any_from_repl_async vx_empty() {return e_any_from_repl_async;}
    @Override
    public Func_any_from_repl_async vx_type() {return t_any_from_repl_async;}

    @Override
    public Core.Func_any_from_any_context_async fn_new(Core.Class_any_from_any_context_async.IFn fn) {return Core.e_any_from_any_context_async;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_any_context_async(final T generic_any_1, final U value, final Core.Type_context context) {
      Repl.Type_repl inputval = Core.f_any_from_any(Repl.t_repl, value);
      CompletableFuture<Core.Type_any> future = Repl.f_any_from_repl_async(inputval, context);
      @SuppressWarnings("unchecked")
      CompletableFuture<T> output = (CompletableFuture<T>)future;
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Repl.Type_repl repl = Core.f_any_from_any(Repl.t_repl, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      CompletableFuture<Core.Type_any> future = Repl.f_any_from_repl_async(repl, context);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Core.Type_any> f_any_from_repl_async(final Repl.Type_repl repl, final Core.Type_context context) {
      return Repl.f_any_from_repl_async(repl, context);
    }

  }

  public static final Func_any_from_repl_async e_any_from_repl_async = new Repl.Class_any_from_repl_async();
  public static final Func_any_from_repl_async t_any_from_repl_async = new Repl.Class_any_from_repl_async();

  public static CompletableFuture<Core.Type_any> f_any_from_repl_async(final Repl.Type_repl repl, final Core.Type_context context) {
    CompletableFuture<Core.Type_any> output = Core.async_new_completed(Core.e_any);
    return output;
  }

  /**
   * @function anylist_from_repllist
   * Run an arbitrary program in the REPL.
   * @param  {repllist} repllist
   * @return {anylist}
   * (func anylist<-repllist)
   */
  public static interface Func_anylist_from_repllist extends Core.Func_any_from_any_context {
    public Core.Type_anylist f_anylist_from_repllist(final Repl.Type_repllist repllist, Core.Type_context context);
  }

  public static class Class_anylist_from_repllist extends Core.Class_base implements Func_anylist_from_repllist {

    @Override
    public Func_anylist_from_repllist vx_new(Object... vals) {
      Class_anylist_from_repllist output = new Class_anylist_from_repllist();
      return output;
    }

    @Override
    public Func_anylist_from_repllist vx_copy(Object... vals) {
      Class_anylist_from_repllist output = new Class_anylist_from_repllist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
          Core.t_typelist.vx_new(Core.t_any), // allowtypes
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
    public Func_anylist_from_repllist vx_empty() {return e_anylist_from_repllist;}
    @Override
    public Func_anylist_from_repllist vx_type() {return t_anylist_from_repllist;}

    @Override
    public Core.Func_any_from_any_context fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any_context(final T generic_any_1, final U value, final Core.Type_context context) {
      T output = Core.f_empty(generic_any_1);
      Repl.Type_repllist inputval = (Repl.Type_repllist)value;
      Core.Type_any outputval = Repl.f_anylist_from_repllist(inputval, context);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Repl.Type_repllist repllist = Core.f_any_from_any(Repl.t_repllist, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      output = Repl.f_anylist_from_repllist(repllist, context);
      return output;
    }

    @Override
    public Core.Type_anylist f_anylist_from_repllist(final Repl.Type_repllist repllist, final Core.Type_context context) {
      return Repl.f_anylist_from_repllist(repllist, context);
    }

  }

  public static final Func_anylist_from_repllist e_anylist_from_repllist = new Repl.Class_anylist_from_repllist();
  public static final Func_anylist_from_repllist t_anylist_from_repllist = new Repl.Class_anylist_from_repllist();

  public static Core.Type_anylist f_anylist_from_repllist(final Repl.Type_repllist repllist, final Core.Type_context context) {
    Core.Type_anylist output = Core.e_anylist;
    output = Core.f_list_from_list(
      Core.t_anylist,
      repllist,
      Core.t_any_from_any.fn_new((repl_any) -> {
        Repl.Type_repl repl = Core.f_any_from_any(Repl.t_repl, repl_any);
        return 
          Repl.f_any_from_repl(repl, context);
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
  public static interface Func_repl_from_liblist_string extends Core.Type_func, Core.Type_replfunc {
    public Repl.Type_repl f_repl_from_liblist_string(final Repl.Type_liblist liblist, final Core.Type_string text);
  }

  public static class Class_repl_from_liblist_string extends Core.Class_base implements Func_repl_from_liblist_string {

    @Override
    public Func_repl_from_liblist_string vx_new(Object... vals) {
      Class_repl_from_liblist_string output = new Class_repl_from_liblist_string();
      return output;
    }

    @Override
    public Func_repl_from_liblist_string vx_copy(Object... vals) {
      Class_repl_from_liblist_string output = new Class_repl_from_liblist_string();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
    public Func_repl_from_liblist_string vx_empty() {return e_repl_from_liblist_string;}
    @Override
    public Func_repl_from_liblist_string vx_type() {return t_repl_from_liblist_string;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Repl.Type_liblist liblist = Core.f_any_from_any(Repl.t_liblist, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      output = Repl.f_repl_from_liblist_string(liblist, text);
      return output;
    }

    @Override
    public Repl.Type_repl f_repl_from_liblist_string(final Repl.Type_liblist liblist, final Core.Type_string text) {
      return Repl.f_repl_from_liblist_string(liblist, text);
    }

  }

  public static final Func_repl_from_liblist_string e_repl_from_liblist_string = new Repl.Class_repl_from_liblist_string();
  public static final Func_repl_from_liblist_string t_repl_from_liblist_string = new Repl.Class_repl_from_liblist_string();

  public static Repl.Type_repl f_repl_from_liblist_string(final Repl.Type_liblist liblist, final Core.Type_string text) {
    Repl.Type_repl output = Repl.e_repl;
    return output;
  }


}
