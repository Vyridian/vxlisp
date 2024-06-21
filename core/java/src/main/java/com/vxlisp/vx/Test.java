package com.vxlisp.vx;

import java.util.ArrayList;
import java.util.concurrent.CompletableFuture;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import com.vxlisp.vx.data.*;
import com.vxlisp.vx.web.*;

public final class Test {


  /**
   * type: testcase
   * Structure to describe a test case
   * (type testcase)
   */
  public interface Type_testcase extends Core.Type_struct {
    public Test.Type_testcase vx_new(final Object... vals);
    public Test.Type_testcase vx_copy(final Object... vals);
    public Test.Type_testcase vx_empty();
    public Test.Type_testcase vx_type();
    public Core.Type_boolean passfail();
    public Core.Type_string testpkg();
    public Core.Type_string casename();
    public Test.Type_testdescribelist describelist();
  }

  public static class Class_testcase extends Core.Class_base implements Type_testcase {

    protected Core.Type_boolean vx_p_passfail;

    @Override
    public Core.Type_boolean passfail() {
      return this.vx_p_passfail == null ? Core.e_boolean : this.vx_p_passfail;
    }

    protected Core.Type_string vx_p_testpkg;

    @Override
    public Core.Type_string testpkg() {
      return this.vx_p_testpkg == null ? Core.e_string : this.vx_p_testpkg;
    }

    protected Core.Type_string vx_p_casename;

    @Override
    public Core.Type_string casename() {
      return this.vx_p_casename == null ? Core.e_string : this.vx_p_casename;
    }

    protected Test.Type_testdescribelist vx_p_describelist;

    @Override
    public Test.Type_testdescribelist describelist() {
      return this.vx_p_describelist == null ? Test.e_testdescribelist : this.vx_p_describelist;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
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

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":passfail", this.passfail());
      output.put(":testpkg", this.testpkg());
      output.put(":casename", this.casename());
      output.put(":describelist", this.describelist());
      return Core.immutablemap(output);
    }

    @Override
    public Test.Type_testcase vx_new(final Object... vals) {
      return e_testcase.vx_copy(vals);
    }

