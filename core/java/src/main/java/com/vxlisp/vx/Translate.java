package com.vxlisp.vx;

import java.util.LinkedHashMap;
import java.util.Map;
import com.vxlisp.vx.data.*;

public final class Translate {

  /**
   * @function translate
   * Returns a translated string from a translation or the original text if not found.
   * @param  {translation} translation
   * @param  {string} text
   * @return {string}
   * (func translate)
   */
  public static interface Func_translate extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_string vx_translate(final Core.Type_translation translation, final Core.Type_string text);
  }

  public static class Class_translate extends Core.Class_base implements Func_translate {

    @Override
    public Func_translate vx_new(Object... vals) {
      Class_translate output = new Class_translate();
      return output;
    }

    @Override
    public Func_translate vx_copy(Object... vals) {
      Class_translate output = new Class_translate();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
    public Func_translate vx_empty() {return e_translate;}
    @Override
    public Func_translate vx_type() {return t_translate;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_translation translation = Core.f_any_from_any(Core.t_translation, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(1)));
      output = Translate.f_translate(translation, text);
      return output;
    }

    @Override
    public Core.Type_string vx_translate(final Core.Type_translation translation, final Core.Type_string text) {
      return Translate.f_translate(translation, text);
    }

  }

  public static final Func_translate e_translate = new Translate.Class_translate();
  public static final Func_translate t_translate = new Translate.Class_translate();

  public static Core.Type_string f_translate(final Core.Type_translation translation, final Core.Type_string text) {
    Core.Type_string output = Core.e_string;
    output = Core.f_if_1(
      Core.t_string,
      Core.f_is_empty_1(translation),
      text,
      Core.f_let(
        Core.t_string,
        Core.t_any_from_func.vx_fn_new(() -> {
          final Core.Type_stringmap textmap = translation.translationmap();
          final Core.Type_string xlate = Core.f_any_from_map(Core.t_string, textmap, text);
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
   * @function translate 1
   * Returns a translated string from current context.
   * @param  {string} text
   * @return {string}
   * (func translate)
   */
  public static interface Func_translate_1 extends Core.Func_any_from_any_context {
    public Core.Type_string vx_translate_1(final Core.Type_context context, final Core.Type_string text);
  }

  public static class Class_translate_1 extends Core.Class_base implements Func_translate_1 {

    @Override
    public Func_translate_1 vx_new(Object... vals) {
      Class_translate_1 output = new Class_translate_1();
      return output;
    }

    @Override
    public Func_translate_1 vx_copy(Object... vals) {
      Class_translate_1 output = new Class_translate_1();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
    public Func_translate_1 vx_empty() {return e_translate_1;}
    @Override
    public Func_translate_1 vx_type() {return t_translate_1;}

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Translate.f_translate_1(context, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string text = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Translate.f_translate_1(context, text);
      return output;
    }

    @Override
    public Core.Type_string vx_translate_1(final Core.Type_context context, final Core.Type_string text) {
      return Translate.f_translate_1(context, text);
    }

  }

  public static final Func_translate_1 e_translate_1 = new Translate.Class_translate_1();
  public static final Func_translate_1 t_translate_1 = new Translate.Class_translate_1();

  public static Core.Type_string f_translate_1(final Core.Type_context context, final Core.Type_string text) {
    Core.Type_string output = Core.e_string;
    output = Translate.f_translate(
      Translate.f_translation_from_context(context),
      text
    );
    return output;
  }

  /**
   * @function translation_load
   * Returns a translation from the translation folder.
   * @param  {string} code
   * @return {translation}
   * (func translation-load)
   */
  public static interface Func_translation_load extends Core.Func_any_from_any_context {
    public Core.Type_translation vx_translation_load(final Core.Type_context context, final Core.Type_string code);
  }

  public static class Class_translation_load extends Core.Class_base implements Func_translation_load {

    @Override
    public Func_translation_load vx_new(Object... vals) {
      Class_translation_load output = new Class_translation_load();
      return output;
    }

    @Override
    public Func_translation_load vx_copy(Object... vals) {
      Class_translation_load output = new Class_translation_load();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/translate", // pkgname
        "translation-load", // name
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
    public Func_translation_load vx_empty() {return e_translation_load;}
    @Override
    public Func_translation_load vx_type() {return t_translation_load;}

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_string inputval = (Core.Type_string)value;
      Core.Type_any outputval = Translate.f_translation_load(context, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_context context = Core.f_any_from_any(Core.t_context, arglist.vx_any(Core.vx_new_int(0)));
      Core.Type_string code = Core.f_any_from_any(Core.t_string, arglist.vx_any(Core.vx_new_int(0)));
      output = Translate.f_translation_load(context, code);
      return output;
    }

    @Override
    public Core.Type_translation vx_translation_load(final Core.Type_context context, final Core.Type_string code) {
      return Translate.f_translation_load(context, code);
    }

  }

  public static final Func_translation_load e_translation_load = new Translate.Class_translation_load();
  public static final Func_translation_load t_translation_load = new Translate.Class_translation_load();

  public static Core.Type_translation f_translation_load(final Core.Type_context context, final Core.Type_string code) {
    Core.Type_translation output = Core.e_translation;
    output = Core.f_let(
      Core.t_translation,
      Core.t_any_from_func.vx_fn_new(() -> {
        final File.Type_file filecsv = Core.f_new(
          File.t_file,
          Core.t_anylist.vx_new(
              Core.vx_new_string(":name"),
              Core.f_new(
                Core.t_string,
                Core.t_anylist.vx_new(
                  code,
                  Core.vx_new_string(".csv")
                )
              ),
              Core.vx_new_string(":path"),
              Core.vx_new_string("translation")
          )
        );
        final Csv.Type_csv csvread = Csv.f_csv_read_from_file(context, filecsv);
        final Core.Type_stringmap textmap = Csv.f_stringmap_from_csv(csvread);
        return Core.f_new(
          Core.t_translation,
          Core.t_anylist.vx_new(
            Core.vx_new_string(":translationmap"),
            textmap
          )
        );
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
  public static interface Func_translation_load_session extends Core.Func_any_from_any_context {
    public Core.Type_translation vx_translation_load_session(final Core.Type_context context, final Core.Type_translation translation);
  }

  public static class Class_translation_load_session extends Core.Class_base implements Func_translation_load_session {

    @Override
    public Func_translation_load_session vx_new(Object... vals) {
      Class_translation_load_session output = new Class_translation_load_session();
      return output;
    }

    @Override
    public Func_translation_load_session vx_copy(Object... vals) {
      Class_translation_load_session output = new Class_translation_load_session();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
    public Func_translation_load_session vx_empty() {return e_translation_load_session;}
    @Override
    public Func_translation_load_session vx_type() {return t_translation_load_session;}

    @Override
    public Core.Func_any_from_any_context vx_fn_new(Core.Class_any_from_any_context.IFn fn) {return Core.e_any_from_any_context;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any_context(final T generic_any_1, final Core.Type_context context, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_translation inputval = (Core.Type_translation)value;
      Core.Type_any outputval = Translate.f_translation_load_session(context, inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
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
  public static interface Func_translation_from_context extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_translation vx_translation_from_context(final Core.Type_context context);
  }

  public static class Class_translation_from_context extends Core.Class_base implements Func_translation_from_context {

    @Override
    public Func_translation_from_context vx_new(Object... vals) {
      Class_translation_from_context output = new Class_translation_from_context();
      return output;
    }

    @Override
    public Func_translation_from_context vx_copy(Object... vals) {
      Class_translation_from_context output = new Class_translation_from_context();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

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
    public Func_translation_from_context vx_empty() {return e_translation_from_context;}
    @Override
    public Func_translation_from_context vx_type() {return t_translation_from_context;}

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


  static {
    Map<String, Core.Type_any> maptype = new LinkedHashMap<>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<>();
    mapfunc.put("translate", Translate.t_translate);
    mapfunc.put("translate_1", Translate.t_translate_1);
    mapfunc.put("translation-load", Translate.t_translation_load);
    mapfunc.put("translation-load-session", Translate.t_translation_load_session);
    mapfunc.put("translation<-context", Translate.t_translation_from_context);
    Core.vx_global_package_set("vx/translate", maptype, mapconst, mapfunc);
  }

}
