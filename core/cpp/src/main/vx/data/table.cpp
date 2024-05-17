#include <map>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "table.hpp"

namespace vx_data_table {



  // (type cell)
  // class Class_cell {
    Abstract_cell::~Abstract_cell() {}

    Class_cell::Class_cell() : Abstract_cell::Abstract_cell() {
      vx_core::refcount += 1;
    }

    Class_cell::~Class_cell() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_value
      });
    }

    // id()
    vx_core::Type_string Class_cell::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // value()
    vx_core::Type_any Class_cell::value() const {
      vx_core::Type_any output = this->vx_p_value;
      if (!output) {
        output = vx_core::e_any;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_cell::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":value") {
        output = this->value();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_cell::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":value"] = this->value();
      return output;
    }

    vx_core::Type_any Class_cell::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_table::e_cell, vals);
    }

    vx_core::Type_any Class_cell::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_table::Type_cell output = vx_data_table::e_cell;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_table::Type_cell val = vx_core::vx_any_from_any(vx_data_table::t_cell, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_core::Type_any vx_p_value = val->value();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":value") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new cell) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (vx_p_id == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new cell :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":value") {
            if (vx_p_value != valsub) {
              ischanged = true;
              vx_p_value = valsub;
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new cell) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_table::Class_cell();
        if (output->vx_p_id != vx_p_id) {
          if (output->vx_p_id) {
            vx_core::vx_release_one(output->vx_p_id);
          }
          output->vx_p_id = vx_p_id;
          vx_core::vx_reserve(vx_p_id);
        }
        if (output->vx_p_value != vx_p_value) {
          if (output->vx_p_value) {
            vx_core::vx_release_one(output->vx_p_value);
          }
          output->vx_p_value = vx_p_value;
          vx_core::vx_reserve(vx_p_value);
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

    vx_core::Type_msgblock Class_cell::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_table::Class_cell::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_cell::vx_empty() const {return vx_data_table::e_cell;}
    vx_core::Type_any Class_cell::vx_type() const {return vx_data_table::t_cell;}

    vx_core::Type_typedef Class_cell::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/table", // pkgname
        "cell", // name
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
            "id", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "value", // name
            vx_core::t_any // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_cell::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type celllist)
  // class Class_celllist {
    Abstract_celllist::~Abstract_celllist() {}

    Class_celllist::Class_celllist() : Abstract_celllist::Abstract_celllist() {
      vx_core::refcount += 1;
    }

    Class_celllist::~Class_celllist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_celllist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_data_table::Type_cell Class_celllist::vx_get_cell(vx_core::Type_int index) const {
      vx_data_table::Type_cell output = vx_data_table::e_cell;
      long iindex = index->vx_int();
      std::vector<vx_data_table::Type_cell> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_data_table::Type_cell> Class_celllist::vx_listcell() const {return vx_p_list;}

    vx_core::Type_any vx_data_table::Class_celllist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_cell(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_celllist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_data_table::Type_celllist output = vx_data_table::e_celllist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_data_table::Type_cell> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_data_table::t_cell) {
          vx_data_table::Type_cell castval = vx_core::vx_any_from_any(vx_data_table::t_cell, valsub);
          list.push_back(castval);
        } else if (vx_core::vx_boolean_from_type_trait(valtype, vx_data_table::t_cell)) {
          vx_data_table::Type_cell castval = vx_core::vx_any_from_any(vx_data_table::t_cell, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(celllist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((list.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_table::Class_celllist();
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

    vx_core::Type_any Class_celllist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_table::e_celllist, vals);
    }

    vx_core::Type_any Class_celllist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_table::Type_celllist output = vx_data_table::e_celllist;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_table::Type_celllist val = vx_core::vx_any_from_any(vx_data_table::t_celllist, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_data_table::Type_cell> listval = val->vx_listcell();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_data_table::t_cell) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_data_table::t_cell, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_data_table::t_cell)) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_data_table::t_cell, valsub));
        } else if (valsubtype == vx_data_table::t_celllist) {
          ischanged = true;
          vx_data_table::Type_celllist multi = vx_core::vx_any_from_any(vx_data_table::t_celllist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listcell());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new celllist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if (ischanged || (listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_table::Class_celllist();
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

    vx_core::Type_msgblock Class_celllist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_table::Class_celllist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_celllist::vx_empty() const {return vx_data_table::e_celllist;}
    vx_core::Type_any Class_celllist::vx_type() const {return vx_data_table::t_celllist;}

    vx_core::Type_typedef Class_celllist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/table", // pkgname
        "celllist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_data_table::t_cell}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_celllist::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type cellmap)
  // class Class_cellmap {
    Abstract_cellmap::~Abstract_cellmap() {}

    Class_cellmap::Class_cellmap() : Abstract_cellmap::Abstract_cellmap() {
      vx_core::refcount += 1;
    }

    Class_cellmap::~Class_cellmap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (auto const& [key, val] : this->vx_p_map) {
        vx_core::vx_release_one(val);
      }
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_cellmap::vx_map() const {
      vx_core::vx_Type_mapany output = vx_core::vx_map_from_map(vx_core::t_any, this->vx_p_map);
      return output;
    }

    // vx_set(map, string, any)
    vx_core::Type_boolean Class_cellmap::vx_set(vx_core::Type_string name, vx_core::Type_any value) {
      vx_core::Type_boolean output = vx_core::c_false;
      vx_core::Type_any valtype = value->vx_type();
      if (valtype == vx_data_table::t_cell) {
        vx_data_table::Type_cell newval = vx_core::vx_any_from_any(vx_data_table::t_cell, value);
        std::string key = name->vx_string();
        if (vx_core::vx_boolean_from_string_starts(key, ":")) {
          key = key.substr(1, key.length());
        }
        vx_data_table::Type_cell oldval = this->vx_p_map[key];
        if (oldval != newval) {
          if (oldval) {
            vx_core::vx_release_one(oldval);
          }
          if (newval == vx_data_table::e_cell) {
            this->vx_p_map.erase(key);
          } else {
            vx_core::vx_reserve(newval);
            this->vx_p_map[key] = newval;
          }
        }
        output = vx_core::c_true;
      }
      return output;
    }
    // vx_get_cell(key)
    vx_data_table::Type_cell Class_cellmap::vx_get_cell(vx_core::Type_string key) const {
      vx_data_table::Type_cell output = vx_data_table::e_cell;
      const vx_data_table::Class_cellmap* map = this;
      std::string skey = key->vx_string();
      if (vx_core::vx_boolean_from_string_starts(skey, ":")) {
        skey = vx_core::vx_string_from_string_start(skey, 2);
      }
      std::map<std::string, vx_data_table::Type_cell> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_data_table::e_cell);
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_cellmap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_cell(key);
    }

    // vx_mapcell()
    std::map<std::string, vx_data_table::Type_cell> Class_cellmap::vx_mapcell() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_cellmap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_data_table::Type_cellmap output = vx_data_table::e_cellmap;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_data_table::Type_cell> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_data_table::t_cell) {
          vx_data_table::Type_cell castval = vx_core::vx_any_from_any(vx_data_table::t_cell, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(cellmap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((map.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_table::Class_cellmap();
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

    vx_core::Type_any Class_cellmap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_table::e_cellmap, vals);
    }

    vx_core::Type_any Class_cellmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_table::Type_cellmap output = vx_data_table::e_cellmap;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_table::Type_cellmap valmap = vx_core::vx_any_from_any(vx_data_table::t_cellmap, copyval);
      output = valmap;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_data_table::Type_cell> mapval = valmap->vx_mapcell();
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
          vx_data_table::Type_cell valany = NULL;
          if (valsubtype == vx_data_table::t_cell) {
            valany = vx_core::vx_any_from_any(vx_data_table::t_cell, valsub);
          } else if (valsubtype == vx_data_table::t_cell) {
            valany = vx_core::vx_any_from_any(vx_data_table::t_cell, valsub);
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("Invalid Key/Value: " + skey + " "  + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
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
        output = new vx_data_table::Class_cellmap();
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

    vx_core::Type_msgblock Class_cellmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_table::Class_cellmap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_cellmap::vx_empty() const {return vx_data_table::e_cellmap;}
    vx_core::Type_any Class_cellmap::vx_type() const {return vx_data_table::t_cellmap;}

    vx_core::Type_typedef Class_cellmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/table", // pkgname
        "cellmap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_data_table::t_cell}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_cellmap::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type field)
  // class Class_field {
    Abstract_field::~Abstract_field() {}

    Class_field::Class_field() : Abstract_field::Abstract_field() {
      vx_core::refcount += 1;
    }

    Class_field::~Class_field() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_name,
        this->vx_p_fldtype
      });
    }

    // id()
    vx_core::Type_string Class_field::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // name()
    vx_core::Type_string Class_field::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // fldtype()
    vx_core::Type_any Class_field::fldtype() const {
      vx_core::Type_any output = this->vx_p_fldtype;
      if (!output) {
        output = vx_core::e_any;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_field::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":fldtype") {
        output = this->fldtype();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_field::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":name"] = this->name();
      output[":fldtype"] = this->fldtype();
      return output;
    }

    vx_core::Type_any Class_field::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_table::e_field, vals);
    }

    vx_core::Type_any Class_field::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_table::Type_field output = vx_data_table::e_field;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_table::Type_field val = vx_core::vx_any_from_any(vx_data_table::t_field, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_core::Type_string vx_p_name = val->name();
      vx_core::Type_any vx_p_fldtype = val->fldtype();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":name") {
            key = testkey;
          } else if (testkey == ":fldtype") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new field) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (vx_p_id == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new field :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":name") {
            if (vx_p_name == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_name = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new field :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":fldtype") {
            if (vx_p_fldtype != valsub) {
              ischanged = true;
              vx_p_fldtype = valsub;
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new field) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_table::Class_field();
        if (output->vx_p_id != vx_p_id) {
          if (output->vx_p_id) {
            vx_core::vx_release_one(output->vx_p_id);
          }
          output->vx_p_id = vx_p_id;
          vx_core::vx_reserve(vx_p_id);
        }
        if (output->vx_p_name != vx_p_name) {
          if (output->vx_p_name) {
            vx_core::vx_release_one(output->vx_p_name);
          }
          output->vx_p_name = vx_p_name;
          vx_core::vx_reserve(vx_p_name);
        }
        if (output->vx_p_fldtype != vx_p_fldtype) {
          if (output->vx_p_fldtype) {
            vx_core::vx_release_one(output->vx_p_fldtype);
          }
          output->vx_p_fldtype = vx_p_fldtype;
          vx_core::vx_reserve(vx_p_fldtype);
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

    vx_core::Type_msgblock Class_field::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_table::Class_field::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_field::vx_empty() const {return vx_data_table::e_field;}
    vx_core::Type_any Class_field::vx_type() const {return vx_data_table::t_field;}

    vx_core::Type_typedef Class_field::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/table", // pkgname
        "field", // name
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
            "id", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "name", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "fldtype", // name
            vx_core::t_any // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_field::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type fieldlist)
  // class Class_fieldlist {
    Abstract_fieldlist::~Abstract_fieldlist() {}

    Class_fieldlist::Class_fieldlist() : Abstract_fieldlist::Abstract_fieldlist() {
      vx_core::refcount += 1;
    }

    Class_fieldlist::~Class_fieldlist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_fieldlist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_data_table::Type_field Class_fieldlist::vx_get_field(vx_core::Type_int index) const {
      vx_data_table::Type_field output = vx_data_table::e_field;
      long iindex = index->vx_int();
      std::vector<vx_data_table::Type_field> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_data_table::Type_field> Class_fieldlist::vx_listfield() const {return vx_p_list;}

    vx_core::Type_any vx_data_table::Class_fieldlist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_field(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_fieldlist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_data_table::Type_fieldlist output = vx_data_table::e_fieldlist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_data_table::Type_field> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_data_table::t_field) {
          vx_data_table::Type_field castval = vx_core::vx_any_from_any(vx_data_table::t_field, valsub);
          list.push_back(castval);
        } else if (vx_core::vx_boolean_from_type_trait(valtype, vx_data_table::t_field)) {
          vx_data_table::Type_field castval = vx_core::vx_any_from_any(vx_data_table::t_field, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(fieldlist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((list.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_table::Class_fieldlist();
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

    vx_core::Type_any Class_fieldlist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_table::e_fieldlist, vals);
    }

    vx_core::Type_any Class_fieldlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_table::Type_fieldlist output = vx_data_table::e_fieldlist;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_table::Type_fieldlist val = vx_core::vx_any_from_any(vx_data_table::t_fieldlist, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_data_table::Type_field> listval = val->vx_listfield();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_data_table::t_field) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_data_table::t_field, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_data_table::t_field)) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_data_table::t_field, valsub));
        } else if (valsubtype == vx_data_table::t_fieldlist) {
          ischanged = true;
          vx_data_table::Type_fieldlist multi = vx_core::vx_any_from_any(vx_data_table::t_fieldlist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listfield());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new fieldlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if (ischanged || (listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_table::Class_fieldlist();
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

    vx_core::Type_msgblock Class_fieldlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_table::Class_fieldlist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_fieldlist::vx_empty() const {return vx_data_table::e_fieldlist;}
    vx_core::Type_any Class_fieldlist::vx_type() const {return vx_data_table::t_fieldlist;}

    vx_core::Type_typedef Class_fieldlist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/table", // pkgname
        "fieldlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_data_table::t_field}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_fieldlist::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type fieldmap)
  // class Class_fieldmap {
    Abstract_fieldmap::~Abstract_fieldmap() {}

    Class_fieldmap::Class_fieldmap() : Abstract_fieldmap::Abstract_fieldmap() {
      vx_core::refcount += 1;
    }

    Class_fieldmap::~Class_fieldmap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_fieldmap::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_data_table::Type_field Class_fieldmap::vx_get_field(vx_core::Type_int index) const {
      vx_data_table::Type_field output = vx_data_table::e_field;
      long iindex = index->vx_int();
      std::vector<vx_data_table::Type_field> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_data_table::Type_field> Class_fieldmap::vx_listfield() const {return vx_p_list;}

    vx_core::Type_any vx_data_table::Class_fieldmap::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_field(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_fieldmap::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_data_table::Type_fieldmap output = vx_data_table::e_fieldmap;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_data_table::Type_field> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_data_table::t_field) {
          vx_data_table::Type_field castval = vx_core::vx_any_from_any(vx_data_table::t_field, valsub);
          list.push_back(castval);
        } else if (vx_core::vx_boolean_from_type_trait(valtype, vx_data_table::t_field)) {
          vx_data_table::Type_field castval = vx_core::vx_any_from_any(vx_data_table::t_field, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(fieldmap) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((list.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_table::Class_fieldmap();
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

    vx_core::Type_any Class_fieldmap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_table::e_fieldmap, vals);
    }

    vx_core::Type_any Class_fieldmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_table::Type_fieldmap output = vx_data_table::e_fieldmap;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_table::Type_fieldmap val = vx_core::vx_any_from_any(vx_data_table::t_fieldmap, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_data_table::Type_field> listval = val->vx_listfield();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_data_table::t_field) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_data_table::t_field, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_data_table::t_field)) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_data_table::t_field, valsub));
        } else if (valsubtype == vx_data_table::t_fieldmap) {
          ischanged = true;
          vx_data_table::Type_fieldmap multi = vx_core::vx_any_from_any(vx_data_table::t_fieldmap, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listfield());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new fieldmap) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if (ischanged || (listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_table::Class_fieldmap();
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

    vx_core::Type_msgblock Class_fieldmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_table::Class_fieldmap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_fieldmap::vx_empty() const {return vx_data_table::e_fieldmap;}
    vx_core::Type_any Class_fieldmap::vx_type() const {return vx_data_table::t_fieldmap;}

    vx_core::Type_typedef Class_fieldmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/table", // pkgname
        "fieldmap", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_data_table::t_field}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_fieldmap::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type filter)
  // class Class_filter {
    Abstract_filter::~Abstract_filter() {}

    Class_filter::Class_filter() : Abstract_filter::Abstract_filter() {
      vx_core::refcount += 1;
    }

    Class_filter::~Class_filter() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_name,
        this->vx_p_idlist
      });
    }

    // id()
    vx_core::Type_string Class_filter::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // name()
    vx_core::Type_string Class_filter::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // idlist()
    vx_core::Type_stringlist Class_filter::idlist() const {
      vx_core::Type_stringlist output = this->vx_p_idlist;
      if (!output) {
        output = vx_core::e_stringlist;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_filter::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":idlist") {
        output = this->idlist();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_filter::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":name"] = this->name();
      output[":idlist"] = this->idlist();
      return output;
    }

    vx_core::Type_any Class_filter::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_table::e_filter, vals);
    }

    vx_core::Type_any Class_filter::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_table::Type_filter output = vx_data_table::e_filter;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_table::Type_filter val = vx_core::vx_any_from_any(vx_data_table::t_filter, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_core::Type_string vx_p_name = val->name();
      vx_core::Type_stringlist vx_p_idlist = val->idlist();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":name") {
            key = testkey;
          } else if (testkey == ":idlist") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new filter) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (vx_p_id == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new filter :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":name") {
            if (vx_p_name == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_name = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new filter :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":idlist") {
            if (vx_p_idlist == valsub) {
            } else if (valsubtype == vx_core::t_stringlist) {
              ischanged = true;
              vx_p_idlist = vx_core::vx_any_from_any(vx_core::t_stringlist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new filter :idlist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new filter) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_table::Class_filter();
        if (output->vx_p_id != vx_p_id) {
          if (output->vx_p_id) {
            vx_core::vx_release_one(output->vx_p_id);
          }
          output->vx_p_id = vx_p_id;
          vx_core::vx_reserve(vx_p_id);
        }
        if (output->vx_p_name != vx_p_name) {
          if (output->vx_p_name) {
            vx_core::vx_release_one(output->vx_p_name);
          }
          output->vx_p_name = vx_p_name;
          vx_core::vx_reserve(vx_p_name);
        }
        if (output->vx_p_idlist != vx_p_idlist) {
          if (output->vx_p_idlist) {
            vx_core::vx_release_one(output->vx_p_idlist);
          }
          output->vx_p_idlist = vx_p_idlist;
          vx_core::vx_reserve(vx_p_idlist);
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

    vx_core::Type_msgblock Class_filter::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_table::Class_filter::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_filter::vx_empty() const {return vx_data_table::e_filter;}
    vx_core::Type_any Class_filter::vx_type() const {return vx_data_table::t_filter;}

    vx_core::Type_typedef Class_filter::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/table", // pkgname
        "filter", // name
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
            "id", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "name", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "idlist", // name
            vx_core::t_stringlist // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_filter::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type row)
  // class Class_row {
    Abstract_row::~Abstract_row() {}

    Class_row::Class_row() : Abstract_row::Abstract_row() {
      vx_core::refcount += 1;
    }

    Class_row::~Class_row() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_cellmap,
        this->vx_p_cellsort
      });
    }

    // id()
    vx_core::Type_string Class_row::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // cellmap()
    vx_data_table::Type_cellmap Class_row::cellmap() const {
      vx_data_table::Type_cellmap output = this->vx_p_cellmap;
      if (!output) {
        output = vx_data_table::e_cellmap;
      }
      return output;
    }

    // cellsort()
    vx_data_table::Type_sort Class_row::cellsort() const {
      vx_data_table::Type_sort output = this->vx_p_cellsort;
      if (!output) {
        output = vx_data_table::e_sort;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_row::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":cellmap") {
        output = this->cellmap();
      } else if (skey == ":cellsort") {
        output = this->cellsort();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_row::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":cellmap"] = this->cellmap();
      output[":cellsort"] = this->cellsort();
      return output;
    }

    vx_core::Type_any Class_row::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_table::e_row, vals);
    }

    vx_core::Type_any Class_row::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_table::Type_row output = vx_data_table::e_row;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_table::Type_row val = vx_core::vx_any_from_any(vx_data_table::t_row, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_data_table::Type_cellmap vx_p_cellmap = val->cellmap();
      vx_data_table::Type_sort vx_p_cellsort = val->cellsort();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":cellmap") {
            key = testkey;
          } else if (testkey == ":cellsort") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new row) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (vx_p_id == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new row :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":cellmap") {
            if (vx_p_cellmap == valsub) {
            } else if (valsubtype == vx_data_table::t_cellmap) {
              ischanged = true;
              vx_p_cellmap = vx_core::vx_any_from_any(vx_data_table::t_cellmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new row :cellmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":cellsort") {
            if (vx_p_cellsort == valsub) {
            } else if (valsubtype == vx_data_table::t_sort) {
              ischanged = true;
              vx_p_cellsort = vx_core::vx_any_from_any(vx_data_table::t_sort, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new row :cellsort " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new row) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_table::Class_row();
        if (output->vx_p_id != vx_p_id) {
          if (output->vx_p_id) {
            vx_core::vx_release_one(output->vx_p_id);
          }
          output->vx_p_id = vx_p_id;
          vx_core::vx_reserve(vx_p_id);
        }
        if (output->vx_p_cellmap != vx_p_cellmap) {
          if (output->vx_p_cellmap) {
            vx_core::vx_release_one(output->vx_p_cellmap);
          }
          output->vx_p_cellmap = vx_p_cellmap;
          vx_core::vx_reserve(vx_p_cellmap);
        }
        if (output->vx_p_cellsort != vx_p_cellsort) {
          if (output->vx_p_cellsort) {
            vx_core::vx_release_one(output->vx_p_cellsort);
          }
          output->vx_p_cellsort = vx_p_cellsort;
          vx_core::vx_reserve(vx_p_cellsort);
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

    vx_core::Type_msgblock Class_row::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_table::Class_row::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_row::vx_empty() const {return vx_data_table::e_row;}
    vx_core::Type_any Class_row::vx_type() const {return vx_data_table::t_row;}

    vx_core::Type_typedef Class_row::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/table", // pkgname
        "row", // name
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
            "id", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "cellmap", // name
            vx_data_table::t_cellmap // type
          ),
          vx_core::vx_new_arg(
            "cellsort", // name
            vx_data_table::t_sort // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_row::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type rowlist)
  // class Class_rowlist {
    Abstract_rowlist::~Abstract_rowlist() {}

    Class_rowlist::Class_rowlist() : Abstract_rowlist::Abstract_rowlist() {
      vx_core::refcount += 1;
    }

    Class_rowlist::~Class_rowlist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_rowlist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_data_table::Type_row Class_rowlist::vx_get_row(vx_core::Type_int index) const {
      vx_data_table::Type_row output = vx_data_table::e_row;
      long iindex = index->vx_int();
      std::vector<vx_data_table::Type_row> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_data_table::Type_row> Class_rowlist::vx_listrow() const {return vx_p_list;}

    vx_core::Type_any vx_data_table::Class_rowlist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_row(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_rowlist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_data_table::Type_rowlist output = vx_data_table::e_rowlist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_data_table::Type_row> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_data_table::t_row) {
          vx_data_table::Type_row castval = vx_core::vx_any_from_any(vx_data_table::t_row, valsub);
          list.push_back(castval);
        } else if (vx_core::vx_boolean_from_type_trait(valtype, vx_data_table::t_row)) {
          vx_data_table::Type_row castval = vx_core::vx_any_from_any(vx_data_table::t_row, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(rowlist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((list.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_table::Class_rowlist();
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

    vx_core::Type_any Class_rowlist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_table::e_rowlist, vals);
    }

    vx_core::Type_any Class_rowlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_table::Type_rowlist output = vx_data_table::e_rowlist;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_table::Type_rowlist val = vx_core::vx_any_from_any(vx_data_table::t_rowlist, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_data_table::Type_row> listval = val->vx_listrow();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_data_table::t_row) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_data_table::t_row, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_data_table::t_row)) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_data_table::t_row, valsub));
        } else if (valsubtype == vx_data_table::t_rowlist) {
          ischanged = true;
          vx_data_table::Type_rowlist multi = vx_core::vx_any_from_any(vx_data_table::t_rowlist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listrow());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new rowlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if (ischanged || (listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_table::Class_rowlist();
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

    vx_core::Type_msgblock Class_rowlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_table::Class_rowlist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_rowlist::vx_empty() const {return vx_data_table::e_rowlist;}
    vx_core::Type_any Class_rowlist::vx_type() const {return vx_data_table::t_rowlist;}

    vx_core::Type_typedef Class_rowlist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/table", // pkgname
        "rowlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_data_table::t_row}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_rowlist::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type rowmap)
  // class Class_rowmap {
    Abstract_rowmap::~Abstract_rowmap() {}

    Class_rowmap::Class_rowmap() : Abstract_rowmap::Abstract_rowmap() {
      vx_core::refcount += 1;
    }

    Class_rowmap::~Class_rowmap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (auto const& [key, val] : this->vx_p_map) {
        vx_core::vx_release_one(val);
      }
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_rowmap::vx_map() const {
      vx_core::vx_Type_mapany output = vx_core::vx_map_from_map(vx_core::t_any, this->vx_p_map);
      return output;
    }

    // vx_set(map, string, any)
    vx_core::Type_boolean Class_rowmap::vx_set(vx_core::Type_string name, vx_core::Type_any value) {
      vx_core::Type_boolean output = vx_core::c_false;
      vx_core::Type_any valtype = value->vx_type();
      if (valtype == vx_data_table::t_row) {
        vx_data_table::Type_row newval = vx_core::vx_any_from_any(vx_data_table::t_row, value);
        std::string key = name->vx_string();
        if (vx_core::vx_boolean_from_string_starts(key, ":")) {
          key = key.substr(1, key.length());
        }
        vx_data_table::Type_row oldval = this->vx_p_map[key];
        if (oldval != newval) {
          if (oldval) {
            vx_core::vx_release_one(oldval);
          }
          if (newval == vx_data_table::e_row) {
            this->vx_p_map.erase(key);
          } else {
            vx_core::vx_reserve(newval);
            this->vx_p_map[key] = newval;
          }
        }
        output = vx_core::c_true;
      }
      return output;
    }
    // vx_get_row(key)
    vx_data_table::Type_row Class_rowmap::vx_get_row(vx_core::Type_string key) const {
      vx_data_table::Type_row output = vx_data_table::e_row;
      const vx_data_table::Class_rowmap* map = this;
      std::string skey = key->vx_string();
      if (vx_core::vx_boolean_from_string_starts(skey, ":")) {
        skey = vx_core::vx_string_from_string_start(skey, 2);
      }
      std::map<std::string, vx_data_table::Type_row> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_data_table::e_row);
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_rowmap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_row(key);
    }

    // vx_maprow()
    std::map<std::string, vx_data_table::Type_row> Class_rowmap::vx_maprow() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_rowmap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_data_table::Type_rowmap output = vx_data_table::e_rowmap;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_data_table::Type_row> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_data_table::t_row) {
          vx_data_table::Type_row castval = vx_core::vx_any_from_any(vx_data_table::t_row, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(rowmap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((map.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_table::Class_rowmap();
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

    vx_core::Type_any Class_rowmap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_table::e_rowmap, vals);
    }

    vx_core::Type_any Class_rowmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_table::Type_rowmap output = vx_data_table::e_rowmap;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_table::Type_rowmap valmap = vx_core::vx_any_from_any(vx_data_table::t_rowmap, copyval);
      output = valmap;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_data_table::Type_row> mapval = valmap->vx_maprow();
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
          vx_data_table::Type_row valany = NULL;
          if (valsubtype == vx_data_table::t_row) {
            valany = vx_core::vx_any_from_any(vx_data_table::t_row, valsub);
          } else if (valsubtype == vx_data_table::t_row) {
            valany = vx_core::vx_any_from_any(vx_data_table::t_row, valsub);
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("Invalid Key/Value: " + skey + " "  + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
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
        output = new vx_data_table::Class_rowmap();
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

    vx_core::Type_msgblock Class_rowmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_table::Class_rowmap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_rowmap::vx_empty() const {return vx_data_table::e_rowmap;}
    vx_core::Type_any Class_rowmap::vx_type() const {return vx_data_table::t_rowmap;}

    vx_core::Type_typedef Class_rowmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/table", // pkgname
        "rowmap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_data_table::t_row}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_rowmap::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type sort)
  // class Class_sort {
    Abstract_sort::~Abstract_sort() {}

    Class_sort::Class_sort() : Abstract_sort::Abstract_sort() {
      vx_core::refcount += 1;
    }

    Class_sort::~Class_sort() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_name,
        this->vx_p_idlist
      });
    }

    // id()
    vx_core::Type_string Class_sort::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // name()
    vx_core::Type_string Class_sort::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // idlist()
    vx_core::Type_stringlist Class_sort::idlist() const {
      vx_core::Type_stringlist output = this->vx_p_idlist;
      if (!output) {
        output = vx_core::e_stringlist;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_sort::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":idlist") {
        output = this->idlist();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_sort::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":name"] = this->name();
      output[":idlist"] = this->idlist();
      return output;
    }

    vx_core::Type_any Class_sort::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_table::e_sort, vals);
    }

    vx_core::Type_any Class_sort::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_table::Type_sort output = vx_data_table::e_sort;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_table::Type_sort val = vx_core::vx_any_from_any(vx_data_table::t_sort, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_core::Type_string vx_p_name = val->name();
      vx_core::Type_stringlist vx_p_idlist = val->idlist();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":name") {
            key = testkey;
          } else if (testkey == ":idlist") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new sort) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (vx_p_id == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new sort :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":name") {
            if (vx_p_name == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_name = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new sort :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":idlist") {
            if (vx_p_idlist == valsub) {
            } else if (valsubtype == vx_core::t_stringlist) {
              ischanged = true;
              vx_p_idlist = vx_core::vx_any_from_any(vx_core::t_stringlist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new sort :idlist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new sort) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_table::Class_sort();
        if (output->vx_p_id != vx_p_id) {
          if (output->vx_p_id) {
            vx_core::vx_release_one(output->vx_p_id);
          }
          output->vx_p_id = vx_p_id;
          vx_core::vx_reserve(vx_p_id);
        }
        if (output->vx_p_name != vx_p_name) {
          if (output->vx_p_name) {
            vx_core::vx_release_one(output->vx_p_name);
          }
          output->vx_p_name = vx_p_name;
          vx_core::vx_reserve(vx_p_name);
        }
        if (output->vx_p_idlist != vx_p_idlist) {
          if (output->vx_p_idlist) {
            vx_core::vx_release_one(output->vx_p_idlist);
          }
          output->vx_p_idlist = vx_p_idlist;
          vx_core::vx_reserve(vx_p_idlist);
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

    vx_core::Type_msgblock Class_sort::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_table::Class_sort::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_sort::vx_empty() const {return vx_data_table::e_sort;}
    vx_core::Type_any Class_sort::vx_type() const {return vx_data_table::t_sort;}

    vx_core::Type_typedef Class_sort::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/table", // pkgname
        "sort", // name
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
            "id", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "name", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "idlist", // name
            vx_core::t_stringlist // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_sort::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type table)
  // class Class_table {
    Abstract_table::~Abstract_table() {}

    Class_table::Class_table() : Abstract_table::Abstract_table() {
      vx_core::refcount += 1;
    }

    Class_table::~Class_table() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_name,
        this->vx_p_fieldmap,
        this->vx_p_fieldsort,
        this->vx_p_rowmap,
        this->vx_p_rowfilter,
        this->vx_p_rowsort
      });
    }

    // id()
    vx_core::Type_string Class_table::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // name()
    vx_core::Type_string Class_table::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // fieldmap()
    vx_data_table::Type_fieldmap Class_table::fieldmap() const {
      vx_data_table::Type_fieldmap output = this->vx_p_fieldmap;
      if (!output) {
        output = vx_data_table::e_fieldmap;
      }
      return output;
    }

    // fieldsort()
    vx_data_table::Type_sort Class_table::fieldsort() const {
      vx_data_table::Type_sort output = this->vx_p_fieldsort;
      if (!output) {
        output = vx_data_table::e_sort;
      }
      return output;
    }

    // rowmap()
    vx_data_table::Type_rowmap Class_table::rowmap() const {
      vx_data_table::Type_rowmap output = this->vx_p_rowmap;
      if (!output) {
        output = vx_data_table::e_rowmap;
      }
      return output;
    }

    // rowfilter()
    vx_data_table::Type_filter Class_table::rowfilter() const {
      vx_data_table::Type_filter output = this->vx_p_rowfilter;
      if (!output) {
        output = vx_data_table::e_filter;
      }
      return output;
    }

    // rowsort()
    vx_data_table::Type_sort Class_table::rowsort() const {
      vx_data_table::Type_sort output = this->vx_p_rowsort;
      if (!output) {
        output = vx_data_table::e_sort;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_table::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":fieldmap") {
        output = this->fieldmap();
      } else if (skey == ":fieldsort") {
        output = this->fieldsort();
      } else if (skey == ":rowmap") {
        output = this->rowmap();
      } else if (skey == ":rowfilter") {
        output = this->rowfilter();
      } else if (skey == ":rowsort") {
        output = this->rowsort();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_table::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":name"] = this->name();
      output[":fieldmap"] = this->fieldmap();
      output[":fieldsort"] = this->fieldsort();
      output[":rowmap"] = this->rowmap();
      output[":rowfilter"] = this->rowfilter();
      output[":rowsort"] = this->rowsort();
      return output;
    }

    vx_core::Type_any Class_table::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_table::e_table, vals);
    }

    vx_core::Type_any Class_table::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_table::Type_table output = vx_data_table::e_table;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_table::Type_table val = vx_core::vx_any_from_any(vx_data_table::t_table, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_core::Type_string vx_p_name = val->name();
      vx_data_table::Type_fieldmap vx_p_fieldmap = val->fieldmap();
      vx_data_table::Type_sort vx_p_fieldsort = val->fieldsort();
      vx_data_table::Type_rowmap vx_p_rowmap = val->rowmap();
      vx_data_table::Type_filter vx_p_rowfilter = val->rowfilter();
      vx_data_table::Type_sort vx_p_rowsort = val->rowsort();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":name") {
            key = testkey;
          } else if (testkey == ":fieldmap") {
            key = testkey;
          } else if (testkey == ":fieldsort") {
            key = testkey;
          } else if (testkey == ":rowmap") {
            key = testkey;
          } else if (testkey == ":rowfilter") {
            key = testkey;
          } else if (testkey == ":rowsort") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new table) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (vx_p_id == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new table :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":name") {
            if (vx_p_name == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_name = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new table :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":fieldmap") {
            if (vx_p_fieldmap == valsub) {
            } else if (valsubtype == vx_data_table::t_fieldmap) {
              ischanged = true;
              vx_p_fieldmap = vx_core::vx_any_from_any(vx_data_table::t_fieldmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new table :fieldmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":fieldsort") {
            if (vx_p_fieldsort == valsub) {
            } else if (valsubtype == vx_data_table::t_sort) {
              ischanged = true;
              vx_p_fieldsort = vx_core::vx_any_from_any(vx_data_table::t_sort, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new table :fieldsort " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":rowmap") {
            if (vx_p_rowmap == valsub) {
            } else if (valsubtype == vx_data_table::t_rowmap) {
              ischanged = true;
              vx_p_rowmap = vx_core::vx_any_from_any(vx_data_table::t_rowmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new table :rowmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":rowfilter") {
            if (vx_p_rowfilter == valsub) {
            } else if (valsubtype == vx_data_table::t_filter) {
              ischanged = true;
              vx_p_rowfilter = vx_core::vx_any_from_any(vx_data_table::t_filter, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new table :rowfilter " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":rowsort") {
            if (vx_p_rowsort == valsub) {
            } else if (valsubtype == vx_data_table::t_sort) {
              ischanged = true;
              vx_p_rowsort = vx_core::vx_any_from_any(vx_data_table::t_sort, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new table :rowsort " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new table) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_table::Class_table();
        if (output->vx_p_id != vx_p_id) {
          if (output->vx_p_id) {
            vx_core::vx_release_one(output->vx_p_id);
          }
          output->vx_p_id = vx_p_id;
          vx_core::vx_reserve(vx_p_id);
        }
        if (output->vx_p_name != vx_p_name) {
          if (output->vx_p_name) {
            vx_core::vx_release_one(output->vx_p_name);
          }
          output->vx_p_name = vx_p_name;
          vx_core::vx_reserve(vx_p_name);
        }
        if (output->vx_p_fieldmap != vx_p_fieldmap) {
          if (output->vx_p_fieldmap) {
            vx_core::vx_release_one(output->vx_p_fieldmap);
          }
          output->vx_p_fieldmap = vx_p_fieldmap;
          vx_core::vx_reserve(vx_p_fieldmap);
        }
        if (output->vx_p_fieldsort != vx_p_fieldsort) {
          if (output->vx_p_fieldsort) {
            vx_core::vx_release_one(output->vx_p_fieldsort);
          }
          output->vx_p_fieldsort = vx_p_fieldsort;
          vx_core::vx_reserve(vx_p_fieldsort);
        }
        if (output->vx_p_rowmap != vx_p_rowmap) {
          if (output->vx_p_rowmap) {
            vx_core::vx_release_one(output->vx_p_rowmap);
          }
          output->vx_p_rowmap = vx_p_rowmap;
          vx_core::vx_reserve(vx_p_rowmap);
        }
        if (output->vx_p_rowfilter != vx_p_rowfilter) {
          if (output->vx_p_rowfilter) {
            vx_core::vx_release_one(output->vx_p_rowfilter);
          }
          output->vx_p_rowfilter = vx_p_rowfilter;
          vx_core::vx_reserve(vx_p_rowfilter);
        }
        if (output->vx_p_rowsort != vx_p_rowsort) {
          if (output->vx_p_rowsort) {
            vx_core::vx_release_one(output->vx_p_rowsort);
          }
          output->vx_p_rowsort = vx_p_rowsort;
          vx_core::vx_reserve(vx_p_rowsort);
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

    vx_core::Type_msgblock Class_table::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_table::Class_table::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_table::vx_empty() const {return vx_data_table::e_table;}
    vx_core::Type_any Class_table::vx_type() const {return vx_data_table::t_table;}

    vx_core::Type_typedef Class_table::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/table", // pkgname
        "table", // name
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
            "id", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "name", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "fieldmap", // name
            vx_data_table::t_fieldmap // type
          ),
          vx_core::vx_new_arg(
            "fieldsort", // name
            vx_data_table::t_sort // type
          ),
          vx_core::vx_new_arg(
            "rowmap", // name
            vx_data_table::t_rowmap // type
          ),
          vx_core::vx_new_arg(
            "rowfilter", // name
            vx_data_table::t_filter // type
          ),
          vx_core::vx_new_arg(
            "rowsort", // name
            vx_data_table::t_sort // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_table::vx_constdef() const {return this->vx_p_constdef;}


  //}

  vx_data_table::Type_cell e_cell = NULL;
  vx_data_table::Type_cell t_cell = NULL;
  vx_data_table::Type_celllist e_celllist = NULL;
  vx_data_table::Type_celllist t_celllist = NULL;
  vx_data_table::Type_cellmap e_cellmap = NULL;
  vx_data_table::Type_cellmap t_cellmap = NULL;
  vx_data_table::Type_field e_field = NULL;
  vx_data_table::Type_field t_field = NULL;
  vx_data_table::Type_fieldlist e_fieldlist = NULL;
  vx_data_table::Type_fieldlist t_fieldlist = NULL;
  vx_data_table::Type_fieldmap e_fieldmap = NULL;
  vx_data_table::Type_fieldmap t_fieldmap = NULL;
  vx_data_table::Type_filter e_filter = NULL;
  vx_data_table::Type_filter t_filter = NULL;
  vx_data_table::Type_row e_row = NULL;
  vx_data_table::Type_row t_row = NULL;
  vx_data_table::Type_rowlist e_rowlist = NULL;
  vx_data_table::Type_rowlist t_rowlist = NULL;
  vx_data_table::Type_rowmap e_rowmap = NULL;
  vx_data_table::Type_rowmap t_rowmap = NULL;
  vx_data_table::Type_sort e_sort = NULL;
  vx_data_table::Type_sort t_sort = NULL;
  vx_data_table::Type_table e_table = NULL;
  vx_data_table::Type_table t_table = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_data_table::e_cell = new Class_cell();
      vx_core::vx_reserve_empty(vx_data_table::e_cell);
      vx_data_table::t_cell = new Class_cell();
      vx_core::vx_reserve_type(vx_data_table::t_cell);
      vx_data_table::e_celllist = new Class_celllist();
      vx_core::vx_reserve_empty(vx_data_table::e_celllist);
      vx_data_table::t_celllist = new Class_celllist();
      vx_core::vx_reserve_type(vx_data_table::t_celllist);
      vx_data_table::e_cellmap = new Class_cellmap();
      vx_core::vx_reserve_empty(vx_data_table::e_cellmap);
      vx_data_table::t_cellmap = new Class_cellmap();
      vx_core::vx_reserve_type(vx_data_table::t_cellmap);
      vx_data_table::e_field = new Class_field();
      vx_core::vx_reserve_empty(vx_data_table::e_field);
      vx_data_table::t_field = new Class_field();
      vx_core::vx_reserve_type(vx_data_table::t_field);
      vx_data_table::e_fieldlist = new Class_fieldlist();
      vx_core::vx_reserve_empty(vx_data_table::e_fieldlist);
      vx_data_table::t_fieldlist = new Class_fieldlist();
      vx_core::vx_reserve_type(vx_data_table::t_fieldlist);
      vx_data_table::e_fieldmap = new Class_fieldmap();
      vx_core::vx_reserve_empty(vx_data_table::e_fieldmap);
      vx_data_table::t_fieldmap = new Class_fieldmap();
      vx_core::vx_reserve_type(vx_data_table::t_fieldmap);
      vx_data_table::e_filter = new Class_filter();
      vx_core::vx_reserve_empty(vx_data_table::e_filter);
      vx_data_table::t_filter = new Class_filter();
      vx_core::vx_reserve_type(vx_data_table::t_filter);
      vx_data_table::e_row = new Class_row();
      vx_core::vx_reserve_empty(vx_data_table::e_row);
      vx_data_table::t_row = new Class_row();
      vx_core::vx_reserve_type(vx_data_table::t_row);
      vx_data_table::e_rowlist = new Class_rowlist();
      vx_core::vx_reserve_empty(vx_data_table::e_rowlist);
      vx_data_table::t_rowlist = new Class_rowlist();
      vx_core::vx_reserve_type(vx_data_table::t_rowlist);
      vx_data_table::e_rowmap = new Class_rowmap();
      vx_core::vx_reserve_empty(vx_data_table::e_rowmap);
      vx_data_table::t_rowmap = new Class_rowmap();
      vx_core::vx_reserve_type(vx_data_table::t_rowmap);
      vx_data_table::e_sort = new Class_sort();
      vx_core::vx_reserve_empty(vx_data_table::e_sort);
      vx_data_table::t_sort = new Class_sort();
      vx_core::vx_reserve_type(vx_data_table::t_sort);
      vx_data_table::e_table = new Class_table();
      vx_core::vx_reserve_empty(vx_data_table::e_table);
      vx_data_table::t_table = new Class_table();
      vx_core::vx_reserve_type(vx_data_table::t_table);
      vx_core::vx_Type_mapany maptype;
      vx_core::vx_Type_mapany mapconst;
      vx_core::vx_Type_mapfunc mapfunc;
      vx_core::vx_Type_mapany mapempty;
      maptype["cell"] = vx_data_table::t_cell;
      maptype["celllist"] = vx_data_table::t_celllist;
      maptype["cellmap"] = vx_data_table::t_cellmap;
      maptype["field"] = vx_data_table::t_field;
      maptype["fieldlist"] = vx_data_table::t_fieldlist;
      maptype["fieldmap"] = vx_data_table::t_fieldmap;
      maptype["filter"] = vx_data_table::t_filter;
      maptype["row"] = vx_data_table::t_row;
      maptype["rowlist"] = vx_data_table::t_rowlist;
      maptype["rowmap"] = vx_data_table::t_rowmap;
      maptype["sort"] = vx_data_table::t_sort;
      maptype["table"] = vx_data_table::t_table;
      vx_core::vx_global_package_set("vx/data/table", maptype, mapconst, mapfunc);
	   }
  // }

}
