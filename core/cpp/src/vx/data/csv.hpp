#pragma once
#include <any>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "../../vx/collection.hpp"
#include "../../vx/type.hpp"
#include "../../vx/data/textblock.hpp"

namespace vx_data_csv {

  // (type csv)
  class Type_csv : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_data_csv::Type_csv* vx_new(Args*... args);
    template<typename... Args> vx_data_csv::Type_csv* vx_copy(Args*... args);
    virtual vx_data_csv::Type_csv* vx_empty();
    virtual vx_data_csv::Type_csv* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // headers()
    vx_core::Type_stringlist* vx_p_headers;
    virtual vx_core::Type_stringlist* headers();
    // rows()
    vx_data_csv::Type_csvrows* vx_p_rows;
    virtual vx_data_csv::Type_csvrows* rows();
  };
  extern vx_data_csv::Type_csv* e_csv;
  extern vx_data_csv::Type_csv* t_csv;

  // (type csvrows)
  class Type_csvrows : public virtual vx_core::Type_list {
  public:
    template<typename... Args> vx_data_csv::Type_csvrows* vx_new(Args*... args);
    template<typename... Args> vx_data_csv::Type_csvrows* vx_copy(Args*... args);
    virtual vx_data_csv::Type_csvrows* vx_empty();
    virtual vx_data_csv::Type_csvrows* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_core::Type_stringlist*> vx_p_list;

    // vx_liststringlist()
    virtual std::vector<vx_core::Type_stringlist*> vx_liststringlist();
    // vx_stringlist(index)
    virtual vx_core::Type_stringlist* vx_stringlist(vx_core::Type_int* index);
  };
  extern vx_data_csv::Type_csvrows* e_csvrows;
  extern vx_data_csv::Type_csvrows* t_csvrows;

  // (const delims)
  class Const_delims : public vx_data_textblock::Type_delimset {
  public:
    vx_core::Type_constdef* vx_constdef();
    static Const_delims* vx_const_new();
  };
  extern Const_delims* c_delims;

  // (func csv<-textblock)
  class Func_csv_from_textblock : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_data_csv::Func_csv_from_textblock* vx_new(Args*... args);
    template<typename... Args> vx_data_csv::Func_csv_from_textblock* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_data_csv::Func_csv_from_textblock* vx_empty();
    virtual vx_data_csv::Func_csv_from_textblock* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_data_csv::Type_csv* vx_csv_from_textblock(vx_data_textblock::Type_textblock* textblock);
  };
  extern Func_csv_from_textblock* e_csv_from_textblock;
  extern Func_csv_from_textblock* t_csv_from_textblock;

  // (func csvrows<-textblock)
  class Func_csvrows_from_textblock : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_data_csv::Func_csvrows_from_textblock* vx_new(Args*... args);
    template<typename... Args> vx_data_csv::Func_csvrows_from_textblock* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_data_csv::Func_csvrows_from_textblock* vx_empty();
    virtual vx_data_csv::Func_csvrows_from_textblock* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_data_csv::Type_csvrows* vx_csvrows_from_textblock(vx_data_textblock::Type_textblock* textblock);
  };
  extern Func_csvrows_from_textblock* e_csvrows_from_textblock;
  extern Func_csvrows_from_textblock* t_csvrows_from_textblock;

  // (func csv<-textblock)
  vx_data_csv::Type_csv* f_csv_from_textblock(vx_data_textblock::Type_textblock* textblock);

  // (func csvrows<-textblock)
  vx_data_csv::Type_csvrows* f_csvrows_from_textblock(vx_data_textblock::Type_textblock* textblock);

}
