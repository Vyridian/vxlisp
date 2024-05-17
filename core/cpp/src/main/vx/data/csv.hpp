#ifndef VX_DATA_CSV_HPP
#define VX_DATA_CSV_HPP
#include <map>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "../../vx/collection.hpp"
#include "../../vx/data/file.hpp"
#include "../../vx/data/textblock.hpp"
#include "../../vx/type.hpp"

namespace vx_data_csv {


  // forward declarations
  class Abstract_csv;
  typedef Abstract_csv* Type_csv;
  extern Type_csv e_csv;
  extern Type_csv t_csv;
  class Abstract_csvrowmap;
  typedef Abstract_csvrowmap* Type_csvrowmap;
  extern Type_csvrowmap e_csvrowmap;
  extern Type_csvrowmap t_csvrowmap;
  class Abstract_csvrows;
  typedef Abstract_csvrows* Type_csvrows;
  extern Type_csvrows e_csvrows;
  extern Type_csvrows t_csvrows;
  class Class_delimcsv;
  typedef Class_delimcsv* Const_delimcsv;
  extern Const_delimcsv c_delimcsv;
  class Abstract_csv_read_from_file;
  typedef Abstract_csv_read_from_file* Func_csv_read_from_file;
  extern Func_csv_read_from_file e_csv_read_from_file;
  extern Func_csv_read_from_file t_csv_read_from_file;
  class Abstract_csv_from_file;
  typedef Abstract_csv_from_file* Func_csv_from_file;
  extern Func_csv_from_file e_csv_from_file;
  extern Func_csv_from_file t_csv_from_file;
  class Abstract_csv_from_string;
  typedef Abstract_csv_from_string* Func_csv_from_string;
  extern Func_csv_from_string e_csv_from_string;
  extern Func_csv_from_string t_csv_from_string;
  class Abstract_csv_from_textblock;
  typedef Abstract_csv_from_textblock* Func_csv_from_textblock;
  extern Func_csv_from_textblock e_csv_from_textblock;
  extern Func_csv_from_textblock t_csv_from_textblock;
  class Abstract_csvrows_from_textblock;
  typedef Abstract_csvrows_from_textblock* Func_csvrows_from_textblock;
  extern Func_csvrows_from_textblock e_csvrows_from_textblock;
  extern Func_csvrows_from_textblock t_csvrows_from_textblock;
  class Abstract_stringmap_from_csv;
  typedef Abstract_stringmap_from_csv* Func_stringmap_from_csv;
  extern Func_stringmap_from_csv e_stringmap_from_csv;
  extern Func_stringmap_from_csv t_stringmap_from_csv;
  class Abstract_textblock_csv_from_string;
  typedef Abstract_textblock_csv_from_string* Func_textblock_csv_from_string;
  extern Func_textblock_csv_from_string e_textblock_csv_from_string;
  extern Func_textblock_csv_from_string t_textblock_csv_from_string;
  // (func csv-read<-file)
  vx_data_csv::Type_csv f_csv_read_from_file(vx_core::Type_context context, vx_data_file::Type_file file);

  // (func csv<-file)
  vx_data_csv::Type_csv f_csv_from_file(vx_data_file::Type_file file);

  // (func csv<-string)
  vx_data_csv::Type_csv f_csv_from_string(vx_core::Type_string text);

  // (func csv<-textblock)
  vx_data_csv::Type_csv f_csv_from_textblock(vx_data_textblock::Type_textblock textblock);

  // (func csvrows<-textblock)
  vx_data_csv::Type_csvrows f_csvrows_from_textblock(vx_data_textblock::Type_textblock textblock);

  // (func stringmap<-csv)
  vx_core::Type_stringmap f_stringmap_from_csv(vx_data_csv::Type_csv csv);

  // (func textblock-csv<-string)
  vx_data_textblock::Type_textblock f_textblock_csv_from_string(vx_core::Type_string text);

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
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_stringlist headers() const override;
    virtual vx_data_csv::Type_csvrows rows() const override;
  };

  // (type csvrowmap)
  class Abstract_csvrowmap : public virtual vx_core::Abstract_map {
  public:
    Abstract_csvrowmap() {};
    virtual ~Abstract_csvrowmap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_set(name, value)
    virtual vx_core::Type_boolean vx_set(vx_core::Type_string name, vx_core::Type_any value) = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
    std::map<std::string, vx_core::Type_stringlist> vx_p_map;
    // vx_mapstringlist()
    virtual std::map<std::string, vx_core::Type_stringlist> vx_mapstringlist() const = 0;
    // vx_get_stringlist(key)
    virtual vx_core::Type_stringlist vx_get_stringlist(vx_core::Type_string key) const = 0;
  };
  class Class_csvrowmap : public virtual Abstract_csvrowmap {
  public:
    Class_csvrowmap();
    virtual ~Class_csvrowmap() override;
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
    virtual std::map<std::string, vx_core::Type_stringlist> vx_mapstringlist() const override;
    virtual vx_core::Type_stringlist vx_get_stringlist(vx_core::Type_string key) const override;
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
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
    virtual std::vector<vx_core::Type_stringlist> vx_liststringlist() const override;
    virtual vx_core::Type_stringlist vx_get_stringlist(vx_core::Type_int index) const override;
  };

  // (const delimcsv)
  class Class_delimcsv : public vx_data_textblock::Class_delim {
  public:
    static void vx_const_new(vx_data_csv::Const_delimcsv output);
  };

  // (func csv-read<-file)
  class Abstract_csv_read_from_file : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_csv_read_from_file() {};
    virtual ~Abstract_csv_read_from_file() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_csv_read_from_file : public virtual Abstract_csv_read_from_file {
  public:
    Class_csv_read_from_file();
    virtual ~Class_csv_read_from_file() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func csv<-file)
  class Abstract_csv_from_file : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_csv_from_file() {};
    virtual ~Abstract_csv_from_file() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_csv_from_file : public virtual Abstract_csv_from_file {
  public:
    Class_csv_from_file();
    virtual ~Class_csv_from_file() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func csv<-string)
  class Abstract_csv_from_string : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_csv_from_string() {};
    virtual ~Abstract_csv_from_string() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_csv_from_string : public virtual Abstract_csv_from_string {
  public:
    Class_csv_from_string();
    virtual ~Class_csv_from_string() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
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
    virtual vx_core::Type_constdef vx_constdef() const override;
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
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func stringmap<-csv)
  class Abstract_stringmap_from_csv : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_stringmap_from_csv() {};
    virtual ~Abstract_stringmap_from_csv() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_stringmap_from_csv : public virtual Abstract_stringmap_from_csv {
  public:
    Class_stringmap_from_csv();
    virtual ~Class_stringmap_from_csv() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func textblock-csv<-string)
  class Abstract_textblock_csv_from_string : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_textblock_csv_from_string() {};
    virtual ~Abstract_textblock_csv_from_string() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_textblock_csv_from_string : public virtual Abstract_textblock_csv_from_string {
  public:
    Class_textblock_csv_from_string();
    virtual ~Class_textblock_csv_from_string() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  class vx_Class_package {
  public:
    vx_Class_package();
    void init();
  };
  inline vx_Class_package const vx_package;

}

#endif
