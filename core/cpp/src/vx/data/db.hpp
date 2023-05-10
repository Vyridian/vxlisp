#pragma once
#include <any>
#include <map>
#include <set>
#include <string>
#include "../../vx/core.hpp"

namespace vx_data_db {

  // forward declarations
  class Type_db;
  extern Type_db* e_db;
  extern Type_db* t_db;
  class Type_dbcell;
  extern Type_dbcell* e_dbcell;
  extern Type_dbcell* t_dbcell;
  class Type_dbcellmap;
  extern Type_dbcellmap* e_dbcellmap;
  extern Type_dbcellmap* t_dbcellmap;
  class Type_dbfield;
  extern Type_dbfield* e_dbfield;
  extern Type_dbfield* t_dbfield;
  class Type_dbfieldmap;
  extern Type_dbfieldmap* e_dbfieldmap;
  extern Type_dbfieldmap* t_dbfieldmap;
  class Type_dbtable;
  extern Type_dbtable* e_dbtable;
  extern Type_dbtable* t_dbtable;


  // (type db)
  class Type_db : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_data_db::Type_db* vx_new(Args*... args);
    template<class... Args> vx_data_db::Type_db* vx_copy(Args*... args);
    virtual vx_data_db::Type_db* vx_empty();
    virtual vx_data_db::Type_db* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // dbid()
    vx_core::Type_string* vx_p_dbid;
    virtual vx_core::Type_string* dbid();
  };

  // (type dbcell)
  class Type_dbcell : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_data_db::Type_dbcell* vx_new(Args*... args);
    template<class... Args> vx_data_db::Type_dbcell* vx_copy(Args*... args);
    virtual vx_data_db::Type_dbcell* vx_empty();
    virtual vx_data_db::Type_dbcell* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // dbcellid()
    vx_core::Type_string* vx_p_dbcellid;
    virtual vx_core::Type_string* dbcellid();
    // dbcellmap()
    vx_data_db::Type_dbcellmap* vx_p_dbcellmap;
    virtual vx_data_db::Type_dbcellmap* dbcellmap();
    // dbfieldmap()
    vx_data_db::Type_dbfieldmap* vx_p_dbfieldmap;
    virtual vx_data_db::Type_dbfieldmap* dbfieldmap();
    // dbparent()
    vx_data_db::Type_dbcell* vx_p_dbparent;
    virtual vx_data_db::Type_dbcell* dbparent();
    // dbtable()
    vx_data_db::Type_dbtable* vx_p_dbtable;
    virtual vx_data_db::Type_dbtable* dbtable();
  };

  // (type dbcellmap)
  class Type_dbcellmap : public virtual vx_core::Type_map {
  public:
    template<class... Args> vx_data_db::Type_dbcellmap* vx_new(Args*... args);
    template<class... Args> vx_data_db::Type_dbcellmap* vx_copy(Args*... args);
    virtual vx_data_db::Type_dbcellmap* vx_empty();
    virtual vx_data_db::Type_dbcellmap* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    std::map<std::string, vx_data_db::Type_dbcell*> vx_p_map;
    // vx_mapdbcell()
    virtual std::map<std::string, vx_data_db::Type_dbcell*> vx_mapdbcell();
    // vx_dbcell(key)
    virtual vx_data_db::Type_dbcell* vx_dbcell(vx_core::Type_string* key);
    virtual vx_data_db::Type_dbcellmap* vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval);
  };

  // (type dbfield)
  class Type_dbfield : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_data_db::Type_dbfield* vx_new(Args*... args);
    template<class... Args> vx_data_db::Type_dbfield* vx_copy(Args*... args);
    virtual vx_data_db::Type_dbfield* vx_empty();
    virtual vx_data_db::Type_dbfield* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // dbfieldid()
    vx_core::Type_string* vx_p_dbfieldid;
    virtual vx_core::Type_string* dbfieldid();
    // type()
    vx_core::Type_any* vx_p_type;
    virtual vx_core::Type_any* type();
    // value()
    vx_core::Type_any* vx_p_value;
    virtual vx_core::Type_any* value();
  };

  // (type dbfieldmap)
  class Type_dbfieldmap : public virtual vx_core::Type_map {
  public:
    template<class... Args> vx_data_db::Type_dbfieldmap* vx_new(Args*... args);
    template<class... Args> vx_data_db::Type_dbfieldmap* vx_copy(Args*... args);
    virtual vx_data_db::Type_dbfieldmap* vx_empty();
    virtual vx_data_db::Type_dbfieldmap* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    std::map<std::string, vx_data_db::Type_dbfield*> vx_p_map;
    // vx_mapdbfield()
    virtual std::map<std::string, vx_data_db::Type_dbfield*> vx_mapdbfield();
    // vx_dbfield(key)
    virtual vx_data_db::Type_dbfield* vx_dbfield(vx_core::Type_string* key);
    virtual vx_data_db::Type_dbfieldmap* vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval);
  };

  // (type dbtable)
  class Type_dbtable : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_data_db::Type_dbtable* vx_new(Args*... args);
    template<class... Args> vx_data_db::Type_dbtable* vx_copy(Args*... args);
    virtual vx_data_db::Type_dbtable* vx_empty();
    virtual vx_data_db::Type_dbtable* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // dbtableid()
    vx_core::Type_string* vx_p_dbtableid;
    virtual vx_core::Type_string* dbtableid();
    // db()
    vx_data_db::Type_db* vx_p_db;
    virtual vx_data_db::Type_db* db();
    // dbcellmap()
    vx_data_db::Type_dbcellmap* vx_p_dbcellmap;
    virtual vx_data_db::Type_dbcellmap* dbcellmap();
    // dbfieldmap()
    vx_data_db::Type_dbfieldmap* vx_p_dbfieldmap;
    virtual vx_data_db::Type_dbfieldmap* dbfieldmap();
  };

}
