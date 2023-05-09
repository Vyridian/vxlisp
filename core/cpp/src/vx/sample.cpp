#include <any>
#include <map>
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
    vx_core::Type_int* vx_sample::Type_mytype::mynum() {
      vx_core::Type_int* output = this->vx_p_mynum;
      if (output == NULL) {
        output = vx_core::t_int;
      }
    }

    // mystr()
    vx_core::Type_string* vx_sample::Type_mytype::mystr() {
      vx_core::Type_string* output = this->vx_p_mystr;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_sample::Type_mytype::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
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
    std::map<std::string, vx_core::Type_any*> vx_sample::Type_mytype::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":mynum"] = this->mynum();
      output[":mystr"] = this->mystr();
      return output;
    }

    template<typename... Args> vx_sample::Type_mytype* vx_sample::Type_mytype::vx_new(Args*... args) {return vx_sample::e_mytype->vx_copy(args...);}
    template<typename... Args> vx_sample::Type_mytype* vx_sample::Type_mytype::vx_copy(Args*... args) {
      vx_sample::Type_mytype* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_mytype* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_mynum = val->mynum();
      output->vx_p_mystr = val->mystr();
      std::set<std::string> validkeys;
      validkeys.insert(":mynum");
      validkeys.insert(":mystr");
      std::string key = "";
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (key == "") {
          std::string testkey = "";
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string* valstr = vx_core::any_from_any(vx_core::t_string, valsub);
            testkey = valstr->vx_string();
          } else if (valsubtype == vx_core::t_nativestring) {
            testkey = vx_core::any_from_any("", valsub);
          }
          bool isvalidkey = vx_core::boolean_contains_from_set_val(validkeys, testkey);
          if (isvalidkey) {
            key = testkey;
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new mytype) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":mynum") {
            if (valsubtype == vx_core::t_int) {
              output->vx_p_mynum = vx_core::any_from_any(vx_core::t_int, valsub);
            } else if (valsubtype == vx_core::t_nativeint) {
              output->vx_p_mynum = vx_core::t_int->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new mytype :mynum " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":mystr") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_mystr = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_mystr = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new mytype :mystr " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new mytype) - Invalid Key: " + key);
            msgblock = msgblock->vx_copy(msg);
          }
          key = "";
        }
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_sample::Type_mytype* vx_sample::Type_mytype::vx_empty() {return vx_sample::e_mytype;}
    vx_sample::Type_mytype* vx_sample::Type_mytype::vx_type() {return vx_sample::t_mytype;}

    vx_core::Type_typedef* vx_sample::Type_mytype::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
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

  //}

  /**
   * Constant: myconst
   * My Constant
   * {int}
   */
  //class Const_myconst {

    // vx_constdef()
    vx_core::Type_constdef* vx_sample::Const_myconst::vx_constdef() {
      return vx_core::Type_constdef::vx_constdef_new(
        "vx/sample", // pkgname
        "myconst", // name
        vx_core::Type_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::t_typelist->vx_new(vx_core::t_number), // traits
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
    vx_sample::Const_myconst* vx_sample::Const_myconst::vx_const_new() {
      vx_sample::Const_myconst* output = new vx_sample::Const_myconst();
      return output;
    }

    int vx_core::Type_int::vx_int() {
      this->vx_p_int = 4;
      return this->vx_p_int;
    }

  //}

  extern vx_sample::Const_myconst* vx_sample::c_myconst = vx_sample::Const_myconst::vx_const_new();

  /**
   * @function main
   * @return {none}
   * (func main)
   */
  //class Func_main {

    template<typename... Args> vx_sample::Func_main* vx_sample::Func_main::vx_new(Args*... args) {
      vx_sample::Func_main* output;
      return output;
    }

    template<typename... Args> vx_sample::Func_main* vx_sample::Func_main::vx_copy(Args*... args) {
      vx_sample::Func_main* output;
      return output;
    }

    vx_core::Type_typedef* vx_sample::Func_main::vx_typedef() {return vx_sample::t_main->vx_typedef();}

    vx_core::Type_funcdef* vx_sample::Func_main::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/sample", // pkgname
        "main", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
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

    vx_sample::Func_main* vx_sample::Func_main::vx_empty() {return vx_sample::e_main;}
    vx_sample::Func_main* vx_sample::Func_main::vx_type() {return vx_sample::t_main;}

    vx_core::Type_any* vx_sample::Func_main::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_sample::f_main();
      return output;
    }

    void* vx_sample::Func_main::vx_main() {vx_sample::f_main();
    }

  //}

  vx_sample::Func_main* vx_sample::e_main = new vx_sample::Func_main();
  vx_sample::Func_main* vx_sample::t_main = new vx_sample::Func_main();

  void* vx_sample::f_main() {
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

    template<typename... Args> vx_sample::Func_myfunc* vx_sample::Func_myfunc::vx_new(Args*... args) {
      vx_sample::Func_myfunc* output;
      return output;
    }

    template<typename... Args> vx_sample::Func_myfunc* vx_sample::Func_myfunc::vx_copy(Args*... args) {
      vx_sample::Func_myfunc* output;
      return output;
    }

    vx_core::Type_typedef* vx_sample::Func_myfunc::vx_typedef() {return vx_sample::t_myfunc->vx_typedef();}

    vx_core::Type_funcdef* vx_sample::Func_myfunc::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/sample", // pkgname
        "myfunc", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::t_typelist->vx_new(vx_core::t_number), // traits
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

    vx_sample::Func_myfunc* vx_sample::Func_myfunc::vx_empty() {return vx_sample::e_myfunc;}
    vx_sample::Func_myfunc* vx_sample::Func_myfunc::vx_type() {return vx_sample::t_myfunc;}

    vx_core::Func_any_from_any* vx_sample::Func_myfunc::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_sample::Func_myfunc::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_core::Type_int* inputval = (vx_core::Type_int)value;
      vx_core::Type_any* outputval = vx_sample::f_myfunc(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_sample::Func_myfunc::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Type_int* myarg = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_sample::f_myfunc(myarg);
      return output;
    }

    vx_core::Type_int* vx_sample::Func_myfunc::vx_myfunc(vx_core::Type_int* myarg) {
      return vx_sample::f_myfunc(myarg);
    }

  //}

  vx_sample::Func_myfunc* vx_sample::e_myfunc = new vx_sample::Func_myfunc();
  vx_sample::Func_myfunc* vx_sample::t_myfunc = new vx_sample::Func_myfunc();

  vx_core::Type_int* vx_sample::f_myfunc(vx_core::Type_int* myarg) {
    vx_core::Type_int* output = vx_core::e_int;
    output = vx_core::f_plus(
      vx_sample::c_myconst,
      myarg
    );
    return output;
  }


//}
