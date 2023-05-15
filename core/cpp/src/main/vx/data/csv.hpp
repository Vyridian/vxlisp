#pragma once
#include <memory>
#include <set>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "../../vx/collection.hpp"
#include "../../vx/type.hpp"
#include "../../vx/data/textblock.hpp"

namespace vx_data_csv {

  // forward declarations
  class Class_csv;
  typedef std::shared_ptr<Class_csv> Type_csv;
  extern Type_csv e_csv;
  extern Type_csv t_csv;
  class Class_csvrows;
  typedef std::shared_ptr<Class_csvrows> Type_csvrows;
  extern Type_csvrows e_csvrows;
  extern Type_csvrows t_csvrows;
  class Class_delims;
  typedef std::shared_ptr<Class_delims> Const_delims;
  extern Const_delims c_delims;
  class Class_csv_from_textblock;
  typedef std::shared_ptr<Class_csv_from_textblock> Func_csv_from_textblock;
  extern Func_csv_from_textblock e_csv_from_textblock;
  extern Func_csv_from_textblock t_csv_from_textblock;
  class Class_csvrows_from_textblock;
  typedef std::shared_ptr<Class_csvrows_from_textblock> Func_csvrows_from_textblock;
  extern Func_csvrows_from_textblock e_csvrows_from_textblock;
  extern Func_csvrows_from_textblock t_csvrows_from_textblock;


  // (type csv)
  class Class_csv : public virtual vx_core::Class_struct {
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
    // headers()
    vx_core::Type_stringlist vx_p_headers;
    virtual vx_core::Type_stringlist headers();
    // rows()
    vx_data_csv::Type_csvrows vx_p_rows;
    virtual vx_data_csv::Type_csvrows rows();
  };

  // (type csvrows)
  class Class_csvrows : public virtual vx_core::Class_list {
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
    std::vector<vx_core::Type_stringlist> vx_p_list;

    // vx_liststringlist()
    virtual std::vector<vx_core::Type_stringlist> vx_liststringlist();
    // vx_stringlist(index)
    virtual vx_core::Type_stringlist vx_stringlist(vx_core::Type_int index);
  };

  // (const delims)
  class Class_delims : public vx_data_textblock::Class_delimset {
  public:
    vx_core::Type_constdef vx_constdef();
    static vx_data_csv::Const_delims vx_const_new();
  };

  // (func csv<-textblock)
  class Class_csv_from_textblock : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_data_csv::Type_csv vx_csv_from_textblock(vx_data_textblock::Type_textblock textblock);
  };

  // (func csvrows<-textblock)
  class Class_csvrows_from_textblock : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_data_csv::Type_csvrows vx_csvrows_from_textblock(vx_data_textblock::Type_textblock textblock);
  };

  // (func csv<-textblock)
  vx_data_csv::Type_csv f_csv_from_textblock(vx_data_textblock::Type_textblock textblock);

  // (func csvrows<-textblock)
  vx_data_csv::Type_csvrows f_csvrows_from_textblock(vx_data_textblock::Type_textblock textblock);

}
