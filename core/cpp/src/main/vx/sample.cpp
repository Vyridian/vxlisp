#include <string>
#include "../vx/core.hpp"
#include "sample.hpp"

namespace vx_sample {


  // (type mytype)
  // class Class_mytype {
    Abstract_mytype::~Abstract_mytype() {}

    Class_mytype::Class_mytype() : Abstract_mytype::Abstract_mytype() {
      vx_core::refcount += 1;
    }
    Class_mytype::~Class_mytype() {
      vx_core::refcount -= 1;
    }
    // mynum()
    vx_core::Type_int Class_mytype::mynum() const {
      vx_core::Type_int output = this->vx_p_mynum;
      if (output == NULL) {
        output = vx_core::e_int();
      }
      return output;
    }

    // mystr()
    vx_core::Type_string Class_mytype::mystr() const {
      vx_core::Type_string output = this->vx_p_mystr;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_mytype::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
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
    vx_core::vx_Type_mapany Class_mytype::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":mynum"] = this->mynum();
      output[":mystr"] = this->mystr();
      return output;
    }

    vx_core::Type_any Class_mytype::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_sample::e_mytype(), vals);
    }
    vx_core::Type_any Class_mytype::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_sample::Type_mytype output = vx_sample::e_mytype();
      vx_sample::Type_mytype val = vx_core::vx_any_from_any(vx_sample::t_mytype(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_int vx_p_mynum = val->mynum();
      vx_core::Type_string vx_p_mystr = val->mystr();
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
          } else if (testkey == ":mynum") {
            key = testkey;
          } else if (testkey == ":mystr") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new mytype) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":mynum") {
            if (valsubtype == vx_core::t_int()) {
              vx_p_mynum = vx_core::vx_any_from_any(vx_core::t_int(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new mytype :mynum " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":mystr") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_mystr = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new mytype :mystr " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new mytype) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_sample::Class_mytype();
      output->vx_p_mynum = vx_p_mynum;
      output->vx_p_mystr = vx_p_mystr;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_mytype::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_sample::Class_mytype::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_mytype::vx_empty() const {return vx_sample::e_mytype();}
    vx_core::Type_any Class_mytype::vx_type() const {return vx_sample::t_mytype();}

    vx_core::Type_typedef Class_mytype::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/sample", // pkgname
        "mytype", // name
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

  // (const myconst)
  // class Class_myconst {

    // vx_constdef()
    vx_core::Type_constdef vx_sample::Class_myconst::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/sample", // pkgname
        "myconst", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_number()}), // traits
          vx_core::e_typelist(), // allowtypes
          vx_core::e_typelist(), // disallowtypes
          vx_core::e_funclist(), // allowfuncs
          vx_core::e_funclist(), // disallowfuncs
          vx_core::e_anylist(), // allowvalues
          vx_core::e_anylist(), // disallowvalues
          vx_core::e_argmap() // properties
        )
      );
    }

    long vx_sample::Class_myconst::vx_int() {
      this->vx_p_int = 4;
      return this->vx_p_int;
    }

  //}

  // (func main)
  void f_main() {
    vx_sample::f_myfunc(vx_core::vx_new_int(2));
  }

  // (func main)
  // class Class_main {
    Abstract_main::~Abstract_main() {}

    Class_main::Class_main() : Abstract_main::Abstract_main() {
      vx_core::refcount += 1;
    }
    Class_main::~Class_main() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_main::vx_new(vx_core::vx_Type_listany vals) const {
      vx_sample::Func_main output = vx_sample::e_main();
      return output;
    }

    vx_core::Type_any Class_main::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_sample::Func_main output = vx_sample::e_main();
      return output;
    }

    vx_core::Type_typedef Class_main::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "none", // name
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

    vx_core::Type_funcdef Class_main::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/sample", // pkgname
        "main", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_main::vx_empty() const {return vx_sample::e_main();}
    vx_core::Type_any Class_main::vx_type() const {return vx_sample::t_main();}
    vx_core::Type_msgblock Class_main::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_main::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_main::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_sample::f_main();
      return output;
    }

  //}

  // (func myfunc)
  vx_core::Type_int f_myfunc(vx_core::Type_int myarg) {
    vx_core::Type_int output = vx_core::e_int();
    output = vx_core::f_plus(
      vx_sample::c_myconst(),
      myarg
    );
    return output;
  }

  // (func myfunc)
  // class Class_myfunc {
    Abstract_myfunc::~Abstract_myfunc() {}

    Class_myfunc::Class_myfunc() : Abstract_myfunc::Abstract_myfunc() {
      vx_core::refcount += 1;
    }
    Class_myfunc::~Class_myfunc() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_myfunc::vx_new(vx_core::vx_Type_listany vals) const {
      vx_sample::Func_myfunc output = vx_sample::e_myfunc();
      return output;
    }

    vx_core::Type_any Class_myfunc::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_sample::Func_myfunc output = vx_sample::e_myfunc();
      return output;
    }

    vx_core::Type_typedef Class_myfunc::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "int", // name
        "", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_number()}), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_myfunc::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/sample", // pkgname
        "myfunc", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_myfunc::vx_empty() const {return vx_sample::e_myfunc();}
    vx_core::Type_any Class_myfunc::vx_type() const {return vx_sample::t_myfunc();}
    vx_core::Type_msgblock Class_myfunc::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_myfunc::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_myfunc::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_myfunc::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_int inputval = vx_core::vx_any_from_any(vx_core::t_int(), val);
      output = vx_sample::f_myfunc(inputval);
      return output;
    }

    vx_core::Type_any Class_myfunc::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_int myarg = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_sample::f_myfunc(myarg);
      return output;
    }

  //}

  vx_sample::vx_Class_package* vx_package = new vx_sample::vx_Class_package();

  vx_sample::Type_mytype e_mytype() {
    vx_sample::Type_mytype output = vx_sample::vx_package->e_mytype;
    if (output == NULL) {
      output = new Class_mytype();
      vx_core::vx_reserve_empty(output);
      vx_sample::vx_package->e_mytype = output;
    }
    return output;
  }
  vx_sample::Type_mytype t_mytype() {
    vx_sample::Type_mytype output = vx_sample::vx_package->t_mytype;
    if (output == NULL) {
      output = new Class_mytype();
      vx_core::vx_reserve_type(output);
      vx_sample::vx_package->t_mytype = output;
    }
    return output;
  }

  // (const myconst)
  vx_sample::Const_myconst c_myconst() {
    vx_sample::Const_myconst output = vx_sample::vx_package->c_myconst;
    if (output == NULL) {
      output = new vx_sample::Class_myconst();
      vx_core::vx_reserve_type(output);
      vx_sample::vx_package->c_myconst = output;
    }
    return output;
  }

  // (func main)
  vx_sample::Func_main e_main() {
    vx_sample::Func_main output = vx_sample::vx_package->e_main;
    if (output == NULL) {
      output = new vx_sample::Class_main();
      vx_core::vx_reserve_empty(output);
      vx_sample::vx_package->e_main = output;
    }
    return output;
  }
  vx_sample::Func_main t_main() {
    vx_sample::Func_main output = vx_sample::vx_package->t_main;
    if (output == NULL) {
      output = new vx_sample::Class_main();
      vx_core::vx_reserve_type(output);
      vx_sample::vx_package->t_main = output;
    }
    return output;
  }

  // (func myfunc)
  vx_sample::Func_myfunc e_myfunc() {
    vx_sample::Func_myfunc output = vx_sample::vx_package->e_myfunc;
    if (output == NULL) {
      output = new vx_sample::Class_myfunc();
      vx_core::vx_reserve_empty(output);
      vx_sample::vx_package->e_myfunc = output;
    }
    return output;
  }
  vx_sample::Func_myfunc t_myfunc() {
    vx_sample::Func_myfunc output = vx_sample::vx_package->t_myfunc;
    if (output == NULL) {
      output = new vx_sample::Class_myfunc();
      vx_core::vx_reserve_type(output);
      vx_sample::vx_package->t_myfunc = output;
    }
    return output;
  }

}