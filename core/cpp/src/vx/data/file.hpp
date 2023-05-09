#pragma once
#include <any>
#include <exception>
#include <map>
#include <set>
#include <string>
#include "../../vx/core.hpp"
#include "../../vx/data/textblock.hpp"

namespace vx_data_file {

  // (type file)
  class Type_file : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_data_file::Type_file* vx_new(Args*... args);
    template<typename... Args> vx_data_file::Type_file* vx_copy(Args*... args);
    virtual vx_data_file::Type_file* vx_empty();
    virtual vx_data_file::Type_file* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // name()
    vx_core::Type_string* vx_p_name;
    virtual vx_core::Type_string* name();
    // format()
    vx_data_file::Type_fileformat* vx_p_format;
    virtual vx_data_file::Type_fileformat* format();
    // path()
    vx_core::Type_string* vx_p_path;
    virtual vx_core::Type_string* path();
    // permission()
    vx_core::Type_permission* vx_p_permission;
    virtual vx_core::Type_permission* permission();
    // text()
    vx_core::Type_string* vx_p_text;
    virtual vx_core::Type_string* text();
  };
  extern vx_data_file::Type_file* e_file;
  extern vx_data_file::Type_file* t_file;

  // (type fileformat)
  class Type_fileformat : public vx_core::Type_any {
  public:
    template<typename... Args> vx_data_file::Type_fileformat* vx_new(Args*... args);
    template<typename... Args> vx_data_file::Type_fileformat* vx_copy(Args*... args);
    virtual vx_data_file::Type_fileformat* vx_empty();
    virtual vx_data_file::Type_fileformat* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
  };
  extern vx_data_file::Type_fileformat* e_fileformat;
  extern vx_data_file::Type_fileformat* t_fileformat;

  // (func boolean-exists<-file)
  class Func_boolean_exists_from_file : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_data_file::Func_boolean_exists_from_file* vx_new(Args*... args);
    template<typename... Args> vx_data_file::Func_boolean_exists_from_file* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_data_file::Func_boolean_exists_from_file* vx_empty();
    virtual vx_data_file::Func_boolean_exists_from_file* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_boolean_exists_from_file(vx_data_file::Type_file* file);
  };
  extern Func_boolean_exists_from_file* e_boolean_exists_from_file;
  extern Func_boolean_exists_from_file* t_boolean_exists_from_file;

  // (func boolean-write<-file-any)
  class Func_boolean_write_from_file_any : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_data_file::Func_boolean_write_from_file_any* vx_new(Args*... args);
    template<typename... Args> vx_data_file::Func_boolean_write_from_file_any* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_data_file::Func_boolean_write_from_file_any* vx_empty();
    virtual vx_data_file::Func_boolean_write_from_file_any* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_boolean_write_from_file_any(vx_data_file::Type_file* file, vx_core::Type_any* val, vx_core::Type_context* context);
  };
  extern Func_boolean_write_from_file_any* e_boolean_write_from_file_any;
  extern Func_boolean_write_from_file_any* t_boolean_write_from_file_any;

  // (func boolean-write<-file-string)
  class Func_boolean_write_from_file_string : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_data_file::Func_boolean_write_from_file_string* vx_new(Args*... args);
    template<typename... Args> vx_data_file::Func_boolean_write_from_file_string* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_data_file::Func_boolean_write_from_file_string* vx_empty();
    virtual vx_data_file::Func_boolean_write_from_file_string* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_boolean_write_from_file_string(vx_data_file::Type_file* file, vx_core::Type_string* text, vx_core::Type_context* context);
  };
  extern Func_boolean_write_from_file_string* e_boolean_write_from_file_string;
  extern Func_boolean_write_from_file_string* t_boolean_write_from_file_string;

  // (func file-read<-file)
  class Func_file_read_from_file : public vx_core::Func_any_from_any_context, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_data_file::Func_file_read_from_file* vx_new(Args*... args);
    template<typename... Args> vx_data_file::Func_file_read_from_file* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_data_file::Func_file_read_from_file* vx_empty();
    virtual vx_data_file::Func_file_read_from_file* vx_type();
    virtual vx_core::Func_any_from_any_context* fn_new(vx_core::Func_any_from_any_context::IFn fn);
    template <class T, class U> T* f_any_from_any_context(T* generic_any_1, U* value, vx_core::Type_context* context);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_data_file::Type_file* vx_file_read_from_file(vx_data_file::Type_file* file, vx_core::Type_context* context);
  };
  extern Func_file_read_from_file* e_file_read_from_file;
  extern Func_file_read_from_file* t_file_read_from_file;

  // (func name<-file)
  class Func_name_from_file : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_data_file::Func_name_from_file* vx_new(Args*... args);
    template<typename... Args> vx_data_file::Func_name_from_file* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_data_file::Func_name_from_file* vx_empty();
    virtual vx_data_file::Func_name_from_file* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_name_from_file(vx_data_file::Type_file* file);
  };
  extern Func_name_from_file* e_name_from_file;
  extern Func_name_from_file* t_name_from_file;

  // (func path<-file)
  class Func_path_from_file : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_data_file::Func_path_from_file* vx_new(Args*... args);
    template<typename... Args> vx_data_file::Func_path_from_file* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_data_file::Func_path_from_file* vx_empty();
    virtual vx_data_file::Func_path_from_file* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_path_from_file(vx_data_file::Type_file* file);
  };
  extern Func_path_from_file* e_path_from_file;
  extern Func_path_from_file* t_path_from_file;

  // (func pathcurrent<-os)
  class Func_pathcurrent_from_os : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_data_file::Func_pathcurrent_from_os* vx_new(Args*... args);
    template<typename... Args> vx_data_file::Func_pathcurrent_from_os* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_data_file::Func_pathcurrent_from_os* vx_empty();
    virtual vx_data_file::Func_pathcurrent_from_os* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_pathcurrent_from_os();
  };
  extern Func_pathcurrent_from_os* e_pathcurrent_from_os;
  extern Func_pathcurrent_from_os* t_pathcurrent_from_os;

  // (func pathfull<-file)
  class Func_pathfull_from_file : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_data_file::Func_pathfull_from_file* vx_new(Args*... args);
    template<typename... Args> vx_data_file::Func_pathfull_from_file* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_data_file::Func_pathfull_from_file* vx_empty();
    virtual vx_data_file::Func_pathfull_from_file* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_pathfull_from_file(vx_data_file::Type_file* file);
  };
  extern Func_pathfull_from_file* e_pathfull_from_file;
  extern Func_pathfull_from_file* t_pathfull_from_file;

  // (func string-read<-file)
  class Func_string_read_from_file : public vx_core::Func_any_from_any_context, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_data_file::Func_string_read_from_file* vx_new(Args*... args);
    template<typename... Args> vx_data_file::Func_string_read_from_file* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_data_file::Func_string_read_from_file* vx_empty();
    virtual vx_data_file::Func_string_read_from_file* vx_type();
    virtual vx_core::Func_any_from_any_context* fn_new(vx_core::Func_any_from_any_context::IFn fn);
    template <class T, class U> T* f_any_from_any_context(T* generic_any_1, U* value, vx_core::Type_context* context);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_read_from_file(vx_data_file::Type_file* file, vx_core::Type_context* context);
  };
  extern Func_string_read_from_file* e_string_read_from_file;
  extern Func_string_read_from_file* t_string_read_from_file;

  // (func boolean-exists<-file)
  vx_core::Type_boolean* f_boolean_exists_from_file(vx_data_file::Type_file* file);

  // (func boolean-write<-file-any)
  vx_core::Type_boolean* f_boolean_write_from_file_any(vx_data_file::Type_file* file, vx_core::Type_any* val, vx_core::Type_context* context);

  // (func boolean-write<-file-string)
  vx_core::Type_boolean* f_boolean_write_from_file_string(vx_data_file::Type_file* file, vx_core::Type_string* text, vx_core::Type_context* context);

  // (func file-read<-file)
  vx_data_file::Type_file* f_file_read_from_file(vx_data_file::Type_file* file, vx_core::Type_context* context);

  // (func name<-file)
  vx_core::Type_string* f_name_from_file(vx_data_file::Type_file* file);

  // (func path<-file)
  vx_core::Type_string* f_path_from_file(vx_data_file::Type_file* file);

  // (func pathcurrent<-os)
  vx_core::Type_string* f_pathcurrent_from_os();

  // (func pathfull<-file)
  vx_core::Type_string* f_pathfull_from_file(vx_data_file::Type_file* file);

  // (func string-read<-file)
  vx_core::Type_string* f_string_read_from_file(vx_data_file::Type_file* file, vx_core::Type_context* context);

}
