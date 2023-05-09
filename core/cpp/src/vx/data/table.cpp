#include <any>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "vx/data/table.hpp"

//namespace vx_data_table {

  /**
   * type: cell
   * (type cell)
   */
  //class Type_cell {
    // id()
    vx_core::Type_string* vx_data_table::Type_cell::id() {
      vx_core::Type_string* output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // value()
    vx_core::Type_any* vx_data_table::Type_cell::value() {
      vx_core::Type_any* output = this->vx_p_value;
      if (output == NULL) {
        output = vx_core::t_any;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_data_table::Type_cell::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":value") {
        output = this->value();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_data_table::Type_cell::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":id"] = this->id();
      output[":value"] = this->value();
      return output;
    }

    template<typename... Args> vx_data_table::Type_cell* vx_data_table::Type_cell::vx_new(Args*... args) {return vx_data_table::e_cell->vx_copy(args...);}
    template<typename... Args> vx_data_table::Type_cell* vx_data_table::Type_cell::vx_copy(Args*... args) {
      vx_data_table::Type_cell* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_cell* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_value = val->value();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
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
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new cell) - Invalid Key Type: " + vx_core::string_from_any(valsub));
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
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new cell :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":value") {
            if (valsubtype == vx_core::t_any) {
              output->vx_p_value = vx_core::any_from_any(vx_core::t_any, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new cell :value " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new cell) - Invalid Key: " + key);
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

    vx_data_table::Type_cell* vx_data_table::Type_cell::vx_empty() {return vx_data_table::e_cell;}
    vx_data_table::Type_cell* vx_data_table::Type_cell::vx_type() {return vx_data_table::t_cell;}

    vx_core::Type_typedef* vx_data_table::Type_cell::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
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
        vx_core::e_argmap // properties
      );
    }

  //}

  /**
   * type: celllist
   * (type celllist)
   */
  //class Type_celllist {
    std::vector<vx_core::Type_any*> vx_data_table::Type_celllist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_data_table::Type_cell* vx_data_table::Type_celllist::vx_cell(vx_core::Type_int* index) {
      vx_data_table::Type_cell* output = vx_data_table::e_cell;
      vx_data_table::Type_celllist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_data_table::Type_cell*> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_data_table::Type_cell*> vx_data_table::Type_celllist::vx_listcell() {return vx_p_list;}

    vx_core::Type_any* vx_data_table::Type_celllist::vx_any(vx_core::Type_int* index) {
      return this->vx_cell(index);
    }

    template<typename... Args> vx_data_table::Type_celllist* vx_data_table::Type_celllist::vx_new(Args*... args) {return vx_data_table::e_celllist->vx_copy(args...);}
    template<typename... Args> vx_data_table::Type_celllist* vx_data_table::Type_celllist::vx_copy(Args*... args) {
      vx_data_table::Type_celllist* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_data_table::Type_celllist* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_data_table::Type_cell*> listval = val->vx_listcell();
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_data_table::t_cell) {
          listval.push_back(vx_core::any_from_any(vx_data_table::t_cell, valsub));
        } else if (valsubtype == vx_data_table::t_celllist) {
          vx_data_table::Type_celllist* multi = vx_core::any_from_any(vx_data_table::t_celllist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listcell());
        } else if (valsubtype == vx_core::t_nativelist) {
          std::vector<std::any*> listunknown = vx_core::any_from_any(std::vector<vx_core::Type_any*>, valsub);
          for (std::any* item : listunknown) {
            vx_core::Type_any* itemtype = vx_core::t_any->vx_type_from_any(item);
            if (itemtype == vx_data_table::t_cell) {
              vx_data_table::Type_cell* valitem = vx_core::any_from_any(vx_data_table::t_cell, item);
              listval.push_back(valitem);
            }
          }
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new celllist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(msg);
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_data_table::Type_celllist* vx_data_table::Type_celllist::vx_empty() {return vx_data_table::e_celllist;}
    vx_data_table::Type_celllist* vx_data_table::Type_celllist::vx_type() {return vx_data_table::t_celllist;}

    vx_core::Type_typedef* vx_data_table::Type_celllist::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/data/table", // pkgname
        "celllist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_data_table::t_cell), // allowtypes
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
   * type: cellmap
   * (type cellmap)
   */
  //class Type_cellmap {
    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_data_table::Type_cellmap::vx_map() {
      return vx_core::map_from_map(vx_core::t_any, this->vx_p_map);
    }

    // vx_cell(key)
    vx_data_table::Type_cell* vx_data_table::Type_cellmap::vx_cell(vx_core::Type_string* key) {
      vx_data_table::Type_cell* output = vx_data_table::e_cell;
      vx_data_table::Type_cellmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_data_table::Type_cell*> mapval = map->vx_p_map;
      output = vx_core::any_from_map(mapval, skey, vx_data_table::e_cell);
      return output;
    }

    // vx_any(key)
    vx_core::Type_any* vx_data_table::Type_cellmap::vx_any(vx_core::Type_string* key) {
      return this->vx_cell(key);
    }

    // vx_mapcell()
    std::map<std::string, vx_data_table::Type_cell*> vx_data_table::Type_cellmap::vx_mapcell() {return vx_p_map;}

    // vx_new_from_map(mapval)
    vx_data_table::Type_cellmap* vx_data_table::Type_cellmap::vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval) {
      vx_data_table::Type_cellmap* output;
      vx_core::Type_msgblock* msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_data_table::Type_cell*> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any* val = iter.second;
        vx_core::Type_any* valtype = vx_core::t_any->vx_type_from_any(val);
        if (valtype == vx_data_table::t_cell) {
          vx_data_table::Type_cell* castval = vx_core::any_from_any(vx_data_table::t_cell, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(cellmap) Invalid Value: " + vx_core::string_from_any(val) + "");
          msgblock = vx_core::t_msgblock->vx_copy(msgblock, msg);
        }
      }
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template<typename... Args> vx_data_table::Type_cellmap* vx_data_table::Type_cellmap::vx_new(Args*... args) {return vx_data_table::e_cellmap->vx_copy(args...);}
    template<typename... Args> vx_data_table::Type_cellmap* vx_data_table::Type_cellmap::vx_copy(Args*... args) {
      vx_data_table::Type_cellmap* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_data_table::Type_cellmap* valmap = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(valmap, vals);
      std::map<std::string, vx_data_table::Type_cell*> mapval;
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
          vx_data_table::Type_cell* valany;
          if (valsubtype == vx_data_table::t_cell) {
            valany = vx_core::any_from_any(vx_data_table::t_cell, valsub);
          } else if (valsubtype == vx_data_table::t_cell) {
            valany = vx_core::any_from_any(vx_data_table::t_cell, valsub);
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

    vx_data_table::Type_cellmap* vx_data_table::Type_cellmap::vx_empty() {return vx_data_table::e_cellmap;}
    vx_data_table::Type_cellmap* vx_data_table::Type_cellmap::vx_type() {return vx_data_table::t_cellmap;}

    vx_core::Type_typedef* vx_data_table::Type_cellmap::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/data/table", // pkgname
        "cellmap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_data_table::t_cell), // allowtypes
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
   * type: field
   * (type field)
   */
  //class Type_field {
    // id()
    vx_core::Type_string* vx_data_table::Type_field::id() {
      vx_core::Type_string* output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // name()
    vx_core::Type_string* vx_data_table::Type_field::name() {
      vx_core::Type_string* output = this->vx_p_name;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // fldtype()
    vx_core::Type_any* vx_data_table::Type_field::fldtype() {
      vx_core::Type_any* output = this->vx_p_fldtype;
      if (output == NULL) {
        output = vx_core::t_any;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_data_table::Type_field::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":fldtype") {
        output = this->fldtype();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_data_table::Type_field::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":id"] = this->id();
      output[":name"] = this->name();
      output[":fldtype"] = this->fldtype();
      return output;
    }

    template<typename... Args> vx_data_table::Type_field* vx_data_table::Type_field::vx_new(Args*... args) {return vx_data_table::e_field->vx_copy(args...);}
    template<typename... Args> vx_data_table::Type_field* vx_data_table::Type_field::vx_copy(Args*... args) {
      vx_data_table::Type_field* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_field* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_name = val->name();
      output->vx_p_fldtype = val->fldtype();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
      validkeys.insert(":name");
      validkeys.insert(":fldtype");
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
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new field) - Invalid Key Type: " + vx_core::string_from_any(valsub));
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
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new field :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_name = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_name = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new field :name " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":fldtype") {
            if (valsubtype == vx_core::t_any) {
              output->vx_p_fldtype = vx_core::any_from_any(vx_core::t_any, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new field :fldtype " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new field) - Invalid Key: " + key);
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

    vx_data_table::Type_field* vx_data_table::Type_field::vx_empty() {return vx_data_table::e_field;}
    vx_data_table::Type_field* vx_data_table::Type_field::vx_type() {return vx_data_table::t_field;}

    vx_core::Type_typedef* vx_data_table::Type_field::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
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
        vx_core::e_argmap // properties
      );
    }

  //}

  /**
   * type: fieldlist
   * (type fieldlist)
   */
  //class Type_fieldlist {
    std::vector<vx_core::Type_any*> vx_data_table::Type_fieldlist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_data_table::Type_field* vx_data_table::Type_fieldlist::vx_field(vx_core::Type_int* index) {
      vx_data_table::Type_field* output = vx_data_table::e_field;
      vx_data_table::Type_fieldlist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_data_table::Type_field*> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_data_table::Type_field*> vx_data_table::Type_fieldlist::vx_listfield() {return vx_p_list;}

    vx_core::Type_any* vx_data_table::Type_fieldlist::vx_any(vx_core::Type_int* index) {
      return this->vx_field(index);
    }

    template<typename... Args> vx_data_table::Type_fieldlist* vx_data_table::Type_fieldlist::vx_new(Args*... args) {return vx_data_table::e_fieldlist->vx_copy(args...);}
    template<typename... Args> vx_data_table::Type_fieldlist* vx_data_table::Type_fieldlist::vx_copy(Args*... args) {
      vx_data_table::Type_fieldlist* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_data_table::Type_fieldlist* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_data_table::Type_field*> listval = val->vx_listfield();
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_data_table::t_field) {
          listval.push_back(vx_core::any_from_any(vx_data_table::t_field, valsub));
        } else if (valsubtype == vx_data_table::t_fieldlist) {
          vx_data_table::Type_fieldlist* multi = vx_core::any_from_any(vx_data_table::t_fieldlist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listfield());
        } else if (valsubtype == vx_core::t_nativelist) {
          std::vector<std::any*> listunknown = vx_core::any_from_any(std::vector<vx_core::Type_any*>, valsub);
          for (std::any* item : listunknown) {
            vx_core::Type_any* itemtype = vx_core::t_any->vx_type_from_any(item);
            if (itemtype == vx_data_table::t_field) {
              vx_data_table::Type_field* valitem = vx_core::any_from_any(vx_data_table::t_field, item);
              listval.push_back(valitem);
            }
          }
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new fieldlist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(msg);
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_data_table::Type_fieldlist* vx_data_table::Type_fieldlist::vx_empty() {return vx_data_table::e_fieldlist;}
    vx_data_table::Type_fieldlist* vx_data_table::Type_fieldlist::vx_type() {return vx_data_table::t_fieldlist;}

    vx_core::Type_typedef* vx_data_table::Type_fieldlist::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/data/table", // pkgname
        "fieldlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_data_table::t_field), // allowtypes
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
   * type: fieldmap
   * (type fieldmap)
   */
  //class Type_fieldmap {
    std::vector<vx_core::Type_any*> vx_data_table::Type_fieldmap::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_data_table::Type_field* vx_data_table::Type_fieldmap::vx_field(vx_core::Type_int* index) {
      vx_data_table::Type_field* output = vx_data_table::e_field;
      vx_data_table::Type_fieldmap* list = this;
      int iindex = index->vx_int();
      std::vector<vx_data_table::Type_field*> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_data_table::Type_field*> vx_data_table::Type_fieldmap::vx_listfield() {return vx_p_list;}

    vx_core::Type_any* vx_data_table::Type_fieldmap::vx_any(vx_core::Type_int* index) {
      return this->vx_field(index);
    }

    template<typename... Args> vx_data_table::Type_fieldmap* vx_data_table::Type_fieldmap::vx_new(Args*... args) {return vx_data_table::e_fieldmap->vx_copy(args...);}
    template<typename... Args> vx_data_table::Type_fieldmap* vx_data_table::Type_fieldmap::vx_copy(Args*... args) {
      vx_data_table::Type_fieldmap* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_data_table::Type_fieldmap* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_data_table::Type_field*> listval = val->vx_listfield();
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_data_table::t_field) {
          listval.push_back(vx_core::any_from_any(vx_data_table::t_field, valsub));
        } else if (valsubtype == vx_data_table::t_fieldmap) {
          vx_data_table::Type_fieldmap* multi = vx_core::any_from_any(vx_data_table::t_fieldmap, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listfield());
        } else if (valsubtype == vx_core::t_nativelist) {
          std::vector<std::any*> listunknown = vx_core::any_from_any(std::vector<vx_core::Type_any*>, valsub);
          for (std::any* item : listunknown) {
            vx_core::Type_any* itemtype = vx_core::t_any->vx_type_from_any(item);
            if (itemtype == vx_data_table::t_field) {
              vx_data_table::Type_field* valitem = vx_core::any_from_any(vx_data_table::t_field, item);
              listval.push_back(valitem);
            }
          }
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new fieldmap) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(msg);
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_data_table::Type_fieldmap* vx_data_table::Type_fieldmap::vx_empty() {return vx_data_table::e_fieldmap;}
    vx_data_table::Type_fieldmap* vx_data_table::Type_fieldmap::vx_type() {return vx_data_table::t_fieldmap;}

    vx_core::Type_typedef* vx_data_table::Type_fieldmap::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/data/table", // pkgname
        "fieldmap", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_data_table::t_field), // allowtypes
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
   * type: filter
   * (type filter)
   */
  //class Type_filter {
    // id()
    vx_core::Type_string* vx_data_table::Type_filter::id() {
      vx_core::Type_string* output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // name()
    vx_core::Type_string* vx_data_table::Type_filter::name() {
      vx_core::Type_string* output = this->vx_p_name;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // idlist()
    vx_core::Type_stringlist* vx_data_table::Type_filter::idlist() {
      vx_core::Type_stringlist* output = this->vx_p_idlist;
      if (output == NULL) {
        output = vx_core::t_stringlist;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_data_table::Type_filter::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":idlist") {
        output = this->idlist();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_data_table::Type_filter::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":id"] = this->id();
      output[":name"] = this->name();
      output[":idlist"] = this->idlist();
      return output;
    }

    template<typename... Args> vx_data_table::Type_filter* vx_data_table::Type_filter::vx_new(Args*... args) {return vx_data_table::e_filter->vx_copy(args...);}
    template<typename... Args> vx_data_table::Type_filter* vx_data_table::Type_filter::vx_copy(Args*... args) {
      vx_data_table::Type_filter* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_filter* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_name = val->name();
      output->vx_p_idlist = val->idlist();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
      validkeys.insert(":name");
      validkeys.insert(":idlist");
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
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new filter) - Invalid Key Type: " + vx_core::string_from_any(valsub));
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
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new filter :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_name = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_name = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new filter :name " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":idlist") {
            if (valsubtype == vx_core::t_stringlist) {
              output->vx_p_idlist = vx_core::any_from_any(vx_core::t_stringlist, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new filter :idlist " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new filter) - Invalid Key: " + key);
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

    vx_data_table::Type_filter* vx_data_table::Type_filter::vx_empty() {return vx_data_table::e_filter;}
    vx_data_table::Type_filter* vx_data_table::Type_filter::vx_type() {return vx_data_table::t_filter;}

    vx_core::Type_typedef* vx_data_table::Type_filter::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
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
        vx_core::e_argmap // properties
      );
    }

  //}

  /**
   * type: row
   * (type row)
   */
  //class Type_row {
    // id()
    vx_core::Type_string* vx_data_table::Type_row::id() {
      vx_core::Type_string* output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // cellmap()
    vx_data_table::Type_cellmap* vx_data_table::Type_row::cellmap() {
      vx_data_table::Type_cellmap* output = this->vx_p_cellmap;
      if (output == NULL) {
        output = vx_data_table::t_cellmap;
      }
    }

    // cellsort()
    vx_data_table::Type_sort* vx_data_table::Type_row::cellsort() {
      vx_data_table::Type_sort* output = this->vx_p_cellsort;
      if (output == NULL) {
        output = vx_data_table::t_sort;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_data_table::Type_row::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":cellmap") {
        output = this->cellmap();
      } else if (skey == ":cellsort") {
        output = this->cellsort();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_data_table::Type_row::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":id"] = this->id();
      output[":cellmap"] = this->cellmap();
      output[":cellsort"] = this->cellsort();
      return output;
    }

    template<typename... Args> vx_data_table::Type_row* vx_data_table::Type_row::vx_new(Args*... args) {return vx_data_table::e_row->vx_copy(args...);}
    template<typename... Args> vx_data_table::Type_row* vx_data_table::Type_row::vx_copy(Args*... args) {
      vx_data_table::Type_row* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_row* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_cellmap = val->cellmap();
      output->vx_p_cellsort = val->cellsort();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
      validkeys.insert(":cellmap");
      validkeys.insert(":cellsort");
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
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new row) - Invalid Key Type: " + vx_core::string_from_any(valsub));
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
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new row :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":cellmap") {
            if (valsubtype == vx_data_table::t_cellmap) {
              output->vx_p_cellmap = vx_core::any_from_any(vx_data_table::t_cellmap, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new row :cellmap " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":cellsort") {
            if (valsubtype == vx_data_table::t_sort) {
              output->vx_p_cellsort = vx_core::any_from_any(vx_data_table::t_sort, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new row :cellsort " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new row) - Invalid Key: " + key);
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

    vx_data_table::Type_row* vx_data_table::Type_row::vx_empty() {return vx_data_table::e_row;}
    vx_data_table::Type_row* vx_data_table::Type_row::vx_type() {return vx_data_table::t_row;}

    vx_core::Type_typedef* vx_data_table::Type_row::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
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
        vx_core::e_argmap // properties
      );
    }

  //}

  /**
   * type: rowlist
   * (type rowlist)
   */
  //class Type_rowlist {
    std::vector<vx_core::Type_any*> vx_data_table::Type_rowlist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_data_table::Type_row* vx_data_table::Type_rowlist::vx_row(vx_core::Type_int* index) {
      vx_data_table::Type_row* output = vx_data_table::e_row;
      vx_data_table::Type_rowlist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_data_table::Type_row*> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_data_table::Type_row*> vx_data_table::Type_rowlist::vx_listrow() {return vx_p_list;}

    vx_core::Type_any* vx_data_table::Type_rowlist::vx_any(vx_core::Type_int* index) {
      return this->vx_row(index);
    }

    template<typename... Args> vx_data_table::Type_rowlist* vx_data_table::Type_rowlist::vx_new(Args*... args) {return vx_data_table::e_rowlist->vx_copy(args...);}
    template<typename... Args> vx_data_table::Type_rowlist* vx_data_table::Type_rowlist::vx_copy(Args*... args) {
      vx_data_table::Type_rowlist* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_data_table::Type_rowlist* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_data_table::Type_row*> listval = val->vx_listrow();
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_data_table::t_row) {
          listval.push_back(vx_core::any_from_any(vx_data_table::t_row, valsub));
        } else if (valsubtype == vx_data_table::t_rowlist) {
          vx_data_table::Type_rowlist* multi = vx_core::any_from_any(vx_data_table::t_rowlist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listrow());
        } else if (valsubtype == vx_core::t_nativelist) {
          std::vector<std::any*> listunknown = vx_core::any_from_any(std::vector<vx_core::Type_any*>, valsub);
          for (std::any* item : listunknown) {
            vx_core::Type_any* itemtype = vx_core::t_any->vx_type_from_any(item);
            if (itemtype == vx_data_table::t_row) {
              vx_data_table::Type_row* valitem = vx_core::any_from_any(vx_data_table::t_row, item);
              listval.push_back(valitem);
            }
          }
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new rowlist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(msg);
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_data_table::Type_rowlist* vx_data_table::Type_rowlist::vx_empty() {return vx_data_table::e_rowlist;}
    vx_data_table::Type_rowlist* vx_data_table::Type_rowlist::vx_type() {return vx_data_table::t_rowlist;}

    vx_core::Type_typedef* vx_data_table::Type_rowlist::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/data/table", // pkgname
        "rowlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_data_table::t_row), // allowtypes
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
   * type: rowmap
   * (type rowmap)
   */
  //class Type_rowmap {
    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_data_table::Type_rowmap::vx_map() {
      return vx_core::map_from_map(vx_core::t_any, this->vx_p_map);
    }

    // vx_row(key)
    vx_data_table::Type_row* vx_data_table::Type_rowmap::vx_row(vx_core::Type_string* key) {
      vx_data_table::Type_row* output = vx_data_table::e_row;
      vx_data_table::Type_rowmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_data_table::Type_row*> mapval = map->vx_p_map;
      output = vx_core::any_from_map(mapval, skey, vx_data_table::e_row);
      return output;
    }

    // vx_any(key)
    vx_core::Type_any* vx_data_table::Type_rowmap::vx_any(vx_core::Type_string* key) {
      return this->vx_row(key);
    }

    // vx_maprow()
    std::map<std::string, vx_data_table::Type_row*> vx_data_table::Type_rowmap::vx_maprow() {return vx_p_map;}

    // vx_new_from_map(mapval)
    vx_data_table::Type_rowmap* vx_data_table::Type_rowmap::vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval) {
      vx_data_table::Type_rowmap* output;
      vx_core::Type_msgblock* msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_data_table::Type_row*> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any* val = iter.second;
        vx_core::Type_any* valtype = vx_core::t_any->vx_type_from_any(val);
        if (valtype == vx_data_table::t_row) {
          vx_data_table::Type_row* castval = vx_core::any_from_any(vx_data_table::t_row, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(rowmap) Invalid Value: " + vx_core::string_from_any(val) + "");
          msgblock = vx_core::t_msgblock->vx_copy(msgblock, msg);
        }
      }
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template<typename... Args> vx_data_table::Type_rowmap* vx_data_table::Type_rowmap::vx_new(Args*... args) {return vx_data_table::e_rowmap->vx_copy(args...);}
    template<typename... Args> vx_data_table::Type_rowmap* vx_data_table::Type_rowmap::vx_copy(Args*... args) {
      vx_data_table::Type_rowmap* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_data_table::Type_rowmap* valmap = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(valmap, vals);
      std::map<std::string, vx_data_table::Type_row*> mapval;
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
          vx_data_table::Type_row* valany;
          if (valsubtype == vx_data_table::t_row) {
            valany = vx_core::any_from_any(vx_data_table::t_row, valsub);
          } else if (valsubtype == vx_data_table::t_row) {
            valany = vx_core::any_from_any(vx_data_table::t_row, valsub);
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

    vx_data_table::Type_rowmap* vx_data_table::Type_rowmap::vx_empty() {return vx_data_table::e_rowmap;}
    vx_data_table::Type_rowmap* vx_data_table::Type_rowmap::vx_type() {return vx_data_table::t_rowmap;}

    vx_core::Type_typedef* vx_data_table::Type_rowmap::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/data/table", // pkgname
        "rowmap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_data_table::t_row), // allowtypes
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
   * type: sort
   * (type sort)
   */
  //class Type_sort {
    // id()
    vx_core::Type_string* vx_data_table::Type_sort::id() {
      vx_core::Type_string* output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // name()
    vx_core::Type_string* vx_data_table::Type_sort::name() {
      vx_core::Type_string* output = this->vx_p_name;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // idlist()
    vx_core::Type_stringlist* vx_data_table::Type_sort::idlist() {
      vx_core::Type_stringlist* output = this->vx_p_idlist;
      if (output == NULL) {
        output = vx_core::t_stringlist;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_data_table::Type_sort::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":idlist") {
        output = this->idlist();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_data_table::Type_sort::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":id"] = this->id();
      output[":name"] = this->name();
      output[":idlist"] = this->idlist();
      return output;
    }

    template<typename... Args> vx_data_table::Type_sort* vx_data_table::Type_sort::vx_new(Args*... args) {return vx_data_table::e_sort->vx_copy(args...);}
    template<typename... Args> vx_data_table::Type_sort* vx_data_table::Type_sort::vx_copy(Args*... args) {
      vx_data_table::Type_sort* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_sort* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_name = val->name();
      output->vx_p_idlist = val->idlist();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
      validkeys.insert(":name");
      validkeys.insert(":idlist");
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
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new sort) - Invalid Key Type: " + vx_core::string_from_any(valsub));
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
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new sort :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_name = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_name = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new sort :name " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":idlist") {
            if (valsubtype == vx_core::t_stringlist) {
              output->vx_p_idlist = vx_core::any_from_any(vx_core::t_stringlist, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new sort :idlist " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new sort) - Invalid Key: " + key);
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

    vx_data_table::Type_sort* vx_data_table::Type_sort::vx_empty() {return vx_data_table::e_sort;}
    vx_data_table::Type_sort* vx_data_table::Type_sort::vx_type() {return vx_data_table::t_sort;}

    vx_core::Type_typedef* vx_data_table::Type_sort::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
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
        vx_core::e_argmap // properties
      );
    }

  //}

  /**
   * type: table
   * (type table)
   */
  //class Type_table {
    // id()
    vx_core::Type_string* vx_data_table::Type_table::id() {
      vx_core::Type_string* output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // name()
    vx_core::Type_string* vx_data_table::Type_table::name() {
      vx_core::Type_string* output = this->vx_p_name;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // fieldmap()
    vx_data_table::Type_fieldmap* vx_data_table::Type_table::fieldmap() {
      vx_data_table::Type_fieldmap* output = this->vx_p_fieldmap;
      if (output == NULL) {
        output = vx_data_table::t_fieldmap;
      }
    }

    // fieldsort()
    vx_data_table::Type_sort* vx_data_table::Type_table::fieldsort() {
      vx_data_table::Type_sort* output = this->vx_p_fieldsort;
      if (output == NULL) {
        output = vx_data_table::t_sort;
      }
    }

    // rowmap()
    vx_data_table::Type_rowmap* vx_data_table::Type_table::rowmap() {
      vx_data_table::Type_rowmap* output = this->vx_p_rowmap;
      if (output == NULL) {
        output = vx_data_table::t_rowmap;
      }
    }

    // rowfilter()
    vx_data_table::Type_filter* vx_data_table::Type_table::rowfilter() {
      vx_data_table::Type_filter* output = this->vx_p_rowfilter;
      if (output == NULL) {
        output = vx_data_table::t_filter;
      }
    }

    // rowsort()
    vx_data_table::Type_sort* vx_data_table::Type_table::rowsort() {
      vx_data_table::Type_sort* output = this->vx_p_rowsort;
      if (output == NULL) {
        output = vx_data_table::t_sort;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_data_table::Type_table::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
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
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_data_table::Type_table::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":id"] = this->id();
      output[":name"] = this->name();
      output[":fieldmap"] = this->fieldmap();
      output[":fieldsort"] = this->fieldsort();
      output[":rowmap"] = this->rowmap();
      output[":rowfilter"] = this->rowfilter();
      output[":rowsort"] = this->rowsort();
      return output;
    }

    template<typename... Args> vx_data_table::Type_table* vx_data_table::Type_table::vx_new(Args*... args) {return vx_data_table::e_table->vx_copy(args...);}
    template<typename... Args> vx_data_table::Type_table* vx_data_table::Type_table::vx_copy(Args*... args) {
      vx_data_table::Type_table* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_table* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_name = val->name();
      output->vx_p_fieldmap = val->fieldmap();
      output->vx_p_fieldsort = val->fieldsort();
      output->vx_p_rowmap = val->rowmap();
      output->vx_p_rowfilter = val->rowfilter();
      output->vx_p_rowsort = val->rowsort();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
      validkeys.insert(":name");
      validkeys.insert(":fieldmap");
      validkeys.insert(":fieldsort");
      validkeys.insert(":rowmap");
      validkeys.insert(":rowfilter");
      validkeys.insert(":rowsort");
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
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new table) - Invalid Key Type: " + vx_core::string_from_any(valsub));
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
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new table :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_name = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_name = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new table :name " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":fieldmap") {
            if (valsubtype == vx_data_table::t_fieldmap) {
              output->vx_p_fieldmap = vx_core::any_from_any(vx_data_table::t_fieldmap, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new table :fieldmap " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":fieldsort") {
            if (valsubtype == vx_data_table::t_sort) {
              output->vx_p_fieldsort = vx_core::any_from_any(vx_data_table::t_sort, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new table :fieldsort " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":rowmap") {
            if (valsubtype == vx_data_table::t_rowmap) {
              output->vx_p_rowmap = vx_core::any_from_any(vx_data_table::t_rowmap, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new table :rowmap " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":rowfilter") {
            if (valsubtype == vx_data_table::t_filter) {
              output->vx_p_rowfilter = vx_core::any_from_any(vx_data_table::t_filter, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new table :rowfilter " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":rowsort") {
            if (valsubtype == vx_data_table::t_sort) {
              output->vx_p_rowsort = vx_core::any_from_any(vx_data_table::t_sort, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new table :rowsort " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new table) - Invalid Key: " + key);
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

    vx_data_table::Type_table* vx_data_table::Type_table::vx_empty() {return vx_data_table::e_table;}
    vx_data_table::Type_table* vx_data_table::Type_table::vx_type() {return vx_data_table::t_table;}

    vx_core::Type_typedef* vx_data_table::Type_table::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
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
        vx_core::e_argmap // properties
      );
    }

  //}

//}
