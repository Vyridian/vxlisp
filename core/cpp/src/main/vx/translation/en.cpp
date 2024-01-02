#include "../../vx/core.hpp"
#include "../../vx/data/file.hpp"
#include "../../vx/translate.hpp"
#include "en.hpp"

namespace vx_translation_en {



  // (func context-en)
  vx_core::Type_context f_context_en(vx_core::Type_anylist args) {
    vx_core::Type_context output = vx_core::e_context;
    vx_core::vx_reserve(args);
    output = vx_core::f_new(
      vx_core::t_context,
      vx_core::vx_new(vx_core::t_anylist, {
        vx_core::vx_new_string(":session"),
        vx_core::f_new(
          vx_core::t_session,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":translation"),
            vx_translation_en::f_translation_en()
          })
        )
      })
    );
    vx_core::vx_release_one_except(args, output);
    return output;
  }

  // (func context-en)
  // class Class_context_en {
    Abstract_context_en::~Abstract_context_en() {}

    Class_context_en::Class_context_en() : Abstract_context_en::Abstract_context_en() {
      vx_core::refcount += 1;
    }

    Class_context_en::~Class_context_en() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_context_en::vx_new(vx_core::vx_Type_listany vals) const {
      vx_translation_en::Func_context_en output = vx_translation_en::e_context_en;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_context_en::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_translation_en::Func_context_en output = vx_translation_en::e_context_en;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_context_en::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/translation/en", // pkgname
        "context-en", // name
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

    vx_core::Type_constdef Class_context_en::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_context_en::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/translation/en", // pkgname
        "context-en", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_context_en::vx_empty() const {return vx_translation_en::e_context_en;}
    vx_core::Type_any Class_context_en::vx_type() const {return vx_translation_en::t_context_en;}
    vx_core::Type_msgblock Class_context_en::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_context_en::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_context_en::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_context_en::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_anylist inputval = vx_core::vx_any_from_any(vx_core::t_anylist, val);
      output = vx_translation_en::f_context_en(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_context_en::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_anylist args = vx_core::vx_any_from_any(vx_core::t_anylist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_translation_en::f_context_en(args);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func context-test)
  vx_core::Type_context f_context_test(vx_core::Type_anylist args) {
    vx_core::Type_context output = vx_core::e_context;
    vx_core::vx_reserve(args);
    output = vx_core::f_new(
      vx_core::t_context,
      vx_core::vx_new(vx_core::t_anylist, {
        vx_core::vx_new_string(":session"),
        vx_core::f_new(
          vx_core::t_session,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":translation"),
            vx_translation_en::f_translation_en(),
            vx_core::vx_new_string(":user"),
            vx_core::f_new(
              vx_core::t_user,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(":security"),
                vx_translation_en::f_securitydata_test()
              })
            )
          })
        )
      })
    );
    vx_core::vx_release_one_except(args, output);
    return output;
  }

  // (func context-test)
  // class Class_context_test {
    Abstract_context_test::~Abstract_context_test() {}

    Class_context_test::Class_context_test() : Abstract_context_test::Abstract_context_test() {
      vx_core::refcount += 1;
    }

    Class_context_test::~Class_context_test() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_context_test::vx_new(vx_core::vx_Type_listany vals) const {
      vx_translation_en::Func_context_test output = vx_translation_en::e_context_test;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_context_test::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_translation_en::Func_context_test output = vx_translation_en::e_context_test;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_context_test::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/translation/en", // pkgname
        "context-test", // name
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

    vx_core::Type_constdef Class_context_test::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_context_test::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/translation/en", // pkgname
        "context-test", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_context_test::vx_empty() const {return vx_translation_en::e_context_test;}
    vx_core::Type_any Class_context_test::vx_type() const {return vx_translation_en::t_context_test;}
    vx_core::Type_msgblock Class_context_test::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_context_test::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_context_test::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_context_test::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_anylist inputval = vx_core::vx_any_from_any(vx_core::t_anylist, val);
      output = vx_translation_en::f_context_test(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_context_test::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_anylist args = vx_core::vx_any_from_any(vx_core::t_anylist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_translation_en::f_context_test(args);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func securitydata-test)
  vx_core::Type_security f_securitydata_test() {
    vx_core::Type_security output = vx_core::e_security;
    output = vx_core::f_new(
      vx_core::t_security,
      vx_core::vx_new(vx_core::t_anylist, {
        vx_core::vx_new_string(":allowfuncs"),
        vx_core::f_new(
          vx_core::t_funclist,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_data_file::t_boolean_write_from_file_any,
            vx_data_file::t_boolean_write_from_file_string,
            vx_data_file::t_file_read_from_file,
            vx_data_file::t_string_read_from_file
          })
        )
      })
    );
    return output;
  }

  // (func securitydata-test)
  // class Class_securitydata_test {
    Abstract_securitydata_test::~Abstract_securitydata_test() {}

    Class_securitydata_test::Class_securitydata_test() : Abstract_securitydata_test::Abstract_securitydata_test() {
      vx_core::refcount += 1;
    }

    Class_securitydata_test::~Class_securitydata_test() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_securitydata_test::vx_new(vx_core::vx_Type_listany vals) const {
      vx_translation_en::Func_securitydata_test output = vx_translation_en::e_securitydata_test;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_securitydata_test::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_translation_en::Func_securitydata_test output = vx_translation_en::e_securitydata_test;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_securitydata_test::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/translation/en", // pkgname
        "securitydata-test", // name
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

    vx_core::Type_constdef Class_securitydata_test::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_securitydata_test::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/translation/en", // pkgname
        "securitydata-test", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_securitydata_test::vx_empty() const {return vx_translation_en::e_securitydata_test;}
    vx_core::Type_any Class_securitydata_test::vx_type() const {return vx_translation_en::t_securitydata_test;}
    vx_core::Type_msgblock Class_securitydata_test::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_securitydata_test::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_securitydata_test::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      output = vx_translation_en::f_securitydata_test();
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func translation-en)
  vx_core::Type_translation f_translation_en() {
    vx_core::Type_translation output = vx_core::e_translation;
    output = vx_core::f_new(
      vx_core::t_translation,
      vx_core::vx_new(vx_core::t_anylist, {
        vx_core::vx_new_string(":name"),
        vx_core::vx_new_string("en"),
        vx_core::vx_new_string(":wordmap"),
        vx_translation_en::f_words()
      })
    );
    return output;
  }

  // (func translation-en)
  // class Class_translation_en {
    Abstract_translation_en::~Abstract_translation_en() {}

    Class_translation_en::Class_translation_en() : Abstract_translation_en::Abstract_translation_en() {
      vx_core::refcount += 1;
    }

    Class_translation_en::~Class_translation_en() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_translation_en::vx_new(vx_core::vx_Type_listany vals) const {
      vx_translation_en::Func_translation_en output = vx_translation_en::e_translation_en;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_translation_en::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_translation_en::Func_translation_en output = vx_translation_en::e_translation_en;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_translation_en::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/translation/en", // pkgname
        "translation-en", // name
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

    vx_core::Type_constdef Class_translation_en::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_translation_en::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/translation/en", // pkgname
        "translation-en", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_translation_en::vx_empty() const {return vx_translation_en::e_translation_en;}
    vx_core::Type_any Class_translation_en::vx_type() const {return vx_translation_en::t_translation_en;}
    vx_core::Type_msgblock Class_translation_en::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_translation_en::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_translation_en::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      output = vx_translation_en::f_translation_en();
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func words)
  vx_core::Type_stringmap f_words() {
    vx_core::Type_stringmap output = vx_core::e_stringmap;
    output = vx_core::f_new(
      vx_core::t_stringmap,
      vx_core::vx_new(vx_core::t_anylist, {
        vx_core::vx_new_string("Hello"),
        vx_core::vx_new_string("Hello"),
        vx_core::vx_new_string("World"),
        vx_core::vx_new_string("World"),
        vx_core::vx_new_string("!vx/core/func exception"),
        vx_core::vx_new_string("Exception in Function"),
        vx_core::vx_new_string("!vx/core/func permissiondenied"),
        vx_core::vx_new_string("Permission Denied to Function"),
        vx_core::vx_new_string("!vx/repl/repl/repl<-string-argmap repltypenotfound"),
        vx_core::vx_new_string("Repl Type Not Found")
      })
    );
    return output;
  }

  // (func words)
  // class Class_words {
    Abstract_words::~Abstract_words() {}

    Class_words::Class_words() : Abstract_words::Abstract_words() {
      vx_core::refcount += 1;
    }

    Class_words::~Class_words() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_words::vx_new(vx_core::vx_Type_listany vals) const {
      vx_translation_en::Func_words output = vx_translation_en::e_words;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_words::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_translation_en::Func_words output = vx_translation_en::e_words;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_words::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/translation/en", // pkgname
        "words", // name
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

    vx_core::Type_constdef Class_words::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_words::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/translation/en", // pkgname
        "words", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_words::vx_empty() const {return vx_translation_en::e_words;}
    vx_core::Type_any Class_words::vx_type() const {return vx_translation_en::t_words;}
    vx_core::Type_msgblock Class_words::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_words::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_words::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      output = vx_translation_en::f_words();
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_translation_en::Func_context_en e_context_en = NULL;
  vx_translation_en::Func_context_en t_context_en = NULL;
  vx_translation_en::Func_context_test e_context_test = NULL;
  vx_translation_en::Func_context_test t_context_test = NULL;
  vx_translation_en::Func_securitydata_test e_securitydata_test = NULL;
  vx_translation_en::Func_securitydata_test t_securitydata_test = NULL;
  vx_translation_en::Func_translation_en e_translation_en = NULL;
  vx_translation_en::Func_translation_en t_translation_en = NULL;
  vx_translation_en::Func_words e_words = NULL;
  vx_translation_en::Func_words t_words = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_translation_en::e_context_en = new vx_translation_en::Class_context_en();
      vx_core::vx_reserve_empty(vx_translation_en::e_context_en);
      vx_translation_en::t_context_en = new vx_translation_en::Class_context_en();
      vx_core::vx_reserve_type(vx_translation_en::t_context_en);
      vx_translation_en::e_context_test = new vx_translation_en::Class_context_test();
      vx_core::vx_reserve_empty(vx_translation_en::e_context_test);
      vx_translation_en::t_context_test = new vx_translation_en::Class_context_test();
      vx_core::vx_reserve_type(vx_translation_en::t_context_test);
      vx_translation_en::e_securitydata_test = new vx_translation_en::Class_securitydata_test();
      vx_core::vx_reserve_empty(vx_translation_en::e_securitydata_test);
      vx_translation_en::t_securitydata_test = new vx_translation_en::Class_securitydata_test();
      vx_core::vx_reserve_type(vx_translation_en::t_securitydata_test);
      vx_translation_en::e_translation_en = new vx_translation_en::Class_translation_en();
      vx_core::vx_reserve_empty(vx_translation_en::e_translation_en);
      vx_translation_en::t_translation_en = new vx_translation_en::Class_translation_en();
      vx_core::vx_reserve_type(vx_translation_en::t_translation_en);
      vx_translation_en::e_words = new vx_translation_en::Class_words();
      vx_core::vx_reserve_empty(vx_translation_en::e_words);
      vx_translation_en::t_words = new vx_translation_en::Class_words();
      vx_core::vx_reserve_type(vx_translation_en::t_words);
      vx_core::vx_Type_mapany maptype;
      vx_core::vx_Type_mapany mapconst;
      vx_core::vx_Type_mapfunc mapfunc;
      vx_core::vx_Type_mapany mapempty;
      mapfunc["context-en"] = vx_translation_en::t_context_en;
      mapfunc["context-test"] = vx_translation_en::t_context_test;
      mapfunc["securitydata-test"] = vx_translation_en::t_securitydata_test;
      mapfunc["translation-en"] = vx_translation_en::t_translation_en;
      mapfunc["words"] = vx_translation_en::t_words;
      vx_core::vx_global_package_set("vx/translation/en", maptype, mapconst, mapfunc);
	   }
  // }

}
