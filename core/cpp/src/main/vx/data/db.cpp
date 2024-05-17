#include <map>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "db.hpp"

namespace vx_data_db {



  // (type db)
  // class Class_db {
    Abstract_db::~Abstract_db() {}

    Class_db::Class_db() : Abstract_db::Abstract_db() {
      vx_core::refcount += 1;
    }

    Class_db::~Class_db() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_dbid
      });
    }

    // dbid()
    vx_core::Type_string Class_db::dbid() const {
      vx_core::Type_string output = this->vx_p_dbid;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_db::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":dbid") {
        output = this->dbid();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_db::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":dbid"] = this->dbid();
      return output;
    }

    vx_core::Type_any Class_db::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_db::e_db, vals);
    }

    vx_core::Type_any Class_db::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_db::Type_db output = vx_data_db::e_db;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_db::Type_db val = vx_core::vx_any_from_any(vx_data_db::t_db, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_dbid = val->dbid();
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
          } else if (testkey == ":dbid") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new db) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":dbid") {
            if (vx_p_dbid == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_dbid = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new db :dbid " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new db) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_db::Class_db();
        if (output->vx_p_dbid != vx_p_dbid) {
          if (output->vx_p_dbid) {
            vx_core::vx_release_one(output->vx_p_dbid);
          }
          output->vx_p_dbid = vx_p_dbid;
          vx_core::vx_reserve(vx_p_dbid);
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

    vx_core::Type_msgblock Class_db::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_db::Class_db::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_db::vx_empty() const {return vx_data_db::e_db;}
    vx_core::Type_any Class_db::vx_type() const {return vx_data_db::t_db;}

    vx_core::Type_typedef Class_db::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
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
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "dbid", // name
            vx_core::t_string // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_db::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type dbcell)
  // class Class_dbcell {
    Abstract_dbcell::~Abstract_dbcell() {}

    Class_dbcell::Class_dbcell() : Abstract_dbcell::Abstract_dbcell() {
      vx_core::refcount += 1;
    }

    Class_dbcell::~Class_dbcell() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_dbcellid,
        this->vx_p_dbcellmap,
        this->vx_p_dbfieldmap,
        this->vx_p_dbparent,
        this->vx_p_dbtable
      });
    }

    // dbcellid()
    vx_core::Type_string Class_dbcell::dbcellid() const {
      vx_core::Type_string output = this->vx_p_dbcellid;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // dbcellmap()
    vx_data_db::Type_dbcellmap Class_dbcell::dbcellmap() const {
      vx_data_db::Type_dbcellmap output = this->vx_p_dbcellmap;
      if (!output) {
        output = vx_data_db::e_dbcellmap;
      }
      return output;
    }

    // dbfieldmap()
    vx_data_db::Type_dbfieldmap Class_dbcell::dbfieldmap() const {
      vx_data_db::Type_dbfieldmap output = this->vx_p_dbfieldmap;
      if (!output) {
        output = vx_data_db::e_dbfieldmap;
      }
      return output;
    }

    // dbparent()
    vx_data_db::Type_dbcell Class_dbcell::dbparent() const {
      vx_data_db::Type_dbcell output = this->vx_p_dbparent;
      if (!output) {
        output = vx_data_db::e_dbcell;
      }
      return output;
    }

    // dbtable()
    vx_data_db::Type_dbtable Class_dbcell::dbtable() const {
      vx_data_db::Type_dbtable output = this->vx_p_dbtable;
      if (!output) {
        output = vx_data_db::e_dbtable;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_dbcell::vx_get_any(vx_core::Type_string key) const {
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
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_dbcell::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":dbcellid"] = this->dbcellid();
      output[":dbcellmap"] = this->dbcellmap();
      output[":dbfieldmap"] = this->dbfieldmap();
      output[":dbparent"] = this->dbparent();
      output[":dbtable"] = this->dbtable();
      return output;
    }

    vx_core::Type_any Class_dbcell::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_db::e_dbcell, vals);
    }

    vx_core::Type_any Class_dbcell::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_db::Type_dbcell output = vx_data_db::e_dbcell;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_db::Type_dbcell val = vx_core::vx_any_from_any(vx_data_db::t_dbcell, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_dbcellid = val->dbcellid();
      vx_data_db::Type_dbcellmap vx_p_dbcellmap = val->dbcellmap();
      vx_data_db::Type_dbfieldmap vx_p_dbfieldmap = val->dbfieldmap();
      vx_data_db::Type_dbcell vx_p_dbparent = val->dbparent();
      vx_data_db::Type_dbtable vx_p_dbtable = val->dbtable();
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
          } else if (testkey == ":dbcellid") {
            key = testkey;
          } else if (testkey == ":dbcellmap") {
            key = testkey;
          } else if (testkey == ":dbfieldmap") {
            key = testkey;
          } else if (testkey == ":dbparent") {
            key = testkey;
          } else if (testkey == ":dbtable") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbcell) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":dbcellid") {
            if (vx_p_dbcellid == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_dbcellid = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbcell :dbcellid " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":dbcellmap") {
            if (vx_p_dbcellmap == valsub) {
            } else if (valsubtype == vx_data_db::t_dbcellmap) {
              ischanged = true;
              vx_p_dbcellmap = vx_core::vx_any_from_any(vx_data_db::t_dbcellmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbcell :dbcellmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":dbfieldmap") {
            if (vx_p_dbfieldmap == valsub) {
            } else if (valsubtype == vx_data_db::t_dbfieldmap) {
              ischanged = true;
              vx_p_dbfieldmap = vx_core::vx_any_from_any(vx_data_db::t_dbfieldmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbcell :dbfieldmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":dbparent") {
            if (vx_p_dbparent == valsub) {
            } else if (valsubtype == vx_data_db::t_dbcell) {
              ischanged = true;
              vx_p_dbparent = vx_core::vx_any_from_any(vx_data_db::t_dbcell, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbcell :dbparent " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":dbtable") {
            if (vx_p_dbtable == valsub) {
            } else if (valsubtype == vx_data_db::t_dbtable) {
              ischanged = true;
              vx_p_dbtable = vx_core::vx_any_from_any(vx_data_db::t_dbtable, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbcell :dbtable " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbcell) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_db::Class_dbcell();
        if (output->vx_p_dbcellid != vx_p_dbcellid) {
          if (output->vx_p_dbcellid) {
            vx_core::vx_release_one(output->vx_p_dbcellid);
          }
          output->vx_p_dbcellid = vx_p_dbcellid;
          vx_core::vx_reserve(vx_p_dbcellid);
        }
        if (output->vx_p_dbcellmap != vx_p_dbcellmap) {
          if (output->vx_p_dbcellmap) {
            vx_core::vx_release_one(output->vx_p_dbcellmap);
          }
          output->vx_p_dbcellmap = vx_p_dbcellmap;
          vx_core::vx_reserve(vx_p_dbcellmap);
        }
        if (output->vx_p_dbfieldmap != vx_p_dbfieldmap) {
          if (output->vx_p_dbfieldmap) {
            vx_core::vx_release_one(output->vx_p_dbfieldmap);
          }
          output->vx_p_dbfieldmap = vx_p_dbfieldmap;
          vx_core::vx_reserve(vx_p_dbfieldmap);
        }
        if (output->vx_p_dbparent != vx_p_dbparent) {
          if (output->vx_p_dbparent) {
            vx_core::vx_release_one(output->vx_p_dbparent);
          }
          output->vx_p_dbparent = vx_p_dbparent;
          vx_core::vx_reserve(vx_p_dbparent);
        }
        if (output->vx_p_dbtable != vx_p_dbtable) {
          if (output->vx_p_dbtable) {
            vx_core::vx_release_one(output->vx_p_dbtable);
          }
          output->vx_p_dbtable = vx_p_dbtable;
          vx_core::vx_reserve(vx_p_dbtable);
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

    vx_core::Type_msgblock Class_dbcell::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_db::Class_dbcell::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_dbcell::vx_empty() const {return vx_data_db::e_dbcell;}
    vx_core::Type_any Class_dbcell::vx_type() const {return vx_data_db::t_dbcell;}

    vx_core::Type_typedef Class_dbcell::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
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
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "dbcellid", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "dbcellmap", // name
            vx_data_db::t_dbcellmap // type
          ),
          vx_core::vx_new_arg(
            "dbfieldmap", // name
            vx_data_db::t_dbfieldmap // type
          ),
          vx_core::vx_new_arg(
            "dbparent", // name
            vx_data_db::t_dbcell // type
          ),
          vx_core::vx_new_arg(
            "dbtable", // name
            vx_data_db::t_dbtable // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_dbcell::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type dbcellmap)
  // class Class_dbcellmap {
    Abstract_dbcellmap::~Abstract_dbcellmap() {}

    Class_dbcellmap::Class_dbcellmap() : Abstract_dbcellmap::Abstract_dbcellmap() {
      vx_core::refcount += 1;
    }

    Class_dbcellmap::~Class_dbcellmap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (auto const& [key, val] : this->vx_p_map) {
        vx_core::vx_release_one(val);
      }
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_dbcellmap::vx_map() const {
      vx_core::vx_Type_mapany output = vx_core::vx_map_from_map(vx_core::t_any, this->vx_p_map);
      return output;
    }

    // vx_set(map, string, any)
    vx_core::Type_boolean Class_dbcellmap::vx_set(vx_core::Type_string name, vx_core::Type_any value) {
      vx_core::Type_boolean output = vx_core::c_false;
      vx_core::Type_any valtype = value->vx_type();
      if (valtype == vx_data_db::t_dbcell) {
        vx_data_db::Type_dbcell newval = vx_core::vx_any_from_any(vx_data_db::t_dbcell, value);
        std::string key = name->vx_string();
        if (vx_core::vx_boolean_from_string_starts(key, ":")) {
          key = key.substr(1, key.length());
        }
        vx_data_db::Type_dbcell oldval = this->vx_p_map[key];
        if (oldval != newval) {
          if (oldval) {
            vx_core::vx_release_one(oldval);
          }
          if (newval == vx_data_db::e_dbcell) {
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
    // vx_get_dbcell(key)
    vx_data_db::Type_dbcell Class_dbcellmap::vx_get_dbcell(vx_core::Type_string key) const {
      vx_data_db::Type_dbcell output = vx_data_db::e_dbcell;
      const vx_data_db::Class_dbcellmap* map = this;
      std::string skey = key->vx_string();
      if (vx_core::vx_boolean_from_string_starts(skey, ":")) {
        skey = vx_core::vx_string_from_string_start(skey, 2);
      }
      std::map<std::string, vx_data_db::Type_dbcell> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_data_db::e_dbcell);
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_dbcellmap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_dbcell(key);
    }

    // vx_mapdbcell()
    std::map<std::string, vx_data_db::Type_dbcell> Class_dbcellmap::vx_mapdbcell() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_dbcellmap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_data_db::Type_dbcellmap output = vx_data_db::e_dbcellmap;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_data_db::Type_dbcell> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_data_db::t_dbcell) {
          vx_data_db::Type_dbcell castval = vx_core::vx_any_from_any(vx_data_db::t_dbcell, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(dbcellmap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((map.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_db::Class_dbcellmap();
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

    vx_core::Type_any Class_dbcellmap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_db::e_dbcellmap, vals);
    }

    vx_core::Type_any Class_dbcellmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_db::Type_dbcellmap output = vx_data_db::e_dbcellmap;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_db::Type_dbcellmap valmap = vx_core::vx_any_from_any(vx_data_db::t_dbcellmap, copyval);
      output = valmap;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_data_db::Type_dbcell> mapval = valmap->vx_mapdbcell();
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
          vx_data_db::Type_dbcell valany = NULL;
          if (valsubtype == vx_data_db::t_dbcell) {
            valany = vx_core::vx_any_from_any(vx_data_db::t_dbcell, valsub);
          } else if (valsubtype == vx_data_db::t_dbcell) {
            valany = vx_core::vx_any_from_any(vx_data_db::t_dbcell, valsub);
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
        output = new vx_data_db::Class_dbcellmap();
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

    vx_core::Type_msgblock Class_dbcellmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_db::Class_dbcellmap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_dbcellmap::vx_empty() const {return vx_data_db::e_dbcellmap;}
    vx_core::Type_any Class_dbcellmap::vx_type() const {return vx_data_db::t_dbcellmap;}

    vx_core::Type_typedef Class_dbcellmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/db", // pkgname
        "dbcellmap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_data_db::t_dbcell}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_dbcellmap::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type dbfield)
  // class Class_dbfield {
    Abstract_dbfield::~Abstract_dbfield() {}

    Class_dbfield::Class_dbfield() : Abstract_dbfield::Abstract_dbfield() {
      vx_core::refcount += 1;
    }

    Class_dbfield::~Class_dbfield() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_dbfieldid,
        this->vx_p_type,
        this->vx_p_value
      });
    }

    // dbfieldid()
    vx_core::Type_string Class_dbfield::dbfieldid() const {
      vx_core::Type_string output = this->vx_p_dbfieldid;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // type()
    vx_core::Type_any Class_dbfield::type() const {
      vx_core::Type_any output = this->vx_p_type;
      if (!output) {
        output = vx_core::e_any;
      }
      return output;
    }

    // value()
    vx_core::Type_any Class_dbfield::value() const {
      vx_core::Type_any output = this->vx_p_value;
      if (!output) {
        output = vx_core::e_any;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_dbfield::vx_get_any(vx_core::Type_string key) const {
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
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_dbfield::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":dbfieldid"] = this->dbfieldid();
      output[":type"] = this->type();
      output[":value"] = this->value();
      return output;
    }

    vx_core::Type_any Class_dbfield::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_db::e_dbfield, vals);
    }

    vx_core::Type_any Class_dbfield::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_db::Type_dbfield output = vx_data_db::e_dbfield;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_db::Type_dbfield val = vx_core::vx_any_from_any(vx_data_db::t_dbfield, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_dbfieldid = val->dbfieldid();
      vx_core::Type_any vx_p_type = val->type();
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
          } else if (testkey == ":dbfieldid") {
            key = testkey;
          } else if (testkey == ":type") {
            key = testkey;
          } else if (testkey == ":value") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbfield) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":dbfieldid") {
            if (vx_p_dbfieldid == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_dbfieldid = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbfield :dbfieldid " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":type") {
            if (vx_p_type != valsub) {
              ischanged = true;
              vx_p_type = valsub;
            }
          } else if (key == ":value") {
            if (vx_p_value != valsub) {
              ischanged = true;
              vx_p_value = valsub;
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbfield) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_db::Class_dbfield();
        if (output->vx_p_dbfieldid != vx_p_dbfieldid) {
          if (output->vx_p_dbfieldid) {
            vx_core::vx_release_one(output->vx_p_dbfieldid);
          }
          output->vx_p_dbfieldid = vx_p_dbfieldid;
          vx_core::vx_reserve(vx_p_dbfieldid);
        }
        if (output->vx_p_type != vx_p_type) {
          if (output->vx_p_type) {
            vx_core::vx_release_one(output->vx_p_type);
          }
          output->vx_p_type = vx_p_type;
          vx_core::vx_reserve(vx_p_type);
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

    vx_core::Type_msgblock Class_dbfield::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_db::Class_dbfield::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_dbfield::vx_empty() const {return vx_data_db::e_dbfield;}
    vx_core::Type_any Class_dbfield::vx_type() const {return vx_data_db::t_dbfield;}

    vx_core::Type_typedef Class_dbfield::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
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
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "dbfieldid", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "type", // name
            vx_core::t_any // type
          ),
          vx_core::vx_new_arg(
            "value", // name
            vx_core::t_any // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_dbfield::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type dbfieldmap)
  // class Class_dbfieldmap {
    Abstract_dbfieldmap::~Abstract_dbfieldmap() {}

    Class_dbfieldmap::Class_dbfieldmap() : Abstract_dbfieldmap::Abstract_dbfieldmap() {
      vx_core::refcount += 1;
    }

    Class_dbfieldmap::~Class_dbfieldmap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (auto const& [key, val] : this->vx_p_map) {
        vx_core::vx_release_one(val);
      }
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_dbfieldmap::vx_map() const {
      vx_core::vx_Type_mapany output = vx_core::vx_map_from_map(vx_core::t_any, this->vx_p_map);
      return output;
    }

    // vx_set(map, string, any)
    vx_core::Type_boolean Class_dbfieldmap::vx_set(vx_core::Type_string name, vx_core::Type_any value) {
      vx_core::Type_boolean output = vx_core::c_false;
      vx_core::Type_any valtype = value->vx_type();
      if (valtype == vx_data_db::t_dbfield) {
        vx_data_db::Type_dbfield newval = vx_core::vx_any_from_any(vx_data_db::t_dbfield, value);
        std::string key = name->vx_string();
        if (vx_core::vx_boolean_from_string_starts(key, ":")) {
          key = key.substr(1, key.length());
        }
        vx_data_db::Type_dbfield oldval = this->vx_p_map[key];
        if (oldval != newval) {
          if (oldval) {
            vx_core::vx_release_one(oldval);
          }
          if (newval == vx_data_db::e_dbfield) {
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
    // vx_get_dbfield(key)
    vx_data_db::Type_dbfield Class_dbfieldmap::vx_get_dbfield(vx_core::Type_string key) const {
      vx_data_db::Type_dbfield output = vx_data_db::e_dbfield;
      const vx_data_db::Class_dbfieldmap* map = this;
      std::string skey = key->vx_string();
      if (vx_core::vx_boolean_from_string_starts(skey, ":")) {
        skey = vx_core::vx_string_from_string_start(skey, 2);
      }
      std::map<std::string, vx_data_db::Type_dbfield> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_data_db::e_dbfield);
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_dbfieldmap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_dbfield(key);
    }

    // vx_mapdbfield()
    std::map<std::string, vx_data_db::Type_dbfield> Class_dbfieldmap::vx_mapdbfield() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_dbfieldmap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_data_db::Type_dbfieldmap output = vx_data_db::e_dbfieldmap;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_data_db::Type_dbfield> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_data_db::t_dbfield) {
          vx_data_db::Type_dbfield castval = vx_core::vx_any_from_any(vx_data_db::t_dbfield, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(dbfieldmap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((map.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_db::Class_dbfieldmap();
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

    vx_core::Type_any Class_dbfieldmap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_db::e_dbfieldmap, vals);
    }

    vx_core::Type_any Class_dbfieldmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_db::Type_dbfieldmap output = vx_data_db::e_dbfieldmap;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_db::Type_dbfieldmap valmap = vx_core::vx_any_from_any(vx_data_db::t_dbfieldmap, copyval);
      output = valmap;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_data_db::Type_dbfield> mapval = valmap->vx_mapdbfield();
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
          vx_data_db::Type_dbfield valany = NULL;
          if (valsubtype == vx_data_db::t_dbfield) {
            valany = vx_core::vx_any_from_any(vx_data_db::t_dbfield, valsub);
          } else if (valsubtype == vx_data_db::t_dbfield) {
            valany = vx_core::vx_any_from_any(vx_data_db::t_dbfield, valsub);
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
        output = new vx_data_db::Class_dbfieldmap();
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

    vx_core::Type_msgblock Class_dbfieldmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_db::Class_dbfieldmap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_dbfieldmap::vx_empty() const {return vx_data_db::e_dbfieldmap;}
    vx_core::Type_any Class_dbfieldmap::vx_type() const {return vx_data_db::t_dbfieldmap;}

    vx_core::Type_typedef Class_dbfieldmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/db", // pkgname
        "dbfieldmap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_data_db::t_dbfield}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_dbfieldmap::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type dbid)
  // class Class_dbid {
    Abstract_dbid::~Abstract_dbid() {}

    Class_dbid::Class_dbid() : Abstract_dbid::Abstract_dbid() {
      vx_core::refcount += 1;
    }

    Class_dbid::~Class_dbid() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_dbid::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_db::e_dbid, vals);
    }

    vx_core::Type_any Class_dbid::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_db::Type_dbid output = vx_data_db::e_dbid;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_dbid::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_db::Class_dbid::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_dbid::vx_empty() const {return vx_data_db::e_dbid;}
    vx_core::Type_any Class_dbid::vx_type() const {return vx_data_db::t_dbid;}

    vx_core::Type_typedef Class_dbid::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/db", // pkgname
        "dbid", // name
        ":string", // extends
        vx_core::e_typelist, // traits
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

    vx_core::Type_constdef Class_dbid::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type dblink)
  // class Class_dblink {
    Abstract_dblink::~Abstract_dblink() {}

    Class_dblink::Class_dblink() : Abstract_dblink::Abstract_dblink() {
      vx_core::refcount += 1;
    }

    Class_dblink::~Class_dblink() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_fromid,
        this->vx_p_toid
      });
    }

    // fromid()
    vx_data_db::Type_dbid Class_dblink::fromid() const {
      vx_data_db::Type_dbid output = this->vx_p_fromid;
      if (!output) {
        output = vx_data_db::e_dbid;
      }
      return output;
    }

    // toid()
    vx_data_db::Type_dbid Class_dblink::toid() const {
      vx_data_db::Type_dbid output = this->vx_p_toid;
      if (!output) {
        output = vx_data_db::e_dbid;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_dblink::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":fromid") {
        output = this->fromid();
      } else if (skey == ":toid") {
        output = this->toid();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_dblink::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":fromid"] = this->fromid();
      output[":toid"] = this->toid();
      return output;
    }

    vx_core::Type_any Class_dblink::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_db::e_dblink, vals);
    }

    vx_core::Type_any Class_dblink::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_db::Type_dblink output = vx_data_db::e_dblink;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_db::Type_dblink val = vx_core::vx_any_from_any(vx_data_db::t_dblink, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_data_db::Type_dbid vx_p_fromid = val->fromid();
      vx_data_db::Type_dbid vx_p_toid = val->toid();
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
          } else if (testkey == ":fromid") {
            key = testkey;
          } else if (testkey == ":toid") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dblink) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":fromid") {
            if (vx_p_fromid == valsub) {
            } else if (valsubtype == vx_data_db::t_dbid) {
              ischanged = true;
              vx_p_fromid = vx_core::vx_any_from_any(vx_data_db::t_dbid, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dblink :fromid " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":toid") {
            if (vx_p_toid == valsub) {
            } else if (valsubtype == vx_data_db::t_dbid) {
              ischanged = true;
              vx_p_toid = vx_core::vx_any_from_any(vx_data_db::t_dbid, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dblink :toid " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dblink) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_db::Class_dblink();
        if (output->vx_p_fromid != vx_p_fromid) {
          if (output->vx_p_fromid) {
            vx_core::vx_release_one(output->vx_p_fromid);
          }
          output->vx_p_fromid = vx_p_fromid;
          vx_core::vx_reserve(vx_p_fromid);
        }
        if (output->vx_p_toid != vx_p_toid) {
          if (output->vx_p_toid) {
            vx_core::vx_release_one(output->vx_p_toid);
          }
          output->vx_p_toid = vx_p_toid;
          vx_core::vx_reserve(vx_p_toid);
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

    vx_core::Type_msgblock Class_dblink::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_db::Class_dblink::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_dblink::vx_empty() const {return vx_data_db::e_dblink;}
    vx_core::Type_any Class_dblink::vx_type() const {return vx_data_db::t_dblink;}

    vx_core::Type_typedef Class_dblink::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/db", // pkgname
        "dblink", // name
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
            "fromid", // name
            vx_data_db::t_dbid // type
          ),
          vx_core::vx_new_arg(
            "toid", // name
            vx_data_db::t_dbid // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_dblink::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type dblinklist)
  // class Class_dblinklist {
    Abstract_dblinklist::~Abstract_dblinklist() {}

    Class_dblinklist::Class_dblinklist() : Abstract_dblinklist::Abstract_dblinklist() {
      vx_core::refcount += 1;
    }

    Class_dblinklist::~Class_dblinklist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_dblinklist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_data_db::Type_dblink Class_dblinklist::vx_get_dblink(vx_core::Type_int index) const {
      vx_data_db::Type_dblink output = vx_data_db::e_dblink;
      long iindex = index->vx_int();
      std::vector<vx_data_db::Type_dblink> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_data_db::Type_dblink> Class_dblinklist::vx_listdblink() const {return vx_p_list;}

    vx_core::Type_any vx_data_db::Class_dblinklist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_dblink(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_dblinklist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_data_db::Type_dblinklist output = vx_data_db::e_dblinklist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_data_db::Type_dblink> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_data_db::t_dblink) {
          vx_data_db::Type_dblink castval = vx_core::vx_any_from_any(vx_data_db::t_dblink, valsub);
          list.push_back(castval);
        } else if (vx_core::vx_boolean_from_type_trait(valtype, vx_data_db::t_dblink)) {
          vx_data_db::Type_dblink castval = vx_core::vx_any_from_any(vx_data_db::t_dblink, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(dblinklist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((list.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_db::Class_dblinklist();
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

    vx_core::Type_any Class_dblinklist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_db::e_dblinklist, vals);
    }

    vx_core::Type_any Class_dblinklist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_db::Type_dblinklist output = vx_data_db::e_dblinklist;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_db::Type_dblinklist val = vx_core::vx_any_from_any(vx_data_db::t_dblinklist, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_data_db::Type_dblink> listval = val->vx_listdblink();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_data_db::t_dblink) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_data_db::t_dblink, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_data_db::t_dblink)) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_data_db::t_dblink, valsub));
        } else if (valsubtype == vx_data_db::t_dblinklist) {
          ischanged = true;
          vx_data_db::Type_dblinklist multi = vx_core::vx_any_from_any(vx_data_db::t_dblinklist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listdblink());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dblinklist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if (ischanged || (listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_db::Class_dblinklist();
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

    vx_core::Type_msgblock Class_dblinklist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_db::Class_dblinklist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_dblinklist::vx_empty() const {return vx_data_db::e_dblinklist;}
    vx_core::Type_any Class_dblinklist::vx_type() const {return vx_data_db::t_dblinklist;}

    vx_core::Type_typedef Class_dblinklist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/db", // pkgname
        "dblinklist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_data_db::t_dblink}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_dblinklist::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type dbnode)
  // class Class_dbnode {
    Abstract_dbnode::~Abstract_dbnode() {}

    Class_dbnode::Class_dbnode() : Abstract_dbnode::Abstract_dbnode() {
      vx_core::refcount += 1;
    }

    Class_dbnode::~Class_dbnode() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_dbid,
        this->vx_p_links
      });
    }

    // dbid()
    vx_data_db::Type_dbid Class_dbnode::dbid() const {
      vx_data_db::Type_dbid output = this->vx_p_dbid;
      if (!output) {
        output = vx_data_db::e_dbid;
      }
      return output;
    }

    // links()
    vx_data_db::Type_dblinklist Class_dbnode::links() const {
      vx_data_db::Type_dblinklist output = this->vx_p_links;
      if (!output) {
        output = vx_data_db::e_dblinklist;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_dbnode::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":dbid") {
        output = this->dbid();
      } else if (skey == ":links") {
        output = this->links();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_dbnode::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":dbid"] = this->dbid();
      output[":links"] = this->links();
      return output;
    }

    vx_core::Type_any Class_dbnode::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_db::e_dbnode, vals);
    }

    vx_core::Type_any Class_dbnode::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_db::Type_dbnode output = vx_data_db::e_dbnode;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_db::Type_dbnode val = vx_core::vx_any_from_any(vx_data_db::t_dbnode, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_data_db::Type_dbid vx_p_dbid = val->dbid();
      vx_data_db::Type_dblinklist vx_p_links = val->links();
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
          } else if (testkey == ":dbid") {
            key = testkey;
          } else if (testkey == ":links") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbnode) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":dbid") {
            if (vx_p_dbid == valsub) {
            } else if (valsubtype == vx_data_db::t_dbid) {
              ischanged = true;
              vx_p_dbid = vx_core::vx_any_from_any(vx_data_db::t_dbid, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbnode :dbid " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":links") {
            if (vx_p_links == valsub) {
            } else if (valsubtype == vx_data_db::t_dblinklist) {
              ischanged = true;
              vx_p_links = vx_core::vx_any_from_any(vx_data_db::t_dblinklist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbnode :links " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbnode) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_db::Class_dbnode();
        if (output->vx_p_dbid != vx_p_dbid) {
          if (output->vx_p_dbid) {
            vx_core::vx_release_one(output->vx_p_dbid);
          }
          output->vx_p_dbid = vx_p_dbid;
          vx_core::vx_reserve(vx_p_dbid);
        }
        if (output->vx_p_links != vx_p_links) {
          if (output->vx_p_links) {
            vx_core::vx_release_one(output->vx_p_links);
          }
          output->vx_p_links = vx_p_links;
          vx_core::vx_reserve(vx_p_links);
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

    vx_core::Type_msgblock Class_dbnode::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_db::Class_dbnode::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_dbnode::vx_empty() const {return vx_data_db::e_dbnode;}
    vx_core::Type_any Class_dbnode::vx_type() const {return vx_data_db::t_dbnode;}

    vx_core::Type_typedef Class_dbnode::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/db", // pkgname
        "dbnode", // name
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
            "dbid", // name
            vx_data_db::t_dbid // type
          ),
          vx_core::vx_new_arg(
            "links", // name
            vx_data_db::t_dblinklist // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_dbnode::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type dbnote)
  // class Class_dbnote {
    Abstract_dbnote::~Abstract_dbnote() {}

    Class_dbnote::Class_dbnote() : Abstract_dbnote::Abstract_dbnote() {
      vx_core::refcount += 1;
    }

    Class_dbnote::~Class_dbnote() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_dbid,
        this->vx_p_valid,
        this->vx_p_noteid,
        this->vx_p_valueid,
        this->vx_p_value
      });
    }

    // dbid()
    vx_data_db::Type_dbid Class_dbnote::dbid() const {
      vx_data_db::Type_dbid output = this->vx_p_dbid;
      if (!output) {
        output = vx_data_db::e_dbid;
      }
      return output;
    }

    // valid()
    vx_data_db::Type_dbid Class_dbnote::valid() const {
      vx_data_db::Type_dbid output = this->vx_p_valid;
      if (!output) {
        output = vx_data_db::e_dbid;
      }
      return output;
    }

    // noteid()
    vx_data_db::Type_dbid Class_dbnote::noteid() const {
      vx_data_db::Type_dbid output = this->vx_p_noteid;
      if (!output) {
        output = vx_data_db::e_dbid;
      }
      return output;
    }

    // valueid()
    vx_data_db::Type_dbid Class_dbnote::valueid() const {
      vx_data_db::Type_dbid output = this->vx_p_valueid;
      if (!output) {
        output = vx_data_db::e_dbid;
      }
      return output;
    }

    // value()
    vx_core::Type_string Class_dbnote::value() const {
      vx_core::Type_string output = this->vx_p_value;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_dbnote::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":dbid") {
        output = this->dbid();
      } else if (skey == ":valid") {
        output = this->valid();
      } else if (skey == ":noteid") {
        output = this->noteid();
      } else if (skey == ":valueid") {
        output = this->valueid();
      } else if (skey == ":value") {
        output = this->value();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_dbnote::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":dbid"] = this->dbid();
      output[":valid"] = this->valid();
      output[":noteid"] = this->noteid();
      output[":valueid"] = this->valueid();
      output[":value"] = this->value();
      return output;
    }

    vx_core::Type_any Class_dbnote::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_db::e_dbnote, vals);
    }

    vx_core::Type_any Class_dbnote::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_db::Type_dbnote output = vx_data_db::e_dbnote;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_db::Type_dbnote val = vx_core::vx_any_from_any(vx_data_db::t_dbnote, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_data_db::Type_dbid vx_p_dbid = val->dbid();
      vx_data_db::Type_dbid vx_p_valid = val->valid();
      vx_data_db::Type_dbid vx_p_noteid = val->noteid();
      vx_data_db::Type_dbid vx_p_valueid = val->valueid();
      vx_core::Type_string vx_p_value = val->value();
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
          } else if (testkey == ":dbid") {
            key = testkey;
          } else if (testkey == ":valid") {
            key = testkey;
          } else if (testkey == ":noteid") {
            key = testkey;
          } else if (testkey == ":valueid") {
            key = testkey;
          } else if (testkey == ":value") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbnote) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":dbid") {
            if (vx_p_dbid == valsub) {
            } else if (valsubtype == vx_data_db::t_dbid) {
              ischanged = true;
              vx_p_dbid = vx_core::vx_any_from_any(vx_data_db::t_dbid, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbnote :dbid " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":valid") {
            if (vx_p_valid == valsub) {
            } else if (valsubtype == vx_data_db::t_dbid) {
              ischanged = true;
              vx_p_valid = vx_core::vx_any_from_any(vx_data_db::t_dbid, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbnote :valid " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":noteid") {
            if (vx_p_noteid == valsub) {
            } else if (valsubtype == vx_data_db::t_dbid) {
              ischanged = true;
              vx_p_noteid = vx_core::vx_any_from_any(vx_data_db::t_dbid, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbnote :noteid " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":valueid") {
            if (vx_p_valueid == valsub) {
            } else if (valsubtype == vx_data_db::t_dbid) {
              ischanged = true;
              vx_p_valueid = vx_core::vx_any_from_any(vx_data_db::t_dbid, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbnote :valueid " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":value") {
            if (vx_p_value == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_value = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbnote :value " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbnote) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_db::Class_dbnote();
        if (output->vx_p_dbid != vx_p_dbid) {
          if (output->vx_p_dbid) {
            vx_core::vx_release_one(output->vx_p_dbid);
          }
          output->vx_p_dbid = vx_p_dbid;
          vx_core::vx_reserve(vx_p_dbid);
        }
        if (output->vx_p_valid != vx_p_valid) {
          if (output->vx_p_valid) {
            vx_core::vx_release_one(output->vx_p_valid);
          }
          output->vx_p_valid = vx_p_valid;
          vx_core::vx_reserve(vx_p_valid);
        }
        if (output->vx_p_noteid != vx_p_noteid) {
          if (output->vx_p_noteid) {
            vx_core::vx_release_one(output->vx_p_noteid);
          }
          output->vx_p_noteid = vx_p_noteid;
          vx_core::vx_reserve(vx_p_noteid);
        }
        if (output->vx_p_valueid != vx_p_valueid) {
          if (output->vx_p_valueid) {
            vx_core::vx_release_one(output->vx_p_valueid);
          }
          output->vx_p_valueid = vx_p_valueid;
          vx_core::vx_reserve(vx_p_valueid);
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

    vx_core::Type_msgblock Class_dbnote::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_db::Class_dbnote::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_dbnote::vx_empty() const {return vx_data_db::e_dbnote;}
    vx_core::Type_any Class_dbnote::vx_type() const {return vx_data_db::t_dbnote;}

    vx_core::Type_typedef Class_dbnote::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/db", // pkgname
        "dbnote", // name
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
            "dbid", // name
            vx_data_db::t_dbid // type
          ),
          vx_core::vx_new_arg(
            "valid", // name
            vx_data_db::t_dbid // type
          ),
          vx_core::vx_new_arg(
            "noteid", // name
            vx_data_db::t_dbid // type
          ),
          vx_core::vx_new_arg(
            "valueid", // name
            vx_data_db::t_dbid // type
          ),
          vx_core::vx_new_arg(
            "value", // name
            vx_core::t_string // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_dbnote::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type dbtable)
  // class Class_dbtable {
    Abstract_dbtable::~Abstract_dbtable() {}

    Class_dbtable::Class_dbtable() : Abstract_dbtable::Abstract_dbtable() {
      vx_core::refcount += 1;
    }

    Class_dbtable::~Class_dbtable() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_dbtableid,
        this->vx_p_db,
        this->vx_p_dbcellmap,
        this->vx_p_dbfieldmap
      });
    }

    // dbtableid()
    vx_core::Type_string Class_dbtable::dbtableid() const {
      vx_core::Type_string output = this->vx_p_dbtableid;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // db()
    vx_data_db::Type_db Class_dbtable::db() const {
      vx_data_db::Type_db output = this->vx_p_db;
      if (!output) {
        output = vx_data_db::e_db;
      }
      return output;
    }

    // dbcellmap()
    vx_data_db::Type_dbcellmap Class_dbtable::dbcellmap() const {
      vx_data_db::Type_dbcellmap output = this->vx_p_dbcellmap;
      if (!output) {
        output = vx_data_db::e_dbcellmap;
      }
      return output;
    }

    // dbfieldmap()
    vx_data_db::Type_dbfieldmap Class_dbtable::dbfieldmap() const {
      vx_data_db::Type_dbfieldmap output = this->vx_p_dbfieldmap;
      if (!output) {
        output = vx_data_db::e_dbfieldmap;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_dbtable::vx_get_any(vx_core::Type_string key) const {
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
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_dbtable::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":dbtableid"] = this->dbtableid();
      output[":db"] = this->db();
      output[":dbcellmap"] = this->dbcellmap();
      output[":dbfieldmap"] = this->dbfieldmap();
      return output;
    }

    vx_core::Type_any Class_dbtable::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_db::e_dbtable, vals);
    }

    vx_core::Type_any Class_dbtable::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_db::Type_dbtable output = vx_data_db::e_dbtable;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_db::Type_dbtable val = vx_core::vx_any_from_any(vx_data_db::t_dbtable, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_dbtableid = val->dbtableid();
      vx_data_db::Type_db vx_p_db = val->db();
      vx_data_db::Type_dbcellmap vx_p_dbcellmap = val->dbcellmap();
      vx_data_db::Type_dbfieldmap vx_p_dbfieldmap = val->dbfieldmap();
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
          } else if (testkey == ":dbtableid") {
            key = testkey;
          } else if (testkey == ":db") {
            key = testkey;
          } else if (testkey == ":dbcellmap") {
            key = testkey;
          } else if (testkey == ":dbfieldmap") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbtable) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":dbtableid") {
            if (vx_p_dbtableid == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_dbtableid = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbtable :dbtableid " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":db") {
            if (vx_p_db == valsub) {
            } else if (valsubtype == vx_data_db::t_db) {
              ischanged = true;
              vx_p_db = vx_core::vx_any_from_any(vx_data_db::t_db, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbtable :db " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":dbcellmap") {
            if (vx_p_dbcellmap == valsub) {
            } else if (valsubtype == vx_data_db::t_dbcellmap) {
              ischanged = true;
              vx_p_dbcellmap = vx_core::vx_any_from_any(vx_data_db::t_dbcellmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbtable :dbcellmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":dbfieldmap") {
            if (vx_p_dbfieldmap == valsub) {
            } else if (valsubtype == vx_data_db::t_dbfieldmap) {
              ischanged = true;
              vx_p_dbfieldmap = vx_core::vx_any_from_any(vx_data_db::t_dbfieldmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbtable :dbfieldmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbtable) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_db::Class_dbtable();
        if (output->vx_p_dbtableid != vx_p_dbtableid) {
          if (output->vx_p_dbtableid) {
            vx_core::vx_release_one(output->vx_p_dbtableid);
          }
          output->vx_p_dbtableid = vx_p_dbtableid;
          vx_core::vx_reserve(vx_p_dbtableid);
        }
        if (output->vx_p_db != vx_p_db) {
          if (output->vx_p_db) {
            vx_core::vx_release_one(output->vx_p_db);
          }
          output->vx_p_db = vx_p_db;
          vx_core::vx_reserve(vx_p_db);
        }
        if (output->vx_p_dbcellmap != vx_p_dbcellmap) {
          if (output->vx_p_dbcellmap) {
            vx_core::vx_release_one(output->vx_p_dbcellmap);
          }
          output->vx_p_dbcellmap = vx_p_dbcellmap;
          vx_core::vx_reserve(vx_p_dbcellmap);
        }
        if (output->vx_p_dbfieldmap != vx_p_dbfieldmap) {
          if (output->vx_p_dbfieldmap) {
            vx_core::vx_release_one(output->vx_p_dbfieldmap);
          }
          output->vx_p_dbfieldmap = vx_p_dbfieldmap;
          vx_core::vx_reserve(vx_p_dbfieldmap);
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

    vx_core::Type_msgblock Class_dbtable::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_db::Class_dbtable::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_dbtable::vx_empty() const {return vx_data_db::e_dbtable;}
    vx_core::Type_any Class_dbtable::vx_type() const {return vx_data_db::t_dbtable;}

    vx_core::Type_typedef Class_dbtable::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
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
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "dbtableid", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "db", // name
            vx_data_db::t_db // type
          ),
          vx_core::vx_new_arg(
            "dbcellmap", // name
            vx_data_db::t_dbcellmap // type
          ),
          vx_core::vx_new_arg(
            "dbfieldmap", // name
            vx_data_db::t_dbfieldmap // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_dbtable::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type dbvalue)
  // class Class_dbvalue {
    Abstract_dbvalue::~Abstract_dbvalue() {}

    Class_dbvalue::Class_dbvalue() : Abstract_dbvalue::Abstract_dbvalue() {
      vx_core::refcount += 1;
    }

    Class_dbvalue::~Class_dbvalue() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_dbid,
        this->vx_p_fromid,
        this->vx_p_toid,
        this->vx_p_noteid,
        this->vx_p_valid,
        this->vx_p_valtext
      });
    }

    // dbid()
    vx_data_db::Type_dbid Class_dbvalue::dbid() const {
      vx_data_db::Type_dbid output = this->vx_p_dbid;
      if (!output) {
        output = vx_data_db::e_dbid;
      }
      return output;
    }

    // fromid()
    vx_data_db::Type_dbid Class_dbvalue::fromid() const {
      vx_data_db::Type_dbid output = this->vx_p_fromid;
      if (!output) {
        output = vx_data_db::e_dbid;
      }
      return output;
    }

    // toid()
    vx_data_db::Type_dbid Class_dbvalue::toid() const {
      vx_data_db::Type_dbid output = this->vx_p_toid;
      if (!output) {
        output = vx_data_db::e_dbid;
      }
      return output;
    }

    // noteid()
    vx_data_db::Type_dbid Class_dbvalue::noteid() const {
      vx_data_db::Type_dbid output = this->vx_p_noteid;
      if (!output) {
        output = vx_data_db::e_dbid;
      }
      return output;
    }

    // valid()
    vx_data_db::Type_dbid Class_dbvalue::valid() const {
      vx_data_db::Type_dbid output = this->vx_p_valid;
      if (!output) {
        output = vx_data_db::e_dbid;
      }
      return output;
    }

    // valtext()
    vx_core::Type_string Class_dbvalue::valtext() const {
      vx_core::Type_string output = this->vx_p_valtext;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_dbvalue::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":dbid") {
        output = this->dbid();
      } else if (skey == ":fromid") {
        output = this->fromid();
      } else if (skey == ":toid") {
        output = this->toid();
      } else if (skey == ":noteid") {
        output = this->noteid();
      } else if (skey == ":valid") {
        output = this->valid();
      } else if (skey == ":valtext") {
        output = this->valtext();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_dbvalue::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":dbid"] = this->dbid();
      output[":fromid"] = this->fromid();
      output[":toid"] = this->toid();
      output[":noteid"] = this->noteid();
      output[":valid"] = this->valid();
      output[":valtext"] = this->valtext();
      return output;
    }

    vx_core::Type_any Class_dbvalue::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_db::e_dbvalue, vals);
    }

    vx_core::Type_any Class_dbvalue::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_db::Type_dbvalue output = vx_data_db::e_dbvalue;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_db::Type_dbvalue val = vx_core::vx_any_from_any(vx_data_db::t_dbvalue, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_data_db::Type_dbid vx_p_dbid = val->dbid();
      vx_data_db::Type_dbid vx_p_fromid = val->fromid();
      vx_data_db::Type_dbid vx_p_toid = val->toid();
      vx_data_db::Type_dbid vx_p_noteid = val->noteid();
      vx_data_db::Type_dbid vx_p_valid = val->valid();
      vx_core::Type_string vx_p_valtext = val->valtext();
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
          } else if (testkey == ":dbid") {
            key = testkey;
          } else if (testkey == ":fromid") {
            key = testkey;
          } else if (testkey == ":toid") {
            key = testkey;
          } else if (testkey == ":noteid") {
            key = testkey;
          } else if (testkey == ":valid") {
            key = testkey;
          } else if (testkey == ":valtext") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbvalue) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":dbid") {
            if (vx_p_dbid == valsub) {
            } else if (valsubtype == vx_data_db::t_dbid) {
              ischanged = true;
              vx_p_dbid = vx_core::vx_any_from_any(vx_data_db::t_dbid, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbvalue :dbid " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":fromid") {
            if (vx_p_fromid == valsub) {
            } else if (valsubtype == vx_data_db::t_dbid) {
              ischanged = true;
              vx_p_fromid = vx_core::vx_any_from_any(vx_data_db::t_dbid, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbvalue :fromid " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":toid") {
            if (vx_p_toid == valsub) {
            } else if (valsubtype == vx_data_db::t_dbid) {
              ischanged = true;
              vx_p_toid = vx_core::vx_any_from_any(vx_data_db::t_dbid, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbvalue :toid " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":noteid") {
            if (vx_p_noteid == valsub) {
            } else if (valsubtype == vx_data_db::t_dbid) {
              ischanged = true;
              vx_p_noteid = vx_core::vx_any_from_any(vx_data_db::t_dbid, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbvalue :noteid " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":valid") {
            if (vx_p_valid == valsub) {
            } else if (valsubtype == vx_data_db::t_dbid) {
              ischanged = true;
              vx_p_valid = vx_core::vx_any_from_any(vx_data_db::t_dbid, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbvalue :valid " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":valtext") {
            if (vx_p_valtext == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_valtext = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbvalue :valtext " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new dbvalue) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_db::Class_dbvalue();
        if (output->vx_p_dbid != vx_p_dbid) {
          if (output->vx_p_dbid) {
            vx_core::vx_release_one(output->vx_p_dbid);
          }
          output->vx_p_dbid = vx_p_dbid;
          vx_core::vx_reserve(vx_p_dbid);
        }
        if (output->vx_p_fromid != vx_p_fromid) {
          if (output->vx_p_fromid) {
            vx_core::vx_release_one(output->vx_p_fromid);
          }
          output->vx_p_fromid = vx_p_fromid;
          vx_core::vx_reserve(vx_p_fromid);
        }
        if (output->vx_p_toid != vx_p_toid) {
          if (output->vx_p_toid) {
            vx_core::vx_release_one(output->vx_p_toid);
          }
          output->vx_p_toid = vx_p_toid;
          vx_core::vx_reserve(vx_p_toid);
        }
        if (output->vx_p_noteid != vx_p_noteid) {
          if (output->vx_p_noteid) {
            vx_core::vx_release_one(output->vx_p_noteid);
          }
          output->vx_p_noteid = vx_p_noteid;
          vx_core::vx_reserve(vx_p_noteid);
        }
        if (output->vx_p_valid != vx_p_valid) {
          if (output->vx_p_valid) {
            vx_core::vx_release_one(output->vx_p_valid);
          }
          output->vx_p_valid = vx_p_valid;
          vx_core::vx_reserve(vx_p_valid);
        }
        if (output->vx_p_valtext != vx_p_valtext) {
          if (output->vx_p_valtext) {
            vx_core::vx_release_one(output->vx_p_valtext);
          }
          output->vx_p_valtext = vx_p_valtext;
          vx_core::vx_reserve(vx_p_valtext);
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

    vx_core::Type_msgblock Class_dbvalue::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_db::Class_dbvalue::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_dbvalue::vx_empty() const {return vx_data_db::e_dbvalue;}
    vx_core::Type_any Class_dbvalue::vx_type() const {return vx_data_db::t_dbvalue;}

    vx_core::Type_typedef Class_dbvalue::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/db", // pkgname
        "dbvalue", // name
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
            "dbid", // name
            vx_data_db::t_dbid // type
          ),
          vx_core::vx_new_arg(
            "fromid", // name
            vx_data_db::t_dbid // type
          ),
          vx_core::vx_new_arg(
            "toid", // name
            vx_data_db::t_dbid // type
          ),
          vx_core::vx_new_arg(
            "noteid", // name
            vx_data_db::t_dbid // type
          ),
          vx_core::vx_new_arg(
            "valid", // name
            vx_data_db::t_dbid // type
          ),
          vx_core::vx_new_arg(
            "valtext", // name
            vx_core::t_string // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_dbvalue::vx_constdef() const {return this->vx_p_constdef;}


  //}

  vx_data_db::Type_db e_db = NULL;
  vx_data_db::Type_db t_db = NULL;
  vx_data_db::Type_dbcell e_dbcell = NULL;
  vx_data_db::Type_dbcell t_dbcell = NULL;
  vx_data_db::Type_dbcellmap e_dbcellmap = NULL;
  vx_data_db::Type_dbcellmap t_dbcellmap = NULL;
  vx_data_db::Type_dbfield e_dbfield = NULL;
  vx_data_db::Type_dbfield t_dbfield = NULL;
  vx_data_db::Type_dbfieldmap e_dbfieldmap = NULL;
  vx_data_db::Type_dbfieldmap t_dbfieldmap = NULL;
  vx_data_db::Type_dbid e_dbid = NULL;
  vx_data_db::Type_dbid t_dbid = NULL;
  vx_data_db::Type_dblink e_dblink = NULL;
  vx_data_db::Type_dblink t_dblink = NULL;
  vx_data_db::Type_dblinklist e_dblinklist = NULL;
  vx_data_db::Type_dblinklist t_dblinklist = NULL;
  vx_data_db::Type_dbnode e_dbnode = NULL;
  vx_data_db::Type_dbnode t_dbnode = NULL;
  vx_data_db::Type_dbnote e_dbnote = NULL;
  vx_data_db::Type_dbnote t_dbnote = NULL;
  vx_data_db::Type_dbtable e_dbtable = NULL;
  vx_data_db::Type_dbtable t_dbtable = NULL;
  vx_data_db::Type_dbvalue e_dbvalue = NULL;
  vx_data_db::Type_dbvalue t_dbvalue = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_data_db::e_db = new Class_db();
      vx_core::vx_reserve_empty(vx_data_db::e_db);
      vx_data_db::t_db = new Class_db();
      vx_core::vx_reserve_type(vx_data_db::t_db);
      vx_data_db::e_dbcell = new Class_dbcell();
      vx_core::vx_reserve_empty(vx_data_db::e_dbcell);
      vx_data_db::t_dbcell = new Class_dbcell();
      vx_core::vx_reserve_type(vx_data_db::t_dbcell);
      vx_data_db::e_dbcellmap = new Class_dbcellmap();
      vx_core::vx_reserve_empty(vx_data_db::e_dbcellmap);
      vx_data_db::t_dbcellmap = new Class_dbcellmap();
      vx_core::vx_reserve_type(vx_data_db::t_dbcellmap);
      vx_data_db::e_dbfield = new Class_dbfield();
      vx_core::vx_reserve_empty(vx_data_db::e_dbfield);
      vx_data_db::t_dbfield = new Class_dbfield();
      vx_core::vx_reserve_type(vx_data_db::t_dbfield);
      vx_data_db::e_dbfieldmap = new Class_dbfieldmap();
      vx_core::vx_reserve_empty(vx_data_db::e_dbfieldmap);
      vx_data_db::t_dbfieldmap = new Class_dbfieldmap();
      vx_core::vx_reserve_type(vx_data_db::t_dbfieldmap);
      vx_data_db::e_dbid = new Class_dbid();
      vx_core::vx_reserve_empty(vx_data_db::e_dbid);
      vx_data_db::t_dbid = new Class_dbid();
      vx_core::vx_reserve_type(vx_data_db::t_dbid);
      vx_data_db::e_dblink = new Class_dblink();
      vx_core::vx_reserve_empty(vx_data_db::e_dblink);
      vx_data_db::t_dblink = new Class_dblink();
      vx_core::vx_reserve_type(vx_data_db::t_dblink);
      vx_data_db::e_dblinklist = new Class_dblinklist();
      vx_core::vx_reserve_empty(vx_data_db::e_dblinklist);
      vx_data_db::t_dblinklist = new Class_dblinklist();
      vx_core::vx_reserve_type(vx_data_db::t_dblinklist);
      vx_data_db::e_dbnode = new Class_dbnode();
      vx_core::vx_reserve_empty(vx_data_db::e_dbnode);
      vx_data_db::t_dbnode = new Class_dbnode();
      vx_core::vx_reserve_type(vx_data_db::t_dbnode);
      vx_data_db::e_dbnote = new Class_dbnote();
      vx_core::vx_reserve_empty(vx_data_db::e_dbnote);
      vx_data_db::t_dbnote = new Class_dbnote();
      vx_core::vx_reserve_type(vx_data_db::t_dbnote);
      vx_data_db::e_dbtable = new Class_dbtable();
      vx_core::vx_reserve_empty(vx_data_db::e_dbtable);
      vx_data_db::t_dbtable = new Class_dbtable();
      vx_core::vx_reserve_type(vx_data_db::t_dbtable);
      vx_data_db::e_dbvalue = new Class_dbvalue();
      vx_core::vx_reserve_empty(vx_data_db::e_dbvalue);
      vx_data_db::t_dbvalue = new Class_dbvalue();
      vx_core::vx_reserve_type(vx_data_db::t_dbvalue);
      vx_core::vx_Type_mapany maptype;
      vx_core::vx_Type_mapany mapconst;
      vx_core::vx_Type_mapfunc mapfunc;
      vx_core::vx_Type_mapany mapempty;
      maptype["db"] = vx_data_db::t_db;
      maptype["dbcell"] = vx_data_db::t_dbcell;
      maptype["dbcellmap"] = vx_data_db::t_dbcellmap;
      maptype["dbfield"] = vx_data_db::t_dbfield;
      maptype["dbfieldmap"] = vx_data_db::t_dbfieldmap;
      maptype["dbid"] = vx_data_db::t_dbid;
      maptype["dblink"] = vx_data_db::t_dblink;
      maptype["dblinklist"] = vx_data_db::t_dblinklist;
      maptype["dbnode"] = vx_data_db::t_dbnode;
      maptype["dbnote"] = vx_data_db::t_dbnote;
      maptype["dbtable"] = vx_data_db::t_dbtable;
      maptype["dbvalue"] = vx_data_db::t_dbvalue;
      vx_core::vx_global_package_set("vx/data/db", maptype, mapconst, mapfunc);
	   }
  // }

}
