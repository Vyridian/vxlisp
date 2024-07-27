namespace Vx;

public static class Translate {

  /**
   * @function session_from_session_name
   * Returns an updated session with a translationmap and a translation name.
   * @param  {session} session
   * @param  {string} name
   * @return {session}
   * (func session<-session-name)
   */
  public interface Func_session_from_session_name : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_session vx_session_from_session_name(Vx.Core.Type_session session, Vx.Core.Type_string name);
  }

  public class Class_session_from_session_name : Vx.Core.Class_base, Func_session_from_session_name {

    public override Vx.Translate.Func_session_from_session_name vx_new(params object[] vals) {
      Class_session_from_session_name output = new Class_session_from_session_name();
      return output;
    }

    public override Vx.Translate.Func_session_from_session_name vx_copy(params object[] vals) {
      Class_session_from_session_name output = new Class_session_from_session_name();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/translate", // pkgname
        "session<-session-name", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "session", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_session_from_session_name;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_session_from_session_name;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_session session = Vx.Core.f_any_from_any(Vx.Core.t_session, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string name = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Translate.f_session_from_session_name(session, name);
      return output;
    }

    public Vx.Core.Type_session vx_session_from_session_name(Vx.Core.Type_session session, Vx.Core.Type_string name) {
      return Vx.Translate.f_session_from_session_name(session, name);
    }

  }

  public static Func_session_from_session_name e_session_from_session_name = new Vx.Translate.Class_session_from_session_name();
  public static Func_session_from_session_name t_session_from_session_name = new Vx.Translate.Class_session_from_session_name();

  public static Vx.Core.Type_session f_session_from_session_name(Vx.Core.Type_session session, Vx.Core.Type_string name) {
    Vx.Core.Type_session output = Vx.Core.e_session;
    output = Vx.Core.f_copy(
      session,
      Vx.Core.vx_new(Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":translation"),
        Vx.Translate.f_translation_from_session_name(session, name)
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
  public interface Func_session_from_session_translation : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_session vx_session_from_session_translation(Vx.Core.Type_session session, Vx.Core.Type_translation translation);
  }

  public class Class_session_from_session_translation : Vx.Core.Class_base, Func_session_from_session_translation {

    public override Vx.Translate.Func_session_from_session_translation vx_new(params object[] vals) {
      Class_session_from_session_translation output = new Class_session_from_session_translation();
      return output;
    }

    public override Vx.Translate.Func_session_from_session_translation vx_copy(params object[] vals) {
      Class_session_from_session_translation output = new Class_session_from_session_translation();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/translate", // pkgname
        "session<-session-translation", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "session", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_session_from_session_translation;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_session_from_session_translation;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_session session = Vx.Core.f_any_from_any(Vx.Core.t_session, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_translation translation = Vx.Core.f_any_from_any(Vx.Core.t_translation, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Translate.f_session_from_session_translation(session, translation);
      return output;
    }

    public Vx.Core.Type_session vx_session_from_session_translation(Vx.Core.Type_session session, Vx.Core.Type_translation translation) {
      return Vx.Translate.f_session_from_session_translation(session, translation);
    }

  }

  public static Func_session_from_session_translation e_session_from_session_translation = new Vx.Translate.Class_session_from_session_translation();
  public static Func_session_from_session_translation t_session_from_session_translation = new Vx.Translate.Class_session_from_session_translation();

  public static Vx.Core.Type_session f_session_from_session_translation(Vx.Core.Type_session session, Vx.Core.Type_translation translation) {
    Vx.Core.Type_session output = Vx.Core.e_session;
    output = Vx.Core.f_copy(
      session,
      Vx.Core.vx_new(Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":translation"),
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
  public interface Func_session_from_session_translationmap_name : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_session vx_session_from_session_translationmap_name(Vx.Core.Type_session session, Vx.Core.Type_translationmap translationmap, Vx.Core.Type_string name);
  }

  public class Class_session_from_session_translationmap_name : Vx.Core.Class_base, Func_session_from_session_translationmap_name {

    public override Vx.Translate.Func_session_from_session_translationmap_name vx_new(params object[] vals) {
      Class_session_from_session_translationmap_name output = new Class_session_from_session_translationmap_name();
      return output;
    }

    public override Vx.Translate.Func_session_from_session_translationmap_name vx_copy(params object[] vals) {
      Class_session_from_session_translationmap_name output = new Class_session_from_session_translationmap_name();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/translate", // pkgname
        "session<-session-translationmap-name", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "session", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_session_from_session_translationmap_name;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_session_from_session_translationmap_name;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_session session = Vx.Core.f_any_from_any(Vx.Core.t_session, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_translationmap translationmap = Vx.Core.f_any_from_any(Vx.Core.t_translationmap, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Type_string name = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Translate.f_session_from_session_translationmap_name(session, translationmap, name);
      return output;
    }

    public Vx.Core.Type_session vx_session_from_session_translationmap_name(Vx.Core.Type_session session, Vx.Core.Type_translationmap translationmap, Vx.Core.Type_string name) {
      return Vx.Translate.f_session_from_session_translationmap_name(session, translationmap, name);
    }

  }

  public static Func_session_from_session_translationmap_name e_session_from_session_translationmap_name = new Vx.Translate.Class_session_from_session_translationmap_name();
  public static Func_session_from_session_translationmap_name t_session_from_session_translationmap_name = new Vx.Translate.Class_session_from_session_translationmap_name();

  public static Vx.Core.Type_session f_session_from_session_translationmap_name(Vx.Core.Type_session session, Vx.Core.Type_translationmap translationmap, Vx.Core.Type_string name) {
    Vx.Core.Type_session output = Vx.Core.e_session;
    output = Vx.Core.f_copy(
      session,
      Vx.Core.vx_new(Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":translation"),
        Vx.Core.f_any_from_map(Vx.Core.t_anylist, translationmap, name),
        Vx.Core.vx_new_string(":translationmap"),
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
  public interface Func_translate : Vx.Core.Func_any_from_any_context {
    public Vx.Core.Type_string vx_translate(Vx.Core.Type_context context, Vx.Core.Type_string text);
  }

  public class Class_translate : Vx.Core.Class_base, Func_translate {

    public override Vx.Translate.Func_translate vx_new(params object[] vals) {
      Class_translate output = new Class_translate();
      return output;
    }

    public override Vx.Translate.Func_translate vx_copy(params object[] vals) {
      Class_translate output = new Class_translate();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/translate", // pkgname
        "translate", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_translate;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_translate;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_string inputval = (Vx.Core.Type_string)value;
      Vx.Core.Type_any outputval = Vx.Translate.f_translate(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Translate.f_translate(context, text);
      return output;
    }

    public Vx.Core.Type_string vx_translate(Vx.Core.Type_context context, Vx.Core.Type_string text) {
      return Vx.Translate.f_translate(context, text);
    }

  }

  public static Func_translate e_translate = new Vx.Translate.Class_translate();
  public static Func_translate t_translate = new Vx.Translate.Class_translate();

  public static Vx.Core.Type_string f_translate(Vx.Core.Type_context context, Vx.Core.Type_string text) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Translate.f_translate_from_translation_string(
      Vx.Translate.f_translation_from_context(context),
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
  public interface Func_translate_1 : Vx.Core.Func_any_from_any_context {
    public Vx.Core.Type_string vx_translate_1(Vx.Core.Type_context context, Vx.Core.Type_msg msg);
  }

  public class Class_translate_1 : Vx.Core.Class_base, Func_translate_1 {

    public override Vx.Translate.Func_translate_1 vx_new(params object[] vals) {
      Class_translate_1 output = new Class_translate_1();
      return output;
    }

    public override Vx.Translate.Func_translate_1 vx_copy(params object[] vals) {
      Class_translate_1 output = new Class_translate_1();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/translate", // pkgname
        "translate", // name
        1, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_translate_1;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_translate_1;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_msg inputval = (Vx.Core.Type_msg)value;
      Vx.Core.Type_any outputval = Vx.Translate.f_translate_1(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_msg msg = Vx.Core.f_any_from_any(Vx.Core.t_msg, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Translate.f_translate_1(context, msg);
      return output;
    }

    public Vx.Core.Type_string vx_translate_1(Vx.Core.Type_context context, Vx.Core.Type_msg msg) {
      return Vx.Translate.f_translate_1(context, msg);
    }

  }

  public static Func_translate_1 e_translate_1 = new Vx.Translate.Class_translate_1();
  public static Func_translate_1 t_translate_1 = new Vx.Translate.Class_translate_1();

  public static Vx.Core.Type_string f_translate_1(Vx.Core.Type_context context, Vx.Core.Type_msg msg) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_string path = msg.path();
        Vx.Core.Type_string code = msg.code();
        Vx.Core.Type_string text = Vx.Core.f_new(
          Vx.Core.t_string,
          Vx.Core.vx_new(Vx.Core.t_anylist,
              Vx.Core.vx_new_string("!"),
              path,
              Vx.Core.vx_new_string(" "),
              code
          )
        );
        Vx.Core.Type_any output_1 = Vx.Translate.f_translate(context, text);
        return output_1;
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
  public interface Func_translate_from_translation_string : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_translate_from_translation_string(Vx.Core.Type_translation translation, Vx.Core.Type_string text);
  }

  public class Class_translate_from_translation_string : Vx.Core.Class_base, Func_translate_from_translation_string {

    public override Vx.Translate.Func_translate_from_translation_string vx_new(params object[] vals) {
      Class_translate_from_translation_string output = new Class_translate_from_translation_string();
      return output;
    }

    public override Vx.Translate.Func_translate_from_translation_string vx_copy(params object[] vals) {
      Class_translate_from_translation_string output = new Class_translate_from_translation_string();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/translate", // pkgname
        "translate<-translation-string", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_translate_from_translation_string;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_translate_from_translation_string;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_translation translation = Vx.Core.f_any_from_any(Vx.Core.t_translation, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Translate.f_translate_from_translation_string(translation, text);
      return output;
    }

    public Vx.Core.Type_string vx_translate_from_translation_string(Vx.Core.Type_translation translation, Vx.Core.Type_string text) {
      return Vx.Translate.f_translate_from_translation_string(translation, text);
    }

  }

  public static Func_translate_from_translation_string e_translate_from_translation_string = new Vx.Translate.Class_translate_from_translation_string();
  public static Func_translate_from_translation_string t_translate_from_translation_string = new Vx.Translate.Class_translate_from_translation_string();

  public static Vx.Core.Type_string f_translate_from_translation_string(Vx.Core.Type_translation translation, Vx.Core.Type_string text) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_if_1(
      Vx.Core.t_string,
      Vx.Core.f_is_empty_1(translation),
      text,
      Vx.Core.f_let(
        Vx.Core.t_string,
        Vx.Core.t_any_from_func.vx_fn_new(() => {
          Vx.Core.Type_stringmap wordmap = translation.wordmap();
          Vx.Core.Type_string xlate = Vx.Core.f_any_from_map(Vx.Core.t_string, wordmap, text);
          Vx.Core.Type_any output_1 = Vx.Core.f_if_1(
            Vx.Core.t_string,
            Vx.Core.f_is_empty(xlate),
            text,
            xlate
          );
          return output_1;
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
  public interface Func_translate_from_translationmap_name_string : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_string vx_translate_from_translationmap_name_string(Vx.Core.Type_translationmap translationmap, Vx.Core.Type_string name, Vx.Core.Type_string text);
  }

  public class Class_translate_from_translationmap_name_string : Vx.Core.Class_base, Func_translate_from_translationmap_name_string {

    public override Vx.Translate.Func_translate_from_translationmap_name_string vx_new(params object[] vals) {
      Class_translate_from_translationmap_name_string output = new Class_translate_from_translationmap_name_string();
      return output;
    }

    public override Vx.Translate.Func_translate_from_translationmap_name_string vx_copy(params object[] vals) {
      Class_translate_from_translationmap_name_string output = new Class_translate_from_translationmap_name_string();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/translate", // pkgname
        "translate<-translationmap-name-string", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "string", // name
          ":string", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_translate_from_translationmap_name_string;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_translate_from_translationmap_name_string;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_translationmap translationmap = Vx.Core.f_any_from_any(Vx.Core.t_translationmap, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string name = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      Vx.Core.Type_string text = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(2)));
      output = Vx.Translate.f_translate_from_translationmap_name_string(translationmap, name, text);
      return output;
    }

    public Vx.Core.Type_string vx_translate_from_translationmap_name_string(Vx.Core.Type_translationmap translationmap, Vx.Core.Type_string name, Vx.Core.Type_string text) {
      return Vx.Translate.f_translate_from_translationmap_name_string(translationmap, name, text);
    }

  }

  public static Func_translate_from_translationmap_name_string e_translate_from_translationmap_name_string = new Vx.Translate.Class_translate_from_translationmap_name_string();
  public static Func_translate_from_translationmap_name_string t_translate_from_translationmap_name_string = new Vx.Translate.Class_translate_from_translationmap_name_string();

  public static Vx.Core.Type_string f_translate_from_translationmap_name_string(Vx.Core.Type_translationmap translationmap, Vx.Core.Type_string name, Vx.Core.Type_string text) {
    Vx.Core.Type_string output = Vx.Core.e_string;
    output = Vx.Core.f_let(
      Vx.Core.t_string,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_translation translation = Vx.Core.f_any_from_map(Vx.Core.t_translation, translationmap, name);
        Vx.Core.Type_any output_1 = Vx.Translate.f_translate_from_translation_string(translation, text);
        return output_1;
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
  public interface Func_translation_load_session : Vx.Core.Func_any_from_any_context {
    public Vx.Core.Type_translation vx_translation_load_session(Vx.Core.Type_context context, Vx.Core.Type_translation translation);
  }

  public class Class_translation_load_session : Vx.Core.Class_base, Func_translation_load_session {

    public override Vx.Translate.Func_translation_load_session vx_new(params object[] vals) {
      Class_translation_load_session output = new Class_translation_load_session();
      return output;
    }

    public override Vx.Translate.Func_translation_load_session vx_copy(params object[] vals) {
      Class_translation_load_session output = new Class_translation_load_session();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/translate", // pkgname
        "translation-load-session", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "translation", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_translation_load_session;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_translation_load_session;
    }

    public Vx.Core.Func_any_from_any_context vx_fn_new(Vx.Core.Class_any_from_any_context.IFn fn) {
      return Vx.Core.e_any_from_any_context;
    }

    public T vx_any_from_any_context<T, U>(T generic_any_1, Vx.Core.Type_context context, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_translation inputval = (Vx.Core.Type_translation)value;
      Vx.Core.Type_any outputval = Vx.Translate.f_translation_load_session(context, inputval);
      output = Vx.Core.f_any_from_any_context(generic_any_1, context, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_translation translation = Vx.Core.f_any_from_any(Vx.Core.t_translation, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Translate.f_translation_load_session(context, translation);
      return output;
    }

    public Vx.Core.Type_translation vx_translation_load_session(Vx.Core.Type_context context, Vx.Core.Type_translation translation) {
      return Vx.Translate.f_translation_load_session(context, translation);
    }

  }

  public static Func_translation_load_session e_translation_load_session = new Vx.Translate.Class_translation_load_session();
  public static Func_translation_load_session t_translation_load_session = new Vx.Translate.Class_translation_load_session();

  public static Vx.Core.Type_translation f_translation_load_session(Vx.Core.Type_context context, Vx.Core.Type_translation translation) {
    Vx.Core.Type_translation output = Vx.Core.e_translation;
    return output;
  }

  /**
   * @function translation_from_context
   * Returns a translated string from current context.
   * @return {translation}
   * (func translation<-context)
   */
  public interface Func_translation_from_context : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_translation vx_translation_from_context(Vx.Core.Type_context context);
  }

  public class Class_translation_from_context : Vx.Core.Class_base, Func_translation_from_context {

    public override Vx.Translate.Func_translation_from_context vx_new(params object[] vals) {
      Class_translation_from_context output = new Class_translation_from_context();
      return output;
    }

    public override Vx.Translate.Func_translation_from_context vx_copy(params object[] vals) {
      Class_translation_from_context output = new Class_translation_from_context();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/translate", // pkgname
        "translation<-context", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "translation", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_translation_from_context;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_translation_from_context;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_context context = Vx.Core.f_any_from_any(Vx.Core.t_context, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Translate.f_translation_from_context(context);
      return output;
    }

    public Vx.Core.Type_translation vx_translation_from_context(Vx.Core.Type_context context) {
      return Vx.Translate.f_translation_from_context(context);
    }

  }

  public static Func_translation_from_context e_translation_from_context = new Vx.Translate.Class_translation_from_context();
  public static Func_translation_from_context t_translation_from_context = new Vx.Translate.Class_translation_from_context();

  public static Vx.Core.Type_translation f_translation_from_context(Vx.Core.Type_context context) {
    Vx.Core.Type_translation output = Vx.Core.e_translation;
    output = Vx.Core.f_session_from_context(context).translation();
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
  public interface Func_translation_from_session_name : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_translation vx_translation_from_session_name(Vx.Core.Type_session session, Vx.Core.Type_string name);
  }

  public class Class_translation_from_session_name : Vx.Core.Class_base, Func_translation_from_session_name {

    public override Vx.Translate.Func_translation_from_session_name vx_new(params object[] vals) {
      Class_translation_from_session_name output = new Class_translation_from_session_name();
      return output;
    }

    public override Vx.Translate.Func_translation_from_session_name vx_copy(params object[] vals) {
      Class_translation_from_session_name output = new Class_translation_from_session_name();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/translate", // pkgname
        "translation<-session-name", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "translation", // name
          ":struct", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.e_typelist, // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_translation_from_session_name;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_translation_from_session_name;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_session session = Vx.Core.f_any_from_any(Vx.Core.t_session, arglist.vx_any(Vx.Core.vx_new_int(0)));
      Vx.Core.Type_string name = Vx.Core.f_any_from_any(Vx.Core.t_string, arglist.vx_any(Vx.Core.vx_new_int(1)));
      output = Vx.Translate.f_translation_from_session_name(session, name);
      return output;
    }

    public Vx.Core.Type_translation vx_translation_from_session_name(Vx.Core.Type_session session, Vx.Core.Type_string name) {
      return Vx.Translate.f_translation_from_session_name(session, name);
    }

  }

  public static Func_translation_from_session_name e_translation_from_session_name = new Vx.Translate.Class_translation_from_session_name();
  public static Func_translation_from_session_name t_translation_from_session_name = new Vx.Translate.Class_translation_from_session_name();

  public static Vx.Core.Type_translation f_translation_from_session_name(Vx.Core.Type_session session, Vx.Core.Type_string name) {
    Vx.Core.Type_translation output = Vx.Core.e_translation;
    output = Vx.Core.f_let(
      Vx.Core.t_translation,
      Vx.Core.t_any_from_func.vx_fn_new(() => {
        Vx.Core.Type_translationmap translationmap = session.translationmap();
        Vx.Core.Type_any output_1 = Vx.Core.f_any_from_map(Vx.Core.t_translation, translationmap, name);
        return output_1;
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
  public interface Func_translationmap_from_translations : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_translationmap vx_translationmap_from_translations(Vx.Core.Type_translationlist translations);
  }

  public class Class_translationmap_from_translations : Vx.Core.Class_base, Func_translationmap_from_translations {

    public override Vx.Translate.Func_translationmap_from_translations vx_new(params object[] vals) {
      Class_translationmap_from_translations output = new Class_translationmap_from_translations();
      return output;
    }

    public override Vx.Translate.Func_translationmap_from_translations vx_copy(params object[] vals) {
      Class_translationmap_from_translations output = new Class_translationmap_from_translations();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      return Vx.Core.t_func.vx_typedef();
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      return Vx.Core.funcdef_new(
        "vx/translate", // pkgname
        "translationmap<-translations", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "translationmap", // name
          ":map", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_translation), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
    }

    public override Vx.Core.Type_any vx_empty() {
      return e_translationmap_from_translations;
    }

    public override Vx.Core.Type_any vx_type() {
      return t_translationmap_from_translations;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_translationlist inputval = (Vx.Core.Type_translationlist)value;
      Vx.Core.Type_any outputval = Vx.Translate.f_translationmap_from_translations(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_translationlist translations = Vx.Core.f_any_from_any(Vx.Core.t_translationlist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Translate.f_translationmap_from_translations(translations);
      return output;
    }

    public Vx.Core.Type_translationmap vx_translationmap_from_translations(Vx.Core.Type_translationlist translations) {
      return Vx.Translate.f_translationmap_from_translations(translations);
    }

  }

  public static Func_translationmap_from_translations e_translationmap_from_translations = new Vx.Translate.Class_translationmap_from_translations();
  public static Func_translationmap_from_translations t_translationmap_from_translations = new Vx.Translate.Class_translationmap_from_translations();

  public static Vx.Core.Type_translationmap f_translationmap_from_translations(Vx.Core.Type_translationlist translations) {
    Vx.Core.Type_translationmap output = Vx.Core.e_translationmap;
    output = Vx.Core.f_map_from_list(
      Vx.Core.t_translationmap,
      translations,
      Vx.Core.t_any_from_any.vx_fn_new((translation_any) => {
        Vx.Core.Type_translation translation = Vx.Core.f_any_from_any(Vx.Core.t_translation, translation_any);
        Vx.Core.Type_any output_1 = 
          translation.name();
        return output_1;
      })
    );
    return output;
  }


  public static class PackageRunOnce {
    public static bool RunOnce() {
    Vx.Core.Map<string, Vx.Core.Type_any> maptype = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_any> mapconst = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_func> mapfunc = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>();
    mapfunc.put("session<-session-name", Vx.Translate.t_session_from_session_name);
    mapfunc.put("session<-session-translation", Vx.Translate.t_session_from_session_translation);
    mapfunc.put("session<-session-translationmap-name", Vx.Translate.t_session_from_session_translationmap_name);
    mapfunc.put("translate", Vx.Translate.t_translate);
    mapfunc.put("translate_1", Vx.Translate.t_translate_1);
    mapfunc.put("translate<-translation-string", Vx.Translate.t_translate_from_translation_string);
    mapfunc.put("translate<-translationmap-name-string", Vx.Translate.t_translate_from_translationmap_name_string);
    mapfunc.put("translation-load-session", Vx.Translate.t_translation_load_session);
    mapfunc.put("translation<-context", Vx.Translate.t_translation_from_context);
    mapfunc.put("translation<-session-name", Vx.Translate.t_translation_from_session_name);
    mapfunc.put("translationmap<-translations", Vx.Translate.t_translationmap_from_translations);
    Vx.Core.vx_global_package_set("vx/translate", maptype, mapconst, mapfunc);
      return true;
    }
  }

  public static bool ranonce = PackageRunOnce.RunOnce();

}
