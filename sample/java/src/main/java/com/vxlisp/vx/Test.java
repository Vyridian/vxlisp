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
    public Type_testcase vx_new(final Object... vals) {return e_testcase.vx_copy(vals);}

    @Override
    public Type_testcase vx_copy(final Object... vals) {
      Class_testcase output = new Class_testcase();
      Type_testcase val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_passfail = val.passfail();
      output.vx_p_testpkg = val.testpkg();
      output.vx_p_casename = val.casename();
      output.vx_p_describelist = val.describelist();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":passfail");
      validkeys.add(":testpkg");
      validkeys.add(":casename");
      validkeys.add(":describelist");
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcase) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":passfail":
            if (valsub instanceof Core.Type_boolean) {
              output.vx_p_passfail = (Core.Type_boolean)valsub;
            } else if (valsub instanceof Boolean) {
              output.vx_p_passfail = Core.t_boolean.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcase :passfail " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":testpkg":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_testpkg = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_testpkg = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcase :testpkg " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":casename":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_casename = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_casename = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcase :casename " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":describelist":
            if (valsub instanceof Test.Type_testdescribelist) {
              output.vx_p_describelist = (Test.Type_testdescribelist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcase :describelist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcase) - Invalid Key: " + key);
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

    protected List<Test.Type_testcase> vxlist = Core.immutablelist(new ArrayList<Test.Type_testcase>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Test.Type_testcase vx_testcase(final Core.Type_int index) {
      Test.Type_testcase output = Test.e_testcase;
      Class_testcaselist list = this;
      int iindex = index.vx_int();
      List<Test.Type_testcase> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Test.Type_testcase> vx_listtestcase() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_testcase(index);
    }

    @Override
    public Type_testcaselist vx_new(final Object... vals) {return e_testcaselist.vx_copy(vals);}

    @Override
    public Type_testcaselist vx_copy(final Object... vals) {
      Class_testcaselist output = new Class_testcaselist();
      Type_testcaselist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Test.Type_testcase> listval = new ArrayList<>(val.vx_listtestcase());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Test.Type_testcase) {
          listval.add((Test.Type_testcase)valsub);
        } else if (valsub instanceof Test.Type_testcase) {
          listval.add((Test.Type_testcase)valsub);
        } else if (valsub instanceof Type_testcaselist) {
          Type_testcaselist multi = (Type_testcaselist)valsub;
          listval.addAll(multi.vx_listtestcase());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Test.Type_testcase) {
              Test.Type_testcase valitem = (Test.Type_testcase)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcaselist) - Invalid Type: " + valsub.toString());
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
    public Type_testcoveragedetail vx_new(final Object... vals) {return e_testcoveragedetail.vx_copy(vals);}

    @Override
    public Type_testcoveragedetail vx_copy(final Object... vals) {
      Class_testcoveragedetail output = new Class_testcoveragedetail();
      Type_testcoveragedetail val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_constmap = val.constmap();
      output.vx_p_funcmap = val.funcmap();
      output.vx_p_testpkg = val.testpkg();
      output.vx_p_typemap = val.typemap();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":constmap");
      validkeys.add(":funcmap");
      validkeys.add(":testpkg");
      validkeys.add(":typemap");
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcoveragedetail) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":constmap":
            if (valsub instanceof Core.Type_intmap) {
              output.vx_p_constmap = (Core.Type_intmap)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcoveragedetail :constmap " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":funcmap":
            if (valsub instanceof Core.Type_intmap) {
              output.vx_p_funcmap = (Core.Type_intmap)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcoveragedetail :funcmap " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":testpkg":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_testpkg = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_testpkg = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcoveragedetail :testpkg " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":typemap":
            if (valsub instanceof Core.Type_intmap) {
              output.vx_p_typemap = (Core.Type_intmap)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcoveragedetail :typemap " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcoveragedetail) - Invalid Key: " + key);
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
    public Type_testcoveragenums vx_new(final Object... vals) {return e_testcoveragenums.vx_copy(vals);}

    @Override
    public Type_testcoveragenums vx_copy(final Object... vals) {
      Class_testcoveragenums output = new Class_testcoveragenums();
      Type_testcoveragenums val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_pct = val.pct();
      output.vx_p_testpkg = val.testpkg();
      output.vx_p_tests = val.tests();
      output.vx_p_total = val.total();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":pct");
      validkeys.add(":testpkg");
      validkeys.add(":tests");
      validkeys.add(":total");
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcoveragenums) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":pct":
            if (valsub instanceof Core.Type_int) {
              output.vx_p_pct = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              output.vx_p_pct = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcoveragenums :pct " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":testpkg":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_testpkg = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_testpkg = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcoveragenums :testpkg " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":tests":
            if (valsub instanceof Core.Type_int) {
              output.vx_p_tests = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              output.vx_p_tests = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcoveragenums :tests " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":total":
            if (valsub instanceof Core.Type_int) {
              output.vx_p_total = (Core.Type_int)valsub;
            } else if (valsub instanceof Integer) {
              output.vx_p_total = Core.t_int.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcoveragenums :total " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcoveragenums) - Invalid Key: " + key);
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
    public Type_testcoveragesummary vx_new(final Object... vals) {return e_testcoveragesummary.vx_copy(vals);}

    @Override
    public Type_testcoveragesummary vx_copy(final Object... vals) {
      Class_testcoveragesummary output = new Class_testcoveragesummary();
      Type_testcoveragesummary val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_bigospacenums = val.bigospacenums();
      output.vx_p_bigotimenums = val.bigotimenums();
      output.vx_p_constnums = val.constnums();
      output.vx_p_docnums = val.docnums();
      output.vx_p_funcnums = val.funcnums();
      output.vx_p_testpkg = val.testpkg();
      output.vx_p_totalnums = val.totalnums();
      output.vx_p_typenums = val.typenums();
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcoveragesummary) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":bigospacenums":
            if (valsub instanceof Test.Type_testcoveragenums) {
              output.vx_p_bigospacenums = (Test.Type_testcoveragenums)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcoveragesummary :bigospacenums " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":bigotimenums":
            if (valsub instanceof Test.Type_testcoveragenums) {
              output.vx_p_bigotimenums = (Test.Type_testcoveragenums)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcoveragesummary :bigotimenums " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":constnums":
            if (valsub instanceof Test.Type_testcoveragenums) {
              output.vx_p_constnums = (Test.Type_testcoveragenums)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcoveragesummary :constnums " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":docnums":
            if (valsub instanceof Test.Type_testcoveragenums) {
              output.vx_p_docnums = (Test.Type_testcoveragenums)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcoveragesummary :docnums " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":funcnums":
            if (valsub instanceof Test.Type_testcoveragenums) {
              output.vx_p_funcnums = (Test.Type_testcoveragenums)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcoveragesummary :funcnums " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":testpkg":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_testpkg = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_testpkg = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcoveragesummary :testpkg " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":totalnums":
            if (valsub instanceof Test.Type_testcoveragenums) {
              output.vx_p_totalnums = (Test.Type_testcoveragenums)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcoveragesummary :totalnums " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":typenums":
            if (valsub instanceof Test.Type_testcoveragenums) {
              output.vx_p_typenums = (Test.Type_testcoveragenums)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcoveragesummary :typenums " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new testcoveragesummary) - Invalid Key: " + key);
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
    public Type_testdescribe vx_new(final Object... vals) {return e_testdescribe.vx_copy(vals);}

    @Override
    public Type_testdescribe vx_copy(final Object... vals) {
      Class_testdescribe output = new Class_testdescribe();
      Type_testdescribe val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_describename = val.describename();
      output.vx_p_testpkg = val.testpkg();
      output.vx_p_testresult = val.testresult();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":describename");
      validkeys.add(":testpkg");
      validkeys.add(":testresult");
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new testdescribe) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":describename":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_describename = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_describename = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testdescribe :describename " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":testpkg":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_testpkg = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_testpkg = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testdescribe :testpkg " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":testresult":
            if (valsub instanceof Test.Type_testresult) {
              output.vx_p_testresult = (Test.Type_testresult)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testdescribe :testresult " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new testdescribe) - Invalid Key: " + key);
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

    protected List<Test.Type_testdescribe> vxlist = Core.immutablelist(new ArrayList<Test.Type_testdescribe>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Test.Type_testdescribe vx_testdescribe(final Core.Type_int index) {
      Test.Type_testdescribe output = Test.e_testdescribe;
      Class_testdescribelist list = this;
      int iindex = index.vx_int();
      List<Test.Type_testdescribe> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Test.Type_testdescribe> vx_listtestdescribe() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_testdescribe(index);
    }

    @Override
    public Type_testdescribelist vx_new(final Object... vals) {return e_testdescribelist.vx_copy(vals);}

    @Override
    public Type_testdescribelist vx_copy(final Object... vals) {
      Class_testdescribelist output = new Class_testdescribelist();
      Type_testdescribelist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Test.Type_testdescribe> listval = new ArrayList<>(val.vx_listtestdescribe());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Test.Type_testdescribe) {
          listval.add((Test.Type_testdescribe)valsub);
        } else if (valsub instanceof Test.Type_testdescribe) {
          listval.add((Test.Type_testdescribe)valsub);
        } else if (valsub instanceof Type_testdescribelist) {
          Type_testdescribelist multi = (Type_testdescribelist)valsub;
          listval.addAll(multi.vx_listtestdescribe());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Test.Type_testdescribe) {
              Test.Type_testdescribe valitem = (Test.Type_testdescribe)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new testdescribelist) - Invalid Type: " + valsub.toString());
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
    public Type_testpackage vx_new(final Object... vals) {return e_testpackage.vx_copy(vals);}

    @Override
    public Type_testpackage vx_copy(final Object... vals) {
      Class_testpackage output = new Class_testpackage();
      Type_testpackage val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_caselist = val.caselist();
      output.vx_p_coveragedetail = val.coveragedetail();
      output.vx_p_coveragesummary = val.coveragesummary();
      output.vx_p_passfail = val.passfail();
      output.vx_p_testpkg = val.testpkg();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":caselist");
      validkeys.add(":coveragedetail");
      validkeys.add(":coveragesummary");
      validkeys.add(":passfail");
      validkeys.add(":testpkg");
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new testpackage) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":caselist":
            if (valsub instanceof Test.Type_testcaselist) {
              output.vx_p_caselist = (Test.Type_testcaselist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testpackage :caselist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":coveragedetail":
            if (valsub instanceof Test.Type_testcoveragedetail) {
              output.vx_p_coveragedetail = (Test.Type_testcoveragedetail)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testpackage :coveragedetail " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":coveragesummary":
            if (valsub instanceof Test.Type_testcoveragesummary) {
              output.vx_p_coveragesummary = (Test.Type_testcoveragesummary)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testpackage :coveragesummary " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":passfail":
            if (valsub instanceof Core.Type_boolean) {
              output.vx_p_passfail = (Core.Type_boolean)valsub;
            } else if (valsub instanceof Boolean) {
              output.vx_p_passfail = Core.t_boolean.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testpackage :passfail " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":testpkg":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_testpkg = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_testpkg = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testpackage :testpkg " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new testpackage) - Invalid Key: " + key);
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

    protected List<Test.Type_testpackage> vxlist = Core.immutablelist(new ArrayList<Test.Type_testpackage>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Test.Type_testpackage vx_testpackage(final Core.Type_int index) {
      Test.Type_testpackage output = Test.e_testpackage;
      Class_testpackagelist list = this;
      int iindex = index.vx_int();
      List<Test.Type_testpackage> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Test.Type_testpackage> vx_listtestpackage() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_testpackage(index);
    }

    @Override
    public Type_testpackagelist vx_new(final Object... vals) {return e_testpackagelist.vx_copy(vals);}

    @Override
    public Type_testpackagelist vx_copy(final Object... vals) {
      Class_testpackagelist output = new Class_testpackagelist();
      Type_testpackagelist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Test.Type_testpackage> listval = new ArrayList<>(val.vx_listtestpackage());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Test.Type_testpackage) {
          listval.add((Test.Type_testpackage)valsub);
        } else if (valsub instanceof Test.Type_testpackage) {
          listval.add((Test.Type_testpackage)valsub);
        } else if (valsub instanceof Type_testpackagelist) {
          Type_testpackagelist multi = (Type_testpackagelist)valsub;
          listval.addAll(multi.vx_listtestpackage());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Test.Type_testpackage) {
              Test.Type_testpackage valitem = (Test.Type_testpackage)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new testpackagelist) - Invalid Type: " + valsub.toString());
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
    public Type_testresult vx_new(final Object... vals) {return e_testresult.vx_copy(vals);}

    @Override
    public Type_testresult vx_copy(final Object... vals) {
      Class_testresult output = new Class_testresult();
      Type_testresult val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_code = val.code();
      output.vx_p_passfail = val.passfail();
      output.vx_p_expected = val.expected();
      output.vx_p_actual = val.actual();
      output.vx_p_fn_actual = val.fn_actual();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":code");
      validkeys.add(":passfail");
      validkeys.add(":expected");
      validkeys.add(":actual");
      validkeys.add(":fn-actual");
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new testresult) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":code":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_code = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_code = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testresult :code " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":passfail":
            if (valsub instanceof Core.Type_boolean) {
              output.vx_p_passfail = (Core.Type_boolean)valsub;
            } else if (valsub instanceof Boolean) {
              output.vx_p_passfail = Core.t_boolean.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testresult :passfail " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":expected":
            if (valsub instanceof Core.Type_any) {
              output.vx_p_expected = (Core.Type_any)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testresult :expected " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":actual":
            if (valsub instanceof Core.Type_any) {
              output.vx_p_actual = (Core.Type_any)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testresult :actual " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":fn-actual":
            if (valsub instanceof Core.Func_any_from_func_async) {
              output.vx_p_fn_actual = (Core.Func_any_from_func_async)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new testresult :fn-actual " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new testresult) - Invalid Key: " + key);
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

    protected List<Test.Type_testresult> vxlist = Core.immutablelist(new ArrayList<Test.Type_testresult>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Test.Type_testresult vx_testresult(final Core.Type_int index) {
      Test.Type_testresult output = Test.e_testresult;
      Class_testresultlist list = this;
      int iindex = index.vx_int();
      List<Test.Type_testresult> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Test.Type_testresult> vx_listtestresult() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_testresult(index);
    }

    @Override
    public Type_testresultlist vx_new(final Object... vals) {return e_testresultlist.vx_copy(vals);}

    @Override
    public Type_testresultlist vx_copy(final Object... vals) {
      Class_testresultlist output = new Class_testresultlist();
      Type_testresultlist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Test.Type_testresult> listval = new ArrayList<>(val.vx_listtestresult());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Test.Type_testresult) {
          listval.add((Test.Type_testresult)valsub);
        } else if (valsub instanceof Test.Type_testresult) {
          listval.add((Test.Type_testresult)valsub);
        } else if (valsub instanceof Type_testresultlist) {
          Type_testresultlist multi = (Type_testresultlist)valsub;
          listval.addAll(multi.vx_listtestresult());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Test.Type_testresult) {
              Test.Type_testresult valitem = (Test.Type_testresult)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new testresultlist) - Invalid Type: " + valsub.toString());
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
  public static class Const_stylesheet_test extends Html.Class_stylesheet {

    public Core.Type_constdef constdef() {
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

    public static Const_stylesheet_test const_new() {
      Const_stylesheet_test output = new Const_stylesheet_test();
      Html.Type_stylesheet val = Html.f_stylesheet_loadmap(
        Core.f_new(
          Html.t_stylesheet,
          Core.t_anylist.vx_new(
            Core.t_string.vx_new_from_string(":name"),
            Core.t_string.vx_new_from_string("Test Suite"),
            Core.t_string.vx_new_from_string(":styles"),
            Core.f_new(
              Html.t_stylelist,
              Core.t_anylist.vx_new(
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":name"),
                    Core.t_string.vx_new_from_string("details summary"),
                    Core.t_string.vx_new_from_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.t_string.vx_new_from_string("cursor"),
                        Core.t_string.vx_new_from_string("pointer"),
                        Core.t_string.vx_new_from_string("display"),
                        Core.t_string.vx_new_from_string("inline-flex"),
                        Core.t_string.vx_new_from_string("gap"),
                        Core.t_string.vx_new_from_string("10px")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":name"),
                    Core.t_string.vx_new_from_string("table"),
                    Core.t_string.vx_new_from_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.t_string.vx_new_from_string("vertical-align"),
                        Core.t_string.vx_new_from_string("top"),
                        Core.t_string.vx_new_from_string("border-collapse"),
                        Core.t_string.vx_new_from_string("collapse"),
                        Core.t_string.vx_new_from_string("margin"),
                        Core.t_string.vx_new_from_string("25px 0"),
                        Core.t_string.vx_new_from_string("font-size"),
                        Core.t_string.vx_new_from_string("0.9em"),
                        Core.t_string.vx_new_from_string("font-family"),
                        Core.t_string.vx_new_from_string("sans-serif"),
                        Core.t_string.vx_new_from_string("min-width"),
                        Core.t_string.vx_new_from_string("400px"),
                        Core.t_string.vx_new_from_string("box-shadow"),
                        Core.t_string.vx_new_from_string("0 0 20px rgba(0, 0, 0, 0.15)")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":name"),
                    Core.t_string.vx_new_from_string("thead tr"),
                    Core.t_string.vx_new_from_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.t_string.vx_new_from_string("background-color"),
                        Core.t_string.vx_new_from_string("#009879"),
                        Core.t_string.vx_new_from_string("color"),
                        Core.t_string.vx_new_from_string("#ffffff"),
                        Core.t_string.vx_new_from_string("text-align"),
                        Core.t_string.vx_new_from_string("left")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":name"),
                    Core.t_string.vx_new_from_string("td"),
                    Core.t_string.vx_new_from_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.t_string.vx_new_from_string("padding"),
                        Core.t_string.vx_new_from_string("10px 10px"),
                        Core.t_string.vx_new_from_string("vertical-align"),
                        Core.t_string.vx_new_from_string("top")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":name"),
                    Core.t_string.vx_new_from_string("tbody tr"),
                    Core.t_string.vx_new_from_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.t_string.vx_new_from_string("border-bottom"),
                        Core.t_string.vx_new_from_string("1px solid #dddddd")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":name"),
                    Core.t_string.vx_new_from_string("tbody tr:nth-of-type(even)"),
                    Core.t_string.vx_new_from_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.t_string.vx_new_from_string("background-color"),
                        Core.t_string.vx_new_from_string("#f3f3f3")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":name"),
                    Core.t_string.vx_new_from_string("tbody tr:last-of-type"),
                    Core.t_string.vx_new_from_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.t_string.vx_new_from_string("border-bottom"),
                        Core.t_string.vx_new_from_string("2px solid #009879")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":name"),
                    Core.t_string.vx_new_from_string("tbody tr.active-row"),
                    Core.t_string.vx_new_from_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.t_string.vx_new_from_string("font-weight"),
                        Core.t_string.vx_new_from_string("bold"),
                        Core.t_string.vx_new_from_string("color"),
                        Core.t_string.vx_new_from_string("#009879")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":name"),
                    Core.t_string.vx_new_from_string(".failflag"),
                    Core.t_string.vx_new_from_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.t_string.vx_new_from_string("background-color"),
                        Core.t_string.vx_new_from_string("red"),
                        Core.t_string.vx_new_from_string("color"),
                        Core.t_string.vx_new_from_string("white"),
                        Core.t_string.vx_new_from_string("padding-left"),
                        Core.t_string.vx_new_from_string("4px"),
                        Core.t_string.vx_new_from_string("padding-right"),
                        Core.t_string.vx_new_from_string("4px"),
                        Core.t_string.vx_new_from_string("padding-top"),
                        Core.t_string.vx_new_from_string("1px"),
                        Core.t_string.vx_new_from_string("padding-bottom"),
                        Core.t_string.vx_new_from_string("1px")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":name"),
                    Core.t_string.vx_new_from_string(".passflag"),
                    Core.t_string.vx_new_from_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.t_string.vx_new_from_string("background-color"),
                        Core.t_string.vx_new_from_string("green"),
                        Core.t_string.vx_new_from_string("color"),
                        Core.t_string.vx_new_from_string("white"),
                        Core.t_string.vx_new_from_string("padding-left"),
                        Core.t_string.vx_new_from_string("4px"),
                        Core.t_string.vx_new_from_string("padding-right"),
                        Core.t_string.vx_new_from_string("4px"),
                        Core.t_string.vx_new_from_string("padding-top"),
                        Core.t_string.vx_new_from_string("1px"),
                        Core.t_string.vx_new_from_string("padding-bottom"),
                        Core.t_string.vx_new_from_string("1px")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":name"),
                    Core.t_string.vx_new_from_string(".coveragenums"),
                    Core.t_string.vx_new_from_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.t_string.vx_new_from_string("width"),
                        Core.t_string.vx_new_from_string("90px")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":name"),
                    Core.t_string.vx_new_from_string(".coveragepct"),
                    Core.t_string.vx_new_from_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.t_string.vx_new_from_string("text-align"),
                        Core.t_string.vx_new_from_string("right")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":name"),
                    Core.t_string.vx_new_from_string(".coveragepctgreen"),
                    Core.t_string.vx_new_from_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.t_string.vx_new_from_string("background-color"),
                        Core.t_string.vx_new_from_string("green"),
                        Core.t_string.vx_new_from_string("color"),
                        Core.t_string.vx_new_from_string("white"),
                        Core.t_string.vx_new_from_string("text-align"),
                        Core.t_string.vx_new_from_string("right")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":name"),
                    Core.t_string.vx_new_from_string(".coveragepctred"),
                    Core.t_string.vx_new_from_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.t_string.vx_new_from_string("background-color"),
                        Core.t_string.vx_new_from_string("red"),
                        Core.t_string.vx_new_from_string("color"),
                        Core.t_string.vx_new_from_string("white"),
                        Core.t_string.vx_new_from_string("text-align"),
                        Core.t_string.vx_new_from_string("right")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":name"),
                    Core.t_string.vx_new_from_string(".pkgheader"),
                    Core.t_string.vx_new_from_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.t_string.vx_new_from_string("display"),
                        Core.t_string.vx_new_from_string("inline-flex"),
                        Core.t_string.vx_new_from_string("gap"),
                        Core.t_string.vx_new_from_string("10px")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":name"),
                    Core.t_string.vx_new_from_string(".pkgname"),
                    Core.t_string.vx_new_from_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.t_string.vx_new_from_string("font-weight"),
                        Core.t_string.vx_new_from_string("bold"),
                        Core.t_string.vx_new_from_string("width"),
                        Core.t_string.vx_new_from_string("180px")
                      )
                    )
                  )
                ),
                Core.f_new(
                  Html.t_style,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":name"),
                    Core.t_string.vx_new_from_string(".preformatted"),
                    Core.t_string.vx_new_from_string(":props"),
                    Core.f_new(
                      Html.t_propmap,
                      Core.t_anylist.vx_new(
                        Core.t_string.vx_new_from_string("display"),
                        Core.t_string.vx_new_from_string("block"),
                        Core.t_string.vx_new_from_string("unicode-bidi"),
                        Core.t_string.vx_new_from_string("embed"),
                        Core.t_string.vx_new_from_string("font-family"),
                        Core.t_string.vx_new_from_string("monospace"),
                        Core.t_string.vx_new_from_string("white-space"),
                        Core.t_string.vx_new_from_string("pre")
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
      output.vx_p_style = val.style();
      output.vx_p_name = val.name();
      output.vx_p_styles = val.styles();
      output.vx_p_stylemap = val.stylemap();
      return output;
    }


  }

  public static final Const_stylesheet_test c_stylesheet_test = Const_stylesheet_test.const_new();

  /**
   * @function div_from_testcaselist
   * @param  {testcaselist} testcaselist
   * @return {div}
   * (func div<-testcaselist)
   */
  public static interface Func_div_from_testcaselist extends Core.Func_any_from_any {
    public Html.Type_div f_div_from_testcaselist(final Test.Type_testcaselist testcaselist);
  }

  public static class Class_div_from_testcaselist extends Core.Class_base implements Func_div_from_testcaselist {

    @Override
    public Func_div_from_testcaselist vx_new(Object... vals) {
      Class_div_from_testcaselist output = new Class_div_from_testcaselist();
      return output;
    }

    @Override
    public Func_div_from_testcaselist vx_copy(Object... vals) {
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
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Test.Type_testcaselist inputval = (Test.Type_testcaselist)value;
      Core.Type_any outputval = Test.f_div_from_testcaselist(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Test.Type_testcaselist testcaselist = Core.f_any_from_any(Test.t_testcaselist, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Test.f_div_from_testcaselist(testcaselist);
      return output;
    }

    @Override
    public Html.Type_div f_div_from_testcaselist(final Test.Type_testcaselist testcaselist) {
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
            Core.t_string.vx_new_from_string(":thead"),
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
                            Core.t_string.vx_new_from_string(":text"),
                            Core.t_string.vx_new_from_string("Pass?")
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
                            Core.t_string.vx_new_from_string(":text"),
                            Core.t_string.vx_new_from_string("Name")
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
                            Core.t_string.vx_new_from_string(":text"),
                            Core.t_string.vx_new_from_string("Test")
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
                            Core.t_string.vx_new_from_string(":text"),
                            Core.t_string.vx_new_from_string("Expected")
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
                            Core.t_string.vx_new_from_string(":text"),
                            Core.t_string.vx_new_from_string("Actual")
                          )
                        )
                      )
                    )
                  )
                )
              )
            ),
            Core.t_string.vx_new_from_string(":tbody"),
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
  public static interface Func_div_from_testpackage extends Core.Func_any_from_any {
    public Html.Type_div f_div_from_testpackage(final Test.Type_testpackage testpackage);
  }

  public static class Class_div_from_testpackage extends Core.Class_base implements Func_div_from_testpackage {

    @Override
    public Func_div_from_testpackage vx_new(Object... vals) {
      Class_div_from_testpackage output = new Class_div_from_testpackage();
      return output;
    }

    @Override
    public Func_div_from_testpackage vx_copy(Object... vals) {
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
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Test.Type_testpackage inputval = (Test.Type_testpackage)value;
      Core.Type_any outputval = Test.f_div_from_testpackage(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Test.Type_testpackage testpackage = Core.f_any_from_any(Test.t_testpackage, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Test.f_div_from_testpackage(testpackage);
      return output;
    }

    @Override
    public Html.Type_div f_div_from_testpackage(final Test.Type_testpackage testpackage) {
      return Test.f_div_from_testpackage(testpackage);
    }

  }

  public static final Func_div_from_testpackage e_div_from_testpackage = new Test.Class_div_from_testpackage();
  public static final Func_div_from_testpackage t_div_from_testpackage = new Test.Class_div_from_testpackage();

  public static Html.Type_div f_div_from_testpackage(final Test.Type_testpackage testpackage) {
    Html.Type_div output = Html.e_div;
    output = Core.f_let(
      Html.t_div,
      Core.t_any_from_func.fn_new(() -> {
        final Test.Type_testcoveragesummary testcoveragesummary = testpackage.coveragesummary();
        final Core.Type_string pkgname = testpackage.testpkg();
        final Test.Type_testcaselist caselist = testpackage.caselist();
        final Core.Type_boolean passfail = testpackage.passfail();
        final Html.Type_style pkgnamestyle = Html.f_style_from_stylesheet_name(
          Test.c_stylesheet_test,
          Core.t_string.vx_new_from_string(".pkgname")
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
              Core.t_string.vx_new_from_string(":style"),
              pkgnamestyle,
              Core.t_string.vx_new_from_string(":text"),
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
              Core.t_string.vx_new_from_string(":summary"),
              summary,
              Core.t_string.vx_new_from_string(":nodes"),
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
  public static interface Func_div_from_testpackagelist extends Core.Func_any_from_any {
    public Html.Type_div f_div_from_testpackagelist(final Test.Type_testpackagelist testpackagelist);
  }

  public static class Class_div_from_testpackagelist extends Core.Class_base implements Func_div_from_testpackagelist {

    @Override
    public Func_div_from_testpackagelist vx_new(Object... vals) {
      Class_div_from_testpackagelist output = new Class_div_from_testpackagelist();
      return output;
    }

    @Override
    public Func_div_from_testpackagelist vx_copy(Object... vals) {
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
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Test.Type_testpackagelist inputval = (Test.Type_testpackagelist)value;
      Core.Type_any outputval = Test.f_div_from_testpackagelist(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Test.Type_testpackagelist testpackagelist = Core.f_any_from_any(Test.t_testpackagelist, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Test.f_div_from_testpackagelist(testpackagelist);
      return output;
    }

    @Override
    public Html.Type_div f_div_from_testpackagelist(final Test.Type_testpackagelist testpackagelist) {
      return Test.f_div_from_testpackagelist(testpackagelist);
    }

  }

  public static final Func_div_from_testpackagelist e_div_from_testpackagelist = new Test.Class_div_from_testpackagelist();
  public static final Func_div_from_testpackagelist t_div_from_testpackagelist = new Test.Class_div_from_testpackagelist();

  public static Html.Type_div f_div_from_testpackagelist(final Test.Type_testpackagelist testpackagelist) {
    Html.Type_div output = Html.e_div;
    output = Core.f_let(
      Html.t_div,
      Core.t_any_from_func.fn_new(() -> {
        final Html.Type_style stylepassfail = Html.f_style_from_stylesheet_name(
          Test.c_stylesheet_test,
          Core.t_string.vx_new_from_string(".passfail")
        );
        final Html.Type_style stylepkgname = Html.f_style_from_stylesheet_name(
          Test.c_stylesheet_test,
          Core.t_string.vx_new_from_string(".pkgname")
        );
        final Html.Type_style stylepkgheader = Html.f_style_from_stylesheet_name(
          Test.c_stylesheet_test,
          Core.t_string.vx_new_from_string(".pkgheader")
        );
        final Html.Type_style stylecoveragenum = Html.f_style_from_stylesheet_name(
          Test.c_stylesheet_test,
          Core.t_string.vx_new_from_string(".coveragenums")
        );
        return Core.f_new(
          Html.t_div,
          Core.t_anylist.vx_new(
            Core.f_new(
              Html.t_div,
              Core.t_anylist.vx_new(
                Core.t_string.vx_new_from_string(":style"),
                stylepkgheader,
                Core.f_new(
                  Html.t_p,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":style"),
                    stylepassfail,
                    Core.t_string.vx_new_from_string(":text"),
                    Core.t_string.vx_new_from_string("Pass?")
                  )
                ),
                Core.f_new(
                  Html.t_p,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":style"),
                    stylepkgname,
                    Core.t_string.vx_new_from_string(":text"),
                    Core.t_string.vx_new_from_string("Package Name")
                  )
                ),
                Core.f_new(
                  Html.t_p,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":style"),
                    stylecoveragenum,
                    Core.t_string.vx_new_from_string(":text"),
                    Core.t_string.vx_new_from_string("Coverage")
                  )
                ),
                Core.f_new(
                  Html.t_p,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":style"),
                    stylecoveragenum,
                    Core.t_string.vx_new_from_string(":text"),
                    Core.t_string.vx_new_from_string("(type)")
                  )
                ),
                Core.f_new(
                  Html.t_p,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":style"),
                    stylecoveragenum,
                    Core.t_string.vx_new_from_string(":text"),
                    Core.t_string.vx_new_from_string("(const)")
                  )
                ),
                Core.f_new(
                  Html.t_p,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":style"),
                    stylecoveragenum,
                    Core.t_string.vx_new_from_string(":text"),
                    Core.t_string.vx_new_from_string("(func)")
                  )
                ),
                Core.f_new(
                  Html.t_p,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":style"),
                    stylecoveragenum,
                    Core.t_string.vx_new_from_string(":text"),
                    Core.t_string.vx_new_from_string(":doc")
                  )
                ),
                Core.f_new(
                  Html.t_p,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":style"),
                    stylecoveragenum,
                    Core.t_string.vx_new_from_string(":text"),
                    Core.t_string.vx_new_from_string(":bigospace")
                  )
                ),
                Core.f_new(
                  Html.t_p,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string(":style"),
                    stylecoveragenum,
                    Core.t_string.vx_new_from_string(":text"),
                    Core.t_string.vx_new_from_string(":bigotime")
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
  public static interface Func_divchildlist_from_testpackagelist extends Core.Func_any_from_any {
    public Html.Type_divchildlist f_divchildlist_from_testpackagelist(final Test.Type_testpackagelist testpackagelist);
  }

  public static class Class_divchildlist_from_testpackagelist extends Core.Class_base implements Func_divchildlist_from_testpackagelist {

    @Override
    public Func_divchildlist_from_testpackagelist vx_new(Object... vals) {
      Class_divchildlist_from_testpackagelist output = new Class_divchildlist_from_testpackagelist();
      return output;
    }

    @Override
    public Func_divchildlist_from_testpackagelist vx_copy(Object... vals) {
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
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Test.Type_testpackagelist inputval = (Test.Type_testpackagelist)value;
      Core.Type_any outputval = Test.f_divchildlist_from_testpackagelist(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Test.Type_testpackagelist testpackagelist = Core.f_any_from_any(Test.t_testpackagelist, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Test.f_divchildlist_from_testpackagelist(testpackagelist);
      return output;
    }

    @Override
    public Html.Type_divchildlist f_divchildlist_from_testpackagelist(final Test.Type_testpackagelist testpackagelist) {
      return Test.f_divchildlist_from_testpackagelist(testpackagelist);
    }

  }

  public static final Func_divchildlist_from_testpackagelist e_divchildlist_from_testpackagelist = new Test.Class_divchildlist_from_testpackagelist();
  public static final Func_divchildlist_from_testpackagelist t_divchildlist_from_testpackagelist = new Test.Class_divchildlist_from_testpackagelist();

  public static Html.Type_divchildlist f_divchildlist_from_testpackagelist(final Test.Type_testpackagelist testpackagelist) {
    Html.Type_divchildlist output = Html.e_divchildlist;
    output = Core.f_list_from_list(
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
  public static interface Func_file_test extends Core.Type_func, Core.Type_replfunc {
    public File.Type_file f_file_test();
  }

  public static class Class_file_test extends Core.Class_base implements Func_file_test {

    @Override
    public Func_file_test vx_new(Object... vals) {
      Class_file_test output = new Class_file_test();
      return output;
    }

    @Override
    public Func_file_test vx_copy(Object... vals) {
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
    public File.Type_file f_file_test() {
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
        Core.t_string.vx_new_from_string(":name"),
        Core.t_string.vx_new_from_string("testsuite.vxlisp"),
        Core.t_string.vx_new_from_string(":path"),
        Core.t_string.vx_new_from_string("src/test/resources")
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
  public static interface Func_file_testhtml extends Core.Type_func, Core.Type_replfunc {
    public File.Type_file f_file_testhtml();
  }

  public static class Class_file_testhtml extends Core.Class_base implements Func_file_testhtml {

    @Override
    public Func_file_testhtml vx_new(Object... vals) {
      Class_file_testhtml output = new Class_file_testhtml();
      return output;
    }

    @Override
    public Func_file_testhtml vx_copy(Object... vals) {
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
    public File.Type_file f_file_testhtml() {
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
        Core.t_string.vx_new_from_string(":name"),
        Core.t_string.vx_new_from_string("testsuite.html"),
        Core.t_string.vx_new_from_string(":path"),
        Core.t_string.vx_new_from_string("src/test/resources")
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
  public static interface Func_file_testnode extends Core.Type_func, Core.Type_replfunc {
    public File.Type_file f_file_testnode();
  }

  public static class Class_file_testnode extends Core.Class_base implements Func_file_testnode {

    @Override
    public Func_file_testnode vx_new(Object... vals) {
      Class_file_testnode output = new Class_file_testnode();
      return output;
    }

    @Override
    public Func_file_testnode vx_copy(Object... vals) {
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
    public File.Type_file f_file_testnode() {
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
        Core.t_string.vx_new_from_string(":name"),
        Core.t_string.vx_new_from_string("testsuitenode.vxlisp"),
        Core.t_string.vx_new_from_string(":path"),
        Core.t_string.vx_new_from_string("src/test/resources")
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
  public static interface Func_html_from_divtest extends Core.Func_any_from_any {
    public Html.Type_html f_html_from_divtest(final Html.Type_div divtest);
  }

  public static class Class_html_from_divtest extends Core.Class_base implements Func_html_from_divtest {

    @Override
    public Func_html_from_divtest vx_new(Object... vals) {
      Class_html_from_divtest output = new Class_html_from_divtest();
      return output;
    }

    @Override
    public Func_html_from_divtest vx_copy(Object... vals) {
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
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Html.Type_div inputval = (Html.Type_div)value;
      Core.Type_any outputval = Test.f_html_from_divtest(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Html.Type_div divtest = Core.f_any_from_any(Html.t_div, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Test.f_html_from_divtest(divtest);
      return output;
    }

    @Override
    public Html.Type_html f_html_from_divtest(final Html.Type_div divtest) {
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
        Core.t_string.vx_new_from_string(":lang"),
        Core.t_string.vx_new_from_string("en"),
        Core.t_string.vx_new_from_string(":head"),
        Core.f_new(
          Html.t_head,
          Core.t_anylist.vx_new(
            Core.f_new(
              Html.t_meta,
              Core.t_anylist.vx_new(
                Core.t_string.vx_new_from_string(":charset"),
                Core.t_string.vx_new_from_string("utf-8")
              )
            ),
            Core.f_new(
              Html.t_title,
              Core.t_anylist.vx_new(
                Core.t_string.vx_new_from_string(":text"),
                Core.t_string.vx_new_from_string("Test Suite")
              )
            ),
            Test.c_stylesheet_test
          )
        ),
        Core.t_string.vx_new_from_string(":body"),
        Core.f_new(
          Html.t_body,
          Core.t_anylist.vx_new(
            Core.f_new(
              Html.t_div,
              Core.t_anylist.vx_new(
                Core.f_new(
                  Html.t_h1,
                  Core.t_anylist.vx_new(
                    Core.t_string.vx_new_from_string("Test Suite")
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
  public static interface Func_p_from_passfail extends Core.Func_any_from_any {
    public Html.Type_p f_p_from_passfail(final Core.Type_boolean passfail);
  }

  public static class Class_p_from_passfail extends Core.Class_base implements Func_p_from_passfail {

    @Override
    public Func_p_from_passfail vx_new(Object... vals) {
      Class_p_from_passfail output = new Class_p_from_passfail();
      return output;
    }

    @Override
    public Func_p_from_passfail vx_copy(Object... vals) {
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
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_boolean inputval = (Core.Type_boolean)value;
      Core.Type_any outputval = Test.f_p_from_passfail(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_boolean passfail = Core.f_any_from_any(Core.t_boolean, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Test.f_p_from_passfail(passfail);
      return output;
    }

    @Override
    public Html.Type_p f_p_from_passfail(final Core.Type_boolean passfail) {
      return Test.f_p_from_passfail(passfail);
    }

  }

  public static final Func_p_from_passfail e_p_from_passfail = new Test.Class_p_from_passfail();
  public static final Func_p_from_passfail t_p_from_passfail = new Test.Class_p_from_passfail();

  public static Html.Type_p f_p_from_passfail(final Core.Type_boolean passfail) {
    Html.Type_p output = Html.e_p;
    output = Core.f_let(
      Html.t_p,
      Core.t_any_from_func.fn_new(() -> {
        final Core.Type_string text = Core.f_if_1(Core.t_string, passfail, Core.t_string.vx_new_from_string("Pass"), Core.t_string.vx_new_from_string("Fail"));
        final Core.Type_string stylename = Core.f_if_1(Core.t_string, passfail, Core.t_string.vx_new_from_string(".passflag"), Core.t_string.vx_new_from_string(".failflag"));
        final Html.Type_style style = Html.f_style_from_stylesheet_name(
          Test.c_stylesheet_test,
          stylename
        );
        return Core.f_new(
          Html.t_p,
          Core.t_anylist.vx_new(
            Core.t_string.vx_new_from_string(":style"),
            style,
            Core.t_string.vx_new_from_string(":text"),
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
  public static interface Func_p_from_testcoveragenums extends Core.Func_any_from_any {
    public Html.Type_p f_p_from_testcoveragenums(final Test.Type_testcoveragenums nums);
  }

  public static class Class_p_from_testcoveragenums extends Core.Class_base implements Func_p_from_testcoveragenums {

    @Override
    public Func_p_from_testcoveragenums vx_new(Object... vals) {
      Class_p_from_testcoveragenums output = new Class_p_from_testcoveragenums();
      return output;
    }

    @Override
    public Func_p_from_testcoveragenums vx_copy(Object... vals) {
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
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Test.Type_testcoveragenums inputval = (Test.Type_testcoveragenums)value;
      Core.Type_any outputval = Test.f_p_from_testcoveragenums(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Test.Type_testcoveragenums nums = Core.f_any_from_any(Test.t_testcoveragenums, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Test.f_p_from_testcoveragenums(nums);
      return output;
    }

    @Override
    public Html.Type_p f_p_from_testcoveragenums(final Test.Type_testcoveragenums nums) {
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
        Core.t_string.vx_new_from_string(":style"),
        Html.f_style_from_stylesheet_name(
          Test.c_stylesheet_test,
          Core.t_string.vx_new_from_string(".coveragenums")
        ),
        Core.t_string.vx_new_from_string(":text"),
        Core.f_new(
          Core.t_string,
          Core.t_anylist.vx_new(
            nums.pct(),
            Core.t_string.vx_new_from_string("% "),
            nums.tests(),
            Core.t_string.vx_new_from_string("/"),
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
  public static interface Func_resolve_testcase extends Core.Func_any_from_any_async {
    public CompletableFuture<Test.Type_testcase> f_resolve_testcase(final Test.Type_testcase testcase);
  }

  public static class Class_resolve_testcase extends Core.Class_base implements Func_resolve_testcase {

    @Override
    public Func_resolve_testcase vx_new(Object... vals) {
      Class_resolve_testcase output = new Class_resolve_testcase();
      return output;
    }

    @Override
    public Func_resolve_testcase vx_copy(Object... vals) {
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
    public Core.Func_any_from_any_async fn_new(Core.Class_any_from_any_async.IFn fn) {return Core.e_any_from_any_async;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_any_async(final T generic_any_1, final U value) {
      Test.Type_testcase inputval = Core.f_any_from_any(Test.t_testcase, value);
      CompletableFuture<Test.Type_testcase> future = Test.f_resolve_testcase(inputval);
      @SuppressWarnings("unchecked")
      CompletableFuture<T> output = (CompletableFuture<T>)future;
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Test.Type_testcase testcase = Core.f_any_from_any(Test.t_testcase, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      CompletableFuture<Test.Type_testcase> future = Test.f_resolve_testcase(testcase);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Test.Type_testcase> f_resolve_testcase(final Test.Type_testcase testcase) {
      return Test.f_resolve_testcase(testcase);
    }

  }

  public static final Func_resolve_testcase e_resolve_testcase = new Test.Class_resolve_testcase();
  public static final Func_resolve_testcase t_resolve_testcase = new Test.Class_resolve_testcase();

  public static CompletableFuture<Test.Type_testcase> f_resolve_testcase(final Test.Type_testcase testcase) {
    CompletableFuture<Test.Type_testcase> output = Core.async_new_completed(Test.e_testcase);
    output = Core.f_let_async(
      Test.t_testcase,
      Core.t_any_from_func_async.fn_new(() -> {
        final Test.Type_testdescribelist describelist = testcase.describelist();
        final CompletableFuture<Test.Type_testdescribelist> future_resolvedlist = Test.f_resolve_testdescribelist(describelist);
        return Core.async_from_async_fn(future_resolvedlist, (resolvedlist) -> {
          final Core.Type_booleanlist passfaillist = Core.f_list_from_list(
            Core.t_booleanlist,
            resolvedlist,
            Core.t_any_from_any.fn_new((testdescribe_any) -> {
              Test.Type_testdescribe testdescribe = Core.f_any_from_any(Test.t_testdescribe, testdescribe_any);
              return 
                    Core.f_let(
                      Core.t_boolean,
                      Core.t_any_from_func.fn_new(() -> {
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
                  Core.t_string.vx_new_from_string(":passfail"),
                  passfail,
                  Core.t_string.vx_new_from_string(":describelist"),
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
  public static interface Func_resolve_testcaselist extends Core.Func_any_from_any_async {
    public CompletableFuture<Test.Type_testcaselist> f_resolve_testcaselist(final Test.Type_testcaselist testcaselist);
  }

  public static class Class_resolve_testcaselist extends Core.Class_base implements Func_resolve_testcaselist {

    @Override
    public Func_resolve_testcaselist vx_new(Object... vals) {
      Class_resolve_testcaselist output = new Class_resolve_testcaselist();
      return output;
    }

    @Override
    public Func_resolve_testcaselist vx_copy(Object... vals) {
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
    public Core.Func_any_from_any_async fn_new(Core.Class_any_from_any_async.IFn fn) {return Core.e_any_from_any_async;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_any_async(final T generic_any_1, final U value) {
      Test.Type_testcaselist inputval = Core.f_any_from_any(Test.t_testcaselist, value);
      CompletableFuture<Test.Type_testcaselist> future = Test.f_resolve_testcaselist(inputval);
      @SuppressWarnings("unchecked")
      CompletableFuture<T> output = (CompletableFuture<T>)future;
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Test.Type_testcaselist testcaselist = Core.f_any_from_any(Test.t_testcaselist, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      CompletableFuture<Test.Type_testcaselist> future = Test.f_resolve_testcaselist(testcaselist);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Test.Type_testcaselist> f_resolve_testcaselist(final Test.Type_testcaselist testcaselist) {
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
  public static interface Func_resolve_testdescribe extends Core.Func_any_from_any_async {
    public CompletableFuture<Test.Type_testdescribe> f_resolve_testdescribe(final Test.Type_testdescribe testdescribe);
  }

  public static class Class_resolve_testdescribe extends Core.Class_base implements Func_resolve_testdescribe {

    @Override
    public Func_resolve_testdescribe vx_new(Object... vals) {
      Class_resolve_testdescribe output = new Class_resolve_testdescribe();
      return output;
    }

    @Override
    public Func_resolve_testdescribe vx_copy(Object... vals) {
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
    public Core.Func_any_from_any_async fn_new(Core.Class_any_from_any_async.IFn fn) {return Core.e_any_from_any_async;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_any_async(final T generic_any_1, final U value) {
      Test.Type_testdescribe inputval = Core.f_any_from_any(Test.t_testdescribe, value);
      CompletableFuture<Test.Type_testdescribe> future = Test.f_resolve_testdescribe(inputval);
      @SuppressWarnings("unchecked")
      CompletableFuture<T> output = (CompletableFuture<T>)future;
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Test.Type_testdescribe testdescribe = Core.f_any_from_any(Test.t_testdescribe, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      CompletableFuture<Test.Type_testdescribe> future = Test.f_resolve_testdescribe(testdescribe);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Test.Type_testdescribe> f_resolve_testdescribe(final Test.Type_testdescribe testdescribe) {
      return Test.f_resolve_testdescribe(testdescribe);
    }

  }

  public static final Func_resolve_testdescribe e_resolve_testdescribe = new Test.Class_resolve_testdescribe();
  public static final Func_resolve_testdescribe t_resolve_testdescribe = new Test.Class_resolve_testdescribe();

  public static CompletableFuture<Test.Type_testdescribe> f_resolve_testdescribe(final Test.Type_testdescribe testdescribe) {
    CompletableFuture<Test.Type_testdescribe> output = Core.async_new_completed(Test.e_testdescribe);
    output = Core.f_let_async(
      Test.t_testdescribe,
      Core.t_any_from_func_async.fn_new(() -> {
        final Test.Type_testresult testresult = testdescribe.testresult();
        final CompletableFuture<Test.Type_testresult> future_resolved = Test.f_resolve_testresult(testresult);
        return Core.async_from_async_fn(future_resolved, (resolved) -> {
          return Core.f_copy(
            testdescribe,
            Core.t_anylist.vx_new(
                  Core.t_string.vx_new_from_string(":testresult"),
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
  public static interface Func_resolve_testdescribelist extends Core.Func_any_from_any_async {
    public CompletableFuture<Test.Type_testdescribelist> f_resolve_testdescribelist(final Test.Type_testdescribelist testdescribelist);
  }

  public static class Class_resolve_testdescribelist extends Core.Class_base implements Func_resolve_testdescribelist {

    @Override
    public Func_resolve_testdescribelist vx_new(Object... vals) {
      Class_resolve_testdescribelist output = new Class_resolve_testdescribelist();
      return output;
    }

    @Override
    public Func_resolve_testdescribelist vx_copy(Object... vals) {
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
    public Core.Func_any_from_any_async fn_new(Core.Class_any_from_any_async.IFn fn) {return Core.e_any_from_any_async;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_any_async(final T generic_any_1, final U value) {
      Test.Type_testdescribelist inputval = Core.f_any_from_any(Test.t_testdescribelist, value);
      CompletableFuture<Test.Type_testdescribelist> future = Test.f_resolve_testdescribelist(inputval);
      @SuppressWarnings("unchecked")
      CompletableFuture<T> output = (CompletableFuture<T>)future;
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Test.Type_testdescribelist testdescribelist = Core.f_any_from_any(Test.t_testdescribelist, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      CompletableFuture<Test.Type_testdescribelist> future = Test.f_resolve_testdescribelist(testdescribelist);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Test.Type_testdescribelist> f_resolve_testdescribelist(final Test.Type_testdescribelist testdescribelist) {
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
  public static interface Func_resolve_testpackage extends Core.Func_any_from_any_async {
    public CompletableFuture<Test.Type_testpackage> f_resolve_testpackage(final Test.Type_testpackage testpackage);
  }

  public static class Class_resolve_testpackage extends Core.Class_base implements Func_resolve_testpackage {

    @Override
    public Func_resolve_testpackage vx_new(Object... vals) {
      Class_resolve_testpackage output = new Class_resolve_testpackage();
      return output;
    }

    @Override
    public Func_resolve_testpackage vx_copy(Object... vals) {
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
    public Core.Func_any_from_any_async fn_new(Core.Class_any_from_any_async.IFn fn) {return Core.e_any_from_any_async;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_any_async(final T generic_any_1, final U value) {
      Test.Type_testpackage inputval = Core.f_any_from_any(Test.t_testpackage, value);
      CompletableFuture<Test.Type_testpackage> future = Test.f_resolve_testpackage(inputval);
      @SuppressWarnings("unchecked")
      CompletableFuture<T> output = (CompletableFuture<T>)future;
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Test.Type_testpackage testpackage = Core.f_any_from_any(Test.t_testpackage, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      CompletableFuture<Test.Type_testpackage> future = Test.f_resolve_testpackage(testpackage);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Test.Type_testpackage> f_resolve_testpackage(final Test.Type_testpackage testpackage) {
      return Test.f_resolve_testpackage(testpackage);
    }

  }

  public static final Func_resolve_testpackage e_resolve_testpackage = new Test.Class_resolve_testpackage();
  public static final Func_resolve_testpackage t_resolve_testpackage = new Test.Class_resolve_testpackage();

  public static CompletableFuture<Test.Type_testpackage> f_resolve_testpackage(final Test.Type_testpackage testpackage) {
    CompletableFuture<Test.Type_testpackage> output = Core.async_new_completed(Test.e_testpackage);
    output = Core.f_let_async(
      Test.t_testpackage,
      Core.t_any_from_func_async.fn_new(() -> {
        final Test.Type_testcaselist testcaselist = testpackage.caselist();
        final CompletableFuture<Test.Type_testcaselist> future_resolvedlist = Test.f_resolve_testcaselist(testcaselist);
        return Core.async_from_async_fn(future_resolvedlist, (resolvedlist) -> {
          final Core.Type_booleanlist passfaillist = Core.f_list_from_list(
            Core.t_booleanlist,
            resolvedlist,
            Core.t_any_from_any.fn_new((testcase_any) -> {
              Test.Type_testcase testcase = Core.f_any_from_any(Test.t_testcase, testcase_any);
              return 
                    testcase.passfail();
            })
          );
          final Core.Type_boolean passfail = Core.f_and_1(passfaillist);
          return Core.f_copy(
            testpackage,
            Core.t_anylist.vx_new(
                  Core.t_string.vx_new_from_string(":passfail"),
                  passfail,
                  Core.t_string.vx_new_from_string(":caselist"),
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
  public static interface Func_resolve_testpackagelist extends Core.Func_any_from_any_async {
    public CompletableFuture<Test.Type_testpackagelist> f_resolve_testpackagelist(final Test.Type_testpackagelist testpackagelist);
  }

  public static class Class_resolve_testpackagelist extends Core.Class_base implements Func_resolve_testpackagelist {

    @Override
    public Func_resolve_testpackagelist vx_new(Object... vals) {
      Class_resolve_testpackagelist output = new Class_resolve_testpackagelist();
      return output;
    }

    @Override
    public Func_resolve_testpackagelist vx_copy(Object... vals) {
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
    public Core.Func_any_from_any_async fn_new(Core.Class_any_from_any_async.IFn fn) {return Core.e_any_from_any_async;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_any_async(final T generic_any_1, final U value) {
      Test.Type_testpackagelist inputval = Core.f_any_from_any(Test.t_testpackagelist, value);
      CompletableFuture<Test.Type_testpackagelist> future = Test.f_resolve_testpackagelist(inputval);
      @SuppressWarnings("unchecked")
      CompletableFuture<T> output = (CompletableFuture<T>)future;
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Test.Type_testpackagelist testpackagelist = Core.f_any_from_any(Test.t_testpackagelist, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      CompletableFuture<Test.Type_testpackagelist> future = Test.f_resolve_testpackagelist(testpackagelist);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Test.Type_testpackagelist> f_resolve_testpackagelist(final Test.Type_testpackagelist testpackagelist) {
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
  public static interface Func_resolve_testresult extends Core.Func_any_from_any_async {
    public CompletableFuture<Test.Type_testresult> f_resolve_testresult(final Test.Type_testresult testresult);
  }

  public static class Class_resolve_testresult extends Core.Class_base implements Func_resolve_testresult {

    @Override
    public Func_resolve_testresult vx_new(Object... vals) {
      Class_resolve_testresult output = new Class_resolve_testresult();
      return output;
    }

    @Override
    public Func_resolve_testresult vx_copy(Object... vals) {
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
    public Core.Func_any_from_any_async fn_new(Core.Class_any_from_any_async.IFn fn) {return Core.e_any_from_any_async;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> CompletableFuture<T> f_any_from_any_async(final T generic_any_1, final U value) {
      Test.Type_testresult inputval = Core.f_any_from_any(Test.t_testresult, value);
      CompletableFuture<Test.Type_testresult> future = Test.f_resolve_testresult(inputval);
      @SuppressWarnings("unchecked")
      CompletableFuture<T> output = (CompletableFuture<T>)future;
      return output;
    }

    public CompletableFuture<Core.Type_any> vx_repl(Core.Type_anylist arglist) {
      CompletableFuture<Core.Type_any> output = CompletableFuture.completedFuture(Core.e_any);
      Test.Type_testresult testresult = Core.f_any_from_any(Test.t_testresult, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      CompletableFuture<Test.Type_testresult> future = Test.f_resolve_testresult(testresult);
      output = Core.async_from_async(Core.t_any, future);
      return output;
    }

    @Override
    public CompletableFuture<Test.Type_testresult> f_resolve_testresult(final Test.Type_testresult testresult) {
      return Test.f_resolve_testresult(testresult);
    }

  }

  public static final Func_resolve_testresult e_resolve_testresult = new Test.Class_resolve_testresult();
  public static final Func_resolve_testresult t_resolve_testresult = new Test.Class_resolve_testresult();

  public static CompletableFuture<Test.Type_testresult> f_resolve_testresult(final Test.Type_testresult testresult) {
    CompletableFuture<Test.Type_testresult> output = Core.async_new_completed(Test.e_testresult);
    output = Core.f_let_async(
      Test.t_testresult,
      Core.t_any_from_func_async.fn_new(() -> {
        final Core.Func_any_from_func_async fn_actual = testresult.fn_actual();
        final Core.Type_any expected = testresult.expected();
        final CompletableFuture<Core.Type_any> future_actual = Core.f_resolve_async(Core.t_any, fn_actual);
        return Core.async_from_async_fn(future_actual, (actual) -> {
          return Core.f_if_2(
            Test.t_testresult,
            Core.t_thenelselist.vx_new(
                  Core.f_then(
                    Core.t_boolean_from_func.fn_new(() -> {
                      return Core.f_is_empty_1(fn_actual);
                    }),
                    Core.t_any_from_func.fn_new(() -> {
                      return testresult;
                    })
                  ),
                  Core.f_else(
                    Core.t_any_from_func.fn_new(() -> {
                      return Core.f_let(
                        Test.t_testresult,
                        Core.t_any_from_func.fn_new(() -> {
                          final Core.Type_boolean passfail = Core.f_eq(expected, actual);
                          return Core.f_copy(
                            testresult,
                            Core.t_anylist.vx_new(
                              Core.t_string.vx_new_from_string(":passfail"),
                              passfail,
                              Core.t_string.vx_new_from_string(":actual"),
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
   * @function test
   * Test expected equal actual
   * @param  {any-1} expected
   * @param  {any-1} actual
   * @return {testresult}
   * (func test)
   */
  public static interface Func_test extends Core.Type_func, Core.Type_replfunc {
    public Test.Type_testresult f_test(final Core.Type_any expected, final Core.Type_any actual, Core.Type_context context);
  }

  public static class Class_test extends Core.Class_base implements Func_test {

    @Override
    public Func_test vx_new(Object... vals) {
      Class_test output = new Class_test();
      return output;
    }

    @Override
    public Func_test vx_copy(Object... vals) {
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
      Core.Type_any expected = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_any actual = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.t_int.vx_new_from_int(2)));
      output = Test.f_test(expected, actual, context);
      return output;
    }

    @Override
    public Test.Type_testresult f_test(final Core.Type_any expected, final Core.Type_any actual, final Core.Type_context context) {
      return Test.f_test(expected, actual, context);
    }

  }

  public static final Func_test e_test = new Test.Class_test();
  public static final Func_test t_test = new Test.Class_test();

  public static Test.Type_testresult f_test(final Core.Type_any expected, final Core.Type_any actual, final Core.Type_context context) {
      Test.Type_testresult output = Test.e_testresult;
    try {
      output = Core.f_new(
        Test.t_testresult,
        Core.t_anylist.vx_new(
          Core.t_string.vx_new_from_string(":code"),
          Core.t_string.vx_new_from_string(":eq"),
          Core.t_string.vx_new_from_string(":passfail"),
          Core.f_eq(expected, actual),
          Core.t_string.vx_new_from_string(":expected"),
          expected,
          Core.t_string.vx_new_from_string(":actual"),
          actual
        )
      );
    } catch (Exception err) {
      Core.Type_msg msg = Core.t_msg.vx_new_from_exception("test", err);
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
  public static interface Func_test_1 extends Core.Type_func, Core.Type_replfunc {
    public Test.Type_testresult f_test_1(final Core.Type_any expected, final Core.Func_any_from_func_async fn_actual, Core.Type_context context);
  }

  public static class Class_test_1 extends Core.Class_base implements Func_test_1 {

    @Override
    public Func_test_1 vx_new(Object... vals) {
      Class_test_1 output = new Class_test_1();
      return output;
    }

    @Override
    public Func_test_1 vx_copy(Object... vals) {
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
      Core.Type_any expected = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Func_any_from_func_async fn_actual = Core.f_any_from_any(Core.t_any_from_func_async, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.t_int.vx_new_from_int(2)));
      output = Test.f_test_1(expected, fn_actual, context);
      return output;
    }

    @Override
    public Test.Type_testresult f_test_1(final Core.Type_any expected, final Core.Func_any_from_func_async fn_actual, final Core.Type_context context) {
      return Test.f_test_1(expected, fn_actual, context);
    }

  }

  public static final Func_test_1 e_test_1 = new Test.Class_test_1();
  public static final Func_test_1 t_test_1 = new Test.Class_test_1();

  public static Test.Type_testresult f_test_1(final Core.Type_any expected, final Core.Func_any_from_func_async fn_actual, final Core.Type_context context) {
      Test.Type_testresult output = Test.e_testresult;
    try {
      output = Core.f_new(
        Test.t_testresult,
        Core.t_anylist.vx_new(
          Core.t_string.vx_new_from_string(":code"),
          Core.t_string.vx_new_from_string(":eq"),
          Core.t_string.vx_new_from_string(":expected"),
          expected,
          Core.t_string.vx_new_from_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (Exception err) {
      Core.Type_msg msg = Core.t_msg.vx_new_from_exception("test", err);
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
  public static interface Func_test_false extends Core.Func_any_from_any_context {
    public Test.Type_testresult f_test_false(final Core.Type_any actual, Core.Type_context context);
  }

  public static class Class_test_false extends Core.Class_base implements Func_test_false {

    @Override
    public Func_test_false vx_new(Object... vals) {
      Class_test_false output = new Class_test_false();
      return output;
    }

    @Override
    public Func_test_false vx_copy(Object... vals) {
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
    public Core.Func_any_from_any_context fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any_context(final T generic_any_1, final U value, final Core.Type_context context) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Test.f_test_false(inputval, context);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any actual = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      output = Test.f_test_false(actual, context);
      return output;
    }

    @Override
    public Test.Type_testresult f_test_false(final Core.Type_any actual, final Core.Type_context context) {
      return Test.f_test_false(actual, context);
    }

  }

  public static final Func_test_false e_test_false = new Test.Class_test_false();
  public static final Func_test_false t_test_false = new Test.Class_test_false();

  public static Test.Type_testresult f_test_false(final Core.Type_any actual, final Core.Type_context context) {
      Test.Type_testresult output = Test.e_testresult;
    try {
      output = Core.f_new(
        Test.t_testresult,
        Core.t_anylist.vx_new(
          Core.t_string.vx_new_from_string(":code"),
          Core.t_string.vx_new_from_string(":false"),
          Core.t_string.vx_new_from_string(":passfail"),
          Core.f_eq(
            Core.t_boolean.vx_new_from_boolean(false),
            actual
          ),
          Core.t_string.vx_new_from_string(":expected"),
          Core.t_boolean.vx_new_from_boolean(false),
          Core.t_string.vx_new_from_string(":actual"),
          actual
        )
      );
    } catch (Exception err) {
      Core.Type_msg msg = Core.t_msg.vx_new_from_exception("test-false", err);
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
  public static interface Func_test_false_1 extends Core.Func_any_from_any_context {
    public Test.Type_testresult f_test_false_1(final Core.Func_any_from_func_async fn_actual, Core.Type_context context);
  }

  public static class Class_test_false_1 extends Core.Class_base implements Func_test_false_1 {

    @Override
    public Func_test_false_1 vx_new(Object... vals) {
      Class_test_false_1 output = new Class_test_false_1();
      return output;
    }

    @Override
    public Func_test_false_1 vx_copy(Object... vals) {
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
    public Core.Func_any_from_any_context fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any_context(final T generic_any_1, final U value, final Core.Type_context context) {
      T output = Core.f_empty(generic_any_1);
      Core.Func_any_from_func_async inputval = (Core.Func_any_from_func_async)value;
      Core.Type_any outputval = Test.f_test_false_1(inputval, context);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Func_any_from_func_async fn_actual = Core.f_any_from_any(Core.t_any_from_func_async, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      output = Test.f_test_false_1(fn_actual, context);
      return output;
    }

    @Override
    public Test.Type_testresult f_test_false_1(final Core.Func_any_from_func_async fn_actual, final Core.Type_context context) {
      return Test.f_test_false_1(fn_actual, context);
    }

  }

  public static final Func_test_false_1 e_test_false_1 = new Test.Class_test_false_1();
  public static final Func_test_false_1 t_test_false_1 = new Test.Class_test_false_1();

  public static Test.Type_testresult f_test_false_1(final Core.Func_any_from_func_async fn_actual, final Core.Type_context context) {
      Test.Type_testresult output = Test.e_testresult;
    try {
      output = Core.f_new(
        Test.t_testresult,
        Core.t_anylist.vx_new(
          Core.t_string.vx_new_from_string(":code"),
          Core.t_string.vx_new_from_string(":false"),
          Core.t_string.vx_new_from_string(":expected"),
          Core.t_boolean.vx_new_from_boolean(false),
          Core.t_string.vx_new_from_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (Exception err) {
      Core.Type_msg msg = Core.t_msg.vx_new_from_exception("test-false", err);
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
  public static interface Func_test_gt extends Core.Type_func, Core.Type_replfunc {
    public Test.Type_testresult f_test_gt(final Core.Type_any expected, final Core.Type_any actual, Core.Type_context context);
  }

  public static class Class_test_gt extends Core.Class_base implements Func_test_gt {

    @Override
    public Func_test_gt vx_new(Object... vals) {
      Class_test_gt output = new Class_test_gt();
      return output;
    }

    @Override
    public Func_test_gt vx_copy(Object... vals) {
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
      Core.Type_any expected = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_any actual = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.t_int.vx_new_from_int(2)));
      output = Test.f_test_gt(expected, actual, context);
      return output;
    }

    @Override
    public Test.Type_testresult f_test_gt(final Core.Type_any expected, final Core.Type_any actual, final Core.Type_context context) {
      return Test.f_test_gt(expected, actual, context);
    }

  }

  public static final Func_test_gt e_test_gt = new Test.Class_test_gt();
  public static final Func_test_gt t_test_gt = new Test.Class_test_gt();

  public static Test.Type_testresult f_test_gt(final Core.Type_any expected, final Core.Type_any actual, final Core.Type_context context) {
      Test.Type_testresult output = Test.e_testresult;
    try {
      output = Core.f_new(
        Test.t_testresult,
        Core.t_anylist.vx_new(
          Core.t_string.vx_new_from_string(":code"),
          Core.t_string.vx_new_from_string(":gt"),
          Core.t_string.vx_new_from_string(":passfail"),
          Core.f_gt(expected, actual),
          Core.t_string.vx_new_from_string(":expected"),
          expected,
          Core.t_string.vx_new_from_string(":actual"),
          actual
        )
      );
    } catch (Exception err) {
      Core.Type_msg msg = Core.t_msg.vx_new_from_exception("test-gt", err);
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
  public static interface Func_test_gt_1 extends Core.Type_func, Core.Type_replfunc {
    public Test.Type_testresult f_test_gt_1(final Core.Type_any expected, final Core.Func_any_from_func_async fn_actual, Core.Type_context context);
  }

  public static class Class_test_gt_1 extends Core.Class_base implements Func_test_gt_1 {

    @Override
    public Func_test_gt_1 vx_new(Object... vals) {
      Class_test_gt_1 output = new Class_test_gt_1();
      return output;
    }

    @Override
    public Func_test_gt_1 vx_copy(Object... vals) {
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
      Core.Type_any expected = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Func_any_from_func_async fn_actual = Core.f_any_from_any(Core.t_any_from_func_async, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.t_int.vx_new_from_int(2)));
      output = Test.f_test_gt_1(expected, fn_actual, context);
      return output;
    }

    @Override
    public Test.Type_testresult f_test_gt_1(final Core.Type_any expected, final Core.Func_any_from_func_async fn_actual, final Core.Type_context context) {
      return Test.f_test_gt_1(expected, fn_actual, context);
    }

  }

  public static final Func_test_gt_1 e_test_gt_1 = new Test.Class_test_gt_1();
  public static final Func_test_gt_1 t_test_gt_1 = new Test.Class_test_gt_1();

  public static Test.Type_testresult f_test_gt_1(final Core.Type_any expected, final Core.Func_any_from_func_async fn_actual, final Core.Type_context context) {
      Test.Type_testresult output = Test.e_testresult;
    try {
      output = Core.f_new(
        Test.t_testresult,
        Core.t_anylist.vx_new(
          Core.t_string.vx_new_from_string(":code"),
          Core.t_string.vx_new_from_string(":gt"),
          Core.t_string.vx_new_from_string(":expected"),
          expected,
          Core.t_string.vx_new_from_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (Exception err) {
      Core.Type_msg msg = Core.t_msg.vx_new_from_exception("test-gt", err);
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
  public static interface Func_test_ne extends Core.Type_func, Core.Type_replfunc {
    public Test.Type_testresult f_test_ne(final Core.Type_any expected, final Core.Type_any actual, Core.Type_context context);
  }

  public static class Class_test_ne extends Core.Class_base implements Func_test_ne {

    @Override
    public Func_test_ne vx_new(Object... vals) {
      Class_test_ne output = new Class_test_ne();
      return output;
    }

    @Override
    public Func_test_ne vx_copy(Object... vals) {
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
      Core.Type_any expected = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_any actual = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.t_int.vx_new_from_int(2)));
      output = Test.f_test_ne(expected, actual, context);
      return output;
    }

    @Override
    public Test.Type_testresult f_test_ne(final Core.Type_any expected, final Core.Type_any actual, final Core.Type_context context) {
      return Test.f_test_ne(expected, actual, context);
    }

  }

  public static final Func_test_ne e_test_ne = new Test.Class_test_ne();
  public static final Func_test_ne t_test_ne = new Test.Class_test_ne();

  public static Test.Type_testresult f_test_ne(final Core.Type_any expected, final Core.Type_any actual, final Core.Type_context context) {
      Test.Type_testresult output = Test.e_testresult;
    try {
      output = Core.f_new(
        Test.t_testresult,
        Core.t_anylist.vx_new(
          Core.t_string.vx_new_from_string(":code"),
          Core.t_string.vx_new_from_string(":ne"),
          Core.t_string.vx_new_from_string(":passfail"),
          Core.f_ne(expected, actual),
          Core.t_string.vx_new_from_string(":expected"),
          expected,
          Core.t_string.vx_new_from_string(":actual"),
          actual
        )
      );
    } catch (Exception err) {
      Core.Type_msg msg = Core.t_msg.vx_new_from_exception("test-ne", err);
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
  public static interface Func_test_ne_1 extends Core.Type_func, Core.Type_replfunc {
    public Test.Type_testresult f_test_ne_1(final Core.Type_any expected, final Core.Func_any_from_func_async fn_actual, Core.Type_context context);
  }

  public static class Class_test_ne_1 extends Core.Class_base implements Func_test_ne_1 {

    @Override
    public Func_test_ne_1 vx_new(Object... vals) {
      Class_test_ne_1 output = new Class_test_ne_1();
      return output;
    }

    @Override
    public Func_test_ne_1 vx_copy(Object... vals) {
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
      Core.Type_any expected = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Func_any_from_func_async fn_actual = Core.f_any_from_any(Core.t_any_from_func_async, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.t_int.vx_new_from_int(2)));
      output = Test.f_test_ne_1(expected, fn_actual, context);
      return output;
    }

    @Override
    public Test.Type_testresult f_test_ne_1(final Core.Type_any expected, final Core.Func_any_from_func_async fn_actual, final Core.Type_context context) {
      return Test.f_test_ne_1(expected, fn_actual, context);
    }

  }

  public static final Func_test_ne_1 e_test_ne_1 = new Test.Class_test_ne_1();
  public static final Func_test_ne_1 t_test_ne_1 = new Test.Class_test_ne_1();

  public static Test.Type_testresult f_test_ne_1(final Core.Type_any expected, final Core.Func_any_from_func_async fn_actual, final Core.Type_context context) {
      Test.Type_testresult output = Test.e_testresult;
    try {
      output = Core.f_new(
        Test.t_testresult,
        Core.t_anylist.vx_new(
          Core.t_string.vx_new_from_string(":code"),
          Core.t_string.vx_new_from_string(":ne"),
          Core.t_string.vx_new_from_string(":expected"),
          expected,
          Core.t_string.vx_new_from_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (Exception err) {
      Core.Type_msg msg = Core.t_msg.vx_new_from_exception("test-ne", err);
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
  public static interface Func_test_string extends Core.Type_func, Core.Type_replfunc {
    public Test.Type_testresult f_test_string(final Core.Type_any expected, final Core.Type_any actual, Core.Type_context context);
  }

  public static class Class_test_string extends Core.Class_base implements Func_test_string {

    @Override
    public Func_test_string vx_new(Object... vals) {
      Class_test_string output = new Class_test_string();
      return output;
    }

    @Override
    public Func_test_string vx_copy(Object... vals) {
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
      Core.Type_any expected = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_any actual = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.t_int.vx_new_from_int(2)));
      output = Test.f_test_string(expected, actual, context);
      return output;
    }

    @Override
    public Test.Type_testresult f_test_string(final Core.Type_any expected, final Core.Type_any actual, final Core.Type_context context) {
      return Test.f_test_string(expected, actual, context);
    }

  }

  public static final Func_test_string e_test_string = new Test.Class_test_string();
  public static final Func_test_string t_test_string = new Test.Class_test_string();

  public static Test.Type_testresult f_test_string(final Core.Type_any expected, final Core.Type_any actual, final Core.Type_context context) {
      Test.Type_testresult output = Test.e_testresult;
    try {
      output = Core.f_new(
        Test.t_testresult,
        Core.t_anylist.vx_new(
          Core.t_string.vx_new_from_string(":passfail"),
          Core.f_eq(
            Core.f_string_from_any(expected),
            Core.f_string_from_any(actual)
          ),
          Core.t_string.vx_new_from_string(":expected"),
          expected,
          Core.t_string.vx_new_from_string(":actual"),
          actual
        )
      );
    } catch (Exception err) {
      Core.Type_msg msg = Core.t_msg.vx_new_from_exception("test-string", err);
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
  public static interface Func_test_string_1 extends Core.Type_func, Core.Type_replfunc {
    public Test.Type_testresult f_test_string_1(final Core.Type_any expected, final Core.Func_any_from_func_async fn_actual, Core.Type_context context);
  }

  public static class Class_test_string_1 extends Core.Class_base implements Func_test_string_1 {

    @Override
    public Func_test_string_1 vx_new(Object... vals) {
      Class_test_string_1 output = new Class_test_string_1();
      return output;
    }

    @Override
    public Func_test_string_1 vx_copy(Object... vals) {
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
      Core.Type_any expected = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Func_any_from_func_async fn_actual = Core.f_any_from_any(Core.t_any_from_func_async, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.t_int.vx_new_from_int(2)));
      output = Test.f_test_string_1(expected, fn_actual, context);
      return output;
    }

    @Override
    public Test.Type_testresult f_test_string_1(final Core.Type_any expected, final Core.Func_any_from_func_async fn_actual, final Core.Type_context context) {
      return Test.f_test_string_1(expected, fn_actual, context);
    }

  }

  public static final Func_test_string_1 e_test_string_1 = new Test.Class_test_string_1();
  public static final Func_test_string_1 t_test_string_1 = new Test.Class_test_string_1();

  public static Test.Type_testresult f_test_string_1(final Core.Type_any expected, final Core.Func_any_from_func_async fn_actual, final Core.Type_context context) {
      Test.Type_testresult output = Test.e_testresult;
    try {
      output = Core.f_new(
        Test.t_testresult,
        Core.t_anylist.vx_new(
          Core.t_string.vx_new_from_string(":code"),
          Core.t_string.vx_new_from_string(":string"),
          Core.t_string.vx_new_from_string(":expected"),
          expected,
          Core.t_string.vx_new_from_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (Exception err) {
      Core.Type_msg msg = Core.t_msg.vx_new_from_exception("test-string", err);
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
  public static interface Func_test_true extends Core.Func_any_from_any_context {
    public Test.Type_testresult f_test_true(final Core.Type_any actual, Core.Type_context context);
  }

  public static class Class_test_true extends Core.Class_base implements Func_test_true {

    @Override
    public Func_test_true vx_new(Object... vals) {
      Class_test_true output = new Class_test_true();
      return output;
    }

    @Override
    public Func_test_true vx_copy(Object... vals) {
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
    public Core.Func_any_from_any_context fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any_context(final T generic_any_1, final U value, final Core.Type_context context) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_any inputval = (Core.Type_any)value;
      Core.Type_any outputval = Test.f_test_true(inputval, context);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_any actual = Core.f_any_from_any(Core.t_any, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      output = Test.f_test_true(actual, context);
      return output;
    }

    @Override
    public Test.Type_testresult f_test_true(final Core.Type_any actual, final Core.Type_context context) {
      return Test.f_test_true(actual, context);
    }

  }

  public static final Func_test_true e_test_true = new Test.Class_test_true();
  public static final Func_test_true t_test_true = new Test.Class_test_true();

  public static Test.Type_testresult f_test_true(final Core.Type_any actual, final Core.Type_context context) {
      Test.Type_testresult output = Test.e_testresult;
    try {
      output = Core.f_new(
        Test.t_testresult,
        Core.t_anylist.vx_new(
          Core.t_string.vx_new_from_string(":code"),
          Core.t_string.vx_new_from_string(":true"),
          Core.t_string.vx_new_from_string(":passfail"),
          Core.f_eq(
            Core.t_boolean.vx_new_from_boolean(true),
            actual
          ),
          Core.t_string.vx_new_from_string(":expected"),
          Core.t_boolean.vx_new_from_boolean(true),
          Core.t_string.vx_new_from_string(":actual"),
          actual
        )
      );
    } catch (Exception err) {
      Core.Type_msg msg = Core.t_msg.vx_new_from_exception("test-true", err);
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
  public static interface Func_test_true_1 extends Core.Func_any_from_any_context {
    public Test.Type_testresult f_test_true_1(final Core.Func_any_from_func_async fn_actual, Core.Type_context context);
  }

  public static class Class_test_true_1 extends Core.Class_base implements Func_test_true_1 {

    @Override
    public Func_test_true_1 vx_new(Object... vals) {
      Class_test_true_1 output = new Class_test_true_1();
      return output;
    }

    @Override
    public Func_test_true_1 vx_copy(Object... vals) {
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
    public Core.Func_any_from_any_context fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any_context(final T generic_any_1, final U value, final Core.Type_context context) {
      T output = Core.f_empty(generic_any_1);
      Core.Func_any_from_func_async inputval = (Core.Func_any_from_func_async)value;
      Core.Type_any outputval = Test.f_test_true_1(inputval, context);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Func_any_from_func_async fn_actual = Core.f_any_from_any(Core.t_any_from_func_async, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      output = Test.f_test_true_1(fn_actual, context);
      return output;
    }

    @Override
    public Test.Type_testresult f_test_true_1(final Core.Func_any_from_func_async fn_actual, final Core.Type_context context) {
      return Test.f_test_true_1(fn_actual, context);
    }

  }

  public static final Func_test_true_1 e_test_true_1 = new Test.Class_test_true_1();
  public static final Func_test_true_1 t_test_true_1 = new Test.Class_test_true_1();

  public static Test.Type_testresult f_test_true_1(final Core.Func_any_from_func_async fn_actual, final Core.Type_context context) {
      Test.Type_testresult output = Test.e_testresult;
    try {
      output = Core.f_new(
        Test.t_testresult,
        Core.t_anylist.vx_new(
          Core.t_string.vx_new_from_string(":code"),
          Core.t_string.vx_new_from_string(":true"),
          Core.t_string.vx_new_from_string(":expected"),
          Core.t_boolean.vx_new_from_boolean(true),
          Core.t_string.vx_new_from_string(":fn-actual"),
          fn_actual
        )
      );
    } catch (Exception err) {
      Core.Type_msg msg = Core.t_msg.vx_new_from_exception("test-true", err);
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
  public static interface Func_tr_from_testdescribe_casename extends Core.Type_func, Core.Type_replfunc {
    public Html.Type_tr f_tr_from_testdescribe_casename(final Test.Type_testdescribe testdescribe, final Core.Type_string casename);
  }

  public static class Class_tr_from_testdescribe_casename extends Core.Class_base implements Func_tr_from_testdescribe_casename {

    @Override
    public Func_tr_from_testdescribe_casename vx_new(Object... vals) {
      Class_tr_from_testdescribe_casename output = new Class_tr_from_testdescribe_casename();
      return output;
    }

    @Override
    public Func_tr_from_testdescribe_casename vx_copy(Object... vals) {
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
      Test.Type_testdescribe testdescribe = Core.f_any_from_any(Test.t_testdescribe, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      Core.Type_string casename = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.t_int.vx_new_from_int(1)));
      output = Test.f_tr_from_testdescribe_casename(testdescribe, casename);
      return output;
    }

    @Override
    public Html.Type_tr f_tr_from_testdescribe_casename(final Test.Type_testdescribe testdescribe, final Core.Type_string casename) {
      return Test.f_tr_from_testdescribe_casename(testdescribe, casename);
    }

  }

  public static final Func_tr_from_testdescribe_casename e_tr_from_testdescribe_casename = new Test.Class_tr_from_testdescribe_casename();
  public static final Func_tr_from_testdescribe_casename t_tr_from_testdescribe_casename = new Test.Class_tr_from_testdescribe_casename();

  public static Html.Type_tr f_tr_from_testdescribe_casename(final Test.Type_testdescribe testdescribe, final Core.Type_string casename) {
    Html.Type_tr output = Html.e_tr;
    output = Core.f_let(
      Html.t_tr,
      Core.t_any_from_func.fn_new(() -> {
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
          Core.t_string.vx_new_from_string(".preformatted")
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
                    Core.t_string.vx_new_from_string(":style"),
                    prestyle,
                    Core.t_string.vx_new_from_string(":text"),
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
                    Core.t_string.vx_new_from_string(":style"),
                    prestyle,
                    Core.t_string.vx_new_from_string(":text"),
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
                    Core.t_string.vx_new_from_string(":style"),
                    prestyle,
                    Core.t_string.vx_new_from_string(":text"),
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
                    Core.t_string.vx_new_from_string(":style"),
                    prestyle,
                    Core.t_string.vx_new_from_string(":text"),
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
  public static interface Func_trlist_from_testcase extends Core.Func_any_from_any {
    public Html.Type_trlist f_trlist_from_testcase(final Test.Type_testcase testcase);
  }

  public static class Class_trlist_from_testcase extends Core.Class_base implements Func_trlist_from_testcase {

    @Override
    public Func_trlist_from_testcase vx_new(Object... vals) {
      Class_trlist_from_testcase output = new Class_trlist_from_testcase();
      return output;
    }

    @Override
    public Func_trlist_from_testcase vx_copy(Object... vals) {
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
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Test.Type_testcase inputval = (Test.Type_testcase)value;
      Core.Type_any outputval = Test.f_trlist_from_testcase(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Test.Type_testcase testcase = Core.f_any_from_any(Test.t_testcase, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Test.f_trlist_from_testcase(testcase);
      return output;
    }

    @Override
    public Html.Type_trlist f_trlist_from_testcase(final Test.Type_testcase testcase) {
      return Test.f_trlist_from_testcase(testcase);
    }

  }

  public static final Func_trlist_from_testcase e_trlist_from_testcase = new Test.Class_trlist_from_testcase();
  public static final Func_trlist_from_testcase t_trlist_from_testcase = new Test.Class_trlist_from_testcase();

  public static Html.Type_trlist f_trlist_from_testcase(final Test.Type_testcase testcase) {
    Html.Type_trlist output = Html.e_trlist;
    output = Core.f_let(
      Html.t_trlist,
      Core.t_any_from_func.fn_new(() -> {
        final Test.Type_testdescribelist describelist = testcase.describelist();
        final Core.Type_string casename = testcase.casename();
        return Core.f_list_from_list(
          Html.t_trlist,
          describelist,
          Core.t_any_from_any.fn_new((testdescribe_any) -> {
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
  public static interface Func_trlist_from_testcaselist extends Core.Func_any_from_any {
    public Html.Type_trlist f_trlist_from_testcaselist(final Test.Type_testcaselist testcaselist);
  }

  public static class Class_trlist_from_testcaselist extends Core.Class_base implements Func_trlist_from_testcaselist {

    @Override
    public Func_trlist_from_testcaselist vx_new(Object... vals) {
      Class_trlist_from_testcaselist output = new Class_trlist_from_testcaselist();
      return output;
    }

    @Override
    public Func_trlist_from_testcaselist vx_copy(Object... vals) {
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
    public Core.Func_any_from_any fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T f_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Test.Type_testcaselist inputval = (Test.Type_testcaselist)value;
      Core.Type_any outputval = Test.f_trlist_from_testcaselist(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Test.Type_testcaselist testcaselist = Core.f_any_from_any(Test.t_testcaselist, arglist.vx_any(Core.t_int.vx_new_from_int(0)));
      output = Test.f_trlist_from_testcaselist(testcaselist);
      return output;
    }

    @Override
    public Html.Type_trlist f_trlist_from_testcaselist(final Test.Type_testcaselist testcaselist) {
      return Test.f_trlist_from_testcaselist(testcaselist);
    }

  }

  public static final Func_trlist_from_testcaselist e_trlist_from_testcaselist = new Test.Class_trlist_from_testcaselist();
  public static final Func_trlist_from_testcaselist t_trlist_from_testcaselist = new Test.Class_trlist_from_testcaselist();

  public static Html.Type_trlist f_trlist_from_testcaselist(final Test.Type_testcaselist testcaselist) {
    Html.Type_trlist output = Html.e_trlist;
    output = Core.f_list_join_from_list(
      Html.t_trlist,
      testcaselist,
      Test.t_trlist_from_testcase
    );
    return output;
  }


}
