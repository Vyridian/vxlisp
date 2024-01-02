#ifndef VX_DATA_FILE_HPP
#define VX_DATA_FILE_HPP
#include <string>
#include "../../vx/core.hpp"
#include "../../vx/data/textblock.hpp"

namespace vx_data_file {


  // forward declarations
  class Abstract_file;
  typedef Abstract_file* Type_file;
  extern Type_file e_file;
  extern Type_file t_file;
  class Abstract_fileformat;
  typedef Abstract_fileformat* Type_fileformat;
  extern Type_fileformat e_fileformat;
  extern Type_fileformat t_fileformat;
  class Abstract_boolean_exists_from_file;
  typedef Abstract_boolean_exists_from_file* Func_boolean_exists_from_file;
  extern Func_boolean_exists_from_file e_boolean_exists_from_file;
  extern Func_boolean_exists_from_file t_boolean_exists_from_file;
  class Abstract_boolean_write_from_file_any;
  typedef Abstract_boolean_write_from_file_any* Func_boolean_write_from_file_any;
  extern Func_boolean_write_from_file_any e_boolean_write_from_file_any;
  extern Func_boolean_write_from_file_any t_boolean_write_from_file_any;
  class Abstract_boolean_write_from_file_string;
  typedef Abstract_boolean_write_from_file_string* Func_boolean_write_from_file_string;
  extern Func_boolean_write_from_file_string e_boolean_write_from_file_string;
  extern Func_boolean_write_from_file_string t_boolean_write_from_file_string;
  class Abstract_file_read_from_file;
  typedef Abstract_file_read_from_file* Func_file_read_from_file;
  extern Func_file_read_from_file e_file_read_from_file;
  extern Func_file_read_from_file t_file_read_from_file;
  class Abstract_name_from_file;
  typedef Abstract_name_from_file* Func_name_from_file;
  extern Func_name_from_file e_name_from_file;
  extern Func_name_from_file t_name_from_file;
  class Abstract_path_from_file;
  typedef Abstract_path_from_file* Func_path_from_file;
  extern Func_path_from_file e_path_from_file;
  extern Func_path_from_file t_path_from_file;
  class Abstract_pathcurrent_from_os;
  typedef Abstract_pathcurrent_from_os* Func_pathcurrent_from_os;
  extern Func_pathcurrent_from_os e_pathcurrent_from_os;
  extern Func_pathcurrent_from_os t_pathcurrent_from_os;
  class Abstract_pathfull_from_file;
  typedef Abstract_pathfull_from_file* Func_pathfull_from_file;
  extern Func_pathfull_from_file e_pathfull_from_file;
  extern Func_pathfull_from_file t_pathfull_from_file;
  class Abstract_string_read_from_file;
  typedef Abstract_string_read_from_file* Func_string_read_from_file;
  extern Func_string_read_from_file e_string_read_from_file;
  extern Func_string_read_from_file t_string_read_from_file;// :headerfirst
// :header

  vx_core::Type_boolean vx_boolean_exists_from_file(vx_data_file::Type_file file);

  vx_core::Type_boolean vx_boolean_write_from_file_string(vx_data_file::Type_file file, vx_core::Type_string text);

  vx_core::Type_boolean vx_boolean_write_from_path_text(std::string path, std::string text);

  vx_core::Type_string vx_string_read_from_file(vx_data_file::Type_file file);

  vx_core::Type_string vx_string_read_from_path(std::string path);

  vx_core::Type_string vx_pathcurrent_from_os();


  // (func boolean-exists<-file)
  vx_core::Type_boolean f_boolean_exists_from_file(vx_data_file::Type_file file);

  // (func boolean-write<-file-any)
  vx_core::Type_boolean f_boolean_write_from_file_any(vx_core::Type_context context, vx_data_file::Type_file file, vx_core::Type_any val);

  // (func boolean-write<-file-string)
  vx_core::Type_boolean f_boolean_write_from_file_string(vx_core::Type_context context, vx_data_file::Type_file file, vx_core::Type_string text);

  // (func file-read<-file)
  vx_data_file::Type_file f_file_read_from_file(vx_core::Type_context context, vx_data_file::Type_file file);

  // (func name<-file)
  vx_core::Type_string f_name_from_file(vx_data_file::Type_file file);

  // (func path<-file)
  vx_core::Type_string f_path_from_file(vx_data_file::Type_file file);

  // (func pathcurrent<-os)
  vx_core::Type_string f_pathcurrent_from_os();

  // (func pathfull<-file)
  vx_core::Type_string f_pathfull_from_file(vx_data_file::Type_file file);

