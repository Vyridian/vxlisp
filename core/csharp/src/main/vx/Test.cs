namespace Vx;

using Vx;

public static class Vx_test {


  /**
   * type: testcase
   * Structure to describe a test case
   * (type testcase)
   */
  public interface Type_testcase : Vx_core.Type_struct {
    public Vx_core.Type_any vx_new(params Object[] vals);
    public Vx_core.Type_any vx_copy(params Object[] vals);
    public Vx_core.Type_any vx_empty();
    public Vx_core.Type_any vx_type();
    public Vx_core.Type_boolean passfail();
    public Vx_core.Type_string testpkg();
    public Vx_core.Type_string casename();
    public Vx_test.Type_testdescribelist describelist();
  }

  public class Class_testcase : Vx_core.Class_base, Type_testcase {

    public Vx_core.Type_boolean vx_p_passfail;

    public Vx_core.Type_boolean passfail() {
      Vx_core.Type_boolean output = Vx_core.e_boolean;
      if (this.vx_p_passfail != null) {
        output = this.vx_p_passfail;
      }
      return output;
    }

    public Vx_core.Type_string vx_p_testpkg;

    public Vx_core.Type_string testpkg() {
      Vx_core.Type_string output = Vx_core.e_string;
      if (this.vx_p_testpkg != null) {
        output = this.vx_p_testpkg;
      }
      return output;
    }

    public Vx_core.Type_string vx_p_casename;

    public Vx_core.Type_string casename() {
      Vx_core.Type_string output = Vx_core.e_string;
      if (this.vx_p_casename != null) {
        output = this.vx_p_casename;
      }
      return output;
    }

    public Vx_test.Type_testdescribelist vx_p_describelist;

    public Vx_test.Type_testdescribelist describelist() {
      Vx_test.Type_testdescribelist output = Vx_test.e_testdescribelist;
      if (this.vx_p_describelist != null) {
        output = this.vx_p_describelist;
      }
      return output;
    }

    public Vx_core.Type_any vx_any(Vx_core.Type_string key) {
      Vx_core.Type_any output = Vx_core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":passfail":
        output = this.passfail();
        break;
      case ":testpkg":
        output = this.testpkg();
        break;
      case ":casename":
        output = this.casename();
        break;
      case ":describelist":
        output = this.describelist();
        break;
      }
      return output;
    }

    public Vx_core.Map<string, Vx_core.Type_any> vx_map() {
      Vx_core.Map<string, Vx_core.Type_any> output = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
      output.put(":passfail", this.passfail());
      output.put(":testpkg", this.testpkg());
      output.put(":casename", this.casename());
      output.put(":describelist", this.describelist());
      return Vx_core.immutablemap(output);
    }

    public override Vx_test.Type_testcase vx_new(params Object[] vals) {
      return Vx_core.vx_copy(
       e_testcase,
       vals);
    }

