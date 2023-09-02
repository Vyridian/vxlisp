#include <string>
#include <vector>
#include "../vx/core.hpp"
#include "../vx/data/textblock.hpp"
#include "repl.hpp"

namespace vx_repl {
// :body

  // vx_string_from_listarg(type, liststring, context)
  std::string vx_string_from_listarg(vx_core::Type_any type, std::vector<std::string> listarg, vx_core::Type_context context) {
    std::string output = "";
    std::vector<vx_core::Type_any> listrepl;
    bool isfirst = true;
    for (std::string sarg : listarg) {
      if (isfirst) {
        isfirst = false;
      } else {
        vx_core::Type_any replval;
        if (vx_core::vx_is_int(sarg)) {
          replval = vx_core::vx_new_int(vx_core::vx_int_from_string(sarg));
        } else if (vx_core::vx_is_float(sarg)) {
          replval = vx_core::vx_new_float(vx_core::vx_float_from_string(sarg));
        } else {
          replval = vx_core::vx_new_string(sarg);
        }
        vx_repl::Type_repl argrepl = vx_core::vx_new(vx_repl::t_repl, {
          vx_core::vx_new_string(":val"), replval
        });
        listrepl.push_back(argrepl);
      }
    }
    vx_repl::Type_repl repl = vx_core::vx_new(vx_repl::t_repl, {
      vx_core::vx_new_string(":type"), type,
      vx_core::vx_new_string(":repllist"), vx_core::vx_new(vx_repl::t_repllist, listrepl)
    });
    vx_core::Type_any any = vx_repl::f_any_from_repl(repl, context);
    vx_core::Type_any anytype = any->vx_type();
    if (anytype == vx_core::t_string) {
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, any);
      output = text->vx_string();
    } else {
      output = vx_core::vx_string_from_any(any);
    }
    vx_core::vx_release(any);
    return output;
  }


  // (type liblist)
  // class Class_liblist {
    Abstract_liblist::~Abstract_liblist() {}

    Class_liblist::Class_liblist() : Abstract_liblist::Abstract_liblist() {
      vx_core::refcount += 1;
    }

    Class_liblist::~Class_liblist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_liblist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_core::Type_string Class_liblist::vx_get_string(vx_core::Type_int index) const {
      vx_core::Type_string output = vx_core::e_string;
      long iindex = index->vx_int();
      std::vector<vx_core::Type_string> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_core::Type_string> Class_liblist::vx_liststring() const {return vx_p_list;}

    vx_core::Type_any vx_repl::Class_liblist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_string(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_liblist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_repl::Type_liblist output = vx_repl::e_liblist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_core::Type_string> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_core::t_string) {
          vx_core::Type_string castval = vx_core::vx_any_from_any(vx_core::t_string, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(liblist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_repl::Class_liblist();
      output->vx_p_list = list;
      for (vx_core::Type_any valadd : list) {
        vx_core::vx_reserve(valadd);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(listval, output);
      return output;
    }

    vx_core::Type_any Class_liblist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_repl::e_liblist, vals);
    }

    vx_core::Type_any Class_liblist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Type_liblist output = vx_repl::e_liblist;
      vx_repl::Type_liblist val = vx_core::vx_any_from_any(vx_repl::t_liblist, copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_core::Type_string> listval = val->vx_liststring();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_string) {
          listval.push_back(vx_core::vx_any_from_any(vx_core::t_string, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_core::t_string)) {
          listval.push_back(vx_core::vx_any_from_any(vx_core::t_string, valsub));
        } else if (valsubtype == vx_repl::t_liblist) {
          vx_repl::Type_liblist multi = vx_core::vx_any_from_any(vx_repl::t_liblist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_liststring());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new liblist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_repl::Class_liblist();
      output->vx_p_list = listval;
      for (vx_core::Type_any valadd : listval) {
        vx_core::vx_reserve(valadd);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_liblist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_repl::Class_liblist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_liblist::vx_empty() const {return vx_repl::e_liblist;}
    vx_core::Type_any Class_liblist::vx_type() const {return vx_repl::t_liblist;}

    vx_core::Type_typedef Class_liblist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "liblist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_core::t_string}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

  //}

  // (type repl)
  // class Class_repl {
    Abstract_repl::~Abstract_repl() {}

    Class_repl::Class_repl() : Abstract_repl::Abstract_repl() {
      vx_core::refcount += 1;
    }

    Class_repl::~Class_repl() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_type,
        this->vx_p_repllist,
        this->vx_p_async,
        this->vx_p_val
      });
    }

    // type()
    vx_core::Type_any Class_repl::type() const {
      vx_core::Type_any output = this->vx_p_type;
      if (!output) {
        output = vx_core::e_any;
      }
      return output;
    }

    // repllist()
    vx_repl::Type_repllist Class_repl::repllist() const {
      vx_repl::Type_repllist output = this->vx_p_repllist;
      if (!output) {
        output = vx_repl::e_repllist;
      }
      return output;
    }

    // async()
    vx_core::Type_boolean Class_repl::async() const {
      vx_core::Type_boolean output = this->vx_p_async;
      if (!output) {
        output = vx_core::e_boolean;
      }
      return output;
    }

    // val()
    vx_core::Type_any Class_repl::val() const {
      vx_core::Type_any output = this->vx_p_val;
      if (!output) {
        output = vx_core::e_any;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_repl::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":type") {
        output = this->type();
      } else if (skey == ":repllist") {
        output = this->repllist();
      } else if (skey == ":async") {
        output = this->async();
      } else if (skey == ":val") {
        output = this->val();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_repl::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":type"] = this->type();
      output[":repllist"] = this->repllist();
      output[":async"] = this->async();
      output[":val"] = this->val();
      return output;
    }

    vx_core::Type_any Class_repl::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_repl::e_repl, vals);
    }

    vx_core::Type_any Class_repl::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Type_repl output = vx_repl::e_repl;
      vx_repl::Type_repl val = vx_core::vx_any_from_any(vx_repl::t_repl, copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_any vx_p_type = val->type();
      vx_repl::Type_repllist vx_p_repllist = val->repllist();
      vx_core::Type_boolean vx_p_async = val->async();
      vx_core::Type_any vx_p_val = val->val();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            testkey = valstr->vx_string();
          }
          if (false) {
          } else if (testkey == ":type") {
            key = testkey;
          } else if (testkey == ":repllist") {
            key = testkey;
          } else if (testkey == ":async") {
            key = testkey;
          } else if (testkey == ":val") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new repl) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":type") {
            vx_p_type = valsub;
          } else if (key == ":repllist") {
            if (valsubtype == vx_repl::t_repllist) {
              vx_p_repllist = vx_core::vx_any_from_any(vx_repl::t_repllist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new repl :repllist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":async") {
            if (valsubtype == vx_core::t_boolean) {
              vx_p_async = vx_core::vx_any_from_any(vx_core::t_boolean, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new repl :async " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":val") {
            vx_p_val = valsub;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new repl) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_repl::Class_repl();
      if (output->vx_p_type != vx_p_type) {
        if (output->vx_p_type) {
          vx_core::vx_release_one(output->vx_p_type);
        }
        output->vx_p_type = vx_p_type;
        vx_core::vx_reserve(vx_p_type);
      }
      if (output->vx_p_repllist != vx_p_repllist) {
        if (output->vx_p_repllist) {
          vx_core::vx_release_one(output->vx_p_repllist);
        }
        output->vx_p_repllist = vx_p_repllist;
        vx_core::vx_reserve(vx_p_repllist);
      }
      if (output->vx_p_async != vx_p_async) {
        if (output->vx_p_async) {
          vx_core::vx_release_one(output->vx_p_async);
        }
        output->vx_p_async = vx_p_async;
        vx_core::vx_reserve(vx_p_async);
      }
      if (output->vx_p_val != vx_p_val) {
        if (output->vx_p_val) {
          vx_core::vx_release_one(output->vx_p_val);
        }
        output->vx_p_val = vx_p_val;
        vx_core::vx_reserve(vx_p_val);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_repl::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_repl::Class_repl::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_repl::vx_empty() const {return vx_repl::e_repl;}
    vx_core::Type_any Class_repl::vx_type() const {return vx_repl::t_repl;}

    vx_core::Type_typedef Class_repl::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "repl", // name
        ":struct", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "type", // name
            vx_core::t_any // type
          ),
          vx_core::vx_new_arg(
            "repllist", // name
            vx_repl::t_repllist // type
          ),
          vx_core::vx_new_arg(
            "async", // name
            vx_core::t_boolean // type
          ),
          vx_core::vx_new_arg(
            "val", // name
            vx_core::t_any // type
          )
        }) // properties
      );
      return output;
    }

  //}

  // (type repllist)
  // class Class_repllist {
    Abstract_repllist::~Abstract_repllist() {}

    Class_repllist::Class_repllist() : Abstract_repllist::Abstract_repllist() {
      vx_core::refcount += 1;
    }

    Class_repllist::~Class_repllist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_repllist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_repl::Type_repl Class_repllist::vx_get_repl(vx_core::Type_int index) const {
      vx_repl::Type_repl output = vx_repl::e_repl;
      long iindex = index->vx_int();
      std::vector<vx_repl::Type_repl> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_repl::Type_repl> Class_repllist::vx_listrepl() const {return vx_p_list;}

    vx_core::Type_any vx_repl::Class_repllist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_repl(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_repllist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_repl::Type_repllist output = vx_repl::e_repllist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_repl::Type_repl> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_repl::t_repl) {
          vx_repl::Type_repl castval = vx_core::vx_any_from_any(vx_repl::t_repl, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(repllist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_repl::Class_repllist();
      output->vx_p_list = list;
      for (vx_core::Type_any valadd : list) {
        vx_core::vx_reserve(valadd);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(listval, output);
      return output;
    }

    vx_core::Type_any Class_repllist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_repl::e_repllist, vals);
    }

    vx_core::Type_any Class_repllist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Type_repllist output = vx_repl::e_repllist;
      vx_repl::Type_repllist val = vx_core::vx_any_from_any(vx_repl::t_repllist, copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_repl::Type_repl> listval = val->vx_listrepl();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_repl::t_repl) {
          listval.push_back(vx_core::vx_any_from_any(vx_repl::t_repl, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_repl::t_repl)) {
          listval.push_back(vx_core::vx_any_from_any(vx_repl::t_repl, valsub));
        } else if (valsubtype == vx_repl::t_repllist) {
          vx_repl::Type_repllist multi = vx_core::vx_any_from_any(vx_repl::t_repllist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listrepl());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new repllist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_repl::Class_repllist();
      output->vx_p_list = listval;
      for (vx_core::Type_any valadd : listval) {
        vx_core::vx_reserve(valadd);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_repllist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_repl::Class_repllist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_repllist::vx_empty() const {return vx_repl::e_repllist;}
    vx_core::Type_any Class_repllist::vx_type() const {return vx_repl::t_repllist;}

    vx_core::Type_typedef Class_repllist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "repllist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_repl::t_repl}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

  //}

  // (func any-repl<-functype-args)
  vx_core::Type_any f_any_repl_from_functype_args(vx_core::Type_any type, vx_core::Type_anylist args) {
    vx_core::Type_any output = vx_core::e_any;
    vx_core::vx_reserve({type, args});
    vx_core::Type_replfunc replfunc = dynamic_cast<vx_core::Type_replfunc>(type);
    output = replfunc->vx_repl(args);
    vx_core::vx_release_one_except({type, args}, output);
    return output;
  }

  // (func any-repl<-functype-args)
  // class Class_any_repl_from_functype_args {
    Abstract_any_repl_from_functype_args::~Abstract_any_repl_from_functype_args() {}

    Class_any_repl_from_functype_args::Class_any_repl_from_functype_args() : Abstract_any_repl_from_functype_args::Abstract_any_repl_from_functype_args() {
      vx_core::refcount += 1;
    }

    Class_any_repl_from_functype_args::~Class_any_repl_from_functype_args() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_any_repl_from_functype_args::vx_new(vx_core::vx_Type_listany vals) const {
      vx_repl::Func_any_repl_from_functype_args output = vx_repl::e_any_repl_from_functype_args;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_any_repl_from_functype_args::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Func_any_repl_from_functype_args output = vx_repl::e_any_repl_from_functype_args;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_any_repl_from_functype_args::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "any-repl<-functype-args", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_any_repl_from_functype_args::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "any-repl<-functype-args", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_any_repl_from_functype_args::vx_empty() const {return vx_repl::e_any_repl_from_functype_args;}
    vx_core::Type_any Class_any_repl_from_functype_args::vx_type() const {return vx_repl::t_any_repl_from_functype_args;}
    vx_core::Type_msgblock Class_any_repl_from_functype_args::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_repl_from_functype_args::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_any_repl_from_functype_args::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any type = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_anylist args = vx_core::vx_any_from_any(vx_core::t_anylist, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_repl::f_any_repl_from_functype_args(type, args);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func any<-liblist-string)
  vx_core::Type_any f_any_from_liblist_string(vx_repl::Type_liblist liblist, vx_core::Type_string text, vx_core::Type_context context) {
    vx_core::Type_any output = vx_core::e_any;
    vx_core::vx_reserve({liblist, text});
    output = vx_core::f_let(
      vx_core::t_any,
      vx_core::t_any_from_func->vx_fn_new({liblist, text, context}, [liblist, text, context]() {
        vx_repl::Type_repl repl = vx_repl::f_repl_from_liblist_string(liblist, text);
        vx_core::vx_ref_plus(repl);
        vx_core::Type_any output_1 = vx_repl::f_any_from_repl(repl, context);
        vx_core::vx_release_one_except(repl, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({liblist, text}, output);
    return output;
  }

  // (func any<-liblist-string)
  // class Class_any_from_liblist_string {
    Abstract_any_from_liblist_string::~Abstract_any_from_liblist_string() {}

    Class_any_from_liblist_string::Class_any_from_liblist_string() : Abstract_any_from_liblist_string::Abstract_any_from_liblist_string() {
      vx_core::refcount += 1;
    }

    Class_any_from_liblist_string::~Class_any_from_liblist_string() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_any_from_liblist_string::vx_new(vx_core::vx_Type_listany vals) const {
      vx_repl::Func_any_from_liblist_string output = vx_repl::e_any_from_liblist_string;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_any_from_liblist_string::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Func_any_from_liblist_string output = vx_repl::e_any_from_liblist_string;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_any_from_liblist_string::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "any<-liblist-string", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_any_from_liblist_string::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "any<-liblist-string", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_any_from_liblist_string::vx_empty() const {return vx_repl::e_any_from_liblist_string;}
    vx_core::Type_any Class_any_from_liblist_string::vx_type() const {return vx_repl::t_any_from_liblist_string;}
    vx_core::Type_msgblock Class_any_from_liblist_string::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_liblist_string::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_any_from_liblist_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_repl::Type_liblist liblist = vx_core::vx_any_from_any(vx_repl::t_liblist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_repl::f_any_from_liblist_string(liblist, text, context);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func any<-liblist-string-async)
  vx_core::vx_Type_async f_any_from_liblist_string_async(vx_repl::Type_liblist liblist, vx_core::Type_string text, vx_core::Type_context context) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve({liblist, text});
    output = vx_core::f_let_async(
      vx_core::t_any,
      vx_core::t_any_from_func_async->vx_fn_new({liblist, text, context}, [liblist, text, context]() {
        vx_repl::Type_repl repl = vx_repl::f_repl_from_liblist_string(liblist, text);
        vx_core::vx_ref_plus(repl);
        vx_core::vx_Type_async future_val = vx_repl::f_any_from_repl_async(repl, context);
        vx_core::vx_Type_fn_any_from_any fn_any_any_val = [](vx_core::Type_any any_val) {
          vx_core::Type_any val = vx_core::vx_any_from_any(vx_core::t_any, any_val);
          vx_core::vx_ref_plus(val);
          vx_core::Type_any output_2 = val;
          vx_core::vx_release_one_except(val, output_2);
          return output_2;
        };
        vx_core::vx_Type_async output_1 = vx_core::vx_async_from_async_fn(future_val, vx_core::t_any, {}, fn_any_any_val);
        vx_core::vx_release_one(repl);
        return output_1;
      })
    );
    vx_core::vx_release_one({liblist, text});
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_core::e_any);
    }
    return output;
  }

  // (func any<-liblist-string-async)
  // class Class_any_from_liblist_string_async {
    Abstract_any_from_liblist_string_async::~Abstract_any_from_liblist_string_async() {}

    Class_any_from_liblist_string_async::Class_any_from_liblist_string_async() : Abstract_any_from_liblist_string_async::Abstract_any_from_liblist_string_async() {
      vx_core::refcount += 1;
    }

    Class_any_from_liblist_string_async::~Class_any_from_liblist_string_async() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_any_from_liblist_string_async::vx_new(vx_core::vx_Type_listany vals) const {
      vx_repl::Func_any_from_liblist_string_async output = vx_repl::e_any_from_liblist_string_async;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_any_from_liblist_string_async::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Func_any_from_liblist_string_async output = vx_repl::e_any_from_liblist_string_async;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_any_from_liblist_string_async::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "any<-liblist-string-async", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_any_from_liblist_string_async::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "any<-liblist-string-async", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_any_from_liblist_string_async::vx_empty() const {return vx_repl::e_any_from_liblist_string_async;}
    vx_core::Type_any Class_any_from_liblist_string_async::vx_type() const {return vx_repl::t_any_from_liblist_string_async;}
    vx_core::Type_msgblock Class_any_from_liblist_string_async::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_liblist_string_async::vx_dispose() {return vx_core::emptylistany;}

    vx_core::vx_Type_async Class_any_from_liblist_string_async::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_value(vx_core::e_any);
      vx_repl::Type_liblist liblist = vx_core::vx_any_from_any(vx_repl::t_liblist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_repl::f_any_from_liblist_string_async(liblist, text, context);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  // (func any<-repl)
  vx_core::Type_any f_any_from_repl(vx_repl::Type_repl repl, vx_core::Type_context context) {
    vx_core::Type_any output = vx_core::e_any;
    vx_core::vx_reserve(repl);
    output = vx_core::f_let(
      vx_core::t_any,
      vx_core::t_any_from_func->vx_fn_new({repl, context}, [repl, context]() {
        vx_core::Type_any val = repl->val();
        vx_core::vx_ref_plus(val);
        vx_core::Type_any repltype = repl->type();
        vx_core::vx_ref_plus(repltype);
        vx_repl::Type_repllist repllist = repl->repllist();
        vx_core::vx_ref_plus(repllist);
        vx_core::Type_anylist args = vx_repl::f_anylist_from_repllist(repllist, context);
        vx_core::vx_ref_plus(args);
        vx_core::Type_any output_1 = vx_core::f_if_2(
          vx_core::t_any,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({val}, [val]() {
                vx_core::Type_boolean output_1 = vx_core::f_notempty_1(val);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({val}, [val]() {
                vx_core::Type_any output_1 = val;
                return output_1;
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({repltype}, [repltype]() {
                vx_core::Type_boolean output_1 = vx_core::f_is_func(repltype);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({repltype, args}, [repltype, args]() {
                vx_core::Type_any output_1 = vx_repl::f_any_repl_from_functype_args(repltype, args);
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({repltype, args}, [repltype, args]() {
                vx_core::Type_any output_1 = vx_core::f_new(repltype, args);
                return output_1;
              })
            )
          })
        );
        vx_core::vx_release_one_except({val, repltype, repllist, args}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(repl, output);
    return output;
  }

  // (func any<-repl)
  // class Class_any_from_repl {
    Abstract_any_from_repl::~Abstract_any_from_repl() {}

    Class_any_from_repl::Class_any_from_repl() : Abstract_any_from_repl::Abstract_any_from_repl() {
      vx_core::refcount += 1;
    }

    Class_any_from_repl::~Class_any_from_repl() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_any_from_repl::vx_new(vx_core::vx_Type_listany vals) const {
      vx_repl::Func_any_from_repl output = vx_repl::e_any_from_repl;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_any_from_repl::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Func_any_from_repl output = vx_repl::e_any_from_repl;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_any_from_repl::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "any<-repl", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_any_from_repl::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "any<-repl", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_any_from_repl::vx_empty() const {return vx_repl::e_any_from_repl;}
    vx_core::Type_any Class_any_from_repl::vx_type() const {return vx_repl::t_any_from_repl;}
    vx_core::Type_msgblock Class_any_from_repl::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_repl::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_any_from_repl::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_any_from_repl::vx_any_from_any_context(vx_core::Type_any val, vx_core::Type_context context) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_repl::Type_repl inputval = vx_core::vx_any_from_any(vx_repl::t_repl, val);
      output = vx_repl::f_any_from_repl(inputval, context);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_any_from_repl::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_repl::Type_repl repl = vx_core::vx_any_from_any(vx_repl::t_repl, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_repl::f_any_from_repl(repl, context);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func any<-repl-async)
  vx_core::vx_Type_async f_any_from_repl_async(vx_repl::Type_repl repl, vx_core::Type_context context) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_reserve(repl);
    vx_core::vx_release_one(repl);
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_core::e_any);
    }
    return output;
  }

  // (func any<-repl-async)
  // class Class_any_from_repl_async {
    Abstract_any_from_repl_async::~Abstract_any_from_repl_async() {}

    Class_any_from_repl_async::Class_any_from_repl_async() : Abstract_any_from_repl_async::Abstract_any_from_repl_async() {
      vx_core::refcount += 1;
    }

    Class_any_from_repl_async::~Class_any_from_repl_async() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_any_from_repl_async::vx_new(vx_core::vx_Type_listany vals) const {
      vx_repl::Func_any_from_repl_async output = vx_repl::e_any_from_repl_async;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_any_from_repl_async::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Func_any_from_repl_async output = vx_repl::e_any_from_repl_async;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_any_from_repl_async::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "any<-repl-async", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_any_from_repl_async::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "any<-repl-async", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_any_from_repl_async::vx_empty() const {return vx_repl::e_any_from_repl_async;}
    vx_core::Type_any Class_any_from_repl_async::vx_type() const {return vx_repl::t_any_from_repl_async;}
    vx_core::Type_msgblock Class_any_from_repl_async::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_repl_async::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context_async Class_any_from_repl_async::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context_async::IFn fn) const {
      return vx_core::e_any_from_any_context_async;
    }

    vx_core::vx_Type_async Class_any_from_repl_async::vx_any_from_any_context_async(vx_core::Type_any generic_any_1, vx_core::Type_any val, vx_core::Type_context context) const {
      vx_repl::Type_repl inputval = vx_core::vx_any_from_any(vx_repl::t_repl, val);
      vx_core::vx_Type_async output = vx_repl::f_any_from_repl_async(inputval, context);
      vx_core::vx_release(val);
      return output;
    }

    vx_core::vx_Type_async Class_any_from_repl_async::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_value(vx_core::e_any);
      vx_repl::Type_repl repl = vx_core::vx_any_from_any(vx_repl::t_repl, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_repl::f_any_from_repl_async(repl, context);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  // (func anylist<-repllist)
  vx_core::Type_anylist f_anylist_from_repllist(vx_repl::Type_repllist repllist, vx_core::Type_context context) {
    vx_core::Type_anylist output = vx_core::e_anylist;
    vx_core::vx_reserve(repllist);
    output = vx_core::f_list_from_list(
      vx_core::t_anylist,
      repllist,
      vx_core::t_any_from_any->vx_fn_new({context}, [context](vx_core::Type_any repl_any) {
        vx_repl::Type_repl repl = vx_core::vx_any_from_any(vx_repl::t_repl, repl_any);
        vx_core::Type_any output_1 = 
          vx_repl::f_any_from_repl(repl, context);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(repllist, output);
    return output;
  }

  // (func anylist<-repllist)
  // class Class_anylist_from_repllist {
    Abstract_anylist_from_repllist::~Abstract_anylist_from_repllist() {}

    Class_anylist_from_repllist::Class_anylist_from_repllist() : Abstract_anylist_from_repllist::Abstract_anylist_from_repllist() {
      vx_core::refcount += 1;
    }

    Class_anylist_from_repllist::~Class_anylist_from_repllist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_anylist_from_repllist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_repl::Func_anylist_from_repllist output = vx_repl::e_anylist_from_repllist;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_anylist_from_repllist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Func_anylist_from_repllist output = vx_repl::e_anylist_from_repllist;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_anylist_from_repllist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "anylist<-repllist", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_anylist_from_repllist::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "anylist<-repllist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_anylist_from_repllist::vx_empty() const {return vx_repl::e_anylist_from_repllist;}
    vx_core::Type_any Class_anylist_from_repllist::vx_type() const {return vx_repl::t_anylist_from_repllist;}
    vx_core::Type_msgblock Class_anylist_from_repllist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_anylist_from_repllist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_anylist_from_repllist::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_anylist_from_repllist::vx_any_from_any_context(vx_core::Type_any val, vx_core::Type_context context) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_repl::Type_repllist inputval = vx_core::vx_any_from_any(vx_repl::t_repllist, val);
      output = vx_repl::f_anylist_from_repllist(inputval, context);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_anylist_from_repllist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_repl::Type_repllist repllist = vx_core::vx_any_from_any(vx_repl::t_repllist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_repl::f_anylist_from_repllist(repllist, context);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func repl<-liblist-string)
  vx_repl::Type_repl f_repl_from_liblist_string(vx_repl::Type_liblist liblist, vx_core::Type_string text) {
    vx_repl::Type_repl output = vx_repl::e_repl;
    vx_core::vx_reserve({liblist, text});
    vx_core::vx_release_one_except({liblist, text}, output);
    return output;
  }

  // (func repl<-liblist-string)
  // class Class_repl_from_liblist_string {
    Abstract_repl_from_liblist_string::~Abstract_repl_from_liblist_string() {}

    Class_repl_from_liblist_string::Class_repl_from_liblist_string() : Abstract_repl_from_liblist_string::Abstract_repl_from_liblist_string() {
      vx_core::refcount += 1;
    }

    Class_repl_from_liblist_string::~Class_repl_from_liblist_string() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_repl_from_liblist_string::vx_new(vx_core::vx_Type_listany vals) const {
      vx_repl::Func_repl_from_liblist_string output = vx_repl::e_repl_from_liblist_string;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_repl_from_liblist_string::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Func_repl_from_liblist_string output = vx_repl::e_repl_from_liblist_string;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_repl_from_liblist_string::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "repl<-liblist-string", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_repl_from_liblist_string::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "repl<-liblist-string", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_repl_from_liblist_string::vx_empty() const {return vx_repl::e_repl_from_liblist_string;}
    vx_core::Type_any Class_repl_from_liblist_string::vx_type() const {return vx_repl::t_repl_from_liblist_string;}
    vx_core::Type_msgblock Class_repl_from_liblist_string::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_repl_from_liblist_string::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_repl_from_liblist_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_repl::Type_liblist liblist = vx_core::vx_any_from_any(vx_repl::t_liblist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_repl::f_repl_from_liblist_string(liblist, text);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_repl::vx_Class_package* vx_package = new vx_repl::vx_Class_package();

  vx_repl::Type_liblist vx_e_liblist() {
    vx_repl::Type_liblist output;
      output = new Class_liblist();
      vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_repl::Type_liblist vx_t_liblist() {
    vx_repl::Type_liblist output = new Class_liblist();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_repl::Type_liblist e_liblist = vx_e_liblist();
  vx_repl::Type_liblist t_liblist = vx_t_liblist();

  vx_repl::Type_repl vx_e_repl() {
    vx_repl::Type_repl output;
      output = new Class_repl();
      vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_repl::Type_repl vx_t_repl() {
    vx_repl::Type_repl output = new Class_repl();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_repl::Type_repl e_repl = vx_e_repl();
  vx_repl::Type_repl t_repl = vx_t_repl();

  vx_repl::Type_repllist vx_e_repllist() {
    vx_repl::Type_repllist output;
      output = new Class_repllist();
      vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_repl::Type_repllist vx_t_repllist() {
    vx_repl::Type_repllist output = new Class_repllist();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_repl::Type_repllist e_repllist = vx_e_repllist();
  vx_repl::Type_repllist t_repllist = vx_t_repllist();

  // (func any-repl<-functype-args)
  vx_repl::Func_any_repl_from_functype_args vx_e_any_repl_from_functype_args() {
    vx_repl::Func_any_repl_from_functype_args output = new vx_repl::Class_any_repl_from_functype_args();
    vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_repl::Func_any_repl_from_functype_args vx_t_any_repl_from_functype_args() {
    vx_repl::Func_any_repl_from_functype_args output = new vx_repl::Class_any_repl_from_functype_args();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_repl::Func_any_repl_from_functype_args e_any_repl_from_functype_args = vx_e_any_repl_from_functype_args();
  vx_repl::Func_any_repl_from_functype_args t_any_repl_from_functype_args = vx_t_any_repl_from_functype_args();

  // (func any<-liblist-string)
  vx_repl::Func_any_from_liblist_string vx_e_any_from_liblist_string() {
    vx_repl::Func_any_from_liblist_string output = new vx_repl::Class_any_from_liblist_string();
    vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_repl::Func_any_from_liblist_string vx_t_any_from_liblist_string() {
    vx_repl::Func_any_from_liblist_string output = new vx_repl::Class_any_from_liblist_string();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_repl::Func_any_from_liblist_string e_any_from_liblist_string = vx_e_any_from_liblist_string();
  vx_repl::Func_any_from_liblist_string t_any_from_liblist_string = vx_t_any_from_liblist_string();

  // (func any<-liblist-string-async)
  vx_repl::Func_any_from_liblist_string_async vx_e_any_from_liblist_string_async() {
    vx_repl::Func_any_from_liblist_string_async output = new vx_repl::Class_any_from_liblist_string_async();
    vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_repl::Func_any_from_liblist_string_async vx_t_any_from_liblist_string_async() {
    vx_repl::Func_any_from_liblist_string_async output = new vx_repl::Class_any_from_liblist_string_async();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_repl::Func_any_from_liblist_string_async e_any_from_liblist_string_async = vx_e_any_from_liblist_string_async();
  vx_repl::Func_any_from_liblist_string_async t_any_from_liblist_string_async = vx_t_any_from_liblist_string_async();

  // (func any<-repl)
  vx_repl::Func_any_from_repl vx_e_any_from_repl() {
    vx_repl::Func_any_from_repl output = new vx_repl::Class_any_from_repl();
    vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_repl::Func_any_from_repl vx_t_any_from_repl() {
    vx_repl::Func_any_from_repl output = new vx_repl::Class_any_from_repl();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_repl::Func_any_from_repl e_any_from_repl = vx_e_any_from_repl();
  vx_repl::Func_any_from_repl t_any_from_repl = vx_t_any_from_repl();

  // (func any<-repl-async)
  vx_repl::Func_any_from_repl_async vx_e_any_from_repl_async() {
    vx_repl::Func_any_from_repl_async output = new vx_repl::Class_any_from_repl_async();
    vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_repl::Func_any_from_repl_async vx_t_any_from_repl_async() {
    vx_repl::Func_any_from_repl_async output = new vx_repl::Class_any_from_repl_async();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_repl::Func_any_from_repl_async e_any_from_repl_async = vx_e_any_from_repl_async();
  vx_repl::Func_any_from_repl_async t_any_from_repl_async = vx_t_any_from_repl_async();

  // (func anylist<-repllist)
  vx_repl::Func_anylist_from_repllist vx_e_anylist_from_repllist() {
    vx_repl::Func_anylist_from_repllist output = new vx_repl::Class_anylist_from_repllist();
    vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_repl::Func_anylist_from_repllist vx_t_anylist_from_repllist() {
    vx_repl::Func_anylist_from_repllist output = new vx_repl::Class_anylist_from_repllist();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_repl::Func_anylist_from_repllist e_anylist_from_repllist = vx_e_anylist_from_repllist();
  vx_repl::Func_anylist_from_repllist t_anylist_from_repllist = vx_t_anylist_from_repllist();

  // (func repl<-liblist-string)
  vx_repl::Func_repl_from_liblist_string vx_e_repl_from_liblist_string() {
    vx_repl::Func_repl_from_liblist_string output = new vx_repl::Class_repl_from_liblist_string();
    vx_core::vx_reserve_empty(output);
    return output;
  }
  vx_repl::Func_repl_from_liblist_string vx_t_repl_from_liblist_string() {
    vx_repl::Func_repl_from_liblist_string output = new vx_repl::Class_repl_from_liblist_string();
    vx_core::vx_reserve_type(output);
    return output;
  }
  vx_repl::Func_repl_from_liblist_string e_repl_from_liblist_string = vx_e_repl_from_liblist_string();
  vx_repl::Func_repl_from_liblist_string t_repl_from_liblist_string = vx_t_repl_from_liblist_string();

}
