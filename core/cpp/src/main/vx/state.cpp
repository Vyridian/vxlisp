#include <map>
#include <string>
#include <vector>
#include "../vx/core.hpp"
#include "state.hpp"

namespace vx_state {


  // (type value-map)
  // class Class_value_map {
    Abstract_value_map::~Abstract_value_map() {}

    Class_value_map::Class_value_map() : Abstract_value_map::Abstract_value_map() {
      vx_core::refcount += 1;
    }

    Class_value_map::~Class_value_map() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (auto const& [key, val] : this->vx_p_map) {
        vx_core::vx_release_one(val);
      }
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_value_map::vx_map() const {
      vx_core::vx_Type_mapany output = this->vx_p_map;
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_value_map::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      const vx_state::Class_value_map* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_any> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_core::e_any);
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_value_map::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_state::Type_value_map output = vx_state::e_value_map;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_core::Type_any> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        map[key] = val;
      }
      output = new vx_state::Class_value_map();
      output->vx_p_map = map;
      for (auto const& [key, val] : map) {
        vx_core::vx_reserve(val);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      for (auto const& [key, val] : mapval) {
        vx_core::vx_release_except(val, output);
      }
      return output;
    }

    vx_core::Type_any Class_value_map::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_state::e_value_map, vals);
    }

    vx_core::Type_any Class_value_map::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_state::Type_value_map output = vx_state::e_value_map;
      vx_state::Type_value_map valmap = vx_core::vx_any_from_any(vx_state::t_value_map, copyval);
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::vector<std::string> keys;
      std::map<std::string, vx_core::Type_any> mapval;
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string valstring = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            key = valstring->vx_string();
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("Key Expected: " + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          vx_core::Type_any valany = valsub;
          if (valany) {
            mapval[key] = valany;
            keys.push_back(key);
            key = "";
          }
        }
      }
      output = new vx_state::Class_value_map();
      output->vx_p_keys = keys;
      output->vx_p_map = mapval;
      for (auto const& [key, val] : mapval) {
        vx_core::vx_reserve(val);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_value_map::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_state::Class_value_map::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_value_map::vx_empty() const {return vx_state::e_value_map;}
    vx_core::Type_any Class_value_map::vx_type() const {return vx_state::t_value_map;}

    vx_core::Type_typedef Class_value_map::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/state", // pkgname
        "value-map", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_core::t_any}), // allowtypes
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

  // (func change)
  vx_core::Type_boolean f_change(vx_state::Type_value_map valuemap) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve(valuemap);
    vx_core::vx_release_one_except(valuemap, output);
    return output;
  }

  // (func change)
  // class Class_change {
    Abstract_change::~Abstract_change() {}

    Class_change::Class_change() : Abstract_change::Abstract_change() {
      vx_core::refcount += 1;
    }

    Class_change::~Class_change() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_change::vx_new(vx_core::vx_Type_listany vals) const {
      vx_state::Func_change output = vx_state::e_change;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_change::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_state::Func_change output = vx_state::e_change;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_change::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/state", // pkgname
        "change", // name
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

    vx_core::Type_funcdef Class_change::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/state", // pkgname
        "change", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_change::vx_empty() const {return vx_state::e_change;}
    vx_core::Type_any Class_change::vx_type() const {return vx_state::t_change;}
    vx_core::Type_msgblock Class_change::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_change::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_change::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_change::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_state::Type_value_map inputval = vx_core::vx_any_from_any(vx_state::t_value_map, val);
      output = vx_state::f_change(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_change::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_state::Type_value_map valuemap = vx_core::vx_any_from_any(vx_state::t_value_map, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_state::f_change(valuemap);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func register)
  vx_core::Type_boolean f_register(vx_core::Type_statelistener listener) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve(listener);
    vx_core::vx_release_one_except(listener, output);
    return output;
  }

  // (func register)
  // class Class_register {
    Abstract_register::~Abstract_register() {}

    Class_register::Class_register() : Abstract_register::Abstract_register() {
      vx_core::refcount += 1;
    }

    Class_register::~Class_register() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_register::vx_new(vx_core::vx_Type_listany vals) const {
      vx_state::Func_register output = vx_state::e_register;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_register::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_state::Func_register output = vx_state::e_register;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_register::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/state", // pkgname
        "register", // name
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

    vx_core::Type_funcdef Class_register::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/state", // pkgname
        "register", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_register::vx_empty() const {return vx_state::e_register;}
    vx_core::Type_any Class_register::vx_type() const {return vx_state::t_register;}
    vx_core::Type_msgblock Class_register::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_register::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_register::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_register::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_statelistener inputval = vx_core::vx_any_from_any(vx_core::t_statelistener, val);
      output = vx_state::f_register(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_register::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_statelistener listener = vx_core::vx_any_from_any(vx_core::t_statelistener, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_state::f_register(listener);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_state::Type_value_map e_value_map = NULL;
  vx_state::Type_value_map t_value_map = NULL;
  vx_state::Func_change e_change = NULL;
  vx_state::Func_change t_change = NULL;
  vx_state::Func_register e_register = NULL;
  vx_state::Func_register t_register = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_state::e_value_map = new Class_value_map();
      vx_core::vx_reserve_empty(vx_state::e_value_map);
      vx_state::t_value_map = new Class_value_map();
      vx_core::vx_reserve_type(vx_state::t_value_map);
      vx_state::e_change = new vx_state::Class_change();
      vx_core::vx_reserve_empty(vx_state::e_change);
      vx_state::t_change = new vx_state::Class_change();
      vx_core::vx_reserve_type(vx_state::t_change);
      vx_state::e_register = new vx_state::Class_register();
      vx_core::vx_reserve_empty(vx_state::e_register);
      vx_state::t_register = new vx_state::Class_register();
      vx_core::vx_reserve_type(vx_state::t_register);
    }
    vx_core::vx_Type_mapany vx_Class_package::maptype() {
      vx_core::vx_Type_mapany output;
      output["anylist"] = vx_core::t_anylist;
      return output;
    }
    vx_core::vx_Type_mapany vx_Class_package::mapconst() {
      vx_core::vx_Type_mapany output;
      return output;
    }
    std::map<std::string, vx_core::Type_func> vx_Class_package::mapfunc() {
      vx_core::vx_Type_mapfunc output;
      return output;
    }
  // }

}
