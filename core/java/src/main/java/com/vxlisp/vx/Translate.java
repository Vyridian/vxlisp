package com.vxlisp.vx;

import java.util.LinkedHashMap;
import java.util.Map;
import com.vxlisp.vx.data.*;

public final class Translate {

  /**
   * @function session_from_session_name
   * Returns an updated session with a translationmap and a translation name.
   * @param  {session} session
   * @param  {string} name
   * @return {session}
   * (func session<-session-name)
   */
  public interface Func_session_from_session_name extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_session vx_session_from_session_name(final Core.Type_session session, final Core.Type_string name);
  }

  public static class Class_session_from_session_name extends Core.Class_base implements Func_session_from_session_name {

    @Override
    public Translate.Func_session_from_session_name vx_new(final Object... vals) {
      Class_session_from_session_name output = new Class_session_from_session_name();
      return output;
    }

    @Override
    public Translate.Func_session_from_session_name vx_copy(final Object... vals) {
      Class_session_from_session_name output = new Class_session_from_session_name();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/translate", // pkgname
        "session<-session-name", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "session", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_session_from_session_name;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_session_from_session_name;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_session session = Core.f_any_from_any(Core.t_session, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string name = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Translate.f_session_from_session_name(session, name);
      return output;
    }

    @Override
    public Core.Type_session vx_session_from_session_name(final Core.Type_session session, final Core.Type_string name) {
      return Translate.f_session_from_session_name(session, name);
    }

  }

  public static final Func_session_from_session_name e_session_from_session_name = new Translate.Class_session_from_session_name();
  public static final Func_session_from_session_name t_session_from_session_name = new Translate.Class_session_from_session_name();

  public static Core.Type_session f_session_from_session_name(final Core.Type_session session, final Core.Type_string name) {
    Core.Type_session output = Core.e_session;
    output = Core.f_copy(
      session,
      Core.vx_new(Core.t_anylist,
        Core.vx_new_string(":translation"),
        Translate.f_translation_from_session_name(session, name)
      )
    );
    return output;
  }

  /**
   * @function session_from_session_translation
   * Returns an updated session with a translation.
   * @param  {session} session
   * @param  {translation} translation
   * @return {session}
   * (func session<-session-translation)
   */
  public interface Func_session_from_session_translation extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_session vx_session_from_session_translation(final Core.Type_session session, final Core.Type_translation translation);
  }

  public static class Class_session_from_session_translation extends Core.Class_base implements Func_session_from_session_translation {

    @Override
    public Translate.Func_session_from_session_translation vx_new(final Object... vals) {
      Class_session_from_session_translation output = new Class_session_from_session_translation();
      return output;
    }

    @Override
    public Translate.Func_session_from_session_translation vx_copy(final Object... vals) {
      Class_session_from_session_translation output = new Class_session_from_session_translation();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/translate", // pkgname
        "session<-session-translation", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "session", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_session_from_session_translation;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_session_from_session_translation;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_session session = Core.f_any_from_any(Core.t_session, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_translation translation = Core.f_any_from_any(Core.t_translation, arglist.vx_any(Core.vx_new_int(1)));
      output = Translate.f_session_from_session_translation(session, translation);
      return output;
    }

    @Override
    public Core.Type_session vx_session_from_session_translation(final Core.Type_session session, final Core.Type_translation translation) {
      return Translate.f_session_from_session_translation(session, translation);
    }

  }

  public static final Func_session_from_session_translation e_session_from_session_translation = new Translate.Class_session_from_session_translation();
  public static final Func_session_from_session_translation t_session_from_session_translation = new Translate.Class_session_from_session_translation();

  public static Core.Type_session f_session_from_session_translation(final Core.Type_session session, final Core.Type_translation translation) {
    Core.Type_session output = Core.e_session;
    output = Core.f_copy(
      session,
      Core.vx_new(Core.t_anylist,
        Core.vx_new_string(":translation"),
        translation
      )
    );
    return output;
  }

  /**
   * @function session_from_session_translationmap_name
   * Returns an updated session with a translationmap and a translation name.
   * @param  {session} session
   * @param  {translationmap} translationmap
   * @param  {string} name
   * @return {session}
   * (func session<-session-translationmap-name)
   */
  public interface Func_session_from_session_translationmap_name extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_session vx_session_from_session_translationmap_name(final Core.Type_session session, final Core.Type_translationmap translationmap, final Core.Type_string name);
  }

  public static class Class_session_from_session_translationmap_name extends Core.Class_base implements Func_session_from_session_translationmap_name {

    @Override
    public Translate.Func_session_from_session_translationmap_name vx_new(final Object... vals) {
      Class_session_from_session_translationmap_name output = new Class_session_from_session_translationmap_name();
      return output;
    }

    @Override
    public Translate.Func_session_from_session_translationmap_name vx_copy(final Object... vals) {
      Class_session_from_session_translationmap_name output = new Class_session_from_session_translationmap_name();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/translate", // pkgname
        "session<-session-translationmap-name", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "session", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_session_from_session_translationmap_name;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_session_from_session_translationmap_name;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_session session = Core.f_any_from_any(Core.t_session, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_translationmap translationmap = Core.f_any_from_any(Core.t_translationmap, arglist.vx_any(Core.vx_new_int(1)));
      Core.Type_string name = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(2)));
      output = Translate.f_session_from_session_translationmap_name(session, translationmap, name);
      return output;
    }

    @Override
    public Core.Type_session vx_session_from_session_translationmap_name(final Core.Type_session session, final Core.Type_translationmap translationmap, final Core.Type_string name) {
      return Translate.f_session_from_session_translationmap_name(session, translationmap, name);
    }

  }

  public static final Func_session_from_session_translationmap_name e_session_from_session_translationmap_name = new Translate.Class_session_from_session_translationmap_name();
  public static final Func_session_from_session_translationmap_name t_session_from_session_translationmap_name = new Translate.Class_session_from_session_translationmap_name();

  public static Core.Type_session f_session_from_session_translationmap_name(final Core.Type_session session, final Core.Type_translationmap translationmap, final Core.Type_string name) {
    Core.Type_session output = Core.e_session;
    output = Core.f_copy(
      session,
      Core.vx_new(Core.t_anylist,
        Core.vx_new_string(":translation"),
        Core.f_any_from_map(Core.t_anylist, translationmap, name),
        Core.vx_new_string(":translationmap"),
        translationmap
      )
    );
    return output;
  }

  /**
   * @function translate
   * Returns a translated string from current context.
   * @param  {string} text
   * @return {string}
   * (func translate)
   */
  public interface Func_translate extends Core.Func_any_from_any_context {
    public Core.Type_string vx_translate(final Core.Type_context context, final Core.Type_string text);
  }

  public static class Class_translate extends Core.Class_base implements Func_translate {

    @Override
    public Translate.Func_translate vx_new(final Object... vals) {
      Class_translate output = new Class_translate();
      return output;
    }

    @Override
    public Translate.Func_translate vx_copy(final Object... vals) {
      Class_translate output = new Class_translate();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/translate", // pkgname
        "translate", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_translate;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_translate;
    }

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {
      return Core.e_any_from_any_context;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Translate.f_translate(context, inputval);
      output = Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Translate.f_translate(context, text);
      return output;
    }

    @Override
    public Core.Type_string vx_translate(final Core.Type_context context, final Core.Type_string text) {
      return Translate.f_translate(context, text);
    }

  }

  public static final Func_translate e_translate = new Translate.Class_translate();
  public static final Func_translate t_translate = new Translate.Class_translate();

  public static Core.Type_string f_translate(final Core.Type_context context, final Core.Type_string text) {
    Core.Type_string output = Core.e_string;
    output = Translate.f_translate_from_translation_string(
      Translate.f_translation_from_context(context),
      text
    );
    return output;
  }

  /**
   * @function translate 1
   * Returns a translated string from a msg.
   * @param  {msg} msg
   * @return {string}
   * (func translate)
   */
  public interface Func_translate_1 extends Core.Func_any_from_any_context {
    public Core.Type_string vx_translate_1(final Core.Type_context context, final Core.Type_msg msg);
  }

  public static class Class_translate_1 extends Core.Class_base implements Func_translate_1 {

    @Override
    public Translate.Func_translate_1 vx_new(final Object... vals) {
      Class_translate_1 output = new Class_translate_1();
      return output;
    }

    @Override
    public Translate.Func_translate_1 vx_copy(final Object... vals) {
      Class_translate_1 output = new Class_translate_1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/translate", // pkgname
        "translate", // name
        1, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_translate_1;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_translate_1;
    }

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {
      return Core.e_any_from_any_context;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_msg inputval = (Core.Type_msg)value;
      Core.Type_any outputval = Translate.f_translate_1(context, inputval);
      output = Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_msg msg = Core.f_any_from_any(Core.t_msg, arglist.vx_any(Core.vx_new_int(0)));
      output = Translate.f_translate_1(context, msg);
      return output;
    }

    @Override
    public Core.Type_string vx_translate_1(final Core.Type_context context, final Core.Type_msg msg) {
      return Translate.f_translate_1(context, msg);
    }

  }

  public static final Func_translate_1 e_translate_1 = new Translate.Class_translate_1();
  public static final Func_translate_1 t_translate_1 = new Translate.Class_translate_1();

  public static Core.Type_string f_translate_1(final Core.Type_context context, final Core.Type_msg msg) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_string path = msg.path();
        final Core.Type_string code = msg.code();
        final Core.Type_string text = Core.f_new(
          Core.t_string,
          Core.vx_new(Core.t_anylist,
              Core.vx_new_string("!"),
              path,
              Core.vx_new_string(" "),
              code
          )
        );
        return Translate.f_translate(context, text);
      })
    );
    return output;
  }

  /**
   * @function translate_from_translation_string
   * Returns a translated string from a translation or the original text if not found.
   * @param  {translation} translation
   * @param  {string} text
   * @return {string}
   * (func translate<-translation-string)
   */
  public interface Func_translate_from_translation_string extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_translate_from_translation_string(final Core.Type_translation translation, final Core.Type_string text);
  }

  public static class Class_translate_from_translation_string extends Core.Class_base implements Func_translate_from_translation_string {

    @Override
    public Translate.Func_translate_from_translation_string vx_new(final Object... vals) {
      Class_translate_from_translation_string output = new Class_translate_from_translation_string();
      return output;
    }

    @Override
    public Translate.Func_translate_from_translation_string vx_copy(final Object... vals) {
      Class_translate_from_translation_string output = new Class_translate_from_translation_string();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/translate", // pkgname
        "translate<-translation-string", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_translate_from_translation_string;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_translate_from_translation_string;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_translation translation = Core.f_any_from_any(Core.t_translation, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Translate.f_translate_from_translation_string(translation, text);
      return output;
    }

    @Override
    public Core.Type_string vx_translate_from_translation_string(final Core.Type_translation translation, final Core.Type_string text) {
      return Translate.f_translate_from_translation_string(translation, text);
    }

  }

  public static final Func_translate_from_translation_string e_translate_from_translation_string = new Translate.Class_translate_from_translation_string();
  public static final Func_translate_from_translation_string t_translate_from_translation_string = new Translate.Class_translate_from_translation_string();

  public static Core.Type_string f_translate_from_translation_string(final Core.Type_translation translation, final Core.Type_string text) {
    Core.Type_string output = Core.e_string;
    output = Core.f_if_1(
      Core.t_string,
      Core.f_is_empty_1(translation),
      text,
      Core.f_let(
        Core.t_string,
        Core.t_any_from_func.vx_fn_new(() -> {
          final Core.Type_stringmap wordmap = translation.wordmap();
          final Core.Type_string xlate = Core.f_any_from_map(Core.t_string, wordmap, text);
          return Core.f_if_1(
            Core.t_string,
            Core.f_is_empty(xlate),
            text,
            xlate
          );
        })
      )
    );
    return output;
  }

  /**
   * @function translate_from_translationmap_name_string
   * Returns a translated string from a translation map given a translation name and text.
   * @param  {translationmap} translationmap
   * @param  {string} name
   * @param  {string} text
   * @return {string}
   * (func translate<-translationmap-name-string)
   */
  public interface Func_translate_from_translationmap_name_string extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_translate_from_translationmap_name_string(final Core.Type_translationmap translationmap, final Core.Type_string name, final Core.Type_string text);
  }

  public static class Class_translate_from_translationmap_name_string extends Core.Class_base implements Func_translate_from_translationmap_name_string {

    @Override
    public Translate.Func_translate_from_translationmap_name_string vx_new(final Object... vals) {
      Class_translate_from_translationmap_name_string output = new Class_translate_from_translationmap_name_string();
      return output;
    }

    @Override
    public Translate.Func_translate_from_translationmap_name_string vx_copy(final Object... vals) {
      Class_translate_from_translationmap_name_string output = new Class_translate_from_translationmap_name_string();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/translate", // pkgname
        "translate<-translationmap-name-string", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_translate_from_translationmap_name_string;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_translate_from_translationmap_name_string;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_translationmap translationmap = Core.f_any_from_any(Core.t_translationmap, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string name = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(2)));
      output = Translate.f_translate_from_translationmap_name_string(translationmap, name, text);
      return output;
    }

    @Override
    public Core.Type_string vx_translate_from_translationmap_name_string(final Core.Type_translationmap translationmap, final Core.Type_string name, final Core.Type_string text) {
      return Translate.f_translate_from_translationmap_name_string(translationmap, name, text);
    }

  }

  public static final Func_translate_from_translationmap_name_string e_translate_from_translationmap_name_string = new Translate.Class_translate_from_translationmap_name_string();
  public static final Func_translate_from_translationmap_name_string t_translate_from_translationmap_name_string = new Translate.Class_translate_from_translationmap_name_string();

  public static Core.Type_string f_translate_from_translationmap_name_string(final Core.Type_translationmap translationmap, final Core.Type_string name, final Core.Type_string text) {
    Core.Type_string output = Core.e_string;
    output = Core.f_let(
      Core.t_string,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_translation translation = Core.f_any_from_map(Core.t_translation, translationmap, name);
        return Translate.f_translate_from_translation_string(translation, text);
      })
    );
    return output;
  }

  /**
   * @function translation_load_session
   * Returns a translation from the translation folder.
   * @param  {translation} translation
   * @return {translation}
   * (func translation-load-session)
   */
  public interface Func_translation_load_session extends Core.Func_any_from_any_context {
    public Core.Type_translation vx_translation_load_session(final Core.Type_context context, final Core.Type_translation translation);
  }

  public static class Class_translation_load_session extends Core.Class_base implements Func_translation_load_session {

    @Override
    public Translate.Func_translation_load_session vx_new(final Object... vals) {
      Class_translation_load_session output = new Class_translation_load_session();
      return output;
    }

    @Override
    public Translate.Func_translation_load_session vx_copy(final Object... vals) {
      Class_translation_load_session output = new Class_translation_load_session();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/translate", // pkgname
        "translation-load-session", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "translation", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_translation_load_session;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_translation_load_session;
    }

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {
      return Core.e_any_from_any_context;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_translation inputval = (Core.Type_translation)value;
      Core.Type_any outputval = Translate.f_translation_load_session(context, inputval);
      output = Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_translation translation = Core.f_any_from_any(Core.t_translation, arglist.vx_any(Core.vx_new_int(0)));
      output = Translate.f_translation_load_session(context, translation);
      return output;
    }

    @Override
    public Core.Type_translation vx_translation_load_session(final Core.Type_context context, final Core.Type_translation translation) {
      return Translate.f_translation_load_session(context, translation);
    }

  }

  public static final Func_translation_load_session e_translation_load_session = new Translate.Class_translation_load_session();
  public static final Func_translation_load_session t_translation_load_session = new Translate.Class_translation_load_session();

  public static Core.Type_translation f_translation_load_session(final Core.Type_context context, final Core.Type_translation translation) {
    Core.Type_translation output = Core.e_translation;
    return output;
  }

  /**
   * @function translation_from_context
   * Returns a translated string from current context.
   * @return {translation}
   * (func translation<-context)
   */
  public interface Func_translation_from_context extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_translation vx_translation_from_context(final Core.Type_context context);
  }

  public static class Class_translation_from_context extends Core.Class_base implements Func_translation_from_context {

    @Override
    public Translate.Func_translation_from_context vx_new(final Object... vals) {
      Class_translation_from_context output = new Class_translation_from_context();
      return output;
    }

    @Override
    public Translate.Func_translation_from_context vx_copy(final Object... vals) {
      Class_translation_from_context output = new Class_translation_from_context();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/translate", // pkgname
        "translation<-context", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "translation", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_translation_from_context;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_translation_from_context;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      output = Translate.f_translation_from_context(context);
      return output;
    }

    @Override
    public Core.Type_translation vx_translation_from_context(final Core.Type_context context) {
      return Translate.f_translation_from_context(context);
    }

  }

  public static final Func_translation_from_context e_translation_from_context = new Translate.Class_translation_from_context();
  public static final Func_translation_from_context t_translation_from_context = new Translate.Class_translation_from_context();

  public static Core.Type_translation f_translation_from_context(final Core.Type_context context) {
    Core.Type_translation output = Core.e_translation;
    output = Core.f_session_from_context(context).translation();
    return output;
  }

  /**
   * @function translation_from_session_name
   * Returns a translation from a session by name.
   * @param  {session} session
   * @param  {string} name
   * @return {translation}
   * (func translation<-session-name)
   */
  public interface Func_translation_from_session_name extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_translation vx_translation_from_session_name(final Core.Type_session session, final Core.Type_string name);
  }

  public static class Class_translation_from_session_name extends Core.Class_base implements Func_translation_from_session_name {

    @Override
    public Translate.Func_translation_from_session_name vx_new(final Object... vals) {
      Class_translation_from_session_name output = new Class_translation_from_session_name();
      return output;
    }

    @Override
    public Translate.Func_translation_from_session_name vx_copy(final Object... vals) {
      Class_translation_from_session_name output = new Class_translation_from_session_name();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/translate", // pkgname
        "translation<-session-name", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "translation", // name
          ":struct", // extends
          Core.e_typelist, // traits
          Core.e_typelist, // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_translation_from_session_name;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_translation_from_session_name;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_session session = Core.f_any_from_any(Core.t_session, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string name = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Translate.f_translation_from_session_name(session, name);
      return output;
    }

    @Override
    public Core.Type_translation vx_translation_from_session_name(final Core.Type_session session, final Core.Type_string name) {
      return Translate.f_translation_from_session_name(session, name);
    }

  }

  public static final Func_translation_from_session_name e_translation_from_session_name = new Translate.Class_translation_from_session_name();
  public static final Func_translation_from_session_name t_translation_from_session_name = new Translate.Class_translation_from_session_name();

  public static Core.Type_translation f_translation_from_session_name(final Core.Type_session session, final Core.Type_string name) {
    Core.Type_translation output = Core.e_translation;
    output = Core.f_let(
      Core.t_translation,
      Core.t_any_from_func.vx_fn_new(() -> {
        final Core.Type_translationmap translationmap = session.translationmap();
        return Core.f_any_from_map(Core.t_translation, translationmap, name);
      })
    );
    return output;
  }

  /**
   * @function translationmap_from_translations
   * Returns a translationmap from one or more translations.
   * @param  {translationlist} translations
   * @return {translationmap}
   * (func translationmap<-translations)
   */
  public interface Func_translationmap_from_translations extends Core.Func_any_from_any {
    public Core.Type_translationmap vx_translationmap_from_translations(final Core.Type_translationlist translations);
  }

  public static class Class_translationmap_from_translations extends Core.Class_base implements Func_translationmap_from_translations {

    @Override
    public Translate.Func_translationmap_from_translations vx_new(final Object... vals) {
      Class_translationmap_from_translations output = new Class_translationmap_from_translations();
      return output;
    }

    @Override
    public Translate.Func_translationmap_from_translations vx_copy(final Object... vals) {
      Class_translationmap_from_translations output = new Class_translationmap_from_translations();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {
      return Core.t_func.vx_typedef();
    }

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/translate", // pkgname
        "translationmap<-translations", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "translationmap", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.vx_new(Core.t_typelist, Core.t_translation), // allowtypes
          Core.e_typelist, // disallowtypes
          Core.e_funclist, // allowfuncs
          Core.e_funclist, // disallowfuncs
          Core.e_anylist, // allowvalues
          Core.e_anylist, // disallowvalues
          Core.e_argmap // properties
        ) // typedef
      );
    }

    @Override
    public Core.Type_any vx_empty() {
      return e_translationmap_from_translations;
    }

    @Override
    public Core.Type_any vx_type() {
      return t_translationmap_from_translations;
    }

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {
      return Core.e_any_from_any;
    }

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_translationlist inputval = (Core.Type_translationlist)value;
      Core.Type_any outputval = Translate.f_translationmap_from_translations(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_translationlist translations = Core.f_any_from_any(Core.t_translationlist, arglist.vx_any(Core.vx_new_int(0)));
      output = Translate.f_translationmap_from_translations(translations);
      return output;
    }

    @Override
    public Core.Type_translationmap vx_translationmap_from_translations(final Core.Type_translationlist translations) {
      return Translate.f_translationmap_from_translations(translations);
    }

  }

  public static final Func_translationmap_from_translations e_translationmap_from_translations = new Translate.Class_translationmap_from_translations();
  public static final Func_translationmap_from_translations t_translationmap_from_translations = new Translate.Class_translationmap_from_translations();

  public static Core.Type_translationmap f_translationmap_from_translations(final Core.Type_translationlist translations) {
    Core.Type_translationmap output = Core.e_translationmap;
    output = Core.f_map_from_list(
      Core.t_translationmap,
      translations,
      Core.t_any_from_any.vx_fn_new((translation_any) -> {
        Core.Type_translation translation = Core.f_any_from_any(Core.t_translation, translation_any);
        return 
        translation.name();
      })
    );
    return output;
  }


  static {
    Map<String, Core.Type_any> maptype = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<String, Core.Type_any>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<String, Core.Type_func>();
    mapfunc.put("session<-session-name", Translate.t_session_from_session_name);
    mapfunc.put("session<-session-translation", Translate.t_session_from_session_translation);
    mapfunc.put("session<-session-translationmap-name", Translate.t_session_from_session_translationmap_name);
    mapfunc.put("translate", Translate.t_translate);
    mapfunc.put("translate_1", Translate.t_translate_1);
    mapfunc.put("translate<-translation-string", Translate.t_translate_from_translation_string);
    mapfunc.put("translate<-translationmap-name-string", Translate.t_translate_from_translationmap_name_string);
    mapfunc.put("translation-load-session", Translate.t_translation_load_session);
    mapfunc.put("translation<-context", Translate.t_translation_from_context);
    mapfunc.put("translation<-session-name", Translate.t_translation_from_session_name);
    mapfunc.put("translationmap<-translations", Translate.t_translationmap_from_translations);
    Core.vx_global_package_set("vx/translate", maptype, mapconst, mapfunc);
  }

}
