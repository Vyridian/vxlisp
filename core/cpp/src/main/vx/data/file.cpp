#include <exception>
#include <string>
#include "../../vx/core.hpp"
#include "../../vx/data/textblock.hpp"
#include "file.hpp"

namespace vx_data_file {
// :body

//vx_core::Type_string Class_file::string_read_from_path(std::string path) {
//  vx_core::Type_string output = vx_core::e_string();
//  std::ifstream filestream (path);
//  if (filestream.is_open()) {
//    std::string text;
//    std::string line;
//    while (std::getline(filestream, line)) {
//      text += line + '\n';
//    }
//    filestream.close();
//    output = vx_core::vx_new_string_from_text(text);
//  } else {
//    msg = vx_core::t_msg()->vx_new_from_errortext("File not found:" + path);
//    output = vx_core::vx_new(vx_core::t_string(), {msg});
//  }
//  return output;
//}

//vx_core::Type_boolean Class_file::boolean_write_from_path_text(std::string path, std::string text) {
//  vx_core::Type_boolean output = vx_core::c_false();
//  std::ofstream filestream;
//  if (filestream.is_open()) {
//    filestream.open(path);
//    filestream << text;
//    filestream.close();
//  } else {
//    msg = vx_core::t_msg()->vx_new_from_errortext("File not found:" + path);
//    output = vx_core::vx_copy(vx_core::c_false(), {msg});
//  }
//  return output;
//}
/*
#include <iostream>
#include <fstream>
*/

  // (type file)
  // class Class_file {
    Abstract_file::~Abstract_file() {}

    Class_file::Class_file() : Abstract_file::Abstract_file() {
      vx_core::refcount += 1;
    }
    Class_file::~Class_file() {
      vx_core::refcount -= 1;
    }
    // name()
    vx_core::Type_string Class_file::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // format()
    vx_data_file::Type_fileformat Class_file::format() const {
      vx_data_file::Type_fileformat output = this->vx_p_format;
      if (output == NULL) {
        output = vx_data_file::e_fileformat();
      }
      return output;
    }

    // path()
    vx_core::Type_string Class_file::path() const {
      vx_core::Type_string output = this->vx_p_path;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // permission()
    vx_core::Type_permission Class_file::permission() const {
      vx_core::Type_permission output = this->vx_p_permission;
      if (output == NULL) {
        output = vx_core::e_permission();
      }
      return output;
    }

    // text()
    vx_core::Type_string Class_file::text() const {
      vx_core::Type_string output = this->vx_p_text;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_file::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
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
    vx_core::vx_Type_mapany Class_file::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":name"] = this->name();
      output[":format"] = this->format();
      output[":path"] = this->path();
      output[":permission"] = this->permission();
      output[":text"] = this->text();
      return output;
    }

