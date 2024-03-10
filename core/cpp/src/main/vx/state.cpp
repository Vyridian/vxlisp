#include <map>
#include <string>
#include <vector>
#include "../vx/core.hpp"
#include "state.hpp"

namespace vx_state {



  // (type valuemap)
  // class Class_valuemap {
    Abstract_valuemap::~Abstract_valuemap() {}

    Class_valuemap::Class_valuemap() : Abstract_valuemap::Abstract_valuemap() {
      vx_core::refcount += 1;
    }

    Class_valuemap::~Class_valuemap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (auto const& [key, val] : this->vx_p_map) {
        vx_core::vx_release_one(val);
      }
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_valuemap::vx_map() const {
      vx_core::vx_Type_mapany output = this->vx_p_map;
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_valuemap::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      const vx_state::Class_valuemap* map = this;
      std::string skey = key->vx_string();
      if (vx_core::vx_boolean_from_string_starts(skey, ":")) {
        skey = vx_core::vx_string_from_string_start(skey, 2);
      }
      std::map<std::string, vx_core::Type_any> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_core::e_any);
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_valuemap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_state::Type_valuemap output = vx_state::e_valuemap;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_core::Type_any> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        map[key] = val;
      }
      if ((map.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_state::Class_valuemap();
        output->vx_p_map = map;
        for (auto const& [key, val] : map) {
          vx_core::vx_reserve(val);
        }
        if (msgblock != vx_core::e_msgblock) {
          output->vx_p_msgblock = msgblock;
          vx_core::vx_reserve(msgblock);
        }
      }
      for (auto const& [key, val] : mapval) {
        vx_core::vx_release_except(val, output);
      }
      return output;
    }

    vx_core::Type_any Class_valuemap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_state::e_valuemap, vals);
    }

    vx_core::Type_any Class_valuemap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_state::Type_valuemap output = vx_state::e_valuemap;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_state::Type_valuemap valmap = vx_core::vx_any_from_any(vx_state::t_valuemap, copyval);
      output = valmap;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_core::Type_any> mapval = valmap->vx_map();
      std::vector<std::string> keys = valmap->vx_p_keys;
      std::string skey = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (skey == "") {
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string valstring = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            skey = valstring->vx_string();
            if (vx_core::vx_boolean_from_string_starts(skey, ":")) {
              skey = vx_core::vx_string_from_string_start(skey, 2);
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("Key Expected: " + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          vx_core::Type_any valany = valsub;
          if (valany) {
            ischanged = true;
            mapval[skey] = valany;
            if (!vx_core::vx_boolean_from_list_find(keys, skey)) {
          	 		keys.push_back(skey);
            }
            skey = "";
          }
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_state::Class_valuemap();
        output->vx_p_keys = keys;
        output->vx_p_map = mapval;
        for (auto const& [key, val] : mapval) {
          vx_core::vx_reserve(val);
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

    vx_core::Type_msgblock Class_valuemap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_state::Class_valuemap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_valuemap::vx_empty() const {return vx_state::e_valuemap;}
    vx_core::Type_any Class_valuemap::vx_type() const {return vx_state::t_valuemap;}

    vx_core::Type_typedef Class_valuemap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/state", // pkgname
        "valuemap", // name
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

    vx_core::Type_constdef Class_valuemap::vx_constdef() const {return this->vx_p_constdef;}


  //}
  /**
   * @function any_readstate_from_mapname_name
   * Returns the named state value
   * @param  {string} mapname
   * @param  {string} name
   * @return {any-1}
   * (func any-readstate<-mapname-name)
   */
  // (func any-readstate<-mapname-name)
  // class Class_any_readstate_from_mapname_name {
    Abstract_any_readstate_from_mapname_name::~Abstract_any_readstate_from_mapname_name() {}

    Class_any_readstate_from_mapname_name::Class_any_readstate_from_mapname_name() : Abstract_any_readstate_from_mapname_name::Abstract_any_readstate_from_mapname_name() {
      vx_core::refcount += 1;
    }

    Class_any_readstate_from_mapname_name::~Class_any_readstate_from_mapname_name() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_any_readstate_from_mapname_name::vx_new(vx_core::vx_Type_listany vals) const {
      vx_state::Func_any_readstate_from_mapname_name output = vx_state::e_any_readstate_from_mapname_name;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_any_readstate_from_mapname_name::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_state::Func_any_readstate_from_mapname_name output = vx_state::e_any_readstate_from_mapname_name;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_any_readstate_from_mapname_name::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/state", // pkgname
        "any-readstate<-mapname-name", // name
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

    vx_core::Type_constdef Class_any_readstate_from_mapname_name::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_any_readstate_from_mapname_name::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/state", // pkgname
        "any-readstate<-mapname-name", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_any_readstate_from_mapname_name::vx_empty() const {return vx_state::e_any_readstate_from_mapname_name;}
    vx_core::Type_any Class_any_readstate_from_mapname_name::vx_type() const {return vx_state::t_any_readstate_from_mapname_name;}
    vx_core::Type_msgblock Class_any_readstate_from_mapname_name::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_readstate_from_mapname_name::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_any_readstate_from_mapname_name::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string mapname = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string name = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_state::f_any_readstate_from_mapname_name(generic_any_1, context, mapname, name);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}
  /**
   * @function any_readstate_from_name
   * Returns the named state value
   * @param  {string} name
   * @return {any-1}
   * (func any-readstate<-name)
   */
  // (func any-readstate<-name)
  // class Class_any_readstate_from_name {
    Abstract_any_readstate_from_name::~Abstract_any_readstate_from_name() {}

    Class_any_readstate_from_name::Class_any_readstate_from_name() : Abstract_any_readstate_from_name::Abstract_any_readstate_from_name() {
      vx_core::refcount += 1;
    }

    Class_any_readstate_from_name::~Class_any_readstate_from_name() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_any_readstate_from_name::vx_new(vx_core::vx_Type_listany vals) const {
      vx_state::Func_any_readstate_from_name output = vx_state::e_any_readstate_from_name;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_any_readstate_from_name::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_state::Func_any_readstate_from_name output = vx_state::e_any_readstate_from_name;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_any_readstate_from_name::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/state", // pkgname
        "any-readstate<-name", // name
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

    vx_core::Type_constdef Class_any_readstate_from_name::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_any_readstate_from_name::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/state", // pkgname
        "any-readstate<-name", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_any_readstate_from_name::vx_empty() const {return vx_state::e_any_readstate_from_name;}
    vx_core::Type_any Class_any_readstate_from_name::vx_type() const {return vx_state::t_any_readstate_from_name;}
    vx_core::Type_msgblock Class_any_readstate_from_name::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_readstate_from_name::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_any_readstate_from_name::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_any_readstate_from_name::vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      output = vx_state::f_any_readstate_from_name(vx_core::t_any, context, inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_any_readstate_from_name::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string name = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_state::f_any_readstate_from_name(generic_any_1, context, name);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func boolean-writestate<-mapname-name-value)
  vx_core::Type_boolean f_boolean_writestate_from_mapname_name_value(vx_core::Type_context context, vx_core::Type_string mapname, vx_core::Type_string name, vx_core::Type_any value) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve({mapname, name, value});
    output = vx_core::f_let(
      vx_core::t_boolean,
      vx_core::t_any_from_func->vx_fn_new({context, mapname, name, value}, [context, mapname, name, value]() {
        vx_state::Type_valuemap valmap = vx_state::f_any_readstate_from_name(vx_state::t_valuemap, context, mapname);
        vx_core::vx_ref_plus(valmap);
        vx_core::Type_boolean output_1 = vx_core::f_if_2(
          vx_core::t_boolean,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({valmap}, [valmap]() {
                vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(valmap);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({name, value, mapname, context}, [name, value, mapname, context]() {
                vx_core::Type_boolean output_1 = vx_core::f_let(
                  vx_core::t_boolean,
                  vx_core::t_any_from_func->vx_fn_new({name, value, mapname, context}, [name, value, mapname, context]() {
                    vx_state::Type_valuemap valmap2 = vx_core::f_new(
                      vx_state::t_valuemap,
                      vx_core::vx_new(vx_core::t_anylist, {
                        name,
                        value
                      })
                    );
                    vx_core::vx_ref_plus(valmap2);
                    vx_core::Type_statelistener listener = vx_core::f_new(
                      vx_core::t_statelistener,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string(":name"),
                        mapname,
                        vx_core::vx_new_string(":value"),
                        valmap2
                      })
                    );
                    vx_core::vx_ref_plus(listener);
                    vx_core::Type_boolean output_1 = vx_state::f_boolean_writestate_from_statelistener(context, listener);
                    vx_core::vx_release_one_except({valmap2, listener}, output_1);
                    return output_1;
                  })
                );
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({valmap, name, value}, [valmap, name, value]() {
                vx_core::Type_boolean output_1 = vx_core::f_boolean_write_from_map_name_value(valmap, name, value);
                return output_1;
              })
            )
          })
        );
        vx_core::vx_release_one_except(valmap, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({mapname, name, value}, output);
    return output;
  }
  /**
   * @function boolean_writestate_from_mapname_name_value
   * Returns the named state value and changes it to the new value
   * @param  {string} mapname
   * @param  {string} name
   * @param  {any} value
   * @return {boolean}
   * (func boolean-writestate<-mapname-name-value)
   */
  // (func boolean-writestate<-mapname-name-value)
  // class Class_boolean_writestate_from_mapname_name_value {
    Abstract_boolean_writestate_from_mapname_name_value::~Abstract_boolean_writestate_from_mapname_name_value() {}

    Class_boolean_writestate_from_mapname_name_value::Class_boolean_writestate_from_mapname_name_value() : Abstract_boolean_writestate_from_mapname_name_value::Abstract_boolean_writestate_from_mapname_name_value() {
      vx_core::refcount += 1;
    }

    Class_boolean_writestate_from_mapname_name_value::~Class_boolean_writestate_from_mapname_name_value() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_boolean_writestate_from_mapname_name_value::vx_new(vx_core::vx_Type_listany vals) const {
      vx_state::Func_boolean_writestate_from_mapname_name_value output = vx_state::e_boolean_writestate_from_mapname_name_value;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_boolean_writestate_from_mapname_name_value::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_state::Func_boolean_writestate_from_mapname_name_value output = vx_state::e_boolean_writestate_from_mapname_name_value;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_boolean_writestate_from_mapname_name_value::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/state", // pkgname
        "boolean-writestate<-mapname-name-value", // name
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

    vx_core::Type_constdef Class_boolean_writestate_from_mapname_name_value::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_boolean_writestate_from_mapname_name_value::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/state", // pkgname
        "boolean-writestate<-mapname-name-value", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_boolean_writestate_from_mapname_name_value::vx_empty() const {return vx_state::e_boolean_writestate_from_mapname_name_value;}
    vx_core::Type_any Class_boolean_writestate_from_mapname_name_value::vx_type() const {return vx_state::t_boolean_writestate_from_mapname_name_value;}
    vx_core::Type_msgblock Class_boolean_writestate_from_mapname_name_value::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_writestate_from_mapname_name_value::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_boolean_writestate_from_mapname_name_value::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string mapname = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string name = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_state::f_boolean_writestate_from_mapname_name_value(context, mapname, name, value);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func boolean-writestate<-name-value)
  vx_core::Type_boolean f_boolean_writestate_from_name_value(vx_core::Type_context context, vx_core::Type_string name, vx_core::Type_any value) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve({name, value});
    output = vx_core::f_let(
      vx_core::t_boolean,
      vx_core::t_any_from_func->vx_fn_new({context, name, value}, [context, name, value]() {
        vx_core::Type_statelistener listenercur = vx_state::f_statelistener_readstate_from_name(context, name);
        vx_core::vx_ref_plus(listenercur);
        vx_core::Type_statelistener listenerchg = vx_core::f_copy(
          vx_core::t_statelistener,
          listenercur,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":name"),
            name,
            vx_core::vx_new_string(":value"),
            value
          })
        );
        vx_core::vx_ref_plus(listenerchg);
        vx_core::Type_boolean output_1 = vx_state::f_boolean_writestate_from_statelistener(context, listenerchg);
        vx_core::vx_release_one_except({listenercur, listenerchg}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({name, value}, output);
    return output;
  }
  /**
   * @function boolean_writestate_from_name_value
   * Returns the named state value and changes it to the new value
   * @param  {string} name
   * @param  {any} value
   * @return {boolean}
   * (func boolean-writestate<-name-value)
   */
  // (func boolean-writestate<-name-value)
  // class Class_boolean_writestate_from_name_value {
    Abstract_boolean_writestate_from_name_value::~Abstract_boolean_writestate_from_name_value() {}

    Class_boolean_writestate_from_name_value::Class_boolean_writestate_from_name_value() : Abstract_boolean_writestate_from_name_value::Abstract_boolean_writestate_from_name_value() {
      vx_core::refcount += 1;
    }

    Class_boolean_writestate_from_name_value::~Class_boolean_writestate_from_name_value() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_boolean_writestate_from_name_value::vx_new(vx_core::vx_Type_listany vals) const {
      vx_state::Func_boolean_writestate_from_name_value output = vx_state::e_boolean_writestate_from_name_value;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_boolean_writestate_from_name_value::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_state::Func_boolean_writestate_from_name_value output = vx_state::e_boolean_writestate_from_name_value;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_boolean_writestate_from_name_value::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/state", // pkgname
        "boolean-writestate<-name-value", // name
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

    vx_core::Type_constdef Class_boolean_writestate_from_name_value::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_boolean_writestate_from_name_value::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/state", // pkgname
        "boolean-writestate<-name-value", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_boolean_writestate_from_name_value::vx_empty() const {return vx_state::e_boolean_writestate_from_name_value;}
    vx_core::Type_any Class_boolean_writestate_from_name_value::vx_type() const {return vx_state::t_boolean_writestate_from_name_value;}
    vx_core::Type_msgblock Class_boolean_writestate_from_name_value::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_writestate_from_name_value::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_boolean_writestate_from_name_value::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string name = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_state::f_boolean_writestate_from_name_value(context, name, value);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func boolean-writestate<-statelistener)
  vx_core::Type_boolean f_boolean_writestate_from_statelistener(vx_core::Type_context context, vx_core::Type_statelistener statelistener) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve(statelistener);
    output = vx_core::f_let(
      vx_core::t_boolean,
      vx_core::t_any_from_func->vx_fn_new({context, statelistener}, [context, statelistener]() {
        vx_core::Type_statelistenermap statelistenermap = vx_state::f_statelistenermap_readstate(context);
        vx_core::vx_ref_plus(statelistenermap);
        vx_core::Type_string name = statelistener->name();
        vx_core::vx_ref_plus(name);
        vx_core::Type_boolean output_1 = vx_core::f_boolean_write_from_map_name_value(statelistenermap, name, statelistener);
        vx_core::vx_release_one_except({statelistenermap, name}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(statelistener, output);
    return output;
  }
  /**
   * @function boolean_writestate_from_statelistener
   * Writes statelistener into state
   * @param  {statelistener} statelistener
   * @return {boolean}
   * (func boolean-writestate<-statelistener)
   */
  // (func boolean-writestate<-statelistener)
  // class Class_boolean_writestate_from_statelistener {
    Abstract_boolean_writestate_from_statelistener::~Abstract_boolean_writestate_from_statelistener() {}

    Class_boolean_writestate_from_statelistener::Class_boolean_writestate_from_statelistener() : Abstract_boolean_writestate_from_statelistener::Abstract_boolean_writestate_from_statelistener() {
      vx_core::refcount += 1;
    }

    Class_boolean_writestate_from_statelistener::~Class_boolean_writestate_from_statelistener() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_boolean_writestate_from_statelistener::vx_new(vx_core::vx_Type_listany vals) const {
      vx_state::Func_boolean_writestate_from_statelistener output = vx_state::e_boolean_writestate_from_statelistener;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_boolean_writestate_from_statelistener::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_state::Func_boolean_writestate_from_statelistener output = vx_state::e_boolean_writestate_from_statelistener;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_boolean_writestate_from_statelistener::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/state", // pkgname
        "boolean-writestate<-statelistener", // name
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

    vx_core::Type_constdef Class_boolean_writestate_from_statelistener::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_boolean_writestate_from_statelistener::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/state", // pkgname
        "boolean-writestate<-statelistener", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_boolean_writestate_from_statelistener::vx_empty() const {return vx_state::e_boolean_writestate_from_statelistener;}
    vx_core::Type_any Class_boolean_writestate_from_statelistener::vx_type() const {return vx_state::t_boolean_writestate_from_statelistener;}
    vx_core::Type_msgblock Class_boolean_writestate_from_statelistener::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_writestate_from_statelistener::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_boolean_writestate_from_statelistener::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_boolean_writestate_from_statelistener::vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_statelistener inputval = vx_core::vx_any_from_any(vx_core::t_statelistener, val);
      output = vx_state::f_boolean_writestate_from_statelistener(context, inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_boolean_writestate_from_statelistener::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_statelistener statelistener = vx_core::vx_any_from_any(vx_core::t_statelistener, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_state::f_boolean_writestate_from_statelistener(context, statelistener);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func change)
  vx_core::Type_boolean f_change(vx_state::Type_valuemap valuemap) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve(valuemap);
    vx_core::vx_release_one_except(valuemap, output);
    return output;
  }
  /**
   * @function change
   * Changes the current state
   * @param  {valuemap} valuemap
   * @return {boolean}
   * (func change)
   */
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

    vx_core::Type_constdef Class_change::vx_constdef() const {return this->vx_p_constdef;}

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
      vx_state::Type_valuemap inputval = vx_core::vx_any_from_any(vx_state::t_valuemap, val);
      output = vx_state::f_change(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_change::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_state::Type_valuemap valuemap = vx_core::vx_any_from_any(vx_state::t_valuemap, arglist->vx_get_any(vx_core::vx_new_int(0)));
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
  /**
   * @function register
   * @param  {statelistener} listener
   * @return {boolean}
   * (func register)
   */
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

    vx_core::Type_constdef Class_register::vx_constdef() const {return this->vx_p_constdef;}

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

  // (func state<-context)
  vx_core::Type_state f_state_from_context(vx_core::Type_context context) {
    vx_core::Type_state output = vx_core::e_state;
    output = context->state();
    return output;
  }
  /**
   * @function state_from_context
   * Returns the full current state
   * @return {state}
   * (func state<-context)
   */
  // (func state<-context)
  // class Class_state_from_context {
    Abstract_state_from_context::~Abstract_state_from_context() {}

    Class_state_from_context::Class_state_from_context() : Abstract_state_from_context::Abstract_state_from_context() {
      vx_core::refcount += 1;
    }

    Class_state_from_context::~Class_state_from_context() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_state_from_context::vx_new(vx_core::vx_Type_listany vals) const {
      vx_state::Func_state_from_context output = vx_state::e_state_from_context;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_state_from_context::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_state::Func_state_from_context output = vx_state::e_state_from_context;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_state_from_context::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/state", // pkgname
        "state<-context", // name
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

    vx_core::Type_constdef Class_state_from_context::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_state_from_context::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/state", // pkgname
        "state<-context", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_state_from_context::vx_empty() const {return vx_state::e_state_from_context;}
    vx_core::Type_any Class_state_from_context::vx_type() const {return vx_state::t_state_from_context;}
    vx_core::Type_msgblock Class_state_from_context::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_state_from_context::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_state_from_context::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_state::f_state_from_context(context);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func statelistener-readstate<-name)
  vx_core::Type_statelistener f_statelistener_readstate_from_name(vx_core::Type_context context, vx_core::Type_string name) {
    vx_core::Type_statelistener output = vx_core::e_statelistener;
    vx_core::vx_reserve(name);
    output = vx_core::f_let(
      vx_core::t_statelistener,
      vx_core::t_any_from_func->vx_fn_new({context, name}, [context, name]() {
        vx_core::Type_statelistenermap statelistenermap = vx_state::f_statelistenermap_readstate(context);
        vx_core::vx_ref_plus(statelistenermap);
        vx_core::Type_statelistener output_1 = vx_core::f_any_from_map(vx_core::t_statelistener, statelistenermap, name);
        vx_core::vx_release_one_except(statelistenermap, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(name, output);
    return output;
  }
  /**
   * @function statelistener_readstate_from_name
   * Returns the named statelistener
   * @param  {string} name
   * @return {statelistener}
   * (func statelistener-readstate<-name)
   */
  // (func statelistener-readstate<-name)
  // class Class_statelistener_readstate_from_name {
    Abstract_statelistener_readstate_from_name::~Abstract_statelistener_readstate_from_name() {}

    Class_statelistener_readstate_from_name::Class_statelistener_readstate_from_name() : Abstract_statelistener_readstate_from_name::Abstract_statelistener_readstate_from_name() {
      vx_core::refcount += 1;
    }

    Class_statelistener_readstate_from_name::~Class_statelistener_readstate_from_name() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_statelistener_readstate_from_name::vx_new(vx_core::vx_Type_listany vals) const {
      vx_state::Func_statelistener_readstate_from_name output = vx_state::e_statelistener_readstate_from_name;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_statelistener_readstate_from_name::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_state::Func_statelistener_readstate_from_name output = vx_state::e_statelistener_readstate_from_name;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_statelistener_readstate_from_name::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/state", // pkgname
        "statelistener-readstate<-name", // name
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

    vx_core::Type_constdef Class_statelistener_readstate_from_name::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_statelistener_readstate_from_name::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/state", // pkgname
        "statelistener-readstate<-name", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_statelistener_readstate_from_name::vx_empty() const {return vx_state::e_statelistener_readstate_from_name;}
    vx_core::Type_any Class_statelistener_readstate_from_name::vx_type() const {return vx_state::t_statelistener_readstate_from_name;}
    vx_core::Type_msgblock Class_statelistener_readstate_from_name::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_statelistener_readstate_from_name::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_statelistener_readstate_from_name::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_statelistener_readstate_from_name::vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      output = vx_state::f_statelistener_readstate_from_name(context, inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_statelistener_readstate_from_name::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string name = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_state::f_statelistener_readstate_from_name(context, name);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func statelistenermap-readstate)
  vx_core::Type_statelistenermap f_statelistenermap_readstate(vx_core::Type_context context) {
    vx_core::Type_statelistenermap output = vx_core::e_statelistenermap;
    output = vx_core::f_let(
      vx_core::t_statelistenermap,
      vx_core::t_any_from_func->vx_fn_new({context}, [context]() {
        vx_core::Type_state state = vx_state::f_state_from_context(context);
        vx_core::vx_ref_plus(state);
        vx_core::Type_statelistenermap output_1 = state->statelistenermap();
        vx_core::vx_release_one_except(state, output_1);
        return output_1;
      })
    );
    return output;
  }
  /**
   * @function statelistenermap_readstate
   * Returns the current state valuemap
   * @return {statelistenermap}
   * (func statelistenermap-readstate)
   */
  // (func statelistenermap-readstate)
  // class Class_statelistenermap_readstate {
    Abstract_statelistenermap_readstate::~Abstract_statelistenermap_readstate() {}

    Class_statelistenermap_readstate::Class_statelistenermap_readstate() : Abstract_statelistenermap_readstate::Abstract_statelistenermap_readstate() {
      vx_core::refcount += 1;
    }

    Class_statelistenermap_readstate::~Class_statelistenermap_readstate() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_statelistenermap_readstate::vx_new(vx_core::vx_Type_listany vals) const {
      vx_state::Func_statelistenermap_readstate output = vx_state::e_statelistenermap_readstate;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_statelistenermap_readstate::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_state::Func_statelistenermap_readstate output = vx_state::e_statelistenermap_readstate;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_statelistenermap_readstate::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/state", // pkgname
        "statelistenermap-readstate", // name
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

    vx_core::Type_constdef Class_statelistenermap_readstate::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_statelistenermap_readstate::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/state", // pkgname
        "statelistenermap-readstate", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_statelistenermap_readstate::vx_empty() const {return vx_state::e_statelistenermap_readstate;}
    vx_core::Type_any Class_statelistenermap_readstate::vx_type() const {return vx_state::t_statelistenermap_readstate;}
    vx_core::Type_msgblock Class_statelistenermap_readstate::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_statelistenermap_readstate::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_statelistenermap_readstate::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_state::f_statelistenermap_readstate(context);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func value-readstate<-name)
  vx_core::Type_any f_value_readstate_from_name(vx_core::Type_context context, vx_core::Type_string name) {
    vx_core::Type_any output = vx_core::e_any;
    vx_core::vx_reserve(name);
    output = vx_core::f_let(
      vx_core::t_any,
      vx_core::t_any_from_func->vx_fn_new({context, name}, [context, name]() {
        vx_core::Type_statelistener statelistener = vx_state::f_statelistener_readstate_from_name(context, name);
        vx_core::vx_ref_plus(statelistener);
        vx_core::Type_any output_1 = statelistener->value();
        vx_core::vx_release_one_except(statelistener, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(name, output);
    return output;
  }
  /**
   * @function value_readstate_from_name
   * Returns the named state value
   * @param  {string} name
   * @return {any}
   * (func value-readstate<-name)
   */
  // (func value-readstate<-name)
  // class Class_value_readstate_from_name {
    Abstract_value_readstate_from_name::~Abstract_value_readstate_from_name() {}

    Class_value_readstate_from_name::Class_value_readstate_from_name() : Abstract_value_readstate_from_name::Abstract_value_readstate_from_name() {
      vx_core::refcount += 1;
    }

    Class_value_readstate_from_name::~Class_value_readstate_from_name() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_value_readstate_from_name::vx_new(vx_core::vx_Type_listany vals) const {
      vx_state::Func_value_readstate_from_name output = vx_state::e_value_readstate_from_name;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_value_readstate_from_name::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_state::Func_value_readstate_from_name output = vx_state::e_value_readstate_from_name;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_value_readstate_from_name::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/state", // pkgname
        "value-readstate<-name", // name
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

    vx_core::Type_constdef Class_value_readstate_from_name::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_value_readstate_from_name::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/state", // pkgname
        "value-readstate<-name", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_value_readstate_from_name::vx_empty() const {return vx_state::e_value_readstate_from_name;}
    vx_core::Type_any Class_value_readstate_from_name::vx_type() const {return vx_state::t_value_readstate_from_name;}
    vx_core::Type_msgblock Class_value_readstate_from_name::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_value_readstate_from_name::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_value_readstate_from_name::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_value_readstate_from_name::vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      output = vx_state::f_value_readstate_from_name(context, inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_value_readstate_from_name::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string name = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_state::f_value_readstate_from_name(context, name);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func valuemap-readstate<-mapname)
  vx_state::Type_valuemap f_valuemap_readstate_from_mapname(vx_core::Type_context context, vx_core::Type_string mapname) {
    vx_state::Type_valuemap output = vx_state::e_valuemap;
    vx_core::vx_reserve(mapname);
    output = vx_core::f_let(
      vx_state::t_valuemap,
      vx_core::t_any_from_func->vx_fn_new({context, mapname}, [context, mapname]() {
        vx_core::Type_any value = vx_state::f_value_readstate_from_name(context, mapname);
        vx_core::vx_ref_plus(value);
        vx_state::Type_valuemap valmap = vx_core::f_any_from_any(vx_state::t_valuemap, value);
        vx_core::vx_ref_plus(valmap);
        vx_state::Type_valuemap output_1 = valmap;
        vx_core::vx_release_one_except({value, valmap}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(mapname, output);
    return output;
  }
  /**
   * @function valuemap_readstate_from_mapname
   * Returns the current state valuemap
   * @param  {string} mapname
   * @return {valuemap}
   * (func valuemap-readstate<-mapname)
   */
  // (func valuemap-readstate<-mapname)
  // class Class_valuemap_readstate_from_mapname {
    Abstract_valuemap_readstate_from_mapname::~Abstract_valuemap_readstate_from_mapname() {}

    Class_valuemap_readstate_from_mapname::Class_valuemap_readstate_from_mapname() : Abstract_valuemap_readstate_from_mapname::Abstract_valuemap_readstate_from_mapname() {
      vx_core::refcount += 1;
    }

    Class_valuemap_readstate_from_mapname::~Class_valuemap_readstate_from_mapname() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_valuemap_readstate_from_mapname::vx_new(vx_core::vx_Type_listany vals) const {
      vx_state::Func_valuemap_readstate_from_mapname output = vx_state::e_valuemap_readstate_from_mapname;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_valuemap_readstate_from_mapname::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_state::Func_valuemap_readstate_from_mapname output = vx_state::e_valuemap_readstate_from_mapname;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_valuemap_readstate_from_mapname::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/state", // pkgname
        "valuemap-readstate<-mapname", // name
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

    vx_core::Type_constdef Class_valuemap_readstate_from_mapname::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_valuemap_readstate_from_mapname::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/state", // pkgname
        "valuemap-readstate<-mapname", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_valuemap_readstate_from_mapname::vx_empty() const {return vx_state::e_valuemap_readstate_from_mapname;}
    vx_core::Type_any Class_valuemap_readstate_from_mapname::vx_type() const {return vx_state::t_valuemap_readstate_from_mapname;}
    vx_core::Type_msgblock Class_valuemap_readstate_from_mapname::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_valuemap_readstate_from_mapname::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_valuemap_readstate_from_mapname::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_valuemap_readstate_from_mapname::vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      output = vx_state::f_valuemap_readstate_from_mapname(context, inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_valuemap_readstate_from_mapname::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string mapname = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_state::f_valuemap_readstate_from_mapname(context, mapname);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_state::Type_valuemap e_valuemap = NULL;
  vx_state::Type_valuemap t_valuemap = NULL;
  vx_state::Func_any_readstate_from_mapname_name e_any_readstate_from_mapname_name = NULL;
  vx_state::Func_any_readstate_from_mapname_name t_any_readstate_from_mapname_name = NULL;
  vx_state::Func_any_readstate_from_name e_any_readstate_from_name = NULL;
  vx_state::Func_any_readstate_from_name t_any_readstate_from_name = NULL;
  vx_state::Func_boolean_writestate_from_mapname_name_value e_boolean_writestate_from_mapname_name_value = NULL;
  vx_state::Func_boolean_writestate_from_mapname_name_value t_boolean_writestate_from_mapname_name_value = NULL;
  vx_state::Func_boolean_writestate_from_name_value e_boolean_writestate_from_name_value = NULL;
  vx_state::Func_boolean_writestate_from_name_value t_boolean_writestate_from_name_value = NULL;
  vx_state::Func_boolean_writestate_from_statelistener e_boolean_writestate_from_statelistener = NULL;
  vx_state::Func_boolean_writestate_from_statelistener t_boolean_writestate_from_statelistener = NULL;
  vx_state::Func_change e_change = NULL;
  vx_state::Func_change t_change = NULL;
  vx_state::Func_register e_register = NULL;
  vx_state::Func_register t_register = NULL;
  vx_state::Func_state_from_context e_state_from_context = NULL;
  vx_state::Func_state_from_context t_state_from_context = NULL;
  vx_state::Func_statelistener_readstate_from_name e_statelistener_readstate_from_name = NULL;
  vx_state::Func_statelistener_readstate_from_name t_statelistener_readstate_from_name = NULL;
  vx_state::Func_statelistenermap_readstate e_statelistenermap_readstate = NULL;
  vx_state::Func_statelistenermap_readstate t_statelistenermap_readstate = NULL;
  vx_state::Func_value_readstate_from_name e_value_readstate_from_name = NULL;
  vx_state::Func_value_readstate_from_name t_value_readstate_from_name = NULL;
  vx_state::Func_valuemap_readstate_from_mapname e_valuemap_readstate_from_mapname = NULL;
  vx_state::Func_valuemap_readstate_from_mapname t_valuemap_readstate_from_mapname = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_state::e_valuemap = new Class_valuemap();
      vx_core::vx_reserve_empty(vx_state::e_valuemap);
      vx_state::t_valuemap = new Class_valuemap();
      vx_core::vx_reserve_type(vx_state::t_valuemap);
      vx_state::e_any_readstate_from_mapname_name = new vx_state::Class_any_readstate_from_mapname_name();
      vx_core::vx_reserve_empty(vx_state::e_any_readstate_from_mapname_name);
      vx_state::t_any_readstate_from_mapname_name = new vx_state::Class_any_readstate_from_mapname_name();
      vx_core::vx_reserve_type(vx_state::t_any_readstate_from_mapname_name);
      vx_state::e_any_readstate_from_name = new vx_state::Class_any_readstate_from_name();
      vx_core::vx_reserve_empty(vx_state::e_any_readstate_from_name);
      vx_state::t_any_readstate_from_name = new vx_state::Class_any_readstate_from_name();
      vx_core::vx_reserve_type(vx_state::t_any_readstate_from_name);
      vx_state::e_boolean_writestate_from_mapname_name_value = new vx_state::Class_boolean_writestate_from_mapname_name_value();
      vx_core::vx_reserve_empty(vx_state::e_boolean_writestate_from_mapname_name_value);
      vx_state::t_boolean_writestate_from_mapname_name_value = new vx_state::Class_boolean_writestate_from_mapname_name_value();
      vx_core::vx_reserve_type(vx_state::t_boolean_writestate_from_mapname_name_value);
      vx_state::e_boolean_writestate_from_name_value = new vx_state::Class_boolean_writestate_from_name_value();
      vx_core::vx_reserve_empty(vx_state::e_boolean_writestate_from_name_value);
      vx_state::t_boolean_writestate_from_name_value = new vx_state::Class_boolean_writestate_from_name_value();
      vx_core::vx_reserve_type(vx_state::t_boolean_writestate_from_name_value);
      vx_state::e_boolean_writestate_from_statelistener = new vx_state::Class_boolean_writestate_from_statelistener();
      vx_core::vx_reserve_empty(vx_state::e_boolean_writestate_from_statelistener);
      vx_state::t_boolean_writestate_from_statelistener = new vx_state::Class_boolean_writestate_from_statelistener();
      vx_core::vx_reserve_type(vx_state::t_boolean_writestate_from_statelistener);
      vx_state::e_change = new vx_state::Class_change();
      vx_core::vx_reserve_empty(vx_state::e_change);
      vx_state::t_change = new vx_state::Class_change();
      vx_core::vx_reserve_type(vx_state::t_change);
      vx_state::e_register = new vx_state::Class_register();
      vx_core::vx_reserve_empty(vx_state::e_register);
      vx_state::t_register = new vx_state::Class_register();
      vx_core::vx_reserve_type(vx_state::t_register);
      vx_state::e_state_from_context = new vx_state::Class_state_from_context();
      vx_core::vx_reserve_empty(vx_state::e_state_from_context);
      vx_state::t_state_from_context = new vx_state::Class_state_from_context();
      vx_core::vx_reserve_type(vx_state::t_state_from_context);
      vx_state::e_statelistener_readstate_from_name = new vx_state::Class_statelistener_readstate_from_name();
      vx_core::vx_reserve_empty(vx_state::e_statelistener_readstate_from_name);
      vx_state::t_statelistener_readstate_from_name = new vx_state::Class_statelistener_readstate_from_name();
      vx_core::vx_reserve_type(vx_state::t_statelistener_readstate_from_name);
      vx_state::e_statelistenermap_readstate = new vx_state::Class_statelistenermap_readstate();
      vx_core::vx_reserve_empty(vx_state::e_statelistenermap_readstate);
      vx_state::t_statelistenermap_readstate = new vx_state::Class_statelistenermap_readstate();
      vx_core::vx_reserve_type(vx_state::t_statelistenermap_readstate);
      vx_state::e_value_readstate_from_name = new vx_state::Class_value_readstate_from_name();
      vx_core::vx_reserve_empty(vx_state::e_value_readstate_from_name);
      vx_state::t_value_readstate_from_name = new vx_state::Class_value_readstate_from_name();
      vx_core::vx_reserve_type(vx_state::t_value_readstate_from_name);
      vx_state::e_valuemap_readstate_from_mapname = new vx_state::Class_valuemap_readstate_from_mapname();
      vx_core::vx_reserve_empty(vx_state::e_valuemap_readstate_from_mapname);
      vx_state::t_valuemap_readstate_from_mapname = new vx_state::Class_valuemap_readstate_from_mapname();
      vx_core::vx_reserve_type(vx_state::t_valuemap_readstate_from_mapname);
      vx_core::vx_Type_mapany maptype;
      vx_core::vx_Type_mapany mapconst;
      vx_core::vx_Type_mapfunc mapfunc;
      vx_core::vx_Type_mapany mapempty;
      maptype["valuemap"] = vx_state::t_valuemap;
      mapfunc["any-readstate<-mapname-name"] = vx_state::t_any_readstate_from_mapname_name;
      mapfunc["any-readstate<-name"] = vx_state::t_any_readstate_from_name;
      mapfunc["boolean-writestate<-mapname-name-value"] = vx_state::t_boolean_writestate_from_mapname_name_value;
      mapfunc["boolean-writestate<-name-value"] = vx_state::t_boolean_writestate_from_name_value;
      mapfunc["boolean-writestate<-statelistener"] = vx_state::t_boolean_writestate_from_statelistener;
      mapfunc["change"] = vx_state::t_change;
      mapfunc["register"] = vx_state::t_register;
      mapfunc["state<-context"] = vx_state::t_state_from_context;
      mapfunc["statelistener-readstate<-name"] = vx_state::t_statelistener_readstate_from_name;
      mapfunc["statelistenermap-readstate"] = vx_state::t_statelistenermap_readstate;
      mapfunc["value-readstate<-name"] = vx_state::t_value_readstate_from_name;
      mapfunc["valuemap-readstate<-mapname"] = vx_state::t_valuemap_readstate_from_mapname;
      vx_core::vx_global_package_set("vx/state", maptype, mapconst, mapfunc);
	   }
  // }

}
