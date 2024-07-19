namespace Vx;

public static class Test {


  /**
   * type: testcase
   * Structure to describe a test case
   * (type testcase)
   */
  public interface Type_testcase : Vx.Core.Type_struct {
    public Vx.Core.Type_boolean passfail();
    public Vx.Core.Type_string testpkg();
    public Vx.Core.Type_string casename();
    public Vx.Test.Type_testdescribelist describelist();
  }

  public class Class_testcase : Vx.Core.Class_base, Type_testcase {

    public Vx.Core.Type_boolean? vx_p_passfail = null;

    public Vx.Core.Type_boolean passfail() {
      Vx.Core.Type_boolean output = Vx.Core.e_boolean;
      if (this.vx_p_passfail != null) {
        output = this.vx_p_passfail;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_testpkg = null;

    public Vx.Core.Type_string testpkg() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_testpkg != null) {
        output = this.vx_p_testpkg;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_casename = null;

    public Vx.Core.Type_string casename() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_casename != null) {
        output = this.vx_p_casename;
      }
      return output;
    }

    public Vx.Test.Type_testdescribelist? vx_p_describelist = null;

    public Vx.Test.Type_testdescribelist describelist() {
      Vx.Test.Type_testdescribelist output = Vx.Test.e_testdescribelist;
      if (this.vx_p_describelist != null) {
        output = this.vx_p_describelist;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":passfail", this.passfail());
      output.put(":testpkg", this.testpkg());
      output.put(":casename", this.casename());
      output.put(":describelist", this.describelist());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Test.Type_testcase vx_new(params Object[] vals) {
      Vx.Test.Type_testcase output = Vx.Core.vx_copy(Vx.Test.e_testcase, vals);
      return output;
    }

    public override Vx.Test.Type_testcase vx_copy(params Object[] vals) {
      Type_testcase output = this;
      bool ischanged = false;
      Class_testcase val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_boolean vx_p_passfail = val.passfail();
      Vx.Core.Type_string vx_p_testpkg = val.testpkg();
      Vx.Core.Type_string vx_p_casename = val.casename();
      Vx.Test.Type_testdescribelist vx_p_describelist = val.describelist();
      List<string> validkeys = new List<string>();
      validkeys.Add(":passfail");
      validkeys.Add(":testpkg");
      validkeys.Add(":casename");
      validkeys.Add(":describelist");
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
            msg = Vx.Core.vx_msg_from_error("vx/test/testcase", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/test/testcase", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":passfail":
            if (valsub == vx_p_passfail) {
            } else if (valsub is Vx.Core.Type_boolean valpassfail) {
              ischanged = true;
              vx_p_passfail = valpassfail;
            } else if (valsub is bool) {
              ischanged = true;
              vx_p_passfail = Vx.Core.vx_new(Vx.Core.t_boolean, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("passfail"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testcase", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":testpkg":
            if (valsub == vx_p_testpkg) {
            } else if (valsub is Vx.Core.Type_string valtestpkg) {
              ischanged = true;
              vx_p_testpkg = valtestpkg;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_testpkg = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("testpkg"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testcase", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":casename":
            if (valsub == vx_p_casename) {
            } else if (valsub is Vx.Core.Type_string valcasename) {
              ischanged = true;
              vx_p_casename = valcasename;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_casename = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("casename"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testcase", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":describelist":
            if (valsub == vx_p_describelist) {
            } else if (valsub is Vx.Test.Type_testdescribelist valdescribelist) {
              ischanged = true;
              vx_p_describelist = valdescribelist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("describelist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testcase", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/test/testcase", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_testcase work = new Class_testcase();
        work.vx_p_passfail = vx_p_passfail;
        work.vx_p_testpkg = vx_p_testpkg;
        work.vx_p_casename = vx_p_casename;
        work.vx_p_describelist = vx_p_describelist;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_testcase;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_testcase;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/test", // pkgname
        "testcase", // name
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

  public static Type_testcase e_testcase = new Class_testcase();
  public static Type_testcase t_testcase = new Class_testcase();

  /**
   * type: testcaselist
   * List of test cases
   * (type testcaselist)
   */
  public interface Type_testcaselist : Vx.Core.Type_list {
    public List<Vx.Test.Type_testcase> vx_listtestcase();
    public Vx.Test.Type_testcase vx_testcase(Vx.Core.Type_int index);
  }

  public class Class_testcaselist : Vx.Core.Class_base, Type_testcaselist {

    public List<Vx.Test.Type_testcase> vx_p_list = Vx.Core.immutablelist(new List<Vx.Test.Type_testcase>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Test.Type_testcase vx_testcase(Vx.Core.Type_int index) {
      Vx.Test.Type_testcase output = Vx.Test.e_testcase;
      Vx.Test.Class_testcaselist list = this;
      int iindex = index.vx_int();
      List<Vx.Test.Type_testcase> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Test.Type_testcase> vx_listtestcase() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_testcase(index);
    }

    public override Vx.Test.Type_testcaselist vx_new(params Object[] vals) {
      Vx.Test.Type_testcaselist output = Vx.Core.vx_copy(Vx.Test.e_testcaselist, vals);
      return output;
    }

    public override Vx.Test.Type_testcaselist vx_copy(params Object[] vals) {
      Type_testcaselist output = this;
      bool ischanged = false;
      Class_testcaselist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Test.Type_testcase> listval = new List<Vx.Test.Type_testcase>(val.vx_listtestcase());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Test.Type_testcase allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Test.Type_testcase) {
          ischanged = true;
          listval.Add((Vx.Test.Type_testcase)valsub);
        } else if (valsub is Vx.Test.Type_testcaselist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listtestcase());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (false) {
            } else if (item is Vx.Test.Type_testcase valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/test/testcaselist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/test/testcaselist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_testcaselist work = new Class_testcaselist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_testcaselist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_testcaselist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/test", // pkgname
        "testcaselist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Test.t_testcase), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_testcoveragedetail : Vx.Core.Type_struct {
    public Vx.Core.Type_intmap constmap();
    public Vx.Core.Type_intmap funcmap();
    public Vx.Core.Type_string testpkg();
    public Vx.Core.Type_intmap typemap();
  }

  public class Class_testcoveragedetail : Vx.Core.Class_base, Type_testcoveragedetail {

    public Vx.Core.Type_intmap? vx_p_constmap = null;

    public Vx.Core.Type_intmap constmap() {
      Vx.Core.Type_intmap output = Vx.Core.e_intmap;
      if (this.vx_p_constmap != null) {
        output = this.vx_p_constmap;
      }
      return output;
    }

    public Vx.Core.Type_intmap? vx_p_funcmap = null;

    public Vx.Core.Type_intmap funcmap() {
      Vx.Core.Type_intmap output = Vx.Core.e_intmap;
      if (this.vx_p_funcmap != null) {
        output = this.vx_p_funcmap;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_testpkg = null;

    public Vx.Core.Type_string testpkg() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_testpkg != null) {
        output = this.vx_p_testpkg;
      }
      return output;
    }

    public Vx.Core.Type_intmap? vx_p_typemap = null;

    public Vx.Core.Type_intmap typemap() {
      Vx.Core.Type_intmap output = Vx.Core.e_intmap;
      if (this.vx_p_typemap != null) {
        output = this.vx_p_typemap;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":constmap", this.constmap());
      output.put(":funcmap", this.funcmap());
      output.put(":testpkg", this.testpkg());
      output.put(":typemap", this.typemap());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Test.Type_testcoveragedetail vx_new(params Object[] vals) {
      Vx.Test.Type_testcoveragedetail output = Vx.Core.vx_copy(Vx.Test.e_testcoveragedetail, vals);
      return output;
    }

    public override Vx.Test.Type_testcoveragedetail vx_copy(params Object[] vals) {
      Type_testcoveragedetail output = this;
      bool ischanged = false;
      Class_testcoveragedetail val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_intmap vx_p_constmap = val.constmap();
      Vx.Core.Type_intmap vx_p_funcmap = val.funcmap();
      Vx.Core.Type_string vx_p_testpkg = val.testpkg();
      Vx.Core.Type_intmap vx_p_typemap = val.typemap();
      List<string> validkeys = new List<string>();
      validkeys.Add(":constmap");
      validkeys.Add(":funcmap");
      validkeys.Add(":testpkg");
      validkeys.Add(":typemap");
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
            msg = Vx.Core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":constmap":
            if (valsub == vx_p_constmap) {
            } else if (valsub is Vx.Core.Type_intmap valconstmap) {
              ischanged = true;
              vx_p_constmap = valconstmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("constmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":funcmap":
            if (valsub == vx_p_funcmap) {
            } else if (valsub is Vx.Core.Type_intmap valfuncmap) {
              ischanged = true;
              vx_p_funcmap = valfuncmap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("funcmap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":testpkg":
            if (valsub == vx_p_testpkg) {
            } else if (valsub is Vx.Core.Type_string valtestpkg) {
              ischanged = true;
              vx_p_testpkg = valtestpkg;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_testpkg = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("testpkg"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":typemap":
            if (valsub == vx_p_typemap) {
            } else if (valsub is Vx.Core.Type_intmap valtypemap) {
              ischanged = true;
              vx_p_typemap = valtypemap;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("typemap"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_testcoveragedetail work = new Class_testcoveragedetail();
        work.vx_p_constmap = vx_p_constmap;
        work.vx_p_funcmap = vx_p_funcmap;
        work.vx_p_testpkg = vx_p_testpkg;
        work.vx_p_typemap = vx_p_typemap;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_testcoveragedetail;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_testcoveragedetail;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/test", // pkgname
        "testcoveragedetail", // name
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

  public static Type_testcoveragedetail e_testcoveragedetail = new Class_testcoveragedetail();
  public static Type_testcoveragedetail t_testcoveragedetail = new Class_testcoveragedetail();

  /**
   * type: testcoveragenums
   * Structure to describe a test coverage summary
   * (type testcoveragenums)
   */
  public interface Type_testcoveragenums : Vx.Core.Type_struct {
    public Vx.Core.Type_int pct();
    public Vx.Core.Type_string testpkg();
    public Vx.Core.Type_int tests();
    public Vx.Core.Type_int total();
  }

  public class Class_testcoveragenums : Vx.Core.Class_base, Type_testcoveragenums {

    public Vx.Core.Type_int? vx_p_pct = null;

    public Vx.Core.Type_int pct() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_pct != null) {
        output = this.vx_p_pct;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_testpkg = null;

    public Vx.Core.Type_string testpkg() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_testpkg != null) {
        output = this.vx_p_testpkg;
      }
      return output;
    }

    public Vx.Core.Type_int? vx_p_tests = null;

    public Vx.Core.Type_int tests() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_tests != null) {
        output = this.vx_p_tests;
      }
      return output;
    }

    public Vx.Core.Type_int? vx_p_total = null;

    public Vx.Core.Type_int total() {
      Vx.Core.Type_int output = Vx.Core.e_int;
      if (this.vx_p_total != null) {
        output = this.vx_p_total;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":pct", this.pct());
      output.put(":testpkg", this.testpkg());
      output.put(":tests", this.tests());
      output.put(":total", this.total());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Test.Type_testcoveragenums vx_new(params Object[] vals) {
      Vx.Test.Type_testcoveragenums output = Vx.Core.vx_copy(Vx.Test.e_testcoveragenums, vals);
      return output;
    }

    public override Vx.Test.Type_testcoveragenums vx_copy(params Object[] vals) {
      Type_testcoveragenums output = this;
      bool ischanged = false;
      Class_testcoveragenums val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_int vx_p_pct = val.pct();
      Vx.Core.Type_string vx_p_testpkg = val.testpkg();
      Vx.Core.Type_int vx_p_tests = val.tests();
      Vx.Core.Type_int vx_p_total = val.total();
      List<string> validkeys = new List<string>();
      validkeys.Add(":pct");
      validkeys.Add(":testpkg");
      validkeys.Add(":tests");
      validkeys.Add(":total");
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
            msg = Vx.Core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":pct":
            if (valsub == vx_p_pct) {
            } else if (valsub is Vx.Core.Type_int valpct) {
              ischanged = true;
              vx_p_pct = valpct;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_pct = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("pct"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":testpkg":
            if (valsub == vx_p_testpkg) {
            } else if (valsub is Vx.Core.Type_string valtestpkg) {
              ischanged = true;
              vx_p_testpkg = valtestpkg;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_testpkg = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("testpkg"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":tests":
            if (valsub == vx_p_tests) {
            } else if (valsub is Vx.Core.Type_int valtests) {
              ischanged = true;
              vx_p_tests = valtests;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_tests = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("tests"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":total":
            if (valsub == vx_p_total) {
            } else if (valsub is Vx.Core.Type_int valtotal) {
              ischanged = true;
              vx_p_total = valtotal;
            } else if (valsub is int) {
              ischanged = true;
              vx_p_total = Vx.Core.vx_new(Vx.Core.t_int, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("total"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_testcoveragenums work = new Class_testcoveragenums();
        work.vx_p_pct = vx_p_pct;
        work.vx_p_testpkg = vx_p_testpkg;
        work.vx_p_tests = vx_p_tests;
        work.vx_p_total = vx_p_total;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_testcoveragenums;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_testcoveragenums;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/test", // pkgname
        "testcoveragenums", // name
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

  public static Type_testcoveragenums e_testcoveragenums = new Class_testcoveragenums();
  public static Type_testcoveragenums t_testcoveragenums = new Class_testcoveragenums();

  /**
   * type: testcoveragesummary
   * Structure to describe a test coverage summary
   * (type testcoveragesummary)
   */
  public interface Type_testcoveragesummary : Vx.Core.Type_struct {
    public Vx.Test.Type_testcoveragenums bigospacenums();
    public Vx.Test.Type_testcoveragenums bigotimenums();
    public Vx.Test.Type_testcoveragenums constnums();
    public Vx.Test.Type_testcoveragenums docnums();
    public Vx.Test.Type_testcoveragenums funcnums();
    public Vx.Core.Type_string testpkg();
    public Vx.Test.Type_testcoveragenums totalnums();
    public Vx.Test.Type_testcoveragenums typenums();
  }

  public class Class_testcoveragesummary : Vx.Core.Class_base, Type_testcoveragesummary {

    public Vx.Test.Type_testcoveragenums? vx_p_bigospacenums = null;

    public Vx.Test.Type_testcoveragenums bigospacenums() {
      Vx.Test.Type_testcoveragenums output = Vx.Test.e_testcoveragenums;
      if (this.vx_p_bigospacenums != null) {
        output = this.vx_p_bigospacenums;
      }
      return output;
    }

    public Vx.Test.Type_testcoveragenums? vx_p_bigotimenums = null;

    public Vx.Test.Type_testcoveragenums bigotimenums() {
      Vx.Test.Type_testcoveragenums output = Vx.Test.e_testcoveragenums;
      if (this.vx_p_bigotimenums != null) {
        output = this.vx_p_bigotimenums;
      }
      return output;
    }

    public Vx.Test.Type_testcoveragenums? vx_p_constnums = null;

    public Vx.Test.Type_testcoveragenums constnums() {
      Vx.Test.Type_testcoveragenums output = Vx.Test.e_testcoveragenums;
      if (this.vx_p_constnums != null) {
        output = this.vx_p_constnums;
      }
      return output;
    }

    public Vx.Test.Type_testcoveragenums? vx_p_docnums = null;

    public Vx.Test.Type_testcoveragenums docnums() {
      Vx.Test.Type_testcoveragenums output = Vx.Test.e_testcoveragenums;
      if (this.vx_p_docnums != null) {
        output = this.vx_p_docnums;
      }
      return output;
    }

    public Vx.Test.Type_testcoveragenums? vx_p_funcnums = null;

    public Vx.Test.Type_testcoveragenums funcnums() {
      Vx.Test.Type_testcoveragenums output = Vx.Test.e_testcoveragenums;
      if (this.vx_p_funcnums != null) {
        output = this.vx_p_funcnums;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_testpkg = null;

    public Vx.Core.Type_string testpkg() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_testpkg != null) {
        output = this.vx_p_testpkg;
      }
      return output;
    }

    public Vx.Test.Type_testcoveragenums? vx_p_totalnums = null;

    public Vx.Test.Type_testcoveragenums totalnums() {
      Vx.Test.Type_testcoveragenums output = Vx.Test.e_testcoveragenums;
      if (this.vx_p_totalnums != null) {
        output = this.vx_p_totalnums;
      }
      return output;
    }

    public Vx.Test.Type_testcoveragenums? vx_p_typenums = null;

    public Vx.Test.Type_testcoveragenums typenums() {
      Vx.Test.Type_testcoveragenums output = Vx.Test.e_testcoveragenums;
      if (this.vx_p_typenums != null) {
        output = this.vx_p_typenums;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":bigospacenums", this.bigospacenums());
      output.put(":bigotimenums", this.bigotimenums());
      output.put(":constnums", this.constnums());
      output.put(":docnums", this.docnums());
      output.put(":funcnums", this.funcnums());
      output.put(":testpkg", this.testpkg());
      output.put(":totalnums", this.totalnums());
      output.put(":typenums", this.typenums());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Test.Type_testcoveragesummary vx_new(params Object[] vals) {
      Vx.Test.Type_testcoveragesummary output = Vx.Core.vx_copy(Vx.Test.e_testcoveragesummary, vals);
      return output;
    }

    public override Vx.Test.Type_testcoveragesummary vx_copy(params Object[] vals) {
      Type_testcoveragesummary output = this;
      bool ischanged = false;
      Class_testcoveragesummary val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Test.Type_testcoveragenums vx_p_bigospacenums = val.bigospacenums();
      Vx.Test.Type_testcoveragenums vx_p_bigotimenums = val.bigotimenums();
      Vx.Test.Type_testcoveragenums vx_p_constnums = val.constnums();
      Vx.Test.Type_testcoveragenums vx_p_docnums = val.docnums();
      Vx.Test.Type_testcoveragenums vx_p_funcnums = val.funcnums();
      Vx.Core.Type_string vx_p_testpkg = val.testpkg();
      Vx.Test.Type_testcoveragenums vx_p_totalnums = val.totalnums();
      Vx.Test.Type_testcoveragenums vx_p_typenums = val.typenums();
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
            msg = Vx.Core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":bigospacenums":
            if (valsub == vx_p_bigospacenums) {
            } else if (valsub is Vx.Test.Type_testcoveragenums valbigospacenums) {
              ischanged = true;
              vx_p_bigospacenums = valbigospacenums;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("bigospacenums"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":bigotimenums":
            if (valsub == vx_p_bigotimenums) {
            } else if (valsub is Vx.Test.Type_testcoveragenums valbigotimenums) {
              ischanged = true;
              vx_p_bigotimenums = valbigotimenums;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("bigotimenums"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":constnums":
            if (valsub == vx_p_constnums) {
            } else if (valsub is Vx.Test.Type_testcoveragenums valconstnums) {
              ischanged = true;
              vx_p_constnums = valconstnums;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("constnums"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":docnums":
            if (valsub == vx_p_docnums) {
            } else if (valsub is Vx.Test.Type_testcoveragenums valdocnums) {
              ischanged = true;
              vx_p_docnums = valdocnums;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("docnums"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":funcnums":
            if (valsub == vx_p_funcnums) {
            } else if (valsub is Vx.Test.Type_testcoveragenums valfuncnums) {
              ischanged = true;
              vx_p_funcnums = valfuncnums;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("funcnums"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":testpkg":
            if (valsub == vx_p_testpkg) {
            } else if (valsub is Vx.Core.Type_string valtestpkg) {
              ischanged = true;
              vx_p_testpkg = valtestpkg;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_testpkg = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("testpkg"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":totalnums":
            if (valsub == vx_p_totalnums) {
            } else if (valsub is Vx.Test.Type_testcoveragenums valtotalnums) {
              ischanged = true;
              vx_p_totalnums = valtotalnums;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("totalnums"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":typenums":
            if (valsub == vx_p_typenums) {
            } else if (valsub is Vx.Test.Type_testcoveragenums valtypenums) {
              ischanged = true;
              vx_p_typenums = valtypenums;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("typenums"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_testcoveragesummary work = new Class_testcoveragesummary();
        work.vx_p_bigospacenums = vx_p_bigospacenums;
        work.vx_p_bigotimenums = vx_p_bigotimenums;
        work.vx_p_constnums = vx_p_constnums;
        work.vx_p_docnums = vx_p_docnums;
        work.vx_p_funcnums = vx_p_funcnums;
        work.vx_p_testpkg = vx_p_testpkg;
        work.vx_p_totalnums = vx_p_totalnums;
        work.vx_p_typenums = vx_p_typenums;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_testcoveragesummary;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_testcoveragesummary;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/test", // pkgname
        "testcoveragesummary", // name
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

  public static Type_testcoveragesummary e_testcoveragesummary = new Class_testcoveragesummary();
  public static Type_testcoveragesummary t_testcoveragesummary = new Class_testcoveragesummary();

  /**
   * type: testdescribe
   * Structure to describe test results
   * (type testdescribe)
   */
  public interface Type_testdescribe : Vx.Core.Type_struct {
    public Vx.Core.Type_string describename();
    public Vx.Core.Type_string testpkg();
    public Vx.Test.Type_testresult testresult();
  }

  public class Class_testdescribe : Vx.Core.Class_base, Type_testdescribe {

    public Vx.Core.Type_string? vx_p_describename = null;

    public Vx.Core.Type_string describename() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_describename != null) {
        output = this.vx_p_describename;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_testpkg = null;

    public Vx.Core.Type_string testpkg() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_testpkg != null) {
        output = this.vx_p_testpkg;
      }
      return output;
    }

    public Vx.Test.Type_testresult? vx_p_testresult = null;

    public Vx.Test.Type_testresult testresult() {
      Vx.Test.Type_testresult output = Vx.Test.e_testresult;
      if (this.vx_p_testresult != null) {
        output = this.vx_p_testresult;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":describename", this.describename());
      output.put(":testpkg", this.testpkg());
      output.put(":testresult", this.testresult());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Test.Type_testdescribe vx_new(params Object[] vals) {
      Vx.Test.Type_testdescribe output = Vx.Core.vx_copy(Vx.Test.e_testdescribe, vals);
      return output;
    }

    public override Vx.Test.Type_testdescribe vx_copy(params Object[] vals) {
      Type_testdescribe output = this;
      bool ischanged = false;
      Class_testdescribe val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_describename = val.describename();
      Vx.Core.Type_string vx_p_testpkg = val.testpkg();
      Vx.Test.Type_testresult vx_p_testresult = val.testresult();
      List<string> validkeys = new List<string>();
      validkeys.Add(":describename");
      validkeys.Add(":testpkg");
      validkeys.Add(":testresult");
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
            msg = Vx.Core.vx_msg_from_error("vx/test/testdescribe", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/test/testdescribe", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":describename":
            if (valsub == vx_p_describename) {
            } else if (valsub is Vx.Core.Type_string valdescribename) {
              ischanged = true;
              vx_p_describename = valdescribename;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_describename = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("describename"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testdescribe", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":testpkg":
            if (valsub == vx_p_testpkg) {
            } else if (valsub is Vx.Core.Type_string valtestpkg) {
              ischanged = true;
              vx_p_testpkg = valtestpkg;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_testpkg = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("testpkg"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testdescribe", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":testresult":
            if (valsub == vx_p_testresult) {
            } else if (valsub is Vx.Test.Type_testresult valtestresult) {
              ischanged = true;
              vx_p_testresult = valtestresult;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("testresult"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testdescribe", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/test/testdescribe", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_testdescribe work = new Class_testdescribe();
        work.vx_p_describename = vx_p_describename;
        work.vx_p_testpkg = vx_p_testpkg;
        work.vx_p_testresult = vx_p_testresult;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_testdescribe;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_testdescribe;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/test", // pkgname
        "testdescribe", // name
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

  public static Type_testdescribe e_testdescribe = new Class_testdescribe();
  public static Type_testdescribe t_testdescribe = new Class_testdescribe();

  /**
   * type: testdescribelist
   * List of testdescribe
   * (type testdescribelist)
   */
  public interface Type_testdescribelist : Vx.Core.Type_list {
    public List<Vx.Test.Type_testdescribe> vx_listtestdescribe();
    public Vx.Test.Type_testdescribe vx_testdescribe(Vx.Core.Type_int index);
  }

  public class Class_testdescribelist : Vx.Core.Class_base, Type_testdescribelist {

    public List<Vx.Test.Type_testdescribe> vx_p_list = Vx.Core.immutablelist(new List<Vx.Test.Type_testdescribe>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Test.Type_testdescribe vx_testdescribe(Vx.Core.Type_int index) {
      Vx.Test.Type_testdescribe output = Vx.Test.e_testdescribe;
      Vx.Test.Class_testdescribelist list = this;
      int iindex = index.vx_int();
      List<Vx.Test.Type_testdescribe> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Test.Type_testdescribe> vx_listtestdescribe() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_testdescribe(index);
    }

    public override Vx.Test.Type_testdescribelist vx_new(params Object[] vals) {
      Vx.Test.Type_testdescribelist output = Vx.Core.vx_copy(Vx.Test.e_testdescribelist, vals);
      return output;
    }

    public override Vx.Test.Type_testdescribelist vx_copy(params Object[] vals) {
      Type_testdescribelist output = this;
      bool ischanged = false;
      Class_testdescribelist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Test.Type_testdescribe> listval = new List<Vx.Test.Type_testdescribe>(val.vx_listtestdescribe());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Test.Type_testdescribe allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Test.Type_testdescribe) {
          ischanged = true;
          listval.Add((Vx.Test.Type_testdescribe)valsub);
        } else if (valsub is Vx.Test.Type_testdescribelist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listtestdescribe());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (false) {
            } else if (item is Vx.Test.Type_testdescribe valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/test/testdescribelist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/test/testdescribelist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_testdescribelist work = new Class_testdescribelist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_testdescribelist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_testdescribelist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/test", // pkgname
        "testdescribelist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Test.t_testdescribe), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_testpackage : Vx.Core.Type_struct {
    public Vx.Test.Type_testcaselist caselist();
    public Vx.Test.Type_testcoveragedetail coveragedetail();
    public Vx.Test.Type_testcoveragesummary coveragesummary();
    public Vx.Core.Type_boolean passfail();
    public Vx.Core.Type_string testpkg();
  }

  public class Class_testpackage : Vx.Core.Class_base, Type_testpackage {

    public Vx.Test.Type_testcaselist? vx_p_caselist = null;

    public Vx.Test.Type_testcaselist caselist() {
      Vx.Test.Type_testcaselist output = Vx.Test.e_testcaselist;
      if (this.vx_p_caselist != null) {
        output = this.vx_p_caselist;
      }
      return output;
    }

    public Vx.Test.Type_testcoveragedetail? vx_p_coveragedetail = null;

    public Vx.Test.Type_testcoveragedetail coveragedetail() {
      Vx.Test.Type_testcoveragedetail output = Vx.Test.e_testcoveragedetail;
      if (this.vx_p_coveragedetail != null) {
        output = this.vx_p_coveragedetail;
      }
      return output;
    }

    public Vx.Test.Type_testcoveragesummary? vx_p_coveragesummary = null;

    public Vx.Test.Type_testcoveragesummary coveragesummary() {
      Vx.Test.Type_testcoveragesummary output = Vx.Test.e_testcoveragesummary;
      if (this.vx_p_coveragesummary != null) {
        output = this.vx_p_coveragesummary;
      }
      return output;
    }

    public Vx.Core.Type_boolean? vx_p_passfail = null;

    public Vx.Core.Type_boolean passfail() {
      Vx.Core.Type_boolean output = Vx.Core.e_boolean;
      if (this.vx_p_passfail != null) {
        output = this.vx_p_passfail;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_testpkg = null;

    public Vx.Core.Type_string testpkg() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_testpkg != null) {
        output = this.vx_p_testpkg;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":caselist", this.caselist());
      output.put(":coveragedetail", this.coveragedetail());
      output.put(":coveragesummary", this.coveragesummary());
      output.put(":passfail", this.passfail());
      output.put(":testpkg", this.testpkg());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Test.Type_testpackage vx_new(params Object[] vals) {
      Vx.Test.Type_testpackage output = Vx.Core.vx_copy(Vx.Test.e_testpackage, vals);
      return output;
    }

    public override Vx.Test.Type_testpackage vx_copy(params Object[] vals) {
      Type_testpackage output = this;
      bool ischanged = false;
      Class_testpackage val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Test.Type_testcaselist vx_p_caselist = val.caselist();
      Vx.Test.Type_testcoveragedetail vx_p_coveragedetail = val.coveragedetail();
      Vx.Test.Type_testcoveragesummary vx_p_coveragesummary = val.coveragesummary();
      Vx.Core.Type_boolean vx_p_passfail = val.passfail();
      Vx.Core.Type_string vx_p_testpkg = val.testpkg();
      List<string> validkeys = new List<string>();
      validkeys.Add(":caselist");
      validkeys.Add(":coveragedetail");
      validkeys.Add(":coveragesummary");
      validkeys.Add(":passfail");
      validkeys.Add(":testpkg");
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
            msg = Vx.Core.vx_msg_from_error("vx/test/testpackage", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/test/testpackage", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":caselist":
            if (valsub == vx_p_caselist) {
            } else if (valsub is Vx.Test.Type_testcaselist valcaselist) {
              ischanged = true;
              vx_p_caselist = valcaselist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("caselist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testpackage", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":coveragedetail":
            if (valsub == vx_p_coveragedetail) {
            } else if (valsub is Vx.Test.Type_testcoveragedetail valcoveragedetail) {
              ischanged = true;
              vx_p_coveragedetail = valcoveragedetail;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("coveragedetail"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testpackage", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":coveragesummary":
            if (valsub == vx_p_coveragesummary) {
            } else if (valsub is Vx.Test.Type_testcoveragesummary valcoveragesummary) {
              ischanged = true;
              vx_p_coveragesummary = valcoveragesummary;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("coveragesummary"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testpackage", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":passfail":
            if (valsub == vx_p_passfail) {
            } else if (valsub is Vx.Core.Type_boolean valpassfail) {
              ischanged = true;
              vx_p_passfail = valpassfail;
            } else if (valsub is bool) {
              ischanged = true;
              vx_p_passfail = Vx.Core.vx_new(Vx.Core.t_boolean, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("passfail"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testpackage", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":testpkg":
            if (valsub == vx_p_testpkg) {
            } else if (valsub is Vx.Core.Type_string valtestpkg) {
              ischanged = true;
              vx_p_testpkg = valtestpkg;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_testpkg = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("testpkg"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testpackage", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/test/testpackage", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_testpackage work = new Class_testpackage();
        work.vx_p_caselist = vx_p_caselist;
        work.vx_p_coveragedetail = vx_p_coveragedetail;
        work.vx_p_coveragesummary = vx_p_coveragesummary;
        work.vx_p_passfail = vx_p_passfail;
        work.vx_p_testpkg = vx_p_testpkg;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_testpackage;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_testpackage;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/test", // pkgname
        "testpackage", // name
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

  public static Type_testpackage e_testpackage = new Class_testpackage();
  public static Type_testpackage t_testpackage = new Class_testpackage();

  /**
   * type: testpackagelist
   * List of testpackage
   * (type testpackagelist)
   */
  public interface Type_testpackagelist : Vx.Core.Type_list {
    public List<Vx.Test.Type_testpackage> vx_listtestpackage();
    public Vx.Test.Type_testpackage vx_testpackage(Vx.Core.Type_int index);
  }

  public class Class_testpackagelist : Vx.Core.Class_base, Type_testpackagelist {

    public List<Vx.Test.Type_testpackage> vx_p_list = Vx.Core.immutablelist(new List<Vx.Test.Type_testpackage>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Test.Type_testpackage vx_testpackage(Vx.Core.Type_int index) {
      Vx.Test.Type_testpackage output = Vx.Test.e_testpackage;
      Vx.Test.Class_testpackagelist list = this;
      int iindex = index.vx_int();
      List<Vx.Test.Type_testpackage> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Test.Type_testpackage> vx_listtestpackage() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_testpackage(index);
    }

    public override Vx.Test.Type_testpackagelist vx_new(params Object[] vals) {
      Vx.Test.Type_testpackagelist output = Vx.Core.vx_copy(Vx.Test.e_testpackagelist, vals);
      return output;
    }

    public override Vx.Test.Type_testpackagelist vx_copy(params Object[] vals) {
      Type_testpackagelist output = this;
      bool ischanged = false;
      Class_testpackagelist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Test.Type_testpackage> listval = new List<Vx.Test.Type_testpackage>(val.vx_listtestpackage());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Test.Type_testpackage allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Test.Type_testpackage) {
          ischanged = true;
          listval.Add((Vx.Test.Type_testpackage)valsub);
        } else if (valsub is Vx.Test.Type_testpackagelist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listtestpackage());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (false) {
            } else if (item is Vx.Test.Type_testpackage valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/test/testpackagelist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/test/testpackagelist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_testpackagelist work = new Class_testpackagelist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_testpackagelist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_testpackagelist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/test", // pkgname
        "testpackagelist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Test.t_testpackage), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public interface Type_testresult : Vx.Core.Type_struct {
    public Vx.Core.Type_string code();
    public Vx.Core.Type_boolean passfail();
    public Vx.Core.Type_any expected();
    public Vx.Core.Type_any actual();
    public Vx.Core.Func_any_from_func_async fn_actual();
  }

  public class Class_testresult : Vx.Core.Class_base, Type_testresult {

    public Vx.Core.Type_string? vx_p_code = null;

    public Vx.Core.Type_string code() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      if (this.vx_p_code != null) {
        output = this.vx_p_code;
      }
      return output;
    }

    public Vx.Core.Type_boolean? vx_p_passfail = null;

    public Vx.Core.Type_boolean passfail() {
      Vx.Core.Type_boolean output = Vx.Core.e_boolean;
      if (this.vx_p_passfail != null) {
        output = this.vx_p_passfail;
      }
      return output;
    }

    public Vx.Core.Type_any? vx_p_expected = null;

    public Vx.Core.Type_any expected() {
      Vx.Core.Type_any output = Vx.Core.e_any;
      if (this.vx_p_expected != null) {
        output = this.vx_p_expected;
      }
      return output;
    }

    public Vx.Core.Type_any? vx_p_actual = null;

    public Vx.Core.Type_any actual() {
      Vx.Core.Type_any output = Vx.Core.e_any;
      if (this.vx_p_actual != null) {
        output = this.vx_p_actual;
      }
      return output;
    }

    public Vx.Core.Func_any_from_func_async? vx_p_fn_actual = null;

    public Vx.Core.Func_any_from_func_async fn_actual() {
      Vx.Core.Func_any_from_func_async output = Vx.Core.e_any_from_func_async;
      if (this.vx_p_fn_actual != null) {
        output = this.vx_p_fn_actual;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
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

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> output = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      output.put(":code", this.code());
      output.put(":passfail", this.passfail());
      output.put(":expected", this.expected());
      output.put(":actual", this.actual());
      output.put(":fn-actual", this.fn_actual());
      return Vx.Core.immutablemap(output);
    }

    public override Vx.Test.Type_testresult vx_new(params Object[] vals) {
      Vx.Test.Type_testresult output = Vx.Core.vx_copy(Vx.Test.e_testresult, vals);
      return output;
    }

    public override Vx.Test.Type_testresult vx_copy(params Object[] vals) {
      Type_testresult output = this;
      bool ischanged = false;
      Class_testresult val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_code = val.code();
      Vx.Core.Type_boolean vx_p_passfail = val.passfail();
      Vx.Core.Type_any vx_p_expected = val.expected();
      Vx.Core.Type_any vx_p_actual = val.actual();
      Vx.Core.Func_any_from_func_async vx_p_fn_actual = val.fn_actual();
      List<string> validkeys = new List<string>();
      validkeys.Add(":code");
      validkeys.Add(":passfail");
      validkeys.Add(":expected");
      validkeys.Add(":actual");
      validkeys.Add(":fn-actual");
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
            msg = Vx.Core.vx_msg_from_error("vx/test/testresult", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/test/testresult", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":code":
            if (valsub == vx_p_code) {
            } else if (valsub is Vx.Core.Type_string valcode) {
              ischanged = true;
              vx_p_code = valcode;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_code = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("code"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testresult", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":passfail":
            if (valsub == vx_p_passfail) {
            } else if (valsub is Vx.Core.Type_boolean valpassfail) {
              ischanged = true;
              vx_p_passfail = valpassfail;
            } else if (valsub is bool) {
              ischanged = true;
              vx_p_passfail = Vx.Core.vx_new(Vx.Core.t_boolean, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("passfail"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testresult", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":expected":
            if (valsub == vx_p_expected) {
            } else if (valsub is Vx.Core.Type_any valexpected) {
              ischanged = true;
              vx_p_expected = valexpected;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("expected"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testresult", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":actual":
            if (valsub == vx_p_actual) {
            } else if (valsub is Vx.Core.Type_any valactual) {
              ischanged = true;
              vx_p_actual = valactual;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("actual"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testresult", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          case ":fn-actual":
            if (valsub == vx_p_fn_actual) {
            } else if (valsub is Vx.Core.Func_any_from_func_async valfn_actual) {
              ischanged = true;
              vx_p_fn_actual = valfn_actual;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("fn-actual"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/test/testresult", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/test/testresult", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_testresult work = new Class_testresult();
        work.vx_p_code = vx_p_code;
        work.vx_p_passfail = vx_p_passfail;
        work.vx_p_expected = vx_p_expected;
        work.vx_p_actual = vx_p_actual;
        work.vx_p_fn_actual = vx_p_fn_actual;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_testresult;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_testresult;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/test", // pkgname
        "testresult", // name
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

  public static Type_testresult e_testresult = new Class_testresult();
  public static Type_testresult t_testresult = new Class_testresult();

  /**
   * type: testresultlist
   * List of test results
   * (type testresultlist)
   */
  public interface Type_testresultlist : Vx.Core.Type_list {
    public List<Vx.Test.Type_testresult> vx_listtestresult();
    public Vx.Test.Type_testresult vx_testresult(Vx.Core.Type_int index);
  }

  public class Class_testresultlist : Vx.Core.Class_base, Type_testresultlist {

    public List<Vx.Test.Type_testresult> vx_p_list = Vx.Core.immutablelist(new List<Vx.Test.Type_testresult>());

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Test.Type_testresult vx_testresult(Vx.Core.Type_int index) {
      Vx.Test.Type_testresult output = Vx.Test.e_testresult;
      Vx.Test.Class_testresultlist list = this;
      int iindex = index.vx_int();
      List<Vx.Test.Type_testresult> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Test.Type_testresult> vx_listtestresult() {
      return vx_p_list;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      return this.vx_testresult(index);
    }

    public override Vx.Test.Type_testresultlist vx_new(params Object[] vals) {
      Vx.Test.Type_testresultlist output = Vx.Core.vx_copy(Vx.Test.e_testresultlist, vals);
      return output;
    }

    public override Vx.Test.Type_testresultlist vx_copy(params Object[] vals) {
      Type_testresultlist output = this;
      bool ischanged = false;
      Class_testresultlist val = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this is Vx.Core.vx_Type_const) {
        ischanged = true;
      }
      List<Vx.Test.Type_testresult> listval = new List<Vx.Test.Type_testresult>(val.vx_listtestresult());
      Vx.Core.Type_msg msg;
      foreach (Object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Test.Type_testresult allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Test.Type_testresult) {
          ischanged = true;
          listval.Add((Vx.Test.Type_testresult)valsub);
        } else if (valsub is Vx.Test.Type_testresultlist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listtestresult());
        } else if (valsub is List<object> listunknown) {
          foreach (Object item in listunknown) {
            if (false) {
            } else if (item is Vx.Test.Type_testresult valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/test/testresultlist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/test/testresultlist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Class_testresultlist work = new Class_testresultlist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_testresultlist;
    }
    public override Vx.Core.Type_any vx_type() {
      return t_testresultlist;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.typedef_new(
        "vx/test", // pkgname
        "testresultlist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Test.t_testresult), // allowtypes
        Vx.Core.e_typelist, // disallowtypes
        Vx.Core.e_funclist, // allowfuncs
        Vx.Core.e_funclist, // disallowfuncs
        Vx.Core.e_anylist, // allowvalues
        Vx.Core.e_anylist, // disallowvalues
        Vx.Core.e_argmap // properties
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
  public class Const_stylesheet_test : Vx.Web.Html.Class_stylesheet, Vx.Core.vx_Type_const {
    
    public Vx.Core.Type_constdef vx_constdef() {
      return Vx.Core.constdef_new(
        "vx/test", // pkgname
        "stylesheet-test", // name
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "stylesheet", // name
          ":struct", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_node, Vx.Web.Html.t_headchild), // traits
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

    public static void const_new(Const_stylesheet_test output) {
      Vx.Web.Html.Type_stylesheet val = Vx.Web.Html.f_stylesheet_loadmap(
        Vx.Core.f_new(
          Vx.Web.Html.t_stylesheet,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":name"),
            Vx.Core.vx_new_string("Test Suite"),
            Vx.Core.vx_new_string(":styles"),
            Vx.Core.f_new(
              Vx.Web.Html.t_stylelist,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.f_new(
                  Vx.Web.Html.t_style,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":name"),
                    Vx.Core.vx_new_string("body"),
                    Vx.Core.vx_new_string(":props"),
                    Vx.Core.f_new(
                      Vx.Web.Html.t_propmap,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.vx_new_string("font-size"),
                        Vx.Core.vx_new_string("0.9em"),
                        Vx.Core.vx_new_string("font-family"),
                        Vx.Core.vx_new_string("sans-serif")
                      )
                    )
                  )
                ),
                Vx.Core.f_new(
                  Vx.Web.Html.t_style,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":name"),
                    Vx.Core.vx_new_string("details summary"),
                    Vx.Core.vx_new_string(":props"),
                    Vx.Core.f_new(
                      Vx.Web.Html.t_propmap,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.vx_new_string("cursor"),
                        Vx.Core.vx_new_string("pointer"),
                        Vx.Core.vx_new_string("display"),
                        Vx.Core.vx_new_string("inline-flex"),
                        Vx.Core.vx_new_string("gap"),
                        Vx.Core.vx_new_string("10px")
                      )
                    )
                  )
                ),
                Vx.Core.f_new(
                  Vx.Web.Html.t_style,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":name"),
                    Vx.Core.vx_new_string("table"),
                    Vx.Core.vx_new_string(":props"),
                    Vx.Core.f_new(
                      Vx.Web.Html.t_propmap,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.vx_new_string("vertical-align"),
                        Vx.Core.vx_new_string("top"),
                        Vx.Core.vx_new_string("border-collapse"),
                        Vx.Core.vx_new_string("collapse"),
                        Vx.Core.vx_new_string("margin"),
                        Vx.Core.vx_new_string("25px 0"),
                        Vx.Core.vx_new_string("min-width"),
                        Vx.Core.vx_new_string("400px"),
                        Vx.Core.vx_new_string("box-shadow"),
                        Vx.Core.vx_new_string("0 0 20px rgba(0, 0, 0, 0.15)")
                      )
                    )
                  )
                ),
                Vx.Core.f_new(
                  Vx.Web.Html.t_style,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":name"),
                    Vx.Core.vx_new_string("thead tr"),
                    Vx.Core.vx_new_string(":props"),
                    Vx.Core.f_new(
                      Vx.Web.Html.t_propmap,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.vx_new_string("background-color"),
                        Vx.Core.vx_new_string("#009879"),
                        Vx.Core.vx_new_string("color"),
                        Vx.Core.vx_new_string("#ffffff"),
                        Vx.Core.vx_new_string("text-align"),
                        Vx.Core.vx_new_string("left")
                      )
                    )
                  )
                ),
                Vx.Core.f_new(
                  Vx.Web.Html.t_style,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":name"),
                    Vx.Core.vx_new_string("td"),
                    Vx.Core.vx_new_string(":props"),
                    Vx.Core.f_new(
                      Vx.Web.Html.t_propmap,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.vx_new_string("padding"),
                        Vx.Core.vx_new_string("10px 10px"),
                        Vx.Core.vx_new_string("vertical-align"),
                        Vx.Core.vx_new_string("top")
                      )
                    )
                  )
                ),
                Vx.Core.f_new(
                  Vx.Web.Html.t_style,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":name"),
                    Vx.Core.vx_new_string("tbody tr"),
                    Vx.Core.vx_new_string(":props"),
                    Vx.Core.f_new(
                      Vx.Web.Html.t_propmap,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.vx_new_string("border-bottom"),
                        Vx.Core.vx_new_string("1px solid #dddddd")
                      )
                    )
                  )
                ),
                Vx.Core.f_new(
                  Vx.Web.Html.t_style,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":name"),
                    Vx.Core.vx_new_string("tbody tr:nth-of-type(even)"),
                    Vx.Core.vx_new_string(":props"),
                    Vx.Core.f_new(
                      Vx.Web.Html.t_propmap,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.vx_new_string("background-color"),
                        Vx.Core.vx_new_string("#f3f3f3")
                      )
                    )
                  )
                ),
                Vx.Core.f_new(
                  Vx.Web.Html.t_style,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":name"),
                    Vx.Core.vx_new_string("tbody tr:last-of-type"),
                    Vx.Core.vx_new_string(":props"),
                    Vx.Core.f_new(
                      Vx.Web.Html.t_propmap,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.vx_new_string("border-bottom"),
                        Vx.Core.vx_new_string("2px solid #009879")
                      )
                    )
                  )
                ),
                Vx.Core.f_new(
                  Vx.Web.Html.t_style,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":name"),
                    Vx.Core.vx_new_string("tbody tr.active-row"),
                    Vx.Core.vx_new_string(":props"),
                    Vx.Core.f_new(
                      Vx.Web.Html.t_propmap,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.vx_new_string("font-weight"),
                        Vx.Core.vx_new_string("bold"),
                        Vx.Core.vx_new_string("color"),
                        Vx.Core.vx_new_string("#009879")
                      )
                    )
                  )
                ),
                Vx.Core.f_new(
                  Vx.Web.Html.t_style,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":name"),
                    Vx.Core.vx_new_string(".failflag"),
                    Vx.Core.vx_new_string(":props"),
                    Vx.Core.f_new(
                      Vx.Web.Html.t_propmap,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.vx_new_string("background-color"),
                        Vx.Core.vx_new_string("red"),
                        Vx.Core.vx_new_string("color"),
                        Vx.Core.vx_new_string("white"),
                        Vx.Core.vx_new_string("padding-left"),
                        Vx.Core.vx_new_string("4px"),
                        Vx.Core.vx_new_string("padding-right"),
                        Vx.Core.vx_new_string("4px"),
                        Vx.Core.vx_new_string("padding-top"),
                        Vx.Core.vx_new_string("1px"),
                        Vx.Core.vx_new_string("padding-bottom"),
                        Vx.Core.vx_new_string("1px")
                      )
                    )
                  )
                ),
                Vx.Core.f_new(
                  Vx.Web.Html.t_style,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":name"),
                    Vx.Core.vx_new_string(".passflag"),
                    Vx.Core.vx_new_string(":props"),
                    Vx.Core.f_new(
                      Vx.Web.Html.t_propmap,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.vx_new_string("background-color"),
                        Vx.Core.vx_new_string("green"),
                        Vx.Core.vx_new_string("color"),
                        Vx.Core.vx_new_string("white"),
                        Vx.Core.vx_new_string("padding-left"),
                        Vx.Core.vx_new_string("4px"),
                        Vx.Core.vx_new_string("padding-right"),
                        Vx.Core.vx_new_string("4px"),
                        Vx.Core.vx_new_string("padding-top"),
                        Vx.Core.vx_new_string("1px"),
                        Vx.Core.vx_new_string("padding-bottom"),
                        Vx.Core.vx_new_string("1px")
                      )
                    )
                  )
                ),
                Vx.Core.f_new(
                  Vx.Web.Html.t_style,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":name"),
                    Vx.Core.vx_new_string(".coveragenums"),
                    Vx.Core.vx_new_string(":props"),
                    Vx.Core.f_new(
                      Vx.Web.Html.t_propmap,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.vx_new_string("width"),
                        Vx.Core.vx_new_string("90px")
                      )
                    )
                  )
                ),
                Vx.Core.f_new(
                  Vx.Web.Html.t_style,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":name"),
                    Vx.Core.vx_new_string(".coveragepct"),
                    Vx.Core.vx_new_string(":props"),
                    Vx.Core.f_new(
                      Vx.Web.Html.t_propmap,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.vx_new_string("text-align"),
                        Vx.Core.vx_new_string("right")
                      )
                    )
                  )
                ),
                Vx.Core.f_new(
                  Vx.Web.Html.t_style,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":name"),
                    Vx.Core.vx_new_string(".coveragepctgreen"),
                    Vx.Core.vx_new_string(":props"),
                    Vx.Core.f_new(
                      Vx.Web.Html.t_propmap,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.vx_new_string("background-color"),
                        Vx.Core.vx_new_string("green"),
                        Vx.Core.vx_new_string("color"),
                        Vx.Core.vx_new_string("white"),
                        Vx.Core.vx_new_string("text-align"),
                        Vx.Core.vx_new_string("right")
                      )
                    )
                  )
                ),
                Vx.Core.f_new(
                  Vx.Web.Html.t_style,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":name"),
                    Vx.Core.vx_new_string(".coveragepctred"),
                    Vx.Core.vx_new_string(":props"),
                    Vx.Core.f_new(
                      Vx.Web.Html.t_propmap,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.vx_new_string("background-color"),
                        Vx.Core.vx_new_string("red"),
                        Vx.Core.vx_new_string("color"),
                        Vx.Core.vx_new_string("white"),
                        Vx.Core.vx_new_string("text-align"),
                        Vx.Core.vx_new_string("right")
                      )
                    )
                  )
                ),
                Vx.Core.f_new(
                  Vx.Web.Html.t_style,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":name"),
                    Vx.Core.vx_new_string(".pkgheader"),
                    Vx.Core.vx_new_string(":props"),
                    Vx.Core.f_new(
                      Vx.Web.Html.t_propmap,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.vx_new_string("display"),
                        Vx.Core.vx_new_string("inline-flex"),
                        Vx.Core.vx_new_string("gap"),
                        Vx.Core.vx_new_string("10px")
                      )
                    )
                  )
                ),
                Vx.Core.f_new(
                  Vx.Web.Html.t_style,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":name"),
                    Vx.Core.vx_new_string(".pkgname"),
                    Vx.Core.vx_new_string(":props"),
                    Vx.Core.f_new(
                      Vx.Web.Html.t_propmap,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.vx_new_string("font-weight"),
                        Vx.Core.vx_new_string("bold"),
                        Vx.Core.vx_new_string("width"),
                        Vx.Core.vx_new_string("180px")
                      )
                    )
                  )
                ),
                Vx.Core.f_new(
                  Vx.Web.Html.t_style,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":name"),
                    Vx.Core.vx_new_string(".preformatted"),
                    Vx.Core.vx_new_string(":props"),
                    Vx.Core.f_new(
                      Vx.Web.Html.t_propmap,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.vx_new_string("display"),
                        Vx.Core.vx_new_string("block"),
                        Vx.Core.vx_new_string("unicode-bidi"),
                        Vx.Core.vx_new_string("embed"),
                        Vx.Core.vx_new_string("font-family"),
                        Vx.Core.vx_new_string("monospace"),
                        Vx.Core.vx_new_string("white-space"),
                        Vx.Core.vx_new_string("pre")
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
  public interface Func_context_test : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_context vx_context_test(Vx.Core.Type_anylist args);
  }

  public class Class_context_test : Vx.Core.Class_base, Func_context_test {

    public override Vx.Test.Func_context_test vx_new(params Object[] vals) {
      Class_context_test output = new Class_context_test();
      return output;
    }

    public override Vx.Test.Func_context_test vx_copy(params Object[] vals) {
      Class_context_test output = new Class_context_test();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "context-test", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "context", // name
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
      return e_context_test;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_context_test;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_anylist inputval = (Vx.Core.Type_anylist)value;
      Vx.Core.Type_any outputval = Vx.Test.f_context_test(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_anylist args = Vx.Core.f_any_from_any(Vx.Core.t_anylist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Test.f_context_test(args);
      return output;
    }

    public Vx.Core.Type_context vx_context_test(Vx.Core.Type_anylist args) {
      return Vx.Test.f_context_test(args);
    }

  }

  public static Func_context_test e_context_test = new Vx.Test.Class_context_test();
  public static Func_context_test t_context_test = new Vx.Test.Class_context_test();

  public static Vx.Core.Type_context f_context_test(Vx.Core.Type_anylist args) {
    Vx.Core.Type_context output = Vx.Core.e_context;
    output = Vx.Core.f_new(
      Vx.Core.t_context,
      Vx.Core.vx_new(Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":session"),
        Vx.Core.f_new(
          Vx.Core.t_session,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":user"),
            Vx.Core.f_new(
              Vx.Core.t_user,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":security"),
                Vx.Test.f_security_test()
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
  public interface Func_div_from_testcaselist : Vx.Core.Func_any_from_any {
    public Vx.Web.Html.Type_div vx_div_from_testcaselist(Vx.Test.Type_testcaselist testcaselist);
  }

  public class Class_div_from_testcaselist : Vx.Core.Class_base, Func_div_from_testcaselist {

    public override Vx.Test.Func_div_from_testcaselist vx_new(params Object[] vals) {
      Class_div_from_testcaselist output = new Class_div_from_testcaselist();
      return output;
    }

    public override Vx.Test.Func_div_from_testcaselist vx_copy(params Object[] vals) {
      Class_div_from_testcaselist output = new Class_div_from_testcaselist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "div<-testcaselist", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "div", // name
          ":struct", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_node, Vx.Web.Html.t_divchild), // traits
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
      return e_div_from_testcaselist;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_div_from_testcaselist;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Test.Type_testcaselist inputval = (Vx.Test.Type_testcaselist)value;
      Vx.Core.Type_any outputval = Vx.Test.f_div_from_testcaselist(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Test.Type_testcaselist testcaselist = Vx.Core.f_any_from_any(Vx.Test.t_testcaselist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Test.f_div_from_testcaselist(testcaselist);
      return output;
    }

    public Vx.Web.Html.Type_div vx_div_from_testcaselist(Vx.Test.Type_testcaselist testcaselist) {
      return Vx.Test.f_div_from_testcaselist(testcaselist);
    }

  }

  public static Func_div_from_testcaselist e_div_from_testcaselist = new Vx.Test.Class_div_from_testcaselist();
  public static Func_div_from_testcaselist t_div_from_testcaselist = new Vx.Test.Class_div_from_testcaselist();

  public static Vx.Web.Html.Type_div f_div_from_testcaselist(Vx.Test.Type_testcaselist testcaselist) {
    Vx.Web.Html.Type_div output = Vx.Web.Html.e_div;
    output = Vx.Core.f_new(
      Vx.Web.Html.t_div,
      Vx.Core.vx_new(Vx.Core.t_anylist,
        Vx.Core.f_new(
          Vx.Web.Html.t_table,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":thead"),
            Vx.Core.f_new(
              Vx.Web.Html.t_thead,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.f_new(
                  Vx.Web.Html.t_tr,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.f_new(
                      Vx.Web.Html.t_td,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.f_new(
                          Vx.Web.Html.t_p,
                          Vx.Core.vx_new(Vx.Core.t_anylist,
                            Vx.Core.vx_new_string(":text"),
                            Vx.Core.vx_new_string("Pass?")
                          )
                        )
                      )
                    ),
                    Vx.Core.f_new(
                      Vx.Web.Html.t_td,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.f_new(
                          Vx.Web.Html.t_p,
                          Vx.Core.vx_new(Vx.Core.t_anylist,
                            Vx.Core.vx_new_string(":text"),
                            Vx.Core.vx_new_string("Name")
                          )
                        )
                      )
                    ),
                    Vx.Core.f_new(
                      Vx.Web.Html.t_td,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.f_new(
                          Vx.Web.Html.t_p,
                          Vx.Core.vx_new(Vx.Core.t_anylist,
                            Vx.Core.vx_new_string(":text"),
                            Vx.Core.vx_new_string("Test")
                          )
                        )
                      )
                    ),
                    Vx.Core.f_new(
                      Vx.Web.Html.t_td,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.f_new(
                          Vx.Web.Html.t_p,
                          Vx.Core.vx_new(Vx.Core.t_anylist,
                            Vx.Core.vx_new_string(":text"),
                            Vx.Core.vx_new_string("Expected")
                          )
                        )
                      )
                    ),
                    Vx.Core.f_new(
                      Vx.Web.Html.t_td,
                      Vx.Core.vx_new(Vx.Core.t_anylist,
                        Vx.Core.f_new(
                          Vx.Web.Html.t_p,
                          Vx.Core.vx_new(Vx.Core.t_anylist,
                            Vx.Core.vx_new_string(":text"),
                            Vx.Core.vx_new_string("Actual")
                          )
                        )
                      )
                    )
                  )
                )
              )
            ),
            Vx.Core.vx_new_string(":tbody"),
            Vx.Core.f_new(
              Vx.Web.Html.t_tbody,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Test.f_trlist_from_testcaselist(testcaselist)
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
  public interface Func_div_from_testpackage : Vx.Core.Func_any_from_any {
    public Vx.Web.Html.Type_div vx_div_from_testpackage(Vx.Test.Type_testpackage testpackage);
  }

  public class Class_div_from_testpackage : Vx.Core.Class_base, Func_div_from_testpackage {

    public override Vx.Test.Func_div_from_testpackage vx_new(params Object[] vals) {
      Class_div_from_testpackage output = new Class_div_from_testpackage();
      return output;
    }

    public override Vx.Test.Func_div_from_testpackage vx_copy(params Object[] vals) {
      Class_div_from_testpackage output = new Class_div_from_testpackage();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "div<-testpackage", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "div", // name
          ":struct", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_node, Vx.Web.Html.t_divchild), // traits
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
      return e_div_from_testpackage;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_div_from_testpackage;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Test.Type_testpackage inputval = (Vx.Test.Type_testpackage)value;
      Vx.Core.Type_any outputval = Vx.Test.f_div_from_testpackage(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Test.Type_testpackage testpackage = Vx.Core.f_any_from_any(Vx.Test.t_testpackage, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Test.f_div_from_testpackage(testpackage);
      return output;
    }

    public Vx.Web.Html.Type_div vx_div_from_testpackage(Vx.Test.Type_testpackage testpackage) {
      return Vx.Test.f_div_from_testpackage(testpackage);
    }

  }

  public static Func_div_from_testpackage e_div_from_testpackage = new Vx.Test.Class_div_from_testpackage();
  public static Func_div_from_testpackage t_div_from_testpackage = new Vx.Test.Class_div_from_testpackage();

  public static Vx.Web.Html.Type_div f_div_from_testpackage(Vx.Test.Type_testpackage testpackage) {
    Vx.Web.Html.Type_div output = Vx.Web.Html.e_div;
    output = Vx.Core.f_let(
      Vx.Web.Html.t_div,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Test.Type_testcoveragesummary testcoveragesummary = testpackage.coveragesummary();
        Vx.Core.Type_string pkgname = testpackage.testpkg();
        Vx.Test.Type_testcaselist caselist = testpackage.caselist();
        Vx.Core.Type_boolean passfail = testpackage.passfail();
        Vx.Web.Html.Type_style pkgnamestyle = Vx.Web.Html.f_style_from_stylesheet_name(
          Vx.Test.c_stylesheet_test,
          Vx.Core.vx_new_string(".pkgname")
        );
        Vx.Web.Html.Type_div node = Vx.Test.f_div_from_testcaselist(caselist);
        Vx.Web.Html.Type_divchildlist nodes = Vx.Core.f_new(
          Vx.Web.Html.t_divchildlist,
          Vx.Core.vx_new(Vx.Core.t_anylist,
              node
          )
        );
        Vx.Web.Html.Type_p p_passfail = Vx.Test.f_p_from_passfail(passfail);
        Vx.Web.Html.Type_p p_pkgname = Vx.Core.f_new(
          Vx.Web.Html.t_p,
          Vx.Core.vx_new(Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":style"),
              pkgnamestyle,
              Vx.Core.vx_new_string(":text"),
              pkgname
          )
        );
        Vx.Web.Html.Type_p p_totalnums = Vx.Test.f_p_from_testcoveragenums(
          testcoveragesummary.totalnums()
        );
        Vx.Web.Html.Type_p p_coveragenums = Vx.Test.f_p_from_testcoveragenums(
          testcoveragesummary.typenums()
        );
        Vx.Web.Html.Type_p p_constnums = Vx.Test.f_p_from_testcoveragenums(
          testcoveragesummary.constnums()
        );
        Vx.Web.Html.Type_p p_funcnums = Vx.Test.f_p_from_testcoveragenums(
          testcoveragesummary.funcnums()
        );
        Vx.Web.Html.Type_p p_docnums = Vx.Test.f_p_from_testcoveragenums(
          testcoveragesummary.docnums()
        );
        Vx.Web.Html.Type_p p_bigospacenums = Vx.Test.f_p_from_testcoveragenums(
          testcoveragesummary.bigospacenums()
        );
        Vx.Web.Html.Type_p p_bigotimenums = Vx.Test.f_p_from_testcoveragenums(
          testcoveragesummary.bigotimenums()
        );
        Vx.Web.Html.Type_divchildlist summary = Vx.Core.f_new(
          Vx.Web.Html.t_divchildlist,
          Vx.Core.vx_new(Vx.Core.t_anylist,
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
        Vx.Web.Html.Type_details details = Vx.Core.f_new(
          Vx.Web.Html.t_details,
          Vx.Core.vx_new(Vx.Core.t_anylist,
              Vx.Core.vx_new_string(":summary"),
              summary,
              Vx.Core.vx_new_string(":nodes"),
              nodes
          )
        );
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Web.Html.t_div,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            details
          )
        );
        return output_1;
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
  public interface Func_div_from_testpackagelist : Vx.Core.Func_any_from_any {
    public Vx.Web.Html.Type_div vx_div_from_testpackagelist(Vx.Test.Type_testpackagelist testpackagelist);
  }

  public class Class_div_from_testpackagelist : Vx.Core.Class_base, Func_div_from_testpackagelist {

    public override Vx.Test.Func_div_from_testpackagelist vx_new(params Object[] vals) {
      Class_div_from_testpackagelist output = new Class_div_from_testpackagelist();
      return output;
    }

    public override Vx.Test.Func_div_from_testpackagelist vx_copy(params Object[] vals) {
      Class_div_from_testpackagelist output = new Class_div_from_testpackagelist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "div<-testpackagelist", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "div", // name
          ":struct", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_node, Vx.Web.Html.t_divchild), // traits
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
      return e_div_from_testpackagelist;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_div_from_testpackagelist;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Test.Type_testpackagelist inputval = (Vx.Test.Type_testpackagelist)value;
      Vx.Core.Type_any outputval = Vx.Test.f_div_from_testpackagelist(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Test.Type_testpackagelist testpackagelist = Vx.Core.f_any_from_any(Vx.Test.t_testpackagelist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Test.f_div_from_testpackagelist(testpackagelist);
      return output;
    }

    public Vx.Web.Html.Type_div vx_div_from_testpackagelist(Vx.Test.Type_testpackagelist testpackagelist) {
      return Vx.Test.f_div_from_testpackagelist(testpackagelist);
    }

  }

  public static Func_div_from_testpackagelist e_div_from_testpackagelist = new Vx.Test.Class_div_from_testpackagelist();
  public static Func_div_from_testpackagelist t_div_from_testpackagelist = new Vx.Test.Class_div_from_testpackagelist();

  public static Vx.Web.Html.Type_div f_div_from_testpackagelist(Vx.Test.Type_testpackagelist testpackagelist) {
    Vx.Web.Html.Type_div output = Vx.Web.Html.e_div;
    output = Vx.Core.f_let(
      Vx.Web.Html.t_div,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Web.Html.Type_style stylepassfail = Vx.Web.Html.f_style_from_stylesheet_name(
          Vx.Test.c_stylesheet_test,
          Vx.Core.vx_new_string(".passfail")
        );
        Vx.Web.Html.Type_style stylepkgname = Vx.Web.Html.f_style_from_stylesheet_name(
          Vx.Test.c_stylesheet_test,
          Vx.Core.vx_new_string(".pkgname")
        );
        Vx.Web.Html.Type_style stylepkgheader = Vx.Web.Html.f_style_from_stylesheet_name(
          Vx.Test.c_stylesheet_test,
          Vx.Core.vx_new_string(".pkgheader")
        );
        Vx.Web.Html.Type_style stylecoveragenum = Vx.Web.Html.f_style_from_stylesheet_name(
          Vx.Test.c_stylesheet_test,
          Vx.Core.vx_new_string(".coveragenums")
        );
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Web.Html.t_div,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.f_new(
              Vx.Web.Html.t_div,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":style"),
                stylepkgheader,
                Vx.Core.f_new(
                  Vx.Web.Html.t_p,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":style"),
                    stylepassfail,
                    Vx.Core.vx_new_string(":text"),
                    Vx.Core.vx_new_string("Pass?")
                  )
                ),
                Vx.Core.f_new(
                  Vx.Web.Html.t_p,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":style"),
                    stylepkgname,
                    Vx.Core.vx_new_string(":text"),
                    Vx.Core.vx_new_string("Package Name")
                  )
                ),
                Vx.Core.f_new(
                  Vx.Web.Html.t_p,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":style"),
                    stylecoveragenum,
                    Vx.Core.vx_new_string(":text"),
                    Vx.Core.vx_new_string("Coverage")
                  )
                ),
                Vx.Core.f_new(
                  Vx.Web.Html.t_p,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":style"),
                    stylecoveragenum,
                    Vx.Core.vx_new_string(":text"),
                    Vx.Core.vx_new_string("(type)")
                  )
                ),
                Vx.Core.f_new(
                  Vx.Web.Html.t_p,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":style"),
                    stylecoveragenum,
                    Vx.Core.vx_new_string(":text"),
                    Vx.Core.vx_new_string("(const)")
                  )
                ),
                Vx.Core.f_new(
                  Vx.Web.Html.t_p,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":style"),
                    stylecoveragenum,
                    Vx.Core.vx_new_string(":text"),
                    Vx.Core.vx_new_string("(func)")
                  )
                ),
                Vx.Core.f_new(
                  Vx.Web.Html.t_p,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":style"),
                    stylecoveragenum,
                    Vx.Core.vx_new_string(":text"),
                    Vx.Core.vx_new_string(":doc")
                  )
                ),
                Vx.Core.f_new(
                  Vx.Web.Html.t_p,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":style"),
                    stylecoveragenum,
                    Vx.Core.vx_new_string(":text"),
                    Vx.Core.vx_new_string(":bigospace")
                  )
                ),
                Vx.Core.f_new(
                  Vx.Web.Html.t_p,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":style"),
                    stylecoveragenum,
                    Vx.Core.vx_new_string(":text"),
                    Vx.Core.vx_new_string(":bigotime")
                  )
                )
              )
            ),
            Vx.Core.f_new(
              Vx.Web.Html.t_div,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Test.f_divchildlist_from_testpackagelist(testpackagelist)
              )
            )
          )
        );
        return output_1;
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
  public interface Func_divchildlist_from_testpackagelist : Vx.Core.Func_any_from_any {
    public Vx.Web.Html.Type_divchildlist vx_divchildlist_from_testpackagelist(Vx.Test.Type_testpackagelist testpackagelist);
  }

  public class Class_divchildlist_from_testpackagelist : Vx.Core.Class_base, Func_divchildlist_from_testpackagelist {

    public override Vx.Test.Func_divchildlist_from_testpackagelist vx_new(params Object[] vals) {
      Class_divchildlist_from_testpackagelist output = new Class_divchildlist_from_testpackagelist();
      return output;
    }

    public override Vx.Test.Func_divchildlist_from_testpackagelist vx_copy(params Object[] vals) {
      Class_divchildlist_from_testpackagelist output = new Class_divchildlist_from_testpackagelist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "divchildlist<-testpackagelist", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "divchildlist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_divchild), // allowtypes
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
      return e_divchildlist_from_testpackagelist;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_divchildlist_from_testpackagelist;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Test.Type_testpackagelist inputval = (Vx.Test.Type_testpackagelist)value;
      Vx.Core.Type_any outputval = Vx.Test.f_divchildlist_from_testpackagelist(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Test.Type_testpackagelist testpackagelist = Vx.Core.f_any_from_any(Vx.Test.t_testpackagelist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Test.f_divchildlist_from_testpackagelist(testpackagelist);
      return output;
    }

    public Vx.Web.Html.Type_divchildlist vx_divchildlist_from_testpackagelist(Vx.Test.Type_testpackagelist testpackagelist) {
      return Vx.Test.f_divchildlist_from_testpackagelist(testpackagelist);
    }

  }

  public static Func_divchildlist_from_testpackagelist e_divchildlist_from_testpackagelist = new Vx.Test.Class_divchildlist_from_testpackagelist();
  public static Func_divchildlist_from_testpackagelist t_divchildlist_from_testpackagelist = new Vx.Test.Class_divchildlist_from_testpackagelist();

  public static Vx.Web.Html.Type_divchildlist f_divchildlist_from_testpackagelist(Vx.Test.Type_testpackagelist testpackagelist) {
    Vx.Web.Html.Type_divchildlist output = Vx.Web.Html.e_divchildlist;
    output = Vx.Core.f_list_from_list_1(
      Vx.Web.Html.t_divchildlist,
      testpackagelist,
      Vx.Test.t_div_from_testpackage
    );
    return output;
  }

  /**
   * @function file_test
   * Default file location for testsuite.vxlisp
   * @return {file}
   * (func file-test)
   */
  public interface Func_file_test : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.File.Type_file vx_file_test();
  }

  public class Class_file_test : Vx.Core.Class_base, Func_file_test {

    public override Vx.Test.Func_file_test vx_new(params Object[] vals) {
      Class_file_test output = new Class_file_test();
      return output;
    }

    public override Vx.Test.Func_file_test vx_copy(params Object[] vals) {
      Class_file_test output = new Class_file_test();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "file-test", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/file", // pkgname
          "file", // name
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
      return e_file_test;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_file_test;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      output = Vx.Test.f_file_test();
      return output;
    }

    public Vx.Data.File.Type_file vx_file_test() {
      return Vx.Test.f_file_test();
    }

  }

  public static Func_file_test e_file_test = new Vx.Test.Class_file_test();
  public static Func_file_test t_file_test = new Vx.Test.Class_file_test();

  public static Vx.Data.File.Type_file f_file_test() {
    Vx.Data.File.Type_file output = Vx.Data.File.e_file;
    output = Vx.Core.f_new(
      Vx.Data.File.t_file,
      Vx.Core.vx_new(Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":name"),
        Vx.Core.vx_new_string("testsuite.vxlisp"),
        Vx.Core.vx_new_string(":path"),
        Vx.Core.vx_new_string("src/test/resources")
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
  public interface Func_file_testhtml : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.File.Type_file vx_file_testhtml();
  }

  public class Class_file_testhtml : Vx.Core.Class_base, Func_file_testhtml {

    public override Vx.Test.Func_file_testhtml vx_new(params Object[] vals) {
      Class_file_testhtml output = new Class_file_testhtml();
      return output;
    }

    public override Vx.Test.Func_file_testhtml vx_copy(params Object[] vals) {
      Class_file_testhtml output = new Class_file_testhtml();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "file-testhtml", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/file", // pkgname
          "file", // name
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
      return e_file_testhtml;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_file_testhtml;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      output = Vx.Test.f_file_testhtml();
      return output;
    }

    public Vx.Data.File.Type_file vx_file_testhtml() {
      return Vx.Test.f_file_testhtml();
    }

  }

  public static Func_file_testhtml e_file_testhtml = new Vx.Test.Class_file_testhtml();
  public static Func_file_testhtml t_file_testhtml = new Vx.Test.Class_file_testhtml();

  public static Vx.Data.File.Type_file f_file_testhtml() {
    Vx.Data.File.Type_file output = Vx.Data.File.e_file;
    output = Vx.Core.f_new(
      Vx.Data.File.t_file,
      Vx.Core.vx_new(Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":name"),
        Vx.Core.vx_new_string("testsuite.html"),
        Vx.Core.vx_new_string(":path"),
        Vx.Core.vx_new_string("src/test/resources")
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
  public interface Func_file_testnode : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Data.File.Type_file vx_file_testnode();
  }

  public class Class_file_testnode : Vx.Core.Class_base, Func_file_testnode {

    public override Vx.Test.Func_file_testnode vx_new(params Object[] vals) {
      Class_file_testnode output = new Class_file_testnode();
      return output;
    }

    public override Vx.Test.Func_file_testnode vx_copy(params Object[] vals) {
      Class_file_testnode output = new Class_file_testnode();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "file-testnode", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/data/file", // pkgname
          "file", // name
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
      return e_file_testnode;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_file_testnode;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      output = Vx.Test.f_file_testnode();
      return output;
    }

    public Vx.Data.File.Type_file vx_file_testnode() {
      return Vx.Test.f_file_testnode();
    }

  }

  public static Func_file_testnode e_file_testnode = new Vx.Test.Class_file_testnode();
  public static Func_file_testnode t_file_testnode = new Vx.Test.Class_file_testnode();

  public static Vx.Data.File.Type_file f_file_testnode() {
    Vx.Data.File.Type_file output = Vx.Data.File.e_file;
    output = Vx.Core.f_new(
      Vx.Data.File.t_file,
      Vx.Core.vx_new(Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":name"),
        Vx.Core.vx_new_string("testsuitenode.vxlisp"),
        Vx.Core.vx_new_string(":path"),
        Vx.Core.vx_new_string("src/test/resources")
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
  public interface Func_html_from_divtest : Vx.Core.Func_any_from_any {
    public Vx.Web.Html.Type_html vx_html_from_divtest(Vx.Web.Html.Type_div divtest);
  }

  public class Class_html_from_divtest : Vx.Core.Class_base, Func_html_from_divtest {

    public override Vx.Test.Func_html_from_divtest vx_new(params Object[] vals) {
      Class_html_from_divtest output = new Class_html_from_divtest();
      return output;
    }

    public override Vx.Test.Func_html_from_divtest vx_copy(params Object[] vals) {
      Class_html_from_divtest output = new Class_html_from_divtest();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "html<-divtest", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "html", // name
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
      return e_html_from_divtest;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_html_from_divtest;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Web.Html.Type_div inputval = (Vx.Web.Html.Type_div)value;
      Vx.Core.Type_any outputval = Vx.Test.f_html_from_divtest(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Web.Html.Type_div divtest = Vx.Core.f_any_from_any(Vx.Web.Html.t_div, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Test.f_html_from_divtest(divtest);
      return output;
    }

    public Vx.Web.Html.Type_html vx_html_from_divtest(Vx.Web.Html.Type_div divtest) {
      return Vx.Test.f_html_from_divtest(divtest);
    }

  }

  public static Func_html_from_divtest e_html_from_divtest = new Vx.Test.Class_html_from_divtest();
  public static Func_html_from_divtest t_html_from_divtest = new Vx.Test.Class_html_from_divtest();

  public static Vx.Web.Html.Type_html f_html_from_divtest(Vx.Web.Html.Type_div divtest) {
    Vx.Web.Html.Type_html output = Vx.Web.Html.e_html;
    output = Vx.Core.f_new(
      Vx.Web.Html.t_html,
      Vx.Core.vx_new(Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":lang"),
        Vx.Core.vx_new_string("en"),
        Vx.Core.vx_new_string(":head"),
        Vx.Core.f_new(
          Vx.Web.Html.t_head,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.f_new(
              Vx.Web.Html.t_meta,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":charset"),
                Vx.Core.vx_new_string("utf-8")
              )
            ),
            Vx.Core.f_new(
              Vx.Web.Html.t_meta,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":name"),
                Vx.Core.vx_new_string("viewport"),
                Vx.Core.vx_new_string(":content"),
                Vx.Core.vx_new_string("width=device-width, initial-scale=1.0")
              )
            ),
            Vx.Core.f_new(
              Vx.Web.Html.t_title,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":text"),
                Vx.Core.vx_new_string("Test Suite")
              )
            ),
            Vx.Test.c_stylesheet_test
          )
        ),
        Vx.Core.vx_new_string(":body"),
        Vx.Core.f_new(
          Vx.Web.Html.t_body,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.f_new(
              Vx.Web.Html.t_div,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.f_new(
                  Vx.Web.Html.t_h1,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string("Test Suite")
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
  public interface Func_p_from_passfail : Vx.Core.Func_any_from_any {
    public Vx.Web.Html.Type_p vx_p_from_passfail(Vx.Core.Type_boolean passfail);
  }

  public class Class_p_from_passfail : Vx.Core.Class_base, Func_p_from_passfail {

    public override Vx.Test.Func_p_from_passfail vx_new(params Object[] vals) {
      Class_p_from_passfail output = new Class_p_from_passfail();
      return output;
    }

    public override Vx.Test.Func_p_from_passfail vx_copy(params Object[] vals) {
      Class_p_from_passfail output = new Class_p_from_passfail();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "p<-passfail", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "p", // name
          ":struct", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_node, Vx.Web.Html.t_divchild), // traits
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
      return e_p_from_passfail;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_p_from_passfail;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_boolean inputval = (Vx.Core.Type_boolean)value;
      Vx.Core.Type_any outputval = Vx.Test.f_p_from_passfail(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_boolean passfail = Vx.Core.f_any_from_any(Vx.Core.t_boolean, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Test.f_p_from_passfail(passfail);
      return output;
    }

    public Vx.Web.Html.Type_p vx_p_from_passfail(Vx.Core.Type_boolean passfail) {
      return Vx.Test.f_p_from_passfail(passfail);
    }

  }

  public static Func_p_from_passfail e_p_from_passfail = new Vx.Test.Class_p_from_passfail();
  public static Func_p_from_passfail t_p_from_passfail = new Vx.Test.Class_p_from_passfail();

  public static Vx.Web.Html.Type_p f_p_from_passfail(Vx.Core.Type_boolean passfail) {
    Vx.Web.Html.Type_p output = Vx.Web.Html.e_p;
    output = Vx.Core.f_let(
      Vx.Web.Html.t_p,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string text = Vx.Core.f_if_1(Vx.Core.t_string, passfail, Vx.Core.vx_new_string("Pass"), Vx.Core.vx_new_string("Fail"));
        Vx.Core.Type_string stylename = Vx.Core.f_if_1(Vx.Core.t_string, passfail, Vx.Core.vx_new_string(".passflag"), Vx.Core.vx_new_string(".failflag"));
        Vx.Web.Html.Type_style style = Vx.Web.Html.f_style_from_stylesheet_name(
          Vx.Test.c_stylesheet_test,
          stylename
        );
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Web.Html.t_p,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":style"),
            style,
            Vx.Core.vx_new_string(":text"),
            text
          )
        );
        return output_1;
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
  public interface Func_p_from_testcoveragenums : Vx.Core.Func_any_from_any {
    public Vx.Web.Html.Type_p vx_p_from_testcoveragenums(Vx.Test.Type_testcoveragenums nums);
  }

  public class Class_p_from_testcoveragenums : Vx.Core.Class_base, Func_p_from_testcoveragenums {

    public override Vx.Test.Func_p_from_testcoveragenums vx_new(params Object[] vals) {
      Class_p_from_testcoveragenums output = new Class_p_from_testcoveragenums();
      return output;
    }

    public override Vx.Test.Func_p_from_testcoveragenums vx_copy(params Object[] vals) {
      Class_p_from_testcoveragenums output = new Class_p_from_testcoveragenums();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "p<-testcoveragenums", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "p", // name
          ":struct", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_node, Vx.Web.Html.t_divchild), // traits
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
      return e_p_from_testcoveragenums;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_p_from_testcoveragenums;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Test.Type_testcoveragenums inputval = (Vx.Test.Type_testcoveragenums)value;
      Vx.Core.Type_any outputval = Vx.Test.f_p_from_testcoveragenums(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Test.Type_testcoveragenums nums = Vx.Core.f_any_from_any(Vx.Test.t_testcoveragenums, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Test.f_p_from_testcoveragenums(nums);
      return output;
    }

    public Vx.Web.Html.Type_p vx_p_from_testcoveragenums(Vx.Test.Type_testcoveragenums nums) {
      return Vx.Test.f_p_from_testcoveragenums(nums);
    }

  }

  public static Func_p_from_testcoveragenums e_p_from_testcoveragenums = new Vx.Test.Class_p_from_testcoveragenums();
  public static Func_p_from_testcoveragenums t_p_from_testcoveragenums = new Vx.Test.Class_p_from_testcoveragenums();

  public static Vx.Web.Html.Type_p f_p_from_testcoveragenums(Vx.Test.Type_testcoveragenums nums) {
    Vx.Web.Html.Type_p output = Vx.Web.Html.e_p;
    output = Vx.Core.f_new(
      Vx.Web.Html.t_p,
      Vx.Core.vx_new(Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":style"),
        Vx.Web.Html.f_style_from_stylesheet_name(
          Vx.Test.c_stylesheet_test,
          Vx.Core.vx_new_string(".coveragenums")
        ),
        Vx.Core.vx_new_string(":text"),
        Vx.Core.f_new(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            nums.pct(),
            Vx.Core.vx_new_string("% "),
            nums.tests(),
            Vx.Core.vx_new_string("/"),
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
  public interface Func_resolve_testcase : Vx.Core.Func_any_from_any_async {
    public Task<Vx.Test.Type_testcase> vx_resolve_testcase(Vx.Test.Type_testcase testcase);
  }

  public class Class_resolve_testcase : Vx.Core.Class_base, Func_resolve_testcase {

    public override Vx.Test.Func_resolve_testcase vx_new(params Object[] vals) {
      Class_resolve_testcase output = new Class_resolve_testcase();
      return output;
    }

    public override Vx.Test.Func_resolve_testcase vx_copy(params Object[] vals) {
      Class_resolve_testcase output = new Class_resolve_testcase();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testcase", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/test", // pkgname
          "testcase", // name
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
      return e_resolve_testcase;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_resolve_testcase;
    }

    public Vx.Core.Func_any_from_any_async vx_fn_new(Vx.Core.Class_any_from_any_async.IFn fn) {
      return Vx.Core.e_any_from_any_async;
    }

    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      Vx.Test.Type_testcase inputval = Vx.Core.f_any_from_any(Vx.Test.t_testcase, value);
      Task<Vx.Test.Type_testcase> future = Vx.Test.f_resolve_testcase(inputval);
      Task<T> output = Vx.Core.vx_async_from_async(generic_any_1, future);
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_completed(Vx.Core.e_any);
      Vx.Test.Type_testcase testcase = Vx.Core.f_any_from_any(Vx.Test.t_testcase, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Task<Vx.Test.Type_testcase> future = Vx.Test.f_resolve_testcase(testcase);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<Vx.Test.Type_testcase> vx_resolve_testcase(Vx.Test.Type_testcase testcase) {
      return Vx.Test.f_resolve_testcase(testcase);
    }

  }

  public static Func_resolve_testcase e_resolve_testcase = new Vx.Test.Class_resolve_testcase();
  public static Func_resolve_testcase t_resolve_testcase = new Vx.Test.Class_resolve_testcase();

  public static Task<Vx.Test.Type_testcase> f_resolve_testcase(Vx.Test.Type_testcase testcase) {
    Task<Vx.Test.Type_testcase> output = Vx.Core.vx_async_new_completed(Vx.Test.e_testcase);
    output = Vx.Core.f_let_async(
      Vx.Test.t_testcase,
      Vx.Core.t_any_from_func_async.vx_fn_new(() => {
        Vx.Test.Type_testdescribelist describelist = testcase.describelist();
        Task<Vx.Test.Type_testdescribelist> future_resolvedlist = Vx.Test.f_resolve_testdescribelist(describelist);
        Task<Vx.Core.Type_any> output_1 = Vx.Core.vx_async_from_async_fn(future_resolvedlist, (resolvedlist) => {;
          Vx.Core.Type_booleanlist passfaillist = Vx.Core.f_list_from_list_1(
            Vx.Core.t_booleanlist,
            resolvedlist,
            Vx.Core.t_any_from_any.vx_fn_new((testdescribe_any) => {
              Vx.Test.Type_testdescribe testdescribe = Vx.Core.f_any_from_any(Vx.Test.t_testdescribe, testdescribe_any);
              Vx.Core.Type_any output_2 = 
                    Vx.Core.f_let(
                      Vx.Core.t_boolean,
                      Vx.Core.t_any_from_func.vx_fn_new(() => {
                        Vx.Test.Type_testresult testresult = testdescribe.testresult();
                        Vx.Core.Type_any output_3 = testresult.passfail();
                        return output_3;
                      })
                    );
              return output_2;
            })
          );
          Vx.Core.Type_boolean passfail = Vx.Core.f_and_1(passfaillist);
          Vx.Core.Type_any output_4 = Vx.Core.f_copy(
            testcase,
            Vx.Core.vx_new(Vx.Core.t_anylist,
                  Vx.Core.vx_new_string(":passfail"),
                  passfail,
                  Vx.Core.vx_new_string(":describelist"),
                  resolvedlist
            )
          );
          return output_4;
        });
        return output_1;
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
  public interface Func_resolve_testcaselist : Vx.Core.Func_any_from_any_async {
    public Task<Vx.Test.Type_testcaselist> vx_resolve_testcaselist(Vx.Test.Type_testcaselist testcaselist);
  }

  public class Class_resolve_testcaselist : Vx.Core.Class_base, Func_resolve_testcaselist {

    public override Vx.Test.Func_resolve_testcaselist vx_new(params Object[] vals) {
      Class_resolve_testcaselist output = new Class_resolve_testcaselist();
      return output;
    }

    public override Vx.Test.Func_resolve_testcaselist vx_copy(params Object[] vals) {
      Class_resolve_testcaselist output = new Class_resolve_testcaselist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testcaselist", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/test", // pkgname
          "testcaselist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Test.t_testcase), // allowtypes
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
      return e_resolve_testcaselist;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_resolve_testcaselist;
    }

    public Vx.Core.Func_any_from_any_async vx_fn_new(Vx.Core.Class_any_from_any_async.IFn fn) {
      return Vx.Core.e_any_from_any_async;
    }

    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      Vx.Test.Type_testcaselist inputval = Vx.Core.f_any_from_any(Vx.Test.t_testcaselist, value);
      Task<Vx.Test.Type_testcaselist> future = Vx.Test.f_resolve_testcaselist(inputval);
      Task<T> output = Vx.Core.vx_async_from_async(generic_any_1, future);
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_completed(Vx.Core.e_any);
      Vx.Test.Type_testcaselist testcaselist = Vx.Core.f_any_from_any(Vx.Test.t_testcaselist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Task<Vx.Test.Type_testcaselist> future = Vx.Test.f_resolve_testcaselist(testcaselist);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<Vx.Test.Type_testcaselist> vx_resolve_testcaselist(Vx.Test.Type_testcaselist testcaselist) {
      return Vx.Test.f_resolve_testcaselist(testcaselist);
    }

  }

  public static Func_resolve_testcaselist e_resolve_testcaselist = new Vx.Test.Class_resolve_testcaselist();
  public static Func_resolve_testcaselist t_resolve_testcaselist = new Vx.Test.Class_resolve_testcaselist();

  public static Task<Vx.Test.Type_testcaselist> f_resolve_testcaselist(Vx.Test.Type_testcaselist testcaselist) {
    Task<Vx.Test.Type_testcaselist> output = Vx.Core.vx_async_new_completed(Vx.Test.e_testcaselist);
    output = Vx.Core.f_list_from_list_async(
      Vx.Test.t_testcaselist,
      testcaselist,
      Vx.Test.t_resolve_testcase
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
  public interface Func_resolve_testdescribe : Vx.Core.Func_any_from_any_async {
    public Task<Vx.Test.Type_testdescribe> vx_resolve_testdescribe(Vx.Test.Type_testdescribe testdescribe);
  }

  public class Class_resolve_testdescribe : Vx.Core.Class_base, Func_resolve_testdescribe {

    public override Vx.Test.Func_resolve_testdescribe vx_new(params Object[] vals) {
      Class_resolve_testdescribe output = new Class_resolve_testdescribe();
      return output;
    }

    public override Vx.Test.Func_resolve_testdescribe vx_copy(params Object[] vals) {
      Class_resolve_testdescribe output = new Class_resolve_testdescribe();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testdescribe", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/test", // pkgname
          "testdescribe", // name
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
      return e_resolve_testdescribe;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_resolve_testdescribe;
    }

    public Vx.Core.Func_any_from_any_async vx_fn_new(Vx.Core.Class_any_from_any_async.IFn fn) {
      return Vx.Core.e_any_from_any_async;
    }

    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      Vx.Test.Type_testdescribe inputval = Vx.Core.f_any_from_any(Vx.Test.t_testdescribe, value);
      Task<Vx.Test.Type_testdescribe> future = Vx.Test.f_resolve_testdescribe(inputval);
      Task<T> output = Vx.Core.vx_async_from_async(generic_any_1, future);
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_completed(Vx.Core.e_any);
      Vx.Test.Type_testdescribe testdescribe = Vx.Core.f_any_from_any(Vx.Test.t_testdescribe, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Task<Vx.Test.Type_testdescribe> future = Vx.Test.f_resolve_testdescribe(testdescribe);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<Vx.Test.Type_testdescribe> vx_resolve_testdescribe(Vx.Test.Type_testdescribe testdescribe) {
      return Vx.Test.f_resolve_testdescribe(testdescribe);
    }

  }

  public static Func_resolve_testdescribe e_resolve_testdescribe = new Vx.Test.Class_resolve_testdescribe();
  public static Func_resolve_testdescribe t_resolve_testdescribe = new Vx.Test.Class_resolve_testdescribe();

  public static Task<Vx.Test.Type_testdescribe> f_resolve_testdescribe(Vx.Test.Type_testdescribe testdescribe) {
    Task<Vx.Test.Type_testdescribe> output = Vx.Core.vx_async_new_completed(Vx.Test.e_testdescribe);
    output = Vx.Core.f_let_async(
      Vx.Test.t_testdescribe,
      Vx.Core.t_any_from_func_async.vx_fn_new(() => {
        Vx.Test.Type_testresult testresult = testdescribe.testresult();
        Task<Vx.Test.Type_testresult> future_resolved = Vx.Test.f_resolve_testresult(testresult);
        Task<Vx.Core.Type_any> output_1 = Vx.Core.vx_async_from_async_fn(future_resolved, (resolved) => {;
          Vx.Core.Type_any output_2 = Vx.Core.f_copy(
            testdescribe,
            Vx.Core.vx_new(Vx.Core.t_anylist,
                  Vx.Core.vx_new_string(":testresult"),
                  resolved
            )
          );
          return output_2;
        });
        return output_1;
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
  public interface Func_resolve_testdescribelist : Vx.Core.Func_any_from_any_async {
    public Task<Vx.Test.Type_testdescribelist> vx_resolve_testdescribelist(Vx.Test.Type_testdescribelist testdescribelist);
  }

  public class Class_resolve_testdescribelist : Vx.Core.Class_base, Func_resolve_testdescribelist {

    public override Vx.Test.Func_resolve_testdescribelist vx_new(params Object[] vals) {
      Class_resolve_testdescribelist output = new Class_resolve_testdescribelist();
      return output;
    }

    public override Vx.Test.Func_resolve_testdescribelist vx_copy(params Object[] vals) {
      Class_resolve_testdescribelist output = new Class_resolve_testdescribelist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testdescribelist", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/test", // pkgname
          "testdescribelist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Test.t_testdescribe), // allowtypes
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
      return e_resolve_testdescribelist;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_resolve_testdescribelist;
    }

    public Vx.Core.Func_any_from_any_async vx_fn_new(Vx.Core.Class_any_from_any_async.IFn fn) {
      return Vx.Core.e_any_from_any_async;
    }

    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      Vx.Test.Type_testdescribelist inputval = Vx.Core.f_any_from_any(Vx.Test.t_testdescribelist, value);
      Task<Vx.Test.Type_testdescribelist> future = Vx.Test.f_resolve_testdescribelist(inputval);
      Task<T> output = Vx.Core.vx_async_from_async(generic_any_1, future);
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_completed(Vx.Core.e_any);
      Vx.Test.Type_testdescribelist testdescribelist = Vx.Core.f_any_from_any(Vx.Test.t_testdescribelist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Task<Vx.Test.Type_testdescribelist> future = Vx.Test.f_resolve_testdescribelist(testdescribelist);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<Vx.Test.Type_testdescribelist> vx_resolve_testdescribelist(Vx.Test.Type_testdescribelist testdescribelist) {
      return Vx.Test.f_resolve_testdescribelist(testdescribelist);
    }

  }

  public static Func_resolve_testdescribelist e_resolve_testdescribelist = new Vx.Test.Class_resolve_testdescribelist();
  public static Func_resolve_testdescribelist t_resolve_testdescribelist = new Vx.Test.Class_resolve_testdescribelist();

  public static Task<Vx.Test.Type_testdescribelist> f_resolve_testdescribelist(Vx.Test.Type_testdescribelist testdescribelist) {
    Task<Vx.Test.Type_testdescribelist> output = Vx.Core.vx_async_new_completed(Vx.Test.e_testdescribelist);
    output = Vx.Core.f_list_from_list_async(
      Vx.Test.t_testdescribelist,
      testdescribelist,
      Vx.Test.t_resolve_testdescribe
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
  public interface Func_resolve_testpackage : Vx.Core.Func_any_from_any_async {
    public Task<Vx.Test.Type_testpackage> vx_resolve_testpackage(Vx.Test.Type_testpackage testpackage);
  }

  public class Class_resolve_testpackage : Vx.Core.Class_base, Func_resolve_testpackage {

    public override Vx.Test.Func_resolve_testpackage vx_new(params Object[] vals) {
      Class_resolve_testpackage output = new Class_resolve_testpackage();
      return output;
    }

    public override Vx.Test.Func_resolve_testpackage vx_copy(params Object[] vals) {
      Class_resolve_testpackage output = new Class_resolve_testpackage();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testpackage", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/test", // pkgname
          "testpackage", // name
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
      return e_resolve_testpackage;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_resolve_testpackage;
    }

    public Vx.Core.Func_any_from_any_async vx_fn_new(Vx.Core.Class_any_from_any_async.IFn fn) {
      return Vx.Core.e_any_from_any_async;
    }

    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      Vx.Test.Type_testpackage inputval = Vx.Core.f_any_from_any(Vx.Test.t_testpackage, value);
      Task<Vx.Test.Type_testpackage> future = Vx.Test.f_resolve_testpackage(inputval);
      Task<T> output = Vx.Core.vx_async_from_async(generic_any_1, future);
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_completed(Vx.Core.e_any);
      Vx.Test.Type_testpackage testpackage = Vx.Core.f_any_from_any(Vx.Test.t_testpackage, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Task<Vx.Test.Type_testpackage> future = Vx.Test.f_resolve_testpackage(testpackage);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<Vx.Test.Type_testpackage> vx_resolve_testpackage(Vx.Test.Type_testpackage testpackage) {
      return Vx.Test.f_resolve_testpackage(testpackage);
    }

  }

  public static Func_resolve_testpackage e_resolve_testpackage = new Vx.Test.Class_resolve_testpackage();
  public static Func_resolve_testpackage t_resolve_testpackage = new Vx.Test.Class_resolve_testpackage();

  public static Task<Vx.Test.Type_testpackage> f_resolve_testpackage(Vx.Test.Type_testpackage testpackage) {
    Task<Vx.Test.Type_testpackage> output = Vx.Core.vx_async_new_completed(Vx.Test.e_testpackage);
    output = Vx.Core.f_let_async(
      Vx.Test.t_testpackage,
      Vx.Core.t_any_from_func_async.vx_fn_new(() => {
        Vx.Test.Type_testcaselist testcaselist = testpackage.caselist();
        Task<Vx.Test.Type_testcaselist> future_resolvedlist = Vx.Test.f_resolve_testcaselist(testcaselist);
        Task<Vx.Core.Type_any> output_1 = Vx.Core.vx_async_from_async_fn(future_resolvedlist, (resolvedlist) => {;
          Vx.Core.Type_booleanlist passfaillist = Vx.Core.f_list_from_list_1(
            Vx.Core.t_booleanlist,
            resolvedlist,
            Vx.Core.t_any_from_any.vx_fn_new((testcase_any) => {
              Vx.Test.Type_testcase testcase = Vx.Core.f_any_from_any(Vx.Test.t_testcase, testcase_any);
              Vx.Core.Type_any output_2 = 
                    testcase.passfail();
              return output_2;
            })
          );
          Vx.Core.Type_boolean passfail = Vx.Core.f_and_1(passfaillist);
          Vx.Core.Type_any output_3 = Vx.Core.f_copy(
            testpackage,
            Vx.Core.vx_new(Vx.Core.t_anylist,
                  Vx.Core.vx_new_string(":passfail"),
                  passfail,
                  Vx.Core.vx_new_string(":caselist"),
                  resolvedlist
            )
          );
          return output_3;
        });
        return output_1;
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
  public interface Func_resolve_testpackagelist : Vx.Core.Func_any_from_any_async {
    public Task<Vx.Test.Type_testpackagelist> vx_resolve_testpackagelist(Vx.Test.Type_testpackagelist testpackagelist);
  }

  public class Class_resolve_testpackagelist : Vx.Core.Class_base, Func_resolve_testpackagelist {

    public override Vx.Test.Func_resolve_testpackagelist vx_new(params Object[] vals) {
      Class_resolve_testpackagelist output = new Class_resolve_testpackagelist();
      return output;
    }

    public override Vx.Test.Func_resolve_testpackagelist vx_copy(params Object[] vals) {
      Class_resolve_testpackagelist output = new Class_resolve_testpackagelist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testpackagelist", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/test", // pkgname
          "testpackagelist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Test.t_testpackage), // allowtypes
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
      return e_resolve_testpackagelist;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_resolve_testpackagelist;
    }

    public Vx.Core.Func_any_from_any_async vx_fn_new(Vx.Core.Class_any_from_any_async.IFn fn) {
      return Vx.Core.e_any_from_any_async;
    }

    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      Vx.Test.Type_testpackagelist inputval = Vx.Core.f_any_from_any(Vx.Test.t_testpackagelist, value);
      Task<Vx.Test.Type_testpackagelist> future = Vx.Test.f_resolve_testpackagelist(inputval);
      Task<T> output = Vx.Core.vx_async_from_async(generic_any_1, future);
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_completed(Vx.Core.e_any);
      Vx.Test.Type_testpackagelist testpackagelist = Vx.Core.f_any_from_any(Vx.Test.t_testpackagelist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Task<Vx.Test.Type_testpackagelist> future = Vx.Test.f_resolve_testpackagelist(testpackagelist);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<Vx.Test.Type_testpackagelist> vx_resolve_testpackagelist(Vx.Test.Type_testpackagelist testpackagelist) {
      return Vx.Test.f_resolve_testpackagelist(testpackagelist);
    }

  }

  public static Func_resolve_testpackagelist e_resolve_testpackagelist = new Vx.Test.Class_resolve_testpackagelist();
  public static Func_resolve_testpackagelist t_resolve_testpackagelist = new Vx.Test.Class_resolve_testpackagelist();

  public static Task<Vx.Test.Type_testpackagelist> f_resolve_testpackagelist(Vx.Test.Type_testpackagelist testpackagelist) {
    Task<Vx.Test.Type_testpackagelist> output = Vx.Core.vx_async_new_completed(Vx.Test.e_testpackagelist);
    output = Vx.Core.f_list_from_list_async(
      Vx.Test.t_testpackagelist,
      testpackagelist,
      Vx.Test.t_resolve_testpackage
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
  public interface Func_resolve_testresult : Vx.Core.Func_any_from_any_async {
    public Task<Vx.Test.Type_testresult> vx_resolve_testresult(Vx.Test.Type_testresult testresult);
  }

  public class Class_resolve_testresult : Vx.Core.Class_base, Func_resolve_testresult {

    public override Vx.Test.Func_resolve_testresult vx_new(params Object[] vals) {
      Class_resolve_testresult output = new Class_resolve_testresult();
      return output;
    }

    public override Vx.Test.Func_resolve_testresult vx_copy(params Object[] vals) {
      Class_resolve_testresult output = new Class_resolve_testresult();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testresult", // name
        0, // idx
        true, // async
        Vx.Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_resolve_testresult;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_resolve_testresult;
    }

    public Vx.Core.Func_any_from_any_async vx_fn_new(Vx.Core.Class_any_from_any_async.IFn fn) {
      return Vx.Core.e_any_from_any_async;
    }

    public Task<T> vx_any_from_any_async<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      Vx.Test.Type_testresult inputval = Vx.Core.f_any_from_any(Vx.Test.t_testresult, value);
      Task<Vx.Test.Type_testresult> future = Vx.Test.f_resolve_testresult(inputval);
      Task<T> output = Vx.Core.vx_async_from_async(generic_any_1, future);
      return output;
    }

    public Task<Vx.Core.Type_any> vx_repl(Vx.Core.Type_anylist arglist) {
      Task<Vx.Core.Type_any> output = Vx.Core.vx_async_new_completed(Vx.Core.e_any);
      Vx.Test.Type_testresult testresult = Vx.Core.f_any_from_any(Vx.Test.t_testresult, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Task<Vx.Test.Type_testresult> future = Vx.Test.f_resolve_testresult(testresult);
      output = Vx.Core.vx_async_from_async(Vx.Core.t_any, future);
      return output;
    }

    public Task<Vx.Test.Type_testresult> vx_resolve_testresult(Vx.Test.Type_testresult testresult) {
      return Vx.Test.f_resolve_testresult(testresult);
    }

  }

  public static Func_resolve_testresult e_resolve_testresult = new Vx.Test.Class_resolve_testresult();
  public static Func_resolve_testresult t_resolve_testresult = new Vx.Test.Class_resolve_testresult();

  public static Task<Vx.Test.Type_testresult> f_resolve_testresult(Vx.Test.Type_testresult testresult) {
    Task<Vx.Test.Type_testresult> output = Vx.Core.vx_async_new_completed(Vx.Test.e_testresult);
    output = Vx.Core.f_let_async(
      Vx.Test.t_testresult,
      Vx.Core.t_any_from_func_async.vx_fn_new(() => {
        Vx.Core.Func_any_from_func_async fn_actual = testresult.fn_actual();
        Vx.Core.Type_any expected = testresult.expected();
        Task<Vx.Core.Type_any> future_actual = Vx.Core.f_resolve_async(Vx.Core.t_any, fn_actual);
        Task<Vx.Core.Type_any> output_1 = Vx.Core.vx_async_from_async_fn(future_actual, (actual) => {;
          Vx.Core.Type_any output_3 = Vx.Core.f_if_2(
            Vx.Test.t_testresult,
            Vx.Core.vx_new(Vx.Core.t_thenelselist,
                  Vx.Core.f_then(
                    Vx.Core.t_boolean_from_func.vx_fn_new(() => {
                      return Vx.Core.f_is_empty_1(fn_actual);
                    }),
                    Vx.Core.t_any_from_func.vx_fn_new(() => {
                      return testresult;
                    })
                  ),
                  Vx.Core.f_else(
                    Vx.Core.t_any_from_func.vx_fn_new(() => {
                      return Vx.Core.f_let(
                        Vx.Test.t_testresult,
                        Vx.Core.t_any_from_func.vx_fn_new(() => {
                          Vx.Core.Type_boolean passfail = Vx.Core.f_eq(expected, actual);
                          Vx.Core.Type_any output_2 = Vx.Core.f_copy(
                            testresult,
                            Vx.Core.vx_new(Vx.Core.t_anylist,
                              Vx.Core.vx_new_string(":passfail"),
                              passfail,
                              Vx.Core.vx_new_string(":actual"),
                              actual
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
        });
        return output_1;
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
  public interface Func_security_test : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_security vx_security_test();
  }

  public class Class_security_test : Vx.Core.Class_base, Func_security_test {

    public override Vx.Test.Func_security_test vx_new(params Object[] vals) {
      Class_security_test output = new Class_security_test();
      return output;
    }

    public override Vx.Test.Func_security_test vx_copy(params Object[] vals) {
      Class_security_test output = new Class_security_test();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "security-test", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "security", // name
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
      return e_security_test;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_security_test;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      output = Vx.Test.f_security_test();
      return output;
    }

    public Vx.Core.Type_security vx_security_test() {
      return Vx.Test.f_security_test();
    }

  }

  public static Func_security_test e_security_test = new Vx.Test.Class_security_test();
  public static Func_security_test t_security_test = new Vx.Test.Class_security_test();

  public static Vx.Core.Type_security f_security_test() {
    Vx.Core.Type_security output = Vx.Core.e_security;
    output = Vx.Core.f_new(
      Vx.Core.t_security,
      Vx.Core.vx_new(Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":allowfuncs"),
        Vx.Core.f_new(
          Vx.Core.t_funclist,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Data.File.t_boolean_write_from_file_any,
            Vx.Data.File.t_boolean_write_from_file_string,
            Vx.Data.File.t_file_read_from_file,
            Vx.Data.File.t_string_read_from_file
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
  public interface Func_test : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Test.Type_testresult vx_test(Vx.Core.Type_context context, Vx.Core.Type_any expected, Vx.Core.Type_any actual);
  }

  public class Class_test : Vx.Core.Class_base, Func_test {

    public override Vx.Test.Func_test vx_new(params Object[] vals) {
      Class_test output = new Class_test();
      return output;
    }

    public override Vx.Test.Func_test vx_copy(params Object[] vals) {
      Class_test output = new Class_test();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "test", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_test;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_test;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any expected = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any actual = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Test.f_test(context, expected, actual);
      return output;
    }

    public Vx.Test.Type_testresult vx_test(Vx.Core.Type_context context, Vx.Core.Type_any expected, Vx.Core.Type_any actual) {
      return Vx.Test.f_test(context, expected, actual);
    }

  }

  public static Func_test e_test = new Vx.Test.Class_test();
  public static Func_test t_test = new Vx.Test.Class_test();

  public static Vx.Test.Type_testresult f_test(Vx.Core.Type_context context, Vx.Core.Type_any expected, Vx.Core.Type_any actual) {
    Vx.Test.Type_testresult output = Vx.Test.e_testresult;
    try {
      output = Vx.Core.f_new(
        Vx.Test.t_testresult,
        Vx.Core.vx_new(Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":code"),
          Vx.Core.vx_new_string(":eq"),
          Vx.Core.vx_new_string(":passfail"),
          Vx.Core.f_eq(expected, actual),
          Vx.Core.vx_new_string(":expected"),
          expected,
          Vx.Core.vx_new_string(":actual"),
          actual
        )
      );
    } catch (Exception err) {
      Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_exception("vx/test/test", err);
      output = Vx.Core.vx_copy(output, msg);
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
  public interface Func_test_1 : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Test.Type_testresult vx_test_1(Vx.Core.Type_context context, Vx.Core.Type_any expected, Vx.Core.Func_any_from_func_async fn_actual);
  }

  public class Class_test_1 : Vx.Core.Class_base, Func_test_1 {

    public override Vx.Test.Func_test_1 vx_new(params Object[] vals) {
      Class_test_1 output = new Class_test_1();
      return output;
    }

    public override Vx.Test.Func_test_1 vx_copy(params Object[] vals) {
      Class_test_1 output = new Class_test_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "test", // name
        1, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_test_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_test_1;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any expected = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Func_any_from_func_async fn_actual = Vx.Core.f_any_from_any(Vx.Core.t_any_from_func_async, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Test.f_test_1(context, expected, fn_actual);
      return output;
    }

    public Vx.Test.Type_testresult vx_test_1(Vx.Core.Type_context context, Vx.Core.Type_any expected, Vx.Core.Func_any_from_func_async fn_actual) {
      return Vx.Test.f_test_1(context, expected, fn_actual);
    }

  }

  public static Func_test_1 e_test_1 = new Vx.Test.Class_test_1();
  public static Func_test_1 t_test_1 = new Vx.Test.Class_test_1();

  public static Vx.Test.Type_testresult f_test_1(Vx.Core.Type_context context, Vx.Core.Type_any expected, Vx.Core.Func_any_from_func_async fn_actual) {
    Vx.Test.Type_testresult output = Vx.Test.e_testresult;
    try {
      output = Vx.Core.f_new(
        Vx.Test.t_testresult,
        Vx.Core.vx_new(Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":code"),
          Vx.Core.vx_new_string(":eq"),
          Vx.Core.vx_new_string(":expected"),
          expected,
          Vx.Core.vx_new_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (Exception err) {
      Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_exception("vx/test/test", err);
      output = Vx.Core.vx_copy(output, msg);
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
  public interface Func_test_false : Vx.Core.Func_any_from_any_context {
    public Vx.Test.Type_testresult vx_test_false(Vx.Core.Type_context context, Vx.Core.Type_any actual);
  }

  public class Class_test_false : Vx.Core.Class_base, Func_test_false {

    public override Vx.Test.Func_test_false vx_new(params Object[] vals) {
      Class_test_false output = new Class_test_false();
      return output;
    }

    public override Vx.Test.Func_test_false vx_copy(params Object[] vals) {
      Class_test_false output = new Class_test_false();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "test-false", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_test_false;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_test_false;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Test.f_test_false(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any actual = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Test.f_test_false(context, actual);
      return output;
    }

    public Vx.Test.Type_testresult vx_test_false(Vx.Core.Type_context context, Vx.Core.Type_any actual) {
      return Vx.Test.f_test_false(context, actual);
    }

  }

  public static Func_test_false e_test_false = new Vx.Test.Class_test_false();
  public static Func_test_false t_test_false = new Vx.Test.Class_test_false();

  public static Vx.Test.Type_testresult f_test_false(Vx.Core.Type_context context, Vx.Core.Type_any actual) {
    Vx.Test.Type_testresult output = Vx.Test.e_testresult;
    try {
      output = Vx.Core.f_new(
        Vx.Test.t_testresult,
        Vx.Core.vx_new(Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":code"),
          Vx.Core.vx_new_string(":false"),
          Vx.Core.vx_new_string(":passfail"),
          Vx.Core.f_eq(
            Vx.Core.vx_new_boolean(false),
            actual
          ),
          Vx.Core.vx_new_string(":expected"),
          Vx.Core.vx_new_boolean(false),
          Vx.Core.vx_new_string(":actual"),
          actual
        )
      );
    } catch (Exception err) {
      Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_exception("vx/test/test-false", err);
      output = Vx.Core.vx_copy(output, msg);
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
  public interface Func_test_false_1 : Vx.Core.Func_any_from_any_context {
    public Vx.Test.Type_testresult vx_test_false_1(Vx.Core.Type_context context, Vx.Core.Func_any_from_func_async fn_actual);
  }

  public class Class_test_false_1 : Vx.Core.Class_base, Func_test_false_1 {

    public override Vx.Test.Func_test_false_1 vx_new(params Object[] vals) {
      Class_test_false_1 output = new Class_test_false_1();
      return output;
    }

    public override Vx.Test.Func_test_false_1 vx_copy(params Object[] vals) {
      Class_test_false_1 output = new Class_test_false_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "test-false", // name
        1, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_test_false_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_test_false_1;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Func_any_from_func_async inputval = (Vx.Core.Func_any_from_func_async)value;
      Vx.Core.Type_any outputval = Vx.Test.f_test_false_1(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Func_any_from_func_async fn_actual = Vx.Core.f_any_from_any(Vx.Core.t_any_from_func_async, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Test.f_test_false_1(context, fn_actual);
      return output;
    }

    public Vx.Test.Type_testresult vx_test_false_1(Vx.Core.Type_context context, Vx.Core.Func_any_from_func_async fn_actual) {
      return Vx.Test.f_test_false_1(context, fn_actual);
    }

  }

  public static Func_test_false_1 e_test_false_1 = new Vx.Test.Class_test_false_1();
  public static Func_test_false_1 t_test_false_1 = new Vx.Test.Class_test_false_1();

  public static Vx.Test.Type_testresult f_test_false_1(Vx.Core.Type_context context, Vx.Core.Func_any_from_func_async fn_actual) {
    Vx.Test.Type_testresult output = Vx.Test.e_testresult;
    try {
      output = Vx.Core.f_new(
        Vx.Test.t_testresult,
        Vx.Core.vx_new(Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":code"),
          Vx.Core.vx_new_string(":false"),
          Vx.Core.vx_new_string(":expected"),
          Vx.Core.vx_new_boolean(false),
          Vx.Core.vx_new_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (Exception err) {
      Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_exception("vx/test/test-false", err);
      output = Vx.Core.vx_copy(output, msg);
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
  public interface Func_test_gt : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Test.Type_testresult vx_test_gt(Vx.Core.Type_context context, Vx.Core.Type_any expected, Vx.Core.Type_any actual);
  }

  public class Class_test_gt : Vx.Core.Class_base, Func_test_gt {

    public override Vx.Test.Func_test_gt vx_new(params Object[] vals) {
      Class_test_gt output = new Class_test_gt();
      return output;
    }

    public override Vx.Test.Func_test_gt vx_copy(params Object[] vals) {
      Class_test_gt output = new Class_test_gt();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "test-gt", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_test_gt;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_test_gt;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any expected = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any actual = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Test.f_test_gt(context, expected, actual);
      return output;
    }

    public Vx.Test.Type_testresult vx_test_gt(Vx.Core.Type_context context, Vx.Core.Type_any expected, Vx.Core.Type_any actual) {
      return Vx.Test.f_test_gt(context, expected, actual);
    }

  }

  public static Func_test_gt e_test_gt = new Vx.Test.Class_test_gt();
  public static Func_test_gt t_test_gt = new Vx.Test.Class_test_gt();

  public static Vx.Test.Type_testresult f_test_gt(Vx.Core.Type_context context, Vx.Core.Type_any expected, Vx.Core.Type_any actual) {
    Vx.Test.Type_testresult output = Vx.Test.e_testresult;
    try {
      output = Vx.Core.f_new(
        Vx.Test.t_testresult,
        Vx.Core.vx_new(Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":code"),
          Vx.Core.vx_new_string(":gt"),
          Vx.Core.vx_new_string(":passfail"),
          Vx.Core.f_gt(expected, actual),
          Vx.Core.vx_new_string(":expected"),
          expected,
          Vx.Core.vx_new_string(":actual"),
          actual
        )
      );
    } catch (Exception err) {
      Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_exception("vx/test/test-gt", err);
      output = Vx.Core.vx_copy(output, msg);
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
  public interface Func_test_gt_1 : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Test.Type_testresult vx_test_gt_1(Vx.Core.Type_context context, Vx.Core.Type_any expected, Vx.Core.Func_any_from_func_async fn_actual);
  }

  public class Class_test_gt_1 : Vx.Core.Class_base, Func_test_gt_1 {

    public override Vx.Test.Func_test_gt_1 vx_new(params Object[] vals) {
      Class_test_gt_1 output = new Class_test_gt_1();
      return output;
    }

    public override Vx.Test.Func_test_gt_1 vx_copy(params Object[] vals) {
      Class_test_gt_1 output = new Class_test_gt_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "test-gt", // name
        1, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_test_gt_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_test_gt_1;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any expected = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Func_any_from_func_async fn_actual = Vx.Core.f_any_from_any(Vx.Core.t_any_from_func_async, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Test.f_test_gt_1(context, expected, fn_actual);
      return output;
    }

    public Vx.Test.Type_testresult vx_test_gt_1(Vx.Core.Type_context context, Vx.Core.Type_any expected, Vx.Core.Func_any_from_func_async fn_actual) {
      return Vx.Test.f_test_gt_1(context, expected, fn_actual);
    }

  }

  public static Func_test_gt_1 e_test_gt_1 = new Vx.Test.Class_test_gt_1();
  public static Func_test_gt_1 t_test_gt_1 = new Vx.Test.Class_test_gt_1();

  public static Vx.Test.Type_testresult f_test_gt_1(Vx.Core.Type_context context, Vx.Core.Type_any expected, Vx.Core.Func_any_from_func_async fn_actual) {
    Vx.Test.Type_testresult output = Vx.Test.e_testresult;
    try {
      output = Vx.Core.f_new(
        Vx.Test.t_testresult,
        Vx.Core.vx_new(Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":code"),
          Vx.Core.vx_new_string(":gt"),
          Vx.Core.vx_new_string(":expected"),
          expected,
          Vx.Core.vx_new_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (Exception err) {
      Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_exception("vx/test/test-gt", err);
      output = Vx.Core.vx_copy(output, msg);
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
  public interface Func_test_ne : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Test.Type_testresult vx_test_ne(Vx.Core.Type_context context, Vx.Core.Type_any expected, Vx.Core.Type_any actual);
  }

  public class Class_test_ne : Vx.Core.Class_base, Func_test_ne {

    public override Vx.Test.Func_test_ne vx_new(params Object[] vals) {
      Class_test_ne output = new Class_test_ne();
      return output;
    }

    public override Vx.Test.Func_test_ne vx_copy(params Object[] vals) {
      Class_test_ne output = new Class_test_ne();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "test-ne", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_test_ne;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_test_ne;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any expected = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any actual = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Test.f_test_ne(context, expected, actual);
      return output;
    }

    public Vx.Test.Type_testresult vx_test_ne(Vx.Core.Type_context context, Vx.Core.Type_any expected, Vx.Core.Type_any actual) {
      return Vx.Test.f_test_ne(context, expected, actual);
    }

  }

  public static Func_test_ne e_test_ne = new Vx.Test.Class_test_ne();
  public static Func_test_ne t_test_ne = new Vx.Test.Class_test_ne();

  public static Vx.Test.Type_testresult f_test_ne(Vx.Core.Type_context context, Vx.Core.Type_any expected, Vx.Core.Type_any actual) {
    Vx.Test.Type_testresult output = Vx.Test.e_testresult;
    try {
      output = Vx.Core.f_new(
        Vx.Test.t_testresult,
        Vx.Core.vx_new(Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":code"),
          Vx.Core.vx_new_string(":ne"),
          Vx.Core.vx_new_string(":passfail"),
          Vx.Core.f_ne(expected, actual),
          Vx.Core.vx_new_string(":expected"),
          expected,
          Vx.Core.vx_new_string(":actual"),
          actual
        )
      );
    } catch (Exception err) {
      Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_exception("vx/test/test-ne", err);
      output = Vx.Core.vx_copy(output, msg);
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
  public interface Func_test_ne_1 : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Test.Type_testresult vx_test_ne_1(Vx.Core.Type_context context, Vx.Core.Type_any expected, Vx.Core.Func_any_from_func_async fn_actual);
  }

  public class Class_test_ne_1 : Vx.Core.Class_base, Func_test_ne_1 {

    public override Vx.Test.Func_test_ne_1 vx_new(params Object[] vals) {
      Class_test_ne_1 output = new Class_test_ne_1();
      return output;
    }

    public override Vx.Test.Func_test_ne_1 vx_copy(params Object[] vals) {
      Class_test_ne_1 output = new Class_test_ne_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "test-ne", // name
        1, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_test_ne_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_test_ne_1;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any expected = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Func_any_from_func_async fn_actual = Vx.Core.f_any_from_any(Vx.Core.t_any_from_func_async, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Test.f_test_ne_1(context, expected, fn_actual);
      return output;
    }

    public Vx.Test.Type_testresult vx_test_ne_1(Vx.Core.Type_context context, Vx.Core.Type_any expected, Vx.Core.Func_any_from_func_async fn_actual) {
      return Vx.Test.f_test_ne_1(context, expected, fn_actual);
    }

  }

  public static Func_test_ne_1 e_test_ne_1 = new Vx.Test.Class_test_ne_1();
  public static Func_test_ne_1 t_test_ne_1 = new Vx.Test.Class_test_ne_1();

  public static Vx.Test.Type_testresult f_test_ne_1(Vx.Core.Type_context context, Vx.Core.Type_any expected, Vx.Core.Func_any_from_func_async fn_actual) {
    Vx.Test.Type_testresult output = Vx.Test.e_testresult;
    try {
      output = Vx.Core.f_new(
        Vx.Test.t_testresult,
        Vx.Core.vx_new(Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":code"),
          Vx.Core.vx_new_string(":ne"),
          Vx.Core.vx_new_string(":expected"),
          expected,
          Vx.Core.vx_new_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (Exception err) {
      Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_exception("vx/test/test-ne", err);
      output = Vx.Core.vx_copy(output, msg);
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
  public interface Func_test_string : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Test.Type_testresult vx_test_string(Vx.Core.Type_context context, Vx.Core.Type_any expected, Vx.Core.Type_any actual);
  }

  public class Class_test_string : Vx.Core.Class_base, Func_test_string {

    public override Vx.Test.Func_test_string vx_new(params Object[] vals) {
      Class_test_string output = new Class_test_string();
      return output;
    }

    public override Vx.Test.Func_test_string vx_copy(params Object[] vals) {
      Class_test_string output = new Class_test_string();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "test-string", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_test_string;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_test_string;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any expected = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any actual = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Test.f_test_string(context, expected, actual);
      return output;
    }

    public Vx.Test.Type_testresult vx_test_string(Vx.Core.Type_context context, Vx.Core.Type_any expected, Vx.Core.Type_any actual) {
      return Vx.Test.f_test_string(context, expected, actual);
    }

  }

  public static Func_test_string e_test_string = new Vx.Test.Class_test_string();
  public static Func_test_string t_test_string = new Vx.Test.Class_test_string();

  public static Vx.Test.Type_testresult f_test_string(Vx.Core.Type_context context, Vx.Core.Type_any expected, Vx.Core.Type_any actual) {
    Vx.Test.Type_testresult output = Vx.Test.e_testresult;
    try {
      output = Vx.Core.f_new(
        Vx.Test.t_testresult,
        Vx.Core.vx_new(Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":passfail"),
          Vx.Core.f_eq(
            Vx.Core.f_string_from_any(expected),
            Vx.Core.f_string_from_any(actual)
          ),
          Vx.Core.vx_new_string(":expected"),
          expected,
          Vx.Core.vx_new_string(":actual"),
          actual
        )
      );
    } catch (Exception err) {
      Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_exception("vx/test/test-string", err);
      output = Vx.Core.vx_copy(output, msg);
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
  public interface Func_test_string_1 : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Test.Type_testresult vx_test_string_1(Vx.Core.Type_context context, Vx.Core.Type_any expected, Vx.Core.Func_any_from_func_async fn_actual);
  }

  public class Class_test_string_1 : Vx.Core.Class_base, Func_test_string_1 {

    public override Vx.Test.Func_test_string_1 vx_new(params Object[] vals) {
      Class_test_string_1 output = new Class_test_string_1();
      return output;
    }

    public override Vx.Test.Func_test_string_1 vx_copy(params Object[] vals) {
      Class_test_string_1 output = new Class_test_string_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "test-string", // name
        1, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_test_string_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_test_string_1;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any expected = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Func_any_from_func_async fn_actual = Vx.Core.f_any_from_any(Vx.Core.t_any_from_func_async, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Test.f_test_string_1(context, expected, fn_actual);
      return output;
    }

    public Vx.Test.Type_testresult vx_test_string_1(Vx.Core.Type_context context, Vx.Core.Type_any expected, Vx.Core.Func_any_from_func_async fn_actual) {
      return Vx.Test.f_test_string_1(context, expected, fn_actual);
    }

  }

  public static Func_test_string_1 e_test_string_1 = new Vx.Test.Class_test_string_1();
  public static Func_test_string_1 t_test_string_1 = new Vx.Test.Class_test_string_1();

  public static Vx.Test.Type_testresult f_test_string_1(Vx.Core.Type_context context, Vx.Core.Type_any expected, Vx.Core.Func_any_from_func_async fn_actual) {
    Vx.Test.Type_testresult output = Vx.Test.e_testresult;
    try {
      output = Vx.Core.f_new(
        Vx.Test.t_testresult,
        Vx.Core.vx_new(Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":code"),
          Vx.Core.vx_new_string(":string"),
          Vx.Core.vx_new_string(":expected"),
          expected,
          Vx.Core.vx_new_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (Exception err) {
      Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_exception("vx/test/test-string", err);
      output = Vx.Core.vx_copy(output, msg);
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
  public interface Func_test_true : Vx.Core.Func_any_from_any_context {
    public Vx.Test.Type_testresult vx_test_true(Vx.Core.Type_context context, Vx.Core.Type_any actual);
  }

  public class Class_test_true : Vx.Core.Class_base, Func_test_true {

    public override Vx.Test.Func_test_true vx_new(params Object[] vals) {
      Class_test_true output = new Class_test_true();
      return output;
    }

    public override Vx.Test.Func_test_true vx_copy(params Object[] vals) {
      Class_test_true output = new Class_test_true();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "test-true", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_test_true;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_test_true;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_any inputval = (Vx.Core.Type_any)value;
      Vx.Core.Type_any outputval = Vx.Test.f_test_true(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_any actual = Vx.Core.f_any_from_any(Vx.Core.t_any, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Test.f_test_true(context, actual);
      return output;
    }

    public Vx.Test.Type_testresult vx_test_true(Vx.Core.Type_context context, Vx.Core.Type_any actual) {
      return Vx.Test.f_test_true(context, actual);
    }

  }

  public static Func_test_true e_test_true = new Vx.Test.Class_test_true();
  public static Func_test_true t_test_true = new Vx.Test.Class_test_true();

  public static Vx.Test.Type_testresult f_test_true(Vx.Core.Type_context context, Vx.Core.Type_any actual) {
    Vx.Test.Type_testresult output = Vx.Test.e_testresult;
    try {
      output = Vx.Core.f_new(
        Vx.Test.t_testresult,
        Vx.Core.vx_new(Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":code"),
          Vx.Core.vx_new_string(":true"),
          Vx.Core.vx_new_string(":passfail"),
          Vx.Core.f_eq(
            Vx.Core.vx_new_boolean(true),
            actual
          ),
          Vx.Core.vx_new_string(":expected"),
          Vx.Core.vx_new_boolean(true),
          Vx.Core.vx_new_string(":actual"),
          actual
        )
      );
    } catch (Exception err) {
      Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_exception("vx/test/test-true", err);
      output = Vx.Core.vx_copy(output, msg);
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
  public interface Func_test_true_1 : Vx.Core.Func_any_from_any_context {
    public Vx.Test.Type_testresult vx_test_true_1(Vx.Core.Type_context context, Vx.Core.Func_any_from_func_async fn_actual);
  }

  public class Class_test_true_1 : Vx.Core.Class_base, Func_test_true_1 {

    public override Vx.Test.Func_test_true_1 vx_new(params Object[] vals) {
      Class_test_true_1 output = new Class_test_true_1();
      return output;
    }

    public override Vx.Test.Func_test_true_1 vx_copy(params Object[] vals) {
      Class_test_true_1 output = new Class_test_true_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "test-true", // name
        1, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
      return e_test_true_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_test_true_1;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Func_any_from_func_async inputval = (Vx.Core.Func_any_from_func_async)value;
      Vx.Core.Type_any outputval = Vx.Test.f_test_true_1(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Func_any_from_func_async fn_actual = Vx.Core.f_any_from_any(Vx.Core.t_any_from_func_async, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Test.f_test_true_1(context, fn_actual);
      return output;
    }

    public Vx.Test.Type_testresult vx_test_true_1(Vx.Core.Type_context context, Vx.Core.Func_any_from_func_async fn_actual) {
      return Vx.Test.f_test_true_1(context, fn_actual);
    }

  }

  public static Func_test_true_1 e_test_true_1 = new Vx.Test.Class_test_true_1();
  public static Func_test_true_1 t_test_true_1 = new Vx.Test.Class_test_true_1();

  public static Vx.Test.Type_testresult f_test_true_1(Vx.Core.Type_context context, Vx.Core.Func_any_from_func_async fn_actual) {
    Vx.Test.Type_testresult output = Vx.Test.e_testresult;
    try {
      output = Vx.Core.f_new(
        Vx.Test.t_testresult,
        Vx.Core.vx_new(Vx.Core.t_anylist,
          Vx.Core.vx_new_string(":code"),
          Vx.Core.vx_new_string(":true"),
          Vx.Core.vx_new_string(":expected"),
          Vx.Core.vx_new_boolean(true),
          Vx.Core.vx_new_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (Exception err) {
      Vx.Core.Type_msg msg = Vx.Core.vx_msg_from_exception("vx/test/test-true", err);
      output = Vx.Core.vx_copy(output, msg);
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
  public interface Func_tr_from_testdescribe_casename : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Web.Html.Type_tr vx_tr_from_testdescribe_casename(Vx.Test.Type_testdescribe testdescribe, Vx.Core.Type_string casename);
  }

  public class Class_tr_from_testdescribe_casename : Vx.Core.Class_base, Func_tr_from_testdescribe_casename {

    public override Vx.Test.Func_tr_from_testdescribe_casename vx_new(params Object[] vals) {
      Class_tr_from_testdescribe_casename output = new Class_tr_from_testdescribe_casename();
      return output;
    }

    public override Vx.Test.Func_tr_from_testdescribe_casename vx_copy(params Object[] vals) {
      Class_tr_from_testdescribe_casename output = new Class_tr_from_testdescribe_casename();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "tr<-testdescribe-casename", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "tr", // name
          ":struct", // extends
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_node), // traits
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
      return e_tr_from_testdescribe_casename;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_tr_from_testdescribe_casename;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Test.Type_testdescribe testdescribe = Vx.Core.f_any_from_any(Vx.Test.t_testdescribe, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string casename = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Test.f_tr_from_testdescribe_casename(testdescribe, casename);
      return output;
    }

    public Vx.Web.Html.Type_tr vx_tr_from_testdescribe_casename(Vx.Test.Type_testdescribe testdescribe, Vx.Core.Type_string casename) {
      return Vx.Test.f_tr_from_testdescribe_casename(testdescribe, casename);
    }

  }

  public static Func_tr_from_testdescribe_casename e_tr_from_testdescribe_casename = new Vx.Test.Class_tr_from_testdescribe_casename();
  public static Func_tr_from_testdescribe_casename t_tr_from_testdescribe_casename = new Vx.Test.Class_tr_from_testdescribe_casename();

  public static Vx.Web.Html.Type_tr f_tr_from_testdescribe_casename(Vx.Test.Type_testdescribe testdescribe, Vx.Core.Type_string casename) {
    Vx.Web.Html.Type_tr output = Vx.Web.Html.e_tr;
    output = Vx.Core.f_let(
      Vx.Web.Html.t_tr,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string describename = testdescribe.describename();
        Vx.Test.Type_testresult result = testdescribe.testresult();
        Vx.Core.Type_boolean passfail = result.passfail();
        Vx.Core.Type_string expected = Vx.Core.f_string_from_any(
          result.expected()
        );
        Vx.Core.Type_string actual = Vx.Core.f_string_from_any(
          result.actual()
        );
        Vx.Web.Html.Type_style prestyle = Vx.Web.Html.f_style_from_stylesheet_name(
          Vx.Test.c_stylesheet_test,
          Vx.Core.vx_new_string(".preformatted")
        );
        Vx.Core.Type_any output_1 = Vx.Core.f_new(
          Vx.Web.Html.t_tr,
          Vx.Core.vx_new(Vx.Core.t_anylist,
            Vx.Core.f_new(
              Vx.Web.Html.t_td,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Test.f_p_from_passfail(passfail)
              )
            ),
            Vx.Core.f_new(
              Vx.Web.Html.t_td,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.f_new(
                  Vx.Web.Html.t_p,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":style"),
                    prestyle,
                    Vx.Core.vx_new_string(":text"),
                    casename
                  )
                )
              )
            ),
            Vx.Core.f_new(
              Vx.Web.Html.t_td,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.f_new(
                  Vx.Web.Html.t_p,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":style"),
                    prestyle,
                    Vx.Core.vx_new_string(":text"),
                    describename
                  )
                )
              )
            ),
            Vx.Core.f_new(
              Vx.Web.Html.t_td,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.f_new(
                  Vx.Web.Html.t_p,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":style"),
                    prestyle,
                    Vx.Core.vx_new_string(":text"),
                    expected
                  )
                )
              )
            ),
            Vx.Core.f_new(
              Vx.Web.Html.t_td,
              Vx.Core.vx_new(Vx.Core.t_anylist,
                Vx.Core.f_new(
                  Vx.Web.Html.t_p,
                  Vx.Core.vx_new(Vx.Core.t_anylist,
                    Vx.Core.vx_new_string(":style"),
                    prestyle,
                    Vx.Core.vx_new_string(":text"),
                    actual
                  )
                )
              )
            )
          )
        );
        return output_1;
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
  public interface Func_trlist_from_testcase : Vx.Core.Func_any_from_any {
    public Vx.Web.Html.Type_trlist vx_trlist_from_testcase(Vx.Test.Type_testcase testcase);
  }

  public class Class_trlist_from_testcase : Vx.Core.Class_base, Func_trlist_from_testcase {

    public override Vx.Test.Func_trlist_from_testcase vx_new(params Object[] vals) {
      Class_trlist_from_testcase output = new Class_trlist_from_testcase();
      return output;
    }

    public override Vx.Test.Func_trlist_from_testcase vx_copy(params Object[] vals) {
      Class_trlist_from_testcase output = new Class_trlist_from_testcase();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "trlist<-testcase", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "trlist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_tr), // allowtypes
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
      return e_trlist_from_testcase;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_trlist_from_testcase;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Test.Type_testcase inputval = (Vx.Test.Type_testcase)value;
      Vx.Core.Type_any outputval = Vx.Test.f_trlist_from_testcase(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Test.Type_testcase testcase = Vx.Core.f_any_from_any(Vx.Test.t_testcase, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Test.f_trlist_from_testcase(testcase);
      return output;
    }

    public Vx.Web.Html.Type_trlist vx_trlist_from_testcase(Vx.Test.Type_testcase testcase) {
      return Vx.Test.f_trlist_from_testcase(testcase);
    }

  }

  public static Func_trlist_from_testcase e_trlist_from_testcase = new Vx.Test.Class_trlist_from_testcase();
  public static Func_trlist_from_testcase t_trlist_from_testcase = new Vx.Test.Class_trlist_from_testcase();

  public static Vx.Web.Html.Type_trlist f_trlist_from_testcase(Vx.Test.Type_testcase testcase) {
    Vx.Web.Html.Type_trlist output = Vx.Web.Html.e_trlist;
    output = Vx.Core.f_let(
      Vx.Web.Html.t_trlist,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Test.Type_testdescribelist describelist = testcase.describelist();
        Vx.Core.Type_string casename = testcase.casename();
        Vx.Core.Type_any output_2 = Vx.Core.f_list_from_list_1(
          Vx.Web.Html.t_trlist,
          describelist,
          Vx.Core.t_any_from_any.vx_fn_new((testdescribe_any) => {
            Vx.Test.Type_testdescribe testdescribe = Vx.Core.f_any_from_any(Vx.Test.t_testdescribe, testdescribe_any);
            Vx.Core.Type_any output_1 = 
              Vx.Test.f_tr_from_testdescribe_casename(testdescribe, casename);
            return output_1;
          })
        );
        return output_2;
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
  public interface Func_trlist_from_testcaselist : Vx.Core.Func_any_from_any {
    public Vx.Web.Html.Type_trlist vx_trlist_from_testcaselist(Vx.Test.Type_testcaselist testcaselist);
  }

  public class Class_trlist_from_testcaselist : Vx.Core.Class_base, Func_trlist_from_testcaselist {

    public override Vx.Test.Func_trlist_from_testcaselist vx_new(params Object[] vals) {
      Class_trlist_from_testcaselist output = new Class_trlist_from_testcaselist();
      return output;
    }

    public override Vx.Test.Func_trlist_from_testcaselist vx_copy(params Object[] vals) {
      Class_trlist_from_testcaselist output = new Class_trlist_from_testcaselist();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/test", // pkgname
        "trlist<-testcaselist", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/web/html", // pkgname
          "trlist", // name
          ":list", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Web.Html.t_tr), // allowtypes
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
      return e_trlist_from_testcaselist;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_trlist_from_testcaselist;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Test.Type_testcaselist inputval = (Vx.Test.Type_testcaselist)value;
      Vx.Core.Type_any outputval = Vx.Test.f_trlist_from_testcaselist(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Test.Type_testcaselist testcaselist = Vx.Core.f_any_from_any(Vx.Test.t_testcaselist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Test.f_trlist_from_testcaselist(testcaselist);
      return output;
    }

    public Vx.Web.Html.Type_trlist vx_trlist_from_testcaselist(Vx.Test.Type_testcaselist testcaselist) {
      return Vx.Test.f_trlist_from_testcaselist(testcaselist);
    }

  }

  public static Func_trlist_from_testcaselist e_trlist_from_testcaselist = new Vx.Test.Class_trlist_from_testcaselist();
  public static Func_trlist_from_testcaselist t_trlist_from_testcaselist = new Vx.Test.Class_trlist_from_testcaselist();

  public static Vx.Web.Html.Type_trlist f_trlist_from_testcaselist(Vx.Test.Type_testcaselist testcaselist) {
    Vx.Web.Html.Type_trlist output = Vx.Web.Html.e_trlist;
    output = Vx.Core.f_list_join_from_list_1(
      Vx.Web.Html.t_trlist,
      testcaselist,
      Vx.Test.t_trlist_from_testcase
    );
    return output;
  }


  public static class PackageRunOnce {
    public static void RunOnce() {
    Const_stylesheet_test.const_new(c_stylesheet_test);
    Vx.Core.Map<string, Vx.Core.Type_any> maptype = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_any> mapconst = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_func> mapfunc = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>();
    maptype.put("testcase", Vx.Test.t_testcase);
    maptype.put("testcaselist", Vx.Test.t_testcaselist);
    maptype.put("testcoveragedetail", Vx.Test.t_testcoveragedetail);
    maptype.put("testcoveragenums", Vx.Test.t_testcoveragenums);
    maptype.put("testcoveragesummary", Vx.Test.t_testcoveragesummary);
    maptype.put("testdescribe", Vx.Test.t_testdescribe);
    maptype.put("testdescribelist", Vx.Test.t_testdescribelist);
    maptype.put("testpackage", Vx.Test.t_testpackage);
    maptype.put("testpackagelist", Vx.Test.t_testpackagelist);
    maptype.put("testresult", Vx.Test.t_testresult);
    maptype.put("testresultlist", Vx.Test.t_testresultlist);
    mapconst.put("stylesheet-test", Vx.Test.c_stylesheet_test);
    mapfunc.put("context-test", Vx.Test.t_context_test);
    mapfunc.put("div<-testcaselist", Vx.Test.t_div_from_testcaselist);
    mapfunc.put("div<-testpackage", Vx.Test.t_div_from_testpackage);
    mapfunc.put("div<-testpackagelist", Vx.Test.t_div_from_testpackagelist);
    mapfunc.put("divchildlist<-testpackagelist", Vx.Test.t_divchildlist_from_testpackagelist);
    mapfunc.put("file-test", Vx.Test.t_file_test);
    mapfunc.put("file-testhtml", Vx.Test.t_file_testhtml);
    mapfunc.put("file-testnode", Vx.Test.t_file_testnode);
    mapfunc.put("html<-divtest", Vx.Test.t_html_from_divtest);
    mapfunc.put("p<-passfail", Vx.Test.t_p_from_passfail);
    mapfunc.put("p<-testcoveragenums", Vx.Test.t_p_from_testcoveragenums);
    mapfunc.put("resolve-testcase", Vx.Test.t_resolve_testcase);
    mapfunc.put("resolve-testcaselist", Vx.Test.t_resolve_testcaselist);
    mapfunc.put("resolve-testdescribe", Vx.Test.t_resolve_testdescribe);
    mapfunc.put("resolve-testdescribelist", Vx.Test.t_resolve_testdescribelist);
    mapfunc.put("resolve-testpackage", Vx.Test.t_resolve_testpackage);
    mapfunc.put("resolve-testpackagelist", Vx.Test.t_resolve_testpackagelist);
    mapfunc.put("resolve-testresult", Vx.Test.t_resolve_testresult);
    mapfunc.put("security-test", Vx.Test.t_security_test);
    mapfunc.put("test", Vx.Test.t_test);
    mapfunc.put("test_1", Vx.Test.t_test_1);
    mapfunc.put("test-false", Vx.Test.t_test_false);
    mapfunc.put("test-false_1", Vx.Test.t_test_false_1);
    mapfunc.put("test-gt", Vx.Test.t_test_gt);
    mapfunc.put("test-gt_1", Vx.Test.t_test_gt_1);
    mapfunc.put("test-ne", Vx.Test.t_test_ne);
    mapfunc.put("test-ne_1", Vx.Test.t_test_ne_1);
    mapfunc.put("test-string", Vx.Test.t_test_string);
    mapfunc.put("test-string_1", Vx.Test.t_test_string_1);
    mapfunc.put("test-true", Vx.Test.t_test_true);
    mapfunc.put("test-true_1", Vx.Test.t_test_true_1);
    mapfunc.put("tr<-testdescribe-casename", Vx.Test.t_tr_from_testdescribe_casename);
    mapfunc.put("trlist<-testcase", Vx.Test.t_trlist_from_testcase);
    mapfunc.put("trlist<-testcaselist", Vx.Test.t_trlist_from_testcaselist);
    Vx.Core.vx_global_package_set("vx/test", maptype, mapconst, mapfunc);
    }
  }

}
