#include <memory>
#include <set>
#include <string>
#include "../vx/core.hpp"
#include "vx/sample.hpp"

//namespace vx_sample {

  /**
   * type: mytype
   * (type mytype)
   */
  //class Type_mytype {
    // mynum()
    vx_core::Type_int vx_sample::Class_mytype::mynum() {
      vx_core::Type_int output = this->vx_p_mynum;
      if (output == NULL) {
        output = vx_core::t_int;
      }
      return output;
    }

    // mystr()
    vx_core::Type_string vx_sample::Class_mytype::mystr() {
      vx_core::Type_string output = this->vx_p_mystr;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any vx_sample::Class_mytype::vx_get_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":mynum") {
        output = this->mynum();
      } else if (skey == ":mystr") {
        output = this->mystr();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_sample::Class_mytype::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":mynum"] = this->mynum();
      output[":mystr"] = this->mystr();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_sample::Class_mytype::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_sample::e_mytype->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_sample::Class_mytype::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_sample::Type_mytype output;
      vx_sample::Class_mytype* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val->vx_msgblock(), vals);
      output->vx_p_mynum = val->mynum();
      output->vx_p_mystr = val->mystr();
      std::set<std::string> validkeys;
      validkeys.insert(":mynum");
      validkeys.insert(":mystr");
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new mytype) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":mynum") {
            if (valsubtype == vx_core::t_int) {
              output->vx_p_mynum = vx_core::any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new mytype :mynum " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":mystr") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_mystr = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new mytype :mystr " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new mytype) - Invalid Key: " + key);
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

    template <class T> std::shared_ptr<T> vx_sample::Class_mytype::vx_empty(std::shared_ptr<T> val) {return vx_sample::e_mytype;}
    template <class T> std::shared_ptr<T> vx_sample::Class_mytype::vx_type(std::shared_ptr<T> val) {return vx_sample::t_mytype;}

    vx_core::Type_typedef vx_sample::Class_mytype::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/sample", // pkgname
        "mytype", // name
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

    vx_sample::Type_mytype vx_sample::e_mytype = std::make_shared<vx_sample::Class_mytype>();
    vx_sample::Type_mytype vx_sample::t_mytype = std::make_shared<vx_sample::Class_mytype>();
  //}

  /**
   * Constant: myconst
   * My Constant
   * {int}
   */
  //class Class_myconst {

    // vx_constdef()
    vx_core::Type_constdef vx_sample::Class_myconst::vx_constdef() {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/sample", // pkgname
        "myconst", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // traits
          vx_core::e_typelist, // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        )
      );
    }

    // vx_const_new()
    vx_sample::Const_myconst vx_sample::Class_myconst::vx_const_new() {
      vx_sample::Const_myconst output = std::shared_ptr<vx_sample::Class_myconst>();
      return output;
    }

    int vx_sample::Class_myconst::vx_int() {
      this->vx_p_int = 4;
      return this->vx_p_int;
    }

  //}

  vx_sample::Const_myconst vx_sample::c_myconst = vx_sample::Class_myconst::vx_const_new();

  /**
   * @function main
   * @return {none}
   * (func main)
   */
  //class Func_main {

    template <class T> std::shared_ptr<T> vx_sample::Class_main::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_sample::Func_main output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_sample::Class_main::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_sample::Func_main output;
      return output;
    }

    vx_core::Type_typedef vx_sample::Class_main::vx_typedef() {return vx_sample::t_main->vx_typedef();}

    vx_core::Type_funcdef vx_sample::Class_main::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/sample", // pkgname
        "main", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "none", // name
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

    template <class T> std::shared_ptr<T> vx_sample::Class_main::vx_empty(std::shared_ptr<T> val) {return vx_sample::e_main;}
    template <class T> std::shared_ptr<T> vx_sample::Class_main::vx_type(std::shared_ptr<T> val) {return vx_sample::t_main;}

    vx_core::Type_any vx_sample::Class_main::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_sample::f_main();
      return output;
    }

    void vx_sample::Class_main::vx_f_main() {vx_sample::f_main();
    }

  //}

  vx_sample::Func_main vx_sample::e_main = std::make_shared<vx_sample::Class_main>();
  vx_sample::Func_main vx_sample::t_main = std::make_shared<vx_sample::Class_main>();

  void vx_sample::f_main() {
    vx_sample::f_myfunc(vx_core::t_int->vx_new_from_int(2));
  }

  /**
   * @function myfunc
   * My Function
   * @param  {int} myarg My Arg
   * @return {int}
   * (func myfunc)
   */
  //class Func_myfunc {

    template <class T> std::shared_ptr<T> vx_sample::Class_myfunc::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_sample::Func_myfunc output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_sample::Class_myfunc::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_sample::Func_myfunc output;
      return output;
    }

    vx_core::Type_typedef vx_sample::Class_myfunc::vx_typedef() {return vx_sample::t_myfunc->vx_typedef();}

    vx_core::Type_funcdef vx_sample::Class_myfunc::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/sample", // pkgname
        "myfunc", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_number}), // traits
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

    template <class T> std::shared_ptr<T> vx_sample::Class_myfunc::vx_empty(std::shared_ptr<T> val) {return vx_sample::e_myfunc;}
    template <class T> std::shared_ptr<T> vx_sample::Class_myfunc::vx_type(std::shared_ptr<T> val) {return vx_sample::t_myfunc;}

    vx_core::Func_any_from_any vx_sample::Class_myfunc::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_sample::Class_myfunc::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_core::Type_int inputval = (vx_core::Type_int)value;
      vx_core::Type_any outputval = vx_sample::f_myfunc(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_sample::Class_myfunc::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_int myarg = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_sample::f_myfunc(myarg);
      return output;
    }

    vx_core::Type_int vx_sample::Class_myfunc::vx_f_myfunc(vx_core::Type_int myarg) {
      return vx_sample::f_myfunc(myarg);
    }

  //}

  vx_sample::Func_myfunc vx_sample::e_myfunc = std::make_shared<vx_sample::Class_myfunc>();
  vx_sample::Func_myfunc vx_sample::t_myfunc = std::make_shared<vx_sample::Class_myfunc>();

  vx_core::Type_int vx_sample::f_myfunc(vx_core::Type_int myarg) {
    vx_core::Type_int output = vx_core::e_int;
    output = vx_core::f_plus(
      vx_sample::c_myconst,
      myarg
    );
    return output;
  }


//}
