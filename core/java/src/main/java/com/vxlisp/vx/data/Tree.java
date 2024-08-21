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
      Core.Type_string testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Tree.Type_brancharrow vx_p_brancharrow = null;

    @Override
    public Tree.Type_brancharrow brancharrow() {
      Tree.Type_brancharrow output = Tree.e_brancharrow;
      Tree.Type_brancharrow testnull = vx_p_brancharrow;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Tree.Type_branchlist vx_p_branchlist = null;

    @Override
    public Tree.Type_branchlist branchlist() {
      Tree.Type_branchlist output = Tree.e_branchlist;
      Tree.Type_branchlist testnull = vx_p_branchlist;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Tree.Type_leaflist vx_p_leaflist = null;

    @Override
    public Tree.Type_leaflist leaflist() {
      Tree.Type_leaflist output = Tree.e_leaflist;
      Tree.Type_leaflist testnull = vx_p_leaflist;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Tree.Type_branch vx_p_parentbranch = null;

    @Override
    public Tree.Type_branch parentbranch() {
      Tree.Type_branch output = Tree.e_branch;
      Tree.Type_branch testnull = vx_p_parentbranch;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Tree.Type_tree vx_p_tree = null;

    @Override
    public Tree.Type_tree tree() {
      Tree.Type_tree output = Tree.e_tree;
      Tree.Type_tree testnull = vx_p_tree;
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
      } else if ((skey.equals(":id"))) {
        output = this.id();
      } else if ((skey.equals(":brancharrow"))) {
        output = this.brancharrow();
      } else if ((skey.equals(":branchlist"))) {
        output = this.branchlist();
      } else if ((skey.equals(":leaflist"))) {
        output = this.leaflist();
      } else if ((skey.equals(":parentbranch"))) {
        output = this.parentbranch();
      } else if ((skey.equals(":tree"))) {
        output = this.tree();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":id", this.id());
      map.put(":brancharrow", this.brancharrow());
      map.put(":branchlist", this.branchlist());
      map.put(":leaflist", this.leaflist());
      map.put(":parentbranch", this.parentbranch());
      map.put(":tree", this.tree());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Tree.Type_branch vx_new(final Object... vals) {
      Tree.Type_branch output = Core.vx_copy(Tree.e_branch, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Tree.Type_branch output = this;
      boolean ischanged = false;
      Tree.Class_branch value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = value.id();
      Tree.Type_brancharrow vx_p_brancharrow = value.brancharrow();
      Tree.Type_branchlist vx_p_branchlist = value.branchlist();
      Tree.Type_leaflist vx_p_leaflist = value.leaflist();
      Tree.Type_branch vx_p_parentbranch = value.parentbranch();
      Tree.Type_tree vx_p_tree = value.tree();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":brancharrow");
      validkeys.add(":branchlist");
      validkeys.add(":leaflist");
      validkeys.add(":parentbranch");
      validkeys.add(":tree");
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
          if (false) {
          } else if ((key.equals(":id"))) {
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valid = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":brancharrow"))) {
            if (valsub == vx_p_brancharrow) {
            } else if (valsub instanceof Tree.Type_brancharrow) {
              Tree.Type_brancharrow valbrancharrow = (Tree.Type_brancharrow)valsub;
              ischanged = true;
              vx_p_brancharrow = valbrancharrow;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":branchlist"))) {
            if (valsub == vx_p_branchlist) {
            } else if (valsub instanceof Tree.Type_branchlist) {
              Tree.Type_branchlist valbranchlist = (Tree.Type_branchlist)valsub;
              ischanged = true;
              vx_p_branchlist = valbranchlist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":leaflist"))) {
            if (valsub == vx_p_leaflist) {
            } else if (valsub instanceof Tree.Type_leaflist) {
              Tree.Type_leaflist valleaflist = (Tree.Type_leaflist)valsub;
              ischanged = true;
              vx_p_leaflist = valleaflist;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":parentbranch"))) {
            if (valsub == vx_p_parentbranch) {
            } else if (valsub instanceof Tree.Type_branch) {
              Tree.Type_branch valparentbranch = (Tree.Type_branch)valsub;
              ischanged = true;
              vx_p_parentbranch = valparentbranch;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":tree"))) {
            if (valsub == vx_p_tree) {
            } else if (valsub instanceof Tree.Type_tree) {
              Tree.Type_tree valtree = (Tree.Type_tree)valsub;
              ischanged = true;
              vx_p_tree = valtree;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/tree/branch", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Tree.Class_branch work = new Tree.Class_branch();
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
      Core.Type_any output = Tree.e_branch;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Tree.t_branch;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Tree.Type_branch e_branch = new Tree.Class_branch();
  public static final Tree.Type_branch t_branch = new Tree.Class_branch();

  /**
   * type: brancharrow
   * (type brancharrow)
   */
  public interface Type_brancharrow extends Core.Type_any {
  }

  public static class Class_brancharrow extends Core.Class_base implements Type_brancharrow {

    @Override
    public Tree.Type_brancharrow vx_new(final Object... vals) {
      Tree.Type_brancharrow output = Core.vx_copy(Tree.e_brancharrow, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Tree.Type_brancharrow output = this;
      boolean ischanged = false;
      Tree.Class_brancharrow value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Tree.Class_brancharrow work = new Tree.Class_brancharrow();
        if (msgblock != Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    @Override
    public Core.Type_any vx_empty() {
      Core.Type_any output = Tree.e_brancharrow;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Tree.t_brancharrow;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Tree.Type_brancharrow e_brancharrow = new Tree.Class_brancharrow();
  public static final Tree.Type_brancharrow t_brancharrow = new Tree.Class_brancharrow();

  /**
   * type: branchlist
   * (type branchlist)
   */
  public interface Type_branchlist extends Core.Type_list {
    public List<Tree.Type_branch> vx_listbranch();
    public Tree.Type_branch vx_branch(final Core.Type_int index);
  }

  public static class Class_branchlist extends Core.Class_base implements Type_branchlist {

    public List<Tree.Type_branch> vx_p_list = Core.immutablelist(
      new ArrayList<Tree.Type_branch>()
    );

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
      List<Tree.Type_branch> output = this.vx_p_list;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Tree.Type_branch output = this.vx_branch(index);
      return output;
    }

    @Override
    public Tree.Type_branchlist vx_new(final Object... vals) {
      Tree.Type_branchlist output = Core.vx_copy(Tree.e_branchlist, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Tree.Type_branchlist output = this;
      boolean ischanged = false;
      Tree.Class_branchlist value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      List<Tree.Type_branch> listval = new ArrayList<Tree.Type_branch>(value.vx_listbranch());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Tree.Type_branch) {
          Tree.Type_branch allowsub = (Tree.Type_branch)valsub;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Tree.Type_branch) {
          ischanged = true;
          listval.add((Tree.Type_branch)valsub);
        } else if (valsub instanceof Tree.Type_branchlist) {
          Tree.Type_branchlist multi = (Tree.Type_branchlist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listbranch());
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof Tree.Type_branch) {
              Tree.Type_branch valitem = (Tree.Type_branch)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/data/tree/branchlist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/data/tree/branchlist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Tree.Class_branchlist work = new Tree.Class_branchlist();
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
      Core.Type_any output = Tree.e_branchlist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Tree.t_branchlist;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Tree.Type_branchlist e_branchlist = new Tree.Class_branchlist();
  public static final Tree.Type_branchlist t_branchlist = new Tree.Class_branchlist();

  /**
   * type: leaf
   * (type leaf)
   */
  public interface Type_leaf extends Core.Type_struct {
    public Core.Type_string id();
    public Core.Type_string name();
    public Core.Type_any value();
  }

  public static class Class_leaf extends Core.Class_base implements Type_leaf {

    public Core.Type_string vx_p_id = null;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_string vx_p_name = null;

    @Override
    public Core.Type_string name() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_name;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_any vx_p_value = null;

    @Override
    public Core.Type_any value() {
      Core.Type_any output = Core.e_any;
      Core.Type_any testnull = vx_p_value;
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
      } else if ((skey.equals(":id"))) {
        output = this.id();
      } else if ((skey.equals(":name"))) {
        output = this.name();
      } else if ((skey.equals(":value"))) {
        output = this.value();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":id", this.id());
      map.put(":name", this.name());
      map.put(":value", this.value());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Tree.Type_leaf vx_new(final Object... vals) {
      Tree.Type_leaf output = Core.vx_copy(Tree.e_leaf, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Tree.Type_leaf output = this;
      boolean ischanged = false;
      Tree.Class_leaf value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = value.id();
      Core.Type_string vx_p_name = value.name();
      Core.Type_any vx_p_value = value.value();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":name");
      validkeys.add(":value");
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
          if (false) {
          } else if ((key.equals(":id"))) {
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valid = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":name"))) {
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valname = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":value"))) {
            if (valsub == vx_p_value) {
            } else if (valsub instanceof Core.Type_any) {
              Core.Type_any valvalue = (Core.Type_any)valsub;
              ischanged = true;
              vx_p_value = valvalue;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/tree/leaf", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Tree.Class_leaf work = new Tree.Class_leaf();
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
      Core.Type_any output = Tree.e_leaf;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Tree.t_leaf;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Tree.Type_leaf e_leaf = new Tree.Class_leaf();
  public static final Tree.Type_leaf t_leaf = new Tree.Class_leaf();

  /**
   * type: leaflist
   * (type leaflist)
   */
  public interface Type_leaflist extends Core.Type_list {
    public List<Tree.Type_leaf> vx_listleaf();
    public Tree.Type_leaf vx_leaf(final Core.Type_int index);
  }

  public static class Class_leaflist extends Core.Class_base implements Type_leaflist {

    public List<Tree.Type_leaf> vx_p_list = Core.immutablelist(
      new ArrayList<Tree.Type_leaf>()
    );

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
      List<Tree.Type_leaf> output = this.vx_p_list;
      return output;
    }

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      Tree.Type_leaf output = this.vx_leaf(index);
      return output;
    }

    @Override
    public Tree.Type_leaflist vx_new(final Object... vals) {
      Tree.Type_leaflist output = Core.vx_copy(Tree.e_leaflist, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Tree.Type_leaflist output = this;
      boolean ischanged = false;
      Tree.Class_leaflist value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      List<Tree.Type_leaf> listval = new ArrayList<Tree.Type_leaf>(value.vx_listleaf());
      Core.Type_msg msg;
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = Core.vx_copy(msgblock, valsub);
        } else if (valsub instanceof Tree.Type_leaf) {
          Tree.Type_leaf allowsub = (Tree.Type_leaf)valsub;
          ischanged = true;
          listval.add(allowsub);
        } else if (valsub instanceof Tree.Type_leaf) {
          ischanged = true;
          listval.add((Tree.Type_leaf)valsub);
        } else if (valsub instanceof Tree.Type_leaflist) {
          Tree.Type_leaflist multi = (Tree.Type_leaflist)valsub;
          ischanged = true;
          listval.addAll(multi.vx_listleaf());
        } else if (valsub instanceof List<?>) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (false) {
            } else if (item instanceof Tree.Type_leaf) {
              Tree.Type_leaf valitem = (Tree.Type_leaf)item;
              ischanged = true;
              listval.add(valitem);
            }
          }
        } else if (valsub instanceof Core.Type_any) {
          Core.Type_any anyinvalid = (Core.Type_any)valsub;
          msg = Core.vx_msg_from_error("vx/data/tree/leaflist", ":invalidtype", anyinvalid);
          msgblock = Core.vx_copy(msgblock, msg);
        } else {
          msg = Core.vx_msg_from_error("vx/data/tree/leaflist", ":invalidtype", Core.vx_new_string(valsub.toString()));
          msgblock = Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Tree.Class_leaflist work = new Tree.Class_leaflist();
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
      Core.Type_any output = Tree.e_leaflist;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Tree.t_leaflist;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Tree.Type_leaflist e_leaflist = new Tree.Class_leaflist();
  public static final Tree.Type_leaflist t_leaflist = new Tree.Class_leaflist();

  /**
   * type: tree
   * (type tree)
   */
  public interface Type_tree extends Core.Type_struct {
    public Core.Type_string id();
    public Core.Type_string name();
    public Tree.Type_branch branch();
  }

  public static class Class_tree extends Core.Class_base implements Type_tree {

    public Core.Type_string vx_p_id = null;

    @Override
    public Core.Type_string id() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Core.Type_string vx_p_name = null;

    @Override
    public Core.Type_string name() {
      Core.Type_string output = Core.e_string;
      Core.Type_string testnull = vx_p_name;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Tree.Type_branch vx_p_branch = null;

    @Override
    public Tree.Type_branch branch() {
      Tree.Type_branch output = Tree.e_branch;
      Tree.Type_branch testnull = vx_p_branch;
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
      } else if ((skey.equals(":id"))) {
        output = this.id();
      } else if ((skey.equals(":name"))) {
        output = this.name();
      } else if ((skey.equals(":branch"))) {
        output = this.branch();
      }
      return output;
    }

    @Override
    public Map<String, Core.Type_any> vx_map() {
      Map<String, Core.Type_any> map = new LinkedHashMap<String, Core.Type_any>();
      map.put(":id", this.id());
      map.put(":name", this.name());
      map.put(":branch", this.branch());
      Map<String, Core.Type_any> output = Core.immutablemap(map);
      return output;
    }

    @Override
    public Tree.Type_tree vx_new(final Object... vals) {
      Tree.Type_tree output = Core.vx_copy(Tree.e_tree, vals);
      return output;
    }

    @Override
    public Core.Type_any vx_copy(final Object... vals) {
      Tree.Type_tree output = this;
      boolean ischanged = false;
      Tree.Class_tree value = this;
      Core.Type_msgblock msgblock = Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Core.e_constdef) {
        ischanged = true;
      }
      Core.Type_string vx_p_id = value.id();
      Core.Type_string vx_p_name = value.name();
      Tree.Type_branch vx_p_branch = value.branch();
      List<String> validkeys = new ArrayList<String>();
      validkeys.add(":id");
      validkeys.add(":name");
      validkeys.add(":branch");
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
          if (false) {
          } else if ((key.equals(":id"))) {
            if (valsub == vx_p_id) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valid = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_id = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":name"))) {
            if (valsub == vx_p_name) {
            } else if (valsub instanceof Core.Type_string) {
              Core.Type_string valname = (Core.Type_string)valsub;
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub instanceof String) {
              ischanged = true;
              vx_p_name = Core.vx_new(Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else if ((key.equals(":branch"))) {
            if (valsub == vx_p_branch) {
            } else if (valsub instanceof Tree.Type_branch) {
              Tree.Type_branch valbranch = (Tree.Type_branch)valsub;
              ischanged = true;
              vx_p_branch = valbranch;
            } else {
              if (false) {
              } else if (valsub instanceof Core.Type_any) {
                Core.Type_any valinvalid = (Core.Type_any)valsub;
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
          } else {
            msgval = Core.vx_new_string(key);
            msg = Core.vx_msg_from_error("vx/data/tree/tree", ":invalidkey", msgval);
            msgblock = Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Core.e_msgblock)) {
        Tree.Class_tree work = new Tree.Class_tree();
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
      Core.Type_any output = Tree.e_tree;
      return output;
    }

    @Override
    public Core.Type_any vx_type() {
      Core.Type_any output = Tree.t_tree;
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      Core.Type_typedef output = Core.typedef_new(
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
      return output;
    }

  }

  public static final Tree.Type_tree e_tree = new Tree.Class_tree();
  public static final Tree.Type_tree t_tree = new Tree.Class_tree();

  /**
   * Constant: brancharrow-down
   * {brancharrow}
   */
  public static class Const_brancharrow_down {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Tree.Type_brancharrow output) {
      Tree.Class_brancharrow outval = (Tree.Class_brancharrow)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Tree.Type_brancharrow c_brancharrow_down = new Tree.Class_brancharrow();


  /**
   * Constant: brancharrow-up
   * {brancharrow}
   */
  public static class Const_brancharrow_up {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Tree.Type_brancharrow output) {
      Tree.Class_brancharrow outval = (Tree.Class_brancharrow)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Tree.Type_brancharrow c_brancharrow_up = new Tree.Class_brancharrow();


  /**
   * Constant: brancharrow-updown
   * {brancharrow}
   */
  public static class Const_brancharrow_updown {
    public static Core.Type_constdef constdef() {
      Core.Type_constdef output = Core.constdef_new(
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
      return output;
    }

    public static void const_new(Tree.Type_brancharrow output) {
      Tree.Class_brancharrow outval = (Tree.Class_brancharrow)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static final Tree.Type_brancharrow c_brancharrow_updown = new Tree.Class_brancharrow();


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
