namespace vx;

public static class vx_sample {


  /**
   * type: mytype
   * (type mytype)
   */
  public interface Type_mytype : vx_core.Type_struct {
    public vx_core.Type_any vx_new(params Object[] vals);
    public vx_core.Type_any vx_copy(params Object[] vals);
    public vx_core.Type_any vx_empty();
    public vx_core.Type_any vx_type();
    public vx_core.Type_int mynum();
    public vx_core.Type_string mystr();
  }

  public class Class_mytype : vx_core.Class_base, Type_mytype {

    public vx_core.Type_int vx_p_mynum;

    public vx_core.Type_int mynum() {
      return this.vx_p_mynum == null ? vx_core.e_int : this.vx_p_mynum;
    }

    public vx_core.Type_string vx_p_mystr;

    public vx_core.Type_string mystr() {
      return this.vx_p_mystr == null ? vx_core.e_string : this.vx_p_mystr;
    }

    public vx_core.Type_any vx_any(vx_core.Type_string key) {
      vx_core.Type_any output = vx_core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":mynum":
        output = this.mynum();
        break;
      case ":mystr":
        output = this.mystr();
        break;
      }
      return output;
    }

    public vx_core.Map<string, vx_core.Type_any> vx_map() {
      vx_core.Map<string, vx_core.Type_any> output = new vx_core.LinkedHashMap<string, vx_core.Type_any>();
      output.put(":mynum", this.mynum());
      output.put(":mystr", this.mystr());
      return vx_core.immutablemap(output);
    }

    public override vx_sample.Type_mytype vx_new(params Object[] vals) {
      return vx_core.vx_copy(
       e_mytype,
       vals);
    }

