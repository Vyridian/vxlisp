namespace Vx;

public static class Sample {


  /**
   * type: mytype
   * (type mytype)
   */
  public interface Type_mytype : Vx.Core.Type_struct {
    public Vx.Core.Type_any vx_new(params Object[] vals);
    public Vx.Core.Type_any vx_copy(params Object[] vals);
    public Vx.Core.Type_any vx_empty();
    public Vx.Core.Type_any vx_type();
    public Vx.Core.Type_int mynum();
    public Vx.Core.Type_string mystr();
  }

  public class Class_mytype : Vx.Core.Class_base, Type_mytype {

    public Vx.Core.Type_int vx_p_mynum;

    public Vx.Core.Type_int mynum() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_mynum != null) {
        output = this.vx_p_mynum;
      }
      return output;
    }

    public Vx.Core.Type_string vx_p_mystr;

    public Vx.Core.Type_string mystr() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_mystr != null) {
        output = this.vx_p_mystr;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":mynum", this.mynum());
      output.put(":mystr", this.mystr());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Sample.Type_mytype vx_new(params Object[] vals) {
      return Vx.Core.vx_copy(
       e_mytype,
       vals);
    }

    public override Vx.Sample.Type_mytype vx_copy(params Object[] vals) {
      Type_mytype output = this;
      bool ischanged = false;
      Class_mytype val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_int vx_p_mynum = val.mynum();
      Vx.Core.Type_string vx_p_mystr = val.mystr();
      List<string> validkeys = new List<string>();
      validkeys.Add(":mynum");
      validkeys.Add(":mystr");
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
          if (valsub is Vx.Core.Type_string) {
            Vx.Core.Type_string valstr = (Vx.Core.Type_string)valsub;
            testkey = valstr.vx_string();
            istestkey = true;
          } else if (valsub is string) {
            testkey = (String)valsub;
            istestkey = true;
          } else {
            if (valsub is Vx.Core.Type_any) {
              msgval = (Vx.Core.Type_any)valsub;
            } else {
              msgval = Vx.Core.vx_new_string(valsub.ToString());
            }
            msg = Vx.Core.vx_msg_from_error("vx/sample/mytype", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/sample/mytype", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":mynum":
            if (valsub == vx_p_mynum) {
            } else if (valsub is Vx.Core.Type_int) {
              ischanged = true;
              vx_p_mynum = (Vx.Core.Type_int)valsub;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_mynum = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("mynum"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/sample/mytype", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":mystr":
            if (valsub == vx_p_mystr) {
            } else if (valsub is Vx.Core.Type_string) {
              ischanged = true;
              vx_p_mystr = (Vx.Core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_mystr = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (valsub is Vx.Core.Type_any) {
                msgval = (Vx.Core.Type_any)valsub;
              } else {
                msgval = Vx.Core.vx_new_string(valsub.ToString());
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("mystr"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/sample/mytype", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/sample/mytype", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_mytype work = new Class_mytype();
        work.vx_p_mynum = vx_p_mynum;
        work.vx_p_mystr = vx_p_mystr;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_mytype;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_mytype;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/sample", // pkgname
        "mytype", // name
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

  public static Type_mytype e_mytype = new Class_mytype();
  public static Type_mytype t_mytype = new Class_mytype();

  /**
   * Constant: myconst
   * My Constant
   * {int}
   */
  public class Const_myconst : Vx.Core.Class_int, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/sample", // pkgname
        "myconst", // name
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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
  public interface Func_main : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public void vx_main();
  }

  public class Class_main : Vx.Core.Class_base, Func_main {

    public override Vx.Sample.Func_main vx_new(params Object[] vals) {
      Class_main output = new Class_main();
      return output;
    }

    public override Vx.Sample.Func_main vx_copy(params Object[] vals) {
      Class_main output = new Class_main();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/sample", // pkgname
        "main", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "none", // name
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
      return e_main;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_main;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Sample.f_main();
      return output;
    }

    public void vx_main() {Vx.Sample.f_main();
    }

  }

  public static Func_main e_main = new Vx.Sample.Class_main();
  public static Func_main t_main = new Vx.Sample.Class_main();

  public static void f_main() {
    Vx.Sample.f_myfunc(Vx.Core.vx_new_int(2));
  }

  /**
   * @function myfunc
   * My Function
   * @param  {int} myarg My Arg
   * @return {int}
   * (func myfunc)
   */
  public interface Func_myfunc : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_int vx_myfunc(Vx.Core.Type_int myarg);
  }

  public class Class_myfunc : Vx.Core.Class_base, Func_myfunc {

    public override Vx.Sample.Func_myfunc vx_new(params Object[] vals) {
      Class_myfunc output = new Class_myfunc();
      return output;
    }

    public override Vx.Sample.Func_myfunc vx_copy(params Object[] vals) {
      Class_myfunc output = new Class_myfunc();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/sample", // pkgname
        "myfunc", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_number), // traits
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
      return e_myfunc;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_myfunc;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_int inputval = (Vx.Core.Type_int)value;
      Vx.Core.Type_any outputval = Vx.Sample.f_myfunc(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_int myarg = Vx.Core.f_any_from_any(Vx.Core.t_int, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Sample.f_myfunc(myarg);
      return output;
    }

    public Vx.Core.Type_int vx_myfunc(Vx.Core.Type_int myarg) {
      return Vx.Sample.f_myfunc(myarg);
    }

  }

  public static Func_myfunc e_myfunc = new Vx.Sample.Class_myfunc();
  public static Func_myfunc t_myfunc = new Vx.Sample.Class_myfunc();

  public static Vx.Core.Type_int f_myfunc(Vx.Core.Type_int myarg) {
    Vx.Core.Type_int output = Vx.Core.e_int;
    output = Vx.Core.f_plus(
      Vx.Sample.c_myconst,
      myarg
    );
    return output;
  }


  public static class PackageRunOnce {
    public static void RunOnce() {
    Const_myconst.const_new(c_myconst);
    Vx.Core.Map<string, Vx.Core.Type_any> maptype = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_any> mapconst = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_func> mapfunc = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>();
    maptype.put("mytype", Vx.Sample.t_mytype);
    mapconst.put("myconst", Vx.Sample.c_myconst);
    mapfunc.put("main", Vx.Sample.t_main);
    mapfunc.put("myfunc", Vx.Sample.t_myfunc);
    Vx.Core.vx_global_package_set("vx/sample", maptype, mapconst, mapfunc);
    }
  }

}
