#pragma once
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>
#include "../../vx/core.hpp"

namespace vx_data_table {

  // forward declarations
  class Class_cell;
  typedef std::shared_ptr<Class_cell> Type_cell;
  extern Type_cell e_cell;
  extern Type_cell t_cell;
  class Class_celllist;
  typedef std::shared_ptr<Class_celllist> Type_celllist;
  extern Type_celllist e_celllist;
  extern Type_celllist t_celllist;
  class Class_cellmap;
  typedef std::shared_ptr<Class_cellmap> Type_cellmap;
  extern Type_cellmap e_cellmap;
  extern Type_cellmap t_cellmap;
  class Class_field;
  typedef std::shared_ptr<Class_field> Type_field;
  extern Type_field e_field;
  extern Type_field t_field;
  class Class_fieldlist;
  typedef std::shared_ptr<Class_fieldlist> Type_fieldlist;
  extern Type_fieldlist e_fieldlist;
  extern Type_fieldlist t_fieldlist;
  class Class_fieldmap;
  typedef std::shared_ptr<Class_fieldmap> Type_fieldmap;
  extern Type_fieldmap e_fieldmap;
  extern Type_fieldmap t_fieldmap;
  class Class_filter;
  typedef std::shared_ptr<Class_filter> Type_filter;
  extern Type_filter e_filter;
  extern Type_filter t_filter;
  class Class_row;
  typedef std::shared_ptr<Class_row> Type_row;
  extern Type_row e_row;
  extern Type_row t_row;
  class Class_rowlist;
  typedef std::shared_ptr<Class_rowlist> Type_rowlist;
  extern Type_rowlist e_rowlist;
  extern Type_rowlist t_rowlist;
  class Class_rowmap;
  typedef std::shared_ptr<Class_rowmap> Type_rowmap;
  extern Type_rowmap e_rowmap;
  extern Type_rowmap t_rowmap;
  class Class_sort;
  typedef std::shared_ptr<Class_sort> Type_sort;
  extern Type_sort e_sort;
  extern Type_sort t_sort;
  class Class_table;
  typedef std::shared_ptr<Class_table> Type_table;
  extern Type_table e_table;
  extern Type_table t_table;


  // (type cell)
  class Class_cell : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // id()
    vx_core::Type_string vx_p_id;
    virtual vx_core::Type_string id();
    // value()
    vx_core::Type_any vx_p_value;
    virtual vx_core::Type_any value();
  };

  // (type celllist)
  class Class_celllist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_data_table::Type_cell> vx_p_list;

    // vx_listcell()
    virtual std::vector<vx_data_table::Type_cell> vx_listcell();
    // vx_cell(index)
    virtual vx_data_table::Type_cell vx_cell(vx_core::Type_int index);
  };

  // (type cellmap)
  class Class_cellmap : public virtual vx_core::Class_map {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key) override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() override;
    // vx_new_from_map(T, Map<T>)
    template <class T> std::shared_ptr<T> vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval);
    std::map<std::string, vx_data_table::Type_cell> vx_p_map;
    // vx_mapcell()
    virtual std::map<std::string, vx_data_table::Type_cell> vx_mapcell();
    // vx_cell(key)
    virtual vx_data_table::Type_cell vx_cell(vx_core::Type_string key);
  };

  // (type field)
  class Class_field : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // id()
    vx_core::Type_string vx_p_id;
    virtual vx_core::Type_string id();
    // name()
    vx_core::Type_string vx_p_name;
    virtual vx_core::Type_string name();
    // fldtype()
    vx_core::Type_any vx_p_fldtype;
    virtual vx_core::Type_any fldtype();
  };

  // (type fieldlist)
  class Class_fieldlist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_data_table::Type_field> vx_p_list;

    // vx_listfield()
    virtual std::vector<vx_data_table::Type_field> vx_listfield();
    // vx_field(index)
    virtual vx_data_table::Type_field vx_field(vx_core::Type_int index);
  };

  // (type fieldmap)
  class Class_fieldmap : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_data_table::Type_field> vx_p_list;

    // vx_listfield()
    virtual std::vector<vx_data_table::Type_field> vx_listfield();
    // vx_field(index)
    virtual vx_data_table::Type_field vx_field(vx_core::Type_int index);
  };

  // (type filter)
  class Class_filter : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // id()
    vx_core::Type_string vx_p_id;
    virtual vx_core::Type_string id();
    // name()
    vx_core::Type_string vx_p_name;
    virtual vx_core::Type_string name();
    // idlist()
    vx_core::Type_stringlist vx_p_idlist;
    virtual vx_core::Type_stringlist idlist();
  };

  // (type row)
  class Class_row : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // id()
    vx_core::Type_string vx_p_id;
    virtual vx_core::Type_string id();
    // cellmap()
    vx_data_table::Type_cellmap vx_p_cellmap;
    virtual vx_data_table::Type_cellmap cellmap();
    // cellsort()
    vx_data_table::Type_sort vx_p_cellsort;
    virtual vx_data_table::Type_sort cellsort();
  };

  // (type rowlist)
  class Class_rowlist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_data_table::Type_row> vx_p_list;

    // vx_listrow()
    virtual std::vector<vx_data_table::Type_row> vx_listrow();
    // vx_row(index)
    virtual vx_data_table::Type_row vx_row(vx_core::Type_int index);
  };

  // (type rowmap)
  class Class_rowmap : public virtual vx_core::Class_map {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key) override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() override;
    // vx_new_from_map(T, Map<T>)
    template <class T> std::shared_ptr<T> vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval);
    std::map<std::string, vx_data_table::Type_row> vx_p_map;
    // vx_maprow()
    virtual std::map<std::string, vx_data_table::Type_row> vx_maprow();
    // vx_row(key)
    virtual vx_data_table::Type_row vx_row(vx_core::Type_string key);
  };

  // (type sort)
  class Class_sort : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // id()
    vx_core::Type_string vx_p_id;
    virtual vx_core::Type_string id();
    // name()
    vx_core::Type_string vx_p_name;
    virtual vx_core::Type_string name();
    // idlist()
    vx_core::Type_stringlist vx_p_idlist;
    virtual vx_core::Type_stringlist idlist();
  };

  // (type table)
  class Class_table : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // id()
    vx_core::Type_string vx_p_id;
    virtual vx_core::Type_string id();
    // name()
    vx_core::Type_string vx_p_name;
    virtual vx_core::Type_string name();
    // fieldmap()
    vx_data_table::Type_fieldmap vx_p_fieldmap;
    virtual vx_data_table::Type_fieldmap fieldmap();
    // fieldsort()
    vx_data_table::Type_sort vx_p_fieldsort;
    virtual vx_data_table::Type_sort fieldsort();
    // rowmap()
    vx_data_table::Type_rowmap vx_p_rowmap;
    virtual vx_data_table::Type_rowmap rowmap();
    // rowfilter()
    vx_data_table::Type_filter vx_p_rowfilter;
    virtual vx_data_table::Type_filter rowfilter();
    // rowsort()
    vx_data_table::Type_sort vx_p_rowsort;
    virtual vx_data_table::Type_sort rowsort();
  };

}
