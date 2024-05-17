#ifndef VX_DATA_DB_HPP
#define VX_DATA_DB_HPP
#include <map>
#include <string>
#include <vector>
#include "../../vx/core.hpp"

namespace vx_data_db {


  // forward declarations
  class Abstract_db;
  typedef Abstract_db* Type_db;
  extern Type_db e_db;
  extern Type_db t_db;
  class Abstract_dbcell;
  typedef Abstract_dbcell* Type_dbcell;
  extern Type_dbcell e_dbcell;
  extern Type_dbcell t_dbcell;
  class Abstract_dbcellmap;
  typedef Abstract_dbcellmap* Type_dbcellmap;
  extern Type_dbcellmap e_dbcellmap;
  extern Type_dbcellmap t_dbcellmap;
  class Abstract_dbfield;
  typedef Abstract_dbfield* Type_dbfield;
  extern Type_dbfield e_dbfield;
  extern Type_dbfield t_dbfield;
  class Abstract_dbfieldmap;
  typedef Abstract_dbfieldmap* Type_dbfieldmap;
  extern Type_dbfieldmap e_dbfieldmap;
  extern Type_dbfieldmap t_dbfieldmap;
  class Abstract_dbid;
  typedef Abstract_dbid* Type_dbid;
  extern Type_dbid e_dbid;
  extern Type_dbid t_dbid;
  class Abstract_dblink;
  typedef Abstract_dblink* Type_dblink;
  extern Type_dblink e_dblink;
  extern Type_dblink t_dblink;
  class Abstract_dblinklist;
  typedef Abstract_dblinklist* Type_dblinklist;
  extern Type_dblinklist e_dblinklist;
  extern Type_dblinklist t_dblinklist;
  class Abstract_dbnode;
  typedef Abstract_dbnode* Type_dbnode;
  extern Type_dbnode e_dbnode;
  extern Type_dbnode t_dbnode;
  class Abstract_dbnote;
  typedef Abstract_dbnote* Type_dbnote;
  extern Type_dbnote e_dbnote;
  extern Type_dbnote t_dbnote;
  class Abstract_dbtable;
  typedef Abstract_dbtable* Type_dbtable;
  extern Type_dbtable e_dbtable;
  extern Type_dbtable t_dbtable;
  class Abstract_dbvalue;
  typedef Abstract_dbvalue* Type_dbvalue;
  extern Type_dbvalue e_dbvalue;
  extern Type_dbvalue t_dbvalue;
  // (type db)
  class Abstract_db : public virtual vx_core::Abstract_struct {
  public:
    Abstract_db() {};
    virtual ~Abstract_db() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // dbid()
    vx_core::Type_string vx_p_dbid = NULL;
    virtual vx_core::Type_string dbid() const = 0;
  };
  class Class_db : public virtual Abstract_db {
  public:
    Class_db();
    virtual ~Class_db() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string dbid() const override;
  };

  // (type dbcell)
  class Abstract_dbcell : public virtual vx_core::Abstract_struct {
  public:
    Abstract_dbcell() {};
    virtual ~Abstract_dbcell() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // dbcellid()
    vx_core::Type_string vx_p_dbcellid = NULL;
    virtual vx_core::Type_string dbcellid() const = 0;
    // dbcellmap()
    vx_data_db::Type_dbcellmap vx_p_dbcellmap = NULL;
    virtual vx_data_db::Type_dbcellmap dbcellmap() const = 0;
    // dbfieldmap()
    vx_data_db::Type_dbfieldmap vx_p_dbfieldmap = NULL;
    virtual vx_data_db::Type_dbfieldmap dbfieldmap() const = 0;
    // dbparent()
    vx_data_db::Type_dbcell vx_p_dbparent = NULL;
    virtual vx_data_db::Type_dbcell dbparent() const = 0;
    // dbtable()
    vx_data_db::Type_dbtable vx_p_dbtable = NULL;
    virtual vx_data_db::Type_dbtable dbtable() const = 0;
  };
  class Class_dbcell : public virtual Abstract_dbcell {
  public:
    Class_dbcell();
    virtual ~Class_dbcell() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string dbcellid() const override;
    virtual vx_data_db::Type_dbcellmap dbcellmap() const override;
    virtual vx_data_db::Type_dbfieldmap dbfieldmap() const override;
    virtual vx_data_db::Type_dbcell dbparent() const override;
    virtual vx_data_db::Type_dbtable dbtable() const override;
  };