    public override vx_sample.Type_mytype vx_copy(params Object[] vals) {
      Type_mytype output = this;
      bool ischanged = false;
      Class_mytype val = this;
      vx_core.Type_msgblock msgblock = vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is vx_core.vx_Type_const) {
        ischanged = true;
      }
      vx_core.Type_int vx_p_mynum = val.mynum();
      vx_core.Type_string vx_p_mystr = val.mystr();
      List<string> validkeys = new List<string>();
      validkeys.Add(":mynum");
      validkeys.Add(":mystr");
      string key = "";
      vx_core.Type_msg msg;
      vx_core.Type_any msgval;
      foreach (Object valsub in vals) {
        if (valsub is vx_core.Type_msgblock) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is vx_core.Type_msg) {
          msgblock = vx_core.vx_copy(msgblock, valsub);
        } else if (key == "") {
          bool istestkey = false;
          string testkey = "";
          if (valsub is vx_core.Type_string) {
            vx_core.Type_string valstr = (vx_core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is vx_core.Type_any) {
              msgval = (vx_core.Type_any)valsub;
            } else {
              msgval = vx_core.vx_new_string(valsub.ToString());
            }
            msg = vx_core.vx_msg_from_error("vx/sample/mytype", ":invalidkeytype", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
          }
          if (istestkey) {
            if (!testkey.StartsWith(":")) {
              testkey = ":" + testkey;
            }
            bool isvalidkey = validkeys.Contains(testkey);
            if (isvalidkey) {
              key = testkey;
            } else {
              msgval = vx_core.vx_new_string(testkey);
              msg = vx_core.vx_msg_from_error("vx/sample/mytype", ":invalidkey", msgval);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":mynum":
            if (valsub == vx_p_mynum) {
            } else if (valsub is vx_core.Type_int) {
              ischanged = true;
              vx_p_mynum = (vx_core.Type_int)valsub;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_mynum = vx_core.vx_new(vx_core.t_int, valsub);
            } else {
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.ToString());
              }
              vx_core.Map<string, vx_core.Type_any> mapany = new vx_core.LinkedHashMap<string, vx_core.Type_any>();
              mapany.put("key", vx_core.vx_new_string("mynum"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/sample/mytype", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":mystr":
            if (valsub == vx_p_mystr) {
            } else if (valsub is vx_core.Type_string) {
              ischanged = true;
              vx_p_mystr = (vx_core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_mystr = vx_core.vx_new(vx_core.t_string, valsub);
            } else {
              if (valsub is vx_core.Type_any) {
                msgval = (vx_core.Type_any)valsub;
              } else {
                msgval = vx_core.vx_new_string(valsub.ToString());
              }
              vx_core.Map<string, vx_core.Type_any> mapany = new vx_core.LinkedHashMap<string, vx_core.Type_any>();
              mapany.put("key", vx_core.vx_new_string("mystr"));
              mapany.put("value", msgval);
              vx_core.Type_map msgmap = vx_core.t_anymap.vx_new_from_map(mapany);
              msg = vx_core.vx_msg_from_error("vx/sample/mytype", ":invalidvalue", msgmap);
              msgblock = vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = vx_core.vx_new_string(key);
            msg = vx_core.vx_msg_from_error("vx/sample/mytype", ":invalidkey", msgval);
            msgblock = vx_core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core.e_msgblock)) {
        Class_mytype work = new Class_mytype();
        work.vx_p_mynum = vx_p_mynum;
        work.vx_p_mystr = vx_p_mystr;
        if (msgblock != vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override vx_core.Type_any vx_empty() {
      return e_mytype;
    }
    public override vx_core.Type_any vx_type() {
      return t_mytype;
    }

    public override vx_core.Type_typedef vx_typedef() {
      return vx_core.typedef_new(
        "vx/sample", // pkgname
        "mytype", // name
        ":struct", // extends
        vx_core.e_typelist, // traits
        vx_core.e_typelist, // allowtypes
        vx_core.e_typelist, // disallowtypes
        vx_core.e_funclist, // allowfuncs
        vx_core.e_funclist, // disallowfuncs
        vx_core.e_anylist, // allowvalues
        vx_core.e_anylist, // disallowvalues
        vx_core.e_argmap // properties
      );
    }

  }

  public static Type_mytype e_mytype = new Class_mytype();
  public static Type_mytype t_mytype = new Class_mytype();

  /**
   * Constant: myconst
   * My Constant
   * {int}
   */
  public class Const_myconst : vx_core.Class_int, vx_core.vx_Type_const {
    
    public vx_core.Type_constdef vx_constdef() {
      return vx_core.constdef_new(
        "vx/sample", // pkgname
        "myconst", // name
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        )
      );
    }

    public static void const_new(Const_myconst output) {
    }

    public int vx_int() {
      this.vxint = 4;
      return this.vxint;
    }

  }

  public static Const_myconst c_myconst = new Const_myconst();

  /**
   * @function main
   * @return {none}
   * (func main)
   */
  public interface Func_main : vx_core.Type_func, vx_core.Type_replfunc {
    public void vx_main();
  }

  public class Class_main : vx_core.Class_base, Func_main {

    public override vx_sample.Func_main vx_new(params Object[] vals) {
      Class_main output = new Class_main();
      return output;
    }

    public override vx_sample.Func_main vx_copy(params Object[] vals) {
      Class_main output = new Class_main();
      return output;
    }

    public vx_core.Type_typedef vx_typedef() {
      return vx_core.t_func.vx_typedef();
    }

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/sample", // pkgname
        "main", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "none", // name
          "", // extends
          vx_core.e_typelist, // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override vx_core.Type_any vx_empty() {
      return e_main;
    }

    public override vx_core.Type_any vx_type() {
      return t_main;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_sample.f_main();
      return output;
    }

    public void vx_main() {vx_sample.f_main();
    }

  }

  public static Func_main e_main = new vx_sample.Class_main();
  public static Func_main t_main = new vx_sample.Class_main();

  public static void f_main() {
    vx_sample.f_myfunc(vx_core.vx_new_int(2));
  }

  /**
   * @function myfunc
   * My Function
   * @param  {int} myarg My Arg
   * @return {int}
   * (func myfunc)
   */
  public interface Func_myfunc : vx_core.Func_any_from_any {
    public vx_core.Type_int vx_myfunc(vx_core.Type_int myarg);
  }

  public class Class_myfunc : vx_core.Class_base, Func_myfunc {

    public override vx_sample.Func_myfunc vx_new(params Object[] vals) {
      Class_myfunc output = new Class_myfunc();
      return output;
    }

    public override vx_sample.Func_myfunc vx_copy(params Object[] vals) {
      Class_myfunc output = new Class_myfunc();
      return output;
    }

    public vx_core.Type_typedef vx_typedef() {
      return vx_core.t_func.vx_typedef();
    }

    public vx_core.Type_funcdef vx_funcdef() {
      return vx_core.funcdef_new(
        "vx/sample", // pkgname
        "myfunc", // name
        0, // idx
        false, // async
        vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core.vx_new(vx_core.t_typelist, vx_core.t_number), // traits
          vx_core.e_typelist, // allowtypes
          vx_core.e_typelist, // disallowtypes
          vx_core.e_funclist, // allowfuncs
          vx_core.e_funclist, // disallowfuncs
          vx_core.e_anylist, // allowvalues
          vx_core.e_anylist, // disallowvalues
          vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override vx_core.Type_any vx_empty() {
      return e_myfunc;
    }

    public override vx_core.Type_any vx_type() {
      return t_myfunc;
    }

    public vx_core.Func_any_from_any vx_fn_new(vx_core.Class_any_from_any.IFn fn) {
      return vx_core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : vx_core.Type_any where U : vx_core.Type_any {
      T output = vx_core.f_empty(generic_any_1);
      vx_core.Type_int inputval = (vx_core.Type_int)value;
      vx_core.Type_any outputval = vx_sample.f_myfunc(inputval);
      output = vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public vx_core.Type_any vx_repl(vx_core.Type_anylist arglist) {
      vx_core.Type_any output = vx_core.e_any;
      vx_core.Type_int myarg = vx_core.f_any_from_any(vx_core.t_int, arglist.vx_any(vx_core.vx_new_int(0)));
      output = vx_sample.f_myfunc(myarg);
      return output;
    }

    public vx_core.Type_int vx_myfunc(vx_core.Type_int myarg) {
      return vx_sample.f_myfunc(myarg);
    }

  }

  public static Func_myfunc e_myfunc = new vx_sample.Class_myfunc();
  public static Func_myfunc t_myfunc = new vx_sample.Class_myfunc();

  public static vx_core.Type_int f_myfunc(vx_core.Type_int myarg) {
    vx_core.Type_int output = vx_core.e_int;
    output = vx_core.f_plus(
      vx_sample.c_myconst,
      myarg
    );
    return output;
  }


  public static class PackageRunOnce {
    public static void RunOnce() {
    Const_myconst.const_new(c_myconst);
    vx_core.Map<string, vx_core.Type_any> maptype = new vx_core.LinkedHashMap<string, vx_core.Type_any>();
    vx_core.Map<string, vx_core.Type_any> mapconst = new vx_core.LinkedHashMap<string, vx_core.Type_any>();
    vx_core.Map<string, vx_core.Type_func> mapfunc = new vx_core.LinkedHashMap<string, vx_core.Type_func>();
    maptype.put("mytype", vx_sample.t_mytype);
    mapconst.put("myconst", vx_sample.c_myconst);
    mapfunc.put("main", vx_sample.t_main);
    mapfunc.put("myfunc", vx_sample.t_myfunc);
    vx_core.vx_global_package_set("vx/sample", maptype, mapconst, mapfunc);
    }
  }

}
