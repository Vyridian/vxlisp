#include <map>
#include <memory>
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
    vx_core::Type_string vx_data_db::Class_db::dbid() {
      vx_core::Type_string output = this->vx_p_dbid;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any vx_data_db::Class_db::vx_get_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":dbid") {
        output = this->dbid();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_data_db::Class_db::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":dbid"] = this->dbid();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_db::Class_db::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_data_db::e_db->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_data_db::Class_db::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_db::Type_db output;
      vx_data_db::Class_db* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val->vx_msgblock(), vals);
      output->vx_p_dbid = val->dbid();
      std::set<std::string> validkeys;
      validkeys.insert(":dbid");
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new db) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":dbid") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_dbid = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new db :dbid " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new db) - Invalid Key: " + key);
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

    template <class T> std::shared_ptr<T> vx_data_db::Class_db::vx_empty(std::shared_ptr<T> val) {return vx_data_db::e_db;}
    template <class T> std::shared_ptr<T> vx_data_db::Class_db::vx_type(std::shared_ptr<T> val) {return vx_data_db::t_db;}

    vx_core::Type_typedef vx_data_db::Class_db::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
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

    vx_data_db::Type_db vx_data_db::e_db = std::make_shared<vx_data_db::Class_db>();
    vx_data_db::Type_db vx_data_db::t_db = std::make_shared<vx_data_db::Class_db>();
  //}

  /**
   * type: dbcell
   * Database Cell trait
   * (type dbcell)
   */
  //class Type_dbcell {
    // dbcellid()
    vx_core::Type_string vx_data_db::Class_dbcell::dbcellid() {
      vx_core::Type_string output = this->vx_p_dbcellid;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // dbcellmap()
    vx_data_db::Type_dbcellmap vx_data_db::Class_dbcell::dbcellmap() {
      vx_data_db::Type_dbcellmap output = this->vx_p_dbcellmap;
      if (output == NULL) {
        output = vx_data_db::t_dbcellmap;
      }
      return output;
    }

    // dbfieldmap()
    vx_data_db::Type_dbfieldmap vx_data_db::Class_dbcell::dbfieldmap() {
      vx_data_db::Type_dbfieldmap output = this->vx_p_dbfieldmap;
      if (output == NULL) {
        output = vx_data_db::t_dbfieldmap;
      }
      return output;
    }

    // dbparent()
    vx_data_db::Type_dbcell vx_data_db::Class_dbcell::dbparent() {
      vx_data_db::Type_dbcell output = this->vx_p_dbparent;
      if (output == NULL) {
        output = vx_data_db::t_dbcell;
      }
      return output;
    }

    // dbtable()
    vx_data_db::Type_dbtable vx_data_db::Class_dbcell::dbtable() {
      vx_data_db::Type_dbtable output = this->vx_p_dbtable;
      if (output == NULL) {
        output = vx_data_db::t_dbtable;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any vx_data_db::Class_dbcell::vx_get_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
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
    vx_core::vx_Type_mapany vx_data_db::Class_dbcell::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":dbcellid"] = this->dbcellid();
      output[":dbcellmap"] = this->dbcellmap();
      output[":dbfieldmap"] = this->dbfieldmap();
      output[":dbparent"] = this->dbparent();
      output[":dbtable"] = this->dbtable();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_db::Class_dbcell::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_data_db::e_dbcell->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_data_db::Class_dbcell::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_db::Type_dbcell output;
      vx_data_db::Class_dbcell* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val->vx_msgblock(), vals);
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new dbcell) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":dbcellid") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_dbcellid = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new dbcell :dbcellid " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":dbcellmap") {
            if (valsubtype == vx_data_db::t_dbcellmap) {
              output->vx_p_dbcellmap = vx_core::any_from_any(vx_data_db::t_dbcellmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new dbcell :dbcellmap " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":dbfieldmap") {
            if (valsubtype == vx_data_db::t_dbfieldmap) {
              output->vx_p_dbfieldmap = vx_core::any_from_any(vx_data_db::t_dbfieldmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new dbcell :dbfieldmap " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":dbparent") {
            if (valsubtype == vx_data_db::t_dbcell) {
              output->vx_p_dbparent = vx_core::any_from_any(vx_data_db::t_dbcell, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new dbcell :dbparent " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":dbtable") {
            if (valsubtype == vx_data_db::t_dbtable) {
              output->vx_p_dbtable = vx_core::any_from_any(vx_data_db::t_dbtable, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new dbcell :dbtable " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new dbcell) - Invalid Key: " + key);
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

    template <class T> std::shared_ptr<T> vx_data_db::Class_dbcell::vx_empty(std::shared_ptr<T> val) {return vx_data_db::e_dbcell;}
    template <class T> std::shared_ptr<T> vx_data_db::Class_dbcell::vx_type(std::shared_ptr<T> val) {return vx_data_db::t_dbcell;}

    vx_core::Type_typedef vx_data_db::Class_dbcell::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
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

    vx_data_db::Type_dbcell vx_data_db::e_dbcell = std::make_shared<vx_data_db::Class_dbcell>();
    vx_data_db::Type_dbcell vx_data_db::t_dbcell = std::make_shared<vx_data_db::Class_dbcell>();
  //}

  /**
   * type: dbcellmap
   * Database Cell Map
   * (type dbcellmap)
   */
  //class Type_dbcellmap {
    // vx_map()
    vx_core::vx_Type_mapany vx_data_db::Class_dbcellmap::vx_map() {
      return vx_core::map_from_map(vx_core::t_any, this->vx_p_map);
    }

    // vx_get_dbcell(key)
    vx_data_db::Type_dbcell vx_data_db::Class_dbcellmap::vx_get_dbcell(vx_core::Type_string key) {
      vx_data_db::Type_dbcell output = vx_data_db::e_dbcell;
      vx_data_db::Class_dbcellmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_data_db::Type_dbcell> mapval = map->vx_p_map;
      output = vx_core::any_from_map(mapval, skey, vx_data_db::e_dbcell);
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any vx_data_db::Class_dbcellmap::vx_get_any(vx_core::Type_string key) {
      return this->vx_get_dbcell(key);
    }

    // vx_mapdbcell()
    std::map<std::string, vx_data_db::Type_dbcell> vx_data_db::Class_dbcellmap::vx_mapdbcell() {return vx_p_map;}

    // vx_new_from_map(mapval)
    template <class T> std::shared_ptr<T>  vx_data_db::Class_dbcellmap::vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval) {
      vx_data_db::Type_dbcellmap output;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_data_db::Type_dbcell> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = vx_core::t_any->vx_type_from_any(val);
        if (valtype == vx_data_db::t_dbcell) {
          vx_data_db::Type_dbcell castval = vx_core::any_from_any(vx_data_db::t_dbcell, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(dbcellmap) Invalid Value: " + vx_core::string_from_any(val) + "");
          msgblock = vx_core::t_msgblock->vx_copy(vx_core::t_msgblock, {msgblock, msg});
        }
      }
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_db::Class_dbcellmap::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_data_db::e_dbcellmap->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_data_db::Class_dbcellmap::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_db::Type_dbcellmap output;
      vx_data_db::Class_dbcellmap* valmap = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_data_db::Type_dbcell> mapval;
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
          vx_data_db::Type_dbcell valany;
          if (valsubtype == vx_data_db::t_dbcell) {
            valany = vx_core::any_from_any(vx_data_db::t_dbcell, valsub);
          } else if (valsubtype == vx_data_db::t_dbcell) {
            valany = vx_core::any_from_any(vx_data_db::t_dbcell, valsub);
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

    template <class T> std::shared_ptr<T> vx_data_db::Class_dbcellmap::vx_empty(std::shared_ptr<T> val) {return vx_data_db::e_dbcellmap;}
    template <class T> std::shared_ptr<T> vx_data_db::Class_dbcellmap::vx_type(std::shared_ptr<T> val) {return vx_data_db::t_dbcellmap;}

    vx_core::Type_typedef vx_data_db::Class_dbcellmap::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/db", // pkgname
        "dbcellmap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_data_db::t_dbcell}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_data_db::Type_dbcellmap vx_data_db::e_dbcellmap = std::make_shared<vx_data_db::Class_dbcellmap>();
    vx_data_db::Type_dbcellmap vx_data_db::t_dbcellmap = std::make_shared<vx_data_db::Class_dbcellmap>();
  //}

  /**
   * type: dbfield
   * Database Field trait
   * (type dbfield)
   */
  //class Type_dbfield {
    // dbfieldid()
    vx_core::Type_string vx_data_db::Class_dbfield::dbfieldid() {
      vx_core::Type_string output = this->vx_p_dbfieldid;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // type()
    vx_core::Type_any vx_data_db::Class_dbfield::type() {
      vx_core::Type_any output = this->vx_p_type;
      if (output == NULL) {
        output = vx_core::t_any;
      }
      return output;
    }

    // value()
    vx_core::Type_any vx_data_db::Class_dbfield::value() {
      vx_core::Type_any output = this->vx_p_value;
      if (output == NULL) {
        output = vx_core::t_any;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any vx_data_db::Class_dbfield::vx_get_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
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
    vx_core::vx_Type_mapany vx_data_db::Class_dbfield::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":dbfieldid"] = this->dbfieldid();
      output[":type"] = this->type();
      output[":value"] = this->value();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_db::Class_dbfield::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_data_db::e_dbfield->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_data_db::Class_dbfield::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_db::Type_dbfield output;
      vx_data_db::Class_dbfield* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val->vx_msgblock(), vals);
      output->vx_p_dbfieldid = val->dbfieldid();
      output->vx_p_type = val->type();
      output->vx_p_value = val->value();
      std::set<std::string> validkeys;
      validkeys.insert(":dbfieldid");
      validkeys.insert(":type");
      validkeys.insert(":value");
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new dbfield) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":dbfieldid") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_dbfieldid = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new dbfield :dbfieldid " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":type") {
            if (valsubtype == vx_core::t_any) {
              output->vx_p_type = vx_core::any_from_any(vx_core::t_any, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new dbfield :type " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":value") {
            if (valsubtype == vx_core::t_any) {
              output->vx_p_value = vx_core::any_from_any(vx_core::t_any, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new dbfield :value " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new dbfield) - Invalid Key: " + key);
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

    template <class T> std::shared_ptr<T> vx_data_db::Class_dbfield::vx_empty(std::shared_ptr<T> val) {return vx_data_db::e_dbfield;}
    template <class T> std::shared_ptr<T> vx_data_db::Class_dbfield::vx_type(std::shared_ptr<T> val) {return vx_data_db::t_dbfield;}

    vx_core::Type_typedef vx_data_db::Class_dbfield::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
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

    vx_data_db::Type_dbfield vx_data_db::e_dbfield = std::make_shared<vx_data_db::Class_dbfield>();
    vx_data_db::Type_dbfield vx_data_db::t_dbfield = std::make_shared<vx_data_db::Class_dbfield>();
  //}

  /**
   * type: dbfieldmap
   * Database Field Map
   * (type dbfieldmap)
   */
  //class Type_dbfieldmap {
    // vx_map()
    vx_core::vx_Type_mapany vx_data_db::Class_dbfieldmap::vx_map() {
      return vx_core::map_from_map(vx_core::t_any, this->vx_p_map);
    }

    // vx_get_dbfield(key)
    vx_data_db::Type_dbfield vx_data_db::Class_dbfieldmap::vx_get_dbfield(vx_core::Type_string key) {
      vx_data_db::Type_dbfield output = vx_data_db::e_dbfield;
      vx_data_db::Class_dbfieldmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_data_db::Type_dbfield> mapval = map->vx_p_map;
      output = vx_core::any_from_map(mapval, skey, vx_data_db::e_dbfield);
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any vx_data_db::Class_dbfieldmap::vx_get_any(vx_core::Type_string key) {
      return this->vx_get_dbfield(key);
    }

    // vx_mapdbfield()
    std::map<std::string, vx_data_db::Type_dbfield> vx_data_db::Class_dbfieldmap::vx_mapdbfield() {return vx_p_map;}

    // vx_new_from_map(mapval)
    template <class T> std::shared_ptr<T>  vx_data_db::Class_dbfieldmap::vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval) {
      vx_data_db::Type_dbfieldmap output;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_data_db::Type_dbfield> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = vx_core::t_any->vx_type_from_any(val);
        if (valtype == vx_data_db::t_dbfield) {
          vx_data_db::Type_dbfield castval = vx_core::any_from_any(vx_data_db::t_dbfield, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(dbfieldmap) Invalid Value: " + vx_core::string_from_any(val) + "");
          msgblock = vx_core::t_msgblock->vx_copy(vx_core::t_msgblock, {msgblock, msg});
        }
      }
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_db::Class_dbfieldmap::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_data_db::e_dbfieldmap->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_data_db::Class_dbfieldmap::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_db::Type_dbfieldmap output;
      vx_data_db::Class_dbfieldmap* valmap = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_data_db::Type_dbfield> mapval;
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
          vx_data_db::Type_dbfield valany;
          if (valsubtype == vx_data_db::t_dbfield) {
            valany = vx_core::any_from_any(vx_data_db::t_dbfield, valsub);
          } else if (valsubtype == vx_data_db::t_dbfield) {
            valany = vx_core::any_from_any(vx_data_db::t_dbfield, valsub);
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

    template <class T> std::shared_ptr<T> vx_data_db::Class_dbfieldmap::vx_empty(std::shared_ptr<T> val) {return vx_data_db::e_dbfieldmap;}
    template <class T> std::shared_ptr<T> vx_data_db::Class_dbfieldmap::vx_type(std::shared_ptr<T> val) {return vx_data_db::t_dbfieldmap;}

    vx_core::Type_typedef vx_data_db::Class_dbfieldmap::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/db", // pkgname
        "dbfieldmap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_data_db::t_dbfield}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_data_db::Type_dbfieldmap vx_data_db::e_dbfieldmap = std::make_shared<vx_data_db::Class_dbfieldmap>();
    vx_data_db::Type_dbfieldmap vx_data_db::t_dbfieldmap = std::make_shared<vx_data_db::Class_dbfieldmap>();
  //}

  /**
   * type: dbtable
   * Database Table trait
   * (type dbtable)
   */
  //class Type_dbtable {
    // dbtableid()
    vx_core::Type_string vx_data_db::Class_dbtable::dbtableid() {
      vx_core::Type_string output = this->vx_p_dbtableid;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // db()
    vx_data_db::Type_db vx_data_db::Class_dbtable::db() {
      vx_data_db::Type_db output = this->vx_p_db;
      if (output == NULL) {
        output = vx_data_db::t_db;
      }
      return output;
    }

    // dbcellmap()
    vx_data_db::Type_dbcellmap vx_data_db::Class_dbtable::dbcellmap() {
      vx_data_db::Type_dbcellmap output = this->vx_p_dbcellmap;
      if (output == NULL) {
        output = vx_data_db::t_dbcellmap;
      }
      return output;
    }

    // dbfieldmap()
    vx_data_db::Type_dbfieldmap vx_data_db::Class_dbtable::dbfieldmap() {
      vx_data_db::Type_dbfieldmap output = this->vx_p_dbfieldmap;
      if (output == NULL) {
        output = vx_data_db::t_dbfieldmap;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any vx_data_db::Class_dbtable::vx_get_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
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
    vx_core::vx_Type_mapany vx_data_db::Class_dbtable::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":dbtableid"] = this->dbtableid();
      output[":db"] = this->db();
      output[":dbcellmap"] = this->dbcellmap();
      output[":dbfieldmap"] = this->dbfieldmap();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_db::Class_dbtable::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_data_db::e_dbtable->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_data_db::Class_dbtable::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_db::Type_dbtable output;
      vx_data_db::Class_dbtable* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val->vx_msgblock(), vals);
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new dbtable) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":dbtableid") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_dbtableid = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new dbtable :dbtableid " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":db") {
            if (valsubtype == vx_data_db::t_db) {
              output->vx_p_db = vx_core::any_from_any(vx_data_db::t_db, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new dbtable :db " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":dbcellmap") {
            if (valsubtype == vx_data_db::t_dbcellmap) {
              output->vx_p_dbcellmap = vx_core::any_from_any(vx_data_db::t_dbcellmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new dbtable :dbcellmap " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":dbfieldmap") {
            if (valsubtype == vx_data_db::t_dbfieldmap) {
              output->vx_p_dbfieldmap = vx_core::any_from_any(vx_data_db::t_dbfieldmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new dbtable :dbfieldmap " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new dbtable) - Invalid Key: " + key);
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

    template <class T> std::shared_ptr<T> vx_data_db::Class_dbtable::vx_empty(std::shared_ptr<T> val) {return vx_data_db::e_dbtable;}
    template <class T> std::shared_ptr<T> vx_data_db::Class_dbtable::vx_type(std::shared_ptr<T> val) {return vx_data_db::t_dbtable;}

    vx_core::Type_typedef vx_data_db::Class_dbtable::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
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

    vx_data_db::Type_dbtable vx_data_db::e_dbtable = std::make_shared<vx_data_db::Class_dbtable>();
    vx_data_db::Type_dbtable vx_data_db::t_dbtable = std::make_shared<vx_data_db::Class_dbtable>();
  //}

//}
