#include <any>
#include <map>
#include <set>
#include <string>
#include "../../vx/core.hpp"
#include "vx/data/db.hpp"

//namespace vx_data_db {

  /**
   * type: db
   * Database trait
   * (type db)
   */
  //class Type_db {
    // dbid()
    vx_core::Type_string* vx_data_db::Type_db::dbid() {
      vx_core::Type_string* output = this->vx_p_dbid;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_data_db::Type_db::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":dbid") {
        output = this->dbid();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_data_db::Type_db::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":dbid"] = this->dbid();
      return output;
    }

    template<typename... Args> vx_data_db::Type_db* vx_data_db::Type_db::vx_new(Args*... args) {return vx_data_db::e_db->vx_copy(args...);}
    template<typename... Args> vx_data_db::Type_db* vx_data_db::Type_db::vx_copy(Args*... args) {
      vx_data_db::Type_db* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_db* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_dbid = val->dbid();
      std::set<std::string> validkeys;
      validkeys.insert(":dbid");
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
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new db) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":dbid") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_dbid = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_dbid = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new db :dbid " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new db) - Invalid Key: " + key);
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

    vx_data_db::Type_db* vx_data_db::Type_db::vx_empty() {return vx_data_db::e_db;}
    vx_data_db::Type_db* vx_data_db::Type_db::vx_type() {return vx_data_db::t_db;}

    vx_core::Type_typedef* vx_data_db::Type_db::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/data/db", // pkgname
        "db", // name
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
   * type: dbcell
   * Database Cell trait
   * (type dbcell)
   */
  //class Type_dbcell {
    // dbcellid()
    vx_core::Type_string* vx_data_db::Type_dbcell::dbcellid() {
      vx_core::Type_string* output = this->vx_p_dbcellid;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // dbcellmap()
    vx_data_db::Type_dbcellmap* vx_data_db::Type_dbcell::dbcellmap() {
      vx_data_db::Type_dbcellmap* output = this->vx_p_dbcellmap;
      if (output == NULL) {
        output = vx_data_db::t_dbcellmap;
      }
    }

    // dbfieldmap()
    vx_data_db::Type_dbfieldmap* vx_data_db::Type_dbcell::dbfieldmap() {
      vx_data_db::Type_dbfieldmap* output = this->vx_p_dbfieldmap;
      if (output == NULL) {
        output = vx_data_db::t_dbfieldmap;
      }
    }

    // dbparent()
    vx_data_db::Type_dbcell* vx_data_db::Type_dbcell::dbparent() {
      vx_data_db::Type_dbcell* output = this->vx_p_dbparent;
      if (output == NULL) {
        output = vx_data_db::t_dbcell;
      }
    }

    // dbtable()
    vx_data_db::Type_dbtable* vx_data_db::Type_dbcell::dbtable() {
      vx_data_db::Type_dbtable* output = this->vx_p_dbtable;
      if (output == NULL) {
        output = vx_data_db::t_dbtable;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_data_db::Type_dbcell::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":dbcellid") {
        output = this->dbcellid();
      } else if (skey == ":dbcellmap") {
        output = this->dbcellmap();
      } else if (skey == ":dbfieldmap") {
        output = this->dbfieldmap();
      } else if (skey == ":dbparent") {
        output = this->dbparent();
      } else if (skey == ":dbtable") {
        output = this->dbtable();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_data_db::Type_dbcell::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":dbcellid"] = this->dbcellid();
      output[":dbcellmap"] = this->dbcellmap();
      output[":dbfieldmap"] = this->dbfieldmap();
      output[":dbparent"] = this->dbparent();
      output[":dbtable"] = this->dbtable();
      return output;
    }

    template<typename... Args> vx_data_db::Type_dbcell* vx_data_db::Type_dbcell::vx_new(Args*... args) {return vx_data_db::e_dbcell->vx_copy(args...);}
    template<typename... Args> vx_data_db::Type_dbcell* vx_data_db::Type_dbcell::vx_copy(Args*... args) {
      vx_data_db::Type_dbcell* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_dbcell* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_dbcellid = val->dbcellid();
      output->vx_p_dbcellmap = val->dbcellmap();
      output->vx_p_dbfieldmap = val->dbfieldmap();
      output->vx_p_dbparent = val->dbparent();
      output->vx_p_dbtable = val->dbtable();
      std::set<std::string> validkeys;
      validkeys.insert(":dbcellid");
      validkeys.insert(":dbcellmap");
      validkeys.insert(":dbfieldmap");
      validkeys.insert(":dbparent");
      validkeys.insert(":dbtable");
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
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new dbcell) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":dbcellid") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_dbcellid = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_dbcellid = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new dbcell :dbcellid " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":dbcellmap") {
            if (valsubtype == vx_data_db::t_dbcellmap) {
              output->vx_p_dbcellmap = vx_core::any_from_any(vx_data_db::t_dbcellmap, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new dbcell :dbcellmap " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":dbfieldmap") {
            if (valsubtype == vx_data_db::t_dbfieldmap) {
              output->vx_p_dbfieldmap = vx_core::any_from_any(vx_data_db::t_dbfieldmap, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new dbcell :dbfieldmap " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":dbparent") {
            if (valsubtype == vx_data_db::t_dbcell) {
              output->vx_p_dbparent = vx_core::any_from_any(vx_data_db::t_dbcell, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new dbcell :dbparent " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":dbtable") {
            if (valsubtype == vx_data_db::t_dbtable) {
              output->vx_p_dbtable = vx_core::any_from_any(vx_data_db::t_dbtable, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new dbcell :dbtable " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new dbcell) - Invalid Key: " + key);
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

    vx_data_db::Type_dbcell* vx_data_db::Type_dbcell::vx_empty() {return vx_data_db::e_dbcell;}
    vx_data_db::Type_dbcell* vx_data_db::Type_dbcell::vx_type() {return vx_data_db::t_dbcell;}

    vx_core::Type_typedef* vx_data_db::Type_dbcell::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/data/db", // pkgname
        "dbcell", // name
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
   * type: dbcellmap
   * Database Cell Map
   * (type dbcellmap)
   */
  //class Type_dbcellmap {
    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_data_db::Type_dbcellmap::vx_map() {
      return vx_core::map_from_map(vx_core::t_any, this->vx_p_map);
    }

    // vx_dbcell(key)
    vx_data_db::Type_dbcell* vx_data_db::Type_dbcellmap::vx_dbcell(vx_core::Type_string* key) {
      vx_data_db::Type_dbcell* output = vx_data_db::e_dbcell;
      vx_data_db::Type_dbcellmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_data_db::Type_dbcell*> mapval = map->vx_p_map;
      output = vx_core::any_from_map(mapval, skey, vx_data_db::e_dbcell);
      return output;
    }

    // vx_any(key)
    vx_core::Type_any* vx_data_db::Type_dbcellmap::vx_any(vx_core::Type_string* key) {
      return this->vx_dbcell(key);
    }

    // vx_mapdbcell()
    std::map<std::string, vx_data_db::Type_dbcell*> vx_data_db::Type_dbcellmap::vx_mapdbcell() {return vx_p_map;}

    // vx_new_from_map(mapval)
    vx_data_db::Type_dbcellmap* vx_data_db::Type_dbcellmap::vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval) {
      vx_data_db::Type_dbcellmap* output;
      vx_core::Type_msgblock* msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_data_db::Type_dbcell*> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any* val = iter.second;
        vx_core::Type_any* valtype = vx_core::t_any->vx_type_from_any(val);
        if (valtype == vx_data_db::t_dbcell) {
          vx_data_db::Type_dbcell* castval = vx_core::any_from_any(vx_data_db::t_dbcell, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(dbcellmap) Invalid Value: " + vx_core::string_from_any(val) + "");
          msgblock = vx_core::t_msgblock->vx_copy(msgblock, msg);
        }
      }
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template<typename... Args> vx_data_db::Type_dbcellmap* vx_data_db::Type_dbcellmap::vx_new(Args*... args) {return vx_data_db::e_dbcellmap->vx_copy(args...);}
    template<typename... Args> vx_data_db::Type_dbcellmap* vx_data_db::Type_dbcellmap::vx_copy(Args*... args) {
      vx_data_db::Type_dbcellmap* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_data_db::Type_dbcellmap* valmap = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(valmap, vals);
      std::map<std::string, vx_data_db::Type_dbcell*> mapval;
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
          vx_data_db::Type_dbcell* valany;
          if (valsubtype == vx_data_db::t_dbcell) {
            valany = vx_core::any_from_any(vx_data_db::t_dbcell, valsub);
          } else if (valsubtype == vx_data_db::t_dbcell) {
            valany = vx_core::any_from_any(vx_data_db::t_dbcell, valsub);
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

    vx_data_db::Type_dbcellmap* vx_data_db::Type_dbcellmap::vx_empty() {return vx_data_db::e_dbcellmap;}
    vx_data_db::Type_dbcellmap* vx_data_db::Type_dbcellmap::vx_type() {return vx_data_db::t_dbcellmap;}

    vx_core::Type_typedef* vx_data_db::Type_dbcellmap::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/data/db", // pkgname
        "dbcellmap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_data_db::t_dbcell), // allowtypes
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
   * type: dbfield
   * Database Field trait
   * (type dbfield)
   */
  //class Type_dbfield {
    // dbfieldid()
    vx_core::Type_string* vx_data_db::Type_dbfield::dbfieldid() {
      vx_core::Type_string* output = this->vx_p_dbfieldid;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // type()
    vx_core::Type_any* vx_data_db::Type_dbfield::type() {
      vx_core::Type_any* output = this->vx_p_type;
      if (output == NULL) {
        output = vx_core::t_any;
      }
    }

    // value()
    vx_core::Type_any* vx_data_db::Type_dbfield::value() {
      vx_core::Type_any* output = this->vx_p_value;
      if (output == NULL) {
        output = vx_core::t_any;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_data_db::Type_dbfield::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":dbfieldid") {
        output = this->dbfieldid();
      } else if (skey == ":type") {
        output = this->type();
      } else if (skey == ":value") {
        output = this->value();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_data_db::Type_dbfield::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":dbfieldid"] = this->dbfieldid();
      output[":type"] = this->type();
      output[":value"] = this->value();
      return output;
    }

    template<typename... Args> vx_data_db::Type_dbfield* vx_data_db::Type_dbfield::vx_new(Args*... args) {return vx_data_db::e_dbfield->vx_copy(args...);}
    template<typename... Args> vx_data_db::Type_dbfield* vx_data_db::Type_dbfield::vx_copy(Args*... args) {
      vx_data_db::Type_dbfield* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_dbfield* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_dbfieldid = val->dbfieldid();
      output->vx_p_type = val->type();
      output->vx_p_value = val->value();
      std::set<std::string> validkeys;
      validkeys.insert(":dbfieldid");
      validkeys.insert(":type");
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
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new dbfield) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":dbfieldid") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_dbfieldid = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_dbfieldid = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new dbfield :dbfieldid " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":type") {
            if (valsubtype == vx_core::t_any) {
              output->vx_p_type = vx_core::any_from_any(vx_core::t_any, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new dbfield :type " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":value") {
            if (valsubtype == vx_core::t_any) {
              output->vx_p_value = vx_core::any_from_any(vx_core::t_any, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new dbfield :value " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new dbfield) - Invalid Key: " + key);
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

    vx_data_db::Type_dbfield* vx_data_db::Type_dbfield::vx_empty() {return vx_data_db::e_dbfield;}
    vx_data_db::Type_dbfield* vx_data_db::Type_dbfield::vx_type() {return vx_data_db::t_dbfield;}

    vx_core::Type_typedef* vx_data_db::Type_dbfield::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/data/db", // pkgname
        "dbfield", // name
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
   * type: dbfieldmap
   * Database Field Map
   * (type dbfieldmap)
   */
  //class Type_dbfieldmap {
    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_data_db::Type_dbfieldmap::vx_map() {
      return vx_core::map_from_map(vx_core::t_any, this->vx_p_map);
    }

    // vx_dbfield(key)
    vx_data_db::Type_dbfield* vx_data_db::Type_dbfieldmap::vx_dbfield(vx_core::Type_string* key) {
      vx_data_db::Type_dbfield* output = vx_data_db::e_dbfield;
      vx_data_db::Type_dbfieldmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_data_db::Type_dbfield*> mapval = map->vx_p_map;
      output = vx_core::any_from_map(mapval, skey, vx_data_db::e_dbfield);
      return output;
    }

    // vx_any(key)
    vx_core::Type_any* vx_data_db::Type_dbfieldmap::vx_any(vx_core::Type_string* key) {
      return this->vx_dbfield(key);
    }

    // vx_mapdbfield()
    std::map<std::string, vx_data_db::Type_dbfield*> vx_data_db::Type_dbfieldmap::vx_mapdbfield() {return vx_p_map;}

    // vx_new_from_map(mapval)
    vx_data_db::Type_dbfieldmap* vx_data_db::Type_dbfieldmap::vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval) {
      vx_data_db::Type_dbfieldmap* output;
      vx_core::Type_msgblock* msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_data_db::Type_dbfield*> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any* val = iter.second;
        vx_core::Type_any* valtype = vx_core::t_any->vx_type_from_any(val);
        if (valtype == vx_data_db::t_dbfield) {
          vx_data_db::Type_dbfield* castval = vx_core::any_from_any(vx_data_db::t_dbfield, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(dbfieldmap) Invalid Value: " + vx_core::string_from_any(val) + "");
          msgblock = vx_core::t_msgblock->vx_copy(msgblock, msg);
        }
      }
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template<typename... Args> vx_data_db::Type_dbfieldmap* vx_data_db::Type_dbfieldmap::vx_new(Args*... args) {return vx_data_db::e_dbfieldmap->vx_copy(args...);}
    template<typename... Args> vx_data_db::Type_dbfieldmap* vx_data_db::Type_dbfieldmap::vx_copy(Args*... args) {
      vx_data_db::Type_dbfieldmap* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_data_db::Type_dbfieldmap* valmap = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(valmap, vals);
      std::map<std::string, vx_data_db::Type_dbfield*> mapval;
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
          vx_data_db::Type_dbfield* valany;
          if (valsubtype == vx_data_db::t_dbfield) {
            valany = vx_core::any_from_any(vx_data_db::t_dbfield, valsub);
          } else if (valsubtype == vx_data_db::t_dbfield) {
            valany = vx_core::any_from_any(vx_data_db::t_dbfield, valsub);
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

    vx_data_db::Type_dbfieldmap* vx_data_db::Type_dbfieldmap::vx_empty() {return vx_data_db::e_dbfieldmap;}
    vx_data_db::Type_dbfieldmap* vx_data_db::Type_dbfieldmap::vx_type() {return vx_data_db::t_dbfieldmap;}

    vx_core::Type_typedef* vx_data_db::Type_dbfieldmap::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/data/db", // pkgname
        "dbfieldmap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_data_db::t_dbfield), // allowtypes
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
   * type: dbtable
   * Database Table trait
   * (type dbtable)
   */
  //class Type_dbtable {
    // dbtableid()
    vx_core::Type_string* vx_data_db::Type_dbtable::dbtableid() {
      vx_core::Type_string* output = this->vx_p_dbtableid;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // db()
    vx_data_db::Type_db* vx_data_db::Type_dbtable::db() {
      vx_data_db::Type_db* output = this->vx_p_db;
      if (output == NULL) {
        output = vx_data_db::t_db;
      }
    }

    // dbcellmap()
    vx_data_db::Type_dbcellmap* vx_data_db::Type_dbtable::dbcellmap() {
      vx_data_db::Type_dbcellmap* output = this->vx_p_dbcellmap;
      if (output == NULL) {
        output = vx_data_db::t_dbcellmap;
      }
    }

    // dbfieldmap()
    vx_data_db::Type_dbfieldmap* vx_data_db::Type_dbtable::dbfieldmap() {
      vx_data_db::Type_dbfieldmap* output = this->vx_p_dbfieldmap;
      if (output == NULL) {
        output = vx_data_db::t_dbfieldmap;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_data_db::Type_dbtable::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":dbtableid") {
        output = this->dbtableid();
      } else if (skey == ":db") {
        output = this->db();
      } else if (skey == ":dbcellmap") {
        output = this->dbcellmap();
      } else if (skey == ":dbfieldmap") {
        output = this->dbfieldmap();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_data_db::Type_dbtable::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":dbtableid"] = this->dbtableid();
      output[":db"] = this->db();
      output[":dbcellmap"] = this->dbcellmap();
      output[":dbfieldmap"] = this->dbfieldmap();
      return output;
    }

    template<typename... Args> vx_data_db::Type_dbtable* vx_data_db::Type_dbtable::vx_new(Args*... args) {return vx_data_db::e_dbtable->vx_copy(args...);}
    template<typename... Args> vx_data_db::Type_dbtable* vx_data_db::Type_dbtable::vx_copy(Args*... args) {
      vx_data_db::Type_dbtable* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_dbtable* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_dbtableid = val->dbtableid();
      output->vx_p_db = val->db();
      output->vx_p_dbcellmap = val->dbcellmap();
      output->vx_p_dbfieldmap = val->dbfieldmap();
      std::set<std::string> validkeys;
      validkeys.insert(":dbtableid");
      validkeys.insert(":db");
      validkeys.insert(":dbcellmap");
      validkeys.insert(":dbfieldmap");
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
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new dbtable) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":dbtableid") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_dbtableid = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_dbtableid = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new dbtable :dbtableid " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":db") {
            if (valsubtype == vx_data_db::t_db) {
              output->vx_p_db = vx_core::any_from_any(vx_data_db::t_db, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new dbtable :db " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":dbcellmap") {
            if (valsubtype == vx_data_db::t_dbcellmap) {
              output->vx_p_dbcellmap = vx_core::any_from_any(vx_data_db::t_dbcellmap, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new dbtable :dbcellmap " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":dbfieldmap") {
            if (valsubtype == vx_data_db::t_dbfieldmap) {
              output->vx_p_dbfieldmap = vx_core::any_from_any(vx_data_db::t_dbfieldmap, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new dbtable :dbfieldmap " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new dbtable) - Invalid Key: " + key);
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

    vx_data_db::Type_dbtable* vx_data_db::Type_dbtable::vx_empty() {return vx_data_db::e_dbtable;}
    vx_data_db::Type_dbtable* vx_data_db::Type_dbtable::vx_type() {return vx_data_db::t_dbtable;}

    vx_core::Type_typedef* vx_data_db::Type_dbtable::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/data/db", // pkgname
        "dbtable", // name
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