  // (type dbcellmap)
  class Abstract_dbcellmap : public virtual vx_core::Abstract_map {
  public:
    Abstract_dbcellmap() {};
    virtual ~Abstract_dbcellmap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_set(name, value)
    virtual vx_core::Type_boolean vx_set(vx_core::Type_string name, vx_core::Type_any value) = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
    std::map<std::string, vx_data_db::Type_dbcell> vx_p_map;
    // vx_mapdbcell()
    virtual std::map<std::string, vx_data_db::Type_dbcell> vx_mapdbcell() const = 0;
    // vx_get_dbcell(key)
    virtual vx_data_db::Type_dbcell vx_get_dbcell(vx_core::Type_string key) const = 0;
  };
  class Class_dbcellmap : public virtual Abstract_dbcellmap {
  public:
    Class_dbcellmap();
    virtual ~Class_dbcellmap() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_boolean vx_set(vx_core::Type_string name, vx_core::Type_any value) override;
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const override;
    virtual std::map<std::string, vx_data_db::Type_dbcell> vx_mapdbcell() const override;
    virtual vx_data_db::Type_dbcell vx_get_dbcell(vx_core::Type_string key) const override;
  };

  // (type dbfield)
  class Abstract_dbfield : public virtual vx_core::Abstract_struct {
  public:
    Abstract_dbfield() {};
    virtual ~Abstract_dbfield() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // dbfieldid()
    vx_core::Type_string vx_p_dbfieldid = NULL;
    virtual vx_core::Type_string dbfieldid() const = 0;
    // type()
    vx_core::Type_any vx_p_type = NULL;
    virtual vx_core::Type_any type() const = 0;
    // value()
    vx_core::Type_any vx_p_value = NULL;
    virtual vx_core::Type_any value() const = 0;
  };
  class Class_dbfield : public virtual Abstract_dbfield {
  public:
    Class_dbfield();
    virtual ~Class_dbfield() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string dbfieldid() const override;
    virtual vx_core::Type_any type() const override;
    virtual vx_core::Type_any value() const override;
  };

  // (type dbfieldmap)
  class Abstract_dbfieldmap : public virtual vx_core::Abstract_map {
  public:
    Abstract_dbfieldmap() {};
    virtual ~Abstract_dbfieldmap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_set(name, value)
    virtual vx_core::Type_boolean vx_set(vx_core::Type_string name, vx_core::Type_any value) = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
    std::map<std::string, vx_data_db::Type_dbfield> vx_p_map;
    // vx_mapdbfield()
    virtual std::map<std::string, vx_data_db::Type_dbfield> vx_mapdbfield() const = 0;
    // vx_get_dbfield(key)
    virtual vx_data_db::Type_dbfield vx_get_dbfield(vx_core::Type_string key) const = 0;
  };
  class Class_dbfieldmap : public virtual Abstract_dbfieldmap {
  public:
    Class_dbfieldmap();
    virtual ~Class_dbfieldmap() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_boolean vx_set(vx_core::Type_string name, vx_core::Type_any value) override;
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const override;
    virtual std::map<std::string, vx_data_db::Type_dbfield> vx_mapdbfield() const override;
    virtual vx_data_db::Type_dbfield vx_get_dbfield(vx_core::Type_string key) const override;
  };

  // (type dbid)
  class Abstract_dbid : public virtual vx_core::Abstract_any {
  public:
    Abstract_dbid() {};
    virtual ~Abstract_dbid() = 0;
  };
  class Class_dbid : public virtual Abstract_dbid {
  public:
    Class_dbid();
    virtual ~Class_dbid() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type dblink)
  class Abstract_dblink : public virtual vx_core::Abstract_struct {
  public:
    Abstract_dblink() {};
    virtual ~Abstract_dblink() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // fromid()
    vx_data_db::Type_dbid vx_p_fromid = NULL;
    virtual vx_data_db::Type_dbid fromid() const = 0;
    // toid()
    vx_data_db::Type_dbid vx_p_toid = NULL;
    virtual vx_data_db::Type_dbid toid() const = 0;
  };
  class Class_dblink : public virtual Abstract_dblink {
  public:
    Class_dblink();
    virtual ~Class_dblink() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_data_db::Type_dbid fromid() const override;
    virtual vx_data_db::Type_dbid toid() const override;
  };

  // (type dblinklist)
  class Abstract_dblinklist : public virtual vx_core::Abstract_list {
  public:
    Abstract_dblinklist() {};
    virtual ~Abstract_dblinklist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_data_db::Type_dblink> vx_p_list;
    // vx_listdblink()
    virtual std::vector<vx_data_db::Type_dblink> vx_listdblink() const = 0;
    // vx_get_dblink(index)
    virtual vx_data_db::Type_dblink vx_get_dblink(vx_core::Type_int index) const = 0;
  };
  class Class_dblinklist : public virtual Abstract_dblinklist {
  public:
    Class_dblinklist();
    virtual ~Class_dblinklist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
    virtual std::vector<vx_data_db::Type_dblink> vx_listdblink() const override;
    virtual vx_data_db::Type_dblink vx_get_dblink(vx_core::Type_int index) const override;
  };

