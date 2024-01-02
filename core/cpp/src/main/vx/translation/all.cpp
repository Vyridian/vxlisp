#include "../../vx/core.hpp"
#include "../../vx/translate.hpp"
#include "../../vx/translation/en.hpp"
#include "../../vx/translation/es.hpp"
#include "all.hpp"

namespace vx_translation_all {



  // (func context-all)
  vx_core::Type_context f_context_all(vx_core::Type_anylist args) {
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
            vx_core::vx_new_string(":translationmap"),
            vx_translation_all::f_translationmap_all()
          })
        )
      })
    );
    vx_core::vx_release_one_except(args, output);
    return output;
  }

  // (func context-all)
  // class Class_context_all {
    Abstract_context_all::~Abstract_context_all() {}

    Class_context_all::Class_context_all() : Abstract_context_all::Abstract_context_all() {
      vx_core::refcount += 1;
    }

    Class_context_all::~Class_context_all() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_context_all::vx_new(vx_core::vx_Type_listany vals) const {
      vx_translation_all::Func_context_all output = vx_translation_all::e_context_all;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_context_all::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_translation_all::Func_context_all output = vx_translation_all::e_context_all;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_context_all::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/translation/all", // pkgname
        "context-all", // name
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

    vx_core::Type_constdef Class_context_all::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_context_all::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/translation/all", // pkgname
        "context-all", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_context_all::vx_empty() const {return vx_translation_all::e_context_all;}
    vx_core::Type_any Class_context_all::vx_type() const {return vx_translation_all::t_context_all;}
    vx_core::Type_msgblock Class_context_all::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_context_all::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_context_all::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_context_all::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_anylist inputval = vx_core::vx_any_from_any(vx_core::t_anylist, val);
      output = vx_translation_all::f_context_all(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_context_all::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_anylist args = vx_core::vx_any_from_any(vx_core::t_anylist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_translation_all::f_context_all(args);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func translationmap-all)
  vx_core::Type_translationmap f_translationmap_all() {
    vx_core::Type_translationmap output = vx_core::e_translationmap;
    output = vx_translate::f_translationmap_from_translations(
      vx_core::vx_new(vx_core::t_translationlist, {
        vx_translation_en::f_translation_en(),
        vx_translation_es::f_translation_es()
      })
    );
    return output;
  }

  // (func translationmap-all)
  // class Class_translationmap_all {
    Abstract_translationmap_all::~Abstract_translationmap_all() {}

    Class_translationmap_all::Class_translationmap_all() : Abstract_translationmap_all::Abstract_translationmap_all() {
      vx_core::refcount += 1;
    }

    Class_translationmap_all::~Class_translationmap_all() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_translationmap_all::vx_new(vx_core::vx_Type_listany vals) const {
      vx_translation_all::Func_translationmap_all output = vx_translation_all::e_translationmap_all;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_translationmap_all::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_translation_all::Func_translationmap_all output = vx_translation_all::e_translationmap_all;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_translationmap_all::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/translation/all", // pkgname
        "translationmap-all", // name
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

    vx_core::Type_constdef Class_translationmap_all::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_translationmap_all::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/translation/all", // pkgname
        "translationmap-all", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_translationmap_all::vx_empty() const {return vx_translation_all::e_translationmap_all;}
    vx_core::Type_any Class_translationmap_all::vx_type() const {return vx_translation_all::t_translationmap_all;}
    vx_core::Type_msgblock Class_translationmap_all::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_translationmap_all::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_translationmap_all::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      output = vx_translation_all::f_translationmap_all();
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_translation_all::Func_context_all e_context_all = NULL;
  vx_translation_all::Func_context_all t_context_all = NULL;
  vx_translation_all::Func_translationmap_all e_translationmap_all = NULL;
  vx_translation_all::Func_translationmap_all t_translationmap_all = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_translation_all::e_context_all = new vx_translation_all::Class_context_all();
      vx_core::vx_reserve_empty(vx_translation_all::e_context_all);
      vx_translation_all::t_context_all = new vx_translation_all::Class_context_all();
      vx_core::vx_reserve_type(vx_translation_all::t_context_all);
      vx_translation_all::e_translationmap_all = new vx_translation_all::Class_translationmap_all();
      vx_core::vx_reserve_empty(vx_translation_all::e_translationmap_all);
      vx_translation_all::t_translationmap_all = new vx_translation_all::Class_translationmap_all();
      vx_core::vx_reserve_type(vx_translation_all::t_translationmap_all);
      vx_core::vx_Type_mapany maptype;
      vx_core::vx_Type_mapany mapconst;
      vx_core::vx_Type_mapfunc mapfunc;
      vx_core::vx_Type_mapany mapempty;
      mapfunc["context-all"] = vx_translation_all::t_context_all;
      mapfunc["translationmap-all"] = vx_translation_all::t_translationmap_all;
      vx_core::vx_global_package_set("vx/translation/all", maptype, mapconst, mapfunc);
	   }
  // }

}
