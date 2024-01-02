#include "../../vx/core.hpp"
#include "../../vx/translate.hpp"
#include "es.hpp"

namespace vx_translation_es {



  // (func translation-es)
  vx_core::Type_translation f_translation_es() {
    vx_core::Type_translation output = vx_core::e_translation;
    output = vx_core::f_new(
      vx_core::t_translation,
      vx_core::vx_new(vx_core::t_anylist, {
        vx_core::vx_new_string(":name"),
        vx_core::vx_new_string("es"),
        vx_core::vx_new_string(":wordmap"),
        vx_translation_es::f_words()
      })
    );
    return output;
  }

  // (func translation-es)
  // class Class_translation_es {
    Abstract_translation_es::~Abstract_translation_es() {}

    Class_translation_es::Class_translation_es() : Abstract_translation_es::Abstract_translation_es() {
      vx_core::refcount += 1;
    }

    Class_translation_es::~Class_translation_es() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_translation_es::vx_new(vx_core::vx_Type_listany vals) const {
      vx_translation_es::Func_translation_es output = vx_translation_es::e_translation_es;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_translation_es::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_translation_es::Func_translation_es output = vx_translation_es::e_translation_es;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_translation_es::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/translation/es", // pkgname
        "translation-es", // name
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

    vx_core::Type_constdef Class_translation_es::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_translation_es::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/translation/es", // pkgname
        "translation-es", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_translation_es::vx_empty() const {return vx_translation_es::e_translation_es;}
    vx_core::Type_any Class_translation_es::vx_type() const {return vx_translation_es::t_translation_es;}
    vx_core::Type_msgblock Class_translation_es::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_translation_es::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_translation_es::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      output = vx_translation_es::f_translation_es();
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
        vx_core::vx_new_string("Hola"),
        vx_core::vx_new_string("World"),
        vx_core::vx_new_string("Mundo")
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
      vx_translation_es::Func_words output = vx_translation_es::e_words;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_words::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_translation_es::Func_words output = vx_translation_es::e_words;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_words::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/translation/es", // pkgname
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
        "vx/translation/es", // pkgname
        "words", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_words::vx_empty() const {return vx_translation_es::e_words;}
    vx_core::Type_any Class_words::vx_type() const {return vx_translation_es::t_words;}
    vx_core::Type_msgblock Class_words::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_words::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_words::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      output = vx_translation_es::f_words();
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_translation_es::Func_translation_es e_translation_es = NULL;
  vx_translation_es::Func_translation_es t_translation_es = NULL;
  vx_translation_es::Func_words e_words = NULL;
  vx_translation_es::Func_words t_words = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_translation_es::e_translation_es = new vx_translation_es::Class_translation_es();
      vx_core::vx_reserve_empty(vx_translation_es::e_translation_es);
      vx_translation_es::t_translation_es = new vx_translation_es::Class_translation_es();
      vx_core::vx_reserve_type(vx_translation_es::t_translation_es);
      vx_translation_es::e_words = new vx_translation_es::Class_words();
      vx_core::vx_reserve_empty(vx_translation_es::e_words);
      vx_translation_es::t_words = new vx_translation_es::Class_words();
      vx_core::vx_reserve_type(vx_translation_es::t_words);
      vx_core::vx_Type_mapany maptype;
      vx_core::vx_Type_mapany mapconst;
      vx_core::vx_Type_mapfunc mapfunc;
      vx_core::vx_Type_mapany mapempty;
      mapfunc["translation-es"] = vx_translation_es::t_translation_es;
      mapfunc["words"] = vx_translation_es::t_words;
      vx_core::vx_global_package_set("vx/translation/es", maptype, mapconst, mapfunc);
	   }
  // }

}
