#include <any>
#include <exception>
#include <functional>
#include <future>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>
#include "vx/core.hpp"

//namespace vx_core {// :body

  vx_core::vx_Type_listany vx_core::emptylistany;
  vx_core::vx_Type_mapany vx_core::emptymapany;

  // any_from_any(T, U)
  template <class T, class U> std::shared_ptr<T> vx_core::any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
    T tvalue = dynamic_cast<T>(&value);
    std::shared_ptr<T> output = std::make_shared<T>(tvalue);
    return output;
  }

  // any_from_map(T, key, defaultval)
  template <class T> std::shared_ptr<T> vx_core::any_from_map(const std::map<std::string, std::shared_ptr<T>> &map, const std::string key, const std::shared_ptr<T> defaultval) {
    std::shared_ptr<T> output = defaultval;
    vx_core::vx_Type_mapany::const_iterator iter = map.find(key);
    if (iter != map.end()) {
      output = it->second;
    }
    return output;
  }

  // async_await(T, async<T>)
  template <class T> static std::shared_ptr<T> vx_core::async_await(std::shared_ptr<T> generic_any_1, std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> async) {
    std::shared_future<T> futureT = async->future;
    std::shared_ptr<vx_core::Async<vx_core::Type_any>> async_parent = async->async_parent;
    T valueT;
    if (async_parent == NULL) {
      valueT = futureT.await();
    } else {
      vx_core::Type_any parentval = vx_core::async_await(T generic_any_1, std::Async<vx_core::Type_any> async_parent);
      std::function<T(vx_core::Type_any) fn = async->fn;
      valueT = fn(parentval);
    }
    std::shared_ptr<T> output = std::make_shared<T>(valueT);
    return output;
  }

  // async_from_async(T, async<U>)
  template <class T, class U> static std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_core::async_from_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<vx_core::Async<std::shared_ptr<U>>> async) {
    std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> output = vx_core::async_new_from_val(vx_core::f_empty(generic_any_1));
    return output;
  }

  // async_from_async_fn(T, async<U>, fn<T>(U))
  template <class T, class U> static std::shared_ptr<vx_core::Async<T>> vx_core::async_from_async_fn(T generic_any_1, std::shared_ptr<vx_core::Async<U>> async, std::function<T(U)> fn) {
    std::shared_ptr<vx_core::Async<T>> futureT = this;
    std::shared_ptr<vx_core::Async<U>> output = std::make_shared(vx_core::Async<T>);
    output->future = futureU;
    output->async_parent = async;
    output->fn = fn;
    return output;
  }

  // async_new_from_val(T)
  template <class T> static std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_core::async_new_from_val(std::shared_ptr<T> val) {
    std::promise<T> promise;
    promise.set_value(val);
    std::shared_ptr<vx_core::Async<std:shared_ptr<T>>> output = std::make_shared(promise.get_future());
    return output;
  }

  // boolean_contains_from_set_val(set<T>, val)
  template <class T> bool vx_core::boolean_contains_from_set_val(std::set<T> set, T val) {
    const bool output = container.find(element) != container.end();
    return output;
  }

  // keyset_from_map(map)
  template <class T> std::set<T> vx_core::keyset_from_map(std::map<std::string, T> map) {
    std::set<T> output;
    for (std::map<std::string, T>::iterator it = map.begin(); it != map.end(); ++it) {
      output.push_back(it->first);
    }
    return output;
  }

  // list_from_list(T, list<U>)
  template <class T, class U> std::vector<std::shared_ptr<T>> vx_core::list_from_list(std::shared_ptr<T> generic_any_1, std::vector<std::shared_ptr<U>> list) {
    std::vector<T*> output = reinterpret_cast<std::vector<T*>&>(list);
    return output;
  }

  // listaddall(list, listadd)
  template <class T> std::vector<std::shared_ptr<T>> vx_core::listaddall(std::vector<std::shared_ptr<T>> list, std::vector<std::shared_ptr<T>> listadd) {
    list.insert(list.end(), listadd.begin(), listadd.end());
  }

  // map_from_map(T, map<U>)
  template <class T, class U> std::map<std::string, std::shared_ptr<T>> vx_core::map_from_map(std::shared_ptr<T> generic_any_1, std::map<std::string, std::shared_ptr<U>> map) {
  }

  // string_from_any(val)
  std::string vx_core::string_from_any(std::any) {
    std::string output = "";
    return output;
  }

  // sync_from_async(generic_any_1, async)
  template <class T> std::shared_ptr<T> vx_core::sync_from_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<Async<std::shared_ptr<T>>> async) {
    future = async->future;
    T valuet = future->wait();
    std::shared_ptr<T> output = std::make_shared<T>(valuet);
    return output;
  }

  //class Class_replfunc {
    vx_core::Type_any vx_core::Class_replfunc::vx_repl(vx_core::Type_anylist arglist) {return vx_core::t_any;}
  //};

  //class Class_replfunc_async {
    std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_core::Class_replfunc_async::vx_repl(vx_core::Type_anylist arglist) {
      return vx_core::async_new_from_val(vx_core::t_any);
    }
  //};

  //class Type_any {

    vx_core::Type_any vx_core::Class_any::vx_type_from_any(vx_core::Type_any val) {
      return val->vx_type(val);
    }

    vx_core::vx_Type_listany vx_core::Class_any::vx_dispose() {
      this->vx_iref = 0;
      return vx_core::emptylistany;
    }

    bool vx_core::Class_any::vx_release() {
      bool output = false;
      if (this->vx_iref < 0) {
      } else if (vx_iref == 0) {
        vx_iref = -1;
        output = true;
      } else {
        vx_iref -= 1;
      }
      return output;
    }

    void vx_core::Class_any::vx_reserve() {this->vx_iref += 1;}

  //};

  //class Type_boolean {

    bool vx_core::Class_boolean::vx_boolean() {return this->vx_p_boolean;}

    vx_core::Type_boolean vx_core::Class_boolean::vx_new_from_boolean(bool isval) {
      vx_core::Type_boolean output = vx_core::c_false;
      if (isval) {
        output = vx_core::c_true;
      }
      return output;
    }

  //};

  //class Type_constdef {
    vx_core::Type_constdef vx_core::Class_constdef::vx_constdef_new(
      std::string pkgname,
      std::string name,
      vx_core::Type_typedef typ
    ) {
      vx_core::Type_constdef output = std::make_shared<Class_constdef>();
      output->vx_p_pkgname = vx_core::t_string->vx_new_from_string(pkgname);
      output->vx_p_name = vx_core::t_string->vx_new_from_string(name);
      output->vx_p_type = typ;
      return output;
    }
  //};

  //class Type_float {
    float vx_core::Class_float::vx_float() {return vx_p_float;}

    vx_core::Type_float vx_core::Class_float::vx_new_from_float(float fval) {
      vx_core::Type_float output = std::make_shared<vx_core::Class_float>();
      output->vx_p_float = fval;
      return output;
    }
  //};

  //class Type_funcdef {
    vx_core::Type_funcdef vx_core::Class_funcdef::vx_funcdef_new(
      std::string pkgname,
      std::string name,
      int idx,
      bool async,
      vx_core::Type_any typ
    ) {
      vx_core::Type_funcdef output = std::make_shared<vx_core::Class_funcdef>();
      output->vx_p_pkgname = vx_core::t_string->vx_new_from_string(pkgname);
      output->vx_p_name = vx_core::t_string->vx_new_from_string(name);
      output->vx_p_idx = vx_core::t_int->vx_new_from_int(idx);
      output->vx_p_async = vx_core::t_boolean->vx_new_from_boolean(async);
      output->vx_p_type = typ;
      return output;
    }
  //};

  //class Type_int {
    int vx_core::Class_int::vx_int() {return vx_p_int;}

    vx_core::Type_int vx_core::Class_int::vx_new_from_int(int ival) {
      vx_core::Type_int output = std::make_shared<vx_core::Class_int>();
      output->vx_p_int = ival;
      return output;
    }
  //};

  //class Type_string {
    std::string vx_core::Class_string::vx_string() {
      return vx_p_string;
    }

    vx_core::Type_string vx_core::Class_string::vx_new_from_string(std::string text) {
      vx_core::Type_string output;
      if (text == "" && vx_core::e_string != NULL) {
        output = vx_core::e_string;
      } else {
        output = std::make_shared<vx_core::Class_string>();
        output->vx_p_string = text;
      }
      return output;
    }
  //};

  //class Type_typedef {
    vx_core::Type_typedef vx_core::Class_typedef::vx_typedef_new(
      std::string pkgname,
      std::string name,
      std::string extend,
      vx_core::Type_typelist traits,
      vx_core::Type_typelist allowtypes,
      vx_core::Type_typelist disallowtypes,
      vx_core::Type_funclist allowfuncs,
      vx_core::Type_funclist disallowfuncs,
      vx_core::Type_anylist allowvalues,
      vx_core::Type_anylist disallowvalues,
      vx_core::Type_argmap properties
    ) {
      vx_core::Type_typedef output = std::make_shared<vx_core::Class_typedef>();
      output->vx_p_pkgname = vx_core::t_string->vx_new_from_string(pkgname);
      output->vx_p_name = vx_core::t_string->vx_new_from_string(name);
      output->vx_p_extend = vx_core::t_string->vx_new_from_string(extend);
      output->vx_p_traits = traits;
      output->vx_p_allowtypes = allowtypes;
      output->vx_p_disallowtypes = disallowtypes;
      output->vx_p_allowfuncs = disallowfuncs;
      output->vx_p_disallowfuncs = disallowfuncs;
      output->vx_p_allowvalues = disallowvalues;
      output->vx_p_disallowvalues = disallowvalues;
      output->vx_p_properties = properties;
      return output;
    }

  //}


  /**
   * type: any
   * Any Value for Variant Type
   * (type any)
   */
  //class Type_any {
    template <class T> std::shared_ptr<T> vx_core::Class_any::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_any->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_any::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_any output;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        }
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any::vx_empty(std::shared_ptr<T> val) {return vx_core::e_any;}
    template <class T> std::shared_ptr<T> vx_core::Class_any::vx_type(std::shared_ptr<T> val) {return vx_core::t_any;}

    vx_core::Type_typedef vx_core::Class_any::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any", // name
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

    vx_core::Type_any vx_core::e_any = std::make_shared<vx_core::Class_any>();
    vx_core::Type_any vx_core::t_any = std::make_shared<vx_core::Class_any>();
  //}

  /**
   * type: list
   * A simple untyped list.
   * (type list)
   */
  //class Type_list {
    vx_core::vx_Type_listany vx_core::Class_list::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_core::Type_any vx_core::Class_list::vx_any(vx_core::Type_int index) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Class_list* list = this;
      int iindex = index->vx_int();
      std::vector<vx_core::Type_any> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_list::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_list->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_list::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_list output;
      vx_core::Class_list* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_core::Type_any> listval = val->vx_list();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_any) {
          listval->push_back(vx_core::any_from_any(vx_core::t_any, valsub));
        } else if (valsubtype == vx_core::t_list) {
          vx_core::Type_list multi = vx_core::any_from_any(vx_core::t_list, valsub);
          listval = vx_core::listaddall(listval, multi->vx_list());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new list) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_list::vx_empty(std::shared_ptr<T> val) {return vx_core::e_list;}
    template <class T> std::shared_ptr<T> vx_core::Class_list::vx_type(std::shared_ptr<T> val) {return vx_core::t_list;}

    vx_core::Type_typedef vx_core::Class_list::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "list", // name
        ":list", // extends
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

    vx_core::Type_list vx_core::e_list = std::make_shared<vx_core::Class_list>();
    vx_core::Type_list vx_core::t_list = std::make_shared<vx_core::Class_list>();
  //}

  /**
   * type: map
   * A simple untyped map.
   * (type map)
   */
  //class Type_map {
    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_map::vx_map() {
      return vx_core::map_from_map(vx_core::t_any, this->vx_p_map);
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_map::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Class_map* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_any> mapval = map->vx_p_map;
      output = vx_core::any_from_map(mapval, skey, vx_core::e_any);
      return output;
    }

    // vx_new_from_map(mapval)
    template <class T> std::shared_ptr<T>  vx_core::Class_map::vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval) {
      vx_core::Type_map output;
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
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(map) Invalid Value: " + vx_core::string_from_any(val) + "");
          msgblock = vx_core::t_msgblock->vx_copy(vx_core::t_msgblock, {msgblock, msg});
        }
      }
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_map::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_map->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_map::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_map output;
      vx_core::Class_map* valmap = this;
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

    template <class T> std::shared_ptr<T> vx_core::Class_map::vx_empty(std::shared_ptr<T> val) {return vx_core::e_map;}
    template <class T> std::shared_ptr<T> vx_core::Class_map::vx_type(std::shared_ptr<T> val) {return vx_core::t_map;}

    vx_core::Type_typedef vx_core::Class_map::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "map", // name
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

    vx_core::Type_map vx_core::e_map = std::make_shared<vx_core::Class_map>();
    vx_core::Type_map vx_core::t_map = std::make_shared<vx_core::Class_map>();
  //}

  /**
   * type: struct
   * Struct is the type of all structures/objects with properties.
   * (type struct)
   */
  //class Type_struct {
    // vx_any(key)
    vx_core::Type_any vx_core::Class_struct::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_struct::vx_map() {
      vx_core::vx_Type_mapany output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_struct::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_struct->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_struct::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_struct output;
      vx_core::Class_struct* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_struct::vx_empty(std::shared_ptr<T> val) {return vx_core::e_struct;}
    template <class T> std::shared_ptr<T> vx_core::Class_struct::vx_type(std::shared_ptr<T> val) {return vx_core::t_struct;}

    vx_core::Type_typedef vx_core::Class_struct::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "struct", // name
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

    vx_core::Type_struct vx_core::e_struct = std::make_shared<vx_core::Class_struct>();
    vx_core::Type_struct vx_core::t_struct = std::make_shared<vx_core::Class_struct>();
  //}

  /**
   * type: boolean
   * (type boolean)
   */
  //class Type_boolean {
    template <class T> std::shared_ptr<T> vx_core::Class_boolean::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_boolean->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_boolean::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_boolean output;
      vx_core::Class_boolean* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_boolean = val->vx_boolean();
      bool booleanval = false;
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_boolean) {
          vx_core::Type_boolean valboolean = vx_core::any_from_any(vx_core::t_boolean, valsub);
          booleanval = booleanval || valboolean->vx_boolean();
        }
      }
      output->vx_p_boolean = booleanval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_boolean::vx_empty(std::shared_ptr<T> val) {return vx_core::e_boolean;}
    template <class T> std::shared_ptr<T> vx_core::Class_boolean::vx_type(std::shared_ptr<T> val) {return vx_core::t_boolean;}

    vx_core::Type_typedef vx_core::Class_boolean::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
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
      );
    }

    vx_core::Type_boolean vx_core::e_boolean = std::make_shared<vx_core::Class_boolean>();
    vx_core::Type_boolean vx_core::t_boolean = std::make_shared<vx_core::Class_boolean>();
  //}

  /**
   * type: number
   * A generic number that could be int, float, or decimal.
   * (type number)
   */
  //class Type_number {
    template <class T> std::shared_ptr<T> vx_core::Class_number::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_number->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_number::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_number output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_number::vx_empty(std::shared_ptr<T> val) {return vx_core::e_number;}
    template <class T> std::shared_ptr<T> vx_core::Class_number::vx_type(std::shared_ptr<T> val) {return vx_core::t_number;}

    vx_core::Type_typedef vx_core::Class_number::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "number", // name
        "", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_int, vx_core::t_float, vx_core::t_decimal}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_number vx_core::e_number = std::make_shared<vx_core::Class_number>();
    vx_core::Type_number vx_core::t_number = std::make_shared<vx_core::Class_number>();
  //}

  /**
   * type: decimal
   * A clean version of float like Java BigDecimal.
   * (type decimal)
   */
  //class Type_decimal {
    template <class T> std::shared_ptr<T> vx_core::Class_decimal::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_decimal->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_decimal::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_decimal output;
      vx_core::Class_decimal* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_decimal = val->vx_string();
      std::string sval = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_string) {
          vx_core::Type_string valstring = vx_core::any_from_any(vx_core::t_string, valsub);
          sval = valstring->vx_string();
        }
      }
      output->vx_p_decimal = sval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_decimal::vx_empty(std::shared_ptr<T> val) {return vx_core::e_decimal;}
    template <class T> std::shared_ptr<T> vx_core::Class_decimal::vx_type(std::shared_ptr<T> val) {return vx_core::t_decimal;}

    vx_core::Type_typedef vx_core::Class_decimal::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "decimal", // name
        "", // extends
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_decimal vx_core::e_decimal = std::make_shared<vx_core::Class_decimal>();
    vx_core::Type_decimal vx_core::t_decimal = std::make_shared<vx_core::Class_decimal>();
  //}

  /**
   * type: float
   * (type float)
   */
  //class Type_float {
    template <class T> std::shared_ptr<T> vx_core::Class_float::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_float->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_float::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_float output;
      vx_core::Class_float* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_float = val->vx_float();
      float floatval = 0;
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_decimal) {
          vx_core::Type_decimal valnum = vx_core::any_from_any(vx_core::t_decimal, valsub);
          floatval += valnum->vx_float();
        } else if (valsubtype == vx_core::t_float) {
          vx_core::Type_float valnum = vx_core::any_from_any(vx_core::t_float, valsub);
          floatval += valnum->vx_float();
        } else if (valsubtype == vx_core::t_int) {
          vx_core::Type_int valnum = vx_core::any_from_any(vx_core::t_int, valsub);
          floatval += valnum->vx_int();
        } else if (valsubtype == vx_core::t_string) {
          vx_core::Type_string valstring = vx_core::any_from_any(vx_core::t_string, valsub);
          floatval += std::stof(valstring->vx_string());
        }
      }
      output->vx_p_float = floatval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_float::vx_empty(std::shared_ptr<T> val) {return vx_core::e_float;}
    template <class T> std::shared_ptr<T> vx_core::Class_float::vx_type(std::shared_ptr<T> val) {return vx_core::t_float;}

    vx_core::Type_typedef vx_core::Class_float::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "float", // name
        "", // extends
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_float vx_core::e_float = std::make_shared<vx_core::Class_float>();
    vx_core::Type_float vx_core::t_float = std::make_shared<vx_core::Class_float>();
  //}

  /**
   * type: int
   * (type int)
   */
  //class Type_int {
    template <class T> std::shared_ptr<T> vx_core::Class_int::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_int->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_int::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_int output;
      vx_core::Class_int val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_int = val->vx_int();
      int intval = 0;
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_int) {
          vx_core::Type_int valnum = vx_core::any_from_any(vx_core::t_int, valsub);
          intval += valnum->vx_int();
        }
      }
      output->vx_p_int = intval;
      if (msgblock != vx_core::t_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_int::vx_empty(std::shared_ptr<T> val) {return vx_core::e_int;}
    template <class T> std::shared_ptr<T> vx_core::Class_int::vx_type(std::shared_ptr<T> val) {return vx_core::t_int;}

    vx_core::Type_typedef vx_core::Class_int::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "int", // name
        "", // extends
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_int vx_core::e_int = std::make_shared<vx_core::Class_int>();
    vx_core::Type_int vx_core::t_int = std::make_shared<vx_core::Class_int>();
  //}

  /**
   * type: string
   * (type string)
   */
  //class Type_string {
    template <class T> std::shared_ptr<T> vx_core::Class_string::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_string->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_string::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_string output;
      vx_core::Class_string val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_string = val->vx_string();
      std::string sb = output->vx_string();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_string) {
          vx_core::Type_string valstring = vx_core::any_from_any(vx_core::t_string, valsub);
          sb += valstring->vx_string();
        } else if (valsubtype == vx_core::t_int) {
          vx_core::Type_int valint = vx_core::any_from_any(vx_core::t_int, valsub);
          sb += valint->vx_int();
        } else if (valsubtype == vx_core::t_float) {
          vx_core::Type_float valfloat = vx_core::any_from_any(vx_core::t_float, valsub);
          sb += valfloat->vx_float();
        } else if (valsubtype == vx_core::t_decimal) {
          vx_core::Type_decimal valdecimal = vx_core::any_from_any(vx_core::t_decimal, valsub);
          sb += valdecimal->vx_string();
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new string) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
        }
      }
      output->vx_p_string = sb;
      if (msgblock != vx_core::t_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_string::vx_empty(std::shared_ptr<T> val) {return vx_core::e_string;}
    template <class T> std::shared_ptr<T> vx_core::Class_string::vx_type(std::shared_ptr<T> val) {return vx_core::t_string;}

    vx_core::Type_typedef vx_core::Class_string::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "string", // name
        "string", // extends
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

    vx_core::Type_string vx_core::e_string = std::make_shared<vx_core::Class_string>();
    vx_core::Type_string vx_core::t_string = std::make_shared<vx_core::Class_string>();
  //}

  /**
   * type: func
   * Original Function Class.
   * (type func)
   */
  //class Type_func {
    vx_core::Type_funcdef vx_core::Class_func::vx_funcdef() {
      return vx_core::e_funcdef;
    }
    template <class T> std::shared_ptr<T> vx_core::Class_func::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_func->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_func::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_func output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_func::vx_empty(std::shared_ptr<T> val) {return vx_core::e_func;}
    template <class T> std::shared_ptr<T> vx_core::Class_func::vx_type(std::shared_ptr<T> val) {return vx_core::t_func;}

    vx_core::Type_typedef vx_core::Class_func::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "func", // name
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
    }

    vx_core::Type_func vx_core::e_func = std::make_shared<vx_core::Class_func>();
    vx_core::Type_func vx_core::t_func = std::make_shared<vx_core::Class_func>();
  //}

  /**
   * type: any-async<-func
   * A sync or async function that returns one value.
   * (type any-async<-func)
   */
  //class Type_any_async_from_func {
    template <class T> std::shared_ptr<T> vx_core::Class_any_async_from_func::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_any_async_from_func->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_any_async_from_func::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_any_async_from_func output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_async_from_func::vx_empty(std::shared_ptr<T> val) {return vx_core::e_any_async_from_func;}
    template <class T> std::shared_ptr<T> vx_core::Class_any_async_from_func::vx_type(std::shared_ptr<T> val) {return vx_core::t_any_async_from_func;}

    vx_core::Type_typedef vx_core::Class_any_async_from_func::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-async<-func", // name
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
    }

    vx_core::Type_any_async_from_func vx_core::e_any_async_from_func = std::make_shared<vx_core::Class_any_async_from_func>();
    vx_core::Type_any_async_from_func vx_core::t_any_async_from_func = std::make_shared<vx_core::Class_any_async_from_func>();
  //}

  /**
   * type: any<-anylist
   * List of Any
   * (type any<-anylist)
   */
  //class Type_any_from_anylist {
    vx_core::vx_Type_listany vx_core::Class_any_from_anylist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_core::Func_any_from_any vx_core::Class_any_from_anylist::vx_any_from_any(vx_core::Type_int index) {
      vx_core::Func_any_from_any output = vx_core::e_any_from_any;
      vx_core::Class_any_from_anylist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_core::Func_any_from_any> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Func_any_from_any> vx_core::Class_any_from_anylist::vx_listany_from_any() {return vx_p_list;}

    vx_core::Type_any vx_core::Class_any_from_anylist::vx_any(vx_core::Type_int index) {
      return this->vx_any_from_any(index);
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_anylist::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_any_from_anylist->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_any_from_anylist::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_any_from_anylist output;
      vx_core::Class_any_from_anylist* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_core::Func_any_from_any> listval = val->vx_listany_from_any();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_any_from_anylist) {
          vx_core::Type_any_from_anylist multi = vx_core::any_from_any(vx_core::t_any_from_anylist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listany_from_any());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new any<-anylist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_anylist::vx_empty(std::shared_ptr<T> val) {return vx_core::e_any_from_anylist;}
    template <class T> std::shared_ptr<T> vx_core::Class_any_from_anylist::vx_type(std::shared_ptr<T> val) {return vx_core::t_any_from_anylist;}

    vx_core::Type_typedef vx_core::Class_any_from_anylist::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any<-anylist", // name
        ":list", // extends
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

    vx_core::Type_any_from_anylist vx_core::e_any_from_anylist = std::make_shared<vx_core::Class_any_from_anylist>();
    vx_core::Type_any_from_anylist vx_core::t_any_from_anylist = std::make_shared<vx_core::Class_any_from_anylist>();
  //}

  /**
   * type: anylist
   * (type anylist)
   */
  //class Type_anylist {
    vx_core::vx_Type_listany vx_core::Class_anylist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_core::Type_any vx_core::Class_anylist::vx_any(vx_core::Type_int index) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Class_anylist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_core::Type_any> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_anylist::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_anylist->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_anylist::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_anylist output;
      vx_core::Class_anylist* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_core::Type_any> listval = val->vx_list();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_any) {
          listval->push_back(vx_core::any_from_any(vx_core::t_any, valsub));
        } else if (valsubtype == vx_core::t_anylist) {
          vx_core::Type_anylist multi = vx_core::any_from_any(vx_core::t_anylist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_list());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new anylist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_anylist::vx_empty(std::shared_ptr<T> val) {return vx_core::e_anylist;}
    template <class T> std::shared_ptr<T> vx_core::Class_anylist::vx_type(std::shared_ptr<T> val) {return vx_core::t_anylist;}

    vx_core::Type_typedef vx_core::Class_anylist::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "anylist", // name
        ":list", // extends
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

    vx_core::Type_anylist vx_core::e_anylist = std::make_shared<vx_core::Class_anylist>();
    vx_core::Type_anylist vx_core::t_anylist = std::make_shared<vx_core::Class_anylist>();
  //}

  /**
   * type: anytype
   * Any Type that allows any Type as a Value
   * (type anytype)
   */
  //class Type_anytype {
    template <class T> std::shared_ptr<T> vx_core::Class_anytype::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_anytype->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_anytype::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_anytype output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_anytype::vx_empty(std::shared_ptr<T> val) {return vx_core::e_anytype;}
    template <class T> std::shared_ptr<T> vx_core::Class_anytype::vx_type(std::shared_ptr<T> val) {return vx_core::t_anytype;}

    vx_core::Type_typedef vx_core::Class_anytype::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "anytype", // name
        ":type", // extends
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

    vx_core::Type_anytype vx_core::e_anytype = std::make_shared<vx_core::Class_anytype>();
    vx_core::Type_anytype vx_core::t_anytype = std::make_shared<vx_core::Class_anytype>();
  //}

  /**
   * type: arg
   * A function argument
   * (type arg)
   */
  //class Type_arg {
    // name()
    vx_core::Type_string vx_core::Class_arg::name() {
      vx_core::Type_string output = this->vx_p_name;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // argtype()
    vx_core::Type_type vx_core::Class_arg::argtype() {
      vx_core::Type_type output = this->vx_p_argtype;
      if (output == NULL) {
        output = vx_core::t_type;
      }
      return output;
    }

    // fn_any()
    vx_core::Func_any_from_func vx_core::Class_arg::fn_any() {
      vx_core::Func_any_from_func output = this->vx_p_fn_any;
      if (output == NULL) {
        output = vx_core::t_any_from_func;
      }
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_arg::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":argtype") {
        output = this->argtype();
      } else if (skey == ":fn-any") {
        output = this->fn_any();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_arg::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":name"] = this->name();
      output[":argtype"] = this->argtype();
      output[":fn-any"] = this->fn_any();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_arg::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_arg->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_arg::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_arg output;
      vx_core::Class_arg* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_name = val->name();
      output->vx_p_argtype = val->argtype();
      output->vx_p_fn_any = val->fn_any();
      std::set<std::string> validkeys;
      validkeys.insert(":name");
      validkeys.insert(":argtype");
      validkeys.insert(":fn-any");
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new arg) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_name = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new arg :name " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":argtype") {
            if (valsubtype == vx_core::t_type) {
              output->vx_p_argtype = vx_core::any_from_any(vx_core::t_type, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new arg :argtype " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":fn-any") {
            if (valsubtype == vx_core::t_any_from_func) {
              output->vx_p_fn_any = vx_core::any_from_any(vx_core::t_any_from_func, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new arg :fn-any " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new arg) - Invalid Key: " + key);
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

    template <class T> std::shared_ptr<T> vx_core::Class_arg::vx_empty(std::shared_ptr<T> val) {return vx_core::e_arg;}
    template <class T> std::shared_ptr<T> vx_core::Class_arg::vx_type(std::shared_ptr<T> val) {return vx_core::t_arg;}

    vx_core::Type_typedef vx_core::Class_arg::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "arg", // name
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

    vx_core::Type_arg vx_core::e_arg = std::make_shared<vx_core::Class_arg>();
    vx_core::Type_arg vx_core::t_arg = std::make_shared<vx_core::Class_arg>();
  //}

  /**
   * type: arglist
   * A list of arg
   * (type arglist)
   */
  //class Type_arglist {
    vx_core::vx_Type_listany vx_core::Class_arglist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_core::Type_arg vx_core::Class_arglist::vx_arg(vx_core::Type_int index) {
      vx_core::Type_arg output = vx_core::e_arg;
      vx_core::Class_arglist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_core::Type_arg> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_arg> vx_core::Class_arglist::vx_listarg() {return vx_p_list;}

    vx_core::Type_any vx_core::Class_arglist::vx_any(vx_core::Type_int index) {
      return this->vx_arg(index);
    }

    template <class T> std::shared_ptr<T> vx_core::Class_arglist::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_arglist->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_arglist::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_arglist output;
      vx_core::Class_arglist* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_core::Type_arg> listval = val->vx_listarg();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_arg) {
          listval->push_back(vx_core::any_from_any(vx_core::t_arg, valsub));
        } else if (valsubtype == vx_core::t_arglist) {
          vx_core::Type_arglist multi = vx_core::any_from_any(vx_core::t_arglist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listarg());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new arglist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_arglist::vx_empty(std::shared_ptr<T> val) {return vx_core::e_arglist;}
    template <class T> std::shared_ptr<T> vx_core::Class_arglist::vx_type(std::shared_ptr<T> val) {return vx_core::t_arglist;}

    vx_core::Type_typedef vx_core::Class_arglist::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "arglist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_arg}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_arglist vx_core::e_arglist = std::make_shared<vx_core::Class_arglist>();
    vx_core::Type_arglist vx_core::t_arglist = std::make_shared<vx_core::Class_arglist>();
  //}

  /**
   * type: argmap
   * A map of arg
   * (type argmap)
   */
  //class Type_argmap {
    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_argmap::vx_map() {
      return vx_core::map_from_map(vx_core::t_any, this->vx_p_map);
    }

    // vx_arg(key)
    vx_core::Type_arg vx_core::Class_argmap::vx_arg(vx_core::Type_string key) {
      vx_core::Type_arg output = vx_core::e_arg;
      vx_core::Class_argmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_arg> mapval = map->vx_p_map;
      output = vx_core::any_from_map(mapval, skey, vx_core::e_arg);
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_argmap::vx_any(vx_core::Type_string key) {
      return this->vx_arg(key);
    }

    // vx_maparg()
    std::map<std::string, vx_core::Type_arg> vx_core::Class_argmap::vx_maparg() {return vx_p_map;}

    // vx_new_from_map(mapval)
    template <class T> std::shared_ptr<T>  vx_core::Class_argmap::vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval) {
      vx_core::Type_argmap output;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_core::Type_arg> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = vx_core::t_any->vx_type_from_any(val);
        if (valtype == vx_core::t_arg) {
          vx_core::Type_arg castval = vx_core::any_from_any(vx_core::t_arg, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(argmap) Invalid Value: " + vx_core::string_from_any(val) + "");
          msgblock = vx_core::t_msgblock->vx_copy(vx_core::t_msgblock, {msgblock, msg});
        }
      }
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_argmap::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_argmap->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_argmap::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_argmap output;
      vx_core::Class_argmap* valmap = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(valmap, vals);
      std::map<std::string, vx_core::Type_arg> mapval;
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
          vx_core::Type_arg valany;
          if (valsubtype == vx_core::t_arg) {
            valany = vx_core::any_from_any(vx_core::t_arg, valsub);
          } else if (valsubtype == vx_core::t_arg) {
            valany = vx_core::any_from_any(vx_core::t_arg, valsub);
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

    template <class T> std::shared_ptr<T> vx_core::Class_argmap::vx_empty(std::shared_ptr<T> val) {return vx_core::e_argmap;}
    template <class T> std::shared_ptr<T> vx_core::Class_argmap::vx_type(std::shared_ptr<T> val) {return vx_core::t_argmap;}

    vx_core::Type_typedef vx_core::Class_argmap::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "argmap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_arg}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_argmap vx_core::e_argmap = std::make_shared<vx_core::Class_argmap>();
    vx_core::Type_argmap vx_core::t_argmap = std::make_shared<vx_core::Class_argmap>();
  //}

  /**
   * type: booleanlist
   * (type booleanlist)
   */
  //class Type_booleanlist {
    vx_core::vx_Type_listany vx_core::Class_booleanlist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_core::Type_boolean vx_core::Class_booleanlist::vx_boolean(vx_core::Type_int index) {
      vx_core::Type_boolean output = vx_core::e_boolean;
      vx_core::Class_booleanlist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_core::Type_boolean> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_boolean> vx_core::Class_booleanlist::vx_listboolean() {return vx_p_list;}

    vx_core::Type_any vx_core::Class_booleanlist::vx_any(vx_core::Type_int index) {
      return this->vx_boolean(index);
    }

    template <class T> std::shared_ptr<T> vx_core::Class_booleanlist::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_booleanlist->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_booleanlist::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_booleanlist output;
      vx_core::Class_booleanlist* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_core::Type_boolean> listval = val->vx_listboolean();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_boolean) {
          listval->push_back(vx_core::any_from_any(vx_core::t_boolean, valsub));
        } else if (valsubtype == vx_core::t_booleanlist) {
          vx_core::Type_booleanlist multi = vx_core::any_from_any(vx_core::t_booleanlist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listboolean());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new booleanlist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_booleanlist::vx_empty(std::shared_ptr<T> val) {return vx_core::e_booleanlist;}
    template <class T> std::shared_ptr<T> vx_core::Class_booleanlist::vx_type(std::shared_ptr<T> val) {return vx_core::t_booleanlist;}

    vx_core::Type_typedef vx_core::Class_booleanlist::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "booleanlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_boolean}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_booleanlist vx_core::e_booleanlist = std::make_shared<vx_core::Class_booleanlist>();
    vx_core::Type_booleanlist vx_core::t_booleanlist = std::make_shared<vx_core::Class_booleanlist>();
  //}

  /**
   * type: collection
   * (type collection)
   */
  //class Type_collection {
    template <class T> std::shared_ptr<T> vx_core::Class_collection::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_collection->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_collection::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_collection output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_collection::vx_empty(std::shared_ptr<T> val) {return vx_core::e_collection;}
    template <class T> std::shared_ptr<T> vx_core::Class_collection::vx_type(std::shared_ptr<T> val) {return vx_core::t_collection;}

    vx_core::Type_typedef vx_core::Class_collection::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "collection", // name
        "", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_list, vx_core::t_map}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_collection vx_core::e_collection = std::make_shared<vx_core::Class_collection>();
    vx_core::Type_collection vx_core::t_collection = std::make_shared<vx_core::Class_collection>();
  //}

  /**
   * type: compilelanguages
   * (type compilelanguages)
   */
  //class Type_compilelanguages {
    template <class T> std::shared_ptr<T> vx_core::Class_compilelanguages::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_compilelanguages->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_compilelanguages::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_compilelanguages output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_compilelanguages::vx_empty(std::shared_ptr<T> val) {return vx_core::e_compilelanguages;}
    template <class T> std::shared_ptr<T> vx_core::Class_compilelanguages::vx_type(std::shared_ptr<T> val) {return vx_core::t_compilelanguages;}

    vx_core::Type_typedef vx_core::Class_compilelanguages::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "compilelanguages", // name
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

    vx_core::Type_compilelanguages vx_core::e_compilelanguages = std::make_shared<vx_core::Class_compilelanguages>();
    vx_core::Type_compilelanguages vx_core::t_compilelanguages = std::make_shared<vx_core::Class_compilelanguages>();
  //}

  /**
   * type: connect
   * General connect trait
   * (type connect)
   */
  //class Type_connect {
    template <class T> std::shared_ptr<T> vx_core::Class_connect::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_connect->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_connect::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_connect output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_connect::vx_empty(std::shared_ptr<T> val) {return vx_core::e_connect;}
    template <class T> std::shared_ptr<T> vx_core::Class_connect::vx_type(std::shared_ptr<T> val) {return vx_core::t_connect;}

    vx_core::Type_typedef vx_core::Class_connect::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "connect", // name
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

    vx_core::Type_connect vx_core::e_connect = std::make_shared<vx_core::Class_connect>();
    vx_core::Type_connect vx_core::t_connect = std::make_shared<vx_core::Class_connect>();
  //}

  /**
   * type: connectlist
   * List of connect
   * (type connectlist)
   */
  //class Type_connectlist {
    vx_core::vx_Type_listany vx_core::Class_connectlist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_core::Type_connect vx_core::Class_connectlist::vx_connect(vx_core::Type_int index) {
      vx_core::Type_connect output = vx_core::e_connect;
      vx_core::Class_connectlist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_core::Type_connect> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_connect> vx_core::Class_connectlist::vx_listconnect() {return vx_p_list;}

    vx_core::Type_any vx_core::Class_connectlist::vx_any(vx_core::Type_int index) {
      return this->vx_connect(index);
    }

    template <class T> std::shared_ptr<T> vx_core::Class_connectlist::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_connectlist->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_connectlist::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_connectlist output;
      vx_core::Class_connectlist* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_core::Type_connect> listval = val->vx_listconnect();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_connect) {
          listval->push_back(vx_core::any_from_any(vx_core::t_connect, valsub));
        } else if (valsubtype == vx_core::t_connectlist) {
          vx_core::Type_connectlist multi = vx_core::any_from_any(vx_core::t_connectlist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listconnect());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new connectlist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_connectlist::vx_empty(std::shared_ptr<T> val) {return vx_core::e_connectlist;}
    template <class T> std::shared_ptr<T> vx_core::Class_connectlist::vx_type(std::shared_ptr<T> val) {return vx_core::t_connectlist;}

    vx_core::Type_typedef vx_core::Class_connectlist::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "connectlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_connect}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_connectlist vx_core::e_connectlist = std::make_shared<vx_core::Class_connectlist>();
    vx_core::Type_connectlist vx_core::t_connectlist = std::make_shared<vx_core::Class_connectlist>();
  //}

  /**
   * type: connectmap
   * Map of connect
   * (type connectmap)
   */
  //class Type_connectmap {
    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_connectmap::vx_map() {
      return vx_core::map_from_map(vx_core::t_any, this->vx_p_map);
    }

    // vx_connect(key)
    vx_core::Type_connect vx_core::Class_connectmap::vx_connect(vx_core::Type_string key) {
      vx_core::Type_connect output = vx_core::e_connect;
      vx_core::Class_connectmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_connect> mapval = map->vx_p_map;
      output = vx_core::any_from_map(mapval, skey, vx_core::e_connect);
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_connectmap::vx_any(vx_core::Type_string key) {
      return this->vx_connect(key);
    }

    // vx_mapconnect()
    std::map<std::string, vx_core::Type_connect> vx_core::Class_connectmap::vx_mapconnect() {return vx_p_map;}

    // vx_new_from_map(mapval)
    template <class T> std::shared_ptr<T>  vx_core::Class_connectmap::vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval) {
      vx_core::Type_connectmap output;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_core::Type_connect> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = vx_core::t_any->vx_type_from_any(val);
        if (valtype == vx_core::t_connect) {
          vx_core::Type_connect castval = vx_core::any_from_any(vx_core::t_connect, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(connectmap) Invalid Value: " + vx_core::string_from_any(val) + "");
          msgblock = vx_core::t_msgblock->vx_copy(vx_core::t_msgblock, {msgblock, msg});
        }
      }
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_connectmap::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_connectmap->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_connectmap::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_connectmap output;
      vx_core::Class_connectmap* valmap = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(valmap, vals);
      std::map<std::string, vx_core::Type_connect> mapval;
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
          vx_core::Type_connect valany;
          if (valsubtype == vx_core::t_connect) {
            valany = vx_core::any_from_any(vx_core::t_connect, valsub);
          } else if (valsubtype == vx_core::t_connect) {
            valany = vx_core::any_from_any(vx_core::t_connect, valsub);
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

    template <class T> std::shared_ptr<T> vx_core::Class_connectmap::vx_empty(std::shared_ptr<T> val) {return vx_core::e_connectmap;}
    template <class T> std::shared_ptr<T> vx_core::Class_connectmap::vx_type(std::shared_ptr<T> val) {return vx_core::t_connectmap;}

    vx_core::Type_typedef vx_core::Class_connectmap::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "connectmap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_connect}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_connectmap vx_core::e_connectmap = std::make_shared<vx_core::Class_connectmap>();
    vx_core::Type_connectmap vx_core::t_connectmap = std::make_shared<vx_core::Class_connectmap>();
  //}

  /**
   * type: const
   * Original Constant Class.
   * (type const)
   */
  //class Type_const {
    template <class T> std::shared_ptr<T> vx_core::Class_const::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_const->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_const::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_const output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_const::vx_empty(std::shared_ptr<T> val) {return vx_core::e_const;}
    template <class T> std::shared_ptr<T> vx_core::Class_const::vx_type(std::shared_ptr<T> val) {return vx_core::t_const;}

    vx_core::Type_typedef vx_core::Class_const::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "const", // name
        ":const", // extends
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

    vx_core::Type_const vx_core::e_const = std::make_shared<vx_core::Class_const>();
    vx_core::Type_const vx_core::t_const = std::make_shared<vx_core::Class_const>();
  //}

  /**
   * type: constdef
   * Const Definition Class for inspecting properties.
   * (type constdef)
   */
  //class Type_constdef {
    // pkgname()
    vx_core::Type_string vx_core::Class_constdef::pkgname() {
      vx_core::Type_string output = this->vx_p_pkgname;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // name()
    vx_core::Type_string vx_core::Class_constdef::name() {
      vx_core::Type_string output = this->vx_p_name;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // type()
    vx_core::Type_any vx_core::Class_constdef::type() {
      vx_core::Type_any output = this->vx_p_type;
      if (output == NULL) {
        output = vx_core::t_any;
      }
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_constdef::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":pkgname") {
        output = this->pkgname();
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":type") {
        output = this->type();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_constdef::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":pkgname"] = this->pkgname();
      output[":name"] = this->name();
      output[":type"] = this->type();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_constdef::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_constdef->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_constdef::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_constdef output;
      vx_core::Class_constdef* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_pkgname = val->pkgname();
      output->vx_p_name = val->name();
      output->vx_p_type = val->type();
      std::set<std::string> validkeys;
      validkeys.insert(":pkgname");
      validkeys.insert(":name");
      validkeys.insert(":type");
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new constdef) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":pkgname") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_pkgname = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new constdef :pkgname " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_name = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new constdef :name " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":type") {
            if (valsubtype == vx_core::t_any) {
              output->vx_p_type = vx_core::any_from_any(vx_core::t_any, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new constdef :type " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new constdef) - Invalid Key: " + key);
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

    template <class T> std::shared_ptr<T> vx_core::Class_constdef::vx_empty(std::shared_ptr<T> val) {return vx_core::e_constdef;}
    template <class T> std::shared_ptr<T> vx_core::Class_constdef::vx_type(std::shared_ptr<T> val) {return vx_core::t_constdef;}

    vx_core::Type_typedef vx_core::Class_constdef::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "constdef", // name
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

    vx_core::Type_constdef vx_core::e_constdef = std::make_shared<vx_core::Class_constdef>();
    vx_core::Type_constdef vx_core::t_constdef = std::make_shared<vx_core::Class_constdef>();
  //}

  /**
   * type: constlist
   * List of Const.
   * (type constlist)
   */
  //class Type_constlist {
    vx_core::vx_Type_listany vx_core::Class_constlist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_core::Type_const vx_core::Class_constlist::vx_const(vx_core::Type_int index) {
      vx_core::Type_const output = vx_core::e_const;
      vx_core::Class_constlist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_core::Type_const> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_const> vx_core::Class_constlist::vx_listconst() {return vx_p_list;}

    vx_core::Type_any vx_core::Class_constlist::vx_any(vx_core::Type_int index) {
      return this->vx_const(index);
    }

    template <class T> std::shared_ptr<T> vx_core::Class_constlist::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_constlist->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_constlist::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_constlist output;
      vx_core::Class_constlist* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_core::Type_const> listval = val->vx_listconst();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_const) {
          listval->push_back(vx_core::any_from_any(vx_core::t_const, valsub));
        } else if (valsubtype == vx_core::t_constlist) {
          vx_core::Type_constlist multi = vx_core::any_from_any(vx_core::t_constlist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listconst());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new constlist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_constlist::vx_empty(std::shared_ptr<T> val) {return vx_core::e_constlist;}
    template <class T> std::shared_ptr<T> vx_core::Class_constlist::vx_type(std::shared_ptr<T> val) {return vx_core::t_constlist;}

    vx_core::Type_typedef vx_core::Class_constlist::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "constlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_const}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_constlist vx_core::e_constlist = std::make_shared<vx_core::Class_constlist>();
    vx_core::Type_constlist vx_core::t_constlist = std::make_shared<vx_core::Class_constlist>();
  //}

  /**
   * type: constmap
   * Map of Const.
   * (type constmap)
   */
  //class Type_constmap {
    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_constmap::vx_map() {
      return vx_core::map_from_map(vx_core::t_any, this->vx_p_map);
    }

    // vx_const(key)
    vx_core::Type_const vx_core::Class_constmap::vx_const(vx_core::Type_string key) {
      vx_core::Type_const output = vx_core::e_const;
      vx_core::Class_constmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_const> mapval = map->vx_p_map;
      output = vx_core::any_from_map(mapval, skey, vx_core::e_const);
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_constmap::vx_any(vx_core::Type_string key) {
      return this->vx_const(key);
    }

    // vx_mapconst()
    std::map<std::string, vx_core::Type_const> vx_core::Class_constmap::vx_mapconst() {return vx_p_map;}

    // vx_new_from_map(mapval)
    template <class T> std::shared_ptr<T>  vx_core::Class_constmap::vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval) {
      vx_core::Type_constmap output;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_core::Type_const> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = vx_core::t_any->vx_type_from_any(val);
        if (valtype == vx_core::t_const) {
          vx_core::Type_const castval = vx_core::any_from_any(vx_core::t_const, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(constmap) Invalid Value: " + vx_core::string_from_any(val) + "");
          msgblock = vx_core::t_msgblock->vx_copy(vx_core::t_msgblock, {msgblock, msg});
        }
      }
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_constmap::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_constmap->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_constmap::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_constmap output;
      vx_core::Class_constmap* valmap = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(valmap, vals);
      std::map<std::string, vx_core::Type_const> mapval;
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
          vx_core::Type_const valany;
          if (valsubtype == vx_core::t_const) {
            valany = vx_core::any_from_any(vx_core::t_const, valsub);
          } else if (valsubtype == vx_core::t_const) {
            valany = vx_core::any_from_any(vx_core::t_const, valsub);
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

    template <class T> std::shared_ptr<T> vx_core::Class_constmap::vx_empty(std::shared_ptr<T> val) {return vx_core::e_constmap;}
    template <class T> std::shared_ptr<T> vx_core::Class_constmap::vx_type(std::shared_ptr<T> val) {return vx_core::t_constmap;}

    vx_core::Type_typedef vx_core::Class_constmap::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "constmap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_const}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_constmap vx_core::e_constmap = std::make_shared<vx_core::Class_constmap>();
    vx_core::Type_constmap vx_core::t_constmap = std::make_shared<vx_core::Class_constmap>();
  //}

  /**
   * type: context
   * Context
   * (type context)
   */
  //class Type_context {
    // code()
    vx_core::Type_string vx_core::Class_context::code() {
      vx_core::Type_string output = this->vx_p_code;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // session()
    vx_core::Type_session vx_core::Class_context::session() {
      vx_core::Type_session output = this->vx_p_session;
      if (output == NULL) {
        output = vx_core::t_session;
      }
      return output;
    }

    // setting()
    vx_core::Type_setting vx_core::Class_context::setting() {
      vx_core::Type_setting output = this->vx_p_setting;
      if (output == NULL) {
        output = vx_core::t_setting;
      }
      return output;
    }

    // state()
    vx_core::Type_state vx_core::Class_context::state() {
      vx_core::Type_state output = this->vx_p_state;
      if (output == NULL) {
        output = vx_core::t_state;
      }
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_context::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":code") {
        output = this->code();
      } else if (skey == ":session") {
        output = this->session();
      } else if (skey == ":setting") {
        output = this->setting();
      } else if (skey == ":state") {
        output = this->state();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_context::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":code"] = this->code();
      output[":session"] = this->session();
      output[":setting"] = this->setting();
      output[":state"] = this->state();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_context::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_context->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_context::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_context output;
      vx_core::Class_context* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_code = val->code();
      output->vx_p_session = val->session();
      output->vx_p_setting = val->setting();
      output->vx_p_state = val->state();
      std::set<std::string> validkeys;
      validkeys.insert(":code");
      validkeys.insert(":session");
      validkeys.insert(":setting");
      validkeys.insert(":state");
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new context) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":code") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_code = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new context :code " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":session") {
            if (valsubtype == vx_core::t_session) {
              output->vx_p_session = vx_core::any_from_any(vx_core::t_session, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new context :session " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":setting") {
            if (valsubtype == vx_core::t_setting) {
              output->vx_p_setting = vx_core::any_from_any(vx_core::t_setting, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new context :setting " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":state") {
            if (valsubtype == vx_core::t_state) {
              output->vx_p_state = vx_core::any_from_any(vx_core::t_state, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new context :state " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new context) - Invalid Key: " + key);
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

    template <class T> std::shared_ptr<T> vx_core::Class_context::vx_empty(std::shared_ptr<T> val) {return vx_core::e_context;}
    template <class T> std::shared_ptr<T> vx_core::Class_context::vx_type(std::shared_ptr<T> val) {return vx_core::t_context;}

    vx_core::Type_typedef vx_core::Class_context::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "context", // name
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

    vx_core::Type_context vx_core::e_context = std::make_shared<vx_core::Class_context>();
    vx_core::Type_context vx_core::t_context = std::make_shared<vx_core::Class_context>();
  //}

  /**
   * type: error
   * Error Type
   * (type error)
   */
  //class Type_error {
    template <class T> std::shared_ptr<T> vx_core::Class_error::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_error->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_error::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_error output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_error::vx_empty(std::shared_ptr<T> val) {return vx_core::e_error;}
    template <class T> std::shared_ptr<T> vx_core::Class_error::vx_type(std::shared_ptr<T> val) {return vx_core::t_error;}

    vx_core::Type_typedef vx_core::Class_error::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "error", // name
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

    vx_core::Type_error vx_core::e_error = std::make_shared<vx_core::Class_error>();
    vx_core::Type_error vx_core::t_error = std::make_shared<vx_core::Class_error>();
  //}

  /**
   * type: funcdef
   * Func Definition Class for inspecting properties.
   * (type funcdef)
   */
  //class Type_funcdef {
    // pkgname()
    vx_core::Type_string vx_core::Class_funcdef::pkgname() {
      vx_core::Type_string output = this->vx_p_pkgname;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // name()
    vx_core::Type_string vx_core::Class_funcdef::name() {
      vx_core::Type_string output = this->vx_p_name;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // idx()
    vx_core::Type_int vx_core::Class_funcdef::idx() {
      vx_core::Type_int output = this->vx_p_idx;
      if (output == NULL) {
        output = vx_core::t_int;
      }
      return output;
    }

    // type()
    vx_core::Type_any vx_core::Class_funcdef::type() {
      vx_core::Type_any output = this->vx_p_type;
      if (output == NULL) {
        output = vx_core::t_any;
      }
      return output;
    }

    // async()
    vx_core::Type_boolean vx_core::Class_funcdef::async() {
      vx_core::Type_boolean output = this->vx_p_async;
      if (output == NULL) {
        output = vx_core::t_boolean;
      }
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_funcdef::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":pkgname") {
        output = this->pkgname();
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":idx") {
        output = this->idx();
      } else if (skey == ":type") {
        output = this->type();
      } else if (skey == ":async") {
        output = this->async();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_funcdef::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":pkgname"] = this->pkgname();
      output[":name"] = this->name();
      output[":idx"] = this->idx();
      output[":type"] = this->type();
      output[":async"] = this->async();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_funcdef::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_funcdef->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_funcdef::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_funcdef output;
      vx_core::Class_funcdef* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_pkgname = val->pkgname();
      output->vx_p_name = val->name();
      output->vx_p_idx = val->idx();
      output->vx_p_type = val->type();
      output->vx_p_async = val->async();
      std::set<std::string> validkeys;
      validkeys.insert(":pkgname");
      validkeys.insert(":name");
      validkeys.insert(":idx");
      validkeys.insert(":type");
      validkeys.insert(":async");
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new funcdef) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":pkgname") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_pkgname = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new funcdef :pkgname " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_name = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new funcdef :name " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":idx") {
            if (valsubtype == vx_core::t_int) {
              output->vx_p_idx = vx_core::any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new funcdef :idx " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":type") {
            if (valsubtype == vx_core::t_any) {
              output->vx_p_type = vx_core::any_from_any(vx_core::t_any, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new funcdef :type " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":async") {
            if (valsubtype == vx_core::t_boolean) {
              output->vx_p_async = vx_core::any_from_any(vx_core::t_boolean, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new funcdef :async " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new funcdef) - Invalid Key: " + key);
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

    template <class T> std::shared_ptr<T> vx_core::Class_funcdef::vx_empty(std::shared_ptr<T> val) {return vx_core::e_funcdef;}
    template <class T> std::shared_ptr<T> vx_core::Class_funcdef::vx_type(std::shared_ptr<T> val) {return vx_core::t_funcdef;}

    vx_core::Type_typedef vx_core::Class_funcdef::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "funcdef", // name
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

    vx_core::Type_funcdef vx_core::e_funcdef = std::make_shared<vx_core::Class_funcdef>();
    vx_core::Type_funcdef vx_core::t_funcdef = std::make_shared<vx_core::Class_funcdef>();
  //}

  /**
   * type: funclist
   * List of Func.
   * (type funclist)
   */
  //class Type_funclist {
    vx_core::vx_Type_listany vx_core::Class_funclist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_core::Type_func vx_core::Class_funclist::vx_func(vx_core::Type_int index) {
      vx_core::Type_func output = vx_core::e_func;
      vx_core::Class_funclist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_core::Type_func> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_func> vx_core::Class_funclist::vx_listfunc() {return vx_p_list;}

    vx_core::Type_any vx_core::Class_funclist::vx_any(vx_core::Type_int index) {
      return this->vx_func(index);
    }

    template <class T> std::shared_ptr<T> vx_core::Class_funclist::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_funclist->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_funclist::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_funclist output;
      vx_core::Class_funclist* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_core::Type_func> listval = val->vx_listfunc();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_func) {
          listval->push_back(vx_core::any_from_any(vx_core::t_func, valsub));
        } else if (valsubtype == vx_core::t_funclist) {
          vx_core::Type_funclist multi = vx_core::any_from_any(vx_core::t_funclist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listfunc());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new funclist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_funclist::vx_empty(std::shared_ptr<T> val) {return vx_core::e_funclist;}
    template <class T> std::shared_ptr<T> vx_core::Class_funclist::vx_type(std::shared_ptr<T> val) {return vx_core::t_funclist;}

    vx_core::Type_typedef vx_core::Class_funclist::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "funclist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_func}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_funclist vx_core::e_funclist = std::make_shared<vx_core::Class_funclist>();
    vx_core::Type_funclist vx_core::t_funclist = std::make_shared<vx_core::Class_funclist>();
  //}

  /**
   * type: funcmap
   * Map of Func.
   * (type funcmap)
   */
  //class Type_funcmap {
    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_funcmap::vx_map() {
      return vx_core::map_from_map(vx_core::t_any, this->vx_p_map);
    }

    // vx_func(key)
    vx_core::Type_func vx_core::Class_funcmap::vx_func(vx_core::Type_string key) {
      vx_core::Type_func output = vx_core::e_func;
      vx_core::Class_funcmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_func> mapval = map->vx_p_map;
      output = vx_core::any_from_map(mapval, skey, vx_core::e_func);
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_funcmap::vx_any(vx_core::Type_string key) {
      return this->vx_func(key);
    }

    // vx_mapfunc()
    std::map<std::string, vx_core::Type_func> vx_core::Class_funcmap::vx_mapfunc() {return vx_p_map;}

    // vx_new_from_map(mapval)
    template <class T> std::shared_ptr<T>  vx_core::Class_funcmap::vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval) {
      vx_core::Type_funcmap output;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_core::Type_func> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = vx_core::t_any->vx_type_from_any(val);
        if (valtype == vx_core::t_func) {
          vx_core::Type_func castval = vx_core::any_from_any(vx_core::t_func, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(funcmap) Invalid Value: " + vx_core::string_from_any(val) + "");
          msgblock = vx_core::t_msgblock->vx_copy(vx_core::t_msgblock, {msgblock, msg});
        }
      }
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_funcmap::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_funcmap->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_funcmap::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_funcmap output;
      vx_core::Class_funcmap* valmap = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(valmap, vals);
      std::map<std::string, vx_core::Type_func> mapval;
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
          vx_core::Type_func valany;
          if (valsubtype == vx_core::t_func) {
            valany = vx_core::any_from_any(vx_core::t_func, valsub);
          } else if (valsubtype == vx_core::t_func) {
            valany = vx_core::any_from_any(vx_core::t_func, valsub);
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

    template <class T> std::shared_ptr<T> vx_core::Class_funcmap::vx_empty(std::shared_ptr<T> val) {return vx_core::e_funcmap;}
    template <class T> std::shared_ptr<T> vx_core::Class_funcmap::vx_type(std::shared_ptr<T> val) {return vx_core::t_funcmap;}

    vx_core::Type_typedef vx_core::Class_funcmap::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "funcmap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_func}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_funcmap vx_core::e_funcmap = std::make_shared<vx_core::Class_funcmap>();
    vx_core::Type_funcmap vx_core::t_funcmap = std::make_shared<vx_core::Class_funcmap>();
  //}

  /**
   * type: intlist
   * A list of int.
   * (type intlist)
   */
  //class Type_intlist {
    vx_core::vx_Type_listany vx_core::Class_intlist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_core::Type_int vx_core::Class_intlist::vx_int(vx_core::Type_int index) {
      vx_core::Type_int output = vx_core::e_int;
      vx_core::Class_intlist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_core::Type_int> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_int> vx_core::Class_intlist::vx_listint() {return vx_p_list;}

    vx_core::Type_any vx_core::Class_intlist::vx_any(vx_core::Type_int index) {
      return this->vx_int(index);
    }

    template <class T> std::shared_ptr<T> vx_core::Class_intlist::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_intlist->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_intlist::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_intlist output;
      vx_core::Class_intlist* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_core::Type_int> listval = val->vx_listint();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_int) {
          listval->push_back(vx_core::any_from_any(vx_core::t_int, valsub));
        } else if (valsubtype == vx_core::t_intlist) {
          vx_core::Type_intlist multi = vx_core::any_from_any(vx_core::t_intlist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listint());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new intlist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_intlist::vx_empty(std::shared_ptr<T> val) {return vx_core::e_intlist;}
    template <class T> std::shared_ptr<T> vx_core::Class_intlist::vx_type(std::shared_ptr<T> val) {return vx_core::t_intlist;}

    vx_core::Type_typedef vx_core::Class_intlist::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "intlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_int}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_intlist vx_core::e_intlist = std::make_shared<vx_core::Class_intlist>();
    vx_core::Type_intlist vx_core::t_intlist = std::make_shared<vx_core::Class_intlist>();
  //}

  /**
   * type: intmap
   * A map of int.
   * (type intmap)
   */
  //class Type_intmap {
    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_intmap::vx_map() {
      return vx_core::map_from_map(vx_core::t_any, this->vx_p_map);
    }

    // vx_int(key)
    vx_core::Type_int vx_core::Class_intmap::vx_int(vx_core::Type_string key) {
      vx_core::Type_int output = vx_core::e_int;
      vx_core::Class_intmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_int> mapval = map->vx_p_map;
      output = vx_core::any_from_map(mapval, skey, vx_core::e_int);
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_intmap::vx_any(vx_core::Type_string key) {
      return this->vx_int(key);
    }

    // vx_mapint()
    std::map<std::string, vx_core::Type_int> vx_core::Class_intmap::vx_mapint() {return vx_p_map;}

    // vx_new_from_map(mapval)
    template <class T> std::shared_ptr<T>  vx_core::Class_intmap::vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval) {
      vx_core::Type_intmap output;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_core::Type_int> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = vx_core::t_any->vx_type_from_any(val);
        if (valtype == vx_core::t_int) {
          vx_core::Type_int castval = vx_core::any_from_any(vx_core::t_int, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(intmap) Invalid Value: " + vx_core::string_from_any(val) + "");
          msgblock = vx_core::t_msgblock->vx_copy(vx_core::t_msgblock, {msgblock, msg});
        }
      }
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_intmap::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_intmap->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_intmap::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_intmap output;
      vx_core::Class_intmap* valmap = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(valmap, vals);
      std::map<std::string, vx_core::Type_int> mapval;
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
          vx_core::Type_int valany;
          if (valsubtype == vx_core::t_int) {
            valany = vx_core::any_from_any(vx_core::t_int, valsub);
          } else if (valsubtype == vx_core::t_int) {
            valany = vx_core::any_from_any(vx_core::t_int, valsub);
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

    template <class T> std::shared_ptr<T> vx_core::Class_intmap::vx_empty(std::shared_ptr<T> val) {return vx_core::e_intmap;}
    template <class T> std::shared_ptr<T> vx_core::Class_intmap::vx_type(std::shared_ptr<T> val) {return vx_core::t_intmap;}

    vx_core::Type_typedef vx_core::Class_intmap::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "intmap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_int}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_intmap vx_core::e_intmap = std::make_shared<vx_core::Class_intmap>();
    vx_core::Type_intmap vx_core::t_intmap = std::make_shared<vx_core::Class_intmap>();
  //}

  /**
   * type: listtype
   * A generic type that extends :list.
   * (type listtype)
   */
  //class Type_listtype {
    template <class T> std::shared_ptr<T> vx_core::Class_listtype::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_listtype->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_listtype::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_listtype output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_listtype::vx_empty(std::shared_ptr<T> val) {return vx_core::e_listtype;}
    template <class T> std::shared_ptr<T> vx_core::Class_listtype::vx_type(std::shared_ptr<T> val) {return vx_core::t_listtype;}

    vx_core::Type_typedef vx_core::Class_listtype::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "listtype", // name
        ":type", // extends
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

    vx_core::Type_listtype vx_core::e_listtype = std::make_shared<vx_core::Class_listtype>();
    vx_core::Type_listtype vx_core::t_listtype = std::make_shared<vx_core::Class_listtype>();
  //}

  /**
   * type: maptype
   * A generic type that extends :map.
   * (type maptype)
   */
  //class Type_maptype {
    template <class T> std::shared_ptr<T> vx_core::Class_maptype::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_maptype->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_maptype::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_maptype output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_maptype::vx_empty(std::shared_ptr<T> val) {return vx_core::e_maptype;}
    template <class T> std::shared_ptr<T> vx_core::Class_maptype::vx_type(std::shared_ptr<T> val) {return vx_core::t_maptype;}

    vx_core::Type_typedef vx_core::Class_maptype::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "maptype", // name
        ":type", // extends
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

    vx_core::Type_maptype vx_core::e_maptype = std::make_shared<vx_core::Class_maptype>();
    vx_core::Type_maptype vx_core::t_maptype = std::make_shared<vx_core::Class_maptype>();
  //}

  /**
   * type: mempool
   * Memory Pool
   * (type mempool)
   */
  //class Type_mempool {
    // valuepool()
    vx_core::Type_value vx_core::Class_mempool::valuepool() {
      vx_core::Type_value output = this->vx_p_valuepool;
      if (output == NULL) {
        output = vx_core::t_value;
      }
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_mempool::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":valuepool") {
        output = this->valuepool();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_mempool::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":valuepool"] = this->valuepool();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_mempool::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_mempool->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_mempool::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_mempool output;
      vx_core::Class_mempool* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_valuepool = val->valuepool();
      std::set<std::string> validkeys;
      validkeys.insert(":valuepool");
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new mempool) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":valuepool") {
            if (valsubtype == vx_core::t_value) {
              output->vx_p_valuepool = vx_core::any_from_any(vx_core::t_value, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new mempool :valuepool " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new mempool) - Invalid Key: " + key);
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

    template <class T> std::shared_ptr<T> vx_core::Class_mempool::vx_empty(std::shared_ptr<T> val) {return vx_core::e_mempool;}
    template <class T> std::shared_ptr<T> vx_core::Class_mempool::vx_type(std::shared_ptr<T> val) {return vx_core::t_mempool;}

    vx_core::Type_typedef vx_core::Class_mempool::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "mempool", // name
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

    vx_core::Type_mempool vx_core::e_mempool = std::make_shared<vx_core::Class_mempool>();
    vx_core::Type_mempool vx_core::t_mempool = std::make_shared<vx_core::Class_mempool>();
  //}

  /**
   * type: msg
   * Message Type for error handling
   * (type msg)
   */
  //class Type_msg {
    // code()
    vx_core::Type_string vx_core::Class_msg::code() {
      vx_core::Type_string output = this->vx_p_code;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // severity()
    vx_core::Type_int vx_core::Class_msg::severity() {
      vx_core::Type_int output = this->vx_p_severity;
      if (output == NULL) {
        output = vx_core::t_int;
      }
      return output;
    }

    // text()
    vx_core::Type_string vx_core::Class_msg::text() {
      vx_core::Type_string output = this->vx_p_text;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_msg::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":code") {
        output = this->code();
      } else if (skey == ":severity") {
        output = this->severity();
      } else if (skey == ":text") {
        output = this->text();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_msg::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":code"] = this->code();
      output[":severity"] = this->severity();
      output[":text"] = this->text();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_msg::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_msg->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_msg::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_msg output;
      vx_core::Class_msg* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_code = val->code();
      output->vx_p_severity = val->severity();
      output->vx_p_text = val->text();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (key == "") {
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string valstr = vx_core::any_from_any(vx_core::t_string, valsub);
            key = valstr->vx_string();
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new msg) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":code") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_code = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new msg :code " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":severity") {
            if (valsubtype == vx_core::t_int) {
              output->vx_p_severity = vx_core::any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new msg :severity " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":text") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_text = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new msg :text " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          }
          key = "";
        }
      }
      return output;
    }

    vx_core::Type_msgblock vx_core::Class_msg::vx_msgblock() {return vx_core::e_msgblock;}
    template <class T> std::shared_ptr<T> vx_core::Class_msg::vx_empty(std::shared_ptr<T> val) {return vx_core::e_msg;}
    template <class T> std::shared_ptr<T> vx_core::Class_msg::vx_type(std::shared_ptr<T> val) {return vx_core::t_msg;}

    vx_core::Type_typedef vx_core::Class_msg::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "msg", // name
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

    vx_core::Type_msg vx_core::e_msg = std::make_shared<vx_core::Class_msg>();
    vx_core::Type_msg vx_core::t_msg = std::make_shared<vx_core::Class_msg>();
  //}

  /**
   * type: msgblock
   * Block of Messages
   * (type msgblock)
   */
  //class Type_msgblock {
    // msgs()
    vx_core::Type_msglist vx_core::Class_msgblock::msgs() {
      vx_core::Type_msglist output = this->vx_p_msgs;
      if (output == NULL) {
        output = vx_core::t_msglist;
      }
      return output;
    }

    // msgblocks()
    vx_core::Type_msgblocklist vx_core::Class_msgblock::msgblocks() {
      vx_core::Type_msgblocklist output = this->vx_p_msgblocks;
      if (output == NULL) {
        output = vx_core::t_msgblocklist;
      }
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_msgblock::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":msgs") {
        output = this->msgs();
      } else if (skey == ":msgblocks") {
        output = this->msgblocks();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_msgblock::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":msgs"] = this->msgs();
      output[":msgblocks"] = this->msgblocks();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_msgblock::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_msgblock->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_msgblock::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_msgblock output;
      vx_core::Class_msgblock* val = this;
      vx_core::Class_msgblock* msgblock = this;
      output->vx_p_msgs = val->msgs();
      output->vx_p_msgblocks = val->msgblocks();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          vx_core::Type_msgblocklist msgblocks = msgblock->msgblocks();
          msgblocks = msgblocks->vx_copy(vx_core::t_msgblocklist, {valsub});
          output->vx_p_msgblocks = msgblocks;
        } else if (valsubtype == vx_core::t_msg) {
          vx_core::Type_msglist msgs = msgblock->msgs();
          msgs = msgs->vx_copy(vx_core::t_msglist, {valsub});
          output->vx_p_msgs = msgs;
        } else if (valsubtype == vx_core::t_msgblocklist) {
          vx_core::Type_msgblocklist msgblocks = msgblock->msgblocks();
          msgblocks = msgblocks->vx_copy(vx_core::t_msgblocklist, {valsub});
          output->vx_p_msgblocks = msgblocks;
        } else if (valsubtype == vx_core::t_msglist) {
          vx_core::Type_msglist msgs = msgblock->msgs();
          msgs = msgs->vx_copy(vx_core::t_msgblocklist, {valsub});
          output->vx_p_msgs = msgs;
        } else if (key == "") {
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string valstr = vx_core::any_from_any(vx_core::t_string, valsub);
            key = valstr->vx_string();
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new msgblock) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":msgs") {
            if (valsubtype == vx_core::t_msglist) {
              output->vx_p_msgs = vx_core::any_from_any(vx_core::t_msglist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new msgblock :msgs " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":msgblocks") {
            if (valsubtype == vx_core::t_msgblocklist) {
              output->vx_p_msgblocks = vx_core::any_from_any(vx_core::t_msgblocklist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new msgblock :msgblocks " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          }
          key = "";
        }
      }
      return output;
    }

    vx_core::Type_msgblock vx_core::Class_msgblock::vx_msgblock() {return vx_core::e_msgblock;}
    template <class T> std::shared_ptr<T> vx_core::Class_msgblock::vx_empty(std::shared_ptr<T> val) {return vx_core::e_msgblock;}
    template <class T> std::shared_ptr<T> vx_core::Class_msgblock::vx_type(std::shared_ptr<T> val) {return vx_core::t_msgblock;}

    vx_core::Type_typedef vx_core::Class_msgblock::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "msgblock", // name
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

    vx_core::Type_msgblock vx_core::e_msgblock = std::make_shared<vx_core::Class_msgblock>();
    vx_core::Type_msgblock vx_core::t_msgblock = std::make_shared<vx_core::Class_msgblock>();
  //}

  /**
   * type: msgblocklist
   * List of Message Blocks
   * (type msgblocklist)
   */
  //class Type_msgblocklist {
    vx_core::vx_Type_listany vx_core::Class_msgblocklist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_core::Type_msgblock vx_core::Class_msgblocklist::vx_msgblock(vx_core::Type_int index) {
      vx_core::Type_msgblock output = vx_core::e_msgblock;
      vx_core::Class_msgblocklist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_core::Type_msgblock> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_msgblock> vx_core::Class_msgblocklist::vx_listmsgblock() {return vx_p_list;}

    vx_core::Type_any vx_core::Class_msgblocklist::vx_any(vx_core::Type_int index) {
      return this->vx_msgblock(index);
    }

    template <class T> std::shared_ptr<T> vx_core::Class_msgblocklist::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_msgblocklist->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_msgblocklist::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_msgblocklist output;
      vx_core::Class_msgblocklist* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_core::Type_msgblock> listval = val->vx_listmsgblock();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msgblock) {
          listval->push_back(vx_core::any_from_any(vx_core::t_msgblock, valsub));
        } else if (valsubtype == vx_core::t_msgblocklist) {
          vx_core::Type_msgblocklist multi = vx_core::any_from_any(vx_core::t_msgblocklist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listmsgblock());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new msgblocklist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_msgblocklist::vx_empty(std::shared_ptr<T> val) {return vx_core::e_msgblocklist;}
    template <class T> std::shared_ptr<T> vx_core::Class_msgblocklist::vx_type(std::shared_ptr<T> val) {return vx_core::t_msgblocklist;}

    vx_core::Type_typedef vx_core::Class_msgblocklist::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "msgblocklist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_msgblock}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_msgblocklist vx_core::e_msgblocklist = std::make_shared<vx_core::Class_msgblocklist>();
    vx_core::Type_msgblocklist vx_core::t_msgblocklist = std::make_shared<vx_core::Class_msgblocklist>();
  //}

  /**
   * type: msglist
   * List of Messages
   * (type msglist)
   */
  //class Type_msglist {
    vx_core::vx_Type_listany vx_core::Class_msglist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_core::Type_msg vx_core::Class_msglist::vx_msg(vx_core::Type_int index) {
      vx_core::Type_msg output = vx_core::e_msg;
      vx_core::Class_msglist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_core::Type_msg> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_msg> vx_core::Class_msglist::vx_listmsg() {return vx_p_list;}

    vx_core::Type_any vx_core::Class_msglist::vx_any(vx_core::Type_int index) {
      return this->vx_msg(index);
    }

    template <class T> std::shared_ptr<T> vx_core::Class_msglist::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_msglist->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_msglist::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_msglist output;
      vx_core::Class_msglist* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_core::Type_msg> listval = val->vx_listmsg();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          listval->push_back(vx_core::any_from_any(vx_core::t_msg, valsub));
        } else if (valsubtype == vx_core::t_msglist) {
          vx_core::Type_msglist multi = vx_core::any_from_any(vx_core::t_msglist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listmsg());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new msglist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_msglist::vx_empty(std::shared_ptr<T> val) {return vx_core::e_msglist;}
    template <class T> std::shared_ptr<T> vx_core::Class_msglist::vx_type(std::shared_ptr<T> val) {return vx_core::t_msglist;}

    vx_core::Type_typedef vx_core::Class_msglist::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "msglist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_msg}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_msglist vx_core::e_msglist = std::make_shared<vx_core::Class_msglist>();
    vx_core::Type_msglist vx_core::t_msglist = std::make_shared<vx_core::Class_msglist>();
  //}

  /**
   * type: none
   * No Type. No type is returned at all. e.g. Void
   * (type none)
   */
  //class Type_none {
    template <class T> std::shared_ptr<T> vx_core::Class_none::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_none->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_none::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_none output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_none::vx_empty(std::shared_ptr<T> val) {return vx_core::e_none;}
    template <class T> std::shared_ptr<T> vx_core::Class_none::vx_type(std::shared_ptr<T> val) {return vx_core::t_none;}

    vx_core::Type_typedef vx_core::Class_none::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "none", // name
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

    vx_core::Type_none vx_core::e_none = std::make_shared<vx_core::Class_none>();
    vx_core::Type_none vx_core::t_none = std::make_shared<vx_core::Class_none>();
  //}

  /**
   * type: notype
   * No Type that allows no Types as a Value
   * (type notype)
   */
  //class Type_notype {
    template <class T> std::shared_ptr<T> vx_core::Class_notype::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_notype->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_notype::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_notype output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_notype::vx_empty(std::shared_ptr<T> val) {return vx_core::e_notype;}
    template <class T> std::shared_ptr<T> vx_core::Class_notype::vx_type(std::shared_ptr<T> val) {return vx_core::t_notype;}

    vx_core::Type_typedef vx_core::Class_notype::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "notype", // name
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

    vx_core::Type_notype vx_core::e_notype = std::make_shared<vx_core::Class_notype>();
    vx_core::Type_notype vx_core::t_notype = std::make_shared<vx_core::Class_notype>();
  //}

  /**
   * type: numberlist
   * A list of number.
   * (type numberlist)
   */
  //class Type_numberlist {
    vx_core::vx_Type_listany vx_core::Class_numberlist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_core::Type_number vx_core::Class_numberlist::vx_number(vx_core::Type_int index) {
      vx_core::Type_number output = vx_core::e_number;
      vx_core::Class_numberlist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_core::Type_number> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_number> vx_core::Class_numberlist::vx_listnumber() {return vx_p_list;}

    vx_core::Type_any vx_core::Class_numberlist::vx_any(vx_core::Type_int index) {
      return this->vx_number(index);
    }

    template <class T> std::shared_ptr<T> vx_core::Class_numberlist::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_numberlist->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_numberlist::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_numberlist output;
      vx_core::Class_numberlist* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_core::Type_number> listval = val->vx_listnumber();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_number) {
          listval->push_back(vx_core::any_from_any(vx_core::t_number, valsub));
        } else if (valsubtype == vx_core::t_numberlist) {
          vx_core::Type_numberlist multi = vx_core::any_from_any(vx_core::t_numberlist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listnumber());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new numberlist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_numberlist::vx_empty(std::shared_ptr<T> val) {return vx_core::e_numberlist;}
    template <class T> std::shared_ptr<T> vx_core::Class_numberlist::vx_type(std::shared_ptr<T> val) {return vx_core::t_numberlist;}

    vx_core::Type_typedef vx_core::Class_numberlist::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "numberlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_numberlist vx_core::e_numberlist = std::make_shared<vx_core::Class_numberlist>();
    vx_core::Type_numberlist vx_core::t_numberlist = std::make_shared<vx_core::Class_numberlist>();
  //}

  /**
   * type: numbermap
   * A map of number.
   * (type numbermap)
   */
  //class Type_numbermap {
    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_numbermap::vx_map() {
      return vx_core::map_from_map(vx_core::t_any, this->vx_p_map);
    }

    // vx_number(key)
    vx_core::Type_number vx_core::Class_numbermap::vx_number(vx_core::Type_string key) {
      vx_core::Type_number output = vx_core::e_number;
      vx_core::Class_numbermap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_number> mapval = map->vx_p_map;
      output = vx_core::any_from_map(mapval, skey, vx_core::e_number);
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_numbermap::vx_any(vx_core::Type_string key) {
      return this->vx_number(key);
    }

    // vx_mapnumber()
    std::map<std::string, vx_core::Type_number> vx_core::Class_numbermap::vx_mapnumber() {return vx_p_map;}

    // vx_new_from_map(mapval)
    template <class T> std::shared_ptr<T>  vx_core::Class_numbermap::vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval) {
      vx_core::Type_numbermap output;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_core::Type_number> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = vx_core::t_any->vx_type_from_any(val);
        if (valtype == vx_core::t_number) {
          vx_core::Type_number castval = vx_core::any_from_any(vx_core::t_number, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(numbermap) Invalid Value: " + vx_core::string_from_any(val) + "");
          msgblock = vx_core::t_msgblock->vx_copy(vx_core::t_msgblock, {msgblock, msg});
        }
      }
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_numbermap::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_numbermap->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_numbermap::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_numbermap output;
      vx_core::Class_numbermap* valmap = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(valmap, vals);
      std::map<std::string, vx_core::Type_number> mapval;
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
          vx_core::Type_number valany;
          if (valsubtype == vx_core::t_number) {
            valany = vx_core::any_from_any(vx_core::t_number, valsub);
          } else if (valsubtype == vx_core::t_number) {
            valany = vx_core::any_from_any(vx_core::t_number, valsub);
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

    template <class T> std::shared_ptr<T> vx_core::Class_numbermap::vx_empty(std::shared_ptr<T> val) {return vx_core::e_numbermap;}
    template <class T> std::shared_ptr<T> vx_core::Class_numbermap::vx_type(std::shared_ptr<T> val) {return vx_core::t_numbermap;}

    vx_core::Type_typedef vx_core::Class_numbermap::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "numbermap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_numbermap vx_core::e_numbermap = std::make_shared<vx_core::Class_numbermap>();
    vx_core::Type_numbermap vx_core::t_numbermap = std::make_shared<vx_core::Class_numbermap>();
  //}

  /**
   * type: package
   * A package that store types, consts and funcs.
   * (type package)
   */
  //class Type_package {
    // vx_any(key)
    vx_core::Type_any vx_core::Class_package::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_package::vx_map() {
      vx_core::vx_Type_mapany output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_package::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_package->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_package::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_package output;
      vx_core::Class_package* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_package::vx_empty(std::shared_ptr<T> val) {return vx_core::e_package;}
    template <class T> std::shared_ptr<T> vx_core::Class_package::vx_type(std::shared_ptr<T> val) {return vx_core::t_package;}

    vx_core::Type_typedef vx_core::Class_package::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "package", // name
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

    vx_core::Type_package vx_core::e_package = std::make_shared<vx_core::Class_package>();
    vx_core::Type_package vx_core::t_package = std::make_shared<vx_core::Class_package>();
  //}

  /**
   * type: packagemap
   * (type packagemap)
   */
  //class Type_packagemap {
    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_packagemap::vx_map() {
      return vx_core::map_from_map(vx_core::t_any, this->vx_p_map);
    }

    // vx_package(key)
    vx_core::Type_package vx_core::Class_packagemap::vx_package(vx_core::Type_string key) {
      vx_core::Type_package output = vx_core::e_package;
      vx_core::Class_packagemap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_package> mapval = map->vx_p_map;
      output = vx_core::any_from_map(mapval, skey, vx_core::e_package);
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_packagemap::vx_any(vx_core::Type_string key) {
      return this->vx_package(key);
    }

    // vx_mappackage()
    std::map<std::string, vx_core::Type_package> vx_core::Class_packagemap::vx_mappackage() {return vx_p_map;}

    // vx_new_from_map(mapval)
    template <class T> std::shared_ptr<T>  vx_core::Class_packagemap::vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval) {
      vx_core::Type_packagemap output;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_core::Type_package> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = vx_core::t_any->vx_type_from_any(val);
        if (valtype == vx_core::t_package) {
          vx_core::Type_package castval = vx_core::any_from_any(vx_core::t_package, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(packagemap) Invalid Value: " + vx_core::string_from_any(val) + "");
          msgblock = vx_core::t_msgblock->vx_copy(vx_core::t_msgblock, {msgblock, msg});
        }
      }
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_packagemap::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_packagemap->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_packagemap::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_packagemap output;
      vx_core::Class_packagemap* valmap = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(valmap, vals);
      std::map<std::string, vx_core::Type_package> mapval;
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
          vx_core::Type_package valany;
          if (valsubtype == vx_core::t_package) {
            valany = vx_core::any_from_any(vx_core::t_package, valsub);
          } else if (valsubtype == vx_core::t_package) {
            valany = vx_core::any_from_any(vx_core::t_package, valsub);
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

    template <class T> std::shared_ptr<T> vx_core::Class_packagemap::vx_empty(std::shared_ptr<T> val) {return vx_core::e_packagemap;}
    template <class T> std::shared_ptr<T> vx_core::Class_packagemap::vx_type(std::shared_ptr<T> val) {return vx_core::t_packagemap;}

    vx_core::Type_typedef vx_core::Class_packagemap::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "packagemap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_package}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_packagemap vx_core::e_packagemap = std::make_shared<vx_core::Class_packagemap>();
    vx_core::Type_packagemap vx_core::t_packagemap = std::make_shared<vx_core::Class_packagemap>();
  //}

  /**
   * type: permission
   * Permission
   * (type permission)
   */
  //class Type_permission {
    // id()
    vx_core::Type_string vx_core::Class_permission::id() {
      vx_core::Type_string output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_permission::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_permission::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_permission::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_permission->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_permission::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_permission output;
      vx_core::Class_permission* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new permission) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_id = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new permission :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new permission) - Invalid Key: " + key);
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

    template <class T> std::shared_ptr<T> vx_core::Class_permission::vx_empty(std::shared_ptr<T> val) {return vx_core::e_permission;}
    template <class T> std::shared_ptr<T> vx_core::Class_permission::vx_type(std::shared_ptr<T> val) {return vx_core::t_permission;}

    vx_core::Type_typedef vx_core::Class_permission::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "permission", // name
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

    vx_core::Type_permission vx_core::e_permission = std::make_shared<vx_core::Class_permission>();
    vx_core::Type_permission vx_core::t_permission = std::make_shared<vx_core::Class_permission>();
  //}

  /**
   * type: permissionlist
   * List of Permission
   * (type permissionlist)
   */
  //class Type_permissionlist {
    vx_core::vx_Type_listany vx_core::Class_permissionlist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_core::Type_permission vx_core::Class_permissionlist::vx_permission(vx_core::Type_int index) {
      vx_core::Type_permission output = vx_core::e_permission;
      vx_core::Class_permissionlist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_core::Type_permission> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_permission> vx_core::Class_permissionlist::vx_listpermission() {return vx_p_list;}

    vx_core::Type_any vx_core::Class_permissionlist::vx_any(vx_core::Type_int index) {
      return this->vx_permission(index);
    }

    template <class T> std::shared_ptr<T> vx_core::Class_permissionlist::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_permissionlist->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_permissionlist::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_permissionlist output;
      vx_core::Class_permissionlist* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_core::Type_permission> listval = val->vx_listpermission();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_permission) {
          listval->push_back(vx_core::any_from_any(vx_core::t_permission, valsub));
        } else if (valsubtype == vx_core::t_permissionlist) {
          vx_core::Type_permissionlist multi = vx_core::any_from_any(vx_core::t_permissionlist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listpermission());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new permissionlist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_permissionlist::vx_empty(std::shared_ptr<T> val) {return vx_core::e_permissionlist;}
    template <class T> std::shared_ptr<T> vx_core::Class_permissionlist::vx_type(std::shared_ptr<T> val) {return vx_core::t_permissionlist;}

    vx_core::Type_typedef vx_core::Class_permissionlist::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "permissionlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_permission}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_permissionlist vx_core::e_permissionlist = std::make_shared<vx_core::Class_permissionlist>();
    vx_core::Type_permissionlist vx_core::t_permissionlist = std::make_shared<vx_core::Class_permissionlist>();
  //}

  /**
   * type: permissionmap
   * Map of Permission
   * (type permissionmap)
   */
  //class Type_permissionmap {
    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_permissionmap::vx_map() {
      return vx_core::map_from_map(vx_core::t_any, this->vx_p_map);
    }

    // vx_permission(key)
    vx_core::Type_permission vx_core::Class_permissionmap::vx_permission(vx_core::Type_string key) {
      vx_core::Type_permission output = vx_core::e_permission;
      vx_core::Class_permissionmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_permission> mapval = map->vx_p_map;
      output = vx_core::any_from_map(mapval, skey, vx_core::e_permission);
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_permissionmap::vx_any(vx_core::Type_string key) {
      return this->vx_permission(key);
    }

    // vx_mappermission()
    std::map<std::string, vx_core::Type_permission> vx_core::Class_permissionmap::vx_mappermission() {return vx_p_map;}

    // vx_new_from_map(mapval)
    template <class T> std::shared_ptr<T>  vx_core::Class_permissionmap::vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval) {
      vx_core::Type_permissionmap output;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_core::Type_permission> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = vx_core::t_any->vx_type_from_any(val);
        if (valtype == vx_core::t_permission) {
          vx_core::Type_permission castval = vx_core::any_from_any(vx_core::t_permission, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(permissionmap) Invalid Value: " + vx_core::string_from_any(val) + "");
          msgblock = vx_core::t_msgblock->vx_copy(vx_core::t_msgblock, {msgblock, msg});
        }
      }
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_permissionmap::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_permissionmap->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_permissionmap::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_permissionmap output;
      vx_core::Class_permissionmap* valmap = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(valmap, vals);
      std::map<std::string, vx_core::Type_permission> mapval;
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
          vx_core::Type_permission valany;
          if (valsubtype == vx_core::t_permission) {
            valany = vx_core::any_from_any(vx_core::t_permission, valsub);
          } else if (valsubtype == vx_core::t_permission) {
            valany = vx_core::any_from_any(vx_core::t_permission, valsub);
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

    template <class T> std::shared_ptr<T> vx_core::Class_permissionmap::vx_empty(std::shared_ptr<T> val) {return vx_core::e_permissionmap;}
    template <class T> std::shared_ptr<T> vx_core::Class_permissionmap::vx_type(std::shared_ptr<T> val) {return vx_core::t_permissionmap;}

    vx_core::Type_typedef vx_core::Class_permissionmap::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "permissionmap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_permission}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_permissionmap vx_core::e_permissionmap = std::make_shared<vx_core::Class_permissionmap>();
    vx_core::Type_permissionmap vx_core::t_permissionmap = std::make_shared<vx_core::Class_permissionmap>();
  //}

  /**
   * type: security
   * Security rules
   * (type security)
   */
  //class Type_security {
    // permissions()
    vx_core::Type_permissionlist vx_core::Class_security::permissions() {
      vx_core::Type_permissionlist output = this->vx_p_permissions;
      if (output == NULL) {
        output = vx_core::t_permissionlist;
      }
      return output;
    }

    // permissionmap()
    vx_core::Type_permissionmap vx_core::Class_security::permissionmap() {
      vx_core::Type_permissionmap output = this->vx_p_permissionmap;
      if (output == NULL) {
        output = vx_core::t_permissionmap;
      }
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_security::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":permissions") {
        output = this->permissions();
      } else if (skey == ":permissionmap") {
        output = this->permissionmap();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_security::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":permissions"] = this->permissions();
      output[":permissionmap"] = this->permissionmap();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_security::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_security->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_security::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_security output;
      vx_core::Class_security* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_permissions = val->permissions();
      output->vx_p_permissionmap = val->permissionmap();
      std::set<std::string> validkeys;
      validkeys.insert(":permissions");
      validkeys.insert(":permissionmap");
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new security) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":permissions") {
            if (valsubtype == vx_core::t_permissionlist) {
              output->vx_p_permissions = vx_core::any_from_any(vx_core::t_permissionlist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new security :permissions " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":permissionmap") {
            if (valsubtype == vx_core::t_permissionmap) {
              output->vx_p_permissionmap = vx_core::any_from_any(vx_core::t_permissionmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new security :permissionmap " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new security) - Invalid Key: " + key);
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

    template <class T> std::shared_ptr<T> vx_core::Class_security::vx_empty(std::shared_ptr<T> val) {return vx_core::e_security;}
    template <class T> std::shared_ptr<T> vx_core::Class_security::vx_type(std::shared_ptr<T> val) {return vx_core::t_security;}

    vx_core::Type_typedef vx_core::Class_security::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "security", // name
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

    vx_core::Type_security vx_core::e_security = std::make_shared<vx_core::Class_security>();
    vx_core::Type_security vx_core::t_security = std::make_shared<vx_core::Class_security>();
  //}

  /**
   * type: session
   * Session
   * (type session)
   */
  //class Type_session {
    // user()
    vx_core::Type_user vx_core::Class_session::user() {
      vx_core::Type_user output = this->vx_p_user;
      if (output == NULL) {
        output = vx_core::t_user;
      }
      return output;
    }

    // connectlist()
    vx_core::Type_connectlist vx_core::Class_session::connectlist() {
      vx_core::Type_connectlist output = this->vx_p_connectlist;
      if (output == NULL) {
        output = vx_core::t_connectlist;
      }
      return output;
    }

    // connectmap()
    vx_core::Type_connectmap vx_core::Class_session::connectmap() {
      vx_core::Type_connectmap output = this->vx_p_connectmap;
      if (output == NULL) {
        output = vx_core::t_connectmap;
      }
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_session::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":user") {
        output = this->user();
      } else if (skey == ":connectlist") {
        output = this->connectlist();
      } else if (skey == ":connectmap") {
        output = this->connectmap();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_session::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":user"] = this->user();
      output[":connectlist"] = this->connectlist();
      output[":connectmap"] = this->connectmap();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_session::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_session->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_session::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_session output;
      vx_core::Class_session* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_user = val->user();
      output->vx_p_connectlist = val->connectlist();
      output->vx_p_connectmap = val->connectmap();
      std::set<std::string> validkeys;
      validkeys.insert(":user");
      validkeys.insert(":connectlist");
      validkeys.insert(":connectmap");
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new session) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":user") {
            if (valsubtype == vx_core::t_user) {
              output->vx_p_user = vx_core::any_from_any(vx_core::t_user, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new session :user " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":connectlist") {
            if (valsubtype == vx_core::t_connectlist) {
              output->vx_p_connectlist = vx_core::any_from_any(vx_core::t_connectlist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new session :connectlist " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":connectmap") {
            if (valsubtype == vx_core::t_connectmap) {
              output->vx_p_connectmap = vx_core::any_from_any(vx_core::t_connectmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new session :connectmap " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new session) - Invalid Key: " + key);
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

    template <class T> std::shared_ptr<T> vx_core::Class_session::vx_empty(std::shared_ptr<T> val) {return vx_core::e_session;}
    template <class T> std::shared_ptr<T> vx_core::Class_session::vx_type(std::shared_ptr<T> val) {return vx_core::t_session;}

    vx_core::Type_typedef vx_core::Class_session::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "session", // name
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

    vx_core::Type_session vx_core::e_session = std::make_shared<vx_core::Class_session>();
    vx_core::Type_session vx_core::t_session = std::make_shared<vx_core::Class_session>();
  //}

  /**
   * type: setting
   * Settings
   * (type setting)
   */
  //class Type_setting {
    // pathmap()
    vx_core::Type_stringmap vx_core::Class_setting::pathmap() {
      vx_core::Type_stringmap output = this->vx_p_pathmap;
      if (output == NULL) {
        output = vx_core::t_stringmap;
      }
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_setting::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":pathmap") {
        output = this->pathmap();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_setting::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":pathmap"] = this->pathmap();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_setting::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_setting->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_setting::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_setting output;
      vx_core::Class_setting* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_pathmap = val->pathmap();
      std::set<std::string> validkeys;
      validkeys.insert(":pathmap");
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new setting) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":pathmap") {
            if (valsubtype == vx_core::t_stringmap) {
              output->vx_p_pathmap = vx_core::any_from_any(vx_core::t_stringmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new setting :pathmap " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new setting) - Invalid Key: " + key);
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

    template <class T> std::shared_ptr<T> vx_core::Class_setting::vx_empty(std::shared_ptr<T> val) {return vx_core::e_setting;}
    template <class T> std::shared_ptr<T> vx_core::Class_setting::vx_type(std::shared_ptr<T> val) {return vx_core::t_setting;}

    vx_core::Type_typedef vx_core::Class_setting::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "setting", // name
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

    vx_core::Type_setting vx_core::e_setting = std::make_shared<vx_core::Class_setting>();
    vx_core::Type_setting vx_core::t_setting = std::make_shared<vx_core::Class_setting>();
  //}

  /**
   * type: state
   * (type state)
   */
  //class Type_state {
    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_state::vx_map() {
      return vx_core::map_from_map(vx_core::t_any, this->vx_p_map);
    }

    // vx_statelistener(key)
    vx_core::Type_statelistener vx_core::Class_state::vx_statelistener(vx_core::Type_string key) {
      vx_core::Type_statelistener output = vx_core::e_statelistener;
      vx_core::Class_state* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_statelistener> mapval = map->vx_p_map;
      output = vx_core::any_from_map(mapval, skey, vx_core::e_statelistener);
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_state::vx_any(vx_core::Type_string key) {
      return this->vx_statelistener(key);
    }

    // vx_mapstatelistener()
    std::map<std::string, vx_core::Type_statelistener> vx_core::Class_state::vx_mapstatelistener() {return vx_p_map;}

    // vx_new_from_map(mapval)
    template <class T> std::shared_ptr<T>  vx_core::Class_state::vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval) {
      vx_core::Type_state output;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_core::Type_statelistener> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = vx_core::t_any->vx_type_from_any(val);
        if (valtype == vx_core::t_statelistener) {
          vx_core::Type_statelistener castval = vx_core::any_from_any(vx_core::t_statelistener, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(state) Invalid Value: " + vx_core::string_from_any(val) + "");
          msgblock = vx_core::t_msgblock->vx_copy(vx_core::t_msgblock, {msgblock, msg});
        }
      }
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_state::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_state->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_state::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_state output;
      vx_core::Class_state* valmap = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(valmap, vals);
      std::map<std::string, vx_core::Type_statelistener> mapval;
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
          vx_core::Type_statelistener valany;
          if (valsubtype == vx_core::t_statelistener) {
            valany = vx_core::any_from_any(vx_core::t_statelistener, valsub);
          } else if (valsubtype == vx_core::t_statelistener) {
            valany = vx_core::any_from_any(vx_core::t_statelistener, valsub);
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

    template <class T> std::shared_ptr<T> vx_core::Class_state::vx_empty(std::shared_ptr<T> val) {return vx_core::e_state;}
    template <class T> std::shared_ptr<T> vx_core::Class_state::vx_type(std::shared_ptr<T> val) {return vx_core::t_state;}

    vx_core::Type_typedef vx_core::Class_state::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "state", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_statelistener}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_state vx_core::e_state = std::make_shared<vx_core::Class_state>();
    vx_core::Type_state vx_core::t_state = std::make_shared<vx_core::Class_state>();
  //}

  /**
   * type: statelistener
   * (type statelistener)
   */
  //class Type_statelistener {
    // path()
    vx_core::Type_string vx_core::Class_statelistener::path() {
      vx_core::Type_string output = this->vx_p_path;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // value()
    vx_core::Type_any vx_core::Class_statelistener::value() {
      vx_core::Type_any output = this->vx_p_value;
      if (output == NULL) {
        output = vx_core::t_any;
      }
      return output;
    }

    // fn_boolean()
    vx_core::Func_boolean_from_none vx_core::Class_statelistener::fn_boolean() {
      vx_core::Func_boolean_from_none output = this->vx_p_fn_boolean;
      if (output == NULL) {
        output = vx_core::t_boolean_from_none;
      }
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_statelistener::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":path") {
        output = this->path();
      } else if (skey == ":value") {
        output = this->value();
      } else if (skey == ":fn-boolean") {
        output = this->fn_boolean();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_statelistener::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":path"] = this->path();
      output[":value"] = this->value();
      output[":fn-boolean"] = this->fn_boolean();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_statelistener::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_statelistener->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_statelistener::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_statelistener output;
      vx_core::Class_statelistener* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_path = val->path();
      output->vx_p_value = val->value();
      output->vx_p_fn_boolean = val->fn_boolean();
      std::set<std::string> validkeys;
      validkeys.insert(":path");
      validkeys.insert(":value");
      validkeys.insert(":fn-boolean");
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new statelistener) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":path") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_path = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new statelistener :path " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":value") {
            if (valsubtype == vx_core::t_any) {
              output->vx_p_value = vx_core::any_from_any(vx_core::t_any, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new statelistener :value " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":fn-boolean") {
            if (valsubtype == vx_core::t_boolean_from_none) {
              output->vx_p_fn_boolean = vx_core::any_from_any(vx_core::t_boolean_from_none, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new statelistener :fn-boolean " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new statelistener) - Invalid Key: " + key);
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

    template <class T> std::shared_ptr<T> vx_core::Class_statelistener::vx_empty(std::shared_ptr<T> val) {return vx_core::e_statelistener;}
    template <class T> std::shared_ptr<T> vx_core::Class_statelistener::vx_type(std::shared_ptr<T> val) {return vx_core::t_statelistener;}

    vx_core::Type_typedef vx_core::Class_statelistener::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "statelistener", // name
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

    vx_core::Type_statelistener vx_core::e_statelistener = std::make_shared<vx_core::Class_statelistener>();
    vx_core::Type_statelistener vx_core::t_statelistener = std::make_shared<vx_core::Class_statelistener>();
  //}

  /**
   * type: stringlist
   * A list of string.
   * (type stringlist)
   */
  //class Type_stringlist {
    vx_core::vx_Type_listany vx_core::Class_stringlist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_core::Type_string vx_core::Class_stringlist::vx_string(vx_core::Type_int index) {
      vx_core::Type_string output = vx_core::e_string;
      vx_core::Class_stringlist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_core::Type_string> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_string> vx_core::Class_stringlist::vx_liststring() {return vx_p_list;}

    vx_core::Type_any vx_core::Class_stringlist::vx_any(vx_core::Type_int index) {
      return this->vx_string(index);
    }

    template <class T> std::shared_ptr<T> vx_core::Class_stringlist::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_stringlist->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_stringlist::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_stringlist output;
      vx_core::Class_stringlist* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_core::Type_string> listval = val->vx_liststring();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_string) {
          listval->push_back(vx_core::any_from_any(vx_core::t_string, valsub));
        } else if (valsubtype == vx_core::t_stringlist) {
          vx_core::Type_stringlist multi = vx_core::any_from_any(vx_core::t_stringlist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_liststring());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new stringlist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_stringlist::vx_empty(std::shared_ptr<T> val) {return vx_core::e_stringlist;}
    template <class T> std::shared_ptr<T> vx_core::Class_stringlist::vx_type(std::shared_ptr<T> val) {return vx_core::t_stringlist;}

    vx_core::Type_typedef vx_core::Class_stringlist::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "stringlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_string}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_stringlist vx_core::e_stringlist = std::make_shared<vx_core::Class_stringlist>();
    vx_core::Type_stringlist vx_core::t_stringlist = std::make_shared<vx_core::Class_stringlist>();
  //}

  /**
   * type: stringmap
   * A map of string.
   * (type stringmap)
   */
  //class Type_stringmap {
    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_stringmap::vx_map() {
      return vx_core::map_from_map(vx_core::t_any, this->vx_p_map);
    }

    // vx_string(key)
    vx_core::Type_string vx_core::Class_stringmap::vx_string(vx_core::Type_string key) {
      vx_core::Type_string output = vx_core::e_string;
      vx_core::Class_stringmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_string> mapval = map->vx_p_map;
      output = vx_core::any_from_map(mapval, skey, vx_core::e_string);
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_stringmap::vx_any(vx_core::Type_string key) {
      return this->vx_string(key);
    }

    // vx_mapstring()
    std::map<std::string, vx_core::Type_string> vx_core::Class_stringmap::vx_mapstring() {return vx_p_map;}

    // vx_new_from_map(mapval)
    template <class T> std::shared_ptr<T>  vx_core::Class_stringmap::vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval) {
      vx_core::Type_stringmap output;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_core::Type_string> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = vx_core::t_any->vx_type_from_any(val);
        if (valtype == vx_core::t_string) {
          vx_core::Type_string castval = vx_core::any_from_any(vx_core::t_string, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(stringmap) Invalid Value: " + vx_core::string_from_any(val) + "");
          msgblock = vx_core::t_msgblock->vx_copy(vx_core::t_msgblock, {msgblock, msg});
        }
      }
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_stringmap::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_stringmap->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_stringmap::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_stringmap output;
      vx_core::Class_stringmap* valmap = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(valmap, vals);
      std::map<std::string, vx_core::Type_string> mapval;
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
          vx_core::Type_string valany;
          if (valsubtype == vx_core::t_string) {
            valany = vx_core::any_from_any(vx_core::t_string, valsub);
          } else if (valsubtype == vx_core::t_string) {
            valany = vx_core::any_from_any(vx_core::t_string, valsub);
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

    template <class T> std::shared_ptr<T> vx_core::Class_stringmap::vx_empty(std::shared_ptr<T> val) {return vx_core::e_stringmap;}
    template <class T> std::shared_ptr<T> vx_core::Class_stringmap::vx_type(std::shared_ptr<T> val) {return vx_core::t_stringmap;}

    vx_core::Type_typedef vx_core::Class_stringmap::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "stringmap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_string}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_stringmap vx_core::e_stringmap = std::make_shared<vx_core::Class_stringmap>();
    vx_core::Type_stringmap vx_core::t_stringmap = std::make_shared<vx_core::Class_stringmap>();
  //}

  /**
   * type: thenelse
   * (type thenelse)
   */
  //class Type_thenelse {
    // code()
    vx_core::Type_string vx_core::Class_thenelse::code() {
      vx_core::Type_string output = this->vx_p_code;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // value()
    vx_core::Type_any vx_core::Class_thenelse::value() {
      vx_core::Type_any output = this->vx_p_value;
      if (output == NULL) {
        output = vx_core::t_any;
      }
      return output;
    }

    // values()
    vx_core::Type_list vx_core::Class_thenelse::values() {
      vx_core::Type_list output = this->vx_p_values;
      if (output == NULL) {
        output = vx_core::t_list;
      }
      return output;
    }

    // fn_cond()
    vx_core::Func_boolean_from_func vx_core::Class_thenelse::fn_cond() {
      vx_core::Func_boolean_from_func output = this->vx_p_fn_cond;
      if (output == NULL) {
        output = vx_core::t_boolean_from_func;
      }
      return output;
    }

    // fn_any()
    vx_core::Func_any_from_func vx_core::Class_thenelse::fn_any() {
      vx_core::Func_any_from_func output = this->vx_p_fn_any;
      if (output == NULL) {
        output = vx_core::t_any_from_func;
      }
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_thenelse::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":code") {
        output = this->code();
      } else if (skey == ":value") {
        output = this->value();
      } else if (skey == ":values") {
        output = this->values();
      } else if (skey == ":fn-cond") {
        output = this->fn_cond();
      } else if (skey == ":fn-any") {
        output = this->fn_any();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_thenelse::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":code"] = this->code();
      output[":value"] = this->value();
      output[":values"] = this->values();
      output[":fn-cond"] = this->fn_cond();
      output[":fn-any"] = this->fn_any();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_thenelse::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_thenelse->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_thenelse::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_thenelse output;
      vx_core::Class_thenelse* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_code = val->code();
      output->vx_p_value = val->value();
      output->vx_p_values = val->values();
      output->vx_p_fn_cond = val->fn_cond();
      output->vx_p_fn_any = val->fn_any();
      std::set<std::string> validkeys;
      validkeys.insert(":code");
      validkeys.insert(":value");
      validkeys.insert(":values");
      validkeys.insert(":fn-cond");
      validkeys.insert(":fn-any");
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new thenelse) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":code") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_code = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new thenelse :code " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":value") {
            if (valsubtype == vx_core::t_any) {
              output->vx_p_value = vx_core::any_from_any(vx_core::t_any, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new thenelse :value " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":values") {
            if (valsubtype == vx_core::t_list) {
              output->vx_p_values = vx_core::any_from_any(vx_core::t_list, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new thenelse :values " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":fn-cond") {
            if (valsubtype == vx_core::t_boolean_from_func) {
              output->vx_p_fn_cond = vx_core::any_from_any(vx_core::t_boolean_from_func, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new thenelse :fn-cond " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":fn-any") {
            if (valsubtype == vx_core::t_any_from_func) {
              output->vx_p_fn_any = vx_core::any_from_any(vx_core::t_any_from_func, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new thenelse :fn-any " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new thenelse) - Invalid Key: " + key);
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

    template <class T> std::shared_ptr<T> vx_core::Class_thenelse::vx_empty(std::shared_ptr<T> val) {return vx_core::e_thenelse;}
    template <class T> std::shared_ptr<T> vx_core::Class_thenelse::vx_type(std::shared_ptr<T> val) {return vx_core::t_thenelse;}

    vx_core::Type_typedef vx_core::Class_thenelse::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "thenelse", // name
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

    vx_core::Type_thenelse vx_core::e_thenelse = std::make_shared<vx_core::Class_thenelse>();
    vx_core::Type_thenelse vx_core::t_thenelse = std::make_shared<vx_core::Class_thenelse>();
  //}

  /**
   * type: thenelselist
   * (type thenelselist)
   */
  //class Type_thenelselist {
    vx_core::vx_Type_listany vx_core::Class_thenelselist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_core::Type_thenelse vx_core::Class_thenelselist::vx_thenelse(vx_core::Type_int index) {
      vx_core::Type_thenelse output = vx_core::e_thenelse;
      vx_core::Class_thenelselist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_core::Type_thenelse> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_thenelse> vx_core::Class_thenelselist::vx_listthenelse() {return vx_p_list;}

    vx_core::Type_any vx_core::Class_thenelselist::vx_any(vx_core::Type_int index) {
      return this->vx_thenelse(index);
    }

    template <class T> std::shared_ptr<T> vx_core::Class_thenelselist::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_thenelselist->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_thenelselist::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_thenelselist output;
      vx_core::Class_thenelselist* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_core::Type_thenelse> listval = val->vx_listthenelse();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_thenelse) {
          listval->push_back(vx_core::any_from_any(vx_core::t_thenelse, valsub));
        } else if (valsubtype == vx_core::t_thenelselist) {
          vx_core::Type_thenelselist multi = vx_core::any_from_any(vx_core::t_thenelselist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listthenelse());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new thenelselist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_thenelselist::vx_empty(std::shared_ptr<T> val) {return vx_core::e_thenelselist;}
    template <class T> std::shared_ptr<T> vx_core::Class_thenelselist::vx_type(std::shared_ptr<T> val) {return vx_core::t_thenelselist;}

    vx_core::Type_typedef vx_core::Class_thenelselist::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "thenelselist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_thenelse}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_core::Type_thenelselist vx_core::e_thenelselist = std::make_shared<vx_core::Class_thenelselist>();
    vx_core::Type_thenelselist vx_core::t_thenelselist = std::make_shared<vx_core::Class_thenelselist>();
  //}

  /**
   * type: type
   * Original Type Class
   * (type type)
   */
  //class Type_type {
    template <class T> std::shared_ptr<T> vx_core::Class_type::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_type->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_type::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_type output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_type::vx_empty(std::shared_ptr<T> val) {return vx_core::e_type;}
    template <class T> std::shared_ptr<T> vx_core::Class_type::vx_type(std::shared_ptr<T> val) {return vx_core::t_type;}

    vx_core::Type_typedef vx_core::Class_type::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "type", // name
        ":type", // extends
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

    vx_core::Type_type vx_core::e_type = std::make_shared<vx_core::Class_type>();
    vx_core::Type_type vx_core::t_type = std::make_shared<vx_core::Class_type>();
  //}

  /**
   * type: typedef
   * Type Definition Class for inspecting Type properties.
   * (type typedef)
   */
  //class Type_typedef {
    // pkgname()
    vx_core::Type_string vx_core::Class_typedef::pkgname() {
      vx_core::Type_string output = this->vx_p_pkgname;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // name()
    vx_core::Type_string vx_core::Class_typedef::name() {
      vx_core::Type_string output = this->vx_p_name;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // extend()
    vx_core::Type_string vx_core::Class_typedef::extend() {
      vx_core::Type_string output = this->vx_p_extend;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // allowfuncs()
    vx_core::Type_funclist vx_core::Class_typedef::allowfuncs() {
      vx_core::Type_funclist output = this->vx_p_allowfuncs;
      if (output == NULL) {
        output = vx_core::t_funclist;
      }
      return output;
    }

    // allowtypes()
    vx_core::Type_typelist vx_core::Class_typedef::allowtypes() {
      vx_core::Type_typelist output = this->vx_p_allowtypes;
      if (output == NULL) {
        output = vx_core::t_typelist;
      }
      return output;
    }

    // allowvalues()
    vx_core::Type_anylist vx_core::Class_typedef::allowvalues() {
      vx_core::Type_anylist output = this->vx_p_allowvalues;
      if (output == NULL) {
        output = vx_core::t_anylist;
      }
      return output;
    }

    // disallowfuncs()
    vx_core::Type_funclist vx_core::Class_typedef::disallowfuncs() {
      vx_core::Type_funclist output = this->vx_p_disallowfuncs;
      if (output == NULL) {
        output = vx_core::t_funclist;
      }
      return output;
    }

    // disallowtypes()
    vx_core::Type_typelist vx_core::Class_typedef::disallowtypes() {
      vx_core::Type_typelist output = this->vx_p_disallowtypes;
      if (output == NULL) {
        output = vx_core::t_typelist;
      }
      return output;
    }

    // disallowvalues()
    vx_core::Type_anylist vx_core::Class_typedef::disallowvalues() {
      vx_core::Type_anylist output = this->vx_p_disallowvalues;
      if (output == NULL) {
        output = vx_core::t_anylist;
      }
      return output;
    }

    // properties()
    vx_core::Type_argmap vx_core::Class_typedef::properties() {
      vx_core::Type_argmap output = this->vx_p_properties;
      if (output == NULL) {
        output = vx_core::t_argmap;
      }
      return output;
    }

    // proplast()
    vx_core::Type_arg vx_core::Class_typedef::proplast() {
      vx_core::Type_arg output = this->vx_p_proplast;
      if (output == NULL) {
        output = vx_core::t_arg;
      }
      return output;
    }

    // traits()
    vx_core::Type_typelist vx_core::Class_typedef::traits() {
      vx_core::Type_typelist output = this->vx_p_traits;
      if (output == NULL) {
        output = vx_core::t_typelist;
      }
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_typedef::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":pkgname") {
        output = this->pkgname();
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":extends") {
        output = this->extend();
      } else if (skey == ":allowfuncs") {
        output = this->allowfuncs();
      } else if (skey == ":allowtypes") {
        output = this->allowtypes();
      } else if (skey == ":allowvalues") {
        output = this->allowvalues();
      } else if (skey == ":disallowfuncs") {
        output = this->disallowfuncs();
      } else if (skey == ":disallowtypes") {
        output = this->disallowtypes();
      } else if (skey == ":disallowvalues") {
        output = this->disallowvalues();
      } else if (skey == ":properties") {
        output = this->properties();
      } else if (skey == ":proplast") {
        output = this->proplast();
      } else if (skey == ":traits") {
        output = this->traits();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_typedef::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":pkgname"] = this->pkgname();
      output[":name"] = this->name();
      output[":extends"] = this->extend();
      output[":allowfuncs"] = this->allowfuncs();
      output[":allowtypes"] = this->allowtypes();
      output[":allowvalues"] = this->allowvalues();
      output[":disallowfuncs"] = this->disallowfuncs();
      output[":disallowtypes"] = this->disallowtypes();
      output[":disallowvalues"] = this->disallowvalues();
      output[":properties"] = this->properties();
      output[":proplast"] = this->proplast();
      output[":traits"] = this->traits();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_typedef::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_typedef->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_typedef::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_typedef output;
      vx_core::Class_typedef* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_pkgname = val->pkgname();
      output->vx_p_name = val->name();
      output->vx_p_extend = val->extend();
      output->vx_p_allowfuncs = val->allowfuncs();
      output->vx_p_allowtypes = val->allowtypes();
      output->vx_p_allowvalues = val->allowvalues();
      output->vx_p_disallowfuncs = val->disallowfuncs();
      output->vx_p_disallowtypes = val->disallowtypes();
      output->vx_p_disallowvalues = val->disallowvalues();
      output->vx_p_properties = val->properties();
      output->vx_p_proplast = val->proplast();
      output->vx_p_traits = val->traits();
      std::set<std::string> validkeys;
      validkeys.insert(":pkgname");
      validkeys.insert(":name");
      validkeys.insert(":extends");
      validkeys.insert(":allowfuncs");
      validkeys.insert(":allowtypes");
      validkeys.insert(":allowvalues");
      validkeys.insert(":disallowfuncs");
      validkeys.insert(":disallowtypes");
      validkeys.insert(":disallowvalues");
      validkeys.insert(":properties");
      validkeys.insert(":proplast");
      validkeys.insert(":traits");
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new typedef) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":pkgname") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_pkgname = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new typedef :pkgname " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_name = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new typedef :name " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":extends") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_extend = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new typedef :extends " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":allowfuncs") {
            if (valsubtype == vx_core::t_funclist) {
              output->vx_p_allowfuncs = vx_core::any_from_any(vx_core::t_funclist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new typedef :allowfuncs " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":allowtypes") {
            if (valsubtype == vx_core::t_typelist) {
              output->vx_p_allowtypes = vx_core::any_from_any(vx_core::t_typelist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new typedef :allowtypes " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":allowvalues") {
            if (valsubtype == vx_core::t_anylist) {
              output->vx_p_allowvalues = vx_core::any_from_any(vx_core::t_anylist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new typedef :allowvalues " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":disallowfuncs") {
            if (valsubtype == vx_core::t_funclist) {
              output->vx_p_disallowfuncs = vx_core::any_from_any(vx_core::t_funclist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new typedef :disallowfuncs " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":disallowtypes") {
            if (valsubtype == vx_core::t_typelist) {
              output->vx_p_disallowtypes = vx_core::any_from_any(vx_core::t_typelist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new typedef :disallowtypes " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":disallowvalues") {
            if (valsubtype == vx_core::t_anylist) {
              output->vx_p_disallowvalues = vx_core::any_from_any(vx_core::t_anylist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new typedef :disallowvalues " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":properties") {
            if (valsubtype == vx_core::t_argmap) {
              output->vx_p_properties = vx_core::any_from_any(vx_core::t_argmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new typedef :properties " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":proplast") {
            if (valsubtype == vx_core::t_arg) {
              output->vx_p_proplast = vx_core::any_from_any(vx_core::t_arg, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new typedef :proplast " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":traits") {
            if (valsubtype == vx_core::t_typelist) {
              output->vx_p_traits = vx_core::any_from_any(vx_core::t_typelist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new typedef :traits " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new typedef) - Invalid Key: " + key);
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

    template <class T> std::shared_ptr<T> vx_core::Class_typedef::vx_empty(std::shared_ptr<T> val) {return vx_core::e_typedef;}
    template <class T> std::shared_ptr<T> vx_core::Class_typedef::vx_type(std::shared_ptr<T> val) {return vx_core::t_typedef;}

    vx_core::Type_typedef vx_core::Class_typedef::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "typedef", // name
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

    vx_core::Type_typedef vx_core::e_typedef = std::make_shared<vx_core::Class_typedef>();
    vx_core::Type_typedef vx_core::t_typedef = std::make_shared<vx_core::Class_typedef>();
  //}

  /**
   * type: typelist
   * List of Types
   * (type typelist)
   */
  //class Type_typelist {
    vx_core::vx_Type_listany vx_core::Class_typelist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_core::Type_any vx_core::Class_typelist::vx_any(vx_core::Type_int index) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Class_typelist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_core::Type_any> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_typelist::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_typelist->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_typelist::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_typelist output;
      vx_core::Class_typelist* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_core::Type_any> listval = val->vx_list();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_any) {
          listval->push_back(vx_core::any_from_any(vx_core::t_any, valsub));
        } else if (valsubtype == vx_core::t_typelist) {
          vx_core::Type_typelist multi = vx_core::any_from_any(vx_core::t_typelist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_list());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new typelist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_typelist::vx_empty(std::shared_ptr<T> val) {return vx_core::e_typelist;}
    template <class T> std::shared_ptr<T> vx_core::Class_typelist::vx_type(std::shared_ptr<T> val) {return vx_core::t_typelist;}

    vx_core::Type_typedef vx_core::Class_typelist::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "typelist", // name
        ":list", // extends
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

    vx_core::Type_typelist vx_core::e_typelist = std::make_shared<vx_core::Class_typelist>();
    vx_core::Type_typelist vx_core::t_typelist = std::make_shared<vx_core::Class_typelist>();
  //}

  /**
   * type: typemap
   * Map of Any Type Class
   * (type typemap)
   */
  //class Type_typemap {
    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_typemap::vx_map() {
      return vx_core::map_from_map(vx_core::t_any, this->vx_p_map);
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_typemap::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Class_typemap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_any> mapval = map->vx_p_map;
      output = vx_core::any_from_map(mapval, skey, vx_core::e_any);
      return output;
    }

    // vx_new_from_map(mapval)
    template <class T> std::shared_ptr<T>  vx_core::Class_typemap::vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval) {
      vx_core::Type_typemap output;
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
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(typemap) Invalid Value: " + vx_core::string_from_any(val) + "");
          msgblock = vx_core::t_msgblock->vx_copy(vx_core::t_msgblock, {msgblock, msg});
        }
      }
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_typemap::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_typemap->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_typemap::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_typemap output;
      vx_core::Class_typemap* valmap = this;
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

    template <class T> std::shared_ptr<T> vx_core::Class_typemap::vx_empty(std::shared_ptr<T> val) {return vx_core::e_typemap;}
    template <class T> std::shared_ptr<T> vx_core::Class_typemap::vx_type(std::shared_ptr<T> val) {return vx_core::t_typemap;}

    vx_core::Type_typedef vx_core::Class_typemap::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "typemap", // name
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

    vx_core::Type_typemap vx_core::e_typemap = std::make_shared<vx_core::Class_typemap>();
    vx_core::Type_typemap vx_core::t_typemap = std::make_shared<vx_core::Class_typemap>();
  //}

  /**
   * type: user
   * User Type
   * (type user)
   */
  //class Type_user {
    // security()
    vx_core::Type_security vx_core::Class_user::security() {
      vx_core::Type_security output = this->vx_p_security;
      if (output == NULL) {
        output = vx_core::t_security;
      }
      return output;
    }

    // username()
    vx_core::Type_string vx_core::Class_user::username() {
      vx_core::Type_string output = this->vx_p_username;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // token()
    vx_core::Type_string vx_core::Class_user::token() {
      vx_core::Type_string output = this->vx_p_token;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_user::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":security") {
        output = this->security();
      } else if (skey == ":username") {
        output = this->username();
      } else if (skey == ":token") {
        output = this->token();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_user::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":security"] = this->security();
      output[":username"] = this->username();
      output[":token"] = this->token();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_user::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_user->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_user::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_user output;
      vx_core::Class_user* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_security = val->security();
      output->vx_p_username = val->username();
      output->vx_p_token = val->token();
      std::set<std::string> validkeys;
      validkeys.insert(":security");
      validkeys.insert(":username");
      validkeys.insert(":token");
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new user) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":security") {
            if (valsubtype == vx_core::t_security) {
              output->vx_p_security = vx_core::any_from_any(vx_core::t_security, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new user :security " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":username") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_username = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new user :username " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":token") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_token = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new user :token " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new user) - Invalid Key: " + key);
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

    template <class T> std::shared_ptr<T> vx_core::Class_user::vx_empty(std::shared_ptr<T> val) {return vx_core::e_user;}
    template <class T> std::shared_ptr<T> vx_core::Class_user::vx_type(std::shared_ptr<T> val) {return vx_core::t_user;}

    vx_core::Type_typedef vx_core::Class_user::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "user", // name
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

    vx_core::Type_user vx_core::e_user = std::make_shared<vx_core::Class_user>();
    vx_core::Type_user vx_core::t_user = std::make_shared<vx_core::Class_user>();
  //}

  /**
   * type: value
   * (type value)
   */
  //class Type_value {
    // next()
    vx_core::Type_any vx_core::Class_value::next() {
      vx_core::Type_any output = this->vx_p_next;
      if (output == NULL) {
        output = vx_core::t_any;
      }
      return output;
    }

    // refs()
    vx_core::Type_int vx_core::Class_value::refs() {
      vx_core::Type_int output = this->vx_p_refs;
      if (output == NULL) {
        output = vx_core::t_int;
      }
      return output;
    }

    // vx_any(key)
    vx_core::Type_any vx_core::Class_value::vx_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":next") {
        output = this->next();
      } else if (skey == ":refs") {
        output = this->refs();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_core::Class_value::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":next"] = this->next();
      output[":refs"] = this->refs();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_value::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_core::e_value->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_core::Class_value::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Type_value output;
      vx_core::Class_value* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_next = val->next();
      output->vx_p_refs = val->refs();
      std::set<std::string> validkeys;
      validkeys.insert(":next");
      validkeys.insert(":refs");
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new value) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":next") {
            if (valsubtype == vx_core::t_any) {
              output->vx_p_next = vx_core::any_from_any(vx_core::t_any, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new value :next " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":refs") {
            if (valsubtype == vx_core::t_int) {
              output->vx_p_refs = vx_core::any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new value :refs " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new value) - Invalid Key: " + key);
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

    template <class T> std::shared_ptr<T> vx_core::Class_value::vx_empty(std::shared_ptr<T> val) {return vx_core::e_value;}
    template <class T> std::shared_ptr<T> vx_core::Class_value::vx_type(std::shared_ptr<T> val) {return vx_core::t_value;}

    vx_core::Type_typedef vx_core::Class_value::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "value", // name
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

    vx_core::Type_value vx_core::e_value = std::make_shared<vx_core::Class_value>();
    vx_core::Type_value vx_core::t_value = std::make_shared<vx_core::Class_value>();
  //}

  /**
   * Constant: false
   * {boolean}
   */
  //class Class_false {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_false::vx_constdef() {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "false", // name
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
        )
      );
    }

    // vx_const_new()
    vx_core::Const_false vx_core::Class_false::vx_const_new() {
      vx_core::Const_false output = std::shared_ptr<vx_core::Class_false>();
      return output;
    }

    bool vx_core::Class_false::vx_boolean() {
      this->vx_p_boolean = false;
      return this->vx_p_boolean;
    }

  //}

  vx_core::Const_false vx_core::c_false = vx_core::Class_false::vx_const_new();


  /**
   * Constant: globalpackagemap
   * {packagemap}
   */
  //class Class_globalpackagemap {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_globalpackagemap::vx_constdef() {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "globalpackagemap", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "packagemap", // name
          ":map", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_package}), // allowtypes
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
    vx_core::Const_globalpackagemap vx_core::Class_globalpackagemap::vx_const_new() {
      vx_core::Const_globalpackagemap output = std::shared_ptr<vx_core::Class_globalpackagemap>();
      return output;
    }


  //}

  vx_core::Const_globalpackagemap vx_core::c_globalpackagemap = vx_core::Class_globalpackagemap::vx_const_new();


  /**
   * Constant: infinity
   * Infinity. Returned during unusual calculations.
   * {int}
   */
  //class Class_infinity {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_infinity::vx_constdef() {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "infinity", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // traits
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
    vx_core::Const_infinity vx_core::Class_infinity::vx_const_new() {
      vx_core::Const_infinity output = std::shared_ptr<vx_core::Class_infinity>();
      return output;
    }

    int vx_core::Class_infinity::vx_int() {
      this->vx_p_int = 0;
      return this->vx_p_int;
    }

  //}

  vx_core::Const_infinity vx_core::c_infinity = vx_core::Class_infinity::vx_const_new();


  /**
   * Constant: mempool-active
   * Active Value Memory Pool
   * {mempool}
   */
  //class Class_mempool_active {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_mempool_active::vx_constdef() {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "mempool-active", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "mempool", // name
          ":struct", // extends
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
    vx_core::Const_mempool_active vx_core::Class_mempool_active::vx_const_new() {
      vx_core::Const_mempool_active output = std::shared_ptr<vx_core::Class_mempool_active>();
      return output;
    }


  //}

  vx_core::Const_mempool_active vx_core::c_mempool_active = vx_core::Class_mempool_active::vx_const_new();


  /**
   * Constant: msg-error
   * Message is an Error
   * {int}
   */
  //class Class_msg_error {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_msg_error::vx_constdef() {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "msg-error", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // traits
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
    vx_core::Const_msg_error vx_core::Class_msg_error::vx_const_new() {
      vx_core::Const_msg_error output = std::shared_ptr<vx_core::Class_msg_error>();
      return output;
    }

    int vx_core::Class_msg_error::vx_int() {
      this->vx_p_int = 2;
      return this->vx_p_int;
    }

  //}

  vx_core::Const_msg_error vx_core::c_msg_error = vx_core::Class_msg_error::vx_const_new();


  /**
   * Constant: msg-info
   * Message is just information
   * {int}
   */
  //class Class_msg_info {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_msg_info::vx_constdef() {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "msg-info", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // traits
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
    vx_core::Const_msg_info vx_core::Class_msg_info::vx_const_new() {
      vx_core::Const_msg_info output = std::shared_ptr<vx_core::Class_msg_info>();
      return output;
    }

    int vx_core::Class_msg_info::vx_int() {
      this->vx_p_int = 0;
      return this->vx_p_int;
    }

  //}

  vx_core::Const_msg_info vx_core::c_msg_info = vx_core::Class_msg_info::vx_const_new();


  /**
   * Constant: msg-severe
   * Message is a Severe Error
   * {int}
   */
  //class Class_msg_severe {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_msg_severe::vx_constdef() {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "msg-severe", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // traits
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
    vx_core::Const_msg_severe vx_core::Class_msg_severe::vx_const_new() {
      vx_core::Const_msg_severe output = std::shared_ptr<vx_core::Class_msg_severe>();
      return output;
    }

    int vx_core::Class_msg_severe::vx_int() {
      this->vx_p_int = 3;
      return this->vx_p_int;
    }

  //}

  vx_core::Const_msg_severe vx_core::c_msg_severe = vx_core::Class_msg_severe::vx_const_new();


  /**
   * Constant: msg-warning
   * Message is a Warning
   * {int}
   */
  //class Class_msg_warning {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_msg_warning::vx_constdef() {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "msg-warning", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // traits
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
    vx_core::Const_msg_warning vx_core::Class_msg_warning::vx_const_new() {
      vx_core::Const_msg_warning output = std::shared_ptr<vx_core::Class_msg_warning>();
      return output;
    }

    int vx_core::Class_msg_warning::vx_int() {
      this->vx_p_int = 1;
      return this->vx_p_int;
    }

  //}

  vx_core::Const_msg_warning vx_core::c_msg_warning = vx_core::Class_msg_warning::vx_const_new();


  /**
   * Constant: neginfinity
   * Negative Infinity. Returned during unusual calculations.
   * {int}
   */
  //class Class_neginfinity {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_neginfinity::vx_constdef() {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "neginfinity", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // traits
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
    vx_core::Const_neginfinity vx_core::Class_neginfinity::vx_const_new() {
      vx_core::Const_neginfinity output = std::shared_ptr<vx_core::Class_neginfinity>();
      return output;
    }

    int vx_core::Class_neginfinity::vx_int() {
      this->vx_p_int = 0;
      return this->vx_p_int;
    }

  //}

  vx_core::Const_neginfinity vx_core::c_neginfinity = vx_core::Class_neginfinity::vx_const_new();


  /**
   * Constant: newline
   * New line constant
   * {string}
   */
  //class Class_newline {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_newline::vx_constdef() {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "newline", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
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
    vx_core::Const_newline vx_core::Class_newline::vx_const_new() {
      vx_core::Const_newline output = std::shared_ptr<vx_core::Class_newline>();
      return output;
    }

    std::string vx_core::Class_newline::vx_string() {
      this->vx_p_string = "\n";
      return this->vx_p_string;
    }

  //}

  vx_core::Const_newline vx_core::c_newline = vx_core::Class_newline::vx_const_new();


  /**
   * Constant: notanumber
   * Not a number. Returned during invalid calculations.
   * {int}
   */
  //class Class_notanumber {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_notanumber::vx_constdef() {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "notanumber", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // traits
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
    vx_core::Const_notanumber vx_core::Class_notanumber::vx_const_new() {
      vx_core::Const_notanumber output = std::shared_ptr<vx_core::Class_notanumber>();
      return output;
    }

    int vx_core::Class_notanumber::vx_int() {
      this->vx_p_int = 0;
      return this->vx_p_int;
    }

  //}

  vx_core::Const_notanumber vx_core::c_notanumber = vx_core::Class_notanumber::vx_const_new();


  /**
   * Constant: nothing
   * Nothing Value. Opposite of every other value. e.g. Nil, Null
   * {string}
   */
  //class Class_nothing {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_nothing::vx_constdef() {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "nothing", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
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
    vx_core::Const_nothing vx_core::Class_nothing::vx_const_new() {
      vx_core::Const_nothing output = std::shared_ptr<vx_core::Class_nothing>();
      return output;
    }

    std::string vx_core::Class_nothing::vx_string() {
      this->vx_p_string = "nothing";
      return this->vx_p_string;
    }

  //}

  vx_core::Const_nothing vx_core::c_nothing = vx_core::Class_nothing::vx_const_new();


  /**
   * Constant: quote
   * Quotation mark constant
   * {string}
   */
  //class Class_quote {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_quote::vx_constdef() {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "quote", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
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
    vx_core::Const_quote vx_core::Class_quote::vx_const_new() {
      vx_core::Const_quote output = std::shared_ptr<vx_core::Class_quote>();
      return output;
    }

    std::string vx_core::Class_quote::vx_string() {
      this->vx_p_string = "\"";
      return this->vx_p_string;
    }

  //}

  vx_core::Const_quote vx_core::c_quote = vx_core::Class_quote::vx_const_new();


  /**
   * Constant: true
   * {boolean}
   */
  //class Class_true {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_true::vx_constdef() {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "true", // name
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
        )
      );
    }

    // vx_const_new()
    vx_core::Const_true vx_core::Class_true::vx_const_new() {
      vx_core::Const_true output = std::shared_ptr<vx_core::Class_true>();
      return output;
    }

    bool vx_core::Class_true::vx_boolean() {
      this->vx_p_boolean = true;
      return this->vx_p_boolean;
    }

  //}

  vx_core::Const_true vx_core::c_true = vx_core::Class_true::vx_const_new();

  /**
   * @function any_from_any
   * Function Type taking any value any-2 and returning generic any-1
   * @param  {any-2} value
   * @return {any-1}
   * (func any<-any)
   */
  //class Func_any_from_any {

    vx_core::Func_any_from_any vx_core::Class_any_from_any::fn_new(vx_core::Class_any_from_any::IFn fn) {
      vx_core::Func_any_from_any output;
      output->fn = fn;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_any::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_any output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_any::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_any output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_any_from_any::vx_typedef() {return vx_core::t_any_from_any->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_any_from_any::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-any", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_any::vx_empty(std::shared_ptr<T> val) {return vx_core::e_any_from_any;}
    template <class T> std::shared_ptr<T> vx_core::Class_any_from_any::vx_type(std::shared_ptr<T> val) {return vx_core::t_any_from_any;}

    vx_core::Type_any vx_core::Class_any_from_any::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any value = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_any_from_any(generic_any_1, value);
      return output;
    }

    template <class T, class U> std::shared_ptr<T> vx_core::Class_any_from_any::vx_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      if (fn != NULL) {
        output = vx_core::f_any_from_any(generic_any_1, fn(value));
      }
      return output;
    }

  //}

  vx_core::Func_any_from_any vx_core::e_any_from_any = std::make_shared<vx_core::Class_any_from_any>();
  vx_core::Func_any_from_any vx_core::t_any_from_any = std::make_shared<vx_core::Class_any_from_any>();

  template <class T, class U> std::shared_ptr<T> vx_core::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    return output;
  }

  /**
   * @function any_from_func
   * Function Type returning Generic any-1 with any parameters
   * @return {any-1}
   * (func any<-func)
   */
  //class Func_any_from_func {

    vx_core::Func_any_from_func vx_core::Class_any_from_func::fn_new(vx_core::Class_any_from_func::IFn fn) {
      vx_core::Func_any_from_func output;
      output->fn = fn;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_func::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_func output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_func::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_func output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_any_from_func::vx_typedef() {return vx_core::t_any_from_func->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_any_from_func::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-func", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_func::vx_empty(std::shared_ptr<T> val) {return vx_core::e_any_from_func;}
    template <class T> std::shared_ptr<T> vx_core::Class_any_from_func::vx_type(std::shared_ptr<T> val) {return vx_core::t_any_from_func;}

    vx_core::Type_any vx_core::Class_any_from_func::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_any_from_func(generic_any_1);
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_func::vx_any_from_func(std::shared_ptr<T> generic_any_1) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      if (fn != NULL) {
        output = vx_core::f_any_from_any(generic_any_1, fn());
      }
      return output;
    }

  //}

  vx_core::Func_any_from_func vx_core::e_any_from_func = std::make_shared<vx_core::Class_any_from_func>();
  vx_core::Func_any_from_func vx_core::t_any_from_func = std::make_shared<vx_core::Class_any_from_func>();

  template <class T> std::shared_ptr<T> vx_core::f_any_from_func(std::shared_ptr<T> generic_any_1) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    return output;
  }

  /**
   * @function not
   * Boolean not
   * @param  {boolean} val Thing to not
   * @return {boolean}
   * (func !)
   */
  //class Func_not {

    template <class T> std::shared_ptr<T> vx_core::Class_not::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_not output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_not::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_not output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_not::vx_typedef() {return vx_core::t_not->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_not::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "!", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_not::vx_empty(std::shared_ptr<T> val) {return vx_core::e_not;}
    template <class T> std::shared_ptr<T> vx_core::Class_not::vx_type(std::shared_ptr<T> val) {return vx_core::t_not;}

    vx_core::Func_any_from_any vx_core::Class_not::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_not::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_boolean inputval = (vx_core::Type_boolean)value;
      vx_core::Type_any outputval = vx_core::f_not(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_not::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_boolean val = vx_core::f_any_from_any(vx_core::t_boolean, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_not(val);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_not::vx_not(vx_core::Type_boolean val) {
      return vx_core::f_not(val);
    }

  //}

  vx_core::Func_not vx_core::e_not = std::make_shared<vx_core::Class_not>();
  vx_core::Func_not vx_core::t_not = std::make_shared<vx_core::Class_not>();

  vx_core::Type_boolean vx_core::f_not(vx_core::Type_boolean val) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    return output;
  }

  /**
   * @function notempty
   * Returns true if text is not empty.
   * @param  {string} text
   * @return {boolean}
   * (func !-empty)
   */
  //class Func_notempty {

    template <class T> std::shared_ptr<T> vx_core::Class_notempty::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_notempty output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_notempty::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_notempty output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_notempty::vx_typedef() {return vx_core::t_notempty->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_notempty::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "!-empty", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_notempty::vx_empty(std::shared_ptr<T> val) {return vx_core::e_notempty;}
    template <class T> std::shared_ptr<T> vx_core::Class_notempty::vx_type(std::shared_ptr<T> val) {return vx_core::t_notempty;}

    vx_core::Func_any_from_any vx_core::Class_notempty::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_notempty::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_string inputval = (vx_core::Type_string)value;
      vx_core::Type_any outputval = vx_core::f_notempty(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_notempty::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_notempty(text);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_notempty::vx_notempty(vx_core::Type_string text) {
      return vx_core::f_notempty(text);
    }

  //}

  vx_core::Func_notempty vx_core::e_notempty = std::make_shared<vx_core::Class_notempty>();
  vx_core::Func_notempty vx_core::t_notempty = std::make_shared<vx_core::Class_notempty>();

  vx_core::Type_boolean vx_core::f_notempty(vx_core::Type_string text) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_core::f_not(
      vx_core::f_is_empty(text)
    );
    return output;
  }

  /**
   * @function notempty 1
   * Returns true if val is not empty.
   * @param  {any} val
   * @return {boolean}
   * (func !-empty)
   */
  //class Func_notempty_1 {

    template <class T> std::shared_ptr<T> vx_core::Class_notempty_1::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_notempty_1 output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_notempty_1::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_notempty_1 output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_notempty_1::vx_typedef() {return vx_core::t_notempty_1->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_notempty_1::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "!-empty", // name
        1, // idx
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

    template <class T> std::shared_ptr<T> vx_core::Class_notempty_1::vx_empty(std::shared_ptr<T> val) {return vx_core::e_notempty_1;}
    template <class T> std::shared_ptr<T> vx_core::Class_notempty_1::vx_type(std::shared_ptr<T> val) {return vx_core::t_notempty_1;}

    vx_core::Func_any_from_any vx_core::Class_notempty_1::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_notempty_1::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_core::f_notempty_1(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_notempty_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any val = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_notempty_1(val);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_notempty_1::vx_notempty_1(vx_core::Type_any val) {
      return vx_core::f_notempty_1(val);
    }

  //}

  vx_core::Func_notempty_1 vx_core::e_notempty_1 = std::make_shared<vx_core::Class_notempty_1>();
  vx_core::Func_notempty_1 vx_core::t_notempty_1 = std::make_shared<vx_core::Class_notempty_1>();

  vx_core::Type_boolean vx_core::f_notempty_1(vx_core::Type_any val) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_core::f_not(
      vx_core::f_is_empty_1(val)
    );
    return output;
  }

  /**
   * @function ne
   * Returns true if the first arg is not equal to any of the other args
   * @param  {any} val1
   * @param  {any} val2
   * @return {boolean}
   * (func !=)
   */
  //class Func_ne {

    template <class T> std::shared_ptr<T> vx_core::Class_ne::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_ne output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_ne::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_ne output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_ne::vx_typedef() {return vx_core::t_ne->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_ne::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "!=", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_ne::vx_empty(std::shared_ptr<T> val) {return vx_core::e_ne;}
    template <class T> std::shared_ptr<T> vx_core::Class_ne::vx_type(std::shared_ptr<T> val) {return vx_core::t_ne;}

    vx_core::Type_any vx_core::Class_ne::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any val1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any val2 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_ne(val1, val2);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_ne::vx_ne(vx_core::Type_any val1, vx_core::Type_any val2) {
      return vx_core::f_ne(val1, val2);
    }

  //}

  vx_core::Func_ne vx_core::e_ne = std::make_shared<vx_core::Class_ne>();
  vx_core::Func_ne vx_core::t_ne = std::make_shared<vx_core::Class_ne>();

  vx_core::Type_boolean vx_core::f_ne(vx_core::Type_any val1, vx_core::Type_any val2) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_core::f_not(
      vx_core::f_eq(val1, val2)
    );
    return output;
  }

  /**
   * @function multiply
   * Math int multiply
   * @param  {int} num1
   * @param  {int} num2
   * @return {int}
   * (func *)
   */
  //class Func_multiply {

    template <class T> std::shared_ptr<T> vx_core::Class_multiply::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_multiply output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_multiply::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_multiply output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_multiply::vx_typedef() {return vx_core::t_multiply->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_multiply::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "*", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // traits
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

    template <class T> std::shared_ptr<T> vx_core::Class_multiply::vx_empty(std::shared_ptr<T> val) {return vx_core::e_multiply;}
    template <class T> std::shared_ptr<T> vx_core::Class_multiply::vx_type(std::shared_ptr<T> val) {return vx_core::t_multiply;}

    vx_core::Type_any vx_core::Class_multiply::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_int num1 = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int num2 = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_multiply(num1, num2);
      return output;
    }

    vx_core::Type_int vx_core::Class_multiply::vx_multiply(vx_core::Type_int num1, vx_core::Type_int num2) {
      return vx_core::f_multiply(num1, num2);
    }

  //}

  vx_core::Func_multiply vx_core::e_multiply = std::make_shared<vx_core::Class_multiply>();
  vx_core::Func_multiply vx_core::t_multiply = std::make_shared<vx_core::Class_multiply>();

  vx_core::Type_int vx_core::f_multiply(vx_core::Type_int num1, vx_core::Type_int num2) {
    vx_core::Type_int output = vx_core::e_int;
    return output;
  }

  /**
   * @function multiply 1
   * Math multipy
   * @param  {number} num1
   * @param  {number} num2
   * @return {number}
   * (func *)
   */
  //class Func_multiply_1 {

    template <class T> std::shared_ptr<T> vx_core::Class_multiply_1::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_multiply_1 output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_multiply_1::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_multiply_1 output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_multiply_1::vx_typedef() {return vx_core::t_multiply_1->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_multiply_1::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "*", // name
        1, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_int, vx_core::t_float, vx_core::t_decimal}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_core::Class_multiply_1::vx_empty(std::shared_ptr<T> val) {return vx_core::e_multiply_1;}
    template <class T> std::shared_ptr<T> vx_core::Class_multiply_1::vx_type(std::shared_ptr<T> val) {return vx_core::t_multiply_1;}

    vx_core::Type_any vx_core::Class_multiply_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_number num1 = vx_core::f_any_from_any(vx_core::t_number, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_number num2 = vx_core::f_any_from_any(vx_core::t_number, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_multiply_1(num1, num2);
      return output;
    }

    vx_core::Type_number vx_core::Class_multiply_1::vx_multiply_1(vx_core::Type_number num1, vx_core::Type_number num2) {
      return vx_core::f_multiply_1(num1, num2);
    }

  //}

  vx_core::Func_multiply_1 vx_core::e_multiply_1 = std::make_shared<vx_core::Class_multiply_1>();
  vx_core::Func_multiply_1 vx_core::t_multiply_1 = std::make_shared<vx_core::Class_multiply_1>();

  vx_core::Type_number vx_core::f_multiply_1(vx_core::Type_number num1, vx_core::Type_number num2) {
    vx_core::Type_number output = vx_core::e_number;
    return output;
  }

  /**
   * @function multiply 2
   * Math multiply
   * @param  {intlist} nums
   * @return {int}
   * (func *)
   */
  //class Func_multiply_2 {

    template <class T> std::shared_ptr<T> vx_core::Class_multiply_2::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_multiply_2 output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_multiply_2::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_multiply_2 output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_multiply_2::vx_typedef() {return vx_core::t_multiply_2->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_multiply_2::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "*", // name
        2, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // traits
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

    template <class T> std::shared_ptr<T> vx_core::Class_multiply_2::vx_empty(std::shared_ptr<T> val) {return vx_core::e_multiply_2;}
    template <class T> std::shared_ptr<T> vx_core::Class_multiply_2::vx_type(std::shared_ptr<T> val) {return vx_core::t_multiply_2;}

    vx_core::Func_any_from_any vx_core::Class_multiply_2::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_multiply_2::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_intlist inputval = (vx_core::Type_intlist)value;
      vx_core::Type_any outputval = vx_core::f_multiply_2(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_multiply_2::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_intlist nums = vx_core::f_any_from_any(vx_core::t_intlist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_multiply_2(nums);
      return output;
    }

    vx_core::Type_int vx_core::Class_multiply_2::vx_multiply_2(vx_core::Type_intlist nums) {
      return vx_core::f_multiply_2(nums);
    }

  //}

  vx_core::Func_multiply_2 vx_core::e_multiply_2 = std::make_shared<vx_core::Class_multiply_2>();
  vx_core::Func_multiply_2 vx_core::t_multiply_2 = std::make_shared<vx_core::Class_multiply_2>();

  vx_core::Type_int vx_core::f_multiply_2(vx_core::Type_intlist nums) {
    vx_core::Type_int output = vx_core::e_int;
    output = vx_core::f_any_from_list_reduce(
      vx_core::t_int,
      nums,
      vx_core::t_int->vx_new_from_int(1),
      vx_core::t_any_from_reduce->fn_new([](vx_core::Type_any total_any, vx_core::Type_any num_any) {
        vx_core::Type_int total = vx_core::f_any_from_any(vx_core::t_int, total_any);
        vx_core::Type_int num = vx_core::f_any_from_any(vx_core::t_int, num_any);
        return 
          vx_core::f_multiply(total, num);
      })
    );
    return output;
  }

  /**
   * @function multiply 3
   * Math multiply
   * @param  {numberlist} nums
   * @return {number}
   * (func *)
   */
  //class Func_multiply_3 {

    template <class T> std::shared_ptr<T> vx_core::Class_multiply_3::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_multiply_3 output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_multiply_3::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_multiply_3 output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_multiply_3::vx_typedef() {return vx_core::t_multiply_3->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_multiply_3::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "*", // name
        3, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_int, vx_core::t_float, vx_core::t_decimal}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_core::Class_multiply_3::vx_empty(std::shared_ptr<T> val) {return vx_core::e_multiply_3;}
    template <class T> std::shared_ptr<T> vx_core::Class_multiply_3::vx_type(std::shared_ptr<T> val) {return vx_core::t_multiply_3;}

    vx_core::Func_any_from_any vx_core::Class_multiply_3::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_multiply_3::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_numberlist inputval = (vx_core::Type_numberlist)value;
      vx_core::Type_any outputval = vx_core::f_multiply_3(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_multiply_3::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_numberlist nums = vx_core::f_any_from_any(vx_core::t_numberlist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_multiply_3(nums);
      return output;
    }

    vx_core::Type_number vx_core::Class_multiply_3::vx_multiply_3(vx_core::Type_numberlist nums) {
      return vx_core::f_multiply_3(nums);
    }

  //}

  vx_core::Func_multiply_3 vx_core::e_multiply_3 = std::make_shared<vx_core::Class_multiply_3>();
  vx_core::Func_multiply_3 vx_core::t_multiply_3 = std::make_shared<vx_core::Class_multiply_3>();

  vx_core::Type_number vx_core::f_multiply_3(vx_core::Type_numberlist nums) {
    vx_core::Type_number output = vx_core::e_number;
    output = vx_core::f_any_from_list_reduce(
      vx_core::t_number,
      nums,
      (vx_core::Type_number)vx_core::t_int->vx_new_from_int(1),
      vx_core::t_any_from_reduce->fn_new([](vx_core::Type_any total_any, vx_core::Type_any num_any) {
        vx_core::Type_number total = vx_core::f_any_from_any(vx_core::t_number, total_any);
        vx_core::Type_number num = vx_core::f_any_from_any(vx_core::t_number, num_any);
        return 
          vx_core::f_multiply_1(total, num);
      })
    );
    return output;
  }

  /**
   * @function plus
   * Math int plus
   * @param  {int} num1
   * @param  {int} num2
   * @return {int}
   * (func +)
   */
  //class Func_plus {

    template <class T> std::shared_ptr<T> vx_core::Class_plus::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_plus output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_plus::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_plus output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_plus::vx_typedef() {return vx_core::t_plus->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_plus::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "+", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // traits
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

    template <class T> std::shared_ptr<T> vx_core::Class_plus::vx_empty(std::shared_ptr<T> val) {return vx_core::e_plus;}
    template <class T> std::shared_ptr<T> vx_core::Class_plus::vx_type(std::shared_ptr<T> val) {return vx_core::t_plus;}

    vx_core::Type_any vx_core::Class_plus::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_int num1 = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int num2 = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_plus(num1, num2);
      return output;
    }

    vx_core::Type_int vx_core::Class_plus::vx_plus(vx_core::Type_int num1, vx_core::Type_int num2) {
      return vx_core::f_plus(num1, num2);
    }

  //}

  vx_core::Func_plus vx_core::e_plus = std::make_shared<vx_core::Class_plus>();
  vx_core::Func_plus vx_core::t_plus = std::make_shared<vx_core::Class_plus>();

  vx_core::Type_int vx_core::f_plus(vx_core::Type_int num1, vx_core::Type_int num2) {
    vx_core::Type_int output = vx_core::e_int;
    return output;
  }

  /**
   * @function plus 1
   * Math number plus
   * @param  {number} num1
   * @param  {number} num2
   * @return {number}
   * (func +)
   */
  //class Func_plus_1 {

    template <class T> std::shared_ptr<T> vx_core::Class_plus_1::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_plus_1 output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_plus_1::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_plus_1 output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_plus_1::vx_typedef() {return vx_core::t_plus_1->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_plus_1::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "+", // name
        1, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_int, vx_core::t_float, vx_core::t_decimal}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_core::Class_plus_1::vx_empty(std::shared_ptr<T> val) {return vx_core::e_plus_1;}
    template <class T> std::shared_ptr<T> vx_core::Class_plus_1::vx_type(std::shared_ptr<T> val) {return vx_core::t_plus_1;}

    vx_core::Type_any vx_core::Class_plus_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_number num1 = vx_core::f_any_from_any(vx_core::t_number, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_number num2 = vx_core::f_any_from_any(vx_core::t_number, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_plus_1(num1, num2);
      return output;
    }

    vx_core::Type_number vx_core::Class_plus_1::vx_plus_1(vx_core::Type_number num1, vx_core::Type_number num2) {
      return vx_core::f_plus_1(num1, num2);
    }

  //}

  vx_core::Func_plus_1 vx_core::e_plus_1 = std::make_shared<vx_core::Class_plus_1>();
  vx_core::Func_plus_1 vx_core::t_plus_1 = std::make_shared<vx_core::Class_plus_1>();

  vx_core::Type_number vx_core::f_plus_1(vx_core::Type_number num1, vx_core::Type_number num2) {
    vx_core::Type_number output = vx_core::e_number;
    return output;
  }

  /**
   * @function plus 2
   * Math int plus
   * @param  {intlist} nums
   * @return {int}
   * (func +)
   */
  //class Func_plus_2 {

    template <class T> std::shared_ptr<T> vx_core::Class_plus_2::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_plus_2 output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_plus_2::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_plus_2 output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_plus_2::vx_typedef() {return vx_core::t_plus_2->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_plus_2::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "+", // name
        2, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // traits
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

    template <class T> std::shared_ptr<T> vx_core::Class_plus_2::vx_empty(std::shared_ptr<T> val) {return vx_core::e_plus_2;}
    template <class T> std::shared_ptr<T> vx_core::Class_plus_2::vx_type(std::shared_ptr<T> val) {return vx_core::t_plus_2;}

    vx_core::Func_any_from_any vx_core::Class_plus_2::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_plus_2::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_intlist inputval = (vx_core::Type_intlist)value;
      vx_core::Type_any outputval = vx_core::f_plus_2(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_plus_2::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_intlist nums = vx_core::f_any_from_any(vx_core::t_intlist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_plus_2(nums);
      return output;
    }

    vx_core::Type_int vx_core::Class_plus_2::vx_plus_2(vx_core::Type_intlist nums) {
      return vx_core::f_plus_2(nums);
    }

  //}

  vx_core::Func_plus_2 vx_core::e_plus_2 = std::make_shared<vx_core::Class_plus_2>();
  vx_core::Func_plus_2 vx_core::t_plus_2 = std::make_shared<vx_core::Class_plus_2>();

  vx_core::Type_int vx_core::f_plus_2(vx_core::Type_intlist nums) {
    vx_core::Type_int output = vx_core::e_int;
    output = vx_core::f_any_from_list_reduce(
      vx_core::t_int,
      nums,
      vx_core::t_int->vx_new_from_int(0),
      vx_core::t_any_from_reduce->fn_new([](vx_core::Type_any total_any, vx_core::Type_any num_any) {
        vx_core::Type_int total = vx_core::f_any_from_any(vx_core::t_int, total_any);
        vx_core::Type_int num = vx_core::f_any_from_any(vx_core::t_int, num_any);
        return 
          vx_core::f_plus(total, num);
      })
    );
    return output;
  }

  /**
   * @function plus 3
   * Math number plus
   * @param  {numberlist} nums
   * @return {number}
   * (func +)
   */
  //class Func_plus_3 {

    template <class T> std::shared_ptr<T> vx_core::Class_plus_3::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_plus_3 output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_plus_3::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_plus_3 output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_plus_3::vx_typedef() {return vx_core::t_plus_3->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_plus_3::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "+", // name
        3, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_int, vx_core::t_float, vx_core::t_decimal}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_core::Class_plus_3::vx_empty(std::shared_ptr<T> val) {return vx_core::e_plus_3;}
    template <class T> std::shared_ptr<T> vx_core::Class_plus_3::vx_type(std::shared_ptr<T> val) {return vx_core::t_plus_3;}

    vx_core::Func_any_from_any vx_core::Class_plus_3::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_plus_3::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_numberlist inputval = (vx_core::Type_numberlist)value;
      vx_core::Type_any outputval = vx_core::f_plus_3(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_plus_3::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_numberlist nums = vx_core::f_any_from_any(vx_core::t_numberlist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_plus_3(nums);
      return output;
    }

    vx_core::Type_number vx_core::Class_plus_3::vx_plus_3(vx_core::Type_numberlist nums) {
      return vx_core::f_plus_3(nums);
    }

  //}

  vx_core::Func_plus_3 vx_core::e_plus_3 = std::make_shared<vx_core::Class_plus_3>();
  vx_core::Func_plus_3 vx_core::t_plus_3 = std::make_shared<vx_core::Class_plus_3>();

  vx_core::Type_number vx_core::f_plus_3(vx_core::Type_numberlist nums) {
    vx_core::Type_number output = vx_core::e_number;
    output = vx_core::f_any_from_list_reduce(
      vx_core::t_number,
      nums,
      (vx_core::Type_number)vx_core::t_int->vx_new_from_int(0),
      vx_core::t_any_from_reduce->fn_new([](vx_core::Type_any total_any, vx_core::Type_any num_any) {
        vx_core::Type_number total = vx_core::f_any_from_any(vx_core::t_number, total_any);
        vx_core::Type_number num = vx_core::f_any_from_any(vx_core::t_number, num_any);
        return 
          vx_core::f_plus_1(total, num);
      })
    );
    return output;
  }

  /**
   * @function plus1
   * Math int plus 1
   * @param  {int} num
   * @return {int}
   * (func +1)
   */
  //class Func_plus1 {

    template <class T> std::shared_ptr<T> vx_core::Class_plus1::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_plus1 output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_plus1::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_plus1 output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_plus1::vx_typedef() {return vx_core::t_plus1->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_plus1::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "+1", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // traits
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

    template <class T> std::shared_ptr<T> vx_core::Class_plus1::vx_empty(std::shared_ptr<T> val) {return vx_core::e_plus1;}
    template <class T> std::shared_ptr<T> vx_core::Class_plus1::vx_type(std::shared_ptr<T> val) {return vx_core::t_plus1;}

    vx_core::Func_any_from_any vx_core::Class_plus1::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_plus1::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_int inputval = (vx_core::Type_int)value;
      vx_core::Type_any outputval = vx_core::f_plus1(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_plus1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_int num = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_plus1(num);
      return output;
    }

    vx_core::Type_int vx_core::Class_plus1::vx_plus1(vx_core::Type_int num) {
      return vx_core::f_plus1(num);
    }

  //}

  vx_core::Func_plus1 vx_core::e_plus1 = std::make_shared<vx_core::Class_plus1>();
  vx_core::Func_plus1 vx_core::t_plus1 = std::make_shared<vx_core::Class_plus1>();

  vx_core::Type_int vx_core::f_plus1(vx_core::Type_int num) {
    vx_core::Type_int output = vx_core::e_int;
    return output;
  }

  /**
   * @function minus
   * Math int minus
   * @param  {int} num1
   * @param  {int} num2
   * @return {int}
   * (func -)
   */
  //class Func_minus {

    template <class T> std::shared_ptr<T> vx_core::Class_minus::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_minus output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_minus::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_minus output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_minus::vx_typedef() {return vx_core::t_minus->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_minus::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "-", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // traits
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

    template <class T> std::shared_ptr<T> vx_core::Class_minus::vx_empty(std::shared_ptr<T> val) {return vx_core::e_minus;}
    template <class T> std::shared_ptr<T> vx_core::Class_minus::vx_type(std::shared_ptr<T> val) {return vx_core::t_minus;}

    vx_core::Type_any vx_core::Class_minus::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_int num1 = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int num2 = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_minus(num1, num2);
      return output;
    }

    vx_core::Type_int vx_core::Class_minus::vx_minus(vx_core::Type_int num1, vx_core::Type_int num2) {
      return vx_core::f_minus(num1, num2);
    }

  //}

  vx_core::Func_minus vx_core::e_minus = std::make_shared<vx_core::Class_minus>();
  vx_core::Func_minus vx_core::t_minus = std::make_shared<vx_core::Class_minus>();

  vx_core::Type_int vx_core::f_minus(vx_core::Type_int num1, vx_core::Type_int num2) {
    vx_core::Type_int output = vx_core::e_int;
    return output;
  }

  /**
   * @function minus 1
   * Math number minus
   * @param  {number} num1
   * @param  {number} num2
   * @return {number}
   * (func -)
   */
  //class Func_minus_1 {

    template <class T> std::shared_ptr<T> vx_core::Class_minus_1::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_minus_1 output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_minus_1::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_minus_1 output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_minus_1::vx_typedef() {return vx_core::t_minus_1->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_minus_1::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "-", // name
        1, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_int, vx_core::t_float, vx_core::t_decimal}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_core::Class_minus_1::vx_empty(std::shared_ptr<T> val) {return vx_core::e_minus_1;}
    template <class T> std::shared_ptr<T> vx_core::Class_minus_1::vx_type(std::shared_ptr<T> val) {return vx_core::t_minus_1;}

    vx_core::Type_any vx_core::Class_minus_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_number num1 = vx_core::f_any_from_any(vx_core::t_number, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_number num2 = vx_core::f_any_from_any(vx_core::t_number, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_minus_1(num1, num2);
      return output;
    }

    vx_core::Type_number vx_core::Class_minus_1::vx_minus_1(vx_core::Type_number num1, vx_core::Type_number num2) {
      return vx_core::f_minus_1(num1, num2);
    }

  //}

  vx_core::Func_minus_1 vx_core::e_minus_1 = std::make_shared<vx_core::Class_minus_1>();
  vx_core::Func_minus_1 vx_core::t_minus_1 = std::make_shared<vx_core::Class_minus_1>();

  vx_core::Type_number vx_core::f_minus_1(vx_core::Type_number num1, vx_core::Type_number num2) {
    vx_core::Type_number output = vx_core::e_number;
    return output;
  }

  /**
   * @function minus 2
   * Math integer minus
   * @param  {intlist} nums
   * @return {int}
   * (func -)
   */
  //class Func_minus_2 {

    template <class T> std::shared_ptr<T> vx_core::Class_minus_2::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_minus_2 output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_minus_2::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_minus_2 output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_minus_2::vx_typedef() {return vx_core::t_minus_2->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_minus_2::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "-", // name
        2, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // traits
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

    template <class T> std::shared_ptr<T> vx_core::Class_minus_2::vx_empty(std::shared_ptr<T> val) {return vx_core::e_minus_2;}
    template <class T> std::shared_ptr<T> vx_core::Class_minus_2::vx_type(std::shared_ptr<T> val) {return vx_core::t_minus_2;}

    vx_core::Func_any_from_any vx_core::Class_minus_2::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_minus_2::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_intlist inputval = (vx_core::Type_intlist)value;
      vx_core::Type_any outputval = vx_core::f_minus_2(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_minus_2::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_intlist nums = vx_core::f_any_from_any(vx_core::t_intlist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_minus_2(nums);
      return output;
    }

    vx_core::Type_int vx_core::Class_minus_2::vx_minus_2(vx_core::Type_intlist nums) {
      return vx_core::f_minus_2(nums);
    }

  //}

  vx_core::Func_minus_2 vx_core::e_minus_2 = std::make_shared<vx_core::Class_minus_2>();
  vx_core::Func_minus_2 vx_core::t_minus_2 = std::make_shared<vx_core::Class_minus_2>();

  vx_core::Type_int vx_core::f_minus_2(vx_core::Type_intlist nums) {
    vx_core::Type_int output = vx_core::e_int;
    output = vx_core::f_any_from_list_reduce(
      vx_core::t_int,
      nums,
      vx_core::t_int->vx_new_from_int(0),
      vx_core::t_any_from_reduce->fn_new([](vx_core::Type_any total_any, vx_core::Type_any num_any) {
        vx_core::Type_int total = vx_core::f_any_from_any(vx_core::t_int, total_any);
        vx_core::Type_int num = vx_core::f_any_from_any(vx_core::t_int, num_any);
        return 
          vx_core::f_minus(total, num);
      })
    );
    return output;
  }

  /**
   * @function minus 3
   * Math number minus
   * @param  {numberlist} nums
   * @return {number}
   * (func -)
   */
  //class Func_minus_3 {

    template <class T> std::shared_ptr<T> vx_core::Class_minus_3::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_minus_3 output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_minus_3::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_minus_3 output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_minus_3::vx_typedef() {return vx_core::t_minus_3->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_minus_3::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "-", // name
        3, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_int, vx_core::t_float, vx_core::t_decimal}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_core::Class_minus_3::vx_empty(std::shared_ptr<T> val) {return vx_core::e_minus_3;}
    template <class T> std::shared_ptr<T> vx_core::Class_minus_3::vx_type(std::shared_ptr<T> val) {return vx_core::t_minus_3;}

    vx_core::Func_any_from_any vx_core::Class_minus_3::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_minus_3::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_numberlist inputval = (vx_core::Type_numberlist)value;
      vx_core::Type_any outputval = vx_core::f_minus_3(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_minus_3::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_numberlist nums = vx_core::f_any_from_any(vx_core::t_numberlist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_minus_3(nums);
      return output;
    }

    vx_core::Type_number vx_core::Class_minus_3::vx_minus_3(vx_core::Type_numberlist nums) {
      return vx_core::f_minus_3(nums);
    }

  //}

  vx_core::Func_minus_3 vx_core::e_minus_3 = std::make_shared<vx_core::Class_minus_3>();
  vx_core::Func_minus_3 vx_core::t_minus_3 = std::make_shared<vx_core::Class_minus_3>();

  vx_core::Type_number vx_core::f_minus_3(vx_core::Type_numberlist nums) {
    vx_core::Type_number output = vx_core::e_number;
    output = vx_core::f_any_from_list_reduce(
      vx_core::t_number,
      nums,
      (vx_core::Type_number)vx_core::t_int->vx_new_from_int(0),
      vx_core::t_any_from_reduce->fn_new([](vx_core::Type_any total_any, vx_core::Type_any num_any) {
        vx_core::Type_number total = vx_core::f_any_from_any(vx_core::t_number, total_any);
        vx_core::Type_number num = vx_core::f_any_from_any(vx_core::t_number, num_any);
        return 
          vx_core::f_minus_1(total, num);
      })
    );
    return output;
  }

  /**
   * @function dotmethod
   * Not Recommened: Support for Object Oriented dot notation. e.g. (this.foo 'a') = this.foo('a')
   * @param  {any} object
   * @param  {string} method
   * @param  {anylist} params
   * @return {any}
   * (func .)
   */
  //class Func_dotmethod {

    template <class T> std::shared_ptr<T> vx_core::Class_dotmethod::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_dotmethod output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_dotmethod::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_dotmethod output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_dotmethod::vx_typedef() {return vx_core::t_dotmethod->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_dotmethod::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        ".", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_dotmethod::vx_empty(std::shared_ptr<T> val) {return vx_core::e_dotmethod;}
    template <class T> std::shared_ptr<T> vx_core::Class_dotmethod::vx_type(std::shared_ptr<T> val) {return vx_core::t_dotmethod;}

    vx_core::Type_any vx_core::Class_dotmethod::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any object = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_string method = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      vx_core::Type_anylist params = vx_core::f_any_from_any(vx_core::t_anylist, arglist->vx_any(vx_core::t_int->vx_new_from_int(2)));
      output = vx_core::f_dotmethod(object, method, params);
      return output;
    }

    vx_core::Type_any vx_core::Class_dotmethod::vx_dotmethod(vx_core::Type_any object, vx_core::Type_string method, vx_core::Type_anylist params) {
      return vx_core::f_dotmethod(object, method, params);
    }

  //}

  vx_core::Func_dotmethod vx_core::e_dotmethod = std::make_shared<vx_core::Class_dotmethod>();
  vx_core::Func_dotmethod vx_core::t_dotmethod = std::make_shared<vx_core::Class_dotmethod>();

  vx_core::Type_any vx_core::f_dotmethod(vx_core::Type_any object, vx_core::Type_string method, vx_core::Type_anylist params) {
    vx_core::Type_any output = vx_core::e_any;
    return output;
  }

  /**
   * @function divide
   * Math divide
   * @param  {number} num1
   * @param  {number} num2
   * @return {number}
   * (func /)
   */
  //class Func_divide {

    template <class T> std::shared_ptr<T> vx_core::Class_divide::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_divide output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_divide::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_divide output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_divide::vx_typedef() {return vx_core::t_divide->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_divide::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "/", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_int, vx_core::t_float, vx_core::t_decimal}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_core::Class_divide::vx_empty(std::shared_ptr<T> val) {return vx_core::e_divide;}
    template <class T> std::shared_ptr<T> vx_core::Class_divide::vx_type(std::shared_ptr<T> val) {return vx_core::t_divide;}

    vx_core::Type_any vx_core::Class_divide::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_number num1 = vx_core::f_any_from_any(vx_core::t_number, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_number num2 = vx_core::f_any_from_any(vx_core::t_number, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_divide(num1, num2);
      return output;
    }

    vx_core::Type_number vx_core::Class_divide::vx_divide(vx_core::Type_number num1, vx_core::Type_number num2) {
      return vx_core::f_divide(num1, num2);
    }

  //}

  vx_core::Func_divide vx_core::e_divide = std::make_shared<vx_core::Class_divide>();
  vx_core::Func_divide vx_core::t_divide = std::make_shared<vx_core::Class_divide>();

  vx_core::Type_number vx_core::f_divide(vx_core::Type_number num1, vx_core::Type_number num2) {
    vx_core::Type_number output = vx_core::e_number;
    return output;
  }

  /**
   * @function lt
   * Returns true if the first arg is less than all of the other args
   * @param  {any} val1
   * @param  {any} val2
   * @return {boolean}
   * (func <)
   */
  //class Func_lt {

    template <class T> std::shared_ptr<T> vx_core::Class_lt::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_lt output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_lt::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_lt output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_lt::vx_typedef() {return vx_core::t_lt->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_lt::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "<", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_lt::vx_empty(std::shared_ptr<T> val) {return vx_core::e_lt;}
    template <class T> std::shared_ptr<T> vx_core::Class_lt::vx_type(std::shared_ptr<T> val) {return vx_core::t_lt;}

    vx_core::Type_any vx_core::Class_lt::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any val1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any val2 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_lt(val1, val2);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_lt::vx_lt(vx_core::Type_any val1, vx_core::Type_any val2) {
      return vx_core::f_lt(val1, val2);
    }

  //}

  vx_core::Func_lt vx_core::e_lt = std::make_shared<vx_core::Class_lt>();
  vx_core::Func_lt vx_core::t_lt = std::make_shared<vx_core::Class_lt>();

  vx_core::Type_boolean vx_core::f_lt(vx_core::Type_any val1, vx_core::Type_any val2) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_core::f_switch(
      vx_core::t_boolean,
      vx_core::f_compare(val1, val2),
      vx_core::t_thenelselist->vx_new(vx_core::t_thenelselist, {
        vx_core::f_case_1(
          vx_core::t_int->vx_new_from_int(-1),
          vx_core::t_any_from_func->fn_new([]() {
            return vx_core::t_boolean->vx_new_from_boolean(true);
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func->fn_new([]() {
            return vx_core::t_boolean->vx_new_from_boolean(false);
          })
        )
      })
    );
    return output;
  }

  /**
   * @function lt 1
   * Returns true if the first arg is less than all of the other args
   * @param  {anylist} values
   * @return {boolean}
   * (func <)
   */
  //class Func_lt_1 {

    template <class T> std::shared_ptr<T> vx_core::Class_lt_1::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_lt_1 output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_lt_1::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_lt_1 output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_lt_1::vx_typedef() {return vx_core::t_lt_1->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_lt_1::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "<", // name
        1, // idx
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

    template <class T> std::shared_ptr<T> vx_core::Class_lt_1::vx_empty(std::shared_ptr<T> val) {return vx_core::e_lt_1;}
    template <class T> std::shared_ptr<T> vx_core::Class_lt_1::vx_type(std::shared_ptr<T> val) {return vx_core::t_lt_1;}

    vx_core::Func_any_from_any vx_core::Class_lt_1::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_lt_1::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_anylist inputval = (vx_core::Type_anylist)value;
      vx_core::Type_any outputval = vx_core::f_lt_1(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_lt_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_anylist values = vx_core::f_any_from_any(vx_core::t_anylist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_lt_1(values);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_lt_1::vx_lt_1(vx_core::Type_anylist values) {
      return vx_core::f_lt_1(values);
    }

  //}

  vx_core::Func_lt_1 vx_core::e_lt_1 = std::make_shared<vx_core::Class_lt_1>();
  vx_core::Func_lt_1 vx_core::t_lt_1 = std::make_shared<vx_core::Class_lt_1>();

  vx_core::Type_boolean vx_core::f_lt_1(vx_core::Type_anylist values) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_core::f_any_from_list_reduce_next(
      vx_core::t_boolean,
      values,
      vx_core::t_boolean->vx_new_from_boolean(true),
      vx_core::t_any_from_reduce_next->fn_new([](vx_core::Type_any reduce_any, vx_core::Type_any current_any, vx_core::Type_any next_any) {
        vx_core::Type_boolean reduce = vx_core::f_any_from_any(vx_core::t_boolean, reduce_any);
        vx_core::Type_any current = vx_core::f_any_from_any(vx_core::t_any, current_any);
        vx_core::Type_any next = vx_core::f_any_from_any(vx_core::t_any, next_any);
        return 
          vx_core::f_and(
            reduce,
            vx_core::f_lt(current, next)
          );
      })
    );
    return output;
  }

  /**
   * @function chainfirst
   * This is a special function that applies a value as the first argument for the first function.
   * The result is then used as the first argument on the next function, etc. Sometimes this
   * improves readability.
   * @param  {any-1} value
   * @param  {any<-anylist} fnlist
   * @return {any-1}
   * (func <-)
   */
  //class Func_chainfirst {

    template <class T> std::shared_ptr<T> vx_core::Class_chainfirst::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_chainfirst output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_chainfirst::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_chainfirst output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_chainfirst::vx_typedef() {return vx_core::t_chainfirst->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_chainfirst::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "<-", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_chainfirst::vx_empty(std::shared_ptr<T> val) {return vx_core::e_chainfirst;}
    template <class T> std::shared_ptr<T> vx_core::Class_chainfirst::vx_type(std::shared_ptr<T> val) {return vx_core::t_chainfirst;}

    vx_core::Type_any vx_core::Class_chainfirst::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any value = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any_from_anylist fnlist = vx_core::f_any_from_any(vx_core::t_any_from_anylist, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_chainfirst(generic_any_1, value, fnlist);
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_chainfirst::vx_chainfirst(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> value, vx_core::Type_any_from_anylist fnlist) {
      return vx_core::f_chainfirst(generic_any_1, value, fnlist);
    }

  //}

  vx_core::Func_chainfirst vx_core::e_chainfirst = std::make_shared<vx_core::Class_chainfirst>();
  vx_core::Func_chainfirst vx_core::t_chainfirst = std::make_shared<vx_core::Class_chainfirst>();

  template <class T> std::shared_ptr<T> vx_core::f_chainfirst(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> value, vx_core::Type_any_from_anylist fnlist) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    return output;
  }

  /**
   * @function chainlast
   * This is a special function that applies a value as the last argument for the first function.
   * The result is then used as the last argument on the next function, etc. Sometimes this
   * improves readability.
   * @param  {any-1} value
   * @param  {any<-anylist} fnlist
   * @return {any-1}
   * (func <<-)
   */
  //class Func_chainlast {

    template <class T> std::shared_ptr<T> vx_core::Class_chainlast::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_chainlast output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_chainlast::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_chainlast output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_chainlast::vx_typedef() {return vx_core::t_chainlast->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_chainlast::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "<<-", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_chainlast::vx_empty(std::shared_ptr<T> val) {return vx_core::e_chainlast;}
    template <class T> std::shared_ptr<T> vx_core::Class_chainlast::vx_type(std::shared_ptr<T> val) {return vx_core::t_chainlast;}

    vx_core::Type_any vx_core::Class_chainlast::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any value = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any_from_anylist fnlist = vx_core::f_any_from_any(vx_core::t_any_from_anylist, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_chainlast(generic_any_1, value, fnlist);
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_chainlast::vx_chainlast(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> value, vx_core::Type_any_from_anylist fnlist) {
      return vx_core::f_chainlast(generic_any_1, value, fnlist);
    }

  //}

  vx_core::Func_chainlast vx_core::e_chainlast = std::make_shared<vx_core::Class_chainlast>();
  vx_core::Func_chainlast vx_core::t_chainlast = std::make_shared<vx_core::Class_chainlast>();

  template <class T> std::shared_ptr<T> vx_core::f_chainlast(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> value, vx_core::Type_any_from_anylist fnlist) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    return output;
  }

  /**
   * @function le
   * Returns true if the first arg is less or equal than all of the other args
   * @param  {any} val1
   * @param  {any} val2
   * @return {boolean}
   * (func <=)
   */
  //class Func_le {

    template <class T> std::shared_ptr<T> vx_core::Class_le::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_le output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_le::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_le output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_le::vx_typedef() {return vx_core::t_le->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_le::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "<=", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_le::vx_empty(std::shared_ptr<T> val) {return vx_core::e_le;}
    template <class T> std::shared_ptr<T> vx_core::Class_le::vx_type(std::shared_ptr<T> val) {return vx_core::t_le;}

    vx_core::Type_any vx_core::Class_le::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any val1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any val2 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_le(val1, val2);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_le::vx_le(vx_core::Type_any val1, vx_core::Type_any val2) {
      return vx_core::f_le(val1, val2);
    }

  //}

  vx_core::Func_le vx_core::e_le = std::make_shared<vx_core::Class_le>();
  vx_core::Func_le vx_core::t_le = std::make_shared<vx_core::Class_le>();

  vx_core::Type_boolean vx_core::f_le(vx_core::Type_any val1, vx_core::Type_any val2) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_core::f_not(
      vx_core::f_gt(val1, val2)
    );
    return output;
  }

  /**
   * @function le 1
   * Returns true if the first arg is less or equal than all of the other args
   * @param  {anylist} args
   * @return {boolean}
   * (func <=)
   */
  //class Func_le_1 {

    template <class T> std::shared_ptr<T> vx_core::Class_le_1::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_le_1 output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_le_1::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_le_1 output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_le_1::vx_typedef() {return vx_core::t_le_1->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_le_1::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "<=", // name
        1, // idx
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

    template <class T> std::shared_ptr<T> vx_core::Class_le_1::vx_empty(std::shared_ptr<T> val) {return vx_core::e_le_1;}
    template <class T> std::shared_ptr<T> vx_core::Class_le_1::vx_type(std::shared_ptr<T> val) {return vx_core::t_le_1;}

    vx_core::Func_any_from_any vx_core::Class_le_1::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_le_1::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_anylist inputval = (vx_core::Type_anylist)value;
      vx_core::Type_any outputval = vx_core::f_le_1(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_le_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_anylist args = vx_core::f_any_from_any(vx_core::t_anylist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_le_1(args);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_le_1::vx_le_1(vx_core::Type_anylist args) {
      return vx_core::f_le_1(args);
    }

  //}

  vx_core::Func_le_1 vx_core::e_le_1 = std::make_shared<vx_core::Class_le_1>();
  vx_core::Func_le_1 vx_core::t_le_1 = std::make_shared<vx_core::Class_le_1>();

  vx_core::Type_boolean vx_core::f_le_1(vx_core::Type_anylist args) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_core::f_not(
      vx_core::f_gt_1(args)
    );
    return output;
  }

  /**
   * @function eq
   * Boolean equal/equivalent
   * @param  {any} val1
   * @param  {any} val2
   * @return {boolean}
   * (func =)
   */
  //class Func_eq {

    template <class T> std::shared_ptr<T> vx_core::Class_eq::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_eq output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_eq::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_eq output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_eq::vx_typedef() {return vx_core::t_eq->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_eq::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "=", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_eq::vx_empty(std::shared_ptr<T> val) {return vx_core::e_eq;}
    template <class T> std::shared_ptr<T> vx_core::Class_eq::vx_type(std::shared_ptr<T> val) {return vx_core::t_eq;}

    vx_core::Type_any vx_core::Class_eq::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any val1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any val2 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_eq(val1, val2);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_eq::vx_eq(vx_core::Type_any val1, vx_core::Type_any val2) {
      return vx_core::f_eq(val1, val2);
    }

  //}

  vx_core::Func_eq vx_core::e_eq = std::make_shared<vx_core::Class_eq>();
  vx_core::Func_eq vx_core::t_eq = std::make_shared<vx_core::Class_eq>();

  vx_core::Type_boolean vx_core::f_eq(vx_core::Type_any val1, vx_core::Type_any val2) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    return output;
  }

  /**
   * @function eq 1
   * Boolean equal/equivalent
   * @param  {anylist} values
   * @return {boolean}
   * (func =)
   */
  //class Func_eq_1 {

    template <class T> std::shared_ptr<T> vx_core::Class_eq_1::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_eq_1 output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_eq_1::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_eq_1 output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_eq_1::vx_typedef() {return vx_core::t_eq_1->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_eq_1::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "=", // name
        1, // idx
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

    template <class T> std::shared_ptr<T> vx_core::Class_eq_1::vx_empty(std::shared_ptr<T> val) {return vx_core::e_eq_1;}
    template <class T> std::shared_ptr<T> vx_core::Class_eq_1::vx_type(std::shared_ptr<T> val) {return vx_core::t_eq_1;}

    vx_core::Func_any_from_any vx_core::Class_eq_1::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_eq_1::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_anylist inputval = (vx_core::Type_anylist)value;
      vx_core::Type_any outputval = vx_core::f_eq_1(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_eq_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_anylist values = vx_core::f_any_from_any(vx_core::t_anylist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_eq_1(values);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_eq_1::vx_eq_1(vx_core::Type_anylist values) {
      return vx_core::f_eq_1(values);
    }

  //}

  vx_core::Func_eq_1 vx_core::e_eq_1 = std::make_shared<vx_core::Class_eq_1>();
  vx_core::Func_eq_1 vx_core::t_eq_1 = std::make_shared<vx_core::Class_eq_1>();

  vx_core::Type_boolean vx_core::f_eq_1(vx_core::Type_anylist values) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_core::f_any_from_list_reduce_next(
      vx_core::t_boolean,
      values,
      vx_core::t_boolean->vx_new_from_boolean(false),
      vx_core::t_any_from_reduce_next->fn_new([](vx_core::Type_any reduce_any, vx_core::Type_any current_any, vx_core::Type_any next_any) {
        vx_core::Type_boolean reduce = vx_core::f_any_from_any(vx_core::t_boolean, reduce_any);
        vx_core::Type_any current = vx_core::f_any_from_any(vx_core::t_any, current_any);
        vx_core::Type_any next = vx_core::f_any_from_any(vx_core::t_any, next_any);
        return 
          vx_core::f_and(
            reduce,
            vx_core::f_eq(current, next)
          );
      })
    );
    return output;
  }

  /**
   * @function gt
   * Returns true if the first arg is greater than all of the other args
   * @param  {any} val1
   * @param  {any} val2
   * @return {boolean}
   * (func >)
   */
  //class Func_gt {

    template <class T> std::shared_ptr<T> vx_core::Class_gt::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_gt output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_gt::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_gt output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_gt::vx_typedef() {return vx_core::t_gt->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_gt::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        ">", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_gt::vx_empty(std::shared_ptr<T> val) {return vx_core::e_gt;}
    template <class T> std::shared_ptr<T> vx_core::Class_gt::vx_type(std::shared_ptr<T> val) {return vx_core::t_gt;}

    vx_core::Type_any vx_core::Class_gt::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any val1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any val2 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_gt(val1, val2);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_gt::vx_gt(vx_core::Type_any val1, vx_core::Type_any val2) {
      return vx_core::f_gt(val1, val2);
    }

  //}

  vx_core::Func_gt vx_core::e_gt = std::make_shared<vx_core::Class_gt>();
  vx_core::Func_gt vx_core::t_gt = std::make_shared<vx_core::Class_gt>();

  vx_core::Type_boolean vx_core::f_gt(vx_core::Type_any val1, vx_core::Type_any val2) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_core::f_switch(
      vx_core::t_boolean,
      vx_core::f_compare(val1, val2),
      vx_core::t_thenelselist->vx_new(vx_core::t_thenelselist, {
        vx_core::f_case_1(
          vx_core::t_int->vx_new_from_int(1),
          vx_core::t_any_from_func->fn_new([]() {
            return vx_core::t_boolean->vx_new_from_boolean(true);
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func->fn_new([]() {
            return vx_core::t_boolean->vx_new_from_boolean(false);
          })
        )
      })
    );
    return output;
  }

  /**
   * @function gt 1
   * Returns true if the first arg is greater than all of the other args
   * @param  {anylist} values
   * @return {boolean}
   * (func >)
   */
  //class Func_gt_1 {

    template <class T> std::shared_ptr<T> vx_core::Class_gt_1::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_gt_1 output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_gt_1::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_gt_1 output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_gt_1::vx_typedef() {return vx_core::t_gt_1->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_gt_1::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        ">", // name
        1, // idx
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

    template <class T> std::shared_ptr<T> vx_core::Class_gt_1::vx_empty(std::shared_ptr<T> val) {return vx_core::e_gt_1;}
    template <class T> std::shared_ptr<T> vx_core::Class_gt_1::vx_type(std::shared_ptr<T> val) {return vx_core::t_gt_1;}

    vx_core::Func_any_from_any vx_core::Class_gt_1::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_gt_1::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_anylist inputval = (vx_core::Type_anylist)value;
      vx_core::Type_any outputval = vx_core::f_gt_1(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_gt_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_anylist values = vx_core::f_any_from_any(vx_core::t_anylist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_gt_1(values);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_gt_1::vx_gt_1(vx_core::Type_anylist values) {
      return vx_core::f_gt_1(values);
    }

  //}

  vx_core::Func_gt_1 vx_core::e_gt_1 = std::make_shared<vx_core::Class_gt_1>();
  vx_core::Func_gt_1 vx_core::t_gt_1 = std::make_shared<vx_core::Class_gt_1>();

  vx_core::Type_boolean vx_core::f_gt_1(vx_core::Type_anylist values) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_core::f_any_from_list_reduce_next(
      vx_core::t_boolean,
      values,
      vx_core::t_boolean->vx_new_from_boolean(true),
      vx_core::t_any_from_reduce_next->fn_new([](vx_core::Type_any reduce_any, vx_core::Type_any current_any, vx_core::Type_any next_any) {
        vx_core::Type_boolean reduce = vx_core::f_any_from_any(vx_core::t_boolean, reduce_any);
        vx_core::Type_any current = vx_core::f_any_from_any(vx_core::t_any, current_any);
        vx_core::Type_any next = vx_core::f_any_from_any(vx_core::t_any, next_any);
        return 
          vx_core::f_and(
            reduce,
            vx_core::f_gt(current, next)
          );
      })
    );
    return output;
  }

  /**
   * @function ge
   * Returns true if val1 is greater or equal to val2
   * @param  {any} val1
   * @param  {any} val2
   * @return {boolean}
   * (func >=)
   */
  //class Func_ge {

    template <class T> std::shared_ptr<T> vx_core::Class_ge::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_ge output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_ge::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_ge output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_ge::vx_typedef() {return vx_core::t_ge->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_ge::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        ">=", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_ge::vx_empty(std::shared_ptr<T> val) {return vx_core::e_ge;}
    template <class T> std::shared_ptr<T> vx_core::Class_ge::vx_type(std::shared_ptr<T> val) {return vx_core::t_ge;}

    vx_core::Type_any vx_core::Class_ge::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any val1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any val2 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_ge(val1, val2);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_ge::vx_ge(vx_core::Type_any val1, vx_core::Type_any val2) {
      return vx_core::f_ge(val1, val2);
    }

  //}

  vx_core::Func_ge vx_core::e_ge = std::make_shared<vx_core::Class_ge>();
  vx_core::Func_ge vx_core::t_ge = std::make_shared<vx_core::Class_ge>();

  vx_core::Type_boolean vx_core::f_ge(vx_core::Type_any val1, vx_core::Type_any val2) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_core::f_not(
      vx_core::f_lt(val1, val2)
    );
    return output;
  }

  /**
   * @function ge 1
   * Returns true if the first arg is greater or equal than all of the other args
   * @param  {anylist} args
   * @return {boolean}
   * (func >=)
   */
  //class Func_ge_1 {

    template <class T> std::shared_ptr<T> vx_core::Class_ge_1::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_ge_1 output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_ge_1::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_ge_1 output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_ge_1::vx_typedef() {return vx_core::t_ge_1->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_ge_1::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        ">=", // name
        1, // idx
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

    template <class T> std::shared_ptr<T> vx_core::Class_ge_1::vx_empty(std::shared_ptr<T> val) {return vx_core::e_ge_1;}
    template <class T> std::shared_ptr<T> vx_core::Class_ge_1::vx_type(std::shared_ptr<T> val) {return vx_core::t_ge_1;}

    vx_core::Func_any_from_any vx_core::Class_ge_1::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_ge_1::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_anylist inputval = (vx_core::Type_anylist)value;
      vx_core::Type_any outputval = vx_core::f_ge_1(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_ge_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_anylist args = vx_core::f_any_from_any(vx_core::t_anylist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_ge_1(args);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_ge_1::vx_ge_1(vx_core::Type_anylist args) {
      return vx_core::f_ge_1(args);
    }

  //}

  vx_core::Func_ge_1 vx_core::e_ge_1 = std::make_shared<vx_core::Class_ge_1>();
  vx_core::Func_ge_1 vx_core::t_ge_1 = std::make_shared<vx_core::Class_ge_1>();

  vx_core::Type_boolean vx_core::f_ge_1(vx_core::Type_anylist args) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_core::f_not(
      vx_core::f_lt_1(args)
    );
    return output;
  }

  /**
   * @function allowtypenames_from_typedef
   * Return allow name list from type
   * @param  {typedef} vtypedef
   * @return {stringlist}
   * (func allowtypenames<-typedef)
   */
  //class Func_allowtypenames_from_typedef {

    template <class T> std::shared_ptr<T> vx_core::Class_allowtypenames_from_typedef::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_allowtypenames_from_typedef output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_allowtypenames_from_typedef::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_allowtypenames_from_typedef output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_allowtypenames_from_typedef::vx_typedef() {return vx_core::t_allowtypenames_from_typedef->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_allowtypenames_from_typedef::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "allowtypenames<-typedef", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "stringlist", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_string}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_core::Class_allowtypenames_from_typedef::vx_empty(std::shared_ptr<T> val) {return vx_core::e_allowtypenames_from_typedef;}
    template <class T> std::shared_ptr<T> vx_core::Class_allowtypenames_from_typedef::vx_type(std::shared_ptr<T> val) {return vx_core::t_allowtypenames_from_typedef;}

    vx_core::Func_any_from_any vx_core::Class_allowtypenames_from_typedef::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_allowtypenames_from_typedef::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_typedef inputval = (vx_core::Type_typedef)value;
      vx_core::Type_any outputval = vx_core::f_allowtypenames_from_typedef(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_allowtypenames_from_typedef::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_typedef vtypedef = vx_core::f_any_from_any(vx_core::t_typedef, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_allowtypenames_from_typedef(vtypedef);
      return output;
    }

    vx_core::Type_stringlist vx_core::Class_allowtypenames_from_typedef::vx_allowtypenames_from_typedef(vx_core::Type_typedef vtypedef) {
      return vx_core::f_allowtypenames_from_typedef(vtypedef);
    }

  //}

  vx_core::Func_allowtypenames_from_typedef vx_core::e_allowtypenames_from_typedef = std::make_shared<vx_core::Class_allowtypenames_from_typedef>();
  vx_core::Func_allowtypenames_from_typedef vx_core::t_allowtypenames_from_typedef = std::make_shared<vx_core::Class_allowtypenames_from_typedef>();

  vx_core::Type_stringlist vx_core::f_allowtypenames_from_typedef(vx_core::Type_typedef vtypedef) {
    vx_core::Type_stringlist output = vx_core::e_stringlist;
    output = vx_core::f_typenames_from_typelist(
      vx_core::f_allowtypes_from_typedef(vtypedef)
    );
    return output;
  }

  /**
   * @function allowtypes_from_typedef
   * Return allow type list from type
   * @param  {typedef} vtypedef
   * @return {typelist}
   * (func allowtypes<-typedef)
   */
  //class Func_allowtypes_from_typedef {

    template <class T> std::shared_ptr<T> vx_core::Class_allowtypes_from_typedef::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_allowtypes_from_typedef output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_allowtypes_from_typedef::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_allowtypes_from_typedef output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_allowtypes_from_typedef::vx_typedef() {return vx_core::t_allowtypes_from_typedef->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_allowtypes_from_typedef::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "allowtypes<-typedef", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "typelist", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_any}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_core::Class_allowtypes_from_typedef::vx_empty(std::shared_ptr<T> val) {return vx_core::e_allowtypes_from_typedef;}
    template <class T> std::shared_ptr<T> vx_core::Class_allowtypes_from_typedef::vx_type(std::shared_ptr<T> val) {return vx_core::t_allowtypes_from_typedef;}

    vx_core::Func_any_from_any vx_core::Class_allowtypes_from_typedef::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_allowtypes_from_typedef::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_typedef inputval = (vx_core::Type_typedef)value;
      vx_core::Type_any outputval = vx_core::f_allowtypes_from_typedef(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_allowtypes_from_typedef::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_typedef vtypedef = vx_core::f_any_from_any(vx_core::t_typedef, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_allowtypes_from_typedef(vtypedef);
      return output;
    }

    vx_core::Type_typelist vx_core::Class_allowtypes_from_typedef::vx_allowtypes_from_typedef(vx_core::Type_typedef vtypedef) {
      return vx_core::f_allowtypes_from_typedef(vtypedef);
    }

  //}

  vx_core::Func_allowtypes_from_typedef vx_core::e_allowtypes_from_typedef = std::make_shared<vx_core::Class_allowtypes_from_typedef>();
  vx_core::Func_allowtypes_from_typedef vx_core::t_allowtypes_from_typedef = std::make_shared<vx_core::Class_allowtypes_from_typedef>();

  vx_core::Type_typelist vx_core::f_allowtypes_from_typedef(vx_core::Type_typedef vtypedef) {
    vx_core::Type_typelist output = vx_core::e_typelist;
    return output;
  }

  /**
   * @function and
   * Returns true if all values are true
   * @param  {boolean} val1
   * @param  {boolean} val2
   * @return {boolean}
   * (func and)
   */
  //class Func_and {

    template <class T> std::shared_ptr<T> vx_core::Class_and::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_and output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_and::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_and output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_and::vx_typedef() {return vx_core::t_and->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_and::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "and", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_and::vx_empty(std::shared_ptr<T> val) {return vx_core::e_and;}
    template <class T> std::shared_ptr<T> vx_core::Class_and::vx_type(std::shared_ptr<T> val) {return vx_core::t_and;}

    vx_core::Type_any vx_core::Class_and::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_boolean val1 = vx_core::f_any_from_any(vx_core::t_boolean, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_boolean val2 = vx_core::f_any_from_any(vx_core::t_boolean, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_and(val1, val2);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_and::vx_and(vx_core::Type_boolean val1, vx_core::Type_boolean val2) {
      return vx_core::f_and(val1, val2);
    }

  //}

  vx_core::Func_and vx_core::e_and = std::make_shared<vx_core::Class_and>();
  vx_core::Func_and vx_core::t_and = std::make_shared<vx_core::Class_and>();

  vx_core::Type_boolean vx_core::f_and(vx_core::Type_boolean val1, vx_core::Type_boolean val2) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    return output;
  }

  /**
   * @function and 1
   * Returns true if all values are true
   * @param  {booleanlist} values
   * @return {boolean}
   * (func and)
   */
  //class Func_and_1 {

    template <class T> std::shared_ptr<T> vx_core::Class_and_1::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_and_1 output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_and_1::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_and_1 output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_and_1::vx_typedef() {return vx_core::t_and_1->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_and_1::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "and", // name
        1, // idx
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

    template <class T> std::shared_ptr<T> vx_core::Class_and_1::vx_empty(std::shared_ptr<T> val) {return vx_core::e_and_1;}
    template <class T> std::shared_ptr<T> vx_core::Class_and_1::vx_type(std::shared_ptr<T> val) {return vx_core::t_and_1;}

    vx_core::Func_any_from_any vx_core::Class_and_1::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_and_1::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_booleanlist inputval = (vx_core::Type_booleanlist)value;
      vx_core::Type_any outputval = vx_core::f_and_1(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_and_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_booleanlist values = vx_core::f_any_from_any(vx_core::t_booleanlist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_and_1(values);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_and_1::vx_and_1(vx_core::Type_booleanlist values) {
      return vx_core::f_and_1(values);
    }

  //}

  vx_core::Func_and_1 vx_core::e_and_1 = std::make_shared<vx_core::Class_and_1>();
  vx_core::Func_and_1 vx_core::t_and_1 = std::make_shared<vx_core::Class_and_1>();

  vx_core::Type_boolean vx_core::f_and_1(vx_core::Type_booleanlist values) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_core::f_switch(
      vx_core::t_boolean,
      vx_core::f_length_from_list(values),
      vx_core::t_thenelselist->vx_new(vx_core::t_thenelselist, {
        vx_core::f_case_1(
          vx_core::t_int->vx_new_from_int(0),
          vx_core::t_any_from_func->fn_new([]() {
            return vx_core::t_boolean->vx_new_from_boolean(true);
          })
        ),
        vx_core::f_case_1(
          vx_core::t_int->vx_new_from_int(1),
          vx_core::t_any_from_func->fn_new([values]() {
            return vx_core::f_any_from_list(vx_core::t_boolean, values, vx_core::t_int->vx_new_from_int(0));
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func->fn_new([values]() {
            return vx_core::f_any_from_list_reduce_next(
              vx_core::t_boolean,
              values,
              vx_core::t_boolean->vx_new_from_boolean(true),
              vx_core::t_any_from_reduce_next->fn_new([](vx_core::Type_any reduce_any, vx_core::Type_any current_any, vx_core::Type_any next_any) {
                vx_core::Type_boolean reduce = vx_core::f_any_from_any(vx_core::t_boolean, reduce_any);
                vx_core::Type_boolean current = vx_core::f_any_from_any(vx_core::t_boolean, current_any);
                vx_core::Type_boolean next = vx_core::f_any_from_any(vx_core::t_boolean, next_any);
                return 
                  vx_core::f_and(
                    reduce,
                    vx_core::f_and(current, next)
                  );
              })
            );
          })
        )
      })
    );
    return output;
  }

  /**
   * 
   * @async
   * @function any_from_any_async
   * Function Type taking any value any-2 and returning generic any-1
   * @param  {any-2} value
   * @return {any-1}
   * (func any<-any-async)
   */
  //class Func_any_from_any_async {

    // static
    vx_core::Func_any_from_any_async vx_core::Class_any_from_any_async::fn_new(vx_core::Class_any_from_any_async::IFn fn) {
      vx_core::Func_any_from_any_async output;
      output->fn = fn;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_any_async::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_any_async output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_any_async::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_any_async output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_any_from_any_async::vx_typedef() {return vx_core::t_any_from_any_async->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_any_from_any_async::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-any-async", // name
        0, // idx
        true, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_any_async::vx_empty(std::shared_ptr<T> val) {return vx_core::e_any_from_any_async;}
    template <class T> std::shared_ptr<T> vx_core::Class_any_from_any_async::vx_type(std::shared_ptr<T> val) {return vx_core::t_any_from_any_async;}

    std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_core::Class_any_from_any_async::vx_repl(vx_core::Type_anylist arglist) {
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> output = vx_core::async_new_from_val(vx_core::e_any);
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any value = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> future = vx_core::f_any_from_any_async(generic_any_1, value);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_core::Class_any_from_any_async::vx_any_from_any_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> output;
      if (fn == NULL) {
        output = vx_core::async_new_from_val(vx_core::f_empty(generic_any_1));
      } else {
        std::shared_ptr<vx_core::Async<vx_core::Type_any>> future = fn(value);
        output = vx_core::async_from_async(generic_any_1, future);
      }
      return output;
    }

  //}

  vx_core::Func_any_from_any_async vx_core::e_any_from_any_async = std::make_shared<vx_core::Class_any_from_any_async>();
  vx_core::Func_any_from_any_async vx_core::t_any_from_any_async = std::make_shared<vx_core::Class_any_from_any_async>();

  template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_core::f_any_from_any_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
    std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> output = vx_core::async_new_from_val(vx_core::f_empty(generic_any_1));
    return output;
  }

  /**
   * @function any_from_any_context
   * Function Type taking any value any-2 and returning generic any-1 using context
   * @param  {any-2} value
   * @return {any-1}
   * (func any<-any-context)
   */
  //class Func_any_from_any_context {

    vx_core::Func_any_from_any_context vx_core::Class_any_from_any_context::fn_new(vx_core::Class_any_from_any_context::IFn fn) {
      vx_core::Func_any_from_any_context output;
      output->fn = fn;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_any_context::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_any_context output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_any_context::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_any_context output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_any_from_any_context::vx_typedef() {return vx_core::t_any_from_any_context->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_any_from_any_context::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-any-context", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_any_context::vx_empty(std::shared_ptr<T> val) {return vx_core::e_any_from_any_context;}
    template <class T> std::shared_ptr<T> vx_core::Class_any_from_any_context::vx_type(std::shared_ptr<T> val) {return vx_core::t_any_from_any_context;}

    vx_core::Type_any vx_core::Class_any_from_any_context::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any value = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_context context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_any_from_any_context(generic_any_1, value, context);
      return output;
    }

    template <class T, class U> std::shared_ptr<T> vx_core::Class_any_from_any_context::vx_any_from_any_context(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value, vx_core::Type_context context) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      if (fn != NULL) {
        output = vx_core::f_any_from_any(generic_any_1, fn(value, context));
      }
      return output;
    }

  //}

  vx_core::Func_any_from_any_context vx_core::e_any_from_any_context = std::make_shared<vx_core::Class_any_from_any_context>();
  vx_core::Func_any_from_any_context vx_core::t_any_from_any_context = std::make_shared<vx_core::Class_any_from_any_context>();

  template <class T, class U> std::shared_ptr<T> vx_core::f_any_from_any_context(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value, vx_core::Type_context context) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    return output;
  }

  /**
   * 
   * @async
   * @function any_from_any_context_async
   * Function Type taking any value any-2 and returning generic any-1
   * @param  {any-2} value
   * @return {any-1}
   * (func any<-any-context-async)
   */
  //class Func_any_from_any_context_async {

    // static
    vx_core::Func_any_from_any_context_async vx_core::Class_any_from_any_context_async::fn_new(vx_core::Class_any_from_any_context_async::IFn fn) {
      vx_core::Func_any_from_any_context_async output;
      output->fn = fn;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_any_context_async::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_any_context_async output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_any_context_async::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_any_context_async output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_any_from_any_context_async::vx_typedef() {return vx_core::t_any_from_any_context_async->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_any_from_any_context_async::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-any-context-async", // name
        0, // idx
        true, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_any_context_async::vx_empty(std::shared_ptr<T> val) {return vx_core::e_any_from_any_context_async;}
    template <class T> std::shared_ptr<T> vx_core::Class_any_from_any_context_async::vx_type(std::shared_ptr<T> val) {return vx_core::t_any_from_any_context_async;}

    std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_core::Class_any_from_any_context_async::vx_repl(vx_core::Type_anylist arglist) {
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> output = vx_core::async_new_from_val(vx_core::e_any);
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any value = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_context context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> future = vx_core::f_any_from_any_context_async(generic_any_1, value, context);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_core::Class_any_from_any_context_async::vx_any_from_any_context_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value, vx_core::Type_context context) {
      std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> output;
      if (fn == NULL) {
        output = vx_core::async_new_from_val(vx_core::f_empty(generic_any_1));
      } else {
        std::shared_ptr<vx_core::Async<vx_core::Type_any>> future = fn(value, context);
        output = vx_core::async_from_async(generic_any_1, future);
      }
      return output;
    }

  //}

  vx_core::Func_any_from_any_context_async vx_core::e_any_from_any_context_async = std::make_shared<vx_core::Class_any_from_any_context_async>();
  vx_core::Func_any_from_any_context_async vx_core::t_any_from_any_context_async = std::make_shared<vx_core::Class_any_from_any_context_async>();

  template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_core::f_any_from_any_context_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value, vx_core::Type_context context) {
    std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> output = vx_core::async_new_from_val(vx_core::f_empty(generic_any_1));
    return output;
  }

  /**
   * 
   * @async
   * @function any_from_func_async
   * Function Type returning Generic any-1 with any parameters
   * @return {any-1}
   * (func any<-func-async)
   */
  //class Func_any_from_func_async {

    // static
    vx_core::Func_any_from_func_async vx_core::Class_any_from_func_async::fn_new(vx_core::Class_any_from_func_async::IFn fn) {
      vx_core::Func_any_from_func_async output;
      output->fn = fn;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_func_async::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_func_async output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_func_async::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_func_async output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_any_from_func_async::vx_typedef() {return vx_core::t_any_from_func_async->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_any_from_func_async::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-func-async", // name
        0, // idx
        true, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_func_async::vx_empty(std::shared_ptr<T> val) {return vx_core::e_any_from_func_async;}
    template <class T> std::shared_ptr<T> vx_core::Class_any_from_func_async::vx_type(std::shared_ptr<T> val) {return vx_core::t_any_from_func_async;}

    std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_core::Class_any_from_func_async::vx_repl(vx_core::Type_anylist arglist) {
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> output = vx_core::async_new_from_val(vx_core::e_any);
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> future = vx_core::f_any_from_func_async(generic_any_1);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    template <class T> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_core::Class_any_from_func_async::vx_any_from_func_async(std::shared_ptr<T> generic_any_1) {
      std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> output;
      if (fn == NULL) {
        output = vx_core::async_new_from_val(vx_core::f_empty(generic_any_1));
      } else {
        std::shared_ptr<vx_core::Async<vx_core::Type_any>> future = fn();
        output = vx_core::async_from_async(generic_any_1, future);
      }
      return output;
    }

  //}

  vx_core::Func_any_from_func_async vx_core::e_any_from_func_async = std::make_shared<vx_core::Class_any_from_func_async>();
  vx_core::Func_any_from_func_async vx_core::t_any_from_func_async = std::make_shared<vx_core::Class_any_from_func_async>();

  template <class T> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_core::f_any_from_func_async(std::shared_ptr<T> generic_any_1) {
    std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> output = vx_core::async_new_from_val(vx_core::f_empty(generic_any_1));
    return output;
  }

  /**
   * @function any_from_key_value
   * @param  {string} key
   * @param  {any-2} val
   * @return {any-1}
   * (func any<-key-value)
   */
  //class Func_any_from_key_value {

    vx_core::Func_any_from_key_value vx_core::Class_any_from_key_value::fn_new(vx_core::Class_any_from_key_value::IFn fn) {
      vx_core::Func_any_from_key_value output;
      output->fn = fn;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_key_value::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_key_value output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_key_value::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_key_value output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_any_from_key_value::vx_typedef() {return vx_core::t_any_from_key_value->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_any_from_key_value::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-key-value", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_key_value::vx_empty(std::shared_ptr<T> val) {return vx_core::e_any_from_key_value;}
    template <class T> std::shared_ptr<T> vx_core::Class_any_from_key_value::vx_type(std::shared_ptr<T> val) {return vx_core::t_any_from_key_value;}

    vx_core::Type_any vx_core::Class_any_from_key_value::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_string key = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any val = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_any_from_key_value(generic_any_1, key, val);
      return output;
    }

    template <class T, class U> std::shared_ptr<T> vx_core::Class_any_from_key_value::vx_any_from_key_value(std::shared_ptr<T> generic_any_1, vx_core::Type_string key, std::shared_ptr<U> val) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      if (fn != NULL) {
        output = vx_core::f_any_from_any(generic_any_1, fn(key, val));
      }
      return output;
    }

  //}

  vx_core::Func_any_from_key_value vx_core::e_any_from_key_value = std::make_shared<vx_core::Class_any_from_key_value>();
  vx_core::Func_any_from_key_value vx_core::t_any_from_key_value = std::make_shared<vx_core::Class_any_from_key_value>();

  template <class T, class U> std::shared_ptr<T> vx_core::f_any_from_key_value(std::shared_ptr<T> generic_any_1, vx_core::Type_string key, std::shared_ptr<U> val) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    return output;
  }

  /**
   * 
   * @async
   * @function any_from_key_value_async
   * @param  {string} key
   * @param  {any-2} val
   * @return {any-1}
   * (func any<-key-value-async)
   */
  //class Func_any_from_key_value_async {

    // static
    vx_core::Func_any_from_key_value_async vx_core::Class_any_from_key_value_async::fn_new(vx_core::Class_any_from_key_value_async::IFn fn) {
      vx_core::Func_any_from_key_value_async output;
      output->fn = fn;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_key_value_async::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_key_value_async output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_key_value_async::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_key_value_async output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_any_from_key_value_async::vx_typedef() {return vx_core::t_any_from_key_value_async->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_any_from_key_value_async::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-key-value-async", // name
        0, // idx
        true, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_key_value_async::vx_empty(std::shared_ptr<T> val) {return vx_core::e_any_from_key_value_async;}
    template <class T> std::shared_ptr<T> vx_core::Class_any_from_key_value_async::vx_type(std::shared_ptr<T> val) {return vx_core::t_any_from_key_value_async;}

    std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_core::Class_any_from_key_value_async::vx_repl(vx_core::Type_anylist arglist) {
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> output = vx_core::async_new_from_val(vx_core::e_any);
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_string key = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any val = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> future = vx_core::f_any_from_key_value_async(generic_any_1, key, val);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_core::Class_any_from_key_value_async::vx_any_from_key_value_async(std::shared_ptr<T> generic_any_1, vx_core::Type_string key, std::shared_ptr<U> val) {
      std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> output;
      if (fn == NULL) {
        output = vx_core::async_new_from_val(vx_core::f_empty(generic_any_1));
      } else {
        std::shared_ptr<vx_core::Async<vx_core::Type_any>> future = fn(key, val);
        output = vx_core::async_from_async(generic_any_1, future);
      }
      return output;
    }

  //}

  vx_core::Func_any_from_key_value_async vx_core::e_any_from_key_value_async = std::make_shared<vx_core::Class_any_from_key_value_async>();
  vx_core::Func_any_from_key_value_async vx_core::t_any_from_key_value_async = std::make_shared<vx_core::Class_any_from_key_value_async>();

  template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_core::f_any_from_key_value_async(std::shared_ptr<T> generic_any_1, vx_core::Type_string key, std::shared_ptr<U> val) {
    std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> output = vx_core::async_new_from_val(vx_core::f_empty(generic_any_1));
    return output;
  }

  /**
   * @function any_from_list
   * Returns nth value from a list or none if out of bounds
   * @param  {list-1} values
   * @param  {int} index
   * @return {any-1}
   * (func any<-list)
   */
  //class Func_any_from_list {

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_list::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_list output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_list::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_list output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_any_from_list::vx_typedef() {return vx_core::t_any_from_list->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_any_from_list::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-list", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_list::vx_empty(std::shared_ptr<T> val) {return vx_core::e_any_from_list;}
    template <class T> std::shared_ptr<T> vx_core::Class_any_from_list::vx_type(std::shared_ptr<T> val) {return vx_core::t_any_from_list;}

    vx_core::Type_any vx_core::Class_any_from_list::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_list values = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int index = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_any_from_list(generic_any_1, values, index);
      return output;
    }

    template <class T, class X> std::shared_ptr<T> vx_core::Class_any_from_list::vx_any_from_list(std::shared_ptr<T> generic_any_1, std::shared_ptr<X> values, vx_core::Type_int index) {
      return vx_core::f_any_from_list(generic_any_1, values, index);
    }

  //}

  vx_core::Func_any_from_list vx_core::e_any_from_list = std::make_shared<vx_core::Class_any_from_list>();
  vx_core::Func_any_from_list vx_core::t_any_from_list = std::make_shared<vx_core::Class_any_from_list>();

  template <class T, class X> std::shared_ptr<T> vx_core::f_any_from_list(std::shared_ptr<T> generic_any_1, std::shared_ptr<X> values, vx_core::Type_int index) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    return output;
  }

  /**
   * @function any_from_list_reduce
   * Returns a val from a list reduce operation
   * @param  {list-2} list
   * @param  {any-1} valstart
   * @param  {any<-reduce} fn-reduce
   * @return {any-1}
   * (func any<-list-reduce)
   */
  //class Func_any_from_list_reduce {

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_list_reduce::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_list_reduce output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_list_reduce::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_list_reduce output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_any_from_list_reduce::vx_typedef() {return vx_core::t_any_from_list_reduce->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_any_from_list_reduce::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-list-reduce", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_list_reduce::vx_empty(std::shared_ptr<T> val) {return vx_core::e_any_from_list_reduce;}
    template <class T> std::shared_ptr<T> vx_core::Class_any_from_list_reduce::vx_type(std::shared_ptr<T> val) {return vx_core::t_any_from_list_reduce;}

    vx_core::Type_any vx_core::Class_any_from_list_reduce::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_list list = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any valstart = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      vx_core::Func_any_from_reduce fn_reduce = vx_core::f_any_from_any(vx_core::t_any_from_reduce, arglist->vx_any(vx_core::t_int->vx_new_from_int(2)));
      output = vx_core::f_any_from_list_reduce(generic_any_1, list, valstart, fn_reduce);
      return output;
    }

    template <class T, class Y> std::shared_ptr<T> vx_core::Class_any_from_list_reduce::vx_any_from_list_reduce(std::shared_ptr<T> generic_any_1, std::shared_ptr<Y> list, std::shared_ptr<T> valstart, vx_core::Func_any_from_reduce fn_reduce) {
      return vx_core::f_any_from_list_reduce(generic_any_1, list, valstart, fn_reduce);
    }

  //}

  vx_core::Func_any_from_list_reduce vx_core::e_any_from_list_reduce = std::make_shared<vx_core::Class_any_from_list_reduce>();
  vx_core::Func_any_from_list_reduce vx_core::t_any_from_list_reduce = std::make_shared<vx_core::Class_any_from_list_reduce>();

  template <class T, class Y> std::shared_ptr<T> vx_core::f_any_from_list_reduce(std::shared_ptr<T> generic_any_1, std::shared_ptr<Y> list, std::shared_ptr<T> valstart, vx_core::Func_any_from_reduce fn_reduce) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    output = valstart;
    std::vector<vx_core::Type_any> listval = list->vx_list();
    for (vx_core::Type_any item : listval) {
      output = fn_reduce->f_any_from_reduce(generic_any_1, output, item);
    };
    return output;
  }

  /**
   * @function any_from_list_reduce_next
   * Returns a val from a list reduce operation
   * @param  {list-2} list
   * @param  {any-1} valstart
   * @param  {any<-reduce-next} fn-reduce-next
   * @return {any-1}
   * (func any<-list-reduce-next)
   */
  //class Func_any_from_list_reduce_next {

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_list_reduce_next::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_list_reduce_next output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_list_reduce_next::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_list_reduce_next output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_any_from_list_reduce_next::vx_typedef() {return vx_core::t_any_from_list_reduce_next->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_any_from_list_reduce_next::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-list-reduce-next", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_list_reduce_next::vx_empty(std::shared_ptr<T> val) {return vx_core::e_any_from_list_reduce_next;}
    template <class T> std::shared_ptr<T> vx_core::Class_any_from_list_reduce_next::vx_type(std::shared_ptr<T> val) {return vx_core::t_any_from_list_reduce_next;}

    vx_core::Type_any vx_core::Class_any_from_list_reduce_next::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_list list = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any valstart = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      vx_core::Func_any_from_reduce_next fn_reduce_next = vx_core::f_any_from_any(vx_core::t_any_from_reduce_next, arglist->vx_any(vx_core::t_int->vx_new_from_int(2)));
      output = vx_core::f_any_from_list_reduce_next(generic_any_1, list, valstart, fn_reduce_next);
      return output;
    }

    template <class T, class Y> std::shared_ptr<T> vx_core::Class_any_from_list_reduce_next::vx_any_from_list_reduce_next(std::shared_ptr<T> generic_any_1, std::shared_ptr<Y> list, std::shared_ptr<T> valstart, vx_core::Func_any_from_reduce_next fn_reduce_next) {
      return vx_core::f_any_from_list_reduce_next(generic_any_1, list, valstart, fn_reduce_next);
    }

  //}

  vx_core::Func_any_from_list_reduce_next vx_core::e_any_from_list_reduce_next = std::make_shared<vx_core::Class_any_from_list_reduce_next>();
  vx_core::Func_any_from_list_reduce_next vx_core::t_any_from_list_reduce_next = std::make_shared<vx_core::Class_any_from_list_reduce_next>();

  template <class T, class Y> std::shared_ptr<T> vx_core::f_any_from_list_reduce_next(std::shared_ptr<T> generic_any_1, std::shared_ptr<Y> list, std::shared_ptr<T> valstart, vx_core::Func_any_from_reduce_next fn_reduce_next) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    return output;
  }

  /**
   * @function any_from_map
   * Returns value from a map or empty if not found
   * @param  {map-1} valuemap
   * @param  {string} key
   * @return {any}
   * (func any<-map)
   */
  //class Func_any_from_map {

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_map::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_map output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_map::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_map output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_any_from_map::vx_typedef() {return vx_core::t_any_from_map->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_any_from_map::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-map", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_map::vx_empty(std::shared_ptr<T> val) {return vx_core::e_any_from_map;}
    template <class T> std::shared_ptr<T> vx_core::Class_any_from_map::vx_type(std::shared_ptr<T> val) {return vx_core::t_any_from_map;}

    vx_core::Type_any vx_core::Class_any_from_map::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_map valuemap = vx_core::f_any_from_any(vx_core::t_map, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_string key = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_any_from_map(generic_any_1, valuemap, key);
      return output;
    }

    template <class T, class N> std::shared_ptr<T> vx_core::Class_any_from_map::vx_any_from_map(std::shared_ptr<T> generic_any_1, std::shared_ptr<N> valuemap, vx_core::Type_string key) {
      return vx_core::f_any_from_map(generic_any_1, valuemap, key);
    }

  //}

  vx_core::Func_any_from_map vx_core::e_any_from_map = std::make_shared<vx_core::Class_any_from_map>();
  vx_core::Func_any_from_map vx_core::t_any_from_map = std::make_shared<vx_core::Class_any_from_map>();

  template <class T, class N> std::shared_ptr<T> vx_core::f_any_from_map(std::shared_ptr<T> generic_any_1, std::shared_ptr<N> valuemap, vx_core::Type_string key) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    return output;
  }

  /**
   * @function any_from_none
   * Function Type returning Generic any-1 with no parameters
   * @return {any-1}
   * (func any<-none)
   */
  //class Func_any_from_none {

    vx_core::Func_any_from_none vx_core::Class_any_from_none::fn_new(vx_core::Class_any_from_none::IFn fn) {
      vx_core::Func_any_from_none output;
      output->fn = fn;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_none::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_none output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_none::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_none output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_any_from_none::vx_typedef() {return vx_core::t_any_from_none->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_any_from_none::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-none", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_none::vx_empty(std::shared_ptr<T> val) {return vx_core::e_any_from_none;}
    template <class T> std::shared_ptr<T> vx_core::Class_any_from_none::vx_type(std::shared_ptr<T> val) {return vx_core::t_any_from_none;}

    vx_core::Type_any vx_core::Class_any_from_none::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_any_from_none(generic_any_1);
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_none::vx_any_from_none(std::shared_ptr<T> generic_any_1) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      if (fn != NULL) {
        output = vx_core::f_any_from_any(generic_any_1, fn());
      }
      return output;
    }

  //}

  vx_core::Func_any_from_none vx_core::e_any_from_none = std::make_shared<vx_core::Class_any_from_none>();
  vx_core::Func_any_from_none vx_core::t_any_from_none = std::make_shared<vx_core::Class_any_from_none>();

  template <class T> std::shared_ptr<T> vx_core::f_any_from_none(std::shared_ptr<T> generic_any_1) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    return output;
  }

  /**
   * 
   * @async
   * @function any_from_none_async
   * Function Type returning Generic any-1 with no parameters
   * @return {any-1}
   * (func any<-none-async)
   */
  //class Func_any_from_none_async {

    // static
    vx_core::Func_any_from_none_async vx_core::Class_any_from_none_async::fn_new(vx_core::Class_any_from_none_async::IFn fn) {
      vx_core::Func_any_from_none_async output;
      output->fn = fn;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_none_async::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_none_async output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_none_async::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_none_async output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_any_from_none_async::vx_typedef() {return vx_core::t_any_from_none_async->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_any_from_none_async::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-none-async", // name
        0, // idx
        true, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_none_async::vx_empty(std::shared_ptr<T> val) {return vx_core::e_any_from_none_async;}
    template <class T> std::shared_ptr<T> vx_core::Class_any_from_none_async::vx_type(std::shared_ptr<T> val) {return vx_core::t_any_from_none_async;}

    std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_core::Class_any_from_none_async::vx_repl(vx_core::Type_anylist arglist) {
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> output = vx_core::async_new_from_val(vx_core::e_any);
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> future = vx_core::f_any_from_none_async(generic_any_1);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    template <class T> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_core::Class_any_from_none_async::vx_any_from_none_async(std::shared_ptr<T> generic_any_1) {
      std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> output;
      if (fn == NULL) {
        output = vx_core::async_new_from_val(vx_core::f_empty(generic_any_1));
      } else {
        std::shared_ptr<vx_core::Async<vx_core::Type_any>> future = fn();
        output = vx_core::async_from_async(generic_any_1, future);
      }
      return output;
    }

  //}

  vx_core::Func_any_from_none_async vx_core::e_any_from_none_async = std::make_shared<vx_core::Class_any_from_none_async>();
  vx_core::Func_any_from_none_async vx_core::t_any_from_none_async = std::make_shared<vx_core::Class_any_from_none_async>();

  template <class T> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_core::f_any_from_none_async(std::shared_ptr<T> generic_any_1) {
    std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> output = vx_core::async_new_from_val(vx_core::f_empty(generic_any_1));
    return output;
  }

  /**
   * @function any_from_reduce
   * @param  {any-1} result
   * @param  {any-2} item
   * @return {any-1}
   * (func any<-reduce)
   */
  //class Func_any_from_reduce {

    vx_core::Func_any_from_reduce vx_core::Class_any_from_reduce::fn_new(vx_core::Class_any_from_reduce::IFn fn) {
      vx_core::Func_any_from_reduce output;
      output->fn = fn;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_reduce::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_reduce output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_reduce::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_reduce output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_any_from_reduce::vx_typedef() {return vx_core::t_any_from_reduce->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_any_from_reduce::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-reduce", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_reduce::vx_empty(std::shared_ptr<T> val) {return vx_core::e_any_from_reduce;}
    template <class T> std::shared_ptr<T> vx_core::Class_any_from_reduce::vx_type(std::shared_ptr<T> val) {return vx_core::t_any_from_reduce;}

    vx_core::Type_any vx_core::Class_any_from_reduce::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any result = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any item = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_any_from_reduce(generic_any_1, result, item);
      return output;
    }

    template <class T, class U> std::shared_ptr<T> vx_core::Class_any_from_reduce::vx_any_from_reduce(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> result, std::shared_ptr<U> item) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      if (fn != NULL) {
        output = vx_core::f_any_from_any(generic_any_1, fn(result, item));
      }
      return output;
    }

  //}

  vx_core::Func_any_from_reduce vx_core::e_any_from_reduce = std::make_shared<vx_core::Class_any_from_reduce>();
  vx_core::Func_any_from_reduce vx_core::t_any_from_reduce = std::make_shared<vx_core::Class_any_from_reduce>();

  template <class T, class U> std::shared_ptr<T> vx_core::f_any_from_reduce(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> result, std::shared_ptr<U> item) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    return output;
  }

  /**
   * 
   * @async
   * @function any_from_reduce_async
   * @param  {any-1} result
   * @param  {any-2} item
   * @return {any-1}
   * (func any<-reduce-async)
   */
  //class Func_any_from_reduce_async {

    // static
    vx_core::Func_any_from_reduce_async vx_core::Class_any_from_reduce_async::fn_new(vx_core::Class_any_from_reduce_async::IFn fn) {
      vx_core::Func_any_from_reduce_async output;
      output->fn = fn;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_reduce_async::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_reduce_async output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_reduce_async::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_reduce_async output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_any_from_reduce_async::vx_typedef() {return vx_core::t_any_from_reduce_async->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_any_from_reduce_async::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-reduce-async", // name
        0, // idx
        true, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_reduce_async::vx_empty(std::shared_ptr<T> val) {return vx_core::e_any_from_reduce_async;}
    template <class T> std::shared_ptr<T> vx_core::Class_any_from_reduce_async::vx_type(std::shared_ptr<T> val) {return vx_core::t_any_from_reduce_async;}

    std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_core::Class_any_from_reduce_async::vx_repl(vx_core::Type_anylist arglist) {
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> output = vx_core::async_new_from_val(vx_core::e_any);
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any result = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any item = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> future = vx_core::f_any_from_reduce_async(generic_any_1, result, item);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_core::Class_any_from_reduce_async::vx_any_from_reduce_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> result, std::shared_ptr<U> item) {
      std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> output;
      if (fn == NULL) {
        output = vx_core::async_new_from_val(vx_core::f_empty(generic_any_1));
      } else {
        std::shared_ptr<vx_core::Async<vx_core::Type_any>> future = fn(result, item);
        output = vx_core::async_from_async(generic_any_1, future);
      }
      return output;
    }

  //}

  vx_core::Func_any_from_reduce_async vx_core::e_any_from_reduce_async = std::make_shared<vx_core::Class_any_from_reduce_async>();
  vx_core::Func_any_from_reduce_async vx_core::t_any_from_reduce_async = std::make_shared<vx_core::Class_any_from_reduce_async>();

  template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_core::f_any_from_reduce_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> result, std::shared_ptr<U> item) {
    std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> output = vx_core::async_new_from_val(vx_core::f_empty(generic_any_1));
    return output;
  }

  /**
   * @function any_from_reduce_next
   * @param  {any-1} result
   * @param  {any-2} current
   * @param  {any-2} next
   * @return {any-1}
   * (func any<-reduce-next)
   */
  //class Func_any_from_reduce_next {

    vx_core::Func_any_from_reduce_next vx_core::Class_any_from_reduce_next::fn_new(vx_core::Class_any_from_reduce_next::IFn fn) {
      vx_core::Func_any_from_reduce_next output;
      output->fn = fn;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_reduce_next::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_reduce_next output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_reduce_next::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_reduce_next output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_any_from_reduce_next::vx_typedef() {return vx_core::t_any_from_reduce_next->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_any_from_reduce_next::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-reduce-next", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_reduce_next::vx_empty(std::shared_ptr<T> val) {return vx_core::e_any_from_reduce_next;}
    template <class T> std::shared_ptr<T> vx_core::Class_any_from_reduce_next::vx_type(std::shared_ptr<T> val) {return vx_core::t_any_from_reduce_next;}

    vx_core::Type_any vx_core::Class_any_from_reduce_next::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any result = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any current = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      vx_core::Type_any next = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(2)));
      output = vx_core::f_any_from_reduce_next(generic_any_1, result, current, next);
      return output;
    }

    template <class T, class U> std::shared_ptr<T> vx_core::Class_any_from_reduce_next::vx_any_from_reduce_next(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> result, std::shared_ptr<U> current, std::shared_ptr<U> next) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      if (fn != NULL) {
        output = vx_core::f_any_from_any(generic_any_1, fn(result, current, next));
      }
      return output;
    }

  //}

  vx_core::Func_any_from_reduce_next vx_core::e_any_from_reduce_next = std::make_shared<vx_core::Class_any_from_reduce_next>();
  vx_core::Func_any_from_reduce_next vx_core::t_any_from_reduce_next = std::make_shared<vx_core::Class_any_from_reduce_next>();

  template <class T, class U> std::shared_ptr<T> vx_core::f_any_from_reduce_next(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> result, std::shared_ptr<U> current, std::shared_ptr<U> next) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    return output;
  }

  /**
   * 
   * @async
   * @function any_from_reduce_next_async
   * @param  {any-1} result
   * @param  {any-2} current
   * @param  {any-2} next
   * @return {any-1}
   * (func any<-reduce-next-async)
   */
  //class Func_any_from_reduce_next_async {

    // static
    vx_core::Func_any_from_reduce_next_async vx_core::Class_any_from_reduce_next_async::fn_new(vx_core::Class_any_from_reduce_next_async::IFn fn) {
      vx_core::Func_any_from_reduce_next_async output;
      output->fn = fn;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_reduce_next_async::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_reduce_next_async output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_reduce_next_async::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_reduce_next_async output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_any_from_reduce_next_async::vx_typedef() {return vx_core::t_any_from_reduce_next_async->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_any_from_reduce_next_async::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-reduce-next-async", // name
        0, // idx
        true, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_reduce_next_async::vx_empty(std::shared_ptr<T> val) {return vx_core::e_any_from_reduce_next_async;}
    template <class T> std::shared_ptr<T> vx_core::Class_any_from_reduce_next_async::vx_type(std::shared_ptr<T> val) {return vx_core::t_any_from_reduce_next_async;}

    std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_core::Class_any_from_reduce_next_async::vx_repl(vx_core::Type_anylist arglist) {
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> output = vx_core::async_new_from_val(vx_core::e_any);
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any result = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any current = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      vx_core::Type_any next = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(2)));
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> future = vx_core::f_any_from_reduce_next_async(generic_any_1, result, current, next);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_core::Class_any_from_reduce_next_async::vx_any_from_reduce_next_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> result, std::shared_ptr<U> current, std::shared_ptr<U> next) {
      std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> output;
      if (fn == NULL) {
        output = vx_core::async_new_from_val(vx_core::f_empty(generic_any_1));
      } else {
        std::shared_ptr<vx_core::Async<vx_core::Type_any>> future = fn(result, current, next);
        output = vx_core::async_from_async(generic_any_1, future);
      }
      return output;
    }

  //}

  vx_core::Func_any_from_reduce_next_async vx_core::e_any_from_reduce_next_async = std::make_shared<vx_core::Class_any_from_reduce_next_async>();
  vx_core::Func_any_from_reduce_next_async vx_core::t_any_from_reduce_next_async = std::make_shared<vx_core::Class_any_from_reduce_next_async>();

  template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_core::f_any_from_reduce_next_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> result, std::shared_ptr<U> current, std::shared_ptr<U> next) {
    std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> output = vx_core::async_new_from_val(vx_core::f_empty(generic_any_1));
    return output;
  }

  /**
   * @function any_from_struct
   * Returns value from a struct
   * @param  {struct-2} vstruct
   * @param  {string} key
   * @return {any-1}
   * (func any<-struct)
   */
  //class Func_any_from_struct {

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_struct::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_struct output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_struct::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_any_from_struct output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_any_from_struct::vx_typedef() {return vx_core::t_any_from_struct->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_any_from_struct::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-struct", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_any_from_struct::vx_empty(std::shared_ptr<T> val) {return vx_core::e_any_from_struct;}
    template <class T> std::shared_ptr<T> vx_core::Class_any_from_struct::vx_type(std::shared_ptr<T> val) {return vx_core::t_any_from_struct;}

    vx_core::Type_any vx_core::Class_any_from_struct::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_struct vstruct = vx_core::f_any_from_any(vx_core::t_struct, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_string key = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_any_from_struct(generic_any_1, vstruct, key);
      return output;
    }

    template <class T, class R> std::shared_ptr<T> vx_core::Class_any_from_struct::vx_any_from_struct(std::shared_ptr<T> generic_any_1, std::shared_ptr<R> vstruct, vx_core::Type_string key) {
      return vx_core::f_any_from_struct(generic_any_1, vstruct, key);
    }

  //}

  vx_core::Func_any_from_struct vx_core::e_any_from_struct = std::make_shared<vx_core::Class_any_from_struct>();
  vx_core::Func_any_from_struct vx_core::t_any_from_struct = std::make_shared<vx_core::Class_any_from_struct>();

  template <class T, class R> std::shared_ptr<T> vx_core::f_any_from_struct(std::shared_ptr<T> generic_any_1, std::shared_ptr<R> vstruct, vx_core::Type_string key) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    return output;
  }

  /**
   * 
   * @async
   * @function async
   * Returns an asynchonous version value. This exists mostly for type-casting.
   * @param  {any-1} value
   * @return {any-1}
   * (func async)
   */
  //class Func_async {

    template <class T> std::shared_ptr<T> vx_core::Class_async::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_async output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_async::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_async output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_async::vx_typedef() {return vx_core::t_async->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_async::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "async", // name
        0, // idx
        true, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_async::vx_empty(std::shared_ptr<T> val) {return vx_core::e_async;}
    template <class T> std::shared_ptr<T> vx_core::Class_async::vx_type(std::shared_ptr<T> val) {return vx_core::t_async;}

    vx_core::Func_any_from_any_async vx_core::Class_async::fn_new(vx_core::Class_any_from_any_async::IFn fn) {return vx_core::e_any_from_any_async;}

    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_core::Class_async::f_any_from_any_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> inputval = vx_core::f_any_from_any(generic_any_1, value);
      std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> output = vx_core::f_async(generic_any_1, inputval);
      return output;
    }

    std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_core::Class_async::vx_repl(vx_core::Type_anylist arglist) {
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> output = vx_core::async_new_from_val(vx_core::e_any);
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any value = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> future = vx_core::f_async(generic_any_1, value);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    template <class T> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_core::Class_async::vx_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> value) {
      return vx_core::f_async(generic_any_1, value);
    }

  //}

  vx_core::Func_async vx_core::e_async = std::make_shared<vx_core::Class_async>();
  vx_core::Func_async vx_core::t_async = std::make_shared<vx_core::Class_async>();

  template <class T> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_core::f_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> value) {
    std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> output = vx_core::async_new_from_val(vx_core::f_empty(generic_any_1));
    return output;
  }

  /**
   * @function boolean_from_any
   * Function Type taking generic any-2 and returning boolean
   * @param  {any-1} value
   * @return {boolean}
   * (func boolean<-any)
   */
  //class Func_boolean_from_any {

    template <class T> std::shared_ptr<T> vx_core::Class_boolean_from_any::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_boolean_from_any output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_boolean_from_any::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_boolean_from_any output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_boolean_from_any::vx_typedef() {return vx_core::t_boolean_from_any->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_boolean_from_any::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "boolean<-any", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_boolean_from_any::vx_empty(std::shared_ptr<T> val) {return vx_core::e_boolean_from_any;}
    template <class T> std::shared_ptr<T> vx_core::Class_boolean_from_any::vx_type(std::shared_ptr<T> val) {return vx_core::t_boolean_from_any;}

    vx_core::Func_any_from_any vx_core::Class_boolean_from_any::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_boolean_from_any::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_core::f_boolean_from_any(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_boolean_from_any::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any value = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_boolean_from_any(value);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_boolean_from_any::vx_boolean_from_any(vx_core::Type_any value) {
      return vx_core::f_boolean_from_any(value);
    }

  //}

  vx_core::Func_boolean_from_any vx_core::e_boolean_from_any = std::make_shared<vx_core::Class_boolean_from_any>();
  vx_core::Func_boolean_from_any vx_core::t_boolean_from_any = std::make_shared<vx_core::Class_boolean_from_any>();

  vx_core::Type_boolean vx_core::f_boolean_from_any(vx_core::Type_any value) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    return output;
  }

  /**
   * @function boolean_from_func
   * Function Type returning boolean with any parameters
   * @return {boolean}
   * (func boolean<-func)
   */
  //class Func_boolean_from_func {

    template <class T> std::shared_ptr<T> vx_core::Class_boolean_from_func::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_boolean_from_func output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_boolean_from_func::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_boolean_from_func output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_boolean_from_func::vx_typedef() {return vx_core::t_boolean_from_func->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_boolean_from_func::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "boolean<-func", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_boolean_from_func::vx_empty(std::shared_ptr<T> val) {return vx_core::e_boolean_from_func;}
    template <class T> std::shared_ptr<T> vx_core::Class_boolean_from_func::vx_type(std::shared_ptr<T> val) {return vx_core::t_boolean_from_func;}

    vx_core::Func_boolean_from_func vx_core::Class_boolean_from_func::fn_new(vx_core::Class_any_from_func::IFn fn) {
      vx_core::Func_boolean_from_func output;
      output->fn = fn;
      return output;
    }

    vx_core::Type_any vx_core::Class_boolean_from_func::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      output = vx_core::f_boolean_from_func();
      return output;
    }

    vx_core::Type_boolean vx_core::Class_boolean_from_func::vx_boolean_from_func() {
      vx_core::Type_boolean output = vx_core::c_false;
      if (fn != NULL) {
        output = vx_core::f_any_from_any(vx_core::t_boolean, fn());
      }
      return output;
    }

  //}

  vx_core::Func_boolean_from_func vx_core::e_boolean_from_func = std::make_shared<vx_core::Class_boolean_from_func>();
  vx_core::Func_boolean_from_func vx_core::t_boolean_from_func = std::make_shared<vx_core::Class_boolean_from_func>();

  vx_core::Type_boolean vx_core::f_boolean_from_func() {
    vx_core::Type_boolean output = vx_core::e_boolean;
    return output;
  }

  /**
   * @function boolean_from_none
   * Function Type returning boolean with no parameters
   * @return {boolean}
   * (func boolean<-none)
   */
  //class Func_boolean_from_none {

    template <class T> std::shared_ptr<T> vx_core::Class_boolean_from_none::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_boolean_from_none output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_boolean_from_none::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_boolean_from_none output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_boolean_from_none::vx_typedef() {return vx_core::t_boolean_from_none->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_boolean_from_none::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "boolean<-none", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_boolean_from_none::vx_empty(std::shared_ptr<T> val) {return vx_core::e_boolean_from_none;}
    template <class T> std::shared_ptr<T> vx_core::Class_boolean_from_none::vx_type(std::shared_ptr<T> val) {return vx_core::t_boolean_from_none;}

    vx_core::Func_boolean_from_none vx_core::Class_boolean_from_none::fn_new(vx_core::Class_any_from_func::IFn fn) {
      vx_core::Func_boolean_from_none output;
      output->fn = fn;
      return output;
    }

    vx_core::Type_any vx_core::Class_boolean_from_none::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      output = vx_core::f_boolean_from_none();
      return output;
    }

    vx_core::Type_boolean vx_core::Class_boolean_from_none::vx_boolean_from_none() {
      vx_core::Type_boolean output = vx_core::c_false;
      if (fn != NULL) {
        output = vx_core::f_any_from_any(vx_core::t_boolean, fn());
      }
      return output;
    }

  //}

  vx_core::Func_boolean_from_none vx_core::e_boolean_from_none = std::make_shared<vx_core::Class_boolean_from_none>();
  vx_core::Func_boolean_from_none vx_core::t_boolean_from_none = std::make_shared<vx_core::Class_boolean_from_none>();

  vx_core::Type_boolean vx_core::f_boolean_from_none() {
    vx_core::Type_boolean output = vx_core::e_boolean;
    return output;
  }

  /**
   * @function case
   * @param  {list-1} values
   * @param  {any<-func} fn-any
   * @return {thenelse}
   * (func case)
   */
  //class Func_case {

    template <class T> std::shared_ptr<T> vx_core::Class_case::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_case output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_case::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_case output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_case::vx_typedef() {return vx_core::t_case->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_case::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "case", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "thenelse", // name
          ":struct", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_case::vx_empty(std::shared_ptr<T> val) {return vx_core::e_case;}
    template <class T> std::shared_ptr<T> vx_core::Class_case::vx_type(std::shared_ptr<T> val) {return vx_core::t_case;}

    vx_core::Type_any vx_core::Class_case::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_list values = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Func_any_from_func fn_any = vx_core::f_any_from_any(vx_core::t_any_from_func, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_case(values, fn_any);
      return output;
    }

    vx_core::Type_thenelse vx_core::Class_case::vx_case(vx_core::Type_list values, vx_core::Func_any_from_func fn_any) {
      return vx_core::f_case(values, fn_any);
    }

  //}

  vx_core::Func_case vx_core::e_case = std::make_shared<vx_core::Class_case>();
  vx_core::Func_case vx_core::t_case = std::make_shared<vx_core::Class_case>();

  vx_core::Type_thenelse vx_core::f_case(vx_core::Type_list values, vx_core::Func_any_from_func fn_any) {
    vx_core::Type_thenelse output = vx_core::e_thenelse;
    output = vx_core::f_new(
      vx_core::t_thenelse,
      vx_core::t_anylist->vx_new(vx_core::t_anylist, {
        vx_core::t_string->vx_new_from_string(":code"),
        vx_core::t_string->vx_new_from_string(":casemany"),
        vx_core::t_string->vx_new_from_string(":values"),
        values,
        vx_core::t_string->vx_new_from_string(":fn-any"),
        fn_any
      })
    );
    return output;
  }

  /**
   * @function case 1
   * @param  {any-1} value
   * @param  {any<-func} fn-any
   * @return {thenelse}
   * (func case)
   */
  //class Func_case_1 {

    template <class T> std::shared_ptr<T> vx_core::Class_case_1::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_case_1 output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_case_1::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_case_1 output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_case_1::vx_typedef() {return vx_core::t_case_1->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_case_1::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "case", // name
        1, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "thenelse", // name
          ":struct", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_case_1::vx_empty(std::shared_ptr<T> val) {return vx_core::e_case_1;}
    template <class T> std::shared_ptr<T> vx_core::Class_case_1::vx_type(std::shared_ptr<T> val) {return vx_core::t_case_1;}

    vx_core::Type_any vx_core::Class_case_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any value = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Func_any_from_func fn_any = vx_core::f_any_from_any(vx_core::t_any_from_func, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_case_1(value, fn_any);
      return output;
    }

    vx_core::Type_thenelse vx_core::Class_case_1::vx_case_1(vx_core::Type_any value, vx_core::Func_any_from_func fn_any) {
      return vx_core::f_case_1(value, fn_any);
    }

  //}

  vx_core::Func_case_1 vx_core::e_case_1 = std::make_shared<vx_core::Class_case_1>();
  vx_core::Func_case_1 vx_core::t_case_1 = std::make_shared<vx_core::Class_case_1>();

  vx_core::Type_thenelse vx_core::f_case_1(vx_core::Type_any value, vx_core::Func_any_from_func fn_any) {
    vx_core::Type_thenelse output = vx_core::e_thenelse;
    output = vx_core::f_new(
      vx_core::t_thenelse,
      vx_core::t_anylist->vx_new(vx_core::t_anylist, {
        vx_core::t_string->vx_new_from_string(":code"),
        vx_core::t_string->vx_new_from_string(":case"),
        vx_core::t_string->vx_new_from_string(":value"),
        value,
        vx_core::t_string->vx_new_from_string(":fn-any"),
        fn_any
      })
    );
    return output;
  }

  /**
   * @function compare
   * Returns 0 if vals are equal, 1 if val1 > val2, -1 if val1 < val2
   * @param  {any} val1
   * @param  {any} val2
   * @return {int}
   * (func compare)
   */
  //class Func_compare {

    template <class T> std::shared_ptr<T> vx_core::Class_compare::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_compare output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_compare::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_compare output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_compare::vx_typedef() {return vx_core::t_compare->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_compare::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "compare", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // traits
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

    template <class T> std::shared_ptr<T> vx_core::Class_compare::vx_empty(std::shared_ptr<T> val) {return vx_core::e_compare;}
    template <class T> std::shared_ptr<T> vx_core::Class_compare::vx_type(std::shared_ptr<T> val) {return vx_core::t_compare;}

    vx_core::Type_any vx_core::Class_compare::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any val1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any val2 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_compare(val1, val2);
      return output;
    }

    vx_core::Type_int vx_core::Class_compare::vx_compare(vx_core::Type_any val1, vx_core::Type_any val2) {
      return vx_core::f_compare(val1, val2);
    }

  //}

  vx_core::Func_compare vx_core::e_compare = std::make_shared<vx_core::Class_compare>();
  vx_core::Func_compare vx_core::t_compare = std::make_shared<vx_core::Class_compare>();

  vx_core::Type_int vx_core::f_compare(vx_core::Type_any val1, vx_core::Type_any val2) {
    vx_core::Type_int output = vx_core::e_int;
    return output;
  }

  /**
   * @function contains
   * Returns true if the given list contains the given value.
   * @param  {string} text
   * @param  {string} find
   * @return {boolean}
   * (func contains)
   */
  //class Func_contains {

    template <class T> std::shared_ptr<T> vx_core::Class_contains::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_contains output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_contains::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_contains output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_contains::vx_typedef() {return vx_core::t_contains->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_contains::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "contains", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_contains::vx_empty(std::shared_ptr<T> val) {return vx_core::e_contains;}
    template <class T> std::shared_ptr<T> vx_core::Class_contains::vx_type(std::shared_ptr<T> val) {return vx_core::t_contains;}

    vx_core::Type_any vx_core::Class_contains::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_string find = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_contains(text, find);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_contains::vx_contains(vx_core::Type_string text, vx_core::Type_string find) {
      return vx_core::f_contains(text, find);
    }

  //}

  vx_core::Func_contains vx_core::e_contains = std::make_shared<vx_core::Class_contains>();
  vx_core::Func_contains vx_core::t_contains = std::make_shared<vx_core::Class_contains>();

  vx_core::Type_boolean vx_core::f_contains(vx_core::Type_string text, vx_core::Type_string find) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    return output;
  }

  /**
   * @function contains 1
   * Returns true if the given list contains the given value.
   * @param  {list-2} values Any list
   * @param  {any} find Any value
   * @return {boolean}
   * (func contains)
   */
  //class Func_contains_1 {

    template <class T> std::shared_ptr<T> vx_core::Class_contains_1::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_contains_1 output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_contains_1::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_contains_1 output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_contains_1::vx_typedef() {return vx_core::t_contains_1->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_contains_1::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "contains", // name
        1, // idx
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

    template <class T> std::shared_ptr<T> vx_core::Class_contains_1::vx_empty(std::shared_ptr<T> val) {return vx_core::e_contains_1;}
    template <class T> std::shared_ptr<T> vx_core::Class_contains_1::vx_type(std::shared_ptr<T> val) {return vx_core::t_contains_1;}

    vx_core::Type_any vx_core::Class_contains_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_list values = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any find = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_contains_1(values, find);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_contains_1::vx_contains_1(vx_core::Type_list values, vx_core::Type_any find) {
      return vx_core::f_contains_1(values, find);
    }

  //}

  vx_core::Func_contains_1 vx_core::e_contains_1 = std::make_shared<vx_core::Class_contains_1>();
  vx_core::Func_contains_1 vx_core::t_contains_1 = std::make_shared<vx_core::Class_contains_1>();

  vx_core::Type_boolean vx_core::f_contains_1(vx_core::Type_list values, vx_core::Type_any find) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    return output;
  }

  /**
   * @function copy
   * Returns a copy of a given value with the given values added or updated.
   * @param  {any-1} value
   * @param  {anylist} values
   * @return {any-1}
   * (func copy)
   */
  //class Func_copy {

    template <class T> std::shared_ptr<T> vx_core::Class_copy::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_copy output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_copy::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_copy output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_copy::vx_typedef() {return vx_core::t_copy->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_copy::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "copy", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_copy::vx_empty(std::shared_ptr<T> val) {return vx_core::e_copy;}
    template <class T> std::shared_ptr<T> vx_core::Class_copy::vx_type(std::shared_ptr<T> val) {return vx_core::t_copy;}

    vx_core::Type_any vx_core::Class_copy::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any value = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_anylist values = vx_core::f_any_from_any(vx_core::t_anylist, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_copy(value, values);
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_copy::vx_copy(std::shared_ptr<T> value, vx_core::Type_anylist values) {
      return vx_core::f_copy(value, values);
    }

  //}

  vx_core::Func_copy vx_core::e_copy = std::make_shared<vx_core::Class_copy>();
  vx_core::Func_copy vx_core::t_copy = std::make_shared<vx_core::Class_copy>();

  template <class T> std::shared_ptr<T> vx_core::f_copy(std::shared_ptr<T> value, vx_core::Type_anylist values) {
    return output;
  }

  /**
   * @function else
   * @param  {any<-func} fn-any
   * @return {thenelse}
   * (func else)
   */
  //class Func_else {

    template <class T> std::shared_ptr<T> vx_core::Class_else::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_else output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_else::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_else output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_else::vx_typedef() {return vx_core::t_else->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_else::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "else", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "thenelse", // name
          ":struct", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_else::vx_empty(std::shared_ptr<T> val) {return vx_core::e_else;}
    template <class T> std::shared_ptr<T> vx_core::Class_else::vx_type(std::shared_ptr<T> val) {return vx_core::t_else;}

    vx_core::Func_any_from_any vx_core::Class_else::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_else::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Func_any_from_func inputval = (vx_core::Func_any_from_func)value;
      vx_core::Type_any outputval = vx_core::f_else(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_else::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Func_any_from_func fn_any = vx_core::f_any_from_any(vx_core::t_any_from_func, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_else(fn_any);
      return output;
    }

    vx_core::Type_thenelse vx_core::Class_else::vx_else(vx_core::Func_any_from_func fn_any) {
      return vx_core::f_else(fn_any);
    }

  //}

  vx_core::Func_else vx_core::e_else = std::make_shared<vx_core::Class_else>();
  vx_core::Func_else vx_core::t_else = std::make_shared<vx_core::Class_else>();

  vx_core::Type_thenelse vx_core::f_else(vx_core::Func_any_from_func fn_any) {
    vx_core::Type_thenelse output = vx_core::e_thenelse;
    output = vx_core::f_new(
      vx_core::t_thenelse,
      vx_core::t_anylist->vx_new(vx_core::t_anylist, {
        vx_core::t_string->vx_new_from_string(":code"),
        vx_core::t_string->vx_new_from_string(":else"),
        vx_core::t_string->vx_new_from_string(":fn-any"),
        fn_any
      })
    );
    return output;
  }

  /**
   * @function empty
   * Returns the empty value for a given type. Can be called using (empty type) or simply (type)
   * @param  {any-1} type
   * @return {any-1}
   * (func empty)
   */
  //class Func_empty {

    template <class T> std::shared_ptr<T> vx_core::Class_empty::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_empty output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_empty::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_empty output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_empty::vx_typedef() {return vx_core::t_empty->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_empty::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "empty", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_empty::vx_empty(std::shared_ptr<T> val) {return vx_core::e_empty;}
    template <class T> std::shared_ptr<T> vx_core::Class_empty::vx_type(std::shared_ptr<T> val) {return vx_core::t_empty;}

    vx_core::Func_any_from_any vx_core::Class_empty::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_empty::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_core::f_empty(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_empty::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any type = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_empty(type);
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_empty::vx_empty(std::shared_ptr<T> type) {
      return vx_core::f_empty(type);
    }

  //}

  vx_core::Func_empty vx_core::e_empty = std::make_shared<vx_core::Class_empty>();
  vx_core::Func_empty vx_core::t_empty = std::make_shared<vx_core::Class_empty>();

  template <class T> std::shared_ptr<T> vx_core::f_empty(std::shared_ptr<T> type) {
    return output;
  }

  /**
   * @function extends_from_any
   * @param  {any-1} val
   * @return {string}
   * (func extends<-any)
   */
  //class Func_extends_from_any {

    template <class T> std::shared_ptr<T> vx_core::Class_extends_from_any::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_extends_from_any output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_extends_from_any::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_extends_from_any output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_extends_from_any::vx_typedef() {return vx_core::t_extends_from_any->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_extends_from_any::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "extends<-any", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_extends_from_any::vx_empty(std::shared_ptr<T> val) {return vx_core::e_extends_from_any;}
    template <class T> std::shared_ptr<T> vx_core::Class_extends_from_any::vx_type(std::shared_ptr<T> val) {return vx_core::t_extends_from_any;}

    vx_core::Func_any_from_any vx_core::Class_extends_from_any::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_extends_from_any::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_core::f_extends_from_any(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_extends_from_any::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any val = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_extends_from_any(val);
      return output;
    }

    vx_core::Type_string vx_core::Class_extends_from_any::vx_extends_from_any(vx_core::Type_any val) {
      return vx_core::f_extends_from_any(val);
    }

  //}

  vx_core::Func_extends_from_any vx_core::e_extends_from_any = std::make_shared<vx_core::Class_extends_from_any>();
  vx_core::Func_extends_from_any vx_core::t_extends_from_any = std::make_shared<vx_core::Class_extends_from_any>();

  vx_core::Type_string vx_core::f_extends_from_any(vx_core::Type_any val) {
    vx_core::Type_string output = vx_core::e_string;
    output = vx_core::f_extends_from_typedef(
      vx_core::f_typedef_from_any(val)
    );
    return output;
  }

  /**
   * @function extends_from_typedef
   * Get the basetype of a given type
   * @param  {typedef} vtypedef
   * @return {string}
   * (func extends<-typedef)
   */
  //class Func_extends_from_typedef {

    template <class T> std::shared_ptr<T> vx_core::Class_extends_from_typedef::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_extends_from_typedef output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_extends_from_typedef::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_extends_from_typedef output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_extends_from_typedef::vx_typedef() {return vx_core::t_extends_from_typedef->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_extends_from_typedef::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "extends<-typedef", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_extends_from_typedef::vx_empty(std::shared_ptr<T> val) {return vx_core::e_extends_from_typedef;}
    template <class T> std::shared_ptr<T> vx_core::Class_extends_from_typedef::vx_type(std::shared_ptr<T> val) {return vx_core::t_extends_from_typedef;}

    vx_core::Func_any_from_any vx_core::Class_extends_from_typedef::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_extends_from_typedef::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_typedef inputval = (vx_core::Type_typedef)value;
      vx_core::Type_any outputval = vx_core::f_extends_from_typedef(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_extends_from_typedef::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_typedef vtypedef = vx_core::f_any_from_any(vx_core::t_typedef, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_extends_from_typedef(vtypedef);
      return output;
    }

    vx_core::Type_string vx_core::Class_extends_from_typedef::vx_extends_from_typedef(vx_core::Type_typedef vtypedef) {
      return vx_core::f_extends_from_typedef(vtypedef);
    }

  //}

  vx_core::Func_extends_from_typedef vx_core::e_extends_from_typedef = std::make_shared<vx_core::Class_extends_from_typedef>();
  vx_core::Func_extends_from_typedef vx_core::t_extends_from_typedef = std::make_shared<vx_core::Class_extends_from_typedef>();

  vx_core::Type_string vx_core::f_extends_from_typedef(vx_core::Type_typedef vtypedef) {
    vx_core::Type_string output = vx_core::e_string;
    output = vtypedef->extend();
    return output;
  }

  /**
   * @function first_from_list
   * Returns first value
   * @param  {list-1} values
   * @return {any-1}
   * (func first<-list)
   */
  //class Func_first_from_list {

    template <class T> std::shared_ptr<T> vx_core::Class_first_from_list::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_first_from_list output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_first_from_list::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_first_from_list output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_first_from_list::vx_typedef() {return vx_core::t_first_from_list->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_first_from_list::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "first<-list", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_first_from_list::vx_empty(std::shared_ptr<T> val) {return vx_core::e_first_from_list;}
    template <class T> std::shared_ptr<T> vx_core::Class_first_from_list::vx_type(std::shared_ptr<T> val) {return vx_core::t_first_from_list;}

    vx_core::Func_any_from_any vx_core::Class_first_from_list::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_first_from_list::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_list inputval = (vx_core::Type_list)value;
      vx_core::Type_any outputval = vx_core::f_first_from_list(vx_core::t_any, inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_first_from_list::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_list values = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_first_from_list(generic_any_1, values);
      return output;
    }

    template <class T, class X> std::shared_ptr<T> vx_core::Class_first_from_list::vx_first_from_list(std::shared_ptr<T> generic_any_1, std::shared_ptr<X> values) {
      return vx_core::f_first_from_list(generic_any_1, values);
    }

  //}

  vx_core::Func_first_from_list vx_core::e_first_from_list = std::make_shared<vx_core::Class_first_from_list>();
  vx_core::Func_first_from_list vx_core::t_first_from_list = std::make_shared<vx_core::Class_first_from_list>();

  template <class T, class X> std::shared_ptr<T> vx_core::f_first_from_list(std::shared_ptr<T> generic_any_1, std::shared_ptr<X> values) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    output = vx_core::f_any_from_list(generic_any_1, values, vx_core::t_int->vx_new_from_int(0));
    return output;
  }

  /**
   * @function first_from_list_fn_any_from_any
   * Returns first value that is not nothing
   * @param  {list-1} values
   * @param  {any<-any} fn-any<-any
   * @return {any-1}
   * (func first<-list-fn-any<-any)
   */
  //class Func_first_from_list_fn_any_from_any {

    template <class T> std::shared_ptr<T> vx_core::Class_first_from_list_fn_any_from_any::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_first_from_list_fn_any_from_any output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_first_from_list_fn_any_from_any::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_first_from_list_fn_any_from_any output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_first_from_list_fn_any_from_any::vx_typedef() {return vx_core::t_first_from_list_fn_any_from_any->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_first_from_list_fn_any_from_any::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "first<-list-fn-any<-any", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_first_from_list_fn_any_from_any::vx_empty(std::shared_ptr<T> val) {return vx_core::e_first_from_list_fn_any_from_any;}
    template <class T> std::shared_ptr<T> vx_core::Class_first_from_list_fn_any_from_any::vx_type(std::shared_ptr<T> val) {return vx_core::t_first_from_list_fn_any_from_any;}

    vx_core::Type_any vx_core::Class_first_from_list_fn_any_from_any::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_list values = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Func_any_from_any fn_any_from_any = vx_core::f_any_from_any(vx_core::t_any_from_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_first_from_list_fn_any_from_any(generic_any_1, values, fn_any_from_any);
      return output;
    }

    template <class T, class X> std::shared_ptr<T> vx_core::Class_first_from_list_fn_any_from_any::vx_first_from_list_fn_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<X> values, vx_core::Func_any_from_any fn_any_from_any) {
      return vx_core::f_first_from_list_fn_any_from_any(generic_any_1, values, fn_any_from_any);
    }

  //}

  vx_core::Func_first_from_list_fn_any_from_any vx_core::e_first_from_list_fn_any_from_any = std::make_shared<vx_core::Class_first_from_list_fn_any_from_any>();
  vx_core::Func_first_from_list_fn_any_from_any vx_core::t_first_from_list_fn_any_from_any = std::make_shared<vx_core::Class_first_from_list_fn_any_from_any>();

  template <class T, class X> std::shared_ptr<T> vx_core::f_first_from_list_fn_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<X> values, vx_core::Func_any_from_any fn_any_from_any) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    return output;
  }

  /**
   * @function fn
   * Shell for lambda function calls
   * @param  {arglist} params
   * @param  {any<-func} fn-any
   * @return {any-1}
   * (func fn)
   */
  //class Func_fn {

    template <class T> std::shared_ptr<T> vx_core::Class_fn::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_fn output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_fn::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_fn output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_fn::vx_typedef() {return vx_core::t_fn->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_fn::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "fn", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_fn::vx_empty(std::shared_ptr<T> val) {return vx_core::e_fn;}
    template <class T> std::shared_ptr<T> vx_core::Class_fn::vx_type(std::shared_ptr<T> val) {return vx_core::t_fn;}

    vx_core::Type_any vx_core::Class_fn::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_arglist params = vx_core::f_any_from_any(vx_core::t_arglist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Func_any_from_func fn_any = vx_core::f_any_from_any(vx_core::t_any_from_func, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_fn(generic_any_1, params, fn_any);
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_fn::vx_fn(std::shared_ptr<T> generic_any_1, vx_core::Type_arglist params, vx_core::Func_any_from_func fn_any) {
      return vx_core::f_fn(generic_any_1, params, fn_any);
    }

  //}

  vx_core::Func_fn vx_core::e_fn = std::make_shared<vx_core::Class_fn>();
  vx_core::Func_fn vx_core::t_fn = std::make_shared<vx_core::Class_fn>();

  template <class T> std::shared_ptr<T> vx_core::f_fn(std::shared_ptr<T> generic_any_1, vx_core::Type_arglist params, vx_core::Func_any_from_func fn_any) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    return output;
  }

  /**
   * @function funcdef_from_func
   * @param  {func} val
   * @return {funcdef}
   * (func funcdef<-func)
   */
  //class Func_funcdef_from_func {

    template <class T> std::shared_ptr<T> vx_core::Class_funcdef_from_func::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_funcdef_from_func output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_funcdef_from_func::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_funcdef_from_func output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_funcdef_from_func::vx_typedef() {return vx_core::t_funcdef_from_func->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_funcdef_from_func::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "funcdef<-func", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "funcdef", // name
          ":struct", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_funcdef_from_func::vx_empty(std::shared_ptr<T> val) {return vx_core::e_funcdef_from_func;}
    template <class T> std::shared_ptr<T> vx_core::Class_funcdef_from_func::vx_type(std::shared_ptr<T> val) {return vx_core::t_funcdef_from_func;}

    vx_core::Func_any_from_any vx_core::Class_funcdef_from_func::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_funcdef_from_func::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_func inputval = (vx_core::Type_func)value;
      vx_core::Type_any outputval = vx_core::f_funcdef_from_func(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_funcdef_from_func::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_func val = vx_core::f_any_from_any(vx_core::t_func, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_funcdef_from_func(val);
      return output;
    }

    vx_core::Type_funcdef vx_core::Class_funcdef_from_func::vx_funcdef_from_func(vx_core::Type_func val) {
      return vx_core::f_funcdef_from_func(val);
    }

  //}

  vx_core::Func_funcdef_from_func vx_core::e_funcdef_from_func = std::make_shared<vx_core::Class_funcdef_from_func>();
  vx_core::Func_funcdef_from_func vx_core::t_funcdef_from_func = std::make_shared<vx_core::Class_funcdef_from_func>();

  vx_core::Type_funcdef vx_core::f_funcdef_from_func(vx_core::Type_func val) {
    vx_core::Type_funcdef output = vx_core::e_funcdef;
    return output;
  }

  /**
   * @function funcname_from_funcdef
   * Get the name of a given funcdef
   * @param  {funcdef} funcdef
   * @return {string}
   * (func funcname<-funcdef)
   */
  //class Func_funcname_from_funcdef {

    template <class T> std::shared_ptr<T> vx_core::Class_funcname_from_funcdef::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_funcname_from_funcdef output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_funcname_from_funcdef::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_funcname_from_funcdef output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_funcname_from_funcdef::vx_typedef() {return vx_core::t_funcname_from_funcdef->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_funcname_from_funcdef::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "funcname<-funcdef", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_funcname_from_funcdef::vx_empty(std::shared_ptr<T> val) {return vx_core::e_funcname_from_funcdef;}
    template <class T> std::shared_ptr<T> vx_core::Class_funcname_from_funcdef::vx_type(std::shared_ptr<T> val) {return vx_core::t_funcname_from_funcdef;}

    vx_core::Func_any_from_any vx_core::Class_funcname_from_funcdef::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_funcname_from_funcdef::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_funcdef inputval = (vx_core::Type_funcdef)value;
      vx_core::Type_any outputval = vx_core::f_funcname_from_funcdef(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_funcname_from_funcdef::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_funcdef funcdef = vx_core::f_any_from_any(vx_core::t_funcdef, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_funcname_from_funcdef(funcdef);
      return output;
    }

    vx_core::Type_string vx_core::Class_funcname_from_funcdef::vx_funcname_from_funcdef(vx_core::Type_funcdef funcdef) {
      return vx_core::f_funcname_from_funcdef(funcdef);
    }

  //}

  vx_core::Func_funcname_from_funcdef vx_core::e_funcname_from_funcdef = std::make_shared<vx_core::Class_funcname_from_funcdef>();
  vx_core::Func_funcname_from_funcdef vx_core::t_funcname_from_funcdef = std::make_shared<vx_core::Class_funcname_from_funcdef>();

  vx_core::Type_string vx_core::f_funcname_from_funcdef(vx_core::Type_funcdef funcdef) {
    vx_core::Type_string output = vx_core::e_string;
    output = vx_core::f_new(
      vx_core::t_string,
      vx_core::t_anylist->vx_new(vx_core::t_anylist, {
        funcdef->pkgname(),
        vx_core::t_string->vx_new_from_string("/"),
        funcdef->name()
      })
    );
    return output;
  }

  /**
   * @function global_package_get
   * @param  {string} pkgname
   * @return {package}
   * (func global-package-get)
   */
  //class Func_global_package_get {

    template <class T> std::shared_ptr<T> vx_core::Class_global_package_get::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_global_package_get output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_global_package_get::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_global_package_get output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_global_package_get::vx_typedef() {return vx_core::t_global_package_get->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_global_package_get::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "global-package-get", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "package", // name
          ":struct", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_global_package_get::vx_empty(std::shared_ptr<T> val) {return vx_core::e_global_package_get;}
    template <class T> std::shared_ptr<T> vx_core::Class_global_package_get::vx_type(std::shared_ptr<T> val) {return vx_core::t_global_package_get;}

    vx_core::Func_any_from_any vx_core::Class_global_package_get::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_global_package_get::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_string inputval = (vx_core::Type_string)value;
      vx_core::Type_any outputval = vx_core::f_global_package_get(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_global_package_get::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string pkgname = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_global_package_get(pkgname);
      return output;
    }

    vx_core::Type_package vx_core::Class_global_package_get::vx_global_package_get(vx_core::Type_string pkgname) {
      return vx_core::f_global_package_get(pkgname);
    }

  //}

  vx_core::Func_global_package_get vx_core::e_global_package_get = std::make_shared<vx_core::Class_global_package_get>();
  vx_core::Func_global_package_get vx_core::t_global_package_get = std::make_shared<vx_core::Class_global_package_get>();

  vx_core::Type_package vx_core::f_global_package_get(vx_core::Type_string pkgname) {
    vx_core::Type_package output = vx_core::e_package;
    return output;
  }

  /**
   * @function global_package_set
   * @param  {string} pkgname
   * @param  {package} pkg
   * @return {none}
   * (func global-package-set)
   */
  //class Func_global_package_set {

    template <class T> std::shared_ptr<T> vx_core::Class_global_package_set::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_global_package_set output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_global_package_set::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_global_package_set output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_global_package_set::vx_typedef() {return vx_core::t_global_package_set->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_global_package_set::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "global-package-set", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "none", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_global_package_set::vx_empty(std::shared_ptr<T> val) {return vx_core::e_global_package_set;}
    template <class T> std::shared_ptr<T> vx_core::Class_global_package_set::vx_type(std::shared_ptr<T> val) {return vx_core::t_global_package_set;}

    vx_core::Type_any vx_core::Class_global_package_set::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string pkgname = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_package pkg = vx_core::f_any_from_any(vx_core::t_package, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      vx_core::f_global_package_set(pkgname, pkg);
      return output;
    }

    void vx_core::Class_global_package_set::vx_global_package_set(vx_core::Type_string pkgname, vx_core::Type_package pkg) {vx_core::f_global_package_set(pkgname, pkg);
    }

  //}

  vx_core::Func_global_package_set vx_core::e_global_package_set = std::make_shared<vx_core::Class_global_package_set>();
  vx_core::Func_global_package_set vx_core::t_global_package_set = std::make_shared<vx_core::Class_global_package_set>();

  void vx_core::f_global_package_set(vx_core::Type_string pkgname, vx_core::Type_package pkg) {
  }

  /**
   * @function if
   * Logical If function
   * @param  {boolean} clause
   * @param  {any-1} then
   * @return {any-1}
   * (func if)
   */
  //class Func_if {

    template <class T> std::shared_ptr<T> vx_core::Class_if::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_if output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_if::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_if output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_if::vx_typedef() {return vx_core::t_if->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_if::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "if", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_if::vx_empty(std::shared_ptr<T> val) {return vx_core::e_if;}
    template <class T> std::shared_ptr<T> vx_core::Class_if::vx_type(std::shared_ptr<T> val) {return vx_core::t_if;}

    vx_core::Type_any vx_core::Class_if::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_boolean clause = vx_core::f_any_from_any(vx_core::t_boolean, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any then = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_if(generic_any_1, clause, then);
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_if::vx_if(std::shared_ptr<T> generic_any_1, vx_core::Type_boolean clause, std::shared_ptr<T> then) {
      return vx_core::f_if(generic_any_1, clause, then);
    }

  //}

  vx_core::Func_if vx_core::e_if = std::make_shared<vx_core::Class_if>();
  vx_core::Func_if vx_core::t_if = std::make_shared<vx_core::Class_if>();

  template <class T> std::shared_ptr<T> vx_core::f_if(std::shared_ptr<T> generic_any_1, vx_core::Type_boolean clause, std::shared_ptr<T> then) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    return output;
  }

  /**
   * @function if 1
   * Logical If function
   * @param  {boolean} clause
   * @param  {any-1} thenval
   * @param  {any-1} elseval
   * @return {any-1}
   * (func if)
   */
  //class Func_if_1 {

    template <class T> std::shared_ptr<T> vx_core::Class_if_1::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_if_1 output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_if_1::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_if_1 output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_if_1::vx_typedef() {return vx_core::t_if_1->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_if_1::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "if", // name
        1, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_if_1::vx_empty(std::shared_ptr<T> val) {return vx_core::e_if_1;}
    template <class T> std::shared_ptr<T> vx_core::Class_if_1::vx_type(std::shared_ptr<T> val) {return vx_core::t_if_1;}

    vx_core::Type_any vx_core::Class_if_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_boolean clause = vx_core::f_any_from_any(vx_core::t_boolean, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any thenval = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      vx_core::Type_any elseval = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(2)));
      output = vx_core::f_if_1(generic_any_1, clause, thenval, elseval);
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_if_1::vx_if_1(std::shared_ptr<T> generic_any_1, vx_core::Type_boolean clause, std::shared_ptr<T> thenval, std::shared_ptr<T> elseval) {
      return vx_core::f_if_1(generic_any_1, clause, thenval, elseval);
    }

  //}

  vx_core::Func_if_1 vx_core::e_if_1 = std::make_shared<vx_core::Class_if_1>();
  vx_core::Func_if_1 vx_core::t_if_1 = std::make_shared<vx_core::Class_if_1>();

  template <class T> std::shared_ptr<T> vx_core::f_if_1(std::shared_ptr<T> generic_any_1, vx_core::Type_boolean clause, std::shared_ptr<T> thenval, std::shared_ptr<T> elseval) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    return output;
  }

  /**
   * @function if 2
   * Logical If function
   * @param  {thenelselist} thenelselist
   * @return {any-1}
   * (func if)
   */
  //class Func_if_2 {

    template <class T> std::shared_ptr<T> vx_core::Class_if_2::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_if_2 output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_if_2::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_if_2 output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_if_2::vx_typedef() {return vx_core::t_if_2->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_if_2::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "if", // name
        2, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_if_2::vx_empty(std::shared_ptr<T> val) {return vx_core::e_if_2;}
    template <class T> std::shared_ptr<T> vx_core::Class_if_2::vx_type(std::shared_ptr<T> val) {return vx_core::t_if_2;}

    vx_core::Func_any_from_any vx_core::Class_if_2::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_if_2::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_thenelselist inputval = (vx_core::Type_thenelselist)value;
      vx_core::Type_any outputval = vx_core::f_if_2(vx_core::t_any, inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_if_2::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_thenelselist thenelselist = vx_core::f_any_from_any(vx_core::t_thenelselist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_if_2(generic_any_1, thenelselist);
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_if_2::vx_if_2(std::shared_ptr<T> generic_any_1, vx_core::Type_thenelselist thenelselist) {
      return vx_core::f_if_2(generic_any_1, thenelselist);
    }

  //}

  vx_core::Func_if_2 vx_core::e_if_2 = std::make_shared<vx_core::Class_if_2>();
  vx_core::Func_if_2 vx_core::t_if_2 = std::make_shared<vx_core::Class_if_2>();

  template <class T> std::shared_ptr<T> vx_core::f_if_2(std::shared_ptr<T> generic_any_1, vx_core::Type_thenelselist thenelselist) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    return output;
  }

  /**
   * @function int_from_func
   * Function Type returning int with any parameters
   * @return {int}
   * (func int<-func)
   */
  //class Func_int_from_func {

    template <class T> std::shared_ptr<T> vx_core::Class_int_from_func::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_int_from_func output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_int_from_func::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_int_from_func output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_int_from_func::vx_typedef() {return vx_core::t_int_from_func->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_int_from_func::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "int<-func", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // traits
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

    template <class T> std::shared_ptr<T> vx_core::Class_int_from_func::vx_empty(std::shared_ptr<T> val) {return vx_core::e_int_from_func;}
    template <class T> std::shared_ptr<T> vx_core::Class_int_from_func::vx_type(std::shared_ptr<T> val) {return vx_core::t_int_from_func;}

    vx_core::Func_int_from_func vx_core::Class_int_from_func::fn_new(vx_core::Class_any_from_func::IFn fn) {
      vx_core::Func_int_from_func output;
      output->fn = fn;
      return output;
    }

    vx_core::Type_any vx_core::Class_int_from_func::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      output = vx_core::f_int_from_func();
      return output;
    }

    vx_core::Type_int vx_core::Class_int_from_func::vx_int_from_func() {
      vx_core::Type_int output = vx_core::e_int;
      if (fn != NULL) {
        output = vx_core::f_any_from_any(vx_core::t_int, fn());
      }
      return output;
    }

  //}

  vx_core::Func_int_from_func vx_core::e_int_from_func = std::make_shared<vx_core::Class_int_from_func>();
  vx_core::Func_int_from_func vx_core::t_int_from_func = std::make_shared<vx_core::Class_int_from_func>();

  vx_core::Type_int vx_core::f_int_from_func() {
    vx_core::Type_int output = vx_core::e_int;
    return output;
  }

  /**
   * @function int_from_string
   * Function Type converting string to int
   * @param  {string} val
   * @return {int}
   * (func int<-string)
   */
  //class Func_int_from_string {

    template <class T> std::shared_ptr<T> vx_core::Class_int_from_string::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_int_from_string output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_int_from_string::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_int_from_string output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_int_from_string::vx_typedef() {return vx_core::t_int_from_string->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_int_from_string::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "int<-string", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // traits
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

    template <class T> std::shared_ptr<T> vx_core::Class_int_from_string::vx_empty(std::shared_ptr<T> val) {return vx_core::e_int_from_string;}
    template <class T> std::shared_ptr<T> vx_core::Class_int_from_string::vx_type(std::shared_ptr<T> val) {return vx_core::t_int_from_string;}

    vx_core::Func_any_from_any vx_core::Class_int_from_string::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_int_from_string::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_string inputval = (vx_core::Type_string)value;
      vx_core::Type_any outputval = vx_core::f_int_from_string(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_int_from_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string val = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_int_from_string(val);
      return output;
    }

    vx_core::Type_int vx_core::Class_int_from_string::vx_int_from_string(vx_core::Type_string val) {
      return vx_core::f_int_from_string(val);
    }

  //}

  vx_core::Func_int_from_string vx_core::e_int_from_string = std::make_shared<vx_core::Class_int_from_string>();
  vx_core::Func_int_from_string vx_core::t_int_from_string = std::make_shared<vx_core::Class_int_from_string>();

  vx_core::Type_int vx_core::f_int_from_string(vx_core::Type_string val) {
    vx_core::Type_int output = vx_core::e_int;
    output = vx_core::f_switch(
      vx_core::t_int,
      val,
      vx_core::t_thenelselist->vx_new(vx_core::t_thenelselist, {
        vx_core::f_case_1(
          vx_core::t_string->vx_new_from_string("notanumber"),
          vx_core::t_any_from_func->fn_new([]() {
            return vx_core::c_notanumber;
          })
        ),
        vx_core::f_case_1(
          vx_core::t_string->vx_new_from_string("infinity"),
          vx_core::t_any_from_func->fn_new([]() {
            return vx_core::c_infinity;
          })
        ),
        vx_core::f_case_1(
          vx_core::t_string->vx_new_from_string("neginfinity"),
          vx_core::t_any_from_func->fn_new([]() {
            return vx_core::c_neginfinity;
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func->fn_new([val]() {// :capture val
            vx_core::Type_int intresult = vx_core::e_int;
            try {
              std::string sval = val->vx_string();
              int ival = std::stoi(sval);
              intresult = vx_core::t_int->vx_new_from_int(ival);
            } catch (std::exception ex) {
              intresult = vx_core::c_notanumber;
            }
            return intresult;
          })
        )
      })
    );
    return output;
  }

  /**
   * @function is_empty
   * Returns true if text is empty.
   * @param  {string} text
   * @return {boolean}
   * (func is-empty)
   */
  //class Func_is_empty {

    template <class T> std::shared_ptr<T> vx_core::Class_is_empty::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_is_empty output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_is_empty::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_is_empty output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_is_empty::vx_typedef() {return vx_core::t_is_empty->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_is_empty::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "is-empty", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_is_empty::vx_empty(std::shared_ptr<T> val) {return vx_core::e_is_empty;}
    template <class T> std::shared_ptr<T> vx_core::Class_is_empty::vx_type(std::shared_ptr<T> val) {return vx_core::t_is_empty;}

    vx_core::Func_any_from_any vx_core::Class_is_empty::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_is_empty::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_string inputval = (vx_core::Type_string)value;
      vx_core::Type_any outputval = vx_core::f_is_empty(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_is_empty::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_is_empty(text);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_is_empty::vx_is_empty(vx_core::Type_string text) {
      return vx_core::f_is_empty(text);
    }

  //}

  vx_core::Func_is_empty vx_core::e_is_empty = std::make_shared<vx_core::Class_is_empty>();
  vx_core::Func_is_empty vx_core::t_is_empty = std::make_shared<vx_core::Class_is_empty>();

  vx_core::Type_boolean vx_core::f_is_empty(vx_core::Type_string text) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    if (text->vx_string().length() == 0) {
     output = vx_core::c_true;
    };
    return output;
  }

  /**
   * @function is_empty 1
   * Returns true if an value is empty
   * @param  {any} value
   * @return {boolean}
   * (func is-empty)
   */
  //class Func_is_empty_1 {

    template <class T> std::shared_ptr<T> vx_core::Class_is_empty_1::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_is_empty_1 output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_is_empty_1::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_is_empty_1 output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_is_empty_1::vx_typedef() {return vx_core::t_is_empty_1->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_is_empty_1::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "is-empty", // name
        1, // idx
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

    template <class T> std::shared_ptr<T> vx_core::Class_is_empty_1::vx_empty(std::shared_ptr<T> val) {return vx_core::e_is_empty_1;}
    template <class T> std::shared_ptr<T> vx_core::Class_is_empty_1::vx_type(std::shared_ptr<T> val) {return vx_core::t_is_empty_1;}

    vx_core::Func_any_from_any vx_core::Class_is_empty_1::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_is_empty_1::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_core::f_is_empty_1(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_is_empty_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any value = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_is_empty_1(value);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_is_empty_1::vx_is_empty_1(vx_core::Type_any value) {
      return vx_core::f_is_empty_1(value);
    }

  //}

  vx_core::Func_is_empty_1 vx_core::e_is_empty_1 = std::make_shared<vx_core::Class_is_empty_1>();
  vx_core::Func_is_empty_1 vx_core::t_is_empty_1 = std::make_shared<vx_core::Class_is_empty_1>();

  vx_core::Type_boolean vx_core::f_is_empty_1(vx_core::Type_any value) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    if (value == value->vx_empty(value)) {
      output = vx_core::c_true;
    } else {
      output = vx_core::c_false;
    };
    return output;
  }

  /**
   * @function is_endswith
   * Returns true if text ends with find.
   * @param  {string} text
   * @param  {string} find
   * @return {boolean}
   * (func is-endswith)
   */
  //class Func_is_endswith {

    template <class T> std::shared_ptr<T> vx_core::Class_is_endswith::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_is_endswith output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_is_endswith::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_is_endswith output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_is_endswith::vx_typedef() {return vx_core::t_is_endswith->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_is_endswith::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "is-endswith", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_is_endswith::vx_empty(std::shared_ptr<T> val) {return vx_core::e_is_endswith;}
    template <class T> std::shared_ptr<T> vx_core::Class_is_endswith::vx_type(std::shared_ptr<T> val) {return vx_core::t_is_endswith;}

    vx_core::Type_any vx_core::Class_is_endswith::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_string find = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_is_endswith(text, find);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_is_endswith::vx_is_endswith(vx_core::Type_string text, vx_core::Type_string find) {
      return vx_core::f_is_endswith(text, find);
    }

  //}

  vx_core::Func_is_endswith vx_core::e_is_endswith = std::make_shared<vx_core::Class_is_endswith>();
  vx_core::Func_is_endswith vx_core::t_is_endswith = std::make_shared<vx_core::Class_is_endswith>();

  vx_core::Type_boolean vx_core::f_is_endswith(vx_core::Type_string text, vx_core::Type_string find) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    return output;
  }

  /**
   * @function is_func
   * Returns true if val is a function.
   * @param  {any} val
   * @return {boolean}
   * (func is-func)
   */
  //class Func_is_func {

    template <class T> std::shared_ptr<T> vx_core::Class_is_func::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_is_func output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_is_func::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_is_func output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_is_func::vx_typedef() {return vx_core::t_is_func->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_is_func::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "is-func", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_is_func::vx_empty(std::shared_ptr<T> val) {return vx_core::e_is_func;}
    template <class T> std::shared_ptr<T> vx_core::Class_is_func::vx_type(std::shared_ptr<T> val) {return vx_core::t_is_func;}

    vx_core::Func_any_from_any vx_core::Class_is_func::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_is_func::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_core::f_is_func(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_is_func::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any val = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_is_func(val);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_is_func::vx_is_func(vx_core::Type_any val) {
      return vx_core::f_is_func(val);
    }

  //}

  vx_core::Func_is_func vx_core::e_is_func = std::make_shared<vx_core::Class_is_func>();
  vx_core::Func_is_func vx_core::t_is_func = std::make_shared<vx_core::Class_is_func>();

  vx_core::Type_boolean vx_core::f_is_func(vx_core::Type_any val) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    return output;
  }

  /**
   * @function is_int
   * Returns true if the value is an integer.
   * @param  {any} value
   * @return {boolean}
   * (func is-int)
   */
  //class Func_is_int {

    template <class T> std::shared_ptr<T> vx_core::Class_is_int::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_is_int output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_is_int::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_is_int output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_is_int::vx_typedef() {return vx_core::t_is_int->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_is_int::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "is-int", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_is_int::vx_empty(std::shared_ptr<T> val) {return vx_core::e_is_int;}
    template <class T> std::shared_ptr<T> vx_core::Class_is_int::vx_type(std::shared_ptr<T> val) {return vx_core::t_is_int;}

    vx_core::Func_any_from_any vx_core::Class_is_int::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_is_int::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_core::f_is_int(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_is_int::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any value = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_is_int(value);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_is_int::vx_is_int(vx_core::Type_any value) {
      return vx_core::f_is_int(value);
    }

  //}

  vx_core::Func_is_int vx_core::e_is_int = std::make_shared<vx_core::Class_is_int>();
  vx_core::Func_is_int vx_core::t_is_int = std::make_shared<vx_core::Class_is_int>();

  vx_core::Type_boolean vx_core::f_is_int(vx_core::Type_any value) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    return output;
  }

  /**
   * @function is_number
   * Return true if val is a number
   * @param  {any} value
   * @return {boolean}
   * (func is-number)
   */
  //class Func_is_number {

    template <class T> std::shared_ptr<T> vx_core::Class_is_number::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_is_number output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_is_number::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_is_number output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_is_number::vx_typedef() {return vx_core::t_is_number->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_is_number::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "is-number", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_is_number::vx_empty(std::shared_ptr<T> val) {return vx_core::e_is_number;}
    template <class T> std::shared_ptr<T> vx_core::Class_is_number::vx_type(std::shared_ptr<T> val) {return vx_core::t_is_number;}

    vx_core::Func_any_from_any vx_core::Class_is_number::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_is_number::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_core::f_is_number(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_is_number::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any value = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_is_number(value);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_is_number::vx_is_number(vx_core::Type_any value) {
      return vx_core::f_is_number(value);
    }

  //}

  vx_core::Func_is_number vx_core::e_is_number = std::make_shared<vx_core::Class_is_number>();
  vx_core::Func_is_number vx_core::t_is_number = std::make_shared<vx_core::Class_is_number>();

  vx_core::Type_boolean vx_core::f_is_number(vx_core::Type_any value) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_core::f_switch(
      vx_core::t_boolean,
      vx_core::f_typename_from_any(value),
      vx_core::t_thenelselist->vx_new(vx_core::t_thenelselist, {
        vx_core::f_case(
          vx_core::f_new(
            vx_core::t_list,
            vx_core::t_anylist->vx_new(vx_core::t_anylist, {
              vx_core::t_string->vx_new_from_string("vx/core/decimal"),
              vx_core::t_string->vx_new_from_string("vx/core/float"),
              vx_core::t_string->vx_new_from_string("vx/core/int"),
              vx_core::t_string->vx_new_from_string("vx/core/number")
            })
          ),
          vx_core::t_any_from_func->fn_new([]() {
            return vx_core::t_boolean->vx_new_from_boolean(true);
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func->fn_new([]() {
            return vx_core::t_boolean->vx_new_from_boolean(false);
          })
        )
      })
    );
    return output;
  }

  /**
   * @function is_pass_from_permission
   * Returns true if permission passes.
   * @param  {permission} permission
   * @return {boolean}
   * (func is-pass<-permission)
   */
  //class Func_is_pass_from_permission {

    template <class T> std::shared_ptr<T> vx_core::Class_is_pass_from_permission::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_is_pass_from_permission output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_is_pass_from_permission::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_is_pass_from_permission output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_is_pass_from_permission::vx_typedef() {return vx_core::t_is_pass_from_permission->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_is_pass_from_permission::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "is-pass<-permission", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_is_pass_from_permission::vx_empty(std::shared_ptr<T> val) {return vx_core::e_is_pass_from_permission;}
    template <class T> std::shared_ptr<T> vx_core::Class_is_pass_from_permission::vx_type(std::shared_ptr<T> val) {return vx_core::t_is_pass_from_permission;}

    vx_core::Func_any_from_any_context vx_core::Class_is_pass_from_permission::fn_new(vx_core::Class_any_from_any_context::IFn fn) {return vx_core::e_any_from_any_context;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_is_pass_from_permission::f_any_from_any_context(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value, vx_core::Type_context context) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_permission inputval = (vx_core::Type_permission)value;
      vx_core::Type_any outputval = vx_core::f_is_pass_from_permission(inputval, context);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_is_pass_from_permission::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_permission permission = vx_core::f_any_from_any(vx_core::t_permission, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_context context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_is_pass_from_permission(permission, context);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_is_pass_from_permission::vx_is_pass_from_permission(vx_core::Type_permission permission, vx_core::Type_context context) {
      return vx_core::f_is_pass_from_permission(permission, context);
    }

  //}

  vx_core::Func_is_pass_from_permission vx_core::e_is_pass_from_permission = std::make_shared<vx_core::Class_is_pass_from_permission>();
  vx_core::Func_is_pass_from_permission vx_core::t_is_pass_from_permission = std::make_shared<vx_core::Class_is_pass_from_permission>();

  vx_core::Type_boolean vx_core::f_is_pass_from_permission(vx_core::Type_permission permission, vx_core::Type_context context) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_core::f_let(
      vx_core::t_boolean,
      vx_core::t_any_from_func->fn_new([permission, context]() {
        vx_core::Type_string id = permission->id();
        vx_core::Type_permission lookup = vx_core::f_permission_from_id_context(id, context);
        return vx_core::f_eq(lookup, permission);
      })
    );
    return output;
  }

  /**
   * @function last_from_list
   * Returns last value
   * @param  {list-1} values
   * @return {any-1}
   * (func last<-list)
   */
  //class Func_last_from_list {

    template <class T> std::shared_ptr<T> vx_core::Class_last_from_list::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_last_from_list output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_last_from_list::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_last_from_list output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_last_from_list::vx_typedef() {return vx_core::t_last_from_list->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_last_from_list::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "last<-list", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_last_from_list::vx_empty(std::shared_ptr<T> val) {return vx_core::e_last_from_list;}
    template <class T> std::shared_ptr<T> vx_core::Class_last_from_list::vx_type(std::shared_ptr<T> val) {return vx_core::t_last_from_list;}

    vx_core::Func_any_from_any vx_core::Class_last_from_list::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_last_from_list::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_list inputval = (vx_core::Type_list)value;
      vx_core::Type_any outputval = vx_core::f_last_from_list(vx_core::t_any, inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_last_from_list::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_list values = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_last_from_list(generic_any_1, values);
      return output;
    }

    template <class T, class X> std::shared_ptr<T> vx_core::Class_last_from_list::vx_last_from_list(std::shared_ptr<T> generic_any_1, std::shared_ptr<X> values) {
      return vx_core::f_last_from_list(generic_any_1, values);
    }

  //}

  vx_core::Func_last_from_list vx_core::e_last_from_list = std::make_shared<vx_core::Class_last_from_list>();
  vx_core::Func_last_from_list vx_core::t_last_from_list = std::make_shared<vx_core::Class_last_from_list>();

  template <class T, class X> std::shared_ptr<T> vx_core::f_last_from_list(std::shared_ptr<T> generic_any_1, std::shared_ptr<X> values) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    output = vx_core::f_let(
      generic_any_1,
      vx_core::t_any_from_func->fn_new([values]() {
        vx_core::Type_int len = vx_core::f_length_from_list(values);
        vx_core::Type_int last = vx_core::f_minus(len, vx_core::t_int->vx_new_from_int(1));
        return vx_core::f_any_from_list(generic_any_1, values, last);
      })
    );
    return output;
  }

  /**
   * @function length_from_list
   * Returns the currently used size/length of a list
   * @param  {list-1} values
   * @return {int}
   * (func length<-list)
   */
  //class Func_length_from_list {

    template <class T> std::shared_ptr<T> vx_core::Class_length_from_list::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_length_from_list output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_length_from_list::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_length_from_list output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_length_from_list::vx_typedef() {return vx_core::t_length_from_list->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_length_from_list::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "length<-list", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // traits
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

    template <class T> std::shared_ptr<T> vx_core::Class_length_from_list::vx_empty(std::shared_ptr<T> val) {return vx_core::e_length_from_list;}
    template <class T> std::shared_ptr<T> vx_core::Class_length_from_list::vx_type(std::shared_ptr<T> val) {return vx_core::t_length_from_list;}

    vx_core::Func_any_from_any vx_core::Class_length_from_list::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_length_from_list::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_list inputval = (vx_core::Type_list)value;
      vx_core::Type_any outputval = vx_core::f_length_from_list(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_length_from_list::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_list values = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_length_from_list(values);
      return output;
    }

    vx_core::Type_int vx_core::Class_length_from_list::vx_length_from_list(vx_core::Type_list values) {
      return vx_core::f_length_from_list(values);
    }

  //}

  vx_core::Func_length_from_list vx_core::e_length_from_list = std::make_shared<vx_core::Class_length_from_list>();
  vx_core::Func_length_from_list vx_core::t_length_from_list = std::make_shared<vx_core::Class_length_from_list>();

  vx_core::Type_int vx_core::f_length_from_list(vx_core::Type_list values) {
    vx_core::Type_int output = vx_core::e_int;
    return output;
  }

  /**
   * @function let
   * @param  {arglist} args
   * @param  {any<-func} fn-any
   * @return {any-1}
   * (func let)
   */
  //class Func_let {

    template <class T> std::shared_ptr<T> vx_core::Class_let::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_let output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_let::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_let output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_let::vx_typedef() {return vx_core::t_let->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_let::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "let", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_let::vx_empty(std::shared_ptr<T> val) {return vx_core::e_let;}
    template <class T> std::shared_ptr<T> vx_core::Class_let::vx_type(std::shared_ptr<T> val) {return vx_core::t_let;}

    vx_core::Type_any vx_core::Class_let::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Func_any_from_func fn_any = vx_core::f_any_from_any(vx_core::t_any_from_func, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_let(generic_any_1, fn_any);
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_let::vx_let(std::shared_ptr<T> generic_any_1, vx_core::Func_any_from_func fn_any) {
      return vx_core::f_let(generic_any_1, fn_any);
    }

  //}

  vx_core::Func_let vx_core::e_let = std::make_shared<vx_core::Class_let>();
  vx_core::Func_let vx_core::t_let = std::make_shared<vx_core::Class_let>();

  template <class T> std::shared_ptr<T> vx_core::f_let(std::shared_ptr<T> generic_any_1, vx_core::Func_any_from_func fn_any) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    return output;
  }

  /**
   * 
   * @async
   * @function let_async
   * Same as normal let but returns async values.
   * @param  {arglist} args
   * @param  {any<-func-async} fn-any-async
   * @return {any-1}
   * (func let-async)
   */
  //class Func_let_async {

    template <class T> std::shared_ptr<T> vx_core::Class_let_async::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_let_async output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_let_async::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_let_async output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_let_async::vx_typedef() {return vx_core::t_let_async->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_let_async::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "let-async", // name
        0, // idx
        true, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_let_async::vx_empty(std::shared_ptr<T> val) {return vx_core::e_let_async;}
    template <class T> std::shared_ptr<T> vx_core::Class_let_async::vx_type(std::shared_ptr<T> val) {return vx_core::t_let_async;}

    std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_core::Class_let_async::vx_repl(vx_core::Type_anylist arglist) {
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> output = vx_core::async_new_from_val(vx_core::e_any);
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Func_any_from_func_async fn_any_async = vx_core::f_any_from_any(vx_core::t_any_from_func_async, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> future = vx_core::f_let_async(generic_any_1, fn_any_async);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    template <class T> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_core::Class_let_async::vx_let_async(std::shared_ptr<T> generic_any_1, vx_core::Func_any_from_func_async fn_any_async) {
      return vx_core::f_let_async(generic_any_1, fn_any_async);
    }

  //}

  vx_core::Func_let_async vx_core::e_let_async = std::make_shared<vx_core::Class_let_async>();
  vx_core::Func_let_async vx_core::t_let_async = std::make_shared<vx_core::Class_let_async>();

  template <class T> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_core::f_let_async(std::shared_ptr<T> generic_any_1, vx_core::Func_any_from_func_async fn_any_async) {
    std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> output = vx_core::async_new_from_val(vx_core::f_empty(generic_any_1));
    return output;
  }

  /**
   * @function list_join_from_list
   * Returns a flattened list of processed items from another list
   * @param  {list-2} values
   * @param  {any<-any} fn-any<-any
   * @return {list-1}
   * (func list-join<-list)
   */
  //class Func_list_join_from_list {

    template <class T> std::shared_ptr<T> vx_core::Class_list_join_from_list::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_list_join_from_list output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_list_join_from_list::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_list_join_from_list output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_list_join_from_list::vx_typedef() {return vx_core::t_list_join_from_list->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_list_join_from_list::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "list-join<-list", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_any}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_core::Class_list_join_from_list::vx_empty(std::shared_ptr<T> val) {return vx_core::e_list_join_from_list;}
    template <class T> std::shared_ptr<T> vx_core::Class_list_join_from_list::vx_type(std::shared_ptr<T> val) {return vx_core::t_list_join_from_list;}

    vx_core::Type_any vx_core::Class_list_join_from_list::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_list generic_list_1 = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_list values = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Func_any_from_any fn_any_from_any = vx_core::f_any_from_any(vx_core::t_any_from_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_list_join_from_list(generic_list_1, values, fn_any_from_any);
      return output;
    }

    template <class X, class Y> std::shared_ptr<X> vx_core::Class_list_join_from_list::vx_list_join_from_list(std::shared_ptr<X> generic_list_1, std::shared_ptr<Y> values, vx_core::Func_any_from_any fn_any_from_any) {
      return vx_core::f_list_join_from_list(generic_list_1, values, fn_any_from_any);
    }

  //}

  vx_core::Func_list_join_from_list vx_core::e_list_join_from_list = std::make_shared<vx_core::Class_list_join_from_list>();
  vx_core::Func_list_join_from_list vx_core::t_list_join_from_list = std::make_shared<vx_core::Class_list_join_from_list>();

  template <class X, class Y> std::shared_ptr<X> vx_core::f_list_join_from_list(std::shared_ptr<X> generic_list_1, std::shared_ptr<Y> values, vx_core::Func_any_from_any fn_any_from_any) {
    std::shared_ptr<X> output = vx_core::f_empty(generic_list_1);
    return output;
  }

  /**
   * @function list_from_list
   * Returns a list of processed items from another list
   * @param  {list-2} values
   * @param  {any<-any} fn-any<-any
   * @return {list-1}
   * (func list<-list)
   */
  //class Func_list_from_list {

    template <class T> std::shared_ptr<T> vx_core::Class_list_from_list::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_list_from_list output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_list_from_list::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_list_from_list output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_list_from_list::vx_typedef() {return vx_core::t_list_from_list->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_list_from_list::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "list<-list", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_any}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_core::Class_list_from_list::vx_empty(std::shared_ptr<T> val) {return vx_core::e_list_from_list;}
    template <class T> std::shared_ptr<T> vx_core::Class_list_from_list::vx_type(std::shared_ptr<T> val) {return vx_core::t_list_from_list;}

    vx_core::Type_any vx_core::Class_list_from_list::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_list generic_list_1 = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_list values = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Func_any_from_any fn_any_from_any = vx_core::f_any_from_any(vx_core::t_any_from_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_list_from_list(generic_list_1, values, fn_any_from_any);
      return output;
    }

    template <class X, class Y> std::shared_ptr<X> vx_core::Class_list_from_list::vx_list_from_list(std::shared_ptr<X> generic_list_1, std::shared_ptr<Y> values, vx_core::Func_any_from_any fn_any_from_any) {
      return vx_core::f_list_from_list(generic_list_1, values, fn_any_from_any);
    }

  //}

  vx_core::Func_list_from_list vx_core::e_list_from_list = std::make_shared<vx_core::Class_list_from_list>();
  vx_core::Func_list_from_list vx_core::t_list_from_list = std::make_shared<vx_core::Class_list_from_list>();

  template <class X, class Y> std::shared_ptr<X> vx_core::f_list_from_list(std::shared_ptr<X> generic_list_1, std::shared_ptr<Y> values, vx_core::Func_any_from_any fn_any_from_any) {
    std::shared_ptr<X> output = vx_core::f_empty(generic_list_1);
    return output;
  }

  /**
   * 
   * @async
   * @function list_from_list_async
   * Returns an asynchronous list of the processed asynchronous items from another list
   * @param  {list-2} values
   * @param  {any<-any-async} fn-any<-any-async
   * @return {list-1}
   * (func list<-list-async)
   */
  //class Func_list_from_list_async {

    template <class T> std::shared_ptr<T> vx_core::Class_list_from_list_async::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_list_from_list_async output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_list_from_list_async::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_list_from_list_async output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_list_from_list_async::vx_typedef() {return vx_core::t_list_from_list_async->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_list_from_list_async::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "list<-list-async", // name
        0, // idx
        true, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_any}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_core::Class_list_from_list_async::vx_empty(std::shared_ptr<T> val) {return vx_core::e_list_from_list_async;}
    template <class T> std::shared_ptr<T> vx_core::Class_list_from_list_async::vx_type(std::shared_ptr<T> val) {return vx_core::t_list_from_list_async;}

    std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_core::Class_list_from_list_async::vx_repl(vx_core::Type_anylist arglist) {
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> output = vx_core::async_new_from_val(vx_core::e_any);
      vx_core::Type_list generic_list_1 = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_list values = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Func_any_from_any_async fn_any_from_any_async = vx_core::f_any_from_any(vx_core::t_any_from_any_async, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      std::shared_ptr<vx_core::Async<vx_core::Type_list>> future = vx_core::f_list_from_list_async(generic_list_1, values, fn_any_from_any_async);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    template <class X, class Y> std::shared_ptr<vx_core::Async<std::shared_ptr<X>>> vx_core::Class_list_from_list_async::vx_list_from_list_async(std::shared_ptr<X> generic_list_1, std::shared_ptr<Y> values, vx_core::Func_any_from_any_async fn_any_from_any_async) {
      return vx_core::f_list_from_list_async(generic_list_1, values, fn_any_from_any_async);
    }

  //}

  vx_core::Func_list_from_list_async vx_core::e_list_from_list_async = std::make_shared<vx_core::Class_list_from_list_async>();
  vx_core::Func_list_from_list_async vx_core::t_list_from_list_async = std::make_shared<vx_core::Class_list_from_list_async>();

  template <class X, class Y> std::shared_ptr<vx_core::Async<std::shared_ptr<X>>> vx_core::f_list_from_list_async(std::shared_ptr<X> generic_list_1, std::shared_ptr<Y> values, vx_core::Func_any_from_any_async fn_any_from_any_async) {
    std::shared_ptr<vx_core::Async<std::shared_ptr<X>>> output = vx_core::async_new_from_val(vx_core::f_empty(generic_list_1));
    return output;
  }

  /**
   * @function list_from_map
   * Returns a list from a map by applying a function to each key value.
   * @param  {map-2} valuemap
   * @param  {any<-key-value} fn-any<-key-value
   * @return {list-1}
   * (func list<-map)
   */
  //class Func_list_from_map {

    template <class T> std::shared_ptr<T> vx_core::Class_list_from_map::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_list_from_map output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_list_from_map::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_list_from_map output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_list_from_map::vx_typedef() {return vx_core::t_list_from_map->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_list_from_map::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "list<-map", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_any}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_core::Class_list_from_map::vx_empty(std::shared_ptr<T> val) {return vx_core::e_list_from_map;}
    template <class T> std::shared_ptr<T> vx_core::Class_list_from_map::vx_type(std::shared_ptr<T> val) {return vx_core::t_list_from_map;}

    vx_core::Type_any vx_core::Class_list_from_map::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_list generic_list_1 = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_map valuemap = vx_core::f_any_from_any(vx_core::t_map, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Func_any_from_key_value fn_any_from_key_value = vx_core::f_any_from_any(vx_core::t_any_from_key_value, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_list_from_map(generic_list_1, valuemap, fn_any_from_key_value);
      return output;
    }

    template <class X, class O> std::shared_ptr<X> vx_core::Class_list_from_map::vx_list_from_map(std::shared_ptr<X> generic_list_1, std::shared_ptr<O> valuemap, vx_core::Func_any_from_key_value fn_any_from_key_value) {
      return vx_core::f_list_from_map(generic_list_1, valuemap, fn_any_from_key_value);
    }

  //}

  vx_core::Func_list_from_map vx_core::e_list_from_map = std::make_shared<vx_core::Class_list_from_map>();
  vx_core::Func_list_from_map vx_core::t_list_from_map = std::make_shared<vx_core::Class_list_from_map>();

  template <class X, class O> std::shared_ptr<X> vx_core::f_list_from_map(std::shared_ptr<X> generic_list_1, std::shared_ptr<O> valuemap, vx_core::Func_any_from_key_value fn_any_from_key_value) {
    std::shared_ptr<X> output = vx_core::f_empty(generic_list_1);
    return output;
  }

  /**
   * 
   * @async
   * @function list_from_map_async
   * @param  {map-2} valuemap
   * @param  {any<-key-value-async} fn-any<-key-value-async
   * @return {list-1}
   * (func list<-map-async)
   */
  //class Func_list_from_map_async {

    template <class T> std::shared_ptr<T> vx_core::Class_list_from_map_async::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_list_from_map_async output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_list_from_map_async::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_list_from_map_async output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_list_from_map_async::vx_typedef() {return vx_core::t_list_from_map_async->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_list_from_map_async::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "list<-map-async", // name
        0, // idx
        true, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_any}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_core::Class_list_from_map_async::vx_empty(std::shared_ptr<T> val) {return vx_core::e_list_from_map_async;}
    template <class T> std::shared_ptr<T> vx_core::Class_list_from_map_async::vx_type(std::shared_ptr<T> val) {return vx_core::t_list_from_map_async;}

    std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_core::Class_list_from_map_async::vx_repl(vx_core::Type_anylist arglist) {
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> output = vx_core::async_new_from_val(vx_core::e_any);
      vx_core::Type_list generic_list_1 = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_map valuemap = vx_core::f_any_from_any(vx_core::t_map, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Func_any_from_key_value_async fn_any_from_key_value_async = vx_core::f_any_from_any(vx_core::t_any_from_key_value_async, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      std::shared_ptr<vx_core::Async<vx_core::Type_list>> future = vx_core::f_list_from_map_async(generic_list_1, valuemap, fn_any_from_key_value_async);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    template <class X, class O> std::shared_ptr<vx_core::Async<std::shared_ptr<X>>> vx_core::Class_list_from_map_async::vx_list_from_map_async(std::shared_ptr<X> generic_list_1, std::shared_ptr<O> valuemap, vx_core::Func_any_from_key_value_async fn_any_from_key_value_async) {
      return vx_core::f_list_from_map_async(generic_list_1, valuemap, fn_any_from_key_value_async);
    }

  //}

  vx_core::Func_list_from_map_async vx_core::e_list_from_map_async = std::make_shared<vx_core::Class_list_from_map_async>();
  vx_core::Func_list_from_map_async vx_core::t_list_from_map_async = std::make_shared<vx_core::Class_list_from_map_async>();

  template <class X, class O> std::shared_ptr<vx_core::Async<std::shared_ptr<X>>> vx_core::f_list_from_map_async(std::shared_ptr<X> generic_list_1, std::shared_ptr<O> valuemap, vx_core::Func_any_from_key_value_async fn_any_from_key_value_async) {
    std::shared_ptr<vx_core::Async<std::shared_ptr<X>>> output = vx_core::async_new_from_val(vx_core::f_empty(generic_list_1));
    return output;
  }

  /**
   * @function list_from_type
   * Create an empty list from a type. Used internally for default lists
   * @param  {any} type
   * @return {any}
   * (func list<-type)
   */
  //class Func_list_from_type {

    template <class T> std::shared_ptr<T> vx_core::Class_list_from_type::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_list_from_type output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_list_from_type::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_list_from_type output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_list_from_type::vx_typedef() {return vx_core::t_list_from_type->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_list_from_type::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "list<-type", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_list_from_type::vx_empty(std::shared_ptr<T> val) {return vx_core::e_list_from_type;}
    template <class T> std::shared_ptr<T> vx_core::Class_list_from_type::vx_type(std::shared_ptr<T> val) {return vx_core::t_list_from_type;}

    vx_core::Func_any_from_any vx_core::Class_list_from_type::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_list_from_type::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_core::f_list_from_type(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_list_from_type::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any type = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_list_from_type(type);
      return output;
    }

    vx_core::Type_any vx_core::Class_list_from_type::vx_list_from_type(vx_core::Type_any type) {
      return vx_core::f_list_from_type(type);
    }

  //}

  vx_core::Func_list_from_type vx_core::e_list_from_type = std::make_shared<vx_core::Class_list_from_type>();
  vx_core::Func_list_from_type vx_core::t_list_from_type = std::make_shared<vx_core::Class_list_from_type>();

  vx_core::Type_any vx_core::f_list_from_type(vx_core::Type_any type) {
    vx_core::Type_any output = vx_core::e_any;
    return output;
  }

  /**
   * @function log
   * @param  {any} value
   * @return {any}
   * (func log)
   */
  //class Func_log {

    template <class T> std::shared_ptr<T> vx_core::Class_log::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_log output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_log::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_log output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_log::vx_typedef() {return vx_core::t_log->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_log::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "log", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_log::vx_empty(std::shared_ptr<T> val) {return vx_core::e_log;}
    template <class T> std::shared_ptr<T> vx_core::Class_log::vx_type(std::shared_ptr<T> val) {return vx_core::t_log;}

    vx_core::Func_any_from_any vx_core::Class_log::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_log::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_core::f_log(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_log::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any value = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_log(value);
      return output;
    }

    vx_core::Type_any vx_core::Class_log::vx_log(vx_core::Type_any value) {
      return vx_core::f_log(value);
    }

  //}

  vx_core::Func_log vx_core::e_log = std::make_shared<vx_core::Class_log>();
  vx_core::Func_log vx_core::t_log = std::make_shared<vx_core::Class_log>();

  vx_core::Type_any vx_core::f_log(vx_core::Type_any value) {
    vx_core::Type_any output = vx_core::e_any;
    return output;
  }

  /**
   * @function map_from_list
   * Returns a list from a map by applying a function to each key value.
   * @param  {list-2} vallist
   * @param  {any<-any} fn-any<-any
   * @return {map-1}
   * (func map<-list)
   */
  //class Func_map_from_list {

    template <class T> std::shared_ptr<T> vx_core::Class_map_from_list::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_map_from_list output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_map_from_list::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_map_from_list output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_map_from_list::vx_typedef() {return vx_core::t_map_from_list->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_map_from_list::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "map<-list", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "map-1", // name
          ":map", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_any}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_core::Class_map_from_list::vx_empty(std::shared_ptr<T> val) {return vx_core::e_map_from_list;}
    template <class T> std::shared_ptr<T> vx_core::Class_map_from_list::vx_type(std::shared_ptr<T> val) {return vx_core::t_map_from_list;}

    vx_core::Type_any vx_core::Class_map_from_list::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_map generic_map_1 = vx_core::f_any_from_any(vx_core::t_map, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_list vallist = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Func_any_from_any fn_any_from_any = vx_core::f_any_from_any(vx_core::t_any_from_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_map_from_list(generic_map_1, vallist, fn_any_from_any);
      return output;
    }

    template <class Y, class N> std::shared_ptr<N> vx_core::Class_map_from_list::vx_map_from_list(std::shared_ptr<N> generic_map_1, std::shared_ptr<Y> vallist, vx_core::Func_any_from_any fn_any_from_any) {
      return vx_core::f_map_from_list(generic_map_1, vallist, fn_any_from_any);
    }

  //}

  vx_core::Func_map_from_list vx_core::e_map_from_list = std::make_shared<vx_core::Class_map_from_list>();
  vx_core::Func_map_from_list vx_core::t_map_from_list = std::make_shared<vx_core::Class_map_from_list>();

  template <class Y, class N> std::shared_ptr<N> vx_core::f_map_from_list(std::shared_ptr<N> generic_map_1, std::shared_ptr<Y> vallist, vx_core::Func_any_from_any fn_any_from_any) {
    std::shared_ptr<N> output = vx_core::f_empty(generic_map_1);
    return output;
  }

  /**
   * @function mempool_addref
   * Add Value Reference
   * @param  {anylist} values
   * @return {none}
   * (func mempool-addref)
   */
  //class Func_mempool_addref {

    template <class T> std::shared_ptr<T> vx_core::Class_mempool_addref::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_mempool_addref output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_mempool_addref::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_mempool_addref output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_mempool_addref::vx_typedef() {return vx_core::t_mempool_addref->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_mempool_addref::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "mempool-addref", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "none", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_mempool_addref::vx_empty(std::shared_ptr<T> val) {return vx_core::e_mempool_addref;}
    template <class T> std::shared_ptr<T> vx_core::Class_mempool_addref::vx_type(std::shared_ptr<T> val) {return vx_core::t_mempool_addref;}

    vx_core::Type_any vx_core::Class_mempool_addref::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_anylist values = vx_core::f_any_from_any(vx_core::t_anylist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::f_mempool_addref(values);
      return output;
    }

    void vx_core::Class_mempool_addref::vx_mempool_addref(vx_core::Type_anylist values) {vx_core::f_mempool_addref(values);
    }

  //}

  vx_core::Func_mempool_addref vx_core::e_mempool_addref = std::make_shared<vx_core::Class_mempool_addref>();
  vx_core::Func_mempool_addref vx_core::t_mempool_addref = std::make_shared<vx_core::Class_mempool_addref>();

  void vx_core::f_mempool_addref(vx_core::Type_anylist values) {
  }

  /**
   * @function mempool_release
   * Recycles a Value and adds it to the valuepool.
   * @param  {value} value
   * @return {none}
   * (func mempool-release)
   */
  //class Func_mempool_release {

    template <class T> std::shared_ptr<T> vx_core::Class_mempool_release::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_mempool_release output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_mempool_release::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_mempool_release output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_mempool_release::vx_typedef() {return vx_core::t_mempool_release->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_mempool_release::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "mempool-release", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "none", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_mempool_release::vx_empty(std::shared_ptr<T> val) {return vx_core::e_mempool_release;}
    template <class T> std::shared_ptr<T> vx_core::Class_mempool_release::vx_type(std::shared_ptr<T> val) {return vx_core::t_mempool_release;}

    vx_core::Type_any vx_core::Class_mempool_release::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_value value = vx_core::f_any_from_any(vx_core::t_value, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::f_mempool_release(value);
      return output;
    }

    void vx_core::Class_mempool_release::vx_mempool_release(vx_core::Type_value value) {vx_core::f_mempool_release(value);
    }

  //}

  vx_core::Func_mempool_release vx_core::e_mempool_release = std::make_shared<vx_core::Class_mempool_release>();
  vx_core::Func_mempool_release vx_core::t_mempool_release = std::make_shared<vx_core::Class_mempool_release>();

  void vx_core::f_mempool_release(vx_core::Type_value value) {
  }

  /**
   * @function mempool_removeref
   * Remove Value Reference
   * @param  {anylist} values
   * @return {none}
   * (func mempool-removeref)
   */
  //class Func_mempool_removeref {

    template <class T> std::shared_ptr<T> vx_core::Class_mempool_removeref::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_mempool_removeref output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_mempool_removeref::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_mempool_removeref output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_mempool_removeref::vx_typedef() {return vx_core::t_mempool_removeref->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_mempool_removeref::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "mempool-removeref", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "none", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_mempool_removeref::vx_empty(std::shared_ptr<T> val) {return vx_core::e_mempool_removeref;}
    template <class T> std::shared_ptr<T> vx_core::Class_mempool_removeref::vx_type(std::shared_ptr<T> val) {return vx_core::t_mempool_removeref;}

    vx_core::Type_any vx_core::Class_mempool_removeref::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_anylist values = vx_core::f_any_from_any(vx_core::t_anylist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::f_mempool_removeref(values);
      return output;
    }

    void vx_core::Class_mempool_removeref::vx_mempool_removeref(vx_core::Type_anylist values) {vx_core::f_mempool_removeref(values);
    }

  //}

  vx_core::Func_mempool_removeref vx_core::e_mempool_removeref = std::make_shared<vx_core::Class_mempool_removeref>();
  vx_core::Func_mempool_removeref vx_core::t_mempool_removeref = std::make_shared<vx_core::Class_mempool_removeref>();

  void vx_core::f_mempool_removeref(vx_core::Type_anylist values) {
  }

  /**
   * @function mempool_removerefchildren
   * Remove Value Child References
   * @param  {anylist} values
   * @return {none}
   * (func mempool-removerefchildren)
   */
  //class Func_mempool_removerefchildren {

    template <class T> std::shared_ptr<T> vx_core::Class_mempool_removerefchildren::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_mempool_removerefchildren output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_mempool_removerefchildren::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_mempool_removerefchildren output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_mempool_removerefchildren::vx_typedef() {return vx_core::t_mempool_removerefchildren->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_mempool_removerefchildren::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "mempool-removerefchildren", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "none", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_mempool_removerefchildren::vx_empty(std::shared_ptr<T> val) {return vx_core::e_mempool_removerefchildren;}
    template <class T> std::shared_ptr<T> vx_core::Class_mempool_removerefchildren::vx_type(std::shared_ptr<T> val) {return vx_core::t_mempool_removerefchildren;}

    vx_core::Type_any vx_core::Class_mempool_removerefchildren::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_anylist values = vx_core::f_any_from_any(vx_core::t_anylist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::f_mempool_removerefchildren(values);
      return output;
    }

    void vx_core::Class_mempool_removerefchildren::vx_mempool_removerefchildren(vx_core::Type_anylist values) {vx_core::f_mempool_removerefchildren(values);
    }

  //}

  vx_core::Func_mempool_removerefchildren vx_core::e_mempool_removerefchildren = std::make_shared<vx_core::Class_mempool_removerefchildren>();
  vx_core::Func_mempool_removerefchildren vx_core::t_mempool_removerefchildren = std::make_shared<vx_core::Class_mempool_removerefchildren>();

  void vx_core::f_mempool_removerefchildren(vx_core::Type_anylist values) {
  }

  /**
   * @function mempool_reserve
   * Returns a recycled Value or creates a new one.
   * @return {value}
   * (func mempool-reserve)
   */
  //class Func_mempool_reserve {

    template <class T> std::shared_ptr<T> vx_core::Class_mempool_reserve::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_mempool_reserve output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_mempool_reserve::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_mempool_reserve output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_mempool_reserve::vx_typedef() {return vx_core::t_mempool_reserve->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_mempool_reserve::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "mempool-reserve", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "value", // name
          ":struct", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_mempool_reserve::vx_empty(std::shared_ptr<T> val) {return vx_core::e_mempool_reserve;}
    template <class T> std::shared_ptr<T> vx_core::Class_mempool_reserve::vx_type(std::shared_ptr<T> val) {return vx_core::t_mempool_reserve;}

    vx_core::Type_any vx_core::Class_mempool_reserve::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      output = vx_core::f_mempool_reserve();
      return output;
    }

    vx_core::Type_value vx_core::Class_mempool_reserve::vx_mempool_reserve() {
      return vx_core::f_mempool_reserve();
    }

  //}

  vx_core::Func_mempool_reserve vx_core::e_mempool_reserve = std::make_shared<vx_core::Class_mempool_reserve>();
  vx_core::Func_mempool_reserve vx_core::t_mempool_reserve = std::make_shared<vx_core::Class_mempool_reserve>();

  vx_core::Type_value vx_core::f_mempool_reserve() {
    vx_core::Type_value output = vx_core::e_value;
    return output;
  }

  /**
   * @function msg_from_error
   * Returns a msg from error string
   * @param  {string} error
   * @return {msg}
   * (func msg<-error)
   */
  //class Func_msg_from_error {

    template <class T> std::shared_ptr<T> vx_core::Class_msg_from_error::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_msg_from_error output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_msg_from_error::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_msg_from_error output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_msg_from_error::vx_typedef() {return vx_core::t_msg_from_error->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_msg_from_error::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "msg<-error", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "msg", // name
          ":struct", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_msg_from_error::vx_empty(std::shared_ptr<T> val) {return vx_core::e_msg_from_error;}
    template <class T> std::shared_ptr<T> vx_core::Class_msg_from_error::vx_type(std::shared_ptr<T> val) {return vx_core::t_msg_from_error;}

    vx_core::Func_any_from_any vx_core::Class_msg_from_error::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_msg_from_error::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_string inputval = (vx_core::Type_string)value;
      vx_core::Type_any outputval = vx_core::f_msg_from_error(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_msg_from_error::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string error = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_msg_from_error(error);
      return output;
    }

    vx_core::Type_msg vx_core::Class_msg_from_error::vx_msg_from_error(vx_core::Type_string error) {
      return vx_core::f_msg_from_error(error);
    }

  //}

  vx_core::Func_msg_from_error vx_core::e_msg_from_error = std::make_shared<vx_core::Class_msg_from_error>();
  vx_core::Func_msg_from_error vx_core::t_msg_from_error = std::make_shared<vx_core::Class_msg_from_error>();

  vx_core::Type_msg vx_core::f_msg_from_error(vx_core::Type_string error) {
    vx_core::Type_msg output = vx_core::e_msg;
    output = vx_core::f_new(
      vx_core::t_msg,
      vx_core::t_anylist->vx_new(vx_core::t_anylist, {
        vx_core::t_string->vx_new_from_string(":severity"),
        vx_core::c_msg_error,
        vx_core::t_string->vx_new_from_string(":text"),
        error
      })
    );
    return output;
  }

  /**
   * @function msgblock_from_msgblock_msg
   * Return a new Msgblock with the added msg
   * @param  {msgblock} origblock
   * @param  {msg} addmsg
   * @return {msgblock}
   * (func msgblock<-msgblock-msg)
   */
  //class Func_msgblock_from_msgblock_msg {

    template <class T> std::shared_ptr<T> vx_core::Class_msgblock_from_msgblock_msg::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_msgblock_from_msgblock_msg output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_msgblock_from_msgblock_msg::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_msgblock_from_msgblock_msg output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_msgblock_from_msgblock_msg::vx_typedef() {return vx_core::t_msgblock_from_msgblock_msg->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_msgblock_from_msgblock_msg::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "msgblock<-msgblock-msg", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "msgblock", // name
          ":struct", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_msgblock_from_msgblock_msg::vx_empty(std::shared_ptr<T> val) {return vx_core::e_msgblock_from_msgblock_msg;}
    template <class T> std::shared_ptr<T> vx_core::Class_msgblock_from_msgblock_msg::vx_type(std::shared_ptr<T> val) {return vx_core::t_msgblock_from_msgblock_msg;}

    vx_core::Type_any vx_core::Class_msgblock_from_msgblock_msg::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_msgblock origblock = vx_core::f_any_from_any(vx_core::t_msgblock, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_msg addmsg = vx_core::f_any_from_any(vx_core::t_msg, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_msgblock_from_msgblock_msg(origblock, addmsg);
      return output;
    }

    vx_core::Type_msgblock vx_core::Class_msgblock_from_msgblock_msg::vx_msgblock_from_msgblock_msg(vx_core::Type_msgblock origblock, vx_core::Type_msg addmsg) {
      return vx_core::f_msgblock_from_msgblock_msg(origblock, addmsg);
    }

  //}

  vx_core::Func_msgblock_from_msgblock_msg vx_core::e_msgblock_from_msgblock_msg = std::make_shared<vx_core::Class_msgblock_from_msgblock_msg>();
  vx_core::Func_msgblock_from_msgblock_msg vx_core::t_msgblock_from_msgblock_msg = std::make_shared<vx_core::Class_msgblock_from_msgblock_msg>();

  vx_core::Type_msgblock vx_core::f_msgblock_from_msgblock_msg(vx_core::Type_msgblock origblock, vx_core::Type_msg addmsg) {
    vx_core::Type_msgblock output = vx_core::e_msgblock;
    output = vx_core::f_copy(origblock, vx_core::t_anylist->vx_new(vx_core::t_anylist, {
      addmsg}));
    return output;
  }

  /**
   * @function msgblock_from_msgblock_msgblock
   * Return a new Msgblock with the added block
   * @param  {msgblock} origblock
   * @param  {msgblock} addblock
   * @return {msgblock}
   * (func msgblock<-msgblock-msgblock)
   */
  //class Func_msgblock_from_msgblock_msgblock {

    template <class T> std::shared_ptr<T> vx_core::Class_msgblock_from_msgblock_msgblock::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_msgblock_from_msgblock_msgblock output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_msgblock_from_msgblock_msgblock::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_msgblock_from_msgblock_msgblock output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_msgblock_from_msgblock_msgblock::vx_typedef() {return vx_core::t_msgblock_from_msgblock_msgblock->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_msgblock_from_msgblock_msgblock::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "msgblock<-msgblock-msgblock", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "msgblock", // name
          ":struct", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_msgblock_from_msgblock_msgblock::vx_empty(std::shared_ptr<T> val) {return vx_core::e_msgblock_from_msgblock_msgblock;}
    template <class T> std::shared_ptr<T> vx_core::Class_msgblock_from_msgblock_msgblock::vx_type(std::shared_ptr<T> val) {return vx_core::t_msgblock_from_msgblock_msgblock;}

    vx_core::Type_any vx_core::Class_msgblock_from_msgblock_msgblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_msgblock origblock = vx_core::f_any_from_any(vx_core::t_msgblock, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_msgblock addblock = vx_core::f_any_from_any(vx_core::t_msgblock, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_msgblock_from_msgblock_msgblock(origblock, addblock);
      return output;
    }

    vx_core::Type_msgblock vx_core::Class_msgblock_from_msgblock_msgblock::vx_msgblock_from_msgblock_msgblock(vx_core::Type_msgblock origblock, vx_core::Type_msgblock addblock) {
      return vx_core::f_msgblock_from_msgblock_msgblock(origblock, addblock);
    }

  //}

  vx_core::Func_msgblock_from_msgblock_msgblock vx_core::e_msgblock_from_msgblock_msgblock = std::make_shared<vx_core::Class_msgblock_from_msgblock_msgblock>();
  vx_core::Func_msgblock_from_msgblock_msgblock vx_core::t_msgblock_from_msgblock_msgblock = std::make_shared<vx_core::Class_msgblock_from_msgblock_msgblock>();

  vx_core::Type_msgblock vx_core::f_msgblock_from_msgblock_msgblock(vx_core::Type_msgblock origblock, vx_core::Type_msgblock addblock) {
    vx_core::Type_msgblock output = vx_core::e_msgblock;
    output = vx_core::f_new(
      vx_core::t_msgblock,
      vx_core::t_anylist->vx_new(vx_core::t_anylist, {
        origblock,
        addblock
      })
    );
    return output;
  }

  /**
   * @function name_from_typedef
   * Returns the name from a typedef.
   * @param  {typedef} vtypedef
   * @return {string}
   * (func name<-typedef)
   */
  //class Func_name_from_typedef {

    template <class T> std::shared_ptr<T> vx_core::Class_name_from_typedef::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_name_from_typedef output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_name_from_typedef::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_name_from_typedef output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_name_from_typedef::vx_typedef() {return vx_core::t_name_from_typedef->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_name_from_typedef::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "name<-typedef", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_name_from_typedef::vx_empty(std::shared_ptr<T> val) {return vx_core::e_name_from_typedef;}
    template <class T> std::shared_ptr<T> vx_core::Class_name_from_typedef::vx_type(std::shared_ptr<T> val) {return vx_core::t_name_from_typedef;}

    vx_core::Func_any_from_any vx_core::Class_name_from_typedef::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_name_from_typedef::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_typedef inputval = (vx_core::Type_typedef)value;
      vx_core::Type_any outputval = vx_core::f_name_from_typedef(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_name_from_typedef::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_typedef vtypedef = vx_core::f_any_from_any(vx_core::t_typedef, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_name_from_typedef(vtypedef);
      return output;
    }

    vx_core::Type_string vx_core::Class_name_from_typedef::vx_name_from_typedef(vx_core::Type_typedef vtypedef) {
      return vx_core::f_name_from_typedef(vtypedef);
    }

  //}

  vx_core::Func_name_from_typedef vx_core::e_name_from_typedef = std::make_shared<vx_core::Class_name_from_typedef>();
  vx_core::Func_name_from_typedef vx_core::t_name_from_typedef = std::make_shared<vx_core::Class_name_from_typedef>();

  vx_core::Type_string vx_core::f_name_from_typedef(vx_core::Type_typedef vtypedef) {
    vx_core::Type_string output = vx_core::e_string;
    output = vtypedef->name();
    return output;
  }

  /**
   * @function native
   * Native Function Call
   * @param  {anylist} clauses
   * @return {any-1}
   * (func native)
   */
  //class Func_native {

    template <class T> std::shared_ptr<T> vx_core::Class_native::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_native output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_native::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_native output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_native::vx_typedef() {return vx_core::t_native->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_native::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "native", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_native::vx_empty(std::shared_ptr<T> val) {return vx_core::e_native;}
    template <class T> std::shared_ptr<T> vx_core::Class_native::vx_type(std::shared_ptr<T> val) {return vx_core::t_native;}

    vx_core::Func_any_from_any vx_core::Class_native::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_native::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_anylist inputval = (vx_core::Type_anylist)value;
      vx_core::Type_any outputval = vx_core::f_native(vx_core::t_any, inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_native::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_anylist clauses = vx_core::f_any_from_any(vx_core::t_anylist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_native(generic_any_1, clauses);
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_native::vx_native(std::shared_ptr<T> generic_any_1, vx_core::Type_anylist clauses) {
      return vx_core::f_native(generic_any_1, clauses);
    }

  //}

  vx_core::Func_native vx_core::e_native = std::make_shared<vx_core::Class_native>();
  vx_core::Func_native vx_core::t_native = std::make_shared<vx_core::Class_native>();

  template <class T> std::shared_ptr<T> vx_core::f_native(std::shared_ptr<T> generic_any_1, vx_core::Type_anylist clauses) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    return output;
  }

  /**
   * @function native_from_any
   * Returns native value of value object
   * @param  {any-1} value
   * @return {any}
   * (func native<-any)
   */
  //class Func_native_from_any {

    template <class T> std::shared_ptr<T> vx_core::Class_native_from_any::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_native_from_any output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_native_from_any::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_native_from_any output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_native_from_any::vx_typedef() {return vx_core::t_native_from_any->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_native_from_any::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "native<-any", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_native_from_any::vx_empty(std::shared_ptr<T> val) {return vx_core::e_native_from_any;}
    template <class T> std::shared_ptr<T> vx_core::Class_native_from_any::vx_type(std::shared_ptr<T> val) {return vx_core::t_native_from_any;}

    vx_core::Func_any_from_any vx_core::Class_native_from_any::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_native_from_any::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_core::f_native_from_any(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_native_from_any::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any value = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_native_from_any(value);
      return output;
    }

    vx_core::Type_any vx_core::Class_native_from_any::vx_native_from_any(vx_core::Type_any value) {
      return vx_core::f_native_from_any(value);
    }

  //}

  vx_core::Func_native_from_any vx_core::e_native_from_any = std::make_shared<vx_core::Class_native_from_any>();
  vx_core::Func_native_from_any vx_core::t_native_from_any = std::make_shared<vx_core::Class_native_from_any>();

  vx_core::Type_any vx_core::f_native_from_any(vx_core::Type_any value) {
    vx_core::Type_any output = vx_core::e_any;
    return output;
  }

  /**
   * @function new
   * Create a new Value of Type A
   * @param  {any-1} type
   * @param  {anylist} values
   * @return {any-1}
   * (func new)
   */
  //class Func_new {

    template <class T> std::shared_ptr<T> vx_core::Class_new::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_new output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_new::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_new output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_new::vx_typedef() {return vx_core::t_new->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_new::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "new", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_new::vx_empty(std::shared_ptr<T> val) {return vx_core::e_new;}
    template <class T> std::shared_ptr<T> vx_core::Class_new::vx_type(std::shared_ptr<T> val) {return vx_core::t_new;}

    vx_core::Type_any vx_core::Class_new::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any type = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_anylist values = vx_core::f_any_from_any(vx_core::t_anylist, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_new(type, values);
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_new::vx_new(std::shared_ptr<T> type, vx_core::Type_anylist values) {
      return vx_core::f_new(type, values);
    }

  //}

  vx_core::Func_new vx_core::e_new = std::make_shared<vx_core::Class_new>();
  vx_core::Func_new vx_core::t_new = std::make_shared<vx_core::Class_new>();

  template <class T> std::shared_ptr<T> vx_core::f_new(std::shared_ptr<T> type, vx_core::Type_anylist values) {
    return output;
  }

  /**
   * @function number_from_func
   * Function Type returning number with any parameters
   * @return {number}
   * (func number<-func)
   */
  //class Func_number_from_func {

    template <class T> std::shared_ptr<T> vx_core::Class_number_from_func::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_number_from_func output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_number_from_func::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_number_from_func output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_number_from_func::vx_typedef() {return vx_core::t_number_from_func->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_number_from_func::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "number<-func", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "number", // name
          "", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_int, vx_core::t_float, vx_core::t_decimal}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_core::Class_number_from_func::vx_empty(std::shared_ptr<T> val) {return vx_core::e_number_from_func;}
    template <class T> std::shared_ptr<T> vx_core::Class_number_from_func::vx_type(std::shared_ptr<T> val) {return vx_core::t_number_from_func;}

    vx_core::Type_any vx_core::Class_number_from_func::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      output = vx_core::f_number_from_func();
      return output;
    }

    vx_core::Type_number vx_core::Class_number_from_func::vx_number_from_func() {
      return vx_core::f_number_from_func();
    }

  //}

  vx_core::Func_number_from_func vx_core::e_number_from_func = std::make_shared<vx_core::Class_number_from_func>();
  vx_core::Func_number_from_func vx_core::t_number_from_func = std::make_shared<vx_core::Class_number_from_func>();

  vx_core::Type_number vx_core::f_number_from_func() {
    vx_core::Type_number output = vx_core::e_number;
    return output;
  }

  /**
   * @function or
   * Returns true if any value is true
   * @param  {boolean} val1
   * @param  {boolean} val2
   * @return {boolean}
   * (func or)
   */
  //class Func_or {

    template <class T> std::shared_ptr<T> vx_core::Class_or::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_or output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_or::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_or output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_or::vx_typedef() {return vx_core::t_or->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_or::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "or", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_or::vx_empty(std::shared_ptr<T> val) {return vx_core::e_or;}
    template <class T> std::shared_ptr<T> vx_core::Class_or::vx_type(std::shared_ptr<T> val) {return vx_core::t_or;}

    vx_core::Type_any vx_core::Class_or::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_boolean val1 = vx_core::f_any_from_any(vx_core::t_boolean, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_boolean val2 = vx_core::f_any_from_any(vx_core::t_boolean, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_or(val1, val2);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_or::vx_or(vx_core::Type_boolean val1, vx_core::Type_boolean val2) {
      return vx_core::f_or(val1, val2);
    }

  //}

  vx_core::Func_or vx_core::e_or = std::make_shared<vx_core::Class_or>();
  vx_core::Func_or vx_core::t_or = std::make_shared<vx_core::Class_or>();

  vx_core::Type_boolean vx_core::f_or(vx_core::Type_boolean val1, vx_core::Type_boolean val2) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    return output;
  }

  /**
   * @function or 1
   * Returns true if any value is true
   * @param  {booleanlist} values
   * @return {boolean}
   * (func or)
   */
  //class Func_or_1 {

    template <class T> std::shared_ptr<T> vx_core::Class_or_1::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_or_1 output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_or_1::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_or_1 output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_or_1::vx_typedef() {return vx_core::t_or_1->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_or_1::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "or", // name
        1, // idx
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

    template <class T> std::shared_ptr<T> vx_core::Class_or_1::vx_empty(std::shared_ptr<T> val) {return vx_core::e_or_1;}
    template <class T> std::shared_ptr<T> vx_core::Class_or_1::vx_type(std::shared_ptr<T> val) {return vx_core::t_or_1;}

    vx_core::Func_any_from_any vx_core::Class_or_1::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_or_1::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_booleanlist inputval = (vx_core::Type_booleanlist)value;
      vx_core::Type_any outputval = vx_core::f_or_1(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_or_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_booleanlist values = vx_core::f_any_from_any(vx_core::t_booleanlist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_or_1(values);
      return output;
    }

    vx_core::Type_boolean vx_core::Class_or_1::vx_or_1(vx_core::Type_booleanlist values) {
      return vx_core::f_or_1(values);
    }

  //}

  vx_core::Func_or_1 vx_core::e_or_1 = std::make_shared<vx_core::Class_or_1>();
  vx_core::Func_or_1 vx_core::t_or_1 = std::make_shared<vx_core::Class_or_1>();

  vx_core::Type_boolean vx_core::f_or_1(vx_core::Type_booleanlist values) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_core::f_any_from_list_reduce_next(
      vx_core::t_boolean,
      values,
      vx_core::t_boolean->vx_new_from_boolean(false),
      vx_core::t_any_from_reduce_next->fn_new([](vx_core::Type_any reduce_any, vx_core::Type_any current_any, vx_core::Type_any next_any) {
        vx_core::Type_boolean reduce = vx_core::f_any_from_any(vx_core::t_boolean, reduce_any);
        vx_core::Type_boolean current = vx_core::f_any_from_any(vx_core::t_boolean, current_any);
        vx_core::Type_boolean next = vx_core::f_any_from_any(vx_core::t_boolean, next_any);
        return 
          vx_core::f_or(
            reduce,
            vx_core::f_or(current, next)
          );
      })
    );
    return output;
  }

  /**
   * @function packagename_from_typedef
   * Returns the package name from a typedef.
   * @param  {typedef} vtypedef
   * @return {string}
   * (func packagename<-typedef)
   */
  //class Func_packagename_from_typedef {

    template <class T> std::shared_ptr<T> vx_core::Class_packagename_from_typedef::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_packagename_from_typedef output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_packagename_from_typedef::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_packagename_from_typedef output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_packagename_from_typedef::vx_typedef() {return vx_core::t_packagename_from_typedef->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_packagename_from_typedef::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "packagename<-typedef", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_packagename_from_typedef::vx_empty(std::shared_ptr<T> val) {return vx_core::e_packagename_from_typedef;}
    template <class T> std::shared_ptr<T> vx_core::Class_packagename_from_typedef::vx_type(std::shared_ptr<T> val) {return vx_core::t_packagename_from_typedef;}

    vx_core::Func_any_from_any vx_core::Class_packagename_from_typedef::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_packagename_from_typedef::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_typedef inputval = (vx_core::Type_typedef)value;
      vx_core::Type_any outputval = vx_core::f_packagename_from_typedef(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_packagename_from_typedef::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_typedef vtypedef = vx_core::f_any_from_any(vx_core::t_typedef, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_packagename_from_typedef(vtypedef);
      return output;
    }

    vx_core::Type_string vx_core::Class_packagename_from_typedef::vx_packagename_from_typedef(vx_core::Type_typedef vtypedef) {
      return vx_core::f_packagename_from_typedef(vtypedef);
    }

  //}

  vx_core::Func_packagename_from_typedef vx_core::e_packagename_from_typedef = std::make_shared<vx_core::Class_packagename_from_typedef>();
  vx_core::Func_packagename_from_typedef vx_core::t_packagename_from_typedef = std::make_shared<vx_core::Class_packagename_from_typedef>();

  vx_core::Type_string vx_core::f_packagename_from_typedef(vx_core::Type_typedef vtypedef) {
    vx_core::Type_string output = vx_core::e_string;
    output = vtypedef->pkgname();
    return output;
  }

  /**
   * @function path_from_context_path
   * Returns a path from a context
   * @param  {string} path
   * @return {string}
   * (func path<-context-path)
   */
  //class Func_path_from_context_path {

    template <class T> std::shared_ptr<T> vx_core::Class_path_from_context_path::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_path_from_context_path output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_path_from_context_path::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_path_from_context_path output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_path_from_context_path::vx_typedef() {return vx_core::t_path_from_context_path->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_path_from_context_path::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "path<-context-path", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_path_from_context_path::vx_empty(std::shared_ptr<T> val) {return vx_core::e_path_from_context_path;}
    template <class T> std::shared_ptr<T> vx_core::Class_path_from_context_path::vx_type(std::shared_ptr<T> val) {return vx_core::t_path_from_context_path;}

    vx_core::Func_any_from_any_context vx_core::Class_path_from_context_path::fn_new(vx_core::Class_any_from_any_context::IFn fn) {return vx_core::e_any_from_any_context;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_path_from_context_path::f_any_from_any_context(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value, vx_core::Type_context context) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_string inputval = (vx_core::Type_string)value;
      vx_core::Type_any outputval = vx_core::f_path_from_context_path(inputval, context);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_path_from_context_path::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string path = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_context context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_path_from_context_path(path, context);
      return output;
    }

    vx_core::Type_string vx_core::Class_path_from_context_path::vx_path_from_context_path(vx_core::Type_string path, vx_core::Type_context context) {
      return vx_core::f_path_from_context_path(path, context);
    }

  //}

  vx_core::Func_path_from_context_path vx_core::e_path_from_context_path = std::make_shared<vx_core::Class_path_from_context_path>();
  vx_core::Func_path_from_context_path vx_core::t_path_from_context_path = std::make_shared<vx_core::Class_path_from_context_path>();

  vx_core::Type_string vx_core::f_path_from_context_path(vx_core::Type_string path, vx_core::Type_context context) {
    vx_core::Type_string output = vx_core::e_string;
    output = vx_core::f_path_from_setting_path(
      vx_core::f_setting_from_context(context),
      path
    );
    return output;
  }

  /**
   * @function path_from_setting_path
   * Returns a path from a setting
   * @param  {setting} session
   * @param  {string} path
   * @return {string}
   * (func path<-setting-path)
   */
  //class Func_path_from_setting_path {

    template <class T> std::shared_ptr<T> vx_core::Class_path_from_setting_path::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_path_from_setting_path output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_path_from_setting_path::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_path_from_setting_path output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_path_from_setting_path::vx_typedef() {return vx_core::t_path_from_setting_path->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_path_from_setting_path::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "path<-setting-path", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_path_from_setting_path::vx_empty(std::shared_ptr<T> val) {return vx_core::e_path_from_setting_path;}
    template <class T> std::shared_ptr<T> vx_core::Class_path_from_setting_path::vx_type(std::shared_ptr<T> val) {return vx_core::t_path_from_setting_path;}

    vx_core::Type_any vx_core::Class_path_from_setting_path::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_setting session = vx_core::f_any_from_any(vx_core::t_setting, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_string path = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_path_from_setting_path(session, path);
      return output;
    }

    vx_core::Type_string vx_core::Class_path_from_setting_path::vx_path_from_setting_path(vx_core::Type_setting session, vx_core::Type_string path) {
      return vx_core::f_path_from_setting_path(session, path);
    }

  //}

  vx_core::Func_path_from_setting_path vx_core::e_path_from_setting_path = std::make_shared<vx_core::Class_path_from_setting_path>();
  vx_core::Func_path_from_setting_path vx_core::t_path_from_setting_path = std::make_shared<vx_core::Class_path_from_setting_path>();

  vx_core::Type_string vx_core::f_path_from_setting_path(vx_core::Type_setting session, vx_core::Type_string path) {
    vx_core::Type_string output = vx_core::e_string;
    return output;
  }

  /**
   * @function permission_from_id_context
   * Return a permission from context by id
   * @param  {string} id
   * @return {permission}
   * (func permission<-id-context)
   */
  //class Func_permission_from_id_context {

    template <class T> std::shared_ptr<T> vx_core::Class_permission_from_id_context::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_permission_from_id_context output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_permission_from_id_context::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_permission_from_id_context output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_permission_from_id_context::vx_typedef() {return vx_core::t_permission_from_id_context->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_permission_from_id_context::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "permission<-id-context", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "permission", // name
          ":struct", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_permission_from_id_context::vx_empty(std::shared_ptr<T> val) {return vx_core::e_permission_from_id_context;}
    template <class T> std::shared_ptr<T> vx_core::Class_permission_from_id_context::vx_type(std::shared_ptr<T> val) {return vx_core::t_permission_from_id_context;}

    vx_core::Func_any_from_any_context vx_core::Class_permission_from_id_context::fn_new(vx_core::Class_any_from_any_context::IFn fn) {return vx_core::e_any_from_any_context;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_permission_from_id_context::f_any_from_any_context(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value, vx_core::Type_context context) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_string inputval = (vx_core::Type_string)value;
      vx_core::Type_any outputval = vx_core::f_permission_from_id_context(inputval, context);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_permission_from_id_context::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string id = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_context context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_permission_from_id_context(id, context);
      return output;
    }

    vx_core::Type_permission vx_core::Class_permission_from_id_context::vx_permission_from_id_context(vx_core::Type_string id, vx_core::Type_context context) {
      return vx_core::f_permission_from_id_context(id, context);
    }

  //}

  vx_core::Func_permission_from_id_context vx_core::e_permission_from_id_context = std::make_shared<vx_core::Class_permission_from_id_context>();
  vx_core::Func_permission_from_id_context vx_core::t_permission_from_id_context = std::make_shared<vx_core::Class_permission_from_id_context>();

  vx_core::Type_permission vx_core::f_permission_from_id_context(vx_core::Type_string id, vx_core::Type_context context) {
    vx_core::Type_permission output = vx_core::e_permission;
    output = vx_core::f_let(
      vx_core::t_permission,
      vx_core::t_any_from_func->fn_new([context]() {
        vx_core::Type_user user = vx_core::f_user_from_context(context);
        vx_core::Type_security security = user->security();
        vx_core::Type_permissionmap permissionmap = security->permissionmap();
        return vx_core::f_any_from_map(vx_core::t_permission, permissionmap, vx_core::t_string->vx_new_from_string(":id"));
      })
    );
    return output;
  }

  /**
   * @function properties_from_typedef
   * Return property map from typedef
   * @param  {typedef} vtypedef
   * @return {argmap}
   * (func properties<-typedef)
   */
  //class Func_properties_from_typedef {

    template <class T> std::shared_ptr<T> vx_core::Class_properties_from_typedef::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_properties_from_typedef output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_properties_from_typedef::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_properties_from_typedef output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_properties_from_typedef::vx_typedef() {return vx_core::t_properties_from_typedef->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_properties_from_typedef::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "properties<-typedef", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "argmap", // name
          ":map", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_arg}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_core::Class_properties_from_typedef::vx_empty(std::shared_ptr<T> val) {return vx_core::e_properties_from_typedef;}
    template <class T> std::shared_ptr<T> vx_core::Class_properties_from_typedef::vx_type(std::shared_ptr<T> val) {return vx_core::t_properties_from_typedef;}

    vx_core::Func_any_from_any vx_core::Class_properties_from_typedef::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_properties_from_typedef::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_typedef inputval = (vx_core::Type_typedef)value;
      vx_core::Type_any outputval = vx_core::f_properties_from_typedef(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_properties_from_typedef::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_typedef vtypedef = vx_core::f_any_from_any(vx_core::t_typedef, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_properties_from_typedef(vtypedef);
      return output;
    }

    vx_core::Type_argmap vx_core::Class_properties_from_typedef::vx_properties_from_typedef(vx_core::Type_typedef vtypedef) {
      return vx_core::f_properties_from_typedef(vtypedef);
    }

  //}

  vx_core::Func_properties_from_typedef vx_core::e_properties_from_typedef = std::make_shared<vx_core::Class_properties_from_typedef>();
  vx_core::Func_properties_from_typedef vx_core::t_properties_from_typedef = std::make_shared<vx_core::Class_properties_from_typedef>();

  vx_core::Type_argmap vx_core::f_properties_from_typedef(vx_core::Type_typedef vtypedef) {
    vx_core::Type_argmap output = vx_core::e_argmap;
    output = vtypedef->properties();
    return output;
  }

  /**
   * @function proplast_from_typedef
   * Return last property from typedef
   * @param  {typedef} vtypedef
   * @return {arg}
   * (func proplast<-typedef)
   */
  //class Func_proplast_from_typedef {

    template <class T> std::shared_ptr<T> vx_core::Class_proplast_from_typedef::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_proplast_from_typedef output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_proplast_from_typedef::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_proplast_from_typedef output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_proplast_from_typedef::vx_typedef() {return vx_core::t_proplast_from_typedef->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_proplast_from_typedef::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "proplast<-typedef", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "arg", // name
          ":struct", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_proplast_from_typedef::vx_empty(std::shared_ptr<T> val) {return vx_core::e_proplast_from_typedef;}
    template <class T> std::shared_ptr<T> vx_core::Class_proplast_from_typedef::vx_type(std::shared_ptr<T> val) {return vx_core::t_proplast_from_typedef;}

    vx_core::Func_any_from_any vx_core::Class_proplast_from_typedef::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_proplast_from_typedef::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_typedef inputval = (vx_core::Type_typedef)value;
      vx_core::Type_any outputval = vx_core::f_proplast_from_typedef(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_proplast_from_typedef::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_typedef vtypedef = vx_core::f_any_from_any(vx_core::t_typedef, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_proplast_from_typedef(vtypedef);
      return output;
    }

    vx_core::Type_arg vx_core::Class_proplast_from_typedef::vx_proplast_from_typedef(vx_core::Type_typedef vtypedef) {
      return vx_core::f_proplast_from_typedef(vtypedef);
    }

  //}

  vx_core::Func_proplast_from_typedef vx_core::e_proplast_from_typedef = std::make_shared<vx_core::Class_proplast_from_typedef>();
  vx_core::Func_proplast_from_typedef vx_core::t_proplast_from_typedef = std::make_shared<vx_core::Class_proplast_from_typedef>();

  vx_core::Type_arg vx_core::f_proplast_from_typedef(vx_core::Type_typedef vtypedef) {
    vx_core::Type_arg output = vx_core::e_arg;
    output = vtypedef->proplast();
    return output;
  }

  /**
   * @function resolve
   * @param  {any-1} value
   * @return {any-1}
   * (func resolve)
   */
  //class Func_resolve {

    template <class T> std::shared_ptr<T> vx_core::Class_resolve::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_resolve output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_resolve::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_resolve output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_resolve::vx_typedef() {return vx_core::t_resolve->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_resolve::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "resolve", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_resolve::vx_empty(std::shared_ptr<T> val) {return vx_core::e_resolve;}
    template <class T> std::shared_ptr<T> vx_core::Class_resolve::vx_type(std::shared_ptr<T> val) {return vx_core::t_resolve;}

    vx_core::Func_any_from_any vx_core::Class_resolve::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_resolve::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_core::f_resolve(vx_core::t_any, inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_resolve::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any value = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_resolve(generic_any_1, value);
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_resolve::vx_resolve(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> value) {
      return vx_core::f_resolve(generic_any_1, value);
    }

  //}

  vx_core::Func_resolve vx_core::e_resolve = std::make_shared<vx_core::Class_resolve>();
  vx_core::Func_resolve vx_core::t_resolve = std::make_shared<vx_core::Class_resolve>();

  template <class T> std::shared_ptr<T> vx_core::f_resolve(std::shared_ptr<T> generic_any_1, std::shared_ptr<T> value) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    output = value;
    return output;
  }

  /**
   * @function resolve 1
   * @param  {any<-func} fn-any
   * @return {any-1}
   * (func resolve)
   */
  //class Func_resolve_1 {

    template <class T> std::shared_ptr<T> vx_core::Class_resolve_1::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_resolve_1 output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_resolve_1::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_resolve_1 output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_resolve_1::vx_typedef() {return vx_core::t_resolve_1->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_resolve_1::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "resolve", // name
        1, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_resolve_1::vx_empty(std::shared_ptr<T> val) {return vx_core::e_resolve_1;}
    template <class T> std::shared_ptr<T> vx_core::Class_resolve_1::vx_type(std::shared_ptr<T> val) {return vx_core::t_resolve_1;}

    vx_core::Func_any_from_any vx_core::Class_resolve_1::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_resolve_1::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Func_any_from_func inputval = (vx_core::Func_any_from_func)value;
      vx_core::Type_any outputval = vx_core::f_resolve_1(vx_core::t_any, inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_resolve_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Func_any_from_func fn_any = vx_core::f_any_from_any(vx_core::t_any_from_func, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_resolve_1(generic_any_1, fn_any);
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_resolve_1::vx_resolve_1(std::shared_ptr<T> generic_any_1, vx_core::Func_any_from_func fn_any) {
      return vx_core::f_resolve_1(generic_any_1, fn_any);
    }

  //}

  vx_core::Func_resolve_1 vx_core::e_resolve_1 = std::make_shared<vx_core::Class_resolve_1>();
  vx_core::Func_resolve_1 vx_core::t_resolve_1 = std::make_shared<vx_core::Class_resolve_1>();

  template <class T> std::shared_ptr<T> vx_core::f_resolve_1(std::shared_ptr<T> generic_any_1, vx_core::Func_any_from_func fn_any) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    return output;
  }

  /**
   * 
   * @async
   * @function resolve_async
   * @param  {any<-func-async} fn-any
   * @return {any-1}
   * (func resolve-async)
   */
  //class Func_resolve_async {

    template <class T> std::shared_ptr<T> vx_core::Class_resolve_async::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_resolve_async output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_resolve_async::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_resolve_async output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_resolve_async::vx_typedef() {return vx_core::t_resolve_async->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_resolve_async::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "resolve-async", // name
        0, // idx
        true, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_resolve_async::vx_empty(std::shared_ptr<T> val) {return vx_core::e_resolve_async;}
    template <class T> std::shared_ptr<T> vx_core::Class_resolve_async::vx_type(std::shared_ptr<T> val) {return vx_core::t_resolve_async;}

    vx_core::Func_any_from_any_async vx_core::Class_resolve_async::fn_new(vx_core::Class_any_from_any_async::IFn fn) {return vx_core::e_any_from_any_async;}

    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_core::Class_resolve_async::f_any_from_any_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> inputval = vx_core::f_any_from_any(generic_any_1, value);
      std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> output = vx_core::f_async(generic_any_1, inputval);
      return output;
    }

    std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_core::Class_resolve_async::vx_repl(vx_core::Type_anylist arglist) {
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> output = vx_core::async_new_from_val(vx_core::e_any);
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Func_any_from_func_async fn_any = vx_core::f_any_from_any(vx_core::t_any_from_func_async, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      std::shared_ptr<vx_core::Async<vx_core::Type_any>> future = vx_core::f_resolve_async(generic_any_1, fn_any);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    template <class T> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_core::Class_resolve_async::vx_resolve_async(std::shared_ptr<T> generic_any_1, vx_core::Func_any_from_func_async fn_any) {
      return vx_core::f_resolve_async(generic_any_1, fn_any);
    }

  //}

  vx_core::Func_resolve_async vx_core::e_resolve_async = std::make_shared<vx_core::Class_resolve_async>();
  vx_core::Func_resolve_async vx_core::t_resolve_async = std::make_shared<vx_core::Class_resolve_async>();

  template <class T> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> vx_core::f_resolve_async(std::shared_ptr<T> generic_any_1, vx_core::Func_any_from_func_async fn_any) {
    std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> output = vx_core::async_new_from_val(vx_core::f_empty(generic_any_1));
    return output;
  }

  /**
   * @function resolve_first
   * Returns the first value that is not nothing
   * @param  {list-1} clauses
   * @return {any-1}
   * (func resolve-first)
   */
  //class Func_resolve_first {

    template <class T> std::shared_ptr<T> vx_core::Class_resolve_first::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_resolve_first output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_resolve_first::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_resolve_first output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_resolve_first::vx_typedef() {return vx_core::t_resolve_first->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_resolve_first::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "resolve-first", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_resolve_first::vx_empty(std::shared_ptr<T> val) {return vx_core::e_resolve_first;}
    template <class T> std::shared_ptr<T> vx_core::Class_resolve_first::vx_type(std::shared_ptr<T> val) {return vx_core::t_resolve_first;}

    vx_core::Func_any_from_any vx_core::Class_resolve_first::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_resolve_first::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_list inputval = (vx_core::Type_list)value;
      vx_core::Type_any outputval = vx_core::f_resolve_first(vx_core::t_any, inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_resolve_first::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_list clauses = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_resolve_first(generic_any_1, clauses);
      return output;
    }

    template <class T, class X> std::shared_ptr<T> vx_core::Class_resolve_first::vx_resolve_first(std::shared_ptr<T> generic_any_1, std::shared_ptr<X> clauses) {
      return vx_core::f_resolve_first(generic_any_1, clauses);
    }

  //}

  vx_core::Func_resolve_first vx_core::e_resolve_first = std::make_shared<vx_core::Class_resolve_first>();
  vx_core::Func_resolve_first vx_core::t_resolve_first = std::make_shared<vx_core::Class_resolve_first>();

  template <class T, class X> std::shared_ptr<T> vx_core::f_resolve_first(std::shared_ptr<T> generic_any_1, std::shared_ptr<X> clauses) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    output = vx_core::f_first_from_list_fn_any_from_any(
      generic_any_1,
      clauses,
      vx_core::t_resolve
    );
    return output;
  }

  /**
   * @function resolve_list
   * @param  {list-1} clauses
   * @return {list-1}
   * (func resolve-list)
   */
  //class Func_resolve_list {

    template <class T> std::shared_ptr<T> vx_core::Class_resolve_list::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_resolve_list output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_resolve_list::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_resolve_list output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_resolve_list::vx_typedef() {return vx_core::t_resolve_list->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_resolve_list::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "resolve-list", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "list-1", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_any}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_core::Class_resolve_list::vx_empty(std::shared_ptr<T> val) {return vx_core::e_resolve_list;}
    template <class T> std::shared_ptr<T> vx_core::Class_resolve_list::vx_type(std::shared_ptr<T> val) {return vx_core::t_resolve_list;}

    vx_core::Func_any_from_any vx_core::Class_resolve_list::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_resolve_list::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_list inputval = (vx_core::Type_list)value;
      vx_core::Type_any outputval = vx_core::f_resolve_list(vx_core::t_list, inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_resolve_list::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_list generic_list_1 = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_list clauses = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_resolve_list(generic_list_1, clauses);
      return output;
    }

    template <class X> std::shared_ptr<X> vx_core::Class_resolve_list::vx_resolve_list(std::shared_ptr<X> generic_list_1, std::shared_ptr<X> clauses) {
      return vx_core::f_resolve_list(generic_list_1, clauses);
    }

  //}

  vx_core::Func_resolve_list vx_core::e_resolve_list = std::make_shared<vx_core::Class_resolve_list>();
  vx_core::Func_resolve_list vx_core::t_resolve_list = std::make_shared<vx_core::Class_resolve_list>();

  template <class X> std::shared_ptr<X> vx_core::f_resolve_list(std::shared_ptr<X> generic_list_1, std::shared_ptr<X> clauses) {
    std::shared_ptr<X> output = vx_core::f_empty(generic_list_1);
    output = vx_core::f_list_from_list(
      generic_list_1,
      clauses,
      vx_core::t_resolve
    );
    return output;
  }

  /**
   * @function session_from_context
   * Returns session from a context
   * @return {session}
   * (func session<-context)
   */
  //class Func_session_from_context {

    template <class T> std::shared_ptr<T> vx_core::Class_session_from_context::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_session_from_context output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_session_from_context::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_session_from_context output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_session_from_context::vx_typedef() {return vx_core::t_session_from_context->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_session_from_context::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "session<-context", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "session", // name
          ":struct", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_session_from_context::vx_empty(std::shared_ptr<T> val) {return vx_core::e_session_from_context;}
    template <class T> std::shared_ptr<T> vx_core::Class_session_from_context::vx_type(std::shared_ptr<T> val) {return vx_core::t_session_from_context;}

    vx_core::Type_any vx_core::Class_session_from_context::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_session_from_context(context);
      return output;
    }

    vx_core::Type_session vx_core::Class_session_from_context::vx_session_from_context(vx_core::Type_context context) {
      return vx_core::f_session_from_context(context);
    }

  //}

  vx_core::Func_session_from_context vx_core::e_session_from_context = std::make_shared<vx_core::Class_session_from_context>();
  vx_core::Func_session_from_context vx_core::t_session_from_context = std::make_shared<vx_core::Class_session_from_context>();

  vx_core::Type_session vx_core::f_session_from_context(vx_core::Type_context context) {
    vx_core::Type_session output = vx_core::e_session;
    output = vx_core::t_context->session();
    return output;
  }

  /**
   * @function setting_from_context
   * Returns setting from a context
   * @return {setting}
   * (func setting<-context)
   */
  //class Func_setting_from_context {

    template <class T> std::shared_ptr<T> vx_core::Class_setting_from_context::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_setting_from_context output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_setting_from_context::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_setting_from_context output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_setting_from_context::vx_typedef() {return vx_core::t_setting_from_context->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_setting_from_context::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "setting<-context", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "setting", // name
          ":struct", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_setting_from_context::vx_empty(std::shared_ptr<T> val) {return vx_core::e_setting_from_context;}
    template <class T> std::shared_ptr<T> vx_core::Class_setting_from_context::vx_type(std::shared_ptr<T> val) {return vx_core::t_setting_from_context;}

    vx_core::Type_any vx_core::Class_setting_from_context::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_setting_from_context(context);
      return output;
    }

    vx_core::Type_setting vx_core::Class_setting_from_context::vx_setting_from_context(vx_core::Type_context context) {
      return vx_core::f_setting_from_context(context);
    }

  //}

  vx_core::Func_setting_from_context vx_core::e_setting_from_context = std::make_shared<vx_core::Class_setting_from_context>();
  vx_core::Func_setting_from_context vx_core::t_setting_from_context = std::make_shared<vx_core::Class_setting_from_context>();

  vx_core::Type_setting vx_core::f_setting_from_context(vx_core::Type_context context) {
    vx_core::Type_setting output = vx_core::e_setting;
    output = vx_core::t_context->setting();
    return output;
  }

  /**
   * @function string_repeat
   * @param  {string} text
   * @param  {int} repeat
   * @return {string}
   * (func string-repeat)
   */
  //class Func_string_repeat {

    template <class T> std::shared_ptr<T> vx_core::Class_string_repeat::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_string_repeat output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_string_repeat::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_string_repeat output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_string_repeat::vx_typedef() {return vx_core::t_string_repeat->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_string_repeat::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "string-repeat", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_string_repeat::vx_empty(std::shared_ptr<T> val) {return vx_core::e_string_repeat;}
    template <class T> std::shared_ptr<T> vx_core::Class_string_repeat::vx_type(std::shared_ptr<T> val) {return vx_core::t_string_repeat;}

    vx_core::Type_any vx_core::Class_string_repeat::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int repeat = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_string_repeat(text, repeat);
      return output;
    }

    vx_core::Type_string vx_core::Class_string_repeat::vx_string_repeat(vx_core::Type_string text, vx_core::Type_int repeat) {
      return vx_core::f_string_repeat(text, repeat);
    }

  //}

  vx_core::Func_string_repeat vx_core::e_string_repeat = std::make_shared<vx_core::Class_string_repeat>();
  vx_core::Func_string_repeat vx_core::t_string_repeat = std::make_shared<vx_core::Class_string_repeat>();

  vx_core::Type_string vx_core::f_string_repeat(vx_core::Type_string text, vx_core::Type_int repeat) {
    vx_core::Type_string output = vx_core::e_string;
    return output;
  }

  /**
   * @function string_from_any
   * Return a string representation of a value
   * @param  {any} value
   * @return {string}
   * (func string<-any)
   */
  //class Func_string_from_any {

    template <class T> std::shared_ptr<T> vx_core::Class_string_from_any::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_string_from_any output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_string_from_any::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_string_from_any output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_string_from_any::vx_typedef() {return vx_core::t_string_from_any->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_string_from_any::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "string<-any", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_string_from_any::vx_empty(std::shared_ptr<T> val) {return vx_core::e_string_from_any;}
    template <class T> std::shared_ptr<T> vx_core::Class_string_from_any::vx_type(std::shared_ptr<T> val) {return vx_core::t_string_from_any;}

    vx_core::Func_any_from_any vx_core::Class_string_from_any::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_string_from_any::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_core::f_string_from_any(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_string_from_any::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any value = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_string_from_any(value);
      return output;
    }

    vx_core::Type_string vx_core::Class_string_from_any::vx_string_from_any(vx_core::Type_any value) {
      return vx_core::f_string_from_any(value);
    }

  //}

  vx_core::Func_string_from_any vx_core::e_string_from_any = std::make_shared<vx_core::Class_string_from_any>();
  vx_core::Func_string_from_any vx_core::t_string_from_any = std::make_shared<vx_core::Class_string_from_any>();

  vx_core::Type_string vx_core::f_string_from_any(vx_core::Type_any value) {
    vx_core::Type_string output = vx_core::e_string;
    output = vx_core::f_string_from_any_indent(
      value,
      vx_core::t_int->vx_new_from_int(0),
      vx_core::t_boolean->vx_new_from_boolean(true)
    );
    return output;
  }

  /**
   * @function string_from_any_indent
   * Return a string representation of a value
   * @param  {any} value
   * @param  {int} indent
   * @param  {boolean} linefeed
   * @return {string}
   * (func string<-any-indent)
   */
  //class Func_string_from_any_indent {

    template <class T> std::shared_ptr<T> vx_core::Class_string_from_any_indent::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_string_from_any_indent output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_string_from_any_indent::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_string_from_any_indent output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_string_from_any_indent::vx_typedef() {return vx_core::t_string_from_any_indent->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_string_from_any_indent::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "string<-any-indent", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_string_from_any_indent::vx_empty(std::shared_ptr<T> val) {return vx_core::e_string_from_any_indent;}
    template <class T> std::shared_ptr<T> vx_core::Class_string_from_any_indent::vx_type(std::shared_ptr<T> val) {return vx_core::t_string_from_any_indent;}

    vx_core::Type_any vx_core::Class_string_from_any_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any value = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      vx_core::Type_boolean linefeed = vx_core::f_any_from_any(vx_core::t_boolean, arglist->vx_any(vx_core::t_int->vx_new_from_int(2)));
      output = vx_core::f_string_from_any_indent(value, indent, linefeed);
      return output;
    }

    vx_core::Type_string vx_core::Class_string_from_any_indent::vx_string_from_any_indent(vx_core::Type_any value, vx_core::Type_int indent, vx_core::Type_boolean linefeed) {
      return vx_core::f_string_from_any_indent(value, indent, linefeed);
    }

  //}

  vx_core::Func_string_from_any_indent vx_core::e_string_from_any_indent = std::make_shared<vx_core::Class_string_from_any_indent>();
  vx_core::Func_string_from_any_indent vx_core::t_string_from_any_indent = std::make_shared<vx_core::Class_string_from_any_indent>();

  vx_core::Type_string vx_core::f_string_from_any_indent(vx_core::Type_any value, vx_core::Type_int indent, vx_core::Type_boolean linefeed) {
    vx_core::Type_string output = vx_core::e_string;
    return output;
  }

  /**
   * @function string_from_func
   * Function Type returning string with any parameters
   * @return {string}
   * (func string<-func)
   */
  //class Func_string_from_func {

    template <class T> std::shared_ptr<T> vx_core::Class_string_from_func::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_string_from_func output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_string_from_func::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_string_from_func output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_string_from_func::vx_typedef() {return vx_core::t_string_from_func->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_string_from_func::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "string<-func", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_string_from_func::vx_empty(std::shared_ptr<T> val) {return vx_core::e_string_from_func;}
    template <class T> std::shared_ptr<T> vx_core::Class_string_from_func::vx_type(std::shared_ptr<T> val) {return vx_core::t_string_from_func;}

    vx_core::Func_string_from_func vx_core::Class_string_from_func::fn_new(vx_core::Class_any_from_func::IFn fn) {
      vx_core::Func_string_from_func output;
      output->fn = fn;
      return output;
    }

    vx_core::Type_any vx_core::Class_string_from_func::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      output = vx_core::f_string_from_func();
      return output;
    }

    vx_core::Type_string vx_core::Class_string_from_func::vx_string_from_func() {
      vx_core::Type_string output = vx_core::e_string;
      if (fn != NULL) {
        output = vx_core::f_any_from_any(vx_core::t_string, fn());
      }
      return output;
    }

  //}

  vx_core::Func_string_from_func vx_core::e_string_from_func = std::make_shared<vx_core::Class_string_from_func>();
  vx_core::Func_string_from_func vx_core::t_string_from_func = std::make_shared<vx_core::Class_string_from_func>();

  vx_core::Type_string vx_core::f_string_from_func() {
    vx_core::Type_string output = vx_core::e_string;
    return output;
  }

  /**
   * @function switch
   * @param  {any-2} val
   * @param  {thenelselist} thenelselist
   * @return {any-1}
   * (func switch)
   */
  //class Func_switch {

    template <class T> std::shared_ptr<T> vx_core::Class_switch::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_switch output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_switch::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_switch output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_switch::vx_typedef() {return vx_core::t_switch->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_switch::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "switch", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any-1", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_switch::vx_empty(std::shared_ptr<T> val) {return vx_core::e_switch;}
    template <class T> std::shared_ptr<T> vx_core::Class_switch::vx_type(std::shared_ptr<T> val) {return vx_core::t_switch;}

    vx_core::Type_any vx_core::Class_switch::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any val = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_thenelselist thenelselist = vx_core::f_any_from_any(vx_core::t_thenelselist, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_switch(generic_any_1, val, thenelselist);
      return output;
    }

    template <class T, class U> std::shared_ptr<T> vx_core::Class_switch::vx_switch(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> val, vx_core::Type_thenelselist thenelselist) {
      return vx_core::f_switch(generic_any_1, val, thenelselist);
    }

  //}

  vx_core::Func_switch vx_core::e_switch = std::make_shared<vx_core::Class_switch>();
  vx_core::Func_switch vx_core::t_switch = std::make_shared<vx_core::Class_switch>();

  template <class T, class U> std::shared_ptr<T> vx_core::f_switch(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> val, vx_core::Type_thenelselist thenelselist) {
    std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
    return output;
  }

  /**
   * @function then
   * @param  {boolean<-func} fn-cond
   * @param  {any<-func} fn-any
   * @return {thenelse}
   * (func then)
   */
  //class Func_then {

    template <class T> std::shared_ptr<T> vx_core::Class_then::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_then output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_then::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_then output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_then::vx_typedef() {return vx_core::t_then->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_then::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "then", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "thenelse", // name
          ":struct", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_then::vx_empty(std::shared_ptr<T> val) {return vx_core::e_then;}
    template <class T> std::shared_ptr<T> vx_core::Class_then::vx_type(std::shared_ptr<T> val) {return vx_core::t_then;}

    vx_core::Type_any vx_core::Class_then::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Func_boolean_from_func fn_cond = vx_core::f_any_from_any(vx_core::t_boolean_from_func, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Func_any_from_func fn_any = vx_core::f_any_from_any(vx_core::t_any_from_func, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_core::f_then(fn_cond, fn_any);
      return output;
    }

    vx_core::Type_thenelse vx_core::Class_then::vx_then(vx_core::Func_boolean_from_func fn_cond, vx_core::Func_any_from_func fn_any) {
      return vx_core::f_then(fn_cond, fn_any);
    }

  //}

  vx_core::Func_then vx_core::e_then = std::make_shared<vx_core::Class_then>();
  vx_core::Func_then vx_core::t_then = std::make_shared<vx_core::Class_then>();

  vx_core::Type_thenelse vx_core::f_then(vx_core::Func_boolean_from_func fn_cond, vx_core::Func_any_from_func fn_any) {
    vx_core::Type_thenelse output = vx_core::e_thenelse;
    output = vx_core::f_new(
      vx_core::t_thenelse,
      vx_core::t_anylist->vx_new(vx_core::t_anylist, {
        vx_core::t_string->vx_new_from_string(":code"),
        vx_core::t_string->vx_new_from_string(":then"),
        vx_core::t_string->vx_new_from_string(":fn-cond"),
        fn_cond,
        vx_core::t_string->vx_new_from_string(":fn-any"),
        fn_any
      })
    );
    return output;
  }

  /**
   * @function traits_from_typedef
   * Return trait list from type
   * @param  {typedef} vtypedef
   * @return {typelist}
   * (func traits<-typedef)
   */
  //class Func_traits_from_typedef {

    template <class T> std::shared_ptr<T> vx_core::Class_traits_from_typedef::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_traits_from_typedef output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_traits_from_typedef::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_traits_from_typedef output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_traits_from_typedef::vx_typedef() {return vx_core::t_traits_from_typedef->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_traits_from_typedef::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "traits<-typedef", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "typelist", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_any}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_core::Class_traits_from_typedef::vx_empty(std::shared_ptr<T> val) {return vx_core::e_traits_from_typedef;}
    template <class T> std::shared_ptr<T> vx_core::Class_traits_from_typedef::vx_type(std::shared_ptr<T> val) {return vx_core::t_traits_from_typedef;}

    vx_core::Func_any_from_any vx_core::Class_traits_from_typedef::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_traits_from_typedef::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_typedef inputval = (vx_core::Type_typedef)value;
      vx_core::Type_any outputval = vx_core::f_traits_from_typedef(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_traits_from_typedef::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_typedef vtypedef = vx_core::f_any_from_any(vx_core::t_typedef, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_traits_from_typedef(vtypedef);
      return output;
    }

    vx_core::Type_typelist vx_core::Class_traits_from_typedef::vx_traits_from_typedef(vx_core::Type_typedef vtypedef) {
      return vx_core::f_traits_from_typedef(vtypedef);
    }

  //}

  vx_core::Func_traits_from_typedef vx_core::e_traits_from_typedef = std::make_shared<vx_core::Class_traits_from_typedef>();
  vx_core::Func_traits_from_typedef vx_core::t_traits_from_typedef = std::make_shared<vx_core::Class_traits_from_typedef>();

  vx_core::Type_typelist vx_core::f_traits_from_typedef(vx_core::Type_typedef vtypedef) {
    vx_core::Type_typelist output = vx_core::e_typelist;
    return output;
  }

  /**
   * @function type_from_any
   * Gets the Type of a given Value
   * @param  {any-1} value
   * @return {any}
   * (func type<-any)
   */
  //class Func_type_from_any {

    template <class T> std::shared_ptr<T> vx_core::Class_type_from_any::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_type_from_any output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_type_from_any::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_type_from_any output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_type_from_any::vx_typedef() {return vx_core::t_type_from_any->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_type_from_any::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "type<-any", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any", // name
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

    template <class T> std::shared_ptr<T> vx_core::Class_type_from_any::vx_empty(std::shared_ptr<T> val) {return vx_core::e_type_from_any;}
    template <class T> std::shared_ptr<T> vx_core::Class_type_from_any::vx_type(std::shared_ptr<T> val) {return vx_core::t_type_from_any;}

    vx_core::Func_any_from_any vx_core::Class_type_from_any::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_type_from_any::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_core::f_type_from_any(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_type_from_any::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any value = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_type_from_any(value);
      return output;
    }

    vx_core::Type_any vx_core::Class_type_from_any::vx_type_from_any(vx_core::Type_any value) {
      return vx_core::f_type_from_any(value);
    }

  //}

  vx_core::Func_type_from_any vx_core::e_type_from_any = std::make_shared<vx_core::Class_type_from_any>();
  vx_core::Func_type_from_any vx_core::t_type_from_any = std::make_shared<vx_core::Class_type_from_any>();

  vx_core::Type_any vx_core::f_type_from_any(vx_core::Type_any value) {
    vx_core::Type_any output = vx_core::e_any;
    return output;
  }

  /**
   * @function typedef_from_any
   * @param  {any} val
   * @return {typedef}
   * (func typedef<-any)
   */
  //class Func_typedef_from_any {

    template <class T> std::shared_ptr<T> vx_core::Class_typedef_from_any::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_typedef_from_any output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_typedef_from_any::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_typedef_from_any output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_typedef_from_any::vx_typedef() {return vx_core::t_typedef_from_any->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_typedef_from_any::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "typedef<-any", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "typedef", // name
          ":struct", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_typedef_from_any::vx_empty(std::shared_ptr<T> val) {return vx_core::e_typedef_from_any;}
    template <class T> std::shared_ptr<T> vx_core::Class_typedef_from_any::vx_type(std::shared_ptr<T> val) {return vx_core::t_typedef_from_any;}

    vx_core::Func_any_from_any vx_core::Class_typedef_from_any::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_typedef_from_any::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_core::f_typedef_from_any(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_typedef_from_any::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any val = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_typedef_from_any(val);
      return output;
    }

    vx_core::Type_typedef vx_core::Class_typedef_from_any::vx_typedef_from_any(vx_core::Type_any val) {
      return vx_core::f_typedef_from_any(val);
    }

  //}

  vx_core::Func_typedef_from_any vx_core::e_typedef_from_any = std::make_shared<vx_core::Class_typedef_from_any>();
  vx_core::Func_typedef_from_any vx_core::t_typedef_from_any = std::make_shared<vx_core::Class_typedef_from_any>();

  vx_core::Type_typedef vx_core::f_typedef_from_any(vx_core::Type_any val) {
    vx_core::Type_typedef output = vx_core::e_typedef;
    output = vx_core::f_typedef_from_type(
      vx_core::f_type_from_any(val)
    );
    return output;
  }

  /**
   * @function typedef_from_type
   * @param  {any} val
   * @return {typedef}
   * (func typedef<-type)
   */
  //class Func_typedef_from_type {

    template <class T> std::shared_ptr<T> vx_core::Class_typedef_from_type::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_typedef_from_type output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_typedef_from_type::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_typedef_from_type output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_typedef_from_type::vx_typedef() {return vx_core::t_typedef_from_type->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_typedef_from_type::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "typedef<-type", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "typedef", // name
          ":struct", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_typedef_from_type::vx_empty(std::shared_ptr<T> val) {return vx_core::e_typedef_from_type;}
    template <class T> std::shared_ptr<T> vx_core::Class_typedef_from_type::vx_type(std::shared_ptr<T> val) {return vx_core::t_typedef_from_type;}

    vx_core::Func_any_from_any vx_core::Class_typedef_from_type::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_typedef_from_type::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_core::f_typedef_from_type(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_typedef_from_type::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any val = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_typedef_from_type(val);
      return output;
    }

    vx_core::Type_typedef vx_core::Class_typedef_from_type::vx_typedef_from_type(vx_core::Type_any val) {
      return vx_core::f_typedef_from_type(val);
    }

  //}

  vx_core::Func_typedef_from_type vx_core::e_typedef_from_type = std::make_shared<vx_core::Class_typedef_from_type>();
  vx_core::Func_typedef_from_type vx_core::t_typedef_from_type = std::make_shared<vx_core::Class_typedef_from_type>();

  vx_core::Type_typedef vx_core::f_typedef_from_type(vx_core::Type_any val) {
    vx_core::Type_typedef output = vx_core::e_typedef;
    return output;
  }

  /**
   * @function typename_from_any
   * Gets the type of a given value
   * @param  {any-2} value
   * @return {string}
   * (func typename<-any)
   */
  //class Func_typename_from_any {

    template <class T> std::shared_ptr<T> vx_core::Class_typename_from_any::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_typename_from_any output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_typename_from_any::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_typename_from_any output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_typename_from_any::vx_typedef() {return vx_core::t_typename_from_any->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_typename_from_any::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "typename<-any", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_typename_from_any::vx_empty(std::shared_ptr<T> val) {return vx_core::e_typename_from_any;}
    template <class T> std::shared_ptr<T> vx_core::Class_typename_from_any::vx_type(std::shared_ptr<T> val) {return vx_core::t_typename_from_any;}

    vx_core::Func_any_from_any vx_core::Class_typename_from_any::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_typename_from_any::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_core::f_typename_from_any(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_typename_from_any::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any value = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_typename_from_any(value);
      return output;
    }

    vx_core::Type_string vx_core::Class_typename_from_any::vx_typename_from_any(vx_core::Type_any value) {
      return vx_core::f_typename_from_any(value);
    }

  //}

  vx_core::Func_typename_from_any vx_core::e_typename_from_any = std::make_shared<vx_core::Class_typename_from_any>();
  vx_core::Func_typename_from_any vx_core::t_typename_from_any = std::make_shared<vx_core::Class_typename_from_any>();

  vx_core::Type_string vx_core::f_typename_from_any(vx_core::Type_any value) {
    vx_core::Type_string output = vx_core::e_string;
    output = vx_core::f_typename_from_type(
      vx_core::f_type_from_any(value)
    );
    return output;
  }

  /**
   * @function typename_from_type
   * Get the name of a given type
   * @param  {any} type
   * @return {string}
   * (func typename<-type)
   */
  //class Func_typename_from_type {

    template <class T> std::shared_ptr<T> vx_core::Class_typename_from_type::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_typename_from_type output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_typename_from_type::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_typename_from_type output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_typename_from_type::vx_typedef() {return vx_core::t_typename_from_type->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_typename_from_type::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "typename<-type", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_typename_from_type::vx_empty(std::shared_ptr<T> val) {return vx_core::e_typename_from_type;}
    template <class T> std::shared_ptr<T> vx_core::Class_typename_from_type::vx_type(std::shared_ptr<T> val) {return vx_core::t_typename_from_type;}

    vx_core::Func_any_from_any vx_core::Class_typename_from_type::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_typename_from_type::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_any inputval = (vx_core::Type_any)value;
      vx_core::Type_any outputval = vx_core::f_typename_from_type(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_typename_from_type::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any type = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_typename_from_type(type);
      return output;
    }

    vx_core::Type_string vx_core::Class_typename_from_type::vx_typename_from_type(vx_core::Type_any type) {
      return vx_core::f_typename_from_type(type);
    }

  //}

  vx_core::Func_typename_from_type vx_core::e_typename_from_type = std::make_shared<vx_core::Class_typename_from_type>();
  vx_core::Func_typename_from_type vx_core::t_typename_from_type = std::make_shared<vx_core::Class_typename_from_type>();

  vx_core::Type_string vx_core::f_typename_from_type(vx_core::Type_any type) {
    vx_core::Type_string output = vx_core::e_string;
    output = vx_core::f_typename_from_typedef(
      vx_core::f_typedef_from_type(type)
    );
    return output;
  }

  /**
   * @function typename_from_typedef
   * Get the name of a given type
   * @param  {typedef} vtypedef
   * @return {string}
   * (func typename<-typedef)
   */
  //class Func_typename_from_typedef {

    template <class T> std::shared_ptr<T> vx_core::Class_typename_from_typedef::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_typename_from_typedef output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_typename_from_typedef::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_typename_from_typedef output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_typename_from_typedef::vx_typedef() {return vx_core::t_typename_from_typedef->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_typename_from_typedef::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "typename<-typedef", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_typename_from_typedef::vx_empty(std::shared_ptr<T> val) {return vx_core::e_typename_from_typedef;}
    template <class T> std::shared_ptr<T> vx_core::Class_typename_from_typedef::vx_type(std::shared_ptr<T> val) {return vx_core::t_typename_from_typedef;}

    vx_core::Func_any_from_any vx_core::Class_typename_from_typedef::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_typename_from_typedef::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_typedef inputval = (vx_core::Type_typedef)value;
      vx_core::Type_any outputval = vx_core::f_typename_from_typedef(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_typename_from_typedef::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_typedef vtypedef = vx_core::f_any_from_any(vx_core::t_typedef, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_typename_from_typedef(vtypedef);
      return output;
    }

    vx_core::Type_string vx_core::Class_typename_from_typedef::vx_typename_from_typedef(vx_core::Type_typedef vtypedef) {
      return vx_core::f_typename_from_typedef(vtypedef);
    }

  //}

  vx_core::Func_typename_from_typedef vx_core::e_typename_from_typedef = std::make_shared<vx_core::Class_typename_from_typedef>();
  vx_core::Func_typename_from_typedef vx_core::t_typename_from_typedef = std::make_shared<vx_core::Class_typename_from_typedef>();

  vx_core::Type_string vx_core::f_typename_from_typedef(vx_core::Type_typedef vtypedef) {
    vx_core::Type_string output = vx_core::e_string;
    output = vx_core::f_new(
      vx_core::t_string,
      vx_core::t_anylist->vx_new(vx_core::t_anylist, {
        vtypedef->pkgname(),
        vx_core::t_string->vx_new_from_string("/"),
        vtypedef->name()
      })
    );
    return output;
  }

  /**
   * @function typenames_from_typelist
   * Get the names from a type list
   * @param  {typelist} typelist
   * @return {stringlist}
   * (func typenames<-typelist)
   */
  //class Func_typenames_from_typelist {

    template <class T> std::shared_ptr<T> vx_core::Class_typenames_from_typelist::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_typenames_from_typelist output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_typenames_from_typelist::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_typenames_from_typelist output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_typenames_from_typelist::vx_typedef() {return vx_core::t_typenames_from_typelist->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_typenames_from_typelist::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "typenames<-typelist", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "stringlist", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_string}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_core::Class_typenames_from_typelist::vx_empty(std::shared_ptr<T> val) {return vx_core::e_typenames_from_typelist;}
    template <class T> std::shared_ptr<T> vx_core::Class_typenames_from_typelist::vx_type(std::shared_ptr<T> val) {return vx_core::t_typenames_from_typelist;}

    vx_core::Func_any_from_any vx_core::Class_typenames_from_typelist::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_core::Class_typenames_from_typelist::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_typelist inputval = (vx_core::Type_typelist)value;
      vx_core::Type_any outputval = vx_core::f_typenames_from_typelist(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_core::Class_typenames_from_typelist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_typelist typelist = vx_core::f_any_from_any(vx_core::t_typelist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_typenames_from_typelist(typelist);
      return output;
    }

    vx_core::Type_stringlist vx_core::Class_typenames_from_typelist::vx_typenames_from_typelist(vx_core::Type_typelist typelist) {
      return vx_core::f_typenames_from_typelist(typelist);
    }

  //}

  vx_core::Func_typenames_from_typelist vx_core::e_typenames_from_typelist = std::make_shared<vx_core::Class_typenames_from_typelist>();
  vx_core::Func_typenames_from_typelist vx_core::t_typenames_from_typelist = std::make_shared<vx_core::Class_typenames_from_typelist>();

  vx_core::Type_stringlist vx_core::f_typenames_from_typelist(vx_core::Type_typelist typelist) {
    vx_core::Type_stringlist output = vx_core::e_stringlist;
    output = vx_core::f_list_from_list(
      vx_core::t_stringlist,
      typelist,
      vx_core::t_any_from_any->fn_new([](vx_core::Type_any type_any) {
        vx_core::Type_any type = vx_core::f_any_from_any(vx_core::t_any, type_any);
        return 
          vx_core::f_typename_from_type(type);
      })
    );
    return output;
  }

  /**
   * @function user_from_context
   * Returns the current user from context.
   * @return {user}
   * (func user<-context)
   */
  //class Func_user_from_context {

    template <class T> std::shared_ptr<T> vx_core::Class_user_from_context::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_user_from_context output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_core::Class_user_from_context::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_core::Func_user_from_context output;
      return output;
    }

    vx_core::Type_typedef vx_core::Class_user_from_context::vx_typedef() {return vx_core::t_user_from_context->vx_typedef();}

    vx_core::Type_funcdef vx_core::Class_user_from_context::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "user<-context", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "user", // name
          ":struct", // extends
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

    template <class T> std::shared_ptr<T> vx_core::Class_user_from_context::vx_empty(std::shared_ptr<T> val) {return vx_core::e_user_from_context;}
    template <class T> std::shared_ptr<T> vx_core::Class_user_from_context::vx_type(std::shared_ptr<T> val) {return vx_core::t_user_from_context;}

    vx_core::Type_any vx_core::Class_user_from_context::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_core::f_user_from_context(context);
      return output;
    }

    vx_core::Type_user vx_core::Class_user_from_context::vx_user_from_context(vx_core::Type_context context) {
      return vx_core::f_user_from_context(context);
    }

  //}

  vx_core::Func_user_from_context vx_core::e_user_from_context = std::make_shared<vx_core::Class_user_from_context>();
  vx_core::Func_user_from_context vx_core::t_user_from_context = std::make_shared<vx_core::Class_user_from_context>();

  vx_core::Type_user vx_core::f_user_from_context(vx_core::Type_context context) {
    vx_core::Type_user output = vx_core::e_user;
    output = vx_core::f_session_from_context(context)->user();
    return output;
  }


//}
