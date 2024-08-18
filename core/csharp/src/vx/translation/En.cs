namespace Vx.Translation;

public static class En {

  /**
   * @function context_en
   * Returns the default context for app main execution. Arguments come from the command line.
   * @param  {anylist} args
   * @return {context}
   * (func context-en)
   */
  public interface Func_context_en : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_context vx_context_en(Vx.Core.Type_anylist args);
  }

  public class Class_context_en : Vx.Core.Class_base, Func_context_en {

    public override Vx.Translation.En.Func_context_en vx_new(params object[] vals) {
      Vx.Translation.En.Class_context_en output = new Vx.Translation.En.Class_context_en();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Translation.En.Class_context_en output = new Vx.Translation.En.Class_context_en();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/translation/en", // pkgname
        "context-en", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "context", // name
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Translation.En.e_context_en;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Translation.En.t_context_en;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_anylist inputval = (Vx.Core.Type_anylist)value;
      Vx.Core.Type_any outputval = Vx.Translation.En.f_context_en(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_anylist args = Vx.Core.f_any_from_any(Vx.Core.t_anylist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Translation.En.f_context_en(args);
      return output;
    }

    public Vx.Core.Type_context vx_context_en(Vx.Core.Type_anylist args) {
      Vx.Core.Type_context output = Vx.Translation.En.f_context_en(args);
      return output;
    }

  }

  public static Vx.Translation.En.Func_context_en e_context_en = new Vx.Translation.En.Class_context_en();
  public static Vx.Translation.En.Func_context_en t_context_en = new Vx.Translation.En.Class_context_en();

  public static Vx.Core.Type_context f_context_en(Vx.Core.Type_anylist args) {
    Vx.Core.Type_context output = Vx.Core.e_context;
    output = Vx.Core.f_new(
      Vx.Core.t_context,
      Vx.Core.vx_new(
        Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":session"),
        Vx.Core.f_new(
          Vx.Core.t_session,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":translation"),
            Vx.Translation.En.f_translation_en()
          )
        )
      )
    );
    return output;
  }

  /**
   * @function context_test
   * Returns the default context for test case execution. Arguments come from the command line.
   * @param  {anylist} args
   * @return {context}
   * (func context-test)
   */
  public interface Func_context_test : Vx.Core.Func_any_from_any {
    public Vx.Core.Type_context vx_context_test(Vx.Core.Type_anylist args);
  }

  public class Class_context_test : Vx.Core.Class_base, Func_context_test {

    public override Vx.Translation.En.Func_context_test vx_new(params object[] vals) {
      Vx.Translation.En.Class_context_test output = new Vx.Translation.En.Class_context_test();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Translation.En.Class_context_test output = new Vx.Translation.En.Class_context_test();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/translation/en", // pkgname
        "context-test", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "context", // name
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Translation.En.e_context_test;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Translation.En.t_context_test;
      return output;
    }

    public Vx.Core.Func_any_from_any vx_fn_new(Vx.Core.Class_any_from_any.IFn fn) {
      return Vx.Core.e_any_from_any;
    }

    public T vx_any_from_any<T, U>(T generic_any_1, U value) where T : Vx.Core.Type_any where U : Vx.Core.Type_any {
      T output = Vx.Core.f_empty(generic_any_1);
      Vx.Core.Type_anylist inputval = (Vx.Core.Type_anylist)value;
      Vx.Core.Type_any outputval = Vx.Translation.En.f_context_test(inputval);
      output = Vx.Core.f_any_from_any(generic_any_1, outputval);
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      Vx.Core.Type_anylist args = Vx.Core.f_any_from_any(Vx.Core.t_anylist, arglist.vx_any(Vx.Core.vx_new_int(0)));
      output = Vx.Translation.En.f_context_test(args);
      return output;
    }

    public Vx.Core.Type_context vx_context_test(Vx.Core.Type_anylist args) {
      Vx.Core.Type_context output = Vx.Translation.En.f_context_test(args);
      return output;
    }

  }

  public static Vx.Translation.En.Func_context_test e_context_test = new Vx.Translation.En.Class_context_test();
  public static Vx.Translation.En.Func_context_test t_context_test = new Vx.Translation.En.Class_context_test();

  public static Vx.Core.Type_context f_context_test(Vx.Core.Type_anylist args) {
    Vx.Core.Type_context output = Vx.Core.e_context;
    output = Vx.Core.f_new(
      Vx.Core.t_context,
      Vx.Core.vx_new(
        Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":session"),
        Vx.Core.f_new(
          Vx.Core.t_session,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Core.vx_new_string(":translation"),
            Vx.Translation.En.f_translation_en(),
            Vx.Core.vx_new_string(":user"),
            Vx.Core.f_new(
              Vx.Core.t_user,
              Vx.Core.vx_new(
                Vx.Core.t_anylist,
                Vx.Core.vx_new_string(":security"),
                Vx.Translation.En.f_securitydata_test()
              )
            )
          )
        )
      )
    );
    return output;
  }

  /**
   * @function securitydata_test
   * Returns the default security for test case execution. Arguments come from the command line.
   * @return {security}
   * (func securitydata-test)
   */
  public interface Func_securitydata_test : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_security vx_securitydata_test();
  }

  public class Class_securitydata_test : Vx.Core.Class_base, Func_securitydata_test {

    public override Vx.Translation.En.Func_securitydata_test vx_new(params object[] vals) {
      Vx.Translation.En.Class_securitydata_test output = new Vx.Translation.En.Class_securitydata_test();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Translation.En.Class_securitydata_test output = new Vx.Translation.En.Class_securitydata_test();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/translation/en", // pkgname
        "securitydata-test", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "security", // name
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Translation.En.e_securitydata_test;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Translation.En.t_securitydata_test;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      output = Vx.Translation.En.f_securitydata_test();
      return output;
    }

    public Vx.Core.Type_security vx_securitydata_test() {
      Vx.Core.Type_security output = Vx.Translation.En.f_securitydata_test();
      return output;
    }

  }

  public static Vx.Translation.En.Func_securitydata_test e_securitydata_test = new Vx.Translation.En.Class_securitydata_test();
  public static Vx.Translation.En.Func_securitydata_test t_securitydata_test = new Vx.Translation.En.Class_securitydata_test();

  public static Vx.Core.Type_security f_securitydata_test() {
    Vx.Core.Type_security output = Vx.Core.e_security;
    output = Vx.Core.f_new(
      Vx.Core.t_security,
      Vx.Core.vx_new(
        Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":allowfuncs"),
        Vx.Core.f_new(
          Vx.Core.t_funclist,
          Vx.Core.vx_new(
            Vx.Core.t_anylist,
            Vx.Data.File.t_boolean_write_from_file_any,
            Vx.Data.File.t_boolean_write_from_file_string,
            Vx.Data.File.t_file_read_from_file,
            Vx.Data.File.t_string_read_from_file
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
  public interface Func_translation_en : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_translation vx_translation_en();
  }

  public class Class_translation_en : Vx.Core.Class_base, Func_translation_en {

    public override Vx.Translation.En.Func_translation_en vx_new(params object[] vals) {
      Vx.Translation.En.Class_translation_en output = new Vx.Translation.En.Class_translation_en();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Translation.En.Class_translation_en output = new Vx.Translation.En.Class_translation_en();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/translation/en", // pkgname
        "translation-en", // name
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
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Translation.En.e_translation_en;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Translation.En.t_translation_en;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      output = Vx.Translation.En.f_translation_en();
      return output;
    }

    public Vx.Core.Type_translation vx_translation_en() {
      Vx.Core.Type_translation output = Vx.Translation.En.f_translation_en();
      return output;
    }

  }

  public static Vx.Translation.En.Func_translation_en e_translation_en = new Vx.Translation.En.Class_translation_en();
  public static Vx.Translation.En.Func_translation_en t_translation_en = new Vx.Translation.En.Class_translation_en();

  public static Vx.Core.Type_translation f_translation_en() {
    Vx.Core.Type_translation output = Vx.Core.e_translation;
    output = Vx.Core.f_new(
      Vx.Core.t_translation,
      Vx.Core.vx_new(
        Vx.Core.t_anylist,
        Vx.Core.vx_new_string(":name"),
        Vx.Core.vx_new_string("en"),
        Vx.Core.vx_new_string(":wordmap"),
        Vx.Translation.En.f_words()
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
  public interface Func_words : Vx.Core.Type_func, Vx.Core.Type_replfunc {
    public Vx.Core.Type_stringmap vx_words();
  }

  public class Class_words : Vx.Core.Class_base, Func_words {

    public override Vx.Translation.En.Func_words vx_new(params object[] vals) {
      Vx.Translation.En.Class_words output = new Vx.Translation.En.Class_words();
      return output;
    }

    public override Vx.Core.Type_any vx_copy(params object[] vals) {
      Vx.Translation.En.Class_words output = new Vx.Translation.En.Class_words();
      return output;
    }

    public override Vx.Core.Type_typedef vx_typedef() {
      Vx.Core.Type_typedef output = Vx.Core.t_func.vx_typedef();
      return output;
    }

    public Vx.Core.Type_funcdef vx_funcdef() {
      Vx.Core.Type_funcdef output = Vx.Core.funcdef_new(
        "vx/translation/en", // pkgname
        "words", // name
        0, // idx
        false, // async
        Vx.Core.typedef_new(
          "vx/core", // pkgname
          "stringmap", // name
          ":map", // extends
          Vx.Core.e_typelist, // traits
          Vx.Core.vx_new(Vx.Core.t_typelist, Vx.Core.t_string), // allowtypes
          Vx.Core.e_typelist, // disallowtypes
          Vx.Core.e_funclist, // allowfuncs
          Vx.Core.e_funclist, // disallowfuncs
          Vx.Core.e_anylist, // allowvalues
          Vx.Core.e_anylist, // disallowvalues
          Vx.Core.e_argmap // properties
        ) // typedef
      );
      return output;
    }

    public override Vx.Core.Type_any vx_empty() {
      Vx.Core.Type_any output = Vx.Translation.En.e_words;
      return output;
    }

    public override Vx.Core.Type_any vx_type() {
      Vx.Core.Type_any output = Vx.Translation.En.t_words;
      return output;
    }

    public Vx.Core.Type_any vx_repl(Vx.Core.Type_anylist arglist) {
      Vx.Core.Type_any output = Vx.Core.e_any;
      output = Vx.Translation.En.f_words();
      return output;
    }

    public Vx.Core.Type_stringmap vx_words() {
      Vx.Core.Type_stringmap output = Vx.Translation.En.f_words();
      return output;
    }

  }

  public static Vx.Translation.En.Func_words e_words = new Vx.Translation.En.Class_words();
  public static Vx.Translation.En.Func_words t_words = new Vx.Translation.En.Class_words();

  public static Vx.Core.Type_stringmap f_words() {
    Vx.Core.Type_stringmap output = Vx.Core.e_stringmap;
    output = Vx.Core.f_new(
      Vx.Core.t_stringmap,
      Vx.Core.vx_new(
        Vx.Core.t_anylist,
        Vx.Core.vx_new_string("Hello"),
        Vx.Core.vx_new_string("Hello"),
        Vx.Core.vx_new_string("World"),
        Vx.Core.vx_new_string("World"),
        Vx.Core.vx_new_string("!vx/core/func exception"),
        Vx.Core.vx_new_string("Exception in Function"),
        Vx.Core.vx_new_string("!vx/core/func permissiondenied"),
        Vx.Core.vx_new_string("Permission Denied to Function"),
        Vx.Core.vx_new_string("!vx/repl/repl/repl<-string-argmap repltypenotfound"),
        Vx.Core.vx_new_string("Repl Type Not Found")
      )
    );
    return output;
  }


  public static class PackageRunOnce {
    public static bool RunOnce() {
    Vx.Core.Map<string, Vx.Core.Type_any> maptype = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_any> mapconst = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_any>();
    Vx.Core.Map<string, Vx.Core.Type_func> mapfunc = new Vx.Core.LinkedHashMap<string, Vx.Core.Type_func>();
    mapfunc.put("context-en", Vx.Translation.En.t_context_en);
    mapfunc.put("context-test", Vx.Translation.En.t_context_test);
    mapfunc.put("securitydata-test", Vx.Translation.En.t_securitydata_test);
    mapfunc.put("translation-en", Vx.Translation.En.t_translation_en);
    mapfunc.put("words", Vx.Translation.En.t_words);
    Vx.Core.vx_global_package_set("vx/translation/en", maptype, mapconst, mapfunc);
      return true;
    }
  }

  public static bool ranonce = PackageRunOnce.RunOnce();

}
