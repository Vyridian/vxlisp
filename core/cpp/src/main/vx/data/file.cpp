#include <exception>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <map>
#include <string>
#include "../../vx/core.hpp"
#include "../../vx/data/textblock.hpp"
#include "file.hpp"

namespace vx_data_file {
// :body

  vx_core::Type_boolean vx_boolean_exists_from_file(vx_data_file::Type_file file) {
    vx_core::Type_boolean output = vx_core::c_false;
		vx_core::Type_string path = vx_data_file::f_pathfull_from_file(file);
    std::string spath = path->vx_string();
    vx_core::vx_release(path);
		std::ifstream f(spath);
    if (f.good()) {
      output = vx_core::c_true;
		}
    return output;
	}

  vx_core::Type_boolean vx_boolean_write_from_file_string(vx_data_file::Type_file file, vx_core::Type_string text) {
    vx_core::Type_boolean output = vx_core::c_false;
		vx_core::Type_string path = vx_data_file::f_pathfull_from_file(file);
    std::string spath = path->vx_string();
    std::string stext = text->vx_string();
    vx_core::vx_release({text, path});
    output = vx_data_file::vx_boolean_write_from_path_text(spath, stext);
    return output;
	}

  vx_core::Type_boolean vx_boolean_write_from_path_text(std::string path, std::string text) {
    vx_core::Type_boolean output = vx_core::c_false;
    std::ofstream filestream(path, std::ios_base::binary | std::ios_base::out);
    if (filestream.is_open()) {
      filestream << text;
      filestream.close();
      output = vx_core::c_true;
    } else {
      vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("File not found:" + path);
      output = vx_core::vx_copy(vx_core::c_false, {msg});
    }
    return output;
  }

  vx_core::Type_string vx_string_read_from_file(vx_data_file::Type_file file) {
    vx_core::Type_string output = vx_core::e_string;
		vx_core::Type_string path = vx_data_file::f_pathfull_from_file(file);
    std::string spath = path->vx_string();
    vx_core::vx_release(path);
		output = vx_data_file::vx_string_read_from_path(spath);
		return output;
	}

  vx_core::Type_string vx_string_read_from_path(std::string path) {
    vx_core::Type_string output = vx_core::e_string;
    std::ifstream filestream(path);
    if (filestream.is_open()) {
      bool isfirst = true;
      std::string text;
      std::string line;
      while (std::getline(filestream, line)) {
        if (isfirst) {
          text = line;
          isfirst = false;
        } else {
          text += "\n" + line;
        }
      }
      filestream.close();
      output = vx_core::vx_new_string(text);
    } else {
      vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("File not found:" + path);
      output = vx_core::vx_new(vx_core::t_string, {msg});
    }
    return output;
  }

  vx_core::Type_string vx_pathcurrent_from_os() {
    vx_core::Type_string output = vx_core::e_string;
		std::string path = std::filesystem::current_path().string();
		output = vx_core::vx_new_string(path);
    return output;
	}


  // (type file)
  // class Class_file {
    Abstract_file::~Abstract_file() {}

    Class_file::Class_file() : Abstract_file::Abstract_file() {
      vx_core::refcount += 1;
    }

