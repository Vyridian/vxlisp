#ifndef VX_DATA_TABLE_HPP
#define VX_DATA_TABLE_HPP
#include <map>
#include <string>
#include <vector>
#include "../../vx/core.hpp"

namespace vx_data_table {


  // forward declarations
  class Abstract_cell;
  typedef Abstract_cell* Type_cell;
  extern Type_cell e_cell;
  extern Type_cell t_cell;
  class Abstract_celllist;
  typedef Abstract_celllist* Type_celllist;
  extern Type_celllist e_celllist;
  extern Type_celllist t_celllist;
  class Abstract_cellmap;
  typedef Abstract_cellmap* Type_cellmap;
  extern Type_cellmap e_cellmap;
  extern Type_cellmap t_cellmap;
  class Abstract_field;
  typedef Abstract_field* Type_field;
  extern Type_field e_field;
  extern Type_field t_field;
  class Abstract_fieldlist;
  typedef Abstract_fieldlist* Type_fieldlist;
  extern Type_fieldlist e_fieldlist;
  extern Type_fieldlist t_fieldlist;
  class Abstract_fieldmap;
  typedef Abstract_fieldmap* Type_fieldmap;
  extern Type_fieldmap e_fieldmap;
  extern Type_fieldmap t_fieldmap;
  class Abstract_filter;
  typedef Abstract_filter* Type_filter;
  extern Type_filter e_filter;
  extern Type_filter t_filter;
  class Abstract_row;
  typedef Abstract_row* Type_row;
  extern Type_row e_row;
  extern Type_row t_row;
  class Abstract_rowlist;
  typedef Abstract_rowlist* Type_rowlist;
  extern Type_rowlist e_rowlist;
  extern Type_rowlist t_rowlist;
  class Abstract_rowmap;
  typedef Abstract_rowmap* Type_rowmap;
  extern Type_rowmap e_rowmap;
  extern Type_rowmap t_rowmap;
  class Abstract_sort;
  typedef Abstract_sort* Type_sort;
  extern Type_sort e_sort;
  extern Type_sort t_sort;
  class Abstract_table;
  typedef Abstract_table* Type_table;
  extern Type_table e_table;
  extern Type_table t_table;
  // (type cell)
  class Abstract_cell : public virtual vx_core::Abstract_struct {
  public:
    Abstract_cell() {};
    virtual ~Abstract_cell() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // id()
    vx_core::Type_string vx_p_id = NULL;
    virtual vx_core::Type_string id() const = 0;
    // value()
    vx_core::Type_any vx_p_value = NULL;
    virtual vx_core::Type_any value() const = 0;
  };
  class Class_cell : public virtual Abstract_cell {
  public:
    Class_cell();
    virtual ~Class_cell() override;
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
    virtual vx_core::Type_string id() const override;
    virtual vx_core::Type_any value() const override;
  };

  // (type celllist)
  class Abstract_celllist : public virtual vx_core::Abstract_list {
  public:
    Abstract_celllist() {};
    virtual ~Abstract_celllist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_data_table::Type_cell> vx_p_list;
    // vx_listcell()
    virtual std::vector<vx_data_table::Type_cell> vx_listcell() const = 0;
    // vx_get_cell(index)
    virtual vx_data_table::Type_cell vx_get_cell(vx_core::Type_int index) const = 0;
  };
  class Class_celllist : public virtual Abstract_celllist {
  public:
    Class_celllist();
    virtual ~Class_celllist() override;
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
    virtual std::vector<vx_data_table::Type_cell> vx_listcell() const override;
    virtual vx_data_table::Type_cell vx_get_cell(vx_core::Type_int index) const override;
  };

  // (type cellmap)
  class Abstract_cellmap : public virtual vx_core::Abstract_map {
  public:
    Abstract_cellmap() {};
    virtual ~Abstract_cellmap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_set(name, value)
    virtual vx_core::Type_boolean vx_set(vx_core::Type_string name, vx_core::Type_any value) = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
    std::map<std::string, vx_data_table::Type_cell> vx_p_map;
    // vx_mapcell()
    virtual std::map<std::string, vx_data_table::Type_cell> vx_mapcell() const = 0;
    // vx_get_cell(key)
    virtual vx_data_table::Type_cell vx_get_cell(vx_core::Type_string key) const = 0;
  };
  class Class_cellmap : public virtual Abstract_cellmap {
  public:
    Class_cellmap();
    virtual ~Class_cellmap() override;
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
    virtual std::map<std::string, vx_data_table::Type_cell> vx_mapcell() const override;
    virtual vx_data_table::Type_cell vx_get_cell(vx_core::Type_string key) const override;
  };

