#include <exception>
#include <memory>
#include <set>
#include <string>
#include "../../vx/core.hpp"
#include "../../vx/data/textblock.hpp"
#include "vx/data/file.hpp"

//namespace vx_data_file {

  /**
   * type: file
   * File structure
   * (type file)
   */
  //class Type_file {
    // name()
    vx_core::Type_string vx_data_file::Class_file::name() {
      vx_core::Type_string output = this->vx_p_name;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // format()
    vx_data_file::Type_fileformat vx_data_file::Class_file::format() {
      vx_data_file::Type_fileformat output = this->vx_p_format;
      if (output == NULL) {
        output = vx_data_file::t_fileformat;
      }
      return output;
    }

    // path()
    vx_core::Type_string vx_data_file::Class_file::path() {
      vx_core::Type_string output = this->vx_p_path;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // permission()
    vx_core::Type_permission vx_data_file::Class_file::permission() {
      vx_core::Type_permission output = this->vx_p_permission;
      if (output == NULL) {
        output = vx_core::t_permission;
      }
      return output;
    }

    // text()
    vx_core::Type_string vx_data_file::Class_file::text() {
      vx_core::Type_string output = this->vx_p_text;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any vx_data_file::Class_file::vx_get_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":format") {
        output = this->format();
      } else if (skey == ":path") {
        output = this->path();
      } else if (skey == ":permission") {
        output = this->permission();
      } else if (skey == ":text") {
        output = this->text();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_data_file::Class_file::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":name"] = this->name();
      output[":format"] = this->format();
      output[":path"] = this->path();
      output[":permission"] = this->permission();
      output[":text"] = this->text();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_file::Class_file::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_data_file::e_file->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_data_file::Class_file::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_file::Type_file output;
      vx_data_file::Class_file* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val->vx_msgblock(), vals);
      output->vx_p_name = val->name();
      output->vx_p_format = val->format();
      output->vx_p_path = val->path();
      output->vx_p_permission = val->permission();
      output->vx_p_text = val->text();
      std::set<std::string> validkeys;
      validkeys.insert(":name");
      validkeys.insert(":format");
      validkeys.insert(":path");
      validkeys.insert(":permission");
      validkeys.insert(":text");
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string valstr = vx_core::any_from_any(vx_core::t_string, valsub);
            testkey = valstr->vx_string();
          }
          bool isvalidkey = vx_core::boolean_contains_from_set_val(validkeys, testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new file) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_name = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new file :name " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":format") {
            if (valsubtype == vx_data_file::t_fileformat) {
              output->vx_p_format = vx_core::any_from_any(vx_data_file::t_fileformat, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new file :format " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":path") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_path = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new file :path " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":permission") {
            if (valsubtype == vx_core::t_permission) {
              output->vx_p_permission = vx_core::any_from_any(vx_core::t_permission, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new file :permission " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":text") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_text = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new file :text " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new file) - Invalid Key: " + key);
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
          key = "";
        }
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_file::Class_file::vx_empty(std::shared_ptr<T> val) {return vx_data_file::e_file;}
    template <class T> std::shared_ptr<T> vx_data_file::Class_file::vx_type(std::shared_ptr<T> val) {return vx_data_file::t_file;}

    vx_core::Type_typedef vx_data_file::Class_file::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/file", // pkgname
        "file", // name
        ":struct", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_data_file::Type_file vx_data_file::e_file = std::make_shared<vx_data_file::Class_file>();
    vx_data_file::Type_file vx_data_file::t_file = std::make_shared<vx_data_file::Class_file>();
  //}

  /**
   * type: fileformat
   * (type fileformat)
   */
  //class Type_fileformat {
    template <class T> std::shared_ptr<T> vx_data_file::Class_fileformat::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_data_file::e_fileformat->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_data_file::Class_fileformat::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_file::Type_fileformat output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_file::Class_fileformat::vx_empty(std::shared_ptr<T> val) {return vx_data_file::e_fileformat;}
    template <class T> std::shared_ptr<T> vx_data_file::Class_fileformat::vx_type(std::shared_ptr<T> val) {return vx_data_file::t_fileformat;}

    vx_core::Type_typedef vx_data_file::Class_fileformat::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/file", // pkgname
        "fileformat", // name
        ":string", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_data_file::Type_fileformat vx_data_file::e_fileformat = std::make_shared<vx_data_file::Class_fileformat>();
    vx_data_file::Type_fileformat vx_data_file::t_fileformat = std::make_shared<vx_data_file::Class_fileformat>();
  //}
  /**
   * @function boolean_exists_from_file
   * Returns true if file/path exists.
   * @param  {file} file
   * @return {boolean}
   * (func boolean-exists<-file)
   */
  //class Func_boolean_exists_from_file {

    template <class T> std::shared_ptr<T> vx_data_file::Class_boolean_exists_from_file::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_file::Func_boolean_exists_from_file output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_file::Class_boolean_exists_from_file::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_file::Func_boolean_exists_from_file output;
      return output;
    }

    vx_core::Type_typedef vx_data_file::Class_boolean_exists_from_file::vx_typedef() {return vx_data_file::t_boolean_exists_from_file->vx_typedef();}

    vx_core::Type_funcdef vx_data_file::Class_boolean_exists_from_file::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "boolean-exists<-file", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_data_file::Class_boolean_exists_from_file::vx_empty(std::shared_ptr<T> val) {return vx_data_file::e_boolean_exists_from_file;}
    template <class T> std::shared_ptr<T> vx_data_file::Class_boolean_exists_from_file::vx_type(std::shared_ptr<T> val) {return vx_data_file::t_boolean_exists_from_file;}

    vx_core::Func_any_from_any vx_data_file::Class_boolean_exists_from_file::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_data_file::Class_boolean_exists_from_file::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_data_file::Type_file inputval = (vx_data_file::Type_file)value;
      vx_core::Type_any outputval = vx_data_file::f_boolean_exists_from_file(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_data_file::Class_boolean_exists_from_file::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file file = vx_core::f_any_from_any(vx_data_file::t_file, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_data_file::f_boolean_exists_from_file(file);
      return output;
    }

    vx_core::Type_boolean vx_data_file::Class_boolean_exists_from_file::vx_f_boolean_exists_from_file(vx_data_file::Type_file file) {
      return vx_data_file::f_boolean_exists_from_file(file);
    }

  //}

  vx_data_file::Func_boolean_exists_from_file vx_data_file::e_boolean_exists_from_file = std::make_shared<vx_data_file::Class_boolean_exists_from_file>();
  vx_data_file::Func_boolean_exists_from_file vx_data_file::t_boolean_exists_from_file = std::make_shared<vx_data_file::Class_boolean_exists_from_file>();

  vx_core::Type_boolean vx_data_file::f_boolean_exists_from_file(vx_data_file::Type_file file) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    return output;
  }

  /**
   * @function boolean_write_from_file_any
   * Write any data structure as a file.
   * @param  {file} file
   * @param  {any} val
   * @return {boolean}
   * (func boolean-write<-file-any)
   */
  //class Func_boolean_write_from_file_any {

    template <class T> std::shared_ptr<T> vx_data_file::Class_boolean_write_from_file_any::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_file::Func_boolean_write_from_file_any output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_file::Class_boolean_write_from_file_any::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_file::Func_boolean_write_from_file_any output;
      return output;
    }

    vx_core::Type_typedef vx_data_file::Class_boolean_write_from_file_any::vx_typedef() {return vx_data_file::t_boolean_write_from_file_any->vx_typedef();}

    vx_core::Type_funcdef vx_data_file::Class_boolean_write_from_file_any::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "boolean-write<-file-any", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_data_file::Class_boolean_write_from_file_any::vx_empty(std::shared_ptr<T> val) {return vx_data_file::e_boolean_write_from_file_any;}
    template <class T> std::shared_ptr<T> vx_data_file::Class_boolean_write_from_file_any::vx_type(std::shared_ptr<T> val) {return vx_data_file::t_boolean_write_from_file_any;}

    vx_core::Type_any vx_data_file::Class_boolean_write_from_file_any::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file file = vx_core::f_any_from_any(vx_data_file::t_file, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_any val = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(1)));
      vx_core::Type_context context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(2)));
      output = vx_data_file::f_boolean_write_from_file_any(file, val, context);
      return output;
    }

    vx_core::Type_boolean vx_data_file::Class_boolean_write_from_file_any::vx_f_boolean_write_from_file_any(vx_data_file::Type_file file, vx_core::Type_any val, vx_core::Type_context context) {
      return vx_data_file::f_boolean_write_from_file_any(file, val, context);
    }

  //}

  vx_data_file::Func_boolean_write_from_file_any vx_data_file::e_boolean_write_from_file_any = std::make_shared<vx_data_file::Class_boolean_write_from_file_any>();
  vx_data_file::Func_boolean_write_from_file_any vx_data_file::t_boolean_write_from_file_any = std::make_shared<vx_data_file::Class_boolean_write_from_file_any>();

  vx_core::Type_boolean vx_data_file::f_boolean_write_from_file_any(vx_data_file::Type_file file, vx_core::Type_any val, vx_core::Type_context context) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    output = vx_data_file::f_boolean_write_from_file_string(
      file,
      vx_core::f_string_from_any(val),
      context
    );
    return output;
  }

  /**
   * @function boolean_write_from_file_string
   * Write a File to Disk
   * @param  {file} file
   * @param  {string} text
   * @return {boolean}
   * (func boolean-write<-file-string)
   */
  //class Func_boolean_write_from_file_string {

    template <class T> std::shared_ptr<T> vx_data_file::Class_boolean_write_from_file_string::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_file::Func_boolean_write_from_file_string output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_file::Class_boolean_write_from_file_string::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_file::Func_boolean_write_from_file_string output;
      return output;
    }

    vx_core::Type_typedef vx_data_file::Class_boolean_write_from_file_string::vx_typedef() {return vx_data_file::t_boolean_write_from_file_string->vx_typedef();}

    vx_core::Type_funcdef vx_data_file::Class_boolean_write_from_file_string::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "boolean-write<-file-string", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_data_file::Class_boolean_write_from_file_string::vx_empty(std::shared_ptr<T> val) {return vx_data_file::e_boolean_write_from_file_string;}
    template <class T> std::shared_ptr<T> vx_data_file::Class_boolean_write_from_file_string::vx_type(std::shared_ptr<T> val) {return vx_data_file::t_boolean_write_from_file_string;}

    vx_core::Type_any vx_data_file::Class_boolean_write_from_file_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file file = vx_core::f_any_from_any(vx_data_file::t_file, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_string text = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(1)));
      vx_core::Type_context context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(2)));
      output = vx_data_file::f_boolean_write_from_file_string(file, text, context);
      return output;
    }

    vx_core::Type_boolean vx_data_file::Class_boolean_write_from_file_string::vx_f_boolean_write_from_file_string(vx_data_file::Type_file file, vx_core::Type_string text, vx_core::Type_context context) {
      return vx_data_file::f_boolean_write_from_file_string(file, text, context);
    }

  //}

  vx_data_file::Func_boolean_write_from_file_string vx_data_file::e_boolean_write_from_file_string = std::make_shared<vx_data_file::Class_boolean_write_from_file_string>();
  vx_data_file::Func_boolean_write_from_file_string vx_data_file::t_boolean_write_from_file_string = std::make_shared<vx_data_file::Class_boolean_write_from_file_string>();

  vx_core::Type_boolean vx_data_file::f_boolean_write_from_file_string(vx_data_file::Type_file file, vx_core::Type_string text, vx_core::Type_context context) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    try {
    } catch (std::exception err) {
      vx_core::Type_msg msg = vx_core::t_msg->vx_new_from_exception("boolean-write<-file-string", err);
      output = output->vx_copy(vx_core::t_boolean, {msg});
    }
    return output;
  }

  /**
   * @function file_read_from_file
   * Read a Text File from Disk
   * @param  {file} file
   * @return {file}
   * (func file-read<-file)
   */
  //class Func_file_read_from_file {

    template <class T> std::shared_ptr<T> vx_data_file::Class_file_read_from_file::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_file::Func_file_read_from_file output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_file::Class_file_read_from_file::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_file::Func_file_read_from_file output;
      return output;
    }

    vx_core::Type_typedef vx_data_file::Class_file_read_from_file::vx_typedef() {return vx_data_file::t_file_read_from_file->vx_typedef();}

    vx_core::Type_funcdef vx_data_file::Class_file_read_from_file::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "file-read<-file", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/data/file", // pkgname
          "file", // name
          ":struct", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_data_file::Class_file_read_from_file::vx_empty(std::shared_ptr<T> val) {return vx_data_file::e_file_read_from_file;}
    template <class T> std::shared_ptr<T> vx_data_file::Class_file_read_from_file::vx_type(std::shared_ptr<T> val) {return vx_data_file::t_file_read_from_file;}

    vx_core::Func_any_from_any_context vx_data_file::Class_file_read_from_file::fn_new(vx_core::Class_any_from_any_context::IFn fn) {return vx_core::e_any_from_any_context;}

    template <class T, class U> std::shared_ptr<T> vx_data_file::Class_file_read_from_file::f_any_from_any_context(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value, vx_core::Type_context context) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_data_file::Type_file inputval = (vx_data_file::Type_file)value;
      vx_core::Type_any outputval = vx_data_file::f_file_read_from_file(inputval, context);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_data_file::Class_file_read_from_file::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file file = vx_core::f_any_from_any(vx_data_file::t_file, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_context context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_data_file::f_file_read_from_file(file, context);
      return output;
    }

    vx_data_file::Type_file vx_data_file::Class_file_read_from_file::vx_f_file_read_from_file(vx_data_file::Type_file file, vx_core::Type_context context) {
      return vx_data_file::f_file_read_from_file(file, context);
    }

  //}

  vx_data_file::Func_file_read_from_file vx_data_file::e_file_read_from_file = std::make_shared<vx_data_file::Class_file_read_from_file>();
  vx_data_file::Func_file_read_from_file vx_data_file::t_file_read_from_file = std::make_shared<vx_data_file::Class_file_read_from_file>();

  vx_data_file::Type_file vx_data_file::f_file_read_from_file(vx_data_file::Type_file file, vx_core::Type_context context) {
    vx_data_file::Type_file output = vx_data_file::e_file;
    output = vx_core::f_copy(
      file,
      vx_core::t_anylist->vx_new(vx_core::t_anylist, {
        vx_core::t_string->vx_new_from_string(":text"),
        vx_data_file::f_string_read_from_file(file, context)
      })
    );
    return output;
  }

  /**
   * @function name_from_file
   * Returns path and name from file.
   * @param  {file} file
   * @return {string}
   * (func name<-file)
   */
  //class Func_name_from_file {

    template <class T> std::shared_ptr<T> vx_data_file::Class_name_from_file::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_file::Func_name_from_file output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_file::Class_name_from_file::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_file::Func_name_from_file output;
      return output;
    }

    vx_core::Type_typedef vx_data_file::Class_name_from_file::vx_typedef() {return vx_data_file::t_name_from_file->vx_typedef();}

    vx_core::Type_funcdef vx_data_file::Class_name_from_file::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "name<-file", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_data_file::Class_name_from_file::vx_empty(std::shared_ptr<T> val) {return vx_data_file::e_name_from_file;}
    template <class T> std::shared_ptr<T> vx_data_file::Class_name_from_file::vx_type(std::shared_ptr<T> val) {return vx_data_file::t_name_from_file;}

    vx_core::Func_any_from_any vx_data_file::Class_name_from_file::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_data_file::Class_name_from_file::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_data_file::Type_file inputval = (vx_data_file::Type_file)value;
      vx_core::Type_any outputval = vx_data_file::f_name_from_file(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_data_file::Class_name_from_file::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file file = vx_core::f_any_from_any(vx_data_file::t_file, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_data_file::f_name_from_file(file);
      return output;
    }

    vx_core::Type_string vx_data_file::Class_name_from_file::vx_f_name_from_file(vx_data_file::Type_file file) {
      return vx_data_file::f_name_from_file(file);
    }

  //}

  vx_data_file::Func_name_from_file vx_data_file::e_name_from_file = std::make_shared<vx_data_file::Class_name_from_file>();
  vx_data_file::Func_name_from_file vx_data_file::t_name_from_file = std::make_shared<vx_data_file::Class_name_from_file>();

  vx_core::Type_string vx_data_file::f_name_from_file(vx_data_file::Type_file file) {
    vx_core::Type_string output = vx_core::e_string;
    output = file->name();
    return output;
  }

  /**
   * @function path_from_file
   * Returns path and name from file.
   * @param  {file} file
   * @return {string}
   * (func path<-file)
   */
  //class Func_path_from_file {

    template <class T> std::shared_ptr<T> vx_data_file::Class_path_from_file::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_file::Func_path_from_file output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_file::Class_path_from_file::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_file::Func_path_from_file output;
      return output;
    }

    vx_core::Type_typedef vx_data_file::Class_path_from_file::vx_typedef() {return vx_data_file::t_path_from_file->vx_typedef();}

    vx_core::Type_funcdef vx_data_file::Class_path_from_file::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "path<-file", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_data_file::Class_path_from_file::vx_empty(std::shared_ptr<T> val) {return vx_data_file::e_path_from_file;}
    template <class T> std::shared_ptr<T> vx_data_file::Class_path_from_file::vx_type(std::shared_ptr<T> val) {return vx_data_file::t_path_from_file;}

    vx_core::Func_any_from_any vx_data_file::Class_path_from_file::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_data_file::Class_path_from_file::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_data_file::Type_file inputval = (vx_data_file::Type_file)value;
      vx_core::Type_any outputval = vx_data_file::f_path_from_file(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_data_file::Class_path_from_file::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file file = vx_core::f_any_from_any(vx_data_file::t_file, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_data_file::f_path_from_file(file);
      return output;
    }

    vx_core::Type_string vx_data_file::Class_path_from_file::vx_f_path_from_file(vx_data_file::Type_file file) {
      return vx_data_file::f_path_from_file(file);
    }

  //}

  vx_data_file::Func_path_from_file vx_data_file::e_path_from_file = std::make_shared<vx_data_file::Class_path_from_file>();
  vx_data_file::Func_path_from_file vx_data_file::t_path_from_file = std::make_shared<vx_data_file::Class_path_from_file>();

  vx_core::Type_string vx_data_file::f_path_from_file(vx_data_file::Type_file file) {
    vx_core::Type_string output = vx_core::e_string;
    output = file->path();
    return output;
  }

  /**
   * @function pathcurrent_from_os
   * Returns current system path.
   * @return {string}
   * (func pathcurrent<-os)
   */
  //class Func_pathcurrent_from_os {

    template <class T> std::shared_ptr<T> vx_data_file::Class_pathcurrent_from_os::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_file::Func_pathcurrent_from_os output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_file::Class_pathcurrent_from_os::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_file::Func_pathcurrent_from_os output;
      return output;
    }

    vx_core::Type_typedef vx_data_file::Class_pathcurrent_from_os::vx_typedef() {return vx_data_file::t_pathcurrent_from_os->vx_typedef();}

    vx_core::Type_funcdef vx_data_file::Class_pathcurrent_from_os::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "pathcurrent<-os", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_data_file::Class_pathcurrent_from_os::vx_empty(std::shared_ptr<T> val) {return vx_data_file::e_pathcurrent_from_os;}
    template <class T> std::shared_ptr<T> vx_data_file::Class_pathcurrent_from_os::vx_type(std::shared_ptr<T> val) {return vx_data_file::t_pathcurrent_from_os;}

    vx_core::Type_any vx_data_file::Class_pathcurrent_from_os::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      output = vx_data_file::f_pathcurrent_from_os();
      return output;
    }

    vx_core::Type_string vx_data_file::Class_pathcurrent_from_os::vx_f_pathcurrent_from_os() {
      return vx_data_file::f_pathcurrent_from_os();
    }

  //}

  vx_data_file::Func_pathcurrent_from_os vx_data_file::e_pathcurrent_from_os = std::make_shared<vx_data_file::Class_pathcurrent_from_os>();
  vx_data_file::Func_pathcurrent_from_os vx_data_file::t_pathcurrent_from_os = std::make_shared<vx_data_file::Class_pathcurrent_from_os>();

  vx_core::Type_string vx_data_file::f_pathcurrent_from_os() {
    vx_core::Type_string output = vx_core::e_string;
    return output;
  }

  /**
   * @function pathfull_from_file
   * Returns full path and name from file.
   * @param  {file} file
   * @return {string}
   * (func pathfull<-file)
   */
  //class Func_pathfull_from_file {

    template <class T> std::shared_ptr<T> vx_data_file::Class_pathfull_from_file::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_file::Func_pathfull_from_file output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_file::Class_pathfull_from_file::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_file::Func_pathfull_from_file output;
      return output;
    }

    vx_core::Type_typedef vx_data_file::Class_pathfull_from_file::vx_typedef() {return vx_data_file::t_pathfull_from_file->vx_typedef();}

    vx_core::Type_funcdef vx_data_file::Class_pathfull_from_file::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "pathfull<-file", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_data_file::Class_pathfull_from_file::vx_empty(std::shared_ptr<T> val) {return vx_data_file::e_pathfull_from_file;}
    template <class T> std::shared_ptr<T> vx_data_file::Class_pathfull_from_file::vx_type(std::shared_ptr<T> val) {return vx_data_file::t_pathfull_from_file;}

    vx_core::Func_any_from_any vx_data_file::Class_pathfull_from_file::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_data_file::Class_pathfull_from_file::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_data_file::Type_file inputval = (vx_data_file::Type_file)value;
      vx_core::Type_any outputval = vx_data_file::f_pathfull_from_file(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_data_file::Class_pathfull_from_file::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file file = vx_core::f_any_from_any(vx_data_file::t_file, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_data_file::f_pathfull_from_file(file);
      return output;
    }

    vx_core::Type_string vx_data_file::Class_pathfull_from_file::vx_f_pathfull_from_file(vx_data_file::Type_file file) {
      return vx_data_file::f_pathfull_from_file(file);
    }

  //}

  vx_data_file::Func_pathfull_from_file vx_data_file::e_pathfull_from_file = std::make_shared<vx_data_file::Class_pathfull_from_file>();
  vx_data_file::Func_pathfull_from_file vx_data_file::t_pathfull_from_file = std::make_shared<vx_data_file::Class_pathfull_from_file>();

  vx_core::Type_string vx_data_file::f_pathfull_from_file(vx_data_file::Type_file file) {
    vx_core::Type_string output = vx_core::e_string;
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->fn_new([file]() {
        vx_core::Type_string path = vx_data_file::f_path_from_file(file);
        vx_core::Type_string name = vx_data_file::f_name_from_file(file);
        return vx_core::f_new(
          vx_core::t_string,
          vx_core::t_anylist->vx_new(vx_core::t_anylist, {
            path,
            vx_core::t_string->vx_new_from_string("/"),
            name
          })
        );
      })
    );
    return output;
  }

  /**
   * @function string_read_from_file
   * Read text from a File
   * @param  {file} file
   * @return {string}
   * (func string-read<-file)
   */
  //class Func_string_read_from_file {

    template <class T> std::shared_ptr<T> vx_data_file::Class_string_read_from_file::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_file::Func_string_read_from_file output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_file::Class_string_read_from_file::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_file::Func_string_read_from_file output;
      return output;
    }

    vx_core::Type_typedef vx_data_file::Class_string_read_from_file::vx_typedef() {return vx_data_file::t_string_read_from_file->vx_typedef();}

    vx_core::Type_funcdef vx_data_file::Class_string_read_from_file::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "string-read<-file", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
          vx_core::e_typelist, // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_data_file::Class_string_read_from_file::vx_empty(std::shared_ptr<T> val) {return vx_data_file::e_string_read_from_file;}
    template <class T> std::shared_ptr<T> vx_data_file::Class_string_read_from_file::vx_type(std::shared_ptr<T> val) {return vx_data_file::t_string_read_from_file;}

    vx_core::Func_any_from_any_context vx_data_file::Class_string_read_from_file::fn_new(vx_core::Class_any_from_any_context::IFn fn) {return vx_core::e_any_from_any_context;}

    template <class T, class U> std::shared_ptr<T> vx_data_file::Class_string_read_from_file::f_any_from_any_context(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value, vx_core::Type_context context) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_data_file::Type_file inputval = (vx_data_file::Type_file)value;
      vx_core::Type_any outputval = vx_data_file::f_string_read_from_file(inputval, context);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_data_file::Class_string_read_from_file::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file file = vx_core::f_any_from_any(vx_data_file::t_file, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_context context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_data_file::f_string_read_from_file(file, context);
      return output;
    }

    vx_core::Type_string vx_data_file::Class_string_read_from_file::vx_f_string_read_from_file(vx_data_file::Type_file file, vx_core::Type_context context) {
      return vx_data_file::f_string_read_from_file(file, context);
    }

  //}

  vx_data_file::Func_string_read_from_file vx_data_file::e_string_read_from_file = std::make_shared<vx_data_file::Class_string_read_from_file>();
  vx_data_file::Func_string_read_from_file vx_data_file::t_string_read_from_file = std::make_shared<vx_data_file::Class_string_read_from_file>();

  vx_core::Type_string vx_data_file::f_string_read_from_file(vx_data_file::Type_file file, vx_core::Type_context context) {
    vx_core::Type_string output = vx_core::e_string;
    try {
    } catch (std::exception err) {
      vx_core::Type_msg msg = vx_core::t_msg->vx_new_from_exception("string-read<-file", err);
      output = output->vx_copy(vx_core::t_string, {msg});
    }
    return output;
  }


//}
