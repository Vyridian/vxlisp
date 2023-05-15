#include <memory>
#include <set>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "vx/data/tree.hpp"

//namespace vx_data_tree {

  /**
   * type: branch
   * (type branch)
   */
  //class Type_branch {
    // id()
    vx_core::Type_string vx_data_tree::Class_branch::id() {
      vx_core::Type_string output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // brancharrow()
    vx_data_tree::Type_brancharrow vx_data_tree::Class_branch::brancharrow() {
      vx_data_tree::Type_brancharrow output = this->vx_p_brancharrow;
      if (output == NULL) {
        output = vx_data_tree::t_brancharrow;
      }
      return output;
    }

    // branchlist()
    vx_data_tree::Type_branchlist vx_data_tree::Class_branch::branchlist() {
      vx_data_tree::Type_branchlist output = this->vx_p_branchlist;
      if (output == NULL) {
        output = vx_data_tree::t_branchlist;
      }
      return output;
    }

    // leaflist()
    vx_data_tree::Type_leaflist vx_data_tree::Class_branch::leaflist() {
      vx_data_tree::Type_leaflist output = this->vx_p_leaflist;
      if (output == NULL) {
        output = vx_data_tree::t_leaflist;
      }
      return output;
    }

    // parentbranch()
    vx_data_tree::Type_branch vx_data_tree::Class_branch::parentbranch() {
      vx_data_tree::Type_branch output = this->vx_p_parentbranch;
      if (output == NULL) {
        output = vx_data_tree::t_branch;
      }
      return output;
    }

    // tree()
    vx_data_tree::Type_tree vx_data_tree::Class_branch::tree() {
      vx_data_tree::Type_tree output = this->vx_p_tree;
      if (output == NULL) {
        output = vx_data_tree::t_tree;
      }
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_data_tree::Class_branch::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":brancharrow") {
        output = this->brancharrow();
      } else if (skey == ":branchlist") {
        output = this->branchlist();
      } else if (skey == ":leaflist") {
        output = this->leaflist();
      } else if (skey == ":parentbranch") {
        output = this->parentbranch();
      } else if (skey == ":tree") {
        output = this->tree();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_data_tree::Class_branch::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":brancharrow"] = this->brancharrow();
      output[":branchlist"] = this->branchlist();
      output[":leaflist"] = this->leaflist();
      output[":parentbranch"] = this->parentbranch();
      output[":tree"] = this->tree();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_tree::Class_branch::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_data_tree::e_branch->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_data_tree::Class_branch::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_tree::Type_branch output;
      vx_data_tree::Class_branch* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_brancharrow = val->brancharrow();
      output->vx_p_branchlist = val->branchlist();
      output->vx_p_leaflist = val->leaflist();
      output->vx_p_parentbranch = val->parentbranch();
      output->vx_p_tree = val->tree();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
      validkeys.insert(":brancharrow");
      validkeys.insert(":branchlist");
      validkeys.insert(":leaflist");
      validkeys.insert(":parentbranch");
      validkeys.insert(":tree");
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string valstr = vx_core::any_from_any(vx_core::t_string, valsub);
            testkey = valstr->vx_string();
          }
          bool isvalidkey = vx_core::boolean_contains_from_set_val(validkeys, testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new branch) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_id = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new branch :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":brancharrow") {
            if (valsubtype == vx_data_tree::t_brancharrow) {
              output->vx_p_brancharrow = vx_core::any_from_any(vx_data_tree::t_brancharrow, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new branch :brancharrow " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":branchlist") {
            if (valsubtype == vx_data_tree::t_branchlist) {
              output->vx_p_branchlist = vx_core::any_from_any(vx_data_tree::t_branchlist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new branch :branchlist " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":leaflist") {
            if (valsubtype == vx_data_tree::t_leaflist) {
              output->vx_p_leaflist = vx_core::any_from_any(vx_data_tree::t_leaflist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new branch :leaflist " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":parentbranch") {
            if (valsubtype == vx_data_tree::t_branch) {
              output->vx_p_parentbranch = vx_core::any_from_any(vx_data_tree::t_branch, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new branch :parentbranch " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":tree") {
            if (valsubtype == vx_data_tree::t_tree) {
              output->vx_p_tree = vx_core::any_from_any(vx_data_tree::t_tree, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new branch :tree " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new branch) - Invalid Key: " + key);
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
          key = "";
        }
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_tree::Class_branch::vx_empty(std::shared_ptr<T> val) {return vx_data_tree::e_branch;}
    template <class T> std::shared_ptr<T> vx_data_tree::Class_branch::vx_type(std::shared_ptr<T> val) {return vx_data_tree::t_branch;}

    vx_core::Type_typedef vx_data_tree::Class_branch::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/tree", // pkgname
        "branch", // name
        ":struct", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_data_tree::Type_branch vx_data_tree::e_branch = std::make_shared<vx_data_tree::Class_branch>();
    vx_data_tree::Type_branch vx_data_tree::t_branch = std::make_shared<vx_data_tree::Class_branch>();
  //}

  /**
   * type: brancharrow
   * (type brancharrow)
   */
  //class Type_brancharrow {
    template <class T> std::shared_ptr<T> vx_data_tree::Class_brancharrow::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_data_tree::e_brancharrow->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_data_tree::Class_brancharrow::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_tree::Type_brancharrow output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_tree::Class_brancharrow::vx_empty(std::shared_ptr<T> val) {return vx_data_tree::e_brancharrow;}
    template <class T> std::shared_ptr<T> vx_data_tree::Class_brancharrow::vx_type(std::shared_ptr<T> val) {return vx_data_tree::t_brancharrow;}

    vx_core::Type_typedef vx_data_tree::Class_brancharrow::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/tree", // pkgname
        "brancharrow", // name
        "", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_data_tree::Type_brancharrow vx_data_tree::e_brancharrow = std::make_shared<vx_data_tree::Class_brancharrow>();
    vx_data_tree::Type_brancharrow vx_data_tree::t_brancharrow = std::make_shared<vx_data_tree::Class_brancharrow>();
  //}

  /**
   * type: branchlist
   * (type branchlist)
   */
  //class Type_branchlist {
    vx_core::vx_Type_listany vx_data_tree::Class_branchlist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_data_tree::Type_branch vx_data_tree::Class_branchlist::vx_branch(vx_core::Type_int index) {
      vx_data_tree::Type_branch output = vx_data_tree::e_branch;
      vx_data_tree::Class_branchlist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_data_tree::Type_branch> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_data_tree::Type_branch> vx_data_tree::Class_branchlist::vx_listbranch() {return vx_p_list;}

    vx_core::Type_any vx_data_tree::Class_branchlist::vx_any(vx_core::Type_int index) {
      return this->vx_branch(index);
    }

    template <class T> std::shared_ptr<T> vx_data_tree::Class_branchlist::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_data_tree::e_branchlist->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_data_tree::Class_branchlist::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_tree::Type_branchlist output;
      vx_data_tree::Class_branchlist* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_data_tree::Type_branch> listval = val->vx_listbranch();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_data_tree::t_branch) {
          listval->push_back(vx_core::any_from_any(vx_data_tree::t_branch, valsub));
        } else if (valsubtype == vx_data_tree::t_branchlist) {
          vx_data_tree::Type_branchlist multi = vx_core::any_from_any(vx_data_tree::t_branchlist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listbranch());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new branchlist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_tree::Class_branchlist::vx_empty(std::shared_ptr<T> val) {return vx_data_tree::e_branchlist;}
    template <class T> std::shared_ptr<T> vx_data_tree::Class_branchlist::vx_type(std::shared_ptr<T> val) {return vx_data_tree::t_branchlist;}

    vx_core::Type_typedef vx_data_tree::Class_branchlist::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/tree", // pkgname
        "branchlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_data_tree::t_branch}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_data_tree::Type_branchlist vx_data_tree::e_branchlist = std::make_shared<vx_data_tree::Class_branchlist>();
    vx_data_tree::Type_branchlist vx_data_tree::t_branchlist = std::make_shared<vx_data_tree::Class_branchlist>();
  //}

  /**
   * type: leaf
   * (type leaf)
   */
  //class Type_leaf {
    // id()
    vx_core::Type_string vx_data_tree::Class_leaf::id() {
      vx_core::Type_string output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // name()
    vx_core::Type_string vx_data_tree::Class_leaf::name() {
      vx_core::Type_string output = this->vx_p_name;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // value()
    vx_core::Type_any vx_data_tree::Class_leaf::value() {
      vx_core::Type_any output = this->vx_p_value;
      if (output == NULL) {
        output = vx_core::t_any;
      }
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_data_tree::Class_leaf::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":value") {
        output = this->value();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_data_tree::Class_leaf::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":name"] = this->name();
      output[":value"] = this->value();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_tree::Class_leaf::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_data_tree::e_leaf->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_data_tree::Class_leaf::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_tree::Type_leaf output;
      vx_data_tree::Class_leaf* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_name = val->name();
      output->vx_p_value = val->value();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
      validkeys.insert(":name");
      validkeys.insert(":value");
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string valstr = vx_core::any_from_any(vx_core::t_string, valsub);
            testkey = valstr->vx_string();
          }
          bool isvalidkey = vx_core::boolean_contains_from_set_val(validkeys, testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new leaf) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_id = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new leaf :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_name = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new leaf :name " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":value") {
            if (valsubtype == vx_core::t_any) {
              output->vx_p_value = vx_core::any_from_any(vx_core::t_any, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new leaf :value " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new leaf) - Invalid Key: " + key);
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
          key = "";
        }
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_tree::Class_leaf::vx_empty(std::shared_ptr<T> val) {return vx_data_tree::e_leaf;}
    template <class T> std::shared_ptr<T> vx_data_tree::Class_leaf::vx_type(std::shared_ptr<T> val) {return vx_data_tree::t_leaf;}

    vx_core::Type_typedef vx_data_tree::Class_leaf::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/tree", // pkgname
        "leaf", // name
        ":struct", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_data_tree::Type_leaf vx_data_tree::e_leaf = std::make_shared<vx_data_tree::Class_leaf>();
    vx_data_tree::Type_leaf vx_data_tree::t_leaf = std::make_shared<vx_data_tree::Class_leaf>();
  //}

  /**
   * type: leaflist
   * (type leaflist)
   */
  //class Type_leaflist {
    vx_core::vx_Type_listany vx_data_tree::Class_leaflist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_data_tree::Type_leaf vx_data_tree::Class_leaflist::vx_leaf(vx_core::Type_int index) {
      vx_data_tree::Type_leaf output = vx_data_tree::e_leaf;
      vx_data_tree::Class_leaflist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_data_tree::Type_leaf> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_data_tree::Type_leaf> vx_data_tree::Class_leaflist::vx_listleaf() {return vx_p_list;}

    vx_core::Type_any vx_data_tree::Class_leaflist::vx_any(vx_core::Type_int index) {
      return this->vx_leaf(index);
    }

    template <class T> std::shared_ptr<T> vx_data_tree::Class_leaflist::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_data_tree::e_leaflist->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_data_tree::Class_leaflist::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_tree::Type_leaflist output;
      vx_data_tree::Class_leaflist* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_data_tree::Type_leaf> listval = val->vx_listleaf();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_data_tree::t_leaf) {
          listval->push_back(vx_core::any_from_any(vx_data_tree::t_leaf, valsub));
        } else if (valsubtype == vx_data_tree::t_leaflist) {
          vx_data_tree::Type_leaflist multi = vx_core::any_from_any(vx_data_tree::t_leaflist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listleaf());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new leaflist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_tree::Class_leaflist::vx_empty(std::shared_ptr<T> val) {return vx_data_tree::e_leaflist;}
    template <class T> std::shared_ptr<T> vx_data_tree::Class_leaflist::vx_type(std::shared_ptr<T> val) {return vx_data_tree::t_leaflist;}

    vx_core::Type_typedef vx_data_tree::Class_leaflist::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/tree", // pkgname
        "leaflist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_data_tree::t_leaf}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_data_tree::Type_leaflist vx_data_tree::e_leaflist = std::make_shared<vx_data_tree::Class_leaflist>();
    vx_data_tree::Type_leaflist vx_data_tree::t_leaflist = std::make_shared<vx_data_tree::Class_leaflist>();
  //}

  /**
   * type: tree
   * (type tree)
   */
  //class Type_tree {
    // id()
    vx_core::Type_string vx_data_tree::Class_tree::id() {
      vx_core::Type_string output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // name()
    vx_core::Type_string vx_data_tree::Class_tree::name() {
      vx_core::Type_string output = this->vx_p_name;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // branch()
    vx_data_tree::Type_branch vx_data_tree::Class_tree::branch() {
      vx_data_tree::Type_branch output = this->vx_p_branch;
      if (output == NULL) {
        output = vx_data_tree::t_branch;
      }
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_data_tree::Class_tree::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":branch") {
        output = this->branch();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_data_tree::Class_tree::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":name"] = this->name();
      output[":branch"] = this->branch();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_tree::Class_tree::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_data_tree::e_tree->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_data_tree::Class_tree::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_tree::Type_tree output;
      vx_data_tree::Class_tree* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_name = val->name();
      output->vx_p_branch = val->branch();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
      validkeys.insert(":name");
      validkeys.insert(":branch");
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string valstr = vx_core::any_from_any(vx_core::t_string, valsub);
            testkey = valstr->vx_string();
          }
          bool isvalidkey = vx_core::boolean_contains_from_set_val(validkeys, testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new tree) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_id = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new tree :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_name = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new tree :name " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":branch") {
            if (valsubtype == vx_data_tree::t_branch) {
              output->vx_p_branch = vx_core::any_from_any(vx_data_tree::t_branch, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new tree :branch " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new tree) - Invalid Key: " + key);
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
          key = "";
        }
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_tree::Class_tree::vx_empty(std::shared_ptr<T> val) {return vx_data_tree::e_tree;}
    template <class T> std::shared_ptr<T> vx_data_tree::Class_tree::vx_type(std::shared_ptr<T> val) {return vx_data_tree::t_tree;}

    vx_core::Type_typedef vx_data_tree::Class_tree::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/tree", // pkgname
        "tree", // name
        ":struct", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_data_tree::Type_tree vx_data_tree::e_tree = std::make_shared<vx_data_tree::Class_tree>();
    vx_data_tree::Type_tree vx_data_tree::t_tree = std::make_shared<vx_data_tree::Class_tree>();
  //}

  /**
   * Constant: brancharrow-down
   * {brancharrow}
   */
  //class Class_brancharrow_down {

    // vx_constdef()
    vx_core::Type_constdef vx_data_tree::Class_brancharrow_down::vx_constdef() {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/data/tree", // pkgname
        "brancharrow-down", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/data/tree", // pkgname
          "brancharrow", // name
          "", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        )
      );
    }

    // vx_const_new()
    vx_data_tree::Const_brancharrow_down vx_data_tree::Class_brancharrow_down::vx_const_new() {
      vx_data_tree::Const_brancharrow_down output = std::shared_ptr<vx_data_tree::Class_brancharrow_down>();
      return output;
    }


  //}

  vx_data_tree::Const_brancharrow_down vx_data_tree::c_brancharrow_down = vx_data_tree::Class_brancharrow_down::vx_const_new();


  /**
   * Constant: brancharrow-up
   * {brancharrow}
   */
  //class Class_brancharrow_up {

    // vx_constdef()
    vx_core::Type_constdef vx_data_tree::Class_brancharrow_up::vx_constdef() {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/data/tree", // pkgname
        "brancharrow-up", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/data/tree", // pkgname
          "brancharrow", // name
          "", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        )
      );
    }

    // vx_const_new()
    vx_data_tree::Const_brancharrow_up vx_data_tree::Class_brancharrow_up::vx_const_new() {
      vx_data_tree::Const_brancharrow_up output = std::shared_ptr<vx_data_tree::Class_brancharrow_up>();
      return output;
    }


  //}

  vx_data_tree::Const_brancharrow_up vx_data_tree::c_brancharrow_up = vx_data_tree::Class_brancharrow_up::vx_const_new();


  /**
   * Constant: brancharrow-updown
   * {brancharrow}
   */
  //class Class_brancharrow_updown {

    // vx_constdef()
    vx_core::Type_constdef vx_data_tree::Class_brancharrow_updown::vx_constdef() {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/data/tree", // pkgname
        "brancharrow-updown", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/data/tree", // pkgname
          "brancharrow", // name
          "", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        )
      );
    }

    // vx_const_new()
    vx_data_tree::Const_brancharrow_updown vx_data_tree::Class_brancharrow_updown::vx_const_new() {
      vx_data_tree::Const_brancharrow_updown output = std::shared_ptr<vx_data_tree::Class_brancharrow_updown>();
      return output;
    }


  //}

  vx_data_tree::Const_brancharrow_updown vx_data_tree::c_brancharrow_updown = vx_data_tree::Class_brancharrow_updown::vx_const_new();


//}
