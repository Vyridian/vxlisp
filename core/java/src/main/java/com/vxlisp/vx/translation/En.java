package com.vxlisp.vx.translation;

import java.util.LinkedHashMap;
import java.util.Map;
import com.vxlisp.vx.*;

public final class En {

  /**
   * @function context_en
   * Returns the default context for app main execution. Arguments come from the command line.
   * @param  {anylist} args
   * @return {context}
   * (func context-en)
   */
  public static interface Func_context_en extends Core.Func_any_from_any {
    public Core.Type_context vx_context_en(final Core.Type_anylist args);
  }

  public static class Class_context_en extends Core.Class_base implements Func_context_en {

    @Override
    public Func_context_en vx_new(Object... vals) {
      Class_context_en output = new Class_context_en();
      return output;
    }

    @Override
    public Func_context_en vx_copy(Object... vals) {
      Class_context_en output = new Class_context_en();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/translation/en", // pkgname
        "context-en", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "context", // name
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
    public Func_context_en vx_empty() {return e_context_en;}
    @Override
    public Func_context_en vx_type() {return t_context_en;}

    @Override
    public Core.Func_any_from_any vx_fn_new(Core.Class_any_from_any.IFn fn) {return Core.e_any_from_any;}

    @Override
    public <T extends Core.Type_any, U extends Core.Type_any> T vx_any_from_any(final T generic_any_1, final U value) {
      T output = Core.f_empty(generic_any_1);
      Core.Type_anylist inputval = (Core.Type_anylist)value;
      Core.Type_any outputval = En.f_context_en(inputval);
      output = Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      Core.Type_anylist args = Core.f_any_from_any(Core.t_anylist, arglist.vx_any(Core.vx_new_int(0)));
      output = En.f_context_en(args);
      return output;
    }

    @Override
    public Core.Type_context vx_context_en(final Core.Type_anylist args) {
      return En.f_context_en(args);
    }

  }

  public static final Func_context_en e_context_en = new En.Class_context_en();
  public static final Func_context_en t_context_en = new En.Class_context_en();

  public static Core.Type_context f_context_en(final Core.Type_anylist args) {
    Core.Type_context output = Core.e_context;
    output = Core.f_new(
      Core.t_context,
      Core.t_anylist.vx_new(
        Core.vx_new_string(":session"),
        Core.f_new(
          Core.t_session,
          Core.t_anylist.vx_new(
            Core.vx_new_string(":translation"),
            En.f_translation_en()
          )
        )
      )
    );
    return output;
  }

  /**
   * @function translation_en
   * Returns translation data
   * @return {translation}
   * (func translation-en)
   */
  public static interface Func_translation_en extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_translation vx_translation_en();
  }

  public static class Class_translation_en extends Core.Class_base implements Func_translation_en {

    @Override
    public Func_translation_en vx_new(Object... vals) {
      Class_translation_en output = new Class_translation_en();
      return output;
    }

    @Override
    public Func_translation_en vx_copy(Object... vals) {
      Class_translation_en output = new Class_translation_en();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/translation/en", // pkgname
        "translation-en", // name
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
    public Func_translation_en vx_empty() {return e_translation_en;}
    @Override
    public Func_translation_en vx_type() {return t_translation_en;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      output = En.f_translation_en();
      return output;
    }

    @Override
    public Core.Type_translation vx_translation_en() {
      return En.f_translation_en();
    }

  }

  public static final Func_translation_en e_translation_en = new En.Class_translation_en();
  public static final Func_translation_en t_translation_en = new En.Class_translation_en();

  public static Core.Type_translation f_translation_en() {
    Core.Type_translation output = Core.e_translation;
    output = Core.f_new(
      Core.t_translation,
      Core.t_anylist.vx_new(
        Core.vx_new_string(":name"),
        Core.vx_new_string("en"),
        Core.vx_new_string(":wordmap"),
        En.f_words()
      )
    );
    return output;
  }

  /**
   * @function words
   * Word Translation
   * @return {stringmap}
   * (func words)
   */
  public static interface Func_words extends Core.Type_func, Core.Type_replfunc {
    public Core.Type_stringmap vx_words();
  }

  public static class Class_words extends Core.Class_base implements Func_words {

    @Override
    public Func_words vx_new(Object... vals) {
      Class_words output = new Class_words();
      return output;
    }

    @Override
    public Func_words vx_copy(Object... vals) {
      Class_words output = new Class_words();
      return output;
    }

    @Override
    public Core.Type_typedef vx_typedef() {return Core.t_func.vx_typedef();}

    @Override
    public Core.Type_funcdef vx_funcdef() {
      return Core.funcdef_new(
        "vx/translation/en", // pkgname
        "words", // name
        0, // idx
        false, // async
        Core.typedef_new(
          "vx/core", // pkgname
          "stringmap", // name
          ":map", // extends
          Core.e_typelist, // traits
          Core.t_typelist.vx_new(Core.t_string), // allowtypes
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
    public Func_words vx_empty() {return e_words;}
    @Override
    public Func_words vx_type() {return t_words;}

    public Core.Type_any vx_repl(Core.Type_anylist arglist) {
      Core.Type_any output = Core.e_any;
      output = En.f_words();
      return output;
    }

    @Override
    public Core.Type_stringmap vx_words() {
      return En.f_words();
    }

  }

  public static final Func_words e_words = new En.Class_words();
  public static final Func_words t_words = new En.Class_words();

  public static Core.Type_stringmap f_words() {
    Core.Type_stringmap output = Core.e_stringmap;
    output = Core.f_new(
      Core.t_stringmap,
      Core.t_anylist.vx_new(
        Core.vx_new_string("Hello"),
        Core.vx_new_string("Hello"),
        Core.vx_new_string("World"),
        Core.vx_new_string("World")
      )
    );
    return output;
  }


  static {
    Map<String, Core.Type_any> maptype = new LinkedHashMap<>();
    Map<String, Core.Type_any> mapconst = new LinkedHashMap<>();
    Map<String, Core.Type_func> mapfunc = new LinkedHashMap<>();
    mapfunc.put("context-en", En.t_context_en);
    mapfunc.put("translation-en", En.t_translation_en);
    mapfunc.put("words", En.t_words);
    Core.vx_global_package_set("vx/translation/en", maptype, mapconst, mapfunc);
  }

}
