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
    public Tree.Type_branch vx_new(final Object... vals);
    public Tree.Type_branch vx_copy(final Object... vals);
    public Tree.Type_branch vx_empty();
    public Tree.Type_branch vx_type();
    public Core.Type_string id();
    public Tree.Type_brancharrow brancharrow();
    public Tree.Type_branchlist branchlist();
    public Tree.Type_leaflist leaflist();
    public Tree.Type_branch parentbranch();
    public Tree.Type_tree tree();
  }

  public static class Class_branch extends Core.Class_base implements Type_branch {

    protected Core.Type_string vx_p_id;

    @Override
    public Core.Type_string id() {
      return this.vx_p_id == null ? Core.e_string : this.vx_p_id;
    }

    protected Tree.Type_brancharrow vx_p_brancharrow;

    @Override
    public Tree.Type_brancharrow brancharrow() {
      return this.vx_p_brancharrow == null ? Tree.e_brancharrow : this.vx_p_brancharrow;
    }

    protected Tree.Type_branchlist vx_p_branchlist;

    @Override
    public Tree.Type_branchlist branchlist() {
      return this.vx_p_branchlist == null ? Tree.e_branchlist : this.vx_p_branchlist;
    }

    protected Tree.Type_leaflist vx_p_leaflist;

    @Override
    public Tree.Type_leaflist leaflist() {
      return this.vx_p_leaflist == null ? Tree.e_leaflist : this.vx_p_leaflist;
    }

    protected Tree.Type_branch vx_p_parentbranch;

    @Override
    public Tree.Type_branch parentbranch() {
      return this.vx_p_parentbranch == null ? Tree.e_branch : this.vx_p_parentbranch;
    }

    protected Tree.Type_tree vx_p_tree;

    @Override
    public Tree.Type_tree tree() {
      return this.vx_p_tree == null ? Tree.e_tree : this.vx_p_tree;
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
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":id", this.id());
      output.put(":brancharrow", this.brancharrow());
      output.put(":branchlist", this.branchlist());
      output.put(":leaflist", this.leaflist());
      output.put(":parentbranch", this.parentbranch());
      output.put(":tree", this.tree());
      return Core.immutablemap(output);
    }

    @Override
    public Type_branch vx_new(final Object... vals) {return e_branch.vx_copy(vals);}

    @Override
    public Type_branch vx_copy(final Object... vals) {
      Class_branch output = new Class_branch();
      Type_branch val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_id = val.id();
      output.vx_p_brancharrow = val.brancharrow();
      output.vx_p_branchlist = val.branchlist();
      output.vx_p_leaflist = val.leaflist();
      output.vx_p_parentbranch = val.parentbranch();
      output.vx_p_tree = val.tree();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":id");
      validkeys.add(":brancharrow");
      validkeys.add(":branchlist");
      validkeys.add(":leaflist");
      validkeys.add(":parentbranch");
      validkeys.add(":tree");
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new branch) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_id = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_id = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new branch :id " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":brancharrow":
            if (valsub instanceof Tree.Type_brancharrow) {
              output.vx_p_brancharrow = (Tree.Type_brancharrow)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new branch :brancharrow " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":branchlist":
            if (valsub instanceof Tree.Type_branchlist) {
              output.vx_p_branchlist = (Tree.Type_branchlist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new branch :branchlist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":leaflist":
            if (valsub instanceof Tree.Type_leaflist) {
              output.vx_p_leaflist = (Tree.Type_leaflist)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new branch :leaflist " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":parentbranch":
            if (valsub instanceof Tree.Type_branch) {
              output.vx_p_parentbranch = (Tree.Type_branch)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new branch :parentbranch " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":tree":
            if (valsub instanceof Tree.Type_tree) {
              output.vx_p_tree = (Tree.Type_tree)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new branch :tree " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new branch) - Invalid Key: " + key);
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
    public Type_branch vx_empty() {return e_branch;}
    @Override
    public Type_branch vx_type() {return t_branch;}

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
    public Tree.Type_brancharrow vx_new(final Object... vals);
    public Tree.Type_brancharrow vx_copy(final Object... vals);
    public Tree.Type_brancharrow vx_empty();
    public Tree.Type_brancharrow vx_type();
  }

  public static class Class_brancharrow extends Core.Class_base implements Type_brancharrow {

    @Override
    public Type_brancharrow vx_new(final Object... vals) {return e_brancharrow.vx_copy(vals);}

    @Override
    public Type_brancharrow vx_copy(final Object... vals) {
      Class_brancharrow output = new Class_brancharrow();
      return output;
    }

    @Override
    public Type_brancharrow vx_empty() {return e_brancharrow;}
    @Override
    public Type_brancharrow vx_type() {return t_brancharrow;}

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
    public Tree.Type_branchlist vx_new(final Object... vals);
    public Tree.Type_branchlist vx_copy(final Object... vals);
    public Tree.Type_branchlist vx_empty();
    public Tree.Type_branchlist vx_type();
    public List<Tree.Type_branch> vx_listbranch();
    public Tree.Type_branch vx_branch(final Core.Type_int index);
  }

  public static class Class_branchlist extends Core.Class_base implements Type_branchlist {

    protected List<Tree.Type_branch> vxlist = Core.immutablelist(new ArrayList<Tree.Type_branch>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Tree.Type_branch vx_branch(final Core.Type_int index) {
      Tree.Type_branch output = Tree.e_branch;
      Class_branchlist list = this;
      int iindex = index.vx_int();
      List<Tree.Type_branch> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Tree.Type_branch> vx_listbranch() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_branch(index);
    }

    @Override
    public Type_branchlist vx_new(final Object... vals) {return e_branchlist.vx_copy(vals);}

    @Override
    public Type_branchlist vx_copy(final Object... vals) {
      Class_branchlist output = new Class_branchlist();
      Type_branchlist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Tree.Type_branch> listval = new ArrayList<>(val.vx_listbranch());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Tree.Type_branch) {
          listval.add((Tree.Type_branch)valsub);
        } else if (valsub instanceof Tree.Type_branch) {
          listval.add((Tree.Type_branch)valsub);
        } else if (valsub instanceof Type_branchlist) {
          Type_branchlist multi = (Type_branchlist)valsub;
          listval.addAll(multi.vx_listbranch());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Tree.Type_branch) {
              Tree.Type_branch valitem = (Tree.Type_branch)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new branchlist) - Invalid Type: " + valsub.toString());
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
    public Type_branchlist vx_empty() {return e_branchlist;}
    @Override
    public Type_branchlist vx_type() {return t_branchlist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/tree", // pkgname
        "branchlist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Tree.t_branch), // allowtypes
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
    public Tree.Type_leaf vx_new(final Object... vals);
    public Tree.Type_leaf vx_copy(final Object... vals);
    public Tree.Type_leaf vx_empty();
    public Tree.Type_leaf vx_type();
    public Core.Type_string id();
    public Core.Type_string name();
    public Core.Type_any value();
  }

  public static class Class_leaf extends Core.Class_base implements Type_leaf {

    protected Core.Type_string vx_p_id;

    @Override
    public Core.Type_string id() {
      return this.vx_p_id == null ? Core.e_string : this.vx_p_id;
    }

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Core.Type_any vx_p_value;

    @Override
    public Core.Type_any value() {
      return this.vx_p_value == null ? Core.e_any : this.vx_p_value;
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
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":id", this.id());
      output.put(":name", this.name());
      output.put(":value", this.value());
      return Core.immutablemap(output);
    }

    @Override
    public Type_leaf vx_new(final Object... vals) {return e_leaf.vx_copy(vals);}

    @Override
    public Type_leaf vx_copy(final Object... vals) {
      Class_leaf output = new Class_leaf();
      Type_leaf val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_id = val.id();
      output.vx_p_name = val.name();
      output.vx_p_value = val.value();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":id");
      validkeys.add(":name");
      validkeys.add(":value");
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new leaf) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_id = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_id = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new leaf :id " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new leaf :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":value":
            if (valsub instanceof Core.Type_any) {
              output.vx_p_value = (Core.Type_any)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new leaf :value " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new leaf) - Invalid Key: " + key);
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
    public Type_leaf vx_empty() {return e_leaf;}
    @Override
    public Type_leaf vx_type() {return t_leaf;}

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
    public Tree.Type_leaflist vx_new(final Object... vals);
    public Tree.Type_leaflist vx_copy(final Object... vals);
    public Tree.Type_leaflist vx_empty();
    public Tree.Type_leaflist vx_type();
    public List<Tree.Type_leaf> vx_listleaf();
    public Tree.Type_leaf vx_leaf(final Core.Type_int index);
  }

  public static class Class_leaflist extends Core.Class_base implements Type_leaflist {

    protected List<Tree.Type_leaf> vxlist = Core.immutablelist(new ArrayList<Tree.Type_leaf>());

    @Override
    public List<Core.Type_any> vx_list() {return Core.immutablelist(new ArrayList<Core.Type_any>(this.vxlist));}

    @Override
    public Tree.Type_leaf vx_leaf(final Core.Type_int index) {
      Tree.Type_leaf output = Tree.e_leaf;
      Class_leaflist list = this;
      int iindex = index.vx_int();
      List<Tree.Type_leaf> listval = list.vxlist;
      if (iindex < listval.size()) {
        output = listval.get(iindex);
      }
      return output;
    }

    @Override
    public List<Tree.Type_leaf> vx_listleaf() {return vxlist;}

    @Override
    public Core.Type_any vx_any(final Core.Type_int index) {
      return this.vx_leaf(index);
    }

    @Override
    public Type_leaflist vx_new(final Object... vals) {return e_leaflist.vx_copy(vals);}

    @Override
    public Type_leaflist vx_copy(final Object... vals) {
      Class_leaflist output = new Class_leaflist();
      Type_leaflist val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      List<Tree.Type_leaf> listval = new ArrayList<>(val.vx_listleaf());
      for (Object valsub : vals) {
        if (valsub instanceof Core.Type_msgblock) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Core.Type_msg) {
          msgblock = msgblock.vx_copy(valsub);
        } else if (valsub instanceof Tree.Type_leaf) {
          listval.add((Tree.Type_leaf)valsub);
        } else if (valsub instanceof Tree.Type_leaf) {
          listval.add((Tree.Type_leaf)valsub);
        } else if (valsub instanceof Type_leaflist) {
          Type_leaflist multi = (Type_leaflist)valsub;
          listval.addAll(multi.vx_listleaf());
        } else if (valsub instanceof List) {
          List<?> listunknown = (List<?>)valsub;
          for (Object item : listunknown) {
            if (item instanceof Tree.Type_leaf) {
              Tree.Type_leaf valitem = (Tree.Type_leaf)item;
              listval.add(valitem);
            }
          }
        } else {
          Core.Type_msg msg = Core.t_msg.vx_new_error("(new leaflist) - Invalid Type: " + valsub.toString());
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
    public Type_leaflist vx_empty() {return e_leaflist;}
    @Override
    public Type_leaflist vx_type() {return t_leaflist;}

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.typedef_new(
        "vx/data/tree", // pkgname
        "leaflist", // name
        ":list", // extends
        Core.e_typelist, // traits
        Core.t_typelist.vx_new(Tree.t_leaf), // allowtypes
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
    public Tree.Type_tree vx_new(final Object... vals);
    public Tree.Type_tree vx_copy(final Object... vals);
    public Tree.Type_tree vx_empty();
    public Tree.Type_tree vx_type();
    public Core.Type_string id();
    public Core.Type_string name();
    public Tree.Type_branch branch();
  }

  public static class Class_tree extends Core.Class_base implements Type_tree {

    protected Core.Type_string vx_p_id;

    @Override
    public Core.Type_string id() {
      return this.vx_p_id == null ? Core.e_string : this.vx_p_id;
    }

    protected Core.Type_string vx_p_name;

    @Override
    public Core.Type_string name() {
      return this.vx_p_name == null ? Core.e_string : this.vx_p_name;
    }

    protected Tree.Type_branch vx_p_branch;

    @Override
    public Tree.Type_branch branch() {
      return this.vx_p_branch == null ? Tree.e_branch : this.vx_p_branch;
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
      Map<String, Core.Type_any> output = new LinkedHashMap<>();
      output.put(":id", this.id());
      output.put(":name", this.name());
      output.put(":branch", this.branch());
      return Core.immutablemap(output);
    }

    @Override
    public Type_tree vx_new(final Object... vals) {return e_tree.vx_copy(vals);}

    @Override
    public Type_tree vx_copy(final Object... vals) {
      Class_tree output = new Class_tree();
      Type_tree val = this;
      Core.Type_msgblock msgblock = Core.t_msgblock.vx_msgblock_from_copy_arrayval(val, vals);
      output.vx_p_id = val.id();
      output.vx_p_name = val.name();
      output.vx_p_branch = val.branch();
      ArrayList<String> validkeys = new ArrayList<>();
      validkeys.add(":id");
      validkeys.add(":name");
      validkeys.add(":branch");
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
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new tree) - Invalid Key Type: " + valsub.toString());
            msgblock = msgblock.vx_copy(msg);
          }
        } else {
          switch (key) {
          case ":id":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_id = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_id = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new tree :id " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":name":
            if (valsub instanceof Core.Type_string) {
              output.vx_p_name = (Core.Type_string)valsub;
            } else if (valsub instanceof String) {
              output.vx_p_name = Core.t_string.vx_new(valsub);
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new tree :name " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          case ":branch":
            if (valsub instanceof Tree.Type_branch) {
              output.vx_p_branch = (Tree.Type_branch)valsub;
            } else {
              Core.Type_msg msg = Core.t_msg.vx_new_error("(new tree :branch " + valsub.toString() + ") - Invalid Value");
              msgblock = msgblock.vx_copy(msg);
            }
            break;
          default:
            Core.Type_msg msg = Core.t_msg.vx_new_error("(new tree) - Invalid Key: " + key);
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
    public Type_tree vx_empty() {return e_tree;}
    @Override
    public Type_tree vx_type() {return t_tree;}

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
  public static class Const_brancharrow_down extends Tree.Class_brancharrow {

    public Core.Type_constdef constdef() {
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

    public static Const_brancharrow_down const_new() {
      Const_brancharrow_down output = new Const_brancharrow_down();
      return output;
    }


  }

  public static final Const_brancharrow_down c_brancharrow_down = Const_brancharrow_down.const_new();


  /**
   * Constant: brancharrow-up
   * {brancharrow}
   */
  public static class Const_brancharrow_up extends Tree.Class_brancharrow {

    public Core.Type_constdef constdef() {
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

    public static Const_brancharrow_up const_new() {
      Const_brancharrow_up output = new Const_brancharrow_up();
      return output;
    }


  }

  public static final Const_brancharrow_up c_brancharrow_up = Const_brancharrow_up.const_new();


  /**
   * Constant: brancharrow-updown
   * {brancharrow}
   */
  public static class Const_brancharrow_updown extends Tree.Class_brancharrow {

    public Core.Type_constdef constdef() {
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

    public static Const_brancharrow_updown const_new() {
      Const_brancharrow_updown output = new Const_brancharrow_updown();
      return output;
    }


  }

  public static final Const_brancharrow_updown c_brancharrow_updown = Const_brancharrow_updown.const_new();


}