  // (type field)
  class Abstract_field : public virtual vx_core::Abstract_struct {
  public:
    Abstract_field() {};
    virtual ~Abstract_field() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // id()
    vx_core::Type_string vx_p_id = NULL;
    virtual vx_core::Type_string id() const = 0;
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
    // fldtype()
    vx_core::Type_any vx_p_fldtype = NULL;
    virtual vx_core::Type_any fldtype() const = 0;
  };
  class Class_field : public virtual Abstract_field {
  public:
    Class_field();
    virtual ~Class_field() override;
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
    virtual vx_core::Type_string id() const override;
    virtual vx_core::Type_string name() const override;
    virtual vx_core::Type_any fldtype() const override;
  };

  // (type fieldlist)
  class Abstract_fieldlist : public virtual vx_core::Abstract_list {
  public:
    Abstract_fieldlist() {};
    virtual ~Abstract_fieldlist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_data_table::Type_field> vx_p_list;
    // vx_listfield()
    virtual std::vector<vx_data_table::Type_field> vx_listfield() const = 0;
    // vx_get_field(index)
    virtual vx_data_table::Type_field vx_get_field(vx_core::Type_int index) const = 0;
  };
  class Class_fieldlist : public virtual Abstract_fieldlist {
  public:
    Class_fieldlist();
    virtual ~Class_fieldlist() override;
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
    virtual std::vector<vx_data_table::Type_field> vx_listfield() const override;
    virtual vx_data_table::Type_field vx_get_field(vx_core::Type_int index) const override;
  };

  // (type fieldmap)
  class Abstract_fieldmap : public virtual vx_core::Abstract_list {
  public:
    Abstract_fieldmap() {};
    virtual ~Abstract_fieldmap() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_data_table::Type_field> vx_p_list;
    // vx_listfield()
    virtual std::vector<vx_data_table::Type_field> vx_listfield() const = 0;
    // vx_get_field(index)
    virtual vx_data_table::Type_field vx_get_field(vx_core::Type_int index) const = 0;
  };
  class Class_fieldmap : public virtual Abstract_fieldmap {
  public:
    Class_fieldmap();
    virtual ~Class_fieldmap() override;
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
    virtual std::vector<vx_data_table::Type_field> vx_listfield() const override;
    virtual vx_data_table::Type_field vx_get_field(vx_core::Type_int index) const override;
  };

  // (type filter)
  class Abstract_filter : public virtual vx_core::Abstract_struct {
  public:
    Abstract_filter() {};
    virtual ~Abstract_filter() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // id()
    vx_core::Type_string vx_p_id = NULL;
    virtual vx_core::Type_string id() const = 0;
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
    // idlist()
    vx_core::Type_stringlist vx_p_idlist = NULL;
    virtual vx_core::Type_stringlist idlist() const = 0;
  };
  class Class_filter : public virtual Abstract_filter {
  public:
    Class_filter();
    virtual ~Class_filter() override;
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
    virtual vx_core::Type_string id() const override;
    virtual vx_core::Type_string name() const override;
    virtual vx_core::Type_stringlist idlist() const override;
  };

  // (type row)
  class Abstract_row : public virtual vx_core::Abstract_struct {
  public:
    Abstract_row() {};
    virtual ~Abstract_row() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // id()
    vx_core::Type_string vx_p_id = NULL;
    virtual vx_core::Type_string id() const = 0;
    // cellmap()
    vx_data_table::Type_cellmap vx_p_cellmap = NULL;
    virtual vx_data_table::Type_cellmap cellmap() const = 0;
    // cellsort()
    vx_data_table::Type_sort vx_p_cellsort = NULL;
    virtual vx_data_table::Type_sort cellsort() const = 0;
  };
  class Class_row : public virtual Abstract_row {
  public:
    Class_row();
    virtual ~Class_row() override;
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
    virtual vx_core::Type_string id() const override;
    virtual vx_data_table::Type_cellmap cellmap() const override;
    virtual vx_data_table::Type_sort cellsort() const override;
  };

