#ifndef VX_DATA_CSV_HPP
#define VX_DATA_CSV_HPP
#include <vector>
#include "../../vx/core.hpp"
#include "../../vx/collection.hpp"
#include "../../vx/type.hpp"
#include "../../vx/data/textblock.hpp"

namespace vx_data_csv {

  // forward declarations
  class Abstract_csv;
  typedef Abstract_csv* Type_csv;
  extern Type_csv e_csv;
  extern Type_csv t_csv;
  class Abstract_csvrows;
  typedef Abstract_csvrows* Type_csvrows;
  extern Type_csvrows e_csvrows;
  extern Type_csvrows t_csvrows;
  class Class_delims;
  typedef Class_delims* Const_delims;
  extern Const_delims c_delims();
  class Abstract_csv_from_textblock;
  typedef Abstract_csv_from_textblock* Func_csv_from_textblock;
  extern Func_csv_from_textblock e_csv_from_textblock;
  extern Func_csv_from_textblock t_csv_from_textblock;
  class Abstract_csvrows_from_textblock;
  typedef Abstract_csvrows_from_textblock* Func_csvrows_from_textblock;
  extern Func_csvrows_from_textblock e_csvrows_from_textblock;
  extern Func_csvrows_from_textblock t_csvrows_from_textblock;

  class vx_Class_package {
  public:
    vx_data_csv::Const_delims c_delims;
  };


  // (func csv<-textblock)
  vx_data_csv::Type_csv f_csv_from_textblock(vx_data_textblock::Type_textblock textblock);

  // (func csvrows<-textblock)
  vx_data_csv::Type_csvrows f_csvrows_from_textblock(vx_data_textblock::Type_textblock textblock);

  // (type csv)
  class Abstract_csv : public virtual vx_core::Abstract_struct {
  public:
    Abstract_csv() {};
    virtual ~Abstract_csv() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // headers()
    vx_core::Type_stringlist vx_p_headers = NULL;
    virtual vx_core::Type_stringlist headers() const = 0;
    // rows()
    vx_data_csv::Type_csvrows vx_p_rows = NULL;
    virtual vx_data_csv::Type_csvrows rows() const = 0;
  };
  class Class_csv : public virtual Abstract_csv {
  public:
    Class_csv();
    virtual ~Class_csv() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_stringlist headers() const override;
    virtual vx_data_csv::Type_csvrows rows() const override;
  };

  // (type csvrows)
  class Abstract_csvrows : public virtual vx_core::Abstract_list {
  public:
    Abstract_csvrows() {};
    virtual ~Abstract_csvrows() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_core::Type_stringlist> vx_p_list;
    // vx_liststringlist()
    virtual std::vector<vx_core::Type_stringlist> vx_liststringlist() const = 0;
    // vx_get_stringlist(index)
    virtual vx_core::Type_stringlist vx_get_stringlist(vx_core::Type_int index) const = 0;
  };
  class Class_csvrows : public virtual Abstract_csvrows {
  public:
    Class_csvrows();
    virtual ~Class_csvrows() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
    virtual std::vector<vx_core::Type_stringlist> vx_liststringlist() const override;
    virtual vx_core::Type_stringlist vx_get_stringlist(vx_core::Type_int index) const override;
  };

  // (const delims)
  class Class_delims : public vx_data_textblock::Class_delimset {
  public:
    static vx_data_csv::Const_delims vx_const_new();
    vx_core::Type_constdef vx_constdef() const;
  };

  // (func csv<-textblock)
  class Abstract_csv_from_textblock : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_csv_from_textblock() {};
    virtual ~Abstract_csv_from_textblock() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_csv_from_textblock : public virtual Abstract_csv_from_textblock {
  public:
    Class_csv_from_textblock();
    virtual ~Class_csv_from_textblock() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func csvrows<-textblock)
  class Abstract_csvrows_from_textblock : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_csvrows_from_textblock() {};
    virtual ~Abstract_csvrows_from_textblock() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_csvrows_from_textblock : public virtual Abstract_csvrows_from_textblock {
  public:
    Class_csvrows_from_textblock();
    virtual ~Class_csvrows_from_textblock() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

}
#endif
