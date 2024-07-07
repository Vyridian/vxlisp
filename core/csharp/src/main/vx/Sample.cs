namespace Vx;

public static class Vx_sample {


  /**
   * type: mytype
   * (type mytype)
   */
  public interface Type_mytype : Vx_core.Type_struct {
    public Vx_core.Type_any vx_new(params Object[] vals);
    public Vx_core.Type_any vx_copy(params Object[] vals);
    public Vx_core.Type_any vx_empty();
    public Vx_core.Type_any vx_type();
    public Vx_core.Type_int mynum();
    public Vx_core.Type_string mystr();
  }

  public class Class_mytype : Vx_core.Class_base, Type_mytype {

    public Vx_core.Type_int vx_p_mynum;

    public Vx_core.Type_int mynum() {
      Vx_core.Type_int output = Vx_core.e_int;
      if (this.vx_p_mynum != null) {
        output = this.vx_p_mynum;
      }
      return output;
    }

    public Vx_core.Type_string vx_p_mystr;

    public Vx_core.Type_string mystr() {
      Vx_core.Type_string output = Vx_core.e_string;
      if (this.vx_p_mystr != null) {
        output = this.vx_p_mystr;
      }
      return output;
    }

    public Vx_core.Type_any vx_any(Vx_core.Type_string key) {
      Vx_core.Type_any output = Vx_core.e_any;
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

    public Vx_core.Map<string, Vx_core.Type_any> vx_map() {
      Vx_core.Map<string, Vx_core.Type_any> output = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
      output.put(":mynum", this.mynum());
      output.put(":mystr", this.mystr());
      return Vx_core.immutablemap(output);
    }

    public override Vx_sample.Type_mytype vx_new(params Object[] vals) {
      return Vx_core.vx_copy(
       e_mytype,
       vals);
    }

    public override Vx_sample.Type_mytype vx_copy(params Object[] vals) {
      Type_mytype output = this;
      bool ischanged = false;
      Class_mytype val = this;
      Vx_core.Type_msgblock msgblock = Vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx_core.vx_Type_const) {
        ischanged = true;
      }
      Vx_core.Type_int vx_p_mynum = val.mynum();
      Vx_core.Type_string vx_p_mystr = val.mystr();
      List<string> validkeys = new List<string>();
      validkeys.Add(":mynum");
      validkeys.Add(":mystr");
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
            msg = Vx_core.vx_msg_from_error("vx/sample/mytype", ":invalidkeytype", msgval);
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
              msg = Vx_core.vx_msg_from_error("vx/sample/mytype", ":invalidkey", msgval);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":mynum":
            if (valsub == vx_p_mynum) {
            } else if (valsub is Vx_core.Type_int) {
              ischanged = true;
              vx_p_mynum = (Vx_core.Type_int)valsub;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_mynum = Vx_core.vx_new(Vx_core.t_int, valsub);
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("mynum"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/sample/mytype", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":mystr":
            if (valsub == vx_p_mystr) {
            } else if (valsub is Vx_core.Type_string) {
              ischanged = true;
              vx_p_mystr = (Vx_core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_mystr = Vx_core.vx_new(Vx_core.t_string, valsub);
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("mystr"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/sample/mytype", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx_core.vx_new_string(key);
            msg = Vx_core.vx_msg_from_error("vx/sample/mytype", ":invalidkey", msgval);
            msgblock = Vx_core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx_core.e_msgblock)) {
        Class_mytype work = new Class_mytype();
        work.vx_p_mynum = vx_p_mynum;
        work.vx_p_mystr = vx_p_mystr;
        if (msgblock != Vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx_core.Type_any vx_empty() {
      return e_mytype;
    }
    public override Vx_core.Type_any vx_type() {
      return t_mytype;
    }

    public override Vx_core.Type_typedef vx_typedef() {
      return Vx_core.typedef_new(
        "vx/sample", // pkgname
        "mytype", // name
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

  public static Type_mytype e_mytype = new Class_mytype();
  public static Type_mytype t_mytype = new Class_mytype();

  /**
   * Constant: myconst
   * My Constant
   * {int}
   */
  public class Const_myconst : Vx_core.Class_int, Vx_core.vx_Type_const {
    
    public Vx_core.Type_constdef vx_constdef() {
      return Vx_core.constdef_new(
        "vx/sample", // pkgname
        "myconst", // name
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx_core.vx_new(Vx_core.t_typelist, Vx_core.t_number), // traits
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
  public interface Func_main : Vx_core.Type_func, Vx_core.Type_replfunc {
    public void vx_main();
  }

  public class Class_main : Vx_core.Class_base, Func_main {

    public override Vx_sample.Func_main vx_new(params Object[] vals) {
      Class_main output = new Class_main();
      return output;
    }

    public override Vx_sample.Func_main vx_copy(params Object[] vals) {
      Class_main output = new Class_main();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/sample", // pkgname
        "main", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "none", // name
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
      return e_main;
    }

    public override Vx_core.Type_any vx_type() {
      return t_main;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_sample.f_main();
      return output;
    }

    public void vx_main() {Vx_sample.f_main();
    }

  }

  public static Func_main e_main = new Vx_sample.Class_main();
  public static Func_main t_main = new Vx_sample.Class_main();

  public static void f_main() {
    Vx_sample.f_myfunc(Vx_core.vx_new_int(2));
  }

  /**
   * @function myfunc
   * My Function
   * @param  {int} myarg My Arg
   * @return {int}
   * (func myfunc)
   */
  public interface Func_myfunc : Vx_core.Func_any_from_any {
    public Vx_core.Type_int vx_myfunc(Vx_core.Type_int myarg);
  }

  public class Class_myfunc : Vx_core.Class_base, Func_myfunc {

    public override Vx_sample.Func_myfunc vx_new(params Object[] vals) {
      Class_myfunc output = new Class_myfunc();
      return output;
    }

    public override Vx_sample.Func_myfunc vx_copy(params Object[] vals) {
      Class_myfunc output = new Class_myfunc();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/sample", // pkgname
        "myfunc", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx_core.vx_new(Vx_core.t_typelist, Vx_core.t_number), // traits
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
      return e_myfunc;
    }

    public override Vx_core.Type_any vx_type() {
      return t_myfunc;
    }

    public Vx_core.Func_any_from_any vx_fn_new(Vx_core.Class_any_from_any.IFn fn) {
      return Vx_core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_core.Type_int inputval = (Vx_core.Type_int)value;
      Vx_core.Type_any outputval = Vx_sample.f_myfunc(inputval);
      output = Vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_int myarg = Vx_core.f_any_from_any(Vx_core.t_int, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_sample.f_myfunc(myarg);
      return output;
    }

    public Vx_core.Type_int vx_myfunc(Vx_core.Type_int myarg) {
      return Vx_sample.f_myfunc(myarg);
    }

  }

  public static Func_myfunc e_myfunc = new Vx_sample.Class_myfunc();
  public static Func_myfunc t_myfunc = new Vx_sample.Class_myfunc();

  public static Vx_core.Type_int f_myfunc(Vx_core.Type_int myarg) {
    Vx_core.Type_int output = Vx_core.e_int;
    output = Vx_core.f_plus(
      Vx_sample.c_myconst,
      myarg
    );
    return output;
  }


  public static class PackageRunOnce {
    public static void RunOnce() {
    Const_myconst.const_new(c_myconst);
    Vx_core.Map<string, Vx_core.Type_any> maptype = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
    Vx_core.Map<string, Vx_core.Type_any> mapconst = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
    Vx_core.Map<string, Vx_core.Type_func> mapfunc = new Vx_core.LinkedHashMap<string, Vx_core.Type_func>();
    maptype.put("mytype", Vx_sample.t_mytype);
    mapconst.put("myconst", Vx_sample.c_myconst);
    mapfunc.put("main", Vx_sample.t_main);
    mapfunc.put("myfunc", Vx_sample.t_myfunc);
    Vx_core.vx_global_package_set("vx/sample", maptype, mapconst, mapfunc);
    }
  }

}
