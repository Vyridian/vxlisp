#ifndef vx_data_db_hpp
#define vx_data_db_hpp
#include <map>
#include <memory>
#include <set>
#include <string>
#include "../../vx/core.hpp"

namespace vx_data_db {

  // forward declarations
  class Class_db;
  typedef std::shared_ptr<Class_db> Type_db;
  extern Type_db e_db;
  extern Type_db t_db;
  class Class_dbcell;
  typedef std::shared_ptr<Class_dbcell> Type_dbcell;
  extern Type_dbcell e_dbcell;
  extern Type_dbcell t_dbcell;
  class Class_dbcellmap;
  typedef std::shared_ptr<Class_dbcellmap> Type_dbcellmap;
  extern Type_dbcellmap e_dbcellmap;
  extern Type_dbcellmap t_dbcellmap;
  class Class_dbfield;
  typedef std::shared_ptr<Class_dbfield> Type_dbfield;
  extern Type_dbfield e_dbfield;
  extern Type_dbfield t_dbfield;
  class Class_dbfieldmap;
  typedef std::shared_ptr<Class_dbfieldmap> Type_dbfieldmap;
  extern Type_dbfieldmap e_dbfieldmap;
  extern Type_dbfieldmap t_dbfieldmap;
  class Class_dbtable;
  typedef std::shared_ptr<Class_dbtable> Type_dbtable;
  extern Type_dbtable e_dbtable;
  extern Type_dbtable t_dbtable;


  // (type db)
  class Class_db : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key);
    // dbid()
    vx_core::Type_string vx_p_dbid;
    virtual vx_core::Type_string dbid();
  };

  // (type dbcell)
  class Class_dbcell : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key);
    // dbcellid()
    vx_core::Type_string vx_p_dbcellid;
    virtual vx_core::Type_string dbcellid();
    // dbcellmap()
    vx_data_db::Type_dbcellmap vx_p_dbcellmap;
    virtual vx_data_db::Type_dbcellmap dbcellmap();
    // dbfieldmap()
    vx_data_db::Type_dbfieldmap vx_p_dbfieldmap;
    virtual vx_data_db::Type_dbfieldmap dbfieldmap();
    // dbparent()
    vx_data_db::Type_dbcell vx_p_dbparent;
    virtual vx_data_db::Type_dbcell dbparent();
    // dbtable()
    vx_data_db::Type_dbtable vx_p_dbtable;
    virtual vx_data_db::Type_dbtable dbtable();
  };

  // (type dbcellmap)
  class Class_dbcellmap : public virtual vx_core::Class_map {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() override;
    // vx_new_from_map(T, Map<T>)
    template <class T> std::shared_ptr<T> vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval);
    std::map<std::string, vx_data_db::Type_dbcell> vx_p_map;
    // vx_mapdbcell()
    virtual std::map<std::string, vx_data_db::Type_dbcell> vx_mapdbcell();
    // vx_get_dbcell(key)
    virtual vx_data_db::Type_dbcell vx_get_dbcell(vx_core::Type_string key);
  };

  // (type dbfield)
  class Class_dbfield : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key);
    // dbfieldid()
    vx_core::Type_string vx_p_dbfieldid;
    virtual vx_core::Type_string dbfieldid();
    // type()
    vx_core::Type_any vx_p_type;
    virtual vx_core::Type_any type();
    // value()
    vx_core::Type_any vx_p_value;
    virtual vx_core::Type_any value();
  };

  // (type dbfieldmap)
  class Class_dbfieldmap : public virtual vx_core::Class_map {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() override;
    // vx_new_from_map(T, Map<T>)
    template <class T> std::shared_ptr<T> vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval);
    std::map<std::string, vx_data_db::Type_dbfield> vx_p_map;
    // vx_mapdbfield()
    virtual std::map<std::string, vx_data_db::Type_dbfield> vx_mapdbfield();
    // vx_get_dbfield(key)
    virtual vx_data_db::Type_dbfield vx_get_dbfield(vx_core::Type_string key);
  };

  // (type dbtable)
  class Class_dbtable : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key);
    // dbtableid()
    vx_core::Type_string vx_p_dbtableid;
    virtual vx_core::Type_string dbtableid();
    // db()
    vx_data_db::Type_db vx_p_db;
    virtual vx_data_db::Type_db db();
    // dbcellmap()
    vx_data_db::Type_dbcellmap vx_p_dbcellmap;
    virtual vx_data_db::Type_dbcellmap dbcellmap();
    // dbfieldmap()
    vx_data_db::Type_dbfieldmap vx_p_dbfieldmap;
    virtual vx_data_db::Type_dbfieldmap dbfieldmap();
  };

}
#endif
