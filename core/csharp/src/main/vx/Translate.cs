namespace Vx;

using Vx;

public static class Vx_translate {

  /**
   * @function session_from_session_name
   * Returns an updated session with a translationmap and a translation name.
   * @param  {session} session
   * @param  {string} name
   * @return {session}
   * (func session<-session-name)
   */
  public interface Func_session_from_session_name : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_core.Type_session vx_session_from_session_name(Vx_core.Type_session session, Vx_core.Type_string name);
  }

  public class Class_session_from_session_name : Vx_core.Class_base, Func_session_from_session_name {

    public override Vx_translate.Func_session_from_session_name vx_new(params Object[] vals) {
      Class_session_from_session_name output = new Class_session_from_session_name();
      return output;
    }

    public override Vx_translate.Func_session_from_session_name vx_copy(params Object[] vals) {
      Class_session_from_session_name output = new Class_session_from_session_name();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/translate", // pkgname
        "session<-session-name", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "session", // name
          ":struct", // extends
          Vx_core.e_typelist, // traits
          Vx_core.e_typelist, // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx_core.Type_any vx_empty() {
      return e_session_from_session_name;
    }

    public override Vx_core.Type_any vx_type() {
      return t_session_from_session_name;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_session session = Vx_core.f_any_from_any(Vx_core.t_session, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_string name = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(1)));
      output = Vx_translate.f_session_from_session_name(session, name);
      return output;
    }

    public Vx_core.Type_session vx_session_from_session_name(Vx_core.Type_session session, Vx_core.Type_string name) {
      return Vx_translate.f_session_from_session_name(session, name);
    }

  }

  public static Func_session_from_session_name e_session_from_session_name = new Vx_translate.Class_session_from_session_name();
  public static Func_session_from_session_name t_session_from_session_name = new Vx_translate.Class_session_from_session_name();

  public static Vx_core.Type_session f_session_from_session_name(Vx_core.Type_session session, Vx_core.Type_string name) {
    Vx_core.Type_session output = Vx_core.e_session;
    output = Vx_core.f_copy(
      session,
      Vx_core.vx_new(Vx_core.t_anylist,
        Vx_core.vx_new_string(":translation"),
        Vx_translate.f_translation_from_session_name(session, name)
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
  public interface Func_session_from_session_translation : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_core.Type_session vx_session_from_session_translation(Vx_core.Type_session session, Vx_core.Type_translation translation);
  }

  public class Class_session_from_session_translation : Vx_core.Class_base, Func_session_from_session_translation {

    public override Vx_translate.Func_session_from_session_translation vx_new(params Object[] vals) {
      Class_session_from_session_translation output = new Class_session_from_session_translation();
      return output;
    }

    public override Vx_translate.Func_session_from_session_translation vx_copy(params Object[] vals) {
      Class_session_from_session_translation output = new Class_session_from_session_translation();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/translate", // pkgname
        "session<-session-translation", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "session", // name
          ":struct", // extends
          Vx_core.e_typelist, // traits
          Vx_core.e_typelist, // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx_core.Type_any vx_empty() {
      return e_session_from_session_translation;
    }

    public override Vx_core.Type_any vx_type() {
      return t_session_from_session_translation;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_session session = Vx_core.f_any_from_any(Vx_core.t_session, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_translation translation = Vx_core.f_any_from_any(Vx_core.t_translation, arglist.vx_any(Vx_core.vx_new_int(1)));
      output = Vx_translate.f_session_from_session_translation(session, translation);
      return output;
    }

    public Vx_core.Type_session vx_session_from_session_translation(Vx_core.Type_session session, Vx_core.Type_translation translation) {
      return Vx_translate.f_session_from_session_translation(session, translation);
    }

  }

  public static Func_session_from_session_translation e_session_from_session_translation = new Vx_translate.Class_session_from_session_translation();
  public static Func_session_from_session_translation t_session_from_session_translation = new Vx_translate.Class_session_from_session_translation();

  public static Vx_core.Type_session f_session_from_session_translation(Vx_core.Type_session session, Vx_core.Type_translation translation) {
    Vx_core.Type_session output = Vx_core.e_session;
    output = Vx_core.f_copy(
      session,
      Vx_core.vx_new(Vx_core.t_anylist,
        Vx_core.vx_new_string(":translation"),
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
  public interface Func_session_from_session_translationmap_name : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_core.Type_session vx_session_from_session_translationmap_name(Vx_core.Type_session session, Vx_core.Type_translationmap translationmap, Vx_core.Type_string name);
  }

  public class Class_session_from_session_translationmap_name : Vx_core.Class_base, Func_session_from_session_translationmap_name {

    public override Vx_translate.Func_session_from_session_translationmap_name vx_new(params Object[] vals) {
      Class_session_from_session_translationmap_name output = new Class_session_from_session_translationmap_name();
      return output;
    }

    public override Vx_translate.Func_session_from_session_translationmap_name vx_copy(params Object[] vals) {
      Class_session_from_session_translationmap_name output = new Class_session_from_session_translationmap_name();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/translate", // pkgname
        "session<-session-translationmap-name", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "session", // name
          ":struct", // extends
          Vx_core.e_typelist, // traits
          Vx_core.e_typelist, // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx_core.Type_any vx_empty() {
      return e_session_from_session_translationmap_name;
    }

    public override Vx_core.Type_any vx_type() {
      return t_session_from_session_translationmap_name;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_session session = Vx_core.f_any_from_any(Vx_core.t_session, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_translationmap translationmap = Vx_core.f_any_from_any(Vx_core.t_translationmap, arglist.vx_any(Vx_core.vx_new_int(1)));
      Vx_core.Type_string name = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(2)));
      output = Vx_translate.f_session_from_session_translationmap_name(session, translationmap, name);
      return output;
    }

    public Vx_core.Type_session vx_session_from_session_translationmap_name(Vx_core.Type_session session, Vx_core.Type_translationmap translationmap, Vx_core.Type_string name) {
      return Vx_translate.f_session_from_session_translationmap_name(session, translationmap, name);
    }

  }

  public static Func_session_from_session_translationmap_name e_session_from_session_translationmap_name = new Vx_translate.Class_session_from_session_translationmap_name();
  public static Func_session_from_session_translationmap_name t_session_from_session_translationmap_name = new Vx_translate.Class_session_from_session_translationmap_name();

  public static Vx_core.Type_session f_session_from_session_translationmap_name(Vx_core.Type_session session, Vx_core.Type_translationmap translationmap, Vx_core.Type_string name) {
    Vx_core.Type_session output = Vx_core.e_session;
    output = Vx_core.f_copy(
      session,
      Vx_core.vx_new(Vx_core.t_anylist,
        Vx_core.vx_new_string(":translation"),
        Vx_core.f_any_from_map(Vx_core.t_anylist, translationmap, name),
        Vx_core.vx_new_string(":translationmap"),
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
  public interface Func_translate : Vx_core.Func_any_from_any_context {
    public Vx_core.Type_string vx_translate(Vx_core.Type_context context, Vx_core.Type_string text);
  }

  public class Class_translate : Vx_core.Class_base, Func_translate {

    public override Vx_translate.Func_translate vx_new(params Object[] vals) {
      Class_translate output = new Class_translate();
      return output;
    }

    public override Vx_translate.Func_translate vx_copy(params Object[] vals) {
      Class_translate output = new Class_translate();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/translate", // pkgname
        "translate", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Vx_core.e_typelist, // traits
          Vx_core.e_typelist, // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx_core.Type_any vx_empty() {
      return e_translate;
    }

    public override Vx_core.Type_any vx_type() {
      return t_translate;
    }

    public Vx_core.Func_any_from_any_context vx_fn_new(Vx_core.Class_any_from_any_context.IFn fn) {
      return Vx_core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx_core.Type_context context, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_core.Type_string inputval = (Vx_core.Type_string)value;
      Vx_core.Type_any outputval = Vx_translate.f_translate(context, inputval);
      output = Vx_core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_string text = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_translate.f_translate(context, text);
      return output;
    }

    public Vx_core.Type_string vx_translate(Vx_core.Type_context context, Vx_core.Type_string text) {
      return Vx_translate.f_translate(context, text);
    }

  }

  public static Func_translate e_translate = new Vx_translate.Class_translate();
  public static Func_translate t_translate = new Vx_translate.Class_translate();

  public static Vx_core.Type_string f_translate(Vx_core.Type_context context, Vx_core.Type_string text) {
    Vx_core.Type_string output = Vx_core.e_string;
    output = Vx_translate.f_translate_from_translation_string(
      Vx_translate.f_translation_from_context(context),
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
  public interface Func_translate_1 : Vx_core.Func_any_from_any_context {
    public Vx_core.Type_string vx_translate_1(Vx_core.Type_context context, Vx_core.Type_msg msg);
  }

  public class Class_translate_1 : Vx_core.Class_base, Func_translate_1 {

    public override Vx_translate.Func_translate_1 vx_new(params Object[] vals) {
      Class_translate_1 output = new Class_translate_1();
      return output;
    }

    public override Vx_translate.Func_translate_1 vx_copy(params Object[] vals) {
      Class_translate_1 output = new Class_translate_1();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/translate", // pkgname
        "translate", // name
        1, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Vx_core.e_typelist, // traits
          Vx_core.e_typelist, // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx_core.Type_any vx_empty() {
      return e_translate_1;
    }

    public override Vx_core.Type_any vx_type() {
      return t_translate_1;
    }

    public Vx_core.Func_any_from_any_context vx_fn_new(Vx_core.Class_any_from_any_context.IFn fn) {
      return Vx_core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx_core.Type_context context, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_core.Type_msg inputval = (Vx_core.Type_msg)value;
      Vx_core.Type_any outputval = Vx_translate.f_translate_1(context, inputval);
      output = Vx_core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_msg msg = Vx_core.f_any_from_any(Vx_core.t_msg, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_translate.f_translate_1(context, msg);
      return output;
    }

    public Vx_core.Type_string vx_translate_1(Vx_core.Type_context context, Vx_core.Type_msg msg) {
      return Vx_translate.f_translate_1(context, msg);
    }

  }

  public static Func_translate_1 e_translate_1 = new Vx_translate.Class_translate_1();
  public static Func_translate_1 t_translate_1 = new Vx_translate.Class_translate_1();

  public static Vx_core.Type_string f_translate_1(Vx_core.Type_context context, Vx_core.Type_msg msg) {
    Vx_core.Type_string output = Vx_core.e_string;
    output = Vx_core.f_let(
      Vx_core.t_string,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_core.Type_string path = msg.path();
        Vx_core.Type_string code = msg.code();
        Vx_core.Type_string text = Vx_core.f_new(
          Vx_core.t_string,
          Vx_core.vx_new(Vx_core.t_anylist,
              Vx_core.vx_new_string("!"),
              path,
              Vx_core.vx_new_string(" "),
              code
          )
        );
        return Vx_translate.f_translate(context, text);
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
  public interface Func_translate_from_translation_string : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_core.Type_string vx_translate_from_translation_string(Vx_core.Type_translation translation, Vx_core.Type_string text);
  }

  public class Class_translate_from_translation_string : Vx_core.Class_base, Func_translate_from_translation_string {

    public override Vx_translate.Func_translate_from_translation_string vx_new(params Object[] vals) {
      Class_translate_from_translation_string output = new Class_translate_from_translation_string();
      return output;
    }

    public override Vx_translate.Func_translate_from_translation_string vx_copy(params Object[] vals) {
      Class_translate_from_translation_string output = new Class_translate_from_translation_string();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/translate", // pkgname
        "translate<-translation-string", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Vx_core.e_typelist, // traits
          Vx_core.e_typelist, // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx_core.Type_any vx_empty() {
      return e_translate_from_translation_string;
    }

    public override Vx_core.Type_any vx_type() {
      return t_translate_from_translation_string;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_translation translation = Vx_core.f_any_from_any(Vx_core.t_translation, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_string text = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(1)));
      output = Vx_translate.f_translate_from_translation_string(translation, text);
      return output;
    }

    public Vx_core.Type_string vx_translate_from_translation_string(Vx_core.Type_translation translation, Vx_core.Type_string text) {
      return Vx_translate.f_translate_from_translation_string(translation, text);
    }

  }

  public static Func_translate_from_translation_string e_translate_from_translation_string = new Vx_translate.Class_translate_from_translation_string();
  public static Func_translate_from_translation_string t_translate_from_translation_string = new Vx_translate.Class_translate_from_translation_string();

  public static Vx_core.Type_string f_translate_from_translation_string(Vx_core.Type_translation translation, Vx_core.Type_string text) {
    Vx_core.Type_string output = Vx_core.e_string;
    output = Vx_core.f_if_1(
      Vx_core.t_string,
      Vx_core.f_is_empty_1(translation),
      text,
      Vx_core.f_let(
        Vx_core.t_string,
        Vx_core.t_any_from_func.vx_fn_new(() => {
          Vx_core.Type_stringmap wordmap = translation.wordmap();
          Vx_core.Type_string xlate = Vx_core.f_any_from_map(Vx_core.t_string, wordmap, text);
          return Vx_core.f_if_1(
            Vx_core.t_string,
            Vx_core.f_is_empty(xlate),
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
  public interface Func_translate_from_translationmap_name_string : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_core.Type_string vx_translate_from_translationmap_name_string(Vx_core.Type_translationmap translationmap, Vx_core.Type_string name, Vx_core.Type_string text);
  }

  public class Class_translate_from_translationmap_name_string : Vx_core.Class_base, Func_translate_from_translationmap_name_string {

    public override Vx_translate.Func_translate_from_translationmap_name_string vx_new(params Object[] vals) {
      Class_translate_from_translationmap_name_string output = new Class_translate_from_translationmap_name_string();
      return output;
    }

    public override Vx_translate.Func_translate_from_translationmap_name_string vx_copy(params Object[] vals) {
      Class_translate_from_translationmap_name_string output = new Class_translate_from_translationmap_name_string();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/translate", // pkgname
        "translate<-translationmap-name-string", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Vx_core.e_typelist, // traits
          Vx_core.e_typelist, // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx_core.Type_any vx_empty() {
      return e_translate_from_translationmap_name_string;
    }

    public override Vx_core.Type_any vx_type() {
      return t_translate_from_translationmap_name_string;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_translationmap translationmap = Vx_core.f_any_from_any(Vx_core.t_translationmap, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_string name = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(1)));
      Vx_core.Type_string text = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(2)));
      output = Vx_translate.f_translate_from_translationmap_name_string(translationmap, name, text);
      return output;
    }

    public Vx_core.Type_string vx_translate_from_translationmap_name_string(Vx_core.Type_translationmap translationmap, Vx_core.Type_string name, Vx_core.Type_string text) {
      return Vx_translate.f_translate_from_translationmap_name_string(translationmap, name, text);
    }

  }

  public static Func_translate_from_translationmap_name_string e_translate_from_translationmap_name_string = new Vx_translate.Class_translate_from_translationmap_name_string();
  public static Func_translate_from_translationmap_name_string t_translate_from_translationmap_name_string = new Vx_translate.Class_translate_from_translationmap_name_string();

  public static Vx_core.Type_string f_translate_from_translationmap_name_string(Vx_core.Type_translationmap translationmap, Vx_core.Type_string name, Vx_core.Type_string text) {
    Vx_core.Type_string output = Vx_core.e_string;
    output = Vx_core.f_let(
      Vx_core.t_string,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_core.Type_translation translation = Vx_core.f_any_from_map(Vx_core.t_translation, translationmap, name);
        return Vx_translate.f_translate_from_translation_string(translation, text);
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
  public interface Func_translation_load_session : Vx_core.Func_any_from_any_context {
    public Vx_core.Type_translation vx_translation_load_session(Vx_core.Type_context context, Vx_core.Type_translation translation);
  }

  public class Class_translation_load_session : Vx_core.Class_base, Func_translation_load_session {

    public override Vx_translate.Func_translation_load_session vx_new(params Object[] vals) {
      Class_translation_load_session output = new Class_translation_load_session();
      return output;
    }

    public override Vx_translate.Func_translation_load_session vx_copy(params Object[] vals) {
      Class_translation_load_session output = new Class_translation_load_session();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/translate", // pkgname
        "translation-load-session", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "translation", // name
          ":struct", // extends
          Vx_core.e_typelist, // traits
          Vx_core.e_typelist, // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx_core.Type_any vx_empty() {
      return e_translation_load_session;
    }

    public override Vx_core.Type_any vx_type() {
      return t_translation_load_session;
    }

    public Vx_core.Func_any_from_any_context vx_fn_new(Vx_core.Class_any_from_any_context.IFn fn) {
      return Vx_core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx_core.Type_context context, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_core.Type_translation inputval = (Vx_core.Type_translation)value;
      Vx_core.Type_any outputval = Vx_translate.f_translation_load_session(context, inputval);
      output = Vx_core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_translation translation = Vx_core.f_any_from_any(Vx_core.t_translation, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_translate.f_translation_load_session(context, translation);
      return output;
    }

    public Vx_core.Type_translation vx_translation_load_session(Vx_core.Type_context context, Vx_core.Type_translation translation) {
      return Vx_translate.f_translation_load_session(context, translation);
    }

  }

  public static Func_translation_load_session e_translation_load_session = new Vx_translate.Class_translation_load_session();
  public static Func_translation_load_session t_translation_load_session = new Vx_translate.Class_translation_load_session();

  public static Vx_core.Type_translation f_translation_load_session(Vx_core.Type_context context, Vx_core.Type_translation translation) {
    Vx_core.Type_translation output = Vx_core.e_translation;
    return output;
  }

  /**
   * @function translation_from_context
   * Returns a translated string from current context.
   * @return {translation}
   * (func translation<-context)
   */
  public interface Func_translation_from_context : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_core.Type_translation vx_translation_from_context(Vx_core.Type_context context);
  }

  public class Class_translation_from_context : Vx_core.Class_base, Func_translation_from_context {

    public override Vx_translate.Func_translation_from_context vx_new(params Object[] vals) {
      Class_translation_from_context output = new Class_translation_from_context();
      return output;
    }

    public override Vx_translate.Func_translation_from_context vx_copy(params Object[] vals) {
      Class_translation_from_context output = new Class_translation_from_context();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/translate", // pkgname
        "translation<-context", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "translation", // name
          ":struct", // extends
          Vx_core.e_typelist, // traits
          Vx_core.e_typelist, // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx_core.Type_any vx_empty() {
      return e_translation_from_context;
    }

    public override Vx_core.Type_any vx_type() {
      return t_translation_from_context;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_context context = Vx_core.f_any_from_any(Vx_core.t_context, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_translate.f_translation_from_context(context);
      return output;
    }

    public Vx_core.Type_translation vx_translation_from_context(Vx_core.Type_context context) {
      return Vx_translate.f_translation_from_context(context);
    }

  }

  public static Func_translation_from_context e_translation_from_context = new Vx_translate.Class_translation_from_context();
  public static Func_translation_from_context t_translation_from_context = new Vx_translate.Class_translation_from_context();

  public static Vx_core.Type_translation f_translation_from_context(Vx_core.Type_context context) {
    Vx_core.Type_translation output = Vx_core.e_translation;
    output = Vx_core.f_session_from_context(context).translation();
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
  public interface Func_translation_from_session_name : Vx_core.Type_func, Vx_core.Type_replfunc {
    public Vx_core.Type_translation vx_translation_from_session_name(Vx_core.Type_session session, Vx_core.Type_string name);
  }

  public class Class_translation_from_session_name : Vx_core.Class_base, Func_translation_from_session_name {

    public override Vx_translate.Func_translation_from_session_name vx_new(params Object[] vals) {
      Class_translation_from_session_name output = new Class_translation_from_session_name();
      return output;
    }

    public override Vx_translate.Func_translation_from_session_name vx_copy(params Object[] vals) {
      Class_translation_from_session_name output = new Class_translation_from_session_name();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/translate", // pkgname
        "translation<-session-name", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "translation", // name
          ":struct", // extends
          Vx_core.e_typelist, // traits
          Vx_core.e_typelist, // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx_core.Type_any vx_empty() {
      return e_translation_from_session_name;
    }

    public override Vx_core.Type_any vx_type() {
      return t_translation_from_session_name;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_session session = Vx_core.f_any_from_any(Vx_core.t_session, arglist.vx_any(Vx_core.vx_new_int(0)));
      Vx_core.Type_string name = Vx_core.f_any_from_any(Vx_core.t_string, arglist.vx_any(Vx_core.vx_new_int(1)));
      output = Vx_translate.f_translation_from_session_name(session, name);
      return output;
    }

    public Vx_core.Type_translation vx_translation_from_session_name(Vx_core.Type_session session, Vx_core.Type_string name) {
      return Vx_translate.f_translation_from_session_name(session, name);
    }

  }

  public static Func_translation_from_session_name e_translation_from_session_name = new Vx_translate.Class_translation_from_session_name();
  public static Func_translation_from_session_name t_translation_from_session_name = new Vx_translate.Class_translation_from_session_name();

  public static Vx_core.Type_translation f_translation_from_session_name(Vx_core.Type_session session, Vx_core.Type_string name) {
    Vx_core.Type_translation output = Vx_core.e_translation;
    output = Vx_core.f_let(
      Vx_core.t_translation,
      Vx_core.t_any_from_func.vx_fn_new(() => {
        Vx_core.Type_translationmap translationmap = session.translationmap();
        return Vx_core.f_any_from_map(Vx_core.t_translation, translationmap, name);
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
  public interface Func_translationmap_from_translations : Vx_core.Func_any_from_any {
    public Vx_core.Type_translationmap vx_translationmap_from_translations(Vx_core.Type_translationlist translations);
  }

  public class Class_translationmap_from_translations : Vx_core.Class_base, Func_translationmap_from_translations {

    public override Vx_translate.Func_translationmap_from_translations vx_new(params Object[] vals) {
      Class_translationmap_from_translations output = new Class_translationmap_from_translations();
      return output;
    }

    public override Vx_translate.Func_translationmap_from_translations vx_copy(params Object[] vals) {
      Class_translationmap_from_translations output = new Class_translationmap_from_translations();
      return output;
    }

    public Vx_core.Type_typedef vx_typedef() {
      return Vx_core.t_func.vx_typedef();
    }

    public Vx_core.Type_funcdef vx_funcdef() {
      return Vx_core.funcdef_new(
        "vx/translate", // pkgname
        "translationmap<-translations", // name
        0, // idx
        false, // async
        Vx_core.typedef_new(
          "vx/core", // pkgname
          "translationmap", // name
          ":map", // extends
          Vx_core.e_typelist, // traits
          Vx_core.vx_new(Vx_core.t_typelist, Vx_core.t_translation), // allowtypes
          Vx_core.e_typelist, // disallowtypes
          Vx_core.e_funclist, // allowfuncs
          Vx_core.e_funclist, // disallowfuncs
          Vx_core.e_anylist, // allowvalues
          Vx_core.e_anylist, // disallowvalues
          Vx_core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx_core.Type_any vx_empty() {
      return e_translationmap_from_translations;
    }

    public override Vx_core.Type_any vx_type() {
      return t_translationmap_from_translations;
    }

    public Vx_core.Func_any_from_any vx_fn_new(Vx_core.Class_any_from_any.IFn fn) {
      return Vx_core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx_core.Type_any where U : Vx_core.Type_any {
      T output = Vx_core.f_empty(generic_any_1);
      Vx_core.Type_translationlist inputval = (Vx_core.Type_translationlist)value;
      Vx_core.Type_any outputval = Vx_translate.f_translationmap_from_translations(inputval);
      output = Vx_core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx_core.Type_any vx_repl(Vx_core.Type_anylist arglist) {
      Vx_core.Type_any output = Vx_core.e_any;
      Vx_core.Type_translationlist translations = Vx_core.f_any_from_any(Vx_core.t_translationlist, arglist.vx_any(Vx_core.vx_new_int(0)));
      output = Vx_translate.f_translationmap_from_translations(translations);
      return output;
    }

    public Vx_core.Type_translationmap vx_translationmap_from_translations(Vx_core.Type_translationlist translations) {
      return Vx_translate.f_translationmap_from_translations(translations);
    }

  }

  public static Func_translationmap_from_translations e_translationmap_from_translations = new Vx_translate.Class_translationmap_from_translations();
  public static Func_translationmap_from_translations t_translationmap_from_translations = new Vx_translate.Class_translationmap_from_translations();

  public static Vx_core.Type_translationmap f_translationmap_from_translations(Vx_core.Type_translationlist translations) {
    Vx_core.Type_translationmap output = Vx_core.e_translationmap;
    output = Vx_core.f_map_from_list(
      Vx_core.t_translationmap,
      translations,
      Vx_core.t_any_from_any.vx_fn_new((translation_any) => {
        Vx_core.Type_translation translation = Vx_core.f_any_from_any(Vx_core.t_translation, translation_any);
        return 
        translation.name();
      })
    );
    return output;
  }


  public static class PackageRunOnce {
    public static void RunOnce() {
    Vx_core.Map<string, Vx_core.Type_any> maptype = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
    Vx_core.Map<string, Vx_core.Type_any> mapconst = new Vx_core.LinkedHashMap<string, Vx_core.Type_any>();
    Vx_core.Map<string, Vx_core.Type_func> mapfunc = new Vx_core.LinkedHashMap<string, Vx_core.Type_func>();
    mapfunc.put("session<-session-name", Vx_translate.t_session_from_session_name);
    mapfunc.put("session<-session-translation", Vx_translate.t_session_from_session_translation);
    mapfunc.put("session<-session-translationmap-name", Vx_translate.t_session_from_session_translationmap_name);
    mapfunc.put("translate", Vx_translate.t_translate);
    mapfunc.put("translate_1", Vx_translate.t_translate_1);
    mapfunc.put("translate<-translation-string", Vx_translate.t_translate_from_translation_string);
    mapfunc.put("translate<-translationmap-name-string", Vx_translate.t_translate_from_translationmap_name_string);
    mapfunc.put("translation-load-session", Vx_translate.t_translation_load_session);
    mapfunc.put("translation<-context", Vx_translate.t_translation_from_context);
    mapfunc.put("translation<-session-name", Vx_translate.t_translation_from_session_name);
    mapfunc.put("translationmap<-translations", Vx_translate.t_translationmap_from_translations);
    Vx_core.vx_global_package_set("vx/translate", maptype, mapconst, mapfunc);
    }
  }

}
