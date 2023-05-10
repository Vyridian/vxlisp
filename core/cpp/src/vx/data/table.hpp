#pragma once
#include <any>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "../../vx/core.hpp"

namespace vx_data_table {

  // forward declarations
  class Type_cell;
  extern Type_cell* e_cell;
  extern Type_cell* t_cell;
  class Type_celllist;
  extern Type_celllist* e_celllist;
  extern Type_celllist* t_celllist;
  class Type_cellmap;
  extern Type_cellmap* e_cellmap;
  extern Type_cellmap* t_cellmap;
  class Type_field;
  extern Type_field* e_field;
  extern Type_field* t_field;
  class Type_fieldlist;
  extern Type_fieldlist* e_fieldlist;
  extern Type_fieldlist* t_fieldlist;
  class Type_fieldmap;
  extern Type_fieldmap* e_fieldmap;
  extern Type_fieldmap* t_fieldmap;
  class Type_filter;
  extern Type_filter* e_filter;
  extern Type_filter* t_filter;
  class Type_row;
  extern Type_row* e_row;
  extern Type_row* t_row;
  class Type_rowlist;
  extern Type_rowlist* e_rowlist;
  extern Type_rowlist* t_rowlist;
  class Type_rowmap;
  extern Type_rowmap* e_rowmap;
  extern Type_rowmap* t_rowmap;
  class Type_sort;
  extern Type_sort* e_sort;
  extern Type_sort* t_sort;
  class Type_table;
  extern Type_table* e_table;
  extern Type_table* t_table;


