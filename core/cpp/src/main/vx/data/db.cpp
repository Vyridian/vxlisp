#include <map>
#include <string>
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
      vx_core::vx_release_one({
        this->vx_p_dbid
      });
    }
    // dbid()
    vx_core::Type_string Class_db::dbid() const {
      vx_core::Type_string output = this->vx_p_dbid;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_db::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":dbid") {
        output = this->dbid();
      }
      vx_core::vx_release(key);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_db::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":dbid"] = this->dbid();
      return output;
    }

    vx_core::Type_any Class_db::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_db::e_db(), vals);
    }
    vx_core::Type_any Class_db::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_db::Type_db output = vx_data_db::e_db();
      vx_data_db::Type_db val = vx_core::vx_any_from_any(vx_data_db::t_db(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_dbid = val->dbid();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string()) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            testkey = valstr->vx_string();
          }
          if (false) {
          } else if (testkey == ":dbid") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new db) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":dbid") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_dbid = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new db :dbid " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new db) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_data_db::Class_db();
      output->vx_p_dbid = vx_p_dbid;
      vx_core::vx_reserve(vx_p_dbid);
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release(copyval);
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_msgblock Class_db::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_db::Class_db::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_db::vx_empty() const {return vx_data_db::e_db();}
    vx_core::Type_any Class_db::vx_type() const {return vx_data_db::t_db();}

    vx_core::Type_typedef Class_db::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/db", // pkgname
        "db", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
      return output;
    }

  //}

  // (type dbcell)
  // class Class_dbcell {
    Abstract_dbcell::~Abstract_dbcell() {}

    Class_dbcell::Class_dbcell() : Abstract_dbcell::Abstract_dbcell() {
      vx_core::refcount += 1;
    }
    Class_dbcell::~Class_dbcell() {
      vx_core::refcount -= 1;
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
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // dbcellmap()
    vx_data_db::Type_dbcellmap Class_dbcell::dbcellmap() const {
      vx_data_db::Type_dbcellmap output = this->vx_p_dbcellmap;
      if (output == NULL) {
        output = vx_data_db::e_dbcellmap();
      }
      return output;
    }

    // dbfieldmap()
    vx_data_db::Type_dbfieldmap Class_dbcell::dbfieldmap() const {
      vx_data_db::Type_dbfieldmap output = this->vx_p_dbfieldmap;
      if (output == NULL) {
        output = vx_data_db::e_dbfieldmap();
      }
      return output;
    }

    // dbparent()
    vx_data_db::Type_dbcell Class_dbcell::dbparent() const {
      vx_data_db::Type_dbcell output = this->vx_p_dbparent;
      if (output == NULL) {
        output = vx_data_db::e_dbcell();
      }
      return output;
    }

    // dbtable()
    vx_data_db::Type_dbtable Class_dbcell::dbtable() const {
      vx_data_db::Type_dbtable output = this->vx_p_dbtable;
      if (output == NULL) {
        output = vx_data_db::e_dbtable();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_dbcell::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
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
      vx_core::vx_release(key);
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
      return this->vx_copy(vx_data_db::e_dbcell(), vals);
    }
    vx_core::Type_any Class_dbcell::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_db::Type_dbcell output = vx_data_db::e_dbcell();
      vx_data_db::Type_dbcell val = vx_core::vx_any_from_any(vx_data_db::t_dbcell(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_dbcellid = val->dbcellid();
      vx_data_db::Type_dbcellmap vx_p_dbcellmap = val->dbcellmap();
      vx_data_db::Type_dbfieldmap vx_p_dbfieldmap = val->dbfieldmap();
      vx_data_db::Type_dbcell vx_p_dbparent = val->dbparent();
      vx_data_db::Type_dbtable vx_p_dbtable = val->dbtable();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string()) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
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
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new dbcell) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":dbcellid") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_dbcellid = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new dbcell :dbcellid " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":dbcellmap") {
            if (valsubtype == vx_data_db::t_dbcellmap()) {
              vx_p_dbcellmap = vx_core::vx_any_from_any(vx_data_db::t_dbcellmap(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new dbcell :dbcellmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":dbfieldmap") {
            if (valsubtype == vx_data_db::t_dbfieldmap()) {
              vx_p_dbfieldmap = vx_core::vx_any_from_any(vx_data_db::t_dbfieldmap(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new dbcell :dbfieldmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":dbparent") {
            if (valsubtype == vx_data_db::t_dbcell()) {
              vx_p_dbparent = vx_core::vx_any_from_any(vx_data_db::t_dbcell(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new dbcell :dbparent " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":dbtable") {
            if (valsubtype == vx_data_db::t_dbtable()) {
              vx_p_dbtable = vx_core::vx_any_from_any(vx_data_db::t_dbtable(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new dbcell :dbtable " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new dbcell) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_data_db::Class_dbcell();
      output->vx_p_dbcellid = vx_p_dbcellid;
      vx_core::vx_reserve(vx_p_dbcellid);
      output->vx_p_dbcellmap = vx_p_dbcellmap;
      vx_core::vx_reserve(vx_p_dbcellmap);
      output->vx_p_dbfieldmap = vx_p_dbfieldmap;
      vx_core::vx_reserve(vx_p_dbfieldmap);
      output->vx_p_dbparent = vx_p_dbparent;
      vx_core::vx_reserve(vx_p_dbparent);
      output->vx_p_dbtable = vx_p_dbtable;
      vx_core::vx_reserve(vx_p_dbtable);
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release(copyval);
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_msgblock Class_dbcell::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_db::Class_dbcell::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_dbcell::vx_empty() const {return vx_data_db::e_dbcell();}
    vx_core::Type_any Class_dbcell::vx_type() const {return vx_data_db::t_dbcell();}

    vx_core::Type_typedef Class_dbcell::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/db", // pkgname
        "dbcell", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
      return output;
    }

  //}

  // (type dbcellmap)
  // class Class_dbcellmap {
    Abstract_dbcellmap::~Abstract_dbcellmap() {}

    Class_dbcellmap::Class_dbcellmap() : Abstract_dbcellmap::Abstract_dbcellmap() {
      vx_core::refcount += 1;
    }
    Class_dbcellmap::~Class_dbcellmap() {
      vx_core::refcount -= 1;
      for (auto const& [key, val] : this->vx_p_map) {
        vx_core::vx_release_one(val);
      }
    }
    // vx_map()
    vx_core::vx_Type_mapany Class_dbcellmap::vx_map() const {
      vx_core::vx_Type_mapany output = vx_core::vx_map_from_map(vx_core::t_any(), this->vx_p_map);
      return output;
    }

    // vx_get_dbcell(key)
    vx_data_db::Type_dbcell Class_dbcellmap::vx_get_dbcell(vx_core::Type_string key) const {
      vx_data_db::Type_dbcell output = vx_data_db::e_dbcell();
      const vx_data_db::Class_dbcellmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_data_db::Type_dbcell> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_data_db::e_dbcell());
      vx_core::vx_release(key);
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
      vx_data_db::Type_dbcellmap output = vx_data_db::e_dbcellmap();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::map<std::string, vx_data_db::Type_dbcell> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_data_db::t_dbcell()) {
          vx_data_db::Type_dbcell castval = vx_core::vx_any_from_any(vx_data_db::t_dbcell(), val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(dbcellmap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_data_db::Class_dbcellmap();
      output->vx_p_map = map;
      for (auto const& [key, val] : map) {
        vx_core::vx_reserve(val);
      }
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      for (auto const& [key, val] : mapval) {
        vx_core::vx_release(val);
      }
      return output;
    }

    vx_core::Type_any Class_dbcellmap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_db::e_dbcellmap(), vals);
    }
    vx_core::Type_any Class_dbcellmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_db::Type_dbcellmap output = vx_data_db::e_dbcellmap();
      vx_data_db::Type_dbcellmap valmap = vx_core::vx_any_from_any(vx_data_db::t_dbcellmap(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_data_db::Type_dbcell> mapval;
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          if (valsubtype == vx_core::t_string()) {
            vx_core::Type_string valstring = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            key = valstring->vx_string();
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("Key Expected: " + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          vx_data_db::Type_dbcell valany;
          if (valsubtype == vx_data_db::t_dbcell()) {
            valany = vx_core::vx_any_from_any(vx_data_db::t_dbcell(), valsub);
          } else if (valsubtype == vx_data_db::t_dbcell()) {
            valany = vx_core::vx_any_from_any(vx_data_db::t_dbcell(), valsub);
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("Invalid Key/Value: " + key + " "  + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          if (valany != NULL) {
            mapval[key] = valany;
            key = "";
          }
        }
      }
      output = new vx_data_db::Class_dbcellmap();
      output->vx_p_map = mapval;
      for (auto const& [key, val] : mapval) {
        vx_core::vx_reserve(val);
      }
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release(copyval);
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_msgblock Class_dbcellmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_db::Class_dbcellmap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_dbcellmap::vx_empty() const {return vx_data_db::e_dbcellmap();}
    vx_core::Type_any Class_dbcellmap::vx_type() const {return vx_data_db::t_dbcellmap();}

    vx_core::Type_typedef Class_dbcellmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/db", // pkgname
        "dbcellmap", // name
        ":map", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_data_db::t_dbcell()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
      return output;
    }

  //}

  // (type dbfield)
  // class Class_dbfield {
    Abstract_dbfield::~Abstract_dbfield() {}

    Class_dbfield::Class_dbfield() : Abstract_dbfield::Abstract_dbfield() {
      vx_core::refcount += 1;
    }
    Class_dbfield::~Class_dbfield() {
      vx_core::refcount -= 1;
      vx_core::vx_release_one({
        this->vx_p_dbfieldid,
        this->vx_p_type,
        this->vx_p_value
      });
    }
    // dbfieldid()
    vx_core::Type_string Class_dbfield::dbfieldid() const {
      vx_core::Type_string output = this->vx_p_dbfieldid;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // type()
    vx_core::Type_any Class_dbfield::type() const {
      vx_core::Type_any output = this->vx_p_type;
      if (output == NULL) {
        output = vx_core::e_any();
      }
      return output;
    }

    // value()
    vx_core::Type_any Class_dbfield::value() const {
      vx_core::Type_any output = this->vx_p_value;
      if (output == NULL) {
        output = vx_core::e_any();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_dbfield::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":dbfieldid") {
        output = this->dbfieldid();
      } else if (skey == ":type") {
        output = this->type();
      } else if (skey == ":value") {
        output = this->value();
      }
      vx_core::vx_release(key);
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
      return this->vx_copy(vx_data_db::e_dbfield(), vals);
    }
    vx_core::Type_any Class_dbfield::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_db::Type_dbfield output = vx_data_db::e_dbfield();
      vx_data_db::Type_dbfield val = vx_core::vx_any_from_any(vx_data_db::t_dbfield(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_dbfieldid = val->dbfieldid();
      vx_core::Type_any vx_p_type = val->type();
      vx_core::Type_any vx_p_value = val->value();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string()) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
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
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new dbfield) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":dbfieldid") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_dbfieldid = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new dbfield :dbfieldid " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":type") {
            vx_p_type = valsub;
          } else if (key == ":value") {
            vx_p_value = valsub;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new dbfield) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_data_db::Class_dbfield();
      output->vx_p_dbfieldid = vx_p_dbfieldid;
      vx_core::vx_reserve(vx_p_dbfieldid);
      output->vx_p_type = vx_p_type;
      vx_core::vx_reserve(vx_p_type);
      output->vx_p_value = vx_p_value;
      vx_core::vx_reserve(vx_p_value);
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release(copyval);
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_msgblock Class_dbfield::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_db::Class_dbfield::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_dbfield::vx_empty() const {return vx_data_db::e_dbfield();}
    vx_core::Type_any Class_dbfield::vx_type() const {return vx_data_db::t_dbfield();}

    vx_core::Type_typedef Class_dbfield::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/db", // pkgname
        "dbfield", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
      return output;
    }

  //}

  // (type dbfieldmap)
  // class Class_dbfieldmap {
    Abstract_dbfieldmap::~Abstract_dbfieldmap() {}

    Class_dbfieldmap::Class_dbfieldmap() : Abstract_dbfieldmap::Abstract_dbfieldmap() {
      vx_core::refcount += 1;
    }
    Class_dbfieldmap::~Class_dbfieldmap() {
      vx_core::refcount -= 1;
      for (auto const& [key, val] : this->vx_p_map) {
        vx_core::vx_release_one(val);
      }
    }
    // vx_map()
    vx_core::vx_Type_mapany Class_dbfieldmap::vx_map() const {
      vx_core::vx_Type_mapany output = vx_core::vx_map_from_map(vx_core::t_any(), this->vx_p_map);
      return output;
    }

    // vx_get_dbfield(key)
    vx_data_db::Type_dbfield Class_dbfieldmap::vx_get_dbfield(vx_core::Type_string key) const {
      vx_data_db::Type_dbfield output = vx_data_db::e_dbfield();
      const vx_data_db::Class_dbfieldmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_data_db::Type_dbfield> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_data_db::e_dbfield());
      vx_core::vx_release(key);
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
      vx_data_db::Type_dbfieldmap output = vx_data_db::e_dbfieldmap();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::map<std::string, vx_data_db::Type_dbfield> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_data_db::t_dbfield()) {
          vx_data_db::Type_dbfield castval = vx_core::vx_any_from_any(vx_data_db::t_dbfield(), val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(dbfieldmap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_data_db::Class_dbfieldmap();
      output->vx_p_map = map;
      for (auto const& [key, val] : map) {
        vx_core::vx_reserve(val);
      }
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      for (auto const& [key, val] : mapval) {
        vx_core::vx_release(val);
      }
      return output;
    }

    vx_core::Type_any Class_dbfieldmap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_db::e_dbfieldmap(), vals);
    }
    vx_core::Type_any Class_dbfieldmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_db::Type_dbfieldmap output = vx_data_db::e_dbfieldmap();
      vx_data_db::Type_dbfieldmap valmap = vx_core::vx_any_from_any(vx_data_db::t_dbfieldmap(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_data_db::Type_dbfield> mapval;
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          if (valsubtype == vx_core::t_string()) {
            vx_core::Type_string valstring = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            key = valstring->vx_string();
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("Key Expected: " + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          vx_data_db::Type_dbfield valany;
          if (valsubtype == vx_data_db::t_dbfield()) {
            valany = vx_core::vx_any_from_any(vx_data_db::t_dbfield(), valsub);
          } else if (valsubtype == vx_data_db::t_dbfield()) {
            valany = vx_core::vx_any_from_any(vx_data_db::t_dbfield(), valsub);
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("Invalid Key/Value: " + key + " "  + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          if (valany != NULL) {
            mapval[key] = valany;
            key = "";
          }
        }
      }
      output = new vx_data_db::Class_dbfieldmap();
      output->vx_p_map = mapval;
      for (auto const& [key, val] : mapval) {
        vx_core::vx_reserve(val);
      }
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release(copyval);
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_msgblock Class_dbfieldmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_db::Class_dbfieldmap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_dbfieldmap::vx_empty() const {return vx_data_db::e_dbfieldmap();}
    vx_core::Type_any Class_dbfieldmap::vx_type() const {return vx_data_db::t_dbfieldmap();}

    vx_core::Type_typedef Class_dbfieldmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/db", // pkgname
        "dbfieldmap", // name
        ":map", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_data_db::t_dbfield()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
      return output;
    }

  //}

  // (type dbtable)
  // class Class_dbtable {
    Abstract_dbtable::~Abstract_dbtable() {}

    Class_dbtable::Class_dbtable() : Abstract_dbtable::Abstract_dbtable() {
      vx_core::refcount += 1;
    }
    Class_dbtable::~Class_dbtable() {
      vx_core::refcount -= 1;
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
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // db()
    vx_data_db::Type_db Class_dbtable::db() const {
      vx_data_db::Type_db output = this->vx_p_db;
      if (output == NULL) {
        output = vx_data_db::e_db();
      }
      return output;
    }

    // dbcellmap()
    vx_data_db::Type_dbcellmap Class_dbtable::dbcellmap() const {
      vx_data_db::Type_dbcellmap output = this->vx_p_dbcellmap;
      if (output == NULL) {
        output = vx_data_db::e_dbcellmap();
      }
      return output;
    }

    // dbfieldmap()
    vx_data_db::Type_dbfieldmap Class_dbtable::dbfieldmap() const {
      vx_data_db::Type_dbfieldmap output = this->vx_p_dbfieldmap;
      if (output == NULL) {
        output = vx_data_db::e_dbfieldmap();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_dbtable::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
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
      vx_core::vx_release(key);
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
      return this->vx_copy(vx_data_db::e_dbtable(), vals);
    }
    vx_core::Type_any Class_dbtable::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_db::Type_dbtable output = vx_data_db::e_dbtable();
      vx_data_db::Type_dbtable val = vx_core::vx_any_from_any(vx_data_db::t_dbtable(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_dbtableid = val->dbtableid();
      vx_data_db::Type_db vx_p_db = val->db();
      vx_data_db::Type_dbcellmap vx_p_dbcellmap = val->dbcellmap();
      vx_data_db::Type_dbfieldmap vx_p_dbfieldmap = val->dbfieldmap();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string()) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
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
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new dbtable) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":dbtableid") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_dbtableid = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new dbtable :dbtableid " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":db") {
            if (valsubtype == vx_data_db::t_db()) {
              vx_p_db = vx_core::vx_any_from_any(vx_data_db::t_db(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new dbtable :db " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":dbcellmap") {
            if (valsubtype == vx_data_db::t_dbcellmap()) {
              vx_p_dbcellmap = vx_core::vx_any_from_any(vx_data_db::t_dbcellmap(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new dbtable :dbcellmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":dbfieldmap") {
            if (valsubtype == vx_data_db::t_dbfieldmap()) {
              vx_p_dbfieldmap = vx_core::vx_any_from_any(vx_data_db::t_dbfieldmap(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new dbtable :dbfieldmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new dbtable) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_data_db::Class_dbtable();
      output->vx_p_dbtableid = vx_p_dbtableid;
      vx_core::vx_reserve(vx_p_dbtableid);
      output->vx_p_db = vx_p_db;
      vx_core::vx_reserve(vx_p_db);
      output->vx_p_dbcellmap = vx_p_dbcellmap;
      vx_core::vx_reserve(vx_p_dbcellmap);
      output->vx_p_dbfieldmap = vx_p_dbfieldmap;
      vx_core::vx_reserve(vx_p_dbfieldmap);
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release(copyval);
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_msgblock Class_dbtable::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_db::Class_dbtable::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_dbtable::vx_empty() const {return vx_data_db::e_dbtable();}
    vx_core::Type_any Class_dbtable::vx_type() const {return vx_data_db::t_dbtable();}

    vx_core::Type_typedef Class_dbtable::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/db", // pkgname
        "dbtable", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
      return output;
    }

  //}

  vx_data_db::vx_Class_package* vx_package = new vx_data_db::vx_Class_package();

  vx_data_db::Type_db e_db() {
    vx_data_db::Type_db output = vx_data_db::vx_package->e_db;
    if (output == NULL) {
      output = new Class_db();
      vx_core::vx_reserve_empty(output);
      vx_data_db::vx_package->e_db = output;
    }
    return output;
  }
  vx_data_db::Type_db t_db() {
    vx_data_db::Type_db output = vx_data_db::vx_package->t_db;
    if (output == NULL) {
      output = new Class_db();
      vx_core::vx_reserve_type(output);
      vx_data_db::vx_package->t_db = output;
    }
    return output;
  }

  vx_data_db::Type_dbcell e_dbcell() {
    vx_data_db::Type_dbcell output = vx_data_db::vx_package->e_dbcell;
    if (output == NULL) {
      output = new Class_dbcell();
      vx_core::vx_reserve_empty(output);
      vx_data_db::vx_package->e_dbcell = output;
    }
    return output;
  }
  vx_data_db::Type_dbcell t_dbcell() {
    vx_data_db::Type_dbcell output = vx_data_db::vx_package->t_dbcell;
    if (output == NULL) {
      output = new Class_dbcell();
      vx_core::vx_reserve_type(output);
      vx_data_db::vx_package->t_dbcell = output;
    }
    return output;
  }

  vx_data_db::Type_dbcellmap e_dbcellmap() {
    vx_data_db::Type_dbcellmap output = vx_data_db::vx_package->e_dbcellmap;
    if (output == NULL) {
      output = new Class_dbcellmap();
      vx_core::vx_reserve_empty(output);
      vx_data_db::vx_package->e_dbcellmap = output;
    }
    return output;
  }
  vx_data_db::Type_dbcellmap t_dbcellmap() {
    vx_data_db::Type_dbcellmap output = vx_data_db::vx_package->t_dbcellmap;
    if (output == NULL) {
      output = new Class_dbcellmap();
      vx_core::vx_reserve_type(output);
      vx_data_db::vx_package->t_dbcellmap = output;
    }
    return output;
  }

  vx_data_db::Type_dbfield e_dbfield() {
    vx_data_db::Type_dbfield output = vx_data_db::vx_package->e_dbfield;
    if (output == NULL) {
      output = new Class_dbfield();
      vx_core::vx_reserve_empty(output);
      vx_data_db::vx_package->e_dbfield = output;
    }
    return output;
  }
  vx_data_db::Type_dbfield t_dbfield() {
    vx_data_db::Type_dbfield output = vx_data_db::vx_package->t_dbfield;
    if (output == NULL) {
      output = new Class_dbfield();
      vx_core::vx_reserve_type(output);
      vx_data_db::vx_package->t_dbfield = output;
    }
    return output;
  }

  vx_data_db::Type_dbfieldmap e_dbfieldmap() {
    vx_data_db::Type_dbfieldmap output = vx_data_db::vx_package->e_dbfieldmap;
    if (output == NULL) {
      output = new Class_dbfieldmap();
      vx_core::vx_reserve_empty(output);
      vx_data_db::vx_package->e_dbfieldmap = output;
    }
    return output;
  }
  vx_data_db::Type_dbfieldmap t_dbfieldmap() {
    vx_data_db::Type_dbfieldmap output = vx_data_db::vx_package->t_dbfieldmap;
    if (output == NULL) {
      output = new Class_dbfieldmap();
      vx_core::vx_reserve_type(output);
      vx_data_db::vx_package->t_dbfieldmap = output;
    }
    return output;
  }

  vx_data_db::Type_dbtable e_dbtable() {
    vx_data_db::Type_dbtable output = vx_data_db::vx_package->e_dbtable;
    if (output == NULL) {
      output = new Class_dbtable();
      vx_core::vx_reserve_empty(output);
      vx_data_db::vx_package->e_dbtable = output;
    }
    return output;
  }
  vx_data_db::Type_dbtable t_dbtable() {
    vx_data_db::Type_dbtable output = vx_data_db::vx_package->t_dbtable;
    if (output == NULL) {
      output = new Class_dbtable();
      vx_core::vx_reserve_type(output);
      vx_data_db::vx_package->t_dbtable = output;
    }
    return output;
  }

}
