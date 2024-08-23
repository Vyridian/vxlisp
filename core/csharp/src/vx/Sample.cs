namespace Vx;

public static class Sample {


  /**
   * type: mytype
   * (type mytype)
   */
  public interface Type_mytype : Vx.Core.Type_struct {
    public Vx.Core.Type_int mynum();
    public Vx.Core.Type_string mystr();
  }

  public class Class_mytype : Vx.Core.Class_base, Type_mytype {

    public Vx.Core.Type_int? vx_p_mynum = null;

    public Vx.Core.Type_int mynum() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      Vx.Core.Type_int? testnull = vx_p_mynum;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_mystr = null;

    public Vx.Core.Type_string mystr() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Core.Type_string? testnull = vx_p_mystr;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      if (false) {
      } else if ((skey==":mynum")) {
        output = this.mynum();
      } else if ((skey==":mystr")) {
        output = this.mystr();
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      map.put(":mynum", this.mynum());
      map.put(":mystr", this.mystr());
      Vx.Core.Map<string, Vx.Core.Type_any> output = Vx.Core.immutablemap(map);
      return output;
    }

    public override Vx.Core.Type_any vx_new(params object[] vals) {
      Vx.Sample.Type_mytype output = Vx.Core.vx_copy(Vx.Sample.e_mytype, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Sample.Type_mytype output = this;
      bool ischanged = false;
      Vx.Sample.Class_mytype value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_int vx_p_mynum = value.mynum();
      Vx.Core.Type_string vx_p_mystr = value.mystr();
      List<string> validkeys = new List<string>();
      validkeys.Add(":mynum");
      validkeys.Add(":mystr");
      string key = "";
      Vx.Core.Type_msg msg = Vx.Core.e_msg;
      Vx.Core.Type_any msgval = Vx.Core.e_any;
      foreach (object valsub in vals) {
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
          if (false) {
          } else if ((key==":mynum")) {
            if (valsub == vx_p_mynum) {
            } else if (valsub is Vx.Core.Type_int valmynum) {
              ischanged = true;
              vx_p_mynum = valmynum;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_mynum = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("mynum"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/sample/mytype", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":mystr")) {
            if (valsub == vx_p_mystr) {
            } else if (valsub is Vx.Core.Type_string valmystr) {
              ischanged = true;
              vx_p_mystr = valmystr;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_mystr = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("mystr"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/sample/mytype", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/sample/mytype", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Sample.Class_mytype work = new Vx.Sample.Class_mytype();
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
      Vx.Core.Type_any output = Vx.Sample.e_mytype;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Sample.t_mytype;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
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
      return output;
    }

  }

  public static Vx.Sample.Type_mytype e_mytype = new Vx.Sample.Class_mytype();
  public static Vx.Sample.Type_mytype t_mytype = new Vx.Sample.Class_mytype();

  /**
   * Constant: myconst
   * My Constant
   * {int}
   */
  public class Const_myconst {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
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
      return output;
    }

    public static void const_new(Vx.Core.Type_int output) {
      Vx.Core.Class_int outval = (Vx.Core.Class_int)output;
      outval.vx_p_constdef = constdef();
      outval.vxint = 4;
    }

  }

  public static Vx.Core.Type_int c_myconst = new Vx.Core.Class_int();

  /**
   * @function main
   * @return {none}
   * (func main)
   */
  public interface Func_main : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_none vx_main();
  }

  public class Class_main : Vx.Core.Class_base, Func_main {

    public override Vx.Core.Type_any vx_new(params object[] vals) {
      Vx.Sample.Class_main output = new Vx.Sample.Class_main();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Sample.Class_main output = new Vx.Sample.Class_main();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Sample.e_main;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Sample.t_main;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      output = Vx.Sample.f_main();
      return output;
    }

    public Vx.Core.Type_none vx_main() {
      Vx.Core.Type_none output = Vx.Sample.f_main();
      return output;
    }

  }

  public static Vx.Sample.Func_main e_main = new Vx.Sample.Class_main();
  public static Vx.Sample.Func_main t_main = new Vx.Sample.Class_main();

  public static Vx.Core.Type_none f_main() {
    Vx.Core.Type_none output = Vx.Core.e_none;
    Vx.Sample.f_myfunc(
      Vx.Core.vx_new_int(2)
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
  public interface Func_myfunc : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_int vx_myfunc(Vx.Core.Type_int myarg);
  }

  public class Class_myfunc : Vx.Core.Class_base, Func_myfunc {

    public override Vx.Core.Type_any vx_new(params object[] vals) {
      Vx.Sample.Class_myfunc output = new Vx.Sample.Class_myfunc();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Sample.Class_myfunc output = new Vx.Sample.Class_myfunc();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Sample.e_myfunc;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Sample.t_myfunc;
      return output;
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
      Vx.Core.Type_int output = Vx.Sample.f_myfunc(myarg);
      return output;
    }

  }

  public static Vx.Sample.Func_myfunc e_myfunc = new Vx.Sample.Class_myfunc();
  public static Vx.Sample.Func_myfunc t_myfunc = new Vx.Sample.Class_myfunc();

  public static Vx.Core.Type_int f_myfunc(Vx.Core.Type_int myarg) {
    Vx.Core.Type_int output = Vx.Core.e_int;
    output = Vx.Core.f_plus(
      Vx.Sample.c_myconst,
      myarg
    );
    return output;
  }


  public static class PackageRunOnce {
    public static bool RunOnce() {
    Const_myconst.const_new(c_myconst);
    Vx.Core.Map<string, Vx.Core.Type_any> maptype = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_any> mapconst = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_func> mapfunc = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>();
    maptype.put("mytype", Vx.Sample.t_mytype);
    mapconst.put("myconst", Vx.Sample.c_myconst);
    mapfunc.put("main", Vx.Sample.t_main);
    mapfunc.put("myfunc", Vx.Sample.t_myfunc);
    Vx.Core.vx_global_package_set("vx/sample", maptype, mapconst, mapfunc);
      return true;
    }
  }

  public static bool ranonce = PackageRunOnce.RunOnce();

}