  // (type rowlist)
  class Abstract_rowlist : public virtual vx_core::Abstract_list {
  public:
    Abstract_rowlist() {};
    virtual ~Abstract_rowlist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_data_table::Type_row> vx_p_list;
    // vx_listrow()
    virtual std::vector<vx_data_table::Type_row> vx_listrow() const = 0;
    // vx_get_row(index)
    virtual vx_data_table::Type_row vx_get_row(vx_core::Type_int index) const = 0;
  };
  class Class_rowlist : public virtual Abstract_rowlist {
  public:
    Class_rowlist();
    virtual ~Class_rowlist() override;
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
    virtual std::vector<vx_data_table::Type_row> vx_listrow() const override;
    virtual vx_data_table::Type_row vx_get_row(vx_core::Type_int index) const override;
  };

  // (type rowmap)
  class Abstract_rowmap : public virtual vx_core::Abstract_map {
  public:
    Abstract_rowmap() {};
    virtual ~Abstract_rowmap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_set(name, value)
    virtual vx_core::Type_boolean vx_set(vx_core::Type_string name, vx_core::Type_any value) = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
    std::map<std::string, vx_data_table::Type_row> vx_p_map;
    // vx_maprow()
    virtual std::map<std::string, vx_data_table::Type_row> vx_maprow() const = 0;
    // vx_get_row(key)
    virtual vx_data_table::Type_row vx_get_row(vx_core::Type_string key) const = 0;
  };
  class Class_rowmap : public virtual Abstract_rowmap {
  public:
    Class_rowmap();
    virtual ~Class_rowmap() override;
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
    virtual std::map<std::string, vx_data_table::Type_row> vx_maprow() const override;
    virtual vx_data_table::Type_row vx_get_row(vx_core::Type_string key) const override;
  };

  // (type sort)
  class Abstract_sort : public virtual vx_core::Abstract_struct {
  public:
    Abstract_sort() {};
    virtual ~Abstract_sort() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // id()
    vx_core::Type_string vx_p_id = NULL;
    virtual vx_core::Type_string id() const = 0;
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
    // idlist()
    vx_core::Type_stringlist vx_p_idlist = NULL;
    virtual vx_core::Type_stringlist idlist() const = 0;
  };
  class Class_sort : public virtual Abstract_sort {
  public:
    Class_sort();
    virtual ~Class_sort() override;
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
    virtual vx_core::Type_string id() const override;
    virtual vx_core::Type_string name() const override;
    virtual vx_core::Type_stringlist idlist() const override;
  };

  // (type table)
  class Abstract_table : public virtual vx_core::Abstract_struct {
  public:
    Abstract_table() {};
    virtual ~Abstract_table() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // id()
    vx_core::Type_string vx_p_id = NULL;
    virtual vx_core::Type_string id() const = 0;
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
    // fieldmap()
    vx_data_table::Type_fieldmap vx_p_fieldmap = NULL;
    virtual vx_data_table::Type_fieldmap fieldmap() const = 0;
    // fieldsort()
    vx_data_table::Type_sort vx_p_fieldsort = NULL;
    virtual vx_data_table::Type_sort fieldsort() const = 0;
    // rowmap()
    vx_data_table::Type_rowmap vx_p_rowmap = NULL;
    virtual vx_data_table::Type_rowmap rowmap() const = 0;
    // rowfilter()
    vx_data_table::Type_filter vx_p_rowfilter = NULL;
    virtual vx_data_table::Type_filter rowfilter() const = 0;
    // rowsort()
    vx_data_table::Type_sort vx_p_rowsort = NULL;
    virtual vx_data_table::Type_sort rowsort() const = 0;
  };
  class Class_table : public virtual Abstract_table {
  public:
    Class_table();
    virtual ~Class_table() override;
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
    virtual vx_core::Type_string id() const override;
    virtual vx_core::Type_string name() const override;
    virtual vx_data_table::Type_fieldmap fieldmap() const override;
    virtual vx_data_table::Type_sort fieldsort() const override;
    virtual vx_data_table::Type_rowmap rowmap() const override;
    virtual vx_data_table::Type_filter rowfilter() const override;
    virtual vx_data_table::Type_sort rowsort() const override;
  };

  class vx_Class_package {
  public:
    vx_Class_package();
    void init();
  };
  inline vx_Class_package const vx_package;

}

#endif
