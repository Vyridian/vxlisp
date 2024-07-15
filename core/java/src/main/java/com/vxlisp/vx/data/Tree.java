package com.vxlisp.vx.data;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import com.vxlisp.vx.*;

public final class Tree {


  /**
   * type: branch
   * (type branch)
   */
  public interface Type_branch extends Core.Type_struct {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Core.Type_string id();
    public Tree.Type_brancharrow brancharrow();
    public Tree.Type_branchlist branchlist();
    public Tree.Type_leaflist leaflist();
    public Tree.Type_branch parentbranch();
    public Tree.Type_tree tree();
  }

  public static class Class_branch extends Core.Class_base implements Type_branch {

    public Core.Type_string vx_p_id = null;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Tree.Type_brancharrow vx_p_brancharrow = null;

    @Override
    public Tree.Type_brancharrow brancharrow() {
      Tree.Type_brancharrow output = Tree.e_brancharrow;
      if (this.vx_p_brancharrow != null) {
        output = this.vx_p_brancharrow;
      }
      return output;
    }

    public Tree.Type_branchlist vx_p_branchlist = null;

    @Override
    public Tree.Type_branchlist branchlist() {
      Tree.Type_branchlist output = Tree.e_branchlist;
      if (this.vx_p_branchlist != null) {
        output = this.vx_p_branchlist;
      }
      return output;
    }

    public Tree.Type_leaflist vx_p_leaflist = null;

    @Override
    public Tree.Type_leaflist leaflist() {
      Tree.Type_leaflist output = Tree.e_leaflist;
      if (this.vx_p_leaflist != null) {
        output = this.vx_p_leaflist;
      }
      return output;
    }

    public Tree.Type_branch vx_p_parentbranch = null;

    @Override
    public Tree.Type_branch parentbranch() {
      Tree.Type_branch output = Tree.e_branch;
      if (this.vx_p_parentbranch != null) {
        output = this.vx_p_parentbranch;
      }
      return output;
    }

    public Tree.Type_tree vx_p_tree = null;

