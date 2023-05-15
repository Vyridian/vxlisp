#pragma once
#include <exception>
#include <memory>
#include <set>
#include <string>
#include "../../vx/core.hpp"
#include "../../vx/data/textblock.hpp"

namespace vx_data_file {

  // forward declarations
  class Class_file;
  typedef std::shared_ptr<Class_file> Type_file;
  extern Type_file e_file;
  extern Type_file t_file;
  class Class_fileformat;
  typedef std::shared_ptr<Class_fileformat> Type_fileformat;
  extern Type_fileformat e_fileformat;
  extern Type_fileformat t_fileformat;
  class Class_boolean_exists_from_file;
  typedef std::shared_ptr<Class_boolean_exists_from_file> Func_boolean_exists_from_file;
  extern Func_boolean_exists_from_file e_boolean_exists_from_file;
  extern Func_boolean_exists_from_file t_boolean_exists_from_file;
  class Class_boolean_write_from_file_any;
  typedef std::shared_ptr<Class_boolean_write_from_file_any> Func_boolean_write_from_file_any;
  extern Func_boolean_write_from_file_any e_boolean_write_from_file_any;
  extern Func_boolean_write_from_file_any t_boolean_write_from_file_any;
  class Class_boolean_write_from_file_string;
  typedef std::shared_ptr<Class_boolean_write_from_file_string> Func_boolean_write_from_file_string;
  extern Func_boolean_write_from_file_string e_boolean_write_from_file_string;
  extern Func_boolean_write_from_file_string t_boolean_write_from_file_string;
  class Class_file_read_from_file;
  typedef std::shared_ptr<Class_file_read_from_file> Func_file_read_from_file;
  extern Func_file_read_from_file e_file_read_from_file;
  extern Func_file_read_from_file t_file_read_from_file;
  class Class_name_from_file;
  typedef std::shared_ptr<Class_name_from_file> Func_name_from_file;
  extern Func_name_from_file e_name_from_file;
  extern Func_name_from_file t_name_from_file;
  class Class_path_from_file;
  typedef std::shared_ptr<Class_path_from_file> Func_path_from_file;
  extern Func_path_from_file e_path_from_file;
  extern Func_path_from_file t_path_from_file;
  class Class_pathcurrent_from_os;
  typedef std::shared_ptr<Class_pathcurrent_from_os> Func_pathcurrent_from_os;
  extern Func_pathcurrent_from_os e_pathcurrent_from_os;
  extern Func_pathcurrent_from_os t_pathcurrent_from_os;
  class Class_pathfull_from_file;
  typedef std::shared_ptr<Class_pathfull_from_file> Func_pathfull_from_file;
  extern Func_pathfull_from_file e_pathfull_from_file;
  extern Func_pathfull_from_file t_pathfull_from_file;
  class Class_string_read_from_file;
  typedef std::shared_ptr<Class_string_read_from_file> Func_string_read_from_file;
  extern Func_string_read_from_file e_string_read_from_file;
  extern Func_string_read_from_file t_string_read_from_file;


  // (type file)
  class Class_file : public virtual vx_core::Class_struct {
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
    // name()
    vx_core::Type_string vx_p_name;
    virtual vx_core::Type_string name();
    // format()
    vx_data_file::Type_fileformat vx_p_format;
    virtual vx_data_file::Type_fileformat format();
    // path()
    vx_core::Type_string vx_p_path;
    virtual vx_core::Type_string path();
    // permission()
    vx_core::Type_permission vx_p_permission;
    virtual vx_core::Type_permission permission();
    // text()
    vx_core::Type_string vx_p_text;
    virtual vx_core::Type_string text();
  };

  // (type fileformat)
  class Class_fileformat : public vx_core::Class_any {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (func boolean-exists<-file)
  class Class_boolean_exists_from_file : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_boolean vx_boolean_exists_from_file(vx_data_file::Type_file file);
  };

  // (func boolean-write<-file-any)
  class Class_boolean_write_from_file_any : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_boolean_write_from_file_any(vx_data_file::Type_file file, vx_core::Type_any val, vx_core::Type_context context);
  };

  // (func boolean-write<-file-string)
  class Class_boolean_write_from_file_string : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_boolean_write_from_file_string(vx_data_file::Type_file file, vx_core::Type_string text, vx_core::Type_context context);
  };

  // (func file-read<-file)
  class Class_file_read_from_file : public vx_core::Class_any_from_any_context, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_context fn_new(vx_core::Class_any_from_any_context::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any_context(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value, vx_core::Type_context context);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_data_file::Type_file vx_file_read_from_file(vx_data_file::Type_file file, vx_core::Type_context context);
  };

  // (func name<-file)
  class Class_name_from_file : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_string vx_name_from_file(vx_data_file::Type_file file);
  };

  // (func path<-file)
  class Class_path_from_file : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_string vx_path_from_file(vx_data_file::Type_file file);
  };

  // (func pathcurrent<-os)
  class Class_pathcurrent_from_os : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_pathcurrent_from_os();
  };

  // (func pathfull<-file)
  class Class_pathfull_from_file : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_string vx_pathfull_from_file(vx_data_file::Type_file file);
  };

  // (func string-read<-file)
  class Class_string_read_from_file : public vx_core::Class_any_from_any_context, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_context fn_new(vx_core::Class_any_from_any_context::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any_context(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value, vx_core::Type_context context);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_read_from_file(vx_data_file::Type_file file, vx_core::Type_context context);
  };

  // (func boolean-exists<-file)
  vx_core::Type_boolean f_boolean_exists_from_file(vx_data_file::Type_file file);

  // (func boolean-write<-file-any)
  vx_core::Type_boolean f_boolean_write_from_file_any(vx_data_file::Type_file file, vx_core::Type_any val, vx_core::Type_context context);

  // (func boolean-write<-file-string)
  vx_core::Type_boolean f_boolean_write_from_file_string(vx_data_file::Type_file file, vx_core::Type_string text, vx_core::Type_context context);

  // (func file-read<-file)
  vx_data_file::Type_file f_file_read_from_file(vx_data_file::Type_file file, vx_core::Type_context context);

  // (func name<-file)
  vx_core::Type_string f_name_from_file(vx_data_file::Type_file file);

  // (func path<-file)
  vx_core::Type_string f_path_from_file(vx_data_file::Type_file file);

  // (func pathcurrent<-os)
  vx_core::Type_string f_pathcurrent_from_os();

  // (func pathfull<-file)
  vx_core::Type_string f_pathfull_from_file(vx_data_file::Type_file file);

  // (func string-read<-file)
  vx_core::Type_string f_string_read_from_file(vx_data_file::Type_file file, vx_core::Type_context context);

}
