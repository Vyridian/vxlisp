#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "tree.hpp"

namespace vx_data_tree {


  // (type branch)
  // class Class_branch {
    Abstract_branch::~Abstract_branch() {}

    Class_branch::Class_branch() : Abstract_branch::Abstract_branch() {
      vx_core::refcount += 1;
    }
    Class_branch::~Class_branch() {
      vx_core::refcount -= 1;
    }
    // id()
    vx_core::Type_string Class_branch::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // brancharrow()
    vx_data_tree::Type_brancharrow Class_branch::brancharrow() const {
      vx_data_tree::Type_brancharrow output = this->vx_p_brancharrow;
      if (output == NULL) {
        output = vx_data_tree::e_brancharrow();
      }
      return output;
    }

    // branchlist()
    vx_data_tree::Type_branchlist Class_branch::branchlist() const {
      vx_data_tree::Type_branchlist output = this->vx_p_branchlist;
      if (output == NULL) {
        output = vx_data_tree::e_branchlist();
      }
      return output;
    }

    // leaflist()
    vx_data_tree::Type_leaflist Class_branch::leaflist() const {
      vx_data_tree::Type_leaflist output = this->vx_p_leaflist;
      if (output == NULL) {
        output = vx_data_tree::e_leaflist();
      }
      return output;
    }

    // parentbranch()
    vx_data_tree::Type_branch Class_branch::parentbranch() const {
      vx_data_tree::Type_branch output = this->vx_p_parentbranch;
      if (output == NULL) {
        output = vx_data_tree::e_branch();
      }
      return output;
    }

    // tree()
    vx_data_tree::Type_tree Class_branch::tree() const {
      vx_data_tree::Type_tree output = this->vx_p_tree;
      if (output == NULL) {
        output = vx_data_tree::e_tree();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_branch::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
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
    vx_core::vx_Type_mapany Class_branch::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":brancharrow"] = this->brancharrow();
      output[":branchlist"] = this->branchlist();
      output[":leaflist"] = this->leaflist();
      output[":parentbranch"] = this->parentbranch();
      output[":tree"] = this->tree();
      return output;
    }

