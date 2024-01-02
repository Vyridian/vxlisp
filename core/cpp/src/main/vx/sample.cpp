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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_mynum,
        this->vx_p_mystr
      });
    }

    // mynum()
    vx_core::Type_int Class_mytype::mynum() const {
      vx_core::Type_int output = this->vx_p_mynum;
      if (!output) {
        output = vx_core::e_int;
      }
      return output;
    }

    // mystr()
    vx_core::Type_string Class_mytype::mystr() const {
      vx_core::Type_string output = this->vx_p_mystr;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_mytype::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":mynum") {
        output = this->mynum();
      } else if (skey == ":mystr") {
        output = this->mystr();
      }
      vx_core::vx_release_except(key, output);
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
      return this->vx_copy(vx_sample::e_mytype, vals);
    }

    vx_core::Type_any Class_mytype::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_sample::Type_mytype output = vx_sample::e_mytype;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_sample::Type_mytype val = vx_core::vx_any_from_any(vx_sample::t_mytype, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_int vx_p_mynum = val->mynum();
      vx_core::Type_string vx_p_mystr = val->mystr();
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
          } else if (testkey == ":mynum") {
            key = testkey;
          } else if (testkey == ":mystr") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new mytype) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":mynum") {
            if (vx_p_mynum == valsub) {
            } else if (valsubtype == vx_core::t_int) {
              ischanged = true;
              vx_p_mynum = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new mytype :mynum " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":mystr") {
            if (vx_p_mystr == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_mystr = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new mytype :mystr " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new mytype) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_sample::Class_mytype();
        if (output->vx_p_mynum != vx_p_mynum) {
          if (output->vx_p_mynum) {
            vx_core::vx_release_one(output->vx_p_mynum);
          }
          output->vx_p_mynum = vx_p_mynum;
          vx_core::vx_reserve(vx_p_mynum);
        }
        if (output->vx_p_mystr != vx_p_mystr) {
          if (output->vx_p_mystr) {
            vx_core::vx_release_one(output->vx_p_mystr);
          }
          output->vx_p_mystr = vx_p_mystr;
          vx_core::vx_reserve(vx_p_mystr);
        }
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_mytype::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_sample::Class_mytype::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_mytype::vx_empty() const {return vx_sample::e_mytype;}
    vx_core::Type_any Class_mytype::vx_type() const {return vx_sample::t_mytype;}

    vx_core::Type_typedef Class_mytype::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
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
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "mynum", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "mystr", // name
            vx_core::t_string // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_mytype::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (const myconst)
  // class Class_myconst {
    // vx_const_new()
    void vx_sample::Class_myconst::vx_const_new(vx_sample::Const_myconst output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/sample", "myconst");
      output->vx_p_int = 4;
      vx_core::vx_reserve_type(output);
    }

    long vx_sample::Class_myconst::vx_int() const {
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_main::vx_new(vx_core::vx_Type_listany vals) const {
      vx_sample::Func_main output = vx_sample::e_main;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_main::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_sample::Func_main output = vx_sample::e_main;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_main::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/sample", // pkgname
        "main", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_main::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_main::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/sample", // pkgname
        "main", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_main::vx_empty() const {return vx_sample::e_main;}
    vx_core::Type_any Class_main::vx_type() const {return vx_sample::t_main;}
    vx_core::Type_msgblock Class_main::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_main::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_main::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_sample::f_main();
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func myfunc)
  vx_core::Type_int f_myfunc(vx_core::Type_int myarg) {
    vx_core::Type_int output = vx_core::e_int;
    vx_core::vx_reserve(myarg);
    output = vx_core::f_plus(
      vx_sample::c_myconst,
      myarg
    );
    vx_core::vx_release_one_except(myarg, output);
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
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_myfunc::vx_new(vx_core::vx_Type_listany vals) const {
      vx_sample::Func_myfunc output = vx_sample::e_myfunc;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_myfunc::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_sample::Func_myfunc output = vx_sample::e_myfunc;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_myfunc::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/sample", // pkgname
        "myfunc", // name
        ":func", // extends
        vx_core::vx_new(vx_core::t_typelist, {vx_core::t_func}), // traits
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

    vx_core::Type_constdef Class_myfunc::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_myfunc::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/sample", // pkgname
        "myfunc", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_myfunc::vx_empty() const {return vx_sample::e_myfunc;}
    vx_core::Type_any Class_myfunc::vx_type() const {return vx_sample::t_myfunc;}
    vx_core::Type_msgblock Class_myfunc::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_myfunc::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_myfunc::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_myfunc::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_int inputval = vx_core::vx_any_from_any(vx_core::t_int, val);
      output = vx_sample::f_myfunc(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_myfunc::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_int myarg = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_sample::f_myfunc(myarg);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_sample::Type_mytype e_mytype = NULL;
  vx_sample::Type_mytype t_mytype = NULL;
  vx_sample::Const_myconst c_myconst = NULL;
  vx_sample::Func_main e_main = NULL;
  vx_sample::Func_main t_main = NULL;
  vx_sample::Func_myfunc e_myfunc = NULL;
  vx_sample::Func_myfunc t_myfunc = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_sample::c_myconst = new vx_sample::Class_myconst();
      vx_sample::e_mytype = new Class_mytype();
      vx_core::vx_reserve_empty(vx_sample::e_mytype);
      vx_sample::t_mytype = new Class_mytype();
      vx_core::vx_reserve_type(vx_sample::t_mytype);
      vx_sample::e_main = new vx_sample::Class_main();
      vx_core::vx_reserve_empty(vx_sample::e_main);
      vx_sample::t_main = new vx_sample::Class_main();
      vx_core::vx_reserve_type(vx_sample::t_main);
      vx_sample::e_myfunc = new vx_sample::Class_myfunc();
      vx_core::vx_reserve_empty(vx_sample::e_myfunc);
      vx_sample::t_myfunc = new vx_sample::Class_myfunc();
      vx_core::vx_reserve_type(vx_sample::t_myfunc);
      vx_sample::Class_myconst::vx_const_new(vx_sample::c_myconst);
      vx_core::vx_Type_mapany maptype;
      vx_core::vx_Type_mapany mapconst;
      vx_core::vx_Type_mapfunc mapfunc;
      vx_core::vx_Type_mapany mapempty;
      maptype["mytype"] = vx_sample::t_mytype;
      mapconst["myconst"] = vx_sample::c_myconst;
      mapfunc["main"] = vx_sample::t_main;
      mapfunc["myfunc"] = vx_sample::t_myfunc;
      vx_core::vx_global_package_set("vx/sample", maptype, mapconst, mapfunc);
	   }
  // }

}
