#include <map>
#include <memory>
#include <string>
#include "../vx/core.hpp"
#include "vx/state.hpp"

//namespace vx_state {

  /**
   * type: value-map
   * (type value-map)
   */
  //class Type_value_map {
    // vx_map()
    vx_core::vx_Type_mapany vx_state::Class_value_map::vx_map() {
      return vx_core::map_from_map(vx_core::t_any, this->vx_p_map);
    }

    // vx_any(key)
    vx_core::Type_any vx_state::Class_value_map::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      vx_state::Class_value_map* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_any> mapval = map->vx_p_map;
      output = vx_core::any_from_map(mapval, skey, vx_core::e_any);
      return output;
    }

    // vx_new_from_map(mapval)
    template <class T> std::shared_ptr<T>  vx_state::Class_value_map::vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval) {
      vx_state::Type_value_map output;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_core::Type_any> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = vx_core::t_any->vx_type_from_any(val);
        if (valtype == vx_core::t_any) {
          vx_core::Type_any castval = vx_core::any_from_any(vx_core::t_any, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(value_map) Invalid Value: " + vx_core::string_from_any(val) + "");
          msgblock = vx_core::t_msgblock->vx_copy(vx_core::t_msgblock, {msgblock, msg});
        }
      }
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_state::Class_value_map::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_state::e_value_map->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_state::Class_value_map::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_state::Type_value_map output;
      vx_state::Class_value_map* valmap = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(valmap, vals);
      std::map<std::string, vx_core::Type_any> mapval;
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::t_msgblock->vx_copy(vx_core::t_msgblock, {msgblock, valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::t_msgblock->vx_copy(vx_core::t_msgblock, {msgblock, valsub});
        } else if (key == "") {
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string valstring = vx_core::any_from_any(vx_core::t_string, valsub);
            key = valstring->vx_string();
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("Key Expected: " + vx_core::string_from_any(valsub) + "");
            msgblock = vx_core::t_msgblock->vx_copy(vx_core::t_msgblock, {msgblock, msg});
          }
        } else {
          vx_core::Type_any valany;
          if (valsubtype == vx_core::t_any) {
            valany = vx_core::any_from_any(vx_core::t_any, valsub);
          } else if (valsubtype == vx_core::t_any) {
            valany = vx_core::any_from_any(vx_core::t_any, valsub);
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("Invalid Key/Value: " + key + " "  + vx_core::string_from_any(valsub) + "");
            msgblock = vx_core::t_msgblock->vx_copy(vx_core::t_msgblock, {msgblock, msg});
          }
          if (valany != NULL) {
            mapval[key] = valany;
            key = "";
          }
        }
      }
      output->vx_p_map = mapval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_state::Class_value_map::vx_empty(std::shared_ptr<T> val) {return vx_state::e_value_map;}
    template <class T> std::shared_ptr<T> vx_state::Class_value_map::vx_type(std::shared_ptr<T> val) {return vx_state::t_value_map;}

    vx_core::Type_typedef vx_state::Class_value_map::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/state", // pkgname
        "value-map", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_any}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_state::Type_value_map vx_state::e_value_map = std::make_shared<vx_state::Class_value_map>();
    vx_state::Type_value_map vx_state::t_value_map = std::make_shared<vx_state::Class_value_map>();
  //}
  /**
   * @function change
   * Changes the current state
   * @param  {value-map} valuemap
   * @return {boolean}
   * (func change)
   */
  //class Func_change {

    template <class T> std::shared_ptr<T> vx_state::Class_change::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_state::Func_change output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_state::Class_change::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_state::Func_change output;
      return output;
    }

    vx_core::Type_typedef vx_state::Class_change::vx_typedef() {return vx_state::t_change->vx_typedef();}

    vx_core::Type_funcdef vx_state::Class_change::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/state", // pkgname
        "change", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_state::Class_change::vx_empty(std::shared_ptr<T> val) {return vx_state::e_change;}
    template <class T> std::shared_ptr<T> vx_state::Class_change::vx_type(std::shared_ptr<T> val) {return vx_state::t_change;}

    vx_core::Func_any_from_any vx_state::Class_change::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_state::Class_change::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_state::Type_value_map inputval = (vx_state::Type_value_map)value;
      vx_core::Type_any outputval = vx_state::f_change(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_state::Class_change::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_state::Type_value_map valuemap = vx_core::f_any_from_any(vx_state::t_value_map, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_state::f_change(valuemap);
      return output;
    }

    vx_core::Type_boolean vx_state::Class_change::vx_change(vx_state::Type_value_map valuemap) {
      return vx_state::f_change(valuemap);
    }

  //}

  vx_state::Func_change vx_state::e_change = std::make_shared<vx_state::Class_change>();
  vx_state::Func_change vx_state::t_change = std::make_shared<vx_state::Class_change>();

  vx_core::Type_boolean vx_state::f_change(vx_state::Type_value_map valuemap) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    return output;
  }

  /**
   * @function register
   * @param  {statelistener} listener
   * @return {boolean}
   * (func register)
   */
  //class Func_register {

    template <class T> std::shared_ptr<T> vx_state::Class_register::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_state::Func_register output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_state::Class_register::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_state::Func_register output;
      return output;
    }

    vx_core::Type_typedef vx_state::Class_register::vx_typedef() {return vx_state::t_register->vx_typedef();}

    vx_core::Type_funcdef vx_state::Class_register::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/state", // pkgname
        "register", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_state::Class_register::vx_empty(std::shared_ptr<T> val) {return vx_state::e_register;}
    template <class T> std::shared_ptr<T> vx_state::Class_register::vx_type(std::shared_ptr<T> val) {return vx_state::t_register;}

    vx_core::Func_any_from_any vx_state::Class_register::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_state::Class_register::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_statelistener inputval = (vx_core::Type_statelistener)value;
      vx_core::Type_any outputval = vx_state::f_register(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_state::Class_register::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_statelistener listener = vx_core::f_any_from_any(vx_core::t_statelistener, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_state::f_register(listener);
      return output;
    }

    vx_core::Type_boolean vx_state::Class_register::vx_register(vx_core::Type_statelistener listener) {
      return vx_state::f_register(listener);
    }

  //}

  vx_state::Func_register vx_state::e_register = std::make_shared<vx_state::Class_register>();
  vx_state::Func_register vx_state::t_register = std::make_shared<vx_state::Class_register>();

  vx_core::Type_boolean vx_state::f_register(vx_core::Type_statelistener listener) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    return output;
  }


//}