    vx_core::Type_any Class_branch::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_tree::e_branch(), vals);
    }
    vx_core::Type_any Class_branch::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_tree::Type_branch output = vx_data_tree::e_branch();
      vx_data_tree::Type_branch val = vx_core::vx_any_from_any(vx_data_tree::t_branch(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_data_tree::Type_brancharrow vx_p_brancharrow = val->brancharrow();
      vx_data_tree::Type_branchlist vx_p_branchlist = val->branchlist();
      vx_data_tree::Type_leaflist vx_p_leaflist = val->leaflist();
      vx_data_tree::Type_branch vx_p_parentbranch = val->parentbranch();
      vx_data_tree::Type_tree vx_p_tree = val->tree();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string()) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            testkey = valstr->vx_string();
          }
          if (false) {
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":brancharrow") {
            key = testkey;
          } else if (testkey == ":branchlist") {
            key = testkey;
          } else if (testkey == ":leaflist") {
            key = testkey;
          } else if (testkey == ":parentbranch") {
            key = testkey;
          } else if (testkey == ":tree") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new branch) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new branch :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":brancharrow") {
            if (valsubtype == vx_data_tree::t_brancharrow()) {
              vx_p_brancharrow = vx_core::vx_any_from_any(vx_data_tree::t_brancharrow(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new branch :brancharrow " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":branchlist") {
            if (valsubtype == vx_data_tree::t_branchlist()) {
              vx_p_branchlist = vx_core::vx_any_from_any(vx_data_tree::t_branchlist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new branch :branchlist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":leaflist") {
            if (valsubtype == vx_data_tree::t_leaflist()) {
              vx_p_leaflist = vx_core::vx_any_from_any(vx_data_tree::t_leaflist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new branch :leaflist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":parentbranch") {
            if (valsubtype == vx_data_tree::t_branch()) {
              vx_p_parentbranch = vx_core::vx_any_from_any(vx_data_tree::t_branch(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new branch :parentbranch " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":tree") {
            if (valsubtype == vx_data_tree::t_tree()) {
              vx_p_tree = vx_core::vx_any_from_any(vx_data_tree::t_tree(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new branch :tree " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new branch) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_data_tree::Class_branch();
      output->vx_p_id = vx_p_id;
      output->vx_p_brancharrow = vx_p_brancharrow;
      output->vx_p_branchlist = vx_p_branchlist;
      output->vx_p_leaflist = vx_p_leaflist;
      output->vx_p_parentbranch = vx_p_parentbranch;
      output->vx_p_tree = vx_p_tree;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_branch::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_tree::Class_branch::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_branch::vx_empty() const {return vx_data_tree::e_branch();}
    vx_core::Type_any Class_branch::vx_type() const {return vx_data_tree::t_branch();}

    vx_core::Type_typedef Class_branch::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/tree", // pkgname
        "branch", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type brancharrow)
  // class Class_brancharrow {
    Abstract_brancharrow::~Abstract_brancharrow() {}

    Class_brancharrow::Class_brancharrow() : Abstract_brancharrow::Abstract_brancharrow() {
      vx_core::refcount += 1;
    }
    Class_brancharrow::~Class_brancharrow() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_brancharrow::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_tree::e_brancharrow(), vals);
    }
    vx_core::Type_any Class_brancharrow::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_tree::Type_brancharrow output = vx_data_tree::e_brancharrow();
      return output;
    }

    vx_core::Type_msgblock Class_brancharrow::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_tree::Class_brancharrow::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_brancharrow::vx_empty() const {return vx_data_tree::e_brancharrow();}
    vx_core::Type_any Class_brancharrow::vx_type() const {return vx_data_tree::t_brancharrow();}

    vx_core::Type_typedef Class_brancharrow::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/tree", // pkgname
        "brancharrow", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type branchlist)
  // class Class_branchlist {
    Abstract_branchlist::~Abstract_branchlist() {}

    Class_branchlist::Class_branchlist() : Abstract_branchlist::Abstract_branchlist() {
      vx_core::refcount += 1;
    }
    Class_branchlist::~Class_branchlist() {
      vx_core::refcount -= 1;
    }
    // vx_list()
    vx_core::vx_Type_listany Class_branchlist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_data_tree::Type_branch Class_branchlist::vx_get_branch(vx_core::Type_int index) const {
      vx_data_tree::Type_branch output = vx_data_tree::e_branch();
      long iindex = index->vx_int();
      std::vector<vx_data_tree::Type_branch> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_data_tree::Type_branch> Class_branchlist::vx_listbranch() const {return vx_p_list;}

    vx_core::Type_any vx_data_tree::Class_branchlist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_branch(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_branchlist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_data_tree::Type_branchlist output = vx_data_tree::e_branchlist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_data_tree::Type_branch> list;
      for (auto const& val : listval) {
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_data_tree::t_branch()) {
          vx_data_tree::Type_branch castval = vx_core::vx_any_from_any(vx_data_tree::t_branch(), val);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(branchlist) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_data_tree::Class_branchlist();
      output->vx_p_list = list;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_branchlist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_tree::e_branchlist(), vals);
    }
    vx_core::Type_any Class_branchlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_tree::Type_branchlist output = vx_data_tree::e_branchlist();
      vx_data_tree::Type_branchlist val = vx_core::vx_any_from_any(vx_data_tree::t_branchlist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_data_tree::Type_branch> listval = val->vx_listbranch();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_data_tree::t_branch()) {
          listval.push_back(vx_core::vx_any_from_any(vx_data_tree::t_branch(), valsub));
        } else if (valsubtype == vx_data_tree::t_branchlist()) {
          vx_data_tree::Type_branchlist multi = vx_core::vx_any_from_any(vx_data_tree::t_branchlist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listbranch());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new branchlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_data_tree::Class_branchlist();
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_branchlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_tree::Class_branchlist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_branchlist::vx_empty() const {return vx_data_tree::e_branchlist();}
    vx_core::Type_any Class_branchlist::vx_type() const {return vx_data_tree::t_branchlist();}

    vx_core::Type_typedef Class_branchlist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/tree", // pkgname
        "branchlist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_data_tree::t_branch()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type leaf)
  // class Class_leaf {
    Abstract_leaf::~Abstract_leaf() {}

    Class_leaf::Class_leaf() : Abstract_leaf::Abstract_leaf() {
      vx_core::refcount += 1;
    }
    Class_leaf::~Class_leaf() {
      vx_core::refcount -= 1;
    }
    // id()
    vx_core::Type_string Class_leaf::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // name()
    vx_core::Type_string Class_leaf::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // value()
    vx_core::Type_any Class_leaf::value() const {
      vx_core::Type_any output = this->vx_p_value;
      if (output == NULL) {
        output = vx_core::e_any();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_leaf::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
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
    vx_core::vx_Type_mapany Class_leaf::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":name"] = this->name();
      output[":value"] = this->value();
      return output;
    }

    vx_core::Type_any Class_leaf::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_tree::e_leaf(), vals);
    }
    vx_core::Type_any Class_leaf::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_tree::Type_leaf output = vx_data_tree::e_leaf();
      vx_data_tree::Type_leaf val = vx_core::vx_any_from_any(vx_data_tree::t_leaf(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_core::Type_string vx_p_name = val->name();
      vx_core::Type_any vx_p_value = val->value();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string()) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            testkey = valstr->vx_string();
          }
          if (false) {
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":name") {
            key = testkey;
          } else if (testkey == ":value") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new leaf) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new leaf :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_name = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new leaf :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":value") {
            if (valsubtype == vx_core::t_any()) {
              vx_p_value = vx_core::vx_any_from_any(vx_core::t_any(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new leaf :value " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new leaf) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_data_tree::Class_leaf();
      output->vx_p_id = vx_p_id;
      output->vx_p_name = vx_p_name;
      output->vx_p_value = vx_p_value;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_leaf::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_tree::Class_leaf::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_leaf::vx_empty() const {return vx_data_tree::e_leaf();}
    vx_core::Type_any Class_leaf::vx_type() const {return vx_data_tree::t_leaf();}

    vx_core::Type_typedef Class_leaf::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/tree", // pkgname
        "leaf", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type leaflist)
  // class Class_leaflist {
    Abstract_leaflist::~Abstract_leaflist() {}

    Class_leaflist::Class_leaflist() : Abstract_leaflist::Abstract_leaflist() {
      vx_core::refcount += 1;
    }
    Class_leaflist::~Class_leaflist() {
      vx_core::refcount -= 1;
    }
    // vx_list()
    vx_core::vx_Type_listany Class_leaflist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_data_tree::Type_leaf Class_leaflist::vx_get_leaf(vx_core::Type_int index) const {
      vx_data_tree::Type_leaf output = vx_data_tree::e_leaf();
      long iindex = index->vx_int();
      std::vector<vx_data_tree::Type_leaf> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_data_tree::Type_leaf> Class_leaflist::vx_listleaf() const {return vx_p_list;}

    vx_core::Type_any vx_data_tree::Class_leaflist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_leaf(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_leaflist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_data_tree::Type_leaflist output = vx_data_tree::e_leaflist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_data_tree::Type_leaf> list;
      for (auto const& val : listval) {
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_data_tree::t_leaf()) {
          vx_data_tree::Type_leaf castval = vx_core::vx_any_from_any(vx_data_tree::t_leaf(), val);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(leaflist) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_data_tree::Class_leaflist();
      output->vx_p_list = list;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_leaflist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_tree::e_leaflist(), vals);
    }
    vx_core::Type_any Class_leaflist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_tree::Type_leaflist output = vx_data_tree::e_leaflist();
      vx_data_tree::Type_leaflist val = vx_core::vx_any_from_any(vx_data_tree::t_leaflist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_data_tree::Type_leaf> listval = val->vx_listleaf();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_data_tree::t_leaf()) {
          listval.push_back(vx_core::vx_any_from_any(vx_data_tree::t_leaf(), valsub));
        } else if (valsubtype == vx_data_tree::t_leaflist()) {
          vx_data_tree::Type_leaflist multi = vx_core::vx_any_from_any(vx_data_tree::t_leaflist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listleaf());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new leaflist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_data_tree::Class_leaflist();
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_leaflist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_tree::Class_leaflist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_leaflist::vx_empty() const {return vx_data_tree::e_leaflist();}
    vx_core::Type_any Class_leaflist::vx_type() const {return vx_data_tree::t_leaflist();}

    vx_core::Type_typedef Class_leaflist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/tree", // pkgname
        "leaflist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_data_tree::t_leaf()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type tree)
  // class Class_tree {
    Abstract_tree::~Abstract_tree() {}

    Class_tree::Class_tree() : Abstract_tree::Abstract_tree() {
      vx_core::refcount += 1;
    }
    Class_tree::~Class_tree() {
      vx_core::refcount -= 1;
    }
    // id()
    vx_core::Type_string Class_tree::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // name()
    vx_core::Type_string Class_tree::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // branch()
    vx_data_tree::Type_branch Class_tree::branch() const {
      vx_data_tree::Type_branch output = this->vx_p_branch;
      if (output == NULL) {
        output = vx_data_tree::e_branch();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_tree::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
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
    vx_core::vx_Type_mapany Class_tree::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":name"] = this->name();
      output[":branch"] = this->branch();
      return output;
    }

    vx_core::Type_any Class_tree::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_tree::e_tree(), vals);
    }
    vx_core::Type_any Class_tree::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_tree::Type_tree output = vx_data_tree::e_tree();
      vx_data_tree::Type_tree val = vx_core::vx_any_from_any(vx_data_tree::t_tree(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_core::Type_string vx_p_name = val->name();
      vx_data_tree::Type_branch vx_p_branch = val->branch();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string()) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            testkey = valstr->vx_string();
          }
          if (false) {
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":name") {
            key = testkey;
          } else if (testkey == ":branch") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new tree) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new tree :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_name = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new tree :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":branch") {
            if (valsubtype == vx_data_tree::t_branch()) {
              vx_p_branch = vx_core::vx_any_from_any(vx_data_tree::t_branch(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new tree :branch " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new tree) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_data_tree::Class_tree();
      output->vx_p_id = vx_p_id;
      output->vx_p_name = vx_p_name;
      output->vx_p_branch = vx_p_branch;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_tree::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_tree::Class_tree::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_tree::vx_empty() const {return vx_data_tree::e_tree();}
    vx_core::Type_any Class_tree::vx_type() const {return vx_data_tree::t_tree();}

    vx_core::Type_typedef Class_tree::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/tree", // pkgname
        "tree", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (const brancharrow-down)
  // class Class_brancharrow_down {

    // vx_constdef()
    vx_core::Type_constdef vx_data_tree::Class_brancharrow_down::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/data/tree", // pkgname
        "brancharrow-down", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/data/tree", // pkgname
          "brancharrow", // name
          "", // extends
          vx_core::e_typelist(), // traits
          vx_core::e_typelist(), // allowtypes
          vx_core::e_typelist(), // disallowtypes
          vx_core::e_funclist(), // allowfuncs
          vx_core::e_funclist(), // disallowfuncs
          vx_core::e_anylist(), // allowvalues
          vx_core::e_anylist(), // disallowvalues
          vx_core::e_argmap() // properties
        )
      );
    }


  //}

  // (const brancharrow-up)
  // class Class_brancharrow_up {

    // vx_constdef()
    vx_core::Type_constdef vx_data_tree::Class_brancharrow_up::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/data/tree", // pkgname
        "brancharrow-up", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/data/tree", // pkgname
          "brancharrow", // name
          "", // extends
          vx_core::e_typelist(), // traits
          vx_core::e_typelist(), // allowtypes
          vx_core::e_typelist(), // disallowtypes
          vx_core::e_funclist(), // allowfuncs
          vx_core::e_funclist(), // disallowfuncs
          vx_core::e_anylist(), // allowvalues
          vx_core::e_anylist(), // disallowvalues
          vx_core::e_argmap() // properties
        )
      );
    }


  //}

  // (const brancharrow-updown)
  // class Class_brancharrow_updown {

    // vx_constdef()
    vx_core::Type_constdef vx_data_tree::Class_brancharrow_updown::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/data/tree", // pkgname
        "brancharrow-updown", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/data/tree", // pkgname
          "brancharrow", // name
          "", // extends
          vx_core::e_typelist(), // traits
          vx_core::e_typelist(), // allowtypes
          vx_core::e_typelist(), // disallowtypes
          vx_core::e_funclist(), // allowfuncs
          vx_core::e_funclist(), // disallowfuncs
          vx_core::e_anylist(), // allowvalues
          vx_core::e_anylist(), // disallowvalues
          vx_core::e_argmap() // properties
        )
      );
    }


  //}

  vx_data_tree::vx_Class_package* vx_package = new vx_data_tree::vx_Class_package();

  vx_data_tree::Type_branch e_branch() {
    vx_data_tree::Type_branch output = vx_data_tree::vx_package->e_branch;
    if (output == NULL) {
      output = new Class_branch();
      vx_core::vx_reserve_empty(output);
      vx_data_tree::vx_package->e_branch = output;
    }
    return output;
  }
  vx_data_tree::Type_branch t_branch() {
    vx_data_tree::Type_branch output = vx_data_tree::vx_package->t_branch;
    if (output == NULL) {
      output = new Class_branch();
      vx_core::vx_reserve_type(output);
      vx_data_tree::vx_package->t_branch = output;
    }
    return output;
  }

  vx_data_tree::Type_brancharrow e_brancharrow() {
    vx_data_tree::Type_brancharrow output = vx_data_tree::vx_package->e_brancharrow;
    if (output == NULL) {
      output = new Class_brancharrow();
      vx_core::vx_reserve_empty(output);
      vx_data_tree::vx_package->e_brancharrow = output;
    }
    return output;
  }
  vx_data_tree::Type_brancharrow t_brancharrow() {
    vx_data_tree::Type_brancharrow output = vx_data_tree::vx_package->t_brancharrow;
    if (output == NULL) {
      output = new Class_brancharrow();
      vx_core::vx_reserve_type(output);
      vx_data_tree::vx_package->t_brancharrow = output;
    }
    return output;
  }

  vx_data_tree::Type_branchlist e_branchlist() {
    vx_data_tree::Type_branchlist output = vx_data_tree::vx_package->e_branchlist;
    if (output == NULL) {
      output = new Class_branchlist();
      vx_core::vx_reserve_empty(output);
      vx_data_tree::vx_package->e_branchlist = output;
    }
    return output;
  }
  vx_data_tree::Type_branchlist t_branchlist() {
    vx_data_tree::Type_branchlist output = vx_data_tree::vx_package->t_branchlist;
    if (output == NULL) {
      output = new Class_branchlist();
      vx_core::vx_reserve_type(output);
      vx_data_tree::vx_package->t_branchlist = output;
    }
    return output;
  }

  vx_data_tree::Type_leaf e_leaf() {
    vx_data_tree::Type_leaf output = vx_data_tree::vx_package->e_leaf;
    if (output == NULL) {
      output = new Class_leaf();
      vx_core::vx_reserve_empty(output);
      vx_data_tree::vx_package->e_leaf = output;
    }
    return output;
  }
  vx_data_tree::Type_leaf t_leaf() {
    vx_data_tree::Type_leaf output = vx_data_tree::vx_package->t_leaf;
    if (output == NULL) {
      output = new Class_leaf();
      vx_core::vx_reserve_type(output);
      vx_data_tree::vx_package->t_leaf = output;
    }
    return output;
  }

  vx_data_tree::Type_leaflist e_leaflist() {
    vx_data_tree::Type_leaflist output = vx_data_tree::vx_package->e_leaflist;
    if (output == NULL) {
      output = new Class_leaflist();
      vx_core::vx_reserve_empty(output);
      vx_data_tree::vx_package->e_leaflist = output;
    }
    return output;
  }
  vx_data_tree::Type_leaflist t_leaflist() {
    vx_data_tree::Type_leaflist output = vx_data_tree::vx_package->t_leaflist;
    if (output == NULL) {
      output = new Class_leaflist();
      vx_core::vx_reserve_type(output);
      vx_data_tree::vx_package->t_leaflist = output;
    }
    return output;
  }

  vx_data_tree::Type_tree e_tree() {
    vx_data_tree::Type_tree output = vx_data_tree::vx_package->e_tree;
    if (output == NULL) {
      output = new Class_tree();
      vx_core::vx_reserve_empty(output);
      vx_data_tree::vx_package->e_tree = output;
    }
    return output;
  }
  vx_data_tree::Type_tree t_tree() {
    vx_data_tree::Type_tree output = vx_data_tree::vx_package->t_tree;
    if (output == NULL) {
      output = new Class_tree();
      vx_core::vx_reserve_type(output);
      vx_data_tree::vx_package->t_tree = output;
    }
    return output;
  }

  // (const brancharrow-down)
  vx_data_tree::Const_brancharrow_down c_brancharrow_down() {
    vx_data_tree::Const_brancharrow_down output = vx_data_tree::vx_package->c_brancharrow_down;
    if (output == NULL) {
      output = new vx_data_tree::Class_brancharrow_down();
      vx_core::vx_reserve_type(output);
      vx_data_tree::vx_package->c_brancharrow_down = output;
    }
    return output;
  }

  // (const brancharrow-up)
  vx_data_tree::Const_brancharrow_up c_brancharrow_up() {
    vx_data_tree::Const_brancharrow_up output = vx_data_tree::vx_package->c_brancharrow_up;
    if (output == NULL) {
      output = new vx_data_tree::Class_brancharrow_up();
      vx_core::vx_reserve_type(output);
      vx_data_tree::vx_package->c_brancharrow_up = output;
    }
    return output;
  }

  // (const brancharrow-updown)
  vx_data_tree::Const_brancharrow_updown c_brancharrow_updown() {
    vx_data_tree::Const_brancharrow_updown output = vx_data_tree::vx_package->c_brancharrow_updown;
    if (output == NULL) {
      output = new vx_data_tree::Class_brancharrow_updown();
      vx_core::vx_reserve_type(output);
      vx_data_tree::vx_package->c_brancharrow_updown = output;
    }
    return output;
  }

}