#pragma once
#include <any>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "../../vx/core.hpp"

namespace vx_data_table {

  // (type cell)
  class Type_cell : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_data_table::Type_cell* vx_new(Args*... args);
    template<typename... Args> vx_data_table::Type_cell* vx_copy(Args*... args);
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
  extern vx_data_table::Type_cell* e_cell;
  extern vx_data_table::Type_cell* t_cell;

  // (type celllist)
  class Type_celllist : public virtual vx_core::Type_list {
  public:
    template<typename... Args> vx_data_table::Type_celllist* vx_new(Args*... args);
    template<typename... Args> vx_data_table::Type_celllist* vx_copy(Args*... args);
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
  extern vx_data_table::Type_celllist* e_celllist;
  extern vx_data_table::Type_celllist* t_celllist;

  // (type cellmap)
  class Type_cellmap : public virtual vx_core::Type_map {
  public:
    template<typename... Args> vx_data_table::Type_cellmap* vx_new(Args*... args);
    template<typename... Args> vx_data_table::Type_cellmap* vx_copy(Args*... args);
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
  extern vx_data_table::Type_cellmap* e_cellmap;
  extern vx_data_table::Type_cellmap* t_cellmap;

  // (type field)
  class Type_field : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_data_table::Type_field* vx_new(Args*... args);
    template<typename... Args> vx_data_table::Type_field* vx_copy(Args*... args);
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
  extern vx_data_table::Type_field* e_field;
  extern vx_data_table::Type_field* t_field;

  // (type fieldlist)
  class Type_fieldlist : public virtual vx_core::Type_list {
  public:
    template<typename... Args> vx_data_table::Type_fieldlist* vx_new(Args*... args);
    template<typename... Args> vx_data_table::Type_fieldlist* vx_copy(Args*... args);
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
  extern vx_data_table::Type_fieldlist* e_fieldlist;
  extern vx_data_table::Type_fieldlist* t_fieldlist;

  // (type fieldmap)
  class Type_fieldmap : public virtual vx_core::Type_list {
  public:
    template<typename... Args> vx_data_table::Type_fieldmap* vx_new(Args*... args);
    template<typename... Args> vx_data_table::Type_fieldmap* vx_copy(Args*... args);
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
  extern vx_data_table::Type_fieldmap* e_fieldmap;
  extern vx_data_table::Type_fieldmap* t_fieldmap;

  // (type filter)
  class Type_filter : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_data_table::Type_filter* vx_new(Args*... args);
    template<typename... Args> vx_data_table::Type_filter* vx_copy(Args*... args);
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
  extern vx_data_table::Type_filter* e_filter;
  extern vx_data_table::Type_filter* t_filter;

  // (type row)
  class Type_row : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_data_table::Type_row* vx_new(Args*... args);
    template<typename... Args> vx_data_table::Type_row* vx_copy(Args*... args);
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
  extern vx_data_table::Type_row* e_row;
  extern vx_data_table::Type_row* t_row;

  // (type rowlist)
  class Type_rowlist : public virtual vx_core::Type_list {
  public:
    template<typename... Args> vx_data_table::Type_rowlist* vx_new(Args*... args);
    template<typename... Args> vx_data_table::Type_rowlist* vx_copy(Args*... args);
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
  extern vx_data_table::Type_rowlist* e_rowlist;
  extern vx_data_table::Type_rowlist* t_rowlist;

  // (type rowmap)
  class Type_rowmap : public virtual vx_core::Type_map {
  public:
    template<typename... Args> vx_data_table::Type_rowmap* vx_new(Args*... args);
    template<typename... Args> vx_data_table::Type_rowmap* vx_copy(Args*... args);
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
  extern vx_data_table::Type_rowmap* e_rowmap;
  extern vx_data_table::Type_rowmap* t_rowmap;

  // (type sort)
  class Type_sort : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_data_table::Type_sort* vx_new(Args*... args);
    template<typename... Args> vx_data_table::Type_sort* vx_copy(Args*... args);
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
  extern vx_data_table::Type_sort* e_sort;
  extern vx_data_table::Type_sort* t_sort;

  // (type table)
  class Type_table : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_data_table::Type_table* vx_new(Args*... args);
    template<typename... Args> vx_data_table::Type_table* vx_copy(Args*... args);
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
  extern vx_data_table::Type_table* e_table;
  extern vx_data_table::Type_table* t_table;

}
