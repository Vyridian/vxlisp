#include <any>
#include <map>
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
    vx_core::Type_string* vx_data_tree::Type_branch::id() {
      vx_core::Type_string* output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // brancharrow()
    vx_data_tree::Type_brancharrow* vx_data_tree::Type_branch::brancharrow() {
      vx_data_tree::Type_brancharrow* output = this->vx_p_brancharrow;
      if (output == NULL) {
        output = vx_data_tree::t_brancharrow;
      }
    }

    // branchlist()
    vx_data_tree::Type_branchlist* vx_data_tree::Type_branch::branchlist() {
      vx_data_tree::Type_branchlist* output = this->vx_p_branchlist;
      if (output == NULL) {
        output = vx_data_tree::t_branchlist;
      }
    }

    // leaflist()
    vx_data_tree::Type_leaflist* vx_data_tree::Type_branch::leaflist() {
      vx_data_tree::Type_leaflist* output = this->vx_p_leaflist;
      if (output == NULL) {
        output = vx_data_tree::t_leaflist;
      }
    }

    // parentbranch()
    vx_data_tree::Type_branch* vx_data_tree::Type_branch::parentbranch() {
      vx_data_tree::Type_branch* output = this->vx_p_parentbranch;
      if (output == NULL) {
        output = vx_data_tree::t_branch;
      }
    }

    // tree()
    vx_data_tree::Type_tree* vx_data_tree::Type_branch::tree() {
      vx_data_tree::Type_tree* output = this->vx_p_tree;
      if (output == NULL) {
        output = vx_data_tree::t_tree;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_data_tree::Type_branch::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
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
    std::map<std::string, vx_core::Type_any*> vx_data_tree::Type_branch::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":id"] = this->id();
      output[":brancharrow"] = this->brancharrow();
      output[":branchlist"] = this->branchlist();
      output[":leaflist"] = this->leaflist();
      output[":parentbranch"] = this->parentbranch();
      output[":tree"] = this->tree();
      return output;
    }

    template<typename... Args> vx_data_tree::Type_branch* vx_data_tree::Type_branch::vx_new(Args*... args) {return vx_data_tree::e_branch->vx_copy(args...);}
    template<typename... Args> vx_data_tree::Type_branch* vx_data_tree::Type_branch::vx_copy(Args*... args) {
      vx_data_tree::Type_branch* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_branch* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
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
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string* valstr = vx_core::any_from_any(vx_core::t_string, valsub);
            testkey = valstr->vx_string();
          } else if (valsubtype == vx_core::t_nativestring) {
            testkey = vx_core::any_from_any("", valsub);
          }
          bool isvalidkey = vx_core::boolean_contains_from_set_val(validkeys, testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new branch) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_id = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_id = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new branch :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":brancharrow") {
            if (valsubtype == vx_data_tree::t_brancharrow) {
              output->vx_p_brancharrow = vx_core::any_from_any(vx_data_tree::t_brancharrow, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new branch :brancharrow " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":branchlist") {
            if (valsubtype == vx_data_tree::t_branchlist) {
              output->vx_p_branchlist = vx_core::any_from_any(vx_data_tree::t_branchlist, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new branch :branchlist " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":leaflist") {
            if (valsubtype == vx_data_tree::t_leaflist) {
              output->vx_p_leaflist = vx_core::any_from_any(vx_data_tree::t_leaflist, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new branch :leaflist " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":parentbranch") {
            if (valsubtype == vx_data_tree::t_branch) {
              output->vx_p_parentbranch = vx_core::any_from_any(vx_data_tree::t_branch, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new branch :parentbranch " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":tree") {
            if (valsubtype == vx_data_tree::t_tree) {
              output->vx_p_tree = vx_core::any_from_any(vx_data_tree::t_tree, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new branch :tree " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new branch) - Invalid Key: " + key);
            msgblock = msgblock->vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_data_tree::Type_branch* vx_data_tree::Type_branch::vx_empty() {return vx_data_tree::e_branch;}
    vx_data_tree::Type_branch* vx_data_tree::Type_branch::vx_type() {return vx_data_tree::t_branch;}

    vx_core::Type_typedef* vx_data_tree::Type_branch::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
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

  //}

  /**
   * type: brancharrow
   * (type brancharrow)
   */
  //class Type_brancharrow {
    template<typename... Args> vx_data_tree::Type_brancharrow* vx_data_tree::Type_brancharrow::vx_new(Args*... args) {return vx_data_tree::e_brancharrow->vx_copy(args...);}
    template<typename... Args> vx_data_tree::Type_brancharrow* vx_data_tree::Type_brancharrow::vx_copy(Args*... args) {
      vx_data_tree::Type_brancharrow* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      return output;
    }

    vx_data_tree::Type_brancharrow* vx_data_tree::Type_brancharrow::vx_empty() {return vx_data_tree::e_brancharrow;}
    vx_data_tree::Type_brancharrow* vx_data_tree::Type_brancharrow::vx_type() {return vx_data_tree::t_brancharrow;}

    vx_core::Type_typedef* vx_data_tree::Type_brancharrow::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
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

  //}

  /**
   * type: branchlist
   * (type branchlist)
   */
  //class Type_branchlist {
    std::vector<vx_core::Type_any*> vx_data_tree::Type_branchlist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_data_tree::Type_branch* vx_data_tree::Type_branchlist::vx_branch(vx_core::Type_int* index) {
      vx_data_tree::Type_branch* output = vx_data_tree::e_branch;
      vx_data_tree::Type_branchlist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_data_tree::Type_branch*> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_data_tree::Type_branch*> vx_data_tree::Type_branchlist::vx_listbranch() {return vx_p_list;}

    vx_core::Type_any* vx_data_tree::Type_branchlist::vx_any(vx_core::Type_int* index) {
      return this->vx_branch(index);
    }

    template<typename... Args> vx_data_tree::Type_branchlist* vx_data_tree::Type_branchlist::vx_new(Args*... args) {return vx_data_tree::e_branchlist->vx_copy(args...);}
    template<typename... Args> vx_data_tree::Type_branchlist* vx_data_tree::Type_branchlist::vx_copy(Args*... args) {
      vx_data_tree::Type_branchlist* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_data_tree::Type_branchlist* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_data_tree::Type_branch*> listval = val->vx_listbranch();
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_data_tree::t_branch) {
          listval.push_back(vx_core::any_from_any(vx_data_tree::t_branch, valsub));
        } else if (valsubtype == vx_data_tree::t_branchlist) {
          vx_data_tree::Type_branchlist* multi = vx_core::any_from_any(vx_data_tree::t_branchlist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listbranch());
        } else if (valsubtype == vx_core::t_nativelist) {
          std::vector<std::any*> listunknown = vx_core::any_from_any(std::vector<vx_core::Type_any*>, valsub);
          for (std::any* item : listunknown) {
            vx_core::Type_any* itemtype = vx_core::t_any->vx_type_from_any(item);
            if (itemtype == vx_data_tree::t_branch) {
              vx_data_tree::Type_branch* valitem = vx_core::any_from_any(vx_data_tree::t_branch, item);
              listval.push_back(valitem);
            }
          }
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new branchlist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(msg);
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_data_tree::Type_branchlist* vx_data_tree::Type_branchlist::vx_empty() {return vx_data_tree::e_branchlist;}
    vx_data_tree::Type_branchlist* vx_data_tree::Type_branchlist::vx_type() {return vx_data_tree::t_branchlist;}

    vx_core::Type_typedef* vx_data_tree::Type_branchlist::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/data/tree", // pkgname
        "branchlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_data_tree::t_branch), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

  //}

  /**
   * type: leaf
   * (type leaf)
   */
  //class Type_leaf {
    // id()
    vx_core::Type_string* vx_data_tree::Type_leaf::id() {
      vx_core::Type_string* output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // name()
    vx_core::Type_string* vx_data_tree::Type_leaf::name() {
      vx_core::Type_string* output = this->vx_p_name;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // value()
    vx_core::Type_any* vx_data_tree::Type_leaf::value() {
      vx_core::Type_any* output = this->vx_p_value;
      if (output == NULL) {
        output = vx_core::t_any;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_data_tree::Type_leaf::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
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
    std::map<std::string, vx_core::Type_any*> vx_data_tree::Type_leaf::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":id"] = this->id();
      output[":name"] = this->name();
      output[":value"] = this->value();
      return output;
    }

    template<typename... Args> vx_data_tree::Type_leaf* vx_data_tree::Type_leaf::vx_new(Args*... args) {return vx_data_tree::e_leaf->vx_copy(args...);}
    template<typename... Args> vx_data_tree::Type_leaf* vx_data_tree::Type_leaf::vx_copy(Args*... args) {
      vx_data_tree::Type_leaf* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_leaf* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_name = val->name();
      output->vx_p_value = val->value();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
      validkeys.insert(":name");
      validkeys.insert(":value");
      std::string key = "";
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string* valstr = vx_core::any_from_any(vx_core::t_string, valsub);
            testkey = valstr->vx_string();
          } else if (valsubtype == vx_core::t_nativestring) {
            testkey = vx_core::any_from_any("", valsub);
          }
          bool isvalidkey = vx_core::boolean_contains_from_set_val(validkeys, testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new leaf) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_id = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_id = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new leaf :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_name = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_name = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new leaf :name " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":value") {
            if (valsubtype == vx_core::t_any) {
              output->vx_p_value = vx_core::any_from_any(vx_core::t_any, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new leaf :value " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new leaf) - Invalid Key: " + key);
            msgblock = msgblock->vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_data_tree::Type_leaf* vx_data_tree::Type_leaf::vx_empty() {return vx_data_tree::e_leaf;}
    vx_data_tree::Type_leaf* vx_data_tree::Type_leaf::vx_type() {return vx_data_tree::t_leaf;}

    vx_core::Type_typedef* vx_data_tree::Type_leaf::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
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

  //}

  /**
   * type: leaflist
   * (type leaflist)
   */
  //class Type_leaflist {
    std::vector<vx_core::Type_any*> vx_data_tree::Type_leaflist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_data_tree::Type_leaf* vx_data_tree::Type_leaflist::vx_leaf(vx_core::Type_int* index) {
      vx_data_tree::Type_leaf* output = vx_data_tree::e_leaf;
      vx_data_tree::Type_leaflist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_data_tree::Type_leaf*> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_data_tree::Type_leaf*> vx_data_tree::Type_leaflist::vx_listleaf() {return vx_p_list;}

    vx_core::Type_any* vx_data_tree::Type_leaflist::vx_any(vx_core::Type_int* index) {
      return this->vx_leaf(index);
    }

    template<typename... Args> vx_data_tree::Type_leaflist* vx_data_tree::Type_leaflist::vx_new(Args*... args) {return vx_data_tree::e_leaflist->vx_copy(args...);}
    template<typename... Args> vx_data_tree::Type_leaflist* vx_data_tree::Type_leaflist::vx_copy(Args*... args) {
      vx_data_tree::Type_leaflist* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_data_tree::Type_leaflist* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_data_tree::Type_leaf*> listval = val->vx_listleaf();
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_data_tree::t_leaf) {
          listval.push_back(vx_core::any_from_any(vx_data_tree::t_leaf, valsub));
        } else if (valsubtype == vx_data_tree::t_leaflist) {
          vx_data_tree::Type_leaflist* multi = vx_core::any_from_any(vx_data_tree::t_leaflist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listleaf());
        } else if (valsubtype == vx_core::t_nativelist) {
          std::vector<std::any*> listunknown = vx_core::any_from_any(std::vector<vx_core::Type_any*>, valsub);
          for (std::any* item : listunknown) {
            vx_core::Type_any* itemtype = vx_core::t_any->vx_type_from_any(item);
            if (itemtype == vx_data_tree::t_leaf) {
              vx_data_tree::Type_leaf* valitem = vx_core::any_from_any(vx_data_tree::t_leaf, item);
              listval.push_back(valitem);
            }
          }
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new leaflist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(msg);
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_data_tree::Type_leaflist* vx_data_tree::Type_leaflist::vx_empty() {return vx_data_tree::e_leaflist;}
    vx_data_tree::Type_leaflist* vx_data_tree::Type_leaflist::vx_type() {return vx_data_tree::t_leaflist;}

    vx_core::Type_typedef* vx_data_tree::Type_leaflist::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/data/tree", // pkgname
        "leaflist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_data_tree::t_leaf), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

  //}

  /**
   * type: tree
   * (type tree)
   */
  //class Type_tree {
    // id()
    vx_core::Type_string* vx_data_tree::Type_tree::id() {
      vx_core::Type_string* output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // name()
    vx_core::Type_string* vx_data_tree::Type_tree::name() {
      vx_core::Type_string* output = this->vx_p_name;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // branch()
    vx_data_tree::Type_branch* vx_data_tree::Type_tree::branch() {
      vx_data_tree::Type_branch* output = this->vx_p_branch;
      if (output == NULL) {
        output = vx_data_tree::t_branch;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_data_tree::Type_tree::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
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
    std::map<std::string, vx_core::Type_any*> vx_data_tree::Type_tree::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":id"] = this->id();
      output[":name"] = this->name();
      output[":branch"] = this->branch();
      return output;
    }

    template<typename... Args> vx_data_tree::Type_tree* vx_data_tree::Type_tree::vx_new(Args*... args) {return vx_data_tree::e_tree->vx_copy(args...);}
    template<typename... Args> vx_data_tree::Type_tree* vx_data_tree::Type_tree::vx_copy(Args*... args) {
      vx_data_tree::Type_tree* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_tree* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_name = val->name();
      output->vx_p_branch = val->branch();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
      validkeys.insert(":name");
      validkeys.insert(":branch");
      std::string key = "";
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string* valstr = vx_core::any_from_any(vx_core::t_string, valsub);
            testkey = valstr->vx_string();
          } else if (valsubtype == vx_core::t_nativestring) {
            testkey = vx_core::any_from_any("", valsub);
          }
          bool isvalidkey = vx_core::boolean_contains_from_set_val(validkeys, testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new tree) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_id = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_id = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new tree :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_name = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_name = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new tree :name " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":branch") {
            if (valsubtype == vx_data_tree::t_branch) {
              output->vx_p_branch = vx_core::any_from_any(vx_data_tree::t_branch, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new tree :branch " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new tree) - Invalid Key: " + key);
            msgblock = msgblock->vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_data_tree::Type_tree* vx_data_tree::Type_tree::vx_empty() {return vx_data_tree::e_tree;}
    vx_data_tree::Type_tree* vx_data_tree::Type_tree::vx_type() {return vx_data_tree::t_tree;}

    vx_core::Type_typedef* vx_data_tree::Type_tree::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
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

  //}

  /**
   * Constant: brancharrow-down
   * {brancharrow}
   */
  //class Const_brancharrow_down {

    // vx_constdef()
    vx_core::Type_constdef* vx_data_tree::Const_brancharrow_down::vx_constdef() {
      return vx_core::Type_constdef::vx_constdef_new(
        "vx/data/tree", // pkgname
        "brancharrow-down", // name
        vx_core::Type_typedef::vx_typedef_new(
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
    vx_data_tree::Const_brancharrow_down* vx_data_tree::Const_brancharrow_down::vx_const_new() {
      vx_data_tree::Const_brancharrow_down* output = new vx_data_tree::Const_brancharrow_down();
      return output;
    }


  //}

  vx_data_tree::Const_brancharrow_down* vx_data_tree::c_brancharrow_down = vx_data_tree::Const_brancharrow_down::vx_const_new();


  /**
   * Constant: brancharrow-up
   * {brancharrow}
   */
  //class Const_brancharrow_up {

    // vx_constdef()
    vx_core::Type_constdef* vx_data_tree::Const_brancharrow_up::vx_constdef() {
      return vx_core::Type_constdef::vx_constdef_new(
        "vx/data/tree", // pkgname
        "brancharrow-up", // name
        vx_core::Type_typedef::vx_typedef_new(
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
    vx_data_tree::Const_brancharrow_up* vx_data_tree::Const_brancharrow_up::vx_const_new() {
      vx_data_tree::Const_brancharrow_up* output = new vx_data_tree::Const_brancharrow_up();
      return output;
    }


  //}

  vx_data_tree::Const_brancharrow_up* vx_data_tree::c_brancharrow_up = vx_data_tree::Const_brancharrow_up::vx_const_new();


  /**
   * Constant: brancharrow-updown
   * {brancharrow}
   */
  //class Const_brancharrow_updown {

    // vx_constdef()
    vx_core::Type_constdef* vx_data_tree::Const_brancharrow_updown::vx_constdef() {
      return vx_core::Type_constdef::vx_constdef_new(
        "vx/data/tree", // pkgname
        "brancharrow-updown", // name
        vx_core::Type_typedef::vx_typedef_new(
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
    vx_data_tree::Const_brancharrow_updown* vx_data_tree::Const_brancharrow_updown::vx_const_new() {
      vx_data_tree::Const_brancharrow_updown* output = new vx_data_tree::Const_brancharrow_updown();
      return output;
    }


  //}

  vx_data_tree::Const_brancharrow_updown* vx_data_tree::c_brancharrow_updown = vx_data_tree::Const_brancharrow_updown::vx_const_new();


//}