    Class_file::~Class_file() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_name,
        this->vx_p_format,
        this->vx_p_path,
        this->vx_p_permission,
        this->vx_p_text
      });
    }

    // name()
    vx_core::Type_string Class_file::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // format()
    vx_data_file::Type_fileformat Class_file::format() const {
      vx_data_file::Type_fileformat output = this->vx_p_format;
      if (!output) {
        output = vx_data_file::e_fileformat;
      }
      return output;
    }

    // path()
    vx_core::Type_string Class_file::path() const {
      vx_core::Type_string output = this->vx_p_path;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // permission()
    vx_core::Type_permission Class_file::permission() const {
      vx_core::Type_permission output = this->vx_p_permission;
      if (!output) {
        output = vx_core::e_permission;
      }
      return output;
    }

    // text()
    vx_core::Type_string Class_file::text() const {
      vx_core::Type_string output = this->vx_p_text;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_file::vx_get_any(vx_core::Type_string key) const {
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
      vx_core::vx_release_except(key, output);
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
      return this->vx_copy(vx_data_file::e_file, vals);
    }

    vx_core::Type_any Class_file::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_file::Type_file output = vx_data_file::e_file;
      vx_data_file::Type_file val = vx_core::vx_any_from_any(vx_data_file::t_file, copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_name = val->name();
      vx_data_file::Type_fileformat vx_p_format = val->format();
      vx_core::Type_string vx_p_path = val->path();
      vx_core::Type_permission vx_p_permission = val->permission();
      vx_core::Type_string vx_p_text = val->text();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string, valsub);
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new file) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string) {
              vx_p_name = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new file :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":format") {
            if (valsubtype == vx_data_file::t_fileformat) {
              vx_p_format = vx_core::vx_any_from_any(vx_data_file::t_fileformat, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new file :format " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":path") {
            if (valsubtype == vx_core::t_string) {
              vx_p_path = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new file :path " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":permission") {
            if (valsubtype == vx_core::t_permission) {
              vx_p_permission = vx_core::vx_any_from_any(vx_core::t_permission, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new file :permission " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":text") {
            if (valsubtype == vx_core::t_string) {
              vx_p_text = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new file :text " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_errortext("(new file) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_data_file::Class_file();
      if (output->vx_p_name != vx_p_name) {
        if (output->vx_p_name) {
          vx_core::vx_release_one(output->vx_p_name);
        }
        output->vx_p_name = vx_p_name;
        vx_core::vx_reserve(vx_p_name);
      }
      if (output->vx_p_format != vx_p_format) {
        if (output->vx_p_format) {
          vx_core::vx_release_one(output->vx_p_format);
        }
        output->vx_p_format = vx_p_format;
        vx_core::vx_reserve(vx_p_format);
      }
      if (output->vx_p_path != vx_p_path) {
        if (output->vx_p_path) {
          vx_core::vx_release_one(output->vx_p_path);
        }
        output->vx_p_path = vx_p_path;
        vx_core::vx_reserve(vx_p_path);
      }
      if (output->vx_p_permission != vx_p_permission) {
        if (output->vx_p_permission) {
          vx_core::vx_release_one(output->vx_p_permission);
        }
        output->vx_p_permission = vx_p_permission;
        vx_core::vx_reserve(vx_p_permission);
      }
      if (output->vx_p_text != vx_p_text) {
        if (output->vx_p_text) {
          vx_core::vx_release_one(output->vx_p_text);
        }
        output->vx_p_text = vx_p_text;
        vx_core::vx_reserve(vx_p_text);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_file::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_file::Class_file::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_file::vx_empty() const {return vx_data_file::e_file;}
    vx_core::Type_any Class_file::vx_type() const {return vx_data_file::t_file;}

    vx_core::Type_typedef Class_file::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
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
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "name", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "format", // name
            vx_data_file::t_fileformat // type
          ),
          vx_core::vx_new_arg(
            "path", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "permission", // name
            vx_core::t_permission // type
          ),
          vx_core::vx_new_arg(
            "text", // name
            vx_core::t_string // type
          )
        }) // properties
      );
      return output;
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_fileformat::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_file::e_fileformat, vals);
    }

    vx_core::Type_any Class_fileformat::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_file::Type_fileformat output = vx_data_file::e_fileformat;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_fileformat::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_file::Class_fileformat::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_fileformat::vx_empty() const {return vx_data_file::e_fileformat;}
    vx_core::Type_any Class_fileformat::vx_type() const {return vx_data_file::t_fileformat;}

    vx_core::Type_typedef Class_fileformat::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
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
      return output;
    }

  //}

  // (func boolean-exists<-file)
  vx_core::Type_boolean f_boolean_exists_from_file(vx_data_file::Type_file file) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve(file);
    output = vx_data_file::vx_boolean_exists_from_file(file);
    vx_core::vx_release_one_except(file, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_boolean_exists_from_file::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_boolean_exists_from_file output = vx_data_file::e_boolean_exists_from_file;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_boolean_exists_from_file::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_boolean_exists_from_file output = vx_data_file::e_boolean_exists_from_file;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_boolean_exists_from_file::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/file", // pkgname
        "boolean-exists<-file", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_boolean_exists_from_file::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "boolean-exists<-file", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_boolean_exists_from_file::vx_empty() const {return vx_data_file::e_boolean_exists_from_file;}
    vx_core::Type_any Class_boolean_exists_from_file::vx_type() const {return vx_data_file::t_boolean_exists_from_file;}
    vx_core::Type_msgblock Class_boolean_exists_from_file::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_exists_from_file::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_boolean_exists_from_file::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_boolean_exists_from_file::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file inputval = vx_core::vx_any_from_any(vx_data_file::t_file, val);
      output = vx_data_file::f_boolean_exists_from_file(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_boolean_exists_from_file::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file file = vx_core::vx_any_from_any(vx_data_file::t_file, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_file::f_boolean_exists_from_file(file);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func boolean-write<-file-any)
  vx_core::Type_boolean f_boolean_write_from_file_any(vx_data_file::Type_file file, vx_core::Type_any val, vx_core::Type_context context) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve({file, val});
    output = vx_data_file::f_boolean_write_from_file_string(
      file,
      vx_core::f_string_from_any(val),
      context
    );
    vx_core::vx_release_one_except({file, val}, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_boolean_write_from_file_any::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_boolean_write_from_file_any output = vx_data_file::e_boolean_write_from_file_any;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_boolean_write_from_file_any::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_boolean_write_from_file_any output = vx_data_file::e_boolean_write_from_file_any;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_boolean_write_from_file_any::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/file", // pkgname
        "boolean-write<-file-any", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_boolean_write_from_file_any::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "boolean-write<-file-any", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_boolean_write_from_file_any::vx_empty() const {return vx_data_file::e_boolean_write_from_file_any;}
    vx_core::Type_any Class_boolean_write_from_file_any::vx_type() const {return vx_data_file::t_boolean_write_from_file_any;}
    vx_core::Type_msgblock Class_boolean_write_from_file_any::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_write_from_file_any::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_boolean_write_from_file_any::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file file = vx_core::vx_any_from_any(vx_data_file::t_file, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any val = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_data_file::f_boolean_write_from_file_any(file, val, context);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func boolean-write<-file-string)
  vx_core::Type_boolean f_boolean_write_from_file_string(vx_data_file::Type_file file, vx_core::Type_string text, vx_core::Type_context context) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve({file, text});
    try {
      output = vx_data_file::vx_boolean_write_from_file_string(file, text);
    } catch (std::exception err) {
      vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_exception("boolean-write<-file-string", err);
      output = vx_core::vx_copy(vx_core::t_boolean, {msg});
    }
    vx_core::vx_release_one_except({file, text}, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_boolean_write_from_file_string::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_boolean_write_from_file_string output = vx_data_file::e_boolean_write_from_file_string;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_boolean_write_from_file_string::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_boolean_write_from_file_string output = vx_data_file::e_boolean_write_from_file_string;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_boolean_write_from_file_string::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/file", // pkgname
        "boolean-write<-file-string", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_boolean_write_from_file_string::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "boolean-write<-file-string", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_boolean_write_from_file_string::vx_empty() const {return vx_data_file::e_boolean_write_from_file_string;}
    vx_core::Type_any Class_boolean_write_from_file_string::vx_type() const {return vx_data_file::t_boolean_write_from_file_string;}
    vx_core::Type_msgblock Class_boolean_write_from_file_string::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_write_from_file_string::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_boolean_write_from_file_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file file = vx_core::vx_any_from_any(vx_data_file::t_file, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_data_file::f_boolean_write_from_file_string(file, text, context);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func file-read<-file)
  vx_data_file::Type_file f_file_read_from_file(vx_data_file::Type_file file, vx_core::Type_context context) {
    vx_data_file::Type_file output = vx_data_file::e_file;
    vx_core::vx_reserve(file);
    output = vx_core::f_copy(
      file,
      vx_core::vx_new(vx_core::t_anylist, {
        vx_core::vx_new_string(":text"),
        vx_data_file::f_string_read_from_file(file, context)
      })
    );
    vx_core::vx_release_one_except(file, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_file_read_from_file::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_file_read_from_file output = vx_data_file::e_file_read_from_file;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_file_read_from_file::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_file_read_from_file output = vx_data_file::e_file_read_from_file;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_file_read_from_file::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/file", // pkgname
        "file-read<-file", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_file_read_from_file::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "file-read<-file", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_file_read_from_file::vx_empty() const {return vx_data_file::e_file_read_from_file;}
    vx_core::Type_any Class_file_read_from_file::vx_type() const {return vx_data_file::t_file_read_from_file;}
    vx_core::Type_msgblock Class_file_read_from_file::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_file_read_from_file::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_file_read_from_file::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_file_read_from_file::vx_any_from_any_context(vx_core::Type_any val, vx_core::Type_context context) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file inputval = vx_core::vx_any_from_any(vx_data_file::t_file, val);
      output = vx_data_file::f_file_read_from_file(inputval, context);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_file_read_from_file::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file file = vx_core::vx_any_from_any(vx_data_file::t_file, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_file::f_file_read_from_file(file, context);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func name<-file)
  vx_core::Type_string f_name_from_file(vx_data_file::Type_file file) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve(file);
    output = file->name();
    vx_core::vx_release_one_except(file, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_name_from_file::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_name_from_file output = vx_data_file::e_name_from_file;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_name_from_file::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_name_from_file output = vx_data_file::e_name_from_file;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_name_from_file::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/file", // pkgname
        "name<-file", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_name_from_file::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "name<-file", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_name_from_file::vx_empty() const {return vx_data_file::e_name_from_file;}
    vx_core::Type_any Class_name_from_file::vx_type() const {return vx_data_file::t_name_from_file;}
    vx_core::Type_msgblock Class_name_from_file::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_name_from_file::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_name_from_file::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_name_from_file::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file inputval = vx_core::vx_any_from_any(vx_data_file::t_file, val);
      output = vx_data_file::f_name_from_file(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_name_from_file::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file file = vx_core::vx_any_from_any(vx_data_file::t_file, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_file::f_name_from_file(file);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func path<-file)
  vx_core::Type_string f_path_from_file(vx_data_file::Type_file file) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve(file);
    output = file->path();
    vx_core::vx_release_one_except(file, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_path_from_file::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_path_from_file output = vx_data_file::e_path_from_file;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_path_from_file::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_path_from_file output = vx_data_file::e_path_from_file;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_path_from_file::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/file", // pkgname
        "path<-file", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_path_from_file::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "path<-file", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_path_from_file::vx_empty() const {return vx_data_file::e_path_from_file;}
    vx_core::Type_any Class_path_from_file::vx_type() const {return vx_data_file::t_path_from_file;}
    vx_core::Type_msgblock Class_path_from_file::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_path_from_file::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_path_from_file::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_path_from_file::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file inputval = vx_core::vx_any_from_any(vx_data_file::t_file, val);
      output = vx_data_file::f_path_from_file(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_path_from_file::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file file = vx_core::vx_any_from_any(vx_data_file::t_file, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_file::f_path_from_file(file);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func pathcurrent<-os)
  vx_core::Type_string f_pathcurrent_from_os() {
    vx_core::Type_string output = vx_core::e_string;
    output = vx_data_file::vx_pathcurrent_from_os();
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_pathcurrent_from_os::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_pathcurrent_from_os output = vx_data_file::e_pathcurrent_from_os;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_pathcurrent_from_os::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_pathcurrent_from_os output = vx_data_file::e_pathcurrent_from_os;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_pathcurrent_from_os::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/file", // pkgname
        "pathcurrent<-os", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_pathcurrent_from_os::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "pathcurrent<-os", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_pathcurrent_from_os::vx_empty() const {return vx_data_file::e_pathcurrent_from_os;}
    vx_core::Type_any Class_pathcurrent_from_os::vx_type() const {return vx_data_file::t_pathcurrent_from_os;}
    vx_core::Type_msgblock Class_pathcurrent_from_os::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_pathcurrent_from_os::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_pathcurrent_from_os::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      output = vx_data_file::f_pathcurrent_from_os();
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func pathfull<-file)
  vx_core::Type_string f_pathfull_from_file(vx_data_file::Type_file file) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve(file);
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({file}, [file]() {
        vx_core::Type_string path = vx_data_file::f_path_from_file(file);
        vx_core::vx_ref_plus(path);
        vx_core::Type_string name = vx_data_file::f_name_from_file(file);
        vx_core::vx_ref_plus(name);
        vx_core::Type_string output_1 = vx_core::f_new(
          vx_core::t_string,
          vx_core::vx_new(vx_core::t_anylist, {
            path,
            vx_core::vx_new_string("/"),
            name
          })
        );
        vx_core::vx_release_one_except({path, name}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(file, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_pathfull_from_file::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_pathfull_from_file output = vx_data_file::e_pathfull_from_file;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_pathfull_from_file::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_pathfull_from_file output = vx_data_file::e_pathfull_from_file;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_pathfull_from_file::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/file", // pkgname
        "pathfull<-file", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_pathfull_from_file::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "pathfull<-file", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_pathfull_from_file::vx_empty() const {return vx_data_file::e_pathfull_from_file;}
    vx_core::Type_any Class_pathfull_from_file::vx_type() const {return vx_data_file::t_pathfull_from_file;}
    vx_core::Type_msgblock Class_pathfull_from_file::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_pathfull_from_file::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_pathfull_from_file::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_pathfull_from_file::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file inputval = vx_core::vx_any_from_any(vx_data_file::t_file, val);
      output = vx_data_file::f_pathfull_from_file(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_pathfull_from_file::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file file = vx_core::vx_any_from_any(vx_data_file::t_file, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_file::f_pathfull_from_file(file);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string-read<-file)
  vx_core::Type_string f_string_read_from_file(vx_data_file::Type_file file, vx_core::Type_context context) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve(file);
    try {
      output = vx_data_file::vx_string_read_from_file(file);
    } catch (std::exception err) {
      vx_core::Type_msg msg = vx_core::t_msg->vx_msg_from_exception("string-read<-file", err);
      output = vx_core::vx_copy(vx_core::t_string, {msg});
    }
    vx_core::vx_release_one_except(file, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_read_from_file::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_string_read_from_file output = vx_data_file::e_string_read_from_file;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_read_from_file::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_file::Func_string_read_from_file output = vx_data_file::e_string_read_from_file;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_read_from_file::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/file", // pkgname
        "string-read<-file", // name
        ":func", // extends
        vx_core::e_typelist, // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_funcdef Class_string_read_from_file::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/file", // pkgname
        "string-read<-file", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_read_from_file::vx_empty() const {return vx_data_file::e_string_read_from_file;}
    vx_core::Type_any Class_string_read_from_file::vx_type() const {return vx_data_file::t_string_read_from_file;}
    vx_core::Type_msgblock Class_string_read_from_file::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_read_from_file::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_string_read_from_file::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_string_read_from_file::vx_any_from_any_context(vx_core::Type_any val, vx_core::Type_context context) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file inputval = vx_core::vx_any_from_any(vx_data_file::t_file, val);
      output = vx_data_file::f_string_read_from_file(inputval, context);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_string_read_from_file::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file file = vx_core::vx_any_from_any(vx_data_file::t_file, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_file::f_string_read_from_file(file, context);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_data_file::Type_file e_file = NULL;
  vx_data_file::Type_file t_file = NULL;
  vx_data_file::Type_fileformat e_fileformat = NULL;
  vx_data_file::Type_fileformat t_fileformat = NULL;
  vx_data_file::Func_boolean_exists_from_file e_boolean_exists_from_file = NULL;
  vx_data_file::Func_boolean_exists_from_file t_boolean_exists_from_file = NULL;
  vx_data_file::Func_boolean_write_from_file_any e_boolean_write_from_file_any = NULL;
  vx_data_file::Func_boolean_write_from_file_any t_boolean_write_from_file_any = NULL;
  vx_data_file::Func_boolean_write_from_file_string e_boolean_write_from_file_string = NULL;
  vx_data_file::Func_boolean_write_from_file_string t_boolean_write_from_file_string = NULL;
  vx_data_file::Func_file_read_from_file e_file_read_from_file = NULL;
  vx_data_file::Func_file_read_from_file t_file_read_from_file = NULL;
  vx_data_file::Func_name_from_file e_name_from_file = NULL;
  vx_data_file::Func_name_from_file t_name_from_file = NULL;
  vx_data_file::Func_path_from_file e_path_from_file = NULL;
  vx_data_file::Func_path_from_file t_path_from_file = NULL;
  vx_data_file::Func_pathcurrent_from_os e_pathcurrent_from_os = NULL;
  vx_data_file::Func_pathcurrent_from_os t_pathcurrent_from_os = NULL;
  vx_data_file::Func_pathfull_from_file e_pathfull_from_file = NULL;
  vx_data_file::Func_pathfull_from_file t_pathfull_from_file = NULL;
  vx_data_file::Func_string_read_from_file e_string_read_from_file = NULL;
  vx_data_file::Func_string_read_from_file t_string_read_from_file = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_data_file::e_file = new Class_file();
      vx_core::vx_reserve_empty(vx_data_file::e_file);
      vx_data_file::t_file = new Class_file();
      vx_core::vx_reserve_type(vx_data_file::t_file);
      vx_data_file::e_fileformat = new Class_fileformat();
      vx_core::vx_reserve_empty(vx_data_file::e_fileformat);
      vx_data_file::t_fileformat = new Class_fileformat();
      vx_core::vx_reserve_type(vx_data_file::t_fileformat);
      vx_data_file::e_boolean_exists_from_file = new vx_data_file::Class_boolean_exists_from_file();
      vx_core::vx_reserve_empty(vx_data_file::e_boolean_exists_from_file);
      vx_data_file::t_boolean_exists_from_file = new vx_data_file::Class_boolean_exists_from_file();
      vx_core::vx_reserve_type(vx_data_file::t_boolean_exists_from_file);
      vx_data_file::e_boolean_write_from_file_any = new vx_data_file::Class_boolean_write_from_file_any();
      vx_core::vx_reserve_empty(vx_data_file::e_boolean_write_from_file_any);
      vx_data_file::t_boolean_write_from_file_any = new vx_data_file::Class_boolean_write_from_file_any();
      vx_core::vx_reserve_type(vx_data_file::t_boolean_write_from_file_any);
      vx_data_file::e_boolean_write_from_file_string = new vx_data_file::Class_boolean_write_from_file_string();
      vx_core::vx_reserve_empty(vx_data_file::e_boolean_write_from_file_string);
      vx_data_file::t_boolean_write_from_file_string = new vx_data_file::Class_boolean_write_from_file_string();
      vx_core::vx_reserve_type(vx_data_file::t_boolean_write_from_file_string);
      vx_data_file::e_file_read_from_file = new vx_data_file::Class_file_read_from_file();
      vx_core::vx_reserve_empty(vx_data_file::e_file_read_from_file);
      vx_data_file::t_file_read_from_file = new vx_data_file::Class_file_read_from_file();
      vx_core::vx_reserve_type(vx_data_file::t_file_read_from_file);
      vx_data_file::e_name_from_file = new vx_data_file::Class_name_from_file();
      vx_core::vx_reserve_empty(vx_data_file::e_name_from_file);
      vx_data_file::t_name_from_file = new vx_data_file::Class_name_from_file();
      vx_core::vx_reserve_type(vx_data_file::t_name_from_file);
      vx_data_file::e_path_from_file = new vx_data_file::Class_path_from_file();
      vx_core::vx_reserve_empty(vx_data_file::e_path_from_file);
      vx_data_file::t_path_from_file = new vx_data_file::Class_path_from_file();
      vx_core::vx_reserve_type(vx_data_file::t_path_from_file);
      vx_data_file::e_pathcurrent_from_os = new vx_data_file::Class_pathcurrent_from_os();
      vx_core::vx_reserve_empty(vx_data_file::e_pathcurrent_from_os);
      vx_data_file::t_pathcurrent_from_os = new vx_data_file::Class_pathcurrent_from_os();
      vx_core::vx_reserve_type(vx_data_file::t_pathcurrent_from_os);
      vx_data_file::e_pathfull_from_file = new vx_data_file::Class_pathfull_from_file();
      vx_core::vx_reserve_empty(vx_data_file::e_pathfull_from_file);
      vx_data_file::t_pathfull_from_file = new vx_data_file::Class_pathfull_from_file();
      vx_core::vx_reserve_type(vx_data_file::t_pathfull_from_file);
      vx_data_file::e_string_read_from_file = new vx_data_file::Class_string_read_from_file();
      vx_core::vx_reserve_empty(vx_data_file::e_string_read_from_file);
      vx_data_file::t_string_read_from_file = new vx_data_file::Class_string_read_from_file();
      vx_core::vx_reserve_type(vx_data_file::t_string_read_from_file);
    }
    vx_core::vx_Type_mapany vx_Class_package::maptype() {
      vx_core::vx_Type_mapany output;
      output["anylist"] = vx_core::t_anylist;
      return output;
    }
    vx_core::vx_Type_mapany vx_Class_package::mapconst() {
      vx_core::vx_Type_mapany output;
      return output;
    }
    std::map<std::string, vx_core::Type_func> vx_Class_package::mapfunc() {
      vx_core::vx_Type_mapfunc output;
      return output;
    }
  // }

}
