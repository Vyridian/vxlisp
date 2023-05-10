#include <any>
#include <map>
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
    std::map<std::string, vx_core::Type_any*> vx_state::Type_value_map::vx_map() {
      return vx_core::map_from_map(vx_core::t_any, this->vx_p_map);
    }

    // vx_any(key)
    vx_core::Type_any* vx_state::Type_value_map::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_state::Type_value_map* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_any*> mapval = map->vx_p_map;
      output = vx_core::any_from_map(mapval, skey, vx_core::e_any);
      return output;
    }

    // vx_new_from_map(mapval)
    vx_state::Type_value_map* vx_state::Type_value_map::vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval) {
      vx_state::Type_value_map* output;
      vx_core::Type_msgblock* msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_core::Type_any*> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any* val = iter.second;
        vx_core::Type_any* valtype = vx_core::t_any->vx_type_from_any(val);
        if (valtype == vx_core::t_any) {
          vx_core::Type_any* castval = vx_core::any_from_any(vx_core::t_any, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(value_map) Invalid Value: " + vx_core::string_from_any(val) + "");
          msgblock = vx_core::t_msgblock->vx_copy(msgblock, msg);
        }
      }
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template<typename... Args> vx_state::Type_value_map* vx_state::Type_value_map::vx_new(Args*... args) {return vx_state::e_value_map->vx_copy(args...);}
    template<typename... Args> vx_state::Type_value_map* vx_state::Type_value_map::vx_copy(Args*... args) {
      vx_state::Type_value_map* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_state::Type_value_map* valmap = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(valmap, vals);
      std::map<std::string, vx_core::Type_any*> mapval;
      std::string key = "";
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::t_msgblock->vx_copy(msgblock, valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::t_msgblock->vx_copy(msgblock, valsub);
        } else if (key == "") {
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string* valstring = vx_core::any_from_any(vx_core::t_string, valsub);
            key = valstring->vx_string();
          } else if (valsubtype == vx_core::t_nativestring) {
            key = vx_core_::any_from_any("", valsub);
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("Key Expected: " + vx_core::string_from_any(valsub) + "");
            msgblock = vx_core::t_msgblock->vx_copy(msgblock, msg);
          }
        } else {
          vx_core::Type_any* valany;
          if (valsubtype == vx_core::t_any) {
            valany = vx_core::any_from_any(vx_core::t_any, valsub);
          } else if (valsubtype == vx_core::t_any) {
            valany = vx_core::any_from_any(vx_core::t_any, valsub);
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("Invalid Key/Value: " + key + " "  + vx_core::string_from_any(valsub) + "");
            msgblock = vx_core::t_msgblock->vx_copy(msgblock, msg);
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

    vx_state::Type_value_map* vx_state::Type_value_map::vx_empty() {return vx_state::e_value_map;}
    vx_state::Type_value_map* vx_state::Type_value_map::vx_type() {return vx_state::t_value_map;}

    vx_core::Type_typedef* vx_state::Type_value_map::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/state", // pkgname
        "value-map", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_any), // allowtypes
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
   * @function change
   * Changes the current state
   * @param  {value-map} valuemap
   * @return {boolean}
   * (func change)
   */
  //class Func_change {

    template<class... Args> vx_state::Func_change* vx_state::Func_change::vx_new(Args*... args) {
      vx_state::Func_change* output;
      return output;
    }

    template<class... Args> vx_state::Func_change* vx_state::Func_change::vx_copy(Args*... args) {
      vx_state::Func_change* output;
      return output;
    }

    vx_core::Type_typedef* vx_state::Func_change::vx_typedef() {return vx_state::t_change->vx_typedef();}

    vx_core::Type_funcdef* vx_state::Func_change::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/state", // pkgname
        "change", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
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

    vx_state::Func_change* vx_state::Func_change::vx_empty() {return vx_state::e_change;}
    vx_state::Func_change* vx_state::Func_change::vx_type() {return vx_state::t_change;}

    vx_core::Func_any_from_any* vx_state::Func_change::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_state::Func_change::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_state::Type_value_map* inputval = (vx_state::Type_value_map)value;
      vx_core::Type_any* outputval = vx_state::f_change(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_state::Func_change::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_state::Type_value_map* valuemap = vx_core::f_any_from_any(vx_state::t_value_map, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_state::f_change(valuemap);
      return output;
    }

    vx_core::Type_boolean* vx_state::Func_change::vx_change(vx_state::Type_value_map* valuemap) {
      return vx_state::f_change(valuemap);
    }

  //}

  vx_state::Func_change* vx_state::e_change = new vx_state::Func_change();
  vx_state::Func_change* vx_state::t_change = new vx_state::Func_change();

  vx_core::Type_boolean* vx_state::f_change(vx_state::Type_value_map* valuemap) {
    vx_core::Type_boolean* output = vx_core::e_boolean;
    return output;
  }

  /**
   * @function register
   * @param  {statelistener} listener
   * @return {boolean}
   * (func register)
   */
  //class Func_register {

    template<class... Args> vx_state::Func_register* vx_state::Func_register::vx_new(Args*... args) {
      vx_state::Func_register* output;
      return output;
    }

    template<class... Args> vx_state::Func_register* vx_state::Func_register::vx_copy(Args*... args) {
      vx_state::Func_register* output;
      return output;
    }

    vx_core::Type_typedef* vx_state::Func_register::vx_typedef() {return vx_state::t_register->vx_typedef();}

    vx_core::Type_funcdef* vx_state::Func_register::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/state", // pkgname
        "register", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
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

    vx_state::Func_register* vx_state::Func_register::vx_empty() {return vx_state::e_register;}
    vx_state::Func_register* vx_state::Func_register::vx_type() {return vx_state::t_register;}

    vx_core::Func_any_from_any* vx_state::Func_register::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_state::Func_register::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_core::Type_statelistener* inputval = (vx_core::Type_statelistener)value;
      vx_core::Type_any* outputval = vx_state::f_register(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_state::Func_register::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Type_statelistener* listener = vx_core::f_any_from_any(vx_core::t_statelistener, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_state::f_register(listener);
      return output;
    }

    vx_core::Type_boolean* vx_state::Func_register::vx_register(vx_core::Type_statelistener* listener) {
      return vx_state::f_register(listener);
    }

  //}

  vx_state::Func_register* vx_state::e_register = new vx_state::Func_register();
  vx_state::Func_register* vx_state::t_register = new vx_state::Func_register();

  vx_core::Type_boolean* vx_state::f_register(vx_core::Type_statelistener* listener) {
    vx_core::Type_boolean* output = vx_core::e_boolean;
    return output;
  }


//}
