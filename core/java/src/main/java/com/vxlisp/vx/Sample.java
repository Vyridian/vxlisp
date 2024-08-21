package com.vxlisp.vx;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

public final class Sample {


  /**
   * type: mytype
   * (type mytype)
   */
  public interface Type_mytype extends Core.Type_struct {
    public Core.Type_int mynum();
    public Core.Type_string mystr();
  }

  public static class Class_mytype extends Core.Class_base implements Type_mytype {

    public Core.Type_int vx_p_mynum = null;

    @Override
    public Core.Type_int mynum() {
      Core.Type_int output = Core.e_int;
      Core.Type_int testnull = vx_p_mynum;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_string vx_p_mystr = null;

    @Override
    public Core.Type_string mystr() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_mystr;
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
      } else if ((skey.equals(":mynum"))) {
        output = this.mynum();
      } else if ((skey.equals(":mystr"))) {
        output = this.mystr();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":mynum", this.mynum());
      map.put(":mystr", this.mystr());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Sample.Type_mytype vx_new(final Object... vals) {
      Sample.Type_mytype output = Core.vx_copy(Sample.e_mytype, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Sample.Type_mytype output = this;
      boolean ischanged = false;
      Sample.Class_mytype value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_int vx_p_mynum = value.mynum();
      Core.Type_string vx_p_mystr = value.mystr();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":mynum");
      validkeys.add(":mystr");
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
            msg = Core.vx_msg_from_error("vx/sample/mytype", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/sample/mytype", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key.equals(":mynum"))) {
            if (valsub == vx_p_mynum) {
            } else if (valsub instanceof Core.Type_int) {
              Core.Type_int valmynum = (Core.Type_int)valsub;
              ischanged = true;
              vx_p_mynum = valmynum;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_mynum = Core.vx_new(Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("mynum"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/sample/mytype", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else if ((key.equals(":mystr"))) {
            if (valsub == vx_p_mystr) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valmystr = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_mystr = valmystr;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_mystr = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("mystr"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/sample/mytype", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/sample/mytype", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Sample.Class_mytype work = new Sample.Class_mytype();
        work.vx_p_mynum = vx_p_mynum;
        work.vx_p_mystr = vx_p_mystr;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Sample.e_mytype;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Sample.t_mytype;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
        "vx/sample", // pkgname
        "mytype", // name
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

  public static final Sample.Type_mytype e_mytype = new Sample.Class_mytype();
  public static final Sample.Type_mytype t_mytype = new Sample.Class_mytype();

  /**
   * Constant: myconst
   * My Constant
   * {int}
   */
  public static class Const_myconst {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
        "vx/sample", // pkgname
        "myconst", // name
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.vx_new(Core.t_typelist, Core.t_number), // traits
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

    public static void const_new(Core.Type_int output) {
      Core.Class_int outval = (Core.Class_int)output;
      outval.vx_p_constdef = constdef();
      outval.vxint = 4;
    }

  }

  public static final Core.Type_int c_myconst = new Core.Class_int();

  /**
   * @function main
   * @return {none}
   * (func main)
   */
  public interface Func_main extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_none vx_main();
  }

  public static class Class_main extends Core.Class_base implements Func_main {

    @Override
    public Sample.Func_main vx_new(final Object... vals) {
      Sample.Class_main output = new Sample.Class_main();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Sample.Class_main output = new Sample.Class_main();
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
        "vx/sample", // pkgname
        "main", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "none", // name
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
      Core.Type_any output = Sample.e_main;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Sample.t_main;
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      output = Sample.f_main();
      return output;
    }

    @Override
    public Core.Type_none vx_main() {
      Core.Type_none output = Sample.f_main();
      return output;
    }

  }

  public static final Sample.Func_main e_main = new Sample.Class_main();
  public static final Sample.Func_main t_main = new Sample.Class_main();

  public static Core.Type_none f_main() {
    Core.Type_none output = Core.e_none;
    Sample.f_myfunc(
      Core.vx_new_int(2)
    );
    return output;
  }

  /**
   * @function myfunc
   * My Function
   * @param  {int} myarg My Arg
   * @return {int}
   * (func myfunc)
   */
  public interface Func_myfunc extends Core.Func_any_from_any {
    public Core.Type_int vx_myfunc(final Core.Type_int myarg);
  }

  public static class Class_myfunc extends Core.Class_base implements Func_myfunc {

    @Override
    public Sample.Func_myfunc vx_new(final Object... vals) {
      Sample.Class_myfunc output = new Sample.Class_myfunc();
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Sample.Class_myfunc output = new Sample.Class_myfunc();
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
        "vx/sample", // pkgname
        "myfunc", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Core.vx_new(Core.t_typelist, Core.t_number), // traits
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
      Core.Type_any output = Sample.e_myfunc;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Sample.t_myfunc;
      return output;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_int inputval = (Core.Type_int)value;
      Core.Type_any outputval = Sample.f_myfunc(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    @Override
    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_int myarg = Core.f_any_from_any(Core.t_int, arglist.vx_any(Core.vx_new_int(0)));
      output = Sample.f_myfunc(myarg);
      return output;
    }

    @Override
    public Core.Type_int vx_myfunc(final Core.Type_int myarg) {
      Core.Type_int output = Sample.f_myfunc(myarg);
      return output;
    }

  }

  public static final Sample.Func_myfunc e_myfunc = new Sample.Class_myfunc();
  public static final Sample.Func_myfunc t_myfunc = new Sample.Class_myfunc();

  public static Core.Type_int f_myfunc(final Core.Type_int myarg) {
    Core.Type_int output = Core.e_int;
    output = Core.f_plus(
      Sample.c_myconst,
      myarg
    );
    return output;
  }


  static {
    Const_myconst.const_new(c_myconst);
    Map<String, Core.Type_any> maptype = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<String, Core.Type_func>();
    maptype.put("mytype", Sample.t_mytype);
    mapconst.put("myconst", Sample.c_myconst);
    mapfunc.put("main", Sample.t_main);
    mapfunc.put("myfunc", Sample.t_myfunc);
    Core.vx_global_package_set("vx/sample", maptype, mapconst, mapfunc);
  }

}