    @Override
    public Test.Type_testcase vx_copy(final Object... vals) {
      Type_testcase output = this;
      boolean ischanged = false;
      Class_testcase val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_boolean vx_p_passfail = val.passfail();
      Core.Type_string vx_p_testpkg = val.testpkg();
      Core.Type_string vx_p_casename = val.casename();
      Test.Type_testdescribelist vx_p_describelist = val.describelist();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":passfail");
      validkeys.add(":testpkg");
      validkeys.add(":casename");
      validkeys.add(":describelist");
      String key = "";
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
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
            msg = Core.vx_msg_from_error("vx/test/testcase", ":invalidkeytype", msgval);
            msgblock = msgblock.vx_copy(msg);
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
              msg = Core.vx_msg_from_error("vx/test/testcase", ":invalidkey", msgval);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":passfail":
            if (valsub == vx_p_passfail) {
            } else if (valsub instanceof Core.Type_boolean) {
              ischanged = true;
              vx_p_passfail = (Core.Type_boolean)valsub;
            } else if (valsub instanceof Boolean) {
              ischanged = true;
              vx_p_passfail = Core.t_boolean.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("passfail"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testcase", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":testpkg":
            if (valsub == vx_p_testpkg) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_testpkg = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_testpkg = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("testpkg"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testcase", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":casename":
            if (valsub == vx_p_casename) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_casename = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_casename = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("casename"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testcase", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":describelist":
            if (valsub == vx_p_describelist) {
            } else if (valsub instanceof Test.Type_testdescribelist) {
              ischanged = true;
              vx_p_describelist = (Test.Type_testdescribelist)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("describelist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testcase", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/test/testcase", ":invalidkey", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_testcase work = new Class_testcase();
        work.vx_p_passfail = vx_p_passfail;
        work.vx_p_testpkg = vx_p_testpkg;
        work.vx_p_casename = vx_p_casename;
        work.vx_p_describelist = vx_p_describelist;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_testcase vx_empty() {return e_testcase;}
    @Override
    public Type_testcase vx_type() {return t_testcase;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/test", // pkgname
        "testcase", // name
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

  public static final Type_testcase e_testcase = new Class_testcase();
  public static final Type_testcase t_testcase = new Class_testcase();

  /**
   * type: testcaselist
   * List of test cases
   * (type testcaselist)
   */
  public interface Type_testcaselist extends Core.Type_list {
    public Test.Type_testcaselist vx_new(final Object... vals);
    public Test.Type_testcaselist vx_copy(final Object... vals);
    public Test.Type_testcaselist vx_empty();
    public Test.Type_testcaselist vx_type();
    public List<Test.Type_testcase> vx_listtestcase();
    public Test.Type_testcase vx_testcase(final Core.Type_int index);
  }

  public static class Class_testcaselist extends Core.Class_base implements Type_testcaselist {

    protected List<Test.Type_testcase> vx_p_list = Core.immutablelist(new ArrayList<Test.Type_testcase>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Test.Type_testcase vx_testcase(final Core.Type_int index) {
      Test.Type_testcase output = Test.e_testcase;
      Class_testcaselist list = this;
      int iindex = index.vx_int();
      List<Test.Type_testcase> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Test.Type_testcase> vx_listtestcase() {return vx_p_list;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_testcase(index);
    }

    @Override
    public Test.Type_testcaselist vx_new(final Object... vals) {
      return e_testcaselist.vx_copy(vals);
    }

    @Override
    public Test.Type_testcaselist vx_copy(final Object... vals) {
      Type_testcaselist output = this;
      boolean ischanged = false;
      Class_testcaselist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      List<Test.Type_testcase> listval = new ArrayList<>(val.vx_listtestcase());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Test.Type_testcase) {
          Test.Type_testcase anysub = (Test.Type_testcase)valsub;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub instanceof Test.Type_testcase) {
          ischanged = true;
          listval.add((Test.Type_testcase)valsub);
        } else if (valsub instanceof Test.Type_testcaselist) {
          Type_testcaselist multi = (Type_testcaselist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listtestcase());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Test.Type_testcase) {
              Test.Type_testcase valitem = (Test.Type_testcase)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anysub = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/test/testcaselist", ":invalidtype", anysub);
          msgblock = msgblock.vx_copy(msg);
        } else {
          msg = Core.vx_msg_from_error("vx/test/testcaselist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_testcaselist work = new Class_testcaselist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_testcaselist vx_empty() {return e_testcaselist;}
    @Override
    public Type_testcaselist vx_type() {return t_testcaselist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/test", // pkgname
        "testcaselist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Test.t_testcase), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_testcaselist e_testcaselist = new Class_testcaselist();
  public static final Type_testcaselist t_testcaselist = new Class_testcaselist();

  /**
   * type: testcoveragedetail
   * Structure to describe a test coverage detail
   * (type testcoveragedetail)
   */
  public interface Type_testcoveragedetail extends Core.Type_struct {
    public Test.Type_testcoveragedetail vx_new(final Object... vals);
    public Test.Type_testcoveragedetail vx_copy(final Object... vals);
    public Test.Type_testcoveragedetail vx_empty();
    public Test.Type_testcoveragedetail vx_type();
    public Core.Type_intmap constmap();
    public Core.Type_intmap funcmap();
    public Core.Type_string testpkg();
    public Core.Type_intmap typemap();
  }

  public static class Class_testcoveragedetail extends Core.Class_base implements Type_testcoveragedetail {

    protected Core.Type_intmap vx_p_constmap;

    @Override
    public Core.Type_intmap constmap() {
      return this.vx_p_constmap == null ? Core.e_intmap : this.vx_p_constmap;
    }

    protected Core.Type_intmap vx_p_funcmap;

    @Override
    public Core.Type_intmap funcmap() {
      return this.vx_p_funcmap == null ? Core.e_intmap : this.vx_p_funcmap;
    }

    protected Core.Type_string vx_p_testpkg;

    @Override
    public Core.Type_string testpkg() {
      return this.vx_p_testpkg == null ? Core.e_string : this.vx_p_testpkg;
    }

    protected Core.Type_intmap vx_p_typemap;

    @Override
    public Core.Type_intmap typemap() {
      return this.vx_p_typemap == null ? Core.e_intmap : this.vx_p_typemap;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
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

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":constmap", this.constmap());
      output.put(":funcmap", this.funcmap());
      output.put(":testpkg", this.testpkg());
      output.put(":typemap", this.typemap());
      return Core.immutablemap(output);
    }

    @Override
    public Test.Type_testcoveragedetail vx_new(final Object... vals) {
      return e_testcoveragedetail.vx_copy(vals);
    }

    @Override
    public Test.Type_testcoveragedetail vx_copy(final Object... vals) {
      Type_testcoveragedetail output = this;
      boolean ischanged = false;
      Class_testcoveragedetail val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_intmap vx_p_constmap = val.constmap();
      Core.Type_intmap vx_p_funcmap = val.funcmap();
      Core.Type_string vx_p_testpkg = val.testpkg();
      Core.Type_intmap vx_p_typemap = val.typemap();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":constmap");
      validkeys.add(":funcmap");
      validkeys.add(":testpkg");
      validkeys.add(":typemap");
      String key = "";
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
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
            msg = Core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidkeytype", msgval);
            msgblock = msgblock.vx_copy(msg);
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
              msg = Core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidkey", msgval);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":constmap":
            if (valsub == vx_p_constmap) {
            } else if (valsub instanceof Core.Type_intmap) {
              ischanged = true;
              vx_p_constmap = (Core.Type_intmap)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("constmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":funcmap":
            if (valsub == vx_p_funcmap) {
            } else if (valsub instanceof Core.Type_intmap) {
              ischanged = true;
              vx_p_funcmap = (Core.Type_intmap)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("funcmap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":testpkg":
            if (valsub == vx_p_testpkg) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_testpkg = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_testpkg = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("testpkg"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":typemap":
            if (valsub == vx_p_typemap) {
            } else if (valsub instanceof Core.Type_intmap) {
              ischanged = true;
              vx_p_typemap = (Core.Type_intmap)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("typemap"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/test/testcoveragedetail", ":invalidkey", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_testcoveragedetail work = new Class_testcoveragedetail();
        work.vx_p_constmap = vx_p_constmap;
        work.vx_p_funcmap = vx_p_funcmap;
        work.vx_p_testpkg = vx_p_testpkg;
        work.vx_p_typemap = vx_p_typemap;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_testcoveragedetail vx_empty() {return e_testcoveragedetail;}
    @Override
    public Type_testcoveragedetail vx_type() {return t_testcoveragedetail;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/test", // pkgname
        "testcoveragedetail", // name
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

  public static final Type_testcoveragedetail e_testcoveragedetail = new Class_testcoveragedetail();
  public static final Type_testcoveragedetail t_testcoveragedetail = new Class_testcoveragedetail();

  /**
   * type: testcoveragenums
   * Structure to describe a test coverage summary
   * (type testcoveragenums)
   */
  public interface Type_testcoveragenums extends Core.Type_struct {
    public Test.Type_testcoveragenums vx_new(final Object... vals);
    public Test.Type_testcoveragenums vx_copy(final Object... vals);
    public Test.Type_testcoveragenums vx_empty();
    public Test.Type_testcoveragenums vx_type();
    public Core.Type_int pct();
    public Core.Type_string testpkg();
    public Core.Type_int tests();
    public Core.Type_int total();
  }

  public static class Class_testcoveragenums extends Core.Class_base implements Type_testcoveragenums {

    protected Core.Type_int vx_p_pct;

    @Override
    public Core.Type_int pct() {
      return this.vx_p_pct == null ? Core.e_int : this.vx_p_pct;
    }

    protected Core.Type_string vx_p_testpkg;

    @Override
    public Core.Type_string testpkg() {
      return this.vx_p_testpkg == null ? Core.e_string : this.vx_p_testpkg;
    }

    protected Core.Type_int vx_p_tests;

    @Override
    public Core.Type_int tests() {
      return this.vx_p_tests == null ? Core.e_int : this.vx_p_tests;
    }

    protected Core.Type_int vx_p_total;

    @Override
    public Core.Type_int total() {
      return this.vx_p_total == null ? Core.e_int : this.vx_p_total;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
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

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":pct", this.pct());
      output.put(":testpkg", this.testpkg());
      output.put(":tests", this.tests());
      output.put(":total", this.total());
      return Core.immutablemap(output);
    }

    @Override
    public Test.Type_testcoveragenums vx_new(final Object... vals) {
      return e_testcoveragenums.vx_copy(vals);
    }

    @Override
    public Test.Type_testcoveragenums vx_copy(final Object... vals) {
      Type_testcoveragenums output = this;
      boolean ischanged = false;
      Class_testcoveragenums val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_int vx_p_pct = val.pct();
      Core.Type_string vx_p_testpkg = val.testpkg();
      Core.Type_int vx_p_tests = val.tests();
      Core.Type_int vx_p_total = val.total();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":pct");
      validkeys.add(":testpkg");
      validkeys.add(":tests");
      validkeys.add(":total");
      String key = "";
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
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
            msg = Core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidkeytype", msgval);
            msgblock = msgblock.vx_copy(msg);
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
              msg = Core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidkey", msgval);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":pct":
            if (valsub == vx_p_pct) {
            } else if (valsub instanceof Core.Type_int) {
              ischanged = true;
              vx_p_pct = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_pct = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("pct"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":testpkg":
            if (valsub == vx_p_testpkg) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_testpkg = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_testpkg = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("testpkg"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":tests":
            if (valsub == vx_p_tests) {
            } else if (valsub instanceof Core.Type_int) {
              ischanged = true;
              vx_p_tests = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_tests = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("tests"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":total":
            if (valsub == vx_p_total) {
            } else if (valsub instanceof Core.Type_int) {
              ischanged = true;
              vx_p_total = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              ischanged = true;
              vx_p_total = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("total"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/test/testcoveragenums", ":invalidkey", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_testcoveragenums work = new Class_testcoveragenums();
        work.vx_p_pct = vx_p_pct;
        work.vx_p_testpkg = vx_p_testpkg;
        work.vx_p_tests = vx_p_tests;
        work.vx_p_total = vx_p_total;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_testcoveragenums vx_empty() {return e_testcoveragenums;}
    @Override
    public Type_testcoveragenums vx_type() {return t_testcoveragenums;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/test", // pkgname
        "testcoveragenums", // name
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

  public static final Type_testcoveragenums e_testcoveragenums = new Class_testcoveragenums();
  public static final Type_testcoveragenums t_testcoveragenums = new Class_testcoveragenums();

  /**
   * type: testcoveragesummary
   * Structure to describe a test coverage summary
   * (type testcoveragesummary)
   */
  public interface Type_testcoveragesummary extends Core.Type_struct {
    public Test.Type_testcoveragesummary vx_new(final Object... vals);
    public Test.Type_testcoveragesummary vx_copy(final Object... vals);
    public Test.Type_testcoveragesummary vx_empty();
    public Test.Type_testcoveragesummary vx_type();
    public Test.Type_testcoveragenums bigospacenums();
    public Test.Type_testcoveragenums bigotimenums();
    public Test.Type_testcoveragenums constnums();
    public Test.Type_testcoveragenums docnums();
    public Test.Type_testcoveragenums funcnums();
    public Core.Type_string testpkg();
    public Test.Type_testcoveragenums totalnums();
    public Test.Type_testcoveragenums typenums();
  }

  public static class Class_testcoveragesummary extends Core.Class_base implements Type_testcoveragesummary {

    protected Test.Type_testcoveragenums vx_p_bigospacenums;

    @Override
    public Test.Type_testcoveragenums bigospacenums() {
      return this.vx_p_bigospacenums == null ? Test.e_testcoveragenums : this.vx_p_bigospacenums;
    }

    protected Test.Type_testcoveragenums vx_p_bigotimenums;

    @Override
    public Test.Type_testcoveragenums bigotimenums() {
      return this.vx_p_bigotimenums == null ? Test.e_testcoveragenums : this.vx_p_bigotimenums;
    }

    protected Test.Type_testcoveragenums vx_p_constnums;

    @Override
    public Test.Type_testcoveragenums constnums() {
      return this.vx_p_constnums == null ? Test.e_testcoveragenums : this.vx_p_constnums;
    }

    protected Test.Type_testcoveragenums vx_p_docnums;

    @Override
    public Test.Type_testcoveragenums docnums() {
      return this.vx_p_docnums == null ? Test.e_testcoveragenums : this.vx_p_docnums;
    }

    protected Test.Type_testcoveragenums vx_p_funcnums;

    @Override
    public Test.Type_testcoveragenums funcnums() {
      return this.vx_p_funcnums == null ? Test.e_testcoveragenums : this.vx_p_funcnums;
    }

    protected Core.Type_string vx_p_testpkg;

    @Override
    public Core.Type_string testpkg() {
      return this.vx_p_testpkg == null ? Core.e_string : this.vx_p_testpkg;
    }

    protected Test.Type_testcoveragenums vx_p_totalnums;

    @Override
    public Test.Type_testcoveragenums totalnums() {
      return this.vx_p_totalnums == null ? Test.e_testcoveragenums : this.vx_p_totalnums;
    }

    protected Test.Type_testcoveragenums vx_p_typenums;

    @Override
    public Test.Type_testcoveragenums typenums() {
      return this.vx_p_typenums == null ? Test.e_testcoveragenums : this.vx_p_typenums;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
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

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":bigospacenums", this.bigospacenums());
      output.put(":bigotimenums", this.bigotimenums());
      output.put(":constnums", this.constnums());
      output.put(":docnums", this.docnums());
      output.put(":funcnums", this.funcnums());
      output.put(":testpkg", this.testpkg());
      output.put(":totalnums", this.totalnums());
      output.put(":typenums", this.typenums());
      return Core.immutablemap(output);
    }

    @Override
    public Test.Type_testcoveragesummary vx_new(final Object... vals) {
      return e_testcoveragesummary.vx_copy(vals);
    }

    @Override
    public Test.Type_testcoveragesummary vx_copy(final Object... vals) {
      Type_testcoveragesummary output = this;
      boolean ischanged = false;
      Class_testcoveragesummary val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Test.Type_testcoveragenums vx_p_bigospacenums = val.bigospacenums();
      Test.Type_testcoveragenums vx_p_bigotimenums = val.bigotimenums();
      Test.Type_testcoveragenums vx_p_constnums = val.constnums();
      Test.Type_testcoveragenums vx_p_docnums = val.docnums();
      Test.Type_testcoveragenums vx_p_funcnums = val.funcnums();
      Core.Type_string vx_p_testpkg = val.testpkg();
      Test.Type_testcoveragenums vx_p_totalnums = val.totalnums();
      Test.Type_testcoveragenums vx_p_typenums = val.typenums();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":bigospacenums");
      validkeys.add(":bigotimenums");
      validkeys.add(":constnums");
      validkeys.add(":docnums");
      validkeys.add(":funcnums");
      validkeys.add(":testpkg");
      validkeys.add(":totalnums");
      validkeys.add(":typenums");
      String key = "";
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
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
            msg = Core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidkeytype", msgval);
            msgblock = msgblock.vx_copy(msg);
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
              msg = Core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidkey", msgval);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":bigospacenums":
            if (valsub == vx_p_bigospacenums) {
            } else if (valsub instanceof Test.Type_testcoveragenums) {
              ischanged = true;
              vx_p_bigospacenums = (Test.Type_testcoveragenums)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("bigospacenums"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":bigotimenums":
            if (valsub == vx_p_bigotimenums) {
            } else if (valsub instanceof Test.Type_testcoveragenums) {
              ischanged = true;
              vx_p_bigotimenums = (Test.Type_testcoveragenums)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("bigotimenums"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":constnums":
            if (valsub == vx_p_constnums) {
            } else if (valsub instanceof Test.Type_testcoveragenums) {
              ischanged = true;
              vx_p_constnums = (Test.Type_testcoveragenums)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("constnums"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":docnums":
            if (valsub == vx_p_docnums) {
            } else if (valsub instanceof Test.Type_testcoveragenums) {
              ischanged = true;
              vx_p_docnums = (Test.Type_testcoveragenums)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("docnums"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":funcnums":
            if (valsub == vx_p_funcnums) {
            } else if (valsub instanceof Test.Type_testcoveragenums) {
              ischanged = true;
              vx_p_funcnums = (Test.Type_testcoveragenums)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("funcnums"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":testpkg":
            if (valsub == vx_p_testpkg) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_testpkg = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_testpkg = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("testpkg"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":totalnums":
            if (valsub == vx_p_totalnums) {
            } else if (valsub instanceof Test.Type_testcoveragenums) {
              ischanged = true;
              vx_p_totalnums = (Test.Type_testcoveragenums)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("totalnums"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":typenums":
            if (valsub == vx_p_typenums) {
            } else if (valsub instanceof Test.Type_testcoveragenums) {
              ischanged = true;
              vx_p_typenums = (Test.Type_testcoveragenums)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("typenums"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/test/testcoveragesummary", ":invalidkey", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_testcoveragesummary work = new Class_testcoveragesummary();
        work.vx_p_bigospacenums = vx_p_bigospacenums;
        work.vx_p_bigotimenums = vx_p_bigotimenums;
        work.vx_p_constnums = vx_p_constnums;
        work.vx_p_docnums = vx_p_docnums;
        work.vx_p_funcnums = vx_p_funcnums;
        work.vx_p_testpkg = vx_p_testpkg;
        work.vx_p_totalnums = vx_p_totalnums;
        work.vx_p_typenums = vx_p_typenums;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_testcoveragesummary vx_empty() {return e_testcoveragesummary;}
    @Override
    public Type_testcoveragesummary vx_type() {return t_testcoveragesummary;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/test", // pkgname
        "testcoveragesummary", // name
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

  public static final Type_testcoveragesummary e_testcoveragesummary = new Class_testcoveragesummary();
  public static final Type_testcoveragesummary t_testcoveragesummary = new Class_testcoveragesummary();

  /**
   * type: testdescribe
   * Structure to describe test results
   * (type testdescribe)
   */
  public interface Type_testdescribe extends Core.Type_struct {
    public Test.Type_testdescribe vx_new(final Object... vals);
    public Test.Type_testdescribe vx_copy(final Object... vals);
    public Test.Type_testdescribe vx_empty();
    public Test.Type_testdescribe vx_type();
    public Core.Type_string describename();
    public Core.Type_string testpkg();
    public Test.Type_testresult testresult();
  }

  public static class Class_testdescribe extends Core.Class_base implements Type_testdescribe {

    protected Core.Type_string vx_p_describename;

    @Override
    public Core.Type_string describename() {
      return this.vx_p_describename == null ? Core.e_string : this.vx_p_describename;
    }

    protected Core.Type_string vx_p_testpkg;

    @Override
    public Core.Type_string testpkg() {
      return this.vx_p_testpkg == null ? Core.e_string : this.vx_p_testpkg;
    }

    protected Test.Type_testresult vx_p_testresult;

    @Override
    public Test.Type_testresult testresult() {
      return this.vx_p_testresult == null ? Test.e_testresult : this.vx_p_testresult;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
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

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":describename", this.describename());
      output.put(":testpkg", this.testpkg());
      output.put(":testresult", this.testresult());
      return Core.immutablemap(output);
    }

    @Override
    public Test.Type_testdescribe vx_new(final Object... vals) {
      return e_testdescribe.vx_copy(vals);
    }

    @Override
    public Test.Type_testdescribe vx_copy(final Object... vals) {
      Type_testdescribe output = this;
      boolean ischanged = false;
      Class_testdescribe val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_describename = val.describename();
      Core.Type_string vx_p_testpkg = val.testpkg();
      Test.Type_testresult vx_p_testresult = val.testresult();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":describename");
      validkeys.add(":testpkg");
      validkeys.add(":testresult");
      String key = "";
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
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
            msg = Core.vx_msg_from_error("vx/test/testdescribe", ":invalidkeytype", msgval);
            msgblock = msgblock.vx_copy(msg);
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
              msg = Core.vx_msg_from_error("vx/test/testdescribe", ":invalidkey", msgval);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":describename":
            if (valsub == vx_p_describename) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_describename = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_describename = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("describename"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testdescribe", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":testpkg":
            if (valsub == vx_p_testpkg) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_testpkg = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_testpkg = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("testpkg"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testdescribe", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":testresult":
            if (valsub == vx_p_testresult) {
            } else if (valsub instanceof Test.Type_testresult) {
              ischanged = true;
              vx_p_testresult = (Test.Type_testresult)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("testresult"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testdescribe", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/test/testdescribe", ":invalidkey", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_testdescribe work = new Class_testdescribe();
        work.vx_p_describename = vx_p_describename;
        work.vx_p_testpkg = vx_p_testpkg;
        work.vx_p_testresult = vx_p_testresult;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_testdescribe vx_empty() {return e_testdescribe;}
    @Override
    public Type_testdescribe vx_type() {return t_testdescribe;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/test", // pkgname
        "testdescribe", // name
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

  public static final Type_testdescribe e_testdescribe = new Class_testdescribe();
  public static final Type_testdescribe t_testdescribe = new Class_testdescribe();

  /**
   * type: testdescribelist
   * List of testdescribe
   * (type testdescribelist)
   */
  public interface Type_testdescribelist extends Core.Type_list {
    public Test.Type_testdescribelist vx_new(final Object... vals);
    public Test.Type_testdescribelist vx_copy(final Object... vals);
    public Test.Type_testdescribelist vx_empty();
    public Test.Type_testdescribelist vx_type();
    public List<Test.Type_testdescribe> vx_listtestdescribe();
    public Test.Type_testdescribe vx_testdescribe(final Core.Type_int index);
  }

  public static class Class_testdescribelist extends Core.Class_base implements Type_testdescribelist {

    protected List<Test.Type_testdescribe> vx_p_list = Core.immutablelist(new ArrayList<Test.Type_testdescribe>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Test.Type_testdescribe vx_testdescribe(final Core.Type_int index) {
      Test.Type_testdescribe output = Test.e_testdescribe;
      Class_testdescribelist list = this;
      int iindex = index.vx_int();
      List<Test.Type_testdescribe> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Test.Type_testdescribe> vx_listtestdescribe() {return vx_p_list;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_testdescribe(index);
    }

    @Override
    public Test.Type_testdescribelist vx_new(final Object... vals) {
      return e_testdescribelist.vx_copy(vals);
    }

    @Override
    public Test.Type_testdescribelist vx_copy(final Object... vals) {
      Type_testdescribelist output = this;
      boolean ischanged = false;
      Class_testdescribelist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      List<Test.Type_testdescribe> listval = new ArrayList<>(val.vx_listtestdescribe());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Test.Type_testdescribe) {
          Test.Type_testdescribe anysub = (Test.Type_testdescribe)valsub;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub instanceof Test.Type_testdescribe) {
          ischanged = true;
          listval.add((Test.Type_testdescribe)valsub);
        } else if (valsub instanceof Test.Type_testdescribelist) {
          Type_testdescribelist multi = (Type_testdescribelist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listtestdescribe());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Test.Type_testdescribe) {
              Test.Type_testdescribe valitem = (Test.Type_testdescribe)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anysub = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/test/testdescribelist", ":invalidtype", anysub);
          msgblock = msgblock.vx_copy(msg);
        } else {
          msg = Core.vx_msg_from_error("vx/test/testdescribelist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_testdescribelist work = new Class_testdescribelist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_testdescribelist vx_empty() {return e_testdescribelist;}
    @Override
    public Type_testdescribelist vx_type() {return t_testdescribelist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/test", // pkgname
        "testdescribelist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Test.t_testdescribe), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_testdescribelist e_testdescribelist = new Class_testdescribelist();
  public static final Type_testdescribelist t_testdescribelist = new Class_testdescribelist();

  /**
   * type: testpackage
   * Structure to hold all tests for a package
   * (type testpackage)
   */
  public interface Type_testpackage extends Core.Type_struct {
    public Test.Type_testpackage vx_new(final Object... vals);
    public Test.Type_testpackage vx_copy(final Object... vals);
    public Test.Type_testpackage vx_empty();
    public Test.Type_testpackage vx_type();
    public Test.Type_testcaselist caselist();
    public Test.Type_testcoveragedetail coveragedetail();
    public Test.Type_testcoveragesummary coveragesummary();
    public Core.Type_boolean passfail();
    public Core.Type_string testpkg();
  }

  public static class Class_testpackage extends Core.Class_base implements Type_testpackage {

    protected Test.Type_testcaselist vx_p_caselist;

    @Override
    public Test.Type_testcaselist caselist() {
      return this.vx_p_caselist == null ? Test.e_testcaselist : this.vx_p_caselist;
    }

    protected Test.Type_testcoveragedetail vx_p_coveragedetail;

    @Override
    public Test.Type_testcoveragedetail coveragedetail() {
      return this.vx_p_coveragedetail == null ? Test.e_testcoveragedetail : this.vx_p_coveragedetail;
    }

    protected Test.Type_testcoveragesummary vx_p_coveragesummary;

    @Override
    public Test.Type_testcoveragesummary coveragesummary() {
      return this.vx_p_coveragesummary == null ? Test.e_testcoveragesummary : this.vx_p_coveragesummary;
    }

    protected Core.Type_boolean vx_p_passfail;

    @Override
    public Core.Type_boolean passfail() {
      return this.vx_p_passfail == null ? Core.e_boolean : this.vx_p_passfail;
    }

    protected Core.Type_string vx_p_testpkg;

    @Override
    public Core.Type_string testpkg() {
      return this.vx_p_testpkg == null ? Core.e_string : this.vx_p_testpkg;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
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

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":caselist", this.caselist());
      output.put(":coveragedetail", this.coveragedetail());
      output.put(":coveragesummary", this.coveragesummary());
      output.put(":passfail", this.passfail());
      output.put(":testpkg", this.testpkg());
      return Core.immutablemap(output);
    }

    @Override
    public Test.Type_testpackage vx_new(final Object... vals) {
      return e_testpackage.vx_copy(vals);
    }

    @Override
    public Test.Type_testpackage vx_copy(final Object... vals) {
      Type_testpackage output = this;
      boolean ischanged = false;
      Class_testpackage val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Test.Type_testcaselist vx_p_caselist = val.caselist();
      Test.Type_testcoveragedetail vx_p_coveragedetail = val.coveragedetail();
      Test.Type_testcoveragesummary vx_p_coveragesummary = val.coveragesummary();
      Core.Type_boolean vx_p_passfail = val.passfail();
      Core.Type_string vx_p_testpkg = val.testpkg();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":caselist");
      validkeys.add(":coveragedetail");
      validkeys.add(":coveragesummary");
      validkeys.add(":passfail");
      validkeys.add(":testpkg");
      String key = "";
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
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
            msg = Core.vx_msg_from_error("vx/test/testpackage", ":invalidkeytype", msgval);
            msgblock = msgblock.vx_copy(msg);
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
              msg = Core.vx_msg_from_error("vx/test/testpackage", ":invalidkey", msgval);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":caselist":
            if (valsub == vx_p_caselist) {
            } else if (valsub instanceof Test.Type_testcaselist) {
              ischanged = true;
              vx_p_caselist = (Test.Type_testcaselist)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("caselist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testpackage", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":coveragedetail":
            if (valsub == vx_p_coveragedetail) {
            } else if (valsub instanceof Test.Type_testcoveragedetail) {
              ischanged = true;
              vx_p_coveragedetail = (Test.Type_testcoveragedetail)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("coveragedetail"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testpackage", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":coveragesummary":
            if (valsub == vx_p_coveragesummary) {
            } else if (valsub instanceof Test.Type_testcoveragesummary) {
              ischanged = true;
              vx_p_coveragesummary = (Test.Type_testcoveragesummary)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("coveragesummary"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testpackage", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":passfail":
            if (valsub == vx_p_passfail) {
            } else if (valsub instanceof Core.Type_boolean) {
              ischanged = true;
              vx_p_passfail = (Core.Type_boolean)valsub;
            } else if (valsub instanceof Boolean) {
              ischanged = true;
              vx_p_passfail = Core.t_boolean.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("passfail"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testpackage", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":testpkg":
            if (valsub == vx_p_testpkg) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_testpkg = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_testpkg = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("testpkg"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testpackage", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/test/testpackage", ":invalidkey", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_testpackage work = new Class_testpackage();
        work.vx_p_caselist = vx_p_caselist;
        work.vx_p_coveragedetail = vx_p_coveragedetail;
        work.vx_p_coveragesummary = vx_p_coveragesummary;
        work.vx_p_passfail = vx_p_passfail;
        work.vx_p_testpkg = vx_p_testpkg;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_testpackage vx_empty() {return e_testpackage;}
    @Override
    public Type_testpackage vx_type() {return t_testpackage;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/test", // pkgname
        "testpackage", // name
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

  public static final Type_testpackage e_testpackage = new Class_testpackage();
  public static final Type_testpackage t_testpackage = new Class_testpackage();

  /**
   * type: testpackagelist
   * List of testpackage
   * (type testpackagelist)
   */
  public interface Type_testpackagelist extends Core.Type_list {
    public Test.Type_testpackagelist vx_new(final Object... vals);
    public Test.Type_testpackagelist vx_copy(final Object... vals);
    public Test.Type_testpackagelist vx_empty();
    public Test.Type_testpackagelist vx_type();
    public List<Test.Type_testpackage> vx_listtestpackage();
    public Test.Type_testpackage vx_testpackage(final Core.Type_int index);
  }

  public static class Class_testpackagelist extends Core.Class_base implements Type_testpackagelist {

    protected List<Test.Type_testpackage> vx_p_list = Core.immutablelist(new ArrayList<Test.Type_testpackage>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Test.Type_testpackage vx_testpackage(final Core.Type_int index) {
      Test.Type_testpackage output = Test.e_testpackage;
      Class_testpackagelist list = this;
      int iindex = index.vx_int();
      List<Test.Type_testpackage> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Test.Type_testpackage> vx_listtestpackage() {return vx_p_list;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_testpackage(index);
    }

    @Override
    public Test.Type_testpackagelist vx_new(final Object... vals) {
      return e_testpackagelist.vx_copy(vals);
    }

    @Override
    public Test.Type_testpackagelist vx_copy(final Object... vals) {
      Type_testpackagelist output = this;
      boolean ischanged = false;
      Class_testpackagelist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      List<Test.Type_testpackage> listval = new ArrayList<>(val.vx_listtestpackage());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Test.Type_testpackage) {
          Test.Type_testpackage anysub = (Test.Type_testpackage)valsub;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub instanceof Test.Type_testpackage) {
          ischanged = true;
          listval.add((Test.Type_testpackage)valsub);
        } else if (valsub instanceof Test.Type_testpackagelist) {
          Type_testpackagelist multi = (Type_testpackagelist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listtestpackage());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Test.Type_testpackage) {
              Test.Type_testpackage valitem = (Test.Type_testpackage)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anysub = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/test/testpackagelist", ":invalidtype", anysub);
          msgblock = msgblock.vx_copy(msg);
        } else {
          msg = Core.vx_msg_from_error("vx/test/testpackagelist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_testpackagelist work = new Class_testpackagelist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_testpackagelist vx_empty() {return e_testpackagelist;}
    @Override
    public Type_testpackagelist vx_type() {return t_testpackagelist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/test", // pkgname
        "testpackagelist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Test.t_testpackage), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_testpackagelist e_testpackagelist = new Class_testpackagelist();
  public static final Type_testpackagelist t_testpackagelist = new Class_testpackagelist();

  /**
   * type: testresult
   * Structure to hold test results
   * (type testresult)
   */
  public interface Type_testresult extends Core.Type_struct {
    public Test.Type_testresult vx_new(final Object... vals);
    public Test.Type_testresult vx_copy(final Object... vals);
    public Test.Type_testresult vx_empty();
    public Test.Type_testresult vx_type();
    public Core.Type_string code();
    public Core.Type_boolean passfail();
    public Core.Type_any expected();
    public Core.Type_any actual();
    public Core.Func_any_from_func_async fn_actual();
  }

  public static class Class_testresult extends Core.Class_base implements Type_testresult {

    protected Core.Type_string vx_p_code;

    @Override
    public Core.Type_string code() {
      return this.vx_p_code == null ? Core.e_string : this.vx_p_code;
    }

    protected Core.Type_boolean vx_p_passfail;

    @Override
    public Core.Type_boolean passfail() {
      return this.vx_p_passfail == null ? Core.e_boolean : this.vx_p_passfail;
    }

    protected Core.Type_any vx_p_expected;

    @Override
    public Core.Type_any expected() {
      return this.vx_p_expected == null ? Core.e_any : this.vx_p_expected;
    }

    protected Core.Type_any vx_p_actual;

    @Override
    public Core.Type_any actual() {
      return this.vx_p_actual == null ? Core.e_any : this.vx_p_actual;
    }

    protected Core.Func_any_from_func_async vx_p_fn_actual;

    @Override
    public Core.Func_any_from_func_async fn_actual() {
      return this.vx_p_fn_actual == null ? Core.e_any_from_func_async : this.vx_p_fn_actual;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
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

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":code", this.code());
      output.put(":passfail", this.passfail());
      output.put(":expected", this.expected());
      output.put(":actual", this.actual());
      output.put(":fn-actual", this.fn_actual());
      return Core.immutablemap(output);
    }

    @Override
    public Test.Type_testresult vx_new(final Object... vals) {
      return e_testresult.vx_copy(vals);
    }

    @Override
    public Test.Type_testresult vx_copy(final Object... vals) {
      Type_testresult output = this;
      boolean ischanged = false;
      Class_testresult val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_code = val.code();
      Core.Type_boolean vx_p_passfail = val.passfail();
      Core.Type_any vx_p_expected = val.expected();
      Core.Type_any vx_p_actual = val.actual();
      Core.Func_any_from_func_async vx_p_fn_actual = val.fn_actual();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":code");
      validkeys.add(":passfail");
      validkeys.add(":expected");
      validkeys.add(":actual");
      validkeys.add(":fn-actual");
      String key = "";
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
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
            msg = Core.vx_msg_from_error("vx/test/testresult", ":invalidkeytype", msgval);
            msgblock = msgblock.vx_copy(msg);
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
              msg = Core.vx_msg_from_error("vx/test/testresult", ":invalidkey", msgval);
              msgblock = msgblock.vx_copy(msg);
            }
          }
        } else {
          switch (key) {
          case ":code":
            if (valsub == vx_p_code) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_code = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_code = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("code"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testresult", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":passfail":
            if (valsub == vx_p_passfail) {
            } else if (valsub instanceof Core.Type_boolean) {
              ischanged = true;
              vx_p_passfail = (Core.Type_boolean)valsub;
            } else if (valsub instanceof Boolean) {
              ischanged = true;
              vx_p_passfail = Core.t_boolean.vx_new(valsub);
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("passfail"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testresult", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":expected":
            if (valsub == vx_p_expected) {
            } else if (valsub instanceof Core.Type_any) {
              ischanged = true;
              vx_p_expected = (Core.Type_any)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("expected"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testresult", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":actual":
            if (valsub == vx_p_actual) {
            } else if (valsub instanceof Core.Type_any) {
              ischanged = true;
              vx_p_actual = (Core.Type_any)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("actual"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testresult", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":fn-actual":
            if (valsub == vx_p_fn_actual) {
            } else if (valsub instanceof Core.Func_any_from_func_async) {
              ischanged = true;
              vx_p_fn_actual = (Core.Func_any_from_func_async)valsub;
            } else {
              Core.Type_any msgval;
              if (valsub instanceof Core.Type_any) {
                msgval = (Core.Type_any)valsub;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<>();
              mapany.put("key", Core.vx_new_string("fn-actual"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/test/testresult", ":invalidvalue", msgmap);
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_any msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/test/testresult", ":invalidkey", msgval);
            msgblock = msgblock.vx_copy(msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_testresult work = new Class_testresult();
        work.vx_p_code = vx_p_code;
        work.vx_p_passfail = vx_p_passfail;
        work.vx_p_expected = vx_p_expected;
        work.vx_p_actual = vx_p_actual;
        work.vx_p_fn_actual = vx_p_fn_actual;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_testresult vx_empty() {return e_testresult;}
    @Override
    public Type_testresult vx_type() {return t_testresult;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/test", // pkgname
        "testresult", // name
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

  public static final Type_testresult e_testresult = new Class_testresult();
  public static final Type_testresult t_testresult = new Class_testresult();

  /**
   * type: testresultlist
   * List of test results
   * (type testresultlist)
   */
  public interface Type_testresultlist extends Core.Type_list {
    public Test.Type_testresultlist vx_new(final Object... vals);
    public Test.Type_testresultlist vx_copy(final Object... vals);
    public Test.Type_testresultlist vx_empty();
    public Test.Type_testresultlist vx_type();
    public List<Test.Type_testresult> vx_listtestresult();
    public Test.Type_testresult vx_testresult(final Core.Type_int index);
  }

  public static class Class_testresultlist extends Core.Class_base implements Type_testresultlist {

    protected List<Test.Type_testresult> vx_p_list = Core.immutablelist(new ArrayList<Test.Type_testresult>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vx_p_list));}

    @Override
    public Test.Type_testresult vx_testresult(final Core.Type_int index) {
      Test.Type_testresult output = Test.e_testresult;
      Class_testresultlist list = this;
      int iindex = index.vx_int();
      List<Test.Type_testresult> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Test.Type_testresult> vx_listtestresult() {return vx_p_list;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_testresult(index);
    }

    @Override
    public Test.Type_testresultlist vx_new(final Object... vals) {
      return e_testresultlist.vx_copy(vals);
    }

    @Override
    public Test.Type_testresultlist vx_copy(final Object... vals) {
      Type_testresultlist output = this;
      boolean ischanged = false;
      Class_testresultlist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      List<Test.Type_testresult> listval = new ArrayList<>(val.vx_listtestresult());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Test.Type_testresult) {
          Test.Type_testresult anysub = (Test.Type_testresult)valsub;
          ischanged = true;
          listval.add(anysub);
        } else if (valsub instanceof Test.Type_testresult) {
          ischanged = true;
          listval.add((Test.Type_testresult)valsub);
        } else if (valsub instanceof Test.Type_testresultlist) {
          Type_testresultlist multi = (Type_testresultlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listtestresult());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Test.Type_testresult) {
              Test.Type_testresult valitem = (Test.Type_testresult)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anysub = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/test/testresultlist", ":invalidtype", anysub);
          msgblock = msgblock.vx_copy(msg);
        } else {
          msg = Core.vx_msg_from_error("vx/test/testresultlist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = msgblock.vx_copy(msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_testresultlist work = new Class_testresultlist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Type_testresultlist vx_empty() {return e_testresultlist;}
    @Override
    public Type_testresultlist vx_type() {return t_testresultlist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/test", // pkgname
        "testresultlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Test.t_testresult), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_testresultlist e_testresultlist = new Class_testresultlist();
  public static final Type_testresultlist t_testresultlist = new Class_testresultlist();

  /**
   * Constant: stylesheet-test
   * The default Test Stylesheet
   * {stylesheet}
   */
  public static class Const_stylesheet_test extends Html.Class_stylesheet implements Core.vx_Type_const {

    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/test", // pkgname
        "stylesheet-test", // name
        Core.typedef_new(
          "vx/web/html", // pkgname
          "stylesheet", // name
          ":struct", // extends
          Core.t_typelist.vx_new(Html.t_node, Html.t_headchild), // traits
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

    public static void const_new(Const_stylesheet_test output) {
      Html.Type_stylesheet val = Html.f_stylesheet_loadmap(
        Core.f_new(
          Html.t_stylesheet,
          Core.t_anylist.vx_new(
            Core.vx_new_string(":name"),
            Core.vx_new_string("Test Suite"),
            Core.vx_new_string(":styles"),
            Core.f_new(
              Html.t_stylelist,
              Core.t_anylist.vx_new(
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":name"),
                    Core.vx_new_string("body"),
                    Core.vx_new_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string("font-size"),
                        Core.vx_new_string("0.9em"),
                        Core.vx_new_string("font-family"),
                        Core.vx_new_string("sans-serif")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":name"),
                    Core.vx_new_string("details summary"),
                    Core.vx_new_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string("cursor"),
                        Core.vx_new_string("pointer"),
                        Core.vx_new_string("display"),
                        Core.vx_new_string("inline-flex"),
                        Core.vx_new_string("gap"),
                        Core.vx_new_string("10px")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":name"),
                    Core.vx_new_string("table"),
                    Core.vx_new_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string("vertical-align"),
                        Core.vx_new_string("top"),
                        Core.vx_new_string("border-collapse"),
                        Core.vx_new_string("collapse"),
                        Core.vx_new_string("margin"),
                        Core.vx_new_string("25px 0"),
                        Core.vx_new_string("min-width"),
                        Core.vx_new_string("400px"),
                        Core.vx_new_string("box-shadow"),
                        Core.vx_new_string("0 0 20px rgba(0, 0, 0, 0.15)")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":name"),
                    Core.vx_new_string("thead tr"),
                    Core.vx_new_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string("background-color"),
                        Core.vx_new_string("#009879"),
                        Core.vx_new_string("color"),
                        Core.vx_new_string("#ffffff"),
                        Core.vx_new_string("text-align"),
                        Core.vx_new_string("left")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":name"),
                    Core.vx_new_string("td"),
                    Core.vx_new_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string("padding"),
                        Core.vx_new_string("10px 10px"),
                        Core.vx_new_string("vertical-align"),
                        Core.vx_new_string("top")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":name"),
                    Core.vx_new_string("tbody tr"),
                    Core.vx_new_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string("border-bottom"),
                        Core.vx_new_string("1px solid #dddddd")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":name"),
                    Core.vx_new_string("tbody tr:nth-of-type(even)"),
                    Core.vx_new_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string("background-color"),
                        Core.vx_new_string("#f3f3f3")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":name"),
                    Core.vx_new_string("tbody tr:last-of-type"),
                    Core.vx_new_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string("border-bottom"),
                        Core.vx_new_string("2px solid #009879")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":name"),
                    Core.vx_new_string("tbody tr.active-row"),
                    Core.vx_new_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string("font-weight"),
                        Core.vx_new_string("bold"),
                        Core.vx_new_string("color"),
                        Core.vx_new_string("#009879")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":name"),
                    Core.vx_new_string(".failflag"),
                    Core.vx_new_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string("background-color"),
                        Core.vx_new_string("red"),
                        Core.vx_new_string("color"),
                        Core.vx_new_string("white"),
                        Core.vx_new_string("padding-left"),
                        Core.vx_new_string("4px"),
                        Core.vx_new_string("padding-right"),
                        Core.vx_new_string("4px"),
                        Core.vx_new_string("padding-top"),
                        Core.vx_new_string("1px"),
                        Core.vx_new_string("padding-bottom"),
                        Core.vx_new_string("1px")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":name"),
                    Core.vx_new_string(".passflag"),
                    Core.vx_new_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string("background-color"),
                        Core.vx_new_string("green"),
                        Core.vx_new_string("color"),
                        Core.vx_new_string("white"),
                        Core.vx_new_string("padding-left"),
                        Core.vx_new_string("4px"),
                        Core.vx_new_string("padding-right"),
                        Core.vx_new_string("4px"),
                        Core.vx_new_string("padding-top"),
                        Core.vx_new_string("1px"),
                        Core.vx_new_string("padding-bottom"),
                        Core.vx_new_string("1px")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":name"),
                    Core.vx_new_string(".coveragenums"),
                    Core.vx_new_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string("width"),
                        Core.vx_new_string("90px")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":name"),
                    Core.vx_new_string(".coveragepct"),
                    Core.vx_new_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string("text-align"),
                        Core.vx_new_string("right")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":name"),
                    Core.vx_new_string(".coveragepctgreen"),
                    Core.vx_new_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string("background-color"),
                        Core.vx_new_string("green"),
                        Core.vx_new_string("color"),
                        Core.vx_new_string("white"),
                        Core.vx_new_string("text-align"),
                        Core.vx_new_string("right")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":name"),
                    Core.vx_new_string(".coveragepctred"),
                    Core.vx_new_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string("background-color"),
                        Core.vx_new_string("red"),
                        Core.vx_new_string("color"),
                        Core.vx_new_string("white"),
                        Core.vx_new_string("text-align"),
                        Core.vx_new_string("right")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":name"),
                    Core.vx_new_string(".pkgheader"),
                    Core.vx_new_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string("display"),
                        Core.vx_new_string("inline-flex"),
                        Core.vx_new_string("gap"),
                        Core.vx_new_string("10px")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":name"),
                    Core.vx_new_string(".pkgname"),
                    Core.vx_new_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string("font-weight"),
                        Core.vx_new_string("bold"),
                        Core.vx_new_string("width"),
                        Core.vx_new_string("180px")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":name"),
                    Core.vx_new_string(".preformatted"),
                    Core.vx_new_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.vx_new_string("display"),
                        Core.vx_new_string("block"),
                        Core.vx_new_string("unicode-bidi"),
                        Core.vx_new_string("embed"),
                        Core.vx_new_string("font-family"),
                        Core.vx_new_string("monospace"),
                        Core.vx_new_string("white-space"),
                        Core.vx_new_string("pre")
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

  public static final Const_stylesheet_test c_stylesheet_test = new Const_stylesheet_test();

  /**
   * @function context_test
   * Returns the default context for test case execution. Arguments come from the command line.
   * @param  {anylist} args
   * @return {context}
   * (func context-test)
   */
  public interface Func_context_test extends Core.Func_any_from_any {
    public Core.Type_context vx_context_test(final Core.Type_anylist args);
  }

  public static class Class_context_test extends Core.Class_base implements Func_context_test {

    @Override
    public Test.Func_context_test vx_new(final Object... vals) {
      Class_context_test output = new Class_context_test();
      return output;
    }

    @Override
    public Test.Func_context_test vx_copy(final Object... vals) {
      Class_context_test output = new Class_context_test();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "context-test", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "context", // name
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
    public Func_context_test vx_empty() {return e_context_test;}
    @Override
    public Func_context_test vx_type() {return t_context_test;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_anylist inputval = (Core.Type_anylist)value;
      Core.Type_any outputval = Test.f_context_test(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_anylist args = Core.f_any_from_any(Core.t_anylist, arglist.vx_any(Core.vx_new_int(0)));
      output = Test.f_context_test(args);
      return output;
    }

    @Override
    public Core.Type_context vx_context_test(final Core.Type_anylist args) {
      return Test.f_context_test(args);
    }

  }

  public static final Func_context_test e_context_test = new Test.Class_context_test();
  public static final Func_context_test t_context_test = new Test.Class_context_test();

  public static Core.Type_context f_context_test(final Core.Type_anylist args) {
    Core.Type_context output = Core.e_context;
    output = Core.f_new(
      Core.t_context,
      Core.t_anylist.vx_new(
        Core.vx_new_string(":session"),
        Core.f_new(
          Core.t_session,
          Core.t_anylist.vx_new(
            Core.vx_new_string(":user"),
            Core.f_new(
              Core.t_user,
              Core.t_anylist.vx_new(
                Core.vx_new_string(":security"),
                Test.f_security_test()
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
  public interface Func_div_from_testcaselist extends Core.Func_any_from_any {
    public Html.Type_div vx_div_from_testcaselist(final Test.Type_testcaselist testcaselist);
  }

  public static class Class_div_from_testcaselist extends Core.Class_base implements Func_div_from_testcaselist {

    @Override
    public Test.Func_div_from_testcaselist vx_new(final Object... vals) {
      Class_div_from_testcaselist output = new Class_div_from_testcaselist();
      return output;
    }

    @Override
    public Test.Func_div_from_testcaselist vx_copy(final Object... vals) {
      Class_div_from_testcaselist output = new Class_div_from_testcaselist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "div<-testcaselist", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/web/html", // pkgname
          "div", // name
          ":struct", // extends
          Core.t_typelist.vx_new(Html.t_node, Html.t_divchild), // traits
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
    public Func_div_from_testcaselist vx_empty() {return e_div_from_testcaselist;}
    @Override
    public Func_div_from_testcaselist vx_type() {return t_div_from_testcaselist;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Test.Type_testcaselist inputval = (Test.Type_testcaselist)value;
      Core.Type_any outputval = Test.f_div_from_testcaselist(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Test.Type_testcaselist testcaselist = Core.f_any_from_any(Test.t_testcaselist, arglist.vx_any(Core.vx_new_int(0)));
      output = Test.f_div_from_testcaselist(testcaselist);
      return output;
    }

    @Override
    public Html.Type_div vx_div_from_testcaselist(final Test.Type_testcaselist testcaselist) {
      return Test.f_div_from_testcaselist(testcaselist);
    }

  }

  public static final Func_div_from_testcaselist e_div_from_testcaselist = new Test.Class_div_from_testcaselist();
  public static final Func_div_from_testcaselist t_div_from_testcaselist = new Test.Class_div_from_testcaselist();

  public static Html.Type_div f_div_from_testcaselist(final Test.Type_testcaselist testcaselist) {
    Html.Type_div output = Html.e_div;
    output = Core.f_new(
      Html.t_div,
      Core.t_anylist.vx_new(
        Core.f_new(
          Html.t_table,
          Core.t_anylist.vx_new(
            Core.vx_new_string(":thead"),
            Core.f_new(
              Html.t_thead,
              Core.t_anylist.vx_new(
                Core.f_new(
                  Html.t_tr,
                  Core.t_anylist.vx_new(
                    Core.f_new(
                      Html.t_td,
                      Core.t_anylist.vx_new(
                        Core.f_new(
                          Html.t_p,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":text"),
                            Core.vx_new_string("Pass?")
                          )
                        )
                      )
                    ),
                    Core.f_new(
                      Html.t_td,
                      Core.t_anylist.vx_new(
                        Core.f_new(
                          Html.t_p,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":text"),
                            Core.vx_new_string("Name")
                          )
                        )
                      )
                    ),
                    Core.f_new(
                      Html.t_td,
                      Core.t_anylist.vx_new(
                        Core.f_new(
                          Html.t_p,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":text"),
                            Core.vx_new_string("Test")
                          )
                        )
                      )
                    ),
                    Core.f_new(
                      Html.t_td,
                      Core.t_anylist.vx_new(
                        Core.f_new(
                          Html.t_p,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":text"),
                            Core.vx_new_string("Expected")
                          )
                        )
                      )
                    ),
                    Core.f_new(
                      Html.t_td,
                      Core.t_anylist.vx_new(
                        Core.f_new(
                          Html.t_p,
                          Core.t_anylist.vx_new(
                            Core.vx_new_string(":text"),
                            Core.vx_new_string("Actual")
                          )
                        )
                      )
                    )
                  )
                )
              )
            ),
            Core.vx_new_string(":tbody"),
            Core.f_new(
              Html.t_tbody,
              Core.t_anylist.vx_new(
                Test.f_trlist_from_testcaselist(testcaselist)
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
  public interface Func_div_from_testpackage extends Core.Func_any_from_any {
    public Html.Type_div vx_div_from_testpackage(final Test.Type_testpackage testpackage);
  }

  public static class Class_div_from_testpackage extends Core.Class_base implements Func_div_from_testpackage {

    @Override
    public Test.Func_div_from_testpackage vx_new(final Object... vals) {
      Class_div_from_testpackage output = new Class_div_from_testpackage();
      return output;
    }

    @Override
    public Test.Func_div_from_testpackage vx_copy(final Object... vals) {
      Class_div_from_testpackage output = new Class_div_from_testpackage();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "div<-testpackage", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/web/html", // pkgname
          "div", // name
          ":struct", // extends
          Core.t_typelist.vx_new(Html.t_node, Html.t_divchild), // traits
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
    public Func_div_from_testpackage vx_empty() {return e_div_from_testpackage;}
    @Override
    public Func_div_from_testpackage vx_type() {return t_div_from_testpackage;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Test.Type_testpackage inputval = (Test.Type_testpackage)value;
      Core.Type_any outputval = Test.f_div_from_testpackage(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Test.Type_testpackage testpackage = Core.f_any_from_any(Test.t_testpackage, arglist.vx_any(Core.vx_new_int(0)));
      output = Test.f_div_from_testpackage(testpackage);
      return output;
    }

    @Override
    public Html.Type_div vx_div_from_testpackage(final Test.Type_testpackage testpackage) {
      return Test.f_div_from_testpackage(testpackage);
    }

  }

  public static final Func_div_from_testpackage e_div_from_testpackage = new Test.Class_div_from_testpackage();
  public static final Func_div_from_testpackage t_div_from_testpackage = new Test.Class_div_from_testpackage();

  public static Html.Type_div f_div_from_testpackage(final Test.Type_testpackage testpackage) {
    Html.Type_div output = Html.e_div;
    output = Core.f_let(
      Html.t_div,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Test.Type_testcoveragesummary testcoveragesummary = testpackage.coveragesummary();
        final Core.Type_string pkgname = testpackage.testpkg();
        final Test.Type_testcaselist caselist = testpackage.caselist();
        final Core.Type_boolean passfail = testpackage.passfail();
        final Html.Type_style pkgnamestyle = Html.f_style_from_stylesheet_name(
          Test.c_stylesheet_test,
          Core.vx_new_string(".pkgname")
        );
        final Html.Type_div node = Test.f_div_from_testcaselist(caselist);
        final Html.Type_divchildlist nodes = Core.f_new(
          Html.t_divchildlist,
          Core.t_anylist.vx_new(
              node
          )
        );
        final Html.Type_p p_passfail = Test.f_p_from_passfail(passfail);
        final Html.Type_p p_pkgname = Core.f_new(
          Html.t_p,
          Core.t_anylist.vx_new(
              Core.vx_new_string(":style"),
              pkgnamestyle,
              Core.vx_new_string(":text"),
              pkgname
          )
        );
        final Html.Type_p p_totalnums = Test.f_p_from_testcoveragenums(
          testcoveragesummary.totalnums()
        );
        final Html.Type_p p_coveragenums = Test.f_p_from_testcoveragenums(
          testcoveragesummary.typenums()
        );
        final Html.Type_p p_constnums = Test.f_p_from_testcoveragenums(
          testcoveragesummary.constnums()
        );
        final Html.Type_p p_funcnums = Test.f_p_from_testcoveragenums(
          testcoveragesummary.funcnums()
        );
        final Html.Type_p p_docnums = Test.f_p_from_testcoveragenums(
          testcoveragesummary.docnums()
        );
        final Html.Type_p p_bigospacenums = Test.f_p_from_testcoveragenums(
          testcoveragesummary.bigospacenums()
        );
        final Html.Type_p p_bigotimenums = Test.f_p_from_testcoveragenums(
          testcoveragesummary.bigotimenums()
        );
        final Html.Type_divchildlist summary = Core.f_new(
          Html.t_divchildlist,
          Core.t_anylist.vx_new(
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
        final Html.Type_details details = Core.f_new(
          Html.t_details,
          Core.t_anylist.vx_new(
              Core.vx_new_string(":summary"),
              summary,
              Core.vx_new_string(":nodes"),
              nodes
          )
        );
        return Core.f_new(
          Html.t_div,
          Core.t_anylist.vx_new(
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
  public interface Func_div_from_testpackagelist extends Core.Func_any_from_any {
    public Html.Type_div vx_div_from_testpackagelist(final Test.Type_testpackagelist testpackagelist);
  }

  public static class Class_div_from_testpackagelist extends Core.Class_base implements Func_div_from_testpackagelist {

    @Override
    public Test.Func_div_from_testpackagelist vx_new(final Object... vals) {
      Class_div_from_testpackagelist output = new Class_div_from_testpackagelist();
      return output;
    }

    @Override
    public Test.Func_div_from_testpackagelist vx_copy(final Object... vals) {
      Class_div_from_testpackagelist output = new Class_div_from_testpackagelist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "div<-testpackagelist", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/web/html", // pkgname
          "div", // name
          ":struct", // extends
          Core.t_typelist.vx_new(Html.t_node, Html.t_divchild), // traits
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
    public Func_div_from_testpackagelist vx_empty() {return e_div_from_testpackagelist;}
    @Override
    public Func_div_from_testpackagelist vx_type() {return t_div_from_testpackagelist;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Test.Type_testpackagelist inputval = (Test.Type_testpackagelist)value;
      Core.Type_any outputval = Test.f_div_from_testpackagelist(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Test.Type_testpackagelist testpackagelist = Core.f_any_from_any(Test.t_testpackagelist, arglist.vx_any(Core.vx_new_int(0)));
      output = Test.f_div_from_testpackagelist(testpackagelist);
      return output;
    }

    @Override
    public Html.Type_div vx_div_from_testpackagelist(final Test.Type_testpackagelist testpackagelist) {
      return Test.f_div_from_testpackagelist(testpackagelist);
    }

  }

  public static final Func_div_from_testpackagelist e_div_from_testpackagelist = new Test.Class_div_from_testpackagelist();
  public static final Func_div_from_testpackagelist t_div_from_testpackagelist = new Test.Class_div_from_testpackagelist();

  public static Html.Type_div f_div_from_testpackagelist(final Test.Type_testpackagelist testpackagelist) {
    Html.Type_div output = Html.e_div;
    output = Core.f_let(
      Html.t_div,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Html.Type_style stylepassfail = Html.f_style_from_stylesheet_name(
          Test.c_stylesheet_test,
          Core.vx_new_string(".passfail")
        );
        final Html.Type_style stylepkgname = Html.f_style_from_stylesheet_name(
          Test.c_stylesheet_test,
          Core.vx_new_string(".pkgname")
        );
        final Html.Type_style stylepkgheader = Html.f_style_from_stylesheet_name(
          Test.c_stylesheet_test,
          Core.vx_new_string(".pkgheader")
        );
        final Html.Type_style stylecoveragenum = Html.f_style_from_stylesheet_name(
          Test.c_stylesheet_test,
          Core.vx_new_string(".coveragenums")
        );
        return Core.f_new(
          Html.t_div,
          Core.t_anylist.vx_new(
            Core.f_new(
              Html.t_div,
              Core.t_anylist.vx_new(
                Core.vx_new_string(":style"),
                stylepkgheader,
                Core.f_new(
                  Html.t_p,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":style"),
                    stylepassfail,
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("Pass?")
                  )
                ),
                Core.f_new(
                  Html.t_p,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":style"),
                    stylepkgname,
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("Package Name")
                  )
                ),
                Core.f_new(
                  Html.t_p,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":style"),
                    stylecoveragenum,
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("Coverage")
                  )
                ),
                Core.f_new(
                  Html.t_p,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":style"),
                    stylecoveragenum,
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("(type)")
                  )
                ),
                Core.f_new(
                  Html.t_p,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":style"),
                    stylecoveragenum,
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("(const)")
                  )
                ),
                Core.f_new(
                  Html.t_p,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":style"),
                    stylecoveragenum,
                    Core.vx_new_string(":text"),
                    Core.vx_new_string("(func)")
                  )
                ),
                Core.f_new(
                  Html.t_p,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":style"),
                    stylecoveragenum,
                    Core.vx_new_string(":text"),
                    Core.vx_new_string(":doc")
                  )
                ),
                Core.f_new(
                  Html.t_p,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":style"),
                    stylecoveragenum,
                    Core.vx_new_string(":text"),
                    Core.vx_new_string(":bigospace")
                  )
                ),
                Core.f_new(
                  Html.t_p,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":style"),
                    stylecoveragenum,
                    Core.vx_new_string(":text"),
                    Core.vx_new_string(":bigotime")
                  )
                )
              )
            ),
            Core.f_new(
              Html.t_div,
              Core.t_anylist.vx_new(
                Test.f_divchildlist_from_testpackagelist(testpackagelist)
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
  public interface Func_divchildlist_from_testpackagelist extends Core.Func_any_from_any {
    public Html.Type_divchildlist vx_divchildlist_from_testpackagelist(final Test.Type_testpackagelist testpackagelist);
  }

  public static class Class_divchildlist_from_testpackagelist extends Core.Class_base implements Func_divchildlist_from_testpackagelist {

    @Override
    public Test.Func_divchildlist_from_testpackagelist vx_new(final Object... vals) {
      Class_divchildlist_from_testpackagelist output = new Class_divchildlist_from_testpackagelist();
      return output;
    }

    @Override
    public Test.Func_divchildlist_from_testpackagelist vx_copy(final Object... vals) {
      Class_divchildlist_from_testpackagelist output = new Class_divchildlist_from_testpackagelist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "divchildlist<-testpackagelist", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/web/html", // pkgname
          "divchildlist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Html.t_divchild), // allowtypes
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
    public Func_divchildlist_from_testpackagelist vx_empty() {return e_divchildlist_from_testpackagelist;}
    @Override
    public Func_divchildlist_from_testpackagelist vx_type() {return t_divchildlist_from_testpackagelist;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Test.Type_testpackagelist inputval = (Test.Type_testpackagelist)value;
      Core.Type_any outputval = Test.f_divchildlist_from_testpackagelist(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Test.Type_testpackagelist testpackagelist = Core.f_any_from_any(Test.t_testpackagelist, arglist.vx_any(Core.vx_new_int(0)));
      output = Test.f_divchildlist_from_testpackagelist(testpackagelist);
      return output;
    }

    @Override
    public Html.Type_divchildlist vx_divchildlist_from_testpackagelist(final Test.Type_testpackagelist testpackagelist) {
      return Test.f_divchildlist_from_testpackagelist(testpackagelist);
    }

  }

  public static final Func_divchildlist_from_testpackagelist e_divchildlist_from_testpackagelist = new Test.Class_divchildlist_from_testpackagelist();
  public static final Func_divchildlist_from_testpackagelist t_divchildlist_from_testpackagelist = new Test.Class_divchildlist_from_testpackagelist();

  public static Html.Type_divchildlist f_divchildlist_from_testpackagelist(final Test.Type_testpackagelist testpackagelist) {
    Html.Type_divchildlist output = Html.e_divchildlist;
    output = Core.f_list_from_list_1(
      Html.t_divchildlist,
      testpackagelist,
      Test.t_div_from_testpackage
    );
    return output;
  }

  /**
   * @function file_test
   * Default file location for testsuite.vxlisp
   * @return {file}
   * (func file-test)
   */
  public interface Func_file_test extends Core.Type_func, Core.Type_replfunc {
    public File.Type_file vx_file_test();
  }

  public static class Class_file_test extends Core.Class_base implements Func_file_test {

    @Override
    public Test.Func_file_test vx_new(final Object... vals) {
      Class_file_test output = new Class_file_test();
      return output;
    }

    @Override
    public Test.Func_file_test vx_copy(final Object... vals) {
      Class_file_test output = new Class_file_test();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "file-test", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/file", // pkgname
          "file", // name
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
    public Func_file_test vx_empty() {return e_file_test;}
    @Override
    public Func_file_test vx_type() {return t_file_test;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      output = Test.f_file_test();
      return output;
    }

    @Override
    public File.Type_file vx_file_test() {
      return Test.f_file_test();
    }

  }

  public static final Func_file_test e_file_test = new Test.Class_file_test();
  public static final Func_file_test t_file_test = new Test.Class_file_test();

  public static File.Type_file f_file_test() {
    File.Type_file output = File.e_file;
    output = Core.f_new(
      File.t_file,
      Core.t_anylist.vx_new(
        Core.vx_new_string(":name"),
        Core.vx_new_string("testsuite.vxlisp"),
        Core.vx_new_string(":path"),
        Core.vx_new_string("src/test/resources")
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
  public interface Func_file_testhtml extends Core.Type_func, Core.Type_replfunc {
    public File.Type_file vx_file_testhtml();
  }

  public static class Class_file_testhtml extends Core.Class_base implements Func_file_testhtml {

    @Override
    public Test.Func_file_testhtml vx_new(final Object... vals) {
      Class_file_testhtml output = new Class_file_testhtml();
      return output;
    }

    @Override
    public Test.Func_file_testhtml vx_copy(final Object... vals) {
      Class_file_testhtml output = new Class_file_testhtml();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "file-testhtml", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/file", // pkgname
          "file", // name
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
    public Func_file_testhtml vx_empty() {return e_file_testhtml;}
    @Override
    public Func_file_testhtml vx_type() {return t_file_testhtml;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      output = Test.f_file_testhtml();
      return output;
    }

    @Override
    public File.Type_file vx_file_testhtml() {
      return Test.f_file_testhtml();
    }

  }

  public static final Func_file_testhtml e_file_testhtml = new Test.Class_file_testhtml();
  public static final Func_file_testhtml t_file_testhtml = new Test.Class_file_testhtml();

  public static File.Type_file f_file_testhtml() {
    File.Type_file output = File.e_file;
    output = Core.f_new(
      File.t_file,
      Core.t_anylist.vx_new(
        Core.vx_new_string(":name"),
        Core.vx_new_string("testsuite.html"),
        Core.vx_new_string(":path"),
        Core.vx_new_string("src/test/resources")
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
  public interface Func_file_testnode extends Core.Type_func, Core.Type_replfunc {
    public File.Type_file vx_file_testnode();
  }

  public static class Class_file_testnode extends Core.Class_base implements Func_file_testnode {

    @Override
    public Test.Func_file_testnode vx_new(final Object... vals) {
      Class_file_testnode output = new Class_file_testnode();
      return output;
    }

    @Override
    public Test.Func_file_testnode vx_copy(final Object... vals) {
      Class_file_testnode output = new Class_file_testnode();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "file-testnode", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/data/file", // pkgname
          "file", // name
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
    public Func_file_testnode vx_empty() {return e_file_testnode;}
    @Override
    public Func_file_testnode vx_type() {return t_file_testnode;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      output = Test.f_file_testnode();
      return output;
    }

    @Override
    public File.Type_file vx_file_testnode() {
      return Test.f_file_testnode();
    }

  }

  public static final Func_file_testnode e_file_testnode = new Test.Class_file_testnode();
  public static final Func_file_testnode t_file_testnode = new Test.Class_file_testnode();

  public static File.Type_file f_file_testnode() {
    File.Type_file output = File.e_file;
    output = Core.f_new(
      File.t_file,
      Core.t_anylist.vx_new(
        Core.vx_new_string(":name"),
        Core.vx_new_string("testsuitenode.vxlisp"),
        Core.vx_new_string(":path"),
        Core.vx_new_string("src/test/resources")
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
  public interface Func_html_from_divtest extends Core.Func_any_from_any {
    public Html.Type_html vx_html_from_divtest(final Html.Type_div divtest);
  }

  public static class Class_html_from_divtest extends Core.Class_base implements Func_html_from_divtest {

    @Override
    public Test.Func_html_from_divtest vx_new(final Object... vals) {
      Class_html_from_divtest output = new Class_html_from_divtest();
      return output;
    }

    @Override
    public Test.Func_html_from_divtest vx_copy(final Object... vals) {
      Class_html_from_divtest output = new Class_html_from_divtest();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "html<-divtest", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/web/html", // pkgname
          "html", // name
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
    public Func_html_from_divtest vx_empty() {return e_html_from_divtest;}
    @Override
    public Func_html_from_divtest vx_type() {return t_html_from_divtest;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Html.Type_div inputval = (Html.Type_div)value;
      Core.Type_any outputval = Test.f_html_from_divtest(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_div divtest = Core.f_any_from_any(Html.t_div, arglist.vx_any(Core.vx_new_int(0)));
      output = Test.f_html_from_divtest(divtest);
      return output;
    }

    @Override
    public Html.Type_html vx_html_from_divtest(final Html.Type_div divtest) {
      return Test.f_html_from_divtest(divtest);
    }

  }

  public static final Func_html_from_divtest e_html_from_divtest = new Test.Class_html_from_divtest();
  public static final Func_html_from_divtest t_html_from_divtest = new Test.Class_html_from_divtest();

  public static Html.Type_html f_html_from_divtest(final Html.Type_div divtest) {
    Html.Type_html output = Html.e_html;
    output = Core.f_new(
      Html.t_html,
      Core.t_anylist.vx_new(
        Core.vx_new_string(":lang"),
        Core.vx_new_string("en"),
        Core.vx_new_string(":head"),
        Core.f_new(
          Html.t_head,
          Core.t_anylist.vx_new(
            Core.f_new(
              Html.t_meta,
              Core.t_anylist.vx_new(
                Core.vx_new_string(":charset"),
                Core.vx_new_string("utf-8")
              )
            ),
            Core.f_new(
              Html.t_meta,
              Core.t_anylist.vx_new(
                Core.vx_new_string(":name"),
                Core.vx_new_string("viewport"),
                Core.vx_new_string(":content"),
                Core.vx_new_string("width=device-width, initial-scale=1.0")
              )
            ),
            Core.f_new(
              Html.t_title,
              Core.t_anylist.vx_new(
                Core.vx_new_string(":text"),
                Core.vx_new_string("Test Suite")
              )
            ),
            Test.c_stylesheet_test
          )
        ),
        Core.vx_new_string(":body"),
        Core.f_new(
          Html.t_body,
          Core.t_anylist.vx_new(
            Core.f_new(
              Html.t_div,
              Core.t_anylist.vx_new(
                Core.f_new(
                  Html.t_h1,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string("Test Suite")
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
  public interface Func_p_from_passfail extends Core.Func_any_from_any {
    public Html.Type_p vx_p_from_passfail(final Core.Type_boolean passfail);
  }

  public static class Class_p_from_passfail extends Core.Class_base implements Func_p_from_passfail {

    @Override
    public Test.Func_p_from_passfail vx_new(final Object... vals) {
      Class_p_from_passfail output = new Class_p_from_passfail();
      return output;
    }

    @Override
    public Test.Func_p_from_passfail vx_copy(final Object... vals) {
      Class_p_from_passfail output = new Class_p_from_passfail();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "p<-passfail", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/web/html", // pkgname
          "p", // name
          ":struct", // extends
          Core.t_typelist.vx_new(Html.t_node, Html.t_divchild), // traits
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
    public Func_p_from_passfail vx_empty() {return e_p_from_passfail;}
    @Override
    public Func_p_from_passfail vx_type() {return t_p_from_passfail;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_boolean inputval = (Core.Type_boolean)value;
      Core.Type_any outputval = Test.f_p_from_passfail(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_boolean passfail = Core.f_any_from_any(Core.t_boolean, arglist.vx_any(Core.vx_new_int(0)));
      output = Test.f_p_from_passfail(passfail);
      return output;
    }

    @Override
    public Html.Type_p vx_p_from_passfail(final Core.Type_boolean passfail) {
      return Test.f_p_from_passfail(passfail);
    }

  }

  public static final Func_p_from_passfail e_p_from_passfail = new Test.Class_p_from_passfail();
  public static final Func_p_from_passfail t_p_from_passfail = new Test.Class_p_from_passfail();

  public static Html.Type_p f_p_from_passfail(final Core.Type_boolean passfail) {
    Html.Type_p output = Html.e_p;
    output = Core.f_let(
      Html.t_p,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string text = Core.f_if_1(Core.t_string, passfail, Core.vx_new_string("Pass"), Core.vx_new_string("Fail"));
        final Core.Type_string stylename = Core.f_if_1(Core.t_string, passfail, Core.vx_new_string(".passflag"), Core.vx_new_string(".failflag"));
        final Html.Type_style style = Html.f_style_from_stylesheet_name(
          Test.c_stylesheet_test,
          stylename
        );
        return Core.f_new(
          Html.t_p,
          Core.t_anylist.vx_new(
            Core.vx_new_string(":style"),
            style,
            Core.vx_new_string(":text"),
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
  public interface Func_p_from_testcoveragenums extends Core.Func_any_from_any {
    public Html.Type_p vx_p_from_testcoveragenums(final Test.Type_testcoveragenums nums);
  }

  public static class Class_p_from_testcoveragenums extends Core.Class_base implements Func_p_from_testcoveragenums {

    @Override
    public Test.Func_p_from_testcoveragenums vx_new(final Object... vals) {
      Class_p_from_testcoveragenums output = new Class_p_from_testcoveragenums();
      return output;
    }

    @Override
    public Test.Func_p_from_testcoveragenums vx_copy(final Object... vals) {
      Class_p_from_testcoveragenums output = new Class_p_from_testcoveragenums();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "p<-testcoveragenums", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/web/html", // pkgname
          "p", // name
          ":struct", // extends
          Core.t_typelist.vx_new(Html.t_node, Html.t_divchild), // traits
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
    public Func_p_from_testcoveragenums vx_empty() {return e_p_from_testcoveragenums;}
    @Override
    public Func_p_from_testcoveragenums vx_type() {return t_p_from_testcoveragenums;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Test.Type_testcoveragenums inputval = (Test.Type_testcoveragenums)value;
      Core.Type_any outputval = Test.f_p_from_testcoveragenums(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Test.Type_testcoveragenums nums = Core.f_any_from_any(Test.t_testcoveragenums, arglist.vx_any(Core.vx_new_int(0)));
      output = Test.f_p_from_testcoveragenums(nums);
      return output;
    }

    @Override
    public Html.Type_p vx_p_from_testcoveragenums(final Test.Type_testcoveragenums nums) {
      return Test.f_p_from_testcoveragenums(nums);
    }

  }

  public static final Func_p_from_testcoveragenums e_p_from_testcoveragenums = new Test.Class_p_from_testcoveragenums();
  public static final Func_p_from_testcoveragenums t_p_from_testcoveragenums = new Test.Class_p_from_testcoveragenums();

  public static Html.Type_p f_p_from_testcoveragenums(final Test.Type_testcoveragenums nums) {
    Html.Type_p output = Html.e_p;
    output = Core.f_new(
      Html.t_p,
      Core.t_anylist.vx_new(
        Core.vx_new_string(":style"),
        Html.f_style_from_stylesheet_name(
          Test.c_stylesheet_test,
          Core.vx_new_string(".coveragenums")
        ),
        Core.vx_new_string(":text"),
        Core.f_new(
          Core.t_string,
          Core.t_anylist.vx_new(
            nums.pct(),
            Core.vx_new_string("% "),
            nums.tests(),
            Core.vx_new_string("/"),
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
  public interface Func_resolve_testcase extends Core.Func_any_from_any_async {
    public CompletableFuture<Test.Type_testcase> vx_resolve_testcase(final Test.Type_testcase testcase);
  }

  public static class Class_resolve_testcase extends Core.Class_base implements Func_resolve_testcase {

    @Override
    public Test.Func_resolve_testcase vx_new(final Object... vals) {
      Class_resolve_testcase output = new Class_resolve_testcase();
      return output;
    }

    @Override
    public Test.Func_resolve_testcase vx_copy(final Object... vals) {
      Class_resolve_testcase output = new Class_resolve_testcase();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testcase", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/test", // pkgname
          "testcase", // name
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
    public Func_resolve_testcase vx_empty() {return e_resolve_testcase;}
    @Override
    public Func_resolve_testcase vx_type() {return t_resolve_testcase;}

    @Override
    public Core.Func_any_from_any_async vx_fn_new(Core.Class_any_from_any_async.IFn fn) {return Core.e_any_from_any_async;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> vx_any_from_any_async(final T generic_any_1, final U value) {
      Test.Type_testcase inputval = Core.f_any_from_any(Test.t_testcase, value);
      CompletableFuture<Test.Type_testcase> future = Test.f_resolve_testcase(inputval);
      @SuppressWarnings("unchecked")
      CompletableFuture<T> output = (CompletableFuture<T>)future;
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Test.Type_testcase testcase = Core.f_any_from_any(Test.t_testcase, arglist.vx_any(Core.vx_new_int(0)));
      CompletableFuture<Test.Type_testcase> future = Test.f_resolve_testcase(testcase);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Test.Type_testcase> vx_resolve_testcase(final Test.Type_testcase testcase) {
      return Test.f_resolve_testcase(testcase);
    }

  }

  public static final Func_resolve_testcase e_resolve_testcase = new Test.Class_resolve_testcase();
  public static final Func_resolve_testcase t_resolve_testcase = new Test.Class_resolve_testcase();

  public static CompletableFuture<Test.Type_testcase> f_resolve_testcase(final Test.Type_testcase testcase) {
    CompletableFuture<Test.Type_testcase> output = Core.async_new_completed(Test.e_testcase);
    output = Core.f_let_async(
      Test.t_testcase,
      Core.t_any_from_func_async.vx_fn_new(() -> {
        final Test.Type_testdescribelist describelist = testcase.describelist();
        final CompletableFuture<Test.Type_testdescribelist> future_resolvedlist = Test.f_resolve_testdescribelist(describelist);
        return Core.async_from_async_fn(future_resolvedlist, (resolvedlist) -> {
          final Core.Type_booleanlist passfaillist = Core.f_list_from_list_1(
            Core.t_booleanlist,
            resolvedlist,
            Core.t_any_from_any.vx_fn_new((testdescribe_any) -> {
              Test.Type_testdescribe testdescribe = Core.f_any_from_any(Test.t_testdescribe, testdescribe_any);
              return 
                  Core.f_let(
                    Core.t_boolean,
                    Core.t_any_from_func.vx_fn_new(() -> {
                      final Test.Type_testresult testresult = testdescribe.testresult();
                      return testresult.passfail();
                    })
                  );
            })
          );
          final Core.Type_boolean passfail = Core.f_and_1(passfaillist);
          return Core.f_copy(
            testcase,
            Core.t_anylist.vx_new(
                  Core.vx_new_string(":passfail"),
                  passfail,
                  Core.vx_new_string(":describelist"),
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
  public interface Func_resolve_testcaselist extends Core.Func_any_from_any_async {
    public CompletableFuture<Test.Type_testcaselist> vx_resolve_testcaselist(final Test.Type_testcaselist testcaselist);
  }

  public static class Class_resolve_testcaselist extends Core.Class_base implements Func_resolve_testcaselist {

    @Override
    public Test.Func_resolve_testcaselist vx_new(final Object... vals) {
      Class_resolve_testcaselist output = new Class_resolve_testcaselist();
      return output;
    }

    @Override
    public Test.Func_resolve_testcaselist vx_copy(final Object... vals) {
      Class_resolve_testcaselist output = new Class_resolve_testcaselist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testcaselist", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/test", // pkgname
          "testcaselist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Test.t_testcase), // allowtypes
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
    public Func_resolve_testcaselist vx_empty() {return e_resolve_testcaselist;}
    @Override
    public Func_resolve_testcaselist vx_type() {return t_resolve_testcaselist;}

    @Override
    public Core.Func_any_from_any_async vx_fn_new(Core.Class_any_from_any_async.IFn fn) {return Core.e_any_from_any_async;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> vx_any_from_any_async(final T generic_any_1, final U value) {
      Test.Type_testcaselist inputval = Core.f_any_from_any(Test.t_testcaselist, value);
      CompletableFuture<Test.Type_testcaselist> future = Test.f_resolve_testcaselist(inputval);
      @SuppressWarnings("unchecked")
      CompletableFuture<T> output = (CompletableFuture<T>)future;
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Test.Type_testcaselist testcaselist = Core.f_any_from_any(Test.t_testcaselist, arglist.vx_any(Core.vx_new_int(0)));
      CompletableFuture<Test.Type_testcaselist> future = Test.f_resolve_testcaselist(testcaselist);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Test.Type_testcaselist> vx_resolve_testcaselist(final Test.Type_testcaselist testcaselist) {
      return Test.f_resolve_testcaselist(testcaselist);
    }

  }

  public static final Func_resolve_testcaselist e_resolve_testcaselist = new Test.Class_resolve_testcaselist();
  public static final Func_resolve_testcaselist t_resolve_testcaselist = new Test.Class_resolve_testcaselist();

  public static CompletableFuture<Test.Type_testcaselist> f_resolve_testcaselist(final Test.Type_testcaselist testcaselist) {
    CompletableFuture<Test.Type_testcaselist> output = Core.async_new_completed(Test.e_testcaselist);
    output = Core.f_list_from_list_async(
      Test.t_testcaselist,
      testcaselist,
      Test.t_resolve_testcase
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
  public interface Func_resolve_testdescribe extends Core.Func_any_from_any_async {
    public CompletableFuture<Test.Type_testdescribe> vx_resolve_testdescribe(final Test.Type_testdescribe testdescribe);
  }

  public static class Class_resolve_testdescribe extends Core.Class_base implements Func_resolve_testdescribe {

    @Override
    public Test.Func_resolve_testdescribe vx_new(final Object... vals) {
      Class_resolve_testdescribe output = new Class_resolve_testdescribe();
      return output;
    }

    @Override
    public Test.Func_resolve_testdescribe vx_copy(final Object... vals) {
      Class_resolve_testdescribe output = new Class_resolve_testdescribe();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testdescribe", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/test", // pkgname
          "testdescribe", // name
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
    public Func_resolve_testdescribe vx_empty() {return e_resolve_testdescribe;}
    @Override
    public Func_resolve_testdescribe vx_type() {return t_resolve_testdescribe;}

    @Override
    public Core.Func_any_from_any_async vx_fn_new(Core.Class_any_from_any_async.IFn fn) {return Core.e_any_from_any_async;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> vx_any_from_any_async(final T generic_any_1, final U value) {
      Test.Type_testdescribe inputval = Core.f_any_from_any(Test.t_testdescribe, value);
      CompletableFuture<Test.Type_testdescribe> future = Test.f_resolve_testdescribe(inputval);
      @SuppressWarnings("unchecked")
      CompletableFuture<T> output = (CompletableFuture<T>)future;
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Test.Type_testdescribe testdescribe = Core.f_any_from_any(Test.t_testdescribe, arglist.vx_any(Core.vx_new_int(0)));
      CompletableFuture<Test.Type_testdescribe> future = Test.f_resolve_testdescribe(testdescribe);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Test.Type_testdescribe> vx_resolve_testdescribe(final Test.Type_testdescribe testdescribe) {
      return Test.f_resolve_testdescribe(testdescribe);
    }

  }

  public static final Func_resolve_testdescribe e_resolve_testdescribe = new Test.Class_resolve_testdescribe();
  public static final Func_resolve_testdescribe t_resolve_testdescribe = new Test.Class_resolve_testdescribe();

  public static CompletableFuture<Test.Type_testdescribe> f_resolve_testdescribe(final Test.Type_testdescribe testdescribe) {
    CompletableFuture<Test.Type_testdescribe> output = Core.async_new_completed(Test.e_testdescribe);
    output = Core.f_let_async(
      Test.t_testdescribe,
      Core.t_any_from_func_async.vx_fn_new(() -> {
        final Test.Type_testresult testresult = testdescribe.testresult();
        final CompletableFuture<Test.Type_testresult> future_resolved = Test.f_resolve_testresult(testresult);
        return Core.async_from_async_fn(future_resolved, (resolved) -> {
          return Core.f_copy(
            testdescribe,
            Core.t_anylist.vx_new(
                  Core.vx_new_string(":testresult"),
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
  public interface Func_resolve_testdescribelist extends Core.Func_any_from_any_async {
    public CompletableFuture<Test.Type_testdescribelist> vx_resolve_testdescribelist(final Test.Type_testdescribelist testdescribelist);
  }

  public static class Class_resolve_testdescribelist extends Core.Class_base implements Func_resolve_testdescribelist {

    @Override
    public Test.Func_resolve_testdescribelist vx_new(final Object... vals) {
      Class_resolve_testdescribelist output = new Class_resolve_testdescribelist();
      return output;
    }

    @Override
    public Test.Func_resolve_testdescribelist vx_copy(final Object... vals) {
      Class_resolve_testdescribelist output = new Class_resolve_testdescribelist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testdescribelist", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/test", // pkgname
          "testdescribelist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Test.t_testdescribe), // allowtypes
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
    public Func_resolve_testdescribelist vx_empty() {return e_resolve_testdescribelist;}
    @Override
    public Func_resolve_testdescribelist vx_type() {return t_resolve_testdescribelist;}

    @Override
    public Core.Func_any_from_any_async vx_fn_new(Core.Class_any_from_any_async.IFn fn) {return Core.e_any_from_any_async;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> vx_any_from_any_async(final T generic_any_1, final U value) {
      Test.Type_testdescribelist inputval = Core.f_any_from_any(Test.t_testdescribelist, value);
      CompletableFuture<Test.Type_testdescribelist> future = Test.f_resolve_testdescribelist(inputval);
      @SuppressWarnings("unchecked")
      CompletableFuture<T> output = (CompletableFuture<T>)future;
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Test.Type_testdescribelist testdescribelist = Core.f_any_from_any(Test.t_testdescribelist, arglist.vx_any(Core.vx_new_int(0)));
      CompletableFuture<Test.Type_testdescribelist> future = Test.f_resolve_testdescribelist(testdescribelist);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Test.Type_testdescribelist> vx_resolve_testdescribelist(final Test.Type_testdescribelist testdescribelist) {
      return Test.f_resolve_testdescribelist(testdescribelist);
    }

  }

  public static final Func_resolve_testdescribelist e_resolve_testdescribelist = new Test.Class_resolve_testdescribelist();
  public static final Func_resolve_testdescribelist t_resolve_testdescribelist = new Test.Class_resolve_testdescribelist();

  public static CompletableFuture<Test.Type_testdescribelist> f_resolve_testdescribelist(final Test.Type_testdescribelist testdescribelist) {
    CompletableFuture<Test.Type_testdescribelist> output = Core.async_new_completed(Test.e_testdescribelist);
    output = Core.f_list_from_list_async(
      Test.t_testdescribelist,
      testdescribelist,
      Test.t_resolve_testdescribe
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
  public interface Func_resolve_testpackage extends Core.Func_any_from_any_async {
    public CompletableFuture<Test.Type_testpackage> vx_resolve_testpackage(final Test.Type_testpackage testpackage);
  }

  public static class Class_resolve_testpackage extends Core.Class_base implements Func_resolve_testpackage {

    @Override
    public Test.Func_resolve_testpackage vx_new(final Object... vals) {
      Class_resolve_testpackage output = new Class_resolve_testpackage();
      return output;
    }

    @Override
    public Test.Func_resolve_testpackage vx_copy(final Object... vals) {
      Class_resolve_testpackage output = new Class_resolve_testpackage();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testpackage", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/test", // pkgname
          "testpackage", // name
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
    public Func_resolve_testpackage vx_empty() {return e_resolve_testpackage;}
    @Override
    public Func_resolve_testpackage vx_type() {return t_resolve_testpackage;}

    @Override
    public Core.Func_any_from_any_async vx_fn_new(Core.Class_any_from_any_async.IFn fn) {return Core.e_any_from_any_async;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> vx_any_from_any_async(final T generic_any_1, final U value) {
      Test.Type_testpackage inputval = Core.f_any_from_any(Test.t_testpackage, value);
      CompletableFuture<Test.Type_testpackage> future = Test.f_resolve_testpackage(inputval);
      @SuppressWarnings("unchecked")
      CompletableFuture<T> output = (CompletableFuture<T>)future;
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Test.Type_testpackage testpackage = Core.f_any_from_any(Test.t_testpackage, arglist.vx_any(Core.vx_new_int(0)));
      CompletableFuture<Test.Type_testpackage> future = Test.f_resolve_testpackage(testpackage);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Test.Type_testpackage> vx_resolve_testpackage(final Test.Type_testpackage testpackage) {
      return Test.f_resolve_testpackage(testpackage);
    }

  }

  public static final Func_resolve_testpackage e_resolve_testpackage = new Test.Class_resolve_testpackage();
  public static final Func_resolve_testpackage t_resolve_testpackage = new Test.Class_resolve_testpackage();

  public static CompletableFuture<Test.Type_testpackage> f_resolve_testpackage(final Test.Type_testpackage testpackage) {
    CompletableFuture<Test.Type_testpackage> output = Core.async_new_completed(Test.e_testpackage);
    output = Core.f_let_async(
      Test.t_testpackage,
      Core.t_any_from_func_async.vx_fn_new(() -> {
        final Test.Type_testcaselist testcaselist = testpackage.caselist();
        final CompletableFuture<Test.Type_testcaselist> future_resolvedlist = Test.f_resolve_testcaselist(testcaselist);
        return Core.async_from_async_fn(future_resolvedlist, (resolvedlist) -> {
          final Core.Type_booleanlist passfaillist = Core.f_list_from_list_1(
            Core.t_booleanlist,
            resolvedlist,
            Core.t_any_from_any.vx_fn_new((testcase_any) -> {
              Test.Type_testcase testcase = Core.f_any_from_any(Test.t_testcase, testcase_any);
              return 
                  testcase.passfail();
            })
          );
          final Core.Type_boolean passfail = Core.f_and_1(passfaillist);
          return Core.f_copy(
            testpackage,
            Core.t_anylist.vx_new(
                  Core.vx_new_string(":passfail"),
                  passfail,
                  Core.vx_new_string(":caselist"),
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
  public interface Func_resolve_testpackagelist extends Core.Func_any_from_any_async {
    public CompletableFuture<Test.Type_testpackagelist> vx_resolve_testpackagelist(final Test.Type_testpackagelist testpackagelist);
  }

  public static class Class_resolve_testpackagelist extends Core.Class_base implements Func_resolve_testpackagelist {

    @Override
    public Test.Func_resolve_testpackagelist vx_new(final Object... vals) {
      Class_resolve_testpackagelist output = new Class_resolve_testpackagelist();
      return output;
    }

    @Override
    public Test.Func_resolve_testpackagelist vx_copy(final Object... vals) {
      Class_resolve_testpackagelist output = new Class_resolve_testpackagelist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testpackagelist", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/test", // pkgname
          "testpackagelist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Test.t_testpackage), // allowtypes
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
    public Func_resolve_testpackagelist vx_empty() {return e_resolve_testpackagelist;}
    @Override
    public Func_resolve_testpackagelist vx_type() {return t_resolve_testpackagelist;}

    @Override
    public Core.Func_any_from_any_async vx_fn_new(Core.Class_any_from_any_async.IFn fn) {return Core.e_any_from_any_async;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> vx_any_from_any_async(final T generic_any_1, final U value) {
      Test.Type_testpackagelist inputval = Core.f_any_from_any(Test.t_testpackagelist, value);
      CompletableFuture<Test.Type_testpackagelist> future = Test.f_resolve_testpackagelist(inputval);
      @SuppressWarnings("unchecked")
      CompletableFuture<T> output = (CompletableFuture<T>)future;
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Test.Type_testpackagelist testpackagelist = Core.f_any_from_any(Test.t_testpackagelist, arglist.vx_any(Core.vx_new_int(0)));
      CompletableFuture<Test.Type_testpackagelist> future = Test.f_resolve_testpackagelist(testpackagelist);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Test.Type_testpackagelist> vx_resolve_testpackagelist(final Test.Type_testpackagelist testpackagelist) {
      return Test.f_resolve_testpackagelist(testpackagelist);
    }

  }

  public static final Func_resolve_testpackagelist e_resolve_testpackagelist = new Test.Class_resolve_testpackagelist();
  public static final Func_resolve_testpackagelist t_resolve_testpackagelist = new Test.Class_resolve_testpackagelist();

  public static CompletableFuture<Test.Type_testpackagelist> f_resolve_testpackagelist(final Test.Type_testpackagelist testpackagelist) {
    CompletableFuture<Test.Type_testpackagelist> output = Core.async_new_completed(Test.e_testpackagelist);
    output = Core.f_list_from_list_async(
      Test.t_testpackagelist,
      testpackagelist,
      Test.t_resolve_testpackage
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
  public interface Func_resolve_testresult extends Core.Func_any_from_any_async {
    public CompletableFuture<Test.Type_testresult> vx_resolve_testresult(final Test.Type_testresult testresult);
  }

  public static class Class_resolve_testresult extends Core.Class_base implements Func_resolve_testresult {

    @Override
    public Test.Func_resolve_testresult vx_new(final Object... vals) {
      Class_resolve_testresult output = new Class_resolve_testresult();
      return output;
    }

    @Override
    public Test.Func_resolve_testresult vx_copy(final Object... vals) {
      Class_resolve_testresult output = new Class_resolve_testresult();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "resolve-testresult", // name
        0, // idx
        true, // async
        Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
    public Func_resolve_testresult vx_empty() {return e_resolve_testresult;}
    @Override
    public Func_resolve_testresult vx_type() {return t_resolve_testresult;}

    @Override
    public Core.Func_any_from_any_async vx_fn_new(Core.Class_any_from_any_async.IFn fn) {return Core.e_any_from_any_async;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> vx_any_from_any_async(final T generic_any_1, final U value) {
      Test.Type_testresult inputval = Core.f_any_from_any(Test.t_testresult, value);
      CompletableFuture<Test.Type_testresult> future = Test.f_resolve_testresult(inputval);
      @SuppressWarnings("unchecked")
      CompletableFuture<T> output = (CompletableFuture<T>)future;
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Test.Type_testresult testresult = Core.f_any_from_any(Test.t_testresult, arglist.vx_any(Core.vx_new_int(0)));
      CompletableFuture<Test.Type_testresult> future = Test.f_resolve_testresult(testresult);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Test.Type_testresult> vx_resolve_testresult(final Test.Type_testresult testresult) {
      return Test.f_resolve_testresult(testresult);
    }

  }

  public static final Func_resolve_testresult e_resolve_testresult = new Test.Class_resolve_testresult();
  public static final Func_resolve_testresult t_resolve_testresult = new Test.Class_resolve_testresult();

  public static CompletableFuture<Test.Type_testresult> f_resolve_testresult(final Test.Type_testresult testresult) {
    CompletableFuture<Test.Type_testresult> output = Core.async_new_completed(Test.e_testresult);
    output = Core.f_let_async(
      Test.t_testresult,
      Core.t_any_from_func_async.vx_fn_new(() -> {
        final Core.Func_any_from_func_async fn_actual = testresult.fn_actual();
        final Core.Type_any expected = testresult.expected();
        final CompletableFuture<Core.Type_any> future_actual = Core.f_resolve_async(Core.t_any, fn_actual);
        return Core.async_from_async_fn(future_actual, (actual) -> {
          return Core.f_if_2(
            Test.t_testresult,
            Core.t_thenelselist.vx_new(
                  Core.f_then(
                    Core.t_boolean_from_func.vx_fn_new(() -> {
                      return Core.f_is_empty_1(fn_actual);
                    }),
                    Core.t_any_from_func.vx_fn_new(() -> {
                      return testresult;
                    })
                  ),
                  Core.f_else(
                    Core.t_any_from_func.vx_fn_new(() -> {
                      return Core.f_let(
                        Test.t_testresult,
                        Core.t_any_from_func.vx_fn_new(() -> {
                          final Core.Type_boolean passfail = Core.f_eq(expected, actual);
                          return Core.f_copy(
                            testresult,
                            Core.t_anylist.vx_new(
                              Core.vx_new_string(":passfail"),
                              passfail,
                              Core.vx_new_string(":actual"),
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
  public interface Func_security_test extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_security vx_security_test();
  }

  public static class Class_security_test extends Core.Class_base implements Func_security_test {

    @Override
    public Test.Func_security_test vx_new(final Object... vals) {
      Class_security_test output = new Class_security_test();
      return output;
    }

    @Override
    public Test.Func_security_test vx_copy(final Object... vals) {
      Class_security_test output = new Class_security_test();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "security-test", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "security", // name
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
    public Func_security_test vx_empty() {return e_security_test;}
    @Override
    public Func_security_test vx_type() {return t_security_test;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      output = Test.f_security_test();
      return output;
    }

    @Override
    public Core.Type_security vx_security_test() {
      return Test.f_security_test();
    }

  }

  public static final Func_security_test e_security_test = new Test.Class_security_test();
  public static final Func_security_test t_security_test = new Test.Class_security_test();

  public static Core.Type_security f_security_test() {
    Core.Type_security output = Core.e_security;
    output = Core.f_new(
      Core.t_security,
      Core.t_anylist.vx_new(
        Core.vx_new_string(":allowfuncs"),
        Core.f_new(
          Core.t_funclist,
          Core.t_anylist.vx_new(
            File.t_boolean_write_from_file_any,
            File.t_boolean_write_from_file_string,
            File.t_file_read_from_file,
            File.t_string_read_from_file
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
  public interface Func_test extends Core.Type_func, Core.Type_replfunc {
    public Test.Type_testresult vx_test(final Core.Type_context context, final Core.Type_any expected, final Core.Type_any actual);
  }

  public static class Class_test extends Core.Class_base implements Func_test {

    @Override
    public Test.Func_test vx_new(final Object... vals) {
      Class_test output = new Class_test();
      return output;
    }

    @Override
    public Test.Func_test vx_copy(final Object... vals) {
      Class_test output = new Class_test();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "test", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
    public Func_test vx_empty() {return e_test;}
    @Override
    public Func_test vx_type() {return t_test;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any expected = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any actual = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Test.f_test(context, expected, actual);
      return output;
    }

    @Override
    public Test.Type_testresult vx_test(final Core.Type_context context, final Core.Type_any expected, final Core.Type_any actual) {
      return Test.f_test(context, expected, actual);
    }

  }

  public static final Func_test e_test = new Test.Class_test();
  public static final Func_test t_test = new Test.Class_test();

  public static Test.Type_testresult f_test(final Core.Type_context context, final Core.Type_any expected, final Core.Type_any actual) {
    Test.Type_testresult output = Test.e_testresult;
    try {
      output = Core.f_new(
        Test.t_testresult,
        Core.t_anylist.vx_new(
          Core.vx_new_string(":code"),
          Core.vx_new_string(":eq"),
          Core.vx_new_string(":passfail"),
          Core.f_eq(expected, actual),
          Core.vx_new_string(":expected"),
          expected,
          Core.vx_new_string(":actual"),
          actual
        )
      );
    } catch (Exception err) {
      Core.Type_msg msg = Core.vx_msg_from_exception("vx/test/test", err);
      output = output.vx_copy(msg);
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
  public interface Func_test_1 extends Core.Type_func, Core.Type_replfunc {
    public Test.Type_testresult vx_test_1(final Core.Type_context context, final Core.Type_any expected, final Core.Func_any_from_func_async fn_actual);
  }

  public static class Class_test_1 extends Core.Class_base implements Func_test_1 {

    @Override
    public Test.Func_test_1 vx_new(final Object... vals) {
      Class_test_1 output = new Class_test_1();
      return output;
    }

    @Override
    public Test.Func_test_1 vx_copy(final Object... vals) {
      Class_test_1 output = new Class_test_1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "test", // name
        1, // idx
        false, // async
        Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
    public Func_test_1 vx_empty() {return e_test_1;}
    @Override
    public Func_test_1 vx_type() {return t_test_1;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any expected = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_any_from_func_async fn_actual = Core.f_any_from_any(Core.t_any_from_func_async, arglist.vx_any(Core.vx_new_int(1)));
      output = Test.f_test_1(context, expected, fn_actual);
      return output;
    }

    @Override
    public Test.Type_testresult vx_test_1(final Core.Type_context context, final Core.Type_any expected, final Core.Func_any_from_func_async fn_actual) {
      return Test.f_test_1(context, expected, fn_actual);
    }

  }

  public static final Func_test_1 e_test_1 = new Test.Class_test_1();
  public static final Func_test_1 t_test_1 = new Test.Class_test_1();

  public static Test.Type_testresult f_test_1(final Core.Type_context context, final Core.Type_any expected, final Core.Func_any_from_func_async fn_actual) {
    Test.Type_testresult output = Test.e_testresult;
    try {
      output = Core.f_new(
        Test.t_testresult,
        Core.t_anylist.vx_new(
          Core.vx_new_string(":code"),
          Core.vx_new_string(":eq"),
          Core.vx_new_string(":expected"),
          expected,
          Core.vx_new_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (Exception err) {
      Core.Type_msg msg = Core.vx_msg_from_exception("vx/test/test", err);
      output = output.vx_copy(msg);
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
  public interface Func_test_false extends Core.Func_any_from_any_context {
    public Test.Type_testresult vx_test_false(final Core.Type_context context, final Core.Type_any actual);
  }

  public static class Class_test_false extends Core.Class_base implements Func_test_false {

    @Override
    public Test.Func_test_false vx_new(final Object... vals) {
      Class_test_false output = new Class_test_false();
      return output;
    }

    @Override
    public Test.Func_test_false vx_copy(final Object... vals) {
      Class_test_false output = new Class_test_false();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "test-false", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
    public Func_test_false vx_empty() {return e_test_false;}
    @Override
    public Func_test_false vx_type() {return t_test_false;}

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Test.f_test_false(context, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any actual = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Test.f_test_false(context, actual);
      return output;
    }

    @Override
    public Test.Type_testresult vx_test_false(final Core.Type_context context, final Core.Type_any actual) {
      return Test.f_test_false(context, actual);
    }

  }

  public static final Func_test_false e_test_false = new Test.Class_test_false();
  public static final Func_test_false t_test_false = new Test.Class_test_false();

  public static Test.Type_testresult f_test_false(final Core.Type_context context, final Core.Type_any actual) {
    Test.Type_testresult output = Test.e_testresult;
    try {
      output = Core.f_new(
        Test.t_testresult,
        Core.t_anylist.vx_new(
          Core.vx_new_string(":code"),
          Core.vx_new_string(":false"),
          Core.vx_new_string(":passfail"),
          Core.f_eq(
            Core.vx_new_boolean(false),
            actual
          ),
          Core.vx_new_string(":expected"),
          Core.vx_new_boolean(false),
          Core.vx_new_string(":actual"),
          actual
        )
      );
    } catch (Exception err) {
      Core.Type_msg msg = Core.vx_msg_from_exception("vx/test/test-false", err);
      output = output.vx_copy(msg);
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
  public interface Func_test_false_1 extends Core.Func_any_from_any_context {
    public Test.Type_testresult vx_test_false_1(final Core.Type_context context, final Core.Func_any_from_func_async fn_actual);
  }

  public static class Class_test_false_1 extends Core.Class_base implements Func_test_false_1 {

    @Override
    public Test.Func_test_false_1 vx_new(final Object... vals) {
      Class_test_false_1 output = new Class_test_false_1();
      return output;
    }

    @Override
    public Test.Func_test_false_1 vx_copy(final Object... vals) {
      Class_test_false_1 output = new Class_test_false_1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "test-false", // name
        1, // idx
        false, // async
        Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
    public Func_test_false_1 vx_empty() {return e_test_false_1;}
    @Override
    public Func_test_false_1 vx_type() {return t_test_false_1;}

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Func_any_from_func_async inputval = (Core.Func_any_from_func_async)value;
      Core.Type_any outputval = Test.f_test_false_1(context, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_any_from_func_async fn_actual = Core.f_any_from_any(Core.t_any_from_func_async, arglist.vx_any(Core.vx_new_int(0)));
      output = Test.f_test_false_1(context, fn_actual);
      return output;
    }

    @Override
    public Test.Type_testresult vx_test_false_1(final Core.Type_context context, final Core.Func_any_from_func_async fn_actual) {
      return Test.f_test_false_1(context, fn_actual);
    }

  }

  public static final Func_test_false_1 e_test_false_1 = new Test.Class_test_false_1();
  public static final Func_test_false_1 t_test_false_1 = new Test.Class_test_false_1();

  public static Test.Type_testresult f_test_false_1(final Core.Type_context context, final Core.Func_any_from_func_async fn_actual) {
    Test.Type_testresult output = Test.e_testresult;
    try {
      output = Core.f_new(
        Test.t_testresult,
        Core.t_anylist.vx_new(
          Core.vx_new_string(":code"),
          Core.vx_new_string(":false"),
          Core.vx_new_string(":expected"),
          Core.vx_new_boolean(false),
          Core.vx_new_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (Exception err) {
      Core.Type_msg msg = Core.vx_msg_from_exception("vx/test/test-false", err);
      output = output.vx_copy(msg);
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
  public interface Func_test_gt extends Core.Type_func, Core.Type_replfunc {
    public Test.Type_testresult vx_test_gt(final Core.Type_context context, final Core.Type_any expected, final Core.Type_any actual);
  }

  public static class Class_test_gt extends Core.Class_base implements Func_test_gt {

    @Override
    public Test.Func_test_gt vx_new(final Object... vals) {
      Class_test_gt output = new Class_test_gt();
      return output;
    }

    @Override
    public Test.Func_test_gt vx_copy(final Object... vals) {
      Class_test_gt output = new Class_test_gt();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "test-gt", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
    public Func_test_gt vx_empty() {return e_test_gt;}
    @Override
    public Func_test_gt vx_type() {return t_test_gt;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any expected = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any actual = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Test.f_test_gt(context, expected, actual);
      return output;
    }

    @Override
    public Test.Type_testresult vx_test_gt(final Core.Type_context context, final Core.Type_any expected, final Core.Type_any actual) {
      return Test.f_test_gt(context, expected, actual);
    }

  }

  public static final Func_test_gt e_test_gt = new Test.Class_test_gt();
  public static final Func_test_gt t_test_gt = new Test.Class_test_gt();

  public static Test.Type_testresult f_test_gt(final Core.Type_context context, final Core.Type_any expected, final Core.Type_any actual) {
    Test.Type_testresult output = Test.e_testresult;
    try {
      output = Core.f_new(
        Test.t_testresult,
        Core.t_anylist.vx_new(
          Core.vx_new_string(":code"),
          Core.vx_new_string(":gt"),
          Core.vx_new_string(":passfail"),
          Core.f_gt(expected, actual),
          Core.vx_new_string(":expected"),
          expected,
          Core.vx_new_string(":actual"),
          actual
        )
      );
    } catch (Exception err) {
      Core.Type_msg msg = Core.vx_msg_from_exception("vx/test/test-gt", err);
      output = output.vx_copy(msg);
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
  public interface Func_test_gt_1 extends Core.Type_func, Core.Type_replfunc {
    public Test.Type_testresult vx_test_gt_1(final Core.Type_context context, final Core.Type_any expected, final Core.Func_any_from_func_async fn_actual);
  }

  public static class Class_test_gt_1 extends Core.Class_base implements Func_test_gt_1 {

    @Override
    public Test.Func_test_gt_1 vx_new(final Object... vals) {
      Class_test_gt_1 output = new Class_test_gt_1();
      return output;
    }

    @Override
    public Test.Func_test_gt_1 vx_copy(final Object... vals) {
      Class_test_gt_1 output = new Class_test_gt_1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "test-gt", // name
        1, // idx
        false, // async
        Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
    public Func_test_gt_1 vx_empty() {return e_test_gt_1;}
    @Override
    public Func_test_gt_1 vx_type() {return t_test_gt_1;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any expected = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_any_from_func_async fn_actual = Core.f_any_from_any(Core.t_any_from_func_async, arglist.vx_any(Core.vx_new_int(1)));
      output = Test.f_test_gt_1(context, expected, fn_actual);
      return output;
    }

    @Override
    public Test.Type_testresult vx_test_gt_1(final Core.Type_context context, final Core.Type_any expected, final Core.Func_any_from_func_async fn_actual) {
      return Test.f_test_gt_1(context, expected, fn_actual);
    }

  }

  public static final Func_test_gt_1 e_test_gt_1 = new Test.Class_test_gt_1();
  public static final Func_test_gt_1 t_test_gt_1 = new Test.Class_test_gt_1();

  public static Test.Type_testresult f_test_gt_1(final Core.Type_context context, final Core.Type_any expected, final Core.Func_any_from_func_async fn_actual) {
    Test.Type_testresult output = Test.e_testresult;
    try {
      output = Core.f_new(
        Test.t_testresult,
        Core.t_anylist.vx_new(
          Core.vx_new_string(":code"),
          Core.vx_new_string(":gt"),
          Core.vx_new_string(":expected"),
          expected,
          Core.vx_new_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (Exception err) {
      Core.Type_msg msg = Core.vx_msg_from_exception("vx/test/test-gt", err);
      output = output.vx_copy(msg);
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
  public interface Func_test_ne extends Core.Type_func, Core.Type_replfunc {
    public Test.Type_testresult vx_test_ne(final Core.Type_context context, final Core.Type_any expected, final Core.Type_any actual);
  }

  public static class Class_test_ne extends Core.Class_base implements Func_test_ne {

    @Override
    public Test.Func_test_ne vx_new(final Object... vals) {
      Class_test_ne output = new Class_test_ne();
      return output;
    }

    @Override
    public Test.Func_test_ne vx_copy(final Object... vals) {
      Class_test_ne output = new Class_test_ne();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "test-ne", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
    public Func_test_ne vx_empty() {return e_test_ne;}
    @Override
    public Func_test_ne vx_type() {return t_test_ne;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any expected = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any actual = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Test.f_test_ne(context, expected, actual);
      return output;
    }

    @Override
    public Test.Type_testresult vx_test_ne(final Core.Type_context context, final Core.Type_any expected, final Core.Type_any actual) {
      return Test.f_test_ne(context, expected, actual);
    }

  }

  public static final Func_test_ne e_test_ne = new Test.Class_test_ne();
  public static final Func_test_ne t_test_ne = new Test.Class_test_ne();

  public static Test.Type_testresult f_test_ne(final Core.Type_context context, final Core.Type_any expected, final Core.Type_any actual) {
    Test.Type_testresult output = Test.e_testresult;
    try {
      output = Core.f_new(
        Test.t_testresult,
        Core.t_anylist.vx_new(
          Core.vx_new_string(":code"),
          Core.vx_new_string(":ne"),
          Core.vx_new_string(":passfail"),
          Core.f_ne(expected, actual),
          Core.vx_new_string(":expected"),
          expected,
          Core.vx_new_string(":actual"),
          actual
        )
      );
    } catch (Exception err) {
      Core.Type_msg msg = Core.vx_msg_from_exception("vx/test/test-ne", err);
      output = output.vx_copy(msg);
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
  public interface Func_test_ne_1 extends Core.Type_func, Core.Type_replfunc {
    public Test.Type_testresult vx_test_ne_1(final Core.Type_context context, final Core.Type_any expected, final Core.Func_any_from_func_async fn_actual);
  }

  public static class Class_test_ne_1 extends Core.Class_base implements Func_test_ne_1 {

    @Override
    public Test.Func_test_ne_1 vx_new(final Object... vals) {
      Class_test_ne_1 output = new Class_test_ne_1();
      return output;
    }

    @Override
    public Test.Func_test_ne_1 vx_copy(final Object... vals) {
      Class_test_ne_1 output = new Class_test_ne_1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "test-ne", // name
        1, // idx
        false, // async
        Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
    public Func_test_ne_1 vx_empty() {return e_test_ne_1;}
    @Override
    public Func_test_ne_1 vx_type() {return t_test_ne_1;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any expected = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_any_from_func_async fn_actual = Core.f_any_from_any(Core.t_any_from_func_async, arglist.vx_any(Core.vx_new_int(1)));
      output = Test.f_test_ne_1(context, expected, fn_actual);
      return output;
    }

    @Override
    public Test.Type_testresult vx_test_ne_1(final Core.Type_context context, final Core.Type_any expected, final Core.Func_any_from_func_async fn_actual) {
      return Test.f_test_ne_1(context, expected, fn_actual);
    }

  }

  public static final Func_test_ne_1 e_test_ne_1 = new Test.Class_test_ne_1();
  public static final Func_test_ne_1 t_test_ne_1 = new Test.Class_test_ne_1();

  public static Test.Type_testresult f_test_ne_1(final Core.Type_context context, final Core.Type_any expected, final Core.Func_any_from_func_async fn_actual) {
    Test.Type_testresult output = Test.e_testresult;
    try {
      output = Core.f_new(
        Test.t_testresult,
        Core.t_anylist.vx_new(
          Core.vx_new_string(":code"),
          Core.vx_new_string(":ne"),
          Core.vx_new_string(":expected"),
          expected,
          Core.vx_new_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (Exception err) {
      Core.Type_msg msg = Core.vx_msg_from_exception("vx/test/test-ne", err);
      output = output.vx_copy(msg);
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
  public interface Func_test_string extends Core.Type_func, Core.Type_replfunc {
    public Test.Type_testresult vx_test_string(final Core.Type_context context, final Core.Type_any expected, final Core.Type_any actual);
  }

  public static class Class_test_string extends Core.Class_base implements Func_test_string {

    @Override
    public Test.Func_test_string vx_new(final Object... vals) {
      Class_test_string output = new Class_test_string();
      return output;
    }

    @Override
    public Test.Func_test_string vx_copy(final Object... vals) {
      Class_test_string output = new Class_test_string();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "test-string", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
    public Func_test_string vx_empty() {return e_test_string;}
    @Override
    public Func_test_string vx_type() {return t_test_string;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any expected = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any actual = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(1)));
      output = Test.f_test_string(context, expected, actual);
      return output;
    }

    @Override
    public Test.Type_testresult vx_test_string(final Core.Type_context context, final Core.Type_any expected, final Core.Type_any actual) {
      return Test.f_test_string(context, expected, actual);
    }

  }

  public static final Func_test_string e_test_string = new Test.Class_test_string();
  public static final Func_test_string t_test_string = new Test.Class_test_string();

  public static Test.Type_testresult f_test_string(final Core.Type_context context, final Core.Type_any expected, final Core.Type_any actual) {
    Test.Type_testresult output = Test.e_testresult;
    try {
      output = Core.f_new(
        Test.t_testresult,
        Core.t_anylist.vx_new(
          Core.vx_new_string(":passfail"),
          Core.f_eq(
            Core.f_string_from_any(expected),
            Core.f_string_from_any(actual)
          ),
          Core.vx_new_string(":expected"),
          expected,
          Core.vx_new_string(":actual"),
          actual
        )
      );
    } catch (Exception err) {
      Core.Type_msg msg = Core.vx_msg_from_exception("vx/test/test-string", err);
      output = output.vx_copy(msg);
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
  public interface Func_test_string_1 extends Core.Type_func, Core.Type_replfunc {
    public Test.Type_testresult vx_test_string_1(final Core.Type_context context, final Core.Type_any expected, final Core.Func_any_from_func_async fn_actual);
  }

  public static class Class_test_string_1 extends Core.Class_base implements Func_test_string_1 {

    @Override
    public Test.Func_test_string_1 vx_new(final Object... vals) {
      Class_test_string_1 output = new Class_test_string_1();
      return output;
    }

    @Override
    public Test.Func_test_string_1 vx_copy(final Object... vals) {
      Class_test_string_1 output = new Class_test_string_1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "test-string", // name
        1, // idx
        false, // async
        Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
    public Func_test_string_1 vx_empty() {return e_test_string_1;}
    @Override
    public Func_test_string_1 vx_type() {return t_test_string_1;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any expected = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_any_from_func_async fn_actual = Core.f_any_from_any(Core.t_any_from_func_async, arglist.vx_any(Core.vx_new_int(1)));
      output = Test.f_test_string_1(context, expected, fn_actual);
      return output;
    }

    @Override
    public Test.Type_testresult vx_test_string_1(final Core.Type_context context, final Core.Type_any expected, final Core.Func_any_from_func_async fn_actual) {
      return Test.f_test_string_1(context, expected, fn_actual);
    }

  }

  public static final Func_test_string_1 e_test_string_1 = new Test.Class_test_string_1();
  public static final Func_test_string_1 t_test_string_1 = new Test.Class_test_string_1();

  public static Test.Type_testresult f_test_string_1(final Core.Type_context context, final Core.Type_any expected, final Core.Func_any_from_func_async fn_actual) {
    Test.Type_testresult output = Test.e_testresult;
    try {
      output = Core.f_new(
        Test.t_testresult,
        Core.t_anylist.vx_new(
          Core.vx_new_string(":code"),
          Core.vx_new_string(":string"),
          Core.vx_new_string(":expected"),
          expected,
          Core.vx_new_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (Exception err) {
      Core.Type_msg msg = Core.vx_msg_from_exception("vx/test/test-string", err);
      output = output.vx_copy(msg);
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
  public interface Func_test_true extends Core.Func_any_from_any_context {
    public Test.Type_testresult vx_test_true(final Core.Type_context context, final Core.Type_any actual);
  }

  public static class Class_test_true extends Core.Class_base implements Func_test_true {

    @Override
    public Test.Func_test_true vx_new(final Object... vals) {
      Class_test_true output = new Class_test_true();
      return output;
    }

    @Override
    public Test.Func_test_true vx_copy(final Object... vals) {
      Class_test_true output = new Class_test_true();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "test-true", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
    public Func_test_true vx_empty() {return e_test_true;}
    @Override
    public Func_test_true vx_type() {return t_test_true;}

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Test.f_test_true(context, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_any actual = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.vx_new_int(0)));
      output = Test.f_test_true(context, actual);
      return output;
    }

    @Override
    public Test.Type_testresult vx_test_true(final Core.Type_context context, final Core.Type_any actual) {
      return Test.f_test_true(context, actual);
    }

  }

  public static final Func_test_true e_test_true = new Test.Class_test_true();
  public static final Func_test_true t_test_true = new Test.Class_test_true();

  public static Test.Type_testresult f_test_true(final Core.Type_context context, final Core.Type_any actual) {
    Test.Type_testresult output = Test.e_testresult;
    try {
      output = Core.f_new(
        Test.t_testresult,
        Core.t_anylist.vx_new(
          Core.vx_new_string(":code"),
          Core.vx_new_string(":true"),
          Core.vx_new_string(":passfail"),
          Core.f_eq(
            Core.vx_new_boolean(true),
            actual
          ),
          Core.vx_new_string(":expected"),
          Core.vx_new_boolean(true),
          Core.vx_new_string(":actual"),
          actual
        )
      );
    } catch (Exception err) {
      Core.Type_msg msg = Core.vx_msg_from_exception("vx/test/test-true", err);
      output = output.vx_copy(msg);
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
  public interface Func_test_true_1 extends Core.Func_any_from_any_context {
    public Test.Type_testresult vx_test_true_1(final Core.Type_context context, final Core.Func_any_from_func_async fn_actual);
  }

  public static class Class_test_true_1 extends Core.Class_base implements Func_test_true_1 {

    @Override
    public Test.Func_test_true_1 vx_new(final Object... vals) {
      Class_test_true_1 output = new Class_test_true_1();
      return output;
    }

    @Override
    public Test.Func_test_true_1 vx_copy(final Object... vals) {
      Class_test_true_1 output = new Class_test_true_1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "test-true", // name
        1, // idx
        false, // async
        Core.typedef_new(
          "vx/test", // pkgname
          "testresult", // name
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
    public Func_test_true_1 vx_empty() {return e_test_true_1;}
    @Override
    public Func_test_true_1 vx_type() {return t_test_true_1;}

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Func_any_from_func_async inputval = (Core.Func_any_from_func_async)value;
      Core.Type_any outputval = Test.f_test_true_1(context, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Func_any_from_func_async fn_actual = Core.f_any_from_any(Core.t_any_from_func_async, arglist.vx_any(Core.vx_new_int(0)));
      output = Test.f_test_true_1(context, fn_actual);
      return output;
    }

    @Override
    public Test.Type_testresult vx_test_true_1(final Core.Type_context context, final Core.Func_any_from_func_async fn_actual) {
      return Test.f_test_true_1(context, fn_actual);
    }

  }

  public static final Func_test_true_1 e_test_true_1 = new Test.Class_test_true_1();
  public static final Func_test_true_1 t_test_true_1 = new Test.Class_test_true_1();

  public static Test.Type_testresult f_test_true_1(final Core.Type_context context, final Core.Func_any_from_func_async fn_actual) {
    Test.Type_testresult output = Test.e_testresult;
    try {
      output = Core.f_new(
        Test.t_testresult,
        Core.t_anylist.vx_new(
          Core.vx_new_string(":code"),
          Core.vx_new_string(":true"),
          Core.vx_new_string(":expected"),
          Core.vx_new_boolean(true),
          Core.vx_new_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (Exception err) {
      Core.Type_msg msg = Core.vx_msg_from_exception("vx/test/test-true", err);
      output = output.vx_copy(msg);
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
  public interface Func_tr_from_testdescribe_casename extends Core.Type_func, Core.Type_replfunc {
    public Html.Type_tr vx_tr_from_testdescribe_casename(final Test.Type_testdescribe testdescribe, final Core.Type_string casename);
  }

  public static class Class_tr_from_testdescribe_casename extends Core.Class_base implements Func_tr_from_testdescribe_casename {

    @Override
    public Test.Func_tr_from_testdescribe_casename vx_new(final Object... vals) {
      Class_tr_from_testdescribe_casename output = new Class_tr_from_testdescribe_casename();
      return output;
    }

    @Override
    public Test.Func_tr_from_testdescribe_casename vx_copy(final Object... vals) {
      Class_tr_from_testdescribe_casename output = new Class_tr_from_testdescribe_casename();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "tr<-testdescribe-casename", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/web/html", // pkgname
          "tr", // name
          ":struct", // extends
          Core.t_typelist.vx_new(Html.t_node), // traits
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
    public Func_tr_from_testdescribe_casename vx_empty() {return e_tr_from_testdescribe_casename;}
    @Override
    public Func_tr_from_testdescribe_casename vx_type() {return t_tr_from_testdescribe_casename;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Test.Type_testdescribe testdescribe = Core.f_any_from_any(Test.t_testdescribe, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string casename = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Test.f_tr_from_testdescribe_casename(testdescribe, casename);
      return output;
    }

    @Override
    public Html.Type_tr vx_tr_from_testdescribe_casename(final Test.Type_testdescribe testdescribe, final Core.Type_string casename) {
      return Test.f_tr_from_testdescribe_casename(testdescribe, casename);
    }

  }

  public static final Func_tr_from_testdescribe_casename e_tr_from_testdescribe_casename = new Test.Class_tr_from_testdescribe_casename();
  public static final Func_tr_from_testdescribe_casename t_tr_from_testdescribe_casename = new Test.Class_tr_from_testdescribe_casename();

  public static Html.Type_tr f_tr_from_testdescribe_casename(final Test.Type_testdescribe testdescribe, final Core.Type_string casename) {
    Html.Type_tr output = Html.e_tr;
    output = Core.f_let(
      Html.t_tr,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string describename = testdescribe.describename();
        final Test.Type_testresult result = testdescribe.testresult();
        final Core.Type_boolean passfail = result.passfail();
        final Core.Type_string expected = Core.f_string_from_any(
          result.expected()
        );
        final Core.Type_string actual = Core.f_string_from_any(
          result.actual()
        );
        final Html.Type_style prestyle = Html.f_style_from_stylesheet_name(
          Test.c_stylesheet_test,
          Core.vx_new_string(".preformatted")
        );
        return Core.f_new(
          Html.t_tr,
          Core.t_anylist.vx_new(
            Core.f_new(
              Html.t_td,
              Core.t_anylist.vx_new(
                Test.f_p_from_passfail(passfail)
              )
            ),
            Core.f_new(
              Html.t_td,
              Core.t_anylist.vx_new(
                Core.f_new(
                  Html.t_p,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":style"),
                    prestyle,
                    Core.vx_new_string(":text"),
                    casename
                  )
                )
              )
            ),
            Core.f_new(
              Html.t_td,
              Core.t_anylist.vx_new(
                Core.f_new(
                  Html.t_p,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":style"),
                    prestyle,
                    Core.vx_new_string(":text"),
                    describename
                  )
                )
              )
            ),
            Core.f_new(
              Html.t_td,
              Core.t_anylist.vx_new(
                Core.f_new(
                  Html.t_p,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":style"),
                    prestyle,
                    Core.vx_new_string(":text"),
                    expected
                  )
                )
              )
            ),
            Core.f_new(
              Html.t_td,
              Core.t_anylist.vx_new(
                Core.f_new(
                  Html.t_p,
                  Core.t_anylist.vx_new(
                    Core.vx_new_string(":style"),
                    prestyle,
                    Core.vx_new_string(":text"),
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
  public interface Func_trlist_from_testcase extends Core.Func_any_from_any {
    public Html.Type_trlist vx_trlist_from_testcase(final Test.Type_testcase testcase);
  }

  public static class Class_trlist_from_testcase extends Core.Class_base implements Func_trlist_from_testcase {

    @Override
    public Test.Func_trlist_from_testcase vx_new(final Object... vals) {
      Class_trlist_from_testcase output = new Class_trlist_from_testcase();
      return output;
    }

    @Override
    public Test.Func_trlist_from_testcase vx_copy(final Object... vals) {
      Class_trlist_from_testcase output = new Class_trlist_from_testcase();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "trlist<-testcase", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/web/html", // pkgname
          "trlist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Html.t_tr), // allowtypes
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
    public Func_trlist_from_testcase vx_empty() {return e_trlist_from_testcase;}
    @Override
    public Func_trlist_from_testcase vx_type() {return t_trlist_from_testcase;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Test.Type_testcase inputval = (Test.Type_testcase)value;
      Core.Type_any outputval = Test.f_trlist_from_testcase(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Test.Type_testcase testcase = Core.f_any_from_any(Test.t_testcase, arglist.vx_any(Core.vx_new_int(0)));
      output = Test.f_trlist_from_testcase(testcase);
      return output;
    }

    @Override
    public Html.Type_trlist vx_trlist_from_testcase(final Test.Type_testcase testcase) {
      return Test.f_trlist_from_testcase(testcase);
    }

  }

  public static final Func_trlist_from_testcase e_trlist_from_testcase = new Test.Class_trlist_from_testcase();
  public static final Func_trlist_from_testcase t_trlist_from_testcase = new Test.Class_trlist_from_testcase();

  public static Html.Type_trlist f_trlist_from_testcase(final Test.Type_testcase testcase) {
    Html.Type_trlist output = Html.e_trlist;
    output = Core.f_let(
      Html.t_trlist,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Test.Type_testdescribelist describelist = testcase.describelist();
        final Core.Type_string casename = testcase.casename();
        return Core.f_list_from_list_1(
          Html.t_trlist,
          describelist,
          Core.t_any_from_any.vx_fn_new((testdescribe_any) -> {
            Test.Type_testdescribe testdescribe = Core.f_any_from_any(Test.t_testdescribe, testdescribe_any);
            return 
            Test.f_tr_from_testdescribe_casename(testdescribe, casename);
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
  public interface Func_trlist_from_testcaselist extends Core.Func_any_from_any {
    public Html.Type_trlist vx_trlist_from_testcaselist(final Test.Type_testcaselist testcaselist);
  }

  public static class Class_trlist_from_testcaselist extends Core.Class_base implements Func_trlist_from_testcaselist {

    @Override
    public Test.Func_trlist_from_testcaselist vx_new(final Object... vals) {
      Class_trlist_from_testcaselist output = new Class_trlist_from_testcaselist();
      return output;
    }

    @Override
    public Test.Func_trlist_from_testcaselist vx_copy(final Object... vals) {
      Class_trlist_from_testcaselist output = new Class_trlist_from_testcaselist();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/test", // pkgname
        "trlist<-testcaselist", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/web/html", // pkgname
          "trlist", // name
          ":list", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Html.t_tr), // allowtypes
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
    public Func_trlist_from_testcaselist vx_empty() {return e_trlist_from_testcaselist;}
    @Override
    public Func_trlist_from_testcaselist vx_type() {return t_trlist_from_testcaselist;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Test.Type_testcaselist inputval = (Test.Type_testcaselist)value;
      Core.Type_any outputval = Test.f_trlist_from_testcaselist(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Test.Type_testcaselist testcaselist = Core.f_any_from_any(Test.t_testcaselist, arglist.vx_any(Core.vx_new_int(0)));
      output = Test.f_trlist_from_testcaselist(testcaselist);
      return output;
    }

    @Override
    public Html.Type_trlist vx_trlist_from_testcaselist(final Test.Type_testcaselist testcaselist) {
      return Test.f_trlist_from_testcaselist(testcaselist);
    }

  }

  public static final Func_trlist_from_testcaselist e_trlist_from_testcaselist = new Test.Class_trlist_from_testcaselist();
  public static final Func_trlist_from_testcaselist t_trlist_from_testcaselist = new Test.Class_trlist_from_testcaselist();

  public static Html.Type_trlist f_trlist_from_testcaselist(final Test.Type_testcaselist testcaselist) {
    Html.Type_trlist output = Html.e_trlist;
    output = Core.f_list_join_from_list_1(
      Html.t_trlist,
      testcaselist,
      Test.t_trlist_from_testcase
    );
    return output;
  }


  static {
    Const_stylesheet_test.const_new(c_stylesheet_test);
    Map<String, Core.Type_any> maptype = new LinkedHashMap<>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<>();
    maptype.put("testcase", Test.t_testcase);
    maptype.put("testcaselist", Test.t_testcaselist);
    maptype.put("testcoveragedetail", Test.t_testcoveragedetail);
    maptype.put("testcoveragenums", Test.t_testcoveragenums);
    maptype.put("testcoveragesummary", Test.t_testcoveragesummary);
    maptype.put("testdescribe", Test.t_testdescribe);
    maptype.put("testdescribelist", Test.t_testdescribelist);
    maptype.put("testpackage", Test.t_testpackage);
    maptype.put("testpackagelist", Test.t_testpackagelist);
    maptype.put("testresult", Test.t_testresult);
    maptype.put("testresultlist", Test.t_testresultlist);
    mapconst.put("stylesheet-test", Test.c_stylesheet_test);
    mapfunc.put("context-test", Test.t_context_test);
    mapfunc.put("div<-testcaselist", Test.t_div_from_testcaselist);
    mapfunc.put("div<-testpackage", Test.t_div_from_testpackage);
    mapfunc.put("div<-testpackagelist", Test.t_div_from_testpackagelist);
    mapfunc.put("divchildlist<-testpackagelist", Test.t_divchildlist_from_testpackagelist);
    mapfunc.put("file-test", Test.t_file_test);
    mapfunc.put("file-testhtml", Test.t_file_testhtml);
    mapfunc.put("file-testnode", Test.t_file_testnode);
    mapfunc.put("html<-divtest", Test.t_html_from_divtest);
    mapfunc.put("p<-passfail", Test.t_p_from_passfail);
    mapfunc.put("p<-testcoveragenums", Test.t_p_from_testcoveragenums);
    mapfunc.put("resolve-testcase", Test.t_resolve_testcase);
    mapfunc.put("resolve-testcaselist", Test.t_resolve_testcaselist);
    mapfunc.put("resolve-testdescribe", Test.t_resolve_testdescribe);
    mapfunc.put("resolve-testdescribelist", Test.t_resolve_testdescribelist);
    mapfunc.put("resolve-testpackage", Test.t_resolve_testpackage);
    mapfunc.put("resolve-testpackagelist", Test.t_resolve_testpackagelist);
    mapfunc.put("resolve-testresult", Test.t_resolve_testresult);
    mapfunc.put("security-test", Test.t_security_test);
    mapfunc.put("test", Test.t_test);
    mapfunc.put("test_1", Test.t_test_1);
    mapfunc.put("test-false", Test.t_test_false);
    mapfunc.put("test-false_1", Test.t_test_false_1);
    mapfunc.put("test-gt", Test.t_test_gt);
    mapfunc.put("test-gt_1", Test.t_test_gt_1);
    mapfunc.put("test-ne", Test.t_test_ne);
    mapfunc.put("test-ne_1", Test.t_test_ne_1);
    mapfunc.put("test-string", Test.t_test_string);
    mapfunc.put("test-string_1", Test.t_test_string_1);
    mapfunc.put("test-true", Test.t_test_true);
    mapfunc.put("test-true_1", Test.t_test_true_1);
    mapfunc.put("tr<-testdescribe-casename", Test.t_tr_from_testdescribe_casename);
    mapfunc.put("trlist<-testcase", Test.t_trlist_from_testcase);
    mapfunc.put("trlist<-testcaselist", Test.t_trlist_from_testcaselist);
    Core.vx_global_package_set("vx/test", maptype, mapconst, mapfunc);
  }

}
