#include "../vx/core.hpp"
#include "../vx/data/csv.hpp"
#include "../vx/data/file.hpp"
#include "translate.hpp"

namespace vx_translate {


  // (func session<-session-name)
  vx_core::Type_session f_session_from_session_name(vx_core::Type_session session, vx_core::Type_string name) {
    vx_core::Type_session output = vx_core::e_session;
    vx_core::vx_reserve({session, name});
    output = vx_core::f_copy(
      vx_core::t_session,
      session,
      vx_core::vx_new(vx_core::t_anylist, {
        vx_core::vx_new_string(":translation"),
        vx_translate::f_translation_from_session_name(session, name)
      })
    );
    vx_core::vx_release_one_except({session, name}, output);
    return output;
  }

  // (func session<-session-name)
  // class Class_session_from_session_name {
    Abstract_session_from_session_name::~Abstract_session_from_session_name() {}

    Class_session_from_session_name::Class_session_from_session_name() : Abstract_session_from_session_name::Abstract_session_from_session_name() {
      vx_core::refcount += 1;
    }

    Class_session_from_session_name::~Class_session_from_session_name() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_session_from_session_name::vx_new(vx_core::vx_Type_listany vals) const {
      vx_translate::Func_session_from_session_name output = vx_translate::e_session_from_session_name;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_session_from_session_name::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_translate::Func_session_from_session_name output = vx_translate::e_session_from_session_name;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_session_from_session_name::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/translate", // pkgname
        "session<-session-name", // name
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

    vx_core::Type_constdef Class_session_from_session_name::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_session_from_session_name::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/translate", // pkgname
        "session<-session-name", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_session_from_session_name::vx_empty() const {return vx_translate::e_session_from_session_name;}
    vx_core::Type_any Class_session_from_session_name::vx_type() const {return vx_translate::t_session_from_session_name;}
    vx_core::Type_msgblock Class_session_from_session_name::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_session_from_session_name::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_session_from_session_name::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_session session = vx_core::vx_any_from_any(vx_core::t_session, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string name = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_translate::f_session_from_session_name(session, name);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func session<-session-translation)
  vx_core::Type_session f_session_from_session_translation(vx_core::Type_session session, vx_core::Type_translation translation) {
    vx_core::Type_session output = vx_core::e_session;
    vx_core::vx_reserve({session, translation});
    output = vx_core::f_copy(
      vx_core::t_session,
      session,
      vx_core::vx_new(vx_core::t_anylist, {
        vx_core::vx_new_string(":translation"),
        translation
      })
    );
    vx_core::vx_release_one_except({session, translation}, output);
    return output;
  }

  // (func session<-session-translation)
  // class Class_session_from_session_translation {
    Abstract_session_from_session_translation::~Abstract_session_from_session_translation() {}

    Class_session_from_session_translation::Class_session_from_session_translation() : Abstract_session_from_session_translation::Abstract_session_from_session_translation() {
      vx_core::refcount += 1;
    }

    Class_session_from_session_translation::~Class_session_from_session_translation() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_session_from_session_translation::vx_new(vx_core::vx_Type_listany vals) const {
      vx_translate::Func_session_from_session_translation output = vx_translate::e_session_from_session_translation;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_session_from_session_translation::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_translate::Func_session_from_session_translation output = vx_translate::e_session_from_session_translation;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_session_from_session_translation::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/translate", // pkgname
        "session<-session-translation", // name
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

    vx_core::Type_constdef Class_session_from_session_translation::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_session_from_session_translation::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/translate", // pkgname
        "session<-session-translation", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_session_from_session_translation::vx_empty() const {return vx_translate::e_session_from_session_translation;}
    vx_core::Type_any Class_session_from_session_translation::vx_type() const {return vx_translate::t_session_from_session_translation;}
    vx_core::Type_msgblock Class_session_from_session_translation::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_session_from_session_translation::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_session_from_session_translation::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_session session = vx_core::vx_any_from_any(vx_core::t_session, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_translation translation = vx_core::vx_any_from_any(vx_core::t_translation, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_translate::f_session_from_session_translation(session, translation);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func session<-session-translationmap-name)
  vx_core::Type_session f_session_from_session_translationmap_name(vx_core::Type_session session, vx_core::Type_translationmap translationmap, vx_core::Type_string name) {
    vx_core::Type_session output = vx_core::e_session;
    vx_core::vx_reserve({session, translationmap, name});
    output = vx_core::f_copy(
      vx_core::t_session,
      session,
      vx_core::vx_new(vx_core::t_anylist, {
        vx_core::vx_new_string(":translation"),
        vx_core::f_any_from_map(vx_core::t_anylist, translationmap, name),
        vx_core::vx_new_string(":translationmap"),
        translationmap
      })
    );
    vx_core::vx_release_one_except({session, translationmap, name}, output);
    return output;
  }

  // (func session<-session-translationmap-name)
  // class Class_session_from_session_translationmap_name {
    Abstract_session_from_session_translationmap_name::~Abstract_session_from_session_translationmap_name() {}

    Class_session_from_session_translationmap_name::Class_session_from_session_translationmap_name() : Abstract_session_from_session_translationmap_name::Abstract_session_from_session_translationmap_name() {
      vx_core::refcount += 1;
    }

    Class_session_from_session_translationmap_name::~Class_session_from_session_translationmap_name() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_session_from_session_translationmap_name::vx_new(vx_core::vx_Type_listany vals) const {
      vx_translate::Func_session_from_session_translationmap_name output = vx_translate::e_session_from_session_translationmap_name;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_session_from_session_translationmap_name::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_translate::Func_session_from_session_translationmap_name output = vx_translate::e_session_from_session_translationmap_name;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_session_from_session_translationmap_name::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/translate", // pkgname
        "session<-session-translationmap-name", // name
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

    vx_core::Type_constdef Class_session_from_session_translationmap_name::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_session_from_session_translationmap_name::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/translate", // pkgname
        "session<-session-translationmap-name", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_session_from_session_translationmap_name::vx_empty() const {return vx_translate::e_session_from_session_translationmap_name;}
    vx_core::Type_any Class_session_from_session_translationmap_name::vx_type() const {return vx_translate::t_session_from_session_translationmap_name;}
    vx_core::Type_msgblock Class_session_from_session_translationmap_name::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_session_from_session_translationmap_name::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_session_from_session_translationmap_name::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_session session = vx_core::vx_any_from_any(vx_core::t_session, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_translationmap translationmap = vx_core::vx_any_from_any(vx_core::t_translationmap, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_string name = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_translate::f_session_from_session_translationmap_name(session, translationmap, name);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func translate)
  vx_core::Type_string f_translate(vx_core::Type_context context, vx_core::Type_string text) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve(text);
    output = vx_translate::f_translate_from_translation_string(
      vx_translate::f_translation_from_context(context),
      text
    );
    vx_core::vx_release_one_except(text, output);
    return output;
  }

  // (func translate)
  // class Class_translate {
    Abstract_translate::~Abstract_translate() {}

    Class_translate::Class_translate() : Abstract_translate::Abstract_translate() {
      vx_core::refcount += 1;
    }

    Class_translate::~Class_translate() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_translate::vx_new(vx_core::vx_Type_listany vals) const {
      vx_translate::Func_translate output = vx_translate::e_translate;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_translate::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_translate::Func_translate output = vx_translate::e_translate;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_translate::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/translate", // pkgname
        "translate", // name
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

    vx_core::Type_constdef Class_translate::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_translate::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/translate", // pkgname
        "translate", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_translate::vx_empty() const {return vx_translate::e_translate;}
    vx_core::Type_any Class_translate::vx_type() const {return vx_translate::t_translate;}
    vx_core::Type_msgblock Class_translate::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_translate::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_translate::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_translate::vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      output = vx_translate::f_translate(context, inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_translate::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_translate::f_translate(context, text);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func translate<-translation-string)
  vx_core::Type_string f_translate_from_translation_string(vx_core::Type_translation translation, vx_core::Type_string text) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({translation, text});
    output = vx_core::f_if_1(
      vx_core::t_string,
      vx_core::f_is_empty_1(translation),
      text,
      vx_core::f_let(
        vx_core::t_string,
        vx_core::t_any_from_func->vx_fn_new({translation, text}, [translation, text]() {
          vx_core::Type_stringmap wordmap = translation->wordmap();
          vx_core::vx_ref_plus(wordmap);
          vx_core::Type_string xlate = vx_core::f_any_from_map(vx_core::t_string, wordmap, text);
          vx_core::vx_ref_plus(xlate);
          vx_core::Type_string output_1 = vx_core::f_if_1(
            vx_core::t_string,
            vx_core::f_is_empty(xlate),
            text,
            xlate
          );
          vx_core::vx_release_one_except({wordmap, xlate}, output_1);
          return output_1;
        })
      )
    );
    vx_core::vx_release_one_except({translation, text}, output);
    return output;
  }

  // (func translate<-translation-string)
  // class Class_translate_from_translation_string {
    Abstract_translate_from_translation_string::~Abstract_translate_from_translation_string() {}

    Class_translate_from_translation_string::Class_translate_from_translation_string() : Abstract_translate_from_translation_string::Abstract_translate_from_translation_string() {
      vx_core::refcount += 1;
    }

    Class_translate_from_translation_string::~Class_translate_from_translation_string() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_translate_from_translation_string::vx_new(vx_core::vx_Type_listany vals) const {
      vx_translate::Func_translate_from_translation_string output = vx_translate::e_translate_from_translation_string;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_translate_from_translation_string::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_translate::Func_translate_from_translation_string output = vx_translate::e_translate_from_translation_string;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_translate_from_translation_string::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/translate", // pkgname
        "translate<-translation-string", // name
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

    vx_core::Type_constdef Class_translate_from_translation_string::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_translate_from_translation_string::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/translate", // pkgname
        "translate<-translation-string", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_translate_from_translation_string::vx_empty() const {return vx_translate::e_translate_from_translation_string;}
    vx_core::Type_any Class_translate_from_translation_string::vx_type() const {return vx_translate::t_translate_from_translation_string;}
    vx_core::Type_msgblock Class_translate_from_translation_string::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_translate_from_translation_string::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_translate_from_translation_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_translation translation = vx_core::vx_any_from_any(vx_core::t_translation, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_translate::f_translate_from_translation_string(translation, text);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func translate<-translationmap-name-string)
  vx_core::Type_string f_translate_from_translationmap_name_string(vx_core::Type_translationmap translationmap, vx_core::Type_string name, vx_core::Type_string text) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({translationmap, name, text});
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({translationmap, name, text}, [translationmap, name, text]() {
        vx_core::Type_translation translation = vx_core::f_any_from_map(vx_core::t_translation, translationmap, name);
        vx_core::vx_ref_plus(translation);
        vx_core::Type_string output_1 = vx_translate::f_translate_from_translation_string(translation, text);
        vx_core::vx_release_one_except(translation, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({translationmap, name, text}, output);
    return output;
  }

  // (func translate<-translationmap-name-string)
  // class Class_translate_from_translationmap_name_string {
    Abstract_translate_from_translationmap_name_string::~Abstract_translate_from_translationmap_name_string() {}

    Class_translate_from_translationmap_name_string::Class_translate_from_translationmap_name_string() : Abstract_translate_from_translationmap_name_string::Abstract_translate_from_translationmap_name_string() {
      vx_core::refcount += 1;
    }

    Class_translate_from_translationmap_name_string::~Class_translate_from_translationmap_name_string() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_translate_from_translationmap_name_string::vx_new(vx_core::vx_Type_listany vals) const {
      vx_translate::Func_translate_from_translationmap_name_string output = vx_translate::e_translate_from_translationmap_name_string;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_translate_from_translationmap_name_string::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_translate::Func_translate_from_translationmap_name_string output = vx_translate::e_translate_from_translationmap_name_string;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_translate_from_translationmap_name_string::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/translate", // pkgname
        "translate<-translationmap-name-string", // name
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

    vx_core::Type_constdef Class_translate_from_translationmap_name_string::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_translate_from_translationmap_name_string::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/translate", // pkgname
        "translate<-translationmap-name-string", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_translate_from_translationmap_name_string::vx_empty() const {return vx_translate::e_translate_from_translationmap_name_string;}
    vx_core::Type_any Class_translate_from_translationmap_name_string::vx_type() const {return vx_translate::t_translate_from_translationmap_name_string;}
    vx_core::Type_msgblock Class_translate_from_translationmap_name_string::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_translate_from_translationmap_name_string::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_translate_from_translationmap_name_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_translationmap translationmap = vx_core::vx_any_from_any(vx_core::t_translationmap, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string name = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_translate::f_translate_from_translationmap_name_string(translationmap, name, text);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func translation-load-session)
  vx_core::Type_translation f_translation_load_session(vx_core::Type_context context, vx_core::Type_translation translation) {
    vx_core::Type_translation output = vx_core::e_translation;
    vx_core::vx_reserve(translation);
    vx_core::vx_release_one_except(translation, output);
    return output;
  }

  // (func translation-load-session)
  // class Class_translation_load_session {
    Abstract_translation_load_session::~Abstract_translation_load_session() {}

    Class_translation_load_session::Class_translation_load_session() : Abstract_translation_load_session::Abstract_translation_load_session() {
      vx_core::refcount += 1;
    }

    Class_translation_load_session::~Class_translation_load_session() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_translation_load_session::vx_new(vx_core::vx_Type_listany vals) const {
      vx_translate::Func_translation_load_session output = vx_translate::e_translation_load_session;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_translation_load_session::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_translate::Func_translation_load_session output = vx_translate::e_translation_load_session;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_translation_load_session::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/translate", // pkgname
        "translation-load-session", // name
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

    vx_core::Type_constdef Class_translation_load_session::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_translation_load_session::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/translate", // pkgname
        "translation-load-session", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_translation_load_session::vx_empty() const {return vx_translate::e_translation_load_session;}
    vx_core::Type_any Class_translation_load_session::vx_type() const {return vx_translate::t_translation_load_session;}
    vx_core::Type_msgblock Class_translation_load_session::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_translation_load_session::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_translation_load_session::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_translation_load_session::vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_translation inputval = vx_core::vx_any_from_any(vx_core::t_translation, val);
      output = vx_translate::f_translation_load_session(context, inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_translation_load_session::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_translation translation = vx_core::vx_any_from_any(vx_core::t_translation, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_translate::f_translation_load_session(context, translation);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func translation<-context)
  vx_core::Type_translation f_translation_from_context(vx_core::Type_context context) {
    vx_core::Type_translation output = vx_core::e_translation;
    output = vx_core::f_any_from_struct(
      vx_core::t_translation,
      vx_core::f_session_from_context(context),
      vx_core::vx_new_string(":translation")
    );
    return output;
  }

  // (func translation<-context)
  // class Class_translation_from_context {
    Abstract_translation_from_context::~Abstract_translation_from_context() {}

    Class_translation_from_context::Class_translation_from_context() : Abstract_translation_from_context::Abstract_translation_from_context() {
      vx_core::refcount += 1;
    }

    Class_translation_from_context::~Class_translation_from_context() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_translation_from_context::vx_new(vx_core::vx_Type_listany vals) const {
      vx_translate::Func_translation_from_context output = vx_translate::e_translation_from_context;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_translation_from_context::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_translate::Func_translation_from_context output = vx_translate::e_translation_from_context;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_translation_from_context::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/translate", // pkgname
        "translation<-context", // name
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

    vx_core::Type_constdef Class_translation_from_context::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_translation_from_context::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/translate", // pkgname
        "translation<-context", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_translation_from_context::vx_empty() const {return vx_translate::e_translation_from_context;}
    vx_core::Type_any Class_translation_from_context::vx_type() const {return vx_translate::t_translation_from_context;}
    vx_core::Type_msgblock Class_translation_from_context::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_translation_from_context::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_translation_from_context::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_translate::f_translation_from_context(context);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func translation<-session-name)
  vx_core::Type_translation f_translation_from_session_name(vx_core::Type_session session, vx_core::Type_string name) {
    vx_core::Type_translation output = vx_core::e_translation;
    vx_core::vx_reserve({session, name});
    output = vx_core::f_let(
      vx_core::t_translation,
      vx_core::t_any_from_func->vx_fn_new({session, name}, [session, name]() {
        vx_core::Type_translationmap translationmap = session->translationmap();
        vx_core::vx_ref_plus(translationmap);
        vx_core::Type_translation output_1 = vx_core::f_any_from_map(vx_core::t_translation, translationmap, name);
        vx_core::vx_release_one_except(translationmap, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({session, name}, output);
    return output;
  }

  // (func translation<-session-name)
  // class Class_translation_from_session_name {
    Abstract_translation_from_session_name::~Abstract_translation_from_session_name() {}

    Class_translation_from_session_name::Class_translation_from_session_name() : Abstract_translation_from_session_name::Abstract_translation_from_session_name() {
      vx_core::refcount += 1;
    }

    Class_translation_from_session_name::~Class_translation_from_session_name() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_translation_from_session_name::vx_new(vx_core::vx_Type_listany vals) const {
      vx_translate::Func_translation_from_session_name output = vx_translate::e_translation_from_session_name;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_translation_from_session_name::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_translate::Func_translation_from_session_name output = vx_translate::e_translation_from_session_name;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_translation_from_session_name::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/translate", // pkgname
        "translation<-session-name", // name
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

    vx_core::Type_constdef Class_translation_from_session_name::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_translation_from_session_name::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/translate", // pkgname
        "translation<-session-name", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_translation_from_session_name::vx_empty() const {return vx_translate::e_translation_from_session_name;}
    vx_core::Type_any Class_translation_from_session_name::vx_type() const {return vx_translate::t_translation_from_session_name;}
    vx_core::Type_msgblock Class_translation_from_session_name::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_translation_from_session_name::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_translation_from_session_name::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_session session = vx_core::vx_any_from_any(vx_core::t_session, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string name = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_translate::f_translation_from_session_name(session, name);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func translationmap<-translations)
  vx_core::Type_translationmap f_translationmap_from_translations(vx_core::Type_translationlist translations) {
    vx_core::Type_translationmap output = vx_core::e_translationmap;
    vx_core::vx_reserve(translations);
    output = vx_core::f_map_from_list(
      vx_core::t_translationmap,
      translations,
      vx_core::t_any_from_any->vx_fn_new({}, [](vx_core::Type_any translation_any) {
        vx_core::Type_translation translation = vx_core::vx_any_from_any(vx_core::t_translation, translation_any);
        vx_core::Type_any output_1 = 
          translation->name();
        return output_1;
      })
    );
    vx_core::vx_release_one_except(translations, output);
    return output;
  }

  // (func translationmap<-translations)
  // class Class_translationmap_from_translations {
    Abstract_translationmap_from_translations::~Abstract_translationmap_from_translations() {}

    Class_translationmap_from_translations::Class_translationmap_from_translations() : Abstract_translationmap_from_translations::Abstract_translationmap_from_translations() {
      vx_core::refcount += 1;
    }

    Class_translationmap_from_translations::~Class_translationmap_from_translations() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_translationmap_from_translations::vx_new(vx_core::vx_Type_listany vals) const {
      vx_translate::Func_translationmap_from_translations output = vx_translate::e_translationmap_from_translations;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_translationmap_from_translations::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_translate::Func_translationmap_from_translations output = vx_translate::e_translationmap_from_translations;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_translationmap_from_translations::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/translate", // pkgname
        "translationmap<-translations", // name
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

    vx_core::Type_constdef Class_translationmap_from_translations::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_translationmap_from_translations::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/translate", // pkgname
        "translationmap<-translations", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_translationmap_from_translations::vx_empty() const {return vx_translate::e_translationmap_from_translations;}
    vx_core::Type_any Class_translationmap_from_translations::vx_type() const {return vx_translate::t_translationmap_from_translations;}
    vx_core::Type_msgblock Class_translationmap_from_translations::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_translationmap_from_translations::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_translationmap_from_translations::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_translationmap_from_translations::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_translationlist inputval = vx_core::vx_any_from_any(vx_core::t_translationlist, val);
      output = vx_translate::f_translationmap_from_translations(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_translationmap_from_translations::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_translationlist translations = vx_core::vx_any_from_any(vx_core::t_translationlist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_translate::f_translationmap_from_translations(translations);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_translate::Func_session_from_session_name e_session_from_session_name = NULL;
  vx_translate::Func_session_from_session_name t_session_from_session_name = NULL;
  vx_translate::Func_session_from_session_translation e_session_from_session_translation = NULL;
  vx_translate::Func_session_from_session_translation t_session_from_session_translation = NULL;
  vx_translate::Func_session_from_session_translationmap_name e_session_from_session_translationmap_name = NULL;
  vx_translate::Func_session_from_session_translationmap_name t_session_from_session_translationmap_name = NULL;
  vx_translate::Func_translate e_translate = NULL;
  vx_translate::Func_translate t_translate = NULL;
  vx_translate::Func_translate_from_translation_string e_translate_from_translation_string = NULL;
  vx_translate::Func_translate_from_translation_string t_translate_from_translation_string = NULL;
  vx_translate::Func_translate_from_translationmap_name_string e_translate_from_translationmap_name_string = NULL;
  vx_translate::Func_translate_from_translationmap_name_string t_translate_from_translationmap_name_string = NULL;
  vx_translate::Func_translation_load_session e_translation_load_session = NULL;
  vx_translate::Func_translation_load_session t_translation_load_session = NULL;
  vx_translate::Func_translation_from_context e_translation_from_context = NULL;
  vx_translate::Func_translation_from_context t_translation_from_context = NULL;
  vx_translate::Func_translation_from_session_name e_translation_from_session_name = NULL;
  vx_translate::Func_translation_from_session_name t_translation_from_session_name = NULL;
  vx_translate::Func_translationmap_from_translations e_translationmap_from_translations = NULL;
  vx_translate::Func_translationmap_from_translations t_translationmap_from_translations = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_translate::e_session_from_session_name = new vx_translate::Class_session_from_session_name();
      vx_core::vx_reserve_empty(vx_translate::e_session_from_session_name);
      vx_translate::t_session_from_session_name = new vx_translate::Class_session_from_session_name();
      vx_core::vx_reserve_type(vx_translate::t_session_from_session_name);
      vx_translate::e_session_from_session_translation = new vx_translate::Class_session_from_session_translation();
      vx_core::vx_reserve_empty(vx_translate::e_session_from_session_translation);
      vx_translate::t_session_from_session_translation = new vx_translate::Class_session_from_session_translation();
      vx_core::vx_reserve_type(vx_translate::t_session_from_session_translation);
      vx_translate::e_session_from_session_translationmap_name = new vx_translate::Class_session_from_session_translationmap_name();
      vx_core::vx_reserve_empty(vx_translate::e_session_from_session_translationmap_name);
      vx_translate::t_session_from_session_translationmap_name = new vx_translate::Class_session_from_session_translationmap_name();
      vx_core::vx_reserve_type(vx_translate::t_session_from_session_translationmap_name);
      vx_translate::e_translate = new vx_translate::Class_translate();
      vx_core::vx_reserve_empty(vx_translate::e_translate);
      vx_translate::t_translate = new vx_translate::Class_translate();
      vx_core::vx_reserve_type(vx_translate::t_translate);
      vx_translate::e_translate_from_translation_string = new vx_translate::Class_translate_from_translation_string();
      vx_core::vx_reserve_empty(vx_translate::e_translate_from_translation_string);
      vx_translate::t_translate_from_translation_string = new vx_translate::Class_translate_from_translation_string();
      vx_core::vx_reserve_type(vx_translate::t_translate_from_translation_string);
      vx_translate::e_translate_from_translationmap_name_string = new vx_translate::Class_translate_from_translationmap_name_string();
      vx_core::vx_reserve_empty(vx_translate::e_translate_from_translationmap_name_string);
      vx_translate::t_translate_from_translationmap_name_string = new vx_translate::Class_translate_from_translationmap_name_string();
      vx_core::vx_reserve_type(vx_translate::t_translate_from_translationmap_name_string);
      vx_translate::e_translation_load_session = new vx_translate::Class_translation_load_session();
      vx_core::vx_reserve_empty(vx_translate::e_translation_load_session);
      vx_translate::t_translation_load_session = new vx_translate::Class_translation_load_session();
      vx_core::vx_reserve_type(vx_translate::t_translation_load_session);
      vx_translate::e_translation_from_context = new vx_translate::Class_translation_from_context();
      vx_core::vx_reserve_empty(vx_translate::e_translation_from_context);
      vx_translate::t_translation_from_context = new vx_translate::Class_translation_from_context();
      vx_core::vx_reserve_type(vx_translate::t_translation_from_context);
      vx_translate::e_translation_from_session_name = new vx_translate::Class_translation_from_session_name();
      vx_core::vx_reserve_empty(vx_translate::e_translation_from_session_name);
      vx_translate::t_translation_from_session_name = new vx_translate::Class_translation_from_session_name();
      vx_core::vx_reserve_type(vx_translate::t_translation_from_session_name);
      vx_translate::e_translationmap_from_translations = new vx_translate::Class_translationmap_from_translations();
      vx_core::vx_reserve_empty(vx_translate::e_translationmap_from_translations);
      vx_translate::t_translationmap_from_translations = new vx_translate::Class_translationmap_from_translations();
      vx_core::vx_reserve_type(vx_translate::t_translationmap_from_translations);
      vx_core::vx_Type_mapany maptype;
      vx_core::vx_Type_mapany mapconst;
      vx_core::vx_Type_mapfunc mapfunc;
      vx_core::vx_Type_mapany mapempty;
      mapfunc["session<-session-name"] = vx_translate::t_session_from_session_name;
      mapfunc["session<-session-translation"] = vx_translate::t_session_from_session_translation;
      mapfunc["session<-session-translationmap-name"] = vx_translate::t_session_from_session_translationmap_name;
      mapfunc["translate"] = vx_translate::t_translate;
      mapfunc["translate<-translation-string"] = vx_translate::t_translate_from_translation_string;
      mapfunc["translate<-translationmap-name-string"] = vx_translate::t_translate_from_translationmap_name_string;
      mapfunc["translation-load-session"] = vx_translate::t_translation_load_session;
      mapfunc["translation<-context"] = vx_translate::t_translation_from_context;
      mapfunc["translation<-session-name"] = vx_translate::t_translation_from_session_name;
      mapfunc["translationmap<-translations"] = vx_translate::t_translationmap_from_translations;
      vx_core::vx_global_package_set("vx/translate", maptype, mapconst, mapfunc);
	   }
  // }

}