  // (type dbnode)
  class Abstract_dbnode : public virtual vx_core::Abstract_struct {
  public:
    Abstract_dbnode() {};
    virtual ~Abstract_dbnode() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // dbid()
    vx_data_db::Type_dbid vx_p_dbid = NULL;
    virtual vx_data_db::Type_dbid dbid() const = 0;
    // links()
    vx_data_db::Type_dblinklist vx_p_links = NULL;
    virtual vx_data_db::Type_dblinklist links() const = 0;
  };
  class Class_dbnode : public virtual Abstract_dbnode {
  public:
    Class_dbnode();
    virtual ~Class_dbnode() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_data_db::Type_dbid dbid() const override;
    virtual vx_data_db::Type_dblinklist links() const override;
  };

  // (type dbnote)
  class Abstract_dbnote : public virtual vx_core::Abstract_struct {
  public:
    Abstract_dbnote() {};
    virtual ~Abstract_dbnote() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // dbid()
    vx_data_db::Type_dbid vx_p_dbid = NULL;
    virtual vx_data_db::Type_dbid dbid() const = 0;
    // valid()
    vx_data_db::Type_dbid vx_p_valid = NULL;
    virtual vx_data_db::Type_dbid valid() const = 0;
    // noteid()
    vx_data_db::Type_dbid vx_p_noteid = NULL;
    virtual vx_data_db::Type_dbid noteid() const = 0;
    // valueid()
    vx_data_db::Type_dbid vx_p_valueid = NULL;
    virtual vx_data_db::Type_dbid valueid() const = 0;
    // value()
    vx_core::Type_string vx_p_value = NULL;
    virtual vx_core::Type_string value() const = 0;
  };
  class Class_dbnote : public virtual Abstract_dbnote {
  public:
    Class_dbnote();
    virtual ~Class_dbnote() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_data_db::Type_dbid dbid() const override;
    virtual vx_data_db::Type_dbid valid() const override;
    virtual vx_data_db::Type_dbid noteid() const override;
    virtual vx_data_db::Type_dbid valueid() const override;
    virtual vx_core::Type_string value() const override;
  };

  // (type dbtable)
  class Abstract_dbtable : public virtual vx_core::Abstract_struct {
  public:
    Abstract_dbtable() {};
    virtual ~Abstract_dbtable() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // dbtableid()
    vx_core::Type_string vx_p_dbtableid = NULL;
    virtual vx_core::Type_string dbtableid() const = 0;
    // db()
    vx_data_db::Type_db vx_p_db = NULL;
    virtual vx_data_db::Type_db db() const = 0;
    // dbcellmap()
    vx_data_db::Type_dbcellmap vx_p_dbcellmap = NULL;
    virtual vx_data_db::Type_dbcellmap dbcellmap() const = 0;
    // dbfieldmap()
    vx_data_db::Type_dbfieldmap vx_p_dbfieldmap = NULL;
    virtual vx_data_db::Type_dbfieldmap dbfieldmap() const = 0;
  };
  class Class_dbtable : public virtual Abstract_dbtable {
  public:
    Class_dbtable();
    virtual ~Class_dbtable() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string dbtableid() const override;
    virtual vx_data_db::Type_db db() const override;
    virtual vx_data_db::Type_dbcellmap dbcellmap() const override;
    virtual vx_data_db::Type_dbfieldmap dbfieldmap() const override;
  };

  // (type dbvalue)
  class Abstract_dbvalue : public virtual vx_core::Abstract_struct {
  public:
    Abstract_dbvalue() {};
    virtual ~Abstract_dbvalue() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // dbid()
    vx_data_db::Type_dbid vx_p_dbid = NULL;
    virtual vx_data_db::Type_dbid dbid() const = 0;
    // fromid()
    vx_data_db::Type_dbid vx_p_fromid = NULL;
    virtual vx_data_db::Type_dbid fromid() const = 0;
    // toid()
    vx_data_db::Type_dbid vx_p_toid = NULL;
    virtual vx_data_db::Type_dbid toid() const = 0;
    // noteid()
    vx_data_db::Type_dbid vx_p_noteid = NULL;
    virtual vx_data_db::Type_dbid noteid() const = 0;
    // valid()
    vx_data_db::Type_dbid vx_p_valid = NULL;
    virtual vx_data_db::Type_dbid valid() const = 0;
    // valtext()
    vx_core::Type_string vx_p_valtext = NULL;
    virtual vx_core::Type_string valtext() const = 0;
  };
  class Class_dbvalue : public virtual Abstract_dbvalue {
  public:
    Class_dbvalue();
    virtual ~Class_dbvalue() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_data_db::Type_dbid dbid() const override;
    virtual vx_data_db::Type_dbid fromid() const override;
    virtual vx_data_db::Type_dbid toid() const override;
    virtual vx_data_db::Type_dbid noteid() const override;
    virtual vx_data_db::Type_dbid valid() const override;
    virtual vx_core::Type_string valtext() const override;
  };

  class vx_Class_package {
  public:
    vx_Class_package();
    void init();
  };
  inline vx_Class_package const vx_package;

}

#endif