    @Override
    public Tree.Type_tree tree() {
      Tree.Type_tree output = Tree.e_tree;
      if (this.vx_p_tree != null) {
        output = this.vx_p_tree;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      case ":brancharrow":
        output = this.brancharrow();
        break;
      case ":branchlist":
        output = this.branchlist();
        break;
      case ":leaflist":
        output = this.leaflist();
        break;
      case ":parentbranch":
        output = this.parentbranch();
        break;
      case ":tree":
        output = this.tree();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<String, Core.Type_any>();
      output.put(":id", this.id());
      output.put(":brancharrow", this.brancharrow());
      output.put(":branchlist", this.branchlist());
      output.put(":leaflist", this.leaflist());
      output.put(":parentbranch", this.parentbranch());
      output.put(":tree", this.tree());
      return Core.immutablemap(output);
    }

    @Override
    public Tree.Type_branch vx_new(final Object... vals) {
      return Core.vx_copy(
       e_branch,
       vals);
    }

    @Override
    public Tree.Type_branch vx_copy(final Object... vals) {
      Type_branch output = this;
      boolean ischanged = false;
      Class_branch val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = val.id();
      Tree.Type_brancharrow vx_p_brancharrow = val.brancharrow();
      Tree.Type_branchlist vx_p_branchlist = val.branchlist();
      Tree.Type_leaflist vx_p_leaflist = val.leaflist();
      Tree.Type_branch vx_p_parentbranch = val.parentbranch();
      Tree.Type_tree vx_p_tree = val.tree();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":brancharrow");
      validkeys.add(":branchlist");
      validkeys.add(":leaflist");
      validkeys.add(":parentbranch");
      validkeys.add(":tree");
      String key = "";
      Core.Type_msg msg;
      Core.Type_any msgval;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
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
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/data/tree/branch", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/tree/branch", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_id = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/tree/branch", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":brancharrow":
            if (valsub == vx_p_brancharrow) {
            } else if (valsub instanceof Tree.Type_brancharrow) {
              ischanged = true;
              vx_p_brancharrow = (Tree.Type_brancharrow)valsub;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("brancharrow"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/tree/branch", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":branchlist":
            if (valsub == vx_p_branchlist) {
            } else if (valsub instanceof Tree.Type_branchlist) {
              ischanged = true;
              vx_p_branchlist = (Tree.Type_branchlist)valsub;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("branchlist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/tree/branch", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":leaflist":
            if (valsub == vx_p_leaflist) {
            } else if (valsub instanceof Tree.Type_leaflist) {
              ischanged = true;
              vx_p_leaflist = (Tree.Type_leaflist)valsub;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("leaflist"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/tree/branch", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":parentbranch":
            if (valsub == vx_p_parentbranch) {
            } else if (valsub instanceof Tree.Type_branch) {
              ischanged = true;
              vx_p_parentbranch = (Tree.Type_branch)valsub;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("parentbranch"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/tree/branch", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":tree":
            if (valsub == vx_p_tree) {
            } else if (valsub instanceof Tree.Type_tree) {
              ischanged = true;
              vx_p_tree = (Tree.Type_tree)valsub;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("tree"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/tree/branch", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/tree/branch", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_branch work = new Class_branch();
        work.vx_p_id = vx_p_id;
        work.vx_p_brancharrow = vx_p_brancharrow;
        work.vx_p_branchlist = vx_p_branchlist;
        work.vx_p_leaflist = vx_p_leaflist;
        work.vx_p_parentbranch = vx_p_parentbranch;
        work.vx_p_tree = vx_p_tree;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_branch;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_branch;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/tree", // pkgname
        "branch", // name
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

  public static final Type_branch e_branch = new Class_branch();
  public static final Type_branch t_branch = new Class_branch();

  /**
   * type: brancharrow
   * (type brancharrow)
   */
  public interface Type_brancharrow extends Core.Type_any {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
  }

  public static class Class_brancharrow extends Core.Class_base implements Type_brancharrow {

    @Override
    public Tree.Type_brancharrow vx_new(final Object... vals) {
      return Core.vx_copy(
       e_brancharrow,
       vals);
    }

    @Override
    public Tree.Type_brancharrow vx_copy(final Object... vals) {
      Type_brancharrow output = this;
      boolean ischanged = false;
      Class_brancharrow val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_brancharrow work = new Class_brancharrow();
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_brancharrow;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_brancharrow;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/tree", // pkgname
        "brancharrow", // name
        "", // extends
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

  public static final Type_brancharrow e_brancharrow = new Class_brancharrow();
  public static final Type_brancharrow t_brancharrow = new Class_brancharrow();

  /**
   * type: branchlist
   * (type branchlist)
   */
  public interface Type_branchlist extends Core.Type_list {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public List<Tree.Type_branch> vx_listbranch();
    public Tree.Type_branch vx_branch(final Core.Type_int index);
  }

  public static class Class_branchlist extends Core.Class_base implements Type_branchlist {

    public List<Tree.Type_branch> vx_p_list = Core.immutablelist(new ArrayList<Tree.Type_branch>());

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(
        new ArrayList<Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    @Override
    public Tree.Type_branch vx_branch(final Core.Type_int index) {
      Tree.Type_branch output = Tree.e_branch;
      Tree.Class_branchlist list = this;
      int iindex = index.vx_int();
      List<Tree.Type_branch> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Tree.Type_branch> vx_listbranch() {
      return vx_p_list;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_branch(index);
    }

    @Override
    public Tree.Type_branchlist vx_new(final Object... vals) {
      return Core.vx_copy(
       e_branchlist,
       vals);
    }

    @Override
    public Tree.Type_branchlist vx_copy(final Object... vals) {
      Type_branchlist output = this;
      boolean ischanged = false;
      Class_branchlist val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      List<Tree.Type_branch> listval = new ArrayList<Tree.Type_branch>(val.vx_listbranch());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Tree.Type_branch) {
          Tree.Type_branch allowsub = (Tree.Type_branch)valsub;;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Tree.Type_branch) {
          ischanged = true;
          listval.add((Tree.Type_branch)valsub);
        } else if (valsub instanceof Tree.Type_branchlist) {
          Type_branchlist multi = (Type_branchlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listbranch());
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;;
          for (Object item : listunknown) {
            if (item instanceof Tree.Type_branch) {
              Tree.Type_branch valitem = (Tree.Type_branch)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;;
          msg = Core.vx_msg_from_error("vx/data/tree/branchlist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/data/tree/branchlist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_branchlist work = new Class_branchlist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_branchlist;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_branchlist;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/tree", // pkgname
        "branchlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Tree.t_branch), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_branchlist e_branchlist = new Class_branchlist();
  public static final Type_branchlist t_branchlist = new Class_branchlist();

  /**
   * type: leaf
   * (type leaf)
   */
  public interface Type_leaf extends Core.Type_struct {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Core.Type_string id();
    public Core.Type_string name();
    public Core.Type_any value();
  }

  public static class Class_leaf extends Core.Class_base implements Type_leaf {

    public Core.Type_string vx_p_id = null;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Core.Type_string vx_p_name = null;

    @Override
    public Core.Type_string name() {
      Core.Type_string output = Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Core.Type_any vx_p_value = null;

    @Override
    public Core.Type_any value() {
      Core.Type_any output = Core.e_any;
      if (this.vx_p_value != null) {
        output = this.vx_p_value;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      case ":name":
        output = this.name();
        break;
      case ":value":
        output = this.value();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<String, Core.Type_any>();
      output.put(":id", this.id());
      output.put(":name", this.name());
      output.put(":value", this.value());
      return Core.immutablemap(output);
    }

    @Override
    public Tree.Type_leaf vx_new(final Object... vals) {
      return Core.vx_copy(
       e_leaf,
       vals);
    }

    @Override
    public Tree.Type_leaf vx_copy(final Object... vals) {
      Type_leaf output = this;
      boolean ischanged = false;
      Class_leaf val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = val.id();
      Core.Type_string vx_p_name = val.name();
      Core.Type_any vx_p_value = val.value();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":name");
      validkeys.add(":value");
      String key = "";
      Core.Type_msg msg;
      Core.Type_any msgval;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
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
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/data/tree/leaf", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/tree/leaf", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_id = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/tree/leaf", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/tree/leaf", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":value":
            if (valsub == vx_p_value) {
            } else if (valsub instanceof Core.Type_any) {
              ischanged = true;
              vx_p_value = (Core.Type_any)valsub;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("value"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/tree/leaf", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/tree/leaf", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_leaf work = new Class_leaf();
        work.vx_p_id = vx_p_id;
        work.vx_p_name = vx_p_name;
        work.vx_p_value = vx_p_value;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_leaf;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_leaf;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/tree", // pkgname
        "leaf", // name
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

  public static final Type_leaf e_leaf = new Class_leaf();
  public static final Type_leaf t_leaf = new Class_leaf();

  /**
   * type: leaflist
   * (type leaflist)
   */
  public interface Type_leaflist extends Core.Type_list {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public List<Tree.Type_leaf> vx_listleaf();
    public Tree.Type_leaf vx_leaf(final Core.Type_int index);
  }

  public static class Class_leaflist extends Core.Class_base implements Type_leaflist {

    public List<Tree.Type_leaf> vx_p_list = Core.immutablelist(new ArrayList<Tree.Type_leaf>());

    @Override
    public List<Core.Type_any> vx_list() {
      List<Core.Type_any> output = Core.immutablelist(
        new ArrayList<Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    @Override
    public Tree.Type_leaf vx_leaf(final Core.Type_int index) {
      Tree.Type_leaf output = Tree.e_leaf;
      Tree.Class_leaflist list = this;
      int iindex = index.vx_int();
      List<Tree.Type_leaf> listval = list.vx_p_list;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Tree.Type_leaf> vx_listleaf() {
      return vx_p_list;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_leaf(index);
    }

    @Override
    public Tree.Type_leaflist vx_new(final Object... vals) {
      return Core.vx_copy(
       e_leaflist,
       vals);
    }

    @Override
    public Tree.Type_leaflist vx_copy(final Object... vals) {
      Type_leaflist output = this;
      boolean ischanged = false;
      Class_leaflist val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      List<Tree.Type_leaf> listval = new ArrayList<Tree.Type_leaf>(val.vx_listleaf());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Tree.Type_leaf) {
          Tree.Type_leaf allowsub = (Tree.Type_leaf)valsub;;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Tree.Type_leaf) {
          ischanged = true;
          listval.add((Tree.Type_leaf)valsub);
        } else if (valsub instanceof Tree.Type_leaflist) {
          Type_leaflist multi = (Type_leaflist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listleaf());
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;;
          for (Object item : listunknown) {
            if (item instanceof Tree.Type_leaf) {
              Tree.Type_leaf valitem = (Tree.Type_leaf)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;;
          msg = Core.vx_msg_from_error("vx/data/tree/leaflist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/data/tree/leaflist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_leaflist work = new Class_leaflist();
        work.vx_p_list = Core.immutablelist(listval);
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_leaflist;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_leaflist;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/tree", // pkgname
        "leaflist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.vx_new(Core.t_typelist, Tree.t_leaf), // allowtypes
        Core.e_typelist, // disallowtypes
        Core.e_funclist, // allowfuncs
        Core.e_funclist, // disallowfuncs
        Core.e_anylist, // allowvalues
        Core.e_anylist, // disallowvalues
        Core.e_argmap // properties
      );
    }

  }

  public static final Type_leaflist e_leaflist = new Class_leaflist();
  public static final Type_leaflist t_leaflist = new Class_leaflist();

  /**
   * type: tree
   * (type tree)
   */
  public interface Type_tree extends Core.Type_struct {
    public Core.Type_any vx_new(final Object... vals);
    public Core.Type_any vx_copy(final Object... vals);
    public Core.Type_any vx_empty();
    public Core.Type_any vx_type();
    public Core.Type_string id();
    public Core.Type_string name();
    public Tree.Type_branch branch();
  }

  public static class Class_tree extends Core.Class_base implements Type_tree {

    public Core.Type_string vx_p_id = null;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      if (this.vx_p_id != null) {
        output = this.vx_p_id;
      }
      return output;
    }

    public Core.Type_string vx_p_name = null;

    @Override
    public Core.Type_string name() {
      Core.Type_string output = Core.e_string;
      if (this.vx_p_name != null) {
        output = this.vx_p_name;
      }
      return output;
    }

    public Tree.Type_branch vx_p_branch = null;

    @Override
    public Tree.Type_branch branch() {
      Tree.Type_branch output = Tree.e_branch;
      if (this.vx_p_branch != null) {
        output = this.vx_p_branch;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_string key) {
      Core.Type_any output = Core.e_any;
      String skey = key.vx_string();
      switch (skey) {
      case ":id":
        output = this.id();
        break;
      case ":name":
        output = this.name();
        break;
      case ":branch":
        output = this.branch();
        break;
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> output = new LinkedHashMap<String, Core.Type_any>();
      output.put(":id", this.id());
      output.put(":name", this.name());
      output.put(":branch", this.branch());
      return Core.immutablemap(output);
    }

    @Override
    public Tree.Type_tree vx_new(final Object... vals) {
      return Core.vx_copy(
       e_tree,
       vals);
    }

    @Override
    public Tree.Type_tree vx_copy(final Object... vals) {
      Type_tree output = this;
      boolean ischanged = false;
      Class_tree val = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(val, vals);
      if (this instanceof Core.vx_Type_const) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = val.id();
      Core.Type_string vx_p_name = val.name();
      Tree.Type_branch vx_p_branch = val.branch();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":name");
      validkeys.add(":branch");
      String key = "";
      Core.Type_msg msg;
      Core.Type_any msgval;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
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
            if (valsub instanceof Core.Type_any) {
              msgval = (Core.Type_any)valsub;
            } else {
              msgval = Core.vx_new_string(valsub.toString());
            }
            msg = Core.vx_msg_from_error("vx/data/tree/tree", ":invalidkeytype", msgval);
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
              msg = Core.vx_msg_from_error("vx/data/tree/tree", ":invalidkey", msgval);
              msgblock = Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_id = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/tree/tree", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":name":
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              ischanged = true;
              vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/tree/tree", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          case ":branch":
            if (valsub == vx_p_branch) {
            } else if (valsub instanceof Tree.Type_branch) {
              ischanged = true;
              vx_p_branch = (Tree.Type_branch)valsub;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;;
                msgval = valinvalid;
              } else {
                msgval = Core.vx_new_string(valsub.toString());
              }
              Map<String, Core.Type_any> mapany = new LinkedHashMap<String, Core.Type_any>();
              mapany.put("key", Core.vx_new_string("branch"));
              mapany.put("value", msgval);
              Core.Type_map msgmap = Core.t_anymap.vx_new_from_map(mapany);
              msg = Core.vx_msg_from_error("vx/data/tree/tree", ":invalidvalue", msgmap);
              msgblock = Core.vx_copy(msgblock, msg);
            }
            break;
          default:
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/tree/tree", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
            break;
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Class_tree work = new Class_tree();
        work.vx_p_id = vx_p_id;
        work.vx_p_name = vx_p_name;
        work.vx_p_branch = vx_p_branch;
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_tree;
    }
    @Override
    public Core.Type_any vx_type() {
      return t_tree;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/tree", // pkgname
        "tree", // name
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

  public static final Type_tree e_tree = new Class_tree();
  public static final Type_tree t_tree = new Class_tree();

  /**
   * Constant: brancharrow-down
   * {brancharrow}
   */
  public static class Const_brancharrow_down extends Tree.Class_brancharrow implements Core.vx_Type_const {
    
    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/data/tree", // pkgname
        "brancharrow-down", // name
        Core.typedef_new(
          "vx/data/tree", // pkgname
          "brancharrow", // name
          "", // extends
          Core.e_typelist, // traits
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

    public static void const_new(Const_brancharrow_down output) {
    }


  }

  public static final Const_brancharrow_down c_brancharrow_down = new Const_brancharrow_down();


  /**
   * Constant: brancharrow-up
   * {brancharrow}
   */
  public static class Const_brancharrow_up extends Tree.Class_brancharrow implements Core.vx_Type_const {
    
    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/data/tree", // pkgname
        "brancharrow-up", // name
        Core.typedef_new(
          "vx/data/tree", // pkgname
          "brancharrow", // name
          "", // extends
          Core.e_typelist, // traits
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

    public static void const_new(Const_brancharrow_up output) {
    }


  }

  public static final Const_brancharrow_up c_brancharrow_up = new Const_brancharrow_up();


  /**
   * Constant: brancharrow-updown
   * {brancharrow}
   */
  public static class Const_brancharrow_updown extends Tree.Class_brancharrow implements Core.vx_Type_const {
    
    @Override
    public Core.Type_constdef vx_constdef() {
      return Core.constdef_new(
        "vx/data/tree", // pkgname
        "brancharrow-updown", // name
        Core.typedef_new(
          "vx/data/tree", // pkgname
          "brancharrow", // name
          "", // extends
          Core.e_typelist, // traits
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

    public static void const_new(Const_brancharrow_updown output) {
    }


  }

  public static final Const_brancharrow_updown c_brancharrow_updown = new Const_brancharrow_updown();


  static {
    Const_brancharrow_down.const_new(c_brancharrow_down);
    Const_brancharrow_up.const_new(c_brancharrow_up);
    Const_brancharrow_updown.const_new(c_brancharrow_updown);
    Map<String, Core.Type_any> maptype = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<String, Core.Type_func>();
    maptype.put("branch", Tree.t_branch);
    maptype.put("brancharrow", Tree.t_brancharrow);
    maptype.put("branchlist", Tree.t_branchlist);
    maptype.put("leaf", Tree.t_leaf);
    maptype.put("leaflist", Tree.t_leaflist);
    maptype.put("tree", Tree.t_tree);
    mapconst.put("brancharrow-down", Tree.c_brancharrow_down);
    mapconst.put("brancharrow-up", Tree.c_brancharrow_up);
    mapconst.put("brancharrow-updown", Tree.c_brancharrow_updown);
    Core.vx_global_package_set("vx/data/tree", maptype, mapconst, mapfunc);
  }

}