    vx_core::Type_any Class_file::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_file::e_file(), vals);
    }
    vx_core::Type_any Class_file::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_file::Type_file output = vx_data_file::e_file();
      vx_data_file::Type_file val = vx_core::vx_any_from_any(vx_data_file::t_file(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_name = val->name();
      vx_data_file::Type_fileformat vx_p_format = val->format();
      vx_core::Type_string vx_p_path = val->path();
      vx_core::Type_permission vx_p_permission = val->permission();
      vx_core::Type_string vx_p_text = val->text();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string()) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            testkey = valstr->vx_string();
          }
          if (false) {
          } else if (testkey == ":name") {
            key = testkey;
          } else if (testkey == ":format") {
            key = testkey;
          } else if (testkey == ":path") {
            key = testkey;
          } else if (testkey == ":permission") {
            key = testkey;
          } else if (testkey == ":text") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new file) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_name = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new file :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":format") {
            if (valsubtype == vx_data_file::t_fileformat()) {
              vx_p_format = vx_core::vx_any_from_any(vx_data_file::t_fileformat(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new file :format " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":path") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_path = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new file :path " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":permission") {
            if (valsubtype == vx_core::t_permission()) {
              vx_p_permission = vx_core::vx_any_from_any(vx_core::t_permission(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new file :permission " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":text") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_text = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new file :text " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new file) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_data_file::Class_file();
      output->vx_p_name = vx_p_name;
      output->vx_p_format = vx_p_format;
      output->vx_p_path = vx_p_path;
      output->vx_p_permission = vx_p_permission;
      output->vx_p_text = vx_p_text;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_file::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_file::Class_file::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_file::vx_empty() const {return vx_data_file::e_file();}
    vx_core::Type_any Class_file::vx_type() const {return vx_data_file::t_file();}

    vx_core::Type_typedef Class_file::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/file", // pkgname
        "file", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type fileformat)
  // class Class_fileformat {
    Abstract_fileformat::~Abstract_fileformat() {}

    Class_fileformat::Class_fileformat() : Abstract_fileformat::Abstract_fileformat() {
      vx_core::refcount += 1;
    }
    Class_fileformat::~Class_fileformat() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_fileformat::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_file::e_fileformat(), vals);
    }
    vx_core::Type_any Class_fileformat::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_file::Type_fileformat output = vx_data_file::e_fileformat();
      return output;
    }

    vx_core::Type_msgblock Class_fileformat::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_file::Class_fileformat::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_fileformat::vx_empty() const {return vx_data_file::e_fileformat();}
    vx_core::Type_any Class_fileformat::vx_type() const {return vx_data_file::t_fileformat();}

    vx_core::Type_typedef Class_fileformat::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/file", // pkgname
        "fileformat", // name
        ":string", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (func boolean-exists<-file)
  vx_core::Type_boolean f_boolean_exists_from_file(vx_data_file::Type_file file) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    return output;
  }

  // (func boolean-exists<-file)
  // class Class_boolean_exists_from_file {
    Abstract_boolean_exists_from_file::~Abstract_boolean_exists_from_file() {}

    Class_boolean_exists_from_file::Class_boolean_exists_from_file() : Abstract_boolean_exists_from_file::Abstract_boolean_exists_from_file() {
      vx_core::refcount += 1;
    }
    Class_boolean_exists_from_file::~Class_boolean_exists_from_file() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_boolean_exists_from_file::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_boolean_exists_from_file output = vx_data_file::e_boolean_exists_from_file();
      return output;
    }

    vx_core::Type_any Class_boolean_exists_from_file::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_boolean_exists_from_file output = vx_data_file::e_boolean_exists_from_file();
      return output;
    }

    vx_core::Type_typedef Class_boolean_exists_from_file::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_boolean_exists_from_file::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "boolean-exists<-file", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_boolean_exists_from_file::vx_empty() const {return vx_data_file::e_boolean_exists_from_file();}
    vx_core::Type_any Class_boolean_exists_from_file::vx_type() const {return vx_data_file::t_boolean_exists_from_file();}
    vx_core::Type_msgblock Class_boolean_exists_from_file::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_exists_from_file::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_boolean_exists_from_file::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_boolean_exists_from_file::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_data_file::Type_file inputval = vx_core::vx_any_from_any(vx_data_file::t_file(), val);
      output = vx_data_file::f_boolean_exists_from_file(inputval);
      return output;
    }

    vx_core::Type_any Class_boolean_exists_from_file::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_data_file::Type_file file = vx_core::vx_any_from_any(vx_data_file::t_file(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_file::f_boolean_exists_from_file(file);
      return output;
    }

  //}

  // (func boolean-write<-file-any)
  vx_core::Type_boolean f_boolean_write_from_file_any(vx_data_file::Type_file file, vx_core::Type_any val, vx_core::Type_context context) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    output = vx_data_file::f_boolean_write_from_file_string(
      file,
      vx_core::f_string_from_any(val),
      context
    );
    return output;
  }

  // (func boolean-write<-file-any)
  // class Class_boolean_write_from_file_any {
    Abstract_boolean_write_from_file_any::~Abstract_boolean_write_from_file_any() {}

    Class_boolean_write_from_file_any::Class_boolean_write_from_file_any() : Abstract_boolean_write_from_file_any::Abstract_boolean_write_from_file_any() {
      vx_core::refcount += 1;
    }
    Class_boolean_write_from_file_any::~Class_boolean_write_from_file_any() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_boolean_write_from_file_any::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_boolean_write_from_file_any output = vx_data_file::e_boolean_write_from_file_any();
      return output;
    }

    vx_core::Type_any Class_boolean_write_from_file_any::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_boolean_write_from_file_any output = vx_data_file::e_boolean_write_from_file_any();
      return output;
    }

    vx_core::Type_typedef Class_boolean_write_from_file_any::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_boolean_write_from_file_any::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "boolean-write<-file-any", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_boolean_write_from_file_any::vx_empty() const {return vx_data_file::e_boolean_write_from_file_any();}
    vx_core::Type_any Class_boolean_write_from_file_any::vx_type() const {return vx_data_file::t_boolean_write_from_file_any();}
    vx_core::Type_msgblock Class_boolean_write_from_file_any::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_write_from_file_any::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_boolean_write_from_file_any::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_data_file::Type_file file = vx_core::vx_any_from_any(vx_data_file::t_file(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any val = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context(), arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_data_file::f_boolean_write_from_file_any(file, val, context);
      return output;
    }

  //}

  // (func boolean-write<-file-string)
  vx_core::Type_boolean f_boolean_write_from_file_string(vx_data_file::Type_file file, vx_core::Type_string text, vx_core::Type_context context) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    try {
    } catch (std::exception err) {
      vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_exception("boolean-write<-file-string", err);
      output = vx_core::vx_copy(vx_core::t_boolean(), {msg});
    }
    return output;
  }

  // (func boolean-write<-file-string)
  // class Class_boolean_write_from_file_string {
    Abstract_boolean_write_from_file_string::~Abstract_boolean_write_from_file_string() {}

    Class_boolean_write_from_file_string::Class_boolean_write_from_file_string() : Abstract_boolean_write_from_file_string::Abstract_boolean_write_from_file_string() {
      vx_core::refcount += 1;
    }
    Class_boolean_write_from_file_string::~Class_boolean_write_from_file_string() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_boolean_write_from_file_string::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_boolean_write_from_file_string output = vx_data_file::e_boolean_write_from_file_string();
      return output;
    }

    vx_core::Type_any Class_boolean_write_from_file_string::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_boolean_write_from_file_string output = vx_data_file::e_boolean_write_from_file_string();
      return output;
    }

    vx_core::Type_typedef Class_boolean_write_from_file_string::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_boolean_write_from_file_string::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "boolean-write<-file-string", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_boolean_write_from_file_string::vx_empty() const {return vx_data_file::e_boolean_write_from_file_string();}
    vx_core::Type_any Class_boolean_write_from_file_string::vx_type() const {return vx_data_file::t_boolean_write_from_file_string();}
    vx_core::Type_msgblock Class_boolean_write_from_file_string::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_write_from_file_string::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_boolean_write_from_file_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_data_file::Type_file file = vx_core::vx_any_from_any(vx_data_file::t_file(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context(), arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_data_file::f_boolean_write_from_file_string(file, text, context);
      return output;
    }

  //}

  // (func file-read<-file)
  vx_data_file::Type_file f_file_read_from_file(vx_data_file::Type_file file, vx_core::Type_context context) {
    vx_data_file::Type_file output = vx_data_file::e_file();
    output = vx_core::f_copy(
      file,
      vx_core::vx_new(vx_core::t_anylist(), {
        vx_core::vx_new_string(":text"),
        vx_data_file::f_string_read_from_file(file, context)
      })
    );
    return output;
  }

  // (func file-read<-file)
  // class Class_file_read_from_file {
    Abstract_file_read_from_file::~Abstract_file_read_from_file() {}

    Class_file_read_from_file::Class_file_read_from_file() : Abstract_file_read_from_file::Abstract_file_read_from_file() {
      vx_core::refcount += 1;
    }
    Class_file_read_from_file::~Class_file_read_from_file() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_file_read_from_file::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_file_read_from_file output = vx_data_file::e_file_read_from_file();
      return output;
    }

    vx_core::Type_any Class_file_read_from_file::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_file_read_from_file output = vx_data_file::e_file_read_from_file();
      return output;
    }

    vx_core::Type_typedef Class_file_read_from_file::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/file", // pkgname
        "file", // name
        ":struct", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_file_read_from_file::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "file-read<-file", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_file_read_from_file::vx_empty() const {return vx_data_file::e_file_read_from_file();}
    vx_core::Type_any Class_file_read_from_file::vx_type() const {return vx_data_file::t_file_read_from_file();}
    vx_core::Type_msgblock Class_file_read_from_file::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_file_read_from_file::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_file_read_from_file::vx_fn_new(vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context();
    }

    vx_core::Type_any Class_file_read_from_file::vx_any_from_any_context(vx_core::Type_any val, vx_core::Type_context context) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_data_file::Type_file inputval = vx_core::vx_any_from_any(vx_data_file::t_file(), val);
      output = vx_data_file::f_file_read_from_file(inputval, context);
      return output;
    }

    vx_core::Type_any Class_file_read_from_file::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_data_file::Type_file file = vx_core::vx_any_from_any(vx_data_file::t_file(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_file::f_file_read_from_file(file, context);
      return output;
    }

  //}

  // (func name<-file)
  vx_core::Type_string f_name_from_file(vx_data_file::Type_file file) {
    vx_core::Type_string output = vx_core::e_string();
    output = file->name();
    return output;
  }

  // (func name<-file)
  // class Class_name_from_file {
    Abstract_name_from_file::~Abstract_name_from_file() {}

    Class_name_from_file::Class_name_from_file() : Abstract_name_from_file::Abstract_name_from_file() {
      vx_core::refcount += 1;
    }
    Class_name_from_file::~Class_name_from_file() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_name_from_file::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_name_from_file output = vx_data_file::e_name_from_file();
      return output;
    }

    vx_core::Type_any Class_name_from_file::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_name_from_file output = vx_data_file::e_name_from_file();
      return output;
    }

    vx_core::Type_typedef Class_name_from_file::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "string", // name
        "string", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_name_from_file::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "name<-file", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_name_from_file::vx_empty() const {return vx_data_file::e_name_from_file();}
    vx_core::Type_any Class_name_from_file::vx_type() const {return vx_data_file::t_name_from_file();}
    vx_core::Type_msgblock Class_name_from_file::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_name_from_file::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_name_from_file::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_name_from_file::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_data_file::Type_file inputval = vx_core::vx_any_from_any(vx_data_file::t_file(), val);
      output = vx_data_file::f_name_from_file(inputval);
      return output;
    }

    vx_core::Type_any Class_name_from_file::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_data_file::Type_file file = vx_core::vx_any_from_any(vx_data_file::t_file(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_file::f_name_from_file(file);
      return output;
    }

  //}

  // (func path<-file)
  vx_core::Type_string f_path_from_file(vx_data_file::Type_file file) {
    vx_core::Type_string output = vx_core::e_string();
    output = file->path();
    return output;
  }

  // (func path<-file)
  // class Class_path_from_file {
    Abstract_path_from_file::~Abstract_path_from_file() {}

    Class_path_from_file::Class_path_from_file() : Abstract_path_from_file::Abstract_path_from_file() {
      vx_core::refcount += 1;
    }
    Class_path_from_file::~Class_path_from_file() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_path_from_file::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_path_from_file output = vx_data_file::e_path_from_file();
      return output;
    }

    vx_core::Type_any Class_path_from_file::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_path_from_file output = vx_data_file::e_path_from_file();
      return output;
    }

    vx_core::Type_typedef Class_path_from_file::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "string", // name
        "string", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_path_from_file::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "path<-file", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_path_from_file::vx_empty() const {return vx_data_file::e_path_from_file();}
    vx_core::Type_any Class_path_from_file::vx_type() const {return vx_data_file::t_path_from_file();}
    vx_core::Type_msgblock Class_path_from_file::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_path_from_file::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_path_from_file::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_path_from_file::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_data_file::Type_file inputval = vx_core::vx_any_from_any(vx_data_file::t_file(), val);
      output = vx_data_file::f_path_from_file(inputval);
      return output;
    }

    vx_core::Type_any Class_path_from_file::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_data_file::Type_file file = vx_core::vx_any_from_any(vx_data_file::t_file(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_file::f_path_from_file(file);
      return output;
    }

  //}

  // (func pathcurrent<-os)
  vx_core::Type_string f_pathcurrent_from_os() {
    vx_core::Type_string output = vx_core::e_string();
    return output;
  }

  // (func pathcurrent<-os)
  // class Class_pathcurrent_from_os {
    Abstract_pathcurrent_from_os::~Abstract_pathcurrent_from_os() {}

    Class_pathcurrent_from_os::Class_pathcurrent_from_os() : Abstract_pathcurrent_from_os::Abstract_pathcurrent_from_os() {
      vx_core::refcount += 1;
    }
    Class_pathcurrent_from_os::~Class_pathcurrent_from_os() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_pathcurrent_from_os::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_pathcurrent_from_os output = vx_data_file::e_pathcurrent_from_os();
      return output;
    }

    vx_core::Type_any Class_pathcurrent_from_os::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_pathcurrent_from_os output = vx_data_file::e_pathcurrent_from_os();
      return output;
    }

    vx_core::Type_typedef Class_pathcurrent_from_os::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "string", // name
        "string", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_pathcurrent_from_os::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "pathcurrent<-os", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_pathcurrent_from_os::vx_empty() const {return vx_data_file::e_pathcurrent_from_os();}
    vx_core::Type_any Class_pathcurrent_from_os::vx_type() const {return vx_data_file::t_pathcurrent_from_os();}
    vx_core::Type_msgblock Class_pathcurrent_from_os::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_pathcurrent_from_os::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_pathcurrent_from_os::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      output = vx_data_file::f_pathcurrent_from_os();
      return output;
    }

  //}

  // (func pathfull<-file)
  vx_core::Type_string f_pathfull_from_file(vx_data_file::Type_file file) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_let(
      vx_core::t_string(),
      vx_core::t_any_from_func()->vx_fn_new([file]() {
        vx_core::Type_string path = vx_data_file::f_path_from_file(file);
        vx_core::Type_string name = vx_data_file::f_name_from_file(file);
        return vx_core::f_new(
          vx_core::t_string(),
          vx_core::vx_new(vx_core::t_anylist(), {
            path,
            vx_core::vx_new_string("/"),
            name
          })
        );
      })
    );
    return output;
  }

  // (func pathfull<-file)
  // class Class_pathfull_from_file {
    Abstract_pathfull_from_file::~Abstract_pathfull_from_file() {}

    Class_pathfull_from_file::Class_pathfull_from_file() : Abstract_pathfull_from_file::Abstract_pathfull_from_file() {
      vx_core::refcount += 1;
    }
    Class_pathfull_from_file::~Class_pathfull_from_file() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_pathfull_from_file::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_pathfull_from_file output = vx_data_file::e_pathfull_from_file();
      return output;
    }

    vx_core::Type_any Class_pathfull_from_file::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_pathfull_from_file output = vx_data_file::e_pathfull_from_file();
      return output;
    }

    vx_core::Type_typedef Class_pathfull_from_file::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "string", // name
        "string", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_pathfull_from_file::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "pathfull<-file", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_pathfull_from_file::vx_empty() const {return vx_data_file::e_pathfull_from_file();}
    vx_core::Type_any Class_pathfull_from_file::vx_type() const {return vx_data_file::t_pathfull_from_file();}
    vx_core::Type_msgblock Class_pathfull_from_file::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_pathfull_from_file::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_pathfull_from_file::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_pathfull_from_file::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_data_file::Type_file inputval = vx_core::vx_any_from_any(vx_data_file::t_file(), val);
      output = vx_data_file::f_pathfull_from_file(inputval);
      return output;
    }

    vx_core::Type_any Class_pathfull_from_file::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_data_file::Type_file file = vx_core::vx_any_from_any(vx_data_file::t_file(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_file::f_pathfull_from_file(file);
      return output;
    }

  //}

  // (func string-read<-file)
  vx_core::Type_string f_string_read_from_file(vx_data_file::Type_file file, vx_core::Type_context context) {
    vx_core::Type_string output = vx_core::e_string();
    try {
    } catch (std::exception err) {
      vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_exception("string-read<-file", err);
      output = vx_core::vx_copy(vx_core::t_string(), {msg});
    }
    return output;
  }

  // (func string-read<-file)
  // class Class_string_read_from_file {
    Abstract_string_read_from_file::~Abstract_string_read_from_file() {}

    Class_string_read_from_file::Class_string_read_from_file() : Abstract_string_read_from_file::Abstract_string_read_from_file() {
      vx_core::refcount += 1;
    }
    Class_string_read_from_file::~Class_string_read_from_file() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_string_read_from_file::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_string_read_from_file output = vx_data_file::e_string_read_from_file();
      return output;
    }

    vx_core::Type_any Class_string_read_from_file::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_string_read_from_file output = vx_data_file::e_string_read_from_file();
      return output;
    }

    vx_core::Type_typedef Class_string_read_from_file::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "string", // name
        "string", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_string_read_from_file::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "string-read<-file", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_string_read_from_file::vx_empty() const {return vx_data_file::e_string_read_from_file();}
    vx_core::Type_any Class_string_read_from_file::vx_type() const {return vx_data_file::t_string_read_from_file();}
    vx_core::Type_msgblock Class_string_read_from_file::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_read_from_file::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_string_read_from_file::vx_fn_new(vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context();
    }

    vx_core::Type_any Class_string_read_from_file::vx_any_from_any_context(vx_core::Type_any val, vx_core::Type_context context) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_data_file::Type_file inputval = vx_core::vx_any_from_any(vx_data_file::t_file(), val);
      output = vx_data_file::f_string_read_from_file(inputval, context);
      return output;
    }

    vx_core::Type_any Class_string_read_from_file::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_data_file::Type_file file = vx_core::vx_any_from_any(vx_data_file::t_file(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_file::f_string_read_from_file(file, context);
      return output;
    }

  //}

  vx_data_file::vx_Class_package* vx_package = new vx_data_file::vx_Class_package();

  vx_data_file::Type_file e_file() {
    vx_data_file::Type_file output = vx_data_file::vx_package->e_file;
    if (output == NULL) {
      output = new Class_file();
      vx_core::vx_reserve_empty(output);
      vx_data_file::vx_package->e_file = output;
    }
    return output;
  }
  vx_data_file::Type_file t_file() {
    vx_data_file::Type_file output = vx_data_file::vx_package->t_file;
    if (output == NULL) {
      output = new Class_file();
      vx_core::vx_reserve_type(output);
      vx_data_file::vx_package->t_file = output;
    }
    return output;
  }

  vx_data_file::Type_fileformat e_fileformat() {
    vx_data_file::Type_fileformat output = vx_data_file::vx_package->e_fileformat;
    if (output == NULL) {
      output = new Class_fileformat();
      vx_core::vx_reserve_empty(output);
      vx_data_file::vx_package->e_fileformat = output;
    }
    return output;
  }
  vx_data_file::Type_fileformat t_fileformat() {
    vx_data_file::Type_fileformat output = vx_data_file::vx_package->t_fileformat;
    if (output == NULL) {
      output = new Class_fileformat();
      vx_core::vx_reserve_type(output);
      vx_data_file::vx_package->t_fileformat = output;
    }
    return output;
  }

  // (func boolean-exists<-file)
  vx_data_file::Func_boolean_exists_from_file e_boolean_exists_from_file() {
    vx_data_file::Func_boolean_exists_from_file output = vx_data_file::vx_package->e_boolean_exists_from_file;
    if (output == NULL) {
      output = new vx_data_file::Class_boolean_exists_from_file();
      vx_core::vx_reserve_empty(output);
      vx_data_file::vx_package->e_boolean_exists_from_file = output;
    }
    return output;
  }
  vx_data_file::Func_boolean_exists_from_file t_boolean_exists_from_file() {
    vx_data_file::Func_boolean_exists_from_file output = vx_data_file::vx_package->t_boolean_exists_from_file;
    if (output == NULL) {
      output = new vx_data_file::Class_boolean_exists_from_file();
      vx_core::vx_reserve_type(output);
      vx_data_file::vx_package->t_boolean_exists_from_file = output;
    }
    return output;
  }

  // (func boolean-write<-file-any)
  vx_data_file::Func_boolean_write_from_file_any e_boolean_write_from_file_any() {
    vx_data_file::Func_boolean_write_from_file_any output = vx_data_file::vx_package->e_boolean_write_from_file_any;
    if (output == NULL) {
      output = new vx_data_file::Class_boolean_write_from_file_any();
      vx_core::vx_reserve_empty(output);
      vx_data_file::vx_package->e_boolean_write_from_file_any = output;
    }
    return output;
  }
  vx_data_file::Func_boolean_write_from_file_any t_boolean_write_from_file_any() {
    vx_data_file::Func_boolean_write_from_file_any output = vx_data_file::vx_package->t_boolean_write_from_file_any;
    if (output == NULL) {
      output = new vx_data_file::Class_boolean_write_from_file_any();
      vx_core::vx_reserve_type(output);
      vx_data_file::vx_package->t_boolean_write_from_file_any = output;
    }
    return output;
  }

  // (func boolean-write<-file-string)
  vx_data_file::Func_boolean_write_from_file_string e_boolean_write_from_file_string() {
    vx_data_file::Func_boolean_write_from_file_string output = vx_data_file::vx_package->e_boolean_write_from_file_string;
    if (output == NULL) {
      output = new vx_data_file::Class_boolean_write_from_file_string();
      vx_core::vx_reserve_empty(output);
      vx_data_file::vx_package->e_boolean_write_from_file_string = output;
    }
    return output;
  }
  vx_data_file::Func_boolean_write_from_file_string t_boolean_write_from_file_string() {
    vx_data_file::Func_boolean_write_from_file_string output = vx_data_file::vx_package->t_boolean_write_from_file_string;
    if (output == NULL) {
      output = new vx_data_file::Class_boolean_write_from_file_string();
      vx_core::vx_reserve_type(output);
      vx_data_file::vx_package->t_boolean_write_from_file_string = output;
    }
    return output;
  }

  // (func file-read<-file)
  vx_data_file::Func_file_read_from_file e_file_read_from_file() {
    vx_data_file::Func_file_read_from_file output = vx_data_file::vx_package->e_file_read_from_file;
    if (output == NULL) {
      output = new vx_data_file::Class_file_read_from_file();
      vx_core::vx_reserve_empty(output);
      vx_data_file::vx_package->e_file_read_from_file = output;
    }
    return output;
  }
  vx_data_file::Func_file_read_from_file t_file_read_from_file() {
    vx_data_file::Func_file_read_from_file output = vx_data_file::vx_package->t_file_read_from_file;
    if (output == NULL) {
      output = new vx_data_file::Class_file_read_from_file();
      vx_core::vx_reserve_type(output);
      vx_data_file::vx_package->t_file_read_from_file = output;
    }
    return output;
  }

  // (func name<-file)
  vx_data_file::Func_name_from_file e_name_from_file() {
    vx_data_file::Func_name_from_file output = vx_data_file::vx_package->e_name_from_file;
    if (output == NULL) {
      output = new vx_data_file::Class_name_from_file();
      vx_core::vx_reserve_empty(output);
      vx_data_file::vx_package->e_name_from_file = output;
    }
    return output;
  }
  vx_data_file::Func_name_from_file t_name_from_file() {
    vx_data_file::Func_name_from_file output = vx_data_file::vx_package->t_name_from_file;
    if (output == NULL) {
      output = new vx_data_file::Class_name_from_file();
      vx_core::vx_reserve_type(output);
      vx_data_file::vx_package->t_name_from_file = output;
    }
    return output;
  }

  // (func path<-file)
  vx_data_file::Func_path_from_file e_path_from_file() {
    vx_data_file::Func_path_from_file output = vx_data_file::vx_package->e_path_from_file;
    if (output == NULL) {
      output = new vx_data_file::Class_path_from_file();
      vx_core::vx_reserve_empty(output);
      vx_data_file::vx_package->e_path_from_file = output;
    }
    return output;
  }
  vx_data_file::Func_path_from_file t_path_from_file() {
    vx_data_file::Func_path_from_file output = vx_data_file::vx_package->t_path_from_file;
    if (output == NULL) {
      output = new vx_data_file::Class_path_from_file();
      vx_core::vx_reserve_type(output);
      vx_data_file::vx_package->t_path_from_file = output;
    }
    return output;
  }

  // (func pathcurrent<-os)
  vx_data_file::Func_pathcurrent_from_os e_pathcurrent_from_os() {
    vx_data_file::Func_pathcurrent_from_os output = vx_data_file::vx_package->e_pathcurrent_from_os;
    if (output == NULL) {
      output = new vx_data_file::Class_pathcurrent_from_os();
      vx_core::vx_reserve_empty(output);
      vx_data_file::vx_package->e_pathcurrent_from_os = output;
    }
    return output;
  }
  vx_data_file::Func_pathcurrent_from_os t_pathcurrent_from_os() {
    vx_data_file::Func_pathcurrent_from_os output = vx_data_file::vx_package->t_pathcurrent_from_os;
    if (output == NULL) {
      output = new vx_data_file::Class_pathcurrent_from_os();
      vx_core::vx_reserve_type(output);
      vx_data_file::vx_package->t_pathcurrent_from_os = output;
    }
    return output;
  }

  // (func pathfull<-file)
  vx_data_file::Func_pathfull_from_file e_pathfull_from_file() {
    vx_data_file::Func_pathfull_from_file output = vx_data_file::vx_package->e_pathfull_from_file;
    if (output == NULL) {
      output = new vx_data_file::Class_pathfull_from_file();
      vx_core::vx_reserve_empty(output);
      vx_data_file::vx_package->e_pathfull_from_file = output;
    }
    return output;
  }
  vx_data_file::Func_pathfull_from_file t_pathfull_from_file() {
    vx_data_file::Func_pathfull_from_file output = vx_data_file::vx_package->t_pathfull_from_file;
    if (output == NULL) {
      output = new vx_data_file::Class_pathfull_from_file();
      vx_core::vx_reserve_type(output);
      vx_data_file::vx_package->t_pathfull_from_file = output;
    }
    return output;
  }

  // (func string-read<-file)
  vx_data_file::Func_string_read_from_file e_string_read_from_file() {
    vx_data_file::Func_string_read_from_file output = vx_data_file::vx_package->e_string_read_from_file;
    if (output == NULL) {
      output = new vx_data_file::Class_string_read_from_file();
      vx_core::vx_reserve_empty(output);
      vx_data_file::vx_package->e_string_read_from_file = output;
    }
    return output;
  }
  vx_data_file::Func_string_read_from_file t_string_read_from_file() {
    vx_data_file::Func_string_read_from_file output = vx_data_file::vx_package->t_string_read_from_file;
    if (output == NULL) {
      output = new vx_data_file::Class_string_read_from_file();
      vx_core::vx_reserve_type(output);
      vx_data_file::vx_package->t_string_read_from_file = output;
    }
    return output;
  }

}