  // (type cell)
  class Type_cell : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_data_table::Type_cell* vx_new(Args*... args);
    template<class... Args> vx_data_table::Type_cell* vx_copy(Args*... args);
    virtual vx_data_table::Type_cell* vx_empty();
    virtual vx_data_table::Type_cell* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // id()
    vx_core::Type_string* vx_p_id;
    virtual vx_core::Type_string* id();
    // value()
    vx_core::Type_any* vx_p_value;
    virtual vx_core::Type_any* value();
  };

  // (type celllist)
  class Type_celllist : public virtual vx_core::Type_list {
  public:
    template<class... Args> vx_data_table::Type_celllist* vx_new(Args*... args);
    template<class... Args> vx_data_table::Type_celllist* vx_copy(Args*... args);
    virtual vx_data_table::Type_celllist* vx_empty();
    virtual vx_data_table::Type_celllist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_data_table::Type_cell*> vx_p_list;

    // vx_listcell()
    virtual std::vector<vx_data_table::Type_cell*> vx_listcell();
    // vx_cell(index)
    virtual vx_data_table::Type_cell* vx_cell(vx_core::Type_int* index);
  };

  // (type cellmap)
  class Type_cellmap : public virtual vx_core::Type_map {
  public:
    template<class... Args> vx_data_table::Type_cellmap* vx_new(Args*... args);
    template<class... Args> vx_data_table::Type_cellmap* vx_copy(Args*... args);
    virtual vx_data_table::Type_cellmap* vx_empty();
    virtual vx_data_table::Type_cellmap* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    std::map<std::string, vx_data_table::Type_cell*> vx_p_map;
    // vx_mapcell()
    virtual std::map<std::string, vx_data_table::Type_cell*> vx_mapcell();
    // vx_cell(key)
    virtual vx_data_table::Type_cell* vx_cell(vx_core::Type_string* key);
    virtual vx_data_table::Type_cellmap* vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval);
  };

  // (type field)
  class Type_field : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_data_table::Type_field* vx_new(Args*... args);
    template<class... Args> vx_data_table::Type_field* vx_copy(Args*... args);
    virtual vx_data_table::Type_field* vx_empty();
    virtual vx_data_table::Type_field* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // id()
    vx_core::Type_string* vx_p_id;
    virtual vx_core::Type_string* id();
    // name()
    vx_core::Type_string* vx_p_name;
    virtual vx_core::Type_string* name();
    // fldtype()
    vx_core::Type_any* vx_p_fldtype;
    virtual vx_core::Type_any* fldtype();
  };

  // (type fieldlist)
  class Type_fieldlist : public virtual vx_core::Type_list {
  public:
    template<class... Args> vx_data_table::Type_fieldlist* vx_new(Args*... args);
    template<class... Args> vx_data_table::Type_fieldlist* vx_copy(Args*... args);
    virtual vx_data_table::Type_fieldlist* vx_empty();
    virtual vx_data_table::Type_fieldlist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_data_table::Type_field*> vx_p_list;

    // vx_listfield()
    virtual std::vector<vx_data_table::Type_field*> vx_listfield();
    // vx_field(index)
    virtual vx_data_table::Type_field* vx_field(vx_core::Type_int* index);
  };

  // (type fieldmap)
  class Type_fieldmap : public virtual vx_core::Type_list {
  public:
    template<class... Args> vx_data_table::Type_fieldmap* vx_new(Args*... args);
    template<class... Args> vx_data_table::Type_fieldmap* vx_copy(Args*... args);
    virtual vx_data_table::Type_fieldmap* vx_empty();
    virtual vx_data_table::Type_fieldmap* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_data_table::Type_field*> vx_p_list;

    // vx_listfield()
    virtual std::vector<vx_data_table::Type_field*> vx_listfield();
    // vx_field(index)
    virtual vx_data_table::Type_field* vx_field(vx_core::Type_int* index);
  };

  // (type filter)
  class Type_filter : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_data_table::Type_filter* vx_new(Args*... args);
    template<class... Args> vx_data_table::Type_filter* vx_copy(Args*... args);
    virtual vx_data_table::Type_filter* vx_empty();
    virtual vx_data_table::Type_filter* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // id()
    vx_core::Type_string* vx_p_id;
    virtual vx_core::Type_string* id();
    // name()
    vx_core::Type_string* vx_p_name;
    virtual vx_core::Type_string* name();
    // idlist()
    vx_core::Type_stringlist* vx_p_idlist;
    virtual vx_core::Type_stringlist* idlist();
  };

  // (type row)
  class Type_row : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_data_table::Type_row* vx_new(Args*... args);
    template<class... Args> vx_data_table::Type_row* vx_copy(Args*... args);
    virtual vx_data_table::Type_row* vx_empty();
    virtual vx_data_table::Type_row* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // id()
    vx_core::Type_string* vx_p_id;
    virtual vx_core::Type_string* id();
    // cellmap()
    vx_data_table::Type_cellmap* vx_p_cellmap;
    virtual vx_data_table::Type_cellmap* cellmap();
    // cellsort()
    vx_data_table::Type_sort* vx_p_cellsort;
    virtual vx_data_table::Type_sort* cellsort();
  };

  // (type rowlist)
  class Type_rowlist : public virtual vx_core::Type_list {
  public:
    template<class... Args> vx_data_table::Type_rowlist* vx_new(Args*... args);
    template<class... Args> vx_data_table::Type_rowlist* vx_copy(Args*... args);
    virtual vx_data_table::Type_rowlist* vx_empty();
    virtual vx_data_table::Type_rowlist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_data_table::Type_row*> vx_p_list;

    // vx_listrow()
    virtual std::vector<vx_data_table::Type_row*> vx_listrow();
    // vx_row(index)
    virtual vx_data_table::Type_row* vx_row(vx_core::Type_int* index);
  };

  // (type rowmap)
  class Type_rowmap : public virtual vx_core::Type_map {
  public:
    template<class... Args> vx_data_table::Type_rowmap* vx_new(Args*... args);
    template<class... Args> vx_data_table::Type_rowmap* vx_copy(Args*... args);
    virtual vx_data_table::Type_rowmap* vx_empty();
    virtual vx_data_table::Type_rowmap* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    std::map<std::string, vx_data_table::Type_row*> vx_p_map;
    // vx_maprow()
    virtual std::map<std::string, vx_data_table::Type_row*> vx_maprow();
    // vx_row(key)
    virtual vx_data_table::Type_row* vx_row(vx_core::Type_string* key);
    virtual vx_data_table::Type_rowmap* vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval);
  };

  // (type sort)
  class Type_sort : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_data_table::Type_sort* vx_new(Args*... args);
    template<class... Args> vx_data_table::Type_sort* vx_copy(Args*... args);
    virtual vx_data_table::Type_sort* vx_empty();
    virtual vx_data_table::Type_sort* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // id()
    vx_core::Type_string* vx_p_id;
    virtual vx_core::Type_string* id();
    // name()
    vx_core::Type_string* vx_p_name;
    virtual vx_core::Type_string* name();
    // idlist()
    vx_core::Type_stringlist* vx_p_idlist;
    virtual vx_core::Type_stringlist* idlist();
  };

  // (type table)
  class Type_table : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_data_table::Type_table* vx_new(Args*... args);
    template<class... Args> vx_data_table::Type_table* vx_copy(Args*... args);
    virtual vx_data_table::Type_table* vx_empty();
    virtual vx_data_table::Type_table* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // id()
    vx_core::Type_string* vx_p_id;
    virtual vx_core::Type_string* id();
    // name()
    vx_core::Type_string* vx_p_name;
    virtual vx_core::Type_string* name();
    // fieldmap()
    vx_data_table::Type_fieldmap* vx_p_fieldmap;
    virtual vx_data_table::Type_fieldmap* fieldmap();
    // fieldsort()
    vx_data_table::Type_sort* vx_p_fieldsort;
    virtual vx_data_table::Type_sort* fieldsort();
    // rowmap()
    vx_data_table::Type_rowmap* vx_p_rowmap;
    virtual vx_data_table::Type_rowmap* rowmap();
    // rowfilter()
    vx_data_table::Type_filter* vx_p_rowfilter;
    virtual vx_data_table::Type_filter* rowfilter();
    // rowsort()
    vx_data_table::Type_sort* vx_p_rowsort;
    virtual vx_data_table::Type_sort* rowsort();
  };

}
