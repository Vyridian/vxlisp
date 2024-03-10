#include <string>
#include <vector>
#include "../vx/core.hpp"
#include "../vx/collection.hpp"
#include "../vx/type.hpp"
#include "../vx/data/textblock.hpp"
#include "repl.hpp"

namespace vx_repl {

// :body

  // vx_string_from_listarg(context, type, liststring)
  std::string vx_string_from_listarg(vx_core::Type_context context, vx_core::Type_any type, std::vector<std::string> listarg) {
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
    vx_core::Type_any any = vx_repl::f_any_from_repl(context, repl);
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
        } else if (vx_core::vx_boolean_from_type_trait(valtype, vx_core::t_string)) {
          vx_core::Type_string castval = vx_core::vx_any_from_any(vx_core::t_string, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(liblist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((list.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_repl::Class_liblist();
        output->vx_p_list = list;
        for (vx_core::Type_any valadd : list) {
          vx_core::vx_reserve(valadd);
        }
        if (msgblock != vx_core::e_msgblock) {
          output->vx_p_msgblock = msgblock;
          vx_core::vx_reserve(msgblock);
        }
      }
      vx_core::vx_release_except(listval, output);
      return output;
    }

    vx_core::Type_any Class_liblist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_repl::e_liblist, vals);
    }

    vx_core::Type_any Class_liblist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Type_liblist output = vx_repl::e_liblist;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_repl::Type_liblist val = vx_core::vx_any_from_any(vx_repl::t_liblist, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_core::Type_string> listval = val->vx_liststring();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_string) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_core::t_string, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_core::t_string)) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_core::t_string, valsub));
        } else if (valsubtype == vx_repl::t_liblist) {
          ischanged = true;
          vx_repl::Type_liblist multi = vx_core::vx_any_from_any(vx_repl::t_liblist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_liststring());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new liblist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if (ischanged || (listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_repl::Class_liblist();
        output->vx_p_list = listval;
        for (vx_core::Type_any valadd : listval) {
          vx_core::vx_reserve(valadd);
        }
        if (msgblock != vx_core::e_msgblock) {
          output->vx_p_msgblock = msgblock;
          vx_core::vx_reserve(msgblock);
        }
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

    vx_core::Type_constdef Class_liblist::vx_constdef() const {return this->vx_p_constdef;}


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
        this->vx_p_name,
        this->vx_p_type,
        this->vx_p_repllist,
        this->vx_p_async,
        this->vx_p_val,
        this->vx_p_doc
      });
    }

    // name()
    vx_core::Type_string Class_repl::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
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

    // doc()
    vx_core::Type_string Class_repl::doc() const {
      vx_core::Type_string output = this->vx_p_doc;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_repl::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":type") {
        output = this->type();
      } else if (skey == ":repllist") {
        output = this->repllist();
      } else if (skey == ":async") {
        output = this->async();
      } else if (skey == ":val") {
        output = this->val();
      } else if (skey == ":doc") {
        output = this->doc();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_repl::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":name"] = this->name();
      output[":type"] = this->type();
      output[":repllist"] = this->repllist();
      output[":async"] = this->async();
      output[":val"] = this->val();
      output[":doc"] = this->doc();
      return output;
    }

    vx_core::Type_any Class_repl::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_repl::e_repl, vals);
    }

    vx_core::Type_any Class_repl::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Type_repl output = vx_repl::e_repl;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_repl::Type_repl val = vx_core::vx_any_from_any(vx_repl::t_repl, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_name = val->name();
      vx_core::Type_any vx_p_type = val->type();
      vx_repl::Type_repllist vx_p_repllist = val->repllist();
      vx_core::Type_boolean vx_p_async = val->async();
      vx_core::Type_any vx_p_val = val->val();
      vx_core::Type_string vx_p_doc = val->doc();
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
          } else if (testkey == ":name") {
            key = testkey;
          } else if (testkey == ":type") {
            key = testkey;
          } else if (testkey == ":repllist") {
            key = testkey;
          } else if (testkey == ":async") {
            key = testkey;
          } else if (testkey == ":val") {
            key = testkey;
          } else if (testkey == ":doc") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new repl) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":name") {
            if (vx_p_name == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_name = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new repl :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":type") {
            if (vx_p_type != valsub) {
              ischanged = true;
              vx_p_type = valsub;
            }
          } else if (key == ":repllist") {
            if (vx_p_repllist == valsub) {
            } else if (valsubtype == vx_repl::t_repllist) {
              ischanged = true;
              vx_p_repllist = vx_core::vx_any_from_any(vx_repl::t_repllist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new repl :repllist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":async") {
            if (vx_p_async == valsub) {
            } else if (valsubtype == vx_core::t_boolean) {
              ischanged = true;
              vx_p_async = vx_core::vx_any_from_any(vx_core::t_boolean, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new repl :async " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":val") {
            if (vx_p_val != valsub) {
              ischanged = true;
              vx_p_val = valsub;
            }
          } else if (key == ":doc") {
            if (vx_p_doc == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_doc = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new repl :doc " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new repl) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_repl::Class_repl();
        if (output->vx_p_name != vx_p_name) {
          if (output->vx_p_name) {
            vx_core::vx_release_one(output->vx_p_name);
          }
          output->vx_p_name = vx_p_name;
          vx_core::vx_reserve(vx_p_name);
        }
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
        if (output->vx_p_doc != vx_p_doc) {
          if (output->vx_p_doc) {
            vx_core::vx_release_one(output->vx_p_doc);
          }
          output->vx_p_doc = vx_p_doc;
          vx_core::vx_reserve(vx_p_doc);
        }
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
            "name", // name
            vx_core::t_string // type
          ),
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
          ),
          vx_core::vx_new_arg(
            "doc", // name
            vx_core::t_string // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_repl::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type replarglist)
  // class Class_replarglist {
    Abstract_replarglist::~Abstract_replarglist() {}

    Class_replarglist::Class_replarglist() : Abstract_replarglist::Abstract_replarglist() {
      vx_core::refcount += 1;
    }

    Class_replarglist::~Class_replarglist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_key,
        this->vx_p_current,
        this->vx_p_repllist
      });
    }

    // key()
    vx_core::Type_string Class_replarglist::key() const {
      vx_core::Type_string output = this->vx_p_key;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // current()
    vx_repl::Type_repl Class_replarglist::current() const {
      vx_repl::Type_repl output = this->vx_p_current;
      if (!output) {
        output = vx_repl::e_repl;
      }
      return output;
    }

    // repllist()
    vx_repl::Type_repllist Class_replarglist::repllist() const {
      vx_repl::Type_repllist output = this->vx_p_repllist;
      if (!output) {
        output = vx_repl::e_repllist;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_replarglist::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":key") {
        output = this->key();
      } else if (skey == ":current") {
        output = this->current();
      } else if (skey == ":repllist") {
        output = this->repllist();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_replarglist::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":key"] = this->key();
      output[":current"] = this->current();
      output[":repllist"] = this->repllist();
      return output;
    }

    vx_core::Type_any Class_replarglist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_repl::e_replarglist, vals);
    }

    vx_core::Type_any Class_replarglist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Type_replarglist output = vx_repl::e_replarglist;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_repl::Type_replarglist val = vx_core::vx_any_from_any(vx_repl::t_replarglist, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_key = val->key();
      vx_repl::Type_repl vx_p_current = val->current();
      vx_repl::Type_repllist vx_p_repllist = val->repllist();
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
          } else if (testkey == ":key") {
            key = testkey;
          } else if (testkey == ":current") {
            key = testkey;
          } else if (testkey == ":repllist") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new replarglist) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":key") {
            if (vx_p_key == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_key = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new replarglist :key " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":current") {
            if (vx_p_current == valsub) {
            } else if (valsubtype == vx_repl::t_repl) {
              ischanged = true;
              vx_p_current = vx_core::vx_any_from_any(vx_repl::t_repl, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new replarglist :current " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":repllist") {
            if (vx_p_repllist == valsub) {
            } else if (valsubtype == vx_repl::t_repllist) {
              ischanged = true;
              vx_p_repllist = vx_core::vx_any_from_any(vx_repl::t_repllist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new replarglist :repllist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new replarglist) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_repl::Class_replarglist();
        if (output->vx_p_key != vx_p_key) {
          if (output->vx_p_key) {
            vx_core::vx_release_one(output->vx_p_key);
          }
          output->vx_p_key = vx_p_key;
          vx_core::vx_reserve(vx_p_key);
        }
        if (output->vx_p_current != vx_p_current) {
          if (output->vx_p_current) {
            vx_core::vx_release_one(output->vx_p_current);
          }
          output->vx_p_current = vx_p_current;
          vx_core::vx_reserve(vx_p_current);
        }
        if (output->vx_p_repllist != vx_p_repllist) {
          if (output->vx_p_repllist) {
            vx_core::vx_release_one(output->vx_p_repllist);
          }
          output->vx_p_repllist = vx_p_repllist;
          vx_core::vx_reserve(vx_p_repllist);
        }
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_replarglist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_repl::Class_replarglist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_replarglist::vx_empty() const {return vx_repl::e_replarglist;}
    vx_core::Type_any Class_replarglist::vx_type() const {return vx_repl::t_replarglist;}

    vx_core::Type_typedef Class_replarglist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "replarglist", // name
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
            "key", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "current", // name
            vx_repl::t_repl // type
          ),
          vx_core::vx_new_arg(
            "repllist", // name
            vx_repl::t_repllist // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_replarglist::vx_constdef() const {return this->vx_p_constdef;}


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
        } else if (vx_core::vx_boolean_from_type_trait(valtype, vx_repl::t_repl)) {
          vx_repl::Type_repl castval = vx_core::vx_any_from_any(vx_repl::t_repl, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(repllist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((list.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_repl::Class_repllist();
        output->vx_p_list = list;
        for (vx_core::Type_any valadd : list) {
          vx_core::vx_reserve(valadd);
        }
        if (msgblock != vx_core::e_msgblock) {
          output->vx_p_msgblock = msgblock;
          vx_core::vx_reserve(msgblock);
        }
      }
      vx_core::vx_release_except(listval, output);
      return output;
    }

    vx_core::Type_any Class_repllist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_repl::e_repllist, vals);
    }

    vx_core::Type_any Class_repllist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Type_repllist output = vx_repl::e_repllist;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_repl::Type_repllist val = vx_core::vx_any_from_any(vx_repl::t_repllist, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_repl::Type_repl> listval = val->vx_listrepl();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_repl::t_repl) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_repl::t_repl, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_repl::t_repl)) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_repl::t_repl, valsub));
        } else if (valsubtype == vx_repl::t_repllist) {
          ischanged = true;
          vx_repl::Type_repllist multi = vx_core::vx_any_from_any(vx_repl::t_repllist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listrepl());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new repllist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if (ischanged || (listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_repl::Class_repllist();
        output->vx_p_list = listval;
        for (vx_core::Type_any valadd : listval) {
          vx_core::vx_reserve(valadd);
        }
        if (msgblock != vx_core::e_msgblock) {
          output->vx_p_msgblock = msgblock;
          vx_core::vx_reserve(msgblock);
        }
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

    vx_core::Type_constdef Class_repllist::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (const delimvxlisp)
  // class Class_delimvxlisp {
    // vx_const_new()
    void vx_repl::Class_delimvxlisp::vx_const_new(vx_repl::Const_delimvxlisp output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/repl", "delimvxlisp");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimvxlisp"),
          vx_core::vx_new_string(":delimlist"),
          vx_core::f_new(
            vx_data_textblock::t_delimlist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_repl::c_delimvxlispparen,
              vx_data_textblock::c_delimcomment,
              vx_data_textblock::c_delimcommentblock
            })
          )
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_starttext = val->starttext();
      vx_core::vx_reserve(output->vx_p_starttext);
      output->vx_p_endtext = val->endtext();
      vx_core::vx_reserve(output->vx_p_endtext);
      output->vx_p_pos = val->pos();
      vx_core::vx_reserve(output->vx_p_pos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const delimvxlispbracket)
  // class Class_delimvxlispbracket {
    // vx_const_new()
    void vx_repl::Class_delimvxlispbracket::vx_const_new(vx_repl::Const_delimvxlispbracket output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/repl", "delimvxlispbracket");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_copy(
        vx_data_textblock::t_delim,
        vx_data_textblock::c_delimbracketsquare,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimvxlispbracketsquare"),
          vx_core::vx_new_string(":delimlist"),
          vx_core::f_new(
            vx_data_textblock::t_delimlist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_data_textblock::c_delimcomment,
              vx_data_textblock::c_delimcommentblock,
              vx_data_textblock::c_delimquote,
              vx_data_textblock::c_delimquoteblock,
              vx_data_textblock::c_delimwhitespace,
              vx_repl::c_delimvxlispparen
            })
          )
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_starttext = val->starttext();
      vx_core::vx_reserve(output->vx_p_starttext);
      output->vx_p_endtext = val->endtext();
      vx_core::vx_reserve(output->vx_p_endtext);
      output->vx_p_pos = val->pos();
      vx_core::vx_reserve(output->vx_p_pos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const delimvxlispparen)
  // class Class_delimvxlispparen {
    // vx_const_new()
    void vx_repl::Class_delimvxlispparen::vx_const_new(vx_repl::Const_delimvxlispparen output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/repl", "delimvxlispparen");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_copy(
        vx_data_textblock::t_delim,
        vx_data_textblock::c_delimparen,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimvxlispparen"),
          vx_core::vx_new_string(":delimlist"),
          vx_core::f_new(
            vx_data_textblock::t_delimlist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_data_textblock::c_delimcomment,
              vx_data_textblock::c_delimcommentblock,
              vx_data_textblock::c_delimquote,
              vx_data_textblock::c_delimquoteblock,
              vx_data_textblock::c_delimwhitespace,
              vx_repl::c_delimvxlispbracket,
              vx_repl::c_delimvxlispparen
            })
          )
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_starttext = val->starttext();
      vx_core::vx_reserve(output->vx_p_starttext);
      output->vx_p_endtext = val->endtext();
      vx_core::vx_reserve(output->vx_p_endtext);
      output->vx_p_pos = val->pos();
      vx_core::vx_reserve(output->vx_p_pos);
      output->vx_p_delimlist = val->delimlist();
      vx_core::vx_reserve(output->vx_p_delimlist);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
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
  /**
   * @function any_repl_from_functype_args
   * Returns any from a repl func and args.
   * @param  {any} type
   * @param  {anylist} args
   * @return {any}
   * (func any-repl<-functype-args)
   */
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
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_any_repl_from_functype_args::vx_constdef() const {return this->vx_p_constdef;}

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
  vx_core::Type_any f_any_from_liblist_string(vx_core::Type_context context, vx_repl::Type_liblist liblist, vx_core::Type_string text) {
    vx_core::Type_any output = vx_core::e_any;
    vx_core::vx_reserve({liblist, text});
    output = vx_core::f_let(
      vx_core::t_any,
      vx_core::t_any_from_func->vx_fn_new({liblist, text, context}, [liblist, text, context]() {
        vx_repl::Type_repl repl = vx_repl::f_repl_from_liblist_string(liblist, text);
        vx_core::vx_ref_plus(repl);
        vx_core::Type_any output_1 = vx_repl::f_any_from_repl(context, repl);
        vx_core::vx_release_one_except(repl, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({liblist, text}, output);
    return output;
  }
  /**
   * @function any_from_liblist_string
   * Run an arbitrary program in the REPL.
   * @param  {liblist} liblist
   * @param  {string} text Program to run
   * @return {any}
   * (func any<-liblist-string)
   */
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
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_any_from_liblist_string::vx_constdef() const {return this->vx_p_constdef;}

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
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_repl::Type_liblist liblist = vx_core::vx_any_from_any(vx_repl::t_liblist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_repl::f_any_from_liblist_string(context, liblist, text);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}
  /**
   * @function any_from_macro
   * A function that joins any number of values into a string and then parses and evaluates it.
   * @param  {anylist} anylist
   * @return {any-1}
   * (func any<-macro)
   */
  // (func any<-macro)
  // class Class_any_from_macro {
    Abstract_any_from_macro::~Abstract_any_from_macro() {}

    Class_any_from_macro::Class_any_from_macro() : Abstract_any_from_macro::Abstract_any_from_macro() {
      vx_core::refcount += 1;
    }

    Class_any_from_macro::~Class_any_from_macro() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_any_from_macro::vx_new(vx_core::vx_Type_listany vals) const {
      vx_repl::Func_any_from_macro output = vx_repl::e_any_from_macro;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_any_from_macro::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Func_any_from_macro output = vx_repl::e_any_from_macro;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_any_from_macro::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "any<-macro", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_any_from_macro::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_any_from_macro::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "any<-macro", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_any_from_macro::vx_empty() const {return vx_repl::e_any_from_macro;}
    vx_core::Type_any Class_any_from_macro::vx_type() const {return vx_repl::t_any_from_macro;}
    vx_core::Type_msgblock Class_any_from_macro::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_macro::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_any_from_macro::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_any_from_macro::vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_anylist inputval = vx_core::vx_any_from_any(vx_core::t_anylist, val);
      output = vx_repl::f_any_from_macro(vx_core::t_any, context, inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_any_from_macro::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_anylist anylist = vx_core::vx_any_from_any(vx_core::t_anylist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_repl::f_any_from_macro(generic_any_1, context, anylist);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func any<-repl)
  vx_core::Type_any f_any_from_repl(vx_core::Type_context context, vx_repl::Type_repl repl) {
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
        vx_core::Type_anylist args = vx_repl::f_anylist_from_repllist(context, repllist);
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
  /**
   * @function any_from_repl
   * Run an arbitrary program in the REPL.
   * @param  {repl} repl
   * @return {any}
   * (func any<-repl)
   */
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
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_any_from_repl::vx_constdef() const {return this->vx_p_constdef;}

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

    vx_core::Type_any Class_any_from_repl::vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_repl::Type_repl inputval = vx_core::vx_any_from_any(vx_repl::t_repl, val);
      output = vx_repl::f_any_from_repl(context, inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_any_from_repl::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_repl::Type_repl repl = vx_core::vx_any_from_any(vx_repl::t_repl, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_repl::f_any_from_repl(context, repl);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func any<-script)
  vx_core::Type_any f_any_from_script(vx_core::Type_context context, vx_core::Type_string script) {
    vx_core::Type_any output = vx_core::e_any;
    vx_core::vx_reserve(script);
    output = vx_core::f_let(
      vx_core::t_any,
      vx_core::t_any_from_func->vx_fn_new({script, context}, [script, context]() {
        vx_data_textblock::Type_textblock textblock = vx_repl::f_textblock_from_script(script);
        vx_core::vx_ref_plus(textblock);
        vx_repl::Type_repl repl = vx_repl::f_repl_from_textblock(textblock);
        vx_core::vx_ref_plus(repl);
        vx_core::Type_any output_1 = vx_repl::f_any_from_repl(context, repl);
        vx_core::vx_release_one_except({textblock, repl}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(script, output);
    return output;
  }
  /**
   * @function any_from_script
   * Run an arbitrary script.
   * @param  {string} script
   * @return {any}
   * (func any<-script)
   */
  // (func any<-script)
  // class Class_any_from_script {
    Abstract_any_from_script::~Abstract_any_from_script() {}

    Class_any_from_script::Class_any_from_script() : Abstract_any_from_script::Abstract_any_from_script() {
      vx_core::refcount += 1;
    }

    Class_any_from_script::~Class_any_from_script() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_any_from_script::vx_new(vx_core::vx_Type_listany vals) const {
      vx_repl::Func_any_from_script output = vx_repl::e_any_from_script;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_any_from_script::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Func_any_from_script output = vx_repl::e_any_from_script;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_any_from_script::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "any<-script", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_any_from_script::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_any_from_script::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "any<-script", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_any_from_script::vx_empty() const {return vx_repl::e_any_from_script;}
    vx_core::Type_any Class_any_from_script::vx_type() const {return vx_repl::t_any_from_script;}
    vx_core::Type_msgblock Class_any_from_script::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_script::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_any_from_script::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_any_from_script::vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      output = vx_repl::f_any_from_script(context, inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_any_from_script::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string script = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_repl::f_any_from_script(context, script);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func anylist<-repllist)
  vx_core::Type_anylist f_anylist_from_repllist(vx_core::Type_context context, vx_repl::Type_repllist repllist) {
    vx_core::Type_anylist output = vx_core::e_anylist;
    vx_core::vx_reserve(repllist);
    output = vx_core::f_list_from_list_1(
      vx_core::t_anylist,
      repllist,
      vx_core::t_any_from_any->vx_fn_new({context}, [context](vx_core::Type_any repl_any) {
        vx_repl::Type_repl repl = vx_core::vx_any_from_any(vx_repl::t_repl, repl_any);
        vx_core::Type_any output_1 = 
          vx_repl::f_any_from_repl(context, repl);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(repllist, output);
    return output;
  }
  /**
   * @function anylist_from_repllist
   * Run an arbitrary program in the REPL.
   * @param  {repllist} repllist
   * @return {anylist}
   * (func anylist<-repllist)
   */
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
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_anylist_from_repllist::vx_constdef() const {return this->vx_p_constdef;}

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

    vx_core::Type_any Class_anylist_from_repllist::vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_repl::Type_repllist inputval = vx_core::vx_any_from_any(vx_repl::t_repllist, val);
      output = vx_repl::f_anylist_from_repllist(context, inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_anylist_from_repllist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_repl::Type_repllist repllist = vx_core::vx_any_from_any(vx_repl::t_repllist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_repl::f_anylist_from_repllist(context, repllist);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func argmap<-textblock-argmap)
  vx_core::Type_argmap f_argmap_from_textblock_argmap(vx_data_textblock::Type_textblock textblock, vx_core::Type_argmap argmap) {
    vx_core::Type_argmap output = vx_core::e_argmap;
    vx_core::vx_reserve({textblock, argmap});
    output = vx_core::f_if_1(
      vx_core::t_argmap,
      vx_core::f_ne(
        vx_core::vx_new_string("delimbracketsquare"),
        vx_core::f_any_from_struct(
          vx_core::t_string,
          textblock->delim(),
          vx_core::vx_new_string(":name")
        )
      ),
      argmap,
      argmap
    );
    vx_core::vx_release_one_except({textblock, argmap}, output);
    return output;
  }
  /**
   * @function argmap_from_textblock_argmap
   * Returns an argmap with parsed args from textblock added.
   * @param  {textblock} textblock
   * @param  {argmap} argmap
   * @return {argmap}
   * (func argmap<-textblock-argmap)
   */
  // (func argmap<-textblock-argmap)
  // class Class_argmap_from_textblock_argmap {
    Abstract_argmap_from_textblock_argmap::~Abstract_argmap_from_textblock_argmap() {}

    Class_argmap_from_textblock_argmap::Class_argmap_from_textblock_argmap() : Abstract_argmap_from_textblock_argmap::Abstract_argmap_from_textblock_argmap() {
      vx_core::refcount += 1;
    }

    Class_argmap_from_textblock_argmap::~Class_argmap_from_textblock_argmap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_argmap_from_textblock_argmap::vx_new(vx_core::vx_Type_listany vals) const {
      vx_repl::Func_argmap_from_textblock_argmap output = vx_repl::e_argmap_from_textblock_argmap;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_argmap_from_textblock_argmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Func_argmap_from_textblock_argmap output = vx_repl::e_argmap_from_textblock_argmap;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_argmap_from_textblock_argmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "argmap<-textblock-argmap", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_argmap_from_textblock_argmap::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_argmap_from_textblock_argmap::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "argmap<-textblock-argmap", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_argmap_from_textblock_argmap::vx_empty() const {return vx_repl::e_argmap_from_textblock_argmap;}
    vx_core::Type_any Class_argmap_from_textblock_argmap::vx_type() const {return vx_repl::t_argmap_from_textblock_argmap;}
    vx_core::Type_msgblock Class_argmap_from_textblock_argmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_argmap_from_textblock_argmap::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_argmap_from_textblock_argmap::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblock = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_argmap argmap = vx_core::vx_any_from_any(vx_core::t_argmap, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_repl::f_argmap_from_textblock_argmap(textblock, argmap);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func const<-string)
  vx_core::Type_any f_const_from_string(vx_core::Type_string text) {
    vx_core::Type_any output = vx_core::e_any;
    vx_core::vx_reserve(text);
    output = vx_core::f_let(
      vx_core::t_any,
      vx_core::t_any_from_func->vx_fn_new({text}, [text]() {
        vx_core::Type_int pkgpos = vx_type::f_int_from_string_findlast(text, vx_core::vx_new_string("/"));
        vx_core::vx_ref_plus(pkgpos);
        vx_core::Type_string pkgname = vx_core::f_if_1(
          vx_core::t_string,
          vx_core::f_eq(vx_core::vx_new_int(0), pkgpos),
          vx_core::vx_new_string("vx/core"),
          vx_type::f_string_from_string_end(
            text,
            vx_core::f_minus1(pkgpos)
          )
        );
        vx_core::vx_ref_plus(pkgname);
        vx_core::Type_string name = vx_core::f_if_1(
          vx_core::t_string,
          vx_core::f_eq(vx_core::vx_new_int(0), pkgpos),
          text,
          vx_type::f_string_from_string_start(
            text,
            vx_core::f_plus1(pkgpos)
          )
        );
        vx_core::vx_ref_plus(name);
        vx_core::Type_package pkg = vx_core::f_package_global_from_name(pkgname);
        vx_core::vx_ref_plus(pkg);
        vx_core::Type_constmap constmap = pkg->constmap();
        vx_core::vx_ref_plus(constmap);
        vx_core::Type_any constval = vx_core::f_any_from_map(vx_core::t_any, constmap, name);
        vx_core::vx_ref_plus(constval);
        vx_core::Type_any output_1 = vx_core::f_if_1(
          vx_core::t_any,
          vx_core::f_notempty_1(constval),
          constval,
          vx_core::f_empty(
            vx_core::t_any
          )
        );
        vx_core::vx_release_one_except({pkgpos, pkgname, name, pkg, constmap, constval}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(text, output);
    return output;
  }
  /**
   * @function const_from_string
   * Returns a constant from a fully qualified name.
   * @param  {string} text
   * @return {any}
   * (func const<-string)
   */
  // (func const<-string)
  // class Class_const_from_string {
    Abstract_const_from_string::~Abstract_const_from_string() {}

    Class_const_from_string::Class_const_from_string() : Abstract_const_from_string::Abstract_const_from_string() {
      vx_core::refcount += 1;
    }

    Class_const_from_string::~Class_const_from_string() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_const_from_string::vx_new(vx_core::vx_Type_listany vals) const {
      vx_repl::Func_const_from_string output = vx_repl::e_const_from_string;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_const_from_string::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Func_const_from_string output = vx_repl::e_const_from_string;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_const_from_string::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "const<-string", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_const_from_string::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_const_from_string::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "const<-string", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_const_from_string::vx_empty() const {return vx_repl::e_const_from_string;}
    vx_core::Type_any Class_const_from_string::vx_type() const {return vx_repl::t_const_from_string;}
    vx_core::Type_msgblock Class_const_from_string::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_const_from_string::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_const_from_string::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_const_from_string::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      output = vx_repl::f_const_from_string(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_const_from_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_repl::f_const_from_string(text);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func repl-bracket<-textblock-argmap)
  vx_repl::Type_repl f_repl_bracket_from_textblock_argmap(vx_data_textblock::Type_textblock textblock, vx_core::Type_argmap argmap) {
    vx_repl::Type_repl output = vx_repl::e_repl;
    vx_core::vx_reserve({textblock, argmap});
    output = vx_core::f_empty(
      vx_repl::t_repl
    );
    vx_core::vx_release_one_except({textblock, argmap}, output);
    return output;
  }
  /**
   * @function repl_bracket_from_textblock_argmap
   * Returns a repl from a squarebracket parsed textblock
   * @param  {textblock} textblock
   * @param  {argmap} argmap
   * @return {repl}
   * (func repl-bracket<-textblock-argmap)
   */
  // (func repl-bracket<-textblock-argmap)
  // class Class_repl_bracket_from_textblock_argmap {
    Abstract_repl_bracket_from_textblock_argmap::~Abstract_repl_bracket_from_textblock_argmap() {}

    Class_repl_bracket_from_textblock_argmap::Class_repl_bracket_from_textblock_argmap() : Abstract_repl_bracket_from_textblock_argmap::Abstract_repl_bracket_from_textblock_argmap() {
      vx_core::refcount += 1;
    }

    Class_repl_bracket_from_textblock_argmap::~Class_repl_bracket_from_textblock_argmap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_repl_bracket_from_textblock_argmap::vx_new(vx_core::vx_Type_listany vals) const {
      vx_repl::Func_repl_bracket_from_textblock_argmap output = vx_repl::e_repl_bracket_from_textblock_argmap;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_repl_bracket_from_textblock_argmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Func_repl_bracket_from_textblock_argmap output = vx_repl::e_repl_bracket_from_textblock_argmap;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_repl_bracket_from_textblock_argmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "repl-bracket<-textblock-argmap", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_repl_bracket_from_textblock_argmap::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_repl_bracket_from_textblock_argmap::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "repl-bracket<-textblock-argmap", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_repl_bracket_from_textblock_argmap::vx_empty() const {return vx_repl::e_repl_bracket_from_textblock_argmap;}
    vx_core::Type_any Class_repl_bracket_from_textblock_argmap::vx_type() const {return vx_repl::t_repl_bracket_from_textblock_argmap;}
    vx_core::Type_msgblock Class_repl_bracket_from_textblock_argmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_repl_bracket_from_textblock_argmap::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_repl_bracket_from_textblock_argmap::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblock = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_argmap argmap = vx_core::vx_any_from_any(vx_core::t_argmap, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_repl::f_repl_bracket_from_textblock_argmap(textblock, argmap);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func repl-empty<-textblock-argmap)
  vx_repl::Type_repl f_repl_empty_from_textblock_argmap(vx_data_textblock::Type_textblock textblock, vx_core::Type_argmap argmap) {
    vx_repl::Type_repl output = vx_repl::e_repl;
    vx_core::vx_reserve({textblock, argmap});
    output = vx_core::f_let(
      vx_repl::t_repl,
      vx_core::t_any_from_func->vx_fn_new({textblock, argmap}, [textblock, argmap]() {
        vx_data_textblock::Type_textblocklist children = textblock->children();
        vx_core::vx_ref_plus(children);
        vx_core::Type_int len = vx_core::f_length_from_list(children);
        vx_core::vx_ref_plus(len);
        vx_repl::Type_repl output_1 = vx_core::f_switch(
          vx_repl::t_repl,
          len,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_case_1(
              vx_core::vx_new_int(0),
              vx_core::t_any_from_func->vx_fn_new({textblock, argmap}, [textblock, argmap]() {
                vx_repl::Type_repl output_1 = vx_repl::f_repl_from_string_argmap(
                  textblock->text(),
                  argmap
                );
                return output_1;
              })
            ),
            vx_core::f_case_1(
              vx_core::vx_new_int(1),
              vx_core::t_any_from_func->vx_fn_new({children, argmap}, [children, argmap]() {
                vx_repl::Type_repl output_1 = vx_repl::f_repl_from_textblock_argmap(
                  vx_core::f_any_from_list(vx_data_textblock::t_textblock, children, vx_core::vx_new_int(1)),
                  argmap
                );
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({}, []() {
                vx_repl::Type_repl output_1 = vx_core::f_new(
                  vx_repl::t_repl,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::f_msg_from_error(vx_core::vx_new_string("Empty delim cannot have more than one child."))
                  })
                );
                return output_1;
              })
            )
          })
        );
        vx_core::vx_release_one_except({children, len}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({textblock, argmap}, output);
    return output;
  }
  /**
   * @function repl_empty_from_textblock_argmap
   * Returns a repl from an empty delim textblock
   * @param  {textblock} textblock
   * @param  {argmap} argmap
   * @return {repl}
   * (func repl-empty<-textblock-argmap)
   */
  // (func repl-empty<-textblock-argmap)
  // class Class_repl_empty_from_textblock_argmap {
    Abstract_repl_empty_from_textblock_argmap::~Abstract_repl_empty_from_textblock_argmap() {}

    Class_repl_empty_from_textblock_argmap::Class_repl_empty_from_textblock_argmap() : Abstract_repl_empty_from_textblock_argmap::Abstract_repl_empty_from_textblock_argmap() {
      vx_core::refcount += 1;
    }

    Class_repl_empty_from_textblock_argmap::~Class_repl_empty_from_textblock_argmap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_repl_empty_from_textblock_argmap::vx_new(vx_core::vx_Type_listany vals) const {
      vx_repl::Func_repl_empty_from_textblock_argmap output = vx_repl::e_repl_empty_from_textblock_argmap;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_repl_empty_from_textblock_argmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Func_repl_empty_from_textblock_argmap output = vx_repl::e_repl_empty_from_textblock_argmap;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_repl_empty_from_textblock_argmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "repl-empty<-textblock-argmap", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_repl_empty_from_textblock_argmap::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_repl_empty_from_textblock_argmap::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "repl-empty<-textblock-argmap", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_repl_empty_from_textblock_argmap::vx_empty() const {return vx_repl::e_repl_empty_from_textblock_argmap;}
    vx_core::Type_any Class_repl_empty_from_textblock_argmap::vx_type() const {return vx_repl::t_repl_empty_from_textblock_argmap;}
    vx_core::Type_msgblock Class_repl_empty_from_textblock_argmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_repl_empty_from_textblock_argmap::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_repl_empty_from_textblock_argmap::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblock = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_argmap argmap = vx_core::vx_any_from_any(vx_core::t_argmap, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_repl::f_repl_empty_from_textblock_argmap(textblock, argmap);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func repl-paren<-textblock-argmap)
  vx_repl::Type_repl f_repl_paren_from_textblock_argmap(vx_data_textblock::Type_textblock textblock, vx_core::Type_argmap argmap) {
    vx_repl::Type_repl output = vx_repl::e_repl;
    vx_core::vx_reserve({textblock, argmap});
    output = vx_core::f_let(
      vx_repl::t_repl,
      vx_core::t_any_from_func->vx_fn_new({textblock, argmap}, [textblock, argmap]() {
        vx_data_textblock::Type_textblocklist childlst = textblock->children();
        vx_core::vx_ref_plus(childlst);
        vx_data_textblock::Type_textblocklist children = vx_data_textblock::f_textblocklist_from_textblocklist_remove(
          childlst,
          vx_data_textblock::c_delimwhitespace
        );
        vx_core::vx_ref_plus(children);
        vx_data_textblock::Type_textblock tbfunc = vx_core::f_any_from_list(vx_data_textblock::t_textblock, children, vx_core::vx_new_int(1));
        vx_core::vx_ref_plus(tbfunc);
        vx_core::Type_string sfunc = tbfunc->text();
        vx_core::vx_ref_plus(sfunc);
        vx_repl::Type_repl replfunc = vx_repl::f_repl_from_string_argmap(sfunc, argmap);
        vx_core::vx_ref_plus(replfunc);
        vx_core::Type_any typefunc = replfunc->type();
        vx_core::vx_ref_plus(typefunc);
        vx_core::Type_int posarg = vx_core::f_switch(
          vx_core::t_int,
          typefunc,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_case_1(
              vx_core::t_let,
              vx_core::t_any_from_func->vx_fn_new({}, []() {
                vx_core::Type_int output_1 = vx_core::vx_new_int(3);
                return output_1;
              })
            ),
            vx_core::f_case_1(
              vx_core::t_fn,
              vx_core::t_any_from_func->vx_fn_new({}, []() {
                vx_core::Type_int output_1 = vx_core::vx_new_int(3);
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({}, []() {
                vx_core::Type_int output_1 = vx_core::vx_new_int(2);
                return output_1;
              })
            )
          })
        );
        vx_core::vx_ref_plus(posarg);
        vx_core::Type_argmap argmap2 = vx_core::f_switch(
          vx_core::t_argmap,
          typefunc,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_case_1(
              vx_core::t_let,
              vx_core::t_any_from_func->vx_fn_new({children, argmap}, [children, argmap]() {
                vx_core::Type_argmap output_1 = vx_repl::f_argmap_from_textblock_argmap(
                  vx_core::f_any_from_list(vx_data_textblock::t_textblock, children, vx_core::vx_new_int(3)),
                  argmap
                );
                return output_1;
              })
            ),
            vx_core::f_case_1(
              vx_core::t_fn,
              vx_core::t_any_from_func->vx_fn_new({children, argmap}, [children, argmap]() {
                vx_core::Type_argmap output_1 = vx_repl::f_argmap_from_textblock_argmap(
                  vx_core::f_any_from_list(vx_data_textblock::t_textblock, children, vx_core::vx_new_int(3)),
                  argmap
                );
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({argmap}, [argmap]() {
                vx_core::Type_any output_1 = argmap;
                return output_1;
              })
            )
          })
        );
        vx_core::vx_ref_plus(argmap2);
        vx_data_textblock::Type_textblocklist tbargs = vx_collection::f_list_from_list_start(vx_data_textblock::t_textblocklist, children, posarg);
        vx_core::vx_ref_plus(tbargs);
        vx_repl::Type_repllist replargs = vx_repl::f_repllist_from_textblocklist_argmap(tbargs, argmap);
        vx_core::vx_ref_plus(replargs);
        vx_repl::Type_repl output_1 = vx_core::f_copy(
          vx_repl::t_repl,
          replfunc,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":repllist"),
            replargs
          })
        );
        vx_core::vx_release_one_except({childlst, children, tbfunc, sfunc, replfunc, typefunc, posarg, argmap2, tbargs, replargs}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({textblock, argmap}, output);
    return output;
  }
  /**
   * @function repl_paren_from_textblock_argmap
   * Returns a repl from a parsed textblock
   * @param  {textblock} textblock
   * @param  {argmap} argmap
   * @return {repl}
   * (func repl-paren<-textblock-argmap)
   */
  // (func repl-paren<-textblock-argmap)
  // class Class_repl_paren_from_textblock_argmap {
    Abstract_repl_paren_from_textblock_argmap::~Abstract_repl_paren_from_textblock_argmap() {}

    Class_repl_paren_from_textblock_argmap::Class_repl_paren_from_textblock_argmap() : Abstract_repl_paren_from_textblock_argmap::Abstract_repl_paren_from_textblock_argmap() {
      vx_core::refcount += 1;
    }

    Class_repl_paren_from_textblock_argmap::~Class_repl_paren_from_textblock_argmap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_repl_paren_from_textblock_argmap::vx_new(vx_core::vx_Type_listany vals) const {
      vx_repl::Func_repl_paren_from_textblock_argmap output = vx_repl::e_repl_paren_from_textblock_argmap;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_repl_paren_from_textblock_argmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Func_repl_paren_from_textblock_argmap output = vx_repl::e_repl_paren_from_textblock_argmap;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_repl_paren_from_textblock_argmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "repl-paren<-textblock-argmap", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_repl_paren_from_textblock_argmap::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_repl_paren_from_textblock_argmap::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "repl-paren<-textblock-argmap", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_repl_paren_from_textblock_argmap::vx_empty() const {return vx_repl::e_repl_paren_from_textblock_argmap;}
    vx_core::Type_any Class_repl_paren_from_textblock_argmap::vx_type() const {return vx_repl::t_repl_paren_from_textblock_argmap;}
    vx_core::Type_msgblock Class_repl_paren_from_textblock_argmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_repl_paren_from_textblock_argmap::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_repl_paren_from_textblock_argmap::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblock = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_argmap argmap = vx_core::vx_any_from_any(vx_core::t_argmap, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_repl::f_repl_paren_from_textblock_argmap(textblock, argmap);
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
  /**
   * @function repl_from_liblist_string
   * Returns a repl from the given text.
   * @param  {liblist} liblist
   * @param  {string} text Program to run
   * @return {repl}
   * (func repl<-liblist-string)
   */
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
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_repl_from_liblist_string::vx_constdef() const {return this->vx_p_constdef;}

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

  // (func repl<-macro)
  vx_repl::Type_repl f_repl_from_macro(vx_core::Type_context context, vx_core::Type_anylist anylist) {
    vx_repl::Type_repl output = vx_repl::e_repl;
    vx_core::vx_reserve(anylist);
    output = vx_core::f_let(
      vx_repl::t_repl,
      vx_core::t_any_from_func->vx_fn_new({anylist}, [anylist]() {
        vx_core::Type_stringlist textlist = vx_core::f_list_from_list_1(
          vx_core::t_stringlist,
          anylist,
          vx_core::t_any_from_any->vx_fn_new({}, [](vx_core::Type_any item) {
            vx_core::Type_any output_1 = 
              vx_core::f_let(
                vx_core::t_string,
                vx_core::t_any_from_func->vx_fn_new({item}, [item]() {
                  vx_core::Type_any typ = vx_core::f_type_from_any(item);
                  vx_core::vx_ref_plus(typ);
                  vx_core::Type_string output_1 = vx_core::f_switch(
                    vx_core::t_string,
                    typ,
                    vx_core::vx_new(vx_core::t_thenelselist, {
                      vx_core::f_case_1(
                        vx_core::t_string,
                        vx_core::t_any_from_func->vx_fn_new({item}, [item]() {
                          vx_core::Type_string output_1 = vx_core::f_any_from_any(vx_core::t_string, item);
                          return output_1;
                        })
                      ),
                      vx_core::f_else(
                        vx_core::t_any_from_func->vx_fn_new({item}, [item]() {
                          vx_core::Type_string output_1 = vx_core::f_string_from_any(item);
                          return output_1;
                        })
                      )
                    })
                  );
                  vx_core::vx_release_one_except(typ, output_1);
                  return output_1;
                })
              );
            return output_1;
          })
        );
        vx_core::vx_ref_plus(textlist);
        vx_core::Type_string script = vx_type::f_string_from_stringlist_join(textlist, vx_core::vx_new_string(""));
        vx_core::vx_ref_plus(script);
        vx_data_textblock::Type_textblock tb = vx_repl::f_textblock_from_script(script);
        vx_core::vx_ref_plus(tb);
        vx_repl::Type_repl output_1 = vx_repl::f_repl_from_textblock(tb);
        vx_core::vx_release_one_except({textlist, script, tb}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(anylist, output);
    return output;
  }
  /**
   * @function repl_from_macro
   * A function that joins any number of values into a string and then parses it.
   * @param  {anylist} anylist
   * @return {repl}
   * (func repl<-macro)
   */
  // (func repl<-macro)
  // class Class_repl_from_macro {
    Abstract_repl_from_macro::~Abstract_repl_from_macro() {}

    Class_repl_from_macro::Class_repl_from_macro() : Abstract_repl_from_macro::Abstract_repl_from_macro() {
      vx_core::refcount += 1;
    }

    Class_repl_from_macro::~Class_repl_from_macro() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_repl_from_macro::vx_new(vx_core::vx_Type_listany vals) const {
      vx_repl::Func_repl_from_macro output = vx_repl::e_repl_from_macro;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_repl_from_macro::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Func_repl_from_macro output = vx_repl::e_repl_from_macro;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_repl_from_macro::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "repl<-macro", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_repl_from_macro::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_repl_from_macro::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "repl<-macro", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_repl_from_macro::vx_empty() const {return vx_repl::e_repl_from_macro;}
    vx_core::Type_any Class_repl_from_macro::vx_type() const {return vx_repl::t_repl_from_macro;}
    vx_core::Type_msgblock Class_repl_from_macro::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_repl_from_macro::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_repl_from_macro::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_repl_from_macro::vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_anylist inputval = vx_core::vx_any_from_any(vx_core::t_anylist, val);
      output = vx_repl::f_repl_from_macro(context, inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_repl_from_macro::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_anylist anylist = vx_core::vx_any_from_any(vx_core::t_anylist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_repl::f_repl_from_macro(context, anylist);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func repl<-script)
  vx_repl::Type_repl f_repl_from_script(vx_core::Type_string script) {
    vx_repl::Type_repl output = vx_repl::e_repl;
    vx_core::vx_reserve(script);
    output = vx_core::f_let(
      vx_repl::t_repl,
      vx_core::t_any_from_func->vx_fn_new({script}, [script]() {
        vx_data_textblock::Type_textblock textblock = vx_repl::f_textblock_from_script(script);
        vx_core::vx_ref_plus(textblock);
        vx_repl::Type_repl output_1 = vx_repl::f_repl_from_textblock(textblock);
        vx_core::vx_release_one_except(textblock, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(script, output);
    return output;
  }
  /**
   * @function repl_from_script
   * Returns a parsed repl from a string
   * @param  {string} script
   * @return {repl}
   * (func repl<-script)
   */
  // (func repl<-script)
  // class Class_repl_from_script {
    Abstract_repl_from_script::~Abstract_repl_from_script() {}

    Class_repl_from_script::Class_repl_from_script() : Abstract_repl_from_script::Abstract_repl_from_script() {
      vx_core::refcount += 1;
    }

    Class_repl_from_script::~Class_repl_from_script() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_repl_from_script::vx_new(vx_core::vx_Type_listany vals) const {
      vx_repl::Func_repl_from_script output = vx_repl::e_repl_from_script;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_repl_from_script::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Func_repl_from_script output = vx_repl::e_repl_from_script;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_repl_from_script::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "repl<-script", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_repl_from_script::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_repl_from_script::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "repl<-script", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_repl_from_script::vx_empty() const {return vx_repl::e_repl_from_script;}
    vx_core::Type_any Class_repl_from_script::vx_type() const {return vx_repl::t_repl_from_script;}
    vx_core::Type_msgblock Class_repl_from_script::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_repl_from_script::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_repl_from_script::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_repl_from_script::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      output = vx_repl::f_repl_from_script(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_repl_from_script::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string script = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_repl::f_repl_from_script(script);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func repl<-string-argmap)
  vx_repl::Type_repl f_repl_from_string_argmap(vx_core::Type_string text, vx_core::Type_argmap argmap) {
    vx_repl::Type_repl output = vx_repl::e_repl;
    vx_core::vx_reserve({text, argmap});
    output = vx_core::f_if_2(
      vx_repl::t_repl,
      vx_core::vx_new(vx_core::t_thenelselist, {
        vx_core::f_then(
          vx_core::t_boolean_from_func->vx_fn_new({text}, [text]() {
            vx_core::Type_boolean output_1 = vx_core::f_and(
              vx_type::f_boolean_from_string_starts(
                text,
                vx_core::c_quote
              ),
              vx_type::f_boolean_from_string_ends(
                text,
                vx_core::c_quote
              )
            );
            return output_1;
          }),
          vx_core::t_any_from_func->vx_fn_new({text}, [text]() {
            vx_repl::Type_repl output_1 = vx_core::f_new(
              vx_repl::t_repl,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":val"),
                vx_type::f_string_from_string_start_end(text, vx_core::vx_new_int(2), vx_core::vx_new_int(-1))
              })
            );
            return output_1;
          })
        ),
        vx_core::f_then(
          vx_core::t_boolean_from_func->vx_fn_new({text}, [text]() {
            vx_core::Type_boolean output_1 = vx_core::f_is_int(text);
            return output_1;
          }),
          vx_core::t_any_from_func->vx_fn_new({text}, [text]() {
            vx_repl::Type_repl output_1 = vx_core::f_new(
              vx_repl::t_repl,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":val"),
                vx_core::f_int_from_string(text)
              })
            );
            return output_1;
          })
        ),
        vx_core::f_then(
          vx_core::t_boolean_from_func->vx_fn_new({text}, [text]() {
            vx_core::Type_boolean output_1 = vx_core::f_is_float(text);
            return output_1;
          }),
          vx_core::t_any_from_func->vx_fn_new({text}, [text]() {
            vx_repl::Type_repl output_1 = vx_core::f_new(
              vx_repl::t_repl,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":val"),
                vx_core::f_float_from_string(text)
              })
            );
            return output_1;
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func->vx_fn_new({argmap, text}, [argmap, text]() {
            vx_repl::Type_repl output_1 = vx_core::f_let(
              vx_repl::t_repl,
              vx_core::t_any_from_func->vx_fn_new({argmap, text}, [argmap, text]() {
                vx_core::Type_any arg = vx_core::f_any_from_map(vx_core::t_any, argmap, text);
                vx_core::vx_ref_plus(arg);
                vx_repl::Type_repl output_1 = vx_core::f_if_2(
                  vx_repl::t_repl,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({arg}, [arg]() {
                        vx_core::Type_boolean output_1 = vx_core::f_notempty_1(arg);
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({arg}, [arg]() {
                        vx_repl::Type_repl output_1 = vx_core::f_new(
                          vx_repl::t_repl,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":val"),
                            arg
                          })
                        );
                        return output_1;
                      })
                    ),
                    vx_core::f_else(
                      vx_core::t_any_from_func->vx_fn_new({text}, [text]() {
                        vx_repl::Type_repl output_1 = vx_core::f_let(
                          vx_repl::t_repl,
                          vx_core::t_any_from_func->vx_fn_new({text}, [text]() {
                            vx_core::Type_any cnst = vx_repl::f_const_from_string(text);
                            vx_core::vx_ref_plus(cnst);
                            vx_repl::Type_repl output_1 = vx_core::f_if_2(
                              vx_repl::t_repl,
                              vx_core::vx_new(vx_core::t_thenelselist, {
                                vx_core::f_then(
                                  vx_core::t_boolean_from_func->vx_fn_new({cnst}, [cnst]() {
                                    vx_core::Type_boolean output_1 = vx_core::f_notempty_1(cnst);
                                    return output_1;
                                  }),
                                  vx_core::t_any_from_func->vx_fn_new({cnst}, [cnst]() {
                                    vx_repl::Type_repl output_1 = vx_core::f_new(
                                      vx_repl::t_repl,
                                      vx_core::vx_new(vx_core::t_anylist, {
                                        vx_core::vx_new_string(":val"),
                                        cnst
                                      })
                                    );
                                    return output_1;
                                  })
                                ),
                                vx_core::f_else(
                                  vx_core::t_any_from_func->vx_fn_new({text}, [text]() {
                                    vx_repl::Type_repl output_1 = vx_core::f_let(
                                      vx_repl::t_repl,
                                      vx_core::t_any_from_func->vx_fn_new({text}, [text]() {
                                        vx_core::Type_any typefunc = vx_repl::f_typefunc_from_string(text);
                                        vx_core::vx_ref_plus(typefunc);
                                        vx_repl::Type_repl output_1 = vx_core::f_if_2(
                                          vx_repl::t_repl,
                                          vx_core::vx_new(vx_core::t_thenelselist, {
                                            vx_core::f_then(
                                              vx_core::t_boolean_from_func->vx_fn_new({typefunc}, [typefunc]() {
                                                vx_core::Type_boolean output_1 = vx_core::f_notempty_1(typefunc);
                                                return output_1;
                                              }),
                                              vx_core::t_any_from_func->vx_fn_new({typefunc}, [typefunc]() {
                                                vx_repl::Type_repl output_1 = vx_core::f_new(
                                                  vx_repl::t_repl,
                                                  vx_core::vx_new(vx_core::t_anylist, {
                                                    vx_core::vx_new_string(":type"),
                                                    typefunc
                                                  })
                                                );
                                                return output_1;
                                              })
                                            ),
                                            vx_core::f_else(
                                              vx_core::t_any_from_func->vx_fn_new({text}, [text]() {
                                                vx_repl::Type_repl output_1 = vx_core::f_new(
                                                  vx_repl::t_repl,
                                                  vx_core::vx_new(vx_core::t_anylist, {
                                                    vx_core::f_msg_from_error_1(vx_core::vx_new_string(":repltypenotfound"), text)
                                                  })
                                                );
                                                return output_1;
                                              })
                                            )
                                          })
                                        );
                                        vx_core::vx_release_one_except(typefunc, output_1);
                                        return output_1;
                                      })
                                    );
                                    return output_1;
                                  })
                                )
                              })
                            );
                            vx_core::vx_release_one_except(cnst, output_1);
                            return output_1;
                          })
                        );
                        return output_1;
                      })
                    )
                  })
                );
                vx_core::vx_release_one_except(arg, output_1);
                return output_1;
              })
            );
            return output_1;
          })
        )
      })
    );
    vx_core::vx_release_one_except({text, argmap}, output);
    return output;
  }
  /**
   * @function repl_from_string_argmap
   * Returns a function, type, const or primitive from given string.
   * @param  {string} text
   * @param  {argmap} argmap
   * @return {repl}
   * (func repl<-string-argmap)
   */
  // (func repl<-string-argmap)
  // class Class_repl_from_string_argmap {
    Abstract_repl_from_string_argmap::~Abstract_repl_from_string_argmap() {}

    Class_repl_from_string_argmap::Class_repl_from_string_argmap() : Abstract_repl_from_string_argmap::Abstract_repl_from_string_argmap() {
      vx_core::refcount += 1;
    }

    Class_repl_from_string_argmap::~Class_repl_from_string_argmap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_repl_from_string_argmap::vx_new(vx_core::vx_Type_listany vals) const {
      vx_repl::Func_repl_from_string_argmap output = vx_repl::e_repl_from_string_argmap;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_repl_from_string_argmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Func_repl_from_string_argmap output = vx_repl::e_repl_from_string_argmap;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_repl_from_string_argmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "repl<-string-argmap", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_repl_from_string_argmap::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_repl_from_string_argmap::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "repl<-string-argmap", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_repl_from_string_argmap::vx_empty() const {return vx_repl::e_repl_from_string_argmap;}
    vx_core::Type_any Class_repl_from_string_argmap::vx_type() const {return vx_repl::t_repl_from_string_argmap;}
    vx_core::Type_msgblock Class_repl_from_string_argmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_repl_from_string_argmap::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_repl_from_string_argmap::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_argmap argmap = vx_core::vx_any_from_any(vx_core::t_argmap, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_repl::f_repl_from_string_argmap(text, argmap);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func repl<-textblock)
  vx_repl::Type_repl f_repl_from_textblock(vx_data_textblock::Type_textblock textblock) {
    vx_repl::Type_repl output = vx_repl::e_repl;
    vx_core::vx_reserve(textblock);
    output = vx_repl::f_repl_from_textblock_argmap(
      textblock,
      vx_core::f_empty(
        vx_core::t_argmap
      )
    );
    vx_core::vx_release_one_except(textblock, output);
    return output;
  }
  /**
   * @function repl_from_textblock
   * Returns a repl from a parsed textblock
   * @param  {textblock} textblock
   * @return {repl}
   * (func repl<-textblock)
   */
  // (func repl<-textblock)
  // class Class_repl_from_textblock {
    Abstract_repl_from_textblock::~Abstract_repl_from_textblock() {}

    Class_repl_from_textblock::Class_repl_from_textblock() : Abstract_repl_from_textblock::Abstract_repl_from_textblock() {
      vx_core::refcount += 1;
    }

    Class_repl_from_textblock::~Class_repl_from_textblock() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_repl_from_textblock::vx_new(vx_core::vx_Type_listany vals) const {
      vx_repl::Func_repl_from_textblock output = vx_repl::e_repl_from_textblock;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_repl_from_textblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Func_repl_from_textblock output = vx_repl::e_repl_from_textblock;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_repl_from_textblock::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "repl<-textblock", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_repl_from_textblock::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_repl_from_textblock::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "repl<-textblock", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_repl_from_textblock::vx_empty() const {return vx_repl::e_repl_from_textblock;}
    vx_core::Type_any Class_repl_from_textblock::vx_type() const {return vx_repl::t_repl_from_textblock;}
    vx_core::Type_msgblock Class_repl_from_textblock::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_repl_from_textblock::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_repl_from_textblock::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_repl_from_textblock::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock inputval = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, val);
      output = vx_repl::f_repl_from_textblock(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_repl_from_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblock = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_repl::f_repl_from_textblock(textblock);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func repl<-textblock-argmap)
  vx_repl::Type_repl f_repl_from_textblock_argmap(vx_data_textblock::Type_textblock textblock, vx_core::Type_argmap argmap) {
    vx_repl::Type_repl output = vx_repl::e_repl;
    vx_core::vx_reserve({textblock, argmap});
    output = vx_core::f_let(
      vx_repl::t_repl,
      vx_core::t_any_from_func->vx_fn_new({textblock, argmap}, [textblock, argmap]() {
        vx_data_textblock::Type_delim delim = textblock->delim();
        vx_core::vx_ref_plus(delim);
        vx_core::Type_string starttext = delim->starttext();
        vx_core::vx_ref_plus(starttext);
        vx_repl::Type_repl output_1 = vx_core::f_switch(
          vx_repl::t_repl,
          starttext,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_case_1(
              vx_core::vx_new_string(""),
              vx_core::t_any_from_func->vx_fn_new({textblock, argmap}, [textblock, argmap]() {
                vx_repl::Type_repl output_1 = vx_repl::f_repl_empty_from_textblock_argmap(textblock, argmap);
                return output_1;
              })
            ),
            vx_core::f_case_1(
              vx_core::f_any_from_struct(
                vx_core::t_string,
                vx_data_textblock::c_delimparen,
                vx_core::vx_new_string(":starttext")
              ),
              vx_core::t_any_from_func->vx_fn_new({textblock, argmap}, [textblock, argmap]() {
                vx_repl::Type_repl output_1 = vx_repl::f_repl_paren_from_textblock_argmap(textblock, argmap);
                return output_1;
              })
            ),
            vx_core::f_case_1(
              vx_core::f_any_from_struct(
                vx_core::t_string,
                vx_data_textblock::c_delimbracketsquare,
                vx_core::vx_new_string(":starttext")
              ),
              vx_core::t_any_from_func->vx_fn_new({textblock, argmap}, [textblock, argmap]() {
                vx_repl::Type_repl output_1 = vx_repl::f_repl_bracket_from_textblock_argmap(textblock, argmap);
                return output_1;
              })
            )
          })
        );
        vx_core::vx_release_one_except({delim, starttext}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({textblock, argmap}, output);
    return output;
  }
  /**
   * @function repl_from_textblock_argmap
   * Returns a repl from a parsed textblock
   * @param  {textblock} textblock
   * @param  {argmap} argmap
   * @return {repl}
   * (func repl<-textblock-argmap)
   */
  // (func repl<-textblock-argmap)
  // class Class_repl_from_textblock_argmap {
    Abstract_repl_from_textblock_argmap::~Abstract_repl_from_textblock_argmap() {}

    Class_repl_from_textblock_argmap::Class_repl_from_textblock_argmap() : Abstract_repl_from_textblock_argmap::Abstract_repl_from_textblock_argmap() {
      vx_core::refcount += 1;
    }

    Class_repl_from_textblock_argmap::~Class_repl_from_textblock_argmap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_repl_from_textblock_argmap::vx_new(vx_core::vx_Type_listany vals) const {
      vx_repl::Func_repl_from_textblock_argmap output = vx_repl::e_repl_from_textblock_argmap;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_repl_from_textblock_argmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Func_repl_from_textblock_argmap output = vx_repl::e_repl_from_textblock_argmap;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_repl_from_textblock_argmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "repl<-textblock-argmap", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_repl_from_textblock_argmap::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_repl_from_textblock_argmap::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "repl<-textblock-argmap", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_repl_from_textblock_argmap::vx_empty() const {return vx_repl::e_repl_from_textblock_argmap;}
    vx_core::Type_any Class_repl_from_textblock_argmap::vx_type() const {return vx_repl::t_repl_from_textblock_argmap;}
    vx_core::Type_msgblock Class_repl_from_textblock_argmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_repl_from_textblock_argmap::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_repl_from_textblock_argmap::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblock = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_argmap argmap = vx_core::vx_any_from_any(vx_core::t_argmap, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_repl::f_repl_from_textblock_argmap(textblock, argmap);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func replarglist<-replarglist-textblock-argmap)
  vx_repl::Type_replarglist f_replarglist_from_replarglist_textblock_argmap(vx_repl::Type_replarglist replargs, vx_data_textblock::Type_textblock tb, vx_core::Type_argmap argmap) {
    vx_repl::Type_replarglist output = vx_repl::e_replarglist;
    vx_core::vx_reserve({replargs, tb, argmap});
    output = vx_core::f_let(
      vx_repl::t_replarglist,
      vx_core::t_any_from_func->vx_fn_new({replargs, tb, argmap}, [replargs, tb, argmap]() {
        vx_core::Type_string key = replargs->key();
        vx_core::vx_ref_plus(key);
        vx_repl::Type_repl current = replargs->current();
        vx_core::vx_ref_plus(current);
        vx_repl::Type_repllist repllist = replargs->repllist();
        vx_core::vx_ref_plus(repllist);
        vx_repl::Type_repllist currlist = current->repllist();
        vx_core::vx_ref_plus(currlist);
        vx_core::Type_string text = vx_core::f_any_from_struct(
          vx_core::t_string,
          vx_data_textblock::t_textblock,
          vx_core::vx_new_string(":text")
        );
        vx_core::vx_ref_plus(text);
        vx_repl::Type_replarglist output_1 = vx_core::f_if_2(
          vx_repl::t_replarglist,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({key}, [key]() {
                vx_core::Type_boolean output_1 = vx_core::f_eq(key, vx_core::vx_new_string(""));
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({text, replargs, repllist, current}, [text, replargs, repllist, current]() {
                vx_repl::Type_replarglist output_1 = vx_core::f_if_2(
                  vx_repl::t_replarglist,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({text}, [text]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eq_1(vx_core::vx_new(vx_core::t_anylist, {
                        text}));
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({replargs, text}, [replargs, text]() {
                        vx_core::Type_any output_1 = vx_core::f_copy(
                          vx_repl::t_replarglist,
                          replargs,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":key"),
                            text
                          })
                        );
                        return output_1;
                      })
                    ),
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({text}, [text]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eq(text, vx_core::vx_new_string(":="));
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({replargs, text}, [replargs, text]() {
                        vx_core::Type_any output_1 = vx_core::f_copy(
                          vx_repl::t_replarglist,
                          replargs,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":key"),
                            text
                          })
                        );
                        return output_1;
                      })
                    ),
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({text}, [text]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eq(text, vx_core::vx_new_string(":doc"));
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({replargs, text}, [replargs, text]() {
                        vx_core::Type_any output_1 = vx_core::f_copy(
                          vx_repl::t_replarglist,
                          replargs,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":key"),
                            text
                          })
                        );
                        return output_1;
                      })
                    ),
                    vx_core::f_else(
                      vx_core::t_any_from_func->vx_fn_new({replargs, text, repllist, current}, [replargs, text, repllist, current]() {
                        vx_core::Type_any output_1 = vx_core::f_copy(
                          vx_repl::t_replarglist,
                          replargs,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":current"),
                            vx_core::f_new(
                              vx_repl::t_repl,
                              vx_core::vx_new(vx_core::t_anylist, {
                                vx_core::vx_new_string(":name"),
                                text
                              })
                            ),
                            vx_core::vx_new_string(":repllist"),
                            vx_core::f_copy(vx_repl::t_repllist, repllist, vx_core::vx_new(vx_core::t_anylist, {
                              current}))
                          })
                        );
                        return output_1;
                      })
                    )
                  })
                );
                return output_1;
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({key}, [key]() {
                vx_core::Type_boolean output_1 = vx_core::f_eq_1(vx_core::vx_new(vx_core::t_anylist, {
                key}));
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({replargs, current, text}, [replargs, current, text]() {
                vx_core::Type_any output_1 = vx_core::f_copy(
                  vx_repl::t_replarglist,
                  replargs,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":key"),
                    vx_core::vx_new_string(""),
                    vx_core::vx_new_string(":current"),
                    vx_core::f_copy(
                      vx_repl::t_repl,
                      current,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":type"),
                        text
                      })
                    )
                  })
                );
                return output_1;
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({key}, [key]() {
                vx_core::Type_boolean output_1 = vx_core::f_eq(key, vx_core::vx_new_string(":="));
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({replargs, current, currlist, tb, argmap}, [replargs, current, currlist, tb, argmap]() {
                vx_core::Type_any output_1 = vx_core::f_copy(
                  vx_repl::t_replarglist,
                  replargs,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":key"),
                    vx_core::vx_new_string(""),
                    vx_core::vx_new_string(":current"),
                    vx_core::f_copy(
                      vx_repl::t_repl,
                      current,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":repllist"),
                        vx_core::f_copy(
                          vx_repl::t_repllist,
                          currlist,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_repl::f_repl_from_textblock_argmap(tb, argmap)
                          })
                        )
                      })
                    )
                  })
                );
                return output_1;
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({key}, [key]() {
                vx_core::Type_boolean output_1 = vx_core::f_eq(key, vx_core::vx_new_string(":doc"));
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({replargs, current, text}, [replargs, current, text]() {
                vx_core::Type_any output_1 = vx_core::f_copy(
                  vx_repl::t_replarglist,
                  replargs,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":key"),
                    vx_core::vx_new_string(""),
                    vx_core::vx_new_string(":current"),
                    vx_core::f_copy(
                      vx_repl::t_repl,
                      current,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":doc"),
                        text
                      })
                    )
                  })
                );
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({replargs}, [replargs]() {
                vx_core::Type_any output_1 = replargs;
                return output_1;
              })
            )
          })
        );
        vx_core::vx_release_one_except({key, current, repllist, currlist, text}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({replargs, tb, argmap}, output);
    return output;
  }
  /**
   * @function replarglist_from_replarglist_textblock_argmap
   * Returns a modified replarglist from by applying a textblock
   * @param  {replarglist} replargs
   * @param  {textblock} tb
   * @param  {argmap} argmap
   * @return {replarglist}
   * (func replarglist<-replarglist-textblock-argmap)
   */
  // (func replarglist<-replarglist-textblock-argmap)
  // class Class_replarglist_from_replarglist_textblock_argmap {
    Abstract_replarglist_from_replarglist_textblock_argmap::~Abstract_replarglist_from_replarglist_textblock_argmap() {}

    Class_replarglist_from_replarglist_textblock_argmap::Class_replarglist_from_replarglist_textblock_argmap() : Abstract_replarglist_from_replarglist_textblock_argmap::Abstract_replarglist_from_replarglist_textblock_argmap() {
      vx_core::refcount += 1;
    }

    Class_replarglist_from_replarglist_textblock_argmap::~Class_replarglist_from_replarglist_textblock_argmap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_replarglist_from_replarglist_textblock_argmap::vx_new(vx_core::vx_Type_listany vals) const {
      vx_repl::Func_replarglist_from_replarglist_textblock_argmap output = vx_repl::e_replarglist_from_replarglist_textblock_argmap;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_replarglist_from_replarglist_textblock_argmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Func_replarglist_from_replarglist_textblock_argmap output = vx_repl::e_replarglist_from_replarglist_textblock_argmap;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_replarglist_from_replarglist_textblock_argmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "replarglist<-replarglist-textblock-argmap", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_replarglist_from_replarglist_textblock_argmap::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_replarglist_from_replarglist_textblock_argmap::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "replarglist<-replarglist-textblock-argmap", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_replarglist_from_replarglist_textblock_argmap::vx_empty() const {return vx_repl::e_replarglist_from_replarglist_textblock_argmap;}
    vx_core::Type_any Class_replarglist_from_replarglist_textblock_argmap::vx_type() const {return vx_repl::t_replarglist_from_replarglist_textblock_argmap;}
    vx_core::Type_msgblock Class_replarglist_from_replarglist_textblock_argmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_replarglist_from_replarglist_textblock_argmap::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_replarglist_from_replarglist_textblock_argmap::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_repl::Type_replarglist replargs = vx_core::vx_any_from_any(vx_repl::t_replarglist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_textblock tb = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_argmap argmap = vx_core::vx_any_from_any(vx_core::t_argmap, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_repl::f_replarglist_from_replarglist_textblock_argmap(replargs, tb, argmap);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func repllist<-textblocklist-argmap)
  vx_repl::Type_repllist f_repllist_from_textblocklist_argmap(vx_data_textblock::Type_textblocklist textblocklist, vx_core::Type_argmap argmap) {
    vx_repl::Type_repllist output = vx_repl::e_repllist;
    vx_core::vx_reserve({textblocklist, argmap});
    output = vx_core::f_list_from_list_1(
      vx_repl::t_repllist,
      textblocklist,
      vx_core::t_any_from_any->vx_fn_new({}, [](vx_core::Type_any textblock_any) {
        vx_data_textblock::Type_textblock textblock = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, textblock_any);
        vx_core::Type_any output_1 = 
          vx_repl::f_repl_from_textblock(textblock);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({textblocklist, argmap}, output);
    return output;
  }
  /**
   * @function repllist_from_textblocklist_argmap
   * Returns a repllist from a parsed textblocklist
   * @param  {textblocklist} textblocklist
   * @param  {argmap} argmap
   * @return {repllist}
   * (func repllist<-textblocklist-argmap)
   */
  // (func repllist<-textblocklist-argmap)
  // class Class_repllist_from_textblocklist_argmap {
    Abstract_repllist_from_textblocklist_argmap::~Abstract_repllist_from_textblocklist_argmap() {}

    Class_repllist_from_textblocklist_argmap::Class_repllist_from_textblocklist_argmap() : Abstract_repllist_from_textblocklist_argmap::Abstract_repllist_from_textblocklist_argmap() {
      vx_core::refcount += 1;
    }

    Class_repllist_from_textblocklist_argmap::~Class_repllist_from_textblocklist_argmap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_repllist_from_textblocklist_argmap::vx_new(vx_core::vx_Type_listany vals) const {
      vx_repl::Func_repllist_from_textblocklist_argmap output = vx_repl::e_repllist_from_textblocklist_argmap;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_repllist_from_textblocklist_argmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Func_repllist_from_textblocklist_argmap output = vx_repl::e_repllist_from_textblocklist_argmap;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_repllist_from_textblocklist_argmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "repllist<-textblocklist-argmap", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_repllist_from_textblocklist_argmap::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_repllist_from_textblocklist_argmap::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "repllist<-textblocklist-argmap", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_repllist_from_textblocklist_argmap::vx_empty() const {return vx_repl::e_repllist_from_textblocklist_argmap;}
    vx_core::Type_any Class_repllist_from_textblocklist_argmap::vx_type() const {return vx_repl::t_repllist_from_textblocklist_argmap;}
    vx_core::Type_msgblock Class_repllist_from_textblocklist_argmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_repllist_from_textblocklist_argmap::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_repllist_from_textblocklist_argmap::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblocklist textblocklist = vx_core::vx_any_from_any(vx_data_textblock::t_textblocklist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_argmap argmap = vx_core::vx_any_from_any(vx_core::t_argmap, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_repl::f_repllist_from_textblocklist_argmap(textblocklist, argmap);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock<-script)
  vx_data_textblock::Type_textblock f_textblock_from_script(vx_core::Type_string script) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve(script);
    output = vx_data_textblock::f_textblock_parse_from_string_delim(
      script,
      vx_repl::c_delimvxlisp
    );
    vx_core::vx_release_one_except(script, output);
    return output;
  }
  /**
   * @function textblock_from_script
   * Returns a parsed textblock from a string
   * @param  {string} script
   * @return {textblock}
   * (func textblock<-script)
   */
  // (func textblock<-script)
  // class Class_textblock_from_script {
    Abstract_textblock_from_script::~Abstract_textblock_from_script() {}

    Class_textblock_from_script::Class_textblock_from_script() : Abstract_textblock_from_script::Abstract_textblock_from_script() {
      vx_core::refcount += 1;
    }

    Class_textblock_from_script::~Class_textblock_from_script() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_from_script::vx_new(vx_core::vx_Type_listany vals) const {
      vx_repl::Func_textblock_from_script output = vx_repl::e_textblock_from_script;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_from_script::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Func_textblock_from_script output = vx_repl::e_textblock_from_script;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_from_script::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "textblock<-script", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_textblock_from_script::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_textblock_from_script::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "textblock<-script", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_from_script::vx_empty() const {return vx_repl::e_textblock_from_script;}
    vx_core::Type_any Class_textblock_from_script::vx_type() const {return vx_repl::t_textblock_from_script;}
    vx_core::Type_msgblock Class_textblock_from_script::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_from_script::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_textblock_from_script::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_textblock_from_script::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      output = vx_repl::f_textblock_from_script(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_textblock_from_script::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string script = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_repl::f_textblock_from_script(script);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func typefunc<-string)
  vx_core::Type_any f_typefunc_from_string(vx_core::Type_string text) {
    vx_core::Type_any output = vx_core::e_any;
    vx_core::vx_reserve(text);
    output = vx_core::f_let(
      vx_core::t_any,
      vx_core::t_any_from_func->vx_fn_new({text}, [text]() {
        vx_core::Type_int pkgpos = vx_type::f_int_from_string_findlast(text, vx_core::vx_new_string("/"));
        vx_core::vx_ref_plus(pkgpos);
        vx_core::Type_string pkgname = vx_core::f_if_1(
          vx_core::t_string,
          vx_core::f_eq(vx_core::vx_new_int(0), pkgpos),
          vx_core::vx_new_string("vx/core"),
          vx_type::f_string_from_string_end(
            text,
            vx_core::f_minus1(pkgpos)
          )
        );
        vx_core::vx_ref_plus(pkgname);
        vx_core::Type_string name = vx_core::f_if_1(
          vx_core::t_string,
          vx_core::f_eq(vx_core::vx_new_int(0), pkgpos),
          text,
          vx_type::f_string_from_string_start(
            text,
            vx_core::f_plus1(pkgpos)
          )
        );
        vx_core::vx_ref_plus(name);
        vx_core::Type_package pkg = vx_core::f_package_global_from_name(pkgname);
        vx_core::vx_ref_plus(pkg);
        vx_core::Type_typemap typemap = pkg->typemap();
        vx_core::vx_ref_plus(typemap);
        vx_core::Type_any typeval = vx_core::f_any_from_map(vx_core::t_any, typemap, name);
        vx_core::vx_ref_plus(typeval);
        vx_core::Type_any output_1 = vx_core::f_if_1(
          vx_core::t_any,
          vx_core::f_notempty_1(typeval),
          typeval,
          vx_core::f_let(
            vx_core::t_any,
            vx_core::t_any_from_func->vx_fn_new({pkg, name}, [pkg, name]() {
              vx_core::Type_funcmap funcmap = pkg->funcmap();
              vx_core::vx_ref_plus(funcmap);
              vx_core::Type_any funcval = vx_core::f_any_from_map(vx_core::t_any, funcmap, name);
              vx_core::vx_ref_plus(funcval);
              vx_core::Type_any output_1 = vx_core::f_if_1(
                vx_core::t_any,
                vx_core::f_notempty_1(funcval),
                funcval,
                vx_core::f_empty(
                  vx_core::t_any
                )
              );
              vx_core::vx_release_one_except({funcmap, funcval}, output_1);
              return output_1;
            })
          )
        );
        vx_core::vx_release_one_except({pkgpos, pkgname, name, pkg, typemap, typeval}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(text, output);
    return output;
  }
  /**
   * @function typefunc_from_string
   * Returns a type, or func from a fully qualified name.
   * @param  {string} text
   * @return {any}
   * (func typefunc<-string)
   */
  // (func typefunc<-string)
  // class Class_typefunc_from_string {
    Abstract_typefunc_from_string::~Abstract_typefunc_from_string() {}

    Class_typefunc_from_string::Class_typefunc_from_string() : Abstract_typefunc_from_string::Abstract_typefunc_from_string() {
      vx_core::refcount += 1;
    }

    Class_typefunc_from_string::~Class_typefunc_from_string() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_typefunc_from_string::vx_new(vx_core::vx_Type_listany vals) const {
      vx_repl::Func_typefunc_from_string output = vx_repl::e_typefunc_from_string;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_typefunc_from_string::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_repl::Func_typefunc_from_string output = vx_repl::e_typefunc_from_string;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_typefunc_from_string::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "typefunc<-string", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_typefunc_from_string::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_typefunc_from_string::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "typefunc<-string", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_typefunc_from_string::vx_empty() const {return vx_repl::e_typefunc_from_string;}
    vx_core::Type_any Class_typefunc_from_string::vx_type() const {return vx_repl::t_typefunc_from_string;}
    vx_core::Type_msgblock Class_typefunc_from_string::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_typefunc_from_string::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_typefunc_from_string::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_typefunc_from_string::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      output = vx_repl::f_typefunc_from_string(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_typefunc_from_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_repl::f_typefunc_from_string(text);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_repl::Type_liblist e_liblist = NULL;
  vx_repl::Type_liblist t_liblist = NULL;
  vx_repl::Type_repl e_repl = NULL;
  vx_repl::Type_repl t_repl = NULL;
  vx_repl::Type_replarglist e_replarglist = NULL;
  vx_repl::Type_replarglist t_replarglist = NULL;
  vx_repl::Type_repllist e_repllist = NULL;
  vx_repl::Type_repllist t_repllist = NULL;
  vx_repl::Const_delimvxlisp c_delimvxlisp = NULL;
  vx_repl::Const_delimvxlispbracket c_delimvxlispbracket = NULL;
  vx_repl::Const_delimvxlispparen c_delimvxlispparen = NULL;
  vx_repl::Func_any_repl_from_functype_args e_any_repl_from_functype_args = NULL;
  vx_repl::Func_any_repl_from_functype_args t_any_repl_from_functype_args = NULL;
  vx_repl::Func_any_from_liblist_string e_any_from_liblist_string = NULL;
  vx_repl::Func_any_from_liblist_string t_any_from_liblist_string = NULL;
  vx_repl::Func_any_from_macro e_any_from_macro = NULL;
  vx_repl::Func_any_from_macro t_any_from_macro = NULL;
  vx_repl::Func_any_from_repl e_any_from_repl = NULL;
  vx_repl::Func_any_from_repl t_any_from_repl = NULL;
  vx_repl::Func_any_from_script e_any_from_script = NULL;
  vx_repl::Func_any_from_script t_any_from_script = NULL;
  vx_repl::Func_anylist_from_repllist e_anylist_from_repllist = NULL;
  vx_repl::Func_anylist_from_repllist t_anylist_from_repllist = NULL;
  vx_repl::Func_argmap_from_textblock_argmap e_argmap_from_textblock_argmap = NULL;
  vx_repl::Func_argmap_from_textblock_argmap t_argmap_from_textblock_argmap = NULL;
  vx_repl::Func_const_from_string e_const_from_string = NULL;
  vx_repl::Func_const_from_string t_const_from_string = NULL;
  vx_repl::Func_repl_bracket_from_textblock_argmap e_repl_bracket_from_textblock_argmap = NULL;
  vx_repl::Func_repl_bracket_from_textblock_argmap t_repl_bracket_from_textblock_argmap = NULL;
  vx_repl::Func_repl_empty_from_textblock_argmap e_repl_empty_from_textblock_argmap = NULL;
  vx_repl::Func_repl_empty_from_textblock_argmap t_repl_empty_from_textblock_argmap = NULL;
  vx_repl::Func_repl_paren_from_textblock_argmap e_repl_paren_from_textblock_argmap = NULL;
  vx_repl::Func_repl_paren_from_textblock_argmap t_repl_paren_from_textblock_argmap = NULL;
  vx_repl::Func_repl_from_liblist_string e_repl_from_liblist_string = NULL;
  vx_repl::Func_repl_from_liblist_string t_repl_from_liblist_string = NULL;
  vx_repl::Func_repl_from_macro e_repl_from_macro = NULL;
  vx_repl::Func_repl_from_macro t_repl_from_macro = NULL;
  vx_repl::Func_repl_from_script e_repl_from_script = NULL;
  vx_repl::Func_repl_from_script t_repl_from_script = NULL;
  vx_repl::Func_repl_from_string_argmap e_repl_from_string_argmap = NULL;
  vx_repl::Func_repl_from_string_argmap t_repl_from_string_argmap = NULL;
  vx_repl::Func_repl_from_textblock e_repl_from_textblock = NULL;
  vx_repl::Func_repl_from_textblock t_repl_from_textblock = NULL;
  vx_repl::Func_repl_from_textblock_argmap e_repl_from_textblock_argmap = NULL;
  vx_repl::Func_repl_from_textblock_argmap t_repl_from_textblock_argmap = NULL;
  vx_repl::Func_replarglist_from_replarglist_textblock_argmap e_replarglist_from_replarglist_textblock_argmap = NULL;
  vx_repl::Func_replarglist_from_replarglist_textblock_argmap t_replarglist_from_replarglist_textblock_argmap = NULL;
  vx_repl::Func_repllist_from_textblocklist_argmap e_repllist_from_textblocklist_argmap = NULL;
  vx_repl::Func_repllist_from_textblocklist_argmap t_repllist_from_textblocklist_argmap = NULL;
  vx_repl::Func_textblock_from_script e_textblock_from_script = NULL;
  vx_repl::Func_textblock_from_script t_textblock_from_script = NULL;
  vx_repl::Func_typefunc_from_string e_typefunc_from_string = NULL;
  vx_repl::Func_typefunc_from_string t_typefunc_from_string = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_repl::c_delimvxlisp = new vx_repl::Class_delimvxlisp();
      vx_repl::c_delimvxlispbracket = new vx_repl::Class_delimvxlispbracket();
      vx_repl::c_delimvxlispparen = new vx_repl::Class_delimvxlispparen();
      vx_repl::e_liblist = new Class_liblist();
      vx_core::vx_reserve_empty(vx_repl::e_liblist);
      vx_repl::t_liblist = new Class_liblist();
      vx_core::vx_reserve_type(vx_repl::t_liblist);
      vx_repl::e_repl = new Class_repl();
      vx_core::vx_reserve_empty(vx_repl::e_repl);
      vx_repl::t_repl = new Class_repl();
      vx_core::vx_reserve_type(vx_repl::t_repl);
      vx_repl::e_replarglist = new Class_replarglist();
      vx_core::vx_reserve_empty(vx_repl::e_replarglist);
      vx_repl::t_replarglist = new Class_replarglist();
      vx_core::vx_reserve_type(vx_repl::t_replarglist);
      vx_repl::e_repllist = new Class_repllist();
      vx_core::vx_reserve_empty(vx_repl::e_repllist);
      vx_repl::t_repllist = new Class_repllist();
      vx_core::vx_reserve_type(vx_repl::t_repllist);
      vx_repl::e_any_repl_from_functype_args = new vx_repl::Class_any_repl_from_functype_args();
      vx_core::vx_reserve_empty(vx_repl::e_any_repl_from_functype_args);
      vx_repl::t_any_repl_from_functype_args = new vx_repl::Class_any_repl_from_functype_args();
      vx_core::vx_reserve_type(vx_repl::t_any_repl_from_functype_args);
      vx_repl::e_any_from_liblist_string = new vx_repl::Class_any_from_liblist_string();
      vx_core::vx_reserve_empty(vx_repl::e_any_from_liblist_string);
      vx_repl::t_any_from_liblist_string = new vx_repl::Class_any_from_liblist_string();
      vx_core::vx_reserve_type(vx_repl::t_any_from_liblist_string);
      vx_repl::e_any_from_macro = new vx_repl::Class_any_from_macro();
      vx_core::vx_reserve_empty(vx_repl::e_any_from_macro);
      vx_repl::t_any_from_macro = new vx_repl::Class_any_from_macro();
      vx_core::vx_reserve_type(vx_repl::t_any_from_macro);
      vx_repl::e_any_from_repl = new vx_repl::Class_any_from_repl();
      vx_core::vx_reserve_empty(vx_repl::e_any_from_repl);
      vx_repl::t_any_from_repl = new vx_repl::Class_any_from_repl();
      vx_core::vx_reserve_type(vx_repl::t_any_from_repl);
      vx_repl::e_any_from_script = new vx_repl::Class_any_from_script();
      vx_core::vx_reserve_empty(vx_repl::e_any_from_script);
      vx_repl::t_any_from_script = new vx_repl::Class_any_from_script();
      vx_core::vx_reserve_type(vx_repl::t_any_from_script);
      vx_repl::e_anylist_from_repllist = new vx_repl::Class_anylist_from_repllist();
      vx_core::vx_reserve_empty(vx_repl::e_anylist_from_repllist);
      vx_repl::t_anylist_from_repllist = new vx_repl::Class_anylist_from_repllist();
      vx_core::vx_reserve_type(vx_repl::t_anylist_from_repllist);
      vx_repl::e_argmap_from_textblock_argmap = new vx_repl::Class_argmap_from_textblock_argmap();
      vx_core::vx_reserve_empty(vx_repl::e_argmap_from_textblock_argmap);
      vx_repl::t_argmap_from_textblock_argmap = new vx_repl::Class_argmap_from_textblock_argmap();
      vx_core::vx_reserve_type(vx_repl::t_argmap_from_textblock_argmap);
      vx_repl::e_const_from_string = new vx_repl::Class_const_from_string();
      vx_core::vx_reserve_empty(vx_repl::e_const_from_string);
      vx_repl::t_const_from_string = new vx_repl::Class_const_from_string();
      vx_core::vx_reserve_type(vx_repl::t_const_from_string);
      vx_repl::e_repl_bracket_from_textblock_argmap = new vx_repl::Class_repl_bracket_from_textblock_argmap();
      vx_core::vx_reserve_empty(vx_repl::e_repl_bracket_from_textblock_argmap);
      vx_repl::t_repl_bracket_from_textblock_argmap = new vx_repl::Class_repl_bracket_from_textblock_argmap();
      vx_core::vx_reserve_type(vx_repl::t_repl_bracket_from_textblock_argmap);
      vx_repl::e_repl_empty_from_textblock_argmap = new vx_repl::Class_repl_empty_from_textblock_argmap();
      vx_core::vx_reserve_empty(vx_repl::e_repl_empty_from_textblock_argmap);
      vx_repl::t_repl_empty_from_textblock_argmap = new vx_repl::Class_repl_empty_from_textblock_argmap();
      vx_core::vx_reserve_type(vx_repl::t_repl_empty_from_textblock_argmap);
      vx_repl::e_repl_paren_from_textblock_argmap = new vx_repl::Class_repl_paren_from_textblock_argmap();
      vx_core::vx_reserve_empty(vx_repl::e_repl_paren_from_textblock_argmap);
      vx_repl::t_repl_paren_from_textblock_argmap = new vx_repl::Class_repl_paren_from_textblock_argmap();
      vx_core::vx_reserve_type(vx_repl::t_repl_paren_from_textblock_argmap);
      vx_repl::e_repl_from_liblist_string = new vx_repl::Class_repl_from_liblist_string();
      vx_core::vx_reserve_empty(vx_repl::e_repl_from_liblist_string);
      vx_repl::t_repl_from_liblist_string = new vx_repl::Class_repl_from_liblist_string();
      vx_core::vx_reserve_type(vx_repl::t_repl_from_liblist_string);
      vx_repl::e_repl_from_macro = new vx_repl::Class_repl_from_macro();
      vx_core::vx_reserve_empty(vx_repl::e_repl_from_macro);
      vx_repl::t_repl_from_macro = new vx_repl::Class_repl_from_macro();
      vx_core::vx_reserve_type(vx_repl::t_repl_from_macro);
      vx_repl::e_repl_from_script = new vx_repl::Class_repl_from_script();
      vx_core::vx_reserve_empty(vx_repl::e_repl_from_script);
      vx_repl::t_repl_from_script = new vx_repl::Class_repl_from_script();
      vx_core::vx_reserve_type(vx_repl::t_repl_from_script);
      vx_repl::e_repl_from_string_argmap = new vx_repl::Class_repl_from_string_argmap();
      vx_core::vx_reserve_empty(vx_repl::e_repl_from_string_argmap);
      vx_repl::t_repl_from_string_argmap = new vx_repl::Class_repl_from_string_argmap();
      vx_core::vx_reserve_type(vx_repl::t_repl_from_string_argmap);
      vx_repl::e_repl_from_textblock = new vx_repl::Class_repl_from_textblock();
      vx_core::vx_reserve_empty(vx_repl::e_repl_from_textblock);
      vx_repl::t_repl_from_textblock = new vx_repl::Class_repl_from_textblock();
      vx_core::vx_reserve_type(vx_repl::t_repl_from_textblock);
      vx_repl::e_repl_from_textblock_argmap = new vx_repl::Class_repl_from_textblock_argmap();
      vx_core::vx_reserve_empty(vx_repl::e_repl_from_textblock_argmap);
      vx_repl::t_repl_from_textblock_argmap = new vx_repl::Class_repl_from_textblock_argmap();
      vx_core::vx_reserve_type(vx_repl::t_repl_from_textblock_argmap);
      vx_repl::e_replarglist_from_replarglist_textblock_argmap = new vx_repl::Class_replarglist_from_replarglist_textblock_argmap();
      vx_core::vx_reserve_empty(vx_repl::e_replarglist_from_replarglist_textblock_argmap);
      vx_repl::t_replarglist_from_replarglist_textblock_argmap = new vx_repl::Class_replarglist_from_replarglist_textblock_argmap();
      vx_core::vx_reserve_type(vx_repl::t_replarglist_from_replarglist_textblock_argmap);
      vx_repl::e_repllist_from_textblocklist_argmap = new vx_repl::Class_repllist_from_textblocklist_argmap();
      vx_core::vx_reserve_empty(vx_repl::e_repllist_from_textblocklist_argmap);
      vx_repl::t_repllist_from_textblocklist_argmap = new vx_repl::Class_repllist_from_textblocklist_argmap();
      vx_core::vx_reserve_type(vx_repl::t_repllist_from_textblocklist_argmap);
      vx_repl::e_textblock_from_script = new vx_repl::Class_textblock_from_script();
      vx_core::vx_reserve_empty(vx_repl::e_textblock_from_script);
      vx_repl::t_textblock_from_script = new vx_repl::Class_textblock_from_script();
      vx_core::vx_reserve_type(vx_repl::t_textblock_from_script);
      vx_repl::e_typefunc_from_string = new vx_repl::Class_typefunc_from_string();
      vx_core::vx_reserve_empty(vx_repl::e_typefunc_from_string);
      vx_repl::t_typefunc_from_string = new vx_repl::Class_typefunc_from_string();
      vx_core::vx_reserve_type(vx_repl::t_typefunc_from_string);
      vx_repl::Class_delimvxlisp::vx_const_new(vx_repl::c_delimvxlisp);
      vx_repl::Class_delimvxlispbracket::vx_const_new(vx_repl::c_delimvxlispbracket);
      vx_repl::Class_delimvxlispparen::vx_const_new(vx_repl::c_delimvxlispparen);
      vx_core::vx_Type_mapany maptype;
      vx_core::vx_Type_mapany mapconst;
      vx_core::vx_Type_mapfunc mapfunc;
      vx_core::vx_Type_mapany mapempty;
      maptype["liblist"] = vx_repl::t_liblist;
      maptype["repl"] = vx_repl::t_repl;
      maptype["replarglist"] = vx_repl::t_replarglist;
      maptype["repllist"] = vx_repl::t_repllist;
      mapconst["delimvxlisp"] = vx_repl::c_delimvxlisp;
      mapconst["delimvxlispbracket"] = vx_repl::c_delimvxlispbracket;
      mapconst["delimvxlispparen"] = vx_repl::c_delimvxlispparen;
      mapfunc["any-repl<-functype-args"] = vx_repl::t_any_repl_from_functype_args;
      mapfunc["any<-liblist-string"] = vx_repl::t_any_from_liblist_string;
      mapfunc["any<-macro"] = vx_repl::t_any_from_macro;
      mapfunc["any<-repl"] = vx_repl::t_any_from_repl;
      mapfunc["any<-script"] = vx_repl::t_any_from_script;
      mapfunc["anylist<-repllist"] = vx_repl::t_anylist_from_repllist;
      mapfunc["argmap<-textblock-argmap"] = vx_repl::t_argmap_from_textblock_argmap;
      mapfunc["const<-string"] = vx_repl::t_const_from_string;
      mapfunc["repl-bracket<-textblock-argmap"] = vx_repl::t_repl_bracket_from_textblock_argmap;
      mapfunc["repl-empty<-textblock-argmap"] = vx_repl::t_repl_empty_from_textblock_argmap;
      mapfunc["repl-paren<-textblock-argmap"] = vx_repl::t_repl_paren_from_textblock_argmap;
      mapfunc["repl<-liblist-string"] = vx_repl::t_repl_from_liblist_string;
      mapfunc["repl<-macro"] = vx_repl::t_repl_from_macro;
      mapfunc["repl<-script"] = vx_repl::t_repl_from_script;
      mapfunc["repl<-string-argmap"] = vx_repl::t_repl_from_string_argmap;
      mapfunc["repl<-textblock"] = vx_repl::t_repl_from_textblock;
      mapfunc["repl<-textblock-argmap"] = vx_repl::t_repl_from_textblock_argmap;
      mapfunc["replarglist<-replarglist-textblock-argmap"] = vx_repl::t_replarglist_from_replarglist_textblock_argmap;
      mapfunc["repllist<-textblocklist-argmap"] = vx_repl::t_repllist_from_textblocklist_argmap;
      mapfunc["textblock<-script"] = vx_repl::t_textblock_from_script;
      mapfunc["typefunc<-string"] = vx_repl::t_typefunc_from_string;
      vx_core::vx_global_package_set("vx/repl", maptype, mapconst, mapfunc);
	   }
  // }

}