    public override Vx_test.Type_testcase vx_copy(params Object[] vals) {
      Type_testcase output = this;
      bool ischanged = false;
      Class_testcase val = this;
      Vx_core.Type_msgblock msgblock = Vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx_core.vx_Type_const) {
        ischanged = true;
      }
      Vx_core.Type_boolean vx_p_passfail = val.passfail();
      Vx_core.Type_string vx_p_testpkg = val.testpkg();
      Vx_core.Type_string vx_p_casename = val.casename();
      Vx_test.Type_testdescribelist vx_p_describelist = val.describelist();
      List<string> validkeys = new List<string>();
      validkeys.Add(":passfail");
      validkeys.Add(":testpkg");
      validkeys.Add(":casename");
      validkeys.Add(":describelist");
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
            msg = Vx_core.vx_msg_from_error("vx/test/testcase", ":invalidkeytype", msgval);
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
              msg = Vx_core.vx_msg_from_error("vx/test/testcase", ":invalidkey", msgval);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":passfail":
            if (valsub == vx_p_passfail) {
            } else if (valsub is Vx_core.Type_boolean) {
              ischanged = true;
              vx_p_passfail = (Vx_core.Type_boolean)valsub;
            } else if (valsub is bool) {
              ischanged = true;
              vx_p_passfail = Vx_core.vx_new(Vx_core.t_boolean, valsub);
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("passfail"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testcase", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":testpkg":
            if (valsub == vx_p_testpkg) {
            } else if (valsub is Vx_core.Type_string) {
              ischanged = true;
              vx_p_testpkg = (Vx_core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_testpkg = Vx_core.vx_new(Vx_core.t_string, valsub);
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("testpkg"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testcase", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":casename":
            if (valsub == vx_p_casename) {
            } else if (valsub is Vx_core.Type_string) {
              ischanged = true;
              vx_p_casename = (Vx_core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_casename = Vx_core.vx_new(Vx_core.t_string, valsub);
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("casename"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testcase", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":describelist":
            if (valsub == vx_p_describelist) {
            } else if (valsub is Vx_test.Type_testdescribelist) {
              ischanged = true;
              vx_p_describelist = (Vx_test.Type_testdescribelist)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("describelist"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testcase", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx_core.vx_new_string(key);
            msg = Vx_core.vx_msg_from_error("vx/test/testcase", ":invalidkey", msgval);
            msgblock = Vx_core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx_core.e_msgblock)) {
        Class_testcase work = new Class_testcase();
        work.vx_p_passfail = vx_p_passfail;
        work.vx_p_testpkg = vx_p_testpkg;
        work.vx_p_casename = vx_p_casename;
        work.vx_p_describelist = vx_p_describelist;
        if (msgblock != Vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx_core.Type_any vx_empty() {
      return e_testcase;
    }
    public override Vx_core.Type_any vx_type() {
      return t_testcase;
    }

    public override Vx_core.Type_typedef vx_typedef() {
      return Vx_core.typedef_new(
        "vx/test", // pkgname
        "testcase", // name
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

  public static Type_testcase e_testcase = new Class_testcase();
  public static Type_testcase t_testcase = new Class_testcase();

  /**
   * type: testcaselist
   * List of test cases
   * (type testcaselist)
   */
  public interface Type_testcaselist : Vx_core.Type_list {
    public Vx_core.Type_any vx_new(params Object[] vals);
    public Vx_core.Type_any vx_copy(params Object[] vals);
    public Vx_core.Type_any vx_empty();
    public Vx_core.Type_any vx_type();
    public List<Vx_test.Type_testcase> vx_listtestcase();
    public Vx_test.Type_testcase vx_testcase(Vx_core.Type_int index);
  }

  public class Class_testcaselist : Vx_core.Class_base, Type_testcaselist {

    public List<Vx_test.Type_testcase> vx_p_list = Vx_core.immutablelist(new List<Vx_test.Type_testcase>());

    public List<Vx_core.Type_any> vx_list() {
      List<Vx_core.Type_any> output = Vx_core.immutablelist(
        new List<Vx_core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx_test.Type_testcase vx_testcase(Vx_core.Type_int index) {
      Vx_test.Type_testcase output = Vx_test.e_testcase;
      Vx_test.Class_testcaselist list = this;
      int iindex = index.vx_int();
      List<Vx_test.Type_testcase> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx_test.Type_testcase> vx_listtestcase() {
      return vx_p_list;
    }

    public Vx_core.Type_any vx_any(Vx_core.Type_int index) {
      return this.vx_testcase(index);
    }

    public override Vx_test.Type_testcaselist vx_new(params Object[] vals) {
      return Vx_core.vx_copy(
       e_testcaselist,
       vals);
    }

    public override Vx_test.Type_testcaselist vx_copy(params Object[] vals) {
      Type_testcaselist output = this;
      bool ischanged = false;
      Class_testcaselist val = this;
      Vx_core.Type_msgblock msgblock = Vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx_core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx_test.Type_testcase> listval = new List<Vx_test.Type_testcase>(val.vx_listtestcase());
      Vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx_core.Type_msgblock) {
          msgblock = Vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx_core.Type_msg) {
          msgblock = Vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx_test.Type_testcase) {
          Vx_test.Type_testcase anysub = valsub as Vx_test.Type_testcase;
          ischanged = true;
          listval.Add(anysub);
        } else if (valsub is Vx_test.Type_testcase) {
          ischanged = true;
          listval.Add((Vx_test.Type_testcase)valsub);
        } else if (valsub is Vx_test.Type_testcaselist) {
          Type_testcaselist multi = (Type_testcaselist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_listtestcase());
        } else if (valsub is List<object>) {
          List<object> listunknown = valsub as List<object>;
          foreach (Object item in listunknown) {
            if (item is Vx_test.Type_testcase) {
              Vx_test.Type_testcase valitem = (Vx_test.Type_testcase)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx_core.Type_any) {
          Vx_core.Type_any anysub = valsub as Vx_core.Type_any;
          msg = Vx_core.vx_msg_from_error("vx/test/testcaselist", ":invalidtype", anysub);
          msgblock = Vx_core.vx_copy(msgblock, msg);
        } else {
          msg = Vx_core.vx_msg_from_error("vx/test/testcaselist", ":invalidtype", Vx_core.vx_new_string(valsub.ToString()));
          msgblock = Vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx_core.e_msgblock)) {
        Class_testcaselist work = new Class_testcaselist();
        work.vx_p_list = Vx_core.immutablelist(listval);
        if (msgblock != Vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx_core.Type_any vx_empty() {
      return e_testcaselist;
    }
    public override Vx_core.Type_any vx_type() {
      return t_testcaselist;
    }

    public override Vx_core.Type_typedef vx_typedef() {
      return Vx_core.typedef_new(
        "vx/test", // pkgname
        "testcaselist", // name
        ":list", // extends
        Vx_core.e_typelist, // traits
        Vx_core.vx_new(Vx_core.t_typelist, Vx_test.t_testcase), // allowtypes
        Vx_core.e_typelist, // disallowtypes
        Vx_core.e_funclist, // allowfuncs
        Vx_core.e_funclist, // disallowfuncs
        Vx_core.e_anylist, // allowvalues
        Vx_core.e_anylist, // disallowvalues
        Vx_core.e_argmap // properties
      );
    }

  }

  public static Type_testcaselist e_testcaselist = new Class_testcaselist();
  public static Type_testcaselist t_testcaselist = new Class_testcaselist();

  /**
   * type: testcoveragedetail
   * Structure to describe a test coverage detail
   * (type testcoveragedetail)
   */
  public interface Type_testcoveragedetail : Vx_core.Type_struct {
    public Vx_core.Type_any vx_new(params Object[] vals);
    public Vx_core.Type_any vx_copy(params Object[] vals);
    public Vx_core.Type_any vx_empty();
    public Vx_core.Type_any vx_type();
    public Vx_core.Type_intmap constmap();
    public Vx_core.Type_intmap funcmap();
    public Vx_core.Type_string testpkg();
    public Vx_core.Type_intmap typemap();
  }

  public class Class_testcoveragedetail : Vx_core.Class_base, Type_testcoveragedetail {

    public Vx_core.Type_intmap vx_p_constmap;

    public Vx_core.Type_intmap constmap() {
      Vx_core.Type_intmap output = Vx_core.e_intmap;
      if (this.vx_p_constmap != null) {
        output = this.vx_p_constmap;
      }
      return output;
    }

    public Vx_core.Type_intmap vx_p_funcmap;

    public Vx_core.Type_intmap funcmap() {
      Vx_core.Type_intmap output = Vx_core.e_intmap;
      if (this.vx_p_funcmap != null) {
        output = this.vx_p_funcmap;
      }
      return output;
    }

    public Vx_core.Type_string vx_p_testpkg;

    public Vx_core.Type_string testpkg() {
      Vx_core.Type_string output = Vx_core.e_string;
      if (this.vx_p_testpkg != null) {
        output = this.vx_p_testpkg;
      }
      return output;
    }

    public Vx_core.Type_intmap vx_p_typemap;

    public Vx_core.Type_intmap typemap() {
      Vx_core.Type_intmap output = Vx_core.e_intmap;
      if (this.vx_p_typemap != null) {
        output = this.vx_p_typemap;
      }
      return output;
    }

    public Vx_core.Type_any vx_any(Vx_core.Type_string key) {
      Vx_core.Type_any output = Vx_core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":constmap":
        output = this.constmap();
        break;
      case ":funcmap":
        output = this.funcmap();
        break;
      case ":testpkg":
        output = this.testpkg();
        break;
      case ":typemap":
        output = this.typemap();
        break;
      }
      return output;
    }

    public Vx_core.Map<string, Vx_core.Type_any> vx_map() {
      Vx_core.Map<string, Vx_core.Type_any> output = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
      output.put(":constmap", this.constmap());
      output.put(":funcmap", this.funcmap());
      output.put(":testpkg", this.testpkg());
      output.put(":typemap", this.typemap());
      return Vx_core.immutablemap(output);
    }

    public override Vx_test.Type_testcoveragedetail vx_new(params Object[] vals) {
      return Vx_core.vx_copy(
       e_testcoveragedetail,
       vals);
    }

    public override Vx_test.Type_testcoveragedetail vx_copy(params Object[] vals) {
      Type_testcoveragedetail output = this;
      bool ischanged = false;
      Class_testcoveragedetail val = this;
      Vx_core.Type_msgblock msgblock = Vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx_core.vx_Type_const) {
        ischanged = true;
      }
      Vx_core.Type_intmap vx_p_constmap = val.constmap();
      Vx_core.Type_intmap vx_p_funcmap = val.funcmap();
      Vx_core.Type_string vx_p_testpkg = val.testpkg();
      Vx_core.Type_intmap vx_p_typemap = val.typemap();
      List<string> validkeys = new List<string>();
      validkeys.Add(":constmap");
      validkeys.Add(":funcmap");
      validkeys.Add(":testpkg");
      validkeys.Add(":typemap");
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
            msg = Vx_core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidkeytype", msgval);
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
              msg = Vx_core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidkey", msgval);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":constmap":
            if (valsub == vx_p_constmap) {
            } else if (valsub is Vx_core.Type_intmap) {
              ischanged = true;
              vx_p_constmap = (Vx_core.Type_intmap)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("constmap"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":funcmap":
            if (valsub == vx_p_funcmap) {
            } else if (valsub is Vx_core.Type_intmap) {
              ischanged = true;
              vx_p_funcmap = (Vx_core.Type_intmap)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("funcmap"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":testpkg":
            if (valsub == vx_p_testpkg) {
            } else if (valsub is Vx_core.Type_string) {
              ischanged = true;
              vx_p_testpkg = (Vx_core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_testpkg = Vx_core.vx_new(Vx_core.t_string, valsub);
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("testpkg"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":typemap":
            if (valsub == vx_p_typemap) {
            } else if (valsub is Vx_core.Type_intmap) {
              ischanged = true;
              vx_p_typemap = (Vx_core.Type_intmap)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("typemap"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx_core.vx_new_string(key);
            msg = Vx_core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidkey", msgval);
            msgblock = Vx_core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx_core.e_msgblock)) {
        Class_testcoveragedetail work = new Class_testcoveragedetail();
        work.vx_p_constmap = vx_p_constmap;
        work.vx_p_funcmap = vx_p_funcmap;
        work.vx_p_testpkg = vx_p_testpkg;
        work.vx_p_typemap = vx_p_typemap;
        if (msgblock != Vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx_core.Type_any vx_empty() {
      return e_testcoveragedetail;
    }
    public override Vx_core.Type_any vx_type() {
      return t_testcoveragedetail;
    }

    public override Vx_core.Type_typedef vx_typedef() {
      return Vx_core.typedef_new(
        "vx/test", // pkgname
        "testcoveragedetail", // name
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

  public static Type_testcoveragedetail e_testcoveragedetail = new Class_testcoveragedetail();
  public static Type_testcoveragedetail t_testcoveragedetail = new Class_testcoveragedetail();

  /**
   * type: testcoveragenums
   * Structure to describe a test coverage summary
   * (type testcoveragenums)
   */
  public interface Type_testcoveragenums : Vx_core.Type_struct {
    public Vx_core.Type_any vx_new(params Object[] vals);
    public Vx_core.Type_any vx_copy(params Object[] vals);
    public Vx_core.Type_any vx_empty();
    public Vx_core.Type_any vx_type();
    public Vx_core.Type_int pct();
    public Vx_core.Type_string testpkg();
    public Vx_core.Type_int tests();
    public Vx_core.Type_int total();
  }

  public class Class_testcoveragenums : Vx_core.Class_base, Type_testcoveragenums {

    public Vx_core.Type_int vx_p_pct;

    public Vx_core.Type_int pct() {
      Vx_core.Type_int output = Vx_core.e_int;
      if (this.vx_p_pct != null) {
        output = this.vx_p_pct;
      }
      return output;
    }

    public Vx_core.Type_string vx_p_testpkg;

    public Vx_core.Type_string testpkg() {
      Vx_core.Type_string output = Vx_core.e_string;
      if (this.vx_p_testpkg != null) {
        output = this.vx_p_testpkg;
      }
      return output;
    }

    public Vx_core.Type_int vx_p_tests;

    public Vx_core.Type_int tests() {
      Vx_core.Type_int output = Vx_core.e_int;
      if (this.vx_p_tests != null) {
        output = this.vx_p_tests;
      }
      return output;
    }

    public Vx_core.Type_int vx_p_total;

    public Vx_core.Type_int total() {
      Vx_core.Type_int output = Vx_core.e_int;
      if (this.vx_p_total != null) {
        output = this.vx_p_total;
      }
      return output;
    }

    public Vx_core.Type_any vx_any(Vx_core.Type_string key) {
      Vx_core.Type_any output = Vx_core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":pct":
        output = this.pct();
        break;
      case ":testpkg":
        output = this.testpkg();
        break;
      case ":tests":
        output = this.tests();
        break;
      case ":total":
        output = this.total();
        break;
      }
      return output;
    }

    public Vx_core.Map<string, Vx_core.Type_any> vx_map() {
      Vx_core.Map<string, Vx_core.Type_any> output = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
      output.put(":pct", this.pct());
      output.put(":testpkg", this.testpkg());
      output.put(":tests", this.tests());
      output.put(":total", this.total());
      return Vx_core.immutablemap(output);
    }

    public override Vx_test.Type_testcoveragenums vx_new(params Object[] vals) {
      return Vx_core.vx_copy(
       e_testcoveragenums,
       vals);
    }

    public override Vx_test.Type_testcoveragenums vx_copy(params Object[] vals) {
      Type_testcoveragenums output = this;
      bool ischanged = false;
      Class_testcoveragenums val = this;
      Vx_core.Type_msgblock msgblock = Vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx_core.vx_Type_const) {
        ischanged = true;
      }
      Vx_core.Type_int vx_p_pct = val.pct();
      Vx_core.Type_string vx_p_testpkg = val.testpkg();
      Vx_core.Type_int vx_p_tests = val.tests();
      Vx_core.Type_int vx_p_total = val.total();
      List<string> validkeys = new List<string>();
      validkeys.Add(":pct");
      validkeys.Add(":testpkg");
      validkeys.Add(":tests");
      validkeys.Add(":total");
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
            msg = Vx_core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidkeytype", msgval);
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
              msg = Vx_core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidkey", msgval);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":pct":
            if (valsub == vx_p_pct) {
            } else if (valsub is Vx_core.Type_int) {
              ischanged = true;
              vx_p_pct = (Vx_core.Type_int)valsub;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_pct = Vx_core.vx_new(Vx_core.t_int, valsub);
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("pct"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":testpkg":
            if (valsub == vx_p_testpkg) {
            } else if (valsub is Vx_core.Type_string) {
              ischanged = true;
              vx_p_testpkg = (Vx_core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_testpkg = Vx_core.vx_new(Vx_core.t_string, valsub);
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("testpkg"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":tests":
            if (valsub == vx_p_tests) {
            } else if (valsub is Vx_core.Type_int) {
              ischanged = true;
              vx_p_tests = (Vx_core.Type_int)valsub;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_tests = Vx_core.vx_new(Vx_core.t_int, valsub);
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("tests"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":total":
            if (valsub == vx_p_total) {
            } else if (valsub is Vx_core.Type_int) {
              ischanged = true;
              vx_p_total = (Vx_core.Type_int)valsub;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_total = Vx_core.vx_new(Vx_core.t_int, valsub);
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("total"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx_core.vx_new_string(key);
            msg = Vx_core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidkey", msgval);
            msgblock = Vx_core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx_core.e_msgblock)) {
        Class_testcoveragenums work = new Class_testcoveragenums();
        work.vx_p_pct = vx_p_pct;
        work.vx_p_testpkg = vx_p_testpkg;
        work.vx_p_tests = vx_p_tests;
        work.vx_p_total = vx_p_total;
        if (msgblock != Vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx_core.Type_any vx_empty() {
      return e_testcoveragenums;
    }
    public override Vx_core.Type_any vx_type() {
      return t_testcoveragenums;
    }

    public override Vx_core.Type_typedef vx_typedef() {
      return Vx_core.typedef_new(
        "vx/test", // pkgname
        "testcoveragenums", // name
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

  public static Type_testcoveragenums e_testcoveragenums = new Class_testcoveragenums();
  public static Type_testcoveragenums t_testcoveragenums = new Class_testcoveragenums();

  /**
   * type: testcoveragesummary
   * Structure to describe a test coverage summary
   * (type testcoveragesummary)
   */
  public interface Type_testcoveragesummary : Vx_core.Type_struct {
    public Vx_core.Type_any vx_new(params Object[] vals);
    public Vx_core.Type_any vx_copy(params Object[] vals);
    public Vx_core.Type_any vx_empty();
    public Vx_core.Type_any vx_type();
    public Vx_test.Type_testcoveragenums bigospacenums();
    public Vx_test.Type_testcoveragenums bigotimenums();
    public Vx_test.Type_testcoveragenums constnums();
    public Vx_test.Type_testcoveragenums docnums();
    public Vx_test.Type_testcoveragenums funcnums();
    public Vx_core.Type_string testpkg();
    public Vx_test.Type_testcoveragenums totalnums();
    public Vx_test.Type_testcoveragenums typenums();
  }

  public class Class_testcoveragesummary : Vx_core.Class_base, Type_testcoveragesummary {

    public Vx_test.Type_testcoveragenums vx_p_bigospacenums;

    public Vx_test.Type_testcoveragenums bigospacenums() {
      Vx_test.Type_testcoveragenums output = Vx_test.e_testcoveragenums;
      if (this.vx_p_bigospacenums != null) {
        output = this.vx_p_bigospacenums;
      }
      return output;
    }

    public Vx_test.Type_testcoveragenums vx_p_bigotimenums;

    public Vx_test.Type_testcoveragenums bigotimenums() {
      Vx_test.Type_testcoveragenums output = Vx_test.e_testcoveragenums;
      if (this.vx_p_bigotimenums != null) {
        output = this.vx_p_bigotimenums;
      }
      return output;
    }

    public Vx_test.Type_testcoveragenums vx_p_constnums;

    public Vx_test.Type_testcoveragenums constnums() {
      Vx_test.Type_testcoveragenums output = Vx_test.e_testcoveragenums;
      if (this.vx_p_constnums != null) {
        output = this.vx_p_constnums;
      }
      return output;
    }

    public Vx_test.Type_testcoveragenums vx_p_docnums;

    public Vx_test.Type_testcoveragenums docnums() {
      Vx_test.Type_testcoveragenums output = Vx_test.e_testcoveragenums;
      if (this.vx_p_docnums != null) {
        output = this.vx_p_docnums;
      }
      return output;
    }

    public Vx_test.Type_testcoveragenums vx_p_funcnums;

    public Vx_test.Type_testcoveragenums funcnums() {
      Vx_test.Type_testcoveragenums output = Vx_test.e_testcoveragenums;
      if (this.vx_p_funcnums != null) {
        output = this.vx_p_funcnums;
      }
      return output;
    }

    public Vx_core.Type_string vx_p_testpkg;

    public Vx_core.Type_string testpkg() {
      Vx_core.Type_string output = Vx_core.e_string;
      if (this.vx_p_testpkg != null) {
        output = this.vx_p_testpkg;
      }
      return output;
    }

    public Vx_test.Type_testcoveragenums vx_p_totalnums;

    public Vx_test.Type_testcoveragenums totalnums() {
      Vx_test.Type_testcoveragenums output = Vx_test.e_testcoveragenums;
      if (this.vx_p_totalnums != null) {
        output = this.vx_p_totalnums;
      }
      return output;
    }

    public Vx_test.Type_testcoveragenums vx_p_typenums;

    public Vx_test.Type_testcoveragenums typenums() {
      Vx_test.Type_testcoveragenums output = Vx_test.e_testcoveragenums;
      if (this.vx_p_typenums != null) {
        output = this.vx_p_typenums;
      }
      return output;
    }

    public Vx_core.Type_any vx_any(Vx_core.Type_string key) {
      Vx_core.Type_any output = Vx_core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":bigospacenums":
        output = this.bigospacenums();
        break;
      case ":bigotimenums":
        output = this.bigotimenums();
        break;
      case ":constnums":
        output = this.constnums();
        break;
      case ":docnums":
        output = this.docnums();
        break;
      case ":funcnums":
        output = this.funcnums();
        break;
      case ":testpkg":
        output = this.testpkg();
        break;
      case ":totalnums":
        output = this.totalnums();
        break;
      case ":typenums":
        output = this.typenums();
        break;
      }
      return output;
    }

    public Vx_core.Map<string, Vx_core.Type_any> vx_map() {
      Vx_core.Map<string, Vx_core.Type_any> output = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
      output.put(":bigospacenums", this.bigospacenums());
      output.put(":bigotimenums", this.bigotimenums());
      output.put(":constnums", this.constnums());
      output.put(":docnums", this.docnums());
      output.put(":funcnums", this.funcnums());
      output.put(":testpkg", this.testpkg());
      output.put(":totalnums", this.totalnums());
      output.put(":typenums", this.typenums());
      return Vx_core.immutablemap(output);
    }

    public override Vx_test.Type_testcoveragesummary vx_new(params Object[] vals) {
      return Vx_core.vx_copy(
       e_testcoveragesummary,
       vals);
    }

    public override Vx_test.Type_testcoveragesummary vx_copy(params Object[] vals) {
      Type_testcoveragesummary output = this;
      bool ischanged = false;
      Class_testcoveragesummary val = this;
      Vx_core.Type_msgblock msgblock = Vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx_core.vx_Type_const) {
        ischanged = true;
      }
      Vx_test.Type_testcoveragenums vx_p_bigospacenums = val.bigospacenums();
      Vx_test.Type_testcoveragenums vx_p_bigotimenums = val.bigotimenums();
      Vx_test.Type_testcoveragenums vx_p_constnums = val.constnums();
      Vx_test.Type_testcoveragenums vx_p_docnums = val.docnums();
      Vx_test.Type_testcoveragenums vx_p_funcnums = val.funcnums();
      Vx_core.Type_string vx_p_testpkg = val.testpkg();
      Vx_test.Type_testcoveragenums vx_p_totalnums = val.totalnums();
      Vx_test.Type_testcoveragenums vx_p_typenums = val.typenums();
      List<string> validkeys = new List<string>();
      validkeys.Add(":bigospacenums");
      validkeys.Add(":bigotimenums");
      validkeys.Add(":constnums");
      validkeys.Add(":docnums");
      validkeys.Add(":funcnums");
      validkeys.Add(":testpkg");
      validkeys.Add(":totalnums");
      validkeys.Add(":typenums");
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
            msg = Vx_core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidkeytype", msgval);
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
              msg = Vx_core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidkey", msgval);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":bigospacenums":
            if (valsub == vx_p_bigospacenums) {
            } else if (valsub is Vx_test.Type_testcoveragenums) {
              ischanged = true;
              vx_p_bigospacenums = (Vx_test.Type_testcoveragenums)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("bigospacenums"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":bigotimenums":
            if (valsub == vx_p_bigotimenums) {
            } else if (valsub is Vx_test.Type_testcoveragenums) {
              ischanged = true;
              vx_p_bigotimenums = (Vx_test.Type_testcoveragenums)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("bigotimenums"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":constnums":
            if (valsub == vx_p_constnums) {
            } else if (valsub is Vx_test.Type_testcoveragenums) {
              ischanged = true;
              vx_p_constnums = (Vx_test.Type_testcoveragenums)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("constnums"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":docnums":
            if (valsub == vx_p_docnums) {
            } else if (valsub is Vx_test.Type_testcoveragenums) {
              ischanged = true;
              vx_p_docnums = (Vx_test.Type_testcoveragenums)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("docnums"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":funcnums":
            if (valsub == vx_p_funcnums) {
            } else if (valsub is Vx_test.Type_testcoveragenums) {
              ischanged = true;
              vx_p_funcnums = (Vx_test.Type_testcoveragenums)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("funcnums"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":testpkg":
            if (valsub == vx_p_testpkg) {
            } else if (valsub is Vx_core.Type_string) {
              ischanged = true;
              vx_p_testpkg = (Vx_core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_testpkg = Vx_core.vx_new(Vx_core.t_string, valsub);
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("testpkg"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":totalnums":
            if (valsub == vx_p_totalnums) {
            } else if (valsub is Vx_test.Type_testcoveragenums) {
              ischanged = true;
              vx_p_totalnums = (Vx_test.Type_testcoveragenums)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("totalnums"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":typenums":
            if (valsub == vx_p_typenums) {
            } else if (valsub is Vx_test.Type_testcoveragenums) {
              ischanged = true;
              vx_p_typenums = (Vx_test.Type_testcoveragenums)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("typenums"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx_core.vx_new_string(key);
            msg = Vx_core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidkey", msgval);
            msgblock = Vx_core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx_core.e_msgblock)) {
        Class_testcoveragesummary work = new Class_testcoveragesummary();
        work.vx_p_bigospacenums = vx_p_bigospacenums;
        work.vx_p_bigotimenums = vx_p_bigotimenums;
        work.vx_p_constnums = vx_p_constnums;
        work.vx_p_docnums = vx_p_docnums;
        work.vx_p_funcnums = vx_p_funcnums;
        work.vx_p_testpkg = vx_p_testpkg;
        work.vx_p_totalnums = vx_p_totalnums;
        work.vx_p_typenums = vx_p_typenums;
        if (msgblock != Vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx_core.Type_any vx_empty() {
      return e_testcoveragesummary;
    }
    public override Vx_core.Type_any vx_type() {
      return t_testcoveragesummary;
    }

    public override Vx_core.Type_typedef vx_typedef() {
      return Vx_core.typedef_new(
        "vx/test", // pkgname
        "testcoveragesummary", // name
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

  public static Type_testcoveragesummary e_testcoveragesummary = new Class_testcoveragesummary();
  public static Type_testcoveragesummary t_testcoveragesummary = new Class_testcoveragesummary();

  /**
   * type: testdescribe
   * Structure to describe test results
   * (type testdescribe)
   */
  public interface Type_testdescribe : Vx_core.Type_struct {
    public Vx_core.Type_any vx_new(params Object[] vals);
    public Vx_core.Type_any vx_copy(params Object[] vals);
    public Vx_core.Type_any vx_empty();
    public Vx_core.Type_any vx_type();
    public Vx_core.Type_string describename();
    public Vx_core.Type_string testpkg();
    public Vx_test.Type_testresult testresult();
  }

  public class Class_testdescribe : Vx_core.Class_base, Type_testdescribe {

    public Vx_core.Type_string vx_p_describename;

    public Vx_core.Type_string describename() {
      Vx_core.Type_string output = Vx_core.e_string;
      if (this.vx_p_describename != null) {
        output = this.vx_p_describename;
      }
      return output;
    }

    public Vx_core.Type_string vx_p_testpkg;

    public Vx_core.Type_string testpkg() {
      Vx_core.Type_string output = Vx_core.e_string;
      if (this.vx_p_testpkg != null) {
        output = this.vx_p_testpkg;
      }
      return output;
    }

    public Vx_test.Type_testresult vx_p_testresult;

    public Vx_test.Type_testresult testresult() {
      Vx_test.Type_testresult output = Vx_test.e_testresult;
      if (this.vx_p_testresult != null) {
        output = this.vx_p_testresult;
      }
      return output;
    }

    public Vx_core.Type_any vx_any(Vx_core.Type_string key) {
      Vx_core.Type_any output = Vx_core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":describename":
        output = this.describename();
        break;
      case ":testpkg":
        output = this.testpkg();
        break;
      case ":testresult":
        output = this.testresult();
        break;
      }
      return output;
    }

    public Vx_core.Map<string, Vx_core.Type_any> vx_map() {
      Vx_core.Map<string, Vx_core.Type_any> output = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
      output.put(":describename", this.describename());
      output.put(":testpkg", this.testpkg());
      output.put(":testresult", this.testresult());
      return Vx_core.immutablemap(output);
    }

    public override Vx_test.Type_testdescribe vx_new(params Object[] vals) {
      return Vx_core.vx_copy(
       e_testdescribe,
       vals);
    }

    public override Vx_test.Type_testdescribe vx_copy(params Object[] vals) {
      Type_testdescribe output = this;
      bool ischanged = false;
      Class_testdescribe val = this;
      Vx_core.Type_msgblock msgblock = Vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx_core.vx_Type_const) {
        ischanged = true;
      }
      Vx_core.Type_string vx_p_describename = val.describename();
      Vx_core.Type_string vx_p_testpkg = val.testpkg();
      Vx_test.Type_testresult vx_p_testresult = val.testresult();
      List<string> validkeys = new List<string>();
      validkeys.Add(":describename");
      validkeys.Add(":testpkg");
      validkeys.Add(":testresult");
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
            msg = Vx_core.vx_msg_from_error("vx/test/testdescribe", ":invalidkeytype", msgval);
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
              msg = Vx_core.vx_msg_from_error("vx/test/testdescribe", ":invalidkey", msgval);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":describename":
            if (valsub == vx_p_describename) {
            } else if (valsub is Vx_core.Type_string) {
              ischanged = true;
              vx_p_describename = (Vx_core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_describename = Vx_core.vx_new(Vx_core.t_string, valsub);
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("describename"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testdescribe", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":testpkg":
            if (valsub == vx_p_testpkg) {
            } else if (valsub is Vx_core.Type_string) {
              ischanged = true;
              vx_p_testpkg = (Vx_core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_testpkg = Vx_core.vx_new(Vx_core.t_string, valsub);
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("testpkg"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testdescribe", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":testresult":
            if (valsub == vx_p_testresult) {
            } else if (valsub is Vx_test.Type_testresult) {
              ischanged = true;
              vx_p_testresult = (Vx_test.Type_testresult)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("testresult"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testdescribe", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx_core.vx_new_string(key);
            msg = Vx_core.vx_msg_from_error("vx/test/testdescribe", ":invalidkey", msgval);
            msgblock = Vx_core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx_core.e_msgblock)) {
        Class_testdescribe work = new Class_testdescribe();
        work.vx_p_describename = vx_p_describename;
        work.vx_p_testpkg = vx_p_testpkg;
        work.vx_p_testresult = vx_p_testresult;
        if (msgblock != Vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx_core.Type_any vx_empty() {
      return e_testdescribe;
    }
    public override Vx_core.Type_any vx_type() {
      return t_testdescribe;
    }

    public override Vx_core.Type_typedef vx_typedef() {
      return Vx_core.typedef_new(
        "vx/test", // pkgname
        "testdescribe", // name
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

  public static Type_testdescribe e_testdescribe = new Class_testdescribe();
  public static Type_testdescribe t_testdescribe = new Class_testdescribe();

  /**
   * type: testdescribelist
   * List of testdescribe
   * (type testdescribelist)
   */
  public interface Type_testdescribelist : Vx_core.Type_list {
    public Vx_core.Type_any vx_new(params Object[] vals);
    public Vx_core.Type_any vx_copy(params Object[] vals);
    public Vx_core.Type_any vx_empty();
    public Vx_core.Type_any vx_type();
    public List<Vx_test.Type_testdescribe> vx_listtestdescribe();
    public Vx_test.Type_testdescribe vx_testdescribe(Vx_core.Type_int index);
  }

  public class Class_testdescribelist : Vx_core.Class_base, Type_testdescribelist {

    public List<Vx_test.Type_testdescribe> vx_p_list = Vx_core.immutablelist(new List<Vx_test.Type_testdescribe>());

    public List<Vx_core.Type_any> vx_list() {
      List<Vx_core.Type_any> output = Vx_core.immutablelist(
        new List<Vx_core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx_test.Type_testdescribe vx_testdescribe(Vx_core.Type_int index) {
      Vx_test.Type_testdescribe output = Vx_test.e_testdescribe;
      Vx_test.Class_testdescribelist list = this;
      int iindex = index.vx_int();
      List<Vx_test.Type_testdescribe> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx_test.Type_testdescribe> vx_listtestdescribe() {
      return vx_p_list;
    }

    public Vx_core.Type_any vx_any(Vx_core.Type_int index) {
      return this.vx_testdescribe(index);
    }

    public override Vx_test.Type_testdescribelist vx_new(params Object[] vals) {
      return Vx_core.vx_copy(
       e_testdescribelist,
       vals);
    }

    public override Vx_test.Type_testdescribelist vx_copy(params Object[] vals) {
      Type_testdescribelist output = this;
      bool ischanged = false;
      Class_testdescribelist val = this;
      Vx_core.Type_msgblock msgblock = Vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx_core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx_test.Type_testdescribe> listval = new List<Vx_test.Type_testdescribe>(val.vx_listtestdescribe());
      Vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx_core.Type_msgblock) {
          msgblock = Vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx_core.Type_msg) {
          msgblock = Vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx_test.Type_testdescribe) {
          Vx_test.Type_testdescribe anysub = valsub as Vx_test.Type_testdescribe;
          ischanged = true;
          listval.Add(anysub);
        } else if (valsub is Vx_test.Type_testdescribe) {
          ischanged = true;
          listval.Add((Vx_test.Type_testdescribe)valsub);
        } else if (valsub is Vx_test.Type_testdescribelist) {
          Type_testdescribelist multi = (Type_testdescribelist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_listtestdescribe());
        } else if (valsub is List<object>) {
          List<object> listunknown = valsub as List<object>;
          foreach (Object item in listunknown) {
            if (item is Vx_test.Type_testdescribe) {
              Vx_test.Type_testdescribe valitem = (Vx_test.Type_testdescribe)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx_core.Type_any) {
          Vx_core.Type_any anysub = valsub as Vx_core.Type_any;
          msg = Vx_core.vx_msg_from_error("vx/test/testdescribelist", ":invalidtype", anysub);
          msgblock = Vx_core.vx_copy(msgblock, msg);
        } else {
          msg = Vx_core.vx_msg_from_error("vx/test/testdescribelist", ":invalidtype", Vx_core.vx_new_string(valsub.ToString()));
          msgblock = Vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx_core.e_msgblock)) {
        Class_testdescribelist work = new Class_testdescribelist();
        work.vx_p_list = Vx_core.immutablelist(listval);
        if (msgblock != Vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx_core.Type_any vx_empty() {
      return e_testdescribelist;
    }
    public override Vx_core.Type_any vx_type() {
      return t_testdescribelist;
    }

    public override Vx_core.Type_typedef vx_typedef() {
      return Vx_core.typedef_new(
        "vx/test", // pkgname
        "testdescribelist", // name
        ":list", // extends
        Vx_core.e_typelist, // traits
        Vx_core.vx_new(Vx_core.t_typelist, Vx_test.t_testdescribe), // allowtypes
        Vx_core.e_typelist, // disallowtypes
        Vx_core.e_funclist, // allowfuncs
        Vx_core.e_funclist, // disallowfuncs
        Vx_core.e_anylist, // allowvalues
        Vx_core.e_anylist, // disallowvalues
        Vx_core.e_argmap // properties
      );
    }

  }

  public static Type_testdescribelist e_testdescribelist = new Class_testdescribelist();
  public static Type_testdescribelist t_testdescribelist = new Class_testdescribelist();

  /**
   * type: testpackage
   * Structure to hold all tests for a package
   * (type testpackage)
   */
  public interface Type_testpackage : Vx_core.Type_struct {
    public Vx_core.Type_any vx_new(params Object[] vals);
    public Vx_core.Type_any vx_copy(params Object[] vals);
    public Vx_core.Type_any vx_empty();
    public Vx_core.Type_any vx_type();
    public Vx_test.Type_testcaselist caselist();
    public Vx_test.Type_testcoveragedetail coveragedetail();
    public Vx_test.Type_testcoveragesummary coveragesummary();
    public Vx_core.Type_boolean passfail();
    public Vx_core.Type_string testpkg();
  }

  public class Class_testpackage : Vx_core.Class_base, Type_testpackage {

    public Vx_test.Type_testcaselist vx_p_caselist;

    public Vx_test.Type_testcaselist caselist() {
      Vx_test.Type_testcaselist output = Vx_test.e_testcaselist;
      if (this.vx_p_caselist != null) {
        output = this.vx_p_caselist;
      }
      return output;
    }

    public Vx_test.Type_testcoveragedetail vx_p_coveragedetail;

    public Vx_test.Type_testcoveragedetail coveragedetail() {
      Vx_test.Type_testcoveragedetail output = Vx_test.e_testcoveragedetail;
      if (this.vx_p_coveragedetail != null) {
        output = this.vx_p_coveragedetail;
      }
      return output;
    }

    public Vx_test.Type_testcoveragesummary vx_p_coveragesummary;

    public Vx_test.Type_testcoveragesummary coveragesummary() {
      Vx_test.Type_testcoveragesummary output = Vx_test.e_testcoveragesummary;
      if (this.vx_p_coveragesummary != null) {
        output = this.vx_p_coveragesummary;
      }
      return output;
    }

    public Vx_core.Type_boolean vx_p_passfail;

    public Vx_core.Type_boolean passfail() {
      Vx_core.Type_boolean output = Vx_core.e_boolean;
      if (this.vx_p_passfail != null) {
        output = this.vx_p_passfail;
      }
      return output;
    }

    public Vx_core.Type_string vx_p_testpkg;

    public Vx_core.Type_string testpkg() {
      Vx_core.Type_string output = Vx_core.e_string;
      if (this.vx_p_testpkg != null) {
        output = this.vx_p_testpkg;
      }
      return output;
    }

    public Vx_core.Type_any vx_any(Vx_core.Type_string key) {
      Vx_core.Type_any output = Vx_core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":caselist":
        output = this.caselist();
        break;
      case ":coveragedetail":
        output = this.coveragedetail();
        break;
      case ":coveragesummary":
        output = this.coveragesummary();
        break;
      case ":passfail":
        output = this.passfail();
        break;
      case ":testpkg":
        output = this.testpkg();
        break;
      }
      return output;
    }

    public Vx_core.Map<string, Vx_core.Type_any> vx_map() {
      Vx_core.Map<string, Vx_core.Type_any> output = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
      output.put(":caselist", this.caselist());
      output.put(":coveragedetail", this.coveragedetail());
      output.put(":coveragesummary", this.coveragesummary());
      output.put(":passfail", this.passfail());
      output.put(":testpkg", this.testpkg());
      return Vx_core.immutablemap(output);
    }

    public override Vx_test.Type_testpackage vx_new(params Object[] vals) {
      return Vx_core.vx_copy(
       e_testpackage,
       vals);
    }

    public override Vx_test.Type_testpackage vx_copy(params Object[] vals) {
      Type_testpackage output = this;
      bool ischanged = false;
      Class_testpackage val = this;
      Vx_core.Type_msgblock msgblock = Vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx_core.vx_Type_const) {
        ischanged = true;
      }
      Vx_test.Type_testcaselist vx_p_caselist = val.caselist();
      Vx_test.Type_testcoveragedetail vx_p_coveragedetail = val.coveragedetail();
      Vx_test.Type_testcoveragesummary vx_p_coveragesummary = val.coveragesummary();
      Vx_core.Type_boolean vx_p_passfail = val.passfail();
      Vx_core.Type_string vx_p_testpkg = val.testpkg();
      List<string> validkeys = new List<string>();
      validkeys.Add(":caselist");
      validkeys.Add(":coveragedetail");
      validkeys.Add(":coveragesummary");
      validkeys.Add(":passfail");
      validkeys.Add(":testpkg");
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
            msg = Vx_core.vx_msg_from_error("vx/test/testpackage", ":invalidkeytype", msgval);
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
              msg = Vx_core.vx_msg_from_error("vx/test/testpackage", ":invalidkey", msgval);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":caselist":
            if (valsub == vx_p_caselist) {
            } else if (valsub is Vx_test.Type_testcaselist) {
              ischanged = true;
              vx_p_caselist = (Vx_test.Type_testcaselist)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("caselist"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testpackage", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":coveragedetail":
            if (valsub == vx_p_coveragedetail) {
            } else if (valsub is Vx_test.Type_testcoveragedetail) {
              ischanged = true;
              vx_p_coveragedetail = (Vx_test.Type_testcoveragedetail)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("coveragedetail"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testpackage", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":coveragesummary":
            if (valsub == vx_p_coveragesummary) {
            } else if (valsub is Vx_test.Type_testcoveragesummary) {
              ischanged = true;
              vx_p_coveragesummary = (Vx_test.Type_testcoveragesummary)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("coveragesummary"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testpackage", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":passfail":
            if (valsub == vx_p_passfail) {
            } else if (valsub is Vx_core.Type_boolean) {
              ischanged = true;
              vx_p_passfail = (Vx_core.Type_boolean)valsub;
            } else if (valsub is bool) {
              ischanged = true;
              vx_p_passfail = Vx_core.vx_new(Vx_core.t_boolean, valsub);
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("passfail"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testpackage", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":testpkg":
            if (valsub == vx_p_testpkg) {
            } else if (valsub is Vx_core.Type_string) {
              ischanged = true;
              vx_p_testpkg = (Vx_core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_testpkg = Vx_core.vx_new(Vx_core.t_string, valsub);
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("testpkg"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testpackage", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx_core.vx_new_string(key);
            msg = Vx_core.vx_msg_from_error("vx/test/testpackage", ":invalidkey", msgval);
            msgblock = Vx_core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx_core.e_msgblock)) {
        Class_testpackage work = new Class_testpackage();
        work.vx_p_caselist = vx_p_caselist;
        work.vx_p_coveragedetail = vx_p_coveragedetail;
        work.vx_p_coveragesummary = vx_p_coveragesummary;
        work.vx_p_passfail = vx_p_passfail;
        work.vx_p_testpkg = vx_p_testpkg;
        if (msgblock != Vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx_core.Type_any vx_empty() {
      return e_testpackage;
    }
    public override Vx_core.Type_any vx_type() {
      return t_testpackage;
    }

    public override Vx_core.Type_typedef vx_typedef() {
      return Vx_core.typedef_new(
        "vx/test", // pkgname
        "testpackage", // name
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

  public static Type_testpackage e_testpackage = new Class_testpackage();
  public static Type_testpackage t_testpackage = new Class_testpackage();

  /**
   * type: testpackagelist
   * List of testpackage
   * (type testpackagelist)
   */
  public interface Type_testpackagelist : Vx_core.Type_list {
    public Vx_core.Type_any vx_new(params Object[] vals);
    public Vx_core.Type_any vx_copy(params Object[] vals);
    public Vx_core.Type_any vx_empty();
    public Vx_core.Type_any vx_type();
    public List<Vx_test.Type_testpackage> vx_listtestpackage();
    public Vx_test.Type_testpackage vx_testpackage(Vx_core.Type_int index);
  }

  public class Class_testpackagelist : Vx_core.Class_base, Type_testpackagelist {

    public List<Vx_test.Type_testpackage> vx_p_list = Vx_core.immutablelist(new List<Vx_test.Type_testpackage>());

    public List<Vx_core.Type_any> vx_list() {
      List<Vx_core.Type_any> output = Vx_core.immutablelist(
        new List<Vx_core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx_test.Type_testpackage vx_testpackage(Vx_core.Type_int index) {
      Vx_test.Type_testpackage output = Vx_test.e_testpackage;
      Vx_test.Class_testpackagelist list = this;
      int iindex = index.vx_int();
      List<Vx_test.Type_testpackage> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx_test.Type_testpackage> vx_listtestpackage() {
      return vx_p_list;
    }

    public Vx_core.Type_any vx_any(Vx_core.Type_int index) {
      return this.vx_testpackage(index);
    }

    public override Vx_test.Type_testpackagelist vx_new(params Object[] vals) {
      return Vx_core.vx_copy(
       e_testpackagelist,
       vals);
    }

    public override Vx_test.Type_testpackagelist vx_copy(params Object[] vals) {
      Type_testpackagelist output = this;
      bool ischanged = false;
      Class_testpackagelist val = this;
      Vx_core.Type_msgblock msgblock = Vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx_core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx_test.Type_testpackage> listval = new List<Vx_test.Type_testpackage>(val.vx_listtestpackage());
      Vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx_core.Type_msgblock) {
          msgblock = Vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx_core.Type_msg) {
          msgblock = Vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx_test.Type_testpackage) {
          Vx_test.Type_testpackage anysub = valsub as Vx_test.Type_testpackage;
          ischanged = true;
          listval.Add(anysub);
        } else if (valsub is Vx_test.Type_testpackage) {
          ischanged = true;
          listval.Add((Vx_test.Type_testpackage)valsub);
        } else if (valsub is Vx_test.Type_testpackagelist) {
          Type_testpackagelist multi = (Type_testpackagelist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_listtestpackage());
        } else if (valsub is List<object>) {
          List<object> listunknown = valsub as List<object>;
          foreach (Object item in listunknown) {
            if (item is Vx_test.Type_testpackage) {
              Vx_test.Type_testpackage valitem = (Vx_test.Type_testpackage)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx_core.Type_any) {
          Vx_core.Type_any anysub = valsub as Vx_core.Type_any;
          msg = Vx_core.vx_msg_from_error("vx/test/testpackagelist", ":invalidtype", anysub);
          msgblock = Vx_core.vx_copy(msgblock, msg);
        } else {
          msg = Vx_core.vx_msg_from_error("vx/test/testpackagelist", ":invalidtype", Vx_core.vx_new_string(valsub.ToString()));
          msgblock = Vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx_core.e_msgblock)) {
        Class_testpackagelist work = new Class_testpackagelist();
        work.vx_p_list = Vx_core.immutablelist(listval);
        if (msgblock != Vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx_core.Type_any vx_empty() {
      return e_testpackagelist;
    }
    public override Vx_core.Type_any vx_type() {
      return t_testpackagelist;
    }

    public override Vx_core.Type_typedef vx_typedef() {
      return Vx_core.typedef_new(
        "vx/test", // pkgname
        "testpackagelist", // name
        ":list", // extends
        Vx_core.e_typelist, // traits
        Vx_core.vx_new(Vx_core.t_typelist, Vx_test.t_testpackage), // allowtypes
        Vx_core.e_typelist, // disallowtypes
        Vx_core.e_funclist, // allowfuncs
        Vx_core.e_funclist, // disallowfuncs
        Vx_core.e_anylist, // allowvalues
        Vx_core.e_anylist, // disallowvalues
        Vx_core.e_argmap // properties
      );
    }

  }

  public static Type_testpackagelist e_testpackagelist = new Class_testpackagelist();
  public static Type_testpackagelist t_testpackagelist = new Class_testpackagelist();

  /**
   * type: testresult
   * Structure to hold test results
   * (type testresult)
   */
  public interface Type_testresult : Vx_core.Type_struct {
    public Vx_core.Type_any vx_new(params Object[] vals);
    public Vx_core.Type_any vx_copy(params Object[] vals);
    public Vx_core.Type_any vx_empty();
    public Vx_core.Type_any vx_type();
    public Vx_core.Type_string code();
    public Vx_core.Type_boolean passfail();
    public Vx_core.Type_any expected();
    public Vx_core.Type_any actual();
    public Vx_core.Func_any_from_func_async fn_actual();
  }

  public class Class_testresult : Vx_core.Class_base, Type_testresult {

    public Vx_core.Type_string vx_p_code;

    public Vx_core.Type_string code() {
      Vx_core.Type_string output = Vx_core.e_string;
      if (this.vx_p_code != null) {
        output = this.vx_p_code;
      }
      return output;
    }

    public Vx_core.Type_boolean vx_p_passfail;

    public Vx_core.Type_boolean passfail() {
      Vx_core.Type_boolean output = Vx_core.e_boolean;
      if (this.vx_p_passfail != null) {
        output = this.vx_p_passfail;
      }
      return output;
    }

    public Vx_core.Type_any vx_p_expected;

    public Vx_core.Type_any expected() {
      Vx_core.Type_any output = Vx_core.e_any;
      if (this.vx_p_expected != null) {
        output = this.vx_p_expected;
      }
      return output;
    }

    public Vx_core.Type_any vx_p_actual;

    public Vx_core.Type_any actual() {
      Vx_core.Type_any output = Vx_core.e_any;
      if (this.vx_p_actual != null) {
        output = this.vx_p_actual;
      }
      return output;
    }

    public Vx_core.Func_any_from_func_async vx_p_fn_actual;

    public Vx_core.Func_any_from_func_async fn_actual() {
      Vx_core.Func_any_from_func_async output = Vx_core.e_any_from_func_async;
      if (this.vx_p_fn_actual != null) {
        output = this.vx_p_fn_actual;
      }
      return output;
    }

    public Vx_core.Type_any vx_any(Vx_core.Type_string key) {
      Vx_core.Type_any output = Vx_core.e_any;
      string skey = key.vx_string();
      switch (skey) {
      case ":code":
        output = this.code();
        break;
      case ":passfail":
        output = this.passfail();
        break;
      case ":expected":
        output = this.expected();
        break;
      case ":actual":
        output = this.actual();
        break;
      case ":fn-actual":
        output = this.fn_actual();
        break;
      }
      return output;
    }

    public Vx_core.Map<string, Vx_core.Type_any> vx_map() {
      Vx_core.Map<string, Vx_core.Type_any> output = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
      output.put(":code", this.code());
      output.put(":passfail", this.passfail());
      output.put(":expected", this.expected());
      output.put(":actual", this.actual());
      output.put(":fn-actual", this.fn_actual());
      return Vx_core.immutablemap(output);
    }

    public override Vx_test.Type_testresult vx_new(params Object[] vals) {
      return Vx_core.vx_copy(
       e_testresult,
       vals);
    }

    public override Vx_test.Type_testresult vx_copy(params Object[] vals) {
      Type_testresult output = this;
      bool ischanged = false;
      Class_testresult val = this;
      Vx_core.Type_msgblock msgblock = Vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx_core.vx_Type_const) {
        ischanged = true;
      }
      Vx_core.Type_string vx_p_code = val.code();
      Vx_core.Type_boolean vx_p_passfail = val.passfail();
      Vx_core.Type_any vx_p_expected = val.expected();
      Vx_core.Type_any vx_p_actual = val.actual();
      Vx_core.Func_any_from_func_async vx_p_fn_actual = val.fn_actual();
      List<string> validkeys = new List<string>();
      validkeys.Add(":code");
      validkeys.Add(":passfail");
      validkeys.Add(":expected");
      validkeys.Add(":actual");
      validkeys.Add(":fn-actual");
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
            msg = Vx_core.vx_msg_from_error("vx/test/testresult", ":invalidkeytype", msgval);
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
              msg = Vx_core.vx_msg_from_error("vx/test/testresult", ":invalidkey", msgval);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":code":
            if (valsub == vx_p_code) {
            } else if (valsub is Vx_core.Type_string) {
              ischanged = true;
              vx_p_code = (Vx_core.Type_string)valsub;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_code = Vx_core.vx_new(Vx_core.t_string, valsub);
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("code"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testresult", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":passfail":
            if (valsub == vx_p_passfail) {
            } else if (valsub is Vx_core.Type_boolean) {
              ischanged = true;
              vx_p_passfail = (Vx_core.Type_boolean)valsub;
            } else if (valsub is bool) {
              ischanged = true;
              vx_p_passfail = Vx_core.vx_new(Vx_core.t_boolean, valsub);
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("passfail"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testresult", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":expected":
            if (valsub == vx_p_expected) {
            } else if (valsub is Vx_core.Type_any) {
              ischanged = true;
              vx_p_expected = (Vx_core.Type_any)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("expected"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testresult", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":actual":
            if (valsub == vx_p_actual) {
            } else if (valsub is Vx_core.Type_any) {
              ischanged = true;
              vx_p_actual = (Vx_core.Type_any)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("actual"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testresult", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          case ":fn-actual":
            if (valsub == vx_p_fn_actual) {
            } else if (valsub is Vx_core.Func_any_from_func_async) {
              ischanged = true;
              vx_p_fn_actual = (Vx_core.Func_any_from_func_async)valsub;
            } else {
              if (valsub is Vx_core.Type_any) {
                msgval = (Vx_core.Type_any)valsub;
              } else {
                msgval = Vx_core.vx_new_string(valsub.ToString());
              }
              Vx_core.Map<string, Vx_core.Type_any> mapany = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
              mapany.put("key", Vx_core.vx_new_string("fn-actual"));
              mapany.put("value", msgval);
              Vx_core.Type_map msgmap = Vx_core.t_anymap.vx_new_from_map(mapany);
              msg = Vx_core.vx_msg_from_error("vx/test/testresult", ":invalidvalue", msgmap);
              msgblock = Vx_core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx_core.vx_new_string(key);
            msg = Vx_core.vx_msg_from_error("vx/test/testresult", ":invalidkey", msgval);
            msgblock = Vx_core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx_core.e_msgblock)) {
        Class_testresult work = new Class_testresult();
        work.vx_p_code = vx_p_code;
        work.vx_p_passfail = vx_p_passfail;
        work.vx_p_expected = vx_p_expected;
        work.vx_p_actual = vx_p_actual;
        work.vx_p_fn_actual = vx_p_fn_actual;
        if (msgblock != Vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx_core.Type_any vx_empty() {
      return e_testresult;
    }
    public override Vx_core.Type_any vx_type() {
      return t_testresult;
    }

    public override Vx_core.Type_typedef vx_typedef() {
      return Vx_core.typedef_new(
        "vx/test", // pkgname
        "testresult", // name
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

  public static Type_testresult e_testresult = new Class_testresult();
  public static Type_testresult t_testresult = new Class_testresult();

  /**
   * type: testresultlist
   * List of test results
   * (type testresultlist)
   */
  public interface Type_testresultlist : Vx_core.Type_list {
    public Vx_core.Type_any vx_new(params Object[] vals);
    public Vx_core.Type_any vx_copy(params Object[] vals);
    public Vx_core.Type_any vx_empty();
    public Vx_core.Type_any vx_type();
    public List<Vx_test.Type_testresult> vx_listtestresult();
    public Vx_test.Type_testresult vx_testresult(Vx_core.Type_int index);
  }

  public class Class_testresultlist : Vx_core.Class_base, Type_testresultlist {

    public List<Vx_test.Type_testresult> vx_p_list = Vx_core.immutablelist(new List<Vx_test.Type_testresult>());

    public List<Vx_core.Type_any> vx_list() {
      List<Vx_core.Type_any> output = Vx_core.immutablelist(
        new List<Vx_core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx_test.Type_testresult vx_testresult(Vx_core.Type_int index) {
      Vx_test.Type_testresult output = Vx_test.e_testresult;
      Vx_test.Class_testresultlist list = this;
      int iindex = index.vx_int();
      List<Vx_test.Type_testresult> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx_test.Type_testresult> vx_listtestresult() {
      return vx_p_list;
    }

    public Vx_core.Type_any vx_any(Vx_core.Type_int index) {
      return this.vx_testresult(index);
    }

    public override Vx_test.Type_testresultlist vx_new(params Object[] vals) {
      return Vx_core.vx_copy(
       e_testresultlist,
       vals);
    }

    public override Vx_test.Type_testresultlist vx_copy(params Object[] vals) {
      Type_testresultlist output = this;
      bool ischanged = false;
      Class_testresultlist val = this;
      Vx_core.Type_msgblock msgblock = Vx_core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx_core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx_test.Type_testresult> listval = new List<Vx_test.Type_testresult>(val.vx_listtestresult());
      Vx_core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx_core.Type_msgblock) {
          msgblock = Vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx_core.Type_msg) {
          msgblock = Vx_core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx_test.Type_testresult) {
          Vx_test.Type_testresult anysub = valsub as Vx_test.Type_testresult;
          ischanged = true;
          listval.Add(anysub);
        } else if (valsub is Vx_test.Type_testresult) {
          ischanged = true;
          listval.Add((Vx_test.Type_testresult)valsub);
        } else if (valsub is Vx_test.Type_testresultlist) {
          Type_testresultlist multi = (Type_testresultlist)valsub;
          ischanged = true;
          listval.AddRange(multi.vx_listtestresult());
        } else if (valsub is List<object>) {
          List<object> listunknown = valsub as List<object>;
          foreach (Object item in listunknown) {
            if (item is Vx_test.Type_testresult) {
              Vx_test.Type_testresult valitem = (Vx_test.Type_testresult)item;
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx_core.Type_any) {
          Vx_core.Type_any anysub = valsub as Vx_core.Type_any;
          msg = Vx_core.vx_msg_from_error("vx/test/testresultlist", ":invalidtype", anysub);
          msgblock = Vx_core.vx_copy(msgblock, msg);
        } else {
          msg = Vx_core.vx_msg_from_error("vx/test/testresultlist", ":invalidtype", Vx_core.vx_new_string(valsub.ToString()));
          msgblock = Vx_core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx_core.e_msgblock)) {
        Class_testresultlist work = new Class_testresultlist();
        work.vx_p_list = Vx_core.immutablelist(listval);
        if (msgblock != Vx_core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx_core.Type_any vx_empty() {
      return e_testresultlist;
    }
    public override Vx_core.Type_any vx_type() {
      return t_testresultlist;
    }

    public override Vx_core.Type_typedef vx_typedef() {
      return Vx_core.typedef_new(
        "vx/test", // pkgname
        "testresultlist", // name
        ":list", // extends
        Vx_core.e_typelist, // traits
        Vx_core.vx_new(Vx_core.t_typelist, Vx_test.t_testresult), // allowtypes
        Vx_core.e_typelist, // disallowtypes
        Vx_core.e_funclist, // allowfuncs
        Vx_core.e_funclist, // disallowfuncs
        Vx_core.e_anylist, // allowvalues
        Vx_core.e_anylist, // disallowvalues
        Vx_core.e_argmap // properties
      );
    }

  }

  public static Type_testresultlist e_testresultlist = new Class_testresultlist();
  public static Type_testresultlist t_testresultlist = new Class_testresultlist();

  /**
   * Constant: stylesheet-test
   * The default Test Stylesheet
   * {stylesheet}
   */
  public class Const_stylesheet_test : Vx_web_html.Class_stylesheet, Vx_core.vx_Type_const {
    
    public Vx_core.Type_constdef vx_constdef() {
      return Vx_core.constdef_new(
        "vx/test", // pkgname
        "stylesheet-test", // name
        Vx_core.typedef_new(
          "vx/web/html", // pkgname
          "stylesheet", // name
          ":struct", // extends
          Vx_core.vx_new(Vx_core.t_typelist, Vx_web_html.t_node, Vx_web_html.t_headchild), // traits
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

    public static void const_new(Const_stylesheet_test output) {
      Vx_web_html.Type_stylesheet val = Vx_web_html.f_stylesheet_loadmap(
        Vx_core.f_new(
          Vx_web_html.t_stylesheet,
          Vx_core.vx_new(Vx_core.t_anylist,
            Vx_core.vx_new_string(":name"),
            Vx_core.vx_new_string("Test Suite"),
            Vx_core.vx_new_string(":styles"),
            Vx_core.f_new(
              Vx_web_html.t_stylelist,
              Vx_core.vx_new(Vx_core.t_anylist,
                Vx_core.f_new(
                  Vx_web_html.t_style,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":name"),
                    Vx_core.vx_new_string("body"),
                    Vx_core.vx_new_string(":props"),
                    Vx_core.f_new(
                      Vx_web_html.t_propmap,
                      Vx_core.vx_new(Vx_core.t_anylist,
                        Vx_core.vx_new_string("font-size"),
                        Vx_core.vx_new_string("0.9em"),
                        Vx_core.vx_new_string("font-family"),
                        Vx_core.vx_new_string("sans-serif")
                      )
                    )
                  )
                ),
                Vx_core.f_new(
                  Vx_web_html.t_style,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":name"),
                    Vx_core.vx_new_string("details summary"),
                    Vx_core.vx_new_string(":props"),
                    Vx_core.f_new(
                      Vx_web_html.t_propmap,
                      Vx_core.vx_new(Vx_core.t_anylist,
                        Vx_core.vx_new_string("cursor"),
                        Vx_core.vx_new_string("pointer"),
                        Vx_core.vx_new_string("display"),
                        Vx_core.vx_new_string("inline-flex"),
                        Vx_core.vx_new_string("gap"),
                        Vx_core.vx_new_string("10px")
                      )
                    )
                  )
                ),
                Vx_core.f_new(
                  Vx_web_html.t_style,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":name"),
                    Vx_core.vx_new_string("table"),
                    Vx_core.vx_new_string(":props"),
                    Vx_core.f_new(
                      Vx_web_html.t_propmap,
                      Vx_core.vx_new(Vx_core.t_anylist,
                        Vx_core.vx_new_string("vertical-align"),
                        Vx_core.vx_new_string("top"),
                        Vx_core.vx_new_string("border-collapse"),
                        Vx_core.vx_new_string("collapse"),
                        Vx_core.vx_new_string("margin"),
                        Vx_core.vx_new_string("25px 0"),
                        Vx_core.vx_new_string("min-width"),
                        Vx_core.vx_new_string("400px"),
                        Vx_core.vx_new_string("box-shadow"),
                        Vx_core.vx_new_string("0 0 20px rgba(0, 0, 0, 0.15)")
                      )
                    )
                  )
                ),
                Vx_core.f_new(
                  Vx_web_html.t_style,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":name"),
                    Vx_core.vx_new_string("thead tr"),
                    Vx_core.vx_new_string(":props"),
                    Vx_core.f_new(
                      Vx_web_html.t_propmap,
                      Vx_core.vx_new(Vx_core.t_anylist,
                        Vx_core.vx_new_string("background-color"),
                        Vx_core.vx_new_string("#009879"),
                        Vx_core.vx_new_string("color"),
                        Vx_core.vx_new_string("#ffffff"),
                        Vx_core.vx_new_string("text-align"),
                        Vx_core.vx_new_string("left")
                      )
                    )
                  )
                ),
                Vx_core.f_new(
                  Vx_web_html.t_style,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":name"),
                    Vx_core.vx_new_string("td"),
                    Vx_core.vx_new_string(":props"),
                    Vx_core.f_new(
                      Vx_web_html.t_propmap,
                      Vx_core.vx_new(Vx_core.t_anylist,
                        Vx_core.vx_new_string("padding"),
                        Vx_core.vx_new_string("10px 10px"),
                        Vx_core.vx_new_string("vertical-align"),
                        Vx_core.vx_new_string("top")
                      )
                    )
                  )
                ),
                Vx_core.f_new(
                  Vx_web_html.t_style,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":name"),
                    Vx_core.vx_new_string("tbody tr"),
                    Vx_core.vx_new_string(":props"),
                    Vx_core.f_new(
                      Vx_web_html.t_propmap,
                      Vx_core.vx_new(Vx_core.t_anylist,
                        Vx_core.vx_new_string("border-bottom"),
                        Vx_core.vx_new_string("1px solid #dddddd")
                      )
                    )
                  )
                ),
                Vx_core.f_new(
                  Vx_web_html.t_style,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":name"),
                    Vx_core.vx_new_string("tbody tr:nth-of-type(even)"),
                    Vx_core.vx_new_string(":props"),
                    Vx_core.f_new(
                      Vx_web_html.t_propmap,
                      Vx_core.vx_new(Vx_core.t_anylist,
                        Vx_core.vx_new_string("background-color"),
                        Vx_core.vx_new_string("#f3f3f3")
                      )
                    )
                  )
                ),
                Vx_core.f_new(
                  Vx_web_html.t_style,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":name"),
                    Vx_core.vx_new_string("tbody tr:last-of-type"),
                    Vx_core.vx_new_string(":props"),
                    Vx_core.f_new(
                      Vx_web_html.t_propmap,
                      Vx_core.vx_new(Vx_core.t_anylist,
                        Vx_core.vx_new_string("border-bottom"),
                        Vx_core.vx_new_string("2px solid #009879")
                      )
                    )
                  )
                ),
                Vx_core.f_new(
                  Vx_web_html.t_style,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":name"),
                    Vx_core.vx_new_string("tbody tr.active-row"),
                    Vx_core.vx_new_string(":props"),
                    Vx_core.f_new(
                      Vx_web_html.t_propmap,
                      Vx_core.vx_new(Vx_core.t_anylist,
                        Vx_core.vx_new_string("font-weight"),
                        Vx_core.vx_new_string("bold"),
                        Vx_core.vx_new_string("color"),
                        Vx_core.vx_new_string("#009879")
                      )
                    )
                  )
                ),
                Vx_core.f_new(
                  Vx_web_html.t_style,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":name"),
                    Vx_core.vx_new_string(".failflag"),
                    Vx_core.vx_new_string(":props"),
                    Vx_core.f_new(
                      Vx_web_html.t_propmap,
                      Vx_core.vx_new(Vx_core.t_anylist,
                        Vx_core.vx_new_string("background-color"),
                        Vx_core.vx_new_string("red"),
                        Vx_core.vx_new_string("color"),
                        Vx_core.vx_new_string("white"),
                        Vx_core.vx_new_string("padding-left"),
                        Vx_core.vx_new_string("4px"),
                        Vx_core.vx_new_string("padding-right"),
                        Vx_core.vx_new_string("4px"),
                        Vx_core.vx_new_string("padding-top"),
                        Vx_core.vx_new_string("1px"),
                        Vx_core.vx_new_string("padding-bottom"),
                        Vx_core.vx_new_string("1px")
                      )
                    )
                  )
                ),
                Vx_core.f_new(
                  Vx_web_html.t_style,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":name"),
                    Vx_core.vx_new_string(".passflag"),
                    Vx_core.vx_new_string(":props"),
                    Vx_core.f_new(
                      Vx_web_html.t_propmap,
                      Vx_core.vx_new(Vx_core.t_anylist,
                        Vx_core.vx_new_string("background-color"),
                        Vx_core.vx_new_string("green"),
                        Vx_core.vx_new_string("color"),
                        Vx_core.vx_new_string("white"),
                        Vx_core.vx_new_string("padding-left"),
                        Vx_core.vx_new_string("4px"),
                        Vx_core.vx_new_string("padding-right"),
                        Vx_core.vx_new_string("4px"),
                        Vx_core.vx_new_string("padding-top"),
                        Vx_core.vx_new_string("1px"),
                        Vx_core.vx_new_string("padding-bottom"),
                        Vx_core.vx_new_string("1px")
                      )
                    )
                  )
                ),
                Vx_core.f_new(
                  Vx_web_html.t_style,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":name"),
                    Vx_core.vx_new_string(".coveragenums"),
                    Vx_core.vx_new_string(":props"),
                    Vx_core.f_new(
                      Vx_web_html.t_propmap,
                      Vx_core.vx_new(Vx_core.t_anylist,
                        Vx_core.vx_new_string("width"),
                        Vx_core.vx_new_string("90px")
                      )
                    )
                  )
                ),
                Vx_core.f_new(
                  Vx_web_html.t_style,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":name"),
                    Vx_core.vx_new_string(".coveragepct"),
                    Vx_core.vx_new_string(":props"),
                    Vx_core.f_new(
                      Vx_web_html.t_propmap,
                      Vx_core.vx_new(Vx_core.t_anylist,
                        Vx_core.vx_new_string("text-align"),
                        Vx_core.vx_new_string("right")
                      )
                    )
                  )
                ),
                Vx_core.f_new(
                  Vx_web_html.t_style,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":name"),
                    Vx_core.vx_new_string(".coveragepctgreen"),
                    Vx_core.vx_new_string(":props"),
                    Vx_core.f_new(
                      Vx_web_html.t_propmap,
                      Vx_core.vx_new(Vx_core.t_anylist,
                        Vx_core.vx_new_string("background-color"),
                        Vx_core.vx_new_string("green"),
                        Vx_core.vx_new_string("color"),
                        Vx_core.vx_new_string("white"),
                        Vx_core.vx_new_string("text-align"),
                        Vx_core.vx_new_string("right")
                      )
                    )
                  )
                ),
                Vx_core.f_new(
                  Vx_web_html.t_style,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":name"),
                    Vx_core.vx_new_string(".coveragepctred"),
                    Vx_core.vx_new_string(":props"),
                    Vx_core.f_new(
                      Vx_web_html.t_propmap,
                      Vx_core.vx_new(Vx_core.t_anylist,
                        Vx_core.vx_new_string("background-color"),
                        Vx_core.vx_new_string("red"),
                        Vx_core.vx_new_string("color"),
                        Vx_core.vx_new_string("white"),
                        Vx_core.vx_new_string("text-align"),
                        Vx_core.vx_new_string("right")
                      )
                    )
                  )
                ),
                Vx_core.f_new(
                  Vx_web_html.t_style,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":name"),
                    Vx_core.vx_new_string(".pkgheader"),
                    Vx_core.vx_new_string(":props"),
                    Vx_core.f_new(
                      Vx_web_html.t_propmap,
                      Vx_core.vx_new(Vx_core.t_anylist,
                        Vx_core.vx_new_string("display"),
                        Vx_core.vx_new_string("inline-flex"),
                        Vx_core.vx_new_string("gap"),
                        Vx_core.vx_new_string("10px")
                      )
                    )
                  )
                ),
                Vx_core.f_new(
                  Vx_web_html.t_style,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":name"),
                    Vx_core.vx_new_string(".pkgname"),
                    Vx_core.vx_new_string(":props"),
                    Vx_core.f_new(
                      Vx_web_html.t_propmap,
                      Vx_core.vx_new(Vx_core.t_anylist,
                        Vx_core.vx_new_string("font-weight"),
                        Vx_core.vx_new_string("bold"),
                        Vx_core.vx_new_string("width"),
                        Vx_core.vx_new_string("180px")
                      )
                    )
                  )
                ),
                Vx_core.f_new(
                  Vx_web_html.t_style,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":name"),
                    Vx_core.vx_new_string(".preformatted"),
                    Vx_core.vx_new_string(":props"),
                    Vx_core.f_new(
                      Vx_web_html.t_propmap,
                      Vx_core.vx_new(Vx_core.t_anylist,
                        Vx_core.vx_new_string("display"),
                        Vx_core.vx_new_string("block"),
                        Vx_core.vx_new_string("unicode-bidi"),
                        Vx_core.vx_new_string("embed"),
                        Vx_core.vx_new_string("font-family"),
                        Vx_core.vx_new_string("monospace"),
                        Vx_core.vx_new_string("white-space"),
                        Vx_core.vx_new_string("pre")
                      )
                    )
                  )
                )
              )
            )
          )
        )
      );
      output.vx_p_id = val.id();
      output.vx_p_eventmap = val.eventmap();
      output.vx_p_style = val.style();
      output.vx_p_style_unique = val.style_unique();
      output.vx_p_stylelist = val.stylelist();
      output.vx_p_name = val.name();
      output.vx_p_styles = val.styles();
      output.vx_p_stylemap = val.stylemap();
    }


  }

  public static Const_stylesheet_test c_stylesheet_test = new Const_stylesheet_test();

  /**
   * @function context_test
   * Returns the default context for test case execution. Arguments come from the command line.
   * @param  {anylist} args
   * @return {context}
   * (func context-test)
   */
  public interface Func_context_test : Vx_core.Func_any_from_any {
    public Vx_core.Type_context vx_context_test(Vx_core.Type_anylist args);
  }

  public class Class_context_test : Vx_core.Class_base, Func_context_test {

    public override Vx_test.Func_context_test vx_new(params Object[] vals) {
      Class_context_test output = new Class_context_test();
      return output;
    }

    public override Vx_test.Func_context_test vx_copy(params Object[] vals) {
      Class_context_test output = new Class_context_test();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "context-test", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "context", // name
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
      return e_context_test;
    }

    public override Vx_core.Type_any vx_type() {
      return t_context_test;
    }

    public Vx_core.Func_any_from_any vx_fn_new(Vx_core.Class_any_from_any.IFn fn) {
      return Vx_core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_core.Type_anylist inputval = (Vx_core.Type_anylist)value;
      Vx_core.Type_any outputval = Vx_test.f_context_test(inputval);
      output = Vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_anylist args = Vx_core.f_any_from_any(Vx_core.t_anylist, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_test.f_context_test(args);
      return output;
    }

    public Vx_core.Type_context vx_context_test(Vx_core.Type_anylist args) {
      return Vx_test.f_context_test(args);
    }

  }

  public static Func_context_test e_context_test = new Vx_test.Class_context_test();
  public static Func_context_test t_context_test = new Vx_test.Class_context_test();

  public static Vx_core.Type_context f_context_test(Vx_core.Type_anylist args) {
    Vx_core.Type_context output = Vx_core.e_context;
    output = Vx_core.f_new(
      Vx_core.t_context,
      Vx_core.vx_new(Vx_core.t_anylist,
        Vx_core.vx_new_string(":session"),
        Vx_core.f_new(
          Vx_core.t_session,
          Vx_core.vx_new(Vx_core.t_anylist,
            Vx_core.vx_new_string(":user"),
            Vx_core.f_new(
              Vx_core.t_user,
              Vx_core.vx_new(Vx_core.t_anylist,
                Vx_core.vx_new_string(":security"),
                Vx_test.f_security_test()
              )
            )
          )
        )
      )
    );
    return output;
  }

  /**
   * @function div_from_testcaselist
   * @param  {testcaselist} testcaselist
   * @return {div}
   * (func div<-testcaselist)
   */
  public interface Func_div_from_testcaselist : Vx_core.Func_any_from_any {
    public Vx_web_html.Type_div vx_div_from_testcaselist(Vx_test.Type_testcaselist testcaselist);
  }

  public class Class_div_from_testcaselist : Vx_core.Class_base, Func_div_from_testcaselist {

    public override Vx_test.Func_div_from_testcaselist vx_new(params Object[] vals) {
      Class_div_from_testcaselist output = new Class_div_from_testcaselist();
      return output;
    }

    public override Vx_test.Func_div_from_testcaselist vx_copy(params Object[] vals) {
      Class_div_from_testcaselist output = new Class_div_from_testcaselist();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "div<-testcaselist", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/web/html", // pkgname
          "div", // name
          ":struct", // extends
          Vx_core.vx_new(Vx_core.t_typelist, Vx_web_html.t_node, Vx_web_html.t_divchild), // traits
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
      return e_div_from_testcaselist;
    }

    public override Vx_core.Type_any vx_type() {
      return t_div_from_testcaselist;
    }

    public Vx_core.Func_any_from_any vx_fn_new(Vx_core.Class_any_from_any.IFn fn) {
      return Vx_core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_test.Type_testcaselist inputval = (Vx_test.Type_testcaselist)value;
      Vx_core.Type_any outputval = Vx_test.f_div_from_testcaselist(inputval);
      output = Vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_test.Type_testcaselist testcaselist = Vx_core.f_any_from_any(Vx_test.t_testcaselist, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_test.f_div_from_testcaselist(testcaselist);
      return output;
    }

    public Vx_web_html.Type_div vx_div_from_testcaselist(Vx_test.Type_testcaselist testcaselist) {
      return Vx_test.f_div_from_testcaselist(testcaselist);
    }

  }

  public static Func_div_from_testcaselist e_div_from_testcaselist = new Vx_test.Class_div_from_testcaselist();
  public static Func_div_from_testcaselist t_div_from_testcaselist = new Vx_test.Class_div_from_testcaselist();

  public static Vx_web_html.Type_div f_div_from_testcaselist(Vx_test.Type_testcaselist testcaselist) {
    Vx_web_html.Type_div output = Vx_web_html.e_div;
    output = Vx_core.f_new(
      Vx_web_html.t_div,
      Vx_core.vx_new(Vx_core.t_anylist,
        Vx_core.f_new(
          Vx_web_html.t_table,
          Vx_core.vx_new(Vx_core.t_anylist,
            Vx_core.vx_new_string(":thead"),
            Vx_core.f_new(
              Vx_web_html.t_thead,
              Vx_core.vx_new(Vx_core.t_anylist,
                Vx_core.f_new(
                  Vx_web_html.t_tr,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.f_new(
                      Vx_web_html.t_td,
                      Vx_core.vx_new(Vx_core.t_anylist,
                        Vx_core.f_new(
                          Vx_web_html.t_p,
                          Vx_core.vx_new(Vx_core.t_anylist,
                            Vx_core.vx_new_string(":text"),
                            Vx_core.vx_new_string("Pass?")
                          )
                        )
                      )
                    ),
                    Vx_core.f_new(
                      Vx_web_html.t_td,
                      Vx_core.vx_new(Vx_core.t_anylist,
                        Vx_core.f_new(
                          Vx_web_html.t_p,
                          Vx_core.vx_new(Vx_core.t_anylist,
                            Vx_core.vx_new_string(":text"),
                            Vx_core.vx_new_string("Name")
                          )
                        )
                      )
                    ),
                    Vx_core.f_new(
                      Vx_web_html.t_td,
                      Vx_core.vx_new(Vx_core.t_anylist,
                        Vx_core.f_new(
                          Vx_web_html.t_p,
                          Vx_core.vx_new(Vx_core.t_anylist,
                            Vx_core.vx_new_string(":text"),
                            Vx_core.vx_new_string("Test")
                          )
                        )
                      )
                    ),
                    Vx_core.f_new(
                      Vx_web_html.t_td,
                      Vx_core.vx_new(Vx_core.t_anylist,
                        Vx_core.f_new(
                          Vx_web_html.t_p,
                          Vx_core.vx_new(Vx_core.t_anylist,
                            Vx_core.vx_new_string(":text"),
                            Vx_core.vx_new_string("Expected")
                          )
                        )
                      )
                    ),
                    Vx_core.f_new(
                      Vx_web_html.t_td,
                      Vx_core.vx_new(Vx_core.t_anylist,
                        Vx_core.f_new(
                          Vx_web_html.t_p,
                          Vx_core.vx_new(Vx_core.t_anylist,
                            Vx_core.vx_new_string(":text"),
                            Vx_core.vx_new_string("Actual")
                          )
                        )
                      )
                    )
                  )
                )
              )
            ),
            Vx_core.vx_new_string(":tbody"),
            Vx_core.f_new(
              Vx_web_html.t_tbody,
              Vx_core.vx_new(Vx_core.t_anylist,
                Vx_test.f_trlist_from_testcaselist(testcaselist)
              )
            )
          )
        )
      )
    );
    return output;
  }

  /**
   * @function div_from_testpackage
   * Retuns a div from a test package
   * @param  {testpackage} testpackage
   * @return {div}
   * (func div<-testpackage)
   */
  public interface Func_div_from_testpackage : Vx_core.Func_any_from_any {
    public Vx_web_html.Type_div vx_div_from_testpackage(Vx_test.Type_testpackage testpackage);
  }

  public class Class_div_from_testpackage : Vx_core.Class_base, Func_div_from_testpackage {

    public override Vx_test.Func_div_from_testpackage vx_new(params Object[] vals) {
      Class_div_from_testpackage output = new Class_div_from_testpackage();
      return output;
    }

    public override Vx_test.Func_div_from_testpackage vx_copy(params Object[] vals) {
      Class_div_from_testpackage output = new Class_div_from_testpackage();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "div<-testpackage", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/web/html", // pkgname
          "div", // name
          ":struct", // extends
          Vx_core.vx_new(Vx_core.t_typelist, Vx_web_html.t_node, Vx_web_html.t_divchild), // traits
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
      return e_div_from_testpackage;
    }

    public override Vx_core.Type_any vx_type() {
      return t_div_from_testpackage;
    }

    public Vx_core.Func_any_from_any vx_fn_new(Vx_core.Class_any_from_any.IFn fn) {
      return Vx_core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_test.Type_testpackage inputval = (Vx_test.Type_testpackage)value;
      Vx_core.Type_any outputval = Vx_test.f_div_from_testpackage(inputval);
      output = Vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_test.Type_testpackage testpackage = Vx_core.f_any_from_any(Vx_test.t_testpackage, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_test.f_div_from_testpackage(testpackage);
      return output;
    }

    public Vx_web_html.Type_div vx_div_from_testpackage(Vx_test.Type_testpackage testpackage) {
      return Vx_test.f_div_from_testpackage(testpackage);
    }

  }

  public static Func_div_from_testpackage e_div_from_testpackage = new Vx_test.Class_div_from_testpackage();
  public static Func_div_from_testpackage t_div_from_testpackage = new Vx_test.Class_div_from_testpackage();

  public static Vx_web_html.Type_div f_div_from_testpackage(Vx_test.Type_testpackage testpackage) {
    Vx_web_html.Type_div output = Vx_web_html.e_div;
    output = Vx_core.f_let(
      Vx_web_html.t_div,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_test.Type_testcoveragesummary testcoveragesummary = testpackage.coveragesummary();
        Vx_core.Type_string pkgname = testpackage.testpkg();
        Vx_test.Type_testcaselist caselist = testpackage.caselist();
        Vx_core.Type_boolean passfail = testpackage.passfail();
        Vx_web_html.Type_style pkgnamestyle = Vx_web_html.f_style_from_stylesheet_name(
          Vx_test.c_stylesheet_test,
          Vx_core.vx_new_string(".pkgname")
        );
        Vx_web_html.Type_div node = Vx_test.f_div_from_testcaselist(caselist);
        Vx_web_html.Type_divchildlist nodes = Vx_core.f_new(
          Vx_web_html.t_divchildlist,
          Vx_core.vx_new(Vx_core.t_anylist,
              node
          )
        );
        Vx_web_html.Type_p p_passfail = Vx_test.f_p_from_passfail(passfail);
        Vx_web_html.Type_p p_pkgname = Vx_core.f_new(
          Vx_web_html.t_p,
          Vx_core.vx_new(Vx_core.t_anylist,
              Vx_core.vx_new_string(":style"),
              pkgnamestyle,
              Vx_core.vx_new_string(":text"),
              pkgname
          )
        );
        Vx_web_html.Type_p p_totalnums = Vx_test.f_p_from_testcoveragenums(
          testcoveragesummary.totalnums()
        );
        Vx_web_html.Type_p p_coveragenums = Vx_test.f_p_from_testcoveragenums(
          testcoveragesummary.typenums()
        );
        Vx_web_html.Type_p p_constnums = Vx_test.f_p_from_testcoveragenums(
          testcoveragesummary.constnums()
        );
        Vx_web_html.Type_p p_funcnums = Vx_test.f_p_from_testcoveragenums(
          testcoveragesummary.funcnums()
        );
        Vx_web_html.Type_p p_docnums = Vx_test.f_p_from_testcoveragenums(
          testcoveragesummary.docnums()
        );
        Vx_web_html.Type_p p_bigospacenums = Vx_test.f_p_from_testcoveragenums(
          testcoveragesummary.bigospacenums()
        );
        Vx_web_html.Type_p p_bigotimenums = Vx_test.f_p_from_testcoveragenums(
          testcoveragesummary.bigotimenums()
        );
        Vx_web_html.Type_divchildlist summary = Vx_core.f_new(
          Vx_web_html.t_divchildlist,
          Vx_core.vx_new(Vx_core.t_anylist,
              p_passfail,
              p_pkgname,
              p_totalnums,
              p_coveragenums,
              p_constnums,
              p_funcnums,
              p_docnums,
              p_bigospacenums,
              p_bigotimenums
          )
        );
        Vx_web_html.Type_details details = Vx_core.f_new(
          Vx_web_html.t_details,
          Vx_core.vx_new(Vx_core.t_anylist,
              Vx_core.vx_new_string(":summary"),
              summary,
              Vx_core.vx_new_string(":nodes"),
              nodes
          )
        );
        return Vx_core.f_new(
          Vx_web_html.t_div,
          Vx_core.vx_new(Vx_core.t_anylist,
            details
          )
        );
      })
    );
    return output;
  }

  /**
   * @function div_from_testpackagelist
   * @param  {testpackagelist} testpackagelist
   * @return {div}
   * (func div<-testpackagelist)
   */
  public interface Func_div_from_testpackagelist : Vx_core.Func_any_from_any {
    public Vx_web_html.Type_div vx_div_from_testpackagelist(Vx_test.Type_testpackagelist testpackagelist);
  }

  public class Class_div_from_testpackagelist : Vx_core.Class_base, Func_div_from_testpackagelist {

    public override Vx_test.Func_div_from_testpackagelist vx_new(params Object[] vals) {
      Class_div_from_testpackagelist output = new Class_div_from_testpackagelist();
      return output;
    }

    public override Vx_test.Func_div_from_testpackagelist vx_copy(params Object[] vals) {
      Class_div_from_testpackagelist output = new Class_div_from_testpackagelist();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "div<-testpackagelist", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/web/html", // pkgname
          "div", // name
          ":struct", // extends
          Vx_core.vx_new(Vx_core.t_typelist, Vx_web_html.t_node, Vx_web_html.t_divchild), // traits
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
      return e_div_from_testpackagelist;
    }

    public override Vx_core.Type_any vx_type() {
      return t_div_from_testpackagelist;
    }

    public Vx_core.Func_any_from_any vx_fn_new(Vx_core.Class_any_from_any.IFn fn) {
      return Vx_core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_test.Type_testpackagelist inputval = (Vx_test.Type_testpackagelist)value;
      Vx_core.Type_any outputval = Vx_test.f_div_from_testpackagelist(inputval);
      output = Vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_test.Type_testpackagelist testpackagelist = Vx_core.f_any_from_any(Vx_test.t_testpackagelist, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_test.f_div_from_testpackagelist(testpackagelist);
      return output;
    }

    public Vx_web_html.Type_div vx_div_from_testpackagelist(Vx_test.Type_testpackagelist testpackagelist) {
      return Vx_test.f_div_from_testpackagelist(testpackagelist);
    }

  }

  public static Func_div_from_testpackagelist e_div_from_testpackagelist = new Vx_test.Class_div_from_testpackagelist();
  public static Func_div_from_testpackagelist t_div_from_testpackagelist = new Vx_test.Class_div_from_testpackagelist();

  public static Vx_web_html.Type_div f_div_from_testpackagelist(Vx_test.Type_testpackagelist testpackagelist) {
    Vx_web_html.Type_div output = Vx_web_html.e_div;
    output = Vx_core.f_let(
      Vx_web_html.t_div,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_web_html.Type_style stylepassfail = Vx_web_html.f_style_from_stylesheet_name(
          Vx_test.c_stylesheet_test,
          Vx_core.vx_new_string(".passfail")
        );
        Vx_web_html.Type_style stylepkgname = Vx_web_html.f_style_from_stylesheet_name(
          Vx_test.c_stylesheet_test,
          Vx_core.vx_new_string(".pkgname")
        );
        Vx_web_html.Type_style stylepkgheader = Vx_web_html.f_style_from_stylesheet_name(
          Vx_test.c_stylesheet_test,
          Vx_core.vx_new_string(".pkgheader")
        );
        Vx_web_html.Type_style stylecoveragenum = Vx_web_html.f_style_from_stylesheet_name(
          Vx_test.c_stylesheet_test,
          Vx_core.vx_new_string(".coveragenums")
        );
        return Vx_core.f_new(
          Vx_web_html.t_div,
          Vx_core.vx_new(Vx_core.t_anylist,
            Vx_core.f_new(
              Vx_web_html.t_div,
              Vx_core.vx_new(Vx_core.t_anylist,
                Vx_core.vx_new_string(":style"),
                stylepkgheader,
                Vx_core.f_new(
                  Vx_web_html.t_p,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":style"),
                    stylepassfail,
                    Vx_core.vx_new_string(":text"),
                    Vx_core.vx_new_string("Pass?")
                  )
                ),
                Vx_core.f_new(
                  Vx_web_html.t_p,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":style"),
                    stylepkgname,
                    Vx_core.vx_new_string(":text"),
                    Vx_core.vx_new_string("Package Name")
                  )
                ),
                Vx_core.f_new(
                  Vx_web_html.t_p,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":style"),
                    stylecoveragenum,
                    Vx_core.vx_new_string(":text"),
                    Vx_core.vx_new_string("Coverage")
                  )
                ),
                Vx_core.f_new(
                  Vx_web_html.t_p,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":style"),
                    stylecoveragenum,
                    Vx_core.vx_new_string(":text"),
                    Vx_core.vx_new_string("(type)")
                  )
                ),
                Vx_core.f_new(
                  Vx_web_html.t_p,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":style"),
                    stylecoveragenum,
                    Vx_core.vx_new_string(":text"),
                    Vx_core.vx_new_string("(const)")
                  )
                ),
                Vx_core.f_new(
                  Vx_web_html.t_p,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":style"),
                    stylecoveragenum,
                    Vx_core.vx_new_string(":text"),
                    Vx_core.vx_new_string("(func)")
                  )
                ),
                Vx_core.f_new(
                  Vx_web_html.t_p,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":style"),
                    stylecoveragenum,
                    Vx_core.vx_new_string(":text"),
                    Vx_core.vx_new_string(":doc")
                  )
                ),
                Vx_core.f_new(
                  Vx_web_html.t_p,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":style"),
                    stylecoveragenum,
                    Vx_core.vx_new_string(":text"),
                    Vx_core.vx_new_string(":bigospace")
                  )
                ),
                Vx_core.f_new(
                  Vx_web_html.t_p,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":style"),
                    stylecoveragenum,
                    Vx_core.vx_new_string(":text"),
                    Vx_core.vx_new_string(":bigotime")
                  )
                )
              )
            ),
            Vx_core.f_new(
              Vx_web_html.t_div,
              Vx_core.vx_new(Vx_core.t_anylist,
                Vx_test.f_divchildlist_from_testpackagelist(testpackagelist)
              )
            )
          )
        );
      })
    );
    return output;
  }

  /**
   * @function divchildlist_from_testpackagelist
   * Returns a divlist from a testpackagelist.
   * @param  {testpackagelist} testpackagelist
   * @return {divchildlist}
   * (func divchildlist<-testpackagelist)
   */
  public interface Func_divchildlist_from_testpackagelist : Vx_core.Func_any_from_any {
    public Vx_web_html.Type_divchildlist vx_divchildlist_from_testpackagelist(Vx_test.Type_testpackagelist testpackagelist);
  }

  public class Class_divchildlist_from_testpackagelist : Vx_core.Class_base, Func_divchildlist_from_testpackagelist {

    public override Vx_test.Func_divchildlist_from_testpackagelist vx_new(params Object[] vals) {
      Class_divchildlist_from_testpackagelist output = new Class_divchildlist_from_testpackagelist();
      return output;
    }

    public override Vx_test.Func_divchildlist_from_testpackagelist vx_copy(params Object[] vals) {
      Class_divchildlist_from_testpackagelist output = new Class_divchildlist_from_testpackagelist();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "divchildlist<-testpackagelist", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/web/html", // pkgname
          "divchildlist", // name
          ":list", // extends
          Vx_core.e_typelist, // traits
          Vx_core.vx_new(Vx_core.t_typelist, Vx_web_html.t_divchild), // allowtypes
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
      return e_divchildlist_from_testpackagelist;
    }

    public override Vx_core.Type_any vx_type() {
      return t_divchildlist_from_testpackagelist;
    }

    public Vx_core.Func_any_from_any vx_fn_new(Vx_core.Class_any_from_any.IFn fn) {
      return Vx_core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_test.Type_testpackagelist inputval = (Vx_test.Type_testpackagelist)value;
      Vx_core.Type_any outputval = Vx_test.f_divchildlist_from_testpackagelist(inputval);
      output = Vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_test.Type_testpackagelist testpackagelist = Vx_core.f_any_from_any(Vx_test.t_testpackagelist, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_test.f_divchildlist_from_testpackagelist(testpackagelist);
      return output;
    }

    public Vx_web_html.Type_divchildlist vx_divchildlist_from_testpackagelist(Vx_test.Type_testpackagelist testpackagelist) {
      return Vx_test.f_divchildlist_from_testpackagelist(testpackagelist);
    }

  }

  public static Func_divchildlist_from_testpackagelist e_divchildlist_from_testpackagelist = new Vx_test.Class_divchildlist_from_testpackagelist();
  public static Func_divchildlist_from_testpackagelist t_divchildlist_from_testpackagelist = new Vx_test.Class_divchildlist_from_testpackagelist();

  public static Vx_web_html.Type_divchildlist f_divchildlist_from_testpackagelist(Vx_test.Type_testpackagelist testpackagelist) {
    Vx_web_html.Type_divchildlist output = Vx_web_html.e_divchildlist;
    output = Vx_core.f_list_from_list_1(
      Vx_web_html.t_divchildlist,
      testpackagelist,
      Vx_test.t_div_from_testpackage
    );
    return output;
  }

  /**
   * @function file_test
   * Default file location for testsuite.vxlisp
   * @return {file}
   * (func file-test)
   */
  public interface Func_file_test : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_data_file.Type_file vx_file_test();
  }

  public class Class_file_test : Vx_core.Class_base, Func_file_test {

    public override Vx_test.Func_file_test vx_new(params Object[] vals) {
      Class_file_test output = new Class_file_test();
      return output;
    }

    public override Vx_test.Func_file_test vx_copy(params Object[] vals) {
      Class_file_test output = new Class_file_test();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "file-test", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/data/file", // pkgname
          "file", // name
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
      return e_file_test;
    }

    public override Vx_core.Type_any vx_type() {
      return t_file_test;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      output = Vx_test.f_file_test();
      return output;
    }

    public Vx_data_file.Type_file vx_file_test() {
      return Vx_test.f_file_test();
    }

  }

  public static Func_file_test e_file_test = new Vx_test.Class_file_test();
  public static Func_file_test t_file_test = new Vx_test.Class_file_test();

  public static Vx_data_file.Type_file f_file_test() {
    Vx_data_file.Type_file output = Vx_data_file.e_file;
    output = Vx_core.f_new(
      Vx_data_file.t_file,
      Vx_core.vx_new(Vx_core.t_anylist,
        Vx_core.vx_new_string(":name"),
        Vx_core.vx_new_string("testsuite.vxlisp"),
        Vx_core.vx_new_string(":path"),
        Vx_core.vx_new_string("src/test/resources")
      )
    );
    return output;
  }

  /**
   * @function file_testhtml
   * Default file location for testsuite.html
   * @return {file}
   * (func file-testhtml)
   */
  public interface Func_file_testhtml : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_data_file.Type_file vx_file_testhtml();
  }

  public class Class_file_testhtml : Vx_core.Class_base, Func_file_testhtml {

    public override Vx_test.Func_file_testhtml vx_new(params Object[] vals) {
      Class_file_testhtml output = new Class_file_testhtml();
      return output;
    }

    public override Vx_test.Func_file_testhtml vx_copy(params Object[] vals) {
      Class_file_testhtml output = new Class_file_testhtml();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "file-testhtml", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/data/file", // pkgname
          "file", // name
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
      return e_file_testhtml;
    }

    public override Vx_core.Type_any vx_type() {
      return t_file_testhtml;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      output = Vx_test.f_file_testhtml();
      return output;
    }

    public Vx_data_file.Type_file vx_file_testhtml() {
      return Vx_test.f_file_testhtml();
    }

  }

  public static Func_file_testhtml e_file_testhtml = new Vx_test.Class_file_testhtml();
  public static Func_file_testhtml t_file_testhtml = new Vx_test.Class_file_testhtml();

  public static Vx_data_file.Type_file f_file_testhtml() {
    Vx_data_file.Type_file output = Vx_data_file.e_file;
    output = Vx_core.f_new(
      Vx_data_file.t_file,
      Vx_core.vx_new(Vx_core.t_anylist,
        Vx_core.vx_new_string(":name"),
        Vx_core.vx_new_string("testsuite.html"),
        Vx_core.vx_new_string(":path"),
        Vx_core.vx_new_string("src/test/resources")
      )
    );
    return output;
  }

  /**
   * @function file_testnode
   * Default file location for testsuitenode.vxlisp
   * @return {file}
   * (func file-testnode)
   */
  public interface Func_file_testnode : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_data_file.Type_file vx_file_testnode();
  }

  public class Class_file_testnode : Vx_core.Class_base, Func_file_testnode {

    public override Vx_test.Func_file_testnode vx_new(params Object[] vals) {
      Class_file_testnode output = new Class_file_testnode();
      return output;
    }

    public override Vx_test.Func_file_testnode vx_copy(params Object[] vals) {
      Class_file_testnode output = new Class_file_testnode();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "file-testnode", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/data/file", // pkgname
          "file", // name
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
      return e_file_testnode;
    }

    public override Vx_core.Type_any vx_type() {
      return t_file_testnode;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      output = Vx_test.f_file_testnode();
      return output;
    }

    public Vx_data_file.Type_file vx_file_testnode() {
      return Vx_test.f_file_testnode();
    }

  }

  public static Func_file_testnode e_file_testnode = new Vx_test.Class_file_testnode();
  public static Func_file_testnode t_file_testnode = new Vx_test.Class_file_testnode();

  public static Vx_data_file.Type_file f_file_testnode() {
    Vx_data_file.Type_file output = Vx_data_file.e_file;
    output = Vx_core.f_new(
      Vx_data_file.t_file,
      Vx_core.vx_new(Vx_core.t_anylist,
        Vx_core.vx_new_string(":name"),
        Vx_core.vx_new_string("testsuitenode.vxlisp"),
        Vx_core.vx_new_string(":path"),
        Vx_core.vx_new_string("src/test/resources")
      )
    );
    return output;
  }

  /**
   * @function html_from_divtest
   * Returns html from test div
   * @param  {div} divtest
   * @return {html}
   * (func html<-divtest)
   */
  public interface Func_html_from_divtest : Vx_core.Func_any_from_any {
    public Vx_web_html.Type_html vx_html_from_divtest(Vx_web_html.Type_div divtest);
  }

  public class Class_html_from_divtest : Vx_core.Class_base, Func_html_from_divtest {

    public override Vx_test.Func_html_from_divtest vx_new(params Object[] vals) {
      Class_html_from_divtest output = new Class_html_from_divtest();
      return output;
    }

    public override Vx_test.Func_html_from_divtest vx_copy(params Object[] vals) {
      Class_html_from_divtest output = new Class_html_from_divtest();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "html<-divtest", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/web/html", // pkgname
          "html", // name
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
      return e_html_from_divtest;
    }

    public override Vx_core.Type_any vx_type() {
      return t_html_from_divtest;
    }

    public Vx_core.Func_any_from_any vx_fn_new(Vx_core.Class_any_from_any.IFn fn) {
      return Vx_core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_web_html.Type_div inputval = (Vx_web_html.Type_div)value;
      Vx_core.Type_any outputval = Vx_test.f_html_from_divtest(inputval);
      output = Vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_web_html.Type_div divtest = Vx_core.f_any_from_any(Vx_web_html.t_div, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_test.f_html_from_divtest(divtest);
      return output;
    }

    public Vx_web_html.Type_html vx_html_from_divtest(Vx_web_html.Type_div divtest) {
      return Vx_test.f_html_from_divtest(divtest);
    }

  }

  public static Func_html_from_divtest e_html_from_divtest = new Vx_test.Class_html_from_divtest();
  public static Func_html_from_divtest t_html_from_divtest = new Vx_test.Class_html_from_divtest();

  public static Vx_web_html.Type_html f_html_from_divtest(Vx_web_html.Type_div divtest) {
    Vx_web_html.Type_html output = Vx_web_html.e_html;
    output = Vx_core.f_new(
      Vx_web_html.t_html,
      Vx_core.vx_new(Vx_core.t_anylist,
        Vx_core.vx_new_string(":lang"),
        Vx_core.vx_new_string("en"),
        Vx_core.vx_new_string(":head"),
        Vx_core.f_new(
          Vx_web_html.t_head,
          Vx_core.vx_new(Vx_core.t_anylist,
            Vx_core.f_new(
              Vx_web_html.t_meta,
              Vx_core.vx_new(Vx_core.t_anylist,
                Vx_core.vx_new_string(":charset"),
                Vx_core.vx_new_string("utf-8")
              )
            ),
            Vx_core.f_new(
              Vx_web_html.t_meta,
              Vx_core.vx_new(Vx_core.t_anylist,
                Vx_core.vx_new_string(":name"),
                Vx_core.vx_new_string("viewport"),
                Vx_core.vx_new_string(":content"),
                Vx_core.vx_new_string("width=device-width, initial-scale=1.0")
              )
            ),
            Vx_core.f_new(
              Vx_web_html.t_title,
              Vx_core.vx_new(Vx_core.t_anylist,
                Vx_core.vx_new_string(":text"),
                Vx_core.vx_new_string("Test Suite")
              )
            ),
            Vx_test.c_stylesheet_test
          )
        ),
        Vx_core.vx_new_string(":body"),
        Vx_core.f_new(
          Vx_web_html.t_body,
          Vx_core.vx_new(Vx_core.t_anylist,
            Vx_core.f_new(
              Vx_web_html.t_div,
              Vx_core.vx_new(Vx_core.t_anylist,
                Vx_core.f_new(
                  Vx_web_html.t_h1,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string("Test Suite")
                  )
                )
              )
            ),
            divtest
          )
        )
      )
    );
    return output;
  }

  /**
   * @function p_from_passfail
   * Returns a <p> tag from a passfail boolean value
   * @param  {boolean} passfail
   * @return {p}
   * (func p<-passfail)
   */
  public interface Func_p_from_passfail : Vx_core.Func_any_from_any {
    public Vx_web_html.Type_p vx_p_from_passfail(Vx_core.Type_boolean passfail);
  }

  public class Class_p_from_passfail : Vx_core.Class_base, Func_p_from_passfail {

    public override Vx_test.Func_p_from_passfail vx_new(params Object[] vals) {
      Class_p_from_passfail output = new Class_p_from_passfail();
      return output;
    }

    public override Vx_test.Func_p_from_passfail vx_copy(params Object[] vals) {
      Class_p_from_passfail output = new Class_p_from_passfail();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "p<-passfail", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/web/html", // pkgname
          "p", // name
          ":struct", // extends
          Vx_core.vx_new(Vx_core.t_typelist, Vx_web_html.t_node, Vx_web_html.t_divchild), // traits
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
      return e_p_from_passfail;
    }

    public override Vx_core.Type_any vx_type() {
      return t_p_from_passfail;
    }

    public Vx_core.Func_any_from_any vx_fn_new(Vx_core.Class_any_from_any.IFn fn) {
      return Vx_core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_core.Type_boolean inputval = (Vx_core.Type_boolean)value;
      Vx_core.Type_any outputval = Vx_test.f_p_from_passfail(inputval);
      output = Vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_boolean passfail = Vx_core.f_any_from_any(Vx_core.t_boolean, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_test.f_p_from_passfail(passfail);
      return output;
    }

    public Vx_web_html.Type_p vx_p_from_passfail(Vx_core.Type_boolean passfail) {
      return Vx_test.f_p_from_passfail(passfail);
    }

  }

  public static Func_p_from_passfail e_p_from_passfail = new Vx_test.Class_p_from_passfail();
  public static Func_p_from_passfail t_p_from_passfail = new Vx_test.Class_p_from_passfail();

  public static Vx_web_html.Type_p f_p_from_passfail(Vx_core.Type_boolean passfail) {
    Vx_web_html.Type_p output = Vx_web_html.e_p;
    output = Vx_core.f_let(
      Vx_web_html.t_p,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_core.Type_string text = Vx_core.f_if_1(Vx_core.t_string, passfail, Vx_core.vx_new_string("Pass"), Vx_core.vx_new_string("Fail"));
        Vx_core.Type_string stylename = Vx_core.f_if_1(Vx_core.t_string, passfail, Vx_core.vx_new_string(".passflag"), Vx_core.vx_new_string(".failflag"));
        Vx_web_html.Type_style style = Vx_web_html.f_style_from_stylesheet_name(
          Vx_test.c_stylesheet_test,
          stylename
        );
        return Vx_core.f_new(
          Vx_web_html.t_p,
          Vx_core.vx_new(Vx_core.t_anylist,
            Vx_core.vx_new_string(":style"),
            style,
            Vx_core.vx_new_string(":text"),
            text
          )
        );
      })
    );
    return output;
  }

  /**
   * @function p_from_testcoveragenums
   * Returns <p>tests / total (pct%)</p> from testcoveragenums
   * @param  {testcoveragenums} nums
   * @return {p}
   * (func p<-testcoveragenums)
   */
  public interface Func_p_from_testcoveragenums : Vx_core.Func_any_from_any {
    public Vx_web_html.Type_p vx_p_from_testcoveragenums(Vx_test.Type_testcoveragenums nums);
  }

  public class Class_p_from_testcoveragenums : Vx_core.Class_base, Func_p_from_testcoveragenums {

    public override Vx_test.Func_p_from_testcoveragenums vx_new(params Object[] vals) {
      Class_p_from_testcoveragenums output = new Class_p_from_testcoveragenums();
      return output;
    }

    public override Vx_test.Func_p_from_testcoveragenums vx_copy(params Object[] vals) {
      Class_p_from_testcoveragenums output = new Class_p_from_testcoveragenums();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "p<-testcoveragenums", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/web/html", // pkgname
          "p", // name
          ":struct", // extends
          Vx_core.vx_new(Vx_core.t_typelist, Vx_web_html.t_node, Vx_web_html.t_divchild), // traits
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
      return e_p_from_testcoveragenums;
    }

    public override Vx_core.Type_any vx_type() {
      return t_p_from_testcoveragenums;
    }

    public Vx_core.Func_any_from_any vx_fn_new(Vx_core.Class_any_from_any.IFn fn) {
      return Vx_core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_test.Type_testcoveragenums inputval = (Vx_test.Type_testcoveragenums)value;
      Vx_core.Type_any outputval = Vx_test.f_p_from_testcoveragenums(inputval);
      output = Vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_test.Type_testcoveragenums nums = Vx_core.f_any_from_any(Vx_test.t_testcoveragenums, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_test.f_p_from_testcoveragenums(nums);
      return output;
    }

    public Vx_web_html.Type_p vx_p_from_testcoveragenums(Vx_test.Type_testcoveragenums nums) {
      return Vx_test.f_p_from_testcoveragenums(nums);
    }

  }

  public static Func_p_from_testcoveragenums e_p_from_testcoveragenums = new Vx_test.Class_p_from_testcoveragenums();
  public static Func_p_from_testcoveragenums t_p_from_testcoveragenums = new Vx_test.Class_p_from_testcoveragenums();

  public static Vx_web_html.Type_p f_p_from_testcoveragenums(Vx_test.Type_testcoveragenums nums) {
    Vx_web_html.Type_p output = Vx_web_html.e_p;
    output = Vx_core.f_new(
      Vx_web_html.t_p,
      Vx_core.vx_new(Vx_core.t_anylist,
        Vx_core.vx_new_string(":style"),
        Vx_web_html.f_style_from_stylesheet_name(
          Vx_test.c_stylesheet_test,
          Vx_core.vx_new_string(".coveragenums")
        ),
        Vx_core.vx_new_string(":text"),
        Vx_core.f_new(
          Vx_core.t_string,
          Vx_core.vx_new(Vx_core.t_anylist,
            nums.pct(),
            Vx_core.vx_new_string("% "),
            nums.tests(),
            Vx_core.vx_new_string("/"),
            nums.total()
          )
        )
      )
    );
    return output;
  }

  /**
   * 
   * @async
   * @function resolve_testcase
   * Resolves a testcase
   * @param  {testcase} testcase
   * @return {testcase}
   * (func resolve-testcase)
   */
  public interface Func_resolve_testcase : Vx_core.Func_any_from_any_async {
    public Task<Vx_test.Type_testcase> vx_resolve_testcase(Vx_test.Type_testcase testcase);
  }

  public class Class_resolve_testcase : Vx_core.Class_base, Func_resolve_testcase {

    public override Vx_test.Func_resolve_testcase vx_new(params Object[] vals) {
      Class_resolve_testcase output = new Class_resolve_testcase();
      return output;
    }

    public override Vx_test.Func_resolve_testcase vx_copy(params Object[] vals) {
      Class_resolve_testcase output = new Class_resolve_testcase();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testcase", // name
        0, // idx
        true, // async
        Vx_core.typedef_new(
          "vx/test", // pkgname
          "testcase", // name
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
      return e_resolve_testcase;
    }

    public override Vx_core.Type_any vx_type() {
      return t_resolve_testcase;
    }

    public Vx_core.Func_any_from_any_async vx_fn_new(Vx_core.Class_any_from_any_async.IFn fn) {
      return Vx_core.e_any_from_any_async;
    }

    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      Vx_test.Type_testcase inputval = Vx_core.f_any_from_any(Vx_test.t_testcase, value);
      Task<Vx_test.Type_testcase> future = Vx_test.f_resolve_testcase(inputval);
      Task<T> output = (Task<T>)future;
      return output;
    }

    public Task<Vx_core.Type_any> vx_repl(Vx_core.Type_anylist arglist) {
      Task<Vx_core.Type_any> output = Vx_core.vx_async_new_completed(Vx_core.e_any);
      Vx_test.Type_testcase testcase = Vx_core.f_any_from_any(Vx_test.t_testcase, arglist.vx_any(Vx_core.vx_new_int(0)));
      Task<Vx_test.Type_testcase> future = Vx_test.f_resolve_testcase(testcase);
      output = Vx_core.vx_async_from_async(Vx_core.t_any, future);
      return output;
    }

    public Task<Vx_test.Type_testcase> vx_resolve_testcase(Vx_test.Type_testcase testcase) {
      return Vx_test.f_resolve_testcase(testcase);
    }

  }

  public static Func_resolve_testcase e_resolve_testcase = new Vx_test.Class_resolve_testcase();
  public static Func_resolve_testcase t_resolve_testcase = new Vx_test.Class_resolve_testcase();

  public static Task<Vx_test.Type_testcase> f_resolve_testcase(Vx_test.Type_testcase testcase) {
    Task<Vx_test.Type_testcase> output = Vx_core.vx_async_new_completed(Vx_test.e_testcase);
    output = Vx_core.f_let_async(
      Vx_test.t_testcase,
      Vx_core.t_any_from_func_async.vx_fn_new(() => {
        Vx_test.Type_testdescribelist describelist = testcase.describelist();
        Task<Vx_test.Type_testdescribelist> future_resolvedlist = Vx_test.f_resolve_testdescribelist(describelist);
        return Vx_core.vx_async_from_async_fn(future_resolvedlist, (resolvedlist) => {
          Vx_core.Type_booleanlist passfaillist = Vx_core.f_list_from_list_1(
            Vx_core.t_booleanlist,
            resolvedlist,
            Vx_core.t_any_from_any.vx_fn_new((testdescribe_any) => {
              Vx_test.Type_testdescribe testdescribe = Vx_core.f_any_from_any(Vx_test.t_testdescribe, testdescribe_any);
              return 
                  Vx_core.f_let(
                    Vx_core.t_boolean,
                    Vx_core.t_any_from_func.vx_fn_new(() => {
                      Vx_test.Type_testresult testresult = testdescribe.testresult();
                      return testresult.passfail();
                    })
                  );
            })
          );
          Vx_core.Type_boolean passfail = Vx_core.f_and_1(passfaillist);
          return Vx_core.f_copy(
            testcase,
            Vx_core.vx_new(Vx_core.t_anylist,
                  Vx_core.vx_new_string(":passfail"),
                  passfail,
                  Vx_core.vx_new_string(":describelist"),
                  resolvedlist
            )
          );
        });
      })
    );
    return output;
  }

  /**
   * 
   * @async
   * @function resolve_testcaselist
   * Resolves a testcaselist
   * @param  {testcaselist} testcaselist
   * @return {testcaselist}
   * (func resolve-testcaselist)
   */
  public interface Func_resolve_testcaselist : Vx_core.Func_any_from_any_async {
    public Task<Vx_test.Type_testcaselist> vx_resolve_testcaselist(Vx_test.Type_testcaselist testcaselist);
  }

  public class Class_resolve_testcaselist : Vx_core.Class_base, Func_resolve_testcaselist {

    public override Vx_test.Func_resolve_testcaselist vx_new(params Object[] vals) {
      Class_resolve_testcaselist output = new Class_resolve_testcaselist();
      return output;
    }

    public override Vx_test.Func_resolve_testcaselist vx_copy(params Object[] vals) {
      Class_resolve_testcaselist output = new Class_resolve_testcaselist();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testcaselist", // name
        0, // idx
        true, // async
        Vx_core.typedef_new(
          "vx/test", // pkgname
          "testcaselist", // name
          ":list", // extends
          Vx_core.e_typelist, // traits
          Vx_core.vx_new(Vx_core.t_typelist, Vx_test.t_testcase), // allowtypes
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
      return e_resolve_testcaselist;
    }

    public override Vx_core.Type_any vx_type() {
      return t_resolve_testcaselist;
    }

    public Vx_core.Func_any_from_any_async vx_fn_new(Vx_core.Class_any_from_any_async.IFn fn) {
      return Vx_core.e_any_from_any_async;
    }

    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      Vx_test.Type_testcaselist inputval = Vx_core.f_any_from_any(Vx_test.t_testcaselist, value);
      Task<Vx_test.Type_testcaselist> future = Vx_test.f_resolve_testcaselist(inputval);
      Task<T> output = (Task<T>)future;
      return output;
    }

    public Task<Vx_core.Type_any> vx_repl(Vx_core.Type_anylist arglist) {
      Task<Vx_core.Type_any> output = Vx_core.vx_async_new_completed(Vx_core.e_any);
      Vx_test.Type_testcaselist testcaselist = Vx_core.f_any_from_any(Vx_test.t_testcaselist, arglist.vx_any(Vx_core.vx_new_int(0)));
      Task<Vx_test.Type_testcaselist> future = Vx_test.f_resolve_testcaselist(testcaselist);
      output = Vx_core.vx_async_from_async(Vx_core.t_any, future);
      return output;
    }

    public Task<Vx_test.Type_testcaselist> vx_resolve_testcaselist(Vx_test.Type_testcaselist testcaselist) {
      return Vx_test.f_resolve_testcaselist(testcaselist);
    }

  }

  public static Func_resolve_testcaselist e_resolve_testcaselist = new Vx_test.Class_resolve_testcaselist();
  public static Func_resolve_testcaselist t_resolve_testcaselist = new Vx_test.Class_resolve_testcaselist();

  public static Task<Vx_test.Type_testcaselist> f_resolve_testcaselist(Vx_test.Type_testcaselist testcaselist) {
    Task<Vx_test.Type_testcaselist> output = Vx_core.vx_async_new_completed(Vx_test.e_testcaselist);
    output = Vx_core.f_list_from_list_async(
      Vx_test.t_testcaselist,
      testcaselist,
      Vx_test.t_resolve_testcase
    );
    return output;
  }

  /**
   * 
   * @async
   * @function resolve_testdescribe
   * Resolves a testdescribe
   * @param  {testdescribe} testdescribe
   * @return {testdescribe}
   * (func resolve-testdescribe)
   */
  public interface Func_resolve_testdescribe : Vx_core.Func_any_from_any_async {
    public Task<Vx_test.Type_testdescribe> vx_resolve_testdescribe(Vx_test.Type_testdescribe testdescribe);
  }

  public class Class_resolve_testdescribe : Vx_core.Class_base, Func_resolve_testdescribe {

    public override Vx_test.Func_resolve_testdescribe vx_new(params Object[] vals) {
      Class_resolve_testdescribe output = new Class_resolve_testdescribe();
      return output;
    }

    public override Vx_test.Func_resolve_testdescribe vx_copy(params Object[] vals) {
      Class_resolve_testdescribe output = new Class_resolve_testdescribe();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testdescribe", // name
        0, // idx
        true, // async
        Vx_core.typedef_new(
          "vx/test", // pkgname
          "testdescribe", // name
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
      return e_resolve_testdescribe;
    }

    public override Vx_core.Type_any vx_type() {
      return t_resolve_testdescribe;
    }

    public Vx_core.Func_any_from_any_async vx_fn_new(Vx_core.Class_any_from_any_async.IFn fn) {
      return Vx_core.e_any_from_any_async;
    }

    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      Vx_test.Type_testdescribe inputval = Vx_core.f_any_from_any(Vx_test.t_testdescribe, value);
      Task<Vx_test.Type_testdescribe> future = Vx_test.f_resolve_testdescribe(inputval);
      Task<T> output = (Task<T>)future;
      return output;
    }

    public Task<Vx_core.Type_any> vx_repl(Vx_core.Type_anylist arglist) {
      Task<Vx_core.Type_any> output = Vx_core.vx_async_new_completed(Vx_core.e_any);
      Vx_test.Type_testdescribe testdescribe = Vx_core.f_any_from_any(Vx_test.t_testdescribe, arglist.vx_any(Vx_core.vx_new_int(0)));
      Task<Vx_test.Type_testdescribe> future = Vx_test.f_resolve_testdescribe(testdescribe);
      output = Vx_core.vx_async_from_async(Vx_core.t_any, future);
      return output;
    }

    public Task<Vx_test.Type_testdescribe> vx_resolve_testdescribe(Vx_test.Type_testdescribe testdescribe) {
      return Vx_test.f_resolve_testdescribe(testdescribe);
    }

  }

  public static Func_resolve_testdescribe e_resolve_testdescribe = new Vx_test.Class_resolve_testdescribe();
  public static Func_resolve_testdescribe t_resolve_testdescribe = new Vx_test.Class_resolve_testdescribe();

  public static Task<Vx_test.Type_testdescribe> f_resolve_testdescribe(Vx_test.Type_testdescribe testdescribe) {
    Task<Vx_test.Type_testdescribe> output = Vx_core.vx_async_new_completed(Vx_test.e_testdescribe);
    output = Vx_core.f_let_async(
      Vx_test.t_testdescribe,
      Vx_core.t_any_from_func_async.vx_fn_new(() => {
        Vx_test.Type_testresult testresult = testdescribe.testresult();
        Task<Vx_test.Type_testresult> future_resolved = Vx_test.f_resolve_testresult(testresult);
        return Vx_core.vx_async_from_async_fn(future_resolved, (resolved) => {
          return Vx_core.f_copy(
            testdescribe,
            Vx_core.vx_new(Vx_core.t_anylist,
                  Vx_core.vx_new_string(":testresult"),
                  resolved
            )
          );
        });
      })
    );
    return output;
  }

  /**
   * 
   * @async
   * @function resolve_testdescribelist
   * Resolves a testdescribelist
   * @param  {testdescribelist} testdescribelist
   * @return {testdescribelist}
   * (func resolve-testdescribelist)
   */
  public interface Func_resolve_testdescribelist : Vx_core.Func_any_from_any_async {
    public Task<Vx_test.Type_testdescribelist> vx_resolve_testdescribelist(Vx_test.Type_testdescribelist testdescribelist);
  }

  public class Class_resolve_testdescribelist : Vx_core.Class_base, Func_resolve_testdescribelist {

    public override Vx_test.Func_resolve_testdescribelist vx_new(params Object[] vals) {
      Class_resolve_testdescribelist output = new Class_resolve_testdescribelist();
      return output;
    }

    public override Vx_test.Func_resolve_testdescribelist vx_copy(params Object[] vals) {
      Class_resolve_testdescribelist output = new Class_resolve_testdescribelist();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testdescribelist", // name
        0, // idx
        true, // async
        Vx_core.typedef_new(
          "vx/test", // pkgname
          "testdescribelist", // name
          ":list", // extends
          Vx_core.e_typelist, // traits
          Vx_core.vx_new(Vx_core.t_typelist, Vx_test.t_testdescribe), // allowtypes
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
      return e_resolve_testdescribelist;
    }

    public override Vx_core.Type_any vx_type() {
      return t_resolve_testdescribelist;
    }

    public Vx_core.Func_any_from_any_async vx_fn_new(Vx_core.Class_any_from_any_async.IFn fn) {
      return Vx_core.e_any_from_any_async;
    }

    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      Vx_test.Type_testdescribelist inputval = Vx_core.f_any_from_any(Vx_test.t_testdescribelist, value);
      Task<Vx_test.Type_testdescribelist> future = Vx_test.f_resolve_testdescribelist(inputval);
      Task<T> output = (Task<T>)future;
      return output;
    }

    public Task<Vx_core.Type_any> vx_repl(Vx_core.Type_anylist arglist) {
      Task<Vx_core.Type_any> output = Vx_core.vx_async_new_completed(Vx_core.e_any);
      Vx_test.Type_testdescribelist testdescribelist = Vx_core.f_any_from_any(Vx_test.t_testdescribelist, arglist.vx_any(Vx_core.vx_new_int(0)));
      Task<Vx_test.Type_testdescribelist> future = Vx_test.f_resolve_testdescribelist(testdescribelist);
      output = Vx_core.vx_async_from_async(Vx_core.t_any, future);
      return output;
    }

    public Task<Vx_test.Type_testdescribelist> vx_resolve_testdescribelist(Vx_test.Type_testdescribelist testdescribelist) {
      return Vx_test.f_resolve_testdescribelist(testdescribelist);
    }

  }

  public static Func_resolve_testdescribelist e_resolve_testdescribelist = new Vx_test.Class_resolve_testdescribelist();
  public static Func_resolve_testdescribelist t_resolve_testdescribelist = new Vx_test.Class_resolve_testdescribelist();

  public static Task<Vx_test.Type_testdescribelist> f_resolve_testdescribelist(Vx_test.Type_testdescribelist testdescribelist) {
    Task<Vx_test.Type_testdescribelist> output = Vx_core.vx_async_new_completed(Vx_test.e_testdescribelist);
    output = Vx_core.f_list_from_list_async(
      Vx_test.t_testdescribelist,
      testdescribelist,
      Vx_test.t_resolve_testdescribe
    );
    return output;
  }

  /**
   * 
   * @async
   * @function resolve_testpackage
   * Resolves a testpackage
   * @param  {testpackage} testpackage
   * @return {testpackage}
   * (func resolve-testpackage)
   */
  public interface Func_resolve_testpackage : Vx_core.Func_any_from_any_async {
    public Task<Vx_test.Type_testpackage> vx_resolve_testpackage(Vx_test.Type_testpackage testpackage);
  }

  public class Class_resolve_testpackage : Vx_core.Class_base, Func_resolve_testpackage {

    public override Vx_test.Func_resolve_testpackage vx_new(params Object[] vals) {
      Class_resolve_testpackage output = new Class_resolve_testpackage();
      return output;
    }

    public override Vx_test.Func_resolve_testpackage vx_copy(params Object[] vals) {
      Class_resolve_testpackage output = new Class_resolve_testpackage();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testpackage", // name
        0, // idx
        true, // async
        Vx_core.typedef_new(
          "vx/test", // pkgname
          "testpackage", // name
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
      return e_resolve_testpackage;
    }

    public override Vx_core.Type_any vx_type() {
      return t_resolve_testpackage;
    }

    public Vx_core.Func_any_from_any_async vx_fn_new(Vx_core.Class_any_from_any_async.IFn fn) {
      return Vx_core.e_any_from_any_async;
    }

    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      Vx_test.Type_testpackage inputval = Vx_core.f_any_from_any(Vx_test.t_testpackage, value);
      Task<Vx_test.Type_testpackage> future = Vx_test.f_resolve_testpackage(inputval);
      Task<T> output = (Task<T>)future;
      return output;
    }

    public Task<Vx_core.Type_any> vx_repl(Vx_core.Type_anylist arglist) {
      Task<Vx_core.Type_any> output = Vx_core.vx_async_new_completed(Vx_core.e_any);
      Vx_test.Type_testpackage testpackage = Vx_core.f_any_from_any(Vx_test.t_testpackage, arglist.vx_any(Vx_core.vx_new_int(0)));
      Task<Vx_test.Type_testpackage> future = Vx_test.f_resolve_testpackage(testpackage);
      output = Vx_core.vx_async_from_async(Vx_core.t_any, future);
      return output;
    }

    public Task<Vx_test.Type_testpackage> vx_resolve_testpackage(Vx_test.Type_testpackage testpackage) {
      return Vx_test.f_resolve_testpackage(testpackage);
    }

  }

  public static Func_resolve_testpackage e_resolve_testpackage = new Vx_test.Class_resolve_testpackage();
  public static Func_resolve_testpackage t_resolve_testpackage = new Vx_test.Class_resolve_testpackage();

  public static Task<Vx_test.Type_testpackage> f_resolve_testpackage(Vx_test.Type_testpackage testpackage) {
    Task<Vx_test.Type_testpackage> output = Vx_core.vx_async_new_completed(Vx_test.e_testpackage);
    output = Vx_core.f_let_async(
      Vx_test.t_testpackage,
      Vx_core.t_any_from_func_async.vx_fn_new(() => {
        Vx_test.Type_testcaselist testcaselist = testpackage.caselist();
        Task<Vx_test.Type_testcaselist> future_resolvedlist = Vx_test.f_resolve_testcaselist(testcaselist);
        return Vx_core.vx_async_from_async_fn(future_resolvedlist, (resolvedlist) => {
          Vx_core.Type_booleanlist passfaillist = Vx_core.f_list_from_list_1(
            Vx_core.t_booleanlist,
            resolvedlist,
            Vx_core.t_any_from_any.vx_fn_new((testcase_any) => {
              Vx_test.Type_testcase testcase = Vx_core.f_any_from_any(Vx_test.t_testcase, testcase_any);
              return 
                  testcase.passfail();
            })
          );
          Vx_core.Type_boolean passfail = Vx_core.f_and_1(passfaillist);
          return Vx_core.f_copy(
            testpackage,
            Vx_core.vx_new(Vx_core.t_anylist,
                  Vx_core.vx_new_string(":passfail"),
                  passfail,
                  Vx_core.vx_new_string(":caselist"),
                  resolvedlist
            )
          );
        });
      })
    );
    return output;
  }

  /**
   * 
   * @async
   * @function resolve_testpackagelist
   * Resolves a testpackagelist
   * @param  {testpackagelist} testpackagelist
   * @return {testpackagelist}
   * (func resolve-testpackagelist)
   */
  public interface Func_resolve_testpackagelist : Vx_core.Func_any_from_any_async {
    public Task<Vx_test.Type_testpackagelist> vx_resolve_testpackagelist(Vx_test.Type_testpackagelist testpackagelist);
  }

  public class Class_resolve_testpackagelist : Vx_core.Class_base, Func_resolve_testpackagelist {

    public override Vx_test.Func_resolve_testpackagelist vx_new(params Object[] vals) {
      Class_resolve_testpackagelist output = new Class_resolve_testpackagelist();
      return output;
    }

    public override Vx_test.Func_resolve_testpackagelist vx_copy(params Object[] vals) {
      Class_resolve_testpackagelist output = new Class_resolve_testpackagelist();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testpackagelist", // name
        0, // idx
        true, // async
        Vx_core.typedef_new(
          "vx/test", // pkgname
          "testpackagelist", // name
          ":list", // extends
          Vx_core.e_typelist, // traits
          Vx_core.vx_new(Vx_core.t_typelist, Vx_test.t_testpackage), // allowtypes
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
      return e_resolve_testpackagelist;
    }

    public override Vx_core.Type_any vx_type() {
      return t_resolve_testpackagelist;
    }

    public Vx_core.Func_any_from_any_async vx_fn_new(Vx_core.Class_any_from_any_async.IFn fn) {
      return Vx_core.e_any_from_any_async;
    }

    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      Vx_test.Type_testpackagelist inputval = Vx_core.f_any_from_any(Vx_test.t_testpackagelist, value);
      Task<Vx_test.Type_testpackagelist> future = Vx_test.f_resolve_testpackagelist(inputval);
      Task<T> output = (Task<T>)future;
      return output;
    }

    public Task<Vx_core.Type_any> vx_repl(Vx_core.Type_anylist arglist) {
      Task<Vx_core.Type_any> output = Vx_core.vx_async_new_completed(Vx_core.e_any);
      Vx_test.Type_testpackagelist testpackagelist = Vx_core.f_any_from_any(Vx_test.t_testpackagelist, arglist.vx_any(Vx_core.vx_new_int(0)));
      Task<Vx_test.Type_testpackagelist> future = Vx_test.f_resolve_testpackagelist(testpackagelist);
      output = Vx_core.vx_async_from_async(Vx_core.t_any, future);
      return output;
    }

    public Task<Vx_test.Type_testpackagelist> vx_resolve_testpackagelist(Vx_test.Type_testpackagelist testpackagelist) {
      return Vx_test.f_resolve_testpackagelist(testpackagelist);
    }

  }

  public static Func_resolve_testpackagelist e_resolve_testpackagelist = new Vx_test.Class_resolve_testpackagelist();
  public static Func_resolve_testpackagelist t_resolve_testpackagelist = new Vx_test.Class_resolve_testpackagelist();

  public static Task<Vx_test.Type_testpackagelist> f_resolve_testpackagelist(Vx_test.Type_testpackagelist testpackagelist) {
    Task<Vx_test.Type_testpackagelist> output = Vx_core.vx_async_new_completed(Vx_test.e_testpackagelist);
    output = Vx_core.f_list_from_list_async(
      Vx_test.t_testpackagelist,
      testpackagelist,
      Vx_test.t_resolve_testpackage
    );
    return output;
  }

  /**
   * 
   * @async
   * @function resolve_testresult
   * Resolves a testresult
   * @param  {testresult} testresult
   * @return {testresult}
   * (func resolve-testresult)
   */
  public interface Func_resolve_testresult : Vx_core.Func_any_from_any_async {
    public Task<Vx_test.Type_testresult> vx_resolve_testresult(Vx_test.Type_testresult testresult);
  }

  public class Class_resolve_testresult : Vx_core.Class_base, Func_resolve_testresult {

    public override Vx_test.Func_resolve_testresult vx_new(params Object[] vals) {
      Class_resolve_testresult output = new Class_resolve_testresult();
      return output;
    }

    public override Vx_test.Func_resolve_testresult vx_copy(params Object[] vals) {
      Class_resolve_testresult output = new Class_resolve_testresult();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testresult", // name
        0, // idx
        true, // async
        Vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_resolve_testresult;
    }

    public override Vx_core.Type_any vx_type() {
      return t_resolve_testresult;
    }

    public Vx_core.Func_any_from_any_async vx_fn_new(Vx_core.Class_any_from_any_async.IFn fn) {
      return Vx_core.e_any_from_any_async;
    }

    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      Vx_test.Type_testresult inputval = Vx_core.f_any_from_any(Vx_test.t_testresult, value);
      Task<Vx_test.Type_testresult> future = Vx_test.f_resolve_testresult(inputval);
      Task<T> output = (Task<T>)future;
      return output;
    }

    public Task<Vx_core.Type_any> vx_repl(Vx_core.Type_anylist arglist) {
      Task<Vx_core.Type_any> output = Vx_core.vx_async_new_completed(Vx_core.e_any);
      Vx_test.Type_testresult testresult = Vx_core.f_any_from_any(Vx_test.t_testresult, arglist.vx_any(Vx_core.vx_new_int(0)));
      Task<Vx_test.Type_testresult> future = Vx_test.f_resolve_testresult(testresult);
      output = Vx_core.vx_async_from_async(Vx_core.t_any, future);
      return output;
    }

    public Task<Vx_test.Type_testresult> vx_resolve_testresult(Vx_test.Type_testresult testresult) {
      return Vx_test.f_resolve_testresult(testresult);
    }

  }

  public static Func_resolve_testresult e_resolve_testresult = new Vx_test.Class_resolve_testresult();
  public static Func_resolve_testresult t_resolve_testresult = new Vx_test.Class_resolve_testresult();

  public static Task<Vx_test.Type_testresult> f_resolve_testresult(Vx_test.Type_testresult testresult) {
    Task<Vx_test.Type_testresult> output = Vx_core.vx_async_new_completed(Vx_test.e_testresult);
    output = Vx_core.f_let_async(
      Vx_test.t_testresult,
      Vx_core.t_any_from_func_async.vx_fn_new(() => {
        Vx_core.Func_any_from_func_async fn_actual = testresult.fn_actual();
        Vx_core.Type_any expected = testresult.expected();
        Task<Vx_core.Type_any> future_actual = Vx_core.f_resolve_async(Vx_core.t_any, fn_actual);
        return Vx_core.vx_async_from_async_fn(future_actual, (actual) => {
          return Vx_core.f_if_2(
            Vx_test.t_testresult,
            Vx_core.vx_new(Vx_core.t_thenelselist,
                  Vx_core.f_then(
                    Vx_core.t_boolean_from_func.vx_fn_new(() => {
                      return Vx_core.f_is_empty_1(fn_actual);
                    }),
                    Vx_core.t_any_from_func.vx_fn_new(() => {
                      return testresult;
                    })
                  ),
                  Vx_core.f_else(
                    Vx_core.t_any_from_func.vx_fn_new(() => {
                      return Vx_core.f_let(
                        Vx_test.t_testresult,
                        Vx_core.t_any_from_func.vx_fn_new(() => {
                          Vx_core.Type_boolean passfail = Vx_core.f_eq(expected, actual);
                          return Vx_core.f_copy(
                            testresult,
                            Vx_core.vx_new(Vx_core.t_anylist,
                              Vx_core.vx_new_string(":passfail"),
                              passfail,
                              Vx_core.vx_new_string(":actual"),
                              actual
                            )
                          );
                        })
                      );
                    })
                  )
            )
          );
        });
      })
    );
    return output;
  }

  /**
   * @function security_test
   * Returns the default security for test case execution. Arguments come from the command line.
   * @return {security}
   * (func security-test)
   */
  public interface Func_security_test : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_core.Type_security vx_security_test();
  }

  public class Class_security_test : Vx_core.Class_base, Func_security_test {

    public override Vx_test.Func_security_test vx_new(params Object[] vals) {
      Class_security_test output = new Class_security_test();
      return output;
    }

    public override Vx_test.Func_security_test vx_copy(params Object[] vals) {
      Class_security_test output = new Class_security_test();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "security-test", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "security", // name
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
      return e_security_test;
    }

    public override Vx_core.Type_any vx_type() {
      return t_security_test;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      output = Vx_test.f_security_test();
      return output;
    }

    public Vx_core.Type_security vx_security_test() {
      return Vx_test.f_security_test();
    }

  }

  public static Func_security_test e_security_test = new Vx_test.Class_security_test();
  public static Func_security_test t_security_test = new Vx_test.Class_security_test();

  public static Vx_core.Type_security f_security_test() {
    Vx_core.Type_security output = Vx_core.e_security;
    output = Vx_core.f_new(
      Vx_core.t_security,
      Vx_core.vx_new(Vx_core.t_anylist,
        Vx_core.vx_new_string(":allowfuncs"),
        Vx_core.f_new(
          Vx_core.t_funclist,
          Vx_core.vx_new(Vx_core.t_anylist,
            Vx_data_file.t_boolean_write_from_file_any,
            Vx_data_file.t_boolean_write_from_file_string,
            Vx_data_file.t_file_read_from_file,
            Vx_data_file.t_string_read_from_file
          )
        )
      )
    );
    return output;
  }

  /**
   * @function test
   * Test expected equal actual
   * @param  {any-1} expected
   * @param  {any-2} actual
   * @return {testresult}
   * (func test)
   */
  public interface Func_test : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_test.Type_testresult vx_test(Vx_core.Type_context context, Vx_core.Type_any expected, Vx_core.Type_any actual);
  }

  public class Class_test : Vx_core.Class_base, Func_test {

    public override Vx_test.Func_test vx_new(params Object[] vals) {
      Class_test output = new Class_test();
      return output;
    }

    public override Vx_test.Func_test vx_copy(params Object[] vals) {
      Class_test output = new Class_test();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "test", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_test;
    }

    public override Vx_core.Type_any vx_type() {
      return t_test;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_any expected = Vx_core.f_any_from_any(Vx_core.t_any, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_any actual = Vx_core.f_any_from_any(Vx_core.t_any, arglist.vx_any(Vx_core.vx_new_int(1)));
      output = Vx_test.f_test(context, expected, actual);
      return output;
    }

    public Vx_test.Type_testresult vx_test(Vx_core.Type_context context, Vx_core.Type_any expected, Vx_core.Type_any actual) {
      return Vx_test.f_test(context, expected, actual);
    }

  }

  public static Func_test e_test = new Vx_test.Class_test();
  public static Func_test t_test = new Vx_test.Class_test();

  public static Vx_test.Type_testresult f_test(Vx_core.Type_context context, Vx_core.Type_any expected, Vx_core.Type_any actual) {
    Vx_test.Type_testresult output = Vx_test.e_testresult;
    try {
      output = Vx_core.f_new(
        Vx_test.t_testresult,
        Vx_core.vx_new(Vx_core.t_anylist,
          Vx_core.vx_new_string(":code"),
          Vx_core.vx_new_string(":eq"),
          Vx_core.vx_new_string(":passfail"),
          Vx_core.f_eq(expected, actual),
          Vx_core.vx_new_string(":expected"),
          expected,
          Vx_core.vx_new_string(":actual"),
          actual
        )
      );
    } catch (Exception err) {
      Vx_core.Type_msg msg = Vx_core.vx_msg_from_exception("vx/test/test", err);
      output = Vx_core.vx_copy(output, msg);
    }
    return output;
  }

  /**
   * @function test 1
   * Async Test expected equal actual
   * @param  {any} expected
   * @param  {any<-func-async} fn-actual
   * @return {testresult}
   * (func test)
   */
  public interface Func_test_1 : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_test.Type_testresult vx_test_1(Vx_core.Type_context context, Vx_core.Type_any expected, Vx_core.Func_any_from_func_async fn_actual);
  }

  public class Class_test_1 : Vx_core.Class_base, Func_test_1 {

    public override Vx_test.Func_test_1 vx_new(params Object[] vals) {
      Class_test_1 output = new Class_test_1();
      return output;
    }

    public override Vx_test.Func_test_1 vx_copy(params Object[] vals) {
      Class_test_1 output = new Class_test_1();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "test", // name
        1, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_test_1;
    }

    public override Vx_core.Type_any vx_type() {
      return t_test_1;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_any expected = Vx_core.f_any_from_any(Vx_core.t_any, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Func_any_from_func_async fn_actual = Vx_core.f_any_from_any(Vx_core.t_any_from_func_async, arglist.vx_any(Vx_core.vx_new_int(1)));
      output = Vx_test.f_test_1(context, expected, fn_actual);
      return output;
    }

    public Vx_test.Type_testresult vx_test_1(Vx_core.Type_context context, Vx_core.Type_any expected, Vx_core.Func_any_from_func_async fn_actual) {
      return Vx_test.f_test_1(context, expected, fn_actual);
    }

  }

  public static Func_test_1 e_test_1 = new Vx_test.Class_test_1();
  public static Func_test_1 t_test_1 = new Vx_test.Class_test_1();

  public static Vx_test.Type_testresult f_test_1(Vx_core.Type_context context, Vx_core.Type_any expected, Vx_core.Func_any_from_func_async fn_actual) {
    Vx_test.Type_testresult output = Vx_test.e_testresult;
    try {
      output = Vx_core.f_new(
        Vx_test.t_testresult,
        Vx_core.vx_new(Vx_core.t_anylist,
          Vx_core.vx_new_string(":code"),
          Vx_core.vx_new_string(":eq"),
          Vx_core.vx_new_string(":expected"),
          expected,
          Vx_core.vx_new_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (Exception err) {
      Vx_core.Type_msg msg = Vx_core.vx_msg_from_exception("vx/test/test", err);
      output = Vx_core.vx_copy(output, msg);
    }
    return output;
  }

  /**
   * @function test_false
   * Test expected to be false
   * @param  {any} actual
   * @return {testresult}
   * (func test-false)
   */
  public interface Func_test_false : Vx_core.Func_any_from_any_context {
    public Vx_test.Type_testresult vx_test_false(Vx_core.Type_context context, Vx_core.Type_any actual);
  }

  public class Class_test_false : Vx_core.Class_base, Func_test_false {

    public override Vx_test.Func_test_false vx_new(params Object[] vals) {
      Class_test_false output = new Class_test_false();
      return output;
    }

    public override Vx_test.Func_test_false vx_copy(params Object[] vals) {
      Class_test_false output = new Class_test_false();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "test-false", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_test_false;
    }

    public override Vx_core.Type_any vx_type() {
      return t_test_false;
    }

    public Vx_core.Func_any_from_any_context vx_fn_new(Vx_core.Class_any_from_any_context.IFn fn) {
      return Vx_core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx_core.Type_context context, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_core.Type_any inputval = (Vx_core.Type_any)value;
      Vx_core.Type_any outputval = Vx_test.f_test_false(context, inputval);
      output = Vx_core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_any actual = Vx_core.f_any_from_any(Vx_core.t_any, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_test.f_test_false(context, actual);
      return output;
    }

    public Vx_test.Type_testresult vx_test_false(Vx_core.Type_context context, Vx_core.Type_any actual) {
      return Vx_test.f_test_false(context, actual);
    }

  }

  public static Func_test_false e_test_false = new Vx_test.Class_test_false();
  public static Func_test_false t_test_false = new Vx_test.Class_test_false();

  public static Vx_test.Type_testresult f_test_false(Vx_core.Type_context context, Vx_core.Type_any actual) {
    Vx_test.Type_testresult output = Vx_test.e_testresult;
    try {
      output = Vx_core.f_new(
        Vx_test.t_testresult,
        Vx_core.vx_new(Vx_core.t_anylist,
          Vx_core.vx_new_string(":code"),
          Vx_core.vx_new_string(":false"),
          Vx_core.vx_new_string(":passfail"),
          Vx_core.f_eq(
            Vx_core.vx_new_boolean(false),
            actual
          ),
          Vx_core.vx_new_string(":expected"),
          Vx_core.vx_new_boolean(false),
          Vx_core.vx_new_string(":actual"),
          actual
        )
      );
    } catch (Exception err) {
      Vx_core.Type_msg msg = Vx_core.vx_msg_from_exception("vx/test/test-false", err);
      output = Vx_core.vx_copy(output, msg);
    }
    return output;
  }

  /**
   * @function test_false 1
   * Async Test expected to be false
   * @param  {any<-func-async} fn-actual
   * @return {testresult}
   * (func test-false)
   */
  public interface Func_test_false_1 : Vx_core.Func_any_from_any_context {
    public Vx_test.Type_testresult vx_test_false_1(Vx_core.Type_context context, Vx_core.Func_any_from_func_async fn_actual);
  }

  public class Class_test_false_1 : Vx_core.Class_base, Func_test_false_1 {

    public override Vx_test.Func_test_false_1 vx_new(params Object[] vals) {
      Class_test_false_1 output = new Class_test_false_1();
      return output;
    }

    public override Vx_test.Func_test_false_1 vx_copy(params Object[] vals) {
      Class_test_false_1 output = new Class_test_false_1();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "test-false", // name
        1, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_test_false_1;
    }

    public override Vx_core.Type_any vx_type() {
      return t_test_false_1;
    }

    public Vx_core.Func_any_from_any_context vx_fn_new(Vx_core.Class_any_from_any_context.IFn fn) {
      return Vx_core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx_core.Type_context context, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_core.Func_any_from_func_async inputval = (Vx_core.Func_any_from_func_async)value;
      Vx_core.Type_any outputval = Vx_test.f_test_false_1(context, inputval);
      output = Vx_core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Func_any_from_func_async fn_actual = Vx_core.f_any_from_any(Vx_core.t_any_from_func_async, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_test.f_test_false_1(context, fn_actual);
      return output;
    }

    public Vx_test.Type_testresult vx_test_false_1(Vx_core.Type_context context, Vx_core.Func_any_from_func_async fn_actual) {
      return Vx_test.f_test_false_1(context, fn_actual);
    }

  }

  public static Func_test_false_1 e_test_false_1 = new Vx_test.Class_test_false_1();
  public static Func_test_false_1 t_test_false_1 = new Vx_test.Class_test_false_1();

  public static Vx_test.Type_testresult f_test_false_1(Vx_core.Type_context context, Vx_core.Func_any_from_func_async fn_actual) {
    Vx_test.Type_testresult output = Vx_test.e_testresult;
    try {
      output = Vx_core.f_new(
        Vx_test.t_testresult,
        Vx_core.vx_new(Vx_core.t_anylist,
          Vx_core.vx_new_string(":code"),
          Vx_core.vx_new_string(":false"),
          Vx_core.vx_new_string(":expected"),
          Vx_core.vx_new_boolean(false),
          Vx_core.vx_new_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (Exception err) {
      Vx_core.Type_msg msg = Vx_core.vx_msg_from_exception("vx/test/test-false", err);
      output = Vx_core.vx_copy(output, msg);
    }
    return output;
  }

  /**
   * @function test_gt
   * Test expected greater than actual
   * @param  {any} expected
   * @param  {any} actual
   * @return {testresult}
   * (func test-gt)
   */
  public interface Func_test_gt : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_test.Type_testresult vx_test_gt(Vx_core.Type_context context, Vx_core.Type_any expected, Vx_core.Type_any actual);
  }

  public class Class_test_gt : Vx_core.Class_base, Func_test_gt {

    public override Vx_test.Func_test_gt vx_new(params Object[] vals) {
      Class_test_gt output = new Class_test_gt();
      return output;
    }

    public override Vx_test.Func_test_gt vx_copy(params Object[] vals) {
      Class_test_gt output = new Class_test_gt();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "test-gt", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_test_gt;
    }

    public override Vx_core.Type_any vx_type() {
      return t_test_gt;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_any expected = Vx_core.f_any_from_any(Vx_core.t_any, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_any actual = Vx_core.f_any_from_any(Vx_core.t_any, arglist.vx_any(Vx_core.vx_new_int(1)));
      output = Vx_test.f_test_gt(context, expected, actual);
      return output;
    }

    public Vx_test.Type_testresult vx_test_gt(Vx_core.Type_context context, Vx_core.Type_any expected, Vx_core.Type_any actual) {
      return Vx_test.f_test_gt(context, expected, actual);
    }

  }

  public static Func_test_gt e_test_gt = new Vx_test.Class_test_gt();
  public static Func_test_gt t_test_gt = new Vx_test.Class_test_gt();

  public static Vx_test.Type_testresult f_test_gt(Vx_core.Type_context context, Vx_core.Type_any expected, Vx_core.Type_any actual) {
    Vx_test.Type_testresult output = Vx_test.e_testresult;
    try {
      output = Vx_core.f_new(
        Vx_test.t_testresult,
        Vx_core.vx_new(Vx_core.t_anylist,
          Vx_core.vx_new_string(":code"),
          Vx_core.vx_new_string(":gt"),
          Vx_core.vx_new_string(":passfail"),
          Vx_core.f_gt(expected, actual),
          Vx_core.vx_new_string(":expected"),
          expected,
          Vx_core.vx_new_string(":actual"),
          actual
        )
      );
    } catch (Exception err) {
      Vx_core.Type_msg msg = Vx_core.vx_msg_from_exception("vx/test/test-gt", err);
      output = Vx_core.vx_copy(output, msg);
    }
    return output;
  }

  /**
   * @function test_gt 1
   * Async Test expected greater than actual
   * @param  {any} expected
   * @param  {any<-func-async} fn-actual
   * @return {testresult}
   * (func test-gt)
   */
  public interface Func_test_gt_1 : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_test.Type_testresult vx_test_gt_1(Vx_core.Type_context context, Vx_core.Type_any expected, Vx_core.Func_any_from_func_async fn_actual);
  }

  public class Class_test_gt_1 : Vx_core.Class_base, Func_test_gt_1 {

    public override Vx_test.Func_test_gt_1 vx_new(params Object[] vals) {
      Class_test_gt_1 output = new Class_test_gt_1();
      return output;
    }

    public override Vx_test.Func_test_gt_1 vx_copy(params Object[] vals) {
      Class_test_gt_1 output = new Class_test_gt_1();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "test-gt", // name
        1, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_test_gt_1;
    }

    public override Vx_core.Type_any vx_type() {
      return t_test_gt_1;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_any expected = Vx_core.f_any_from_any(Vx_core.t_any, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Func_any_from_func_async fn_actual = Vx_core.f_any_from_any(Vx_core.t_any_from_func_async, arglist.vx_any(Vx_core.vx_new_int(1)));
      output = Vx_test.f_test_gt_1(context, expected, fn_actual);
      return output;
    }

    public Vx_test.Type_testresult vx_test_gt_1(Vx_core.Type_context context, Vx_core.Type_any expected, Vx_core.Func_any_from_func_async fn_actual) {
      return Vx_test.f_test_gt_1(context, expected, fn_actual);
    }

  }

  public static Func_test_gt_1 e_test_gt_1 = new Vx_test.Class_test_gt_1();
  public static Func_test_gt_1 t_test_gt_1 = new Vx_test.Class_test_gt_1();

  public static Vx_test.Type_testresult f_test_gt_1(Vx_core.Type_context context, Vx_core.Type_any expected, Vx_core.Func_any_from_func_async fn_actual) {
    Vx_test.Type_testresult output = Vx_test.e_testresult;
    try {
      output = Vx_core.f_new(
        Vx_test.t_testresult,
        Vx_core.vx_new(Vx_core.t_anylist,
          Vx_core.vx_new_string(":code"),
          Vx_core.vx_new_string(":gt"),
          Vx_core.vx_new_string(":expected"),
          expected,
          Vx_core.vx_new_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (Exception err) {
      Vx_core.Type_msg msg = Vx_core.vx_msg_from_exception("vx/test/test-gt", err);
      output = Vx_core.vx_copy(output, msg);
    }
    return output;
  }

  /**
   * @function test_ne
   * Test expected not equal actual
   * @param  {any} expected
   * @param  {any} actual
   * @return {testresult}
   * (func test-ne)
   */
  public interface Func_test_ne : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_test.Type_testresult vx_test_ne(Vx_core.Type_context context, Vx_core.Type_any expected, Vx_core.Type_any actual);
  }

  public class Class_test_ne : Vx_core.Class_base, Func_test_ne {

    public override Vx_test.Func_test_ne vx_new(params Object[] vals) {
      Class_test_ne output = new Class_test_ne();
      return output;
    }

    public override Vx_test.Func_test_ne vx_copy(params Object[] vals) {
      Class_test_ne output = new Class_test_ne();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "test-ne", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_test_ne;
    }

    public override Vx_core.Type_any vx_type() {
      return t_test_ne;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_any expected = Vx_core.f_any_from_any(Vx_core.t_any, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_any actual = Vx_core.f_any_from_any(Vx_core.t_any, arglist.vx_any(Vx_core.vx_new_int(1)));
      output = Vx_test.f_test_ne(context, expected, actual);
      return output;
    }

    public Vx_test.Type_testresult vx_test_ne(Vx_core.Type_context context, Vx_core.Type_any expected, Vx_core.Type_any actual) {
      return Vx_test.f_test_ne(context, expected, actual);
    }

  }

  public static Func_test_ne e_test_ne = new Vx_test.Class_test_ne();
  public static Func_test_ne t_test_ne = new Vx_test.Class_test_ne();

  public static Vx_test.Type_testresult f_test_ne(Vx_core.Type_context context, Vx_core.Type_any expected, Vx_core.Type_any actual) {
    Vx_test.Type_testresult output = Vx_test.e_testresult;
    try {
      output = Vx_core.f_new(
        Vx_test.t_testresult,
        Vx_core.vx_new(Vx_core.t_anylist,
          Vx_core.vx_new_string(":code"),
          Vx_core.vx_new_string(":ne"),
          Vx_core.vx_new_string(":passfail"),
          Vx_core.f_ne(expected, actual),
          Vx_core.vx_new_string(":expected"),
          expected,
          Vx_core.vx_new_string(":actual"),
          actual
        )
      );
    } catch (Exception err) {
      Vx_core.Type_msg msg = Vx_core.vx_msg_from_exception("vx/test/test-ne", err);
      output = Vx_core.vx_copy(output, msg);
    }
    return output;
  }

  /**
   * @function test_ne 1
   * Async Test expected not equal actual
   * @param  {any} expected
   * @param  {any<-func-async} fn-actual
   * @return {testresult}
   * (func test-ne)
   */
  public interface Func_test_ne_1 : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_test.Type_testresult vx_test_ne_1(Vx_core.Type_context context, Vx_core.Type_any expected, Vx_core.Func_any_from_func_async fn_actual);
  }

  public class Class_test_ne_1 : Vx_core.Class_base, Func_test_ne_1 {

    public override Vx_test.Func_test_ne_1 vx_new(params Object[] vals) {
      Class_test_ne_1 output = new Class_test_ne_1();
      return output;
    }

    public override Vx_test.Func_test_ne_1 vx_copy(params Object[] vals) {
      Class_test_ne_1 output = new Class_test_ne_1();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "test-ne", // name
        1, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_test_ne_1;
    }

    public override Vx_core.Type_any vx_type() {
      return t_test_ne_1;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_any expected = Vx_core.f_any_from_any(Vx_core.t_any, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Func_any_from_func_async fn_actual = Vx_core.f_any_from_any(Vx_core.t_any_from_func_async, arglist.vx_any(Vx_core.vx_new_int(1)));
      output = Vx_test.f_test_ne_1(context, expected, fn_actual);
      return output;
    }

    public Vx_test.Type_testresult vx_test_ne_1(Vx_core.Type_context context, Vx_core.Type_any expected, Vx_core.Func_any_from_func_async fn_actual) {
      return Vx_test.f_test_ne_1(context, expected, fn_actual);
    }

  }

  public static Func_test_ne_1 e_test_ne_1 = new Vx_test.Class_test_ne_1();
  public static Func_test_ne_1 t_test_ne_1 = new Vx_test.Class_test_ne_1();

  public static Vx_test.Type_testresult f_test_ne_1(Vx_core.Type_context context, Vx_core.Type_any expected, Vx_core.Func_any_from_func_async fn_actual) {
    Vx_test.Type_testresult output = Vx_test.e_testresult;
    try {
      output = Vx_core.f_new(
        Vx_test.t_testresult,
        Vx_core.vx_new(Vx_core.t_anylist,
          Vx_core.vx_new_string(":code"),
          Vx_core.vx_new_string(":ne"),
          Vx_core.vx_new_string(":expected"),
          expected,
          Vx_core.vx_new_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (Exception err) {
      Vx_core.Type_msg msg = Vx_core.vx_msg_from_exception("vx/test/test-ne", err);
      output = Vx_core.vx_copy(output, msg);
    }
    return output;
  }

  /**
   * @function test_string
   * Test that the string version of expected equal actual
   * @param  {any} expected
   * @param  {any} actual
   * @return {testresult}
   * (func test-string)
   */
  public interface Func_test_string : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_test.Type_testresult vx_test_string(Vx_core.Type_context context, Vx_core.Type_any expected, Vx_core.Type_any actual);
  }

  public class Class_test_string : Vx_core.Class_base, Func_test_string {

    public override Vx_test.Func_test_string vx_new(params Object[] vals) {
      Class_test_string output = new Class_test_string();
      return output;
    }

    public override Vx_test.Func_test_string vx_copy(params Object[] vals) {
      Class_test_string output = new Class_test_string();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "test-string", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_test_string;
    }

    public override Vx_core.Type_any vx_type() {
      return t_test_string;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_any expected = Vx_core.f_any_from_any(Vx_core.t_any, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_any actual = Vx_core.f_any_from_any(Vx_core.t_any, arglist.vx_any(Vx_core.vx_new_int(1)));
      output = Vx_test.f_test_string(context, expected, actual);
      return output;
    }

    public Vx_test.Type_testresult vx_test_string(Vx_core.Type_context context, Vx_core.Type_any expected, Vx_core.Type_any actual) {
      return Vx_test.f_test_string(context, expected, actual);
    }

  }

  public static Func_test_string e_test_string = new Vx_test.Class_test_string();
  public static Func_test_string t_test_string = new Vx_test.Class_test_string();

  public static Vx_test.Type_testresult f_test_string(Vx_core.Type_context context, Vx_core.Type_any expected, Vx_core.Type_any actual) {
    Vx_test.Type_testresult output = Vx_test.e_testresult;
    try {
      output = Vx_core.f_new(
        Vx_test.t_testresult,
        Vx_core.vx_new(Vx_core.t_anylist,
          Vx_core.vx_new_string(":passfail"),
          Vx_core.f_eq(
            Vx_core.f_string_from_any(expected),
            Vx_core.f_string_from_any(actual)
          ),
          Vx_core.vx_new_string(":expected"),
          expected,
          Vx_core.vx_new_string(":actual"),
          actual
        )
      );
    } catch (Exception err) {
      Vx_core.Type_msg msg = Vx_core.vx_msg_from_exception("vx/test/test-string", err);
      output = Vx_core.vx_copy(output, msg);
    }
    return output;
  }

  /**
   * @function test_string 1
   * Async Test that the string version of expected equal actual
   * @param  {any} expected
   * @param  {any<-func-async} fn-actual
   * @return {testresult}
   * (func test-string)
   */
  public interface Func_test_string_1 : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_test.Type_testresult vx_test_string_1(Vx_core.Type_context context, Vx_core.Type_any expected, Vx_core.Func_any_from_func_async fn_actual);
  }

  public class Class_test_string_1 : Vx_core.Class_base, Func_test_string_1 {

    public override Vx_test.Func_test_string_1 vx_new(params Object[] vals) {
      Class_test_string_1 output = new Class_test_string_1();
      return output;
    }

    public override Vx_test.Func_test_string_1 vx_copy(params Object[] vals) {
      Class_test_string_1 output = new Class_test_string_1();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "test-string", // name
        1, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_test_string_1;
    }

    public override Vx_core.Type_any vx_type() {
      return t_test_string_1;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_any expected = Vx_core.f_any_from_any(Vx_core.t_any, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Func_any_from_func_async fn_actual = Vx_core.f_any_from_any(Vx_core.t_any_from_func_async, arglist.vx_any(Vx_core.vx_new_int(1)));
      output = Vx_test.f_test_string_1(context, expected, fn_actual);
      return output;
    }

    public Vx_test.Type_testresult vx_test_string_1(Vx_core.Type_context context, Vx_core.Type_any expected, Vx_core.Func_any_from_func_async fn_actual) {
      return Vx_test.f_test_string_1(context, expected, fn_actual);
    }

  }

  public static Func_test_string_1 e_test_string_1 = new Vx_test.Class_test_string_1();
  public static Func_test_string_1 t_test_string_1 = new Vx_test.Class_test_string_1();

  public static Vx_test.Type_testresult f_test_string_1(Vx_core.Type_context context, Vx_core.Type_any expected, Vx_core.Func_any_from_func_async fn_actual) {
    Vx_test.Type_testresult output = Vx_test.e_testresult;
    try {
      output = Vx_core.f_new(
        Vx_test.t_testresult,
        Vx_core.vx_new(Vx_core.t_anylist,
          Vx_core.vx_new_string(":code"),
          Vx_core.vx_new_string(":string"),
          Vx_core.vx_new_string(":expected"),
          expected,
          Vx_core.vx_new_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (Exception err) {
      Vx_core.Type_msg msg = Vx_core.vx_msg_from_exception("vx/test/test-string", err);
      output = Vx_core.vx_copy(output, msg);
    }
    return output;
  }

  /**
   * @function test_true
   * Test expected to be true
   * @param  {any} actual
   * @return {testresult}
   * (func test-true)
   */
  public interface Func_test_true : Vx_core.Func_any_from_any_context {
    public Vx_test.Type_testresult vx_test_true(Vx_core.Type_context context, Vx_core.Type_any actual);
  }

  public class Class_test_true : Vx_core.Class_base, Func_test_true {

    public override Vx_test.Func_test_true vx_new(params Object[] vals) {
      Class_test_true output = new Class_test_true();
      return output;
    }

    public override Vx_test.Func_test_true vx_copy(params Object[] vals) {
      Class_test_true output = new Class_test_true();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "test-true", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_test_true;
    }

    public override Vx_core.Type_any vx_type() {
      return t_test_true;
    }

    public Vx_core.Func_any_from_any_context vx_fn_new(Vx_core.Class_any_from_any_context.IFn fn) {
      return Vx_core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx_core.Type_context context, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_core.Type_any inputval = (Vx_core.Type_any)value;
      Vx_core.Type_any outputval = Vx_test.f_test_true(context, inputval);
      output = Vx_core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_any actual = Vx_core.f_any_from_any(Vx_core.t_any, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_test.f_test_true(context, actual);
      return output;
    }

    public Vx_test.Type_testresult vx_test_true(Vx_core.Type_context context, Vx_core.Type_any actual) {
      return Vx_test.f_test_true(context, actual);
    }

  }

  public static Func_test_true e_test_true = new Vx_test.Class_test_true();
  public static Func_test_true t_test_true = new Vx_test.Class_test_true();

  public static Vx_test.Type_testresult f_test_true(Vx_core.Type_context context, Vx_core.Type_any actual) {
    Vx_test.Type_testresult output = Vx_test.e_testresult;
    try {
      output = Vx_core.f_new(
        Vx_test.t_testresult,
        Vx_core.vx_new(Vx_core.t_anylist,
          Vx_core.vx_new_string(":code"),
          Vx_core.vx_new_string(":true"),
          Vx_core.vx_new_string(":passfail"),
          Vx_core.f_eq(
            Vx_core.vx_new_boolean(true),
            actual
          ),
          Vx_core.vx_new_string(":expected"),
          Vx_core.vx_new_boolean(true),
          Vx_core.vx_new_string(":actual"),
          actual
        )
      );
    } catch (Exception err) {
      Vx_core.Type_msg msg = Vx_core.vx_msg_from_exception("vx/test/test-true", err);
      output = Vx_core.vx_copy(output, msg);
    }
    return output;
  }

  /**
   * @function test_true 1
   * Async Test expected to be true
   * @param  {any<-func-async} fn-actual
   * @return {testresult}
   * (func test-true)
   */
  public interface Func_test_true_1 : Vx_core.Func_any_from_any_context {
    public Vx_test.Type_testresult vx_test_true_1(Vx_core.Type_context context, Vx_core.Func_any_from_func_async fn_actual);
  }

  public class Class_test_true_1 : Vx_core.Class_base, Func_test_true_1 {

    public override Vx_test.Func_test_true_1 vx_new(params Object[] vals) {
      Class_test_true_1 output = new Class_test_true_1();
      return output;
    }

    public override Vx_test.Func_test_true_1 vx_copy(params Object[] vals) {
      Class_test_true_1 output = new Class_test_true_1();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "test-true", // name
        1, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_test_true_1;
    }

    public override Vx_core.Type_any vx_type() {
      return t_test_true_1;
    }

    public Vx_core.Func_any_from_any_context vx_fn_new(Vx_core.Class_any_from_any_context.IFn fn) {
      return Vx_core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx_core.Type_context context, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_core.Func_any_from_func_async inputval = (Vx_core.Func_any_from_func_async)value;
      Vx_core.Type_any outputval = Vx_test.f_test_true_1(context, inputval);
      output = Vx_core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Func_any_from_func_async fn_actual = Vx_core.f_any_from_any(Vx_core.t_any_from_func_async, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_test.f_test_true_1(context, fn_actual);
      return output;
    }

    public Vx_test.Type_testresult vx_test_true_1(Vx_core.Type_context context, Vx_core.Func_any_from_func_async fn_actual) {
      return Vx_test.f_test_true_1(context, fn_actual);
    }

  }

  public static Func_test_true_1 e_test_true_1 = new Vx_test.Class_test_true_1();
  public static Func_test_true_1 t_test_true_1 = new Vx_test.Class_test_true_1();

  public static Vx_test.Type_testresult f_test_true_1(Vx_core.Type_context context, Vx_core.Func_any_from_func_async fn_actual) {
    Vx_test.Type_testresult output = Vx_test.e_testresult;
    try {
      output = Vx_core.f_new(
        Vx_test.t_testresult,
        Vx_core.vx_new(Vx_core.t_anylist,
          Vx_core.vx_new_string(":code"),
          Vx_core.vx_new_string(":true"),
          Vx_core.vx_new_string(":expected"),
          Vx_core.vx_new_boolean(true),
          Vx_core.vx_new_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (Exception err) {
      Vx_core.Type_msg msg = Vx_core.vx_msg_from_exception("vx/test/test-true", err);
      output = Vx_core.vx_copy(output, msg);
    }
    return output;
  }

  /**
   * @function tr_from_testdescribe_casename
   * Returns tr from a testdescribe
   * @param  {testdescribe} testdescribe
   * @param  {string} casename
   * @return {tr}
   * (func tr<-testdescribe-casename)
   */
  public interface Func_tr_from_testdescribe_casename : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_web_html.Type_tr vx_tr_from_testdescribe_casename(Vx_test.Type_testdescribe testdescribe, Vx_core.Type_string casename);
  }

  public class Class_tr_from_testdescribe_casename : Vx_core.Class_base, Func_tr_from_testdescribe_casename {

    public override Vx_test.Func_tr_from_testdescribe_casename vx_new(params Object[] vals) {
      Class_tr_from_testdescribe_casename output = new Class_tr_from_testdescribe_casename();
      return output;
    }

    public override Vx_test.Func_tr_from_testdescribe_casename vx_copy(params Object[] vals) {
      Class_tr_from_testdescribe_casename output = new Class_tr_from_testdescribe_casename();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "tr<-testdescribe-casename", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/web/html", // pkgname
          "tr", // name
          ":struct", // extends
          Vx_core.vx_new(Vx_core.t_typelist, Vx_web_html.t_node), // traits
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
      return e_tr_from_testdescribe_casename;
    }

    public override Vx_core.Type_any vx_type() {
      return t_tr_from_testdescribe_casename;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_test.Type_testdescribe testdescribe = Vx_core.f_any_from_any(Vx_test.t_testdescribe, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_string casename = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(1)));
      output = Vx_test.f_tr_from_testdescribe_casename(testdescribe, casename);
      return output;
    }

    public Vx_web_html.Type_tr vx_tr_from_testdescribe_casename(Vx_test.Type_testdescribe testdescribe, Vx_core.Type_string casename) {
      return Vx_test.f_tr_from_testdescribe_casename(testdescribe, casename);
    }

  }

  public static Func_tr_from_testdescribe_casename e_tr_from_testdescribe_casename = new Vx_test.Class_tr_from_testdescribe_casename();
  public static Func_tr_from_testdescribe_casename t_tr_from_testdescribe_casename = new Vx_test.Class_tr_from_testdescribe_casename();

  public static Vx_web_html.Type_tr f_tr_from_testdescribe_casename(Vx_test.Type_testdescribe testdescribe, Vx_core.Type_string casename) {
    Vx_web_html.Type_tr output = Vx_web_html.e_tr;
    output = Vx_core.f_let(
      Vx_web_html.t_tr,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_core.Type_string describename = testdescribe.describename();
        Vx_test.Type_testresult result = testdescribe.testresult();
        Vx_core.Type_boolean passfail = result.passfail();
        Vx_core.Type_string expected = Vx_core.f_string_from_any(
          result.expected()
        );
        Vx_core.Type_string actual = Vx_core.f_string_from_any(
          result.actual()
        );
        Vx_web_html.Type_style prestyle = Vx_web_html.f_style_from_stylesheet_name(
          Vx_test.c_stylesheet_test,
          Vx_core.vx_new_string(".preformatted")
        );
        return Vx_core.f_new(
          Vx_web_html.t_tr,
          Vx_core.vx_new(Vx_core.t_anylist,
            Vx_core.f_new(
              Vx_web_html.t_td,
              Vx_core.vx_new(Vx_core.t_anylist,
                Vx_test.f_p_from_passfail(passfail)
              )
            ),
            Vx_core.f_new(
              Vx_web_html.t_td,
              Vx_core.vx_new(Vx_core.t_anylist,
                Vx_core.f_new(
                  Vx_web_html.t_p,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":style"),
                    prestyle,
                    Vx_core.vx_new_string(":text"),
                    casename
                  )
                )
              )
            ),
            Vx_core.f_new(
              Vx_web_html.t_td,
              Vx_core.vx_new(Vx_core.t_anylist,
                Vx_core.f_new(
                  Vx_web_html.t_p,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":style"),
                    prestyle,
                    Vx_core.vx_new_string(":text"),
                    describename
                  )
                )
              )
            ),
            Vx_core.f_new(
              Vx_web_html.t_td,
              Vx_core.vx_new(Vx_core.t_anylist,
                Vx_core.f_new(
                  Vx_web_html.t_p,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":style"),
                    prestyle,
                    Vx_core.vx_new_string(":text"),
                    expected
                  )
                )
              )
            ),
            Vx_core.f_new(
              Vx_web_html.t_td,
              Vx_core.vx_new(Vx_core.t_anylist,
                Vx_core.f_new(
                  Vx_web_html.t_p,
                  Vx_core.vx_new(Vx_core.t_anylist,
                    Vx_core.vx_new_string(":style"),
                    prestyle,
                    Vx_core.vx_new_string(":text"),
                    actual
                  )
                )
              )
            )
          )
        );
      })
    );
    return output;
  }

  /**
   * @function trlist_from_testcase
   * @param  {testcase} testcase
   * @return {trlist}
   * (func trlist<-testcase)
   */
  public interface Func_trlist_from_testcase : Vx_core.Func_any_from_any {
    public Vx_web_html.Type_trlist vx_trlist_from_testcase(Vx_test.Type_testcase testcase);
  }

  public class Class_trlist_from_testcase : Vx_core.Class_base, Func_trlist_from_testcase {

    public override Vx_test.Func_trlist_from_testcase vx_new(params Object[] vals) {
      Class_trlist_from_testcase output = new Class_trlist_from_testcase();
      return output;
    }

    public override Vx_test.Func_trlist_from_testcase vx_copy(params Object[] vals) {
      Class_trlist_from_testcase output = new Class_trlist_from_testcase();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "trlist<-testcase", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/web/html", // pkgname
          "trlist", // name
          ":list", // extends
          Vx_core.e_typelist, // traits
          Vx_core.vx_new(Vx_core.t_typelist, Vx_web_html.t_tr), // allowtypes
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
      return e_trlist_from_testcase;
    }

    public override Vx_core.Type_any vx_type() {
      return t_trlist_from_testcase;
    }

    public Vx_core.Func_any_from_any vx_fn_new(Vx_core.Class_any_from_any.IFn fn) {
      return Vx_core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_test.Type_testcase inputval = (Vx_test.Type_testcase)value;
      Vx_core.Type_any outputval = Vx_test.f_trlist_from_testcase(inputval);
      output = Vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_test.Type_testcase testcase = Vx_core.f_any_from_any(Vx_test.t_testcase, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_test.f_trlist_from_testcase(testcase);
      return output;
    }

    public Vx_web_html.Type_trlist vx_trlist_from_testcase(Vx_test.Type_testcase testcase) {
      return Vx_test.f_trlist_from_testcase(testcase);
    }

  }

  public static Func_trlist_from_testcase e_trlist_from_testcase = new Vx_test.Class_trlist_from_testcase();
  public static Func_trlist_from_testcase t_trlist_from_testcase = new Vx_test.Class_trlist_from_testcase();

  public static Vx_web_html.Type_trlist f_trlist_from_testcase(Vx_test.Type_testcase testcase) {
    Vx_web_html.Type_trlist output = Vx_web_html.e_trlist;
    output = Vx_core.f_let(
      Vx_web_html.t_trlist,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_test.Type_testdescribelist describelist = testcase.describelist();
        Vx_core.Type_string casename = testcase.casename();
        return Vx_core.f_list_from_list_1(
          Vx_web_html.t_trlist,
          describelist,
          Vx_core.t_any_from_any.vx_fn_new((testdescribe_any) => {
            Vx_test.Type_testdescribe testdescribe = Vx_core.f_any_from_any(Vx_test.t_testdescribe, testdescribe_any);
            return 
            Vx_test.f_tr_from_testdescribe_casename(testdescribe, casename);
          })
        );
      })
    );
    return output;
  }

  /**
   * @function trlist_from_testcaselist
   * Returns a trlist from a testcaselist.
   * @param  {testcaselist} testcaselist
   * @return {trlist}
   * (func trlist<-testcaselist)
   */
  public interface Func_trlist_from_testcaselist : Vx_core.Func_any_from_any {
    public Vx_web_html.Type_trlist vx_trlist_from_testcaselist(Vx_test.Type_testcaselist testcaselist);
  }

  public class Class_trlist_from_testcaselist : Vx_core.Class_base, Func_trlist_from_testcaselist {

    public override Vx_test.Func_trlist_from_testcaselist vx_new(params Object[] vals) {
      Class_trlist_from_testcaselist output = new Class_trlist_from_testcaselist();
      return output;
    }

    public override Vx_test.Func_trlist_from_testcaselist vx_copy(params Object[] vals) {
      Class_trlist_from_testcaselist output = new Class_trlist_from_testcaselist();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/test", // pkgname
        "trlist<-testcaselist", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/web/html", // pkgname
          "trlist", // name
          ":list", // extends
          Vx_core.e_typelist, // traits
          Vx_core.vx_new(Vx_core.t_typelist, Vx_web_html.t_tr), // allowtypes
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
      return e_trlist_from_testcaselist;
    }

    public override Vx_core.Type_any vx_type() {
      return t_trlist_from_testcaselist;
    }

    public Vx_core.Func_any_from_any vx_fn_new(Vx_core.Class_any_from_any.IFn fn) {
      return Vx_core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_test.Type_testcaselist inputval = (Vx_test.Type_testcaselist)value;
      Vx_core.Type_any outputval = Vx_test.f_trlist_from_testcaselist(inputval);
      output = Vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_test.Type_testcaselist testcaselist = Vx_core.f_any_from_any(Vx_test.t_testcaselist, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_test.f_trlist_from_testcaselist(testcaselist);
      return output;
    }

    public Vx_web_html.Type_trlist vx_trlist_from_testcaselist(Vx_test.Type_testcaselist testcaselist) {
      return Vx_test.f_trlist_from_testcaselist(testcaselist);
    }

  }

  public static Func_trlist_from_testcaselist e_trlist_from_testcaselist = new Vx_test.Class_trlist_from_testcaselist();
  public static Func_trlist_from_testcaselist t_trlist_from_testcaselist = new Vx_test.Class_trlist_from_testcaselist();

  public static Vx_web_html.Type_trlist f_trlist_from_testcaselist(Vx_test.Type_testcaselist testcaselist) {
    Vx_web_html.Type_trlist output = Vx_web_html.e_trlist;
    output = Vx_core.f_list_join_from_list_1(
      Vx_web_html.t_trlist,
      testcaselist,
      Vx_test.t_trlist_from_testcase
    );
    return output;
  }


  public static class PackageRunOnce {
    public static void RunOnce() {
    Const_stylesheet_test.const_new(c_stylesheet_test);
    Vx_core.Map<string, Vx_core.Type_any> maptype = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
    Vx_core.Map<string, Vx_core.Type_any> mapconst = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
    Vx_core.Map<string, Vx_core.Type_func> mapfunc = new Vx_core.LinkedHashMap<string, Vx_core.Type_func>();
    maptype.put("testcase", Vx_test.t_testcase);
    maptype.put("testcaselist", Vx_test.t_testcaselist);
    maptype.put("testcoveragedetail", Vx_test.t_testcoveragedetail);
    maptype.put("testcoveragenums", Vx_test.t_testcoveragenums);
    maptype.put("testcoveragesummary", Vx_test.t_testcoveragesummary);
    maptype.put("testdescribe", Vx_test.t_testdescribe);
    maptype.put("testdescribelist", Vx_test.t_testdescribelist);
    maptype.put("testpackage", Vx_test.t_testpackage);
    maptype.put("testpackagelist", Vx_test.t_testpackagelist);
    maptype.put("testresult", Vx_test.t_testresult);
    maptype.put("testresultlist", Vx_test.t_testresultlist);
    mapconst.put("stylesheet-test", Vx_test.c_stylesheet_test);
    mapfunc.put("context-test", Vx_test.t_context_test);
    mapfunc.put("div<-testcaselist", Vx_test.t_div_from_testcaselist);
    mapfunc.put("div<-testpackage", Vx_test.t_div_from_testpackage);
    mapfunc.put("div<-testpackagelist", Vx_test.t_div_from_testpackagelist);
    mapfunc.put("divchildlist<-testpackagelist", Vx_test.t_divchildlist_from_testpackagelist);
    mapfunc.put("file-test", Vx_test.t_file_test);
    mapfunc.put("file-testhtml", Vx_test.t_file_testhtml);
    mapfunc.put("file-testnode", Vx_test.t_file_testnode);
    mapfunc.put("html<-divtest", Vx_test.t_html_from_divtest);
    mapfunc.put("p<-passfail", Vx_test.t_p_from_passfail);
    mapfunc.put("p<-testcoveragenums", Vx_test.t_p_from_testcoveragenums);
    mapfunc.put("resolve-testcase", Vx_test.t_resolve_testcase);
    mapfunc.put("resolve-testcaselist", Vx_test.t_resolve_testcaselist);
    mapfunc.put("resolve-testdescribe", Vx_test.t_resolve_testdescribe);
    mapfunc.put("resolve-testdescribelist", Vx_test.t_resolve_testdescribelist);
    mapfunc.put("resolve-testpackage", Vx_test.t_resolve_testpackage);
    mapfunc.put("resolve-testpackagelist", Vx_test.t_resolve_testpackagelist);
    mapfunc.put("resolve-testresult", Vx_test.t_resolve_testresult);
    mapfunc.put("security-test", Vx_test.t_security_test);
    mapfunc.put("test", Vx_test.t_test);
    mapfunc.put("test_1", Vx_test.t_test_1);
    mapfunc.put("test-false", Vx_test.t_test_false);
    mapfunc.put("test-false_1", Vx_test.t_test_false_1);
    mapfunc.put("test-gt", Vx_test.t_test_gt);
    mapfunc.put("test-gt_1", Vx_test.t_test_gt_1);
    mapfunc.put("test-ne", Vx_test.t_test_ne);
    mapfunc.put("test-ne_1", Vx_test.t_test_ne_1);
    mapfunc.put("test-string", Vx_test.t_test_string);
    mapfunc.put("test-string_1", Vx_test.t_test_string_1);
    mapfunc.put("test-true", Vx_test.t_test_true);
    mapfunc.put("test-true_1", Vx_test.t_test_true_1);
    mapfunc.put("tr<-testdescribe-casename", Vx_test.t_tr_from_testdescribe_casename);
    mapfunc.put("trlist<-testcase", Vx_test.t_trlist_from_testcase);
    mapfunc.put("trlist<-testcaselist", Vx_test.t_trlist_from_testcaselist);
    Vx_core.vx_global_package_set("vx/test", maptype, mapconst, mapfunc);
    }
  }

}