  // (func string-read<-file)
  vx_core::Type_string f_string_read_from_file(vx_core::Type_context context, vx_data_file::Type_file file);

  // (type file)
  class Abstract_file : public virtual vx_core::Abstract_struct {
  public:
    Abstract_file() {};
    virtual ~Abstract_file() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
    // format()
    vx_data_file::Type_fileformat vx_p_format = NULL;
    virtual vx_data_file::Type_fileformat format() const = 0;
    // path()
    vx_core::Type_string vx_p_path = NULL;
    virtual vx_core::Type_string path() const = 0;
    // permission()
    vx_core::Type_permission vx_p_permission = NULL;
    virtual vx_core::Type_permission permission() const = 0;
    // text()
    vx_core::Type_string vx_p_text = NULL;
    virtual vx_core::Type_string text() const = 0;
  };
  class Class_file : public virtual Abstract_file {
  public:
    Class_file();
    virtual ~Class_file() override;
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
    virtual vx_core::Type_string name() const override;
    virtual vx_data_file::Type_fileformat format() const override;
    virtual vx_core::Type_string path() const override;
    virtual vx_core::Type_permission permission() const override;
    virtual vx_core::Type_string text() const override;
  };

  // (type fileformat)
  class Abstract_fileformat : public virtual vx_core::Abstract_any {
  public:
    Abstract_fileformat() {};
    virtual ~Abstract_fileformat() = 0;
  };
  class Class_fileformat : public virtual Abstract_fileformat {
  public:
    Class_fileformat();
    virtual ~Class_fileformat() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (func boolean-exists<-file)
  class Abstract_boolean_exists_from_file : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_boolean_exists_from_file() {};
    virtual ~Abstract_boolean_exists_from_file() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_boolean_exists_from_file : public virtual Abstract_boolean_exists_from_file {
  public:
    Class_boolean_exists_from_file();
    virtual ~Class_boolean_exists_from_file() override;
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

  // (func boolean-write<-file-any)
  class Abstract_boolean_write_from_file_any : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_boolean_write_from_file_any() {};
    virtual ~Abstract_boolean_write_from_file_any() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_boolean_write_from_file_any : public virtual Abstract_boolean_write_from_file_any {
  public:
    Class_boolean_write_from_file_any();
    virtual ~Class_boolean_write_from_file_any() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func boolean-write<-file-string)
  class Abstract_boolean_write_from_file_string : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_boolean_write_from_file_string() {};
    virtual ~Abstract_boolean_write_from_file_string() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_boolean_write_from_file_string : public virtual Abstract_boolean_write_from_file_string {
  public:
    Class_boolean_write_from_file_string();
    virtual ~Class_boolean_write_from_file_string() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func file-read<-file)
  class Abstract_file_read_from_file : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_file_read_from_file() {};
    virtual ~Abstract_file_read_from_file() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_file_read_from_file : public virtual Abstract_file_read_from_file {
  public:
    Class_file_read_from_file();
    virtual ~Class_file_read_from_file() override;
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

  // (func name<-file)
  class Abstract_name_from_file : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_name_from_file() {};
    virtual ~Abstract_name_from_file() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_name_from_file : public virtual Abstract_name_from_file {
  public:
    Class_name_from_file();
    virtual ~Class_name_from_file() override;
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

  // (func path<-file)
  class Abstract_path_from_file : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_path_from_file() {};
    virtual ~Abstract_path_from_file() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_path_from_file : public virtual Abstract_path_from_file {
  public:
    Class_path_from_file();
    virtual ~Class_path_from_file() override;
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

  // (func pathcurrent<-os)
  class Abstract_pathcurrent_from_os : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_pathcurrent_from_os() {};
    virtual ~Abstract_pathcurrent_from_os() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_pathcurrent_from_os : public virtual Abstract_pathcurrent_from_os {
  public:
    Class_pathcurrent_from_os();
    virtual ~Class_pathcurrent_from_os() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func pathfull<-file)
  class Abstract_pathfull_from_file : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_pathfull_from_file() {};
    virtual ~Abstract_pathfull_from_file() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_pathfull_from_file : public virtual Abstract_pathfull_from_file {
  public:
    Class_pathfull_from_file();
    virtual ~Class_pathfull_from_file() override;
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

  // (func string-read<-file)
  class Abstract_string_read_from_file : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_read_from_file() {};
    virtual ~Abstract_string_read_from_file() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_read_from_file : public virtual Abstract_string_read_from_file {
  public:
    Class_string_read_from_file();
    virtual ~Class_string_read_from_file() override;
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

  class vx_Class_package {
  public:
    vx_Class_package();
    void init();
  };
  inline vx_Class_package const vx_package;

}

#endif
