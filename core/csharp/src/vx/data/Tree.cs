namespace Vx.Data;

public static class Tree {


  /**
   * type: branch
   * (type branch)
   */
  public interface Type_branch : Vx.Core.Type_struct {
    public Vx.Core.Type_string id();
    public Vx.Data.Tree.Type_brancharrow brancharrow();
    public Vx.Data.Tree.Type_branchlist branchlist();
    public Vx.Data.Tree.Type_leaflist leaflist();
    public Vx.Data.Tree.Type_branch parentbranch();
    public Vx.Data.Tree.Type_tree tree();
  }

  public class Class_branch : Vx.Core.Class_base, Type_branch {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Core.Type_string? testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Tree.Type_brancharrow? vx_p_brancharrow = null;

    public Vx.Data.Tree.Type_brancharrow brancharrow() {
      Vx.Data.Tree.Type_brancharrow output = Vx.Data.Tree.e_brancharrow;
      Vx.Data.Tree.Type_brancharrow? testnull = vx_p_brancharrow;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Tree.Type_branchlist? vx_p_branchlist = null;

    public Vx.Data.Tree.Type_branchlist branchlist() {
      Vx.Data.Tree.Type_branchlist output = Vx.Data.Tree.e_branchlist;
      Vx.Data.Tree.Type_branchlist? testnull = vx_p_branchlist;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Tree.Type_leaflist? vx_p_leaflist = null;

    public Vx.Data.Tree.Type_leaflist leaflist() {
      Vx.Data.Tree.Type_leaflist output = Vx.Data.Tree.e_leaflist;
      Vx.Data.Tree.Type_leaflist? testnull = vx_p_leaflist;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Tree.Type_branch? vx_p_parentbranch = null;

    public Vx.Data.Tree.Type_branch parentbranch() {
      Vx.Data.Tree.Type_branch output = Vx.Data.Tree.e_branch;
      Vx.Data.Tree.Type_branch? testnull = vx_p_parentbranch;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Tree.Type_tree? vx_p_tree = null;

    public Vx.Data.Tree.Type_tree tree() {
      Vx.Data.Tree.Type_tree output = Vx.Data.Tree.e_tree;
      Vx.Data.Tree.Type_tree? testnull = vx_p_tree;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      if (false) {
      } else if ((skey==":id")) {
        output = this.id();
      } else if ((skey==":brancharrow")) {
        output = this.brancharrow();
      } else if ((skey==":branchlist")) {
        output = this.branchlist();
      } else if ((skey==":leaflist")) {
        output = this.leaflist();
      } else if ((skey==":parentbranch")) {
        output = this.parentbranch();
      } else if ((skey==":tree")) {
        output = this.tree();
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      map.put(":id", this.id());
      map.put(":brancharrow", this.brancharrow());
      map.put(":branchlist", this.branchlist());
      map.put(":leaflist", this.leaflist());
      map.put(":parentbranch", this.parentbranch());
      map.put(":tree", this.tree());
      Vx.Core.Map<string, Vx.Core.Type_any> output = Vx.Core.immutablemap(map);
      return output;
    }

    public override Vx.Data.Tree.Type_branch vx_new(params object[] vals) {
      Vx.Data.Tree.Type_branch output = Vx.Core.vx_copy(Vx.Data.Tree.e_branch, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Tree.Type_branch output = this;
      bool ischanged = false;
      Vx.Data.Tree.Class_branch value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = value.id();
      Vx.Data.Tree.Type_brancharrow vx_p_brancharrow = value.brancharrow();
      Vx.Data.Tree.Type_branchlist vx_p_branchlist = value.branchlist();
      Vx.Data.Tree.Type_leaflist vx_p_leaflist = value.leaflist();
      Vx.Data.Tree.Type_branch vx_p_parentbranch = value.parentbranch();
      Vx.Data.Tree.Type_tree vx_p_tree = value.tree();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":brancharrow");
      validkeys.Add(":branchlist");
      validkeys.Add(":leaflist");
      validkeys.Add(":parentbranch");
      validkeys.Add(":tree");
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
            msg = Vx.Core.vx_msg_from_error("vx/data/tree/branch", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/data/tree/branch", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key==":id")) {
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string valid) {
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/tree/branch", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":brancharrow")) {
            if (valsub == vx_p_brancharrow) {
            } else if (valsub is Vx.Data.Tree.Type_brancharrow valbrancharrow) {
              ischanged = true;
              vx_p_brancharrow = valbrancharrow;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("brancharrow"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/tree/branch", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":branchlist")) {
            if (valsub == vx_p_branchlist) {
            } else if (valsub is Vx.Data.Tree.Type_branchlist valbranchlist) {
              ischanged = true;
              vx_p_branchlist = valbranchlist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("branchlist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/tree/branch", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":leaflist")) {
            if (valsub == vx_p_leaflist) {
            } else if (valsub is Vx.Data.Tree.Type_leaflist valleaflist) {
              ischanged = true;
              vx_p_leaflist = valleaflist;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("leaflist"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/tree/branch", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":parentbranch")) {
            if (valsub == vx_p_parentbranch) {
            } else if (valsub is Vx.Data.Tree.Type_branch valparentbranch) {
              ischanged = true;
              vx_p_parentbranch = valparentbranch;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("parentbranch"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/tree/branch", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":tree")) {
            if (valsub == vx_p_tree) {
            } else if (valsub is Vx.Data.Tree.Type_tree valtree) {
              ischanged = true;
              vx_p_tree = valtree;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("tree"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/tree/branch", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/tree/branch", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Tree.Class_branch work = new Vx.Data.Tree.Class_branch();
        work.vx_p_id = vx_p_id;
        work.vx_p_brancharrow = vx_p_brancharrow;
        work.vx_p_branchlist = vx_p_branchlist;
        work.vx_p_leaflist = vx_p_leaflist;
        work.vx_p_parentbranch = vx_p_parentbranch;
        work.vx_p_tree = vx_p_tree;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Tree.e_branch;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Tree.t_branch;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/data/tree", // pkgname
        "branch", // name
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

  public static Vx.Data.Tree.Type_branch e_branch = new Vx.Data.Tree.Class_branch();
  public static Vx.Data.Tree.Type_branch t_branch = new Vx.Data.Tree.Class_branch();

  /**
   * type: brancharrow
   * (type brancharrow)
   */
  public interface Type_brancharrow : Vx.Core.Type_any {
  }

  public class Class_brancharrow : Vx.Core.Class_base, Type_brancharrow {

    public override Vx.Data.Tree.Type_brancharrow vx_new(params object[] vals) {
      Vx.Data.Tree.Type_brancharrow output = Vx.Core.vx_copy(Vx.Data.Tree.e_brancharrow, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Tree.Type_brancharrow output = this;
      bool ischanged = false;
      Vx.Data.Tree.Class_brancharrow value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Tree.Class_brancharrow work = new Vx.Data.Tree.Class_brancharrow();
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Tree.e_brancharrow;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Tree.t_brancharrow;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/data/tree", // pkgname
        "brancharrow", // name
        "", // extends
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

  public static Vx.Data.Tree.Type_brancharrow e_brancharrow = new Vx.Data.Tree.Class_brancharrow();
  public static Vx.Data.Tree.Type_brancharrow t_brancharrow = new Vx.Data.Tree.Class_brancharrow();

  /**
   * type: branchlist
   * (type branchlist)
   */
  public interface Type_branchlist : Vx.Core.Type_list {
    public List<Vx.Data.Tree.Type_branch> vx_listbranch();
    public Vx.Data.Tree.Type_branch vx_branch(Vx.Core.Type_int index);
  }

  public class Class_branchlist : Vx.Core.Class_base, Type_branchlist {

    public List<Vx.Data.Tree.Type_branch> vx_p_list = Vx.Core.immutablelist(
      new List<Vx.Data.Tree.Type_branch>()
    );

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Data.Tree.Type_branch vx_branch(Vx.Core.Type_int index) {
      Vx.Data.Tree.Type_branch output = Vx.Data.Tree.e_branch;
      Vx.Data.Tree.Class_branchlist list = this;
      int iindex = index.vx_int();
      List<Vx.Data.Tree.Type_branch> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Data.Tree.Type_branch> vx_listbranch() {
      List<Vx.Data.Tree.Type_branch> output = this.vx_p_list;
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      Vx.Data.Tree.Type_branch output = this.vx_branch(index);
      return output;
    }

    public override Vx.Data.Tree.Type_branchlist vx_new(params object[] vals) {
      Vx.Data.Tree.Type_branchlist output = Vx.Core.vx_copy(Vx.Data.Tree.e_branchlist, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Tree.Type_branchlist output = this;
      bool ischanged = false;
      Vx.Data.Tree.Class_branchlist value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      List<Vx.Data.Tree.Type_branch> listval = new List<Vx.Data.Tree.Type_branch>(value.vx_listbranch());
      Vx.Core.Type_msg msg;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Data.Tree.Type_branch allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Data.Tree.Type_branch) {
          ischanged = true;
          listval.Add((Vx.Data.Tree.Type_branch)valsub);
        } else if (valsub is Vx.Data.Tree.Type_branchlist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listbranch());
        } else if (valsub is List<Vx.Core.Type_any> listany) {
          foreach (Vx.Core.Type_any item in listany) {
            if (false) {
            } else if (item is Vx.Data.Tree.Type_branch valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/data/tree/branchlist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/data/tree/branchlist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Tree.Class_branchlist work = new Vx.Data.Tree.Class_branchlist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Tree.e_branchlist;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Tree.t_branchlist;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/data/tree", // pkgname
        "branchlist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Data.Tree.t_branch), // allowtypes
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

  public static Vx.Data.Tree.Type_branchlist e_branchlist = new Vx.Data.Tree.Class_branchlist();
  public static Vx.Data.Tree.Type_branchlist t_branchlist = new Vx.Data.Tree.Class_branchlist();

  /**
   * type: leaf
   * (type leaf)
   */
  public interface Type_leaf : Vx.Core.Type_struct {
    public Vx.Core.Type_string id();
    public Vx.Core.Type_string name();
    public Vx.Core.Type_any value();
  }

  public class Class_leaf : Vx.Core.Class_base, Type_leaf {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Core.Type_string? testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Core.Type_string? testnull = vx_p_name;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_any? vx_p_value = null;

    public Vx.Core.Type_any value() {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_any? testnull = vx_p_value;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      if (false) {
      } else if ((skey==":id")) {
        output = this.id();
      } else if ((skey==":name")) {
        output = this.name();
      } else if ((skey==":value")) {
        output = this.value();
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      map.put(":id", this.id());
      map.put(":name", this.name());
      map.put(":value", this.value());
      Vx.Core.Map<string, Vx.Core.Type_any> output = Vx.Core.immutablemap(map);
      return output;
    }

    public override Vx.Data.Tree.Type_leaf vx_new(params object[] vals) {
      Vx.Data.Tree.Type_leaf output = Vx.Core.vx_copy(Vx.Data.Tree.e_leaf, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Tree.Type_leaf output = this;
      bool ischanged = false;
      Vx.Data.Tree.Class_leaf value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = value.id();
      Vx.Core.Type_string vx_p_name = value.name();
      Vx.Core.Type_any vx_p_value = value.value();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":name");
      validkeys.Add(":value");
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
            msg = Vx.Core.vx_msg_from_error("vx/data/tree/leaf", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/data/tree/leaf", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key==":id")) {
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string valid) {
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/tree/leaf", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":name")) {
            if (valsub == vx_p_name) {
            } else if (valsub is Vx.Core.Type_string valname) {
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/tree/leaf", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":value")) {
            if (valsub == vx_p_value) {
            } else if (valsub is Vx.Core.Type_any valvalue) {
              ischanged = true;
              vx_p_value = valvalue;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("value"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/tree/leaf", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/tree/leaf", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Tree.Class_leaf work = new Vx.Data.Tree.Class_leaf();
        work.vx_p_id = vx_p_id;
        work.vx_p_name = vx_p_name;
        work.vx_p_value = vx_p_value;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Tree.e_leaf;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Tree.t_leaf;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/data/tree", // pkgname
        "leaf", // name
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

  public static Vx.Data.Tree.Type_leaf e_leaf = new Vx.Data.Tree.Class_leaf();
  public static Vx.Data.Tree.Type_leaf t_leaf = new Vx.Data.Tree.Class_leaf();

  /**
   * type: leaflist
   * (type leaflist)
   */
  public interface Type_leaflist : Vx.Core.Type_list {
    public List<Vx.Data.Tree.Type_leaf> vx_listleaf();
    public Vx.Data.Tree.Type_leaf vx_leaf(Vx.Core.Type_int index);
  }

  public class Class_leaflist : Vx.Core.Class_base, Type_leaflist {

    public List<Vx.Data.Tree.Type_leaf> vx_p_list = Vx.Core.immutablelist(
      new List<Vx.Data.Tree.Type_leaf>()
    );

    public List<Vx.Core.Type_any> vx_list() {
      List<Vx.Core.Type_any> output = Vx.Core.immutablelist(
        new List<Vx.Core.Type_any>(this.vx_p_list)
      );
      return output;
    }

    public Vx.Data.Tree.Type_leaf vx_leaf(Vx.Core.Type_int index) {
      Vx.Data.Tree.Type_leaf output = Vx.Data.Tree.e_leaf;
      Vx.Data.Tree.Class_leaflist list = this;
      int iindex = index.vx_int();
      List<Vx.Data.Tree.Type_leaf> listval = list.vx_p_list;
      if (iindex < listval.Count) {
        output = listval[iindex];
      }
      return output;
    }

    public List<Vx.Data.Tree.Type_leaf> vx_listleaf() {
      List<Vx.Data.Tree.Type_leaf> output = this.vx_p_list;
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_int index) {
      Vx.Data.Tree.Type_leaf output = this.vx_leaf(index);
      return output;
    }

    public override Vx.Data.Tree.Type_leaflist vx_new(params object[] vals) {
      Vx.Data.Tree.Type_leaflist output = Vx.Core.vx_copy(Vx.Data.Tree.e_leaflist, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Tree.Type_leaflist output = this;
      bool ischanged = false;
      Vx.Data.Tree.Class_leaflist value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      List<Vx.Data.Tree.Type_leaf> listval = new List<Vx.Data.Tree.Type_leaf>(value.vx_listleaf());
      Vx.Core.Type_msg msg;
      foreach (object valsub in vals) {
        if (valsub is Vx.Core.Type_msgblock) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Core.Type_msg) {
          msgblock = Vx.Core.vx_copy(msgblock, valsub);
        } else if (valsub is Vx.Data.Tree.Type_leaf allowsub) {
          ischanged = true;
          listval.Add(allowsub);
        } else if (valsub is Vx.Data.Tree.Type_leaf) {
          ischanged = true;
          listval.Add((Vx.Data.Tree.Type_leaf)valsub);
        } else if (valsub is Vx.Data.Tree.Type_leaflist multi) {
          ischanged = true;
          listval.AddRange(multi.vx_listleaf());
        } else if (valsub is List<Vx.Core.Type_any> listany) {
          foreach (Vx.Core.Type_any item in listany) {
            if (false) {
            } else if (item is Vx.Data.Tree.Type_leaf valitem) {
              ischanged = true;
              listval.Add(valitem);
            }
          }
        } else if (valsub is Vx.Core.Type_any anyinvalid) {
          msg = Vx.Core.vx_msg_from_error("vx/data/tree/leaflist", ":invalidtype", anyinvalid);
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        } else {
          msg = Vx.Core.vx_msg_from_error("vx/data/tree/leaflist", ":invalidtype", Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub)));
          msgblock = Vx.Core.vx_copy(msgblock, msg);
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Tree.Class_leaflist work = new Vx.Data.Tree.Class_leaflist();
        work.vx_p_list = Vx.Core.immutablelist(listval);
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Tree.e_leaflist;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Tree.t_leaflist;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/data/tree", // pkgname
        "leaflist", // name
        ":list", // extends
        Vx.Core.e_typelist, // traits
        Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Data.Tree.t_leaf), // allowtypes
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

  public static Vx.Data.Tree.Type_leaflist e_leaflist = new Vx.Data.Tree.Class_leaflist();
  public static Vx.Data.Tree.Type_leaflist t_leaflist = new Vx.Data.Tree.Class_leaflist();

  /**
   * type: tree
   * (type tree)
   */
  public interface Type_tree : Vx.Core.Type_struct {
    public Vx.Core.Type_string id();
    public Vx.Core.Type_string name();
    public Vx.Data.Tree.Type_branch branch();
  }

  public class Class_tree : Vx.Core.Class_base, Type_tree {

    public Vx.Core.Type_string? vx_p_id = null;

    public Vx.Core.Type_string id() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Core.Type_string? testnull = vx_p_id;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_string? vx_p_name = null;

    public Vx.Core.Type_string name() {
      Vx.Core.Type_string output = Vx.Core.e_string;
      Vx.Core.Type_string? testnull = vx_p_name;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Data.Tree.Type_branch? vx_p_branch = null;

    public Vx.Data.Tree.Type_branch branch() {
      Vx.Data.Tree.Type_branch output = Vx.Data.Tree.e_branch;
      Vx.Data.Tree.Type_branch? testnull = vx_p_branch;
      if (testnull != null) {
        output = testnull;
      }
      return output;
    }

    public Vx.Core.Type_any vx_any(Vx.Core.Type_string key) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      string skey = key.vx_string();
      if (false) {
      } else if ((skey==":id")) {
        output = this.id();
      } else if ((skey==":name")) {
        output = this.name();
      } else if ((skey==":branch")) {
        output = this.branch();
      }
      return output;
    }

    public Vx.Core.Map<string, Vx.Core.Type_any> vx_map() {
      Vx.Core.Map<string, Vx.Core.Type_any> map = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
      map.put(":id", this.id());
      map.put(":name", this.name());
      map.put(":branch", this.branch());
      Vx.Core.Map<string, Vx.Core.Type_any> output = Vx.Core.immutablemap(map);
      return output;
    }

    public override Vx.Data.Tree.Type_tree vx_new(params object[] vals) {
      Vx.Data.Tree.Type_tree output = Vx.Core.vx_copy(Vx.Data.Tree.e_tree, vals);
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Data.Tree.Type_tree output = this;
      bool ischanged = false;
      Vx.Data.Tree.Class_tree value = this;
      Vx.Core.Type_msgblock msgblock = Vx.Core.vx_msgblock_from_copy_arrayval(value, vals);
      if (this.vx_constdef() != Vx.Core.e_constdef) {
        ischanged = true;
      }
      Vx.Core.Type_string vx_p_id = value.id();
      Vx.Core.Type_string vx_p_name = value.name();
      Vx.Data.Tree.Type_branch vx_p_branch = value.branch();
      List<string> validkeys = new List<string>();
      validkeys.Add(":id");
      validkeys.Add(":name");
      validkeys.Add(":branch");
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
            msg = Vx.Core.vx_msg_from_error("vx/data/tree/tree", ":invalidkeytype", msgval);
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
              msg = Vx.Core.vx_msg_from_error("vx/data/tree/tree", ":invalidkey", msgval);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          }
        } else {
          if (false) {
          } else if ((key==":id")) {
            if (valsub == vx_p_id) {
            } else if (valsub is Vx.Core.Type_string valid) {
              ischanged = true;
              vx_p_id = valid;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_id = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("id"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/tree/tree", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":name")) {
            if (valsub == vx_p_name) {
            } else if (valsub is Vx.Core.Type_string valname) {
              ischanged = true;
              vx_p_name = valname;
            } else if (valsub is string) {
              ischanged = true;
              vx_p_name = Vx.Core.vx_new(Vx.Core.t_string, valsub);
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("name"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/tree/tree", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else if ((key==":branch")) {
            if (valsub == vx_p_branch) {
            } else if (valsub is Vx.Data.Tree.Type_branch valbranch) {
              ischanged = true;
              vx_p_branch = valbranch;
            } else {
              if (false) {
              } else if (valsub is Vx.Core.Type_any valinvalid) {
                msgval = valinvalid;
              } else {
                msgval = Vx.Core.vx_new_string(Vx.Core.vx_string_from_object(valsub));
              }
              Vx.Core.Map<string, Vx.Core.Type_any> mapany = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
              mapany.put("key", Vx.Core.vx_new_string("branch"));
              mapany.put("value", msgval);
              Vx.Core.Type_map msgmap = Vx.Core.t_anymap.vx_new_from_map(mapany);
              msg = Vx.Core.vx_msg_from_error("vx/data/tree/tree", ":invalidvalue", msgmap);
              msgblock = Vx.Core.vx_copy(msgblock, msg);
            }
          } else {
            msgval = Vx.Core.vx_new_string(key);
            msg = Vx.Core.vx_msg_from_error("vx/data/tree/tree", ":invalidkey", msgval);
            msgblock = Vx.Core.vx_copy(msgblock, msg);
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != Vx.Core.e_msgblock)) {
        Vx.Data.Tree.Class_tree work = new Vx.Data.Tree.Class_tree();
        work.vx_p_id = vx_p_id;
        work.vx_p_name = vx_p_name;
        work.vx_p_branch = vx_p_branch;
        if (msgblock != Vx.Core.e_msgblock) {
          work.vxmsgblock = msgblock;
        }
        output = work;
      }
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Data.Tree.e_tree;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Data.Tree.t_tree;
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.typedef_new(
        "vx/data/tree", // pkgname
        "tree", // name
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

  public static Vx.Data.Tree.Type_tree e_tree = new Vx.Data.Tree.Class_tree();
  public static Vx.Data.Tree.Type_tree t_tree = new Vx.Data.Tree.Class_tree();

  /**
   * Constant: brancharrow-down
   * {brancharrow}
   */
  public class Const_brancharrow_down {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/data/tree", // pkgname
        "brancharrow-down", // name
        Vx.Core.typedef_new(
          "vx/data/tree", // pkgname
          "brancharrow", // name
          "", // extends
          Vx.Core.e_typelist, // traits
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

    public static void const_new(Vx.Data.Tree.Type_brancharrow output) {
      Vx.Data.Tree.Class_brancharrow outval = (Vx.Data.Tree.Class_brancharrow)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Data.Tree.Type_brancharrow c_brancharrow_down = new Vx.Data.Tree.Class_brancharrow();


  /**
   * Constant: brancharrow-up
   * {brancharrow}
   */
  public class Const_brancharrow_up {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/data/tree", // pkgname
        "brancharrow-up", // name
        Vx.Core.typedef_new(
          "vx/data/tree", // pkgname
          "brancharrow", // name
          "", // extends
          Vx.Core.e_typelist, // traits
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

    public static void const_new(Vx.Data.Tree.Type_brancharrow output) {
      Vx.Data.Tree.Class_brancharrow outval = (Vx.Data.Tree.Class_brancharrow)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Data.Tree.Type_brancharrow c_brancharrow_up = new Vx.Data.Tree.Class_brancharrow();


  /**
   * Constant: brancharrow-updown
   * {brancharrow}
   */
  public class Const_brancharrow_updown {
    public static Vx.Core.Type_constdef constdef() {
      Vx.Core.Type_constdef output = Vx.Core.constdef_new(
        "vx/data/tree", // pkgname
        "brancharrow-updown", // name
        Vx.Core.typedef_new(
          "vx/data/tree", // pkgname
          "brancharrow", // name
          "", // extends
          Vx.Core.e_typelist, // traits
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

    public static void const_new(Vx.Data.Tree.Type_brancharrow output) {
      Vx.Data.Tree.Class_brancharrow outval = (Vx.Data.Tree.Class_brancharrow)output;
      outval.vx_p_constdef = constdef();
    }

  }

  public static Vx.Data.Tree.Type_brancharrow c_brancharrow_updown = new Vx.Data.Tree.Class_brancharrow();


  public static class PackageRunOnce {
    public static bool RunOnce() {
    Const_brancharrow_down.const_new(c_brancharrow_down);
    Const_brancharrow_up.const_new(c_brancharrow_up);
    Const_brancharrow_updown.const_new(c_brancharrow_updown);
    Vx.Core.Map<string, Vx.Core.Type_any> maptype = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_any> mapconst = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_func> mapfunc = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>();
    maptype.put("branch", Vx.Data.Tree.t_branch);
    maptype.put("brancharrow", Vx.Data.Tree.t_brancharrow);
    maptype.put("branchlist", Vx.Data.Tree.t_branchlist);
    maptype.put("leaf", Vx.Data.Tree.t_leaf);
    maptype.put("leaflist", Vx.Data.Tree.t_leaflist);
    maptype.put("tree", Vx.Data.Tree.t_tree);
    mapconst.put("brancharrow-down", Vx.Data.Tree.c_brancharrow_down);
    mapconst.put("brancharrow-up", Vx.Data.Tree.c_brancharrow_up);
    mapconst.put("brancharrow-updown", Vx.Data.Tree.c_brancharrow_updown);
    Vx.Core.vx_global_package_set("vx/data/tree", maptype, mapconst, mapfunc);
      return true;
    }
  }

  public static bool ranonce = PackageRunOnce.RunOnce();

}
